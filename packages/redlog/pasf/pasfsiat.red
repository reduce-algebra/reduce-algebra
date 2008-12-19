% ----------------------------------------------------------------------
% $Id: pasfsiat.red,v 1.50 2008/01/27 15:05:53 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Log: pasfsiat.red,v $
% Revision 1.50  2008/01/27 15:05:53  lasaruk
% Quoted 't replaced by t
%
% Revision 1.49  2007/07/29 00:59:31  lasaruk
% Congruence case in PQE implemented. Small bug in pasf_siat.red corrected.
%
% Revision 1.48  2007/06/22 12:47:52  lasaruk
% Factorization of inequalities
%
% Revision 1.47  2007/06/21 18:43:49  lasaruk
% Factorization of atomic formulas, smart substitution
%
% Revision 1.46  2007/03/22 17:45:35  lasaruk
% rlint bug reports corrected
%
% Revision 1.45  2005/08/04 11:03:58  lasaruk
% Uniform comments
%
% Revision 1.44  2005/07/17 16:56:34  lasaruk
% Comments rewritten
%
% Revision 1.43  2005/04/29 12:17:16  lasaruk
% Debugging code removed
%
% Revision 1.42  2005/04/27 19:39:23  lasaruk
% Version the tests for diplomarbeit ran on
%
% Revision 1.41  2005/04/22 20:29:25  lasaruk
% Elimination set conflating added
%
% Revision 1.40  2005/03/17 16:58:45  lasaruk
% Code structure changed
%
% Revision 1.39  2005/02/24 15:20:03  lasaruk
% QE code completely rewritten using a correct representant choice
%
% Revision 1.38  2005/01/28 02:29:28  lasaruk
% Treatement of domain valued congruences with parametric modulus corrected
%
% Revision 1.37  2005/01/24 23:32:50  lasaruk
% Minor changes while debugging
%
% Revision 1.36  2005/01/24 20:52:44  lasaruk
% Correct semantics for substituting negative denominators and
% correct congruence handling.
%
% Revision 1.35  2005/01/22 19:36:34  lasaruk
% Atomic formula simplification works now with uniform presburger arithmetic
%
% Revision 1.34  2004/08/29 20:42:13  lasaruk
% Simplification of atomic formulas rewritten without the term
% normal form. Administration details switches and other
% stuff put into some order and are commented now. Floor and
% ceil procedures corrected to fit the semantics. pasf_susidec
% moved to pasf_dec. pasf_deci for integer decomposition added.
% In QE the simplification is done at the last stage even if
% rlpasfsimplify is turned off. All sutable rl_mkn's are turned
% to rl_smkn. In pasfsiat.red order reduction has been added.
% In pasfsism.red substitution and simplification goals have
% been revisited. Configuration tested on more than 3*10^5
% formulas with different structure.
% Revision 1.33  2004/08/18 12:12:01  lasaruk
% error message in pasf_atf2tnf corrected
%
% Revision 1.32  2004/08/11 15:17:08  lasaruk
% New comments done. Now automatic procedure documentation possible. 
% Some code rewritten.
%
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
   pasf_siat_rcsid!* := "$Id: pasfsiat.red,v 1.50 2008/01/27 15:05:53 lasaruk Exp $";
   pasf_siat_copyright!* :=
      "Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfsiat;
% Presburger arithmetic standard form atomic formula simplification. Submodule
% of PASF.

procedure pasf_simplat1(atf,sop);
   % Presburger arithmetic standard form simplify atomic formula. [atf] is an
   % atomic formula; [sop] is the boolean operator [atf] occurs with or
   % nil. Returns a quantifier-free formula that is a simplified equivalent of
   % [atf].
   begin
      % Conversion to normal form (NF) and evaluation of variable free atomic
      % formulas
      atf := pasf_vf pasf_dt pasf_mkpos pasf_zcong atf;
      if rl_tvalp atf then return atf;
      % Congruences are treated differently as non-congruences
      if pasf_congp atf then
	 % Total modulo reduction possible; content elimination for
	 % congruences (CEcong)
	 atf := pasf_cecong pasf_vf pasf_mr atf
      else (if pasf_opn atf memq '(equal neq) then
	 atf := pasf_ceeq atf
      else
	 atf := pasf_cein atf);
      % Checking if done yet
      if rl_tvalp atf then return atf;
      % Advanced simplification
      atf := if pasf_opn atf memq '(cong ncong) then	       
	 % Solvability of congruences (SECong)
	 pasf_sc atf
      else if pasf_opn atf memq '(equal neq) then
	 % Solvability of diophantine (in-)equations (SE-Rule)	 
	 pasf_se atf
      else
	 % Order relation reduction
	 pasf_or atf;
      % Factorization check
      return pasf_fact atf;
   end;

procedure pasf_zcong(atf);
   % Presburger arithmetic standard form zero congruences. [atf] is an atomic
   % formula. Returns an equality if modulus of the congruence is zero.
   if pasf_congp atf then (
      if null pasf_m atf then
      	 pasf_0mk2(if pasf_opn atf eq 'cong then 'equal else 'neq,
	    pasf_arg2l atf)
      else if null pasf_arg2l atf and pasf_opn atf eq 'cong then 'true
      else if null pasf_arg2l atf and pasf_opn atf eq 'ncong then 'false
      else atf) 
   else 
      atf;

procedure pasf_mkpos(atf);
   % Presburger arithmetic standard form make atomic formula positive. [atf]
   % is an atomic formula. Returns an equivalent atomic formula with a
   % positive leading coefficient.
   begin scalar res;
      % Left handside 
      res := if not(rl_tvalp atf) and minusf pasf_arg2l atf then
      	 pasf_anegateat atf
      else
	 atf;
      % Congruences with negative modulus
      if pasf_congp res and minusf pasf_m res then
	 res := pasf_0mk2(((pasf_opn res) . (negf pasf_m res)),pasf_arg2l res);
      return res
   end;

procedure pasf_vf(atf);
   % Presburger arithmetic standard form evaluation of variable free atomic
   % formulas. [atf] is an atomic formula. Returns [atf] if it is not
   % variable-free or a truth value.
   begin
      if (not(rl_tvalp atf) and domainp pasf_arg2l atf) then <<
	 % Parametric modulus
	 if pasf_congp atf and null domainp pasf_m atf then
	    if null pasf_arg2l atf then 
	       return 'false
	    else
	       return atf;
      	 return if pasf_evalatp(pasf_op atf,pasf_arg2l atf) then
   	    'true
      	 else
   	    'false
      >>;
      return atf
   end;	 

procedure pasf_dt(atf);
   % Presburger arithmetic standard form evaluation of definite terms. [atf]
   % is an atomic formula. Returns [atf] if no simplification is possible or a
   % truth value.
   begin scalar pdp,opn;
      if rl_tvalp atf then return atf;
      pdp := pasf_pdp pasf_arg2l atf;
      opn := pasf_opn atf;
      % Positive and negative definite terms
      if pdp eq 'pdef and opn memq '(equal lessp leq) then return 'false;
      if pdp eq 'ndef and opn memq '(equal greaterp geq) then return 'false;
      if pdp eq 'pdef and opn memq '(neq greaterp geq) then return 'true;
      if pdp eq 'ndef and opn memq '(neq lessp leq) then return 'true;
      % Positive and negative semidefinite terms
      if pdp eq 'psdef and opn eq 'lessp then return 'false;
      if pdp eq 'nsdef and opn eq 'greaterp then return 'false;
      if pdp eq 'psdef and opn eq 'geq then return 'true;
      if pdp eq 'nsdef and opn eq 'leq then return 'true;
      if pdp eq 'psdef and opn eq 'neq then return 
	 pasf_0mk2('greaterp,pasf_arg2l atf);
      if pdp eq 'nsdef and opn eq 'neq then return 
	 pasf_0mk2('lessp,pasf_arg2l atf);
      return atf
   end;

procedure pasf_mr(atf);
   % Presburger arithmetic standard form modulo reduction. [atf] is an atomic
   % formula. Returns a modulo free formula equivalent to [atf]. For
   % non-congruences nothing can be done.
   if not rl_tvalp atf and pasf_congp atf and domainp pasf_m atf then
      pasf_0mk2(pasf_op atf,remf(pasf_arg2l atf,pasf_m atf))
   else
      % For non-congruences nothing can be done
      atf;

procedure pasf_ceeq(atf);
   % Presburger arithmetic standard form content elimination (CE) for
   % equalities. [atf] is an atomic formula. Returns an equivalent atomic
   % formula.
   begin scalar g;
      % Nothing to do for non-equalities
      if rl_tvalp atf or not(pasf_opn atf memq '(equal neq)) then
	 return atf;
      % Computing the domain valued content of the coefficients
      g := sfto_dcontentf pasf_arg2l atf;
      return pasf_0mk2(pasf_op atf,quotfx(pasf_arg2l atf, numr simp g))
   end;

procedure pasf_cein(atf);
   % Presburger arithmetic standard form content elimination (CE) for
   % non-equalities. [atf] is an atomic formula. Returns an equivalent atomic
   % formula.
   begin scalar g,decp;
      if rl_tvalp atf or not(pasf_opn atf memq '(leq greaterp geq lessp)) then
	 return atf;
      % Computing the content of the parametric part
      decp := pasf_deci pasf_arg2l atf;
      g := sfto_dcontentf car decp;
      return pasf_0mk2(pasf_op atf,
	 addf(quotfx(car decp,numr simp g),
	    if pasf_opn atf memq '(leq greaterp) then
	       negf pasf_floor(-(cdr decp),g)
	    else if pasf_opn atf memq '(geq lessp) then
	       negf pasf_ceil(-(cdr decp),g)))
   end;

procedure pasf_cecong(atf);
   % Presburger arithmetic standard form content elimination (CE) for
   % congruences. [atf] is an atomic formula. Returns equivalent atomic
   % formula.
   begin scalar inv,m,g;
      % For non-congruences nothing to do
      if rl_tvalp atf or not pasf_congp atf then
	    return atf;
      m := pasf_m atf;
      g := gcdf(m,sfto_dcontentf pasf_arg2l atf);
      atf := pasf_0mk2(pasf_mkop(pasf_opn atf,quotfx(m,numr simp g)),	      
	 quotfx(pasf_arg2l atf,numr simp g));
      m := pasf_m atf;
      g := sfto_dcontentf pasf_arg2l atf;
      inv := domainp m and gcdf(m,g) = 1;
      % Check if the content has an inverse
      return if inv then
	 % Division is always possible
      	 pasf_0mk2(pasf_op atf,quotfx(pasf_arg2l atf,numr simp g))
      else
	 atf
   end;

procedure pasf_se(atf);
   % Presburger arithmetic standard form (un-)solvability check for
   % (in-)equalities. [atf] is an atomic formula. Returns a truth value or
   % [atf].
   begin scalar decp,g;
      % For non-equalities nothing to do
      if rl_tvalp atf or not(pasf_opn atf memq '(neq equal)) then
	 return atf;
      % Computing the content
      decp := pasf_deci pasf_arg2l atf;
      g := sfto_dcontentf car decp;
      if remainder(cdr decp,g) neq 0 and pasf_opn atf eq 'neq then
	 return 'true;
      if remainder(cdr decp,g) neq 0 and pasf_opn atf eq 'equal then
	 return 'false;
      return atf
   end;

procedure pasf_or(atf);
   % Presburger arithmetic standard form order relation reduction. [atf] is an
   % atomic formula. Returns equivalent atomic formula.
   begin scalar decp;
      % For non orderings nothing to do
      if rl_tvalp atf or not(pasf_opn atf memq '(lessp greaterp leq geq)) then
	 return atf;
      % Decomposing the atomic formula
      decp := pasf_deci pasf_arg2l atf;
      if pasf_opn atf eq 'lessp and cdr decp < 0 then
	 return pasf_0mk2('leq, addf(pasf_arg2l atf, numr simp 1));
      if pasf_opn atf eq 'leq and cdr decp > 0 then
	 return pasf_0mk2('lessp, addf(pasf_arg2l atf, negf numr simp 1));
      if pasf_opn atf eq 'greaterp and cdr decp > 0 then
	 return pasf_0mk2('geq, addf(pasf_arg2l atf, negf numr simp 1));
      if pasf_opn atf eq 'geq and cdr decp < 0 then
	 return pasf_0mk2('greaterp, addf(pasf_arg2l atf, numr simp 1));
      return atf
   end;

procedure pasf_sc(atf);
   % Presburger arithmetic standard form (un-)solvability check for
   % (in-)congruences. [atf] is an atomic formula. Returns a truth value or
   % [atf].
   begin scalar g,res,m,decp;
      % For noncongruences nothing to do
      if rl_tvalp atf or not(pasf_opn atf memq '(cong ncong)) or
      	 % For congruences with non-domainvalued modulus nothing is done yet
	 null domainp pasf_m atf then
	    return atf;
      % Decomposing the formula
      decp := pasf_deci pasf_arg2l atf;
      % Computing the content 
      g := sfto_dcontentf car decp;
      m := pasf_m atf;
      % Verbose check for simplification
      res := t;
      for j := 0 : m do
	 res := res and (remainder(cdr decp + j*g,m) neq 0);
      if res and pasf_opn atf eq 'cong then
	 return 'false;
      if res and pasf_opn atf eq 'ncong then
	 return 'true;
      return atf
   end;

procedure pasf_evalatp(rel,lhs);
   % Presburger arithmetic standard form evaluate atomic formula. [rel] is a
   % relation; [lhs] is a domain element. Returns a truth value equivalent to
   % $[rel]([lhs],0)$.
   if pairp rel and car rel memq '(cong ncong) then
      % Only congruences with nonparametric modulus are allowed
      (if domainp cdr rel then pasf_evalatpm(car rel,lhs,cdr rel)
      else rederr{"pasf_evalatp : parametric modulus in input"})
   else
      pasf_evalatpm(rel,lhs,nil);

procedure pasf_evalatpm(rel,lhs,m);
   % Presburger arithmetic standard form evaluate atomic formula
   % subroutine. [rel] is a relation; [lhs] is a domain element; [m] is an
   % optional modulus. Returns a truth value equivalent to $[rel]([lhs],0)$.
   if rel eq 'equal then null lhs or lhs = 0
   else if rel eq 'neq then not (null lhs or lhs = 0)
   else if rel eq 'leq then minusf lhs or (null lhs or lhs = 0)
   else if rel eq 'geq then not minusf lhs
   else if rel eq 'lessp then minusf lhs
   else if rel eq 'greaterp then not (minusf lhs or null lhs or lhs = 0)
   else if rel eq 'cong then 
      (null lhs or lhs = 0) or 0 = remainder(lhs,m)
   else if rel eq 'ncong then 
      not ((null lhs or lhs = 0) or 0 = remainder(lhs,m))
   else rederr {"pasf_evalatp: unknown operator",rel};


procedure pasf_fact(atf);
   % Presburger arithmetic standard form factorization of atomic formulas.
   % [atf] is an atomic formula. Returns atf if no factorization can be done
   % and an equivalent quantifier-free formula else.
   begin scalar fac,op,m;
      if rl_tvalp atf then
	 return atf;
      op := pasf_op atf;
      fac := fctrf pasf_arg2l atf;
      if length fac < 3 then
	 return atf;
      if op memq '(equal neq) then
	 return rl_mkn(if op eq 'equal then 'or else 'and,
	    for each fct in cdr fac collect
	       pasf_0mk2(op,car fct));
      if op memq '(leq lessp geq greaterp) then
	 return pasf_fact1(cdr fac,	    
	    if minusf car fac then pasf_anegrel op else op);
      return atf;
   end;

procedure pasf_fact1(fac,op);
   % Presburger arithmetic standard form factorization of atomic formulas
   % subprocedure. [fac] is a factorization of an atomic formula; [op] is the
   % operator. Returns an equivalent formula to $\prod_i fac(i) op 0$.
   if null cdr fac then
      pasf_0mk2(op,caar fac)
   else if remainder(cdar fac,2) neq 0 then 
      rl_mkn('or,{
	 rl_mkn('and,{pasf_0mk2(op,caar fac),
	    if op memq '(geq greaterp) then 
	       pasf_fact1(cdr fac,op) 
	    else
	       pasf_fact1(cdr fac,pasf_anegrel op)}),
	 rl_mkn('and,{pasf_0mk2(pasf_anegrel op,caar fac),
	    if op memq '(geq greaterp) then 
	       pasf_fact1(cdr fac,pasf_anegrel op) 
	    else
	       pasf_fact1(cdr fac,op)})})
   else
      pasf_fact1(cdr fac,op);

endmodule; % [pasfsiat]

end; % of file
