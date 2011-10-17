symbolic;

in "../src/patches.red"$

date!* := compress('!" . append(explode2 "15-Jul-95, patched to ",
                                nconc(explode2 patch!-date!*,list '!")));

<< initreduce();
   preserve('begin, bldmsg("%w, %w ...", version!*, date!*)) >>;



