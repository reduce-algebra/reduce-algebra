module cde_tools; % CDIFF package, procedures of general utility

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% % *****************************************************************
% Author and maintainer: Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo
%
% Version and Date:  2.0, October 2015.
%
% ===============================================================

%
%-----------------------------------------------------------------------------%
% Module tools
%-----------------------------------------------------------------------------%
%
% Various utility procedures for working on lists.

symbolic procedure cde_alglistp(l);
% Check if l is an algebraic list
 (listp l) and ((car l) equal 'list);

symbolic procedure cde_mkset l;
% Comes from the procedure delete!-dups in sets.red, misc packages,
% by F.J. Wright.
   if l then
      if car l member cdr l then cde_mkset(cdr l)
      else car l . cde_mkset(cdr l);

symbolic operator cde_mkset;

symbolic procedure cde_list2id l;
% Comes from the procedure list_to_ids in genpurfn.red, assist package,
% by H. Caprasse.
   if atom l then rederr "argument for cde_list2id must be a list"
    else intern compress for each i in l join explode i;

symbolic procedure cde_mkzero n;
   for i:=1:n collect 0;

symbolic procedure clean_algebraic_list(l);
% Here l is an algebraic list in input;
% it must consist of algebraic identifiers.
begin scalar ll;
 if not(car l equal 'list) then
  rederr "Input of clean_algebraic_list is not an algebraic list";
 ll:=cdr l;
 return for each el in ll collect !*a2k el;
end;

%% symbolic procedure cde_replace_nth(l,ind,el);
%% % Replaces the ind element of the list l by el
%% begin scalar lenl;
%%    lenl:=length(l);
%%    return for i:=1:lenl collect if i=ind then el else nth(l,i)
%% end;

symbolic procedure cde_replace_nth(l,ind,el);
% Replaces the ind element of the list l by el, second version
   if l then if ind=1 then el . cdr l else
      car l . cde_replace_nth(cdr l,ind - 1,el);

symbolic procedure cde_delete(el,l);
% Deletes all instances of el from the list l
begin scalar dl;
   for each ell in l do if not(ell equal el) then dl:=ell . dl;
   return reversip dl
end;

symbolic procedure cde_insert(el,l,n);
% Inserts the element el in the list l at the n-th place.
begin scalar firstl; integer n;
  if not listp l then typerr(l,"must be a list") else
    if n<=0 then rederr("third argument must be a positive integer");
% Unwanted behaviour:
% else
%  if (n:=n+1) > length l then return append(l,list el);
  for i:=1:n-1 do <<firstl:=car l . firstl; l:=cdr l>>;
  return append(reversip firstl,el . l)
end;

symbolic procedure cde_diffset(set,rem);
% Removes the subset rem from the set set
   if not rem then set else cde_diffset(cde_delete(car rem,set),cdr rem);

symbolic procedure cde_lassoc(el,l);
% Like assoc, but on the second element.
   if not l then nil
      else if atom car l then rederr "Error: bad alist"
      else if el equal cadar l then car l
      else cde_lassoc(el,cdr l);

symbolic procedure cde_lassoc2(el,l);
% Like cde_lassoc, but it works when the second element
% of the alist pair is a list.
   if not l then nil
      else if atom car l then rederr "Error: bad alist"
      else if el equal cdar l then car l
      else cde_lassoc2(el,cdr l);

symbolic procedure cde_position(el,l);
% If el is in l then counts its position; returns 0 in other case.
  if member(el,l) then cde_position2(el,l) else 0;

symbolic procedure cde_position2(el,l);
% Finds the integer representing the position of el into l;
% does not check the presence of el in l beforehand!
  if equal(el,car l) then 1 else 1+cde_position2(el,cdr l);

symbolic procedure cde_sublis(l,n);
% Takes the first n elements of a list l
  if eqn(n,0) then nil else cons(car l,cde_sublis(cdr l,n-1));

% Some functions taken from the package crack, renamed in order
% to avoid name clashes

% Remember: the procedure smember(u,v) checks for a sexp u
% if it is present in v at any level. Defined in alg/general.red

symbolic procedure cde_memberl(a,b);
%  member for a list; checks if elements of a are in b
  if a and b then
  if member(car a,b) then cons(car a,cde_memberl(cdr a,b))
  else cde_memberl(cdr a,b);

symbolic procedure cde_freeof(u,v);
%  a patch for FREEOF in REDUCE 3.5 including functional dependencies
  not(smember(v,u)) and cde_freeofdepl(depl!*,u,v);

lisp flag('(my_freeof),'boolean);

symbolic operator cde_freeof;

symbolic procedure cde_freeofl(l,m);
% freeof for a list; checks if l is free of elements in m.
  if null m then t
  else if cde_freeof(l,car m) then cde_freeofl(l,cdr m)
  else nil;

symbolic operator cde_freeofl;

symbolic procedure cde_freeofdepl(de,u,v);
% Checks if the list de, which is a list of the type list(values of v) . v,
% (usually the list of dependencies depl!*)
% is free of a certain variable u
  if null de then t
  else if smember(v,cdar de) and smember(caar de,u) then nil
  else cde_freeofdepl(cdr de,u,v);

% End of crack procedures.

symbolic procedure cde_dependon(l,v);
% Checking if the expression l depends on a given variable v.
  if null v then nil else not(cde_freeof(l,v));

symbolic operator cde_dependon;

symbolic procedure cde_dependonl(l,d);
% Collecting variables (out of a given list d)
% on which a given expression l depend.
  if null d then nil
  else if cde_dependon(l,car d) then cons(car d,cde_dependonl(l,cdr d))
  else cde_dependonl(l,cdr d);

symbolic operator cde_dependonl;

%% symbolic procedure cde_pair(l1,l2);
%% % Making an alist
%% if and(l1,l2) then (car l1 . {car l2}) . cde_pair(cdr l1,cdr l2)
%%  else if or(l1,l2) then rederr "Error: lists must have the same length"
%%   else nil;

symbolic procedure ev_operator2(op_name,l_arg);
% Evaluates a scalar operator with n arguments on a list of n normalized counts;
% returns the corresponding coefficient.
% NOTE: no checking on arguments, please check args before using it!
begin
   if atom l_arg then return op_name . (list l_arg)
   else return op_name . cdr l_arg;
end;

symbolic procedure cde_forall_form(opname,lpars,lfvars,rhs_opdef);
  % Given a list of indices lpars:=(j,i1,i2,...)
  % and a list of free variables lfvars:=(phi1,phi2,...)
  % and an operator name opname
  % create a list u such that the evaluation of forall u
  % will be the same as the evaluation of the algebraic statement
  % for all phi1,phi2,... let opname(phi1,phi2,...)=rhs_opdef;
    'list . list(mkquote(lfvars),mkquote('t),
	    mkquote(list('let00,mkquote list list('equal,
	      opname . append(lpars,lfvars),rhs_opdef))));

symbolic procedure cde_ev_forall u;
  % This evaluates the list u created by cde_forall_form
  eval list('forall,u);

symbolic procedure check_letop(list_expr);
  % Check if in an expression or a list of expressions
  % there is a dependency on the variable `letop'.
  if not(freeof(list_expr,'letop)) then
    rederr "Presence of letop, jetspace too small!";

symbolic operator check_letop;

symbolic procedure cde_tools();
% This is a place for possible initialization routines.
   nil;

endmodule;

end;
