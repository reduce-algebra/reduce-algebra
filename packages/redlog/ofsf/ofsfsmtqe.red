module ofsfsmtqe;

revision('ofsfsmtqe, "$Id$");

copyright('ofsfsmtqe, "(c) 2017 M. Kosta, T. Sturm");

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

%%% parameterizing procedures

asserted procedure smtqe_setfnal();
   <<
      vs_patchfnal('fn_pc!-decomposition, 'smtqe_pc!-decomposition);
      vs_patchfnal('fn_applyvsts, 'smtqe_applyvsts)
   >>;

%%% implementation of parameterizing procedures

asserted procedure smtqe_pc!-decomposition(de: VSde);
   % Compute a prime constituent decomposition.
   begin scalar f, gl, cgl, atl, gposl, pc, pcl;
      integer n;
      % Replacements with [false] in this procedure is done to mark
      % subformulas that play no role (i.e. we do not need to look
      % into them) in further PC computation. Simplification of [f]
      % after thse replacements would NOT be semantically correct!

      f := vsde_f de;
      assert(rl_op f eq 'and);
      % find Gauss prime constituents (in each subformula)
      gl := for each subf in rl_argn f join <<
	 n := n + 1;
	 qff_gaussposl(vsde_v de, subf, {n}, vsde_bvl de, vsde_curtheo de)
      >>;
      if vsde_failedalp gl then
	 % We continue in the failed case, because the subformula
	 % causing the failure can become part of a co-Gauss prime
	 % constituent.
	 gl := nil
      else
      	 % TODO: Choose an efficient ordering of [gl].
      	 % TODO: Here is the place for gentle simplification.
      	 f := qff_replacel(f, for each pr in gl collect car pr, 'false);
      % find co-Gauss prime constituents (in each subformula)
      n := 0;
      cgl := for each subf in rl_argn f join <<
	 n := n + 1;
	 qff_cogaussposl(vsde_v de, subf, {n}, vsde_bvl de, vsde_curtheo de)
      >>;
      if vsde_failedalp cgl then <<
	 % We terminate in the failed case, because the subformula
	 % causing the failure will lead to failure during atomic
	 % prime constituents computation as well.
	 vsde_putpcl(de, nil);
	 return
      >>;
      gl := pos_delsubposal(cgl, gl);
      % find atomic prime constituents
      f := qff_replacel(f, for each pr in cgl collect car pr, 'false);
      atl := qff_atposl(vsde_v de, f, nil, vsde_bvl de, vsde_curtheo de);
      if vsde_failedalp atl then <<
	 vsde_putpcl(de, nil);
	 return
      >>;
      for each pr in atl do <<
	 pc := vspc_mk(car pr, 'at, cdr pr, gposl, nil);
	 push(pc, pcl)
      >>;
      for each pr in cgl do <<
	 pc := vspc_mk(car pr, 'cogauss, cdr pr, gposl, nil);
	 push(pc, pcl)
      >>;
      for each pr in gl do <<
	 pc := vspc_mk(car pr, 'gauss, cdr pr, gposl, nil);
	 push(pc, pcl);
	 push(car pr, gposl)
      >>;
      vsde_putpcl(de, pcl)
   end;

asserted procedure smtqe_applyvsts(ds: VSds);
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
      % We do not terminate when [g] is [false].
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
      assert(rl_op f eq 'and);
      % Write guard [g] into each conjunction member separately.
      f := rl_smkn('and, for each subf in rl_argn f collect rl_mkn('and, {g, subf}));
      % Simplify each conjunction member separately.
      f := smtqe_simpl(f, theo);
      if !*rlverbose then
	 ioto_prin2t "]";
      vsds_putres(ds, f)
   end;

%%% entry point

rl_provideService rl_smtqe = smtqe_smtqe;

asserted procedure smtqe_smtqe(l: List): List3;
   begin scalar formula, db;
      smtqe_setfnal();
      formula := rl_smkn('and, l);
      formula := smtqe_simpl(formula, nil);
      db := vsdb_mk(cl_fvarl formula, formula, nil, nil, t);
      vs_blockmainloop db;
      if !*ofsfvsqetree2gml then
      	 vsdb_2gml(db, rlqetreegmlfile!*);
      % TODO: Extract result from [db].
      return smtqe_collectResult db
   end;

%%% procedures doing "real work" %%%

asserted procedure smtqe_simpl(f: QfFormula, theo: Theory): QfFormula;
   rl_smkn('and, for each subf in rl_argn f collect cl_simpl(subf, theo, -1));

asserted procedure smtqe_collectResult(db: VSdb): DottedPair;
   begin scalar fl, vl, w, uc;
      integer n;
      assert(not vsdb_todop db);
      for each nd in vsdb_sc db do <<
	 assert(not vsnd_flg nd);
	 push(vsnd_f nd, fl)
      >>;
%%       n := length rl_argn vsdb_f db;
%%       w := for i := 0 : n - 1 collect
%% 	 mkid('x, i) . for each f in fl collect
%% 	    if nth(f, i + 2) eq 'false then 1 else 0;
%%       uc := lto_setCover w;
      uc := smtqe_fl2uc fl;
      return {rl_mkn('or, fl), nil, uc}
      % TODO: Take care of failure nodes.
      % for each nd in vsdb_fc db do <<
      % 	 assert(not vsnd_flg nd);
      % 	 push(vsnd_f nd, fl);
      % 	 vl := union(vl, vsnd_vl nd)
      % >>;
   end;

asserted procedure smtqe_fl2uc(fl: List): List;
  % [fl] is a list of conjunctions [a_0, ..., a_n] with [a_i in {true, false},
  % which all contain at least one [false]. Returns a subset of [{0, ..., n}]
  % such that all conjunctions contain at least one [false] already on that
  % subset.
  begin scalar mtx1, mtx, row, c, scmtx, uc, inp, otime; integer n;
     if !*rlverbose then ioto_tprin2 "+++++ unsat core: ";
     if null fl then return nil;
     mtx1 := for each f in fl collect
	 for each tv in rl_argn f collect
	    if tv eq 'false then 1 else 0;
     n := length car mtx1;
     if !*rlverbose then ioto_prin2 {n, ", order preprocessing: "};
     mtx1 := (for i := 0 : n-1 collect lto_int2id i) . mtx1;
     mtx1 := lto_transposip mtx1;
     for each row in mtx1 do <<
	 scmtx := mtx;
	 c := t; while c and scmtx do <<
	    if lto_ordprod(cdr row, cdr car scmtx, 'geq) then <<
	       car scmtx := row;
	       c := nil
	    >> else if lto_ordprod(cdr row, cdr car scmtx, 'leq) then
	       c := nil
	    else
	       pop scmtx
	 >>;
	 if c then push(row, mtx)
     >>;
     if !*rlverbose then ioto_prin2 {length mtx, ", set cover: "};
     uc := lto_setCover mtx where !*rlverbose = nil;
     if !*rlverbose then ioto_prin2t length uc;
     return for each x in uc collect lto_id2int x
  end;

endmodule;

end;
