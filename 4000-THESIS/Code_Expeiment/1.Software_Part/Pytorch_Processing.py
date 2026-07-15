import torch # The core PyTorch library for tensor math
import torch.nn as nn # Neural network modules (layers, loss functions)
import torch.nn.functional as F # Functional interface for activations and stateless operations
import torch.optim as optim # Optimization algorithms like Adam
from torchvision import datasets, transforms # For loading and augmenting image datasets
import numpy as np # For handling standard arrays before converting to tensors
import os # For interacting with your local file system to read the .txt files
from ExporttoFPGA import export_model_to_txt # Custom function to export weights to FPGA-friendly format

# =====================================================================
# 1. HARDWARE QUANTIZATION-AWARE TRAINING (QAT) ENGINE
# =====================================================================
class DualShiftQuantize(torch.autograd.Function):
    @staticmethod
    def forward(ctx, weight, global_scale=128.0): # Scale of 128.0 (2^7) turns decimals into 8-bit integers
        
        # Scale the weights and force them into our 8-bit hardware boundary (-127 to 127)
        w_scaled = weight * global_scale
        w_scaled = torch.round(w_scaled) # Rounding simulates hardware losing decimal precision
        w_scaled = torch.clamp(w_scaled, -127.0, 127.0) # Hardware cannot hold numbers larger than 8 bits
        
        # Extract the Global Sign bit (Mapping to w[7] in your hardware)
        sign = torch.sign(w_scaled) # Returns -1 or 1
        sign = torch.where(sign == 0, torch.tensor(1.0, device=weight.device), sign) # Treat 0 as positive to avoid math errors
        magnitude = torch.abs(w_scaled) # The absolute magnitude to be processed by the shifters
        
        # Find the primary power of two (Mapping to Shift A: w[6:4])
        # 1e-9 prevents log2(0) crashes. Ceil finds the upper bound power of two. 
        e = 1e-9
        log_mag = torch.log2(magnitude + e)
        # -------------------------------------------------------------
        # 1. Calculate Primary Shifts (Shift A)
        # -------------------------------------------------------------
        a_ceil = torch.clamp(torch.ceil(log_mag), 0.0, 7.0) # Clamp to 7.0 because the shift wire is 3 bits wide
        a_floor = torch.clamp(torch.floor(log_mag), 0.0, 7.0)
        
        # Find the secondary power of two (Mapping to Shift B: w[2:0])
        # Calculate remainders for both A paths
        rem_ceil = torch.abs(magnitude - 2.0**a_ceil)
        rem_floor = torch.abs(magnitude - 2.0**a_floor)

        # -------------------------------------------------------------
        # 2. Calculate Secondary Shifts (Shift B)
        # -------------------------------------------------------------
        
        # Ceil-Ceil Combination:
        val  = torch.log2(rem_ceil + e)
        val  = torch.ceil(val)
        b_cc = torch.clamp(val, 0.0, 7.0)
        
        # Ceil-Floor Combination:
        val  = torch.log2(rem_ceil + e)
        val  = torch.floor(val)
        b_cf = torch.clamp(val, 0.0, 7.0)
        
        # Floor-Ceil Combination:
        val  = torch.log2(rem_floor + e)
        val  = torch.ceil(val)
        b_fc = torch.clamp(val, 0.0, 7.0)

        # Floor-Floor Combination:
        val  = torch.log2(rem_floor + e)
        val  = torch.floor(val)
        b_ff = torch.clamp(val, 0.0, 7.0)

        # -------------------------------------------------------------
        # 3. Determine the Add/Sub bit ('mark' in your logic)
        # -------------------------------------------------------------
        # If the target magnitude (x) is less than the base (2**x1), we subtract.
        mark_c = (magnitude < 2.0**a_ceil).float()
        mark_f = (magnitude < 2.0**a_floor).float()

        # -------------------------------------------------------------
        # 4. Reconstruct the 4 Candidate Values
        # -------------------------------------------------------------
        val_cc = 2.0**a_ceil + ((-1.0)**mark_c) * 2.0**b_cc
        val_cf = 2.0**a_ceil + ((-1.0)**mark_c) * 2.0**b_cf
        val_fc = 2.0**a_floor + ((-1.0)**mark_f) * 2.0**b_fc
        val_ff = 2.0**a_floor + ((-1.0)**mark_f) * 2.0**b_ff

        # -------------------------------------------------------------
        # 5. Calculate Absolute Errors
        # -------------------------------------------------------------
        err_cc = torch.abs(magnitude - val_cc)
        err_cf = torch.abs(magnitude - val_cf)
        err_fc = torch.abs(magnitude - val_fc)
        err_ff = torch.abs(magnitude - val_ff)

        # -------------------------------------------------------------
        # 6. Select the Optimal Candidate (Minimum Error)
        # -------------------------------------------------------------
        # Stack all candidates and errors into a new dimension (Size: 4 x Tensor Shape)
        all_vals = torch.stack([val_cc, val_cf, val_fc, val_ff], dim=0)
        all_errs = torch.stack([err_cc, err_cf, err_fc, err_ff], dim=0)

        # Find the index (0, 1, 2, or 3) of the smallest error for every single weight
        _, best_indices = torch.min(all_errs, dim=0) # first part is given the minimum value
        # second part is given the minimum value carrying indices.

        # Gather the winning reconstructed values using the winning indices
        best_mag = torch.gather(all_vals, dim=0, index=best_indices.unsqueeze(0)).squeeze(0)

        # -------------------------------------------------------------
        # 7. Apply the Global Sign and Scale Down
        # -------------------------------------------------------------
        w_quant = best_mag * sign
        return w_quant / global_scale
        

    @staticmethod
    def backward(ctx, grad_output):
        # Straight-Through Estimator (STE): PyTorch cannot derive rounding/shifting logic.
        # This passes the gradient straight through so the network keeps learning despite the harsh hardware constraints.
        return grad_output, None

# =====================================================================
# 2. HARDWARE-SPECIFIC CONVOLUTION LAYER
# =====================================================================
class QATConv2d(nn.Conv2d):
    def __init__(self,in_channels,out_channels,kernel_size,stride=1,padding=0,dilation=1,groups=1,bias=True):
        super().__init__(in_channels, out_channels, kernel_size, stride, padding, dilation, groups, bias)

    def forward(self, input): # Override the forward function of nn.Conv2d
        
        # Before performing the math, this intercepts the weights and forces them into the Dual-Shift format.
        q_weight = DualShiftQuantize.apply(self.weight) 
        
        # Standard convolution operation using our restricted hardware-ready weights
        return F.conv2d(input, q_weight, self.bias, self.stride, self.padding, self.dilation, self.groups)

# =====================================================================
# 3. YOUR CNN ARCHITECTURE (MAPPED FOR SYSTOLIC ARRAY)
# =====================================================================
class HardwareNet(nn.Module):
    def __init__(self):
        super().__init__()
        
        # Layer 1: 32 feature maps. 3x3 kernel. Stride 1.
        self.conv1 = QATConv2d(1, 32, kernel_size=3, padding=0) # Padding 0 shrinks 28x28 input to 26x26
        self.pool1 = nn.MaxPool2d(2, 2) # Shrinks 26x26 down to 13x13. Reduces hardware BRAM usage.
        
        # Layer 2: 64 feature maps. 3x3 kernel. 
        self.conv2 = QATConv2d(32, 64, kernel_size=3, padding=0) # Shrinks 13x13 to 11x11
        self.pool2 = nn.MaxPool2d(2, 2) # Shrinks 11x11 down to 5x5
        
        # Layer 3: 64 feature maps. 3x3 kernel.
        self.conv3 = QATConv2d(64, 64, kernel_size=3, padding=0) # Shrinks 5x5 down to 3x3 spatial map
        
        # Output Classification Layers
        self.flatten = nn.Flatten() # Flattens 3D data into 1D array for final prediction
        # 64 channels * 3 height * 3 width = 576 incoming values
        self.fc1 = nn.Linear(64 * 3 * 3, 64) # 64 neurons chosen to balance logic area and accuracy
        self.fc2 = nn.Linear(64, 10) # 10 neurons required exactly because there are 10 digit classes (0-9)

    def forward(self, x):
        # The forward propagation matching your physical post-processing modules
        x = self.pool1(F.relu(self.conv1(x))) # Conv -> ReLU Activation -> MaxPool
        x = self.pool2(F.relu(self.conv2(x)))
        x = F.relu(self.conv3(x))
        x = self.flatten(x)
        x = F.relu(self.fc1(x))
        return self.fc2(x) # PyTorch CrossEntropyLoss expects raw scores, so no Softmax here

# =====================================================================
# 4. DATA PIPELINE & TRAINING LOOP
# =====================================================================
def train_model():
    # Setup device to utilize GPU acceleration if available
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    
    # 1. Dataset Loading (Mimicking your TF Logic)
    # Load standard MNIST (60000 train, 10000 test)
    train_dataset = datasets.MNIST('./data', train=True, download=True)
    test_dataset = datasets.MNIST('./data', train=False, download=True)
    
    # Convert PyTorch tensors back to raw numpy lists to inject your custom text files
    x_train = list(train_dataset.data.numpy())
    y_train = list(train_dataset.targets.numpy())
    
    # Load custom text files from Digit_Image_Array
    for digit in range(10): # Iterates exactly 10 times for digits 0 through 9
        file_path = f"./Digit_Image_Array/Digit{digit}.txt"
        if os.path.exists(file_path):
            with open(file_path, mode="r") as file:
                lines = file.readlines()
                a = []
                for i in lines:
                    if len(i.split(' ')) == 1: # Single character lines act as the 'y' label
                        if len(a) > 0: # Ensure array isn't empty
                            x_train.append(a)
                            y_train.append(int(i))
                        a = []
                        continue
                    temp = []
                    for j in i.split(' '):
                        try:
                            temp.append(int(j)) # Convert text string pixels to integer values
                        except ValueError:
                            continue
                    if temp:
                        a.append(temp)
    
    # 2. Preprocessing
    x_train = np.array(x_train, dtype=np.float32)
    y_train = np.array(y_train, dtype=np.int64) # Labels must be 64-bit integers for PyTorch loss function
    print(f"Total Training Samples: {len(x_train)}")
    
    x_train = x_train / 255.0 # Scale pixel brightness from 0-255 down to 0.0-1.0 to stabilize gradients
    x_train = np.expand_dims(x_train, 1) # Reshape to (Batch, 1 Channel, 28, 28) for PyTorch 2D Convolutions
    
    # Convert numpy arrays into PyTorch Tensors
    x_tensor = torch.tensor(x_train)
    y_tensor = torch.tensor(y_train)
    
    # Combine into a PyTorch Dataset
    custom_dataset = torch.utils.data.TensorDataset(x_tensor, y_tensor)
    
    # 4. Augmentation (Replicating your Keras ImageDataGenerator)
    # Randomly alters images to prevent the network from memorizing the training data
    transform = transforms.Compose([
        transforms.RandomAffine(
            degrees=15, # Rotate by max 15 degrees to simulate tilted handwriting
            translate=(0.15, 0.15), # Shift by 15% width/height to simulate off-center writing
            scale=(0.85, 1.15) # Zoom out 15% or in 15% (1.0 - 0.15, 1.0 + 0.15)
        )
    ])
    
    # Wrap dataset to apply transforms during loading
    class AugmentedDataset(torch.utils.data.Dataset):
        def __init__(self, ds, trans):
            self.ds = ds
            self.trans = trans
        def __len__(self): return len(self.ds)
        def __getitem__(self, idx):
            img, label = self.ds[idx]
            return self.trans(img), label

    aug_dataset = AugmentedDataset(custom_dataset, transform)
    
    # Loaders feed the network exactly 64 images at a time (Balances RAM usage and gradient smoothness)
    train_loader = torch.utils.data.DataLoader(aug_dataset, batch_size=64, shuffle=True)
    
    # 3. Model Initialization
    model = HardwareNet().to(device)
    criterion = nn.CrossEntropyLoss() # Standard classification loss; combines Softmax and Negative Log Likelihood
    optimizer = optim.Adam(model.parameters(), lr=0.001) # Learning rate of 0.001 is the industry standard starting point for Adam
    
    # 5. Model Fit Loop
    print("\nStarting Hardware-Constrained Training...")
    epochs = 15 # Train over the entire dataset exactly 15 times
    
    for epoch in range(epochs):
        model.train()
        running_loss = 0.0
        correct = 0
        total = 0
        
        for inputs, labels in train_loader:
            inputs, labels = inputs.to(device), labels.to(device)
            
            optimizer.zero_grad() # Clear old gradients from the previous step to avoid compounding
            outputs = model(inputs) # Forward pass through the network
            
            loss = criterion(outputs, labels) # Calculate error
            loss.backward() # Backpropagation (Utilizes our STE trick)
            optimizer.step() # Update weights based on gradients
            
            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1) # Grab the index of the highest prediction
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
        print(f"Epoch {epoch+1}/{epochs} | Loss: {running_loss/len(train_loader):.4f} | Accuracy: {100 * correct / total:.2f}%")

    # 6. Save the Model
    model_filename = "Trained_hardware_digit_model.pth"
    torch.save(model.state_dict(), model_filename)
    print(f"\n✅ Dual-Shift Model saved successfully as '{model_filename}'")

if __name__ == "__main__":
    train_model()
    export_model_to_txt() # Automatically export weights to FPGA-friendly format after training

# 98.03% accuracy after 15 epochs of training with the custom hardware quantization-aware architecture!