module antisubs;

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


exports antisubs;

imports interr,dependsp,setdiff;


symbolic procedure antisubs(place,x);
% Produces the inverse substitution to a substitution list.
begin
  scalar answer,w;
  while place and
        (x=caar place) do<<
    w:=cdar place;
    % w is the substitution rule.
    if atom w
      then if w neq x
        then interr "False atomic substitution"
        else nil
      else answer:=(x.anti2(w,x)).answer;
    place:=cdr place>>;
  if null answer
    then answer:=(x.x).answer;
  return answer
  end;


symbolic procedure anti2(eexpr,x);
%Produces the function inverse to the eexpr provided.
if atom eexpr
  then if eexpr eq x
    then x
    else interr "False atom"
  else if car eexpr eq 'plus
    then deplus(cdr eexpr,x)
    else if car eexpr eq 'minus
      then subst(list('minus,x),x,anti2(cadr eexpr,x))
      else if car eexpr eq 'quotient
        then if dependsp(cadr eexpr,x)
          then if dependsp(caddr eexpr,x)
            then interr "Complicated division"
            else subst(list('times,caddr eexpr,x),x,anti2(cadr eexpr,x))
          else if dependsp(caddr eexpr,x)
            then subst(list('quotient,cadr eexpr,x),x,
                       anti2(caddr eexpr,x))
            else interr "No division"
        else if car eexpr eq 'expt
          then if caddr eexpr iequal 2
            then subst(list('sqrt,x),x,anti2(cadr eexpr,x))
            else interr "Unknown root"
          else if car eexpr eq 'times
            then detimes(cdr eexpr,x)
            else if car eexpr eq 'difference
              then deplus(list(cadr eexpr,list('minus,caddr eexpr)),x)
              else interr "Unrecognised form in antisubs";



symbolic procedure detimes(p!-list,var);
% Copes with lists 'times.
begin
  scalar u,v;
  u:=deplist(p!-list,var);
  v:=setdiff(p!-list,u);
  if null v
    then v:=var
    else if null cdr v
      then v:=list('quotient,var,car v)
      else v:=list('quotient,var,'times.v);
  if (null u) or
     (cdr u)
    then interr "Weird multiplication";
  return subst(v,var,anti2(car u,var))
  end;


symbolic procedure deplist(p!-list,var);
% Returns a list of those elements of p!-list which depend on var.
if null p!-list
  then nil
  else if dependsp(car p!-list,var)
    then (car p!-list).deplist(cdr p!-list,var)
    else deplist(cdr p!-list,var);


symbolic procedure deplus(p!-list,var);
% Copes with lists 'plus.
begin
  scalar u,v;
  u:=deplist(p!-list,var);
  v:=setdiff(p!-list,u);
  if null v
    then v=var
    else if null cdr v
      then v:=list('plus,var,list('minus,car v))
      else v:=list('plus,var,list('minus,'plus.v));
  if (null u) or
     (cdr u)
    then interr "Weird addition";
  return subst(v,var,anti2(car u,var))
  end;

endmodule;

end;

