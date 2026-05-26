module counter
(
	input wire CLK,
	input wire Reset,
	output wire [3:0] q
);

	wire [3:0] d_temp, q_temp;
	register register_circuit1 (CLK, Reset, d_temp, q_temp);
	subone sub (q_temp, d_temp);
	assign q = q_temp;

endmodule
