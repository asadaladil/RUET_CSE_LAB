module adder4 (
    input wire [3:0]A,B,
    input wire cin,
    output wire [3:0]S,C
);

full_adder c1(cin,A[0],B[0],C[0],S[0]);
full_adder c2(C[0],A[1],B[1],C[1],S[1]);
full_adder c3(C[1],A[2],B[2],C[2],S[2]);
full_adder c4(C[2],A[3],B[3],C[3],S[3]);    
endmodule