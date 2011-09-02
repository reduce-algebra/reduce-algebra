module bfloat; % Routines for arbitrary precision real arithmetic.

% Author: T. Sasaki, 1979.

% Modifications by: Anthony C. Hearn (interface to algebraic mode)
%                   Jed B. Marti (general cleanup)

global '(bfsaveprec!* !*nat !:prec!: domainlist!*);

% BFSAVEPREC!* is precision at which to save constants. If NIL, use
% !:PREC!: otherwise use value of this global (usually set in REND).

% Constants for use during this package. These are set at the
% end of this package.

global '(!:bf!-pi         %PI to 20 digits.
         !:bf!-0          %0.0
         !:bf!-1          %1.0
         !:bf!-e          %E to 20 digits
         !:bf!-0!.5       %0.5
         !:bf!-0!.25      %0.25
         !:bf!-0!.1       %0.1
         !:bf!-1!.72      %1.72
         !:bf!-0!.42      %0.42
         !:bf!-0!.72      %0.72
        );

switch bigfloat;

comment *** Tables for Bigfloats ***;

domainlist!* := union('(!:bf!:),domainlist!*);
put('bigfloat,'tag,'!:bf!:);
put('!:bf!:,'dname,'bigfloat);
flag('(!:bf!:),'field);
put('!:bf!:,'i2d,'i2bf!:);
put('!:ft!:,'!:bf!:,'!*ft2bf);
put('!:rn!:,'!:bf!:,'!*rn2bf);
put('!:bf!:,'minusp,'minusp!:);
put('!:bf!:,'plus,'bfplus!:);
put('!:bf!:,'times,'ttimes!:);
put('!:bf!:,'difference,'tdifference!:);
put('!:bf!:,'quotient,'bfquotient!:);
put('!:bf!:,'zerop,'bfzerop!:);
put('!:bf!:,'onep,'bfonep!:);
put('!:bf!:,'prepfn,'bfprep!:);
put('!:bf!:,'prifn,'bfprin!:);
put('!:bf!:,'cmpxtype,list '!:gbf!:);

comment SMACROS needed;

symbolic smacro procedure mt!:(nmbr);
 % This function selects the mantissa of a number "n".
 % NMBR is a BIG-FLOAT representation of "n".
          cadr nmbr;


symbolic smacro procedure ep!:(nmbr);
 % This function selects the exponent of a number "n".
 % NMBR is a BIG-FLOAT representation of "n".
          cddr nmbr;


symbolic procedure i2bf!: u; '!:bf!: . u . 0;

symbolic procedure !*rn2bf u;
   begin scalar x;
      x := get('!:bf!:,'i2d);
      return apply2(get('!:bf!:,'quotient),
                    apply(x,list cadr u),apply(x,list cddr u))
   end;

symbolic procedure !*ft2bf u; conv!:a2bf cdr u;

symbolic procedure bfplus!:(u,v);
   % Value is sum of U and V, or tagged bigfloat zero if outside
   % precision.
   begin scalar x,y;
      x := tplus!:(u,v);
      y := '!:bf!: . abs mt!: x . (ep!: x+!:prec!:-1);
      return if lessp!:(y,abs!: u) and lessp!:(y,abs!: v)
               then '!:bf!: . (0 . ep!: x)
              else x
   end;

symbolic procedure bfquotient!:(u,v); divide!:(u,v,!:prec!:);

symbolic procedure bfzerop!: u;
   % This is possibly too restricted a definition.
   mt!: u = 0;

symbolic procedure bfonep!: u;
   % allow for roundup of four in the last place.
   begin scalar x,y;
      y := ep!: u + !:prec!:;
      if not(y=0 or y=1) then return;
      x := mt!: u*10**y - 10**!:prec!:;
      return (x<=0 and x>=-4)
   end;

symbolic procedure bfprep!: u; u;

symbolic procedure bfprin!: u;
   % Print tagged bigfloat U.
   bfprin cdr u;

symbolic procedure bfprin nmbr;
   %prints a big-float in a variety of formats. Still needs work
   %for fortran output;
    begin integer j,k;  scalar u,v;
 nmbr := round!:mt('!:bf!: . nmbr,!:prec!:-2);
 if bfzerop!:(nmbr) then return prin2!* '!0;
 u := explode abs(j := mt!: nmbr);
 k := ep!: nmbr;
 if k>=0 then if k>5 then go to etype
  else <<v := list('!.,'!0);
         while (k := k-1)>=0 do v := '!0 . v;
         u := nconc(u,v)>>
  else if (k := order!:(nmbr)+1)>0 
   then <<v := u;
   while (k := k-1)>0 do v := cdr v;
   rplacd(v,'!. . cdr v)>>
  else if k<-10 then go to etype
  else <<while (k := k+1)<=0 do u := '!0 . u;
  u := '!0 . '!. . u>>;
 bfprin1(u,j);
 return nmbr;
   etype:
 if null( cdr(u)) then rplacd(u , list('!0));
 u:= car u . '!. . cdr u;
 j := bfprin1(u,j);
 if j=0 then <<prin2!*("E "  ); j:=2>> else
 if j=1 then <<prin2!*(" E " ); j:=4>> else
 if j=2 then <<prin2!*(" E  "); j:=0>> else
 if j=3 then <<prin2!*(" E " ); j:=0>> else
 if j=4 then <<prin2!*("  E "); j:=2>>;
 u:=explode( k:=order!:(nmbr));
 if k>=0 then u:=cons('!+,u);
 while u do <<prin2!*( car(u)); u:=cdr(u); j:=j+1;
     if j=5 then <<prin2!*(" "); j:=0>> >>;
 return nmbr
    end;

symbolic procedure bfprin1(u,j);
   begin scalar v,w;
 if j<0 then u := '!- . u;
 %suppress trailing zeros;
 v := u;
 while not(car v eq '!.) do v := cdr v;
 v := cdr v;
    l: while cdr v and not(cadr v eq '!0) do v := cdr v;
 w := cdr v;
        while w and car w eq '!0 do w := cdr w;
 if null w then rplacd(v,nil) else <<v := w; go to l>>;
 %now print the number;
 j := 0;
 for each char in u do <<prin2!* char; j := j+1;
    if j=5 then <<if !*nat then prin2!* '! ;
           j := 0>>>>;
 return j
   end;

symbolic procedure bflerrmsg u;
   %Standard error message for BFLOAT module;
   rederr list("Invalid argument to",u);


% Simp property for !:BF!: since PREP is identity.

symbolic procedure !:bf!:simp u; ('!:bf!: . u) ./ 1;

put('!:bf!:,'simpfn,'!:bf!:simp);

!:prec!: := 12;   %default value;

initdmode 'bigfloat;

symbolic procedure precision n;
   if n=0 then !:prec!:-2 else <<!:prec!: := n+2; n>>;

flag('(precision),'opfn);    % symbolic operator precision;


% *** Tables for Elementary Function and Constant Values ***

deflist('((exp exp!*) (expt bfexpt!:) (log log!*) (sin sin!*)
   (cos cos!*) (tan tan!*) (asin asin!*) (acos acos!*)
   (atan atan!*) (sqrt sqrt!*) (sinh sinh!*) (cosh cosh!*)
   (e e!*) (pi pi!*)),
 '!:bf!:);

symbolic procedure bfexpt!:(u,v);
   % Calculates u**v, including case u<0.
   if minusp!: u 
     then multd(texpt!:any(minus!: u,v),
                !*q2f if null numr simp list('difference,v,
                                             '(quotient 1 2))
                        then simp 'i
                       else mksq(list('expt,'(minus 1),v),1))
    else texpt!:any(u,v);

symbolic procedure exp!* u; exp!:(u,!:prec!:);

symbolic procedure log!* u; log!:(u,!:prec!:);

symbolic procedure sin!* u; sin!:(u,!:prec!:);

symbolic procedure cos!* u; cos!:(u,!:prec!:);

symbolic procedure tan!* u; tan!:(u,!:prec!:);

symbolic procedure asin!* u; asin!:(u,!:prec!:);

symbolic procedure acos!* u; acos!:(u,!:prec!:);

symbolic procedure atan!* u; atan!:(u,!:prec!:);

symbolic procedure sqrt!* u; sqrt!:(u,!:prec!:);

symbolic procedure sinh!* u;
   ttimes!:(conv!:a2bf 0.5,
            tdifference!:(exp!* u,exp!* !:minus u));

symbolic procedure cosh!* u;
   ttimes!:(conv!:a2bf 0.5,
            bfplus!:(exp!* u,exp!* !:minus u));

symbolic procedure pi!*;
   if !:prec!:>1000 then !:bigpi !:prec!: else !:pi !:prec!:;

symbolic procedure e!*; !:e !:prec!:;


%*************************************************************
%*************************************************************
%**                                                         **
%**       ARBITRARY PRECISION REAL ARITHMETIC SYSTEM        **
%**               machine-independent version               **
%**                                                         **
%**                         made by                         **
%**                                                         **
%**                     Tateaki  Sasaki                     **
%**                                                         **
%**           The University of Utah,  March 1979           **
%**                                                         **
%**=========================================================**
%**                                                         **
%**  For design philosophy and characteristics of this      **
%**      system, see T. Sasaki, "An Arbitrary Precision     **
%**      Real Arithmetic Package in REDUCE," Proceedings    **
%**      of EUROSAM '79, Marseille (France), June 1979.     **
%**                                                         **
%**  For implementing and using this system, see T. Sasaki, **
%**      "Manual for Arbitrary Precision Real Arithmetic    **
%**      System in REDUCE," Operating Report of Utah Sym-   **
%**      bolic Computation Group.                           **
%**                                                         **
%**=========================================================**
%**                                                         **
%**  In order to speed up this system, you have only to     **
%**      rewrite four routines (DECPREC!:, INCPREC!:,       **
%**      PRECI!:, and ROUND!:LAST) machine-dependently.     **
%**                                                         **
%**=========================================================**
%**                                                         **
%**                    Table of Contents                    **
%**                                                         **
%** 1-1. Initialization.                                    **
%** 1-2. Constructor, selectors and basic predicate.        **
%** 1-3. Temporary routines for rational number arithmetic. **
%** 1-4. Counters.                                          **
%** 1-5. Routines for converting the numeric type.          **
%** 1-6. Routines for converting a big-float number.        **
%** 1-7. Routines for reading/printing numbers.             **
%** 2-1. Arithmetic manipulation routines.                  **
%** 2-2. Arithmetic predicates.                             **
%** 3-1. Elementary constants.                              **
%** 3-2. Routines for saving constants.                     **
%** 4-1. Elementary functions.                              **
%** 5-1. Appendix: routines for defining infix operators.   **
%**                                                         **
%*************************************************************
%*************************************************************


%*************************************************************
%**                                                         **
%** 1-1. Initialization.                                    **
%**                                                         **
%*************************************************************

%*************************************************************
%**                                                         **
%** 1-2. CONSTRUCTOR, SELECTORS and basic PREDICATE.        **
%**                                                         **
%*************************************************************

 symbolic smacro procedure make!:bf(mt,ep);
 % MT and EP are any integers (positive or negative).  So,
 %      you can handle any big or small numbers.  In this
 %      sense, "BF" denotes a BIG-FLOATING-POINT number.
 %      Hereafter, an internal representation of a number
 %      constructed by MAKE!:BF is referred to as a
 %      BIG-FLOAT representation.
          cons('!:bf!: , cons(mt,ep))$


symbolic procedure bfp!:(x);
 % This function returns T if X is a BIG-FLOAT
 %      representation, else it returns NIL.
 % X is any LISP entity.
          if atom(x) then nil else
          if car(x) eq '!:bf!: then t else nil$


%*************************************************************
%**                                                         **
%** 1-3. Temporary routines for rational number arithmetic. **
%**                                                         **
%*************************************************************

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
  if zerop dn then rederr "ZERO DENOMINATOR IN MAKE!:RATNUM"
    else if dn > 0 then '!:ratnum!: . (nm . dn)
                   else '!:ratnum!: . (-nm . -dn);


symbolic procedure ratnump!:(x);
% This function returns T if X is a rational number
%      representation, else it returns NIL.
% X is any LISP entity.
eqcar(x, '!:ratnum!:);                   %JBM Change to EQCAR.


symbolic smacro procedure numr!: rnmbr;
% This function selects the numerator of a rational
%      number "n".
% RNMBR is a rational number representation of "n".
          cadr rnmbr$


symbolic smacro procedure denm!: rnmbr;
% This function selects the denominator of a rational
%      number "n".
% RNMBR is a rational number representation of "n".
          cddr rnmbr$


%*************************************************************
%**                                                         **
%** 1-4. COUNTERS.                                          **
%**                                                         **
%*************************************************************

symbolic smacro procedure preci!: nmbr;
% This function counts the precision of a number "n".
% NMBR is a BIG-FLOAT representation of "n".
          length explode abs mt!: nmbr$


symbolic procedure order!: nmbr;
% This function counts the order of a number "n".
% NMBR is a BIG-FLOAT representation of "n".
% **** ORDER(n)=k if 10**k <= ABS(n) < 10**(k+1)
% ****     when n is not 0, and ORDER(0)=0.
  if mt!: nmbr = 0 then 0
   else preci!: nmbr + ep!: nmbr - 1$


%*************************************************************
%**                                                         **
%** 1-5. Routines for converting the numeric type.          **
%**                                                         **
%*************************************************************

symbolic procedure conv!:a2bf(n);
% This function converts a number N or a number-like
%      entity N to a <BIG-FLOAT>, i.e., a BIG-FLOAT
%      representation of N.
% N is either an integer, a floating-point number,
%      a string representing a number, a rational
%      number, or a <BIG-FLOAT>.
% **** This function is the most general conversion
% ****      function to get a BIG-FLOAT representation.
% ****      In this sense, A means an Arbitrary number.
% **** A rational number is converted to a <BIG-FLOAT>
% ****      of precision !:PREC!: if !:PREC!: is not
% ****      NIL, else the precision is set 50.
   if bfp!: n then n
    else if fixp n then make!:bf(n, 0)
    else if floatp n then read!:num n
    else if stringp n then read!:num n
    else if ratnump!: n then 
       conv!:r2bf(n, if !:prec!: then !:prec!: else 50)
    else if not atom n and idp car n and get(car n,'dname)
     then apply(get(car n,'!:bf!:),list n)
    else bflerrmsg 'conv!:a2bf$


symbolic procedure conv!:f2bf fnmbr;
% This function converts a floating-point number
%      FNMBR to a <BIG-FLOAT>, i.e., a BIG-FLOAT
%      representation.
% FNMBR is a floating-point number.
% **** CAUTION!. If you input a number, say, 0.1,
% ****      some systems do not accept it as 0.1
% ****      but may accept it as 0.09999999.
% ****      In such a case, you had better use
% ****      CONV!:S2BF than to use CONV!:F2BF.
  if floatp fnmbr then read!:num fnmbr
     else bflerrmsg 'conv!:f2bf$


symbolic procedure conv!:i2bf intgr;
% This function converts an integer INTGR to a <BIG-
%      FLOAT>, i.e., a BIG-FLOAT representation.
% INTGR is an integer.
  if fixp intgr then make!:bf(intgr, 0)
    else bflerrmsg 'conv!:i2bf$


symbolic procedure conv!:r2bf(rnmbr,k);
% This function converts a rational number RNMBR to a
%      <BIG-FLOAT> of precision K, i.e., a BIG-FLOAT
%      representation with a given precision.
% RNMBR is a rational number representation.
% K is a positive integer.
  if ratnump!: rnmbr and fixp k and k > 0 then
             divide!:( make!:bf( numr!: rnmbr, 0),
                       make!:bf( denm!: rnmbr, 0), k)
   else bflerrmsg 'conv!:r2bf$


symbolic procedure conv!:s2bf strng;
% This function converts a string representing
%      a number "n" to a <BIG-FLOAT>, i.e.,
%      a BIG-FLOAT representation.
% STRNG is a string representing "n".  "n" may
%      be an integer, a floating-point number
%      of any precision, or a rational number.
% **** CAUTION!  Some systems may set the
% ****           maximum size of string.
  if stringp strng then read!:num strng
   else bflerrmsg 'conv!:s2bf$


symbolic procedure conv!:bf2f nmbr;
% This function converts a <BIG-FLOAT>, i.e., a BIG-FLOAT
%      representation of "n", to a floating-point number.
% NMBR is a BIG-FLOAT representation of the number "n".
  if bfp!: nmbr then
       float mt!: nmbr * float(10 ** ep!: nmbr)
   else bflerrmsg 'conv!:bf2f$


symbolic procedure conv!:bf2i nmbr;
% This function converts a <BIG-FLOAT>, i.e., a BIG-FLOAT
%      representation of "n", to an integer.  The result
%      is the integer part of "n".
% **** For getting the nearest integer to "n", please use
% ****      the combination MT!:( CONV!:EP(NMBR,0)).
% NMBR is a BIG-FLOAT representation of the number "n".
  if bfp!: nmbr then
      if ep!:(nmbr := cut!:ep(nmbr, 0)) = 0 then mt!: nmbr
             else mt!: nmbr * 10 ** ep!: nmbr
   else bflerrmsg 'conv!:bf2i$


symbolic procedure conv!:bf2r nmbr;
% This function converts a <BIG-FLOAT>, i.e., a BIG-FLOAT
%      representation of "n", to a rational number.
% NMBR is a BIG-FLOAT representation of "n".
% **** The numerator and the denominator of the result
% ****      have no common divisor.
  if bfp!: nmbr then
    begin integer nn,nd,m,n,q;
          if (q := ep!: nmbr) >= 0 then
               << nn := mt!: nmbr * 10**q; nd := 1; m := 1 >>
          else << nn := mt!: nmbr; nd := 10 ** -q;
                  if abs nn > abs nd then <<m := nn; n := nd >>
                     else << m := nd; n:= nn >>;
                 while not(n = 0) do
                       << q := remainder(m, n); m := n; n := q >> >>;
          return make!:ratnum(nn/m, nd/m);
    end
   else bflerrmsg 'conv!:bf2r$


%*************************************************************
%**                                                         **
%** 1-6. Routines for converting a BIG-FLOAT number.        **
%**                                                         **
%*************************************************************

symbolic procedure decprec!:(nmbr, k);
% This function converts a number "n" to an equivalent
%      number the precision of which is decreased by K.
% **** CAUTION!  No rounding is made.
% NMBR is a BIG-FLOAT representation of "n".
% K is a positive integer.
   make!:bf( mt!: nmbr / 10**k, ep!: nmbr + k)$


symbolic procedure incprec!:(nmbr, k);
% This function converts a number "n" to an equivalent
%      number the precision of which is increased by K.
% **** CAUTION!  No rounding is made.
% NMBR is a BIG-FLOAT representation of "n".
% K is a positive integer.
   make!:bf( mt!: nmbr * 10**k, ep!: nmbr - k)$


symbolic procedure conv!:mt(nmbr, k);
% This function converts a number "n" to an
%      equivalent number of precision K by
%      rounding "n" or adding "0"s to "n".
% NMBR is a BIG-FLOAT representation of "n".
% K is a positive integer.
  if bfp!: nmbr and fixp k and k > 0 then
    if (k := preci!: nmbr - k) = 0 then nmbr
      else if k < 0 then incprec!:(nmbr, -k)
           else round!:last(decprec!:(nmbr, k - 1))
   else bflerrmsg 'conv!:mt$


symbolic procedure conv!:ep(nmbr, k);
% This function converts a number "n" to an
%      equivalent number having the exponent K
%      by rounding "n" or adding "0"s to "n".
% NMBR is a BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
  if bfp!: nmbr and fixp k then
    if (k := k - ep!: nmbr) = 0 then nmbr
       else if k < 0 then incprec!:(nmbr, -k)
            else round!:last(decprec!:(nmbr, k - 1))
   else bflerrmsg 'conv!:ep$


symbolic procedure cut!:mt(nmbr,k);
% This function returns a given number "n" unchanged
%      if its precision is not greater than K, else it
%      cuts off its mantissa at the (K+1)th place and
%      returns an equivalent number of precision K.
% **** CAUTION!  No rounding is made.
% NMBR is a BIG-FLOAT representation of "n".
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
% NMBR is a BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
  if bfp!: nmbr and fixp k then
     if (k := k - ep!: nmbr) <= 0 then nmbr
        else decprec!:(nmbr, k)
   else bflerrmsg 'cut!:ep$


symbolic procedure match!:(n1,n2);
% This function converts either "n1" or "n2" so that they
%      have the same exponent, which is the smaller of
%      the exponents of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
% **** CAUTION!  Using this function, one of the previous
% ****           expressions of "n1" and "n2" is lost.
 if bfp!: n1 and bfp!: n2 then
    begin integer e1,e2;  scalar n;
          if (e1 := ep!: n1) = (e2 := ep!: n2) then return t;
          if e1 > e2 then << rplaca(n1, car(n := conv!:ep(n1, e2)));
                             rplacd(n1, cdr n) >>
           else << rplaca(n2, car(n := conv!:ep(n2, e1)));
                   rplacd(n2, cdr n) >>;
          return t;
    end
   else bflerrmsg 'match!:$


symbolic procedure round!:mt(nmbr, k);
% This function rounds a number "n" at the (K+1)th place
%      and returns an equivalent number of precision K
%      if the precision of "n" is greater than K, else
%      it returns the given number unchanged.
% NMBR is a BIG-FLOAT representation of "n".
% K is a positive integer.
  if bfp!: nmbr and fixp k and k > 0 then
    if (k := preci!: nmbr - k - 1) < 0 then nmbr
       else if k = 0 then round!:last nmbr
           else round!:last decprec!:(nmbr, k)
   else bflerrmsg 'round!:mt$


symbolic procedure round!:ep(nmbr, k);
% This function rounds a number "n" and returns an
%      equivalent number having the exponent K if
%      the exponent of "n" is less than K, else
%      it returns the given number unchanged.
% NMBR is a BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
  if bfp!: nmbr and fixp k then
    if (k := k - 1 - ep!: nmbr) < 0 then nmbr
      else if k = 0 then round!:last nmbr
      else round!:last decprec!:(nmbr, k)
   else bflerrmsg 'round!:ep$


symbolic procedure round!:last nmbr;
% This function rounds a number "n" at its last place.
% NMBR is a BIG-FLOAT representation of "n".
begin scalar n;
   n := divide(abs mt!: nmbr, 10);
   if cdr n < 5 then n := car n else n := car n + 1;
   if mt!: nmbr < 0 then n := -n;
   return make!:bf(n, ep!: nmbr + 1);
end$


%*************************************************************
%**                                                         **
%** 1-7. Routines for reading/printing numbers.             **
%**                                                         **
%*************************************************************

symbolic procedure allfixp l;            %JBM
% Returns T if all of L are FIXP.        %JBM
if null l then t                         %JBM
  else if not fixp car l then nil        %JBM
  else allfixp cdr l;                    %JBM


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
          return make!:bf(sign * mt, ep);
    end$


symbolic procedure read!:num(n);
% This function reads a number or a number-like entity N
%      and constructs a BIG-FLOAT representation of it.
% N is an integer, a floating-point number, or a string
%      representing a number.
% **** If the system does not accept or may incorrectly
% ****      accept the floating-point numbers, you can
% ****      input them as strings such as "1.234E-56",
% ****      "-78.90 D+12" , "+3456 B -78", or "901/234".
% **** A rational number in a string form is converted
% ****      to a <BIG-FLOAT> of precision !:PREC!: if
% ****      !:PREC!: is not NIL, else the precision of
% ****      the result is set 50.
% **** Some systems set the maximum size of strings.  If
% ****      you want to input long numbers exceeding
% ****      such a maximum size, please use READ!:LNUM.
if fixp n then make!:bf(n, 0)
else if not(numberp n or stringp n) then bflerrmsg 'read!:num
else
    begin integer j,m,sign;  scalar ch,u,v,l,appear!.,appear!/;
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
    endl: if l := cdr l then goto loop else goto make;
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
                              if !:prec!: then !:prec!: else 50);
          if appear!. then j := - j else j := 0;
          if sign = 1 then u := compress u else u := - compress u;
          return make!:bf(u, j + m);
    end$


symbolic procedure print!:bf(nmbr, type);
% This function prints a number "n" in the print-type TYPE.
% NMBR is a BIG-FLOAT representation of "n".
% TYPE is either 'N, 'I, 'E, 'F, 'L, 'R, meaning as:
%      TYPE='N ... the internal representation is printed.
%      TYPE='I ... the integer part is printed.
%      TYPE='E ... <mantissa in form *.***>E<exponent>.
%      TYPE='F ... <integer part>.<decimal part>.
%      TYPE='L ... in a list form readable by READ!:LNUM.
%      TYPE='R ... printed as a rational number.
% **** The number is printed by being inserted a blank
% ****      after each five characters.  Therefore, you
% ****      can not use the printed numbers as input data,
% ****      except when they are printed in type 'L.
if not(type memq '(n i e f l r))         %JBM
   or not bfp!: nmbr then bflerrmsg 'print!:bf
else
    begin integer j,k;  scalar u,v;
%          if bfzerop!: nmbr  then nmbr:=make!:bf(0, 0);
          if bfzerop!: nmbr then nmbr := !:bf!-0;    %JBM
          if type eq 'i then goto itype
           else if type eq 'e then goto etype
           else if type eq 'f then goto ftype
           else if type eq 'l then goto ltype
           else if type eq 'r then goto rtype;
   ntype: print nmbr;
          return t;
   itype: u := explode conv!:bf2i nmbr;
          j := 0;
          while u do << prin2 car u; u := cdr u; j := j + 1;
                        if j = 5 then << prin2 " "; j := 0 >> >>;
          terpri();
          return t;
   etype: u := explode abs(j := mt!: nmbr);
          if null cdr u then rplacd(u , list 0);
          if j >= 0 then u := car u . ('!. . cdr u)
           else u := '!- . (car u . ('!. . cdr u));
          j := 0;
          while u do << prin2 car u; u := cdr u; j := j + 1;
                        if j = 5 then << prin2 " "; j := 0 >> >>;
          if j = 0 then << prin2 "E "; j := 2 >>
           else if j = 1 then << prin2 " E "; j := 4 >>
           else if j = 2 then << prin2 " E  "; j := 0 >>
           else if j = 3 then << prin2 " E "; j := 0 >>
           else if j = 4 then << prin2 "  E "; j := 2 >>;
          u := explode(k := order!: nmbr);
          if k >= 0 then u := '!+ . u;
          while u do << prin2 car u; u := cdr u; j := j + 1;
                        if j=5 then << prin2 " "; j := 0 >> >>;
          terpri();
          return t;
   ftype: u := explode abs mt!: nmbr;
          if (j := ep!: nmbr) >= 0 then
               << v := nil; while (j := j - 1) >= 0 do v := 0 . v;
                  u := nconc(u, v) >>
           else if (j := order!: nmbr + 1) > 0 then
               << v := u; while (j := j - 1) > 0 do v := cdr v;
                  rplacd(v, '!. . cdr v) >>
           else << while (j := j + 1) <= 0 do u := 0 . u;
                   u := 0 . ('!. . u) >>;
          if mt!: nmbr < 0 then u := '!- . u;
          j := 0;
          while u do << prin2 car u; u := cdr u; j := j + 1;
                        if j = 5 then << prin2 " "; j := 0 >> >>;
          terpri();
          return t;
   ltype: prin2 " '(";
          prin2 order!: nmbr;
          prin2 "  ";
          u := explode mt!: nmbr;
          j := 0;
          while u do << prin2 car u; u := cdr u; j := j + 1;
                       if j >= 5 and u and not(car u eq '!0)
                          then <<prin2 " "; j := j - 5 >> >>;
          prin2 ")";
          terpri();
          return t;
   rtype: print!:ratnum conv!:bf2r nmbr;
          return t;
    end$


symbolic procedure print!:ratnum rnmbr;
% This function prints a rational number "n".
% RNMBR is a rational number representation of "n".
% **** The number is printed by being inserted a blank
% ****      after each five characters.  So, you can
% ****      not use the printed numbers as input data.
if not ratnump!: rnmbr then bflerrmsg 'print!:ratnum
 else
    begin integer j;  scalar u, v;
          u := numr!: rnmbr;
          v := denm!: rnmbr;
          if v < 0 then << u := - u; v := - v >>;
          j := 0;
          for each d in explode u        %JBM loop here.
              do << prin2 d; j := j + 1;
                    if j = 5 then << prin2 " "; j := 0 >> >>;
          if j = 0 then << prin2 "/ "; j := 2 >>
           else if j = 1 then << prin2 " / "; j := 4 >>
           else if j = 2 then << prin2 " /  "; j := 0 >>
           else if j = 3 then << prin2 " / "; j := 0 >>
           else if j = 4 then << prin2 "  / "; j := 2 >>;
          for each d in explode v        %JBM loop here.
              do << prin2 d; j := j + 1;
                    if j = 5 then << prin2 " "; j := 0 >> >>;
          terpri();
          return t;
    end$


%*************************************************************
%**                                                         **
%** 2-1. Arithmetic manipulation routines.                  **
%**                                                         **
%*************************************************************

symbolic procedure abs!: nmbr;
% This function makes the absolute value of "n".
% N is a BIG-FLOAT representation of "n".
  if mt!: nmbr > 0 then nmbr
   else make!:bf(- mt!: nmbr, ep!: nmbr)$


symbolic procedure minus!: nmbr;
% This function makes the minus number of "n".
% N is a BIG-FLOAT representation of "n".
   make!:bf(- mt!: nmbr, ep!: nmbr)$


symbolic procedure plus!:(n1, n2);
% This function calculates the sum of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  begin integer e1, e2;
        if (e1 := ep!: n1) = (e2 := ep!: n2) then return
           make!:bf(mt!: n1 + mt!: n2, e1)
         else if e1 > e2 then return 
           make!:bf(mt!: incprec!:(n1, e1 - e2) + mt!: n2, e2)
         else return
           make!:bf(mt!: n1 + mt!: incprec!:(n2, e2 - e1), e1);
  end$


symbolic procedure difference!:(n1, n2);
% This function calculates the difference of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  begin integer e1,e2;
        if (e1 := ep!: n1) = (e2 := ep!: n2) then return
           make!:bf(mt!: n1 - mt!: n2, e1)
        else if e1 > e2 then return
           make!:bf(mt!: incprec!:(n1, e1 - e2) - mt!: n2, e2)
        else return
           make!:bf(mt!: n1 - mt!: incprec!:(n2, e2 - e1), e1);
  end$


symbolic procedure times!:(n1, n2);
% This function calculates the product of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  make!:bf(mt!: n1 * mt!: n2, ep!: n1 + ep!: n2)$


 symbolic procedure divide!:(n1,n2,k);
% This function calculates the quotient of "n1" and "n2",
%      with the precision K, by rounding the ratio of "n1"
%      and "n2" at the (K+1)th place.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
% K is any positive integer.
begin
  n1 := conv!:mt(n1, k + preci!: n2 + 1);
  n1 := make!:bf(mt!: n1 / mt!: n2, ep!: n1 - ep!: n2);
  return round!:mt(n1, k);
end$


symbolic procedure expt!:(nmbr, k);
% This function calculates the Kth power of "n".
%      The result will become a long number if
%      ABS(K) >> 1.
% NMBR is a BIG-FLOAT representation of "n".
% K is an integer (positive or negative).
% **** For calculating a power X**K, with non-
% ****      integer K, please use TEXPT!:ANY.
if k >= 0 then
   make!:bf(mt!: nmbr ** k, ep!: nmbr * k)
% else divide!:(make!:bf(1, 0), expt!:(nmbr, - k),
 else divide!:(!:bf!-1, expt!:(nmbr, - k),    %JBM
                               - preci!: nmbr * k)$


symbolic procedure tplus!:(n1, n2);
% This function calculates the sum of "n1" and "n2"
%      up to a precision specified by !:PREC!: or N1 or N2.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2",
%      otherwise they are converted to <BIG-FLOAT>'s.
if bfp!:(n1 := conv!:a2bf n1) and
   bfp!:(n2 := conv!:a2bf n2) then
     round!:mt(plus!:(n1, n2), 
               (if !:prec!: then !:prec!:
                 else max(preci!: n1, preci!: n2)))
   else bflerrmsg 'tplus!:$


symbolic procedure tdifference!:(n1, n2);
% This function calculates the difference of "n1" and "n2"
%      up to a precision specified by !:PREC!: or N1 or N2.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2",
%      otherwise they are converted to <BIG-FLOAT>'s.
if bfp!:(n1 := conv!:a2bf n1) and
   bfp!:(n2 := conv!:a2bf n2) then
    round!:mt(difference!:(n1, n2),
              (if !:prec!: then !:prec!:
                           else max(preci!: n1, preci!: n2)))
   else bflerrmsg 'tdifference!:$


symbolic procedure ttimes!:(n1, n2);
% This function calculates the product of "n1" and "n2"
%      up to a precision specified by !:PREC!: or N1 or N2.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2",
%      otherwise they are converted to <BIG-FLOAT>'s.
if bfp!:(n1 := conv!:a2bf n1) and
   bfp!:(n2 := conv!:a2bf n2) then
    round!:mt(times!:(n1, n2),
              (if !:prec!: then !:prec!:
                else max(preci!: n1, preci!: n2)))
   else bflerrmsg 'ttimes!:$


symbolic procedure tdivide!:(n1, n2);
% This function calculates the quotient of "n1" and "n2"
%      up to a precision specified by !:PREC!: or N1 or N2.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2",
%      otherwise they are converted to <BIG-FLOAT>'s.
if bfp!:(n1 := conv!:a2bf n1) and
   bfp!:(n2 := conv!:a2bf n2) then
    divide!:(n1,
             n2,
             (if !:prec!: then !:prec!:
              else max(preci!: n1, preci!: n2)))
   else bflerrmsg 'tdivide!:$


symbolic procedure texpt!:(nmbr, k);
% This function calculates the Kth power of "n" up to
%      the precision specified by !:PREC!: or NMBR.
% NMBR is a BIG-FLOAT representation of "n",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is an integer (positive or negative).
% **** For calculating a power X**K, where K is not
% ****      an integer, please use TEXPT!:ANY.
if bfp!:(nmbr := conv!:a2bf nmbr) and fixp k then
%    if k = 0 then make!:bf(1, 0)
    if zerop k then !:bf!-1    %JBM
     else if k = 1 then nmbr
%     else if k < 0 then tdivide!:(make!:bf(1, 0),
     else if minusp k then tdivide!:(!:bf!-1,   %JBM
                                  texpt!:(nmbr, - k))
     else texpt!:cal(nmbr, k,
                     (if !:prec!: then !:prec!: else preci!: nmbr))
   else bflerrmsg 'texpt!:$


symbolic procedure texpt!:cal(nmbr,k,prec);
if k=1 then nmbr
 else begin integer k2;  scalar u;
          u := round!:mt(times!:(nmbr, nmbr), prec);
          if k = 2 then return u
           else if (k - 2 * (k2 := k / 2)) = 0 then return
               texpt!:cal(u, k2, prec)
           else return round!:mt
               (times!:(nmbr, texpt!:cal(u, k2, prec)), prec);
      end$


symbolic procedure quotient!:(n1, n2);
% This function calculates the integer quotient of "n1"
%      and "n2", just as the "QUOTIENT" for integers does.
% **** For calculating the quotient up to a necessary
% ****      precision, please use DIVIDE!:.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
begin integer e1, e2;
  if (e1 := ep!: n1) = (e2 := ep!: n2) then return
             make!:bf(mt!: n1 / mt!: n2, 0)
   else if e1 > e2 then return
             quotient!:(incprec!:(n1, e1 - e2) , n2)
   else return
             quotient!:(n1, incprec!:(n2, e2 - e1));
end$


symbolic procedure remainder!:(n1, n2);
% This function calculates the remainder of "n1" and "n2",
%      just as the "REMAINDER" for integers does.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
begin integer e1, e2;
  if (e1 := ep!: n1) = (e2 := ep!: n2) then return
      make!:bf(remainder(mt!: n1, mt!: n2), e2)
   else if e1 > e2 then return
      remainder!:(incprec!:(n1, e1 - e2), n2)
   else return
      remainder!:(n1, incprec!:(n2, e2 - e1));
end$


symbolic procedure texpt!:any(x, y);
% This function calculates the power x**y, where "x"
%      and "y" are any numbers.  The precision of
%      the result is specified by !:PREC!: or X or Y.
% **** For a negative "x", this function returns
% ****      -(-x)**y unless "y" is an integer.
% X is a BIG-FLOAT representation of "x", otherwise
%      it is converted to a <BIG-FLOAT>.
% Y is either an integer, a floating-point number,
%      or a BIG-FLOAT number, i.e., a BIG-FLOAT
%      representation of "y".
if fixp y then texpt!:(x, y)
 else if integerp!: y then texpt!:(x, conv!:bf2i y)
 else if not bfp!:(x := conv!:a2bf x) or
         not bfp!:(y := conv!:a2bf y) then bflerrmsg 'texpt!:any
% else if minusp!: y then tdivide!:(make!:bf(1, 0),
 else if minusp!: y then tdivide!:(!:bf!-1,    %JBM
                                   texpt!:any(x, minus!: y))
 else begin integer n;  scalar xp, yp;
          n := (if !:prec!: then !:prec!:
                else max(preci!: x, preci!: y));
          if minusp!: x then xp:=minus!: x else xp := x;
          if integerp!: times!:(y, conv!:i2bf 2) then  %CONSTANT
             << xp := incprec!:(xp, 1);
                yp := texpt!:(xp, conv!:bf2i y);
                yp := times!:(yp, sqrt!:(xp, n + 1)); 
                yp := round!:mt(yp, n) >>
          else
             << yp := ttimes!:(y, log!:(xp, n + 1));
                yp := exp!:(yp, n) >>;

          return (if minusp!: x then minus!: yp else yp);
     end$


symbolic procedure max!:(n1,n2);
% This function returns the larger of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  if greaterp!:(n2, n1) then n2 else n1$


symbolic procedure min!:(n1,n2);
% This function returns the smaller of "n1" and "n2".
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  if lessp!:(n2, n1) then n2 else n1$


%*************************************************************
%**                                                         **
%** 2-2. Arithmetic predicates.                             **
%**                                                         **
%*************************************************************

symbolic procedure greaterp!:(n1, n2);
% This function returns T if "n1" > "n2" else returns NIL.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
begin integer e1,e2;
  if (e1 := ep!: n1) = (e2 := ep!: n2) then
     return (mt!: n1 > mt!: n2)          %JBM
  else if e1 > e2 then
     return mt!: incprec!:(n1, e1 - e2) > mt!: n2   %JBM
  else 
     return mt!: n1 > mt!: incprec!:(n2, e2 - e1)   %JBM
end$


symbolic procedure geq!:(n1, n2);
% This function returns T if "n1" >= "n2" else returns NIL.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  not lessp!:(n1, n2)$


symbolic procedure equal!:(n1,n2);
% This function returns T if "n1" = "n2" else returns NIL.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
 bfzerop!: difference!:(n1, n2)$


symbolic procedure lessp!:(n1, n2);
% This function returns T if "n1" < "n2" else returns NIL.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  greaterp!:(n2, n1)$


symbolic procedure leq!:(n1, n2);
% This function returns T if "n1" <= "n2" else returns NIL.
% N1 and N2 are BIG-FLOAT representations of "n1" and "n2".
  not greaterp!:(n1, n2)$


symbolic procedure integerp!: x;
% This function returns T if X is a BIG-FLOAT
%      representing an integer, else it returns NIL.
% X is any LISP entity.
%JBM Critique: this is pretty slow. Couldn't we just check the
%JBM Critique: exponent in relation to the precision?
bfp!: x and
  (ep!: x >= 0 or
   equal!:(x, conv!:i2bf conv!:bf2i x));


symbolic procedure minusp!: x;
% This function returns T if "x"<0 else returns NIL.
% X is any LISP entity.
  bfp!: x and mt!: x < 0$


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
 else if k <= 20 then
%   round!:mt(make!:bf(314159265358979323846, -20), k)
   round!:mt(!:bf!-pi, k)    %JBM
 else
    begin integer k3,s,ss,m,n,x;  scalar u;

          u := get!:const('!:pi, k);
          if u neq "NOT FOUND" then return u;
          ss := n := 10 ** (k3 := k + 3) / 5;
          x := -5 ** 2;
          m := 1;
          while n neq 0 do <<n := n/x; ss := ss + n/(m := m + 2)>>;
          s := n := 10 ** k3 / 239;
          x := -239 ** 2;
          m := 1;
          while n neq 0 do << n := n / x; s := s + n / (m := m + 2) >>;
     ans: u := round!:mt(make!:bf(16 * ss - 4 * s, - k3), k);
          save!:const('!:pi, u);
          return u;
    end$


symbolic procedure !:bigpi k;
% This function calculates the value of the circular
%      constant "PI", with the precision K, by the
%      arithmetic-geometric mean method.  (See,
%      R. Brent, JACM Vol.23, #2, pp.242-251(1976).)
% K is a positive integer.
% **** This function should be used only when you
% ****      need "PI" of precision higher than 1000.
if not fixp k or k <= 0 then bflerrmsg '!:bigpi
 else begin integer k2, n;  scalar dcut, half, x, y, u, v;
          u := get!:const('!:pi, k);
          if u neq "NOT FOUND" then return u;
          k2 := k + 2;
%          half := conv!:s2bf "0.5";      %constant
          half := !:bf!-0!.5;    %JBM
          dcut := make!:bf(10, - k2);
          x := conv!:i2bf(n := 1);
          y := divide!:(x, !:sqrt2 k2, k2);
%          u := conv!:s2bf "0.25";        %constant
          u := !:bf!-0!.25;    %JBM
          while greaterp!:(abs!: difference!:(x, y), dcut) do
            << v := x;
               x := times!:(plus!:(x, y), half);
               y := sqrt!:(cut!:ep(times!:(y, v), - k2), k2);
               v := difference!:(x, v);
               v := times!:(times!:(v, v), conv!:i2bf n);
               u := difference!:(u, cut!:ep(v, - k2));
               n := 2 * n >>;
          v := cut!:mt(expt!:(plus!:(x, y), 2), k2);
          u := divide!:(v, times!:(conv!:i2bf 4, u), k); %CONSTANT
          save!:const('!:pi, u);
          return u;
    end$


symbolic procedure !:e k;
% This function calculates the value of "e", the base
%      of the natural logarithm, with the precision K,
%      by summing the Taylor series for exp(x=1).
%      Calculation is performed mainly on integers.
% K is a positive integer.
if not fixp k or k <= 0 then bflerrmsg '!:e
 else if k <= 20 then
%   round!:mt(make!:bf(271828182845904523536, -20), k)
   round!:mt(!:bf!-e, k)    %JBM
 else begin integer k2, ans, m, n;  scalar u;
          u := get!:const('!:e, k);
          if u neq "NOT FOUND" then return u;
          k2 := k + 2;
          m := 1;
          n := 10 ** k2;
          ans := 0;
          while n neq 0  do ans := ans + (n := n / (m := m + 1));
          ans := ans + 2 * 10 ** k2;
          u := round!:mt(make!:bf(ans, - k2), k);
          save!:const('!:e2, u);
          return u;
       end$


symbolic procedure !:e01(k);
% This function calculates exp(0.1), the value of the
%      exponential function at the point 0.1, with
%      the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:e01, k);
  if u neq "NOT FOUND" then return u;
%  u := exp!:(conv!:s2bf "0.1", k);       %constant
  u := exp!:(!:bf!-0!.1, k);    %JBM
  save!:const('!:e01, u);
  return u;
end$


symbolic procedure !:log2 k;
% This function calculates log(2), the natural
%      logarithm of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log2, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(conv!:i2bf 2, k);           %CONSTANT
  save!:const('!:log2, u);
  return u;
end$


symbolic procedure !:log3 k;
% This function calculates log(3), the natural
%      logarithm of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log3, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(conv!:i2bf 3, k);           %CONSTANT
  save!:const('!:log3, u);
  return u;
end$


symbolic procedure !:log5 k;
% This function calculates log(5), the natural
%      logarithm of 5, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log5, k);
  if u neq "NOT FOUND" then return u;
  u := log!:(conv!:i2bf 5, k);           %CONSTANT
  save!:const('!:log5, u);
  return u;
end$


symbolic procedure !:log10 k;
% This function calculates log(10), the natural
%      logarithm of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:log10,  k);
  if u neq "NOT FOUND" then return u;
  u := log!:(conv!:i2bf 10, k);          %CONSTANT
  save!:const('!:log10, u);
  return u;
end$


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
end$


symbolic procedure !:sqrt2(k);
% This function calculates SQRT(2), the square root
%      of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt2, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(conv!:i2bf 2, k);          %CONSTANT
  save!:const('!:sqrt2, u);
  return u;
end$


symbolic procedure !:sqrt3(k);
% This function calculates SQRT(3), the square root
%      of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u:=get!:const('!:sqrt3, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(conv!:i2bf 3, k);          %CONSTANT
  save!:const('!:sqrt3, u);
  return u;
end$


symbolic procedure !:sqrt5 k;
% This function calculates SQRT(5), the square root
%      of 5, with the precision K. 
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt5, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(conv!:i2bf 5, k);          %CONSTANT
  save!:const('!:sqrt5, u);
  return u;
end$


symbolic procedure !:sqrt10 k;
% This function calculates SQRT(10), the square root
%      of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:sqrt10, k);
  if u neq "NOT FOUND" then return u;
  u := sqrt!:(conv!:i2bf 10, k);         %CONSTANT
  save!:const('!:sqrt10, u);
  return u;
end$


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
end$


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
end$


symbolic procedure !:cbrt2 k;
% This function calculates CBRT(2), the cube root
%      of 2, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt2, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(conv!:i2bf 2, k);          %CONSTANT
  save!:const('!:cbrt2, u);
  return u;
end$


symbolic procedure !:cbrt3 k;
% This function calculates CBRT(3), the cube root
%      of 3, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt3, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(conv!:i2bf 3, k);
  save!:const('!:cbrt3, u);
  return u;
end$


symbolic procedure !:cbrt5 k;
% This function calculates CBRT(5), the cube root
%    of 5, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt5, k);
  if u = "NOT FOUND" then return u;
  u := cbrt!:(conv!:i2bf 5, k);          %CONSTANT
  save!:const('!:cbrt5, u);
  return u;
end$


symbolic procedure !:cbrt10 k;
% This function calculates CBRT(10), the cube root
%      of 10, with the precision K.
% K is a positive integer.
begin scalar u;
  u := get!:const('!:cbrt10, k);
  if u neq "NOT FOUND" then return u;
  u := cbrt!:(conv!:i2bf 10, k);         %CONSTANT
  save!:const('!:cbrt10, u);
  return u;
end$


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
end$


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
end$


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

set!:const( '!:e01   , '( 0   1105 17091 80756 47624 81170
     78264 90246 66822 45471 94737 51871 87928 63289 44096
     79667 47654 30298 91433 18970 74865 36329 2) )$

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
%      of "x", with the precision K, by Newton's
%      iteration method.
% X is a BIG-FLOAT representation of "x", x >= 0,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or minusp!: x or
     not fixp k or k <= 0 then bflerrmsg 'sqrt!:
    else if bfzerop!: x then conv!:i2bf 0
    else begin integer k2,ncut,nfig;  scalar dcut,half,dy,y,y0,u;
          k2 := k + 2;
          ncut := k2 - (order!: x + 1) / 2;
%          half := conv!:s2bf "0.5";
          half := !:bf!-0!.5;    %JBM
          dcut := make!:bf(10, - ncut);
          dy := make!:bf(20, - ncut);
          y0 := conv!:mt(x, 2);
          if remainder(ep!: y0, 2) = 0 then
                y0 := make!:bf(3 + 2 * mt!: y0 / 25,  ep!: y0 / 2)
           else y0 := make!:bf(10 + 2 * mt!: y0 / 9, (ep!: y0 - 1) / 2);
          nfig := 1;
          while nfig < k2 or greaterp!:(abs!: dy, dcut) do
            << if (nfig := 2 * nfig) > k2 then nfig := k2;
               u := divide!:(x, y0, nfig);
               y := times!:(plus!:(y0, u), half);
               dy := difference!:(y, y0);
               y0 := y >>;
          return round!:mt(y, k);
    end$


symbolic procedure cbrt!:(x, k);
% This function calculates CBRT(x), the cube root
%      of "x", with the precision K, by Newton's
%      iteration method.
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'cbrt!:
   else if bfzerop!: x then conv!:i2bf 0
   else if minusp!: x then minus!: cbrt!:(minus!: x, k)
   else begin integer k2, ncut, nfig, j;  scalar dcut, thre, dy, y, u;
          k2 := k + 2;
          ncut := k2 - (order!: x + 2) / 3;
          thre := conv!:i2bf 3;
          dcut := make!:bf(10, - ncut);
          dy := make!:bf(20, - ncut);
          y := conv!:mt(x, 3);
          if (j := remainder(ep!: y, 3)) = 0 then
               y := make!:bf(5 + mt!: y / 167, ep!: y / 3)
           else if j = 1 or j = -2 then
                y := make!:bf(10 + mt!: y / 75, (ep!: y - 1) / 3)
           else y := make!:bf(22 + 2 * mt!: y / 75, (ep!: y - 2) / 3);
          nfig := 1;
          while nfig < k2 or greaterp!:(abs!: dy, dcut) do
            << if (nfig := 2 * nfig) > k2 then nfig := k2;
               u := cut!:mt(times!:(y, y), nfig);
               u := divide!:(x, u, nfig);
               j :=order!:(u := difference!:(u, y)) + ncut - k2;
               dy := divide!:(u, thre, max(1, nfig + j));
               y := plus!:(y, dy) >>;
          return round!:mt(y, k);
    end$


symbolic procedure exp!:(x, k);
% This function calculates exp(x), the value of
%      the exponential function at the point "x",
%      with the precision K, by summing terms of
%      the Taylor series for exp(z), 0 < z < 1.
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'exp!: 
   else if bfzerop!: x then conv!:i2bf 1
   else begin integer k2, m;  scalar one, q, r, y, yq, yr, save!:p;
          k2 := k + 2;
          one := conv!:i2bf 1;
          q := conv!:i2bf(m := conv!:bf2i(y := abs!: x));
          r := difference!:(y, q);
          if bfzerop!: q then yq := one
           else << save!:p := !:prec!:;
                   !:prec!: := k2;
                   yq := texpt!:(!:e k2, m);
                   !:prec!: := save!:p >>;
          if bfzerop!: r then yr:=one
           else begin integer j, n;  scalar dcut, fctrial, ri, tm;
              dcut := make!:bf(10, - k2);
              yr := ri := tm := one;
              m := 1;
              j := 0;
              while greaterp!:(tm, dcut) do
                << fctrial := conv!:i2bf(m := m * (j := j + 1));
                   ri := cut!:ep(times!:(ri, r), - k2);
                   n := max(1, k2 - order!: fctrial + order!: ri);
                   tm := divide!:(ri, fctrial, n);
                   yr := plus!:(yr,tm);
                   if remainder(j,10)=0 then yr := cut!:ep(yr, - k2) >>;
        end;
          y := cut!:mt(times!:(yq, yr), k + 1);
          return (if minusp!: x then divide!:(one, y, k)
                  else round!:last y);
    end$


symbolic procedure log!:(x, k);
% This function calculates log(x), the value of the
%      logarithmic function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for log(1+z), 0 < z < 0.10518.
% X is a BIG-FLOAT representation of "x", x > 0,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     minusp!: x or bfzerop!: x or
     not fixp k or k <= 0 then bflerrmsg 'log!:
   else if equal!:(x, conv!:i2bf 1) then conv!:i2bf 0
   else begin integer k2,m;  scalar ee,es,one,sign,l,y,z,save!:p;
          k2 := k + 2;
          one := conv!:i2bf 1;
          ee := !:e k2;
          es := !:e01 k2;
          if greaterp!:(x, one) then << sign := one; y := x >>
           else << sign := minus!: one; y := divide!:(one, x, k2) >>;
          if lessp!:(y, ee) then << m := 0; z := y >>
           else << if (m := (order!: y * 23) / 10) = 0 then z := y
                    else << save!:p := !:prec!:;
                            !:prec!: := k2;
                            z := divide!:(y, texpt!:(ee, m), k2);
                            !:prec!: := save!:p >>;
                    while greaterp!:(z, ee) do
                       << m := m+1; z := divide!:(z, ee, k2) >> >>;
          l := conv!:i2bf m;
%          y := conv!:s2bf "0.1";         %constant
          y := !:bf!-0!.1;    %JBM
          while greaterp!:(z, es) do
            << l := plus!:(l, y); z := divide!:(z, es, k2) >>;
          z := difference!:(z, one);
        begin integer n;  scalar dcut, tm, zi;
              y := tm := zi := z;
              z := minus!: z;
              dcut := make!:bf(10, - k2);
              m := 1;
              while greaterp!:(abs!: tm, dcut) do
               << zi := cut!:ep(times!:(zi, z), - k2);
                  n := max(1, k2 + order!: zi);
                  tm := divide!:(zi, conv!:i2bf(m := m + 1), n);
                  y := plus!:(y, tm);
                  if zerop remainder(m,10) then y := cut!:ep(y,-k2)>>;
        end;
          y := plus!:(y, l);
          return round!:mt(times!:(sign, y), k);
    end$


symbolic procedure ln!:(x, k);
% This function calculates log(x), the value of
%      the logarithmic function at the point "x",
%      with the precision K, by solving
%         x = exp(y)  by Newton's method.
% X is a BIG-FLOAT representation of "x", x > 0,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     minusp!: x or bfzerop!: x or
     not fixp k or k <= 0 then bflerrmsg 'ln!:
    else if equal!:(x, conv!:i2bf 1) then conv!:i2bf 0
    else begin integer k2, m;  scalar ee, one, sign, y, z, save!:p;
          k2 := k + 2;
          one := conv!:i2bf 1;
          ee := !:e(k2 + 2);
          if greaterp!:(x, one) then << sign := one; y := x >>
           else << sign := minus!: one; y := divide!:(one, x, k2) >>;
          if lessp!:(y, ee) then << m := 0; z := y >>
           else << if zerop (m := (order!: y * 23) / 10) then z := y
                    else << save!:p := !:prec!:;
                            !:prec!: := k2;
                            z := divide!:(y, texpt!:(ee, m), k2);
                            !:prec!: := save!:p >>;
                    while greaterp!:(z, ee) do
                     << m := m + 1; z := divide!:(z, ee, k2) >> >>;
        begin integer nfig, n;  scalar dcut, dx, dy, x0;
              dcut := make!:bf(10, - k2);
              dy := make!:bf(20, - k2);
%             y := divide!:(difference!:(z,one), conv!:s2bf "1.72", 2);
              y := divide!:(difference!:(z,one), !:bf!-1!.72, 2);  %JBM
              nfig := 1;
              while nfig < k2 or greaterp!:(abs!: dy, dcut) do
               << if (nfig := 2 * nfig) > k2 then nfig := k2;
                  x0 := exp!:(y, nfig);
                  dx := difference!:(z, x0);
                  n := max(1, nfig + order!: dx);
                  dy := divide!:(dx, x0, n);
                  y := plus!:(y, dy) >>;
        end;
          y := plus!:(conv!:i2bf m, y);
          return round!:mt(times!:(sign, y), k);
    end$


symbolic procedure sin!:(x, k);
% This function calculates sin(x), the value of
%      the sine function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for sin(z), 0 < z < PI/4.
% X is a BIG-FLOAT representation of any rael "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'sin!:
   else if bfzerop!: x then conv!:i2bf 0
   else if minusp!: x then minus!: sin!:(minus!: x, k)
   else begin integer k2, m;  scalar pi4, sign, q, r, y;
          k2 := k + 2;
          m := preci!: x;
%          pi4 := times!:(!:pi(k2 + m), conv!:s2bf "0.25"); %constant
          pi4 := times!:(!:pi(k2 + m), !:bf!-0!.25);    %JBM
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          sign := conv!:i2bf 1;
          if m >= 8 then m := remainder(m, 8);
          if m >= 4 then << sign := minus!: sign; m := m - 4>>;
          if m = 0 then goto sn
           else if onep m then goto m1
           else if m = 2 then goto m2
           else goto m3;
      m1: r := cut!:mt(difference!:(pi4, r), k2);
          return times!:(sign, cos!:(r, k));
      m2: r := cut!:mt(r, k2);
          return times!:(sign, cos!:(r, k));
      m3: r := cut!:mt(difference!:(pi4, r), k2);
    sn: begin integer j, n, ncut;  scalar dcut, fctrial, ri, tm;
              ncut := k2 - min(0, order!: r + 1);
              dcut := make!:bf(10, - ncut);
              y := ri := tm := r;
              r := minus!: cut!:ep(times!:(r, r), - ncut);
              m := j := 1;
              while greaterp!:(abs!: tm, dcut) do
               << j := j + 2;
                  fctrial := conv!:i2bf(m := m * j * (j - 1));
                  ri := cut!:ep(times!:(ri, r), - ncut);
                  n := max(1, k2 - order!: fctrial + order!: ri);
                  tm := divide!:(ri, fctrial, n);
                  y := plus!:(y, tm);
                  if zerop remainder(j,20) then y := cut!:ep(y,-ncut)>>;
        end;
          return round!:mt(times!:(sign, y), k);
    end$


symbolic procedure cos!:(x, k);
% This function calculates cos(x), the value of
%      the cosine function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for cos(z), 0 < z < PI/4.
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'cos!:
    else if bfzerop!: x then conv!:i2bf 1
    else if minusp!: x then cos!:(minus!: x, k)
    else begin integer k2, m;  scalar pi4, sign, q, r, y;
          k2 := k + 2;
          m := preci!: x;
%          pi4 := times!:(!:pi(k2 + m), conv!:s2bf "0.25"); %constant
          pi4 := times!:(!:pi(k2 + m), !:bf!-0!.25);    %JBM
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          sign := conv!:i2bf 1;
          if m >= 8 then m := remainder(m, 8);
          if m >= 4 then << sign := minus!: sign; m := m - 4 >>;
          if m >= 2 then sign := minus!: sign;
          if m = 0 then goto cs
           else if m = 1 then goto m1
           else if m = 2 then goto m2
           else goto m3;
      m1: r := cut!:mt(difference!:(pi4, r), k2);
          return times!:(sign, sin!:(r, k));
      m2: r := cut!:mt(r, k2);
          return times!:(sign, sin!:(r, k));
      m3: r := cut!:mt(difference!:(pi4, r), k2);
    cs: begin integer j, n;  scalar dcut, fctrial, ri, tm;
              dcut := make!:bf(10, - k2);
              y := ri := tm := conv!:i2bf 1;
              r := minus!: cut!:ep(times!:(r, r), - k2);
              m := 1;
              j := 0;
              while greaterp!:(abs!: tm, dcut) do
               << j := j + 2;
                  fctrial := conv!:i2bf(m := m * j * (j - 1));
                  ri := cut!:ep(times!:(ri, r), - k2);
                  n := max(1, k2 - order!: fctrial + order!: ri);
                  tm := divide!:(ri, fctrial, n);
                  y := plus!:(y, tm);
                  if zerop remainder(j,20) then y := cut!:ep(y,-k2)>>;
        end;
          return round!:mt(times!:(sign, y), k);
    end$


symbolic procedure tan!:(x, k);
% This function calculates tan(x), the value of
%      the tangent function at the point "x",
%      with the precision K, by calculating
%         sin(x)  or  cos(x) = sin(PI/2-x).
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'tan!:
   else if bfzerop!: x then conv!:i2bf 0
   else if minusp!: x then minus!: tan!:(minus!: x, k)
   else begin integer k2, m;  scalar one, pi4, sign, q, r;
          k2 := k + 2;
          one := conv!:i2bf 1;
          m := preci!: x;
%          pi4 := times!:(!:pi(k2 + m), conv!:s2bf "0.25"); %constant
          pi4 := times!:(!:pi(k2 + m), !:bf!-0!.25);    %JBM
          if lessp!:(x, pi4) then << m := 0; r := x >>
           else << m := conv!:bf2i(q := quotient!:(x, pi4));
                   r := difference!:(x, times!:(q, pi4)) >>;
          if m >= 4 then m := remainder(m, 4);
          if m >= 2 then sign := minus!: one else sign := one;
          if m = 1 or m = 3 then r := difference!:(pi4, r);
          r := cut!:mt(r, k2);
          if m = 0 or m = 3 then goto m03 else goto m12;
     m03: r := sin!:(r, k2);
          q := difference!:(one, times!:(r, r));
          q := sqrt!:(cut!:mt(q, k2), k2);
          return times!:(sign, divide!:(r, q, k));
     m12: r := sin!:(r, k2);
          q := difference!:(one, times!:(r, r));
          q := sqrt!:(cut!:mt(q, k2), k2);
          return times!:(sign, divide!:(q, r, k));
    end$


symbolic procedure asin!:(x, k);
% This function calculates asin(x), the value of
%      the arcsine function at the point "x",
%      with the precision K, by calculating
%         atan(x/SQRT(1-x**2))  by ATAN!:.
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of "x", IxI <= 1,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     greaterp!:(abs!: x, conv!:i2bf 1) or
     not fixp k or k <= 0 then bflerrmsg 'asin!:
   else if minusp!: x then minus!: asin!:(minus!: x, k)
   else begin integer k2;  scalar one, y;
          k2 := k + 2;
          one := conv!:i2bf 1;
          if lessp!:(difference!:(one, x), make!:bf(10, - k2))
%          then return round!:mt(times!:(!:pi(k+1),conv!:s2bf "0.5"),k);
            then return round!:mt(times!:(!:pi add1 k,!:bf!-0!.5),k);
                 %JBM
          y := cut!:mt(difference!:(one, times!:(x, x)), k2);
          y := divide!:(x, sqrt!:(y, k2), k2);
          return atan!:(y, k);
    end$


symbolic procedure acos!:(x, k);
% This function calculates acos(x), the value of
%      the arccosine function at the point "x",
%      with the precision K, by calculating
%         atan(SQRT(1-x**2)/x)  if  x > 0  or
%         atan(SQRT(1-x**2)/x) + PI  if  x < 0.
%      The answer is in the range [0 , PI].
% X is a BIG-FLOAT representation of "x", IxI <= 1,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     greaterp!:(abs!: x, conv!:i2bf 1) or
     not fixp k or k <= 0 then bflerrmsg 'acos!:
   else begin integer k2;  scalar y;
          k2 := k + 2;
          if lessp!:(abs!: x, make!:bf(50, - k2))
%          then return round!:mt(times!:(!:pi(k+1),conv!:s2bf "0.5"),k);
           then return round!:mt(times!:(!:pi add1 k,!:bf!-0!.5),k);
                %JBM
          y := difference!:(conv!:i2bf 1, times!:(x, x));
          y := cut!:mt(y, k2);
          y := divide!:(sqrt!:(y, k2), abs!: x, k2);
          return (if minusp!: x then
                   round!:mt(difference!:(!:pi(k + 1), atan!:(y, k)), k)
                  else atan!:(y, k) );
    end$


symbolic procedure atan!:(x, k);
% This function calculates atan(x), the value of the
%      arctangent function at the point "x", with
%      the precision K, by summing terms of the
%      Taylor series for atan(z)  if  0 < z < 0.42.
%      Otherwise the following identities are used:
%         atan(x) = PI/2 - atan(1/x)  if  1 < x  and
%         atan(x) = 2*atan(x/(1+SQRT(1+x**2)))
%            if  0.42 <= x <= 1.
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'atan!:
   else if bfzerop!: x then conv!:i2bf 0
   else if minusp!: x then minus!: atan!:(minus!: x, k)
   else begin integer k2;  scalar one, pi4, y, z;
          k2 := k + 2;
          one := conv!:i2bf 1;
%          pi4 := times!:(!:pi k2, conv!:s2bf "0.25"); %constant
          pi4 := times!:(!:pi k2, !:bf!-0!.25);    %JBM
          if equal!:(x, one) then return round!:mt(pi4, k);
          if greaterp!:(x, one) then return
           round!:mt(difference!:(plus!:(pi4, pi4),
                                  atan!:(divide!:(one,x,k2),k + 1)),k);
%         if lessp!:(x, conv!:s2bf "0.42") then goto at; %constant
          if lessp!:(x, !:bf!-0!.42) then goto at;    %JBM
          y := plus!:(one, cut!:mt(times!:(x, x), k2));
          y := plus!:(one, sqrt!:(y, k2));
          y := atan!:(divide!:(x, y, k2), k + 1);
          return round!:mt(times!:(y, conv!:i2bf 2), k);
    at: begin integer m, n, ncut;  scalar dcut, tm, zi;
              ncut := k2 - min(0, order!: x + 1);
              y := tm := zi := x;
              z := minus!: cut!:ep(times!:(x, x), - ncut);
              dcut := make!:bf(10, - ncut);
              m := 1;
              while greaterp!:(abs!: tm, dcut) do
               << zi := cut!:ep(times!:(zi, z), - ncut);
                  n := max(1, k2 + order!: zi);
                  tm := divide!:(zi, conv!:i2bf(m := m + 2), n);
                  y := plus!:(y, tm);
                  if zerop remainder(m,20) then y := cut!:ep(y,-ncut)>>;
        end;
          return round!:mt(y, k)
    end$


symbolic procedure arcsin!:(x, k);
% This function calculates arcsin(x), the value of
%      the arcsine function at the point "x", with
%      the precision K, by solving
%         x = sin(y)  if  0 < x <= 0.72,  or
%         SQRT(1-x**2) = sin(y)  if  0.72 < x,
%      by Newton's iteration method.
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of "x", IxI <= 1,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     greaterp!:(abs!: x, conv!:i2bf 1) or
     not fixp k or k <= 0 then bflerrmsg 'arcsin!:
   else if bfzerop!: x then conv!:i2bf 0
   else if minusp!: x then minus!: arcsin!:(minus!: x, k)
   else begin integer k2;  scalar dcut, one, pi2, y;
          k2 := k + 2;
          dcut := make!:bf(10, - k2 + order!: x + 1);
          one := conv!:i2bf 1;
%         pi2 := times!:(!:pi(k2 + 2), conv!:s2bf "0.5"); %constant
          pi2 := times!:(!:pi(k2 + 2), !:bf!-0!.5);    %JBM
          if lessp!:(difference!:(one, x), dcut) then
             return round!:mt(pi2, k);
%         if greaterp!:(x, conv!:s2bf "0.72") then goto ac
          if greaterp!:(x, !:bf!-0!.72) then goto ac    %JBM
             else goto as;
      ac: y := cut!:mt(difference!:(one, times!:(x, x)), k2);
          y := arcsin!:(sqrt!:(y, k2), k);
          return round!:mt(difference!:(pi2, y), k);
    as: begin integer nfig,n;  scalar cx, dx, dy, x0;
              dy := one;
              y := x;
              nfig := 1;
              while nfig < k2 or greaterp!:(abs!: dy, dcut) do
               << if (nfig := 2 * nfig) > k2 then nfig := k2;
                  x0 := sin!:(y, nfig);
                  cx := difference!:(one, times!:(x0, x0));
                  cx := cut!:mt(cx, nfig);
                  cx := sqrt!:(cx, nfig);
                  dx := difference!:(x, x0);
                  n := max(1, nfig + order!: dx);
                  dy := divide!:(dx, cx, n);
                  y := plus!:(y, dy) >>;
        end;
          return round!:mt(y, k);
    end$


symbolic procedure arccos!:(x, k);
% This function calculates arccos(x), the value of
%      the arccosine function at the point "x", with
%      the precision K, by calculating
%         arcsin(SQRT(1-x**2))  if  x > 0.72  and
%         PI/2 - arcsin(x)  otherwise  by ARCSIN!:.
%      The answer is in the range [0 , PI].
% X is a BIG-FLOAT representation of "x", IxI <= 1,
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     greaterp!:(abs!: x, conv!:i2bf 1) or
     not fixp k or k <= 0 then bflerrmsg 'arccos!:
%  else if leq!:(x, conv!:s2bf "0.72") then
   else if leq!:(x, !:bf!-0!.72) then    %JBM
             round!:mt(difference!:
%              (times!:(!:pi(k + 1), conv!:s2bf "0.5"),
               (times!:(!:pi add1 k, !:bf!-0!.5),    %JBM
                arcsin!:(x, k) ), k)
          else arcsin!:(sqrt!:(cut!:mt
               (difference!:(conv!:i2bf 1, times!:(x, x)),
                 k + 2), k + 2), k)$


symbolic procedure arctan!:(x, k);
% This function calculates arctan(x), the value of
%      the arctangent function at the point "x",
%      with the precision K, by calculating
%         arcsin(x/SQRT(1+x**2))  by ARCSIN!:
%      The answer is in the range [-PI/2 , PI/2].
% X is a BIG-FLOAT representation of any real "x",
%      otherwise it is converted to a <BIG-FLOAT>.
% K is a positive integer.
  if not bfp!:(x := conv!:a2bf x) or
     not fixp k or k <= 0 then bflerrmsg 'arctan!:
   else if minusp!: x then minus!: arctan!:(minus!: x, k)
   else arcsin!:(divide!:(x, sqrt!:(cut!:mt
          (plus!:(conv!:i2bf 1, times!:(x, x)), k + 2), k + 2), k + 2),
                 k)$


%Miscellaneous constants (added by JBM).

!:bf!-pi := make!:bf(314159265358979323846, -20);

!:bf!-0 := make!:bf(0, 0);

!:bf!-1 := make!:bf(1, 0);

!:bf!-e := make!:bf(271828182845904523536, -20);

!:bf!-0!.5 := conv!:s2bf "0.5";

!:bf!-0!.25 := conv!:s2bf "0.25";

!:bf!-0!.1 := conv!:s2bf "0.1";

!:bf!-1!.72 := conv!:s2bf "1.72";

!:bf!-0!.42 := conv!:s2bf "0.42";

!:bf!-0!.72 := conv!:s2bf "0.72";


endmodule;


module gbf;   % Support for gaussian bigfloats.

% Author: Eberhard Schruefer.

global '(domainlist!*);

fluid '(!*big!_complex);

domainlist!* := union('(!:gbf!:),domainlist!*);

put('big!_complex,'tag,'!:gbf!:);
put('!:gbf!:,'dname,'big!_complex);
put('!:gbf!:,'i2d,'!*i2gbf);
put('!:gbf!:,'minusp,'gbfminusp!:);
put('!:gbf!:,'zerop,'gbfzerop!:);
put('!:gbf!:,'onep,'gbfonep!:);
put('!:gbf!:,'plus,'gbfplus!:);
put('!:gbf!:,'difference,'gbfdifference!:);
put('!:gbf!:,'times,'gbftimes!:);
put('!:gbf!:,'quotient,'gbfquotient!:);
put('!:gbf!:,'rationalizefn,'girationalize!:);
put('!:gbf!:,'prepfn,'gbfprep!:);
put('!:gbf!:,'prifn,'gbfprn!:);
put('!:bf!:,'!:gbf!:,'bf2gbf);
put('!:rn!:,'!:gbf!:,'rn2gbf);
put('!:ft!:,'!:gbf!:,'ft2gbf);
put('!:gbf!:,'!:bf!:,'gbf2bf);
put('!:gbf!:,'cmpxfn,'mkgbf);
put('!:gbf!:,'ivalue,'mkdgbf);
put('!:gbf!:,'realtype,'!:bf!:);
flag('(!:gbf!:),'field);

symbolic procedure mkdgbf u;
   ('!:gbf!: . (i2bf!: 0 . i2bf!: 1)) ./ 1;

smacro procedure mkgbf(rp,ip);
   '!:gbf!: . (rp . ip);

symbolic procedure bf2gbf u; mkgbf(u,i2bf!: 0);

symbolic procedure rn2gbf u; mkgbf(!*rn2bf u,i2bf!: 0);

symbolic procedure ft2gbf u; mkgbf(!*ft2bf u,i2bf!: 0);

symbolic procedure gbf2bf u;
   if bfzerop!: cddr u then cadr u
    else rederr
          "conversion to bigfloat requires zero imaginary part";

symbolic procedure !*i2gbf u;
   '!:gbf!: . (i2bf!: u . i2bf!: 0);

symbolic procedure gbfminusp!: u;
   %this makes not much sense;
   if bfzerop!: cddr u then minusp!: cadr u
    else minusp!: cddr u;

symbolic procedure gbfzerop!: u;
   bfzerop!:(cadr u) and bfzerop!:(cddr u);

symbolic procedure gbfonep!: u;
   bfonep!:(cadr u) and bfzerop!:(cddr u);

symbolic procedure gbfplus!:(u,v);
   mkgbf(bfplus!:(cadr u,cadr v),bfplus!:(cddr u,cddr v));

symbolic procedure gbfdifference!:(u,v);
   mkgbf(tdifference!:(cadr u,cadr v),
         tdifference!:(cddr u,cddr v));

symbolic procedure gbftimes!:(u,v);
   begin scalar r1,i1,r2,i2,rr,ii;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     rr := tdifference!:(ttimes!:(r1,r2),ttimes!:(i1,i2));
     ii := bfplus!:(ttimes!:(r1,i2),ttimes!:(r2,i1));
     return mkgbf(rr,ii)
   end;

symbolic procedure gbfquotient!:(u,v);
   begin scalar r1,i1,r2,i2,rr,ii,d;
     r1 := cadr u; i1 := cddr u;
     r2 := cadr v; i2 := cddr v;
     d := bfplus!:(ttimes!:(r2,r2),ttimes!:(i2,i2));
     rr := bfplus!:(ttimes!:(r1,r2),ttimes!:(i1,i2));
     ii := tdifference!:(ttimes!:(i1,r2),ttimes!:(i2,r1));
     return mkgbf(bfquotient!:(rr,d),bfquotient!:(ii,d))
   end;

symbolic procedure gbfprep!: u; gbfprep1 cdr u;

%symbolic procedure simpgbf u;
   %('!:gbf!: . u) ./ 1;

%put('!:gbf!:,'simpfn,'simpgbf);

symbolic procedure gbfprep1 u;
   if bfzerop!: cdr u then if bfonep!: car u then 1
                            else car u
    else if bfzerop!: car u then if bfonep!: cdr u then 'i
                                  else list('times,cdr u,'i)
    else list('plus,car u,if bfonep!: cdr u then 'i
                           else list('times,cdr u,'i));

symbolic procedure gbfprn!: u;
   (lambda v; if atom v or car v eq 'times
                  or car v memq domainlist!* then maprin v
               else <<prin2!* "("; maprin v; prin2!* ")">>) gbfprep1 u;


%*** elementary functions;

% All functions below return the principal value. Be aware of certain
% pecularities in this respect. E.g. if you raise a complex quantity
% to a complex power and then raise the result to the reciprocal power
% you will not in general obtain the base, since (u**v)**(1/v) is
% different from u in general.

deflist('((e gbfe!*) (pi gbfpi!*)),'!:gbf!:);

symbolic procedure gbfe!*; bf2gbf e!*();

symbolic procedure gbfpi!*; bf2gbf pi!*();

deflist('((expt gbfexpt) (sin gbfsin) (cos gbfcos) (tan gbftan)
          (asin gbfasin) (acos gbfacos) (atan gbfatan)
          (log gbflog)),'!:gbf!:);

symbolic procedure gbfexpt(u,v);
   begin scalar norm,ang,angr;
     norm := sqrt!*(bfplus!:(ttimes!:(cadr u,cadr u),
                             ttimes!:(cddr u,cddr u)));
     ang := bfarg!: u;
     angr := bfplus!:(ttimes!:(cddr v,log!* norm),
                      ttimes!:(cadr v,ang));
     norm := ttimes!:(texpt!:any(norm,cadr v),
                 exp!* ttimes!:('!:bf!: . (-cadddr v) . cddddr v,ang));
     return mkgbf(ttimes!:(norm,cos!* angr),
                  ttimes!:(norm,sin!* angr))
   end;

symbolic procedure bfarg!: u;
   % Returns bfarg u in the range (-pi,+pi), as a bigfloat.
   (lambda x,y;
      if bfzerop!: y then if minusp!: x then pi!*()
                           else i2bf!: 0
       else if bfzerop!: x then if minusp!: y then
                                    ttimes!:(pi!*(),conv!:a2bf(-0.5))
                                 else ttimes!:(pi!*(),conv!:a2bf 0.5)
       else if minusp!: x and minusp!: y then
               tdifference!:(atan!*(bfquotient!:(y,x)),pi!*())
       else if minusp!: x and not minusp!: y then
               bfplus!:(atan!*(bfquotient!:(y,x)),pi!*())
       else atan!*(bfquotient!:(y,x))) (cadr u,cddr u);

%put('bfarg,'polyfn,'bfarg!:); %make it available to algebraic mode;

symbolic procedure gbfsin u;
   mkgbf(ttimes!:(sin!* cadr u,cosh!* cddr u),
         ttimes!:(cos!* cadr u,sinh!* cddr u));

symbolic procedure gbfcos u;
   mkgbf(ttimes!:(cos!* cadr u,cosh!* cddr u),
        !:minus ttimes!:(sin!* cadr u,sinh!* cddr u));

symbolic procedure gbftan u;
   begin scalar v;
     v := bfplus!:(cos!* ttimes!:(conv!:a2bf 2.0,cadr u),
                   cosh!* ttimes!:(conv!:a2bf 2.0,cddr u));
     return
        mkgbf(bfquotient!:(sin!* ttimes!:(conv!:a2bf 2.0,cadr u),v),
              bfquotient!:(sinh!* ttimes!:(conv!:a2bf 2.0,cddr u),v))
   end;

symbolic procedure gbfasin u;
   begin scalar a,b,c;
     a := ttimes!:(conv!:a2bf 0.5,
       sqrt!*(bfplus!:(texpt!:any(bfplus!:(cadr u,i2bf!: 1),i2bf!: 2),
                       ttimes!:(cddr u,cddr u))));
     b := ttimes!:(conv!:a2bf 0.5,
       sqrt!*(bfplus!:(texpt!:any(bfplus!:(cadr u,i2bf!:(-1)),i2bf!: 2),
                       ttimes!:(cddr u,cddr u))));
     c := bfplus!:(a,b);
     b := tdifference!:(a,b);
     a := c;
     c := bfplus!:(a,sqrt!*(tdifference!:(ttimes!:(a,a),i2bf!: 1)));
     return mkgbf(asin!* b,log!* c)
   end;

symbolic procedure gbfacos u;
   begin scalar a,b,c;
     a := ttimes!:(conv!:a2bf 0.5,
       sqrt!*(bfplus!:(texpt!:any(bfplus!:(cadr u,i2bf!: 1),i2bf!: 2),
                       ttimes!:(cddr u,cddr u))));
     b := ttimes!:(conv!:a2bf 0.5,
       sqrt!*(bfplus!:(texpt!:any(bfplus!:(cadr u,i2bf!:(-1)),i2bf!: 2),
                       ttimes!:(cddr u,cddr u))));
     c := bfplus!:(a,b);
     b := tdifference!:(a,b);
     a := c;
     c := bfplus!:(a,sqrt!*(tdifference!:(ttimes!:(a,a),i2bf!: 1)));
     return mkgbf(acos!* b,ttimes!:(log!* c,i2bf!:(-1)))
   end;

symbolic procedure gbfatan u;
   gbftimes!:(gbflog(gbfquotient!:(
                        gbfplus!:(!*i2gbf 1,gbftimes!:(mkgbf(0,-1),u)),
                        gbfplus!:(!*i2gbf 1,gbftimes!:(mkgbf(0,1),u)))),
              mkgbf(0,conv!:a2bf 0.5));

symbolic procedure gbflog u;
   %Returns the principal value of log u;
   if realp u then mkgbf(log!* u,i2bf!: 0)
    else begin scalar norm;
           norm := sqrt!* bfplus!:(ttimes!:(cadr u,cadr u),
                                   ttimes!:(cddr u,cddr u));
           return mkgbf(log!* norm,bfarg!: u)
         end;

initdmode 'big!_complex;

endmodule;


end;
