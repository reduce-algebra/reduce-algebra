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

%DS
% GAnu ::= 'minf | 'pinf | Anu
% AnuInterval ::= AnuSpan | AnuPoint | nil
% AnuSpan ::= ('anuiv_span, AnuSpanBound, AnuSpanBound)
% AnuSpanBound ::= ('anusp_open | 'anusp_closed, GAnu)
% AnuPoint ::= ('anuiv_point, Anu)

struct GAnu asserted by ganup;
struct AnuIntervalList asserted by anuintervallistp;
struct AnuInterval asserted by anuintervalp;
struct AnuSpan asserted by anuspanp;
struct AnuSpanBound asserted by anuspanboundp;
struct AnuPoint asserted by anupointp;

procedure ganup(s);
   anup s or s eq 'minf or s eq 'pinf;

procedure anuintervallistp(s);
   not s or pairp s and anuintervalp car s and anuintervallistp cdr s;

procedure anuintervalp(s);
   not s or eqcar(s, 'anuiv_span) or eqcar(s, 'anuiv_point);

procedure anuspanp(s);
   eqcar(s, 'anuiv_span);

procedure anuspanboundp(s);
   eqcar(s, 'anusp_open) or eqcar(s, 'anusp_closed);

procedure anupointp(s);
   eqcar(s, 'anuiv_point);

asserted procedure anuiv_ptp(iv: AnuInterval): ExtraBoolean;
   eqcar(iv, 'anuiv_point);

asserted procedure anuiv_spp(iv: AnuInterval): ExtraBoolean;
   eqcar(iv, 'anuiv_span);

asserted  procedure anupt_mk(anu: Anu): AnuPoint;
   {'anuiv_point, anu};

asserted  procedure anupt_anu(pt: AnuPoint): Anu;
   nth(pt, 2);

asserted procedure anusp_mk(lt: Id, lb: GAnu, ut: Id, ub: GAnu): AnuSpan;
   {'anuiv_span,
      {if lb eq 'minf then 'anusp_open else lt, lb},
      {if ub eq 'pinf then 'anusp_open else ut, ub}};

asserted procedure anusp_lt(iv: AnuSpan): Id;
   car nth(iv, 2);

asserted procedure anusp_lb(iv: AnuSpan): GAnu;
   cadr nth(iv, 2);

asserted procedure anusp_ut(iv: AnuSpan): Id;
   car nth(iv, 3);

asserted procedure anusp_ub(iv: AnuSpan): GAnu;
   cadr nth(iv, 3);

struct ExfrData checked by ExfrDataP;

procedure ExfrDataP(s);
   atom s and getv(s, 0) eq 'exfrdata;

asserted procedure exfrdata_mkblank(): ExfrData;
   begin scalar ed;
      ed := mkvect(12);
      putv(ed, 0, 'exfrdata);
      return ed
   end;

procedure exfrdata_phi(ed);       getv(ed, 1);
procedure exfrdata_varl(ed);      getv(ed, 2);
procedure exfrdata_n(ed);         getv(ed, 3);
procedure exfrdata_oldorder(ed);  getv(ed, 4);
procedure exfrdata_lvlal(ed);     getv(ed, 5);
procedure exfrdata_cc(ed);        getv(ed, 6);
procedure exfrdata_asgv(ed);      getv(ed, 7);
procedure exfrdata_trlv(ed);      getv(ed, 8);
procedure exfrdata_ivlv(ed);      getv(ed, 9);
procedure exfrdata_level(ed);     getv(ed, 10);
procedure exfrdata_mode(ed);      getv(ed, 11);
procedure exfrdata_target(ed);    getv(ed, 12);

procedure exfrdata_putphi(ed, phi);       putv(ed, 1, phi);
procedure exfrdata_putvarl(ed, varl);     putv(ed, 2, varl);
procedure exfrdata_putn(ed, n);           putv(ed, 3, n);
procedure exfrdata_putoldorder(ed, oo);   putv(ed, 4, oo);
procedure exfrdata_putlvlal(ed, lvlal);   putv(ed, 5, lvlal);
procedure exfrdata_putcc(ed, cc);         putv(ed, 6, cc);
procedure exfrdata_putasgv(ed, v);        putv(ed, 7, v);
procedure exfrdata_puttrlv(ed, v);        putv(ed, 8, v);
procedure exfrdata_putivlv(ed, v);        putv(ed, 9, v);
procedure exfrdata_putlevel(ed, l);       putv(ed, 10, l);
procedure exfrdata_putmode(ed, m);        putv(ed, 11, m);
procedure exfrdata_puttarget(ed, tgt);    putv(ed, 12, tgt);

asserted procedure exfrdata_init(phi: OfFormula): ExfrData;
   % [phi] is a quantifier-free formula in CNF.
   begin scalar ed, varl, oo, lvlal, cc;
      integer n, i;
      ed := exfrdata_mkblank();
      varl := cl_fvarl phi;
      oo := setkorder varl;
      n := length varl;
      lvlal := for each v in reverse varl collect
	 v . (i := i + 1);
      cc := mkvect n;
      exfr_splitphi(phi, lvlal, cc);
      exfrdata_putphi(ed, phi);
      exfrdata_putvarl(ed, varl);
      exfrdata_putn(ed, n);
      exfrdata_putoldorder(ed, oo);
      exfrdata_putlvlal(ed, lvlal);
      exfrdata_putcc(ed, cc);
      exfrdata_putasgv(ed, mkvect n);
      exfrdata_puttrlv(ed, mkvect n);
      exfrdata_putivlv(ed, mkvect n);
      exfrdata_putlevel(ed, 1);
      exfrdata_putmode(ed, nil);
      exfrdata_puttarget(ed, nil);
      return ed
   end;

asserted procedure exfr_splitphi(phi: QfFormula, lvlal: AList, cc: Atom): Any;
   % [phi] is a quantifier-free formula in CNF without negation. [cc] is changed
   % in place.
   begin scalar w;
      integer lvl;
      assert(rl_op phi eq 'and);
      for each c in rl_argn phi do <<
	 assert(rl_op c eq 'or);
	 lvl := cdr atsoc(car cl_fvarl c, lvlal);
	 push(rl_argn c, getv(cc, lvl))
      >>
   end;

%DS
% State ::= ('rl_state, Mode, Target, Trail, ClauseList, VariableList, Level)
% Mode ::= 'models | 'vdash | nil
% Target ::= Clause | nil
% Clause ::= ('rl_clause, nil | t, Level, LiteralList) (* nil means input, t means learned *)
% Level ::= Integer
% Trail ::= TrailElementList
% TrailElement ::= TrailLit | VarAss
% TrailLit ::= PropLit | DecLit
% PropLit ::= ('rl_proplit, Clause | CadInput, AtomicFormula) (* AtomicFormula occurs in Clause *)
% DecLit ::= ('rl_declit, nil, AtomicFormula)
% VarAss ::= ('rl_varass, Kernel, Anu)

struct State asserted by StateP;
struct Trail asserted by listp;
struct Clause asserted by ClauseP;
struct TrailLit asserted by TrailLitP;

procedure StateP(s);
   eqcar(s, 'rl_state);

procedure ClauseP(s);
   eqcar(s, 'rl_clause);

procedure TrailLitP(s);
   eqcar(s, 'rl_proplit) or eqcar(s, 'rl_declit);

asserted procedure state_mk(m: Id, ta: Any, trl: Trail, cl: List, vl: List, n: Integer): State;
   % [m] is 'models, 'vdash or nil; [ta] is Clause or nil; [trl] is
   % TrailElementList; [cl] is ClauseList; [vl] is a VariableList containing
   % unassigned variables; [n] is Level. Returns a state.
   {'rl_state, m, ta, trl, cl, vl, n};

asserted procedure state_mode(s: State): Id;
   nth(s, 2);

asserted procedure state_target(s: State): Clause;
   nth(s, 3);

asserted procedure state_trail(s: State): Trail;
   nth(s, 4);

asserted procedure state_cl(s: State): List;
   nth(s, 5);

asserted procedure state_vl(s: State): List;
   nth(s, 6);

asserted procedure state_level(s: State): Integer;
   nth(s, 7);

asserted procedure clause_mk(tg: Boolean, n: Integer, ll: List): Clause;
   % [tg] is [nil] when it is an input clause; [n] is the level of the clause;
   % [ll] is the list of literals
   {'rl_clause, tg, n, ll};

asserted procedure clause_tg(c: Clause): Boolean;
   nth(c, 2);

asserted procedure clause_level(c: Clause): Integer;
   nth(c, 3);

asserted procedure clause_ll(c: Clause): List;
   nth(c, 4);

asserted procedure trail_push(tre: Any, trl: Trail): Trail;
   tre . trl;

asserted procedure trail_pop(trl: Trail): DottedPair;
   trl;

asserted procedure trail_extract(trl: Trail): DottedPair;
   % Returns a pair [assl . litl], where [assl] is the List of all assignments
   % of [trl] and [litl] is the List of all literals in [trl] after the last
   % assignment.
   begin scalar tre, assl, litl;
      trl := reverse trl;
      while trl do <<
	 tre := pop trl;
	 if tre_varassp tre then <<
	    push(tre, assl);
	    litl := nil
	 >> else  % we know [tre_litp tre]
	    push(tre, litl)
      >>;
      return reversip assl . reversip litl
   end;

asserted procedure tlit_mk(tag: Id, e: Any, atf: OfsfAtf): TrailLit;
   % [tag] is 'rl_declit or 'rl_proplit; [e] is a Clause or CadInput or [nil];
   % [atf] is an atomic formula. Returns TrailLit.
   {tag, e, atf};

asserted procedure tlit_tag(tl: TrailLit): Id;
   nth(tl, 1);

asserted procedure tlit_e(tl: TrailLit): Any;
   nth(tl, 2);

asserted procedure tlit_atf(tl: TrailLit): OfsfAtf;
   nth(tl, 3);

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

inline procedure varass_mk(x, anu);
   {'rl_varass, x, anu};

inline procedure varass_x(va);
   nth(va, 2);

inline procedure varass_value(va);
   nth(va, 3);

asserted procedure ofsf_selectClause(s: State): State;
   begin scalar cl, lv, trl, w, sc;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      cl := state_cl s;
      lv := state_level s;
      trl := state_trail s;
      while cl do <<
	 w := pop cl;
	 if eqn(lv, clause_level w) and ofsf_undefp(w, trl) then <<
	    cl := nil;
	    sc := w
	 >>
      >>;
      if null sc then
	 return nil;
      % Rule is applicable.
      return state_mk('models, sc, trl, state_cl s, state_vl s, lv)
   end;

asserted procedure ofsf_conflict(s: State): State;
   begin scalar cl, lv, trl, w, cc;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      cl := state_cl s;
      lv := state_level s;
      trl := state_trail s;
      while cl do <<
	 w := pop cl;
	 % an imporant fact: Should we check lv = clause_level w or lv >=
	 % clause_level w? This depends on the order of rule applications.
	 if (lv >= clause_level w) and ofsf_value(w, trl) eq 'false then <<
	    cl := nil;
	    cc := w
	 >>
      >>;
      if not cc then
	 return nil;
      % Rule is applicable.
      return state_mk('vdash, cc, trl, state_cl s, state_vl s, lv)
   end;

asserted procedure ofsf_sat(s: State): State;
   begin scalar eql;
      if state_mode s or state_vl s then
	 return nil;
      eql := car trail_extract state_trail s;
      return state_mk('sat, nil, eql, nil, state_vl s, state_level s + 1)
   end;

asserted procedure ofsf_liftLevel(s: State): State;
   begin scalar vl, xk, ivl, alpha;
      if state_mode s then
	 return nil;
      vl := state_vl s;
      xk := pop vl;
      ivl := ofsf_feasible state_trail s;
      if null ivl then
	 return nil;
      alpha := ofsf_chooseFromIv(car ivl, xk);
      state_mk(nil, nil,
	 trail_push(state_trail s, varass_mk(xk, alpha)),
 	 state_cl s, vl, state_level s + 1)
   end;

asserted procedure ofsf_feasible(trl: Trail): AnuIntervalList;
   % [trl] is a well-formed trail. Returns a finite list of intervals with Anu
   % bounds.
   begin scalar assl, litl, atf, fl, gl, assal;
      assl . litl := trail_extract trl;
      assal := for each a in assl collect
	 varass_x a . varass_value a;
      for each lit in litl do <<
	 atf := tlit_atf lit;
	 if ofsf_op atf eq 'equal then
	    push(atf, fl)
      	 else
	    push(atf, gl)
      >>;
      fl := for each f in fl collect
	 ofsf_anusubf(ofsf_arg2l f, assal) . 'equal;
      gl := for each g in gl collect
	 ofsf_anusubf(ofsf_arg2l g, assal) . ofsf_op g;
      return if fl then
	 ofsf_feasible1(fl, gl)
      else
	 ofsf_feasible2 gl
   end;

asserted procedure ofsf_feasible1(fl: List, gl: List): AnuIntervalList;
   % [fl] is a non-empty list of pairs [f . 'equal] where [f] is an Aex; [gl] is
   % a list of pairs [f . op] where [f] is an Aex and [op] is an ofsf operator
   % different from ['equal].
   begin scalar xk, f;
      f := car pop fl;
      xk := aex_mvar f;
      return for each anu in aex_findroots(f, xk) join
	 if ofsf_feasible11(anu, xk, fl, gl) then
	    {anupt_mk anu};
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
	 if not aex_evalop(aex_bind(g, xk, anu), op) then
	    cnt := nil
      >>;
      return cnt
   end;

asserted procedure ofsf_feasible2(gl: List): AnuIntervalList;
   % [gl] is a list of pairs [f . op] where [f] is an Aex and [op] is an ofsf
   % operator different from ['equal].
   begin scalar ivl, xk, g, givl, rel;
      ivl := {anusp_mk('anusp_open, 'minf, 'anusp_open, 'pinf)};
      if null gl then
	 return ivl;
      xk := aex_mvar caar gl;
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

asserted procedure ofsf_updivl(ivl: AnuIntervalList, givl: AnuIntervalList): AnuIntervalList;
   % Update interval lists.
   begin scalar iv, res1, res2;
      if not ivl then
	 return nil;
      iv := pop ivl;
      res1 := ofsf_ivcutl(iv, givl);
      res2 := ofsf_updivl(ivl, givl);
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

asserted procedure ofsf_forget(s: State): State;
   begin scalar tcl, tc, cnt, ntcl;
      if state_mode s then
	 return nil;
      % TODO: Is there a strategy for selecting c?
      tcl := state_cl s;
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
   % [c] is a Clause; [trl] is a Trail
   begin scalar avl, at, defp;
      avl := for each tre in trl join
	 if tre_varassp tre then
	    {varass_x tre};
      defp := t; while defp and c do <<
	 at := pop c;
	 if not lto_subsetq(ofsf_varlat at, avl) then
	    defp := nil
      >>;
      return not defp
   end;

asserted procedure ofsf_value(c: Clause, trl: Trail): Id;
   begin scalar eqal, cnt, at;
      % TODO: This procedure does not work. Fix it so that Boolean propagation
      % is taken into account.
      if ofsf_undefp(c, trl) then
      	 return 'undef;
      eqal := for each tre in trl join
	 if tre_varassp tre then
	    {varass_x tre . varass_value tre};
      cnt := t; while cnt and c do <<
	 at := pop c;
	 if ofsf_valueat(at, eqal) eq 'true then
	    cnt := nil
      >>;
      return if cnt then 'false else 'true
   end;

asserted procedure ofsf_valueat(at: OfsfAtf, eqal: Alist): Id;
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
   % [al] is an Alist, where the keys are kernels and the values are Anu.
   begin scalar aex;
      aex := aex_fromsf f;
      for each pr in al do
	 aex := aex_bind(aex, car pr, cdr pr);
      return aex
   end;

asserted procedure ofsf_chooseFromIv(iv: AnuInterval, x: Kernel): Anu;
   % [givl] is an interval with GAnu endpoints. Returns an Anu (with [mvar x])
   % contained in the interval.
   begin scalar lt, lb, ut, ub, rl, ru;
      % TODO: Pick a nice Anu.
      if anuiv_ptp iv then
	 return anupt_anu iv;
      % we know [anuiv_spp iv]
      lt := anusp_lt iv;
      lb := anusp_lb iv;
      if lt eq 'anusp_closed then
	 return lb;
      ut := anusp_ut iv;
      ub := anusp_ub iv;
      if ut eq 'anusp_closed then
	 return ub;
      % we know [lt eq 'anusp_open and ut eq 'anusp_open]
      if lb eq 'minf then <<
	 if ub eq 'pinf then
	    return anu_fromrat(x, nil ./ 1);
	 return anu_fromrat(x, iv_lb anu_iv ub)
      >>;
      if ub eq 'pinf then
	 return anu_fromrat(x, iv_rb anu_iv lb);
      rl := iv_rb anu_iv lb;
      ru := iv_lb anu_iv ub;
      assert(rat_leq(rl, ru));
      return anu_fromrat(x, rl)
   end;

asserted procedure ofsf_decideLiteral(s: State): State;
   begin scalar c, trl, atf;
      if state_mode s neq 'models then
	 return nil;
      c := state_target s;
      trl := state_trail s;
      atf := ofsf_pickCompatAtf(c, trl);
      trl := trail_push(tlit_mk('rl_declit, c, atf), trl);
      return state_mk(nil, nil, trl, state_cl s, state_vl s, state_level s)
   end;

asserted procedure ofsf_pickCompatAtf(c: Clause, trl: Trail): OfsfAtf;
   begin scalar d, atf;
      c . d := ofsf_undefAtf(c, trl);
      if null d then
	 return nil;
      atf := car d;
      c . d := ofsf_undefAtf(cdr d, trl);
      if null d then
	 return nil;
      if ofsf_compatible(atf, trl) then
      	 return atf
   end;

asserted procedure ofsf_undefAtf(c: Clause, trl: Trail): DottedPair;
   % The clause [c] has value ['undef]. Returns a pair [c1 . c2] of clauses,
   % where [ofsf_value(c1, trl)] has value ['false] and the first atom of [c2]
   % has value ['undef].
   begin scalar cnt, atf, v, d;
      cnt := t; while cnt and c do <<
	 atf := pop c;
	 v := ofsf_value({atf}, trl);
	 assert(v neq 'true);
	 if v eq 'undef then <<
	    cnt := nil;
	    push(atf, c)
	 >> else
	    push(atf, d)
      >>;
      return reversip d . c
   end;

asserted procedure ofsf_compatible(atf: OfsfAtf, trl: Trail): ExtraBoolean;
   % TODO: Write a more efficient version.
   ofsf_feasible trail_push(declit_mk atf, trl);

asserted procedure ofsf_BPropagate(s: State): State;
   begin scalar c, trl, atf;
      if state_mode s neq 'models then
	 return nil;
      c := state_target s;
      trl := state_trail s;
      atf := ofsf_pickBPropagatedAtf(c, trl);
      trl := trail_push(tlit_mk('rl_proplit, c, atf), trl);
      return state_mk(nil, nil, trl, state_cl s, state_vl s, state_level s)
   end;

asserted procedure ofsf_pickBPropagatedAtf(c: Clause, trl: Trail): OfsfAtf;
   begin scalar c, d, atf;
      c . d := ofsf_undefAtf(c, trl);
      atf := car d;
      c . d := ofsf_undefAtf(cdr d, trl);
      if d then
	 return nil;
      return atf
   end;

asserted procedure ofsf_RPropagate(s: State): State;
   begin scalar c, trl, atf, e;
      if state_mode s neq 'models then
	 return nil;
      c := state_target s;
      trl := state_trail s;
      atf := ofsf_incompatibleAtf(c, trl);
      if not atf then
	 return nil;
      e := ofsf_explain(atf, trl);
      trl := trail_push(tlit_mk('rl_proplit, e, atf), trl);
      return state_mk(nil, nil, trl, state_cl s, state_vl s, state_level s)
   end;

asserted procedure ofsf_incompatibleAtf(c: Clause, trl: Trail): DottedPair;
   % The clause [c] has value ['undef]. Returns a pair [c1 . c2] of clauses,
   % where [ofsf_value(c1, trl)] has value ['false] and the first atom of [c2]
   % has value ['undef] and the negation of it is incompatible with [trl].
   begin scalar cnt, d, atf;
      cnt := t; while cnt and c do <<
      	 c . d := ofsf_undefAtf(c, trl);
      	 atf := car d;
      	 if not ofsf_compatible(ofsf_negateat atf, trl) then
      	    cnt := nil
      	 else
      	    c := cdr d
      >>;
      return if cnt then nil else atf
   end;

asserted procedure ofsf_explain(atf: OfsfAtf, trl: Trail): Clause;
   begin
      return {atf, trl}
   end;

asserted procedure ganu_evalf(ganu: GAnu);
   % Returns Floating or [minf] or [pinf].
   if ganu memq '(minf pinf) then ganu else anu_evalf ganu;

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
