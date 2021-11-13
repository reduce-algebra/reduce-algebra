off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2, x3}, {-180+407*x3, 37*x1-12, 37*x2-20}};

classifyComponents P;

end;
