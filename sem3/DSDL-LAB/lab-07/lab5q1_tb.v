`timescale 1ns/1ns
`include "l5q13to8dec.v"
// `include "lab5q1.v";
module l5q13to8dec_tb();
reg [1:0]in;
reg en;
wire [3:0]out;
dec2to4 d0(in, en, out);
initial
begin
$dumpfile("l5q13to8dec.vcd");
$dumpvars(0,l5q13to8dec_tb);
in = 0;en =1'b0;#20;
in = 1;en =1'b0;#20;
in = 2;en =1'b0;#20;
in = 3;en =1'b0;#20;
in = 4;en =1'b0;#20;
in = 5;en =1'b0;#20;
in = 6;en =1'b0;#20;
in = 7;en =1'b0;#20;
in = 8 ; en =1'b1;#20;
in = 9;  en =1'b1;#20;
in = 10 ;en =1'b1;#20;
in = 11 ;en =1'b1;#20;
in = 12 ;en =1'b1;#20;
in = 13 ;en =1'b1;#20;
in = 14; en =1'b1;#20;
in = 15; en =1'b1;#20;
$display("Test Done");
end 
endmodule

