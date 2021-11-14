off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{100*x3-x1, 100*x4-x2, -x1*x2^2+x1*x2+2000000*x5, -x1^2*x2+x1*x2+2000000*x6}};

classifyComponents P;

end;
