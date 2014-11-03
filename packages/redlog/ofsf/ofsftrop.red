% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2013-2014 T. Sturm
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

module ofsftrop;

fluid '(ofsf_lpsolprec!*);
ofsf_lpsolprec!* := 8;

fluid '(rlsat2polatnum!*);

switch rlgurobi;  % use the Gurobi optimizer
off1 'rlgurobi;

switch rltropdel0;  % delete the (0,...,0) monomial
off 'rltropdel0;

switch rltropilp;  % use ILP solving instead of LP solving
on1 'rltropilp;

switch rltropint;  % use integers, not floats, even with off rltropilp

switch rltropsos;  % use sum of squares instead of sum for conjunctions
off1 'rltropsos;

switch rltroplcm;  % use lcm instead of product for disjunctions
on1 'rltroplcm;

% Entry points.

put('zerop, 'psopfn, 'ofsf_zeropeval);
put('pzerop, 'psopfn, 'ofsf_pzeropeval);

asserted procedure ofsf_tropsat(f: QfFormula);
   % Redlog service
   ofsf_tropsat1(f, nil);

asserted procedure ofsf_ptropsat(f: QfFormula);
   % Redlog service
   ofsf_tropsat1(f, t);

asserted procedure ofsf_sat2pol(f: QfFormula): SF;
   % Redlog service.
   ofsf_sat2pol1(f, nil);

asserted procedure ofsf_psat2pol(f: QfFormula): SF;
   % Redlog service.
   ofsf_sat2pol1(f, t);

asserted procedure ofsf_zeropeval(argl: List): List;
   % psopfn AM entry point
   ofsf_zeropeval1(argl, nil);

asserted procedure ofsf_pzeropeval(argl: List): List;
   % psopfn AM entry point
   ofsf_zeropeval1(argl, t);

asserted procedure ofsf_zeropeval1(argl: List, posp: Boolean): List;
   begin integer f, vl, w;
%%      ioto_tprin2t {"!*echo = ", !*echo};
      f := numr simp car argl;
%%      vl := sort(kernels f, 'ordop);
%%       if null vl or null cdr vl then
%% 	 rederr {car argl, "is not multivariate"};
      w := ofsf_zerop1(f, posp);
      return 'list . w
   end;

asserted procedure ofsf_zerop(f: SF): List;
   % SM entry point
   ofsf_zerop1(f, nil);

asserted procedure ofsf_pzerop(f: SF): List;
   % SM entry point
      ofsf_zerop1(f, t);

asserted procedure ofsf_tropsat1(f: QfFormula, posp: Boolean): Id;
   begin scalar p, w, sol, vl;
      p := ofsf_sat2pol1(f, posp);
      w := ofsf_zerop1(p, posp);
      if eqcar(w, 1) then <<
	 if !*rlverbose then
 	    ioto_tprin2 "found candidate, solving ... ";
	 sol := ofsf_zerosolve(p, w);
	 if !*rlverbose then
 	    ioto_prin2t "done";
	 vl := cl_fvarl1 f;
	 sol := for each pr in sol join if car pr memq vl then {pr};
	 % Evaluate f at sol
	 return 'sat;
      >>;
      if eqcar(w, 0) then
	 return 'unsat;
      if eqcar(w, -1) then
	 return 'unknown;
      rederr {"something wrong in ofsf_tropsat: ofsf_zerop1 returned ", w}
   end;

asserted procedure ofsf_sat2pol1(f: QfFormula, posp: Boolean): SF;
   begin scalar w; integer rlsat2polatnum!*;
      w := cl_simpl(cl_pnf f, nil, -1);
      rlsat2polatnum!* := cl_atnum f;
      return car ofsf_formula2pol1(w, nil, nil, nil, posp)
   end;

asserted procedure ofsf_formula2pol1(f: QfFormula, geal: Alist, gral: Alist, neal: Alist, posp: Boolean): List4;
   begin scalar op, e, ee;
      if f eq 'true then
	 return {0, geal, gral, neal};
      if f eq 'false then
	 return {1, geal, gral, neal};
      op := rl_op f;
      if op eq 'or then <<
      	 e := 1;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal, posp);
	    e := sfto_sqfpartf if !*rltroplcm then lcm!*(ee, e) else multf(ee, e)
      	 >>;
	 return {e, geal, gral, neal}
      >>;
      if op eq 'and then <<
	 e := nil;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal, posp);
	    if !*rltropsos then
	       ee := exptf(ee, 2);
	    e := sfto_sqfpartf addf(ee, e)
      	 >>;
%	 e := sfto_sqfpartf e;
	 return {e, geal, gral, neal}
      >>;
      if !*rlverbose then
	 ioto_prin2 {"[", rlsat2polatnum!* := rlsat2polatnum!* - 1};
      if op eq 'equal then <<
      	 if !*rlverbose then ioto_prin2 "e] ";
 	 return {ofsf_arg2l f, geal, gral, neal}
      >>;
      if op eq 'geq then
	 return ofsf_geq2pol(ofsf_arg2l f, geal, gral, neal, posp);
      if op eq 'leq then
	 return ofsf_geq2pol(negf ofsf_arg2l f, geal, gral, neal, posp);
      if op eq 'greaterp then
	 return ofsf_greaterp2pol(ofsf_arg2l f, geal, gral, neal, posp);
      if op eq 'lessp then
	 return ofsf_greaterp2pol(negf ofsf_arg2l f, geal, gral, neal, posp);
      if op eq 'neq then
	 return ofsf_neq2pol(ofsf_arg2l f, geal, gral, neal, posp);
      rederr {"something wrong in ofsf_formula2pol1: op =  ", op}
   end;

asserted procedure ofsf_geq2pol(lhs: SF, geal: Alist, gral: Alist, neal: Alist, posp: Boolean): List4;
   begin scalar w, e;
      w := assoc(lhs, geal);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := if posp then
	 sfto_sqfpartf addf(lhs, negf !*k2f intern gensym())
      else
	 sfto_sqfpartf addf(lhs, negf exptf(!*k2f intern gensym(), 2));
      if !*rlverbose then ioto_prin2 "] ";
      return {e, (lhs . e) . geal, gral, neal}
   end;

asserted procedure ofsf_greaterp2pol(lhs: SF, geal: Alist, gral: Alist, neal: Alist, posp: Boolean): List4;
   begin scalar w, e;
      w := assoc(lhs, gral);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := if posp then
	 sfto_sqfpartf addf(multf(!*k2f intern gensym(), lhs), negf 1)
      else
	 sfto_sqfpartf addf(multf(exptf(!*k2f intern gensym(), 2), lhs), negf 1);
      if !*rlverbose then ioto_prin2 "] ";
      return {e, geal, (lhs . e) . gral, neal}
   end;

asserted procedure ofsf_neq2pol(lhs: SF, geal: Alist, gral: Alist, neal: Alist, posp: Boolean): List4;
   begin scalar w, e;
      w := assoc(lhs, neal);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := if posp then
	 sfto_sqfpartf addf(multf(addf(!*k2f intern gensym(), negf !*k2f intern gensym()), lhs), negf 1)
      else
	 sfto_sqfpartf addf(multf(!*k2f intern gensym(), lhs), negf 1);
      if !*rlverbose then ioto_prin2 "] ";
      return {e, geal, gral, (lhs . e) . neal}
   end;

asserted procedure ofsf_zerop1(f: SF, posp: Boolean): List;
   begin
      scalar one, fone, vl, w, flag, signfone, tryonesol;
      integer ofsf_anuc!*;
      if domainp f then
	 return if null f then
 	    '(1 (list (list) 0))
  	 else if minusf f then
	    {0, 'nd, {'list, {'list}, f}}
	 else
	    {0, {'list, {'list}, f}, 'pd};
      vl := sort(kernels f, 'ordop);
      {signfone, one, fone, tryonesol} := ofsf_zeropTryOne(f, vl);
      if eqn(signfone, 0) then
	 return tryonesol;
      if eqn(signfone, -1) then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is negative at (1, ..., 1), ",
	       "looking for a positive point of f"};
	 w := ofsf_zerop2(f, nil, posp);
	 flag := if w eq 'nd then 0 else if w eq 'failed then -1 else 1;
	 return {flag, w, {'list, one, fone}}
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ f is positive at (1, ..., 1), ",
	    "looking for a positive point of -f"};
      w := ofsf_zerop2(negf f, t, posp);
      flag := if w eq 'pd then 0 else if w eq 'failed then -1 else 1;
      return {flag, {'list, one, fone}, w}
   end;

asserted procedure ofsf_zeropTryOne(f: SF, vl: List): List4;
   if !*rltropilp or !*rltropint then
      ofsf_zeropTryOneInt(f, vl)
   else
      ofsf_zeropTryOneFloat(f, vl);

asserted procedure ofsf_zeropTryOneInt(f: SF, vl: List): List4;
   begin scalar one, fone;
      one := 'list . for each v in vl collect {'equal, v, 1};
      fone := subf(f, for each v in vl collect v . 1);
      if null numr fone then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is zero at (1, ..., 1)"};
	 return {0, one, fone, {1, {'list, one, 0}}}
      >>;
      return {sgn numr fone, one, prepsq fone, nil}
   end;

asserted procedure ofsf_zeropTryOneFloat(f: SF, vl: List): List4;
   begin scalar one, fone;
      one := 'list . for each v in vl collect {'equal, v, 1.0};
      fone := ofsf_fsubf(f, for each v in vl collect v . 1.0);
      if fone = 0.0 then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is zero at (1, ..., 1)"};
	 return {0, one, fone, {1, {'list, one, 0}}}
      >>;
      return {sgn fone, one, fone, nil}
   end;

asserted procedure ofsf_zerop2(f: SF, negp: Boolean, posp: Boolean): List;
   begin
      scalar monl, vl, status, dir, ev, nvar;
      integer  d;
      vl . monl := sfto_sf2monl f;
      d := length vl;
      if !*rlverbose then
      	 ioto_tprin2t {"+++ dimension: ", d};
      {status, dir, ev, nvar} := ofsf_posdirp(d, vl, monl, posp);
      if status eq 'infeasible then
	 return 'failed;
      if status eq 'definite then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ the ", if negp then "negated " else "",
 	       "polynomial is negative definite"};
	 return if negp then 'pd else 'nd
      >>;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found approximate direction of positive value: "};
	 mathprint('list . dir);
	 ioto_tprin2 {"+++ at point: "};
	 mathprint('list . for each v in vl collect {'equal, v, pop ev});
      >>;
      if !*rltropilp or !*rltropint then
 	 return ofsf_zeropLp1int(f, negp, d, vl, dir, nvar);
      return ofsf_zeropLp1float(f, negp, d, vl, dir, nvar)
   end;

asserted procedure ofsf_softnegp(vl: List, ev: List): ExtraBoolean;
   % Returns a variable with an odd corresponding exponent in [ev] or [nil].
   if ev then
      if not evenp car ev then
 	 car vl
      else
 	 ofsf_softnegp(cdr vl, cdr ev);

asserted procedure ofsf_posdirp(d: List, vl: List, monl: List, posp: Boolean): List4;
   begin scalar posl, snegl, hnegl, w, delposp; integer np, ns, nh;
      if !*rltropilp then
      	 lp_newmodel(1, d)
      else
      	 lp_newmodel(d+1, 0);
      for each pt in monl do
	 if !*rltropdel0 and ofsf_zerolistp car pt then <<
	    if !*rlverbose then
	       ioto_tprin2t "+++ deleting (0,...,0)";
	    delposp := cdr pt > 0
	 >> else if cdr pt > 0 then <<
	    posl := car pt . posl;
	    np := np + 1
	 >> else if ofsf_softnegp(vl, car pt) then <<
	    snegl := car pt . snegl;
	    ns := ns + 1
	 >> else <<
	    hnegl := car pt . hnegl;
	    nh := nh + 1
	 >>;
      if !*rlverbose then <<
	 ioto_tprin2 "+++ #points in the frame (+, soft -, hard -, all): ";
	 ioto_prin2t {np, ", ", ns, ", ", nh, ", ", np + ns + nh};
      	 ioto_tprin2 "+++ ";
	 ioto_prin2t lp_optaction()
      >>;
      if null posl and (posp or null snegl) and not delposp then
      	  return {'definite, nil, nil, nil};
      for each l in {posl, snegl, hnegl} do
      	 ofsf_addconstraints l;
      lp_updatemodel();
      w := ofsf_posdirp1(posl, np, d, vl, nil);
      if not posp and eqcar(w, 'infeasible) then <<
	 if !*rlverbose then
	    ioto_cterpri();
      	 w := ofsf_posdirp1(snegl, ns, d, vl, t)
      >>;
      lp_freemodel();
      return w
   end;

asserted procedure ofsf_zerolistp(l);
   null l or eqn(car l, 0) and ofsf_zerolistp cdr l;

asserted procedure ofsf_posdirp1(l: List, c: Integer, d: Integer, vl: List, snegp: Boolean): List4;
   begin scalar cnt, w, dir, ev; integer i;
      if null l then
	 return {'infeasible, nil, nil, nil};
      cnt := t; while cnt and l do <<
	 if !*rlverbose then <<
	    ioto_prin2 {"[", c, "] "};
	    c := c - 1
	 >>;
	 ev := pop l;
%% ev1 := copy ev;
%% mathprint reval ('times . for each v in vl join << ee := pop ev1; if ee neq 0 then {{'expt, v, ee}} >>);
	 lp_negconstr1();
	 w := lp_optimize();
	 if w neq 'infeasible then
	    cnt := nil
	 else <<
	    lp_delconstr1();
      	    lp_updatemodel()
	 >>
      >>;
      if w eq 'infeasible then
      	 return {'infeasible, nil, nil, nil};
      dir := {'equal, 'c, pop w} . for i := 1:d collect {'equal, mkid('n, i), pop w};
      return {'feasible, dir, ev, if snegp then ofsf_softnegp(vl, ev)}
   end;

asserted procedure ofsf_addconstraints(l: List);
   for each pt in l do
      lp_addconstraint('leq, (-1) . pt, -1);

asserted procedure ofsf_oddevp(ev: List): ExtraBoolean;
   ev and (not evenp car ev or ofsf_oddevp cdr ev);

asserted procedure ofsf_zeropLp1int(f: SF, negp: Boolean, d: Integer, vl: List, dirp: List, nvar: ExtraBoolean): List;
   begin scalar isol, fsol, sol, fval, v, inf; integer  pow, ee;
      dirp := ofsf_spoint2intpoint dirp;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ lifted to integers: "};
	 mathprint('list . dirp)
      >>;
      pop dirp;
      isol := for i := 1:d collect <<
	 v := pop vl;
	 ee := caddr pop dirp;
	 inf := if v eq nvar then
	    {'minus, {'expt, 'infinity, ee}}
	 else
	    {'expt, 'infinity, ee};
	 {'equal, v, inf}
      >>;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ modulo rounding errors there ",
	    "is a positive value at: "};
	 mathprint('list . isol)
      >>;
      fsol := subf(f, for each e in isol collect cadr e . caddr e);
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ ", if negp then "negated " else "",
 	    "polynomial at that infinite point: "};
	 mathprint prepsq fsol
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ realizing infinity by increasing powers of 2 ..."};
      pow . fval := ofsf_realizeinfinity fsol;
      sol := 'list . for each e in isol collect
	 {'equal, cadr e, prepsq subsq(simp caddr e, {'infinity . pow})};
      if negp then fval := negsq fval;
      return {'list, sol, prepsq fval}
   end;

asserted procedure ofsf_zeropLp1float(f: SF, negp: Boolean, d: Integer, vl: List, dirp: List, nvar: ExtraBoolean): List;
   begin scalar subl, scvl, val, pow, this, v, expo;
      if !*rlverbose then
	 ioto_tprin2t {"+++ realizing infinity by increasing powers of 2 ..."};
      repeat <<
	 pow := if null pow then 1.0 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 scvl := vl;
	 subl := for each e in cdr dirp collect <<
	    v := pop scvl;
	    expo := if eqcar(caddr e, 'minus) then - cadr caddr e else caddr e;
	    this := pow ^ expo;
	    if v eq nvar then this := -this;
	    v . this
	 >>;
	 val := ofsf_fsubf(f, subl)
      >> until val > 0;
      if negp then val := -val;
      return {'list, 'list . for each pr in subl collect {'equal, car pr, cdr pr}, val}
   end;

asserted procedure ofsf_fsubf(f: SF, subl: AList): Floating;
   if domainp f then
      f or 0
   else
      cdr atsoc(mvar f, subl)^ldeg f * ofsf_fsubf(lc f, subl) + ofsf_fsubf(red f, subl);

asserted procedure ofsf_spoint2intpoint(dirp: List): List;
   if !*rlgurobi then
      ofsf_fpoint2intpoint dirp
   else
      ofsf_rpoint2intpoint dirp;

asserted procedure ofsf_fpoint2intpoint(dirp: List): List;
   begin scalar res, w; integer g;
      res := car dirp . for each e in cdr dirp collect <<
	 w := fix(if !*rltropilp then
 	    caddr e
 	 else
 	    10^ofsf_lpsolprec!* * caddr e + 0.5 * sgn caddr e);
	 g := gcdn(g, w);
 	 {'equal, cadr e, w}
      >>;
      for each e in cdr res do
	 caddr e := caddr e / g;
      return res
   end;

asserted procedure ofsf_rpoint2intpoint(dirp: List): List;
   begin scalar res, w; integer g;
      res := car dirp . for each e in cdr dirp collect <<
	 w := simp caddr e;
	 g := gcdn(g, denr w);
 	 {'equal, cadr e, w}
      >>;
      g := !*f2q g;
      for each e in cdr res do
	 caddr e := sfto_sf2int numr multsq(caddr e, g);
      return res
   end;

asserted procedure ofsf_realizeinfinity(fsol: SQ): DottedPair;
   begin scalar val; integer pow;
      if minusf numr fsol then
	 rederr "negative lc - probably something wrong";
      repeat <<
	 pow := if eqn(pow, 0) then 1 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 val := subsq(fsol, {'infinity . pow})
      >> until numr val and numr val > 0;
      return pow . val
   end;

asserted procedure ofsf_zerosolve(g: SF, l: List): AList;
   % Returns (x_1 . anu_1, ..., x_n .  anu_n).
   %
   % g(p_1, ..., p_n) < 0 < g(q_1, ..., q_n)
   %
   % g(x_1, ..., x_n) = 0
   % x_1 = p_1 + Y * (q_1 - p_1)
   % ...
   % x_n = p_n + Y * (q_n - p_n)
   %
   begin
      scalar p, q, y, yq, subal, g0, g0ae, rl, res, x_i, p_i, q_i;
      assert(eqcar(l, 1));
      ofsf_anuc!* := 10000;
      p := cdr cadr cadr l;
      q := cdr cadr caddr l;
      y := !*a2k ofsf_genavar();
      yq := !*k2q y;
      subal := for each w in p collect <<
	 x_i := !*a2k cadr w;
	 p_i := simp caddr w;
	 q_i := simp caddr pop q;
	 x_i . addsq(p_i, multsq(yq, subtrsq(q_i, p_i)))
      >>;
      g0 := sfto_qsub(g, subal);
      assert(domainp denr g0);
      g0ae := aex_prpart aex_fromrp g0;
      rl := aex_findroots(g0ae, y);
      assert(rl);           % One ...
      assert(null cdr rl);  % and only one root.
      res := for each pr in subal collect
	 car pr . aex_bind(aex_fromsf cdr pr, y, car rl);
      return res
   end;

asserted procedure ofsf_zerosolve(g: SF, l: List): AList;
   % Returns (x_1 . anu_1, ..., x_n .  anu_n).
   %
   % g(p_1, ..., p_n) < 0 < g(q_1, ..., q_n)
   %
   % g(x_1, ..., x_n) = 0
   % x_1 = p_1 + Y * (q_1 - p_1)
   % ...
   % x_n = p_n + Y * (q_n - p_n)
   %
   begin
      scalar p, q, y, yq, subal, g0, g0ae, rl, res, x_i, p_i, q_i;
      assert(eqcar(l, 1));
      return ofsf_zeroapprox(g, l);
      p := cdr cadr cadr l;
      q := cdr cadr caddr l;
      yq := !*k2q ra_x();
      subal := for each w in p collect <<
	 x_i := !*a2k cadr w;
	 p_i := simp caddr w;
	 q_i := simp caddr pop q;
	 x_i . addsq(p_i, multsq(yq, subtrsq(q_i, p_i)))
      >>;
      g0 := sfto_qsub(g, subal);
      assert(domainp denr g0);
      on1 'ranum;
      rl := ra_isolate numr g0;
      off1 'ranum;
      assert(rl);           % One ...
      assert(null cdr rl);  % and only one root.
      res := for each pr in subal collect
	 car pr . aex_bind(aex_fromsf cdr pr, y, car rl);
      return res
   end;

asserted procedure ofsf_signatanuat(at: OfsfAtf, al: AList): OfsfAtf;
   begin scalar lhs;
      lhs := ofsf_lhs at;
   end;

put('zeroapprox, 'psopfn, 'ofsf_zeroapproxeval);

asserted procedure ofsf_zeroapproxeval(l: List): List;
   begin scalar f, zres; integer len, prec;
      len := length l;
      if len < 2 or len > 3 then
	 rederr "usage: zeroapprox(<polynomial>, <[p]zero result>, [precision])";
      f := numr simp pop l;
      zres := reval pop l;
      prec := if l then reval pop l;
      if null prec then
 	 prec := precision 0;
      if not numberp prec or prec < 8 then <<
	 lprim "specified precision not in {8, 9, ...} - using precision 8";
	 prec := 8
      >>;
      return ofsf_zeroapprox0(f, zres, prec)
   end;

asserted procedure ofsf_zeroapprox0(f: SF, l: List, prec: Integer): List;
   begin scalar oldprec, oldpprec, w;
      % need errorset here ... later ...
      oldprec := precision prec;
      oldpprec := getprintprecision();
      setprintprecision prec;
      setprintprecision prec;
      w := ofsf_zeroapprox(f, cdr l);
      precision oldprec;
      setprintprecision oldpprec;
      return nth(w, 3)
   end;

asserted procedure ofsf_zeroapprox(f: SF, l: List): List;
   begin scalar p1, p2, subal, f0, g, rl, zero, fzero;
      if !*rlverbose then <<
	 terpri();
	 terpri();
	 ioto_tprin2t {"+++ approximating zero, float precision is ", precision 0, " ..."}
      >>;
      if car l neq 1 then
	 return l;
      p1 := cdr cadr cadr l;   % positive point as a symbolic list of equations
      p2 := cdr cadr caddr l;  % negative point as a symbolic list of equations
      g := intern gensym();
      subal := for each e1 in p1 collect
	 cadr e1 . {'plus, caddr e1, {'times, g, {'plus, caddr pop p2, {'minus, caddr e1}}}};
      f0 := numr subf(f, subal);
      rl := ofsf_realrootswrap f0;
      zero := for each pr in subal collect
	 car pr . prepsq subsq(simp cdr pr, rl);
      fzero := prepsq subf(f, zero);
      zero := for each pr in zero collect
	 {'equal, car pr, cdr pr};
      return append(l, {{'list, 'list . zero, fzero}})
   end;

asserted procedure ofsf_realrootswrap(f: SF): List;
   begin scalar rl, w;
      rl := for each e in cdr realroots {prepf f} collect
 	 cadr e . caddr e;
      rl := for each pr in rl collect <<
	 w := numr simp cdr pr;
	 car pr . if rdp w  then prepf !*rd2rn w else w
      >>;
      return rl
   end;

algebraic procedure testpzerop(hu, sol);
   begin scalar w, subsol, foundsol, ok;
      ok := 1;
      for i := 2:length sol do <<
	 w := part(sol, i);
	 if w neq pd and w neq nd and w neq failed then <<
	    subsol := sub(part(w, 1), hu);
	    subsol := evalf subsol;
	    foundsol := part(w, 2);
	    w := evalf(foundsol - subsol);
	    if w neq 0 then <<
	       lisp lprim {"solution", i-1, "is not correct: difference is", w};
	       ok := 0
	    >>
      	 >>
      >>;
      return ok
   end;

endmodule;

end;  % of file
