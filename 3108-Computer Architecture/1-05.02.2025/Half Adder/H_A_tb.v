`timescale 1ns/1ps // 1ps=0.001ns , can handle 3 decimal point 
module H_A_tb;
reg A,B;
wire C,S;

H_A uut(
    .A(A),
    .B(B),
    .C(C),
    .S(S)
);

initial begin
$dumpfile("test.vcd");
$dumpvars(0, H_A_tb);

A=0;B=0;
#20 B=1;
#20 A=1;B=0;
#20 B=1;
#40;
end
initial begin
$monitor("A=%d,B=%d,C=%d,S=%d\n",A,B,C,S);
end
endmodule