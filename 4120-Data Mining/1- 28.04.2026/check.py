import torch

# 1. Check if NVIDIA CUDA is available
if torch.cuda.is_available():
    device = torch.device("cuda")
    print(f"GPU is available: {torch.cuda.get_device_name(0)}")
else:
    device = torch.device("cpu")
    print("GPU not found. Defaulting to CPU.")

# 2. To run a model on the GPU, pass it to the device:
# model = MyConvolutionalNeuralNetwork().to(device)

# 3. Remember to send your training data/images to the device too:
# images, labels = images.to(device), labels.to(device)
