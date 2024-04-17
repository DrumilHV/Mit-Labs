`timescale 1ns/1ns
`include "and_or.v" 

module and_or_tb();
reg a,b,c;
wire lhs,rhs;
and_or andor(a,b,c,lhs,rhs); 
initial
begin
$dumpfile("and_or_tb.vcd");
$dumpvars(0, and_or_tb);

a=1'b0; b=1'b0; c=1'b0;
#20;
a=1'b0; b=1'b0; c=1'b1;
#20;
a=1'b0; b=1'b1; c=1'b0;
#20;
a=1'b0; b=1'b1; c=1'b1;
#20;
a=1'b1; b=1'b0; c=1'b0;
#20;
a=1'b1; b=1'b0; c=1'b1;
#20;
a=1'b1; b=1'b1; c=1'b0;
#20;
a=1'b1; b=1'b1; c=1'b1;
#20;



$display("Test complete");
end
endmodule
