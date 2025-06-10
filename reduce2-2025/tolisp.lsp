lisp;
on comp, backtrace;
symbolic procedure escaped l;
  if null l then nil
  else '!! . car l . escaped cdr l;

%symbolic procedure string2id u;
%  if stringp u then mkquote compress escaped explodec u
%  else if atom u then u
%  else string2id car u . string2id cdr u;

remflag(oblist(), 'eval)$
remflag(oblist(), 'lose)$
for each x in oblist() do remprop(x, 'number!-of!-arguments)$
for each x in oblist() do remprop(x, 'inline)$
%for each x in oblist() do if eqcar(getd x, 'macro) then <<
%  print x;
%  if length explodec x > 1 then remob x >>$
remob 'mkarray;

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

symbolic procedure funnyprint u;
  begin
    if eqcar(u, 'put) and caddr u = ''number!-of!-args then return;
    if eqcar(u, 'put) and caddr u = ''defined!-on!-line then return;
    if eqcar(u, 'put) and caddr u = ''defined!-in!-file then return;
    if eqcar(u, 'put) and caddr u = ''procedure_type then return;
    if eqcar(u, 'progn) then <<
       for each v in cdr u do funnyprint v;
       return nil >>;
%   tprettyprint string2id u;
    tprettyprint u;
    terpri();
  end;

dfprint!* := 'funnyprint;

smacro procedure RED U; cdr U;
smacro procedure DIV(U,V); U . V;

INFIX MULT,ADD,DIV;

off echo;
out "reduce.lsp"$
terpri()$
on defn$
in "reduce.red.patched"$
out nil;

end;

