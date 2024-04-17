`timescale 1ns/1ns
`include "d511.v"
module d511_tb();
reg [1:0]w;
// reg [1:0]en;
wire [7:0]y;
d511 d2to4(w,y);
    initial
    begin
    $dumpfile("d511_tb.vcd");
    $dumpvars(0, d511_tb);
    w = 3'b000; #20;
    w = 3'b001; #20;
    w = 3'b010; #20;
    w = 3'b011; #20;
    w = 3'b100; #20;
    w = 3'b101; #20;
    w = 3'b110; #20;
    w = 3'b111; #20;
$display("Test complete");
end
endmodule