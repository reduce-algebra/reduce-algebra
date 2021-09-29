module clqestate;

revision('clqestate, "$Id$");

copyright('clqestate, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define QESTATE_TAG 0
#define QESTATE_INPUTTHEORY 31
#define QESTATE_INPUTFORMULA 32
#define QESTATE_ANSWERMODE 33
#define QESTATE_ASSUMEMODE 34
#define QESTATE_NOASSUMEVARS 35
#define QESTATE_THEORY 36
#define QESTATE_FORMULA 37
#define QESTATE_ANSWER 38
#define QESTATE_BLOCKS 39
#define QESTATE_VARIABLES 40
#define QESTATE_PRODUCEANSWER 41
#define QESTATE_WORKINGNODES 42
#define QESTATE_SUCCESSNODES 43
#define QESTATE_FAILURENODES 44
#define QESTATE_CURRENTNODE 45
#define QESTATE_BFSLEVELCOUNT 46
#define QESTATE_UPLIM 46

asserted procedure QeState_new(): Vector;
   begin scalar state;
      state := QeEnv_new();
      ASSERT( upbv(state) = QESTATE_UPLIM );
      putv(state, QESTATE_TAG, 'QeState);
      % The following fields are constant, i.e., assigned exactly once after the creation of qestate:
      putv(state, QESTATE_INPUTTHEORY, 'undefined);        % InputTheory
      putv(state, QESTATE_INPUTFORMULA, 'undefined);       % InputTheory
      putv(state, QESTATE_ANSWERMODE, 'undefined);         % AnswerMode; 'raw, 'standard, or nil
      putv(state, QESTATE_ASSUMEMODE, 'undefined);         % AssumeMode; 'full, 'monomial, or nil
      putv(state, QESTATE_NOASSUMEVARS, 'undefined);       % NoAssumeVars; do not make assumptions on these variables, includes quantified variables
      % The following fields change during execution:
      putv(state, QESTATE_THEORY, 'undefined);             % Theory
      putv(state, QESTATE_FORMULA, 'undefined);            % matrix formula of the current block
      putv(state, QESTATE_ANSWER, 'undefined);
      putv(state, QESTATE_BLOCKS, 'undefined);
      putv(state, QESTATE_VARIABLES, 'undefined);          % list of existentially quantified variables to be eliminated
      putv(state, QESTATE_PRODUCEANSWER, 'undefined);      % ProduceAnswer: Boolean
      putv(state, QESTATE_WORKINGNODES, 'undefined);       % WorkingNodes; container
      putv(state, QESTATE_SUCCESSNODES, 'undefined);       % SuccessNodes; list
      putv(state, QESTATE_FAILURENODES, 'undefined);       % FailureNodes; list
      putv(state, QESTATE_CURRENTNODE, 'undefined);        % WorkingNodes; container
      putv(state, QESTATE_BFSLEVELCOUNT, 'undefined);      % number of working nodes with current number of variables
      return state
   end;

asserted procedure QeState_print(state: Vector): Vector;
   begin scalar !*nat, indent, inputTheory, inputFormula, theory, formula, container;
      indent := "  ";
      ioto_tprin2t {"{"};
      ioto_tprin2t {indent, "Class:         ", getv(state, QESTATE_TAG)};
      inputTheory := getv(state, QESTATE_INPUTTHEORY);
      if inputTheory neq 'undefined then
         inputTheory := ioto_smaprin('list . for each f in inputTheory collect rl_prepfof f);
      ioto_tprin2t {indent, "InputTheory:   ", inputTheory};
      inputFormula := getv(state, QESTATE_INPUTFORMULA);
      if inputFormula neq 'undefined then
         inputFormula := ioto_smaprin rl_prepfof inputFormula;
      ioto_tprin2t {indent, "InputFormula:  ", inputFormula};
      ioto_tprin2t {indent, "AnswerMode:    ", getv(state, QESTATE_ANSWERMODE)};
      ioto_tprin2t {indent, "AssumeMode:    ", getv(state, QESTATE_ASSUMEMODE)};
      ioto_tprin2t {indent, "NoAssumeVars:  ", getv(state, QESTATE_NOASSUMEVARS)};
      theory := getv(state, QESTATE_THEORY);
      if theory neq 'undefined then
         theory := ioto_smaprin('list . for each f in theory collect rl_prepfof f);
      ioto_tprin2t {indent, "Theory:        ", theory};
      formula := getv(state, QESTATE_FORMULA);
      if formula neq 'undefined then
         formula := ioto_smaprin rl_prepfof formula;
      ioto_tprin2  {indent, "Formula:       ", formula};
      ioto_tprin2t {indent, "Answer:        ", getv(state, QESTATE_ANSWER)};
      ioto_tprin2t {indent, "Blocks:        ", getv(state, QESTATE_BLOCKS)};
      ioto_tprin2t {indent, "Variables:     ", getv(state, QESTATE_VARIABLES)};
      ioto_tprin2t {indent, "ProduceAnswer: ", getv(state, QESTATE_PRODUCEANSWER)};
      ioto_tprin2  {indent, "WorkingNodes:  "};
      container := getv(state, QESTATE_WORKINGNODES);
      if container neq 'undefined then
         QeCont_print(container, "  ")
      else
         ioto_prin2 {'undefined};
      ioto_tprin2  {indent, "SuccessNodes:  "};
      QeNode_printList(getv(state, QESTATE_SUCCESSNODES), indent);
      ioto_tprin2 {indent, "FailureNodes:  "};
      QeNode_printList(getv(state, QESTATE_FAILURENODES), indent);
      ioto_tprin2t {indent, "CurrentNode:   ", getv(state, QESTATE_CURRENTNODE)};
      ioto_tprin2t {"}"};
      return state
   end;

asserted procedure QeState_fetchBlock(state: Vector): DottedPair;
   begin scalar blocks, nextBlock, quantifier, variables;
      blocks := getv(state, QESTATE_BLOCKS);
      nextBlock := pop blocks;
      putv(state, QESTATE_BLOCKS, blocks);
      if !*rlverbose and QeEnv_getVb(state) then <<
         quantifier . variables := nextBlock;
         ioto_tprin2 {"---- ", (quantifier . reverse variables)}
      >>;
      return nextBlock
   end;

asserted procedure QeState_addBlock(state: Vector, block: DottedPair): Vector;
   putv(state, QESTATE_BLOCKS, block . getv(state, QESTATE_BLOCKS));

asserted procedure QeState_isEmptyBlocks(state: Vector): Boolean;
   null getv(state, QESTATE_BLOCKS);

asserted procedure QeState_fetchVariables(state: Vector): List;
   begin scalar variables;
      variables := getv(state, QESTATE_VARIABLES);
      putv(state, QESTATE_VARIABLES, nil);
      if !*rlverbose and QeEnv_getVb(state) and QeEnv_getDfs(state) then <<
         ioto_prin2 {" [DFS"};
         if QeEnv_getDyn(state) then ioto_prin2 {" DYN"};
         ioto_prin2 {"] "}
      >>;
      if !*rlverbose and QeEnv_getVb(state) and not QeEnv_getDfs(state) then <<
         ioto_prin2 {" [BFS: depth ", length(variables), "] "}
      >>;
      return variables
   end;

asserted procedure QeState_initializeWorkingNodes(state: Vector): Vector;
   begin scalar traversalMode, dynamicProgramming;
      traversalMode := if QeEnv_getDfs(state) then 'dfs else 'bfs;
      dynamicProgramming := QeEnv_getDyn(state);
      putv(state, QESTATE_WORKINGNODES, QeCont_new(traversalMode, dynamicProgramming));
      if !*rlverbose and QeEnv_getVb(state) then
         putv(state, QESTATE_BFSLEVELCOUNT, 0);
      return state
   end;

asserted procedure QeState_fetchWorkingNode(state: Vector): List;
   begin scalar node;
         integer bfsLevelCount;
      if !*rlverbose and QeEnv_getVb(state) and QeEnv_getDfs(state) then <<
            ioto_prin2 ioto_printListToString {QeState_workingNodesStatistics(state)};
      >>;
      if !*rlverbose and QeEnv_getVb(state) and not QeEnv_getDfs(state) then <<
         bfsLevelCount := getv(state, QESTATE_BFSLEVELCOUNT);
         if bfsLevelCount = 0 then <<
            ioto_tprin2 {"-- left: ", length QeState_firstWorkingNodeVariables(state)};
            ioto_prin2t {" ", QeState_firstWorkingNodeVariables(state)};
            bfsLevelCount := QeState_numberOfWorkingNodes(state)
         >>;
         ioto_prin2 {bfsLevelCount};
         bfsLevelCount := bfsLevelCount - 1;
         putv(state, QESTATE_BFSLEVELCOUNT, bfsLevelCount)
      >>;
      node := QeCont_fetch(getv(state, QESTATE_WORKINGNODES));
      return node
   end;

asserted procedure QeState_firstWorkingNode(state: Vector): List;
   QeCont_firstNode(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_addWorkingNodes(state: Vector, nodes: List): Vector;
   <<
      QeCont_add(getv(state, QESTATE_WORKINGNODES), nodes);
      state
   >>;

asserted procedure QeState_isEmptyWorkingNodes(state: Vector): Boolean;
   QeCont_isEmpty(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_fetchSuccessNodes(state: Vector): List;
   begin scalar successNodes;
      successNodes := getv(state, QESTATE_SUCCESSNODES);
      putv(state, QESTATE_SUCCESSNODES, nil);
      return successNodes
   end;

asserted procedure QeState_fetchFailureNodes(state: Vector): List;
   begin scalar failureNodes;
      failureNodes := getv(state, QESTATE_FAILURENODES);
      putv(state, QESTATE_FAILURENODES, nil);
      return failureNodes
   end;

% The following qestate methods are used for verbose output.

asserted procedure QeState_numberOfWorkingNodes(state: Vector): Integer;
   % This is used for verbose output with DFS.
   QeCont_length(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_fetchWorkingNodeDeletions(state: Vector): DottedPair;
   begin scalar container;
         integer requested, deleted, p;
      container := getv(state, QESTATE_WORKINGNODES);
      requested := QeCont_getRequestedAdditions(container);
      deleted := requested - QeCont_getEffectiveAdditions(container);
      if !*rlverbose and QeEnv_getVb(state) then <<
         p := (100.0 * deleted) / requested;
         ioto_prin2 ioto_printListToString {"[DEL ", deleted, "/", requested, " = ", p, "%]"}
      >>;
      QeCont_setRequestedAdditions(container, 0);
      QeCont_setEffectiveAdditions(container, 0);
      return deleted . requested
   end;

asserted procedure QeState_workingNodesStatistics(state: Vector): DottedPair;
   % Returns the maximum length of the "Variables" fields in the working nodes, along with the
   % number of occurrences of corresponding nodes. This is used for verbose output with DFS.
   QeCont_statistics(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_firstWorkingNodeVariables(state: Vector): List;
   % Returns the "Variables" field of the firstworking node. This is used for verbose output with
   % DFS.
   QeNode_getVariables(QeCont_firstNode(getv(state, QESTATE_WORKINGNODES)));

% Getters and setters

asserted procedure QeState_getInputTheory(state: Vector): Theory;
   getv(state, QESTATE_INPUTTHEORY);

asserted procedure QeState_setInputTheory(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_INPUTTHEORY, theory); state >>;

asserted procedure QeState_getInputFormula(state: Vector): Formula;
   getv(state, QESTATE_INPUTFORMULA);

asserted procedure QeState_setInputFormula(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_INPUTFORMULA, theory); state >>;

asserted procedure QeState_getAnswerMode(state: Vector): Id;
   getv(state, QESTATE_ANSWERMODE);

asserted procedure QeState_setAnswerMode(state: Vector, mode: Id): Vector;
   << putv(state, QESTATE_ANSWERMODE, mode); state >>;

asserted procedure QeState_getAssumeMode(state: Vector): Id;
   getv(state, QESTATE_ASSUMEMODE);

asserted procedure QeState_setAssumeMode(state: Vector, mode: Id): Vector;
   << putv(state, QESTATE_ASSUMEMODE, mode); state >>;

asserted procedure QeState_getNoAssumeVars(state: Vector): List;
   getv(state, QESTATE_NOASSUMEVARS);

asserted procedure QeState_setNoAssumeVars(state: Vector, vars: List): Vector;
   << putv(state, QESTATE_NOASSUMEVARS, vars); state >>;

asserted procedure QeState_getTheory(state: Vector): Theory;
   getv(state, QESTATE_THEORY);

asserted procedure QeState_setTheory(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_THEORY, theory); state >>;

asserted procedure QeState_getFormula(state: Vector): Formula;
   getv(state, QESTATE_FORMULA);

asserted procedure QeState_setFormula(state: Vector, f: Formula): Vector;
   << putv(state, QESTATE_FORMULA, f); state >>;

asserted procedure QeState_getAnswer(state: Vector): List;
   getv(state, QESTATE_ANSWER);

asserted procedure QeState_setAnswer(state: Vector, answer: List): Vector;
   << putv(state, QESTATE_ANSWER, answer); state >>;

asserted procedure QeState_getBlocks(state: Vector): List;
   getv(state, QESTATE_BLOCKS);

asserted procedure QeState_setBlocks(state: Vector, blocks: List): Vector;
   << putv(state, QESTATE_BLOCKS, blocks); state >>;

asserted procedure QeState_getVariables(state: Vector): List;
   getv(state, QESTATE_VARIABLES);

asserted procedure QeState_setVariables(state: Vector, vars: List): Vector;
   << putv(state, QESTATE_VARIABLES, vars); state >>;

asserted procedure QeState_getProduceAnwer(state: Vector): Boolean;
   getv(state, QESTATE_PRODUCEANSWER);

asserted procedure QeState_setProduceAnswer(state: Vector, ans: Boolean): Vector;
   << putv(state, QESTATE_PRODUCEANSWER, ans); state >>;

asserted procedure QeState_getSuccessNodes(state: Vector): List;
   getv(state, QESTATE_SUCCESSNODES);

asserted procedure QeState_setSuccessNodes(state: Vector, nodes: List): Vector;
   << putv(state, QESTATE_SUCCESSNODES, nodes); state >>;

asserted procedure QeState_getFailureNodes(state: Vector): List;
   getv(state, QESTATE_FAILURENODES);

asserted procedure QeState_setFailureNodes(state: Vector, nodes: List): Vector;
   << putv(state, QESTATE_FAILURENODES, nodes); state >>;

asserted procedure QeState_getCurrentNode(state: Vector): List;
   getv(state, QESTATE_CURRENTNODE);

asserted procedure QeState_setCurrentNode(state: Vector, node: List): Vector;
   << putv(state, QESTATE_CURRENTNODE, node); state >>;

endmodule;

end;
