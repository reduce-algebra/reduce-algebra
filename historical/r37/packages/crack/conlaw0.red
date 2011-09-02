
%==== Procedures as in LIEPDE:

symbolic procedure comparedif1(u1l,u2l)$
% checks whether u2l has more or at least equally many 1's, 2's, ...
% contained as u1l.
% returns a list of 1's, 2's, ... which are in excess in u2l
% compared with u1l. The returned value is 0 if both are identical
begin
 scalar ul;
 if u2l=nil then if u1l neq nil then return nil 
				else return 0
	    else if u1l=nil then return u2l
			    else % both are non-nil
 if car u1l < car u2l then return nil else 
 if car u1l = car u2l then return comparedif1(cdr u1l,cdr u2l) else <<
  ul:=comparedif1(u1l,cdr u2l);
  return if not   ul then nil          else 
	 if zerop ul then list car u2l else
			  cons(car u2l,ul)
 >>
end$ % of comparedif1

%-------------

symbolic procedure comparedif2(u1,u1list,du2)$
% checks whether du2 is a derivative of u1 differentiated
% wrt. u1list
begin
 scalar u2l;
 u2l:=combidif(du2)$ % u2l=(u2, 1, 1, ..)
 if car u2l neq u1 then return nil else
 return comparedif1(u1list, cdr u2l)
end$ % of comparedif2

%-------------

symbolic procedure listdifdif1(du1,deplist)$
% lists all elements of deplist which are *not* derivatives
% of du1
begin
 scalar u1,u1list,res,h$
 h:=combidif(du1);
 u1:=car h;
 u1list:=cdr h;
 for each h in deplist do
 if not comparedif2(u1,u1list,h) then res:=cons(h,res);
 return res
end$ % of listdifdif1

%-------------

symbolic operator listdifdif2$
symbolic procedure listdifdif2(lhslist,deplist)$
% lists all elements of deplist which are *not* derivatives
% of any element of lhslist
begin
  scalar h;
  deplist:=cdr reval deplist;
  lhslist:=cdr reval lhslist;
  for each h in lhslist do
  deplist:=listdifdif1(h,deplist);
  return cons('LIST,deplist)
end$ % of listdifdif2

%-------------

symbolic operator totdeg$
symbolic procedure totdeg(p,f)$
%   Ordnung (total) der hoechsten Ableitung von f im Ausdruck p
eval(cons('PLUS,ldiff1(car ldifftot(reval p,reval f),fctargs reval f)))$

%-------------

symbolic procedure diffdeg(p,v)$
%   liefert Ordnung der Ableitung von p nach v$
%   p Liste Varible+Ordnung der Ableitung, v Variable (Atom)
if null p then 0                        %  alle Variable bearbeitet ?
else if car p=v then                    %  v naechste Variable ?
     if cdr p then
	if numberp(cadr p) then cadr p  %  folgt eine Zahl ?
				else 1
	else 1
     else diffdeg(cdr p,v)$             %  weitersuchen

%-------------

symbolic procedure ldiff1(l,v)$
%  liefert Liste der Ordnungen der Ableitungen nach den Variablen aus v
%  l Liste (Variable + Ordnung)$ v Liste der Variablen
if null v then nil                      %  alle Variable abgearbeitet ?
else cons(diffdeg(l,car v),ldiff1(l,cdr v))$
					%  Ordnung der Ableitung nach
					%  erster Variable anhaengen

%-------------

symbolic procedure ldifftot(p,f)$
%  leading derivative total degree ordering
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ldifftot1(p,f,fctargs f)$

%-------------

symbolic procedure ldifftot1(p,f,vl)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion, lv Variablenliste
begin scalar a$
a:=cons(nil,0)$
if not atom p then
if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,
	  'QUOTIENT,'DF,'EQUAL)) then
					%  erlaubte Funktionen
	<<if (car p='PLUS) or (car p='TIMES) or (car p='QUOTIENT)
	     or (car p='EQUAL) then
		<<p:=cdr p$
		while p do
			<<a:=diffreltot(ldifftot1(car p,f,vl),a,vl)$
			p:=cdr p>> >>
	else if car p='MINUS then
		a:=ldifftot1(cadr p,f,vl)
	else if car p='EXPT then        %  Exponent
			if numberp caddr p then
			<<a:=ldifftot1(cadr p,f,vl)$
			a:=cons(car a,times(caddr p,cdr a))>>
			else a:=cons(nil,0)
					%  Poetenz aus Basis wird mit
					%  Potenz multipliziert
	else if car p='DF then          %  Ableitung
		if cadr p=f then a:=cons(cddr p,1)
					%  f wird differenziert?
		else a:=cons(nil,0)>>   %  sonst Konstante bzgl. f
else if p=f then a:=cons(nil,1)
					%  Funktion selbst
	else a:=cons(nil,0)             %  alle uebrigen Fkt. werden
else if p=f then a:=cons(nil,1)$        %  wie Konstante behandelt
return a
end$

%-------------

symbolic procedure diffreltot(p,q,v)$
%   liefert komplizierteren Differentialausdruck$
if diffreltotp(p,q,v) then q
		   else p$

%-------------

symbolic procedure diffreltotp(p,q,v)$
%   liefert t, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
begin scalar n,m$
m:=eval(cons('PLUS,ldiff1(car p,v)))$
n:=eval(cons('PLUS,ldiff1(car q,v)))$
return
 if m<n then t
 else if n<m then nil
      else diffrelp(p,q,v)$
end$

%-------------

algebraic procedure subdif1(xlist,ylist,ordr)$
% A list of lists of derivatives of one order for all functions
begin
 scalar allsub,revx,i,el,oldsub,newsub;
 revx:=reverse xlist;
 allsub:={};
 oldsub:= for each y in ylist collect y=y;
 for i:=1:ordr do      %  i is the order of next substitutions
 <<oldsub:=for each el in oldsub join nextdy(revx,xlist,el);
   allsub:=cons(oldsub,allsub)
 >>;
 return allsub
end$

%-------------

algebraic procedure nextdy(revx,xlist,dy)$
% generates all first order derivatives of lhs dy
% revx = reverse xlist; xlist is the list of variables;
%                       dy the old derivative
begin
  scalar x,n,ldy,rdy,ldyx,sublist;
  x:=first revx; revx:=rest revx;
  sublist:={};
  ldy:=lhs dy;
  rdy:=rhs dy;
 
  while lisp(not member(prepsq simp!* algebraic x,
	     prepsq simp!* algebraic ldy))
	and (revx neq {}) do 
  <<x:=first revx; revx:=rest revx>>;
 
  n:=length xlist;
  if revx neq {} then                % dy is not the function itself
  while first xlist neq x do xlist:=rest xlist;
  xlist:=reverse xlist;

  % New higher derivatives
  while xlist neq {} do
  <<x:=first xlist;
    ldyx:=df(ldy,x);
    sublist:=cons((lisp reval algebraic ldyx)=
                  mkid(mkid(rdy,!`),n), sublist);
    n:=n-1;
    xlist:=rest xlist
  >>;
  return sublist
end$

%-------------

symbolic procedure combidif(s)$
% extracts the list of derivatives from s: % u`1`1`2 --> (u, 1, 1, 2)
begin scalar temp,ans,no,n1;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;
  
  while not null temp do
  <<n1:=<<no:=nil;
	  while (not null temp) and (not eqcar(temp,'!`)) do
	  <<no:=car temp . no;temp:=cdr temp>>; 
	  compress no
	>>;
    if (not fixp n1) then n1:=intern n1;
    ans:=n1 . ans;
    if eqcar(temp,'!`) then <<temp:=cdr temp; temp:=cdr temp>>;
  >>;
  return ans
end$

%-------------

symbolic operator dif$
symbolic procedure dif(s,n)$
% e.g.:   dif(fnc!`1!`3!`3!`4, 3) --> fnc!`1!`3!`3!`3!`4
begin scalar temp,ans,no,n1,n2,done;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;
  n2:=reval n;
  n2:=explode n2;

  while (not null temp) and (not done) do
  <<n1:=<<no:=nil;
	  while (not null temp) and (not eqcar(temp,'!`)) do
	  <<no:=car temp . no;temp:=cdr temp>>; 
	  compress no
	>>;
    if (not fixp n1) or ((fixp n1) and (n1 leq n)) then
    <<ans:=nconc(n2,ans); ans:='!` . ans; ans:='!! . ans; done:=t>>;
    ans:=nconc(no,ans);
    if eqcar(temp,'!`) then <<ans:='!` . ans; ans:='!! . ans; 
			      temp:=cdr temp; temp:=cdr temp>>; 
  >>;
  return intern compress nconc(reverse temp,ans);
end$

%-------------

algebraic procedure maklist(ex)$
% making a list out of an expression if not already
if lisp(atom algebraic ex) then {ex} else
if lisp(car algebraic ex neq 'LIST) then ex:={ex}
                                    else ex$

%-------------

algebraic procedure depnd(y,xlist)$
for each xx in xlist do
for each x  in xx    do depend y,x$

%==== Other procedures:

symbolic operator totdif$
symbolic procedure totdif(s,x,n,dylist)$
% total derivative of s(x,dylist) w.r.t. x which is the n'th variable
begin
  scalar tdf,el1,el2;
  tdf:=simpdf {s,x};
  <<dylist:=cdr dylist;
    while dylist do
    <<el1:=cdar dylist;dylist:=cdr dylist;
      while el1 do
      <<el2:=car el1;el1:=cdr el1;
	tdf:=addsq(tdf ,multsq( simp!* dif(el2,n), simpdf {s,el2}))
      >>
    >>
  >>;
  return prepsq tdf
end$

%-------------

algebraic procedure simppl(pllist,ulist,tt,xx)$
begin
 scalar pl,hh,td,xd,lulist,ltt,lxx,ltd,dv,newtd,e1,deno,ok,
        newpllist,contrace; 
%contrace:=t;
 lisp <<
  lulist:=cdr reval algebraic ulist;
  lxx:=reval algebraic xx;
  ltt:=reval algebraic tt;
 >>;
 newpllist:={};
 for each pl in pllist do <<
  td:=first  pl;
  xd:=second pl;
  repeat <<
   lisp <<
    ltd:=reval algebraic td;
    if contrace then <<write"ltd1=",ltd;terpri()>>$
    dv:=nil;
    newtd:=nil;
    deno:=nil;
    if (pairp ltd) and (car ltd='QUOTIENT)   and
      my_freeof(caddr ltd,ltt) and
      my_freeof(caddr ltd,lxx) 
    then <<deno:=caddr ltd;ltd:=cadr ltd>>;
    ok:=t;

    if (pairp ltd) and (car ltd = 'PLUS) then ltd:= cdr ltd else
    if (pairp ltd) and (car ltd neq 'TIMES) then ok:=nil
                                            else ltd:=list ltd;   
    if contrace then <<write"ltd2=",ltd;terpri()>>$
    if ok then <<
     for each e1 in ltd do <<
      hh:=intpde(e1, lulist, list(lxx,ltt), lxx, t);
      dv   :=cons(car hh,dv);
      newtd:=cons(cadr hh,newtd);
     >>;
     dv   :=reval cons('PLUS,dv);
     newtd:=reval cons('PLUS,newtd);
     if deno then <<newtd:=list('QUOTIENT,newtd,deno);
                    dv   :=list('QUOTIENT,dv   ,deno) >>;
     if contrace then <<write"newtd=",newtd;terpri();
                        write"dv=",dv      ;terpri() >>$

     td:=newtd;
     if contrace then <<write"td=",td;terpri()>>$
     if (dv neq 0) and (dv neq nil) then <<
      xd:=reval(list('PLUS,xd,list('DF,dv,tt)));
      if contrace then <<write"xd=",xd;terpri()>>$
      %algebraic mode:
      %hh:=lisp gensym()$
      %sbb:=absorbconst({td*hh,xd*hh},{hh})$
      %if (sbb neq nil) and (sbb neq 0) then
      %<<td:=sub(sbb,td*hh)/hh;  xd:=sub(sbb,xd*hh)/hh>>;
      % cllist would have to be scaled as well
     >>
    >>
   >>
  >>
  until lisp(dv)=0;
  newpllist:=cons({td,xd}, newpllist);
 >>;
 return reverse newpllist
end$ % simppl

%-------------

symbolic operator fdepterms$
symbolic procedure fdepterms(td,f)$
% fdepterms regards td as a fraction where f occurs only in the
% numerator. It determines all terms of the numerator in
% which f occurs divided through the denominator.
begin
  scalar nu,de,e1,sm;
  td:=reval td;
  if pairp td then
  if car td='QUOTIENT then <<nu:=cadr td;de:=caddr td>>;
  if null nu then nu:=td;
  if not pairp nu then if freeof(nu,f) then sm:=0
				       else sm:=nu
		  else <<
    if car nu = 'PLUS then nu:=cdr nu
		      else nu:=list nu;
    for each e1 in nu do
    if not freeof(e1,f) then sm:=cons(e1,sm);
    if null sm then sm:=0 else
    if length sm = 1 then sm:=car sm
		     else sm:=cons('PLUS,sm)
  >>;
  if de then sm:=list('QUOTIENT,sm,de);
  return sm
end$ % of fdepterms             

%-------------

end$





