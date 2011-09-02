module consel;

%/*Constructors and selectors for a distributed polynomial form*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

%/*A distributive polynomial has the following informal syntax:
%
%   <dipoly> ::= dipzero
%                | <exponent vector> . <base coefficient> . <dipoly>*/

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

endmodule;


module bcoeff;  % Computation of base coefficients.


%/*Definitions of base coefficient operations for distributive
% polynomial package.  We assume that only field elements are used, but
% no check is made for this.  In this module, a standard quotient
% coefficient is assumed*/


%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

global '(!*nat);

expr procedure bcless!? (a1,a2);
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


expr procedure bccomp (a1,a2);
%  /* Base coefficient compare a1 and a2 are base coefficients.
%    bccomp(a1,a2) compares the base coefficients a1 and a2 and returns
%    a digit 1 if a1 greater than a2, a digit 0 if a1 equals a2 else a
%    digit -1. */
     (if bczero!? sl then 0
       else if bcminus!? sl then -1
       else 1)
       where sl = bcdif(a1, a2);


expr procedure bcfi a;
%  /* Base coefficient from integer. a is an integer. bcfi(a) returns
%    the base coefficient a. */
     mkbc(a,1);


expr procedure bclcmd(u,v);
% Base coefficient least common multiple of denominators.
% u and v are two base coefficients. bclcmd(u,v) calculates the
% least common multiple of the denominator of u and the
% denominator of v and returns a base coefficient of the form
% 1/lcm(denom u,denom v).
  if bczero!? u then mkbc(1,denr v)
   else if bczero!? v then mkbc(1,denr u)
   else mkbc(1,multf(quotf(denr u,gcdf(denr u,denr v)),denr v));


expr procedure bclcmdprod(u,v);
% Base coefficient least common multiple denominator product.
% u is a basecoefficient of the form 1/integer. v is a base
% coefficient. bclcmdprod(u,v) calculates (denom u/denom v)*nom v/1
% and returns a base coefficient.
  mkbc(multf(quotf(denr u,denr v),numr v),1);


expr procedure bcquod(u,v);
% Base coefficient quotient. u and v are base coefficients.
% bcquod(u,v) calculates u/v and returns a base coefficient.
  bcprod(u,bcinv v);


expr procedure bcone!? u;
%  /* Base coefficient one. u is a base coefficient.
%    bcone!?(u) returns a boolean expression, true if the
%    base coefficient u is equal 1. */
   denr u = 1 and numr u = 1;


expr procedure bcinv u;
%  /* Base coefficient inverse. u is a base coefficient.
%    bcinv(u) calculates 1/u and returns a base coefficient. */
    invsq u;


expr procedure bcneg u;
%  /* Base coefficient negative. u is a base coefficient.
%    bcneg(u) returns the negative of the base coefficient
%    u, a base coefficient. */
   negsq u;


expr procedure bcprod (u,v);
%  /* Base coefficient product. u and v are base coefficients.
%    bcprod(u,v) calculates u*v and returns a base coefficient.
   multsq(u,v);

expr procedure mkbc(u,v);
%   /* Convert u and v into u/v in lowest terms*/
   if v = 1 then u ./ v
    else if v<0 then mkbc(negf u,negf  v)
    else quotf(u,m) ./ quotf(v,m) where m = gcdf(u,v);


expr procedure bcquot (u,v);
%  /* Base coefficient quotient. u and v are base coefficients.
%    bcquot(u,v) calculates u/v and returns a base coefficient. */
   quotsq(u,v);


expr procedure bcsum (u,v);
%  /* Base coefficient sum. u and v are base coefficients.
%    bcsum(u,v) calculates u+v and returns a base coefficient. */
   addsq(u,v);


expr procedure bcdif(u,v);
%  /* Base coefficient difference. u and v are base coefficients.
%    bcdif(u,v) calculates u-v and returns a base coefficient. */
   bcsum(u,bcneg v);


expr procedure bcpow(u,n);
%   /*Returns the base coefficient u raised to the nth power, where
%    n is an integer*/
   exptsq(u,n);


expr procedure a2bc u;
%   /*Converts the algebraic (kernel) u into a base coefficient.
    simp!* u;


expr procedure bc2a u;
%   /* Returns the prefix equivalent of the base coefficient u*/
   prepsq u;


expr procedure bcprin u;
%   /* Prints a base coefficient in infix form*/
   begin scalar nat;
      nat := !*nat;
      !*nat := nil;
      sqprint u;
      !*nat := nat
    end;

endmodule;


module expvec;

% /*Specific support for distributive polynomial exponent vectors*/

% /* Authors: R. Gebauer, A. C. Hearn, H. Kredel */

%   We assume here that an exponent vector is a list of integers.  This
%   version uses small integer arithmetic on the individual exponents
%   and assumes that a compiled function can be dynamically redefined*/


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
     if n = 1 then evfirst e1
        else evnth(evred e1, n - 1);


expr procedure evred e1;
%  /* Exponent vector reductum. e1 is an exponent vector. evred(e1)
%    returns the reductum of the exponent vector e1. */
     cdr e1;


expr procedure evfirst e1;
%  /* Exponent vector first. e1 is an exponent vector. evfirst(e1)
%   returns the first element of the exponent vector e1, an exponent. */
     car e1;


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
% returns a list of indixes of non zero exponents.
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


expr procedure evcompless!?(e1,e2);
%  /* Exponent vector compare less. e1, e2 are exponent vectors
%    in some order. Evcompless? is a boolean function which returns
%    true if e1 is ordered less than e2. This function is assigned a
%    value by the ordering mechanism, so is dummy for now*/
   apply(get(dipsortmode!*,'evcompless!?),list(e1,e2));


expr procedure evlexcompless!?(e1,e2);
%  /* Exponent vector lexicographical compare less. e1, e2 are exponent
%    vectors in lexicographical order. Evlexcompless?(e1,e2) is a
%    boolean function which returns true if e1 is ordered less than e2*/
   if null e1 then nil
    else if car e1 = car e2 then evlexcompless!?(cdr e1,cdr e2)
    else car e1 #> car e2;


expr procedure evcomp (e1,e2);
%  /* Exponent vector compare. e1, e2 are exponent vectors in some
%    order.  Evcomp(e1,e2) returns the digit 0 if exponent vector e1 is
%    equal exponent vector e2, the digit 1 if e1 is greater than e2,
%    else the digit -1. This function is assigned a value by the
%    ordering mechanism, so is dummy for now*/
   apply(get(dipsortmode!*,'evcomp),list(e1,e2));


expr procedure evilcompless!?(e1,e2);
% /* Exponent vector inverse lexicographical compare less. e1, e2 are
%  exponent vectors in lexicographical order.  Evilcompless?(e1,e2) is
%  a boolean function which returns true if e1 is ordered less than e2*/
   if null e1 then nil
    else if car e1 = car e2 then evilcompless!?(cdr e1,cdr e2)
    else car e1 #< car e2;


expr procedure evlexcomp(e1,e2);
%  /* Exponent vector lexicographical compare. e1, e2 are exponent
%    vectors in lexicographical order.  Evlexcomp(e1,e2) returns the
%    digit 0 if exponent vector e1 is equal exponent vector e2, 1 if e1
%    is greater than e2, else the digit -1. */
   if null e1 then 0
    else if car e1 = car e2 then evlexcomp(cdr e1,cdr e2)
    else if car e1 #< car e2 then 1
    else -1;


expr procedure evilcomp (e1,e2);
%  /* Exponent vector inverse lexicographical compare. The
%    exponent vectors e1 and e2 are in inverse lexicographical
%    ordering. evilcomp(e1,e2) returns the digit 0 if exponent
%    vector e1 is equal exponent vector e2, the digit 1 if e1 is
%    greater than e2, else the digit -1. */
   if null e1 then 0
    else if car e1 = car e2 then evilcomp(cdr e1,cdr e2)
    else if car e1 #> car e2 then 1
    else -1;


expr procedure evitdcompless!?(e1,e2);
%  /* Exponent vector inverse total degree compare less.
%    The exponent vectors e1 and e2 are in inverse total degree
%    ordering. evitdcompless!?(e1,e2) is a boolean function that
%    returns true if exponent vector e1 is ordered less than e2*/
   if null e1 then nil
    else if car e1 = car e2 then evitdcompless!?(cdr e1, cdr e2)
    else (if te1 = te2 then car e1 #< car e2 else te1 #< te2)
          where te1 = evtdeg e1, te2 = evtdeg e2;


expr procedure evtdcompless!?(e1,e2);
%  /*Exponent vector total degree compare less.*/
   if null e1 then nil
     else if car e1 = car e2 then evtdcompless!?(cdr e1,cdr e2)
     else (if te1 = te2 then car e1 #> car e2 else te1 #< te2)
           where te1 = evtdeg e1, te2 = evtdeg e2;


expr procedure evitdcomp (e1,e2);
%  /* Exponent vector inverse total degree compare.
%    The exponent vectors e1 and e2 are in inverse total degree
%    ordering. evitdcomp(e1,e2) returns the digit 0 if exponent
%    vector e1 is equal exponent vector e2, the digit 1 if e1 is
%    greater than e2, else the digit -1. */
   if null e1 then 0
    else if car e1 = car e2 then evitdcomp(cdr e1, cdr e2)
    else (if te1 = te2 then if car e1 #> car e2 then 1 else -1
           else if te1 #> te2 then 1 else -1)
          where te1 = evtdeg e1, te2 = evtdeg e2;


expr procedure evtdcomp (e1,e2);
% /* ... */
   if null e1 then 0
    else if car e1 = car e2 then evtdcomp(cdr e1,cdr e2)
    else (if te1 = te2 then if car e1 #< car e2 then 1 else -1
           else if te1 #> te2 then 1 else -1)
          where te1 = evtdeg e1, te2 = evtdeg e2;


expr procedure evtdeg e1;
%  /* Exponent vector total degree. e1 is an exponent vector.
%    evtdeg(e1) calculates the total degree of the exponent
%    e1 and returns an integer. */
   (<<while e1 do <<x := car e1 #+ x; e1 := cdr e1>>; x>>) where x = 0;


expr procedure evlcm (e1,e2);
%  /* Exponent vector least common multiple. e1 and e2 are
%    exponent vectors. evlcm(e1,e2) computes the least common
%    multiple of the exponent vectors e1 and e2, and returns
%    an exponent vector. */
   % for each lpart in e1 each rpart in e2 collect
   %     if lpart #> rpart then lpart else rpart;
   begin scalar x;
      while e1 do
         <<x := (if car e1 #> car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      return reversip x
   end;


expr procedure evmtest!? (e1,e2);
%  /* Exponent vector multiple test. e1 and e2 are compatible exponent
%    vectors. evmtest!?(e1,e2) returns a boolean expression.
%    True if exponent vector e1 is a multiple of exponent
%    vector e2, else false. */
   null e1 or not(car e1 #< car e2) and evmtest!?(cdr e1,cdr e2);


expr procedure evsum (e1,e2);
%  /* Exponent vector sum. e1 and e2 are exponent vectors.
%    evsum(e1,e2) calculates the sum of the exponent vectors.
%    e1 and e2 componentwise and returns an exponent vector. */
   % for each lpart in e1 each rpart in e2 collect lpart #+ rpart;
     begin scalar x;
      while e1 do
         <<x := (car e1 #+ car e2) . x; e1 := cdr e1; e2 := cdr e2>>;
      return reversip x
   end;


expr procedure evdif (e1,e2);
%  /* Exponent vector difference. e1 and e2 are exponent
%    vectors. evdif(e1,e2) calculates the difference of the
%    exponent vectors e1 and e2 componentwise and returns an
%    exponent vector. */
   % for each lpart in e1 each rpart in e2 collect lpart #- rpart;
   begin scalar x;
      while e1 do
         <<x := (car e1 #- car e2) . x; e1 := cdr e1; e2 := cdr e2>>;
      return reversip x
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


remprop('torder,'stat);

expr procedure torder u;
   % algebraic mode interface to dipsortingmode.
   dipsortingmode car u;

put('torder,'stat,'rlis);

expr procedure dipsortingmode u;
%  /* Sets the exponent vector sorting mode. Returns the previous mode*/
   if not idp u or not flagp(u,'dipsortmode)
     then typerr(u,"term ordering mode")
    else begin scalar x;
            x := dipsortmode!*; dipsortmode!* := u; return x
         end;


flag('(lex invlex totaldegree invtotaldegree),'dipsortmode);

put('lex,'evcompless!?,'evlexcompless!?);

put('lex,'evcomp,'evlexcomp);

put('invlex,'evcompless!?,'evilcompless!?);

put('invlex,'evcomp,'evilcomp);

put('invtotaldegree,'evcompless!?,'evitdcompless!?);

put('invtotaldegree,'evcomp,'evitdcomp);

put('totaldegree,'evcompless!?,'evtdcompless!?);

put('totaldegree,'evcomp,'evtdcomp);

dipsortingmode 'invlex;   % /*Default value*/


endmodule;


module dipoly;  % /*Distributive polnomial algorithms*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

fluid '(dipvars!* dipzero);

fexpr procedure polyin p; a2dip car p;

expr procedure dipconst!? p;
 not dipzero!? p
 and dipzero!? dipmred p
 and evzero!? dipevlmon p;


expr procedure   dfcprint pl;
% h polynomial factor list of distributive polynomials print.
for each p in pl do dfcprintin p;

expr procedure   dfcprintin p;
% factor with exponent print.
( if cdr p neq 1 then << prin2 " ( "; dipprint1(p1,nil); prin2 " )** ";
  prin2 cdr p; terprit 2  >> else << prin2 "  "; dipprint p1>> )
      where p1:= dipmonic a2dip prepf car p;

expr procedure   dfcprin p;
% print content, factors and exponents of factorized polynomial p.
   << terpri(); prin2 " content of factorized polynomials  =  ";
   prin2 car p;
   terprit 2; dfcprint cdr p >>;


expr procedure diplcm p;
% Distributive polynomial least common multiple of denomiators.
% p is a distributive rational polynomial. diplcm(p) calculates
% the least common multiple of the denominators and returns a
% base coefficient of the form  1/lcm(denom bc1,.....,denom bci).
  if dipzero!? p then mkbc(1,1)
     else bclcmd(diplbc p, diplcm dipmred p);

expr procedure diprectoint(p,u);
% Distributive polynomial conversion rational to integral.
% p is a distributive rational polynomial, u is a base coefficient
% ( 1/lcm denom p ). diprectoint(p,u) returns a primitive
% associate pseudo integral ( denominators are 1 ) distributive
% polynomial.
  if bczero!? u then dipzero
     else if bcone!? u then p
          else diprectoint1(p,u);

expr procedure diprectoint1(p,u);
% Distributive polynomial conversion rational to integral internall 1.
% diprectoint1 is used in diprectoint.
  if dipzero!? p then dipzero
     else dipmoncomp(bclcmdprod(u,diplbc p),dipevlmon p,
                     diprectoint1(dipmred p,u));


expr procedure dipresul(p1,p2);
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

expr procedure   dipbcprod (p,a);
%   /* Distributive polynomial base coefficient product.
%     p is a distributive polynomial, a is a base coefficient.
%     dipbcprod(p,a) computes p*a, a distributive polynomial. */

     if bczero!? a then dipzero
                  else if bcone!? a then p
                                   else dipbcprodin(p,a);

expr procedure   dipbcprodin (p,a);
%   /* Distributive polynomial base coefficient product internal.
%     p is a distributive polynomial, a is a base coefficient,
%     where a is not equal 0 and not equal 1.
%     dipbcprodin(p,a) computes p*a, a distributive polynomial. */

     if dipzero!? p then dipzero
                   else dipmoncomp(bcprod(a, diplbc p),
                                   dipevlmon p,
                                   dipbcprodin(dipmred p, a));


expr procedure dipdif (p1,p2);
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

expr procedure   diplength p;
%   /* Distributive polynomial length. p is a distributive
%     polynomial. diplength(p) returns the number of terms
%     of the distributive polynomial p, a digit.*/

     if dipzero!? p then 0 else 1 + diplength dipmred p;



expr procedure   diplistsum pl;
%   /* Distributive polynomial list sum. pl is a list of distributive
%     polynomials. diplistsum(pl) calculates the sum of all polynomials
%     and returns a list of one distributive polynomial. */

     if null pl or null cdr pl then pl
        else diplistsum(dipsum(car pl, cadr pl) . diplistsum cddr pl);



expr procedure   diplmerge (pl1,pl2);
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

expr procedure   diplsort pl;
%  /* Distributive polynomial list sort. pl is a list of
%    distributive polynomials. diplsort(pl) returns the
%    sorted distributive polynomial list of pl.
   sort(pl, function dipevlcomp);

expr procedure   dipevlcomp (p1,p2);
%  /*  Distributive polynomial exponent vector leading monomial
%     compare. p1 and p2 are distributive polynomials.
%     dipevlcomp(p1,p2) returns a boolean expression true if the
%     distributive polynomial p1 is smaller or equal the distributive
%     polynomial p2 else false. */

   not evcompless!?(dipevlmon p1, dipevlmon p2);



expr procedure   dipmonic p;
%   /* Distributive polynomial monic. p is a distributive
%     polynomial. dipmonic(p) computes p/lbc(p) if p is
%     not equal dipzero and returns a distributive
%     polynomial, else dipmonic(p) returns dipzero. */

     if dipzero!? p then p
                   else dipbcprod(p, bcinv diplbc p);



expr procedure   dipneg p;
%  /* Distributive polynomial negative. p is a distributive
%    polynomial. dipneg(p) returns the negative of the distributive
%    polynomial p, a distributive polynomial. */

    if dipzero!? p then p
       else dipmoncomp ( bcneg diplbc p,
                         dipevlmon p,
                         dipneg dipmred p );



expr procedure   dipone!? p;
%  /* Distributive polynomial one.  p is a distributive polynomial.
%    dipone!?(p) returns a boolean value. If p is the distributive
%    polynomial one then true else false. */

    not dipzero!? p
        and dipzero!? dipmred p
            and evzero!? dipevlmon p
                and bcone!? diplbc p;



expr procedure   dippairsort pl;
%  /* Distributive polynomial list pair merge sort. pl is a list
%    of distributive polynomials. dippairsort(pl) returns the
%    list of merged and in non decreasing order sorted
%    distributive polynomials. */

    if null pl or null cdr pl then pl
       else diplmerge(diplmerge( car(pl) . nil, cadr(pl) . nil ),
                      dippairsort cddr pl);



expr procedure   dipprod (p1,p2);
%   /* Distributive polynomial product. p1 and p2 are distributive
%    polynomials. dipprod(p1,p2) calculates the product of the
%    two distributive polynomials p1 and p2, a distributive polynomial*/

     if diplength p1 <= diplength p2 then dipprodin(p1, p2)
        else dipprodin(p2, p1);



expr procedure   dipprodin (p1,p2);
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



expr procedure   dipprodls (p1,p2);
%   /* Distributive polynomial product. p1 and p2 are distributive
%     polynomials. dipprod(p1,p2) calculates the product of the
%     two distributive polynomials p1 and p2, a distributive polynomial
%     using distributive polynomials list sum (diplistsum). */

     if dipzero!? p1 or dipzero!? p2 then dipzero
        else car diplistsum if diplength p1 <= diplength p2
                               then dipprodlsin(p1, p2)
                               else dipprodlsin(p2, p1);



expr procedure   dipprodlsin (p1,p2);
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



expr procedure   dipsum (p1,p2);
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
    else if n=0 then if dipzero!? v then rederr "0**0 invalid"
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


module dipprint;   %/* printing routines for distributive polynomials*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

fluid '(dipvars!*);

expr procedure diplprint u;
%   /* Prints a list of distributive polynomials using dipprint*/
     for each v in u do dipprint v;

expr procedure dipprint u;
%   /* Prints a distributive polynomial in infix form*/
   <<terpri(); dipprint1(u,nil); terpri(); terpri()>>;

expr procedure dipprint1(u,v);
%   /* Prints a distributive polynomial in infix form.
%     U is a distributive form. V is a flag which is true if a term
%     has preceded current form*/
   if dipzero!? u then if null v then dipprin2 0 else nil
    else begin scalar bool,w;
       w := diplbc u;
       if bcminus!? w then <<bool := t; w := bcneg w>>;
       if bool then dipprin2 " - " else if v then dipprin2 " + ";
       (if not bcone!? w or evzero!? x then <<bcprin w; dipevlpri(x,t)>>
         else dipevlpri(x,nil))
           where x = dipevlmon u;
       dipprint1(dipmred u,t)
     end;

expr procedure dipprin2 u;
%   /* Prints u, preceding by two EOL's if we have reached column 70*/
   <<if posn()>69 then <<terpri(); terpri()>>; prin2 u>>;

endmodule;


module grinterf;  % Interface of Groebner package to REDUCE.

% /*Authors: R. Gebauer, A. C. Hearn, M. Moeller.

fluid '(dipvars!*);

expr procedure groebnereval u;
   begin integer n;
      n := length u;
      if n=1 then return groebner(reval car u,nil)
       else if n neq 2
        then rederr "GROEBNER called with wrong number of arguments"
       else return groebner(reval car u,reval cadr u)
      end;

put('groebner,'psopfn,'groebnereval);

expr procedure greduce u;
% /* Polynomial reduction modulo a Groebner basis driver. u is an
% expression and v a list of expressions.  Greduce calculates the
% polynomial u reduced wrt the list of expressions v reduced to a
% groebner basis modulo using the optional third argument as the
% order of variables.
   begin integer n; scalar dipvars!*,v;
      n := length u;
      v := for each j in getrlist reval cadr u collect
                      if eqexpr j then !*eqn2a j else j;
      if n=2
        then dipvars!* := for each j in gvarlis v collect !*a2k j
       else if n=3 then dipvars!* := getrlist caddr u
       else rederr "GREDUCE called with wrong number of arguments";
      v := groebner2 for each j in v collect a2dip j;
      if cdr v then errach list("Groebner",u)
       else  if null cdar v and dip2a caar v = 1
        then rederr "Inconsistent Basis";
      return dip2a dipnorform(car v,a2dip reval car u)
   end;

put('greduce,'psopfn,'greduce);

expr procedure preduce(u,v);
% /* Polynomial reduction driver. u is an expression and v a list of
% expressions.  Preduce calculates the polynomial u reduced wrt the list
% of expressions v. */
   begin scalar dipvars!*;
      v := for each j in getrlist reval v collect
              if eqexpr j then !*eqn2a j else j;
      dipvars!* := for each j in gvarlis v collect !*a2k j;
      return dip2a dipnorform(for each j in v collect a2dip j,
                              a2dip reval u)
   end;

flag('(preduce),'opfn);

endmodule;


module groebner;  % Basic Groebner base code using Buchberger algorithm.

% /*Authors: R. Gebauer, A. C. Hearn, M. Moeller.

fluid '(!*groebopt !*groebfac !*hopt !*trgroeb !*trgroebs !*trgroeb0
        !*trgroeb1 dipvars!* dipzero);

switch groebopt,groebfac,hopt,trgroeb,trgroebs,trgroeb0,trgroeb1;

% /*   option ' groebopt'    "optimizes" the given input     */
% /*                         polynomial set ( variable       */
% /*                         ordering )                      */
% /*   option ' trgroeb'     prints intermediate             */
% /*                         results on the output file      */
% /*   option ' trgroeb1'    prints internal representation  */
% /*                         of critical pair list d         */
% /*   option ' trgroeb0'    factorizes the S - polynom      */
% /*                         the S - polynom will not be     */
% /*                         replaced by a factor            */
% /*   option ' trgroebs '   prints S - polynomials          */
% /*                         on the output file              */
% /*   option ' hopt '       the H- polynomials are          */
% /*                         optimised using resultant       */
% /*                         and factorisation method        */
% /*   option ' groebfac '   the H - polynomials are         */
% /*                         factorized. If a H - polynom    */
% /*                         could be factorized, new sub-   */
% /*                         problems are generated and      */
% /*                         option ' fac ' is set to off    */
% /*                         NOTE: this option is not complete     */
% /*                         at the moment and has been suppressed */

% expr procedure bas p; diplprint car groebner(p,dipvars!*);


expr procedure groebner(u,v);
% /* Buchberger algorithm system driver. u is a list of expressions
%    and v a list of variables or NIL in which case the variables in u
%    are used.  Groebner(p) calculates the Groebner basis of the
%     expressions wrt the variables. */
   begin scalar dipvars!*,w;
      w := for each j in getrlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rederr "Empty list in Groebner"
       else if null cdr w then return 'list . w;
      if null v then v := gvarlis w else v := getrlist v;
      dipvars!* := for each j in v collect !*a2k j;
      w := groebner2 for each j in w collect a2dip j;
      if cdr w then errach list("Groebner",u,dipvars!*);
      return 'list . for each j in car w collect dip2a j
   end;


expr procedure gvarlis u;
   % Finds variables (kernels) in the list of expressions u.
   gvarlis1(u,nil);


expr procedure gvarlis1(u,v);
   if null u then v
    else union(gvar1(car u,v),gvarlis1(cdr u,v));


expr procedure gvar1(u,v);
   if null u or numberp u then v
    else if atom u then if u member v then v else u . v
    else if car u memq '(plus times expt difference minus)
     then gvarlis1(cdr u,v)
    else if car u eq 'quotient then gvar1(cadr u,v)
    else if u member v then v
    else u . v;


expr procedure groebner2 p;
 begin scalar tim,spac,spac1,p1;
       tim   := time(); % terprit 3;
       spac := gctime(); p1:= dipgbase p;
       spac1 := gctime() - spac;
%      prin2 " garbage collection time for test     ";
%      prin2 spac1;
%      prin2 "( not yet available )";
       if !*trgroeb then
        <<prin2 "Computing time for test ";
          prin2(time() - tim - spac1);
%      prin2(time() - tim );
          prin2t " milliseconds  ">>;
       return p1
 end;


expr procedure  dipindexpol(pl,n);
% Distributive polynomial index list. pl is a list of distributive
% polynomials; n is an index, an integer. dipindexpol(pl,n)
% returns a list of distributive polynomials in the form
% ( (n,p1) (n+1,p2) ..... (n+k,pk) ).
  if null pl then pl else
             list(n,car pl) . dipindexpol(cdr pl, n + 1);


expr procedure  dipindexpolspec pl;
% Distributive polynomial special list. pl is a list produced
% by dipindexpol. dipindexpolspec pl constructs a list of lists
% of polynomials in the form ( (p1,.....,pl) (p2,.....,pl)....
% ..(pl-1,,pl) (pl) ).
  for each pl0 on pl collect
                   ( for each pl1 in pl0 collect pl1 );


expr procedure  dipcpairlistopt pl;
% Distributive critical pair list optimise. pl is a special list
% ( constructed by dipcpairlist ) of elements used in the
% Groebner calculation. dipcpairlistopt(pl) returns a list which
% is optimised using Buchberger criterion 4.
 if pl then ( if buchcrit4(caddr x, cadddr x, cadr x)
        then x . dipcpairlistopt cdr pl
        else dipcpairlistopt cdr pl
             ) where x = car pl  else nil;


expr procedure dipcpairlistop(d,d0);
% Distributive polynomial critical pair list optimise.
% dipcpairlistop(d,d0) returns an optimised critical pair
% starting list using the new criteria's.
   begin scalar x;
  while d do << x:= dipcpairlistopt1(cadar d,d0,d0);
                                        d0:= x; d:= cdr d>>;
   return x
   end;


expr procedure dipcpairlistopt1(h,d,d0);
% Distributive polynomial critical pair list optimise version 1.
% dipcpairlistopt1(h,d,d0) returns an optimised critical pair
% list.
  if null d then d0 else ( if evmtest!?(cadar d,ev1) then
            dipcpairlistopt1(h, cdr d,x) else
            dipcpairlistopt1(h,cdr d,d0)
                     ) where x= dipcpairlistopt1in(ev1,cadar d,car d,d0)
                    where  ev1 = dipevlmon h;


expr procedure dipcpairlistopt1in(ev1,ev2,id1,d);
% Distributive polynomial critical pair list optimise version 1.
% internall. dipcpairlistopt1in is used in dipcpairlistopt1.
  if ev2 neq evlcm(ev1,dipevlmon caddr id1) and
     ev2 neq evlcm(ev1,dipevlmon cadddr id1) then
         dipcpairlistopt1in1(id1,d) else d;


expr procedure dipcpairlistopt1in1(d1,d);
% Distributive polynomial critical pair list optimise version 1
% internall version 1. dipcpairlistopt1in1 is used in
% dipcpairlistopt1in.
  if null d then nil else if d1 eq car d then
            dipcpairlistopt1in1(d1,cdr d) else
            car d . dipcpairlistopt1in1(d1,cdr d);


expr procedure dipindexpolrec pl;
% Distributive index polynom list reconstruct. pl is a list of
% polynomials used in the Groebner calculation. dipindexpolrec(pl)
% returns a list of distributive polynomials.
  for each p in pl collect cadr p;


 expr procedure  dipcplist pl;
% Distributive polynomial critical pair list construct.
% dipcplist returns a list of elements where an element has the
% structure ( (ipi,ipj) lcm(epi,epj) pi pj ).
% where ipi is the index of polynomial i, epi is the headterm of
% the polynomial pi.
 for each p in pl
     conc ( dipcplistopt2(nil, dipcplistin(ep, pi1, reverse cdr p))
          ) where ep = dipevlmon cadr pi1 where pi1 = car p;


expr procedure  dipcplistin(ep,p1,pl);
% Distributive polynomial critical pair list construct internall.
% dipcplistin is used in dipcplist.
  if null pl then pl else
          ( list(list(car p1,car p2), evlcm(ep,dipevlmon cadr p2),
            cadr p1, cadr p2) . dipcplistin(ep, p1, cdr pl)
          ) where p2 = car pl;


expr procedure dipcplistadd(ind,p,pl);
% Distributive polynomial critical pair list add.
% dipcplistadd returns a new critical pair list where all
% combinations of p with pl are added.
  if null pl then pl else
     ( list(list(car ps,ind),evlcm(dipevlmon p1,
     dipevlmon p),p1,p) . dipcplistadd(ind,p,cdr pl)
     ) where p1 = cadr ps where ps = car pl;


expr procedure dipcplistopt2in(p1,pl);
% Distributive polynomial critical pair list optimise version 2
% internall use. dipcplistopt2in(pl1,pl) is used in
% dipcplistopt2.
  if null pl then dipzero else
       ( if evmtest!?(cadr p1, cadr p) then
            dipcplistopt2in1(p1,p)
         else dipcplistopt2in(p1,cdr pl)
       ) where p = car pl;


expr procedure dipcplistopt2in1(p1,p2);
% Distributive polynomial critical pair list optimise version 2
% internall use version 1. dipcplistopt2in1(pl1,pl) is used in
% dipcplistopt2in.
  if cadr p1 = cadr p2 then
     ( if evilcompless!?(reverse car p1, reverse car p2) then
       p1 else p2 )
       else p2;


expr procedure dipindexpoloptin(p1,pl);
% Distributive index polynomial list optimise internall use.
% dipindexpoloptin is used in dipindexpolopt.
if null pl then dipzero else
     ( if evmtest!?(dipevlmon cadr p1, dipevlmon cadr p) then
      dipindexpoloptin1(p1,p)
        else dipindexpoloptin(p1,cdr pl)
     ) where p = car pl;


expr procedure dipindexpoloptin1(p1,p2);
% Distributive index polynomial list optimise internall version 1.
% dipindexpoloptin1 is used in dipindexpoloptin.
  if dipevlmon cadr p1 = dipevlmon cadr p2
     then ( if car p1 < car p2 then p1 else p2 )
          else p2;


expr procedure dipcplistopt2(pl1,pl2);
% Distributive polynomial critical pair list optimise version 2.
% dipcplistopt2(pl1,pl2) returns the optimised critical pair list.
  if null pl2 then pl1 else
     ( if dipzero!? dipcplistopt2in(p,pl1)
       and dipzero!? dipcplistopt2in(p,pl0)
       then dipcplistopt2(cons(p,pl1),pl0)
       else dipcplistopt2(pl1,pl0)
     ) where p = car pl2, pl0 = cdr pl2;


expr procedure dipindexpolopt(pl1,pl2);
% Distributive index polynomial list optimise. pl1 and pl2
% are lists of polynomials used in the Groebner calculation.
% dipindexpolopt(pl1,pl2) returns an optimised list of polynomials.
  if null pl2 then pl1 else
   ( if dipzero!? dipindexpoloptin(p,pl1) and
        dipzero!? dipindexpoloptin(p,pl0)
        then dipindexpolopt(cons(p,pl1),pl0)
        else dipindexpolopt(pl1,pl0)
   ) where p = car pl2, pl0 = cdr pl2;


expr procedure dipcplistsort pl;
% Distributive polynomial critical pair list sort. pl is a
% special list for Groebner calculation. dipcplistsort(pl)
% returns the sorted list pl;
  begin scalar tree;
    if null pl then return nil;
    tree :=  list(car pl,nil);
    while pairp(pl:= cdr pl) do dipcplistsortadd(car pl,tree);
    return tree2list(tree,nil)
  end;


smacro procedure dipcplistevlcomp(p1,p2);
% Distributive polynomial critical pair list exponent vector
% compare. p1 and p2 are elements of the critical pair list.
% dipcplistevlcomp(p1,p2) returns a boolean expression, true
% if exponent vector of p1 is smaller or equal exponent vector
% of p2 else false.
  evcompless!?(cadr p1, cadr p2);


expr procedure dipcplistsortadd(item,node);
% Distributive polynomial critical pair list sort addition.
% add item to a node, using dipcplistevlcomp as an order
% predicate.
  if dipcplistevlcomp(item, car node) then if cadr node then
  dipcplistsortadd(item, cadr node) else
       rplaca(cdr node,list(item,nil))  else
       if cddr node then dipcplistsortadd(item,cddr node) else
       rplacd(cdr node,list(item,nil));


expr procedure dipcplistmerge(pl1,pl2);
% Distributive polynomial critical pair list merge. pl1 and pl2
% are critical pair lists used in the Groebner calculation.
% dipcplistmerge(pl1,pl2) returns the merged list.
  if null pl1 then pl2 else if null pl2 then pl1
  else ( if sl then cpl1 . dipcplistmerge(cdr pl1,pl2)
  else cpl2 . dipcplistmerge(pl1,cdr pl2)
       ) where sl = evcompless!?(cadr cpl1, cadr cpl2)
        where cpl1 = car pl1, cpl2 = car pl2;

expr procedure buchcrit4(p1,p2,e);
% Buchberger criterion 4. p1 and p2 are distributive
% polynomials. e is the least common multiple of
% the leading exponent vectors of the distributive
% polynomials p1 and p2. buchcrit4(p1,p2,e) returns a
% boolean expression. True if the reduction of the
% distributive polynomials p1 and p2 is necessary
% else false.
 e neq evsum( dipevlmon p1, dipevlmon p2);


expr procedure   dipgbase pl;
%  /* Distributive polynomial Groebner base. pl is a list of distributiv
%    polynomials. dipgbase(pl) calculates the Groebner base of the list
%    of distributive polynomials pl and returns a list of distributive
%    polynomials. */
    if null pl then nil
     else if null cdr pl then list pl
     else if !*groebopt then dipgbasein dipvordopt pl
     else dipgbasein pl;


expr procedure   gbprint pl;
% Groebner basis list of distributive polynomials print.
for each p in pl do dipprint dipmonic p;


expr procedure rescheck!?(a,h1,vl);
  length h1 = a and car h1 = vl - 1;


expr procedure rescheck1!?(a,h1,vl);
  length h1 = a and car h1 = vl - 2 and cadr h1 = vl - 1;


expr procedure newhpol(p1,p2,x);
begin scalar q1,q2,q;
q1:=dip2a diprectoint(p1,diplcm p1);
q2:=dip2a diprectoint(p2,diplcm p2);
q:=a2dip prepsq simpresultant list(q1,q2,x);
return q;
end;


expr procedure sqpol p1;
begin scalar q1,q;
q1:=dip2a diprectoint(p1,diplcm p1);
q:=a2dip caar sqfrf q1;
return q;
end;


expr procedure   dipnorfor (pl,p);
%  /* Distributive polynom normalform. pl is a list of distributive
%    polynomials, p is a distributive polynomial. dipnorfor(pl,p)
%    calculates a distributive polynomial such that the powerproduct
%    of the distributive
%    polynomial p is reducible to this modulo the distributive
%    polynomial list pl and is in normalform with respect to the
%    distributive polynomial p and returns a distributive polynomial. */
     if dipzero!? p or null pl then p
        else ( if dipzero!? q then p
             else (
                if dipzero!? rq then  dipnorfor(pl,dipmred p)
                      else dipnorfor(pl,
                              dipdif(dipmred p,
                                 dipprod(rq,
                                    dipfmon(bcquot(diplbc p,
                                                   diplbc q),
                                            evdif(ep,
                                                  dipevlmon q) ) ) ) )
             ) where rq = dipmred q
             ) where q = dipnorformsel(ep, pl)
                  where ep = dipevlmon p;


expr procedure dipmingbase pl;
% Distributive polynomial minimal ordered Groebner base. pl is a
% list of distributive polynomials. dipmingbase(pl) calculates
% the minimal normed and ordered Groebner base of the distributive
% polyomials pl and returns a list of distributive polyomials.
  if null cdr pl then pl
            else dipmingbasein2(nil,dipmingbasein1(nil,pl) );



expr procedure   dipgbasein ql;
%  /* Distributive polynomial Groebner base. pl is a list of distributiv
%    polynomials. dipgbase(pl) calculates the Groebner base of the list
%    of distributive polynomials pl and returns a list of distributive
%    polynomials. */
begin scalar ql0,u,ql1,w,d,ql22,lql1,ql11,lv,h1h0,d1,d0,p1,
    sp0,n,dl,p2,ct1,sp,h,ct11,h1,h10,hs1,h1h1,h0,hs2;
       u := 1; w := 1; n := 1; ql0 := nil;
       ql1:= dipindexpol(ql,1);
       d:= dipcplistsort dipcpairlistopt dipcplist dipindexpolspec ql1;
           ql22 := ql;
           lql1:= length ql1;  ql11:=dipindexpolopt(nil, ql1);
           d:=dipcpairlistop(ql11,d);
       if !*hopt then << lv:=length dipvars!*; h1h0:=nil>>;
           d1:=list list(lql1,ql1,ql11,ql22,d);
        if !*trgroeb1 then <<
           prin2 " list d1 =   ";
           prin2 d1; terpri();
           prin2 length d1; terpri() >>;
           while not null d1 do <<
              d0:= car d1; d1:= cdr d1; lql1:= car d0;
              ql1:= cadr d0; ql11:= caddr d0;
              ql22:= cadddr d0; d:= cadddr cdr d0;
           while not null d do   <<
                     dl:= car d;
                     d := cdr d;
                     p1:= caddr dl;
                     p2:= cadddr dl;
                       if !*trgroeb then << ct1 := time() >>;
                       sp := dipspolynom(p1,p2);
                                  if !*trgroebs then <<
                                     prin2t "S-polynom:";
                                     dipprint sp; terpri() >>;
          if !*trgroeb0 then << sp0:= dip2a diprectoint(sp,diplcm sp);
                         sp0:= factorf !*q2f simp sp0;
                         dfcprin sp0; terprit 2 >>;
                   h := dipnorform(ql22, sp);
                       if !*trgroeb then << ct11 := time() - ct1 >>;
                       if dipzero!? h then <<
      if !*trgroeb then <<  terprit 2; printb 57; terpri();
                       prin2 " / reduction of polynom "; prin2 caar dl;
                       prin2 " and "; prin2 cadar dl;
                       prin2 " leads to 0  "; prin2 " ( ";
                       prin2 ct11; prin2 "  ms )";
                       terpri(); printb 57; terprit 2 >> >>;
                       if not dipzero!? h then
                           if dipconst!? h
                             then  <<
                                  ql11:= list list(lql1,dipmonic h);
                                                          d:=nil >>
                     else  << h1 := dipmonic h; lql1:= lql1 + 1;
                                  if !*trgroeb then <<
                                     prin2 "h-polynom ";
                                     prin2 lql1; prin2 "     pair";
                       prin2 " ( "; prin2 caar dl;
                       prin2 ","; prin2 cadar dl; prin2t " ) :";
                                     dipprint h1; terpri();
                       prin2 " computing time for h-polynom ";
                       prin2 ct11;
                            terprit 3 >>;
     % The following option has been suppressed since it is not
     % complete.
     if nil and !*groebfac and u = 1 then << h10:= h1;
                          h1:= dip2a diprectoint(h1,diplcm h1);
                          h1:= factorf !*q2f simp h1;
                             hs1:= reverse diplsort makdiplist cdr h1;
                                  if !*trgroeb then <<
                                     prin2 "h-polynom factorized:  ";
                                     terpri();
                                     dfcprin h1; terpri()  >>;
                         h1:= dipmonic car hs1; hs1:= reverse cdr hs1;
                         if  not dipzero!? (dipdif(h1,h10)) then
                         << u:= 0 >>;
                        if !*trgroeb  then <<   prin2 " new h-polynom ";
                          terprit 3;  dipprint h1; terprit 2 >> >>;
   if !*hopt and w = 1 then <<
                     h1h1:= indexcpl(evsum0(lv,h1),1);
   if !*trgroeb then <<  prin2 " index: "; prin2 h1h1; terpri();
                       prin2 " index: "; prin2 h1h0; terprit 3 >>;
                     if  h1h1 = h1h0
                     and rescheck!?(2,h1h0,lv)
                       then <<
                    hs2:= reverse diplsort
                          newhpo(h1,h0,cadr reverse dipvars!*); w:= 0>>;
                     if  h1h1 = h1h0
                     and rescheck1!?(2,h1h0,lv)
                       then <<
                hs2:= reverse diplsort
                      newhpo(h1,h0,caddr reverse dipvars!*); w:= 0  >>;
       if null hs2 then << w:= 1 >>
                     >>;
   if u = 0 and not null hs1 then <<
                     d0:= maklistd1(hs1,lql1,ql1,ql11,ql22,d);
                     u:= 2; d1:=nconc(d0,d1)  >>;
%%%%%%%              u:= 1; d1:=nconc(d0,d1)  >>;
                     d:= dipcpairlistopt1(h1,d,d);
   if !*trgroeb then  << terpri(); prin2 "Restpairs: ";
                       prin2t length d; terpri() >>;
                  d:=  dipcplistmerge(dipcplistsort
   dipcpairlistopt dipcplistopt2(nil,dipcplistadd(lql1,h1,ql11)),d);
if !*hopt and w = 1 then << h1h0:=indexcpl(evsum0(lv,h1),1); h0:= h1 >>;
                   ql11:= nconc(list list(lql1,h1),ql11);
                   ql22:= nconc(list(h1),ql22);
                   ql11:= dipindexpolopt(nil,ql11);
if !*trgroeb1 then <<  prin2 " *** d =   "; prin2 d; terpri();
                     prin2t " ql11   "; prin2 ql11; terpri() >>;
 if w = 0 then << h1:= dipmonic car hs2; hs2:= reverse cdr hs2;
           lql1:= lql1 + 1; if not null hs2 then <<
           d0:= maklistd1(hs2,lql1,ql1,ql11,ql22,d);
           w:= 2; d1:= nconc(d0,d1)     >>;
                     d:= dipcpairlistopt1(h1,d,d);
                     d:=  dipcplistmerge(dipcplistsort
   dipcpairlistopt dipcplistopt2(nil,dipcplistadd(lql1,h1,ql11)),d);
                   ql11:= nconc(list list(lql1,h1),ql11);
                   ql22:= nconc(list(h1),ql22);
                      ql11:= dipindexpolopt(nil,ql11);
if !*trgroeb1 then <<  prin2 " *** d =   "; prin2 d; terpri();
                     prin2t " ql11   "; prin2 ql11; terpri() >>
             >>    >> >>;
           ql11:=dipindexpolrec ql11;
           if !*trgroeb then <<
           prin2t " calculation now in final reduction ";
           terpri(); ct1 := time() >>;
           ql:=dipmingbase diplsort ql11;
           if !*trgroeb then << ct11 := time() - ct1;
              prin2 " computing time for final calculation ";
              prin2 ct11;
              prin2 "    milliseconds "; terprit 3;
           prin2 " Number of Groebner Basis Polynomials :=   ";
           prin2t length ql; terprit 2;
           if n = 1 and null d1 then <<
           prin2t " The Groebner Basis Polynomials "; terpri() >>
           else
           << prin2 " The Groebner Basis Polynomials  ( Factor ";
           prin2 n; prin2t "  )"; terpri(); n:= n + 1 >>;
           gbprint ql;
           if not null d1 then <<
           prin2 " Calculation for Factor  "; prin2t n; terprit 4 >>
                       >>;  ql0:= ql . ql0     >>;
           return ql0
           end;


expr procedure makdiplist pl;
% Make list of distributive polynomials from list of polynomials pl.
  for each p in pl collect a2dip prepf car p;


expr procedure terprit n;
% print blank lines.
   for i:=1:n do << terpri() >>;


expr procedure printb n;
% print special sign ( - ).
   for i:=1:n do << prin2 "-" >>;


expr procedure newhpo(h1,h0,x);
% new h-polynom calculation. newhpo(h1,h2,x) calculates
% the resultant of the two distributive polynomials h1 and h0
% with respect to x.
begin scalar ct00,hh,hh1,hs2;
   if !*trgroeb then << ct00:= time() >>;
              hh:= dipmonic newhpol(h1,h0,x);
   if !*trgroeb  then <<   prin2 " resultant "; terprit 2;
                     dipprint hh; terprit 4 >>; hs2:= nil;
   if not dipzero!? hh then << hh1:= dip2a diprectoint(hh,diplcm hh);
                          hh1:= factorf !*q2f simp hh1;
   if !*trgroeb then << prin2 " resultant factorized:  "; terprit 2;
                      dfcprin hh1; terprit 2;
                      ct00:= time() - ct00;
                     prin2 " special time for h:    "; prin2 ct00;
                     terpri() >>;
                     hs2:= makdiplist cdr hh1 >>;
  return hs2
  end;


expr procedure maklistd1(x1,x2,x3,x4,x5,x6);
% make list d1. save part time problems.
  begin scalar x,h1;
   while x1 do  << h1:= car x1; x1:= cdr x1;
           x:= list(x2,x3,
               (dipindexpolopt(nil,nconc(list list(x2,h1),x4))),
               (nconc(list h1,x5)),
               (dipcplistmerge(dipcplistsort
         dipcpairlistopt dipcplistopt2(nil,dipcplistadd(x2,h1,x4)),
               dipcpairlistopt1(h1,x6,x6)))) . x >>;
   return x
   end;


expr procedure   dipmingbasein1 (pl1,pl2);
%  /* Distributive polynomial minimal ordered Groebner base internal1.
%    pl1 and pl2 are lists of distributive polynomials.
%    dipmingbasein1(pl1,pl2) is used in dipmingbase and returns a list
%    of  distributive polynomials. */
     if null pl2 then pl1
        else ( if dipzero!? dipnorformsel(ep, pl1)
                  and dipzero!? dipnorformsel(ep,cpl2)
                      then dipmingbasein1( cons(p, pl1), cpl2)
                           else dipmingbasein1( pl1, cpl2)
             ) where  ep = dipevlmon p,
                      cpl2 = cdr pl2
              where  p = car pl2;


expr procedure   dipmingbasein2 (pl1,pl2);
%  /* Distributive polynomial minimal ordered Groebner base internal2.
%    pl1 and pl2 are lists of distributive polynomials.
%    dipmingbasein2(pl1,pl2) is used in dipmingbase and returns a list
%    of  distributive polynomials. */
     if null pl2 then pl1
        else ( dipmingbasein2(dipnorform(pl1,dipnorform(rp, p)) . pl1,
                             rp) )
               where p  = car pl2,
                     rp = cdr pl2;



expr procedure   dipnorform (pl,p);
%  /* Distributive polynom normalform. pl is a list of distributive
%    polynomials, p is a distributive polynomial. dipnorform(pl,p)
%    calculates a distributive polynomial such that the distributive
%    polynomial p is reducible to this modulo the distributive
%    polynomial list pl and is in normalform with respect to the
%    distributive polynomial p and returns a distributive polynomial. */
     if dipzero!? p or null pl then p
        else ( if dipzero!? q then dipmoncomp(diplbc p,
                                             ep,
                                             dipnorform(pl,
                                                        dipmred p) )
               else ( if dipzero!? rq then dipnorform(pl, dipmred p)
                      else dipnorform(pl,
                              dipdif(dipmred p,
                                 dipprod(rq,
                                    dipfmon(bcquot(diplbc p,
                                                   diplbc q),
                                            evdif(ep,
                                                  dipevlmon q) ) ) ) )
                    ) where rq = dipmred q
             ) where q = dipnorformsel(ep, pl)
                  where ep = dipevlmon p;

expr procedure   dipnorformsel (ep,pl);
%  /* Distributive polynom normalform select. ep is an exponent vector
%    of a distributive polynomial. pl is a list of distributive
%    polynomials. dipnorformsel(ep,pl) returns a distributive
%    polynomial of pl where ep is a multiple of the leading
%    exponent vector else dipzero. */
     if null pl then dipzero
        else ( if evmtest!?(ep, dipevlmon q) then q
                  else dipnorformsel(ep, cdr pl)
             ) where q = car pl;


expr procedure   dipspolynom (p1,p2);
% /* Distributive polynom S polynom. p1 and p2 are distributive
%   polynomials. dipspolynom(p1,p2) calculates the S polynom of the
%   distributive polynomials p1 and p2 and returns a distributive
%   polynomial. */
    if dipzero!? p1 or dipzero!? p2 then dipzero
       else ( if dipzero!? rp1 and dipzero!? rp2 then rp1
              else ( if dipzero!? rp1 then
                        dipprod(rp2,
                                dipfmon(bcneg diplbc p1,
                                       evdif(ep, ep2) ) )
                     else if dipzero!? rp2 then
                             dipprod(rp1,
                                     dipfmon(diplbc p2,
                                            evdif(ep, ep1) ) )
                          else dipdif(
                                      dipprod(rp2,
                                              dipfmon(diplbc p1,
                                                     evdif(ep, ep2) ) ),
                                      dipprod(rp1,
                                              dipfmon(diplbc p2,
                                                     evdif(ep, ep1) ) )
                                     )
                   ) where ep = evlcm(ep1, ep2)
                        where ep1 = dipevlmon p1,
                              ep2 = dipevlmon p2
            ) where rp1 = dipmred p1,
                    rp2 = dipmred p2;



expr procedure delqip1(u,v);
   if pairp cdr v
     then if u eq cadr v then rplacd(v,cddr v) else delqip1(u,cdr v);


expr procedure delqip(u,v);
%  /*Destructive delete of first occurrence of u in v*/
   if not pairp v then v
    else if u eq car v then cdr v
    else <<delqip1(u,v); v>>;


endmodule;


module dipopt;

%  /* Authors: R. Gebauer, A. C. Hearn, H. Kredel */

fluid '(!*trbas dipvars!*);

%define ezero = 'nil;

fluid '(dipzero ezero);
     %/*Until we understand how to define something to nil*/

expr procedure dipoptmat1 (el,dpl);
%  /* Distributive optimisation matrix subfunction 1. el is an
%    exponent vector, dpl is a degree matix. dipoptmat1(el,dpl)
%    returns the addition of el to dpl. */
     if null el then dpl
        else dipsum ( dipfmon (bcfi 1,
                               evcons(evfirst el, ezero)), car dpl)
             . dipoptmat1(evred el, cdr dpl);


expr procedure dipoptmat2 (p,pl);
%  /* Distributive optimisation matrix subfunction 2. p is a
%    distributive polynomial, pl is a list of distributive
%    polynomials. dipoptmat1 is used. */
     if dipzero!? p then pl
        else dipoptmat2(dipmred p, dipoptmat1(dipevlmon p, pl));


expr procedure dipoptmat3 (p,pl);
%  /* Distributive optimisation matrix subfunction 3. p is a
%    distributive polynomial, pl is a list of distributive
%    polynomials. dipoptmat2 is used. */
     if null p then pl
        else dipoptmat3(cdr p, dipoptmat2(car p, pl));


expr procedure dipoptmat pl;
%  /* Distributive optimisation matrix. pl is a list of distributive
%    polynomials. dipoptmat(pl) returns the optimisation matrix
%    ( a degree matrix ) of pl, a list of univariate distributive
%    polynomials. */
     if null pl then nil
        else dipoptmat3(pl, for each x in dipvars!* collect dipzero);


expr procedure dipless!? (p1,p2);
%  /* Distributive polynomial less. p1 and p2 are distributive
%    polynomials. dipless!?(p1,p2) returns a boolean expression,
%    true if p1 is less than p2 else false. */
     if dipzero!? p1 and dipzero!? p2 then nil
        else if not dipzero!? p1 then
                if not dipzero!? p2 then
                 ( if sl < 0 then t
                      else if sl > 0 then nil
                      else ( if bl < 0 then t
                              else if bl > 0 then nil
                              else dipless!?(dipmred p1, dipmred p2)
                           )  where bl = bccomp(diplbc p1, diplbc p2)
                 ) where sl = evcomp(dipevlmon p1, dipevlmon p2)
                else t
             else nil;


expr procedure pvdema pl;
%  /* Permutation vector degree matrix. pl is a list of univariate
%    polynomials in distributive representation. pvdema(pl) returns
%    a list ( indexlist ) where the elements are digits.*/
     pvdema2 sort(pvdema1(pl, 1), 'pvdema3);


expr procedure pvdema1(pl,n);
%  /* Permutation vector degree matrix subfunction 1. pl is a list
%    of univariate distributive polynomials, n is a digit.
%    pvdema1 changes the internal structure ( add index for each
%    polynomial ) and is used in pvdema. */
     if null pl then pl
        else list(car pl, n) . pvdema1(cdr pl, n + 1);


expr procedure pvdema2(pl);
%  /* Permutation vector degree matrix subfunction 2. pl is a list of
%    univariate distributive polynomials. pvdema2(pl) changes the
%    internal structure ( delete index for each polynomial ) and
%    is used in pvdema. */
     if null pl then pl
        else nconc(cdar pl, pvdema2(cdr pl));


expr procedure pvdema3 (p1,p2);
%  /* Permutation vector degree matrix subfunction 3. p1 and p2 are
%    distributive univariate polynomials. pvdema3(p1,p2) returns
%    a boolean expression, true if the distributive polynomial p1
%    is less than the distributive polynomial p2 else false. */
     dipless!?(car p1, car p2);


expr procedure listperm (v,n);
%  /* List permutation. v is a list ( any kind ) and n is an indexlist.
%    listperm(v,n) permutates v in respect to n and returns a
%    permutated list v. */
     if null n then nil
        else nth(v, car n) . listperm(v, cdr n);


expr procedure dipreorder (p,n);
%  /* Distributive polynomial reorder. p is a distributive polynomial,
%    n is an indexlist. dipreorder(p,n) reorders the exponent vectors
%    of each term of p in respect to the indexlist n and returns a
%    distributive polynomial. */
     if dipzero!? p then nil
        else dipsum(dipfmon(diplbc p, evperm(dipevlmon p, n)),
                    dipreorder(dipmred p, n));


expr procedure diplreorder (pl,n);
%  /* Distributive polynomial list reorder. pl is a list of distributive
%    polynomials and n is an indexlist. diplreorder(pl,n) reorders the
%    exponent vectors of each term of each polynomial in the list pl in
%    respect to the indexlist n and returns a list of distributive
%    polynomials.*/
     for each x in pl collect dipreorder(x, n);


expr procedure dipvordopt pl;
%  /* Distributive polynomial variable ordering optimisation.
%    pl is a list of distributive polynomials. dipvordopt(pl)
%    calculates the " optimal representation " and returns a list
%    of distributive polynomials.
%    NOTE: dipvordopt can change the global variable list dipvars!* */
     begin scalar n,olddipvars,pl1;
        n := pvdema diopmatin pl;
        if !*trbas then <<  prin2t " The new index list :";
         terprit 2; prin2t n; terprit 2  >>;
         olddipvars := dipvars!*;
         dipvars!* := listperm(dipvars!*, n);
        if !*trbas then <<  prin2t " The new variable list :";
         terprit 2; prin2t dipvars!*; terprit 2 >>;
         pl1 := diplreorder(pl, n);
        if !*trbas then <<  prin2t " The new polynomial list :";
         terprit 2; diplprint pl1; terprit 2 >>;
%       dipvars!* := olddipvars;
        return pl1
     end;


expr procedure diopmatin pl;
% print univariate polynomials.
   begin scalar n1;
        << if !*trbas then << prin2t " The variable list :";
           terprit 2; prin2t dipvars!*; terprit 2;
           prin2t " The univariate polynomials in each variable :";
           terprit 2 >>; n1:=dipoptmat pl;
           if !*trbas then << dioprin(n1,dipvars!*) >> >>;
     return n1
     end;


expr procedure dioprin(pl,d);
% print variables.
     begin scalar dipvars!*;
       for each x in pair(pl,d)
                  do << dipvars!* := list cdr x; dipprint car x >>
     end;


endmodule;


end;
