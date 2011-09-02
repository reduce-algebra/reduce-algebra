module nbasis;

% Author: James H. Davenport.

fluid '(!*tra nestedsqrts sqrt!-intvar taylorasslist);

exports normalbasis;
imports substitutesq,taylorform,printsq,newplace,sqrtsinsq,union,
        sqrtsign,interr,vecsort,mapvec,firstlinearrelation,mksp,multsq,
        !*multsq,addsq,removecmsq,antisubs,involvesq;


symbolic procedure normalbasis(zbasis,x,infdegree);
begin
  scalar n,nestedsqrts,sqrts,u,v,w,li,m,lam,i,inf,basis,save;
  save:=taylorasslist;
  inf:=list list(x,'quotient,1,x);
  n:=upbv zbasis;
  basis:=mkvect n;
  lam:=mkvect n;
  m:=mkvect n;
  goto  a;
square:
  sqrts:=nil;
  inf:=append(inf,list list(x,'expt,x,2));
  % we were in danger of getting sqrt(x) where we didnt want it.
a:
  newplace(inf);
  for i:=0:n do <<
    v:=substitutesq(getv(zbasis,i),inf);
    putv(basis,i,v);
    sqrts:=union(sqrts,sqrtsinsq(v,x)) >>;
  if !*tra then <<
    princ "Normal integral basis reduction with the";
    prin2t " following sqrts lying over infinity:";
    superprint sqrts >>;
  if member(list('sqrt,x),sqrts)
    then goto square;
  sqrts:=sqrtsign(sqrts,x);
  if iadd1 n neq length sqrts
    then interr "Length mismatch in normalbasis";
  for i:=0:n do <<
    v:=cl8roweval(getv(basis,i),sqrts);
    putv(m,i,cdr v);
    putv(lam,i,car v) >>;
reductionloop:
  vecsort(lam,list(basis,m));
  if !*tra then <<
    prin2t "Matrix before a reduction step at infinity is:";
    mapvec(m,function prin2t) >>;
  v:=firstlinearrelation(m,iadd1 n);
  if null v
    then goto ret;
  i:=n;
  while null numr getv(v,i) do
    i:=isub1 i;
  li:=getv(lam,i);
  w:=nil ./ 1;
  for j:=0:i do
    w:=!*addsq(w,!*multsq(getv(basis,j),
                 multsq(getv(v,j),1 ./  !*fmksp(x,-li+getv(lam,j)) )));
           % note the change of sign. my x is coates 1/x at this point!.
  if !*tra then <<
    princ "Element ";
    princ i;
    prin2t " replaced by the function printed below:" >>;
  w:=removecmsq w;
  putv(basis,i,w);
  w:=cl8roweval(w,sqrts);
  if car w <= li
    then interr "Normal basis reduction did not work";
  putv(lam,i,car w);
  putv(m,i,cdr w);
  goto reductionloop;
ret:
  newplace list (x.x);
  u:= 1 ./ !*p2f mksp(x,1);
  inf:=antisubs(inf,x);
  u:=substitutesq(u,inf);
  m:=nil;
  for i:=0:n do begin
    v:=getv(lam,i)-infdegree;
    if v < 0
      then goto next;
    w:=substitutesq(getv(basis,i),inf);
    for j:=0:v do <<
      if not involvesq(w,sqrt!-intvar)
        then m:=w.m;
      w:=!*multsq(w,u) >>;
  next:
    end;
  tayshorten save;
  return m
  end;


symbolic procedure !*fmksp(x,i);
% sf for x**i.
if i iequal 0
  then 1
  else !*p2f mksp(x,i);


symbolic procedure cl8roweval(basiselement,sqrts);
begin
  scalar lam,row,i,v,minimum,n;
  n:=isub1 length sqrts;
  lam:=mkvect n;
  row:=mkvect n;
  i:=0;
  minimum:=1000000;
  while sqrts do <<
    v:=taylorform substitutesq(basiselement,car sqrts);
    v:=assoc(taylorfirst v,taylorlist v);
    putv(row,i,cdr v);
    v:=car v;
    putv(lam,i,v);
    if v < minimum
      then minimum:=v;
    i:=iadd1 i;
    sqrts:=cdr sqrts >>;
  if !*tra then <<
    princ "Evaluating ";
    printsq basiselement;
    prin2t lam;
    prin2t row >>;
  v:=1000000;
  for i:=0:n do <<
    v:=getv(lam,i);
    if v > minimum
      then putv(row,i,nil ./ 1) >>;
  return minimum.row
  end;

endmodule;

end;
