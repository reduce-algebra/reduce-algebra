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

switch pzerochull;

switch pzeroaddzero;
on1 'pzeroaddzero;

switch pzeropint;
on1 'pzeropint;

switch pzerozero;
on1 'pzerozero;

put('pzerop, 'psopfn, 'ofsf_pzerop0);

asserted procedure ofsf_pzerop0(argl: List): List;
   begin integer f, vl, w;
      f := numr simp car argl;
      vl := kernels f;
      if null vl or null cdr vl then
	 rederr {car argl, "is not multivariate"};
      w := ofsf_pzerop f;
      if !*pzerozero and eqcar(w, 1) then
	 w := ofsf_pzerosolve(f, w);
      return 'list . w
   end;

asserted procedure ofsf_pzerop(f: SF): List;
   if !*pzerochull then
      ofsf_pzeropChull f
   else
      ofsf_pzeropLp f;

asserted procedure ofsf_pzeropChull(f: SF): List;
   begin
      scalar w, ww, vl, chl, m, c, posp, negp, resl, zero, monl;
      integer pn, nn;
      vl . w := sfto_sf2monl f;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ dimension: ", length vl};
	 for each pt in w do if cdr pt > 0 then
 	    pn := pn + 1
	 else if cdr pt < 0 then
	    nn := nn + 1;
	 ioto_tprin2t {"+++ #points in the frame (positive, negative, all): ",
 	    pn, ", ", nn, ", ", length w}
      >>;
      monl := for each mon in w collect car mon;
      if !*pzeroaddzero then <<
      	 zero := for each v in vl collect 0;
 	 if not member(zero, monl) then <<
	    if !*rlverbose then
	       ioto_tprin2t "+++ Adding zero";
	    ww := t;
	    monl := zero . monl
      	 >>
      >>;
      if !*rlverbose then
	 ioto_tprin2 "+++ computing convex hull ... ";
      chl := qhull_qhull monl;
      if !*rlverbose then
	 ioto_prin2t "done";
      if ww then <<
	 if !*rlverbose then
	    ioto_tprin2t "+++ Removing zero";
      	 chl := deletip(zero, chl)
      >>;
      if !*rlverbose then <<
	 pn := nn := 0;
	 for each pt in chl do if (ww := cdr assoc(pt, w)) > 0 then
 	    pn := pn + 1
	 else if ww < 0 then
	    nn := nn + 1;
	 ioto_tprin2t {"+++ #points in the Newton polytope (positive, negative, all): ",
	    pn, ", ", nn, ", ", length chl};
      >>;
      posp := negp := nil . nil;
      while chl and (posp = nil . nil or negp = nil . nil) do <<
	 m := assoc(pop chl, w);
	 assert(m);
	 c := cdr m;
	 if c > 0 and posp = nil . nil then
	    posp := m . ofsf_findDirectionLp(m, chl)
	 else if c < 0 and negp = nil . nil then <<
	    negp := m . ofsf_findDirectionLp(m, chl);
	 >>
      >>;
      resl := {'list, ofsf_pzerop!-mon2lp(vl, car negp), 'list . vl, 'list . cdr negp} . resl;
      resl := {'list, ofsf_pzerop!-mon2lp(vl, car posp), 'list . vl, 'list . cdr posp} . resl;
%%       if negp then
%% 	 resl := ofsf_pzerop!-mon2lp(vl, negp) . resl;
%%       if posp then
%% 	 resl := ofsf_pzerop!-mon2lp(vl, posp) . resl;
      return resl
   end;

asserted procedure ofsf_pzeropLp(f: SF): List;
   begin scalar one, fone, vl, w, flag, signfone, tryonesol;
      vl := kernels f;
      {signfone, one, fone, tryonesol} := ofsf_pzeroLpTryOne(f, vl);
      if eqn(signfone, 0) then
	 return tryonesol;
      if eqn(signfone, -1) then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ f is negative at (1, ..., 1), ",
	       "looking for a positive point of f"};
	 w := ofsf_pzeropLp1(f, nil);
	 flag := if w eq 'nd then 0 else if w eq 'failed then -1 else 1;
	 return {flag, w, {'list, one, fone}}
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++ f is positive at (1, ..., 1), ",
	    "looking for a positive point of -f"};
      w := ofsf_pzeropLp1(negf f, t);
      flag := if w eq 'pd then 0 else if w eq 'failed then -1 else 1;
      return {flag, {'list, one, fone}, w}
   end;

procedure ofsf_pzeroLpTryOne(f, vl);
   if !*pzeropint then
      ofsf_pzeroLpTryOneInt(f, vl)
   else
      ofsf_pzeroLpTryOneFloat(f, vl);

procedure ofsf_pzeroLpTryOneInt(f, vl);
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

procedure ofsf_pzeroLpTryOneFloat(f, vl);
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

asserted procedure ofsf_pzeropLp1(f: SF, negp: Boolean): List;
   begin scalar monl, vl, posp, ev, w; integer  d;
      vl . monl := sfto_sf2monl f;
      d := length vl;
      if !*rlverbose then
      	 ioto_tprin2t {"+++ dimension: ", d};
      posp . ev := ofsf_findposdirection monl;
      if null posp then <<
	 if !*rlverbose then
	    ioto_tprin2t {"+++ the ", if negp then "negated " else "",
 	       "polynomial is negative definite"};
	 return if negp then 'pd else 'nd
      >>;
      if posp eq 'infeasible then
	 return 'failed;
      if !*rlverbose then <<
	 ioto_tprin2 {"+++ found approximate direction of positive value: "};
	 mathprint('list . posp);
	 ioto_tprin2 {"+++ at point: "};
	 mathprint('list . for each v in vl collect {'equal, v, pop ev});
      >>;
      if !*pzeropint then
 	 return ofsf_pzeropLp1int(f, negp, d, vl, posp);
      return ofsf_pzeropLp1float(f, negp, d, vl, posp)
   end;

procedure ofsf_findposdirection(monl);
   begin scalar posl, negl, ev, posp, ml; integer c;
      for each pt in monl do <<
	 ml := car pt . ml;
 	 if cdr pt > 0 then
	    posl := car pt . posl
      	 else if cdr pt < 0 then
	    negl := car pt . negl
      >>;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ #points in the frame (positive, negative, all): ",
 	    c := length posl, ", ", length negl, ", ", length monl}
      >>;
      while posl do <<
	 if !*rlverbose then <<
	    ioto_prin2 {"[", c, "] "};
	    c := c - 1
	 >>;
	 ev := pop posl;
	 posp := ofsf_findDirectionLp(ev, ml);
	 if posp neq 'infeasible then
	    posl := nil
      >>;
      return posp . ev
   end;

asserted procedure ofsf_findDirectionLp(m: DottedPair, ml: List): List;
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

procedure ofsf_mklhs(d, ev, nl);
   begin scalar lhs;
      lhs := {{'minus, 'c}};
      for i := 1:d do <<
      	 lhs := {'times, sfto_int2sf pop ev, pop nl} . lhs
      >>;
      lhs := reval('plus . lhs);
      return lhs
   end;

switch rlgurobi;
on1 'rlgurobi;

asserted procedure ofsf_runsimplex(cl: List, vl: List, d: Integer): List;
   if !*rlgurobi then
      ofsf_rungurobi(cl, vl, d)
   else
      ofsf_runlinalg(cl, vl, d);

switch rllpkeepfiles;

asserted procedure ofsf_rungurobi(cl: List, vl: List, d: Integer): List;
   begin scalar bfn, lp, sol, log, cl, call, res;
      bfn := lto_sconcat {"/tmp/writelp-", getenv "USER", "-", lto_at2str random(2^16)};
      lp := lto_sconcat {bfn, ".lp"};
      sol := lto_sconcat {bfn, ".sol"};
      log := lto_sconcat {bfn, ".log"};
      ofsf_writeLp(lp, {'times, 0, 'c}, cl, vl);
      call := lto_sconcat {"gurobi_cl ResultFile=", sol, " ", lp, " &> ", log};
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

asserted procedure ofsf_pzeropLp1int(f: SF, negp: Boolean, d: Integer, vl: List, posp: List): List;
   begin scalar isol, fsol, sol, fval; integer  pow;
      posp := ofsf_spoint2intpoint posp;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ lifted to integers: "};
	 mathprint('list . posp)
      >>;
      pop posp;
      isol := for i := 1:d collect
	 {'equal, pop vl, {'expt, 'infinity, caddr pop posp}};
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
	 {'equal, cadr e, reval {'expt, pow, caddr caddr e}};
      if negp then fval := negsq fval;
      return {'list, sol, prepsq fval}
   end;

asserted procedure ofsf_pzeropLp1float(f: SF, negp: Boolean, d: Integer, vl: List, posp: List): List;
   begin scalar subl, scvl, val, pow;
      repeat <<
	 pow := if null pow then 1.0 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 scvl := vl;
	 subl := for each e in cdr posp collect
	    pop scvl . (pow^caddr e);
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

procedure ofsf_spoint2intpoint(posp);
   if !*rlgurobi then ofsf_fpoint2intpoint posp else ofsf_rpoint2intpoint posp;

procedure ofsf_rpoint2intpoint(posp);
   begin scalar res, w; integer g;
      res := car posp . for each e in cdr posp collect <<
	 w := simp caddr e;
	 g := gcdn(g, denr w);
 	 {'equal, cadr e, w}
      >>;
      g := !*f2q g;
      for each e in cdr res do
	 caddr e := sfto_sf2int numr multsq(caddr e, g);
      return res
   end;

procedure ofsf_fpoint2intpoint(posp);
   begin scalar res, w; integer g;
      res := car posp . for each e in cdr posp collect <<
	 w := fix(10^8 * caddr e + 0.5 * sgn caddr e);
	 g := gcdn(g, w);
 	 {'equal, cadr e, w}
      >>;
      for each e in cdr res do
	 caddr e := caddr e / g;
      return res
   end;

procedure ofsf_fpoint2intpoint_old(posp);
   begin scalar w; integer pden;
      posp := for each e in posp collect reval reval e;
      pden := 1;
      posp := car posp . for each e in cdr posp collect <<
	 w := simp caddr e;
	 pden := lcm(pden, denr w);
	 {'equal, cadr e, w}
      >>;
      pden := !*f2q pden;
      posp := car posp . for each e in cdr posp collect
 	 {'equal, cadr e, prepsq multsq(caddr e, pden)};
      return posp
   end;

procedure ofsf_realizeinfinity(fsol);
   begin scalar val; integer pow;
      if domainp numr fsol and minusf numr fsol or minusf lc numr fsol then
	 rederr "negative lc - probably something wrong";
      repeat <<
	 pow := if eqn(pow, 0) then 1 else pow * 2;
	 if !*rlverbose then
	    ioto_prin2 {"[", pow, "] "};
	 val := subsq(fsol, {'infinity . pow})
      >> until numr val and numr val > 0;
      return pow . val
   end;

asserted procedure ofsf_findDirection(m: DottedPair, ml: List): List;
   begin scalar cl, nl, c, ev, scnl, lhs, feas, point, phi; integer d;
      d := length car m;
      nl := for i := 1:d collect !*k2f mkid('n, i);
      c := addf(negf !*k2f 'c, 1);
      cl := for each mm in ml collect <<
	 ev := car mm;
	 lhs := c;
	 scnl := nl;
	 for i := 1:d do
	    lhs := addf(multf(pop scnl, sfto_int2sf pop ev), lhs);
	 if mm eq m then
	    ofsf_0mk2('equal, addf(lhs, negf 1))
 	 else
 	    ofsf_0mk2('leq, lhs)
      >>;
%%       for each n in nl do
%% 	 cl := ofsf_0mk2('neq, n) . cl;
      phi := cl_ex(rl_smkn('and, cl), nil);
      if !*rlverbose then
	 mathprint rl_prepfof phi;
      {feas, point} := car ofsf_qea(phi, nil) where !*rlqeaprecise=t, !*rlxopt=nil;
      assert(feas eq 'true);
      return point
   end;

procedure ofsf_writeLp(fn, obj, cl, vl);
   begin scalar fn, oldprtch, w, scsemic, oldecho, oldutf8, isfancy;
      oldprtch := get('times, 'prtch);
      put('times, 'prtch, '! );
      scsemic := semic!*;
      oldecho := !*echo;
      oldutf8 := !*utf8;
      isfancy := !*fancy;
      !*utf8 := nil;
      !*fancy := nil;
      out fn;
      w := errorset({'ofsf_writeLp1, mkquote obj, mkquote cl, mkquote vl}, nil, !*backtrace);
      shut fn;
      put('times, 'prtch, oldprtch);
      !*utf8 := oldutf8;
      !*echo := oldecho;
      semic!* := scsemic;
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

procedure ofsf_pzerop!-mon2lp(vl, pt);
   reval('times . cdr pt . for each d in car pt collect {'expt, pop vl, d});

asserted procedure ofsf_pzerosolve(f: SF, l: List): List;
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

procedure ofsf_tropsat(f);
   begin scalar w;
      w := ofsf_sat2pol f;
      w := ofsf_pzerop w;
      if eqcar(w, 1) then
	 return 'sat;
      if eqcar(w, 0) then
	 return 'unknown;  % unsat for positive variables
      if eqcar(w, -1) then
	 return 'unknown;
      rederr {"something wrong in ofsf_tropsat: ofsf_pzerop returned ", w}
   end;

fluid '(rlsat2polatnum!*);

procedure ofsf_sat2pol(f);
   begin scalar w; integer rlsat2polatnum!*;
      w := cl_simpl(cl_pnf f, nil, -1);
      rlsat2polatnum!* := cl_atnum f;
      return car ofsf_formula2pol1(w, nil, nil, nil)
   end;

procedure ofsf_formula2pol1(f, geal, gral, neal);
   begin scalar op, e, ee;
      op := rl_op f;
      if op eq 'or then <<
      	 e := 1;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal);
	    e := sfto_sqfpartf multf(ee, e)
      	 >>;
	 return {e, geal, gral, neal}
      >>;
      if op eq 'and then <<
	 e := nil;
	 for each a in rl_argn f do <<
	    {ee, geal, gral, neal} := ofsf_formula2pol1(a, geal, gral, neal);
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
	 return ofsf_geq2pol(ofsf_arg2l f, geal, gral, neal);
      if op eq 'leq then
	 return ofsf_geq2pol(negf ofsf_arg2l f, geal, gral, neal);
      if op eq 'greaterp then
	 return ofsf_greaterp2pol(ofsf_arg2l f, geal, gral, neal);
      if op eq 'lessp then
	 return ofsf_greaterp2pol(negf ofsf_arg2l f, geal, gral, neal);
      if op eq 'neq then
	 return ofsf_neq2pol(ofsf_arg2l f, geal, gral, neal);
      rederr {"something wrong in ofsf_formula2pol1: op =  ", op}
   end;

procedure ofsf_geq2pol(lhs, geal, gral, neal);
   begin scalar w, e;
      w := assoc(lhs, geal);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := sfto_sqfpartf addf(lhs, negf exptf(!*k2f intern gensym(), 2));
      if !*rlverbose then ioto_prin2 "] ";
      return {e, (lhs . e) . geal, gral, neal}
   end;

procedure ofsf_greaterp2pol(lhs, geal, gral, neal);
   begin scalar w, e;
      w := assoc(lhs, gral);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := sfto_sqfpartf addf(multf(exptf(!*k2f intern gensym(), 2), lhs), negf 1);
      if !*rlverbose then ioto_prin2 "] ";
      return {e, geal, (lhs . e) . gral, neal}
   end;

procedure ofsf_neq2pol(lhs, geal, gral, neal);
   begin scalar w, e;
      w := assoc(lhs, neal);
      if w then <<
	 if !*rlverbose then ioto_prin2 "!] ";
	 return {cdr w, geal, gral, neal}
      >>;
      e := sfto_sqfpartf addf(multf(!*k2f intern gensym(), lhs), negf 1);
      if !*rlverbose then ioto_prin2 "] ";
      return {e, geal, gral, (lhs . e) . neal}
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
