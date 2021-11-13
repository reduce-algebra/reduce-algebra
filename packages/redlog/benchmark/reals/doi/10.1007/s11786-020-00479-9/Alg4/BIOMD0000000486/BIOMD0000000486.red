off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 3*x1 + 25*x2, 3*x1 - 25*x2};

classifyComponents {basis};

end;
