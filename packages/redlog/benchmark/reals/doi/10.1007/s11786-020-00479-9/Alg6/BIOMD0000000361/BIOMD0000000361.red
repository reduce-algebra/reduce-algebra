off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x3, x4, x8, 27*x5*x6-10*x7}, {x2, x3, x1*x5-154*x4, 20*x1*x7-3*x8, 2772*x4*x6-x8, 27*x5*x6-10*x7, 3080*x4*x7-3*x5*x8}};

classifyComponents P;

end;
