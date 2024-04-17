`timescale 1ns/1ns
`include "k42.v" 

module k42_tb();
reg a,b,c,d;
wire f;

k42 K42(a,b,c,d,f);
initial 
begin

	$dumpfile("k42_tb.vcd");
	$dumpvars(0,k42_tb);	
	a=1'b0; b=1'b0; c=1'b0; d=1'b0;
	#20;	
	a=1'b0; b=1'b0; c=1'b0; d=1'b1;
	#20;	
	a=1'b0; b=1'b0; c=1'b1; d=1'b0;
	#20;	
	a=1'b0; b=1'b0; c=1'b1; d=1'b1;
	#20;	
	a=1'b0; b=1'b1; c=1'b0; d=1'b0;
	#20;	
	a=1'b0; b=1'b1; c=1'b0; d=1'b1;
	#20;	
	a=1'b0; b=1'b1; c=1'b1; d=1'b0;
	#20;	
	a=1'b0; b=1'b1; c=1'b1; d=1'b1;
	#20;
	a=1'b1; b=1'b0; c=1'b0; d=1'b0;
	#20;	
	a=1'b1; b=1'b0; c=1'b0; d=1'b1;
	#20;	
	a=1'b1; b=1'b0; c=1'b1; d=1'b0;
	#20;	
	a=1'b1; b=1'b0; c=1'b1; d=1'b1;
	#20;	
	a=1'b1; b=1'b1; c=1'b0; d=1'b0;
	#20;	
	a=1'b1; b=1'b1; c=1'b0; d=1'b1;
	#20;	
	a=1'b1; b=1'b1; c=1'b1; d=1'b0;
	#20;	
	a=1'b1; b=1'b1; c=1'b1; d=1'b1;
	#20;
	$display("Test Complete");
end

endmodule