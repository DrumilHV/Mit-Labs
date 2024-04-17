module k11(a,b,c,d,f);
    input a,b,c,d;
    output f;
    assign f = (~a & b) | (~b & c) | (c & d) | (b & ~c & ~d);
endmodule
