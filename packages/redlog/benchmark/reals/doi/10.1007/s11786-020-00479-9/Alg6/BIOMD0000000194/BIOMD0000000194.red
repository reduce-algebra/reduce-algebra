off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{100000000000*x3*x4-x5, 20000000*x1*x2-20*x3-x5}};

classifyComponents P;

end;
