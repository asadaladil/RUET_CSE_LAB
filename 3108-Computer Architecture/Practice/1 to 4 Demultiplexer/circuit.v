module circuit (
    input wire [3:0]A,
    input wire [1:0]S,
    input wire en,
    output reg [3:0][3:0]F
);
// using assignment operator
// assign F[0]=(S == 2'b00)&en ? A: 4'bxxxx;
// assign F[1]=(S == 2'b01)&en ? A: 4'bxxxx;
// assign F[2]=(S == 2'b10)&en ? A: 4'bxxxx;
// assign F[3]=(S == 2'b11)&en ? A: 4'bxxxx;
         

// using if else statement
// always @(*) begin
//     if (en==0)
//         F = 16'bxxxx_xxxx_xxxx_xxxx;
//     else
//         F[0]=(S == 2'b00) ? A: 4'bxxxx;
//         F[1]=(S == 2'b01) ? A: 4'bxxxx;
//         F[2]=(S == 2'b10) ? A: 4'bxxxx;
//         F[3]=(S == 2'b11) ? A: 4'bxxxx;
//         end   

// using case statement
always @(*) begin
    case(en)
    1'b1: 
    begin
        F[0]=(S == 2'b00) ? A: 4'bxxxx;
        F[1]=(S == 2'b01) ? A: 4'bxxxx;
        F[2]=(S == 2'b10) ? A: 4'bxxxx;
        F[3]=(S == 2'b11) ? A: 4'bxxxx;
    end
    default: F = 16'bxxxx_xxxx_xxxx_xxxx;
    endcase    
end 
endmodule