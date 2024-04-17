module q2(x,y,z,lhs,rhs);
    input x,y,z;
    output lhs,rhs;
    assign lhs = x & (y|z);
    assign rhs = (x&y) | (x&z);
endmodule
