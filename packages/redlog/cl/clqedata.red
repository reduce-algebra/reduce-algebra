module clqedata;

revision('clqedata, "$Id$");

copyright('clqedata, "(c) 2021 A. Dolzmann, T. Sturm");

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

#define QEDB_TAG 0
#define QEDB_INPUTFORMULA 1
#define QEDB_INPUTTHEORY 2
#define QEDB_NOASSUMEVARS 3
#define QEDB_ASSUMEMODE 4
#define QEDB_ANSWERMODE 5
#define QEDB_BLOCKS 6
#define QEDB_VARIABLES 7
#define QEDB_FORMULA 8
#define QEDB_ANSWER 9
#define QEDB_CURRENTNODE 15
#define QEDB_WORKINGNODES 10
#define QEDB_SUCCESSNODES 11
#define QEDB_FAILURENODES 12
#define QEDB_CURRENTTHEORY 13
#define QEDB_PRODUCEANSWER 14
#define QEDB_UPLIM 15

asserted procedure qedb_new(): Vector;
   % QE data for a block, construct new instance.
   begin scalar db;
      db := mkvect(QEDB_UPLIM);
      putv(db, QEDB_TAG, 'qedb);
      % The following fields are constant, i.e., assigned exactly once after the creation of qedb:
      putv(db, QEDB_INPUTFORMULA, 'undefined);       % InputTheory
      putv(db, QEDB_INPUTTHEORY, 'undefined);        % InputTheory
      putv(db, QEDB_NOASSUMEVARS, 'undefined);       % NoAssumeVars; do not make assumptions on these variables, includes quantified variables
      putv(db, QEDB_ASSUMEMODE, 'undefined);         % AssumeMode; 'full, 'monomial, or nil
      putv(db, QEDB_ANSWERMODE, 'undefined);         % AnswerMode; 'raw, 'standard, or nil
      % The following fields change during execution:
      putv(db, QEDB_BLOCKS, 'undefined);
      putv(db, QEDB_VARIABLES, 'undefined);          % list of existentially quantified variables to be eliminated
      putv(db, QEDB_FORMULA, 'undefined);            % matrix formula of the current block
      putv(db, QEDB_ANSWER, 'undefined);
      putv(db, QEDB_CURRENTNODE, 'undefined);        % WorkingNodes; container
      putv(db, QEDB_WORKINGNODES, 'undefined);       % WorkingNodes; container
      putv(db, QEDB_SUCCESSNODES, 'undefined);       % SuccessNodes; list
      putv(db, QEDB_FAILURENODES, 'undefined);       % FailureNodes; list
      putv(db, QEDB_CURRENTTHEORY, 'undefined);      % CurrentTheory
      putv(db, QEDB_PRODUCEANSWER, 'undefined);      % ProduceAnswer: Boolean
      return db
   end;

asserted procedure qedb_print(db: Vector): Vector;
   begin scalar !*nat;
      ioto_tprin2t {"{"};
      ioto_tprin2t {"    TypeTag:               ", getv(db, QEDB_TAG)};
      ioto_tprin2t {"    InputFormula:          ", getv(db, QEDB_INPUTFORMULA)};
      ioto_tprin2t {"    InputTheory:           ", getv(db, QEDB_INPUTTHEORY)};
      ioto_tprin2t {"    NoAssumeVars:          ", getv(db, QEDB_NOASSUMEVARS)};
      ioto_tprin2t {"    AssumeMode:            ", getv(db, QEDB_ASSUMEMODE)};
      ioto_tprin2t {"    AnswerMode:            ", getv(db, QEDB_ANSWERMODE)};
      ioto_tprin2t {"    Blocks:                ", getv(db, QEDB_BLOCKS)};
      ioto_tprin2t {"    Vars:                  ", getv(db, QEDB_VARIABLES)};
      ioto_tprin2t {"    Formula:               ", ioto_smaprin rl_prepfof getv(db, QEDB_FORMULA)};
      ioto_tprin2t {"    Answer:                ", getv(db, QEDB_ANSWER)};
      ioto_tprin2t {"    CurrentNode:           ", getv(db, QEDB_CURRENTNODE)};
      ioto_tprin2t {"    WorkingNodes:          ", getv(db, QEDB_WORKINGNODES)};
      ioto_tprin2t {"    SuccessNodes:          ", getv(db, QEDB_SUCCESSNODES)};
      ioto_tprin2t {"    FailureNodes:          ", getv(db, QEDB_FAILURENODES)};
      ioto_tprin2t {"    CurentTheory:          ", getv(db, QEDB_CURRENTTHEORY)};
      ioto_tprin2t {"    ProduceAnswer:         ", getv(db, QEDB_PRODUCEANSWER)};
      ioto_tprin2t {"}"};
      return db
   end;

asserted procedure qedb_verbosePrint(db: Vector): Vector;
   begin scalar !*nat;
      ioto_tprin2t {"{"};
      ioto_tprin2t {"    TypeTag:                ", getv(db, QEDB_TAG)};
      ioto_tprin2t {"    #InputFormula:          ", rl_atnum getv(db, QEDB_INPUTFORMULA)};
      ioto_tprin2t {"    #InputTheory:           ", length getv(db, QEDB_INPUTTHEORY)};
      ioto_tprin2t {"    NoAssumeVars:           ", getv(db, QEDB_NOASSUMEVARS)};
      ioto_tprin2t {"    AssumeMode:             ", getv(db, QEDB_ASSUMEMODE)};
      ioto_tprin2t {"    AnswerMode:             ", getv(db, QEDB_ANSWERMODE)};
      ioto_tprin2t {"    Blocks:                 ", getv(db, QEDB_BLOCKS)};
      ioto_tprin2t {"    Vars:                   ", getv(db, QEDB_VARIABLES)};
      ioto_tprin2t {"    #Formula:               ", rl_atnum getv(db, QEDB_FORMULA)};
      ioto_tprin2t {"    Answer:                 ", getv(db, QEDB_ANSWER)};
      ioto_tprin2t {"    CurrentNode:            ", getv(db, QEDB_CURRENTNODE)};
      if getv(db, QEDB_WORKINGNODES) eq 'undefined then
         ioto_tprin2t {"    WorkingNodes:           ", 'undefined}
      else
         ioto_tprin2t {"    #WorkingNodes:          ", length getv(getv(db, QEDB_WORKINGNODES), 1)};
      ioto_tprin2t {"    #SuccessNodes:          ", length getv(db, QEDB_SUCCESSNODES)};
      ioto_tprin2t {"    #FailureNodes:          ", length getv(db, QEDB_FAILURENODES)};
      ioto_tprin2t {"    #CurentTheory:          ", length getv(db, QEDB_CURRENTTHEORY)};
      ioto_tprin2t {"    ProduceAnswer:          ", getv(db, QEDB_PRODUCEANSWER)};
      ioto_tprin2t {"}"};
      return db
   end;

asserted procedure qedb_getInputFormula(db: Vector): Formula;
   getv(db, QEDB_INPUTFORMULA);

asserted procedure qedb_setInputFormula(db: Vector, theory: Theory): Vector;
   << putv(db, QEDB_INPUTFORMULA, theory); db >>;

asserted procedure qedb_getInputTheory(db: Vector): Theory;
   getv(db, QEDB_INPUTTHEORY);

asserted procedure qedb_setInputTheory(db: Vector, theory: Theory): Vector;
   << putv(db, QEDB_INPUTTHEORY, theory); db >>;

asserted procedure qedb_getNoAssumeVars(db: Vector): List;
   getv(db, QEDB_NOASSUMEVARS);

asserted procedure qedb_setNoAssumeVars(db: Vector, vars: List): Vector;
   << putv(db, QEDB_NOASSUMEVARS, vars); db >>;

asserted procedure qedb_getAssumeMode(db: Vector): Id;
   getv(db, QEDB_ASSUMEMODE);

asserted procedure qedb_setAssumeMode(db: Vector, mode: Id): Vector;
   << putv(db, QEDB_ASSUMEMODE, mode); db >>;

asserted procedure qedb_getAnswerMode(db: Vector): Id;
   getv(db, QEDB_ANSWERMODE);

asserted procedure qedb_setAnswerMode(db: Vector, mode: Id): Vector;
   << putv(db, QEDB_ANSWERMODE, mode); db >>;

asserted procedure qedb_getBlocks(db: Vector): List;
   getv(db, QEDB_BLOCKS);

asserted procedure qedb_setBlocks(db: Vector, blocks: List): Vector;
   << putv(db, QEDB_BLOCKS, blocks); db >>;

asserted procedure qedb_getVariables(db: Vector): List;
   getv(db, QEDB_VARIABLES);

asserted procedure qedb_setVariables(db: Vector, vars: List): Vector;
   << putv(db, QEDB_VARIABLES, vars); db >>;

asserted procedure qedb_getFormula(db: Vector): Formula;
   getv(db, QEDB_FORMULA);

asserted procedure qedb_setFormula(db: Vector, f: Formula): Vector;
   << putv(db, QEDB_FORMULA, f); db >>;

asserted procedure qedb_getAnswer(db: Vector): List;
   getv(db, QEDB_ANSWER);

asserted procedure qedb_setAnswer(db: Vector, answer: List): Vector;
   << putv(db, QEDB_ANSWER, answer); db >>;

asserted procedure qedb_getCurrentNode(db: Vector): List;
   getv(db, QEDB_CURRENTNODE);

asserted procedure qedb_setCurrentNode(db: Vector, node: List): Vector;
   << putv(db, QEDB_CURRENTNODE, node); db >>;

asserted procedure qedb_getSuccessNodes(db: Vector): List;
   getv(db, QEDB_SUCCESSNODES);

asserted procedure qedb_setSuccessNodes(db: Vector, nodes: List): Vector;
   << putv(db, QEDB_SUCCESSNODES, nodes); db >>;

asserted procedure qedb_getFailureNodes(db: Vector): List;
   getv(db, QEDB_FAILURENODES);

asserted procedure qedb_setFailureNodes(db: Vector, nodes: List): Vector;
   << putv(db, QEDB_FAILURENODES, nodes); db >>;

asserted procedure qedb_getCurrentTheory(db: Vector): Theory;
   getv(db, QEDB_CURRENTTHEORY);

asserted procedure qedb_setCurrentTheory(db: Vector, theory: Theory): Vector;
   << putv(db, QEDB_CURRENTTHEORY, theory); db >>;

asserted procedure qedb_getProduceAnwer(db: Vector): Boolean;
   getv(db, QEDB_PRODUCEANSWER);

asserted procedure qedb_setProduceAnswer(db: Vector, ans: Boolean): Vector;
   << putv(db, QEDB_PRODUCEANSWER, ans); db >>;

asserted procedure qedb_initializeWorkingNodes(db: Vector, traversalMode: Id): Vector;
   <<
      putv(db, QEDB_WORKINGNODES, qeco_new(traversalMode));
      db
   >>;

asserted procedure qedb_fetchWorkingNode(db: Vector): List;
   qeco_fetch(getv(db, QEDB_WORKINGNODES));

asserted procedure qedb_firstWorkingNode(db: Vector): List;
   qeco_firstNode(getv(db, QEDB_WORKINGNODES));

asserted procedure qedb_addWorkingNodes(db: Vector, nodes: List): Vector;
   <<
      qeco_add(getv(db, QEDB_WORKINGNODES), nodes);
      db
   >>;

asserted procedure qedb_isEmptyWorkingNodes(db: Vector): Boolean;
   qeco_isEmpty(getv(db, QEDB_WORKINGNODES));

#define QECO_TAG 0
#define QECO_NODES 1
#define QECO_LASTNODE 2
#define QECO_TRAVERSALMODE 3
#define QECO_HASHTABLE 4
#define QECO_UPLIM 4

asserted procedure qeco_new(traversalMode: Id): Vector;
   % QE data for a block new.
   begin scalar db;
      db := mkvect(QECO_UPLIM);
      putv(db, QECO_TAG, 'qeco);
      putv(db, QECO_NODES, nil);                    % list (stack or queue) of QE tree working nodes
      putv(db, QECO_TRAVERSALMODE, traversalMode);  % 'bfs (breadth-first search) or 'dfs (depth-first search)
      if traversalMode eq 'dfs then <<
         putv(db, QECO_LASTNODE, 'unused);
         putv(db, QECO_HASHTABLE, nil)              % hashed dynamic programming data
      >> else <<
         ASSERT( traversalMode eq 'bfs );
         putv(db, QECO_LASTNODE, nil);              % the last node in nodes
         putv(db, QECO_HASHTABLE, 'unused)
      >>;
      return db
   end;

asserted procedure qeco_add(co: Container, new: List): Container;
   begin scalar nodes, lastNode;
      if null new then
         return co;
      nodes := getv(co, QECO_NODES);
      if getv(co, QECO_TRAVERSALMODE) eq 'bfs then <<
         lastNode := getv(co, QECO_LASTNODE);
         if null lastNode then
            lastNode := nodes := {pop new};
         for each node in new do
            if not member(node, nodes) then <<
               cdr lastNode := node . nil;
               lastNode := cdr lastNode
            >>;
         putv(co, QECO_NODES, nodes);
         putv(co, QECO_LASTNODE, lastNode)
      >> else <<
         ASSERT( getv(co, QECO_TRAVERSALMODE) eq 'dfs );
         for each node in new do
            if not lto_hmember(node, getv(co, QECO_HASHTABLE), 'co_hfn) then <<
               putv(co, QECO_HASHTABLE, lto_hinsert(node, getv(co, QECO_HASHTABLE), 'co_hfn));
               nodes := node . nodes
            >>;
         putv(co, QECO_NODES, nodes)
      >>;
      return co
   end;

asserted procedure qeco_firstNode(co: Container): List;
   car getv(co, QECO_NODES);

asserted procedure qeco_fetch(co: Container): List;
   begin scalar nodes, node;
      nodes := getv(co, QECO_NODES);
      ASSERT( not null nodes );
      node := pop nodes;
      if null nodes and getv(co, QECO_TRAVERSALMODE) eq 'bfs then
         putv(co, QECO_LASTNODE, nil);
      putv(co, QECO_NODES, nodes);
      return node
   end;

asserted procedure qeco_isEmpty(co: Container): Boolean;
   null getv(co, QECO_NODES);

#define QENOD_TAG 1
#define QENOD_VARIABLES 2
#define QENOD_FORMULA 3
#define QENOD_ANSWER 6

asserted procedure qenod_new(variables: KernelL, f: Formula, answer: List): List4;
   {'qenod, variables, f, nil, nil, answer};

asserted procedure qenod_getVariables(node: List4): KernelL;
   nth(node, QENOD_VARIABLES);

asserted procedure qenod_getFormula(node: List4): Formula;
   nth(node, QENOD_FORMULA);

asserted procedure qenod_getAnswer(node: List4): List;
   nth(node, QENOD_ANSWER);

endmodule;

end;
