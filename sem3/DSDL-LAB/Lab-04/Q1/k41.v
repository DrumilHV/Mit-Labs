module k41(a,b,c,d,f);
    input a,b,c,d;
    output f;

    nand(B,b,b);
    nand(l,B,a);
    nand(D,d,d);
    nand(m,D,c);
    nand(n,l,m);
    nand(f,n,n);

    //assign f = ((a ~& (b ~& b)) ~& (c ~& (d ~& d))) ~& ((a ~& (b ~& b)) ~& (c ~& (d ~& d))) ;
endmodule
