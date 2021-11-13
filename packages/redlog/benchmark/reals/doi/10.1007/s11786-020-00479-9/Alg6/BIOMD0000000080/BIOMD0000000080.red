off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2, x3, x5, x7, x9}, {x10, x2, x3, x5, x7, x9}, {x3, x4, x5, x7, x9, 500000*x1*x10-x2}, {x7, x8, x9, 500000*x1*x10-x2, 1000000000*x2*x4-x3, 20000*x5*x6-x3}, {x1, x2, x3, x6, x7, x8, x9}, {x10, x2, x3, x6, x7, x8, x9}, {x3, x4, x6, x7, x8, x9, 500000*x1*x10-x2}};

classifyComponents P;

end;
