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
#define QEDB_ANSWERMODE 4
#define QEDB_ASSUMEMODE 5
#define QEDB_BLOCKSYMBOLS 6
#define QEDB_BLOCKVARLISTS 7
#define QEDB_LASTBLOCKINPUTFORMULA 8
#define QEDB_VARS 9
#define QEDB_FORMULA 10
#define QEDB_ANSWER 11
#define QEDB_SUCCESSNODES 12
#define QEDB_FAILURENODES 13
#define QEDB_CURRENTTHEORY 14
#define QEDB_PRODUCEANSWER 15
#define QEDB_LAST 15

asserted procedure qedb_new(): Vector;
   % QE data for a block new.
   begin scalar db;
      db := mkvect(QEDB_LAST);
      putv(db, QEDB_TAG, 'qedb);

      % The following fields are constant, i.e., assigned exactly once after the creation of qedb:
      putv(db, QEDB_INPUTFORMULA, 'undefined);       % InputTheory
      putv(db, QEDB_INPUTTHEORY, 'undefined);        % InputTheory
      putv(db, QEDB_NOASSUMEVARS, 'undefined);       % NoAssumeVars; do not make assumptions on these variables, includes quantified variables
      putv(db, QEDB_ANSWERMODE, 'undefined);         % AnswerMode; 'raw, 'standard, or nil
      putv(db, QEDB_ASSUMEMODE, 'undefined);         % AssumeMode; 'full, 'monomial, or nil

      % The following fields change during execution:
      putv(db, QEDB_BLOCKSYMBOLS, 'undefined);
      putv(db, QEDB_BLOCKVARLISTS, 'undefined);
      putv(db, QEDB_LASTBLOCKINPUTFORMULA, 'undefined);

      putv(db, QEDB_VARS, 'undefined);               % Vars; list of existentially quantified variables to be eliminated
      putv(db, QEDB_FORMULA, 'undefined);            % F; matrix formula of the current block
      putv(db, QEDB_ANSWER, 'undefined);
      putv(db, QEDB_SUCCESSNODES, 'undefined);       % SuccessNodes; list
      putv(db, QEDB_FAILURENODES, 'undefined);       % FailureNodes; list
      putv(db, QEDB_CURRENTTHEORY, 'undefined);      % CurrentTheory
      putv(db, QEDB_PRODUCEANSWER, 'undefined);      % ProduceAnswer: Boolean
      return db
   end;

procedure qedb_print(db: Vector): Vector;
   begin scalar !*nat;
      ioto_tprin2t {"{"};
      ioto_tprin2t {"    TypeTag:               ", getv(db, QEDB_TAG)};
      ioto_tprin2t {"    InputFormula:          ", getv(db, QEDB_INPUTFORMULA)};
      ioto_tprin2t {"    InputTheory:           ", getv(db, QEDB_INPUTTHEORY)};
      ioto_tprin2t {"    NoAssumeVars:          ", getv(db, QEDB_NOASSUMEVARS)};
      ioto_tprin2t {"    AnswerMode:            ", getv(db, QEDB_ANSWERMODE)};
      ioto_tprin2t {"    AssumeMode:            ", getv(db, QEDB_ASSUMEMODE)};
      ioto_tprin2t {"    BlockSymbols:          ", getv(db, QEDB_BLOCKSYMBOLS)};
      ioto_tprin2t {"    BlockVarLists:         ", getv(db, QEDB_BLOCKVARLISTS)};
      ioto_tprin2t {"    LastBlockInputFormula: ", getv(db, QEDB_LASTBLOCKINPUTFORMULA)};
      ioto_tprin2t {"    Vars:                  ", getv(db, QEDB_VARS)};
      ioto_tprin2t {"    Formula:               ", ioto_smaprin rl_prepfof getv(db, QEDB_FORMULA)};
      ioto_tprin2t {"    Answer:                ", getv(db, QEDB_ANSWER)};
      ioto_tprin2t {"    SuccessNodes:          ", getv(db, QEDB_SUCCESSNODES)};
      ioto_tprin2t {"    FailureNodes:          ", getv(db, QEDB_FAILURENODES)};
      ioto_tprin2t {"    CurentTheory:          ", getv(db, QEDB_CURRENTTHEORY)};
      ioto_tprin2t {"    ProduceAnswer:         ", getv(db, QEDB_PRODUCEANSWER)};
      ioto_tprin2t {"}"};
      return db
   end;

procedure qedb_getInputFormula(db);              getv(db, QEDB_INPUTFORMULA);
procedure qedb_getInputTheory(db);               getv(db, QEDB_INPUTTHEORY);
procedure qedb_getNoAssumeVars(db);              getv(db, QEDB_NOASSUMEVARS);
procedure qedb_getAnswerMode(db);                getv(db, QEDB_ANSWERMODE);
procedure qedb_getAssumeMode(db);                getv(db, QEDB_ASSUMEMODE);

procedure qedb_getBlockSymbols(db);              getv(db, QEDB_BLOCKSYMBOLS);
procedure qedb_getBlockVarLists(db);             getv(db, QEDB_BLOCKVARLISTS);
procedure qedb_getLastBlockInputFormula(db);     getv(db, QEDB_LASTBLOCKINPUTFORMULA);

procedure qedb_getVars(db);                      getv(db, QEDB_VARS);
procedure qedb_getF(db);                         getv(db, QEDB_FORMULA);
procedure qedb_getAnswer(db);                    getv(db, QEDB_ANSWER);
procedure qedb_getSuccessNodes(db);              getv(db, QEDB_SUCCESSNODES);
procedure qedb_getFailureNodes(db);              getv(db, QEDB_FAILURENODES);
procedure qedb_getCurrentTheory(db);             getv(db, QEDB_CURRENTTHEORY);
procedure qedb_getProduceAnwer(db);              getv(db, QEDB_PRODUCEANSWER);

procedure qedb_setInputFormula(db, theory);      putv(db, QEDB_INPUTFORMULA, theory);
procedure qedb_setInputTheory(db, theory);       putv(db, QEDB_INPUTTHEORY, theory);
procedure qedb_setNoAssumeVars(db, navs);        putv(db, QEDB_NOASSUMEVARS, navs);
procedure qedb_setAnswerMode(db, mode);          putv(db, QEDB_ANSWERMODE, mode);
procedure qedb_setAssumeMode(db, mode);          putv(db, QEDB_ASSUMEMODE, mode);

procedure qedb_setBlockSymbols(db, ql);          putv(db, QEDB_BLOCKSYMBOLS, ql);
procedure qedb_setBlockVarLists(db, vll);        putv(db, QEDB_BLOCKVARLISTS, vll);
procedure qedb_setLastBlockInputFormula(db, f);  putv(db, QEDB_LASTBLOCKINPUTFORMULA, f);

procedure qedb_setVars(db, vars);                putv(db, QEDB_VARS, vars);
procedure qedb_setF(db, f);                      putv(db, QEDB_FORMULA, f);
procedure qedb_setAnswer(db, answer);            putv(db, QEDB_ANSWER, answer);
procedure qedb_setSuccessNodes(db, nodes);       putv(db, QEDB_SUCCESSNODES, nodes);
procedure qedb_setFailureNodes(db, nodes);       putv(db, QEDB_FAILURENODES, nodes);
procedure qedb_setCurrentTheory(db, theory);     putv(db, QEDB_CURRENTTHEORY, theory);
procedure qedb_setProduceAnswer(db, ans);        putv(db, QEDB_PRODUCEANSWER, ans);

asserted procedure cl_qe_new(f: Formula, theo: Theory): Formula;
   % Quantifier elimination. Eliminate as many quantifiers as possible from f,
   % yielding a formula g such that theo |= f <=> g.
   begin scalar db, !*rlsipw, !*rlsipo;
      !*rlsipw := !*rlsipo := t;
      db := qedb_new();
      qedb_setInputFormula(db, f);
      qedb_setInputTheory(db, theo);
      qedb_setNoAssumeVars(db, nil);
      qedb_setAnswerMode(db, nil);
      qedb_setAssumeMode(db, nil);
      cl_qe1_new(db);
      return qedb_getF(db)
   end;

asserted procedure cl_qe1_new(db: Vector): Vector;
   begin scalar f, theo, answer, ql, varll, bvl;
      f := qedb_getInputFormula(db);
      theo := qedb_getInputTheory(db);
      f := rl_simpl(rl_pnf f, theo, -1);
      if f eq 'inctheo then
         return rl_exception 'inctheo;
      if not rl_quap rl_op f then
         return qedb_setF(db, f);
      {ql, varll, f, bvl} := cl_split f;
      % Remove from the theory atomic formulas containing quantified variables:
      qedb_setCurrentTheory(db, for each atf in theo join if null intersection(rl_varlat atf, bvl) then {atf});
      % Prohibit assumptions on quantified variables:
      qedb_setNoAssumeVars(db, union(bvl, qedb_getNoAssumeVars(db)));
      qedb_setBlockSymbols(db, ql);
      qedb_setBlockVarlists(db, varll);
      qedb_setF(db, f);
      cl_qe1!-iterate_new(db);
      ql := qedb_getBlockSymbols(db);
      varll := qedb_getBlockVarLists(db);
      theo := qedb_getCurrentTheory(db);
      f := cl_simpl(cl_unsplit(ql, varll, qedb_getF(db)), theo, -1);
      if not null qedb_getAnswerMode(db) then <<
         % At present, we always requantify; no fallback QE with answers.
         if null ql or null cdr ql then <<
            % We have finished or at least reached the outmost block.
            answer := for each node in append(qedb_getSuccessNodes(db), qedb_getFailureNodes(db)) collect
               cl_unsplit(ql, varll, ce_f(node) . rl_qemkans(ce_ans(node), qedb_getLastBlockInputFormula(db)))
         >> else
            answer := {f . nil};
         qedb_setF(db, f);
         qedb_setAnswer(db, answer);
         return db
      >>;
      if !*rlqefb and rl_quap rl_op f then
         theo . f := rl_fbqe(f, theo);
      qedb_setCurrentTheory(db, theo);
      qedb_setF(db, f);
      return db
   end;

asserted procedure cl_qe1!-iterate_new(db: Vector): Vector;
   % Iteratively apply cl_qeblock to quantifier blocks.
   begin scalar ql, varll, f, produceAnswer, theo, db, svrlidentify,
                svrlqeprecise, svrlqeaprecise, q, varl,rvl, w;
      svrlidentify := !*rlidentify;
      ql := qedb_getBlockSymbols(db);
      varll := qedb_getBlockVarLists(db);
      f := qedb_getF(db);
      theo := qedb_getInputTheory(db);
      ASSERT( not null ql );
      while null rvl and ql do <<
         q := pop ql;
         varl := pop varll;
         qedb_setVars(db, varl);
         produceAnswer := not null qedb_getAnswerMode(db) and null ql;
         qedb_setProduceAnswer(db, produceAnswer);
         if produceAnswer then
            qedb_setLastBlockInputFormula(db, f);
         svrlqeprecise := !*rlqeprecise;
         svrlqeaprecise := !*rlqeaprecise;
         if ql then <<  % Should better be an argument of qeblock ...
            off1 'rlqeprecise;
            off1 'rlqeaprecise
         >>;
         if q eq 'all then
            f := rl_simpl(rl_nnfnot f, theo, -1);
         qedb_setF(db, f);
         qedb_setSuccessNodes(db, nil);
         qedb_setFailureNodes(db, nil);
         qedb_setCurrentTheory(db, theo);
         cl_qeblock4_new(db);
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
         if ql then <<
            onoff('rlqeprecise, svrlqeprecise);
            onoff('rlqeaprecise, svrlqeaprecise)
         >>
      >>;
      onoff('rlidentify, svrlidentify);
      if not null rvl then <<
         ql := q . ql;
         varll := rvl . varll
      >>;
      qedb_setF(db, f);
      qedb_setBlockSymbols(db, ql);
      qedb_setBlockVarlists(db, varll);
      return db
   end;

asserted procedure cl_qeblock4_new(db: Vector): Vector;
   begin scalar f, varl, theo, w, co, cvl, coe, successNodes, failureNodes;
      theo := qedb_getCurrentTheory(db);
      varl := qedb_getVars(db);
      f := qedb_getF(db);
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

asserted procedure qeco_new(traversalMode: Id): Vector;
   % QE data for a block new.
   begin scalar db;
      db := mkvect(4);
      putv(db, 0, 'qeco);
      putv(db, 1, nil);                                             % Nodes: list (stack or queue) of QE tree working nodes
      putv(db, 2, if traversalMode eq 'bfs then nil else 'unused);  % LastNode
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
         lastNode := getv(co ,2);
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
         putv(co, 1, nodes);
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

endmodule;

end;
