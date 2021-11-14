off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{23673*x1-69185*x7, 315*x2-19*x7, 65*x3-19*x7, 13*x4-38*x7, 315*x5-19*x7, 65*x6-19*x7, 1821*x8-26000*x7}};

classifyComponents P;

end;
