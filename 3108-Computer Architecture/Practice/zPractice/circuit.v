module circuit(
    input wire [6:0]I,
    input wire clk,
    input wire en,
    input wire reset,
    output reg [6:0]Q
);

wire [6:0] q_temp,q_reg;

always @(posedge clk) 
begin
    if (reset)
        q_reg<=7'b000_0000;
    else if (en)
        q_reg<=q_temp;
    else
        q_reg<=7'bxxx_xxxx;    
end

assign Q=q_reg;
assign q_temp=I;
endmodule