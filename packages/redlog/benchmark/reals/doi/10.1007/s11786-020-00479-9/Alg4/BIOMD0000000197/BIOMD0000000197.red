off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {16*x1*x2 - 17025*x1 + 9925*x2 + 20675*x3 + 50*x5,  - 16*x1*x2 + 16000*x1 - 9925*x2, 19*x1 + 49*x3*x4 - 49851*x3 + 8000*x4,  - 49*x3*x4 + 49000*x3 - 8000*x4, 3*x1 + 875*x3 - 2*x5, 0, 0};

classifyComponents {basis};

end;
