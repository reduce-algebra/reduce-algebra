off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{4*x1-x3, x2-x3, 8*x3^2-3}};

classifyComponents P;

end;
