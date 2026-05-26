`timescale 1ns/1ps
module adder_4bit_tb;

reg [3:0]A,B;
reg cin;
wire [3:0]C,S;

adder4 uut(
    .A(A),.B(B),.cin(cin),.C(C),.S(S)
);
initial begin
    A=4'b0001;
    B=4'b0001;
    cin=0;

    #20 A=4'b0110;
    #20 cin=1;
    #20 A=4'b1000;B=4'b1000; 
    #40;
end
initial begin
     $monitor("A=%b B=%b Cin=%b--->C=%b S=%b",A,B,cin,C[3],S);
end
endmodule