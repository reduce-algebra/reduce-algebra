off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1000000*x1*x2 + 50000000*x3*x4 + x3,  - 20000000*x1*x2 - 100000*x2*x4 + 20*x3 + x5, 1000000*x1*x2 - 50000000*x3*x4 - x3,  - 100000*x2*x4 - 1000000000*x3*x4 - 1000000*x4*x6 + x5 + 20*x8, 100000*x2*x4 + 1000000000*x3*x4 - 1000000000*x5*x6 - x5 + 2*x7,  - 500000*x4*x6 - 500000000*x5*x6 + x7 + 10*x8, 500000000*x5*x6 - x7, 50000*x4*x6 - x8};

classifyComponents {basis};

end;
