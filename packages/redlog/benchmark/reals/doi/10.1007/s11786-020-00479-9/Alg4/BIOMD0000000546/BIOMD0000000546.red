off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 1200*x1*x3 + 31*x1, 3*x1*x3 - 750000*x2, 500*x2 - 21*x3,  - 31*x1, 3*x2, 21*x3,  - 100*x2};

classifyComponents {basis};

end;
