off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x4}, {200*x1+27*x4, 180000*x2+1}};

classifyComponents P;

end;
