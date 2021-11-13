off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 355303285*x1 + 524562060*x2 + 19741911*x3, 352295770200*x1 - 18640752830073*x2 + 708772208540*x4 + 3367405962*x5, 11105*x1 - 30513*x3, 6017*x2 - 1928060*x4, 6231137000*x2 - 15528647*x5 + 6875022*x6, 11105*x5 - 5313*x6};

classifyComponents {basis};

end;
