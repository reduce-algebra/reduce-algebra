off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0,  - 3*x2, 3*x2 - 1160*x3, 58*x3 - 141*x4, 141*x4 - 13*x5, 13*x5};

classifyComponents {basis};

end;
