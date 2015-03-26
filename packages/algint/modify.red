module modify;

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


fluid '(!*tra intvar);

exports modify!-sqrts,combine!-sqrts;

symbolic procedure modify!-sqrts(basis,sqrtl);
begin
  scalar sqrtl!-in!-sf,n,u,v,f;
  n:=upbv basis;
  sqrtl!-in!-sf:=for each u in sqrtl collect
                    !*q2f simp argof u;
  for i:=0:n do begin
    u:=getv(basis,i);
    v:=sqrtsinsq(u,intvar);
    % We have two tasks to perform,
    % the replacing of SQRT(A)*SQRT(B) by SQRT(A*B)
    % where relevant and the replacing of SQRT(A)
    % by SQRT(A*B) or 1 (depending on whether it occurs in
    % the numerator or the denominator).
    v:=setdiff(v,sqrtl);
    if null v
      then go to nochange;
    u:=sqrt2top u;
    u:=multsq(modify2(numr u,v,sqrtl!-in!-sf) ./ 1,
              1 ./ modify2(denr u,v,sqrtl!-in!-sf));
    v:=sqrtsinsq(u,intvar);
    v:=setdiff(v,sqrtl);
    if v then <<
      if !*tra then <<
        printc "Discarding element";
        printsq u >>;
      putv(basis,i,1 ./ 1) >>
      else putv(basis,i,removecmsq u);
    f:=t;
  nochange:
    end;
  basis:=mkuniquevect basis;
  if f and !*tra then <<
    printc "Basis replaced by";
    mapvec(basis,function printsq) >>;
  return basis
  end;


symbolic procedure combine!-sqrts(basis,sqrtl);
begin
  scalar sqrtl!-in!-sf,n,u,v,f;
  n:=upbv basis;
  sqrtl!-in!-sf:=for each u in sqrtl collect
                    !*q2f simp argof u;
  for i:=0:n do begin
    u:=getv(basis,i);
    v:=sqrtsinsq(u,intvar);
    % We have one task to perform,
    % the replacing of SQRT(A)*SQRT(B) by SQRT(A*B)
    % where relevant.
    v:=setdiff(v,sqrtl);
    if null v
      then go to nochange;
    u:=multsq(modify2(numr u,v,sqrtl!-in!-sf) ./ 1,
              1 ./ modify2(denr u,v,sqrtl!-in!-sf));
    putv(basis,i,u);
    f:=t;
  nochange:
    end;
  if f and !*tra then <<
    printc "Basis replaced by";
    mapvec(basis,function printsq) >>;
  return basis
  end;


symbolic procedure modify2(sf,sqrtsin,realsqrts);
if atom sf
  then sf
  else if atom mvar sf
    then sf
    else if eqcar(mvar sf,'sqrt) and dependsp(mvar sf,intvar)
      then begin
        scalar u,v,w,lcsf,sqrtsin2,w2,lcsf2,temp;
        u:=!*q2f simp argof mvar sf;
        v:=realsqrts;
        while v and null (w:=modify!-quotf(car v,u))
          do v:=cdr v;
        if null v
          then <<
            if !*tra then <<
              printc "Unable to modify (postponed)";
              printsf !*kk2f mvar sf >>;
            return sf >>;
        v:=car v;
        % We must modify SQRT(U) into SQRT(V) if possible.
        lcsf:=lc sf;
        sqrtsin2:=delete(mvar sf,sqrtsin);
        while sqrtsin2 and (w neq 1) do <<
          temp:=!*q2f simp argof car sqrtsin2;
          if (w2:=modify!-quotf(w,temp)) and
             (lcsf2:=modify!-quotf(lcsf,!*kk2f car sqrtsin2))
            then <<
              w:=w2;
              lcsf:=lcsf2 >>;
          sqrtsin2:=cdr sqrtsin2 >>;
        if w = 1
          then return addf(multf(lcsf,formsqrt v),
                           modify2(red sf,sqrtsin,realsqrts));
                           % It is important to use FORMSQRT here since
                           % SIMPSQRT will recreate the factorisation
                           % we are trying to destroy.
          % Satisfactorily explained away.
        return addf(multf(!*p2f lpow sf,
                          modify2(lc sf,sqrtsin,realsqrts)),
                    modify2(red sf,sqrtsin,realsqrts))
        end
      else addf(multf(!*p2f lpow sf,
                      modify2(lc sf,sqrtsin,realsqrts)),
                modify2(red sf,sqrtsin,realsqrts));



%symbolic procedure modifydown(sf,sqrtl);
%if atom sf
%  then sf
%  else if atom mvar sf
%    then sf
%    else if eqcar(mvar sf,'sqrt) and
%            dependsp(mvar sf,intvar) and
%           not member(!*q2f simp argof mvar sf,sqrtl)
%      then addf(modifydown(lc sf,sqrtl),
%                modifydown(red sf,sqrtl))
%      else addf(multf(!*p2f lpow sf,
%                      modifydown(lc sf,sqrtl)),
%                modifydown(red sf,sqrtl));


% symbolic procedure modifyup(sf,sqrtl);
% if atom sf
%   then sf
%   else if atom mvar sf
%     then sf
%     else if eqcar(mvar sf,'sqrt) and
%             dependsp(mvar sf,intvar)
%       then begin
%         scalar u,v;
%         u:=!*q2f simp argof mvar sf;
%         if u member sqrtl
%         then return addf(multf(!*p2f lpow sf,
%                                 modifyup(lc sf,sqrtl)),
%                           modifyup(red sf,sqrtl));
%        v:=sqrtl;
%        while v and not modify!-quotf(car v,u)
%          do v:=cdr v;
%        if null v
%          then interr "No sqrt to upgrade to";
%       return addf(multf(!*kk2f simpsqrt2 car v,
%                          modifyup(lc sf,sqrtl)),
%                    modifyup(red sf,sqrtl))
%        end
%      else addf(multf(!*p2f lpow sf,
%                      modifyup(lc sf,sqrtl)),
%                modifyup(red sf,sqrtl));


symbolic procedure modify!-quotf(u,v);
% Replacement for quotf, in that it gets sqrts right.
if atom v or atom mvar v
  then quotf(u,v)
  else if u=v then 1
  else begin
    scalar sq;
    sq:=sqrt2top(u ./ v);
    if involvesf(denr sq,intvar)
      then return nil;
    if not onep denr sq
      then if not numberp denr sq
        then interr "Gauss' lemma violated in modify"
        else if !*tra
          then <<
            printc "*** Denominator ignored in modify";
            printc denr sq >>;
    return numr sq
    end;

endmodule;

end;

