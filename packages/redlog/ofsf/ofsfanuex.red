% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2001-2009 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
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

lisp <<
   fluid '(ofsf_anuex_rcsid!* ofsf_anuex_copyright!*);
   ofsf_anuex_rcsid!* :=
      "$Id$";
   ofsf_anuex_copyright!* := "(c) 2001-2009 A. Dolzmann, A. Seidl, T. Sturm"
>>;

module ofsfanuex;
% ANUEX: a package for primitive or hierarchical representation of algebraic
% numbers and expressions in algebraic numbers (algebraic polynomials). The
% features include incremental real root isolation and factorization.

% An algebraic number (Aex) consists of a rational polynomial with a context
% (Ctx). A context binds some of the variables to algebraic numbers (Anu). An
% algebraic number consists of a univariate (one free variable) Aex together
% with a rational interval such that the Aex has exactly one real root in this
% interval.

% Some of the basic algorithms (rem, psrem, gcd) were inspired by book "Groebner
% bases" by Becker, Weispfenning, and Kredel.

% Conventions:
% Functions working with Aex and Anu rely on and ensure that the following
% properties hold:
% 1) Bound variables are "big," w.r.t. ordop in the followin sense: For every
% free variable x and a bound variable y we have (ordop(x, y) and x neq y) = t.
% This implies that in a univariate Aex the free variable is the main variable
% of the rational polynomial.
% 2) If a variable x is bound to an Anu, the main variable of the algebraic
% polynomial defining this algebraic number is x.

fluid '(bigvarpref!* bigvarcount!* smallvarpref!* smallvarcount!*);
bigvarpref!* := 'zzzzz;
bigvarcount!* := 0;
smallvarpref!* := '!_!_x;
smallvarcount!* := 10000;

procedure mksmallid();
   begin scalar w; integer d;
      smallvarcount!* := smallvarcount!* - 1;
      w := explode smallvarcount!*;
      d := length w;
      while d < 5 do <<
	 w := '!0 . w;
	 d := d + 1
      >>;
      return compress append(explode smallvarpref!*, w)
   end;

procedure mkbigid();
   begin scalar w; integer d;
      bigvarcount!* := bigvarcount!* + 1;
      w := explode bigvarcount!*;
      d := length w;
      while d < 5 do <<
	 w := '!0 . w;
	 d := d + 1
      >>;
      return compress append(explode bigvarpref!*, w)
   end;

% Rational functions.

asserted procedure rat_mk(n: Integer, d: Integer): Rational;
   % Rational number make.
   quotsq(simp n, simp d);

asserted procedure rat_numr(q: Rational): SF;
   % Rational number numerator.
   numr q;

asserted procedure rat_numrn(q: Rational): Integer;
   % Rational number numerator, numeric version.
   if null numr q then 0 else numr q;

asserted procedure rat_denr(q: Rational): Integer;
   % Rational number denumerator.
   denr q;

asserted procedure rat_print(q: Rational): Any;
   % Rational number print.
   <<
      prin2 rat_numrn q;
      prin2 "/";
      prin2 rat_denr q;
      nil
   >>;

asserted procedure rat_fromnum(n: Integer): Rational;
   % Rational number from integer number.
   simp n;

asserted procedure rat_neg(q: Rational): Rational;
   % Rational number negation.
   negsq q;

asserted procedure rat_add(p: Rational, q: Rational): Rational;
   % Rational number addition.
   addsq(p, q);

asserted procedure rat_minus(p: Rational, q: Rational): Rational;
   % Rational number minus.
   addsq(p, negsq q);

asserted procedure rat_addl(pl: RationalList): Rational;
   % Rational number addition of a list.
   if null pl then
      rat_0()
   else
      rat_add(car pl, rat_addl cdr pl);

asserted procedure rat_mult(p: Rational, q: Rational): Rational;
   % Rational number multiplication.
   multsq(p, q);

asserted procedure rat_quot(p: Rational, q: Rational): Rational;
   % Rational number quotient.
   quotsq(p, q);

asserted procedure rat_nullp(q: Rational): Boolean;
   % Rational number null predicate.
   null numr q;

asserted procedure rat_sgn(q: Rational): Integer;
   % Rational number sign. [q] is of type RAT.
   sgn rat_numrn q;

asserted procedure rat_0(): Rational;
   % Rational number 0.
   nil ./ 1;

asserted procedure rat_1(): Rational;
   % Rational number 1.
   1 ./ 1;

asserted procedure rat_less(p: Rational, q: Rational): Boolean;
   % Rational number less. Returns [t] iff [p] < [q].
   eqn(rat_sgn(addsq(p, negsq q)), -1);

asserted procedure rat_greater(p: Rational, q: Rational): Boolean;
   % Rational number greater. Returns [t] iff [p] > [q].
   eqn(rat_sgn(addsq(p, negsq q)), 1);

asserted procedure rat_eq(p: Rational, q: Rational): Boolean;
   % Rational number equal. Returns [t] iff [p] = [q].
   eqn(rat_sgn(rat_minus(p, q)), 0);

asserted procedure rat_leq(p: Rational, q: Rational): Boolean;
   % Rational number less equal. Returns [t] iff [p] <= [q].
   rat_sgn(addsq(p, negsq q)) < 1;

asserted procedure rat_min(p: Rational, q: Rational): Rational;
   % Rational number minimum.
   if rat_leq(p, q) then
      p
   else
      q;

asserted procedure rat_max(p: Rational, q: Rational): Rational;
   % Rational number maximum.
   if rat_leq(p, q) then
      q
   else
      p;

asserted procedure rat_mapmax(pl: RationalList): Rational;
   % Rational number maximum of a list. [pl] is a non-empty list.
   if null cdr pl then
      car pl
   else
      rat_max(car pl, rat_mapmax cdr pl);

asserted procedure rat_min4(a: Rational, b: Rational, c: Rational, d: Rational): Rational;
   % Rational number minimum of 4.
   rat_min(rat_min(a, b), rat_min(c, d));

asserted procedure rat_max4(a: Rational, b: Rational, c: Rational, d: Rational): Rational;
   % Rational number maximum of 4.
   rat_max(rat_max(a, b), rat_max(c, d));

asserted procedure rat_abs(p: Rational): Rational;
   % Rational number absolute value.
   absf numr p ./ denr p;

% RatInterval functions.

asserted procedure iv_mk(l: Rational, r: Rational): RatInterval;
   l . r;

asserted procedure iv_mk4(n1: Integer, d1: Integer, n2: Integer, d2: Integer): RatInterval;
   iv_mk(rat_mk(n1, d1), rat_mk(n2, d2));

asserted procedure iv_lb(iv: RatInterval): Rational;
   % Left bound of [iv].
   car iv;

asserted procedure iv_rb(iv: RatInterval): Rational;
   % Right bound of [iv].
   cdr iv;

asserted procedure iv_print(iv: RatInterval): Any;
   % Print interval.
   <<
      prin2 "]";
      rat_print iv_lb iv;
      prin2 ",";
      rat_print iv_rb iv;
      prin2t "[";
      nil
   >>;

asserted procedure iv_neg(iv: RatInterval): RatInterval;
   % Returns $-[i]$, i.e., the interval mirrored at 0.
   iv_mk(negsq iv_rb iv, negsq iv_lb iv);

asserted procedure iv_add(iv1: RatInterval, iv2: RatInterval): RatInterval;
   % Interval addition.
   iv_mk(addsq(iv_lb iv1, iv_lb iv2), addsq(iv_rb iv1, iv_rb iv2));

asserted procedure iv_mapadd(ivl: RatIntervalList): RatInterval;
   % Interval map addition. Recommendation: [ivl] is non-empty
   if null ivl then
      iv_mk(rat_fromnum 0, rat_fromnum 0)
   else
      iv_add(car ivl, iv_mapadd cdr ivl);

asserted procedure iv_mult(iv1: RatInterval, iv2: RatInterval): RatInterval;
   % Interval multiplication.
   iv_mk(rat_min4(rr,rl,lr,ll),rat_max4(rr,rl,lr,ll)) where
      rr = multsq(iv_rb iv1,iv_rb iv2),
      rl = multsq(iv_rb iv1,iv_lb iv2),
      lr = multsq(iv_lb iv1,iv_rb iv2),
      ll = multsq(iv_lb iv1,iv_lb iv2);

asserted procedure iv_med(iv: RatInterval): Rational;
   % Point in the middle of an interval.
   rat_mult(rat_add(iv_lb iv,iv_rb iv),rat_mk(1,2));

asserted procedure iv_tothen(iv: RatInterval, n: Integer): RatInterval;
   % Interval to the n.
   if n=0 then
      iv_mk(rat_mk(1,1),rat_mk(1,1))
   else
      iv_mult(iv,iv_tothen(iv,n-1));

asserted procedure iv_containszero(iv: RatInterval): Boolean;
   % Interval contains zero.
   if rat_leq(iv_lb iv,rat_0()) and rat_leq(rat_0(),iv_rb iv) then
      t
   else
      nil;

asserted procedure iv_comp(iv1: RatInterval, iv2: RatInterval): Integer;
   % Compare intervals. Returns -1, if [iv1] is below [iv2], 1, if [iv2] is
   % above [iv1] and 0, if the intersection of [iv1] and [iv2] is non- empty.
   % [iv1], [iv2] are regarded as open intervals.
   if rat_leq(iv_rb iv1,iv_lb iv2) then
      -1
   else if rat_leq(iv_rb iv2,iv_lb iv1) then
      1
   else 0;

asserted procedure iv_maxabs(iv: RatInterval): Rational;
   % Interval maximal absolute value.
   rat_max(rat_abs iv_lb iv,rat_abs iv_rb iv);

asserted procedure iv_minabs(iv: RatInterval): Rational;
   % Interval minimal absolute value.
   if iv_containszero iv then
      rat_0()
   else
      rat_min(rat_abs iv_lb iv,rat_abs iv_rb iv);

asserted procedure iv_minus(iv1: RatInterval, iv2: RatInterval): RatIntervalList;
   % Returns a list of IV, resulting from subtracting [iv2] from [iv1].
   nconc(
      if rat_less(iv_lb iv1,iv_lb iv2) then
	 {iv_mk(iv_lb iv1,rat_min(iv_lb iv2,iv_rb iv1))},
      if rat_less(iv_rb iv2,iv_rb iv1) then
	 {iv_mk(rat_max(iv_rb iv2,iv_lb iv1),iv_rb iv1)});

asserted procedure iv_minuslist(iv: RatInterval, ivl: RatIntervalList): RatIntervalList;
   % Interval minus list of intervals. [ivl] is a list of distinct
   % intervals.
   if null ivl then
      {iv}
   else
      iv_listminuslist(iv_minus(iv,car ivl),cdr ivl);

asserted procedure iv_listminuslist(ivl1: RatIntervalList, ivl2: RatIntervalList): RatIntervalList;
   % Interval list minus interval list. [ivl1] and [ivl2] are each lists of
   % distinct intervals.
   for each iv1 in ivl1 join
      iv_minuslist(iv1,ivl2);

% TODO: Rename and move these procedures to sfto module.

asserted procedure sfto_dgcd(f: SF, g: SF): Integer;
   begin scalar cf;
      cf := sfto_dcontentf f;
      if eqn(cf, 1) then
	 return cf;
      return sfto_gcdf(cf, sfto_dcontentf g)
   end;

asserted procedure sfto_kexp(x: Kernel, n: Integer): SF;
   % Non-negative power of a variable as a SF.
   <<
      assert(n >= 0);
      if eqn(n, 0) then 1 else (((x .^ n) .* 1) .+ nil)
   >>;

asserted procedure sfto_psrem(f: SF, g: SF, x: Kernel, s: Integer): SF;
   % Pseudo-remainder of [f] and [g]. [f] and [g] contain [x] as the main
   % variable.
   begin scalar lcf, lcg, redg, tmp; integer degf, degg, lcgcd;
      assert(mvar f eq x);
      assert(mvar g eq x);
      lcg := lc g;
      redg := red g;
      degf := ldeg f;
      degg := ldeg g;
      while degf >= degg do <<
	 lcf := sfto_lcx f;
	 lcgcd := sfto_dgcd(lcf, lcg);
	 tmp := multf(quotfx(lcf, lcgcd), sfto_kexp(x, degf - degg));
	 f := addf(multf(quotfx(lcg, lcgcd), red f), negf multf(tmp, redg));
	 if eqn(s, -1) then
	    f := negf f;
	 degf := sfto_vardeg(f, x)
      >>;
      return f
   end;
   % cdr pseudo!-qremf(numr f, numr g, x);

asserted procedure sfto_psquotrem(f: SF, g: SF, x: Kernel): DottedPair;
   % Pseudo-quotient and pseudo-remainder of [f] and [g]. [f] and [g] contain
   % [x] as the main variable. Returns (psquot . psrem).
   begin scalar lcf, lcg, redg, tmp, psquot; integer degf, degg;
      assert(mvar f eq x);
      assert(mvar g eq x);
      lcg := sfto_lcx g;
      redg := red g;
      degf := sfto_vardeg(f, x);
      degg := sfto_vardeg(g, x);
      while degf >= degg do <<
	 lcf := sfto_lcx f;
	 tmp := multf(lcf, sfto_kexp(x, degf - degg));
	 % To ensure that we always multiply with something positive:
	 psquot := addf(multf(psquot, exptf(lcg, 2)), tmp);
	 f := addf(multf(lcg, red f), negf multf(tmp, redg));
	 % To ensure that we always multiply with something positive:
	 f := multf(f, lcg);
	 degf := sfto_vardeg(f, x)
      >>;
      return psquot . f
   end;

% AexCtx functions.

% Contexts are sorted w.r.t. ordop.

asserted procedure ctx_new(): AexCtx;
   {'ctx, nil};

asserted procedure ctx_fromial(ial: Alist): AexCtx;
   {'ctx, sort(ial, function ordopcar)};

asserted procedure ctx_ial(c: AexCtx): Alist;
   cadr c;

asserted procedure ctx_idl(c: AexCtx): List;
   for each ia in ctx_ial c collect
      car ia;

asserted procedure ctx_print(c: AexCtx): Any;
   <<
      prin2t "[";
      for each ia in ctx_ial c do <<
	 prin2 car ia;
	 prin2t "->";
	 anu_print cdr ia
      >>;
      prin2t "]";
      nil
   >>;

asserted procedure ctx_get(c: AexCtx, x: Kernel): ExtraBoolean;
   % Get variable assignment. Returns the algebraic number to which [x] is bound
   % by context [c]. If [x] is not bound by [c], nil is returned.
   begin scalar ial, res;
      ial := ctx_ial c;
      while ial and null res do <<
	 if caar ial eq x then
	    res := cdar ial;
	 ial := cdr ial
      >>;
      return res
   end;

asserted procedure ctx_add(c: AexCtx, ia: DottedPair): AexCtx;
   % Add to context. [ia] is a dotted pair (x . a), where [x] is a Kernel and
   % [a] is an Anu. It is assumed that [x] is not bound by [c].
   begin scalar ial, var, w, prevl;
      assert(not (car ia memq ctx_idl c));
      ial := ctx_ial c;
      var := car ia;
      while ial and ordop(caar ial, var) do <<
	 w := pop ial;
	 prevl := w . prevl
      >>;
      return {'ctx, append(reverse prevl, ia . ial)}
   end;

asserted procedure ctx_remove(c: AexCtx, x: Kernel): AexCtx;
   % Delete assignment to [x].
   {'ctx,
      for each e in ctx_ial c join
      	 if not eqcar(e, x) then {e}};

asserted procedure ctx_filter(varl: List, c: AexCtx): AexCtx;
   % Delete assignments to variables, which do not occur in [varl].
   {'ctx,
      for each e in ctx_ial c join
	 if car e memq varl then {e}};

asserted procedure ctx_union(c1: AexCtx, c2: AexCtx): AexCtx;
   % Union of syntactically compatible contexts. Syntactically/semantically
   % compatible means: For every Kernel [x]: If (x . a1) in [c1] and (x . a2) in
   % [c2] then syntactically/semantically [a1] = [a2]. We assume that [c1] and
   % [c2] are sorted w.r.t. the current kernel order.
   begin scalar ial1, ial2, w;
      ial1 := for each pr in ctx_ial c1 collect car pr . cdr pr;
      ial2 := for each pr in ctx_ial c2 collect car pr . cdr pr;
      w := lto_almerge({ial1, ial2}, function arg1of2);
      return {'ctx, sort(w, function ordopcar)}
   end;

% Aex functions.

% Tags: In a previous version of this modules, aex contained two tags: lcnttag
% and reducedtag. [lcnttag] = t iff the leading coefficient is non-trivial, i.e.
% not zero according to the context. The idea is that this property is preserved
% under multiplication. [reducedtag]: This is another property which is
% preserved under addition.

asserted procedure aex_mk(rp: RatPoly, c: AexCtx): Aex;
   {'aex, rp, c};

asserted procedure aex_fromrat(r: Rational): Aex;
   {'aex, r, ctx_new()};

asserted procedure aex_fromrp(rp: RatPoly): Aex;
   {'aex, rp, ctx_new()};

asserted procedure aex_fromsf(f: SF): Aex;
   {'aex, !*f2q f, ctx_new()};

asserted procedure aex_0(): Aex;
   {'aex, !*f2q nil, ctx_new()};

asserted procedure aex_1(): Aex;
   {'aex, !*f2q 1, ctx_new()};

asserted procedure aex_mklin(x: Kernel, ba: Rational): Aex;
   % Make linear polynomial a*x + b.
   aex_fromsf addf(multf(!*k2f x, denr ba), negf numr ba);

asserted procedure aex_ex(ae: Aex): RatPoly;
   nth(ae, 2);

asserted procedure aex_ctx(ae: Aex): AexCtx;
   nth(ae, 3);

asserted procedure aex_varl(ae: Aex): List;
   % All variables, variables with the smallest kernel order first.
   kernels numr aex_ex ae;

asserted procedure aex_fvarl(ae: Aex): List;
   % Free variables, variables with the smallest kernel order first.
   lto_setminus(aex_varl ae, ctx_idl aex_ctx ae);

asserted procedure aex_bvarl(ae: Aex): List;
   % Bound variables, variable with the smallest kernel order first.
   ctx_idl aex_ctx ae;

asserted procedure aex_bind(ae: Aex, x: Kernel, a: Anu): Aex;
   begin scalar ctx, fvarl, r, nctx, nx, rp;
      ctx := aex_ctx ae;
      if ctx_get(ctx, x) then
	 return ae;
      fvarl := aex_fvarl ae;
      if not (x memq fvarl) then
	 return ae;
      r := anu_ratp a;  % Test whether [a] is rational. If yes, use aex_subrp.
      if r then
	 return aex_subrp(ae, x, r);
      if x eq lto_maxkl fvarl then <<  % [x] is the biggest free variable in [ae]
	 nctx := ctx_add(aex_ctx ae, x . anu_rename(a, x));
	 return aex_mk(aex_ex ae, nctx)
      >>;
      nx := mkbigid();
      nctx := ctx_add(aex_ctx ae, nx . anu_rename(a, nx));
      rp := aex_ex ae;
      return aex_mk(quotsq(!*f2q sfto_renamef(numr rp, x, nx), !*f2q denr rp), nctx)
   end;

asserted procedure aex_unbind(ae: Aex, x: Kernel): Aex;
   % Delete assignment to [x].
   aex_mk(aex_ex ae, ctx_remove(aex_ctx ae, x));

asserted procedure aex_print(ae: Aex): Any;
   <<
      ioto_prin2t ioto_form2str prepsq aex_ex ae;
      if ctx_ial aex_ctx ae then <<
	 prin2t ", where";
	 ctx_print aex_ctx ae
      >>
   >>;

asserted procedure aex_mvartest(ae: Aex, x: Kernel): Boolean;
   sfto_mvartest(numr aex_ex ae, x);

asserted procedure aex_nullp(ae: Aex): Boolean;
   % Null predicate.
   begin scalar tmp;
      % Make the leading coefficient non-trivial, i.e. non-zero.
      tmp := aex_mklcnt ae;
      if aex_fvarl tmp then  % [ae] is a non-constant polynomial.
	 return nil;
      if eqn(aex_sgn tmp, 0) then
	 return t;
      return nil
   end;

asserted procedure aex_simplenullp(ae: Aex): Boolean;
   % Simple but incomplete null-predicate. It is complete, if [ae] is reduced,
   % i.e. leading coefficient of aex_ex is non-zero or aex_ex is zero
   % polynomial.
   null numr aex_ex ae;

asserted procedure aex_simplenumberp(ae: Aex): Boolean;
   null aex_fvarl ae;

asserted procedure aex_simpleratp(ae: Aex): Boolean;
   ((numberp numr q and not eqn(numr q, 0)) or null numr q) where (q = aex_ex ae);

% Aex arithmetic.

asserted procedure aex_mvar(ae: Aex): Kernel;
   <<
      assert(null aex_fvarl ae or eqcar(aex_fvarl ae, sfto_mvarx numr aex_ex ae));
      sfto_mvarx numr aex_ex ae
   >>;

asserted procedure aex_deg(ae: Aex, x: Kernel): Integer;
   sfto_vardeg(numr aex_ex ae, x);

asserted procedure aex_lc(ae: Aex, x: Kernel): Aex;
   begin scalar q, newq;
      if aex_mvartest(ae, x) then <<
      	 q := aex_ex ae;
      	 newq := quotsq(!*f2q sfto_lcx numr q, !*f2q denr q);
	 return aex_mk(newq, ctx_filter(kernels numr newq, aex_ctx ae))
      >>;
      return ae
   end;

asserted procedure aex_red(ae: Aex, x: Kernel): Aex;
   % Reductum of [ae] wrt [x]. Needs not to be minimized.
   begin scalar q, newq;
      if aex_mvartest(ae, x) then <<
      	 q := aex_ex ae;
	 newq := quotsq(!*f2q sfto_redx numr q, !*f2q denr q);
      	 return aex_mk(newq, ctx_filter(kernels numr newq, aex_ctx ae))
      >>;
      return aex_0()
   end;

asserted procedure aex_neg(ae: Aex): Aex;
   % Negate.
   aex_mk(negsq aex_ex ae, aex_ctx ae);

asserted procedure aex_addrat(ae: Aex, r: Rational): Aex;
   % Add rational number.
   aex_mk(addsq(aex_ex ae, r), aex_ctx ae);

asserted procedure aex_add(ae1: Aex, ae2: Aex): Aex;
   % Add, contexts are assumed to be compatible and will be merged.
   begin scalar q;
      q := addsq(aex_ex ae1, aex_ex ae2);
      return aex_mk(q, ctx_filter(kernels numr q, ctx_union(aex_ctx ae1, aex_ctx ae2)))
   end;

asserted procedure aex_minus(ae1: Aex, ae2: Aex): Aex;
   % Minus, contexts are assumed to be compatible and will be merged.
   begin scalar q;
      q := subtrsq(aex_ex ae1, aex_ex ae2);
      return aex_mk(q, ctx_filter(kernels numr q, ctx_union(aex_ctx ae1, aex_ctx ae2)))
   end;

asserted procedure aex_mult(ae1: Aex, ae2: Aex): Aex;
   % Multiplication, contexts are assumed to be compatible and will be merged.
   if aex_simplenullp ae1 or aex_simplenullp ae2 then
      aex_0()
   else
      aex_mk(multsq(aex_ex ae1, aex_ex ae2), ctx_union(aex_ctx ae1, aex_ctx ae2));

asserted procedure aex_multl(ael: AexList): Aex;
   if null ael then
      aex_1()
   else
      aex_mult(car ael, aex_multl cdr ael);

asserted procedure aex_multrat(ae: Aex, r: Rational): Aex;
   % Multiply with rational number.
   aex_mk(multsq(aex_ex ae, r), aex_ctx ae);

asserted procedure aex_power(ae: Aex, n: Integer): Aex;
   % [ae] to the power of [n]. Note that here 0^0 = 1.
   begin scalar q;
      assert(n >= 0);  % Only non-negative powers are supported.
      if eqn(n, 0) then
      	 return aex_1();
      q := aex_ex ae;
      return aex_mk(quotsq(!*f2q exptf(numr q, n), !*f2q exptf(denr q, n)), aex_ctx ae)
   end;

asserted procedure aex_diff(ae: Aex, x: Kernel): Aex;
   % Differentiate.
   begin scalar q;
      q := diffsq(aex_ex ae, x);
      return aex_mk(q, ctx_filter(kernels numr q, aex_ctx ae))
   end;

asserted procedure aex_subrp(ae: Aex, x: Kernel, rp: RatPoly): Aex;
   % Substitute algebraic form in algebraic expression.
   % aex_mk(ratpoly_subrp(aex_ex ae, x, rp), aex_ctx ae);
   begin scalar q, newq;
      q := aex_ex ae;
      newq := quotsq(sfto_qsub1(numr q, {x . rp}), !*f2q denr q);
      return aex_mk(newq, ctx_filter(kernels numr newq, aex_ctx ae))
   end;

asserted procedure aex_subrat(ae: Aex, x: Kernel, r: Rational): Aex;
   % Substitute rational number. Exact version.
   begin scalar q, newq;
      q := aex_ex ae;
      newq := quotsq(sfto_qsubhor(numr q, x, r), !*f2q denr q);
      return aex_mk(newq, ctx_filter(kernels numr newq, aex_ctx ae))
   end;

asserted procedure aex_subrat1(ae: Aex, x: Kernel, r: Rational): Aex;
   % Substitute rational number. Exact up to sign version.
   begin scalar q, newq;
      q := aex_ex ae;
      newq := sfto_qsubhor1(numr q, x, r);
      return aex_mk(newq, ctx_filter(kernels numr newq, aex_ctx ae))
   end;

asserted procedure aex_pp(ae: Aex): Aex;
   % Domain primitive part.
   aex_mk(!*f2q sfto_dprpartksf numr aex_ex ae, aex_ctx ae);

asserted procedure aex_xtothen(x: Kernel, n: Integer): Aex;
   % Exponentiation. [x]^[n]
   aex_mk(!*f2q sfto_kexp(x, n), ctx_new());

asserted procedure aex_mklcnt(ae: Aex): Aex;
   % Make the leading coefficient of a non-constant polynomial non-trivial.
   begin scalar idl;
      % Quick win: [ae] is a Rational or no variables are bound:
      if aex_simpleratp ae or null ctx_idl aex_ctx ae then
      	 return ae;
      idl := aex_fvarl ae;
      if idl then <<  % [ae] is a non-constant algebraic polynomial.
	 assert(car idl eq aex_mvar ae);
      	 if aex_nullp aex_lc(ae, car idl) then
      	    return aex_mklcnt aex_red(ae, car idl);
	 return ae
      >>;
      % Now we know that [ae] is a constant algebraic polynomial.
      if eqn(aex_sgn ae, 0) then
	 return aex_0();
      return ae
   end;

asserted procedure aex_reduce(ae: Aex): Aex;
   begin scalar x, rlc, rred, alpha, tmp;
      if null aex_bvarl ae then
	 return ae;
      % There are bound variables.
      if aex_fvarl ae then <<
      	 x := aex_mvar ae;
	 rlc := aex_reduce aex_lc(ae, x);
	 rred := aex_reduce aex_red(ae, x);
	 return aex_add(aex_mult(rlc, aex_xtothen(x, aex_deg(ae, x))), rred)
      >>;
      % There are no free variables.
      x := aex_mvar ae;
      alpha := ctx_get(aex_ctx ae, x);
      tmp := aex_reduce aex_unbind(ae, x);
      if aex_deg(tmp, x) >= aex_deg(anu_dp alpha, x) then
	 tmp := aex_rem(tmp, anu_dp alpha, x);
      tmp := aex_bind(tmp, x, alpha);
      % Computation self-test:
      assert(aex_nullp aex_minus(ae, tmp));
      return tmp
   end;

% This version has a different recursion pattern.
% asserted procedure aex_reduce(ae: Aex): Aex;
%    begin scalar x, xn, alpha, rl, rred; integer d;
%       if null aex_boundil ae then
% 	 return ae;
%       x := aex_mvar ae;
%       d := aex_deg(ae, x);
%       alpha := ctx_get(aex_ctx ae, x);
%       rlc := aex_reduce aex_lc(ae, x);
%       if aex_simplenullp rlc then
% 	 return aex_reduce aex_red(ae, x);
%       if not alpha or d < anu_dpdeg alpha then <<  % [x] is free
%       	 rred := aex_reduce aex_red(ae, x);
% 	 return aex_add(aex_mult(rlc, aex_xtothen(x, d)), rred)
%       >>;
%       % [x] is bound and x^d can be reduced
%       rxn := aex_rem(aex_mk(!*f2q sfto_kexp(x, d), ctx_fromial {x . alpha}), anu_dp alpha, x);
%       return aex_reduce aex_add(aex_mult(rlc, rxn), aex_red(ae, x))
%    end;

% asserted procedure anu_dpdeg(a: Anu): Integer;
%    ldeg numr aex_ex anu_dp a;

asserted procedure aex_psquotrem(f: Aex, g: Aex, x: Kernel): DottedPair;
   % Aex pseudo quotient and remainder. Returns a pair (psquot . psrem).
   begin scalar ff, gf, psq, psr;
      assert(not aex_simplenullp g);
      if null aex_fvarl g then
   	 return f . aex_0();
      assert(not eqn(aex_sgn aex_lc(f, x), 0));
      assert(not eqn(aex_sgn aex_lc(g, x), 0));
      ff := sfto_dprpartksf numr aex_ex f;
      gf := sfto_dprpartksf numr aex_ex g;
      psq . psr := sfto_psquotrem(ff, gf, x);
      psq := sfto_dprpartksf psq;
      psr := sfto_dprpartksf psr;
      return
	 aex_mklcnt aex_mk(!*f2q psq, ctx_filter(kernels psq, ctx_union(aex_ctx f, aex_ctx g))) .
	 aex_mklcnt aex_mk(!*f2q psr, ctx_filter(kernels psr, ctx_union(aex_ctx f, aex_ctx g)))
   end;

asserted procedure aex_psrem(f: Aex, g: Aex, x: Kernel): Aex;
   % Aex pseudo remainder. Returns a polynomial, which is sign-equivalent with
   % (i.e., has the same sign for any choice of [x] as) the pseudo remainder of
   % [f] and [g]. This procedure is independent from aex_psquotrem.
   begin scalar ff, gf, lcsgn, psr;
      assert(not aex_simplenullp g);
      if null aex_fvarl g then
   	 return aex_0();
      ff := numr aex_ex f;
      gf := numr aex_ex g;
      lcsgn := aex_sgn aex_lc(g, x);
      assert(eqn(lcsgn, 1) or eqn(lcsgn, -1));
      psr := sfto_psrem(ff, gf, x, lcsgn);
      return aex_mklcnt aex_mk(!*f2q psr, ctx_filter(kernels psr, ctx_union(aex_ctx f, aex_ctx g)))
   end;

asserted procedure aex_psremseq(f: Aex, g: Aex, x: Kernel): AexList;
   % Pseudo remainder sequence for polynomials f and g. Returns a sequence,
   % which is sign-equivalent with the pseudo remainder sequence for polynomials
   % f and g.
   begin scalar rem, res;
      assert(not aex_simplenullp g);
      f := aex_divposcnt(aex_mklcnt f, x);
      g := aex_divposcnt(aex_mklcnt g, x);
      res := {g, f};
      while aex_deg(g, x) > 0 do <<
	 rem := aex_psrem(f, g, x);
	 f := g;
	 g := aex_neg rem;
	 if not aex_simplenullp g then <<
	    g := aex_divposcnt(g, x);
	    res := g . res
	 >>
      >>;
      return reversip res
   end;

asserted procedure aex_divposcnt(ae: Aex, x: Kernel): Aex;
   % Divide positive content. [ae] is a univariate Aex in variable [x] with
   % non-trivial leading coefficient. Returns an Aex, which is sign-equivalent
   % to [ae].
   begin scalar f, ct, q, res; integer sgn;
      f := numr aex_ex ae;
      ct := sfto_ucontentf f;
      q := quotfx(f, ct);
      sgn := aex_sgn aex_mk(!*f2q ct, ctx_filter(kernels ct, aex_ctx ae));
      assert(eqn(sgn, 1) or eqn(sgn, -1));
      res := aex_mk(!*f2q q, ctx_filter(kernels q, aex_ctx ae));
      if eqn(sgn, 1) then
	 return res;
      return aex_neg res
   end;

asserted procedure aex_stdsturmchain(f: Aex, x: Kernel): AexList;
   % Standard Sturm chain. Pseudo remainder is used to construct the chain.
   <<
      assert(aex_mvar f eq x);
      aex_sturmchain(f, aex_diff(f, x), x)
   >>;

asserted procedure aex_sturmchain(f: Aex, g: Aex, x: Kernel): AexList;
   % Sturm chain. Pseudo remainder is used to construct the chain.
   aex_psremseq(f, g, x);

asserted procedure aex_stchsgnch(sc: AexList, x: Kernel, r: GRational): Integer;
   % Sturm chain sign changes. [sc] is a list of univariate Aex in variable [x].
   % [r] is either a rational nubmer or 'infty or 'minfty. Returns the number of
   % sign changes of [sc] evaluated at [r].
   if r eq 'infty then
      lto_sgnchg for each e in sc collect aex_sgnatinfty(e, x)
   else if r eq 'minfty then
      lto_sgnchg for each e in sc collect aex_sgnatminfty(e, x)
   else
      aex_stchsgnch1(sc, x, r);

asserted procedure aex_stchsgnch1(sc: AexList, x: Kernel, r: Rational): Integer;
   lto_sgnchg for each e in sc collect aex_sgn aex_subrat1(e, x, r);

asserted procedure aex_sgnatinfty(ae: Aex, x: Kernel): Integer;
   % Sign at infinity. We assume: 1) [ae] contains at most one free variable
   % [x]. 2) [ae] has non-trivial lc or is simply null.
   begin scalar fvarl;
      if aex_simplenullp ae then
	 return 0;
      fvarl := aex_fvarl ae;
      if null fvarl then
	 return aex_sgn ae;
      assert(car fvarl eq x);
      assert(null cdr fvarl);
      return aex_sgn aex_lc(ae, x)
   end;

asserted procedure aex_sgnatminfty(ae: Aex, x: Kernel): Integer;
   % Sign at minus infinity. We assume: 1) [ae] contains at most one free
   % variable [x]. 2) [ae] has non-trivial lc or is simply null.
   begin scalar fvarl;
      if aex_simplenullp ae then
	 return 0;
      fvarl := aex_fvarl ae;
      if null fvarl then
	 return aex_sgn ae;
      assert(car fvarl eq x);
      assert(null cdr fvarl);
      if evenp aex_deg(ae, x) then
	 return aex_sgn aex_lc(ae, x);
      return (-1)*aex_sgn aex_lc(ae, x)
   end;

asserted procedure aex_sgn(ae: Aex): Integer;
   % Sign of a constant Aex.
   begin scalar con, x, alpha, g, f, sc;
      assert(null aex_fvarl ae);
      if aex_simpleratp ae then  % [ae] is obviously rational.
	 return rat_sgn aex_ex ae;
      if !*rlanuexsgnopt then <<  % possible optimization
      	 con := aex_containment ae;
      	 if rat_less(rat_0(), iv_lb con) then
	    return 1;
      	 if rat_less(iv_rb con, rat_0()) then
	    return (-1)
      >>;
      % [ae] is Aex g(alpha), where alpha is an Anu, which is the root of f in
      % the defining interval.
      x := aex_mvar ae;
      alpha := ctx_get(aex_ctx ae, x);
      g := aex_mklcnt aex_reduce aex_unbind(ae, x);
      if aex_simpleratp g then
	 return rat_sgn aex_ex g;
      if !*rlverbose and !*rlanuexverbose then
	 if aex_deg(g, x) <= 0 then prin2 "[aex_sgn:num!]";
      f := anu_dp alpha;
      % [sc] is the Sturm chain for f(x), f'(x)g(x):
      % Possible optimization: call aex_reduce after aex_diff.
      sc := aex_sturmchain(f, aex_mult(aex_diff(f, x), g), x);
      return aex_stchsgnch1(sc, x, iv_lb anu_iv alpha)
	 - aex_stchsgnch1(sc, x, iv_rb anu_iv alpha)
   end;

asserted procedure aex_evalop(ae: Aex, op: Id): Boolean;
   % Evaluate operator. [ae] is a constant Aex; [op] is an ofsf operator.
   % Returns a Boolean.
   begin scalar sgn;
      assert(null aex_fvarl ae);
      sgn := aex_sgn ae;
      if eqn(sgn, 0) then
	 sgn := nil;
      return ofsf_evalatp(op, sgn)
   end;

% Exact arithmetic with multiplicative inverses.

asserted procedure aex_quotrem(f: Aex, g: Aex, x: Kernel): DottedPair;
   % Quotient and remainder. [g] is non-zero with non-zero leading coefficient.
   % Returns a pair (quotient . remainder). It holds that the remainder has a
   % non-zero leading coefficient.
   begin scalar quot, lcg, lcginv, lcf, tmp, redg; integer degf, degg;
      assert(not aex_simplenullp g);
      if null aex_fvarl g then
	 return aex_mult(aex_inv g, f) . aex_0();
      assert(not eqn(aex_sgn aex_lc(f, x), 0));
      assert(not eqn(aex_sgn aex_lc(g, x), 0));
      quot := aex_0();
      degf := aex_deg(f, x);
      degg := aex_deg(g, x);
      lcg := aex_lc(g, x);
      lcginv := aex_inv lcg;
      redg := aex_red(g, x);
      while degf >= degg do <<
	 lcf := aex_lc(f, x);
	 % aex_reduce added for optimization:
	 tmp := aex_reduce aex_mult(aex_mult(lcf, lcginv), aex_xtothen(x, degf - degg));
	 % Why seg violation when aex_reduce here?
	 f := aex_mklcnt aex_minus(aex_red(f, x), aex_mult(tmp, redg));
	 quot := aex_add(quot, tmp);
	 degf := aex_deg(f, x)
      >>;
      return quot . f
   end;

asserted procedure aex_quot(f: Aex, g: Aex, x: Kernel): Aex;
   % Quotient.
   car aex_quotrem(f, g, x);

asserted procedure aex_rem(f: Aex, g: Aex, x: Kernel): Aex;
   % Remainder. Just a modification of aex_quotrem avoiding the computation of
   % quotient.
   begin scalar lcg, lcginv, redg, lcf, tmp; integer degf, degg;
      assert(not aex_simplenullp g);
      if null aex_fvarl g then
   	 return aex_0();
      assert(not eqn(aex_sgn aex_lc(f, x), 0));
      assert(not eqn(aex_sgn aex_lc(g, x), 0));
      degf := aex_deg(f, x);
      degg := aex_deg(g, x);
      lcg := aex_lc(g, x);
      lcginv := aex_inv lcg;
      redg := aex_red(g, x);
      while degf >= degg do <<
   	 lcf := aex_lc(f, x);
	 % aex_reduce added for optimization:
   	 tmp := aex_reduce aex_mult(aex_mult(lcf, lcginv), aex_xtothen(x, degf - degg));
   	 f := aex_mklcnt aex_minus(aex_red(f, x), aex_mult(tmp, redg));
   	 degf := aex_deg(f, x)
      >>;
      return f
   end;

asserted procedure aex_gcd(f: Aex, g: Aex, x: Kernel): Aex;
   % Euclidean algorithm. [g] is non-zero with non-zero leading coefficient.
   begin scalar tmp;
      while not aex_simplenullp g do <<
	 tmp := aex_rem(f, g, x);
	 f := g;
	 g := tmp
      >>;
      assert(not aex_nullp aex_lc(f, x));
      if eqn(aex_deg(f, x), 0) then
	 return aex_1();
      if !*rlanuexgcdnormalize then
	 return aex_mult(f, aex_inv aex_lc(f, x));
      return f
   end;

asserted procedure aex_gcdext(f: Aex, g: Aex, x: Kernel): AexList;
   % Extended Euclidean algorithm. [g] is non-zero with non-zero leading
   % coefficient. Returns a list [{d, u, v}] such that [d] is the gcd of [f] and
   % [g], and d = f*u + g*v.
   begin scalar ff, fg, gf, gg, quot, rem, tff, tfg, lcinv;
      ff := aex_1();
      fg := aex_0();
      gf := aex_0();
      gg := aex_1();
      while not aex_simplenullp g do <<
	 quot . rem := aex_quotrem(f, g, x);
	 f := g;
	 g := rem;
	 tff := ff;
	 tfg := fg;
	 ff := gf;
	 fg := gg;
	 gf := aex_minus(tff, aex_mult(quot, gf));
	 gg := aex_minus(tfg, aex_mult(quot, gg))
      >>;
      assert(not aex_nullp aex_lc(f, x));
      if !*rlanuexgcdnormalize then <<
	 lcinv := aex_inv aex_lc(f, x);
	 f := aex_mult(f, lcinv);
	 ff := aex_mult(ff, lcinv);
	 fg := aex_mult(fg, lcinv)
      >>;
      return {f, ff, fg}
   end;

asserted procedure aex_sqfree(f: Aex, x: Kernel): Aex;
   % Square-free part.
   % TODO: Think about precise specification, i.e.:
   % 1. Do we need [lc f] non-zero?
   % 2. Do we need [f] reduced?
   if aex_deg(f, x) < 2 then
      f
   else
      aex_quot(f, aex_gcd(f, aex_diff(f, x), x), x);

% Old code:
% asserted procedure aex_inv(ae: Aex): Aex;
%    % Invert a constant, non-zero polynomial.
%    begin scalar x, alpha, g, f, d, f1, aa, ss, tt;
%       if aex_simpleratp ae then  % [ae] is obviously a rational number.
% 	 return aex_fromrp quotsq(1 ./ 1, aex_ex ae);
%       % Now we know that [ae] is a constant algebraic polynomial.
%       x . alpha := car ctx_ial aex_ctx ae;  % (x . (anu f iv))
%       g := aex_unbind(ae, x);
%       f := anu_dp alpha;
%       f := aex_sqfree(f, x);  % MK + TS 12/2012
%       d := car aex_gcdext(f, g, x);
%       f1 := aex_quot(f, d, x);
%       % Applying extended euclidean algorithm to f1 and g, gives: aa = ss*f1 + tt*g.
%       {aa, ss, tt} := aex_gcdext(f1, g, x);
%       % [aa] is non-zero rational, but not necessarily 1.
%       if !*rlanuexgcdnormalize then
% 	 return aex_bind(aex_mult(aa, tt), x, alpha);
%       return aex_bind(aex_mult(aex_inv aa, tt), x, alpha)
%    end;

asserted procedure aex_inv(ae: Aex): Aex;
   % Invert a constant, non-zero polynomial.
   begin scalar x, alpha, g, f, d, u, v;
      if aex_simpleratp ae then
	 return aex_fromrp quotsq(1 ./ 1, aex_ex ae);
      x := aex_mvar ae;
      alpha := ctx_get(aex_ctx ae, x);
      g := aex_unbind(ae, x);
      f := anu_dp alpha;
      {d, u, v} := aex_gcdext(f, g, x);
      if aex_simpleratp d then <<
      	 return aex_bind(aex_mult(aex_inv d, v), x, alpha)
      >>;
      f := aex_quot(f, d, x);
      {d, u, v} := aex_gcdext(f, g, x);
      % [d] represents a rational number. This does NOT imply that
      % [aex_simpleratp d] holds.
      if !*rlanuexgcdnormalize then
	 return aex_bind(aex_mult(aex_inv d, v), x, alpha);
      return aex_bind(aex_mult(d, v), x, alpha)
   end;

% Root isolation.

asserted procedure aex_coefl(ae: Aex, x: Kernel): AexList;
   if aex_mvartest(ae, x) then
      aex_lc(ae, x) . aex_coefl(aex_red(ae, x), x)
   else
      {ae};

asserted procedure aex_coefdegl(ae: Aex, x: Kernel): List;
   % Coefficients and degree list. [ae] is Aex in x.
   if aex_mvartest(ae, x) then
      (aex_lc(ae, x) . aex_deg(ae, x)) . aex_coefdegl(aex_red(ae, x), x)
   else
      {ae . 0};

asserted procedure aex_fromcoefdegl(cfdgl: AexList, x: Kernel): Aex;
   begin scalar ae;
      ae := aex_0();
      for each cd in cfdgl do
	 ae := aex_add(ae, aex_mult(car cd, aex_xtothen(x, cdr cd)));
      return ae
   end;

asserted procedure aex_containment(ae: Aex): RatInterval;
   % Algebraic expression containment. [ae] is a constant Aex. Returns an
   % interval. The algebraic number represented by [ae] is contained in the
   % returned interval regarded as closed.
   begin scalar r, x, alpha, ivalpha, cfdgl, ivl;
      assert(not aex_badp(ae, 0));
      assert(null aex_fvarl ae);
      if null aex_bvarl ae then <<
	 r := aex_ex ae;
	 return iv_mk(r, r)
      >>;
      % Now there is a bound variable.
      x := aex_mvar ae;
      alpha := ctx_get(aex_ctx ae, x);
      ivalpha := anu_iv alpha;
      cfdgl := aex_coefdegl(aex_unbind(ae, x), x);
      ivl := for each c in cfdgl collect
	 iv_mult(aex_containment car c, iv_tothen(ivalpha, cdr c));
      return iv_mapadd ivl
   end;

asserted procedure aex_distinguishpositivefromzero(ae: Aex, iv: RatInterval): Rational;
   % Algebraic expression distinguish positive from zero. [ae] is a positive
   % constant Aex, [iv] is an interval containing the positive algebraic number
   % represented by [ae]. Returns a Rational, which lies in open interval (0,
   % ae).
   begin scalar half, rb;
      half := rat_mk(1, 2);
      rb := rat_mult(iv_rb iv, half);
      while not eqn(aex_sgn aex_addrat(ae, rat_neg rb), 1) do
	 rb := rat_mult(rb, half);
      return rb
   end;

asserted procedure aex_distinguishfromzero(ae: Aex, iv: RatInterval): Rational;
   % Algebraic expression distinguish from zero. [ae] is a constant Aex, [iv] an
   % interval containing the algebraic number represented by [ae]. Returns a
   % Rational which lies in $(0, ae)$ or $(ae, 0)$, respectively.
   begin scalar sgnae;
      sgnae := aex_sgn ae;
      if eqn(sgnae, 0) then
	 return rat_0();
      if eqn(sgnae, 1) then
	 return aex_distinguishpositivefromzero(ae, iv);
      return rat_neg aex_distinguishpositivefromzero(aex_neg ae, iv_neg iv)
   end;

asserted procedure aex_cauchybound(ae: Aex, x: Kernel): Rational;
   % Algebraic expression Cauchy bound. [ae] is a univariate Aex in [x] with
   % non-zero leading coefficient. Returns a positive Rational [cb] such that
   % all roots of [ae] lie in open interval (-cb, cb).
   begin scalar cfl, lcae, lcaeiv, lcest, cfestl, tmp, cb1, cb2;
      assert(not aex_badp(ae, 1));
      assert(not aex_simplenullp aex_lc(ae, x));
      if aex_deg(ae, x) < 1 then
	 return rat_1();
      cfl := aex_coefl(ae, x);
      lcae := car cfl;
      lcaeiv := aex_containment lcae;
      if iv_containszero lcaeiv then
   	 lcest := rat_abs aex_distinguishfromzero(lcae, lcaeiv)
      else
	 lcest :=  iv_minabs lcaeiv;
      cfestl := for each c in cdr cfl collect
	 iv_maxabs aex_containment c;
      cb1 := rat_0();
      cb2 := rat_0();
      for each cfest in cfestl do <<
	 tmp := rat_quot(cfest, lcest);
	 cb1 := rat_add(cb1, tmp);
	 cb2 := rat_max(cb2, tmp)
      >>;
      cb1 := rat_max(rat_1(), cb1);
      cb2 := rat_add(rat_1(), cb2);
      return rat_add(rat_1(), rat_min(cb1, cb2))
   end;

asserted procedure aex_findrootsoflist(ael: AexList, x: Kernel): AnuList;
   aex_findroots(aex_multl ael, x);

asserted procedure aex_findroots(ae: Aex, x: Kernel): AnuList;
   % Aex find roots. [ae] is a univariate Aex. If [ae]'s ldeg is not positive,
   % the empty list will be returned.
   begin scalar cb, rootlist;
      if aex_deg(ae,x) < 1 then
	 return nil;
      cb := aex_cauchybound(ae, x);
      rootlist := aex_findrootsiniv1(ae, x, iv_mk(rat_neg cb, cb),
	 aex_stdsturmchain(ae, x));
      return rootlist
   end;

asserted procedure aex_findrootsiniv(ae: Aex, x: Kernel, iv: RatInterval): AnuList;
   % Aex find roots in interval. [ae] is a univariate Aex with positive ldeg,
   % [ae] represents a non-constant polynomial. Returns an ordered list of Anu.
   aex_findrootsiniv1(ae, x, iv, aex_stdsturmchain(ae, x));

asserted procedure aex_findrootsiniv1(ae: Aex, x: Kernel, iv: RatInterval, sc: AexList): AnuList;
   % Aex find roots in interval. [ae] is a univariate Aex with positive ldeg,
   % [sc] is [ae]'s Sturm chain. Returns an ordered list of Anu: all roots of
   % [ae] in open interval [iv].
   begin scalar lb, rb, sclb, scrb, m, ml, mr, r, retl;
      lb := iv_lb iv;
      rb := iv_rb iv;
      sclb := aex_stchsgnch1(sc, x, lb);
      if eqn(sclb, 0) then
	 return nil;
      scrb := aex_stchsgnch1(sc, x, rb);
      if eqn(sclb - scrb, 0) then
	 return nil;
      if eqn(sclb - scrb, 1) then
	 return {anu_mk(ae, iv)};
      m := rat_mult(rat_add(lb, rb), rat_mk(1, 2));
      ml := mr := m;
      if aex_atratnullp(ae, x, m) then <<
	 r := aex_isoratroot(ae, m, rat_mult(rat_minus(rb, lb), rat_mk(1, 4)), sc, x);
	 ml := rat_minus(m, r);
	 mr := rat_add(m, r)
      >>;
      retl := aex_findrootsiniv1(ae, x, iv_mk(mr, rb), sc);
      if not rat_eq(ml, mr) then
	 retl := anu_mk(ae, iv_mk(ml, mr)) . retl;
      retl := append(aex_findrootsiniv1(ae, x, iv_mk(lb, ml), sc), retl);
      return retl
   end;

asserted procedure aex_isoratroot(ae: Aex, m: Rational, r: Rational, sc: AexList, x: Kernel): Rational;
   % Aex isolate rational root. [m] is a rational root of univariate Aex [ae] of
   % positive degree, [sc] is [ae]'s Sturm chain, [r] is positive rational
   % number. Returns a Rational [s] such that [ae] has exactly one root in the
   % open interval $(m-s, m+s)$ and it holds that 0 < s <= r.
   begin scalar mmr, mpr;
      mmr := rat_minus(m, r);
      mpr := rat_add(m, r);
      while
	 aex_atratnullp(ae, x, mmr) or
      	 aex_atratnullp(ae, x, mpr) or
	 not eqn(aex_stchsgnch1(sc, x, mmr) - aex_stchsgnch1(sc, x, mpr), 1) do <<
	    r := rat_mult(r, rat_mk(1, 2));
      	    mmr := rat_minus(m, r);
      	    mpr := rat_add(m, r)
	 >>;
      return r
   end;

asserted procedure aex_atratnullp(ae: Aex, x: Kernel, r: Rational): Boolean;
   % Zero at rational point predicate.
   eqn(aex_sgn aex_subrat1(ae, x, r), 0);

asserted procedure aex_deltastchsgnch(sc: AexList, x: Kernel, iv: RatInterval): Integer;
   % delta Sturm chain sign changes in an interval
   begin integer sclb, scrb;
      sclb := aex_stchsgnch1(sc, x, iv_lb iv);
      if eqn(sclb, 0) then
	 return 0;
      scrb := aex_stchsgnch1(sc, x, iv_rb iv);
      return sclb - scrb
   end;

% Incremental root isolation submodule.

% The Iri data structure consists of the following:
% 1) a list of Irp, i.e., incremental root isolation polynomials
% 2) a list of intervals with rational endpoints, regarded as closed, such that
% no polynomial from 1) has a root in these intervals
% 3) a list of already isolated roots
% 4) the current polynomial (of type Irp) whose roots will be isolated next
% 5) a list of intervals with rational endpoints, regarded as open, such that
% all real roots of the polynomial from 4) lie exclusively in these intervals

% The Irp data structure representing a single polynomial consists of the
% following:
% 1) square-free univariate Aex
% 2) root isolation data, which is precomputed during the initialization of an
% Irp instance; At present this is the standard Sturm chain.
% 3) a tag of an unspecified type

% The Iri data structure has to be initialized with a list of univariate,
% coprime, and square-free Irp. If {f1, ..., fn} is the input, then semantically
% roots of f1*...*fn will be isolated.

% The most important function is iri_nextroot, which isolates the next real
% root, and returns a tagged Anu [anu . tag] such that the [anu] is a root of
% polynomial with tag [tag]. Furthermore, iri_nextroot returns nil if all roots
% of all polynomials were already isolated. The data structure is changed
% in-place by iri_nextroot and other functions.

struct Irp asserted by list3p;
struct IrpList asserted by listp;

asserted procedure irp_aex(p: Irp): Aex;
   nth(p, 1);

asserted procedure irp_idata(p: Irp): Any;
   nth(p, 2);

asserted procedure irp_tag(p: Irp): Any;
   nth(p, 3);

asserted procedure irp_mk(a: Aex, d: Any, tag: Any): Irp;
   {a, d, tag};

asserted procedure iri_irpl(ir: Iri): IrpList;
   nth(ir, 2);

asserted procedure iri_ivl(ir: Iri): RatIntervalList;
   nth(ir, 3);

asserted procedure iri_rootl(ir: Iri): TgAnuList;
   nth(ir, 4);

asserted procedure iri_curirp(ir: Iri): Irp;
   nth(ir, 5);

asserted procedure iri_curivl(ir: Iri): RatIntervalList;
   nth(ir, 6);

asserted procedure iri_popirpl(ir: Iri): Irp;
   pop nth(ir, 2);

asserted procedure iri_pushivl(iv: RatInterval, ir: Iri): Any;
   push(iv, nth(ir, 3));

asserted procedure iri_pushrootl(a: TgAnu, ir: Iri): Any;
   push(a, nth(ir, 4));

asserted procedure iri_pushcurivl(iv: RatInterval, ir: Iri): Any;
   push(iv, nth(ir, 6));

asserted procedure iri_popcurivl(ir: Iri): RatInterval;
   pop nth(ir, 6);

asserted procedure iri_setcurirp(ir: Iri, p: Irp): Any;
   nth(ir, 5) := p;

asserted procedure iri_setcurivl(ir: Iri, ivl: RatIntervalList): Any;
   nth(ir, 6) := ivl;

asserted procedure iri_mk(pl: IrpList): Iri;
   {'iri, pl, nil, nil, nil, nil};

asserted procedure iri_nextroot(ir: Iri): ExtraBoolean;
   % Returns either nil or TgAnu.
   begin scalar rootfound;
      while not rootfound and iri_preparecur ir do
      	 rootfound := iri_nextrootiv ir;
      if not rootfound then
	 return nil;
      return car iri_rootl ir
   end;

asserted procedure iri_preparecur(ir: Iri): Boolean;
   begin scalar c, p, curivl;
      if iri_curivl ir and iri_curirp ir then
	 return t;
      while null c and iri_irpl ir do <<
	 p := iri_popirpl ir;
	 curivl := iv_minuslist(irp_rootsiv p, iri_ivl ir);
	 if curivl then
	    c := t
      >>;
      if c then <<
      	 iri_setcurirp(ir, p);
      	 iri_setcurivl(ir, curivl);
      	 return t
      >>;
      return nil
   end;

asserted procedure iri_nextrootiv(ir: Iri): Boolean;
   begin scalar p, ae, iv, numroots, lb, rb, m, r, mpr, mmr;
      assert(iri_curirp ir and iri_curivl ir);
      p := iri_curirp ir;
      iv := iri_popcurivl ir;
      numroots := irp_numroots(p, iv);
      if eqn(numroots, 0) then
	 return nil;
      if eqn(numroots, 1) then <<
	 iri_addroot(ir, p, iv);
	 return t
      >>;
      % There are at least two roots.
      ae := irp_aex p;
      lb := iv_lb iv;
      rb := iv_rb iv;
      m := rat_quot(rat_add(lb, rb), rat_mk(2, 1));
      if eqn(aex_sgn aex_subrat1(ae, aex_mvar ae, m), 0) then <<
	 % ioto_tprin2t "FOUND A RATIONAL ROOT!";
	 r := irp_isoratroot(p, m, rat_minus(iv_rb iv, m));
	 mpr := rat_add(m, r);
	 mmr := rat_minus(m, r);
	 % TODO: Add simple anu, representing a rational number.
	 iri_addroot(ir, p, iv_mk(mmr, mpr));
      	 iri_pushcurivl(iv_mk(mpr, rb), ir);
      	 iri_pushcurivl(iv_mk(lb, mmr), ir);
	 return t
      >>;
      iri_pushcurivl(iv_mk(m, rb), ir);
      iri_pushcurivl(iv_mk(lb, m), ir);
      return nil
   end;

asserted procedure iri_addroot(ir: Iri, p: Irp, iv: RatInterval): Any;
   begin scalar anu;
      anu := irp_refine(p, iv, iri_irpl ir);
      iri_pushivl(anu_iv anu, ir);
      iri_pushrootl(anu . irp_tag p, ir)
   end;

% To use a different root isolation method, only the following procedures need
% to be changed.

asserted procedure iri_init(tael: TgAexList, x: Kernel): Iri;
   begin scalar ae, tag, sc, irpl; integer d;
      while tael do <<
	 ae . tag := pop tael;
      	 assert(x eq aex_mvar ae);
      	 sc := aex_stdsturmchain(ae, x);
      	 d := aex_stchsgnch(sc, x, 'minfty);
      	 % Optimization: Delete all polynomials, which do not have a real root:
      	 if not eqn(d, 0) and  d - aex_stchsgnch(sc, x, 'infty) > 0 then
      	    push(irp_mk(ae, sc, tag), irpl)
      >>;
      return iri_mk reversip irpl
   end;

asserted procedure irp_rootsiv(p: Irp): RatInterval;
   % Returns an interval, regarded as open, such that all roots of [p] lie in
   % this interval.
   begin scalar ae, b;
      ae := irp_aex p;
      b := aex_cauchybound(ae, aex_mvar ae);
      return iv_mk(rat_neg b, b)
   end;

asserted procedure irp_numroots(p: Irp, iv: RatInterval): Integer;
   % Returns the number of real roots of [p] in [iv].
   begin scalar ae, sc, x; integer sclb;
      ae := irp_aex p;
      sc := irp_idata p;
      x := aex_mvar ae;
      sclb := aex_stchsgnch1(sc, x, iv_lb iv);
      if eqn(sclb, 0) then
	 return 0;
      return sclb - aex_stchsgnch1(sc, x, iv_rb iv)
   end;

asserted procedure irp_refine(p: Irp, iv: RatInterval, ppl: IrpList): Anu;
   % We assume that [p] has exactly one root in [iv]. The interval [iv] is
   % refined in such a way that no polynomial from [ppl] has a root in it.
   % Finally, an Anu with [iv] as the bounding interval is returned.
   begin scalar ae, sc, a, x, pp, aepp, scpp;
      ae := irp_aex p;
      sc := irp_idata p;
      a := anu_mk(ae, iv);
      x := aex_mvar ae;
      while ppl do <<
	 pp := pop ppl;
	 aepp := irp_aex pp;
	 scpp := irp_idata pp;
      	 while
	    aex_deltastchsgnch(scpp, x, anu_iv a) > 0 or
	    aex_atratnullp(aepp, x, iv_lb anu_iv a) or
	    aex_atratnullp(aepp, x, iv_rb anu_iv a) do
	       anu_refineip(a, sc)
      >>;
      return a
   end;

asserted procedure irp_isoratroot(p: Irp, m: Rational, r: Rational): Rational;
   begin scalar ae, sc, x, mmr, mpr;
      ae := irp_aex p;
      sc := irp_idata p;
      x := aex_mvar ae;
      r := rat_mult(r, rat_mk(1, 2));
      mmr := rat_minus(m, r);
      mpr := rat_add(m, r);
      while
	 aex_atratnullp(ae, x, mmr) or
      	 aex_atratnullp(ae, x, mpr) or
	 not eqn(aex_stchsgnch1(sc, x, mmr) - aex_stchsgnch1(sc, x, mpr), 1) do <<
	    r := rat_mult(r, rat_mk(1, 2));
      	    mmr := rat_minus(m, r);
      	    mpr := rat_add(m, r)
	 >>;
      return r
   end;

% Anu functions.

asserted procedure anu_mk(ae: Aex, iv: RatInterval): Anu;
   {'anu, ae, iv};

asserted procedure anu_dp(a: Anu): Aex;
   cadr a;

asserted procedure anu_iv(a: Anu): RatInterval;
   caddr a;

asserted procedure anu_fromrat(x: Kernel, r: Rational): Anu;
   anu_mk(aex_mklin(x, r), iv_mk(r, r));

asserted procedure anu_putiv(a: Anu, iv: RatInterval): Any;
   % Algebraic number put interval. Changes the isolating interval in a
   % nonconstructive way. The returned value is not of interest.
   caddr a := iv;

asserted procedure anu_print(a: Anu): Any;
   <<
      prin2t "(";
      aex_print anu_dp a;
      prin2t "root in interval:";
      iv_print anu_iv a;
      prin2t ")";
      nil
   >>;

asserted procedure anu_ratp(a: Anu): ExtraBoolean;
   % A very limited rationality test. If [a] is a root of a linear polynomial
   % with integer coefficients, the root is returned. Otherwise, [nil] is
   % returned.
   begin scalar aex, fvarl, x, f;
      aex := anu_dp a;
      if aex_bvarl aex then
	 return nil;
      fvarl := aex_fvarl aex;
      assert(fvarl);
      if cdr fvarl then
	 return nil;
      x := car fvarl;
      if eqn(aex_deg(aex, x), 1) then <<
	 f := numr aex_ex aex;
	 return quotsq(!*f2q negf red f, !*f2q lc f)
      >>;
      return nil
   end;

asserted procedure anu_compare(a1: Anu, a2: Anu): Integer;
   % Compare two Anu. [a1], [a2] are Anu. Returns an integer [z]. We have [z <
   % 0] if [a1 < a2], [z = 0] if [a1 = a2] and [z = 1] if [a1 > a2].
   begin scalar iv1, iv2;
      if a1 = a2 then
	 return 0;
      iv1 := anu_iv a1;
      iv2 := anu_iv a2;
      if rat_leq(iv_rb iv1, iv_lb iv2) then
	 return -1;
      if rat_leq(iv_rb iv2, iv_lb iv1) then
	 return 1;
      return anu_compare1(a1, a2)
   end;

asserted procedure anu_compare1(a1: Anu, a2: Anu): Integer;
   begin scalar v1, v2, ctx;
      v1 := aex_mvar anu_dp a1;
      v2 := aex_mvar anu_dp a2;
      if v1 eq v2 then <<
      	 v2 := mksmallid();
      	 a2 := anu_rename(a2, v2);
      >>;
      ctx := ctx_fromial {v1 . a1, v2. a2};
      return aex_sgn aex_mk(addsq(!*k2q v1, negsq !*k2q v2), ctx)
   end;

asserted procedure anu_refine(a: Anu): Anu;
   % Algebraic number refine. Returns an [a] with smaller isolating interval.
   begin scalar iv, w, aex, sc;
      iv := anu_iv a;
      if iv_lb iv = iv_rb iv then
	 return a;
      w := copy a;
      aex := anu_dp a;
      sc := aex_stdsturmchain(aex, aex_mvar aex);
      anu_refineip(w, sc);
      return w
   end;

asserted procedure anu_refineip(a: Anu, s: AexList): Anu;
   % Algebraic number refine in place. [s] is a Sturm chain. Returns an [a] with
   % smaller isolating interval. Remark: 1000 was replaced by 4.
   begin scalar x, iv, lb, rb, m, scm;
      x := aex_mvar anu_dp a;
      iv := anu_iv a;
      lb := iv_lb iv;
      rb := iv_rb iv;
      m := rat_quot(rat_add(lb, rb), rat_mk(2, 1));
      if eqn(aex_sgn aex_subrat1(anu_dp a, x, m), 0) then <<
	 % TODO: Rational number, construct simpler Anu.
	 anu_putiv(a, iv_mk(
	    rat_minus(m, rat_mult(rat_mk(1,4), rat_minus(m, lb))),
	    rat_add(m, rat_mult(rat_mk(1,4), rat_minus(m, lb)))));
	 return a
      >>;
      scm := aex_stchsgnch1(s, x, m);
      if eqn(aex_stchsgnch1(s, x, lb) - scm, 1) then <<
	 anu_putiv(a, iv_mk(lb, m));
	 return a
      >>;
      anu_putiv(a, iv_mk(m, rb));
      return a
   end;

asserted procedure anu_evalf(a: Anu): Floating;
   % Algebraic number evaluate floating point. Returns a floating point
   % approximation of [a], which is precise up to [anu_precision!*] decimal
   % places.
   begin scalar iv, ra, lb, ub;
      ra := a;
      repeat <<
      	 ra := anu_refine ra;
	 iv := anu_iv ra;
	 lb := float(numr car iv or 0)/float denr car iv;
	 ub := float(numr cdr iv or 0)/float denr cdr iv
      >> until anu_approxEqualEnough(lb, ub);
      return lb
   end;

asserted procedure anu_approxEqualEnough(lb: Floating, ub: Floating): Boolean;
   eqn(fix(lb * 10^anu_precision!*) - fix(ub * 10^anu_precision!*), 0);

asserted procedure anu_rename(a: Anu, xnew: Kernel);
   begin scalar aex, rp, varl, x, varal, rpnew, ialnew, w;
      aex := anu_dp a;
      rp := aex_ex aex;
      varl := kernels numr rp;
      x := car varl;
      if x eq xnew then
	 return a;
      rpnew := quotsq(!*f2q sfto_renamealf(numr rp, {x . xnew}), !*f2q denr rp);
      if ordop(xnew, x) then
	 return anu_mk(aex_mk(rpnew, aex_ctx aex), anu_iv a);
      varal := for each var in cdr varl collect
	 var . mkbigid();
      rpnew := quotsq(!*f2q sfto_renamealf(numr rpnew, {x . xnew}), !*f2q denr rpnew);
      ialnew := for each pr in ctx_ial aex_ctx aex collect <<
	 w := cdr atsoc(car pr, varal);
	 w . anu_rename(cdr pr, w)
      >>;
      return anu_mk(aex_mk(rpnew, ctx_fromial ialnew), anu_iv a)
   end;

asserted procedure anu_check(a: Anu): Boolean;
   % Algebraic number check.
   begin scalar dp, x, l, r, s, valid;
      valid := t;
      dp := anu_dp a;
      x := aex_fvarl dp; % tmp
      if length x neq 1 then
	 prin2t "***** anu_check: def. poly corrupt";
      x := car x; l := iv_lb anu_iv a; r := iv_rb anu_iv a;
      s := aex_stdsturmchain(dp,aex_mvar dp);
      if aex_nullp aex_subrat1(dp,x,l) then <<
	 valid := nil;
      	 prin2t "***** anu_check: def. poly null at left bound";
      >>;
      if aex_nullp aex_subrat1(dp,x,r) then <<
	 valid := nil;
      	 prin2t "***** anu_check: def. poly null at right bound";
      >>;
      if aex_deltastchsgnch(s,x,anu_iv a) neq 1 then <<
	 valid := nil;
      	 prin2t "***** anu_check: no root";
      >>;
      return valid
   end;

asserted procedure aex_badp(aex: Aex, fvn: Integer): ExtraBoolean;
   % [fvn] is the number of expected variables or -1.
   begin scalar varl, ctx, ial, brk, v, anu, bvarl, fvarl, fv, bv, scbvarl;
      if not eqcar(aex, 'aex) then
	 return 1;
      varl := kernels numr aex_ex aex;
      ctx := aex_ctx aex;
      if not eqcar(ctx, 'ctx) then
	 return 2;
      ial := ctx_ial ctx;
      brk := nil; while not brk and ial do <<
	 v . anu := pop ial;
	 % if not (v memq varl) then
	 %    brk := 3;
	 if not brk and ial and (not ordop(v, caar ial) or v eq caar ial) then
	    brk := 4;  % bound variables in the context of [aex] are not sorted w.r.t. ordop
	 if not brk and v neq aex_mvar anu_dp anu then
	    brk := 5;  % variable [v] is not defined by Aex with main variable [v]
	 brk := brk or anu_badp anu
      >>;
      if brk then
	 return brk;
      bvarl := for each pr in ctx_ial aex_ctx aex collect car pr;
      fvarl := lto_setminus(varl, bvarl);
      if not eqn(fvn, -1) and not eqn(length fvarl, fvn) then
	 return 6;  % the number of variables in [aex] is not as expected
      brk := nil; while not brk and fvarl do <<
	 fv := pop fvarl;
	 scbvarl := bvarl;
	 while not brk and scbvarl do <<
	    bv := pop scbvarl;
	    if ordop(bv, fv) and bv neq fv then
	       brk := 7  % bound variable [bv] is smaller than free variable [fv] w.r.t. ordop
	 >>
      >>;
      return brk
   end;

asserted procedure anu_badp(anu: Anu): ExtraBoolean;
   begin scalar aex, iv, lb, rb, w;
      if not eqcar(anu, 'anu) then
	 return 11;
      aex := anu_dp anu;
      iv := anu_iv anu;
      if not pairp iv then
	 return 12;
      lb := iv_lb iv;
      if not pairp lb or not rationalp lb then
	 return 13;
      rb := iv_rb iv;
      if not pairp rb or not rationalp rb then
	 return 14;
      if not sfto_lessq(lb, rb) then
	 return 15;
      w := aex_badp(aex, 1);
      if w then
	 return w + 1000
   end;

endmodule;  % ofsfanuex

end;  % of file
