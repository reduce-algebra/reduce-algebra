off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0, x10 - 1000*x2*x9, 0, 0, 0, 0, 0, 0, x10 - 1000*x2*x9,  - x10 + 1000*x2*x9, 0, 0, 0, 0, 0, 0, 0,  - 5*x18 + 1007,  - 7*x19 + 2400,  - 83*x20 + 50000,  - 7*x21 + 100,  - 2*x22 + 1285,  - 2*x23 + 625, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

classifyComponents {basis};

end;
