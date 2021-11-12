off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0,  - 2*x10*x2 - x2*x4 - x2*x6 - x2 + 50*x5 + 100*x7 + 50*x8, 2*x10*x2 - x3,  - x2*x4 + 50*x5, x2*x4 - 50*x5,  - x2*x6 + 100*x7, x2*x6 - 100*x7, 50*x4 + 500*x5 - 10*x8, x6 + 5000*x7 - 50*x9,  - 10*x10*x2 - x10 + 5*x3 + 25*x9};

classifyComponents {basis};

end;
