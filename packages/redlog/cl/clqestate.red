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
#define QESTATE_INPUTFORMULA 1
#define QESTATE_INPUTTHEORY 2
#define QESTATE_NOASSUMEVARS 3
#define QESTATE_ASSUMEMODE 4
#define QESTATE_ANSWERMODE 5
#define QESTATE_BLOCKS 6
#define QESTATE_VARIABLES 7
#define QESTATE_FORMULA 8
#define QESTATE_ANSWER 9
#define QESTATE_CURRENTNODE 15
#define QESTATE_WORKINGNODES 10
#define QESTATE_SUCCESSNODES 11
#define QESTATE_FAILURENODES 12
#define QESTATE_CURRENTTHEORY 13
#define QESTATE_PRODUCEANSWER 14
#define QESTATE_UPLIM 15

asserted procedure QeState_new(): Vector;
   begin scalar state;
      state := mkvect(QESTATE_UPLIM);
      putv(state, QESTATE_TAG, 'qestate);
      % The following fields are constant, i.e., assigned exactly once after the creation of qestate:
      putv(state, QESTATE_INPUTFORMULA, 'undefined);       % InputTheory
      putv(state, QESTATE_INPUTTHEORY, 'undefined);        % InputTheory
      putv(state, QESTATE_NOASSUMEVARS, 'undefined);       % NoAssumeVars; do not make assumptions on these variables, includes quantified variables
      putv(state, QESTATE_ASSUMEMODE, 'undefined);         % AssumeMode; 'full, 'monomial, or nil
      putv(state, QESTATE_ANSWERMODE, 'undefined);         % AnswerMode; 'raw, 'standard, or nil
      % The following fields change during execution:
      putv(state, QESTATE_BLOCKS, 'undefined);
      putv(state, QESTATE_VARIABLES, 'undefined);          % list of existentially quantified variables to be eliminated
      putv(state, QESTATE_FORMULA, 'undefined);            % matrix formula of the current block
      putv(state, QESTATE_ANSWER, 'undefined);
      putv(state, QESTATE_CURRENTNODE, 'undefined);        % WorkingNodes; container
      putv(state, QESTATE_WORKINGNODES, 'undefined);       % WorkingNodes; container
      putv(state, QESTATE_SUCCESSNODES, 'undefined);       % SuccessNodes; list
      putv(state, QESTATE_FAILURENODES, 'undefined);       % FailureNodes; list
      putv(state, QESTATE_CURRENTTHEORY, 'undefined);      % CurrentTheory
      putv(state, QESTATE_PRODUCEANSWER, 'undefined);      % ProduceAnswer: Boolean
      return state
   end;

asserted procedure QeState_print(state: Vector): Vector;
   begin scalar !*nat;
      ioto_tprin2t {"{"};
      ioto_tprin2t {"    TypeTag:               ", getv(state, QESTATE_TAG)};
      ioto_tprin2t {"    InputFormula:          ", getv(state, QESTATE_INPUTFORMULA)};
      ioto_tprin2t {"    InputTheory:           ", getv(state, QESTATE_INPUTTHEORY)};
      ioto_tprin2t {"    NoAssumeVars:          ", getv(state, QESTATE_NOASSUMEVARS)};
      ioto_tprin2t {"    AssumeMode:            ", getv(state, QESTATE_ASSUMEMODE)};
      ioto_tprin2t {"    AnswerMode:            ", getv(state, QESTATE_ANSWERMODE)};
      ioto_tprin2t {"    Blocks:                ", getv(state, QESTATE_BLOCKS)};
      ioto_tprin2t {"    Vars:                  ", getv(state, QESTATE_VARIABLES)};
      ioto_tprin2t {"    Formula:               ", ioto_smaprin rl_prepfof getv(state, QESTATE_FORMULA)};
      ioto_tprin2t {"    Answer:                ", getv(state, QESTATE_ANSWER)};
      ioto_tprin2t {"    CurrentNode:           ", getv(state, QESTATE_CURRENTNODE)};
      ioto_tprin2t {"    WorkingNodes:          ", getv(state, QESTATE_WORKINGNODES)};
      ioto_tprin2t {"    SuccessNodes:          ", getv(state, QESTATE_SUCCESSNODES)};
      ioto_tprin2t {"    FailureNodes:          ", getv(state, QESTATE_FAILURENODES)};
      ioto_tprin2t {"    CurentTheory:          ", getv(state, QESTATE_CURRENTTHEORY)};
      ioto_tprin2t {"    ProduceAnswer:         ", getv(state, QESTATE_PRODUCEANSWER)};
      ioto_tprin2t {"}"};
      return state
   end;

asserted procedure QeState_verbosePrint(state: Vector): Vector;
   begin scalar !*nat;
      ioto_tprin2t {"{"};
      ioto_tprin2t {"    TypeTag:                ", getv(state, QESTATE_TAG)};
      ioto_tprin2t {"    #InputFormula:          ", rl_atnum getv(state, QESTATE_INPUTFORMULA)};
      ioto_tprin2t {"    #InputTheory:           ", length getv(state, QESTATE_INPUTTHEORY)};
      ioto_tprin2t {"    NoAssumeVars:           ", getv(state, QESTATE_NOASSUMEVARS)};
      ioto_tprin2t {"    AssumeMode:             ", getv(state, QESTATE_ASSUMEMODE)};
      ioto_tprin2t {"    AnswerMode:             ", getv(state, QESTATE_ANSWERMODE)};
      ioto_tprin2t {"    Blocks:                 ", getv(state, QESTATE_BLOCKS)};
      ioto_tprin2t {"    Vars:                   ", getv(state, QESTATE_VARIABLES)};
      ioto_tprin2t {"    #Formula:               ", rl_atnum getv(state, QESTATE_FORMULA)};
      ioto_tprin2t {"    Answer:                 ", getv(state, QESTATE_ANSWER)};
      ioto_tprin2t {"    CurrentNode:            ", getv(state, QESTATE_CURRENTNODE)};
      if getv(state, QESTATE_WORKINGNODES) eq 'undefined then
         ioto_tprin2t {"    WorkingNodes:           ", 'undefined}
      else
         ioto_tprin2t {"    #WorkingNodes:          ", length getv(getv(state, QESTATE_WORKINGNODES), 1)};
      ioto_tprin2t {"    #SuccessNodes:          ", length getv(state, QESTATE_SUCCESSNODES)};
      ioto_tprin2t {"    #FailureNodes:          ", length getv(state, QESTATE_FAILURENODES)};
      ioto_tprin2t {"    #CurentTheory:          ", length getv(state, QESTATE_CURRENTTHEORY)};
      ioto_tprin2t {"    ProduceAnswer:          ", getv(state, QESTATE_PRODUCEANSWER)};
      ioto_tprin2t {"}"};
      return state
   end;

asserted procedure QeState_getInputFormula(state: Vector): Formula;
   getv(state, QESTATE_INPUTFORMULA);

asserted procedure QeState_setInputFormula(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_INPUTFORMULA, theory); state >>;

asserted procedure QeState_getInputTheory(state: Vector): Theory;
   getv(state, QESTATE_INPUTTHEORY);

asserted procedure QeState_setInputTheory(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_INPUTTHEORY, theory); state >>;

asserted procedure QeState_getNoAssumeVars(state: Vector): List;
   getv(state, QESTATE_NOASSUMEVARS);

asserted procedure QeState_setNoAssumeVars(state: Vector, vars: List): Vector;
   << putv(state, QESTATE_NOASSUMEVARS, vars); state >>;

asserted procedure QeState_getAssumeMode(state: Vector): Id;
   getv(state, QESTATE_ASSUMEMODE);

asserted procedure QeState_setAssumeMode(state: Vector, mode: Id): Vector;
   << putv(state, QESTATE_ASSUMEMODE, mode); state >>;

asserted procedure QeState_getAnswerMode(state: Vector): Id;
   getv(state, QESTATE_ANSWERMODE);

asserted procedure QeState_setAnswerMode(state: Vector, mode: Id): Vector;
   << putv(state, QESTATE_ANSWERMODE, mode); state >>;

asserted procedure QeState_getBlocks(state: Vector): List;
   getv(state, QESTATE_BLOCKS);

asserted procedure QeState_setBlocks(state: Vector, blocks: List): Vector;
   << putv(state, QESTATE_BLOCKS, blocks); state >>;

asserted procedure QeState_getVariables(state: Vector): List;
   getv(state, QESTATE_VARIABLES);

asserted procedure QeState_setVariables(state: Vector, vars: List): Vector;
   << putv(state, QESTATE_VARIABLES, vars); state >>;

asserted procedure QeState_getFormula(state: Vector): Formula;
   getv(state, QESTATE_FORMULA);

asserted procedure QeState_setFormula(state: Vector, f: Formula): Vector;
   << putv(state, QESTATE_FORMULA, f); state >>;

asserted procedure QeState_getAnswer(state: Vector): List;
   getv(state, QESTATE_ANSWER);

asserted procedure QeState_setAnswer(state: Vector, answer: List): Vector;
   << putv(state, QESTATE_ANSWER, answer); state >>;

asserted procedure QeState_getCurrentNode(state: Vector): List;
   getv(state, QESTATE_CURRENTNODE);

asserted procedure QeState_setCurrentNode(state: Vector, node: List): Vector;
   << putv(state, QESTATE_CURRENTNODE, node); state >>;

asserted procedure QeState_getSuccessNodes(state: Vector): List;
   getv(state, QESTATE_SUCCESSNODES);

asserted procedure QeState_setSuccessNodes(state: Vector, nodes: List): Vector;
   << putv(state, QESTATE_SUCCESSNODES, nodes); state >>;

asserted procedure QeState_getFailureNodes(state: Vector): List;
   getv(state, QESTATE_FAILURENODES);

asserted procedure QeState_setFailureNodes(state: Vector, nodes: List): Vector;
   << putv(state, QESTATE_FAILURENODES, nodes); state >>;

asserted procedure QeState_getCurrentTheory(state: Vector): Theory;
   getv(state, QESTATE_CURRENTTHEORY);

asserted procedure QeState_setCurrentTheory(state: Vector, theory: Theory): Vector;
   << putv(state, QESTATE_CURRENTTHEORY, theory); state >>;

asserted procedure QeState_getProduceAnwer(state: Vector): Boolean;
   getv(state, QESTATE_PRODUCEANSWER);

asserted procedure QeState_setProduceAnswer(state: Vector, ans: Boolean): Vector;
   << putv(state, QESTATE_PRODUCEANSWER, ans); state >>;

asserted procedure QeState_initializeWorkingNodes(state: Vector, traversalMode: Id): Vector;
   <<
      putv(state, QESTATE_WORKINGNODES, QeCont_new(traversalMode));
      state
   >>;

asserted procedure QeState_fetchWorkingNode(state: Vector): List;
   QeCont_fetch(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_firstWorkingNode(state: Vector): List;
   QeCont_firstNode(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_addWorkingNodes(state: Vector, nodes: List): Vector;
   <<
      QeCont_add(getv(state, QESTATE_WORKINGNODES), nodes);
      state
   >>;

asserted procedure QeState_isEmptyWorkingNodes(state: Vector): Boolean;
   QeCont_isEmpty(getv(state, QESTATE_WORKINGNODES));

% The following qestate methods are used for verbose output.

asserted procedure QeState_numberOfWorkingNodes(state: Vector): Integer;
   % This is used for verbose output with DFS.
   QeCont_length(getv(state, QESTATE_WORKINGNODES));

asserted procedure QeState_fetchWorkingNodeDeletions(state: Vector): DottedPair;
   begin scalar container;
         integer requested, deleted;
      container := getv(state, QESTATE_WORKINGNODES);
      requested := QeCont_getRequestedAdditions(container);
      deleted := requested - QeCont_getEffectiveAdditions(container);
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

endmodule;

end;
