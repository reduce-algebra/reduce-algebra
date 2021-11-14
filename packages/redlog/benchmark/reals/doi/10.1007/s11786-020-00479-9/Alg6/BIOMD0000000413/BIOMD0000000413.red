off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{79*x1-3050, 25071*x2-263860*x3, 4375*x4+79*x5-12150, 1006250*x3*x5+73707*x5-11335950}};

classifyComponents P;

end;
