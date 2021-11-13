off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 200*x1*x13 + 6*x2 + x5, 200*x1*x13 - 7*x2,  - 200*x13*x3 + x2 - 50*x3*x4 + 4*x5 + 6*x6 + x8,  - 10*x3*x4 - 10*x4*x7 + x5 + x8, 10*x3*x4 - x5, 200*x13*x3 - 7*x6,  - 50*x4*x7 + x6 + 4*x8, 10*x4*x7 - x8, 5*x12 + 21*x16 - 165*x19*x9,  - 100*x10*x11 - 33*x10*x19 + 8*x12 + x14 + 4*x15 + x16,  - 100*x10*x11 - 100*x11*x13 + 9*x12 + 9*x14, 100*x10*x11 - 9*x12,  - 200*x1*x13 - 100*x11*x13 - 200*x13*x3 + 8*x14 + x15 + 7*x2 + 7*x6, 100*x11*x13 - 9*x14, 33*x10*x19 - 5*x15,  - 26*x16 + 165*x19*x9,  - 10*x17*x18 + x21 + 4*x22,  - 2*x17*x18 + x22,  - 165*x10*x19 + 25*x15 + 26*x16 - 25*x19*x20 - 165*x19*x9 + 25*x21 + 5*x22,  - 5*x19*x20 + 6*x21, 5*x19*x20 - 6*x21, 2*x17*x18 - x22};

classifyComponents {basis};

end;
