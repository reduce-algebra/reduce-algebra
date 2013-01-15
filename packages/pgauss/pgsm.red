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
   fluid '(pgsm_rcsid!* pgsm_copyright!*);
   pgsm_rcsid!* := "$Id$";
   pgsm_copyright!* := "(c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012 T. Sturm"
>>;

module pgsm;

exports sm_create, sm_rightsidesarenotredp, sm_m, sm_n, sm_get,
   sm_redcoefficient, sm_nongreencoefficient, sm_swap, sm_put, sm_copy,
   sm_firststep, sm_getcase, sm_print;

% System-matrix.
% An equation system with m equations and n indeterminants
%
%       a00*x0 + ... +     a0(n-1)*x(n-1) = b0
%          :                      :         :
%          :                      :         :
%   a(m-1)0*x0 + ... + a(m-1)(n-1)*x(n-1) = b(m-1)
%
% is represented by the system-matrix (m+1 lines, n+1 columns):
%
%    a00     ... a0(n-1)     b0
%    :           :           :
%    :           :           :
%    a(m-1)0 ... a(m-1)(n-1) b(m-1)
%    x0          x(n-1)      *
%
% Elements of C := {aij | 0<=i<=(m-1), 0<=i<=(n-1)} are called coefficients,
% elements of R := {bi | 0<=i<=(m-1)} are called right sides, and the
% elements of I := {xj | 0<=j<=(n-1)} are called indeterminants.
%
% A coefficient is called red, if it is certainly nonnull (e.g. its
% nummerator is nonnull) it is called white, if he maybe nonnull (e.g. its
% nummerator is a nonnull polynomial with the parameters as indeterminants).


procedure sm_create(el, vl);
   % Create system-matrix. el is a nonempty list of equations, vl is a nonempty
   % list of identifieres. Returns the corresponding system-matrix.
   begin scalar m, n, v, elp, vlp, sm;
      m := length el;
      n := length vl;
      sm := mkvect m;
      elp := el;
      for l := 0 : (m-1) do
      <<
      	 vlp := vl;
      	 putv(sm, l, sm_eq2vec(car elp, vlp, n));
      	 elp := cdr elp
      >>;
      v := mkvect n;
      vlp := vl;
      for c := 0 : (n-1) do
      <<
      	 putv(v, c, car vlp);
      	 vlp := cdr vlp
      >>;
      putv(sm, m, v);
      return sm;
   end;

procedure sm_eq2vec(eqt, vl, n);
   % Equation to vector. eqt is an equation, vl is a list of identifiers
   % x0..x(n-1), n is a natural number, the length of vl.
   % Returns a vector [a0..a(n-1) b] containing standard quotients, where
   % ai is the coefficient of xi (i in 0..n-1) and b is the right side
   % of eqt (converted to a SQ).
   begin scalar oldorder, v, s, p, q;
      oldorder := setkorder vl;
      v := mkvect n;
      s := addsq(simp eqt_leftside eqt, negsq simp eqt_rightside eqt);
      p := numr s; q := denr s;
      for i := 0 : (n-1) do
      <<
      	 setkorder vl;
      	 p := reorder p;
      	 if not(domainp p) and not(ldeg p eq 1 or mvar p neq car vl) then
            rederr {"sm_eq2vec:",
               "No degrees higher than 1 are allowed for indeterminants."};
      	 if (not domainp p) and (mvar p eq car vl) then
         <<
            putv(v, i, quotsq(!*f2q lc p, !*f2q q));
            s := addsq(s, negsq(multsq(simp car vl, getv(v, i))));
         >>
      	 else
            putv(v, i, nil . 1);
      	 vl := cdr vl;
      >>;
      putv(v, n, negsq s);
      setkorder oldorder;
      return v;
   end;

procedure sm_rightsidesarenotredp(cl, sm, sl);
   % Right sides may be null. sm is a system-matrix. Returns nil if a right side
   % exists that is red (certainly null). The test starts with line sl.
   begin scalar arenotred, rscond, tmp, tmp2; integer l, m, n;
      arenotred := t;
      m := sm_m sm;
      n := sm_n sm;
      l := sl;
      pg_verbose {"[sm_rightsidesarenotredp entered..."};
      if !*pgverbose then sm_print sm;
      % tmp2 := {b_sl=0, ..., b_m-1=0}
      for i := sl : m-1 do
     	 tmp2 := (cond_0mkeqt numr  sm_get(sm, i, n)) . tmp2;
      tmp2 := nconc(tmp2, cl);
      if !*pgverbose then <<prin2"tmp2: ";prin2t tmp2>>;
      rscond %rightsidescondition
     	 := rl_smkn('and, tmp2);
      if !*pgverbose then <<prin2"rscond: ";cond_prin2 rscond>>;
      if !*pgverbose then <<prin2"cl: ";cond_prin2l cl>>;
      %
      if !*pgspsimpl or !*pgspqe then
     	 arenotred := (if cond_inconsistentp(tmp2) then nil else t)
      else
     	 while (l <= m-1) and arenotred do
	    %    if numberp(tmp := numr sm_get(sm, l, n)) and not null tmp then
	    %      arenotred := nil
    	    if sm_redp(cl, numr sm_get(sm, l, n)) then
      	       arenotred := nil
    	    else
       	       l := l+1;
      pg_verbose {"...leaving sm_rightsidesarenotredp ", arenotred, "]"};
      return arenotred
   end;

procedure sm_m(sm);
   % m. sm is a system-matrix. Returns its m-value.
   upbv sm;

procedure sm_n(sm);
   % n. sm is a system-matrix. Returns its n-value.
   upbv getv(sm, 0);

procedure sm_get(sm, l, c);
   % Get. sm is a system-matrix, l and c are natural numbers.
   % Returns the entry of sm at line l and column n.
   getv(getv(sm, l), c);

procedure sm_redcoefficient(cl, sm);
   % Is there a red coefficient? sm is a system-matrix. Returns nil,
   % if there is no red coefficient, l . c, if there is a red coefficient
   % in line l at column c.
   begin scalar rcfound, tmp; integer l, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      %  if !*pgverbose then cond_prin2l cl;
      while l <= m-1 and not rcfound do
      <<
      	 c := 0;
      	 while c <= n-1 and not rcfound do
	    %        if numberp(tmp := numr sm_get(sm, l, c)) and not null tmp then
	    %          rcfound := t
            if sm_redp(cl, numr sm_get(sm, l, c)) then
               rcfound := t
            else
               c := c+1;
      	 if not rcfound then
            l := l+1
      >>;
      if rcfound then
      <<
       	 if !*pgverbose then
       	 <<
	    prin2 "--redcoefficient found: ";
	    mathprint prepsq sm_get(sm, l, c)
       	 >>;
       	 return (l . c)
      >>
      else
    	 return nil
   end;

procedure sm_nongreencoefficient(cl, sm);
   % Is there a nongreen coefficient? sm is a system-matrix. It is assumed, that
   % there are no red coefficients in sm.
   % Returns nil, if there is no white coefficient, l . c, if there is a white
   % coefficient in line l at column c.
   begin scalar wcfound; integer l, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      while l <= m-1 and not wcfound do
      <<
      	 c := 0;
      	 while c <= n-1 and not wcfound do
	    %        if not null numr sm_get(sm, l, c) then
	    %           wcfound := t
	    if not sm_greenp(cl, numr sm_get(sm, l, c)) then
	       wcfound := t
            else
               c := c+1;
      	 if not wcfound then
            l := l+1
      >>;
      if wcfound then
      <<
     	 if !*pgverbose then
     	 <<
	    prin2 "--nongreencoefficient found: ";
	    mathprint prepsq sm_get(sm, l, c)
     	 >>;
     	 return l . c
      >>
      else
    	 return nil
   end;

procedure sm_redp(cl, sf);
   % Red predicate.
   % cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is red wrt. cl.
   sm_surep(cl, cond_0mkuneqt sf);

procedure sm_greenp(cl, sf);
   % Green predicate.
   % cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is green wrt. cl.
   sm_surep(cl, cond_0mkeqt sf);

procedure sm_surep(cl, c);
   % cl is a list of conditions in ofsf. c is a conditions in ofsf.
   % Returns t if the heuristics say cl |- c, nil otherwise;
   if !*pgspsimpl and !*pgspqe then %lazy
      ((if rl_simpl(c, cl, -1) eq 'true then t) or
	 (if (rl_qe(rl_all(rl_mk2('impl, rl_mkn('and, cl), c), nil), nil)
	    where !*rlverbose = nil) eq 'true	 then t))
   else if !*pgspsimpl then
      (if rl_simpl(c, cl, -1) eq 'true then t)
   else if !*pgspqe then
      (if (rl_qe(rl_all(rl_mk2('impl, rl_mkn('and, cl), c), nil), nil)
	 where !*rlverbose = nil) eq 'true
      then t)
   else if ofsf_op c eq 'equal then %nongreen:
      (if null ofsf_arg2l c then t)
   else %red: t if it is a number <> 0
      if ((domainp ofsf_arg2l c) and (not null ofsf_arg2l c)) then t;

procedure sm_swap(sm, l, c);
   % Swap. sm is a system-matrix. l and c are natural numbers.
   % Permutes line 0 with line l and coulumn 0 with column c.
   begin scalar tmp;
      tmp := getv(sm, 0);
      if not(l eq 0) then
      <<
      	 putv(sm, 0, getv(sm, l));
      	 putv(sm, l, tmp)
      >>;
      if not(c eq 0) then
    	 for i := 0 : sm_m sm do
      	 <<
            tmp := sm_get(sm, i, 0);
            sm_put(sm, i, 0, sm_get(sm, i, c));
            sm_put(sm, i, c, tmp);
      	 >>
   end;

procedure sm_put(sm, l, c, entry);
   % Put. sm is a system-matrix, l and c are natural numbers. entry is anything.
   % Puts entry at line l and column n in sm. Return-value is uninteresting,
   % the argument is changed.
   putv(getv(sm, l), c, entry);

procedure sm_copy(sm, sl, sc);
   % Copy. sm is a system-matrix. sl and sc are natural numbers.
   % Returns a copy of the submatrix (smij | sl<=i<=m, sc<=j<=n).
   begin scalar newsm; integer m, n;
      m := sm_m sm;
      n := sm_n sm;
      newsm := mkvect(m-sl);
      for l := sl : m do
      <<
      	 putv(newsm, l-sl, mkvect(n-sc));
      	 for c := sc : n do
            sm_put(newsm, l-sl, c-sc, sm_get(sm, l, c))
      >>;
      return newsm
   end;

procedure sm_firststep(sm);
   % First step. sm is a system-matrix. Brings the first column in gauss-jordan-
   % normal-form. Return-value is not interesting, the argument is changed.
   for l := 1 : (sm_m sm)-1 do
      sm_addkl1tol2(sm, negsq quotsq(sm_get(sm, l, 0), sm_get(sm, 0, 0)), 0, l);

procedure sm_addkl1tol2(sm, k, l1, l2);
   % Add k*l1 to l2. sm is a system-matrix. k is a standard quotient.
   % l1 and l2 are natural numbers. Return-value is not interesting,
   % the argument is changed.
   for c := 0 : sm_n sm do
      sm_put(sm, l2, c, addsq(multsq(k, sm_get(sm, l1, c)), sm_get(sm, l2, c)));

procedure sm_getcase(sm);
   % Get case. sm is a system-matrix. Returns an identifier.
   if sm_m sm eq 1 then
      'pg_lcase
   else if sm_n sm eq 1 then
      'pg_ccase
   else
      'pg_rcase;

procedure sm_print(sm);
   % Print. sm is a system-matrix. Returns nil.
   begin integer n, m;
      m := upbv sm;
      n := upbv getv(sm, 0);
      for l := 0 : (m-1) do
      <<
      	 terpri!* nil;
      	 for c := 0 : n do
         <<
            maprin prepsq sm_get(sm, l, c);
            maprin '!_!_
         >>;
      	 terpri!* t
      >>;
      for c := 0 : (n-1) do
      <<
      	 prin2 sm_get(sm, m, c);
      	 prin2 "   "
      >>;
      terpri();
      return nil
   end;


% Conditioned system matrix: A csm is a dotted pair c . sm where c is a set of
% conditions, and sm is a system matrix.

procedure csm_create(c, sm);
   % Create. c is a list of conditions. sm is a system matrix.
   % Returns the corresponding conditioned system matrix.
   c.sm;

procedure csm_getc(csm);
   % Get conditions. csm is a conditioned system matrix.
   % returns the corresponding list of conditions.
   car csm;

procedure csm_getsm(csm);
   % Get system matrix. csm is a conditioned system matrix.
   % returns the corresponding system matrix.
   cdr csm;

procedure csm_copy(csm, sl, sc);
   % Copy csm. csm is a conditioned system-matrix. sl and sc are natural
   % numbers.
   % Returns a copy of csm consisting of the original conditions and a copy of
   % the submatrix (smij | sl<=i<=m, sc<=j<=n).
   csm_create(csm_getc(csm), sm_copy(csm_getsm(csm), sl, sc));

endmodule;

end;  % of file
