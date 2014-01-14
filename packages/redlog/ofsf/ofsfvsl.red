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

% VslState ::= ('vslstate, list of input constraints, substitution list, list of positive lemmas, list of negative lemmas,
%   property list)

struct VslState asserted by VslStateP;
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

asserted procedure vslstate_mk(il: OfsfAtfl, sal: List, pl: OfsfAtfl, nl: VslNegLemmaL): VslState;
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

asserted procedure vsl_eterm(s: VslState, x: Kernel): DottedPair;
   % Eterm function.
   begin scalar ifl, nl, res, f, w;
      ifl := vslstate_inputl s;
      nl := vslstate_nl s;
      repeat
	 res := vsl_eterm1(pop ifl, vslstate_stackl s, nl, x)
      until res or null ifl;
      return res or x . 'bottom
   end;

asserted procedure vsl_eterm1(atf: OfsfAtf, sl: List, nl: List, x: Kernel): ExtraBoolean;
   begin scalar rlhs, etermq;
      if not memq(x, ofsf_varlat atf) then
	 return nil;
      rlhs := sfto_reorder(rl_arg2l atf, x);
      etermq := quotsq(!*f2q negf red rlhs, !*f2q lc rlhs);
      if not vsl_admissible(x, etermq, sl, nl) then
	 return nil;
      return x . etermq
   end;

asserted procedure vsl_admissible(x: Kernel, etermq: SQ, sl: List, nl: List): Boolean;
   begin scalar c;
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
      numr ofsf_subf(vsl_substackf(f, cdr sl), car car sl, cdr car sl);

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
