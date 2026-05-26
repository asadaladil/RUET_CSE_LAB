module sub1 (
    input wire A,
    input wire B,
    input wire Bin,
    output wire D,
    output wire Bout
);

assign D=A^B^Bin;
assign Bout=Bin&(~(A^B)) || (~A)&B;    


endmodule