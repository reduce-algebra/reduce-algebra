off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x3, x4}, {x3-480*x4, -3+250000*x4+10000000*x1, 1000000000000000000*x4^2+50250000*x4-603}};

classifyComponents P;

end;
