module and_or(a,b,c,lhs,rhs);
    input a,b,c;
    output lhs,rhs;
    assign lhs = (a|(b&c))&(b|(c&a));
    assign rhs = (a&b)|(b&c)|(c&a);
endmodule
