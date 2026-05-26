`timescale 1ns/1ps
module circuit_tb;
reg [3:0]A;
reg [1:0]S;
reg en;
wire [3:0][3:0]F;

circuit uut(
    .A(A),
    .S(S),
    .en(en),
    .F(F)
);
initial begin
    A=4'b1110;
    en=0;
    S=2'b00;
    #20 en=1;
    #20 S=2'b01;
    #20 S=2'b10;
    #20 S=2'b11;
end
initial begin
    $monitor("S=%b-->F=%b-%b-%b-%b",S,F[3],F[2],F[1],F[0]);
end
endmodule