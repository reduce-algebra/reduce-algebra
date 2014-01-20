%*********************************************************************
module separation$
%*********************************************************************
%  Routines for separation of de's
%  Author: Andreas Brand, updates and extensions by Thomas Wolf
%

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

symbolic procedure get_separ_pde(pdes)$
% Find the directly separable PDE with the most variables
begin scalar p,m$
  m:=-1$
  while pdes do <<
    if (flagp(car pdes,'to_sep                    ) or 
        (force_sep and flagp(car pdes,'to_casesep))    ) and 
      get(car pdes,'starde)                              and 
      (zerop cdr get(car pdes,'starde))                  and
      ((null p                ) or 
       (get(car pdes,'nvars)<m)    ) then <<
      p:=car pdes$
      m:=get(p,'nvars)
    >>$
    pdes:=cdr pdes$
  >>$
  return p
end$

%###### Which procedures from this file get called from outside
% so that the caller should be capable to handle a return of 1 ?
% --> separ() in crgensep, crsimp
% --> separate() in crmain and crgensep
symbolic procedure separate(de,pdes)$
%  Separation of the equation de
%  result: a list of equations
%          NIL=no separation
% If force_sep then case-distinctions are generated and then pdes are
% needed deep inside as pdes is not (yet) a global variable.
if (flagp(de,'to_sep) or 
    (force_sep and flagp(de,'to_casesep))) and get(de,'starde) then 
begin scalar l$

 if (l:=splitSQ de) then return <<
   l:=mkeqSQlist(for each a in l collect (a . 1),nil,nil,get(de,'fcts),
                 get(de,'vars),delete('to_sep,allflags_),t,
                 get(de,'orderings),pdes)$
   if print_ then <<
     terpri()$write "Separation of ",de," yields ",l$
     terpri()
   >>$
   l
 >>$

 cp_sq2p_val(de)$
 l:=separ(get(de,'pval),get(de,'fcts),get(de,'vars),get(de,'nonrational),
          if force_sep then pdes else nil)$
 if l=1 then <<
   if print_ then <<
     terpri()$write "Separation of ",de," leads to one or more case distinctions."$
     terpri()
   >>$
   return 1
 >>     else 
 if (length l>1) or ((length l=1) and (caar l neq 1)) then <<
   l:=mkeqSQlist(nil,nil,for each a in l collect cdr a,get(de,'fcts),
                 get(de,'vars),delete('to_sep,allflags_),t,
                 get(de,'orderings),pdes)$
   if print_ then <<
     terpri()$write "Separation of ",de," yields ",l$
     terpri()
   >>$
   return l
 >>
 else <<remflag1(de,'to_sep)$
        if force_sep then remflag1(de,'to_casesep)>>
end$

symbolic procedure splitSQ(de)$
if 0 neq cdr get(de,'starde) then nil else 
begin scalar splitvar,fn,nrk,sv,v,nrkcp,ke,k$
 splitvar:=car get(de,'starde)$
 fn:=get(de,'fcts);

 % We only split wrt variables that occur in kernels without unknown functions.
 nrk:=get(de,'non_rat_kern)$
 if nrk then <<
  sv:=nil;
  while splitvar do <<
   v:=car splitvar; splitvar:=cdr splitvar;
   nrkcp:=nrk;
   while nrkcp and (my_freeof(car nrkcp,v) or freeoflist(car nrkcp,fn)) do
   nrkcp:=cdr nrkcp;
   if null nrkcp then sv:=cons(v,sv)
  >>$
  splitvar:=sv
 >>$

 if null splitvar then return nil$

 % We add all kernels to splitvar which involve splitvar and no fcts
 ke:=get(de,'kern);
 for each k in ke do 
 if (not freeoflist(k,splitvar)) and 
    freeoflist(k,fn) then splitvar:=union({k},splitvar)$

 % sorting the splitvar according to the current kernel ordering
 if cdr splitvar then splitvar:=kernel_sort(splitvar)$

 k:=setkorder splitvar$
 sv:=itercoeff(reorder numr get(de,'sqval),splitvar)$
 setkorder k$

 return sv

end$

symbolic procedure termsep(a,x,nonrat)$
%  splits the product a in two parts: the first contains all
%  factors dependend on x the second all others
%  Result: nil, if no splitting possible
%          ((depending on x)(indep on x))
begin scalar l,p,q,sig,l1,l2,carl$
 if my_freeof(a,x) then l:=list(1,a) else       % a unabh. von x
 if atom a         then l:=list(a,1) else <<    % Variable oder Funktion von x
  if car a='MINUS then<<a:=cadr a$sig:=not sig>>$
  if pairp a and (car a='TIMES) then l:=cdr a  
			        else l:=list a$ % l Liste der Faktoren
   p:=nil$                                      % Liste der x-abhaeng. Faktoren
   q:=nil$                                      % Liste der x-unabhae. Faktoren
   while l do <<
    if my_freeof(car l,x) then q:=cons(car l,q)	%   Faktor enth. x nicht
                          else <<
     carl:=car l$
     if pairp carl and car carl='SQRT then 
     carl:={'EXPT,cadr carl,{'QUOTIENT,1,2}};

     if pairp carl and (car carl='EXPT) and 
	my_freeof(cadr carl,x) and                 % Basis x-unabhaengig
	(pairp caddr carl) and                     % Exponent ist
	(car caddr carl='PLUS) then <<             % eine Summe
      for each s in cdr caddr carl do if my_freeof(s,x) then l1:=cons(s,l1)
						        else l2:=cons(s,l2)$
      if l1 then <<
       if cdr l1 then l1:=cons('PLUS,l1)
		 else l1:=car l1$
       q:=cons(list('EXPT,cadr carl,l1),q)
      >>$
      if l2 and cdr l2 then l2:=cons('PLUS,l2)
		       else l2:=car l2$
      p:=cons(list('EXPT,cadr carl,l2),p)
     >>                      else p:=cons(carl,p)$
    >>$    
    l:=cdr l
   >>$

   if p then if null force_sep and
                not freeoflist(p,nonrat) then <<p:=q:=l:=nil>> else
		p:=if length p>1 then cons('TIMES,p)
                                 else car p$
   if q then if length q>1 then q:=cons('TIMES,q)
		           else q:=car q$
   if p or q then                          %   war Sep. moegl.?
   if null p then if sig then l:=list(1,list('MINUS,q))
	                 else l:=list(1,q)
             else if q then if sig then l:=list(p,list('MINUS,q))
		                   else l:=list(p,q)
                       else if sig then l:=list(p,list('MINUS,1))
			           else l:=list(p,1)>>$
 return l
end$

% What if the denominator depends on nonrat? --> perform a test
symbolic procedure sumsep(l,x,nonrat,pdes)$
%   Separieren einer Liste von Summanden
%   l Liste von Ausdr. in LISP-Notation, x Var.
%   Ergebnis: nil, falls keine Sep. moegl.,
%   sonst Liste von Listen von Summanden
begin scalar cl,p,q,s$
while l do
    if pairp car l and (caar l='QUOTIENT) then
      <<p:=termsep(cadar l,x,nonrat)$
	if not q then q:=termsep(caddar l,x,nonrat);  % Quotient immer gleich
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
      <<p:=termsep(car l,x,nonrat);          %  Separieren eines Summanden
	if p then                            %  erfolgreich
		<<l:=cdr l$
		cl:=termsort(cl,p)>>         %  Terme einordnen
	else
		<<l:=nil$                    %  Abbruch
		cl:=nil>> >>$                %  keine
					     %  Separ. moegl.

 if cl and (length cl>1) then 

 if nonrat and << % test whether cases should be generated
  s:=cl$
  while s and freeoflist(caar s,nonrat) do s:=cdr s$
  s
 >> then << % find two caar cl which could be potentially equal
  if pairp caar cl and (caaar cl='QUOTIENT) 
  then l:=for each s in cl collect cadar s
  else l:=for each s in cl collect car   s$
  s:=equality_assumption(l,x,nonrat,pdes)$
  if  null s then cl:=nil else
  if s neq 1 then cl:=1
     % else leave cl unchanged and consider all terms to be linearly independent
 >>         else <<
  if print_ then <<terpri()$write "separation w.r.t. "$fctprint list x$write" . ">>$
					%   of linear independence
  if pairp caar cl and (caaar cl='QUOTIENT) then
       l:=for each s in cl collect cadar s
  else l:=for each s in cl collect car s$
  if not linearindeptest(l,list x) then cl:=nil
 >>$

 return cl     % either = 1 then case-distinction has been written into todo-list
               % or     = list of x-indep expressions
               % or     = nil if not separable
end$

symbolic procedure expon(h,x)$
if h=1 then 0 else
if h=x then 1 else
if pairp h and car h='EXPT and cadr h=x then caddr h else 
if pairp h and car h='TIMES then 
begin scalar g,s,k$
 s:=for each g in cdr h collect expon(g,x)$
 % if one of the factors is not 1 or x or {'EXPT,x,...} then k:=t
 for each g in s do if null g then k:=t$
 return if k then nil
             else cons('PLUS,s)
end                         else nil$

symbolic procedure equality_assumption(l,x,nonrat,pdes)$
% tries to find an element of l that involves nonrat and could
% potentially be equal some other element without violating an inequality
%
% returns: > nil if relations existed but no solvable relation could be found
%          > 1 if all relations were solvable but already investigated 
%             --> all elements of l are lin independent
%          > s<>nil, s<>1 if possible relation is found
begin scalar a,ea,b,eb,lcp,h,s,print_bak,iq,nr$
 s:=1;
 if pairp l then
 while cdr l and (null s or s=1) do << % as long as there are at least 2 elements
                                       % and no possible equality is found
  % 1. find an element involving nonrat
  h:=l;
  while h and freeoflist(car h,nonrat) do h:=cdr h;

  if null h then l:={1} % no element involing nonrat, cannot be
			% according to test before calling this procedure
            else <<
   a:=car h$ l:=delete(a,l)$
   ea:=expon(a,x)$
   if null ea then s:=nil % non-exponential expression in x
              else <<  
    % Now find an element in l that could be equal a
    lcp:=l$ 
    while lcp and (null s or s=1) do <<
     b:=car lcp; lcp:=cdr lcp;
     eb:=expon(b,x)$
     if null eb then 
     if freeoflist(b,nonrat) then % is ok, only no solution due to inequalities 
                             else s:=nil % non-exponential expression in x
                                         % not sure how to solve -> non-separable
                else <<  
      h:=reval {'DIFFERENCE,ea,eb}$
      print_bak:=print_$
      print_:=nil$
%     h:=simplifypde(h,nonrat,t,nil)$ % h,ftem,factorization,history recording 
      h:=simplifypdeSQ(simp h,nonrat,t,nil,nil)$ 
                            % h,ftem,factorization,history recording,separation 
      % does car h contradict an inequality?
      print_:=print_bak$

      if freeoflist(car h,nonrat) then contradiction_:=t$
      if contradiction_ then contradiction_:=nil 
                        else 
%      if follows_from(h,pdes) then % Is the new condition already in pdes?
      if follows_fromSQ(if pairp cdr h then cdr h
                                       else list car h,pdes) then 
      % Is the new condition already in pdes?
      % Then we are inside a case. The equation to be separated should first
      % be simplified based on 0=h before other cases are to be considered.
      % We therefore mark this expression as 'unseparable so that in
      % separate() it will be set: remflag1(de,'to_casesep)
      <<s:=nil;l:={1};lcp:=nil>>          else <<
       % If the program ever gets to this point, the outcome can only
       % be s=nil or s=(new condition).
       h:=car h$ % in SQ-form

       s:=nil$ nr:=nonrat$
       while nr and null s do <<
        s:=err_catch_solve({'LIST,{'!*SQ,h,t}},list('LIST,car nr))$
        % Does the solution violate any identity?
        % One could run new_ineq_from_pde or ineqreduct but that could
        % change pdes so one needs backup,... . We instead check directly:
        if s then <<
         iq:=ineq_$
!#if (equal version!* "REDUCE 3.6")
         while iq and not zerop reval reval aeval subst(caddar s,cadar s,car iq) do 
!#else          
         while iq and not zerop reval subst(caddar s,cadar s,prepsq car iq) do 
!#endif
         % This is a try to find a situation where one reval is not enough.
            iq:=cdr iq$
         if iq then s:=nil
        >>$
        if null s then nr:=cdr nr
       >>$
       % if null s=nil then there exists an un-solvable case --> sep. not possible
       if s then to_do_list:=cons(list('split_into_cases,h),to_do_list)
      >>
     >>
    >>  
   >>
  >>
 >>$
 return s
end$

symbolic procedure linearindeptest(l,vl)$
begin scalar l1,flag,print_bak$
l1:=l$flag:=t$
while flag and pairp l1 do
	if freeoflist(car l1,vl) then l1:=cdr l1
	else if member(car l1,vl) then l1:=cdr l1
	else if (pairp car l1) and (caar l1='EXPT) and
		(numberp caddar l1) and member(cadar l1,vl) then l1:=cdr l1
	else flag:=nil$
if not flag then <<
        if independence_ then <<
          print_bak:=print_;  print_:=10000
        >>$
        if print_ then <<terpri()$write "linear independent expressions : ">>$
	for each x in l do eqprint(x)$
	if independence_ then <<
	  if yesp "Are the expressions linear independent? " then flag:=t
                                                             else flag:=nil;
          print_:=print_bak
        >>               else flag:=t>>$
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

symbolic procedure eqsep(eql,ftem,nonrat,pdes)$
%   Separieren einer Liste von: Gl. als Liste von Koeffizient + Summ.
%   + Liste der Var. nach denen schon erfolglos sep. wurde
%   + Liste der Var. nach denen noch nicht separiert wurde
begin scalar vlist1,vlist2,a,x,l,eql1$
 % eql is the list of equations that is still to be separated wrt to 
 % some variables
 % eql1 is the list of completely separated equations
 while eql do <<         
  a:=car eql$                   % a ist eine Gl mit Koeff, Ausdr, vlist1 und 2
  vlist1:=cadr a$               % Var. nach d. erfolglos sep. wurde
  vlist2:=caddr a$              % Var. nach denen nicht sep. wurde
  eql:=cdr eql$
  if null vlist2 then eql1:=cons(a,eql1) % a is completely separated
                 else <<        % verbleibende Var. nach denen zu sep. ist
   x:=car vlist2$
   vlist2:=cdr vlist2$
   if my_freeof(cdar a,x) then if vlist2 then 
                               eql:=cons(list(car a,vlist1,vlist2),eql)
                                % a is to be separated wrt. remaining vlist2
                                         else eql1:=cons(a,eql1)
                                % a is completely separated
                          else 
   if member(x,argset smemberl(ftem,list cdar a))
   then eql:=cons(list(car a,cons(x,vlist1),vlist2),eql)
                                % not separable now but perhaps later
   else <<
    l:=sumsep(cdar a,x,nonrat,pdes)$ % nil oder 1 oder Liste der Gl. die sich 
			        % durch Sep. nach x ergeben
    if l=1 then <<eql:=nil; eql1:=1>> else % case distinctions written into todo-list
    if l then if vlist1 or 
                 vlist2 then eql:=append(varapp(l,caar a,nil,
                                                append(vlist2,vlist1)),eql)
			        % nach erfolgr. Sep. wird nach bisher
			        % erfolglosen Var. sep.
                        else eql1:=append(varapp(l,caar a,nil,nil),eql1)
	 else if vlist2 then eql:=cons(list(car a,cons(x,vlist1),vlist2),eql)
                        else eql1:=cons(a,eql1)
   >> 
  >>	   
 >>$
 return eql1$
end$

symbolic procedure varapp(l,a,v1,v2)$
%   an jede Gl. aus l werden v1 und v2 angehaengt
if null l then nil
else
cons(list(cons(cons(caar l,a),cdar l),v1,v2),varapp(cdr l,a,v1,v2))$

symbolic procedure sep(p,ftem,varl,nonrat,pdes)$
%  Die Gl. p (in LISP-Notation) wird nach den Variablen
%  der Liste varl separiert.
%  It returns a list of dotted pairs where the car is the coefficient
%  which depends on the only explicitly occuring variables and
%  the cdr is what is to be set to zero.
%  It may return 1. Then case distinctions have been written into todo-list
begin scalar eql,eqlist,a,q$
  if pairp p and (car p='QUOTIENT) then
  <<q:=cdr err_catch_fac(caddr p)$
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
  eql:=eqsep(eql,ftem,nonrat,pdes)$
  if eql=1 then return 1$

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

%########## Check whether creating case distinctions when calling
% separ2 from crint(?) makes sense
% Check whether it is allowed to happen that sep() returns 1 below
symbolic procedure separ2(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
begin scalar eqlist$
  if p and not zerop p then
  if not (pairp p and (car p='QUOTIENT) and
	 intersection(argset smemberl(ftem,cadr p),varl)) then
  <<eqlist:=sep(p,ftem,varl,nil,nil)$
%##### if eqlist=1 then case distinctions have been written into
%todo-list. Should that be reversed or prevented?

    % because called from specialsol in crint, a more restrictive
    % conditions is ok, as long as it separates, so nil as 4th
    % argument to sep(), i.e. nonrational ftem may occur in the
    % explicit supposed to be linear indep. factors
    if pairp eqlist then eqlist:=union(cdr eqlist,list car eqlist)$
    % The union command drops all duplicate elements of eqlist.
  >>;   % else eqlist is nil

  return eqlist
end$

symbolic procedure separ(p,ftem,varl,nonrat,pdes)$
%  Die Gl. p (in prefix form) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eql,eqlist,a,b,l,s$

  if null p or zerop p then eqlist:=list cons(0,0) else

  if pairp p and (car p='QUOTIENT) and
     intersection(argset smemberl(ftem,caddr p),varl) then % FTEM in DENR of p
  eqlist:=list cons(1,p)                              else

  <<if (pairp p) and (car p = 'TIMES) then p:=reval p$
    eqlist:=sep(p,ftem,varl,nonrat,pdes)$
    if eqlist neq 1 then <<  % if eqlist=1 then case distinctions
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
    >>
  >>$                     

  return eqlist
end$

%----------------------------------------------------

% The following procedures are used for preprocessing of CRACK, i.e.
% for splitting large expressions quickly which are given in standard
% quotient form. To be useful within CRACK, it could be necessary to
% work within CRACK with the standard quotient form and not the prefix form.

%----------------------------------------------------

symbolic procedure itercoeff(sf,splitvar)$
if not pairp sf then {sf} else
if (car sf = '!:rn!:) or
   (car sf = '!:gi!:) then {sf} else
if not member(mvar sf,splitvar) then {sf} else
nconc(itercoeff(lc sf,splitvar),itercoeff(red sf,splitvar))$

%----------------------------------------------------

put('split_simp,'psopfn,'split_simplify)$

symbolic procedure split_simplify(inp)$
% This is a psopfn procedure which does not evaluate the arguments
% automatically, this is done at the start of split_simplify.
% call from algebraic mode:
%     split_simp(eqns,ineq,fncts,indepvar,simp)$
% The input equations and inequalities should be in {!*sq,..,t} 
% form (fast) but can be in prefix form (slow).
% inp is a lisp list of 4 algebraic mode lists: the equations, 
% inequalities, functions/unknowns and independent variables
% and a flag t/nil whether simplifications shall be done.
% The procedure returns a simplified list of splitted equations.
begin 
 scalar le,k,h,p,q,ineq_bak,w,nopowersbak,m,r,s,a,indepvar,splitvar,
        eqns,ine,fll,cpu,to_simplify,max_gc_fac_bak$
 if !*time then cpu:=time();

 if length inp neq 5 then <<
  terpri()$
  write"SPLIT_SIMPLIFY DOES NOT HAVE 5 ARGUMENTS."$
  terpri()$
  write"SOME PARAMETER IS MISSING OR IS TOO MUCH."$
 >>$
 if print_ then <<
  terpri()$
  write"Start of splitting equations"$terpri()$
 >>$

 eqns       := cdr aeval        car inp$
 ine        := cdr aeval       cadr inp$
 fll        := cdr reval      caddr inp$
 indepvar   := cdr reval     cadddr inp$
 to_simplify:=     reval car cddddr inp$

 q:=1;
 for each p in eqns do <<
  if (not fixp p) and (not pairp p or (car p neq '!*sq)) then <<
   write"THE ",q,". ELEMENT OF THE INPUT LIST OF EQUATIONS IS NOT IN STANDARD"$terpri()$
   write"QUOTIENT FORM! THIS MAY HAVE BEEN CAUSED BY USING COMMANDS LIKE cons"$terpri()$
   write"IN ALGEBRAIC MODE. IN THAT CASE, USE sqcons, sqrest, sqfirst, sqsecond,"$terpri()$
   write"sqthird, sqpart INSTEAD."$terpri()$
  >>$
  q:=add1 q
 >>$
 
 if !*time then <<
  write((k:=time())-cpu)/1000," s: Determination of the splitting variables"$
  terpri()$ cpu:=k
 >>$

 % Are there any atomic variables in indepvar that are arguments to any 
 % functions in depl!* ? If yes, then determine all kernels depending
 % on these variables which do not involve fll functions

 % determine the list q of all functions in depl!* that depend on elements of indepvar and
 % that are not in fll:
 splitvar:=nil$
 q:=nil$
 for each h in indepvar do
 if  %  atom h and    % changed 1 Dec 08
    my_freeof(fll,h) then << 
  splitvar:=union({h},splitvar);  % <-- at first collect suitable elements of indepvar
  for each p in depl!* do 
  if freeof(fll,car p) and (not freeof(cdr p,h)) then q:=union({car p},q);
 >>$

 % We will split wrt any kernel that involves functions q
 if q then <<
  k:=nil$
  for each p in eqns do if (pairp p) and (car p = '!*sq) then 
  k:=union(kernels numr cadr p,k);

  % then all kernels that depend on indepvar elements
  for each p in k do % i.e. for each kernel
  if (not freeoflist(p,q)) or (not freeoflist(p,indepvar)) and % changed 1 Dec 08
          freeoflist(p,fll) then splitvar:=union({p},splitvar)
 >>$

 if null splitvar then 
 if null to_simplify then return cons('LIST,eqns) 
                     else <<h:=for each p in eqns collect 
                               if pairp p then numr cadr p
                                          else p;
                            le:=length h>>
                  else <<
  if cdr splitvar then                                          % added 1 Dec 08
  % sorting the splitvar according to the current kernel ordering
  % splitvar:=cdr reval cons('TIMES,splitvar)$  % does work too
  splitvar:=kernel_sort(splitvar)$

  if not linearindeptest(splitvar,indepvar) then return cons('LIST,eqns);   % changed 1 Dec 08

  % Do not split an expression that includes powers depending on splitvar
  % and have non-integer exponents
  k:=search_li2(eqns,'EXPT)$
  h:=splitvar;
  while h and my_freeof(k,car h) do h:=cdr h$
  if h then return cons('LIST,eqns); 

  if !*time then <<
   write((k:=time())-cpu)/1000," s: Variables to be used for splitting: ",splitvar$
   terpri()$ cpu:=k;
   write((k:=time())-cpu)/1000," s: Start of splitting equations"$terpri()$ cpu:=k
  >>$
  k:=setkorder splitvar$
  h:=for each p in eqns conc % faster than join 
     itercoeff(if not pairp p then p else 
               if car p = '!*sq then reorder numr cadr p
                                else         numr simp p, splitvar)$
  setkorder k$
  le:=length h$
  % Print original number of equations and time for splitting
  if print_ then <<write le," equations result"$terpri()>>$
 >>$

 if to_simplify then <<

  if !*time then <<
   write((k:=time())-cpu)/1000,
         " s: Now simplifying equations and dropping multiple ones"$terpri()$
   cpu:=k;
  >>$

  % Simplifying equations and dropping multiple ones
  w:=nil;   % list of equations consisting of only a coefficient
  nopowersbak:=!*nopowers;
  algebraic(off nopowers);
  eqns:=nil$
  ineq_bak:=ineq_;          
  ineq_:=for each a in ine collect cadr a$    % matters in simplifySQ()

  m:=nil; % list of new equations found in each run consisting of only a single unknown
  r:=0;
  max_gc_fac_bak:=max_gc_fac$
  max_gc_fac:=0$  % for err_catch_fac3 
  repeat <<
   r:=add1 r; if print_ then <<write r,". simplification run"$terpri()>>$

   % Substituting all newly found unknows that must vanish in all equations
   if print_ then <<write"Substitution of vanishing unknowns"$ terpri()>>$
   s:=for each a in m collect (a . 0);   % the list of substitutions
   if m then <<
    w:=nconc(m,w)$   % w is the complete list of vanishing unknowns
    m:=nil; % list of new equations consisting of only a single unknown
   >>$
   % h is a list of standard form expressions which are to vanish
   for each p in h do <<  % i.e. for each equation
    if s then q:=numr subf(p,s)
	 else q:=p;            % ### How fast/slow is such an assignment?

    if s and (p=q) then eqns:=union({p},eqns)
		   else << % first time is s=nil

%     p:= cdr err_catch_fac3 numr simp!*sq list(q . 1,nil)$      
     p := cdr err_catch_fac3 q$
	 % simp!*sq  --> internal standard quotient (without !*sq at start),  
	 % numr      --> standard form (numerator)
         % err_atch_fac3 --> call of fctr
	 % fctrf     --> factorization list of factors in special format ...
	 % cdr       --> drop numerical factor

     if null p then %--> q not factorizable
     eqns:=union({numr car simplifySQ((q . 1),fll,nil,nil,nil)},eqns)
               else <<
      % drop all constant factors, i.e. which do no involve an element of fll
      % and all non-zero factors
      q:=nil;
      while p do <<
       if (not freeoflist(caar p,fll)) and % caar gives the basis without 
				           % exponent of first factor
          (not member((caar p . 1),ineq_)) then 
       q:=cons(caar p,q);
       p:=cdr p
      >>$

      % again simplification 
      if null q then eqns:=cons(1,eqns) else 
      if cdr q then <<h:=1;
                      for each k in q do h:=multf(k,h); 
                      eqns:=union({h},eqns)
                    >> % multiplication of factors to give a standard form
	       else <<
       q:=numr car simplifySQ(((car q) . 1),fll,nil,nil,nil)$ 
       if pairp q then    % else q is a number, i.e. a contradiction
       if null cdr q  and % only one term
	  cdar  q = 1 and % coefficient = 1
	  cdaar q = 1 and % exponent    = 1
	  atom caaar q then m   :=union({caaar q},   m) % added to list of vanishing unknowns
		       else eqns:=union({      q},eqns)
      >>
     >>
    >>
   >>$

   h:=eqns; eqns:=nil
  >> until null m;   
  max_gc_fac:=max_gc_fac_bak$
  ineq_:=ineq_bak;  

  k:=length w;
  if print_ then <<write k," coefficients found to be zero: "$
                   if k<100 then listprint w$terpri()>>$
  h:=append(h,w)$
  if print_ then <<write reval (le-length h),
                        " redundant equations have been dropped."$
                   terpri()>>$

 >>$ % of to_simplify

 eqns:=p:=q:=ineq_bak:=w:=nopowersbak:=m:=r:=s:=a:=splitvar:=fll:=le:=nil$

 if nopowersbak then algebraic(on nopowers)$
 if !*time then <<
  write(time()-cpu)/1000," s: The system is formulated."$terpri()
 >>$
  
 return cons('LIST,for each k in h collect list('!*sq, (k . 1) ,nil))

end$

%----------------------------------------------------


endmodule$

end$

tr splitSQ
tr separation
tr get_separ_pde
tr separate
tr separ
tr sep
tr eqsep
tr sumsep
tr termsep
tr termsort
tr equality_assumption
tr linearindeptest
tr itercoeff
