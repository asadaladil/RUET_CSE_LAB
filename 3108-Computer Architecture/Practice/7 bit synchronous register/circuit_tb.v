`timescale 1ns/1ns

module circuit_tb;
	reg clk;
	reg en;
	reg reset;
	reg [6:0] d;
	wire [6:0] q;

circuit uut (clk,en, reset, d, q);

always begin
	clk = ~clk;
	#10;
end
initial begin

	clk<=0;
	en=0;
	reset<=1;
	d <= 7'b11;
	#20;
	reset<=0;
	en=0;
	d<=7'b1110;
	#20;
	en=1;
	#20;

    $finish; // finish for 1 step count. otherwise it will run infinite time
end
initial begin
	$monitor("clk = %b, reset = %b, en=%b, d = %b, q = %b", clk, reset,en, d, q);
end

endmodule
