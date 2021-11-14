off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

P := {{93*x1-28*x7, 9*x5-14*x7, 30841993*x7^4-213840000, -2639*x7^2+9000*x2, -2639*x7^2+5400*x3, -2372461*x7^3+10692000*x4, -2639*x7^3+4050*x6}};

classifyComponents P;

end;
