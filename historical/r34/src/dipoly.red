module dipoly;   % Header module for dipoly package.

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

% For the time being, this contains the smacros that used to be in
% consel, and repeats those in bcoeff.

%/*Constructors and selectors for a distributed polynomial form*/

%/*A distributive polynomial has the following informal syntax:
%
%   <dipoly> ::= dipzero
%                | <exponent vector> . <base coefficient> . <dipoly>*/

% Vdp2dip modules included.  They could be in a separate package.

create!-package('(dipoly a2dip bcoeff dip2a dipoly1 dipvars
                  expvec torder vdp2dip vdpcom),
                '(contrib dipoly));

%define dipzero = 'nil;

fluid '(dipzero);
     %/*Until we understand how to define something to nil*/


smacro procedure dipzero!? u; null u;

smacro procedure diplbc p;
%  /* Distributive polynomial leading base coefficient.
%    p is a distributive polynomial. diplbc(p)  returns
%    the leading base coefficient of p. */
   cadr p;

smacro procedure dipmoncomp (a,e,p);
%  /* Distributive polynomial monomial composition. a is a base
%    coefficient, e is an exponent vector and p is a
%    distributive polynomial. dipmoncomp(a,e,p) returns a dis-
%    tributive polynomial with p as monomial reductum, e as
%    exponent vector of the leading monomial and a as leading
%    base coefficient. */
   e . a . p;

smacro procedure dipevlmon p;
%  /* Distributive polynomial exponent vector leading monomial.
%    p is a distributive polynomial. dipevlmon(p) returns the
%    exponent vector of the leading monomial of p. */
   car p;

smacro procedure dipfmon (a,e);
%  /* Distributive polynomial from monomial. a is a base coefficient
%    and e is an exponent vector. dipfmon(a,e) returns a
%    distributive polynomial with e as exponent vector and
%    a as base coefficient. */
   e . a . dipzero;

smacro procedure dipnov p;
%  /* Distributive polynomial number of variables. p is a distributive
%    polynomial. dipnov(p) returns a digit, the number of variables
%    of the distributive polynomial p. */
   length car p;

smacro procedure dipmred p;
%  /* Distributive polynomial reductum. p is a distributive polynomial
%    dipmred(p) returns the reductum of the distributive polynomial p,
%    a distributive polynomial. */
   cddr p;


% These smacros are also in bcoeff.

smacro procedure bcminus!? u;
%   /* Boolean function. Returns true if u is a negative base coeff*/
   minusf numr u;

smacro procedure bczero!? u;
%  /* Returns a boolean expression, true if base coefficient u is zero*/
   null numr u;

endmodule;


module a2dip;
  %/*Convert an algebraic (prefix) form to distributive polynomial*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

fluid '(dipvars!* dipzero);

expr procedure a2dip u;
%   /*Converts the algebraic (prefix) form u to a distributive poly.
%     We assume that all variables used have been previously
%     defined in dipvars!*, but a check is also made for this*/
   if atom u then a2dipatom u
    else if not atom car u or not idp car u 
     then typerr(car u,"dipoly operator")
    else (if x then apply(x,list for each y in cdr u collect a2dip y)
         else a2dipatom u)
          where x = get(car u,'dipfn);

expr procedure a2dipatom u;
%   /*Converts the atom (or kernel) u into a distributive polynomial*/
   if u=0 then dipzero
    else if numberp u or not(u member dipvars!*)
      then dipfmon(a2bc u,evzero())
    else dipfmon(a2bc 1,mkexpvec u);

expr procedure dipfnsum u;
%   /*U is a list of dip expressions. Result is the distributive poly
%    representation for the sum*/
   (<<for each y in cdr u do x := dipsum(x,y); x>>) where x = car u;

put('plus,'dipfn,'dipfnsum);

put('plus2,'dipfn,'dipfnsum);

expr procedure dipfnprod u;
%   /*U is a list of dip expressions. Result is the distributive poly
%    representation for the product*/
%   /*Maybe we should check for a zero*/
   (<<for each y in cdr u do x := dipprod(x,y); x>>) where x = car u;

put('times,'dipfn,'dipfnprod);

put('times2,'dipfn,'dipfnprod);

expr procedure dipfndif u;
%   /*U is a list of two dip expressions. Result is the distributive
%    polynomial representation for the difference*/
   dipsum(car u,dipneg cadr u);

put('difference,'dipfn,'dipfndif);

expr procedure dipfnpow u;
%   /*U is a pair of dip expressions. Result is the distributive poly
%    representation for the first raised to the second power*/
  (if not fixp n or n<0 
     then typerr(n,"distributive polynomial exponent")
    else if n=0 then if dipzero!? v then rerror(dipoly,1,"0**0 invalid")
                  else w
    else if dipzero!? v or n=1 then v
    else if dipzero!? dipmred v
     then dipfmon(bcpow(diplbc v,n),intevprod(n,dipevlmon v))
    else <<while n>0 do
         <<if not evenp n then w := dipprod(w,v);
             n := n/2;
           if n>0 then v := dipprod(v,v)>>;
         w>>)
    where n := dip2a cadr u, v := car u,
        w := dipfmon(a2bc 1,evzero());

put('expt,'dipfn,'dipfnpow);

expr procedure dipfnneg u;
%   /*U is a list of one dip expression. Result is the distributive
%    polynomial representation for the negative*/
   (if dipzero!? v then v
    else dipmoncomp(bcneg diplbc v,dipevlmon v,dipmred v))
    where v = car u;

put('minus,'dipfn,'dipfnneg);

expr procedure dipfnquot u;
%   /*U is a list of two dip expressions. Result is the distributive
%    polynomial representation for the quotient*/
   if dipzero!? cadr u or not dipzero!? dipmred cadr u
       or not evzero!? dipevlmon cadr u
      then typerr(dip2a cadr u,"distributive polynomial denominator")
    else dipfnquot1(car u,diplbc cadr u);

expr procedure dipfnquot1(u,v);
   if dipzero!? u then u
    else dipmoncomp(bcquot(diplbc u,v),
                dipevlmon u,
                dipfnquot1(dipmred u,v));

put('quotient,'dipfn,'dipfnquot);

endmodule;


module bcoeff;  % Computation of base coefficients.


%/*Definitions of base coefficient operations for distributive
% polynomial package.  We assume that only field elements are used, but
% no check is made for this.  In this module, a standard quotient
% coefficient is assumed*/


%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/
 
% H. Melenk: added routines for faster handling of standard case
% of standard quotients representing integers.

fluid '(dmode!*);

symbolic procedure bcint2op(a1,a2,op);
    null dmode!* and
    1=denr a1 and numberp (a1:=numr a1) and 
    1=denr a2 and numberp (a2:=numr a2) and
    (a1 := apply(op,list(a1,a2))) and
    ((if a1=0 then nil else a1) ./ 1);

fluid '(!*nat);

symbolic procedure bcless!? (a1,a2);
%  /* Base coefficient less. a1 and a2 are base coefficients.
%    bcless!?(a1,a2) returns a boolean expression, true if
%    a1 is less than a2 else false. */
     minusf numr addsq(a1,negsq a2);


smacro procedure bcminus!? u;
%   /* Boolean function. Returns true if u is a negative base coeff*/
   minusf numr u;


smacro procedure bczero!? u;
%  /* Returns a boolean expression, true if the base coefficient u is
%    zero*/
   null numr u;


symbolic procedure bccomp (a1,a2);
%  /* Base coefficient compare a1 and a2 are base coefficients.
%    bccomp(a1,a2) compares the base coefficients a1 and a2 and returns
%    a digit 1 if a1 greater than a2, a digit 0 if a1 equals a2 else a
%    digit -1. */
     (if bczero!? sl then 0
       else if bcminus!? sl then -1
       else 1)
       where sl = bcdif(a1, a2);


symbolic procedure bcfi a;
%  /* Base coefficient from integer. a is an integer. bcfi(a) returns
%    the base coefficient a. */
     mkbc(a,1);


symbolic procedure bclcmd(u,v);
% Base coefficient least common multiple of denominators.
% u and v are two base coefficients. bclcmd(u,v) calculates the
% least common multiple of the denominator of u and the
% denominator of v and returns a base coefficient of the form
% 1/lcm(denom u,denom v).
  if bczero!? u then mkbc(1,denr v)
   else if bczero!? v then mkbc(1,denr u)
   else mkbc(1,multf(quotf(denr u,gcdf(denr u,denr v)),denr v));


symbolic procedure bclcmdprod(u,v);
% Base coefficient least common multiple denominator product.
% u is a basecoefficient of the form 1/integer. v is a base
% coefficient. bclcmdprod(u,v) calculates (denom u/denom v)*nom v/1
% and returns a base coefficient.
  mkbc(multf(quotf(denr u,denr v),numr v),1);


symbolic procedure bcquod(u,v);
% Base coefficient quotient. u and v are base coefficients.
% bcquod(u,v) calculates u/v and returns a base coefficient.
  bcprod(u,bcinv v);


symbolic procedure bcone!? u;
%  /* Base coefficient one. u is a base coefficient.
%    bcone!?(u) returns a boolean expression, true if the
%    base coefficient u is equal 1. */
   denr u = 1 and numr u = 1;


symbolic procedure bcinv u;
%  /* Base coefficient inverse. u is a base coefficient.
%    bcinv(u) calculates 1/u and returns a base coefficient. */
    invsq u;


symbolic procedure bcneg u;
%  /* Base coefficient negative. u is a base coefficient.
%    bcneg(u) returns the negative of the base coefficient
%    u, a base coefficient. */
   negsq u;


symbolic procedure bcprod (u,v);
%  /* Base coefficient product. u and v are base coefficients.
%    bcprod(u,v) calculates u*v and returns a base coefficient.
   bcint2op(u,v,'bcnumtimes) or multsq(u,v);
 
symbolic procedure bcnumtimes(u,v); u*v;

symbolic procedure mkbc(u,v);
%   /* Convert u and v into u/v in lowest terms*/
   if v = 1 then u ./ v
    else if minusf v then mkbc(negf u,negf  v)
    else quotf(u,m) ./ quotf(v,m) where m = gcdf(u,v);


symbolic procedure bcquot (u,v);
%  /* Base coefficient quotient. u and v are base coefficients.
%    bcquot(u,v) calculates u/v and returns a base coefficient. */
   quotsq(u,v);


symbolic procedure bcsum (u,v);
%  /* Base coefficient sum. u and v are base coefficients.
%    bcsum(u,v) calculates u+v and returns a base coefficient. */
   bcint2op(u,v,'bcnumplus) or addsq(u,v);
  
symbolic procedure bcnumplus(u,v); u+v;


symbolic procedure bcdif(u,v);
%  /* Base coefficient difference. u and v are base coefficients.
%    bcdif(u,v) calculates u-v and returns a base coefficient. */
   bcint2op(u,v,'bcnumdifference) or bcsum(u,bcneg v);
  
symbolic procedure bcnumdifference(u,v); u-v;


symbolic procedure bcpow(u,n);
%   /*Returns the base coefficient u raised to the nth power, where
%    n is an integer*/
   exptsq(u,n);


symbolic procedure a2bc u;
%   /*Converts the algebraic (kernel) u into a base coefficient.
    simp!* u;


symbolic procedure bc2a u;
%   /* Returns the prefix equivalent of the base coefficient u*/
   prepsq u;

      
fluid '(!*groebigpos !*groebigneg !*groescale); 
!*groescale := 20; 
!*groebigpos:= 10** !*groescale; !*groebigneg := - 10** !*groescale; 
  
symbolic procedure bcprin u;
%   /* Prints a base coefficient in infix form*/
   begin scalar nat;
      nat := !*nat;
      !*nat := nil;
      if cdr u = 1 and 
           numberp car u and 
           (car u>!*groebigpos or car u<!*groebigneg)
          then bcprin2big car u
       else
          sqprint u;
      !*nat := nat
    end;

symbolic procedure bcprin2big u;
    << if u<0 then<< prin2 "-"; u:= -u>>;
       bcprin2big1(u,0)>>;
 
symbolic procedure bcprin2big1 (u,n);
    if u>!*groebigpos then
             bcprin2big1 (u/!*groebigpos,n#+!*groescale)
      else <<prin2 u; prin2 "e"; prin2 n>>;
    
endmodule;


module dip2a;

%/* Functions for converting distributive forms into prefix forms*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

expr procedure dip2a u;
%   /* Returns prefix equivalent of distributive polynomial u*/
   if dipzero!? u then 0 else dipreplus dip2a1 u;

expr procedure dip2a1 u;
   if dipzero!? u then nil
    else ((if bcminus!? x then list('minus,dipretimes(bc2a bcneg x . y))
           else dipretimes(bc2a x . y))
         where x = diplbc u, y = expvec2a dipevlmon u)
           . dip2a1 dipmred u;

expr procedure dipreplus u;
   if atom u then u else if null cdr u then car u else 'plus . u;

expr procedure dipretimes u;
%   /* U is a list of prefix expressions the first of which is a number.
%     Result is prefix representation for their product*/
   if car u = 1 then if cdr u then dipretimes cdr u else 1
    else if null cdr u then car u
    else 'times . u;

endmodule;


module dipoly;  % /*Distributive polnomial algorithms*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/
% modification for REDUCE 3.4: H. Melenk.

fluid '(dipvars!* dipzero);

symbolic procedure dipconst!? p;
 not dipzero!? p
 and dipzero!? dipmred p
 and evzero!? dipevlmon p;


symbolic procedure   dfcprint pl;
% h polynomial factor list of distributive polynomials print.
for each p in pl do dfcprintin p;

symbolic procedure   dfcprintin p;
% factor with exponent print.
( if cdr p neq 1 then << prin2 " ( "; dipprint1(p1,nil); prin2 " )** ";
  prin2 cdr p; terprit 2  >> else << prin2 "  "; dipprint p1>> )
      where p1:= dipmonic a2dip prepf car p;

symbolic procedure   dfcprin p;
% print content, factors and exponents of factorized polynomial p.
   << terpri(); prin2 " content of factorized polynomials  =  ";
   prin2 car p;
   terprit 2; dfcprint cdr p >>;


symbolic procedure diplcm p;
% Distributive polynomial least common multiple of denomiators.
% p is a distributive rational polynomial. diplcm(p) calculates
% the least common multiple of the denominators and returns a
% base coefficient of the form  1/lcm(denom bc1,.....,denom bci).
  if dipzero!? p then mkbc(1,1)
     else bclcmd(diplbc p, diplcm dipmred p);

symbolic procedure diprectoint(p,u);
% Distributive polynomial conversion rational to integral.
% p is a distributive rational polynomial, u is a base coefficient
% ( 1/lcm denom p ). diprectoint(p,u) returns a primitive
% associate pseudo integral ( denominators are 1 ) distributive
% polynomial.
  if bczero!? u then dipzero
     else if bcone!? u then p
          else diprectoint1(p,u);

symbolic procedure diprectoint1(p,u);
% Distributive polynomial conversion rational to integral internall 1.
% diprectoint1 is used in diprectoint.
  if dipzero!? p then dipzero
     else dipmoncomp(bclcmdprod(u,diplbc p),dipevlmon p,
                     diprectoint1(dipmred p,u));


symbolic procedure dipresul(p1,p2);
% test for fast downwards calculation
% p1 and p2 are two bivariate distributive polynomials.
% dipresul(p1,p2) returns the resultant of p1 and p2 with respect
% respect to the first variable of the variable list (car dipvars!*).
 begin scalar q1,q2,q,ct;
 q1:=dip2a diprectoint(p1,diplcm p1);
 q2:=dip2a diprectoint(p2,diplcm p2);
 ct := time();
 q:= a2dip prepsq simpresultant list(q1,q2,car dipvars!*);
 ct := time() - ct;
 prin2 " resultant : "; dipprint dipmonic q; terpri();
 prin2 " time resultant : "; prin2 ct; terpri();
 end;

symbolic procedure   dipbcprod (p,a);
%   /* Distributive polynomial base coefficient product.
%     p is a distributive polynomial, a is a base coefficient.
%     dipbcprod(p,a) computes p*a, a distributive polynomial. */

     if bczero!? a then dipzero
            else if bcone!? a then p
                                   else dipbcprodin(p,a);

symbolic procedure   dipbcprodin (p,a);
%   /* Distributive polynomial base coefficient product internal.
%     p is a distributive polynomial, a is a base coefficient,
%     where a is not equal 0 and not equal 1.
%     dipbcprodin(p,a) computes p*a, a distributive polynomial. */

     if dipzero!? p then dipzero
                   else dipmoncomp(bcprod(a, diplbc p),
                                   dipevlmon p,
                                   dipbcprodin(dipmred p, a));


symbolic procedure dipdif (p1,p2);
%   /* Distributive polynomial difference. p1 and p2 are distributive
%    polynomials. dipdif(p1,p2) calculates the difference of the
%    two distributive polynomials p1 and p2, a distributive polynomial*/
     if dipzero!? p1 then dipneg p2
        else if dipzero!? p2 then p1
             else ( if sl = 1 then dipmoncomp(diplbc p1,
                                              ep1,
                                              dipdif(dipmred p1, p2) )
                  else if sl = -1 then dipmoncomp(bcneg diplbc p2,
                                                  ep2,
                                                  dipdif(p1,dipmred p2))
                       else ( if bczero!? al
                                then dipdif(dipmred p1, dipmred p2)
                              else dipmoncomp(al,
                                              ep1,
                                              dipdif(dipmred p1,
                                                     dipmred p2) )
                            ) where al = bcdif(diplbc p1, diplbc p2)
            ) where sl = evcomp(ep1, ep2)
                 where ep1 = dipevlmon p1, ep2 = dipevlmon p2;

symbolic procedure   diplength p;
%   /* Distributive polynomial length. p is a distributive
%     polynomial. diplength(p) returns the number of terms
%     of the distributive polynomial p, a digit.*/

     if dipzero!? p then 0 else 1 + diplength dipmred p;



symbolic procedure   diplistsum pl;
%   /* Distributive polynomial list sum. pl is a list of distributive
%     polynomials. diplistsum(pl) calculates the sum of all polynomials
%     and returns a list of one distributive polynomial. */

     if null pl or null cdr pl then pl
        else diplistsum(dipsum(car pl, cadr pl) . diplistsum cddr pl);



symbolic procedure   diplmerge (pl1,pl2);
%  /* Distributive polynomial list merge. pl1 and pl2 are lists
%    of distributive polynomials where pl1 and pl2 are in non
%    decreasing order. diplmerge(pl1,pl2) returns the merged
%    distributive polynomial list of pl1 and pl2. */

    if null pl1 then pl2
       else if null pl2 then pl1
            else ( if sl >= 0 then cpl1 . diplmerge(cdr pl1, pl2)
                 else cpl2 . diplmerge(cdr pl2, pl1)
           ) where sl = evcomp(ep1, ep2)
                where ep1 = dipevlmon cpl1, ep2 = dipevlmon cpl2
                where cpl1 = car pl1, cpl2 = car pl2;

symbolic procedure   diplsort pl;
%  /* Distributive polynomial list sort. pl is a list of
%    distributive polynomials. diplsort(pl) returns the
%    sorted distributive polynomial list of pl.
   sort(pl, function dipevlcomp);

symbolic procedure   dipevlcomp (p1,p2);
%  /*  Distributive polynomial exponent vector leading monomial
%     compare. p1 and p2 are distributive polynomials.
%     dipevlcomp(p1,p2) returns a boolean expression true if the
%     distributive polynomial p1 is smaller or equal the distributive
%     polynomial p2 else false. */

   not evcompless!?(dipevlmon p1, dipevlmon p2);



symbolic procedure   dipmonic p;
%   /* Distributive polynomial monic. p is a distributive
%     polynomial. dipmonic(p) computes p/lbc(p) if p is
%     not equal dipzero and returns a distributive
%     polynomial, else dipmonic(p) returns dipzero. */

     if dipzero!? p then p
                   else dipbcprod(p, bcinv diplbc p);



symbolic procedure   dipneg p;
%  /* Distributive polynomial negative. p is a distributive
%    polynomial. dipneg(p) returns the negative of the distributive
%    polynomial p, a distributive polynomial. */

    if dipzero!? p then p
       else dipmoncomp ( bcneg diplbc p,
                         dipevlmon p,
                         dipneg dipmred p );



symbolic procedure   dipone!? p;
%  /* Distributive polynomial one.  p is a distributive polynomial.
%    dipone!?(p) returns a boolean value. If p is the distributive
%    polynomial one then true else false. */

    not dipzero!? p
        and dipzero!? dipmred p
            and evzero!? dipevlmon p
                and bcone!? diplbc p;



symbolic procedure   dippairsort pl;
%  /* Distributive polynomial list pair merge sort. pl is a list
%    of distributive polynomials. dippairsort(pl) returns the
%    list of merged and in non decreasing order sorted
%    distributive polynomials. */

    if null pl or null cdr pl then pl
       else diplmerge(diplmerge( car(pl) . nil, cadr(pl) . nil ),
                      dippairsort cddr pl);



symbolic procedure   dipprod (p1,p2);
%   /* Distributive polynomial product. p1 and p2 are distributive
%    polynomials. dipprod(p1,p2) calculates the product of the
%    two distributive polynomials p1 and p2, a distributive polynomial*/

     if diplength p1 <= diplength p2 then dipprodin(p1, p2)
        else dipprodin(p2, p1);



symbolic procedure   dipprodin (p1,p2);
%   /* Distributive polynomial product internal. p1 and p2 are distrib
%    polynomials. dipprod(p1,p2) calculates the product of the
%    two distributive polynomials p1 and p2, a distributive polynomial*/

     if dipzero!? p1 or dipzero!? p2 then dipzero
        else ( dipmoncomp(bcprod(bp1, diplbc p2),
                        evsum(ep1, dipevlmon p2),
                        dipsum(dipprodin(dipfmon(bp1, ep1),
                                         dipmred p2),
                               dipprodin(dipmred p1, p2) ) )
             ) where bp1 = diplbc p1,
                     ep1 = dipevlmon p1;



symbolic procedure   dipprodls (p1,p2);
%   /* Distributive polynomial product. p1 and p2 are distributive
%     polynomials. dipprod(p1,p2) calculates the product of the
%     two distributive polynomials p1 and p2, a distributive polynomial
%     using distributive polynomials list sum (diplistsum). */

     if dipzero!? p1 or dipzero!? p2 then dipzero
        else car diplistsum if diplength p1 <= diplength p2
                               then dipprodlsin(p1, p2)
                               else dipprodlsin(p2, p1);



symbolic procedure   dipprodlsin (p1,p2);
%   /* Distributive polynomial product. p1 and p2 are distributive
%     polynomials. dipprod(p1,p2) calculates the product of the
%     two distributive polynomials p1 and p2, a distributive polynomial
%     using distributive polynomials list sum (diplistsum). */

     if dipzero!? p1 or dipzero!? p2 then nil
        else ( dipmoncomp(bcprod(bp1, diplbc p2),
                          evsum(ep1, dipevlmon p2),
                          car dipprodlsin(dipfmon(bp1, ep1),
                                          dipmred p2))
                          . dipprodlsin(dipmred p1, p2)
             ) where bp1 = diplbc p1,
                     ep1 = dipevlmon p1;



symbolic procedure   dipsum (p1,p2);
%  /* Distributive polynomial sum. p1 and p2 are distributive
%    polynomials. dipsum(p1,p2) calculates the sum of the
%    two distributive polynomials p1 and p2, a distributive polynomial*/

    if dipzero!? p1 then p2
       else if dipzero!? p2 then p1
            else ( if sl = 1 then dipmoncomp(diplbc p1,
                                             ep1,
                                             dipsum(dipmred p1, p2) )
                 else if sl = -1 then dipmoncomp(diplbc p2,
                                                 ep2,
                                                 dipsum(p1,dipmred p2))
                      else ( if bczero!? al then dipsum(dipmred p1,
                                                        dipmred p2)
                             else dipmoncomp(al,
                                             ep1,
                                             dipsum(dipmred p1,
                                                    dipmred p2) )
                           ) where al = bcsum(diplbc p1, diplbc p2)
           ) where sl = evcomp(ep1, ep2)
                where  ep1 = dipevlmon p1, ep2 = dipevlmon p2;

endmodule;


module dipvars;

%/* Determine distributive polynomial variables in a prefix form*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

expr procedure dipvars u;
%   /* Returns list of variables in prefix form u*/
   dipvars1(u,nil);

expr procedure dipvars1(u,v);
   if atom u then if constantp u or u memq v then v else u . v
    else if idp car u and get(car u,'dipfn)
     then dipvarslist(cdr u,v)
    else if u memq v then v
    else u . v;

expr procedure dipvarslist(u,v);
   if null u then v
    else dipvarslist(cdr u,union(dipvars car u,v));

endmodule;


module expvec;

% /*Specific support for distributive polynomial exponent vectors*/

% /* Authors: R. Gebauer, A. C. Hearn, H. Kredel */

%   We assume here that an exponent vector is a list of integers.  This
%   version uses small integer arithmetic on the individual exponents
%   and assumes that a compiled function can be dynamically redefined*/

%   Modification H. Melenk (August 1988)
%   1. Most ev-routines handle exponent vectors with variable length:
%      the convention is, that trailing zeros may be omitted.
%   2. evcompless!? is mapped to evcomp such that each term order mode
%      is supported by exactly one procedure entry.
%   3. complete exponent vector compare collected in separate module
%      TORDER (TORD33)

fluid '(dipsortmode!* dipvars!*);


expr procedure evperm (e1,n);
%  /* Exponent vector permutation. e1 is an exponent vector, n is a
%    index list , a list of digits. evperm(e1,n) returns a list e1
%    permuted in respect to n. */
     if null n then nil
        else evnth(e1, car n) . evperm(e1, cdr n);


expr procedure evcons (e1,e2);
%  /* Exponent vector construct. e1 and e2 are exponents. evcons(e1,e2)
%    constructs an exponent vector. */
     e1 . e2;


expr procedure evnth (e1,n);
%  /* Exponent vector n-th element. e1 is an exponent vector, n is a
%    digit. evnth(e1,n) returns the n-th element of e1, an exponent. */
     if null e1 then 0 else
     if n = 1 then evfirst e1 else evnth(evred e1, n - 1);


expr procedure evred e1;
%  /* Exponent vector reductum. e1 is an exponent vector. evred(e1)
%    returns the reductum of the exponent vector e1. */
     if e1 then cdr e1 else nil;


expr procedure evfirst e1;
%  /* Exponent vector first. e1 is an exponent vector. evfirst(e1)
%   returns the first element of the exponent vector e1, an exponent. */
     if e1 then car e1 else 0;


expr procedure evsum0(n,p);
% exponent vector sum version 0. n is the length of dipvars!*.
% p is a distributive polynomial.
  if dipzero!? p then evzero1 n else
  evsum(dipevlmon p, evsum0(n,dipmred p));


expr procedure evzero1 n;
% Returns the exponent vector power representation
% of length n for a zero power.
  begin scalar x;
   for i:=1: n do << x := 0 . x >>;
  return x
  end;


expr procedure indexcpl(ev,n);
% returns a list of indexes of non zero exponents.
  if null ev then ev else ( if car ev = 0 then
                            indexcpl(cdr ev,n + 1) else
     ( n . indexcpl(cdr ev,n + 1))  );


expr procedure evzer1!? e;
% returns a boolean expression. true if e is null else false.
  null e;


expr procedure evzero!? e;
%  /* Returns a boolean expression. True if all exponents are zero*/
   null e or car e = 0 and evzero!? cdr e;


expr procedure evzero;
%  /* Returns the exponent vector representation for a zero power*/
   % for i := 1:length dipvars!* collect 0;
   begin scalar x;
      for i := 1:length dipvars!* do <<x := 0 . x>>;
      return x
   end;


expr procedure mkexpvec u;
%  /* Returns an exponent vector with a 1 in the u place*/
   if not(u member dipvars!*) then typerr(u,"dipoly variable")
    else for each x in dipvars!* collect if x eq u then 1 else 0;


expr procedure evlcm (e1,e2);
%  /* Exponent vector least common multiple. e1 and e2 are
%    exponent vectors. evlcm(e1,e2) computes the least common
%    multiple of the exponent vectors e1 and e2, and returns
%    an exponent vector. */
   % for each lpart in e1 each rpart in e2 collect
   %     if lpart #> rpart then lpart else rpart;
   begin scalar x;
      while e1 and e2 do
         <<x := (if car e1 #> car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      return reversip x
   end;


symbolic procedure evmtest!? (e1,e2);
%  /* Exponent vector multiple test. e1 and e2 are compatible exponent
%    vectors. evmtest!?(e1,e2) returns a boolean expression.
%    True if exponent vector e1 is a multiple of exponent
%    vector e2, else false. */
   if e1 and e2 then not(car e1 #< car e2) and evmtest!?(cdr e1,cdr e2)
   else  evzero!? e2 ;


expr procedure evsum (e1,e2);
%  /* Exponent vector sum. e1 and e2 are exponent vectors.
%    evsum(e1,e2) calculates the sum of the exponent vectors.
%    e1 and e2 componentwise and returns an exponent vector. */
   % for each lpart in e1 each rpart in e2 collect lpart #+ rpart;
     begin scalar x;
      while e1 and e2 do
         <<x := (car e1 #+ car e2) . x; e1 := cdr e1; e2 := cdr e2>>;
      x :=  reversip x;
      return if e1 then nconc(x,e1) else
             if e2 then nconc(x,e2) else x;
   end;


expr procedure evdif (e1,e2);
%  /* Exponent vector difference. e1 and e2 are exponent
%    vectors. evdif(e1,e2) calculates the difference of the
%    exponent vectors e1 and e2 componentwise and returns an
%    exponent vector. */
   % for each lpart in e1 each rpart in e2 collect lpart #- rpart;
   begin scalar x;
      while e2 do
         <<if null e1 then e1 := '(0);
           x := (car e1 #- car e2) . x; e1 := cdr e1; e2 := cdr e2>>;
      return nconc (reversip x,e1);
   end;


expr procedure intevprod(n,e);
% /* Multiplies each element of the exponent vector u by the integer n*/
   for each x in e collect n #* x;


expr procedure expvec2a e;
%  /* Returns list of prefix equivalents of exponent vector e*/
   expvec2a1(e,dipvars!*);


expr procedure expvec2a1(u,v);
%  /* Sub function of expvec2a */
   if null u then nil
    else if car u = 0 then expvec2a1(cdr u,cdr v)
    else if car u = 1 then car v . expvec2a1(cdr u,cdr v)
    else list('expt,car v,car u) . expvec2a1(cdr u,cdr v);


expr procedure dipevlpri(e,v);
%  /* Print exponent vector e in infix form. V is a boolean variable
%    which is true if an element in a product has preceded this one*/
   dipevlpri1(e,dipvars!*,v);


expr procedure dipevlpri1(e,u,v);
%  /* Sub function of dipevlpri */
   if null e then nil
    else if car e = 0 then dipevlpri1(cdr e,cdr u,v)
    else <<if v then dipprin2 "*";
           dipprin2 car u;
           if car e #> 1 then <<dipprin2 "**"; dipprin2 car e>>;
           dipevlpri1(cdr e,cdr u,t)>>;

endmodule;



module torder; % Term order modes for distributive polynomials.
               % New interface, based on one routine per order
               % mode.
               % H. Melenk, ZIB Berlin
 
fluid '(dipsortmode!* dipsortevcomp!* olddipsortmode!*);
fluid '(vdpsortmode!* vdpsortextension!*);
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   switching between term order modes: TORDER statement.
%

symbolic procedure torder u;
  begin scalar oldmode,oldex;
   oldmode := vdpsortmode!*; oldex := vdpsortextension!*;
   vdpsortmode!* := reval car u;
   vdpsortextension!* := for each x in cdr u collect reval x;
   return if null oldex then oldmode 
          else 'list . oldmode . oldex;
  end;

put('torder,'stat,'rlis);

symbolic procedure dipsortingmode u;
%  /* Sets the exponent vector sorting mode. Returns the previous mode*/
         begin scalar x,y,z;
            if not idp u or
                  (not flagp(u,'dipsortmode)
                    and null (y:= assoc(u,olddipsortmode!*)))
                 then return typerr(u,"term ordering mode");
            if y then
            <<prin2 "**** warning: TORDER ";
              prin2 u;
              prin2 " no longer supported; using ";
              prin2 cdr y;
              prin2t " instead";
              u := cdr y>>;
            x := dipsortmode!*; dipsortmode!* := u; 
                % saves thousands of calls to GET;
            dipsortevcomp!* := get(dipsortmode!*,'evcomp); 
            if not getd dipsortevcomp!* then
               rerror(dipoly,2,
                      "No compare routine for term order mode found");
            if (z:=get(dipsortmode!*,'evcompinit)) then apply(z,nil);
            return x
         end;
 
 
olddipsortmode!*:= '((invlex . lex)(invtotaldegree . totaldegree)
                     (totaldegree . revgradlex));

flag('(lex gradlex revgradlex),'dipsortmode);
 
put('lex,'evcomp,'evlexcomp);
 
put('gradlex,'evcomp,'evgradlexcomp);
 
put('revgradlex,'evcomp,'evrevgradlexcomp);
 
symbolic procedure evcompless!?(e1,e2);
%    Exponent vector compare less. e1, e2 are exponent vectors
%    in some order. Evcompless? is a boolean function which returns
%    true if e1 is ordered less than e2.
%    Mapped to evcomp
    1 = evcomp(e2,e1);

symbolic procedure evcomp (e1,e2);
%   Exponent vector compare. e1, e2 are exponent vectors in some
%    order.  Evcomp(e1,e2) returns the digit 0 if exponent vector e1 is
%    equal exponent vector e2, the digit 1 if e1 is greater than e2,
%    else the digit -1. This function is assigned a value by the
%    ordering mechanism, so is dummy for now.
% IDapply would be better here, but is not within standard LISP!
   apply(dipsortevcomp!*,list(e1,e2));


symbolic procedure evlexcomp (e1,e2);
%  /* Exponent vector lexicographical compare. The
%    exponent vectors e1 and e2 are in lexicographical
%    ordering. evLexComp(e1,e2) returns the digit 0 if exponent
%    vector e1 is equal exponent vector e2, the digit 1 if e1 is
%    greater than e2, else the digit -1. */
   if null e1 then 0
    else if null e2 then evlexcomp(e1,'(0))
    else if car e1 #- car e2 =0 then evlexcomp(cdr e1,cdr e2)
    else if car e1 #> car e2 then 1
    else -1;
 
 
symbolic procedure evgradlexcomp (e1,e2);
%  /* Exponent vector graduated lex compare.
%    The exponent vectors e1 and e2 are in graduated lex
%    ordering. evGradLexComp(e1,e2) returns the digit 0 if exponent
%    vector e1 is equal exponent vector e2, the digit 1 if e1 is
%    greater than e2, else the digit -1. */
   if null e1 then 0
    else if null e2 then evgradlexcomp(e1,'(0))
    else if car e1 #- car e2 =0 then evgradlexcomp(cdr e1, cdr e2)
    else (if te1#-te2=0 then if car e1 #> car e2 then 1 else -1
          else if te1 #> te2 then 1 else -1)
          where te1 = evtdeg e1, te2 = evtdeg e2;
 
 
symbolic procedure evrevgradlexcomp (e1,e2);
%  /* Exponent vector reverse graduated lex compare.
%    The exponent vectors e1 and e2 are in reverse graduated lex
%    ordering. evRevGradLexcomp(e1,e2) returns the digit 0 if exponent
%    vector e1 is equal exponent vector e2, the digit 1 if e1 is
%    greater than e2, else the digit -1. */
   if null e1 then 0
    else if null e2 then evrevgradlexcomp(e1,'(0))
    else if car e1 = car e2 then evrevgradlexcomp(cdr e1, cdr e2)
    else (if te1 = te2 then evlexcomp(e2,e1)  % here lex reversed
          else if te1 #> te2 then 1 else -1)
          where te1 = evtdeg e1, te2 = evtdeg e2;
 

symbolic procedure evtdeg e1;
%  /* Exponent vector total degree. e1 is an exponent vector.
%    evtdeg(e1) calculates the total degree of the exponent
%    e1 and returns an integer. */
   (<<while e1 do <<x := car e1 #+ x; e1 := cdr e1>>; x>>) where x = 0;
 

% The following secion contains additional term order modes.
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  gradlexgradlex
%
%  this order can have several steps
%      torder gradlexgradlex,3,2,4;
%  


flag ('(gradlexgradlex),'dipsortmode);
flag ('(gradlexgradlex),'dipsortextension);
put('gradlexgradlex,'evcomp,'evgradgradcomp);

symbolic procedure evgradgradcomp (e1,e2);
      evgradgradcomp1 (e1,e2,car vdpsortextension!*,
                             cdr vdpsortextension!*);

symbolic procedure evgradgradcomp1 (e1,e2,n,nl);
   if null e1 then 0
    else if null e2 then evgradgradcomp1(e1,'(0),n,nl)
    else if n=0 then if null nl then evgradlexcomp(e1,e2)
                   else evgradgradcomp1 (e1,e2,car nl,cdr nl)
    else if car e1 = car e2 then 
              evgradgradcomp1(cdr e1,cdr e2,n#-1,nl)
    else (if te1 = te2 then if car e1 #< car e2 then 1 else -1
           else if te1 #> te2 then 1 else -1)
          where te1 = evpartdeg(e1,n), te2 = evpartdeg(e2,n);

symbolic procedure evpartdeg(e1,n); evpartdeg1(e1,n,0); 
  
symbolic procedure evpartdeg1(e1,n,sum); 
     if n = 0 or null e1 then sum 
      else evpartdeg1(cdr e1,n #-1, car e1 #+ sum); 
  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  gradlexrevgradlex
%
%


flag ('(gradlexrevgradlex),'dipsortmode);
flag ('(gradlexrevgradlex),'dipsortextension);
put('gradlexrevgradlex,'evcomp,'evgradrevgradcomp);

symbolic procedure evgradrevgradcomp (e1,e2);
      evgradrevgradcomp1 (e1,e2,car vdpsortextension!*);

symbolic procedure evgradrevgradcomp1 (e1,e2,n);
   if null e1 then 0
    else if null e2 then evgradrevgradcomp1(e1,'(0),n)
    else if n=0 then evrevgradlexcomp(e1,e2)
    else if car e1 = car e2 then evgradrevgradcomp1(cdr e1,cdr e2,n#-1)
    else (if te1 = te2 then if car e1 #< car e2 then 1 else -1
           else if te1 #> te2 then 1 else -1)
          where te1 = evpartdeg(e1,n), te2 = evpartdeg(e2,n);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  LEXGRADLEX
%
%


flag ('(lexgradlex),'dipsortmode);
flag ('(lexgradlex),'dipsortextension);
put('lexgradlex,'evcomp,'evlexgradlexcomp);


symbolic procedure evlexgradlexcomp (e1,e2);
      evlexgradlexcomp1 (e1,e2,car vdpsortextension!*);

symbolic procedure evlexgradlexcomp1 (e1,e2,n);
   if null e1 then (if evzero!? e2 then 0 else -1)
    else if null e2 then evlexgradlexcomp1(e1,'(0),n)
    else if n=0 then evgradlexcomp(e1,e2)
    else if car e1 = car e2 then evlexgradlexcomp1(cdr e1,cdr e2,n#-1)
    else if car e1 #> car e2 then 1 else -1;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  LEXREVGRADLEX
%
%
 
 
flag ('(lexrevgradlex),'dipsortmode);
flag ('(lexrevgradlex),'dipsortextension);
put('lexrevgradlex,'evcomp,'evlexrevgradlexcomp);
 
 
symbolic procedure evlexrevgradlexcomp (e1,e2);
      evlexrevgradlexcomp1 (e1,e2,car vdpsortextension!*);
 
symbolic procedure evlexrevgradlexcomp1 (e1,e2,n);
   if null e1 then (if evzero!? e2 then 0 else -1)
    else if null e2 then evlexrevgradlexcomp1(e1,'(0),n)
    else if n=0 then evrevgradlexcomp(e1,e2)
    else if car e1 = car e2 then 
                   evlexrevgradlexcomp1(cdr e1,cdr e2,n#-1)
    else if car e1 #> car e2 then 1 else -1;
 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  WEIGHTED
%
%

                                                  
flag ('(weighted),'dipsortmode);
flag ('(weighted),'dipsortextension);
put('weighted,'evcomp,'evweightedcomp);


symbolic procedure evweightedcomp (e1,e2);
     (if dg1 = dg2 then evlexcomp(e1,e2) else
      if dg1 #> dg2 then 1 else -1
       ) where dg1=evweightedcomp1(e1,vdpsortextension!*),
               dg2=evweightedcomp1(e2,vdpsortextension!*);

symbolic procedure evweightedcomp1 (e,w);         
  % scalar product of exponent and weight vector
   if null e then 0 else
   if null w then evweightedcomp1 (e,'(1 1 1 1 1)) else
   car e #* car w #+ evweightedcomp1(cdr e,cdr w);




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% PRIVATE
%
%

fluid '(dipvars!*);
flag ('(private),'dipsortmode);
flag ('(lexgradlex),'dipsortextension);
put('private,'evcomp,'evprivatecomp);
put('private,'evcompinit,'evprivateinit);

fluid '(evprivate1!*,evprivate2!*,evprivatel!*,evprivatefn!*);
 
symbolic procedure evprivateinit();
  begin integer n; scalar m,v1,v2,v3;
     n:=length dipvars!*;
     evprivatefn!* := car vdpsortextension!*;
     if null getd evprivatefn!* then
       rerror(dipoly,3,
              "Second parameter for private torder is not a function");
     evprivatel!* := n;
     evprivate1!* := mkvect n;
     evprivate2!* := mkvect n;
         % compatibility test
     v1 := for i:=1:n collect 1+random(50);
     while (null v2 or v1=v2) do
       v2 := for i:=1:n collect 1+random(50);
     v3 := ((car v1) + 1 ) . cdr v1;
     m := list(
        evprivatecomp (v1,v1),
        evprivatecomp (v2,v2),
        evprivatecomp (v1,v3),
        evprivatecomp (v3,v1),
        evprivatecomp (reverse v1,reverse v3),    
        evprivatecomp (reverse v3,reverse v1),
        evprivatecomp (v1,v2)*evprivatecomp (v2,v1));
     if not(m='(0 0 -1 1 -1 1 -1))then
            rerror(dipoly,4,"Private order not admissible")
   end;

symbolic procedure evprivatecomp (e1,e2);
     <<evprivatespread(e1,e2,1);
      apply(evprivatefn!*,list(evprivate1!*,evprivate2!*))>>;

symbolic procedure evprivatespread (e1,e2,n);
    if n #> evprivatel!* then nil
    else (<<putv(evprivate1!*,n,x1);putv(evprivate2!*,n,x2);
            evprivatespread (y1,y2,n#+1)>>) 
           where x1 = if e1 then car e1 else 0,
                 x2 = if e2 then car e2 else 0,
                 y1 = if e1 then cdr e1 else nil,
                 y2 = if e2 then cdr e2 else nil;


% symbolic procedure specimen(v1,v2);
%   % simulating a 2 dim lex ordering.
%    if getv(v1,1) < getv(v2,1) then -1 else
%    if getv(v1,1) > getv(v2,1) then  1 else
%    if getv(v1,2) < getv(v2,2) then -1 else
%    if getv(v1,2) > getv(v2,2) then  1 else 0;
%
% torder private,specimen;

endmodule;


module vdp2dip;

imports dipoly;

% create!-package('(vdp2dip vdpcom vdp2dip1),
%                 '(contrib dipoly));

% load!-package 'dipoly;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% interface for Virtual Distributive Polynomials (VDP)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% "Distributive representation" with respect to  a given set of
% variables  ("vdpvars") means for a polynomial, that the polynomial
% is regarded as  a sequence of monomials, each of which is a
% product of a "coefficient"  and of some powers of the variables.
% This internal representation is  very closely connected to the
% standard external (printed) representation of a  polynomial in
% REDUCE if nothing is factored out. The monomials are locically
% ordered by a term order mode based on the  ordering which is
% given bye the sequence "vdpvars"; with respect to this  ordering
% the representation of a polynomial is unique. The "highest" term
%  is the car one. Monomials are represented by their coefficient
% ("vbc") and by  a vector of the exponents("vev") (in the order 
% corresponding to the  vector vars). The distributive representation
% is good for those algorithms, which  base their decisions on the
% complete ledading monomial:  this representation guarantees a 
% fast and uniform access to the car monomial and to the reductum
% (the cdr of the polynomial beginning with the cadr monomial).
% The algorithms of the Groebner package are of this type.  The 
% interface defines the distributive polynomials as abstract data
% objects via their acess functions. These functions map the
% distributive operations to an arbitrary real data structure
% ("virtual"). The mapping of the access functions to an actual
% data structure is cdrricted only by the demand, that the typical
% "distributive operations" be efficient.  Additionally to the
% algebraic value a VDP object has a property list. So the algorithms
% using the  VDP interface can assign name-value-pairs to individual
% polynomials. The interface is defined by a set of routines which
% create and handle the distributive polynomials. In general the
% car letters of the routine name classifies the data its works on:
 
%   vdp...      complete virt. polynomial objects
%   vbc...      virt. base coefficients
%   vev...      virt. exponent vectors
 
% 0. general control
%
%   vdpinit(dv) initialises the vdp package for the variables
%              given in the list "dv". vdpinit modifies the
%              torder and returns the prvevious torder as its
%              result. vdpinit sets the global variable
%              vdpvars!*;
 
% 1. conversion
%
%   a2vdp      algebraic (prefix) to vdp
%   f2vdp      standard form to vdp
%   a2vbc      algebraic (prefix) to vbc
%   vdp2a      vdp to algebraic (prefix)
%   vdp2f      vdp to standard form
%   vbc2a      vbc to algebraic (prefix)
 
% 2. composing/decomposing
%
%   vdpfmon    make a vdp from a vbc and an vev
%   vdpMonComp add a monomial (vbc and vev) to the front of a vdp
%   vdpAppendMon add a monomial (vbc and vev) to the bottom of a vdp
%   vdpMonAdd  add a monomial (vbc and vev) to a vdp, not yet 
%              knowing the place of the insertion
%   vdpAppendVdp concat two vdps
%
%   vdpLbc     extract leading vbc
%   vdpevlmon  extract leading vev
%   vdpred     reductum of vbc
%   vevnth      nth element from exponent vector
 
% 3. testing
%
%   vdpZero?    test vdp = 0
%   vdpredZero!? test rductum of vdp = 0
%   vdpOne?     test vdp = 1
%   vevZero?    test vev = (0 0 ... 0)
%   vbczero?    test vbc = 0
%   vbcminus?   test vbc <= 0 (not decidable for algebraic vbcs)
%   vbcplus?    test vbc >= 0 (not decidable for algebraic vbcs)
%   vbcone!?    test vbc = 1
%   vbcnumberp  test vbc is a numeric value
%   vevdivides? test if vev1 < vev2 elementwise
%   vevlcompless?  test ordering vev1 < vev2
%   vdpvevlcomp    calculate ordering vev1 / vev1: -1, 0 or +1
%   vdpEqual   test vdp1 = vdp2
%   vdpMember  member based on "vdpEqual"
%   vevequal    test vev1 = vev2
 
% 4. arithmetic
%
% 4.1 vdp arithmetic
%
%  vdpsum       vdp + vdp
%               special routines for monomials: see above (2.)
%  vdpdif       vdp - vdp
%  vdpprod      vdp * vdp
%  vdpvbcprod   vbc * vdp
%  vdpDivMon    vdp / (vbc,vev)  divisability presumed
%  vdpCancelvev substitute all multiples of monomial (1,vev) in vdp by 0
%  vdpLcomb1    vdp1*(vbc1,vev1) + vdp2*(vbc2,vev2)
%  vdpContent   calculate gcd over all vbcs
 
% 4.2 vbc arithmetic
%
%  vbcsum       vbc1 + vbc2
%  vbcdif       vbc1 - vbc2
%  vbcneg       - vbc
%  vbcprod      vbc1 * vbc2
%  vbcquot      vbc1 / vbc2     divisability assumed if domain = ring
%  vbcinv       1 / vbc        only usable in field
%  vbcgcd       gcd(vbc1,vbc2)  only usable in Euclidean field
 
% 4.2 vev arithmetic
%
% vevsum        vev1 + vev2 elementwise
% vevdif        vev1 - vev2 elementwise
% vevtdeg       sum over all exponents
% vevzero       generate a zero vev
 
% 5, auxiliary
%
% vdpPutProp   assign indicator-value-pair to vdp
%              the property "number" is used for printing.
% vdpGetProp   read value of indicator from vdp
% vdplSort     sort list of polynomials with respect to ordering
% vdplSortIn   sort a vdp into a sorted list of vdps
% vdpprint     print a vdp together with its number
% vdpprin2t    print a vdp "naked"
% vdpprin3t    print a vdp with closing ";"
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% RECCORD STRUCTURE
%
% a virtual polynomial here is a record (list) with the entries
%    ('vdp <vdpevlmon> <vdplbc> <form> <plist>)
%
%     'vdp        a type tag
%     <vdpevlmon> the exponents of the variables in the leading
%                 leading monomial; the positions correspond to
%                 the positions in vdpvars!*. Trailing zeroes
%                 can be omitted.
%
%     <lcoeff>    the "coeffcient" of the leading monomial, which
%                 in general is a standard form.
%
%     <form>      the complete polynomial,e.g.as REDUCE standard form.
%
%     <plist>     an asso list for the properties of the polynomial
%
% The components should not be manipulated only via the interface
% functions and macros, so that application programs remain
% independent from the internal representation.
% The only general assumption made on <form> is, that the zero
% polynomial is represented as NIL. That is the case e.g. for both,
% REDUCE standard forms and DIPOLYs.
 
% Conventions for the usage:
% -------------------------
%
%    vdpint has to be called prveviously to all vdp calls. The list of
%    vdp paraemters is passed to vdpinit. The value of vdpvars!*
%    and the current torder must remain unmodfied afterwards.
%    usual are simple id's, e.g.
%
%
% Modifications to vdpvars!* during calculations
% ----------------------------------------------
%
% This mapping of vdp operations to standard forms offers the
% ability to enlarge vdpvars during the calculation in order
% to add new (intermediate) variables. Basis is the convention,
% that exponent vectors logically have an arbitrary number
% of trailing zeros. All routines processing exponent vectors
% are able to handle varying length of exponent vectors.
% A new call to vdpinit is necessary.
%
% During calculation vdpvars may be enlarged (new variables
% suffixed) without needs to modify existing polynomials; only
% korder has to be set to the new variable sequence.
% modifications to the sequence in vdpvars requires a
% new call to vdpinit  and a reordering of exisiting
% polynomials, e.g. by
%          vdpint newvdpvars;
%          f2vdp vdp2f p1; f2vdp vdp2f p2; .....
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% DECLARATION SECTION
%
%  this module must be present during code generation for modules
%  using the vdp - sf interface

 
fluid '(vdpvars!* intvdpvars!* secondvalue!* vdpsortmode!* !*groebrm
        !*vdpinteger !*trgroeb !*trgroebs !*groebdivide pcount!*);
 
global '(vdpprintmax groebmonfac);
 
flag('(vdpprintmax),'share);
 
% basic internal constructor of vdp-record
smacro procedure makevdp (vbc,vev,form); list('vdp,vev,vbc,form,nil);

% basic selectors (conversions)
 
smacro procedure vdppoly u; cadr cddr u;

smacro procedure vdplbc u; caddr u;
 
smacro procedure vdpevlmon u; cadr u;
 
% basic tests
 
smacro procedure vdpzero!? u;
    null u or null vdppoly u;
 
smacro procedure vevzero!? u;
    null u or (car u = 0 and vevzero!?1 cdr u);

smacro procedure vdpone!? p;
     not vdpzero!? p and vevzero!? vdpevlmon p;

% base coefficients
 
%  manipulating of exponent vectors
 
smacro procedure vevdivides!? (vev1,vev2); vevmtest!? (vev2,vev1);
 
smacro procedure vevzero();
        vevmaptozero1(vdpvars!*,nil);
 
smacro procedure vdpnumber f; vdpgetprop(f,'number) ;
 
 
% the code for checkpointing is factored out
% This version: NO CHECKPOINT FACILITY
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% interface for DIPOLY polynomials as records (objects).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
 
fluid '(intvdpvars!* vdpvars!* secondvalue!* vdpsfsortmode!* !*groebrm
        !*vdpinteger !*trgroeb !*trgroebs !*groebdivide pcount!*
        !*groebsubs);
 
fluid '(vdpsortmode!*);
 
global '(vdpprintmax groebmonfac);
flag('(vdpprintmax),'share);
 
fluid '(dipvars!* !*vdpinteger);
 
symbolic procedure dip2vdp u;
 % is unsed when u can be empty
   (if dipzero!? uu then makevdp(a2bc 0,nil,nil)
                    else makevdp(diplbc uu,dipevlmon uu,uu))
           where uu = if !*groebsubs then dipsubs2 u else u;

% some simple mappings
 
smacro procedure makedipzero(); nil;
 
symbolic procedure vdpredzero!? u; dipzero!? dipmred vdppoly u;
 
symbolic procedure vbczero!? u; bczero!? u;
 
symbolic procedure vbcnumber u; 
       if  pairp u and numberp car u and 1=cdr u then cdr u else nil;

symbolic procedure vbcfi u; bcfi u;
 
symbolic procedure a2vbc u; a2bc u;
 
symbolic procedure vbcquot(u,v); bcquot(u,v);
 
symbolic procedure vbcneg u; bcneg u;
 
symbolic procedure vbcabs u; if vbcminus!? u then bcneg u else u; 
 
symbolic procedure vbcone!? u; bcone!? u; 
 
symbolic procedure vbcprod (u,v); bcprod(u,v);
 
 % initializing vdp-dip polynomial package
symbolic procedure vdpinit2(vars);
  begin scalar oldorder;
    oldorder := kord!*;
    if null vars then rerror(dipoly,8,"Vdpinit: vdpvars not set");
    vdpvars!* := dipvars!* := vars;
    torder2 vdpsortmode!*;
    return oldorder;
  end;
 
symbolic procedure vdpred u;
    (if dipzero!? r then makevdp(nil ./ nil,nil,makedipzero())
                   else makevdp(diplbc r,dipevlmon r,r))
       where  r = dipmred vdppoly u;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  coefficient handling; here we assume that coefficients are
%  standard quotients;
%
 
symbolic procedure vbcgcd (u,v);
     if denr u = 1 and denr v = 1 then
       if fixp u and fixp numr v then gcdn(numr u,numr v)  ./ 1
            else gcdf!*(numr u,numr v) ./ 1
     else 1 ./ 1;
 
% the following functions must be redefinable
symbolic procedure vbcplus!? u; (numberp v and v>0) where v = numr u;
symbolic procedure bcplus!? u; (numberp v and v>0) where v = numr u;
 
symbolic procedure vbcminus!? u; 
       (numberp v and v<0) where v = numr u;
 
symbolic procedure vbcinv u; bcinv u;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  conversion between forms, vdps and prefix expressions
%
 
% prefix to vdp
symbolic procedure a2vdp u;
     if u=0 or null u then makevdp(nil ./ nil,nil,makedipzero())
     else (makevdp(diplbc r,dipevlmon r,r)  where  r = a2dip u);
 
% vdp to prefix
symbolic procedure vdp2a u; dip2a vdppoly u;
 
symbolic procedure vbc2a u; bc2a  u;
 
% form to vdp
symbolic procedure f2vdp(u);
     if u=0 or null u then makevdp(nil ./ nil,nil,makedipzero())
     else (makevdp(diplbc r,dipevlmon r,r)  where  r = f2dip u);
 
% vdp to form
symbolic procedure vdp2f u; dip2f vdppoly u;
 
% vdp from monomial
symbolic procedure vdpfmon (coef,vev); 
                 makevdp(coef,vev,dipfmon(coef,vev));
 
% add a monomial to a vdp in front (new vev and coeff)
symbolic procedure vdpmoncomp(coef,vev,vdp);
   if vdpzero!? vdp then vdpfmon(coef,vev)
         else
   if vbczero!? coef then vdp
         else
   makevdp(coef,vev,dipmoncomp(coef,vev,vdppoly vdp));
 
%add a monomial to the end of a vdp (vev remains unchanged)
symbolic procedure vdpappendmon(vdp,coef,vev);
   if vdpzero!? vdp then vdpfmon(coef,vev)
         else
   if vbczero!? coef then vdp
         else
   makevdp(vdplbc vdp,vdpevlmon vdp,
            dipsum(vdppoly vdp,dipfmon(coef,vev)));
 
% add monomial to vdp, place of new monomial still unknown
symbolic procedure vdpmonadd(coef,vev,vdp);
    if vdpzero!? vdp then vdpfmon(coef,vev) else
   (if c = 1 then vdpmoncomp(coef,vev,vdp) else
    if c = -1 then makevdp (vdplbc vdp,vdpevlmon vdp,
                               dipsum(vdppoly vdp,dipfmon(coef,vev)))
    else vdpsum(vdp,vdpfmon(coef,vev))
   ) where c = vevcomp(vev,vdpevlmon vdp);
 
symbolic procedure vdpzero(); a2vdp 0;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  comparing of exponent vectors
%
%
 
symbolic procedure vdpvevlcomp (p1,p2); 
                  dipevlcomp (vdppoly p1,vdppoly p2);
symbolic procedure vevilcompless!?(e1,e2); 1 = evilcomp(e2,e1);
symbolic procedure vevilcomp (e1,e2); evilcomp (e1,e2);
symbolic procedure vevcompless!?(e1,e2); 1 = evcomp(e2,e1);
symbolic procedure vevcomp (e1,e2); evcomp (e1,e2);
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  routines traversing the "coefficients"
%
 
% CONTENT of a vdp
% The content is the gcd of all coefficients.
 
symbolic procedure vdpcontent d; 
     if vdpzero!? d then a2bc 0 else
     <<d := vdppoly d;
       dipnumcontent(dipmred d,diplbc d)>>;
 
symbolic procedure vdpcontent1(d,c); dipnumcontent(vdppoly d,c);
 
symbolic procedure dipnumcontent(d,c);
     if bcone!? c or dipzero!? d then c
     else dipnumcontent(dipmred d,vbcgcd(c,diplbc d));
 
 
symbolic procedure dipcontenti p;
% the content is a pair of the lcm of the coefficients and the
% exponent list of the common monomial factor.
   if dipzero!? p then 1 else
   (if dipzero!? rp then diplbc p .
                             (if !*groebrm then dipevlmon p else nil)
      else
    dipcontenti1(diplbc p,
                 if !*groebrm then dipevlmon p else nil,rp) )
                           where rp=dipmred p;
 
symbolic procedure dipcontenti1 (n,ev,p1);
   if dipzero!? p1 then n . ev
   else begin scalar nn;
             nn := vbcgcd (n,diplbc p1);
             if ev then ev := dipcontevmin(dipevlmon p1,ev);
             if bcone!? nn and null ev then return nn . nil
                       else return dipcontenti1 (nn,ev,dipmred p1)
       end;
 
 
 
% CONTENT and MONFAC (if groebrm on)
symbolic procedure vdpcontenti d;
       vdpcontent d . if !*groebrm then vdpmonfac d else nil;
 
symbolic procedure vdpmonfac d; dipmonfac vdppoly d;

symbolic procedure dipmonfac p;
% exponent list of the common monomial factor.
   if dipzero!? p or not !*groebrm then evzero()  
   else (if dipzero!? rp then dipevlmon p
         else dipmonfac1(dipevlmon p,rp) ) where rp=dipmred p;

symbolic procedure dipmonfac1(ev,p1);
   if dipzero!? p1 or evzero!? ev then ev
   else dipmonfac1(dipcontevmin(ev,dipevlmon p1),dipmred p1);


% vdpCoeffcientsFromDomain!?
symbolic procedure vdpcoeffcientsfromdomain!? w;
          dipcoeffcientsfromdomain!? vdppoly w;
 
symbolic procedure dipcoeffcientsfromdomain!? w;
      if dipzero!? w then t else
      (if denr v = 1 and domainp numr v then
              dipcoeffcientsfromdomain!? dipmred w
            else nil) where v =diplbc w;
 
symbolic procedure vdplength f; diplength vdppoly f;
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  polynomial operations:
%             coefficient normalization and reduction of monomial
%             factors
%
 
 
symbolic procedure vdpequal(p1,p2);
     p1 eq p2
     or (n1 and n1 = n2   % number comparison is faster most times
     or dipequal(vdppoly p1,vdppoly p2)
           where n1 = vdpgetprop(p1,'number),
                 n2 = vdpgetprop(p2,'number));

symbolic procedure dipequal(p1,p2);
    if dipzero!? p1 then dipzero!? p2
    else if dipzero!? p2 then nil
    else diplbc p1 = diplbc p2 
     and evequal(dipevlmon p1,dipevlmon p2)
     and dipequal(dipmred p1,dipmred p2);

symbolic procedure evequal(e1,e2);
   % test equality with variable length exponent vectors
     if null e1 and null e2 then t
     else if null e1 then evequal('(0),e2) 
     else if null e2 then evequal(e1,'(0))
     else 0=(car e1 #- car e2) and evequal(cdr e1,cdr e2);

symbolic procedure vdplcm p; diplcm vdppoly p;
 
symbolic procedure vdprectoint(p,q); dip2vdp diprectoint(vdppoly p,q);
 
symbolic procedure vdpsimpcont(p);
          begin scalar r;
              r := vdppoly p;
              if dipzero!? r then return p;
              r := dipsimpcont r;
              p := dip2vdp cdr r;  % the polynomial
              r := car r;          % the monomial factor if any
              if not evzero!? r then vdpputprop(p,'monfac,r);
              return p;
          end;
 
symbolic procedure dipsimpcont  (p);
    if !*vdpinteger or not !*groebdivide  then dipsimpconti p
                          else dipsimpcontr p;
 
% routines for integer coefficient case:
% calculation of contents and dividing all coefficients by it
 
symbolic procedure dipsimpconti (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar co,lco,res,num;
    if dipzero!?  p then return nil . p;
    co := bcfi 1;
    co := if !*groebdivide then dipcontenti p
             else if !*groebrm then co . dipmonfac p
             else co . nil;
    num := car co;
    if not bcplus!? num then num := bcneg num;
    if not bcplus!? diplbc p then num := bcneg num;
    if bcone!? num  and cdr co = nil  then return nil . p;
    lco := cdr co;
    if groebmonfac neq 0  then lco := dipcontlowerev cdr co;
    res := p;
    if not(bcone!? num and lco = nil) then
                 res := dipreduceconti (p,num,lco);
    if null cdr co then return nil . res;  
    lco := evdif(cdr co,lco);                
    return(if lco and not evzero!? evdif(dipevlmon res,lco)
                           then lco else nil).res;
    end;
 
symbolic procedure vdpreduceconti (p,co,vev);
%  divide polynomial p by monomial from co and vev
        vdpdivmon(p,co,vev);


 
%  divide all coefficients of p by cont
symbolic procedure dipreduceconti (p,co,ev);
    if dipzero!? p
         then makedipzero()
         else
           dipmoncomp ( bcquot (diplbc p,co),
                        if ev then evdif(dipevlmon p,ev)
                              else dipevlmon p,
                        dipreduceconti (dipmred p,co,ev));
 
 
% routines for rational coefficient case:
% calculation of contents and dividing all coefficients by it
 
symbolic procedure dipsimpcontr (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar co,lco,res;
    if dipzero!?  p then return nil . p;
    co := dipcontentr p;
    if bcone!? diplbc p  and co = nil  then return nil . p;
    lco := dipcontlowerev co;
    res := p;
    if not(bcone!? diplbc p and lco = nil) then
               res := dipreducecontr (p,bcinv diplbc p,lco);
    return (if co then evdif(co,lco) else nil) . res;
    end;
 
 
symbolic procedure dipcontentr p;
% the content is the exponent list of the common monomial factor.
   (if dipzero!? rp then
                            (if !*groebrm then dipevlmon p else nil)
      else
    dipcontentr1(if !*groebrm then dipevlmon p else nil,rp) )
                          where rp=dipmred p;
 
 
symbolic procedure dipcontentr1 (ev,p1);
   if dipzero!? p1 then ev
      else begin
             if ev then ev := dipcontevmin(dipevlmon p1,ev);
             if null ev then return nil
                       else return dipcontentr1 (ev,dipmred p1)
       end;
 
%  divide all coefficients of p by cont
symbolic procedure dipreducecontr (p,co,ev);
    if dipzero!? p
         then makedipzero()
         else
           dipmoncomp ( bcprod (diplbc p,co),
                        if ev then evdif(dipevlmon p,ev)
                              else dipevlmon p,
                        dipreducecontr (dipmred p,co,ev));
 
 
symbolic procedure dipcontevmin (e1,e2);
% calculates the minimum of two exponents; if one is shorter, trailing
% zeroes are assumed.
% e1 is an exponent vector. e2 is a list of exponents
    begin scalar res;
       while e1 and e2 do
          <<res := (if ilessp(car e1,car e2) then car e1 else car e2)
                    . res;
            e1 := cdr e1; e2 := cdr e2>>;
       while res and 0=car res do res := cdr res; 
       return reversip res;
    end;
 
 
symbolic procedure dipcontlowerev (e1);
% subtract a 1 from those elements of an exponent vector which 
% are greater  than 1.
% e1 is a list of exponents, the result is an exponent vector.
    begin scalar res;
       while e1 do
          <<res := (if igreaterp(car e1,0) then car e1 - 1 else 0) 
                    . res;
            e1 := cdr e1>>;
       while res and 0 = car res do res := cdr res;
            if res and !*trgroebs then
                   <<prin2 "***** exponent reduction:"; 
                     prin2t reverse res>>;
       return  reversip res;
    end;
 
symbolic procedure dipappendmon(dip,bc,ev);
         append(dip,dipfmon(bc,ev));
 
smacro procedure dipnconcmon(dip,bc,ev);
         nconc(dip,dipfmon(bc,ev));
 
smacro procedure dipappenddip(dip1,dip2); append(dip1,dip2);
 
smacro procedure dipnconcdip(dip1,dip2); nconc(dip1,dip2);
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  basic polynomial arithmetic:
%
 
symbolic procedure vdpsum(d1,d2);
              dip2vdp dipsum(vdppoly d1,vdppoly d2);
 
symbolic procedure vdpdif(d1,d2);
              dip2vdp dipdif(vdppoly d1,vdppoly d2);
 
symbolic procedure vdpprod(d1,d2);
              dip2vdp dipprod(vdppoly d1,vdppoly d2);
 
 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  linear combination: the Buchberger Workhorse
%
% LCOMB1: calculate mon1 * vdp1 + mon2 * vdp2
symbolic procedure vdpilcomb1(d1,vbc1,vev1,d2,vbc2,vev2);
 dip2vdp dipilcomb1 (vdppoly d1,vbc1,vev1,vdppoly d2,vbc2,vev2);
 
symbolic procedure dipilcomb1 (p1,bc1,ev1,p2,bc2,ev2);
% same asl dipILcomb, exponent vectors multiplied in already
   begin scalar ep1,ep2,sl,res,sum,z1,z2,p1new,p2new,lptr,bptr;
       z1 := not evzero!? ev1; z2 := not evzero!? ev2;
       p1new := p2new := t;
       lptr := bptr := res := makedipzero();
 loop:
       if p1new then
       << if dipzero!? p1 then
              return if dipzero!? p2 then res else
                     dipnconcdip(res, dipprod(p2,dipfmon(bc2,ev2)));
          ep1 := dipevlmon p1;
          if z1 then ep1 := evsum(ep1,ev1);
          p1new := nil;>>;
       if p2new then
       << if dipzero!? p2 then
              return dipnconcdip(res, dipprod(p1,dipfmon(bc1,ev1)));
          ep2 := dipevlmon p2;
          if z2 then ep2 := evsum(ep2,ev2);
          p2new := nil; >>;
        sl := evcomp(ep1, ep2);
        if sl = 1 then
                      << lptr := dipnconcmon (bptr,
                                              bcprod(diplbc p1,bc1),
                                              ep1);
                         bptr := dipmred lptr;
                         p1 := dipmred p1; p1new := t;
                      >>
        else if sl = -1 then
                      << lptr := dipnconcmon (bptr,
                                              bcprod(diplbc p2,bc2),
                                              ep2);
                         bptr := dipmred lptr;
                         p2 := dipmred p2; p2new := t;
                      >>
        else
                      << sum := bcsum (bcprod(diplbc p1,bc1),
                                       bcprod(diplbc p2,bc2));
                         if not bczero!? sum then
                             <<   lptr := dipnconcmon(bptr,sum,ep1);
                                  bptr := dipmred lptr>>;
                         p1 := dipmred p1; p2 := dipmred p2;
                         p1new := p2new := t;
                      >>;
        if dipzero!? res then <<res := bptr := lptr>>; % initial
        goto loop;
 end;
 

 
symbolic procedure vdpvbcprod(p,a); dip2vdp dipbcprod(vdppoly p,a);
 
 
symbolic procedure vdpdivmon(p,c,vev);
   dip2vdp dipdivmon(vdppoly p,c,vev);
 
 
symbolic procedure dipdivmon(p,bc,ev);
    % divides a polynomial by a monomial
    % we are sure that the monomial ev is a factor of p
    if dipzero!? p
         then makedipzero()
         else
           dipmoncomp ( bcquot(diplbc p,bc),
                        evdif(dipevlmon p,ev),
                        dipdivmon (dipmred p,bc,ev));
 
 
symbolic procedure vdpcancelmvev(f,vev);
     dip2vdp dipcancelmev(vdppoly f,vev);
 
symbolic procedure dipcancelmev(f,ev);
    % cancels all monomials in f which are multiples of ev
      dipcancelmev1(f,ev,makedipzero());
 
symbolic procedure dipcancelmev1(f,ev,res);
    if dipzero!? f then res
    else if evmtest!?(dipevlmon f,ev) then
                       dipcancelmev1(dipmred f,ev,res)
     else dipcancelmev1(dipmred f,ev,
       %                 dipAppendMon(res,diplbc f,dipevlmon f));
                         dipnconcmon(res,diplbc f,dipevlmon f));
 
 
% some prehistoric routines needed in resultant operation
symbolic procedure vevsum0(n,p);
% exponent vector sum version 0. n is the length of vdpvars!*.
% p is a distributive polynomial.
  if vdpzero!? p then vevzero1 n else
  vevsum(vdpevlmon p, vevsum0(n,vdpred p));
 
symbolic procedure vevzero1 n;
% Returns the exponent vector power representation
% of length n for a zero power.
  begin scalar x;
   for i:=1: n do << x := 0 . x >>;
  return x
  end;
 
symbolic procedure vdpresimp u;
   % fi domain changes, the coefficients have to be resimped
   dip2vdp dipresimp vdppoly u;
 
symbolic procedure dipresimp u;
   if null u then nil else
   (for each x in u collect
      <<toggle := not toggle;
      if toggle then simp prepsq x else x>>
      ) where toggle = t;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% printing of polynomials
%
 
symbolic procedure vdpprin2t u; << vdpprint1(u,nil,9999); terpri()>>;

symbolic procedure vdpprin3t u;
      << vdpprint1(u,nil,9999); prin2t ";">>;
 
symbolic procedure vdpprint u;
      <<vdpprin2 u; terpri()>>;

symbolic procedure vdpprin2 u;
   <<(if x then <<prin2 "P("; prin2 x; prin2 "):  ">>) 
                 where x=vdpgetprop(u,'number);
      vdpprint1(u,nil,vdpprintmax)>>;
 
symbolic procedure vdpprint1(u,v,max); vdpprint1x(vdppoly u,v,max);
 
symbolic procedure vdpprint1x(u,v,max);
%   /* Prints a distributive polynomial in infix form.
%     U is a distributive form. V is a flag which is true if a term
%     has preceded current form
%     max limits the number of terms to be printed
   if dipzero!? u then if null v then dipprin2 0 else nil
    else if max = 0 then   % maximum of terms reached
              << terpri();
                 prin2 " ### etc (";
                 prin2 diplength u;
                 prin2 " terms) ###";
                 terpri();>>
    else begin scalar bool,w;
       w := diplbc u;
       if bcminus!? w then <<bool := t; w := bcneg w>>;
       if bool then dipprin2 " - " else if v then dipprin2 " + ";
       (if not bcone!? w or evzero!? x then<<bcprin w; dipevlpri(x,t)>>
         else dipevlpri(x,nil))
           where x = dipevlmon u;
       vdpprint1x(dipmred u,t, max - 1)
     end;
 
symbolic procedure dipprin2 u;
   <<if posn()>69 then terprit 2 ;  prin2 u>>;
    
symbolic procedure vdpsave u; u;
 
 
%   switching between term order modes
 
symbolic procedure torder2 u; dipsortingmode u;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% additional conversion utilities 
 

% conversion dip to standard form / standard quotient

symbolic procedure dip2f u;
      (if denr v neq 1 then
        <<print u;
          rerror(dipoly,9,
                 "Distrib. poly. with rat coeff cannot be converted")>>
       else numr v) where v = dip2sq u;

symbolic procedure dip2sq u;
   % convert a dip into a standard quotient.
     if dipzero!? u then nil ./ 1
     else addsq(diplmon2sq(diplbc u,dipevlmon u),dip2sq dipmred u); 
 
symbolic procedure diplmon2sq(bc,ev);
   %convert a monomial into a standard quotient.
     multsq(bc,dipev2f(ev,dipvars!*) ./ 1);
 
symbolic procedure dipev2f(ev,vars);
     if null ev then 1
     else if car ev = 0 then dipev2f(cdr ev,cdr vars)
     else multf(car vars .** car ev .* 1 .+ nil,
                dipev2f(cdr ev,cdr vars));
     
% evaluate SUBS2 for the coefficients of a dip
 
symbolic procedure dipsubs2 u;
   begin scalar v,secondvalue!*;
      secondvalue!* := 1 ./ 1;
      v := dipsubs21 u;
      return diprectoint(v,secondvalue!*);
   end;
      
symbolic procedure dipsubs21 u;
   begin scalar c;
      if dipzero!? u then return u;
      c := groebsubs2 diplbc u;
      if null numr c then return dipsubs21 dipmred u;
      if not(denr c = 1) then
          secondvalue!* := bclcmd(c,secondvalue!*);
      return dipmoncomp(c,dipevlmon u,dipsubs21 dipmred u);
   end;

% conversion standard form to dip
 
symbolic procedure f2dip u; f2dip1(u,evzero(),1 ./ 1);
 
symbolic procedure f2dip1 (u,ev,bc);
  % f to dip conversion: scan the standard form. ev
  % and bc are the exponent and coefficient parts collected
  % so far from higher parts.
   if null u then nil 
   else if domainp u then dipfmon(multsq(bc,u ./ 1),ev)
   else dipsum(f2dip2(mvar u,ldeg u,lc u,ev,bc),
               f2dip1(red u,ev,bc));
 
symbolic procedure f2dip2(var,dg,c,ev,bc);
  % f to dip conversion:
  % multiply leading power either into exponent vector
  % or into the base coefficient.
   <<if ev1 then ev := ev1
     else bc := multsq(bc,var.**dg.*1 .+nil./1);
     f2dip1(c,ev,bc)>>
           where ev1=if memq(var,dipvars!*) then
                evinsert(ev,var,dg,dipvars!*) else nil;
 
symbolic procedure evinsert(ev,v,dg,vars);
   % f to dip conversion:
   % Insert the "dg" into the ev in the place of variable v.
     if null ev or null vars then nil
     else if car vars eq v then dg . cdr ev
     else car ev . evinsert(cdr ev,v,dg,cdr vars);

endmodule;


module vdpcom;
 
% common routines to all vdp mappings
 

fluid '(intvdpvars!* vdpvars!* secondvalue!* vdpsortmode!* !*groebrm
        !*vdpinteger !*trgroeb !*groebdivide pcount!* 
         vdpsortextension!* );


global '(vdpprintmax);
flag('(vdpprintmax),'share);
vdpprintmax := 5;
 
% Repeat of smacros defined in vdp2dip.

smacro procedure vdppoly u; cadr cddr u;

smacro procedure vdpzero!? u;
    null u or null vdppoly u;

smacro procedure vdpevlmon u; cadr u;

 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  manipulating of exponent vectors
%
 
symbolic procedure vevnth (a,n);
 % extract nth element from a
   if null a then 0 else if n=1 then car a else vevnth(cdr a,n #- 1);
 
% unrolled code for zero test (very often called)
smacro procedure vevzero!? u;
        null u or (car u = 0 and vevzero!?1 cdr u);
 
symbolic procedure vevzero!?1 u;
        null u or (car u = 0 and vevzero!? cdr u);
 
symbolic procedure veveq(vev1,vev2);
  if null vev1 then vevzero!? vev2
  else if null vev2 then vevzero!? vev1
  else (car vev1 = car vev2 and vevequal(cdr vev1,vev2));
   
symbolic procedure vevmaptozero e;
 %  generate an exponent vector with same length as e and zeros only
        vevmaptozero1(e,nil);
 
symbolic procedure vevmaptozero1(e,vev);
     if null e then vev else vevmaptozero1(cdr e, 0 . vev);
 
symbolic procedure vevmtest!? (e1,e2);
%  /* Exponent vector multiple test. e1 and e2 are compatible exponent
%    vectors. vevmtest?(e1,e2) returns a boolean expression.
%    True if exponent vector e1 is a multiple of exponent
%    vector e2, else false. */
    if null e2 then t
    else if null e1 then if vevzero!? e2 then t else nil
    else not(car e1 #<car e2)and vevmtest!?(cdr e1,cdr e2);
 
 
symbolic procedure vevlcm (e1,e2);
%  /* Exponent vector least common multiple. e1 and e2 are
%    exponent vectors. vevlcm(e1,e2) computes the least common
%    multiple of the exponent vectors e1 and e2, and returns
%    an exponent vector. */
   begin scalar x;
      while e1 and e2 do
         <<x := (if car e1 #> car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      x := reversip x;
      if e1 then x := nconc(x,e1)
      else if e2 then x := nconc(x,e2);
      return x;
   end;
 
symbolic procedure vevmin (e1,e2);
%   Exponent vector minima
   begin scalar x;
      while e1 and e2 do
         <<x := (if car e1 #< car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      while x and 0=car x do x := cdr x;  % cut trailing zeros
      return reversip x;
   end;
 
symbolic procedure vevsum (e1,e2);
%  /* Exponent vector sum. e1 and e2 are exponent vectors.
%    vevsum(e1,e2) calculates the sum of the exponent vectors.
%    e1 and e2 componentwise and returns an exponent vector. */
   begin scalar x;
      while e1 and e2 do
         <<x := (car e1 #+ car e2) . x;e1 := cdr e1; e2 := cdr e2>>;
      x := reversip x;
      if e1 then x := nconc(x,e1)
      else if e2 then x := nconc(x,e2);
      return x;
   end;
 
 
symbolic procedure vevtdeg u;
% calculate the total degree of u
   if null u then 0 else car u #+ vevtdeg cdr u;
 
 
symbolic procedure vevdif (ee1,ee2);
%    Exponent vector difference. e1 and e2 are exponent
%    vectors. vevdif(e1,e2) calculates the difference of the
%    exponent vectors e1 and e2 componentwise and returns an
%    exponent vector.
   begin scalar x,y,break,e1,e2;
      e1 := ee1; e2 := ee2;
      while e1 and e2 and not break do
         <<y := (car e1 #- car e2); x := y . x;
           break := y #< 0;
           e1 := cdr e1; e2 := cdr e2>>;
      if break or (e2 and not vevzero!? e2) then
        <<print ee1; print ee2; 
          if getd 'backtrace then backtrace();
         return rerror(dipoly,5,"Vevdif, difference would be < 0")>>;
      return nconc(reversip x,e1);
   end;
 
 
symbolic procedure vevdivides!?(e1,e2);
   % test if e2 is a multiple of e1
    null e1
    or (null e2 and vevzero!? e1)
    or (car e1 leq car e2 and vevdivides!?(cdr e1,cdr e2));
                                        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% numbering of polynomials
%
 
  symbolic procedure vdpenumerate f;
  % f is a temporary result. Prepare it for medium range storage
  % and ssign a number
  if vdpzero!? f then f else
  << f := vdpsave f;
     if not vdpgetprop(f,'number) then
        f := vdpputprop(f,'number,(pcount!* := pcount!* #+ 1));
     f>>;

%smacro procedure vdpNumber f;
%     vdpGetProp(f,'NUMBER) ;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  operations on sets of polynomials
%
 
symbolic procedure vdpmember(p1,l);
% test membership of a polynomial in a list of polys
      if null l then nil
         else
      if vdpequal(p1,car l) then l
         else
               vdpmember(p1,cdr l);
 
 
symbolic procedure vdpunion (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % union of the sets using vdpMember as crit
   if null s1 then s2
      else
   if vdpmember(car s1,s2) then vdpunion(cdr s1,s2)
      else car s1 . vdpunion(cdr s1,s2);
  
symbolic procedure vdpintersection (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % intersection of the sets using vdpMember as crit
   if null s1 then nil
      else
   if vdpmember(car s1,s2) then car s1 . vdpunion(cdr s1,s2)
      else vdpunion(cdr s1,s2);
 
symbolic procedure vdpsetequal!?(s1,s2);
 % tests if s1 and s2 have the same polynomials as members
     if not (length s1 = length s2) then nil
         else vdpsetequal!?1(s1,append(s2,nil));
 
symbolic procedure vdpsetequal!?1(s1,s2);
  % destroys its second parameter (is therefor copied when called)
     if null s1 and null s2 then t
         else
     if null s1 or null s2 then nil
         else
     (if hugo then vdpsetequal!?1(cdr s1,groedeletip(car hugo,s2))
        else nil) where hugo = vdpmember(car s1,s2);
 
 

symbolic procedure vdpsortedsetequal!?(s1,s2);
 % tests if s1 and s2 have the same polynomials as members
 % here assuming, that both sets are sorted by the same
 % principles
     if null s1 and null s2 then t
         else
     if null s1 or null s2 then nil
         else
     if vdpequal(car s1,car s2) then
       vdpsortedsetequal!?(cdr s1,cdr s2)
          else nil;


symbolic procedure vdpdisjoint!? (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % test that there are no common members
   if null s1 then t
      else
   if vdpmember(car s1,s2) then nil
      else vdpdisjoint!?(cdr s1,s2);

symbolic procedure vdpsubset!? (s1,s2);
    not length s1 > length s2 and  vdpsubset!?1(s1,s2);


symbolic procedure vdpsubset!?1 (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % test if s1 is subset of s2
    if null s1 then t
      else
   if vdpmember(car s1,s2) then vdpsubset!?1 (cdr s1,s2)
      else nil;

symbolic procedure vdpdeletemember(p,l);
   % delete polynomial p from list l
    if null l then nil
        else
    if vdpequal(p,car l) then vdpdeletemember(p,cdr l)
        else car l . vdpdeletemember(p,cdr l);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  sorting of polynomials
%
 
symbolic procedure   vdplsort pl;
%  /* Distributive polynomial list sort. pl is a list of
%    distributive polynomials. vdplsort(pl) returns the
%    sorted distributive polynomial list of pl.
   sort(pl, function vdpvevlcomp);
 
symbolic procedure  vdplsortin (po,pl);
%    po is a polynomial, pl is a list of polynomials.
%    po is inserted into pl at its place determined by vevlcompless?.
%    the result is the updated pl;
   if null pl then list po
   else if vevcompless!? (vdpevlmon po, vdpevlmon car pl)
       then  car pl . vdplsortin (po, cdr pl)
     else po . pl;
 
symbolic procedure  vdplsortinreplacing (po,pl);
%    po is a polynomial, pl is a list of polynomials.
%    po is inserted into pl at its place determined by vevlcompless?.
%    if there is a multiple of the exponent of pl, this is deleted
%    the result is the updated pl;
   if null pl then list po
   else if vevdivides!? (vdpevlmon po, vdpevlmon car pl) 
       then vdplsortinreplacing (po, cdr pl)
   else if vevcompless!? (vdpevlmon po, vdpevlmon car pl)
       then  car pl . vdplsortinreplacing (po, cdr pl)
     else po . pl;





%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% property lists for polynomials
%

symbolic procedure vdpputprop (poly,prop,val);
   begin scalar c,p;
      if not pairp poly or not pairp (c := cdr poly)
                        or not pairp (c := cdr c)
                        or not pairp (c := cdr c)
                        or not pairp (c := cdr c  ) 
            then rerror(dipoly,6,
                  list("vdpPutProp given a non-vdp as 1st parameter",
                        poly,prop,val));
      p := assoc(prop,car c);
      if p then rplacd(p,val)
           else rplaca(c,(prop . val) . car c);
      return poly;
   end;

symbolic procedure vdpgetprop (poly,prop);
     if null poly then nil  % nil is a legal variant of vdp=0
       else
     if not eqcar(poly,'vdp)
            then rerror(dipoly,7,
                  list("vdpGetProp given a non-vdp as 1st parameter",
                        poly,prop))
       else
      (if p then cdr p else nil)
          where p=assoc(prop,cadr cdddr poly);
 
symbolic procedure vdpremallprops u; 
     begin scalar c;
      if not pairp u or not pairp (c := cdr u)
                     or not pairp (c := cdr c)
                     or not pairp (c := cdr c)
                     or not pairp (c := cdr c)
            then return u;
      rplaca(c,nil); return u;
     end;
         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Groebner interface to power substitution
 
fluid '(!*sub2);

symbolic procedure groebsubs2 q;
     (subs2 q) where !*sub2=t;

% and a special print
symbolic procedure vdpprintshort u;
    begin scalar m;
       m := vdpprintmax;
       vdpprintmax:= 2;
       vdpprint u;
       vdpprintmax:=m;
    end;

endmodule;


end;
