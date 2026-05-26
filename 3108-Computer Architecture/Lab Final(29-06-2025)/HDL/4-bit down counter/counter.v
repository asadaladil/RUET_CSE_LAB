module counter (
    input wire clk,
    input wire reset,
    output wire [3:0]q
);

wire [3:0]d_temp,q_temp;

register c1(d_temp,clk,reset,q_temp);
subone c2(q_temp,d_temp);

assign q=q_temp;
    
endmodule