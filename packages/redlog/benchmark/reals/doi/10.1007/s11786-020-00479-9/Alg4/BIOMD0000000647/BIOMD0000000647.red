off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 5300*x1*x2 + 72*x3 + 315*x4,  - 1325*x1*x2 + 2175*x11 + 18*x3, 10600*x1*x2 - 12500*x3*x9 - 144*x3 + 49*x4, 12500*x3*x9 - 679*x4, 63*x4 - 1600*x5*x7 + 15*x8,  - 46000*x10*x6 + 61*x11 + 1575*x4,  - 1600*x5*x7 + 157*x8, 1600*x5*x7 - 157*x8,  - 12500*x3*x9 + 49*x4 + 1420*x8,  - 46000*x10*x6 + 43561*x11, 46000*x10*x6 - 43561*x11};

classifyComponents {basis};

end;
