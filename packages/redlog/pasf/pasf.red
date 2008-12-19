% ----------------------------------------------------------------------
% $Id: pasf.red,v 1.103 2008/03/13 08:15:27 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002-2008 A. Dolzmann, A. Seidl, and T. Sturm
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

% $Log: pasf.red,v $
% Revision 1.103  2008/03/13 08:15:27  sturm
% Fixed a bug in pasf_univnlp, which can be called with (leq nil nil).
%
% Revision 1.102  2008/01/27 15:05:53  lasaruk
% Quoted 't replaced by t
%
% Revision 1.101  2007/12/16 12:22:11  sturm
% Added fluid declaration for !*rlsusi.
%
% Revision 1.100  2007/07/10 09:13:36  lasaruk
% Bug in substitution procedure in pasfmisc corrected.
%
% Revision 1.99  2007/07/05 06:20:45  lasaruk
% Probabilistic quantifier elimination skeleton added.
%
% Revision 1.98  2007/04/01 12:42:57  lasaruk
% ifacl ifacml implemented
%
% Revision 1.97  2007/03/22 17:45:35  lasaruk
% rlint bug reports corrected
%
% Revision 1.96  2006/08/21 05:15:40  sturm
% Added fluid for switch rlqeasri.
%
% Revision 1.95  2006/08/02 08:12:38  sturm
% Added module clresolv.
%
% Revision 1.94  2006/06/23 08:24:45  lasaruk
% initial checkin of univariate separated qe
%
% Revision 1.93  2006/06/01 12:24:30  sturm
% Added even switch declaration for rlqepnf. This is dirty and should be
% temporary.
%
% Revision 1.92  2006/06/01 12:13:54  sturm
% Added missing fluids.
%
% Revision 1.91  2006/05/15 21:39:47  sturm
% Rewritten pasf_simpat(). Accept denominators.
%
% Revision 1.90  2006/04/09 07:48:05  lasaruk
% Substitution can be performed only with presburger terms.
% Expansion procedure for answers added.
%
% Revision 1.89  2006/03/15 19:02:14  lasaruk
% Weak and strict quantifier elimination and quantifier elimination with
% answers separated into rlqe (rlwqe) and rlwqe (rlwqea).
% The first expands always.
%
% Revision 1.88  2006/03/10 21:56:21  lasaruk
% rlqewa renamed to rlwqea
%
% Revision 1.87  2006/03/07 07:42:26  lasaruk
% weak quantifier elimination with answers according to the papaer added
%
% Revision 1.86  2005/11/18 10:19:29  lasaruk
% Local tests for incorrect forumals added: quantified modulus and quantified
% bound parameters.
%
% Revision 1.85  2005/09/21 18:32:18  lasaruk
% binding of variable values from outside a formula is now possible
%
% Revision 1.84  2005/08/04 11:03:57  lasaruk
% Uniform comments
%
% Revision 1.83  2005/07/31 13:23:16  lasaruk
% Congruence empty case modified. Some changes in gauss elimination. Comments
%
% Revision 1.82  2005/07/17 16:26:45  lasaruk
% Some comments rewritten. Unused switches removed.
%
% Revision 1.81  2005/04/29 12:17:16  lasaruk
% Debugging code removed
%
% Revision 1.80  2005/04/27 19:39:23  lasaruk
% Version the tests for diplomarbeit ran on
%
% Revision 1.79  2005/04/22 20:29:25  lasaruk
% Elimination set conflating added
%
% Revision 1.78  2005/04/18 21:13:23  lasaruk
% Structural elimination sets with discussed strategy
%
% Revision 1.77  2005/04/06 14:59:20  lasaruk
% New switch rlpasfbapprox for bound approximation added.
%
% Revision 1.76  2005/04/05 22:49:44  lasaruk
% new quantifier elimination method introduced
%
% Revision 1.75  2005/03/17 16:58:45  lasaruk
% Code structure changed
%
% Revision 1.74  2005/02/24 15:20:02  lasaruk
% QE code completely rewritten using a correct representant choice
%
% Revision 1.73  2005/01/24 16:02:07  lasaruk
% Uniform Presburger Arithmetic is now implemented. Elimination code rewritten,
% so no elimination normal form is explicitly computed.
%
% Revision 1.72  2005/01/22 20:23:40  lasaruk
% Uniform Presburger Arithmetic introduced
%
% Revision 1.71  2005/01/21 17:56:16  lasaruk
% printing atomic formulas with constant part always on the left handside
%
% Revision 1.70  2005/01/20 23:19:59  lasaruk
% Partial elimination sets improoved. Linear optimization rewritten with
% single QE call, minimal value search and bound value reconstruction.
% Care for bounded quantifiers in gauss elimination and condensing added.
%
% Revision 1.69  2005/01/17 22:17:00  lasaruk
% Linear optimization added. For now withot parameters.
%
% Revision 1.68  2005/01/15 20:28:27  lasaruk
% Quantifier elimination with answers experimental version
%
% Revision 1.67  2005/01/13 03:05:10  lasaruk
% Assymetric bounds
%
% Revision 1.66  2004/12/29 14:31:38  lasaruk
% Quantifier elimination with condensing and generic code. QE with answers does
% not work yet properly, due to inssuficient care of bounded quantifiers.
% Positional condesning is also missing.
%
% Revision 1.65  2004/12/18 21:31:09  lasaruk
% Gauss-Elimination added
%
% Revision 1.64  2004/08/29 20:42:13  lasaruk
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
%
% Revision 1.63  2004/08/11 15:17:07  lasaruk
% New comments done. Now automatic procedure documentation possible. 
% Some code rewritten.
%
% Revision 1.62  2004/08/06 15:35:16  lasaruk
% Congruence simplification added. Some errors corrected.
%
% Revision 1.61  2004/06/09 06:38:09  lasaruk
% Smart simplification improoved. Transitive simplification added
% (without modifications on clsimpl not functional)
%
% Revision 1.60  2004/06/01 15:25:14  lasaruk
% simple gauss simplification added, transitive simplification
% with switches temporary removed, additive simplification
% filled with some minor cases
%
% Revision 1.59  2004/05/26 11:06:59  seidl
% Added service rl_subfof. Added chain simplification: E.g. a<b<=c>=d>e is
% allowed as input now (but no equations and congruences).
%
% Revision 1.58  2004/05/25 12:24:11  dolzmann
% Added service rlqnum.
%
% Revision 1.57  2004/02/22 21:08:15  lasaruk
% Added switch rlsusisubst for substitution of equalities. Substitution
% results in smaller formulas or formulas with less free variables.
% Up to 80% length reduction. Switch rlsusitr should not be used yet.
%
% Revision 1.56  2003/12/30 10:25:56  lasaruk
% Fixed bug in pasf_resimpat that caused crashes after value substitutions
%
% Revision 1.55  2003/12/11 15:24:02  sturm
% Switch on rlsusi for this context.
%
% Revision 1.54  2003/12/11 10:51:19  lasaruk
% Smart simplification improoved.
%
% Revision 1.53  2003/12/02 14:36:31  sturm
% Witch rlpasfvb off by default!
%
% Revision 1.52  2003/11/28 12:59:38  sturm
% Print congruences as ~n~ instead of =n= to avoid confusion.
%
% Revision 1.51  2003/11/07 12:08:12  sturm
% Improved printing.
%
% Revision 1.50  2003/11/05 13:56:19  lasaruk
% Some more changes. pasf_content renamed to pasf_gcd with more
% exact specificaton. lisp, symbolic and some "comments" are removed.
%
% Revision 1.49  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.48  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.47  2003/10/12 19:41:11  sturm
% Introduced rl_texmacs. The test "if get('or,'fancy!-infix!-symbol) = 218"
% does not work in general since Windows does not guarantee to load
% fmprint at startup.
%
% Revision 1.46  2003/10/12 18:26:14  sturm
% Printing for both fmprint and tmprint in pasf now.
% The test is done via "if get('or,'fancy!-infix!-symbol) = 218" for now.
% IBALP printing remains to be adapted.
%
% Revision 1.45  2003/10/12 16:53:26  sturm
% Texmacs fancy-printing crashed Windows. Substituted fancy procedures
% by less fancy but working ones for now.
%
% Revision 1.44  2003/09/09 10:56:17  lasaruk
% check for correct form improoved
%
% Revision 1.43  2003/09/02 07:22:41  seidl
% Changed fancyprinting for TeXmacs from division to congruence.
%
% Revision 1.42  2003/08/28 15:30:40  lasaruk
% Simplification verbose output done better. QE-Bug with truth values
% corrected (will be done more effitient). Some fancy examples added.
%
% Revision 1.41  2003/08/27 16:10:04  lasaruk
% Added switch rlpasfatfsimpvb to print out simplification steps if
% simplification was really done. Check for correct PASF form added.
%
% Revision 1.40  2003/08/21 14:52:02  seidl
% Fancy printing for bounded quantifiers (for TeXmacs).
%
% Revision 1.39  2003/08/19 09:36:11  seidl
% Defined blackbox "bsatp" to be pasf_qff2ivl; there could be a more
% efficient implementation. Introduced temporarly switch rlsiverbose,
% which provides verbose output for rules (TV), (EQ), (SB), (SM), (STRB)
% during simplification of bounded quantifiers.
%
% Revision 1.38  2003/08/14 21:44:38  seidl
% Simplification of bounded quantifiers looks quite good now. A hack has
% to be cured by a blackbox bsatp (bound sat. predicate). rlsism can be
% savely turned on now in pasf, but there is a problem with susi and
% congruences.
%
% Revision 1.37  2003/07/22 08:45:03  seidl
% Improved simplifiations of equations and negated equations. Still there
% can be done more. Simplification of atomic formulas has to be thoroughly
% revised.
%
% Revision 1.36  2003/07/21 21:57:41  seidl
% Intermediate check-in. Part of advanced smart simplification works
% already.
%
% Revision 1.35  2003/07/17 16:12:20  lasaruk
% Congruence bug removed. Printing methods for congruences rewritten.
%
% Revision 1.34  2003/07/16 13:50:47  lasaruk
% Debug messages removed. Bug in printing congurences removed.
% Testfile adjusted to changes (working cases).
%
% Revision 1.33  2003/07/16 12:43:44  lasaruk
% conflicts resolved. pasf_simpl removed. implementation of
% pasf_simplb and pasf_b2terml added and tested.
% temporary method for pasf_b2terml in algebraic mode added.
% empty list bug in pasf_ivl2qff removed.
% expansion method uses now pasf_b2terml. some comments done
% better.
%
% Revision 1.32  2003/07/15 12:40:41  seidl
% Renamed pasf_iv2qff to pasf_ivl2qff and pasf_qff2iv to pasf_qff2ivl.
% Provided algebraic mode access to simplb, ivl2qff, qdd2ivl. Changed
% pasf_mkrng so intervals with same upper and lower bound result in an
% equation. Fixed serious bug in pasf_prepat. Added cvs header to
% pasf.tst. Todo Lasaruk: pasf_ivl2qff crashes with empty interval as
% argument, see testfile.
%
% Revision 1.31  2003/07/14 12:37:58  lasaruk
% Common utilities attached and tested (see the testfile).
%
% Revision 1.30  2003/06/04 12:33:40  lasaruk
% Some smaller modifications.
%
% Revision 1.29  2003/05/22 22:00:58  lasaruk
% DNF added.
%
% Revision 1.28  2003/05/17 16:27:56  lasaruk
% Pasf simplification added. Some errors corrected.
%
% Revision 1.27  2003/04/20 12:04:04  lasaruk
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
%
% Revision 1.26  2003/04/14 10:11:39  lasaruk
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
%
% Revision 1.25  2003/03/26 11:19:23  lasaruk
% Formula runthrough rewritten as cl_atnum. True/false in rlexpabnd bug
% removed. Some services added.
%
% Revision 1.24  2003/03/11 00:41:29  lasaruk
% Prenex normal form with correct range predicate handling added. Documentation
% extended. Todo section added.
%
% Revision 1.23  2003/03/04 09:33:23  lasaruk
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
%
% Revision 1.22  2003/02/17 10:55:40  lasaruk
% Stable full featured version
%
% Revision 1.21  2003/02/01 07:38:33  lasaruk
% Recursive range expansion.
%
% Revision 1.20  2003/01/31 14:09:17  lasaruk
% Test for range predicate check added.
%
% Revision 1.19  2003/01/30 11:48:26  sturm
% Fixed bugs in operator declaration for congruences and range.
% Changed output routine for range.
%
% Revision 1.18  2003/01/29 15:24:47  sturm
% Added service rlexpand for context pasf. Had to split pasf_exprng for this.
%
% Revision 1.17  2003/01/29 15:06:52  sturm
% Made rlsism a context switch. It has to be off in this context for now.
%
% Revision 1.16  2003/01/27 17:40:01  lasaruk
% Switches renamed. Bugs in docu fixed.
%
% Revision 1.15  2003/01/26 17:49:37  lasaruk
% Null congruence error added. Terms without quant. varl. stay
% untouched. Bugs fixed.
%
% Revision 1.14  2003/01/21 10:43:34  lasaruk
% logging changed to verbose
%
% Revision 1.13  2003/01/20 10:35:56  lasaruk
% Switches pasf_logging and pasf_rangeexpand added.
% WARNING: Actually block elimination does not work in not expansion mode.
%
% Revision 1.12  2002/12/23 07:06:33  lasaruk
% operator pasf_opn and pasf_op differed
%
% Revision 1.11  2002/12/10 08:49:41  lasaruk
% Correct elimination of an exist. quantifier call added.
% Procedures debugged.
%
% Revision 1.10  2002/12/02 12:53:37  lasaruk
% Elimination of one variable in front of an ex quantifier. Not really
% worth looking at.
%
% Revision 1.9  2002/10/18 13:39:11  lasaruk
% QE one variable preparation added. No bounded quantifiers first.
%
% Revision 1.8  2002/10/10 09:09:20  lasaruk
% Range predicate implemented. Todo: logical negation of range predicate
%
% Revision 1.7  2002/10/02 14:31:19  lasaruk
% Initial check in. Only dummy methods for advanced simplification first.
%
% Revision 1.6  2002/09/26 14:54:55  lasaruk
% Errors corrected. Negation form implemented.
%
% Revision 1.5  2002/09/26 10:47:31  lasaruk
% Prenex normal form functionality added. Tests follow.
%
% Revision 1.4  2002/09/19 08:49:42  lasaruk
% All operators are binary. Before printing modulus of cong and ncong is
% put directly after the operator. Ordering corrected.
%
% Revision 1.3  2002/09/16 10:49:55  lasaruk
% Testversion for cong and ncong with dotted pair operator and 2 parameters.
%
% Revision 1.2  2002/08/23 08:07:19  seidl
% Added service rl_atl with trival black box rl_ordatp.
% Created module pasfmisc for this.
%
% Revision 1.1  2002/08/22 14:01:54  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_rcsid!* pasf_copyright!*);
   pasf_rcsid!* := "$Id: pasf.red,v 1.103 2008/03/13 08:15:27 sturm Exp $";
   pasf_copyright!* :=
      "Copyright (c) 2002-2008 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;


module pasf;
% Presburger arithmetic standard form main module. Algorithms on first-order
% formulas over the language of rings together with congruences. Binary
% relations (operators) are [equal], [neq], [leq], [geq], [lessp],
% [greaterp]. Ternary relations are [cong] and [ncong].

create!-package('(pasf pasfbnf pasfmisc pasfnf pasfsiat 
   pasfqe pasfsism pasfopt),nil);

fluid '(!*rlnzden !*rlposden !*rladdcond !*rlqeasri !*rlsusi);

load!-package 'cl;
load!-package 'rltools;
imports rltools,cl;

fluid '(!*rlverbose secondvalue!*);
flag('(pasf),'rl_package);
flag('(pasf_chsimpat),'full);
flag('(pasf_simpat),'full);
flag('(equal neq leq geq lessp greaterp),'spaced);

% QE-Switches

% QE call to DNF on the input formula's matrix
switch rlpasfdnffirst;
off1 'rlpasfdnffirst;
% Expand bounded quantifiers inside QE, if possible; Not used in the current
% implementation
switch rlpasfexpand;
off1 'rlpasfexpand;
% Simplify intermediate results
switch rlpasfsimplify;
on1 'rlpasfsimplify;
% Approximate bounds by maximal and minimal values
switch rlpasfbapprox;
on1 'rlpasfbapprox;
% Gauss elimination
switch rlpasfgauss;
on1 'rlpasfgauss;
% Full gauss condensing
switch rlpasfgc;
on1 'rlpasfgc;
% Structural condensing
switch rlpasfsc;
on1 'rlpasfsc;
% Structural elimination sets
switch rlpasfses;
on1 'rlpasfses;
% Conflation of structural elimination sets
switch rlpasfconf;
on1 'rlpasfconf;
% If on constrained virtual substitution uses infinity symbols instead of
% cauchy bounds
switch 'rlqesubi;
on1 'rlqesubi;

% Force cl_qe to make the formula prenex
switch rlqepnf;  % hack for now - TS
on1 'rlqepnf;

% Verboseswitches

% General verbose switch
switch rlpasfvb;
off1 'rlpasfvb;

% Smart simplification verbose
switch rlsiverbose;
off1 'rlsiverbose;

% Switches automaticly handled on context change
put('pasf,'rl_cswitches,'(
   (rlsism . t)
   (rlsusi . t)));

% Parameters
put('pasf,'rl_params,'(
   (rl_subat!* . pasf_subat)
   (rl_subalchk!* . pasf_subalchk)
   (rl_eqnrhskernels!* . pasf_eqnrhskernels)
   (rl_simplat1!* . pasf_simplat1)
   (rl_fctrat!* . pasf_fctrat)
   (rl_ordatp!* . pasf_ordatp)
   (rl_op!* . pasf_op)
   (rl_simplb!* . pasf_simplb)
   (rl_varsubstat!* . pasf_varsubstat)
   (rl_negateat!* . pasf_negateat)
   (rl_bnfsimpl!* . cl_bnfsimpl)
   (rl_tordp!* . ordp)
   (rl_termmlat!* . pasf_termmlat)
   (rl_sacat!* . pasf_sacat)
   (rl_sacatlp!* . cl_sacatlp)
   (rl_varlat!* . pasf_varlat)
   (rl_smupdknowl!* . pasf_smwupdknowl)
   (rl_smrmknowl!* . pasf_smwrmknowl)
   (rl_smcpknowl!* . pasf_smwcpknowl)
   (rl_smmkatl!* . pasf_smwmkatl)
   (rl_smsimpl!-impl!* . cl_smsimpl!-impl)
   (rl_smsimpl!-equiv1!* . cl_smsimpl!-equiv1)
   (rl_susibin!* . pasf_susibin)
   (rl_susipost!* . pasf_susipost)
   (rl_susitf!* . pasf_susitf)
   (rl_b2terml!* . pasf_b2terml)
   (rl_b2atl!* . pasf_b2atl)
   (rl_bsatp!* . pasf_bsatp)
   (rl_rxffn!* . pasf_rxffn)));

% Services
put('pasf,'rl_services,'(
   (rl_subfof!* . cl_subfof)
   (rl_apnf!* . cl_apnf)
   (rl_atml!* . cl_atml)
   (rl_terml!* . cl_terml)
   (rl_termml!* . cl_termml)
   (rl_ifacl!* . cl_ifacl)
   (rl_ifacml!* . cl_ifacml)
   (rl_tnf!* . cl_tnf)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_all!* . cl_all)
   (rl_ex!* . cl_ex)
   (rl_simpl!* . cl_simpl)
   (rl_atnum!* . cl_atnum)
   (rl_qnum!* . cl_qnum)
   (rl_matrix!* . cl_matrix)
   (rl_qe!* . pasf_qe)
   (rl_wqe!* . pasf_wqe)
   (rl_expand!* . pasf_expand)
   (rl_atl!* . cl_atl)
   (rl_pnf!* . pasf_pnf)
   (rl_dnf!* . pasf_dnf)
   (rl_cnf!* . pasf_cnf)
   (rl_nnf!* . cl_nnf)
   (rl_opt!* . pasf_opt)
   (rl_qea!* . pasf_qea)
   (rl_pqea!* . pasf_pqea)
   (rl_wqea!* . pasf_wqea)
   (rl_pqe!* . pasf_pqe)
   (rl_expanda!* . pasf_expanda)
   (rl_zsimpl!* . pasf_zsimpl)
   (rl_resolve!* . cl_resolve)));

% Administration definitions
put('pasf,'simpfnname,'pasf_simpfn);
put('pasf,'rl_prepat,'pasf_prepat);
put('pasf,'rl_resimpat,'pasf_resimpat);
put('pasf,'rl_lengthat,'pasf_lengthat);
put('pasf,'rl_prepterm,'prepf);
put('pasf,'rl_simpterm,'pasf_simpterm);

algebraic infix equal;
put('equal,'pasf_simpfn,'pasf_chsimpat);
put('equal,'number!-of!-args,2);

algebraic infix neq;
put('neq,'pasf_simpfn,'pasf_chsimpat);
put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq);

algebraic infix leq;
put('leq,'pasf_simpfn,'pasf_chsimpat);
put('leq,'number!-of!-args,2);
put('leq,'rtypefn,'quotelog);

algebraic infix geq;
put('geq,'pasf_simpfn,'pasf_chsimpat);
put('geq,'number!-of!-args,2);
put('geq,'rtypefn,'quotelog);

algebraic infix lessp;
put('lessp,'pasf_simpfn,'pasf_chsimpat);
put('lessp,'number!-of!-args,2);
put('lessp,'rtypefn,'quotelog);

algebraic infix greaterp;
put('greaterp,'pasf_simpfn,'pasf_chsimpat);
put('greaterp,'number!-of!-args,2);
put('greaterp,'rtypefn,'quotelog);

algebraic operator cong;
put('cong,'prifn,'pasf_pricong);
put('cong,'pasf_simpfn,'pasf_simpat);
put('cong,'number!-of!-args,3);
put('cong,'rtypefn,'quotelog);
put('cong,'fancy!-prifn,'pasf_fancy!-pricong);

algebraic operator ncong;
put('ncong,'prifn,'pasf_princong);
put('ncong,'pasf_simpfn,'pasf_simpat);
put('ncong,'number!-of!-args,3);
put('ncong,'rtypefn,'quotelog);
put('ncong,'fancy!-prifn,'pasf_fancy!-pricong);

procedure pasf_pricong(l);
   % Presburger arithmetic standard form print a congruence. [l] is a lisp
   % prefix. Returns 'failed iff printing failed.
   if null !*nat then
      'failed
   else <<
      maprin cadr l;
      prin2!* " ~";
      maprin cadddr l;
      prin2!* "~ ";
      maprin caddr l
   >>;

procedure pasf_princong(l);
   % Presburger arithmetic standard form print an incongruence. [l] is a lisp
   % prefix. Returns 'failed iff printing failed.
   if null !*nat then
      'failed
   else <<
      maprin cadr l;
      prin2!* " #";
      maprin cadddr l;
      prin2!* "# ";
      maprin caddr l
   >>;

procedure pasf_fancy!-pricong(l);
   % Presburger arithmetic standard form texmacs print a congruence. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if rl_texmacsp() then
      pasf_fancy!-pricong!-texmacs l
   else
      pasf_fancy!-pricong!-fm l;

procedure pasf_fancy!-pricong!-texmacs(l);
   % Presburger arithmetic standard form texmacs print a congruence. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if null !*nat then
      'failed
   else <<
      maprin cadr l; % lhs
      if car l eq 'cong then
	 fancy!-prin2 "\equiv"
      else
	 fancy!-prin2 "\not\equiv";
      fancy!-prin2!-underscore();
      fancy!-prin2 "{";
      maprin cadddr l; % modulus
      fancy!-prin2 "}";
      maprin caddr l; % rhs
   >>;

procedure pasf_fancy!-pricong!-fm(l);
   % Presburger arithmetic standard form texmacs print a congruence. [l] is a
   % lisp prefix. Returns 'failed iff printing failed.
   if null !*nat then
      'failed
   else <<
      maprin cadr l;
      if car l eq 'cong then
      	 fancy!-special!-symbol(186,2)
      else <<
	 fancy!-prin2 "/";
	 fancy!-special!-symbol(186,2)
      >>;
      maprin caddr l;
      fancy!-prin2 " (";
      maprin cadddr l;
      fancy!-prin2 ")"
   >>;

procedure pasf_verbosep();
   % Presburger arithmetic standard form verbose switch. Returns t iff the
   % main switch rlverbose is on and the switch rlpasfvb is on.
   !*rlverbose and !*rlpasfvb;

procedure pasf_simpterm(l);
   % Presburger arithmetic standard form simp term. [l] is lisp
   % prefix. Returns [l] as a PASF term.
   numr simp l;

procedure pasf_prepat(atf);
   % Presburger arithmetic standard form prep atomic formula. [atf] is a PASF
   % atomic formula. Returns [atf] in Lisp prefix form.
   if pasf_congp atf then
       {pasf_opn atf,prepf pasf_arg2l atf,prepf pasf_arg2r atf,
	  prepf pasf_m atf}
   else
      pasf_opn atf . for each arg in rl_argn atf collect prepf arg;

procedure pasf_resimpat(atf);
   % Presburger arithmetic standard form resimp atomic formula. [atf] is a
   % PASF atomic formula. Returns the atomic formula [atf] with resimplified
   % terms.
   pasf_mk2(if pasf_congp atf then 
      (pasf_opn atf . numr resimp !*f2q pasf_m atf)
   else 
      pasf_op atf,
      numr resimp !*f2q pasf_arg2l atf, numr resimp !*f2q pasf_arg2r atf);

procedure pasf_lengthat(atf);
   % Presburger arithmetic standard form length of an atomic formula. [atf] is
   % an atomic formula. Returns a number, the length of [atf].
   length rl_argn atf;
   % Note: This procedure is added only for code compatibility and is not used
   % inside PASF yet.

procedure pasf_chsimpat(l);
   % Presburger arithmetic standard form chain simp. [l] is a lisp prefix.
   % Returns [l] as a conjunction of atomic formulas.
   rl_smkn('and,for each x in pasf_chsimpat1 l collect pasf_simpat x);

procedure pasf_chsimpat1(l);
   % Presburger arithmetic standard form chain simp subprocedure. [l] is a
   % lisp prefix. Returns [l] without chains.
   begin scalar leftl,rightl,lhs,rhs;
      lhs := cadr l;
      if pairp lhs and pasf_opp car lhs then <<
	 leftl := pasf_chsimpat1 lhs;
	 lhs := caddr lastcar leftl
      >>;
      rhs := caddr l;
      if pairp rhs and pasf_opp car rhs then <<
	 rightl := pasf_chsimpat1 rhs;
	 rhs := cadr car rightl
      >>;
      return nconc(leftl,{car l,lhs,rhs} . rightl)
   end;

procedure pasf_simpat(u);
   % Simp atomic formula. [u] is Lisp prefix. Returns an atomic
   % formula.
   begin scalar op,lhs,rhs,nlhs,f,m;
      op := car u;
      if op memq '(cong ncong) then <<
	 if length u neq 4 then
 	    rederr("invalid length in congruence");
	 lhs := subtrsq(simp cadr u,simp caddr u);
	 m := simp cadddr u;
	 if denr lhs neq 1 or denr m neq 1 then
 	    rederr("denominators in congruence");
	 return pasf_0mk2(op . numr m,numr lhs)
      >>;
      lhs := simp cadr u;
      if not (!*rlnzden or !*rlposden or (domainp denr lhs)) then
 	 typerr(u,"atomic formula");
      rhs := simp caddr u;
      if not (!*rlnzden or !*rlposden or (domainp denr rhs)) then
 	 typerr(u,"atomic formula");
      lhs := subtrsq(lhs,rhs);
      nlhs := numr lhs;
      if !*rlposden and not domainp denr lhs then <<
	 f := pasf_0mk2(op,nlhs);
	 if !*rladdcond then
	    f := if op memq '(lessp leq greaterp geq) then
	       rl_mkn('and,{pasf_0mk2('greaterp,denr lhs),f})
	    else
	       rl_mkn('and,{pasf_0mk2('neq,denr lhs),f});
	 return f
      >>;
      if !*rlnzden and not domainp denr lhs then <<
	 if op memq '(lessp leq greaterp geq) then
	    nlhs := multf(nlhs,denr lhs);
	 f := pasf_0mk2(op,nlhs);
	 if !*rladdcond then
	    f := rl_mkn('and,{pasf_0mk2('neq,denr lhs),f});
	 return f
      >>;
      return pasf_0mk2(op,nlhs)
   end;

procedure pasf_termp(exps,exclst);
   % Presburger arithmetic standard form test for a correct presburger
   % term. [exps] is an expression supposed to be a PASF term; [exclst] is an
   % exception list of variables, that are not allowed to be
   % non-linear. Returns t iff the term is a correct UPrA term.
   begin scalar p,errc,oldord;
      oldord:= setkorder({});
      for each var in kernels exps do <<
	 setkorder({var});
	 p := reorder(exps);
	 if var memq exclst then <<
	    % Testing for degree of the variable
	    %if ldeg p > 1 then
	    %   rederr{"Illegal UPrA formula :",
	    %   	  "Quantified variable",var,"with degreee",ldeg p};
	    % Testing for other quantified variables in exception list
	    for each v in exclst do
	       if v neq var and v memq kernels lc p then
 	       	  rederr{"Illegal UPrA formula :",
		  "Quantified variables",var,"and",v,"multiplied"}
	 >>;
	 % Testing for parametric coefficients
	 if not domainp lc p then
	    errc := t
      >>;
      % Term is correct
      setkorder(oldord);
      return errc
   end;

procedure pasf_uprap(f);
   % Presburger arithmetic standard form test for uniform presburger
   % arithmetic formula. [f] is a formula. Returns t only if the formula is
   % in UPrA and not in PrA and raises an error if the formula is neither in
   % PrA nor in UPrA.
   pasf_uprap1(f,nil);

procedure pasf_uprap1(f,bvarl);
   % Presburger arithmetic standard form test for uniform presburger
   % arithmetic formula subprocedure. [f] is a formula; [bvarl] is a list of
   % bounded variables. Returns t only if the formula is in UPrA and not in
   % PrA and raises an error if the formula is neither in PrA nor in UPrA.
   begin scalar s;
      if rl_tvalp f then
      	 return nil;
      if rl_boolp rl_op f then <<
	 % If one of the arguments is in UPrA then the whole formula too
	 for each arg in rl_argn f do
	    s := s or pasf_uprap1(arg,bvarl);
	 return s
      >>;
      if rl_quap rl_op f then 
	 return pasf_uprap1(rl_mat f,rl_var f . bvarl);
      if rl_bquap rl_op f then
	 return (pasf_uprap1(rl_mat f,rl_var f . bvarl) or 
	    pasf_uprap1(rl_b f,bvarl));
      % Atomic formulas
      return if pasf_congp f then
	 pasf_termp(pasf_arg2l f,bvarl) or not domainp pasf_m f
      else
	 pasf_termp(pasf_arg2l f,bvarl)
   end;

procedure pasf_opn(atf);
   % Presburger arithmetic standard form operator name. [atf] is an atomic
   % formula $r(t_1,t_2)$ or $r(t_1,t_2,m)$. Returns $r$.
   if rl_tvalp atf then
      atf
   else if pairp car atf then
      caar atf
   else
      car atf;

procedure pasf_univnlfp(f,x);
   % Presburger arithmetic standard form univariate nonlinear formula
   % predicate. [f] is a formula; [x] is a variable. Returns t iff [f] is a
   % univariate formula and contains a term, that is not linear in [x].
   begin scalar res;
      for each atf in rl_atl f do
      	 res := res or pasf_univnlp(atf,x);
      return res;
   end;

procedure pasf_univnlp(atf,x);
   % Presburger arithmetic standard form univariate nonlinear atomic formula
   % predicate. [atf] is an atomic formula; [x] is a variable. Returns t iff
   % [atf] is a univariate formula and contains a term, that is not linear in
   % [x].
   begin scalar oldord,res;
      oldord := setkorder({x});
      % quick fix to avoid car on nil (TS)
      if not domainp pasf_arg2l atf and ldeg reorder pasf_arg2l atf > 1 then
	 res := t;
      setkorder oldord;
      return res;
   end;

procedure pasf_op(atf);
   % Presburger arithmetic standard form operator. [atf] is an atomic formula
   % $r(t_1,t_2)$ or $r(t_1,t_2,m)$. Returns $r$ or in case of a congruence
   % the pair $(r . m)$.
   car atf;

procedure pasf_opp(op);
   % Presburger arithmetic standard form operator predicate. [op] is an
   % expression. Returns t iff the name of [op] is a legal operator or
   % relation name.
   op memq '(lessp leq equal neq geq greaterp) or
      (pairp op and car op memq '(cong ncong));

procedure pasf_mkop(op,m);
   % Presburger arithmetic standard form make operator. [op] is an operator;
   % [m] is an optional modulus. Returns $op$ if the operator is not 'cong or
   % 'ncong and $([op] . [m])$ otherwise.
   if op memq '(cong ncong) then
      (op . if null m then
	 % User should use equations instead of congruences modulo 0
      	 rederr{"Modulo 0 congruence created"}
      else
	 m)
   else
      op;

procedure pasf_atfp(f);
   % Presburger arithmetic standard form atomic formula predicate. [f] is a
   % formula. Returns t iff [f] has a legal relation name.
   (pasf_opn f) memq '(equal neq leq geq lessp greaterp
      cong ncong);

procedure pasf_congp(atf);
   % Presburger arithmetic standard form congruence atomic formula
   % predicate. [atf] is an atomic formula. Returns t iff the operator is
   % 'cong or 'ncong.
   pasf_opn(atf) memq '(cong ncong);

procedure pasf_m(atf);
   % Presburger arithmetic standard form modulus operator. [atf] is an atomic
   % formula $t_1 \equiv_m t_2$. Returns $m$.
   cdar atf;

procedure pasf_arg2l(atf);
   % Presburger arithmetic standard form left hand side argument. [atf] is an
   % atomic formula $r(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure pasf_arg2r(atf);
   % Presburger arithmetic standard form right hand side argument. [atf] is an
   % atomic formula $r(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure pasf_mk2(op,lhs,rhs);
   % Presburger arithmetic standard form make atomic formula. [op] is an
   % operator; [lhs] is the left handside term; [rhs] is the right handside
   % term. Returns the atomic formula $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure pasf_0mk2(op,lhs);
   % Presburger arithmetic standard form make zero right hand atomic
   % formula. [op] is an operator; [lhs] is a term. Returns the atomic formula
   % $[op]([lhs],0)$.
   {op,lhs,nil};

procedure pasf_mkrng(v,lb,ub);
   % Presburger arithmetic standard form make interval range formula. [v] is a
   % variable; [lb] is a lower bound; [ub] is an upper bound. Returns the
   % formula $[lb] \leq [v] \leq [ub]$.
   if lb eq ub then
      pasf_0mk2('equal,addf(v,negf lb))
   else rl_mkn('and,{
      pasf_0mk2('geq,addf(v,negf lb)),
      pasf_0mk2('leq,addf(v,negf ub))});

endmodule; % [pasf]

end; % of file
