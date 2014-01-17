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

% VslState ::= ('vslstate, list of input constraints, VslSubL, list of positive
%   lemmas, list of negative lemmas, property list)
% VslSub ::= (Kernel, SQ | bottom, OfsfAtf | nil)

struct Void;
struct VslState asserted by VslStateP;
struct VslSub asserted by List3;
struct VslNegLemma asserted by VslNegLemmaP;
struct VslNegLemmaL asserted by listp;

procedure VslStateP(s);
   eqcar(s, 'vslstate);

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

asserted procedure vsls_pl(s: VslState): List;
   nth(s, 4);

asserted procedure vsls_setpl(s: VslState, pl: List): Void;
   nth(s, 4) := pl;

asserted procedure vsls_nl(s: VslState): List;
   nth(s, 5);

asserted procedure vsls_setnl(s: VslState, nl: List): Void;
   nth(s, 5) := nl;

asserted procedure vsls_prop(s: VslState): AList;
   nth(s, 6);

asserted procedure vsls_setprop(s: VslState, propl: AList): Void;
   % begin scalar lastpair;
   %    lastpair := cddddr cdr s;
   %    car lastpair := propl;
   %    return propl
   % end;
   nth(s, 6) := propl;

asserted procedure vsls_put(s: VslState, key: Id, value: Any): Any;
   begin scalar w, h;
      h := cddddr cdr s;
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
   atsoc(key, nth(s, 6));

asserted procedure vsls_mk(il: OfsfAtfL, sal: List, pl: OfsfAtfL, nl: VslNegLemmaL): VslState;
   {'vslstate, il, sal, pl, nl, nil};

asserted procedure vsls_print(s: VslState): Void;
   begin scalar sl;
      ioto_tprin2 "   stack: ";
      sl := reverse vsls_sl s;
      for each sub in sl do <<
	 ioto_prin2 {car sub, "=", if idp cadr sub then cadr sub else prepsq cadr sub};
	 if caddr sub then
	    ioto_prin2 {" ", rl_prepfof caddr sub}
      >>;
      ioto_tprin2 "   freevarl: ";
      ioto_prin2 {cdr vsls_kvget(s, 'freevarl)}
   end;

asserted procedure vsl_vsl(inputl: List): QfFormula;
   begin scalar state, sl; integer decisionc;
      state := vsls_mk(vsl_normalize inputl, nil, nil, nil);
      % vsl_normalize does not change the contained variables.
      vsls_put(state, 'freevarl, cl_fvarl rl_mkn('and, inputl));
      if !*rlverbose then
	 vsls_print state;
      while not rl_tvalp car vsls_il state do <<
	 if vsl_undecidedp state then
	    vsl_decide state;
	 decisionc := decisionc + 1;
	 vsl_substitute state;
	 sl := vsls_sl state;
	 if vsl_eoesetp car sl then
	    if cdr sl then
	       vsl_ibacktrack state
	    else
	       vsl_fail state
	 else if vsl_tinconsistentp state then
	    vsl_lbacktrack state
	 else if null vsl_freevarl state then
	    vsl_succeed state
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"Number of decisions: ", decisionc};
      return car vsls_il state
   end;

asserted procedure vsl_freevarl(s: VslState): List;
   begin scalar w;
      w := vsls_kvget(s, 'freevarl);
      assert(w);
      return cdr w
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

asserted procedure vsl_eterm(s: VslState, x: Kernel): VslSub;
   begin scalar eterm;
      repeat
	 eterm := vsl_eterm1(s, x)
      until vsl_eoesetp eterm or vsl_admissiblep(s, eterm, x);
      return eterm
   end;

asserted procedure vsl_eoesetp(eterm: List): ExtraBoolean;
   % End of eset predicate.
   cadr eterm eq 'bottom;

asserted procedure vsl_eterm1(s: VslState, x: Kernel): VslSub;
   begin scalar w, esetal, eset, res;
      w := vsls_kvget(s, 'esets);
      esetal := if w then cdr w;
      w := atsoc(x, esetal);
      if null w then <<  % Elimination set was not computed.
	 eset := vsl_eset(s, x);
	 w := x . eset;
	 push(w, esetal)
      >> else
      	 eset := cdr w;
      if null eset then
	 return {x, 'bottom, nil};
      res := pop eset;
      cdr w := eset;
      vsls_put(s, 'esets, esetal);
      return {x, car res, cdr res}
   end;

asserted procedure vsl_eset(s: VslState, x: Kernel): List;
   begin scalar sl, fs, lhs, ubl, lbl;
      sl := vsls_sl s;
      for each ineq in vsls_il s do <<
	 fs := vsl_substackat(ineq, sl);
	 lhs := sfto_reorder(ofsf_arg2l fs, x);
	 if not domainp lhs and mvar lhs eq x then
	    if lc lhs > 0 then
	       push(lhs . ineq, lbl)
	    else
	       push(lhs . ineq, ubl)
      >>;
      if null lbl and null ubl then
	 return nil;
      return vsl_eset1(lbl, ubl, x)
   end;

asserted procedure vsl_eset1(lbl: List, ubl: List, x: Kernel): List;
   % We have to think about 'inf and 'minf. Maybe there are strategies for the
   % case that length lbl = length ubl.
   if null lbl or (not null ubl and length lbl > length ubl) then
      vsl_eset2(ubl, x)
   else
      vsl_eset2(lbl, x);

asserted procedure vsl_eset2(bl: List, x: Kernel): List;
   for each b in bl collect
      quotsq(!*f2q negf red car b, !*f2q lc car b) . cdr b;

switch vsllearn;

asserted procedure vsl_admissiblep(s: VslState, eterm: DottedPair, x: Kernel): Boolean;
   begin scalar c, etermq, nl, sl;
      if not !*vsllearn then
	 return t;
      etermq := car eterm;
      sl := vsl_sl s;
      nl := vsl_nl s;
      c := t; while c and nl do
	 if cl_simpl(vsl_substack(pop nl, (x . etermq) . sl), nil, -1) eq 'false then
	    c := nil;
      return c
   end;

asserted procedure vsl_substack(f: QfFormula, sl: List): QfFormula;
   % [sl] is a stack growing to the left. We take care that the substitutions in
   % [sl] are carried out from the right to the left.
   cl_apply2ats1(f, function vsl_substackat, {sl});

asserted procedure vsl_substackat(atf: OfsfAtf, sl: List): OfsfAtf;
   ofsf_0mk2(ofsf_op atf, vsl_substackf(ofsf_arg2l atf, sl));

asserted procedure vsl_substackf(f: SF, sl: List): SF;
   if null sl then
      f
   else
      numr ofsf_subf(vsl_substackf(f, cdr sl), car car sl, cadr car sl);

asserted procedure vsl_analyze(s: VslState): List;
   ;

asserted procedure vsl_decide(s: VslState): Void;
   begin scalar w, varl, v;
      if !*rlverbose then
      	 ioto_tprin2t "<decide>";
      w := vsls_kvget(s, 'freevarl);
      assert(w);
      varl := cdr w;
      v . varl := vsl_varsel varl;
      vsls_setsl(s, {v, nil, nil} . vsls_sl s);
      vsls_put(s, 'freevarl, varl);
      if !*rlverbose then
	 vsls_print s
   end;

asserted procedure vsl_undecidedp(s: VslState): ExtraBoolean;
   begin scalar sl;
      sl := vsls_sl s;
      return null sl or cadr car sl
   end;

asserted procedure vsl_varsel(varl: List): DottedPair;
   varl;  % car varl . cdr varl

asserted procedure vsl_substitute(s: VslState): Void;
   begin scalar sl, v;
      if !*rlverbose then
	 ioto_tprin2t "<substitute>";
      sl := vsls_sl s;
      assert(sl);
      v := car pop sl;
      vsls_setsl(s, sl);
      push(vsl_eterm(s, v), sl);
      vsls_setsl(s, sl);
      if !*rlverbose then
	 vsls_print s
   end;

asserted procedure vsl_lbacktrack(s: VslState): Void;
   begin scalar sl, vsub;
      if !*rlverbose then
	 ioto_tprin2t "<lbacktrack>";
      sl := vsls_sl s;
      assert(sl);
      vsub := pop sl;
      vsls_setsl(s, {car vsub, nil, nil} . sl);
      if !*rlverbose then
	 vsls_print s
   end;

asserted procedure vsl_tinconsistentp(s: VslState): Boolean;
   begin scalar il, sl, c, slhs;
      il := vsls_il s;
      sl := vsls_sl s;
      c := t; while c and il do <<
	 slhs := vsl_substackf(ofsf_arg2l pop il, sl);  % This is an SF.
	 if domainp slhs and minusf slhs then
	    c := nil
      >>;
      return not c
   end;

asserted procedure vsl_ibacktrack(s: VslState): Void;
   begin scalar sl, vsub;
      if !*rlverbose then
	 ioto_tprin2t "<ibacktrack>";
      sl := vsls_sl s;
      assert(sl and cdr sl);
      pop sl;
      vsub := pop sl;
      vsls_setsl(s, {car vsub, nil, nil} . sl);
      if !*rlverbose then
	 vsls_print s
   end;

asserted procedure vsl_fail(s: VslState): Void;
   <<
      if !*rlverbose then
      	 ioto_tprin2t "<fail>";
      vsls_setil(s, {'false})
   >>;

asserted procedure vsl_succeed(s: VslState): Void;
   <<
      if !*rlverbose then <<
      	 ioto_tprin2t "<succeed>";
	 mathprint('list . for each atf in vsls_il s collect
	    rl_prepfof vsl_substackat(atf, vsls_sl s))
      >>;
      vsls_setil(s, {'true})
   >>;

endmodule;  % vsl

end;  % of file
