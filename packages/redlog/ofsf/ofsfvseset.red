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
   fluid '(ofsfvseset_rcsid!* ofsfvseset_copyright!*);
   ofsfvseset_rcsid!* :=
      "$Id$";
   ofsfvseset_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvseset;

fluid '(rlbndswithilp!*);
rlbndswithilp!* := nil;

%%% parametric root description %%%
% constructors and access functions

asserted procedure vspr_mk(f: SF, x: Kernel, rsl: List, rc: QfFormula): VSpr;
   % Parametric root description make. If [f] is [nil], then [x] is
   % [nil]. Otherwise [x] is [mvar f]; [rsl] is a list of root
   % specifications, whereas a root specification is a pair [(real
   % type code . index)], where [type] is a real type and [index] is a
   % root index; [rc] is a relevance condition (not containing [x])
   % under which it is needed to substitute this parametric root
   % description. It will be conjuncted with the guard.
   {'vspr, f, x, rsl, rc};

asserted procedure vspr_f(pr: VSpr): SF;
   % Parametric root description polynomial.
   nth(pr, 2);

asserted procedure vspr_v(pr: VSpr): SF;
   % Parametric root description variable.
   nth(pr, 3);

asserted procedure vspr_rsl(pr: VSpr): AList;
   % Parametric root description root specification list.
   nth(pr, 4);

asserted procedure vspr_rc(pr: VSpr): QfFormula;
   % Parametric root description relevance condition.
   nth(pr, 5);

asserted procedure vspr_d(pr: VSpr): Integer;
   % Parametric root description degree.
   begin scalar f;
      f := vspr_f pr;
      if f then
	 return ldeg f;
      return 0
   end;

asserted procedure vspr_rtl(pr: VSpr): List;
   % Parametric root description root type list.
   begin scalar rtl;
      rtl := for each rs in vspr_rsl pr collect
	 car rs;
      % TODO: There could be duplicates in [rtl] in the future. Then
      % you will have to delete them here!
      return sort(rtl, function(lambda(a, b); a < b))
   end;

asserted procedure vspr_reorder(pr: VSpr): VSpr;
   % Parametric root description reorder.
   vspr_mk(reorder vspr_f pr, vspr_v pr, vspr_rsl pr, vspr_rc pr);

asserted procedure vspr_guard(pr: VSpr): QfFormula;
   % Parametric root description guard.
   if vspr_rc pr eq 'true then
      vsub_guard pr
   else
      rl_mk2('and, vsub_guard pr, vspr_rc pr);

%%% prime constituent (PC) %%%
% constructors and access functions

asserted procedure vspc_mk(p: Position, type: Id, cs: VScs, gpl: PositionL, b: List): VSpc;
   % Prime constituent make. [p] is the position of the PC, [type] is
   % one of ['(gauss cogauss at)]; [cs] are candidate solutions; [gpl]
   % are positions of Gauss prime constituents; [b] is bound choice
   {'vspc, p, type, cs, gpl, b};

asserted procedure vspc_p(pc: VSpc): Position;
   % Prime constituent position.
   nth(pc, 2);

asserted procedure vspc_type(pc: VSpc): Id;
   %  Prime constituent type.
   nth(pc, 3);

asserted procedure vspc_cs(pc: VSpc): VScs;
   %  Prime constituent candidate solutions.
   nth(pc, 4);

asserted procedure vspc_gpl(pc: VSpc): PositionL;
   % Prime constituent Gauss position list.
   nth(pc, 5);

asserted procedure vspc_b(pc: VSpc): List;
   %  Prime constituent bound choice.
   nth(pc, 6);

%%% candidate solutions %%%
% constructors and access functions

% VScs data structure is analogous to the ALP data structure.

%DS
% keys in [bal] are:
% ip: isolated point
% ep: excluded point
% slb: strict lower bound
% wlb: weak lower bound
% sub: strict upper bound
% wub: weak upper bound

asserted procedure vscs_mk(ts: Theory, s: Any): VScs;
   % Candidate solutions make. [ts] is theory supplement; [s] is
   % either ['failed] or an AList. The keys in [s] are from ['(ip ep
   % slb wlb sub wub)], values are lists of parametric root
   % descriptions.
   ts . s;

asserted procedure vscs_failedp(cs: VScs): Boolean;
   % Candidate solutions failed predicate.
   cdr cs eq 'failed;

asserted procedure vscs_ts(cs: VScs): Theory;
   % Candidate solutions theory supplement.
   car cs;

asserted procedure vscs_ip(cs: VScs): VSprL;
   % Candidate solutions isolated points.
   begin scalar w;
      w := atsoc('ip, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_ep(cs: VScs): VSprL;
   % Candidate solutions excluded points.
   begin scalar w;
      w := atsoc('ep, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_slb(cs: VScs): VSprL;
   % Candidate solutions strict lower bounds.
   begin scalar w;
      w := atsoc('slb, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_wlb(cs: VScs): VSprL;
   % Candidate solutions weak lower bounds.
   begin scalar w;
      w := atsoc('wlb, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_sub(cs: VScs): VSprL;
   % Candidate solutions strict upper bounds.
   begin scalar w;
      w := atsoc('sub, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_wub(cs: VScs): VSprL;
   % Candidate solutions weak upper bounds.
   begin scalar w;
      w := atsoc('wub, cdr cs);
      if w then
	 return cdr w;
      return nil
   end;

asserted procedure vscs_nip(cs: VScs): Integer;
   % Candidate solutions number of isolated points.
   length vscs_ip cs;

asserted procedure vscs_nep(cs: VScs): Integer;
   % Candidate solutions number of excluded points.
   length vscs_ep cs;

asserted procedure vscs_nslb(cs: VScs): Integer;
   % Candidate solutions number of strict lower bounds.
   length vscs_slb cs;

asserted procedure vscs_nwlb(cs: VScs): Integer;
   % Candidate solutions number of weak lower bounds.
   length vscs_wlb cs;

asserted procedure vscs_nsub(cs: VScs): Integer;
   % Candidate solutions number of strict upper bounds.
   length vscs_sub cs;

asserted procedure vscs_nwub(cs: VScs): Integer;
   % Candidate solutions number of weak upper bounds.
   length vscs_wub cs;

asserted procedure vscs_merge(c1: VScs, c2: VScs): VScs;
   % Candidate solutions merge.
   begin scalar theo, al, w1, w2;
      if vscs_failedp c1 then
	 return c1;
      if vscs_failedp c2 then
	 return c2;
      theo := append(car c1, car c2);
      al := for each k in '(ip ep slb wlb sub wub) join <<
	 w1 := atsoc(k, cdr c1);
	 w2 := atsoc(k, cdr c2);
	 w1 := if w1 then cdr w1;
	 w2 := if w2 then cdr w2;
	 if w1 or w2 then
	    {k . append(w1, w2)}
	 else
	    nil
      >>;
      return theo . al
   end;

%%% test point %%%
% constructors and access functions

asserted procedure vstp_mk(p: Position, gpl: PositionL, np: Id, pr: VSpr): VStp;
   % Test point make. [p] is the position of the prime constituent
   % that generated this test point; [gpl] is a list of positions of
   % Gauss prime constituents; [np] is nonstandard part, it is one of
   % ['(nil minf pinf meps peps)]; [pr] is a parametric root
   % description.
   {'vstp, p, gpl, np, pr};

asserted procedure vstp_p(tp: VStp): Position;
   % Test point position.
   nth(tp, 2);

asserted procedure vstp_gpl(tp: VStp): PositionL;
   % Test point Gauss position list.
   nth(tp, 3);

asserted procedure vstp_np(tp: VStp): Id;
   % Test point nonstandard part.
   nth(tp, 4);

asserted procedure vstp_pr(tp: VStp): VSpr;
   % Test point parametric root description.
   nth(tp, 5);

asserted procedure vstp_reorder(tp: VStp): VStp;
   % Test point reorder.
   if vstp_np tp memq '(minf pinf) then
      tp
   else
      {'vstp, vstp_p tp, vstp_gpl tp, vstp_np tp, vspr_reorder vstp_pr tp};

% THE FOLLOWING PROCEDURE IS TEMPORARY! It uses old code to have something runnable.
% asserted procedure vstp_reorder(tp: VStp): VStp;
%    tp;

asserted procedure vstp_guard(tp: VStp): QfFormula;
   % Test point guard.
   if vstp_np tp memq '(minf pinf) then
      'true
   else
      vspr_guard vstp_pr tp;

%%% VS data for elimination set computation %%%
% constructors and access functions

asserted procedure vsde_new(): VSde;
   % VS data for elimination set computation new.
   begin scalar de;
      de := mkvect(6);
      putv(de, 0, 'vsde);
      putv(de, 1, 'undefined);        % [v]: variable to compute elimset for
      putv(de, 2, 'undefined);        % [f]: quantifier-free formula
      putv(de, 3, 'undefined);        % [curtheo]: current background theory
      putv(de, 4, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(de, 5, 'undefined);        % [pcl]: list of prime constituents
      putv(de, 6, 'undefined);        % [tpl]: list of test points
      return de
   end;

procedure vsde_v(de);                           getv(de, 1);
procedure vsde_f(de);                           getv(de, 2);
procedure vsde_curtheo(de);                     getv(de, 3);
procedure vsde_bvl(de);                         getv(de, 4);
procedure vsde_pcl(de);                         getv(de, 5);
procedure vsde_tpl(de);                         getv(de, 6);

procedure vsde_putv(de, x);                     putv(de, 1, x);
procedure vsde_putf(de, f);                     putv(de, 2, f);
procedure vsde_putcurtheo(de, theo);            putv(de, 3, theo);
procedure vsde_putbvl(de, bvl);                 putv(de, 4, bvl);
procedure vsde_putpcl(de, pcl);                 putv(de, 5, pcl);
procedure vsde_puttpl(de, tpl);                 putv(de, 6, tpl);

asserted procedure vsde_mk(var: Kernel, f: QfFormula, theo: Theory, bvl: KernelL): VSde;
   % VS data for elimination set computation make.
   begin scalar de;
      de := vsde_new();
      vsde_putv(de, var);
      vsde_putf(de, f);
      vsde_putcurtheo(de, theo);
      vsde_putbvl(de, bvl);
      vsde_putpcl(de, nil);
      vsde_puttpl(de, nil);
      return de
   end;

%%% VS data for candidate solutions computation %%%
% constructors and access functions

asserted procedure vsdc_new(): VSdc;
   % VS data for candidate solutions computation new.
   begin scalar dc;
      dc := mkvect(6);
      putv(dc, 0, 'vsdc);
      putv(dc, 1, 'undefined);        % [v]: variable
      putv(dc, 2, 'undefined);        % [f]: quantifier-free formula
      putv(dc, 3, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(dc, 4, 'undefined);        % [ptheo]: persistent theory
      putv(dc, 5, 'undefined);        % [ttheo]: temporary theory
      putv(dc, 6, 'undefined);        % [res]: AList of DottedPairs of the form (Position . VScs); resulting candidate solutions
      return dc
   end;

procedure vsdc_v(dc);                           getv(dc, 1);
procedure vsdc_f(dc);                           getv(dc, 2);
procedure vsdc_bvl(dc);                         getv(dc, 3);
procedure vsdc_ptheo(dc);                       getv(dc, 4);
procedure vsdc_ttheo(dc);                       getv(dc, 5);
procedure vsdc_res(dc);                         getv(dc, 6);

procedure vsdc_putv(dc, x);                     putv(dc, 1, x);
procedure vsdc_putf(dc, f);                     putv(dc, 2, f);
procedure vsdc_putbvl(dc, bvl);                 putv(dc, 3, bvl);
procedure vsdc_putptheo(dc, ptheo);             putv(dc, 4, ptheo);
procedure vsdc_putttheo(dc, ttheo);             putv(dc, 5, ttheo);
procedure vsdc_putres(dc, res);                 putv(dc, 6, res);

asserted procedure vsdc_mk(var: Kernel, f: QfFormula, bvl: KernelL, ptheo: Theory, ttheo: Theory): VSdc;
   begin scalar dc;
      dc := vsdc_new();
      vsdc_putv(dc, var);
      vsdc_putf(dc, f);
      vsdc_putbvl(dc, bvl);
      vsdc_putptheo(dc, ptheo);
      vsdc_putttheo(dc, ttheo);
      vsdc_putres(dc, nil);
      return dc
   end;

asserted procedure vsdc_mkfrom(dc: VSdc): VSdc;
   begin scalar ndc;
      ndc := vsdc_new();
      vsdc_putv(ndc, vsdc_v dc);
      vsdc_putf(ndc, vsdc_f dc);
      vsdc_putbvl(ndc, vsdc_bvl dc);
      vsdc_putptheo(ndc, vsdc_ptheo dc);
      vsdc_putttheo(ndc, vsdc_ttheo dc);
      vsdc_putres(ndc, vsdc_res dc);
      return ndc
   end;

asserted procedure vsdc_ptheoinsert(dc: VSdc, f: QfFormula);
   vsdc_putptheo(dc, f . vsdc_ptheo dc);

asserted procedure vsdc_ttheoinsert(dc: VSdc, f: QfFormula);
   vsdc_putttheo(dc, f . vsdc_ttheo dc);

asserted procedure vsdc_add2ttheo(dc: VSdc, fl: QfFormulaL, neg: Boolean);
   % Add to temporary theory. Some formulas from [fl] are added to
   % [vsdc_ttheo dc]. If [neg] is [t], then the formulas are negated
   % before adding them to [vsdc_ttheo dc]. The current criterion:
   % Atomic formulas not containing the variable [vsdc_v dc].
   for each f in fl do
      if (not rl_boolp rl_op f) and
      not rl_tvalp f and
      not (vsdc_v dc memq cl_fvarl f) then
	 vsdc_ttheoinsert(dc, if neg then rl_negateat f else f);

%%% "real" procedures %%%

asserted procedure vsde_compute(de: VSde);
   % This is the usual entry point. Compute an elimination set.
   begin
      vsde_pc!-decomposition de;
      if null vsde_pcl de then <<
	 vsde_puttpl(de, nil);
	 return
      >>;
      vsde_select!-bounds de;
      vsde_pcl2tpl de;
      vsde_conflate!-tpl de
   end;

% THE FOLLOWING PROCEDURE IS TEMPORARY! It uses old code to have something runnable.
% asserted procedure vsde_compute(de: VSde);
%    % Compute an elimination set.
%    begin scalar alp, w, ww;
%       alp := cl_qeatal(vsde_f de, vsde_v de, nil, nil);
%       w := ofsf_elimset(vsde_v de, alp);
%       ww := for each hu in w join
% 	 for each huhu in cdr hu collect
% 	    car hu . huhu;
%       vsde_puttpl(de, ww)
%    end;

%%% prime constitutent decomposition submodule %%%

asserted procedure vsde_pc!-decomposition(de: VSde);
   % Compute a prime constituent decomposition.
   begin scalar f, gl, cgl, atl, gposl, pc, pcl;
      % Replacement with [false] is done here only to mark subformulas
      % that play no role (i.e. we do not need to look into them).
      % Simplification after this replacement would NOT be
      % semantically correct!
      % find Gauss prime constituents
      f := vsde_f de;
      gl := qff_gaussposl(vsde_v de, f, vsde_bvl de, vsde_curtheo de);
      if not vsde_failedalp gl then <<
      	 % TODO: Choose an efficient ordering of [gl].
      	 % TODO: Here is the place for gentle simplification.
      	 f := qff_replacel(f, for each pr in gl collect car pr, 'false)
      >> else
	 % It makes sense to continue in the failed case, because the
	 % subformula causing the failure can become part of a
	 % co-Gauss prime constituent.
	 gl := nil;
      % find co-Gauss prime constituents
      cgl := qff_cogaussposl(vsde_v de, f, vsde_bvl de, vsde_curtheo de);
      if vsde_failedalp cgl then <<
	 vsde_putpcl(de, nil);
	 return
      >>;
      gl := pos_delsubposal(cgl, gl);
      % find atomic prime constituents
      f := qff_replacel(f, for each pr in cgl collect car pr, 'false);
      atl := qff_atposl(vsde_v de, f, vsde_bvl de, vsde_curtheo de);
      if vsde_failedalp atl then <<
	 vsde_putpcl(de, nil);
	 return
      >>;
      for each pr in atl do <<
	 pc := vspc_mk(car pr, 'at, cdr pr, gposl, nil);
	 push(pc, pcl)
      >>;
      for each pr in cgl do <<
	 pc := vspc_mk(car pr, 'cogauss, cdr pr, gposl, nil);
	 push(pc, pcl)
      >>;
      for each pr in gl do <<
	 pc := vspc_mk(car pr, 'gauss, cdr pr, gposl, nil);
	 push(pc, pcl);
	 push(car pr, gposl)
      >>;
      vsde_putpcl(de, pcl)
   end;

asserted procedure vsde_failedalp(al: AList);
   al and null caar al and vscs_failedp cdar al;

asserted procedure qff_gaussposl(var: Kernel, f: QfFormula, bvl: KernelL, theo: Theory): AList;
   % wrapper
   begin scalar gdc;
      gdc := vsdc_mk(var, f, bvl, theo, nil);
      vsdc_gaussposl(gdc, nil);
      return for each pr in vsdc_res gdc collect
	 reverse car pr . cdr pr
   end;

asserted procedure qff_cogaussposl(var: Kernel, f: QfFormula, bvl: KernelL, theo: Theory): AList;
   % wrapper
   begin scalar cgdc;
      cgdc := vsdc_mk(var, f, bvl, theo, nil);
      vsdc_cogaussposl(cgdc, nil);
      return for each pr in vsdc_res cgdc collect
	 reverse car pr . cdr pr
   end;

asserted procedure qff_atposl(var: Kernel, f: QfFormula, bvl: KernelL, theo: Theory): AList;
   % wrapper
   begin scalar atdc;
      atdc := vsdc_mk(var, f, bvl, theo, nil);
      vsdc_atposl(atdc, nil);
      return for each pr in vsdc_res atdc collect
	 reverse car pr . cdr pr
   end;

asserted procedure qff_replacel(f: QfFormula, pl: PositionL, rf: QfFormula): QfFormula;
   % Quantifier-free formula replace positions with formula. The
   % positions in [pl] have to be independent, i.e, each pair of
   % positions is a pair of formulas that are not subformulas of each
   % other. Returns the formula [f] with all positions in [pl]
   % replaced with [rf].
   begin scalar op, ncl, poscl; integer n;
      if null pl then
	 return f;
      if pl = {nil} then
	 return rf;
      op := rl_op f;
      assert(op eq 'and or op eq 'or);
      ncl := for each c in rl_argn f collect <<
	 n := n + 1;
	 poscl := for each p in pl join
	    if eqn(car p, n) then
	       {cdr p};
	 qff_replacel(c, poscl, rf)
      >>;
      return rl_mkn(op, ncl)
   end;

asserted procedure vsdc_gaussposl(dc: VSdc, p: Position);
   % Compute positions of all Gauss prime constituents. [p] is the
   % position of [vsdc_f dc]. Positions are reversed, i.e., the last
   % entry in the list is the index of a child of the root. Positions
   % of all Gauss prime constituent are stored as a list in [vsdc_res
   % dc].
   begin scalar op;
      op := rl_op vsdc_f dc;
      if not rl_boolp op then <<
	 vsdc_gaussposl!-at(dc, p);
	 return
      >>;
      assert(op eq 'and or op eq 'or);
      if op eq 'and then
	 vsdc_gaussposl!-and(dc, p);
      if op eq 'or then
	 vsdc_gaussposl!-or(dc, p)
   end;

asserted procedure vsdc_gaussposl!-at(dc: VSdc, p: Position);
   % Compute positions of all Gauss prime constituents: atomic formula
   % subroutine. [p] is the position of atomic formula [vsdc_f dc].
   begin scalar atf, op, lhs, v, cs, theo, w, fml, f; integer m;
      atf := vsdc_f dc;
      if rl_tvalp atf then <<
	 vsdc_putres(dc, nil);
      	 return
      >>;
      op := rl_op atf;
      lhs := rl_arg2l atf;
      v := vsdc_v dc;
      if op eq 'equal and sfto_mvartest(lhs, v) then <<
	 cs := vscs_mk(nil, nil);
	 theo := append(vsdc_ptheo dc, vsdc_ttheo dc);
	 w := fctrf lhs;  % TODO: Save the factorization result.
	 fml := cdr w;
	 while fml and cs do <<
	    f . m := pop fml;
	    if not ofsf_nonvanishp(f, v, theo) then  % position [p] is not Gauss, exit
	       % TODO THEO: In case we reach this position we could
	       % add something to the theory to make the formula
	       % Gauss.
	       cs := nil
	    else if sfto_mvartest(f, v) then
	       cs := vscs_merge(cs, vscs_opf2cs(op, f, v, theo))
	 >>
      >>;
      if cs then
      	 vsdc_putres(dc, {p . cs})
      else
	 vsdc_putres(dc, nil)
   end;

asserted procedure vsdc_gaussposl!-and(dc: VSdc, p: Position);
   % Compute positions of all Gauss prime constituents: and formula
   % subroutine. [p] is the position of [vsdc_f dc]. This procedures
   % recurses and merges the obtained results to obtain the list of
   % all Gauss prime constituents in formula [vsdc_f dc] at position
   % [p].
   begin scalar cl, c, cdc, pcl, cal, cdcgl, cdcl, al; integer i;
      assert(rl_op vsdc_f dc eq 'and);
      cl := rl_argn vsdc_f dc;
      while cl do <<
	 c := pop cl;
	 i := i + 1;
	 cdc := vsdc_mkfrom dc;
	 vsdc_putf(cdc, c);
	 vsdc_add2ttheo(cdc, append(pcl, cl), nil);
	 vsdc_gaussposl(cdc, i . p);
	 cal := vsdc_res cdc;
      	 if cal then
	    if caar cal = (i . p) then  % position [i . p] is Gauss or failed
	       push(cdc, cdcgl)
	    else  % position [i . p] is neither Gauss nor failed
	       push(cdc, cdcl);
	 push(c, pcl)
      >>;
      if cdcgl then <<  % position [p] is Gauss or failed
	 cal := vsdc_res vsdc_gaussposl!-bestcdc(dc, p, reversip cdcgl);
	 al := {p .  cdar cal}
      >> else  % position [p] is neither Gauss nor failed
	 for each cdc in cdcl do
	    al := append(al, vsdc_res cdc);
      vsdc_putres(dc, al)
   end;

asserted procedure vsdc_gaussposl!-or(dc: VSdc, p: Position);
   % Compute positions of all Gauss prime constituents: or formula
   % subroutine. [p] is the position of [vsdc_f dc]. This procedures
   % recurses and merges the obtained results to obtain the list of
   % all Gauss prime constituents in formula [vsdc_f dc] at position
   % [p].
   begin scalar g, cl, fld, c, cdc, pcl, cal, al, cs; integer i;
      assert(rl_op vsdc_f dc eq 'or);
      g := t;
      cl := rl_argn vsdc_f dc;
      while cl and not fld do <<
	 c := pop cl;
	 i := i + 1;
	 cdc := vsdc_mkfrom dc;
	 vsdc_putf(cdc, c);
	 vsdc_add2ttheo(cdc, append(pcl, cl), t);
	 vsdc_gaussposl(cdc, i . p);
	 cal := vsdc_res cdc;
	 if null cal or not (caar cal = (i . p)) then  % position [i . p] is not Gauss
	    g := nil
	 else if vscs_failedp cdar cal then  % position [i . p] is failed
	    fld := t;
	 al := append(al, cal);
	 push(c, pcl);
      >>;
      if fld then <<
	 vsdc_putres(dc, {p . vscs_mk(nil, 'failed)});
	 return
      >>;
      if g then <<  % position [p] is Gauss
	 cs := vscs_mk(nil, nil);
	 for each e in al do
	    cs := vscs_merge(cs, cdr e);
	 al := {p . cs}
      >>;
      vsdc_putres(dc, al)
   end;

asserted procedure vsdc_gaussposl!-bestcdc(dc: VSdc, p: Position, cdcgl: VSdcL): VSdc;
   % Select the best child from children list [cdcgl].
   begin scalar fld, w;
      fld := t;
      while fld and cdcgl do <<
	 w := pop cdcgl;
	 if not vscs_failedp cdar vsdc_res w then
	    fld := nil;
      >>;
      return w
   end;

asserted procedure vsdc_cogaussposl(dc: VSdc, p: Position);
   % Compute positions of all co-Gauss prime constituents. [p] is the
   % position of [vsdc_f dc]. Positions are reversed, i.e., the last
   % entry in the list is the index of a child of the root. Positions
   % of all co-Gauss prime constituents are stored in [vsdc_res dc].
   begin scalar op;
      op := rl_op vsdc_f dc;
      if not rl_boolp op then <<
	 vsdc_cogaussposl!-at(dc, p);
	 return
      >>;
      assert(op eq 'and or op eq 'or);
      if op eq 'and then
	 vsdc_cogaussposl!-and(dc, p);
      if op eq 'or then
	 vsdc_cogaussposl!-or(dc, p)
   end;

asserted procedure vsdc_cogaussposl!-at(dc: VSdc, p: Position);
   % Compute positions of all co-Gauss prime constituents: atomic
   % formula subroutine. [p] is the position of atomic formula [vsdc_f
   % dc].
   begin scalar atf, op, lhs, v, cs, theo, w, fml, f; integer m;
      atf := vsdc_f dc;
      if rl_tvalp atf then <<
	 vsdc_putres(dc, nil);
	 return
      >>;
      op := rl_op atf;
      lhs := rl_arg2l atf;
      v := vsdc_v dc;
      if op eq 'neq and sfto_mvartest(lhs, v) then <<
	 cs := vscs_mk(nil, nil);
	 theo := append(vsdc_ptheo dc, vsdc_ttheo dc);
	 w := fctrf lhs;  % TODO: Save the factorization result.
	 fml := cdr w;
	 while fml and cs do <<
	    f . m := pop fml;
	    if not ofsf_nonvanishp(f, v, theo) then  % position [p] is not co-Gauss, exit
	       % TODO THEO: In case we reach this position we could
	       % add something to the theory to make the formula
	       % co-Gauss.
	       cs := nil
	    else if sfto_mvartest(f, v) then
	       cs := vscs_merge(cs, vscs_opf2cs(op, f, v, theo))
	 >>
      >>;
      if cs then
      	 vsdc_putres(dc, {p . cs})
      else
	 vsdc_putres(dc, nil)
   end;

asserted procedure vsdc_cogaussposl!-and(dc: VSdc, p: Position);
   % Compute positions of all co-Gauss prime constituents: and formula
   % subroutine. [p] is the position of [vsdc_f dc]. This procedures
   % recurses and merges the obtained results to obtain the list of
   % all co-Gauss prime constituents in formula [vsdc_f dc] at
   % position [p].
   begin scalar g, cl, fld, c, cdc, pcl, cal, al, cs; integer i;
      assert(rl_op vsdc_f dc eq 'and);
      g := t;
      cl := rl_argn vsdc_f dc;
      while cl do <<
	 c := pop cl;
	 i := i + 1;
	 cdc := vsdc_mkfrom dc;
	 vsdc_putf(cdc, c);
	 vsdc_add2ttheo(cdc, append(pcl, cl), nil);
	 vsdc_cogaussposl(cdc, i . p);
	 cal := vsdc_res cdc;
	 if null cal or not (caar cal = (i . p)) then  % position [i . p] is not Gauss
	    g := nil
	 else if vscs_failedp cdar cal then  % position [i . p] is failed
	    fld := t;
	 al := append(al, cal);
	 push(c, pcl)
      >>;
      if fld then <<
	 vsdc_putres(dc, {p . vscs_mk(nil, 'failed)});
	 return
      >>;
      if g then <<  % position [p] is co-Gauss
	 cs := vscs_mk(nil, nil);
	 for each e in al do
	    cs := vscs_merge(cs, cdr e);
	 al := {p . cs}
      >>;
      vsdc_putres(dc, al)
   end;

asserted procedure vsdc_cogaussposl!-or(dc: VSdc, p: Position);
   % Compute positions of all co-Gauss prime constituents: or formula
   % subroutine. [p] is the position of [vsdc_f dc]. This procedures
   % recurses and merges the obtained results to obtain the list of
   % all co-Gauss prime constituents in formula [vsdc_f dc] at
   % position [p].
   begin scalar cl, c, cdc, pcl, cal, cdcgl, cdcl, al; integer i;
      assert(rl_op vsdc_f dc eq 'or);
      cl := rl_argn vsdc_f dc;
      while cl do <<
	 c := pop cl;
	 i := i + 1;
	 cdc := vsdc_mkfrom dc;
	 vsdc_putf(cdc, c);
	 vsdc_add2ttheo(cdc, append(pcl, cl), t);
	 vsdc_cogaussposl(cdc, i . p);
	 cal := vsdc_res cdc;
      	 if cal then
	    if caar cal = (i . p) then  % position [i . p] is co-Gauss or failed
	       push(cdc, cdcgl)
	    else  % position [i . p] is neither co-Gauss nor failed
	       push(cdc, cdcl);
	 push(c, pcl)
      >>;
      if cdcgl then <<  % position [p] is co-Gauss or failed
	 cal := vsdc_res vsdc_cogaussposl!-bestcdc(dc, p, reversip cdcgl);
	 al := {p .  cdar cal}
      >> else  % position [p] is neither co-Gauss nor failed
	 for each cdc in cdcl do
	    al := append(al, vsdc_res cdc);
      vsdc_putres(dc, al)
   end;

asserted procedure vsdc_cogaussposl!-bestcdc(dc: VSdc, p: Position, cdcgl: VSdcL): VSdc;
   % Select the best child from children list [cdcgl].
   begin scalar fld, w;
      fld := t;
      while fld and cdcgl do <<
	 w := pop cdcgl;
	 if not vscs_failedp cdar vsdc_res w then
	    fld := nil;
      >>;
      return w
   end;

asserted procedure vsdc_atposl(dc: VSdc, p: Position);
   % Compute positions of all atomic prime constituents. [p] is the
   % position of [vsdc_f dc]. Positions are reversed, i.e., the last
   % entry in the list is the index of a child of the root. Positions
   % of all atomic prime constituents are stored in [vsdc_res dc].
   begin scalar op, cl, fld, c, cdc, pcl, cal, al; integer i;
      op := rl_op vsdc_f dc;
      if not rl_boolp op then <<
	 vsdc_atposl!-at(dc, p);
	 return
      >>;
      assert(op eq 'and or op eq 'or);
      cl := rl_argn vsdc_f dc;
      while cl and not fld do <<
	 c := pop cl;
	 i := i + 1;
	 cdc := vsdc_mkfrom dc;
	 vsdc_putf(cdc, c);
	 vsdc_add2ttheo(cdc, append(pcl, cl), op eq 'or);
	 vsdc_atposl(cdc, i . p);
	 cal := vsdc_res cdc;
	 if cal and (caar cal = (i . p)) and vscs_failedp cdar cal then  % position [i . p] is failed
	    fld := t;
	 al := append(al, cal);
	 push(c, pcl)
      >>;
      if fld then <<
	 vsdc_putres(dc, {p . vscs_mk(nil, 'failed)});
	 return
      >>;
      vsdc_putres(dc, al)
   end;

asserted procedure vsdc_atposl!-at(dc: VSdc, p: Position);
   % Compute positions of all atomic prime constituents: atomic
   % formula subroutine. [p] is the position of [vsdc_f dc].
   begin scalar atf, op, lhs, v, theo, w, opfl;
      atf := vsdc_f dc;
      if rl_tvalp atf then <<
	 vsdc_putres(dc, nil);
	 return
      >>;
      op := rl_op atf;
      lhs := rl_arg2l atf;
      v := vsdc_v dc;
      if not sfto_mvartest(lhs, v) then <<
	 vsdc_putres(dc, nil);
	 return
      >>;
      theo := append(vsdc_ptheo dc, vsdc_ttheo dc);
      w := fctrf lhs;  % TODO: Save the factorization result.
      opfl := ofsf_opfml2opfl(op, (car w . 1) . cdr w, v, theo);
      vsdc_putres(dc, {p . vscs_opfl2cs(opfl, v, theo)})
   end;

asserted procedure ofsf_opfml2opfl(op: Id, fml: List, x: Kernel, theo: Theory): List;
   % Ordered field standard form operator and factor multiplicity list
   % to operator factor list. [op] is an operator; [fml] is a list of
   % pairs [f . m], where [f] is a SF and [m] is the multiplicity of
   % [f]; [x] is a Kernel. Returns a list of dotted pairs of the form
   % [op . f], where [f] is a SF and [op] is an operator.
   begin scalar fmxl, fmnxl, s, f, wop, opfl; integer m;
      fmxl . fmnxl := ofsf_sepfac(fml, x);
      assert(fmxl);  % there is at least one irreducible factor containing [x]
      if op memq '(equal neq) then
	 return for each fmx in fmxl collect
	    op . car fmx;
      assert(op memq '(leq geq lessp greaterp));
      if null cdr fmxl then <<
	 % - there is exactly one irreducible factor containing [x]
	 s := ofsf_definite(fmnxl, theo);
	 if s then <<
	    % - the sign of the factors not containing [x] is a non-zero constant
	    % TODO: If the sign of the factors not containing [x] is
	    % not a non-zero constant, then we could multiply them
	    % with f and continue. Investigate this.
	    f . m := car fmxl;
	    op := ofsf_adjustop(op, s);
	    if evenp m then
	       op := if op eq 'greaterp then 'neq else if op eq 'leq then 'equal;
	    return if op then {op . f} else nil
	 >>
      >>;
      while fmxl do <<
	 f . m := pop fmxl;
	 if evenp m then <<
	    wop := if op memq '(leq geq) then 'equal else 'neq;
	    push(wop . f, opfl)
	 >> else <<
	    push(op . f, opfl);
	    push(ofsf_adjustop(op, -1) . f, opfl)
	 >>
      >>;
      return opfl
   end;

asserted procedure vscs_opfl2cs(opfl: List, x: Kernel, theo: Theory): VScs;
   % List of operator and SF to candidate solutions. [opfl] is a List
   % of dotted pairs of the form [op . f], where [op] is an operator
   % and [f] is a SF.
   begin scalar cs, op, f;
      cs := vscs_mk(nil, nil);
      while opfl do <<
	 op . f := pop opfl;
	 cs := vscs_merge(cs, vscs_opf2cs(op, f, x, theo))
      >>;
      return cs
   end;

asserted procedure vscs_opf2cs(op: Id, f: SF, x: Kernel, theo: Theory): VScs;
   % Operator and SF to candidate solutions. [op] is an operator; [f]
   % is a SF. Returns a VScs, which contains parametric root
   % descriptions of [f] that possibly represent ip, ep, slb, wlb,
   % sub, or wub of the satisfying set of the atomic formula [f op 0].
   % Theory [theo] is used to possibly rule out some parametric root
   % descriptions.
   begin scalar lcf, finished, cs, c, cl;
      % This procedure uses locally equational theory as follows: If
      % [lc f = 0] follows from [theo], then [f] is not considered. If
      % [lc f <> 0] follows from [theo], then [red f] is not
      % considered. If [lc f <> 0] does not follow from [theo], then
      % we add [lc f = 0] to [theo], and consider [red f]. Equations
      % added in this way to the theory are also used as relevance
      % conditions of parametric root descriptions created here.
      assert(sfto_mvartest(f, x));
      cs := vscs_mk(nil, nil);
      repeat <<
      	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('greaterp, lcf), theo) then <<
	       finished := t;
      	       cs := vscs_merge(cs, vscs_opf2csnz(op, f, x, 1, cl))
	    >> else if ofsf_surep(ofsf_0mk2('lessp, lcf), theo) then <<
	       finished := t;
      	       cs := vscs_merge(cs, vscs_opf2csnz(op, f, x, -1, cl))
	    >> else if not ofsf_surep(ofsf_0mk2('equal, lcf), theo) then <<
      	       cs := vscs_merge(cs, vscs_opf2csnz(op, f, x, nil, cl));
	       c := ofsf_0mk2('equal, lcf);
	       push(c, theo);
	       push(c, cl)
	    >>;
	    f := red f
	 >> else
	    finished := t
      >> until finished;
      return cs
   end;

asserted procedure vscs_opf2csnz(op: Id, f: SF, x: Kernel, s: Any, cl: QfFormulaL): VScs;
   % Operator and SF to candidate solutions subprocedure. [op] is an
   % operator; [x] is [mvar f]; [s] is the sign of [lc f]: If [lc f]
   % possibly vanishes, then [s] is [nil]. Formulas in [cl] are used
   % in relevance conditions of parametric root descriptions created
   % here. Returns a VScs, which contains parametric root descriptions
   % of [f] that possibly represent ip, ep, slb, wlb, sub, or wub of
   % the satisfying set of the atomic formula [f op 0] under the
   % assumption that [lc f] is non-zero.
   begin scalar w, pral; integer d;
      assert(sfto_mvartest(f, x));
      d := ldeg f;
      w := vsub_compute!-rsl(op, f, x, s);
      if w eq 'failed then
	 return vscs_mk(nil, 'failed);
      pral := for each pr in w collect
	 car pr . for each rs in cdr pr collect
	    vspr_mk(f, x, rs, vs_mkand cl);
      return vscs_mk(nil, pral)
   end;

asserted procedure ofsf_nonvanishp(f: SF, x: Kernel, theo: Theory): Boolean;
   % Ordered field standard form non-vanishing predicate. [f] is a SF
   % in the main variable [x], i.e., if [mvar f neq x], then [f] does
   % not contain [x] and should be treated as a coefficient of [x^0];
   % [theo] is a theory. Returns [t] if [f] cannot identically vanish
   % under the theory [theo].
   begin scalar w, finished, res;
      w := 'false;
      repeat <<
	 if sfto_mvartest(f, x) then <<
	    w := rl_mkn('or, {w, ofsf_0mk2('neq, lc f)});
	    w := cl_simpl(w, theo, -1);
	    f := red f
	 >> else <<
	    w := rl_mkn('or, {w, ofsf_0mk2('neq, f)});
	    w := cl_simpl(w, theo, -1);
	    finished := t
	 >>;
	 if w eq 'true then
	    res := t
      >> until finished or res;
      return res
   end;

asserted procedure ofsf_definite(fml: List, theo: Theory): ExtraBoolean;
   % Ordered field standard form definiteness checking procedure.
   % [fml] is a List of pairs [f . m], where [f] is a SF and [m] is
   % the multiplicity of [f]; [theo] is a theory. Returns [1] iff the
   % product of [fml] is positive definite, [-1] if the product of
   % [fml] is negative definite, and [nil] if the product of [fml] can
   % be zero w.r.t. [theo].
   begin scalar s, f; integer m;
      s := 1;
      while fml and s do <<
	 f . m := pop fml;
	 if evenp m then <<
	    if not ofsf_surep(ofsf_0mk2('neq, f), theo) then
	       s := nil
	 >> else
	    if ofsf_surep(ofsf_0mk2('lessp, f), theo) then
	       s := s * (-1)
	    else if not ofsf_surep(ofsf_0mk2('greaterp, f), theo) then
	       s := nil
      >>;
      return s
   end;

asserted procedure ofsf_sepfac(fml: List, x: Kernel): DottedPair;
   % Ordered field standard form separate factors. [fml] is a List of
   % pairs [f . m], where [f] is a SF and [m] is the multiplicity of
   % [f]; [x] is a Kernel. Returns a DottedPair [fmxl . fmnxl] where
   % [fmxl] contains factors containing [x] and [fmnxl] contains
   % factors not containing [x].
   begin scalar f, fmxl, fmnxl; integer m;
      while fml do <<
	 f . m := pop fml;
	 if sfto_mvartest(f, x) then
	    push(f . m, fmxl)
	 else
	    push(f . m, fmnxl)
      >>;
      return fmxl . fmnxl
   end;

%%% bound selection submodule %%%

asserted procedure vsde_select!-bounds(de: VSde);
   % Select bounds of prime constituents. We assume that no PC in
   % [vsde_pcl de] has ['failed] as candidate solutions.
   if rlbndswithilp!* then
      vsde_select!-bounds!-ilp de
   else
      vsde_select!-bounds!-noilp de;

asserted procedure vsde_select!-bounds!-noilp(de: VSde);
   % Select bounds of prime constituents without ILP.
   begin scalar pcl, cs, bnd, npcl; integer nl, nu;
      pcl := vsde_pcl de;
      for each pc in pcl do <<
      	 cs := vspc_cs pc;
	 nl := vscs_nwlb cs + vscs_nslb cs;
	 nu := vscs_nwub cs + vscs_nsub cs
      >>;
      bnd := if nl < nu then '(lb) else '(ub);
      npcl := for each pc in pcl collect
	 vspc_mk(vspc_p pc, vspc_type pc, vspc_cs pc, vspc_gpl pc, bnd);
      vsde_putpcl(de, npcl)
   end;

%%% prime constitutents to test points submodule %%%

asserted procedure vsde_pcl2tpl(de: VSde);
   % Prime constituent list to test point list. We assume that no PC
   % in [vsde_pcl de] has ['failed] as candidate solutions, and that
   % every PC in [vsde_pcl de] has some selected bounds.
   begin scalar pcl, cs, p, gpl, b, tpl, imi, ipi;
      pcl := vsde_pcl de;
      for each pc in pcl do <<
	 cs := vspc_cs pc;
	 p := vspc_p pc;
	 gpl := vspc_gpl pc;
	 for each pr in vscs_ip cs do
	    push(vstp_mk(p, gpl, nil, pr), tpl);
	 b := vspc_b pc;
	 if 'lb memq b then <<
	    imi := t;
	    for each pr in vscs_ep cs do
	       push(vstp_mk(p, gpl, 'peps, pr), tpl);
	    for each pr in vscs_slb cs do
	       push(vstp_mk(p, gpl, 'peps, pr), tpl);
	    for each pr in vscs_wlb cs do
	       push(vstp_mk(p, gpl, nil, pr), tpl)
	 >>;
	 if 'ub memq b then <<
	    ipi := t;
	    for each pr in vscs_ep cs do
	       push(vstp_mk(p, gpl, 'meps, pr), tpl);
	    for each pr in vscs_sub cs do
	       push(vstp_mk(p, gpl, 'meps, pr), tpl);
	    for each pr in vscs_wub cs do
	       push(vstp_mk(p, gpl, nil, pr), tpl)
	 >>;
	 vsde_putcurtheo(de, append(vsde_curtheo de, vscs_ts cs))
      >>;
      if imi then
	 push(vstp_mk(nil, nil, 'minf, vspr_mk(nil, nil, nil, 'true)), tpl);  % minus infinity
      if ipi then
	 push(vstp_mk(nil, nil, 'pinf, vspr_mk(nil, nil, nil, 'true)), tpl);  % plus infinity
      vsde_puttpl(de, tpl)
   end;

%%% conflation submodule %%%

asserted procedure vsde_conflate!-tpl(de: VSde);
   % Conflate test point list.
   begin scalar tpl, ttpl, tp1, tp2, w, restpl;
      tpl := vsde_tpl de;
      while tpl do <<
	 tp1 := pop tpl;
	 ttpl := tpl;
	 tpl := nil;
	 while ttpl do <<
	    tp2 := pop ttpl;
	    w := vstp_conflate(tp1, tp2);
	    if w then  % conflation was possible
	       tp1 := w
	    else
	       push(tp2, tpl)
	 >>;
	 tpl := reverse tpl;  % This is not necessary. We just don't want to mix [tpl] too much.
	 push(tp1, restpl)
      >>;
      vsde_puttpl(de, reversip restpl)
   end;

asserted procedure vstp_conflate(tp1: VStp, tp2: VStp): ExtraBoolean;
   % Conflate [tp1] with [tp2] if this is possible. Returns [nil] when
   % [tp1] cannot be conflated with [tp2]. If [tp1] and [tp2] can be
   % conflated, then a test point representing a conflation of these
   % two test points is returned.
   begin scalar pr1, pr2;
      pr1 := vstp_pr tp1;
      pr2 := vstp_pr tp2;
      if not eqn(vspr_d pr1, vspr_d pr2) then  % degree test
	 return nil;
      if not (vstp_np tp1 eq vstp_np tp2) then  % nonstandard part test
	 return nil;
      if not (vspr_f pr1 equal vspr_f pr2) then  % polynomial test
	 return nil;
      if lto_subset(vspr_rsl pr1, vspr_rsl pr2) then  % S1 subset of S2
	 return vstp_mk(pos_lca(vstp_p tp1, vstp_p tp2),
	    intersection(vstp_gpl tp1, vstp_gpl tp2),
	    vstp_np tp2,
	    vspr_mk(vspr_f pr2, vspr_v pr2, vspr_rsl pr2, rl_mk2('or, vspr_rc pr1, vspr_rc pr2))
	       );
      if lto_subset(vspr_rsl pr2, vspr_rsl pr1) then % S2 subset of S1
	 return vstp_mk(pos_lca(vstp_p tp1, vstp_p tp2),
	    intersection(vstp_gpl tp1, vstp_gpl tp2),
	    vstp_np tp1,
	    vspr_mk(vspr_f pr1, vspr_v pr1, vspr_rsl pr1, rl_mk2('or, vspr_rc pr1, vspr_rc pr2))
	       );
      return nil
   end;

%%% other procedures %%%

asserted procedure vsde_tpllinp(de: VSde, vl: KernelL): Boolean;
   % VS data for elimination set computation test point list linear
   % predicate. Returns [t] if [vsde_tpl de] is an elimination set
   % containing only linear test points.
   begin scalar tpl, ok, tp;
      tpl := vsde_tpl de;
      if null tpl then  % An elimination set has to be non-empty.
	 return nil;
      ok := t;
      while tpl and ok do <<
	 tp := pop tpl;
	 ok := vstp_linp(tp, vl)
      >>;
      return ok
   end;

asserted procedure vstp_linp(tp: VStp, vl: KernelL): Boolean;
   % Test point linear predicate. Returns [t] if the test point [tp]
   % contains a parametric root of a polynomial [f] that is linear
   % w.r.t. [vl], i.e., the total degree of [f] is 1 and the leading
   % coefficient contains no variables from [vl].
   begin scalar pr, f, x;
      pr := vstp_pr tp;
      f := vspr_f pr;
      x := vspr_v pr;
      if null f then <<
	 assert(vstp_np tp memq '(minf pinf));
	 return t
      >>;
      assert(sfto_mvartest(f, x));
      if eqn(ldeg f, 1) and null intersection(kernels lc f, vl) then
 	 return t;
      return nil
   end;

asserted procedure vsde_tplldp(de: VSde, n: Integer): Boolean;
   % VS data for elimination set computation test point list low
   % degree predicate. Returns [t] if [vsde_tpl de] is an elimination
   % set containing only test points of degree at most [n].
   begin scalar tpl, ok, tp;
      tpl := vsde_tpl de;
      if null tpl then  % An elimination set is non-empty.
	 return nil;
      ok := t;
      while tpl and ok do <<
	 tp := pop tpl;
	 ok := vstp_ldp(tp, n)
      >>;
      return ok
   end;

asserted procedure vstp_ldp(tp: VStp, n: Integer): Boolean;
   % Test point low degree predicate. Returns [t] if the test point
   % [tp] contains a parametric root of a polynomial [f] that is of
   % degree at most [n].
   begin scalar pr, f, x;
      pr := vstp_pr tp;
      f := vspr_f pr;
      x := vspr_v pr;
      if null f then <<
	 assert(vstp_np tp memq '(minf pinf));
	 return t
      >>;
      assert(sfto_mvartest(f, x));
      if ldeg f <= n then
	 return t;
      return nil
   end;

asserted procedure ofsf_adjustop(op: Id, s: Integer): Id;
   % Ordered field standard form adjust operator. Returns [op]
   % adjusted by multiplying it with [s].
   begin
      assert(eqn(s, 1) or eqn(s, -1));
      assert(op memq '(equal neq lessp leq geq greaterp));
      if op memq '(equal neq) or eqn(s, 1) then
      	 return op;
      if op eq 'lessp then
	 return 'greaterp;
      if op eq 'greaterp then
	 return 'lessp;
      if op eq 'geq then
	 return 'leq;
      if op eq 'leq then
	 return 'geq
   end;

asserted procedure pos_delsubposal(pal1: AList, pal2: AList): AList;
   % Delete from [pal2] all positions, which are subpositions of a
   % position from [pal1]. [pal1] and [pal2] are ALists containing
   % pairs of the form [(Position . Any)].
   begin scalar pl1, pl2, npl2;
      pl1 := for each pr in pal1 collect
	 car pr;
      pl2 := for each pr in pal2 collect
	 car pr;
      npl2 := pos_delsubposl(pl1, pl2);
      return for each np2 in npl2 collect
	 assoc(np2, pal2)
   end;

asserted procedure pos_delsubposl(pl1: PositionL, pl2: PositionL): PositionL;
   % Delete from [pl2] all positions, which are subpositions of a
   % position from [pl1].
   begin scalar w, c, p1, res;
      for each p2 in pl2 do <<
	 w := pl1;
	 c := nil;
	 while w and not c do <<
	    p1 := pop w;
	    c := pos_subposp(p1, p2)
	 >>;
	 if not c then
	    push(p2, res)
      >>;
      return reversip res
   end;

asserted procedure pos_subposp(p1: Position, p2: Position): Boolean;
   % Subposition predicate. Returns [t] iff [p2] is a subposition of
   % [p1].
      if null p1 then
	 t
      else if null p2 then
	 nil
      else if eqn(car p1, car p2) then
	 pos_subposp(cdr p1, cdr p2)
      else
	 nil;

asserted procedure pos_lca(p1: Position, p2: Position): Position;
   % Lowest common ancestor of [p1] and [p2].
      if null p1 or null p2 then
	 nil
      else if not eqn(car p1, car p2) then
	 nil
      else
	 car p1 . pos_lca(cdr p1, cdr p2);

% TODO: Move the following procedure to cl.
asserted procedure vs_mkand(fl: QfFormulaL): QfFormula;
   if null fl then
      'true
   else if null cdr fl then
      car fl
   else
      rl_mkn('and, fl);

% functions mainly for debugging purposes

asserted procedure vsdc_prints(dc: VSdc);
   % VSdc print summary.
   <<
      % ioto_prin2 {"VSdc with ttheo:"};
      % for each f in vsdc_ttheo dc do
      % 	 mathprint rl_prepfof f
      ioto_prin2 {"VSdc: "};
      ioto_prin2t {"f: ", vsdc_f dc,
      	 " #ptheo: ", length vsdc_ptheo dc,
      	 " #ttheo: ", length vsdc_ttheo dc,
      	 " data: ", vsdc_data dc}
   >>;

asserted procedure vscs_prints(cs: VScs);
   % VScs print summary.
   if vscs_failedp cs then
      ioto_prin2t {"VScs: failed"}
   else <<
      ioto_prin2 {"VScs: "};
      ioto_prin2t {"#ip: ", length vscs_ip cs,
	 " #ep: ", length vscs_ep cs,
	 " #slb: ", length vscs_slb cs,
	 " #wlb: ", length vscs_wlb cs,
	 " #sub: ", length vscs_sub cs,
	 " #wub: ", length vscs_wub cs}
   >>;

asserted procedure vscs_print(cs: VScs);
   % VScs print.
   if vscs_failedp cs then
      ioto_prin2t {"VScs: failed"}
   else <<
      ioto_prin2t {"VScs: "};
      ioto_prin2t {"ip: ", vscs_ip cs};
      ioto_prin2t {"ep: ", vscs_ep cs};
      ioto_prin2t {"slb: ", vscs_slb cs};
      ioto_prin2t {"wlb: ", vscs_wlb cs};
      ioto_prin2t {"sub: ", vscs_sub cs};
      ioto_prin2t {"wub: ", vscs_wub cs}
   >>;

asserted procedure vspc_prints(pc: VSpc);
   % VSpc print summary.
   <<
      ioto_prin2 {"VSpc: "};
      ioto_prin2t {"type: ", vspc_type pc,
      	 " pos: ", vspc_p pc,
      	 " gpl: ", vspc_gpl pc,
	 " bndch: ", vspc_b pc,
      	 " cs: "};
      vscs_prints vspc_cs pc
   >>;

asserted procedure vspr_prints(pr: VSpr);
   % VSpr print summary.
   <<
      ioto_prin2 {"VSpr: "};
      ioto_prin2 {"poly:"};
      mathprint prepf vspr_f pr;
      ioto_prin2t {"root specs: ", vspr_rsl pr}
   >>;

asserted procedure vstp_prints(tp: VStp);
   % VStp print summary.
   <<
      ioto_prin2 {"VStp: "};
      ioto_prin2t {"pos: ", vstp_p tp,
	 " gpl: ", vstp_gpl tp,
	 " np: ", vstp_np tp,
	 " pr:"};
      vspr_prints vstp_pr tp;
      ioto_prin2t {"guard:"};
      mathprint rl_prepfof vstp_guard tp
   >>;

endmodule;  % [ofsfvseset]

end;  % of file
