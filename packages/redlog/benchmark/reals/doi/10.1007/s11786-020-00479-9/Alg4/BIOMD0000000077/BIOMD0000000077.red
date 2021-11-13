off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 5*x1*x3 + 10*x2, 5*x1*x3 - 10000*x2**2 - 10*x2 + 20*x4,  - 5*x1*x3 + 10*x2, 2500*x2**2 - 4000*x4*x6 - 5*x4 + 200*x5, 4000*x4*x6 - 200*x5,  - 4000*x4*x6 + 200*x5, 20000000*x5 - 10*x7, 0};

classifyComponents {basis};

end;
