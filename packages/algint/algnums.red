module algnums;

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


exports denr!-algno;


symbolic procedure denr!-algno u;
% Returns the true denominator of the algebraic number u.
begin
  scalar sqlist,n,m,u!*!*j,d;
  u!*!*j:=1 ./ 1;
  sqlist:=sqrtsinsq(u,nil);
  sqlist:=multbyallcombinations(list(1 ./ 1),
                               for each u in sqlist
                                 collect !*kk2q u);
  n:=0;
  sqlist:=for each u in sqlist collect
    (numr u) . (n:=iadd1 n);
    % format is of an associtaion list.
  n:=length sqlist;
  m:=mkvect n;
  for i:=0:n do
    putv(m,i,mkvect2(n,nil ./ 1));
  putv(getv(m,0),cdr assoc(1,sqlist),1 ./ 1);
  % initial matrix is now set up.
  for j:=1:n do begin
    scalar v,w;
    u!*!*j:=!*multsq(u!*!*j,u);
    dump!-sqrts!-coeffs(u!*!*j,sqlist,getv(m,j));
    v:=firstlinearrelation(m,n);
    if null v
      then return;
    if last!-non!-zero v > j
      then return;
    if (w:=getv(v,j)) neq (1 ./ 1)
      then <<
        w:=!*invsq w;
        for i:=0:j do
          putv(v,i,!*multsq(w,getv(v,i))) >>;
    m:=v;
    n:=j;
    return
    end;
  % Now m is a monic polynomial, minimal for u, of degree n.
  d:=1;
  for i:=0:isub1 n do begin
    scalar v,prime;
    v:=denr getv(m,i);
    prime:=2;
loop:
    if v = 1
      then return;
    if cdr divide(v,prime) neq 0 then prime:=nextprime(prime)
      else <<
        d:=d*prime;
        for i:=0:n do
          putv(v,i,multsq(getv(v,i),1 ./ (prime ** (n-i)) )) >>;
    go to loop;
    end;
  return d;
  end;


symbolic procedure dump!-sqrts!-coeffs(u,sqlist,vec);
begin
  scalar w;
  dump!-sqrts!-coeffs2(numr u,sqlist,vec,1);
  u:=1 ./ denr u;
  if denr u neq 1
    then for i:=0:upbv vec do
      if numr(w:=getv(vec,i))
        then putv(vec,i,!*multsq(u,w));
  end;


symbolic procedure dump!-sqrts!-coeffs2(u,sqlist,vec,sqrtssofar);
if null u
  then nil
  else if numberp u
    then putv(vec,cdr assoc(sqrtssofar,sqlist),u)
    else <<
      dump!-sqrts!-coeffs2(red u,sqlist,vec,sqrtssofar);
      dump!-sqrts!-coeffs2(lc u,sqlist,vec,!*multf(sqrtssofar,
                                                   !*k2f mvar u)) >>;


symbolic procedure last!-non!-zero vec;
begin
  scalar n;
  for i:=0:upbv vec do
    if numr getv(vec,i)
      then n:=i;
  return n
  end;

endmodule;

end;

