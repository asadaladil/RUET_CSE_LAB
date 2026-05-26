`timescale 1ns/1ps
module count_tb;
reg en;
reg reset;
reg clk;
wire [6:0]o;

count uut(clk,reset,en,o);

always begin
    clk=~clk;
    #10;
    
end
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,count_tb);

    clk<=0;
    reset<=0;
    en=1'b0;
    #20; 
    en=1;
    #20;
    #20;
    #20;
    #20;

    $finish;
    
end
initial begin
    $monitor("en=%b clk=%b reset=%b o=%b",en,clk,reset,o);
end
    
endmodule