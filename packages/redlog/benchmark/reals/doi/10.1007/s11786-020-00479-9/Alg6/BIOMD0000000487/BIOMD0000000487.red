off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x6-x3, 10*x1*x2-11*x3, 10*x4*x5-11*x3}};

classifyComponents P;

end;
