off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x4, x6, x7, x2-10000}, {x1, x5, x6, x7, x2-10000}};

classifyComponents P;

end;
