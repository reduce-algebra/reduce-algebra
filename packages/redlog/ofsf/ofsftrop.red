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

switch rlgurobi;   % use the Gurobi optimizer
off1 'rlgurobi;

switch rltropdel0; % delete the (0,...,0) monomial
on 'rltropdel0;

switch rltropilp;  % use ILP solving instead of LP solving with Gurobi
                   % ignore otherwise
on1 'rltropilp;

switch rltropsos;  % use sum of squares instead of sum for conjunctions
off1 'rltropsos;

switch rltroplcm;  % use lcm instead of product for disjunctions
on1 'rltroplcm;

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

asserted procedure ofsf_tropsat1(f: QfFormula, posp: Boolean): Id;
   begin scalar p, sol, vl, flag, one, other;
      p := ofsf_sat2pol1(f, posp);
      {flag, one, other} := ofsf_zerop1(p, posp);
      if eqn(flag, 1) then <<
	 if !*rlverbose then
 	    ioto_tprin2 "found candidate, solving ... ";
	 sol := car ofsf_zerosolve(p, car one, car other);
	 if !*rlverbose then
 	    ioto_prin2t "done";
	 vl := cl_fvarl1 f;
	 sol := for each pr in sol join if car pr memq vl then {pr};
	 % Evaluate f at sol
	 if !*rlverbose then
 	    ioto_prin2t "evaluating input formula at candidate solution";
	 return 'sat
      >>;
      if eqn(flag, 0) then
	 return 'unsat;
      if eqn(flag, -1) then
	 return 'unknown;
      rederr {"something wrong in ofsf_tropsat: ofsf_zerop1 returned ", flag}
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
	    e := addf(ee, e)
      	 >>;
	 e := sfto_sqfpartf e;
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

put('zerop, 'psopfn, 'ofsf_zeropeval);
put('pzerop, 'psopfn, 'ofsf_pzeropeval);

asserted procedure ofsf_zeropeval(argl: List): List;
   % psopfn AM entry point
   ofsf_zeropeval1(argl, nil);

asserted procedure ofsf_pzeropeval(argl: List): List;
   % psopfn AM entry point
   ofsf_zeropeval1(argl, t);

asserted procedure ofsf_zeropeval1(argl: List, posp: Boolean): List;
   begin scalar f, flag, one, other;
      f := numr simp car argl;
      {flag, one, other} := ofsf_zerop1(f, posp);
      if not eqn(flag, 1) then
      	 return {'list, flag};
      one := ofsf_s2aPointPair one;
      other := ofsf_s2aPointPair other;
      return {'list, flag, one, other}
   end;

asserted procedure ofsf_s2aPointPair(pp: List2): List2;
   {'list, ofsf_al2eql car pp, cadr pp};

asserted procedure ofsf_al2eql(al: AList): List;
   'list . for each pr in al collect {'equal, car pr, cdr pr};

asserted procedure ofsf_zerop(f: SF): List;
   % SM entry point
   ofsf_zerop1(f, nil);

asserted procedure ofsf_pzerop(f: SF): List;
   % SM entry point
   ofsf_zerop1(f, t);

asserted procedure ofsf_zerop1(f: SF, posp: Boolean): List3;
   % Returns (FLAG, ONE, OTHER). The semantics of FLAG is as follows:
   %
   % FLAG = -1: This incomplete method failed.
   % FLAG =  0: f has no (positive) zero.
   % FLAG >  0: f has at least one (positive) zero.
   % FLAG =  1: There is at least one (positive) zero.
   % FLAG =  2: f(1, ..., 1) = 0
   % FLAG =  3: f is positive definite (on the first hyper-octant).
   %
   % If FLAG = 1, then ONE = (1, ..., 1), f(1, ..., 1)) and OTHER = (p, f(p))
   % such that f(1, ..., 1) * f(p) < 0, i.e., OTHER is the witness for the
   % existence of a zero via the intermediate value theorem. All coordinates of
   % p are integer powers of 2. For all other values of FLAG we have ONE = OTHER
   % = nil.
   %
   begin scalar one, fone, other, vl; integer flag;
      if domainp f then
	 return if null f then
 	    '(1 nil nil)
 	 else if minusf f then
 	    '(0 nil nil)
	 else
 	    '(3 nil  nil);
      vl := sort(kernels f, 'ordop);
      {flag, one, fone} := ofsf_zeropTryOne(f, vl);
      if eqn(flag, 2) then
	 return '(2 nil nil);
      assert(flag = -1);
      {flag, other} := ofsf_zerop2(f, fone > 0, posp);
      if eqn(flag, -1) then
	 return '(-1 nil nil);
      if eqn(flag, 0) then
	 return '(0 nil nil);
      assert(flag = 1);
      return {1, {one, fone}, other}
   end;

asserted procedure ofsf_zeropTryOne(f: SF, vl: List): List3;
   % Returns (FLAG, ONE, FONE). The semantics of FLAG is as follows:
   %
   % FLAG = -1: f(1, ..., 1) <> 0
   % FLAG =  2: f(1, ..., 1) = 0
   %
   % If FLAG = -1, then ONE = (x_1 . 1, ..., x_n . 1) and FONE = f(1, ..., 1)).
   % Else ONE = FONE = nil.
   %
   begin scalar eins, one, fone;
      eins := if !*rltropilp then 1 else 1.0;
      one := for each v in vl collect v . eins;
      fone := sfto_sf2int sfto_floatsub(f, one);
      if eqn(fone, 0) then <<
	 if !*rlverbose then
 	    ioto_tprin2t {"+++ f is zero at (1, ..., 1)"};
	 return '(2 nil nil)
      >>;
      return {-1, one, fone}
   end;

asserted procedure ofsf_zerop2(f: SF, negatep: Boolean, posp: Boolean): List;
   % Returns (FLAG, OTHER). Define ff := if negatep then -f else f. The
   % semantics of FLAG is as follows:
   %
   % FLAG = -1: This incomplete method failed.
   % FLAG =  0: f has no (positive) zero.
   % FLAG =  1: We have found a point p such that ff(p) > 0.
   %
   % If FLAG = 1, then OTHER = (p, f(p)). Else OTHER = nil.
   %
   begin scalar ff, monl, vl, status, dir, ev, nvar; integer  d;
      if !*rlverbose then
	 ioto_tprin2t if negatep then
	    {"+++ f is positive at (1,...,1), looking for a positive point of -f"}
	 else
	    {"+++ f is negative at (1,...,1) looking for a positive point of f"};
      ff := if negatep then negf f else f;
      vl . monl := sfto_sf2monlip ff;
      d := length vl;
      if !*rlverbose then
      	 ioto_tprin2t {"+++ dimension: ", d};
      {status, dir, ev, nvar} := ofsf_posdirp(d, vl, monl, posp);
      if status eq 'definite then <<
	 % We did not find a coefficient in ff suitable for our purposes. In the
	 % posp case, this means that all coefficients are negative, and we may
	 % conclude that ff is negative definite on the first hyper-octant. In
	 % the general case, this means all coefficients negative and all
	 % degrees are even, and we may conclude that ff is negative definite.
	 % It follows that the original polynomial f is either positive or
	 % negative definite. In both variants our incomplete method was
	 % successful with a negative answer: we guarantee that there is no
	 % (positive) zero.
	 if !*rlverbose then
	    ioto_tprin2t {"+++ ", if negatep then "-" else "", "f is negative definite"};
	 return '(0 nil)
      >>;
      if status eq 'infeasible then
	 % There were suitable coefficients in the frame but none of them was in
	 % the Newton polytope. Thas is ILP solving returned "infeasible" for
	 % all of them. This is exactly where our incomplete method fails.
	 return '(-1 nil);
      return if !*rlgurobi and !*rltropilp then
 	 ofsf_zerop3i(ff, negatep, d, vl, ev, dir, nvar)
      else if !*rlgurobi then
 	 ofsf_zerop3f(ff, negatep, vl, ev, dir, nvar)
      else  % Reduce Simplex
	 ofsf_zerop3r(ff, negatep, d, vl, ev, dir, nvar)
   end;

asserted procedure ofsf_posdirp(d: List, vl: List, monl: List, posp: Boolean): List4;
   % Returns (FLAG, DIR, EV, NEVAR). We refer to exponent vector as points and
   % to the sign of a corresponding coefficient as the sign of the point. Then
   % the semantics of FLAG is as follows:
   %
   % FLAG =   definite: no positive (or weakly negative) point at all
   % FLAG = infeasible: no positive (or weakly negative) point in the Newton polytope.
   % FLAG =   feasible: We found a point with a suitable coefficient in the Newton polytope.
   %
   % If FLAG = feasible, then EV is the point, DIR is the normal vector of a
   % separating hyperplane for EV, given as a set of equations introducing
   % variables c, n_i. If we are not in the posp case, then NEVAR is one
   % variable whose corresponding exponent in EV is odd. If FLAG is in
   % {definite, infeasible}, then DIR = EV = NEVAR = nil.
   %
   begin scalar posl, snegl, hnegl, w, delposp; integer np, ns, nh;
      if !*rltropilp then
      	 lp_newmodel(1, d)
      else
      	 lp_newmodel(d+1, 0);
      for each pt in monl do
	 if !*rltropdel0 and lto_0listp car pt then <<
	    if !*rlverbose then
	       ioto_tprin2t "+++ deleting (0,...,0)";
	    delposp := cdr pt > 0
	 >> else if cdr pt > 0 then <<
	    posl := car pt . posl;
	    np := np + 1
	 >> else if not posp and ofsf_softnegp(vl, car pt) then <<
	    snegl := car pt . snegl;
	    ns := ns + 1
	 >> else <<
	    hnegl := car pt . hnegl;
	    nh := nh + 1
	 >>;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ number of points in the frame "};
	 if posp then
	     ioto_prin2 {"(+, -, all): ", np, ", ", nh, ", ", np + nh}
	 else
	    ioto_tprin2 {"(+, soft -, hard -, all): ", np, ", ", ns, ", ", nh, ", ", np + ns + nh};
      	 ioto_tprin2t {"+++ ", lp_optaction()}
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
      dir := ('c . pop w) . for i := 1:d collect mkid('n, i) . pop w;
      return {'feasible, dir, ev, if snegp then ofsf_softnegp(vl, ev)}
   end;

asserted procedure ofsf_softnegp(vl: List, ev: List): ExtraBoolean;
   % Returns a variable with an odd corresponding exponent in [ev] or [nil].
   if ev then
      if not evenp car ev then
 	 car vl
      else
 	 ofsf_softnegp(cdr vl, cdr ev);

asserted procedure ofsf_addconstraints(l: List);
   for each pt in l do
      lp_addconstraint('leq, (-1) . pt, -1);

asserted procedure ofsf_zerop3i(f: SF, negatep: Boolean, d: Integer, vl: List, ev: List, dirp: AList, nvar: ExtraBoolean): List;
   begin integer w, g;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found integer direction towards a positive value"};
	 mathprint ofsf_al2eql dirp;
	 ioto_tprin2t {"+++ at monomial: "};
	 mathprint('times . for each v in vl collect {'expt, v, pop ev});
      >>;
      dirp := car dirp . for each e in cdr dirp collect <<
	 w := fix cdr e;
	 g := gcdn(g, w);
 	 car e . w
      >>;
      for each e in cdr dirp do  % I have copied dirp right above
	 cdr e := cdr e / g;
      return ofsf_zerop4i(f, negatep, d, vl, dirp, nvar)
   end;

asserted procedure ofsf_zerop4i(f: SF, negatep: Boolean, d: Integer, vl: List, dirp: AList, nvar: ExtraBoolean): List;
   begin scalar v, isol, fsol, sol, fval, inf;
      pop dirp;
      isol := for i := 1:d collect <<
	 v := pop vl;
	 inf := sfto_mkpowq('infinity, cdr pop dirp);
	 v . if v eq nvar then negsq inf else inf
      >>;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ there is a positive value at: "};
	 mathprint ofsf_al2eql for each pr in isol collect car pr . prepsq cdr pr;
	 ioto_tprin2 {"+++ computing ", if negatep then "-" else "", "f at that nonstandard point ... "}
      >>;
      fsol := sfto_qsub(f, isol);
      if !*rlverbose then <<
	 ioto_prin2t "done:";
	 mathprint prepsq fsol;
	 ioto_tprin2 {"+++ realizing infinity by increasing powers of 2: "}
      >>;
      sol .  fval := ofsf_realizeinfinity(isol, fsol);
      if negatep then fval := negsq fval;
      return {1, {sol, prepsq fval}}
   end;

asserted procedure ofsf_realizeinfinity(isol: AList, fsol: SQ): DottedPair;
   begin scalar nfsol, nval, val, isubl, sol; integer pow;
      nfsol := numr fsol;
      if minusf nfsol then
	 rederr "negative lc - probably something wrong";
      repeat <<
	 pow := if eqn(pow, 0) then 1 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
      	 isubl := {'infinity . pow};
	 nval := sfto_fsub(nfsol, isubl)
      >> until nval and nval > 0;
      ioto_cterpri();
      val := quotsq(!*f2q nval, !*f2q sfto_fsub(denr fsol, isubl));
      sol := for each e in isol collect
	 car e . prepsq sfto_fsubq(cdr e, isubl);
      return sol . val
   end;

asserted procedure ofsf_zerop3f(f: SF, negatep: Boolean, vl: List, ev: List, dirp: List, nvar: ExtraBoolean): List;
   begin scalar subl, scvl, val, pow, this, v, isol;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found approximate direction towards a positive value"};
	 mathprint ofsf_al2eql dirp;
	 ioto_tprin2t {"+++ at monomial: "};
	 mathprint('times . for each v in vl collect {'expt, v, pop ev});
      	 isol := 'list . for each pr in cdr dirp collect {'expt, 'infinity, cdr pr};
	 ioto_tprin2t {"+++ modulo rounding errors there is a positive value at: "};
	 mathprint isol;
	 ioto_tprin2t {"+++ realizing infinity by increasing powers of 2 ..."}
      >>;
      repeat <<
	 pow := if null pow then 1.0 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 scvl := vl;
	 subl := for each e in cdr dirp collect <<
	    v := pop scvl;
	    this := pow ^ cdr e;
	    v . if v eq nvar then -this else this
	 >>;
	 val := sfto_floatsub(f, subl)
      >> until val > 0;
      ioto_cterpri();
      if negatep then val := -val;
      return {1, {subl, val}}
   end;

asserted procedure ofsf_zerop3r(f: SF, negatep: Boolean, d: Integer, vl: List, ev: List, dirp: AList, nvar: ExtraBoolean): List;
   begin integer w, l;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found rational direction towards a positive value"};
	 mathprint ofsf_al2eql dirp;
	 ioto_tprin2t {"+++ at monomial: "};
	 mathprint('times . for each v in vl collect {'expt, v, pop ev});
      >>;
      l := 1;
      dirp := car dirp . for each pr in cdr dirp collect <<
	 w := simp cdr pr;
	 l := lcmn(l, denr w);
 	 car pr . w
      >>;
      l := !*f2q l;
      for each pr in cdr dirp do  % I have copied dirp right above
	 cdr pr := sfto_sf2int numr multsq(cdr pr, l);
      return ofsf_zerop4i(f, negatep, d, vl, dirp, nvar)
   end;

put('zerosolve, 'psopfn, 'ofsf_zerosolveeval);

asserted procedure ofsf_zerosolveeval(l: List): List;
   begin scalar f, zres, zero, gzero, p, q; integer len;
      len := length l;
      if not eqn(len, 2) then
	 rederr "usage: zerosolve(<polynomial>, <[p]zero result>)";
      f := numr simp pop l;
      zres := cdr reval pop l;
      if not eqcar(zres, 1) then
	 rederr {"second argument is not of a solvable type"};
      % extract points as alists:
      p := for each ee in cdr cadr cadr zres collect
 	 cadr ee . caddr ee;
      q := for each ee in cdr cadr caddr zres collect
  	 cadr ee . caddr ee;
      zero . gzero := ofsf_zerosolve(f, p, q);
      zero := for each pr in zero collect
	 {'equal, car pr, mk!*sq cdr pr};
      return {'list, 'list . zero, mk!*sq gzero}
   end;

asserted procedure ofsf_zerosolve(g: SF, p: AList, q: AList): DottedPair;
   %
   % g(p_1, ..., p_n) < 0 < g(q_1, ..., q_n)
   %
   % g(x_1, ..., x_n) = 0
   % x_1 = p_1 + Y * (q_1 - p_1)
   % ...
   % x_n = p_n + Y * (q_n - p_n), Y in [0,1]
   %
   begin
      scalar y, yq, subal, g0, rl, ral, x_i, p_i, q_i, zero, w, val, precq, gzero, floatzero;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ computing zero, precision is ", precision 0, " ..."};
	 ioto_tprin2t {"******************************************************************"};
	 ioto_tprin2t {"* Intervals of algebraic numbers are refined and printed to the  *"};
	 ioto_tprin2t {"* current precision of the rounded domain. The returned function *"};
	 ioto_tprin2t {"* value is the value at the lower bounds of the intervals;       *"};
	 ioto_tprin2t {"* substituion of the actual algebraic numbers into the original  *"};
	 ioto_tprin2t {"* polynomial is not feasible at present.                         *"};
	 ioto_tprin2t {"******************************************************************"}
      >>;
      y := ra_x();
      yq := !*f2q !*k2f y;
      subal := for each w in p collect <<
	 x_i := !*a2k car w;
	 p_i := simp cdr w;
	 q_i := simp cdr pop q;
	 x_i . addsq(p_i, multsq(yq, subtrsq(q_i, p_i)))
      >>;
      g0 := sfto_qsub(g, subal);
      assert(domainp denr g0);
      on1 'ranum;
      rl := ra_isolate(numr g0, nil ./ 1, 1 ./ 1);
      if !*rlverbose then
	 ioto_tprin2t {"+++ found ", length rl, " zero", if cdr rl then "s" else "", " on the relevant line segment"};
      if null rl then
	 rederr {"severe error - no zero on the relevant line segement"};
      ral := {y . car rl};
      precq := 1 ./ 10 ^ (precision 0 + 2);
      zero := for each pr in subal collect <<
	 w := quotsq(!*f2q sfto_fsub(numr cdr pr, ral), !*f2q denr cdr pr);
	 assert(eqn(denr(w, 1)));
	 val := numr w;
	 if val and not numberp val then
	    while sfto_geqq(subtrsq(ra_u val, ra_l val), precq) do
	       val := ra_refine(val,1);
	 car pr . (val ./ 1)
      >>;
      off1 'ranum;
      % Here using rounded instead of rationals seems to be faster by a factor
      % of two:
      on1 'rounded;
      floatzero := for each pr in zero collect
	 car pr . numr resimp if null numr cdr pr or numberp numr cdr pr then
 	    cdr pr
 	 else
 	    ra_l numr cdr pr;
      gzero := !*f2q sfto_fsub(g, floatzero);
      off rounded;
      return zero . gzero
   end;

put('zeroapprox, 'psopfn, 'ofsf_zeroapproxeval);

asserted procedure ofsf_zeroapproxeval(l: List): List;
   begin scalar f, zres, zero, gzero, p, q; integer len;
      len := length l;
      if not eqn(len, 2) then
	 rederr "usage: zeroapprox(<polynomial>, <[p]zero result>)";
      f := numr simp pop l;
      zres := cdr reval pop l;
      if not eqcar(zres, 1) then
	 rederr {"second argument is not of a solvable type"};
      % extract points as alists:
      p := for each ee in cdr cadr cadr zres collect
 	 cadr ee . caddr ee;
      q := for each ee in cdr cadr caddr zres collect
  	 cadr ee . caddr ee;
      zero . gzero := ofsf_zeroapprox(f, p, q);
      zero := for each pr in zero collect
	 {'equal, car pr, mk!*sq cdr pr};
      return {'list, 'list . zero, mk!*sq gzero}
   end;

asserted procedure ofsf_zeroapprox(g: SF, p: AList, q: AList): DottedPair;
   begin scalar subal, x_i, p_i, q_i, g0, y, yq, w, rl, ral, zero, gzero;
      if !*rlverbose then
	 ioto_tprin2t {"+++ approximating zero, float precision is ", precision 0, " ..."};
      y := intern gensym();
      yq := !*f2q !*k2f y;
      subal := for each w in p collect <<
	 x_i := !*a2k car w;
	 p_i := simp cdr w;
	 q_i := simp cdr pop q;
	 x_i . addsq(p_i, multsq(yq, subtrsq(q_i, p_i)))
      >>;
      g0 := sfto_qsub(g, subal);
      assert(domainp denr g0);
      rl := ofsf_realrootswrap1 numr g0;
      on1 'rounded;
      if !*rlverbose then
	 ioto_tprin2t {"+++ found ", length rl, " zero", if cdr rl then "s" else "", " on the relevant line segment"};
      if null rl then
	 rederr {"severe error - no zero on the relevant line segement"};
      ral := {car rl};
      zero := for each pr in subal collect
	 car pr . quotsq(!*f2q sfto_fsub(numr cdr pr, ral), !*f2q denr cdr pr);
      gzero := sfto_qsub(g, zero);
      off1 'rounded;
      return zero . gzero
   end;

asserted procedure ofsf_realrootswrap(f: SF): List;
   for each pr in ofsf_realrootswrap1 f collect
      if rdp cdr pr then car pr . prepf !*rd2rn cdr pr else pr;

asserted procedure ofsf_realrootswrap1(f: SF): List;
   % The result is an Alist (... (kernel .  solution) ...), where the solution
   % is in the :rn: domain.
   for each e in cdr realroots {prepf f, 0, 1} collect
      cadr e . numr simp caddr e;

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
