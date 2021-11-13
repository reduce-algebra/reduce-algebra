off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{6*x1*x3-x2, 7*x2*x4-100*x5}};

classifyComponents P;

end;
