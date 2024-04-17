module dec2to4(in, en, out);
	input [1:0]in;
	input en;
	output reg [3:0]out;
	integer k;
	always@(in or en)
	if(en==1)
		begin
			if(in == 0)
				out=1;
			else if(in == 1)
				out = 2;
			else if(in == 2)
				out = 4;
			else if(in == 3)
				out = 8;
		end 
	else
		out = 0;
endmodule



