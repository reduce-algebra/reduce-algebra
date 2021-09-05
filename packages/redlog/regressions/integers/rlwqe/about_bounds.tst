% An artificial example with some non-trivial bounds. Specifically, one can
% see bound-variables _kj occurring in the bound of some other _ki.
% Furthermore, some bounds are printed with abs.
off rlabout;

rlset z;

f := ex({m, n}, a+2*b = (a+b)*m and a*(m+n) < 0);

rlwqe f;

end;
