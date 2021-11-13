off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2}, {x1, x4}, {x2, x3}, {x3, x4}};

classifyComponents P;

end;
