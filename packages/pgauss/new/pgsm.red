module pgsm;

revision('pgsm, "$Id$");

copyright('pgsm, "(c) 1998 A. Dolzmann, A. Seidl, T. Sturm, 2012- T. Sturm");

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

exports sm_create, sm_rightsidesarenotredp, sm_m, sm_n, sm_get,
   sm_redcoefficient, sm_nongreencoefficient, sm_swap, sm_put, sm_copy,
   sm_firststep, sm_getcase, sm_print;

% System-matrix.
% A linear system with m equations and n indeterminants
%
%       a[0,0]*x[0] + ... + a[0,n-1]*x[n-1]   = b[0]
%                                             :
%                                             :
%     a[m-1,0]*x[0] + ... + a[m-1,n-1]*x[n-1] = b[m-1]
%
% is represented by the (m+1) x (n+1) system-matrix
%
%    a[0,0]   ... a[0,n-1]   b[0]
%    :            :          :
%    :            :          :
%    a[m-1,0] ... a[m-1,n-1] b[m-1]
%    x[0]         x[n-1]     V
%
% Elements of C := {a[i,j] | 0<=i<=m-1, 0<=i<=n-1} are called coefficients,
% elements of R := {b[i] | 0<=i<=m-1} are called right hand sides, and the
% elements of I := {x[j] | 0<=j<=n-1} are called indeterminates.
%
% V is a list of inert indeterminates, for which column swaps should be
% avoided when possible.
%
% A coefficient is red, if sm_redp() can derive that it is nonzero under the
% assumptions made so far. It is green, if sm_greenp() can derive that it is
% zero under the assumptions made so far. Otherwise it is white. Depending on
% user options, the procedures sm_redp() and sm_greenp() range from literal
% comparisons of constraints to complete decision procedures. When the algorithm
% introduces new assumptions in the course of a case distinction, those
% assumptions literally state that a particular coefficient is red or green, so
% that even weak implementations of sm_redp() and sm_greep() that check only the
% literal presence of conditions, possibly even classifying numerical
% coefficients as white, would suffice for the correctnes of the algorithm.

asserted procedure sm_create(el: List, vl: List, inert: List): SM;
   % Create system matrix. el is a nonempty list of equations, vl is a nonempty
   % list of identifiers. Returns the corresponding system-matrix as a vector of
   % rows, where each row 0..m-1 is a vector of coefficients, and row m contains
   % information on indeterminates.
   begin scalar m, n, v, elp, vlp, sm;
      m := length el;
      n := length vl;
      sm := mkvect m;
      elp := el;
      for l := 0:m-1 do
      	 putv(sm, l, sm_equation2row(pop elp, vl, n));
      v := mkvect n;
      vlp := vl;
      for c := 0 : n-1 do
      	 putv(v, c, pop vlp);
      putv(v, n, inert);
      putv(sm, m, v);
      return sm
   end;

procedure sm_equation2row(eqt: Equation, vl: List, n: Integer): Vector;
   % Equation to matrix row. eqt is an equation, vl is a list of identifiers
   % x0..x(n-1), n is a natural number, the length of vl. The x(i) are linear in
   % eqt. Returns a vector [a0..a(n-1) b] of SQ, where a(i) is the coefficient
   % of x(i), and b is the absolute summand.
   begin scalar oldorder, row, v, s, p, q;
      oldorder := setkorder vl;
      row := mkvect n;
      s := addsq(simp cadr eqt, negsq simp caddr eqt);
      p := numr s;
      q := denr s;
      for i := 0 : (n-1) do <<
      	 setkorder vl;
      	 p := reorder p;
	 v := pop vl;
      	 if not domainp p and v eq mvar p and not eqn(ldeg p, 1) then <<
	    setkorder oldorder;
            rederr {v, "has degree", ldeg p, "in", reorder p}
	 >>;
      	 if not domainp p and v eq mvar p then <<
            putv(row, i, quotsq(!*f2q lc p, !*f2q q));
            s := addsq(s, negsq(multsq(!*f2q !*k2f v, getv(row, i))));
         >> else
            putv(row, i, nil ./ 1)
      >>;
      putv(row, n, negsq s);
      setkorder oldorder;
      return row
   end;

procedure sm_rightsidesarenotredp(cl, sm, sl);
   % Right sides may be null. sm is a system-matrix. Returns nil if a right side
   % exists that is red (certainly null). The test starts with line sl.
   begin scalar arenotred, rscond, tmp, tmp2; integer l, m, n;
      arenotred := t;
      m := sm_m sm;
      n := sm_n sm;
      l := sl;
%%       if !*pgverbose then <<
%%       	 ioto_prin2t {"+ pgsm.red/sm_rightsidesarenotredp: entering"};
%%  	 sm_print sm
%%       >>;
      % tmp2 := {b_sl=0, ..., b_m-1=0}
      for i := sl : m-1 do
     	 tmp2 := (cond_0mkeqt numr  sm_get(sm, i, n)) . tmp2;
      tmp2 := nconc(tmp2, cl);
      rscond := rl_smkn('and, tmp2);  % rightsidescondition
%%       if !*pgverbose then
%% 	 ioto_prin2t {"+ pgsm.red/sm_rightsidesarenotredp:",
%% 	    " tmp2 is ",
%%  	    ioto_smaprin('list . for each x in tmp2 collect rl_prepfof x),
%% 	    ", cl is ",
%%  	    ioto_smaprin('list . for each x in cl collect rl_prepfof x),
%% 	    ", rscond is ", ioto_smaprin rl_prepfof rscond} where !*nat=nil;
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
      if !*pgverbose then
	 ioto_prin2t {"++ pgsm.red/sm_rightsidesarenotredp: ", arenotred};
      return arenotred
   end;

asserted procedure sm_m(sm: SM): Integer;
   % m. sm is a system-matrix. Returns number of rows, which is number of
   % equations plus 1.
   upbv sm;

asserted procedure sm_n(sm: SM): Integer;
   % n. sm is a system-matrix. Returns number of columns, which is number of
   % indeterminates plus 1.
   upbv getv(sm, 0);

asserted procedure sm_get(sm: SM, r: Integer, c: Integer): Any;
   % Get sm[r,c].
   getv(getv(sm, l), c);

asserted procedure sm_put(sm: SM, r: Integer, c: Integer, entry: Any);
   % sm[r,c] := entry, in place.
   putv(getv(sm, r), c, entry);

asserted procedure sm_swap(sm: SM, r: Integer, c: Integer);
   % Swap rows 0 with r and columns 0 with c, in place.
   begin scalar tmp;
      tmp := getv(sm, 0);
      if not eqn(r, 0) then <<
      	 putv(sm, 0, getv(sm, r));
      	 putv(sm, r, tmp)
      >>;
      if not eqn(c, 0) then
    	 for i := 0 : sm_m sm do <<
            tmp := sm_get(sm, i, 0);
            sm_put(sm, i, 0, sm_get(sm, i, c));
            sm_put(sm, i, c, tmp)
      	 >>
   end;

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

procedure sm_redcoefficient(cl, sm);
   % Is there a red coefficient? sm is a system-matrix. Returns nil if there is
   % no red coefficient. Otherwise returns l . c, such that there is is a red
   % coefficient at row l, column c.
   begin scalar rcfound, tmp; integer l, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      while l <= m-1 and not rcfound do <<
      	 c := 0;
      	 while c <= n-1 and not rcfound do
	    % if numberp(tmp := numr sm_get(sm, l, c)) and not null tmp then
	    %    rcfound := t
            if sm_redp(cl, numr sm_get(sm, l, c)) then
               rcfound := l . c
            else
               c := c+1;
      	 if not rcfound then
            l := l+1
      >>;
      return rcfound
   end;

procedure sm_nongreencoefficient(cl, sm);
   % Is there a nongreen coefficient? sm is a system-matrix. It is assumed, that
   % there are no red coefficients in sm.
   % Returns nil, if there is no nongreen coefficient, l . c, if there is a nongreen
   % coefficient in line l at column c.
   begin scalar wcfound; integer l, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      while l <= m-1 and not wcfound do <<
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
      if wcfound then <<
%%      	 if !*pgverbose then <<
%% 	    prin2 "--nongreencoefficient found: ";
%% 	    mathprint prepsq sm_get(sm, l, c)
%%      	 >>;
     	 return l . c
      >>;
      return nil
   end;

asserted procedure sm_nonInertRed(cl: List, sm: SM): ExtraBoolean;
   % Look for a red coefficient in either column 0 or a non-inert column.
   % Returns nil if there is no such coefficient. Otherwise returns the r . c,
   % where row r, column c is the position of such a coefficient.
   sm_nonInertCoeff(function(sm_redp), cl, sm);

asserted procedure sm_nonInertNonGreen(cl: List, sm: SM): ExtraBoolean;
   % Look for a non-green coefficient in either column 0 or a non-inert column.
   % Returns nil if there is no such coefficient. Otherwise returns the r . c,
   % where row r, column c is the position of such a coefficient.
   sm_nonInertCoeff(function(sm_nonGreenP), cl, sm);

asserted procedure sm_nonInertCoeff(sel: Applicable, cl: List, sm: SM): ExtraBoolean;
   % Look for a coefficient matching selector sel in either column 0 or a
   % non-inert column. Returns nil if there is no such coefficient. Otherwise
   % returns the r . c, where row r, column c is the position of such a
   % coefficient.
   begin scalar pos; integer r, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      while not pos and r <= m-1 do
	 if apply(sel, {cl, numr sm_get(sm, r, 0)}) then
	    pos := r . 0
	 else
	    r := r + 1;
      if pos then return pos;
      c := 1;
      while not pos and c <= n-1 do <<
	 if not sm_inertcol(sm, c) then <<
	    r := 0;
      	    while not pos and r <= m-1 do
	       if apply(sel, {cl, numr sm_get(sm, r, c)}) then
	    	  pos := r . c
	       else
	    	  r := r + 1
	 >>;
      	 c := c + 1
      >>;
      return pos
   end;

asserted procedure sm_InertRed(cl: List, sm: SM): ExtraBoolean;
   % Look for a red coefficient in an inert column. Returns nil if there is no
   % such coefficient. Otherwise returns the r . c, where row r, column c is the
   % position of such a coefficient.
   sm_InertCoeff(function(sm_redp), cl, sm);

asserted procedure sm_InertNonGreen(cl: List, sm: SM): ExtraBoolean;
   % Look for a non-green coefficient in an inert column. Returns nil if there
   % is no such coefficient. Otherwise returns the r . c, where row r, column c
   % is the position of such a coefficient.
   sm_InertCoeff(function(sm_nonGreenP), cl, sm);

asserted procedure sm_inertCoeff(sel: Applicable, cl: List, sm: SM): ExtraBoolean;
   % Look for a coefficient matching selector sel in an inert column, excluding
   % column 0. Returns nil if there is no such coefficient. Otherwise returns
   % the r . c, where row r, column c is the position of such a coefficient.
   begin scalar pos; integer r, c, m, n;
      m := sm_m sm;
      n := sm_n sm;
      c := 1;
      while not pos and c <= n-1 do <<
	 if sm_inertcol(sm, c) then <<
	    r := 0;
      	    while not pos and r <= m-1 do
	       if apply(sel, {cl, numr sm_get(sm, r, c)}) then
	    	  pos := r . c
	       else
	    	  r := r + 1
	 >>;
      	 c := c + 1
      >>;
      return pos
   end;

asserted procedure sm_redp(cl: List, sf: SF);
   % Red predicate. cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is red wrt. cl.
   sm_surep(cl, cond_0mkuneqt sf);

asserted procedure sm_greenp(cl: List, sf: SF);
   % Green predicate. cl is a list of conditions in ofsf. sf is a standard form.
   % Returns t if sf is green wrt. cl.
   sm_surep(cl, cond_0mkeqt sf);

asserted procedure sm_nonGreenP(cl: List, sf: SF): Boolean;
   % Non-green predicate. cl is a list of conditions in ofsf. sf is a standard
   % form. Returns t if sf is green wrt. cl.
   not sm_greenp(cl, sf);

asserted procedure sm_surep(cl: List, c: List3): Boolean;
   % cl is a list of conditions; c is a single condition. Return t if the
   % heuristics say cl |- c, nil otherwise.
   if !*pgspsimpl and !*pgspqe then  % lazy
      ((if rl_simpl(c, cl, -1) eq 'true then t) or
	 (if (rl_qe(rl_all(rl_mk2('impl, rl_mkn('and, cl), c), nil), nil)
	    where !*rlverbose = nil) eq 'true	 then t))
   else if !*pgspsimpl then
      (if rl_simpl(c, cl, -1) eq 'true then t)
   else if !*pgspqe then
      (if (rl_qe(rl_all(rl_mk2('impl, rl_mkn('and, cl), c), nil), nil)
	 where !*rlverbose = nil) eq 'true
      then t)
   else if ofsf_op c eq 'equal then  % white:
      (if null ofsf_arg2l c then t)
   else  % red: t if it is a number <> 0
      if ((domainp ofsf_arg2l c) and (not null ofsf_arg2l c)) then t;


procedure sm_firststep(sm);
   % First step. sm is a system-matrix. Brings the first column in Gauss-Jordan
   % normal form. Return value is not interesting, the argument is changed.
   for l := 1 : sm_m sm - 1 do
      sm_addkl1tol2(sm, negsq quotsq(sm_get(sm, l, 0), sm_get(sm, 0, 0)), 0, l);

procedure sm_addkl1tol2(sm, k, l1, l2);
   % Add k*l1 to l2. sm is a system-matrix. k is a standard quotient.
   % l1 and l2 are natural numbers. Return-value is not interesting,
   % the argument is changed.
   for c := 0 : sm_n sm do
      sm_put(sm, l2, c, addsq(multsq(k, sm_get(sm, l1, c)), sm_get(sm, l2, c)));

procedure sm_inertcol(sm: Vector, c: Integer): ExtraBoolean;
   sm_get(sm, sm_m sm, c) memq sm_get(sm, sm_m sm, sm_n sm);

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
   begin scalar smcpy; integer m, n;
      m := sm_m sm;
      n := sm_n sm;
      smcpy := sm_copy(sm, 0, 0);
      sm_put(smcpy, m, n, 'list . sm_get(smcpy, m, n));
      maprin sm_s2a smcpy
   end;

procedure sm_s2a(sm);
   % Print. sm is a system-matrix. Returns nil.
   begin integer n, m;
      m := upbv sm;
      n := upbv getv(sm, 0);
      return 'mat . for l := 0 : (m-1)+1 collect
      	 for c := 0 : n collect
	    if l = m then
	       sm_get(sm, l, c) or 0
	    else
               prepsq sm_get(sm, l, c)
   end;

% Conditioned system matrix: A csm is a dotted pair c . sm where c is a set of
% conditions, and sm is a system matrix.

asserted procedure csm_create(c: List, sm: SM): CSM;
   % Constructor.
   c . sm;

asserted procedure csm_cond(csm: CSM): List;
   % Get conditions. csm is a conditioned system matrix.
   % returns the corresponding list of conditions.
   car csm;

asserted procedure csm_sm(csm: CSM): SM;
   % Get system matrix. csm is a conditioned system matrix.
   % returns the corresponding system matrix.
   cdr csm;

procedure csm_copy(csm, sl, sc);
   % Copy csm. csm is a conditioned system-matrix. sl and sc are natural
   % numbers.
   % Returns a copy of csm consisting of the original conditions and a copy of
   % the submatrix (smij | sl<=i<=m, sc<=j<=n).
   csm_create(csm_getc csm, sm_copy(csm_getsm csm, sl, sc));

asserted procedure csm_print(csm: CSM);
   begin scalar smcpy; integer m, n;
      smcpy := sm_copy(csm_getsm csm, 0, 0);
      m := sm_m smcpy;
      n := sm_n smcpy;
      sm_put(smcpy, m, n, 'list . sm_get(smcpy, m, n));
      mathprint {'list, rl_prepfof rl_smkn('and, csm_getc csm), sm_s2a smcpy}
   end;

endmodule;

end;  % of file
