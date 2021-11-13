off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x2, x3, x6, x7, x10-80*x9, x5-100*x4, x8-10*x9}};

classifyComponents P;

end;
