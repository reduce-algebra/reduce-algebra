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
   fluid '(ofsfvs_rcsid!* ofsfvs_copyright!*);
   ofsfvs_rcsid!* :=
      "$Id$";
   ofsfvs_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvs;

fluid '(rlvarsellvl!*);
rlvarsellvl!* := 1;

% data types and access functions

struct VSsu checked by VSsuP;  % virtual substitution
struct VSvs checked by VSvsP;  % virtual substitution: test point substitution
struct VSdg checked by VSdgP;  % virtual substitution: degree shift
struct VSar checked by VSarP;  % virtual substitution: arbitrary
struct VStp checked by VStpP;  % test point
struct VSnd checked by VSndP;  % QE tree node
struct VSco checked by VScoP;  % container of nodes
struct VSht checked by VShtP;  % hash table of quantifier-free formulas
struct VStr checked by VStrP;  % QE tree
struct VSdb checked by VSdbP;  % virtual substitution data for a block

struct VStpL checked by VStpLP;  % list of test points
struct VSndL checked by VSndLP;  % list of QE tree nodes

procedure VSsuP(s);  % virtual substitution
   VSarP s or VSdgP s or VSvsP s;

procedure VSvsP(s);  % virtual substitution: test point substitution
   pairp s and car s eq 'vsvs;

procedure VSdgP(s);  % virtual substitution: degree shift
   pairp s and car s eq 'vsdg;

procedure VSarP(s);  % virtual substitution: arbitrary
   pairp s and car s eq 'vsar;

procedure VStpP(s);  % test point
   % TODO: Specify this data type.
   pairp s;

procedure VSndP(s);  % QE tree node
   pairp s and car s eq 'vsnd;

procedure VScoP(s);  % container of nodes
   listp s;

procedure VShtP(s);  % hash table of quantifier-free formulas
   pairp s and car s eq 'vsht;

procedure VStrP(s);  % QE tree
   pairp s and car s eq 'vstr;

procedure VSdbP(s);  % virtual substitution data for a block
   atom s and getv(s, 0) eq 'vsdb;

procedure VStpLP(s);  % list of test points
   null s or (pairp s and VStpP car s and VStpLP cdr s);

procedure VSndLP(s);  % list of QE tree nodes
   null s or (pairp s and VSndP car s and VSndLP cdr s);

asserted procedure vssu_vpp(vs: VSsu): Boolean;
   % Virtual substitution test point substitution predicate.
   pairp vs and car vs eq 'vsvs;

asserted procedure vssu_dgp(vs: VSsu): Boolean;
   % Virtual substitution degree shift predicate.
   pairp vs and car vs eq 'vsdg;

asserted procedure vssu_arp(vs: VSsu): Boolean;
   % Virtual substitution arbitrary predicate.
   pairp vs and car vs eq 'vsar;

asserted procedure vsvs_mk(v: Kernel, tp: VStp): VSsu;
   % Virtual substitution test point substitution make.
   {'vsvs, v, tp};

asserted procedure vsvs_v(vs: VSvs): Kernel;
   % Virtual substitution test point substitution variable.
   nth(vs, 2);

asserted procedure vsvs_tp(vs: VSvs): VStp;
   % Virtual substitution test point substitution test point.
   nth(vs, 3);

asserted procedure vsdg_mk(v: Kernel, g: Integer, sv: Kernel): VSsu;
   % Virtual substitution degree shift make.
   {'vsdg, v, g, sv};

asserted procedure vsdg_v(vs: VSdg): Kernel;
   % Virtual substitution degree shift variable.
   nth(vs, 2);

asserted procedure vsdg_g(vs: VSdg): Integer;
   % Virtual substitution degree shift gcd.
   nth(vs, 3);

asserted procedure vsdg_sv(vs: VSdg): Kernel;
   % Virtual substitution degree shift shadow variable.
   nth(vs, 4);

asserted procedure vsar_mk(v: Kernel): VSsu;
   % Virtual substitution arbitrary make.
   {'vsar, v};

asserted procedure vsar_v(vs: VSar): Kernel;
   % Virtual substitution arbitrary variable.
   nth(vs, 2);

asserted procedure vsnd_mk(flg: Boolean, vs: VSsu, varl: KernelL, f: QfFormula, p: VSnd): VSnd;
   % QE tree node make. [flg] denotes whether virtual substitution
   % [vs] needs to be applied; [varl] is a list of variables to be
   % eliminated; [f] is a quantifier-free formula; [p] is the parent
   % QE tree node.
   {'vsnd, flg, vs, varl, f, p};

asserted procedure vsnd_flg(nd: VSnd): Boolean;
   % QE tree node flag.
   nth(nd, 2);

asserted procedure vsnd_su(nd: VSnd): VSsu;
   % QE tree node virtual substitution.
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

asserted procedure vsco_new(): VSco;
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

asserted procedure vsht_new(): VSht;
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

asserted procedure vstr_new(): VStr;
   % QE tree new.
   {'vstr, vsco_new(), vsco_new(), vsco_new(), vsht_new()};

asserted procedure vstr_w(vtr: VStr): VSco;
   % QE tree working nodes container.
   nth(vtr, 2);

asserted procedure vstr_s(vtr: VStr): VSco;
   % QE tree success nodes container.
   nth(vtr, 3);

asserted procedure vstr_f(vtr: VStr): VSco;
   % QE tree failure nodes container.
   nth(vtr, 4);

asserted procedure vstr_h(vtr: VStr): VSht;
   % QE tree hash table.
   nth(vtr, 5);

asserted procedure vstr_todop(vtr: VStr): ExtraBoolean;
   % QE tree todo predicate. Checks whether the working nodes
   % container is empty.
   vsco_nonemptyp vstr_w vtr;

asserted procedure vstr_wget(vtr: VStr): DottedPair;
   % QE tree get working node. [vtr] is a QE tree with a non-empty
   % working nodes container. Returns a pair [(nd . ntr)], where [nd]
   % is VSnd and [ntr] is VStr with [nd] removed from the working
   % nodes container.
   begin scalar c;
      assert(vstr_todop vtr);
      c := vsco_get vstr_w vtr;
      return car c . {'vstr, cdr c, vstr_s vtr, vstr_f vtr, vstr_h vtr}
   end;

asserted procedure vstr_dropall(vtr: VStr): VStr;
   % QE tree drop all tree nodes. Returns VStr with working, success,
   % and failure containers empty.
   {'vstr, vsco_new(), vsco_new(), vsco_new(), vstr_h vtr};

asserted procedure vstr_hmember(vtr: VStr, f: QfFormula): ExtraBoolean;
   % QE tree hash table member.
   vsht_member(vstr_h vtr, f);

asserted procedure vstr_winsert(vtr: VStr, nd: VSnd): VStr;
   % QE tree working container insert.
   {'vstr, vsco_insert(vstr_w vtr, nd), vstr_s vtr, vstr_f vtr, vstr_h vtr};

asserted procedure vstr_sinsert(vtr: VStr, nd: VSnd): VStr;
   % QE tree success container insert.
   {'vstr, vstr_w vtr, vsco_insert(vstr_s vtr, nd), vstr_f vtr, vstr_h vtr};

asserted procedure vstr_finsert(vtr: VStr, nd: VSnd): VStr;
   % QE tree failure container insert.
   {'vstr, vstr_w vtr, vstr_s vtr, vsco_insert(vstr_f vtr, nd), vstr_h vtr};

asserted procedure vstr_hinsert(vtr: VStr, f: QfFormula): VStr;
   % QE tree hash table insert.
   {'vstr, vstr_w vtr, vstr_s vtr, vstr_f vtr, vsht_insert(vstr_h vtr, f)};

asserted procedure vsdb_new(): VSdb;
   % Virtual substitution data for a block new.
   begin scalar vdb;
      vdb := mkvect(6);
      putv(vdb, 0, 'vsdb);
      putv(vdb, 1, 'undefined);        % variables to be eliminated
      putv(vdb, 2, 'undefined);        % matrix formula of the current block
      putv(vdb, 3, 'undefined);        % global background theory
      putv(vdb, 4, 'undefined);        % do not make assumptions on variables in [bvl]
      putv(vdb, 5, 'undefined);        % whether we should compute answers
      putv(vdb, 6, 'undefined);        % pool of QE tree nodes: working, success, and failure
      % putv(vdb, 7, nil);      % QEA flag; quantifier elimination with answers
      % putv(vdb, 8, nil);      % QEASTD flag; quantifier elimination with standard answers
      % putv(vdb, 9, nil);      % QEGEN flag; generic quantifier elimination
      % putv(vdb, 10, nil);     % QELOCAL flag; local quantifier elimination
      % putv(vdb, 11, nil);     % QEDEBUG flag; debugging
      % putv(vdb, 12, nil);     % QESTAT flag; statistics
      return vdb
   end;

procedure vsdb_varl(vdb);                         getv(vdb, 1);
procedure vsdb_f(vdb);                            getv(vdb, 2);
procedure vsdb_theo(vdb);                         getv(vdb, 3);
procedure vsdb_bvl(vdb);                          getv(vdb, 4);
procedure vsdb_ans(vdb);                          getv(vdb, 5);
procedure vsdb_tree(vdb);                         getv(vdb, 6);

procedure vsdb_putvarl(vdb, varl);                putv(vdb, 1, varl);
procedure vsdb_putf(vdb, f);                      putv(vdb, 2, f);
procedure vsdb_puttheo(vdb, theo);                putv(vdb, 3, theo);
procedure vsdb_putbvl(vdb, bvl);                  putv(vdb, 4, bvl);
procedure vsdb_putans(vdb, ans);                  putv(vdb, 5, ans);
procedure vsdb_puttree(vdb, tree);                putv(vdb, 6, tree);

asserted procedure vssu_apply(vs: VSsu, f: QfFormula): QfFormula;
   % Virtual substitution apply.
   if vssu_vpp vs then
      vsvs_apply(vs, f)
   else if vssu_dgp vs then
      vsdg_apply(vs, f)
   else if vssu_arp vs then
      vsar_apply(vs, f);

asserted procedure vsvs_apply(vs: VSvs, f: QfFormula): QfFormula;
   % Virtual substitution test point substitution apply.
   % TEMPORARY! Using old code to have something runnable.
   begin scalar v, tp;
      v := vsvs_v vs;
      tp := vsvs_tp vs;
      return cdr apply(car tp, nil . nil . f . v . cdr tp)
   end;

asserted procedure vsdg_apply(vs: VSdg, f: QfFormula): QfFormula;
   % Virtual substitution degree shift apply.
   begin
      f := cl_apply2ats1(f, 'vs_decdeg, {vsdg_v vs, vsdg_g vs, vsdg_sv vs});
      if not evenp vsdg_g vs then
	 return f;
      return rl_mk2('and, ofsf_0mk2('geq, vsdg_sv vs), f)
   end;

asserted procedure vs_decdeg(at: QfFormula, v: Kernel, g: Integer, sv: Kernel): QfFormula;
   % Decrement degree of atomic formula. Replace each occurence of
   % [v^n] by [sv^(n/g)].
   begin scalar f;
      % assert(at is atomic);
      f := rl_arg2l at;
      f := sfto_decdegf(f, v, g);
      return ofsf_0mk2(rl_op at, sfto_renamef(f, v, sv))
   end;

asserted procedure vsar_apply(vs: VSar, f: QfFormula): QfFormula;
   % Virtual substitution arbitrary apply.
   f;

asserted procedure vsnd_expand(nd: VSnd): VSndL;
   % QE tree node expand. Returns a list of QE tree nodes. The list is
   % empty iff expanding failed.
   begin scalar w;
      assert(vsnd_varl nd);
      assert(not vsnd_flg nd);
      w := vsnd_expandNO nd;
      if w then
	 return w;
      w := vsnd_expandDG nd;
      if w then
	 return w;
      % Now each variable occurs, and no degree shift is possible.
      if eqn(rlvarsellvl!*, 1) then
	 return vsnd_expand1 nd;
      if eqn(rlvarsellvl!*, 2) then
	 return vsnd_expand2 nd;
      if eqn(rlvarsellvl!*, 3) then
	 return vsnd_expand3 nd;
      if eqn(rlvarsellvl!*, 4) then
	 return vsnd_expand4 nd
   end;

asserted procedure vsnd_expandNO(nd: VSnd): VSndL;
   % QE tree node expand by non-occurring variables. Returns either
   % [nil] or a one element list of QE tree nodes. [nil] is returned
   % iff expand w.r.t. non-occurring variables is not possible, i.e.,
   % when every variable from [vsnd_varl nd] occurs in [vsnd_f nd].
   begin scalar vl, rvl, res, v;
      vl := vsnd_varl nd;
      rvl := cl_fvarl1 vsnd_f nd;
      while vl and null res do <<
	 v := pop vl;
	 if not (v memq rvl) then
	    res := {vsnd_mk(nil, vsar_mk v, delq(v, vsnd_varl nd), vsnd_f nd, nd)}
      >>;
      return res
   end;

asserted procedure vsnd_expandDG(nd: VSnd): VSndL;
   % QE tree node expand by degree shift. Returns either [nil] or a
   % one element list of QE tree nodes. [nil] is returned iff degree
   % shift is not possible w.r.t. no variable in [vsnd_varl nd].
   begin scalar vl, f, res, v, sv; integer g;
      vl := vsnd_varl nd;
      f := vsnd_f nd;
      if vssu_dgp vsnd_su nd then
	 vl := delq(vsdg_sv vsnd_su nd, vl);  % degree shift is not possible w.r.t. the most recent shadow variable
      while vl and null res do <<
	 v := pop vl;
	 g := vs_dgcd(f, v);
	 if g > 1 then <<
	    sv := vs_shadow v;
	    res := {vsnd_mk(t, vsdg_mk(v, g, sv),
	       subst(sv, v, vsnd_varl nd), vsnd_f nd, nd)}
	 >>
      >>;
      return res
   end;

asserted procedure vsnd_expand1(nd: VSnd): VSndL;
   % QE tree node expand1: Use the first variable.
   begin scalar v;
      v := car vsnd_varl nd;
      return vsnd_eset2vsndl(nd, eset_compute(vsnd_f nd, v), v)
   end;

asserted procedure vsnd_expand2(nd: VSnd): VSndL;
   % QE tree node expand2: Use the first feasible variable.
   begin scalar varl, f, eset, v;
      varl := vsnd_varl nd;
      f := vsnd_f nd;
      while null eset and varl do <<
	 v := pop varl;
	 eset := eset_compute(f, v)
      >>;
      return vsnd_eset2vsndl(nd, eset, v)
   end;

asserted procedure vsnd_expand3(nd: VSnd): VSndL;
   % QE tree node expand3: Use the variable with the best elimination
   % set.
   ;

asserted procedure vsnd_expand4(nd: VSnd): VSndL;
   % QE tree node expand4: Use the variable with the best formula
   % after elimination.
   ;

asserted procedure vsnd_eset2vsndl(nd: VSnd, eset: VStpL, v: Kernel): VSndL;
   % QE tree node eset2vsndl. Transform elimination set [eset] for
   % node [nd] to list of QE tree nodes.
   begin scalar varl, f;
      varl := vsnd_varl nd;
      f := vsnd_f nd;
      return for each tp in eset collect
	 vsnd_mk(t, vsvs_mk(v, tp), delq(v, varl), f, nd)
   end;

asserted procedure eset_compute(f: QfFormula, x: Kernel): VStpL;
   % Elimination set compute.
   % TEMPORARY! Using old code to obtain something runnable.
   begin scalar alp, w;
      alp := cl_qeatal(f, x, nil, nil);
      w := ofsf_elimset(x, alp);
      return for each hu in w join
	 for each huhu in cdr hu collect
	    car hu . huhu
   end;

asserted procedure vs_block(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % TODO: Update this old procedure description.
   % Quantifier elimination for one block subroutine. The result
   % contains the list of variables for which elimination failed, the
   % (possibly partial) possibly negated elimination result as a
   % JunctionL, and the new theory.
   begin scalar vdb, root, tree;
      vdb := vsdb_new();
      root := vsnd_mk(nil, nil, varl, f, nil);
      tree := vstr_winsert(vstr_new(), root);
      vsdb_putf(vdb, f);
      vsdb_putvarl(vdb, varl);
      vsdb_puttheo(vdb, theo);
      vsdb_putans(vdb, ans);
      vsdb_putbvl(vdb, bvl);
      vsdb_puttree(vdb, tree);
      vs_mainloop vdb;
      ioto_prin2t nil;
      vstr_printSummary vsdb_tree vdb;
      return {varl, {f . nil}, theo}
   end;

asserted procedure vs_mainloop(vdb: VSdb);
   % Quantifier elimination for one block subroutine. This procedure
   % realizes the main loop of QE for a single block of quantifiers.
   % No meaningful return value. [vdb] is modified in-place.
   begin scalar n, tree, varl, f, su, mbr, childl;
      tree := vsdb_tree vdb;
      while vstr_todop tree do <<
	 n . tree := vstr_wget tree;
	 varl := vsnd_varl n;
	 f := vsnd_f n;
	 su := vsnd_su n;
	 if vsnd_flg n then  % substitution has not been done yet
	    for each ff in vs_splitor vssu_apply(su, f) do
	       tree := vstr_winsert(tree,
		  vsnd_mk(nil, su, varl, ff, vsnd_parent n))
	 else <<  % substitution was already done
	    mbr := vstr_hmember(tree, f);
	    if not mbr or vssu_arp su then <<
	       if not mbr then
	       	  tree := vstr_hinsert(tree, f);
	       if f eq 'true then
	       	  tree := vstr_dropall tree;
	       if null varl then
	       	  tree := vstr_sinsert(tree, n)
	       else <<
	       	  childl := vsnd_expand n;
	       	  if childl then
		     for each child in childl do
		     	tree := vstr_winsert(tree, child)
	       	  else
		     tree := vstr_finsert(tree, n)
	       >>
	    >>
	 >>
      >>;
      vsdb_puttree(vdb, tree);
      return
   end;

% TODO: Move the following procedure to cl.
asserted procedure vs_splitor(f: QfFormula): QfFormulaL;
   if rl_op f eq 'or then
      rl_argn f
   else
      {f};

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

asserted procedure vstr_printSummary(vtr: VStr);
   <<
      ioto_prin2 {"VS tree: "};
      	 ioto_prin2t {"#W: ", length vstr_w vtr,
      	    " #S: ", length vstr_s vtr,
      	    " #F: ", length vstr_f vtr,
      	    " #H: ", length cadr vstr_h vtr}
   >>;

asserted procedure vsnd_printSummary(nd: VSnd);
   ioto_prin2t {"VS node:",
      " FLAG: ", vsnd_flg nd,
      " VARL: ", vsnd_varl nd};

asserted procedure vsndl_printLength(ndl: VSndL);
   ioto_prin2t {"VS node list of length ", length ndl};

asserted procedure vssu_printSummary(vs: VSsu);
   <<
      ioto_prin2 {"VS: "};
      if vssu_vpp vs then
      	 ioto_prin2t {vsvs_v vs, " = test point"}
      else if vssu_dgp vs then
      	 ioto_prin2t {vsdg_v vs, " = ", vsdg_g vs, "-th root of ", vsdg_sv vs}
      else if vssu_arp vs then
      	 ioto_prin2t {vsar_v vs, " = arbitrary"}
   >>;

endmodule;  % ofsfvs

end;  % of file
