`timescale 1ns/1ps
module full_adder_tb;
reg cin,A,B;
wire S,C;

full_adder uut(
    .A(A),.B(B),.cin(cin),.S(S),.C(C)
);

initial begin
    A=0;
    B=1;
    cin=0;

    #20 A=1;
    #20 cin=1;
    #40;
end
initial begin
    $monitor("A=%d B=%d Cin=%d--->C=%d S=%d",A,B,cin,C,S);
end
    
endmodule