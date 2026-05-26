`timescale 1ns/1ps
module circuit_tb;
reg clk;
reg reset;
reg en;
wire [3:0]q;

counter uut(reset,clk,en,q);

always 
begin
    clk=~clk;
    #10;    
end

initial begin
    clk=0;
    reset=0;en=0;
    #20;
    reset=1;en=0;
    #20;
    reset=1;en=1;
    #20;
    reset=0;
    #100;
    en=0;
    #20;
    en=1;
    #100;
    $finish;
end

initial begin
    $monitor("en=%b,reset=%b,q=%b",en,reset,q);
end
endmodule