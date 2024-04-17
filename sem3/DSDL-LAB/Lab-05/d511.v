`include "d51.v"
module d511(input [2:0]w, output reg [7:0]y);

d51 s1(w[1:0],~w[2],y[3:0]);
d51 s2(w[1:0],w[2],y[7:4]);

endmodule

