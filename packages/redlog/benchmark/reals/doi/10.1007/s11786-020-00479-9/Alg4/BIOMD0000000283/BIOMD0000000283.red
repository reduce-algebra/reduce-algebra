off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1*x2,  - 2*x1*x2 + x3, 2*x1*x2 - x3, x3};

classifyComponents {basis};

end;
