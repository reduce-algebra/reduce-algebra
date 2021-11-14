off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x10, x2, x3, x4, x6}, {x10, x2, x3, x4, x6, x8}, {x10, x3, x4, x6, x9, 10000000*x1*x8-x2}, {x10, x6, x7, 10000000*x1*x8-x2, 1000000000*x2*x9-x3, 1000000*x4*x5-x3}, {x1, x10, x2, x3, x5, x6, x7}, {x10, x2, x3, x5, x6, x7, x8}, {x10, x3, x5, x6, x7, x9, 10000000*x1*x8-x2}};

classifyComponents P;

end;
