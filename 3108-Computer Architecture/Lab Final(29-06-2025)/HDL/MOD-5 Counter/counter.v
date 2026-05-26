module counter (
    input wire clk,
    input wire reset,
    output wire [2:0]q
);

wire [2:0]d_temp,q_temp;

register c1(d_temp,clk,reset,q_temp);
addone c2(q_temp,d_temp);

assign q=q_temp;
    
endmodule