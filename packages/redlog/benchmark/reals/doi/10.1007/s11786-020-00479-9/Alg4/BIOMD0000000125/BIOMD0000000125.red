off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1 + 2*x4 + x5, 2*x1 - x2, x1 - x3, 0, 0};

classifyComponents {basis};

end;
