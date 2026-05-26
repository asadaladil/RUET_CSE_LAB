module circuit (
    input wire clk,en,
    input wire reset,
    input wire [6:0]d,
    output reg [6:0]q
);
// wire [6:0] q_next;
// reg [6:0] q_reg;

always @(posedge clk, posedge reset,posedge en) 
begin
    if (reset && en)
        q<=7'b0;
    else if(en)
        q<=d;
    else
        q<=7'bx;
end

endmodule