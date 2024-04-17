module dec3to8(en,w,y);
	imput en;
	input[3:0]w;
	output reg [7:0] y;
	intiger i;
	always @(en,w)
	begin
		if(en==0)
			y=0
		else
			begin
				for(i = 0;i<8;i=i+1)
					begin
						if(w==1)
							y[i]=1;
						else
							y[i] = 0;
					end
			end
	end 
endmodule