MODULE HACKSQRT;  % Routines for manipulation of sqrt expressions.

% Author: James H. Davenport.

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


fluid '(nestedsqrts thisplace);

exports sqrtsintree,sqrtsinsq,sqrtsinsql,sqrtsinsf,sqrtsign;
exports degreenest,sortsqrts;

imports mkvect,interr,getv,dependsp,union;

symbolic procedure sqrtsintree(u,var,slist);
% Adds to slist all the sqrts in the prefix-type tree u.
if atom u
  then slist
  else if car u eq '!*sq
    then union(slist,sqrtsinsq(cadr u,var))
    else if car u eq 'sqrt
      then if dependsp(argof u,var)
        then <<
          slist:=sqrtsintree(argof u,var,slist);
          %  nested square roots
          if member(u,slist)
            then slist
            else u.slist >>
        else slist
      else sqrtsintree(car u,var,sqrtsintree(cdr u,var,slist));


symbolic procedure sqrtsinsq(u,var);
   % Returns list of all sqrts in sq.
   sqrtsinsf(denr u,sqrtsinsf(numr u,nil,var),var);


symbolic procedure sqrtsinsql(u,var);
% Returns list of all sqrts in sq list.
if null u
  then nil
  else sqrtsinsf(denr car u,
      sqrtsinsf(numr car u,sqrtsinsql(cdr u,var),var),var);


symbolic procedure sqrtsinsf(u,slist,var);
% Adds to slist all the sqrts in sf.
if domainp u or null u
  then slist
  else <<
    if  eqcar(mvar u,'sqrt) and
        dependsp(argof mvar u,var) and
        not member(mvar u,slist)
      then begin
        scalar slist2;
        slist2:=sqrtsintree(argof mvar u,var,nil);
        if slist2
          then <<
            nestedsqrts:=t;
            slist:=union(slist2,slist) >>;
        slist:=(mvar u).slist
        end;
    sqrtsinsf(lc u,sqrtsinsf(red u,slist,var),var) >>;


symbolic procedure easysqrtsign(slist,things);
% This procedure builds a list of all substitutions for all possible
% combinations of square roots in list.
if null slist
  then things
  else easysqrtsign(cdr slist,
                    nconc(mapcons(things,(car slist).(car slist)),
                          mapcons(things,
                                  list(car slist,'minus,car slist))));

symbolic procedure hardsqrtsign(slist,things);
% This procedure fulfils the same role for nested sqrts
% ***assumption: the simpler sqrts come further up the list.
if null slist
  then things
  else begin
    scalar thisplace,answers,pos,neg;
    thisplace:=car slist;
    answers:= for each u in things collect sublis(u,thisplace) . u;
    pos := for each u in answers collect (thisplace . car u) . cdr u;
    % pos is sqrt(f) -> sqrt(innersubst f)
    neg := for each u in answers
       collect {thisplace,'minus,car u} . cdr u;
    % neg is sqrt(f) -> -sqrt(innersubst f)
    return hardsqrtsign(cdr slist,nconc(pos,neg))
    end;


symbolic procedure degreenest(pf,var);
% Returns the maximum degree of nesting of var
% inside sqrts in the prefix form pf.
if atom pf
  then 0
  else if car pf eq 'sqrt
    then if dependsp(cadr pf,var)
      then iadd1 degreenest(cadr pf,var)
      else 0
    else if car pf eq 'expt
      then if dependsp(cadr pf,var)
        then if eqcar(caddr pf,'quotient)
          then iadd1 degreenest(cadr pf,var)
          else degreenest(cadr pf,var)
        else 0
      else degreenestl(cdr pf,var);

symbolic procedure degreenestl(u,var);
%Returns max degreenest from list of pfs u.
if null u
  then 0
  else max(degreenest(car u,var),
           degreenestl(cdr u,var));


symbolic procedure sortsqrts(u,var);
% Sorts list of sqrts into order required by hardsqrtsign
% (and many other parts of the package).
begin
  scalar i,v;
  v:=mkvect(10); %should be good enough!
  while u do <<
    i:=degreenest(car u,var);
    if i iequal 0
      then interr "Non-dependent sqrt found";
    if i > 10
      then interr
         "Degree of nesting exceeds 10 (recompile with 10 increased)";
    putv(v,i,(car u).getv(v,i));
    u:=cdr u >>;
  u:=getv(v,10);
  for i :=9 step -1 until 1 do
    u:=nconc(getv(v,i),u);
  return u
  end;


symbolic procedure sqrtsign(sqrts,x);
   if nestedsqrts then hardsqrtsign(sortsqrts(sqrts,x),list nil)
    else easysqrtsign(sqrts,list nil);

endmodule;

end;


