% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2014 T. Sturm
% ----------------------------------------------------------------------
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

module ranum;
% Real algebraic numbers.
%
% Real algebraic numbers are represented as x = (:ra: f (iv l u)), where f is a
% univariate squarefree SF in ra_v() and l and u are SQ representations of
% numbers.
%
% (1) The domain-specific representation of 0 is (:ra: x (iv -1 1)).
%
% For all intervals (iv l u) of non-zero numbers it is guanranteed that
%
% (2) there is exactly one zero of f in ]l, u[ but
% (3) no such zero at the interval bounds.
%
% Consequently, for numbers u and l it does not matter whether the intervals are
% considered open or closed. We consider them open, because this is cleaner with
% respect to -infinity and infinity. Note that (1) implies that l < u and that
% deg f > 1.
%
% Furthermore, most functions require that x <> 0 is normalized in the following
% sense:
%
% (4) NOT l < 0 < u.
%
% For forms x satisfying (1)--(3) but possibly not (4), there is a
% function ra_normalize(x) yielding x' so that x'=x and ra' satisfies (1)--(4).
%
% Since (3) prohibits to represent rational numbers p/q via one-point intervals,
% the recommended way to do so is (:ar: q*x-p (iv -infinity 0)) or (:ar: q*x-p
% (iv 0 infinity)) or any other suitable interval in the sense of (2) and (3).

load!-package 'assert;
load!-package 'rltools;

struct RA asserted by RAp;

procedure RAp(s);
   null s or eqcar(s, '!:ra!:);

struct IV checked by IVp;

procedure IVp(s);
   eqcar(s, 'iv);

create!-package('(ranum raarith rarcount raiv), nil);

global '(domainlist!*);

global '(emsg!*);

fluid '(dmode!*);

fluid '(!*backtrace);

fluid '(!*msg);

fluid '(ra_precision!*);

if not ra_precision!* then ra_precision!* := 2;

switch ranum;
switch rasimpl;
switch rasifac;

on1 'rasimpl;
on1 'rasifac;

domainlist!* := union('(!:ra!:), domainlist!*);

put('ranum, 'tag, '!:ra!:);

flag('(!:ra!:), 'field);

put('!:ra!:, 'dname, 'ranum);

put('!:ra!:, 'zerop, 'ra_zerop);
put('!:ra!:, 'onep, 'ra_onep);
put('!:ra!:, 'minusp, 'ra_minusp);

put('!:ra!:, 'i2d, 'ra_i2ra);

put('!:ra!:, 'plus, 'ra_plus);
put('!:ra!:, 'minus, 'ra_minus);
put('!:ra!:, 'difference, 'ra_difference);
put('!:ra!:, 'times, 'ra_times);
put('!:ra!:, 'quotient, 'ra_quotient);
put('!:ra!:, 'intequivfn, 'ra_intequiv);

put('ra, 'simpfn,'ra_simp);
put('!:ra!:, 'prepfn, 'ra_prep);
put('!:ra!:, 'prifn, 'ra_print);

put('!:rn!:, '!:ra!:, 'ra_rn2ra);

macro procedure ra_wrap(argl);
   begin scalar iname, oname, n, args, prgn;
      iname := cadr argl;
      oname := caddr argl;
      n := get(iname, 'number!-of!-args) or if cdddr argl then cadddr argl;
      if null n then
	 rederr {car argl, cdr argl, "cannot determine the arity of", iname};
      args := for i := 1:n collect mkid('a,i);
      prgn := {'put, mkquote oname, ''number!-of!-args, n} . prgn;
      prgn := {'de, oname, args, {'ra_wrapper, mkquote iname, 'list . args}} . prgn;
      return 'progn . prgn
   end;

asserted procedure ra_wrapper(f: Id, argl: List): Any;
   begin scalar w, oldmode;
      oldmode := get(dmode!*, 'dname);
      w := errorset({'ra_wrapper1, mkquote f, mkquote argl, mkquote oldmode}, t, !*backtrace);
      if errorp w then <<
      	 lprim {"caught error - restoring domain mode", oldmode};
	 if oldmode then on1 oldmode;
	 error1()
      >>;
      return car w
   end;

asserted procedure ra_wrapper1(f: Id, argl: List, oldmode: Id): Any;
   begin scalar w;
      if oldmode then off1 oldmode;
      w := apply(f, argl);
      if oldmode then on1 oldmode;
      return w
   end;

asserted procedure ra_wrappertest0(x: Integer, y: Integer): Integer;
   <<
      if x=7 then rederr {"x=7"};
      x+y
   >>;

ra_wrap(ra_wrappertest0, ra_wrappertest, 2);

asserted procedure ra_prep(x: RA): List;
   {'ra, prepf ra_f x, prepsq iv_l ra_iv x, prepsq iv_u ra_iv x};

put('ra, 'prifn, function(lambda u; ra_print numr ra_simp u));

inline procedure ra_x();
   'x;

inline procedure ra_y();
   % Choosing my y smaller than my x save some reordering with resultant
   % computations.
   'w;

inline procedure ra_zero();
   % The ranum representation of 0, in contrast to [nil].
   ra_mk(!*k2f ra_x(), iv_mk(-1 ./ 1, 1 ./ 1));

asserted procedure ra_mk(f: SF, i: IV): RA;
   {'!:ra!:, f, i};

asserted procedure ra_qmk(f: SF, l: SQ, u: SQ): RA;
   % Quick make construct the interval.
   {'!:ra!:, f, iv_mk(l, u)};

asserted procedure ra_f(x: RA): SF;
   % [x] must not be zero.
   cadr x;

asserted procedure ra_iv(x: RA): IV;
   % [x] must not be zero.
   caddr x;

asserted procedure ra_l(x: RA): SQ;
   % [x] must not be zero.
   iv_l ra_iv x;

asserted procedure ra_u(x: RA): SQ;
   % [x] must not be zero.
   iv_u ra_iv x;

asserted procedure ra_print(x: RA);
   if not !*nat then <<
      prin2!* "ranum(";
      maprin prepf ra_f x;
      prin2!* ", ";
      maprin prepsq iv_l ra_iv x;
      prin2!* ", ";
      maprin prepsq iv_u ra_iv x;
      prin2!* ")"
   >> else <<
      prin2!* "(";
      maprin prepf ra_f x;
      prin2!* ", ";
      maprin ra_iv x;
      prin2!* ")"
   >>;

asserted procedure ra_simp0(u: List): SQ;
   begin scalar f, l, u, w;
      u := cdr u;
      f := numr simp car u;
      f := sfto_dprpartf sfto_sqfpartf f;
      l := simp cadr u;
      u := simp caddr u;
      w := ra_qmk(f, l, u);
      return !*f2q ra_simpl0 ra_normalize0 w
   end;

ra_wrap(ra_simp0, ra_simp, 1);

asserted procedure ra_ra0(u: List): RA;
   % The Algebraic Mode constructor for real algebraic numbers.
   begin scalar bc, f, l, u;
      f := numr simp car u;
      f := sfto_dprpartf sfto_sqfpartf f;
      l := simp cadr u;
      u := simp caddr u;
      if null numr sfto_qsub1(f, {ra_x() . l}) then
	 rederr {"polynomial has a zero at the lower bound of the specified interval"};
      if null numr sfto_qsub1(f, {ra_x() . u}) then
	 rederr {"polynomial has a zero at the upper bound of the specified interval"};
      bc := ra_budancount(f, l, u);
      if eqn(bc, 1) then
      	 return mk!*sq !*f2q ra_simpl0 ra_normalize0 ra_qmk(f, l, u);
      if eqn(bc, 0) then
	 rederr {"polynomial has no zero on specified interval"};
      rederr {"polynomial has more than one zero on specified interval"}
   end;

ra_wrap(ra_ra0, ra_ra, 1);

put('ra, 'psopfn, 'ra_ra);

asserted procedure ra_zerop(x: RA): Boolean;
   null red ra_f x;

asserted procedure ra_onep0(x: RA): Boolean;
   % Explicity treat the special case x^n - 1 for efficiency.
   iv_contains(ra_iv x, 1 ./ 1) and
      (eqn(red ra_f x, -1) or eqn(sfto_fsub1(ra_f x, {ra_x() . 1}), 1));

asserted procedure ra_onep0(x: RA): Boolean;
   % Explicity treat the special case x^n - 1 for efficiency.
   iv_contains(ra_iv x, 1 ./ 1) and
      (eqn(red ra_f x, -1) or eqn(sfto_fsub1(ra_f x, {ra_x() . 1}), 1));

ra_wrap(ra_onep0, ra_onep, 1);

asserted procedure ra_intequiv0(x: RA): Any;
   % Returns [x] or the Integer represented by [x].
   begin scalar f, l, u, z;
      if ra_zerop x then
	 return 0;
      f := ra_f x;
      if eqn(ldeg f, 1) and eqn(lc f, 1) then
	 return negf red f;
      l := iv_l ra_iv x;
      u := iv_u ra_iv x;
      while sfto_greaterq(subtrsq(u, l), 1 ./ 1) do
	 l . u := ra_refine1(f, l, u, 1);
      z := addf(numr sfto_floorq l, 1);
      if sfto_lessq(!*f2q z, u) and null sfto_fsub1(f, {ra_x() . z}) then
	 return z or 0;
      return x
   end;

ra_wrap(ra_intequiv0, ra_intequiv, 1);

asserted procedure raprintprecision(n: Integer): Integer;
   % [n] is the number of digits printed after the period. At present the number
   % of digits available is limited by other factors (pecision, machine floats,
   % ...?) so that [n] > 5 does not make much sense. With negative [n] the
   % rational numbers actually used internally are printed.
   begin scalar w;
      w := ra_precision!*;
      ra_precision!* := n;
      return w
   end;

operator raprintprecision;

asserted procedure ra_i2ra0(z: Integer): RA;
   begin scalar f, l, u;
      if eqn(z, 0) then
	 return ra_zero();
      f := addf(!*k2f ra_x(), negf z);
      l := !*f2q sfto_int2sf(z-1);
      u := !*f2q sfto_int2sf(z+1);
      return ra_normalize0 ra_qmk(f, l, u)
   end;

ra_wrap(ra_i2ra0, ra_i2ra, 1);

asserted procedure ra_rn2ra0(rn: DottedPair): RA;
   begin scalar f, l, u;
      if rnzerop!: rn then
      	 return ra_zero();
      f := addf(multf(!*k2f ra_x(), cddr rn), negf cadr rn);
      l := sfto_int2sf(cadr rn - 1) ./ cddr rn;
      u := sfto_int2sf(cadr rn + 1) ./ cddr rn;
      return ra_normalize0 ra_qmk(f, l, u)
   end;

ra_wrap(ra_rn2ra0, ra_rn2ra, 1);

initdmode 'ranum;

endmodule;

end;
