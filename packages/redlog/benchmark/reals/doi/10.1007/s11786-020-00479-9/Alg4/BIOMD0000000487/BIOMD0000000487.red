off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 10*x1*x2 + 11*x3,  - 10*x1*x2 + 10*x3 + x6, 10*x1*x2 - 11*x3,  - 10*x4*x5 + 11*x6, x3 - 10*x4*x5 + 10*x6, 10*x4*x5 - 11*x6};

classifyComponents {basis};

end;
