off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1 + 10*x26 + 100*x27 + 2*x28, 100*x1 - 10*x14*x2 - 50*x2*x3 + 10*x4 + 10*x6, 10000*x13*x8 - 50*x2*x3 - 100*x3 + 110*x4, 50*x2*x3 - 110*x4, 100*x4 - 100*x5, 10*x14*x2 - 10*x6, x14**2 - x7,  - 1000000*x13*x8 + 10000*x3 - x8 + 1, 10*x30 + 100*x31 - x9,  - 100*x10 + 100*x9,  - 5*x11 + x30 + 10*x31, 100*x11 - 100*x12, 0, 0,  - x15 + 2*x29, 100*x15 - 100*x16,  - 100*x17*x18 + 100*x24,  - 1000*x17*x18 - x18 + 1000*x24 + 1,  - 100*x19*x25 + 100*x23*x24,  - 100*x20*x25 + 100*x22*x24,  - x21 + 100*x32, 100*x20*x25 + 100*x21 - 100*x22*x24 - 100*x22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

classifyComponents {basis};

end;
