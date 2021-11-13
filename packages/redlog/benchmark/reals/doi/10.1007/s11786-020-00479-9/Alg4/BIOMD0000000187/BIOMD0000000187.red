off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1000000*x1*x2 + 500000000*x3*x4 + x3,  - 20000000*x1*x2 - 100000*x2*x4 + 20*x3 + x5, 1000000*x1*x2 - 500000000*x3*x4 - x3, 8*x11 - 100000*x2*x4 - 10000000000*x3*x4 - 1000000*x4*x6 - 500000000*x4*x9 + x5 + 20*x8, 100000*x2*x4 + 10000000000*x3*x4 - 1000000000*x5*x6 - x5 + 2*x7,  - 500000*x4*x6 - 500000000*x5*x6 + x7 + 10*x8, 500000000*x5*x6 - 5000000000*x7*x9 - x7, 50000*x4*x6 - x8, 2*x11 - 125000000*x4*x9 - 2500000000*x7*x9, 100000000*x7*x9,  - 2*x11 + 125000000*x4*x9};

classifyComponents {basis};

end;
