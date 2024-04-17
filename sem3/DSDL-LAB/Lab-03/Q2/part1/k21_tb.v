`timescale 1ns/1ns
`include "k21.v" 

module k2_tb();
reg b,c,d;
wire f;
k21 K21(b,c,d,f); 
initial
begin
$dumpfile("k21_tb.vcd");
$dumpvars(0, k2_tb);

b=1'b0; c=1'b0; d=1'b0; 
#20;
b=1'b0; c=1'b0; d=1'b1; 
#20;
b=1'b0; c=1'b1; d=1'b0; 
#20;
b=1'b0; c=1'b1; d=1'b1; 
#20;
b=1'b1; c=1'b0; d=1'b0; 
#20;
b=1'b1; c=1'b0; d=1'b1; 
#20;
b=1'b1; c=1'b1; d=1'b0; 
#20;
b=1'b1; c=1'b1; d=1'b1; 
#20;

$display("Test complete");
end
endmodule
