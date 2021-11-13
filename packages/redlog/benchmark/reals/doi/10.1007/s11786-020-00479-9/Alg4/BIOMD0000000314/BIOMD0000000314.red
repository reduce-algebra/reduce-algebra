off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 2596860*x1 + 39243*x2, 2596860*x1 - 39243*x2,  - 907541*x3*x7, 4537705*x3*x7 - 162066*x4, 162066*x4 - 208769*x5,  - 3000190*x3*x6 - 3000190*x4*x6 + 981611*x7*x8, 3000190*x3*x6 + 3000190*x4*x6 - 981611*x7*x8, 0, 1163890*x10*x8 - 426767*x7*x9,  - 1163890*x10*x8 + 426767*x7*x9, 14491*x10, 0};

classifyComponents {basis};

end;
