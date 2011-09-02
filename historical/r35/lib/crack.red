comment

Title: CRACK
Authors:

        Andreas Brand
        Institut fuer Angewandte und Technische Informatik
        Friedrich Schiller Universitaet Jena
        07740 Jena,  Germany
        email: maa@hpux.rz.uni-jena.de
        tel.:  + 49 3641 630790 ,

        Thomas Wolf
        School of Mathematical Sciences
        Queen Mary and Westfield College
        University of London
        London E1 4NS
        email: T.Wolf@maths.qmw.ac.uk
        tel.:  + 44 71 975 5493

Date of release: 25 August 93

Abstract:
CRACK is a package for solving overdetermined systems of partial or
ordinary differential equations (PDEs, ODEs). Examples of programs
which make use of CRACK for investigating ODEs (finding symmetries,
first integrals, an equivalent Lagrangian or a "differential
factorization") are added. The manual CRACKMAN gives further details.

REDUCE version: 3.4.
CRACK uses the package ODESOLVE of Malcolm MacCallum which is included
in REDUCE 3.4.

T. Wolf, An Analytic Algorithm for Decoupling and Integrating
         systems of Nonlinear Partial Differential Equations, J. Comp.
         Phys., no. 3, 60 (1985) 437-446.
T. Wolf, The Symbolic Integration of Exact PDEs, preprint.
M.A.H. MacCallum, An Ordinary Differential Equation Solver for REDUCE,
         Proc. ISAAC'88, Springer Lect. Notes in Comp Sci. 358,
         196--205.

Keywords: partial differential equations, computer analytic

$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                     %
%   CRACK Version 25 Aug. 93                                          %
%                                                                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%**********************************************************************
module crackstar$
%**********************************************************************
%  Main program
%  Author: Andreas Brand
%  1991,1993

symbolic fluid '(REDUCEFUNCTIONS_ cont_ odesolve_ fcteval_ print_
         logoprint_ sp_cases independence_ tr_gensep decouple_
         tr_genint contradiction_ poly_only fname_ factorize_ nfct_
         fnew_ special_cases genint_ ineq_ time_)$

symbolic operator setcrackflags$
symbolic procedure setcrackflags$
<<REDUCEFUNCTIONS_:= '(ABS ACOS ACOSD ACOSH ACOT ACOTD ACOTH ACSC ACSCD
                       ACSCH ASEC ASECD ASECH ASIN ASIND ASINH ATAN
                       ATAND ATANH ATAN2 ATAN2D CBRT COS COSD COSH COT
                       COTD COTH CSC CSCD CSCH EXP FACTORIAL HYPOT LN
                       LOG LOGB LOG10 SEC SECD SECH SIN SIND SINH SQRT
                       TAN TAND TANH PLUS DIFFERENCE DF MINUS TIMES
                       QUOTIENT EXPT INT)$
if not fixp nfct_ then
nfct_:=1$          %  index of new functions and constants initialized
cont_:=nil$        % if t then the user will be asked if a de
                   % is too long for integration or substitution
sp_cases:=nil$     % special cases for arbitrary functions or constants
                   % are not of interest
independence_:=nil$% if t then the user will be asked whether or not
                   % expr. are considered to be linear independent
genint_:=nil$      % generalized integration disabled/enabled
factorize_:=5$     % recursion depth for factorizing equations
odesolve_:=100$    % maximal length of a de (number of terms) to be
                   % integrated as ode
fcteval_:=100$     % maximal length of an expression to be substituted
                   % for a function
decouple_:=2$      % max. number of decoupling processes for a function
tr_gensep:=nil$    % Trace generalized separation
tr_genint:=nil$    % Trace generalized integration
fname_:='c$        % name of new functions and constants (integration)
logoprint_:=t$     % print logo for crack call
poly_only:=t$      % all equations are polynomials only
time_:=t$          % print the time needed for running crack
print_:=8>>$       % maximal length of an expression to be printed

symbolic operator crackhelp$
symbolic procedure crackhelp$
<<
terpri()$
write "The call:       CRACK({expr1,...,exprn},{fct1,...,fctm},",
      "{var1,...vark})"$
terpri()$terpri()$
write "expr1,...,exprn are the equations expr1=0,...,exprn=0."$
write "fct1,...,fctm   are the unknown functions depending on ",
      "arguments"$
terpri()$
write "                declared by DEPEND fcti,...$ ."$terpri()$
write "var1,...,vark   are further independent free variables which"$
terpri()$
write "                none of the fcti depends on."$terpri()$terpri()$
write "The Return:     {res1,...,resr},  each resi representing a",
      " solution of the form"$terpri()$
write "resi = {list_remain_ness_and_suff_conditions, ",
      "list_solved_functions,"$
terpri()$
write "        list_free_or_unsolved_functions}"$terpri()$
write "i.e. CRACK returns {} if it found that no solution exists"$
terpri()$terpri()$
write "The performance of CRACK can be controlled with special flags."$
terpri()$
write "The procedure SETCRACKFLAGS() sets the defaults for all flags"$
terpri()$
write "and the procedure LISTCRACKFLAGS() shows the flags and their ",
      "defaults."$
terpri()$
write "All flags are GLOBAL or FLUID symbolic mode variables."$
terpri()$
write "They can be changed with: SYMBOLIC (flagname:=value)$"$
terpri()$terpri()$
write "This helptext can be recalled by: CRACKHP()"$terpri()$
write "For more detailed information see the manual."
>>$

symbolic operator listcrackflags$
symbolic procedure listcrackflags$
<<
write
"The values in parenthesis are the defaults. ",
"For more details see the manual."$
terpri()$terpri()$write
"CONT_ (nil):         ",
"if t then the user will be asked if a de is too long"$
terpri()$write
"                     (wrt. odesolve_, fcteval_) ",
"for integration or substitution"$
terpri()$write
"DECOUPLE_ (2):       maximal number of decoupling attempts ",
"for each function"$
terpri()$write
"FACTORIZE_ (5):      recursion depth for factorizing equations"$
terpri()$write
"FCTEVAL_ (100):      maximal length of an expression to be ",
"substituted"$
terpri()$write
"                     for a function"$
terpri()$write
"FNAME_ ('c):         name of new functions and constants (integr.)"$
terpri()$write
"GENINT_ (nil):       generalized integration disabled/enabled"$
terpri()$write
"INDEPENDENCE_ (nil): if t then the user will be asked whether or not"$
terpri()$write
"                     expressions are considered to be linear ",
"independent"$
terpri()$write
"ODESOLVE_ (100):     maximal length of a de (number of terms) to be"$
terpri()$write
"                     integrated as ode"$
terpri()$write
"PRINT_ (8):          maximal length of an expression to be printed"$
terpri()$write
"SP_CASES (nil):      if nil then dropping also such factors after ",
"factorization"$
terpri()$write
"                     which contain unknown functions or constants ",
"which are"$
terpri()$write
"TIME_ (T):           print the time needed for running crack"$
terpri()$write
"                     parametric and not to calculate"$
terpri()$write
"TR_GENINT (nil):     Trace generalized integration"$
terpri()$write
"TR_GENSEP (nil):     Trace generalized separation"$
terpri()$
>>$

symbolic operator crack$
symbolic procedure crack(el,il,fl,vl)$
begin scalar l,l1,l2,n,m,ezgcdold,mcdold,gcdold,expold,ratold,ratargold$

if print_ and logoprint_ then
<<
"**************************************************************",
"************"$
terpri()$
write
"This is CRACK - a solver for overdetermined partial differential ",
"equations"$
terpri()$
write "Version 25-08-1993"$terpri()$
write
"***************************************************************",
"***********"$
terpri()$
>>$

ezgcdold:=!*ezgcd$
gcdold:=!*gcd$
expold:=!*exp$
mcdold:=!*mcd$
ratold:=!*rational$
ratargold:=!*ratarg$
!*ezgcd:=t$
!*gcd:=nil$
!*exp:=t$
!*mcd:=t$
%!*rational:=nil$
!*rational:=t$
!*ratarg:=t$
fnew_:=nil$
special_cases:=nil$
vl:=union(reverse argset cdr fl,cdr vl)$
%    if print_ then
%     <<terpri()$write "CRACK is called with :"$terpri()$
%     terpri()$write "equations : "$deprint cdr el$terpri()$
%     terpri()$write "functions : "$fctprint cdr fl$terpri()$
%     terpri()$write "variables : "$fctprint vl$terpri()>>$
n:=time()$
m:=gctime()$
l:=union(crack1(cdr el,nil,cdr il,cdr fl,vl,factorize_,nil,nil),nil)$
if !*time or time_ then
   <<terpri()$write "CRACK needed :  ",time()-n," ms    GC time : ",
                    gctime()-m," ms">>$
!*ezgcd:=ezgcdold$
!*gcd:=gcdold$
!*exp:=expold$
!*mcd:=mcdold$
!*rational:=ratold$
!*ratarg:=ratargold$
l:=for each a in l collect
       <<l1:=nil$
       l2:=caddr a$
       for each b in cadr a do
        if (pairp b) and (car b = 'EQUAL) then l1:=cons(b,l1)
                                          else l2:=cons(b,l2)$
       list(car a,l1,l2)>>$
return if l then
       cons('LIST,for each a in l collect list('LIST,cons('LIST,car a),
                                                cons('LIST,cadr a),
                                                cons('LIST,caddr a)))
       else list('LIST)
end$

symbolic procedure crack1(ss,sf,ineq,forg,vl,fact,level,ass)$
%   Main program
begin scalar q,p,s,ftem,fges,f,ls,lf,l,l1,se,ndecouple,decfl$
contradiction_:=nil$
ineq_:=ineq$
ndecouple:=0$
ss:=desort ss$                   %  sort the de's w.r.t. its length
sf:=desort sf$
fges:=union(smemberl(fnew_,append(forg,append(ss,sf))),forg)$
                                 %  add new functions
fnew_:=nil$
rep:    ftem:=smemberl(fges,union(ss,sf))$   %  only occuring functions
 if print_ and (ss or sf) then
  <<terpri()$write "equations: "$
  deprint(ss)$
  deprint(sf)>>$
 if print_ and ineq_ then
    <<terpri()$write "non-vanishing expressions: "$
    for each aa in ineq_ do eqprint aa>>$
 if print_ then
         <<terpri()$write "functions: "$
         fctprint(forg)>>$
 if print_ then fctprint(setdiff(ftem,forg))$
 for each p in union(sf,ss) do
  if member(p,ftem) then l:=cons(cons(0,p),l)$
 while l or ss do
  <<for each p in l do
   <<l1:=ls:=lf:=nil$
   if print_ then
    <<terpri()$write "substitution :  "$
    substprint(cdr p,car p)>>$
   if ineq_ and null (ineq_:=ineqsubst(p,ftem)) then l:=ss:=nil$
   while not contradiction_ and ss do
   <<s:=car ss$
     ss:=cdr ss$
     ls:=cons(reval subst(car p,cdr p,s),ls)$
     contradiction(s,fges)>>$
   while not contradiction_ and sf do
   <<s:=car sf$
     sf:=cdr sf$
     if freeof(s,cdr p) then lf:=cons(s,lf)
     else
     <<ls:=cons(reval subst(car p,cdr p,s),ls)$
       if contradiction(s,fges) then contradiction_:=t>> >>$
   if not contradiction_ then
   <<for each s in se do
      if freeof(s,cdr p) then l1:=cons(s,l1)$
     se:=reverse l1$
     ss:=desort delete(0,union(ls,nil))$
     sf:=desort delete(0,union(lf,nil))>>$
   forg:=fctsubst(car p,cdr p,forg)$
   ftem:=delete(cdr p,ftem)$
   fges:=delete(cdr p,fges)$
  >>$               % alle Fkt. subst.
  ls:=ss$
  l:=nil$
  while not contradiction_ and ls do
   <<q:=car ls$
   ls:=cdr ls$
   ss:=delete(q,ss)$
   if pairp q then
    <<l1:=desort gensep(q,smemberl(union(fnew_,ftem),q),vl)$
    sf:=union(reverse l1,sf)$
    ftem:=union(fnew_,smemberl(ftem,append(sf,ss)))$
    fges:=union(fnew_,smemberl(fges,append(sf,ss)))$
    for each p in l1 do
     if member(p,ftem) then l:=union(list cons(0,p),l)
                       else se:=cons(p,se)$
    if l then ls:=nil>>
   else se:=cons(q,se)$
   se:=desort union(se,nil)$
   if not contradiction_ then
    while se and not l do
     <<if q:=fcteval(car se,ftem,vl) then
      <<l:=union(list q,l)$
      ls:=nil>>$
     se:=cdr se>>
   >>$
  while se and not l do
   <<if q:=fcteval(car se,ftem,vl) then l:=union(list q,l)$
   se:=cdr se>>
  >>$
if contradiction_ then RETURN NIL$
if fact and (fact>0) then
  q:=splitandcrack(sf,ineq_,forg,ftem,vl,fact,level,ass)
                     else q:=nil$
decfl:=makedecfl(fges,decfl)$
if q then p:=nil
else                               %    decoupling process starts
if (ndecouple<decouple_) and
   (p:=decouple(sf,forg,ftem,fges,vl,decfl,fact)) then
   if contradiction_ then RETURN NIL
   else
   <<ndecouple:=add1 ndecouple$
   if setdiff(car p,sf) or setdiff(sf,car p) or (cadr p) then
     <<sf:=car p$
     ss:=cadr p$
     forg:=caddr p$
     fges:=cadddr p$
     decfl:=car cddddr p$
     goto rep>> >>$
if not q then
   <<q:=list list(
          sf,
          forg,
          smemberl(setdiff(fges,forg),
              append(sf,for each l in equallist forg collect cddr l)))$
   if print_ then resout(caar q,cadar q,caddar q)>>$
ineq_:=ineq$
return q
end$         % of crack1

symbolic procedure ineqsubst(p,ftem)$
% tests all q's in ineq_ for subst(car p, cdr p,q)=0
% result: nil, if 0 occurs
%         otherwise list of the subst(car p,...)
begin scalar l,a$
while ineq_ do
 if not freeof(car ineq_,cdr p) then
 <<a:=reval subst(car p, cdr p,car ineq_)$
   if zerop a then
   <<if print_ then
     <<terpri()$write "contradiction :"$
       eqprint list('EQUAL,cdr p,car p)$
       write "because of non-vanishing expression:"$
       deprint list car ineq_>>$
     contradiction_:=t$
     l:=nil$
     ineq_:=nil>>
   else
   <<if pairp a and (car a='QUOTIENT) then a:=cadr a$
     a:=cdr reval list('FACTORIZE,a)$
     for each s in a do
     if smemberl(ftem,s) and not member(s,l) then l:=cons(s,l)$
     ineq_:=cdr ineq_>> >>
 else
 <<l:=cons(car ineq_,l)$
   ineq_:=cdr ineq_>>$
return reverse l$
end$

symbolic procedure contradiction(s,fges)$
% tests expression s for contradiction an non-zero expressions
if (s=0) or smemberl(fges,s) then
  if member(s,ineq_) then
   <<if print_ then
    <<terpri()$write "non-zero expression vanishes : "$
    deprint list s>>$
   t>>
  else nil
else
<<if print_ then
  <<terpri()$write "Contradiction found : "$
    deprint list s>>$
t>>$

symbolic procedure makedecfl(fges,decfl)$
% makes decouple flag list of functions in fges
begin scalar s$
while decfl do
 <<if member(caar decfl,fges) then s:=cons(car decfl,s)$
 decfl:=cdr decfl>>$
for each f in fges do
 if not assoc(f,s) then s:=cons(cons(f,decouple_),s)$
return s$
end$

symbolic procedure resout(sorg,forg,fnew)$
begin scalar l$
if print_ then
   <<for each a in forg do
      if (pairp a) and (car a='EQUAL) then l:=cons(a,l)
                                      else fnew:=cons(a,fnew)$
   terpri()$write "End of this CRACK run"$terpri()$terpri()$
   write "The solution : "$
   if l then
      fctprint l$
   if sorg then
      <<write "Remaining conditions : "$
      deprint sorg$
      if fnew then
         <<write "for the functions : "$fctprint fnew>> >>
   else if fnew then
      <<write "Free functions or constants : "$fctprint fnew>>$
   terpri()$
   write
   "*************************************************************",
   "*************"$terpri()$terpri()>>$
end$

symbolic procedure splitandcrack(sorg,ineq,forg,ftem,vl,fact,level,ass)$
%  If possible one de form sorg is factoirized and
%  crack1 is called with each factor instead
begin scalar l,p,q,a,n$
l:=sorg$
while l do
   if (p:=splitde(car l,ftem)) then    %  factorizing a de
      <<a:=car l$
      if print_ then
           <<terpri()$
           write "factorizing "$deprint(list a)$
           write "we get the alternative equations : "$deprint(p)>>$
      l:=nil>>
   else l:=cdr l$
if p then
   <<n:=0$
   for each d in p do                  %  for each factor
     if not member(d,ineq_) then
       <<ass:=cons(d,ass)$
       n:=n+1$
       level:=cons(n,level)$
       if print_ then
            <<terpri()$
            write "Level : "$
            for each m in reverse level do write m,"."$terpri()$
            write "CRACK is now called with the assumtion(s) : "$
            deprint(reverse ass)>>$
%       sorg:=cons(d,delete(a,sorg))$
       l:=crack1(list(d),delete(a,sorg),ineq,
                 union(forg,smemberl(ftem,sorg)),
                 vl, if fact<2 then nil else fact-1,level,ass)$
       ineq:=union(list d,ineq)$
       ass:=cdr ass$
       level:=cdr level$
       if l then q:=union(clearphantomfct(l,forg),q)>> >>$
                                       %  crack1 is called
return q
end$

symbolic procedure clearphantomfct(l,forg)$
% functions from higher level ftem beeing removed from forg
for each a in l collect clrphfct(a,forg)$

symbolic procedure clrphfct(a,forg)$
begin scalar l,l1,fl$
if a then
  <<for each f in forg do
     if (pairp f) and (car f='EQUAL) then fl:=cons(cadr f,fl)
        else fl:=cons(f,fl)$           % List of functions in forg
  for each f in cadr a do
     if (pairp f) and (car f='EQUAL) then
        (if member(cadr f,fl) then l:=cons(f,l)) % Member of forg
     else l1:=cons(f,l1)$              % free or unknown function
  l1:=smemberl(l1,append(car a,append(fl,l)))$
                                       % occuring in forg or sorg
  return list(car a,l,union(l1,caddr a))>>
end$

endmodule$


%********************************************************************
module decoupling$
%********************************************************************
%  Routines for decoupling de's
%  Author: Andreas Brand
%  August 1991

symbolic procedure eqderiv(p,f,vl)$
%   yields a list of de's by differentiating p w.r.t all those
%   variables from vl on which f not depends
begin scalar l$
vl:=setdiff(vl,fctargs f)$           % variables on which f not depends
for each v in vl do
    if not freeof(p,v) then l:=cons(reval list('DF,p,v),l)$
return l
end$

symbolic procedure decouplelist(liste,f)$
%  produces a list of de's for decoupling process w.r.t function f
%  the elements are of the type: ((expr (deriv.pot)) flag),
%  f Funktion
begin scalar p,q$
p:=nexteq(liste,t)$                     %  find first de marked with t
q:=nexteq(liste,nil)$                   %  find first de marked with nil
return if minausdp(p,q) then
        append(derivlist(list(list(q,nil),list(p,t)),f,
                             difdiff(cadr q,cadr p),fctargs f,t),liste)
                                        %  simplier de is marked with t
                                        %  the other with nil
                                        %  than the de's are diff.
        else append(derivlist(list(list(p,t),list(q,nil)),f,
                   difdiff(cadr p,cadr q),fctargs f,nil),liste)
end$


symbolic procedure nexteq(liste,flag)$
%  finds the first element in liste marked with flag
begin scalar stop$
while (liste and (not stop)) do
      if flag=cadar liste then stop:=t
                          else liste:=cdr liste$
return if stop then caar liste
               else nil$
end$

symbolic procedure derivlist(dl,f,l,v,flag)$
%   differentiates de's from dl, dl:list of de's
%   f:function, l:list of numbers, v:list of variables,
%   flag:de to be substituted by a simplier one
begin scalar m,p,q,li$
for each x in v do
<<m:=car l$
l:=cdr l$
if m<0 then                            %  second de to be diff.
   <<if not q then q:=car nexteq(dl,not flag)$
     q:=reval list('DF,q,x,list('MINUS,m))$
     li:=cons(list(cons(q,ldiff(q,f)),not flag),li)>>
else if 0<m then                       %  first de to be differentiated
   <<if not p then p:=car nexteq(dl,flag)$
     p:=reval list('DF,p,x,m)$
     li:=cons(list(cons(p,ldiff(p,f)),flag),li)>> >>$
return li$
end$

symbolic procedure fctchoose(stem,fl)$
%   finds function from fl with the maximal number of arguments
if null (fl:=smemberl(fl,stem)) then nil
else begin
     scalar s,n$
     s:=car fl$
     n:=fctlength s$
     for each f in cdr fl do
       if length(fctargs f)>n then
          <<s:=f$n:=fctlength s>>$
     return s
end$

symbolic procedure dechoose(gl,f)$
%   chooses two de's from list gl witch are optimal to be decoupled
%   w.r.t function f
begin scalar d,c$
d:=shortdesearch(gl,f)$
c:=secondde(delete(d,gl),d,f)$
return if null c then list(list(d,nil),list(nil,t))
                 else
        if minausdp(d,c) then list(list(c,nil),list(d,t))
                        else list(list(d,nil),list(c,t))
end$

symbolic procedure shortdesearch(gl,f)$
%   finds shortest de from list gl in which function f occurs
if null gl then nil
else if freeof(caar gl,f) then shortdesearch(cdr gl,f)
                          else shortde(car gl,shortdesearch(cdr gl,f))$

symbolic procedure shortde(g1,g2)$
%   finds the shorter of two de's
if null g1 then g2
else if null g2 then g1
        else begin scalar n,m$
                n:=delength(car g1)$
                m:=delength(car g2)$
                return if n<m then g1
                else if n=m then minausd(g1,g2)
                                        %  the simplier de
                        else g2$
end$

symbolic procedure secondde(gl,g,f)$
%   Auswahl der 2. Dgl. aus gl,g 1.Dgl.,f Funktion
begin scalar c$
c:=secondde1(gl,g,f)$
if null c then c:=shortdesearch(gl,f)$
return c
end$

symbolic procedure secondde1(gl,g,f)$
%   Auswahl der kuerzesten Gl. aus gl, die die Funktion f enthaelt und
%   einfacher als die Gleichung g ist
if null gl then nil
else
if freeof(caar gl,f) or minausdp(car gl,g) then secondde1(cdr gl,g,f)
                                    %  Gl., die f nicht enthalten oder
                                    %  schwieriger als g sind, nicht
        else shortde(car gl,secondde1(cdr gl,g,f))$
                                    %  die kuerzere aus der 1. Gl. und
                                    %  der kuerzesten des Rests

symbolic procedure decouple(sorg,forg,ftem,fges,vl,decfl,fact)$
begin scalar repe,a,f,fl,l,l1,s,p,q,r,ss,s13,stem,ftem1,ftem2,stop2,h,
             fctflag$
fl:=t$
repe:=1$
ftem1:=ftem$
stem:=sorg$
rep:
stop2:=nil$
ftem1:=smemberl(ftem1,stem)$
ftem2:=nil$
for each a in ftem1 do
        if assoc(a,decfl) then ftem2:=cons(a,ftem2)$
if null ftem2 then
        <<l:=union(setdiff(stem,sorg),setdiff(s13,sorg))$
                                         %  new equations
        stop2:=t$
        if null l or repe<=0 then
                <<for each a in l do
                      sorg:=union(list reval aeval a,sorg)$
                sorg:=desort sorg$
                fl:=nil>>
        else <<repe:=sub1 repe$
             for each a in l do sorg:=union(list reval aeval a,sorg)$
             sorg:=desort sorg>> >>
else if (f:=fctchoose(stem,ftem2)) then
        <<fctflag:=t$
        f:=assoc(f,decfl)$
        decfl:=cons(cons(car f,sub1 cdr f),delete(f,decfl))$
        f:=car f$
        if print_ then
                <<terpri()$write "decoupling: "$eqprint(f)>>$
        stem:=powappend(stem,f)$
        if print_ then <<terpri()$write "new equations: ">>$
           begin scalar stop3$
rep1:      stop3:=nil$
           l1:=dechoose(stem,f)$           %  optimale Gl. suchen
           p:=caar l1$                     %  p schwierigere Gl.
           if (null caadr l1) and fctflag then
             if length varslist(p,smemberl(ftem,p),vl)>fctlength f then
                                           %  f kommt nur in einer
                                           %  Gl. vor und haengt nicht
                                           %  von allen Variablen ab
                 <<fctflag:=nil$
                 stem:=union(powappend(eqderiv(car p,f,vl),f),stem)$
                                           %  Hinzufuegen neuer Gl.
                 l1:=dechoose(stem,f)$
                 p:=caar l1>>$
           if not null caadr l1 then
           <<repeat
           <<l1:=decouplelist(l1,f)$       %list of de's to be decoupled
           h:=mkldiff(f,cadaar l1)$        %  h leading derivative
           s:=car nexteq(l1,t)$
           if pairp s and (car s='QUOTIENT) then
              <<if (a:=casecheck(caddr s,vl)) then
                   ineq_:=union(list a,ineq_)$
                s:=cadr s$>>$
           r:=car nexteq(l1,nil)$
           if pairp r and (car r='QUOTIENT) then
              <<if (a:=casecheck(caddr r,vl)) then
                   ineq_:=union(list a,ineq_)$
                r:=cadr r>>$
           s:=reval !*q2a simpresultant list(s,r,h)$  %  alg. decoupl.
           s:=car simplifyde(s,ftem1,vl,nil)$
           if contradiction(s,ftem1) then
           <<stem:=nil$
           stop2:=t$
           stop3:=t$
           contradiction_:=t$
           fl:=nil>>
           else
           <<ftem1:=union(fnew_,ftem1)$
             fges:=union(fnew_,fges)$
             if freeof(s,f) and
                stardep(s,smemberl(ftem1,s),varslist(s,ftem1,vl)) then
                  <<ss:=list s$
                  sorg:=desort sorg$
                  fges:=union(fnew_,fges)$
                  stem:=nil$
                  stop2:=t$
                  stop3:=t>> >>$
           if not stop3 then
           if (q:=fcteval(s,ftem1,vl)) then
               <<if print_ then
               <<terpri()$write "substitution :  "$
               substprint(cdr q,car q)>>$
               if member(cdr q,ftem) then
                  <<l:=nil$
                  while sorg do
                   <<a:=car sorg$
                   sorg:=cdr sorg$
                   if freeof(a,cdr q) then l:=cons(a,l)
                   else
                     <<ss:=cons(reval subst(car q,cdr q,a),ss)$
                     if contradiction(car ss,ftem) then sorg:=nil
                     >>
                   >>$
                  if not contradiction_ then
                    <<sorg:=desort reverse l$
                    ss:=desort delete(0,union(ss,nil))$
                    forg:=fctsubst(car q,cdr q,forg)$
                    stop3:=t$
                    stop2:=t>>
                  >>
               else
                  <<stem:=powdelete(stem)$
                  stem:=substandsep(q,stem,ftem1,vl)$
                  if not contradiction_ then
                     <<stem:=powappend(stem,f)$
                     s13:=substandsep(q,s13,ftem1,vl)>>$
                  stop3:=t$
                  if contradiction_ then
                     <<stop2:=t$
                     fl:=t>>
                  >>$
               ftem1:=delete(cdr q,ftem1)>>$
           if not stop3 then
           <<s:=cons(s,ldiff(s,f))$        %  fuehr. Abl. + Potenz
           l1:=reverse l1$                 %  Reihenfolge umkehren
           l:=list(car l1)$                %  einfach. Ausgangsgl.
           l1:=cdr l1$                     %  Glgn., von denen eine
                                           %  ersetzt wird
           while not null l1 and minausdsp(caar l1,s) do
                <<l:=cons(car l1,l)$    %  erste einfachere Gl.
                l1:=cdr l1>>$
           l1:=cons(list(s,not cadar l),l)$    %  durch s ersetzen
           l:=nil$
           stop3:=nil$
           if print_  and (length l1=2) then
                   <<eqprint(list('EQUAL,0,car s))$
                   write "with leading derivative "$
                   write reval list('EXPT,mkldiff(f,cadr s),cddr s)$
                   write " replaces a de with "$
                   write reval list('EXPT,mkldiff(f,cadr p),cddr p)$
                   terpri()>> >> >>
           until ((length(l1)=2) and not q) or stop3$
           if not stop3 then
              if null car s or zerop car s then
                 <<stem:=delete(p,stem)$
                 p:=nil$
                 stop2:=nil>>
              else
                 <<
                 stem:=cons(s,delete(p,stem))$
%                 stem:=cons(cons(algsimple(car s,f,ftem1,vl),cdr s),
%                              delete(p,stem))$
                 p:=s:=nil$
                 stop2:=nil>> >>
           else
                <<s13:=cons(car p,s13)$
                stem:=delete(p,stem)$
                p:=nil$
                stop3:=t>>$
        if not stop3 then goto rep1$
        end$
        stem:=powdelete(stem)>>$
if not stop2 then goto rep$
return if fl then list(sorg,ss,forg,fges,decfl)
             else nil
end$

endmodule$

%*********************************************************************
module separation$
%*********************************************************************
%  Routines for separation of de's
%  Author: Andreas Brand
%  June 1990

symbolic procedure termsep(a,x)$
%   Separieren eines Produktes
%   a Ausdr. in LISP-Notation, x Var.
%   Ergebnis: nil, falls keine Sep. moegl.,sonst Liste von Produktpaaren
%   ((abh. von x)(unabh. von x))
begin scalar l,p,q,sig,l1,l2$
if atom a then if x=a then l:=list(a,1)         %   Variable
                      else l:=list(1,a)         %   Konstante
else if freeof(a,x) then l:=list(1,a)           %   a unabh. von x
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
             <<if freeof(car l,x) then q:=cons(car l,q)
                                                %   Faktor enth. x nicht
             else
               if pairp car l and (caar l='EXPT) and freeof(cadar l,x)
                  and (pairp caddar l) and (car caddar l='PLUS) then
                     <<for each s in cdr caddar l do
                        if freeof(s,x) then l1:=cons(s,l1)
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
begin scalar cl,p,q,s,qflag$
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
        if atom car l1 then l1:=cdr l1
        else if member(car l1,vl) then l1:=cdr l1
        else if caar l1='EXPT then
             if (numberp caddar l1) and member(cadar l1,vl)
                then l1:=cdr l1
                else flag:=nil
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
           if freeof(cdar a,x) then
              eql:=cons(list(car a,vlist1,vlist2),eql)
           else if fctdepend(list cdar a,x,ftem)
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

symbolic procedure separ(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eql,eqlist,a,q,l,s$
if p and not zerop p then
if not (pairp p and (car p='QUOTIENT) and
        intersection(argset smemberl(ftem,cadr p),varl)) then
<<if pairp p and (car p='QUOTIENT) then
    <<q:=cdr reval list('FACTORIZE,caddr p)$
    if length q>1 then q:=cons('TIMES,q)
                  else q:=car q$
    p:=cadr p>>$
if pairp p and (car p='PLUS) then
   a:=cons(nil,if not q then cdr p
               else for each b in cdr p collect list('QUOTIENT,b,q))
else if not q then a:=list(nil,p)
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
        eql:=cdr eql>>$
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
   eqlist:=cons(a,eqlist)>>
>>
else eqlist:=list cons(1,p)        % FTEM functions in the DENR of p
else eqlist:=list cons(0,0)$
return eqlist
end$

symbolic procedure separate(p,ftem,vl)$
%  Separieren der Gleichung p
%  ftem Liste der Fkt., vl Liste der Variablen
begin scalar l$
l:=separ(p,ftem,vl)$
return union(for each a in l collect cdr a,nil)$
end$

symbolic procedure stardep(p,ftem,vl)$
%  yields: nil, if a function (from ftem) in p depends
%               on all variables (from vl)
%          cons(v,n) otherweise, with v beeing the list of variables
%               on which depend a minimal number n of functions
begin scalar ft,b,v,n,m$
vl:=varslist(p,ftem,vl)$
ft:=ftem$
n:=length vl$                          % number of all variables
while not b and ft do                  % searching a fct of all vars
   if fctlength car ft=n then b:=t
   else ft:=cdr ft$
if not b then
  <<n:=sub1 length ftem$
  while vl do                  % searching var.s on which depend a
                               % minimal number of functions
    <<if n> (b:=for each h in ftem sum
                                   if member(car vl,fctargs h) then 1
                                                               else 0)
    then
       <<n:=b$                         % a new minimum
       v:=list car vl>>
    else if b=n then v:=cons(car vl,v)$
    vl:=cdr vl>> >>$
return if v then cons(v,n)             % on each varible from v depend n
                                       % functions
            else nil
end$

symbolic procedure gensep(p,ftem,vl)$
begin scalar a,aa,q,l,l1,l2,ft,pl,pl1,x,vl1,deno$
  if pairp p and (car p = 'QUOTIENT) then
  <<casecheck(caddr p,vl)$
    p:=cadr p>>$
  ftem:=smemberl(ftem,p)$
  vl:=varslist(p,ftem,vl)$
  if not (a:=stardep(p,ftem,vl)) then pl:=list p
                                 else
  if zerop cdr a then pl:=separate(p,ftem,vl)
                 else                              % e.g. a=((x y z).2)
  <<pl:=list p$
    if print_ then <<terpri()$write "generalized separation ">>$
    if tr_gensep then
    <<terpri()$write "de to be separated : "$
      deprint pl$
      terpri()$write "variable list for separation : ",car a$
      terpri()$write "for each of these variables ",cdr a,
                     " function(s) do(es) not depend on it ">>$
    a:=car a$
    while pairp a do % i.e. being able to make a separation for each x
    <<x:=car a$
      q:=p$ ft:=l2:=nil$
      for each f in ftem do
      if member(x,fctargs f) and not freeof(q,f) then ft:=cons(f,ft)$
      if tr_gensep then
      <<terpri()$write "to separate directly w.r.t. ",x$
                 write " the expression : "$deprint list q$
                 write "will be differentiated">>$
      ft:=reverse fctsort ft$      % sorting w.r.t. number of args
      while ft do          % throwing out all functions ft
        if (l1:=felim(q,car ft,ftem,vl,l2)) then
        <<q:=car l1$
          l2:=cadr l1$
          aa:=stardep(q,smemberl(ftem,q),vl)$
          if not aa or zerop cdr aa then ft:=nil
                                    else ft:=smemberl(cdr ft,q)>>
        else ft:=nil$
      if l1 then
      <<if (pairp q) and (car q='QUOTIENT) then
        <<deno:=caddr q;
          q:=cadr q;
          ft:=smemberl(ftem,q)>>           else ft:=nil$
        if ft then
        <<vl1:=nil$
          for each y in vl do if freeof(ft,y) then vl1:=cons(y,vl1)
        >>    else vl1:=vl$
        if aa and zerop cdr aa and not (q=0) then
        <<if tr_gensep then
          <<terpri()$write "trying direct separation of "$
            deprint list q$
            write "Remaining variables: ",vl1>>;
          l1:=separate(q,ftem,vl1)$
          if tr_gensep then
          <<write "The result of direct separation: "$deprint l1>>$
          if l1 and cdr l1 and tr_gensep then
          <<terpri()$
            write "direct separation yields ",length l1," equations">>
        >>
        else l1:=list q$
        l1:=desort for each s in l1 collect
        if deno then
          backint(list('QUOTIENT,s,deno),l2,union(fnew_,ftem),vl)
                else
          backint(s,l2,union(fnew_,ftem),vl)$
        ftem:=union(fnew_,ftem)$
        pl:=union(l1,pl)$
        while l1 do
        <<if fctevalstrict(car l1,ftem,vl) then
          <<pl1:=cons(car l1,pl1)$
            a:=list nil$
            ftem:=union(fnew_,ftem)>>$
          l1:=cdr l1
        >>
      >>$
      a:=cdr a$
    >>$
  >>$
  if pl1 then
    pl:=union(simplifyde(reval p,union(fnew_,ftem),vl,genint_),pl1)
         else
  <<if null pl then pl:=list p$
    for each p in pl do
    pl1:=union(simplifyde(reval p,union(fnew_,ftem),vl,genint_),pl1)$
    pl:=pl1$
    if cdr pl and print_ then
    <<terpri()$write "separation yields ",length pl," equations"$
      if tr_gensep then deprint pl>>
  >>$
  return pl$
end$

symbolic procedure felim(q,f,ftem,vl,l2)$
begin scalar a,b,l,l1,ft1,v,prflag$
  v:=car setdiff(vl,fctargs f)$  % getting rid of f through diff. wrt. v
  ft1:=nil$
  for each f in ftem do if freeof(f,v) then ft1:=cons(f,ft1)$
  if not (pairp q and (car q='QUOTIENT) and smemberl(ft1,caddr q)) then
  <<prflag:=print_$print_:=nil$
    l:=desort separ(q,ft1,list v)$ % det. all lin. ind. factors with v
    if tr_gensep then
    <<terpri()$write "To get rid of ",f,
                     " we differentiate w.r.t. : ",v>>$
    print_:=prflag$
    l1:=nil$
    while l do
    <<a:=car l$
      b:=nil$
      if not freeof(cdr a,f) and (not zerop car a) then
      if (pairp cdr a) and (cadr a='PLUS) then
      <<for each c in cddr a do if not freeof(c,f) then b:=cons(c,b)$
        if b then b:=cons('PLUS,b)>>      else b:=cdr a$
      if b then
      <<l1:=cons(car a,l1)$
%       q:=reval list('DIFFERENCE,q,list('times,b,car a))
      >>$
      l:=cdr l
    >>$
    if tr_gensep then
    <<terpri()$
      write v," - depending coefficients of terms containing ",f," : "$
      for each ss in l1 do eqprint ss>>$
    while l1 do
    <<b:=reval aeval car l1$
      l1:=cdr l1$
      if not zerop b then
      <<a:=reval aeval list('QUOTIENT,q,b)$
  %      if not freeof(a,v) then
        <<l:=cons(b,l)$  % for later backward integrations
          l1:=for each c in l1 collect
                  reval list('DF,list('QUOTIENT,c,b),v)$
          casecheck(b,vl)$
          q:=reval list('DF,a,v)$
          if tr_gensep then
          <<write "The new equation: "$
            eqprint q$
            write "The remaining factors:"$
            for each ss in l1 do eqprint ss$>>
        >>
%                 else <<q:=b$ l1:=nil>>
      >>
    >>$
    if tr_gensep then
    <<terpri()$write "new expression (should not depend on ",f,") : "$
      eqprint q$>>$
    if l then l2:=cons(list(v,l),l2)$
    if tr_gensep and l2 then
    <<write "The list of multiplications and integrations ",
            "to go backwards after direct separation:"$
      for each ss in l2 do <<write "integr. wrt. ",car ss$ terpri()$
                             write "multiply with "$
                             for each aa in cadr ss do
                                 eqprint aa>>
    >>$
    l1:=list(q,l2)
  >>$
  return l1$
end$

symbolic procedure backint(s,l2,ftem,vl)$
begin scalar fl,ft,q,l,v,v1,v2,vf,s2,p,f2,fnew1$
  fnew1:=fnew_$
  fl:=q:=t$
  p:=s$
  while l2 and fl do
  <<l:=car l2$
    l2:=cdr l2$
    v:=car l$
    if tr_gensep then
    <<terpri()$
      write "backward integration w.r.t. ",v," of the expression : "$
      eqprint p>>$
    l:=cadr l$
    while l and q do
    <<ft:=smemberl(ftem,p)$
%terpri()$write "vor int: p= "$eqprint p$
      fnew_:=nil$
      q:=integratepde(p,ft,list v,nil)$
      fnew1:=append(fnew_,fnew1)$
      if q then
      <<fl:=t$
        p:=reval list('TIMES,car l,car q)$

        % Substituting the new functions of integration by derivatives
        % of them such that back-integration can be made
% hat fnew_ nur ein element, d.h. wird nur eine Integration gemacht
% oder mehrere?
        for each f1 in fnew_ do
        <<f2:=f1;
          vf:=setdiff(vl,fctargs f1);
          for each s1 in reverse l2 do
          <<v1:=car s1;
            if not freeof(f1,v1) then
% only then integration makes difficulties
            <<s2:=reverse cadr s1;
              while s2 do
              <<if not smemberl(vf,car s2) then
                  f2:=reval list('DF,list('QUOTIENT,f2,car s2),v1);
% actually only dividing through those factors of (car s2)
% which depend on v1 and which do not contain variables
% which f2 does not depent on.
                s2:=cdr s2
              >>
            >>
          >>;
          if f1 neq f2 then
          <<if tr_gensep then <<write f1," is replaced by ";
                                eqprint f2>>;
            p:=subst(f2,f1,p)$
          >>
        >>;
        ftem:=union(fnew_,ftem)
      >>   else fl:=nil$
      l:=cdr l
    >>
  >>$
  if tr_gensep then if fl then <<terpri()$write "yields : "$
                                 eqprint p$>>
                          else <<terpri()$
                                 write "was not successful.">>$
  fnew_:=union(fnew1,fnew_)$
  return if fl then p
               else s
end$

endmodule$


%*********************************************************************
module integration$
%*********************************************************************
%  Routines for integration of pde's containing unnown functions
%  Author: Andreas Brand
%  June 1990

symbolic procedure intminderiv(p,ftem,vl)$
% yields a list l of variables from vl, such that in p for each v in l
% there exists a derivative of a function f from ftem wrt. v
begin scalar l,ft,a$
for each v in vl do
    <<ft:=ftem$
    a:=t$
    while ft and a do
       if member(v,fctargs car ft) and highdiff(p,car ft,v)=0
          then a:=nil
          else ft:=cdr ft$
    if a then l:=cons(v,l)>>$
return l
end$

symbolic procedure integratepde(p,ftem,varl,genflag)$
%  Generalized integration of the expression p
%     if not genflag then "normal integration"
begin scalar l,l1,vl,n,l2,q,f,flag$
varl:=if genflag then varl
                 else intminderiv(p,ftem,varl)$
q:=p$
if tr_genint then
<<terpri()$write "integration of the expression : "$
eqprint q$
>>$
%ftem:=smemberl(ftem,p)$
vl:=argset ftem$
if zerop q then flag:='success$
for each v in varl do
  if member(v,vl) then
    <<n:=0$
    if flag neq 'genint then
        <<p:=q$
        while (p and not zerop p) do
            <<p:=intpde(q,ftem,vl,v)$
            if p then
               if zerop cadr p then
                  <<q:=car p$n:=add1 n$flag:='success>>
               else if not genflag then p:=nil
                 else
                 <<if print_ and not tr_genint then
                   <<terpri()$write "generalized Integration: ">>$
                   if (l2:=partint(cadr p,smemberl(ftem,cadr p),vl,v))
                   then
                      <<q:=reval list('PLUS,car p,car l2)$
                      n:=add1 n$
                      ftem:=union(fnew_,ftem)$
                      l1:=append(cdr l2,l1)$  % additional de's
                      flag:='genint>>$
                   p:=nil$
                 >>$
            >> >>$
    l:=cons(n,l)>>
  else
    <<flag:='success$
    l:=cons(1,l)$
    q:=reval list('INT,q,v)$
    l2:=1$
    >>$
l:=reverse l$
if not zerop q then
   <<ftem:=reverse fctsort ftem$
   while ftem do
     if fctlength car ftem<length vl then ftem:=nil
     else if fctlinear(q,f) then
             <<f:=car ftem$
             ftem:=nil>>
          else ftem:=cdr ftem$
   if f then
      <<l2:=lderiv2(q,f,fctargs f)$
      l2:=reval coeffn(q,reval car l2,cdr l2)>>
   else l2:=1>>$
return if flag then
          <<if varl then
               for each v in varl do
                  <<q:=list('PLUS,q,intconst(l2,vl,v,car l))$
                  l:=cdr l>>
             else
               <<q:=newfct(fname_,vl,nfct_)$
               nfct_:=add1 nfct_$
               fnew_:=cons(q,fnew_)>>$
          cons(reval q,l1)>>
       else nil$
end$

symbolic procedure intpde(p,ftem,vl,x)$
% integration of an polynomial expr. p w.r.t. x
begin scalar f,ft,l,l1,vl,k,s,a,iflag,flag$
ft:=ftem$
vl:=cons(x,delete(x,vl))$
while ftem and not flag do
   <<f:=car ftem$
   if member(x,fctargs f) then
      <<l1:=l:=lderiv2(p,f,vl)$
      while not (flag or (iflag:=intlintest(p,f,l,x))) do
         <<k:=reval coeffn(p,car l,cdr l)$
         if intcoefftest(lderiv1(k,f,vl),car l,vl) then
            <<a:=decderiv(car l,x)$
            k:=reval list('INT,subst('v_a_r_,a,k),'v_a_r_)$
            k:=reval subst(a,'v_a_r_,k)$
            s:=cons(k,s)$
            p:=reval aeval list('DIFFERENCE,p,list('DF,k,x))$
            if (l:=lderiv2(p,f,vl))=l1 then flag:='neverending
                                       else l1:=l>>
         else flag:='coeffld>>$
      if iflag='nofct then ftem:=smemberl(ftem,p)
      else if fctlength f<length vl then
              <<ftem:=cdr ftem$flag:=nil>>
      else flag:=(iflag or flag)>>
   else ftem:=cdr ftem>>$
return if not flag then
          <<l:=explicitpart(p,ft,x)$
          l:=list('INT,l,x)$
          s:=reval aeval cons('PLUS,cons(l,s))$
          p:=list('DIFFERENCE,p,list('DF,l,x))$
          if poly_only then
             if ratexp(s,ft) then list(s,reval aeval p)
                             else nil
          else list(s,reval aeval p)>>
       else nil$
end$

symbolic procedure explicitpart(p,ft,x)$
% part of a sum p which only explicitly depends on a variable x
begin scalar l$
if not member(x,argset smemberl(ft,p)) then l:=p
else if pairp p then
   <<if car p='MINUS then
        l:=reval list('MINUS,explicitpart(cadr p,ft,x))$
   if (car p='QUOTIENT) and not member(x,argset smemberl(ft,caddr p))
   then
      l:=reval list('QUOTIENT,explicitpart(cadr p,ft,x),caddr p)$
   if car p='PLUS then
      <<for each a in cdr p do
          if not member(x,argset smemberl(ft,a)) then l:=cons(a,l)$
      if pairp l then l:=reval cons('PLUS,l)>> >>$
if not l then l:=0$
return l$
end$

symbolic procedure intconst(co,vl,x,n)$
begin scalar l,l2,f$
while n>0 do
        <<f:=newfct(fname_,delete(x,vl),nfct_)$
        nfct_:=add1 nfct_$
        fnew_:=cons(f,fnew_)$
        l:=cons(list('TIMES,f,list('EXPT,x,sub1 n)),l)$
        n:=sub1 n>>$
if length l>1 then l:=cons('PLUS,l)
                else if pairp l then l:=car l
                                else l:=0$
if length co>1 then
        <<if car co='TIMES then co:=cdr co
                else co:=list co$
        while co do
                <<if freeof(car co,x) then l2:=cons(car co,l2)$
                co:=cdr co>> >>
else if not (co=x) then l2:=list co$
return reval if l2 then cons('TIMES,cons(l,l2))
                   else l
end$

symbolic procedure intcoefftest(l,l1,vl)$
begin scalar s$
return if not pairp l then t
       else if car l='DF then
               <<s:=decderiv(l1,car vl)$
               if pairp s and pairp cdr s then s:=cddr s
                                          else s:=nil$
               if diffrelp(cons(cddr l,1),cons(s,1),vl) then t
                                                       else nil>>
else t$
end$

symbolic procedure fctlinear(p,f)$
<<p:=ldiffp(p,f)$
(null car p) and (cdr p=1)>>$

symbolic procedure intlintest(p,f,l,x)$
%  Test,ob in einem Paar (fuehrende Ableitung.Potenz)
%  eine x-Ableitung linear auftritt
if freeof(l,f) then 'nofct
else                                    %  Fkt. tritt auf
  if (car l) and (cdr l=1) then         %  fuehr. Abl. tritt linear auf
                if pairp car l then     %  Abl. der Fkt. tritt auf
                    if caar l='DF then
                        if member(x,cddar l) then nil
                                        %  x-Abl. tritt auf
                        else if member(x,fctargs cadar l) then 'noxdrv
                                else 'noxdep
                    else 'nodrv
                else 'nodrv
  else 'nonlin$

symbolic procedure decderiv(l,x)$
%  in Diff.ausdr. l wird Ordn. d. Abl. nach x um 1 gesenkt
begin scalar l1$
return if l then if car l='DF then
        <<l1:=decderiv1(cddr l,x)$
        if l1 then cons('DF,cons(cadr l,l1))
                 else cadr l>>
                            else l
           else nil$
end$

symbolic procedure decderiv1(l,x)$
if null l then nil
else
if car l=x then
     if cdr l then
            if numberp cadr l then
                  if cadr l>2 then cons(car l,cons(sub1 cadr l,cddr l))
                  else cons(car l,cddr l)
            else cdr l
     else nil
else cons(car l,decderiv1(cdr l,x))$

symbolic procedure integratede(q,ftem,genflag)$
%  Integration of a de
%  result: newde if successfull, nil otherwise
begin scalar l,l1,fl$
ftem:=smemberl(ftem,q)$
if l1:=integrableode(q,ftem) then       % looking for an integrable ode
   if l1:=integrateode(q,car l1,cadr l1,caddr l1,ftem) then
                                       % trying to integrate it
      <<q:=l1$
      fl:=t$
      ftem:=smemberl(union(fnew_,ftem),q)>>$
if l1:=integratepde(q,ftem,argset ftem,genflag) then
                                       % trying to integrate a pde
      <<q:=car l1$
      l:=for each a in cdr l1 conc
             <<ftem:=union(fnew_,ftem)$
             if (l1:=integratede(a,ftem,nil)) then l1
                                              else list a>>$
      fl:=t$
      ftem:=union(fnew_,ftem)>>$
if fl then
   <<l:=cons(q,l)$
   l:=for each a in l collect reval aeval a$
   l:=for each a in l collect
          if pairp a and (car a='QUOTIENT) then cadr a
                                           else a>>$
return l$
end$

endmodule$

%********************************************************************
module generalized_integration$
%********************************************************************
%  Routines for generalized integration of pde's containing unnown
%  functions
%  Author: Andreas Brand
%  December 1991

symbolic procedure gintorder(p,vl,x)$
%  reorder equation p
begin scalar l,l1,q,n,m,b,c$
  if pairp(p) and (car p='QUOTIENT) then <<q:=caddr p$p:=cadr p>>$
  if pairp(p) and (car p='PLUS) then p:=cdr p   % list of summands
                                else p:=list p$
  while p do
  <<l1:=gintorder1(car p,x)$
    if DepOnAllVars(car l1,x,vl) then l:=p:=nil
                                 else <<l:=termsort(l,l1)$p:=cdr p>> >>$
  if l then
  <<l:=for each a in l collect if cddr a then
               <<b:=car a$
                 c:=cdr reval coeff1(cons('PLUS,cdr a),x,nil)$
                 m:=0;
                 while c and (car c=0) do <<c:=cdr c$m:=add1 m>>$
                 if m>0 then b:=list('TIMES,list('EXPT,x,m),b)$
                 cons(reval b,c)>>
                                         else
                 cons(reval car a,cdr reval coeff1(cadr a,x,nil))$
    if q then
      if freeof(q,x) then
       l:=for each a in l collect
              cons(car a,for each s in cdr a collect
                             reval list('QUOTIENT,s,q))
      else
       l:=for each a in l collect
              cons(reval list('QUOTIENT,car a,q),cdr a)>>$
return l$
end$

symbolic procedure DepOnAllVars(c,x,vl)$
% tests for occurence off vars from vl in factors of c depending on x
begin scalar l$
if pairp c and (car c='TIMES) then c:=cdr c
                              else c:=list c$
while c and vl do
<<if not freeof(car c,x) then
     for each v in vl do if not freeof(car c,v) then l:=cons(v,l)$
  vl:=setdiff(vl,l)$
  c:=cdr c
>>$
return (null vl)$
end$

symbolic procedure gintorder1(p,x)$
%  reorder a term p
begin scalar l1,l2,sig$          % l2:list of factors of p not depending
                                 %    on x or beeing a power of x
                                 % l1:all other factors
if pairp p and (car p='MINUS) then <<sig:=t$p:=cadr p>>$
if pairp p and (car p='TIMES) then p:=cdr p
                              else p:=list p$
for each a in p do
   <<if freeof(a,x) then l2:=cons(a,l2)
     else if a=x then l2:=cons(a,l2)
     else if pairp a and (car a='EXPT) and (cadr a=x) and fixp caddr a
     then l2:=cons(a,l2)
     else l1:=cons(a,l1)>>$
if pairp l1 then
   if cdr l1 then l1:=cons('TIMES,l1)
             else l1:=car l1$
if pairp l2 then
   <<if cdr l2 then l2:=cons('TIMES,l2)
               else l2:=car l2$
   if sig then l2:=list('MINUS,l2)>>$
return list(if l1 then l1 else 1,if l2 then l2 else 1)$
end$

symbolic procedure partint(p,ftem,vl,x)$
begin scalar f,neg,l1,n,k,l$
if tr_genint then
<<terpri()$write "generalized integration of the unintegrated rest : "$
eqprint p
>>$
l:=gintorder(p,vl,x)$
l:=for each s in l collect
    <<f:=newfct(fname_,varslist(car s,ftem,vl),nfct_)$
    nfct_:=add1 nfct_$
    fnew_:=cons(f,fnew_)$
    neg:=t$
    n:=sub1 length cdr s$
    k:=-1$
    l1:=cons(reval list('DIFFERENCE,car s,list('DF,f,x,add1 n)),l1)$
    reval cons('PLUS, for each sk on cdr s collect
                <<neg:=not neg$
                k:=add1 k$
                reval
                list('TIMES,if neg then -1 else 1,
                            list('DF,f,x,n-k),tailsum(sk,k,x))>>
              )>>$
if l then l:=cons(reval cons('PLUS,l),l1)$
if tr_gensep then
 <<terpri()$
 write "result (without constant or function of integration): "$
 eqprint car l$
 write "additional equations : "$
 deprint cdr l$
>>$
return l$
end$

symbolic procedure tailsum(sk,k,x)$
begin scalar j$
j:=-1$
return reval cons('PLUS,
for each a in sk collect
    <<j:=j+1$
    list('TIMES,a,prod(j+1,j+k),list('EXPT,x,j)) >> )
end$

symbolic procedure prod(m,n)$
if m>n then 1
       else for i:=m:n product i$

endmodule$

%********************************************************************
module odeintegration$
%********************************************************************
%  Routines for integration of ode's containing unnown functions
%  Author: Thomas Wolf
%  August 1991

symbolic procedure integrateode(de,fold,xnew,ordr,ftem)$
begin scalar newde,newnewde,l$        % Integral einer Gleichung
 return
 if not xnew then begin         % Integr. einer alg. Gl. fuer eine Abl.
  newde:=cadr solveeval list(de,fold)$
  newde:=reval list('PLUS,cadr newde,list('MINUS,caddr newde))$
  return
  if newde=de then nil
              else if (l:=integratede(newde,ftem,nil)) then car l
                                                       else nil$
 end         else               % eine ode fuer ein f?
 if not pairp fold then         % i.e. not df(...,...), i.e. fold=f
                        odeconvert(de,fold,xnew,ordr)
                                % --> ode fuer eine Abl. von f
                   else begin
  newde:=odeconvert(de,fold,xnew,ordr)$
%  if print_ then
%     if newde then <<terpri()$write "One ode has been integrated.">>$
  return
  if not newde then nil
               else <<
    newnewde:=cadr solveeval list(newde,fold)$
    newnewde:=reval list('PLUS,cadr newnewde,list('MINUS,
                                                  caddr newnewde))$
    ftem:=union(fnew_,ftem)$
    newnewde:=integratede(newnewde,ftem,nil)$
    if newnewde then car newnewde
                else newde >>
 end
end$  % of integrateode

symbolic operator polyans$
symbolic procedure polyans(ordr,dgr,x,y,d_y,fn)$
% generates a polynom
% for i:=0:dgr sum fn"i"(x,y,d_y(1),..,d_y(ordr-1))*d_y(ordr)**i
% with fn as the function names and d_y as names or derivatives of y
% w.r.t. x
begin scalar ll,fl,a,i,f$
    i:=sub1 ordr$
    while i>0 do
          <<ll:=cons(list(d_y,i),ll)$
          i:=sub1 i>>$
    ll:=cons(y,ll)$
    ll:=reverse cons(x,ll)$
    fl:=nil$
    i:=0$
    while i<=dgr do
    <<f:=newfct(fn,ll,i)$
      fl:=(f . fl)$
      a:=list('PLUS,list('TIMES,f,list('EXPT,list(d_y,ordr),i)),a)$
      i:=add1 i>>$
    return list('list,reval a,cons('list,fl))
end$ % of polyans

symbolic operator sepans$
symbolic procedure sepans(kind,v1,v2,fn)$
% Generates a separation ansatz
% v1,v2 = lists of variables, fn = new function name + index added
% The first variable of v1 occurs only in one sort of the two sorts of
% functions and the remaining variables of v1 in the other sort of
% functios.
% The variables of v2 occur in all functions.
% Returned is a sum of products of each one function of both sorts.
% form: fn1(v11;v21,v22,v23,..)*fn2(v12,..,v1n;v21,v22,v23,..)+...
% the higher "kind", the more general and difficult the ansatz is
% kind = 0 is the full case
begin scalar n,vl1,vl2,h1,h2,h3,h4,fl$
  if cdr v1 = nil then <<vl1:=cdr v2;vl2:=cdr v2>>
                  else <<vl1:=cons(cadr v1,cdr v2)$
                         vl2:=append(cddr v1,cdr v2)>>$
  return
  if kind = 0 then <<vl1:=append(cdr v1,cdr v2)$
                     h1:=newfct(fn,vl1,'_)$
                     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 1 then <<h1:=newfct(fn,vl1,1)$
                     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 2 then <<h1:=newfct(fn,vl2,1)$
                     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 3 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     list('LIST,reval list('PLUS,h1,h2),
                          list('LIST,h1,h2))>>
  else
  if kind = 4 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     list('LIST,reval list('TIMES,h1,h2),
                          list('LIST,h1,h2))>>
  else
  if kind = 5 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
                          list('LIST,h1,h2,h3))>>
  else
  if kind = 6 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl2,3)$
                     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
                          list('LIST,h1,h2,h3))>>
  else
  if kind = 7 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     h4:=newfct(fn,vl2,4)$
                     list('LIST,reval list('PLUS,
                          list('TIMES,h1,h2),h3,h4),
                          list('LIST,h1,h2,h3,h4))>>
  else
% ansatz of the form FN = FN1(v11,v2) + FN2(v12,v2) + ... + FNi(v1i,v2)
  if kind = 8 then <<n:=1$ vl1:=cdr v1$ vl2:=cdr v2$
                    fl:=();
                     while vl1 neq () do <<
                       h1:=newfct(fn,cons(car vl1,vl2),n)$
                       vl1:=cdr vl1;
                       fl:=cons(h1, fl);
                       n:=n+1
                     >>;
                     list('LIST, cons('PLUS,fl), cons('LIST,fl))>>


  else
                   <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     h4:=newfct(fn,vl2,4)$
                     list('LIST,reval list('PLUS,list('TIMES,h1,h2),
                                                 list('TIMES,h3,h4)),
                          list('LIST,h1,h2,h3,h4))>>
end$ % of sepans

symbolic procedure odecheck(ex,fint,ftem)$
% assumes an revaled expression ex
% Does wrong if car ex is a list!
begin scalar a,b,op,ex1$
                   %***** ex is a ftem-function *****
 if ex=fint then             % list(ex,0,0,..)
   <<a:=list ex$
     ex:=fctargs ex$
     while ex do
      <<a:=append(list(0,0),a)$
      ex:=cdr ex>>$
      % not checked if it is a function of an expression of x
     op:=reverse a>>
 else if pairp ex then
                          %***** car ex is 'df *****
 if (car ex)='df then
  <<a:=odecheck(cadr ex,fint,ftem)$
  if not pairp a then op:=a
  else                            % a is list(fctname,0,0,..,0,0)
   <<op:=list(car a)$
   a:=fctargs car a$              % a is list(variables), not checked
   ex:=cddr ex$                   % ex is list(derivatives)
   while a do
    <<ex1:=ex$
    while ex1 and ((car a) neq (car ex1)) do ex1:=cdr ex1$
    if null ex1 then op:=cons(0,cons(0,op))
    else
     <<if not cdr ex1 then b:=1   % b is number of deriv. of that var.
     else
      <<b:=cadr ex1$
      if not numberp b then b:=1>>$
     op:=cons(b,cons(b,op))>>$
    a:=cdr a>>$
   op:=reverse op>> >>
 else
             %***** car ex is a standard or other function *****
  <<a:=car ex$                    % for linearity check
  ex:=cdr ex$
  if a='INT then ex:=reval car ex$
  while (op neq '!_abb) and ex do
   <<b:=odecheck(car ex,fint,ftem)$
   if b then                                  % function found
   if b eq '!_abb then op:='!_abb else        % occures properly
   if not poly_only then op:=odetest(op,b) else      % linearity check
   if (a = 'PLUS) or (a = 'MINUS) then op:=odetest(op,b) else
   if a = 'TIMES then
   if smemberl(ftem,cdr ex) then op:='!_abb
                                  %car b is f.-name->freeof works
                            else op:=odetest(op,b)
                 else op:='!_abb$
   ex:=cdr ex>> >>$
 return op
end$

symbolic procedure integrableode(p,ftem)$
if delength p>(if odesolve_ then odesolve_ else 0) then
   (if cont_ then
      if yesp("expression to be integrated ? ") then
           integrableode1(p,ftem))
else integrableode1(p,ftem)$

symbolic procedure integrableode1(p,ftem)$
begin scalar a,b,u,vl,le,uvar,
           fint,fivar,% the function to be integrated and its variables
           fold,      % the new function of the ode
           xnew,      % the independ. variable of the ode
           ordr1,     % order of the ode
           ordr2,     % order of the derivative for which it is an ode
           intlist$   % list of ode's
  ftem:=smemberl(ftem,p)$
  vl:=argset ftem$
% p muss genau eine Funktion aus ftem von allen Variablen enthalten.
% Die Integrationsvariable darf nicht Argument anderer in p enthaltener
% ftem-Funktionen sein.
  a:=ftem$
  b:=nil$
  le:=length vl$
  while a and vl do
    <<u:=car a$
    uvar:=fctargs u$
    if (length uvar) = le then
       if b then
          <<vl:=nil$a:=list(nil)>>
       else
          <<b:=t$
          fint:=u$
          fivar:=uvar>>
    else vl:=setdiff(vl,uvar)$
    a:=cdr a>>$
  if not b then vl:=nil$
  le:=length p$
  if ((1<le) and vl) then
    <<a:=odecheck(p,fint,ftem)$
    if not atom a then                     % The equation is an ode
      <<ordr1:=0$
      ordr2:=0$
      xnew:=nil$
      a:=cdr a$
      b:=fivar$
      while b do
        <<if (car a) neq 0 then
           <<fold:=cons(car b,fold)$
           if (car a) > 1 then fold:=cons(car a,fold)>>$
        ordr2:=ordr2+car a$
        if (car a) neq (cadr a) then
           <<xnew:=car b$
           if not member(xnew,vl) then
              <<b:=list(nil)$vl:=nil>>$
           ordr1:=(cadr a) - (car a)>>$
        b:=cdr b$
        a:=cddr a>>$
      fold:=reverse fold$
        %fold is the list of diff.variables + number of diff.
      if fold then fold:=cons('df,cons(fint,fold))
              else fold:=fint$
      if vl and ((ordr1 neq 0) or (ordr2 neq 0)) then
        intlist:=list(fold,xnew,ordr1,ordr2)
    >>     % of variable found
  >>$    % of if
  return intlist
end$  % of integrableode1

symbolic procedure odetest(op,b)$
if not op then b
else                           % op=nil --> first function found
  if (car op) neq (car b) then '!_abb else  % f occurs in differ. fct.s
begin scalar dif,a$
 dif:=nil$                     % dif=t --> different derivatives
 a:=list(car op)$              % in one variable already found
 op:=cdr op$
 b:=cdr b$
 while op do
  <<a:=cons(max(cadr op,cadr b),cons(min(car op,car b),a))$
  if (car a) neq ( cadr a) then
  if dif then
    <<a:='!_abb$
    op:=list(1,1)>>
  else dif:=t$
  op:=cddr op$
  b:=cddr b>>$
 if not atom a then a:=reverse a$
 return a      % i.e. '!_abb or  (fctname,min x1-der.,max x1-der.,...)
end$

symbolic procedure odeconvert(de,ford,xnew,ordr)$
begin scalar j,ford_,newco,oldde,newde,newvl,null_$
 ford_:='y_$%gensym$
 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 depend1(ford_,xnew,t)$
 oldde:=reval subst(ford_,ford,de)$
 if pairp ford then                 % i.e.  (car ford) eq 'DF then
 << for j:=1:ordr do
   oldde:= subst( reval list('DF,ford_,xnew,j),
                  reval list('DF,ford,xnew,j), oldde)>>$
 algebraic !!arbconst:=0$
 algebraic ( explog:= {
 cot(~x) => 1/tan(x),
 e**(~x+~y) => e**x*e**y,
 sqrt(e)**(~x+~y) => sqrt(e)**x*sqrt(e)**y,
 e**((~x+~y)/~z) => e**(x/z)*e**(y/z),
 sqrt(e)**((~x+~y)/~z) => sqrt(e)**(x/z)*sqrt(e)**(y/z),
 sqrt(e)**(log(~y)/~x) => y**(1/x/2),
 sqrt(e)**(-log(~y)/~x) => y**(-1/x/2),
 sqrt(e)**(~x*log(~y)/~z) => y**(x/z/2),
 sqrt(e)**(-~x*log(~y)/~z) => y**(-x/z/2),
 sqrt(e)**((~x*log(~y))/~z) => y**(x/z/2),
 e**(log(~y)/~x) => y**(1/x),
 e**(~x*log(~y)/~z) => y**(x/z),
 e**((~x*log(~y))/~z) => y**(x/z),
 int(df(~y,~x)/~y,~x) => log(y) })$
 algebraic( let explog )$
 newde:=algebraic first
            odesolve(symbolic oldde,symbolic ford_,symbolic xnew)$
 if (cadr newde neq oldde) then begin   % solution found
  % Test der Loesung klappt nur, wenn Loesung explizit gegeben
  if cadr newde neq ford_ then
  (if print_ then
    <<write "Solution of the ode is not explicitly given."$
    algebraic write "Equation is: ",algebraic symbolic oldde$
    algebraic write "Solution is: ",algebraic symbolic newde>>)
                           else begin
   null_:=reval reval aeval subst(caddr newde, ford_, oldde)$
%  reval reval because of a REDUCE bug for special data,
%  to be droped as soon as possible
   if (null_ neq 0) then begin
%    newde:=nil;
    if print_ then begin
     write "odesolve solves :  "$
     deprint list oldde$
     write "to"$
     deprint list newde$
     Write "which inserted in the equation yields"$
     deprint list null_$
    end
   end
  end
 end$
 algebraic ( clear explog )$
 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 if newde then
 <<newde:=list('PLUS,cadr newde,list('MINUS,caddr newde))$
   if 0 = reval list('PLUS,newde,list('MINUS,oldde)) then newde:=nil>>$
 return
 if not newde then nil
              else
 <<newde:=subst(ford,ford_,newde)$
   newvl:=delete(xnew,if (pairp ford and (car ford='DF))
                         then fctargs cadr ford
                         else fctargs ford)$
%   if pairp ford then newvl:=delete(xnew,cdr assoc(cadr ford,depl!*))
%                 else newvl:=delete(xnew,cdr assoc(ford,depl!*))$
   for j:=1:ordr do begin
    newco:=newfct(fname_,newvl,nfct_)$
    nfct_:=add1 nfct_$
    fnew_:=cons(newco,fnew_)$
    newde:=subst(newco,list('arbconst,j),newde)
%    newde:=subst(newco, prepf !*kk2f list('arbconst,j),newde)
%    newde:=reval subst(newco,list('arbconst,j),newde)
%    newde:=reval subst(newco, prepf !*kk2f list('arbconst,j),newde)
   end$
   newde>>
end$

endmodule$

%********************************************************************
module simplifications$
%********************************************************************
%  Routines for simplifications and substitution of functions
%  Author: Andreas Brand
%  August 1991

symbolic procedure clearfactors(sorg,ftem,vl)$
%  liefert Liste der Gl. die entstehen, wenn in allen Gl. aus sorg
%  gemeinsame Faktoren, die keine der Funktionen aus ftem sowie deren
%  Ableitungen enthalten, gekuerzt werden
if sorg and ftem then
begin scalar l,ft$
while sorg do
        <<if not zerop car sorg then
        if not(ft:=smemberl(ftem,car sorg)) then l:=cons(car sorg,l)
        else l:=cons(reval algsimple(reval car sorg,car ft,ft,vl),l)$
        sorg:=cdr sorg>>$
return l
end
else sorg$

symbolic procedure algsimple(g,f,ftem,vl)$
%  Gl. die entsteht, wenn in g gemeinsame Faktoren, die keine der Fkt.
%  aus ftem sowie deren Ableitungen enthalten, gekuerzt werden
if pairp g then
begin scalar h,l$
if car g='MINUS then g:=algsimple(cadr g,f,ftem,vl)
else if car g='QUOTIENT then
   g:=reval aeval list('QUOTIENT,algsimple(cadr g,f,ftem,vl),
                                 algsimple(caddr g,f,ftem,vl))
else
<<h:=ftem$
if pairp g and (car g='PLUS) and (pairp cadr g) and (caadr g='MINUS)
then g:=reval list('MINUS,g)$
if freeof(g,f) then
    <<f:=nil$
    while h do
        if not freeof(g,car h) then <<f:=car h$h:=nil>>
                               else h:=cdr h>>$
if f then
    <<l:=lderiv2(g,f,fctargs f)$
    h:=car reverse cdr reval list('COEFF,g,reval car l)$
      %highest coefficient
    if lowpow!*>1 then
       g:=reval list('QUOTIENT,g,list('EXPT,car l,lowpow!*-1))$
    if not zerop h then
        if pairp h then
            <<h:=independpart(reval list('GCD,g,h),ftem,vl)$
            if not zerop h then g:=reval list('QUOTIENT,g,h)>>
        else g:=reval list('QUOTIENT,g,list('GCD,g,h))>>
>>$
return g
end
else if zerop g then 0
                else if freeof(ftem,g) then 1
                                       else g$

symbolic procedure lcasepossible(l,vl)$
begin scalar l1$
for each a in l do l1:=union(list casepossible(a,vl),l1)$
return delete('NIL,l1)
end$

symbolic procedure casepossible(a,vl)$
if pairp a then
 if (car a='QUOTIENT) or (car a='EXPT) or (car a='MINUS) then
  casepossible(cadr a,vl)
 else
  if car a='TIMES then begin scalar l$
   return if (l:=lcasepossible(cdr a,vl)) then reval cons('TIMES,l)
  end
  else if setdiff(idlist a,append(idlist vl,REDUCEFUNCTIONS_)) then a
else if setdiff(idlist a,append(idlist vl,REDUCEFUNCTIONS_)) then a$

symbolic procedure casecheck(p,vl)$
begin scalar a$
 if (a:=casepossible(p,vl)) and not member(a,special_cases) then
  <<special_cases:=cons(a,special_cases)$
  ineq_:=union(list a,ineq_)$
  if print_ then
   <<terpri()$write "Special case to be considered : "$
   deprint list a>> >>$
 return a
end$

symbolic procedure independpart(g,ftem,vl)$
%  determines factors not depending on functions in ftem
begin scalar l,l1$
g:=cdr reval list('FACTORIZE,g)$
while g do
  <<if member(car g,cdr g) or member(car g,ineq_)
      then l:=cons(car g,l)
      else l1:=cons(car g,l1)$
  g:=cdr g>>$
for each x in l1 do
  if not smemberl(ftem,x) then
   if not casecheck(x,vl) or not sp_cases then l:=cons(x,l)$
return if l then if cdr l then cons('TIMES,l)
                          else car l
            else 1
end$

symbolic procedure splitde(p,ftem)$
begin scalar l$
    if pairp p and (car p='QUOTIENT) then p:=cadr p$
    for each x in cdr reval list('FACTORIZE,p) do
          if smemberl(ftem,x) then l:=cons(reval x,l)$
return if length l>1 then union(l,nil)
                     else nil
end$

symbolic procedure simplifyde(a,ftem,vl,genflag)$
begin scalar l,f,p$
ftem:=smemberl(ftem,a)$
if f:=fctchoose(list a,ftem) then
   <<p:=reval algsimple(reval a,f,ftem,vl)$
   if not p or zerop p then
    <<write "***** Error in ALGSIMPLE : "$
    mathprint a>>
   else a:=p$
   if not stardep(a,ftem,vl) then
    if (l:=integratede(a,ftem,genflag)) and print_ then
      if null cdr l then
         <<terpri()$write "integrated equation :  "$deprint(l)>>
      else
          <<terpri()$write "generalized integration yields ",
                           length l," equations :  "$deprint(l)>> >>$
return if l then l
            else list a
end$

symbolic procedure fctsubst(ex,fo,forg)$
% substitution of a function fo in the list forg by an expression ex
<<%if not member(fo,forg) then depl!*:=delete(assoc(fo,depl!*),depl!*)$
for each f in forg collect
    if f=fo then list('EQUAL,fo,ex)
            else if freeof(f,fo) then f
                                 else reval subst(ex,fo,f)>>$

symbolic procedure substandsep(g,sorg,ftem,vlist)$
%  in allen Gl. aus sorg wird die Fkt. car g durch cdr g ersetzt
begin scalar l,p,q,a$
while sorg do
    <<p:=car sorg$
    sorg:=cdr sorg$
    if freeof(p,car g) then l:=union(list p,l)
    else
        <<q:=reval subst(cdr g,car g,p)$
        if (ineq_:=ineqsubst(g,ftem)) then
          if pairp q then
             <<a:=gensep(q,smemberl(union(fnew_,ftem),q),vlist)$
             if contradiction_ then l:=sorg:=nil
                               else l:=union(car a,l)>>
          else
             if q neq 0 then l:=union(list q,l)>>
    >>$
return l
end$

symbolic procedure fcteval(p,ftem,vl)$
begin
  if pairp p and (car p='QUOTIENT) then
   <<casecheck(caddr p,vl)$
   p:=cadr p>>$
  return
  if delength p>(if fcteval_ then fcteval_ else 0) then
     (if cont_ then
        if yesp("function to be evaluated ? ") then
              fcteval1(p,ftem,vl))
  else fcteval1(p,ftem,vl)
end$

symbolic procedure fcteval1(p,ftem,vl)$
begin scalar l,f,n,ft,a$
  ft:=smemberl(ftem,p)$
  n:=length varslist(p,ft,vl)$
  for each x in ft do
      if fctlength x>=n then
          <<l:=ldiffp(p,x)$
          if (null car l) and (cdr l=1) then
             if freeofzero(coeffn(p,x,1),delete(x,ft)) then f:=x>>$
  if f then
    p:=reval list('DIFFERENCE,f,list('QUOTIENT,p,coeffn(p,f,1)))$
return if f then cons(p,f)
            else nil$
end$

symbolic procedure freeofzero(p,ft)$
%   liefert t, falls p nicht 0 wird
if null ft then t
else if freeof(p,car ft) then freeofzero(p,cdr ft)
else
begin scalar a$
 p:=cdr reval list('FACTORIZE,p)$
 while p do
  if null smemberl(ft,car p) or member(car p,ineq_) then p:=cdr p
                                                    else <<p:=nil$
                                                         a:=t>>$
return (null a)
end$

symbolic procedure fctevalstrict(a,ftem,vl)$
% fcteval with additional condition
% substituted expr. contains only functions of less arguments
% than the function
begin scalar l,n,ft$
 l:=fcteval(a,ftem,vl)$
 if l then
  <<ft:=smemberl(ftem,car l)$
  n:=for each f in ft collect length fctargs f$
  if not (reval cons('MAX,n)<length fctargs cdr l) then l:=nil>>$
 return l$
end$

endmodule$

%********************************************************************
module utilities$
%********************************************************************
%  Routines for finding leading derivatives and others
%  Author: Andreas Brand
%  June 1990

symbolic procedure diffrel(p,q,v)$
%   liefert komplizierteren Differentialausdruck$
if diffrelp(p,q,v) then q
                   else p$

symbolic procedure diffrelp(p,q,v)$
%   liefert q, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
if null v then                          %  alle Variable untersucht ?
        if cdr p>cdr q then nil
                  else t
else begin
        scalar a,b$
        a:=diffdeg(car p, car v)$       %  Ordnung der Ableitung nach
        b:=diffdeg(car q,car v)$        %  der ersten Variablen
        return if a<b then t
        else if b<a then nil
                else diffrelp(p,q,cdr v) %  falls Ableitungen
                                        %  erste Variable gleich, dann
                                        %  restliche Variablen
end$

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

symbolic procedure ldiff(p,f)$
%  Suchen der fuehrenden Ableitung der Fkt. f(arg1.,...,argn) in p
%  p Ausdruck in Listenform,f Funktion in listenform
%  Ergebnis: (p,(liste.power))$ liste: Liste der Ordn. der Ableitungen

begin scalar l$
l:=ldiffp(p,f)$                         %  fuerende Liste mit Potenz
return cons(ldiff1(car l,fctargs f),cdr l)$
                                        %  aus Liste Variablen + Ordnung
                                        %  wird Liste der Ordnungen
end$

symbolic operator fargs$
symbolic procedure fargs f$
cons('LIST,fctargs f)$

symbolic procedure fctargs f$
%  arguments of a function
%if pairp f then cdr f$
if (f:=assoc(f,depl!*)) then cdr f$


symbolic procedure fctlength f$
%  number of arguments
length fctargs f$

symbolic procedure argset(ftem)$
%  List of arguments of all functions in ftem
if ftem then union(reverse fctargs car ftem,argset(cdr ftem))
        else nil$

symbolic procedure ldiff1(l,v)$
%  liefert Liste der Ordnungen der Ableitungen nach den Variablen aus v
%  l Liste (Variable + Ordnung)$ v Liste der Variablen
if null v then nil                      %  alle Variable abgearbeitet ?
else cons(diffdeg(l,car v),ldiff1(l,cdr v))$
                                        %  Ordnung der Ableitung nach
                                        %  erster Variable anhaengen

symbolic procedure ldiffp(p,f)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ldiffp1(p,f,fctargs f)$

symbolic procedure ldiffp1(p,f,vl)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion, lv Variablenliste
begin scalar a$
a:=cons(nil,0)$
if not atom p then
if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,'QUOTIENT,'DF,'EQUAL))
then
                                        %  erlaubte Funktionen
        <<if (car p='PLUS) or (car p='TIMES) or (car p='QUOTIENT)
             or (car p='EQUAL) then
                <<p:=cdr p$
                while p do
                        <<a:=diffrel(ldiffp1(car p,f,vl),a,vl)$
                        p:=cdr p>> >>
        else if car p='MINUS then
                a:=ldiffp1(cadr p,f,vl)
        else if car p='EXPT then        %  Exponent
                        if numberp caddr p then
                        <<a:=ldiffp1(cadr p,f,vl)$
                                        %  fuehrende Abl. aus der Basis
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
        else a:=cons(nil,0)             %  alle uebrigen Fkt. werden wie
else if p=f then a:=cons(nil,1)$        %  Konstante behandelt
return a
end$

symbolic procedure lderiv(p,f)$
%  fuehrende Ableitung in LISP-Notation ohne Potenz
lderiv1(p,f,fctargs f)$

symbolic procedure lderiv1(p,f,vl)$
%  fuerende Ableitung in LISP-Notation ohne Potenz
%  mit Angabe der Rangfolge der Variablen
begin scalar l$
l:=ldiffp1(p,f,vl)$
return if car l then cons('DF,cons(f,car l))
                  else if zerop cdr l then nil
                                          else f
end$

symbolic procedure lderiv2(p,f,vl)$
%  fuehrende Ableitung in LISP-Notation mit Potenz (als dotted pair)
begin scalar l$
l:=ldiffp1(p,f,vl)$
return cons(if car l then cons('DF,cons(f,car l))
                  else if zerop cdr l then nil
                          else f
                ,cdr l)
end$

symbolic procedure highdiff(p,f,x)$
%  hoechste Ableitung einer Funktion f nach der Variable x
%  in einem Ausdruck p
%  p,f in LISP-Notation, x Atom
diffdeg(car ldiffp1(p,f,list x),x)$

symbolic procedure minausd(p,q)$
%   minimalen Differentialausdruck suchen$
%   p,q, Ausdr. in Listenform mit fuehrender Ableitung + Potenz
%   zur Berechnung wird nur fuehrender Ableitung + Potenz benutzt
if minausdp1(cadr p,cddr p,cadr q,cddr q) then p
                                          else q$

symbolic procedure minausdsp(p,q)$
%   falls p minimaler Diff.ausdr. und p nicht laenger als q, p sonst nil
%   p,q, Ausdr. in Listenform mit fuerender Ableitung und Potenz
%   benutzt wird nur fuerende Ableitung und Potenz
begin scalar s$
s:=minausdp1(cadr p,cddr p,cadr q,cddr q)$
return if s then if s='EQUAL!= then     %  falls die Ausdruecke gleich
                                        %  schwierig sind,
                if shorter(car p,car q) then p
                                        else nil
                                        %  geht auch die Laenge ein
                else p
        else nil
end$

symbolic procedure minausdp(p,q)$
%   falls p minimaler Differentialausdruck, p sonst nil
%   p,q, Ausdr. in Listenform mit fuehrender Ableitung und Potenz
%   benutzt wird nur fuerende Ableitung und Potenz
begin scalar j,k$
return if minausdp1(cadr p,cddr p,cadr q,cddr q) then p
                                          else nil$
end$

symbolic procedure minausdp1(l1,p1,l2,p2)$
%  liefert t, wenn der erste von zwei Differentialausdr. echt einfacher,
%  'EQUAL!=, wenn sie gleich schwierig sind, sonst nil
%  l1,l2 Listen der Ordnungen der Ableit., p1,p2 Potenzen
if null l1 then                 %  Ordnungen gleich ?
                        if p1=p2 then 'EQUAL!=
                                        %  Potenzen gleich ?
                                else p1<p2
        else if null l2 then nil        %  darf eigentlich nicht sein
        else if car l1<car l2 then t    %  Ordn. der 1. Var. kleiner ?
                else if car l1>car l2 then nil
                                        %  Ordn. der 1. Var. groeaer ?
                        else minausdp1(cdr l1,p1,cdr l2,p2)$
                                        %  restliche Variable testen


symbolic procedure difdiff(r,s)$
%   liefert Liste der Differenzen der Elemente zweier Listen
if null r then nil
else cons (car r-car s,difdiff(cdr r,cdr s))$

symbolic procedure mkldiff(f,l)$
%   erzeugt die Ableitung der Funktion f nach
%   den Variablen (einschliesslich Ordnungen) aus der Liste l
cons('DF,cons(f,difflist(fctargs f,l)))$

symbolic procedure difflist(v,l)$
%   erzeugt aus der Liste der Variablen und der Liste der Ordnungen der
%   Ableitungen eine Liste von Variablen + Ordnungen
if null v then nil
else if car l=0 then difflist(cdr v,cdr l)
                                        %  Ordnung 0
        else if car l=1 then cons(car v,difflist(cdr v,cdr l))
                                        %  bei Ordnung 1 wird Variable
                                        %  ohne Ordnung angehaengt
                else cons(car v,cons(car l,difflist(cdr v,cdr l)))$

symbolic procedure delength(d)$
%   Laenge eines Polynoms in LISP - Notation
if not pairp d then if d then 1
                         else 0
else
if car d='PLUS then length(d)-1         %  Laenge in LISP ohne PLUS
else if car d='EQUAL then delength(cadr d)+delength(caddr d)
else if car d='QUOTIENT then delength(cadr d)
else 1$

symbolic procedure shorter(a,b)$
delength a<=delength b$

symbolic procedure desort(l)$
% list sorting
begin scalar l1,l2,l3,m,n$
return
if null l then nil
else
<<n:=delength car l$
  l2:=list car l$
  l:=cdr l$
  while l do
   <<m:=delength car l$
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2)$
   l:=cdr l>>$
  append(desort(l1),append(l2,desort(l3)))>>
end$

symbolic procedure smemberl(fl,ex)$
if fl and ex then
if smember(car fl,ex) then cons(car fl,smemberl(cdr fl,ex))
                       else smemberl(cdr fl,ex)$

symbolic procedure fctsort(l)$
% list sorting
begin scalar l1,l2,l3,m,n$
return
if null l then nil
else
<<n:=fctlength car l$
  l2:=list car l$
  l:=cdr l$
  while l do
   <<m:=fctlength car l$
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2)$
   l:=cdr l>>$
  append(fctsort(l1),append(l2,fctsort(l3)))>>
end$

symbolic procedure fctprint(fl)$
%   Ausdrucken der Funktionen aus fl
begin scalar n,l$
n:=0$
for each f in fl do
   if pairp f then
      if car f='EQUAL then
        <<n:=delength reval f$
        if n>print_ then
        <<terpri()$write cadr f,"= expr. with ",n," terms"$terpri()>>
        else mathprint f$
        n:=0>>
      else
         <<if n eq 5 then
              <<terpri()$n:=0>>$
         write car f$
         if pairp cdr f then
            <<write "("$write cadr f$
            for each v in cddr f do
               <<write ","$write v>>$
            write ")  ">>
         else
            <<write car f$
            write "  ">>$
         n:=add1 n>>
   else
       <<if n eq 5 then
            <<terpri()$n:=0>>$
       write f$
       if (l:=fctargs f) then
         <<write "("$write car l$
         for each v in cdr l do write ",",v$
         write ")">>$
       write "  "$
       n:=add1 n>>$
%if n neq 0 then terpri()
end$

symbolic procedure eqprint(e)$
%   Ausdrucken der Gl. e
if print_ then
 begin scalar n$
 n:=delength reval e$
 if n>print_ then
        <<write "expr. with "$write n$write " terms"$terpri()>>
 else
        mathprint e$
end$

symbolic procedure substprint(a,b)$
if print_ then
begin scalar n$
 n:=delength reval b$
 if n>print_ then <<fctprint list a$write "=  expr. with ",n," terms"$
                    terpri()>>
             else mathprint list('EQUAL,a,b)
end$

symbolic procedure deprint(l)$
%   Ausdrucken der Gl. aus der Liste l
if l and print_ then for each x in l do eqprint(list('EQUAL,0,x))$

symbolic procedure powappend(l,f)$
%   Anhaengen der fuehrenden Ableitung
if null l then nil
else cons(cons(car l,ldiff(car l,f)),powappend(cdr l,f))$

symbolic procedure powdelete(l)$
%   Loeschen der fuehrenden Ableitung
if null l then nil
else cons(caar l,powdelete(cdr l))$

symbolic procedure fctdepend(e,v,fctset)$
%   Test,ob variable v im Ausdruck e nicht in Abhaeng. von
%   Fkt. aus fctset vorkommt
if member(v,argset smemberl(fctset,e)) then t
                                     else freeof(e,v) $

symbolic procedure subset(a,b)$
%   test,ob a Teilmenge von b ist
if null a then t
else if member(car a,b) then subset(cdr a,b)
        else nil$

symbolic procedure idlist(l)$
if pairp l then union(idlist car l,idlist cdr l)
else if l and idp l then list l
else nil$

symbolic procedure varapp(l,a,v1,v2)$
%   an jede Gl. aus l werden v1 und v2 angehaengt
if null l then nil
else
cons(list(cons(cons(caar l,a),cdar l),v1,v2),varapp(cdr l,a,v1,v2))$

symbolic procedure varslist(p,ftem,vl)$
begin scalar l$
ftem:=argset smemberl(ftem,p)$
for each v in vl do
  if not freeof(p,v) or member(v,ftem) then l:=cons(v,l)$
return reverse l$
end$

symbolic procedure newfct(id,l,nfct)$
begin scalar f$
f:=mkid(id,nfct)$
depl!*:=delete(assoc(f,depl!*),depl!*)$
%put(f,'simpfn,'simpiden)$
%if pairp l then f:=cons(f,l)$
if pairp l then depl!*:=cons(cons(f,l),depl!*)$
if print_ then
   <<terpri()$
   if pairp l then
     <<write "new function: "$
     fctprint list f>>
   else
     write "new constant: ",f>>$
return f$
end$

symbolic procedure equallist(forg)$
% List of all members of forg which are pairs
if forg then
   if pairp car forg then cons(car forg,equallist cdr forg)
                     else equallist cdr forg$

symbolic procedure spmin(a,b)$
if null a then b
        else if null b then a
                else if cadr a<cadr b then a
                        else b$

symbolic procedure specons(a,l)$
if freeof(l,car a) then cons(car a,cons(cadr a,l))
else specons1(a,l)$

symbolic procedure specons1(a,l)$
if null l then nil
else if car l=car a then
        if cadr l<cadr a then cons(car a,cons(cadr a,cddr l))
                else l
        else cons(car l,cons(cadr l,specons1(a,cddr l)))$

symbolic procedure polyp(p,ftem)$
begin scalar a$
a:=t$
while ftem do
   if polyp1(p,car ftem) then ftem:=cdr ftem
   else
       <<terpri()$
       write "***** This equation is not a polynomial w.r.t. "$
       write car ftem$write " and its derivatives : "$
       deprint(list p)$
       ftem:=nil$
       a:=nil>>$
return a
end$

symbolic procedure polyp1(p,f)$
%  prueft, ob p f nur in polynomialer Form enthaelt
if freeof(p,f) then t
else
begin scalar a$
if atom p then a:=t
else
if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,'QUOTIENT,'DF)) then
                                        %  erlaubte Funktionen
        <<if (car p='PLUS) or (car p='TIMES) then
                <<p:=cdr p$
                while p do
                    if a:=polyp1(car p,f) then p:=cdr p
                                         else p:=nil>>
        else if (car p='MINUS) then
                a:=polyp1(cadr p,f)
        else if (car p='QUOTIENT) then
                <<if freeof(caddr p,f) then a:=polyp1(cadr p,f)>>
        else if car p='EXPT then        %  Exponent
                <<if (fixp caddr p) then
                   if caddr p>0 then a:=polyp1(cadr p,f)>>
        else if car p='DF then          %  Ableitung
                if (cadr p=f) or freeof(cadr p,f) then a:=t>>
else a:=(p=f)$
return a
end$

symbolic operator rationalexp$
symbolic procedure rationalexp(p,ftem)$
ratexp(p,cdr ftem)$

lisp flag('(rationalexp),'BOOLEAN)$

symbolic procedure ratexp(p,ftem)$
if null ftem then t
             else if ratexp1(p,car ftem) then ratexp(p,cdr ftem)
                                         else nil$

symbolic procedure ratexp1(p,f)$
%  prueft, ob p f nur in rationaler Form enthaelt
if not pairp p or freeof(p,f) then t
else if car p='QUOTIENT then polyp1(cadr p,f) and polyp1(caddr p,f)
else polyp1(p,f)$

%symbolic procedure freeof(u,v)$
%not(smember(v,u)) and freeofdepl(depl!*,u,v)$

symbolic procedure freeofdepl(de,u,v)$
if null de then t
else if smember(v,cdar de) and smember(caar de,u) then nil
else freeofdepl(cdr de,u,v)$

symbolic procedure freeoflist(l,m)$
%   liefert t, falls kein Element aus m in l auftritt
if null m then t
else if freeof(l,car m) then freeoflist(l,cdr m)
                        else nil$

endmodule$

%********************************************************************
module dfint;         % Patch to improve symbolic differentiation,
                      % mainly of integrals.

% Author: Francis J. Wright <F.J.Wright@QMW.ac.uk>
%       QMW, London and CBPF, Rio.
% Date: Thu Nov 19 21:11:12 1992
% REDUCE version: 3.4.1 (ONLY); PSL

% Beta test version

% 19 June 1992: Preliminary alpha test version (for CRACK)
% 28 Oct  1992: !*k2q -> !*kk2q to avoid non-unique kernels
%     But maybe it should be done as in diffp instead?
%  7 Nov 1992: Allowdfint mode added; completely revised REDUCE 3.4.1
%     version

% DOCUMENTATION
% =============
% This patch has several functions: for examples see the test and
% demonstration file DFINT.TST.

% Let A, B, C, D be arbitrary SEQUENCES of kernels.

% 1.  REDUCE commutes the order of differentiations so as to collect
% differentiation variables, but it misses the commutation that would
% simplify any expression equivalent to df(y, A, y, B) to zero (unless
% A is absent).        A one-line patch to procedure diffp (below) fixes
% this.        This simplification must surely ALWAYS be correct and
% desirable (since REDUCE commutes differentiations), and is very
% cheap to include, so it is ALWAYS performed.

% 2.  However, the main purpose of this patch is to differentiate
% integrals (hence the name DFINT) in a controlled manner.  This is
% implemented for single derivatives and differentiation wrt the first
% variable in multiple derivatives via the new main procedure
% dfform_int, together with a patch to the existing procedure diffp
% (below) to deal with differentiation wrt later variables in multiple
% derivatives.

% It is not possible in general in REDUCE to perform any of these
% simplifications by pattern matching because of the arbitrary number
% of arguments.        In particular, this patch makes redundant the
% following specific rule defined in INT.RED:
% put('df,'opmtch,'(((int !=y !=x) !=x) (nil . t) (evl!* !=y) nil) .
% get('df,'opmtch));
% This is equivalent (but NOT identical) to the algebraic command
% for all y,x let df(int(y,x), x) = y;
% which could therefore be cleared - see DFINT.TST.  However, leaving
% it effective should not matter.  The code here to replace this rule
% is not NECESSARY, but seems desirable since the code has to check
% for differentiation of an integral anyway.

% The precise operation of the new facility to differentiate integrals
% is as follows:

% (a).        Differentiation wrt the integration variable:

% df(int(F(A,x,B),x),C,x,D), or any equivalent composition of
% derivatives applied to one integral, is ALWAYS simplified to
% df(F(A,x,B),C,D).

% (b).        Differentiation wrt a parameter of the integrand:

% If the switch ALLOWDFINT is turned on (it is ON by default) then "df
% int" will be commuted into "int df" IF THIS SIMPLIFIES THE
% INTEGRAND, meaning currently that the new integrand is not a
% symbolic derivative.        Thus differentiation under the integral sign
% will be performed so that df(int(F(A,x,B),x),C,y,D) simplifies to
% df(int(F_y(A,x,B),x),C,D) if F_y = dF/dy simplifies.        It think this
% is normally desirable.

% If the switch DFINT is turned on (it is OFF by default) then the
% commutation is ALWAYS performed.  Thus df(int(F(A,x,B),x),C,y,D)
% ALWAYS evaluates to int(df(F(A,x,B),C,y,D),x).  I think this will
% not normally be desirable, although for special purposes it is.

% If used together with either Herbert Melenk's patch or mine (called
% intpatch) that allow integrands to be implicitly dependent on the
% integration variable, this code is intended to also work with such
% dependent integrands, rather than only with explicit operators as
% illustrated above.  For examples see the end of the test and
% demonstration file DFINT.TST.


% This file is intended to be compiled using faslout and then loaded
% using load_package, but alternatively the source code can be input
% when required and either compiled or interpreted.  It could also be
% edited into the standard source file POLY.RED and built permanently
% into REDUCE.

% ** WARNING ** To use this patch with REDUCE 3.4 the new procedures
% called by diffp in 3.4.1 need to be supplied, or the end of diffp
% changed back to its 3.4 form.


switch allowdfint, dfint;     % dfint OFF by default
deflist('((allowdfint ((t (rmsubs)))) (dfint ((t (rmsubs))))), 'simpfg);
   % There is no code to reverse the df-int commutation,
   % so no reason to call rmsubs when the switch is turned off.
% on allowdfint;  % But would be done when INput rather than LOADed!
!*allowdfint := t;  rmsubs(); % allowdfint ON by default
!*dfint:=t;
put('int, 'dfform, 'dfform_int);

% dfform is a new hook, otherwise used only by taylor (I think).
% This code does not necessarily need to use this hook,
% but it needs to be called as an alternative to diffp so
% that the linearity of differentiation has already been applied.

symbolic procedure dfform_int(u, v, n);
   % Simplify a SINGLE derivative of an integral.
   % u = '(int y x) [as main variable of SQ form]
   % v = kernel
   % n = integer power
   % Return SQ form of df(u**n, v) = n*u**(n-1)*df(u, v)
   % This routine is called by diffp via the hook
   % if x := get(car u,'dfform) then return apply3(x,u,v,n)
   begin scalar result, x, y;
      y := simp!* cadr u;  % SQ form integrand
      x := caddr u;  % kernel
      result :=
      if v eq x then y
       % df(int(y,x), x) -> y  replacing the let rule in INT.RED
      else if (!*allowdfint or !*dfint) and << y := diffsq(y, v);
          !*dfint or not_df_p y  % it has simplified
       >> then simp{'int, mk!*sq y, x}  % MUST re-simplify it!!!
       % i.e. differentiate under the integral sign
       % df(int(y, x), v) -> int(df(y, v), x).
         % (Perhaps I should use prepsq - kernels are normally
         % true prefix?)
      else !*kk2q{'df, u, v};  % remain unchanged
      if not(n eq 1) then
       result := multsq( (((u .** (n-1)) .* n) .+ nil) ./ 1, result);
      return result
   end;

symbolic procedure not_df_p y;
   % True if the SQ form y is not a df kernel.
   not(denr y eq 1 and
       not domainp (y := numr y) and eqcar(mvar y, 'df));


% Author: Anthony C. Hearn.
% Copyright (c) 1991 RAND.  All rights reserved.
% Modifications by Francis J. Wright, QMW, London and CBPF, Rio
% (clearly flagged -- search for FJW).

% This procedure is from the REDUCE 3.4.1 module poly in file POLY.RED
% and is a little different from the 3.4 version!  It needs a minor
% addition to improve the simplification of MULTIPLE derivatives.
% Note that in PSL-REDUCE POLY is compiled into the base system, so
% this procedure is always defined and can safely be re-defined.
% Under other Lisps this may not be true, so BEWARE!!!

symbolic procedure diffp(u,v);
   % U is a standard power, V a kernel.
   % Value is the standard quotient derivative of U wrt V.
   begin scalar n,w,x,y,z; integer m;
      n := cdr u;     % integer power.
      u := car u;     % main variable.
      if u eq v and (w := 1 ./ 1) then go to e
       else if atom u then go to f
       %else if (x := assoc(u,dsubl!*)) and (x := atsoc(v,cdr x))
%             and (w := cdr x) then go to e   % deriv known.
           % DSUBL!* not used for now.
       else if (not atom car u and (w:= difff(u,v)))
                or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
        then go to c  % extended kernel found.
       else if x := get(car u,'dfform) then return apply3(x,u,v,n)
       else if x:= get(car u,'dfn) then nil
       else if car u eq 'plus and (w := diffsq(simp u,v))
        then go to c
       else go to h;  % unknown derivative.
      y := x;
      z := cdr u;
    a:        w := diffsq(simp car z,v) . w;
      if caar w and null car y then go to h;  % unknown deriv.
      y := cdr y;
      z := cdr z;
      if z and y then go to a
       else if z or y then go to h;  % arguments do not match.
      y := reverse w;
      z := cdr u;
      w := nil ./ 1;
    b:        % computation of kernel derivative.
      if caar y
        then w := addsq(multsq(car y,simp subla(pair(caar x,z),
                                                 cdar x)),
                        w);
      x := cdr x;
      y := cdr y;
      if y then go to b;
    c:        % save calculated deriv in case it is used again.
      % if x := atsoc(u,dsubl!*) then go to d
      %  else x := u . nil;
      % dsubl!* := x . dsubl!*;
  % d:         rplacd(x,xadd(v . w,cdr x,t));
    e:        % allowance for power.
      % first check to see if kernel has weight.
      if (x := atsoc(u,wtl!*))
        then w := multpq('k!* .** (-cdr x),w);
      m := n-1;
      % Evaluation is far more efficient if results are rationalized.
      return rationalizesq if n=1 then w
              else if flagp(dmode!*,'convert)
                   and null(n := int!-equiv!-chk
                                         apply1(get(dmode!*,'i2d),n))
               then nil ./ 1
              else multsq(!*t2q((u .** m) .* n),w);
    f:        % Check for possible unused substitution rule.
      if not depends(u,v)
         and (not (x:= atsoc(u,powlis!*))
               or not depends(cadddr x,v))
        then return nil ./ 1;
      w := list('df,u,v);
      go to j;
    h:        % Final check for possible kernel deriv.
      if car u eq 'df
        then if depends(cadr u,v)
%% BEGIN addition to 3.4.1 version by FJW
                      and not(cadr u eq v) then
                      % (df (df v A) v) ==> 0
      << if eqcar(cadr u, 'int) then
            % (df (df (int F x) A) v) ==> (df (df (int F x) v) A) ?
            % Commute the derivatives to differentiate the integral?
            if caddr cadr u eq v then
               % Evaluating (df u v) where u = (df (int F v) A)
               % Just return (df F A) - derivative absorbed
               << w := 'df . cadr cadr u . cddr u;  go to j >>
            else if !*allowdfint and
               % Evaluating (df u v) where u = (df (int F x) A)
               % Commute only if the result simplifies:
               not_df_p(w := diffsq(simp!* cadr cadr u, v))
              then <<
                 % Generally must re-evaluate the integral (carefully!)
               w := aeval{'int, mk!*sq w, caddr cadr u} . cddr u;
               go to j >>;  % derivative absorbed
%% END addition to 3.4.1 version by FJW
%% BEGIN difference from 3.4
                    if (x := find_sub_df(w:= cadr u . derad(v,cddr u),
                                         get('df,'kvalue)))
                        then <<w := simp car x;
                               for each el in cdr x do
                                  for i := 1:cdr el do
                                      w := diffsq(w,car el);
                               go to e>>
                     else w := 'df . w
%% END difference from 3.4
              >> %FJW
              else return nil ./ 1
       else if depends(u,v) then w := list('df,u,v)
       else return nil ./ 1;
    j:        w := if x := opmtch w then simp x else mksq(w,1);
      go to e
   end;

endmodule;

module intpatch;  % Integrate dependent variables & rational powers

% Author: Francis J. Wright <F.J.Wright@QMW.ac.uk>
% Date: 19 June 1992  (Very minor update 16/11/92)
% REDUCE version: 3.4 or 3.4.1; PSL

% This version (19 June 1992) fixes a bug that integrals that remained
% symbolic were not returned as unique kernels - I now use !*kk2q.
% This bug caused rather obscure symptoms, such as failures with on
% factor.

% DOCUMENTATION
% =============
% This patch has two separate functions:

% 1: It allow integrals containing IMPLICITLY dependent variables,
% created using the DEPEND command, to remain symbolic rather than
% cause an error, whilst preserving other error handling as normal.
% ON FAILHARD turns this facility off.
% This facility was developed from a patch by Herbert Melenk,
% which this patch is intended to replace.

% 2: It integrates simple rational powers of the integration
% variable that the integrator currently fails to integrate.


% This file is intended to be compiled using faslout and then loaded
% using load_package, but alternatively the source code can be input
% when required and either compiled or interpreted.  It could also be
% edited into the standard source file INT.RED and built permanently
% into REDUCE.

% Because of the autoload definitions for int (see ENTRY.RED) it is
% safe to load this module before the integrator has been loaded, and
% it does not cause the integrator to load.  The integrator can safely
% be AUTOLOADED by calling INT afterwards, either from algebraic mode
% or from symbolic mode using any of the methods described below, but
% MUST NOT BE EXPLICITLY LOADED AFTER this patch, otherwise this patch
% will not work because the simpfn property of int will get
% overwritten.        I cannot see any solution to this, other than avoiding
% doing it!

% WARNING: To call the integrator from symbolic mode when this patch
% is loaded DO NOT CALL SIMPINT DIRECTLY.  Instead, there are several
% possibilities that should work, including any of the following:

% 1.  Use the form ????{'int, integrand, int_var}, where ???? is
% reval, aeval or simp, etc, depending on the form of result you want,
% and the arguments are in prefix (or pseudo-prefix) form.  This is
% equivalent to calling the integrator from algebraic mode, and I
% currently think this is probably the best approach.

% 2.  Call simpintpatch directly, but this is not general and so not
% recommended.

% 3.  Replace calls of "simpint" by (say) "integrator", and do
% essentially the following:
% global'(integration_function);
% symbolic(integration_function := get('int, 'simpfn));
%
% symbolic procedure integrator u;
%    apply1(integration_function, u);
% Note: apply1 is defined in RLISP.RED.


fluid '(!*failhard);

%% fluid '(soft!-rerror!-number);
% Hope not necessary - it seems not to be.


symbolic procedure SimpIntPatch u;
   % Driver for various patches:
   % 1: Catch errors from SimpInt, trap error number 7 only,
   % and pass on all other errors as normal hard REDUCE errors.
   % 2: Post-process unintegrated rational powers.
   begin scalar r, !*usermode,!*redefmsg, !*uncached; !*uncached := t;
      % !*redefmsg rebound to avoid PSL messages
      % about redefinition of rerror.
      %% integer soft!-rerror!-number;          % defaults to 0, not nil
      put('int, 'simpfn, 'SimpInt);     % assumed & reset by SimpInt
      copyd('rerror, 'intpatch!-rerror);  % redefine rerror
      r := errorset!*({'SimpInt, mkquote u}, nil);
      copyd('rerror, 'rerror!%);        % restore rerror
      put('int, 'simpfn, 'SimpIntPatch);  % reset INT interface
      if pairp r then <<
       % First call of SimpInt succeeded -
       % try to reprocess any integrals left:
       put('int, 'simpfn, 'SimpIntRatPow);
       u := resimp car r;  % this works ONLY with !*uncached := t;
       put('int, 'simpfn, 'SimpIntPatch);
       return u
      >>
      else if !*failhard or not(r eq 7) then
       rederr EMSG!*              % Error failure
      else return !*kk2q('int . u)  % Remain symbolic
   end;


% Integrator error trap patch to allow controlled error handling
% ==============================================================

% The error numbers generated by SIMPINT and the corresponding
% error message that would be output by INT are the following,
% collected from the INT source code:

%  1  =        "Improper number of arguments to INT"
%  2  =        "Improper number of arguments to INT"
%  3  =        "Too many arguments to INT"
%  4  =        "FAILHARD switch set"
%  5  =        "Invalid polynomial in int-quadterm"
%  6  =        "Empty list to mapply"
%  7  =        "Can't integrate in the presence of side-relations" (TRAPPED)
%  8  =        "Invalid exponent"
%  9  =        "FAILHARD switch set"

% If any other error number, such as 0, should occur then it
% corresponds to some other non-specific error.


symbolic procedure rerror!%(packagename,number,message);
   % This is precisely the definition of rerror in RLISP.RED,
   % but redefining it here makes sure it is loaded,
   % and also avoids the need to save it.
   % Precisely this procedure is also defined in SOFTSOLV.
   rederr message;

symbolic procedure intpatch!-rerror(packagename,number,message);
   %% << soft!-rerror!-number := number; error1() >>;
   % The following will suffice provided errorsets
   % are not nested in the integrator.
   % It makes error message text available in EMSG!*.
   error(number, message);


% Integrator postprocessor patch to integrate simple rational
% powers that the integrator currently fails to integrate.
% =======================================================

symbolic procedure SimpIntRatPow u;  % u = (integ var)
   % Integrate integrands of the form var**(m/n),
   % which the integrator leaves in a rather bizarre form -
   % hence the precise form of the following code.
   % Returns original integral if it has the wrong form.
   begin scalar integ, var, power;
      integ := car u;  var := cadr u;
       % assumes true prefix forms, already evaluated by SimpInt.
%     power := errorset!*(
%      {'FindRatPow, mkquote integ, mkquote var}, nil);
%     errorset!*(u,v) == errorset(u,v,!*backtrace)
%     Backtrace from this is unlikely to be interesting, so ...
      power := errorset(
       {'FindRatPow, mkquote integ, mkquote var}, nil, nil);
      if errorp power then return !*kk2q('int . u);
      power := car power;  % correct form of integrand found.
      % integrand = var**power, so return integral:
      power := reval {'plus, power, 1};
      return simp!* {'quotient, {'expt, var, power}, power}
   end;

symbolic procedure FindRatPow(monom, var);
   % Return power of a monomial in var, as a
   % rational number in UNSIMPLIFIED prefix form
   % or cause error return to enclosing errorset.
   if eqcar(monom, 'quotient) then
      {'plus, FindRatPow(cadr monom, var),
       {'minus, FindRatPow(caddr monom, var)}}
   else if eqcar(monom, 'times) then
      'plus . for each el in cdr monom collect FindRatPow1(el, var)
   else FindRatPow1(monom, var);

symbolic procedure FindRatPow1(monom, var);
   if monom eq 1 then 0        % only possible constant by linearity
   else if monom = var then 1
   else if eqcar(monom, 'expt) and
      cadr monom = var then caddr monom
   else error1();  % wrong form

endmodule;

load_package int$

% die folgende Aenderung verhindert das Erzeugen von int* ...

remd('simpint!*)$

symbolic procedure simpint!* u$
   begin scalar x;
      return if (x := opmtch('int . u)) then simp x
              else simpiden('int . u)
% statt       else simpiden('int!* . u)
   end$

setcrackflags()$

!*fullroots:=t;

% Zum Integrieren

put('int, 'simpfn, 'SimpIntPatch);
share !*intflag!*;  % True inside integrator.

algebraic let {
 int(1/~x^(~n),~x) => -x/(x^n*(n-1)) when numberp n,
     ~x^(~m/~n)*~x => x**((m+n)/n) when (numberp n and numberp m),
     int(~z/~y,~x) => log(y) when z = df(y,x)};

load_package crack2;

end$
