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
   % Quantifier elimination. Compute a prenex normal form of the input formula, split it into
   % quantifier blocks and the quantifier-free matrix, and prepare qedb accordingly.

   % If virtual subtituation fails at some point due to degree violations, the elimination result
   % obtained so far is requantified with the remaining quantifiers. Optionally, a fallback
   % quantifier elimination method is applied.
   begin scalar f, theo, answer, blocks, allQuantifiedVariables, point;
         integer n;
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
      % Discuss: I had to bind f here for the verbose message. With a qedb_simplifyFormula method
      % the verbose could be moved there. I think this would go beyond the fetch methods suggested
      % elsewhere, and I have some doubts.
      f := qedb_getFormula(db);
      % Discuss: In the old version the following verbose output does not show up with
      % "rlqea ex(x, m*x+b=0);"
      if !*rlverbose then ioto_tprin2 {"+++ Final simplification ... ", cl_atnum f, " -> "};
      % We deliberately lose quantifers over non-occurring variables.
      f := cl_simpl(cl_unsplit_new(blocks, f), theo, -1);
      if !*rlverbose then ioto_prin2t cl_atnum f;
      if qedb_getAnswerMode(db) then <<
         % At present, we always requantify; no fallback QE with answers.
         if null blocks or null cdr blocks then <<
            % We have finished or at least reached the outmost block.
            if !*rlverbose then <<
               ioto_tprin2 "+++ Postprocessing answer:";
               n := length(qedb_getSuccessNodes(db)) + length(qedb_getFailureNodes(db))
            >>;
            answer := for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect <<
               if !*rlverbose then ioto_prin2 {" [", n := n - 1};
               point := rl_qemkans(qenod_getAnswer(node)) where !*rlqestdans = (qedb_getAnswerMode(db) eq 'standard);
               if !*rlverbose then ioto_prin2 {"]"};
               cl_unsplit_new(blocks, qenod_getFormula(node)) . point
            >>
         >> else
            answer := {f . nil};
         qedb_setFormula(db, f);
         qedb_setAnswer(db, answer);
         return db
      >>;
      if !*rlqefb and rl_quap rl_op f then <<
         if !*rlverbose then ioto_tprin2 {"++++ Entering fallback QE: "};
         theo . f := rl_fbqe(f, theo)
      >>;
      qedb_setCurrentTheory(db, theo);
      qedb_setFormula(db, f);
      return db
   end;

asserted procedure cl_split_new(f: Formula): List3;
   % Split a prenex formula. Returns a list containing the quantifier blocks, the matrix, and a flat
   % list of all quantified variables (regardless of the corresponding quantifier symbol). The
   % quantifier blocks are list of pairs conatining the quantifier symbol and a list of variables.
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
   % Iterate over quantifier blocks. The blocks are successively eliminated from the inside to the
   % outside. Universal quantifier blocks are reduced to existential ones via logical negation.
   begin scalar blocks, f, produceAnswer, theo, db, svrlidentify, svrlqeprecise, svrlqeaprecise, q,
                variables,remainingVariables, w, op, arguments;
      svrlidentify := !*rlidentify;
      blocks := qedb_getBlocks(db);
      f := qedb_getFormula(db);
      theo := qedb_getInputTheory(db);
      ASSERT( not null blocks );
      while not null blocks and null remainingVariables do <<
         q . variables := pop blocks;
         qedb_setBlocks(db, blocks);
         % Discuss: implement qedb_fetchBlocks and move this !*rlverbose to qedb
         if !*rlverbose then
            ioto_tprin2 {"---- ", (q . reverse variables)};
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
         cl_qeblock4_new(db);
         if q eq 'all then <<
            % In the following we could benefit from mutable qenod
            w := for each node in qedb_getSuccessNodes(db) collect
               qenod_new(qenod_getVariables(node), rl_nnfnot(qenod_getFormula(node)), qenod_getAnswer(node));
            qedb_setSuccessNodes(db, w);
            w := for each node in qedb_getFailureNodes(db) collect
               qenod_new(qenod_getVariables(node), rl_nnfnot(qenod_getFormula(node)), qenod_getAnswer(node));
            qedb_setFailureNodes(db, w)
         >>;
         op := if q eq 'all then 'and else 'or;
         arguments := for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect
            qenod_getFormula(node);
         f := rl_smkn(op, arguments);
         if not null qedb_getFailureNodes(db) then
            for each node in qedb_getFailureNodes(db) do
               remainingVariables := union(remainingVariables, qenod_getVariables(node));
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
   % Eliminate a block of prenex existential quantifiers. The quantified variables and the matrix
   % formula haven already been identified and stored in qedb. The existential block could be the
   % logical negation of a universal block from the original input. The corresponding negation and
   % back-negation takes place outside this procedure.
   begin scalar f, variables, theo;
         integer maxLength, maxCount, knownLength, knownCount, bfsLevelCount, requested, deleted;
      % Discuss: implement qedb_fetchVariables and move this !*rlverbose to qedb
      theo := qedb_getCurrentTheory(db);
      variables := qedb_getVariables(db);
      if !*rlverbose and !*rlqedfs then
         ioto_prin2t {" [DFS", if !*rlqedyn then " DYN]" else "]"};
      if !*rlverbose and not !*rlqedfs then
         ioto_prin2t {" [BFS: depth ", length(variables), "]"};
      f := qedb_getFormula(db);
      if !*rlqegsd then
         f := rl_gsn(f, theo, 'dnf);
      qedb_initializeWorkingNodes(db, if !*rlqedfs then 'dfs else 'bfs);
      if rl_op f eq 'or then
         for each subFormula in rl_argn f do
            qedb_addWorkingNodes(db, {qenod_new(variables, subFormula, nil)})
      else
         qedb_addWorkingNodes(db, {qenod_new(variables, f, nil)});
      while not qedb_isEmptyWorkingNodes(db) do <<
         if !*rlverbose and !*rlqedfs then <<
            maxLength . maxCount := qedb_workingNodesStatistics(db);
            if knownLength = 0 or maxLength < knownLength or (maxLength = knownLength and maxCount < knownCount) then <<
               knownLength := maxLength;
               knownCount := maxCount;
               ioto_prin2 {"[", knownLength, ":", knownCount, "] "}
            >>;
            if null qedb_firstWorkingNodeVariables(db) then ioto_prin2 ". "
         >>;
         if !*rlverbose and not !*rlqedfs then <<
            if bfsLevelCount = 0 then <<
               ioto_tprin2t {"-- left: ", length qedb_firstWorkingNodeVariables(db), " ", qedb_firstWorkingNodeVariables(db)};
               bfsLevelCount := qedb_numberOfWorkingNodes(db)
            >>;
            ioto_nterpri(length explode bfsLevelCount + 4);
            ioto_prin2 {"[", bfsLevelCount};
            bfsLevelCount := bfsLevelCount - 1
         >>;
         if !*rlqeidentify then on1 'rlidentify;
         cl_qevar_new(db);
         if !*rlverbose and not !*rlqedfs then ioto_prin2 "] ";
      >>;
      if !*rlverbose then  <<
         requested . deleted := qedb_fetchWorkingNodeDeletions(db);
         ioto_prin2 ioto_printListtoString {"[DEL ", requested, "/", deleted, " = ", (100.0 * requested) / deleted, "%]"}
      >>;
      return db
   end;

asserted procedure cl_qevar_new(db: Vector): Vector;
   % Quantifier elimination one variable. Successively tries specialized methods, followed by
   % regular virtual substitution, and processing of possible failure due to degree violations.
   % Discuss: Should return Boolean for success?
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
   % Transformation. Tries to transform the current node into an equivalent simpler problem. No
   % elimintaion takes place. This is used, e.g., for the degree shift with ofsf.
   begin scalar node, theo, noAssumeVars, produceAnswer, variables, answer, f, w, hasTransformed;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := qenod_getFormula(node);
      variables := qenod_getVariables(node);
      answer := qenod_getAnswer(node);
      hasTransformed := nil;
      for each variable in variables do <<
         w := rl_transform(variable, f, variables, answer, theo, produceAnswer, noAssumeVars);
         if w then <<
            hasTransformed := t;
            {f, variables, answer, theo, produceAnswer, noAssumeVars} := w
         >>;
      >>;
      if hasTransformed then <<
         % In the following we could benefit from mutable qenod
         node := qenod_new(variables, f, answer);
         qedb_setCurrentNode(db, node);
         qedb_setCurrentTheory(db, theo);
         qedb_setNoAssumeVars(db, noAssumeVars);
         qedb_setProduceAnswer(db, produceAnswer)  % should not be relevant
      >>;
      return hasTransformed
   end;

asserted procedure cl_gauss_new(db): Boolean;
   % Gaussian elimination. Tries to eliminate the current node using a generalization of Gaussian
   % elimination. The return value signals success.
   begin scalar w, node, theo, noAssumeVars, produceAnswer, f, variables, answer, variable,
                eliminationSet, nodes;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := qenod_getFormula(node);
      variables := qenod_getVariables(node);
      w := rl_trygauss(f, variables, theo, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      if !*rlverbose and not !*rlqedfs then ioto_prin2 "g";
      answer := qenod_getAnswer(node);
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
   % Special elimination Wrapper. A wrapper for using  the blackbox rl_specelim with the qedb model.
   % Special elimination tries to eliminate the current node using optimized elimination sets or,
   % more generally specialized methods that are expected to be more efficient than virtual
   % substitution on the current node. This is used, e.g., for the quadratic special case in ofsf.
   % The return value signals success.
   begin scalar w, node, theo, noAssumeVars, produceAnswer, f, variables, nodes;
      node := qedb_getCurrentNode(db);
      theo := qedb_getCurrentTheory(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      produceAnswer := qedb_getProduceAnwer(db);
      f := qenod_getFormula(node);
      variables := qenod_getVariables(node);
      w := rl_specelim(f, variables, theo, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      w . theo := w;
      ASSERT( car w eq t );
      nodes := cdr w;
      qedb_setCurrentTheory(db, theo);
      qedb_setCurrentNode(db, 'false);
      cl_storeRegularNodes(nodes, not null cdr variables, db);
      return t
   end;

asserted procedure cl_regularEliminationSet(db: Vector): Boolean;
   % Quantifier elimination using regular elimination set computation. This includes variable
   % selection via the blackbox rl_varsel and optional look-ahead for a list of candidates
   % delivered by varsel. The return value signals success in the sense that there was no degree
   % violation.
   begin scalar produceAnswer, noAssumeVars, theo, node, f, nodeVariables, nodeAnswer, found,
                candidateVariables, candidateVariable, alp, successorNodes, newTheory,
                bestSuccessorNodes, bestTheory, successorNodeVariables;
      produceAnswer := qedb_getProduceAnwer(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      theo := qedb_getCurrentTheory(db);
      node := qedb_getCurrentNode(db);
      f := qenod_getFormula(node);
      nodeVariables := qenod_getVariables(node);
      nodeAnswer := qenod_getAnswer(node);
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
            if !*rlverbose and not !*rlqedfs then ioto_prin2 "*";
            bestTheory := theo;
            successorNodeVariables := lto_delq(candidateVariable, nodeVariables);
            if produceAnswer then
               nodeAnswer := cl_updans(candidateVariable, 'arbitrary, nil, nil, nodeAnswer, produceAnswer);
            bestSuccessorNodes := {qenod_new(successorNodeVariables, f, nodeAnswer)};
            found := t;
            goto brk
         >> else if car alp neq 'failed then <<
            % Candidate variable is eliminable
            if !*rlverbose and not !*rlqedfs then ioto_prin2 "e";
            successorNodes . newTheory := cl_esetsubst_new(node, candidateVariable, rl_elimset(candidateVariable, alp), db);
            % Discuss: The pair arguments look strange. The theories are actually not used. The
            % rl_betterp blackbox is set to cl_betterp in all contexts. I have removed an
            % initial "not found" from the if condition because cl_betterp prints verbose output:
            if rl_betterp(successorNodes . newTheory, bestSuccessorNodes . bestTheory) then <<
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
   % Store a list of nodes in qedb. The nodes must uniformly fall into one of the
   % categories "working", "success", or "finished". The second argument helps to distinguish
   % between "working" and "finished". Discuss: Why "store *regular* nodes"? Could we drop the 2nd
   % arg and look at the vl of the first node?
   begin scalar successNodes;
      if not null nodes then <<
         if qenod_getVariables(car nodes) eq 'break then <<
            % We have found true
            qedb_initializeWorkingNodes(db, if !*rlqedfs then 'dfs else 'bfs);
            successNodes := qedb_getSuccessNodes(db);
            % With mutable qenod we could reuse the break node here
            successNodes := {qenod_new(nil, 'true, qenod_getAnswer(car nodes))};
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

asserted procedure cl_esetsubst_new(node: List, variable: Kernel, eliminationSet: List, db: Vector): DottedPair;
   % Work in progress.
   begin scalar produceAnswer, noAssumeVars, currentTheory, f, nodeVariables, nodeAnswer,
                successorNodeVariables, successorNodes, newTheory;
      produceAnswer := qedb_getProduceAnwer(db);
      noAssumeVars := qedb_getNoAssumeVars(db);
      currentTheory := qedb_getCurrentTheory(db);
      f := qenod_getFormula(node);
      nodeVariables := qenod_getVariables(node);
      nodeAnswer := qenod_getAnswer(node);
      successorNodeVariables := lto_delq(variable, nodeVariables);
      successorNodes . newTheory := cl_esetsubst(f, variable, eliminationSet, successorNodeVariables,
                                                 nodeAnswer, currentTheory, produceAnswer, noAssumeVars);
      return successorNodes . newTheory
   end;

asserted procedure cl_betterp_new(current: DottedPair, best: DottedPair): Boolean;
   % Both arguments are a pair of a lists of nodes and a theory. The theories are not used.
   begin integer currentNumberOfNodes, bestNumberOfNodes;
      currentNumberOfNodes := for each node in car current sum rl_atnum(qenod_getFormula(node));
      if !*rlverbose and not !*rlqedfs then ioto_prin2 {"(", currentNumberOfNodes, ")"};
      if best = '(nil . nil) then
         return t;
      bestNumberOfNodes := for each node in car best sum rl_atnum(qenod_getFormula(node));
      return currentNumberOfNodes < bestNumberOfNodes
   end;

endmodule;

end;
