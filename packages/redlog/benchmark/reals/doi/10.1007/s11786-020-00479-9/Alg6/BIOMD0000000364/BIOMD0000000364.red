off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x1, x10, x12, x13, x2, x4, x6, x7, x9}, {x10, x11, x12, x13, x2, x3, x4, x5, x6, x7, x9}, {x10, x11, x12, x13, x2, x3, x9, 2649987500000000*x1+546221, 403858111747921*x4+101653828950000*x5, 15875000000*x6-13*x4, 262375000000*x7+39*x4}, {x2, x3, x4, x5, x6, x7, x9, 333700000000000000000*x1+51333032053, 1499148366226500000000*x10+21562216463723*x11, 5990000000*x12-723*x10, 14200000000000*x13+241*x10}};

classifyComponents P;

end;
