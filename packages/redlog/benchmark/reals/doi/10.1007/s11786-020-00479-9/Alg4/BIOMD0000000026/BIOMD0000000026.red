off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 200*x1*x4 - 11*x1*x5 + 860*x11 + 10000*x6, 500*x10 - 16*x2*x4 - 10*x2*x5 + 5*x6 + 500*x7 + 500*x9,  - 9*x3*x5 + 3000*x7 + 200*x8,  - 10*x1*x4 - 16*x2*x4 + 505*x6 + 8000*x7,  - 11*x1*x5 + 10000*x10 + 860*x11 - 200*x2*x5 - 450*x3*x5 + 10000*x8 + 10000*x9, 2*x1*x4 - 101*x6, 4*x2*x4 - 2000*x7, 45*x3*x5 - 1092*x8, 5*x2*x5 + 46*x8 - 500*x9,  - 150*x10 + x2*x5, 11*x1*x5 + 5000*x10 - 860*x11};

classifyComponents {basis};

end;
