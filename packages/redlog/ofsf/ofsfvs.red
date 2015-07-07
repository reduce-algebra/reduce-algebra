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

fluid '(rlvarsellvl!* rldegbound!*);
rlvarsellvl!* := 1;
rldegbound!* := 3;

%%% data types %%%

struct Position checked by PositionP;  % position in formula

struct VSsu checked by VSsuP;  % VS
struct VSvs checked by VSvsP;  % VS: test point substitution
struct VSdg checked by VSdgP;  % VS: degree shift
struct VSar checked by VSarP;  % VS: arbitrary
struct VStp checked by VStpP;  % test point
struct VSnd checked by VSndP;  % QE tree node
struct VSco checked by VScoP;  % container of nodes
struct VSht checked by VShtP;  % hash table of quantifier-free formulas
struct VSdb checked by VSdbP;  % VS data for a block
struct VSde checked by VSdeP;  % VS data for elimination set computation
struct VSdt checked by VSdtP;  % VS data for formula traversal

struct VStpL checked by VStpLP;  % list of VStp
struct VSndL checked by VSndLP;  % list of VSnd
struct VSdtL checked by VSdtLP;  % list of VSdt

%%% checking procedures %%%

procedure PositionP(s);  % position in formula
   null s or (pairp s and fixp car s and PositionP cdr s);

procedure VSsuP(s);  % VS
   VSarP s or VSdgP s or VSvsP s;

procedure VSvsP(s);  % VS: test point substitution
   pairp s and car s eq 'vsvs;

procedure VSdgP(s);  % VS: degree shift
   pairp s and car s eq 'vsdg;

procedure VSarP(s);  % VS: arbitrary
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

procedure VSdbP(s);  % VS data for a block
   vectorp s and getv(s, 0) eq 'vsdb;

procedure VSdeP(s);  % VS data for elimination set computation
   vectorp s and getv(s, 0) eq 'vsde;

procedure VSdtP(s);  % VS data for formula traversal
   vectorp s and getv(s, 0) eq 'vsdt;

procedure VStpLP(s);
   null s or (pairp s and VStpP car s and VStpLP cdr s);

procedure VSndLP(s);
   null s or (pairp s and VSndP car s and VSndLP cdr s);

procedure VSdtLP(s);
   null s or (pairp s and VSdtP car s and VSdtLP cdr s);

%%% VS %%%

asserted procedure vssu_vpp(vs: VSsu): Boolean;
   % VS test point substitution predicate.
   pairp vs and car vs eq 'vsvs;

asserted procedure vssu_dgp(vs: VSsu): Boolean;
   % VS degree shift predicate.
   pairp vs and car vs eq 'vsdg;

asserted procedure vssu_arp(vs: VSsu): Boolean;
   % VS arbitrary predicate.
   pairp vs and car vs eq 'vsar;

asserted procedure vsvs_mk(v: Kernel, tp: VStp): VSsu;
   % VS test point substitution make.
   {'vsvs, v, tp};

asserted procedure vsvs_v(vs: VSvs): Kernel;
   % VS test point substitution variable.
   nth(vs, 2);

asserted procedure vsvs_tp(vs: VSvs): VStp;
   % VS test point substitution test point.
   nth(vs, 3);

asserted procedure vsdg_mk(v: Kernel, g: Integer, sv: Kernel): VSsu;
   % VS degree shift make.
   {'vsdg, v, g, sv};

asserted procedure vsdg_v(vs: VSdg): Kernel;
   % VS degree shift variable.
   nth(vs, 2);

asserted procedure vsdg_g(vs: VSdg): Integer;
   % VS degree shift gcd.
   nth(vs, 3);

asserted procedure vsdg_sv(vs: VSdg): Kernel;
   % VS degree shift shadow variable.
   nth(vs, 4);

asserted procedure vsar_mk(v: Kernel): VSsu;
   % VS arbitrary make.
   {'vsar, v};

asserted procedure vsar_v(vs: VSar): Kernel;
   % VS arbitrary variable.
   nth(vs, 2);

%%% QE tree node %%%

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
   % Todo predicate. Checks whether the working nodes container is
   % empty.
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

%%% VS data for elimination set computation %%%

asserted procedure vsde_new(): VSde;
   % VS data for elimination set computation new.
   begin scalar de;
      de := mkvect(6);
      putv(de, 0, 'vsde);
      putv(de, 1, 'undefined);        % [var]: variable to compute elimset for
      putv(de, 2, 'undefined);        % [f]: quantifier-free formula
      putv(de, 3, 'undefined);        % [curtheo]: current background theory
      putv(de, 4, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(de, 5, 'undefined);        % [apcl]: list of atomic prime constituents
      putv(de, 6, 'undefined);        % [tpl]: list of test points
      return de
   end;

procedure vsde_var(de);                         getv(de, 1);
procedure vsde_f(de);                           getv(de, 2);
procedure vsde_curtheo(de);                     getv(de, 3);
procedure vsde_bvl(de);                         getv(de, 4);
procedure vsde_apcl(de);                        getv(de, 5);
procedure vsde_tpl(de);                         getv(de, 6);

procedure vsde_putvar(de, var);                 putv(de, 1, var);
procedure vsde_putf(de, f);                     putv(de, 2, f);
procedure vsde_putcurtheo(de, theo);            putv(de, 3, theo);
procedure vsde_putbvl(de, bvl);                 putv(de, 4, bvl);
procedure vsde_putapcl(de, apcl);               putv(de, 5, apcl);
procedure vsde_puttpl(de, tpl);                 putv(de, 6, tpl);

asserted procedure vsde_mk(var: Kernel, f: QfFormula, theo: Theory, bvl: KernelL): VSde;
   begin scalar de;
      de := vsde_new();
      vsde_putvar(de, var);
      vsde_putf(de, f);
      vsde_putcurtheo(de, theo);
      vsde_putbvl(de, bvl);
      vsde_putapcl(de, nil);
      vsde_puttpl(de, nil);
      return de
   end;

asserted procedure vsdt_new(): VSdt;
   % VS data for formula traversal new.
   begin scalar dt;
      dt := mkvect(6);
      putv(dt, 0, 'vsdt);
      putv(dt, 1, 'undefined);        % [var]: variable
      putv(dt, 2, 'undefined);        % [f]: quantifier-free formula
      putv(dt, 3, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(dt, 4, 'undefined);        % [ptheo]: persistent theory
      putv(dt, 5, 'undefined);        % [ttheo]: temporary theory
      putv(dt, 6, 'undefined);        % [data]: list of collected data
      return dt
   end;

%DS
% CollectedData ::= (Position, list of ParamRoot, persistent theory supplement)

procedure vsdt_var(dt);                         getv(dt, 1);
procedure vsdt_f(dt);                           getv(dt, 2);
procedure vsdt_bvl(dt);                         getv(dt, 3);
procedure vsdt_ptheo(dt);                       getv(dt, 4);
procedure vsdt_ttheo(dt);                       getv(dt, 5);
procedure vsdt_data(dt);                        getv(dt, 6);

procedure vsdt_putvar(dt, var);                 putv(dt, 1, var);
procedure vsdt_putf(dt, f);                     putv(dt, 2, f);
procedure vsdt_putbvl(dt, bvl);                 putv(dt, 3, bvl);
procedure vsdt_putptheo(dt, ptheo);             putv(dt, 4, ptheo);
procedure vsdt_putttheo(dt, ttheo);             putv(dt, 5, ttheo);
procedure vsdt_putdata(dt, data);               putv(dt, 6, data);

asserted procedure vsdt_mk(var: Kernel, f: QfFormula, bvl: KernelL, ptheo: Theory, ttheo: Theory): VSdt;
   begin scalar dt;
      dt := vsdt_new();
      vsdt_putvar(dt, var);
      vsdt_putf(dt, f);
      vsdt_putbvl(dt, bvl);
      vsdt_putptheo(dt, ptheo);
      vsdt_putttheo(dt, ttheo);
      vsdt_putdata(dt, nil);
      return dt
   end;

asserted procedure vsdt_mkfrom(dt: VSdt): VSdt;
   begin scalar ndt;
      ndt := vsdt_new();
      vsdt_putvar(ndt, vsdt_var dt);
      vsdt_putf(ndt, vsdt_f dt);
      vsdt_putbvl(ndt, vsdt_bvl dt);
      vsdt_putptheo(ndt, vsdt_ptheo dt);
      vsdt_putttheo(ndt, vsdt_ttheo dt);
      vsdt_putdata(ndt, vsdt_data dt);
      return ndt
   end;

asserted procedure vsdt_ptheoinsert(dt: VSdt, f: QfFormula);
   vsdt_putptheo(dt, f . vsdt_ptheo dt);

asserted procedure vsdt_ttheoinsert(dt: VSdt, f: QfFormula);
   vsdt_putttheo(dt, f . vsdt_ttheo dt);

%%% "real" procedures %%%

asserted procedure vssu_apply(vs: VSsu, f: QfFormula): QfFormula;
   % VS apply.
   if vssu_vpp vs then
      vsvs_apply(vs, f)
   else if vssu_dgp vs then
      vsdg_apply(vs, f)
   else if vssu_arp vs then
      vsar_apply(vs, f);

asserted procedure vsvs_apply(vs: VSvs, f: QfFormula): QfFormula;
   % VS test point substitution apply.
   % TEMPORARY! Using old code to have something runnable.
   begin scalar v, tp;
      v := vsvs_v vs;
      tp := vsvs_tp vs;
      return cdr apply(car tp, nil . nil . f . v . cdr tp)
   end;

asserted procedure vsdg_apply(vs: VSdg, f: QfFormula): QfFormula;
   % VS degree shift apply.
   begin
      f := cl_apply2ats1(f, 'vsdg_decdeg, {vsdg_v vs, vsdg_g vs, vsdg_sv vs});
      if not evenp vsdg_g vs then
	 return f;
      return rl_mk2('and, ofsf_0mk2('geq, vsdg_sv vs), f)
   end;

asserted procedure vsdg_decdeg(at: QfFormula, v: Kernel, g: Integer, sv: Kernel): QfFormula;
   % Decrement degree of atomic formula. Replace each occurence of
   % [v^n] by [sv^(n/g)].
   begin scalar f;
      % assert(at is atomic);
      f := rl_arg2l at;
      f := sfto_decdegf(f, v, g);
      return ofsf_0mk2(rl_op at, sfto_renamef(f, v, sv))
   end;

asserted procedure vsar_apply(vs: VSar, f: QfFormula): QfFormula;
   % VS arbitrary apply. Mathematically, it should be never needed to
   % apply this VS.
   <<
      assert(nil);
      f
   >>;

asserted procedure vsdb_expandNode(db: VSdb, nd: VSnd);
   % Expand node. No meaningful return value. [db] is modified in
   % place so that [nd] is properly expanded at the end of the
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

asserted procedure vsde_compute(de: VSde);
   % Compute elimination set.
   % TEMPORARY! Using old code to obtain something runnable.
   begin scalar alp, w, ww;
      alp := cl_qeatal(vsde_f de, vsde_var de, nil, nil);
      w := ofsf_elimset(vsde_var de, alp);
      ww := for each hu in w join
	 for each huhu in cdr hu collect
	    car hu . huhu;
      vsde_puttpl(de, ww)
   end;

asserted procedure vsdt_gaussposl(dt: VSdt, p: Position);
   % Compute positions of all Gauss prime constituents. [p] is the
   % position of [vsdt_f dt]. Positions are reversed, i.e., the last
   % entry in the list is the index of a child of the root. Positions
   % of all Gauss prime constituent are stored as a list in [vsdt_data
   % dt].
   begin scalar op, cl, c, cdt, cdtl, pcl; integer i;
      op := rl_op vsdt_f dt;
      if not rl_boolp op then <<
	 vsdt_gaussposl!-at(dt, p);
	 return
      >>;
      assert(op eq 'and or op eq 'or);
      cl := rl_argn vsdt_f dt;
      while cl do <<
	 c := pop cl;
	 i := i + 1;
	 cdt := vsdt_mkfrom dt;
	 vsdt_putf(cdt, c);
	 vsdt_add2ttheo(cdt, append(pcl, cl), op eq 'or);
	 vsdt_gaussposl(cdt, i . p);
	 push(cdt, cdtl);
	 push(c, pcl)
      >>;
      if op eq 'and then
	 vsdt_gaussposl!-gand(dt, p, reversip cdtl);
      if op eq 'or then
	 vsdt_gaussposl!-gor(dt, p, reversip cdtl)
   end;

asserted procedure vsdt_gaussposl!-at(dt: VSdt, p: Position);
   % Compute positions of all Gauss prime constituents in atomic
   % formula. [p] is the position of atomic formula [vsdt_f dt].
   begin scalar atf, op, lhs, data;
      atf := vsdt_f dt;
      op := rl_op atf;
      lhs := rl_arg2l atf;
      if op eq 'equal and not domainp lhs and ldeg lhs <= rldegbound!* then  % position [p] is Gauss
	 data := {{p, 'roots!-from . p, nil}};
      vsdt_putdata(dt, data)
   end;

asserted procedure vsdt_cogaussposl(dt: VSdt, p: Position);
   % Compute positions of all co-Gauss prime constituents. [p] is the
   % position of [vsdt_f dt]. Positions are reversed, i.e., the last
   % entry in the list is the index of a child of the root. Position
   % of all co-Gauss prime constituents are stored in [vsdt_data dt].
   begin scalar op, cl, c, cdt, cdtl, pcl; integer i;
      op := rl_op vsdt_f dt;
      if not rl_boolp op then <<
	 vsdt_cogaussposl!-at(dt, p);
	 return
      >>;
      assert(op eq 'and or op eq 'or);
      cl := rl_argn vsdt_f dt;
      while cl do <<
	 c := pop cl;
	 i := i + 1;
	 cdt := vsdt_mkfrom dt;
	 vsdt_putf(cdt, c);
	 vsdt_add2ttheo(cdt, append(pcl, cl), op eq 'or);
	 vsdt_cogaussposl(cdt, i . p);
	 push(cdt, cdtl);
	 push(c, pcl)
      >>;
      if op eq 'and then
	 vsdt_gaussposl!-gor(dt, p, reversip cdtl);
      if op eq 'or then
	 vsdt_gaussposl!-gand(dt, p, reversip cdtl)
   end;

asserted procedure vsdt_cogaussposl!-at(dt: VSdt, p: Position);
   % Compute positions of all co-Gauss prime constituents in atomic
   % formula. [p] is the position of atomic formula [vsdt_f dt].
   begin scalar atf, op, lhs, data;
      atf := vsdt_f dt;
      op := rl_op atf;
      lhs := rl_arg2l atf;
      if op eq 'neq and not domainp lhs and ldeg lhs <= rldegbound!* then  % position [p] is co-Gauss
	 data := {{p, 'roots!-from . p, nil}};
      vsdt_putdata(dt, data)
   end;

asserted procedure vsdt_gaussposl!-gand(dt: VSdt, p: Position, cdtl: VSdtL);
   % Compute positions of all (co)-Gauss prime constituents:
   % generalized and subroutine. [p] is the position of [vsdt_f dt].
   % [cdtl] are VSdt for all children of [p] with pre-computed data.
   % This procedure merges these to obtain the list of all (co)-Gauss
   % prime constituents in formula [vsdt_f dt] at position [p].
   begin scalar cdata, cdtgl, bcdt, data; integer i;
      for each cdt in cdtl do <<
	 i := i + 1;
      	 cdata := vsdt_data cdt;
      	 if cdata and nth(car cdata, 1) = (i . p) then  % position [i . p] is (co)-Gauss
	    push(cdt, cdtgl)
      >>;
      if cdtgl then <<  % position [p] is (co)-Gauss
	 bcdt := vsdt_gaussposl!-bestcdt(dt, p, reversip cdtgl);
	 cdata := vsdt_data bcdt;
	 data := {p, nth(car cdata, 2), nth(car cdata, 3)}
      >> else  % position [p] is not (co)-Gauss
	 for each cdt in cdtl do
	    data := vsdt_mergedata(data, vsdt_data cdt);
      vsdt_putdata(dt, data)
   end;

asserted procedure vsdt_gaussposl!-gor(dt: VSdt, p: Position, cdtl: VSdtL);
   % Compute positions of all (co)-Gauss prime constituents:
   % generalized or subroutine. [p] is the position of [vsdt_f dt].
   % [cdtl] are VSdt for all children of [p] with pre-computed data.
   % This procedure merges these to obtain the list of all (co)-Gauss
   % prime constituents in formula [vsdt_f dt] at position [p].
   begin scalar g, cdata, data, prl, ptl; integer i;
      g := t;
      for each cdt in cdtl do <<
	 i := i + 1;
	 cdata := vsdt_data cdt;
	 if null cdata or not (nth(car cdata, 1) = (i . p)) then  % position [i . p] is not (co)-Gauss
	    g := nil;
	 data := vsdt_mergedata(data, cdata)
      >>;
      if g then <<  % position [p] is (co)-Gauss
	 for each dt in data do <<
	    prl := append(prl, nth(dt, 2));
	    ptl := append(ptl, nth(dt, 3))
	 >>;
	 data := {p, prl, ptl}
      >>;
      vsdt_putdata(dt, data)
   end;

asserted procedure vsdt_gaussposl!-bestcdt(dt: VSdt, p: Position, cdtgl: VSdtL): VSdt;
   % Select the best child from children list [cdtgl].
   car cdtgl;

asserted procedure vsdt_add2ttheo(dt: VSdt, fl: QfFormulaL, neg: Boolean);
   % Add to temporary theory. Some formulas from [fl] are added to
   % [vsdt_ttheo dt]. If [neg] is [t], then the formulas are negated
   % before adding them to [vsdt_ttheo dt]. The current criterion:
   % Atomic formulas not containing the variable [vsdt_var dt].
   for each f in fl do
      % TODO: Write and use qff_atp f.
      if (not rl_boolp rl_op f) and not (vsdt_var dt memq cl_fvarl f) then
	 vsdt_ttheoinsert(dt, if neg then rl_negateat f else f);

asserted procedure vsdt_mergedata(data1: List, data2: List): List;
   % Merge CollectedData.
   append(data1, data2);

asserted procedure vs_block(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % TODO: Update this old procedure description.
   % Quantifier elimination for one block subroutine. The result
   % contains the list of variables for which elimination failed, the
   % (possibly partial) possibly negated elimination result as a
   % JunctionL, and the new theory.
   begin scalar db;
      db := vsdb_mk(varl, f, theo, bvl, ans);
      vs_mainloop db;
      ioto_prin2t nil;
      vsdb_printSummary db;
      return {varl, {f . nil}, theo}
   end;

asserted procedure vs_mainloop(db: VSdb);
   % Quantifier elimination for one block subroutine. This procedure
   % realizes the main loop of QE for a single block of quantifiers.
   % No meaningful return value. [db] is modified in-place.
   begin scalar nd, varl, f, su, mbr;
      while vsdb_todop db do <<
	 nd := vsdb_wcget db;
	 varl := vsnd_varl nd;
	 f := vsnd_f nd;
	 su := vsnd_su nd;
	 if vsnd_flg nd then  % substitution has not been done yet
	    for each ff in vs_splitor vssu_apply(su, f) do
	       vsdb_wcinsert(db,
		  vsnd_mk(nil, su, varl, ff, vsnd_parent nd))
	 else <<  % substitution was already done
	    mbr := vsdb_htmember(db, f);
	    if not mbr or vssu_arp su then <<
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

asserted procedure vsdt_printSummary(dt: VSdt);
   <<
      ioto_prin2 {"VSdt with ttheo:"};
      for each f in vsdt_ttheo dt do
      	 mathprint rl_prepfof f
      % ioto_prin2 {"VSdt: "};
      % ioto_prin2t {"f: ", vsdt_f dt,
      % 	 " #ptheo: ", length vsdt_ptheo dt,
      % 	 " #ttheo: ", length vsdt_ttheo dt,
      % 	 " data: ", vsdt_data dt}
   >>;

endmodule;  % ofsfvs

end;  % of file
