% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2013 T. Sturm
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

fluid '(rlsat2polatnum!*);

switch zeropaddzero;
on1 'zeropaddzero;

switch zeropint;
on1 'zeropint;

switch zeropzero;
on1 'zeropzero;

switch rlgurobi;
on1 'rlgurobi;

switch rllpkeepfiles;

% Entry points.

put('zerop, 'psopfn, 'ofsf_zerop0);
put('pzerop, 'psopfn, 'ofsf_pzerop0);

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

asserted procedure ofsf_zerop0(argl: List): List;
   % psopfn AM entry point
   ofsf_zerop1(argl, nil);

asserted procedure ofsf_pzerop0(argl: List): List;
   % psopfn AM entry point
   ofsf_zerop1(argl, t);

asserted procedure ofsf_zerop(f: SF): List;
   % SM entry point
   ofsf_zeropLp(f, nil);

asserted procedure ofsf_pzerop(f: SF): List;
   % SM entry point
   ofsf_zeropLp(f, t);

asserted procedure ofsf_tropsat1(f: QfFormula, posp: Boolean): Id;
   begin scalar w;
      w := ofsf_sat2pol1(f, posp);
      w := ofsf_zeropLp(w, posp);
      if eqcar(w, 1) then
	 return 'sat;
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
      op := rl_op f;
      if op eq 'or then <<
      	 e := 1;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal, posp);
	    e := sfto_sqfpartf multf(ee, e)
      	 >>;
	 return {e, geal, gral, neal}
      >>;
      if op eq 'and then <<
	 e := nil;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal, posp);
	    e := addf(exptf(ee, 2), e)
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

asserted procedure ofsf_zerop1(argl: List, posp: Boolean): List;
   begin integer f, vl, w;
      f := numr simp car argl;
      vl := sort(kernels f, 'ordop);
      if null vl or null cdr vl then
	 rederr {car argl, "is not multivariate"};
      w := ofsf_zeropLp(f, posp);
      if !*zeropzero and eqcar(w, 1) then
	 w := ofsf_zerosolve(f, w);
      return 'list . w
   end;

asserted procedure ofsf_zeropLp(f: SF, posp: Boolean): List;
   begin scalar one, fone, vl, w, flag, signfone, tryonesol;
      vl := sort(kernels f, 'ordop);
      {signfone, one, fone, tryonesol} := ofsf_zeroLpTryOne(f, vl);
      if eqn(signfone, 0) then
	 return tryonesol;
      if eqn(signfone, -1) then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is negative at (1, ..., 1), ",
	       "looking for a positive point of f"};
	 w := ofsf_zeropLp1(f, nil, posp);
	 flag := if w eq 'nd then 0 else if w eq 'failed then -1 else 1;
	 return {flag, w, {'list, one, fone}}
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ f is positive at (1, ..., 1), ",
	    "looking for a positive point of -f"};
      w := ofsf_zeropLp1(negf f, t, posp);
      flag := if w eq 'pd then 0 else if w eq 'failed then -1 else 1;
      return {flag, {'list, one, fone}, w}
   end;

asserted procedure ofsf_zeroLpTryOne(f: SF, vl: List): List4;
   if !*zeropint then
      ofsf_zeroLpTryOneInt(f, vl)
   else
      ofsf_zeroLpTryOneFloat(f, vl);

asserted procedure ofsf_zeroLpTryOneInt(f: SF, vl: List): List4;
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

asserted procedure ofsf_zeroLpTryOneFloat(f: SF, vl: List): List4;
   begin scalar one, fone;
      one := 'list . for each v in vl collect {'equal, v, 1.0};
      fone := ofsf_fsubf(f, for each v in vl collect v . 1.0);
      if fone = 0 then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is zero at (1, ..., 1)"};
	 return {0, one, fone, {1, {'list, one, 0}}}
      >>;
      return {sgn fone, one, fone, nil}
   end;

asserted procedure ofsf_zeropLp1(f: SF, negp: Boolean, posp: Boolean): List;
   begin scalar monl, vl, dirp, ev, nvar; integer  d;
      vl . monl := sfto_sf2monl f;
      d := length vl;
      if !*rlverbose then
      	 ioto_tprin2t {"+++ dimension: ", d};
      dirp . ev := ofsf_findPosDirectionLp(vl, monl, posp);
      if not posp then
      	 nvar := ofsf_softnegp(vl, ev);
      if null dirp then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ the ", if negp then "negated " else "",
 	       "polynomial is negative definite"};
	 return if negp then 'pd else 'nd
      >>;
      if dirp eq 'infeasible then
	 return 'failed;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found approximate direction of positive value: "};
	 mathprint('list . dirp);
	 ioto_tprin2 {"+++ at point: "};
	 mathprint('list . for each v in vl collect {'equal, v, pop ev});
      >>;
      if !*zeropint then
 	 return ofsf_zeropLp1int(f, negp, d, vl, dirp, nvar);
      return ofsf_zeropLp1float(f, negp, d, vl, dirp, nvar)
   end;

procedure ofsf_softnegp(vl, ev);
   if ev then
      if not evenp car ev then
 	 car vl
      else
 	 ofsf_softnegp(cdr vl, cdr ev);

asserted procedure ofsf_findPosDirectionLp(vl: List, monl: List, posp: Boolean): DottedPair;
   if posp then
      ofsf_pfindPosDirectionLp1(vl, monl)
   else
      ofsf_findPosDirectionLp1(vl, monl);

asserted procedure ofsf_findPosDirectionLp1(vl: List, monl: List): DottedPair;
   begin scalar posl, onegl, negl, ev, dirp, ml; integer c1, c2;
      for each pt in monl do <<
	 ml := car pt . ml;
 	 if cdr pt > 0 then
	    posl := car pt . posl
	 else if ofsf_softnegp(vl, car pt) then
	    onegl := car pt . onegl
      	 else
	    negl := car pt . negl
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ #points in the frame (positive, soft negative, negative, all): ",
 	    c1 := length posl, ", ", c2 := length onegl, ", ",
 	    length negl, ", ", length monl};
      dirp . ev := ofsf_findDirectionLpLoop(ml, posl, c1);
      if dirp and dirp neq 'infeasible then
      	 return dirp . ev;
      return ofsf_findDirectionLpLoop(ml, onegl, c2)
   end;

asserted procedure ofsf_oddevp(ev: List): ExtraBoolean;
   ev and (not evenp car ev or ofsf_oddevp cdr ev);

asserted procedure ofsf_findDirectionLpLoop(ml, l, c): DottedPair;
   begin scalar ev, dirp;
      while l do <<
	 if !*rlverbose then <<
	    ioto_prin2 {"[", c, "] "};
	    c := c - 1
	 >>;
	 ev := pop l;
	 dirp := ofsf_findDirectionLp(ev, ml);
	 if dirp neq 'infeasible then
	    l := nil
      >>;
      return dirp . ev
   end;

asserted procedure ofsf_pfindPosDirectionLp1(vl: List, monl: List): DottedPair;
   begin scalar posl, negl, ml; integer c;
      for each pt in monl do <<
	 ml := car pt . ml;
 	 if cdr pt > 0 then
	    posl := car pt . posl
      	 else if cdr pt < 0 then
	    negl := car pt . negl
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ #points in the frame (positive, negative, all): ",
 	    c := length posl, ", ", length negl, ", ", length monl};
      return ofsf_findDirectionLpLoop(ml, posl, c)
   end;

asserted procedure ofsf_findDirectionLp(m: List, ml: List): List;
   begin scalar cl, nl, ev, res; integer d;
      d := length m;
      nl := for i := 1:d collect mkid('n, i);
      cl := for each ev in ml join
	 if ev neq m then
	    {{'leq, ofsf_mklhs(d, ev, nl), -1}};
      cl := {'equal, ofsf_mklhs(d, m, nl), 0} . cl;
      res := ofsf_runsimplex(cl, 'c . nl, d + 1);
      return res
   end;

asserted procedure ofsf_mklhs(d: Integer, ev: List, nl: List): List;
   begin scalar lhs;
      lhs := {{'minus, 'c}};
      for i := 1:d do <<
      	 lhs := {'times, sfto_int2sf pop ev, pop nl} . lhs
      >>;
      lhs := reval('plus . lhs);
      return lhs
   end;

asserted procedure ofsf_runsimplex(cl: List, vl: List, d: Integer): List;
   if !*rlgurobi then
      ofsf_rungurobi(cl, vl, d)
   else
      ofsf_runlinalg(cl, vl, d);

asserted procedure ofsf_rungurobi(cl: List, vl: List, d: Integer): List;
   begin scalar bfn, lp, sol, log, cl, call, res;
      bfn := lto_sconcat {"/tmp/writelp-", getenv "USER", "-", lto_at2str random(2^16)};
      lp := lto_sconcat {bfn, ".lp"};
      sol := lto_sconcat {bfn, ".sol"};
      log := lto_sconcat {bfn, ".log"};
      ofsf_writeLp(lp, {'times, 0, 'c}, cl, vl);
      call := lto_sconcat {"gurobi_cl ResultFile=", sol, " ", lp, " > ", log};
      system call;
      res := ofsf_readLpSol(sol, d);
      if not !*rllpkeepfiles then
	 for each fn in {lp, sol, log} do
	    system lto_sconcat {"rm -f ", fn};
      return res
   end;

asserted procedure ofsf_runlinalg(cl: List, vl: List, d: Integer): List;
   begin scalar w, bounds;
      bounds := for each v in vl collect v . '((minus infinity) infinity);
      w := fs_simplex2('min, sc_simp 0, cl, bounds);
      if w eq 'infeasible then
	 return 'infeasible;
      return cdr w
   end;

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
   begin scalar subl, scvl, val, pow, v, p;
      repeat <<
	 pow := if null pow then 1.0 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 scvl := vl;
	 subl := for each e in cdr dirp collect <<
	    v := pop scvl;
	    pow := if v eq nvar then -pow else pow;
	    v . (p^caddr e)
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
   if !*rlgurobi then ofsf_fpoint2intpoint dirp else ofsf_rpoint2intpoint dirp;

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

asserted procedure ofsf_fpoint2intpoint(dirp: List): List;
   begin scalar res, w; integer g;
      res := car dirp . for each e in cdr dirp collect <<
	 w := fix(10^8 * caddr e + 0.5 * sgn caddr e);
	 g := gcdn(g, w);
 	 {'equal, cadr e, w}
      >>;
      for each e in cdr res do
	 caddr e := caddr e / g;
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

procedure ofsf_writeLp(fn, obj, cl, vl);
   begin scalar fn, oldprtch, w, scsemic, oldecho, oldutf8, isfancy;
      oldprtch := get('times, 'prtch);
      put('times, 'prtch, '! );
      scsemic := semic!*;
      oldecho := !*echo;
      oldutf8 := !*utf8;
      isfancy := !*fancy;
      !*echo := nil;
      !*utf8 := nil;
      !*fancy := nil;
      out fn;
      w := errorset({'ofsf_writeLp1, mkquote obj, mkquote cl, mkquote vl}, nil, !*backtrace);
      shut fn;
      !*fancy := isfancy;
      !*utf8 := oldutf8;
      !*echo := oldecho;
      semic!* := scsemic;
      put('times, 'prtch, oldprtch);
      if errorp w then
	 rederr car w;
   end;

procedure ofsf_writeLp1(obj, cl, vl);
   <<
      prin2!* "Minimize";
      terpri!* nil;
      maprin obj;
      terpri!* nil;
      prin2!* "Subject To";
      terpri!* nil;
      for each c in cl do <<
	 maprin c;
	 terpri!* nil
      >>;
      prin2!* "Bounds";
      terpri!* nil;
      for each v in vl do <<
	 maprin {'geq, v, '!-Inf};
      	 terpri!* nil
      >>;
      prin2!* "End";
      terpri!* nil
   >>;

procedure ofsf_readLpSol(fn, d);
   begin scalar ch, tok, ni, res;
      ch := open(fn, 'input);
      rds ch;
      tok := read();
      if tok neq '!# then <<
	 rds nil;
	 close ch;
	 return 'infeasible
      >>;
      repeat tok := read() until tok = 0;
      res := for i := 1:d collect
	 read() . read();
      rds nil;
      close ch;
      res := {'equal, 'c, cdr atsoc('c, res)} . for i := 1:d-1 collect <<
	 ni := mkid('n, i);
	 {'equal, ni, cdr atsoc(ni, res)}
      >>;
      return res
   end;

asserted procedure ofsf_zerosolve(f: SF, l: List): List;
   begin scalar p1, p2, subal, f0, g, rl, zero, fzero;
      if !*rlverbose then <<
	 terpri();
	 terpri();
	 ioto_tprin2t {"+++ approximating zero, float precision is ", precision 0, " ..."}
      >>;
      if car l neq 1 then
	 return l;
      p1 := cdr cadr cadr l;
      p2 := cdr cadr caddr l;
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

procedure ofsf_realrootswrap(f);
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


% % Lecacy code below here

% switch pzerochull;

% asserted procedure ofsf_pzeropChull(f: SF): List;
%    begin
%       scalar w, ww, vl, chl, m, c, posp, negp, resl, zero, monl;
%       integer pn, nn;
%       vl . w := sfto_sf2monl f;
%       if !*rlverbose then <<
% 	 ioto_tprin2t {"+++ dimension: ", length vl};
% 	 for each pt in w do if cdr pt > 0 then
%  	    pn := pn + 1
% 	 else if cdr pt < 0 then
% 	    nn := nn + 1;
% 	 ioto_tprin2t {"+++ #points in the frame (positive, negative, all): ",
%  	    pn, ", ", nn, ", ", length w}
%       >>;
%       monl := for each mon in w collect car mon;
%       if !*zeropaddzero then <<
%       	 zero := for each v in vl collect 0;
%  	 if not member(zero, monl) then <<
% 	    if !*rlverbose then
% 	       ioto_tprin2t "+++ Adding zero";
% 	    ww := t;
% 	    monl := zero . monl
%       	 >>
%       >>;
%       if !*rlverbose then
% 	 ioto_tprin2 "+++ computing convex hull ... ";
%       chl := qhull_qhull monl;
%       if !*rlverbose then
% 	 ioto_prin2t "done";
%       if ww then <<
% 	 if !*rlverbose then
% 	    ioto_tprin2t "+++ Removing zero";
%       	 chl := deletip(zero, chl)
%       >>;
%       if !*rlverbose then <<
% 	 pn := nn := 0;
% 	 for each pt in chl do if (ww := cdr assoc(pt, w)) > 0 then
%  	    pn := pn + 1
% 	 else if ww < 0 then
% 	    nn := nn + 1;
% 	 ioto_tprin2t {"+++ #points in the Newton polytope (positive, negative, all): ",
% 	    pn, ", ", nn, ", ", length chl};
%       >>;
%       posp := negp := nil . nil;
%       while chl and (posp = nil . nil or negp = nil . nil) do <<
% 	 m := assoc(pop chl, w);
% 	 assert(m);
% 	 c := cdr m;
% 	 if c > 0 and posp = nil . nil then
% 	    posp := m . ofsf_findDirectionLp(m, chl)
% 	 else if c < 0 and negp = nil . nil then <<
% 	    negp := m . ofsf_findDirectionLp(m, chl);
% 	 >>
%       >>;
%       resl := {'list, ofsf_pzerop!-mon2lp(vl, car negp), 'list . vl, 'list . cdr negp} . resl;
%       resl := {'list, ofsf_pzerop!-mon2lp(vl, car posp), 'list . vl, 'list . cdr posp} . resl;
%       if negp then
% 	 resl := ofsf_pzerop!-mon2lp(vl, negp) . resl;
%       if posp then
% 	 resl := ofsf_pzerop!-mon2lp(vl, posp) . resl;
%       return resl
%    end;

% procedure ofsf_pzerop!-mon2lp(vl, pt);
%    reval('times . cdr pt . for each d in car pt collect {'expt, pop vl, d});

%% procedure ofsf_fpoint2intpoint_old(posp);
%%    begin scalar w; integer pden;
%%       posp := for each e in posp collect reval reval e;
%%       pden := 1;
%%       posp := car posp . for each e in cdr posp collect <<
%% 	 w := simp caddr e;
%% 	 pden := lcm(pden, denr w);
%% 	 {'equal, cadr e, w}
%%       >>;
%%       pden := !*f2q pden;
%%       posp := car posp . for each e in cdr posp collect
%%  	 {'equal, cadr e, prepsq multsq(caddr e, pden)};
%%       return posp
%%    end;%% asserted procedure ofsf_findDirection(m: DottedPair, ml: List): List;
%%    begin scalar cl, nl, c, ev, scnl, lhs, feas, point, phi; integer d;
%%       d := length car m;
%%       nl := for i := 1:d collect !*k2f mkid('n, i);
%%       c := addf(negf !*k2f 'c, 1);
%%       cl := for each mm in ml collect <<
%% 	 ev := car mm;
%% 	 lhs := c;
%% 	 scnl := nl;
%% 	 for i := 1:d do
%% 	    lhs := addf(multf(pop scnl, sfto_int2sf pop ev), lhs);
%% 	 if mm eq m then
%% 	    ofsf_0mk2('equal, addf(lhs, negf 1))
%%  	 else
%%  	    ofsf_0mk2('leq, lhs)
%%       >>;
%% %%       for each n in nl do
%% %% 	 cl := ofsf_0mk2('neq, n) . cl;
%%       phi := cl_ex(rl_smkn('and, cl), nil);
%%       if !*rlverbose then
%% 	 mathprint rl_prepfof phi;
%%       {feas, point} := car ofsf_qea(phi, nil) where !*rlqeaprecise=t, !*rlxopt=nil;
%%       assert(feas eq 'true);
%%       return point
%%    end;

endmodule;

end;  % of file
