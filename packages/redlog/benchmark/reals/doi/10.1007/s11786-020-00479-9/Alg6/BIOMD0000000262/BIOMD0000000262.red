off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x11, x3, x4, x6, x8, x9, 10000000000*x2-681901837333797}};

classifyComponents P;

end;
