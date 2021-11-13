off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1**2*x4 + x1*x4 - 100000*x1 + 10000000*x3 + 20000*x6,  - x2**2*x3 + x2*x3 - 100000*x2 + 10000000*x4 + 20000*x5,  - x2**2*x3 + x2*x3 + 20000*x5,  - x1**2*x4 + x1*x4 + 20000*x6, x2**2*x3 - x2*x3 - 20000*x5, x1**2*x4 - x1*x4 - 20000*x6, x1 - 100*x3, x2 - 100*x4};

classifyComponents {basis};

end;
