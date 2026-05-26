module register (
    input wire [2:0]d,
    input wire clk,
    input wire reset,
    output wire [2:0]q
);

reg [2:0]r_reg;
wire [2:0]r_next;

always @(posedge clk, posedge reset) 
begin
    if (reset || r_reg==3'b100)
        r_reg<=3'b000;
    else
        r_reg<=r_next;
end

assign r_next=d;    
assign q=r_reg;

endmodule