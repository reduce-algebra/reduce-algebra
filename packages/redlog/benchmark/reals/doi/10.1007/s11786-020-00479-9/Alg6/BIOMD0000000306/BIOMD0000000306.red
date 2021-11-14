off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2}, {4*x1+3, x2+1}};

classifyComponents P;

end;
