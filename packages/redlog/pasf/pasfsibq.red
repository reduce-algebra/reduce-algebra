module pasfsibq;
% Presburger arithmetic standard form simplify bounded quantifier.

revision('pasfsibq, "$Id$");

copyright('pasfsibq, "(c) 2021 A. Dolzmann, T. Sturm");

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

asserted procedure pasf_simplifyBoundedQuantifier(f: Formula, knowl: Any, n: Integer): Formula;
   % Common logic simplify bounded quantifier. [f] is a formula with bounded
   % quantifier as an operator; [knowl] is a theory; [n] is the current
   % boolean level. Returns a simplified equivalent formula.
   begin scalar b, mtx;
      knowl := rl_smrmknowl(knowl, rl_var f);
      % Context-dependent bound simplification
      b := pasf_simplb(rl_b f, rl_var f);
      % Bound's information to knowledge
      knowl := rl_smupdknowl('and, pasf_b2atl(b, rl_var f), knowl, n);
      % Matrix simplification detects trivial cases
      mtx := cl_simpl1(rl_mat f, knowl, n-1, rl_op f);
      f := pasf_simpltb(rl_op f, rl_var f, b, mtx);
      % Moving formulas to bound
      if rl_bquap rl_op f then
         f := pasf_simplstrb(rl_op f, rl_var f, rl_b f, rl_mat f);
      return if not rl_tvalp f and not rl_bquap rl_op f then
         % Note: Only trivial simplifications are performed for now
         cl_simpl1(f, nil, -1, nil)
      else f
   end;

asserted procedure pasf_simpltb(op: Id, var: Id, b: Formula, mtx: Formula): Formula;
   % Common logic simplify bounded quantifier trivial bound. [mtx] is the
   % bounded quantifier matrix; [b] is the bound of the bounded quantifier;
   % [op] is the operator; [var] is the variable. Returns a simplified
   % equivalent formula.
   begin scalar bfvl;
      % Note: Simplification of the bound to false is context dependent
      if b eq 'false then
         return if op eq 'bex then 'false else 'true;
      if mtx eq 'false and op eq 'bex or mtx eq 'true and op eq 'ball then
         return mtx;
      % Matrix does not contain the bound variable. Note: nil as a result of
      % pasf_bsatp means, that satisfability test has failed.
      if not(var memq rl_fvarl mtx) and pasf_bsatp(b, var) then
         return mtx;
      % Bound is an equation. Note: Should be only relevant if rlsism is off
      bfvl := cl_fvarl b;
      if rl_op b eq 'equal and null cdr bfvl and eqcar(bfvl, var) then
         % Note: using a context speciefic bound simplifier one can do more
         return cl_subfof({var . car pasf_b2terml(b, var)}, mtx);
      % Nothing was done
      return rl_mkbq(op, var, b, mtx)
   end;

asserted procedure pasf_simplstrb(op: Id, var: Id, b: Formula, mtx: Formula): Formula;
   % Common logic simplify bounded quantifier strengthen bound. [mtx] is the
   % bounded quantifier matrix; [b] is the bound of the bounded quantifier; [op]
   % is the operator; [var] is the variable. Returns a simplified equivalent
   % formula.
   begin scalar neg, st, lv, vfl;
      if cl_atfp mtx and length cl_fvarl mtx = 1 and
         car cl_fvarl mtx eq var and not pasf_univnlfp(mtx, var) then <<
            if op eq 'ball then <<
               b := pasf_simplb(rl_smkn('and, rl_mkn('not, {mtx}) . {b}), var);
               mtx := 'false
            >>;
            if op eq 'bex then <<
               b := pasf_simplb(rl_smkn('and, mtx . {b}), var);
               mtx := 'true
            >>;
            % The formula is trivial, but it can be too expensive to find it out
            return pasf_simpltb(op, var, b, mtx)
         >>;
      if op eq 'ball and rl_op mtx eq 'or then      
         neg := 'negate;
      if op eq 'bex and rl_op mtx eq 'and then
         neg := 'leave;
      if neg then <<
         for each arg in rl_argn mtx do  <<
            vfl := cl_fvarl arg;
            if length vfl = 1 and car vfl eq var and cl_atfp arg and not pasf_univnlfp(arg, var) then
               st := (if neg eq 'negate then rl_mkn('not, {arg}) else arg) . st
            else
               lv := arg . lv;
         >>;
         % Post bound simplification. The matrix is trivial or no
         % simplification can be performed
         b := pasf_simplb(rl_smkn('and, b . st), var);
         % Note: different semantics if the list of formulas left in matrix is
         % empty. For bex the matrix is true and for ball false
         mtx := if lv then
            rl_smkn(rl_op mtx, lv)
         else
            if op eq 'ball then
               'false
            else
               'true;
         % Now the formula is maybe trivial
         return pasf_simpltb(op, var, b, mtx)
      >>;
      return rl_mkbq(op, var, b, mtx)
   end;

procedure pasf_simplb(f,var);
   % Presburger arithmetic standard form simplify formulas' bound. [f] is a
   % bound of some bounded formula; [var] is the bounded variable. Returns an
   % [f]-equivalent simplified formula (flat simplified DNF of [f]).
   begin scalar sb,nsb,flg,argn,argna;
      f := pasf_dnf cl_simpl(f,nil,-1);
      if rl_tvalp f then return f;
      % If the bound is parametric or contains univariate formulas only normal
      % simplification is done
      if length cl_fvarl f > 1 or pasf_univnlfp(f,var) then
         return f;
      % Looking for one argument in the DNF without a congruence
      argn := if rl_op f eq 'or then rl_argn f else {f};
      % Note: Congruences in the bound are critical to heap space and time
      for each arg in argn do <<
         flg := nil;
         argna := if rl_op arg eq 'and then rl_argn arg else {arg};
         for each a in argna do if pasf_congp a then flg := t;
         if null flg then
            sb := arg . sb
         else
            nsb := arg . nsb
      >>;
      sb := pasf_ivl2qff(pasf_qff2ivl rl_smkn('or,sb),var);
      return cl_simpl(rl_smkn('or,sb . nsb),nil,-1)
   end;

procedure pasf_b2atl(b,k);
   % Presburger arithmetic standard form bound to list of atoms. [b] is a
   % formula in at most one variable with finite satisfability set in DNF; [k]
   % is the variable of [b]. Returns a list of atomic formulas
   % $(\varphi_i)_{i}$, so that the equivalence $$\bigvee_i \varphi_i
   % \longleftrightarrow b$$ holds and nil if it is too expensive to derive
   % atomic formulas from the bound.
   if rl_tvalp b then
      (if b eq 'false then {} else rederr "pasf_b2atl: infinite bound")
   else if cl_atfp b then
      {b}
   else if rl_op b eq 'and then
      % Using the fact the application of b2atl is performed after a DNF
      rl_argn b;

endmodule;

end;
