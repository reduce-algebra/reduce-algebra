
Comment expandlogs not always working with precise on:
        According to the manual log(3*y) should be simplified to log(3)+log(y) ;

log(x^2-1);

log(3*y);

log(2^x);

on expandlogs;

log(x^2-1);

log(3*y);

log(2^x);

off precise;

log(x^2-1);

log(3*y);

log(2^x);

on factor;

log(x^2-1);

log(3*y);

log(2^x);

on precise;

log(x^2-1);

log(3*y);

log(2^x);

realvalued x;

log(x^2-1);

notrealvalued x;

log(x^2-1);

log(3*x+3);

end;
