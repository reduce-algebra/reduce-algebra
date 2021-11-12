off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1300*x1 + 2500*x7 + 91*x8, 26000*x1 - 1260000*x2 + x8, 126*x2 - 26*x3, 130*x3 - 13*x4, 13*x4 - 630*x5, 126*x5 - 26*x6, 130*x6 - 38*x7, 26000*x7 - 1821*x8, 0, 0, 0, 0, 0, 0, 0};

classifyComponents {basis};

end;
