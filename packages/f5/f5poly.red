module f5poly;
% f5 polynomials. Polynomial interface to be used in f5. Implements a
% `Polynomial` data type.

revision('f5poly, "$Id$");

copyright('f5poly, "(c) 2022 A. Demin, T. Sturm, MPI Informatics, Germany");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

% Polynomial `p` is stored as a list of 4 items:
%     {'p, Terms, Coeffs, Sugar}
% Where `p` is a convenience tag,
%       `Terms` is a list of `Term`s. Each `Term` is an exponent list of
%         non-negative integers of form
%              {totaldegree, pow1, pow2, ... pown}
%              `Term` supports basic arithmetic operations,
%              the interface is defined further in this file.
%       `Coeffs` is a list of `Coeff`s,
%         where `Coeff` can be either a SQ or an Integer.
%       `Sugar` is an Integer, the sugar degree.
% Some relevant functions on `Coeff` are defined further in this file:
%     . poly_addCoeff(x, y)  -- addition x + y
%     . poly_divCoeff(x, y)  -- division x / y
%     . poly_invCoeff(x)     -- inverse  x^(-1)
%     . poly_negCoeff(x)     -- negation -x
%     . poly_mulCoeff(x, y)  -- product  x * y
%     . poly_iszeroCoeff(x)  -- zero?    x
%
% `Terms` are ordered according to the current term order decreasingly,
%  and `Coeffs` are ordered respectively.
%
% For example, xy^2 + 3x is stored as
%  {'p, {{3, 1, 2}, {1, 1, 0}}, {1 ./ 1, 3 ./ 1}, 3}
%
% Zero polynomial is represented as
%   {'p, nil, nil, anything}
%
% The global polynomial ring should be initialized before constructing polynomials.
% To initialize the ring in variables `vars` and sort mode `ord`
% the function `poly_initRing(vars, ord)` should be used.

off1 'allfac;

% We use the term order comparators for exponent lists from dipoly
load!-package 'dipoly;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Returns the current torder
asserted procedure poly_extractTorder(): List;
   begin scalar oldTorder;
      oldTorder := torder('(list));
      torder(cdr oldTorder);
      dipsortingmode(vdpsortmode!*);
      return oldTorder
   end;

% Initializes polynomial ring with the parameters from `u`,
% and returns the corresponding torder.
%
% Possible options are:
%  - u is nil, then change nothing;
%  - u is of length 1, then set variables in torder to the only element of u;
%  - u is of length 2, then set variables and order in torder to the ones of u.
asserted procedure poly_initRing(u: List): List;
   begin scalar vars, ord, oldTorder;
      if null u then <<
         oldTorder := poly_extractTorder()
      >> else if length(u) = 1 then <<
         vars := pop u;
         oldTorder := poly_extractTorder();
         global!-dipvars!* := 'list . vars
      >> else <<
         vars := pop u;
         ord  := pop u;
         if null u then
            oldTorder := torder({'list . vars, ord})
         else
            oldTorder := torder({'list . vars, ord, pop u})
      >>;
      return oldTorder
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% POLYNOMIAL INTERFACE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Constructor of Polynomial, forms a Polynomial
% from a list of `Term`s, a list of `Coeff`s, and a sugar degree.
asserted inline procedure poly_PolynomialWithSugar(ts: Terms, cfs: Coeffs, sugar: Integer): Polynomial;
   {'p, ts, cfs, sugar};

% Same as above, but doesn't care about sugar
asserted inline procedure poly_Polynomial(ts: Terms, cfs: Coeffs): Polynomial;
   poly_PolynomialWithSugar(ts, cfs, 0);

asserted inline procedure poly_getTerms(poly: Polynomial): Terms;
   cadr poly;

asserted inline procedure poly_getCoeffs(poly: Polynomial): Coeffs;
   caddr poly;

asserted inline procedure poly_getSugar(poly: Polynomial): Integer;
   cadddr poly;

% Returns zero polynomial
asserted inline procedure poly_zero(): Polynomial;
   poly_Polynomial(nil, nil);

% Returns polynomial one
asserted inline procedure poly_one(): Polynomial;
   poly_Polynomial({poly_zeroExp()}, {poly_oneCoeff()});

% Checks if `p` is zero
asserted inline procedure poly_iszero!?(p: Polynomial): Boolean;
   null poly_getTerms(p);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% POLYNOMIAL CONVERSIONS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% SF, SQ --> Poly

% Constructs a Polynomial from a SF `u`
asserted inline procedure poly_sf2poly(u: SF): Polynomial;
   poly_sq2poly(u ./ 1);

% Conversion to Polynomial: scan the standard form. ev and bc are the
% exponent and coefficient parts collected so far from higher parts.
asserted procedure poly_sf2poly1(u: SQ, ev: List, bc: Coeff): Polynomial;
  if null u then
     poly_zero()
  else if domainp u then
     poly_PolynomialWithSugar({ev}, {poly_mulCoeff(bc, poly_2Coeff(u))}, poly_totalDegExp(ev))
  else
     poly_sumPoly(poly_sf2poly2(mvar u,ldeg u,lc u,ev,bc), poly_sf2poly1(red u,ev,bc));

% Returns true if `var` is the variable in the current polynomial ring,
% nil otherwise
asserted procedure poly_isPolyVar(var: Any): Boolean;
   begin scalar vars;
      vars := global!-dipvars!*;
      while vars and not (car vars eq var) do
         vars := cdr vars;
      return not null vars
   end;

% returns var^deg as a Standard Quotient
asserted inline procedure poly_groundCoeff(var, deg);
   ((((var . deg) . 1) . nil) ./ 1);

% Conversion to Polynomial: multiply leading power either into exponent vector
% or into coefficient
asserted procedure poly_sf2poly2(var,dg,c,ev,bc): Polynomial;
   if poly_isPolyVar(var) then 
      poly_sf2poly1(c,poly_insertExp(ev, var, dg, cdr global!-dipvars!*), bc)
   else
      poly_sf2poly1(c, ev, poly_mulCoeff(bc, poly_groundCoeff(var, dg)));

% Constructs a Polynomial from a SQ `u`.
% Assuming the Polynomial is correct, `poly_poly2sq` is the inverse function, 
% so that poly_poly2sq(poly_sq2poly(x)) = x.
asserted inline procedure poly_sq2poly(u: SQ): Polynomial;
   poly_sq2poly1(u, poly_zeroExp(), poly_oneCoeff());

% Recusrively converts a Standard Quotient X/Y to a Polynomial.
% Polynomial variables are encoded in exponent vector `ev`, 
% and parameters are encoded in coefficient `bc`.
% If polynomial variable is encountered in denominator Y, an error is raised.
asserted procedure poly_sq2poly1(u: SQ, ev: List, bc: Coeff): Polynomial;
   begin scalar numpoly;
      for each var in kernels denr u do <<
         if poly_isPolyVar(var) then
            rederr {"Polynomial variable in denominator in input:", var}
      >>;
      numpoly := poly_sf2poly1(numr u, ev, bc);
      return poly_multCoeffs(numpoly, 1 ./ denr u)
   end;

% SQ --> Poly

% Converts cf*tm where cf is a Coeff and tm is a Term
% to a Standard Quotient
asserted procedure poly_lead2sq(cf: Coeff, tm: Term): SQ;
   begin scalar vs;
      vs := global!-dipvars!*;
      for each e in cdr tm do    % not very general
         cf := multsq(mksp!*(numr simp (pop vs), e) ./ 1, cf);
      return cf
   end;

% Converts a Polynomial to a Standard Quotient
asserted procedure poly_poly2sq(p: Polynomial): SQ;
   addsq(
      poly_lead2sq(poly_leadCoeff(p), poly_leadTerm(p)), 
      poly_poly2sq(poly_tail(p))
   );

% Poly --> Lisp Prefix 

% Returns prefix equivalent to the sum of elements of u
asserted procedure poly_replus(u: List): List;
   if atom u then u else if null cdr u then car u else 'plus . u;

% Returns prefix equivalent to the product of elements of u.
% u is a list of prefix expressions the first of which is a number.
procedure poly_retimes(u: List): List;
   if car u = 1 then
      if cdr u then poly_retimes cdr u else 1
   else if null cdr u then
      car u
   else
      'times . u;

% Returns prefix equivalent to the Polynomial u.
asserted procedure poly_poly2lp1(u: Polynomial): List;
   begin scalar x,y;
      if poly_iszero!?(u) then
         return nil;
      x := poly_leadCoeff u;
      y := poly_2aExp poly_leadTerm u;
      if poly_isNegCoeff!?(x) then <<
         return {'minus,poly_retimes(poly_2aCoeff(poly_negCoeff(x)) . y)} . poly_poly2lp1 poly_tail(u)
      >>;
      return poly_retimes(poly_2aCoeff x . y) . poly_poly2lp1 poly_tail(u)
   end;

% Converts a Polynomial to an equivalent Lisp Prefix
asserted procedure poly_poly2lp(f: Polynomial): List;
   if poly_iszero!?(f) then 0 else poly_replus poly_poly2lp1(f);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% EXPONENT LISTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Invariant: the first entry in the exponent list is the sum of subsequent entries

% Returns the first entry in the exponent list - the total degree
asserted inline procedure poly_totalDegExp(e1: List): Integer;
   car e1;

% Returns exponent list of zeros of the appropriate length
asserted inline procedure poly_zeroExp(): List;
   for x := 1:length(global!-dipvars!*) collect 0;

asserted procedure poly_sumExp(e1: List, e2: List): List;
   <<
      ASSERT(not null e1 and not null e2);
      if car e1 #= 0 then
         e2
      else if car e2 #= 0 then
         e1
      else
         for each x in e1 collect x #+ pop e2
   >>;

% Return the elementwise subtraction of exponent lists e1, e2
asserted procedure poly_subExp(e1: List, e2: List): List;
   <<
      ASSERT(not null e1 and not null e2);
      for each x in e1 collect x #- pop e2
   >>;

% Returns the elementwise maximum of exponent lists e1, e2
asserted procedure poly_elmaxExp(e1: List, e2: List): List;
   begin scalar w;
      ASSERT(not null e1 and not null e2);
      e1 := cdr e1;
      e2 := cdr e2;
      w := for each x in e1 collect max(x, pop e2);
      return (for each x in w sum x) . w
   end;

% Checks if e1 is elementwise less or equal than e2
asserted procedure poly_divExp!?(e1: List, e2: List): Boolean;
   begin scalar brk;
      % We deliberately also check the total degree.
      while not brk and e1 do
         brk := pop e1 #> pop e2;
      return not brk
   end;

% Checks that at least one of e1[i] or e2[i] is zero for each i
asserted procedure poly_disjExp!?(e1: List, e2: List): Boolean;
   begin scalar ok;
      e1 := cdr e1;
      e2 := cdr e2;
      ok := t;
      while ok and e1 do
         ok := pop e1 #= 0 or pop e2 #= 0;
      return ok
   end;

% Insert the "dg" into the ev in the place of variable v
asserted procedure poly_insertExp(ev: List, v: Any, dg: Integer, vars: List): List;
   (car ev #+ dg) . poly_insertExp1(cdr ev, v, dg, vars);

asserted procedure poly_insertExp1(ev: List, v: Any, dg: Integer, vars: List): List;
   if null ev or null vars then
      nil
   else if car vars eq v then
      dg . cdr ev
   else
      car ev . poly_insertExp1(cdr ev, v, dg, cdr vars);

asserted inline procedure poly_2aExp(e);
   % Returns list of prefix equivalents of exponent vector e.
   ev_2aExp1(cdr e,  cdr global!-dipvars!*);

procedure ev_2aExp1(u,v);
   if null u then
      nil
   else if car u #= 0 then
      ev_2aExp1(cdr u,cdr v)
   else if car u #= 1 then
      car v . ev_2aExp1(cdr u,cdr v)
   else
      {'expt,car v,car u} . ev_2aExp1(cdr u,cdr v);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Comparators for exponent lists.
% We mainly fall back to functions from dipoly package here

% Compares exponent lists e1, e2 w.r.t. lex term order,
% and returns e1 < e2
asserted procedure poly_cmpExpLex(e1: List, e2: List): Boolean;
   <<
      e1 := cdr e1;
      e2 := cdr e2;
      while e1 and (car e1 #= car e2) do <<
         e1 := cdr e1;
         e2 := cdr e2
      >>;
      e1 and (car e1 #< car e2)
   >>;

% Compares exponent lists e1, e2 w.r.t. graded lex term order,
% and returns e1 < e2
asserted inline procedure poly_cmpExpGradLex(e1: List, e2: List): Boolean;
   (car e1 #< car e2) or (car e1 #= car e2 and poly_cmpExpLex(e1, e2));

% Compares exponent lists e1, e2 w.r.t. graded reversed lex term order,
% and returns e1 < e2
asserted inline procedure poly_cmpExpRevGradLex(e1: List, e2: List): Boolean;
   (car e1 #< car e2) or (car e1 #= car e2 and evinvlexcomp(cdr e1, cdr e2) #= -1);

% Compares exponent lists e1, e2 w.r.t. the current order in torder
asserted inline procedure poly_cmpExpGeneric(e1: List, e2: List): Boolean;
   evcomp(cdr e1, cdr e2) = -1;

% Compares exponent lists e1, e2 w.r.t. the current term order
asserted procedure poly_cmpExp(e1: List, e2: List): Boolean;
   <<
   if vdpsortmode!* eq 'lex then
      poly_cmpExpLex(e1, e2)
   else if vdpsortmode!* eq 'gradlex then
      poly_cmpExpGradLex(e1, e2)
   else if vdpsortmode!* eq 'revgradlex then
      poly_cmpExpRevGradLex(e1, e2)
   else  % Trouble with vdpmatrix!*
      poly_cmpExpGeneric(e1, e2)
   >>;

% Compares exponent lists w.r.t. the total degree
asserted inline procedure poly_tdegCmpExp(e1: List, e2: List): Boolean;
   car e1 #< car e2;

% Checks that e1 = e2 elementwise
asserted inline procedure poly_eqExp!?(e1: List, e2: List): Boolean;
   e1 = e2;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%% TERMS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A Term is a polynomial term, which is implemented as an exponent list.

% Returns the identity Term (just one).
asserted inline procedure poly_identityTerm(): Term;
   poly_zeroExp();

asserted inline procedure poly_isIdentityTerm!?(tm: Term): Boolean;
   poly_totalDegTerm(tm) #= 0;

% Returns the total degree of the Term
asserted inline procedure poly_totalDegTerm(a: Term): Integer;
   poly_totalDegExp(a);

% Returns a * b
asserted inline procedure poly_mulTerm(a: Term, b: Term): Term;
   poly_sumExp(a, b);

% Returns a / b,
% Assuming a >= b.
asserted inline procedure poly_divTerm(a: Term, b: Term): Term;
   poly_subExp(a, b);

% Checks that a | b
asserted inline procedure poly_dividesTerm!?(a: Term, b: Term): Boolean;
   poly_divExp!?(a, b);

% Returns lcm(a, b)
asserted inline procedure poly_lcmTerm(a: Term, b: Term): Term;
   poly_elmaxExp(a, b);

% Returns a < b in the current term order term order
asserted inline procedure poly_cmpTerm(a: Term, b: Term): Boolean;
   poly_cmpExp(a, b);

% Checks if gcd(a, b) is one
asserted inline procedure poly_disjTerm!?(a: Term, b: Term): Boolean;
   poly_disjExp!?(a, b);

% Checks if a = b
asserted inline procedure poly_eqTerm!?(a: Term, b: Term): Boolean;
   poly_eqExp!?(a, b);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%% POLYNOMIALS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Returns the tail of the polynomial `poly`.
% That is, `poly - lead(poly)`,
% and preserves the sugar degree.
asserted inline procedure poly_tail(poly: Polynomial): Polynomial;
   poly_PolynomialWithSugar(poly_tailTerms(poly), poly_tailCoeffs(poly), poly_getSugar(poly));

% Returns the leading term of `poly`
asserted inline procedure poly_leadTerm(poly: Polynomial): Term;
   car poly_getTerms(poly);

% Returns the leading coefficient of `poly`
asserted inline procedure poly_leadCoeff(poly: Polynomial): Coeff;
   car poly_getCoeffs(poly);

% Returns the tail terms of `poly`
asserted inline procedure poly_tailTerms(poly: Polynomial): Terms;
   cdr poly_getTerms(poly);

% Returns the tail coefficients of `poly`
asserted inline procedure poly_tailCoeffs(poly: Polynomial): Coeffs;
   cdr poly_getCoeffs(poly);

% Returns the length of `poly`, i.e., the number of terms
asserted inline procedure poly_length(poly: Polynomial): Integer;
   length(poly_getTerms(poly));

% Returns true if the polynomial is constant
asserted inline procedure poly_isConst!?(poly: Polynomial): Boolean;
   poly_iszero!?(poly) or poly_eqExp!?(poly_leadTerm(poly), poly_zeroExp());

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% ADAPTIVE COEFFICIENT ARITHMETIC %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

asserted inline procedure poly_iszeroCoeff!?(a: Coeff): Boolean;
   not numr(a);

asserted inline procedure poly_isoneCoeff!?(a: Coeff): Boolean;
   eqn(numr(a), 1) and eqn(denr(a), 1);

asserted inline procedure poly_zeroCoeff(): Coeff;
   poly_2Coeff(0);

asserted inline procedure poly_oneCoeff(): Coeff;
   poly_2Coeff(1);

asserted inline procedure poly_2Coeff(c: Any): Coeff;
   if sqp c then
      c
   else
      c ./ 1;

asserted inline procedure poly_2aCoeff(c: Coeff);
   prepsq c;

asserted inline procedure poly_addCoeff(a: Coeff, b: Coeff): Coeff;
   addsq(a, b);

asserted inline procedure poly_subCoeff(a: Coeff, b: Coeff): Coeff;
   subtrsq(a, b);

asserted inline procedure poly_mulCoeff(a: Coeff, b: Coeff): Coeff;
   multsq(a, b);

asserted inline procedure poly_negCoeff(a: Coeff): Coeff;
   negsq(a);

asserted inline procedure poly_isNegCoeff!?(a: Coeff): Boolean;
   minusf numr a;

asserted inline procedure poly_divCoeff(a: Coeff, b: Coeff): Coeff;
   quotsq(a, b);

asserted inline procedure poly_invCoeff(a: Coeff): Coeff;
   <<
      % ASSERT(not null numr a);
      denr(a) ./ numr(a)
   >>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% POLYNOMIAL LOW LEVEL OPERATIONS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Returns s = fmult*f - fcoeff*gmult*g
%
% !! Assuming the leading terms of `fmult*f` and `fcoeff*gmult*g`
%    mutually cancel each other
asserted inline procedure poly_paircombTail(f: Polynomial, fmult: Term, fcoeff: Coeff, 
                                             g: Polynomial, gmult: Term, gcoeff: Coeff): Polynomial;
   % Assuming the leading monomials of `fmult*f` and `fcoeff*gmult*g`
   % are mutually canceled, we can use the general reduction applied to
   % the tails of input polynomials
   poly_paircomb(poly_tail(f), fmult, fcoeff, poly_tail(g), gmult, gcoeff);

% Returns s = gcoeff*fmult*f - fcoeff*gmult*g
asserted procedure poly_paircomb(f: Polynomial, fmult: Term, fcoeff: Coeff, 
                                 g: Polynomial, gmult: Term, gcoeff: Coeff): Polynomial;
   begin scalar fterms, fcoeffs, gterms, gcoeffs, gmultcoeff, isOneFmult,
                sterms, scoeffs, ft, gt, fc, gc, newc, sugar, isOneGmult,
                isOneFmultCf, isOneGmultCf, fmultcoeff;
      % We return s, a new polynomial,
      % constructed as s = fmultcoeff*fmult*f - gmultcoeff*gmult*g.
      % We form two lists, sterms and scoeffs, which would be the list of
      % terms and the list of coefficients of s.
      % The sterms list is formed by merging two sorted lists:
      % the list of terms of f each multiplied by fmult,
      % with the list of terms of g each multiplied by gmult.
      % In parallel (in the same loop), scoeffs list is formed
      % by merging the list of coefficients of f each multiplied by fmultcoeff,
      % with the list of coefficients of g each multiplied by gmultcoeff,
      % in the same merge order as for the terms.
      fterms  := poly_getTerms(f); fcoeffs := poly_getCoeffs(f);
      gterms  := poly_getTerms(g); gcoeffs := poly_getCoeffs(g);
      gmultcoeff := fcoeff;
      fmultcoeff := gcoeff;
      % identity check is 1 car and 1 comparison
      isOneFmult := poly_isIdentityTerm!?(fmult);
      isOneGmult := poly_isIdentityTerm!?(gmult);
      % identity check is 1 comparison
      isOneFmultCf := poly_isoneCoeff!?(fmultcoeff);
      isOneGmultCf := poly_isoneCoeff!?(gmultcoeff);
      % Merge two sorted lists: fterms and gterms, multiplied by fmult and gmult, respectively.
      % Merge in the same order two other lists:
      % fcoeffs and gcoeffs, multiplied by gmultcoeff and fmultcoeff, respectively.
      %
      % if n = length(fterms), m = length(gterms), then in the worst case
      %   2(n+m)*E  +    m*E     +     2m*C    +   (n+m)
      % comparison    term mult.    coeff op.     reverse
      %
      % where E is the cost of iterating exponent vector,
      % and C is the cost of one arithmetic operation on coefficients
      while fterms and gterms do <<
         if null ft then <<
            ft := car fterms;
            if not isOneFmult then
               ft := poly_mulTerm(ft, fmult)
         >>;
         if null gt then <<
            gt := car gterms;
            if not isOneGmult then
               gt := poly_mulTerm(gt, gmult)
         >>;
         % Optimization: return -1,0,1 just as C comparator;
         if poly_cmpTerm(gt, ft) then <<   % if term gt < term ft
            push(ft, sterms);
            if isOneFmultCf then
               push(car fcoeffs, scoeffs)
            else
               push(poly_mulCoeff(fmultcoeff, car fcoeffs), scoeffs);
            pop(fterms); pop(fcoeffs);
            ft := nil
         >> else if poly_eqTerm!?(gt, ft) then <<  % if term gt = term ft
            fc := if isOneFmultCf then
               car fcoeffs
            else
               poly_mulCoeff(car fcoeffs, fmultcoeff);
            gc := if isOneGmultCf then
               car gcoeffs
            else
               poly_mulCoeff(car gcoeffs, gmultcoeff);
            newc := poly_subCoeff(fc, gc);
            if not poly_iszeroCoeff!?(newc) then <<
               push(gt, sterms);
               push(newc, scoeffs)
            >>;
            pop(fterms); pop(fcoeffs);
            pop(gterms); pop(gcoeffs);
            gt := nil;
            ft := nil
         >> else <<   % if term gt > term ft
            push(gt, sterms);
            if isOneGmultCf then
               push(poly_negCoeff(car gcoeffs), scoeffs)
            else
               push(poly_negCoeff(poly_mulCoeff(car gcoeffs, gmultcoeff)), scoeffs);
            pop(gterms); pop(gcoeffs);
            gt := nil
         >>
      >>;
      if null gterms and null fterms then <<
         scoeffs := reversip(scoeffs);
         sterms  := reversip(sterms)
      >>;
      % Merge what is left from gterms and gcoeffs
      if not null gterms then <<
         if poly_isIdentityTerm!?(gmult) then
            sterms := nconc(reversip sterms, gterms)
         else <<
            while gterms do
               push(poly_mulTerm(pop(gterms), gmult), sterms);
            sterms := reversip(sterms)
         >>;
         while gcoeffs do
            push(poly_negCoeff(poly_mulCoeff(pop(gcoeffs), gmultcoeff)), scoeffs);
         scoeffs := reversip(scoeffs)
      >>;
      % Merge what is left from fterms and fcoeffs
      if not null fterms then <<
         if isOneFmult then
            sterms := nconc(reversip sterms, fterms)
         else <<
            while fterms do
               push(poly_mulTerm(pop(fterms), fmult), sterms);
            sterms := reversip(sterms)
         >>;
         while fcoeffs do
            push(poly_mulCoeff(pop(fcoeffs), fmultcoeff), scoeffs);
         scoeffs := reversip(scoeffs)
      >>;
      sugar := max(poly_getSugar(f) + poly_totalDegTerm(fmult),
                        poly_getSugar(g) + poly_totalDegTerm(gmult));
      return poly_PolynomialWithSugar(sterms, scoeffs, sugar)
   end;

% for history
procedure copyList(l);
  begin scalar queue, newPair;
    if null l then
      return nil;
    queue := car l . nil;
    queue := queue . queue;
  % car queue points to the end of the queue
  % cdr queue points to the beginning of the queue
    l := cdr l;
    while not null l do <<
      newPair := car l . nil;
      cdar queue := newPair;
      car queue := newPair;
      l := cdr l
    >>;
    return cdr queue
  end;

% Returns poly*c
asserted procedure poly_multCoeffs(poly: Polynomial, cf: Coeff): Polynomial;
   if poly_isoneCoeff!?(cf) then
      poly
   else
      poly_PolynomialWithSugar(
         poly_getTerms(poly), 
         for each c in poly_getCoeffs(poly) collect poly_mulCoeff(c, cf), 
         poly_getSugar(poly)
      );

% Constructs a new polynomial as a copy of `poly` with normalized coefficients.
% If !*f5fractionfree is ON, this will divide all coefficients by the content of `poly`
% (resulting in a polynomial with unit content).
% Otherwise, this will divide all coefficient by the leading coefficient of `poly`.
% (resulting in a monic polynomial).
asserted procedure poly_normalize(poly: Polynomial): Polynomial;
   if !*f5fractionfree then
      if (not !*f5parametric) or (!*f5parametric and !*f5parametricNormalize) then
         poly_normalizeByContentParametric(poly)
      else
         poly_normalizeByContent(poly)
   else
      if (not !*f5parametric) or (!*f5parametric and !*f5parametricNormalize) then
         poly_normalizeByLeadParametric(poly)
      else
         poly_normalizeByLead(poly);

% Constructs a new polynomial as a copy of `poly`
% with coefficients divided by the content of `poly`
asserted procedure poly_normalizeByContent(poly: Polynomial): Polynomial;
   begin scalar newcoeffs, cnt;
      cnt := poly_content(poly);
      % The leading coefficient will be positive after division
      if poly_isNegCoeff!?(poly_leadCoeff(poly)) then
         cnt := poly_negCoeff(cnt);
      newcoeffs := for each cf in poly_getCoeffs(poly)
         collect poly_divCoeff(cf, cnt);
      return poly_PolynomialWithSugar(poly_getTerms(poly), newcoeffs, poly_getSugar(poly))
   end;

% Constructs a new polynomial as a copy of `poly`
% with coefficients divided by the content of `poly`
asserted procedure poly_normalizeByContentParametric(poly: Polynomial): Polynomial;
   begin scalar newcoeffs, cnt;
      cnt := poly_contentParametric(poly);
      if !*f5parametricNormalize then
         param_addAssumptionNormalize(cnt);
      % The leading coefficient will be positive after division
      if poly_isNegCoeff!?(poly_leadCoeff(poly)) then
         cnt := poly_negCoeff(cnt);
      newcoeffs := for each cf in poly_getCoeffs(poly)
         collect poly_divCoeff(cf, cnt);
      return poly_PolynomialWithSugar(poly_getTerms(poly), newcoeffs, poly_getSugar(poly))
   end;

% Constructs a new polynomial as a copy of `poly`
% with coefficients divided by the leading coeff of `poly`
asserted procedure poly_normalizeByLead(poly: Polynomial): Polynomial;
   begin scalar newcoeffs, mult1;
      return if sfto_dcontentf(numr poly_leadCoeff(poly)) = 1 then
         poly
      else <<
         mult1 := sfto_dcontentf(numr poly_leadCoeff(poly)) ./ 1;
         if poly_isNegCoeff!?(poly_leadCoeff(poly)) then
            mult1 := poly_negCoeff(mult1);
         newcoeffs := for each cf in poly_getCoeffs(poly)
            collect poly_divCoeff(cf, mult1);
         poly_PolynomialWithSugar(poly_getTerms(poly), newcoeffs, poly_getSugar(poly))
      >>
   end;

% Constructs a new polynomial as a copy of `poly`
% with coefficients divided by the leading coeff of `poly`
asserted procedure poly_normalizeByLeadParametric(poly: Polynomial): Polynomial;
   begin scalar newcoeffs, mult1;
      return if poly_isoneCoeff!?(poly_leadCoeff(poly)) then
         poly
      else <<
         if !*f5parametricNormalize then
            param_addAssumptionNormalize(poly_leadCoeff(poly));
         mult1 := poly_invCoeff(poly_leadCoeff(poly));
         newcoeffs := for each cf in poly_getCoeffs(poly)
            collect poly_mulCoeff(cf, mult1);
         poly_PolynomialWithSugar(poly_getTerms(poly), newcoeffs, poly_getSugar(poly))
      >>
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% High level functions: Spolynomial computation and reduction

asserted inline procedure poly_sumPoly(f: Polynomial, g: Polynomial): Polynomial;
   if poly_iszero!?(f) then
      g
   else if poly_iszero!?(g) then
      f
   else 
      poly_paircomb(f, poly_identityTerm(), poly_negCoeff(poly_oneCoeff()),
                     g, poly_identityTerm(), poly_oneCoeff());

% Computes S-polynomial of f and g
asserted procedure poly_spoly(f: Polynomial, g: Polynomial): Polynomial;
   begin scalar e1, e2, elcm, mult1, mult2;
      e1 := poly_leadTerm(f);
      e2 := poly_leadTerm(g);
      elcm := poly_lcmTerm(e1, e2);
      mult1 := poly_divTerm(elcm, e2);
      mult2 := poly_divTerm(elcm, e1);
      % using poly_paircombTail since leading terms vanish
      return poly_paircombTail(f, mult2, poly_leadCoeff(f), g, mult1, poly_leadCoeff(g))
   end;

% Tries to top-reduce f using g (reduces only the leading term of f, only once).
% Two cases are possible:
% 1. the leading term of g divides the leading term of f. Then we perform
%    the top-reduction f - u*g for some u and return the t flag
%    and the result of reduction.
% 2. top-reduction is not possible, we return the nil flag and f
asserted procedure poly_tryTopReductionStep(f: Polynomial,
                                              g: Polynomial): DottedPair;
   begin scalar glead, flead, fmult, gmult, updated;
      glead := poly_leadTerm(g);
      flead := poly_leadTerm(f);
      if poly_dividesTerm!?(glead, flead) then <<
         if !*f5parametric then <<
            param_addAssumptionRed(poly_leadCoeff(g))
         >>;
         fmult := poly_identityTerm();
         gmult := poly_divTerm(flead, glead);
         % using poly_paircombTail since leading terms vanish.
         % Optimization: do not pass fmult;
         % Optimization: poly_leadCoeff(g) is always one;
         f := poly_paircombTail(f, fmult, poly_leadCoeff(f), g, gmult, poly_leadCoeff(g));
         updated := t
      >>;
      return updated . f
   end;

% Tries to reduce f with g (only once). Two cases are possible:
% 1. the leading term of g divides some term of f. Then we perform
%    the reduction of that term, and return t flag and the result of reduction.
% 2. reduction is not possible, we return nil flag and f
asserted procedure poly_tryReductionStep(f: Polynomial,
                                          g: Polynomial): DottedPair;
   begin scalar updated, fterms, fcoeffs, glead,
                fcoef, fterm, fmult, gmult;
      fterms  := poly_getTerms(f);
      fcoeffs := poly_getCoeffs(f);
      glead := poly_leadTerm(g);
      while (not updated) and fterms do <<
         fterm := pop(fterms);
         fcoef := pop(fcoeffs);
         if poly_dividesTerm!?(glead, fterm) then <<
            if !*f5parametric then <<
               param_addAssumptionRed(poly_leadCoeff(g))
            >>;
            fmult := poly_identityTerm();
            gmult := poly_divTerm(fterm, glead);
            f := poly_paircomb(f, fmult, fcoef, g, gmult, poly_leadCoeff(g));
            updated := t
         >>
      >>;
      return updated . f
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Additional polynomial coefficient manipulations

% Returns the lcm of denominators of coefficients of `f`
asserted procedure poly_commonDenominator(f: Polynomial): Integer;
   begin scalar fcoeffs, den;
      den := 1;
      fcoeffs := poly_getCoeffs(f);
      while fcoeffs do <<
         den := lcm(den, denr pop(fcoeffs))
      >>;
      return den ./ 1
   end;

% Returns the content of `f`
asserted procedure poly_contentParametric(f: Polynomial): SF;
   begin scalar fcoeffs, cnt;
      cnt := numr poly_leadCoeff(f);
      fcoeffs := poly_tailCoeffs(f);
      while fcoeffs do <<
         cnt := gcdf(cnt, numr pop(fcoeffs))
      >>;
      cnt := cnt ./ 1;
      return if poly_isNegCoeff!?(cnt) then poly_negCoeff(cnt) else cnt
   end;

% Returns the content of `f`
asserted procedure poly_content(f: Polynomial): Integer;
   begin scalar fcoeffs, cnt;
      cnt := sfto_dcontentf(numr poly_leadCoeff(f));
      fcoeffs := poly_tailCoeffs(f);
      while fcoeffs do <<
         cnt := gcdf(cnt, sfto_dcontentf(numr pop(fcoeffs)))
      >>;
      cnt := cnt ./ 1;
      return if poly_isNegCoeff!?(cnt) then poly_negCoeff(cnt) else cnt
   end;

% Constructs a new polynomial in the following way:
%   f * inv(poly_commonDenominator(f))
asserted procedure poly_scaleDenominators(f: Polynomial): Polynomial;
   begin scalar fcoeffs, newcoeffs, den;
      den := poly_commonDenominator(f);
      if !*f5parametric then <<
         if not param_isConstAssumption(den) then <<
            lprim {prepsq den, "assumed to be non-vanishing"};
            param_addAssumptionInput(den)
         >>
      >>;
      fcoeffs := poly_getCoeffs(f);
      while fcoeffs do <<
         push(poly_mulCoeff(den, pop(fcoeffs)), newcoeffs)
      >>;
      return poly_PolynomialWithSugar(poly_getTerms(f), reversip(newcoeffs), poly_getSugar(f))
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Polynomial sorting ad-hoc

% Returns leadTerm(poly1) < leadTerm(poly2)
asserted inline procedure poly_cmpPolyLead(poly1: Polynomial,
                                            poly2: Polynomial): Boolean;
   poly_cmpTerm(poly_leadTerm(poly1), poly_leadTerm(poly2));

% Returns t if
% the total degree of lead term of poly1 < the total degree of lead term poly2,
% Otherwise, if degrees are equal compares terms with the current order,
% Otherwise, nil.
asserted procedure poly_leadTotalDegreeCmp(poly1: Polynomial,
                                            poly2: Polynomial): Boolean;
   begin integer t1, t2;
      t1 := poly_totalDegTerm(poly_leadTerm(poly1));
      t2 := poly_totalDegTerm(poly_leadTerm(poly2));
      return if t1 #= t2 then
         poly_cmpPolyLead(poly1, poly2)
      else
         t1 #< t2
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Auxiliary functions

% Returns xi^n as a Term struct
asserted procedure poly_ithVariable(idx: Integer, deg: Integer): Term;
   deg . for x := 1:length(global!-dipvars!*)-1
         collect if x = idx then deg else 0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

endmodule;  % end of module f5poly

end;  % of file
