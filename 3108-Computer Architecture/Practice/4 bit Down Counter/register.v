module register
(
	input wire clk,
	input wire reset,
	input wire [3:0] d,
	output wire [3:0] q
);

reg [3:0] q_reg;
wire [3:0] q_next;

always @(posedge clk, posedge reset)
begin
	if (reset)
    	q_reg<= 4'b1111;
	else
    	q_reg<=q_next;   
end

assign q_next=d;
assign q=q_reg;

endmodule
