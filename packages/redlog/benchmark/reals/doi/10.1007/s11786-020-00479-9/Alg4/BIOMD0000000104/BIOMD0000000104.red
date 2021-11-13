off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - x1*x3, x1*x3 - x2*x4, 0, 0, x2*x4, 0};

classifyComponents {basis};

end;
