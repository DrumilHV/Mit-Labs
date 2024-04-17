`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg x,y,z;
wire lhs,rhs;
q3 q_3(x,y,z,lhs,rhs); 
initial
begin
$dumpfile("q3_tb.vcd");
$dumpvars(0, q3_tb);

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
