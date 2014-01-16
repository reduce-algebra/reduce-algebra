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

struct VslState asserted by VslStateP;
struct VslSub asserted by List3;
struct VslNegLemma asserted by VslNegLemmaP;
struct VslNegLemmaL asserted by listp;

procedure VslStateP(s);
   eqcar(s, 'vslstate);

procedure VslNegLemmaP(s);
   listp s and eqcar(s, 'or);

asserted procedure vslstate_inputl(s: VslState): OfsfAtfL;
   nth(s, 2);

asserted procedure vslstate_stackl(s: VslState): List;
   nth(s, 3);

asserted procedure vslstate_pl(s: VslState): List;
   nth(s, 4);

asserted procedure vslstate_nl(s: VslState): List;
   nth(s, 5);

asserted procedure vslstate_prop(s: VslState): List;
   nth(s, 6);

asserted procedure vslstate_mk(il: OfsfAtfL, sal: List, pl: OfsfAtfL, nl: VslNegLemmaL): VslState;
   {'vslstate, il, sal, pl, nl, nil};

asserted procedure vslstate_put(s: VslState, key: Id, value: Any): Any;
   begin scalar w, h;
      h := cddddr cdr s;
      w := atsoc(key, car h);
      if w then
	 cdr w := value
      else
	 car h := (key . value) . car h;
      return value
   end;

asserted procedure vslstate_get(s: VslState, key: Id): Any;
   atsoc(key, nth(s, 6));

asserted procedure vsl_vsl(inputl: List): QfFormula;
   begin scalar state;
      state := vslstate_mk(inputl, nil, nil, nil);
      return 'false
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
      w := vslstate_get(s, 'esets);
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
      vslstate_put(s, 'esets, esetal);
      return {x, car res, cdr res}
   end;

asserted procedure vsl_eset(s: VslState, x: Kernel): List;
   begin scalar sl, fs, lhs, ubl, lbl;
      sl := vslstate_stackl s;
      for each ineq in vslstate_inputl s do <<
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
   if null lbl or length lbl > length ubl then
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
      sl := vsl_stackl s;
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

asserted procedure vsl_decide(s: VslState): VslState;
   ;

asserted procedure vsl_fback(s: VslState): VslState;
   ;

asserted procedure vsl_lneqback(s: VslState): VslState;
   ;

endmodule;  % vsl

end;  % of file
