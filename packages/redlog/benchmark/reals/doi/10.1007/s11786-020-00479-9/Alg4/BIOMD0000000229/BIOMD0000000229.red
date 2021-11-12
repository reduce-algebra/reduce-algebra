off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 9*x1*x3 + 20*x2,  - 9*x2 + 46*x7,  - 3*x3 + 5*x4, 3*x1 - 8*x4*x6, 3*x2 - 4*x3*x5,  - 13*x5*x6 + 10, 7*x1 - 49*x7};

classifyComponents {basis};

end;
