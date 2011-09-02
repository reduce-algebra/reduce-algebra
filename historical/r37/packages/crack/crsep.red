%*********************************************************************
module separation$
%*********************************************************************
%  Routines for separation of de's
%  Author: Andreas Brand
%  1990 1994

symbolic procedure get_separ_pde(pdes)$
% Find the directly separable PDE with the most variables
begin scalar p,m$
  m:=-1$
  while pdes do <<
    if get(car pdes,'starde) and 
      (zerop cdr get(car pdes,'starde)) and
      ((null p) or 
       (get(car pdes,'nvars)<m)) then <<
      p:=car pdes$
      m:=get(p,'nvars)
    >>$
    pdes:=cdr pdes$
  >>$
  return p
end$

symbolic procedure separate(de)$
%  Separation of the equation de
%  result: a list of equations
%          NIL=no separation
if flagp(de,'to_sep) and get(de,'starde) then 
begin scalar l$
 l:=separ(get(de,'val),get(de,'fcts),get(de,'vars))$
 if length l>1 then 
    <<l:=mkeqlist(for each a in l collect cdr a,get(de,'fcts),
                  get(de,'vars),delete('to_sep,allflags_),t,
                  get(de,'orderings))$
    if print_ then 
       <<terpri()$write "Separation of ",de," yields ",l>>$
    return l>>
 else remflag1(de,'to_sep)$
end$

symbolic procedure termsep(a,x)$
%  splits the product a in two parts: the first contains all
%  factors dependend on x the second all others
%  Result: nil, if no splitting possible
%          ((depending on x)(indep on x))
begin scalar l,p,q,sig,l1,l2$
if atom a then if x=a then l:=list(a,1)         %   Variable
		      else l:=list(1,a)         %   Konstante
else if my_freeof(a,x) then l:=list(1,a)           %   a unabh. von x
else
	<<if car a='MINUS then
		<<a:=cadr a$
		sig:=not sig>>$
	if pairp a and (car a='TIMES) then l:=cdr a  
			  else l:=list a$       %   l Liste der Faktoren
	p:=nil$                                 %   Liste der Faktoren,
						%   die x enthalten
	q:=nil$                                 %   Liste der Faktoren,
						%   die x nicht enth.
	while l do
	     <<if my_freeof(car l,x) then q:=cons(car l,q)
						%   Faktor enth. x nicht
	     else
	       if pairp car l and (caar l='EXPT) and my_freeof(cadar l,x)
		  and (pairp caddar l) and (car caddar l='PLUS) then
		     <<for each s in cdr caddar l do
			if my_freeof(s,x) then l1:=cons(s,l1)
				       else l2:=cons(s,l2)$
			if l1 then
			   <<if cdr l1 then l1:=cons('PLUS,l1)
				       else l1:=car l1$
			   q:=cons(list('EXPT,cadar l,l1),q)>>$
			if l2 and cdr l2 then l2:=cons('PLUS,l2)
					 else l2:=car l2$
			p:=cons(list('EXPT,cadar l,l2),p)>>
	     else p:=cons(car l,p)$
	     l:=cdr l>>$
	if p then
		if length p>1 then p:=cons('TIMES,p)
		 else p:=car p$
	if q then
		if length q>1 then q:=cons('TIMES,q)
		 else q:=car q$
	if p or q then                          %   war Sep. moegl.?
		if null p then if sig then l:=list(1,list('MINUS,q))
				      else l:=list(1,q)
		else
			if q then if sig then l:=list(p,list('MINUS,q))
					 else l:=list(p,q)
			     else if sig then l:=list(p,list('MINUS,1))
					 else l:=list(p,1)>>$
return l
end$

symbolic procedure sumsep(l,x)$
%   Separieren einer Liste von Summanden
%   l Liste von Ausdr. in LISP-Notation, x Var.
%   Ergebnis: nil, falls keine Sep. moegl.,
%   sonst Liste von Listen von Summanden
begin scalar cl,p,q,s$
while l do
    if pairp car l and (caar l='QUOTIENT) then
      <<p:=termsep(cadar l,x)$
	if not q then q:=termsep(caddar l,x)$    % Quotient immer gleich
	if p and q then
	   <<l:=cdr l$
	   if car q=1 then s:=car p
		      else s:=list('QUOTIENT,car p,car q)$
	   if cadr q=1 then p:=list(s,cadr p)
		       else p:=list(s,list('QUOTIENT,cadr p,cadr q))$
	   cl:=termsort(cl,p)>>
	else
	   <<l:=nil$
	   cl:=nil>> >>
    else
      <<p:=termsep(car l,x)$          %   Separieren eines Summanden
	if p then                               %   erfolgreich
		<<l:=cdr l$
		cl:=termsort(cl,p)>>            %   Terme einordnen
	else
		<<l:=nil$                       %   Abbruch
		cl:=nil>> >>$                   %   keine Separ. moegl.
if cl and print_ and (length cl>1) then         %   output for test
   <<terpri()$write "separation w.r.t. "$fctprint list x$
					%   of linear independence
   if pairp caar cl and (caaar cl='QUOTIENT) then
	l:=for each s in cl collect cadar s
   else l:=for each s in cl collect car s$
   if not linearindeptest(l,list x) then cl:=nil>>$

return cl                               %   Liste der Terme, die von x
						%   unabh. sind
end$

symbolic procedure linearindeptest(l,vl)$
begin scalar l1,flag$
l1:=l$flag:=t$
while flag and pairp l1 do
	if freeoflist(car l1,vl) then l1:=cdr l1
	else if member(car l1,vl) then l1:=cdr l1
	else if (pairp car l1) and (caar l1='EXPT) and
		(numberp caddar l1) and member(cadar l1,vl) then l1:=cdr l1
	else flag:=nil$
if not flag then
	<<terpri()$write "linear independent expressions : "$
	for each x in l do eqprint(x)$
	if independence_ then
	   if yesp "Are the expressions linear independent?"
	      then flag:=t
	      else flag:=nil
	else flag:=t>>$
return flag$
end$

symbolic procedure termsort(cl,p)$
%   Zusammenfassen der Terme
%   cl Liste von Paaren,p Paar
%   Sind bei einem Element von cl und bei p die ersten Teile gleich,
%   wird der zweite Teil von p an den des Elements von cl angehaengt
if null cl then list p
else if caar cl=car p then cons(cons(car p,cons(cadr p,cdar cl)),cdr cl)
		      else cons(car cl,termsort(cdr cl,p))$

symbolic procedure eqsep(eql,ftem)$
%   Separieren einer Liste von: Gl. als Liste von Koeffizient + Summ.
%   + Liste der Var. nach denen schon erfolglos sep. wurde
%   + Liste der Var. nach denen noch nicht separiert wurde
begin scalar vlist1,vlist2,a,x,l,eql1$
while eql do
	<<a:=car eql$             %   erste Gl. +Listen
	vlist1:=cadr a$           %   Var. nach d. erfolglos sep. wurde
	vlist2:=caddr a$          %   Var. nach denen nicht sep. wurde
	eql:=cdr eql$
	if vlist2 then            %   noch Var. zu sep.
         <<x:=car vlist2$
         vlist2:=cdr vlist2$
	 if my_freeof(cdar a,x) then
	    eql:=cons(list(car a,vlist1,vlist2),eql)
         else 
         if (my_freeof(cdar a,x) or 
             member(x,argset smemberl(ftem,list cdar a)))
	   then eql:=cons(list(car a,cons(x,vlist1),vlist2),eql)
	   else <<l:=sumsep(cdar a,x)$
			       %   Liste der Gl. die sich durch Sep.
			       %   nach x ergeben
	   if l then
	   eql:=append(varapp(l,caar a,nil,append(vlist1,vlist2)),eql)
			       %   nach erfolgr. Sep. wird nach bisher
			       %   erfolglosen Var. sep.
	   else
	   eql:=cons(list(car a,cons(x,vlist1),vlist2),eql)>> >>
			       %   erfolgloses Sep.,x wird als
			       %   erfolglose Var. registriert
	else eql1:=cons(a,eql1)>>$
return eql1$
end$

symbolic procedure varapp(l,a,v1,v2)$
%   an jede Gl. aus l werden v1 und v2 angehaengt
if null l then nil
else
cons(list(cons(cons(caar l,a),cdar l),v1,v2),varapp(cdr l,a,v1,v2))$

symbolic procedure sep(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eql,eqlist,a,q$
  if pairp p and (car p='QUOTIENT) then
  <<q:=cdr reval list('FACTORIZE,caddr p)$
    if length q>1 then q:=cons('TIMES,q)
		  else q:=car q$
    p:=cadr p
  >>$
  if pairp p and (car p='PLUS) then
  a:=cons(nil,if not q then cdr p
		       else for each b in cdr p
			    collect list('QUOTIENT,b,q))
			       else
  if not q then a:=list(nil,p)
	   else a:=list(nil,List('QUOTIENT,p,q))$
				       %   Gl. als Liste von Summanden
  eql:=list(list(a,nil,varl))$
				       %   Listen der Var. anhaengen
  eql:=eqsep(eql,ftem)$

  while eql do
  <<a:=caar eql$                  %   Listen der Var. streichen
    if cddr a then a:=cons(car a,cons('PLUS,cdr a))
	      else a:=cons(car a,cadr a)$       %   PLUS eintragen
    if car a then
    if cdar a then a:=cons(cons('TIMES, car a),cdr a)
	      else a:=cons(caar a,cdr a)
	     else a:=cons(1,cdr a)$
    eqlist:=cons(a,eqlist)$
    eql:=cdr eql
  >>$

  return eqlist
end$

symbolic procedure separ2(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eqlist$
  if p and not zerop p then
  if not (pairp p and (car p='QUOTIENT) and
	 intersection(argset smemberl(ftem,cadr p),varl)) then
  <<eqlist:=sep(p,ftem,varl)$
    if eqlist then eqlist:=union(cdr eqlist,list car eqlist)$
  >>;   % else eqlist is nil

  return eqlist
end$

symbolic procedure separ(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eql,eqlist,a,b,l,s$
  if p and not zerop p then
  if not (pairp p and (car p='QUOTIENT) and
	intersection(argset smemberl(ftem,cadr p),varl)) then
  <<eqlist:=sep(p,ftem,varl)$
    if eqlist then eql:=union(cdr eqlist,list car eqlist)$
    eqlist:=nil$
    while eql do
    <<a:=car eql$
      l:=eql:=cdr eql$
      for each b in l do
      <<s:=reval list('QUOTIENT,cdr b,cdr a)$
	if not smemberl(append(varl,ftem),s) then
	<<eql:=delete(b,eql)$
	  a:=cons(reval list('PLUS,car a,list('TIMES,s,car b)),cdr a)>>
      >>$
      eqlist:=cons(a,eqlist)
    >>
  >>                                                     else
  eqlist:=list cons(1,p)        % FTEM functions in the DENR of p
		     else eqlist:=list cons(0,0)$
  return eqlist
end$

endmodule$

end$
