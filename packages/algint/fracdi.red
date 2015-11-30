module fracdi;

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


fluid '(basic!-listofallsqrts basic!-listofnewsqrts expsub intvar
    sqrt!-intvar);

global '(coates!-fdi);

exports fdi!-print,fdi!-revertsq,fdi!-upgrade,
   fractional!-degree!-at!-infinity;

% internal!-fluid '(expsub);

symbolic procedure fdi!-print();
<< princ "We substitute ";
   princ intvar;
   princ "**";
   princ coates!-fdi;
   princ " for ";
   princ intvar;
   printc " in order to avoid fractional degrees at infinity" >>;


symbolic procedure fdi!-revertsq u;
if coates!-fdi iequal 1
  then u
  else (fdi!-revert numr u) ./ (fdi!-revert denr u);


symbolic procedure fdi!-revert u;
if not involvesf(u,intvar)
  then u
  else addf(fdi!-revert red u,
        !*multf(fdi!-revertpow lpow u,
            fdi!-revert lc u));


symbolic procedure fdi!-revertpow pow;
if not dependsp(car pow,intvar)
  then (pow .* 1) .+ nil
  else if car pow eq intvar
    then begin
      scalar v;
      v:=divide(cdr pow,coates!-fdi);
      if cdr pow=0
        then return (mksp(intvar,car pow) .* 1) .+ nil
    else interr "Unable to revert fdi";
      end
    else if eq(car pow,'sqrt)
      then simpsqrt2 fdi!-revert !*q2f simp argof car pow
      else interr "Unrecognised term to revert";


symbolic procedure fdi!-upgrade place;
begin
  scalar ans,u,expsub,n;
  n:=coates!-fdi;
  for each u in place do
    if eqcar(u:=rsubs u,'expt)
      then n:=n / caddr u;
      % if already upgraded, we must take account of this.
  if n = 1
    then return place;
  expsub:=list(intvar,'expt,intvar,n);
  ans:=nconc(basicplace place,list expsub);
  expsub:=list expsub; % this prevents later nconc from causing trouble.
  u:=extenplace place;
  while u do begin
    scalar v,w,rfu;
    v:=fdi!-upgr2 lfirstsubs u;
    if v iequal 1
      then return (u:=cdr u);
    if eqcar(rfu:=rfirstsubs u,'minus)
      then w:=argof rfu
      else if eqcar(rfu,'sqrt)
        then w:=rfu
    else interr "Unknown place format";
    w:=fdi!-upgr2 w;
    if w iequal 1
      then interr "Place collapses under rewriting";
    if eqcar(rfu,'minus)
      then ans:=nconc(ans,list list(v,'minus,w))
      else ans:=nconc(ans,list(v.w));
    u:=cdr u;
    return
    end;
  sqrtsave(basic!-listofallsqrts,
       basic!-listofnewsqrts,
           basicplace ans);
  return ans
  end;


symbolic procedure fdi!-upgr2 u;
begin
  scalar v,mv;
% V:=SUBSTITUTESQ(SIMP U,EXPSUB);
% The above line doesn't work due to int(sqrt(x-1)/sqrt(x+1),x);
% where the attempt to make sqrt(x^2-1) is frustrated by the presence of
% sqrt(x-1) and sqrt(x+1) which get SIMPed (even after we allow for the
% NEWPLACE call in COATES
  v:=xsubstitutep(u,expsub);
  if denr v neq 1
    then goto error;
  v:=numr v;
loop:
  if atom v
    then return v;
  if red v
    then go to error;
  mv:=mvar v;
  if (not dependsp(mv,intvar)) or (mv eq intvar)
    then <<
      v:=lc v;
      goto loop >>;
  if eqcar(mv,'sqrt) and not sqrtsinsf(lc v,nil,intvar)
      then return mv;
error:
  printc "*** Format error ***";
  princ "unable to go x:=x**";
  printc coates!-fdi;
  superprint u;
  interr "Failure to make integral at infinity"
  end;


symbolic procedure fractional!-degree!-at!-infinity sqrts;
if sqrts
  then lcmn(fdi2 car sqrts,fractional!-degree!-at!-infinity cdr sqrts)
  else 1;


symbolic procedure fdi2 u;
   % Returns the denominator of the degree of x at infinity
   % in the sqrt expression u.
begin
  scalar n;
  u:=substitutesq(simp u,list list(intvar,'quotient,1,intvar));
  n:=0;
  while involvesq(u,sqrt!-intvar) do <<
    n:=iadd1 n;
    u:=substitutesq(u,list list(intvar,'expt,intvar,2)) >>;
  return (2**n)
  end;


symbolic procedure lcmn(i,j);
  i*j/gcdn(i,j);

% unfluid '(expsub);

endmodule;

end;

