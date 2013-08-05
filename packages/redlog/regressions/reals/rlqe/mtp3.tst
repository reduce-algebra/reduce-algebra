% Testing rlqe (xopt-qe)
% Multi-Index Transportation Problem

rlset reals;

mtp3 :=
ex(x111,ex(x112,ex(x113,ex(x121,ex(x122,ex(x123,ex(x131,ex(x132,ex(x133,
ex(x211,ex(x212,ex(x213,ex(x221,ex(x222,ex(x223,ex(x231,ex(x232,ex(x233,
ex(x311,ex(x312,ex(x313,ex(x321,ex(x322,ex(x323,ex(x331,ex(x332,ex(x333,
x111+x211+x311=a11 and x112+x212+x312=a12 and x113+x213+x313=a13 and
x121+x221+x321=a21 and x122+x222+x322=a22 and x123+x223+x323=a23 and
x131+x231+x331=a31 and x132+x232+x332=a32 and x133+x233+x333=a33 and
x111+x121+x131=b11 and x112+x122+x132=b12 and x113+x123+x133=b13 and
x211+x221+x231=b21 and x212+x222+x232=b22 and x213+x223+x233=b23 and
x311+x321+x331=b31 and x312+x322+x332=b32 and x313+x323+x333=b33 and
x111+x112+x113=c11 and x121+x122+x123=c12 and x131+x132+x133=c13 and
x211+x212+x213=c21 and x221+x222+x223=c22 and x231+x232+x233=c23 and
x311+x312+x313=c31 and x321+x322+x323=c32 and x331+x332+x333=c33 and
0 leq x111 and 0 leq x112 and 0 leq x113 and
0 leq x121 and 0 leq x122 and 0 leq x123 and
0 leq x131 and 0 leq x132 and 0 leq x133 and
0 leq x211 and 0 leq x212 and 0 leq x213 and
0 leq x221 and 0 leq x222 and 0 leq x223 and
0 leq x231 and 0 leq x232 and 0 leq x233 and
0 leq x311 and 0 leq x312 and 0 leq x313 and
0 leq x321 and 0 leq x322 and 0 leq x323 and
0 leq x331 and 0 leq x332 and 0 leq x333)))))))))))))))))))))))))))$

rlqe mtp3;

end;
