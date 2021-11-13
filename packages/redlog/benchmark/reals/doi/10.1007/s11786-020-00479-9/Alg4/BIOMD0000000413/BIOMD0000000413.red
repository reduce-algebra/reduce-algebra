off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 411*x1*x2 - 395000*x1 + 167000*x3 + 15250000,  - 411*x1*x2 + 167000*x3, 411*x1*x2 - 575000*x3*x5 - 167000*x3 + 2332500*x4, 230*x3*x5 - 933*x4,  - 28750*x3*x5 + 112250*x4 - 79*x5 + 12150};

classifyComponents {basis};

end;
