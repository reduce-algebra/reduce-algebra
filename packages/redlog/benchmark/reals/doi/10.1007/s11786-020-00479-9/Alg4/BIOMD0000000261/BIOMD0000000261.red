off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 19998*x1 + 170*x11 + 86*x12 + 230*x13 + 67*x14 + 99*x16 + 28*x17 + 1910*x4 + 100*x5 + 140*x6 + 240*x7, 3460*x1 - 273*x2, 125*x2 - 8*x3, 23*x2 + 16*x3 - 955*x4, 105*x1 - 2*x5, 126*x1 - 7*x6, 19*x1 - 120*x7, 665*x1 - 36*x8, 93*x1 - 22*x9, 145*x15 + 36*x8 + 110*x9, 36*x1 - 17*x11, 315*x1 - 43*x12, 162*x1 - 23*x13, 43*x1 - 67*x14, 27*x1 - 29*x15, 66*x1 - 99*x16, 21*x1 - 28*x17};

classifyComponents {basis};

end;
