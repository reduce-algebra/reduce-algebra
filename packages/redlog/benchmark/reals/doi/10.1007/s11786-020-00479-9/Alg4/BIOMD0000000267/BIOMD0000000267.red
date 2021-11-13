off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 29*x1, 58*x1 - 141*x2, 141*x2 - 13*x3, 13*x3};

classifyComponents {basis};

end;
