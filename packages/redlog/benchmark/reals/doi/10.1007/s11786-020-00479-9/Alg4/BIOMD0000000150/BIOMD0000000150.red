off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 25813*x1 + 19000000000*x2*x3 + 557*x4, 25*x1 - 19000000*x2*x3, 25*x1 - 19000000*x2*x3, 813*x1 - 557*x4};

classifyComponents {basis};

end;
