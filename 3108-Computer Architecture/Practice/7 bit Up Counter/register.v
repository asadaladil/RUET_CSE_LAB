module register
(
	input wire clk,
	input wire reset,
	input wire [6:0] d,
	output wire [6:0] q
);

//signal declaration
reg [6:0] q_reg ;
wire [6:0] q_next ;
// body or memory or state register
always @(posedge clk, posedge reset)
begin
	if (reset)
    	q_reg <= 7'b0000_000;
	else
    	q_reg <= q_next;   
end

//next state logic
assign q_next = d;

//output logic
assign q = q_reg;
    
endmodule