`timescale 1ns/1ns

module circuit_tb;
	reg clk;
	reg reset;
	reg [15:0] d;
	wire [15:0] q;

circuit uut (clk, reset, d, q);

always begin
	clk = ~clk;
	#10;
end
initial begin

	clk <= 0;
	reset <= 1;
	d <= 16'b0;
	#20;

	reset <= 0;
	d <= 16'b1110;
	#20;
    $finish; // finish for 1 step count.
end
initial begin
	$monitor("clk = %b, reset = %b, d = %b, q = %b", clk, reset, d, q);
end

endmodule
