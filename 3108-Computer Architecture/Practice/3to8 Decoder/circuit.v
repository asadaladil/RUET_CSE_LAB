module circuit (
    input wire [2:0]A,
    input wire En,
    output wire [7:0]F
);
 // using assign statement....
    // assign F[0]=(~A[2])&(~A[1])&(~A[0])&En;
    // assign F[1]=(~A[2])&(~A[1])&(A[0])&En;
    // assign F[2]=(~A[2])&(A[1])&(~A[0])&En;
    // assign F[3]=(~A[2])&(A[1])&(A[0])&En;
    // assign F[4]=(A[2])&(~A[1])&(~A[0])&En;
    // assign F[5]=(A[2])&(~A[1])&(A[0])&En;
    // assign F[6]=(A[2])&(A[1])&(~A[0])&En;
    // assign F[7]=(A[2])&(A[1])&(A[0])&En;

    //assign F=En?8'b1<<A:8'b0;


// using if else statement
// always @* 
// begin
//     if(En==1'b0)
//         F=8'b00000000;
//     else if (A==3'b000)
//         F=8'b00000001;
//     else if (A==3'b001)
//         F=8'b00000010;
//     else if (A==3'b010)
//         F=8'b00000100;
//     else if (A==3'b011)
//         F=8'b00001000;
//     else if (A==3'b100)
//         F=8'b00010000;
//     else if (A==3'b101)
//         F=8'b00100000;
//     else if (A==3'b110)
//         F=8'b01000000;
//     else if (A==3'b111)
//         F=8'b10000000;
// end

// always @* 
// begin
//     if(En==1'b0)
//         F=8'b00000000;
//     else
//         F=(8'b1 << A);
// end

// using case statement
always @* 
begin
    case(En)
        1'b1 : F=(8'b1 << A);
        default : F=8'b0000_0000;
    endcase
end
endmodule