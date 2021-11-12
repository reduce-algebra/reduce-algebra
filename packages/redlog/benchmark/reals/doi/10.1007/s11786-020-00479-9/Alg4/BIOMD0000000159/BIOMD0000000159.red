off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 32*x1*x2 + 3,  - x2 + x3, 4*x1 - x3};

classifyComponents {basis};

end;
