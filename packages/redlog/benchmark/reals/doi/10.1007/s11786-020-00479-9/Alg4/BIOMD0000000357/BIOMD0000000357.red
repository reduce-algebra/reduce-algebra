off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 484800000*x1*x3 - 757500000*x1*x4 - 23500000*x1*x8 + 579000000*x2 + 1050425000*x5 + 270500000*x7 + 213000133*x9, 459*x1*x3 - 579*x2,  - 2424*x1*x3 + 835*x2 + 545*x7,  - 30300*x1*x4 + 16480*x2 + 37*x5, 30300*x1*x4 - 42017*x5, 2099*x5 + 426*x9, 258*x1*x3 - 2705*x7,  - 23500000*x1*x8 + 161500000*x7 + 133*x9, 23500000*x1*x8 - 213000133*x9};

classifyComponents {basis};

end;
