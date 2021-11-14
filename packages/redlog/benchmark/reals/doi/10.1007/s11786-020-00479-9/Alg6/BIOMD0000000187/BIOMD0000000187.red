off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x11, x4, x5, x7, x8, -1000000*x1*x2+x3}, {x2, x3, x5, x7, -62500000*x4*x9+x11, -50000*x4*x6+x8}, {x5, x7, x2+100000*x3, 100000000000*x1+500000000*x4+1, -62500000*x4*x9+x11, -50000*x4*x6+x8}, {x11, x9, -50000*x4*x6+x8, -500000000*x5*x6+x7, 100000*x2*x4+10000000000*x3*x4-x5, 20000000*x1*x2+100000*x2*x4-20*x3-x5}, {x6, x7, x8, 62500000*x4*x9-x11, 1000000*x1*x2-500000000*x3*x4-x3, 100000*x2*x4+10000000000*x3*x4-x5, -x11*x2-100000*x11*x3+625*x5*x9, 100000000000*x1*x3*x4+500000000*x3*x4^2-10*x1*x5+x3*x4}};

classifyComponents P;

end;
