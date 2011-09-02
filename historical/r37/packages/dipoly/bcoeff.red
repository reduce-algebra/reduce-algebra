module bcoeff;  % Computation of base coefficients.

% Definitions of base coefficient operations for distributive
% polynomial package.  Fields and rings are supported as coefficient
% domains. Side relations (computing modulo an ideal) are supported
% if the list bczerodivl is non-zero.
% 
% In this module, a standard quotient coefficient is assumed, unless
% !*grmod!* is true, in which case it is a small modular number.

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/
 
% H. Melenk: added routines for faster computation with 
% quotients representing integers.

% June 94: Added side relations (zero divisor list) bczerodivl!*;
% Nov 94:  Using quotfx and quotientx for divison with known zero
%          remainder.

fluid '(!*balanced_mod
	dmode!*
        bczerodivl!*  % List of expressions (sf) equivalent to zero.
        !*bcsubs2     % check bc for substitutions.
	!*grmod!*     % indicating small modular coefficients
	!*vdpinteger  % if t: arithmetic restricted to ring mode.
       );

symbolic procedure bcint2op(a1,a2,op);
    null dmode!* and
    1=denr a1 and numberp (a1:=numr a1) and 
    1=denr a2 and numberp (a2:=numr a2) and
%   (a1 := idapply(op,list(a1,a2))) and
    (a1 := apply2(op,a1,a2)) and
    ((if a1=0 then nil else a1) ./ 1);

fluid '(!*nat);

% symbolic procedure bcless!? (a1,a2);
%  /* Base coefficient less. a1 and a2 are base coefficients.
%    bcless!?(a1,a2) returns a boolean expression, true if
%    a1 is less than a2 else false. */
%    minusf numr addsq(a1,negsq a2);

% The following two could be smacros.  However, they would then need to
% be included in dipoly, thus destroying the modularity of the base
% coefficient code.

symbolic procedure bcminus!? u;
%   /* Boolean function. Returns true if u is a negative base coeff*/
    null !*grmod!* and minusf numr u;

symbolic procedure bczero!? u;
%  /* Returns a boolean expression, true if the base coefficient u is
%    zero*/
    if !*grmod!* then eqn(u,0) else null numr u;

%symbolic procedure bcxzero!? u;
%  extended zero test: check for zero divisors.
%     begin scalar l,d; 
%       l:=bczerodivl!*;
%       u := numr u;
%       while not d and l do <<d:=quotf(u,car l);l:=cdr l>>;
%       return d;
%     end;
     

% symbolic procedure bccomp (a1,a2);
%  /* Base coefficient compare a1 and a2 are base coefficients.
%    bccomp(a1,a2) compares the base coefficients a1 and a2 and returns
%    a digit 1 if a1 greater than a2, a digit 0 if a1 equals a2 else a
%    digit -1. */
%    (if bczero!? sl then 0
%      else if bcminus!? sl then -1
%      else 1)
%      where sl = bcdif(a1, a2);


symbolic procedure bcfd a;
%  /* Base coefficient from domain. a is a domain element. bcfd(a)
%    returns the base coefficient a. */
     if null !*grmod!* then mkbc(a,1)
      else if fixp a then bcfi a
      else if not(car a eq '!:mod!:)
       then rederr list("Invalid modular coefficient",a)
      else bcfi cdr a;

symbolic procedure bcfi a;
%  /* Base coefficient from integer. a is an integer. bcfi(a)
%    returns the base coefficient a. */
   (if u<0
      then if !*balanced_mod and u+u > - current!-modulus then u
	    else u #+ current!-modulus
     else if !*balanced_mod and u+u > current!-modulus
      then u #- current!-modulus
     else u)
    where u=remainder(a,current!-modulus);

symbolic procedure bcdomain!? u;
%  True if base coefficient u is a domain element.
   !*grmod!* or (denr u =1 and domainp numr u);

symbolic procedure bclcmd(u,v);
% Base coefficient least common multiple of denominators.
% u and v are two base coefficients. bclcmd(u,v) calculates the
% least common multiple of the denominator of u and the
% denominator of v and returns a base coefficient of the form
% 1/lcm(denom u,denom v).
  if bczero!? u then mkbc(1,denr v)
   else if bczero!? v then mkbc(1,denr u)
   else mkbc(1,multf(quotfx(denr u,gcdf(denr u,denr v)),denr v));


symbolic procedure bclcmdprod(u,v);
% Base coefficient least common multiple denominator product.
% u is a basecoefficient of the form 1/integer. v is a base
% coefficient. bclcmdprod(u,v) calculates (denom u/denom v)*nom v/1
% and returns a base coefficient.
  mkbc(multf(quotfx(denr u,denr v),numr v),1);


% symbolic procedure bcquod(u,v);
% Base coefficient quotient. u and v are base coefficients.
% bcquod(u,v) calculates u/v and returns a base coefficient.
% bcprod(u,bcinv v);


symbolic procedure bcone!? u;
%  /* Base coefficient one. u is a base coefficient.
%    bcone!?(u) returns a boolean expression, true if the
%    base coefficient u is equal 1. */
   if !*grmod!* then eqn(u,1) else denr u = 1 and numr u = 1;

symbolic procedure bcinv u;
%  /* Base coefficient inverse. u is a base coefficient.
%    bcinv(u) calculates 1/u and returns a base coefficient. */
   if !*grmod!*
     then if !*balanced_mod
	    then (if v+v>current!-modulus then v #- current!-modulus
		   else v) where v= modular!-reciprocal u
	   else reciprocal!-by!-gcd(current!-modulus,u,0,1)
    else invsq u;


symbolic procedure bcneg u;
%  /* Base coefficient negative. u is a base coefficient.
%    bcneg(u) returns the negative of the base coefficient
%    u, a base coefficient. */
   if !*grmod!* then if eqn(u,0) then u else current!-modulus #- u
    else negsq u;


symbolic procedure bcprod (u,v);
%  /* Base coefficient product. u and v are base coefficients.
%    bcprod(u,v) calculates u*v and returns a base coefficient.
   if !*grmod!* then bcfi(u*v)
    else bcint2op(u,v,'times2) or bccheckz multsq(u,v);
 
symbolic procedure mkbc(u,v);
%   /* Convert u and v into u/v in lowest terms*/
   if !*grmod!*
     then bcfi(u*modular!-reciprocal v)
    else if v = 1 then u ./ v
    else if minusf v then mkbc(negf u,negf  v)
    else quotfx(u,m) ./ quotfx(v,m) where m = gcdf(u,v);

if null getd 'quotientx then copyd('quotientx,'quotient);

symbolic procedure bcquot(u,v);
%  /* Base coefficient quotient. u and v are base coefficients.
%    bcquot(u,v) calculates u/v and returns a base coefficient. */
  if !*grmod!*
    then bcfi(u*modular!-reciprocal v)
   else if !*vdpinteger then
     (bcint2op(u,v,'quotientx) or !*f2q quotfx(numr u,numr v))
   else quotsq(u,v);


symbolic procedure bcsum(u,v);
%  /* Base coefficient sum. u and v are base coefficients.
%    bcsum(u,v) calculates u+v and returns a base coefficient. */
   if !*grmod!* then bcfi(u+v)
    else bcint2op(u,v,'plus2) or bccheckz addsq(u,v);
  
symbolic procedure bccheckz u;
% Reduce a sum/difference result by members of bczerodivl!*.
   if null numr u then u else if !*bcsubs2 then subs2 u else
 <<while l and n do <<n:=cdr qremf(n,car l);l := cdr l>>; n./d>>
     where l=bczerodivl!*,n=numr u,d=denr u;

symbolic procedure bcdif(u,v);
%  /* Base coefficient difference. u and v are base coefficients.
%    bcdif(u,v) calculates u-v and returns a base coefficient. */
   if !*grmod!* then bcfi(u - v)
    else bcint2op(u,v,'difference) or bcsum(u,bcneg v);
  

symbolic procedure bcpow(u,n);
%   /*Returns the base coefficient u raised to the nth power, where
%    n is an integer*/
   if !*grmod!* then modular!-expt(u,n) else exptsq(u,n);


symbolic procedure a2bc u;
%   /*Converts the algebraic (kernel) u into a base coefficient.
   if !*grmod!*
     then if not domainp u then rederr list("Invalid coefficient",u)
	   else bcfd u
    else simp!* u;


symbolic procedure bc2a u;
%   /* Returns the prefix equivalent of the base coefficient u*/
   if !*grmod!* then u else prepsq u;

      
fluid '(!*groebigpos !*groebigneg !*groescale); 
!*groescale := 20; 
!*groebigpos:= 10** !*groescale; !*groebigneg := - 10** !*groescale; 
  
symbolic procedure bcprin u;
%   /* Prints a base coefficient in infix form*/
   if !*grmod!* then prin2 u else
   begin scalar nat;
      nat := !*nat;
      !*nat := nil;
      if cdr u = 1 and 
           numberp car u and 
           (car u>!*groebigpos or car u<!*groebigneg)
          then bcprin2big car u
      else if cdr u neq 1 or not numberp car u then
         <<prin2!* "[";sqprint u; prin2!* "]">>
       else sqprint u;
      !*nat := nat
    end;

symbolic procedure bcprin2big u;
    <<if u<0 then<< prin2 "-"; u:= -u>>; bcprin2big1(u,0)>>;
 
symbolic procedure bcprin2big1 (u,n);
    if u>!*groebigpos then
             bcprin2big1 (u/!*groebigpos,n#+!*groescale)
      else <<prin2 u; prin2 "e"; prin2 n>>;
    
endmodule;

end;
