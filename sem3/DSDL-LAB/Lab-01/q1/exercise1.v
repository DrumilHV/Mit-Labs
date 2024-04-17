module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	and(k1,a,b);
	or(k2,k1,c);
	not(k3,k2);
	and(k4,k3,d);
	and(l1,a,b);
	or(l2,l1,c);
	or(l3,l2,d);
	and(f,k4,l3);
endmodule

