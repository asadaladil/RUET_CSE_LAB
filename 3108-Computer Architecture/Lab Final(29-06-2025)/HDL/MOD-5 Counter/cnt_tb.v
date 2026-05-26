`timescale 1ns/1ps
module cnt_tb;
reg clk;
reg reset;
wire [2:0]q;

counter uut(clk,reset,q);

always begin
    clk=~clk;
    #10;    
end

initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,cnt_tb);

    clk<=0;
    reset<=1;
    #20;
    reset<=0;
    #20;#20;#20;
    #40;

    $finish;

end

initial begin
    $monitor("reset=%b clk=%b q=%b",reset,clk,q);
end
    
endmodule