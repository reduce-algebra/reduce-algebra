off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 4000000000000*x1*x4 - 201*x1 + 2500*x3, 0,  - x3 + 480*x4,  - 4000000000000*x1*x4 + 201*x1 - 200000000000*x4**2 + 1200000*x4, 0};

classifyComponents {basis};

end;
