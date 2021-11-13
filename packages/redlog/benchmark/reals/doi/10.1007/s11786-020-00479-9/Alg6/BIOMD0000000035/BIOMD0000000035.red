off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{25*x9-x10, x6+5000*x7-2*x10, 50*x8-x3-x2, 250*x4-x3+2500*x5-x2, 2*x10*x2-x3, 50*x2*x6-2*x10+x6, -2*x10^2+x10*x6+25*x3*x6, -2*x10*x3+500*x10*x4+50*x3*x4-x3, 50*x2*x4-x2-x3+250*x4, -4*x10^2+100*x10*x4+2*x10*x6+12450*x4*x6-2*x10+x6}};

classifyComponents P;

end;
