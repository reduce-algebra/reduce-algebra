off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{11603945*x1-17485402*x2, 48736569*x3-26727514*x2, 1928060*x4-6017*x2, 1158777*x5-6231137000*x2, 24334317*x6-273505045000*x2}};

classifyComponents P;

end;
