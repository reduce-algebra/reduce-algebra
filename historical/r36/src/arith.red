module arith;  % Header module for real arith package.

% Last updated Dec 14, 1992

% Assumptions being made on the underlying arithmetic:
%
% (1) The integer arithmetic is binary.
%
% (2) It is possible to convert any lisp float into an integer
%     by applying fix, and this yields the result with the full
%     precision of the float.
%


create!-package('(arith smlbflot bfauxil paraset math rounded comprd
                  rdelem crelem bfelem), nil);

exports ashift, bfloat, bfminusp, bfnzp, bfp!:, bfzp, crim, crrl,
        divbf, ep!:, gfzerop, i2bf!:, lshift, make!:cr, make!:ibf,
        make!:rd, msd!:, mt!:, oddintp, preci!:, rdp, retag, rndpwr,
        sgn, tagrl, tagim, timbf;

imports eqcar, round!:mt;

fluid '(!*noconvert !:bprec!: dmode!*);

switch noconvert;

symbolic smacro procedure mt!: u;
   % This function selects the mantissa of U, a binary bigfloat
   % representation of a number.
   cadr u;

symbolic smacro procedure ep!: u;
   % This function selects the exponent of U, a binary bigfloat
   % representation of a number.
   cddr u;

symbolic smacro procedure make!:ibf (mt, ep);
   '!:rd!: . (mt . ep);

symbolic smacro procedure i2bf!: u; make!:ibf (u, 0);

symbolic smacro procedure make!:rd u;
   '!:rd!: . u;

symbolic smacro procedure rdp x;
   % This function returns true if X is a rounded number
   % representation, else NIL.  X is any Lisp entity.
   eqcar(x,'!:rd!:);

symbolic smacro procedure float!-bfp x; atom cdr x;

symbolic smacro procedure rd2fl x; cdr x;

symbolic smacro procedure fl2rd x; make!:rd x;

symbolic smacro procedure bfp!:(x);
   % This function returns true if X is a binary bigfloat
   % representation, else NIL.  X is any Lisp entity.
   rdp x and not float!-bfp x;

symbolic smacro procedure retag u;
   if atom u then u else '!:rd!: . u;

symbolic smacro procedure rndpwr j; normbf round!:mt(j,!:bprec!:);

symbolic procedure msd!: m;
  % returns the position n of the most significant (binary) digit
  % of a positive binary integer m, i.e. floor(log2 m) + 1
  begin integer i,j,k;
    j := m;
    while (j := ((k := j) / 65536)) neq 0 do i := i + 16;
    j := k;
    while (j := ((k := j) / 256)) neq 0 do i := i + 8;
    j := k;
    while (j := ((k := j) / 16)) neq 0 do i := i + 4;
    j := k;
    while (j := ((k := j) / 2)) neq 0 do i := i + 1;
    return (i + 1);
  end;

symbolic procedure ashift(m,d);
   % This procedure resembles loosely an arithmetic shift.
   %  It returns m*2**d
   if d=0 then m
    else if d<0 then m/2**(-d)
    else m*2**d;

symbolic procedure lshift(m,d);
   % Variant of ashift that is called ONLY when m>=0.
   %  This should be redefined for Lisp systems that provide
   %  an efficient logical shift.
   ashift(m,d);

symbolic smacro procedure oddintp n; not evenp n;

symbolic smacro procedure preci!: nmbr;
   % This function counts the precision of a number "n". NMBR is a
   % binary bigfloat representation of "n".
   msd!: abs mt!: nmbr;


symbolic smacro procedure divbf(u,v); normbf divide!:(u,v,!:bprec!:);

symbolic smacro procedure timbf(u,v); rndpwr times!:(u,v);

symbolic smacro procedure bfminusp u;
  if atom u then minusp u else minusp!: u;

symbolic smacro procedure bfzp u;
  if atom u then zerop u else mt!: u=0;

symbolic smacro procedure bfnzp u; not bfzp u;

symbolic smacro procedure bfloat x;
  if floatp x then fl2bf x
   else normbf(if not atom x then x
                else if fixp x then i2bf!: x
                else read!:num x);

symbolic smacro procedure rdfl2rdbf x; fl2bf rd2fl x;

symbolic smacro procedure rd!:forcebf x;
   % forces rounded number x to binary bigfloat representation
   if float!-bfp x then rdfl2rdbf x else x;

symbolic smacro procedure crrl x; cadr x;

symbolic smacro procedure crim x; cddr x;

symbolic smacro procedure make!:cr (re,im);
   '!:cr!: . (re . im);

symbolic smacro procedure crp x;
   % This function returns true if X is a complex rounded number
   % representation, else NIL.  X is any Lisp entity.
   eqcar(x,'!:cr!:);

symbolic smacro procedure tagrl x; make!:rd crrl x;

symbolic smacro procedure tagim x; make!:rd crim x;

symbolic smacro procedure gfrl u; car u;

symbolic smacro procedure gfim u; cdr u;

symbolic smacro procedure mkgf (rl,im); rl . im;

symbolic smacro procedure gfzerop u;
  if not atom gfrl u then mt!: gfrl u = 0 and mt!: gfim u = 0
   else u = '(0.0 . 0.0);

% symbolic smacro procedure sgn x;
%   if x>0 then 1 else if x<0 then -1 else 0;


global '(bfz!* bfhalf!* bfone!* bftwo!* bfthree!* bffive!* bften!*
         !:bf60!* !:180!* !:bf1!.5!*);

global '(!:bf!-0!.25        %0.25
         !:bf!-0!.0625      %0.0625
         !:bf0!.419921875   %0.419921875
        );

%Miscellaneous constants

bfz!* := make!:ibf(0,0);

bfhalf!* := make!:ibf(1,-1);

bfone!* := make!:ibf(1,0);

!:bf1!.5!* := make!:ibf (3, -1);

bftwo!* := make!:ibf (2, 0);

bfthree!* := make!:ibf (3, 0);

bffive!* := make!:ibf (5, 0);

bften!* := make!:ibf (5, 1);

!:bf60!* := make!:ibf (15, 2);

!:180!* := make!:ibf (45, 2);

!:bf!-0!.25 := make!:ibf(1,-2);

!:bf!-0!.0625 := make!:ibf (1, -4);

!:bf0!.419921875 := make!:ibf(215, -9);

% These need to be added to other modules.

symbolic procedure dn!:simp u;
  if car u = 0 then nil ./ 1
   else if u = '(10 . -1) and null !*noconvert then 1 ./ 1
   else if dmode!* memq '(!:rd!: !:cr!:)
    then rd!:simp cdr decimal2internal (car u, cdr u)
   else if cdr u >= 0 then !*f2q (car u * 10**cdr u)
   else simp {'quotient, car u, 10**(-cdr u)};

put ('!:dn!:, 'simpfn, 'dn!:simp);

symbolic procedure dn!:prin u;
  bfprin0x (cadr u, cddr u);

put ('!:dn!:, 'prifn, 'dn!:prin);

endmodule;


module smlbflot;   % Basic support for bigfloat arithmetic.

% Authors: S.L. Kameny and T. Sasaki.
% Modified for binary bigfloat arithmetic by Iain Beckingham and Rainer
% Schoepf.
% Modified for double precision printing by Herbert Melenk.

% Last change made Dec 8, 1992.

exports abs!:, bfexplode0, bflerrmsg, bfprin!:, bftrim!:, bfzerop!:,
        conv!:mt, cut!:ep, cut!:mt, decimal2internal, decprec!:,
        difference!:, divide!:, equal!:, fl2bf, greaterp!:, incprec!:,
        leq!:, lessp!:, max!:, max!:, max2!:, min!:, min2!:, minus!:,
        minusp!:, order!:, plus!:, read!:num, round!:mt, round!:last,
        times!:;

imports aconc, ashift, bfp!:, ceiling, conv!:bf2i, ep!:, eqcar, floor,
        geq, i2bf!:, leq, lshift, make!:ibf, msd!:, mt!:, neq, normbf,
        oddintp, preci!:, precision, prin2!*, rerror, retag, reversip;

fluid '(!*bfspace !*fullprec !*nat !:prec!: !:bprec!: !:print!-prec!:
        !:upper!-sci!: !:lower!-sci!:);

global '(!!nfpd !!nbfpd bften!* bfz!* fort_exponent);

switch bfspace,fullprec;

flag('(fort_exponent),'share);

!*bfspace := nil;

% !*fullprec := t;

!:lower!-sci!: := 10;

!:upper!-sci!: := 5;

symbolic procedure bflerrmsg u;
   % Revised error message for BFLOAT module, using error, not rederr.
   error(0,{"Invalid argument to",u});

symbolic procedure bfzerop!: u;
   % This is possibly too restricted a definition.
   mt!: u = 0;

symbolic procedure fl2bf x;
  (if zerop x then bfz!* else
   begin scalar s,r; integer d;
     if x<0 then <<x := -x; s := t>>;
     % convert x to an integer equivalent;
      r := normbf read!:num x;
      d := ep!: r+msd!: mt!: r;
      x := x*2.0**-d; x := x + 0.5/2**!:bprec!:;
      x := fix(x*2**!:bprec!:);
      return make!:ibf (if s then -x else x, d - !:bprec!:) end)
        where !:bprec!:=!!nbfpd;

symbolic procedure bfprin!: u;
%  if preci!: u>!!nbfpd then bfprin0 u
%   else (bfprin0 u where !*bfspace=nil);
   bfprin0 u;

symbolic procedure divide!-by!-power!-of!-ten (x, n);
  if n < 0 then bflerrmsg 'divide!-by!-power!-of!-ten
   else <<
     while n > 0 do <<
       if oddintp n then x := normbf divide!: (x, f, !:bprec!:);
       n := lshift (n, -1);
       f := normbf cut!:mt (times!: (f, f), !:bprec!:) >>;
     x >> where f := bften!*;

symbolic procedure multiply!-by!-power!-of!-ten (x, n);
  if n < 0 then bflerrmsg 'multiply!-by!-power!-of!-ten
   else <<
     while n > 0 do <<
       if oddintp n then x := normbf times!: (x, f);
       n := lshift (n, -1);
       f := normbf cut!:mt (times!: (f, f), !:bprec!:) >>;
     normbf cut!:mt (x, !:bprec!:) >> where f := bften!*;

global '(log2of10);

symbolic procedure round!:dec (x, p);
  %
  % rounds bigfloat x to p decimal places
  %
  begin scalar setpr; integer m, ex;
    if null p then p := if !:print!-prec!: then !:print!-prec!:
                         else !:prec!: - 2
     else if p > precision 0 then setpr := precision p;
    x := round!:dec1 (x,p);
    m := car x; ex := cdr x;
    x := i2bf!: m;
    if ex < 0 then x := divide!-by!-power!-of!-ten (x, -ex)
     else if ex > 0 then x := multiply!-by!-power!-of!-ten (x, ex);
    if setpr then precision setpr;
    return round!:mt (x, ceiling (p * log2of10))
  end;

symbolic procedure round!:dec1 (x, p);
  %
  % rounds bigfloat x to p decimal places
  % returns pair (m . ex) of mantissa and exponent to base 10,
  % m having exactly p digits
  % performs all calculations at at least current precision,
  % but increases the precision of the calculations to log10(x)
  % if this is larger
  %
  if bfzerop!: x then cdr x
   else (begin scalar exact, lo, sign; integer ex, k, m, n, l;
    %
    % We need to calculate the number k so that 10^(k+1) > |x| >= 10^k
    %  k = floor (log10 |x|) = floor (log2 |x| / log2of10);
    % We can easily compute n so that 2^(n+1) > |x| >= 2^n,
    %  i.e., n = floor (log2 |x|), since this is just order!:(x).
    % Since n+1 > log2 |x| >= n, it follows that
    %  floor ((n+1) / log2of10) >= k >= floor (n / log2of10)
    % I.e., if both bounds agree, we know k, otherwise we have to check.
    %
    if mt!: x < 0 then <<sign := t; x := minus!: x>>;
    n := order!: x;
    %
    % The division by log2of10 has to be done with precision larger than
    % the precision of n. In particular, log2of10 has to be calculated
    % to a larger precision.  Instead of dividing by log2of10, we
    % multiply by log10of2.
    %
    l := msd!: abs n;
    <<lo := divide!: (!:log2 !:bprec!:, !:log10 !:bprec!:, !:bprec!:);
      k := conv!:bf2i times!: (i2bf!: n, lo);
      if k = conv!:bf2i times!: (i2bf!: (n+1), lo) then exact := t>>
        where !:bprec!: := max (!!nbfpd, l + 7);
    %
    % For the following calculation the precision must be increased by
    % the precision of n. The is necessary to ensure that the mantissa
    % is calculated correctly for large values of the exponent. This is
    % due to the fact that if we multiply the number x by 10^n its
    % precision will be decreased by n.
    %
    !:bprec!: := !:bprec!: + l;
    %
    % since conv!:bf2i rounds always towards 0, we must correct for n<0
    %
    if n < 0 then k := k - 1;
    ex := k - p + 1;
    if ex < 0 then x := multiply!-by!-power!-of!-ten (x, -ex)
     else if ex > 0 then x := divide!-by!-power!-of!-ten (x, ex);
    if exact then nil
     else <<l := length explode conv!:bf2i x;
            if l < p then <<x := times!: (x, bften!*); ex := ex - 1>>
             else if l > p then <<x := divide!: (x, bften!*, !:bprec!:);
                                  ex := ex + 1>>>>;
    %
    % do rounding
    %
    x := plus!:(x, bfhalf!*);
    m := conv!:bf2i x;
    if length explode m > p then <<m := (m + 5) / 10; ex := ex + 1>>;
    if sign then m := -m;
    return (m . ex);
  end) where !:bprec!: := !:bprec!:;

% symbolic procedure internal2decimal (x, p);
  %
  % converts bigfloat x to decimal format, with precision p
  % Result is a pair (m . e), so that x = m*10^e, with
  % m having exactly p decimal digits.
  % Calculation is done with the current precision,
  % but at least with p + 2.
  %
%   begin scalar setpr;
%     if null p then p := if !:print!-prec!: then !:print!-prec!:
%                          else !:prec!: - 2
%      else if p > precision 0 then setpr := precision p;
%     x := round!:dec1 (x,p);
%     if setpr then precision setpr;
%     return x
%   end;


symbolic procedure bfprin0 u;
  begin scalar r; integer m, ex;
    r := round!:dec1 (u, if !:print!-prec!: then !:print!-prec!:
                          else !:prec!: - 2);
    m := car r; ex := cdr r;
    bfprin0x (m, ex)
  end;

symbolic procedure bfprin0x(m,ex);
  begin scalar lst; integer dotpos;
    lst := bfexplode0x(m,ex);
    ex := cadr lst;
    dotpos := caddr lst;
    lst := car lst;
    return bfprin!:lst (lst,ex,dotpos)
  end;

symbolic procedure bfexplode0 u;
  % returns a list (lst ex dotpos) where
  %  lst    = list of characters in mantissa
  %            (ie optional sign and digits)
  %  ex     = decimal exponent
  %  dotpos = position of decimal point in lst
  %            (note that the sign is counted)
  begin scalar r; integer m, ex;
    r := round!:dec1 (u,if !:print!-prec!: then !:print!-prec!:
                         else !:prec!: - 2);
    m := car r; ex := cdr r;
    return bfexplode0x (m, ex)
  end;


symbolic procedure bfexplode0x (m, ex);
  begin scalar lst, s; integer dotpos, l;
    if m<0 then <<s := t; m := -m>>;
    lst := explode m;
    l := length lst;
    if ex neq 0 and (l+ex < -!:lower!-sci!: or l+ex > !:upper!-sci!:)
      then <<dotpos := 1;
             ex := ex + l - 1>>
     else <<dotpos := l + ex;
            ex := 0;
            if dotpos > l - 1
              %
              % add dotpos - l + 1 zeroes at the end
              %
              then lst := nconc!*(lst,nlist('!0,dotpos - l + 1))
             else while dotpos < 1 do <<lst := '!0 . lst;
                                        dotpos := dotpos + 1>>>>;
    if s then <<lst := '!- . lst; dotpos := dotpos + 1>>;
    if null !*fullprec
      then <<lst := reversip lst;
             while lst and car lst eq '!0 and length lst > dotpos + 1 do
                lst := cdr lst;
             lst := reversip lst>>;
    return {lst, ex, dotpos}
  end;

symbolic procedure bfprin!:lst (lst, ex, dotpos);
  begin scalar result,ee,w; integer j;
    ee:='e;
    if !*fort and liter(w:=reval fort_exponent) then ee:=w else w:=nil;
    if car lst eq '!- and dotpos = 1 then <<dotpos := 2; ex := ex - 1>>;
    if ex neq 0 then if car lst eq '!- then <<ex := ex + dotpos - 2;
                                              dotpos := 2>>
                      else <<ex := ex + dotpos - 1; dotpos := 1>>
     else if dotpos = length lst then dotpos := -1;
    for each char in lst do <<
      result := char . result; j := j + 1; dotpos := dotpos - 1;
      if j=5 then <<if !*nat and !*bfspace then result := '!  . result;
                    j := 0>>;
      if dotpos = 0 then <<result := '!. . result; j := j + 1>>;
      if j=5 then <<if !*nat and !*bfspace then result := '!  . result;
                    j := 0>>>>;
    if ex neq 0 or w then <<
    if not (!*nat and !*bfspace) then result := ee . result
     else if j=0 then <<result := '!  . ee . result; j := 2>>
     else if j=1 then <<result := '!  . ee . '!  . result; j := 4>>
     else if j=2
      then <<result := '!  . '!  . ee . '!  . result; j := 0>>
     else if j=3 then <<result := '!  . ee . '!  . result; j := 0>>
     else if j=4 then <<result := '!  . ee . '!  . result; j := 2>>;
    lst := if ex > 0 then '!+ . explode ex else explode ex;
    for each char in lst do <<
      result := char . result; j := j + 1;
      if j=5 then <<if !*nat and !*bfspace then result := '!  . result;
                    j := 0>>>>>>;
    if !*nat then for each char in reversip result do prin2!* char
     else prin2!* compress('!" . reversip('!" . result))
  end;

symbolic procedure scientific_notation n;
   begin scalar oldu,oldl;
     oldu := !:upper!-sci!:; oldl := !:lower!-sci!: + 1;
     if fixp n
       then <<
         if n<0
           then rerror(arith,1,
                       {"Invalid argument to scientific_notation:",n});
         !:lower!-sci!: := n - 1; !:upper!-sci!: := n;
      >>
      else if eqcar(n,'list) and length n=3
       then if not (fixp cadr n and fixp caddr n)
              then rerror(arith,2,
                        {"Invalid argument to scientific_notation:",n})
             else <<!:upper!-sci!: := cadr n;
                    !:lower!-sci!: := caddr n - 1 >>;
     return {'list,oldu,oldl}   % Return previous range.
  end;

flag('(scientific_notation), 'opfn);

symbolic procedure order!: nmbr;
   % This function counts the order of a number "n".  NMBR is a bigfloat
   %  representation of "n".
   % **** ORDER(n)=k if 2**k <= ABS(n) < 2**(k+1)
   % ****     when n is not 0, and ORDER(0)=0.
   %
   if mt!: nmbr = 0 then 0 else preci!: nmbr + ep!: nmbr - 1;

symbolic smacro procedure decprec!:(nmbr, k);
   make!:ibf(ashift(mt!: nmbr,-k), ep!: nmbr + k);

symbolic smacro procedure incprec!:(nmbr, k);
   make!:ibf(ashift(mt!: nmbr,k), ep!: nmbr - k);

symbolic procedure conv!:mt(nmbr, k);
   % This function converts a number "n" to an equivalent number of
   % binary precision K by rounding "n" or adding "0"s to "n".
   % NMBR is a binary bigfloat representation of "n".
   %  K is a positive integer.
   if bfp!: nmbr and fixp k and k > 0
     then if (k := preci!: nmbr - k) = 0 then nmbr
           else if k < 0 then incprec!:(nmbr, -k)
           else round!:last(decprec!:(nmbr, k - 1))
    else bflerrmsg 'conv!:mt;

symbolic procedure round!:mt(nmbr, k);
   % This function rounds a number "n" at the (K+1)th place and returns
   % an equivalent number of binary precision K if the precision of "n"
   % is greater than K, else it returns the given number unchanged.
   % NMBR is a bigfloat representation of "n".  K is a positive integer.
   if bfp!: nmbr and fixp k and k > 0 then
      if (k := preci!: nmbr - k - 1) < 0 then nmbr
      else if k = 0 then round!:last nmbr
      else round!:last decprec!:(nmbr, k)
   else bflerrmsg 'round!:mt;

symbolic procedure round!:ep(nmbr, k);
% This function rounds a number "n" and returns an
%      equivalent number having the exponent K if
%      the exponent of "n" is less than K, else
%      it returns the given number unchanged.
% NMBR is a BINARY BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
  if bfp!: nmbr and fixp k then
    if (k := k - 1 - ep!: nmbr) < 0 then nmbr
      else if k = 0 then round!:last nmbr
      else round!:last decprec!:(nmbr, k)
   else bflerrmsg 'round!:ep$

symbolic procedure round!:last nmbr;
   % This function rounds a number "n" at its last place.
   % NMBR is a binary bigfloat representation of "n".
   << if m < 0 then << m := -m; s := t >>;
      m := if oddintp m then lshift (m, -1) + 1
            else lshift (m, -1);
      if s then m := -m;
      make!:ibf (m, e) >>
       where m := mt!: nmbr, e := ep!: nmbr + 1, s := nil;

symbolic procedure cut!:mt(nmbr,k);
% This function returns a given number "n" unchanged
%      if its binary precision is not greater than K, else it
%      cuts off its mantissa at the (K+1)th place and
%      returns an equivalent number of precision K.
% **** CAUTION!  No rounding is made.
% NMBR is a BINARY BIG-FLOAT representation of "n".
% K is a positive integer.
  if bfp!: nmbr and fixp k and k > 0 then
     if (k := preci!: nmbr - k) <= 0 then nmbr
             else decprec!:(nmbr, k)
   else bflerrmsg 'cut!:mt$

symbolic procedure cut!:ep(nmbr, k);
% This function returns a given number "n" unchanged
%      if its exponent is not less than K, else it
%      cuts off its mantissa and returns an equivalent
%      number of exponent K.
% **** CAUTION!  No rounding is made.
% NMBR is a BINARY BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
  if bfp!: nmbr and fixp k then
     if (k := k - ep!: nmbr) <= 0 then nmbr
        else decprec!:(nmbr, k)
   else bflerrmsg 'cut!:ep$

symbolic procedure bftrim!: v;
   normbf round!:mt(v,!:bprec!: - 3);

symbolic procedure decimal2internal (base10,exp10);
  if exp10 >= 0 then i2bf!: (base10 * 10**exp10)
   else divide!-by!-power!-of!-ten (i2bf!: base10, -exp10);

symbolic procedure read!:num(n);
   % This function reads a number or a number-like entity N
   %      and constructs a bigfloat representation of it.
   % N is an integer, a floating-point number, or a string
   %      representing a number.
   % **** If the system does not accept or may incorrectly
   % ****      accept the floating-point numbers, you can
   % ****      input them as strings such as "1.234E-56",
   % ****      "-78.90 D+12" , "+3456 B -78", or "901/234".
   % **** A rational number in a string form is converted
   % ****      to a bigfloat of precision !:PREC!: if
   % ****      !:PREC!: is not NIL, else the precision of
   % ****      the result is set 170.
   % **** Some systems set the maximum size of strings.  If
   % ****      you want to input long numbers exceeding
   % ****      such a maximum size, please use READ!:LNUM.
   if fixp n then make!:ibf(n, 0)
    else if not(numberp n or stringp n) then bflerrmsg 'read!:num
    else begin integer j,m,sign;  scalar ch,u,v,l,appear!.,appear!/;
          j := m := 0;
          sign := 1;
          u := v := appear!. := appear!/ := nil;
          l := explode n;
    loop: ch := car l;
          if digit ch then << u := ch . u; j := j + 1 >>
           else if ch eq '!. then << appear!. := t; j := 0 >>
           else if ch eq '!/ then << appear!/ := t; v := u; u := nil >>
           else if ch eq '!- then sign := -1
           else if ch memq '(!E !D !B !e !d !b) then go to jump;  %JBM
           if l := cdr l then goto loop else goto make;
    jump: while l := cdr l do
            <<if digit(ch := car l) or ch eq '!-
                 then v := ch . v >>;
          l := reverse v;
          if car l eq '!- then m := - compress cdr l
                          else m:= compress l;
    make: u := reverse u;
          v := reverse v;
          if appear!/ then
            return conv!:r2bf(make!:ratnum(sign*compress v,compress u),
                              if !:bprec!: then !:bprec!: else 170);
          if appear!. then j := - j else j := 0;
          if sign = 1 then u := compress u else u := - compress u;
          return round!:mt (decimal2internal (u, j + m), !:bprec!:)
                   where !:bprec!: := if !:bprec!: then !:bprec!:
                                       else msd!: abs u
    end;

symbolic procedure abs!: nmbr;
   % This function makes the absolute value of "n".  N is a binary
   % bigfloat representation of "n".
   if mt!: nmbr > 0 then nmbr else make!:ibf(- mt!: nmbr, ep!: nmbr);

symbolic procedure minus!: nmbr;
   % This function makes the minus number of "n".  N is a binary
   % bigfloat representation of "n".
   make!:ibf(- mt!: nmbr, ep!: nmbr);

symbolic procedure plus!:(n1,n2);
   begin scalar m1,m2,e1,e2,d; return
      if (m1 := mt!: n1)=0 then n2
      else if (m2 := mt!: n2)=0 then n1
      else if (d := (e1 := ep!: n1)-(e2 := ep!: n2))=0
         then make!:ibf(m1+m2, e1)
      else if d>0 then make!:ibf(ashift(m1,d)+m2,e2)
      else make!:ibf(m1+ashift(m2,-d),e1) end;

symbolic procedure difference!:(n1,n2);
   begin scalar m1,m2,e1,e2,d; return
      if (m1 := mt!: n1)=0 then minus!: n2
      else if (m2 := mt!: n2)=0 then n1
      else if (d := (e1 := ep!: n1)-(e2 := ep!: n2))=0
         then make!:ibf(m1 - m2, e1)
      else if d>0 then make!:ibf(ashift(m1,d) - m2,e2)
      else make!:ibf(m1 - ashift(m2,-d),e1) end;

symbolic procedure times!:(n1, n2);
   % This function calculates the product of "n1" and "n2".
   % N1 and N2 are bigfloat representations of "n1" and "n2".
   make!:ibf(mt!: n1 * mt!: n2, ep!: n1 + ep!: n2);

symbolic procedure divide!:(n1,n2,k);
   % This function calculates the quotient of "n1" and "n2", with the
   % precision K, by rounding the ratio of "n1" and "n2" at the (K+1)th
   % place.  N1 and N2 are bigfloat representations of "n1" and "n2".
   % K is any positive integer.
   begin
      n1 := conv!:mt(n1, k + preci!: n2 + 1);
      n1 := make!:ibf(mt!: n1 / mt!: n2, ep!: n1 - ep!: n2);
      return round!:mt(n1, k)
   end;

symbolic procedure max2!:(a,b);
   % This function returns the larger of "n1" and "n2".
   % N1 and N2 are bigfloat representations of "n1" and "n2".
   if greaterp!:(a,b) then a else b;

macro procedure max!: x; expand(cdr x,'max2!:);

symbolic procedure min2!:(a,b);
   % This function returns the smaller of "n1" and "n2".
   % N1 and N2 are binary bigfloat representations of "n1" and "n2".
   if greaterp!:(a,b) then b else a;

macro procedure min!: x; expand(cdr x,'min2!:);

symbolic procedure greaterp!:(a,b);
% this function calculates the a > b, but avoids
% generating large numbers if magnitude difference is large.
     if ep!: a=ep!: b then mt!: a>mt!: b else
       (((if d=0 then ma>mb else
          ((if d>p2 then ma>0 else if d<-p2 then mb<0
            else if d>0 then ashift(ma,d)>mb
            else ma>ashift(mb,-d))
          where p2=2*!:bprec!:))
         where d=ep!: a - ep!: b, ma=mt!: a, mb=mt!: b)
        where a= normbf a, b=normbf b);

symbolic procedure equal!:(a,b);
  %tests bfloats for a=b rapidly without generating digits. %SK
   zerop mt!: a and zerop mt!: b or
   ep!:(a := normbf a)=ep!:(b := normbf b) and mt!: a=mt!: b;

symbolic procedure lessp!:(n1, n2);
   % This function returns T if "n1" < "n2" else returns NIL.
   % N1 and N2 are bigfloat representations of "n1" and "n2".
   greaterp!:(n2, n1);

symbolic procedure leq!:(n1, n2);
   % This function returns T if "n1" <= "n2" else returns NIL.
   % N1 and N2 are bigfloat representations of "n1" and "n2".
   not greaterp!:(n1, n2);

symbolic procedure minusp!: x;
   % This function returns T if "x"<0 else returns NIL.
   % X is any Lisp entity.
   bfp!: x and mt!: x < 0;

symbolic procedure make!:ratnum(nm,dn);
   % This function constructs an internal representation
   %      of a rational number composed of the numerator
   %      NM and the denominator DN.
   % NM and DN are any integers (positive or negative).
   % **** Four routines in this section are temporary.
   % ****      That is, if your system has own routines
   % ****      for rational number arithmetic, you can
   % ****      accommodate our system to yours only by
   % ****      redefining these four routines.
   if zerop dn then rerror(arith,3,"Zero divisor in make:ratnum")
    else if dn > 0 then '!:ratnum!: . (nm . dn)
    else '!:ratnum!: . (-nm . -dn);

symbolic procedure ratnump!:(x);
   % This function returns T if X is a rational number
   % representation, else NIL.
   % X is any Lisp entity.
   eqcar(x,'!:ratnum!:);                   %JBM Change to EQCAR.

symbolic smacro procedure numr!: rnmbr;
   % This function selects the numerator of a rational number "n".
   % RNMBR is a rational number representation of "n".
   cadr rnmbr;

symbolic smacro procedure denm!: rnmbr;
   % This function selects the denominator of a rational number "n".
   % RNMBR is a rational number representation of "n".
   cddr rnmbr;

symbolic procedure conv!:r2bf(rnmbr,k);
   % This function converts a rational number RNMBR to a bigfloat of
   % precision K, i.e., a bigfloat representation with a given
   % precision.  RNMBR is a rational number representation.  K is a
   % positive integer.
   if ratnump!: rnmbr and fixp k and k > 0
     then divide!:(make!:ibf( numr!: rnmbr, 0),
                   make!:ibf( denm!: rnmbr, 0),k)
    else bflerrmsg 'conv!:r2bf;

endmodule;


module bfauxil; % Support for the roots package and ROUNDED domain.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.93, 23 Jun 1993.

% Copyright (c) 1988,1989,1990. Stanley L. Kameny. All Rights Reserved.

Comment   support for modules allroot and isoroot, and for ROUNDED
 domain logic;

exports !!shbinflp, bf2flr, bfdiffer, bfdivide, bfinverse, bflessp,
        bfminus, bfsqrt, cflot, conv!:bf2i, difbf, exptbf, fl2int,
        gf2bf, gf2fl, gfdiffer, gfdot, gfminus, gfplus, gfquotient,
        gfsqrt, gftimes, grpbf, icbrt, ilog2, invbf, irootn, isqrt,
        normbf, plubf, r2bf, r2fl, realrat;

imports abs!:, ashift, bflerrmsg, bfloat, bfminusp, bfnzp, bfp!:,
        bfzerop!:, bfzp, conv!:mt, cut!:ep, decprec!:, difference!:,
        divbf, divide!:, ep!:, eqcar, error1, errorp, errorset!*,
        evenp, fl2bf, gcdn, geq, gfim, gfrl, gfzerop, greaterp!:,
        hypot, i2bf!:, leq, lshift, make!:ibf, minus!:, minusp!:,
        msd!:, mt!:, order!:, plus!:, preci!:, read!:num, rndpwr,
        round!:mt, sgn, sqrt, terrlst, timbf, times!:, typerr;

fluid '(!:prec!: !:bprec!:);

global '(bfone!* bfhalf!* bfz!*);

global '(!!nfpd !!nbfpd !!shbinfl vv!! !!flbint);


global '(!!minflbf !!maxflbf);

symbolic procedure normbf x;
   begin scalar mt,s,r;integer ep,ep1;
      if (mt := mt!: x)=0 then go to ret;
      if mt<0 then <<mt := -mt; s := t>>;
      ep := ep!: x;
      while remainder(mt,1073741824)=0 do << % 2**30
        mt := lshift(mt,-30);
        ep := ep+30 >>;
      while remainder(mt,256)=0 do <<
        mt := lshift(mt,-8);
        ep := ep+8 >>;
      while not oddintp mt do <<
        mt := lshift(mt,-1);
        ep := ep+1>>;
      if s then mt := -mt;
ret:    return make!:ibf(mt,ep) end;

%symbolic procedure divbf(u,v); normbf divide!:(u,v,!:bprec!:);

symbolic procedure bfdivide(u,v);
   if atom u then u/v else divbf(u,v);

%symbolic procedure timbf(u,v); rndpwr times!:(u,v);

symbolic procedure bftimes(u,v); if atom u then u*v else timbf(u,v);

symbolic procedure plubf(a,b);
% this function calculates the normalized rounded sum of a and b,
% but avoids generating large numbers if magnitude difference is large.
  rndpwr
    begin scalar ma,mb,ea,eb,d,ld,p;
      if (ma:=mt!: a)=0 then return b;
      if (mb:=mt!: b)=0 then return a;
      if (d := (ea := ep!: a)-(eb := ep!: b))=0
        then return make!:ibf(ma+mb,ea);
      ld := d+msd!: abs ma - msd!: abs mb;
      p := !:bprec!:+1;
      if ld>p then return a;
      if ld<-p then return b;
      if d>0 then return make!:ibf(ashift(ma,d)+mb,eb)
        else return make!:ibf(ma+ashift(mb,-d),ea) end;

symbolic procedure bfplus(u,v); if atom u then u+v else plubf(u,v);

symbolic procedure difbf(a,b);
% this function calculates the normalized rounded difference of a and b,
% but avoids generating large numbers if magnitude difference is large.
  rndpwr
    begin scalar ma,mb,ea,eb,d,ld,p;
      if (ma:=mt!: a)=0 then return minus!: b;
      if (mb:=mt!: b)=0 then return a;
      if (d := (ea := ep!: a)-(eb := ep!: b))=0
        then return make!:ibf(ma - mb,ea);
      ld := d+msd!: abs ma - msd!: abs mb;
      p := !:bprec!:+1;
      if ld>p then return a;
      if ld<-p then return minus!: b;
      if d>0 then return make!:ibf(ashift(ma,d) - mb,eb)
        else return make!:ibf(ma - ashift(mb,-d),ea) end;

symbolic procedure bfdiffer(u,v); if atom u then u - v else difbf(u,v);

symbolic procedure invbf u; divbf(bfone!*,u);

symbolic procedure bfinverse u; if atom u then 1.0/u else invbf u;

symbolic procedure bfminus u; if atom u then -u else minus!: u;

symbolic procedure bflessp(a,b); if atom a then a<b else grpbf(b,a);

symbolic procedure grpbf(a,b);
  % this function calculates a > b, but avoids generating large numbers
  % if magnitude difference is large.
   <<if ma=0 then mb<0
     else if mb=0 then ma>0
     else if ma>0 and mb<0 then t
     else if ma<0 and mb>0 then nil
     else (if do>0 then ma>0           % the case |a| > |b|
            else if do<0 then ma<0     % the case |a| < |b|
            else if de=0 then ma>mb    % exponents are the same
            else if de>0 then ashift(ma,de)>mb
            else ma>ashift(mb,-de))
          where do=order!: a - order!: b,
                de=ep!: a - ep!: b>>
    where ma=mt!: a,mb=mt!: b;

%symbolic procedure bfminusp u; if atom u then minusp u else minusp!: u;

%symbolic procedure bfzp u; if atom u then zerop u else mt!: u=0;

%symbolic procedure bf!:zerop u; if atom u then zerop u else mt!: u=0;

%symbolic procedure bfnzp u; not bfzp u;

%symbolic procedure bfloat x; if floatp x then fl2bf x else
%normbf(if atom x then if fixp x then i2bf!: x else read!:num x else x);

symbolic procedure !!shbinflp;
   begin integer n; vv!! := 9.0;
     while n<300 and not errorp errorset!*('(vv!!!*1e10),nil)
        do n := n+10;
     return n<300 end;

symbolic procedure vv!!!*1e10; vv!! := vv!!*1.0e10;

symbolic (!!shbinfl := !!shbinflp());

symbolic procedure bfsqrt x;
 % computes sqrt x by Newton's method.
  if minusp!: x then terrlst(x,'bfsqrt) else
  begin  scalar nx,dx,dc,k7,nf;
         if bfzerop!: x then return bfz!*;
         k7 := !:bprec!: + 7;
         dc := make!:ibf (1, (-k7+(order!: x + 10)/2));
         nx := if not oddintp ep!:(nx := conv!:mt(x,2))
            then make!:ibf((2+3*mt!: nx)/5, (ep!: nx/2))
            else make!:ibf((9+5*mt!: nx)/10, ((ep!: nx - 1)/2));
         nf := 1;
   loop: if (nf := 2*nf)>k7 then nf := k7;
         dx := times!:(bfhalf!*,plus!:(divide!:(x,nx,nf),nx));
         if nf>=k7 and not greaterp!:(abs!: difference!:(dx,nx),dc)
            then return rndpwr nx;
         nx := dx; go to loop end;

symbolic procedure realrat x;
   begin scalar d,g;
         if bfp!: x then go to bf;
         if eqcar(x,'quotient) then
            if fixp cadr x and fixp caddr x then
               <<x := if (d := caddr x)<0 then -cadr x else cadr x;
                 d := abs d; go to ret>>
            else x := cadr x/caddr x;
         if zerop x then return (0 . 1);
         if not floatp x then return (x . 1);
         x := bfloat x;
     bf: d := cddr(x := normbf x); x := cadr x;
         if x=0 then return (0 . 1);
         if d< 0 then d := lshift(1,-d)
          else <<x := ashift(x,d); d := 1>>;
    ret: g := gcdn(abs x,d); return (x/g) . (d/g) end;

remflag ('(fl2int),'lose);

symbolic procedure fl2int x;
   <<x := fl2bf x;
     (if d=0 then m else ashift(m,d))
      where m=mt!: x,d=ep!: x>>;

flag ('(fl2int),'lose);

symbolic procedure cflot x;
   if floatp x then x else if atom x then float x else bf2flr x;

symbolic procedure conv!:bf2i nmbr;
% This function converts a <BIG-FLOAT>, i.e., a BINARY BIG-FLOAT
%      representation of "n", to an integer.  The result
%      is the integer part of "n".
% **** For getting the nearest integer to "n", please use
% ****      the combination MT!:( CONV!:EP(NMBR,0)).
% NMBR is a BIG-FLOAT representation of the number "n".
%   if ep!:(nmbr := cut!:ep(nmbr, 0)) = 0 then mt!: nmbr
%    else
     ashift (mt!: nmbr, ep!: nmbr);

symbolic procedure bf2flr u;
   % u is always bigfloat.
   % Converts bfloat to float by rounding at !!nbfpd binary digits.
   % We use error1 rather than rerror, because we want to catch such an
   % error in an errorset.
   begin scalar ep,m,y;
      if bfzerop!: u then return 0.0;
      ep := ep!:(u := round!:mt(u,!!nbfpd));
      if grpbf(!!minflbf,y := abs!: u) or grpbf(y,!!maxflbf)
        then error1();
      if ep<0 then <<ep := ep+!!nbfpd; m := t>>;
      ep := 2.0**ep;
      if ep = 0.0 then error1(); % underflow
      return if not m then ep * mt!: u else ep * mt!: u / !!flbint
   end;

symbolic procedure gf2fl a; % force into float format.
   if atom a then a else if bfp!: a then bf2flr a
      else (gf2fl car a) . gf2fl cdr a;

symbolic procedure gf2bf a; if a then % force into bfloat format.
   if atom a then bfloat a else if bfp!: a then a
      else (gf2bf car a) . gf2bf cdr a;

symbolic procedure r2bf u;
  % translate any real number object to bigfloat.
    if atom u then bfloat u
       else if bfp!: u then u
       else if numberp car u then divbf(i2bf!: car u,i2bf!: cdr u)
       else if eqcar(u,'quotient) then
            divbf(i2bf!: cadr u,i2bf!: caddr u)
       else if eqcar(u,'!:rn!:) then r2bf cdr u
       else r2bf cadr u;

symbolic procedure r2fl u;
 % translate any real number object to float.
   if u=0 then 0.0
      else if atom u then float u
      else if numberp car u then (float car u)/cdr u
      else if eqcar(u,'quotient) then (float cadr u)/caddr u
      else if bfp!: u then bf2flr u
      else if eqcar(u,'!:rn!:) then r2fl cdr u
      else r2fl cadr u;

symbolic procedure gfplus(u,v);
   if atom car u then gffplus(u,v) else gbfplus(u,v);

symbolic procedure gffplus(u,v); (car u+car v) . (cdr u+cdr v);

symbolic procedure gbfplus(u,v);
   (plubf(car u,car v)) . plubf(cdr u,cdr v);

symbolic procedure gfdiffer(u,v);
   if atom car u then gffdiff(u,v) else gbfdiff(u,v);

symbolic procedure gffdiff(u,v); (car u - car v) . (cdr u - cdr v);

symbolic procedure gbfdiff(u,v);
   (difbf(car u,car v)) . difbf(cdr u,cdr v);

symbolic procedure gftimes(u,v);
   if atom car u then gfftimes(u,v) else gbftimes(u,v);

symbolic procedure gfftimes(u,v);
   begin scalar ru,iu,rv,iv;
         ru := car u; iu := cdr u; rv := car v; iv := cdr v;
         return (ru*rv - iu*iv) . (ru*iv+iu*rv) end;

symbolic procedure gbftimes(u,v);
   begin scalar ru,iu,rv,iv;
         ru := car u; iu := cdr u; rv := car v; iv := cdr v;
         return (difbf(timbf(ru,rv),timbf(iu,iv))) .
            plubf(timbf(ru,iv),timbf(iu,rv)) end;

symbolic procedure gfquotient(u,v);
   if atom car u then gffquot(u,v) else gbfquot(u,v);

symbolic procedure gffquot(u,v);
   begin scalar ru,iu,rv,iv,d;
         ru := car u; iu := cdr u; rv := car v; iv := cdr v;
         d := rv*rv+iv*iv;
         return ((ru*rv+iu*iv)/d) . ((iu*rv - ru*iv)/d) end;

symbolic procedure gbfquot(u,v);
   begin scalar ru,iu,rv,iv,d;
         ru := car u; iu := cdr u; rv := car v; iv := cdr v;
         d := plubf(timbf(rv,rv),timbf(iv,iv));
         return divbf(plubf(timbf(ru,rv),timbf(iu,iv)),d) .
            divbf(difbf(timbf(iu,rv),timbf(ru,iv)),d) end;

symbolic procedure gfminus u; (bfminus car u) . (bfminus cdr u);

symbolic procedure gfrotate u; (bfminus cdr u) . (car u);

%symbolic procedure gfrl u; car u;

%symbolic procedure gfim u; cdr u;

%symbolic procedure gfzerop u;
%   if not atom gfrl u then mt!: gfrl u = 0 and mt!: gfim u = 0
%      else equal(u,(0.0 . 0.0));

symbolic procedure gfdot(u,v);
   if atom car u then gffdot(u,v) else gbfdot(u,v);

symbolic procedure gffdot(u,v); car u*car v+cdr u*cdr v;

symbolic procedure gbfdot(u,v);
   plubf(timbf(car u,car v),timbf(cdr u,cdr v));

symbolic procedure gfrsq u; gfdot(u,u);

symbolic procedure gffrsq u; car u*car u+cdr u*cdr u;

symbolic procedure gbfrsq u;
   plubf(timbf(car u,car u),timbf(cdr u,cdr u));

symbolic procedure gffmult(r,u); (r*car u) . (r*cdr u);

symbolic procedure gffsqrt x;
   begin scalar x0,nx,xd,xd0,rl,im; rl := gfrl x; im := gfim x;
     rl := sqrt(hypot(rl,im)/2+rl/2); im := im/(2*rl); nx := rl . im;
     repeat
       <<x0 := nx;
         nx := gffmult(0.5,gffplus(x0,gffquot(x,x0)));
         xd0 := xd; xd := gffrsq gffdiff(x,gfftimes(nx,nx))>>
     until xd0 and xd0 - xd<=0.0; return x0 end;

symbolic procedure gbfmult(r,u);
   <<r := bfloat r; (timbf(r,car u)) . (timbf(r,cdr u))>>;

symbolic procedure gbfsqrt x;
   begin scalar x0,nx,xd,xd0,rl;
     nx :=
      <<rl := (bfsqrt timbf(bfhalf!*,plubf(bfsqrt gfrsq x,gfrl x)));
        rl . timbf(bfhalf!*,divbf(gfim x,rl))>>;
     repeat
       <<x0 := nx;
         nx := gbfmult(bfhalf!*,gbfplus(x0,gbfquot(x,x0)));
         xd0 := xd; xd := gbfrsq gbfdiff(x,gbftimes(nx,nx))>>
     until xd0 and mt!: difbf(xd0,xd)<=0; return x0 end;

symbolic smacro procedure rl2gfc x;
   x . if atom x then 0.0 else bfz!*;

symbolic procedure gfsqrt x;
 % computes gfsqrt x by Newton's method, for both gf and gbf.
   begin scalar xn,neg,negi;
         if gfzerop x then return x;
         if bfminusp gfrl x
           then <<x := gfminus x; neg := t;
                  if bfminusp gfim x then nil else negi := t >>;
         if bfzp gfim x then
            <<x := gfrl x;
              xn := rl2gfc(if atom x then sqrt x else bfsqrt x);
              go to ret>>;
         xn := if atom gfrl x then gffsqrt x else gbfsqrt x;
         if negi then xn := gfminus xn;
    ret: return if neg then gfrotate xn else xn end;

symbolic procedure sgn x; if x>0 then 1 else if x<0 then -1 else 0;

symbolic procedure exptbf(x,n,a);
  % Computes a*x**n in bfloat arithmetic for positive x
  % and positive integer n.
   begin
  lp: if oddintp n then a := timbf(a,x); % not evenp n
      n := lshift (n, -1);
      if n=0 then return a;
      x := timbf(x,x); go to lp end;

symbolic procedure icbrt x;
   % computes icbrt by Newton's method, avoiding magnitude problems.
   if abs(x := fix x) < 2 then x else
   begin scalar s,r,g,trv,nx;
         if x<0 then x := -x else s := t;
         if x<100 then <<nx := 1; go to loop>>;
         r := remainder(ep!:(nx := conv!:mt(make!:ibf(x, 0),3)),3);
         nx := if r=0 then lshift((12 + mt!: nx )/10, nx/3)
            else if r=1 or r= -2
           then lshift((17+4*mt!: nx)/16,(ep!: nx - 1)/3)
            else lshift((15+4*mt!: nx)/12,(ep!: nx - 2)/3);
   loop: trv := nx; nx := 2*trv+x/(trv*trv); nx := nx/3;
         if g and nx>=trv then go to ret;
         g := t; go to loop;
    ret: return if s then trv else -trv end;

symbolic procedure isqrt x;
 % computes isqrt x by Newton's method, avoiding magnitude problems.
   if x<0 then terrlst(x,'isqrt)
   else if (x := fix x)=0 or x=1 then x else
   begin  scalar trv,nx,g;
      if x<144 then <<nx := 1; go to loop>>;
      nx := if not oddintp ep!:(nx := conv!:mt(make!:ibf(x, 0),2))
         then lshift((2+3*mt!: nx)/5,ep!: nx/2)
         else lshift((9+5*mt!: nx)/10,(ep!: nx - 1)/2);
 loop: trv := nx; nx := (trv + x/trv)/2;
       if g and nx>=trv then return trv;
       g := t; go to loop end;

%symbolic procedure ilog2 x; % logb(10,2) is ~ 485/146.
%   if x<=0 then terrlst(x,'ilog2) else if (x := fix x)<3 then x - 1
%    else (<<y := lshift(1,p := p/146);
%      while x>=y do <<y := y*2; p := p+1>>; p - 1>>
%    where p=(length explode x - 1)*485,y=1);

symbolic procedure ilog2 x;
   if x<=0 then terrlst(x,'ilog2) else msd!: x - 1;

symbolic procedure irootn!-round(m,n);
   % M,n integral, n>0, answer is nearest integer to m/n.
   (m+n/2)/n;

symbolic procedure irootn!-roundup(m,n);
   % M,n integral, n>0, answer is least integer >= m/n.
   (if cdr quotrem<=0 then car quotrem else 1+car quotrem)
   where quotrem = divide(m,n);

symbolic procedure irootn(n,r);
   % n,r integral; result 's' approximates rth root of n.  That is,
   % if n>0 then s**r <= n < (s+1)**r else s**r >= n > (s - 1)**r.
   % 3363/2378 is an approximation to sqrt 2.
   % This definition uses isqrt or icbrt where applicable.
   if not fixp n then typerr(n,"integer")
    else if not fixp r or r<=0 then typerr(r,"positive integer")
    else if n<0
     then if evenp r then typerr(r,"odd integer") else -irootn(-n,r)
   % Modified here to use isqrt or icbrt for speed.
   else if r=1 then n else if r=2 then isqrt n else if r=3 then icbrt n
   else begin scalar x,newx,upb;
      x:=2**(irootn!-round(1+ilog2 n,r));
      newx:=x - irootn!-roundup(x - n/x**(r - 1),r);
      upb:=(3363*x)/2378;
      if upb<newx then newx:=upb;
      repeat <<x:=newx; newx:=x - irootn!-roundup(x - n/x**(r - 1),r)>>
         until newx>=x or newx=0;
      return x
   end;

put('irootn,'number!-of!-args,2);   %  For VALUECHK.

endmodule;


module paraset;   % Parameter determining module.

% Author: Stanley L. Kameny.

% Last change date: 23 June 1993.

% Paraset.red determines the parameters !!nfpd, !!nbfpd, and !!maxbflexp
% for floating point numbers.  !!nfpd, !!nbfpd, and !!maxbflexp are
% computed at load, but !!maxbflexp may have to be fixed up at run time
% if !!flexperr is true.

imports errorp, errorset!*, neq, roundconstants;

exports !!mfefix, find!!nbfpd, find!!nfpd, infinityp;

global '(!!nfpd !!nbfpd !!!~xx !!yy !!maxbflexp !!flexperr !!plumax
         !!epsqrt !!flint !!flbint);

flag('(!!nfpd !!nbfpd !!maxflexp),'share);

symbolic procedure find!!nfpd;
   begin scalar x,y,z;integer i; x:=y:=9.0;
      repeat <<x := 10.0*x+y; i := i+1>> until (z := x+1.0)=x;
      if 10.0*fix(z/10) - 1.0 neq x then i := i - 1;
      return !!nfpd:=i end;

symbolic procedure find!!nbfpd;
   begin scalar x,y,z;integer i; x:=y:=1.0;
      repeat <<x := 2.0*x+y; i := i+1>> until (z := x+1.0)=x;
      if 2.0*fix(z/2) - 1.0 neq x then i := i-1;
      return !!nbfpd:=i end;

symbolic procedure find!!maxbflexp;
   begin scalar z; integer n;
      !!!~xx := 1.0;
      while not errorp
       (z := errorset!*(
          '(progn (setq !!yy (plus 1.0 (times !!!~xx 2.0)))
                  (and (not (infinityp !!yy))
                       (greaterp !!yy !!!~xx))),nil))
         and car z do
            <<n := n+1; !!!~xx := !!yy>>;
      !!flexperr := not errorp z and not car z;
      return !!maxbflexp := n end;

symbolic procedure infinityp u;
   % Check for a representation of an IEEE floating point infinity.
   not(x eq '!- or digit x) where x=car explode u;

symbolic procedure !!mfefix;
  <<if !!flexperr then
      begin integer n;
        !!flexperr := !!plumax := nil;
        while errorp errorset!*('(explode !!!~xx),nil) do
          <<!!!~xx := !!!~xx/2.0; n := n+1>>;
        !!maxbflexp := !!maxbflexp - n;
      end;
    if not !!plumax then roundconstants()>>;

find!!nfpd(); find!!nbfpd();
find!!maxbflexp();

!!epsqrt := 10.0**((-1 - !!nfpd)/2);

!!flint := 10.0**!!nfpd;

!!flbint := 2.0 ** !!nbfpd;

endmodule;


module math;  % Mathematical Package for REDUCE.

% Author: Stanley L. Kameny <valley!stan@rand.org>,
% and Arthur C. Norman.

% Version and Date:  Mod 1.63, 23 June 1993.

% Copyright (c) 1987, 1988, 1989, 1990, 1991, 1993 Stanley L. Kameny.
% All Rights Reserved.

%*******************************************************************
%**                                                               **
%**  This math package will compute the floating point values of  **
%**  the usual elementary functions, namely:                      **
%**     sin     asin     sind    asind     sinh    asinh          **
%**     cos     acos     cosd    acosd     cosh    acosh          **
%**     tan     atan     tand    atand     tanh    atanh          **
%**     cot     acot     cotd    acotd     coth    acoth          **
%**     sec     asec     secd    asecd     sech    asech          **
%**     csc     acsc     cscd    acscd     csch    acsch          **
%**             atan2            atan2d                           **
%**     exp     ln       sqrt    factorial                        **
%**     expt    log      cbrt                                     **
%**     logb    hypot                                             **
%**     log10   floor                                             **
%**             ceiling                                           **
%**             round                                             **
%**                                                               **
%**  All functions are computed to the accuracy of the floating-  **
%**  point precision of the system set up at the time.            **
%**                                                               **
%*******************************************************************

% Revisions:

%     1 May 93  expt improved; fix2 eliminated (not needed).
%    15 Sep 92  expt, hypot, log improved. factorial added.
%    25 May 91  atan2d added.  Function list updated.
%     6 Feb 90  exp, expt, and hyperbolic functions improved.
%     6 Nov 90  find!!nfpd improved; fl2int eliminated (now in bfauxil.)
%    31 Mar 90  fl2int speeded up for very large argument.
%    25 Feb 90  expt modified.
%    15 Oct 89  atan2 and sind,asind family added.
%     8 Oct 89  !!scalsintan,sqrt,expt,and hyperbolics modified.
%     8 Oct 89  hypot,floor,ceiling,round added
%    26 Aug 89  zerop test used in expt
%    20 Jul 89  !!scalsintan revised: same limits for deg and rad
%    17 May 89  find!!nfpd revised (for binary or decimal floats)
%    18 Apr 89  global log10 -> logten (to avoid name conflict)
%    18 Apr 89  !!scalsintan revised (per: Rainer Schoepf)
%    27 Nov 88  log,expt,sqrt revised for speed
%     5 Jun 88  log -> log10; ln -> log; exptfp -> expt (revised)
%    11 Nov 87  hyperbolic fns rewritten: speeded up; improved
%     6 Nov 87  ln,atan rewritten: speeded up. sq!-1  eliminated
%    30 Oct 87  sin,(cos),tan,(cot),exp  rewritten; speeded up

%*******************************************************************
%**                       Basic functions                         **
%*******************************************************************

exports acos, acosd, acosh, acot, acotd, acoth, acsc, acscd, acsch,
        asec, asecd, asech, asin, asind, asinh, atan, atan2, atan2d,
        atand, atanh, cbrt, ceiling, cos, cosd, cosh, cot, cotd, coth,
        csc, cscd, csch, exp, factorial, floor, hypot, log, log10,
        logb, sec, secd, sech, sin, sind, sinh, sqrt, tan, tand, tanh,
        terrlst;

imports !!shbinflp, fl2int, geq, leq, neq, rerror, sgn;

global '(math!!label);
math!!label := "Math package mod 1.7, 1 May 93";

symbolic procedure terrlst (x,y); error(0,list(x," invalid for ",y));

global '(!!nfpd !!flint !!epsqrt !!flprec);

if not !!nfpd then flag('(!!nfpd),'share);

symbolic procedure sqrt x;
 % Computes sqrt x by Newton's method, avoiding magnitude problems.
   if x<0 then terrlst(x,'sqrt) else
   begin  scalar trv,nx,g,l,o,c1,c2,f1; f1 := nx := o := 1.0;
          if (x := float x)=0.0 or x=o then return x;
          if x<o then <<x := o/x; l := t>>;
          c1 := 8192.0; c2 := c1*c1;
          while x>c2 do <<x := x/c2; f1 := f1*c1>>;
    loop: trv := nx; nx := (trv + x/trv)/2;
          if g and nx>=trv then go to ret;
          g := t; go to loop;
     ret: nx := nx*f1; return if l then o/nx else nx end;

symbolic procedure cbrt x;
   begin scalar s,l,o,g,trv,nx,c1,c2,f1; f1 := nx := o := 1.0;
         if (x := float x)=0.0 or abs x=o then return x
         else if x<0 then x := -x else s := t;
         if x<o then <<x := o/x; l := t>> else if x=o then go to ret;
         c1 := 1024.0; c2 := c1*c1*c1;
         while x>c2 do <<x := x/c2; f1 := f1*c1>>;
   loop: trv := nx; nx := trv/1.5+x/(trv*trv*3);
         if g and nx>=trv then go to ret;
         g := t; go to loop;
    ret: nx := nx*f1; if l then nx := o/nx;
         return if s then nx else -nx end;

symbolic procedure hypot(p,q);
   % Hypot(p,q)=sqrt(p*p+q*q) but avoids intermediate overflow.
   begin scalar r;
         if (p := float p)<0 then p := -p;
         if (q := float q)<0 then q := -q;
         if zerop p then return q
         else if zerop q then return p
         else if p<q then <<r := p; p := q; q := r>>;
         if p+q=p then return p else r := q/p;
         return if r<!!epsqrt then p else p*sqrt(1+r*r) end;

symbolic procedure floor x;
   % Returns the largest integer less than or equal to x
   % (i.e. the "greatest integer" function.)
   % Note the trickiness to compensate for fact that (unlike APL's
   % "FLOOR" function) FIX truncates towards zero.
   % A definition of fix(x+sgn(x)*0.5) has also been suggested.
   if fixp x then x
    else (if x = float n then n else if x >= 0 then n else n - 1)
       where n = fix x;

symbolic procedure ceiling x;
   % Returns the smallest integer greater than or equal to X.
   % Note the trickiness to compensate for fact that (unlike APL's
   % "FLOOR" function) FIX truncates towards zero.
   if fixp x then x
    else (if x = float n then n else if x >= 0 then n+1 else n)
       where n = fix x;

symbolic procedure round x;
   % Rounds to the closest integer.
   % Kind of sloppy -- it's biased when the digit causing rounding is a
   % five.  (Changed to work properly for X<0.  SLK)
   if fixp x then x else if x<0 then -round(-x) else floor(x+0.5);

symbolic procedure rounddec (x,p);
   % Rounds x to p decimal places, unless x must already be an integer.
   if abs x>=!!flint then x
    else  begin scalar xl,xr,sc;
            sc := 10.0**p; xl := fix(x := x*sc); xr := x - xl;
            if x>0 and xr>=0.5 then xl := xl+1;
            if x<0 and xr<-0.5 then xl := xl - 1;
            return xl/sc
          end;

global '(log2 sq2 sq2!-1 logsq2 logten log1000 log1e9);
global '(log1e81 log1e27);

sq2 := sqrt 2.0; sq2!-1 := 1/(1+sq2);

symbolic procedure log x;
   begin scalar s,lx; integer p;
      if (x := float x)<=0.0 then terrlst(x,'log)
         else if x - 1<0 then x := 1/x else s := t;
      lx := 0.0;
      while x>1.0e81 do <<x := x/1.0e81; lx := lx+log1e81>>;
      while x>1.0e27 do <<x := x/1.0e27; lx := lx+log1e27>>;
      while x>1.0e9 do <<x := x/1.0e9; lx := lx+log1e9>>;
      while x>1000 do <<x := x/1000; lx := lx+log1000>>;
      while x>10 do <<x := x/10; lx := lx+logten>>;
      while x>2 do <<x := x/2; lx := lx+log2>>;
      if x>sq2 then <<x := x/sq2; lx := lx+logsq2>>;
      lx := lx+sclogx!-1(x - 1);
      return if s then lx else -lx end;

symbolic procedure sclogx!-1 x;
   begin scalar tx,px,lx,st,sl; integer p;
         tx := px := x; p := 1; lx := 0.0;
         st := x*(1 - x/2);
         while st+abs tx>st do
            <<sl := tx . sl; tx := (px:=-px*x)/(p := p+1)>>;
         for each i in sl do lx := lx+i;
         return lx end;

log2 := 2*(logsq2 := sclogx!-1 sq2!-1);
log1e81 := 3*(log1e27 := 3*(log1e9 := 3*(log1000 :=
  3*(logten := log 10.0))));

global '(!!pilist);

global(!!pilist := '(!!pii !!pii2 !!pii3 !!pii4 !!pii6 !!twopi
                     !!rad2deg !!deg2rad));

remflag(!!pilist,'reserved);

symbolic procedure atan x;
   begin scalar arg,term,termp,trv,s,g,y;
      integer p;
      if (x := float x)< 0 then x := -x
       else s := t;
      if x > 1 then x:=1/x else g:=t;
      if x < !!epsqrt then go to quad;
      term := if x<0.43 then (arg := x)
         else (arg := x/(1+sqrt(1+x*x)))*2;
      arg := arg*arg; p := 1; trv := (termp := term)*(1 - arg/3);
      while trv+abs termp >trv do
        <<y := termp . y; termp := (term := -term*arg)/(p := p+2)>>;
      x := 0;
      for each i in y do x := x+i;
quad: if not g then x := !!pii2 - x;
      if not s then x := -x;
      return x end;

symbolic procedure atand x; !!rad2deg * atan x;

!!twopi := 2*(!!pii := 2*(!!pii2 := 2*(!!pii4:=atan 1.0)));
!!pii3 := 2*(!!pii6 := !!pii2/3);
!!deg2rad:=!!pii4/45; !!rad2deg:=45/!!pii4;

flag(!!pilist,'reserved);

fluid '(!*ddf!* !*df!* !*sf!* !*qf!*);

symbolic procedure sin x;
  begin scalar !*sf!*,!*qf!*;integer p;
   % test for 90 deg -> 1.0
      x := !!scalsintan(x,t);
      if !*qf!* then <<x := 1.0; go to ret>>;
   % for x>45, compute cos of complement, else compute sin.
      if x>!!pii4 then x := !!pii2 - x else p := 1;
      x := !!sints(x,p);
   ret: return if !*sf!* then x else -x end;

symbolic procedure sind x;
  begin scalar !*sf!*,!*qf!*;integer p;
   % test for 90 deg -> 1.0
      x := !!scalsintand(x,t);
      if !*qf!* then <<x := 1.0; go to ret>>;
   % for x>45, compute cos of complement, else compute sin.
      if x>45.0 then x := 90.0 - x else p := 1;
      x := !!sints(x*!!deg2rad,p);
   ret: return if !*sf!* then x else -x end;

symbolic procedure tan x;
   begin scalar y,inv,!*sf!*,!*qf!*;
      y:=x; x:= !!scalsintan(x,nil);
      if !*qf!* then terrlst(y,'tan);
      if x>!!pii4 then x := !!pii2 - x else inv := t;
 % For scaled x>45, compute cot else compute tan.
      if x>!!epsqrt then <<x := !!sints(x,1); x := x/sqrt(1 - x*x)>>;
      if not inv then x := 1/x;
      return if !*sf!* then -x else x end;

symbolic procedure tand x;
   begin scalar y,inv,!*sf!*,!*qf!*;
      y:=x; x:= !!scalsintand(x,nil);
      if !*qf!* then terrlst(y,'tand);
      if x>45.0 then x := 90.0 - x else inv := t;
 % For scaled x>45, compute cot else compute tan.
      x := x*!!deg2rad;
      if x>!!epsqrt then <<x := !!sints(x,1); x := x/sqrt(1 - x*x)>>;
      if not inv then x := 1.0/x;
      return if !*sf!* then -x else x end;

global '(max!-trig!-fact); max!-trig!-fact := 10**(!!nfpd/2);

fluid '(!:prec!:);

symbolic procedure !!scalsintan(x,w);
% x is scaled to 0<=x<=90 deg, with !*sf!* = {sin>0 or tan<0}.
% w true for sin, false for tan.
%modified to avoid infinite loop for large x, after Rainer Schoepf's
%suggestion, adjusted so degree and radian input agrees- SLK.
   begin scalar xf,x0;
      if x<0 then x := -x else !*sf!* := t; x0 := x;
      if (xf := fix(x/!!twopi))>max!-trig!-fact then
         terrlst(if !*sf!* then x else -x,if w then 'sin else 'tan);
      x := x - float xf * !!twopi;
      if x>!!pii then (if w then
           <<x := !!twopi - x; !*sf!* := not !*sf!*>>
       else x := x - !!pii);
      if x>!!pii2 then x:=!!pii - x
       else if not w then !*sf!*:=not !*sf!*;
      !*qf!* := x>=!!pii2;
 % the remaining tests and scaling are done separately by sin and tan
      if x<x0/10.0**(!:prec!: - 3) then x := 0.0;
      return x end;

symbolic procedure !!scalsintand(x,w);
% x is scaled to 0<=x<=90 deg, with !*sf!* = {sin>0 or tan<0}.
% w true for sin, false for tan.
%modified to avoid infinite loop for large x, after Rainer Schoepf's
%suggestion, adjusted so degree and radian input agrees- SLK.
   begin scalar xf,x0;
      if x<0 then x := -x else !*sf!* := t; x0 := x;
      if (xf := fix(x/360.0))>max!-trig!-fact then
         terrlst(if !*sf!* then x else -x,if w then 'sin else 'tan);
      x := x - float xf * 360.0;
      if x>180.0 then (if w then
           <<x := 360.0 - x; !*sf!* := not !*sf!*>> else x:= x - 180.0);
      if x>90.0 then x:=180.0 - x else if not w then !*sf!*:=not !*sf!*;
      !*qf!* := x>=90.0;
 % the remaining tests and scaling are done separately by sin and tan
      if x<x0/10.0**(!:prec!: - 3) then x := 0.0;
      return x end;

symbolic procedure !!sints (x,p);
 % Does the actual computation of the sin or cos series.
   begin scalar sl,sq,st,term;
        x := float x;
        if x<!!epsqrt then return if p=1 then x else 1.0;
        sq := x*x;
        st := if p=1 then (term:=x)*(1 - sq/6)
               else (term:=1.0)*(1 - sq/2);
        while st + abs term > st do
           <<sl:=term . sl;
             p:=p+2.0;
             term:=-term*sq/((p - 1.0)*p) >>;
        x:=0.0;
        for each i in sl do x:=x+i;
        return x end;

symbolic procedure !!sinhts x;
 % Does the actual computation of the sinh for 0<x<0.91.
   begin scalar p,sl,sq,st,term;
        if x<2*!!epsqrt then return x;
        st:= (term := x)*(1 - (sq := x*x)/6); p := 1;
        while st + term > st do
           <<sl:=term . sl;
             p:=p+2.0;
             term:=term*sq/((p - 1.0)*p) >>;
        x := 0.0;
        for each i in sl do x := x+i;
        return x end;

global '(!!ee);

symbolic procedure exp v;
   begin scalar d,nr,mr,fr,st;integer p,ip;
         mr := fr := 1.0; v := float v;
         if abs v>1 then <<ip := fix v; v := v - ip; fr := !!ee**ip>>;
         if abs v>0.5 then v := v/2 else d := t;
         if v=0.0 then go to ret;
         st := mr+v;
         while st+abs mr > st do
               <<nr := mr . nr; mr := mr*v/(p := p+1)>>;
         mr := 0.0;
         for each i in nr do mr := mr+i;
    ret: if not d then mr := mr*mr;
         return fr*mr end;

remflag('(!!ee),'reserved); !!ee := exp 1.0; flag('(!!ee),'reserved);

put('expt,'number!-of!-args,2);

% NOTE that any Lisp system with a very good implementation of EXPT is
% entitled to replace the following definition of EXPT with it, but they
% should also arrange that fexpt gets redirected to the same good
% built-in function.

symbolic procedure iexpt(x,n);
   % Calculate x**n where n is a strictly positive integer.  This uses
   % repeated squaring.  It is appropriate for use when x is an integer,
   % and can be used for floating x provided that n is not too large.
    if not (n > 0) then error(0, "iexpt argument <= 0")
    else if n=1 or x=1  then x
    else if fixp x and remainder(x,2)=0 then lshift(iexpt(x/2,n),n)
    else if remainder(n,2)=0 then (y*y) where y=iexpt(x,n/2)
    else (x*y*y) where y=iexpt(x,(n - 1)/2) ;

symbolic procedure expt(x,y);
   % Computes x**y.  Valid for any x provided that y is an integer,
   % but only for positive x if y is floating.
   begin integer iy,p; scalar sy,fy,r;
      % Some of the initial tests here are subsumed by those in rexpt,
      % and could be removed - but I prefer to implement a proper
      % general version of expt, even though doing so adds (slightly)
      % to the cost of using this portable version.  Note that getting
      % accurate answers from expt in a portable way is a real pain,
      % and I will not do a 100% good job here... see Cody and Waite
      % for a discussion of the issues involved.
      if zerop y then
         if zerop x then error(0,"0**0 undefined")
          else return if floatp x or floatp y then 1.0 else 1
       else if zerop x then
         if y>0 then return if floatp x or floatp y then 0.0 else 0
          else error(0,"divide by zero in EXPT")
       else if fixp y then
         return if fixp x then
                  if y < 0 then 0 else if x = 1 then 1 else iexpt(x,y)
      % See comments with the function FEXPT for an explanation of the
      % tests here - I deem exponents of less than 50 to be small
      % enough to handle the simple (and cheap) way.
                   else if y > 50 then fexpt(x, y)
                   else if y > 0 then iexpt(x, y)
                   else if y < -50 then 1.0/fexpt(x,-y)
                 else 1.0/iexpt(x,-y);
      % Since y is floating, float x if fixed.
      if fixp x then x := float x;
      if x<0.0 then
        error(0,"attempt to raise negative value to floating power");
      % Record the sign of y, but do not invert x yet, since it is
      % important not to corrupt the value of x by even one unit in the
      % last place.  Note that this will leave me with a risk that
      % (e.g.) 10.0**(-1000.0) will try to compute 10.0**1000.0 (which
      % will overflow) and only then take its reciprocal, while
      % possible had I inverted x here I would have had a silent
      % arithmetic underflow.  For now I will argue that arithmetic
      % underflow is really an error too and that the exception
      % deserved to be raised.
      if y < 0.0 then <<sy := t; y := -y>>;
      % Still use multiplication if y has integral value.
      iy := fix y;
      fy := float iy;
      if y = fy then <<
         if iy > 50 then x := fexpt(x, iy)
          else x := iexpt(x, iy);
         if sy then return 1.0/x
          else return x>>;
      % For x fairly close to 1.0 and smallish values of y I can use
      % the simple formula with exp and log, and I will not lose
      % overmuch accuracy.  The limits I apply here are a compromise
      % between wanting to use this cheap recipe as often as possible
      % and the desire to get best possible accuracy.
      if 0.1 < x and x < 10.0 and y < 5.0
        then <<if sy then y := -y; return exp(y*log x)>>;
      % Now scale x as 2^p * something
      p := 0;
      while x < 0.005524 do <<x := x*256.0; p := p - 8>>;
      while x < 0.707106781 do <<x := x*2.0; p := p - 1>>;
      while x >= 181.02 do <<x := x/256.0; p := p+8>>;
      while x >= 1.414213562 do <<x := x/2.0; p := p+1>>;
      % Now x is in the range 0.707 <= x < 1.414, so log x is fairly
      % small.  I can compute x**iy my multiplication, x**(y - iy) by
      % logs, and that just leaves 2**(y*p) to worry about.
      if (y - fy) > 0.5 then <<fy := fy+1.0; iy := iy+1>>;
      r := exp((y - fy)*log x);
      if iy > 50 then r := r*fexpt(x, iy)
       else if iy > 0 then r := r*iexpt(x, iy);
      y := p*y;
      iy := fix y;
      fy := y - float iy; % fractional part of y.
      % Now I need to compute 2**iy * 2**fy.
      r := r * exp(fy*log2);
      % I can afford to use iexpt() here since powers of 2.0 have exact
      % representations as floats (with binary machines!) so there
      % should be no rounding errors in what follows.
      if iy > 0 then r := r*iexpt(2.0, iy)
       else if iy < 0 then r := r*iexpt(0.5, -iy);
      if sy then r := 1.0/r;
      return r
   end;

Comment
   Consider the calculation z = 1.01 ** 16384.  I have chosen the
   exponent to be a power of 2 for simplicity of explanation, but other
   values will suffer the same way.  The value of z will be computed as
   (1.01*1.01) raised to the power 8192.  The multiplication 1.01*1.01
   will introduce an error of about e = 1/2 unit in the last place
   (around 1.0e-16 perhaps).  If all calculations after that very first
   multiplication are then performed exactly, the final result (6.3e70
   or so) will have a relative error of around 8000 units in the last
   place.  To avoid this sort of trouble it is necessary to use extra
   precision in the multiplications - something that slows us down but
   which is needed.  I only use this expensive code if I am going to
   raise a float to a power greater than 50 (a rather arbitrary
   cut-off) so that speed of calculation involving small powers is not
   hurt too badly;

symbolic procedure fsplit x;
   % This decomposes a floating point value x into two parts x1 and x2
   % such that x = x1+x2 and x1 is a number with at most 12 significant
   % bits in its mantissa.  I choose to keep 12 bits here since I then
   % expect (i.e., REQUIRE) that products of pairs of such numbers get
   % formed without any rounding at all.  This should be so even on
   % IEEE single precision arithmetic (25 bits of mantissa).  For IBM
   % mainframe single precision even more effort would be needed.
   begin scalar xx, n;
      if x = 0.0 then return (0.0 . 0.0);
      xx := x; n := 1.0;
      if x < 0.0 then xx := -xx;
      while xx < 8.0 do << xx := xx*256.0; n := n*256.0>>;
      while xx < 2048.0 do << xx := xx*2.0; n := n*2.0>>;
      while xx >= 4096.0 do << xx := xx*0.5; n := n*0.5>>;
      xx := float fix xx/n;
      if x < 0.0 then xx := -xx;
      return (xx . (x - xx))
   end;

symbolic procedure f_multiply(a, b);
   % a and b are split-up floating point values as generated by fsplit.
   % Multiply them together and return the result as an fsplit-num.
   begin scalar h, l;
      h := fsplit(car a*car b);
      l := cdr h + car a*cdr b + (car b + cdr b)*cdr a;
      return (car h . l)
   end;

symbolic procedure fexpt(x, n);
   % Like iexpt, this raises x to the (positive integer) power n.  But
   % it uses fplit-num arithmetic to get about 12 bits of extra
   % precision in the calculation, which should preserve reasonable
   % accuracy until n gets to be much bigger than 5000.
   begin scalar w;
      w := fexpt1(fsplit x, n);
      return car w + cdr w
   end;

symbolic procedure fexpt1(x, n);
   % Calculate x**n where n is a strictly positive integer, using extra
   % precision arithmetic.
   if not (n > 0) then error(0, "fexpt1 argument <= 0")
    else if n = 1 then x
    else if remainder(n, 2) = 0 then fexpt1(f_multiply(x, x), n/2)
    else f_multiply(x, fexpt1(f_multiply(x, x), (n - 1)/2));

symbolic procedure rexpt(x,y);
   % Computes x**y in for argument sets that yield real values.  In
   % particular if x is negative but y is a floating point value that
   % is sufficiently close to a rational number then a real result will
   % be computed, where the system-level expt function might have
   % reported an error.  This also picks up various marginal or error
   % cases (e.g. 0**0) so that their treatment is precisely defined in
   % REDUCE.
   begin scalar s,q; integer p;
      if zerop y then
         if zerop x then error(0,"0**0 undefined")
         else return if floatp x or floatp y then 1.0 else 1
      else if zerop x then
         if y>0 then return if floatp x or floatp y then 0.0 else 0
         else error(0,"divide by zero in EXPT")
      else if fixp y then <<
         if fixp x then <<
            if y<0 then return 0
            else if x = 1 then return 1
            else return iexpt(x, y) >>;
      % Floating numbers raised to integer powers are still pretty
      % painful.  If the base is negative then the sign of the result
      % depends on whether the power was odd or even.  For large
      % exponents I use fexpt() for extra accuracy (but at significant
      % extra cost).
         s := 0;
         if y < 0 then <<s:=1; y := -y>>;
         if x < 0 then <<s:=s+2; x := -x>>;
         if y > 50 then x := fexpt(x, y) else x := iexpt(x, y);
         if s=1 or s=3 then x := 1.0/x;
         if s>1 and remainder(y,2) neq 0 then x := -x;
         return x>>;
      % Since y is floating, float x if fixed.
      if fixp x then x := float x;
      % Invert here if exponent is negative float.
      if y<0.0 then <<x := 1.0/x; y := -y>>;
      % Still use integer exponentiation if y has integral value.
      if zerop(y - (p := fix y)) then return iexpt(x, p);
      % If x < 0 then x**y only yields a real result if y is a rational
      % number.  We already know that y is not an integer, so call
      % ft2rn1 to see if a good rational approximation to y exists.  A
      % previous version of this code called ft2rn1 for all floating
      % point values of y and then used combination sof sqrt/cbrt to
      % evaluate x**y in some cases.  This version bets that the cost
      % of ft2rn1 would exceed the savings of using sqrt, and so only
      % does the expensive thing when x < 0 and thus when there might
      % otherwise have been an error.
      if x<0.0 then <<
         q := ft2rn1 y; p := car q; q := cdr q;
         x := -x;
         if not(abs p<10 or q<10
             or 2*max(length explode q,length explode p) < !!flprec+1)
             or remainder(q,2)=0
               then error (0,list (-x,"**",y," not real"))
           else if remainder(p,2)=1 then s := t >>;
      x := expt(x, y);     % Use the lower level expt function
      return (if s then -x else x)
 end;

symbolic procedure ft2rn1 n;
  if n < 0.0 then ((-car r) . cdr r) where r = ft2rn2(-n)
   else ft2rn2 n;

symbolic procedure ft2rn2 n;
  % Here, the positive input n is a float.
   begin scalar a,p0,p1,q0,q1,w,nn,r0,r1,flpr;
      flpr := abs n*100.0/!!flint;
      a := fix n;
      nn := n - a;
      p0 := 1; p1 := a; q0 := 0; q1 := 1;
      r0 := n + 1.0;
 top: r1 := abs(n - float p1/float q1);
      if nn=0.0 or r1=0.0 or not (r1 > flpr) then return p1 . q1
       else if not (r1 < r0) then return p0 . q0;
      nn := 1.0/nn;
      a := fix nn;
      nn := nn - a;
      w := p0 + a*p1; p0 := p1; p1 := w;
      w := q0 + a*q1; q0 := q1; q1 := w;
      r0 := r1;
      go to top
  end;


%**********************************************************************
%**             Functions derived from basic functions               **
%**********************************************************************

symbolic procedure cos x; sin(!!pii2 - x);

symbolic procedure cot x; tan(!!pii2 - x);

symbolic procedure sec x; 1.0/cos x;

symbolic procedure csc x; 1.0/sin x;

symbolic procedure acot x; !!pii2 - atan x;

symbolic procedure asin x;
   if abs x<1 then
      atan(if abs x<!!epsqrt then x else x/sqrt(1 - x*x))
   else if abs x>1 then terrlst (x,'asin)
   else if x>0 then !!pii2 else -!!pii2;

symbolic procedure acos x; !!pii2 - asin x;

symbolic procedure acsc x;
   if abs x>=1 then asin(1.0/x) else terrlst(x,'acsc);

symbolic procedure asec x;
   if abs x<1 then terrlst(x,'asec) else !!pii2 - asin(1.0/x);

symbolic procedure cosd x; sind(90.0 - x);

symbolic procedure cotd x; tand(90.0 - x);

symbolic procedure secd x; 1/cosd x;

symbolic procedure cscd x; 1/sind x;

symbolic procedure acotd x; 90.0 - atand x;

symbolic procedure asind x; !!rad2deg * asin x;

symbolic procedure acosd x; 90.0 - asind x;

symbolic procedure acscd x;
   if abs x>=1 then asind(1.0/x) else terrlst(x,'acscd);

symbolic procedure asecd x;
   if abs x<1 then terrlst(x,'asecd) else 90.0 - asind(1.0/x);

symbolic procedure sinh x;
   begin scalar s;
      if x<0.0 then x:=-x else s:=t;
      if (x := float x)<0.91 then <<x := !!sinhts x; go to ret>>;
      x := exp(-x); x := (1.0/x - x)/2;
 ret: return if s then x else -x end;

symbolic procedure cosh x; <<x := exp(-abs x),(x+1.0/x)/2>>;

symbolic procedure tanh x;
   if x<0.0 then -tanh(-x) else
      <<x := exp(-2.0*x); (1.0 - x)/(1.0+x)>>;

symbolic procedure coth x;
   if x<0.0 then -coth(-x) else
      <<x := exp(-2.0*x); (1.0+x)/(1.0 - x)>>;

symbolic procedure asinh x; begin scalar s;
   if x<0 then x:=-x else s:=t;
   x:=if x<!!epsqrt then x else log (x+if x<2 then sqrt(x*x+1)
           else if 1/x<!!epsqrt then x else x*sqrt(1+1/(x*x)));
   return if s then x else -x end;

symbolic procedure acosh x; if x<1 then terrlst(x,'acosh)
   else log (x+if 1/x<!!epsqrt then x else x*sqrt(1 - 1/(x*x)));

symbolic procedure atanh x; if abs x>=1 then terrlst(x,'atanh)
   else if abs x<!!epsqrt then x else 0.5*log((1+x)/(1 - x));

symbolic procedure acoth x;
   if abs x<=1 then terrlst(x,'acoth) else atanh (1.0/x);

symbolic procedure sech x;1/cosh x;

symbolic procedure csch x;1/sinh x;

symbolic procedure asech x;
   if x<=0 or x>1 then terrlst(x,'asech) else acosh (1.0/x);

symbolic procedure acsch x;
   if (x:= float x)=0.0 then terrlst(x,'acsch) else asinh(1/x);

symbolic procedure ln x; log x;

symbolic procedure log10 x;
   if x>0 then log x/logten else terrlst(x,'logten);

symbolic procedure logb (x,b); %log x to base b;
   begin scalar a,s; a:=x>0; s:=not(b<=0 or zerop(b - 1));
         if a and s then return log x/log b
         else terrlst((if a then list ('base,b)
            else if s then list('arg,x) else list(x,b)),'logb) end;

symbolic procedure atan2(y,x);
   if zerop x then !!pii2*sgn y else
   <<(if x>0 then a else if y<0 then a - !!pii else a+!!pii)
     where a=atan(y/x)>>;

symbolic procedure atan2d(y,x);
   if zerop x then 90.0*sgn y else
   <<(if x>0 then a else if y<0 then a - 180.0 else a+180.0)
     where a=!!rad2deg*atan(y/x)>>;

% A numerical factorial function.

symbolic procedure factorial n;
   if not fixp n or n<0
     then rerror(arith,4,list(n,"invalid factorial argument"))
    else nfactorial n;

symbolic procedure nfactorial n;
   % Numerical factorial function.  It is assumed that n is numerical
   % and non-negative.
   if n>20 then fac!-part(1,n)
    else begin scalar m;
       m:=1;
       for i:=1:n do m:=m*i;
       return m;
     end;

symbolic procedure fac!-part (m,n);
    if m=n then m
     else if m=n - 1 then m*n
     else (fac!-part(m,p)*fac!-part(p+1,n)) where p=(m+n)/2;

endmodule;


module rounded; % *** Support for Arbitrary Rounded Arithmetic.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

% Last updated: 23 June 1993.

% Copyright (c) 1991,1993 RAND.  All rights reserved.

Comment this module defines a rounded object as a list with two fields:

      (<tag>.<structure>).

The <structure> depends on the precision.  It is either a floating point
number or the stripped bfloat (mt . ep);

exports chkint!*, chkrn!*, convprec, convprec!*, deg2rad!*,
        i2rd!*, logfp, mkround, rd!:difference, rd!:minus, rd!:minusp,
        rd!:onep, rd!:plus, rd!:prep, rd!:prin, rd!:quotient,
        rd!:simp, rd!:times, rd!:zerop, rdprep1, rdqoterr, rdzchk,
        rndbfon, round!*, roundbfoff, roundbfon, roundconstants,
        safe!-fp!-times;

imports !*d2q, !:difference, !:minus, !:minusp, !:zerop, abs!:, aeval,
        apply1, bf2flr, bfdiffer, bfexplode0, bfinverse, bflessp,
        bfloat, bfminus, bfminusp, bfprin!:, bftrim!:, bfzerop!:,
        bfzp, ceiling, copyd, deg2rad!*, difbf, divbf, dmoderr,
        ep!:, eqcar, equal!:, errorp, errorset!*, fl2int,
        fl2rd, float!-bfp, floor, ft2rn1, geq, greaterp!:, grpbf,
        i2bf!:, initdmode, invbf, leq, lessp!:, log, lprim, lshift,
        make!:ibf, make!:rd, minus!:, minusp!:, mkquote, msgpri, mt!:,
        neq, normbf, off1, on1, over, plubf, preci!:, r2bf, rd2fl,
        rd!:forcebf, realrat, rerror, retag, rmsubs, round!:mt, setk,
        sqrt, timbf, times!:, union;

fluid '(!:prec!: !:bprec!: !:print!-prec!: minprec!# rootacc!#!#);

fluid '(dmode!* !*bfspace !*numval !*roundbf !*!*roundbf !*norndbf);

fluid '(!*noconvert);

global '(bfone!* epsqrt!* log2of10);

global '(domainlist!* !!nfpd !!nbfpd !!flprec !!rdprec mxflbf!!
         mnflbf!!);

global '(!!plumax !!plumin !!timmax !!timmin !!maxflbf !!minflbf
         !!fleps1 !!fleps2 !!flint !!maxbflexp log2 !!maxarg);

global '(rd!-tolerance!* cr!-tolerance!* yy!! bfz!* !!smlsin);

switch rounded;

%Set value for !!flprec. It never changes.
!!flprec := !!nfpd - 3;

!!smlsin := 10.0^-(2+!!flprec);

symbolic procedure logfp x;
  % floating log of x**(1/n) using bfloat logic as boost.
  (log(m/float lshift(1,p))+(p+ep!: x)*log2)
    where p=(preci!: x - 1) where m=mt!: x;

symbolic procedure roundconstants;
   <<!!plumax := float(2**(!!maxbflexp -1));
     !!minflbf := invbf(!!maxflbf := make!:ibf (1,!!maxbflexp));
    % plumin must be large enough to avoid underflow from difference.
     !!plumin := 10.0**!!flprec/!!plumax;
     !!timmin := 1/(!!timmax := sqrt(!!plumax));
     !!maxarg := logfp !!maxflbf>>;

switch bfspace,numval,roundbf; % norndbf.

!*bfspace := nil;
!*numval := t;

put('roundbf,'simpfg,'((t (roundbfon)) (nil (roundbfoff))));

symbolic procedure roundbfon; !*!*roundbf := t;

symbolic procedure roundbfoff; !*!*roundbf := !!rdprec > !!flprec;

%  put('rounded,'package!-name,'arith);  % Use if ARITH autoloaded.

domainlist!* := union('(!:rd!:),domainlist!*);

put('rounded,'tag,'!:rd!:);
put('!:rd!:,'dname,'rounded);
flag('(!:rd!:),'field);
put('!:rd!:,'i2d,'i2rd!*);
put('!:rd!:,'minusp,'rd!:minusp);
put('!:rd!:,'plus,'rd!:plus);
put('!:rd!:,'times,'rd!:times);
put('!:rd!:,'difference,'rd!:difference);
put('!:rd!:,'quotient,'rd!:quotient);
put('!:rd!:,'zerop,'rd!:zerop);
put('!:rd!:,'onep,'rd!:onep);
put('!:rd!:,'prepfn,'rd!:prep);
put('!:rd!:,'prifn,'rd!:prin);
put('!:rd!:,'minus,'rd!:minus);
put('!:rd!:,'rootfn,'rd!:root);
put('!:rd!:,'!:rn!:,'!*rd2rn);
put('!:rn!:,'!:rd!:,'!*rn2rd);

symbolic procedure round!* x;
   % Returns actual number representation, as either float or bfloat.
%   retag cdr x;
   if float!-bfp x then rd2fl x else x;

symbolic procedure mkround u;
   % inverse operation to round!*, i.e. tags a naked float
   if atom u then make!:rd u else u;

%symbolic procedure roundbfp; !*roundbf or !!rdprec > !!flprec;

symbolic procedure print!-precision n;
   % Set the system printing precision !:print!-prec!:.
   % Returns previous value.
   begin scalar oldprec;
      if n=0 then return !:print!-prec!:;
      if n<0 then
         << oldprec := !:print!-prec!:;
            !:print!-prec!: := nil;
            return oldprec >>;
      if n > !:prec!: then
         << msgpri(nil,"attempt to set print!-precision greater than",
                       "precision ignored",nil,nil);
            return nil >>;
      oldprec := !:print!-prec!:;
      !:print!-prec!: := n;
      return oldprec
   end;

symbolic procedure print_precision n;
   % Alternative name.
   print!-precision n;

symbolic procedure precision0 n;
  % called from algebraic call of precision.
   if n member '((nil) () (reset))
      then <<rootacc!#!# := nil; precision !!flprec>>
   else if cdr n
     or not numberp(n := prepsq simp!* aeval {'fix,prepsq simp!* car n})
     or n<0 then
       rerror(arith,5,"positive numeric value or `RESET' required")
   else <<if n>0 then rootacc!#!# := max(n,6); precision n>>;

put('precision,'psopfn,'precision0);

symbolic procedure precision n;
   % Set the system precision !!rdprec, bfloat precision !:prec!:,
   % and rd!:onep tolerance. Returns previous value.
   <<if not numberp n or n<0
       then rerror(arith,6,"positive number required");
     precision1(n,t)>>;

log2of10 := log 10 / log 2;

symbolic procedure decprec2internal p;
   ceiling(p * log2of10) + 3;

% symbolic procedure internal2decprec p;
%    floor ((p - 3) / log2of10);

symbolic procedure precision1(n,bool);
   begin scalar oldprec;
      if n=0 then return !!rdprec;
      if bool then rmsubs();  % So that old results are resimplified.
      oldprec := !!rdprec;
      !:prec!: :=
        (!!rdprec := if !*roundbf then n else max(n,minprec!#))+2;
      if !:print!-prec!: and n < !:print!-prec!:+2
         then !:print!-prec!: := nil; %unset
      !:bprec!: := decprec2internal !:prec!:;
      epsqrt!* := make!:ibf(1, -!:bprec!:/2);
      rd!-tolerance!* := make!:ibf(1, 6-!:bprec!:);
      cr!-tolerance!* := make!:ibf(1, 2*(6-!:bprec!:));
%     if !!rdprec <= !!flprec then
%        <<!!fleps1 := 1.0/float(2**(!:bprec!: - 2));
%          !!fleps2 := !!fleps1**2>>;
      !*!*roundbf := !!rdprec > !!flprec or !*roundbf;
      return oldprec end;

flag('(print!-precision),'opfn); % Symbolic operator print!-precision.
flag('(print_precision),'opfn);  % Symbolic operator print_precision.

symbolic procedure !*rd2rn x;
 % Converts a rounded number N into a rational to the system precision.
 % Elegant form: uses both rd2rn1 and realrat... and choses the best,
 %  but uses a heuristic to avoid the extra work when not needed.
   begin scalar n,p,r,r1,r2,d1,d2,ov;
     if rd!:zerop x then return '!:rn!: . (0 . 1);
     p := precision 0;
     r := rd2rn1 x;
     r1 := '!:rn!: . r;
     if abs car r<10 or cdr r<10
       or 2*max(length explode cdr r,length explode abs car r)<p+1
         then go to ret;
     r2 := '!:rn!: . realrat bftrim!: rd!:forcebf x;
     precision(2+p);
     d1 := !:difference(x,r1); if !:minusp d1 then d1 := !:minus d1;
     d2 := !:difference(x,r2); if !:minusp d2 then d2 := !:minus d2;
     if !:zerop d2 or !:minusp !:difference(d2,d1) then ov := t;
     precision p;
ret: return if ov then r2 else r1 end;

symbolic procedure rd2rn1 n;
   if float!-bfp n then ft2rn1 rd2fl n else bf2rn1 n;

symbolic procedure bf2rn1 n;
  % Here, the nonzero input n is always a binary bigfloat
   begin scalar negp,a,p0,p1,q0,q1,w,flagg,nn,r0,r1;
      if mt!: n<0 then <<negp := t; n := minus!: n>>;
      nn := n;
 top: a := ((if d=0 then m else lshift(m,d))
              where m=mt!: n,d=ep!: n);
      n := difbf(n,normbf i2bf!: a);
      if not flagg
        then <<flagg := t; p0 := 1; p1 := a; q0 := 0; q1 := 1>>
       else <<w := p0 + a*p1; p0 := p1; p1 := w; r0 := r1;
              w := q0 + a*q1; q0 := q1; q1 := w>>;
      r1 := abs!: difbf(nn,divbf(i2bf!: p1,i2bf!: q1));
     % temporary write statement here
    % if !*trrd2rn1 then << write p1 . q1," -> ",r1; terpri()>>;
      if bfzerop!: n or bfzerop!: r1
          then return if negp then (-p1) . q1 else p1 . q1
       else if r0 and not greaterp!:(r0,r1)
          then return if negp then (-p0) . q0 else p0 . q0;
      n := invbf n;
      go to top
  end;

symbolic procedure !*rn2rd u;
   % Converts the (tagged) rational u/v into a (tagged) rounded
   % number to the system precision, after testing to number
   mkround chkrn!* r2bf cdr u;

minprec!# := min(6,!!flprec-2);

precision1(!!flprec,nil);        % Initial value = effective float prec.

%!!fleps1 := 1.0/float(2**(!:bprec!: - 6));
!!fleps1 := 2.0**(6 - !:bprec!:);
!!fleps2 := !!fleps1**2;

symbolic procedure precmsg pr;
   if pr>!!rdprec then
      <<msgpri(nil,"precision increased to",pr,nil,nil);
        precision1(pr,t)>>;

symbolic procedure rd!:simp u;
   if eqcar(u,0) then nil ./ 1
    else if null dmode!* or dmode!* eq '!:gi!:
     then (if eqcar(x,'!:rn!:) then cdr x else x ./ 1)
           where x = !*rd2rn make!:rd u
    else if dmode!* memq '(!:rd!: !:cr!:)
     then (mkround convprec!* u) ./ 1 % Must call convprec!*, since
                                      % precision may have changed.
    else (if y then !*d2q apply1(y,make!:rd u)
           else dmoderr('!:rd!:,dmode!*))
          where y = get('!:rd!:,dmode!*);

put('!:rd!:,'simpfn,'rd!:simp);

symbolic procedure rndbfon; if not !*norndbf then
   <<!*!*roundbf := t;
     if !:prec!:<!!flprec+3 then
         <<!*roundbf := t;
           lprim "ROUNDBF turned on to increase accuracy">>>>;

symbolic procedure i2rd!* u;
% Converts integer U to tagged rounded form.
 mkround chkint!* u;

symbolic procedure chkint!* u;
   if !*!*roundbf then bfloat u else
    ((if msd!: x <= !!maxbflexp then float u
      else <<rndbfon(); bfloat u>>) where x=abs u);

mnflbf!! := invbf(mxflbf!! := make!:ibf (1, 800));

symbolic procedure chkrn!* u;
   if !*!*roundbf then u else bf2flck u;

symbolic procedure bf2flck u;
   if !*!*roundbf then u
   else if mt!: u=0 then 0.0 else
    ((if not grpbf(!!minflbf,r) and not grpbf(r,!!maxflbf)
         then bf2flr u
      else <<rndbfon(); u>>) where r := abs!: u);

symbolic procedure convchk x;
   if !*!*roundbf then if atom x then bfloat x else x
   else if atom x then x else bf2flck x;

symbolic procedure convprec!* u;
   convchk retag u;

symbolic procedure convprec u; convchk round!* u;

symbolic procedure rd!:minusp u;
  % bfminusp round!* u;
   if float!-bfp u then minusp rd2fl u else minusp!: u;

symbolic procedure convprc2(u,v);
   <<u := convprec u; yy!! := convprec v;
     if !*roundbf then <<yy!! := bfloat yy!!; bfloat u>> else u>>;

symbolic procedure rdzchk(u,x,y);
 if atom u then
    if u=0.0 or x>0.0 and y>0.0 or x<0.0 and y<0.0 then u
    else if abs u<(abs x)*!!fleps1 then 0.0 else u
 else
    if mt!: u=0 or mt!: x>0 and mt!: y>0 or mt!: x<0 and mt!: y<0 then u
    else if lessp!:(abs!: u,times!:(abs!: x,rd!-tolerance!*)) then bfz!*
    else u;

symbolic procedure rd!:plus(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-plus(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      u := if not atom x then plubf(x,y) else
         <<z := errorset!*(list('plus2,mkquote x,mkquote y),nil);
           if errorp z
             then <<rndbfon(); plubf(x := bfloat x,y := bfloat y)>>
             else car z>>;
      return mkround rdzchk(u,x,y) end) where z=nil;

symbolic procedure rd!:difference(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-plus(cdr u,-cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      u := if not atom x then difbf(x,y) else
         <<z := errorset!*(list('difference,mkquote x,mkquote y),nil);
           if errorp z
             then <<rndbfon(); difbf(x := bfloat x,y := bfloat y)>>
             else car z>>;
      return mkround rdzchk(u,x,if atom y then -y else minus!: y) end)
   where z=nil;

symbolic procedure rd!:times(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-times(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      return mkround if not atom x then timbf(x,y) else
         <<z := errorset!*(list('times2,mkquote x,mkquote y),nil);
           if errorp z then <<rndbfon(); timbf(bfloat x,bfloat y)>>
              else car z>> end) where z=nil;

symbolic procedure rd!:quotient(u,v);
  if !:zerop v then rerror(arith,7,"division by zero") else
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-quot(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      if atom x and zerop y then rdqoterr();
      return mkround if not atom x then
         if mt!: y=0 then rdqoterr() else divbf(x,y)
         else
           <<z := errorset!*(list('quotient,mkquote x,mkquote y),nil);
             if errorp z then <<rndbfon(); divbf(bfloat x,bfloat y)>>
                else car z>> end) where z=nil;

symbolic procedure rdqoterr; error(0,"zero divisor in quotient");

% symbolic procedure safe!-fp!-plus(x,y);
%    if zerop x then y else if zerop y then x else
%    begin scalar u;
%       if x>0.0 and y>0.0 then
%          if x<!!plumax and y<!!plumax then go to ret else return nil;
%       if x<0.0 and y<0.0 then
%         if -x<!!plumax and -y<!!plumax then go to ret else return nil;
%       if abs x<!!plumin and abs y<!!plumin then return nil;
%  ret: return
%         if (u := plus2(x,y))=0.0
%            or x>0.0 and y>0.0 or x<0.0 and y<0.0 then u
%         else if abs u<(abs x)*!!fleps1 then 0.0 else u end;

symbolic procedure safe!-fp!-plus(x,y);
   if zerop x then y
    else if zerop y then x
    else if x>0.0 and y>0.0
     then if x<!!plumax and y<!!plumax then plus2(x,y) else nil
    else if x<0.0 and y<0.0
     then if -x<!!plumax and -y<!!plumax then plus2(x,y) else nil
    else if abs x<!!plumin and abs y<!!plumin then nil
    else (if u=0.0 then u else if abs u<!!fleps1*abs x then 0.0 else u)
         where u = plus2(x,y);

symbolic procedure safe!-fp!-times(x,y);
 if zerop x or zerop y then 0.0
 else if x=1.0 then y else if y=1.0 then x else
   begin scalar u,v; u := abs x; v := abs y;
      if u>=1.0 and u<=!!timmax then
         if v<=!!timmax then go to ret else return nil;
      if u>!!timmax then if v<=1.0 then go to ret else return nil;
      if u<1.0 and u>=!!timmin then
         if v>=!!timmin then go to ret else return nil;
      if u<!!timmin and v<1.0 then return nil;
 ret: return times2(x,y) end;

symbolic procedure safe!-fp!-quot(x,y);
 if zerop y then rdqoterr()
 else if zerop x then 0.0 else if y=1.0 then x else
   begin scalar u,v; u := abs x; v := abs y;
      if u>=1.0 and u<=!!timmax then
         if v>=!!timmin then go to ret else return nil;
      if u>!!timmax then if v>=1.0 then go to ret else return nil;
      if u<1.0 and u>=!!timmin then
         if v<=!!timmax then go to ret else return nil;
      if u<!!timmin and v>1.0 then return nil;
 ret: return quotient(x,y) end;

symbolic procedure rd!:zerop u;
  % bfzp round!* u;
   if float!-bfp u then zerop rd2fl u else mt!: u = 0;

symbolic procedure rd!:minus u;
  % mkround bfminus round!* u;
   if float!-bfp u then fl2rd (- rd2fl u) else minus!: u;

symbolic procedure rd!:onep u;
   % We need the tolerance test since some LISPs (e.g. PSL) can print
   % a number as 1.0, but it doesn't equal 1.0!
   if float!-bfp u then abs(1.0 - rd2fl u)<!!fleps1
    else equal!:(bfone!*,bftrim!: u);

symbolic procedure rd!:root(u,n);
   if float!-bfp u then fl2rd expt(rd2fl u,recip float n)
    else texpt!:any(u,quotient!:(bfone!*,i2bf!: n));

% Since decimal input -> :rd: in all dmodes, dmode!* must be used to
% determine whether to round to current precision,  but input never gets
% truncated, since precision is always increased at input time.
% to avoid inaccuracies in floating point representation, rd!:prep
% returns values in bfloat format.

symbolic procedure rd!:prep u;
   if !*noconvert then rdprep1 u
    else if rd!:onep u then 1
   else if rd!:onep rd!:minus u then -1 else rdprep1 u;

%symbolic procedure rdprep1 u;
%   if float!-bfp u then
%     if not dmode!* memq '(!:rd!: !:cr!:) or !*!*roundbf
%       then round!:mt(bfloat rd2fl u,min(!:bprec!:,!!nbfpd))
%      else if !:bprec!:>!!nbfpd then u
%      else fl2rd bf2flr round!:mt(bfloat rd2fl u,!:bprec!:)
%    else round!:mt(u,!:bprec!:);

symbolic procedure rdprep1 u;
   if float!-bfp u then u else round!:mt(u,!:bprec!:);

symbolic procedure rd!:prin u;
  % Printed output is rounded to 2 fewer places than internal value.
   bfprin!: bftrim!: rd!:forcebf u;

symbolic procedure rd!:explode u;
   bfexplode0 bftrim!: rd!:forcebf u;

initdmode 'rounded;

endmodule;


module comprd; % *** Support for Complex Rounded Arithmetic.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

% Last updated: 23 June 1993.

% Copyright (c) 1989, 1993 The RAND Corporation.  All rights reserved.

Comment this module defines a complex rounded as:

  (<tag>. (<structure> . <structure>>)  or  ('!:cr!: . (rl . im))

The <structure> depends on the precision.  It is either a floating point
number or the stripped bfloat (mt . ep);


exports !*cr2crn, !*cr2rd, !*cr2rn, !*crn2cr, !*gi2cr, !*rd2cr,
        !*rn2cr, cr!:differ, cr!:minus, cr!:minusp, cr!:onep,
        cr!:plus, cr!:prep, cr!:prin, cr!:quotient, cr!:times,
        cr!:zerop, cr2i!*, crhalf!*, cri!*, cri!/2, crone!*, crprcd,
        gf2cr!:, i2cr!*, mkcr;

imports bfloat, bfnzp, bftrim!:, bfzp, chkint!*, chkrn!*, convprec,
        convprec!*, crim, crrl, ep!:, errorp, errorset!*,
        gf2bf, gfdiffer, gfminus, gfplus, gfquotient, gftimes,
        gfzerop, initdmode, leq, lessp!:, make!:cr, make!:rd, maprin,
        mkcrn, mkquote, mkrn, mkround, normbf, over, plubf, preci!:,
        prin2!*, r2bf, rd!:minus, rd!:minusp, rd!:onep, rd!:prep,
        rd!:zerop, rdprep1, rdhalf!*, rdone!*, rdqoterr, rdtwo!*,
        rdzchk, rdzero!*, realrat, retag, rndbfon, round!:mt,
        safe!-fp!-plus, safe!-fp!-times, timbf, union;

fluid '(!:prec!: !:bprec!:);

global '(bfone!* epsqrt!*);

fluid '(dmode!* !*bfspace !*numval !*roundbf !*!*roundbf);

global '(cr!-tolerance!* domainlist!* !!nfpd !!flprec !!rdprec bfz!*
         yy!!);

domainlist!* := union('(!:cr!:),domainlist!*);

fluid '(!*complex!-rounded);

put('complex!-rounded,'tag,'!:cr!:);
put('!:cr!:,'dname,'complex!-rounded);
flag('(!:cr!:),'field);
put('!:cr!:,'i2d,'i2cr!*);
put('!:cr!:,'plus,'cr!:plus);
put('!:cr!:,'times,'cr!:times);
put('!:cr!:,'difference,'cr!:differ);
put('!:cr!:,'quotient,'cr!:quotient);
put('!:cr!:,'zerop,'cr!:zerop);
put('!:cr!:,'onep,'cr!:onep);
put('!:cr!:,'prepfn,'cr!:prep);
put('!:cr!:,'prifn,'cr!:prin);
put('!:cr!:,'minus,'cr!:minus);
put('!:cr!:,'minusp,'cr!:minusp);
% put('!:cr!:,'rationalizefn,'girationalize!:);  % Needs something
                                                 % different.
put('!:cr!:,'!:rn!:,'!*cr2rn);
put('!:rn!:,'!:cr!:,'!*rn2cr);
put('!:rd!:,'!:cr!:,'!*rd2cr);
put('!:cr!:,'!:rd!:,'!*cr2rd);
put('!:cr!:,'!:crn!:,'!*cr2crn);
put('!:crn!:,'!:cr!:,'!*crn2cr);
put('!:gi!:,'!:cr!:,'!*gi2cr);
put('!:cr!:,'cmpxfn,'mkcr);
put('!:cr!:,'ivalue,'mkdcrn);
put('!:cr!:,'realtype,'!:rd!:);
put('!:rd!:,'cmpxtype,'!:cr!:);

symbolic procedure cr!:minusp u;
   (if atom x then zerop y and x<0 else zerop car y and car x<0)
    where x=cadr u,y=cddr u;

symbolic procedure striptag u; if atom u then u else cdr u;

symbolic procedure mkcr(u,v); make!:cr (striptag u, striptag v);

symbolic procedure gf2cr!: x;
   make!:cr (striptag car x, striptag cdr x);

symbolic procedure crprcd u;
   (rl . im) where rl=convprec!* crrl u,im=convprec!* crim u;

symbolic procedure crprcd2(x,y);
   <<x := crprcd x; yy!! := crprcd y; x>>;

% simp must call convprec!*, since precision may have changed.
symbolic procedure cr!:simp u; (gf2cr!: crprcd u) ./ 1;

put('!:cr!:,'simpfn,'cr!:simp);

%symbolic procedure mkdcr u; cri!*() ./ 1;

symbolic procedure i2cr!* u;
   %converts integer U to tagged cr form.
   <<u := chkint!* u; mkcr(u,if atom u then 0.0 else bfz!*)>>;

symbolic procedure trimcrrl n; trimcr crrl n;

symbolic procedure trimcr n;
   bftrim!: if atom n then bfloat n else retag n;

symbolic procedure cr2rderr;
   error(0,
   "complex to real type conversion requires zero imaginary part");

symbolic procedure !*cr2rn n;
   % Converts a cr number n into a rational if possible.
   if bfnzp retag crim n then cr2rderr() else
   <<n := realrat trimcrrl n; mkrn(car n,cdr n)>>;

symbolic procedure !*rn2cr u;
   % Converts the (tagged) rational u/v into a (tagged) rounded complex
   % number to the system precision.
   <<u := chkrn!* r2bf cdr u; mkcr(u,if atom u then 0.0 else bfz!*)>>;

symbolic procedure !*cr2crn u;
   % Converts a (tagged) cr number u into a (tagged) crn.
   mkcrn(realrat trimcrrl u,realrat trimcr crim u);

symbolic procedure !*crn2cr u;
   % Converts a (tagged) crn number u into a (tagged) cr.
    mkcr(rl,if !*roundbf then bfloat im else im)
     where rl=chkrn!* r2bf cadr u where im=chkrn!* r2bf cddr u;

symbolic procedure !*cr2rd n;
   if bfnzp retag crim n then cr2rderr() else make!:rd crrl n;

symbolic procedure !*rd2cr u;
   mkcr(x,if atom x then 0.0 else bfz!*) where x=convprec u;

symbolic procedure !*gi2cr u;
   mkcr(rl,if !*roundbf then bfloat im else im)
    where rl=chkint!* cadr u where im=chkint!* cddr u;

symbolic procedure bfrsq u;
   (if atom x then x*x+y*y else plubf(timbf(x,x),timbf(y,y)))
    where x=car u,y=cdr u;

symbolic procedure crzchk(u,x,y);
 begin
    if atom car u then
      if bfrsq u<(bfrsq x)*!!fleps2 then return 0.0 . 0.0 else go to ck;
    if lessp!:(bfrsq u,timbf(bfrsq x,cr!-tolerance!*)) then
      return bfz!* . bfz!*;
ck: return rdzchk(car u,car x,car y) . rdzchk(cdr u,cdr x,cdr y) end;

symbolic procedure cr!:plus(u,v);
 begin scalar x,y; x := crprcd2(u,v); y := yy!!;
   u := if !*!*roundbf then gfplus(x,y)
        else if (v := safe!-crfp!-plus(x,y)) then v else
     ((if errorp r then
       <<rndbfon(); gfplus(x := gf2bf x,y := gf2bf y)>> else car r)
     where r=errorset(list('gfplus,mkquote x,mkquote y),nil,nil));
   return gf2cr!: crzchk(u,x,y) end;

symbolic procedure cr!:differ(u,v);
 begin scalar x,y; x := crprcd2(u,v); y := yy!!;
   u := if !*!*roundbf then gfdiffer(x,y)
        else if (v := safe!-crfp!-diff(x,y)) then v else
     ((if errorp r then
       <<rndbfon(); gfplus(x := gf2bf x,y := gf2bf y)>> else car r)
     where r=errorset(list('gfdiffer,mkquote x,mkquote y),nil,nil));
   return gf2cr!: crzchk(u,x,gfminus y) end;

symbolic procedure cr!:times(u,v);
 gf2cr!:
 (if !*!*roundbf then gftimes(x,yy!!)
  else if (u := safe!-crfp!-times(x,yy!!)) then u else
 ((if errorp r then <<rndbfon(); gftimes(gf2bf x,gf2bf yy!!)>>
      else car r)
    where r=errorset!*(list('gftimes,mkquote x,mkquote yy!!),nil)))
   where x=crprcd2(u,v);

symbolic procedure cr!:quotient(u,v);
 gf2cr!:
 (if gfzerop yy!! then rdqoterr()
  else if !*!*roundbf then gfquotient(x,yy!!)
  else if (u := safe!-crfp!-quot(x,yy!!)) then u else
 ((if errorp r then
      <<rndbfon(); gfquotient(gf2bf x,gf2bf yy!!)>> else car r)
    where r=errorset!*(list('gfquotient,mkquote x,mkquote yy!!),nil)))
   where x=crprcd2(u,v);

symbolic procedure safe!-crfp!-plus(u,v);
   (if x and y then crzchk(x . y,u,v))
   where x=safe!-fp!-plus(car u,car v),y=safe!-fp!-plus(cdr u,cdr v);

symbolic procedure safe!-crfp!-diff(u,v);
   (if x and y then crzchk(x . y,u,gfminus v))
   where x=safe!-fp!-plus(car u,-car v),y=safe!-fp!-plus(cdr u,-cdr v);

symbolic procedure safe!-crfp!-times(u,v);
   begin scalar ru,iu,rv,iv,a,b;
      ru := car u; iu := cdr u; rv := car v; iv := cdr v;
      if not (a := safe!-fp!-times(ru,rv)) or
         not (b := safe!-fp!-times(iu,iv)) then return nil;
      if not(u := safe!-fp!-plus(a,-b)) then return nil;
      u := rdzchk(u,a,-b);
      if not (a := safe!-fp!-times(ru,iv)) or
         not (b := safe!-fp!-times(iu,rv)) then return nil;
      if not(v := safe!-fp!-plus(a,b)) then return nil;
      return u . rdzchk(v,a,b) end;

symbolic procedure safe!-crfp!-quot(u,v);
  % compute u * inverse v.
   begin scalar ru,iu,rv,iv,a,b,dd;
      ru := car u; iu := cdr u; rv := car v; iv := cdr v;
      if not (a := safe!-fp!-times(rv,rv)) or
         not (b := safe!-fp!-times(iv,iv)) or
         not (dd := safe!-fp!-plus(a,b)) then return nil;
      rv := rv/dd; iv := iv/dd;
      if not (a := safe!-fp!-times(ru,rv)) or
         not (b := safe!-fp!-times(iu,iv)) or
         not (u := safe!-fp!-plus(a,b)) then return nil;
      u := rdzchk(u,a,b);
      if not (a := safe!-fp!-times(ru,-iv)) or
         not (b := safe!-fp!-times(iu,rv)) or
         not (v := safe!-fp!-plus(a,b)) then return nil;
      return u . rdzchk(v,a,b) end;

symbolic procedure cr!:minus u; gf2cr!: gfminus crprcd u;

symbolic procedure cr!:zerop u;
   bfzp retag crrl u and bfzp retag crim u;

symbolic procedure cr!:onep u;
   bfzp retag crim u and rd!:onep mkround retag crrl u;

% prep works entirely in bfloat, to avoid floating point conversion
% errors.

symbolic procedure cr!:prep u;
   crprep1((rd!:prep tagrl u) . rd!:prep tagim u);

symbolic procedure crprep1 u;
 % a and d are 1,-1,or rounded.
  (if not numberp d and rd!:zerop d then a else
     <<d := if numberp d or not rd!:minusp d
        then crprimp d else {'minus,crprimp rd!:minus d};
       if not numberp a and rd!:zerop a then d else
         <<if a = -1 then a := {'minus,1}
             else if not numberp a and rd!:minusp a
               then a := {'minus,rd!:minus a};
           {'plus,a,d}>> >>) where a=car u,d=cdr u;

symbolic procedure crprimp u;
   if u=1 then 'i else if u= -1 then {'minus,'i} else {'times,u,'i};

symbolic procedure cr!:prin v;
   if atom (v := cr!:prep v)
     or car v eq 'times or car v memq domainlist!*
      then maprin v
    else <<prin2!* "("; maprin v; prin2!* ")">>;

initdmode 'complex!-rounded;

symbolic procedure crone!*; mkcr(rdone!*(),rdzero!*());

symbolic procedure crhalf!*; mkcr(rdhalf!*(),rdzero!*());

symbolic procedure cri!*; mkcr(rdzero!*(),rdone!*());

symbolic procedure cri!/2; mkcr(rdzero!*(),rdhalf!*());

symbolic procedure cr2i!*; mkcr(rdzero!*(),rdtwo!*());

endmodule;


module rdelem;  % Elementary functions in rounded domain.

exports deg2rad!*, quotient!:, rad2deg!*, rdacos!*, rdacosd!*,
        rdacosh!*, rdacot!*, rdacotd!*, rdacoth!*, rdacsc!*, rdacscd!*,
        rdacsch!*, rdarg!*, rdasec!*, rdasecd!*, rdasech!*, rdasin!*,
        rdasind!*, rdasinh!*, rdatan!*, rdatan2!*, rdatan2d!*,
        rdatand!*, rdatanh!*, rdcbrt!*, rdcos!*, rdcosd!*, rdcosh!*,
        rdcot!*, rdcotd!*, rdcoth!*, rdcsc!*, rdcscd!*, rdcsch!*,
        rde!*, rdexp!*, rdexpt!*, rdhalf!*, rdhypot!*, rdlog!*,
        rdlog10!*, rdlogb!*, rdnorm!*, rdone!*, rdpi!*, rdsec!*,
        rdsecd!*, rdsech!*, rdsin!*, rdsind!*, rdsinh!*,
        rdsqrt!*, rdtan!*, rdtand!*, rdtanh!*, rdtwo!*, rdzero!*,
        texpt!:, texpt!:any;

imports !*f2q, abs!:, acos, acos!*, acosd, acosh, acot, acotd, acoth,
        acsc, acscd, acsch, asec, asecd, asech, asin, asin!*, asind,
        asinh, atan, atan!*, atan2, atan2d, atand, atanh, bflerrmsg,
        bfloat, bfp!:, bfsqrt, cbrt, conv!:bf2i, conv!:bf2i, conv!:mt,
        convprec, cos, cos!*, cosd, cosh, cot, cotd, coth, csc, cscd,
        csch, difbf, divbf, e!*, ep!:, eqcar, equal!:, exp, exp!*,
        exp!:, exptbf, geq, greaterp!:, hypot, i2rd!*, incprec!:,
        invbf, leq, leq!:, lessp!:, log, log!*, log10, log!:,
        logb, logfp, lshift, make!:ibf, minus!:, minusp!:, mk!*sq,
        mkround, mt!:, neq, pi!*, plubf, preci!:, rd!:minus,
        rd!:minusp, read!:num, rndbfon, round!*, round!:last,
        round!:mt, sec, secd, sech, sgn, simprd, sin, sin!*, sind,
        sinh, sqrt, sqrt!:, tan, tan!*, tand, tanh, terrlst, timbf,
        times!:;

fluid '(!:prec!: !:bprec!: !*!*roundbf);

global '(bfz!* bfone!* bften!* bfhalf!* !:180!* !:bf1!.5!* bfthree!*
 !:bf60!* epsqrt!* bftwo!* !!pii !!flprec !!rdprec !!shbinfl
 pi!/180 !180!/pi !!ee !!maxarg);

pi!/180 := !!pii/180;  !180!/pi := 180/!!pii;

fluid '(!*numval);

deflist('((exp rdexp!*) (expt rdexpt!*) (log rdlog!*) (sin rdsin!*)
   (cos rdcos!*) (tan rdtan!*) (asin rdasin!*) (acos rdacos!*)
   (atan rdatan!*) (sqrt rdsqrt!*) (sinh rdsinh!*) (cosh rdcosh!*)
   (sec rdsec!*) (csc rdcsc!*) (cot rdcot!*) (tanh rdtanh!*)
   (coth rdcoth!*) (sech rdsech!*) (csch rdcsch!*) (asinh rdasinh!*)
   (acosh rdacosh!*) (acot rdacot!*) (asec rdasec!*) (acsc rdacsc!*)
   (atanh rdatanh!*) (acoth rdacoth!*) (asech rdasech!*)
   (acsch rdacsch!*) (logb rdlogb!*) (log10 rdlog10!*) (ln rdlog!*)
   (atan2 rdatan2!*) (hypot rdhypot!*) % (cbrt rdcbrt!*)
   (deg2rad deg2rad!*) (rad2deg rad2deg!*) (deg2dms deg2dms!*)
   (rad2dms rad2dms!*) (dms2deg dms2deg!*) (dms2rad dms2rad!*)
   (norm rdnorm!*) (arg rdarg!*) (e rde!*) (pi rdpi!*)),
   '!:rd!:);

% deflist('((sind rdsind!*) (cosd rdcosd!*) (asind rdasind!*) (acosd
%    rdacosd!*) (tand rdtand!*) (cotd rdcotd!*) (atand rdatand!*) (acotd
%    rdacotd!*) (secd rdsecd!*) (cscd rdcscd!*) (asecd rdasecd!*) (acscd
%    rdacscd!*) (atan2d rdatan2d!*)),'!:rd!:);



for each n in '(exp sin cos tan asin acos atan sinh cosh  % log
    sec csc cot tanh coth sech csch asinh acosh acot asec acsc atanh
    acoth asech acsch logb log10 ln atan2 hypot
%   sind cosd asind acosd tand cotd atand acotd secd cscd asecd acscd
%   atan2d cbrt
    deg2rad rad2deg deg2dms rad2dms dms2deg dms2rad norm arg argd)
       do put(n,'simpfn,'simpiden);

flag('(dms2deg dms2rad),'listargp);

deflist('((dms2deg!* simpdms) (dms2rad!* simpdms)), 'simparg);

deflist('((atan2 2) (hypot 2) (atan2d 2) (logb 2)),
  'number!-of!-args);

flag('(acsc sind asind tand atand cotd acotd cscd acscd csch
       acsch deg2rad rad2deg),'odd);   % sgn.

flag('(cosd secd),'even);

flag('(cotd sech),'nonzero);

symbolic procedure rdexp!* u; mkround
  (if not atom x then exp!* x
   else if x>!!maxarg then <<rndbfon(); exp!* bfloat x>>
   else if x<-!!maxarg then 0.0 else exp x)
   where x=convprec u;

symbolic procedure rdsqrt!* u;
   mkround(if atom x then sqrt x else bfsqrt x)
   where x=convprec u;

symbolic procedure rdexpt!*(u,v);
   mkround
     (if not atom x then texpt!:any(x,y) else
       if zerop x then if zerop y then rederr "0**0 formed" else u else
      ((if z>!!maxarg then <<rndbfon(); texpt!:any(bfloat x,bfloat y)>>
        else if z<-!!maxarg then 0.0 else rexpt(x,y))
        where z=y*logfp bfloat abs x))
      where x=convprec u,y=convprec v;

symbolic procedure rdlog!* u;
   mkround(if atom x then log x else log!* x)
   where x=convprec u;

% symbolic procedure rdsgn!* u;
%   (if atom x then sgn x else sgn mt!: x) where x=round!* u;

symbolic procedure rdatan2!*(u,v);
   if !:zerop u and !:zerop v
     then rerror(arith,8,"0/0 formed")
    else (mkround(if atom x then atan2(x,y) else atan2!*(x,y))
          where x=convprec u,y=convprec v);

% symbolic procedure rdatan2d!*(u,v);
%    mkround(if atom x then atan2d(x,y) else rad2deg!: atan2!*(x,y))
%    where x=convprec u,y=convprec v;

symbolic procedure atan2!*(y,x);
   if mt!: x=0 then if (y := mt!: y)=0 then bfz!* else
      <<x := pi!/2!*(); if y<0 then minus!: x else x>>
   else <<(if mt!: x>0 then a
      else if mt!: y<0 then difbf(a,pi!*())
         else plubf(a,pi!*()))
     where a=atan!* divbf(y,x)>>;

% symbolic procedure atan2d!*(y,x);
%    if mt!: x=0 then if (y := mt!: y)=0 then bfz!* else
%       <<x := timbf(!:180!*,bfhalf!*); if y<0 then minus!: x else x>>
%    else <<(if mt!: x>0 then a
%       else if mt!: y<0 then difbf(a,!:180!*) else plubf(a,!:180!*))
%      where a=rad2deg!: atan!* divbf(y,x)>>;

symbolic procedure rde!*; mkround if !*!*roundbf then e!*() else !!ee;

symbolic procedure rdpi!*;
   mkround if !*!*roundbf then pi!*() else !!pii;

symbolic procedure pi!/2!*; timbf(bfhalf!*,pi!*());

symbolic procedure deg2rad!* u;
   mkround(if atom x then deg2rad x else deg2rad!: x)
   where x=convprec u;

symbolic procedure rad2deg!* u;
   mkround(if atom x then rad2deg x else rad2deg!: x)
   where x=convprec u;

symbolic procedure deg2rad x; x*pi!/180;

symbolic procedure rad2deg x; x*!180!/pi;

symbolic procedure deg2rad!: x; divbf(timbf(x,pi!*()),!:180!*);

symbolic procedure rad2deg!: x; divbf(timbf(x,!:180!*),pi!*());

symbolic procedure rdsin!* u;
   mkround (if atom x then sin x else sin!* x)
   where x=convprec u;

% symbolic procedure rdsind!* u;
%    mkround (if atom x then sind x else sin!* deg2rad!: x)
%    where x=convprec u;

symbolic procedure rdcos!* u;
   mkround(if atom x then cos x else cos!* x)
   where x=convprec u;

% symbolic procedure rdcosd!* u;
%    mkround(if atom x then cosd x else cos!* deg2rad!: x)
%   where x=convprec u;

symbolic procedure rdtan!* u;
   mkround(if atom x then tan x else tan!* x)
   where x=convprec u;

% symbolic procedure rdtand!* u;
%    mkround(if atom x then tand x else tan!* deg2rad!: x)
%   where x=convprec u;

symbolic procedure rdasin!* u;
   mkround(if atom x then asin x else asin!* x)
   where x=convprec u;

% symbolic procedure rdasind!* u;
%    mkround(if atom x then asind x else rad2deg!: asin!* x)
%    where x=convprec u;

symbolic procedure rdacos!* u;
   mkround(if atom x then acos x else acos!* x)
   where x=convprec u;

% symbolic procedure rdacosd!* u;
%    mkround(if atom x then acosd x else rad2deg!: acos!* x)
%    where x=convprec u;

symbolic procedure rdatan!* u;
   mkround(if atom x then atan x else atan!* x)
   where x=convprec u;

% symbolic procedure rdatand!* u;
%    mkround(if atom x then atand x else rad2deg!: atan!* x)
%   where x=convprec u;

symbolic procedure rdsinh!* u;
   mkround(if atom x then sinh x else sinh!* x)
   where x=convprec u;

symbolic procedure rdcosh!* u;
   mkround(if atom x then cosh x else cosh!* x)
   where x=convprec u;

% these redefine functions that are in bfelem, and are faster.

symbolic procedure sinh!* x;
   timbf(bfhalf!*,difbf(y,invbf y)) where y=exp!* x;

symbolic procedure cosh!* x;
   timbf(bfhalf!*,plubf(y,invbf y)) where y=exp!* x;


% no bfelem functions after this point.

symbolic procedure rdsec!* u;
   mkround(if atom x then sec x else invbf cos!* x)
   where x=convprec u;

% symbolic procedure rdsecd!* u;
%    mkround(if atom x then secd x else invbf cos!* deg2rad!: x)
%    where x=convprec u;

symbolic procedure rdcsc!* u;
   mkround(if atom x then csc x else invbf sin!* x)
   where x=convprec u;

% symbolic procedure rdcscd!* u;
%    mkround(if atom x then cscd x else invbf sin!* deg2rad!: x)
%   where x=convprec u;

symbolic procedure rdcot!* u;
   mkround(if atom x then cot x else tan!* difbf(pi!/2!*(),x))
   where x=convprec u;

% symbolic procedure rdcotd!* u;
%   mkround(if atom x then cotd x else tan!* difbf(pi!/2!*(),
%           deg2rad!: x))
%    where x=convprec u;

symbolic procedure rdtanh!* u;
   mkround(if atom x then tanh x else divbf(sinh!* x,cosh!* x))
   where x=convprec u;

symbolic procedure rdcoth!* u;
   mkround(if atom x then coth x else divbf(cosh!* x,sinh!* x))
   where x=convprec u;

symbolic procedure rdsech!* u;
   mkround(if atom x then sech x else invbf cosh!* x)
   where x=convprec u;

symbolic procedure rdcsch!* u;
   mkround(if atom x then csch x else invbf sinh!* x)
   where x=convprec u;

symbolic procedure rdasinh!* u;
   mkround(if atom x then asinh x else asinh!* x)
   where x=convprec u;

symbolic procedure rdacosh!* u;
   mkround(if atom x then acosh x else acosh!* x)
   where x=convprec u;

symbolic procedure asinh!* x; begin scalar s;
   if minusp!: x then x := minus!: x else s := t;
   x := if leq!:(x,epsqrt!*) then x
      else log!* plubf(x,
         if lessp!:(x,bftwo!*) then bfsqrt plubf(timbf(x,x),bfone!*)
         else if lessp!:(invbf x,epsqrt!*) then x
         else timbf(x,bfsqrt plubf(bfone!*,divbf(bfone!*,timbf(x,x)))));
   return if s then x else minus!: x end;

symbolic procedure acosh!* x;
   if lessp!:(x,bfone!*) then terrlst(x,'acosh)
   else log!* plubf(x,if leq!:(invbf x,epsqrt!*) then x
      else timbf(x,bfsqrt difbf(bfone!*,divbf(bfone!*,timbf(x,x)))));

symbolic procedure rdacot!* u;
   mkround(if atom x then acot x
      else difbf(pi!/2!*(),atan!* x))
   where x=convprec u;

% symbolic procedure rdacotd!* u;
%   mkround(if atom x then acotd x
%       else rad2deg!: difbf(pi!/2!*(),atan!* x))
%    where x=convprec u;

symbolic procedure rdasec!* u;  % not yet
   mkround(if atom x then asec x else
      difbf(pi!/2!*(),asin!* invbf x))
   where x=convprec u;

% symbolic procedure rdasecd!* u;  % not yet
%    mkround(if atom x then asecd x else
%       rad2deg!: difbf(pi!/2!*(),asin!* invbf x))
%    where x=convprec u;

symbolic procedure rdacsc!* u;
   mkround(if atom x then acsc x else asin!* invbf x)
   where x=convprec u;

% symbolic procedure rdacscd!* u;
%   mkround(if atom x then acscd x else rad2deg!: asin!* invbf x)
%   where x=convprec u;

symbolic procedure rdatanh!* u;
   mkround(if atom x then atanh x else atanh!* x)
   where x=convprec u;

symbolic procedure atanh!* x;
   if not greaterp!:(bfone!*,abs!: x) then terrlst(x,'atanh)
   else if leq!:(abs!: x,epsqrt!*) then x
   else timbf(bfhalf!*,
      log!* divbf(plubf(bfone!*,x),difbf(bfone!*,x)));

symbolic procedure rdacoth!* u;
   mkround(if atom x then acoth x else atanh!* invbf x)
   where x=convprec u;

symbolic procedure rdasech!* u;   % not from here down
   mkround(if atom x then asech x
      else if leq!:(x,bfz!*) or greaterp!:(x,bfone!*)
         then terrlst(x,'asech) else acosh!* invbf x)
   where x=convprec u;

symbolic procedure rdacsch!* u;
   mkround(if atom x then acsch x
      else if mt!: x=0 then terrlst(x,'acsh) else asinh!* invbf x)
   where x=convprec u;

symbolic procedure rdlogb!*(u,v);
   mkround(if atom x then logb(x,b) else logb!*(x,b))
   where x=convprec u,b=convprec v;

symbolic procedure rdlog10!* u;
   mkround(if atom x then log10 x else logb!*(x,bften!*))
   where x=convprec u;

symbolic procedure logb!* (x,b); %log x to base b;
   begin scalar a,s;
      a := greaterp!:(x,bfz!*);
      s := not(leq!:(b,bfz!*) or equal!:(b,bfone!*));
      if a and s then return divbf(log!* x,log!* b)
         else terrlst((if a then list ('base,b)
            else if s then list('arg,x) else list(x,b)),'logb) end;

% symbolic procedure rdcbrt!* u;
%    mkround(if atom x then cbrt x else cbrt!* x)
%    where x=convprec u;

% symbolic procedure cbrt!* x;
%    begin scalar s,l,g,u,nx,r; u := bfone!*;
%          if mt!: x=0 or equal!:(abs!: x,u) then return x
%          else if minusp!: x then x := minus!: x else s := t;
%          if lessp!:(x,u) then <<x := divbf(u,x); l := t>>
%             else if equal!:(x,u) then go to ret;
%          nx := '!:bf!: .
%             <<r := remainder(ep!:(nx := conv!:mt(x,3)),3);
%               if r=0 then (5+mt!: nx/179) . (ep!: nx/3)
%               else if r=1 or r=-2
%                then (10+mt!: nx/74) . ((ep!: nx-1)/3)
%               else (22+mt!: nx/35) . ((ep!: nx-2)/3)>>;
%    loop: r := nx;
%          nx := plubf(divbf(r,!:bf1!.5!*),
%             divbf(x,timbf(r,timbf(r,bfthree!*))));
%          if g and leq!:(r,nx) then go to ret;
%          g := t; go to loop;
%     ret: if l then nx := divbf(u,nx);
%          return if s then nx else minus!: nx end;

symbolic procedure rdhypot!*(u,v);
   mkround(if atom p then hypot(p,q) else hypot!*(p,q))
   where p=convprec u,q=convprec v;

symbolic procedure hypot!*(p,q);
 % Hypot(p,q)=sqrt(p*p+q*q) but avoids intermediate swell.
 begin scalar r;
   if minusp!: p then p := minus!: p; if minusp!: q then q := minus!: q;
   if mt!: p=0 then return q else if mt!: q=0 then return p
   else if lessp!:(p,q) then <<r := p; p := q; q := r>>;
   r := divbf(q,p);
   return if lessp!:(r,epsqrt!*) then p
      else timbf(p,bfsqrt plubf(bfone!*,timbf(r,r))) end;

symbolic procedure simpdms l;
   % Converts argument of form ({d,m,s}) to rd ((d m s)) if possible.
   if cdr l or atom (l := car l) or not eqcar(l,'list)
      or length l neq 4 then nil else
   begin scalar fl;
      l := for each a in cdr l collect
          if not (null(a := simprd list a) and (fl := t))
             then a := car a;
      if not fl then return list l end;

symbolic procedure round2a!* a; if atom a then a else round!* a;

symbolic procedure dms2rad!* u; deg2rad!* dms2deg!* u;

symbolic procedure dms2deg!* u;
   mkround(if atom caddr l then dms2deg l else dms2deg!: l)
   where l=list(round2a!* car u,round2a!* cadr u,round!* caddr u);

symbolic procedure dms2deg l; ((caddr l/60.0+cadr l)/60.0+car l);

symbolic procedure dms2deg!: l;
   plubf(bfloat car l,divbf(plubf(bfloat cadr l,
      divbf(bfloat caddr l,!:bf60!*)),!:bf60!*));

symbolic procedure rad2dms x; deg2dms rad2deg x;

symbolic procedure rad2dms!* u; deg2dms!* rad2deg!* u;

symbolic procedure deg2dms!* u;
   mklist3!*(if atom x then deg2dms x else deg2dms!: x)
   where x=round2a!* u;

symbolic procedure mklist3!* x; % floats seconds if not integer.
   'list . list(car x,cadr x,
      <<(if atom s and zerop(s-fix s) then fix s
         else if not atom s and integerp!: s then conv!:bf2i s
         else mk!*sq !*f2q mkround s) where s=caddr x>>);

symbolic procedure deg2dms x; % dms output in form list(d,m,s);
   begin integer d,m;
%     m := fix(x := 60.0*(x-(d := fix2 x)));
      m := fix(x := 60.0*(x-(d := fix x)));
      return list(d,m,60.0*(x-m)) end;

symbolic procedure deg2dms!: x; % dms output in form list(d,m,s).
   begin integer d,m;
      d := conv!:bf2i x;
      m := conv!:bf2i(x := timbf(!:bf60!*,difbf(x,bfloat d)));
      return list(d,m,timbf(!:bf60!*,difbf(x,bfloat m))) end;

symbolic procedure rdnorm!* u; if rd!:minusp u then rd!:minus u else u;

symbolic procedure rdarg!* u;
   if rd!:minusp u then rdpi!*() else rdzero!*();

% the following bfloat definitions are needed in addition to files
% smbflot and bfelem.red to support rdelem.

global '(!:bfone!* bftwo!* bfhalf!* bfz!* !:bf!-0!.25);

symbolic procedure rdone!*; if !*!*roundbf then bfone!* else 1.0;

symbolic procedure rdtwo!*; if !*!*roundbf then bftwo!* else 2.0;

symbolic procedure rdhalf!*; if !*!*roundbf then bfhalf!* else 0.5;

symbolic procedure rdzero!*; if !*!*roundbf then bfz!* else 0.0;

symbolic procedure texpt!:(nmbr, k);
% This function calculates the Kth power of "n" up to the
% binary precision specified by !:BPREC!:. %SK
% NMBR is a BINARY BIG-FLOAT representation of "n" and K an integer.
   if not fixp k then bflerrmsg 'texpt!:  % use texpt!:any in this case.
    else if k=0 then bfone!*
    else if k=1 then nmbr
    else if k<0 then invbf texpt!:(nmbr,-k) %SK
    else exptbf(nmbr,k,bfone!*); %SK

symbolic procedure quotient!:(n1, n2);
% This function calculates the integer quotient of "n1"
%      and "n2", just as the "QUOTIENT" for integers does.
% **** For calculating the quotient up to a necessary
% ****      precision, please use DIVIDE!:.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
begin integer e1, e2;
  if (e1 := ep!: n1) = (e2 := ep!: n2) then return
             make!:ibf(mt!: n1 / mt!: n2, 0)
   else if e1 > e2 then return
             quotient!:(incprec!:(n1, e1 - e2) , n2)
   else return
             quotient!:(n1, incprec!:(n2, e2 - e1));
end$

symbolic procedure texpt!:any(x, y);
  %modified by SK to use bfsqrt and exp!*, invbf and timbf.
% This function calculates the power x**y, where "x"
%      and "y" are any numbers.  The precision of
%      the result is specified by !:PREC!:. % SK
% **** For a negative "x", this function returns
% ****      -(-x)**y unless "y" is an integer.
% X is a BIG-FLOAT representation of "x".
% Y is either an integer, a floating-point number,
%      or a BIG-FLOAT number, i.e., a BIG-FLOAT
%      representation of "y".
    if equal!:(x,e!*()) then exp!* bfloat y
    else if fixp y then texpt!:(x, y)
    else if integerp!: y then texpt!:(x,conv!:bf2i y)
    else if not(bfp!: y or bfp!:(y := read!:num y))
     then bflerrmsg 'texpt!:any     % read!:num probably not necessary.
    else if minusp!: y then invbf texpt!:any(x,minus!: y) %SK
    else if equal!:(y,bfhalf!*) then bfsqrt x   %SK
    else if equal!:(y,!:bf!-0!.25) then bfsqrt bfsqrt x   %SK
    else begin integer n;  scalar xp, yp;
          n := (if !:bprec!: then !:bprec!:
                else max(preci!: x, preci!: y));
%          if minusp!: x then xp:=minus!: x else xp := x;
          if minusp!: x then bflerrmsg 'texpt!:any
           else xp := x;
          if integerp!: times!:(y,bftwo!*) then
             << xp := incprec!:(xp, 1);
                yp := texpt!:(xp, conv!:bf2i y);
                yp := times!:(yp, sqrt!:(xp, n + 1));
                yp := round!:mt(yp, n) >>
          else
             << yp := timbf(y, log!:(xp, n + 1)); %SK
                yp := exp!:(yp, n) >>;
          return (if minusp!: x then minus!: yp else yp);
     end;

symbolic procedure integerp!: x;
% This function returns T if X is a BINARY BIG-FLOAT
%      representing an integer, else it returns NIL.
% X is any LISP entity.
bfp!: x and
  (ep!: x >= 0 or
    preci!: x > - ep!: x and remainder(mt!: x,lshift(1,-ep!: x)) = 0);

endmodule;


module crelem; % Complex elementary functions for complex rounded.

imports !*rd2cr, bflessp, bfminusp, cr!:differ, cr!:minus, cr!:plus,
        cr!:quotient, cr!:times, cr!:zerop, cr2i!*, crhalf!*, cri!*,
        cri!/2, crprcd, crrl, deg2rad!*, gf2cr!:, gfsqrt, i2cr!*,
        i2rd!*, mkcr, rad2deg!*, rd!:minus, rd!:quotient, rd!:times,
        rdatan2!*, rdatan2d!*, rdcos!*, rdcosd!*, rdcosh!*, rde!*,
        rdexp!*, rdhalf!*, rdhypot!*, rdlog!*, rdone!*, rdpi!*,
        rdsin!*, rdsind!*, rdsinh!*, rdtwo!*, rdzero!*, retag,
        round!*, tagim, tagrl;

fluid '(!*!*roundbf);

global '(!!flprec !!rdprec bfz!* bftwo!* bfone!* bfhalf!*);

deflist('((expt crexpt!*) (sin crsin!*) (cos crcos!*) (tan crtan!*)
          (asin crasin!*) (acos cracos!*) (atan cratan!*)
          (cot crcot!*) (acot cracot!*) (sec crsec!*) (asec crasec!*)
          (csc crcsc!*) (acsc cracsc!*) (sinh crsinh!*) (cosh crcosh!*)
          (asinh crasinh!*) (acosh cracosh!*) (tanh crtanh!*)
          (coth crcoth!*) (atanh cratanh!*) (acoth cracoth!*)
          (sech crsech!*) (csch crcsch!*) (asech crasech!*)
          (acsch cracsch!*) (atan2 cratan2!*) (arg crarg!*)
          (sqrt crsqrt!*) (norm crnorm!*) (arg crarg!*) (log crlog!*)
          (exp crexp!*) (logb crlogb!*) (e cre!*) (pi crpi!*)),'!:cr!:);

% deflist('((sind crsind!*) (cosd crcosd!*) (tand crtand!*)
%           (asind crasind!*) (acosd cracosd!*) (atand cratand!*)
%           (cotd crcotd!*) (acotd cracotd!*) (secd crsecd!*)
%           (cscd crcscd!*) (acscd cracscd!*)
%           (asecd crasecd!*) (argd crargd!*)),'!:cr!:);

symbolic procedure cre!*; mkcr(rde!*(),rdzero!*());

symbolic procedure crpi!*; mkcr(rdpi!*(),rdzero!*());

symbolic procedure crexpt!*(u,v);
   if cr!:zerop(cr!:differ(v,crhalf!*())) then crsqrt!* u
   else crexp!* cr!:times(v,crlog!* u);

symbolic procedure crnorm!* u; rdhypot!*(tagrl u,tagim u);

symbolic procedure crarg!* u; rdatan2!*(tagim u,tagrl u);

% symbolic procedure crargd!* u; rdatan2d!*(tagim u,tagrl u);

symbolic procedure crsqrt!* u; gf2cr!: gfsqrt crprcd u;

symbolic procedure crr2d!* u; mkcr(rad2deg!* tagrl u,rad2deg!* tagim u);

symbolic procedure crd2r!* u; mkcr(deg2rad!* tagrl u,deg2rad!* tagim u);

symbolic procedure crsin!* u;
   mkcr(rd!:times(rdsin!* rl,rdcosh!* im),
        rd!:times(rdcos!* rl,rdsinh!* im))
    where rl=tagrl u,im=tagim u;

% symbolic procedure crsind!* u;
%    mkcr(rd!:times(rdsind!* rl,rdcosh!* deg2rad!* im),
%         rd!:times(rdcos!* rl,rdsinh!* deg2rad!* im))
%     where rl=tagrl u,im=tagim u;

symbolic procedure crcos!* u;
   mkcr(rd!:times(rdcos!* rl,rdcosh!* im),
        rd!:minus rd!:times(rdsin!* rl,rdsinh!* im))
    where rl=tagrl u,im=tagim u;

% symbolic procedure crcosd!* u;
%    mkcr(rd!:times(rdcosd!* rl,rdcosh!* deg2rad!* im),
%         rd!:minus rd!:times(rdsind!* rl,rdsinh!* deg2rad!* im))
%     where rl=tagrl u,im=tagim u;

symbolic procedure crtan!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:differ(y,x),cr!:plus(y,x)))
   where x=crexp!*(cr!:times(cr2i!*(),u)),y=i2cr!* 1;

% symbolic procedure crtand!* u;
%    cr!:times(cri!*(),cr!:quotient(cr!:differ(y,x),cr!:plus(y,x)))
%    where x=crexp!*(cr!:times(cr2i!*(),crd2r!* u)),y=i2cr!* 1;

symbolic procedure crcot!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:plus(x,y),cr!:differ(x,y)))
   where x=crexp!*(cr!:times(cr2i!*(),u)),y=i2cr!* 1;

% symbolic procedure crcotd!* u;
%    cr!:times(cri!*(),cr!:quotient(cr!:plus(x,y),cr!:differ(x,y)))
%    where x=crexp!*(cr!:times(cr2i!*(),crd2r!* u)),y=i2cr!* 1;

symbolic procedure cratan2!*(y,x);
    begin scalar q,p;
       q := crsqrt!* cr!:plus(cr!:times(y,y),cr!:times(x,x));
      if cr!:zerop q then error(0,list("invalid arguments to ",'atan2));
       y := cr!:quotient(y,q); x := cr!:quotient(x,q); p := rdpi!*();
       if cr!:zerop x then
          <<q := rd!:quotient(p,i2rd!* 2);
            return if bfminusp retag crrl y then rd!:minus q else q>>;
       q := cratan!* cr!:quotient(y,x);
       if bfminusp retag crrl x then
          <<p := !*rd2cr p;
            q := if bfminusp retag crrl y
               then cr!:differ(q,p) else cr!:plus(q,p)>>;
          %  bfzp x is probably impossible?
       return q end;

symbolic procedure crlog!* u;
   mkcr(rdlog!* crnorm!* u,crarg!* u);

symbolic procedure crlogb!*(u,b); cr!:quotient(crlog!* u,crlog!* b);

symbolic procedure timesi!* u; cr!:times(cri!*(),u);

symbolic procedure crasin!* u; cr!:minus timesi!* crasinh!* timesi!* u;

% symbolic procedure crasind!* u;
%    crr2d!* cr!:minus timesi!* crasinh!* timesi!* u;

symbolic procedure cracos!* u;
   cr!:plus(cr!:times(crhalf!*(),crpi!*()),
      timesi!* crasinh!* timesi!* u);

% symbolic procedure cracosd!* u;
%    crr2d!* cr!:plus(cr!:times(crhalf!*(),crpi!*()),
%       timesi!* crasinh!* timesi!* u);

symbolic procedure cratan!* u;
   cr!:times(cri!/2(),crlog!* cr!:quotient(
      cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));

% symbolic procedure cratand!* u;
%    crr2d!* cr!:times(cri!/2(),crlog!* cr!:quotient(
%       cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));

symbolic procedure cracot!* u;
   cr!:times(cri!/2(),crlog!* cr!:quotient(
      cr!:differ(u,cri!*()),cr!:plus(cri!*(),u)));

% symbolic procedure cracotd!* u;
%    crr2d!* cr!:times(cri!/2(),crlog!* cr!:quotient(
%       cr!:differ(u,cri!*()),cr!:plus(cri!*(),u)));

symbolic procedure crsec!* u; cr!:quotient(i2cr!* 1,crcos!* u);

% symbolic procedure crsecd!* u;
%    cr!:quotient(i2cr!* 1,crcos!* crd2r!* u);

symbolic procedure crcsc!* u; cr!:quotient(i2cr!* 1,crsin!* u);

% symbolic procedure crcscd!* u;
%   cr!:quotient(i2cr!* 1,crsin!* crd2r!* u);

symbolic procedure crasec!* u; cracos!* cr!:quotient(i2cr!* 1,u);

% symbolic procedure crasecd!* u;
%   crr2d!* cracos!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsc!* u; crasin!* cr!:quotient(i2cr!* 1,u);

% symbolic procedure cracscd!* u;
%   crr2d!* crasin!* cr!:quotient(i2cr!* 1,u);

symbolic procedure crsinh!* u;
   cr!:times(crhalf!*(),cr!:differ(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crcosh!* u;
   cr!:times(crhalf!*(),cr!:plus(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crtanh!* u;
   cr!:quotient(cr!:differ(x,y),cr!:plus(x,y))
   where x=crexp!*(cr!:times(i2cr!* 2,u)),y=i2cr!* 1;

symbolic procedure crcoth!* u;
   cr!:quotient(cr!:plus(x,y),cr!:differ(x,y))
   where x=crexp!*(cr!:times(i2cr!* 2,u)),y=i2cr!* 1;

symbolic procedure crsech!* u;
   cr!:quotient(i2cr!* 2,cr!:plus(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crcsch!* u;
   cr!:quotient(i2cr!* 2,cr!:differ(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crasinh!* u;
   crlog!* cr!:plus(u,
      if bflessp(round!* crnorm!* u,rdtwo!*())
         then crsqrt!* cr!:plus(i2cr!* 1,s)
         else cr!:times(u,
            crsqrt!* cr!:plus(i2cr!* 1,cr!:quotient(i2cr!* 1,s))))
   where s=cr!:times(u,u);

symbolic procedure cracosh!* u;
   crlog!* cr!:plus(u,crsqrt!* cr!:differ(cr!:times(u,u),i2cr!* 1));

symbolic procedure cratanh!* u;
   cr!:times(crhalf!*(),crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),
      cr!:differ(i2cr!* 1,u)));

symbolic procedure cracoth!* u;
   cr!:times(crhalf!*(),crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),
      cr!:differ(u,i2cr!* 1)));

symbolic procedure crasech!* u; cracosh!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsch!* u; crasinh!* cr!:quotient(i2cr!* 1,u);

symbolic procedure crexp!* u;
   <<u := tagim u; mkcr(rd!:times(r,rdcos!* u),rd!:times(r,rdsin!* u))>>
   where r=rdexp!* tagrl u;

endmodule;


module bfelem;  % Bigfloat elementary constants and functions.

% Last change date: 1 Jan 1993.

% Author: T. Sasaki, 1979.

% Modifications by: Anthony C. Hearn, Jed B. Marti, Stanley L. Kameny.
% Changed for binary arithmetic by Iain Beckingham and Rainer M. Schoepf

exports !:cbrt10, !:cbrt2, !:cbrt3, !:cbrt5, !:cbrte, !:cbrtpi,
        !:e, !:log10, !:log2, !:log3, !:log5, !:logpi, !:pi, !:sqrt10,
        !:sqrt2, !:sqrt3, !:sqrt5, !:sqrte, !:sqrtpi, acos!*,
        asin!*, atan!*, cos!*, e!*,
        exp!*, exp!:, get!:const, log!*, log!:, pi!*,
        sin!*, sqrt!:, tan!*;

imports !*q2f, abs!:, bflerrmsg, bfp!:, bfzerop!:, conv!:bf2i,
        conv!:mt, cut!:ep, cut!:mt, decimal2internal, difference!:,
        divide!:, ep!:, equal!:, geq, greaterp!:, i2bf!:, leq, lessp!:,
        lshift, make!:ibf, minus!:, minusp!:, mksq, mt!:, multd, neq,
        numr, order!:, plus!:, preci!:, quotient!:, round!:mt, simp,
        texpt!:, texpt!:any, times!:;


fluid '(!:prec!: !:bprec!: !!scls !!sclc);

global '(bfsaveprec!*);

global '(bfz!* bfhalf!* bfone!* bftwo!* bfthree!* bffive!* bften!*
         !:bf!-0!.0625 !:bf!-0!.25 !:bf0!.419921875);

% *** Tables for Elementary Function and Constant Values ***

symbolic procedure allfixp l;
   % Returns T if all of L are FIXP.
   null l or fixp car l and allfixp cdr l;

symbolic procedure read!:lnum(l);
% This function reads a long number "n" represented by a list in a way
% described below, and constructs a BIG-FLOAT representation of "n".
% L is a list of integers, the first element of which gives the order of
% "n" and all the next elements when concatenated give the mantissa of
% "n".
% **** ORDER(n)=k if 10**k <= ABS(n) < 10**(k+1).
% **** Except for the first element, all integers in L
% ****      should not begin with "0" because some
% ****      systems suppress leading zeros.
% JBM: Fix some kludgy coding here.
% JBM: Add BFSAVEPREC!* precision saver.
if not allfixp l then bflerrmsg 'read!:lnum
 else begin scalar mt, ep, k, sign, u, v, dcnt;
          mt := dcnt := 0;      %JBM
%          ep := car(u := l) + 1;   %JBM
          u := l;
          ep := add1 car u;
          sign := if minusp cadr l then -1 else 1;   %JBM
          while u:=cdr u do
            << k := length explode(v := abs car u);  %JBM
%               k := 0;  %JBM
%               while v do << k := k + 1; v := cdr v >>;  %JBM
               mt := mt * 10**k + v; %JBM
               ep := ep - k;
               dcnt := dcnt +  k;    % JBM
               if bfsaveprec!* and dcnt > bfsaveprec!* then  %JBM
                  u := '(nil) >>;     %JBM
          return decimal2internal (sign * mt, ep)
                   where !:bprec!: := msd!: mt;
    end;


%symbolic procedure bfexpt!:(u,v);
%   % Calculates u**v, including case u<0.
%   if minusp!: u
%     then multd(texpt!:any(minus!: u,v),
%                !*q2f if null numr simp list('difference,v,
%                                             '(quotient 1 2))
%                        then simp 'i
%                       else mksq(list('expt,'(minus 1),v),1))
%    else texpt!:any(u,v);

symbolic procedure exp!* u; exp!:(u,!:bprec!:);

symbolic procedure log!* u; log!:(u,!:bprec!:);

symbolic procedure sin!* u; sin!:(u,!:bprec!:);

symbolic procedure cos!* u; cos!:(u,!:bprec!:);

symbolic procedure tan!* u; tan!:(u,!:bprec!:);

symbolic procedure asin!* u; asin!:(u,!:bprec!:);

symbolic procedure acos!* u; acos!:(u,!:bprec!:);

symbolic procedure atan!* u; atan!:(u,!:bprec!:);

symbolic procedure sqrt!* u; sqrt!:(u,!:bprec!:);

symbolic procedure pi!*;
   if !:prec!:>1000 then !:bigpi !:bprec!: else !:pi !:bprec!:;

symbolic procedure e!*; !:e !:bprec!:;


%*************************************************************
%**                                                         **
%** 3-1. Elementary CONSTANTS.                              **
%**                                                         **
%*************************************************************

symbolic procedure !:pi k;
% This function calculates the value of the circular
%      constant "PI", with the precision K, by
%      using Machin's well known identity:
%         PI = 16*atan(1/5) - 4*atan(1/239).
%      Calculation is performed mainly on integers.
% K is a positive integer.
if not fixp k or k <= 0 then bflerrmsg '!:pi
 else
    begin integer k3,s,ss,m,n,x,test;  scalar u;
          u := get!:const('!:pi, k);
          if u neq "NOT FOUND" then return u;
          ss := n := 2 ** (k3 := k + 3) / 5;
          x := -5 ** 2;
          m := 1;
          while n neq 0 do <<n := n/x; ss := ss + n/(m := m + 2)>>;
          s := n := 2 ** k3 / 239;
          x := -239 ** 2;
          m := 1;
          while n neq 0 do << n := n / x; s := s + n / (m := m + 2) >>;
          u := round!:mt(make!:ibf(test := 16 * ss - 4 * s, - k3), k);
          save!:const('!:pi, u);
          return u;
    end;

symbolic procedure !:bigpi k;
% This function calculates the value of the circular
%      constant "PI", with the binary precision K, by the
%      arithmetic-geometric mean method.  (See,
%      R. Brent, JACM Vol.23, #2, pp.242-251(1976).)
% K is a positive integer.
% **** This function should be used only when you
% ****      need "PI" of precision higher than 1000.
if not fixp k or k <= 0 then bflerrmsg '!:bigpi
 else begin integer k7, n;  scalar dcut, half, x, y, u, v;
          u := get!:const('!:pi, k);
          if u neq "NOT FOUND" then return u;
          k7 := k + 7;
          half := bfhalf!*;    %JBM
          dcut := make!:ibf(2, - k7);
          n := 1;
          x := bfone!*;
          y := divide!:(x, !:sqrt2 k7, k7);
          u := !:bf!-0!.25;    %JBM
          while greaterp!:(abs!: difference!:(x, y), dcut) do
            << v := x;
               x := times!:(plus!:(x, y), half);
               y := sqrt!:(cut!:ep(times!:(y, v), - k7), k7);
               v := difference!:(x, v);
               v := times!:(times!:(v, v),i2bf!: n);
               u := difference!:(u, cut!:ep(v, - k7));
               n := 2*n>> ;
          v := cut!:mt(texpt!:(plus!:(x, y), 2), k7);
          u := divide!:(v, times!:(i2bf!: 4, u), k);
          save!:const('!:pi, u);
          return u;
    end;

symbolic procedure !:e k;
% This function calculates the value of "e", the base
%      of the natural logarithm, with the binary precision K,
%      by summing the Taylor series for exp(x=1).
%      Calculation is performed mainly on integers.
% K is a positive integer.
if not fixp k or k <= 0 then bflerrmsg '!:e
 else begin integer k7, ans, m, n;  scalar u;
          u := get!:const('!:e, k);
          if u neq "NOT FOUND" then return u;
          k7 := k + 7;
          m := 1;
          n := lshift (1, k7); % 2**k7
          ans := 0;
          while n neq 0  do ans := ans + (n := n / (m := m + 1));
          ans := ans + lshift (1, k7 + 1); % 2 * 2**k7
          u := round!:mt(make!:ibf(ans, - k7), k);
          save!:const('!:e2, u);
          return u;
       end;

symbolic procedure !:e0625(k);
% This function calculates exp(0.0625), the value of the
%      exponential function at the point 0.0625, with
%      the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:e0625, k);
  if u neq "NOT FOUND" then return u;
  u := exp!:(!:bf!-0!.0625, k);    %JBM
  save!:const('!:e0625, u);
  return u;
end;

symbolic procedure !:log2 k;
% This function calculates log(2), the natural
%      logarithm of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log2, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(bftwo!*, k);
  save!:const('!:log2, u);
  return u;
end;

symbolic procedure !:log3 k;
% This function calculates log(3), the natural
%      logarithm of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log3, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(bfthree!*, k);
  save!:const('!:log3, u);
  return u;
end;

symbolic procedure !:log5 k;
% This function calculates log(5), the natural
%      logarithm of 5, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log5, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(bffive!*, k);
  save!:const('!:log5, u);
  return u;
end;

symbolic procedure !:log10 k;
% This function calculates log(10), the natural
%      logarithm of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log10,  k);
  if u neq "NOT FOUND" then return u;
  u := log!:(bften!*, k);
  save!:const('!:log10, u);
  return u;
end;

symbolic procedure !:logpi k;
% This function calculates log(PI), the natural
%      logarithm of "PI", with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:logpi, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(!:pi(k + 2), k);
  save!:const('!:logpi, u);
  return u
end;

symbolic procedure !:sqrt2(k);
% This function calculates SQRT(2), the square root
%      of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt2, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(bftwo!*, k);
  save!:const('!:sqrt2, u);
  return u;
end;

symbolic procedure !:sqrt3(k);
% This function calculates SQRT(3), the square root
%      of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u:=get!:const('!:sqrt3, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(bfthree!*, k);
  save!:const('!:sqrt3, u);
  return u;
end;

symbolic procedure !:sqrt5 k;
% This function calculates SQRT(5), the square root
%      of 5, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt5, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(bffive!*, k);
  save!:const('!:sqrt5, u);
  return u;
end;

symbolic procedure !:sqrt10 k;
% This function calculates SQRT(10), the square root
%      of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt10, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(bften!*, k);
  save!:const('!:sqrt10, u);
  return u;
end;

symbolic procedure !:sqrtpi k;
% This function calculates SQRT(PI), the square root
%      of "PI", with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrtpi, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(!:pi(k + 2), k);
  save!:const('!:sqrtpi, u);
  return u;
end;

symbolic procedure !:sqrte k;
% This function calculates SQRT(e), the square root
%      of "e", with the precision K.
% K is a positive integer.
begin scalar u;
  u:=get!:const('!:sqrte, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(!:e(k + 2), k);
  save!:const('!:sqrte, u);
  return u;
end;

symbolic procedure !:cbrt2 k;
% This function calculates CBRT(2), the cube root
%      of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt2, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(bftwo!*, k);
  save!:const('!:cbrt2, u);
  return u;
end;

symbolic procedure !:cbrt3 k;
% This function calculates CBRT(3), the cube root
%      of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt3, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(bfthree!*, k);
  save!:const('!:cbrt3, u);
  return u;
end;

symbolic procedure !:cbrt5 k;
% This function calculates CBRT(5), the cube root
%    of 5, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt5, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(bffive!*, k);
  save!:const('!:cbrt5, u);
  return u;
end;

symbolic procedure !:cbrt10 k;
% This function calculates CBRT(10), the cube root
%      of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt10, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(bften!*, k);
  save!:const('!:cbrt10, u);
  return u;
end;

symbolic procedure !:cbrtpi k;
% This function calculates CBRT(PI), the cube root
%      of "PI", with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrtpi, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(!:pi(k + 2), k);
  save!:const('!:cbrtpi, u);
  return u;
end;

symbolic procedure !:cbrte k;
% This function calculates CBRT(e), the cube root
%      of "e", with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrte, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(!:e(k + 2), k);
  save!:const('!:cbrte, u);
  return u;
end;

%*************************************************************
%**                                                         **
%** 3-2. Routines for saving CONSTANTS.                     **
%**                                                         **
%*************************************************************

symbolic procedure get!:const(cnst, k);
% This function returns the value of constant CNST
%      of the precision K, if it was calculated
%      previously with, at least, the precision K,
%      else it returns "NOT FOUND".
% CNST is the name of the constant (to be quoted).
% K is a positive integer.
  if atom cnst and fixp k and k > 0 then
    begin scalar u;
          u := get(cnst, 'save!:c);
          if null u or car u < k then return "NOT FOUND"
           else if car u = k then return cdr u
                             else return round!:mt(cdr u, k);
    end
   else bflerrmsg 'get!:const$

symbolic procedure save!:const(cnst, nmbr);
% This function saves the value of constant CNST
%      for the later use.
% CNST is the name of the constant (to be quoted).
% NMBR is a BIG-FLOAT representation of the value.
  if atom cnst and bfp!: nmbr then
       put(cnst, 'save!:c, preci!: nmbr . nmbr)
   else bflerrmsg 'save!:const$

symbolic procedure set!:const(cnst, l);
% This function sets the value of constant CNST.
% CNST is the name of the constant (to be quoted).
% L is a list of integers, which represents the
%      value of the constant in the way described
%      in the function READ!:LNUM.
     save!:const(cnst, read!:lnum l)$


% Setting the constants.

set!:const( '!:pi    , '( 0   3141 59265 35897 93238 46264
     33832 79502 88419 71693 99375 105820 9749 44592 30781
     64062 86208 99862 80348 25342 11706 79821 48086 51328
     23066 47093 84460 95505 82231 72535 94081 28481 1174
    5028410 2701 93852 11055 59644 62294 89549 30381 96442
     88109 8) )$

set!:const( '!:e     , '( 0   2718 28182 84590 45235 36028
     74713 52662 49775 72470 93699 95957 49669 67627 72407
     66303 53547 59457 13821 78525 16642 74274 66391 93200
     30599 21817 41359 66290 43572 90033 42952 60595 63073
     81323 28627 943490 7632 33829 88075 31952 510190 1157
     38341 9) )$

set!:const( '!:e0625   , '( 0 1064 49445 89178 59429 563390
      5946 42889 673100 7254 43649 35330 151930 7510 63556
     39368 2816600 633 42934 35506 87662 43755 1) );

set!:const( '!:log2  , '(-1   6931 47180 55994 53094 17232
     12145 81765 68075 50013 43602 55254 1206 800094 93393
     62196 96947 15605 86332 69964 18687 54200 2) )$

set!:const( '!:log3  , '( 0   1098 61228 866810 9691 39524
     52369 22525 70464 74905 57822 74945 17346 94333 63749
     42932 18608 96687 36157 54813 73208 87879 7) )$

set!:const( '!:log5  , '( 0   1609 43791 2434100 374 60075
     93332 26187 63952 56013 54268 51772 19126 47891 47417
     898770 7657 764630 1338 78093 179610 7999 7) )$

set!:const( '!:log10 , '( 0   2302 58509 29940 456840 1799
     14546 84364 20760 11014 88628 77297 60333 27900 96757
     26096 77352 48023 599720 5089 59829 83419 7) )$

set!:const( '!:logpi , '( 0   1144 72988 5849400 174 14342
     73513 53058 71164 72948 12915 31157 15136 23071 47213
     77698 848260 7978 36232 70275 48970 77020 1) )$

set!:const( '!:sqrt2 , '( 0   1414 21356 23730 95048 80168
     872420 96980 7856 96718 75376 94807 31766 79737 99073
     24784 621070 38850 3875 34327 64157 27350 1) )$

set!:const( '!:sqrt3 , '( 0   17320 5080 75688 77293 52744
     634150 5872 36694 28052 53810 38062 805580 6979 45193
     301690 88000 3708 11461 86757 24857 56756 3) )$

set!:const( '!:sqrt5 , '( 0   22360 6797 74997 89696 40917
     36687 31276 235440 6183 59611 52572 42708 97245 4105
    209256 37804 89941 441440 8378 78227 49695 1) )$

set!:const( '!:sqrt10, '( 0   3162 277660 1683 79331 99889
     35444 32718 53371 95551 39325 21682 685750 4852 79259
     44386 39238 22134 424810 8379 30029 51873 47))$

set!:const( '!:sqrtpi, '( 0   1772 453850 9055 16027 29816
     74833 41145 18279 75494 56122 38712 821380 7789 85291
     12845 91032 18137 49506 56738 54466 54162 3) )$

set!:const( '!:sqrte , '( 0   1648 721270 7001 28146 8486
    507878 14163 57165 3776100 710 14801 15750 79311 64066
     10211 94215 60863 27765 20056 36664 30028 7) )$

set!:const( '!:cbrt2 , '( 0   1259 92104 98948 73164 7672
    106072 78228 350570 2514 64701 5079800 819 75112 15529
     96765 13959 48372 93965 62436 25509 41543 1) )$

set!:const( '!:cbrt3 , '( 0   1442 249570 30740 8382 32163
     83107 80109 58839 18692 53499 35057 75464 16194 54168
     75968 29997 33985 47554 79705 64525 66868 4) )$

set!:const( '!:cbrt5 , '( 0   1709 97594 66766 96989 35310
     88725 43860 10986 80551 105430 5492 43828 61707 44429
     592050 4173 21625 71870 10020 18900 220450 ) )$

set!:const( '!:cbrt10, '( 0   2154 4346900 318 83721 75929
     35665 19350 49525 93449 42192 10858 24892 35506 34641
     11066 48340 80018 544150 3543 24327 61012 6) )$

set!:const( '!:cbrtpi, '( 0   1464 59188 75615 232630 2014
     25272 63790 39173 85968 55627 93717 43572 55937 13839
     36497 98286 26614 56820 67820 353820 89750 ) )$

set!:const( '!:cbrte , '( 0   1395 61242 50860 89528 62812
     531960 2586 83759 79065 15199 40698 26175 167060 3173
     90156 45951 84696 97888 17295 83022 41352 1) )$


%*************************************************************
%**                                                         **
%** 4-1. Elementary FUNCTIONS.                              **
%**                                                         **
%*************************************************************

symbolic procedure sqrt!:(x, k);
% This function calculates SQRT(x), the square root
%      of "x", with the binary precision K, by Newton's
%      iteration method.
% X is a BIG-FLOAT representation of "x", x >= 0.
% K is a positive integer.
  if minusp!: x or not fixp k or k <= 0 then bflerrmsg 'sqrt!:
    else if bfzerop!: x then bfz!*
    else begin integer k7,ncut,nfig;  scalar dcut,half,dy,y,y0,u;
          k7 := k + 7;
          ncut := k7 - (order!: x + 1) / 2;
          half := bfhalf!*;    %JBM
          dcut := make!:ibf(2, - ncut);
          dy := make!:ibf(4, - ncut);
          %y0 := incprec!:(x,1);
          y0 := conv!:mt(x, 2);
          if remainder(ep!: y0, 2) = 0 then
                y0 := make!:ibf((2 + 3 * mt!: y0)/5,  ep!: y0/2)
           else y0 := make!:ibf((9 + 5 * mt!: y0)/10, (ep!: y0 - 1)/2);
          nfig := 1;
          while nfig < k7 or greaterp!:(abs!: dy, dcut) do
            << if (nfig := 2 * nfig) > k7 then nfig := k7;
               u := divide!:(x, y0, nfig);
               y := times!:(plus!:(y0, u), half);
               dy := difference!:(y, y0);
               y0 := y >>;
          return round!:mt(y, k);
    end;


symbolic procedure cbrt!:(x, k);
% This function calculates CBRT(x), the cube root
%      of "x", with the binary precision K, by Newton's
%      iteration method.
% X is a BIG-FLOAT representation of any real "x".
% K is a positive integer.
   if not fixp k or k <= 0 then bflerrmsg 'cbrt!:
   else if bfzerop!: x then bfz!*
   else if minusp!: x then minus!: cbrt!:(minus!: x, k)
   else begin integer k7, ncut, nfig, j;  scalar dcut, thre, dy, y, u;
          k7 := k + 7;
          ncut := k7 - (order!: x + 2) / 3;
          thre := bfthree!*;
          dcut := make!:ibf(2, - ncut);
          dy := make!:ibf(4, - ncut);
          y := conv!:mt(x, 3);
          if (j := remainder(ep!: y, 3)) = 0 then
               y := make!:ibf((12 + mt!: y ) / 10, ep!: y / 3)
           else if j = 1 or j = -2 then
                y := make!:ibf((17 + 4 * mt!: y)/16, (ep!: y - 1)/3)
           else y := make!:ibf((15 + 4 * mt!: y)/12, (ep!: y - 2)/3);
          nfig := 1;
          while nfig < k7 or greaterp!:(abs!: dy, dcut) do
            << if (nfig := 2 * nfig) > k7 then nfig := k7;
               u := cut!:mt(times!:(y, y), nfig);
               u := divide!:(x, u, nfig);
               j := order!:(u := difference!:(u, y)) + ncut - k7;
               dy := divide!:(u, thre, max(1, nfig + j));
               y := plus!:(y, dy) >>;
          return round!:mt(y, k);
    end;


symbolic procedure exp!:(x, k);
% This function calculates exp(x), the value of
%      the exponential function at the point "x",
%      with the binary precision K, by summing terms of
%      the Taylor series for exp(z), 0 < z < 1.
% X is a BINARY BIG-FLOAT representation of any real "x".
% K is a positive integer.
   if not fixp k or k <= 0 then bflerrmsg 'exp!:
   else if bfzerop!: x then bfone!*
   else begin integer k7, m;  scalar q, r, y, yq, yr;
          q := i2bf!:(m := conv!:bf2i(y := abs!: x));
          r := difference!:(y, q);
          k7 := k + msd!: m + 7;
          r := difference!:(y, q);
          if bfzerop!: q then yq := bfone!*
           else (yq := texpt!:(!:e k7, m) where !:bprec!: := k7);
          if bfzerop!: r then yr:=bfone!*
           else begin integer j, n;  scalar dcut, fctrial, ri, tm;
              dcut := make!:ibf(2, - k7);
              yr := ri := tm := bfone!*;
              m := 1;
              j := 0;
              while greaterp!:(tm, dcut) do
                << fctrial := i2bf!:(m := m * (j := j + 1));
                   ri := cut!:ep(times!:(ri, r), - k7);
                   n := max(1, k7 - order!: fctrial + order!: ri);
                   tm := divide!:(ri, fctrial, n);
                   yr := plus!:(yr,tm);
                   if remainder(j,10)=0 then yr := cut!:ep(yr, - k7) >>;
        end;
          y := cut!:mt(times!:(yq, yr), k + 1);
          return (if minusp!: x then divide!:(bfone!*, y, k)
                  else round!:mt (y,k));
    end;


symbolic procedure log!:(x, k);
% This function calculates log(x), the value of the
%      logarithmic function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for log(1+z), 0 < z < 0.10518.
% X is a BIG-FLOAT representation of "x", x > 0.
% K is a positive integer.
   if minusp!: x or bfzerop!: x or
     not fixp k or k <= 0 then bflerrmsg 'log!:
   else if equal!:(x,bfone!*) then bfz!*
   else begin integer k7,m;  scalar eee,es,sign,l,y,z;
          k7 := k + 7;
          eee := !:e k7;
          es := !:e0625 k7;
          if greaterp!:(x, bfone!*) then << sign := bfone!*; y := x >>
           else <<sign := minus!: bfone!*;
                  y := divide!:(bfone!*, x, k7)>>;
          if lessp!:(y, eee) then << m := 0; z := y >>
           else << if (m := (order!: y * 69) / 100) = 0 then z := y
                    else (z := divide!:(y, texpt!:(eee, m), k7)
                             where !:bprec!: := k7);
                    while greaterp!:(z, eee) do
                       << m := m+1; z := divide!:(z, eee, k7) >> >>;
          l := i2bf!: m;
          y := !:bf!-0!.0625;
          while greaterp!:(z, es) do
            << l := plus!:(l, y); z := divide!:(z, es, k7) >>;
          z := difference!:(z, bfone!*);
        begin integer n;  scalar dcut, tm, zi;
              y := tm := zi := z;
              z := minus!: z;
              dcut := make!:ibf(2, - k7);
              m := 1;
              while greaterp!:(abs!: tm, dcut) do
               << zi := cut!:ep(times!:(zi, z), - k7);
                  n := max(1, k7 + order!: zi);
                  tm := divide!:(zi,i2bf!:(m := m + 1), n);
                  y := plus!:(y, tm);
                  if zerop remainder(m,10) then y := cut!:ep(y,-k7)>>;
        end;
          y := plus!:(y, l);
          return round!:mt(times!:(sign, y), k);
    end;


symbolic procedure sin!:(x, k);
% This function calculates sin(x), the value of
%      the sine function at the point "x", with
%      the binary precision K, by summing terms of the
%      Taylor series for sin(z), 0 < z < PI/4.
% X is a BIG-FLOAT representation of any real "x".
% K is a positive integer.  (revised SLK)                         %<===
   if not fixp k or k <= 0 then bflerrmsg 'sin!:
   else if bfzerop!: x then bfz!*
   else if minusp!: x then minus!: sin!:(minus!: x, k)
   else begin integer k7, m;  scalar pi4, sign, q, r, y, !!scls;  %<===
           k7 := k + 7;
          m := preci!: x;
          pi4 := times!:(!:pi(k7 + m), !:bf!-0!.25);
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          sign := bfone!*;
          if m >= 8 then m := remainder(m, 8);
          if m >= 4 then << sign := minus!: sign; m := m - 4>>;
          if m = 0 then <<!!scls := x; go to sn>>                  %<===
           else if onep m then go to m1
           else if m = 2 then go to m2
           else go to m3;;
      m1: r := cut!:mt(difference!:(pi4, r), k7);
          return times!:(sign, cos!:(r, k));
      m2: r := cut!:mt(r, k7);
          return times!:(sign, cos!:(r, k));
      m3: r := cut!:mt(difference!:(pi4, r), k7); !!scls := x;     %<===
    sn: x := if !!sclc then !!sclc else !!scls;                    %<===
        if x and lessp!:(r,times!:(x,make!:ibf(1, 3 - k)))         %<===
          then return bfz!* else                                   %<===
        begin integer j, n, ncut;  scalar dcut, fctrial, ri, tm;
              ncut := k7 - min(0, order!: r + 1);
              dcut := make!:ibf(2, - ncut);
              y := ri := tm := r;
              r := minus!: cut!:ep(times!:(r, r), - ncut);
              m := j := 1;
              while greaterp!:(abs!: tm, dcut) do
               << j := j + 2;
                  fctrial := i2bf!:(m := m*j*(j - 1));
                  ri := cut!:ep(times!:(ri, r), - ncut);
                  n := max(1,k7 - order!: fctrial + order!: ri);
                  tm := divide!:(ri, fctrial, n);
                  y := plus!:(y, tm);
                  if zerop remainder(j,20) then y := cut!:ep(y,-ncut)>>;
        end;
          return round!:mt(times!:(sign, y), k);
    end;

symbolic procedure cos!:(x, k);
% This function calculates cos(x), the value of
%      the cosine function at the point "x", with
%      the binary precision K, by summing terms of the
%      Taylor series for cos(z), 0 < z < PI/4.
% X is a BIG-FLOAT representation of any real "x".
% K is a positive integer.  (revised SLK)                          %<===
   if not fixp k or k <= 0 then bflerrmsg 'cos!:
    else if bfzerop!: x then bfone!*
    else if minusp!: x then cos!:(minus!: x, k)
    else begin integer k7, m;  scalar pi4, sign, q, r, y, !!sclc;  %<===
          k7 := k + 7;
          m := preci!: x;
          pi4 := times!:(!:pi(k7 + m), !:bf!-0!.25);
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          sign := bfone!*;
          if m >= 8 then m := remainder(m, 8);
          if m >= 4 then << sign := minus!: sign; m := m - 4 >>;
          if m >= 2 then sign := minus!: sign;
          if m = 0 then go to cs
           else if m = 1 then go to m1
           else if m = 2 then go to m2
           else go to m3;
      m1: r := cut!:mt(difference!:(pi4, r), k7); !!sclc := x;     %<===
          return times!:(sign, sin!:(r, k));
      m2: r := cut!:mt(r, k7); !!sclc := x;                        %<===
          return times!:(sign, sin!:(r, k));
      m3: r := cut!:mt(difference!:(pi4, r), k7);
    cs: begin integer j, n;  scalar dcut, fctrial, ri, tm;
              dcut := make!:ibf(2, - k7);
              y := ri := tm := bfone!*;
              r := minus!: cut!:ep(times!:(r, r), - k7);
              m := 1;
              j := 0;
              while greaterp!:(abs!: tm, dcut) do
               << j := j + 2;
                  fctrial := i2bf!:(m := m * j * (j - 1));
                  ri := cut!:ep(times!:(ri, r), - k7);
                  n := max(1, k7 - order!: fctrial + order!: ri);
                  tm := divide!:(ri, fctrial, n);
                  y := plus!:(y, tm);
                  if zerop remainder(j,20) then y := cut!:ep(y,-k7)>>;
        end;
          return round!:mt(times!:(sign, y), k);
    end;

symbolic procedure tan!:(x, k);
% This function calculates tan(x), the value of
%      the tangent function at the point "x",
%      with the binary precision K, by calculating
%         sin(x)  or  cos(x) = sin(PI/2-x).
% X is a BIG-FLOAT representation of any real "x",
% K is a positive integer.
   if not fixp k or k <= 0 then bflerrmsg 'tan!:
   else if bfzerop!: x then bfz!*
   else if minusp!: x then minus!: tan!:(minus!: x, k)
   else begin integer k7, m;  scalar pi4, sign, q, r;
          k7 := k + 7;
          m := preci!: x;
          pi4 := times!:(!:pi(k7 + m), !:bf!-0!.25);
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          if m >= 4 then m := remainder(m, 4);
          if m >= 2 then sign := minus!: bfone!* else sign := bfone!*;
          if m = 1 or m = 3 then r := difference!:(pi4, r);
          r := cut!:mt(r, k7);
          if m = 0 or m = 3 then go to m03 else go to m12;
     m03: r := sin!:(r, k7);
          q := difference!:(bfone!*, times!:(r, r));
          q := sqrt!:(cut!:mt(q, k7), k7);
          return times!:(sign, divide!:(r, q, k));
     m12: r := sin!:(r, k7);
          q := difference!:(bfone!*, times!:(r, r));
          q := sqrt!:(cut!:mt(q, k7), k7);
          return times!:(sign, divide!:(q, r, k));
    end;

symbolic procedure asin!:(x, k);
% This function calculates asin(x), the value of
%      the arcsine function at the point "x",
%      with the binary precision K, by calculating
%         atan(x/SQRT(1-x**2))  by ATAN!:.
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of "x", IxI <= 1;
% K is a positive integer.
   if greaterp!:(abs!: x, bfone!*) or
     not fixp k or k <= 0 then bflerrmsg 'asin!:
   else if minusp!: x then minus!: asin!:(minus!: x, k)
   else begin integer k7;  scalar y;
          k7 := k + 7;
          if lessp!:(difference!:(bfone!*, x), make!:ibf(2, - k7))
            then return round!:mt(times!:(!:pi add1 k,bfhalf!*),k);
                 %JBM
          y := cut!:mt(difference!:(bfone!*, times!:(x, x)), k7);
          y := divide!:(x, sqrt!:(y, k7), k7);
          return atan!:(y, k);
    end;

symbolic procedure acos!:(x, k);
% This function calculates acos(x), the value of
%      the arccosine function at the point "x",
%      with the precision K, by calculating
%         atan(SQRT(1-x**2)/x)  if  x > 0  or
%         atan(SQRT(1-x**2)/x) + PI  if  x < 0.
%      The answer is in the range [0 , PI].
% X is a BIG-FLOAT representation of "x", IxI <= 1.
% K is a positive integer.
   if greaterp!:(abs!: x, bfone!*) or
     not fixp k or k <= 0 then bflerrmsg 'acos!:
   else begin integer k7;  scalar y;
          k7 := k + 7;
          if lessp!:(abs!: x, make!:ibf(2, - k7))  %%%%% 5 * base = 5*2
           then return round!:mt(times!:(!:pi add1 k,bfhalf!*),k);
                %JBM
          y := difference!:(bfone!*, times!:(x, x));
          y := cut!:mt(y, k7);
          y := divide!:(sqrt!:(y, k7), abs!: x, k7);
          return (if minusp!: x then
                   round!:mt(difference!:(!:pi(k + 1), atan!:(y, k)), k)
                  else atan!:(y, k) );
    end;

symbolic procedure atan!:(x, k);
% This function calculates atan(x), the value of the
%      arctangent function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for atan(z)  if  0 < z < 0.419921875.
%      Otherwise the following identities are used:
%         atan(x) = PI/2 - atan(1/x)  if  1 < x  and
%         atan(x) = 2*atan(x/(1+SQRT(1+x**2)))
%            if  0.419921875 <= x <= 1.
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of any real "x".
% K is a positive integer.
   if not fixp k or k <= 0 then bflerrmsg 'atan!:
   else if bfzerop!: x then bfz!*
   else if minusp!: x then minus!: atan!:(minus!: x, k)
   else begin integer k7;  scalar pi4, y, z;
          k7 := k + 7;
          pi4 := times!:(!:pi k7, !:bf!-0!.25);    %JBM
          if equal!:(x, bfone!*) then return round!:mt(pi4, k);
          if greaterp!:(x, bfone!*) then return
           round!:mt(difference!:(plus!:(pi4, pi4),
                               atan!:(divide!:(bfone!*,x,k7),k + 1)),k);
          if lessp!:(x, !:bf0!.419921875) then go to at;
          y := plus!:(bfone!*, cut!:mt(times!:(x, x), k7));
          y := plus!:(bfone!*, sqrt!:(y, k7));
          y := atan!:(divide!:(x, y, k7), k + 1);
          return round!:mt(times!:(y, bftwo!*), k);
    at: begin integer m, n, ncut;  scalar dcut, tm, zi;
              ncut := k7 - min(0, order!: x + 1);
              y := tm := zi := x;
              z := minus!: cut!:ep(times!:(x, x), - ncut);
              dcut := make!:ibf(2, - ncut);
              m := 1;
              while greaterp!:(abs!: tm, dcut) do
               << zi := cut!:ep(times!:(zi, z), - ncut);
                  n := max(1, k7 + order!: zi);
                  tm := divide!:(zi, i2bf!:(m := m + 2), n);
                  y := plus!:(y, tm);
                  if zerop remainder(m,20) then y := cut!:ep(y,-ncut)>>;
        end;
          return round!:mt(y, k)
    end;

endmodule;


end;
