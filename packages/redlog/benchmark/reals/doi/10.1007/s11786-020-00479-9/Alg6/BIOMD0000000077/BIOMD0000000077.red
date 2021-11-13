off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x7-2000000*x5, 500*x2^2-x4, x1*x3-2*x2, 20*x4*x6-x5}};

classifyComponents P;

end;
