module not_and(a,b,c,lhs);
    input a,b,c;
    output lhs;
    assign lhs = ~(~(a&b) & ~(a&c) & ~(b&c));
endmodule
