off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 23*x1, 57*x1 - 2632*x2, 156*x1 - 2259*x3, 155*x1 - 34*x4*x5 - 159*x4 + 907*x6, 155*x1 + 2632*x2 + 2259*x3 - 34*x4*x5, 22*x11 + 794*x2 - 1181*x6, 159*x4 + 274*x6, 425*x3 - 3817*x8, 159*x4 + 19085*x8,  - 8*x10 + 707*x2, 8*x10 - 22*x11 + 1131*x2, 159*x4, 17*x4*x5, 67*x3};

classifyComponents {basis};

end;
