off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x3, x4, x9, -27*x5*x6+10*x7}, {x1, x3, x4, x5, x7, x9}, {x1, x3, x4, x6, x7, x9}, {x2, x3, x4, x5, x7, x9}, {x2, x3, x6, x7, x9, x1*x5-154*x4}};

classifyComponents P;

end;
