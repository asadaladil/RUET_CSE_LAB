module count (
    input wire clk,
    input wire reset,
    input wire en,
    output wire [6:0]o
);

wire [6:0]o_temp,i_next;
circuit Reg (i_next,clk,en,reset,o_temp);
add1 add (o_temp,i_next);
assign o=o_temp;


endmodule