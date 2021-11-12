off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1000000*x1*x2 + 5000000000*x3*x4 + x3,  - 20000000*x1*x2 + 20*x3 + x5, 1000000*x1*x2 - 5000000000*x3*x4 - x3,  - 100000000000*x3*x4 + x5, 100000000000*x3*x4 - x5};

classifyComponents {basis};

end;
