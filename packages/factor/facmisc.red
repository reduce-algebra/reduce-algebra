module facmisc;  % Miscellaneous routines used from several sections.

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(current!-modulus
        image!-set!-modulus
        modulus!/2
        othervars
        polyzero
%       pt
        save!-zset
        zerovarset);

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


global '(largest!-small!-modulus pseudo!-primes teeny!-primes);


% (1) Investigate variables in polynomial.

symbolic procedure multivariatep(a,v);
    if domainp a then nil
    else if not(mvar a eq v) then t
    else if multivariatep(lc a,v) then t
    else multivariatep(red a,v);

symbolic procedure variables!-in!-form a;
% collect variables that occur in the form a;
    variables!.in!.form(a,nil);

symbolic procedure get!.coefft!.bound(poly,degbd);
% Calculates a coefft bound for the factors of poly.  This simple
% bound is that suggested by Paul Wang and Linda p. Rothschild in
% Math. Comp. Vol 29 July 75, p.940, due to Gel'fond.
% Note that for tiny polynomials the bound is forced up to be
% larger than any prime that will get used in the mod-p splitting;
  max(get!-height poly * fixexpfloat sumof degbd,110);

symbolic procedure sumof degbd;
  if null degbd then 0 else cdar degbd + sumof cdr degbd;

symbolic procedure fixexpfloat n;
   % Compute exponential function e**n for potentially large N,
   % rounding result up somewhat. Note that exp(10)=22027 or so,
   % so if the basic floating point exponential function is accurate
   % to 6 or so digits we are protected here against roundoff.
   % This could be replaced by ceiling exp n, but is written this
   % way to avoid floating point overflow.
%  if n>10 then (fixexpfloat(n2)*fixexpfloat(n-n2) where n2 = n/2)
%   else 1+fix exp n;
   if n>10 then 22027*fixexpfloat(n-10) else ceiling exp float n;

% (2) Minor variations on ordinary algebraic operations.

symbolic procedure quotfail(a,b);
% version of quotf that fails if the division does;
  if polyzerop a then polyzero
  else begin scalar w;
    w:=quotf(a,b);
    if didntgo w then errorf list("UNEXPECTED DIVISION FAILURE",a,b)
    else return w
  end;

symbolic procedure quotfail1(a,b,msg);
% version of quotf that fails if the division does, and gives
% custom message;
  if polyzerop a then polyzero
  else begin scalar w;
    w:=quotf(a,b);
    if didntgo w then errorf msg
    else return w
  end;


% (3) pseudo-random prime numbers - small and large.

symbolic procedure set!-teeny!-primes();
  begin scalar i;
    i:=-1;
    teeny!-primes:=mkvect 9;
    putv(teeny!-primes,i:=iadd1 i,3);
    putv(teeny!-primes,i:=iadd1 i,5);
    putv(teeny!-primes,i:=iadd1 i,7);
    putv(teeny!-primes,i:=iadd1 i,11);
    putv(teeny!-primes,i:=iadd1 i,13);
    putv(teeny!-primes,i:=iadd1 i,17);
    putv(teeny!-primes,i:=iadd1 i,19);
    putv(teeny!-primes,i:=iadd1 i,23);
    putv(teeny!-primes,i:=iadd1 i,29);
    putv(teeny!-primes,i:=iadd1 i,31)
  end;

set!-teeny!-primes();

symbolic procedure random!-small!-prime();
  begin
    scalar p;
    repeat <<p:=small!-random!-number(); if evenp p then p := iadd1 p>>
       until primep p;
    return p
  end;

symbolic procedure small!-random!-number();
% Returns a smallish number from a distribution strongly favouring
% smaller numbers;
  begin scalar w;
% The next lines generate a random value in the range 0 to 1000000.
    w := remainder(next!-random!-number(), 1000);
    w := remainder(next!-random!-number(),1000) + 1000*w;
    if w < 0 then w := w + 1000000;
    w:=1.0+1.5*float w/1000000.0;  % 1.0 to 2.5
    w:=times(w,w);                 % In range 1.0 to 6.25
    return fix exp w;              % Should be in range 3 to 518,
                                   % < 21 about half the time;
  end;

% symbolic procedure fac!-exp u;
%    % Simple exp routine.  Assumes that Lisp has a routine for
%    % exponentiation of floats by integers.  Relative accuracy 4.e-5.
%    begin scalar x; integer n;
%      n := fix u;
%      if (x := (u - float n)) > 0.5 then <<x := x - 1.0; n := n + 1>>;
%      u := ee***n;
%      return u*((x+6.0)*x+12.0)/((x-6.0)*x+12.0)
%    end;

symbolic procedure random!-teeny!-prime l;
% get one of the first 10 primes at random providing it is
% not in the list L or that L says we have tried them all;
  if l='all or (length l = 10) then nil
  else begin scalar p;
    repeat
       p:=getv(teeny!-primes,remainder(next!-random!-number(),10))
    until not member(p,l);
    return p
  end;

% Here I have code that can test any number up to 2^27-1 for primality. It
% uses Miller-Rabin with two carefully chosen bases such that in that
% range there are only two strong pseudoprime left over, so a rather simple
% test copes with those.
% Note that when the code in this file was first implemented Miller had
% published a deterministic prime test that relied on the Extended Riemenn
% Hyposthesis, but Rabin not developed the probabilistic varient, and
% computer searches to find "good" bases to use in tests for finite ranges
% had not had a chance to get very far! So it is not really incompetence that
% the original code here was less good!

% My choice of 2^27-1 is driven by the fact that CSL and the 32-bit version
% of PSL have that as their largest "fixnum". 64-bit PSL and future 64-bit
% versions of CSL can support larger fixnums, but then the prime checking
% needs at least an test using a further modulus, or other cleverness. It is
% also driven by a balance - to cover a larger range (say up to 2^32 or 2^48)
% would leave the code that tests for primality slower... and finding good
% bases to use in the testing would be harder. Well if you do a web search you
% will find the clever idea of using just ONE Miller-Rabin test using a base
% obtained by hashing the number that is to be tested, and a modest size
% hash table and that trick lets you test primes up to 32-bits rather fast,
% while more elaborate versions with only a couple of Miller-Rabin tests can
% cope with 64-bit inputs.... What I have here is good enough for now!

symbolic procedure miller!-rabin(a, n);
  begin
    scalar d, s, x;
% The next 3 lines might be handled as preconditions rather than being tested
% for explicitly here. But they do not cost much and leave the code more
$ self-contained. Note that if gcd(a,n)!=1 this will return nil even if n
% is prime...
    if n = 1 then return nil
    else if remainder(n, 2) = 0 then return (n = 2)
    else if n <= 7 then return t;
    d := n - 1;
    s := 0;
    while remainder(d, 2) = 0 do <<
      d := d / 2;
      s := s + 1 >>;
    set!-modulus n;
    a := remainder(a, n);
    x := modular!-expt(a, d);
% During development I had a few print statements - I leave them in, but
% commented out, for the benefit of anybopdy who wants to play with the code.
%   printf("%p^%p = %p mod %p%n", a, d, x, n);
    if x = 1 or x = n-1 then return t;
loop:
%   printf("s = %p%n", s);
    if s = 1 then return nil;
    x := modular!-times(x, x);
%   printf("now x = %p mod %p%n", x, n);
    if x = 1 then return nil
    else if x = n-1 then return t;
    s := s - 1;
    go to loop
  end;

symbolic procedure primep27 n;
  begin
    scalar oldmod, r;
% The next line is because 8958=2**3*1493. The cases of 2 and 3 are dealt
% with specially anyway, but the effect is that trying a witness of 8958
% in a naive manner would report 1493 as composite not prime.  The other
% witness that I use is 4704=2^5*3*7^2 and primes up as far as 7 are handled
% specially already...
    if n = 1493 then return t;
    oldmod := set!-modulus nil;
    r := miller!-rabin(8958, n) and
         miller!-rabin(4704, n) and
% Using the abive two witnesses gets primaility detected for all numbers up
% to 2^27 apart from the following two exceptions:
%    9131401 = 2137*4273
%    6089071 = 1951*3121.
% These numbers are not especially magic and it is just that the particular
% pair of bases used are the smallest pair I have found that leave so few
% excepotional cases over for the range of numbers I am checking. 
         not (n = 9131401 or
              n = 6089071);
    set!-modulus oldmod;
    return r;
  end;

symbolic procedure random!-prime();
  begin
% I want a random prime that is smaller than largest-small-modulus.
% I do this by generating random odd integers in the range lsm/2 to
% lsm and filtering them for primality. Prime testing is done using
% a Miller-Rabin test using two bases and then explicit code to cope with
% the small number of strong pseudoprimes left over.
% The prime that I find here will be at least half the value of the largest
% small modulus. One side effect of that is that when testing for primality
% I do not need to worry at all about any special cases for small values, but
% for safety and potential future use I still check everything.
    scalar n, lsm, lsm2;
    lsm := largest!-small!-modulus;
    if lsm > 2**27 then lsm := 2**27;
    lsm2 := lsm/2;
    repeat <<
      n := remainder(next!-random!-number(), lsm);
      if n < lsm2 then n := n + lsm2;
      if evenp n then n := n + 1 >> until primep27 n;
    return n
  end;

% (4) useful routines for vectors.

symbolic procedure form!-sum!-and!-product!-mod!-p(avec,fvec,r);
% sum over i (avec(i) * fvec(i));
  begin scalar s;
    s:=polyzero;
    for i:=1:r do
      s:=plus!-mod!-p(times!-mod!-p(getv(avec,i),getv(fvec,i)),
        s);
    return s
  end;

symbolic procedure form!-sum!-and!-product!-mod!-m(avec,fvec,r);
% Same as above but AVEC holds alphas mod p and want to work
% mod m (m > p) so minor difference to change AVEC to AVEC mod m;
  begin scalar s;
    s:=polyzero;
    for i:=1:r do
      s:=plus!-mod!-p(times!-mod!-p(
        !*f2mod !*mod2f getv(avec,i),getv(fvec,i)),s);
    return s
  end;

symbolic procedure reduce!-vec!-by!-one!-var!-mod!-p(v,pt,n);
% Substitute for the given variable in all elements creating a
% new vector for the result. (All arithmetic is mod p).
  begin scalar newv;
    newv:=mkvect n;
    for i:=1:n do
      putv(newv,i,evaluate!-mod!-p(getv(v,i),car pt,cdr pt));
    return newv
  end;

symbolic procedure make!-bivariate!-vec!-mod!-p(v,imset,var,n);
  begin scalar newv;
    newv:=mkvect n;
    for i:=1:n do
      putv(newv,i,make!-bivariate!-mod!-p(getv(v,i),imset,var));
    return newv
  end;

symbolic procedure times!-vector!-mod!-p(v,n);
% product of all the elements in the vector mod p;
  begin scalar w;
    w:=1;
    for i:=1:n do w:=times!-mod!-p(getv(v,i),w);
    return w
  end;

symbolic procedure make!-vec!-modular!-symmetric(v,n);
% fold each elt of V which is current a modular poly in the
% range 0->(p-1) onto the symmetric range (-p/2)->(p/2);
  for i:=1:n do putv(v,i,make!-modular!-symmetric getv(v,i));

% (5) Combinatorial fns used in finding values for the variables.


symbolic procedure make!-zerovarset vlist;
% vlist is a list of pairs (v . tag) where v is a variable name and
% tag is a boolean tag. The procedure splits the list into two
% according to the tags: Zerovarset is set to a list of variables
% whose tag is false and othervars contains the rest;
  for each w in vlist do
    if cdr w then othervars:= car w . othervars
    else zerovarset:= car w . zerovarset;

symbolic procedure make!-zeroset!-list n;
% Produces a list of lists each of length n with all combinations of
% ones and zeroes;
  begin scalar w;
    for k:=0:n do w:=append(w,kcombns(k,n));
    return w
  end;

symbolic procedure kcombns(k,m);
% produces a list of all combinations of ones and zeroes with k ones
% in each;
  if k=0 or k=m then begin scalar w;
    if k=m then k:=1;
    for i:=1:m do w:=k.w;
    return list w
    end
  else if k=1 or k=isub1 m then <<
    if k=isub1 m then k:=0;
    list!-with!-one!-a(k,1 #- k,m) >>
  else append(
    for each x in kcombns(isub1 k,isub1 m) collect (1 . x),
    for each x in kcombns(k,isub1 m) collect (0 . x) );

symbolic procedure list!-with!-one!-a(a,b,m);
% Creates list of all lists with one a and m-1 b's in;
  begin scalar w,x,r;
    for i:=1:isub1 m do w:=b . w;
    r:=list(a . w);
    for i:=1:isub1 m do <<
      x:=(car w) . x; w:=cdr w;
      r:=append(x,(a . w)) . r >>;
    return r
  end;

symbolic procedure make!-next!-zset l;
  begin scalar k,w;
    image!-set!-modulus:=iadd1 image!-set!-modulus;
    set!-modulus image!-set!-modulus;
    w:=for each ll in cdr l collect
      for each n in ll collect
        if n=0 then n
        else <<
          k:=modular!-number next!-random!-number();
          while (zerop k) or (onep k) do
            k:=modular!-number next!-random!-number();
          if k>modulus!/2 then k:=k-current!-modulus;
           k >>;
    save!-zset:=nil;
    return w
  end;

endmodule;

end;
