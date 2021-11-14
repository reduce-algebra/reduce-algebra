off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x2-2*x1, x3-x1, -x1+2*x4+x5}};

classifyComponents P;

end;
