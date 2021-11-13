off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0, 0,  - 2*x3**2 - 2*x3*x4 - 3*x3 + 32*x4, x3**2 - 8*x4};

classifyComponents {basis};

end;
