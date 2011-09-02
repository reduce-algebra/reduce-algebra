%********************************************************************
module simpsolution$
%********************************************************************
%  Routines for simplifying expressions by changing free functions
%  and constants of integration
%  Author: Thomas Wolf
%  Nov 1993
%
% $Id: crsimpso.red,v 1.6 1998/06/04 15:05:13 tw Exp tw $
%


symbolic operator dropredundant$

symbolic procedure dropredundant(ex,fl,vl,unequ)$
comment
 All arguments are algebraic, ex is the list of expressions or
 equations from which the right side is taken, fl is the list of
 functions to be sorted out, vl the list of all extra independent variables,
 not already included in fl.
 returns algebraic list of redundant functions/const.=0, new EX, new FL;
begin scalar a;
 vl:=union(reverse argset cdr fl,cdr vl)$
 a:=dropredund(list(list(nil),cdr ex,cdr fl,cdr unequ),nil,vl);
 return if a then list('LIST,cons('LIST,car    a),
			     cons('LIST,caddr  a),
			     cons('LIST,cadddr a) )
	     else nil
end$

symbolic procedure dropredund(a,nofl,vl);
begin
 scalar sol,arbit,fl,el1,el2,el3,corres,b,b1,b2,condi,oldcon,
        printold,redund,flstart,fldrop,flnew,newfu,fnew_,
        newcorres,unequ,vlf,vla,potold,newnewfu,todelete;
 % a has the structure of one solution of CRACK in symbolic mode,
 % makes a copy of the free constants and functions in the solution
 % nofl is a list of functions not to be modified or dropped
 % sets to zero the difference between the old solution and the new
 % with replaced constants and functions and finds the non-essential
 % returns  cons(list of redundant fnc./cons=0,new solution)
 if cadr  a then if length cadr  a > 0 then
 if caddr a then if length caddr a > 0 then <<
  printold:=print_;
  print_:=nil;
  for each el1 in append(car a,cadr a) do
  if el1 then b1:=cons(if pairp el1 then 
                       if car el1 = 'EQUAL then caddr el1
                                           else el1
		                    else el1             ,b1);
  % b1 is the list of expressions to be invariant
  b2:=b1;

  % arbit is the list of original free functions in the input solution
  arbit:=caddr a;

  % flstart is the list of functions which can be gauged and which
  %         turn up in the invariant expressions including the
  %         duplicates of these functions
  % fldrop  is the list of functions which can be dropped and do not
  %         turn up
  % todelete is a list of all new duplicate-functions
  % b2      is a duplicate of the list of invariant expressions b1
  % flnew   is a duplicate of todelete
  % fl      is the list of all functions
  % corres  is a list of correspondences of functions and their dupl.
  for each el1 in arbit do 
  if freeof(nofl,el1) then 
  if not my_freeof(b1,el1) then <<
   flstart:=cons(el1,flstart);
   el2:=newfct(fname_,fctargs(el1),nfct_)$
   todelete:=cons(el2,todelete);
   nfct_:=add1 nfct_$
   b2:=subst(el2,el1,b2);
   flnew:=cons(el2,flnew);
   fl:=cons(el1,cons(el2,fl));
   corres:=cons((el1 . el2),corres);
  >>                       else
  fldrop:=cons(el1,fldrop);

  % condi is the set of conditions: difference of related expressions=0
  while b1 do <<
   condi:=cons(reval list('PLUS,car b1,list('MINUS,car b2)),condi);
   b1:=cdr b1;
   b2:=cdr b2
  >>;
  b1:=0;b2:=0;
  fnew_:=nil;
  potold:=potint_;
  potint_:=nil;
  orderings_:=mkvect(1)$
  putv(orderings_,0,list(vl,fl,'default_ordering_function))$
  b:=crackmain(mkeqlist(condi,fl,vl,allflags_,t,orderings_prop_list_all()),
                        nil,fl,vl);

  while b and cadddr car b do b:=cdr b; % a solution without inequalities
  if null b then return nil
            else b:=car b;
  print_:=printold;
  potint_:=potold;
  if not car b then <<    % if no equations remain to be solved
   arbit:=caddr b;        % arbit are the free functions of the CRACK run
                          % newfu are the solved functions
   for each el1 in cadr b do
   if not((pairp el1       ) and
          (car el1 = 'EQUAL)     ) then arbit:=cons(el1,arbit)
                                   else newfu:=cons(el1,newfu)$
   oldcon:=car a;
   sol:=cadr a;
   unequ:=cadddr a;

   % flstart are the remaining essential free functions
   % redund are the functions to be dropped, they are set to 0 in
   % the old solution
   for each el1 in corres do
   if member(car el1,arbit) and member(cdr el1,arbit) then <<
    redund:=cons(list('EQUAL,car el1,0),redund);
    fldrop:=cons(car el1,fldrop);
    % the function and its copy are both not essential
    oldcon:=for each el2 in oldcon collect reval subst(0,car el1,el2);
    sol:=for each el2 in sol collect reval subst(0,car el1,el2);
    unequ:=for each el2 in unequ collect reval subst(0,car el1,el2);
    arbit:=delete(car el1,arbit);
    arbit:=delete(cdr el1,arbit);
    fl:=delete(car el1,fl);
    fl:=delete(cdr el1,fl);
    flstart:=delete(car el1,flstart);
    flnew:=delete(cdr el1,flnew);    
    newfu:=subst(0,car el1,newfu);
    newfu:=subst(0,cdr el1,newfu);
   >>                                                 else
   newcorres:=cons(el1,newcorres);

   % Eliminate from all equations the flnew function in terms of
   % the corresponding flstart function and possibly other terms
   % newnewfu becomes a list of substitutions of new functions
   % by expressions in old functions.
   while newfu do <<
    el1:=car newfu; % el1: evaluated function = expression
    el2:=cadr el1;  % el2: evaluated function
    b:=newcorres;   % the remaining correspondences
    while b and (el2 neq cdar b) do b:=cdr b;
    if b then       % el2 = cdar b is a new function 
    if (not freeof(el1,caar b)) then newnewfu:=cons(el1,newnewfu)
                                else <<
     % The right hand side ex1 of equation el1: el2=ex1 does not 
     % contain the old function, say f, which corresponds to the 
     % new function el2
     % --> search for an equation car el3 in newfu of the form 
     % f = ex2, then add el2=ex1+f-ex2 to newnewfu
     el3:=newfu;
     while el3 and (cadar el3 neq caar b) do el3:=cdr el3;
     if el3 then <<
      newnewfu:=cons(list('EQUAL,el2,list('PLUS,caddr el1,cadar el3,
                                          list('MINUS,caddar el3)     )),
                     newnewfu);
      newfu:=delete(car el3,newfu)
     >>     else newnewfu:=nil;  % means later that it can not be treated
    >>   else <<    % el2 is an old function 
     % like in the case above, only that in order to add equations of
     % the form new_fct = expr in old_fcts can be added to newnewfu,
     % the equations has to be solved for new_fct
     b:=newcorres;  % the correspondences of the remaining functions
     while el2 neq caar b do b:=cdr b; % caar b is now el2 (old function)
     if (not freeof(el1,cdar b)) then  % image function of el2 is in el1
     % solving el1 for the image function cdar b of el2
     newnewfu:=cons(list('EQUAL,cdar b,list('PLUS,cdar b,el2,
                                            list('MINUS,caddr el1))
                        ),newnewfu)
                                 else <<
      % add an equ. to el1 with (the pri-image function of el2) = ...
      el3:=newfu;
      while el3 and (cadar el3 neq cdar b) do el3:=cdr el3;
      if el3 then <<
       newnewfu:=cons(list('EQUAL,cdar b,
                           list('PLUS,caddar el3,cadr el1,
                                list('MINUS,caddr el1)      )),
                      newnewfu);
       newfu:=delete(car el3,newfu)
      >>     else newnewfu:=nil;  % means later that it can not be treated
     >>    
    >>;
    newfu:=cdr newfu
   >>;
   newfu:=newnewfu;
   
   % test, whether each new function has exactly one substitution
   % and no new function appears on a rhs
   if length flnew = length newfu then 
   while newnewfu and freeoflist(caddar newnewfu,flnew) do 
   newnewfu:=cdr newnewfu;
   
   if newfu and (not newnewfu) then <<  
    % now the conditions have really been solved for the new 
    % functions, no new function is on the rhs

    % arbit are all free old and new functions after the above CRACK-run
    % fl are all functions at the start of the above CRACK-run
    % flnew are all remaining new functions
    % flstart are all the old functions
    % new arbit: all functions which came in only through the
    %            last CRACK run
    arbit:=setdiff(setdiff(union(arbit,fl),flnew),flstart);

    % rewriting the substitutions as: old fct = expr in old fcts
    newfu:=
    for each el1 in newfu collect <<
     b:=cadr el1;     % b is a new function
     el2:=newcorres;  % caar el2 the corresponding old function
     while b neq cdar el2 do el2:=cdr el2; 
     list('EQUAL,caar el2,caddr el1)
    >>;

    % Specifying the functions in arbit which are free to get as many
    % as possible functions flstart to zero
    arbit:=fctsort(arbit)$  % to use the functions with most variables first
    for each el1 in arbit do <<
     vla:=fctargs el1; % variables of the function to be eliminated
     el2:=newfu;
     while el2 do 
     if freeof(car el2,el1) then el2:=cdr el2
                            else <<
      vlf:=fctargs cadar el2;
      if (null not_included(vla,vlf)) and
         (null not_included(vlf,vla)) then <<
       % cadar el2 is a function that shall be made to zero
       % by a choice for el1

       % It is checked whether the arbitrary function el1 occurs only
       % linearly algebraically, so that it can be computed by
       % solving equation car el2
       b:=lderiv2(caddar el2,el1,vla);
       if cdr b=1 then << % success!! cadar el2 can be set to zero!
        if car b neq el1 then <<terpri()$
         write" It is assumed that the equation:";terpri()$
         deprint cddar el2 ;
         write" has always a solution in ",el1;terpri()$
         write" functions: ";
         el3:=append(flstart,arbit); 
         b:=nil;
         while el3 do <<
          if not freeof(cddar el2,car el3) then fctprint list car el3;
          el3:=cdr el3
         >>;
        >>;
        redund:=cons(list('EQUAL,cadar el2,0),redund);
        fldrop:=cons(cadar el2,fldrop);
        oldcon:=for each el3 in oldcon collect reval subst(0,cadar el2,el3);
        sol:=for each el3 in sol collect reval subst(0,cadar el2,el3);
        unequ:=for each el3 in unequ collect reval subst(0,cadar el2,el3);
        flstart:=delete(cadar el2,flstart);
        newfu:=delete(car el2,newfu);     
        el2:=nil;
       >>
      >>;
      if el2 then el2:=cdr el2
     >>
    >>;

    % substituting all remaining functions arbit in the substitutions 
    % newfu to zero which are not already specified
    for each el1 in arbit do newfu:=subst(0,el1,newfu);
   >> 
  >>;
  if fldrop and printold then <<
   write"non-essential dropped constant(s) or function(s): ";
   fctprint fldrop
  >>$
  for each el1 in append(todelete,fldrop) do 
  depl!*:=delete(assoc(el1,depl!*),depl!*)$
  return
  if null fldrop then nil
		 else list(redund,oldcon,sol,flstart,unequ)
 >>
end$

symbolic operator ncontent$
symbolic procedure ncontent p$
% Return numeric content of expression p
% based on simpnprimitive in ezgcd.
<< p := simp!* p;
%   if polyzerop(numr p) then 0 else
   if p=('NIL . 1) then 0 else
   mk!*sq(numeric!-content numr p ./ numeric!-content denr p)
>>$

algebraic procedure absorbconst(exlist,flist)$
% absorbing numerical factors into free constants/functions of flist
% if the list of expressions in exlist is known to be linear in flist
% returns an algebraic list of substitutions to be done
begin
  scalar e1,e2,n,n1,n2,nu,sb,cs1,cs2;
  sb:={};
  for each e1 in flist do <<
    n1:=nil;
    % to make a change of sign at least one equation 
    % must demand it which is cs1=t
    % and no equation must forbit it which is cs2=nil
    cs1:=nil; cs2:=t;
    for each e2 in exlist do <<
      n:=coeffn(e2,e1,1);
      if n neq 0 then <<
	% if at least one equation does not demand a change of
	% sign then no change of sign is made

        if (numberp n) and (n<0) then cs1:=t
                                 else
	if lisp pairp reval algebraic n then <<
	  if part(n,0)='MINUS then cs1:=t 
			      else
	  if part(n,0)='QUOTIENT then
          <<nu:=part(n,1);
            if lisp( pairp reval algebraic nu) and 
               (part(nu,0)='MINUS) then cs1:=t 
                                   else
            if (numberp nu) and (nu<0) then cs1:=t
                                       else cs2:=nil
          >>                     else cs2:=nil
	>>;
	n:=ncontent(n);
	if n1=nil then <<n1:=num n; n2:=den n>>
		  else <<
	  n1:=gcd(n1,num(n));
	  n2:=n2*den(n)/gcd(n2,den(n))
	>>
      >>
    >>;
    if n1 and ((n1 neq 1) or (n2 neq 1)) then <<
      if cs1 and cs2 then n2:=-n2;
      sb:=cons(e1=e1*n2/n1 , sb);
    >>                                   else
    if cs1 and cs2 then sb:=cons(e1=-e1, sb);
  >>;
  return if sb={} then nil else sb
end$ % of absorbconst

algebraic procedure drop_const(oldsoln, vars, additive)$
comment
  oldsoln is the output of a CRACK call. In all solutions functions
  which are independent of all elements of vars are dropped from
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
      vcopy := vars;
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
	    vcopy := vars;
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


endmodule$

end$
