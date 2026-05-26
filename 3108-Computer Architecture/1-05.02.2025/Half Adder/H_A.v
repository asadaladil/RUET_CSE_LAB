module H_A 
(
input A,
input B,
output C,
output S
);

assign C=A&B;
assign S=A^B; 
// and(C,A,B);
// xor(S,A,B);

endmodule