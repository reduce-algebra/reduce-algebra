off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 6*x1*x3 + x2, 300*x1*x3 - 7*x2*x4 - 50*x2 + 100*x5,  - 6*x1*x3 + x2,  - 7*x2*x4 + 100*x5, 7*x2*x4 - 100*x5};

classifyComponents {basis};

end;
