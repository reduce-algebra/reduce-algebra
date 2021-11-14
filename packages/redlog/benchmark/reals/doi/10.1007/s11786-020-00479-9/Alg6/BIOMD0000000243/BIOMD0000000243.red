off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x10, x11, x13, x14, x15, x17, x18, x6, x8, x9}, {x1, x10, x13, x14, x15, x17, x18, x19, x6, x8, x9}, {x10, x11, x13, x14, x15, x16, x17, x18, x6, x8, x9}, {x10, x13, x14, x15, x16, x17, x18, x19, x6, x8, x9}, {x1, x10, x11, x13, x14, x15, x2, x3, x4, x5, x6, x9}, {x1, x10, x13, x14, x15, x19, x2, x3, x4, x5, x6, x9}, {x10, x11, x13, x14, x15, x16, x2, x3, x4, x5, x6, x9}, {x10, x13, x14, x15, x16, x19, x2, x3, x4, x5, x6, x9}};

classifyComponents P;

end;
