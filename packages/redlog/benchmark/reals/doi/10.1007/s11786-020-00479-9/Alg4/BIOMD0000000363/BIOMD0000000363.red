off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 501*x1, x1 - 2*x2, 400*x2 + x4, 2*x1 - 5*x4};

classifyComponents {basis};

end;
