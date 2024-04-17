module exercise2(a,b,c,d,f,g);
	input a,b,c,d;
	output j,g;
	nand(k,a,b);
	xor(f,d,c,k);
	nor(g,c,d,b);
endmodule

