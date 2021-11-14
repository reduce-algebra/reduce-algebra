off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{17*x1-1100*x3, 3*x2-275*x3, 84700000*x3^2-907500*x3+1343}};

classifyComponents P;

end;
