module farith;  % Operators for fast arithmetic;

% Authors: A. C. Norman and P. M. A. Moore, 1981;

remprop('iplus,'infix);  % to allow for redefinition;

remprop('itimes,'infix);

symbolic macro procedure iplus u; expand(cdr u,'plus2);

symbolic macro procedure itimes u; expand(cdr u,'times2);

smacro procedure isub1 a; a-1;

smacro procedure iadd1 a; a+1;

remprop('iminus,'infix);

smacro procedure iminus a; -a;

smacro procedure idifference(a,b); a-b;

smacro procedure iquotient(a,b); a/b;

smacro procedure iremainder(a,b); remainder(a,b);

smacro procedure igreaterp(a,b); a>b;

smacro procedure ilessp(a,b); a<b;

smacro procedure iminusp a; a<0;

newtok '((!#) hash);
newtok '((!# !+) iplus);
newtok '((!# !-) idifference);
newtok '((!# !*) itimes);
newtok '((!# !/) iquotient);
newtok '((!# !>) igreaterp);
newtok '((!# !<) ilessp);

infix #+,#-,#*,#/,#>,#<;

precedence #+,+;
precedence #-,-;
precedence #*,*;
precedence #/,/;
precedence #>,>;
precedence #<,<;

flag('(iplus itimes),'nary);

deflist('((idifference iminus)),'unary);

deflist('((iminus iplus)), 'alt);

endmodule;


module genmod; % Modular arithmetic where the modulus may be any size.

% Authors: A. C. Norman and P. M. A. Moore, 1981;

fluid '(current!-modulus modulus!/2);

symbolic procedure set!-general!-modulus p;
  if not numberp p then current!-modulus
  else begin
    scalar previous!-modulus;
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2 := p/2;
    return previous!-modulus
  end;

symbolic procedure general!-modular!-plus(a,b);
  begin scalar result;
     result:=a+b;
     if result >= current!-modulus then result:=result-current!-modulus;
     return result
  end;

symbolic procedure general!-modular!-difference(a,b);
  begin scalar result;
     result:=a-b;
     if result < 0 then result:=result+current!-modulus;
     return result
  end;

symbolic procedure general!-modular!-number a;
  begin
     a:=remainder(a,current!-modulus);
     if a < 0 then a:=a+current!-modulus;
     return a
  end;

symbolic procedure general!-modular!-times(a,b);
  begin scalar result;
     result:=remainder(a*b,current!-modulus);
     if result<0
       then result := result+current!-modulus;  %can this happen?
     return result
  end;

symbolic procedure general!-modular!-reciprocal a;
  begin
    return general!-reciprocal!-by!-gcd(current!-modulus,a,0,1)
  end;

symbolic procedure general!-modular!-quotient(a,b);
    general!-modular!-times(a,general!-modular!-reciprocal b);

symbolic procedure general!-modular!-minus a;
    if a=0 then a else current!-modulus - a;

symbolic procedure general!-reciprocal!-by!-gcd(a,b,x,y);
%On input A and B should be coprime. This routine then
%finds X and Y such that A*X+B*Y=1, and returns the value Y
%on input A > B;
   if b=0 then rederr "INVALID MODULAR DIVISION"
   else if b=1 then if y < 0 then y+current!-modulus else y
   else begin scalar w;
%N.B. Invalid modular division is either:
% a)  attempt to divide by zero directly
% b)  modulus is not prime, and input is not
%     coprime with it;
     w:=quotient(a,b); %Truncated integer division;
     return general!-reciprocal!-by!-gcd(b,a-b*w,y,x-y*w)
   end;

%symbolic procedure general!-modular!-expt(x,n);
%   if not fixp n then
%      rederr
%        "ZFACT(general-modular-expt): power is not a small integer"
%   else if n=0 then 1
%   else if n=1 then x
%   else
%     (lambda ans;
%        if evenp n then
%           general!-modular!-times(ans,ans)
%        else general!-modular!-times(general!-modular!-times(ans,x),
%                                     ans))
%      general!-modular!-expt(x,n/2);
 
symbolic procedure general!-modular!-expt(a,n);
% a**n;
    if n=0 then 1
    else if n=1 then a
    else begin scalar x;
     x:=general!-modular!-expt(a,n/2);
     x:=general!-modular!-times(x,x);
     if not evenp n then x:=general!-modular!-times(x,a);
     return x
    end;

endmodule;


module smallmod; %Small integer modular arithmetic used in factorizer.

% Author: Arthur C. Norman.

fluid '(current!-modulus modulus!/2);

global '(largest!-small!-modulus);

symbolic procedure set!-modulus p;
  if not numberp p or p=0 then current!-modulus
  else begin
    scalar previous!-modulus;
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2:=p/2;
    set!-small!-modulus p;
    return previous!-modulus
  end;

symbolic procedure set!-small!-modulus p;
  begin
    scalar previous!-modulus;
    if p>largest!-small!-modulus
      then rederr list("Overlarge modulus",p,"being used");
    previous!-modulus:=current!-modulus;
    current!-modulus:=p;
    modulus!/2 := p/2;
    return previous!-modulus
  end;


smacro procedure modular!-plus(a,b);
  begin scalar result;
     result:=a #+ b;
     if not result #< current!-modulus then
            result:=result #- current!-modulus;
     return result
  end;

smacro procedure modular!-difference(a,b);
  begin scalar result;
     result:=a #- b;
     if iminusp result then result:=result #+ current!-modulus;
     return result
  end;

symbolic procedure modular!-number a;
  begin
     a:=remainder(a,current!-modulus);
     if iminusp a then a:=a #+ current!-modulus;
     return a
  end;

smacro procedure modular!-times(a,b);
    remainder(a*b,current!-modulus);

smacro procedure modular!-reciprocal a;
    reciprocal!-by!-gcd(current!-modulus,a,0,1);

symbolic procedure reciprocal!-by!-gcd(a,b,x,y);
%On input A and B should be coprime. This routine then
%finds X and Y such that A*X+B*Y=1, and returns the value Y
%on input A > B;
   if b=0 then rederr "Invalid modular division"
   else if b=1 then if iminusp y then y #+ current!-modulus else y
   else begin scalar w;
%N.B. Invalid modular division is either:
% a)  attempt to divide by zero directly
% b)  modulus is not prime, and input is not
%     coprime with it;
     w:= a #/ b; %Truncated integer division;
     return reciprocal!-by!-gcd(b,a #- b #* w,
                                y,x #- y #* w)
   end;

smacro procedure modular!-quotient(a,b);
    modular!-times(a,modular!-reciprocal b);


smacro procedure modular!-minus a;
    if a=0 then a else current!-modulus #- a;

symbolic procedure modular!-expt(a,n);
% a**n;
    if n=0 then 1
    else if n=1 then a
    else begin scalar x;
     x:=modular!-expt(a,n#/2);
     x:=modular!-times(x,x);
     if not (iremainder(n,2) = 0) then x:=modular!-times(x,a);
     return x
    end;

symbolic set!-modulus(1) ; % forces everything into a standard state;

endmodule;


module random;  % Random Number Generator.

% Author: Unknown.

global '(randomseed!* randommodulus!*);

% The declarations below constitute a linear, congruential random number
% generator (see Knuth, "The Art of Computer Programming:  Volume 2:
% Seminumerical Algorithms", pp9-24).  With the given constants it has a
% period of 392931 and potency 6.  To have deterministic behaviour, set
% RANDOMSEED.

% Constants are:        6   2
%    modulus: 392931 = 3 * 7 * 11
%    multiplier: 232 = 3 * 7 * 11 + 1
%    increment: 65537 is prime
%
% Would benefit from being recoded in a SysLisp style, when full word
% integers could be used with "automatic" modular arithmetic (see
% Knuth).  Perhaps we should have a longer period version?

randommodulus!* := 392931;

% randomseed!* := remainder(time(),randommodulus!*);

randomseed!* := 300000;   % To avoid use of time function.

symbolic procedure next!-random!-number;
   % Returns a pseudo-random number between 0 and RandomModulus-1
   % (inclusive).
   randomseed!* := remainder(232*randomseed!* + 65537, randommodulus!*);

symbolic procedure random(n);
% Returns a pseudo-random number uniformly selected from the range
% 0..N-1.
   fix( (float(n) * next!-random!-number()) / randommodulus!*);

endmodule;


module zfactor;  % Integer factorization.
 
% Author: Julian Padget.
 
% exports zfactor, primep;
% zfactor - returns an alist of factors dotted with their multiplicities
% primep - determines whether argument is prime or not
%
% imports evenp, gcdn, general-modular-expt, general-modular-times, leq,
% modular-expt, modular-times, neq, prin2t, rederr, reversip,
% set-general-modulus, set-small-modulus;
%
% needs bigmod,smallmod;
%
% internal-functions add-factor, general-primep, mcfactor!*,
% internal-primep, isqrt, mcfactor, small-primep;
 
% Parameters to this module are:
%
%    !*confidence!* - controls the computation in the primality test.
%        Probability that a number is composite when test says it is
%        prime is 1/(2**(2*!*confidence!*)).
%
%    !*maxtrys!* - controls the maximum number of attempts to be made
%        at factorisation (using mcfactor) whilst varying the polynomial
%        used as part of the Monte-Carlo technique.  When !*maxtrys!* is
%        exceeded assumes n is prime (case will most likely occur when
%        primality test fails).
%
%    !*mod!* - controls the modulus of the numbers emitted by the random
%        number generator.  It is important that the number being tested
%        for primality should lie in [0,!*mod!*].
%
% Globals private to this module are:
%
%    !*primelist!* - a list of the first xxx prime numbers used in the
%        first part of the factorisation where trial division is
%        employed.
%
%    !*last!-prime!-in!-list!* - the largest prime in the !*primelist!*
 
fluid '(!*maxtrys!* !*confidence!*);
 
!*maxtrys!*:=10; !*confidence!*:=10;
 
global '(!*primelist!* !*last!-prime!-in!-list!*);
 
!*primelist!*:='(
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191
193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283
293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401
409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509
521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631
641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751
757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877
881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997 1009
1013 1019 1021 1031 1033 1039 1049 1051 1061 1063 1069 1087 1091 1093
1097 1103 1109 1117 1123 1129 1151 1153 1163 1171 1181 1187 1193 1201
1213 1217 1223 1229 1231 1237 1249 1259 1277 1279 1283 1289 1291 1297
1301 1303 1307 1319 1321 1327 1361 1367 1373 1381 1399 1409 1423 1427
1429 1433 1439 1447 1451 1453 1459 1471 1481 1483 1487 1489 1493 1499
1511 1523 1531 1543 1549 1553 1559 1567 1571 1579 1583 1597 1601 1607
1609 1613 1619 1621 1627 1637 1657 1663 1667 1669 1693 1697 1699 1709
1721 1723 1733 1741 1747 1753 1759 1777 1783 1787 1789 1801 1811 1823
1831 1847 1861 1867 1871 1873 1877 1879 1889 1901 1907 1913 1931 1933
1949 1951 1973 1979 1987 1993 1997 1999 2003 2011 2017 2027 2029 2039
2053 2063 2069 2081 2083 2087 2089 2099 2111 2113 2129 2131 2137 2141
2143 2153 2161 2179 2203 2207 2213 2221 2237 2239 2243 2251 2267 2269
2273 2281 2287 2293 2297 2309 2311 2333 2339 2341 2347 2351 2357 2371
2377 2381 2383 2389 2393 2399 2411 2417 2423 2437 2441 2447 2459 2467
2473 2477 2503 2521 2531 2539 2543 2549 2551 2557 2579 2591 2593 2609
2617 2621 2633 2647 2657 2659 2663 2671 2677 2683 2687 2689 2693 2699
2707 2711 2713 2719 2729 2731 2741 2749 2753 2767 2777 2789 2791 2797
2801 2803 2819 2833 2837 2843 2851 2857 2861 2879 2887 2897 2903 2909
2917 2927 2939 2953 2957 2963 2969 2971 2999 3001 3011 3019 3023 3037
3041 3049 3061 3067 3079 3083 3089 3109 3119 3121 3137 3163 3167 3169
3181 3187 3191 3203 3209 3217 3221 3229 3251 3253 3257 3259 3271 3299
3301 3307 3313 3319 3323 3329 3331 3343 3347 3359 3361 3371 3373 3389
3391 3407 3413 3433 3449 3457 3461 3463 3467 3469 3491 3499 3511 3517
3527 3529 3533 3539 3541 3547 3557 3559 3571 )$

!*last!-prime!-in!-list!* := car reverse !*primelist!*;
 
% the following four routines were written by John Abbot and are
% incorporated here with his permission.

symbolic procedure ilog2 n;
% n integral; result 'r' s.t. 2**r <= abs n < 2**(r+1)
if not fixp n then
   rederr "(ZFACTOR(ilog2):argument must be an integer"
else begin scalar ans, powers!-of!-2;
   if n<0 then n:=-n;
   powers!-of!-2:=2 . nil;
   ans:=1;
   while n>=(car powers!-of!-2) do <<
      n:=n/(car powers!-of!-2);
      powers!-of!-2:=((car powers!-of!-2)**2) . powers!-of!-2
   >>;
   while (car powers!-of!-2) neq n and cdr powers!-of!-2 do <<
      powers!-of!-2:=cdr powers!-of!-2;
      ans:=ans+ans;
      if powers!-of!-2 and n>=(car powers!-of!-2) then <<
         n:=n/(car powers!-of!-2);
         ans:=ans+1
      >>
   >>;
   return (ans-1)
end;
 
symbolic procedure isqrt n; irootn(n,2);

symbolic procedure irootn(n,r);
% n,r integral; result 's' approximates rth root of n
% that is if n>0 then s**r <= n < (s+1)**r else s**r >= n > (s-1)**r
% 3363/2378 is an approximation to sqrt 2;
if not (fixp n and fixp r) then
   rederr "ZFACTOR(irootn): both arguments must be integers"
else if r<=0 then
   rederr "ZFACTOR(irootn): non-positive integer root"
else if n<0 then
   if evenp r then
      rederr "ZFACTOR(irootn): even root of a negative integer"
   else
      -irootn(-n,r)
else if r=1 then n
else begin scalar x,newx,upb;
   x:=2**(irootn!-round(1+ilog2 n,r));
   newx:=x-irootn!-roundup(x-n/x**(r-1),r);
   upb:=(3363*x)/2378;
   if upb<newx then newx:=upb;
   repeat <<
      x:=newx;
      newx:=x-irootn!-roundup(x-n/x**(r-1),r)
   >> until newx>=x or newx=0;
   return x
end;
 
symbolic procedure irootn!-round(m,n);
% m,n integral, n>0, answer is nearest integer to m/n
(m+n/2)/n;
 
symbolic procedure irootn!-roundup(m,n);
% m,n integral, n>0, answer is least integer >= m/n
(lambda quotrem;
   if (cdr quotrem)=0 then car quotrem else 1+(car quotrem))
 divide(m,n);
 
symbolic procedure add!-factor(n,l);
   (lambda (p); if p then << rplacd(p,add1 cdr p); l>> else (n . 1) . l)
      if pairp l then if n>(caar l) then nil else atsoc(n,l) else nil;
 
symbolic procedure zfactor n;
if n<0 then
   ((-1) . 1) . zfactor(-n)
else if n<4 then
   list (n . 1)
else % trial division then advanced technology if needed
   (lambda (primelist,rootn,factor!-list); <<
      while pairp primelist do
         (lambda aprime; <<
            while remainder(n,aprime)=0 do <<
               n:=n/aprime;
               rootn:=isqrt n;
               factor!-list:=add!-factor(aprime,factor!-list)
            >>;
            if rootn < aprime then <<
               if n neq 1
                then factor!-list:=add!-factor(n,factor!-list);
               primelist:=aprime
            >>
            else
               primelist:=cdr primelist
          >>)
          car primelist;
      if null primelist then mcfactor!*(n,factor!-list)
       else factor!-list
      >>)
    (!*primelist!*,isqrt n,nil);
 
symbolic procedure mcfactor!*(n,factors!-so!-far);
if internal!-primep n then
   add!-factor(n,factors!-so!-far)
else <<
   n:=(lambda (p,tries); <<
         while (atom p) and (tries<!*maxtrys!*) do <<
            tries:=tries+1;
            p:=mcfactor(n,tries)
         >>;
         if tries>!*maxtrys!* then <<
            prin2 "ZFACTOR(mcfactor!*):Assuming ";
            prin2 n; prin2t " is prime";
            p:=list n
         >>
         else p
       >>)
       (mcfactor(n,1),1);
   if null cdr n then
      add!-factor(n,factors!-so!-far)
   else if (car n)<(cdr n) then
      mcfactor!*(cdr n,mcfactor!*(car n,factors!-so!-far))
   else
      mcfactor!*(car n,mcfactor!*(cdr n,factors!-so!-far))
>>;
 
symbolic procedure mcfactor(n,p);
% Based on "An Improved Monte-Carlo Factorisation Algorithm" by
% R.P.Brent in BIT 20 (1980) pp 176-184.  Argument n is the number to
% factor, p specifies the constant term of the polynomial.  There are
% supposed to be optimal p's for each n, but in general p=1 works well.
begin scalar gg,k,m,q,r,x,y,ys;
   y:=0; r:=q:=m:=1;
outer:
   x:=y;
   for i:=1:r do y:=remainder(y*y+p,n);
   k:=0;
inner:
   ys:=y;
   for i:=1:(if m<(r-k) then m else r-k) do <<
      y:=remainder(y*y+p,n);
      q:=remainder(q*abs(x-y),n)
   >>;
   gg:=gcdn(q,n);
   k:=k+m;
   if (k<r) and (gg leq 1) then goto inner;
   r:=2*r;
   if gg leq 1 then goto outer;
   if gg=n then begin
   loop:
      ys:=remainder(ys*ys+p,n);
      gg:=gcdn(abs(x-ys),n);
      if gg leq 1 then goto loop
   end;
   return if gg=n then n else gg . (n/gg)
end;
 
symbolic procedure primep n;
   if n member !*primelist!* then t
   else if (isqrt n)<!*last!-prime!-in!-list!* then
      begin scalar p;
         p:=!*primelist!*;
      loop:
         if remainder(n,car p)=0 then return nil;
         if null(p:=cdr p) then return t;
         go loop
      end
   else if n>largest!-small!-modulus then
      general!-primep n
   else
      small!-primep n;
 
symbolic procedure internal!-primep n;
   if n>largest!-small!-modulus then
      general!-primep n
   else
      small!-primep n;
 
symbolic procedure small!-primep n;
% Based on an algorithm of M.Rabin published in the Journal of Number
% Theory Vol 12, pp 128-138 (1980).  This version uses small modular
% arithmetic which can be open coded.
begin scalar i,m,l,b2m,result,x,!*mod!*;
   m:=n-1;
   l:=0;
   set!-small!-modulus n;
      % first a quick check for compositeness
   if modular!-expt(3,m) neq 1 then return nil;
   i:=20;
   while (!*mod!*:=2**i)<n do i:=i+4;
      % construct (2**l)*m from n-1
   while evenp m do << m:=m/2; l:=l+1 >>;
   i:=1;
   result:=t;
   b2m:=mkvect l;
   while result and i<=!*confidence!* do <<
         % pick a potential witness
         % make a vector of b**(2*m) up to b**((2**l)*m)
      x:=putv(b2m,1,modular!-expt(remainder(random(!*mod!*),n),m+m));
      for j:=2:l do x:=putv(b2m,j,modular!-times(x,x));
         % neq 1 implies a witness that n is composite
      if getv(b2m,l)=1 then
         for j:=1:l do <<
            if result then <<
               x:=gcdn(getv(b2m,j)-1,n);
               if (x neq 1) and (x neq n) then result:=nil
            >>
         >>
      else result:=nil;
      i:=i+1
   >>;
   return result
end;
 
symbolic procedure general!-primep n;
% Based on an algorithm of M.Rabin published in the Journal of Number
% Theory Vol 12, pp 128-138 (1980).  This version uses general modular
% arithmetic which is somewhat more expensive than the above routine
begin scalar i,m,l,b2m,result,x,!*mod!*;
   m:=n-1;
   l:=0;
   set!-general!-modulus n;
      % first a quick check for compositeness
   if general!-modular!-expt(3,m) neq 1 then return nil;
   i:=32;
   while (!*mod!*:=2**i)<n do i:=i+4;
      % construct (2**l)*m from n-1
   while evenp m do << m:=m/2; l:=l+1 >>;
   i:=1;
   result:=t;
   b2m:=mkvect l;
   while result and i<=!*confidence!* do <<
         % pick a potential witness
         % make a vector of b**(2*m) up to b**((2**l)*m)
      x:=putv(b2m,1,
              general!-modular!-expt(remainder(random(!*mod!*),n),m+m));
      for j:=2:l do x:=putv(b2m,j,general!-modular!-times(x,x));
         % /=1 implies a witness that n is composite
      if getv(b2m,l)=1 then
         for j:=1:l do <<
            if result then <<
               x:=gcdn(getv(b2m,j)-1,n);
               if (x neq 1) and (x neq n) then result:=nil
            >>
         >>
      else result:=nil;
      i:=i+1
   >>;
   return result
end;
 
endmodule;


end;
