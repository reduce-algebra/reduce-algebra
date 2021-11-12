off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0,  - 2100000000*x2*x4 - 92645000*x2 + 1300000000000*x3 + 3*x4 + 250000000000000000, 17*x2 - 520000*x3, 50000000*x2 - 3*x4};

classifyComponents {basis};

end;
