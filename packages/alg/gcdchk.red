module gcdchk;   % Check for a unit gcd using modular arithmetic.

% Author: Arthur C. Norman and Mary Ann Moore.

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


% Modifications by: Anthony C. Hearn.

fluid '(!*backtrace list!-of!-large!-primes modular!-values);

% LIST!-OF!-LARGE!-PRIMES is a list of the largest pair of adjacent
% primes that can fit in the inum range of the implementation.
% This should be set here in an implementation dependent manner.
% For the time begin, a maximum inum value of 2^23 is assumed.

list!-of!-large!-primes := '(8388449 8388451);

symbolic procedure monic!-mod!-p a;
   if null a then nil
    else if domainp a then 1
    else if lc a = 1 then a
    else multiply!-by!-constant!-mod!-p(a,modular!-reciprocal lc a);

symbolic inline procedure before!-in!-order(a,b);
%Predicate taking the value true if the polynomial
%a has a leading term which comes strictly before that
%of b in canonical order;
   null domainp a and (domainp b or ldeg a>ldeg b);

symbolic procedure uni!-plus!-mod!-p(a,b);
% Form the sum of the two univariate polynomials a and b
% working over the ground domain defined by the routines
% modular!-plus, modular!-times etc. The inputs to this
% routine are assumed to have coefficients already
% in the required domain;
  if null a then b
   else if null b then a
   else if before!-in!-order(a,b)
    then (lt a) .+ uni!-plus!-mod!-p(red a,b)
   else if before!-in!-order(b,a)
    then (lt b) .+ uni!-plus!-mod!-p(a,red b)
   else if domainp a
    then <<a:=modular!-plus(a,b); if a=0 then nil else a>>
   else begin scalar w;
      w:=uni!-plus!-mod!-p(red a,red b);
      b:=modular!-plus(lc a,lc b);
      if b=0 then return w;
      return (lpow a .* b) .+ w
   end;

%symbolic procedure uni!-times!-mod!-p(a,b);
%   if (null a) or (null b) then nil
%   else if domainp a then multiply!-by!-constant!-mod!-p(b,a)
%   else if domainp b then multiply!-by!-constant!-mod!-p(a,b)
%   else uni!-plus!-mod!-p(
%         uni!-plus!-mod!-p(uni!-times!-mod!-p(red a,red b),
%                                 uni!-times!-term!-mod!-p(lt a,b)),
%                    uni!-times!-term!-mod!-p(lt b,red a));

symbolic procedure uni!-times!-term!-mod!-p(term,b);
%Multiply the given polynomial by the given term;
    if null b then nil
    else if domainp b then <<
       b:=modular!-times(tc term,b);
       if b=0 then nil
       else (tpow term .* b) .+ nil >>
    else begin scalar w;
        w:=modular!-times(tc term,lc b);
        if w=0 then return uni!-times!-term!-mod!-p(term,red b);
        w:= (tvar term to (tdeg term+ldeg b)) .* w;
        return w .+ uni!-times!-term!-mod!-p(term,red b)
    end;

symbolic procedure uni!-remainder!-mod!-p(a,b);
% Remainder when a is divided by b;
    if null b then rederr "b=0 in remainder-mod-p"
    else if domainp b then nil
    else xuni!-remainder!-mod!-p(a,b);

symbolic procedure xuni!-remainder!-mod!-p(a,b);
% Remainder when the univariate modular polynomial a is
% divided by b, given that b is non degenerate;
   if domainp a or ldeg a < ldeg b then a
   else begin
    scalar q,w;
    q:=modular!-quotient(modular!-minus lc a,lc b);
% compute -lc of quotient;
    w:= ldeg a - ldeg b; %ldeg of quotient;
    if w=0 then a:=uni!-plus!-mod!-p(red a,
      multiply!-by!-constant!-mod!-p(red b,q))
    else
      a:=uni!-plus!-mod!-p(red a,uni!-times!-term!-mod!-p(
            (mvar b to w) .* q,red b));
% the above lines of code use red a and red b because
% by construction the leading terms of the required
% answers will cancel out;
     return xuni!-remainder!-mod!-p(a,b)
   end;

symbolic procedure multiply!-by!-constant!-mod!-p(a,n);
% Multiply the polynomial a by the constant n
% assumes that a is univariate, and that n is coprime with
% the current modulus so that modular!-times(xxx,n) neq 0
% for all xxx;
   if null a then nil
   else if n=1 then a
   else if domainp a then modular!-times(a,n)
   else (lpow a .* modular!-times(lc a,n)) .+
     multiply!-by!-constant!-mod!-p(red a,n);

symbolic procedure uni!-gcd!-mod!-p(a,b);
%Return the monic gcd of the two modular univariate
%polynomials a and b;
    if null a then monic!-mod!-p b
    else if null b then monic!-mod!-p a
    else if domainp a then 1
    else if domainp b then 1
    else if ldeg a > ldeg b then
      ordered!-uni!-gcd!-mod!-p(a,b)
    else ordered!-uni!-gcd!-mod!-p(b,a);

symbolic procedure ordered!-uni!-gcd!-mod!-p(a,b);
% As above, but degr a > degr b;
   if null b then monic!-mod!-p a
   else ordered!-uni!-gcd!-mod!-p(b,uni!-remainder!-mod!-p(a,b));

symbolic macro procedure myerr u;
   list('errorset,
        'list .
           mkquote caadr u .
              for each j in cdadr u collect list('mkquote,j),
        t,'!*backtrace);

symbolic procedure modular!-multicheck(u,v,var);
   if errorp (u := myerr modular!-multicheck1(u,v,var)) then nil
    else car u;

symbolic procedure modular!-multicheck1(u,v,var);
% TRUE if a modular check tells me that U and V are coprime;
  begin
    scalar oldp,p,modular!-values,umodp,vmodp;
    p:=list!-of!-large!-primes;
    oldp:=setmod nil;
try!-next!-prime:
    modular!-values:=nil;
    if null p then goto uncertain;
    setmod car p;
    p:=cdr p;
    if null modular!-image(lc u,var) or null modular!-image(lc v,var)
      then go to try!-next!-prime;
    umodp:=modular!-image(u,var);
    vmodp:=modular!-image(v,var);
    p := domainp uni!-gcd!-mod!-p(umodp,vmodp);
uncertain:
    setmod oldp;
    return p
  end;

symbolic procedure modular!-image(p,var);
    if domainp p
      then if null p then nil
            else if not atom p then error1()
            else <<p := modular!-number p; if p=0 then nil else p>>
    else begin
      scalar v,x,w;
      v:=mvar p;
      if v=var then <<
          x:=modular!-image(lc p,var);
          if null x then return modular!-image(red p,var)
          else return (lpow p .* x) .+ modular!-image(red p,var) >>;
      x:=atsoc(v,modular!-values);
      if null x then <<
          x:=modular!-number random car list!-of!-large!-primes;
          modular!-values:=(v . x) . modular!-values >>
      else x:=cdr x;
      x:=modular!-expt(x,ldeg p);
      w:=modular!-image(red p,var);
      v:=modular!-image(lc p,var);
      if null v then x:=nil
      else x:=modular!-times(v,x);
      if w then x:=modular!-plus(x,w);
      return if x=0 then nil else x
    end;

endmodule;

end;

