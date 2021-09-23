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

asserted procedure cl_qe_new(f: Formula, theory: FormulaL): Formula;
   % Quantifier elimination. Eliminate as many quantifiers as possible from f,
   % yielding a formula g such that theory |= f <=> g.
   begin scalar state, !*rlsipo, !*rlsipw;
      !*rlsipo := t;
      !*rlsipw := t;
      state := QeState_new();
      QeState_setInputFormula(state, f);
      QeState_setInputTheory(state, theory);
      QeState_setNoAssumeVars(state, nil);
      QeState_setAnswerMode(state, nil);
      QeState_setAssumeMode(state, nil);
      state := cl_qe1_new(state);
      if rl_excp(state) then
         return state;
      return QeState_getFormula(state)
   end;

asserted procedure cl_qea_new(f: Formula, theory: FormulaL): List;
   % Extended quantifier elimination (aka "with answer").
   begin scalar state, !*rlqeans, !*rlsipo, !*rlsipw;
      !*rlqeans := t;
      !*rlsipo := t;
      !*rlsipw := t;
      state := QeState_new();
      QeState_setInputFormula(state, f);
      QeState_setInputTheory(state, theory);
      QeState_setNoAssumeVars(state, nil);
      % Standard answers work only for decision problems. The old procedure
      % did not check this and rederr() could happen in the ANU module. We
      % now check this here, but we should think about checking later.
      QeState_setAssumeMode(state, nil);
      QeState_setAnswerMode(state, if !*rlqestdans and null rl_fvarl f then 'standard else 'raw);
      state := cl_qe1_new(state);
      if rl_excp(state) then
         return state;
      return QeState_getAnswer(state)
   end;

asserted procedure cl_gqe_new(f: Formula, theory: FormulaL, xNoAssumeVars: KernelL): DottedPair;
   % Generic quantifier elimination. Eliminate as many quantifiers as possible
   % from f, yielding a formula g such that theory |= f <=> g. The procedure is
   % allowed to assume inequations on parameters that are not in
   % xNoAssumeVars. Those assumptions are added to theory.
   begin scalar state, !*rlqegen, !*rlsipo, !*rlsipw;
      !*rlqegen := t;
      !*rlsipo := t;
      !*rlsipw := t;
      state := QeState_new();
      QeState_setInputFormula(state, f);
      QeState_setInputTheory(state, theory);
      QeState_setNoAssumeVars(state, xNoAssumeVars);
      QeState_setAssumeMode(state, if !*rlqegenct then 'full else 'monomial);
      QeState_setAnswerMode(state, nil);
      state := cl_qe1_new(state);
      if rl_excp(state) then
         return state;
      % The old procedure applies rl_thsimpl(). This must be checked.
      return QeState_getCurrentTheory(state) . QeState_getFormula(state)
   end;

asserted procedure cl_gqea_new(f: Formula, theory: FormulaL, xNoAssumeVars: KernelL): DottedPair;
   % Generic extended quantifier elimination (aka "with answer").
   begin scalar state, !*rlqeans, !*rlqegen, !*rlsipo, !*rlsipw;
      !*rlqegen := t;
      !*rlqeans := t;
      !*rlsipo := t;
      !*rlsipw := t;
      state := QeState_new();
      QeState_setInputFormula(state, f);
      QeState_setInputTheory(state, theory);
      QeState_setNoAssumeVars(state, xNoAssumeVars);
      QeState_setAssumeMode(state, if !*rlqegenct then 'full else 'monomial);
      QeState_setAnswerMode(state, if !*rlqestdans and null rl_fvarl f then'standard else 'raw);
      state := cl_qe1_new(state);
      if rl_excp(state) then
         return state;
      % The old procedure applies rl_thsimpl(). This must be checked.
      return QeState_getCurrentTheory(state) . QeState_getAnswer(state)
   end;

asserted procedure cl_qe1_new(state: Vector): Vector;
   % Quantifier elimination. Compute a prenex normal form of the input formula, split it into
   % quantifier blocks and the quantifier-free matrix, and prepare the state accordingly. Pass the
   % state to another function, which iterates elimination over the quantifier blocks. If virtual
   % subtituation has failed at some point due to degree violations, requantify the elimination
   % result with the remaining quantifiers. Optionally apply a fallback quantifier elimination
   % method.
   begin scalar f, theory, answer, blocks, allQuantifiedVariables, point;
         integer n;
      f := QeState_getInputFormula(state);
      theory := QeState_getInputTheory(state);
      f := rl_pnf f;
      {blocks, f, allQuantifiedVariables} := cl_split_new f;
      if null blocks then <<
         if not null QeState_getAnswerMode(state) then
            QeState_setAnswer(state, {f . nil});
         return state
      >>;
      f := rl_simpl(f, theory, -1);
      if rl_excp(f) then
         return f;
      % Remove from the theory atomic formulas containing quantified variables
      QeState_setCurrentTheory(state, for each atf in theory join if null intersection(rl_varlat atf, allQuantifiedVariables) then {atf});
      % Prohibit assumptions on quantified variables:
      QeState_setNoAssumeVars(state, union(allQuantifiedVariables, QeState_getNoAssumeVars(state)));
      QeState_setBlocks(state, blocks);
      QeState_setFormula(state, f);
      cl_qe1!-iterate_new(state);
      blocks := QeState_getBlocks(state);
      theory := QeState_getCurrentTheory(state);
      % Discuss: I had to bind f here for the verbose message. With a QeState_simplifyFormula method
      % the verbose could be moved there. I think this would go beyond the fetch methods suggested
      % elsewhere, and I have some doubts.
      f := QeState_getFormula(state);
      % Discuss: In the old version the following verbose output does not show up with
      % "rlqea ex(x, m*x+b=0);"
      if !*rlverbose then ioto_tprin2 {"+++ Final simplification ... ", cl_atnum f, " -> "};
      % We deliberately lose quantifers over non-occurring variables.
      f := cl_simpl(cl_unsplit_new(blocks, f), theory, -1);
      if !*rlverbose then ioto_prin2t cl_atnum f;
      if QeState_getAnswerMode(state) then <<
         % At present, we always requantify; no fallback QE with answers.
         if null blocks or null cdr blocks then <<
            % We have finished or at least reached the outmost block.
            if !*rlverbose then <<
               ioto_tprin2 "+++ Postprocessing answer:";
               n := length(QeState_getSuccessNodes(state)) + length(QeState_getFailureNodes(state))
            >>;
            answer := for each node in append(QeState_getSuccessNodes(state), QeState_getFailureNodes(state)) collect <<
               if !*rlverbose then ioto_prin2 {" [", n := n - 1};
               point := rl_qemkans(QeNode_getAnswer(node)) where !*rlqestdans = (QeState_getAnswerMode(state) eq 'standard);
               if !*rlverbose then ioto_prin2 {"]"};
               cl_unsplit_new(blocks, QeNode_getFormula(node)) . point
            >>
         >> else
            answer := {f . nil};
         QeState_setFormula(state, f);
         QeState_setAnswer(state, answer);
         return state
      >>;
      if !*rlqefb and rl_quap rl_op f then <<
         if !*rlverbose then ioto_tprin2 {"++++ Entering fallback QE: "};
         theory . f := rl_fbqe(f, theory)
      >>;
      QeState_setCurrentTheory(state, theory);
      QeState_setFormula(state, f);
      return state
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

asserted procedure cl_qe1!-iterate_new(state: Vector): Vector;
   % Iterate over quantifier blocks. The blocks are successively eliminated from the inside to the
   % outside. Universal quantifier blocks are reduced to existential ones via logical negation.
   begin scalar blocks, f, produceAnswer, theory, state, svrlidentify, svrlqeprecise, svrlqeaprecise,
                quantifier, variables, remainingVariables, tmpNodes, op, arguments;
      svrlidentify := !*rlidentify;
      f := QeState_getFormula(state);
      theory := QeState_getInputTheory(state);
      ASSERT( not null blocks );
      while not QeState_isEmptyBlocks(state) and null remainingVariables do <<
         quantifier . variables := QeState_fetchBlock(state);
         % Discuss: implement QeState_fetchBlocks and move this !*rlverbose to QeState
         if !*rlverbose then
            ioto_tprin2 {"---- ", (quantifier . reverse variables)};
         QeState_setVariables(state, variables);
         produceAnswer := QeState_getAnswerMode(state) and QeState_isEmptyBlocks(state);
         QeState_setProduceAnswer(state, produceAnswer);
         svrlqeprecise := !*rlqeprecise;
         svrlqeaprecise := !*rlqeaprecise;
         if not QeState_isEmptyBlocks(state) then <<  % Should better be an argument of qeblock ...
            off1 'rlqeprecise;
            off1 'rlqeaprecise
         >>;
         if quantifier eq 'all then
            f := rl_simpl(rl_nnfnot f, theory, -1);
         QeState_setFormula(state, f);
         QeState_setSuccessNodes(state, nil);
         QeState_setFailureNodes(state, nil);
         QeState_setCurrentTheory(state, theory);
         cl_qeblock4_new(state);
         if quantifier eq 'all then <<
            % In the following we could benefit from mutable QeNode
            tmpNodes := for each node in QeState_getSuccessNodes(state) collect
               QeNode_new(QeNode_getVariables(node), rl_nnfnot(QeNode_getFormula(node)), QeNode_getAnswer(node));
            QeState_setSuccessNodes(state, tmpNodes);
            tmpNodes := for each node in QeState_getFailureNodes(state) collect
               QeNode_new(QeNode_getVariables(node), rl_nnfnot(QeNode_getFormula(node)), QeNode_getAnswer(node));
            QeState_setFailureNodes(state, tmpNodes)
         >>;
         op := if quantifier eq 'all then 'and else 'or;
         arguments := for each node in append(QeState_getSuccessNodes(state), QeState_getFailureNodes(state)) collect
            QeNode_getFormula(node);
         f := rl_smkn(op, arguments);
         if not null QeState_getFailureNodes(state) then
            for each node in QeState_getFailureNodes(state) do
               remainingVariables := union(remainingVariables, QeNode_getVariables(node));
         theory := QeState_getCurrentTheory(state);
         if not QeState_isEmptyBlocks(state) then <<
            onoff('rlqeprecise, svrlqeprecise);
            onoff('rlqeaprecise, svrlqeaprecise)
         >>
      >>;
      onoff('rlidentify, svrlidentify);
      if not null remainingVariables then
         QeState_addBlock(state, quantifier . remainingVariables);
      QeState_setFormula(state, f);
      return state
   end;

asserted procedure cl_qeblock4_new(state: Vector): Vector;
   % Eliminate a block of prenex existential quantifiers. The quantified variables and the matrix
   % formula haven already been identified and stored in QeState. The existential block could be the
   % logical negation of a universal block from the original input. The corresponding negation and
   % back-negation takes place outside this procedure.
   begin scalar f, variables, theory;
         integer maxLength, maxCount, knownLength, knownCount, bfsLevelCount, requested, deleted;
      % Discuss: implement QeState_fetchVariables and move this !*rlverbose to QeState
      theory := QeState_getCurrentTheory(state);
      variables := QeState_getVariables(state);
      if !*rlverbose and !*rlqedfs then
         ioto_prin2t {" [DFS", if !*rlqedyn then " DYN]" else "]"};
      if !*rlverbose and not !*rlqedfs then
         ioto_prin2t {" [BFS: depth ", length(variables), "]"};
      f := QeState_getFormula(state);
      if !*rlqegsd then
         f := rl_gsn(f, theory, 'dnf);
      QeState_initializeWorkingNodes(state, if !*rlqedfs then 'dfs else 'bfs);
      if rl_op f eq 'or then
         for each subFormula in rl_argn f do
            QeState_addWorkingNodes(state, {QeNode_new(variables, subFormula, nil)})
      else
         QeState_addWorkingNodes(state, {QeNode_new(variables, f, nil)});
      while not QeState_isEmptyWorkingNodes(state) do <<
         if !*rlverbose and !*rlqedfs then <<
            maxLength . maxCount := QeState_workingNodesStatistics(state);
            if knownLength = 0 or maxLength < knownLength or (maxLength = knownLength and maxCount < knownCount) then <<
               knownLength := maxLength;
               knownCount := maxCount;
               ioto_prin2 {"[", knownLength, ":", knownCount, "] "}
            >>;
            if null QeState_firstWorkingNodeVariables(state) then ioto_prin2 ". "
         >>;
         if !*rlverbose and not !*rlqedfs then <<
            if bfsLevelCount = 0 then <<
               ioto_tprin2t {"-- left: ", length QeState_firstWorkingNodeVariables(state), " ", QeState_firstWorkingNodeVariables(state)};
               bfsLevelCount := QeState_numberOfWorkingNodes(state)
            >>;
            ioto_nterpri(length explode bfsLevelCount + 4);
            ioto_prin2 {"[", bfsLevelCount};
            bfsLevelCount := bfsLevelCount - 1
         >>;
         if !*rlqeidentify then on1 'rlidentify;
         cl_qevar_new(state);
         if !*rlverbose and not !*rlqedfs then ioto_prin2 "] ";
      >>;
      if !*rlverbose then  <<
         requested . deleted := QeState_fetchWorkingNodeDeletions(state);
         ioto_prin2 ioto_printListtoString {"[DEL ", requested, "/", deleted, " = ", (100.0 * requested) / deleted, "%]"}
      >>;
      return state
   end;

asserted procedure cl_qevar_new(state: Vector): Vector;
   % Quantifier elimination one variable. Successively tries specialized methods, followed by
   % regular virtual substitution, and processing of possible failure due to degree violations.
   % Discuss: Should return Boolean for success?
   begin scalar node, failureNodes;
      node := QeState_fetchWorkingNode(state);
      QeState_setCurrentNode(state, node);
      cl_transform_new(state);
      if cl_gauss_new(state) then
         return state;
      if cl_specelimWrapper_new(state) then
         return state;
      if cl_regularEliminationSet(state) then
         return state;
      node := QeState_getCurrentNode(state);
      QeState_setCurrentNode(state, 'false);
      failureNodes := QeState_getFailureNodes(state);
      failureNodes := lto_insert(node, failureNodes);
      QeState_setFailureNodes(state, failureNodes);
      return state
   end;

asserted procedure cl_transform_new(state: Vector): Boolean;
   % Transformation. Tries to transform the current node into an equivalent simpler problem. No
   % elimintaion takes place. This is used, e.g., for the degree shift with ofsf.
   begin scalar node, theory, noAssumeVars, produceAnswer, variables, answer, f, w, hasTransformed;
      node := QeState_getCurrentNode(state);
      theory := QeState_getCurrentTheory(state);
      noAssumeVars := QeState_getNoAssumeVars(state);
      produceAnswer := QeState_getProduceAnwer(state);
      f := QeNode_getFormula(node);
      variables := QeNode_getVariables(node);
      answer := QeNode_getAnswer(node);
      hasTransformed := nil;
      for each variable in variables do <<
         w := rl_transform(variable, f, variables, answer, theory, produceAnswer, noAssumeVars);
         if w then <<
            hasTransformed := t;
            {f, variables, answer, theory, produceAnswer, noAssumeVars} := w
         >>;
      >>;
      if hasTransformed then <<
         % In the following we could benefit from mutable qenod
         node := QeNode_new(variables, f, answer);
         QeState_setCurrentNode(state, node);
         QeState_setCurrentTheory(state, theory);
         QeState_setNoAssumeVars(state, noAssumeVars);
         QeState_setProduceAnswer(state, produceAnswer)  % should not be relevant
      >>;
      return hasTransformed
   end;

asserted procedure cl_gauss_new(state): Boolean;
   % Gaussian elimination. Tries to eliminate the current node using a generalization of Gaussian
   % elimination. The return value signals success.
   begin scalar w, node, theory, noAssumeVars, produceAnswer, f, variables, answer, variable,
                eliminationSet, nodes;
      node := QeState_getCurrentNode(state);
      theory := QeState_getCurrentTheory(state);
      noAssumeVars := QeState_getNoAssumeVars(state);
      produceAnswer := QeState_getProduceAnwer(state);
      f := QeNode_getFormula(node);
      variables := QeNode_getVariables(node);
      w := rl_trygauss(f, variables, theory, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      if !*rlverbose and not !*rlqedfs then ioto_prin2 "g";
      answer := QeNode_getAnswer(node);
      variable . eliminationSet := car w;
      theory := cdr w;
      variables := lto_delq(variable, variables);
      nodes . theory := cl_esetsubst(f, variable, eliminationSet, variables, answer, theory, produceAnswer, noAssumeVars);
      QeState_setCurrentTheory(state, theory);
      QeState_setCurrentNode(state, 'false);
      cl_storeRegularNodes(nodes, not null variables, state);  % no cdr here!
      return t
   end;

asserted procedure cl_specelimWrapper_new(state): Boolean;
   % Special elimination Wrapper. A wrapper for using  the blackbox rl_specelim with the QeState model.
   % Special elimination tries to eliminate the current node using optimized elimination sets or,
   % more generally specialized methods that are expected to be more efficient than virtual
   % substitution on the current node. This is used, e.g., for the quadratic special case in ofsf.
   % The return value signals success.
   begin scalar w, node, theory, noAssumeVars, produceAnswer, f, variables, nodes;
      node := QeState_getCurrentNode(state);
      theory := QeState_getCurrentTheory(state);
      noAssumeVars := QeState_getNoAssumeVars(state);
      produceAnswer := QeState_getProduceAnwer(state);
      f := QeNode_getFormula(node);
      variables := QeNode_getVariables(node);
      w := rl_specelim(f, variables, theory, produceAnswer, noAssumeVars);
      if w eq 'failed then
         return nil;
      w . theory := w;
      ASSERT( car w eq t );
      nodes := cdr w;
      QeState_setCurrentTheory(state, theory);
      QeState_setCurrentNode(state, 'false);
      cl_storeRegularNodes(nodes, not null cdr variables, state);
      return t
   end;

asserted procedure cl_regularEliminationSet(state: Vector): Boolean;
   % Quantifier elimination using regular elimination set computation. This includes variable
   % selection via the blackbox rl_varsel and optional look-ahead for a list of candidates
   % delivered by varsel. The return value signals success in the sense that there was no degree
   % violation.
   begin scalar produceAnswer, noAssumeVars, theory, node, f, nodeVariables, nodeAnswer, found,
                candidateVariables, candidateVariable, alp, successorNodes, newTheory,
                bestSuccessorNodes, bestTheory, successorNodeVariables;
         integer len;
      produceAnswer := QeState_getProduceAnwer(state);
      noAssumeVars := QeState_getNoAssumeVars(state);
      theory := QeState_getCurrentTheory(state);
      node := QeState_getCurrentNode(state);
      f := QeNode_getFormula(node);
      nodeVariables := QeNode_getVariables(node);
      nodeAnswer := QeNode_getAnswer(node);
      candidateVariables := if null cdr nodeVariables then
         nodeVariables
      else if not !*rlqevarsel then
         {car nodeVariables}
      else
         rl_varsel(f, nodeVariables, theory);
      found := nil;
      if !*rlverbose and not !*rlqedfs and (len := length candidateVariables) > 1 then ioto_prin2 {"{", len, ":"};
      while candidateVariables do <<
         candidateVariable := pop candidateVariables;
         alp := cl_qeatal(f, candidateVariable, theory, produceAnswer);
         if alp = '(nil . nil) then <<
            % Candidate variable does not occur in f
            if !*rlverbose and not !*rlqedfs then ioto_prin2 "*";
            bestTheory := theory;
            successorNodeVariables := lto_delq(candidateVariable, nodeVariables);
            if produceAnswer then
               nodeAnswer := cl_updans(candidateVariable, 'arbitrary, nil, nil, nodeAnswer, produceAnswer);
            bestSuccessorNodes := {QeNode_new(successorNodeVariables, f, nodeAnswer)};
            found := t;
            goto brk
         >> else if car alp neq 'failed then <<
            % Candidate variable is eliminable
            if !*rlverbose and not !*rlqedfs then ioto_prin2 "e";
            successorNodes . newTheory := cl_esetsubst_new(node, candidateVariable, rl_elimset(candidateVariable, alp), state);
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
      if !*rlverbose and not !*rlqedfs and len > 1 then ioto_prin2 {"}"};
      if not found then
         return nil;
      QeState_setCurrentTheory(state, bestTheory);
      cl_storeRegularNodes(bestSuccessorNodes, not null cdr nodeVariables, state);
      QeState_setCurrentNode(state, 'false);
      return t
   end;

asserted procedure cl_storeRegularNodes(nodes: List, variablesLeft: Boolean, state: Vector): Vector;
   % Store a list of nodes in QeState. The nodes must uniformly fall into one of the
   % categories "working", "success", or "finished". The second argument helps to distinguish
   % between "working" and "finished". Discuss: Why "store *regular* nodes"? Could we drop the 2nd
   % arg and look at the vl of the first node?
   begin scalar successNodes;
      if not null nodes then <<
         if QeNode_getVariables(car nodes) eq 'break then <<
            % We have found true
            QeState_initializeWorkingNodes(state, if !*rlqedfs then 'dfs else 'bfs);
            successNodes := QeState_getSuccessNodes(state);
            % With mutable QeNode we could reuse the break node here
            successNodes := {QeNode_new(nil, 'true, QeNode_getAnswer(car nodes))};
            QeState_setSuccessNodes(state, successNodes);
            QeState_setFailureNodes(state, nil)
         >> else if variablesLeft then <<
            QeState_addworkingNodes(state, nodes)
         >> else <<
            successNodes := QeState_getSuccessNodes(state);
            for each node in nodes do
               successNodes := lto_insert(node, successNodes);
            QeState_setSuccessNodes(state, successNodes)
         >>
      >>;
      return state
   end;

asserted procedure cl_esetsubst_new(node: List, variable: Kernel, eliminationSet: List, state: Vector): DottedPair;
   % Work in progress.
   begin scalar produceAnswer, noAssumeVars, currentTheory, f, nodeVariables, nodeAnswer,
                successorNodeVariables, successorNodes, newTheory;
      produceAnswer := QeState_getProduceAnwer(state);
      noAssumeVars := QeState_getNoAssumeVars(state);
      currentTheory := QeState_getCurrentTheory(state);
      f := QeNode_getFormula(node);
      nodeVariables := QeNode_getVariables(node);
      nodeAnswer := QeNode_getAnswer(node);
      successorNodeVariables := lto_delq(variable, nodeVariables);
      successorNodes . newTheory := cl_esetsubst(f, variable, eliminationSet, successorNodeVariables,
                                                 nodeAnswer, currentTheory, produceAnswer, noAssumeVars);
      return successorNodes . newTheory
   end;

asserted procedure cl_betterp_new(current: DottedPair, best: DottedPair): Boolean;
   % Both arguments are a pair of a lists of nodes and a theory. The theories are not used.
   begin integer currentNumberOfNodes, bestNumberOfNodes;
      currentNumberOfNodes := for each node in car current sum rl_atnum(QeNode_getFormula(node));
      if !*rlverbose and not !*rlqedfs then ioto_prin2 {"(", currentNumberOfNodes, ")"};
      if best = '(nil . nil) then
         return t;
      bestNumberOfNodes := for each node in car best sum rl_atnum(QeNode_getFormula(node));
      return currentNumberOfNodes < bestNumberOfNodes
   end;

endmodule;

end;
