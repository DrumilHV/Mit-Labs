`include "dec2to4.v";
module dec3to8(in, en ,out);
	input [2:0]in;
	input en;
	output [7:0]out;
	wire en1,en2;

	always@(in or en)
	assign en1 = ~in[2]&en;
	assign en2 = in[2]&en;
	dec2to4 d0(in[1:0],en2,out[4:7]);
	dec2to4 d1(in[1:0],en1,out[3:0]);
endmodule