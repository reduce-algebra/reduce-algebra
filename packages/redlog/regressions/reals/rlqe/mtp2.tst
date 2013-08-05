% Testing rlqe (xopt-qe)
% Multi-Index Transportation Problem

rlset reals;

mtp2 := ex(x11,ex(x12,ex(x13,ex(x21,ex(x22,ex(x23,ex(x31,ex(x32,ex(x33,
x11+x12+x13=a1 and x21+x22+x23=a2 and x31+x32+x33=a3 and
x11+x21+x31=b1 and x12+x22+x32=b2 and x13+x23+x33=b3 and
0 leq x11 and 0 leq x12 and 0 leq x13 and
0 leq x21 and 0 leq x22 and 0 leq x23 and
0 leq x31 and 0 leq x32 and 0 leq x33
)))))))))$

rlqe mtp2;

end;
