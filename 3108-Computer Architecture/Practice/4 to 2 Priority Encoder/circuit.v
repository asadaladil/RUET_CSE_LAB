module circuit (
    input wire [3:0]F,
    input wire en,
    output reg [1:0]A
);

// using assignment Operator....
// assign A[0]=((~F[3])&(~F[2])&(F[1]) || F[3])&en;
// assign A[1]=((~F[3])&(F[2]) || F[3])&en;


// using if else statement.....
// always @(*) begin
//     if (en==0)
//         A=2'b00;
//     else
//        A[0]=((~F[3])&(~F[2])&(F[1]) || F[3]);
//        A[1]=((~F[3])&(F[2]) || F[3]); 
// end

// using case statement....
always @(*) begin
    case(en)
    1'b1: 
    begin 
        A[0]=((~F[3])&(~F[2])&(F[1]) || F[3]);
        A[1]=((~F[3])&(F[2]) || F[3]);
    end
    default : A=2'b00;
    endcase
end
endmodule