% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2014 M. Kosta, T. Sturm
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

module vsl;
% Virtual substitution with learning, linear case.

% VslState ::= ('vslstate, list of input constraints, VslStackElemL, list of negative lemmas, property list)
% VslStackElem ::= ('vslstackelem, Kernel, SQ | 'pinf | 'minf | 'bottom | nil, OfsfAtf | nil, OfsfAtfL, OfsfQfFormulaL)

struct Void;
struct VslState asserted by VslStateP;
struct VslStackElem asserted by VslStackElemP; %List4;
struct VslNegLemma asserted by VslNegLemmaP;
struct VslNegLemmaL asserted by listp;

procedure VslStateP(s);
   eqcar(s, 'vslstate);

procedure VslStackElemP(s);
   eqcar(s, 'vslstackelem);

procedure VslNegLemmaP(s);
   listp s and eqcar(s, 'or);

asserted procedure vsls_il(s: VslState): OfsfAtfL;
   nth(s, 2);

asserted procedure vsls_setil(s: VslState, il: OfsfAtfL): Void;
   nth(s, 2) := il;

asserted procedure vsls_sl(s: VslState): List;
   nth(s, 3);

asserted procedure vsls_setsl(s: VslState, sl: List): Void;
   nth(s, 3) := sl;

asserted procedure vsls_nl(s: VslState): List;
   nth(s, 4);

asserted procedure vsls_setnl(s: VslState, nl: List): Void;
   nth(s, 4) := nl;

asserted procedure vsls_prop(s: VslState): AList;
   nth(s, 5);

asserted procedure vsls_put(s: VslState, key: Id, value: Any): Any;
   begin scalar h, w;
      h := cdddr cdr s;
      w := atsoc(key, car h);
      if w then
	 cdr w := value
      else
	 car h := (key . value) . car h;
      return value
   end;

asserted procedure vsls_kvget(s: VslState, key: Id): Any;
   % Note that in contrast to the Lisp get we obtain not only the value, but the
   % key value pair.
   atsoc(key, vsls_prop s);

asserted procedure vsls_mk(il: OfsfAtfL, sal: List, nl: VslNegLemmaL): VslState;
   {'vslstate, il, sal, nl, nil};

switch vslsprintil;
switch vslsprintsl;
switch vslsprintnl;

off1 'vslsprintil;
on1 'vslsprintsl;
on1 'vslsprintnl;

asserted procedure vsls_print(s: VslState): Void;
   begin scalar sl, il, nl;
      if !*vslsprintil then <<
	 ioto_prin2 "   input: ";
	 il := vsls_il s;
	 if null il then
	    ioto_prin2t "nil"
	 else <<
	    ioto_prin2t {"|", ioto_form2str rl_prepfof car il};
	    for each atf in cdr il do <<
      	       ioto_tprin2 "          |";
	       ioto_prin2t ioto_form2str rl_prepfof atf
	    >>
	 >>
      >>;
      if !*vslsprintsl then <<
      	 ioto_prin2 "   stack: ";
      	 sl := vsls_sl s;
      	 if null sl then <<
	    ioto_prin2t "nil";
	    return
      	 >> else <<
      	    vslse_print car sl;
      	    for each se in cdr sl do <<
      	       ioto_tprin2 "          ";
	       vslse_print se
      	    >>
	 >>
      >>;
      if !*vslsprintnl then <<
	 ioto_prin2 "  lemmas: ";
	 nl := vsls_nl s;
	 if null nl then
	    ioto_prin2t "nil"
	 else <<
	    ioto_prin2t {"|", ioto_form2str rl_prepfof rl_smkn('or, car nl)};
	    for each l in cdr nl do <<
      	       ioto_tprin2 "          |";
	       ioto_prin2t ioto_form2str rl_prepfof rl_smkn('or, l)
	    >>
	 >>
      >>
   end;

asserted procedure vslse_v(se: VslStackElem): Kernel;
   nth(se, 2);

asserted procedure vslse_eterm(se: VslStackElem): Any;
   nth(se, 3);

asserted procedure vslse_orig(se: VslStackElem): Any;
   nth(se, 4);

asserted procedure vslse_ils(se: VslStackElem): List;
   nth(se, 5);

asserted procedure vslse_nls(se: VslStackElem): List;
   nth(se, 6);

asserted procedure vslse_mk(v: Kernel, e: Any, o: Any, i: List, l: List): VslStackElem;
   {'vslstackelem, v, e, o, i, l};

switch vslseprintnls;

on1 'vslseprintnls;

asserted procedure vslse_print(se: VslStackElem): Any;
   begin scalar nls;
      if !*vslseprintnls then <<
	 ioto_prin2 "|  nls = ";
	 nls := vslse_nls se;
	 if null nls then
	    ioto_prin2t "nil"
	 else <<
	    ioto_prin2t {"|", ioto_form2str rl_prepfof rl_smkn('or, car nls)};
	    for each atf in cdr nls do <<
	       ioto_prin2 "        ";
	       ioto_prin2t {"|", ioto_form2str rl_prepfof rl_smkn('or, atf)}
	    >>
	 >>;
	 ioto_tprin2 "          "
      >>;
      ioto_prin2t {"|", vslse_v se, "=",
      	 ioto_form2str if idp vslse_eterm se then vslse_eterm se else prepsq vslse_eterm se};
   end;

fluid '(rlsolves!*);
fluid '(rlnnalpha!*);

asserted procedure vsl_vsl(inputl: List): QfFormula;
   begin %scalar !*rlsiatadv,!*rldavgcd;
      scalar state, freevarl, sl, kgeq0;
      integer rlnnalpha!*;
      integer rlsolves!*;
      integer substc;
      state := vsls_mk(vsl_normalize inputl, nil, nil);
      % vsl_normalize does not change the contained variables.
      if !*rlverbose and !*rlvsllog then <<
	 ioto_tprin2t "<normalize>";
	 vsls_print state
      >>;
      while not rl_tvalp car vsls_il state do <<
	 freevarl := vsl_freevarl state;
	 if freevarl then
	    vsl_decide(state, freevarl);
	 vsl_substitute state;
	 sl := vsls_sl state;
      	 if !*rlverbose and not vslse_eoesetp car sl then
	    substc := substc + 1;
	 if vslse_eoesetp car sl then
	    if cdr sl then
	       vsl_ibacktrack state
	    else
	       vsl_fail state
	 else if (kgeq0 := vsl_tinconsistentp state) then <<
	    if !*rlvsllearn then
	       vsl_aconflict(state, kgeq0);
	    vsl_lbacktrack state
	 >> else if null vsl_freevarl state then
	    vsl_succeed state
      >>;
      if !*rlverbose then <<
	 ioto_tprin2t {"Number of computed nodes: ", substc};
	 ioto_tprin2t {"Number of solves: ", rlsolves!*};
	 ioto_tprin2t {"Number of solves without negative alpha: ", rlnnalpha!*}
      >>;
      return car vsls_il state
   end;

asserted procedure vsl_normalize(inputl: List): List;
   begin scalar op;
      return for each atf in inputl join <<
      	 op := ofsf_op atf;
	 if op eq 'geq then
	    {atf}
	 else if op eq 'leq then
	    {ofsf_0mk2('geq, negf ofsf_arg2l atf)}
	 else if op eq 'equal then
	    {ofsf_0mk2('geq, negf ofsf_arg2l atf),
	       ofsf_0mk2('geq, ofsf_arg2l atf)}
	 else
	    rederr {"Illegal relation", op, "in", atf}
      >>
   end;

asserted procedure vsl_freevarl(s: VslState): List;
   cl_fvarl rl_smkn('and, vsl_ils s);

asserted procedure vslse_eoesetp(se: VslStackElem): ExtraBoolean;
   % End of eset predicate.
   vslse_eterm se eq 'bottom;

switch vslfast;

asserted procedure vsl_eterm(s: VslState, x: Kernel): VslStackElem;
   begin scalar eset, sb, b, borig, lhs, q, nils, nnl, nnlem, ap;
      eset := vsls_esetget(s, x);
      sb := vslse_mk(x, 'bottom, nil, nil, nil);
      while eset and vslse_eterm sb eq 'bottom do <<
      	 b . borig := pop eset;
	 if vsl_infp b then <<
	    % We know that b is admissible.
	    nils := for each atf in vsl_ils s collect
	       vsl_subati(atf, x, b);
	    nnl := for each nlem in vsl_nls s join <<
	       nnlem := vsl_subnlemi(nlem, x, b);
	       assert(not null nnlem);
	       if ofsf_arg2l car nnlem neq 1 then
		  {nnlem}
	    >>;
      	    sb := vslse_mk(x, b, nil, nils, nnl)
	 >> else <<
	    lhs := ofsf_arg2l b;
	    % lhs is already reordered w.r.t. x.
	    q := quotsq(!*f2q negf red lhs, !*f2q lc lhs);
	    ap := vsl_admissiblep(vsl_nls s, x, q);
	    if ap then <<
	       if !*vslfast then
		  nils := vsl_subilssq(s, vsl_ils s, x, q)
	       else
	       	  nils := for each atf in vsl_ils s collect
	       	     vsl_subatsq(atf, x, q);
      	       sb := vslse_mk(x, q, borig, nils, car ap)
	    >> else if !*rlverbose and !*rlvsllog then
	       ioto_tprin2t {"   dropped test term by learning: ", x, "=",
	       	  ioto_form2str prepsq q}
	 >>
      >>;
      vsls_esetput(s, x, eset);
      return sb
   end;

asserted procedure vsl_infp(s: Any): Boolean;
   s eq 'minf or s eq 'pinf;

asserted procedure vsls_esetget(s: VslState, x: Kernel): List;
   begin scalar w;
      w := vsls_kvget(s, 'eset);
      assert(w);
      w := atsoc(x, cdr w);
      assert(w);
      return cdr w
   end;

asserted procedure vsls_esetput(s: VslState, x: Kernel, eset: List): List;
   begin scalar w, esetal;
      w := vsls_kvget(s, 'eset);
      if null w then
	 return vsls_put(s, 'eset, {x . eset});
      esetal := cdr w;
      w := atsoc(x, esetal);
      if null w then
	 return vsls_put(s, 'eset, (x . eset) . esetal);
      cdr w := eset;
      return eset
   end;

asserted procedure vsl_eset(s: VslState, x: Kernel): List;
   begin scalar il, borig, lhs, b, lbl, ubl;
      il := vsls_il s;
      for each b in vsl_ils s do <<
	 borig := pop il;
	 lhs := sfto_reorder(sfto_dprpartksf ofsf_arg2l b, x);
	 if not domainp lhs and mvar lhs eq x then <<
	    b := ofsf_0mk2('geq, lhs);
	    if lc lhs > 0 then
	       (if not assoc(b, lbl) then
	       	  push(b . borig, lbl))
	    else
	       if not assoc(b, ubl) then
		  push(b . borig, ubl)
	 >>
      >>;
      if null lbl and null ubl then
	 return nil;
      return vsl_eset1(lbl, ubl)
   end;

asserted procedure vsl_eset1(lbl: List, ubl: List): List;
   % We have to think about 'inf and 'minf. Maybe there are strategies for the
   % case that length lbl = length ubl.
   if null lbl then
      {'minf . nil}
   else if null ubl then
      {'pinf . nil}
   else if length lbl > length ubl then
      ubl
   else
      lbl;

asserted procedure vsl_ils(s: VslState): List;
   (if sl then vslse_ils car sl else vsls_il s) where sl = vsls_sl s;

asserted procedure vsl_nls(s: VslState): List;
   (if sl then vslse_nls car sl else vsls_nl s) where sl = vsls_sl s;

asserted procedure vsl_admissiblep(nls: List, x: Kernel, q: SQ): ExtraBoolean;
   % Returns nil or nls/(x=q) as a singleton
   begin scalar c, nlem, nnls;
      if not !*rlvsllearn then
	 return {nil};
      c := t; while c and nls do <<  % scanning conjunction
	 nlem := vsl_subnlemsq(pop nls, x, q);
	 if null nlem or ofsf_arg2l car nlem neq 1 then
	    % [nlem] is certainly false or contains variables.
	    if null nlem then  % [nlem] is certainly false.
	       c := nil
	    else  % [nlem] contains variables.
	       push(nlem, nnls)
	 % else [nlem] is certainly true, do nothing.
      >>;
      return if c then {reversip nnls}
   end;

asserted procedure vsl_substack(f: QfFormula, sl: List): QfFormula;
   % [sl] is a stack growing to the left. We take care that the substitutions in
   % [sl] are carried out from the right to the left.
   cl_apply2ats1(f, function vsl_substackat, {sl});

asserted procedure vsl_substackat(atf: OfsfAtf, sl: List): OfsfAtf;
   if null sl then
      atf
   else
      vsl_subat(vsl_substackat(atf, cdr sl), vslse_v car sl, vslse_eterm car sl);

asserted procedure vsl_subnlem(nlem: List, x: Kernel, eterm: Any): OfsfAtf;
   if eterm eq 'minf or eterm eq 'pinf then
      vsl_subnlemi(nlem, x, eterm)
   else
      vsl_subnlemsq(nlem, x, eterm);

asserted procedure vsl_subnlemi(nlem: List, x: Kernel, inf: Id): List;
   begin scalar c, atf, nnlem;
      c := t; while c and nlem do <<
	 atf := pop nlem;
	 if not sfto_kmemberf(x, ofsf_arg2l atf) then
	    push(atf, nnlem)
	 else
	    c := nil
      >>;
      return if c then reversip nnlem else {ofsf_0mk2('neq, 1)}
   end;

asserted procedure vsl_subnlemsq(nlem: List, x: Kernel, q: SQ): List;
   begin scalar c, atf, nnlem, lhs;
      c := t; while c and nlem do <<  % scanning disjunction of neqs
      	 atf := vsl_subatsq(pop nlem, x, q);
      	 lhs := ofsf_arg2l atf;
      	 if not null lhs then  % This disjunction is certainly true or contains variables.
	    if domainp lhs then <<  % This disjunction is certainly true.
	       nnlem := {ofsf_0mk2('neq, 1)};
	       c := nil
	    >> else
	       push(atf, nnlem)
      >>;
      return reversip nnlem
   end;

asserted procedure vsl_subat(atf: OfsfAtf, x: Kernel, eterm: Any): OfsfAtf;
   <<
      assert(eqcar(atf, 'geq));
      if eterm eq 'minf or eterm eq 'pinf then
	 vsl_subati(atf, x, eterm)
      else
	 vsl_subatsq(atf, x, eterm)
   >>;

asserted procedure vsl_subati(atf: OfsfAtf, x: Kernel, inf: Id): OfsfAtf;
   begin scalar res, lhs;
      assert(eqcar(atf, 'geq));
      lhs := ofsf_arg2l atf;
      while not res and not domainp lhs do <<
	 if mvar lhs eq x then <<
	    % We semantically know that our inf cannot violate any bound.
	    assert(vsl_subimatch(lc lhs, inf));
	    res := ofsf_0mk2('geq, nil)
	 >>;
	 lhs := red lhs
      >>;
      return res or atf
   end;

asserted procedure vsl_subimatch(f: SF, b: Id): ExtraBoolean;
   minusf f and b eq 'minf or not minusf f and b eq 'pinf;

asserted procedure vsl_subilssq(s: VslState, ils: List, x: Kernel, q: SQ);
   begin scalar c, il, orig, atf, natf, nlhs, nils;
      il := vsls_il s;
      c := t; while c and ils do <<
	 atf := pop ils;
	 orig := pop il;
	 natf := vsl_subatsq(atf, x, q);
	 nlhs := ofsf_arg2l natf;
	 if not domainp nlhs or not minusf nlhs then
	    push(natf, nils)
	 else <<
	    c := nil
	 >>
      >>;
      vsls_put(s, 'inconsistent, if null c then orig);
      return reversip nils
   end;

asserted procedure vsl_subatsq(atf: OfsfAtf, x: Kernel, q: SQ): OfsfAtf;
   ofsf_0mk2(ofsf_op atf, numr ofsf_subf(ofsf_arg2l atf, x, q));

asserted procedure vsl_decide(s: VslState, freevarl: List): Void;
   begin scalar il, lhsl, w, lhs, a, varl, v;
      if !*rlverbose and !*rlvsllog then
      	 ioto_tprin2 "<decide>";
      % Try Gauss.
      il := vsls_il s;
      lhsl := for each b in vsl_ils s collect
	 ofsf_arg2l b;
      while lhsl and not w do <<
	 lhs := negf pop lhsl;
	 a := pop il;
	 if not domainp lhs and lhs member lhsl then
	    w := {ofsf_0mk2('geq, lhs) . a}
      >>;
      if w then <<
	 if !*rlverbose and !*rlvsllog then
	    ioto_prin2 " *gauss*";
	 v := mvar lhs;
	 vsls_esetput(s, v, w)
      >> else <<
      	 v . varl := vsl_varsel(freevarl, vsl_ils s);
      	 vsls_esetput(s, v, vsl_eset(s, v))
      >>;
      vsls_setsl(s, vslse_mk(v, nil, nil, nil, nil) . vsls_sl s);
      if !*rlverbose and !*rlvsllog then <<
	 terpri();
	 vsls_print s
      >>
   end;

asserted procedure vsl_undecidedp(s: VslState): ExtraBoolean;
   begin scalar sl;
      sl := vsls_sl s;
      return null sl or not null vslse_eterm car sl
   end;

asserted procedure vsl_varsel(varl: List, ils: List): DottedPair;
   begin scalar bt, bestv; integer ubn, lbn, bestn, thisn;
      assert(not null varl);
      assert(not null ils);
      if not !*rlqevarsel then
	 return varl;  % car varl . cdr varl
      bestn := -1;
      for each x in varl do <<
      	 for each atf in ils do <<
	    bt := vsl_boundtype(atf, x);
	    if bt eq 'ub then
	       ubn := ubn + 1
	    else if bt eq 'lb then
	       lbn := lbn + 1
      	 >>;
	 thisn := min(ubn, lbn);
	 if eqn(bestn, -1) or thisn < bestn then <<
	    bestn := thisn;
	    bestv := x
	 >>;
	 ubn := 0;
	 lbn := 0
      >>;
      return bestv . delq(bestv, varl)
   end;

asserted procedure vsl_boundtype(atf: OfsfAtf, x: Kernel): Id;
   vsl_boundtype1(ofsf_arg2l atf, x);

asserted procedure vsl_boundtype1(f: SF, x: Kernel): Id;
   if domainp f then
      nil
   else if mvar f eq x then
      if minusf lc f then
	 'ub
      else
	 'lb
   else
      vsl_boundtype1(red f, x);

asserted procedure vsl_substitute(s: VslState): Void;
   begin scalar sl, v;
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2 "<substitute>";
      sl := vsls_sl s;
      assert(sl);
      v := vslse_v pop sl;
      vsls_setsl(s, sl);
      push(vsl_eterm(s, v), sl);
      vsls_setsl(s, sl);
      if !*rlverbose and !*rlvsllog then <<
	 terpri();
	 vsls_print s
      >>
   end;

asserted procedure vsl_aconflict(s: VslState, kgeq0: OfsfAtf): Void;
   begin scalar sl, nlem, w;
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2t "<aconflict>";
      sl := vsls_sl s;
      assert(sl);
      % The original constraint is nil with infinity substitutions. Infinity
      % substitutions are not analyzed.
      nlem := vsl_analyze(kgeq0 .
	 for each se in sl collect if (w := vslse_orig se) then w);
      vsls_setnl(s, nlem . vsls_nl s);
      % TODO: Add substituted lemmas into stack.
      if !*rlverbose and !*rlvsllog then
	 ioto_prin2t {"   nlearned: ", ioto_form2str rl_prepfof rl_smkn('or, nlem)}
   end;

asserted procedure vsl_lbacktrack(s: VslState): Void;
   begin scalar nsl, nnlem, rsl, c, se;
      if !*rlverbose and !*rlvsllog then
      	 ioto_tprin2 "<lbacktrack> ";
      if not !*rlvsllearn then <<
	 nsl := vsls_sl s;
	 se := pop nsl;
	 nsl := vslse_mk(vslse_v se, nil, nil, nil, nil) . nsl;
	 vsls_setsl(s, nsl);
	 return
      >>;
      % We now rely on that we really have learned something and that car nl is
      % the newly learned item.
      nnlem := car vsls_nl s;
      rsl := reverse vsls_sl s;
      c := t; while c and rsl do <<
	 se := pop rsl;
	 nnlem := vsl_subnlem(nnlem, vslse_v se, vslse_eterm se);
	 if nnlem then
	    push(vslse_mk(vslse_v se, vslse_eterm se, vslse_orig se, vslse_ils se,
	       nnlem . vslse_nls se), nsl)
	 else  % certainly "false"
	    c := nil
      >>;
      assert(null c);  % At least the top stack entry must be inconsistent.
      push(vslse_mk(vslse_v se, nil, nil, nil, nil), nsl);
      vsls_setsl(s, nsl);
      if !*rlverbose and !*rlvsllog then <<
	 ioto_prin2 {"(", length rsl + 1, ")"};
	 vsls_print s
      >>
   end;

asserted procedure vsl_tinconsistentp(s: VslState): ExtraBoolean;
   begin scalar il, ils, c, w, slhs;
      if !*vslfast then
	 return cdr vsls_kvget(s, 'inconsistent);
      il := vsls_il s;
      ils := vsl_ils s;
      c := t; while c and ils do <<
	 w := pop il;
	 slhs := ofsf_arg2l pop ils;  % This is an SF.
	 if domainp slhs and minusf slhs then
	    c := nil
      >>;
      return if not c then w
   end;

asserted procedure vsl_analyze(l: List): List;
   begin scalar xl, y, yl, hugo, rhugo, sysl, solal, w, nlearnl;
      xl := cl_fvarl rl_smkn('and, l);
      for each c in l do <<
	 y := gensym();
	 push(y, yl);
      	 hugo := addf(hugo, multf(!*k2f y, ofsf_arg2l c))
      >>;
      rhugo := sfto_lreorder(hugo, xl);
      while not domainp rhugo and mvar rhugo memq xl do <<
	 push(lc rhugo, sysl);
	 rhugo := red rhugo
      >>;
      push(addf(rhugo, 1), sysl);
      solal := vsl_solve(sysl, yl);
      hugo := sfto_lreorder(hugo, yl);
      while not domainp hugo do <<
	 w := atsoc(mvar hugo, solal);
	 assert(w);
	 if minusf numr cdr w then
	    push(ofsf_0mk2('neq, lc hugo), nlearnl);
	 hugo := red hugo
      >>;
      if !*rlverbose then <<
	 rlsolves!* := rlsolves!* + 1;
 	 if null nlearnl then
	    rlnnalpha!* := rlnnalpha!* + 1
      >>;
      return nlearnl
   end;

asserted procedure vsl_solve(sysl: List, yl: List): AList;
   begin scalar tsl, vl, sl, plugal, subal, resal, s;
      yl := sort(yl, 'ordop);
      tsl := if !*cramer then solvecramer(sysl, yl) else solvebareiss(sysl, yl);
      assert(car tsl);
      tsl := cdr tsl;
      assert(null cdr tsl);
      tsl := car tsl;
      vl := cadr tsl;
      sl := car tsl;
      plugal := vsl_plugin lto_setminus(yl, vl);
      subal := for each pr in plugal collect
	 car pr . prepsq cdr pr;
      resal := plugal;
      for each v in vl do <<
	 s := subsq(pop sl, subal);
	 resal := (v . s) . resal
      >>;
      return sort(resal, function(lambda(x,y); ordop(car x, car y)))
   end;

asserted procedure vsl_plugin(yl: Kernel): AList;
   for each y in yl collect
      y . (nil ./ 1);

asserted procedure vsl_ibacktrack(s: VslState): Void;
   begin scalar sl, se;
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2t "<ibacktrack>";
      sl := vsls_sl s;
      assert(sl and cdr sl);
      pop sl;
      se := pop sl;
      vsls_setsl(s, vslse_mk(vslse_v se, nil, nil, nil, nil) . sl);
      if !*rlverbose and !*rlvsllog then
	 vsls_print s
   end;

asserted procedure vsl_fail(s: VslState): Void;
   <<
      if !*rlverbose and !*rlvsllog then
      	 ioto_tprin2t "<fail>";
      vsls_setil(s, {'false})
   >>;

asserted procedure vsl_succeed(s: VslState): Void;
   begin scalar ils;
      if !*rlverbose and !*rlvsllog then <<
      	 ioto_tprin2t "<succeed>";
	 ils := vsl_ils s;
	 ioto_tprin2 {"   F/S: |", ioto_form2str rl_prepfof pop ils};
	 for each atf in ils do
            ioto_tprin2t {"        |", ioto_form2str rl_prepfof atf}
      >>;
      vsls_setil(s, {'true})
   end;

if modulep 'debug then load!-package 'debug;

global '(trprinter!*);

trprinter!* := 'vsl_trprinter;

procedure vsl_trprinter(s);
   if eqcar(s, 'vslstate) then
      vsls_print s
   else if eqcar(s, 'vslstackelem) then
      vslse_print s
   else if sqp s then
      printx ioto_form2str prepsq s
   else
      printx s;

algebraic procedure isub(eql, form);
   if eql = {} then
      form
   else
      isub(rest eql, sub(first eql, form));

endmodule;  % vsl

end;  % of file
