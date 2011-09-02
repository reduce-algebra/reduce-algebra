% ----------------------------------------------------------------------
% $Id: pasfsiat.red,v 1.31 2003/12/16 07:45:34 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: pasfsiat.red,v $
% Revision 1.31  2003/12/16 07:45:34  lasaruk
% Redlog normal form in the simplifier.
%
% Revision 1.30  2003/12/11 14:23:18  sturm
% Do not use domain gcd in pasf_gcd(). Not relevant QE appears to spend
% around 9% of time there.
%
% Revision 1.29  2003/11/07 12:07:52  sturm
% Fixed a bug in pasf_mkpos.
%
% Revision 1.28  2003/11/05 13:56:19  lasaruk
% Some more changes. pasf_content renamed to pasf_gcd with more
% exact specificaton. lisp, symbolic and some "comments" are removed.
%
% Revision 1.27  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.26  2003/10/28 09:59:11  dolzmann
% Added correct content of fluids pasf_siat_rcsid!* and
% pasf_siat_copyright!*.
%
% Revision 1.25  2003/10/28 09:56:36  dolzmann
% Removed trailing spaces.
% Changed true to 'true.
%
% Revision 1.24  2003/09/09 10:56:17  lasaruk
% check for correct form improoved
%
% Revision 1.23  2003/08/28 15:30:40  lasaruk
% Simplification verbose output done better. QE-Bug with truth values
% corrected (will be done more effitient). Some fancy examples added.
%
% Revision 1.22  2003/08/27 16:10:04  lasaruk
% Added switch rlpasfatfsimpvb to print out simplification steps if
% simplification was really done. Check for correct PASF form added.
%
% Revision 1.21  2003/08/12 10:33:05  lasaruk
% Value evaluation bug removed.
%
% Revision 1.20  2003/08/12 09:38:55  lasaruk
% Absent atomic formula simplification cases added. Testfile
% expanded. Testcases from Andreas checked.
%
% Revision 1.19  2003/08/05 12:05:14  lasaruk
% Standard simplification completely rewritten.
%
% Revision 1.18  2003/08/05 08:57:17  seidl
% Intermediate check-in.
%
% Revision 1.17  2003/07/22 08:45:03  seidl
% Improved simplifiations of equations and negated equations. Still there
% can be done more. Simplification of atomic formulas has to be thoroughly
% revised.
%
% Revision 1.16  2003/07/10 07:54:30  seidl
% Added cvs header and logs up to 1.15.
%
% ----------------------------------------------------------------------
% revision 1.15
% date: 2003/04/20 12:04:04;  author: lasaruk;  state: Exp;  lines: +0 -3
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
% ----------------------------
% revision 1.14
% date: 2003/04/14 10:11:39;  author: lasaruk;  state: Exp;  lines: +4 -1
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
% ----------------------------
% revision 1.13
% date: 2003/03/04 09:33:23;  author: lasaruk;  state: Exp;  lines: +64 -30
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
% ----------------------------
% revision 1.12
% date: 2003/02/28 11:55:40;  author: lasaruk;  state: Exp;  lines: +55 -90
% Simplifier congruence bug removed. Switch siatadv now actively used.
% ----------------------------
% revision 1.11
% date: 2003/02/17 10:55:40;  author: lasaruk;  state: Exp;  lines: +22 -15
% Stable full featured version
% ----------------------------
% revision 1.10
% date: 2003/01/21 17:39:14;  author: lasaruk;  state: Exp;  lines: +13 -13
% Switch rlsiatadv turned off. Bugs fixed.
% ----------------------------
% revision 1.9
% date: 2003/01/06 18:20:32;  author: lasaruk;  state: Exp;  lines: +5 -5
% Bugs fixed
% ----------------------------
% revision 1.8
% date: 2003/01/06 17:33:27;  author: lasaruk;  state: Exp;  lines: +5 -7
% Some simplifier bugs fixed. Alternating quantifier elimination attached.
% ----------------------------
% revision 1.7
% date: 2003/01/05 15:55:05;  author: lasaruk;  state: Exp;  lines: +7 -5
% Simplification improoved. Expansion of range predicates added.
% ----------------------------
% revision 1.6
% date: 2002/12/31 13:57:49;  author: lasaruk;  state: Exp;  lines: +5 -5
% Simplifier bugs fixed.
% ----------------------------
% revision 1.5
% date: 2002/12/31 13:33:34;  author: lasaruk;  state: Exp;  lines: +44 -21
% Standard simplifier attached. Standard simplification of expressions
% attached.
% ----------------------------
% revision 1.4
% date: 2002/12/23 07:07:40;  author: lasaruk;  state: Exp;  lines: +15 -15
% Simplifier corrected
% ----------------------------
% revision 1.3
% date: 2002/10/18 13:39:11;  author: lasaruk;  state: Exp;  lines: +1 -1
% QE one variable preparation added. No bounded quantifiers first.
% ----------------------------
% revision 1.2
% date: 2002/10/10 09:09:20;  author: lasaruk;  state: Exp;  lines: +15 -11
% Range predicate implemented. Todo: logical negation of range predicate
% ----------------------------
% revision 1.1
% date: 2002/10/02 14:31:19;  author: lasaruk;  state: Exp;
% Initial check in. Only dummy methods for advanced simplification first.
% ======================================================================

lisp <<
   fluid '(pasf_siat_rcsid!* pasf_siat_copyright!*);
   pasf_siat_rcsid!* := "$Id: pasfsiat.red,v 1.31 2003/12/16 07:45:34 lasaruk Exp $";
   pasf_siat_copyright!* :=
      "Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfsiat;

% Presburger arithmetic standard form simplification. Submodule of
% [pasf].

% Datastructure <TNF> for term normal form.
% <TMF> = (<CONST>,<COEF>,<VARS>)
% <CONST> = a_0 is the integer constant part of the term
% <COEF> = (a_1,a_2,a_3, ... , a_n)
% <VARS> = (x_1,x_2,x_3, ... , x_n)
% The interpretation of <TNF> as a term in normal form is
% $t = a_0 + \sum_{i=1}^{n} a_i x_i$

procedure tnf_atf2tnf(atf);
   % Term normal form constructor from an atomic formula. [atf] is an
   % atomic formula in redlog normal form. Returns a new <TNF>
   % structure for the left hand side of [atf].
   tnf_expr2tnf pasf_arg2l atf;

procedure tnf_expr2tnf(exps);
   % Term normal form constructor from an expression. [exps] is an
   % expression. Returns a new <TNF> structure for the expression
   % [exps].
   begin scalar as,xs;
      while not domainp exps do <<
	 if ldeg exps <> 1 then
	    rederr {"termnf_atf2tnf : invalid PASF formula :",
	       "polynome degree for",mvar exps,"is greater than 1"};
	 if not domainp lc exps then
	    rederr {"termnf_atf2tnf : invalid PASF formula :",
	       "non constant leading coefitient"};
	 as := (if lc exps then lc exps else 0) . as;
	 xs := (mvar exps) . xs;
	 exps := red exps
      >>;
      % Replacing "nil" by 0
      return {if exps then exps else 0,as,xs}
   end;

procedure tnf_new(const,coef,vars);
   % Term normal form constructor. [const] ist the constant part of
   % the term; [coef] are the variable coefitients; [vars] are the
   % free variables. Returns a <TNF> representing the term.
   {if const then const else 0,coef,vars};

procedure tnf_const(tnf);
   % Term normal form accessor for the constant part of the term.
   % [tnf] is a <TNF> structure. Returns the constant part of the
   % term.
   car tnf;

procedure tnf_coef(tnf);
   % Term normal form accessor for the coefitients of the term. [tnf]
   % is a <TNF> structure. Returns the coefitients of the term.
   cadr tnf;

procedure tnf_vars(tnf);
   % Term normal form accessor for the cariables of the term. [tnf] is
   % a <TNF> structure. Returns the variables of the term.
   caddr tnf;

procedure tnf_tnf2expr(tnf);
   % Term normal form accessor for the term structure. [tnf] is
   % a <TNF> structure. Returns a term derived from the <TNF>.
   begin scalar term,vars;
      vars := tnf_vars tnf;
      for each coef in tnf_coef tnf do <<
	 term := addf(term,multf(numr simp coef,numr simp car vars));
	 vars := cdr vars
      >>;
      return addf(numr simp tnf_const tnf,term)
   end;

procedure pasf_simplat1(atf,sop);
   % Presburger arithmetic standard form simplify atomic formula.
   % [atf] is an atomic formula; [sop] is the boolean operator [atf]
   % occurs with or [nil]. Accesses switches [rlsiatadv]. Returns a
   % quantifier-free formula that is a simplified equivalent of [atf].
   begin scalar tnf,m,tnfm,c;
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then <<
	 prin2t "Simplifying atomic formula";
	 mathprint rl_mk!*fof atf
      >>;
      % Conversion to normal form (NF)
      atf := pasf_mkpos atf;
      tnf := tnf_atf2tnf atf;
      % Evaluation of variable free terms (VF)
      if null tnf_vars tnf then	<<
      	 % Verbose check for simplification
      	 if !*rlpasfatfsimpvb then
	    prin2!* "[VF]";
      	 return if pasf_evalatp(pasf_op atf,tnf_const tnf) then
	    'true
	 else
	    'false;
      >>;
      % Congruences are treated differently as non-congruences
      if pasf_opn atf memq '(cong ncong) then <<
	 m := pasf_m atf;
	 tnf := pasf_mr(tnf,m);
      	 % Variable free terms are possible
	 c := pasf_gcd tnf_coef tnf;
	 % Now if the content is 0 then the whole list had only
	 % zeros. Evaluating the formula
	 if c = 0 then <<
      	    if !*rlpasfatfsimpvb then
	       prin2!* "[VFs]";
	    return if pasf_evalatp(pasf_op atf,tnf_const tnf) then
	       'true
	    else
	       'false
	 >>;
	 tnfm := pasf_cecong(tnf,m);
	 tnf := car tnfm;
	 m := cdr tnfm
      >> else
	 tnf := if pasf_opn atf memq '(equal neq) then
	    pasf_ceeq tnf
	 else
	    pasf_cein(tnf,pasf_opn atf);
      % Advanced simplification
      if !*rlsiatadv then <<
	 % Solvability of diophantine (in-)equations (SE-Rule)
	 if pasf_opn atf eq 'equal and not pasf_se tnf then
	    return 'false;
	 if pasf_opn atf eq 'neq and not pasf_se tnf then
	    return 'true;
	 % Solvability of congruences
	 if pasf_opn atf eq 'cong and pasf_sc(tnf,m) then
	    return 'false;
	 if pasf_opn atf eq 'ncong and pasf_sc(tnf,m) then
	    return 'true
      >>;
      return if pasf_opn atf memq '(cong ncong) then
	 pasf_mk2(pasf_mkop(pasf_opn atf,m),tnf_tnf2expr tnf,nil)
      else
	 pasf_mk2(pasf_opn atf,tnf_tnf2expr tnf,nil)
   end;

procedure pasf_mkpos(atf);
   % Presburger arithmetic standard form make atomic formula positive.
   % [atf] is an atomic formula. Returns an equivalent atomic formula
   % with a positive leading coefitient.
   if minusf pasf_arg2l atf then
      	 pasf_anegateat atf
   else
      atf;

procedure pasf_mr(tnf,m);
   % Presburger arithmetic standard form modulo reduction. [tnf] is a
   % <TNF> structure. Returns a <TNF> that represents the modulo free
   % term.
   begin scalar c,as,xs,succ;
      % print tnf;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Verbose check for simplification
      for each a in as do
	 if !*rlpasfatfsimpvb then
	    if remainder(a,m) <> a then
	       succ := 't;
      as := for each a in as collect
	 remainder(a,m);
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then
	 if remainder(c,m) <> c then
	    succ := 't;
      if succ then prin2!* "[MR]";
      return tnf_new(remainder(c,m),as,xs);
   end;

procedure pasf_ceeq(tnf);
   % Presburger arithmetic standard form content elimination (CE) for
   % equalities. [tnf] is a <TNF> structure. Returns a <TNF> that
   % represents a term with eliminated content.
   begin scalar c,as,xs,g;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Computing the content of the coefitients list joined with the
      % constant part
      g := pasf_gcd(c . as);
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then
	 if g <> 1 then
	    prin2!* "[CE(n)eq]";
      as := for each a in as collect
	 a/g;
      return tnf_new(c/g,as,xs)
   end;

procedure pasf_cein(tnf,op);
   % Presburger arithmetic standard form content elimination (CE) for
   % inequalities. [tnf] is a <TNF> structure; [op] is the inequality
   % operator. Returns a <TNF> that represents a term with eliminated
   % content.
   begin scalar c,as,xs,g;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Computing the content
      g := pasf_gcd as;
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then
	 if g <> 1 then
	    prin2!* "[CEineq]";
      as := for each a in as collect
	 a/g;
      return
	 if op memq '(leq,greaterp) then
	    tnf_new(negf pasf_floor(-c,g),as,xs)
	 else if op memq '(geq,lessp) then
	    tnf_new(negf pasf_ceil(-c,g),as,xs)
	 else
	    rederr {"pasf_cein : invalid inequality operator",op}
   end;

procedure pasf_cecong(tnf,m);
   % Presburger arithmetic standard form content elimination (CE) for
   % congruences. [tnf] is a <TNF> structure; [m] is the
   % modulus. Returns a dotted pair $(<TNF> . modulus)$ that
   % represents a term with eliminated content.
   begin scalar c,as,xs,g,prime;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Computing if the modulus is prime. Is used not to call
      % "primep" twice
      prime := primep m;
      % Computing the content with modulus
      g := if prime then
	 % In case of prime modulus the modulo ring is a field and so
	 % content division is always possible
      	 pasf_gcd(c . as)
      else
      	 pasf_gcd(c . m . as);
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then
	 if g <> 1 then
	    prin2!* "[CEcong]";
      as := for each a in as collect
	 a/g;
      return if prime then
	 (tnf_new(c/g,as,xs) . m)
      else
	 (tnf_new(c/g,as,xs) . (m/g))
   end;

procedure pasf_se(tnf);
   % Presburger arithmetic standard form (un-)solvability check for
   % (in-)equalities. [tnf] is a <TNF> structure. Returns ['t] if and
   % only if the $gcd(\{a_1, ..., a_n\} \setminus \{0\}) \mid a_0$.
   begin scalar c,as,xs,g;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Computing the content of the coefitients list
      g := pasf_gcd as;
      % Verbose check for simplification
      if !*rlpasfatfsimpvb then
	 if remainder(c,g) <> 0 then
	    prin2!* "[SE]";
      return (remainder(c,g) = 0)
   end;

procedure pasf_sc(tnf,m);
   % Presburger arithmetic standard form (un-)solvability check for
   % (non-)congruences. [tnf] is a <TNF> structure. Returns ['t] if
   % and only if the $m \mid j * gcd(\{a_1, ..., a_n\} \setminus \{0\})
   % + a_0$ for all $0 <= j < m$.
   begin scalar c,as,xs,g,res;
      c := tnf_const tnf;
      as := tnf_coef tnf;
      xs := tnf_vars tnf;
      % Computing the content of the coefitients list
      g := pasf_gcd as;
      % Verbose check for simplification
      res := 'true;
      for j := 0 : m do
	 res := res and (remainder(c + j*g,m) <> 0);
      if !*rlpasfatfsimpvb then
	 if res then
	    prin2!* "[SC]";
      return res
   end;

procedure pasf_gcd(coefl);
   % Presburger arithmetic standard form list gcd computation. [coefl]
   % is a list of integers. Returns the $\gcd(coefl)$.
   if null coefl then 0 else gcdn(car coefl,pasf_gcd cdr coefl);

procedure pasf_evalatp(rel,lhs);
   % Presburger arithmetic standard form evaluate atomic
   % formula. [rel] is a relation; [lhs] is a domain element; Returns
   % a truth value equivalent to $[rel]([lhs],0)$.
   if pairp rel and car rel memq '(cong ncong) then
      pasf_evalatpm(car rel,lhs,cdr rel)
   else
      pasf_evalatpm(rel,lhs,nil);

procedure pasf_evalatpm(rel,lhs,m);
   % Presburger arithmetic standard form evaluate atomic formula
   % subroutine. [rel] is a relation; [lhs] is a domain element; [m]
   % is an optional modulus; Returns a truth value equivalent to
   % $[rel]([lhs],0)$.
   if rel eq 'equal then null lhs or lhs = 0
   else if rel eq 'neq then not (null lhs or lhs = 0)
   else if rel eq 'leq then minusf lhs or (null lhs or lhs = 0)
   else if rel eq 'geq then not minusf lhs
   else if rel eq 'lessp then minusf lhs
   else if rel eq 'greaterp then not (minusf lhs or null lhs or lhs = 0)
   else if rel eq 'cong then (null lhs or lhs = 0) or 0 = remainder(lhs,m)
   else if rel eq 'ncong then not ((null lhs or lhs = 0)
      or 0 = remainder(lhs,m))
   else rederr {"pasf_evalatp: unknown operator",rel};

endmodule;  % [pasfsiat]

end;  % of file
