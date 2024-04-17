module k21(b,c,d,f);
    input b,c,d;
    output f;
    assign f = (~b|d)&(b|c);
endmodule
