module places;

% Author: James H. Davenport.

fluid '(basic!-listofallsqrts
        basic!-listofnewsqrts
        intvar
        listofallsqrts
        listofnewsqrts
        sqrt!-intvar
        sqrt!-places!-alist
        sqrts!-in!-integrand);

exports getsqrtsfromplaces,sqrtsinplaces,get!-correct!-sqrts,basicplace,
        extenplace,equalplace,printplace;



% Function to manipulate places
% a place is stored as a list of substitutions
% substitutions (x.f(x)) define the algrbraic number
% of which this place is an extension,
% while places (f(x).g(x)) define the extension.
%    currently g(x( is list ('minus,f(x))
%       or similar,e.g. (sqrt(sqrt x)).(sqrt(-sqrt x)).

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




% Given a list of places, produces a list of all
% the SQRTs in it that depend on INTVAR.
symbolic procedure getsqrtsfromplaces places;
  % The following loop finds all the SQRTs for a basis,
  % taking account of BASICPLACEs.
begin
  scalar basis,v,b,c,vv;
  for each u in places do <<
    v:=antisubs(basicplace u,intvar);
    vv:=sqrtsinsq (substitutesq(!*kk2q intvar,v),intvar);
      % We must go via SUBSTITUTESQ to get parallel
      % substitutions performed correctly.
    if vv
      then vv:=simp argof car vv;
    for each w in extenplace u do <<
      b:=substitutesq(simp lsubs w,v);
      b:=delete(sqrt!-intvar,sqrtsinsq(b,intvar));
      for each u in b do
        for each v in delete(u,b) do
          if dependsp(v,u)
            then b:=delete(u,b);
            % remove all the "inner" items, since they will
            % be accounted for anyway.
      if length b iequal 1
        then b:=car b
 else b:=mvar numr simpsqrtsq mapply(function !*multsq,
                                for each u in b collect simp argof u);
      if vv and not (b member sqrts!-in!-integrand)
        then <<
          c:=numr multsq(simp argof b,vv);
          c:=car sqrtsinsf(simpsqrt2 c,nil,intvar);
   if c member sqrts!-in!-integrand
            then b:=c >>;
      if not (b member basis)
        then basis:=b.basis >> >>;
  % The following loop deals with the annoying case of, say,
  % (X DIFFERENCE X 1) (X EXPT X 2) which should give rise to
  % SQRT(X-1).
  for each u in places do begin
    v:=cdr u;
    if null v or (car rfirstsubs v neq 'expt)
      then return;
    u:=simp!* subst(list('minus,intvar),intvar,rfirstsubs u);
    while v and (car rfirstsubs v eq 'expt) do <<
      u:=simpsqrtsq u;
      v:=cdr v;
      basis:=union(basis,delete(sqrt!-intvar,sqrtsinsq(u,intvar))) >>
    end;
  return remove!-extra!-sqrts basis
  end;



symbolic procedure sqrtsinplaces u;
% Note the difference between this procedure and
% the previous one: this one does not take account
% of the BASICPLACE component (& is pretty useless).
if null u
  then nil
  else sqrtsintree(for each v in car u collect lsubs v,
                   intvar,
                   sqrtsinplaces cdr u);



%symbolic procedure placesindiv places;
% Given a list of places (i.e. a divisor),
% produces a list of all the SQRTs on which the places
% explicitly depend.
%begin scalar v;
%  for each u in places do
%    for each uu in u do
%      if not (lsubs uu member v)
%        then v:=(lsubs uu) . v;
%  return v
%  end;



symbolic procedure get!-correct!-sqrts u;
% u is a basicplace.
begin
  scalar v;
  v:=assoc(u,sqrt!-places!-alist);
  if v
    then <<
      v:=cdr v;
      listofallsqrts:=cdr v;
      listofnewsqrts:=car v
      >>
    else <<
      listofnewsqrts:=basic!-listofnewsqrts;
      listofallsqrts:=basic!-listofallsqrts
      >>;
  return nil
  end;



%symbolic procedure change!-place(old,new);
%% old and new are basicplaces;
%begin
%  scalar v;
%  v:=assoc(new,sqrt!-places!-alist);
%  if v
%    then sqrtsave(cddr v,cadr v,old)
%    else <<
%      listofnewsqrts:=basic!-listofnewsqrts;
%      listofallsqrts:=basic!-listofallsqrts
%      >>;
%  return nil
%  end;



symbolic procedure basicplace(u);
% Returns the basic part of a place.
if null u
  then nil
  else if atom caar u
    then (car u).basicplace cdr u
    else nil;



symbolic procedure extenplace(u);
% Returns the extension part of a place.
if u and atom caar u
  then extenplace cdr u
  else u;



symbolic procedure equalplace(a,b);
% Sees if two extension places represent the same place or not.
if null a
  then if null b
    then t
    else nil
  else if null b
    then nil
    else if member(car a,b)
      then equalplace(cdr a,delete(car a,b))
      else nil;



symbolic procedure remove!-extra!-sqrts basis;
begin
  scalar basis2,save;
  save:=basis2:=for each u in basis collect !*q2f simp argof u;
  for each u in basis2 do
    for each v in delete(u,basis2) do
      if quotf(v,u)
        then basis2:=delete(v,basis2);
  if basis2 eq save
    then return basis
    else return for each u in basis2 collect list('sqrt,prepf u)
  end;



symbolic procedure printplace u;
begin
  scalar a,n,v;
  a:=rfirstsubs u;
  princ (v:=lfirstsubs u);
  princ "=";
  if atom a
    then princ "0"
    else if (car a eq 'quotient) and (cadr a=1)
      then princ "infinity"
      else <<
 n:=negsq addsq(!*kk2q v,negsq simp!* a);
% NEGSQ added JHD 22.3.87 - the previous value was wrong.
% If the substitution is (X-v) then this takes -v to 0,
% so the place was at -v.
        if (numberp numr n) and (numberp denr n)
          then <<
            princ numr n;
            if not onep denr n
              then <<
                princ " / ";
                princ denr n >> >>
          else <<
            if degreein(numr n,intvar) > 1
             then printc "Any root of:";
            printsq n;
            if cdr u
              then princ "at the place " >> >>;
  u:=cdr u;
  if null u
    then goto nl!-return;
  n:=1;
  while u and (car rfirstsubs u eq 'expt) do <<
    n:=n * caddr rfirstsubs u;
    u:=cdr u >>;
  if n neq 1 then <<
    terpri!* nil;
    prin2 " ";
    princ v;
    princ "=>";
    princ v;
    princ "**";
    princ n >>;
  while u do <<
    if car rfirstsubs u eq 'minus
      then princ "-"
      else princ "+";
    u:=cdr u >>;
nl!-return:
  terpri();
  return
  end;



symbolic procedure degreein(sf,var);
if atom sf
  then 0
  else if mvar sf eq var
    then ldeg sf
    else max(degreein(lc sf,var),degreein(red sf,var));

endmodule;

end;

