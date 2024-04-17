`timescale 1ns/1ns
`include "q1.v" 

module q1_tb();
reg a;
wire lhs,rhs;
q1 q_1(a,lhs,rhs); 
initial
begin
$dumpfile("q1_tb.vcd");
$dumpvars(0, q1_tb);

a=1'b0;
#20;
a=1'b1;
#20;

$display("Test complete");
end
endmodule
