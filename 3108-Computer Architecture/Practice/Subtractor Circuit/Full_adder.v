module full_adder (
    input wire cin,
    input wire A,
    input wire B,
    output wire C,
    output wire S
);
    assign S=(A^B^cin);
    assign C=A&B || B&cin || A&cin;
endmodule