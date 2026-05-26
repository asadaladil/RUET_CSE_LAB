`timescale 1ns/1ns

module counter_tb;
	reg clk;
	reg reset;
	wire [3:0]q;

counter count(clk,reset,q);

always begin
	clk = ~clk;
	#10;
end
initial begin

	clk<=0;
	reset<=1;
	#20;
	reset<=0;
	#20;
	#20;
	#20;
	#20;
	#20;

    $finish; // finish for 1 step count. otherwise it will run infinite time
end
initial begin
	$monitor("clk = %b, reset = %b, q = %b", clk, reset, q);
end

endmodule
