#! /bin/bash -v

redcsl -w -l tolisp.log <<XX

lisp;
remflag(oblist(), 'eval)$
remflag(oblist(), 'lose)$
for each x in oblist() do remprop(x, 'number!-of!-arguments)$
for each x in oblist() do if eqcar(getd x, 'macro) then <<
  print x;
  remob x >>$

deflist ('(
        (ADD CONS)
        (LC CDAR)
        (LDEG CDAAR)
        (LT CAR)
        (MULT CONS)
        (MVAR CAAAR)
        (LPOW CAAR)
        (NUMR CAR)
        (DENR CDR)
        (TC CDR)
   ), 'NEWNAM);

smacro procedure RED U; cdr U;
smacro procedure DIV(U,V); U . V;

INFIX MULT,ADD,DIV;

off echo;
out "reduce.lsp.tmp";
on defn;
in "reduce.red.patched"$
out nil;

end;

XX

ls -l reduce.lsp.tmp

# BEWARE:
# There are a bunch of places where the procedure_type information
# end up splut across several lines, as in
#   (put
#       'x
#       'procedure_type
#       (something long enough that all would not fit on one line))
# and the automated tidying up here only gets rid on the single line
# with "procedure_type" visible. So reduce.lsp needs manual cleanup
# afterwards to get rid of the remaining rubbish!

cat reduce.lsp.tmp                  | \
    grep -v 'defined!-in!-file'     | \
    grep -v 'defined!-on!-line'     | \
    grep -v 'number!-of'            | \
    grep -v 'procedure_type'        | \
    sed 's/^(/\n&/g'                | \
    tail -n+3                       > reduce.lsp.initial

