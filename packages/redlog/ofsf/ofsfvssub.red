module ofsfvssub;

revision('ofsfvssub, "$Id$");

copyright('ofsfvssub, "(c) 2015-2017 M. Kosta, T. Sturm");

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

%%% VS %%%
% constructors and access functions

asserted procedure vsvs_arp(vs: VSvs): Boolean;
   % VS arbitrary predicate.
   VSarP vs;

asserted procedure vsvs_dgp(vs: VSvs): Boolean;
   % VS degree shift predicate.
   VSdgP vs;

asserted procedure vsvs_tsp(vs: VSvs): Boolean;
   % VS test point substitution predicate.
   VStsP vs;

asserted procedure vsvs_v(vs: VSvs): Kernel;
   % VS variable.
   nth(vs, 2);

asserted procedure vsar_mk(x: Kernel): VSvs;
   % VS arbitrary make.
   {'vsar, x};

asserted procedure vsdg_mk(x: Kernel, g: Integer, sv: Kernel): VSvs;
   % VS degree shift make.
   {'vsdg, x, g, sv};

asserted procedure vsdg_g(vs: VSdg): Integer;
   % VS degree shift gcd.
   nth(vs, 3);

asserted procedure vsdg_sv(vs: VSdg): Kernel;
   % VS degree shift shadow variable.
   nth(vs, 4);

asserted procedure vsts_mk(x: Kernel, tp: VStp): VSvs;
   % VS test point substitution make.
   {'vsts, x, tp};

asserted procedure vsts_tp(vs: VSts): VStp;
   % VS test point substitution test point.
   nth(vs, 3);

asserted procedure vsvs_reorder(vs: VSvs): VSvs;
   % VS reorder.
   if vsvs_tsp vs then
      {'vsts, vsvs_v vs, vstp_reorder vsts_tp vs}
   else
      vs;

%%% VS data for virtual subsitution %%%
% constructors and access functions

asserted procedure vsds_new(): VSds;
   % VS data for virtual substitution new.
   begin scalar ds;
      ds := mkvect(6);
      putv(ds, 0, 'vsds);
      putv(ds, 1, 'undefined);        % [vs]: virtual substitution
      putv(ds, 2, 'undefined);        % [f]: quantifier-free formula
      putv(ds, 3, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(ds, 4, 'undefined);        % [ptheo]: persistent theory
      putv(ds, 5, 'undefined);        % [ttheo]: temporary theory
      putv(ds, 6, 'undefined);        % [res]: quantifier-free formula; result of the virtual substitution
      return ds
   end;

procedure vsds_vs(ds);                          getv(ds, 1);
procedure vsds_f(ds);                           getv(ds, 2);
procedure vsds_bvl(ds);                         getv(ds, 3);
procedure vsds_ptheo(ds);                       getv(ds, 4);
procedure vsds_ttheo(ds);                       getv(ds, 5);
procedure vsds_res(ds);                         getv(ds, 6);

procedure vsds_putvs(ds, vs);                   putv(ds, 1, vs);
procedure vsds_putf(ds, f);                     putv(ds, 2, f);
procedure vsds_putbvl(ds, bvl);                 putv(ds, 3, bvl);
procedure vsds_putptheo(ds, ptheo);             putv(ds, 4, ptheo);
procedure vsds_putttheo(ds, ttheo);             putv(ds, 5, ttheo);
procedure vsds_putres(ds, res);                 putv(ds, 6, res);

asserted procedure vsds_mk(vs: VSvs, f: QfFormula, bvl: KernelL, ptheo: Theory, ttheo: Theory): VSds;
   begin scalar ds;
      ds := vsds_new();
      vsds_putvs(ds, vs);
      vsds_putf(ds, f);
      vsds_putbvl(ds, bvl);
      vsds_putptheo(ds, ptheo);
      vsds_putttheo(ds, ttheo);
      vsds_putres(ds, nil);
      return ds
   end;

asserted procedure vsds_mkfrom(ds: VSds): VSds;
   begin scalar nds;
      nds := vsds_new();
      vsds_putvs(nds, vsds_vs ds);
      vsds_putf(nds, vsds_f ds);
      vsds_putbvl(nds, vsds_bvl ds);
      vsds_putptheo(nds, vsds_ptheo ds);
      vsds_putttheo(nds, vsds_ttheo ds);
      vsds_putres(nds, vsds_res ds);
      return nds
   end;

%%% procedures doing "real work" %%%

asserted procedure qff_applyvs(vs: VSvs, f: QfFormula, bvl: KernelL, theo: Theory): QfFormulaL;
   % This is the usual entry point.
   % wrapper
   begin scalar ds, ff;
      ds := vsds_mk(vs, f, bvl, theo, nil);
      vsds_applyvs ds;
      ff := vsds_res ds;
      return vs_splitor ff
   end;

asserted procedure vsds_applyvs(ds: VSds);
   % VS data for virtual substitution apply VS. [ds] is modified
   % in-place.
   begin scalar vs;
      vs := vsds_vs ds;
      if vsvs_arp vs then
	 vsds_applyvsar ds;
      if vsvs_dgp vs then
	 vsds_applyvsdg ds;
      if vsvs_tsp vs then
	 vsds_applyvsts ds
   end;

asserted procedure vsds_applyvsar(ds: VSds);
   % VS data for virtual substitution apply VSar. [ds] is modified
   % in-place. [vsds_vs ds] is an arbitrary substitution [x //
   % arbitrary]. It should be never needed to apply VSar.
   <<
      assert(nil);
      vsds_putres(ds, vsds_f ds)
   >>;

asserted procedure vsds_applyvsdg(ds: VSds);
   % VS data for virtual substitution apply VSdg. [ds] is modified
   % in-place. [vsds_vs ds] is a degree shift substitution [x^n //
   % x^(n/d)].
   begin scalar vs, f;
      vs := vsds_vs ds;
      f := vsds_f ds;
      f := cl_apply2ats1(f, 'vsdg_decdeg, {vsvs_v vs, vsdg_g vs, vsdg_sv vs});
      if evenp vsdg_g vs then
	 f := rl_mk2('and, ofsf_0mk2('geq, !*k2f vsdg_sv vs), f);
      vsds_putres(ds, f)
   end;

asserted procedure vsdg_decdeg(at: QfFormula, x: Kernel, g: Integer, y: Kernel): QfFormula;
   % Decrement degree of atomic formula. Replace each occurence of
   % [x^n] by [y^(n/g)].
   begin scalar f;
      % assert(at is atomic);
      f := rl_arg2l at;
      f := sfto_decdegf(f, x, g);
      return ofsf_0mk2(rl_op at, sfto_renamef(f, x, y))
   end;

asserted procedure vsds_applyvsts(ds: VSds);
   % VS data for virtual substitution apply VSts. [ds] is modified
   % in-place. [vsds_vs ds] is a test point substitution [x // tp],
   % where [tp] is a test point computed from formula [vsds_f ds].
   begin scalar vs, f, tp, ttheo, theo, g;
      vs := vsds_vs ds;
      f := vsds_f ds;
      tp := vsts_tp vs;
      ttheo := vsds_ttheo ds;
      theo := append(vsds_ptheo ds, ttheo);
      g . ttheo := vsds_g2gtt(vstp_guard tp, theo, ttheo);
      if g eq 'false then <<
	 vsds_putres(ds, 'false);
	 return
      >>;
      vsds_putttheo(ds, ttheo);
      f := qff_replacel(f, vstp_gpl tp, 'false);
      % TODO: Here we could replace the position(s) that produced the
      % test point [tp] with ['true]. WARNING: This replacement is NOT
      % correct when using clustering!
      if !*rlverbose then <<
	 ioto_tprin2 {"+++++ VSUB ", vsvs_v vs, " "};
	 ioto_prin2 "[condense"
      >>;
      f := qff_condense(f, vstp_p tp);
      if !*rlverbose then <<
	 ioto_prin2 "]";
	 ioto_prin2 "[substitute"
      >>;
      f := cl_apply2ats1(f, 'vsds_applyvsts!-at, {ds});
      if !*rlverbose then <<
	 ioto_prin2 "]";
	 ioto_prin2 "[simplify"
      >>;
      f := vs_applyfn('tladdguard, {f, g});
      f := vs_applyfn('tlsimpl, {f, theo});
      if !*rlverbose then
	 ioto_prin2t "]";
      vsds_putres(ds, f)
   end;

asserted procedure vsds_g2gtt(g: QfFormula, theo: Theory, ttheo: Theory): DottedPair;
   % Guard to guard and ttheo. [ttheo] is contained in [theo]. Returns
   % a pair [gg . ttheo], where [gg] is a simplified [g] and [ttheo]
   % is a new temporary theory.
   begin scalar op;
      g := cl_simpl(g, theo, -1);
      if rl_tvalp g then
	 return g . ttheo;
      op := rl_op g;
      if not rl_boolp op then
	 return g . append(ttheo, {g});
      if op eq 'and then <<
	 return g . append(ttheo,
	    for each f in rl_argn g join
	       if not rl_boolp rl_op f then {f})
      >>;
      return g . ttheo
   end;

% THE FOLLOWING PROCEDURE IS TEMPORARY! It uses old code to have something runnable.
% asserted procedure vsds_applyvsts(ds: VSds);
%    % VS data for virtual substitution apply VSts. [ds] is modified
%    % in-place.
%    begin scalar vs, f, v, tp;
%       vs := vsds_vs ds;
%       f := vsds_f ds;
%       v := vsvs_v vs;
%       tp := vsts_tp vs;
%       vsds_putres(ds, cdr apply(car tp, nil . nil . f . v . cdr tp))
%    end;

asserted procedure qff_condense(f: QfFormula, p: Position): QfFormula;
   % Quantifier-free formula condense with respect to position [p].
   % Returns a formula, which is obtained from [f] by replacing each
   % position disjunctively associated with [p] replaced with
   % ['false].
   begin scalar op, ncl; integer n, i;
      if null p then
	 return f;
      op := rl_op f;
      assert(op eq 'and or op eq 'or);
      n := car p;
      if op eq 'and then <<
	 for each c in rl_argn f do <<
	    i := i + 1;
	    if eqn(i, n) then
	       push(qff_condense(c, cdr p), ncl)
	    else
	       push(c, ncl)
	 >>;
      	 return rl_mkn(op, reversip ncl)
      >>;
      % we know that [op eq 'or]
      for each c in rl_argn f do <<
	 i := i + 1;
	 if eqn(i, n) then
	    push(qff_condense(c, cdr p), ncl)
	 else
	    push('false, ncl)
      >>;
      return rl_mkn(op, reversip ncl)
   end;

asserted procedure vsds_applyvsts!-at(at: QfFormula, ds: VSds): QfFormula;
   % VS data for virtual substitution apply VSts: atomic formula
   % subroutine. [vsds_vs ds] is a test point substitution [x // tp],
   % where [tp] is a test point computed from formula [vsds_f ds].
   begin scalar x, np, w, pr, theo;
      x := vsvs_v vsds_vs ds;
      np := vstp_np vsts_tp vsds_vs ds;
      w := if np memq '(minf pinf) then
	 vsds_expand!-at!-inf(at, x, np)
      else if np memq '(meps peps) then
	 vsds_expand!-at!-eps(at, x, np)
      else
	 at;
      if np memq '(minf pinf) then
	 return w;
      pr := vstp_pr vsts_tp vsds_vs ds;
      theo := append(vsds_ptheo ds, vsds_ttheo ds);
      return cl_apply2ats1(w, 'vsds_applyvsts!-at!-pr, {pr, theo})
   end;

asserted procedure vsds_expand!-at!-inf(at: QfFormula, x: Kernel, np: Id): QfFormula;
   % Expand atomic formula at +- infinity.
   begin scalar g, op;
      assert(np memq '(minf pinf));
      if rl_tvalp at then
	 return at;
      g := rl_arg2l at;
      if not sfto_mvartest(g, x) then
	 return at;
      op := rl_op at;
      if op eq 'equal then
      	 return rl_mkn('and, for each c in coeffs g collect ofsf_0mk2('equal, c));
      if op eq 'neq then
      	 return rl_mkn('or, for each c in coeffs g collect ofsf_0mk2('neq, c));
      return vsds_expand!-at!-inf1(op, g, x, np)
   end;

asserted procedure vsds_expand!-at!-inf1(op: Id, g: SF, x: Kernel, np: Id): QfFormula;
   % Expand atomic formula at +- infinity subroutine.
   begin scalar w;
      assert(op memq '(lessp leq geq greaterp));
      if not sfto_mvartest(g, x) then
	 return ofsf_0mk2(op, g);
      w := if np eq 'minf and not evenp ldeg g then
	 negf lc g
      else
	 lc g;
      return rl_mkn('or, {ofsf_0mk2(ofsf_mkstrict op, w),
	 rl_mkn('and, {ofsf_0mk2('equal, w), vsds_expand!-at!-inf1(op, red g, x, np)})})
   end;

asserted procedure vsds_expand!-at!-eps(at: QfFormula, x: Kernel, np: Id): QfFormula;
   % Expand atomic formula at test point +- eps.
   begin scalar g, op;
      assert(np memq '(meps peps));
      if rl_tvalp at then
	 return at;
      g := rl_arg2l at;
      if not sfto_mvartest(g, x) then
	 return at;
      op := rl_op at;
      if op eq 'equal then
      	 return rl_mkn('and, for each c in coeffs g collect ofsf_0mk2('equal, c));
      if op eq 'neq then
      	 return rl_mkn('or, for each c in coeffs g collect ofsf_0mk2('neq, c));
      return vsds_expand!-at!-eps1(op, g, x, np)
   end;

asserted procedure vsds_expand!-at!-eps1(op: Id, g: SF, x: Kernel, np: Id): QfFormula;
   % Expand atomic formula at test point +- eps subroutine.
   begin scalar dg;
      assert(op memq '(lessp leq geq greaterp));
      if not sfto_mvartest(g, x) then
	 return ofsf_0mk2(op, g);
      dg := if np eq 'peps then
	 diff(g, x)
      else
	 negf diff(g, x);
      return rl_mkn('or, {ofsf_0mk2(ofsf_mkstrict op, g),
	 rl_mkn('and, {ofsf_0mk2('equal, g), vsds_expand!-at!-eps1(op, dg, x, np)})})
   end;

asserted procedure vsds_applyvsts!-at!-pr(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   % Apply virtual substitution to an atomic formula.
   begin scalar g, x, f;
      if rl_tvalp at then
	 return at;
      g := rl_arg2l at;
      x := vspr_v pr;
      if not sfto_mvartest(g, x) then
	 return at;
      f := vspr_f pr;
      g := sfto_psrem!-sgn(g, f, x, theo);
      return vsub_vsub(ofsf_0mk2(rl_op at, g), pr, theo)
   end;

% TODO: Rename and move this procedure to the sfto module.
asserted procedure sfto_psrem!-sgn(g: SF, f: SF, x: Kernel, theo: Theory): SF;
   % Polynomial sign-equivalent to the pseudo remainder of [g] and
   % [f]. Returns a polynomial [h] such that:
   % (i) the degree of [h] is smaller than the degree of [f],
   % (ii) [h] has the same sign at a root of [f] as [g] for any choice
   % of parameters (variables other than [x])
   begin scalar lcf, srp, srm, w, lcg, qlc; integer degf, degg;
      assert(sfto_mvartest(f, x));
      degf := ldeg f;
      lcf := lc f;
      srp := ofsf_surep(ofsf_0mk2('geq, lcf), theo);
      srm := ofsf_surep(ofsf_0mk2('leq, lcf), theo);
      degg := sfto_vardeg(g, x);
      while degg >= degf do <<
	 w := multf(sfto_kexp(x, degg - degf), red f);
      	 lcg := lc g;
	 qlc := quotf(lcg, lcf);
	 g := if qlc then
	    addf(red g, negf multf(qlc, w))
	 else if srp then
	    addf(multf(lcf, red g), negf multf(lcg, w))
	 else if srm then
	    negf addf(multf(lcf, red g), negf multf(lcg, w))
	 else
	    addf(multf(multf(lcf, lcf), red g), negf multf(multf(lcf, lcg), w));
	 degg := sfto_vardeg(g, x)
      >>;
      return g
   end;

% TODO: Move the following procedure to cl.
asserted procedure vs_splitor(f: QfFormula): QfFormulaL;
   if rl_op f eq 'or then
      rl_argn f
   else
      {f};

% functions mainly for debugging purposes

asserted procedure vsvs_prints(vs: VSvs);
   % VSvs print summary.
   <<
      ioto_prin2 {"VSvs: "};
      if vsvs_tsp vs then <<
      	 ioto_prin2t {vsvs_v vs, " = tp"};
	 vstp_prints vsts_tp vs
      >> else if vsvs_dgp vs then
      	 ioto_prin2t {vsvs_v vs, " = ", vsdg_g vs, "-th root of ", vsdg_sv vs}
      else if vsvs_arp vs then
      	 ioto_prin2t {vsvs_v vs, " = arbitrary"}
   >>;

endmodule;  % [ofsfvssub]

end;  % of file
