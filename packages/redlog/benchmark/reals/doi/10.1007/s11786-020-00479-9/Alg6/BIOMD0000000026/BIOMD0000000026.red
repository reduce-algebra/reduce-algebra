off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x10, x11, x4, x5, x6, x7, x8, x9}, {50*x10-x6, 23*x8-3750*x7, 100*x9-3*x6-1500*x7, 69*x1*x3-9191*x2^2, 2*x1*x4-101*x6, x2*x4-500*x7, x2*x5-3*x6, 23*x3*x5-91000*x7, 1000*x1*x7-101*x2*x6, -91000*x2*x7+69*x3*x6, 3*x4*x6-500*x5*x7, 860000*x11*x7-3333*x6^2-100000*x6*x7, 33*x1*x6-860*x11*x2+100*x2*x6, 11*x1*x5-860*x11+100*x6, 59340*x11*x3-303303*x2*x6-9100000*x2*x7, 5160*x11*x4-3333*x5*x6-100000*x5*x7}};

classifyComponents P;

end;
