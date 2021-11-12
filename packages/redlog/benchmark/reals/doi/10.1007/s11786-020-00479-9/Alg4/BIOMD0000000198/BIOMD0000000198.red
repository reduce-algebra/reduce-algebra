off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0,  - 350*x2 + 800*x3, 350*x2 - 1650*x3, 4250*x3 - 100*x4 + x5, 100*x4 - x5,  - 350*x6 + 800*x7, 350*x6 - 1650*x7, 1700*x7 - 5*x8 + 50*x9, x10 + 125*x8 - 1330*x9,  - x10 + 80*x9, 0, 0};

classifyComponents {basis};

end;
