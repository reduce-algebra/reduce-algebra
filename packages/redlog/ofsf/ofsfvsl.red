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

switch rlvsllog;

% VslState ::= ('vslstate, list of input constraints, VslSubL, list of positive
%   lemmas, list of negative lemmas, property list)
% VslSub ::= (Kernel, SQ | bottom, OfsfAtf | nil, OfsfAtfL)

struct Void;
struct VslState asserted by VslStateP;
struct VslSub asserted by List4;
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
      sl := vsls_sl s;
      ioto_prin2t if null sl then
	  "<>"
      else
	 vsl_printstkelem pop sl;
      for each sub in sl do <<
      	 ioto_tprin2 "          ";
	 vsl_printstkelem sub;
	 % if caddr sub then
	 %    ioto_prin2 {" ", rl_prepfof caddr sub}
      >>
   end;

procedure vsl_printstkelem(sub);
   ioto_prin2t {"|", car sub, "=",
      ioto_form2str if idp cadr sub then cadr sub else prepsq cadr sub};

asserted procedure vsl_vsl(inputl: List): QfFormula;
   begin scalar state, freevarl, sl, kgeq0; integer substc;
      state := vsls_mk(vsl_normalize inputl, nil, nil, nil);
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
      	 if !*rlverbose and cadr car vsls_sl state neq 'bottom then
	    substc := substc + 1;
	 sl := vsls_sl state;
	 if vsl_eoesetp car sl then
	    if cdr sl then
	       vsl_ibacktrack state
	    else
	       vsl_fail state
	 else if (kgeq0 := vsl_tinconsistentp state) then
	    vsl_lbacktrack(state, kgeq0)
	 else if null vsl_freevarl state then
	    vsl_succeed state
      >>;
      if !*rlverbose then
	 ioto_tprin2t {"Number of computed nodes: ", substc};
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

asserted procedure vsl_eoesetp(eterm: List): ExtraBoolean;
   % End of eset predicate.
   cadr eterm eq 'bottom;

asserted procedure vsl_eterm(s: VslState, x: Kernel): VslSub;
   begin scalar eset, sb, b, borig, lhs, q, nils;
      eset := vsls_esetget(s, x);
      sb := {x, 'bottom, nil, nil};
      while eset and cadr sb eq 'bottom do <<
      	 b . borig := pop eset;
	 lhs := ofsf_arg2l b;
	 % lhs is already reordered w.r.t. x.
	 q := quotsq(!*f2q negf red lhs, !*f2q lc lhs);
	 if vsl_admissiblep(s, x, q) then <<
	    nils := for each f in vsl_ils s collect
	       ofsf_0mk2(ofsf_op f, numr ofsf_subf(ofsf_arg2l f, x, q));
      	    sb := {x, q, borig, nils}
	 >>
      >>;
      vsls_esetput(s, x, eset);
      return sb
   end;

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
	 lhs := sfto_reorder(sfto_dprpartf ofsf_arg2l b, x);
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
   if null lbl or (not null ubl and length lbl > length ubl) then
      ubl
   else
      lbl;

asserted procedure vsl_ils(s: VslState): List;
   (if sl then nth(car sl, 4) else vsls_il s) where sl = vsls_sl s;

switch vsllearn;

asserted procedure vsl_admissiblep(s: VslState, x: Kernel, q: SQ): Boolean;
   begin scalar sl, nl, c;
      if not !*vsllearn then
	 return t;
      sl := vsls_sl s;
      nl := vsls_nl s;
      c := t; while c and nl do
      	 if cl_simpl(vsl_substack(pop nl, {x, q, nil, nil} . sl), nil, -1) eq 'false then
      	    c := nil;
      if !*rlverbose and !*rlvsllog and not c then
	 ioto_tprin2t {"   dropped test term by learning: ", x, "=", ioto_form2str prepsq q};
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
      	 v . varl := vsl_varsel freevarl;
      	 vsls_esetput(s, v, vsl_eset(s, v))
      >>;
      vsls_setsl(s, {v, nil, nil, nil} . vsls_sl s);
      if !*rlverbose and !*rlvsllog then
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
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2 "<substitute>";
      sl := vsls_sl s;
      assert(sl);
      v := car pop sl;
      vsls_setsl(s, sl);
      push(vsl_eterm(s, v), sl);
      vsls_setsl(s, sl);
      if !*rlverbose and !*rlvsllog then
	 vsls_print s
   end;

asserted procedure vsl_lbacktrack(s: VslState, kgeq0: OfsfAtf): Void;
   begin scalar sl, vsub, l;
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2t "<lbacktrack>";
      sl := vsls_sl s;
      assert(sl);
      if !*vsllearn then <<
      	 l := vsl_analyze(kgeq0 . for each sub in sl collect nth(sub, 3));
      	 vsls_setnl(s, l . vsls_nl s);
      	 if !*rlverbose and !*rlvsllog then
	    ioto_prin2t {"   learned: ", ioto_form2str rl_prepfof l}
      >>;
      vsub := pop sl;
      vsls_setsl(s, {car vsub, nil, nil, nil} . sl);
      if !*rlverbose and !*rlvsllog then
	 vsls_print s
   end;

asserted procedure vsl_tinconsistentp(s: VslState): ExtraBoolean;
   begin scalar il, ils, c, w, slhs;
      il := vsls_il s;
      ils := vsl_ils s;
      % if cl_simpl(rl_smkn('and, ils), nil, -1) eq 'false then
      % 	 return t;
      % return nil;
      c := t; while c and ils do <<
	 w := pop il;
	 slhs := ofsf_arg2l pop ils;  % This is an SF.
	 if domainp slhs and minusf slhs then
	    c := nil
      >>;
      return if not c then w
   end;

asserted procedure vsl_analyze(l: List): QfFormula;
   begin scalar xl, y, yl, hugo, rhugo, sysl, solal, w, learnl;
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
	    push(ofsf_0mk2('neq, lc hugo), learnl);
	 hugo := red hugo
      >>;
      return rl_smkn('or, learnl)
   end;

asserted procedure vsl_solve(sysl: List, yl: List): List;
   begin scalar tsl, vl, sl, plugal, subal, resal, s;
      yl := sort(yl, 'ordop);
      tsl := solvebareiss(sysl, yl);
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
      y . simp 1;

asserted procedure vsl_ibacktrack(s: VslState): Void;
   begin scalar sl, vsub;
      if !*rlverbose and !*rlvsllog then
	 ioto_tprin2t "<ibacktrack>";
      sl := vsls_sl s;
      assert(sl and cdr sl);
      pop sl;
      vsub := pop sl;
      vsls_setsl(s, {car vsub, nil, nil, nil} . sl);
      if !*rlverbose and !*rlvsllog then
	 vsls_print s
   end;

asserted procedure vsl_fail(s: VslState): Void;
   <<
      if !*rlverbose then
      	 ioto_tprin2t "<fail>";
      vsls_setil(s, {'false})
   >>;

asserted procedure vsl_succeed(s: VslState): Void;
   begin scalar ils;
      if !*rlverbose then <<
      	 ioto_tprin2t "<succeed>";
	 ils := vsl_ils s;
	 ioto_tprin2 {"   F/S: |", ioto_form2str rl_prepfof pop ils};
	 for each atf in ils do
            ioto_tprin2t {"        |", ioto_form2str rl_prepfof atf}
      >>;
      vsls_setil(s, {'true})
   end;

endmodule;  % vsl

end;  % of file
