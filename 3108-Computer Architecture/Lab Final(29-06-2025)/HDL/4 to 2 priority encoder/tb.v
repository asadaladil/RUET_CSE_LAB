`timescale 1ns/1ps
module  tb;
reg [3:0]A;
wire [1:0]Y;

priority_encoder uut(A,Y);

initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,tb);

    A=4'b0111;
    #20;
    A=4'b1111;
    #20;
    A=4'b0011;
end

initial begin
    $monitor("A=%b Y=%b",A,Y);
end


endmodule