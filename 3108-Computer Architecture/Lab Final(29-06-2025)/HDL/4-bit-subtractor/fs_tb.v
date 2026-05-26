`timescale 1ns/1ps
module fs_tb;
reg [3:0]A;
reg [3:0]B;
reg Bin;
wire [3:0]Bout;
wire [3:0]D;

Full_sub uut(A,B,Bin,D,Bout);

initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,fs_tb);
    A=4'b1000;
    B=4'b0011;
    Bin=0;
    #20;
    A=4'b1111;
    B=4'b0011;
    #20;
    A=4'b1001;
    B=4'b1001;
    #20;
    A=4'b0111;
    B=4'b1010;
    #20;
    #40;
end

initial begin
    
$monitor("A=%b, B=%b Bin=%b D=%b Bout=%b",A,B,Bin,D,Bout);
    end



endmodule