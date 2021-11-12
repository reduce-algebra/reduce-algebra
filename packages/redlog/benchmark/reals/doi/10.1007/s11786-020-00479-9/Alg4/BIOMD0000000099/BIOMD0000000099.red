off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 31*x1 + 6*x5,  - 100*x2*x4 + 29*x5, 5*x2 - 3*x3,  - 13*x4*x7 + 20,  - 9*x5 + 14*x7, 66*x1 - 9*x3*x6,  - 4*x3*x7 + 3*x6};

classifyComponents {basis};

end;
