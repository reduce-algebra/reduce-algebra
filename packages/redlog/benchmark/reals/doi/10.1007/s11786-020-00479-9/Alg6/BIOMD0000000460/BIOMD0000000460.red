off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{520000*x3-17*x2, 3*x4-50000000*x2, 7000000000000*x2^2+29*x2-50000000000000}};

classifyComponents P;

end;
