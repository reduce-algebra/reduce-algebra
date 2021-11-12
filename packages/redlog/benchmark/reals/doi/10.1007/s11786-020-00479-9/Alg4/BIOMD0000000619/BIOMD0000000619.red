off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 9075250000*x1 + 26775000000*x4, 489311500000*x1 - 664198500000*x2 + 14787832500*x3,  - 3*x3,  - 5075000000*x4 + 756250000*x5,  - 36159337500000*x5 + 1631866250000*x6 + 25347446556250*x7 + 126532563958125*x9, 37613680000000*x1 - 1434916875000*x6, 63843250000*x1 + 332099250000*x2 - 426323821875*x7, 59375*x7, 89300000*x1 - 625871575*x9, 1573*x9};

classifyComponents {basis};

end;
