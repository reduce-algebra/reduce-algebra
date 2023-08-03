off output, msg;
%on comp;
remprop('pg_gauss, 'opfn)$
lisp infile "pgauss.red"$
lisp infile "pgsm.red"$
lisp infile "pgcond.red"$
on output, msg;
off comp;
end;
