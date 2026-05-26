`timescale 1ns/1ps
module AC_BD_tb;
reg A,B,C,D;
wire Z;
AC_BD uut(.A(A),.B(B),.C(C),.D(D),.Z(Z));
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,AC_BD_tb);
    A=0; B=0; C=0; D=0; 
    #20 A=1;B=1;
    #20 C=1;
    #20 A=0;D=1;
    end
initial begin
    $monitor("A=%b B=%b C=%b D=%b Z=%d\n",A,B,C,D,Z);
end
endmodule