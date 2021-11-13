off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 12*x1*x2 - 2000000*x1 + x4, 8*x1*x3 + 100000*x1 - 125*x2, 4000*x1 - x3, 800000*x3 - 2001*x4, 0};

classifyComponents {basis};

end;
