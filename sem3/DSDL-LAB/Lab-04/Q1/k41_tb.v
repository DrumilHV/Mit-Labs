`timescale 1ns/1ns
`include "k41.v" 

module k41_tb();
reg a,b,c,d;
wire f;

k41 K41(a,b,c,d,f);
initial 
begin

	$dumpfile("k41_tb.vcd");
	$dumpvars(0,k41_tb);	
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