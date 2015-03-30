module hypergeomrsolve;

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


fluid '(!*tracefps);

algebraic procedure hypergeomrsolve (r,k,a0);

% solves the recurrence equation
%
%  a(k+1) = r(k) * a(k), a(0) = a0

  begin scalar re,nnn,ddd,c,p,q,ak,sols,ii;

   p := {}; q := {};
   c := 1;

   re := r * (k + 1);

   nnn := old_factorize num re; ddd := old_factorize den re;

   foreach nn in nnn do
   if freeof (nn,k) then c := c * nn
        else if deg(nn,k) =1 then
        << c:= c*coeffn(nn,k,1);
            p:= append (p,list(coeffn(nn,k,0)/coeffn(nn,k,1)))>>
        else if deg(nn,k) =2 then
        << c := c *  lcof(nn,k);
                sols := solve(nn,k);
                for each s in sols do
                   << for i:=1:first multiplicities!* do
                        p:= (- rhs s) . p;
                      multiplicities!* := rest multiplicities!*;
                  >>
        >>
        else rederr(" hypergeomRsolve failed");

   foreach dd in ddd do
   if freeof (dd,k) then c := c / dd
        else if deg(dd,k) =1 then
        << c:= c/coeffn(dd,k,1);
            q:= append (q,list(coeffn(dd,k,0)/coeffn(dd,k,1)))>>
        else if deg(dd,k) =2 then
             << c := c /  lcof(dd,k);
                sols := solve(dd,k);
                for each s in sols do
                   << for i:=1:first multiplicities!* do
                        q:= (- rhs s) . q;
                      multiplicities!* := rest multiplicities!*;
                  >>;
             >>
        else rederr(" hypergeomRsolve failed");

   rsolve := infinite;
   for each s in p do if fixp s and s < 0 then rsolve := finite;
   if symbolic !*tracefps then  write "RSOLVE  = ",rsolve;

   p := for each s in p product Pochhammer(s,k);
   q := for each s in q product Pochhammer(s,k);

   ak := a0 * (c^k) * p/(q * factorial k);

% Do additional simplification here??

   return ak;
end;

% A special ruleset for powerseries; nn has a special meaning here and
% should be treated as integer

algebraic <<

hgspec_pochhammer :=

{ Pochhammer(~kk,~nn) => 1 when nn=0,
  Pochhammer(~kk,nn) => 0 when kk = 0,
  Pochhammer(~kk,nn) => (-1)^nn * factorial(-kk)/factorial(-kk-nn)
                        when fixp(kk) and kk <=0,
  Pochhammer(~kk,nn) => factorial(kk+nn-1)/factorial(kk-1) when fixp kk,
  Pochhammer(~kk,~w*nn) =>
     factorial(kk+w*nn-1)/factorial(kk-1) when fixp kk}
>>;

endmodule;
end;


