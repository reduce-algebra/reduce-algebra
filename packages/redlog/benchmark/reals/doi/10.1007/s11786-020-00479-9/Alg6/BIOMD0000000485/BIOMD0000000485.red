off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{12*x1^3-1536*x1^2+38399*x1-156250}};

classifyComponents P;

end;
