off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{19*x1-851*x3, 19*x5-9589*x3, 13616*x2*x3+188575*x2-13616000*x3, 3987513*x2*x4+369607000*x2-4357120000*x4, 49*x3*x4-49000*x3+8000*x4}};

classifyComponents P;

end;
