module Full_sub (
    input wire [3:0]A,
    input wire [3:0]B,
    input wire Bin,
    output wire [3:0]D,
    output wire [3:0]Bout
);


sub1 s0(A[0],B[0],Bin,D[0],Bout[0]);
sub1 s1(A[1],B[1],Bout[0],D[1],Bout[1]);
sub1 s2(A[2],B[2],Bout[1],D[2],Bout[2]);
sub1 s3(A[3],B[3],Bout[2],D[3],Bout[3]);

    
endmodule