off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x10, x3, x4, x5, x7, -865620*x1+13081*x2}, {x10, x4, x5, x6, x7, -865620*x1+13081*x2}, {x10, x3, x4, x5, x8, x9, -865620*x1+13081*x2}};

classifyComponents P;

end;
