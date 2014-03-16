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
% ANUEX - a package for primitive or hierarchical representation of algebraic
% numbers and expressions in algebraic numbers (algebraic polynomials). The
% features include incremental real root isolation and factorisation.

% Algebraic number (Aex) consists of a rational polynomial with a context (Ctx).
% Context binds some of the variables to algebraic numbers (Anu). Algebraic
% number consists of a univariate (one free variable) Aex together with rational
% internval such that the Aex has exactly one root in this interval.

% Conventions:
% Functions working with Aex and Anu rely on and ensure that the following hold:
% 1) Bound variables are "big," w.r.t. ordop: For every free variable x and a
% bound variable y ordop(x, y) = t. This imples that in a univariate Aex the
% free variable is the main variable of the rational polynomial.
% 2) If a variable x is bound to an Anu, the main variable of the algebraic
% polynomial defining this number is x.

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

struct Rational checked by RationalP;
struct RationalList checked by RationalListP;
struct GRational checked by GRationalP;
struct RatInterval checked by RatIntervalP;
struct RatIntervalList checked by RatIntervalListP;
struct RatPoly checked by RatPolyP;
struct AexCtx checked by AexCtxP;
struct Aex checked by AexP;
struct AexList checked by AexListP;
struct Anu asserted by AnuP;
struct AnuList asserted by AnuListP;

procedure IntegerListP(s);
   null s or pairp s and fixp car s and IntegerListP cdr s;

procedure RationalP(s);
   sqp s and (null numr s or (fixp numr s and not eqn(numr s, 0))) and
      fixp denr s and denr s > 0;

procedure RationalListP(s);
   null s or pairp s and RationalP car s and RationalListP cdr s;

procedure GRationalP(s);
   RationalP s or s eq 'minfty or s eq 'infty;  % TODO: Change to 'minf, 'pinf.

procedure RatIntervalP(s);
   pairp s and RationalP car s and RationalP cdr s;

procedure RatIntervalListP(s);
   null s or pairp s and RatIntervalP car s and RatIntervalListP cdr s;

procedure RatPolyP(s);
   sqp s and sfpx numr s and not zerop numr s and
      fixp denr s and denr s > 0;

procedure AexCtxP(s);
   pairp s and eqcar(s, 'ctx);

procedure AexP(s);
   pairp s and eqcar(s, 'aex);
   % begin scalar varl, bvaral, c;
   %    if not pairp s then
   % 	 return nil;
   %    if not eqcar(s, 'aex) then
   % 	 return nil;
   %    varl := kernels numr nth(s, 2);
   %    bvaral := cadr nth(s, 3);
   %    c := t; while c and bvaral do <<
   % 	 if not (caar bvaral memq varl) then
   % 	    c := nil;
   % 	 bvaral := cdr bvaral
   %    >>;
   %    return c
   % end;

procedure AexListP(s);
   null s or pairp s and AexP car s and AexListP cdr s;

procedure AnuP(s);
   pairp s and eqcar(s, 'anu);

procedure AnuListP(s);
   null s or pairp s and AnuP car s and AnuListP cdr s;

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

% RatPoly functions.

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

asserted procedure ctx_fromial(ial: AList): AexCtx;
   {'ctx, sort(ial, function(lambda(x, y); ordop(car x, car y)))};

asserted procedure ctx_ial(c: AexCtx): AList;
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
   begin scalar ial, var, prevl;
      assert(not (car ia memq ctx_idl c));
      ial := ctx_ial c;
      var := car ia;
      while ial and ordop(var, caar ial) do <<
	 prevl := car ial . prevl;
	 ial := cdr ial
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
      w := lto_almerge({ial1, ial2}, function(lambda(x, y); x));
      w := sort(w, function(lambda(x, y); ordop(car x, car y)));
      return {'ctx, w}
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
   kernels numr aex_ex ae;

asserted procedure aex_fvarl(ae: Aex): List;
   % Free identifiers, the id with highest kernel order first.
   lto_setminus(aex_varl ae, ctx_idl aex_ctx ae);

asserted procedure aex_bvarl(ae: Aex): List;
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
      if x eq car reversip fvarl then <<  % [x] is the biggest free variable in [ae]
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
   % Aex pseudo remainder. This algorithm is independent from aex_psquotrem.
   begin scalar ff, gf, lcsgn, psr;
      assert(not aex_simplenullp g);
      if null aex_fvarl g then
   	 return aex_0();
      ff := sfto_dprpartksf numr aex_ex f;
      gf := sfto_dprpartksf numr aex_ex g;
      lcsgn := aex_sgn aex_lc(g, x);
      assert(eqn(lcsgn, 1) or eqn(lcsgn, -1));
      psr := sfto_dprpartksf sfto_psrem(ff, gf, x, lcsgn);
      return aex_mklcnt aex_mk(!*f2q psr, ctx_filter(kernels psr, ctx_union(aex_ctx f, aex_ctx g)))
   end;

asserted procedure aex_psremseq(f: Aex, g: Aex, x: Kernel): AexList;
   % Pseudo remainder sequence for polynomials f and g. Returns a pseudo
   % remainder sequence for polynomials f and g.
   begin scalar rem, res;
      assert(not aex_simplenullp g);
      res := {g, f};
      while aex_deg(g, x) > 0 do <<
	 rem := aex_psrem(f, g, x);
	 f := g;
	 g := aex_neg rem;
	 if not aex_simplenullp g then
	    res := g . res
      >>;
      return reversip res
   end;

asserted procedure aex_stdsturmchain(f: Aex, x: Kernel): AexList;
   % Standard sturm chain. Pseudo remainder is used to construct the chain.
   aex_sturmchain(f, aex_diff(f, x), x);

asserted procedure aex_sturmchain(f: Aex, g: Aex, x: Kernel): AexList;
   % Sturm chain. Pseudo remainder is used to construct the chain.
   aex_psremseq(aex_pp f, aex_pp g, x);

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

% Exact arithmetic with multiplicative inverses.

asserted procedure aex_quotrem(f: Aex, g: Aex, x: Kernel): DottedPair;
   % Quotient and remainder. [f] and [g] have to have non-trivial leading
   % coefficient. Returns a pair (quotient . remainder). It holds that the
   % remainder has a non-zero leading coefficient. Reference: Becker,
   % Weispfenning, Kredel - Groebner bases, p. 81.
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
   % Remainder. Just a modification of aex_quotrem avoiding computation of
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

asserted procedure aex_gcd(a: Aex, b: Aex, x: Kernel): Aex;
   begin scalar d;
      % d := car aex_gcdext1(a, b, x, nil);
      d := car aex_gcdext(a, b, x);
      % Optimization: if the gcd is not a poly, then it's 1:
      if aex_deg(d, x) < 1 then
	 d := aex_1();
      % Make sure that the leading coeffcient of d is non-trivial:
      assert(not aex_nullp aex_lc(d, x));
      return d
   end;

asserted procedure aex_gcdext(a: Aex, b: Aex, x: Kernel): AexList;
   % Extended euclidean algorithm. See Becker, Weispfenning, Kredel: Groebner
   % bases, p.83.
   begin scalar aa,bb,ss,tt,uu,vv,qr,ss1,tt1,tmp;
      aa := a; bb := b;
      ss := aex_1(); tt := aex_0();
      uu := aex_0(); vv := aex_1();
      while not aex_simplenullp bb do << %%% simplenullp should suffice
	 qr := aex_quotrem(aa,bb,x);
	 aa := bb; bb := cdr qr; % attention: cadr with psquotrem
	 ss1 := ss; tt1 := tt;
	 ss := uu; tt := vv;
	 uu := aex_minus(ss1,aex_mult(car qr,uu));
	 vv := aex_minus(tt1,aex_mult(car qr,vv));
      >>;
      if !*rlanuexgcdnormalize then <<
	 tmp := aex_inv aex_lc(aa,x); aa := aex_mult(aa,tmp);
	 ss := aex_mult(ss,tmp); tt := aex_mult(tt,tmp);
      >>;
      % Computation self-test (aa = ss*a + tt*b):
      assert(aex_nullp aex_minus(aa,aex_add(aex_mult(ss,a),aex_mult(tt,b))));
      return {aa,ss,tt}
   end;

procedure aex_tgpairwiseprime(ael, x);
   % Pairwise prime. [ael] is a list of Aex with non-trivial lc. Returns a list
   % of Aex with non-trivial lc.
   begin scalar pprestlist,tmp;
      if length ael <= 1 then return ael;
      pprestlist := aex_tgpairwiseprime(cdr ael,x);
      tmp := aex_tgpairwiseprime1(car ael . pprestlist,x);
      % lets assume aex_quot returns something with lc non-trivial.
      return if not aex_simplenumberp tag_object car tmp then
	 tmp else cdr tmp
   end;

procedure aex_tgpairwiseprime1(ael, x);
   % makes ae1 prime to ae2l.
   begin scalar ae1,ae2,ae2l,ae2lnew,g,n1,n2;
      ae1 := car ael; ae2l := cdr ael; ae2lnew := nil;
      while ae2l and not aex_simplenumberp tag_object ae1 do <<
	 ae2 := car ae2l;
	 g := aex_gcd(tag_object ae1,tag_object ae2,x);
	 n1 := aex_deg(tag_object ae1,x);
      	 ae1 := tag_(aex_quot(tag_object ae1,g,x),tag_taglist ae1);
	 n2 := aex_deg(tag_object ae1,x);
	 if n1 > n2 then
	    ae2 := tag_(tag_object ae2,union(tag_taglist ae1,tag_taglist ae2));
 	 ae2lnew := ae2 . ae2lnew;
      	 ae2l := cdr ae2l;
      >>;
      return ae1 . ae2lnew
   end;

asserted procedure aex_sqfree(f: Aex, x: Kernel): Aex;
   % Pseudo square-free part. Question: What if [f] is not reduced?
   if aex_deg(f,x) < 2 then
      f
   else
      aex_quot(f, aex_gcd(f, aex_diff(f, x), x), x);

asserted procedure aex_inv(ae: Aex): Aex;
   % Invert a constant, not-zero polynomial. TODO: The case of a purely rational
   % ae occurs very often. Avoid the progn by splitting into two functions.
   begin scalar x, alpha, g, f, d, f1, aa, ss, tt;
      if aex_simpleratp ae then  % [ae] is obviously a rational number.
	 return aex_fromrp quotsq(1 ./ 1, aex_ex ae);
      % Now we know that [ae] is a constant algebraic polynomial.
      x . alpha := car ctx_ial aex_ctx ae;  % (x . (anu f iv))
      g := aex_unbind(ae, x);
      f := anu_dp alpha;
      f := aex_sqfree(f, x);  % MK + TS 12/2012
      d := car aex_gcdext(f, g, x);
      f1 := aex_quot(f, d, x);
      % Applying extended euclidean algorithm to f1 and g, gives: aa = ss*f1 + tt*g.
      {aa, ss, tt} := aex_gcdext(f1, g, x);
      % [aa] is non-zero rational, but not necessarily 1.
      if !*rlanuexgcdnormalize then
	 return aex_bind(aex_mult(aa, tt), x, alpha);
      return aex_bind(aex_mult(aex_inv aa, tt), x, alpha)
   end;

% Root isolation.

asserted procedure aex_coefl(ae: Aex, x: Kernel): AexList;
   if aex_mvartest(ae,x) then
      aex_lc(ae,x) . aex_coefl(aex_red(ae,x),x)
   else
      {ae};

asserted procedure aex_coefdegl(ae: Aex, x: Kernel): List;
   % Coefficients and degree list. [ae] is Aex in x.
   if aex_mvartest(ae,x) then
      (aex_lc(ae,x) . aex_deg(ae,x)) . aex_coefdegl(aex_red(ae,x),x)
   else
      {aex_lc(ae,x) . 0};

asserted procedure aex_fromcoefdegl(cfdgl: List, x: Kernel): Aex;
   begin scalar ae;
      ae := aex_0();
      for each cd in cfdgl do
	 ae := aex_add(ae,aex_mult(car cd,aex_xtothen(x,cdr cd)));
      return ae
   end;

asserted procedure aex_containment(ae: Aex): RatInterval;
   % Algebraic expression containment. [ae] is a constant Aex. Returns an
   % interval. The algebraic number represented by [ae] is contained in the
   % returned interval regarded as closed.
   begin scalar ia,cfdgl,ctac,ivl,r;
      % coefficient and degree list, containment of a_c, interval list
      % [ae] should be a constant.
      assert(not aex_badp(ae, 0));
      assert(null aex_fvarl ae);
      if null aex_bvarl ae then <<
	 assert(null aex_varl ae);
	 r := aex_ex ae;
	 return iv_mk(r, r)
      >>;
      % Now there is a bound variable.
      ia := car ctx_ial aex_ctx ae;
      ctac := anu_iv cdr ia;
      %ae := aex_unbind(ae,car ia);
      cfdgl := aex_coefdegl(aex_unbind(ae,car ia),car ia);
      % Reconstruct Aex from [cfdgl] for test purposes.
      assert(aex_nullp aex_minus(ae,aex_fromcoefdegl(cfdgl, car ia)));
      ivl := for each cfdg in cfdgl collect
	 iv_mult(aex_containment car cfdg,iv_tothen(ctac,cdr cfdg));
      return iv_mapadd ivl
   end;

asserted procedure aex_distinguishpositivefromzero(ae: Aex, iv: RatInterval): Rational;
   % Algebraic expression distinguish positive from zero. [ae] is a positive
   % constant Aex, [iv] is an interval containing the positive algebraic number
   % represented by [ae]. Returns a Rational, which lies in [0, ae].
   begin scalar rb;
      rb := rat_mult(iv_rb iv, rat_mk(1, 2));
      while not eqn(aex_sgn aex_addrat(ae, rat_neg rb), 1) do
	 rb := rat_mult(rb, rat_mk(1, 2));
      return rb
   end;

asserted procedure aex_distinguishfromzero(ae: Aex, iv: RatInterval): Rational;
   % Algebraic expression distinguish from zero. [ae] is a constant Aex, [iv] an
   % interval containing the algebraic number represented by [ae]. Returns a
   % Rational which lies in $[0, ae]$ or $[ae, 0]$, respectively.
   begin scalar sgnae;
      sgnae := aex_sgn ae;
      if eqn(sgnae, 0) then
	 return rat_0();
      if eqn(sgnae, 1) then
	 return aex_distinguishpositivefromzero(ae, iv);
      return rat_neg aex_distinguishpositivefromzero(aex_neg ae, iv_neg iv)
   end;

asserted procedure aex_cauchybound(ae: Aex, x: Kernel): Rational;
   % Algebraic expression cauchy bounds. [ae] is an univariate Aex in [x] with
   % non-trivial leading coefficient. Returns an non-negative Rational, the
   % minimum of the cauchy bounds of ae.
   begin scalar cfl,am,ctam,nb,ctl,ml,m,n,minabsam,cb,aesc;
      % [ae] should not have non-trivial degree:
      assert(not aex_badp(ae, 1));
      assert(not aex_simplenullp aex_lc(ae, x));
      if aex_deg(ae,x) <= 0 then
	 return rat_1(); % avoids trivial sturmchains
      cfl := aex_coefl(ae,x); % has at least length 1
      am := car cfl;
      ctam := aex_containment am;
      if iv_containszero ctam then <<
	 if !*rlverbose and !*rlanuexverbose then
	    prin2 "+++ aex_cauchybound: iteration case +++";
   	 nb := aex_distinguishfromzero(am,ctam);
	 ctam := if rat_less(nb,rat_0()) then
	    iv_mk(iv_lb ctam,nb)
	 else
	    iv_mk(nb,iv_rb ctam)
      >>;
      % now ctam is a containing interval for a_m without 0.
      ctl := for each cf in cdr cfl collect aex_containment cf;
      ml := for each iv in ctl collect iv_maxabs iv;
      minabsam := iv_minabs ctam;
      m := rat_max(rat_1(),rat_quot(rat_addl ml,minabsam));
      n := if null ml then
	 rat_1()
      else
	 rat_add(rat_1(),
	    rat_mapmax for each a in ml collect rat_quot(a,minabsam));
      cb := rat_min(m,n);
      aesc := aex_stdsturmchain(ae,x);
      % Check if the bound was computed correctly:
      assert(aex_stchsgnch1(aesc,x,cb) eq aex_stchsgnch(aesc,x,'infty));
      assert(aex_stchsgnch(aesc,x,'minfty) eq
	 aex_stchsgnch1(aesc,x,rat_minus(rat_neg cb,rat_1())));
      return cb
   end;

asserted procedure aex_findrootsoflist(ael: AexList, x: Kernel): AnuList;
   aex_findroots(aex_multl ael,x);

asserted procedure aex_findroots(ae: Aex, x: Kernel): AnuList;
   % Aex find roots. [ae] is an Aex(c,c+1). Returns a list of Anu(c+1). If
   % [ae]'s ldeg is not positive, the empty list will be returned. The interval
   % to start with has to be slightly enlarged.
   begin scalar cb,rootlist;
      if aex_deg(ae,x) < 1 then return nil;
      cb := rat_add(aex_cauchybound(ae,x),rat_1()); % necessary to add 1.
      %cb := 256 . 1; %%% later cauchybound!!!
      rootlist := aex_findrootsiniv1(ae,x,iv_mk(rat_neg cb,cb),
	 aex_stdsturmchain(ae,x));
      return rootlist
   end;

asserted procedure aex_findrootsiniv(ae: Aex, x: Kernel, iv: RatInterval): AnuList;
   % Aex find roots in interval. [ae] is an Aex(c,c+1). The ldeg of [ae] has to
   % be positive, i.e. [ae] must not represent a constant polynomial. Returns an
   % ordered list of Anu(c+1).
   aex_findrootsiniv1(ae,x,iv,aex_stdsturmchain(ae,x));

asserted procedure aex_findrootsiniv1(ae: Aex, x: Kernel, iv: RatInterval, sc: AexList): AnuList;
   % Aex find roots in interval. [ae] is an Aex(c,c+1), [sc] is [ae]'s Sturm
   % chain. The ldeg of [ae] is positive, i.e. [ae] must not represent a
   % constant polynomial. Returns an ordered list of Anu(c+1).
   begin scalar lb,rb,sclb,scrb,m,ml,mr,retl,r;
      lb := iv_lb iv;
      rb := iv_rb iv;
      sclb := aex_stchsgnch1(sc,x,lb);
      if sclb = 0 then return nil;
      scrb := aex_stchsgnch1(sc,x,rb);
      if sclb - scrb = 0 then
	 return nil;
      if sclb - scrb = 1 then
	 return {anu_mk(ae,iv)};
      m := rat_quot(rat_add(lb,rb),rat_fromnum 2);
      ml := mr := m;
      if eqn(aex_sgn aex_subrat1(ae,x,m), 0) then <<
	 r := aex_isoroot(ae,x,m,rat_mult(rat_minus(rb,lb),rat_mk(1,4)),sc);
	 ml := rat_minus(m,r);
	 mr := rat_add(m,r)
      >>;
      retl := aex_findrootsiniv1(ae,x,iv_mk(mr,rb),sc);
      if not rat_eq(ml,mr) then
	 retl := anu_mk(ae,iv_mk(ml,mr)) . retl;
      retl := append(aex_findrootsiniv1(ae,x,iv_mk(lb,ml),sc),retl);% nconc!!!
      return retl
   end;

asserted procedure aex_isoroot(ae: Aex, x: Kernel, m: Rational, r: Rational, sc: AexList): Rational;
   % Aex isolate root. [ae] is an AEX(c,c+1), [sc] is [ae]'s Sturm chain. The
   % ldeg of [ae] is positive, i.e. [ae] must not represent a constant
   % polynomial. Returns a Rational $s$ such that [ae] has no root within the
   % interval $[m-s,m+s]$.
   <<
      while not (not aex_atratnullp(ae,x,rat_minus(m,r)) and
      not aex_atratnullp(ae,x,rat_add(m,r)) and
	 aex_stchsgnch1(sc,x,rat_minus(m,r))-
	    aex_stchsgnch1(sc,x,rat_add(m,r)) eq 1) do
      	       r := rat_mult(r,rat_mk(1,2));
      r
   >>;

asserted procedure aex_atratnullp(ae: Aex, x: Kernel, r: Rational): Boolean;
   % Zero at rational point predicate.
   eqn(aex_sgn aex_subrat1(ae, x, r), 0);

%%% --- global root isolation --- %%%

%procedure aex_globalrootisolationinit(ff,x);
%   % [ff] is a (maybe empty) list of AEX (univariate alg.
%   % polynomials). [ff] is factorized, i.e. each root occures only in
%   % one polynomial.
%   {nil,nil,for each f in ff collect f . aex_stdsturmchain(f,x)};

procedure aex_nextroot(rip,x);
   % [rip] is of form {rootl,ivl,pscl}, where rootl is a list of ANU,
   % ivl a list of IV, pscl a list of dotted pais p . sc where p ia an
   % AEX (a univariate alg. polynomial) and sc is the corresponding
   % sturmchain. Returns t, if a root is found, nil otherwise. The
   % argument is changed in-place.
   begin scalar rootfound,cb;
      while not rootfound and rip_pscl rip do <<
	 % pscl is not empty. if ivl is empty, mk new iv with cb.
	 while null rip_ivl rip and rip_pscl rip do <<
	    cb := rat_add(
	       aex_cauchybound(tag_object caar rip_pscl rip,x),rat_1());
	    rip_addivl(rip,iv_minuslist(iv_mk(rat_neg cb,cb),
	       for each a in rip_rootlnotags rip collect anu_iv a));
	    % maybe after minuslist there are no intervals left
	    if null rip_ivl rip then rip_poppscl rip;
	 >>;
	 % care for the case that there was no poly left with a root
	 if rip_pscl rip then << % there is at least one interval and one poly
	    % Check that there is an interval and a polynomial:
	    assert(rip_ivl rip and rip_pscl rip);
	    if aex_nextroot1(rip,x) then
	       rootfound := t;
	    if null rip_ivl rip then
	       rip_poppscl rip
	 >>
      >>;
      if rootfound then <<
	 assert(anu_check tag_object car rip_rootl rip);
	 return car rip_rootl rip
      >>;
      return nil
   end;

procedure aex_nextroot1(rip,x);
   % There is an interval and there is a poly. this function attempts
   % to isolate at most one root. A root might be added to rootl and
   % intervals might be added to ivl, but pscl is not popped. Returns
   % t, if a root was found. Possible Optimazions: tagged intervals,
   % use anu_fromrat if a rat. root is found. rip contains tagged
   % polynomials.
   begin scalar iv,lb,rb,sc,sclb,scrb,m,ml,mr,r;
      % remove iv from ivl
      iv := rip_popivl rip; lb := iv_lb iv; rb := iv_rb iv;
      sc := cdar rip_pscl rip;
      sclb := aex_stchsgnch1(sc,x,lb);
      if sclb = 0 then return nil;
      scrb := aex_stchsgnch1(sc,x,rb);
      if sclb - scrb = 0 then return nil;
      if sclb - scrb = 1 then <<
	 rip_addroot(rip,
	    tag_(aex_refinewrt1(anu_mk(tag_object caar rip_pscl rip,iv),
	       cdr rip_psclnotags rip,cdar rip_pscl rip),
	       tag_taglist caar rip_pscl rip));
	 return t
      >>;
      % there are at least two roots.
      m := rat_quot(rat_add(lb,rb),rat_fromnum 2);
      ml := mr := m;
      if eqn(aex_sgn aex_subrat1(tag_object caar rip_pscl rip,x,m), 0) then <<
	 r := aex_isoratroot(m,rat_mult(rat_minus(rb,lb),rat_mk(1,4)),
	    rip_psclnotags rip,x); % cdr rip_pscl rip would be wrong
	 ml := rat_minus(m,r); mr := rat_add(m,r);
	 %rip_addroot(rip,anu_mk(caar rip_pscl rip,iv_mk(ml,mr)))
	 % instead, the following is only a very small optimization(1-2%):
	 rip_addroot(rip,tag_(anu_fromrat(x,m,iv_mk(ml,mr)),
	    tag_taglist caar rip_pscl rip))
      >>;
      rip_addivl(rip,{iv_mk(mr,rb)});
      rip_addivl(rip,{iv_mk(lb,ml)});
      return not rat_eq(ml,mr);
   end;

procedure aex_isoratroot(m,r,pscl,x);
   % [m] is a rational root of [caar pscl]. Returns a r such that no
   % sturmchain from cdr scl has a sign change in (m-r,m+r), and such
   % that car scl has 1 sign change in (m-r,m+r). No tags in here.
   << % Refine r until p's sc has only 1 sgn change.
      while aex_atratnullp(caar pscl,x,rat_minus(m,r)) or
      aex_atratnullp(caar pscl,x,rat_minus(m,r)) or
	 aex_deltastchsgnch(cdar pscl,x,
	    iv_mk(rat_minus(m,r),rat_add(m,r))) > 1 do
	       r := rat_mult(r,rat_mk(1,2));
      pscl := cdr pscl;
      % Refine r until the other sc's have no sgn changes.
      for each psc in pscl do
      while aex_atratnullp(car psc,x,rat_minus(m,r)) or
	 aex_atratnullp(car psc,x,rat_minus(m,r)) or
	    aex_deltastchsgnch(cdr psc,x,
	       iv_mk(rat_minus(m,r),rat_add(m,r))) > 0 do
		  r := rat_mult(r,rat_mk(1,2));
      r
   >>;

asserted procedure aex_refinewrt1(alpha: Anu, pscl: List, scalpha: AexList): Anu;
   % Refine [alpha] in such a way that no sturm chain from [pscl] has a sign
   % change in alpha's isolating interval. [scalpha] is the sturm chain for
   % alpha's defining polynomial.
   begin scalar x, p, sc;
      x := aex_mvar anu_dp alpha;
      for each psc in pscl do <<
	 p := car psc;
      	 sc := cdr psc;
      	 while aex_atratnullp(p, x, iv_lb anu_iv alpha) or
	 aex_atratnullp(p, x, iv_rb anu_iv alpha) or
	 aex_deltastchsgnch(sc, x, anu_iv alpha) > 0 do
	    anu_refine1ip(alpha, scalpha);
      >>;
      return alpha
   end;

procedure aex_deltastchsgnch(sc,x,iv);
   % delta sturm chain sign changes in an interval
   begin integer sclb, scrb;
      sclb := aex_stchsgnch1(sc,x,iv_lb iv);
      if eqn(sclb, 0) then
	 return 0;
      scrb := aex_stchsgnch1(sc,x,iv_rb iv);
      return sclb - scrb
   end;

% - little helpers for global root isolation - %
% rip stands for root list, interval list, p.sc list

procedure psc_sortdesc(psc1,psc2);
   % Sort function descending. psc1 and psc2 are list of dotted pairs
   % p.sc phere p is a ratpoly and sc is a sturmchain. To be used by
   % generic_sort, yiels a sorted list with descending length of sturm
   % chains.
   sgn(length cdr psc2 - length cdr psc1);

procedure psc_sortasc(psc1,psc2);
   % Sort function asscending. psc1 and psc2 are list of dotted pairs
   % p.sc phere p is a ratpoly and sc is a sturmchain. To be used by
   % generic_sort, yiels a sorted list with ascending length of sturm
   % chains.
   sgn(length cdr psc1 - length cdr psc2);

procedure rip_init(ael,x);
   % [ael] is a (maybe empty) list of TAG(AEX) (tagged univariate alg.
   % polynomials). [ael] is factorized, i.e. each root occures only in
   % one polynomial.
   {nil,nil,for each ae in ael collect
      ae . aex_stdsturmchain(tag_object ae,x)};
%      generic_sort(for each ae in ael collect ae . aex_stdsturmchain(ae,x),
%	 'psc_sortasc)};

procedure rip_rootl rip;
   car rip;

procedure rip_rootlnotags rip;
   for each r in car rip collect tag_object r;

procedure rip_ivl rip;
   cadr rip;

procedure rip_pscl rip;
   caddr rip;

procedure rip_psclnotags rip;
   for each psc in caddr rip collect tag_object car psc . cdr psc;

procedure rip_putivl(rip,ivl);
   cadr rip := ivl;

procedure rip_putpscl(rip,pscl);
   caddr rip := pscl;

procedure rip_addroot(rip,root);
   car rip := root . car rip;

procedure rip_addivl(rip,ivl);
   cadr rip := nconc(ivl,rip_ivl rip);

procedure rip_poppscl rip;
   caddr rip := cdr caddr rip;

procedure rip_popivl rip;
   <<cadr rip := cdr cadr rip; carivl>> where carivl=car rip_ivl rip;

%procedure aex_ivlfromrootl rootl;
%   % interval list from root list. [rootl] is a list of ANU.
%   for each a in rootl collect anu_iv a;

% Anu functions.

asserted procedure anu_mk(ae: Aex, iv: RatInterval): Anu;
   {'anu, ae, iv};

asserted procedure anu_dp(a: Anu): Aex;
   cadr a;

asserted procedure anu_iv(a: Anu): RatInterval;
   caddr a;

asserted procedure anu_fromrat(x: Kernel, r: Rational, iv: RatInterval): Anu;
   anu_mk(aex_mklin(x, r), iv);

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
   begin scalar dp,x,l,r,s,valid;
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

asserted procedure anu_refine1ip(a: Anu, s: AexList): Anu;
   % Algebraic number refine in place. [s] is a sturmchain. Returns an [a] with
   % smaller isolating interval. Remark: 1000 was replaced by 4.
   begin scalar x, iv, lb, rb, m, scm;
      x := aex_mvar anu_dp a;
      iv := anu_iv a;
      lb := iv_lb iv;
      rb := iv_rb iv;
      m := rat_quot(rat_add(lb, rb), rat_mk(2, 1));
      if eqn(aex_sgn aex_subrat1(anu_dp a, x, m), 0) then <<
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

asserted procedure aex_badp(aex: Aex, fvn: Integer): ExtraBoolean;
   % [fvn] is the number of expected variables or -1.
   begin scalar varl, ctx, ial, brk, v, anu, bvarl, fvarl, fv, bv, scbvarl;
      if not eqcar(aex, 'aex) then
	 return 1;
      varl := kernels numr cadr aex;
      ctx := caddr aex;
      if not eqcar(ctx, 'ctx) then
	 return 2;
      ial := cadr ctx;
      brk := nil; while not brk and ial do <<
	 v . anu := pop ial;
	 % if not (v memq varl) then
	 %    brk := 3;
	 if not brk and ial and (not ordop(v, caar ial) or v eq caar ial) then
	    brk := 4;
	 if not brk and v neq aex_mvar anu_dp anu then
	    brk := 5;
	 brk := brk or anu_badp anu
      >>;
      if brk then
	 return brk;
      bvarl := for each pr in cadr ctx collect car pr;
      fvarl := lto_setminus(varl, bvarl);
      if not eqn(fvn, -1) and not eqn(length fvarl, fvn) then
	 return 6;
      brk := nil; while not brk and fvarl do <<
	 fv := pop fvarl;
	 scbvarl := bvarl;
	 while not brk and scbvarl do <<
	    bv := pop scbvarl;
	    if not ordop(fv, bv) and fv neq bv then
	       brk := 7
	 >>
      >>;
      return brk
   end;

asserted procedure anu_badp(anu: Anu): ExtraBoolean;
   begin scalar aex, iv, w;
      if not eqcar(anu, 'anu) then
	 return 11;
      aex := cadr anu;
      iv := caddr anu;
      if not pairp iv then
	 return 12;
      if not pairp car iv or not RationalP car iv then
	 return 13;
      if not pairp cdr iv or not RationalP cdr iv then
	 return 14;
      if not sfto_lessq(car iv, cdr iv) then
	 return 15;
      w := aex_badp(aex, 1);
      if w then
	 return w + 1000
   end;

endmodule;  % ofsfanuex

end;  % of file
