`timescale 1ns/1ns
`include "not_and.v" 

module not_and_tb();
reg a,b,c;
wire lhs;
not_and no_and(a,b,c,lhs); 
initial
begin
$dumpfile("not_and_tb.vcd");
$dumpvars(0, not_and_tb);

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
