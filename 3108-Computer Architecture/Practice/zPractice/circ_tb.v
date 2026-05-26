`timescale 1ns/1ps
module circ_tb;
reg [6:0]I;
reg en;
reg reset;
reg clk;
wire [6:0]Q;

circuit uut(I,clk,en,reset,Q);

always begin
    clk=~clk;
    #10;
    
end
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,circ_tb);

    clk<=0;
    en=1'b1;
    reset=0;
    I<=7'b0000_000;
    #20; 
    #20;
    #20;
    #20;
    #20;

    $finish;
    
end
initial begin
    $monitor("en=%b clk=%b reset=%b I=%b Q=%b",en,clk,reset,I,Q);
end
    
endmodule