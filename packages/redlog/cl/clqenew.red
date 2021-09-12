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

#define QEDB_TAG 0
#define QEDB_INPUTFORMULA 1
#define QEDB_INPUTTHEORY 2
#define QEDB_NOASSUMEVARS 3
#define QEDB_ASSUMEMODE 4
#define QEDB_ANSWERMODE 5
#define QEDB_BLOCKS 6
#define QEDB_LASTBLOCKINPUTFORMULA 8
#define QEDB_VARIABLES 9
#define QEDB_FORMULA 10
#define QEDB_ANSWER 11
#define QEDB_SUCCESSNODES 12
#define QEDB_FAILURENODES 13
#define QEDB_CURRENTTHEORY 14
#define QEDB_PRODUCEANSWER 15
#define QEDB_LAST 15

asserted procedure qedb_new(): Vector;
   % QE data for a block, construct new instance.
   begin scalar db;
      db := mkvect(QEDB_LAST);
      putv(db, QEDB_TAG, 'qedb);
      % The following fields are constant, i.e., assigned exactly once after the creation of qedb:
      putv(db, QEDB_INPUTFORMULA, 'undefined);       % InputTheory
      putv(db, QEDB_INPUTTHEORY, 'undefined);        % InputTheory
      putv(db, QEDB_NOASSUMEVARS, 'undefined);       % NoAssumeVars; do not make assumptions on these variables, includes quantified variables
      putv(db, QEDB_ASSUMEMODE, 'undefined);         % AssumeMode; 'full, 'monomial, or nil
      putv(db, QEDB_ANSWERMODE, 'undefined);         % AnswerMode; 'raw, 'standard, or nil
      % The following fields change during execution:
      putv(db, QEDB_BLOCKS, 'undefined);
      putv(db, QEDB_LASTBLOCKINPUTFORMULA, 'undefined);
      putv(db, QEDB_VARIABLES, 'undefined);          % list of existentially quantified variables to be eliminated
      putv(db, QEDB_FORMULA, 'undefined);            % matrix formula of the current block
      putv(db, QEDB_ANSWER, 'undefined);
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
      ioto_tprin2t {"    LastBlockInputFormula: ", getv(db, QEDB_LASTBLOCKINPUTFORMULA)};
      ioto_tprin2t {"    Vars:                  ", getv(db, QEDB_VARIABLES)};
      ioto_tprin2t {"    Formula:               ", ioto_smaprin rl_prepfof getv(db, QEDB_FORMULA)};
      ioto_tprin2t {"    Answer:                ", getv(db, QEDB_ANSWER)};
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
      ioto_tprin2t {"    #LastBlockInputFormula: ", rl_atnum getv(db, QEDB_LASTBLOCKINPUTFORMULA)};
      ioto_tprin2t {"    Vars:                   ", getv(db, QEDB_VARIABLES)};
      ioto_tprin2t {"    #Formula:               ", rl_atnum getv(db, QEDB_FORMULA)};
      ioto_tprin2t {"    Answer:                 ", getv(db, QEDB_ANSWER)};
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

asserted procedure qedb_getLastBlockInputFormula(db: Vector): Formula;
   getv(db, QEDB_LASTBLOCKINPUTFORMULA);

asserted procedure qedb_setLastBlockInputFormula(db: Vector, f: Formula): Vector;
   << putv(db, QEDB_LASTBLOCKINPUTFORMULA, f); db >>;

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

asserted procedure qeco_new(traversalMode: Id): Vector;
   % QE data for a block new.
   begin scalar db;
      db := mkvect(4);
      putv(db, 0, 'qeco);
      putv(db, 1, nil);                                             % Nodes: list (stack or queue) of QE tree working nodes
      putv(db, 2, if traversalMode eq 'bfs then nil else 'unused);  % LastNode: the last node in Nodes
      putv(db, 3, traversalMode);                                   % 'bfs (breadth-first search) or 'dfs (depth-first search)
      if traversalMode eq 'dfs then
      putv(db, 4, nil)
      else <<
         ASSERT( traversalMode eq 'bfs );
      putv(db, 4, 'unused)        % hashed dynamic programming data
      >>;
      return db
   end;

asserted procedure qeco_add(co: Container, new: NodeL): Container;
   begin scalar nodes, lastNode;
      if null new then
         return co;
      nodes := getv(co, 1);
      if getv(co, 3) eq 'bfs then <<
         lastNode := getv(co, 2);
         if null lastNode then
            lastNode := nodes := {pop new};
         for each node in new do
            if not member(node, nodes) then <<
               cdr lastNode := node . nil;
               lastNode := cdr lastNode
            >>;
         putv(co, 1, nodes);
         putv(co, 2, lastNode)
      >> else <<
         ASSERT( getv(co, 3) eq 'dfs );
         for each node in new do
            if not lto_hmember(node, getv(co, 4), 'co_hfn) then <<
               lto_hinsert(node, getv(co, 4), 'co_hfn);
               nodes := node . nodes
            >>;
         putv(co, 1, nodes)
      >>;
      return co
   end;

asserted procedure qeco_fetch(co: Container): Node;
   begin scalar nodes, node;
      nodes := getv(co, 1);
      ASSERT( not null nodes );
      node := pop nodes;
      if null nodes and getv(co, 3) eq 'bfs then
         putv(co, 2, nil);
      putv(co, 1, nodes);
      return node
   end;

asserted procedure qeco_isEmpty(co: Container): Boolean;
   null getv(co, 1);

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
      % I have a memory that AD suggested to simplify only the matrix.
      f := rl_simpl(rl_pnf f, theo, -1);
      if rl_excp(f) then
         return f;
      {blocks, f, allQuantifiedVariables} := cl_split_new f;
      % Remove from the theory atomic formulas containing quantified variables:
      qedb_setCurrentTheory(db, for each atf in theo join if null intersection(rl_varlat atf, allQuantifiedVariables) then {atf});
      % Prohibit assumptions on quantified variables:
      qedb_setNoAssumeVars(db, union(allQuantifiedVariables, qedb_getNoAssumeVars(db)));
      qedb_setBlocks(db, blocks);
      qedb_setFormula(db, f);
      if null blocks then <<
         % TS has moved this down a bit. There are no quantifiers left after
         % initial simplification. Note the remark before that
         % simplification! We are here at a point where the formula and the
         % theory have been set properly in the db. However, the answer is
         % still undefined. Recall that the semantics of the answer depends
         % on the quantifier type of the outmost block, which does not exist
         % here. The definition of the answer as {f . nil} chosen here
         % corresponds to the old code and is semantically correct. Still, TS
         % does not like the entire situation.
         if not null qedb_getAnswerMode(db) then
            qedb_setAnswer(db, {f . nil});
         return db
      >>;
      cl_qe1!-iterate_new(db);
      blocks := qedb_getBlocks(db);
      theo := qedb_getCurrentTheory(db);
      f := cl_simpl(cl_unsplit_new(blocks, qedb_getFormula(db)), theo, -1);
      if not null qedb_getAnswerMode(db) then <<
         % At present, we always requantify; no fallback QE with answers.
         if null blocks or null cdr blocks then <<
            % We have finished or at least reached the outmost block.
            answer := for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect <<
               point := rl_qemkans(ce_ans(node), qedb_getLastBlockInputFormula(db))
                        where !*rlqestdans = (qedb_getAnswerMode(db) eq 'standard);
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
   begin scalar blocks, f, produceAnswer, theo, db, svrlidentify, svrlqeprecise, svrlqeaprecise, q, varl,rvl, w;
      svrlidentify := !*rlidentify;
      blocks := qedb_getBlocks(db);
      f := qedb_getFormula(db);
      theo := qedb_getInputTheory(db);
      ASSERT( not null blocks );
      while null rvl and blocks do <<
         q . varl := pop blocks;
         qedb_setVariables(db, varl);
         produceAnswer := not null qedb_getAnswerMode(db) and null blocks;
         qedb_setProduceAnswer(db, produceAnswer);
         if produceAnswer then  % TODO: rubbish!
            qedb_setLastBlockInputFormula(db, f);
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
            w := qedb_getSuccessNodes(db);
            w := for each x in w collect
               ce_mk(ce_vl x, rl_nnfnot ce_f x, nil, nil, ce_ans x);
            qedb_setSuccessNodes(db, w);
            w := qedb_getFailureNodes(db);
            w := for each x in w collect
               ce_mk(ce_vl x, rl_nnfnot ce_f x, nil, nil, ce_ans x);
            qedb_setFailureNodes(db, w)
         >>;
         f := rl_smkn(if q eq 'all then 'and else 'or,
                      for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect ce_f node);
         if not null qedb_getFailureNodes(db) then
            for each node in qedb_getFailureNodes(db) do
               rvl := union(rvl, ce_vl node);
         theo := qedb_getCurrentTheory(db);
         if blocks then <<
            onoff('rlqeprecise, svrlqeprecise);
            onoff('rlqeaprecise, svrlqeaprecise)
         >>
      >>;
      onoff('rlidentify, svrlidentify);
      if not null rvl then
         push(q . rvl, blocks);
      qedb_setFormula(db, f);
      qedb_setBlocks(db, blocks);
      return db
   end;

asserted procedure cl_qeblock4_new(db: Vector): Vector;
   begin scalar f, varl, theo, w, co, cvl, coe, successNodes, failureNodes;
      theo := qedb_getCurrentTheory(db);
      varl := qedb_getVariables(db);
      f := qedb_getFormula(db);
      if !*rlqegsd then
         f := rl_gsn(f, theo, 'dnf);
      co := qeco_new(if !*rlqedfs then 'dfs else 'bfs);
      if rl_op f eq 'or then
         for each x in rl_argn f do
            qeco_add(co, {ce_mk(varl, x, nil, nil, nil)})
      else
         qeco_add(co, {ce_mk(varl, f, nil, nil, nil)});
      successNodes := nil;
      failureNodes := nil;
      while not qeco_isEmpty(co) do <<
         if !*rlqeidentify then on1 'rlidentify;
         coe := qeco_fetch(co);
         cvl := ce_vl coe;
         w . theo := cl_qevar(ce_f coe, ce_vl coe, ce_ans coe, theo, qedb_getProduceAnwer(db), qedb_getNoAssumeVars(db));
         if car w then <<  % We have found a suitable variable.
            w := cdr w;
            if w then % w is a junct = list(ce)
               if ce_vl car w eq 'break then <<  % we have found true
                  successNodes := {ce_mk(nil, 'true, nil, nil, ce_ans car w)};
                  failureNodes := nil;
                  goto brk
               >> else if cdr cvl then <<  % there are variables left
                  co := qeco_add(co, w);
               >> else  % there is no variable left
                  for each x in w do
                     successNodes := lto_insert(x, successNodes);
         >> else <<
            % There is no eliminable variable. Invalidate this entry, and save
            % its variables for later requantification.
            failureNodes := lto_insert(coe, failureNodes)
         >>
      >>;
   brk:
      qedb_setSuccessNodes(db, successNodes);
      qedb_setFailureNodes(db, failureNodes);
      qedb_setCurrentTheory(db, theo);
      return db
   end;

endmodule;

end;
