module clsimpl;
% Common logic simplification

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

%DS
% <theory> ::= (<atomic_formula>,...)

rl_provideService rl_simpl = cl_simpl using
   rl_negateat, rl_simplat1, rl_smupdknowl, rl_smrmknowl, rl_smcpknowl,
   rl_smmkatl, rl_ordatp, rl_susipost, rl_susitf, rl_susibin, rl_b2terml,
   rl_simplb, rl_b2atl, rl_bsatp;

asserted procedure cl_simpl(f: Formula, atl: List, n: Integer): Formula;
   % Common logic simplify. [f] is a formula; [atl] is a list of atomic
   % formulas, which are considered to describe a theory; [n] is an integer.
   % Depends on switches [!*rlsism], [!*rlsiso]. Returns the identifier
   % [inctheo] or a formula. [inctheo] means that [atl] is inconsistent. Else
   % the result is [f], simplified (wrt. [atl]). For non-negative [n],
   % simplification stops at level [n].
   begin scalar w;
      if null !*rlsism then
 	 return cl_simpl1(f, nil, n, nil);
      atl := cl_sitheo atl;
      if atl eq 'inctheo then
	 return rl_exc 'inctheo;
      w := rl_smupdknowl('and, atl, nil, n+1);
      if w eq 'false then
 	 return 'inctheo;
      return cl_simpl1(f, w, n, nil)
   end;

asserted procedure cl_sitheo(atl: List);
   % Common logic simplify theory. [atl] is a THEORY. Returns either a
   % list $l$ of atomic formulas, or the identifier [inctheo]. In the
   % first case the conjunction over $l$ is equivalent to the
   % conjuction over [atl], and $l$ contains only simplified atomic
   % formulas. The return value [inctheo] means that the conjunction
   % over [atl] is equivalent to [false].
   begin scalar atf, w, natl, !*rlsiexpla;
      while atl do <<
	 atf := car atl;
	 atl := cdr atl;
	 w := cl_simplat(atf, nil);
	 if w eq 'false then <<
	    atf := 'inctheo;
	    atl := nil
	 >> else if w neq 'true then
	    natl := w . natl
      >>;
      if atf eq 'inctheo then
	 return 'inctheo;
      return natl
   end;

asserted procedure cl_simpl1(f: Formula, knowl: Any, n: Integer, sop: Id): Formula;
   % Common logic simplify. [f] is a formula; [knowl] is an IRL; [n] is an
   % integer; [sop] is a CL operator. Depends on switches [!*rlsism],
   % [!*rlsiso]. Returns a formula. Simplifies [f] recursively using [knowl].
   begin scalar op, result, w, newknowl;
      if eqn(n,0) then
 	 return f;
      op := rl_op f;
      if rl_tvalp op then
 	 return f;
      if rl_junctp op then
	 return rl_smkn(op, cl_smsimpl!-junct(op, rl_argn f, knowl, n));
      if op eq 'not then <<
    	 result := cl_simpl1(rl_arg1 f, knowl, n-1, 'not);
    	 if rl_tvalp result then
 	    return cl_flip result;
	 if cl_atfp result then
 	    return rl_negateat result;
    	 return cl_negate!-invol(result)
      >>;
      if rl_quap op then <<
	 if !*rlsism then
 	    knowl := rl_smrmknowl(knowl, rl_var f);
    	 result := cl_simpl1(rl_mat f, knowl, n-1, op);
    	 if rl_tvalp result then
 	    return result;
	 if not (rl_var f memq cl_fvarl result) then
	    return result;
    	 return rl_mkq(op, rl_var f, result)
      >>;
      if rl_bquap op then <<
	 if !*rlsism then
 	    knowl := rl_smrmknowl(knowl, rl_var f);
       	 return cl_simplbq(f, knowl, n)
      >>;
      if op eq 'impl then
	 return cl_smsimpl!-imprep(rl_arg2l f, rl_arg2r f,knowl, n);
      if op eq 'repl then
	 return cl_smsimpl!-imprep(rl_arg2r f, rl_arg2l f, knowl, n);
      if op eq 'equiv then
	 return cl_smsimpl!-equiv(rl_arg2l f, rl_arg2r f, knowl, n);
      w := cl_simplat(f,sop);
      if !*rlsism then <<
	 op := rl_op w;
	 if rl_junctp op then
	    return rl_smkn(op, cl_smsimpl!-junct(op, rl_argn w, knowl, n));
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
      >>;
      if w then
 	 return w;
      rederr {"cl_simpl1(): unknown operator", op}
   end;

asserted procedure cl_simplbq(f: Formula, knowl: Any, n: Integer): Formula;
   % Common logic simplify bounded quantifier. [f] is a formula with bounded
   % quantifier as an operator; [knowl] is a theory; [n] is the current
   % boolean level. Returns a simplified equivalent formula. Assuming used
   % blackboxes rl_simplb, rl_b2atl and rl_bsatp to be "light". Blackbox
   % rl_b2terml used.
   begin scalar b, mtx;
      % Context-dependent bound simplification
      b := rl_simplb(rl_b f, rl_var f);
      % Bound's information to knowledge
      if !*rlsism then
	 knowl := rl_smupdknowl('and, rl_b2atl(b, rl_var f), knowl, n);
      % Matrix simplification detects trivial cases
      mtx := cl_simpl1(rl_mat f, knowl, n-1, rl_op f);
      f := cl_simpltb(rl_op f, rl_var f, b, mtx);
      % Moving formulas to bound
      if rl_bquap rl_op f then
      	 f := cl_simplstrb(rl_op f, rl_var f, rl_b f, rl_mat f);
      return if not rl_tvalp f and not rl_bquap rl_op f then
      	 % Note: Only trivial simplifications are performed for now
	 cl_simpl1(f, nil, -1, nil)
      else f
   end;

asserted procedure cl_simpltb(op: Id, var: Id, b: Formula, mtx: Formula): Formula;
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
      % rl_bsatp means, that satisfability test has failed.
      if not(var memq rl_fvarl mtx) and rl_bsatp(b, var) then
 	 return mtx;
      % Bound is an equation. Note: Should be only relevant if rlsism is off
      bfvl := cl_fvarl b;
      if rl_op b eq 'equal and null cdr bfvl and eqcar(bfvl, var) then
	 % Note: using a context speciefic bound simplifier one can do more
      	 return cl_subfof({var . car rl_b2terml(b, var)}, mtx);
      % Nothing was done
      return rl_mkbq(op, var, b, mtx)
   end;

asserted procedure cl_simplstrb(op: Id, var: Id, b: Formula, mtx: Formula): Formula;
   % Common logic simplify bounded quantifier strengthen bound. [mtx] is the
   % bounded quantifier matrix; [b] is the bound of the bounded quantifier; [op]
   % is the operator; [var] is the variable. Returns a simplified equivalent
   % formula.
   begin scalar neg, st, lv, vfl;
      if cl_atfp mtx and length cl_fvarl mtx = 1 and
	 car cl_fvarl mtx eq var and not pasf_univnlfp(mtx, var) then <<
	 if op eq 'ball then <<
	    b := rl_simplb(rl_smkn('and, rl_mkn('not, {mtx}) . {b}), var);
	    mtx := 'false
	 >>;
	 if op eq 'bex then <<
	    b := rl_simplb(rl_smkn('and, mtx . {b}), var);
	    mtx := 'true
	 >>;
	 % The formula is trivial, but it can be too expensive to find it out
	 return cl_simpltb(op, var, b, mtx)
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
	 b := rl_simplb(rl_smkn('and, b . st), var);
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
	 return cl_simpltb(op, var, b, mtx)
      >>;
      return rl_mkbq(op, var, b, mtx)
   end;

asserted procedure cl_negate!-invol(f: Formula): Formula;
   % Common logic negate applying the law of involutivity. [f] is a
   % formula. Returns $\phi$ if [f] is of the form $\lnot \phi$,
   % $\lnot [f]$ else.
   if rl_op f eq 'not then rl_arg1 f else rl_mk1('not,f);

asserted procedure cl_gand!-col(fl: List, n: Integer, gand: Id, knowl: Any): List;
   % Common logic generic ['and] collect. [fl] is a list of formulas; [n] is an
   % integer; [gand] is one of ['and], ['or]; [knowl] is an IRL. Returns a list
   % $l$ of simplified formulas such that $[gand](l)$ is equivalent to
   % $[gand]([fl])$. Moreover there are no truth values in $l$, and no element
   % of $l$ has [gand] as its top-level operator.
   begin scalar result, a, gtrue, gfalse;
      gtrue := cl_cflip('true, gand eq 'and);
      gfalse := cl_flip gtrue;
      while fl do <<
	 a := cl_simpl1(car fl, knowl, n-1, gand);
	 fl := cdr fl;
	 if a eq gfalse then <<
	    result := {gfalse};
	    fl := nil
	 >> else if a neq gtrue then
	    if rl_op a eq gand then
	       for each subf in rl_argn a do
		  result := lto_insert(subf, result)
      	    else
	       result := lto_insert(a, result)
      >>;
      return if result then reversip result else {gtrue}
   end;

asserted procedure cl_smsimpl!-junct(op: Id, junct: List, knowl: Any, n: Integer): List;
   % Common logic smart simplify. [op] is one of [and], [or]; [junct]
   % is a list of formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a list of formulas. Accesses the switch [!*rlsism]. With
   % [!*rlsism] on sophisticated simplifications are applied to
   % [junct].
   begin scalar break, w, atl, col, newknowl, a, wop, argl, sicol, natl;
      if not !*rlsism then
	 return cl_gand!-col(junct, n, op, nil);
      newknowl := rl_smcpknowl knowl;
      break := cl_cflip('false, op eq 'and);
      for each subf in junct do <<
	 w := if cl_atfp subf then cl_simplat(subf, op) else subf;
	 if cl_atfp w then atl := w . atl else col := w . col
      >>;
      newknowl := rl_smupdknowl(op, atl, newknowl, n);
      if newknowl eq 'false then
 	 return {break};
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
 	 return {break};
      atl := rl_smmkatl(op, knowl, newknowl, n);
      if atl eq break then
	 return {break};
      w := sicol;
      sicol := nil;
      for each x in w do
 	 sicol := lto_insert(x, sicol);
      if !*rlsiso then <<
	 atl := sort(atl, 'rl_ordatp);
	 if !*rlsisocx then
	    sicol := sort(sicol, 'cl_sordp)
      >>;
      w := nconc(atl, sicol);
      if w then
 	 return w;
      return {cl_flip break}
   end;

asserted procedure cl_sordp(f1: Formula, f2: Formula): ExtraBoolean;
   % This is a strict ordering.
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
	 if rl_var f1 neq rl_var f2 then
	    return not(ordp(rl_var f1, rl_var f2) and rl_var f1 neq rl_var f2)
	 else
	    return cl_sordp(rl_mat f1, rl_mat f2);
      if rl_bquap op1 then
	 if rl_var f1 neq rl_var f2 then
	    return not(ordp(rl_var f1, rl_var f2) and rl_var f1 neq rl_var f2)
	 else if rl_b f1 neq rl_b f2 then
	    return cl_sordp(rl_b f1, rl_b f2)
	 else
      	    return cl_sordp(rl_mat f1, rl_mat f2);
      return cl_sordpl(rl_argn f1, rl_argn f2)
   end;

asserted procedure cl_sordpl(fl1: List, fl2: List): ExtraBoolean;
   if not fl2 then
      nil
   else if not fl1 then
      t
   else if car fl1 neq car fl2 then
      cl_sordp(car fl1, car fl2)
   else
      cl_sordpl(cdr fl1, cdr fl2);

asserted procedure cl_ordopp(op1: Id, op2: Id): ExtraBoolean;
   % Operator less predicate. [op1] and [op2] are first-order operators. Returns
   % [t] iff $[op1] < [op2]$.
   op2 memq cdr (op1 memq '(and or not impl repl equiv bex ball ex all true false));

asserted procedure cl_smsimpl!-imprep(prem: Formula, concl: Formula, knowl: Any, n: Integer): Formula;
   % Common logic smart simplify implication/replication. [prem] and [concl] are
   % formulas; [knowl] is an IRL; [n] is an integer. Returns a formula
   % equivalent to [prem impl concl] assuming [knowl].
   begin
      if not !*rlsism then
	 return cl_imprep!-col(prem, concl, knowl, n);
      if cl_atfp prem then
 	 prem := cl_simplat(prem, 'prem);
      if cl_atfp concl then
 	 concl := cl_simplat(concl, 'concl);
      if prem eq 'false or concl eq 'true then
      	 return 'true;
      return cl_smsimpl!-imprep1(prem, concl, knowl, n)
   end;

asserted procedure cl_imprep!-col(prem: Formula, concl: Formula, knowl: Any, n: Integer): Formula;
   begin scalar w;
      prem := cl_simpl1(prem, knowl, n-1, 'prem);
      concl := cl_simpl1(concl, knowl, n-1, 'concl);
      if w := cl_smtvchk!-impl(prem, concl) then
	 return w;
      if prem = concl then return 'true;
      return rl_mk2('impl, prem, concl)
   end;

asserted procedure cl_smsimpl!-imprep1(prem: Formula, concl: Formula, knowl: Any, n: Integer): Formula;
   % Common logic smart simplify implication/replication. [prem] and
   % [concl] are formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a formula equivalent to [prem impl concl] assuming
   % [knowl].
   begin scalar w;
      if cl_atfp prem then
 	 return cl_smsimpl!-imprep!-atprem(prem, concl, knowl, n);
      if cl_atfp concl then
 	 return cl_smsimpl!-imprep!-atconcl(prem, concl, knowl, n);
      prem := cl_simpl1(prem, knowl, n-1, 'prem);
      concl := cl_simpl1(concl, knowl, n-1, 'concl);
      if w := cl_smtvchk!-impl(prem, concl) then
	 return w;
      if cl_cxfp prem and cl_cxfp concl then <<
	 if prem = concl then
	    return 'true;
	 return rl_mk2('impl, prem, concl)
      >>;
      % At least one of prem, concl has become atomic
      return cl_smsimpl!-imprep1(prem, concl, knowl, n)
   end;

asserted procedure cl_smtvchk!-impl(prem: Formula, concl: Formula): Formula;
   if prem eq 'true then
      concl
   else if concl eq 'false then
      cl_simpl(rl_mk1('not, prem), nil, 1)
   else if prem eq 'false or concl eq 'true then
      'true;

asserted procedure cl_smsimpl!-imprep!-atprem(atprem: Atom, concl: Formula, knowl: Any, n: Integer): Formula;
   begin scalar w, newknowl;
      newknowl := rl_smcpknowl knowl;
      if cl_atfp concl then
	 return cl_smsimpl!-impl(atprem, concl, knowl, newknowl, n);
      newknowl := rl_smupdknowl('and, {atprem}, newknowl, n);
      if newknowl eq 'false then
	 return 'true;
      concl := cl_simpl1(concl, newknowl, n-1, 'concl);
      if w := cl_smtvchk!-impl(atprem, concl) then
	 return w;
      if cl_atfp concl then
	 return cl_smsimpl!-impl(atprem, concl, knowl, newknowl, n);
      return rl_mk2('impl, atprem, concl)
   end;

asserted procedure cl_smsimpl!-imprep!-atconcl(prem: Formula, atconcl: Atom, knowl: Any, n: Integer): Formula;
   % CL smart simplify implication/replication with atomic formula
   % conclusion. [prem] is a complex formula; [atconcl] is a
   % simplified atomic formula; [knowl] is an IRL; [n] is an integer.
   % Returns a formula.
   begin scalar w, newknowl;
      newknowl := rl_smupdknowl('or, {atconcl}, rl_smcpknowl knowl, n);
      if newknowl eq 'false then
	 return 'true;
      prem := cl_simpl1(prem, newknowl, n-1, 'prem);
      if w := cl_smtvchk!-impl(prem, atconcl) then
	 return w;
      if cl_atfp prem then
	 return cl_smsimpl!-impl(prem, atconcl, knowl, newknowl, n);
      return rl_mk2('impl, prem, atconcl)
   end;

asserted procedure cl_smsimpl!-impl(atprem: Atom, atconcl: Atom, oldknowl: Any, newknowl: Any, n: Integer): Formula;
   % Common logic smart simplifier simplify implication. [atprem] and [atconcl]
   % are atomic formulas; [oldknowl] and [newknowl] are knowledge bases; [n] is
   % an integer. Returns a formula. This once was a generic implementation of a
   % blackbox.
   begin scalar w;
      w := cl_simpl1(rl_nnf rl_mk2('impl, atprem, atconcl), oldknowl, n, nil);
      if rl_tvalp w or cl_atfp w then
 	 return w;
      atprem := cl_simpl1(atprem, oldknowl, n, 'prem);
      atconcl := cl_simpl1(atconcl, oldknowl, n, 'concl);
      return rl_mk2('impl, atprem, atconcl)
   end;

asserted procedure cl_smtvchk!-equiv(lhs: Formula, rhs: Formula): Formula;
   if lhs eq 'true then
      rhs
   else if rhs eq 'true then
      lhs
   else if lhs eq 'false then
      cl_simpl(rl_mk1('not, rhs), nil, 1)
   else if rhs eq 'false then
      cl_simpl(rl_mk1('not, lhs), nil, 1);

asserted procedure cl_smsimpl!-equiv(lhs: Formula, rhs: Formula, knowl: Any, n: Integer): Formula;
   begin scalar w, newknowl;
      lhs := cl_simpl1(lhs, knowl, n-1, 'equiv);
      rhs := cl_simpl1(rhs, knowl, n-1, 'equiv);
      if w := cl_smtvchk!-equiv(lhs, rhs) then
	 return w;
      if lhs = rhs then
 	 return 'true;
      if null !*rlsism or cl_cxfp lhs or cl_cxfp rhs then <<
      	 if cl_ordp(lhs, rhs) then
 	    return rl_mk2('equiv, lhs, rhs);
      	 return rl_mk2('equiv, rhs, lhs)
      >>;
      newknowl := rl_smcpknowl(knowl);
      return cl_smsimpl!-equiv1(lhs, rhs, knowl, newknowl, n)
   end;

asserted procedure cl_smsimpl!-equiv1(lhs: Formula, rhs: Formula, oldknowl: Any, newknowl: Any, n: Integer): Formula;
   % Common logic smart simplifier simplify equivalence. [lhs] and
   % [rhs] are atomic formulas; [oldknowl] and [newknowl] are
   % knowledge bases; [n] is an integer. Returns a formula. This once was a
   % generic implementation of a blackbox.
   begin scalar w, x;
      w := cl_simpl1(rl_nnf rl_mk2('equiv, lhs, rhs), oldknowl, n, nil);
      if rl_tvalp w or cl_atfp w then
 	 return w;
      x := rl_argn w;
      if cl_atfp car x and cl_atfp cadr x and null cddr x then
	 return w;
      lhs := cl_simpl1(lhs, oldknowl, n, 'equiv);
      rhs := cl_simpl1(rhs, oldknowl, n, 'equiv);
      if cl_ordp(lhs, rhs) then
	 return rl_mk2('equiv, lhs, rhs);
      return rl_mk2('equiv, rhs, lhs)
   end;

asserted procedure cl_ordp(f1: Formula, f2: Formula): Boolean;
   % Common logic order predicate. [f1] and [f2] are formulas. Returns
   % [T] or [nil]. [nil] is returned if [f1] and [f2] are atomic
   % formulas and [f1] is less than [f2] wrt. [rl_ordatp].
   cl_cxfp f2 or (cl_atfp f1 and rl_ordatp(f1, f2));

asserted procedure cl_simplat(atf: Atom, sop: Id): QfFormula;
   % Common logic simplify atomic formula. [atf] is an atomic formula;
   % [sop] is a CL operator. Returns a quantifier-free formula
   % equivalent to [atf].
   if not !*rlidentify then
      rl_simplat1(atf, sop)
   else
      cl_apply2ats(rl_simplat1(atf, sop), 'cl_identifyat);

asserted procedure cl_identifyathfn(atf: Atom): List2;
   {rl_op atf, cl_varl1 atf};

asserted procedure cl_identifyat(atf: Atom): Atom;
   % Common logic identify atomic formula. [atf] is an atomic formula.
   % Returns an atomic formula equal to [atf].
   begin scalar w;
      if rl_tvalp atf then return atf;
      if (w := lto_hmember(atf, cl_identify!-atl!*, 'cl_identifyathfn)) then
 	 return car w;
      cl_identify!-atl!* :=
	 lto_hinsert(atf, cl_identify!-atl!*, 'cl_identifyathfn);
      return atf
   end;

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

rl_provideService rl_qesil = cl_qesil;
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
      atl := cl_sitheo atl;
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
	    ioto_prin2 {"[", n:=n-1};
	 sol := rl_qe(test, nil) where !*rlverbose=nil;
	 if !*rlverbose then
	    ioto_prin2 {if sol eq 'true then "!" else "", "] "};
      	 if sol neq 'true then
   	    {f}
      >>;
      if !*rlverbose then
	 ioto_cterpri();
      return res
   end;

endmodule;  % [clsimpl]

end;  % of file
