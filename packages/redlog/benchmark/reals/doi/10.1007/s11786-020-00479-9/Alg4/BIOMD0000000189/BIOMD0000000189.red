off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 23100*x1*x2 - 200000*x1*x5 - 8660*x1 + 16731*x3 + 9900*x4,  - 23100*x1*x2 + 231*x3 + 1560000, 23100*x1*x2 - 16731*x3, x2 - x4,  - 10000*x1*x5 - 100*x5 + 1000*x6 + 33*x7, 10*x1*x5 - x6,  - x7, 0, 0, 33*x3, 39, 433*x1 + 1000*x6, 99*x4, x4, x2, 0, 0, 0};

classifyComponents {basis};

end;
