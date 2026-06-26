import torch
import os

# =====================================================================
# 1. STANDARD INTEGER CONVERSION (Two's Complement)
# =====================================================================
def get_twos_complement_bits(val_float, scale=128.0):
    """
    Converts any floating-point weight or bias into a standard 
    8-bit Two's Complement binary string.
    """
    # 1. Scale the decimal up to an integer space
    val_scaled = round(val_float * scale)
    
    # 2. Clamp strictly to the 8-bit signed integer boundary [-128 to 127]
    val_scaled = int(max(min(val_scaled, 127), -128))
    
    # 3. Apply Two's Complement math for negative numbers
    # if val_scaled < 0:
    #     val_scaled = (1 << 8) + val_scaled # e.g., -1 becomes 255 (which is 11111111 in 8-bit)
        
    # 4. Format as exactly 8 binary digits
    return f"{val_scaled}"

# =====================================================================
# 2. EXTRACTION LOGIC
# =====================================================================
def export_model_to_txt(model_path="Trained_hardware_digit_model_GPU.pth", output_dir="./FPGA_Integer_Files"):
    # Create output folder
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    print(f"Loading {model_path}...")
    try:
        # Load the raw weights dictionary
        state_dict = torch.load(model_path, map_location="cpu", weights_only=True)
    except FileNotFoundError:
        print(f"Error: Could not find {model_path}!")
        return

    # Loop through every layer (Weights and Biases)
    for layer_name, tensor in state_dict.items():
        # Flatten the multi-dimensional tensor into a 1D array for Block RAM
        flat_tensor = tensor.flatten().tolist()
        
        safe_name = layer_name.replace('.', '_')
        file_path = os.path.join(output_dir, f"{safe_name}.txt")
        
        with open(file_path, 'w') as f:
            for val in flat_tensor:
                # Because we are using standard multipliers, weights and biases 
                # are extracted using the exact same mathematical function!
                binary_str = get_twos_complement_bits(val)
                
                # Write exactly one binary string per line
                f.write(binary_str + "\n")
                
        print(f"Exported {len(flat_tensor)} integers to -> {file_path}")

    print("\n✅ All Integer FPGA Memory Files Generated Successfully!")

# =====================================================================
# 3. EXECUTE
# =====================================================================
if __name__ == "__main__":
    export_model_to_txt()