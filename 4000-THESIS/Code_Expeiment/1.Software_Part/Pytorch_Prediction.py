import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
import os

# =====================================================================
# 1. REBUILD THE HARDWARE ARCHITECTURE (Same as before)
# =====================================================================
class DualShiftQuantize(torch.autograd.Function):
    @staticmethod
    def forward(ctx, weight, global_scale=128.0):
        w_scaled = torch.round(weight * global_scale)
        w_scaled = torch.clamp(w_scaled, -127.0, 127.0) 
        sign = torch.sign(w_scaled)
        sign = torch.where(sign == 0, torch.tensor(1.0, device=weight.device), sign)
        mag = torch.abs(w_scaled)
        
        shift_a = torch.clamp(torch.ceil(torch.log2(mag + 1e-9)), 0.0, 7.0)
        base_a = 2.0 ** shift_a
        remainder = torch.abs(base_a - mag)
        shift_b = torch.clamp(torch.round(torch.log2(remainder + 1e-9)), 0.0, 7.0)
        
        sub_bit = (base_a > mag).float()
        w_quant = (2.0**shift_a + ((-1.0)**sub_bit) * 2.0**shift_b) * sign
        return w_quant / global_scale

    @staticmethod
    def backward(ctx, grad_output):
        return grad_output, None

class QATConv2d(nn.Conv2d):
    def forward(self, input):
        q_weight = DualShiftQuantize.apply(self.weight)
        return F.conv2d(input, q_weight, self.bias, self.stride, self.padding, self.dilation, self.groups)

class HardwareNet(nn.Module):
    def __init__(self):
        super(HardwareNet, self).__init__()
        self.conv1 = QATConv2d(1, 32, kernel_size=3, padding=0)
        self.pool1 = nn.MaxPool2d(2, 2)
        self.conv2 = QATConv2d(32, 64, kernel_size=3, padding=0)
        self.pool2 = nn.MaxPool2d(2, 2)
        self.conv3 = QATConv2d(64, 64, kernel_size=3, padding=0)
        self.flatten = nn.Flatten()
        self.fc1 = nn.Linear(64 * 3 * 3, 64)
        self.fc2 = nn.Linear(64, 10)

    def forward(self, x):
        x = self.pool1(F.relu(self.conv1(x)))
        x = self.pool2(F.relu(self.conv2(x)))
        x = F.relu(self.conv3(x))
        x = self.flatten(x)
        x = F.relu(self.fc1(x))
        return self.fc2(x)

# =====================================================================
# 2. RAW ARRAY INFERENCE LOGIC
# =====================================================================
def predict_from_array(image_array, model_path="Trained_hardware_digit_model_GPU.pth"):
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    
    # 1. Load the model
    model = HardwareNet().to(device)
    try:
        model.load_state_dict(torch.load(model_path, map_location=device))
    except FileNotFoundError:
        print(f"Error: Could not find {model_path}.")
        return

    # 2. Set to evaluation mode (turns off training features)
    model.eval()

    # 3. Convert the raw 28x28 Python list/array to a numpy array
    raw_array = np.array(image_array, dtype=np.float32)
    
    # Ensure it is exactly 28x28
    if raw_array.shape != (28, 28):
        print(f"Error: Expected a 28x28 array, but got {raw_array.shape}")
        return

    # 4. Normalize the data (just like in your training script)
    # If your text files contain values from 0-255, this scales them to 0.0-1.0
    normalized_array = raw_array / 255.0

    # 5. Convert to PyTorch Tensor and add Batch & Channel dimensions
    # raw_array is (28, 28) -> We need (1, 1, 28, 28) for the CNN
    img_tensor = torch.tensor(normalized_array).to(device)
    img_tensor = img_tensor.unsqueeze(0).unsqueeze(0) 

    # 6. Execute Multiplier-Less Forward Pass
    with torch.no_grad():
        raw_output = model(img_tensor)
        probabilities = F.softmax(raw_output, dim=1)[0]
        
        predicted_class = torch.argmax(probabilities).item()
        confidence = probabilities[predicted_class].item() * 100

    print("-" * 40)
    print(f"Hardware Prediction: {predicted_class}")
    print(f"Confidence: {confidence:.2f}%")
    print("-" * 40)
    return predicted_class


# =====================================================================
# 3. HELPER FUNCTION: READ ARRAY FROM YOUR TEXT FILES
# =====================================================================
# def load_array_from_txt(filepath):
#     """
#     Reads a text file containing space-separated pixel values 
#     and returns a 28x28 Python list.
#     """
#     if not os.path.exists(filepath):
#         print(f"File not found: {filepath}")
#         return None

#     image_array = []
#     with open(filepath, mode="r") as file:
#         lines = file.readlines()
#         for line in lines:
#             # Skip single-character label lines if they exist
#             if len(line.split(' ')) == 1: 
#                 continue
            
#             row = []
#             for pixel in line.split(' '):
#                 try:
#                     row.append(int(pixel))
#                 except ValueError:
#                     continue
            
#             if row:
#                 image_array.append(row)
                
#     return image_array

# =====================================================================
# 4. EXECUTE
# =====================================================================
# if __name__ == "__main__":
#     # Example usage: Read a file from your training data format
#     test_file = "./Digit_Image_Array/Test_Digit.txt" 
    
#     my_array = load_array_from_txt(test_file)
    
#     if my_array:
#         predict_from_array(my_array)