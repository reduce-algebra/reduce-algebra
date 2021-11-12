off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 55*x1*x2 + 83*x2*x3,  - 55*x1*x2 - 83*x2*x3, 55*x1*x2 - 83*x2*x3, 83*x2*x3, 0, 0};

classifyComponents {basis};

end;
