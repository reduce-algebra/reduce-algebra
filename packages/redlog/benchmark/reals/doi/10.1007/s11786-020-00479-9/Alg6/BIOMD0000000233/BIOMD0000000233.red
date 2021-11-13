off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x3, x4}, {-9+2*x4, x3-6}, {-1+2*x4, x3-2}};

classifyComponents P;

end;
