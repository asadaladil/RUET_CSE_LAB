module AC_BD (
    input A,B,C,D,
    // input B,
    // input C,
    // input D,
    output Z
);
wire p,q;
assign p=A&C;
assign q=B&D;
assign Z=p||q;
endmodule