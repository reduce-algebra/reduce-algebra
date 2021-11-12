off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1*x2 - 2*x1*x4,  - x1*x2 - 2*x2*x5, x1*x2 - 8*x3*x4 + 20000*x6,  - x1*x4 + 200000*x16*x8 - 4*x3*x4 - 40*x4, x1*x4 - x2*x5, x2*x5 + 4*x3*x4 - 10000*x6,  - 2000*x12*x7 + 40*x4 + 10000*x6 - 100000*x7*x9 - x7,  - 5000*x16*x8 + x4 + 250*x6, 25*x10 - 500*x14*x9 + 3*x15 - 5000*x7*x9,  - 5*x10 + 1000*x7*x9, 500*x10 - 200000*x11 + x14 + 60*x15 + x7,  - 10*x12*x7 + x13, 10*x12*x7 - x13, 200*x13 - 10000*x14*x9 - x14, 500*x14*x9 - 3*x15, 1000*x11 - 1000*x16*x8, 1000*x11 - 10*x17, 3*x13 - 3*x18, 3*x18 - 3*x19, 3*x19 - 3*x20};

classifyComponents {basis};

end;
