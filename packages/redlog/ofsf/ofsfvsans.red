module ofsfvsans;

revision('ofsfvsans, "$Id$");

copyright('ofsfvsans, "(c) 2017 M. Kosta, T. Sturm");

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

asserted procedure vsdb_computeAns(db: VSdb): AList;
   % Compute answers to existential sentences: entry point.
   begin scalar nd;
      if not eqn(vsco_length vsdb_sc db, 1) then  % there are at least two success nodes
	 return nil;
      nd := vsdb_scget db;
      if vsnd_f nd neq 'true then  % result is other than [true]
	 return nil;
      if !*rlverbose then
	 ioto_prin2t "++++ Computing answers";
      return vsdb_ans!-main(db, nd, nil)
   end;

asserted procedure vsdb_ans!-main(db: VSdb, nd: VSnd, ctx: AList): AList;
   % Core of the answers computing procedure. [nd] is a node in the
   % tree of nodes contained in [db]; [ctx] is the current context,
   % i.e., list of pairs (Kernel . Anu) containing assignments to
   % variables in [vsnd_vs nd] except of [vsvs_v vsnd_vs nd]. Starting
   % in node [nd] we compute the answers w.r.t. the current context
   % [ctx].
   begin scalar vs, v, anu;
      vs := vsnd_vs nd;
      if null vs then  % [nd] is the root of the QE tree
	 return ctx;
      v := vsvs_v vs;
      % Next we distinguish how [nd] was obtained from its parent
      % node:
      if vsvs_arp vs then  % arbitrary
	 anu := vsnd_ans!-arb(nd, ctx);
      if vsvs_dgp vs then  % degree shift
	 anu := vsnd_ans!-dgs(nd, ctx);
      if vsvs_tsp vs then  % test point
	 anu := vsnd_ans!-tp(nd, ctx);
      return vsdb_ans!-main(db, vsnd_parent nd, (v . anu) . ctx)
   end;

asserted procedure vsnd_ans!-arb(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by
   % "arbitrary" VS from its parent.
   begin scalar v;
      assert(vsvs_arp vsnd_vs nd);
      v := vsvs_v vsnd_vs nd;
      return anu_fromrat(v, rat_0())
   end;

asserted procedure vsnd_ans!-dgs(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by
   % "degree shift" VS from its parent.
   begin scalar v, sv, svanu, aex;
      integer g;
      assert(vsvs_dgp vsnd_vs nd);
      v := vsvs_v vsnd_vs nd;
      g := vsdg_g vsnd_vs nd;
      sv := vsdg_sv vsnd_vs nd;
      assert(atsoc(sv, ctx));
      svanu := cdr atsoc(sv, ctx);
      aex := aex_fromsf addf(exptf(!*k2f v, g), negf !*k2f sv);  % v^g - sv
      aex := aex_bind(aex, sv, svanu);
      if evenp g then
	 return anu_mk(aex, iv_mk(rat_0(), iv_rb anu_iv svanu));
      return anu_mk(aex, anu_iv svanu)
   end;

asserted procedure vsnd_ans!-tp(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by "test
   % point" VS from its parent.
   begin scalar vs, v, tp;
      vs := vsnd_vs nd;
      assert(vsvs_tsp vs);
      v := vsvs_v vs;
      tp := vsts_tp vs;
      if vstp_np tp memq '(minf pinf) then  % + - infinity
	 return vsnd_ans!-infinity(nd, ctx);
      if vstp_np tp memq '(meps peps) then  % root + - epsilon
	 return vsnd_ans!-epsilon(nd, ctx);
      assert(null vstp_np tp);
      return vsnd_ans!-root(nd, ctx)  % root
   end;

asserted procedure vsnd_ans!-infinity(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by
   % "+-infinity" VS from its parent.
   begin scalar v, f, inf, tval;
      integer vval;
      v := vsvs_v vsnd_vs nd;
      f := vsnd_f vsnd_parent nd;
      inf := vstp_np vsts_tp vsnd_vs nd;
      assert(inf memq '(minf pinf));
      vval :=
 	 if inf eq 'minf then
	    -1
      	 else
 	    1;
      repeat <<
	 vval := 2 * vval;
	 tval := vsnd_evalqff(f, (v . anu_fromrat(v, vval ./ 1)) . ctx)
      >> until tval eq 'true;
      return anu_fromrat(v, vval ./ 1)
   end;

asserted procedure vsnd_ans!-epsilon(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by
   % "root+-epsilon" VS from its parent.
   begin scalar v, f, root, sc, eps, vval, tval;
      v := vsvs_v vsnd_vs nd;
      f := vsnd_f vsnd_parent nd;
      root := vsnd_ans!-root(nd, ctx);
      sc := aex_stdsturmchain(anu_dp root, v);
      eps := vstp_np vsts_tp vsnd_vs nd;
      repeat <<
	 anu_refineip(root, sc);
	 vval :=
	    if eps eq 'meps then
	       iv_lb anu_iv root
	    else
	       iv_rb anu_iv root;
	 tval := vsnd_evalqff(f, (v . anu_fromrat(v, vval)) . ctx)
      >> until tval eq 'true;
      return anu_fromrat(v, vval)
   end;

asserted procedure vsnd_ans!-root(nd: VSnd, ctx: AList): Anu;
   % Compute answer for [nd], assuming that [nd] was obtained by
   % "root" VS from its parent.
   begin scalar v, tp, pr, aex;
      integer rtcode, rindex;
      assert(vsvs_tsp vsnd_vs nd);
      assert(vstp_np vsts_tp vsnd_vs nd memq '(nil meps peps));
      v := vsvs_v vsnd_vs nd;
      tp := vsts_tp vsnd_vs nd;
      pr := vstp_pr tp;
      aex := aex_fromsf vspr_f vstp_pr tp;
      for each pair in ctx do
	 aex := aex_bind(aex, car pair, cdr pair);
      rtcode := cdr assoc(vspr_d pr . aex_realtype aex, deg!-type!-code!-alist!*);
      rindex := cdr atsoc(rtcode, vspr_rsl pr);
      % if !*rlverbose then
      % 	 ioto_prin2t {"aex for ", v, " root specification: ", rtcode . rindex};
      return nth(aex_findroots(aex, v), rindex)
   end;

asserted procedure vsnd_evalqff(f: QfFormula, ctx: AList): Id;
   % a wrapper for [ofsf_evalqff]
   begin scalar sp, varl;
      sp := for each pr in ctx collect cdr pr;
      varl := for each pr in ctx collect car pr;
      return ofsf_evalqff(f, sp, reverse varl)
   end;

endmodule;  % [ofsfvsans]

end;  % of file
