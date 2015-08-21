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
rlvarsellvl!* := 1;

%%% QE tree node %%%
% constructors and access functions

asserted procedure vsnd_mk(flg: Boolean, vs: VSsu, varl: KernelL, f: QfFormula, p: VSnd): VSnd;
   % QE tree node make. [flg] denotes whether VS [vs] needs to be
   % applied; [varl] is a list of variables to be eliminated; [f] is a
   % quantifier-free formula; [p] is the parent QE tree node.
   {'vsnd, flg, vs, varl, f, p};

asserted procedure vsnd_flg(nd: VSnd): Boolean;
   % QE tree node flag.
   nth(nd, 2);

asserted procedure vsnd_su(nd: VSnd): VSsu;
   % QE tree node VS.
   nth(nd, 3);

asserted procedure vsnd_varl(nd: VSnd): KernelL;
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
      putv(db, 1, 'undefined);        % [varl]: variables to be eliminated
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

procedure vsdb_varl(db);                         getv(db, 1);
procedure vsdb_f(db);                            getv(db, 2);
procedure vsdb_theo(db);                         getv(db, 3);
procedure vsdb_bvl(db);                          getv(db, 4);
procedure vsdb_ans(db);                          getv(db, 5);
procedure vsdb_wc(db);                           getv(db, 6);
procedure vsdb_sc(db);                           getv(db, 7);
procedure vsdb_fc(db);                           getv(db, 8);
procedure vsdb_ht(db);                           getv(db, 9);
procedure vsdb_curtheo(db);                      getv(db, 10);

procedure vsdb_putvarl(db, varl);                putv(db, 1, varl);
procedure vsdb_putf(db, f);                      putv(db, 2, f);
procedure vsdb_puttheo(db, theo);                putv(db, 3, theo);
procedure vsdb_putbvl(db, bvl);                  putv(db, 4, bvl);
procedure vsdb_putans(db, ans);                  putv(db, 5, ans);
procedure vsdb_putwc(db, wc);                    putv(db, 6, wc);
procedure vsdb_putsc(db, sc);                    putv(db, 7, sc);
procedure vsdb_putfc(db, fc);                    putv(db, 8, fc);
procedure vsdb_putht(db, ht);                    putv(db, 9, ht);
procedure vsdb_putcurtheo(db, theo);             putv(db, 10, theo);

asserted procedure vsdb_mk(varl: KernelL, f: QfFormula, theo: Theory, bvl: KernelL, ans: Boolean): VSdb;
   % VS data for a block make initial VSdb.
   begin scalar db;
      db := vsdb_new();
      vsdb_putvarl(db, varl);
      vsdb_putf(db, f);
      vsdb_puttheo(db, theo);
      vsdb_putbvl(db, bvl);
      vsdb_putans(db, ans);
      vsdb_putwc(db, vsco_mk());
      vsdb_putsc(db, vsco_mk());
      vsdb_putfc(db, vsco_mk());
      vsdb_putht(db, vsht_mk());
      vsdb_putcurtheo(db, theo);
      vsdb_wcinsert(db, vsnd_mk(nil, nil, varl, f, nil));
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

asserted procedure vs_block(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % This is the usual entry point.
   % TODO: Update this old procedure description.
   % Quantifier elimination for one block subroutine. The result
   % contains the list of variables for which elimination failed, the
   % (possibly partial) possibly negated elimination result as a
   % JunctionL, and the new theory.
   begin scalar db;
      db := vsdb_mk(varl, f, theo, bvl, ans);
      vs_blockmainloop db;
      ioto_prin2t nil;
      vsdb_printSummary db;
      return {varl, {f . nil}, theo}
   end;

asserted procedure vs_blockmainloop(db: VSdb);
   % Quantifier elimination for one block subroutine. This procedure
   % realizes the main loop of QE for a single block of quantifiers.
   % No meaningful return value. [db] is modified in-place.
   begin scalar nd, varl, f, mbr;
      while vsdb_todop db do <<
	 nd := vsdb_wcget db;
	 varl := vsnd_varl nd;
	 f := vsnd_f nd;
	 if vsnd_flg nd then  % substitution has not been applied yet
	    vsdb_applySub(db, nd)
	 else <<  % substitution was already applied
	    mbr := vsdb_htmember(db, f);
	    if not mbr or vssu_arp vsnd_su nd then <<
	       if not mbr then
	       	  vsdb_htinsert(db, f);
	       if f eq 'true then
	       	  vsdb_dropall db;
	       if null varl then
	       	  vsdb_scinsert(db, nd)
	       else
		  vsdb_expandNode(db, nd)
	    >>
	 >>
      >>
   end;

asserted procedure vsdb_applySub(db: VSdb, nd: VSnd);
   % Apply substitution. No meaningful return value; [db] is modified
   % in-place so that the subsitution in [nd] is applied, i.e., a list
   % of nodes is added to the working container.
   begin scalar su, ffl;
      su := vsnd_su nd;
      ffl := qff_applysub(su, vsnd_f nd, vsdb_bvl db, vsdb_curtheo db);
      for each ff in ffl do
	 vsdb_wcinsert(db, vsnd_mk(nil, su, vsnd_varl nd, ff, vsnd_parent nd))
   end;

asserted procedure vsdb_expandNode(db: VSdb, nd: VSnd);
   % Expand node. No meaningful return value; [db] is modified
   % in-place so that [nd] is properly expanded at the end of the
   % procedure, i.e., either a list of children is added to the
   % working container, or [nd] is added to the failure container.
   begin
      assert(vsnd_varl nd);
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
   % [vsnd_varl nd] occurs in [vsnd_f nd].
   begin scalar vl, rvl, res, v;
      vl := vsnd_varl nd;
      rvl := cl_fvarl1 vsnd_f nd;
      while vl and not res do <<
	 v := pop vl;
	 if not (v memq rvl) then <<
	    res := t;
	    vsdb_wcinsert(db,
	       vsnd_mk(nil, vsar_mk v, delq(v, vsnd_varl nd), vsnd_f nd, nd))
	 >>
      >>;
      return res
   end;

asserted procedure vsdb_tryExpandDG(db: VSdb, nd: VSnd): Boolean;
   % Try to expand node by degree shift. Returns whether this was
   % successful. [nil] is returned iff degree shift is not possible
   % w.r.t. no variable in [vsnd_varl nd].
   begin scalar vl, f, res, v, sv; integer g;
      vl := vsnd_varl nd;
      f := vsnd_f nd;
      if vssu_dgp vsnd_su nd then
	 vl := delq(vsdg_sv vsnd_su nd, vl);  % We need not to try degree shift w.r.t. the most recent shadow variable.
      while vl and not res do <<
	 v := pop vl;
	 g := vs_dgcd(f, v);
	 if g > 1 then <<
	    res := t;
	    sv := vs_shadow v;
	    vsdb_wcinsert(db, vsnd_mk(t,
	       vsdg_mk(v, g, sv), subst(sv, v, vsnd_varl nd), vsnd_f nd, nd))
	 >>
      >>;
      return res
   end;

asserted procedure vsdb_expandNode1(db: VSdb, nd: VSnd);
   % Expand node using strategy 1: Use the first variable.
   begin scalar de, v;
      v := car vsnd_varl nd;
      de := vsde_mk(v, vsnd_f nd, vsdb_curtheo db, vsdb_bvl db);
      vsde_compute de;
      vsdb_insertaec(db, nd, de)
   end;

asserted procedure vsdb_expandNode2(db: VSdb, nd: VSnd);
   % Expand node using strategy 2: Use the first feasible variable.
   begin scalar varl, f, v, de;
      varl := vsnd_varl nd;
      f := vsnd_f nd;
      repeat <<
	 v := pop varl;
      	 de := vsde_mk(v, vsnd_f nd, vsdb_curtheo db, vsdb_bvl db);
	 vsde_compute de;
      >> until null varl or vsde_tpl de;
      vsdb_insertaec(db, nd, de)
   end;

asserted procedure vsdb_expandNode3(db: VSdb, nd: VSnd);
   % Expand node using strategy 3: Use the variable with the best
   % elimination set.
   ;

asserted procedure vsdb_expandNode4(db: VSdb, nd: VSnd);
   % Expand node using strategy 4: Use the variable with the best
   % formula after elimination.
   ;

asserted procedure vsdb_insertaec(db: VSdb, nd: VSnd, de: VSde);
   % Insert node after elimination set computation.
   begin scalar tpl, f, v, nvarl;
      tpl := vsde_tpl de;
      if null vsde_tpl de then <<
	 vsdb_finsert(db, nd);
	 return
      >>;
      f := vsde_f de;
      v := vsde_var de;
      nvarl := delq(v, vsnd_varl nd);
      for each tp in tpl do
	 vsdb_wcinsert(db, vsnd_mk(t, vsvs_mk(v, tp), nvarl, f, nd))
   end;

%%% other procedures %%%

% TODO: Move the following procedure to cl.
asserted procedure vs_shadow(v: Kernel): Kernel;
   % Create shadow variable for [v].
   begin scalar res;
      res := gensym();
      put(res, 'shadow, v);
      return res
   end;

% TODO: Move the following procedure to cl.
asserted procedure vs_dgcd(f: QfFormula, v: Kernel): Integer;
   % Degree gcd. Returns the gcd of the exponents of [v] in [f]. If
   % [v] does not occur in [f], then [0] is returned.
   begin scalar atl, at; integer g;
      atl := cl_atl1 f;
      while atl and not eqn(g, 1) do <<
	 at := pop atl;
	 g := gcdn(g, sfto_dgcdf(ofsf_arg2l at, v))
      >>;
      return g
   end;

% TODO: Move the following procedure to sfto.
asserted procedure sfto_dgcdf(f: SF, v: Kernel): Integer;
   % Degree gcd. Returns the gcd of the exponents of [v] in [f]. If
   % [v] does not occur in [f], then [0] is returned.
   begin scalar oo; integer g;
      if domainp f then
	 return 0;
      oo := setkorder {v};
      f := reorder f;
      while not domainp f and mvar f eq v and not eqn(g, 1) do <<
	 g := gcdn(g, ldeg f);
	 f := red f
      >>;
      setkorder oo;
      return g
   end;

% functions mainly for debugging purposes

asserted procedure vsdb_printSummary(db: VSdb);
   <<
      ioto_prin2 {"VSdb: "};
      	 ioto_prin2t {"#W: ", length vsdb_wc db,
      	    " #S: ", length vsdb_sc db,
      	    " #F: ", length vsdb_fc db,
      	    " #H: ", length cadr vsdb_ht db}
   >>;

asserted procedure vsnd_printSummary(nd: VSnd);
   ioto_prin2t {"VS node:",
      " FLAG: ", vsnd_flg nd,
      " VARL: ", vsnd_varl nd};

asserted procedure vsndl_printLength(ndl: VSndL);
   ioto_prin2t {"VS node list of length ", length ndl};

endmodule;  % [ofsfvsblock]

end;  % of file
