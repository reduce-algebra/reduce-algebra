% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2015 M. Kosta, T. Sturm
% ----------------------------------------------------------------------
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

lisp <<
   fluid '(ofsfvsblock_rcsid!* ofsfvsblock_copyright!*);
   ofsfvsblock_rcsid!* :=
      "$Id$";
   ofsfvsblock_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvsblock;

fluid '(rlvarsellvl!*);
rlvarsellvl!* := 3;

switch ofsfvsqetree2gml;
off1 'ofsfvsqetree2gml;

fluid '(rlqetreegmlfile!*);
rlqetreegmlfile!* := "/tmp/qe-tree.gml";

%%% QE tree node %%%
% constructors and access functions

asserted procedure vsnd_mk(flg: Boolean, vs: VSvs, vl: KernelL, f: QfFormula, p: VSnd): VSnd;
   % QE tree node make. [flg] denotes whether VS [vs] needs to be
   % applied; [vl] is a list of variables to be eliminated; [f] is a
   % quantifier-free formula; [p] is the parent QE tree node.
   {'vsnd, flg, vs, vl, f, p};

asserted procedure vsnd_flg(nd: VSnd): Boolean;
   % QE tree node flag.
   nth(nd, 2);

asserted procedure vsnd_vs(nd: VSnd): VSvs;
   % QE tree node VS.
   nth(nd, 3);

asserted procedure vsnd_vl(nd: VSnd): KernelL;
   % QE tree node variable list.
   nth(nd, 4);

asserted procedure vsnd_f(nd: VSnd): QfFormula;
   % QE tree node formula.
   nth(nd, 5);

asserted procedure vsnd_parent(nd: VSnd): VSnd;
   % QE tree node parent QE tree node.
   nth(nd, 6);

%%% container of nodes %%%
% constructors and access functions

asserted procedure vsco_mk(): VSco;
   % Container new.
   nil;

asserted procedure vsco_nonemptyp(co: VSco): ExtraBoolean;
   % Container non-empty predicate.
   co;

asserted procedure vsco_insert(co: VSco, nd: VSnd): VSco;
   % Container insert. Insert one QE tree node [nd] into container
   % [co].
   nd . co;

asserted procedure vsco_get(co: VSco): DottedPair;
   % Container get. [co] is a non-empty container. Returns [(nd . c)]
   % where [nd] is a node and [c] is the container [co] without the
   % entry [nd].
   <<
      assert(co);
      co
   >>;

%%% hash table of quantifier-free formulas %%%
% constructors and access functions

asserted procedure vsht_mk(): VSht;
   % Hash table new.
   {'vsht, nil};

asserted procedure vsht_insert(ht: VSht, f: QfFormula): VSht;
   % Hash table insert.
   {'vsht, lto_hinsert(f, nth(ht, 2), 'vsht_hfn)};

asserted procedure vsht_member(ht: VSht, f: QfFormula): ExtraBoolean;
   % Hash table member.
   lto_hmember(f, nth(ht, 2), 'vsht_hfn);

asserted procedure vsht_hfn(f: QfFormula): List;
   % Hash table hashing function.
   {f};

%%% VS data for a block %%%
% constructors and access functions

asserted procedure vsdb_new(): VSdb;
   % VS data for a block new.
   begin scalar db;
      db := mkvect(10);
      putv(db, 0, 'vsdb);
      % The following fields are constant, i.e., assigned exactly once
      % after the creation of VSdb:
      putv(db, 1, 'undefined);        % [vl]: variables to be eliminated
      putv(db, 2, 'undefined);        % [f]: matrix formula of the current block
      putv(db, 3, 'undefined);        % [theo]: global background theory
      putv(db, 4, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(db, 5, 'undefined);        % [ans]: whether we should compute answers
      % putv(db, x, 'undefined);        % QEA flag; quantifier elimination with answers
      % putv(db, x, 'undefined);        % QEASTD flag; quantifier elimination with standard answers
      % putv(db, x, 'undefined);        % QEGEN flag; generic quantifier elimination
      % putv(db, x, 'undefined);        % QELOCAL flag; local quantifier elimination
      % putv(db, x, 'undefined);        % QEDEBUG flag; debugging
      % putv(db, x, 'undefined);        % QESTAT flag; statistics
      % The following fields change during execution:
      putv(db, 6, 'undefined);        % [wc]: container of QE tree working nodes
      putv(db, 7, 'undefined);        % [sc]: container of QE tree success nodes
      putv(db, 8, 'undefined);        % [fc]: container of QE tree failure nodes
      putv(db, 9, 'undefined);        % [ht]: hash table of quantifier-free formulas
      putv(db, 10, 'undefined);       % [curtheo]: current theory
      return db
   end;

procedure vsdb_vl(db);                           getv(db, 1);
procedure vsdb_f(db);                            getv(db, 2);
procedure vsdb_theo(db);                         getv(db, 3);
procedure vsdb_bvl(db);                          getv(db, 4);
procedure vsdb_ans(db);                          getv(db, 5);
procedure vsdb_wc(db);                           getv(db, 6);
procedure vsdb_sc(db);                           getv(db, 7);
procedure vsdb_fc(db);                           getv(db, 8);
procedure vsdb_ht(db);                           getv(db, 9);
procedure vsdb_curtheo(db);                      getv(db, 10);

procedure vsdb_putvl(db, vl);                    putv(db, 1, vl);
procedure vsdb_putf(db, f);                      putv(db, 2, f);
procedure vsdb_puttheo(db, theo);                putv(db, 3, theo);
procedure vsdb_putbvl(db, bvl);                  putv(db, 4, bvl);
procedure vsdb_putans(db, ans);                  putv(db, 5, ans);
procedure vsdb_putwc(db, wc);                    putv(db, 6, wc);
procedure vsdb_putsc(db, sc);                    putv(db, 7, sc);
procedure vsdb_putfc(db, fc);                    putv(db, 8, fc);
procedure vsdb_putht(db, ht);                    putv(db, 9, ht);
procedure vsdb_putcurtheo(db, theo);             putv(db, 10, theo);

asserted procedure vsdb_mk(vl: KernelL, f: QfFormula, theo: Theory, bvl: KernelL, ans: Boolean): VSdb;
   % VS data for a block make initial VSdb.
   begin scalar db;
      db := vsdb_new();
      vsdb_putvl(db, vl);
      vsdb_putf(db, f);
      vsdb_puttheo(db, theo);
      vsdb_putbvl(db, bvl);
      vsdb_putans(db, ans);
      vsdb_putwc(db, vsco_mk());
      vsdb_putsc(db, vsco_mk());
      vsdb_putfc(db, vsco_mk());
      vsdb_putht(db, vsht_mk());
      vsdb_putcurtheo(db, theo);
      vsdb_wcinsert(db, vsnd_mk(nil, nil, vl, f, nil));
      return db
   end;

asserted procedure vsdb_todop(db: VSdb): ExtraBoolean;
   % Todo predicate. Checks whether the working container is empty.
   vsco_nonemptyp vsdb_wc db;

asserted procedure vsdb_wcget(db: VSdb): VSnd;
   % Get a node from the working container.
   begin scalar c;
      assert(vsdb_todop db);
      c := vsco_get vsdb_wc db;
      vsdb_putwc(db, cdr c);
      return car c
   end;

asserted procedure vsdb_dropall(db: VSdb);
   % Drop all nodes. Removes all nodes from working, success, and
   % failure containers.
   <<
      vsdb_putwc(db, vsco_mk());
      vsdb_putsc(db, vsco_mk());
      vsdb_putfc(db, vsco_mk())
   >>;

asserted procedure vsdb_htmember(db: VSdb, f: QfFormula): ExtraBoolean;
   % Hash table member.
   vsht_member(vsdb_ht db, f);

asserted procedure vsdb_wcinsert(db: VSdb, nd: VSnd);
   % Working container insert.
   vsdb_putwc(db, vsco_insert(vsdb_wc db, nd));

asserted procedure vsdb_scinsert(db: VSdb, nd: VSnd);
   % Success container insert.
   vsdb_putsc(db, vsco_insert(vsdb_sc db, nd));

asserted procedure vsdb_fcinsert(db: VSdb, nd: VSnd);
   % Failure container insert.
   vsdb_putfc(db, vsco_insert(vsdb_fc db, nd));

asserted procedure vsdb_htinsert(db: VSdb, f: QfFormula);
   % Hash table insert.
   vsdb_putht(db, vsht_insert(vsdb_ht db, f));

%%% "real" procedures %%%

asserted procedure vs_block(f: QfFormula, vl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % This is the usual entry point.
   % TODO: Update this old procedure description.
   % Quantifier elimination for one block subroutine. The result
   % contains the list of variables for which elimination failed, the
   % (possibly partial) possibly negated elimination result as a
   % JunctionL, and the new theory.
   begin scalar db, rf, rvl;
      db := vsdb_mk(vl, f, theo, bvl, ans);
      vs_blockmainloop db;
      % ioto_prin2t nil;
      % vsdb_print db;
      rf . rvl := vsdb_collectResult db;
      if !*ofsfvsqetree2gml then
      	 vsdb_2gml(db, rlqetreegmlfile!*);
      return {rvl, {rf . nil}, theo}
   end;

asserted procedure vs_blockmainloop(db: VSdb);
   % Quantifier elimination for one block subroutine. This procedure
   % realizes the main loop of QE for a single block of quantifiers.
   % No meaningful return value. [db] is modified in-place.
   begin scalar nd, vl, f, mbr;
      while vsdb_todop db do <<
	 nd := vsdb_wcget db;
	 vl := vsnd_vl nd;
	 f := vsnd_f nd;
	 if vsnd_flg nd then  % substitution has not been applied yet
	    vsdb_applyvs(db, nd)
	 else <<  % substitution was already applied
	    mbr := vsdb_htmember(db, f);
	    if not mbr or vsvs_arp vsnd_vs nd then <<
	       if not mbr then
	       	  vsdb_htinsert(db, f);
	       if f eq 'true then
	       	  vsdb_dropall db;
	       if null vl then
	       	  vsdb_scinsert(db, nd)
	       else <<
		  if !*rlverbose then
		     vsnd_printinfo nd;
		  vsdb_expandNode(db, nd)
	       >>
	    >> % else
 	       % vsdb_scinsert(db, nd)
	       %
	       % One can use this "else" branch to document also those
	       % nodes that were dropped because they contained a
	       % formula occurring elsewhere in the QE tree.
	 >>
      >>
   end;

asserted procedure vsdb_applyvs(db: VSdb, nd: VSnd);
   % Apply substitution. No meaningful return value; [db] is modified
   % in-place so that the subsitution in [nd] is applied, i.e., a list
   % of nodes is added to the working container.
   begin scalar vs, v, oo, ffl;
      % TODO: more liberal kernel reordering policy
      vs := vsnd_vs nd;
      v := vsvs_v vs;
      oo := updkorder v;
      ffl := qff_applyvs(vsvs_reorder vs,
	 ofsf_reorder vsnd_f nd, vsdb_bvl db, ofsf_reorderl vsdb_curtheo db);
      setkorder oo;
      for each ff in ffl do
	 vsdb_wcinsert(db, vsnd_mk(nil, vs, vsnd_vl nd, ff, vsnd_parent nd))
   end;

asserted procedure vsdb_expandNode(db: VSdb, nd: VSnd);
   % Expand node. No meaningful return value; [db] is modified
   % in-place so that [nd] is properly expanded at the end of the
   % procedure, i.e., either a list of children is added to the
   % working container, or [nd] is added to the failure container.
   begin
      assert(vsnd_vl nd);
      assert(not vsnd_flg nd);
      if vsdb_tryExpandNO(db, nd) then
	 return;
      if vsdb_tryExpandDG(db, nd) then
	 return;
      % Now each variable occurs, and no degree shift is possible.
      if eqn(rlvarsellvl!*, 1) then
	 vsdb_expandNode1(db, nd);
      if eqn(rlvarsellvl!*, 2) then
	 vsdb_expandNode2(db, nd);
      if eqn(rlvarsellvl!*, 3) then
	 vsdb_expandNode3(db, nd);
      if eqn(rlvarsellvl!*, 4) then
	 vsdb_expandNode4(db, nd)
   end;

asserted procedure vsdb_tryExpandNO(db: VSdb, nd: VSnd): Boolean;
   % Try to expand node by non-occurring variable. Returns whether
   % this was successful. [nil] is returned iff every variable from
   % [vsnd_vl nd] occurs in [vsnd_f nd].
   begin scalar vl, rvl, res, v;
      vl := vsnd_vl nd;
      rvl := cl_fvarl1 vsnd_f nd;
      while vl and not res do <<
	 v := pop vl;
	 if not (v memq rvl) then <<
	    res := t;
	    vsdb_wcinsert(db,
	       vsnd_mk(nil, vsar_mk v, delq(v, vsnd_vl nd), vsnd_f nd, nd))
	 >>
      >>;
      if !*rlverbose and res then
	 ioto_tprin2t {"+++++ ESET succ ", v, " (does not occur)"};
      return res
   end;

asserted procedure vsdb_tryExpandDG(db: VSdb, nd: VSnd): Boolean;
   % Try to expand node by degree shift. Returns whether this was
   % successful. [nil] is returned iff degree shift is not possible
   % w.r.t. no variable in [vsnd_vl nd].
   begin scalar vl, f, res, v, sv; integer g;
      vl := vsnd_vl nd;
      f := vsnd_f nd;
      if vsvs_dgp vsnd_vs nd then
	 vl := delq(vsdg_sv vsnd_vs nd, vl);  % We need not to try degree shift w.r.t. the most recent shadow variable.
      while vl and not res do <<
	 v := pop vl;
	 g := vs_dgcd(f, v);
	 if g > 1 then <<
	    res := t;
	    sv := vs_shadow v;
	    vsdb_wcinsert(db, vsnd_mk(t,
	       vsdg_mk(v, g, sv), subst(sv, v, vsnd_vl nd), vsnd_f nd, nd))
	 >>
      >>;
      if !*rlverbose and res then
	 ioto_tprin2t {"+++++ ESET succ ", v, " ^ ", g, " = ", sv, " (degree shift)"};
      return res
   end;

asserted procedure vsdb_expandNode1(db: VSdb, nd: VSnd);
   % Expand node using strategy 1: Use the first variable.
   begin scalar v, oo, de;
      % TODO: more liberal kernel reordering policy
      v := car vsnd_vl nd;
      oo := updkorder v;
      de := vsde_mk(v, ofsf_reorder vsnd_f nd, ofsf_reorderl vsdb_curtheo db, vsdb_bvl db);
      vsde_compute de;
      setkorder oo;
      vsdb_insertaec(db, nd, de)
   end;

asserted procedure vsdb_expandNode2(db: VSdb, nd: VSnd);
   % Expand node using strategy 2: Use the first feasible variable.
   begin scalar vl, f, theo, bvl, v, oo, de;
      % TODO: more liberal kernel reordering policy
      vl := vsnd_vl nd;
      f := vsnd_f nd;
      theo := vsdb_curtheo db;
      bvl := vsdb_bvl db;
      repeat <<
	 v := pop vl;
	 oo := updkorder v;
      	 de := vsde_mk(v, ofsf_reorder f, ofsf_reorderl theo, bvl);
	 vsde_compute de;
      	 setkorder oo
      >> until null vl or vsde_tpl de;
      vsdb_insertaec(db, nd, de)
   end;

asserted procedure vsdb_expandNode3(db: VSdb, nd: VSnd);
   % Expand node using strategy 3: Use the variable with the best
   % elimination set.
   begin scalar vl, f, theo, bvl, sltd, v, oo, de, del;
      vl := vsnd_vl nd;
      f := vsnd_f nd;
      theo := vsdb_curtheo db;
      bvl := vsdb_bvl db;
      % Try to select a variable with a linear elimset w.r.t. [bvl].
      while vl and not sltd do <<
	 v := pop vl;
	 oo := updkorder v;
	 de := vsde_mk(v, ofsf_reorder f, ofsf_reorderl theo, bvl);
	 vsde_compute de;
	 if vsde_tpllinp(de, bvl) then  % If there is a variable with a linear elimset, then take it.
	    sltd := t;
	 push(de, del);
	 setkorder oo
      >>;
      if sltd then <<
      	 vsdb_insertaec(db, nd, de);
	 return
      >>;
      de := vsdb_expandNode3!-selectBestDE reversip del;
      vsdb_insertaec(db, nd, de)
   end;

asserted procedure vsdb_expandNode3!-selectBestDE(del: List): VSde;
   begin scalar tmpdel, sltd, de, oo;
      assert(del);
      % Try to select a variable with an elimset of degree 1.
      tmpdel := del;
      while tmpdel and not sltd do <<
	 de := pop tmpdel;
	 oo := updkorder vsde_v de;
      	 if vsde_tplldp(de, 1) then
	    sltd := t;
	 setkorder oo
      >>;
      if sltd then
	 return de;
      % Try to select a variable with an elimset of degree 2.
      tmpdel := del;
      while tmpdel and not sltd do <<
	 de := pop tmpdel;
	 oo := updkorder vsde_v de;
      	 if vsde_tplldp(de, 2) then
	    sltd := t;
	 setkorder oo
      >>;
      if sltd then
	 return de;
      % Try to select a variable with some non-failed elimset.
      tmpdel := del;
      while tmpdel and not sltd do <<
	 de := pop tmpdel;
	 oo := updkorder vsde_v de;
      	 if vsde_tpl de then
	    sltd := t;
	 setkorder oo
      >>;
      if sltd then
	 return de;
      % Select the first variable.
      return car del
   end;

asserted procedure vsdb_expandNode4(db: VSdb, nd: VSnd);
   % Expand node using strategy 4: Use the variable with the best
   % formula after elimination.
   ;

asserted procedure vsdb_insertaec(db: VSdb, nd: VSnd, de: VSde);
   % Insert node after elimination set computation.
   begin scalar tpl, f, v, nvl;
      tpl := vsde_tpl de;
      if null vsde_tpl de then <<  % An elimination set has to be non-empty.
      	 if !*rlverbose then
	    ioto_tprin2t {"+++++ ESET fail ", vsde_v de};
	 vsdb_fcinsert(db, nd);
	 return
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"+++++ ESET succ ", vsde_v de, " (eset size: ", length vsde_tpl de, ")"};
      f := vsde_f de;
      v := vsde_v de;
      nvl := delq(v, vsnd_vl nd);
      for each tp in tpl do
	 vsdb_wcinsert(db, vsnd_mk(t, vsts_mk(v, tp), nvl, f, nd))
   end;

asserted procedure vsdb_collectResult(db: VSdb): DottedPair;
   % Collect the result of elimination stored in [db]. Returns a pair
   % [f . vl], where [f] is the resulting formula and [vl] is the list
   % of variables that were not eliminated.
   begin scalar fl, vl;
      assert(not vsdb_todop db);
      for each nd in vsdb_sc db do <<
	 assert(not vsnd_flg nd);
	 push(vsnd_f nd, fl)
      >>;
      for each nd in vsdb_fc db do <<
	 assert(not vsnd_flg nd);
	 push(vsnd_f nd, fl);
	 vl := union(vl, vsnd_vl nd)
      >>;
      return cl_simpl(rl_mkn('or, fl), vsdb_theo db, -1) . vl
   end;

%%% other procedures %%%

% TODO: Move the following procedure to cl.
asserted procedure vs_shadow(x: Kernel): Kernel;
   % Create shadow variable for [x].
   begin scalar res;
      res := gensym();
      put(res, 'shadow, x);
      return res
   end;

% TODO: Move the following procedure to cl.
asserted procedure vs_dgcd(f: QfFormula, x: Kernel): Integer;
   % Degree gcd. Returns the gcd of the exponents of [x] in [f]. If
   % [x] does not occur in [f], then [0] is returned.
   begin scalar atl, at; integer g;
      atl := cl_atl1 f;
      while atl and not eqn(g, 1) do <<
	 at := pop atl;
	 g := gcdn(g, sfto_dgcdf(ofsf_arg2l at, x))
      >>;
      return g
   end;

% TODO: Move the following procedure to sfto.
asserted procedure sfto_dgcdf(f: SF, x: Kernel): Integer;
   % Degree gcd. Returns the gcd of the exponents of [x] in [f]. If
   % [x] does not occur in [f], then [0] is returned.
   begin scalar oo; integer g;
      if domainp f then
	 return 0;
      oo := setkorder {x};
      f := reorder f;
      while sfto_mvartest(f, x) and not eqn(g, 1) do <<
	 g := gcdn(g, ldeg f);
	 f := red f
      >>;
      setkorder oo;
      return g
   end;

asserted procedure vsdb_2gml(db: VSdb, filename: String): Any;
   % Output a graph of nodes contained in [db] in gml format.
   begin scalar nat, vlm;
      nat := !*nat;
      off1 'nat;
      out filename;
      ioto_prin2t "Creator ""REDLOG""";
      ioto_prin2t "graph [";
      ioto_prin2t "label ""VSdb graph generated by REDLOG.""";
      ioto_prin2t "directed 1";
      vlm := nil . 0;
      for each nd in vsdb_wc db do
	 vlm := vsdb_2gmln(nd, cdr vlm + 1, "#C0C0C0", vlm);
      for each nd in vsdb_sc db do
	 vlm := vsdb_2gmln(nd, cdr vlm + 1, "#00FF00", vlm);
      for each nd in vsdb_fc db do
	 vlm := vsdb_2gmln(nd, cdr vlm + 1, "#FF0000", vlm);
      ioto_prin2t "]";
      if nat then on1 'nat;
      shut filename
   end;

asserted procedure vsdb_2gmln(nd: VSnd, n: Integer, c: String, vlm: DottedPair): DottedPair;
   % Output a graph of nodes contained in [db] in gml format: node
   % subprocedure.
   begin scalar w, p;
      w := atsoc(nd, car vlm);
      if w then
	 return vlm;
      vsdb_2gmln!-printn(nd, n, c);
      p := vsnd_parent nd;
      if p then <<
	 vlm := vsdb_2gmln(p, n + 1, "#C0C0C0", vlm);
      	 w := atsoc(p, car vlm);
      	 assert(w);
      	 vsdb_2gmln!-printe(nd, cdr w, n)
      >>;
      return ((nd . n) . car vlm) . if n > cdr vlm then n else cdr vlm
   end;

asserted procedure vsdb_2gmln!-printn(nd: VSnd, n: Integer, c: String);
   % Output a graph of nodes contained in [db] in gml format: print
   % node subprocedure.
   <<
      ioto_prin2t "node [";
      ioto_prin2t {"id ", n};
      ioto_prin2t "label """;
      mathprint rl_prepfof vsnd_f nd;
      ioto_prin2t {"vl: ", vsnd_vl nd};
      ioto_prin2t """";
      % color
      ioto_prin2t {"graphics [", "fill """, c, """]"};
      ioto_prin2t "]"
   >>;

asserted procedure vsdb_2gmln!-printe(nd: VSnd, ss: Integer, tt: Integer);
   % Output a graph of nodes contained in [db] in gml format: print
   % edge subprocedure.
   begin scalar vs, tp;
      vs := vsnd_vs nd;
      ioto_prin2t "edge [";
      ioto_prin2t {"source ", ss};
      ioto_prin2t {"target ", tt};
      ioto_prin2t "label """;
      if vsvs_tsp vs then <<
	 tp := vsts_tp vs;
	 if vstp_np tp eq 'minf then <<
      	    ioto_prin2t {vsvs_v vs, " = - inf"};
	    ioto_prin2 "guard:";
	    mathprint rl_prepfof vstp_guard tp
	 >> else if vstp_np tp eq 'pinf then <<
      	    ioto_prin2t {vsvs_v vs, " = + inf"};
	    ioto_prin2 "guard:";
	    mathprint rl_prepfof vstp_guard tp
	 >> else if vstp_np tp eq 'meps then <<
      	    ioto_prin2t {vsvs_v vs, " = tp - eps"};
	    mathprint prepf vspr_f vstp_pr tp;
	    ioto_prin2t vspr_rsl vstp_pr tp;
	    ioto_prin2 "guard:";
	    mathprint rl_prepfof vstp_guard tp
      	 >> else if vstp_np tp eq 'peps then <<
      	    ioto_prin2t {vsvs_v vs, " = tp + eps"};
	    mathprint prepf vspr_f vstp_pr tp;
	    ioto_prin2t vspr_rsl vstp_pr tp;
	    ioto_prin2 "guard:";
	    mathprint rl_prepfof vstp_guard tp
	 >> else <<
      	    ioto_prin2t {vsvs_v vs, " = tp"};
	    mathprint prepf vspr_f vstp_pr tp;
	    ioto_prin2t vspr_rsl vstp_pr tp;
	    ioto_prin2 "guard:";
	    mathprint rl_prepfof vstp_guard tp
	 >>
      >> else if vsvs_dgp vs then
      	 ioto_prin2t {vsvs_v vs, " = ", vsdg_g vs, "-th root of ", vsdg_sv vs}
      else if vsvs_arp vs then
      	 ioto_prin2t {vsvs_v vs, " = arbitrary"};
      ioto_prin2t """";
      ioto_prin2t "]"
   end;

% functions mainly for debugging purposes

asserted procedure vsdb_prints(db: VSdb);
   % VSdb print summary.
   <<
      ioto_prin2 "VSdb: ";
      	 ioto_prin2t {"#W: ", length vsdb_wc db,
      	    " #S: ", length vsdb_sc db,
      	    " #F: ", length vsdb_fc db,
      	    " #H: ", length cadr vsdb_ht db}
   >>;

asserted procedure vsdb_print(db: VSdb);
   % VSdb print.
   begin scalar wc, sc, fc;
      wc := vsdb_wc db;
      sc := vsdb_sc db;
      fc := vsdb_fc db;
      ioto_prin2t nil;
      ioto_prin2 "VSdb WORKING NODES:";
      if null wc then
      	 ioto_prin2t " NONE"
      else <<
      	 ioto_prin2t nil;
	 vsnd_printl wc
      >>;
      ioto_prin2t nil;
      ioto_prin2 "VSdb SUCCESS NODES:";
      if null sc then
      	 ioto_prin2t " NONE"
      else <<
      	 ioto_prin2t nil;
	 vsnd_printl sc
      >>;
      ioto_prin2t nil;
      ioto_prin2 "VSdb FAILURE NODES:";
      if null fc then
      	 ioto_prin2t " NONE"
      else <<
      	 ioto_prin2t nil;
	 vsnd_printl fc
      >>
   end;

asserted procedure vsnd_printl(ndl: VSndL);
   % VSnd print list.
   for each nd in ndl do
      vsnd_print nd;

asserted procedure vsnd_prints(nd: VSnd);
   % VSnd print summary.
   ioto_prin2t {"VSnd:",
      " vl: ", vsnd_vl nd,
      " flag: ", vsnd_flg nd};

asserted procedure vsnd_print(nd: VSnd);
   % VSnd print.
   begin scalar vs;
      ioto_prin2t "VSnd:";
      mathprint rl_prepfof vsnd_f nd;
      ioto_prin2t {"vl: ", vsnd_vl nd, " flag: ", vsnd_flg nd};
      vs := vsnd_vs nd;
      vsvs_prints vs
   end;

asserted procedure vsnd_printinfo(nd: VSnd);
   begin scalar f;
      f := vsnd_f nd;
      ioto_tprin2 "+++++ QE node: ";
      ioto_prin2 {"#q-var = ", length vsnd_vl nd, ", "};
      ioto_prin2t {"#at = ", cl_atnum f};
      % ioto_prin2 "+++++ max degs: ";
      % for each s on car cl_ifacdegl f do <<
      % 	 ioto_prin2 {caar s, ": ", cdar s};
      % 	 if cdr s then
      % 	    ioto_prin2 ", "
      % >>;
      ioto_prin2t nil
   end;

endmodule;  % [ofsfvsblock]

end;  % of file
