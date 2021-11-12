off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := {0,  - 1648219678970*x2 + 317772000000*x3*x4 + 13461500*x3 + 108559*x4 + 1000000000000000000, 903538*x2 - 3177720000*x3*x4 - 134615*x3, 9325170*x2 - 108559*x4};

classifyComponents {basis};

end;
