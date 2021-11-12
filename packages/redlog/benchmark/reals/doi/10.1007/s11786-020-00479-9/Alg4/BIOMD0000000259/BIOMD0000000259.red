off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 2001*x1 + 6*x11 + 41*x12 + 20*x13 + 5*x14 + 10*x16 + 2*x17 + 1461*x4 + 25*x5 + 3*x6 + 17*x7, 1322*x1 - 241*x2, 185*x2 - 3*x3, 56*x2 + 3*x3 - 1461*x4, 227*x1 - 25*x5, 96*x1 - 3*x6, 2*x1 - 17*x7, 104*x1 - 3*x8, 49*x1 - 15*x9, 18*x15 + 3*x8 + 30*x9, 11*x1 - 6*x11, 79*x1 - 41*x12, 21*x1 - 10*x13, 4*x1 - 5*x14, 9*x1 - 18*x15, 2*x1 - 5*x16, 3*x1 - 2*x17};

classifyComponents {basis};

end;
