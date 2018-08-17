module zfactor;  % Integer factorization.

% Author: Julian Padget.
% Modifications by: Fran Burstall, John Abbott, Herbert Melenk,
%                   Arthur Norman.

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


exports nextprime, primep, zfactor, zfactor1, nrootnn;

% nextprime - returns the next prime GREATER than its argument;
% primep - determines whether argument is prime or not;
% zfactor - returns an alist of factors dotted with their multiplicities

imports evenp, gcdn, general!-modular!-expt, general!-modular!-times,
idifference, igreaterp, ilessp, iplus2, iroot, isqrt, leq,
modular!-expt, modular!-times, neq, prepf, prin2t, random, reversip,
set!-general!-modulus, set!-modulus, set!-small!-modulus, typerr;

% needs bigmod,smallmod;
%
% internal-functions add-factor, general-primep, mcfactor!*,
% internal-primep, mcfactor, small-primep;

% Parameters to this module are:
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
%        first part of the factorization where trial division is
%        employed.
%
%    !*last!-prime!-in!-list!* - the largest prime in the !*primelist!*

fluid '(!*maxtrys!*);

!*maxtrys!*:=10;

global '(!*last!-prime!-squared!* !*primelist!*
         !*last!-prime!-in!-list!* largest!-small!-modulus);

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

!*last!-prime!-squared!* := !*last!-prime!-in!-list!*^2;

symbolic procedure add!-factor(n,l);
   (lambda (p); if p then << rplacd(p,add1 cdr p); l>> else (n . 1) . l)
      if pairp l then if n>(caar l) then nil else assoc(n,l) else nil;

symbolic procedure zfactor n; zfactor1(n,t);

symbolic procedure zfactor1(n,bool);
   % If bool is NIL, mcfactor!* isn't used.
   if n<0 then ((-1) . 1) . zfactor1(-n,bool)
    else if n<4 then list(n . 1)
    else begin scalar primelist,factor!-list,p,qr;
       primelist := !*primelist!*;
       factor!-list := nil;
       while primelist do
        <<p := car primelist; primelist := cdr primelist;
          while cdr(qr := divide(n, p)) = 0 do
            <<n:= car qr; factor!-list:= add!-factor(p,factor!-list)>>;
       if n neq 1 and p*p>n
         then <<primelist := nil;
                factor!-list:=add!-factor(n,factor!-list);
                n := 1>>>>;
       return if n=1 then factor!-list
               else if null bool then (n . 1) . factor!-list
               else mcfactor!*(n,factor!-list)
     end;

symbolic procedure mcfactor!*(n,factors!-so!-far);
   if internal!-primep n then add!-factor(n,factors!-so!-far)
    else <<n:=(lambda (p,tries); <<
         while (atom p) and (tries<!*maxtrys!*) do <<
            tries:=tries+1;
            p:=mcfactor(n,tries)>>;
         if tries>!*maxtrys!* then <<
            prin2 "ZFACTOR(mcfactor!*): Assuming ";
            prin2 n; prin2t " is prime";
            p:=list n>>
         else p>>)
          (mcfactor(n,1),1);
   if atom n then add!-factor(n,factors!-so!-far)
   else if car n < cdr n then
      mcfactor!*(cdr n,mcfactor!*(car n,factors!-so!-far))
   else mcfactor!*(car n,mcfactor!*(cdr n,factors!-so!-far))>>;

symbolic procedure mcfactor(n,p);
% Based on "An Improved Monte-Carlo Factorisation Algorithm" by
% R.P.Brent in BIT 20 (1980) pp 176-184.  Argument n is the number to
% factor, p specifies the constant term of the polynomial.  There are
% supposed to be optimal p's for each n, but in general p=1 works well.
begin scalar gg,k,m,q,r,x,y,ys;
   m := 20;
   y:=0; r:=q:=1;
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

global '(has!-primep64!*);
has!-primep64!* := not null getd 'primep64;

symbolic procedure primep n;
% Returns T if n is prime (an integer that is not zero or a unit).
   if not fixp n then typerr(n,"integer")
    else if n<0 then primep(-n)
% CSL now has a built-in function primep64 that can test any integer up to
% 64-bits (unsigned)...
    else if has!-primep64!* and n < 0x10000000000000000 then primep64 n
    else if n <= 0xffffffff and
            n <= largest!-small!-modulus then primep32 n
    else if evenp n or
       remainder(n,3) = 0 or
       remainder(n,5) = 0 or
       remainder(n,7) = 0 then nil
% I will always start with a test using base 2.
    else if not general!-miller!-rabin(2, n) then nil
% If n < 2^64 one can guarantee correct results by using a special set of 7
% witness values determined by Sinclair in 2011. In a while I intend to
% replace this with a hashed version using a smaller number of bases.
% but providing a correct version first seems good, even though in this
% form the BPSW general case might in fact be faster.
    else if n < 0x10000000000000000 then
      general!-miller!-rabin(325, n) and
      general!-miller!-rabin(9375, n) and
      general!-miller!-rabin(28178, n) and
      general!-miller!-rabin(450775, n) and
      general!-miller!-rabin(9780504, n) and
      general!-miller!-rabin(1795265022, n)
% For yet larger cases I use BPSW, which follows up the base 2 Miller Rabin
% with a Strong Lucas test. This is certainly known to give correct answers
% up to 2^64, and while it is expected that there will be BPSW-pseudoprimes
% there are (at the time of writing) no known ones at all, and some estimates
% that the smallest may be greater than 10^10000
% (http://mathworld.wolfram.com/Baillie-PSWPrimalityTest.html).
    else lucas_test n;

flag('(primep),'boolean);

symbolic procedure internal!-primep n;
   primep n;

% The next few functions are ones that could be implemented within the
% Lisp system (at least if its bignum representation was in binary!) in
% rather easy ways. The code here can serve as an explanation and a
% reference implementation.

% My initial idea here had been that if there were functions that might
% be built in to SOME but not ALL of the Lisp system then I could guard
% portable definitions with "#if (not (getd 'foo))". That is a good idea,
% but if fails when a bootstrap bersion of Reduce is built (thereby
% defining the function) and that is then used to build the final version
% of the module. To cope with that I arrange that when I define a portable
% version of a function I flag its name with 'rlisp, and then during the
% final definitive build I will see that and understand that I need to
% instate it.

#if (or (not (getd 'lsd)) (flagp 'lsd 'rlisp))

% Find least significant bit of an integer. c.f. msd and integer!-length,
% and before using any of these check whether counting treats the lowest bit
% of a number as "bit 0" or as "bit 1". This function and msd treat it as
% "bit 1" which is what Reduce historically wanted. But logbitp uses a
% zero-based bit labelling.

symbolic procedure lsd n;
  begin
    scalar r;
    if n = 0 then return 0;
    r := 1;
    while land(n, 0xffffffffffffffff) = 0 do <<
      n := lshift(n, -64);
      r := r + 64 >>;
    if land(n, 0xffffffff) = 0 then << n := lshift(n, -32); r := r + 32 >>;
    if land(n, 0xffff) = 0 then << n := lshift(n, -16); r := r + 16 >>;
    if land(n, 0xff) = 0 then << n := lshift(n, -8); r := r + 8 >>;
    if land(n, 0xf) = 0 then << n := lshift(n, -4); r := r + 4 >>;
    if land(n, 0x3) = 0 then << n := lshift(n, -2); r := r + 2 >>;
    if land(n, 0x1) = 0 then r := r + 1;
    return r;
  end;

flag('(lsd), 'rlisp);

#endif

#if (or (not (getd 'logbitp)) (flagp 'logbitp 'rlisp))

% Test if bit i is set in the binary representation of n. I rather expect
% that for large i this will yield true when n is negative, as one would
% expect if the notional representation of a negative number (in 2s
% complement representation) has an unending sequence of leading 1 bits.

symbolic procedure logbitp(i, n);
  not zerop land(n, lshift(1, i));

flag('(logbitp), 'rlisp);

#endif

#if (or (not (getd 'integer!-length)) (flagp 'integer!-length 'rlisp))

% Determine the number of bits needed to represent an integer in binary. For
% negative numbers this is the number of bits not counting the sign bit... a
% convention adopted by Common Lisp. Thus the results should be
%        integer!-length -6  =>  3
%        integer!-length -5  =>  3
%        integer!-length -4  =>  2
%        integer!-length -3  =>  2
%        integer!-length -2  =>  1
%        integer!-length -1  =>  0
%        integer!-length 0   =>  0
%        integer!-length 1   =>  1
%        integer!-length 2   =>  2
%        integer!-length 3   =>  2
%        integer!-length 4   =>  3
%        integer!-length 5   =>  3
%        integer!-length 6   =>  3

symbolic procedure integer!-length n;
  begin
    scalar r;
    if n < 0 then n := -n-1;
    if n = 0 then return 0;
    r := 1;
% I shift in chunks of 64 first
    while n >= 0x10000000000000000 do <<
       n := lshift(n, -64);
       r := r + 64 >>;
    if n >= 0x100000000 then << n := lshift(n, -32), r := r + 32 >>;
    if n >= 0x10000 then << n := lshift(n, -16), r := r + 16 >>;
    if n >= 0x100 then << n := lshift(n, -8), r := r + 8 >>;
    if n >= 0x10 then << n := lshift(n, -4), r := r + 4 >>;
    if n >= 0x4 then << n := lshift(n, -2), r := r + 2 >>;
    if n >= 0x2 then r := r + 1;
    return r
  end;

flag('(integer!-length), 'rlisp);

#endif

global '(witness!-table oddprime!-bitmap);

% This is a table of 64 32-bit integers, so 2048 bits in all, reporting
% whioch of the odd numbers up to 4096 are prime using a simple bitmap
% lookup.

oddprime!-bitmap := list!-to!-vector
  '(0x64b4cb6e  0x816d129a  0x864a4c32  0x2196820d  0x5a0434c9  0xa4896120 
    0x29861144  0x4a2882d1  0x32424030  0x08349921  0x4225064b  0x148a4884 
    0x6c304205  0x0b40b408  0x125108a0  0x65048928  0x804c3098  0x80124496 
    0x41124221  0xc02104c9  0x00982d32  0x08044900  0x82689681  0x220825b0 
    0x40a28948  0x90042659  0x30434006  0x69009244  0x08088210  0x12410da4 
    0x2400c060  0x086122d2  0x821b0484  0x0110d301  0xc044a002  0x14916022 
    0x04a6400c  0x092094d2  0x00522094  0x4ca21008  0x51018200  0xa48b0810 
    0x44309a25  0x034c1081  0x80522502  0x20844908  0x18003250  0x241140a2 
    0x01840128  0x0a41a001  0x36004512  0x29260008  0xc0618283  0x10100480 
    0x4822006d  0xc20c2658  0x24894810  0x45205820  0x19002488  0x10c02502 
    0x01140868  0x802832ca  0x264b0400  0x60901300); 

% All the values in this table are in fact 16-bit unsigned integers. See
% the directory csl/cslbase/mr in the Reduce source tree for further
% commentary and explanation.

witness!-table := list!-to!-vector
  '(17490   5756   7143  10476  13223   5143  54949  46324  11327  21776 
       14  11348   1837  11945  17130    814  24668  27778  29292  12320 
    27999  24665    217   2136    370  15513  11577  11464   9734   5117 
     4796  11231   1760   9541  13930   1807  10976  11212  46077  10885 
    13981    148    415   4031  26689   9236   2257  14300    183   6148 
    31088   7970   6283    556   2674   6442   3501  17049  20938  44337 
     7812   4627  21294   6768   5134  40093   4662    774  12178  10453 
    16975  20017   3405  32346  11745    294  14936  20713   3371  13471 
     3728   4090  40339  57759  22007   1115  24211  10564  13850  11754 
     2278   5745  16753  51913  13076   1160   2581  13858  13147   1072 
    44224   5022   1417  19493  39737   6276   6792   4207   6345  40285 
    23786  51941   4542   3302   9249   6428  35246   4981   9628   9231 
    23685  15481   2335  34333  27605  11926   6602   6167   2161   6073 
    10601   4248  46263   2678   6247   8332   5569   4439  50964   2326 
    17596   1511  43893  11640   2691  40811   4676  32329   3214  18961 
     9118   3713  41097   4067   9690   8901   3074     67   3153    985 
    33378   8698  16533  41199  47465  47912  21939  21286    652  21348 
    12998   3723   1294   8768   7897  60772   9880  25647   5644   1481 
    16626   1608  16379  25558    176   5553  17031   9330   6323   2764 
     5798   4108   6234  51499  19125   1845  22910   9111   5817  55318 
     2221   7784  13964  46759   3442  14692   6748   6657   7293   1576 
      330  27166   1625  10388  16052   6421);

fluid '(!*trace_primep);
!*trace_primep := nil;

symbolic procedure primep32 n;
  begin integer l,m,x,y,w,save; scalar result;
% First deal with any input up to 4096 using simple table look-up. That
% should be very fast!
    if n < 0 then n := -n; % sShould not arise, but done here to be safe.
    if n <= 4096 then <<
      if !*trace_primep then
        printf("%fTesting %w. <= 4096 so use table lookup%n", n);
      if evenp n then return (n = 2)
      else return logbitp(remainder(n/2, 32), getv(oddprime!-bitmap,n/64)) >>
% Now if I look at the number modulo 42 I can detect cases where the
% input is a multiple of 2, 3 or 7. logbitp uses the "magic" integer constant
% here as a vector of bits to look up the result in.
    else if logbitp(remainder(n, 42), 0x000001df5d75d7dd) then return nil
% In a similar way multiples of 5 and 11 can be filtered out.
    else if logbitp(remainder(n, 55), 0x0004310a42508c21) then return nil;
% Now I have a value over 4096 that does not have any factors lower than 13.
% The next 3 lines compute a hash function and use it to extract a
% witness from a carefully pre-computed table so that the Miller Rabin test
% will be reliable on all integers up to 2^32 that have not already been
% sorted out by special cases above.
% The next line has as its intent "multiply n but the given 64-bit
% constant and only keep the low 64 bits of the result".
    w := 0x8bd03fd5cb49666b*n;
% I now have a 64-bit intermediate value. I shift it right by 31 bits to
% discard low order bits and then take the remainder by my table size. I
% need to do the mask operation here to ger results that match the C code,
% because a case ti (unsigned int) has effects that were in fact not what I
% had probably first intended! But that are what the hash table is built
% to work with.
    w := land(lshift(w, -31), 0xffffffff); % Leaves a positive result.
    w := remainder(w, 216);
    if !*trace_primep then printf("%fTesting %w which hashes to %w,", n, w);
    w := getv(witness!-table, w);
    if !*trace_primep then printf(" so use base %w%n", w);
% Start implementation of Miller-Rabin... which will only be use on
% numbers up to largest!-small!-modulus.
    save := set!-small!-modulus n;
    m := n-1;
% Express n-1 = (2^l)*m
%      l:=0;
%      while evenp m do <<m := m/2; l := l+1>>;
    l := sub1 lsd m;
    m := m / lshift(1, l);
    x := modular!-expt(w, m);
    if !*trace_primep then printf("%w = %w * %w, and %w^%w = %w%n",
       n-1, m, lshift(1, l), w, m, x);
    result:=t;
    if x neq 1 then <<
      for k:=1:l do <<
        y := modular!-times(x,x);
        if !*trace_primep then <<
          m := 2*m;
          printf("%w^%w = %w%n", w, m, y) >>;
        if y=1 and x neq (n-1) and x neq 1 then result := nil
        else x := y >>;
      if x neq 1 then result := nil >>;
    set!-small!-modulus save;
    if !*trace_primep then printf("result is %w%n", result);
    return result
  end;

% This is a version of primep written by FEB for inclusion in zfactor.
% It has been updated by ACN.

% Test n for primality using Miller-Rabin with base w. This version of the
% code is for used with arbitrarily large inputs, and will in fact just
% be needed when n is at least largest!-small!-modulus.

symbolic procedure general!-miller!-rabin(w, n);
  begin
    scalar m, save, l, result, x, y;
    if !*trace_primep then
      printf("%fGeneral M-R test on %w using base %w%n", m, w);
    m := n-1;
    save := set!-general!-modulus n;
% Express n-1 = (2^l)*m
    l:=0;
    while evenp m do << m := m/2; l := l+1 >>;
    result := t;
% Raise to the odd power.
    x := general!-modular!-expt(w, m);
    if !*trace_primep then
      printf("%w^%w = %w%n", w, m, x);
% From here I can complete the calculation of w^(n-1) by doing a
% sequence of squaring operations.  While I do that I check to see if I
% come across a non-trivial square root of 1, and if I do then I know n
% could not have been prime.
    if x neq 1 then <<
      for k:=1:l do <<
        y := general!-modular!-times(x,x);
        if !*trace_primep then <<
          m := 2*m;
          printf("%w^%w = %w%n", w, m, y) >>;
% It is tolerable to continue round the loop after setting result=nil
% because I will then be repeating a squaring of 1, which is cheap.
        if y=1 and x neq (n-1) and x neq 1 then result := nil
        else x := y >>;
% Also if I do not get to 1 at the end then the number is composite.
         if x neq 1 then result := nil >>;
    set!-general!-modulus save;
    if !*trace_primep then printf("result = %w%n", result);
    return result
  end;

symbolic procedure general!-primep n;
% Based on an algorithm of M.Rabin published in the Journal of Number
% Theory Vol 12, pp 128-138 (1980).
  begin
    if n < 0 then n := -n;
% Filter out some easy cases first
    if evenp n or
       remainder(n,3) = 0 or
       remainder(n,5) = 0 or
       remainder(n,7) = 0 then return nil;
% I will always start with a test using base 3.
    if not general!-miller!-rabin(2, n) then return nil;
% If n < 2^64 one can guarantee correct results by using a special set of 7
% witness values determined by Sinclair in 2011:
    if n < 0x10000000000000000 then <<
% I will be able to improve on this using hashing, but for now I want
% a version of this code that I dare to check-in.
      if not general!-miller!-rabin(325, n) then return nil;
      if not general!-miller!-rabin(325, n) then return nil;
      if not general!-miller!-rabin(9375, n) then return nil;
      if not general!-miller!-rabin(28178, n) then return nil;
      if not general!-miller!-rabin(9780504, n) then return nil;
      if not general!-miller!-rabin(1795265022, n) then return nil;
      return t >>;
% For yet larger cases I use BPSW, which follows up the base 2 Miller Rabin
% with a Strong Lucas test. This is certainly known to give correct answers
% up to 2^64, and while it is expected that there will be BPSW-pseudoprimes
% there are (at the time of writing) no known ones at all, and some estimates
% that the smallest may be greater than 10^10000
% (http://mathworld.wolfram.com/Baillie-PSWPrimalityTest.html).
    return lucas_test n
  end;

% The implementation of primep is:
%   up to 2^32     a single Miller-Rabin test with witness selected using
%                  a hash table.
%   up to 2^64     4 Miller-Rabin tests, where the first 3 used fixed bases
%                  but the fourth uses one selected using a hash table.
%                  (at present I use a deterministic set of 7 bases, because
%                  I have not merged in the hashing code).
% The above cases should be 100% reliable.
%   over 2^64      one Miller-Rabin using base 2, followed by one Strong
%                  Lucas test. At the time of writing this (June 2017) I
%                  believe that there are no known cases where this fails,
%                  but it is expected that for large enough numbers there
%                  will be some pseudoprimes. This is the Baillie-PSW test,
%                  and the Lucas part of it is sufficiently more expensive
%                  than a few extra Miller-Rabin rounds that it is not the
%                  scheme of choice for up to 2^64.
% For heavy-duty security-related applications I see suggestions of
% a modest number of Miller-Rabin rounds using reliable random bases,
% followed by a single Lucas test. But current predictions are that the
% code I give here yields correct judgements on all integer inputs with
% up to at least 10000 digits.



% This computes the Jacobi symbol. As in the number theory function
% related to Legendre Symbols and perhaps quadratic residues.

#if (or (not (getd 'jacobi!-symbol)) (flagp 'jacobi!-symbol 'rlisp))

symbolic procedure jacobi!-symbol(a, b);
  if b <= 0 or evenp b then 0
  else begin
    scalar j, r;
    j := 1;
    if a < 0 then <<
      a := -a;
      if land(b, 3) = 3 then j := -j >>;
% a and b are both positive here, so the use of REMAINDER lower down is safe.
    while not zerop a do <<
      while evenp a do <<
        a := a/2;
        if (r := land(b, 7)) = 3 or r = 5 then j := -j >>;
      r := a;
      a := b;
      b := r;
      if land(a, 3) = 3 and land(b, 3) = 3 then j := -j;
      a := remainder(a, b) >>;
    if b = 1 then return j
    else return 0
  end;

flag('(jacobi!-symbol), 'rlisp);

#endif

#if (or (not (getd 'is!-perfect!-square)) (flagp 'is!-perfect!-square 'rlisp))

% I expect that this can be be implemented better within the Lisp, among
% other things using the representation of a bignum to generate an initial
% estimate for the square root and folding the final test into the
% square root iteration. But this portable version is neat and concise!

symbolic procedure is!-perfect!-square n;
  n = r*r where r = isqrt n;

flag('(is!-perfect!-square), 'rlisp);

#endif

% This  code for the Lucas test will only be invoked if small factors
% for c have been rules out. In particular c will certainly be odd. It
% returns true if c is a Lucas probable-prime.

symbolic procedure lucas_test c;
  begin
    scalar d, j, k, kk, u, v, q, qk, l, ll, tmp, savemod;
% Find a proper value for D such that jacobi(d,c)=-1. This is achieved
% by trying the sequence 5, -7, 9, -11, 13, -15, 17, -19, 21, -23,....
% until one works (note that 9 and 25 can not work because they are perfect
% squares, but they are included in the test sequence anyway. It is very much
% expected that almost always a suitable d will be found within the first
% couple of tries. If the input c had been a perfect square then there will
% never be a valid d, so if I am searching for longer than expected I will
% divert and check for that. At present the world believe that even for the
% biggest inputs one could envisage here that the value of d found will be
% small.
    d := 5;
    while (j := jacobi!-symbol(d, c)) > 0 and
          (d neq 21 or not is!-perfect!-square c) do
      if d > 0 then d := -d - 2
      else d := -d + 2;
    if !*trace_primep then printf("%fTest %w using D=%w, j=%w%n", c, d, j);
% j would be zero if d and c had a non-trivial gcd (and hence unless
% |d|=c and d is a prime c is certainly composite. Well in the big picture
% I will only be using this when c > 2^64 and for d to get that large would
% take more time than could possibly be feasible.
% j would be 1 if I exited because c was a perfect square, and again that
% means it is not prime. Well if c = |d| then c might still be a prime!
    if j >= 0 then return (c=abs d and primep32 c);
% The sequence of values for d that are tried guarantee that the divison
% by 4 here is always exact.
    q := (1-d)/4;
    if !*trace_primep then printf("will use P=1, Q=%w%n", q);
% Another cheap test for easy cases that could detect c being composite, and
% where c > 2^24 and d having been found by checking in an arithmetic
% progression means I can not have q prime and q = c.
    if gcdn(c, q) neq 1 then return nil;
    k := c+1;
    savemod := set!-general!-modulus c;
% I now set up a Lucas sequence with initial values u_0=1, v_0=2, u_1=1, v_1=1
% and the general iteration u_{n} = u_{n-1} - q u_{n-2}. In terms of articles
% about Lucas sequences this is the special case where p=1.
    u := 1;
    v := 1;
%-- % For small examples I can compute the Lucas sequence in a naive manner
%-- % and display all the values. This is intended to be useful for comparison
%-- % with the values calculated below using the more sophisticated method.
%-- % The cut-off at 500 is entirely arbitrary, but tabulating more than 500
%-- % lines of sequence would start to get clumsy.
%--     if !*trace_primep then begin
%--       scalar nn, w, u0, u1, ut, v0, v1, vt;
%--       w := c+1;
%-- % I will tabulate the values of k that the doubling method will go via..
%--       while w neq 0 do <<
%--         nn := w . nn;
%--         if evenp w then w := w/2 else w := w-1 >>;
%--       u0 := 0; u1 := 1;
%--       v0 := 2; v1 := 1;
%--       for i := 1:(c+1) do <<
%--         ut := u1 - q*u0;
%--         vt := v1 - q*v0;
%--         u0 := u1; u1 := ut;
%--         v0 := v1; v1 := vt;
%-- % I display k, u_k, v_k and then those two values modulo c, just in the
%-- % cases that should arise in the cleverer doubling code. I will display the
%-- % exact integer values if they are small enough to fit on the line, otherwise
%-- % the annotation "<huge>"
%--         if abs u0 <= 99999999999999999999999999 then ut := u0
%--         else ut := "<huge>";
%--         if abs v0 <= 99999999999999999999999999 then vt := v0
%--         else vt := "<huge>";
%--         if i member nn then printf("%f%w:%t[%w, %w]%t%w %t%w%n",
%--                i, 7, mod(u0, c), mod(v0, c), 24, ut, 51, vt)  >>
%--     end;
% For subsequent arithmetic to work properly I must ensure that even if
% q starts off negative I have a version of it reduced to the range [0,c) to
% work with. Similarly d. The variable qk will hold q^k where k is an index
% into the Lucas sequence. 
    qk := q := general!-modular!-number q;
    d := general!-modular!-number d;
% I will iterate downwards over bits in a binary representation of (c+1).
% well to implement a Strong Lucas Test I need to iterate down until I
% have no more below bits set in k.
    l := sub1 integer!-length k;
    ll := sub1 lsd k;
    if !*trace_primep then
      printf("k=%w uses %w bits and has %w trailing zero bits%n",
             k, add1 l, ll);
% I will first do the part of the Lucas sequence up to where it will have
% used up all the nonzero bits in the representation of k. kk will track how
% far I have gone, and is only needed for trace output but tracking it is
% cheap.
    kk := 1;
    if !*trace_primep then printf "1:     [1, 1]%n"; % Always the start-line!
    while (l := l-1) >= ll do <<
% I can double a subscript in the Lucas sequence using:
%    u_{2k} := u_{k} v_{k}
%    v_{2k} := v_{k}^2 - 2 qk_{k}
%    qk_{2k}:= qk_{k} qk_{k}
% and happily I can do those updates sequentially.
      u := general!-modular!-times(u, v);
      v := general!-modular!-difference(general!-modular!-times(v, v),
                                        general!-modular!-times(2, qk));
      kk := 2*kk;
      qk := general!-modular!-times(qk, qk);
      if !*trace_primep then printf("%f%w: %t[%w, %w] q^k=%w%n", kk, 7, u, v, qk);
if !*trace_primep then printf("(A) l=%w ll=%w k=%w logbit=%w%n", l, ll, k, logbitp(l, k));
% Now I need to do a step whenever there is a "1" bit in the binary
% representation of k.
      if logbitp(l, k) then <<
% The rule used here is:
%    u_{k+1} = (u_{k} + v_{k})/2
%    v_{k+1} = (d u_{k} + v_{k})/2
%    qk_{k+1}= q qk_{k}
% and again all the arithmetic is to be done modulo c. I need a temporary
% veriable when updating u and v since each depends on the other.
        tmp := general!-modular!-plus(u, v);
        v := general!-modular!-plus(general!-modular!-times(d, u), v);
        u := tmp;
% Dividing by 2 when I have an even modulus is something I can write out
% in-line here rather easily, and I expect this to be nicer than using
% general!-modular!-quotient or even that having computed a modular reciprocal of 2
% and doing a modular multiplication by it.
        if not evenp u then u := u + c;
        u := u/2;
        if not evenp v then v := v + c;
        v := v/2;
        kk := kk+1;
        qk := general!-modular!-times(q, qk);
        if !*trace_primep then printf("%f%w: %t[%w, %w] q^k=%w%n", kk, 7, u, v, qk)
      >>
    >>;
% From now on I will only do doubling operations, and they are of the form
%      u := u*v;
% so if u is zero now I can be certain that it will be at the end, and the
% Regular (as distinct from Strong) Lucas test will be passed.
    if u = 0 then <<
      if !*trace_primep then printf("u=0 so value is probably prime%n");
      set!-general!-modulus savemod;
      return t >>; % Probably prime!
% Now all the rest of the Lucas sequence is done using just the "doubling"
% process. But I am no longer interested in u.
    if !*trace_primep then <<
      printf("After final non-doubling step u = %w%n", u);
      printf("Will just do doubling steps from now on...%n") >>;
    while v neq 0 and (l := l-1) >= 0 do <<
% I can again double a subscript in the Lucas sequence using:
%    v_{2k} := v_{k}^2 - 2 qk_{k}
%    qk_{2k}:= qk_{k} qk_{k}
      v := general!-modular!-difference(general!-modular!-times(v, v),
                                        general!-modular!-times(2, qk));
      kk := 2*kk;
      qk := general!-modular!-times(qk, qk);
% I do not compute u here because at each stage I just multiply u by v. If
% I have a prime then this is a field multiplication and u can only end up zero
% if some v is zero.
      if !*trace_primep then printf("%f%w: %t[??, %w] qk=%w%n", kk, 7, v, qk);
if !*trace_primep then printf("(B) l=%w ll=%w k=%w logbit=%w%n", l, ll, k, logbitp(l, k));
    >>;
if !*trace_primep then printf("exit loop with l = %w and v = %w%n", l, v);
% If at this point v=0 then c is a Strong Lucas Probable-prime using the
% values p=1 and q as derived here.
    set!-general!-modulus savemod;
    return (v = 0)
  end;



% The next function comes from J.H. Davenport.

symbolic procedure nextprime p;
   % Returns the next prime number bigger than p.
   if null p or p=0 or p=1 or p=-1 or p=-2 then 2
    else if p=-3 then -2
    else if not fixp p then typerr(!*f2a p,"integer")
    else begin
       if evenp p then p:=p+1 else p:=p+2;
       while not primep p do p:=p+2;
       return p
   end;

put('nextprime,'polyfn,'nextprime);

% The following definition has been added by Herbert Melenk.

symbolic procedure nrootnn(n,x);
   % N is an integer, x a positive integer. Value is a pair
   % of integers r,s such that r*s**(1/x)=n**(1/x). The decomposition
   % may be incomplete if the number is too big. The extraction of
   % the members of primelist* is complete.
   begin scalar pl,signn,qr,w; integer r,s,p,q;
     r := 1; s := 1;
     if n<0 then <<n := -n; if evenp x then signn := t else r := -1>>;
     pl:= !*primelist!*;
loop:
     p:=car pl; pl:=cdr pl; q:=0;
     while cdr (qr:=divide(n,p))=0 do <<n:=car qr; q:=q #+ 1>>;
     if not (q #< x) then
         <<w:=divide(q,x); r:=r*(p**car w); q:=cdr w>>;
     while q #> 0 do <<s:=s*p; q:=q #- 1>>;
     if car qr < p then << s:=n*s; goto done>>;
     if pl then goto loop;
       % heuristic bound for complete factorization.
     if 10^20 > n then
     <<q:=mcfactor!*(n,nil);
       for each j in q do
         <<w := divide(cdr j,x);
           r := car j**car w*r;
           s := car j**cdr w*s>>;
     >>
      else if (q:=iroot(n,x)) then r:=r*q
      else s:=n*s;
done:
     if signn then s := -s;
     return r . s
   end;

endmodule;

end;

