% ----------------------------------------------------------------------
% $Id: pasfqe.red,v 1.114 2008/01/27 15:05:53 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2001 A. Dolzmann, A. Seidl, and T. Sturm
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

% $Log: pasfqe.red,v $
% Revision 1.114  2008/01/27 15:05:53  lasaruk
% Quoted 't replaced by t
%
% Revision 1.113  2007/12/16 12:40:26  sturm
% Fixed issue in pasf_qe_rcsid!*.
% Bugfix: lc had been used as local variable in pasf_vsubstcatf.
%
% Revision 1.112  2007/09/19 14:03:33  lasaruk
% Bug in pasf_inplaceqe resolved
%
% Revision 1.111  2007/09/19 08:02:38  lasaruk
% Small bug in PQE corrected
%
% Revision 1.110  2007/07/29 00:59:31  lasaruk
% Congruence case in PQE implemented. Small bug in pasf_siat.red corrected.
%
% Revision 1.109  2007/07/22 19:39:16  lasaruk
% Probabilistic QE changed to work with probability parameter.
%
% Revision 1.108  2007/07/10 09:13:36  lasaruk
% Bug in substitution procedure in pasfmisc corrected.
%
% Revision 1.107  2007/07/05 06:20:45  lasaruk
% Probabilistic quantifier elimination skeleton added.
%
% Revision 1.106  2007/06/19 19:07:44  lasaruk
% Bug in interval computation corrected
%
% Revision 1.105  2007/04/01 12:42:57  lasaruk
% ifacl ifacml implemented
%
% Revision 1.104  2007/03/22 17:45:35  lasaruk
% rlint bug reports corrected
%
% Revision 1.103  2006/11/06 19:07:52  lasaruk
% eq's replaced by eqn's in integer comparisons
%
% Revision 1.102  2006/06/29 05:45:15  lasaruk
% debug output removed
%
% Revision 1.101  2006/06/29 05:41:08  lasaruk
% Conflation corrected
%
% Revision 1.100  2006/06/28 17:55:17  lasaruk
% Special case of virtual substitution added
%
% Revision 1.99  2006/06/23 11:01:19  lasaruk
% Gauss elimination turned off for univariate case. Properly created ranges.
%
% Revision 1.98  2006/06/23 09:28:42  lasaruk
% Small modifications
%
% Revision 1.97  2006/06/23 08:24:45  lasaruk
% initial checkin of univariate separated qe
%
% Revision 1.96  2006/06/02 07:37:56  lasaruk
% bugs found by cref eliminated
%
% Revision 1.95  2006/06/02 06:29:16  lasaruk
% calls to pasf_inplaceqe1 are now with two arguments, as desired
%
% Revision 1.94  2006/05/15 21:42:22  sturm
% Adapted call of pasf_expanda.
%
% Revision 1.93  2006/04/09 07:48:06  lasaruk
% Substitution can be performed only with presburger terms.
% Expansion procedure for answers added.
%
% Revision 1.92  2006/03/17 15:16:04  lasaruk
% Answer formula is always simplified on output.
%
% Revision 1.91  2006/03/15 19:02:14  lasaruk
% Weak and strict quantifier elimination and quantifier elimination with
% answers separated into rlqe (rlwqe) and rlwqe (rlwqea).
% The first expands always.
%
% Revision 1.90  2006/03/07 07:42:26  lasaruk
% weak quantifier elimination with answers according to the papaer added
%
% Revision 1.89  2005/11/18 10:19:29  lasaruk
% Local tests for incorrect forumals added: quantified modulus and quantified
% bound parameters.
%
% Revision 1.88  2005/08/04 11:03:58  lasaruk
% Uniform comments
%
% Revision 1.87  2005/07/31 13:23:16  lasaruk
% Congruence empty case modified. Some changes in gauss elimination. Comments
%
% Revision 1.86  2005/07/17 20:31:28  lasaruk
% Comments rewritten
%
% Revision 1.85  2005/04/29 12:17:16  lasaruk
% Debugging code removed
%
% Revision 1.84  2005/04/27 19:39:23  lasaruk
% Version the tests for diplomarbeit ran on
%
% Revision 1.83  2005/04/22 20:29:25  lasaruk
% Elimination set conflating added
%
% Revision 1.82  2005/04/18 21:13:24  lasaruk
% Structural elimination sets with discussed strategy
%
% Revision 1.81  2005/04/14 15:28:18  lasaruk
% Finetuning and some bugfixes that come with tests
%
% Revision 1.80  2005/04/13 18:07:51  lasaruk
% QE-Code rewritten with datastructures. Each non-internal representation 
% greater than a pair is now encapsulated in a datastructure
%
% Revision 1.79  2005/04/06 14:59:20  lasaruk
% New switch rlpasfbapprox for bound approximation added.
%
% Revision 1.78  2005/04/05 22:49:45  lasaruk
% new quantifier elimination method introduced
%
% Revision 1.77  2005/03/25 14:50:50  lasaruk
% Light tests for bounded quantifier simplification added
%
% Revision 1.76  2005/03/17 16:58:45  lasaruk
% Code structure changed
%
% Revision 1.75  2005/02/24 15:20:03  lasaruk
% QE code completely rewritten using a correct representant choice
%
% Revision 1.74  2005/01/28 02:28:48  lasaruk
% Representation search code rewritten. Now correct treatment of congruences.
% Partial elimination sets code rewritten, but produces still too many sets.
%
% Revision 1.73  2005/01/24 23:32:50  lasaruk
% Minor changes while debugging
%
% Revision 1.72  2005/01/24 20:52:44  lasaruk
% Correct semantics for substituting negative denominators and
% correct congruence handling.
%
% Revision 1.71  2005/01/24 16:02:08  lasaruk
% Uniform Presburger Arithmetic is now implemented. Elimination code rewritten,
% so no elimination normal form is explicitly computed.
%
% Revision 1.70  2005/01/22 19:50:57  lasaruk
% Uniform presburger arithmetic introduced
%
% Revision 1.69  2005/01/20 23:19:59  lasaruk
% Partial elimination sets improoved. Linear optimization rewritten with
% single QE call, minimal value search and bound value reconstruction.
% Care for bounded quantifiers in gauss elimination and condensing added.
%
% Revision 1.68  2005/01/17 22:17:00  lasaruk
% Linear optimization added. For now withot parameters.
%
% Revision 1.67  2005/01/16 22:47:24  lasaruk
% Partial elimination sets
%
% Revision 1.66  2005/01/15 20:28:27  lasaruk
% Quantifier elimination with answers experimental version
%
% Revision 1.65  2005/01/15 01:04:26  lasaruk
% Positional condensing
%
% Revision 1.64  2005/01/13 03:05:10  lasaruk
% Assymetric bounds
%
% Revision 1.63  2004/12/29 14:31:38  lasaruk
% Quantifier elimination with condensing and generic code. QE with answers does
% not work yet properly, due to inssuficient care of bounded quantifiers.
% Positional condesning is also missing.
%
% Revision 1.62  2004/12/18 21:31:10  lasaruk
% Gauss-Elimination added
%
% Revision 1.61  2004/08/29 20:42:13  lasaruk
% Simplification of atomic formulas rewritten without the term
% normal form. Administration details switches and other
% stuff put into some order and are commented now. Floor and
% ceil procedures corrected to fit the semantics. pasf_susidec
% moved to pasf_dec. pasf_deci for integer decomposition added.
% In QE the simplification is done at the last stage even if
% rlpasfsimplify is turned off. All suitable rl_mkn's are turned
% to rl_smkn. In pasfsiat.red order reduction has been added.
% In pasfsism.red substitution and simplification goals have
% been revisited. Configuration tested on more than 3*10^5
% formulas with different structure.
%
% Revision 1.60  2004/08/11 15:17:08  lasaruk
% New comments done. Now automatic procedure documentation
% possible. Some code rewritten.
%
% Revision 1.59  2004/08/06 15:35:17  lasaruk
% Congruence simplification added. Some errors corrected.
%
% Revision 1.58  2004/06/01 15:25:15  lasaruk
% simple gauss simplification added, transitive simplification
% with switches temporary removed, additive simplification
% filled with some minor cases
%
% Revision 1.57  2004/02/22 21:08:15  lasaruk
% Added switch rlsusisubst for substitution of equalities. Substitution
% results in smaller formulas or formulas with less free variables.
% Up to 80% length reduction. Switch rlsusitr should not be used yet.
%
% Revision 1.56  2003/12/16 07:45:34  lasaruk
% Redlog normal form in the simplifier.
%
% Revision 1.55  2003/12/11 10:51:19  lasaruk
% Smart simplification improoved.
%
% Revision 1.54  2003/12/02 15:27:13  sturm
% Introduced ioto_nterpri to avoid ugly linebreaks in verbosity output.
%
% Revision 1.53  2003/12/02 15:00:57  sturm
% Removed a call to cl_simpl in pasf_qeex (superfluous checking for truth
% values).
% Do a more general check on variable not occurring.
%
% Revision 1.52  2003/12/02 14:37:07  sturm
% Rewritten pasf_qeexblock and added canonical verbose output.
%
% Revision 1.51  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.50  2003/10/28 10:02:03  dolzmann
% Added correct content of fluids pasf_siat_rcsid!* and
% pasf_siat_copyright!*.
%
% Revision 1.49  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.48  2003/10/12 15:18:11  sturm
% pasf_qe requires second (theo, dummy for now) argument. This became visible
% under CSL.
%
% Revision 1.47  2003/08/28 15:30:40  lasaruk
% Simplification verbose output done better. QE-Bug with truth values
% corrected (will be done more effitient). Some fancy examples added.
%
% Revision 1.46  2003/07/16 12:58:50  lasaruk
% Error in QE removed.
%
% Revision 1.45  2003/07/16 12:51:35  lasaruk
% Tipp error.
%
% Revision 1.44  2003/07/16 12:48:33  lasaruk
% See message below.
%
% Revision 1.43  2003/07/15 12:40:41  seidl
% Renamed pasf_iv2qff to pasf_ivl2qff and pasf_qff2iv to pasf_qff2ivl.
% Provided algebraic mode access to simplb, ivl2qff, qdd2ivl. Changed
% pasf_mkrng so intervals with same upper and lower bound result in an
% equation. Fixed serious bug in pasf_prepat. Added cvs header to
% pasf.tst. Todo Lasaruk: pasf_ivl2qff crashes with empty interval as
% argument, see testfile.
%
% Revision 1.42  2003/06/04 12:33:40  lasaruk
% Some smaller modifications.
%
% Revision 1.41  2003/05/28 20:37:51  lasaruk
% Expansion done better.
%
% Revision 1.40  2003/05/26 20:50:57  lasaruk
% Range expansion with congruences
%
% Revision 1.39  2003/05/22 22:00:58  lasaruk
% DNF added.
%
% Revision 1.38  2003/05/17 17:04:16  lasaruk
% bugs removed
%
% Revision 1.37  2003/05/17 16:27:56  lasaruk
% Pasf simplification added. Some errors corrected.
%
% Revision 1.36  2003/05/15 23:34:47  lasaruk
% Interval expansion added
%
% Revision 1.35  2003/04/20 12:04:04  lasaruk
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
%
% Revision 1.34  2003/04/14 10:11:39  lasaruk
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
%
% Revision 1.33  2003/03/26 11:19:23  lasaruk
% Formula runthrough rewritten as cl_atnum. True/false in rlexpabnd bug
% removed. Some services added.
%
% Revision 1.32  2003/03/04 09:33:23  lasaruk
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
%
% Revision 1.31  2003/02/24 19:50:19  lasaruk
% Congruences without x removed.
%
% Revision 1.30  2003/02/18 12:45:03  lasaruk
% Better code for some methods.
%
% Revision 1.29  2003/02/17 14:44:55  lasaruk
% Debug messages removed.
%
% Revision 1.28  2003/02/17 10:55:40  lasaruk
% Stable full featured version
%
% Revision 1.27  2003/02/03 13:41:04  lasaruk
% Experimental version with full functionality. A bit buggy.
%
% Revision 1.26  2003/02/02 17:33:44  lasaruk
% Internal representation of data is converted completely into SF's
% except the representation of moduli.
%
% Revision 1.25  2003/02/01 08:42:50  lasaruk
% Stack container implemented.
%
% Revision 1.24  2003/02/01 07:38:33  lasaruk
% Recursive range expansion.
%
% Revision 1.23  2003/01/31 14:25:06  lasaruk
% Bug fixed.
%
% Revision 1.22  2003/01/31 14:18:48  lasaruk
% Found better method for impoding.
%
% Revision 1.21  2003/01/31 14:09:58  lasaruk
% New variable method added. K is no loger fixed, but a new variable.
%
% Revision 1.20  2003/01/29 16:07:46  lasaruk
% Better limits.
%
% Revision 1.19  2003/01/29 15:24:47  sturm
% Added service rlexpand for context pasf. Had to split pasf_exprng for this.
%
% Revision 1.18  2003/01/27 17:40:02  lasaruk
% Switches renamed. Bugs in docu fixed.
%
% Revision 1.17  2003/01/26 18:31:49  lasaruk
% Simplification position altered.
%
% Revision 1.16  2003/01/26 17:49:37  lasaruk
% Null congruence error added. Terms without quant. varl. stay
% untouched. Bugs fixed.
%
% Revision 1.15  2003/01/21 17:39:14  lasaruk
% Switch rlsiatadv turned off. Bugs fixed.
%
% Revision 1.14  2003/01/21 10:44:14  lasaruk
% Congruence substitution added. Bugs fixed.
%
% Revision 1.13  2003/01/20 10:36:51  lasaruk
% First trial to work with congruences. Bugs fixed.
%
% Revision 1.12  2003/01/06 18:20:32  lasaruk
% Bugs fixed
%
% Revision 1.11  2003/01/06 17:33:27  lasaruk
% Some simplifier bugs fixed. Alternating quantifier elimination attached.
%
% Revision 1.10  2003/01/05 15:55:05  lasaruk
% Simplification improoved. Expansion of range predicates added.
%
% Revision 1.9  2002/12/31 13:57:49  lasaruk
% Simplifier bugs fixed.
%
% Revision 1.8  2002/12/31 13:33:34  lasaruk
% Standard simplifier attached. Standard simplification of expressions
% attached.
%
% Revision 1.7  2002/12/23 07:41:19  lasaruk
% Simplifier turned off temporary
%
% Revision 1.6  2002/12/23 07:07:05  lasaruk
% Elimination code completely rewritten
%
% Revision 1.5  2002/12/10 08:49:41  lasaruk
% Correct elimination of an exist. quantifier call added.
% Procedures debugged.
%
% Revision 1.3  2002/12/02 12:53:37  lasaruk
% Elimination of one variable in front of an ex quantifier. Not really
% worth looking at.
%
% Revision 1.2  2002/11/15 12:00:48  seidl
% Head added.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_qe_rcsid!* pasf_qe_copyright!*);
   pasf_qe_rcsid!* :=
      "$Id: pasfqe.red,v 1.114 2008/01/27 15:05:53 lasaruk Exp $";
   pasf_qe_copyright!* :=
      "Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm"
>>;


module pasfqe;
% Presburger arithmetic standard form quantifier elimination. Submodule of
% PASF.

% ---- Quantifier elimination control ----------------------------------------

procedure pasf_qe(phi,theo);
   % Presburger arithmetic standard form quantifier elimination. [phi] is a
   % formula; [theo] is an explicit theory. Returns a strictly quantifier-free
   % formula equivalent to [phi].
   if null pasf_uprap phi then
      pasf_expand pasf_gqe(phi,theo,nil,simp 1)
   else
      rederr{"Only weak quantifier elimination possible"};

procedure pasf_wqe(phi,theo);
   % Presburger arithmetic standard form weak quantifier elimination. [phi] is
   % a formula; [theo] is an explicit theory. Returns a weakly quantifier-free
   % formula equivalent to [phi].
   pasf_gqe(phi,theo,nil,simp 1);

procedure pasf_qea(phi,theo);
   % Presburger arithmetic standard form quantifier elimination with
   % answers. [phi] is a formula; [theo] is an explicit theory. Returns an
   % answer to the quantifier elimination.
   if null pasf_uprap phi then
      pasf_expanda(pasf_wqea(phi,theo),phi)
   else
      rederr{"Only weak quantifier elimination possible"};

procedure pasf_wqea(phi,theo);
   % Presburger arithmetic standard form weak quantifier elimination with
   % answers. [phi] is a formula; [theo] is an explicit theory. Returns an
   % answer to the quantifier elimination.
   begin scalar res,ret;
      res := pasf_gqe(phi,theo,t,simp 1);
      for each r in res do
	 ret := {answ_f r,for each b in answ_bl r collect b,
      	    for each eqn in answ_tl r collect
	       pasf_mk2('equal,prepf pasf_arg2l eqn,prepsq pasf_arg2r eqn)} . ret;
      return ret
   end;

procedure pasf_pqe(phi,p,theo);
   % Presburger arithmetic standard form probabilistic weak quantifier
   % elimination. [phi] is a formula; [theo] is an explicit theory; [p] is a
   % probability for PQE. Returns a $p$-equivalent quantifier-free formula.
   if null pasf_uprap phi then
      pasf_gqe(phi,theo,nil,p)
   else
      rederr{"Probabilistic quantifier elimination impossible"};

procedure pasf_pqea(phi,p,theo);
   % Presburger arithmetic standard form probabilistic weak quantifier
   % eliminationwith answers. [phi] is a formula; [theo] is an explicit
   % theory; [p] is a probability for PQE. Returns a $p$-equivalent
   % quantifier-free formula.
   if null pasf_uprap phi then
      pasf_expanda(pasf_pqea1(phi,theo,p),phi)
   else
      rederr{"Probabilistic quantifier elimination impossible"};

procedure pasf_pqea1(phi,theo,p);
   % Presburger arithmetic standard form probabilistic quantifier elimination
   % with answers subprocedure. [phi] is a formula; [theo] is an explicit
   % theory; [p] is a probability for PQE. Returns an answer to the
   % probabilistic quantifier elimination.
   begin scalar res,ret;
      res := pasf_gqe(phi,theo,t,p);
      for each r in res do
	 ret := {answ_f r,for each b in answ_bl r collect b,
      	    for each eqn in answ_tl r collect
	       pasf_mk2('equal,prepf pasf_arg2l eqn,prepsq pasf_arg2r eqn)} . ret;
      return ret
   end;

procedure pasf_gqe(phi,theo,answ,p);
   % Presburger arithmetic standard form generic compute a quantifier-free
   % formula equivalent. [phi] is a formula; [theo] is the explicit theory;
   % [answ] should be set to nil iff no answers are required; [p] is the
   % probability for PQE. Returns a quantifier-free formula $\psi$ equivalent
   % to $\phi$ if [answ] is nil and a pair $(\psi . a)$ where $a$ is an answer
   % for the last quantifier block otherwise.
   begin scalar rslt,pt,retn,tmp,bl,tl;
      if !*rlverbose then ioto_tprin2 "++++ Entering pasf_qe";
      % Tests for correct UPrA form.
      % pasf_uprap(phi);
      % The formula is always simplified via input theory
      phi := cl_simpl(phi,theo,-1);
      % Performing DNF on the matrix if wanted
      rslt := if !*rlpasfdnffirst then
	 % Note: a pseudo DNF computation is performed. In the second case the
	 % pseudo-DNF is also in PNF, so a PNF is computed in any case.
    	 pasf_dnf phi
      else
      	 pasf_pnf phi;
      % Determining the problem type for answers
      if rl_op rslt eq 'ex or phi then pt := 'existential 
      else if rl_op rslt eq 'all or phi then pt := 'universal
      % For now user has to specify the formula with a non-bounded quantifier
      % in front to get answers
      else if answ then rederr{"QE with answers impossible"};
      rslt := pasf_inplaceqe(rslt,theo,answ,p);
      % Tuning rslt to fit QE with answers result type
      if answ and rl_tvalp rslt then
	 rslt := {answ_new(rslt,nil,nil)};
      % The last step is always simplified via input theory
      if answ then << 
	 for each an in rslt do <<
	    tmp :=  cl_simpl(answ_f an,theo,-1);
	    bl := answ_bl an;
	    tl := answ_tl an;
	    % Results with false guard for existential and with true guard for
	    % universal problems will be ignored
	    if pt eq 'existential and tmp neq 'false or
	       pt eq 'universal and tmp neq 'true then
	    	  retn := lto_insert(answ_new(tmp,bl,tl),retn)
	 >>;
	 if null retn then retn := {answ_new('false,nil,nil)};
 	 return retn
      >> else
	 return cl_simpl(rslt,theo,-1)
   end;

procedure pasf_inplaceqe(phi,theo,answ,p);
   % Presburger arithmetic standard form inplace quantifier elimination. [phi]
   % is a formula; [theo] is a theory; [answ] is the answer flag, [p] is the
   % probability for PQE. Returns a quantifier-free equivalent or an answer
   % according to answ flag.
   begin scalar res;
      res := pasf_inplaceqe1(phi,theo,p);
      if cdr res then
      % The outter-most block is eliminated explicitly
	 return pasf_qeblock(cadr res,cddr res,car res,theo,
	    if answ then answ_new('true,nil,nil) else nil,p);
      return car res
   end;

procedure pasf_inplaceqe1(phi,theo,p);
   % Presburger arithmetic standard form inplace quantifier elimination
   % subprocedure. [phi] is a formula; [theo] is a theory; [p] is the
   % probability for PQE. Returns a quantifier-free equivalent.
   begin scalar tmp,f;
      % Note: We can ignore the answer because all the blocks qe called inside
      % this procedure with are not the outter-most
      if rl_bquap rl_op phi then <<
	 tmp := pasf_inplaceqe1(rl_mat phi,theo,p);
	 if cdr tmp then 
	    % A normal quantifier block has ended by outter bounded quantifier
	    f := pasf_qeblock(cadr tmp,cddr tmp,car tmp,theo,nil,p)
	 else
	    f := car tmp;
	 return (rl_mkbq(rl_op phi,rl_var phi,rl_b phi,f) . nil)
      >>;
      if rl_quap rl_op phi then <<
	 tmp := pasf_inplaceqe1(rl_mat phi,theo,p);
	 return if cdr tmp then 
 	    (if cadr tmp neq rl_op phi then
	       (pasf_qeblock(cadr tmp,cddr tmp,car tmp,theo,nil,p) . 
	       	  (rl_op phi . {rl_var phi}))
	    else
	       (car tmp . (cadr tmp . (rl_var phi . cddr tmp))))
	 else
	    (car tmp . (rl_op phi . {rl_var phi}))
      >>;
      % Now, assuming that the formula is in PNF, the formula is strong
      % quantifier-free
      return (phi . nil)
   end;

procedure pasf_qeblock(theta,varl,psi,theo,answ,p);
   % Presburger arithmetic standrd form eliminate a block of
   % quantifiers. [theta] if the quantifier type; [varl] is a list of bounded
   % variables by the quantifier; [psi] is the matrix of the formula; [theo]
   % is the current theory; [answ] should be set to nil if no answers are
   % required; [p] is the probability for PQE. Returns an equivalent
   % quantifier-free formula or a pair $(\psi . a)$ where $a$ is an answer.
   begin scalar res;integer dpth,vlv;
      if !*rlverbose then <<
	 ioto_tprin2 {"---- ",theta . reverse varl};
	 dpth := length varl;
      	 if !*rlqedfs then <<  % should not happen by now
	    vlv :=  dpth / 4;
	    ioto_prin2t {" [DFS: depth ",dpth,", watching ",dpth - vlv,"]"}
      	 >> else
	    ioto_prin2t {" [BFS: depth ",dpth,"]"}
      >>;
      if theta eq 'ex then
      	 res := pasf_qeexblock(varl,psi,dpth,vlv,theo,answ,p) 
      else <<
	 % Handling of the all operator
      	 res := pasf_qeexblock(varl,cl_nnfnot psi,dpth,vlv,theo,answ,p);
      	 res := if answ then
	    for each an in res collect
	       answ_new(cl_nnfnot answ_f an,answ_bl an,answ_tl an)
      	 else
	    cl_nnfnot res
      >>;
      return res
   end;

procedure pasf_qeexblock(varl,psi,dpth,vlv,theo,answ,p);
   % Presburger arithmetic standrd form eliminate a block of existential
   % quantifiers. [varl] are the bounded variables; [psi] is the matrix of the
   % formula; [dpth] ist the recursion depth; [vlv] is a list of variables;
   % [theo] is a theory; [answ] is nil if no answers are required; [p] is the
   % probability for PQE. Returns an equivalent quantifier-free formula or a
   % pair $(\psi . a)$ where $a$ is an answer.
   begin scalar co,cvl,w,coe,f,newj,v,ans; integer c,delc,oldcol,count;
      cvl := varl;
      if rl_op psi eq 'or then
	 for each x in rl_argn psi do
	    co := cl_save(co,{cl_mkcoel(cvl,x,answ,nil)})
      else
      	 co := cl_save(co,{cl_mkcoel(cvl,psi,answ,nil)});
      while co do <<
	 w := cl_get co;
	 co := cdr w;
	 coe := car w;
    	 cvl := cl_covl coe;
	 f := cl_cof coe;
	 count := count + 1;
	 if !*rlverbose then
	    if !*rlqedfs then <<
	       if vlv = length cvl then
	       	  ioto_tprin2t {"-- crossing: ",dpth - vlv};
	       ioto_prin2 {"[",dpth - length cvl}
	    >> else <<
	       if c=0 then <<
	       	  ioto_tprin2t {"-- left: ",length cvl};
		  c := cl_colength co + 1
	       >>;
	       ioto_nterpri(length explode c + 4);
	       ioto_prin2 {"[",c};
	       c := c - 1
	    >>;
	 % Variable selection
	 v := car cvl;
	 cvl := cdr cvl;
	 % Eliminating the selected variable
	 ans := pasf_qeex(f,v,theo,cl_coan coe,cvl,p);
	 if cvl then <<
	    if !*rlverbose then oldcol := cl_colength(co);
	    co := cl_save(co,ans);
	    if !*rlverbose then
	       delc := delc + oldcol + length ans - cl_colength(co)
	 >> else <<
	    if answ then
	       for each an in ans do 
		  newj := lto_insert(cl_coan an,newj)
	    else
	       for each an in ans do newj := lto_insert(cl_cof an,newj)
	 >>;
	 if !*rlverbose then <<
	    ioto_prin2 "] ";
	    if !*rlqedfs and null cvl then ioto_prin2 ". "
      	 >>
      >>;
      if !*rlverbose then ioto_prin2{"[DEL:",delc,"/",count,"]"};
      return if answ then newj else rl_smkn('or,newj)
   end;

procedure pasf_qeex(psi,x,theo,answ,cvlm,p);
   % Presburger arithmetic standard form eliminate an existential quantifier
   % in front of a quantifier free formula. [psi] is a formula; [x] is the
   % quantified variable; [theo] is the current theory; [answ] is an ANSW
   % structure; [cvlm] is the variable list; [p] is the probability for
   % PQE. Returns a pair $(a . p) . theo'$ where $a=t$ and $p$ is a list of
   % container elements and $theo'$ a theory.
   begin scalar eset,dec,f,res,pcc,tmp;
      % PNF must be applied because of guards added during the substitution
      psi := pasf_pnf psi;
      if not (x memq cl_fvarl1 psi) then <<
      	 % The formula does not contain the quantified variable
	 if !*rlverbose then ioto_prin2 "*";
	 return {cl_mkcoel(cvlm,psi,answ_new(psi,nil,
	    if answ then 
	       pasf_mk2('equal,numr simp x,simp 0) . answ_tl answ else nil),nil)}
      >>;
      if !*rlverbose then ioto_prin2 "e";
      % Computing a gauss decomposition of the input formula
      dec := if !*rlpasfgauss then 
	 pasf_gaussdec(psi,x,theo)
      else
	 (nil . psi);
      if !*rlverbose and car dec then ioto_prin2 "g";
      % f is the formula resulting from psi by replacing all gauss subformulas
      % by false
      f := cl_simpl(cdr dec,theo,-1);
      if not (x memq cl_fvarl1 f) then <<
 	 % The non-gauss part of the formula does not contain the quantified
 	 % variable or is even possibly trivial
	 if !*rlverbose then ioto_prin2 "#"
      >> else
      	 % Computing the elimination set of the input without gauss-formulas
      	 eset := pasf_elimset(f,x,theo,p);
      % Computing the quantifier-free equivalent. Each item of the following
      % list contains an answer to the corresponding substitution point.
      pcc := 0;
      res := append(
	 % Substitution of points from non gauss formulas
	 if null eset and f neq 'false then {answ_new(f,nil,
	    if answ then 
	       pasf_mk2('equal,numr simp x,simp 0) . answ_tl answ else nil)} else
	    for each elimpt in eset collect 
	       pasf_vs(if !*rlpasfsc then <<
		  tmp := pasf_condense(f,elimpt_pos elimpt);
		  pcc := pcc + cdr tmp;
		  car tmp
	       >> else f,x,elimpt),
	 % Substitution of points from gauss formulas
	 for each elimpt in car dec collect
	    pasf_vs(if !*rlpasfgc then <<
	       tmp := pasf_condense(psi,elimpt_pos elimpt);
	       pcc := pcc + cdr tmp;
	       car tmp
	    >> else psi,x,elimpt));
      if !*rlverbose and pcc > 0 then << 
	 ioto_prin2 "c";
	 ioto_prin2 pcc 
      >>;
      % Simplifying the results
      res := for each rs in res collect
	 answ_new(if !*rlpasfsimplify then 
	    cl_simpl(answ_f rs,theo,-1) else answ_f rs,answ_bl rs,answ_tl rs);
      % Answers represent directly the output disjunction
      return for each an in res collect 
	 cl_mkcoel(cvlm,answ_f an,answ_backsubst(an,answ),nil)
   end;

% ---- Virtual substitution --------------------------------------------------

procedure pasf_vs(f,x,elimpt);
   % Presburger arithmetic standard form virtual substitution. [f] is a
   % positive quantifier-free formula; [x] is a variable; [elimptl] is an
   % ELIMPT. Returns a list of ANSW structures.
   begin scalar res,tf,bvl,sf;
      % Creating the formula to substitute
      sf := cl_apply2ats1(f,'pasf_vsubstatf,
	 {x,elimpt_den elimpt,elimpt_nom elimpt,elimpt_unif elimpt});
      tf := rl_smkn('and, {sf,elimpt_guard elimpt});
      % Checking if the substitution is trivial eg. gauss substitution.
      if elimpt_bvl elimpt then <<
	 % There are bounded quantifiers to create
	 bvl := elimpt_bvl elimpt;
	 for each bv in bvl do
	    tf := rl_mkbq('bex,cdr bv,car bv,tf)
      >>;
      res := answ_new(tf,for each bv in bvl collect car bv,
     	 {pasf_mk2('equal,numr simp x,
	    (elimpt_nom elimpt . elimpt_den elimpt))});
      % mathprint rl_mk!*fof answ_f res;
      return res
   end;

procedure pasf_vsubstatf(atf,x,n_j,a_j,unif);
   % Presburger arithmetic standard form virtual stubstitution in atomic
   % formula. [atf] is an atomic formula; [x] is the eliminated variable;
   % [n_j] is a substitution parameter; [a_j] is a substitution parameter;
   % [unif] is a flag that is t iff the formula represents cauchy
   % bounds. Returns the substituted atomic formula.
   begin scalar n_i,a_i,dc,d,degr;
      % Decomposing the atomic formula
      dc := repr_atfnew(atf,x,nil);
      % Highest degree of the polynomial
      degr := repr_ldeg dc;
      % Constrained substitution if univariate formula
      if degr > 1 and not unif then 
	 return pasf_vsubstcatf(atf,x,n_j,a_j);
      if degr <= 1 then <<
      	 n_i := repr_n dc;
      	 a_i := repr_a dc;
      	 % Returning unchanged formula if no quantified variable in the formula
      	 if null n_i then return atf;
      	 d := pasf_pdp n_j;
      	 return if pasf_congp atf then
	    % Multiplying the modulus
      	    pasf_0mk2(pasf_mkop(pasf_opn atf,multf(pasf_m atf,n_j)),
	       addf(multf(n_i,a_j),negf multf(n_j,a_i)))
      	 else if pasf_op atf memq '(leq lessp geq greaterp) then
	    (if d memq '(pdef psdef) then
	       pasf_0mk2(repr_op dc,addf(multf(n_i,a_j), negf multf(n_j,a_i)))
      	    else if d memq '(ndef nsdef) then
	       pasf_0mk2(anegrel repr_op dc,addf(multf(n_i,a_j), 
	       	  negf multf(negf n_j,a_i)))
	    else if d eq 'indef then
	       % For inequalities with indefinite denominator the denominator
	       % must be made positive
      	       pasf_0mk2(repr_op dc,addf(multf(multf(n_i,n_j),a_j), 
	       	  negf multf(multf(n_j,n_j),a_i))))
      	 else 
	    pasf_0mk2(repr_op dc,addf(multf(n_i,a_j), negf multf(n_j,a_i)))
      >> else <<
	 % Trivial substitution
	 return pasf_subat({(x . prepf a_j)},atf);
      >>;
   end;

procedure pasf_vsubstcatf(atf,x,n_j,a_j);
   % Presburger arithmetic standard form constrained virtual stubstitution in
   % a univariate nonlinear atomic formula. [atf] is an atomic formula; [x] is
   % the eliminated variable; [n_j] is the test point nominator; [a_j] is the
   % test point denominator. Returns a formula.
   begin scalar cl,cb,cbadd,lcoeff;
      %if pasf_congp atf then
      %rederr{"For now no congruences with univariate polynomials allowed"};
      cl := pasf_coeflst(pasf_arg2l atf,x);
      cb := pasf_cauchybndcl(cl);
      cbadd := multf(multf(n_j,n_j),cb);
      lcoeff := car cl;
      if domainp car lcoeff and remainder(cdr lcoeff,2) = 0 then
	 return rl_smkn('or,
	    {rl_smkn('and,{pasf_0mk2('leq,addf(a_j,cbadd)),
	       pasf_0mk2(pasf_op atf,car lcoeff)}),
	       rl_smkn('and,{pasf_0mk2('geq,addf(a_j,negf cbadd)),
		  pasf_0mk2(pasf_op atf,car lcoeff)})});
      if !*rlqesubi then 
	 return rl_smkn('or,
	    {rl_smkn('and,{pasf_0mk2('leq,addf(a_j,cbadd)),
	    pasf_qesubiat(atf,x,'minf)}),
	       rl_smkn('and,{pasf_0mk2('geq,addf(a_j,negf cbadd)),
	    pasf_qesubiat(atf,x,'pinf)})})
      else
	 return rl_smkn('or,
	    {rl_smkn('and,{pasf_0mk2('leq,addf(a_j,cbadd)),
	    pasf_subat({(x . prepf negf cb)},atf)}),
	       rl_smkn('and,{pasf_0mk2('geq,addf(a_j,negf cbadd)),
	    pasf_subat({(x . prepf cb)},atf)})})
   end;

procedure pasf_qesubi(f,v,inf);
   % Presburger arithmetic standard form quantifier elimination substitute
   % infinite element. [bvl] is a list of variables, [theo] is the
   % current theory; [f] is a quantifier-free formula; [v] is a
   % variable; [inf] is one of ['minf], ['pinf] which stand for
   % $-\infty$ and $\infty$ resp. Returns a pair $(\Theta' . \phi)$
   % where $\Theta'$ is a theory and $\phi$ is a quantifier-free
   % formula. $\phi$ is equivalent to $[f]([v]/[inf])$ under the
   % theory $[th] \cup \Theta'$. $\Theta' is currently always [nil].
   cl_apply2ats1(f,'pasf_qesubiat,{v,inf});

procedure pasf_qesubiat(atf,v,inf);
   % Presburger arithmetic standard form quantifier elimination substitute
   % infinite element into atomic formula. [atf] is an atomic formula;
   % [v] is a variable; [inf] is one of ['minf], ['pinf] which stand for
   % $-\infty$ and $\infty$ resp. Returns a quantifier-free formula
   % equivalent to $[atf]([v]/[inf])$.
   begin scalar op,lhs;
      if not (v memq pasf_varlat atf) then return atf;
      op := pasf_op atf;
      lhs := pasf_arg2l atf;
      if op eq 'equal or op eq 'neq then
	 return pasf_qesubtranseq(op,lhs,v);
      % [op] is an ordering relation.
      return pasf_qesubiord(op,lhs,v,inf)
   end;

procedure pasf_qesubtranseq(op,lhs,v);
   % Presburger arithmetic standard form quantifier elimination substitute
   % transcendental element with equality relation. [op] is one of
   % ['equal], ['neq]; [lhs] is an SF; [v] is a variable. Returns a
   % quantifier-free formula equivalent to $[r]([lhs],0)([v]/\alpha)$
   % for any transcendental $\alpha$.
   if op eq 'equal then
      pasf_qesubtransequal(lhs,v)
   else  % [op eq 'neq]
      cl_nnfnot pasf_qesubtransequal(lhs,v);

procedure pasf_qesubtransequal(lhs,v);
   % Presburger arithmetic standard form quantifier elimination substitute
   % transcendental element into equation. [lhs] is an SF; [v] is a
   % variable. Returns a quantifier-free formula equivalent to
   % $[lhs]([v]/\alpha)=0$ for any transcendental $\alpha$.
   pasf_qesubtransequal1(sfto_reorder(lhs,v),v);

procedure pasf_qesubtransequal1(lhs,v);
   % Presburger arithmetic standard form quantifier elimination substitute
   % transcendental element into equation. [lhs] is an SF reordered
   % wrt. [v]; [v] is a variable. Returns a quantifier-free formula
   % equivalent to $[lhs]([v]/\alpha)=0$ for any transcendental
   % $\alpha$.
   begin scalar cl;
      while not domainp lhs and mvar lhs eq v do <<
	 cl := pasf_0mk2('equal,reorder lc lhs) . cl;
	 lhs := red lhs
      >>;
      cl := pasf_0mk2('equal,reorder lhs) . cl;
      return rl_smkn('and,cl)
   end;

procedure pasf_qesubiord(op,f,v,inf);
   % Presburger arithmetic standard form quantifier elimination substitute
   % infinite element with ordering relation. [op] is an ordering
   % relation. [f] is an SF; [v] is a variable; [inf] is one of
   % ['minf], ['pinf] which stand for $-\infty$ and $\infty$ resp.
   % Returns a quantifier-free formula equivalent to
   % $[op]([lhs]([v]/[inf]),0)$.
   pasf_qesubiord1(op,sfto_reorder(f,v),v,inf);

procedure pasf_qesubiord1(op,f,v,inf);
   % Presburger arithmetic standard form quantifier elimination substitute
   % infinite element with ordering relation subroutine. [op] is an
   % ordering relation. [f] is an SF, which is reordered wrt. [v]; [v]
   % is a variable; [inf] is one of ['minf], ['pinf] which stand for
   % $-\infty$ and $\infty$ resp. Returns a quantifier-free formula
   % equivalent to $[op]([lhs]([v]/[inf]),0)$.
   begin scalar an;
      if domainp f or mvar f neq v then
      	 return pasf_0mk2(op,reorder f);
      an := if inf eq 'minf and not evenp ldeg f then
 	 negf reorder lc f
      else
 	 reorder lc f;
      % The use of [an] is correct in the equal case.   % Generic QE!
      return rl_mkn('or,{pasf_0mk2(pasf_mkstrict op,an),rl_mkn(
	 'and,{pasf_0mk2('equal,an),pasf_qesubiord1(op,red f,v,inf)})})
   end;

% ---- Condensing operator --------------------------------------------------

procedure pasf_condense(f,pl);
   % Presburger arithmetic standard form condensing operator. [f] is a
   % positive quantifier-free formula; [pl] is a list of tree positions of
   % formulas to condense. Returns a pair $(f' . c)$ where $f'$ results from
   % [f] by replacing each subformula, that is not conjunctively associated to
   % [pl], with false and $c$ is the total amount of condensed subtrees.
   begin scalar r,c,tmp,cm;
      % We have found the formula producing the resulting test point
      if null pl then return (f . 0);
      % In disjunctions we remove all points that are not conjunctively
      % associated to the formula producing the test point
      if rl_op f eq 'or then <<
	 c := 0;
	 for each sf in rl_argn f do <<
	    if c = car pl then 
	       r := pasf_condense(sf,cdr pl);
	    c := c + 1
	 >>;
	 if c = 0 then 
	    rederr{"Bug in pasf_condense, reference leads to nothing"};
	 return (car r . (cdr r + c - 1))
      >>;
      % In conjunctions we proceed with condensing on the way to the formula,
      % that produced the testpoint, without replacing anything on the current
      % level
      if rl_op f eq 'and then <<
	 c := 0;
	 cm := 0;
	 for each sf in rl_argn f do <<
	    if c = car pl then <<
	       tmp := pasf_condense(sf,cdr pl);
	       r := (car tmp) . r;
	       cm := cdr tmp 
	    >> else
	       r := sf . r;
	    c := c + 1
	 >>;
	 return (rl_smkn('and,r) . cm)
      >>;
      % Note: Universal bounded quantifiers stay as they are even if one tries
      % to condense something inside such a quantifier. It could make sence to
      % raise an error, if one tries to do so, but this implementation avoids
      % condensing of universal bounded quantifiers with other tools
      if rl_op f eq 'bex then <<
	 tmp := pasf_condense(rl_mat f,cdr pl);
	 return (rl_mkbq(rl_op f,rl_var f,rl_b f,car tmp) . cdr tmp)
      >>;
      return (f . 0)
   end;

% ---- Elimination set computation -------------------------------------------

procedure pasf_elimset(f,x,theo,p);
   % Presburger arithmetic standard form elimination set computation. [f] is a
   % forumla; [x] is a variable; [theo] is a theory; [p] is the probability
   % for PQE. Returns an ELIMPT list.
   begin scalar reprl,reprls,m,tempm,pdp,rl,res,vl,tz,toc;
      % Probabilistic mode is on
      if !*rlverbose and p neq simp 1 then ioto_prin2 "p";
      reprls := pasf_rep(f,x);
      % Creating all new variables. This prevents running out of variables
      vl := for i := 1 : length fdec_bvl car reprls + 1 collect 
	 pasf_newvar(nil);
      if !*rlverbose and length cdr reprls > 1 then << 
	 ioto_prin2 "s";
	 ioto_prin2 length cdr reprls
      >>;
      for each reprl in cdr reprls do <<
      	 % Computing the approximation for the moduli period
      	 m := 1;
	 rl := nil;
	 toc := t;
      	 for each repr in reprl do
	    % Only representants containing the quantified variable concerned
      	    if repr_n repr then <<
               if pairp repr_op repr and 
 	       	  car repr_op repr memq '(cong ncong) then <<
		     % Getting the modulus
		     tempm := cdr repr_op repr;
		     pdp := pasf_pdp tempm;
		     % For definite moduli no approximation needed
		     m := if pdp eq 'pdef then lcm(m,tempm)
		     else if pdp eq 'ndef then lcm(m,negf tempm)
			% For semidefinite moduli just adding 1
		     else if pdp eq 'psdef then lcm(m,addf(tempm,1))
		     else if pdp eq 'nsdef then lcm(m,addf(negf tempm,1))
			% Approximating the modulus by it's square plus 1
		     else lcm(m,addf(multf(tempm,tempm),1));
		     % Adding the congruence to the representant list if it
		     % can turn to zero
		     if not (pdp memq '(pdef ndef)) then <<
			toc := t;
			rl := repr . rl
		     >>
	     	  >> else
		     rl := repr . rl
      	    >>;
	 res := append(pasf_testpt(fdec_bvl car reprls,rl,m,vl,toc,p),res)
      >>;
      tz := length res;
      res := if !*rlpasfconf then pasf_conflate res else res;
      if !*rlverbose and !*rlpasfconf and tz-length res > 0 then << 
	 ioto_prin2 "t";
	 ioto_prin2 (tz-length res)
      >>;
      if null res then rederr{"error in elimination set creation"};
      % Adding the zero-case only in case of uniform input and non-univariate
      % formula
      return if pasf_uprap f and not pasf_univnlfp(f,x) then 
	 elimpt_new(nil,'true,nil,1,nil,nil) . res 
      else res
   end;

procedure pasf_testpt(b,l,m,vl,toc,p);
   % Presburger arithmetic standard form elimination test points. [b] is a
   % list of bound/bound variable pairs; [l] is the list of representants that
   % will be used for test point generation; [m] is a congruence period
   % approximation, which can be not positive definite only in case of generic
   % elimination; [vl] is a list of new varibles; [toc] is a flag that signals
   % if the congruence case has to be added; [p] is the probability for
   % PQE. Returns an ELIMSET.
   begin scalar v,res,cp,nsv,rnd,rng,n;
      v := car vl;
      nsv := numr simp v;
      % The congruences case
      res := if null l or null toc then 
	 if p neq simp 1 then 
	    pasf_testptpqe(nil,0,1,0,m,p,nil)
         else
	    {elimpt_new(nil,'true,numr simp v,1,
	       {(rl_smkn('or,{pasf_mkrng(numr simp v,nil,m),
	    	  pasf_mkrng(nsv,nil,negf m)}) . v)},nil)};
      for each repr in l do <<
         % DEBUG Test for correct representants
	 if repr_ldeg repr = 0 then
	    rederr{"pasf_testpt: representant with leading degree 0"};
	 % Probabilistic test point
	 if p neq simp 1 and repr_ldeg repr = 1 then
	    res := pasf_testptpqe(repr_pos repr,repr_r repr,repr_n repr,
	       -m*repr_n repr,m*repr_n repr,p,t)
      	 else if repr_ldeg repr = 1 then
	    % Simple test point
	    res := elimpt_new(
	       % Position of the subformula
	       	  repr_pos repr,
       	    	  % Guards for each representant
	    	  rl_smkn('and,{pasf_0mk2('neq,repr_n repr),
	       	     pasf_0mk2(('cong . repr_n repr),
		  	addf(repr_r repr, nsv))}),
	    	  % Substitution point
	    	  addf(repr_r repr,nsv),repr_n repr,
	    	  % Bounds
	    	  pasf_substb(b,repr_t repr,v,m,repr_n repr,cdr vl),nil) . res
      	 else <<
	    % Univariate test point. Note: assuming m to be positive
	    cp := addf(pasf_cauchybndcl repr_cl repr,m);
	    res := elimpt_new(
	       % Position of the subformula
	       repr_pos repr,
	       % Guards for the substitution
	       'true,
	       % Substitution point
	       nsv,1,
	       % Bounds are the Cauchy-bounds
	       {(pasf_mkrng(nsv,negf cp,cp) . v)},t) . res;
	 >>
      >>;
      return res
   end;

procedure pasf_testptpqe(pos,nom,den,a,b,p,g);
   % Presburger arithmetic standard form elimination test points for
   % pqe. [pos] is the position of the formula; [nom] is the numerator term;
   % [den] is the denominator; [a] is the lower interval boundary; [b] is the
   % upper interval boundary; [p] is the probability for PQE; [g] is nil iff
   % there are no guards to create. Returns an ELIMSET which contains random
   % points from the range $[t+a,t+b]$ such that each term is hit with
   % probability [p].
   begin scalar n,rnd,res;
      n := max2(ceiling(ln(1.0-numr p*1.0/denr p)/ln(1.0-1.0/(b-a+1))-1),1);
      for i := 1 : n do <<
	 rnd := numr simp (random(b-a+1)+a);
	 print rnd;
	 res := elimpt_new(pos,
	    if g then 
	       rl_smkn('and,{pasf_0mk2('neq,den),
	    	  pasf_0mk2(('cong . den),addf(nom,rnd))})
	    else
	       'true,addf(nom,rnd),den,nil,nil) . res
      >>;
      return res
   end;

procedure pasf_substb(b,term,v,m,n_j,vl);
   % Presburger arithmetic standard form bound substitution. [b] is a list of
   % bound/bound variable pairs; [term] is the term of linear combinations of
   % bounded variables in b; [m] is an approximation of all moduli; [n_j] is
   % the coefficient of the representant; [vl] is a list of new
   % variables. Returns a list of bounds where $v$ runs in some range about
   % all values of [term] in [b].
   begin scalar nb,nv,nt1,nt2,res,sb,nbb,tmp,pdp;
      % Collecting all variables for substitution
      for each bnd in b do <<
	 sb := (cdr bnd . car vl) . sb;
	 vl := cdr vl
      >>;
      % Duplicating the term
      term := numr subf(term,sb);
      % Duplicating the bounds
      for each bnd in b do <<
	 nbb := car bnd;
	 nv := nil;
	 for each s in sb do <<
	    if car s eq cdr bnd then nv := cdr s;
	    % Note: Bounds are strong quantifier-free
	    nbb := pasf_subfof(car s,cdr s,nbb)
	 >>;
	 if null nv then rederr {"bug in bound substitution"};
	 nb := (nbb . nv) . nb
      >>;
      if !*rlpasfbapprox then <<
	 % Bound approximation
	 tmp := pasf_bapprox(nb,term,v,m,n_j);
	 if tmp then return tmp
      >>;
      % Note: nt1 assumes m and n_j to be both positive
      nt1 := multf(n_j,m);
      % Note: nt2 assumes analog n_j to be negative
      nt2 := multf(negf n_j,m);
      % Bound substitution
      pdp := pasf_pdp n_j;
      res := rl_smkn('or,
      	 if pdp eq 'pdef then
	    {pasf_mkrng(addf(numr simp v,negf term),negf nt1,nt1)}
	 else if pdp eq 'ndef then
	    {pasf_mkrng(addf(numr simp v,negf term),negf nt2,nt2)}
	 else
	    {pasf_mkrng(addf(numr simp v,negf term),negf nt1,nt1),
      	       pasf_mkrng(addf(numr simp v,negf term),negf nt2,nt2)});
      return ((res . v) . reverse nb)
   end; 

procedure pasf_bapprox(b,term,v,l,n_j);
   % Presburger arithmetic standard form bound approximation. [b] is a list of
   % bound/bound variable pairs; [term] is the term of linear combinations of
   % bounded variables in [b]; [l] is the lcm of all nonzero coefficients;
   % [n_j] is the coefficient of the representant. Returns a new bound in [v]
   % where [v] runs in some range about all values of [term] in [b].
   begin scalar tmin,tmax,tmp,flag,tpool,tnpool,res,fvl;
      % For now only the real non uniform case
      if null domainp l then return nil;
      if null domainp n_j then return nil;
      if pasf_termp(term,nil) then return nil;
      tpool := {term};
      % Collecting all ranges of the bounds
      for each bnd in b do <<
	 fvl := cl_fvarl car bnd;
	 if length fvl > 1 then flag := t;
	 if length fvl = 1 and car fvl neq cdr bnd then 
	    rederror{"bug in bound approximation"};
	 if null flag then <<
	    tmp := pasf_brng(car bnd,cdr bnd);
	    tnpool := nil;
	    for each tm in tpool do <<
	       tnpool := numr subf(tm,{(cdr bnd . car tmp)}) . tnpool;
	       tnpool := numr subf(tm,{(cdr bnd . cdr tmp)}) . tnpool
	    >>
	 >>;
	 tpool := tnpool
      >>;
      % If parametric bounds appear substitution fails
      if flag then return nil;
      % Looking for minimum and maximum in the term list
      tmax := 'minf;
      tmin := 'pinf;
      for each tm in tpool do <<
	 if pasf_leqp(tm,tmin) then tmin := tm;
	 if pasf_leqp(tmax,tm) then tmax := tm
      >>;
      if n_j < 0 then n_j := -n_j;
      if l < 0 then l := -l;
      res := pasf_mkrng(numr simp v, 
	 addf(tmin,negf multf(n_j,l)),
	 addf(tmax,multf(n_j,l)));
      return {(res . v)}
   end;

procedure pasf_conflate(elsl);
   % Presburger arithmetic standard form conflation of elimination
   % sets. [elsl] is a list of test points. Returns a conflated elimination
   % set.
   begin scalar tmp,res;
      while elsl do <<
	 tmp := pasf_conflate1(cdr elsl,car elsl);
	 res := car tmp . res;
	 elsl := cdr tmp
      >>;
      return res
   end;

procedure pasf_conflate1(elsl,els1);
   % Presburger arithmetic standard form conflation of elimination sets
   % subprocedure. [elsl] is a list of test points; [els1] is a point to
   % conflate with. Returns a conflated elimination set.
   begin scalar r,rev1,rev2;
      for each els2 in elsl do <<
	 if (elimpt_nom els1 = elimpt_nom els2) and
	 (elimpt_den els1 = elimpt_den els2) and
	 (elimpt_guard els1 = elimpt_guard els2) and 
	 (elimpt_unif els1 = elimpt_unif els2) then <<
	    rev1 := elimpt_bvl els1;
	    rev2 := elimpt_bvl els2;
	    els1 := elimpt_new(elimpt_cpos(els1,els2),
	       elimpt_guard els1,elimpt_nom els1,elimpt_den els1,
	       % Note: This part uses the special form of the elimination 
	       % set of the QE-method (refer to the diploma thesis of lasaruk)
	       if rev1 and rev2 then
		  ((rl_mkn('or,{caar rev1,caar rev2}) . 
		     cdar rev1) . cdr rev1)
	       else if rev1 then rev1 
	       else rev2,elimpt_unif els1)
	 >> else r := els2 . r
      >>;
      return (els1 . r)
   end;

% ---- Representant computation ---------------------------------------------

procedure pasf_rep(f,x);
   % Presburger arithmetic standard form search for representants. [f] is a
   % weak quantifier-free formula in PNF; [x] is the eliminated
   % variable. Returns a pair of a FDEC structure and a list of REPR
   % structures.
   begin scalar fdec,ball;
      % Computing the matrix and the list of bounded variables
      fdec := fdec_new(f,x);
      for each b in fdec_bopl fdec do if b eq 'ball then ball := t;
      % Doing structural elimination only in existential problems. This
      % specially avoids condensing of formulas with universal bounded
      % quantifiers
      return if !*rlpasfses and null ball then
	 (fdec . pasf_ses(fdec_mat fdec,x,fdec_pos fdec,fdec_bvl fdec))
      else
      	 (fdec . {pasf_rep1(fdec_mat fdec,x,fdec_pos fdec,fdec_bvl fdec)})
   end;

procedure pasf_rep1(f,x,pos,bvl);
   % Presburger arithmetic standard form search for representants
   % subprocedure. [f] a strong quantifier-free formula; [x] is the
   % eliminatied variable; [pos] is the current position inside the formula;
   % [bvar] is the list of bounded variables. Returns the elimindation data.
   begin scalar n,res;
      % Note: pos is reserved for future implementation of positional
      % condensing
      n := 0;
      if rl_bquap rl_op f or rl_bquap rl_op f then
      	 % Input formula should be strong quantifier-free
      	 rederr{"pasf_canrep : quantifier illegal inside a formula's matrix"};
      if rl_boolp rl_op f then <<
      	 for each arg in rl_argn f do <<
	    % For now condensing only in structural elimination sets
	    res := append(pasf_rep1(arg,x,nil,bvl),res);
	    n := n+1
	 >>;
	 return res
      >>;
      % Atomic formula reached
      if pasf_congp f and x memq kernels pasf_m f then
	 rederr{"Quantified variable ",x," is not allowed in modulus"};
      return {repr_atfbnew(f,x,nil,bvl)}
   end;

procedure pasf_ses(f,x,pos,bvl);
   % Presburger arithmetic standard form search for representants with
   % structural elimination sets. [f] a strong quantifier-free formula; [x] is
   % the eliminatied variable; [pos] is the current position inside the
   % formula; [bvar] is the list of bounded variables. Returns the
   % elimindation data.
   begin scalar n,res,tmp,lmax,smax;
      n := 0;
      if rl_quap rl_op f or rl_bquap rl_op f then
      	 % Input formula should be strong quantifier-free
      	 rederr{"bug in pasf_canrep"};
      if rl_op f eq 'and then <<
	 lmax := 0;
      	 for each arg in rl_argn f do <<
	    tmp := pasf_ses(arg,x,append(pos,{n}),bvl);
	    if length tmp > lmax then <<
	       for each sm in smax do res := append(sm,res);
	       lmax := length tmp;
	       smax := tmp
	    >> else
	       for each sm in tmp do res := append(sm,res);
	    n := n+1
	 >>;
	 return for each esl in smax collect
	    append(esl,for each r in res collect 
	       repr_setpos(r,repr_pos car esl))
      >>;
      if rl_op f eq 'or then <<
     	 for each arg in rl_argn f do <<
	    res := append(pasf_ses(arg,x,append(pos,{n}),bvl),res);
	    n := n+1
	 >>;
	 return res
      >>;
      % Atomic formula reached
      if pasf_congp f and x memq kernels pasf_m f then
	 rederr{"Quantified variable",x,"is not allowed in modulus"};
      return {{repr_atfbnew(f,x,pos,bvl)}}
   end;

% ---- Gauss decomposition ---------------------------------------------------

procedure pasf_gaussdec(f,x,theo);
   % Presburger arithmetic standard form gauss decomposition. [f] is a
   % positive weakly quantifier-free formula; [x] is a variable; [theo] is a
   % theory. Returns a pair $(l . \psi)$ where $l$ is a list of $(p . es)$
   % where $p$ is the position of a gauss formula in $f$ and $es$ is it's
   % elimination set and $\psi$ is the formula resulting from $f$ by replacing
   % every gauss formula by false.
   begin scalar r,fdec,f,opl,stp,vl;
      % Note : Using the fact the formula is in PNF
      fdec := fdec_new(f,x);
      % Gauss elimination does not work for now with univariate formulas
      if pasf_univnlfp(fdec_mat fdec,x) then return (nil . f);
      opl := fdec_bopl fdec;
      % Cancelling gauss elimination for universal bounded quantifiers
      for each op in opl do 
	 if op eq 'ball then stp := t;
      if stp then return (nil . f);
      % Creating new variables
      vl := for i := 1 : length fdec_bvl fdec + 1 collect pasf_newvar(nil);
      r := pasf_gaussdec1(fdec_mat fdec,x,theo,fdec_pos fdec,fdec_bvl fdec,vl);
      f := caddr r;
      for each bv in fdec_bvl fdec do <<
	 f := rl_mkbq(car opl,cdr bv,car bv,f);
	 opl := cdr opl
      >>;
      return (cadr r . f)
   end;

procedure pasf_gaussdec1(f,x,theo,pos,bvar,vl);
   % Presburger arithmetic standard form gauss decomposition subprocedure.
   % [f] is a formula; [x] is a variable; [theo] is a theory; [pos] is a
   % position; [bvar] is a list of bounded variable and bound pairs; [vl] is
   % the new variable list. Returns list $\{flg , l , \psi\}$ where $flg$ is
   % t iff the formula is a gauss formula, $l$ is a list of $(p . es)$ where
   % $p$ is the position of a gauss formula in [f] and $es$ is it's
   % elimination set and $\psi$ is the formula resulting from [f] by replacing
   % every gauss formula by 'false.
   begin scalar c,tmp,r;
      if f eq 'false then 
	 return{t,nil,f};
      if f eq 'true then
	 return{nil,nil,f};
      if rl_op f eq 'and then <<
 	 % It is sufficient to find one gauss argument
	 c := 0;
	 % Internal datastructure {a,b,c}. First element is t iff a
	 % gauss-formula was found. The second is a list of ELIMPT of nested
	 % gauss formulas till now. The third is the formula without gauss
	 % formulas inside
	 tmp := {nil,nil,nil};
	 for each sf in rl_argn f do <<
	    % Among gauss subformulas we choose the elimination set with a
	    % corresponding heuristic
	    r := pasf_gaussdec1(sf,x,theo,append(pos,{c}),bvar,vl);
	    if car r then 
	       % Found a new gauss subformula
	       tmp := {t,pasf_gaussesord(cadr tmp,cadr r),'false}
	    else if null car tmp then
 	       % There for now no gauss subformulas found and the current one
 	       % is a non-gauss-formula
	       tmp := {nil,append(cadr tmp,cadr r),caddr r . caddr tmp};
	    % Note: Non-gauss subformulas are ignored if one is already found
	    c := c + 1
	 >>;
	 if car tmp then 
	    % This formula is a gauss formula
	    return tmp
	 else
	    return {nil,cadr tmp,rl_smkn('and,caddr tmp)}
      >>;
      if rl_op f eq 'or then <<
	 % All arguments have to be gauss formulas
	 c := 0;
	 tmp := {t,nil,nil};
	 for each sf in rl_argn f do <<
	    r := pasf_gaussdec1(sf,x,theo,append(pos,{c}),bvar,vl);
	    if car r then 
	       % Found a new gauss subformula
	       tmp := {car tmp,append(cadr tmp,cadr r),caddr r . caddr tmp}
	    else
	       tmp := {nil,append(cadr tmp,cadr r),caddr r . caddr tmp}; 
	    c := c + 1
 	 >>;
	 if car tmp then
	    % The formula is a gauss formula
	    return {t,cadr tmp,'false}
	 else
	    return {nil,cadr tmp,rl_smkn('or,caddr tmp)}
      >>;
      % There are no bounded quantifiers inside the pnf matrix
      if rl_bquap rl_op f then rederr{"Bug in gauss decomposition"};
      % Gauss atomic formulas are only equations
      if pasf_atfp f then 
 	 if pasf_opn f eq 'equal then 
	    return pasf_gaussdec2(f,x,bvar,pos,vl)
	 else
 	    return {nil,nil,f};
      % This code should not be reached at runtime, because that would mean
      % there is a negation, extended boolean operator or a quantifier in the
      % formula.
      rederr{"Bug in gauss decomposition. Code assumed dead reached"}
   end;

procedure pasf_gaussdec2(atf,x,bvar,pos,vl);
   % Presburger arithmetic standard form gauss decomposition subprocedure for
   % the treatment of gauss-equations. [bvar] is a list of bounded variables;
   % [x] is the eliminated variable; [atf] is an atomic gauss equation; [pos]
   % is the position of this gauss formula; [vl] is the new variable
   % list. Returns the gauss decomposition of the atomic formula.
   begin scalar repr,a_i,b;
      repr := repr_atfbnew(atf,x,pos,bvar);
      a_i := repr_r repr;
      % Bound for gauss formula
      b := pasf_substb(bvar,repr_t repr,car vl,nil,nil,cdr vl);
      if bvar then a_i := addf(a_i,numr simp car vl);
      if repr_n repr and domainp repr_n repr then
	 return {t,{elimpt_new(
	    % Position of the gauss formula
	    pos,
	    % Guard for gauss formulas
	    rl_mkn('and,{pasf_0mk2(('cong . repr_n repr),a_i),
	       pasf_0mk2('neq,repr_n repr)}),
	       % Test point for gauss formulas
	       a_i, repr_n repr,
	    if bvar then b else nil,nil)},'false};
      % Nothing can be done
      return {nil,nil,atf}
   end;

procedure pasf_gaussesord(a,b);
   % Presburger arithmetic standard form gauss elimination set ordering. [a]
   % and [b] are lists of ELIMPT. Returns one of [a] or [b] according to the
   % length of the elimination sets term form.
   begin
      if null a and b then return b 
      else if null a and null b then return nil 
      else if a and null b then return a 
      else if length cdar b < length cdar a then return b 
      else if length cdar b > length cdar a then return a;
      % Now the only case is the equality of lengths
      return b
   end;

endmodule; % pasfqe.red

end; % of file
