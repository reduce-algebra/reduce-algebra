off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{580*x11-21*x4, 142*x8-63*x4, 26680000*x10*x6-914781*x4, 12500*x3*x9-679*x4, 227200*x5*x7-9891*x4, 5300*x1*x2-72*x3-315*x4}};

classifyComponents P;

end;
