off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 2520*x1*x2 + 2475*x1 - 237,  - 3*x2 + 275*x3, 17*x1 - 1100*x3};

classifyComponents {basis};

end;
