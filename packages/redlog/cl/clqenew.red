module clqenew;

revision('clqenew, "$Id$");

copyright('clqenew, "(c) 2021 A. Dolzmann, T. Sturm");

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

asserted procedure cl_qe_new(f: Formula, theo: Theory): Formula;
   % Quantifier elimination. Eliminate as many quantifiers as possible from f,
   % yielding a formula g such that theo |= f <=> g.
   begin scalar db, !*rlsipo, !*rlsipw;
      !*rlsipo := t;
      !*rlsipw := t;
      db := qedb_new();
      qedb_setInputFormula(db, f);
      qedb_setInputTheory(db, theo);
      qedb_setNoAssumeVars(db, nil);
      qedb_setAnswerMode(db, nil);
      qedb_setAssumeMode(db, nil);
      db := cl_qe1_new(db);
      if rl_excp(db) then
         return db;
      return qedb_getFormula(db)
   end;

asserted procedure cl_qea_new(f: Formula, theo: Theory): List;
   % Extended quantifier elimination (aka "with answer").
   begin scalar db, !*rlqeans, !*rlsipo, !*rlsipw;
      !*rlqeans := t;
      !*rlsipo := t;
      !*rlsipw := t;
      db := qedb_new();
      qedb_setInputFormula(db, f);
      qedb_setInputTheory(db, theo);
      qedb_setNoAssumeVars(db, nil);
      % Standard answers work only for decision problems. The old procedure
      % did not check this and rederr() could happen in the ANU module. We
      % now check this here, but we should think about checking later.
      qedb_setAssumeMode(db, nil);
      qedb_setAnswerMode(db, if !*rlqestdans and null rl_fvarl f then'standard else 'raw);
      db := cl_qe1_new(db);
      if rl_excp(db) then
         return db;
      return qedb_getAnswer(db)
   end;

asserted procedure cl_gqe_new(f: Formula, theo: Theory, xNoAssumeVars: KernelL): DottedPair;
   % Generic quantifier elimination. Eliminate as many quantifiers as possible
   % from f, yielding a formula g such that theo |= f <=> g. The procedure is
   % allowed to assume inequations on parameters that are not in
   % xNoAssumeVars. Those assumptions are added to theo.
   begin scalar db, !*rlqegen, !*rlsipo, !*rlsipw;
      !*rlqegen := t;
      !*rlsipo := t;
      !*rlsipw := t;
      db := qedb_new();
      qedb_setInputFormula(db, f);
      qedb_setInputTheory(db, theo);
      qedb_setNoAssumeVars(db, xNoAssumeVars);
      qedb_setAssumeMode(db, if !*rlqegenct then 'full else 'monomial);
      qedb_setAnswerMode(db, nil);
      db := cl_qe1_new(db);
      if rl_excp(db) then
         return db;
      % The old procedure applies rl_thsimpl(). This must be checked.
      return qedb_getCurrentTheory(db) . qedb_getFormula(db)
   end;

asserted procedure cl_gqea_new(f: Formula, theo: Theory, xNoAssumeVars: KernelL): DottedPair;
   % Generic extended quantifier elimination (aka "with answer").
   begin scalar db, !*rlqeans, !*rlqegen, !*rlsipo, !*rlsipw;
      !*rlqegen := t;
      !*rlqeans := t;
      !*rlsipo := t;
      !*rlsipw := t;
      db := qedb_new();
      qedb_setInputFormula(db, f);
      qedb_setInputTheory(db, theo);
      qedb_setNoAssumeVars(db, xNoAssumeVars);
      qedb_setAssumeMode(db, if !*rlqegenct then 'full else 'monomial);
      qedb_setAnswerMode(db, if !*rlqestdans and null rl_fvarl f then'standard else 'raw);
      db := cl_qe1_new(db);
      if rl_excp(db) then
         return db;
      % The old procedure applies rl_thsimpl(). This must be checked.
      return qedb_getCurrentTheory(db) . qedb_getAnswer(db)
   end;

asserted procedure cl_qe1_new(db: Vector): Vector;
   begin scalar f, theo, answer, blocks, allQuantifiedVariables, point;
      f := qedb_getInputFormula(db);
      theo := qedb_getInputTheory(db);
      f := rl_pnf f;
      {blocks, f, allQuantifiedVariables} := cl_split_new f;
      if null blocks then <<
         if not null qedb_getAnswerMode(db) then
            qedb_setAnswer(db, {f . nil});
         return db
      >>;
      f := rl_simpl(f, theo, -1);
      if rl_excp(f) then
         return f;
      % Remove from the theory atomic formulas containing quantified variables
      qedb_setCurrentTheory(db, for each atf in theo join if null intersection(rl_varlat atf, allQuantifiedVariables) then {atf});
      % Prohibit assumptions on quantified variables:
      qedb_setNoAssumeVars(db, union(allQuantifiedVariables, qedb_getNoAssumeVars(db)));
      qedb_setBlocks(db, blocks);
      qedb_setFormula(db, f);
      cl_qe1!-iterate_new(db);
      blocks := qedb_getBlocks(db);
      theo := qedb_getCurrentTheory(db);
      % We deliberately lose quantifers over non-occurring variables.
      f := cl_simpl(cl_unsplit_new(blocks, qedb_getFormula(db)), theo, -1);
      if qedb_getAnswerMode(db) then <<
         % At present, we always requantify; no fallback QE with answers.
         if null blocks or null cdr blocks then <<
            % We have finished or at least reached the outmost block.
            answer := for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect <<
               point := rl_qemkans(ce_ans(node)) where !*rlqestdans = (qedb_getAnswerMode(db) eq 'standard);
               cl_unsplit_new(blocks, ce_f(node)) . point
            >>
         >> else
            answer := {f . nil};
         qedb_setFormula(db, f);
         qedb_setAnswer(db, answer);
         return db
      >>;
      if !*rlqefb and rl_quap rl_op f then
         theo . f := rl_fbqe(f, theo);
      qedb_setCurrentTheory(db, theo);
      qedb_setFormula(db, f);
      return db
   end;

asserted procedure cl_split_new(f: Formula): List3;
   % Split a prenex formula. Returns a list containing the quantifier blocks,
   % the matrix, and the quantified variables. The quantifier blocks are are
   % list of pairs conatining the quantifier symbol and a list of variables.
   begin scalar currentQuantifier, currentQuantifiedVariables, blocks, allQuantifiedVariables;
      if not rl_quap rl_op f then
         return {nil, f, nil};
      currentQuantifier := rl_op f;
      while rl_quap rl_op f do <<
         if rl_op f neq currentQuantifier then <<
            push(currentQuantifier . currentQuantifiedVariables, blocks);
            currentQuantifier := rl_op f;
            currentQuantifiedVariables := nil
         >>;
         push(rl_var f, currentQuantifiedVariables);
         push(rl_var f, allQuantifiedVariables);
         f := rl_mat f
      >>;
      push(currentQuantifier . currentQuantifiedVariables, blocks);
      return {blocks, f, allQuantifiedVariables}
   end;

asserted procedure cl_unsplit_new(blocks: List, f: Formula): Formula;
   begin scalar result;
      result := f;
      for each block in blocks do
         for each variable in cdr block do
            result := rl_mkq(car block, variable, result);
      return result
   end;

asserted procedure cl_qe1!-iterate_new(db: Vector): Vector;
   % Iteratively apply cl_qeblock to quantifier blocks.
   begin scalar blocks, f, produceAnswer, theo, db, svrlidentify, svrlqeprecise, svrlqeaprecise, q,
                variables,remainingVariables, w;
      svrlidentify := !*rlidentify;
      blocks := qedb_getBlocks(db);
      f := qedb_getFormula(db);
      theo := qedb_getInputTheory(db);
      ASSERT( not null blocks );
      while not null blocks and null remainingVariables do <<
         q . variables := pop blocks;
         qedb_setBlocks(db, blocks);
         qedb_setVariables(db, variables);
         produceAnswer := qedb_getAnswerMode(db) and null blocks;
         qedb_setProduceAnswer(db, produceAnswer);
         svrlqeprecise := !*rlqeprecise;
         svrlqeaprecise := !*rlqeaprecise;
         if blocks then <<  % Should better be an argument of qeblock ...
            off1 'rlqeprecise;
            off1 'rlqeaprecise
         >>;
         if q eq 'all then
            f := rl_simpl(rl_nnfnot f, theo, -1);
         qedb_setFormula(db, f);
         qedb_setSuccessNodes(db, nil);
         qedb_setFailureNodes(db, nil);
         qedb_setCurrentTheory(db, theo);
         if !*rlverbose then << qedb_verbosePrint(db) >>;
         cl_qeblock4_new(db);
         if !*rlverbose then << qedb_verbosePrint(db) >>;
         if q eq 'all then <<
            w := for each node in qedb_getSuccessNodes(db) collect
               ce_mk(ce_vl node, rl_nnfnot ce_f node, nil, nil, ce_ans node);
            qedb_setSuccessNodes(db, w);
            w := for each node in qedb_getFailureNodes(db) collect
               ce_mk(ce_vl node, rl_nnfnot ce_f node, nil, nil, ce_ans node);
            qedb_setFailureNodes(db, w)
         >>;
         f := rl_smkn(if q eq 'all then 'and else 'or,
                      for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect ce_f node);
         if not null qedb_getFailureNodes(db) then
            for each node in qedb_getFailureNodes(db) do
               remainingVariables := union(remainingVariables, ce_vl node);
         theo := qedb_getCurrentTheory(db);
         if blocks then <<
            onoff('rlqeprecise, svrlqeprecise);
            onoff('rlqeaprecise, svrlqeaprecise)
         >>
      >>;
      onoff('rlidentify, svrlidentify);
      if not null remainingVariables then
         push(q . remainingVariables, blocks);
      qedb_setBlocks(db, blocks);
      qedb_setFormula(db, f);
      return db
   end;

asserted procedure cl_qeblock4_new(db: Vector): Vector;
   begin scalar f, variables, theo;
      theo := qedb_getCurrentTheory(db);
      variables := qedb_getVariables(db);
      f := qedb_getFormula(db);
      if !*rlqegsd then
         f := rl_gsn(f, theo, 'dnf);
      qedb_initializeWorkingNodes(db, if !*rlqedfs then 'dfs else 'bfs);
      if rl_op f eq 'or then
         for each subFormula in rl_argn f do
            qedb_addWorkingNodes(db, {ce_mk(variables, subFormula, nil, nil, nil)})
      else
         qedb_addWorkingNodes(db, {ce_mk(variables, f, nil, nil, nil)});
      while not qedb_isEmptyWorkingNodes(db) do <<
         if !*rlqeidentify then on1 'rlidentify;
         cl_qevar_new(db)
      >>;
      return db
   end;

asserted procedure cl_qevar_new(db: Vector): Vector;
   % Quantifier eliminate one variable. Returns a pair $a . p$. Either $a=[T]$
   % and $p$ is a pair of a list of container elements and a theory or $a=[nil]$
   % and $p$ is an error message. If there is a container element with ['break]
   % as varlist, this is the only one.
   begin scalar node, failureNodes;
      node := qedb_fetchWorkingNode(db);
      qedb_setCurrentNode(db, node);
      cl_transform_new(db);
      if cl_gauss_new(db) then
         return db;
      if cl_specelimWrapper_new(db) then
         return db;
      if cl_regularEliminationSet(db) then
         return db;
      node := qedb_getCurrentNode(db);
      qedb_setCurrentNode(db, 'false);
      failureNodes := qedb_getFailureNodes(db);
      failureNodes := lto_insert(node, failureNodes);
      qedb_setFailureNodes(db, failureNodes);
      return db
   end;

asserted procedure cl_transform_new(db: Vector): Boolean;
   begin scalar node, theo, noAssumeVars, produceAnswer, variables, answer, f, w, hasTransformed;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := ce_f(node);
      variables := ce_vl(node);
      answer := ce_ans(node);
      hasTransformed := nil;
      for each variable in variables do <<
         w := rl_transform(variable, f, variables, answer, theo, produceAnswer, noAssumeVars);
         if w then <<
            hasTransformed := t;
            {f, variables, answer, theo, produceAnswer, noAssumeVars} := w
         >>;
      >>;
      if hasTransformed then <<
         node := ce_mk(variables, f, nil, nil, answer);
         qedb_setCurrentNode(db, node);
         qedb_setCurrentTheory(db, theo);
         qedb_setNoAssumeVars(db, noAssumeVars);
         qedb_setProduceAnswer(db, produceAnswer)  % should not be relevant
      >>;
      return hasTransformed
   end;

asserted procedure cl_gauss_new(db): Boolean;
   begin scalar w, node, theo, noAssumeVars, produceAnswer, f, variables, answer, variable,
                eliminationSet, nodes;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := ce_f(node);
      variables := ce_vl(node);
      w := rl_trygauss(f, variables, theo, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
         ioto_prin2 "[gauss]";
      answer := ce_ans(node);
      variable . eliminationSet := car w;
      theo := cdr w;
      variables := lto_delq(variable, variables);
      nodes . theo := cl_esetsubst(f, variable, eliminationSet, variables, answer, theo, produceAnswer, noAssumeVars);
      qedb_setCurrentTheory(db, theo);
      qedb_setCurrentNode(db, 'false);
      cl_storeRegularNodes(nodes, not null variables, db);  % no cdr here!
      return t
   end;

asserted procedure cl_specelimWrapper_new(db): Boolean;
   begin scalar w, node, theo, noAssumeVars, produceAnswer, f, variables, nodes;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := ce_f(node);
      variables := ce_vl(node);
      w := rl_specelim(f, variables, theo, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
         ioto_prin2 "[spec]";
      w . theo := w;
      ASSERT( car w eq t );
      nodes := cdr w;
      qedb_setCurrentTheory(db, theo);
      qedb_setCurrentNode(db, 'false);
      cl_storeRegularNodes(nodes, not null cdr variables, db);
      return t
   end;

asserted procedure cl_regularEliminationSet(db: Vector): Boolean;
   begin scalar produceAnswer, noAssumeVars, theo, node, f, nodeVariables, nodeAnswer, found,
                candidateVariables, candidateVariable, alp, successorNodes, newTheory,
                bestSuccessorNodes, bestTheory, successorNodeVariables;
      produceAnswer := qedb_getProduceAnwer(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      theo := qedb_getCurrentTheory(db);
      node := qedb_getCurrentNode(db);
      f := ce_f(node);
      nodeVariables := ce_vl(node);
      nodeAnswer := ce_ans(node);
      candidateVariables := if null cdr nodeVariables then
         nodeVariables
      else if not !*rlqevarsel then
         {car nodeVariables}
      else
         rl_varsel(f, nodeVariables, theo);
      found := nil;
      while candidateVariables do <<
         candidateVariable := pop candidateVariables;
         alp := cl_qeatal(f, candidateVariable, theo, produceAnswer);
         if alp = '(nil . nil) then <<
            % Candidate variable does not occur in f
            if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
               ioto_prin2 "*";
            bestTheory := theo;
            successorNodeVariables := lto_delq(candidateVariable, nodeVariables);
            if produceAnswer then
               nodeAnswer := cl_updans(candidateVariable, 'arbitrary, nil, nil, nodeAnswer, produceAnswer);
            bestSuccessorNodes := {ce_mk(successorNodeVariables, f, nil, nil, nodeAnswer)};
            found := t;
            goto brk
         >> else if car alp neq 'failed then <<
            % Candidate variable is eliminable
            if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
               ioto_prin2 "e";
            successorNodes . newTheory := cl_esetsubst_new(node, candidateVariable, rl_elimset(candidateVariable, alp), db);
            if not found or rl_betterp(successorNodes . newTheory, bestSuccessorNodes . bestTheory) then <<
               bestTheory := newTheory;
               bestSuccessorNodes := successorNodes;
               found := t
            >>
         >>
      >>;
   brk:
      if not found then
         return nil;
      qedb_setCurrentTheory(db, bestTheory);
      cl_storeRegularNodes(bestSuccessorNodes, not null cdr nodeVariables, db);
      qedb_setCurrentNode(db, 'false);
      return t
   end;

asserted procedure cl_storeRegularNodes(nodes: List, variablesLeft: Boolean, db: Vector): Vector;
   begin scalar successNodes;
      if not null nodes then <<
         if ce_vl car nodes eq 'break then <<  % we have found true
            qedb_initializeWorkingNodes(db, if !*rlqedfs then 'dfs else 'bfs);
            successNodes := qedb_getSuccessNodes(db);
            successNodes := {ce_mk(nil, 'true, nil, nil, ce_ans car nodes)};
            qedb_setSuccessNodes(db, successNodes);
            qedb_setFailureNodes(db, nil)
         >> else if variablesLeft then <<
            qedb_addworkingNodes(db, nodes)
         >> else <<
            successNodes := qedb_getSuccessNodes(db);
            for each node in nodes do
               successNodes := lto_insert(node, successNodes);
            qedb_setSuccessNodes(db, successNodes)
         >>
      >>;
      return db
   end;

asserted procedure cl_esetsubst_new(node: List, variable: Kernel, eliminationSet: List, db: Vector): List2;
   begin scalar produceAnswer, noAssumeVars, currentTheory, f, nodeVariables, nodeAnswer,
                successorNodeVariables, successorNodes, newTheory;
      produceAnswer := qedb_getProduceAnwer(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      currentTheory := qedb_getCurrentTheory(db);
      f := ce_f(node);
      nodeVariables := ce_vl(node);
      nodeAnswer := ce_ans(node);
      successorNodeVariables := lto_delq(variable, nodeVariables);
      successorNodes . newTheory := cl_esetsubst(f, variable, eliminationSet, successorNodeVariables,
                                                 nodeAnswer, currentTheory, produceAnswer, noAssumeVars);
      return successorNodes . newTheory
   end;

endmodule;

end;
