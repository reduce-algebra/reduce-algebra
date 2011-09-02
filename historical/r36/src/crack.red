module crack;   % Top level CRACK module.

%**********************************************************************
Comment

Title: CRACK
Authors:

        Andreas Brand
        Institut fuer Informatik
        Friedrich Schiller Universitaet Jena
        07740 Jena,  Germany
        email: maa@hpux.rz.uni-jena.de
        tel.:  + 49 3641 630698,

        Thomas Wolf
        School of Mathematical Sciences
        Queen Mary and Westfield College
        University of London
        London E1 4NS
        email: T.Wolf@maths.qmw.ac.uk
        tel.:  + 44 71 975 5493

Date of last change: 1995-03-20

Abstract:
CRACK is a package for solving overdetermined systems of partial or
ordinary differential equations (PDEs, ODEs). Examples of programs
which make use of CRACK for investigating ODEs (finding symmetries,
first integrals, an equivalent Lagrangian or a "differential
factorization") are added. The manual CRACK.TEX gives further details.

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
%   CRACK Version 1995-03-20                                          %
%                                                                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

create!-package('(crack crackstr decouple separate integrat genint
                  intfactr odeint simplf utilts simpsols intfix dfint),
                '(contrib crack));

endmodule;


module crackstr;

%  Author: Andreas Brand
%  1991,1993

symbolic fluid '(reducefunctions_ cont_ odesolve_ fcteval_ print_
         facint_ potint_ safeint_ solvealg_ logoprint_ independence_
         tr_gensep decouple_ tr_genint contradiction_ poly_only fname_
         factorize_ nfct_ fnew_ genint_ gensep_ ineq_ time_ adjust_fnc)$

symbolic operator setcrackflags$
symbolic procedure setcrackflags$
<<reducefunctions_:= '(abs acos acosd acosh acot acotd acoth acsc acscd
                       acsch asec asecd asech asin asind asinh atan
                       atand atanh atan2 atan2d cbrt cos cosd cosh cot
                       cotd coth csc cscd csch exp factorial hypot ln
                       log logb log10 sec secd sech sin sind sinh sqrt
                       tan tand tanh plus difference df minus times
                       quotient expt int)$
if not fixp nfct_ then
nfct_:=1$          %  index of new functions and constants initialized
cont_:=nil$        % if t then the user will be asked if a de
                   % is too long for integration or substitution
independence_:=nil$% if t then the user will be asked whether or not
                   % expr. are considered to be linear independent
genint_:=t$        % generalized integration disabled/enabled
facint_:=nil$      % allowing the search of integrating factors
potint_:=nil$      % allowing `potential integration'
safeint_:=t$       % uses only solns of ODEs with non-vanishing denom.
gensep_:=8$        % max. size of expressions to separate in a
                   % generalized way
factorize_:=5$     % recursion depth for factorizing equations
odesolve_:=100$    % maximal length of a de (number of terms) to be
                   % integrated as ode
fcteval_:=100$     % maximal length of an expression to be substituted
                   % for a function
decouple_:=10$     % max. number of decoupling processes for a function
tr_gensep:=nil$    % Trace generalized separation
tr_genint:=nil$    % Trace generalized integration
solvealg_:=nil$    % Use SOLVE for algebraic equations
fname_:='c$        % name of new functions and constants (integration)
logoprint_:=t$     % print logo for crack call
poly_only:=t$      % all equations are polynomials only
time_:=t$          % print the time needed for running crack
print_:=8$         % maximal length of an expression to be printed
adjust_fnc:=nil>>$ % if t then free constants/functions are scaled and
                   % redundant ones are droped to simplify the result

symbolic operator crackhelp$
symbolic procedure crackhelp$
<<
terpri()$
write "The call:      CRACK({ex1,..,exn},{ineq1,..,ineql},",
      "                     {fct1,..,fctm},{var1,..,vark})"$
terpri()$terpri()$
write "ex1,..,exn     are the equations ex1=0,..,exn=0."$
write "ineq1,..,ineql are the inequalities inequ1<>0,..,ineql<>0"$
write "fct1,..,fctm   are the unknown functions depending on ",
      "arguments"$
terpri()$
write "               declared by DEPEND fcti,...$ ."$terpri()$
write "var1,..,vark   are further independent free variables which"$
terpri()$
write "               none of the fcti depends on."$terpri()$terpri()$
write "The Return:    {res1,...,resr},  each resi representing a",
      " solution of the form"$terpri()$
write "resi = {list_remain_ness_and_suff_conditions, ",
      "list_solved_functions,"$
terpri()$
write "        list_free_or_unsolved_functions, list_inequalities}"$
terpri()$
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
write "This helptext can be recalled by: CRACKHELP()"$terpri()$
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
"DECOUPLE_ (10):      maximal number of decoupling attempts ",
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
"GENINT_ (T):         generalized integration disabled/enabled"$
terpri()$write
"GENSEP_ (8):         maximal length of an expression for doing a",
"generalized"$
terpri()$write
"                     separation"$
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
"FACINT_ (nil):       allowing the search for integrating factors"$
terpri()$write
"PRINT_ (8):          maximal length of an expression to be printed"$
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
terpri()$write
"ADJUST_FNC (nil):    simplification of result by droping redundant ",
"free "$
terpri()$write
"                     functions and constants or rescaling them"$
terpri()$
>>$


symbolic operator crack$
symbolic procedure crack(el,il,fl,vl)$
% Main procedure
%     el - list of PDEs , il - list of nonvanishing expr.
%     fl - list of functions, vl - list of variables
begin scalar l,l1,l2,n,m,ezgcdold,mcdold,gcdold,expold,ratold,
             ratargold,failure$
      scalar !*precise;
if print_ and logoprint_ then
<<
"**************************************************************",
"************"$
terpri()$
write
"This is CRACK - a solver for overdetermined partial differential ",
"equations"$
terpri()$
write "Version 1995-03-20"$terpri()$
write
"***************************************************************",
"***********"$
terpri()$
>>$
if el then
if pairp el and (car el='list) then el:=cdr el
                               else el:=list el$
if fl then
if pairp fl and (car fl='list) then fl:=cdr fl
                               else fl:=list fl$
if il then
if pairp il and (car il='list) then il:=cdr il
                               else il:=list il$
if vl then
if pairp vl and (car vl='list) then vl:=cdr vl
                               else vl:=list vl$
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
vl:=union(reverse argset fl,vl)$
%    if print_ then
%     <<terpri()$write "CRACK is called with :"$terpri()$
%     terpri()$write "equations : "$deprint el$terpri()$
%     terpri()$write "functions : "$fctprint fl$terpri()$
%     terpri()$write "variables : "$fctprint vl$terpri()>>$
n:=time()$
m:=gctime()$
l1:=el$
if poly_only then
 while l1 do
  if rationaltest(car l1,fl) then l1:=cdr l1
                             else <<failure:=t$l1:=nil>>$
if not failure then
<<l:=union(crack1(el,nil,il,fl,vl,factorize_,nil,nil),nil)$
  if !*time or time_ then
  <<terpri()$write "CRACK needed :  ",time()-n," ms    GC time : ",
                    gctime()-m," ms">>$
  l:=for each a in l collect
       <<l1:=nil$
       l2:=caddr a$
       for each b in cadr a do
        if (pairp b) and (car b = 'equal) then l1:=cons(b,l1)
                                          else l2:=cons(b,l2)$
       list(car a,l1,l2,cadddr a)>>$
  if adjust_fnc then
     l:=for each a in l collect if l1:=dropredund(a,vl) then cdr l1
                                                        else a>>
else l:=nil$
!*ezgcd:=ezgcdold$
!*gcd:=gcdold$
!*exp:=expold$
!*mcd:=mcdold$
!*rational:=ratold$
!*ratarg:=ratargold$
return if l then
       cons('list,for each a in l collect
                      list('list,cons('list,car a),
                                                cons('list,cadr a),
                                                cons('list,caddr a),
                                                cons('list,cadddr a)))
       else list('list)
end$

symbolic procedure crack1(ss,sf,ineq,forg,vl,fact,level,ass)$
%   Main program
begin scalar q,p,s,ftem,fges,ls,ls1,lf,l,l1,se,decfl$
contradiction_:=nil$
ineq_:=ineq$
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
 while not contradiction_ and (l or ss) do
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
     contradiction(car ls,fges)>>$
   while not contradiction_ and sf do
   <<s:=car sf$
     sf:=cdr sf$
     if my_freeof(s,cdr p) then lf:=cons(s,lf)
     else
     <<ls:=cons(reval subst(car p,cdr p,s),ls)$
       contradiction(car ls,fges)>> >>$
   if not contradiction_ then
   <<for each s in se do
      if my_freeof(s,cdr p) then l1:=cons(s,l1)$
     se:=reverse l1$
     ss:=desort delete(0,union(ls,nil))$
     sf:=desort delete(0,union(lf,nil))$
     forg:=fctsubst(car p,cdr p,forg)$
     if print_ then fctprint(forg);
     ftem:=delete(cdr p,ftem)$
     fges:=delete(cdr p,fges)>>$
  >>$               % alle Fkt. subst.
  ls:=ss$
  l:=nil$
  while not contradiction_ and ls do
   <<q:=car ls$
   ls:=cdr ls$
   ss:=delete(q,ss)$
   if pairp q then
    <<l1:=desort gensep(q,smemberl(union(fnew_,ftem),q),vl)$
    if not contradiction_ then
      <<sf:=union(reverse l1,sf)$
      ftem:=union(fnew_,smemberl(ftem,append(sf,ss)))$
      fges:=union(fnew_,smemberl(fges,append(sf,ss)))$
      for each p in l1 do
       if member(p,ftem) then l:=union(list cons(0,p),l)
                         else se:=cons(p,se)$
      if l then ls:=nil>> >>
   else se:=cons(q,se)$
   se:=desort union(se,nil)$
   ls1:=se$
   if not contradiction_ then
    <<while ls1 and not l do
       <<if q:=fctevalstrict(car ls1,ftem,vl) then
          <<l:=union(list q,l)$
          ls:=nil>>$
         ls1:=cdr ls1>>$
    while se and not l do
     <<if q:=fcteval(car se,ftem,vl) then
      <<l:=union(list q,l)$
      ls:=nil>>$
     se:=cdr se>> >>
   >>$
  if not contradiction_ then
    <<ls1:=se$
    while ls1 and not l do
     <<if q:=fctevalstrict(car ls1,ftem,vl) then l:=union(list q,l)$
     ls1:=cdr ls1>>$
    while se and not l do
     <<if q:=fcteval(car se,ftem,vl) then l:=union(list q,l)$
     se:=cdr se>>
    >>
  >>$
if contradiction_ then return nil$
if fact and (fact>0) then
  q:=splitandcrack(sf,ineq_,forg,ftem,vl,fact,level,ass)
else q:=nil$
if contradiction_ then return nil$
decfl:=makedecfl(fges,decfl)$
if q then p:=nil
else                               %    decoupling process starts
if (p:=decouple(sf,forg,ftem,fges,vl,decfl)) then
     if setdiff(car p,sf) or setdiff(sf,car p) or (cadr p) then
       <<sf:=car p$
       ss:=cadr p$
       forg:=caddr p$
       fges:=cadddr p$
       decfl:=car cddddr p$
       goto rep>>$
if contradiction_ then return nil$
if not q then
   <<q:=list list(
          sf,
          forg,
          smemberl(setdiff(fges,forg),
              append(sf,for each l in equallist forg collect cddr l)),
          ineq_)$
   if print_ then resout(car q)>>$
ineq_:=ineq$
return q
end$         % of crack1

symbolic procedure ineqsubst(p,ftem)$
% tests all q's in ineq_ for subst(car p, cdr p,q)=0
% result: nil, if 0 occurs
%         otherwise list of the subst(car p,...)
begin scalar l,a$
while ineq_ do
 if not my_freeof(car ineq_,cdr p) then
 <<a:=reval subst(car p, cdr p,car ineq_)$
   if zerop a then
   <<if print_ then
     <<terpri()$write "contradiction :"$
       eqprint list('equal,cdr p,car p)$
       write "because of non-vanishing expression:"$
       deprint list car ineq_>>$
     contradiction_:=t$
     l:=nil$
     ineq_:=nil>>
   else
   <<if pairp a and (car a='quotient) then a:=cadr a$
     a:=cdr reval list('factorize,a)$
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
   <<contradiction_:=t$
   if print_ then
     <<terpri()$write "non-zero expression vanishes : "$
   deprint list s>>$
   t>>
  else nil
else
<<contradiction_:=t$
if print_ then
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

symbolic procedure resout(reslist)$
%  print results
%   reslist=list(sorg,forg,fnew,ineq)
begin scalar l,fnew$
fnew:=caddr reslist$
if print_ then
   <<for each a in cadr reslist do
      if (pairp a) and (car a='equal) then l:=cons(a,l)
                                      else fnew:=cons(a,fnew)$
   terpri()$write "End of this CRACK run"$terpri()$terpri()$
   write "The solution : "$
   if l then
      fctprint l$
   if car reslist then
      <<write "Remaining conditions : "$
      deprint car reslist$
      if fnew then
         <<write "for the functions : "$fctprint fnew>> >>
   else if fnew then
      <<write "Free functions or constants : "$fctprint fnew>>$
   if cadddr reslist then
      <<terpri()$write "Non-vanishing expressions: "$
      for each a in cadddr reslist do eqprint a>>$
   terpri()$
   write
   "*************************************************************",
   "*************"$terpri()$terpri()>>$
end$

symbolic procedure splitandcrack(sorg,ineq,forg,ftem,vl,fact,level,ass)$
%  If possible one de form sorg is factoirized and
%  crack1 is called with each factor instead
begin scalar l,p,q,a,n,contrad$
l:=sorg$
while l do
   if (p:=splitde(car l,ftem)) then    %  factorizing a de
      <<a:=car l$
        contrad:=t$
        if print_ then
           <<terpri()$
           write "factorizing "$deprint(list a)$
           if length p>1 then write "we get the alternative equations: "
                         else write "we get the equation : "$
           deprint(p)>>$
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
       l:=crack1(list(d),delete(a,sorg),ineq,
                 union(forg,smemberl(ftem,sorg)),
                 vl, if fact<2 then nil else fact-1,level,ass)$
       ineq:=union(list d,ineq)$
       if not contradiction_ then contrad:=nil$
       ass:=cdr ass$
       level:=cdr level$
       if l then q:=union(clearphantomfct(l,forg),q)>> >>$
                                       %  crack1 is called
contradiction_:=contrad$
return q
end$

symbolic procedure clearphantomfct(l,forg)$
% functions from higher level ftem beeing removed from forg
for each a in l collect clrphfct(a,forg)$

symbolic procedure clrphfct(a,forg)$
begin scalar l,l1,fl$
if a then
  <<for each f in forg do
     if (pairp f) and (car f='equal) then fl:=cons(cadr f,fl)
        else fl:=cons(f,fl)$           % List of functions in forg
  for each f in cadr a do
     if (pairp f) and (car f='equal) then
        (if member(cadr f,fl) then l:=cons(f,l)) % Member of forg
     else l1:=cons(f,l1)$              % free or unknown function
  l1:=smemberl(l1,append(car a,append(fl,l)))$
                                       % occuring in forg or sorg
  return list(car a,l,union(l1,caddr a),cadddr a)>>
end$

endmodule;


module decouple;  % Routines for decoupling de's.

%  Author: Andreas Brand
%  August 1991

symbolic procedure eqderiv(p,f,vl)$
%   yields a list of de's by differentiating p w.r.t all those
%   variables from vl on which f not depends
begin scalar l$
vl:=setdiff(vl,fctargs f)$           % variables on which f not depends
for each v in vl do
    if not my_freeof(p,v) then l:=cons(reval list('df,p,v),l)$
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
     q:=reval list('df,q,x,list('minus,m))$
     li:=cons(list(cons(q,ldiff(q,f)),not flag),li)>>
else if 0<m then                       %  first de to be differentiated
   <<if not p then p:=car nexteq(dl,flag)$
     p:=reval list('df,p,x,m)$
     li:=cons(list(cons(p,ldiff(p,f)),flag),li)>> >>$
return li$
end$

symbolic procedure fctchoose(stem,fl)$
%   finds function from fl with the maximal number of arguments
if null (fl:=smemberl(fl,stem)) then nil
else begin
     scalar s,n,m,ma$
     ma:=length argset fl$
     s:=car fl$
     n:=fctlength s$
     fl:=cdr fl$
     while fl and (n<ma) do
       <<m:=fctlength car fl$
       if m>n then
          <<s:=car fl$n:=m>>$
       fl:=cdr fl>>$
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
else if my_freeof(caar gl,f) then shortdesearch(cdr gl,f)
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
if my_freeof(caar gl,f) or minausdp(car gl,g) then secondde1(cdr gl,g,f)
                                    %  Gl., die f nicht enthalten oder
                                    %  schwieriger als g sind, nicht
        else shortde(car gl,secondde1(cdr gl,g,f))$
                                    %  die kuerzere aus der 1. Gl. und
                                    %  der kuerzesten des Rests

symbolic procedure decouple(sorg,forg,ftem,fges,vl,decfl)$
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
for each f in ftem1 do
    if (a:=assoc(f,decfl)) and not zerop cdr a then
       ftem2:=cons(f,ftem2)$
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
else if (f:=fctchoose (stem,ftem2)) then
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
           if pairp s and (car s='quotient) then s:=cadr s$
           r:=car nexteq(l1,nil)$
           if pairp r and (car r='quotient) then r:=cadr r$
           s:=reval !*q2a simpresultant list(s,r,h)$  %  alg. decoupl.
           s:=car simplifyde(s,ftem1,vl,nil)$
           ftem1:=union(fnew_,ftem1)$
           if contradiction_ then
           <<stem:=nil$
             stop2:=t$
             stop3:=t$
             fl:=nil>>
           else
           <<fges:=union(fnew_,fges)$
             if my_freeof(s,f) and
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
                    if my_freeof(a,cdr q) then l:=cons(a,l)
                    else
                       <<ss:=cons(reval subst(car q,cdr q,a),ss)$
                       if contradiction(car ss,ftem1) then
                          <<sorg:=nil$
                          fl:=nil>>
                       >>
                    >>$
                  if not contradiction_ then
                    <<sorg:=desort reverse l$
                    ss:=desort delete(0,union(ss,nil))$
                    forg:=fctsubst(car q,cdr q,forg);
                    if print_ then fctprint(forg)>>$
                  stop3:=t$
                  stop2:=t
                  >>
               else
                  <<stem:=powdelete(stem)$
                  stem:=substandsep(q,stem,ftem1,vl)$
                  if not contradiction_ then
                     <<stem:=powappend(stem,f)$
                     s13:=substandsep(q,s13,ftem1,vl)>>
                  else
                     <<stop2:=t$
                     fl:=nil>>$
                  stop3:=t$
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
                   <<eqprint(list('equal,0,car s))$
                   write "with leading derivative "$
                   write reval list('expt,mkldiff(f,cadr s),cddr s)$
                   write " replaces a de with "$
                   write reval list('expt,mkldiff(f,cadr p),cddr p)$
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

endmodule;


module separate;  % Routines for separation of de's.

%  Author: Andreas Brand
%  June 1990

fluid '(fnew_ genint_ gensep_ independence_ tr_gensep);

symbolic procedure termsep(a,x)$
%   Separieren eines Produktes
%   a Ausdr. in LISP-Notation, x Var.
%   Ergebnis: nil, falls keine Sep. moegl.,sonst Liste von Produktpaaren
%   ((abh. von x)(unabh. von x))
begin scalar l,p,q,sig,l1,l2$
if atom a then if x=a then l:=list(a,1)         %   Variable
                      else l:=list(1,a)         %   Konstante
else if my_freeof(a,x) then l:=list(1,a)           %   a unabh. von x
else
        <<if car a='minus then
                <<a:=cadr a$
                sig:=not sig>>$
        if pairp a and (car a='times) then l:=cdr a
                          else l:=list a$       %   l Liste der Faktoren
        p:=nil$                                 %   Liste der Faktoren,
                                                %   die x enthalten
        q:=nil$                                 %   Liste der Faktoren,
                                                %   die x nicht enth.
        while l do
             <<if my_freeof(car l,x) then q:=cons(car l,q)
                                                %   Faktor enth. x nicht
             else
               if pairp car l and (caar l='expt)
                  and my_freeof(cadar l,x)
                  and (pairp caddar l) and (car caddar l='plus) then
                     <<for each s in cdr caddar l do
                        if my_freeof(s,x) then l1:=cons(s,l1)
                                       else l2:=cons(s,l2)$
                        if l1 then
                           <<if cdr l1 then l1:=cons('plus,l1)
                                       else l1:=car l1$
                           q:=cons(list('expt,cadar l,l1),q)>>$
                        if l2 and cdr l2 then l2:=cons('plus,l2)
                                         else l2:=car l2$
                        p:=cons(list('expt,cadar l,l2),p)>>
             else p:=cons(car l,p)$
             l:=cdr l>>$
        if p then
                if length p>1 then p:=cons('times,p)
                 else p:=car p$
        if q then
                if length q>1 then q:=cons('times,q)
                 else q:=car q$
        if p or q then                          %   war Sep. moegl.?
                if null p then if sig then l:=list(1,list('minus,q))
                                      else l:=list(1,q)
                else
                        if q then if sig then l:=list(p,list('minus,q))
                                         else l:=list(p,q)
                             else if sig then l:=list(p,list('minus,1))
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
    if pairp car l and (caar l='quotient) then
      <<p:=termsep(cadar l,x)$
        if not q then q:=termsep(caddar l,x)$    % Quotient immer gleich
        if p and q then
           <<l:=cdr l$
           if car q=1 then s:=car p
                      else s:=list('quotient,car p,car q)$
           if cadr q=1 then p:=list(s,cadr p)
                       else p:=list(s,list('quotient,cadr p,cadr q))$
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
   if pairp caar cl and (caaar cl='quotient) then
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
        else if (pairp car l1) and (caar l1='expt) and
                (numberp caddar l1) and member(cadar l1,vl)
         then l1:=cdr l1
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


symbolic procedure sep(p,ftem,varl)$
%  Die Gl. p (in LISP-Notation) wird nach den Var. aus varl separiert
%  varl Liste der Variabl.
begin scalar eql,eqlist,a,q$
  if pairp p and (car p='quotient) then
  <<q:=cdr reval list('factorize,caddr p)$
    if length q>1 then q:=cons('times,q)
                  else q:=car q$
    p:=cadr p
  >>$
  if pairp p and (car p='plus) then
  a:=cons(nil,if not q then cdr p
                       else for each b in cdr p
                            collect list('quotient,b,q))
                               else
  if not q then a:=list(nil,p)
           else a:=list(nil,list('quotient,p,q))$
                                       %   Gl. als Liste von Summanden
  eql:=list(list(a,nil,varl))$
                                       %   Listen der Var. anhaengen
  eql:=eqsep(eql,ftem)$

  while eql do
  <<a:=caar eql$                  %   Listen der Var. streichen
    if cddr a then a:=cons(car a,cons('plus,cdr a))
              else a:=cons(car a,cadr a)$       %   PLUS eintragen
    if car a then
    if cdar a then a:=cons(cons('times, car a),cdr a)
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
  if not (pairp p and (car p='quotient) and
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
  if not (pairp p and (car p='quotient) and
        intersection(argset smemberl(ftem,cadr p),varl)) then
  <<eqlist:=sep(p,ftem,varl)$
    if eqlist then eql:=union(cdr eqlist,list car eqlist)$
    eqlist:=nil$
    while eql do
    <<a:=car eql$
      l:=eql:=cdr eql$
      for each b in l do
      <<s:=reval list('quotient,cdr b,cdr a)$
        if not smemberl(append(varl,ftem),s) then
        <<eql:=delete(b,eql)$
          a:=cons(reval list('plus,car a,list('times,s,car b)),cdr a)>>
      >>$
      eqlist:=cons(a,eqlist)
    >>
  >>                                                     else
  eqlist:=list cons(1,p)        % FTEM functions in the DENR of p
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

symbolic procedure starp(ft,vl)$
% vl are all variables in an expression, yields a boolean value
% whether a function of ft contains all variables of vl
begin scalar b,n$
  n:=length vl$                        % number of all variables
  while not b and ft do                % searching a fct of all vars
  if fctlength car ft=n then b:=t
                        else ft:=cdr ft$
  return not b
end$

symbolic procedure stardep(p,ftem,vl)$
%  yields: nil, if a function (from ftem) in p depends
%               on all variables (from vl)
%          cons(v,n) otherweise, with v beeing the list of variables
%               on which depend a minimal number n of functions
begin scalar b,v,n$
  vl:=varslist(p,ftem,vl)$
  if starp(ftem,vl) then
  <<n:=sub1 length ftem$
    while vl do                % searching var.s on which depend a
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
begin scalar a,aa,q,l1,l2,ft,pl,pl1,x,vl1,deno$
  if pairp p and (car p = 'quotient) then p:=cadr p$
  ftem:=smemberl(ftem,p)$
  vl:=varslist(p,ftem,vl)$
  if not (a:=stardep(p,ftem,vl)) then pl:=list p
                                 else
  if zerop cdr a then pl:=separate(p,ftem,vl)
                 else                              % e.g. a=((x y z).2)
  if delength(p) leq gensep_ then
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
      if member(x,fctargs f) and not my_freeof(q,f) then ft:=cons(f,ft)$
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
      <<if (pairp q) and (car q='quotient) then
        <<deno:=caddr q$
          q:=cadr q$
          ft:=smemberl(ftem,q)>>           else ft:=nil$
        if ft then
        <<vl1:=nil$
          for each y in vl do if my_freeof(ft,y) then vl1:=cons(y,vl1)
        >>    else vl1:=vl$
        if aa and zerop cdr aa and not (q=0) then
        <<if tr_gensep then
          <<terpri()$write "trying direct separation of "$
            deprint list q$
            write "Remaining variables: ",vl1>>$
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
          backint(list('quotient,s,deno),l2,union(fnew_,ftem),vl)
                else
          backint(s,l2,union(fnew_,ftem),vl)$
        ftem:=union(fnew_,ftem)$
        pl:=union(l1,pl)$
%       while l1 do
%       <<if fctevalstrict(car l1,ftem,vl) then
%         <<pl1:=cons(car l1,pl1)$
%           a:=list nil$
%           ftem:=union(fnew_,ftem)>>$
%         l1:=cdr l1
%       >>

        l1:=nil

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
  for each f in ftem do if my_freeof(f,v) then ft1:=cons(f,ft1)$
  if not (pairp q and (car q='quotient) and smemberl(ft1,caddr q)) then
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
      if not my_freeof(cdr a,f) and (not zerop car a) then
      if (pairp cdr a) and (cadr a='plus) then
      <<for each c in cddr a do if not my_freeof(c,f) then b:=cons(c,b)$
        if b then b:=cons('plus,b)>>      else b:=cdr a$
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
      <<a:=reval aeval list('quotient,q,b)$
  %      if not my_freeof(a,v) then
        <<l:=cons(b,l)$  % for later backward integrations
          l1:=for each c in l1 collect
                  reval list('df,list('quotient,c,b),v)$
%         casecheck(b,ftem,vl)$
%          if not freeofzero(b,ftm,vl) then .....
          q:=reval list('df,a,v)$
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
begin scalar fl,ft,q,l,v,v1,vf,s2,p,f2,fnew1$
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
      q:=integratepde(p,ft,v,nil,nil)$ % genflag:=nil, potflag=nil
      fnew1:=append(fnew_,fnew1)$
      if q then
      <<fl:=t$
        p:=reval list('times,car l,car q)$

        % Substituting the new functions of integration by derivatives
        % of them such that back-integration can be made
% hat fnew_ nur ein element, d.h. wird nur eine Integration gemacht
% oder mehrere?
        for each f1 in fnew_ do
        <<f2:=f1$
          vf:=setdiff(vl,fctargs f1)$
          for each s1 in reverse l2 do
          <<v1:=car s1$
            if not my_freeof(f1,v1) then
% only then integration makes difficulties
            <<s2:=reverse cadr s1$
              while s2 do
              <<if not smemberl(vf,car s2) then
                  f2:=reval list('df,list('quotient,f2,car s2),v1)$
% actually only dividing through those factors of (car s2)
% which depend on v1 and which do not contain variables
% which f2 does not depent on.
                s2:=cdr s2
              >>
            >>
          >>$
          if f1 neq f2 then
          <<if tr_gensep then <<write f1," is replaced by "$
                                eqprint f2>>$
            p:=subst(f2,f1,p)$
          >>
        >>$
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

endmodule;


module integrat;  % Routines for integration of pde's.

%  Author: Thomas Wolf, Andreas Brand
%  June 1993

fluid '(facint_ fnew_ poly_only potint_ tr_genint);

%symbolic procedure intpoly(p,x)$
%% increases all powers of x (also the zeroth) of the polynomial p of x
%% with x-independent coefficients, copying terms with x-dependent
%% functions
%if not pairp p then if my_freeof(p,x) then list('TIMES,x,p)
%                                   else p
%               else
%if car p='MINUS then cons('MINUS,intpoly(cadr p,x)) else
%if car p='TIMES then
%<<p:=cdr p;
%  if my_freeof(car p,x)                                        then
%     reval list('TIMES, car p,
%                intpoly(if (1<length cdr p) then
%                        cons('TIMES,cdr p)  else cadr p,x)) else
%  if car p=x then
%     reval cons('TIMES, cons(list('TIMES,x,car p), cdr p)) else
%  if (caar p='EXPT) and (cadar p=x) then
%     reval cons('TIMES, cons(list('TIMES,x,car p), cdr p)) else
%  cons('TIMES, cdr p)
%>>              else
%if car p='PLUS then
%list('PLUS,intpoly(cadr p                                       , x),
%           intpoly(if (1<length cddr p) then cons('PLUS,cddr p)
%                                        else caddr p            , x) )
%               else if my_freeof(p,x) then list('TIMES,x,p)
%                                   else p$

%-----------------

symbolic procedure ldlist(p,f,vl)$
% provides a reverse list of leading derivatives of f in p, vl is list
% of variables
begin scalar a$
  if not atom p then
  if member(car p,list('expt,'plus,'minus,'times,'quotient,'df,'equal))
  then <<
    if (car p='plus) or (car p='times) or
       (car p='quotient) or (car p='equal) then
    <<p:=cdr p$
      while p do
      <<a:=diffincl(a,ldlist(car p,f,vl))$
        p:=cdr p>>
    >>                                     else
    if car p='minus then a:=ldlist(cadr p,f,vl) else
    if car p='expt         then   % if numberp caddr p then
    a:=ldlist(cadr p,f,vl) else   % fuehrende Abl. aus der Basis
                                  % else a:=nil
    if car p='df then if cadr p=f then
    <<p:=cddr p;
      while vl do
      <<a:=cons(diffdeg(p,car vl),a);
        vl:=cdr vl>>;
      a:=list a
    >>
  >>$
  return a
end$


symbolic procedure diffincl(a,b)$
% a,b are lists of leading derivatives which are to be united
begin
  scalar p;
  while a and b do
  <<a:=ddroplow(a,car b);
    if car a then p:=cons(car a,p);
    a:=cdr a;
    b:=cdr b>>;
  return
  if null a then if p then nconc(p,b)
                      else b
            else if p then a:=nconc(p,a)
                      else a
end$


symbolic procedure ddroplow(a,cb)$
% loescht Elemente von a, von denen cb eine Ableitung ist, loescht cb,
% wenn ein Element von a eine Ableitung von cb ist
begin
  scalar h;
  return
  if null a then list(cb)
            else
  <<h:=compdiffer(car a,cb);
    if numberp(h) then if h>0 then cons(nil,a)        % car a=df(cb,..
                              else ddroplow(cdr a,cb) % cb=df(car a,..
                  else <<h:=ddroplow(cdr a,cb);       % neither
                         cons(car h,cons(car a,cdr h))>>
  >>
end$


symbolic procedure compdiffer(p,q)$
% finds whether p is a derivative of q or q of p or neither
begin
  scalar p!>q,q!>p;
  while p and ((null p!>q) or (null q!>p)) do
  <<if car p>car q then p!>q:=t else  % compare orders of derivatives
    if car p<car q then q!>p:=t;
    p:=cdr p;q:=cdr q
  >>;
  return
  if q!>p then if p!>q then nil     %  neither
                       else 0       %  q is derivative of p
          else if p!>q then 2       %  p is derivative of q
                       else 1       %  p equal q
end$


symbolic procedure ldintersec(a)$
% determines the intersection of derivatives in the list a
begin
  scalar b;
  return
  if null a then nil else
  <<b:=car a;a:=cdr a;
    while a do
    <<b:=isec(b,car a)$
      a:=cdr a
    >>;
    b
  >>
end$


symbolic procedure isec(ca,b)$
% determines the minimum derivatives between ca and b
begin
  scalar newb;
  while ca do
  <<newb:=cons(if car b<car ca then car b else car ca, newb);
    ca:=cdr ca;b:=cdr b
  >>;
  return reverse newb
end$


symbolic procedure disjun(a,b)$
<<while a do
  if (car a neq 0) and (car b neq 0) then a:=nil
                                     else <<a:=cdr a;b:=cdr b>>;
  if b then nil else t
>>$


symbolic procedure ddrophigh(a,cb)$
% loescht Elemente von a, die Ableitung von cb sind,
% loescht cb, wenn cb Ableitung eines Elements von a ist oder =a ist,
% haengt cb ansonsten an
begin
  scalar h;
  return
  if null a then list(cb)
            else
  <<h:=compdiffer(car a,cb);
    if numberp(h) then if h<2 then a         % cb is deriv or = car a
                              else ddrophigh(cdr a,cb) % car a=df(cb,..
                  else cons(car a,ddrophigh(cdr a,cb)) % neither
  >>
end$


symbolic procedure elibar(l1,l2,lds)$
begin
  scalar found1,found2,h;
  % found1=t if an LD=l1 is found, found2=t if contradiction found
  while lds and (not found2) do
  <<if car lds=l1 then found1:=t else
    <<h:=compdiffer(l2,car lds);
      if (null h) or (h eq 2) then found2:=t
    >>;
    lds:=cdr lds
  >>;
  return found1 and (not found2)
end$

symbolic procedure intminderiv(p,ftem,vlrev,maxvanz,nfsub)$
% yields a list {nv1,nv2, ... } such that nvi is the minimum
% of the highest derivatives w.r.t. vi of all the leading derivatives
% of all functions of ftem which are functions of all maxvanz variables.
% Only those are kept for which nvi>0.
% further a list ((f1 ld's of f1) (f2 ld's of f2)...),
begin scalar l,a,listoflds$
  while ftem do
  <<if (maxvanz=(fctlength car ftem)) or (nfsub=0) then
    <<l:=ldlist(p,car ftem,vlrev);
      listoflds:=cons(cons(car ftem,l),listoflds)$
      a:=if a then ldintersec(cons(a,l))
              else ldintersec(l)
    >>$
    ftem:=cdr ftem
  >>$
  return list(a,listoflds)
end$


symbolic procedure potintegrable(listoflds)$
begin
  scalar h,l1,l2,f,n,lds,f1,f2$
  if tr_genint then write "Does a potential exist?"$
  %------- Determining 2 minimal sets of integration variables
  % There must be two disjunct LDs such that all others are in their
  % ideal. This is necessary if we want to eliminate 2 functions.
  h:=listoflds;
  l1:=nil;
  while h do
  <<l2:=cdar h; % the list of LDs for the function caar h
    while l2 do
    <<l1:=ddrophigh(l1,car l2)$
      l2:=cdr l2>>;
    h:=cdr h
  >>;
  return
  if length l1 neq 2 then nil else
  if not disjun(car l1,cadr l1) then nil else
  % if there would be an overlap between l1 and l2 then it would have
  % to be integrated for elimination but it cannot --> no overlap
  % possible
  <<% selecting interesting functions for which one LD is = l1 and all
    % others are derivatives of l2 or equal l2 and vice versa. Two
    % necessary (one with an LD=l1 and one with an LD=l2) from which at
    % functions are least one (f) has no further LD.
    % Exception: 2 functions with each 2 LDs equal to (l1,l2) (these
    % functions are counted by n)
    l2:=cadr l1;l1:=car l1;
    f:=nil;f1:=nil;f2:=nil;n:=0;
    h:=listoflds;
    while h and ((not f1) or (not f2) or ((not f) and (n neq 2))) do
    <<lds:=cdar h;
      if (not f1) or (not f) then
      if elibar(l1,l2,lds) then
      <<f1:=cons(caar h,f1);
        if length lds eq 1 then f:=caar h else
        if length lds eq 2 then
        if (car lds = l2) or (cadr lds = l2) then n:=n+1
      >>;
      if (not f2) or (not f) then
      if elibar(l2,l1,lds) then
      <<f2:=cons(caar h,f2);
        if length lds eq 1 then f:=caar h
      >>;
      h:=cdr h
    >>;
    if f1 and ((n>1) or (f2 and f)) then list(l1,l2)
                                    else nil
  >>
end$ % of potintegrable


symbolic procedure vlofintlist(vl,intlist)$
% provides a list of elements of vl for which the corresponding
% elements of intlist are non-zero
begin scalar a;
  while intlist do
  <<if (car intlist) and (not zerop car intlist) then a:=cons(car vl,a);
    vl:=cdr vl;
    intlist:=cdr intlist
  >>;
  return a
end$


symbolic procedure vlofintfaclist(vl,intfaclist)$
% determining the list of all variables of vl in intfaclist
begin scalar e1,a;
  for each e1 in vl do
  if not my_freeof(intfaclist,e1) then a:=cons(e1,a);
  return a
end$


symbolic procedure multipleint(intvar,ftem,q,vari,vl,genflag,
                               potflag,partial,doneintvar)$
% multiple integration of q wrt. variables in vl, max. number of
% integrations specified by intvar
% integrating factors must not depend on doneintvar, doneintvar is
% a list of integration variables so far
% partial=t then as much as possible of an expression is integrated
% even if there is a remainder
begin
  scalar pri,vlcop,v,nmax,geni,intlist,iflag,n,nges,newcond,
         intfaclist,ph,pih,qh,qih,intfacdepnew,intfacdep$
  % intfacdep is a list of variables on which factors of integration
  % depend so far, other than the integration variable in their
  % integration --> no integration wrt. these variables by potint
  % because there the diff. operators wrt. to different variables
  % need not commute because the integrations are not done

  % pri:=t$
  if (not vari) and (zerop q) then return nil;
  nges:=0;
  vlcop:=vl;
  pih:=t;

  % Splitting of the equation into the homogeneous and inhomogeneous
  % part which is of advantage for finding integrating factors
  q:=splitinhom(q,ftem,vl)$
  qh:=car q; qih:=cdr q; q:=nil;

  while (vari or vlcop) and (pih or (not potflag)) do
  %------- if for potflag=t one variable can not be integrated the
  %------- maximal number of times (nmax) then immediate stop because
  %------- then no elimination of two functions will be possible
  << %-- The next integration variable: x, no of integrations: nmax
    if vari then <<v:=vari;nmax:=1>>
            else <<v:=car vlcop;     vlcop:=cdr vlcop;
                   nmax:=car intvar; intvar:=cdr intvar>>;


    if zerop nmax then intlist:=cons(nil,intlist)
                  else
    <<if pri then write"anf: intvar=",intvar," vari=",vari,"    q=",q$
      if vari and (not member(v,vl)) then
      <<iflag:='success$
        intlist:=cons(list(1),intlist)$
        q:=reval list('int,q,v)$
      >>                  else
      <<n:=0$
        if pri then write"333"$
        intfaclist:=nil; %-- the list of integr. factors in v-integr.
        if potflag or my_freeof(intfacdep,v) then
        % otherwise v-integration not allowed because one integrating
        % factor already depends on v
        % for potflag=t this `commutativity'-demand plays no role
        repeat << %--- max nmax integrations of qh and qih wrt. v
          if pri then <<write"444  vor intpde:"$eqprint q$terpri()$
                        write"potflag=",potflag," v=",v,
                        "  ftem=",ftem>>$
          % At first trying a direct integration of the homog. part qh
          ph:=intpde(qh,ftem,vl,v,potflag)$  % faster if potflag=nil
          if pri then <<write"nach intpde(qh):"$deprint ph>>$

          %------ At first the integration of the homogeneous part
          intfacdepnew:=intfacdep;
          if ph and (partial or (zerop cadr ph)) then <<
            %---- For the homogen. part cadr ph must be zero
            intfaclist:=cons(1,intfaclist);
            ph:=car ph
          >>                                     else
          if vari then ph:=nil
                  else
          if facint_ then <<
            ph:=findintfac(list(qh),ftem,vl,v,doneintvar,intfacdep,
                           not zerop n); % factorize before ivestig.
            if ph then << %--- Complete integr. of qh was possible
              %--- update the list of variables on which all integr.
              %--- factors depend apart from the integration variable
              intfacdepnew:=caddr ph;
              %--- extend the list of integrating factors, cadr ph
              %--- is a list of integr. factors, here only one
              intfaclist:=cons(caadr ph,intfaclist);
              %--- multiply the inhomogeneous part with integ. factor
              qih:=reval list('times,car intfaclist,qih);
              ph:=car ph  % the integral of qh
            >>
          >>;

          %------ Now the integration of the inhomogeneous part
          if not ph then pih:=nil %--- no integration possible
                    else <<
            if zerop qih then pih:=list(0,0) else
            pih:=intpde(qih,ftem,vl,v,potflag)$

            if null pih then
            write"error2: inhom. expr. can not be integrated"$
            if pri then <<write"nach intpde(qih):"$deprint pih>>$

            if pih then
            if zerop cadr pih then
            <<qih:=car pih$n:=add1 n$iflag:='success>>
                              else if not genflag then pih:=nil
                                                  else
            <<if pri then write"555"$
              if (geni:=partint(cadr pih,smemberl(ftem,cadr pih),
                                vl,v)) then
              <<qih:=reval list('plus,car pih,car geni)$
                n:=add1 n$
                ftem:=union(fnew_,ftem)$
                newcond:=append(cdr geni,newcond)$  % additional de's
                if pri then
                <<terpri()$write"nach gen newcond:"$deprint newcond>>$
                iflag:='genint
              >>                       else
              if partial then qih:=car pih
                         else pih:=nil
            >>;
            if pih then <<
              qh:=ph;
              if (not potflag) and (n neq 1) then
              intfacdep:=intfacdepnew
              %-The first integr. factor of all v-integrations does not
              % depend on any earlier integration variables and can
              % therefore be taken out of all integrals --> no incease
              % of intfacdep for n=1.
              %-For potential integration the integration variables and
              % extra-dependencies-variables of integr. factors need not
              % be disjunct therefore the intfacdep-update only for
              % not-potflag
            >>     else <<
              % inhomogeneous part can not be integrated therefore
              % reversing the succesful integration of the hom. part
              if car intfaclist neq 1 then
              qih:=reval list('quotient,qih,car intfaclist);
              intfaclist:=cdr intfaclist
            >>;
          >> %-- end of the integration of the inhomog. part

        >> until (n=nmax) or (not pih)$ %---- end of v-integration
        %------- variables of done integrations are collected for
        %------- determining integrating factors in later integr.
        if not zerop n then doneintvar:=cons(v,doneintvar)$
        nges:=nges+n;
        intlist:=cons(intfaclist,intlist)
      >>$  % of    not ( vari and (not member(v,vl)))
      if vari then <<vari:=nil;vlcop:=nil>>;
      if pri then write"ende: intvar=",intvar," vari=",vari,
      "    qh=",qh,"   qih=",qih$
    >> % of (nmax neq zero)
  >>$  % of ( while (vari or vlcop) and (pih or (not potflag)) )

  % intlist and its elements intfaclist are in the inverse order
  % to vl and the sequence of integrations done
  q:=reval list('plus,qh,qih)$ %--- adding homog. and inhomog. part
  if pri then <<terpri()$write"\\\  newcond:"$deprint newcond;
    write"multiple result:",if null iflag then nil
    else list(q,intlist,newcond,nges)
  >>;
  return if null iflag then nil
                       else list(q,intlist,newcond,nges)
end$  % of multipleint


symbolic procedure uplistoflds(intlist,listoflds)$
begin
  scalar f,h1,h2,h3,h4,lds,itl;
  while listoflds do
  <<f:=caar listoflds;
    lds:=cdar listoflds;
    listoflds:=cdr listoflds;
    h2:=nil;            % h2 becomes the new list of lds of f
    while lds do
    <<h3:=car lds; lds:=cdr lds;
      itl:=intlist;
      h4:=nil;          % h4 becomes one new ld of f
      while h3 do
      <<h4:=cons(car h3 - if null car itl then 0
                                          else length car itl, h4);
        h3:=cdr h3;itl:=cdr itl
      >>;
      h2:=cons(reverse h4,h2)
    >>;
    h1:=cons(cons(f,h2),h1)
  >>;
  return h1  % updated listoflds
end$ % of uplistoflds


symbolic procedure addintco(q, ftem, ifac, vl, vari)$
begin scalar v,f,l,vl1;
  % multi.ing factors to the constants/functions of integration
  if zerop q then l:=1
             else
  <<ftem:=reverse fctsort ftem$
    while ftem do
    if fctlength car ftem<length vl then ftem:=nil
                                    else if fctlinear(q,f)          then
                                         <<f:=car ftem$ ftem:=nil>> else
                                         ftem:=cdr ftem$
    if f then
    <<l:=lderiv2(q,f,fctargs f)$
      l:=reval coeffn(q,reval car l,cdr l)
    >>   else l:=1
  >>;
  % the constants and functions of integration
  if vari then q:=list('plus,q,intconst(l,vl,vari,list(1)))
          else
  <<vl1:=vl;
    while vl1 do
    <<v:=car vl1; vl1:=cdr vl1;
      if car ifac then
      q:=list('plus,q,intconst(l,vl,v,car ifac))$
      % l..product of factors in the coefficient of the function to be
      % eliminated, car ifac .. list of integrating factors
      ifac:=cdr ifac;
    >>
  >>$
  return reval q
end$ % of addintco


symbolic procedure integratepde(p,ftem,vari,genflag,potflag)$
%  Generalized integration of the expression p
%     if not genflag then "normal integration"
%  Equation p must not be directly separable, otherwise the depen-
%  dencies of functions of integration on their variables is wrong,
%  i.e. no dependence on explicit variables
%  ftem are all functions from the `global' ftem which occur in p, i.e.
%  ftem:=smemberl(ftem,p)$
%  if vari=nil then integration w.r.t. all possible variables within
%                   the equation
%              else only w.r.t. vari one time

begin
  scalar vl,vlrev,v,intlist,
  ili1a,ili2a,maxvanz,fsub,h,hh,nfsub,iflag,newcond,
  n1,n2,pot1,pot2,p1,p2,listoflds,secnd,ifac0,
  ifac1a,ifac1b,ifac2a,ifac2b,cop,v1a,v2a,revvl,pri$

  % pri:=t;
  if pri then <<terpri()$write"Start Integratepde">>$
  vl:=argset ftem$
  vlrev:=reverse vl;
  if vari then <<potflag:=nil;
                 if zerop p then iflag:='success>>
          else
  <<%------- determining fsub=list of functions of all variables
    maxvanz:=length vl$
    fsub:=nil;
    h:=ftem;
    while h do
    <<if fctlength car h=maxvanz then
      fsub:=cons(car h,fsub)$
      h:=cdr h
    >>$
    nfsub:=length fsub$  % must be >1 for potential-integration
    h:=intminderiv(p,ftem,vlrev,maxvanz,nfsub)$ % fsub is also for below
    intlist:=car h$
    %-- list of necessary integrations of the whole equation to solve
    %-- for a function of all variables
    listoflds:=cadr h$ %-- list of leading derivatives
  >>$
  if pri then <<terpri()$
                write"complete integrations:",intlist," for:",vl>>;
  %-- n1 is the number of integrations which must be done to try
  %-- potential integration which must enable to eliminate 2 functions
  %-- n2 is the number of integrations actually done
  n1:=for each h in intlist sum h;
  if (not vari) and (zerop n1) then
  <<n2:=0;
    if potflag then % else not necessary
    for h:=1:(length vl) do ifac0:=cons(nil,ifac0)
  >>                           else
  <<if tr_genint then
    <<terpri()$write "integration of the expression : "$
      eqprint p>>$
    if pri then
    <<terpri()$write"at first all multiple complete integration">>;
    %-- At first if possible n2 integrations of the whole equation
    h:=multipleint(intlist,ftem,p,vari,vl,genflag,nil,nil,nil)$
                   % potflag=nil, partial=nil, doneintvar=nil
    if h then
    <<p:=car h;
      ifac0:=cadr h;  % ifac0 is the list of lists of integr. factors
      newcond:=caddr h;
      n2:=cadddr h;   % number of done integrations
      % doneintvar & intfacdep for the two halfs of integrations
      % from the two parts of ifac0
      h:=nil;
      iflag:='success;
    >>   else n2:=0;
    ftem:=union(fnew_,ftem)$
  >>;
  %------------ Existence of a potential ?
  if (n1=n2) and potflag and (nfsub>1) then
  %---- at least 2 functions to solve for
  <<if not zerop n2 then            %---- update listoflds
    listoflds:=uplistoflds(reverse ifac0,listoflds)$
    if pri then <<terpri()$write"uplistoflds:",listoflds>>$
    if h:=potintegrable(listoflds) then
    <<ili1a:=car h; ili2a:=cadr h;
      % The necess. differentiations of the potential
      if pri then
      <<terpri()$write"potintegrable:",ili1a,"  ",ili2a>>$

      if pri then <<write"+++ intlist=",intlist,
                           "    ili1a=",ili1a,
                           "    ili2a=",ili2a>>$
      %-- distributing the integrating factors of ifac0 among
      %-- the two lists ifac1b and ifac2b which are so far nil
      %-- such that (ifac1b and ili1a are disjunct) and
      %--           (ifac2b and ili2a are disjunct)
      v1a:=vlofintlist(vl,ili1a);
      v2a:=vlofintlist(vl,ili2a);

      hh:=t;
      cop:=ifac0;
      while hh and cop do <<
        % cop is a list of lists of integr. factors
        if car cop then h:=vlofintfaclist(vl,cdar cop)
                   else h:=nil;
        if freeoflist(h,v2a) then <<
          ifac1b:=cons( nil, ifac1b);
          ifac2b:=cons( reverse car cop, ifac2b)
        >>                   else
        if freeoflist(h,v1a) then <<
          ifac2b:=cons( nil, ifac2b);
          ifac1b:=cons( reverse car cop, ifac1b)
        >>                   else hh:=nil;
        cop:=cdr cop;
      >>;
      % the elements of ifac1b,ifac2b are in reverse order to
      % ifac1a,ifac2a and are in the same order as vl, also
      % the elements in the infac-lists are in inverse order,
      % i.e. in the order the integrations have been done
      if pri then <<terpri()$
                    write  "ifac1a=",ifac1a,"  ifac1b=",ifac1b,
                    "  ifac2a=",ifac2a,"  ifac2b=",ifac2b >>$

      %-- lists of integrations to be done to both parts
      if hh then
      repeat % possibly a second try with part2 integrated first
      <<n1:=for each n1 in ili1a sum n1;
        % n1 .. number of remaining integrations of the first half
        p1:=multipleint(ili1a,ftem,p,nil,vl,genflag,t,t,
                        % potflag=t, partial=t
                        union(vlofintlist(vl,ili2a),
                              vlofintlist(vl,ifac1b)))$
        % that the variables of integration are not in ifac1b
        % was already checked. Only restriction: the integrating
        % factors must not depend on the last argument.

        ftem:=union(fnew_,ftem)$
        if p1 then <<
          ifac1a:=cadr p1;
          % ifac1a is now the list of integrating factors
          if newcond then newcond:=nconc(newcond,caddr p1)
                     else newcond:=caddr p1;
          if pri then <<terpri()$write"mul2: newcond=",newcond>>$
          n2:=cadddr p1;
          p1:=car p1
        >>;
        if p1 and (n1=n2) then
        %--- if the first half has been integrated suff. often
        <<%--- integrating the second half sufficiently often
          revvl:=reverse vl;
          n1:=for each n1 in ili2a sum n1;
          % calculation of the 2. part which is not contained in p1
          p2:=p1;
          cop:=ifac1a; hh:=revvl; % because ifac1a is reversed
          while cop do <<
            h:=car cop;cop:=cdr cop;
            v:=car hh;hh:=cdr hh;
            % h is the list of integrating factors of the v-integr.
            while h do <<
              p2:=reval list('quotient,list('df,p2,v),car h);
              h:=cdr h
            >>
          >>;
          p2:=reval reval list('plus,p,list('minus,p2));
          p2:=multipleint(ili2a,ftem,p2,nil,vl,genflag,t,nil,
                          % potflag=t, partial=nil
                          union(vlofintlist(vl,ili1a),
                                vlofintlist(vl,ifac2b)))$
          ftem:=union(fnew_,ftem)$
          if p2 then <<
            ifac2a:=cadr p2;
            % ifac2a is now list of integrating factors
            if newcond then newcond:=nconc(newcond,caddr p2)
                       else newcond:=caddr p2;
            if pri then <<terpri()$write"mul3: newcond=",newcond>>$
            n2:=cadddr p2;
            p2:=car p2
          >>;
          if p2 and (n1=n2) then
          % if the second half has been integrated sufficiently often
          <<iflag:='potint;
            % ifac1b,ifac2b are in reverse order to ifac1a,ifac2a!
            pot1:=newfct(fname_,vl,nfct_)$  % the new potential fct.
            pot2:=pot1;
            nfct_:=add1 nfct_$
            fnew_:=cons(pot1,fnew_);
            v:=revvl;
            while v do
            <<cop:=car ifac1a; ifac1a:=cdr ifac1a;
              while cop do <<
                pot1 :=
                   reval list('quotient,list('df,pot1,car v),car cop);
                cop:=cdr cop
              >>;
              cop:=car ifac2a; ifac2a:=cdr ifac2a;
              while cop do <<
                pot2 :=
                   reval list('quotient,list('df,pot2,car v),car cop);
                cop:=cdr cop
              >>;
              v:=cdr v;
            >>;
            p:=addintco(list('plus,p1,reval pot2),
                        ftem,ifac1b,vlrev,nil)$
            newcond:=cons(addintco(list('plus,p2,
                                        list('minus,reval pot1)),
                                   ftem,ifac2b,vlrev,nil),
                          newcond) % vari=nil
          >>
          ;if pri then write":::"$
        >>;
        secnd:=not secnd;
        % retry in different order of integration, p is still the same
        if (iflag neq 'potint) and secnd then
        <<cop:=ili1a;ili1a:=ili2a;ili2a:=cop>>
      >> until (iflag eq 'potint) or (not secnd)
    >>;
  >>$

  %--------- returning the result
  return if not iflag then nil
                      else
  <<if iflag neq 'potint then  % constants of integration
    p:=addintco(p, ftem, % the completely reversed ifac0
    <<h:=nil;
      while ifac0 do <<h:=cons(reverse car ifac0,h);ifac0:=cdr ifac0>>;
      h
    >>, vl, vari)$
    if pri then
    <<terpri()$write"ENDE INTEGRATEPDE"$deprint(cons(p,newcond))>>$
    cons(p,newcond)
  >>
end$ % of integratepde

symbolic procedure intpde(p,ftem,vl,x,potint)$
% integration of an polynomial expr. p w.r.t. x
begin scalar f,ft,l,l1,vl,k,s,a,iflag,flag$
  ft:=ftem$
  vl:=cons(x,delete(x,vl))$
  while ftem and not flag do
  <<f:=car ftem$ % integrating all terms including car ftem
    if member(x,fctargs f) then
    <<l1:=l:=lderiv2(p,f,vl)$
      while not (flag or (iflag:=intlintest(l,x))) do
      <<k:=reval coeffn(p,car l,cdr l)$
        if intcoefftest(lderiv1(k,f,vl),car l,vl) then
        <<a:=decderiv(car l,x)$
          k:=reval list('int,subst('v_a_r_,a,k),'v_a_r_)$
          k:=reval subst(a,'v_a_r_,k)$
          s:=cons(k,s)$
          p:=reval aeval list('difference,p,list('df,k,x))$
          if (l:=lderiv2(p,f,vl))=l1 then flag:='neverending
                                     else l1:=l
        >>                                        else
        flag:='coeffld
      >>$
      % iflag='nofct is the so far integrable case
      % the non-integrable cases are: flag neq nil,
      % (iflag neq nil) and (iflag neq 'nofct), an exception to the
      % second case is potint where non-integrable rests are allowed
      if iflag='nofct then ftem:=smemberl(ftem,p)
                      else if potint or (fctlength f<length vl) then
                           <<ftem:=cdr ftem$flag:=nil>>         else
                           flag:=(iflag or flag)
    >>                     else
    ftem:=cdr ftem
  >>$
  return
  if not flag then
  <<l:=explicitpart(p,ft,x)$
    l:=list('int,l,x)$
    s:=reval aeval cons('plus,cons(l,s))$
    p:=list('difference,p,list('df,l,x))$
    if poly_only then if ratexp(s,ft) then list(s,reval reval aeval p)
                                      else nil
                 else list(s,reval reval aeval p)
  >>          else nil$
end$ % of intpde

symbolic procedure explicitpart(p,ft,x)$
% part of a sum p which only explicitly depends on a variable x
begin scalar l$
if not member(x,argset smemberl(ft,p)) then l:=p
else if pairp p then
   <<if car p='minus then
        l:=reval list('minus,explicitpart(cadr p,ft,x))$
   if (car p='quotient) and not member(x,argset smemberl(ft,caddr p))
   then
      l:=reval list('quotient,explicitpart(cadr p,ft,x),caddr p)$
   if car p='plus then
      <<for each a in cdr p do
          if not member(x,argset smemberl(ft,a)) then l:=cons(a,l)$
      if pairp l then l:=reval cons('plus,l)>> >>$
if not l then l:=0$
return l$
end$

symbolic procedure intconst(co,vl,x,ifalist)$
% The factors in ifalist must be in the order of integrations done
if null ifalist then 0 else
begin scalar l,l2,f,coli,cotmp$
  while ifalist do <<
    cotmp:=coli;
    coli:=nil;
    while cotmp do <<
      coli:=cons(list('int,list('times,car ifalist,car cotmp),x),coli);
      cotmp:=cdr cotmp
    >>;
    coli:=cons(1,coli);
    ifalist:=cdr ifalist
  >>;

  while coli do
  <<f:=newfct(fname_,delete(x,vl),nfct_)$
    nfct_:=add1 nfct_$
    fnew_:=cons(f,fnew_)$
    l:=cons(list('times,f,car coli),l)$
    coli:=cdr coli
  >>$
  if length l>1 then l:=cons('plus,l)
                else if pairp l then l:=car l
                                else l:=0$
  if co and co neq 1 then
  if pairp co then
  <<if car co='times then co:=cdr co
                     else co:=list co$
    while co do <<if my_freeof(car co,x) then l2:=cons(car co,l2)$
                  co:=cdr co>>
  >>
              else if co neq x then l2:=list co$
  return reval if l2 then cons('times,cons(l,l2))
                     else l
end$

symbolic procedure intcoefftest(l,l1,vl)$
begin scalar s$
return if not pairp l then t
       else if car l='df then
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

symbolic procedure intlintest(l,x)$
%  Test,ob in einem Paar (fuehrende Ableitung.Potenz)
%  eine x-Ableitung linear auftritt
if not car l then
   if zerop cdr l then 'nofct
                  else 'nonlin
else                                    %  Fkt. tritt auf
  if (car l) and (cdr l=1) then         %  fuehr. Abl. tritt linear auf
                if pairp car l then     %  Abl. der Fkt. tritt auf
                    if caar l='df then
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
return if l then if car l='df then
        <<l1:=decderiv1(cddr l,x)$
        if l1 then cons('df,cons(cadr l,l1))
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
begin scalar l,l1,l2,fl$
ftem:=smemberl(ftem,q)$
if l1:=integrableode(q,ftem) then       % looking for an integrable ode
   if l1:=integrateode(q,car l1,cadr l1,caddr l1,ftem) then
                                       % trying to integrate it
      <<q:=algsimple(l1,ftem,argset ftem)$
      ftem:=smemberl(union(fnew_,ftem),q)$
      fl:=t>>$
while l1:=integratepde(q,ftem,nil,genflag,potint_) do
                                       % trying to integrate a pde
      <<q:=car l1$
      for each a in cdr l1 do
             <<ftem:=union(fnew_,ftem)$
             if (l2:=integratede(a,ftem,nil)) then l:=append(l2,l)
                                              else l:=cons(a,l)>>$
      fl:=t$
      if null genflag then l1:=nil$
      ftem:=smemberl(union(fnew_,ftem),q)>>$
if fl then
   <<l:=cons(q,l)$
   l:=for each a in l collect reval aeval a$
   l:=for each a in l collect
          if pairp a and (car a='quotient) then cadr a
                                           else a>>$
return l$
end$

endmodule;


module genint; %Generalized integration of pde's containing unknown fns.

%  Author: Andreas Brand
%  December 1991

fluid '(fname_ fnew_ nfct_ tr_genint tr_gensep);

symbolic procedure gintorder(p,vl,x)$
%  reorder equation p
begin scalar l,l1,q,m,b,c$
  if pairp(p) and (car p='quotient) then <<q:=caddr p$p:=cadr p>>$
  if pairp(p) and (car p='plus) then p:=cdr p   % list of summands
                                else p:=list p$
  while p do
  <<l1:=gintorder1(car p,x)$
    if deponallvars(car l1,x,vl) then l:=p:=nil
                                 else <<l:=termsort(l,l1)$p:=cdr p>> >>$
  if l then
  <<l:=for each a in l collect if cddr a then
               <<b:=car a$
                 c:=cdr reval coeff1(cons('plus,cdr a),x,nil)$
                 m:=0$
                 while c and (car c=0) do <<c:=cdr c$m:=add1 m>>$
                 if m>0 then b:=list('times,list('expt,x,m),b)$
                 cons(reval b,c)>>
                                         else
                 cons(reval car a,cdr reval coeff1(cadr a,x,nil))$
    if q then
      if my_freeof(q,x) then
       l:=for each a in l collect
              cons(car a,for each s in cdr a collect
                             reval list('quotient,s,q))
      else
       l:=for each a in l collect
              cons(reval list('quotient,car a,q),cdr a)>>$
return l$
end$

symbolic procedure deponallvars(c,x,vl)$
% tests for occurence off vars from vl in factors of c depending on x
begin scalar l$
if pairp c and (car c='times) then c:=cdr c
                              else c:=list c$
while c and vl do
<<if not my_freeof(car c,x) then
     for each v in vl do if not my_freeof(car c,v) then l:=cons(v,l)$
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
if pairp p and (car p='minus) then <<sig:=t$p:=cadr p>>$
if pairp p and (car p='times) then p:=cdr p
                              else p:=list p$
for each a in p do
   <<if my_freeof(a,x) then l2:=cons(a,l2)
     else if a=x then l2:=cons(a,l2)
     else if pairp a and (car a='expt) and (cadr a=x) and fixp caddr a
     then l2:=cons(a,l2)
     else l1:=cons(a,l1)>>$
if pairp l1 then
   if cdr l1 then l1:=cons('times,l1)
             else l1:=car l1$
if pairp l2 then
   if cdr l2 then l2:=cons('times,l2)
             else l2:=car l2$
if sig then if l2 then l2:=list('minus,l2)
                  else l2:=list('minus,1)$
return list(if l1 then l1 else 1,if l2 then l2 else 1)$
end$

symbolic procedure partint(p,ftem,vl,x)$
begin scalar f,neg,l1,l2,n,k,l$
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
    if (pairp car s) and (caar s='df) then
      <<l1 := reval list('difference,cadar s,list('df,f,x,add1 n)) . l1;
      l2:=cddar s>>
    else
      <<l1:=cons(signchange reval list('difference,car s,
                                        list('df,f,x,add1 n)),l1)$
      l2:=nil>>$
    reval cons('plus, for each sk on cdr s collect
                <<neg:=not neg$
                k:=add1 k$
                reval
                list('times,if neg then -1 else 1,
                            append(list('df,f,x,n-k),l2),
                                   tailsum(sk,k,x))>>
              )>>$
if l then l:=cons(reval cons('plus,l),l1)$
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
return reval cons('plus,
for each a in sk collect
    <<j:=j+1$
    list('times,a,prod(j+1,j+k),list('expt,x,j)) >> )
end$

symbolic procedure prod(m,n)$
if m>n then 1
       else for i:=m:n product i$

endmodule;


module intfactr;  % Routines for finding integrating factors of PDEs.

%  Author: Thomas Wolf
%  July 1994

% The following without factorization --> faster but less general
%symbolic procedure fctrs(p,vl,v)$
%begin scalar fl1,fl2,neg;
%
%write"p=",p;
%
% if car p='MINUS then <<neg:=t;p:=cdr p>>$
% return
% if not pairp p then if my_freeof(p,v) and (not freeoflist(p,vl)) then
%                     list(p,1,neg)                             else
%                     list(1,p,neg)
%                else if car p='PLUS then list(1,p,neg)
%                                    else
% if car p='TIMES then
% <<for each el in cdr p do
%       if my_freeof(el,v) and (not freeoflist(p,vl)) then
%   fl1:=cons(el,fl1)                                              else
%   fl2:=cons(el,fl2);
%   if pairp fl1 then fl1:=cons('TIMES,fl1);
%   if pairp fl2 then fl2:=cons('TIMES,fl2);
%   if not fl1 then fl1:=1;
%   if not fl2 then fl2:=1;
%   list(fl1,fl2,neg)
% >>              else if my_freeof(p,v) and (not freeoflist(p,vl)) then
% list(p,1,neg)                                                  else
% list(1,p,neg)
%end$ % of fctrs
%

symbolic procedure fctrs(p,indep,v)$
begin scalar fl1,fl2;
 p:=cdr reval factorize p;
 for each el in p do
 if freeoflist(el,indep) and (not my_freeof(el,v))
   then fl1:=cons(el,fl1)
  else fl2:=cons(el,fl2);
 if null fl1 then fl1:=1;
 if null fl2 then fl2:=1;
 if pairp fl1 then fl1:=cons('times,fl1);
 if pairp fl2 then fl2:=cons('times,fl2);
 return list(fl1,fl2)
end$ % of fctrs


symbolic procedure extractfac(p,indep,v)$
% Looks for factors of p dependent of v and independent of indep and
% returns a list of the numerator factors and a list of the denominator
% factors.
begin scalar nu,de$
 return
 if car p='quotient                          then
 <<nu:=fctrs( cadr p,indep,v);
   de:=fctrs(caddr p,indep,v);
   list( reval list('quotient,  car nu,  car de),
               list('quotient, cadr nu, cadr de) )
 >>                                          else fctrs(p,indep,v)
end$ % of extractfac

%----------------------------

symbolic procedure get_kernels(ex)$
% gets the list of all kernels in ex
begin scalar res,pri$
 % pri:=t;
 ex:=reval ex$
 if pri then <<terpri()$write"ex=",ex>>;
 if pairp ex then
 if (car ex='quotient) or (car ex='plus) or (car ex='times) then
 for each s in cdr ex do res:=union(get_kernels s,res)      else
 if (car ex='minus) or
    ((car ex='expt)    and
%    (numberp caddr ex)) then % not for e.g. (quotient,2,3)
     (cadr ex neq 'e)  and
     (cadr ex neq 'e)  and
     (not fixp cadr ex)   ) then res:=get_kernels cadr ex
                            else res:=list ex
             else if idp ex then res:=list ex$
 if pri then <<terpri()$write"res=",res>>;
 return res$
end$

%------------------

symbolic procedure specialsol(p,vl,fl,x,indep,gk)$
% tries a power ansatz for the functions in fl in the kernels
% of p to make p to zero
% indep is a list of kernels, on which the special solution should
% not depend. Is useful, to reduce the search-space, e.g. when an
% integrating factor for a linear equation for, say f, is to be
% found then f itself can not turn up in the integrating factor fl
% gk are kernels which occur in p and possibly extra ones which
% e.g. are not longer in p because of factorizing p but which are
% likely to play a role, if nil then determined below
begin
 scalar e1,e2,n,nl,h,sublist,eqs,startval,pri,printold;
 % pri:=t;
 p:=num p;
 if pri then <<
  terpri()$write"The equation for the integrating factor:";
  terpri()$eqprint p;
 >>;
 if null gk then gk:=get_kernels(p);
 for each e1 in fl do <<
  h:=nil; %---- h is the power ansatz
  if pri then
  for each e2 in gk do <<
   terpri()$write"e2=",e2;
   if my_freeof(e2,x) then write" freeof1";
   if not freeoflist(e2,fl) then write" not freeoflist"$
   if not freeoflist(e2,indep) then write" dependent on indep"
  >>;
  %----- nl is the list of constants to be found
  for each e2 in gk do
  if (not my_freeof(e2,x)) and % integ. fac. should depend on x
     freeoflist(e2,fl)  and % if the equation is linear in fl
                            % e.g. if an integr. factor is to
                            % be found even for a non-lin. de
     freeoflist(e2,indep) then <<
   n:=gensym();nl:=cons(n,nl);
   h:=cons(list('expt,e2,n),h);
  >>;
  if h then <<
   if length h > 1 then h:=cons('times,h)
                   else h:=car h;
   %-- the list of substitutions for the special ansatz
   sublist:=cons((e1 . h),sublist);
   if pri then <<terpri()$write"Ansatz: ",e1," = ",h>>;
   p:= reval num reval subst(h,e1,p);
   if pri then <<terpri()$write"p=";eqprint p>>
  >>
 >>;
 if null h then return nil;
 %------- An numerical approach to solve  for the constants
 if nil then << % numerical approach
  %--- Substituting all kernels in p by numbers
  on rounded;
  precision 20;
  terpri()$terpri()$write"Before substituting numerical values:";
  eqprint p;
  terpri()$terpri()$write"Constants to be calculated: ";
  for each n in nl do write n,"  ";

  for each e1 in nl do <<
   h:=p;
   for each e2 in gk do
   if freeoflist(e2,fl) then
   if pairp e2 and ((car e2 = 'df) or (car e2 = 'int)) then <<
    n:=list('quotient,1+random 30028,30029);
    terpri();write"substitution done: ",e2," = ",n;
    h:=subst(list('quotient,1+random 30028,30029),e2,h)
   >>;
   for each e2 in gk do
   if freeoflist(e2,fl) then
   if not(pairp e2 and ((car e2 = 'df) or (car e2 = 'int))) then <<
    n:=list('quotient,1+random 30028,30029);
    terpri();write"substitution done: ",e2," = ",n;
    h:=subst(list('quotient,1+random 30028,30029),e2,h)
   >>;

   terpri()$terpri()$write"The equation after all substitutions: ";
   terpri()$
   eqprint h;

   eqs:=cons(reval h,eqs);
   startval:=cons(list('equal,e1,1),startval)
  >>;
  if length eqs = 1 then eqs:=cdr eqs
                    else eqs:=cons('list,eqs);
  if length startval = 1 then startval:=cdr startval
                         else startval:=cons('list,startval);
  terpri()$write"start rdsolveeval!";terpri()$terpri()$
  h:=rdsolveeval list(eqs,startval);
  eqs:=nil;
  off rounded;
 >>;

 %----- An analytical approach to solve for the constants
 if null pri then <<printold:=print_;print_:=nil>>;
 if p and not zerop p then                  % uebernommen aus SEPAR
 if not (pairp p and (car p='quotient) and  %      "       "    "
        intersection(argset smemberl(fl,cadr p),vl)) then
 p:=separ2(p,fl,vl)                                  else
 p:=nil;
 if null pri then print_:=printold;

 if p then <<
  % possibly investigating linear dependencies of different caar p
  % solve(lasse x-abhaengige und nl-unabhaengige faktoren fallen von
  %       factorize df(reval list('QUOTIENT, caar p1, caar p2),x),nl).
  while p do
  if freeoflist(cdar p,nl) then <<eqs:=nil;p:=nil>>
  % singular system --> no solution
                           else <<
   eqs:=cons(cdar p,eqs);
   p:=cdr p
  >>;
 >>;
 if pri then <<terpri()$write"eqs1=",eqs>>;
 if null eqs then return nil
             else <<
  if pri then <<
   terpri()$write"The algebraic system to solve for ",nl," is:";
   if length eqs > 1 then deprint eqs
                     else eqprint car eqs
  >>;
  if length eqs > 1 then eqs:=cons('list,eqs)
                    else eqs:=car eqs;

  if pri then <<terpri()$write"eqs2=",eqs;terpri();write"nl=",nl>>$

  % for catching the error message `singular equations'
  if pri then <<
   terpri()$write"The algebraic system to solve for ",nl," is:";
   eqprint eqs
  >>;
  h:=cons('list,nl);
  eqs:=<<
   h:=errorset({'solveeval,mkquote{eqs, h}},nil,nil)
   where !*protfg=t;
   erfg!*:=nil;
   if errorp h then nil else cdar h    % cdr for deleting 'LIST
  >>;

  if pri then <<terpri()$write"eqs3=",eqs;terpri()>>$

  %--- eqs is the list of solutions for the constant exponents of the
  %--- integrating factor

  if null eqs then return nil;
  if length nl=1 then eqs:=list eqs;
  if pri then <<write"nl=",nl,"  eqs4=",eqs;terpri()>>;

  for each e1 in eqs do <<  % each e1 is a list of substitutions
   if pri then <<terpri()$write"e2=",e1;terpri()>>$
   if car e1='list then e1:=cdr e1;
   if pri then <<terpri()$write"e3=",e1;terpri()>>$
   for each e2 in e1 do <<
    if pri then algebraic write"solution:",symbolic e2;
    sublist:=subst(caddr e2,cadr e2,sublist)
   >>;
   if pri then <<terpri()$write"The sublist is:",sublist>>
  >>;
 >>;
 return for each e1 in sublist collect (car e1 . reval cdr e1)
end$   % of specialsol

%------------------

symbolic operator findintfac$
symbolic procedure findintfac(pl,ftem,vl,x,doneintvar,intfacdep,
                              factr)$

% - pl is a list of equations from which the *-part (inhomogeneous
%   terms) have been dropped.
% - each equation of pl gets an integrating factor h
% - doneintvar is a list of variables, on which the integrating factor
%   should not depend. The chances to find an integrating factor
%   increase if the inhomogeneous part of pl is dropped and
%   separately integrated with generalized integration later.
% - if factr is not nil then the equation(s) pl is(are) at first
%   factorized, e.g. if integration(s) have already been done
%   and there is a chance that the equation can factorize, thereby
%   simplify and giving a higher chance for integrability.

begin
 scalar h,newequ,tozero,fl,e1,pri,factr,exfactors,ftr,gk;
 % exfactors is the list of factors extracted at the beginning
 % pri:=t;
 factr:=t; % whether tozero should be factorized

 if pri then <<terpri()$write"START VON FINDINTFAC">>;
 %--- Generation of the condition for the integrating factor(s) in fl
 for each e1 in pl do <<
  %--- extracting factors dependend on x and independent of
  %--- doneintvar but only if integrations have already been done,
  %--- i.e. (doneintvar neq nil)
  gk:=union(gk,get_kernels(e1));
  if factr then <<ftr:=extractfac(e1,append(doneintvar,ftem),x);
                  if not evalnumberp car ftr then
                  gk:=union(gk,car ftr);
                  if (cadr ftr) and (not evalnumberp cadr ftr) then
                  gk:=union(gk,cadr ftr)>>
           else ftr:=list(1,nil);
  exfactors:=cons(car ftr,exfactors);
  if car ftr neq 1 then <<
   e1:=cadr ftr;
   if pri then <<terpri()$write"extracted factor:",eqprint car ftr>>;
  >>;
  %--- making an ansatz for the integrating factor
  h:=gensym();
  depl!*:=cons(list(h,x),depl!*)$
  depend h,x;
  fl:=h . fl;
  e1:=intpde(reval list('times,h,e1),ftem,vl,x,t);
  if null car e1 then <<
   pl:=nil;
   tozero:=nil
  >>             else <<
   newequ:=car e1 . newequ;
   tozero:=cadr e1 . tozero;
   if pri then <<
    terpri()$write" the main part of integration:"$ eqprint(car e1);
    terpri()$write"car e1=",car e1;
    terpri()$write" the remainder of integration:"$ eqprint(cadr e1);
    terpri()$write"cadr e1=",cadr e1;
   >>
  >>;
 >>;
 if null tozero then return nil;
 %-------- newequ is the integral
 newequ:=if length pl > 1 then cons('plus,newequ)
                          else car newequ;
 %-------- tozero is the PDE for the integrating factor
 tozero:=reval if length pl > 1 then cons('plus,tozero)
                                else car tozero;

 if pairp tozero and (car tozero='quotient) then tozero:=cadr tozero$

 if factr then <<
  h:=cdr reval list('factorize,tozero)$
  if pri then <<terpri()$write"The factors of tozero:",h>>;
  tozero:=nil;
  for each e1 in h do
  if smemberl(fl,e1) then tozero:=cons(e1,tozero)$
  tozero:= reval if length tozero > 1 then cons('times,tozero)
                                      else car tozero;
 >>;
 if nil and pri then <<write"tozero =";eqprint tozero >>;
 h:=nil;
 % actually only those f in ftem, in which pl is nonlinear, but also
 % then only integrating factors with a leading derivative low enough
 h:=specialsol(tozero,vl,fl,x,append(ftem,doneintvar),gk);
 % h:=specialsol(tozero,vl,fl,x,doneintvar,gk);
 if pri then <<write"h=",h;terpri()>>;
 if h then <<
  if print_ then <<
   if length pl = 1 then write"An integrating factor has been found:"
                    else write"Integrating factors have been found: "$
   for each e1 in h do algebraic write lisp cdr e1,"  ";
  >>;
  for each e1 in h do << % each e1 is one integrating factor determined
   if pri then <<terpri()$write"e1=",e1;
                   terpri()$write"newequ=",newequ;terpri()>>;
   newequ:=reval subst(cdr e1,car e1,newequ);
   if pri then <<terpri()$write"newequ=",newequ>>;
  >>
 >>   else if pri then write"no integrating factor";

 %--- delete all dependencies of the functions in fl
 %--- must come before the following update
 for each e1 in fl do
 depl!*:=delete(assoc(e1,depl!*),depl!*)$

 %--- update intfacdep
 for each e1 in vl do
 if (e1 neq x) and my_freeof(intfacdep,e1) and
    ((not my_freeof(h,e1)) or (not my_freeof(exfactors,e1)))
 then intfacdep:=cons(e1,intfacdep);

 %--- returns nil if no integrating factor else a list of the
 %--- factors and the integral
 if h and print_ then <<
  terpri()$write"The integrated equation:";
  eqprint newequ
 >>;
 return if (null h) or (zerop newequ) then nil else
 list(newequ,
      for each e1 in h collect <<
       ftr:=car exfactors;
       exfactors:=cdr exfactors;
       if ftr=1 then cdr e1
                else reval list('quotient,cdr e1,ftr)
      >>,
      intfacdep)
end$

endmodule;


module odeint;  % Integration of ode's containing unknown functions.

%  Author: Thomas Wolf
%  August 1991

fluid '(cont_ fnew_ odesolve_ poly_only safeint_);

symbolic procedure integrateode(de,fold,xnew,ordr,ftem)$
begin scalar newde,newnewde,l,factrs,fc,changd$
 return
 if not xnew then begin    % Integr. einer alg. Gl. fuer eine Abl.
  if pairp de and (car de='quotient) then de:=cadr de$
  factrs:=cdr reval list('factorize,de);
  l:=for each fc in factrs collect
  if smember(fold,fc) then <<
   newde:=cadr solveeval list(fc,fold)$
   if not freeof(newde,'root_of) then fc
                                 else <<
    newde:=list('plus,cadr newde,list('minus,caddr newde))$
    if (l:=integratepde(newde,ftem,nil,t,nil)) then
    <<changd:=t;car l>>                        else fc
   >>
  >>                  else fc;
  return if not changd then nil
                       else
  if length l > 1 then cons('times,l)
                  else cdr l
%  newde:=cadr solveeval list(de,fold)$
%  l:='ROOT_OF;
%  if not freeof(newde,l) then return nil;
%  newde:=list('PLUS,cadr newde,list('MINUS,caddr newde))$
%  return if (l:=integratepde(newde,ftem,nil,t,nil)) then car l
%                %genflag=t,potflag=t               else nil

%  if newde=de then nil
%             else if (l:=integratede(newde,ftem,nil)) then car l
%                                                      else nil$
 end         else               % eine ode fuer ein f?
 if not pairp fold then         % i.e. not df(...,...), i.e. fold=f
                        odeconvert(de,fold,xnew,ordr,ftem)
                                % --> ode fuer eine Abl. von f
                   else begin
  newde:=odeconvert(de,fold,xnew,ordr,ftem)$
%  if print_ then
%     if newde then <<terpri()$write "One ode has been integrated.">>$
  return
  if not newde then nil
               else <<
    newnewde:=cadr solveeval list(newde,fold)$
    newnewde:=reval list('plus,cadr newnewde,list('minus,
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
      a:=list('plus,list('times,f,list('expt,list(d_y,ordr),i)),a)$
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
  if cdr v1 = nil then <<vl1:=cdr v2$vl2:=cdr v2>>
                  else <<vl1:=cons(cadr v1,cdr v2)$
                         vl2:=append(cddr v1,cdr v2)>>$
  return
  if kind = 0 then <<vl1:=append(cdr v1,cdr v2)$
                     h1:=newfct(fn,vl1,'_)$
                     list('list,h1,list('list,h1))>>
  else
  if kind = 1 then <<h1:=newfct(fn,vl1,1)$
                     list('list,h1,list('list,h1))>>
  else
  if kind = 2 then <<h1:=newfct(fn,vl2,1)$
                     list('list,h1,list('list,h1))>>
  else
  if kind = 3 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     list('list,reval list('plus,h1,h2),
                          list('list,h1,h2))>>
  else
  if kind = 4 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     list('list,reval list('times,h1,h2),
                          list('list,h1,h2))>>
  else
  if kind = 5 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     list('list,reval list('plus,list('times,h1,h2),h3),
                          list('list,h1,h2,h3))>>
  else
  if kind = 6 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl2,3)$
                     list('list,reval list('plus,list('times,h1,h2),h3),
                          list('list,h1,h2,h3))>>
  else
  if kind = 7 then <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     h4:=newfct(fn,vl2,4)$
                     list('list,reval list('plus,
                          list('times,h1,h2),h3,h4),
                          list('list,h1,h2,h3,h4))>>
  else
% ansatz of the form FN = FN1(v11,v2) + FN2(v12,v2) + ... + FNi(v1i,v2)
  if kind = 8 then <<n:=1$ vl1:=cdr v1$ vl2:=cdr v2$
                    fl:=()$
                     while vl1 neq () do <<
                       h1:=newfct(fn,cons(car vl1,vl2),n)$
                       vl1:=cdr vl1$
                       fl:=cons(h1, fl)$
                       n:=n+1
                     >>$
                     list('list, cons('plus,fl), cons('list,fl))>>


  else
                   <<h1:=newfct(fn,vl1,1)$
                     h2:=newfct(fn,vl2,2)$
                     h3:=newfct(fn,vl1,3)$
                     h4:=newfct(fn,vl2,4)$
                     list('list,reval list('plus,list('times,h1,h2),
                                                 list('times,h3,h4)),
                          list('list,h1,h2,h3,h4))>>
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
  if a='int then ex:=list reval car ex$
  while (op neq '!_abb) and ex do
   <<b:=odecheck(car ex,fint,ftem)$
   if b then                                  % function found
     if b eq '!_abb then op:='!_abb           % occures properly
                    else op:=odetest(op,b)$
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

symbolic procedure odeconvert(de,ford,xnew,ordr,ftem)$
begin scalar j,ford_,newco,oldde,newde,newvl,null_$
 ford_:='y_$%gensym$
 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 depend1(ford_,xnew,t)$
 oldde:=reval subst(ford_,reval ford,de)$
 if pairp ford then                 % i.e.  (car ford) eq 'DF then
 << for j:=1:ordr do
   oldde:= subst( reval list('df,ford_,xnew,j),
                  reval list('df,ford,xnew,j), oldde)>>$
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
 newde:=reval algebraic first
            odesolve(symbolic oldde,symbolic ford_,symbolic xnew)$
 % Instead of the following test one should return several cases
 if safeint_ and zero_den(newde,ftem,argset ftem) then newde:=nil;
 if newde and (cadr newde neq oldde) then begin   % solution found
  % Test der Loesung klappt nur, wenn Loesung explizit gegeben
  if cadr newde neq ford_ then <<
   if print_ then
    <<write "Solution of the ode is not explicitly given."$
    algebraic write "Equation is: ",algebraic symbolic oldde$
    algebraic write "Solution is: ",algebraic symbolic newde
   >>;
   if poly_only then % The solution must be rational in the
                     % function and constants of integration
   if not ratexp1(newde,ford_) then newde:=nil else <<
    j:=1;
    while (j leq ordr) and
          ratexp1(subst(ford_,list('arbconst,j),newde),ford_) do j:=j+1;
    if j leq ordr then newde:=nil
   >>;
  >>                      else begin
   null_:=reval reval aeval subst(caddr newde, ford_, oldde)$
%  reval reval because of a REDUCE bug for special data,
%  to be droped as soon as possible
   if (null_ neq 0) then begin
%    newde:=nil$
    if print_ then begin
     write "odesolve solves :  "$
     deprint list oldde$
     write "to"$
     deprint list newde$
     write "which inserted in the equation yields"$
     deprint list null_$
    end
   end
  end
 end$
 algebraic ( clear explog )$
 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 if newde then
 <<newde:=list('plus,cadr newde,list('minus,caddr newde))$
   if 0 = reval list('plus,newde,list('minus,oldde)) then newde:=nil>>$
 return
 if not newde then nil
              else
 <<newde:=subst(ford,ford_,newde)$
   newvl:=delete(xnew,if (pairp ford and (car ford='df))
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

endmodule;


module simplf;  % Simplifications and substitution of functions.

%  Author: Andreas Brand, Thomas Wolf
%  August 1991, May 1995

fluid '(cont_ contradiction_ fcteval_ fnew_ ineq_
        one_argument_functions_ print_ solvealg_);

symbolic procedure clearfactors(sorg,ftem,vl)$
%  liefert Liste der Gl. die entstehen, wenn in allen Gl. aus sorg
%  gemeinsame Faktoren, die keine der Funktionen aus ftem sowie deren
%  Ableitungen enthalten, gekuerzt werden
if sorg and ftem then
begin scalar l,ft$
while sorg do
        <<if not zerop car sorg then
        if not(ft:=smemberl(ftem,car sorg)) then l:=cons(car sorg,l)
        else l:=cons(reval algsimple(reval car sorg,ft,vl),l)$
        sorg:=cdr sorg>>$
return l
end
else sorg$

symbolic procedure simplifyterm(p,ftem)$
%  simplify a single factor p of g=p*q*r*...=0
if (ftem:=smemberl(ftem,p)) then
  if pairp p and (member(car p,'(minus sqrt quotient)) or
                 ((car p='expt) and numberp caddr p)) then
     simplifyterm(cadr p,ftem)
  else p
else 1$

symbolic procedure signchange(g)$
%  ensure, that the first term is positive
if pairp g and (car g='minus) then cadr g
else
if pairp g and (car g='plus) and (pairp cadr g) and (caadr g='minus)
then reval list('minus,g)
else g$

symbolic procedure algsimple(g,ftem,vl)$
%  Gl. die entsteht, wenn in g gemeinsame Faktoren, die keine der Fkt.
%  aus ftem sowie deren Ableitungen enthalten, gekuerzt werden
if pairp g then
begin scalar h,l$
g:=reval aeval g$
if (car g='expt) and freeoflist(cadr g,vl) then g:=1
else if car g='minus then g:=algsimple(cadr g,ftem,vl)
else if (car g='quotient) or (car g='times) then
   g:=reval aeval cons(car g,
                       for each a in cdr g collect algsimple(a,ftem,vl))
else
<<h:=ftem$
  g:=signchange(g)$
  l:=cons(nil,0)$
  while h do
     <<l:=lderiv(g,car h,fctargs car h)$
     if l then h:=nil
          else h:=cdr h>>$
  if l then
    <<h:=car reverse cdr reval list('coeff,g,l)$
                                         %highest coefficient
    if lowpow!*>1 then
       g:=reval list('quotient,g,list('expt,l,lowpow!*-1))$
    if not zerop h then
        if pairp h then
            <<h:=independpart(reval list('gcd,g,h),ftem,vl)$
            if not zerop h then g:=reval list('quotient,g,h)>>
        else g:=reval list('quotient,g,list('gcd,g,h))>>
>>$
return g
end
else if zerop g then 0
                else if my_freeof(ftem,g) then 1
                                       else g$

symbolic procedure intsimplify_drop(factlist,xl,ex)$
%  Find factors in factlist which can't be droped and
%  the GCD of the exponents
begin scalar fl,ex1$
 for each s in factlist do
     if not freeoflist(s,xl) then
        <<fl:=cons(s,fl)$
        if ex and pairp s and (car s='expt) then
           if zerop ex then ex:=caddr s
                       else ex:=reval list('gcd,ex,caddr s)
        else ex:=nil>>$
 if zerop ex or (ex=1) then ex:=nil$
 if ex and not freeoflist(ex,xl) then
    if pairp ex then
       <<if car ex='times then ex1:=cdr ex
                          else ex1:=cdr reval list('factorize,ex)$

         ex:=nil$
         for each s in ex1 do
             if freeoflist(s,xl) then ex:=cons(s,ex)$
         if pairp ex then
            if pairp cdr ex then ex:=cons('times,reverse ex)
                            else ex:=car ex
         else ex:=nil>>
    else ex:=nil$
  return cons(reverse fl,ex)$
end$

symbolic procedure facsum(ex)$
begin scalar newex,fa,ep;
 return
 if (pairp ex) and (car ex = 'plus) then <<
  ex:=cdr reval factorize ex;
  while ex do <<
   fa:=car ex;ex:=cdr ex;
   ep:=1;
   while (pairp ex) and (car ex=fa) do
   <<ep:=ep+1;ex:=cdr ex>>;
   if ep=1 then newex:=cons(fa,newex)
           else newex:=cons(list('expt,fa,ep),newex)
  >>;
  if length newex=1 then car newex
                    else cons('times,newex)
 >>                                else ex
end$

symbolic procedure intsimplify_divide(fact_ex,xl)$
%  fact_ex is (list_of_factors . common_expt_of_the_factors)
%  if rekur then rekursive call of intsimplify
if pairp car fact_ex then
<<if cdr fact_ex then fact_ex:=     % there exists a common exponent
  for each s in car fact_ex collect % devide each factors exponent
  reval list('expt,cadr s,list('quotient,caddr s,cdr fact_ex))
                 else fact_ex:=car fact_ex$
  % fact_ex is now the list of factors !!!
  if pairp cdr fact_ex then cons('times,fact_ex)
                       else car fact_ex
>> else 0$

symbolic procedure simpli(p,vl);
begin
 scalar cp,k,kernl,diffr;
 if p then
 if atom p then if not freeof(vl,p) then kernl:=p
                                    else
           else <<
  if car p = 'plus then cp:=facsum p
                   else cp:=p;
  repeat <<
   k:=simpli(car cp,vl);
   cp:=cdr cp;
   if k then
   if not kernl then kernl:=k else
   if kernl neq k then diffr:=t;
  >>
  until (not cp) or diffr;
 >>;
 if diffr then kernl:=p;
 return kernl
end$

symbolic procedure intsimplify(q,xl)$
%  Simplification of the equation q=c, where c is arbitrarily
%  adjustable, but independent of the variable and function list xl
begin
  scalar q1,q2,p$
  if pairp q then <<
    q:=simpli(q,xl);
    if pairp q then
    if car q='expt then
      p:=reval intsimplify_divide(intsimplify_drop(list q,xl,0),xl)
    else if car q='times then
      p:=intsimplify_divide(intsimplify_drop(cdr q,xl,0),xl)
    else if car q='quotient then
    <<p:=list('quotient,facsum cadr q,facsum caddr q);
      if pairp cadr p and (caadr p='times) then q1:=cdadr p
                                           else q1:=list cadr p$
      if pairp caddr p and (caaddr p='times) then q2:=cdaddr p
                                             else q2:=list caddr p$
      q1:=intsimplify_drop(q1,xl,0)$
      q2:=intsimplify_drop(q2,xl,cdr q1)$
      q1:=cons(car q1,cdr q2)$
      p:=list('quotient,intsimplify_divide(q1,xl),
                        intsimplify_divide(q2,xl))
    >>
    else if car q='plus then p:=facsum q;
    if p and (p neq q) then q:=intsimplify(p,xl);
  >>;
  return q
end$

symbolic procedure independpart(g,ftem,vl)$
%  determines factors which can be get rid of
begin scalar l$
g:=cdr reval list('factorize,g)$
while g do
  <<if (pairp car g and (caar g='expt) and freeoflist(cadar g,vl))
       or member(car g,cdr g) or member(signchange(car g),ineq_)
       or not smemberl(ftem,car g)
    then l:=cons(car g,l)$
  g:=cdr g>>$
return if l then if cdr l then cons('times,l)
                          else car l
            else 1
end$

symbolic procedure solvesplit(q,ftem)$
begin scalar l$
   q:=list q$
   if length(ftem:=alldfs(car q,ftem))=1 then begin
      l:=cdr reval solveeval(list(car q,car ftem))$
      if length l>1 then
         q:=for each a in l collect reval
            if pairp caddr a and (caaddr a='root_of) then
               subst(cadr a,cadd caddr a,cadr caddr a)
            else list('plus,cadr a,list('minus,caddr a))$
   end$
return q$
end$

symbolic procedure splitde(p,ftem)$
begin scalar l$
    if pairp p and (car p='quotient) then p:=cadr p$
    for each x in cdr reval list('factorize,p) do
          if smemberl(ftem,x) then l:=cons(reval x,l)$
    l:=union(l,nil)$
    if solvealg_ then begin
       p:=nil$
       for each q in l do p:=union(solvesplit(q,ftem),p)$
       l:=p$
    end$
return if length l>1 then l
                     else nil
end$

symbolic procedure simplifyde(a,ftem,vl,genflag)$
begin scalar l,f,p$
ftem:=smemberl(ftem,a)$
if not contradiction(a,ftem)
   and (f:=fctchoose(list a,ftem)) then
   <<p:=reval algsimple(reval a,cons(f,delete(f,ftem)),vl)$
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
    if f=fo then list('equal,fo,ex)
            else if my_freeof(f,fo) then f
                                 else reval subst(ex,fo,f)>>$

symbolic procedure substandsep(g,sorg,ftem,vlist)$
%  in allen Gl. aus sorg wird die Fkt. car g durch cdr g ersetzt
begin scalar l,p,q,a$
while sorg do
    <<p:=car sorg$
    sorg:=cdr sorg$
    if my_freeof(p,cdr g) then l:=union(list p,l)
    else
        <<q:=reval subst(car g,cdr g,p)$
        contradiction(q,ftem)$
        if (ineq_:=ineqsubst(g,ftem)) then
          if pairp q then
             <<a:=gensep(q,smemberl(union(fnew_,ftem),q),vlist)$
             if contradiction_ then l:=sorg:=nil
                               else l:=union(list car a,l)>>
          else
             if q neq 0 then l:=union(list q,l)>>
    >>$
return l
end$

symbolic procedure fcteval(p,ftem,vl)$
begin
  if pairp p and (car p='quotient) then p:=cadr p$
  return
  if delength p>(if fcteval_ then fcteval_ else 0) then
     (if cont_ then
        if yesp("function to be evaluated ? ") then
              fcteval1(p,ftem,vl))
  else fcteval1(p,ftem,vl)
end$

symbolic procedure fcteval1(p,ftem,vl)$
begin scalar l,f,n,ft$
  ft:=smemberl(ftem,p)$
  n:=length varslist(p,ft,vl)$
  for each x in ft do
      if fctlength x>=n then
          <<l:=ldiffp(p,x)$
          if (null car l) and (cdr l=1) then
             if freeofzero(coeffn(p,x,1),delete(x,ft),vl) then f:=x>>$
  if f then
    p:=reval list('difference,f,list('quotient,p,coeffn(p,f,1)))$
return if f then cons(p,f)
            else nil$
end$

symbolic procedure freeofzero(p,ft,vl)$
%   gets p (factorized), if p not vanishes identically
if null ft then p
else
begin scalar a,b,fr,pri$
 pri:=print_$
 print_:=nil$
% terpri()$write "FREEOFZERO called with ineq_= ",ineq_$
 for each s in cdr reval list('factorize,p) do
    a:=union(list simplifyterm(s,ft),a)$
% terpri()$write "a= ",a$
 if length a>1 then p:=cons('times,a)$
 while a do
  if null smemberl(ft,car a) or member(car a,ineq_) then a:=cdr a
  else if pairp cdr (b:=separate(car a,ft,vl)) then
   <<fr:=nil$
   while b do
    if freeofzero(car b,ft,vl) then <<b:=nil$fr:=t>>
                               else b:=cdr b$
   if fr then a:=cdr a
         else <<a:=nil$p:=nil>> >>
  else <<a:=nil$p:=nil>>$
 print_:=pri$
return p
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
  if not (reval cons('max,n)<length fctargs cdr l) then l:=nil>>$
 return l$
end$

endmodule;


module utilts; %  Routines for finding leading derivatives and others.

%  Author: Andreas Brand
%  June 1990

symbolic procedure diffrel(p,q,v)$
%   liefert komplizierteren Differentialausdruck$
if diffrelp(p,q,v) then q
                   else p$

symbolic procedure diffrelp(p,q,v)$
%   liefert t, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
if cdr p='infinity then nil
else if cdr q='infinity then t
     else diffrelp1(p,q,v)$

symbolic procedure diffrelp1(p,q,v)$
if null v then                          %  alle Variable untersucht ?
   if cdr p>cdr q then nil
                  else t
else begin
        scalar a,b$
        a:=diffdeg(car p, car v)$       %  Ordnung der Ableitung nach
        b:=diffdeg(car q,car v)$        %  der ersten Variablen
        return if a<b then t
        else if b<a then nil
                else diffrelp1(p,q,cdr v) %  falls Ableitungen
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

symbolic procedure highdiff(p,f,x)$
%  hoechste Ableitung einer Funktion f nach der Variable x
%  in einem Ausdruck p
%  p,f in LISP-Notation, x Atom
diffdeg(car ldiffp1(p,f,list x),x)$

symbolic operator fargs$
symbolic procedure fargs f$
cons('list,fctargs f)$

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

symbolic procedure alldfs(p,ftem)$
if not pairp p then smemberl(ftem,p)
else if (car p='df) and member(cadr p,ftem) then list p
else union(alldfs(car p,ftem),alldfs(cdr p,ftem))$

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
if p=f then a:=cons(nil,1)
else
<<a:=cons(nil,0)$
if pairp p then
  if member(car p,'(plus times quotient equal)) then
     <<p:=cdr p$
       while p do
         <<a:=diffrel(ldiffp1(car p,f,vl),a,vl)$
           if cdr a='infinity then p:=nil
                              else p:=cdr p
         >>
     >>
   else if car p='minus then a:=ldiffp1(cadr p,f,vl)
   else if car p='expt then
     <<a:=ldiffp1(cadr p,f,vl)$         %  fuehrende Abl. aus der Basis
       if numberp cdr a then
         if numberp caddr p
         then a:=cons(car a,times(caddr p,cdr a))
         else if not zerop cdr a
           then a:=cons(nil,'infinity)
           else if not my_freeof(caddr p,f)
             then a:=cons(nil,'infinity)
     >>
   else if car p='df then
           if cadr p=f then a:=cons(cddr p,1)  %  f wird differenziert?
           else if my_freeof(cadr p,f)
                then a:=cons(nil,0)     %  sonst Konstante bzgl. f
                else a:=cons(nil,'infinity)
   else if my_freeof(p,f) then a:=cons(nil,0)
                       else a:=cons(nil,'infinity)
>>$
return a
end$

symbolic procedure lderiv(p,f,vl)$
%  fuehrende Ableitung in LISP-Notation ohne Potenz
%lderiv1(p,f,fctargs f)$
lderiv1(p,f,vl)$

symbolic procedure lderiv1(p,f,vl)$
%  fuerende Ableitung in LISP-Notation ohne Potenz
%  mit Angabe der Rangfolge der Variablen
begin scalar l$
l:=ldiffp1(p,f,vl)$
return if car l then cons('df,cons(f,car l))
                  else if zerop cdr l then nil
                                          else f
end$

symbolic procedure lderiv2(p,f,vl)$
%  fuehrende Ableitung in LISP-Notation mit Potenz (als dotted pair)
begin scalar l$
l:=ldiffp1(p,f,vl)$
return cons(if car l then cons('df,cons(f,car l))
                  else if zerop cdr l then nil
                          else f
                ,cdr l)
end$



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
return if s then if s='equal!= then     %  falls die Ausdruecke gleich
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
if minausdp1(cadr p,cddr p,cadr q,cddr q) then p
                                          else nil$

symbolic procedure minausdp1(l1,p1,l2,p2)$
%  liefert t, wenn der erste von zwei Differentialausdr. echt einfacher,
%  'EQUAL!=, wenn sie gleich schwierig sind, sonst nil
%  l1,l2 Listen der Ordnungen der Ableit., p1,p2 Potenzen
if null l1 then                 %  Ordnungen gleich ?
                        if p1=p2 then 'equal!=
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
cons('df,cons(f,cr_difflist(fctargs f,l)))$

symbolic procedure cr_difflist(v,l)$
%   erzeugt aus der Liste der Variablen und der Liste der Ordnungen der
%   Ableitungen eine Liste von Variablen + Ordnungen
if null v then nil
else if car l=0 then cr_difflist(cdr v,cdr l)
                                        %  Ordnung 0
        else if car l=1 then cons(car v,cr_difflist(cdr v,cdr l))
                                        %  bei Ordnung 1 wird Variable
                                        %  ohne Ordnung angehaengt
                else cons(car v,cons(car l,cr_difflist(cdr v,cdr l)))$

symbolic procedure delength(d)$
%   Laenge eines Polynoms in LISP - Notation
if not pairp d then if d then 1
                         else 0
else
if car d='plus then length(d)-1         %  Laenge in LISP ohne PLUS
else if car d='equal then delength(cadr d)+delength(caddr d)
else if car d='quotient then delength(cadr d)
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
      if car f='equal then
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
             else mathprint list('equal,a,b)
end$

symbolic procedure deprint(l)$
%   Ausdrucken der Gl. aus der Liste l
if l and print_ then for each x in l do eqprint(list('equal,0,x))$

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
                                     else my_freeof(e,v) $

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
  if not my_freeof(p,v) or member(v,ftem) then l:=cons(v,l)$
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
if my_freeof(l,car a) then cons(car a,cons(cadr a,l))
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
while ftem and a do
   if polyp1(p,car ftem) then ftem:=cdr ftem
                         else a:=nil$
return a
end$

symbolic procedure polynomtest(p,ftem)$
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
if my_freeof(p,f) then t
else
begin scalar a$
if atom p then a:=t
else
if member(car p,list('expt,'plus,'minus,'times,'quotient,'df)) then
                                        %  erlaubte Funktionen
        <<if (car p='plus) or (car p='times) then
                <<p:=cdr p$
                while p do
                    if a:=polyp1(car p,f) then p:=cdr p
                                         else p:=nil>>
        else if (car p='minus) then
                a:=polyp1(cadr p,f)
        else if (car p='quotient) then
                <<if my_freeof(caddr p,f) then a:=polyp1(cadr p,f)>>
        else if car p='expt then        %  Exponent
                <<if (fixp caddr p) then
                   if caddr p>0 then a:=polyp1(cadr p,f)>>
        else if car p='df then          %  Ableitung
                if (cadr p=f) or my_freeof(cadr p,f) then a:=t>>
else a:=(p=f)$
return a
end$

symbolic operator rationalexp$
symbolic procedure rationalexp(p,ftem)$
ratexp(p,cdr ftem)$

lisp flag('(rationalexp),'boolean)$

symbolic procedure rationaltest(p,ftem)$
begin scalar a$
a:=t$
while ftem do
   if ratexp1(p,car ftem) then ftem:=cdr ftem
   else
       <<terpri()$
       write "***** This equation is not a rational expr. w.r.t. "$
       write car ftem$write " and its derivatives : "$
       deprint(list p)$
       ftem:=nil$
       a:=nil>>$
return a
end$

symbolic procedure ratexp(p,ftem)$
if null ftem then t
             else if ratexp1(p,car ftem) then ratexp(p,cdr ftem)
                                         else nil$

symbolic procedure ratexp1(p,f)$
%  prueft, ob p f nur in rationaler Form enthaelt
if not pairp p or my_freeof(p,f) then t
else if car p='equal then ratexp1(cadr p,f) and ratexp1(caddr p,f)
else if car p='quotient then polyp1(cadr p,f) and polyp1(caddr p,f)
else polyp1(p,f)$

symbolic operator my_freeof$
symbolic procedure my_freeof(u,v)$
not(smember(v,u)) and freeofdepl(depl!*,u,v)$

lisp flag('(my_freeof),'boolean)$

symbolic procedure freeofdepl(de,u,v)$
if null de then t
else if smember(v,cdar de) and smember(caar de,u) then nil
else freeofdepl(cdr de,u,v)$

symbolic procedure freeoflist(l,m)$
%   liefert t, falls kein Element aus m in l auftritt
if null m then t
else if my_freeof(l,car m) then freeoflist(l,cdr m)
                        else nil$

symbolic procedure splitinhom(q,ftem,vl)$
% Splitting the equation q into the homogeneous and inhom. part
% returns dotted pair qhom . qinhom
begin scalar qhom,qinhom,denm;
  vl:=varslist(q,ftem,vl)$
  if pairp q and (car q = 'quotient) then
  if starp(smemberl(ftem,caddr q),vl) then
  <<denm:=caddr q; q:=cadr q>>        else return (q . 0)
                                     else denm:=1;

  if pairp q and (car q = 'plus) then q:=cdr q
                                 else q:=list q;
  while q do <<
   if starp(smemberl(ftem,car q),vl) then qinhom:=cons(car q,qinhom)
                                     else qhom  :=cons(car q,qhom);
   q:=cdr q
  >>;
  if null qinhom then qinhom:=0
                 else
  if length qinhom > 1 then qinhom:=cons('plus,qinhom)
                       else qinhom:=car qinhom;
  if null qhom then qhom:=0
               else
  if length qhom   > 1 then qhom:=cons('plus,qhom)
                       else qhom:=car qhom;
  if denm neq 1 then <<qhom  :=list('quotient,  qhom,denm);
                       qinhom:=list('quotient,qinhom,denm)>>;
  return qhom . qinhom
end$

symbolic procedure search_den(l)$
% get all denominators anywhere in a list l
if pairp l then
 if car l='quotient then union(cddr l,search_den(cdr l))
 else if member(car l,'(log ln logb log10)) then
  union(cdr l,search_den(cdr l))
 else union(search_den(car l),search_den(cdr l))$

symbolic procedure zero_den(l,ftem,vl)$
begin scalar l1$
 for each s in search_den(l) do
  if not freeofzero(s,ftem,vl) then l1:=cons(s,l1)$
return l1
end$

endmodule;


module simpsols;  % Routines for simplifying expressions by changing
                  % free functions and constants of integration.

%  Author: Thomas Wolf
%  Nov 1993

fluid '(factorize_ nfct_ print_);

symbolic operator dropredundant$

symbolic procedure dropredundant(ex,fl,vl)$
Comment
 All arguments are algebraic, ex is the list of expressions or
 equations from which the right side is taken, fl is the list of
 functions to be sorted out, vl the list of all extra independent
 variables, not already included in fl.
 returns algebraic list of redundant functions/const.=0, new EX, new FL;
begin scalar a;
 vl:=union(reverse argset cdr fl,cdr vl)$
 a:=dropredund(list(list(nil),cdr ex,cdr fl),vl);
 return if a then list('list,cons('list,car    a),
                             cons('list,caddr  a),
                             cons('list,cadddr a) )
             else nil
end$


symbolic procedure dropredund(a,vl);
begin
 scalar sol,arbit,fl,el1,el2,corres,b,condi,oldcon,printold,redund,
        flstart,fldrop$
 % a has the structure of one solution of CRACK in symbolic mode,
 % makes a copy of the free constants and functions in the solution
 % sets to zero the difference between the old solution and the new
 % with replaced constants and functions and finds the non-essential
 % returns  cons(list of redundant fnc./cons=0,new solution)
 if cadr  a then if length cadr  a > 0 then
 if caddr a then if length caddr a > 0 then <<
  printold:=print_;
  print_:=nil;
  sol:=for each el1 in cadr a collect
       if pairp el1 then if car el1 = 'equal then caddr el1
                                             else el1
                    else el1;
  b:=sol;
  arbit:=caddr a;
  for each el1 in arbit do
  if (not my_freeof(b,el1)) or (not my_freeof(car a,el1)) then <<
   flstart:=cons(el1,flstart);
   el2:=newfct(fname_,fctargs(el1),nfct_)$
   nfct_:=add1 nfct_$
   sol:=subst(el2,el1,sol);
   fl:=cons(el1,cons(el2,fl));
   corres:=cons((el1 . el2),corres);
  >>                                                else
  fldrop:=cons(el1,fldrop);
  while b do <<
   condi:=cons(reval list('plus,car b,list('minus,car sol)),condi);
   b:=cdr b;
   sol:=cdr sol
  >>;
  b:=car crack1(condi,nil,nil,fl,vl,factorize_,nil,nil);
  print_:=printold;
  if not car b then <<
   arbit:=caddr b;
   for each el1 in cadr b do
   if not((pairp el1) and
      (car el1 = 'equal)) then arbit:=cons(el1,arbit)$
   oldcon:=car a;
   sol:=cadr a;
   % the remaining essential free functions : flstart
   for each el1 in corres do
   if member(car el1,arbit) and member(cdr el1,arbit) then <<
    redund:=cons(list('equal,car el1,0),redund);
    fldrop:=cons(car el1,fldrop);
    % the function and its copy are both not essential
    oldcon:=for each el2 in oldcon collect reval subst(0,car el1,el2);
    sol:=for each el2 in sol collect reval subst(0,car el1,el2);
    flstart:=delete(car el1,flstart)
   >>;
  >>;
  if fldrop and printold then <<
   write"non-essential dropped constant(s) or function(s): ";
   fctprint fldrop
  >>$
  return
  if null fldrop then nil
                 else list(redund,oldcon,sol,flstart)
 >>
end$


algebraic procedure absorbconst(exlist,flist)$
% absorbing numerical factors into free constants/functions of flist
% if the list of expressions in exlist is known to be linear in flist
% returns an algebraic list of substitutions to be done
begin
  scalar e1,e2,n,n1,n2,sb;
  sb:={};
  for each e1 in flist do <<
    n1:=nil;
    for each e2 in exlist do <<
      n:=coeffn(e2,e1,1);
      if n neq 0 then <<
        n:=ncontent(n);
        if n1=nil then <<n1:=num n; n2:=den n>>
                  else <<
          n1:=gcd(n1,num(n));
          n2:=n2*den(n)/gcd(n2,den(n))
        >>
      >>
    >>;
    if n1 and ((n1 neq 1) or (n2 neq 1)) then
    sb:=cons(e1=e1*n2/n1 , sb)
  >>;
  return if sb={} then nil else sb
end$ % of absorbconst


algebraic procedure drop_const(oldsoln, varlist, additive)$

Comment
  oldsoln is the output of a CRACK call. In all solutions functions
  which are independent of all elements of varlist are dropped from
  the list of free functions/constants and
  - set to zero if additive=t and they are additive or
  - set to 1 if additive=nil and they are multiplicative;

begin
  scalar soln, sl, fncn, h1, h2, newfl, vcopy, constnt, v, fcopy,f1,co,
         mcdold;
  soln := {};
  mcdold:=lisp !*mcd$
  off mcd;
  while oldsoln neq {} do <<
    sl := first oldsoln; oldsoln := rest oldsoln;
    fncn := second sl;
    h1 := third sl;
    newfl:={};
    for each h2 in h1 do <<
              % is h2 constant ?
      vcopy := varlist;
      constnt := t;
      while constnt and (vcopy neq {}) do <<
        v := first vcopy; vcopy := rest vcopy;
        if not my_freeof(co,v) then constnt := nil
      >>;
      if constnt then
      if (not my_freeof(first sl, h2)) or my_freeof(fncn, h2)
      then constnt := nil;
      if constnt then <<
          % is the coefficient of h2 constant in all solved expressions
          % and occurs h2 only linear ?
        fcopy := fncn;
        while constnt and (fcopy neq {}) do <<
          f1 := rhs first fcopy; fcopy := rest fcopy;
          on mcd;
          co:=coeffn(f1,h2,1);
          if (not my_freeof(co,h2))                               or
             (     additive  and (not my_freeof(f1 - co*h2, h2))) or
             ((not additive) and ((f1 - co*h2) neq 0))
          then constnt := nil;
          off mcd;
          if constnt and additive then <<
            vcopy := varlist;
            while constnt and (vcopy neq {}) do <<
              v := first vcopy; vcopy := rest vcopy;
              if not my_freeof(co,v) then constnt := nil
            >>
          >>
        >>
      >>;
      if constnt then if additive then fncn := sub(h2=0, fncn)
                                  else fncn := sub(h2=1, fncn)
                 else newfl := cons(h2, newfl)
    >>;
    soln := cons({first sl, fncn, newfl}, soln)
  >>;
  if mcdold then on mcd;
  return soln
end$ % of drop_const


endmodule;


module intfix;  % Further fixes to the integration package.

load_package int$

% die folgende Aenderung verhindert das Erzeugen von int* ...

remd('simpint!*)$

symbolic procedure simpint!* u$
   begin scalar x$
      return if (x := opmtch('int . u)) then simp x
              else simpiden('int . u)
% statt       else simpiden('int!* . u)
   end$

setcrackflags()$

!*fullroots:=t$

% ein Patch fuer das REDUCE 3.5 EZGCD

%symbolic procedure simpexpt u$
%   % We suppress reordering during exponent evaluation, otherwise
%   % internal parts (as in e^(a*b)) can have wrong order.
%   begin scalar expon;
%      expon := simpexpon carx(cdr u,'expt) where kord!*=nil;
%      expon := resimp expon;  % We still need right order. <--- change.
%      return simpexpt1(car u,expon,nil)
%   end$

% Zum Integrieren

% put('int, 'simpfn, 'SimpIntPatch)$

algebraic <<
 let {
 int(1/~x^(~n),~x) => -x/(x^n*(n-1)) when numberp n,
     ~x^(~m/~n)*~x => x**((m+n)/n) when (numberp n and numberp m),
     int(~z/~y,~x) => log(y) when z = df(y,x)}$

 if sin(!%x)**2+cos(!%x)**2 neq 1 then
 let {sin(~x)**2 => 1-cos(x)**2}$

 if cosh(!%x)**2 neq (sinh(!%x)**2 + 1) then
 let {cosh(~x)**2 => (sinh(x)**2 + 1)}$

 if sin(!%x)*tan(!%x/2)+cos(!%x) neq 1 then
 let {tan(!%x/2) => (1-cos(!%x))/sin(!%x)}$

 if sin(!%x)*cot(!%x/2)-cos(!%x) neq 1 then
 let {cot(!%x/2) => (1+cos(!%x))/sin(!%x)}$

 if sqrt(!%x**2-!%y**2)-sqrt(!%x-!%y)*sqrt(!%x+!%y) neq 0 then
 let {sqrt(~x)*sqrt(~y) => sqrt(x*y)}
>>$

endmodule;


module dfint; % Patch to improve differentiation, mainly of integrals.
              % This version specifically for use by the crack package.

% Author: Francis J. Wright <F.J.Wright@QMW.ac.uk>
%       QMW, London and CBPF, Rio.
% Date: Thu Nov 19 21:11:12 1992
% Revised 12 April 1995 for REDUCE 3.6

switch allowdfint, dfint;
deflist('((allowdfint ((t (rmsubs)))) (dfint ((t (rmsubs))))), 'simpfg);
!*allowdfint := !*dfint := t;  rmsubs();

put('int, 'dfform, 'dfform_int);

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


% The remainder of this patch is included in the procedure diffp in
% module diff in the poly package in REDUCE 3.6.  But it currently
% still needs to be explicitly turned on:

fluid '(!*fjwflag);  !*fjwflag := t;

endmodule;


end;
