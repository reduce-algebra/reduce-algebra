off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 2500*x1*x2 - 2500*x1*x5 - 220*x1*x7 + 385000*x3 + 385000*x4 + 33*x8,  - 5*x1*x2 + 770*x3, 5*x1*x2 - 1190*x3, 5*x1*x5 + 420*x3 - 10*x4*x6 - 770*x4,  - 2500*x1*x5 + 385000*x4 - 27*x5*x6 + 10*x7,  - 5000*x4*x6 - 27*x5*x6 + 10*x7,  - 220*x1*x7 + 27*x5*x6 - 10*x7 + 33*x8, 220*x1*x7 - 33*x8, 10*x4*x6};

classifyComponents {basis};

end;
