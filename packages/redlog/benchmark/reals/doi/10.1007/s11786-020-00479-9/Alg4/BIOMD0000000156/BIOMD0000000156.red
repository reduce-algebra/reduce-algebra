off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 37*x1*x2 + 20*x1,  - 9*x2 + 11*x3, 15*x1 - 11*x3};

classifyComponents {basis};

end;
