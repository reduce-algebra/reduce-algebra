off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2, x3, x4}, {6003*x2+200500000, x3-4000*x1, 2001*x4-3200000000*x1, 48024*x1^2+150075*x1+6265625}};

classifyComponents P;

end;
