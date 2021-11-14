off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2, x5, x7, x9}, {x2, x3, x4, x5, x7, x8, x9}};

classifyComponents P;

end;
