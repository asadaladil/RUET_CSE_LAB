`timescale 1ns/1ps
module circuit_tb;
    reg [3:0]F;
    reg en;
    wire [1:0]A;

    circuit uut
    (
        .F(F),
        .en(en),
        .A(A)
    );
    initial begin
        F=4'b0000;
        #20 en=1;
        #20 F[2]=1;
        #20 F[3]=1;
        #20 F=4'b0001;
        #40;
    end
    initial begin
        $monitor("F=%b-->A=%b",F,A);
    end
    endmodule

