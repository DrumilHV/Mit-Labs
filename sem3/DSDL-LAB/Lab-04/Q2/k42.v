module k42(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	nor(l,b,c);
	nor(m,b,d);
	nor(D,d,d);
	nor(n,a,c,D);
	nor(y,l,m,n);
	nor(f,y,y);
	
	//Correct answer:
	//assign f = ((~b & ~d) | (~b & ~c) | (~a & ~c & d));

endmodule                                                                                                



	
	