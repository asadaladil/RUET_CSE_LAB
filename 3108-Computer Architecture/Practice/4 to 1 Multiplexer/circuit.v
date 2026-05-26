module circuit (
    input wire [3:0][3:0]A,
    input wire [1:0]S,
    input wire en,
    output reg [3:0]F
);
// using assignment operator
// assign F=(S == 2'b00) ? A[0] :
//          (S == 2'b01) ? A[1] :
//          (S == 2'b10) ? A[2] : A[3];

// using if else statement
// always @(*) begin
//     if (en==0)
//         F = 4'bxxxx;
//     else
//         F=(S == 2'b00) ? A[0] :
//          (S == 2'b01) ? A[1] :
//          (S == 2'b10) ? A[2] : A[3];
// end   

// using case statement
always @(*) begin
    case(en)
    1'b1: F=(S == 2'b00) ? A[0] :
         (S == 2'b01) ? A[1] :
         (S == 2'b10) ? A[2] : A[3];
    default: F=4'bxxxx; 
    endcase    
end 
endmodule