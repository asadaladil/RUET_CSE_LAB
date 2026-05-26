module counter (
    input wire reset,clk,en,
    output reg [3:0]q
);

always @(posedge clk) 
begin
    if (reset && en)
        q<=4'b1111;
    else if(en)
        q<=(q-1);
    else
        q<=q;
end
endmodule