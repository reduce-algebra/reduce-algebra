off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 625*x3 + 307, 0,  - 625*x3 - 123*x4 + 600, 625*x3 - 123*x4, 0, 0};

classifyComponents {basis};

end;
