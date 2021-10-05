module clsimpl;
% Common logic simplification. This is a generic implementation of the "standard simplifier"
% described in  "Simplification of Quantifier-Free Formulae over Ordered Fields", J. Symb. Comput.
% 24(2):209–231, 1997, https://doi.org/10.1006/jsco.1997.0123.

revision('clsimpl, "$Id$");

copyright('clsimpl, "(c) 1995-2021 A. Dolzmann, T. Sturm");

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

rl_provideService rl_simpl = cl_simpl using rl_negateat, rl_simplat1,
   rl_smupdknowl, rl_smrmknowl, rl_smcpknowl, rl_smmkatl, rl_ordatp;

asserted procedure cl_simpl(f: Formula, atl: FormulaL, n: Integer): Formula;
   % Common logic simplify. Simplify f subject to the theory atl. For non-negative n, simplification
   % stops at the n-th recursion into f. For full simplification use n = -1.
   begin scalar w;
      atl := cl_simplifyTheory atl;
      if rl_excp atl then
         return atl;
      w := rl_smupdknowl('and, atl, nil, n+1);
      if w eq 'false then
         return rl_exc("inconsistent theory");
      return cl_simpl1(f, w, n, nil)
   end;

asserted procedure cl_simplifyTheory(atl: List): List;
   % Common logic simplify theory. [atl] is a THEORY. Returns either a
   % list $l$ of atomic formulas, or the identifier [inctheo]. In the
   % first case the conjunction over $l$ is equivalent to the
   % conjuction over [atl], and $l$ contains only simplified atomic
   % formulas. The return value [inctheo] means that the conjunction
   % over [atl] is equivalent to [false].
   begin scalar atf, w, natl, !*rlsiexpla;
      while atl do <<
         atf := pop atl;
         w := cl_simplat(atf, nil);
         if w eq 'false then <<
            atf := 'inctheo;
            atl := nil
         >> else if w neq 'true then
            natl := w . natl
      >>;
      if atf eq 'inctheo then
         return rl_exc("inconsistent theory");
      return natl
   end;

asserted procedure cl_simpl1(f: Formula, knowl: Any, n: Integer, sop: Id): Formula;
   % Common logic simplify. [f] is a formula; [knowl] is an IRL; [n] is an
   % integer; [sop] is a CL operator. Depends on switch [!*rlsiso]. Returns a
   % formula. Simplifies [f] recursively using [knowl].
   begin scalar op;
      if eqn(n, 0) then
         return f;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if rl_junctp op then
         return cl_simplifyAndOr(f, knowl, n);
      if op eq 'not then
         return cl_simplifyNot(f, knowl, n);
      if rl_quap op then
         return cl_simplifyQuantifier(f, knowl, n);
      if rl_bquap op then
         return rl_simplifyBoundedQuantifier(f, knowl, n);
      if op eq 'impl then
         return cl_simplifyImplication(rl_arg2l f, rl_arg2r f,knowl, n);
      if op eq 'repl then
         return cl_simplifyImplication(rl_arg2r f, rl_arg2l f, knowl, n);
      if op eq 'equiv then
         return cl_simplifyEquivalence(rl_arg2l f, rl_arg2r f, knowl, n);
      ASSERT( cl_atfp f );
      return cl_simplifyAtom(f, knowl, n, sop)
   end;

asserted procedure cl_simplifyAtom(f: AtFormula, knowl: Any, n: Integer, sop: Id): Formula;
   begin scalar w, op, newknowl;
      w := cl_simplat(f, sop);
      op := rl_op w;
      if rl_junctp op then
         return cl_simplifyAndOr(w, knowl, n);
      if rl_tvalp op then
         return w;
      ASSERT( cl_atfp w );
      newknowl := rl_smupdknowl('and, {w}, rl_smcpknowl knowl, n);
      if newknowl eq 'false then
         return 'false;
      w := rl_smmkatl('and, knowl, newknowl, n);
      if w eq 'false then
         return 'false;
      return rl_smkn('and, w)
   end; 

asserted procedure cl_simplifyQuantifier(f: Formula, knowl: Any, n: Integer): Formula;
   begin scalar q, x, w;
      q := rl_op f;
      x := rl_var f;
      knowl := rl_smrmknowl(knowl, x);
      w := cl_simpl1(rl_mat f, knowl, n-1, q);
      if not (x memq cl_fvarl1 w) then
         % This test covers truth values.
         return w;
      return rl_mkq(q, x, w)
   end;

asserted procedure cl_simplifyNot(f: Formula, knowl: Any, n: Integer): Formula;
   begin scalar result;
      result := cl_simpl1(rl_arg1 f, knowl, n-1, 'not);
      if rl_tvalp result then
         return cl_flip result;
      if cl_atfp result then
         return rl_negateat result;
      return cl_involutiveNot result
   end;  

asserted procedure cl_involutiveNot(f: Formula): Formula;
   % Common logic negate applying the law of involutivity. [f] is a
   % formula. Returns $\phi$ if [f] is of the form $\lnot \phi$,
   % $\lnot [f]$ else.
   if rl_op f eq 'not then rl_arg1 f else rl_mk1('not, f);

asserted procedure cl_simplifyAndOr(f: Formula, knowl: Any, n: Integer): Formula;
   % Common logic simplify conjunction or disjunction.
   begin scalar op, junct, break, w, atl, col, newknowl, a, wop, argl, sicol, natl;
      newknowl := rl_smcpknowl knowl;
      op := rl_op f;
      junct := rl_argn f;
      break := cl_cflip('false, op eq 'and);
      for each subf in junct do <<
         w := if cl_atfp subf then cl_simplat(subf, op) else subf;
         if cl_atfp w then
            atl := w . atl
         else
            col := w . col
      >>;
      newknowl := rl_smupdknowl(op, atl, newknowl, n);
      if newknowl eq 'false then
         return break;
      col := reversip col;
      while col do <<
         a := pop col;
         w := cl_simpl1(a, newknowl, n-1, op);
         wop := rl_op w;
         if wop eq break then <<
            a := break;
            col := nil
         >> else if wop eq op then <<
            argl := rl_argn w;
            while argl and cl_atfp car argl do <<
               natl := car argl . natl;
               argl := cdr argl
            >>;
            if natl then <<
               col := nconc(reversip sicol,col);
               sicol := nil
            >>;
            sicol := nconc(sicol,reverse argl)  % must be constructive
         >> else if rl_cxp wop then
            (if wop neq cl_flip break then sicol := w . sicol)
         else <<
            ASSERT( cl_atfp w );
            col := nconc(reversip sicol, col);
            sicol := nil;
            natl := {w}
         >>;
         if natl then <<
            newknowl := rl_smupdknowl(op, natl, newknowl, n);
            if newknowl eq 'false then <<
               a := break;
               col := nil
            >>;
            natl := nil
         >>
      >>;
      if a eq break then
         return break;
      atl := rl_smmkatl(op, knowl, newknowl, n);
      if atl eq break then
         return break;
      % It might be better to avoid duplicates right away.
      w := sicol;
      sicol := nil;
      for each x in w do
         sicol := lto_insert(x, sicol);
      if !*rlsiso then <<
         atl := sort(atl, 'rl_ordatp);
         sicol := sort(sicol, 'cl_ordp)
      >>;
      return rl_smkn(op, nconc(atl, sicol))
   end;

asserted procedure cl_simplifyImplication(prem: Formula, concl: Formula, knowl: Any, n: Integer): Formula;
   begin scalar w, newknowl;
      if concl eq 'true then
         return 'true;
      prem := cl_simpl1(prem, knowl, n-1, 'prem);
      if prem eq 'false then
         return 'true;
      concl := cl_simpl1(concl, knowl, n-1, 'concl);
      if concl eq 'true then
         return 'true;
      if prem eq 'true then
         return concl;
      if concl eq 'false then
         return cl_involutiveNot prem;
      ASSERT( not rl_tvalp prem and not rl_tvalp concl );
      if prem = concl then
         return 'true;
      if cl_atfp prem and cl_atfp concl then <<
         w := cl_simpl1(rl_nnf rl_mk2('impl, prem, concl), knowl, n-1, nil);
         if rl_tvalp w or cl_atfp w then
            return w;
         return rl_mk2('impl, prem, concl)
      >> else if cl_atfp prem and cl_cxfp concl then <<
         newknowl := rl_smupdknowl('and, {prem}, rl_smcpknowl knowl, n);
         if newknowl eq 'false then
            return 'true;
         return rl_mk2('impl, prem, cl_simpl1(concl, newknowl, n-1, 'concl))
      >> else if cl_cxfp prem and cl_atfp concl then <<
         newknowl := rl_smupdknowl('or, {concl}, rl_smcpknowl knowl, n);
         if newknowl eq 'false then
            return 'true;
         return rl_mk2('impl, cl_simpl1(prem, newknowl, n-1, 'concl), concl)
      >> else <<
         ASSERT( cl_cxfp prem and cl_cxfp concl );
         return rl_mk2('impl, prem, concl)
      >>
   end;

asserted procedure cl_simplifyEquivalence(lhs: Formula, rhs: Formula, knowl: Any, n: Integer): Formula;
   begin scalar w;
      lhs := cl_simpl1(lhs, knowl, n-1, 'equiv);
      rhs := cl_simpl1(rhs, knowl, n-1, 'equiv);
      if lhs eq 'true then
         return rhs;
      if rhs eq 'true then
         return lhs;
      if lhs eq 'false then
         return cl_involutiveNot rhs;
      if rhs eq 'false then
         return cl_involutiveNot lhs;
      if lhs = rhs then
         return 'true;
      if cl_atfp lhs and cl_atfp rhs then <<
         w := cl_simpl1(rl_nnf rl_mk2('equiv, lhs, rhs), knowl, n, nil);
         if rl_tvalp w or cl_atfp w then
            return w
      >>;
      return if cl_ordp(lhs, rhs) then
         rl_mk2('equiv, lhs, rhs)
      else
         rl_mk2('equiv, rhs, lhs)
   end;

% The following code implements the ordering of formulas used for sorting the
% boolean levels.

asserted procedure cl_ordp(f1: Formula, f2: Formula): ExtraBoolean;
   % Common logic order predicate. This is a strict total ordering.
   begin scalar op1,op2;
      op1 := rl_op f1;
      op2 := rl_op f2;
      if not rl_cxp op1 and not rl_cxp op2 then
         return rl_ordatp(f1, f2);
      if not rl_cxp op1 and rl_cxp op2 then
         return t;
      if rl_cxp op1 and not rl_cxp op2 then
         return nil;
      % Both [op1] and [op2] are non-atomic now.
      if op1 neq op2 then
         return cl_ordopp(op1, op2);
      if rl_tvalp op1 then
         return t;
      if rl_quap op1 then
         return if rl_var f1 neq rl_var f2 then
            not(ordp(rl_var f1, rl_var f2) and rl_var f1 neq rl_var f2)
         else
            cl_ordp(rl_mat f1, rl_mat f2);
      if rl_bquap op1 then
         return rl_BQordp(f1, f2);
      ASSERT( rl_junctp op1 and op1 = op2 );
      return cl_ordpl(rl_argn f1, rl_argn f2)
   end;

asserted procedure cl_ordpl(fl1: List, fl2: List): ExtraBoolean;
   % Common logic order predicate on lists. Generalizes cl_ordp to lists.
   if not fl2 then
      nil
   else if not fl1 then
      t
   else if car fl1 neq car fl2 then
      cl_ordp(car fl1, car fl2)
   else
      cl_ordpl(cdr fl1, cdr fl2);

asserted procedure cl_ordopp(op1: Id, op2: Id): ExtraBoolean;
   % Common logic ordered operator predicate. [op1] and [op2] are first-order
   % operators. Returns t iff op1 < op2.
   op2 memq cdr (op1 memq '(and or not impl repl equiv bex ball ex all true false));

% The following code implements a "generic smart simplification". All black
% boxes for the smart simplification are implemented generically using only a
% single non-generic black box rl_negateat. rl_negateat must return an atomic
% formula.

asserted procedure cl_smcpknowl(knowl: Alist): Alist;
   % Common logic smart simplifier copy knowledge. [knowl] is a
   % knowledge base. Returns a toplevel copy of [knowl].
   for each p in knowl collect p;

asserted procedure cl_smrmknowl(knowl: Alist, v: Id): Alist;
   % Common logic smart simplifier remove knowledge. [knowl] is a
   % knowledge base; [v] is a variable. Returns a knowledge base.
   % Removes all knowledge involving [v] from the knowledge base.
   nil;

asserted procedure cl_smupdknowl(op: Id, atl: List, knowl: Alist, n: Integer): Alist;
   % Common logic smart simplifier update knowledge. [op] is one of the
   % operators [and], [or]; [atl] is a list of atomic formulas; [knowl] is
   % knowledge base; [n] is an integer. Returns a knowledge base. If [op] is
   % [and], then all knowledge in [atl] is added to the [knowl] with the tag
   % [n]. If [op] is [or], then the negation of all knowledge in [atl] is added
   % to [knowl].
   begin scalar at;
      while atl do <<
         at := car atl;
         atl := cdr atl;
         knowl := cl_smupdknowl1(op, at, knowl, n);
         if knowl eq 'false then <<
            atl := nil;
            at := 'break
         >>
      >>;
      if at eq 'break then
         return 'false
      else
         return knowl
   end;

asserted procedure cl_smupdknowl1(op: Id, at: Atom, knowl: Alist, n: Integer): Alist;
   begin scalar ent, contra;
      if op eq 'or then <<
         ent := rl_negateat at;
         contra := at
      >> else <<
         ent := at;
         contra := rl_negateat at
      >>;
      if assoc(contra, knowl) then
         return 'false;
      if assoc(ent, knowl) then
         return knowl;
      return knowl := (ent . n) . knowl
   end;

asserted procedure cl_smmkatl(op: Id, knowl: Alist, newknowl: Alist, n: Integer): List;
   % Common logic smart simplifier make atomic formula list. [op] is
   % one of the operators [and], [or]; [knowl], [newknowl] are
   % knowledge bases; [n] is an integer. Returns a list of atomic
   % formulas. All knowledge tagged with [n] is extraced from
   % [newknowl] and returned as a list of atomic formulas.
   begin scalar res;
      res := for each pair in newknowl join
         if cdr pair = n then {car pair};
      if op eq 'or then
         res := for each at in res collect rl_negateat at;
      return res
   end;

endmodule;  % [clsimpl]

end;  % of file
