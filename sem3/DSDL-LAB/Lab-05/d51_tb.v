`timescale 1ns/1ns
`include "d51.v"
module d51_tb();
reg [3:0]w;
reg en;
wire y;
d51 dec2to4(en,w,y);
initial
begin
$dumpfile("d51_tb.vcd");
$dumpvars(0, d51_tb);
w = 2'b00; y = 1'b0; 
#20;
w = 2'b01; y = 1'b0; 
#20;
w = 2'b10; y = 1'b0; 
#20;
w = 2'b11; y = 1'b0; 
#20;
w = 2'b00; y = 1'b1; 
#20;
w = 2'b01; y = 1'b1; 
#20;
w = 2'b10; y = 1'b1; 
#20;
w = 2'b11; y = 1'b1; 
#20;
$display("Test complete");
end
endmodule