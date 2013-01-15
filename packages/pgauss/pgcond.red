% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012 T. Sturm
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
   fluid '(cond_rcsid!* cond_copyright!*);
   cond_rcsid!* := "$Id$";
   cond_copyright!* := "(c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012 T. Sturm"
>>;

module pgcond;
% Conditions: Conditions occur in a (symbolic-mode) solution set. conditions are
% equations or negated equations in fosf-form.

exports cond_eqtp, cond_leftside, cond_rightside, cond_0mkeqt, cond_0mkuneqt;

procedure cond_copy(cl);
   % Copy. cl is a list of conditions. returns a copy of cl.
   cl;

procedure cond_eqtp(eqt);
   % Equation. eqt is a ofsf.
   % Tests, if eqt is an equation.
   if ofsf_op(eqt) eq 'equal then t;

procedure cond_leftside(eqt);
   % Left side. eqt is an equation in ofsf. Returns the left side.
   ofsf_arg2l eqt;

procedure cond_rightside(eqt);
   % Right side. eqt is an equation in ofsf. Returns the right side.
   ofsf_arg2r eqt;

procedure cond_0mkeqt(ls);
   % Make equation with right side zero. ls is a standard form.
   % Returns the equation ls = 0 in ofsf.
   ofsf_0mk2('equal, ls);

procedure cond_0mkuneqt(ls);
   % Make unequation. ls anrs are anything. Returns a lisp-prefix-form.
   ofsf_0mk2('neq, ls);

procedure cond_inconsistentp(cl);
   % Inconsistent predicate. cl is a list of ofsf.
   % Returns t if cl is sure inconsistent, nil otherwise.
   if !*pgspsimpl and !*pgspqe then %lazy
      ((if rl_simpl(rl_smkn('and, cl), nil, -1) eq 'false then t) or
	 (if (rl_qe(rl_ex(rl_smkn('and, cl), nil), nil) where !*rlverbose = nil)
	    eq 'false then t))
   else if !*pgspsimpl then
      (if rl_simpl(rl_smkn('and, cl), nil, -1) eq 'false then t)
   else if !*pgspqe then
      (if (rl_qe(rl_ex(rl_smkn('and, cl), nil), nil) where !*rlverbose = nil)
	 eq 'false then t)
   else rederr{"cond_inconsistentp: No simplifier switched on."};

procedure cond_simpl(cl);
   % Simplification. cl is a list of ofsf.
   % Returns a ofsf $c$ that satisfies \forall(\and(cl)<->c)
   rl_simpl(rl_smkn('and, cl), nil, -1);

procedure cond_qe(cl);
   % Quantifier elimination. cl is a list of ofsf.
   % Returns a ofsf $c$ that satisfies \forall(\ex(\and(cl))<->c)
   (rl_qe(rl_ex(rl_smkn('and, cl), nil), nil) where !*rlverbose = nil);
%  (rl_qe(     (rl_smkn('and, cl)    ), nil) where !*rlverbose = nil);

procedure cond_prin2(c);
   % Print.
   mathprint rl_prepfof c;

procedure cond_prin2l(cl);
   % Print list.
   for each c in cl do mathprint rl_prepfof c;

endmodule;

end;  % of file
