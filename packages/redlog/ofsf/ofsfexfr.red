% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2012 M. Kosta, T. Sturm
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
   fluid '(ofsf_exfr_rcsid!* ofsf_exfr_copyright!*);
   ofsf_exfr_rcsid!* :=
      "$Id$";
   ofsf_exfr_copyright!* := "(c) 2012 M. Kosta, T. Sturm"
>>;

module ofsfexfr;

fluid '(anu_precision!*);
anu_precision!* := 2;

%DS
% GAnu ::= 'minf | 'pinf | Anu
% AnuInterval ::= AnuSpan | AnuPoint | nil
% AnuSpan ::= ('anuiv_span, AnuSpanBound, AnuSpanBound)
% AnuSpanBound ::= ('anusp_open | 'anusp_closed, GAnu)
% AnuPoint ::= ('anuiv_point, Anu)

struct GAnu asserted by GAnuP;
struct AnuIntervalList asserted by AnuIntervalListP;
struct AnuInterval asserted by AnuIntervalP;
struct AnuSpan asserted by AnuSpanP;
struct AnuSpanBound asserted by AnuSpanBoundP;
struct AnuPoint asserted by AnuPointP;

procedure GAnuP(s);
   AnuP s or s eq 'minf or s eq 'pinf;

procedure AnuIntervalListP(s);
   not s or pairp s and AnuIntervalP car s and AnuIntervalListP cdr s;

procedure AnuIntervalP(s);
   not s or eqcar(s, 'anuiv_span) or eqcar(s, 'anuiv_point);

procedure AnuSpanP(s);
   eqcar(s, 'anuiv_span);

procedure AnuSpanBoundP(s);
   eqcar(s, 'anusp_open) or eqcar(s, 'anusp_closed);

procedure AnuPointP(s);
   eqcar(s, 'anuiv_point);

asserted procedure anuiv_type(iv: AnuInterval): Id;
   car iv;

asserted procedure anuiv_ptp(iv: AnuInterval): ExtraBoolean;
   eqcar(iv, 'anuiv_point);

asserted procedure anuiv_spp(iv: AnuInterval): ExtraBoolean;
   eqcar(iv, 'anuiv_interval);

asserted  procedure anupt_mk(anu: Anu): AnuPoint;
   {'anuiv_point, anu};

asserted  procedure anupt_anu(pt: AnuPoint): Anu;
   cadr pt;

asserted procedure anusp_mk(lt: Id, lb: GAnu, ut: Id, ub: GAnu): AnuSpan;
   {'anuiv_span,
      {if lb eq 'minf then 'anusp_open else lt, lb},
      {if ub eq 'pinf then 'anusp_open else ut, ub}};

asserted procedure anusp_lt(iv: AnuSpan): Id;
   car cadr iv;

asserted procedure anusp_lb(iv: AnuSpan): GAnu;
   cadr cadr iv;

asserted procedure anusp_ut(iv: AnuSpan): Id;
   car caddr iv;

asserted procedure anusp_ub(iv: AnuSpan): GAnu;
   cadr caddr iv;

%DS
% State ::= ('rl_state, Mode, Target, Trail, TaggedClauseList, VariableList, Level)
% Mode ::= 'models | 'vdash | nil
% Target ::= Clause | nil
% TaggedClause ::= (nil | t . Clause) (* nil means input, t means learned *)
% Level ::= Number
% Trail ::= TrailElementList
% TrailElement ::= TrailLit | VarAss
% TrailLit ::= PropLit | DecLit
% PropLit ::= ('rl_proplit, Clause | CadInput, AtomicFormula) (* AtomicFormula in Clause *)
% DecLit ::= ('rl_declit, nil, AtomicFormula)
% VarAss ::= ('rl_varass, Kernel, Anu)

struct State asserted by StateP;
struct Trail asserted by listp;
struct Clause asserted by listp;
struct TrailLit asserted by TrailLitP;

procedure StateP(s);
   eqcar(s, 'rl_state);

procedure TrailLitP(s);
   eqcar(s, 'rl_proplit) or eqcar(s, 'rl_declit);

asserted procedure state_mk(m: Id, ta: Clause, trl: Trail, tcl: List, vl: List, n: Integer): State;
   % [m] is 'models, 'vdash or nil; [ta] is Clause or nil; [trl] is
   % TrailElementList; [tcl] is TaggedClauseList; [vl] is a VariableList
   % containing unassigned variables; [n] is Level. Returns a state.
   {'rl_state, m, ta, trl, for each tc in tcl collect nil . tc, vl, n};

asserted procedure state_mode(s: State): Id;
   cadr s;

asserted procedure state_target(s: State): Clause;
   caddr s; % to do with nth(s, 3)

asserted procedure state_trail(s: State): Trail;
   cadddr s;

asserted procedure state_tcl(s: State): List;
   car cddddr s;

asserted procedure state_vl(s: State): List;
   car cdr cddddr s;

asserted procedure state_level(s: State): Integer;
   car cdr cdr cddddr s;

asserted procedure trail_push(tre: Any, trl: Trail): Trail;
   tre . trl;

asserted procedure trail_pop(trl: Trail): DottedPair;
   trl;

asserted procedure tlit_mk(tag: Id, e: Any, atf: OfsfAtf): TrailLit;
   % [tag] is 'rl_declit or 'rl_proplit; [e] is a Clause or CadInput or [nil];
   % [atf] is an atomic formula. Returns TrailLit.
   {tag, e, atf};

asserted procedure tlit_tag(tl: TrailLit): Id;
   car tl;

asserted procedure tlit_e(tl: TrailLit): Any;
   cadr tl;

asserted procedure tlit_atf(tl: TrailLit): OfsfAtf;
   caddr tl;

inline procedure tre_varassp(tre);
   eqcar(tre, 'rl_varass);

inline procedure tre_declitp(tre);
   eqcar(tre, 'rl_declit);

inline procedure tre_proplitp(tre);
   eqcar(tre, 'rl_proplit);

inline procedure tre_litp(tre);
   tre_proplitp tre or tre_declitp tre;

inline procedure tre_lit(tre);
   cadr tre;

inline procedure varass_mk(k, anu);
   {'rl_varass, k, anu};

inline procedure varass_k(va);
   cadr va;

inline procedure varass_value(va);
   caddr va;

inline procedure declit_mk(lit);
   {'rl_declit, lit};

inline procedure proplit_mk(lit);
   {'rl_proplit, lit};

asserted procedure ofsf_selectClause(s: State): State;
   begin scalar tcl, c;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      tcl := state_tcl s;
      while tcl do <<
	 c := cdr pop tcl;
	 if ofsf_undef(c, state_trail s) then
	    tcl := nil;
      >>;
      if not c then
	 return nil;
      % Rule is applicable.
      return state_mk('models, c, state_trail s, state_tcl s, state_vl s,
	 state_level s)
   end;

asserted procedure ofsf_conflict(s: State): State;
   begin scalar tcl, c;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      tcl := state_tcl s;
      while tcl do <<
	 c := cdr pop tcl;
	 if ofsf_value(c, state_trail s) eq 'false then
	    tcl := nil;
      >>;
      if not c then
	 return nil;
      % Rule is applicable.
      return state_mk('vdash, c, state_trail s, state_tcl s, state_vl s,
	 state_level s)
   end;

asserted procedure ofsf_sat(s: State): State;
   begin scalar eql;
      if state_mode s or state_vl s then
	 return nil;
      eql := for each tre in state_trail s join
	 if tre_varassp tre then
	    {tre};
      return state_mk('sat, nil, eql, nil, state_vl s, state_level s + 1)
   end;

asserted procedure ofsf_liftLevel(s: State): State;
   begin scalar xk, a, vl;
      if state_mode s then
	 return nil;
      vl := state_vl s;
      xk := pop vl;
      a := ofsf_feasible(state_trail s);
      if not a then
	 return nil;
      state_mk(nil, nil,
	 trail_push(state_trail s, varass_mk(xk, a)),
 	 state_tcl s, vl, state_level s + 1)
   end;

asserted procedure ofsf_feasible(trl: Trail): AnuIntervalList;
   % [trl] is a trail. Returns a finite list of intervals with Anu bounds.
   begin scalar fl, gl, assal, lit;
      for each tre in trl do
	 if tre_varassp tre then
	    assal := (varass_k tre . varass_value tre) . assal
	 else <<  % we know tre_litp tre
	    lit := tre_lit tre;
	    if ofsf_op lit eq 'equal then
	       fl := lit . fl
	    else
	       gl := lit . gl
	 >>;
      fl := for each f in fl collect
	 ofsf_anusubf(ofsf_arg2l f, assal) . 'equal;
      gl := for each g in gl collect
	 ofsf_anusubf(ofsf_arg2l g, assal) . ofsf_op g;
      return if fl then
	 ofsf_feasible1(fl, gl)
      else
	 ofsf_feasible2(gl)
   end;

asserted procedure ofsf_feasible1(fl: List, gl: List): AnuIntervalList;
   % [fl] is a list of pairs [f . 'equal] where [f] is an Aex; [gl] is a list of
   % pairs [f . op] where [f] is an Aex and [op] is an ofsf operator different
   % from ['equal].
   begin scalar xk, f, l, fidl;
      f := car pop fl;
      fidl := aex_fvarl f;
      assert(fidl and not cdr fidl);
      xk := car fidl;
      l := for each anu in aex_findroots(f, xk) join
	 if ofsf_feasible11(anu, xk, fl, gl) then
	    {anupt_mk anu};
      return l
   end;

asserted procedure ofsf_feasible11(anu: Anu, xk: Kernel, fl: List, gl: List): Boolean;
   begin scalar cnt, f, g, op;
      cnt := t; while cnt and fl do <<
	 f := car pop fl;
	 if not aex_nullp aex_bind(f, xk, anu) then
	    cnt := nil
      >>;
      while cnt and gl do <<
	 g . op := pop gl;
	 if not aex_evalsgn(aex_bind(g, xk, anu), op) then
	    cnt := nil
      >>;
      return cnt
   end;

asserted procedure ofsf_feasible2(gl: List): AnuIntervalList;
   % [gl] is a list of pairs [f . op] where [f] is an Aex and [op] is an ofsf
   % operator different from ['equal].
   begin scalar xk, fidl, ivl, g, givl, rel;
      assert gl;
      ivl := {anusp_mk('anusp_open, 'minf, 'anusp_open, 'pinf)};
      fidl := aex_fvarl caar gl;
      assert(fidl and not cdr fidl);
      xk := car fidl;
      while gl do <<
	 g . rel := pop gl;
      	 givl := ofsf_lit2ivl(rel, g, xk);
	 ivl := ofsf_updivl(ivl, givl);
	 if not ivl then
	    gl := nil
      >>;
      return ivl
   end;

asserted procedure ofsf_lit2ivl(rel: Id, g: Aex, xk: Kernel): AnuIntervalList;
   begin scalar sgvl, rootl;
      assert(aex_fvarl g = {xk});
      rootl := aex_findroots(g, xk);
      sgvl := ofsf_lit2ivl1(rel, g, xk, rootl);
      return sgvl
   end;

asserted procedure ofsf_lit2ivl1(rel: Id, g: Aex, xk: Kernel, rootl: AnuList): AnuIntervalList;
   begin scalar tag, gp, givl, insp, lb, ub, sign;
      if rel eq 'neq then
	 return ofsf_lit2ivlNeq(rootl);
      tag := if rel memq '(geq leq) then 'anusp_closed else 'anusp_open;
      gp := aex_diff(g, xk);
      if ofsf_feasibleEval(rel, ofsf_feasibleEvalSgn(g, xk, 'minf)) then <<
	 givl := {anusp_mk('anusp_open, 'minf, 'anusp_open, car rootl)};
	 insp := t
      >>;
      rootl := nconc(rootl, {'pinf});
      for each rrootl on rootl do
      	 if cdr rrootl then <<
	    lb := car rrootl;
	    ub := cadr rrootl;
	    sign := ofsf_feasibleEvalSgn(gp, xk, lb);
	    if eqn(sign, 0) then
	       if insp then
		  givl := anusp_mk(tag, lb, tag, ub) . givl
	       else
		  (if tag eq 'anusp_closed then
		     givl := anupt_mk lb . givl)
	    else <<
	       if not insp then
		  givl := anusp_mk(tag, lb, tag, ub) . givl;
	       insp := not insp
	    >>
      	 >>;
      givl := reversip givl;
      if tag eq 'anusp_closed then
	 givl := ofsf_lit2ivlJoin givl;
      return givl
   end;

asserted procedure ofsf_lit2ivlNeq(rootl: AnuList): AnuIntervalList;
   begin scalar givl, lb;
      lb := 'minf;
      for each r in rootl do <<
	 givl := anusp_mk('anusp_open, lb, 'anusp_open, r) . givl;
	 lb := r
      >>;
      givl := anusp_mk('anusp_open, lb, 'anusp_open, 'pinf) . givl;
      return reversip givl
   end;

asserted procedure ofsf_lit2ivlJoin(givl: AnuIntervalList): AnuIntervalList;
   begin scalar iv1, iv2, jgivl;
      if not givl or not cdr givl then
	 return givl;
      iv1 := pop givl;
      jgivl := ofsf_lit2ivlJoin givl;
      if anuiv_ptp iv1 then
	 return iv1 . jgivl;
      iv2 := pop jgivl;
      if anuiv_ptp iv2 then
	 return iv1 . iv2 . jgivl;
      if anusp_ub iv1 neq anusp_lb iv2 then
	 return iv1 . iv2 . jgivl;
      return anusp_mk(
	 anusp_lt iv1, anusp_lb iv1, anusp_ut iv2, anusp_ub iv2) . jgivl
   end;

asserted procedure ofsf_feasibleEval(op: Id, n: Integer): Boolean;
   % [op] is an ofsf relation; [n] is an Integer. Returns Boolean.
   ofsf_evalatp(op, if eqn(n, 0) then nil else n);

asserted procedure ofsf_updIvl(ivl: AnuIntervalList, givl: AnuIntervalList): AnuIntervalList;
   % Update interval lists.
   begin scalar iv, res1, res2;
      if not ivl then
	 return nil;
      iv := pop ivl;
      res1 := ofsf_ivcutl(iv, givl);
      res2 := ofsf_updIvl(ivl, givl);
      return nconc(res1, res2)
   end;

asserted procedure ofsf_ivcutl(iv: AnuInterval, ivl: AnuIntervalList): AnuIntervalList;
   % Interval cut list. [iv] is an Interval, [ivl] is a list of Intervals.
   % Returns a list of Intervals. The result is the intersection of [iv] and
   % [ivl].
   begin scalar iv2, res, w;
      if not ivl then
	 return nil;
      iv2 := pop ivl;
      w := ofsf_ivcutl(iv, ivl);
      res := ofsf_ivcut(iv, iv2);
      if res then
	 w := res . w;
      return w
   end;

asserted procedure ofsf_ivcut(iv1: AnuInterval, iv2: AnuInterval): AnuInterval;
   begin
      if anuiv_ptp iv1 and anuiv_ptp iv2 then <<
	 if eqn(ganu_compare(anupt_anu iv1, anupt_anu iv2), 0) then
	    return iv1;  % TODO: return the nicer anu?
	 return nil
      >>;
      if anuiv_ptp iv1 then
	 return ofsf_ivcut1(iv1, iv2);
      if anuiv_ptp iv2 then
	 return ofsf_ivcut1(iv2, iv1);
      return ofsf_ivcut2(iv1, iv2)
   end;

asserted procedure ofsf_ivcut1(p: AnuPoint, iv: AnuInterval): AnuInterval;
   begin scalar w;
      w := ganu_compare(anupt_anu p, anusp_lb iv);
      if w < 0 or (eqn(w, 0) and anusp_lt iv eq 'anusp_open) then
	 return nil;
      w := ganu_compare(anupt_anu p, anusp_ub iv);
      if w > 0 or (eqn(w, 0) and anusp_ut iv eq 'anusp_open) then
	 return nil;
      return p
   end;

asserted procedure ofsf_ivcut2(iv1: AnuSpan, iv2: AnuSpan): AnuInterval;
   begin scalar lt, lb, ut, ub, w;
      lt . lb := ofsf_ivbmax(
	 anusp_lt iv1, anusp_lb iv1, anusp_lt iv2, anusp_lb iv2);
      ut . ub := ofsf_ivbmin(
	 anusp_ut iv1, anusp_ub iv1, anusp_ut iv2, anusp_ub iv2);
      w := ganu_compare(lb, ub);
      if w > 0 then
	 return nil;
      if w < 0 then
	 return anusp_mk(lt, lb, ut, ub);
      if lt eq 'anusp_closed and ut qe 'anusp_closed then
	 return anupt_mk lb;  % TODO: find the nicer Anu?
      return nil
   end;

asserted procedure ofsf_ivbmax(t1: Id, b1: GAnu, t2: Id, b2: GAnu): DottedPair;
   % The result is the maximum of both.
   begin scalar w;
      w := ganu_compare(b1, b2);
      if w < 0 then
	 return t2 . b2;
      if w > 0 then
	 return t1 . b1;
      if t1 eq 'anusp_open then
	 return t1 . b1;
      return t2 . b2
   end;

asserted procedure ofsf_ivbmin(t1: Id, b1: GAnu, t2: Id, b2: GAnu): DottedPair;
   % The result is the minimum of both.
   begin scalar w;
      w := ganu_compare(b1, b2);
      if w > 0 then
	 return t2 . b2;
      if w < 0 then
	 return t1 . b1;
      if t1 eq 'anusp_open then
	 return t1 . b1;
      return t2 . b2
   end;

asserted procedure ganu_compare(ganu1: GAnu, ganu2: GAnu): Integer;
   % Returns an integer [z]. We have [z < 0] if [anu1 < anu2], [z = 0] if [anu1
   % = anu2] and [z = 1] if [anu1 > anu2].
   if ganu1 eq ganu2 then
      0
   else if ganu1 eq 'pinf or ganu2 eq 'minf then
      1
   else if ganu1 eq 'minf or ganu2 eq 'pinf then
      -1
   else
      anu_compare(ganu1, ganu2);

asserted procedure anu_compare(anu1: Anu, anu2: Anu): Integer;
   begin scalar iv1, iv2;
      if anu1 = anu2 then
	 return 0;
      iv1 := anu_iv anu1;
      iv2 := anu_iv anu2;
      if rat_compare(iv_rb iv1, iv_lb iv2) leq 0 then
	 return -1;
      if rat_compare(iv_rb iv2, iv_lb iv1) leq 0 then
	 return 1;
      return anu_compare1(anu1, anu2)
   end;

asserted procedure rat_compare(r1, r2): Integer;
   numr subtrsq(r1, r2) or 0;

asserted procedure anu_compare1(anu1: Anu, anu2: Anu): Integer;
   begin scalar g, oldorder, w;
      g := gensym();
      oldorder := setkorder(g . kord!*);
      w := errorset({'anu_compare2, mkquote anu1, mkquote anu2, mkquote g},
	 nil, !*backtrace);
      setkorder oldorder;
      if errorp w then
	 rederr emsg!*;
      return car w
   end;

asserted procedure anu_compare2(anu1: Anu, anu2: Anu, g: Kernel): Integer;
   % [anu1], [anu2] are Anu or 'minf or 'pinf. Returns an integer [z]. We have
   % [z < 0] if [anu1 < anu2], [z = 0] if [anu1 = anu2] and [z = 1] if [anu1 >
   % anu2].
   begin scalar aex1, aex2;
      aex1 := aex_fromAnu anu1;
      aex2 := aex_fromAnu anu_varChange(anu2, g);
      return aex_sgn aex_minus(aex1, aex2)
   end;

asserted procedure aex_fromAnu(anu: Anu): Aex;
   begin scalar vl, v, aex;
      vl := aex_fvarl anu_dp anu;
      assert(length vl = 1);
      v := car vl;
      aex := aex_bind(aex_fromrp simp v, v, anu);
      return aex
   end;

asserted procedure anu_varChange(anu: Anu, newvar: Kernel): Anu;
   begin scalar dp;
      dp := anu_dp anu;
      return anu_mk(aex_subrp(dp, car aex_fvarl dp, newvar), anu_iv anu)
   end;

asserted procedure ofsf_feasibleEvalSgn(g: Aex, x: Kernel, anu: GAnu): Integer;
   % Feasible evaluate sign. [g] is an Aex; [x] is the only free id in [g];
   % [anu] is an Anu or 'minf or 'pinf. Returns -1, 0, or 1. The result is the
   % sign of [g] at the point [anu].
   if anu eq 'pinf then
      aex_sgnatinfty(g, x)
   else if anu eq 'minf then
      aex_sgnatminfty(g, x)
   else
      aex_sgn aex_bind(g, x, anu);

asserted procedure aex_evalsgn(aex: Aex, op: Id): Boolean;
   % [aex] is a constant Aex; [op] is an ofsf operator. Returns Boolean.
   begin scalar sgn;
      assert(aex_constp aex);
      sgn := aex_sgn aex;
      if eqn(sgn, 0) then
	 sgn := nil;
      return ofsf_evalatp(op, sgn)
   end;

asserted procedure ofsf_forget(s: State): State;
   begin scalar tcl, tc, cnt, ntcl;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      tcl := state_tcl s;
      cnt := t; while cnt and tcl do <<
	 tc := pop tcl;
	 if not car tc then
	    ntcl := tc . ntcl
	 else <<
	    cnt := nil;
	    ntcl := nconc(reversip ntcl, tcl);
	 >>
      >>;
      if cnt then % No learned clauses.
	 return nil;
      % Rule is applicable.
      return state_mk(nil, nil, state_trail s, ntcl, state_vl s, state_level s)
   end;

asserted procedure ofsf_undefp(c: Clause, trl: Trail): Boolean;
   % [c] is a Clause; [trl] is a Trail.
   begin scalar avl, at, defp;
      avl := for each tre in trl join
	 if tre_varassp tre then
	    {varass_k tre};
      defp := t; while defp and c do <<
	 at := pop c;
	 if not lto_subsetq(ofsf_varlat at, avl) then
	    defp := nil
      >>;
      return not defp
   end;

asserted procedure ofsf_value(c: Clause, trl: Trail): Id;
   begin scalar eqal, cnt, at;
      if ofsf_undefp(c, trl) then
      	 return 'undef;
      eqal := for each tre in trl join
	 if tre_varassp tre then
	    {varass_k tre . varass_value tre};
      cnt := t; while cnt and c do <<
	 at := pop c;
	 if ofsf_valueat(at, eqal) eq 'true then
	    cnt := nil
      >>;
      return if cnt then 'false else 'true
   end;

asserted procedure ofsf_valueat(at: OfsfAtf, eqal: AList): Id;
   if ofsf_evalatp(ofsf_op at, ofsf_subalf(ofsf_arg2l at, eqal)) then
      'true
   else
      'false;

asserted procedure ofsf_subalf(f: SF, al: Alist): SQ;
   % The keys of [al] are a superset of the variables in [f]; the values are
   % SQs.
   begin scalar nred, nlc;
      if domainp f then
      	 return !*f2q f;
      nred := ofsf_subalf(red f, al);
      nlc := ofsf_subalf(lc f, al);
      return addsq(multsq(nlc, exptsq(cdr atsoc(mvar f, al), ldeg f)), nred)
   end;

asserted procedure ofsf_anusubf(f: SF, al: Alist): Aex;
   % [al] is an Alist, where the keys are kernels and the values
   % are Anu.
   begin scalar aex;
      aex := aex_fromsf f;
      for each pr in al do
	 aex := aex_bind(aex, car pr, cdr pr);
      return aex
   end;

asserted procedure anu_refine(anu: Anu): Anu;
   begin scalar iv, w, sc, fidl, x;
      iv := anu_iv anu;
      if iv_lb iv = iv_rb iv then
	 return anu;
      w := copy anu;
      fidl := aex_fvarl anu_dp anu;
      assert eqn(length fidl, 1);
      x := car fidl;
      sc := aex_stdsturmchain(anu_dp anu, x);
      anu_refine1ip(w, sc);
      assert(w neq anu);
      return w
   end;

asserted procedure ganu_evalf(ganu: GAnu);
   % Returns Floating or [minf] or [pinf].
   if ganu memq '(minf pinf) then ganu else anu_evalf ganu;

asserted procedure anu_evalf(anu: Anu): Floating;
   begin scalar iv, ranu, lb, ub;
      ranu := anu;
      repeat <<
      	 ranu := anu_refine ranu;
	 iv := anu_iv ranu;
	 lb := float(numr car iv or 0)/float denr car iv;
	 ub := float(numr cdr iv or 0)/float denr cdr iv
      >> until anu_approxEqualEnough(lb, ub);
      return lb
   end;

asserted procedure anu_approxEqualEnough(lb: Floating, ub: Floating): Boolean;
   eqn(fix(lb * 10^anu_precision!*) - fix(ub * 10^anu_precision!*), 0);

procedure ofsf_ivlapprox(ivl);
   for each iv in ivl collect
      ofsf_ivapprox iv;

procedure ofsf_ivapprox(iv);
   if anuiv_ptp iv then
      {'anuiv_fpoint, anu_evalf cadr iv}
   else
      {'anuiv_fspan,
   	 {anusp_lt iv, ganu_evalf anusp_lb iv},
	 {anusp_ut iv, ganu_evalf anusp_ub iv}};

procedure ofsf_ivlprint(ivl);
   if not ivl then
      ioto_prin2t "{}"
   else <<
      ioto_prin2 "{";
      ofsf_ivprin car ivl;
      for each iv in cdr ivl do <<
	 ioto_prin2 ", ";
	 ofsf_ivprin iv
      >>;
      ioto_prin2t "}"
   >>;

procedure ofsf_ivprint(iv);
   <<
      ofsf_ivprin iv;
      terpri()
   >>;

procedure ofsf_ivprin(iv);
   begin scalar oldprecision, w;
      oldprecision := getprintprecision();
      setprintprecision(anu_precision!* + 1);
      w := errorset({'ofsf_ivprin1, mkquote iv}, nil, !*backtrace);
      setprintprecision oldprecision;
      if errorp w then
	 rederr emsg!*;
      return car w
   end;

procedure ofsf_ivprin1(iv);
   begin scalar lb, ub;
      if not iv then
	 return;
      if eqcar(iv, 'anuiv_fpoint) then
      	 ioto_prin2 cadr iv
      else <<
	 lb := cadr iv;
	 ub := cadr cdr iv;
      	 ioto_prin2 {
      	    if car lb eq 'anusp_open then "]" else "[",
      	    if cadr lb neq 'minf then cadr lb else "minf",
      	    ",",
      	    if cadr ub neq 'pinf then cadr ub else "pinf",
      	    if car ub eq 'anusp_open then "[" else "]"}
      >>
   end;

endmodule;

end;  % of file
