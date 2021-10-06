module clmisc;
% Common logic miscellaneous algorithms.

revision('clmisc, "$Id$");

copyright('clmisc, "(c) 1995-2021 A. Dolzmann, T. Sturm");

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

asserted procedure cl_apply2ats(f: Formula, client: Applicable): Formula;
   % Common logic apply to atomic formulas. Each atomic formula alpha in f is
   % replaced with the formula client(alpha).
   cl_apply2ats1(f, client, nil);

asserted procedure cl_apply2ats1(f: Formula, client: Applicable, xargs: List): Formula;
   % Common logic apply to atomic formulas variant. Let xargs =
   % (x_1, ..., x_n). Then each atomic formula alpha in f is replaced with
   % the formula client(alpha, x_1, ..., x_n).
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if rl_quap op then
         return rl_mkq(op, rl_var f, cl_apply2ats1(rl_mat f, client, xargs));
      if rl_bquap op then
         return rl_BQapply2ats1(f, client, xargs);
      if rl_boolp op then
         return rl_mkn(op, for each s in rl_argn f collect cl_apply2ats1(s, client, xargs));
      ASSERT( cl_atfp f );
      return apply(client, f . xargs)
   end;

asserted procedure cl_apply2ats2(f: Formula, client: Applicable, xargs: List, omega: Id): Formula;
   % Common logic apply to atomic formulas variant. Let xargs =
   % (x_1, ..., x_n). Then each atomic formula alpha in f is replaced with
   % the formula client(alpha, omega, x_1, ..., x_n), where omega is the
   % operator of the boolean level where alpha occurs. Does not support
   % bounded quantifiers.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if rl_quap op then
         return rl_mkq(op, rl_var f, cl_apply2ats2(rl_mat f, client, xargs, op));
      if rl_boolp op then
         return rl_mkn(op, for each s in rl_argn f collect cl_apply2ats2(s, client, xargs, op));
      ASSERT( cl_atfp f );
      return apply(client, f . omega . xargs)
   end;

asserted procedure cl_atnum(f: Formula): Integer;
   % Common logic nummber of contained atomic formulas. Counts multiplicities.
   begin scalar op;
      op := rl_op f;
      if rl_boolp op then
         return for each subf in rl_argn f sum cl_atnum(subf);
      if rl_quap op then
         return cl_atnum(rl_mat f);
      if rl_bquap op then
         return rl_BQatnum(f);
      if rl_tvalp op then
         return 0;
      ASSERT( cl_atfp f );
      return 1
   end;

asserted procedure cl_qnum(f: Formula): Integer;
   % Common logic number of quantifiers. Counts the number of quantifiers
   % occurring in f. Counting of bounded quantifiers is context-dependent.
   begin scalar op;
      op := rl_op f;
      if rl_boolp op then
         return for each s in rl_argn f sum cl_qnum s;
      if rl_quap op then
         return 1 + cl_qnum rl_mat f;
      if rl_bquap op then
         return rl_BQqnum f;
      if rl_tvalp op then
         return 0;
      ASSERT( cl_atfp f );
      return 0
   end;

asserted procedure cl_depth(f: Formula): Integer;
   % The depth of f is the maximum nesting of boolean subformulas.
   % Consideration of bounds in bounded quantifiers is context-dependent.
   begin scalar op;
      op := rl_op f;
      if rl_basbp op then
         return 1 + lto_max for each sf in rl_argn f collect cl_depth sf;
      if rl_quap op then
         return 1 + cl_depth rl_mat f;
      if rl_bquap op then
         return rl_BQdepth f;
      if op eq 'not then
         return 1 + cl_depth rl_arg1 f;
      if rl_extbp op then
         return 1 + max(cl_depth rl_arg2l f, cl_depth rl_arg2r f);
      ASSERT( rl_tvalp op or cl_atfp f );
      return 0
   end;

asserted procedure cl_prenexp(f: Formula): Boolean;
   % Prenex predicate. This is not prepeared for bounded quantifiers.
   begin
      while rl_quap rl_op f do
         f := rl_mat f;
      return cl_qnum f = 0
   end;

%DS
% <MULTIPLICITY LIST> ::= (..., (<S-EXPRESSION> . <OCCURRENCES>), ...)
% <OCCURRENCES> ::= <INTEGER>

asserted procedure cl_f2ml(f: Formula, client: Applicable): List;
   % Common logic formula to multiplicity list. Apply client to all atomic
   % formulas, and merge the obtained multiplicity lists. Consideration of
   % bounds is context-dependent.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp f then
         return nil;
      if rl_boolp op then
         return lto_almerge(for each subf in rl_argn f collect cl_f2ml(subf, client), 'plus2);
      if rl_quap op then
         return cl_f2ml(rl_mat f, client);
      if rl_bquap op then
         return rl_BQf2ml(f, client);
      ASSERT( cl_atfp f );
      return apply(client, {f})
   end;

rl_provideService rl_atml = cl_atml using rl_ordatp;

asserted procedure cl_atml(f: Formula): List;
   % Common logic atomic formula multiplicity list. Returns a multiplicity
   % list of the atomic formulas occurring in f, sorted wrt. rl_ordatp.
   % Consideration of bounds is context-dependent.
   sort(cl_atml1 f, function(lambda(x, y); rl_ordatp(car x, car y)));

asserted procedure cl_atml1(f: Formula): List;
   % Common logic atomic formula multiplicity list. Returns an unsorted
   % multiplicity list of the atomic formulas occurring in f. Consideration
   % of bounds is context-dependent.
   cl_f2ml(f, 'cl_atmlc);

asserted procedure cl_atmlc(atf: AtFormula): List;
   {atf . 1};

rl_provideService rl_atl = cl_atl using rl_ordatp;

asserted procedure cl_atl(f: Formula): List;
   % The set of atomic formulas contained in f as a list, sorted wrt.
   % rl_ordatp. Consideration of bounds is context-dependent.
   sort(cl_atl1 f, 'rl_ordatp);

asserted procedure cl_atl1(f: Formula): List;
   % The set of atomic formulas contained in f as an unsorted list.
   % Consideration of bounds is context-dependent.
   for each x in cl_atml1 f collect car x;

rl_provideService rl_ifacml = cl_ifacml using rl_fctrat, rl_tordp;

asserted procedure cl_ifacml(f: Formula): List;
   % Multiplicity list of irreducible factors of the terms occurring in f. The
   % result is sorted wrt. rl_tordp. Consideration of bounds is
   % context-dependent.
   sort(cl_ifacml1 f, function(lambda(x, y); rl_tordp(car x, car y)));

asserted procedure cl_ifacml1(f: Formula): List;
   % Unsorted multiplicity list of irreducible factors of the terms occurring
   % in f. Consideration of bounds is context-dependent.
   cl_f2ml(f, 'rl_fctrat);

rl_provideService rl_ifacl = cl_ifacl using rl_fctrat, rl_tordp;

asserted procedure cl_ifacl(f: Formula): List;
   % The set of irreducible factors of the terms occurring in f as a list,
   % sorted wrt. rl_ordatp. Consideration of bounds is context-dependent.
   sort(cl_ifacl1 f, 'rl_tordp);

asserted procedure cl_ifacl1(f: Formula): List;
   % The set of irreducible factors of the terms occurring in f as an unsorted
   % list. Consideration of bounds is context-dependent.
   for each x in cl_ifacml1 f collect car x;

rl_provideService rl_ifacdegl = cl_ifacdegl using rl_tordp;

asserted procedure cl_ifacdegl(f: Formula): DottedPair;
   % Irreducible factors degree lists. Returns a pair al_f . al _b of alists.
   % al_f contains pairs x . d, where d is the maximal degree of x in the
   % irreducible non-unit factors all terms of f in which x is free. al_b is
   % the analogue for bound occurrences. Both al_f and and a_b are sorted
   % wrt. rl_tordp on the variables.
   begin scalar fvarl, bvarl, facl, fal, bal; integer d;
      fvarl . bvarl := cl_varl1 f;
      facl := cl_ifacl1 f;
      for each v in fvarl do <<
         d := 0;
         for each p in facl do
            d := max(d, degreef(p, v));
         fal := (v . d) . fal
      >>;
      for each v in bvarl do <<
         d := 0;
         for each p in facl do
            d := max(d, degreef(p, v));
         bal := (v . d) . bal
      >>;
      fal := sort(fal, function(lambda(x, y); rl_tordp(car x, car y)));
      bal := sort(bal, function(lambda(x, y); rl_tordp(car x, car y)));
      return fal . bal
   end;

rl_provideService rl_matrix = cl_matrix;

asserted procedure cl_matrix(f: Formula): Formula;
   % Remove all leading quantifiers from f.
   if rl_quap rl_op f then cl_matrix rl_mat f else f;

rl_provideService rl_all = cl_all;

asserted procedure cl_all(f: Formula, exclude: KernelL): Formula;
   % Universal closure of f, but leaving the variables in exclude free.
   cl_closure('all, f, exclude);

rl_provideService rl_ex = cl_ex;

asserted procedure cl_ex(f: Formula, exclude: KernelL): Formula;
   % Existential closure of f, but leaving the variables in exclude free.
   cl_closure('ex, f, exclude);

asserted procedure cl_closure(q: Id, f: Formula, exclude: KernelL): Formula;
   % q-closure of f, but leaving the variables in exclude free.
   begin scalar freevarl, result;
      freevarl := reversip car cl_varl f;
      for each v in exclude do
         freevarl := lto_delqip(v, freevarl);
      result := f;
      for each x in freevarl do
         result := rl_mkq(q, x, result);
      return result
   end;

rl_provideService rl_termml = cl_termml using rl_termmlat, rl_tordp;

procedure cl_termml(f);
   % Common logic term multiplicity list. [f] is a formula. Returns
   % the MULTIPLICITY LIST of all non-zero terms occurring in
   % [f]. The result is sorted wrt. [rl_tordp].
   sort(cl_termml1 f, function(lambda(x, y); rl_tordp(car x, car y)));

procedure cl_termml1(f);
   % Common logic term multiplicity list subroutine. [f] is a formula.
   % Returns the MULTIPLICITY LIST of all non-zero terms occurring in
   % [f].
   cl_f2ml(f, 'rl_termmlat);

rl_provideService rl_terml = cl_terml using rl_tordp;

procedure cl_terml(f);
   % Common logic term list. [f] is a formula. Returns the set of all
   % non-zero terms occurring in [f] as a list. The result is sorted wrt.
   % [rl_tordp].
   sort(cl_terml1 f, 'rl_tordp);

procedure cl_terml1(f);
   % Common logic term list subroutine. [f] is a formula. Returns the
   % set of all non-zero terms occurring in [f] as a list.
   for each x in cl_termml1 f collect car x;

rl_provideService rl_struct = cl_struct using rl_structat, rl_ifstructat;

asserted procedure cl_struct(f: Formula, fac: Boolean, v: Id): DottedPair;
   if fac then cl_ifstruct(f, v) else cl_struct0(f, v);

asserted procedure cl_struct0(f: Formula, v: Id): DottedPair;
   % Structure of a formula. Returns a pair f_abstract . assignment.
   % f_abstract is a formula with left hand side terms v_1, ..., v_n.
   % assignment ist a list of pairs ((v_1 . t_1), ..., (v_n . t_n)).
   % Substitution of t_1, ..., t_n for v_1, ..., v_n into f_abstract yields
   % f.
   begin scalar w; integer j;
      w := cl_terml(f);
      w := for each s in w collect
         s . mkid(v, j := j + 1);
      return cl_struct1(f, w) . for each pr in w collect cdr pr . car pr
   end;

asserted procedure cl_struct1(f: Formula, al: Alist): Formula;
   cl_apply2ats1(f, 'rl_structat, {al});

asserted procedure cl_ifstruct(f: Formula, v: Id): DottedPair;
   % Irreducible factor structure of a formula. Returns a pair f_abstract .
   % assignment. f_abstract is a formula where all left hand side terms are
   % products of variables v_1, ..., v_n. assignment is a list of pairs (
   % (v_1 . t_1), ..., (v_n . t_n)), where the terms t_i are irreducible.
   % Substitution of t_1, ..., t_n for v_1, ..., v_n into f_abstract yields
   % f.
   begin scalar w; integer j;
      w := cl_ifacl(f);
      w := for each s in w collect
         s . mkid(v, j := j + 1);
      return cl_ifstruct1(f, w) . for each pr in w collect cdr pr . car pr
   end;

asserted procedure cl_ifstruct1(f: Formula, al: Alist): Formula;
   cl_apply2ats1(f, 'rl_ifstructat, {al});

rl_provideService rl_surep = cl_surep using rl_multsurep;

asserted procedure cl_surep(at: AtFormula, atl: List): Boolean;
   % Sure predicate. Heurictically test whether atl entails at.
   if !*rlspgs then
      rl_gsn(at, atl, 'dnf) eq 'true or rl_multsurep(at, atl)
   else
      rl_simpl(at, atl, -1) eq 'true or rl_multsurep(at, atl);

asserted procedure cl_flip(op: Id): Id;
   % Logical negation of the first-order operator op.
   if op eq 'and then 'or
   else if op eq 'or then 'and
   else if op eq 'all then 'ex
   else if op eq 'ex then 'all
   else if op eq 'ball then 'bex
   else if op eq 'bex then 'ball
   else if op eq 'true then 'false
   else if op eq 'false then 'true
   else rederr {"cl_flip(): don't know", op};

asserted procedure cl_cflip(op: Id, flag: ExtraBoolean): Id;
   % Conditional logical negation of the first-order operator op. Note that
   % negation takes place with flag = nil.
   if flag then op else cl_flip op;

%DS
% <QBLK> ::= (<QUANTIFIER> . <VARLIST>)
% <QUANTIFIER> ::= ['ex] | ['all]
% <VARLIST> ::= (..., <VARIABLE>, ...)

procedure cl_splt(f);
   % Common logic split. [f] is a formula in prenex normal form.
   % Returns a list $(\Gamma, \phi, \Lambda)$, where $\Gamma$ is a list
   % of QBLK's, $\phi$ is the quantifier-free matrix formula of [f], 
   % and $\Lambda$ is the list of all bound variables. $\Gamma$
   % contains the quantifier blocks of [f] in reverse order.
   begin scalar w, q, vl, qblkl, bvl, v;
      q := rl_op f;
      if not(q memq '(ex all)) then
         return {nil, f, nil};
      while (w := rl_op f) memq '(ex all) do <<
         v := rl_var f;
         bvl := v . bvl;
         if w eq q then
            vl := v . vl
         else <<
            qblkl := (q . vl) . qblkl;
            q := w;
            vl := {v}
         >>;
         f := rl_mat f
      >>;
      qblkl := (q . vl) . qblkl;
      return {qblkl, f, bvl}
   end;

procedure cl_atl2b(atl);
   % List of atoms to bound. [atl] is a list of atoms. Returns a fof.
   if null atl then
      'false  % caveat: smkn would give true!
   else rl_smkn('and, atl);

% The following should either become a service or should be moved to rl.
% Regarding service, note that there is already another service rlex2 below,
% which is the ex2-closure.

operator ex2;

asserted procedure ex2(vars: List, f: Formula): Formula;
   % AM interface.
   <<
      vars := if eqcar(vars, 'list) then cdr vars else {vars};
      rl_mk!*fof cl_ex21(vars, rl_simp f)
   >>;

rl_provideService rl_ex2 = cl_ex2 using rl_mkequation;

asserted procedure cl_ex2(f: Formula, pl: List): Formula;
   % Existential closure wrt. "exist at least 2"-quantification
   begin scalar fvl, bvl, vl;
      fvl . bvl := rl_varl f;
      vl := lto_setminus(fvl, pl);
      return cl_ex21(vl, f)
   end;

asserted procedure cl_ex21(vl: List, f: Formula): Formula;
   % "exist at least 2"-quantification
   begin scalar w, fvl, bvl, vl, ql, sl, eqs, res;
      fvl . bvl := rl_varl f;
      for each v in vl do <<
         w := v;
         repeat w := mkid(w, '!#) until not memq(w, fvl) and not memq(w, bvl);
         ql := w . ql;
         sl := (v . w) . sl;
         eqs := rl_mkequation(v, w) . eqs
      >>;
      ql := nconc(ql, reversip vl);
      eqs := rl_mk1('not, rl_smkn('and, reversip eqs));
      res := rl_mkn('and, {f, cl_subfof(sl, f), eqs});
      for each q in ql do
         res := rl_mkq('ex, q, res);
      return res
   end;

asserted procedure cl_divide(f: Formula): DottedPair;
   % Divide QE problem into subproblems. Returns a pair j . l, where j is one
   % of "and", "or", and l is a list of formulas such that j(l) is equivalent
   % to f. The idea is to explicitly move "ex" inside disjuctions or "all"
   % inside conjunctions for using 3rd-party software as a fallback QE.
   begin scalar ql, varll, m, op, q, varl, l, w;
      {ql, varll, m} := cl_split cl_pnf f;
      if not ql or cdr ql then
         return 'or . {f};
      q := car ql;
      op := rl_op m;
      if not (q eq 'ex and op eq 'or) and not (q eq 'all and op eq 'and) then
         return 'or . {f};
      varl := car varll;
      l := for each subf in rl_argn m collect <<
         w := subf;
         for each v in varl do
            w := rl_mkq(q, v, subf);
         w
      >>;
      return op . l
   end;

% The following is not a service. It uses a function parameter in contrast to
% a black box.

asserted procedure cl_eval(f: Formula, subal: Any, evalat: Applicable);
   % f is a univariate positive formula.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return op;
      if op eq 'and then
         return cl_eval!-gand('and, rl_argn f, subal, evalat, 'true);
      if op eq 'or then
         return cl_eval!-gand('or, rl_argn f, subal, evalat, 'false);
      return apply(evalat, {f, subal})
   end;

asserted procedure cl_eval!-gand(gand: Id, argl: QfFormulaL, subal: Any, evalat: Applicable, gtrue: Id);
   begin scalar res;
      res := gtrue;
      while res eq gtrue and argl do
         res := cl_eval(pop argl, subal, evalat);
      return res
   end;

rl_provideService rl_sign = cl_sign using rl_signat;

asserted procedure cl_sign(f: Formula): Formula;
   cl_apply2ats(f, 'rl_signat);

rl_provideService cl_siaddatl = cl_siaddatl;
% SM only. Used by CGB

asserted procedure cl_siaddatl(atl: List, c: Formula): Formula;
   % Common logic simplifying add atomic formula list. [atl] is a list
   % of atomic formulas; [c] is [true], [false], a simplified atomic
   % formula, or a simplified conjunction of atomic formulas. Returns
   % [true], [false], a simplified atomic formula, or a simplified
   % conjunction of atomic formulas. The result is equivalent to
   % $\bigwedge [atl] \land [c]$.
   begin scalar w, sicd;
      if c eq 'false then
         return 'false;
      atl := cl_simplifyTheory atl;
      if atl eq 'inctheo then
         return 'false;
      sicd := if c eq 'true then
         nil
      else if cl_cxfp c then <<
         ASSERT( rl_op c eq 'and );
         rl_argn c
      >> else
         {c};
      w := rl_smupdknowl('and, nconc(atl, sicd), nil, 1);
      if w eq 'false then
         return 'false;
      w := rl_smmkatl('and, nil, w, 1);
      if w eq 'false then
         return 'false;
      if !*rlsiso then w := sort(w, 'rl_ordatp);
      return rl_smkn('and, w)
   end;

rl_provideService rl_qesil = cl_qesil;

asserted procedure cl_qesil(fl: List, theo: List): List;
   % QE-based simplification of a list of formulas. Eliminated formulas that are
   % implied by the conjunction of all others.
   begin scalar prem, test, sol, res; integer n;
      if !*rlverbose then <<
         n := length fl + 1;
         ioto_cterpri()
      >>;
      res := for each f in fl join <<
         prem := rl_mkn('and, {rl_smkn('and, theo), rl_smkn('and, delete(f, fl))});
         test := rl_all(rl_mk2('impl, prem, f), nil);
         if !*rlverbose then
            ioto_prin2 {"[", n := n - 1};
         sol := rl_qe(test, nil) where !*rlverbose = nil;
         if !*rlverbose then
            ioto_prin2 {if sol eq 'true then "!" else "", "] "};
            if sol neq 'true then
               {f}
      >>;
      if !*rlverbose then
         ioto_cterpri();
      return res
   end;

endmodule;  % [clmisc]

end;  % of file
