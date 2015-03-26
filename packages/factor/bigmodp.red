module bigmodp; % Modular polynomial arithmetic where the modulus may
                % be a bignum.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

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


fluid '(current!-modulus modulus!/2);

symbolic inline procedure comes!-before(p1, p2);
% Similar to the REDUCE function ORDPP, but does not cater for
% non-commutative terms and assumes that exponents are small integers.
    (car p1=car p2 and igreaterp(cdr p1,cdr p2)) or
       (not(car p1=car p2) and ordop(car p1,car p2));

symbolic procedure general!-plus!-mod!-p(a,b);
% form the sum of the two polynomials a and b
% working over the ground domain defined by the routines
% general!-modular!-plus, general!-modular!-times etc. the inputs to
% this routine are assumed to have coefficients already
% in the required domain;
   if null a then b
   else if null b then a
   else if domainp a then
      if domainp b then !*n2f general!-modular!-plus(a,b)
      else (lt b) .+ general!-plus!-mod!-p(a,red b)
   else if domainp b then (lt a) .+ general!-plus!-mod!-p(red a,b)
   else if lpow a = lpow b then
      adjoin!-term(lpow a,
         general!-plus!-mod!-p(lc a,lc b),
         general!-plus!-mod!-p(red a,red b))
   else if comes!-before(lpow a,lpow b) then
         (lt a) .+ general!-plus!-mod!-p(red a,b)
   else (lt b) .+ general!-plus!-mod!-p(a,red b);

symbolic procedure general!-times!-mod!-p(a,b);
   if (null a) or (null b) then nil
   else if domainp a then gen!-mult!-by!-const!-mod!-p(b,a)
   else if domainp b then gen!-mult!-by!-const!-mod!-p(a,b)
   else if mvar a=mvar b then general!-plus!-mod!-p(
     general!-plus!-mod!-p(general!-times!-term!-mod!-p(lt a,b),
                  general!-times!-term!-mod!-p(lt b,red a)),
     general!-times!-mod!-p(red a,red b))
   else if ordop(mvar a,mvar b) then
     adjoin!-term(lpow a,general!-times!-mod!-p(lc a,b),
       general!-times!-mod!-p(red a,b))
   else adjoin!-term(lpow b,
        general!-times!-mod!-p(a,lc b),general!-times!-mod!-p(a,red b));

symbolic procedure general!-times!-term!-mod!-p(term,b);
%multiply the given polynomial by the given term;
    if null b then nil
    else if domainp b then
        adjoin!-term(tpow term,
            gen!-mult!-by!-const!-mod!-p(tc term,b),nil)
    else if tvar term=mvar b then
         adjoin!-term(mksp(tvar term,iplus2(tdeg term,ldeg b)),
                      general!-times!-mod!-p(tc term,lc b),
                      general!-times!-term!-mod!-p(term,red b))
    else if ordop(tvar term,mvar b) then
      adjoin!-term(tpow term,general!-times!-mod!-p(tc term,b),nil)
    else adjoin!-term(lpow b,
      general!-times!-term!-mod!-p(term,lc b),
      general!-times!-term!-mod!-p(term,red b));

symbolic procedure gen!-mult!-by!-const!-mod!-p(a,n);
% multiply the polynomial a by the constant n;
   if null a then nil
   else if n=1 then a
   else if domainp a then !*nsf general!-modular!-times(a,n)
   else adjoin!-term(lpow a,gen!-mult!-by!-const!-mod!-p(lc a,n),
     gen!-mult!-by!-const!-mod!-p(red a,n));

symbolic procedure general!-difference!-mod!-p(a,b);
   general!-plus!-mod!-p(a,general!-minus!-mod!-p b);

symbolic procedure general!-minus!-mod!-p a;
   if null a then nil
   else if domainp a then general!-modular!-minus a
   else (lpow a .* general!-minus!-mod!-p lc a) .+
        general!-minus!-mod!-p red a;

symbolic procedure general!-reduce!-mod!-p a;
%converts a multivariate poly from normal into modular polynomial;
    if null a then nil
    else if domainp a then !*n2f general!-modular!-number a
    else adjoin!-term(lpow a,
                      general!-reduce!-mod!-p lc a,
                      general!-reduce!-mod!-p red a);

symbolic procedure general!-make!-modular!-symmetric a;
% input is a multivariate MODULAR poly A with nos in the range 0->(p-1).
% This folds it onto the symmetric range (-p/2)->(p/2);
    if null a then nil
    else if domainp a then
      if a>modulus!/2 then !*nsf(a - current!-modulus)
      else a
    else adjoin!-term(lpow a,
                      general!-make!-modular!-symmetric lc a,
                      general!-make!-modular!-symmetric red a);

endmodule;

end;

