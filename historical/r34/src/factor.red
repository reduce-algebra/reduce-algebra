module factor;  % Header for factorizer.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

create!-package('(factor bigmodp degsets facprim facmod facuni % factrr
                  imageset pfactor vecpoly),
                nil);

% Other packages needed.

load!-package 'ezgcd;

for each j in get('factor,'package)
    do put(j,'compiletime,'(setq !*fastfor t));

fluid '(!*ifactor !*overview !*trallfac !*trfac factor!-level
        factor!-trace!-list posn!*);

global '(spare!*);

switch ifactor,overview,trallfac,trfac;

Comment This factorizer should be used with a system dependent file
containing a setting of the variable LARGEST!-SMALL!-MODULUS. If at all
possible the integer arithmetic operations used here should be mapped
onto corresponding ones available in the underlying Lisp implementation,
and the support for modular arithmetic (perhaps based on these integer
arithmetic operations) should be reviewed.  This file provides
placeholder definitions of functions that are used on some
implementations to support block compilation, car/cdr access checks and
the like.  The front-end files on the systems that can use these
features will disable the definitions given here by use of a 'LOSE flag;

deflist('((minus!-one -1)),'newnam);   % So that it EVALs properly.

symbolic smacro procedure carcheck u; nil;

% symbolic smacro procedure irecip u; 1/u;

% symbolic smacro procedure isdomain u; domainp u;

% symbolic smacro procedure readgctime; gctime();

% symbolic smacro procedure readtime; time()-gctime();

% symbolic smacro procedure ttab n; spaces(n-posn());


%   ***** The remainder of this module used to be in FLUIDS.

% Macro definitions for functions that create and access reduce-type
% datastructures.

% smacro procedure polyzerop u; null u;

smacro procedure didntgo q; null q;

% smacro procedure depends!-on!-var(a,v);
%   (lambda !#!#a; (not domainp !#!#a) and (mvar !#!#a=v)) a;

% smacro procedure l!-numeric!-c(a,vlist); lnc a;

% Macro definitions for use in Berlekamp's algorithm.

% Smacros used in linear equation package.

% smacro procedure getm2(a,i,j);
%    % Store by rows, to ease pivoting process.
%    getv(getv(a,i),j);

% smacro procedure putm2(a,i,j,v);
%    putv(getv(a,i),j,v);

smacro procedure !*f2mod u; u;

smacro procedure !*mod2f u; u;

%%%smacro procedure adjoin!-term (p,c,r);
%%%  (lambda !#c!#; % Lambda binding prevents repeated evaluation of C.
%%%    if null !#c!# then r else (p .* !#c!#) .+ r) c;

symbolic smacro procedure get!-f!-numvec s; cadr cddr cdddr s;

% !*overshoot:=nil; % Default not to show overshoot occurring.

% reconstructing!-gcd:=nil;  % This is primarily a factorizer!

symbolic procedure ttab!* n;
<<if n>(linelength nil - spare!*) then n:=0;
  if posn!* > n then terpri!*(nil);
  while not(posn!*=n) do prin2!* '!  >>;

smacro procedure printstr l; << prin2!* l; terpri!*(nil) >>;

smacro procedure printvar v; printstr v;

smacro procedure prinvar v; prin2!* v;

% smacro procedure display!-time(str,mt);
% Displays the string str followed by time mt (millisecs).
%  << prin2 str; prin2 mt; prin2t " millisecs." >>;

% trace control package.

% smacro procedure trace!-time action; if !*timings then action;

smacro procedure new!-level(n,c); (lambda factor!-level; c) n;

symbolic procedure set!-trace!-factor(n,file);
    factor!-trace!-list:=(n . (if file=nil then nil
                               else open(mkfil file,'output))) .
                                                factor!-trace!-list;

symbolic procedure clear!-trace!-factor n;
  begin
    scalar w;
    w := assoc(n,factor!-trace!-list);
    if w then <<
       if cdr w then close cdr w;
       factor!-trace!-list:=delasc(n,factor!-trace!-list) >>;
    return nil
  end; 

symbolic procedure close!-trace!-files();
 << while factor!-trace!-list
       do clear!-trace!-factor(caar factor!-trace!-list);
    nil >>;

endmodule;


module bigmodp; % Modular polynomial arithmetic where the modulus may
                % be a bignum.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

fluid '(current!-modulus modulus!/2);

symbolic smacro procedure comes!-before(p1,p2);
% Similar to the REDUCE function ORDPP, but does not cater for
% non-commutative terms and assumes that exponents are small integers.
    (car p1=car p2 and igreaterp(cdr p1,cdr p2)) or
       (not car p1=car p2 and ordop(car p1,car p2));

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
         adjoin!-term(mksp(tvar term,iplus(tdeg term,ldeg b)),
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
   else if domainp a then !*n2f general!-modular!-times(a,n)
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
      if a>modulus!/2 then !*n2f(a - current!-modulus)
      else a
    else adjoin!-term(lpow a,
                      general!-make!-modular!-symmetric lc a,
                      general!-make!-modular!-symmetric red a);

endmodule;


module degsets;   % Degree set processing.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

fluid '(!*trallfac
        !*trfac
        bad!-case
        best!-set!-pointer
        dpoly
        factor!-level
        factor!-trace!-list
        factored!-lc
        irreducible
        modular!-info
        one!-complete!-deg!-analysis!-done
        previous!-degree!-map
        split!-list
        valid!-image!-sets);

symbolic procedure check!-degree!-sets(n,multivariate!-case);
% MODULAR!-INFO (vector of size N) contains the modular factors now.
  begin scalar degree!-sets,w,x!-is!-factor,degs;
    w:=split!-list;
    for i:=1:n do <<
      if multivariate!-case then
        x!-is!-factor:=not numberp get!-image!-content
          getv(valid!-image!-sets,cdar w);
      degs:=for each v in getv(modular!-info,cdar w) collect ldeg v;
      degree!-sets:=
        (if x!-is!-factor then 1 . degs else degs)
              . degree!-sets;
      w:=cdr w >>;
    check!-degree!-sets!-1 degree!-sets;
    best!-set!-pointer:=cdar split!-list;
    if multivariate!-case and factored!-lc then <<
      while null(w:=get!-f!-numvec
           getv(valid!-image!-sets,best!-set!-pointer))
       and (split!-list:=cdr split!-list) do
        best!-set!-pointer:=cdar split!-list;
      if null w then bad!-case:=t >>;
            % make sure the set is ok for distributing the
            % leading coefft where necessary;
  end;

symbolic procedure check!-degree!-sets!-1 l;
  % L is a list of degree sets. Try to discover if the entries
  % in it are consistent, or if they imply that some of the
  % modular splittings were 'false'.
  begin scalar i,degree!-map,degree!-map1,dpoly,
               plausible!-split!-found,target!-count;
    factor!-trace <<
       prin2t "Degree sets are:";
       for each s in l do <<
          prin2 "     ";
          for each n in s do <<
             prin2 " "; prin2 n >>;
          terpri() >> >>;
    dpoly:=sum!-list car l;
    target!-count:=length car l;
    for each s in cdr l do
        target!-count:=min(target!-count,length s);
    % This used to be IMIN, but since it was the only use, it was
    % eliminated.
    if null previous!-degree!-map then <<
      degree!-map:=mkvect dpoly;
    % To begin with all degrees of factors may be possible;
      for i:=0:dpoly do putv(degree!-map,i,t) >>
    else <<
      factor!-trace "Refine an existing degree map";
      degree!-map:=previous!-degree!-map >>;
    degree!-map1:=mkvect dpoly;
    for each s in l do <<
    % For each degree set S I will collect in DEGREE-MAP1 a
    % bitmap showing what degree factors would be consistent
    % with that set. By ANDing together all these maps
    % (into DEGREE-MAP) I find what degrees for factors are
    % consistent with the whole of the information I have.
      for i:=0:dpoly do putv(degree!-map1,i,nil);
      putv(degree!-map1,0,t);
      putv(degree!-map1,dpoly,t);
      for each d in s do for i:=dpoly#-d#-1 step -1 until 0 do
        if getv(degree!-map1,i) then
           putv(degree!-map1,i#+d,t);
      for i:=0:dpoly do
        putv(degree!-map,i,getv(degree!-map,i) and
             getv(degree!-map1,i)) >>;
    factor!-trace <<
        prin2t "Possible degrees for factors are: ";
        for i:=1:dpoly#-1 do
          if getv(degree!-map,i) then << prin2 i; prin2 " " >>;
        terpri() >>;
    i:=dpoly#-1;
    while i#>0 do if getv(degree!-map,i) then i:=-1
                 else i:=i#-1;
    if i=0 then <<
       factor!-trace
          prin2t "Degree analysis proves polynomial irreducible";
       return irreducible:=t >>;
    for each s in l do if length s=target!-count then begin
      % Sets with too many factors are not plausible anyway.
      i:=s;
      while i and getv(degree!-map,car i) do i:=cdr i;
      % If I drop through with I null it was because the set was
      % consistent, otherwise it represented a false split;
      if null i then plausible!-split!-found:=t end;
    previous!-degree!-map:=degree!-map;
    if plausible!-split!-found or one!-complete!-deg!-analysis!-done
      then return nil;
%    PRINTC "Going to try getting some more images";
    return bad!-case:=t
  end;

symbolic procedure sum!-list l;
   if null cdr l then car l else car l #+ sum!-list cdr l;

endmodule;


module facprim;   % Factorize a primitive multivariate polynomial.

% Author: P. M. A. Moore, 1979.

% Modifications by: Arthur C. Norman, Anthony C. Hearn.

fluid '(!*force!-zero!-set
        !*overshoot
        !*overview
        !*trfac
        alphalist
        alphavec
        bad!-case
        best!-factor!-count
        best!-known!-factors
        best!-modulus
        best!-set!-pointer
        chosen!-prime
        current!-factor!-product
        deltam
        f!-numvec
        factor!-level
        factor!-trace!-list
        factored!-lc
        factorvec
        facvec
        fhatvec
        forbidden!-primes
        forbidden!-sets
        full!-gcd
        hensel!-growth!-size
        image!-content
        image!-factors
        image!-lc
        image!-mod!-p
        image!-poly
        image!-set
        image!-set!-modulus
        input!-leading!-coefficient
        input!-polynomial
        inverted
        inverted!-sign
        irreducible
        known!-factors
        kord!*
        m!-image!-variable
        modfvec
        modular!-info
        multivariate!-factors
        multivariate!-input!-poly
        no!-of!-best!-sets
        no!-of!-primes!-to!-try
        no!-of!-random!-sets
        non!-monic
        null!-space!-basis
        number!-of!-factors
        one!-complete!-deg!-analysis!-done
        othervars
        poly!-mod!-p
        polynomial!-to!-factor
        previous!-degree!-map
        prime!-base
        reconstructing!-gcd
        reduction!-count
        save!-zset
        split!-list
        target!-factor!-count
        true!-leading!-coeffts
        usable!-set!-found
        valid!-image!-sets
        vars!-to!-kill
        zero!-set!-tried
        zerovarset
        zset);

global '(largest!-small!-modulus);


%***********************************************************************
%
%    Primitive multivariate polynomial factorization more or less as
%    described by Paul Wang in:  Math. Comp. vol.32 no.144 oct 1978 pp.
%    1215-1231 'An Improved Multivariate Polynomial Factoring Algorithm'
%
%***********************************************************************

%-----------------------------------------------------------------------
%   This code works by using a local database of fluid variables
%   whose meaning is (hopefully) obvious.
%   they are used as follows:
%
%   global name:            set in:               comments:
%
% m!-factored!-leading!    create!.images        only set if non-numeric
%  -coefft
% m!-factored!-images      factorize!.images     vector
% m!-input!-polynomial     factorize!-primitive!
%                           -polynomial
% m!-best!-image!-pointer  choose!.best!.image
% m!-image!-factors        choose!.best!.image   vector
% m!-true!-leading!        choose!.best!.image   vector
%  -coeffts
% m!-prime                 choose!.best!.image
% irreducible              factorize!.images     predicate
% inverted                 create!.images        predicate
% m!-inverted!-sign        create!-images        +1 or -1
% non!-monic               determine!-leading!   predicate
%                           -coeffts
%                          (also reconstruct!-over!
%                           -integers)
% m!-number!-of!-factors   choose!.best!.image
% m!-image!-variable       square!.free!.factorize
%                          or factorize!-form
% m!-image!-sets           create!.images        vector
% this last contains the images of m!-input!-polynomial and the
% numbers associated with the factors of lc m!-input!-polynomial (to be
% used later) the latter existing only when the lc m!-input!-polynomial
% is non-integral. ie.:
%    m!-image!-sets=< ... , (( d . u ), a, d) , ... >   ( a vector)
% where: a = an image set (=association list);
%        d = cont(m!-input!-polynomial image wrt a);
%        u = prim.part.(same) which is non-trivial square-free
%            by choice of image set.;
%        d = vector of numbers associated with factors in lc
%            m!-input!-polynomial (these depend on a as well);
% the number of entries in m!-image!-sets is defined by the fluid
% variable, no.of.random.sets.


%***********************************************************************
% Multivariate factorization part 1. entry point for this code:
% (** NB ** the polynomial is assumed to be non-trivial, primitive and
% square free.)
%***********************************************************************

symbolic procedure factorize!-primitive!-polynomial u;
% U is primitive square free and at least linear in
% m!-image!-variable. M!-image!-variable is the variable preserved in
% the univariate images. This function determines a random set of
% integers and a prime to create a univariate modular image of u,
% factorize it and determine the leading coeffts of the factors in the
% full factorization of u. Finally the modular image factors are grown
% up to the full multivariates ones using the hensel construction.
% Result is simple list of irreducible factors.
  if not(m!-image!-variable eq mvar u) then errach "factorize variable"
   else if degree!-in!-variable(u,m!-image!-variable) = 1 then list u
   else if degree!-in!-variable(u,m!-image!-variable) = 2
    then factorize!-quadratic u
   else if fac!-univariatep u then univariate!-factorize u
   else begin scalar
    valid!-image!-sets,factored!-lc,image!-factors,prime!-base,
    one!-complete!-deg!-analysis!-done,zset,zerovarset,othervars,
    multivariate!-input!-poly,best!-set!-pointer,reduction!-count,
    true!-leading!-coeffts,number!-of!-factors,
    inverted!-sign,irreducible,inverted,vars!-to!-kill,
    forbidden!-sets,zero!-set!-tried,non!-monic,
    no!-of!-best!-sets,no!-of!-random!-sets,bad!-case,
    target!-factor!-count,modular!-info,multivariate!-factors,
    hensel!-growth!-size,alphalist,
    previous!-degree!-map,image!-set!-modulus,
    best!-known!-factors,reconstructing!-gcd,full!-gcd;
%   base!-timer:=time();
%   trace!-time display!-time(
%     " Entered multivariate primitive polynomial code after ",
%     base!-timer - base!-time);
    % Note that this code works by using a local database of fluid
    % variables that are updated by the subroutines directly called
    % here.  This allows for the relatively complicated interaction
    % between flow of data and control that occurs in the factorization
    % algorithm.
    factor!-trace <<
      printstr "From now on we shall refer to this polynomial as U.";
      printstr
         "We now create an image of U by picking suitable values ";
      printstr "for all but one of the variables in U.";
      prin2!* "The variable preserved in the image is ";
      prinvar m!-image!-variable; terpri!*(nil) >>;
    initialize!-fluids u;
            % set up the fluids to start things off.
%   w!-time:=time();
tryagain:
    get!-some!-random!-sets();
    choose!-the!-best!-set();
%     trace!-time <<
%       display!-time("Modular factoring and best set chosen in ",
%         time()-w!-time);
%       w!-time:=time() >>;
      if irreducible then return list u
      else if bad!-case then <<
        if !*overshoot then prin2t "Bad image sets - loop";
        bad!-case:=nil; goto tryagain >>;
    reconstruct!-image!-factors!-over!-integers();
%     trace!-time <<
%       display!-time("Image factors reconstructed in ",time()-w!-time);
%       w!-time:=time() >>;
      if irreducible then return list u
      else if bad!-case then <<
        if !*overshoot then prin2t "Bad image factors - loop";
        bad!-case:=nil; goto tryagain >>;
    determine!.leading!.coeffts();
%     trace!-time <<
%       display!-time("Leading coefficients distributed in ",
%         time()-w!-time);
%       w!-time:=time() >>;
      if irreducible then
        return list u
      else if bad!-case then <<
        if !*overshoot then prin2t "Bad split shown by LC distribution";
        bad!-case:=nil; goto tryagain >>;
    if determine!-more!-coeffts()='done then <<
%     trace!-time <<
%       display!-time("All the coefficients distributed in ",
%         time()-w!-time);
%       w!-time:=time() >>;
      return check!-inverted multivariate!-factors >>;
%   trace!-time <<
%     display!-time("More coefficients distributed in ",
%       time()-w!-time);
%     w!-time:=time() >>;
    reconstruct!-multivariate!-factors(nil);
      if bad!-case and not irreducible then <<
        if !*overshoot then prin2t "Multivariate overshoot - restart";
         bad!-case:=nil; goto tryagain >>;
%     trace!-time
%       display!-time("Multivariate factors reconstructed in ",
%         time()-w!-time);
      if irreducible then return list u;
    return check!-inverted multivariate!-factors
   end;

symbolic procedure check!-inverted multi!-faclist;
  begin scalar inv!.sign,l;
    if inverted then <<
      inv!.sign:=1;
      multi!-faclist:=
        for each x in multi!-faclist collect <<
        l:=invert!.poly(x,m!-image!-variable);
        inv!.sign:=(car l) * inv!.sign;
        cdr l >>;
      if not(inv!.sign=inverted!-sign) then
        errorf list("INVERSION HAS LOST A SIGN",inv!.sign) >>;
      return multivariate!-factors:=multi!-faclist end;

symbolic procedure getcof(p, v, n);
% Get coeff of v^n in p.
% I bet this exists somewhere under a different name....
  if domainp p then if n=0 then p else nil
  else if mvar p = v then
    if ldeg p=n then lc p
    else getcof(red p, v, n)
  else addf(multf((lpow p .* 1) .+ nil, getcof(lc p, v, n)),
            getcof(red p, v, n));
 
symbolic procedure factorize!-quadratic u;
% U is a primitive square-free quadratic. It factors if and only if
% its discriminant is a perfect square.
  begin scalar a, b, c, discr, f1, f2, x;
% I am unreasonably cautious here - I THINK that the image variable
% should be the main var here, but in case things have got themselves
% reordered & to make myself bomb proof against future changes I will
% not assume same.
    a := getcof(u, m!-image!-variable, 2);
    b := getcof(u, m!-image!-variable, 1);
    c := getcof(u, m!-image!-variable, 0);
    if dmode!* = '!:mod!: and current!-modulus = 2 then % problems
       if b=1 and c=1 then return list u; % Irreducible.
    discr := addf(multf(b, b), multf(a, multf(-4, c)));
    discr := sqrtf2 discr;
    if discr=-1 then return list u; % Irreducible.
    x := addf(multf(a, multf(2, !*k2f m!-image!-variable)), b);
    f1 := addf(x, discr);
    f2 := addf(x, negf discr);
    f1 := quotf(f1,
               cdr contents!-with!-respect!-to(f1, m!-image!-variable));
    f2 := quotf(f2,
               cdr contents!-with!-respect!-to(f2, m!-image!-variable));
    return list(f1, f2)
  end;
 
symbolic procedure sqrtd2 d;
% Square root of domain element or -1 if it does not have an exact one.
% Possibly needs upgrades to deal with non-integer domains, e.g. in
% modular arithmetic just half of all values have square roots (= are
% quadratic residues), but finding the roots is (I think) HARD.  In
% floating point it could be taken that all positive values have square
% roots.  Anyway somebody can adjust this as necessary and I think that
% SQRTF2 will then behave properly...
  if d=nil then nil
  else if not fixp d or d<0 then -1
  else begin
    scalar q, r, rold;
    q := pmam!-sqrt d;        % Works even if D is really huge.
    r := q*q-d;
    repeat <<
      rold := abs r;
      q := q - (r+q)/(2*q);   % / truncates, so this rounds to nearest
      r := q*q-d >> until abs r >= rold;
    if r=0 then return q
    else return -1
  end;
 
symbolic procedure pmam!-sqrt n;
   % Find the square root of n and return integer part + 1.  N is fixed
   % pt on input.  As it may be very large, i.e. > largest allowed
   % floating pt number, it is scaled appropriately.
   begin scalar s,ten!*!*6,ten!*!*12,ten!*!*14;
      s:=0;
      ten!*!*6:=10**6;
      ten!*!*12:=ten!*!*6**2;
      ten!*!*14:=100*ten!*!*12;
      while n>ten!*!*14 do << s:=iadd1 s; n:=1+n/ten!*!*12 >>;
      return (fix sqrt float n + 1)*10**(6*s)
   end;

symbolic procedure sqrtf2 p;
% Return square root of the polynomial P if there is an exact one,
% else returns -1 to indicate failure.
  if domainp p then sqrtd2 p
   else begin
    scalar v, d, qlc, q, r, w;
    if not evenp (d := ldeg p) or
       (qlc := sqrtf2 lc p) = -1 then return -1;
    d := d/2;
    v := mvar p;
    q := (mksp(v, d) .* qlc) .+ nil;      % First approx to sqrt(P)
    r := multf(2, q);
    p := red p;                           % Residue
    while not domainp p and
          mvar p = v and
          ldeg p >= d and
          (w := quotf(lt p .+ nil, r)) neq nil do
        <<  p := addf(p, multf(negf w, addf(multf(2, q), w)));
            q := addf(q, w) >>;
    if null p then return q else return -1
  end;

symbolic procedure initialize!-fluids u;
% Set up the fluids to be used in factoring primitive poly.
  begin scalar w,w1;
    if !*force!-zero!-set then <<
      no!-of!-random!-sets:=1;
      no!-of!-best!-sets:=1 >>
    else <<
      no!-of!-random!-sets:=9;
      % we generate this many and calculate their factor counts.
      no!-of!-best!-sets:=5;
            % we find the modular factors of this many.
      >>;
    image!-set!-modulus:=5;
    vars!-to!-kill:=variables!-to!-kill lc u;
    multivariate!-input!-poly:=u;
    no!-of!-primes!-to!-try := 5;
    target!-factor!-count:=degree!-in!-variable(u,m!-image!-variable);
    if not domainp lc multivariate!-input!-poly then
      if domainp (w:=
        trailing!.coefft(multivariate!-input!-poly,
                         m!-image!-variable)) then
    << inverted:=t;
        % note that we are 'inverting' the poly m!-input!-polynomial.
      w1:=invert!.poly(multivariate!-input!-poly,m!-image!-variable);
      multivariate!-input!-poly:=cdr w1;
      inverted!-sign:=car w1;
            % to ease the lc problem, m!-input!-polynomial <- poly
            % produced by taking numerator of (m!-input!-polynomial
            % with 1/m!-image!-variable substituted for
            % m!-image!-variable).
            % m!-inverted!-sign is -1 if we have inverted the sign of
            % the resulting poly to keep it +ve, else +1.
      factor!-trace <<
        prin2!* "The trailing coefficient of U wrt ";
        prinvar m!-image!-variable; prin2!* "(="; prin2!* w;
        printstr ") is purely numeric so we 'invert' U to give: ";
        prin2!* "  U <- "; printsf multivariate!-input!-poly;
        printstr "This simplifies any problems with the leading ";
        printstr "coefficient of U." >>
    >>
    else <<
%     trace!-time prin2t "Factoring the leading coefficient:";
%     wtime:=time();
      factored!-lc:=
        factorize!-form!-recursion lc multivariate!-input!-poly;
%     trace!-time display!-time("Leading coefficient factored in ",
%       time()-wtime);
            % factorize the lc of m!-input!-polynomial completely.
      factor!-trace <<
        printstr
           "The leading coefficient of U is non-trivial so we must ";
        printstr "factor it before we can decide how it is distributed";
        printstr "over the leading coefficients of the factors of U.";
        printstr "So the factors of this leading coefficient are:";
        fac!-printfactors factored!-lc >>
    >>;
   make!-zerovarset vars!-to!-kill;
            % Sets ZEROVARSET and OTHERVARS.
   if null zerovarset then zero!-set!-tried:=t
   else <<
    zset:=make!-zeroset!-list length zerovarset;
    save!-zset:=zset >>
  end;

symbolic procedure variables!-to!-kill lc!-u;
% Picks out all the variables in u except var. Also checks to see if
% any of these divide lc u: if they do they are dotted with t otherwise
% dotted with nil. result is list of these dotted pairs.
  for each w in cdr kord!* collect
    if (domainp lc!-u) or didntgo quotf(lc!-u,!*k2f w) then
       (w . nil) else (w . t);


%***********************************************************************
% Multivariate factorization part 2. Creating image sets and picking
%  the best one.

fluid '(usable!-set!-found);

symbolic procedure get!-some!-random!-sets();
% here we create a number of random sets to make the input
% poly univariate by killing all but 1 of the variables. at
% the same time we pick a random prime to reduce this image
% poly mod p.
  begin scalar image!-set,chosen!-prime,image!-lc,image!-mod!-p,
        image!-content,image!-poly,f!-numvec,forbidden!-primes,i,j,
        usable!-set!-found;
    valid!-image!-sets:=mkvect no!-of!-random!-sets;
    i:=0;
    while i < no!-of!-random!-sets do <<
%     wtime:=time();
      generate!-an!-image!-set!-with!-prime(
        if i<idifference(no!-of!-random!-sets,3) then nil else t);
%     trace!-time
%       display!-time("  Image set generated in ",time()-wtime);
      i:=iadd1 i;
      putv(valid!-image!-sets,i,list(
        image!-set,chosen!-prime,image!-lc,image!-mod!-p,image!-content,
        image!-poly,f!-numvec));
      forbidden!-sets:=image!-set . forbidden!-sets;
      forbidden!-primes:=list chosen!-prime;
      j:=1;
      while (j<3) and (i<no!-of!-random!-sets) do <<
%       wtime:=time();
        image!-mod!-p:=find!-a!-valid!-prime(image!-lc,image!-poly,
          not numberp image!-content);
        if not(image!-mod!-p='not!-square!-free) then <<
%         trace!-time
%           display!-time("  Prime and image mod p found in ",
%             time()-wtime);
          i:=iadd1 i;
          putv(valid!-image!-sets,i,list(
            image!-set,chosen!-prime,image!-lc,image!-mod!-p,
            image!-content,image!-poly,f!-numvec));
          forbidden!-primes:=chosen!-prime . forbidden!-primes >>;
        j:=iadd1 j
        >>
      >>
  end;

symbolic procedure choose!-the!-best!-set();
% Given several random sets we now choose the best by factoring
% each image mod its chosen prime and taking one with the
% lowest factor count as the best for hensel growth.
  begin scalar split!-list,poly!-mod!-p,null!-space!-basis,
               known!-factors,w,n,fnum,remaining!-split!-list;
    modular!-info:=mkvect no!-of!-random!-sets;
%   wtime:=time();
    for i:=1:no!-of!-random!-sets do <<
      w:=getv(valid!-image!-sets,i);
      get!-factor!-count!-mod!-p(i,get!-image!-mod!-p w,
        get!-chosen!-prime w,not numberp get!-image!-content w) >>;
    split!-list:=sort(split!-list,function lessppair);
            % this now contains a list of pairs (m . n) where
            % m is the no: of factors in image no: n. the list
            % is sorted with best split (smallest m) first.
%   trace!-time
%     display!-time("  Factor counts found in ",time()-wtime);
    if caar split!-list = 1 then <<
      irreducible:=t; return nil >>;
    w:=nil;
%   wtime:=time();
    for i:=1:no!-of!-best!-sets do <<
      n:=cdar split!-list;
      get!-factors!-mod!-p(n,
          get!-chosen!-prime getv(valid!-image!-sets,n));
      w:=(car split!-list) . w;
      split!-list:=cdr split!-list >>;
            % pick the best few of these and find out their
            % factors mod p.
%   trace!-time
%     display!-time("  Best factors mod p found in ",time()-wtime);
    remaining!-split!-list:=split!-list;
    split!-list:=reversip w;
            % keep only those images that are fully factored mod p.
%   wtime:=time();
    check!-degree!-sets(no!-of!-best!-sets,t);
            % the best image is pointed at by best!-set!-pointer.
%   trace!-time
%     display!-time("  Degree sets analysed in ",time()-wtime);
            % now if these didn't help try the rest to see
            % if we can avoid finding new image sets altogether:
    if bad!-case then <<
      bad!-case:=nil;
%     wtime:=time();
      while remaining!-split!-list do <<
        n:=cdar remaining!-split!-list;
        get!-factors!-mod!-p(n,
            get!-chosen!-prime getv(valid!-image!-sets,n));
        w:=(car remaining!-split!-list) . w;
        remaining!-split!-list:=cdr remaining!-split!-list >>;
%     trace!-time
%       display!-time("  More sets factored mod p in ",time()-wtime);
      split!-list:=reversip w;
%     wtime:=time();
      check!-degree!-sets(no!-of!-random!-sets - no!-of!-best!-sets,t);
            % best!-set!-pointer hopefully points at the best image.
%     trace!-time
%       display!-time("  More degree sets analysed in ",time()-wtime)
    >>;
    one!-complete!-deg!-analysis!-done:=t;
    factor!-trace <<
      w:=getv(valid!-image!-sets,best!-set!-pointer);
      prin2!* "The chosen image set is:  ";
      for each x in get!-image!-set w do <<
        prinvar car x; prin2!* "="; prin2!* cdr x; prin2!* "; " >>;
      terpri!*(nil);
      prin2!* "and chosen prime is "; printstr get!-chosen!-prime w;
      printstr "Image polynomial (made primitive) = ";
      printsf get!-image!-poly w;
      if not(get!-image!-content w=1) then <<
        prin2!* " with (extracted) content of ";
        printsf get!-image!-content w >>;
      prin2!* "The image polynomial mod "; prin2!* get!-chosen!-prime w;
      printstr ", made monic, is:";
      printsf get!-image!-mod!-p w;
      printstr "and factors of the primitive image mod this prime are:";
      for each x in getv(modular!-info,best!-set!-pointer)
         do printsf x;
      if (fnum:=get!-f!-numvec w) and not !*overview then <<
        printstr "The numeric images of each (square-free) factor of";
        printstr "the leading coefficient of the polynomial are as";
        prin2!* "follows (in order):";
        prin2!* "  ";
        for i:=1:length cdr factored!-lc do <<
          prin2!* getv(fnum,i); prin2!* "; " >>;
        terpri!*(nil) >>
      >>
  end;


%***********************************************************************
% Multivariate factorization part 3. Reconstruction of the
% chosen image over the integers.


symbolic procedure reconstruct!-image!-factors!-over!-integers();
% The Hensel construction from modular case to univariate
% over the integers.
  begin scalar best!-modulus,best!-factor!-count,input!-polynomial,
    input!-leading!-coefficient,best!-known!-factors,s,w,i,
    x!-is!-factor,x!-factor;
    s:=getv(valid!-image!-sets,best!-set!-pointer);
    best!-known!-factors:=getv(modular!-info,best!-set!-pointer);
    best!-modulus:=get!-chosen!-prime s;
    best!-factor!-count:=length best!-known!-factors;
    input!-polynomial:=get!-image!-poly s;
    if ldeg input!-polynomial=1 then
      if not(x!-is!-factor:=not numberp get!-image!-content s) then
        errorf list("Trying to factor a linear image poly: ",
          input!-polynomial)
      else begin scalar brecip,ww,om,x!-mod!-p;
        number!-of!-factors:=2;
        prime!-base:=best!-modulus;
        x!-factor:=!*k2f m!-image!-variable;
        putv(valid!-image!-sets,best!-set!-pointer,
          put!-image!-poly!-and!-content(s,lc get!-image!-content s,
            multf(x!-factor,get!-image!-poly s)));
        om:=set!-modulus best!-modulus;
        brecip:=modular!-reciprocal
          red (ww:=reduce!-mod!-p input!-polynomial);
        x!-mod!-p:=!*f2mod x!-factor;
        alphalist:=list(
          (x!-mod!-p . brecip),
          (ww . modular!-minus modular!-times(brecip,lc ww)));
        do!-quadratic!-growth(list(x!-factor,input!-polynomial),
          list(x!-mod!-p,ww),best!-modulus);
        w:=list input!-polynomial; % All factors apart from X-FACTOR.
        set!-modulus om
      end
    else <<
      input!-leading!-coefficient:=lc input!-polynomial;
      factor!-trace <<
        printstr
           "Next we use the Hensel Construction to grow these modular";
      printstr "factors into factors over the integers." >>;
      w:=reconstruct!.over!.integers();
      if irreducible then return t;
      if (x!-is!-factor:=not numberp get!-image!-content s) then <<
        number!-of!-factors:=length w + 1;
        x!-factor:=!*k2f m!-image!-variable;
        putv(valid!-image!-sets,best!-set!-pointer,
          put!-image!-poly!-and!-content(s,lc get!-image!-content s,
            multf(x!-factor,get!-image!-poly s)));
        fix!-alphas() >>
      else number!-of!-factors:=length w;
      if number!-of!-factors=1 then return irreducible:=t >>;
    if number!-of!-factors>target!-factor!-count then
      return bad!-case:=list get!-image!-set s;
    image!-factors:=mkvect number!-of!-factors;
    i:=1;
    factor!-trace
      printstr "The full factors of the image polynomial are:";
    for each im!-factor in w do <<
      putv(image!-factors,i,im!-factor);
      factor!-trace printsf im!-factor;
      i:=iadd1 i >>;
   if x!-is!-factor then <<
     putv(image!-factors,i,x!-factor);
     factor!-trace <<
       printsf x!-factor;
       printsf get!-image!-content
         getv(valid!-image!-sets,best!-set!-pointer) >> >>
  end;

symbolic procedure do!-quadratic!-growth(flist,modflist,p);
  begin scalar fhatvec,alphavec,factorvec,modfvec,facvec,
    current!-factor!-product,i,deltam,m;
    fhatvec:=mkvect number!-of!-factors;
    alphavec:=mkvect number!-of!-factors;
    factorvec:=mkvect number!-of!-factors;
    modfvec:=mkvect number!-of!-factors;
    facvec:=mkvect number!-of!-factors;
    current!-factor!-product:=1;
    i:=0;
    for each ff in flist do <<
      putv(factorvec,i:=iadd1 i,ff);
      current!-factor!-product:=multf(ff,current!-factor!-product) >>;
    i:=0;
    for each modff in modflist do <<
      putv(modfvec,i:=iadd1 i,modff);
      putv(alphavec,i,cdr get!-alpha modff) >>;
    deltam:=p;
    m:=deltam*deltam;
    while m<largest!-small!-modulus do <<
      quadratic!-step(m,number!-of!-factors);
      m:=m*deltam >>;
    hensel!-growth!-size:=deltam;
    alphalist:=nil;
    for j:=1:number!-of!-factors do
      alphalist:=(reduce!-mod!-p getv(factorvec,j) . getv(alphavec,j))
        . alphalist
  end;

symbolic procedure fix!-alphas();
% We extracted a factor x (where x is the image variable)
% before any alphas were calculated, we now need to put
% back this factor and its coresponding alpha which incidently
% will change the other alphas.
  begin scalar om,f1,x!-factor,a,arecip,b;
    om:=set!-modulus hensel!-growth!-size;
    f1:=reduce!-mod!-p input!-polynomial;
    x!-factor:=!*f2mod !*k2f m!-image!-variable;
    arecip:=modular!-reciprocal
      (a:=evaluate!-mod!-p(f1,m!-image!-variable,0));
    b:=times!-mod!-p(modular!-minus arecip,
      quotfail!-mod!-p(difference!-mod!-p(f1,a),x!-factor));
    alphalist:=(x!-factor . arecip) .
      (for each aa in alphalist collect
        ((car aa) . remainder!-mod!-p(times!-mod!-p(b,cdr aa),car aa)));
    set!-modulus om
  end;


%***********************************************************************
% Multivariate factorization part 4. Determining the leading
%  coefficients.

symbolic procedure determine!.leading!.coeffts();
% This function determines the leading coeffts to all but a constant
% factor which is spread over all of the factors before reconstruction.
  begin scalar delta,c,s;
    s:=getv(valid!-image!-sets,best!-set!-pointer);
    delta:=get!-image!-content s;
            % cont(the m!-input!-polynomial image).
    if not domainp lc multivariate!-input!-poly then
    << true!-leading!-coeffts:=
      distribute!.lc(number!-of!-factors,image!-factors,s,
        factored!-lc);
       if bad!-case then <<
         bad!-case:=list get!-image!-set s;
         target!-factor!-count:=number!-of!-factors - 1;
         if target!-factor!-count=1 then irreducible:=t;
         return bad!-case >>;
       delta:=car true!-leading!-coeffts;
       true!-leading!-coeffts:=cdr true!-leading!-coeffts;
            % if the lc problem exists then use Wang's algorithm to
            % distribute it over the factors.
       if not !*overview then factor!-trace <<
         printstr "We now determine the leading coefficients of the ";
         printstr "factors of U by using the factors of the leading";
         printstr "coefficient of U and their (square-free) images";
         printstr "referred to earlier:";
         for i:=1:number!-of!-factors do <<
           prinsf getv(image!-factors,i);
           prin2!* " with l.c.: ";
           printsf getv(true!-leading!-coeffts,i)
         >> >>;
       if not onep delta then factor!-trace <<
         if !*overview then
        << printstr
              "In determining the leading coefficients of the factors";
           prin2!* "of U, " >>;
         prin2!* "We have an integer factor, ";
         prin2!* delta;
         printstr ", left over that we ";
         printstr "cannot yet distribute correctly." >>
      >>
    else <<
      true!-leading!-coeffts:=mkvect number!-of!-factors;
      for i:=1:number!-of!-factors do
        putv(true!-leading!-coeffts,i,lc getv(image!-factors,i));
      if not onep delta then
        factor!-trace <<
          prin2!* "U has a leading coefficient = ";
          prin2!* delta;
          printstr " which we cannot ";
          printstr "yet distribute correctly over the image factors." >>
      >>;
    if not onep delta then
    << for i:=1:number!-of!-factors do
       << putv(image!-factors,i,multf(delta,getv(image!-factors,i)));
          putv(true!-leading!-coeffts,i,
            multf(delta,getv(true!-leading!-coeffts,i)))
       >>;
       divide!-all!-alphas delta;
       c:=expt(delta,isub1 number!-of!-factors);
       multivariate!-input!-poly:=multf(c,multivariate!-input!-poly);
       non!-monic:=t;
       factor!-trace <<
         printstr "(a) We multiply each of the image factors by the ";
         printstr "absolute value of this constant and multiply";
         prin2!* "U by ";
         if not(number!-of!-factors=2) then
           << prin2!* delta; prin2!* "**";
             prin2!* isub1 number!-of!-factors >>
         else prin2!* delta;
         printstr " giving new image factors";
         printstr "as follows: ";
         for i:=1:number!-of!-factors do
           printsf getv(image!-factors,i)
       >>
    >>;
            % If necessary, fiddle the remaining integer part of the
            % lc of m!-input!-polynomial.
  end;

endmodule;


module facmod; % Modular factorization: discover the factor count mod p.

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(current!-modulus
        dpoly
        dwork1
        dwork2
        known!-factors
        linear!-factors
        m!-image!-variable
        modular!-info
        null!-space!-basis
        number!-needed
        poly!-mod!-p
        poly!-vector
        safe!-flag
        split!-list
        work!-vector1
        work!-vector2);


safe!-flag:= carcheck 0; % For speed of array access - important here.
carcheck 0;              % and again for fasl purposes (in case carcheck
                         % is flagged EVAL).

symbolic procedure get!-factor!-count!-mod!-p
                              (n,poly!-mod!-p,p,x!-is!-factor);
% gets the factor count mod p from the nth image using the
% first half of Berlekamp's method;
  begin scalar old!-m,f!-count;
    old!-m:=set!-modulus p;
%    PRIN2 "prime = ";% prin2t current!-modulus;
%    PRIN2 "degree = ";% prin2t ldeg poly!-mod!-p;
%   trace!-time display!-time("Entered GET-FACTOR-COUNT after ",time());
%   wtime:=time();
    f!-count:=modular!-factor!-count();
%   trace!-time display!-time("Factor count obtained in ",time()-wtime);
    split!-list:=
      ((if x!-is!-factor then car f!-count#+1 else car f!-count) . n)
        . split!-list;
    putv(modular!-info,n,cdr f!-count);
    set!-modulus old!-m
  end;

symbolic procedure modular!-factor!-count();
  begin
    scalar poly!-vector,wvec1,wvec2,x!-to!-p,
      n,w,lin!-f!-count,null!-space!-basis;
    known!-factors:=nil;
    dpoly:=ldeg poly!-mod!-p;
    wvec1:=mkvect (2#*dpoly);
    wvec2:=mkvect (2#*dpoly);
    x!-to!-p:=mkvect dpoly;
    poly!-vector:=mkvect dpoly;
    for i:=0:dpoly do putv(poly!-vector,i,0);
    poly!-to!-vector poly!-mod!-p;
    w:=count!-linear!-factors!-mod!-p(wvec1,wvec2,x!-to!-p);
    lin!-f!-count:=car w;
    if dpoly#<4 then return
       (if dpoly=0 then lin!-f!-count
        else lin!-f!-count#+1) .
        list(lin!-f!-count . cadr w,
             dpoly . poly!-vector,
             nil);
% When I use Berlekamp I certainly know that the polynomial
% involved has no linear factors;
%   wtime:=time();
    null!-space!-basis:=use!-berlekamp(x!-to!-p,caddr w,wvec1);
%   trace!-time display!-time("Berlekamp done in ",time()-wtime);
    n:=lin!-f!-count #+ length null!-space!-basis #+ 1;
            % there is always 1 more factor than the number of
            % null vectors we have picked up;
    return n . list(
     lin!-f!-count . cadr w,
     dpoly . poly!-vector,
     null!-space!-basis)
  end;

%**********************************************************************;
% Extraction of linear factors is done specially;

symbolic procedure count!-linear!-factors!-mod!-p(wvec1,wvec2,x!-to!-p);
% Compute gcd(x**p-x,u). It will be the product of all the
% linear factors of u mod p;
  begin scalar dx!-to!-p,lin!-f!-count,linear!-factors;
    for i:=0:dpoly do putv(wvec2,i,getv(poly!-vector,i));
    dx!-to!-p:=make!-x!-to!-p(current!-modulus,wvec1,x!-to!-p);
    for i:=0:dx!-to!-p do putv(wvec1,i,getv(x!-to!-p,i));
    if dx!-to!-p#<1 then <<
        if dx!-to!-p#<0 then putv(wvec1,0,0);
        putv(wvec1,1,modular!-minus 1);
        dx!-to!-p:=1 >>
    else <<
      putv(wvec1,1,modular!-difference(getv(wvec1,1),1));
      if dx!-to!-p=1 and getv(wvec1,1)=0 then
         if getv(wvec1,0)=0 then dx!-to!-p:=-1
         else dx!-to!-p:=0 >>;
    if dx!-to!-p#<0 then
      lin!-f!-count:=copy!-vector(wvec2,dpoly,wvec1)
    else lin!-f!-count:=gcd!-in!-vector(wvec1,dx!-to!-p,
      wvec2,dpoly);
    linear!-factors:=mkvect lin!-f!-count;
    for i:=0:lin!-f!-count do
      putv(linear!-factors,i,getv(wvec1,i));
    dpoly:=quotfail!-in!-vector(poly!-vector,dpoly,
        linear!-factors,lin!-f!-count);
    return list(lin!-f!-count,linear!-factors,dx!-to!-p)
  end;

symbolic procedure make!-x!-to!-p(p,wvec1,x!-to!-p);
  begin scalar dx!-to!-p,dw1;
    if p#<dpoly then <<
       for i:=0:p#-1 do putv(x!-to!-p,i,0);
       putv(x!-to!-p,p,1);
       return p >>;
    dx!-to!-p:=make!-x!-to!-p(p/2,wvec1,x!-to!-p);
    dw1:=times!-in!-vector(x!-to!-p,dx!-to!-p,x!-to!-p,dx!-to!-p,wvec1);
    dw1:=remainder!-in!-vector(wvec1,dw1,
        poly!-vector,dpoly);
    if not(iremainder(p,2)=0) then <<
       for i:=dw1 step -1 until 0 do
          putv(wvec1,i#+1,getv(wvec1,i));
       putv(wvec1,0,0);
       dw1:=remainder!-in!-vector(wvec1,dw1#+1,
         poly!-vector,dpoly) >>;
    for i:=0:dw1 do putv(x!-to!-p,i,getv(wvec1,i));
    return dw1
  end;

symbolic procedure find!-linear!-factors!-mod!-p(p,n);
% P is a vector representing a polynomial of degree N which has
% only linear factors. Find all the factors and return a list of
% them;
  begin
    scalar root,var,w,vec1;
    if n#<1 then return nil;
    vec1:=mkvect 1;
    putv(vec1,1,1);
    root:=0;
    while (n#>1) and not (root #> current!-modulus) do <<
        w:=evaluate!-in!-vector(p,n,root);
        if w=0 then << %a factor has been found!!;
          if var=nil then
             var:=mksp(m!-image!-variable,1) . 1;
          w:=!*f2mod
            adjoin!-term(car var,cdr var,!*n2f modular!-minus root);
          known!-factors:=w . known!-factors;
          putv(vec1,0,modular!-minus root);
          n:=quotfail!-in!-vector(p,n,vec1,1) >>;
        root:=root#+1 >>;
    known!-factors:=
        vector!-to!-poly(p,n,m!-image!-variable) . known!-factors
  end;


%**********************************************************************;
% Berlekamp's algorithm part 1: find null space basis giving factor
% count;


symbolic procedure use!-berlekamp(x!-to!-p,dx!-to!-p,wvec1);
% Set up a basis for the set of remaining (nonlinear) factors
% using Berlekamp's algorithm;
  begin
    scalar berl!-m,berl!-m!-size,w,dcurrent,current!-power;
    berl!-m!-size:=dpoly#-1;
    berl!-m:=mkvect berl!-m!-size;
    for i:=0:berl!-m!-size do <<
      w:=mkvect berl!-m!-size;
      for j:=0:berl!-m!-size do putv(w,j,0); %initialize to zero;
      putv(berl!-m,i,w) >>;
% Note that column zero of the matrix (as used in the
% standard version of Berlekamp's algorithm) is not in fact
% needed and is not used here;
% I want to set up a matrix that has entries
%  x**p, x**(2*p), ... , x**((n-1)*p)
% as its columns,
% where n is the degree of poly-mod-p
% and all the entries are reduced mod poly-mod-p;
% Since I computed x**p I have taken out some linear factors,
% so reduce it further;
    dx!-to!-p:=remainder!-in!-vector(x!-to!-p,dx!-to!-p,
      poly!-vector,dpoly);
    dcurrent:=0;
    current!-power:=mkvect berl!-m!-size;
    putv(current!-power,0,1);
    for i:=1:berl!-m!-size do <<
       if current!-modulus#>dpoly then
         dcurrent:=times!-in!-vector(
            current!-power,dcurrent,
            x!-to!-p,dx!-to!-p,
            wvec1)
       else << % Multiply by shifting;
         for i:=0:current!-modulus#-1 do
           putv(wvec1,i,0);
         for i:=0:dcurrent do
           putv(wvec1,current!-modulus#+i,
             getv(current!-power,i));
         dcurrent:=dcurrent#+current!-modulus >>;
       dcurrent:=remainder!-in!-vector(
         wvec1,dcurrent,
         poly!-vector,dpoly);
       for j:=0:dcurrent do
          putv(getv(berl!-m,j),i,putv(current!-power,j,
            getv(wvec1,j)));
% also I need to subtract 1 from the diagonal of the matrix;
       putv(getv(berl!-m,i),i,
         modular!-difference(getv(getv(berl!-m,i),i),1)) >>;
%   wtime:=time();
%   print!-m("Q matrix",berl!-m,berl!-m!-size);
    w := find!-null!-space(berl!-m,berl!-m!-size);
%   trace!-time display!-time("Null space found in ",time()-wtime);
    return w
  end;


symbolic procedure find!-null!-space(berl!-m,berl!-m!-size);
% Diagonalize the matrix to find its rank and hence the number of
% factors the input polynomial had;
  begin scalar null!-space!-basis;
% find a basis for the null-space of the matrix;
    for i:=1:berl!-m!-size do
      null!-space!-basis:=
        clear!-column(i,null!-space!-basis,berl!-m,berl!-m!-size);
%    print!-m("Null vectored",berl!-m,berl!-m!-size);
    return
      tidy!-up!-null!-vectors(null!-space!-basis,berl!-m,berl!-m!-size)
  end;

symbolic procedure print!-m(m,berl!-m,berl!-m!-size);
 << prin2t m;
    for i:=0:berl!-m!-size do <<
      for j:=0:berl!-m!-size do <<
        prin2 getv(getv(berl!-m,i),j);
        ttab((4#*j)#+4) >>;
      terpri() >> >>;



symbolic procedure clear!-column(i,
                    null!-space!-basis,berl!-m,berl!-m!-size);
% Process column I of the matrix so that (if possible) it
% just has a '1' in row I and zeros elsewhere;
  begin
    scalar ii,w;
% I want to bring a non-zero pivot to the position (i,i)
% and then add multiples of row i to all other rows to make
% all but the i'th element of column i zero. First look for
% a suitable pivot;
    ii:=0;
search!-for!-pivot:
    if getv(getv(berl!-m,ii),i)=0 or
       ((ii#<i) and not(getv(getv(berl!-m,ii),ii)=0)) then
          if (ii:=ii#+1)#>berl!-m!-size then
              return (i . null!-space!-basis)
          else go to search!-for!-pivot;
% Here ii references a row containing a suitable pivot element for
% column i. Permute rows in the matrix so as to bring the pivot onto
% the diagonal;
    w:=getv(berl!-m,ii);
    putv(berl!-m,ii,getv(berl!-m,i));
    putv(berl!-m,i,w);
            % swop rows ii and i ;
    w:=modular!-minus modular!-reciprocal getv(getv(berl!-m,i),i);
% w = -1/pivot, and is used in zeroing out the rest of column i;
    for row:=0:berl!-m!-size do
      if row neq i then begin
         scalar r; %process one row;
         r:=getv(getv(berl!-m,row),i);
         if not(r=0) then <<
           r:=modular!-times(r,w);
   %that is now the multiple of row i that must be added to row ii;
           for col:=i:berl!-m!-size do
             putv(getv(berl!-m,row),col,
               modular!-plus(getv(getv(berl!-m,row),col),
               modular!-times(r,getv(getv(berl!-m,i),col)))) >>
         end;
    for col:=i:berl!-m!-size do
        putv(getv(berl!-m,i),col,
           modular!-times(getv(getv(berl!-m,i),col),w));
    return null!-space!-basis
  end;


symbolic procedure tidy!-up!-null!-vectors(null!-space!-basis,
                    berl!-m,berl!-m!-size);
  begin
    scalar row!-to!-use;
    row!-to!-use:=berl!-m!-size#+1;
    null!-space!-basis:=
      for each null!-vector in null!-space!-basis collect
        build!-null!-vector(null!-vector,
            getv(berl!-m,row!-to!-use:=row!-to!-use#-1),berl!-m);
    berl!-m:=nil; % Release the store for full matrix;
%    prin2 "Null vectors: ";
%    print null!-space!-basis;
    return null!-space!-basis
  end;

symbolic procedure build!-null!-vector(n,vec,berl!-m);
% At the end of the elimination process (the CLEAR-COLUMN loop)
% certain columns, indicated by the entries in NULL-SPACE-BASIS
% will be null vectors, save for the fact that they need a '1'
% inserted on the diagonal of the matrix. This procedure copies
% these null-vectors into some of the vectors that represented
% rows of the Berlekamp matrix;
  begin
%   putv(vec,0,0); % Not used later!!;
    for i:=1:n#-1 do
      putv(vec,i,getv(getv(berl!-m,i),n));
    putv(vec,n,1);
%   for i:=n#+1:berl!-m!-size do
%     putv(vec,i,0);
    return vec . n
  end;



%**********************************************************************;
% Berlekamp's algorithm part 2: retrieving the factors mod p;


symbolic procedure get!-factors!-mod!-p(n,p);
% given the modular info (for the nth image) generated by the
% previous half of Berlekamp's method we can reconstruct the
% actual factors mod p;
  begin scalar nth!-modular!-info,old!-m;
    nth!-modular!-info:=getv(modular!-info,n);
    old!-m:=set!-modulus p;
%   wtime:=time();
    putv(modular!-info,n,
      convert!-null!-vectors!-to!-factors nth!-modular!-info);
%   trace!-time display!-time("Factors constructed in ",time()-wtime);
    set!-modulus old!-m
  end;

symbolic procedure convert!-null!-vectors!-to!-factors m!-info;
% Using the null space found, complete the job
% of finding modular factors by taking gcd's of the
% modular input polynomial and variants on the
% null space generators;
  begin
    scalar number!-needed,factors,
      work!-vector1,dwork1,work!-vector2,dwork2;
    known!-factors:=nil;
%   wtime:=time();
    find!-linear!-factors!-mod!-p(cdar m!-info,caar m!-info);
%   trace!-time display!-time("Linear factors found in ",time()-wtime);
    dpoly:=caadr m!-info;
    poly!-vector:=cdadr m!-info;
    null!-space!-basis:=caddr m!-info;
    if dpoly=0 then return known!-factors; % All factors were linear;
    if null null!-space!-basis then
      return known!-factors:=
          vector!-to!-poly(poly!-vector,dpoly,m!-image!-variable) .
            known!-factors;
    number!-needed:=length null!-space!-basis;
% count showing how many more factors I need to find;
    work!-vector1:=mkvect dpoly;
    work!-vector2:=mkvect dpoly;
    factors:=list (poly!-vector . dpoly);
try!-next!-null:
    if null!-space!-basis=nil then
      errorf "RAN OUT OF NULL VECTORS TOO EARLY";
%   wtime:=time();
    factors:=try!-all!-constants(factors,
        caar null!-space!-basis,cdar null!-space!-basis);
%   trace!-time display!-time("All constants tried in ",time()-wtime);
    if number!-needed=0 then
       return known!-factors:=append!-new!-factors(factors,
            known!-factors);
    null!-space!-basis:=cdr null!-space!-basis;
    go to try!-next!-null
  end;


symbolic procedure try!-all!-constants(list!-of!-polys,v,dv);
% use gcd's of v, v+1, v+2, ... to try to split up the
% polynomials in the given list;
  begin
    scalar a,b,aa,s;
% aa is a list of factors that can not be improved using this v,
% b is a list that might be;
    aa:=nil; b:=list!-of!-polys;
    s:=0;
try!-next!-constant:
    putv(v,0,s); % Fix constant term of V to be S;
%    wtime:=time();
    a:=split!-further(b,v,dv);
%    trace!-time display!-time("Polys split further in ",time()-wtime);
    b:=cdr a; a:=car a;
    aa:=nconc(a,aa);
% Keep aa up to date as a list of polynomials that this poly
% v can not help further with;
    if b=nil then return aa; % no more progress possible here;
    if number!-needed=0 then return nconc(b,aa);
      % no more progress needed;
    s:=s#+1;
    if s#<current!-modulus then go to try!-next!-constant;
% Here I have run out of choices for the constant
% coefficient in v without splitting everything;
    return nconc(b,aa)
  end;

symbolic procedure split!-further(list!-of!-polys,v,dv);
% list-of-polys is a list of polynomials. try to split
% its members further by taking gcd's with the polynomial
% v. return (a . b) where the polys in a can not possibly
% be split using v+constant, but the polys in b might
% be;
    if null list!-of!-polys then nil . nil
    else begin
      scalar a,b,gg,q;
      a:=split!-further(cdr list!-of!-polys,v,dv);
      b:=cdr a; a:=car a;
      if number!-needed=0 then go to no!-split;
      % if all required factors have been found there is no need to
      % search further;
      dwork1:=copy!-vector(v,dv,work!-vector1);
      dwork2:=copy!-vector(caar list!-of!-polys,cdar list!-of!-polys,
        work!-vector2);
      dwork1:=gcd!-in!-vector(work!-vector1,dwork1,
         work!-vector2,dwork2);
      if dwork1=0 or dwork1=cdar list!-of!-polys then go to no!-split;
      dwork2:=copy!-vector(caar list!-of!-polys,cdar list!-of!-polys,
        work!-vector2);
      dwork2:=quotfail!-in!-vector(work!-vector2,dwork2,
        work!-vector1,dwork1);
% Here I have a splitting;
      gg:=mkvect dwork1;
      copy!-vector(work!-vector1,dwork1,gg);
      a:=((gg . dwork1) . a);
      copy!-vector(work!-vector2,dwork2,q:=mkvect dwork2);
      b:=((q . dwork2) . b);
      number!-needed:=number!-needed#-1;
      return (a . b);
   no!-split:
      return (a . ((car list!-of!-polys) . b))
    end;

symbolic procedure append!-new!-factors(a,b);
% Convert to REDUCE (rather than vector) form;
    if null a then b
    else
      vector!-to!-poly(caar a,cdar a,m!-image!-variable) .
        append!-new!-factors(cdr a,b);



carcheck safe!-flag; % Restore status quo.

endmodule;


module facuni;

% Authors: A. C. Norman and P. M. A. Moore, 1979;

fluid '(!*force!-prime
        !*trfac
        alphalist
        bad!-case
        best!-factor!-count
        best!-known!-factors
        best!-modulus
        best!-set!-pointer
        chosen!-prime
        factor!-level
        factor!-trace!-list
        forbidden!-primes
        hensel!-growth!-size
        input!-leading!-coefficient
        input!-polynomial
        irreducible
        known!-factors
        m!-image!-variable
        modular!-info
        no!-of!-best!-primes
        no!-of!-random!-primes
        non!-monic
        null!-space!-basis
        number!-of!-factors
        one!-complete!-deg!-analysis!-done
        poly!-mod!-p
        previous!-degree!-map
        reduction!-count
        split!-list
        target!-factor!-count
        univariate!-factors
        univariate!-input!-poly
        valid!-primes);


symbolic procedure univariate!-factorize poly;
% input poly a primitive square-free univariate polynomial at least
% quadratic and with +ve lc.  output is a list of the factors of poly
% over the integers ;
  if testx!*!*n!+1 poly then
    factorizex!*!*n!+1(m!-image!-variable,ldeg poly,1)
  else if testx!*!*n!-1 poly then
    factorizex!*!*n!-1(m!-image!-variable,ldeg poly,1)
  else univariate!-factorize1 poly;

symbolic procedure univariate!-factorize1 poly;
  begin scalar
    valid!-primes,univariate!-input!-poly,best!-set!-pointer,
    number!-of!-factors,irreducible,forbidden!-primes,
    no!-of!-best!-primes,no!-of!-random!-primes,bad!-case,
    target!-factor!-count,modular!-info,univariate!-factors,
    hensel!-growth!-size,alphalist,previous!-degree!-map,
    one!-complete!-deg!-analysis!-done,reduction!-count,
    multivariate!-input!-poly;
%note that this code works by using a local database of
%fluid variables that are updated by the subroutines directly
%called here. this allows for the relativly complicated
%interaction between flow of data and control that occurs in
%the factorization algorithm;
    factor!-trace <<
      prin2!* "Univariate polynomial="; printsf poly;
      printstr
         "The polynomial is univariate, primitive and square-free";
      printstr "so we can treat it slightly more specifically. We";
      printstr "factorise mod several primes,then pick the best one";
      printstr "to use in the Hensel construction." >>;
    initialize!-univariate!-fluids poly;
            % set up the fluids to start things off;
tryagain:
    get!-some!-random!-primes();
    choose!-the!-best!-prime();
      if irreducible then <<
        univariate!-factors:=list univariate!-input!-poly;
        goto exit >>
      else if bad!-case then <<
        bad!-case:=nil; goto tryagain >>;
    reconstruct!-factors!-over!-integers();
      if irreducible then <<
        univariate!-factors:=list univariate!-input!-poly;
        goto exit >>;
exit:
    factor!-trace <<
      printstr "The univariate factors are:";
      for each ff in univariate!-factors do printsf ff >>;
    return univariate!-factors
   end;


%**********************************************************************
% univariate factorization part 1. initialization and setting fluids;


symbolic procedure initialize!-univariate!-fluids u;
% Set up the fluids to be used in factoring primitive poly;
  begin
    if !*force!-prime then <<
      no!-of!-random!-primes:=1;
      no!-of!-best!-primes:=1 >>
    else <<
      no!-of!-random!-primes:=5;
            % we generate this many modular images and calculate
            % their factor counts;
      no!-of!-best!-primes:=3;
            % we find the modular factors of this many;
      >>;
    univariate!-input!-poly:=u;
    target!-factor!-count:=ldeg u
  end;


%**********************************************************************;
% univariate factorization part 2. creating modular images and picking
%  the best one;


symbolic procedure get!-some!-random!-primes();
% here we create a number of random primes to reduce the input mod p;
  begin scalar chosen!-prime,poly!-mod!-p,i;
    valid!-primes:=mkvect no!-of!-random!-primes;
    i:=0;
    while i < no!-of!-random!-primes do <<
      poly!-mod!-p:=
        find!-a!-valid!-prime(lc univariate!-input!-poly,
                    univariate!-input!-poly,nil);
      if not(poly!-mod!-p='not!-square!-free) then <<
        i:=iadd1 i;
        putv(valid!-primes,i,chosen!-prime . poly!-mod!-p);
        forbidden!-primes:=chosen!-prime . forbidden!-primes
        >>
      >>
  end;

symbolic procedure choose!-the!-best!-prime();
% given several random primes we now choose the best by factoring
% the poly mod its chosen prime and taking one with the
% lowest factor count as the best for hensel growth;
  begin scalar split!-list,poly!-mod!-p,null!-space!-basis,
               known!-factors,w,n;
    modular!-info:=mkvect no!-of!-random!-primes;
    for i:=1:no!-of!-random!-primes do <<
      w:=getv(valid!-primes,i);
      get!-factor!-count!-mod!-p(i,cdr w,car w,nil) >>;
    split!-list:=sort(split!-list,function lessppair);
            % this now contains a list of pairs (m . n) where
            % m is the no: of factors in set no: n. the list
            % is sorted with best split (smallest m) first;
    if caar split!-list = 1 then <<
      irreducible:=t; return nil >>;
    w:=split!-list;
    for i:=1:no!-of!-best!-primes do <<
      n:=cdar w;
      get!-factors!-mod!-p(n,car getv(valid!-primes,n));
      w:=cdr w >>;
            % pick the best few of these and find out their
            % factors mod p;
    split!-list:=delete(w,split!-list);
            % throw away the other sets;
    check!-degree!-sets(no!-of!-best!-primes,nil);
            % the best set is pointed at by best!-set!-pointer;
    one!-complete!-deg!-analysis!-done:=t;
    factor!-trace <<
      w:=getv(valid!-primes,best!-set!-pointer);
      prin2!* "The chosen prime is "; printstr car w;
      prin2!* "The polynomial mod "; prin2!* car w;
      printstr ", made monic, is:";
      printsf cdr w;
      printstr "and the factors of this modular polynomial are:";
      for each x in getv(modular!-info,best!-set!-pointer)
         do printsf x;
      >>
  end;



%**********************************************************************;
% univariate factorization part 3. reconstruction of the
% chosen image over the integers;


symbolic procedure reconstruct!-factors!-over!-integers();
% the hensel construction from modular case to univariate
% over the integers;
  begin scalar best!-modulus,best!-factor!-count,input!-polynomial,
    input!-leading!-coefficient,best!-known!-factors,s;
    s:=getv(valid!-primes,best!-set!-pointer);
    best!-known!-factors:=getv(modular!-info,best!-set!-pointer);
    input!-leading!-coefficient:=lc univariate!-input!-poly;
    best!-modulus:=car s;
    best!-factor!-count:=length best!-known!-factors;
    input!-polynomial:=univariate!-input!-poly;
    univariate!-factors:=reconstruct!.over!.integers();
    if irreducible then return t;
    number!-of!-factors:=length univariate!-factors;
    if number!-of!-factors=1 then return irreducible:=t
  end;


symbolic procedure reconstruct!.over!.integers();
  begin scalar w,lclist,non!-monic;
    set!-modulus best!-modulus;
    for i:=1:best!-factor!-count do
      lclist:=input!-leading!-coefficient . lclist;
    if not (input!-leading!-coefficient=1) then <<
      best!-known!-factors:=
        for each ff in best!-known!-factors collect
          multf(input!-leading!-coefficient,!*mod2f ff);
      non!-monic:=t;
      factor!-trace <<
        printstr
           "(a) Now the polynomial is not monic so we multiply each";
        printstr
           "of the modular factors, f(i), by the absolute value of";
        prin2!* "the leading coefficient: ";
        prin2!* input!-leading!-coefficient; printstr '!.;
        printstr "To bring the polynomial into agreement with this, we";
        prin2!* "multiply it by ";
        if best!-factor!-count > 2 then
          << prin2!* input!-leading!-coefficient; prin2!* "**";
            printstr isub1 best!-factor!-count >>
        else printstr input!-leading!-coefficient >> >>;
    w:=uhensel!.extend(input!-polynomial,
      best!-known!-factors,lclist,best!-modulus);
    if irreducible then return t;
    if car w ='ok then return cdr w
    else errorf w
  end;


% Now some special treatment for cyclotomic polynomials;

symbolic procedure testx!*!*n!+1 u;
  not domainp u and (
    lc u=1 and
    red u = 1);


symbolic procedure testx!*!*n!-1 u;
  not domainp u and (
    lc u=1 and
    red u = -1);


symbolic procedure factorizex!*!*n!+1(var,degree,vorder);
% Deliver factors of (VAR**VORDER)**DEGREE+1 given that it is
% appropriate to treat VAR**VORDER as a kernel;
  if evenp degree then factorizex!*!*n!+1(var,degree/2,2*vorder)
  else begin
    scalar w;
    w := factorizex!*!*n!-1(var,degree,vorder);
    w := negf car w . cdr w;
    return for each p in w collect negate!-variable(var,2*vorder,p)
  end;

symbolic procedure negate!-variable(var,vorder,p);
% VAR**(VORDER/2) -> -VAR**(VORDER/2) in the polynomial P;
  if domainp p then p
  else if mvar p=var then
    if remainder(ldeg p,vorder)=0 then
            lt p .+ negate!-variable(var,vorder,red p)
    else (lpow p .* negf lc p) .+ negate!-variable(var,vorder,red p)
  else (lpow p .* negate!-variable(var,vorder,lc p)) .+
        negate!-variable(var,vorder,red p);


symbolic procedure integer!-factors n;
% Return integer factors of N, with attached multiplicities. Assumes
% that N is fairly small;
  begin
    scalar l,q,m,w;
% L is list of results generated so far, Q is current test divisor,
% and M is associated multiplicity;
    if n=1 then return '((1 . 1));
    q := 2; m := 0;
    % Test divide by 2,3,5,7,9,11,13,...
top:
    w := divide(n,q);
    while cdr w=0 do << n := car w; w := divide(n,q); m := m+1 >>;
    if not m=0 then l := (q . m) . l;
    if q>car w then <<
      if not n=1 then l := (n . 1) . l;
      return reversip l >>;
%   q := ilogor(1,iadd1 q);
    q := iadd1 q;
    if q #> 3 then q := iadd1 q;
    m := 0;
    go to top
  end;


symbolic procedure factored!-divisors fl;
% FL is an association list of primes and exponents. Return a list
% of all subsets of this list, i.e. of numbers dividing the
% original integer. Exclude '1' from the list;
  if null fl then nil
  else begin
    scalar l,w;
    w := factored!-divisors cdr fl;
    l := w;
    for i := 1:cdar fl do <<
      l := list (caar fl . i) . l;
      for each p in w do
        l := ((caar fl . i) . p) . l >>;
    return l
  end;

symbolic procedure factorizex!*!*n!-1(var,degree,vorder);
  if evenp degree then append(factorizex!*!*n!+1(var,degree/2,vorder),
                              factorizex!*!*n!-1(var,degree/2,vorder))
  else if degree=1 then list((mksp(var,vorder) .* 1) .+ (-1))
  else begin
    scalar facdeg;
    facdeg := '((1 . 1)) . factored!-divisors integer!-factors degree;
    return for each fl in facdeg
       collect cyclotomic!-polynomial(var,fl,vorder)
  end;

symbolic procedure cyclotomic!-polynomial(var,fl,vorder);
% Create Psi<degree>(var**order)
% where degree is given by the association list of primes and
% multiplicities FL;
  if not cdar fl=1 then
    cyclotomic!-polynomial(var,(caar fl . sub1 cdar fl) . cdr fl,
                           vorder*caar fl)
  else if cdr fl=nil then
     if caar fl=1 then (mksp(var,vorder) .* 1) .+ (-1)
     else quotfail((mksp(var,vorder*caar fl) .* 1) .+ (-1),
                   (mksp(var,vorder) .* 1) .+ (-1))
  else quotfail(cyclotomic!-polynomial(var,cdr fl,vorder*caar fl),
                cyclotomic!-polynomial(var,cdr fl,vorder));



endmodule;


module imageset;

% Authors: A. C. Norman and P. M. A. Moore, 1979;

fluid '(!*force!-prime
        !*force!-zero!-set
        !*trfac
        bad!-case
        chosen!-prime
        current!-modulus
        f!-numvec
        factor!-level
        factor!-trace!-list
        factor!-x
        factored!-lc
        forbidden!-primes
        forbidden!-sets
        image!-content
        image!-lc
        image!-mod!-p
        image!-poly
        image!-set
        image!-set!-modulus
        kord!*
        m!-image!-variable
        modulus!/2
        multivariate!-input!-poly
        no!-of!-primes!-to!-try
        othervars
        polyzero
        save!-zset
        usable!-set!-found
        vars!-to!-kill
        zero!-set!-tried
        zerovarset
        zset);


%*******************************************************************;
%
%      this section deals with the image sets used in
%      factorising multivariate polynomials according
%      to wang's theories.
%       ref:  math. comp. vol.32 no.144 oct 1978 pp 1217-1220
%        'an improved multivariate polynomial factoring algorithm'
%
%*******************************************************************;


%*******************************************************************;
%    first we have routines for generating the sets
%*******************************************************************;


symbolic procedure generate!-an!-image!-set!-with!-prime
                      good!-set!-needed;
% given a multivariate poly (in a fluid) we generate an image set
% to make it univariate and also a random prime to use in the
% modular factorization. these numbers are random except that
% we will not allow anything in forbidden!-sets or forbidden!-primes;
  begin scalar currently!-forbidden!-sets,u;
    u:=multivariate!-input!-poly;
            % a bit of a handful to type otherwise!!!!   ;
    image!-set:=nil;
    currently!-forbidden!-sets:=forbidden!-sets;
tryanotherset:
    if image!-set then
      currently!-forbidden!-sets:=image!-set .
                                currently!-forbidden!-sets;
%   wtime:=time();
    image!-set:=get!-new!-set currently!-forbidden!-sets;
%           princ "Trying imageset= ";
%           prin2t image!-set;
%   trace!-time <<
%     display!-time("    New image set found in ",time()-wtime);
%     wtime:=time() >>;
    image!-lc:=make!-image!-lc!-list(lc u,image!-set);
            % list of image lc's wrt different variables in IMAGE-SET;
%    princ "Image set to try is:";% prin2t image!-set;
%    prin2!* "L.C. of poly is:";% printsf lc u;
%    prin2t "Image l.c.s with variables substituted on order:";
%    for each imlc in image!-lc do printsf imlc;
%   trace!-time
%     display!-time("    Image of lc made in ",time()-wtime);
    if (caar image!-lc)=0 then goto tryanotherset;
%   wtime:=time();
    image!-poly:=make!-image(u,image!-set);
%   trace!-time <<
%     display!-time("    Image poly made in ",time()-wtime);
%     wtime:=time() >>;
    image!-content:=get!.content image!-poly;
            % note: the content contains the image variable if it
            % is a factor of the image poly;
%   trace!-time
%     display!-time("    Content found in ",time()-wtime);
    image!-poly:=quotfail(image!-poly,image!-content);
            % make sure the image polynomial is primitive which includes
            % making the leading coefft positive (-ve content if
            % necessary).
            % If the image polynomial was of the form k*v^2 where v is
            % the image variable then GET.CONTENT will have taken out
            % one v and the k leaving the polynomial v here.
            % Divisibility by v here thus indicates that the image was
            % not square free, and so we will not be able to find a
            % sensible prime to use.
    if not didntgo quotf(image!-poly,!*k2f m!-image!-variable) then
        go to tryanotherset;
%   wtime:=time();
    image!-mod!-p:=find!-a!-valid!-prime(image!-lc,image!-poly,
      not numberp image!-content);
    if image!-mod!-p='not!-square!-free then goto tryanotherset;
%   trace!-time <<
%     display!-time("    Prime and image mod p found in ",time()-wtime);
%     wtime:=time() >>;
    if factored!-lc then
      if f!-numvec:=unique!-f!-nos(factored!-lc,image!-content,
          image!-set) then usable!-set!-found:=t
%       trace!-time
%         display!-time("    Nos for lc found in ",time()-wtime) >>
      else <<
%       trace!-time display!-time("    Nos for lc failed in ",
%           time()-wtime);
        if (not usable!-set!-found) and good!-set!-needed then
          goto tryanotherset >>
  end;


symbolic procedure get!-new!-set forbidden!-s;
% associate each variable in vars-to-kill with a random no. mod
% image-set-modulus. If the boolean tagged with a variable is true then
% a value of 1 or 0 is no good and so rejected, however all other
% variables can take these values so they are tried exhaustively before
% using truly random values. sets in forbidden!-s not allowed;
  begin scalar old!.m,alist,n,nextzset,w;
    if zero!-set!-tried then <<
      if !*force!-zero!-set then
        errorf "Zero set tried - possibly it was invalid";
      image!-set!-modulus:=iadd1 image!-set!-modulus;
      old!.m:=set!-modulus image!-set!-modulus;
      alist:=for each v in vars!-to!-kill collect
      << n:=modular!-number next!-random!-number();
         if n>modulus!/2 then n:=n-current!-modulus;
         if cdr v then <<
           while n=0
              or n=1
              or (n = (isub1 current!-modulus)) do
             n:=modular!-number next!-random!-number();
           if n>modulus!/2 then n:=n-current!-modulus >>;
         car v . n >> >>
    else <<
      old!.m:=set!-modulus image!-set!-modulus;
      nextzset:=car zset;
      alist:=for each zv in zerovarset collect <<
        w:=zv . car nextzset;
        nextzset:=cdr nextzset;
        w >>;
      if othervars then alist:=
        append(alist,for each v in othervars collect <<
          n:=modular!-number next!-random!-number();
          while n=0
             or n=1
             or (n = (isub1 current!-modulus)) do
            n:=modular!-number next!-random!-number();
          if n>modulus!/2 then n:=n-current!-modulus;
          v . n >>);
      if null(zset:=cdr zset) then
        if null save!-zset then zero!-set!-tried:=t
        else zset:=make!-next!-zset save!-zset;
      alist:=for each v in cdr kord!* collect atsoc(v,alist);
            % Puts the variables in alist in the right order;
      >>;
    set!-modulus old!.m;
    return if member(alist,forbidden!-s) then
        get!-new!-set forbidden!-s
      else alist
  end;


%**********************************************************************
% now given an image/univariate polynomial find a suitable random prime;


symbolic procedure find!-a!-valid!-prime(lc!-u,u,factor!-x);
% finds a suitable random prime for reducing a poly mod p.
% u is the image/univariate poly. we are not allowed to use
% any of the primes in forbidden!-primes (fluid).
% lc!-u is either numeric or (in the multivariate case) a list of
% images of the lc;
  begin scalar currently!-forbidden!-primes,res,prime!-count,v,w;
    if factor!-x then u:=multf(u,v:=!*k2f m!-image!-variable);
    chosen!-prime:=nil;
    currently!-forbidden!-primes:=forbidden!-primes;
    prime!-count:=1;
tryanotherprime:
    if chosen!-prime then
      currently!-forbidden!-primes:=chosen!-prime .
                                 currently!-forbidden!-primes;
    chosen!-prime:=get!-new!-prime currently!-forbidden!-primes;
    set!-modulus chosen!-prime;
    if not atom lc!-u then <<
      w:=lc!-u;
      while w and
           ((domainp caar w and not(modular!-number caar w = 0))
              or not (domainp caar w or modular!-number lnc caar w=0))
            do w:=cdr w;
      if w then goto tryanotherprime >>
    else if modular!-number lc!-u=0 then goto tryanotherprime;
    res:=monic!-mod!-p reduce!-mod!-p u;
    if not square!-free!-mod!-p res then
      if multivariate!-input!-poly
         and (prime!-count:=prime!-count+1)>no!-of!-primes!-to!-try
        then <<no!-of!-primes!-to!-try := no!-of!-primes!-to!-try+1;
               res:='not!-square!-free>>
      else goto tryanotherprime;
    if factor!-x and not(res='not!-square!-free) then
      res:=quotfail!-mod!-p(res,!*f2mod v);
    return res
 end;

symbolic procedure get!-new!-prime forbidden!-p;
% get a small prime that is not in the list forbidden!-p;
% we pick one of the first 10 primes if we can;
  if !*force!-prime then !*force!-prime
  else begin scalar p,primes!-done;
    for each pp in forbidden!-p do
      if pp<32 then primes!-done:=pp.primes!-done;
tryagain:
    if null(p:=random!-teeny!-prime primes!-done) then <<
      p:=random!-small!-prime();
      primes!-done:='all >>
    else primes!-done:=p . primes!-done;
    if member(p,forbidden!-p) then goto tryagain;
    return p
  end;

%***********************************************************************
% find the numbers associated with each factor of the leading
% coefficient of our multivariate polynomial. this will help
% to distribute the leading coefficient later.;



symbolic procedure unique!-f!-nos(v,cont!.u0,im!.set);
% given an image set (im!.set), this finds the numbers associated with
% each factor in v subject to wang's condition (2) on the image set.
% this is an implementation of his algorithm n. if the condition
% is met the result is a vector containing the images of each factor
% in v, otherwise the result is nil;
  begin scalar d,k,q,r,lc!.image!.vec;
            % v's integer factor is at the front:  ;
    k:=length cdr v;
            % no. of non-trivial factors of v;
    if not numberp cont!.u0 then cont!.u0:=lc cont!.u0;
    putv(d:=mkvect k,0,abs(cont!.u0 * car v));
            % d will contain the special numbers to be used in the
            % loop below;
    putv(lc!.image!.vec:=mkvect k,0,abs(cont!.u0 * car v));
            % vector for result with 0th entry filled in;
    v:=cdr v;
            % throw away integer factor of v;
            % k is no. of non-trivial factors (say f(i)) in v;
            % d will contain the nos. associated with each f(i);
            % v is now a list of the f(i) (and their multiplicities);
    for i:=1:k do
    << q:=abs make!-image(caar v,im!.set);
       putv(lc!.image!.vec,i,q);
       v:=cdr v;
       for j:=isub1 i step -1 until 0 do
       << r:=getv(d,j);
          while not onep r do
          << r:=gcdn(r,q); q:=q/r >>;
          if onep q then <<lc!.image!.vec:=nil; j := -1>>
            % if q=1 here then we have failed the condition so exit;
          >>;
      if null lc!.image!.vec then i := k+1 else putv(d,i,q);
            % else q is the ith number we want;
   >>;
    return lc!.image!.vec
  end;

symbolic procedure get!.content u;
% u is a univariate square free poly. gets the content of u (=integer);
% if lc u is negative then the minus sign is pulled out as well;
% nb. the content includes the variable if it is a factor of u;
  begin scalar c;
    c:=if poly!-minusp u then -(numeric!-content u)
       else numeric!-content u;
    if not didntgo quotf(u,!*k2f m!-image!-variable) then
      c:=adjoin!-term(mksp(m!-image!-variable,1),c,polyzero);
    return c
  end;


%********************************************************************;
%    finally we have the routines that use the numbers generated
%    by unique.f.nos to determine the true leading coeffts in
%    the multivariate factorization we are doing and which image
%    factors will grow up to have which true leading coefft.
%********************************************************************;




symbolic procedure distribute!.lc(r,im!.factors,s,v);
% v is the factored lc of a poly, say u, whose image factors (r of
% them) are in the vector im.factors. s is a list containing the
% image information including the image set, the image poly etc.
%  this uses wang's ideas for distributing the factors in v over
% those in im.factors. result is (delta . vector of the lc's of
% the full factors of u) , where delta is the remaining integer part
% of the lc that we have been unable to distribute.             ;
  (lambda factor!-level;
  begin scalar k,delta,div!.count,q,uf,i,d,max!.mult,f,numvec,
               dvec,wvec,dtwid,w;
    delta:=get!-image!-content s;
            % the content of the u image poly;
    dist!.lc!.msg1(delta,im!.factors,r,s,v);
    v:=cdr v;
            % we are not interested in the numeric factors of v;
    k:=length v;
            % number of things to distribute;
    numvec:=get!-f!-numvec s;
            % nos. associated with factors in v;
    dvec:=mkvect r;
    wvec:=mkvect r;
    for j:=1:r do <<
      putv(dvec,j,1);
      putv(wvec,j,delta*lc getv(im!.factors,j)) >>;
            % result lc's will go into dvec which we initialize to 1's;
            % wvec is a work vector that we use in the division process
            % below;
    v:=reverse v;
    for j:=k step -1 until 1 do
    << % (for each factor in v, call it f(j) );
      f:=caar v;
            % f(j) itself;
      max!.mult:=cdar v;
            % multiplicity of f(j) in v (=lc u);
      v:=cdr v;
      d:=getv(numvec,j);
            % number associated with f(j);
      i:=1; % we trial divide d into lc of each image
            % factor starting with 1st;
      div!.count:=0;
            % no. of d's that have been distributed;
      factor!-trace <<
        prin2!* "f("; prin2!* j; prin2!* ")= "; printsf f;
        prin2!* "There are "; prin2!* max!.mult;
        printstr " of these in the leading coefficient.";
        prin2!* "The absolute value of the image of f("; prin2!* j;
        prin2!* ")= "; printstr d >>;
      while ilessp(div!.count,max!.mult)
        and not igreaterp(i,r) do
      << q:=divide(getv(wvec,i),d);
            % first trial division;
        factor!-trace <<
          prin2!* "  Trial divide into ";
          prin2!* getv(wvec,i); printstr " :" >>;
        while (zerop cdr q) and ilessp(div!.count,max!.mult) do
        << putv(dvec,i,multf(getv(dvec,i),f));
            % f(j) belongs in lc of ith factor;
          factor!-trace <<
            prin2!* "    It goes so an f("; prin2!* j;
            prin2!* ") belongs in ";
            printsf getv(im!.factors,i);
            printstr "  Try again..." >>;
          div!.count:=iadd1 div!.count;
            % another d done;
          putv(wvec,i,car q);
            % save the quotient for next factor to distribute;
          q:=divide(car q,d);
            % try again;
        >>;
        i:=iadd1 i;
            % as many d's as possible have gone into that
            % factor so now try next factor;
        factor!-trace
           <<printstr "    no good so try another factor ..." >>>>;
            % at this point the whole of f(j) should have been
            % distributed by dividing d the maximum no. of times
            % (= max!.mult), otherwise we have an extraneous factor;
      if ilessp(div!.count,max!.mult) then
        <<bad!-case:=t; div!.count := max!.mult>>
    >>;
    if bad!-case then return;
    dist!.lc!.msg2(dvec,im!.factors,r);
    if onep delta then
    << for j:=1:r do <<
         w:=lc getv(im!.factors,j) /
          evaluate!-in!-order(getv(dvec,j),get!-image!-set s);
         if w<0 then begin
           scalar oldpoly;
           delta:= -delta;
           oldpoly:=getv(im!.factors,j);
           putv(im!.factors,j,negf oldpoly);
            % to keep the leading coefficients positive we negate the
            % image factors when necessary;
           multiply!-alphas(-1,oldpoly,getv(im!.factors,j));
            % remember to fix the alphas as well;
         end;
         putv(dvec,j,multf(abs w,getv(dvec,j))) >>;
      dist!.lc!.msg3(dvec,im!.factors,r);
      return (delta . dvec)
    >>;
      % if delta=1 then we know the true lc's exactly so put in their
      % integer contents and return with result.
      % otherwise try spreading delta out over the factors:      ;
    dist!.lc!.msg4 delta;
    for j:=1:r do
    << dtwid:=evaluate!-in!-order(getv(dvec,j),get!-image!-set s);
       uf:=getv(im!.factors,j);
       d:=gcddd(lc uf,dtwid);
       putv(dvec,j,multf(lc uf/d,getv(dvec,j)));
       putv(im!.factors,j,multf(dtwid/d,uf));
            % have to fiddle the image factors by an integer multiple;
       multiply!-alphas!-recip(dtwid/d,uf,getv(im!.factors,j));
            % fix the alphas;
       delta:=delta/(dtwid/d)
    >>;
    % now we've done all we can to distribute delta so we return with
    % what's left:                                    ;
    if delta<=0 then
      errorf list("FINAL DELTA IS -VE IN DISTRIBUTE!.LC",delta);
    factor!-trace <<
      printstr "     Finally we have:";
      for j:=1:r do <<
        prinsf getv(im!.factors,j);
        prin2!* " with l.c. ";
        printsf getv(dvec,j) >> >>;
    return (delta . dvec)
  end) (factor!-level * 10);

symbolic procedure dist!.lc!.msg1(delta,im!.factors,r,s,v);
    factor!-trace <<
      terpri(); terpri();
      printstr "We have a polynomial whose image factors (call";
      printstr "them the IM-factors) are:";
      prin2!* delta; printstr " (= numeric content, delta)";
      printvec(" f(",r,")= ",im!.factors);
      prin2!* "  wrt the image set: ";
      for each x in get!-image!-set s do <<
        prinvar car x; prin2!* "="; prin2!* cdr x; prin2!* ";" >>;
      terpri!*(nil);
      printstr "We also have its true multivariate leading";
      printstr "coefficient whose factors (call these the";
      printstr "LC-factors) are:";
      fac!-printfactors v;
      printstr "We want to determine how these LC-factors are";
      printstr "distributed over the leading coefficients of each";
      printstr "IM-factor.  This enables us to feed the resulting";
      printstr "image factors into a multivariate Hensel";
      printstr "construction.";
      printstr "We distribute each LC-factor in turn by dividing";
      printstr "its image into delta times the leading coefficient";
      printstr "of each IM-factor until it finds one that it";
      printstr "divides exactly. The image set is chosen such that";
      printstr "this will only happen for the IM-factors to which";
      printstr "this LC-factor belongs - (there may be more than";
      printstr "one if the LC-factor occurs several times in the";
      printstr "leading coefficient of the original polynomial).";
      printstr "This choice also requires that we distribute the";
      printstr "LC-factors in a specific order:"
      >>;

symbolic procedure dist!.lc!.msg2(dvec,im!.factors,r);
    factor!-trace <<
      printstr "The leading coefficients are now correct to within an";
      printstr "integer factor and are as follows:";
      for j:=1:r do <<
        prinsf getv(im!.factors,j);
        prin2!* " with l.c. ";
        printsf getv(dvec,j) >> >>;

symbolic procedure dist!.lc!.msg3(dvec,im!.factors,r);
      factor!-trace <<
        printstr "Since delta=1, we have no non-trivial content of the";
        printstr
          "image to deal with so we know the true leading coefficients";
        printstr
          "exactly.  We fix the signs of the IM-factors to match those";
        printstr "of their true leading coefficients:";
        for j:=1:r do <<
          prinsf getv(im!.factors,j);
          prin2!* " with l.c. ";
          printsf getv(dvec,j) >> >>;

symbolic procedure dist!.lc!.msg4 delta;
    factor!-trace <<
      prin2!* " Here delta is not 1 meaning that we have a content, ";
      printstr delta;
      printstr "of the image to distribute among the factors somehow.";
      printstr "For each IM-factor we can divide its leading";
      printstr "coefficient by the image of its determined leading";
      printstr "coefficient and see if there is a non-trivial result.";
      printstr "This will indicate a factor of delta belonging to this";
      printstr "IM-factor's leading coefficient." >>;

endmodule;


module pfactor;  % Factorization of polynomials modulo p.

% Author: A. C. Norman, 1978.

fluid '(!*gcd
        current!-modulus
        m!-image!-variable
        modular!-info
        modulus!/2
        user!-prime);

symbolic procedure pfactor(q,p);
   % Q is a standard form. Factorize and return the factors mod p.
   begin scalar user!-prime,current!-modulus,modulus!/2,r,x;
%   set!-time();
    if not numberp p then typerr(p,"number")
     else if not primep p then typerr(p,"prime");
    user!-prime:=p;
    set!-modulus p;
    if domainp q or null reduce!-mod!-p lc q then
       prin2t "*** Degenerate case in modular factorization";
    if not (length variables!-in!-form q=1) then
       rerror(factor,1,"Multivariate input to modular factorization");
    r:=reduce!-mod!-p q;
%   lncoeff := lc r;
    x := lnc r;
    r :=monic!-mod!-p r;
%   print!-time "About to call FACTOR-FORM-MOD-P";
    r:=errorset!*(list('factor!-form!-mod!-p,mkquote r),t);
%   print!-time "FACTOR-FORM-MOD-P returned";
    if not errorp r then return x . car r;
    prin2t "****** FACTORIZATION FAILED******";
    return list(1,prepf q)   % 1 needed by factorize.
  end;


symbolic procedure factor!-form!-mod!-p p;
% input:
% p is a reduce standard form that is to be factorized
% mod prime;
% result:
% ((p1 . x1) (p2 . x2) .. (pn . xn))
% where p<i> are standard forms and x<i> are integers,
% and p= product<i> p<i>**x<i>;
    sort!-factors factorize!-by!-square!-free!-mod!-p p;

symbolic procedure sort!-factors l;
   % Sort factors as found into some sort of standard order.  The order
   % used here is more or less random, but will be self-consistent.
   sort(l,function orderfactors);

symbolic procedure factorize!-by!-square!-free!-mod!-p p;
    if p=1 then nil
    else if domainp p then (p . 1) . nil
    else
     begin
      scalar dp,v;
      v:=(mksp(mvar p,1).* 1) .+ nil;
      dp:=0;
      while evaluate!-mod!-p(p,mvar v,0)=0 do <<
        p:=quotfail!-mod!-p(p,v);
        dp:=dp+1 >>;
      if dp>0 then return ((v . dp) .
        factorize!-by!-square!-free!-mod!-p p);
      dp:=derivative!-mod!-p p;
      if dp=nil then <<
%here p is a something to the power current!-modulus;
        p:=divide!-exponents!-by!-p(p,current!-modulus);
        p:=factorize!-by!-square!-free!-mod!-p p;
        return multiply!-multiplicities(p,current!-modulus) >>;
      dp:=gcd!-mod!-p(p,dp);
      if dp=1 then return factorize!-pp!-mod!-p p;
%now p is not square-free;
      p:=quotfail!-mod!-p(p,dp);
%factorize p and dp separately;
      p:=factorize!-pp!-mod!-p p;
      dp:=factorize!-by!-square!-free!-mod!-p dp;
% i feel that this scheme is slightly clumsy, but
% square-free decomposition mod p is not as straightforward
% as square free decomposition over the integers, and pfactor
% is probably not going to be slowed down too badly by
% this;
      return mergefactors(p,dp)
   end;




%**********************************************************************;
% code to factorize primitive square-free polynomials mod p;



symbolic procedure divide!-exponents!-by!-p(p,n);
    if domainp p then p
    else (mksp(mvar p,exactquotient(ldeg p,n)) .* lc p) .+
       divide!-exponents!-by!-p(red p,n);

symbolic procedure exactquotient(a,b);
  begin
    scalar w;
    w:=divide(a,b);
    if cdr w=0 then return car w;
    error(50,list("Inexact division",list(a,b,w)))
  end;


symbolic procedure multiply!-multiplicities(l,n);
    if null l then nil
    else (caar l . (n*cdar l)) .
        multiply!-multiplicities(cdr l,n);


symbolic procedure mergefactors(a,b);
% a and b are lists of factors (with multiplicities),
% merge them so that no factor occurs more than once in
% the result;
    if null a then b
    else mergefactors(cdr a,addfactor(car a,b));

symbolic procedure addfactor(a,b);
%add factor a into list b;
    if null b then list a
    else if car a=caar b then
      (car a . (cdr a + cdar b)) . cdr b
    else car b . addfactor(a,cdr b);

symbolic procedure factorize!-pp!-mod!-p p;
%input a primitive square-free polynomial p,
% output a list of irreducible factors of p;
  begin
    scalar vars;
    if p=1 then return nil
    else if domainp p then return (p . 1) . nil;
% now I am certain that p is not degenerate;
%   print!-time "primitive square-free case detected";
    vars:=variables!-in!-form p;
    if length vars=1 then return unifac!-mod!-p p;
    errorf "SHAMBLED IN PFACTOR - MULTIVARIATE CASE RESURFACED"
  end;

symbolic procedure unifac!-mod!-p p;
%input p a primitive square-free univariate polynomial
%output a list of the factors of p over z mod p;
  begin
    scalar modular!-info,m!-image!-variable;
    if domainp p then return nil
    else if ldeg p=1 then return (p . 1) . nil;
    modular!-info:=mkvect 1;
    m!-image!-variable:=mvar p;
    get!-factor!-count!-mod!-p(1,p,user!-prime,nil);
%   print!-time "Factor counts obtained";
    get!-factors!-mod!-p(1,user!-prime);
%   print!-time "Actual factors extracted";
    return for each z in getv(modular!-info,1) collect (z . 1)
  end;

endmodule;


module vecpoly;

% Authors: A. C. Norman and P. M. A. Moore, 1979;

fluid '(current!-modulus safe!-flag);


%**********************************************************************;
% Routines for working with modular univariate polynomials
% stored as vectors. Used to avoid unwarranted storage management
% in the mod-p factorization process;


safe!-flag:=carcheck 0;


symbolic procedure copy!-vector(a,da,b);
% Copy A into B;
 << for i:=0:da do
      putv(b,i,getv(a,i));
    da >>;

symbolic procedure times!-in!-vector(a,da,b,db,c);
% Put the product of A and B into C and return its degree.
% C must not overlap with either A or B;
  begin
    scalar dc,ic,w;
    if da#<0 or db#<0 then return minus!-one;
    dc:=da#+db;
    for i:=0:dc do putv(c,i,0);
    for ia:=0:da do <<
      w:=getv(a,ia);
      for ib:=0:db do <<
        ic:=ia#+ib;
        putv(c,ic,modular!-plus(getv(c,ic),
          modular!-times(w,getv(b,ib)))) >> >>;
    return dc
  end;


symbolic procedure quotfail!-in!-vector(a,da,b,db);
% Overwrite A with (A/B) and return degree of result.
% The quotient must be exact;
    if da#<0 then da
    else if db#<0 then errorf "Attempt to divide by zero"
    else if da#<db then errorf "Bad degrees in QUOTFAIL-IN-VECTOR"
    else begin
      scalar dc;
      dc:=da#-db; % Degree of result;
      for i:=dc step -1 until 0 do begin
        scalar q;
        q:=modular!-quotient(getv(a,db#+i),getv(b,db));
        for j:=0:db#-1 do
          putv(a,i#+j,modular!-difference(getv(a,i#+j),
            modular!-times(q,getv(b,j))));
        putv(a,db#+i,q)
      end;
      for i:=0:db#-1 do if getv(a,i) neq 0 then
        errorf "Quotient not exact in QUOTFAIL!-IN!-VECTOR";
      for i:=0:dc do
        putv(a,i,getv(a,db#+i));
      return dc
    end;


symbolic procedure remainder!-in!-vector(a,da,b,db);
% Overwrite the vector A with the remainder when A is
% divided by B, and return the degree of the result;
  begin
    scalar delta,db!-1,recip!-lc!-b,w;
    if db=0 then return minus!-one
    else if db=minus!-one then errorf "ATTEMPT TO DIVIDE BY ZERO";
    recip!-lc!-b:=modular!-minus modular!-reciprocal getv(b,db);
    db!-1:=db#-1; % Leading coeff of B treated specially, hence this;
    while not((delta:=da#-db) #< 0) do <<
      w:=modular!-times(recip!-lc!-b,getv(a,da));
      for i:=0:db!-1 do
        putv(a,i#+delta,modular!-plus(getv(a,i#+delta),
          modular!-times(getv(b,i),w)));
      da:=da#-1;
      while not(da#<0) and getv(a,da)=0 do da:=da#-1 >>;
    return da
  end;

symbolic procedure evaluate!-in!-vector(a,da,n);
% Evaluate A at N;
  begin
    scalar r;
    r:=getv(a,da);
    for i:=da#-1 step -1 until 0 do
      r:=modular!-plus(getv(a,i),
        modular!-times(r,n));
    return r
  end;

symbolic procedure gcd!-in!-vector(a,da,b,db);
% Overwrite A with the gcd of A and B. On input A and B are
% vectors of coefficients, representing polynomials
% of degrees DA and DB. Return DG, the degree of the gcd;
  begin
    scalar w;
    if da=0 or db=0 then << putv(a,0,1); return 0 >>
    else if da#<0 or db#<0 then errorf "GCD WITH ZERO NOT ALLOWED";
top:
% Reduce the degree of A;
    da:=remainder!-in!-vector(a,da,b,db);
    if da=0 then << putv(a,0,1); return 0 >>
    else if da=minus!-one then <<
      w:=modular!-reciprocal getv(b,db);
      for i:=0:db do putv(a,i,modular!-times(getv(b,i),w));
      return db >>;
% Now reduce degree of B;
    db:=remainder!-in!-vector(b,db,a,da);
    if db=0 then << putv(a,0,1); return 0 >>
    else if db=minus!-one then <<
      w:=modular!-reciprocal getv(a,da);
      if not (w=1) then
        for i:=0:da do putv(a,i,modular!-times(getv(a,i),w));
      return da >>;
    go to top
  end;



carcheck safe!-flag;


endmodule;


end;
