module q1(a,lhs,rhs);
	input a;
	output lhs,rhs;
	assign lhs = ~(~a);
	assign rhs = a;
endmodule

