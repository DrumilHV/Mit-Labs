`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg x,y,z;
wire lhs,rhs;
q2 q_2(x,y,z,lhs,rhs); 
initial
begin
$dumpfile("q2_tb.vcd");
$dumpvars(0, q2_tb);

x=1'b0; y=1'b0; z=1'b0;
#20;
x=1'b0; y=1'b0; z=1'b1;
#20;
x=1'b0; y=1'b1; z=1'b0;
#20;
x=1'b0; y=1'b1; z=1'b1;
#20;
x=1'b1; y=1'b0; z=1'b0;
#20;
x=1'b1; y=1'b0; z=1'b1;
#20;
x=1'b1; y=1'b1; z=1'b0;
#20;
x=1'b1; y=1'b1; z=1'b1;
#20;


$display("Test complete");
end
endmodule
