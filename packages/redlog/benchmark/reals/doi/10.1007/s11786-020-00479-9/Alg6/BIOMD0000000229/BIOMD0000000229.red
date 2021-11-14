off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x2, x3, x4, x7, 13*x5*x6-10}, {-184+189*x4, -567*x1+1472*x6, -27*x1+80*x5, 63*x2-46*x1, 567*x3-920, 7*x7-x1, 199017*x1^2-1177600}};

classifyComponents P;

end;
