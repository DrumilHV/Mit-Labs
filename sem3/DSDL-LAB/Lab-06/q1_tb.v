`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [3:0] W;
// reg En;
wire F;
q1 s1(W,F);
initial
begin
$dumpfile("q1_tb.vcd");
$dumpvars(0, q1_tb);
W = 0; #20;
W = 1; #20;
W = 2; #20;
W = 3; #20;
W = 4; #20;
W = 5; #20;
W = 6; #20;
W = 7; #20;
W = 8; #20;
W = 9; #20;
W = 10; #20;
W = 11; #20;
W = 12; #20;
W = 13; #20;
W = 14; #20;
W = 15; #20;

$display("Test complete");
end
endmodule