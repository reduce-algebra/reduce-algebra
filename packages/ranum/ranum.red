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
% univariate SF in ra_v() and l and u are SQs that are either numbers or SQ
% representations iv_minf() or iv_pinf() of -infinity or infinity, resp.
%
% f need not be minimal in any way, in particular, f need not be squarefree.
%
% For all intervals (iv l u) it is guanranteed that
%
% (1) there is exactly one zero of f in ]l, u[ but
% (2) no such zero at the interval bounds.
%
% Consequently, for numbers u and l it does not matter whether the intervals are
% considered open or closed. We consider them open, because this is cleaner with
% respect to -infinity and infinity. Note that (1) implies that l < u and that
% deg f > 1.
%
% Furthermore, most functions require that x is normalized in the following
% sense:
%
% (3) the only valid representation for 0 ist nil, and
% (4) NOT l < 0 < u.
%
% For forms x satisfying (1) and (2) but possibly not (3) or (4), there is a
% function ra_normalize(x) yielding x' so that x'=x and ra' satisfies (1), ...,
% (4).
%
% Since (2) prohibits to represent rational numbers p/q via one-point intervals,
% the recommended way to do so is (:ar: q*x-p (iv -infinity 0)) or (:ar: q*x-p
% (iv 0 infinity)) or any other suitable interval in the sense of (1) and (2).

load!-package 'assert;
load!-package 'rltools;

struct RA asserted by RAp;

procedure RAp(s);
   null s or eqcar(s, '!:ra!:);

struct IV checked by IVp;

procedure IVp(s);
   eqcar(s, 'iv);

create!-package('(ranum), nil);

global '(domainlist!*);

fluid '(dmode!*);

switch ranum;

domainlist!* := union('(!:ra!:), domainlist!*);

put('ranum, 'tag,' !:ra!:);

flag('(!:ra!:), 'field);

put('!:ra!:, 'dname, 'ranum);

put('!:ra!:, 'zerop, 'ra_zerop);
put('!:ra!:, 'onep, 'ra_onep);
put('!:ra!:, 'minusp, 'ra_minusp);

put('!:ra!:, 'plus, 'ra_plus);
put('!:ra!:, 'difference, 'ra_difference);
put('!:ra!:, 'times, 'ra_times);
put('!:ra!:, 'quotient, 'ra_quotient);
put('!:ra!:, 'intequivfn, 'ra_intequiv);

put('!:ra!:, 'prepfn, 'ra_prep);
put('!:ra!:, 'prifn, 'ra_print);

inline procedure iv_minf();
   '((((infinity . 1) . -1)) . 1);

inline procedure iv_pinf();
   '((((infinity . 1) . 1)) . 1);

asserted procedure iv_mk(l: SQ, u: SQ): IV;
   % [l] and [u] are numbers of one of iv_minf(), iv_pinf().
   {'iv, l, u};

asserted procedure iv_l(i: IV): SQ;
   % Lower bound.
   cadr i;

asserted procedure iv_u(i: IV): SQ;
   % Upper bound.
   caddr i;

asserted procedure iv_plus(i1: IV, i2: IV): IV;
   % ]l1, u1[ + ]l2, u2[ = ]l1 + l2, u1 + u2[
   iv_mk(addsq(iv_l i1, iv_l i2), addsq(iv_u i1, iv_u i2));

inline procedure ra_v();
   'x;

asserted procedure ra_mk(f: SF, l: SQ, u: SQ): RA;
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

asserted procedure ra_zerop(x: RA): Boolean;
   % [x] must be normalized. The only normalized representation of zero is nil,
   % which is caught by !:zerop.
   nil;

asserted procedure ra_onep(x: RA): Boolean;
   % We are not doing anything special about 1. After inspecting the Reduce
   % sources, I suspect that this is not seriuosly needed anywhere, in
   % particular since we are in a field. I throw an error to be on the safe
   % side anyway.
   <<
      backtrace();
      rederr "!:onep is not implemented for !:ra!:!"
   >>;

asserted procedure ra_minusp(x: RA): Boolean;
   % [x] must ne normalized.
   begin scalar l;
      if null x then
 	 return nil;
      l := ra_l x;
      return l = iv_minf() or sfto_lessq(l, nil ./ nil)
   end;

asserted procedure ra_normalize(x: RA): RA;
   % Normaize [x]. That is, return [nil] if [x] represents 0, else refine [x]
   % such that its interval does not contain zero.
   begin scalar f, l, u, sc;
      if null x then
	 return x;
      f := ra_f x;
      l := ra_l x;
      u := ra_u x;
      assert(not null numr sfto_subq(f, {ra_v() . l}));
      assert(not null numr sfto_subq(f, {ra_v() . u}));
      if null numr u or minusf numr u or null l or minusf negf numr l then
	 return x;
      % We now know l < 0 < u.
      if null sfto_abssummand f then
	 return nil;
      % We now know x <> 0.
      sc := sfto_sturmchain(f, ra_diff f);
      if eqn(sfto_sturmcount(sc, l, nil ./ 1), 1) then
	 return ra_mk(f, l, nil ./ 1);
      assert(eqn(sfto_sturmcount(sc, nil ./ 1, u), 1));
      return ra_mk(f, nil ./ 1, u)
   end;

asserted procedure ra_diff(f: SF): SF;
   numr difff(f, ra_v());

asserted procedure ra_plus(x: RA, y: RA): RA;
   ;



asserted procedure ra_isolate(f: SF): List;
   begin scalar cb;
      cb := sfto_cauchyf(f, ra_v());
      return ra_vca(f, negsq cb, cb)
   end;

procedure ra_help(hu);
   for each pr in hu collect {float(caar pr or 0) / float(cdar pr), float(cadr pr or 0)/float(cddr pr)};

asserted procedure ra_vca(f: SF, l: SQ, u: SQ): List;
   begin scalar ff, resl;
      ff := numr sfto_qsub1(f, {ra_v() . ra_transform(!*k2q ra_v(), l, u)});
      resl := ra_vca1(ff, l, u);
      return resl
   end;

asserted procedure ra_transform(x: SQ, l: SQ, u: SQ): SQ;
   addsq(multsq(subtrsq(u, l), x), l);

asserted procedure ra_vca1(f: SF, a: SQ, b: SQ): List;
   begin
      scalar ff, fff, c, resl;
      integer sv;
      sv := ra_budan!-0!-1 f;
      if eqn(sv, 0) then
	 return nil;
      if eqn(sv, 1) then
	 return {a . b};
      c := quotsq(addsq(a, b), !*f2q 2);
      ff := multf(2^ldeg f, f);
      fff := numr sfto_qsub1(ff, {ra_v() . (!*k2f ra_v() ./ 2)});
      resl := ra_vca1(fff, a, c);
      if null numr sfto_qsub1(f, {ra_v() . (1 ./ 2)}) then
	 resl := append(resl, {c . c});
      fff := numr sfto_qsub1(ff, {ra_v() . (addf(!*k2f ra_v(), 1) ./ 2)});
      resl := append(resl, ra_vca1(fff, c, b));
      return resl
   end;

asserted procedure ra_budan!-0!-1(f: SF): Integer;
   begin
      scalar xp1, ff, c;
      integer sign, cursign, signchanges;
      xp1 := addf(!*k2f ra_v(), 1);
      ff := sfto_qsub1(f, {ra_v() . (1 ./ xp1)});
      ff := multsq(!*f2q exptf(xp1, ldeg f), ff);
      ff := numr ff;
      while ff do <<
	 if domainp ff then <<
	    c := ff;
	    ff := nil
	 >> else <<
	    c := lc ff;
	    ff := red ff
	 >>;
	 sign := if minusf c then -1 else 1;
	 if sign * cursign < 0 then
	    signchanges := signchanges + 1;
	 cursign := sign;
      >>;
      return signchanges
   end;

endmodule;

end;
