module k44(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	nor(l,a,d);
	nor(m,d,c);
	nor(n,l,m);
	nor(f,n,n);
	
	//left = (a ~| (d ~| d))
	//right = (c ~| (d ~| d))
	//left nor right = ((a ~| (d ~| d)) ~| (c ~| (d ~| d)))
	
	// assign f = (((a ~| (d ~| d)) ~| (c ~| (d ~| d))) ~| ((a ~| (d ~| d)) ~| (c ~| (d ~| d))));
	
	//Correct answer 
	//assign f = ((~a & d) | (~c & d));
	
endmodule