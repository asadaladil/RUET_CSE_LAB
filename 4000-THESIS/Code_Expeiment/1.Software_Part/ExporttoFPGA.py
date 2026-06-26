import torch
import math
import os

# =====================================================================
# 1. HARDWARE BIT-MAPPING FUNCTION (Your Exhaustive Search)
# =====================================================================
def get_hardware_bits(weight_float, scale=128.0):
    """
    Converts a 32-bit float into your exact 8-bit Dual-Shift binary string.
    Format: w[7]=Sign, w[6:4]=Shift_A, w[3]=Mark(Add/Sub), w[2:0]=Shift_B
    """
    # Scale and clamp to hardware limits
    w_scaled = round(weight_float * scale)
    w_scaled = max(min(w_scaled, 127), -127) 
    
    if w_scaled == 0:
        return "00000000" # Hardware zero-skipping logic
        
    sign_bit = 1 if w_scaled < 0 else 0
    x = abs(w_scaled)
    e = 1e-9
    
    best_err = float('inf')
    best_bits = ""
    
    # Exhaustive search: Test all 4 paths to match the PyTorch training logic
    for path_a in ['ceil', 'floor']:
        for path_b in ['ceil', 'floor']:
            
            # 1. Primary Shift (w[6:4])
            a = math.ceil(math.log2(x + e)) if path_a == 'ceil' else math.floor(math.log2(x + e))
            a = max(min(a, 7), 0) # 3-bit wire limit
            
            base_a = 2**a
            rem = abs(x - base_a)
            
            # 2. Secondary Shift (w[2:0])
            b = math.ceil(math.log2(rem + e)) if path_b == 'ceil' else math.floor(math.log2(rem + e))
            b = max(min(b, 7), 0) # 3-bit wire limit
            
            # 3. Add/Sub bit (w[3]) -> 1 if subtract, 0 if add
            mark = 1 if x < base_a else 0
            
            # 4. Check Error
            reconstructed = base_a + ((-1)**mark) * (2**b)
            err = abs(x - reconstructed)
            
            # 5. Save the absolute best bit combination
            if err < best_err:
                best_err = err
                # Format string: Sign(1) + ShiftA(3) + Mark(1) + ShiftB(3)
                best_bits = f"{sign_bit:01b}{a:03b}{mark:01b}{b:03b}"
                
    return best_bits

def get_bias_bits(bias_float, scale=128.0):
    """
    Converts floating point bias into standard 8-bit Two's Complement binary.
    """
    b_scaled = round(bias_float * scale)
    b_scaled = int(max(min(b_scaled, 127), -128))
    
    # Standard Two's Complement for negative numbers
    if b_scaled < 0:
        b_scaled = (1 << 8) + b_scaled
        
    return f"{b_scaled:08b}"

# =====================================================================
# 2. EXTRACTION LOGIC
# =====================================================================
def export_model_to_txt(model_path="Trained_hardware_digit_model_GPU.pth", output_dir="./FPGA_Memory_Files"):
    # Create output folder
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # Load the raw weights dictionary (We don't even need the Model class here!)
    print(f"Loading {model_path}...")
    try:
        state_dict = torch.load(model_path, map_location="cpu", weights_only=True)
    except FileNotFoundError:
        print("Error: Model file not found!")
        return

    # Loop through every layer in the network
    for layer_name, tensor in state_dict.items():
        # Flatten the multi-dimensional tensor into a 1D array for Block RAM
        flat_tensor = tensor.flatten().tolist()
        
        # Create a file name (e.g., "conv1_weight.txt" or "conv1_bias.txt")
        safe_name = layer_name.replace('.', '_')
        file_path = os.path.join(output_dir, f"{safe_name}.txt")
        
        with open(file_path, 'w') as f:
            for val in flat_tensor:
                if 'weight' in layer_name:
                    # Apply your Dual-Shift extraction logic
                    binary_str = get_hardware_bits(val)
                elif 'bias' in layer_name:
                    # Apply standard integer extraction logic
                    binary_str = get_bias_bits(val)
                
                # Write exactly one binary string per line
                f.write(binary_str + "\n")
                
        print(f"Exported {len(flat_tensor)} parameters to -> {file_path}")

    print("\n✅ All FPGA Memory Files Generated Successfully!")

# =====================================================================
# 3. EXECUTE
# =====================================================================
if __name__ == "__main__":
    export_model_to_txt()