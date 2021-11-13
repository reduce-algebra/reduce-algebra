off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 10496*x1*x2 - 3293660*x1 + 1721350*x3 + 993805*x4 + 1699528560,  - 10496*x1*x2 + 1721350*x3 + 993805*x4, 2624*x1*x2 - 2301005*x3, 3741335*x3 - 1476048*x4, 317871*x4, 82021*x4};

classifyComponents {basis};

end;
