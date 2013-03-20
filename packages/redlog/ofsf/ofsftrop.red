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

put('pzerop, 'psopfn, 'ofsf_pzerop0);

asserted procedure ofsf_pzerop0(argl: List): List;
   begin integer f, vl;
      f := numr simp car argl;
      vl := kernels f;
      if null vl or null cdr vl then
	 rederr {car argl, "is not multivariate"};
      return 'list . ofsf_pzerop f
   end;
%%    begin scalar pl, vl;
%%       vl . pl := ofsf_pzerop(numr simp car argl);
%%       return {'list,
%% 	 'list . vl,
%% 	 'list .  for each mon in pl collect
%%  	    {'list, 'list . car mon or 0, cadr mon}}
%%    end;

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
   begin scalar monl, vl, posp; integer  d;
      vl . monl := sfto_sf2monl f;
      d := length vl;
      if !*rlverbose then
      	 ioto_tprin2t {"+++ dimension: ", d};
      posp := ofsf_findposdirection monl;
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
	 mathprint('list . posp)
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
      return posp
   end;

switch rllpkeepfiles;

asserted procedure ofsf_findDirectionLp(m: DottedPair, ml: List): List;
   begin scalar bfn, lp, sol, log, cl, nl, ev, call, res; integer d;
      d := length m;
      nl := for i := 1:d collect mkid('n, i);
      cl := for each ev in ml join
	 if ev neq m then
	    {{'leq, ofsf_mklhs(d, ev, nl), -1}};
      cl := {'equal, ofsf_mklhs(d, m, nl), 0} . cl;
      bfn := lto_sconcat {"/tmp/writelp-", getenv "USER", "-", lto_at2str random(2^16)};
      lp := lto_sconcat {bfn, ".lp"};
      sol := lto_sconcat {bfn, ".sol"};
      log := lto_sconcat {bfn, ".log"};
      ofsf_writeLp(lp, {'times, 0, 'c}, cl,  'c . nl);
      call := lto_sconcat {"gurobi_cl ResultFile=", sol, " ", lp, " &> ", log};
      system call;
      res := ofsf_readLpSol(sol, d);
      if not !*rllpkeepfiles then
	 for each fn in {lp, sol, log} do
	    system lto_sconcat {"rm -f ", fn};
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

asserted procedure ofsf_pzeropLp1int(f: SF, negp: Boolean, d: Integer, vl: List, posp: List): List;
   begin scalar isol, fsol, sol, fval; integer  pow;
      posp := ofsf_fpoint2intpoint posp;
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

procedure ofsf_fpoint2intpoint(posp);
   begin scalar res, w; integer g;
      res := for each e in posp collect <<
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
      res := for i := 1:d+1 collect
	 read() . read();
      rds nil;
      close ch;
      res := {'equal, 'c, cdr atsoc('c, res)} . for i := 1:d collect <<
	 ni := mkid('n, i);
	 {'equal, ni, cdr atsoc(ni, res)}
      >>;
      return res
   end;

procedure ofsf_pzerop!-mon2lp(vl, pt);
   reval('times . cdr pt . for each d in car pt collect {'expt, pop vl, d});

algebraic procedure testpzerop(hu, sol);
   begin scalar w, subsol, foundsol, ok;
      ok := 1;
      for i := 2:3 do <<
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

end;
