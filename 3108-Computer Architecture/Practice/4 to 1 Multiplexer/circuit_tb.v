`timescale 1ns/1ps
module circuit_tb;
reg [3:0][3:0]A;
reg [1:0]S;
reg en;
wire [3:0]F;

circuit uut(
    .A(A),
    .S(S),
    .en(en),
    .F(F)
);
initial begin
    A=16'b0100_0011_1110_1100;
    en=0;
    S=2'b00;
    #20 en=1;
    #20 S=2'b01;
    #20 S=2'b10;
    #20 S=2'b11;
end
initial begin
    $monitor("S=%b-->F=%b",S,F);
end
endmodule