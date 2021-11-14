off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{x17, x24, x25, x1-x4, x10-50*x11, x12-x11, 100*x13-x3, -x15+2*x29, x16-x15, x18-1, -x21+100*x32, x22-x21, x5-x4, x8-1, x9-50*x11, -5*x11+x30+10*x31, 2*x28+10*x26+100*x27-x4, x14^2-x7, x14*x2-x6, 5*x2*x3-11*x4, -x14*x6+x2*x7, -11*x14*x4+5*x3*x6}, {x17, x19, x20, x24, x1-x4, x10-50*x11, x12-x11, 100*x13-x3, -x15+2*x29, x16-x15, x18-1, -x21+100*x32, x22-x21, x5-x4, x8-1, x9-50*x11, -5*x11+x30+10*x31, 2*x28+10*x26+100*x27-x4, x14^2-x7, x14*x2-x6, 5*x2*x3-11*x4, -x14*x6+x2*x7, -11*x14*x4+5*x3*x6}, {x1-x4, x10-50*x11, x12-x11, 100*x13-x3, -x15+2*x29, x16-x15, x17-x24, x18-1, -x21+100*x32, x22-x21, x5-x4, x8-1, x9-50*x11, -5*x11+x30+10*x31, 2*x28+10*x26+100*x27-x4, x14^2-x7, x14*x2-x6, 5*x2*x3-11*x4, -x14*x6+x2*x7, -11*x14*x4+5*x3*x6, -x19*x21+x20*x23, x19*x25-x23*x24, x20*x25-x21*x24}};

classifyComponents P;

end;
