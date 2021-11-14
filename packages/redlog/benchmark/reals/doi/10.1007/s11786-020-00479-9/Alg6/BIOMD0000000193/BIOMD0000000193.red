off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{-50000*x4*x6+x8, -500000000*x5*x6+x7, 100000*x2*x4+1000000000*x3*x4-x5, 20000000*x1*x2+100000*x2*x4-20*x3-x5}};

classifyComponents P;

end;
