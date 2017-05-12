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

rl_provideService rl_smtqe = smtqe_smtqe;

asserted procedure smtqe_smtqe(l: List): List3;
   begin scalar formula, db;
      smtqe_setfnal();
      formula := rl_smkn('and, l);
      formula := smtqe_tlsimpl(formula, nil);
      db := vsdb_mk(cl_fvarl formula, formula, nil, nil, t, t);
      vs_blockmainloop db;
      if !*ofsfvsqetree2gml then
      	 vsdb_2gml(db, rlqetreegmlfile!*);
      % TODO: Extract result from [db].
      return smtqe_collectResult db
   end;

asserted procedure smtqe_setfnal();
   <<
      vs_patchfnal('tlsimpl, 'smtqe_tlsimpl);
      vs_patchfnal('tladdguard, 'smtqe_tladdguard)
   >>;

%%% implementation of parameterizing procedures

asserted procedure smtqe_tlsimpl(f: QfFormula, assume: Theory): QfFormula;
   <<
      assert(rl_op f eq 'and);
      rl_smkn('and, for each subf in rl_argn f collect cl_simpl(subf, assume, -1))
   >>;

asserted procedure smtqe_tladdguard(f: QfFormula, g: QfFormula): QfFormula;
   <<
      assert(rl_op f eq 'and);
      rl_smkn('and, for each subf in rl_argn f collect rl_mkn('and, {g, subf}))
   >>;

%%% procedures doing "real work" %%%

asserted procedure smtqe_collectResult(db: VSdb): DottedPair;
   begin scalar fl, vl, w, uc;
      integer n;
      assert(not vsdb_todop db);
      for each nd in vsdb_sc db do <<
	 assert(not vsnd_flg nd);
	 push(vsnd_f nd, fl)
      >>;
      n := length rl_argn vsdb_f db;
      w := for i := 0 : n - 1 collect
	 mkid('x, i) . for each f in fl collect
	    if nth(f, i + 2) eq 'false then 1 else 0;
      uc := lto_setCover w;
      return {rl_mkn('or, fl), nil, uc}
      % TODO: Take care of failure nodes.
      % for each nd in vsdb_fc db do <<
      % 	 assert(not vsnd_flg nd);
      % 	 push(vsnd_f nd, fl);
      % 	 vl := union(vl, vsnd_vl nd)
      % >>;
   end;

endmodule;

end;
