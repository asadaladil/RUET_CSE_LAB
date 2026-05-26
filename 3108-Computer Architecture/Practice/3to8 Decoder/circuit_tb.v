`timescale 1ns/1ps
module circuit_tb;
   reg [2:0]A;
   reg En;
   wire [7:0]F;

   circuit uut
   (
       .A(A),
       .En(En),
       .F(F)
   );

   initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,circuit_tb);
        A=3'b000;
        En = 0;
        #20;
        En = 1;
        #20;
        A[0] = 1;
        #20;
        A[1] = 1;
        #20;
        A[0] = 0;
        #20;
   end

 initial begin
    $monitor("E=%d A=%b-->F=%b",En,A,F);
 end

endmodule
