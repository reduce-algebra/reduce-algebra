% ----------------------------------------------------------------------
% $Id: pasf.red,v 1.57 2004/02/22 21:08:15 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002 Andreas Dolzmann, Andreas Seidl, and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: pasf.red,v $
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
   pasf_rcsid!* := "$Id: pasf.red,v 1.57 2004/02/22 21:08:15 lasaruk Exp $";
   pasf_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasf;
% Presburger arithmetic standard form. Main module. Algorithms on
% first-order formulas over the language of rings together with
% congruences, i.e., binary relations [equal], [neq], [cong], [ncong],
% [leq], [geq], [lessp], [greaterp]. The terms are SF's.

create!-package('(pasf pasfbnf pasfmisc pasfnf pasfsiat pasfqe pasfsism),nil);

load!-package 'cl;
load!-package 'rltools;

imports rltools,cl;

fluid '(!*rlverbose);

flag('(pasf),'rl_package);

% Switches
switch rlpasfrangeexpand;
switch rlpasfvb;
switch rlpasfsimplify;
switch rlsiverbose;
switch rlsusitr;
switch rlsusisubst;

% Verboseswitch for atomic formula simplification
switch rlpasfatfsimpvb;

off1 'rlpasfrangeexpand;
off1 'rlpasfvb;
on1 'rlpasfsimplify;
off1 'rlsiverbose;
off1 'rlsusitr;
off1 'rlpasfatfsimpvb;
off1 'rlsusisubst;

% Parameters
put('pasf,'rl_params,'(
   (rl_subat!* . pasf_subat)
   (rl_subalchk!* . pasf_subalchk)
   (rl_eqnrhskernels!* . pasf_eqnrhskernels)
   (rl_simplat1!* . pasf_simplat1)
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
   (rl_bsatp!* . pasf_qff2ivl)
   ));

% Services
put('pasf,'rl_services,'(
   (rl_apnf!* . cl_apnf)
   (rl_atml!* . cl_atml)
   (rl_terml!* . cl_terml)
   (rl_termml!* . cl_termml)
   (rl_tnf!* . cl_tnf)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_all!* . cl_all)
   (rl_ex!* . cl_ex)
   (rl_simpl!* . cl_simpl)
   (rl_atnum!* . cl_atnum)
   (rl_matrix!* . cl_matrix)
   (rl_qe!* . pasf_qe)
   (rl_expand!* . pasf_expand)
   (rl_atl!* . cl_atl)
   (rl_pnf!* . pasf_pnf)
   (rl_dnf!* . cl_dnf)
   (rl_cnf!* . cl_cnf)
   (rl_nnf!* . cl_nnf)
   (rl_simplb!* . pasf_simplb)
   (rl_b2terml!* . pasf_b2terml)
   (rl_b2atl!* . pasf_b2atl)
   ));

% Switches
put('pasf,'rl_cswitches,'(
   (rlsism . t)
   (rlsusi . t)));

% Admin
put('pasf,'simpfnname,'pasf_simpfn);

put('pasf,'rl_prepat,'pasf_prepat);
put('pasf,'rl_resimpat,'pasf_resimpat);
put('pasf,'rl_lengthat,'pasf_lengthat);

put('pasf,'rl_prepterm,'prepf);
put('pasf,'rl_simpterm,'pasf_simpterm);

algebraic infix equal;
put('equal,'pasf_simpfn,'pasf_simpat);
put('equal,'number!-of!-args,2);

algebraic infix neq;
put('neq,'pasf_simpfn,'pasf_simpat);
put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq);

algebraic operator cong;
put('cong,'prifn,'pasf_pricong);
put('cong,'pasf_simpfn,'pasf_simpat);
put('cong,'number!-of!-args,3);
put('cong,'rtypefn,'quotelog);
put('cong,'fancy!-prifn,'pasf_fancy!-pricong);

procedure pasf_pricong(x);
   if null !*nat then
      'failed
   else <<
      maprin cadr x;
      prin2!* " ~";
      maprin cadddr x;
      prin2!* "~ ";
      maprin caddr x
   >>;

% alternative printing with |
%symbolic procedure pasf_fancy!-pricong(c);
%   if null !*nat then
%      'failed
%   else <<
%      maprin cadddr c;
%      if car c eq 'cong then
%	 fancy!-prin2 "|"
%      else
%	 fancy!-prin2 "\not|";
%      maprin cadr c;
%   >>;

procedure pasf_fancy!-pricong(c);
   if rl_texmacsp() then
      pasf_fancy!-pricong!-texmacs c
   else
      pasf_fancy!-pricong!-fm c;

procedure pasf_fancy!-pricong!-texmacs(c);
   if null !*nat then
      'failed
   else <<
      maprin cadr c; % lhs
      if car c eq 'cong then
	 fancy!-prin2 "\equiv"
      else
	 fancy!-prin2 "\not\equiv";
      fancy!-prin2!-underscore();
      fancy!-prin2 "{";
      maprin cadddr c; % modulus
      fancy!-prin2 "}";
      fancy!-prin2 " ";
      maprin caddr c; % rhs
   >>;

procedure pasf_fancy!-pricong!-fm(x);
   if null !*nat then
      'failed
   else <<
      maprin cadr x;
      if car x eq 'cong then
      	 fancy!-special!-symbol(186,2)
      else <<
	 fancy!-prin2 "/";
	 fancy!-special!-symbol(186,2)
      >>;
      maprin caddr x;
      fancy!-prin2 " (";
      maprin cadddr x;
      fancy!-prin2 ")"
   >>;

algebraic operator ncong;
put('ncong,'prifn,'pasf_princong);
put('ncong,'pasf_simpfn,'pasf_simpat);
put('ncong,'number!-of!-args,3);
put('ncong,'rtypefn,'quotelog);
put('ncong,'fancy!-prifn,'pasf_fancy!-pricong);

procedure pasf_princong(x);
   if null !*nat then
      'failed
   else <<
      maprin cadr x;
      prin2!* " #";
      maprin cadddr x;
      prin2!* "# ";
      maprin caddr x
   >>;

algebraic infix leq;
put('leq,'pasf_simpfn,'pasf_simpat);
put('leq,'number!-of!-args,2);
put('leq,'rtypefn,'quotelog);

algebraic infix geq;
put('geq,'pasf_simpfn,'pasf_simpat);
put('geq,'number!-of!-args,2);
put('geq,'rtypefn,'quotelog);

algebraic infix lessp;
put('lessp,'pasf_simpfn,'pasf_simpat);
put('lessp,'number!-of!-args,2);
put('lessp,'rtypefn,'quotelog);

algebraic infix greaterp;
put('greaterp,'pasf_simpfn,'pasf_simpat);
put('greaterp,'number!-of!-args,2);
put('greaterp,'rtypefn,'quotelog);

flag('(equal neq leq geq lessp greaterp),'spaced);

flag('(pasf_simpat),'full);

% Temporarily introduced algebraic mode interfaces

operator rlqeex;
procedure rlqeex(phi,k);
   rl_mk!*fof pasf_qeex(rl_simp phi,k);

operator rlsimplb;
procedure rlsimplb(phi,k);
   rl_mk!*fof rl_simplb(rl_simp phi,k);
   %rl_mk!*fof rl_simp phi;

operator rlstrb;
procedure rlstrb(phi);
   (if res then rl_mk!*fof res else '(list))
      where res = cl_simpl!-bqua!-strb(rl_simp phi,'unknown);

operator rleq;
procedure rleq(phi);
   (if res then rl_mk!*fof res else '(list))
      where res = cl_simpl!-bqua!-eq(rl_simp phi);

operator rlsimplat;
procedure rlsimplat(phi);
  rl_mk!*fof rl_simplat1(rl_simp phi,'dummy);

operator rlivl2qff;
procedure rlivl2qff(ivl,var);
   rl_mk!*fof pasf_ivl2qff(for each iv in cdr ivl collect
      cadr iv . caddr iv,var);

operator rlqff2ivl;
procedure rlqff2ivl(f);
   'list . for each iv in pasf_qff2ivl1(rl_simp f) collect
      {'list,car iv,cdr iv};

operator rlb2terml;
procedure rlb2terml(b, var);
   'list . pasf_b2terml(rl_simp b, var);

operator rlb2atl;
procedure rlb2atl(b, var);
   'list . for each at in rl_b2atl(rl_simp b, var) collect rl_mk!*fof at;

% End of temporary methods

procedure pasf_verbosep();
   % Presburger arithmetic verbose verbose switch. Returns true if the
   % main switch rlverbose is on and the secondary switch rlpasfvb is
   % on.
   !*rlverbose and !*rlpasfvb;

procedure pasf_simpterm(u);
   % Presburger arithmetic simp term. [u] is Lisp Prefix. Returns
   % the [u] as a PASF term.
   numr simp u;

procedure pasf_prepat(f);
   % Presburger arithmetic prep atomic formula. [f] is a PASF
   % atomic formula. Returns [f] in Lisp prefix form.
   if pasf_cong f then
       {pasf_opn f,prepf pasf_arg2l f,prepf pasf_arg2r f,pasf_m f}
   else
      pasf_opn f . for each arg in pasf_argn f collect prepf arg;

procedure pasf_resimpat(f);
   % Presburger arithmetic resimp atomic formula. [f] is an PASF
   % atomic formula. Returns the atomic formula [f] with resimplified
   % terms.
   pasf_mkn(pasf_op f,for each arg in pasf_argn f collect
      numr resimp !*f2q arg);

procedure pasf_lengthat(f);
   % Presburger arithmetic length of atomic formula. [f] is an
   % atomic formula. Returns a number, the length of [f].
   length pasf_argn f;

procedure pasf_simpat(u);
   % Presburger arithmetic simp atomic formula. [u] is Lisp prefix.
   % Returns [u] as an atomic formula.
   begin scalar op,lhs,rhs,m,term,atf;
      op := car u;
      lhs := simp cadr u;
      if denr lhs neq 1 then
 	 typerr(u,"atomic formula");
      rhs := simp caddr u;
      if denr rhs neq 1 then
 	 typerr(u,"atomic formula");
      term := numr subtrsq(lhs,rhs);
      % Check for the correct term form. Method fails if
      % the term is not correct.
      tnf_expr2tnf term;
      % Now the formula term is surely correct
      if op memq '(cong ncong) then <<
	 m := cadddr u;
	 if not (numberp m) or eqn(m,0) then
	    typerr(m,"modulus");
	 return pasf_0mk2((op . numr simp m),term)
      >>;
      atf := pasf_0mk2(op,term);
      return atf;
   end;

procedure pasf_opn(atf);
   % Presburger arithmetic operator name. [atf] is an atomic formula
   % $R(t_1,t_2)$. Returns the name of $R$.
   if pairp car atf then
      caar atf
   else
      car atf;

procedure pasf_op(atf);
   % Presburger arithmetic operator. [atf] is an atomic formula
   % $R(t_1,t_2)$. Returns $R$.
   car atf;

procedure pasf_mkop(op,m);
   % Presburger arithmetic make operator. [op] is one of the operators
   % [equal], [neq], [cong], [ncong], [leq], [geq], [lessp],
   % [greaterp]; m is a modulus. Returns $op$ if operator is not
   % [cong] or [ncong] and $(op . m)$ else.
   if op memq '(cong ncong) then
      (op . if null m then
      	 rederr{"Modulo 0 congruence created"}
      else
	 m)
   else
      op;

procedure pasf_atfp(f);
   % Presburger arithmetic atomic formula predicate. [f] is a
   % formula. Returns t is and only if [f] is an atomic formula.
   (pasf_opn f) memq '(equal neq leq geq lessp greaterp
      cong ncong);

procedure pasf_cong(atf);
   % Presburger arithmetic congruence atomic formula. [atf] is an
   % atomic formula. Returns $t$ if the operator is [cong] or [ncong].
   pasf_opn(atf) memq '(cong ncong);

procedure pasf_m(atf);
   % Presburger arithmetic modulus operator. [atf] is an atomic
   % formula $t_1 = t_2 ~(n)$. Returns $n$.
   cdar atf;

procedure pasf_hasm(atf);
   % Presburger arithmetic has modulus operator. [atf] is an atomic
   % formula $t_1 = t_2 ~(n)$. Returns $true$ if and only if [atf]
   % is a congruence.
   pairp car atf;

procedure pasf_arg2l(atf);
   % Presburger arithmetic binary operator left hand side argument.
   % [atf] is an atomic formula $R(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure pasf_arg2r(atf);
   % Presburger arithmetic binary operator right hand side argument.
   % [atf] is an atomic formula $R(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure pasf_argn(atf);
   % Presburger arithmetic n-ary operator argument list. [atf] is an
   % atomic formula $R(t_1,...,t_n)$. Returns the list
   % $(t_1,...,t_n)$.
   cdr atf;

procedure pasf_mk2(op,lhs,rhs);
   % Presburger arithmetic make atomic formula for binary operator.
   % [op] is one of the operators [equal], [neq], [div], [sdiv],
   % [assoc], and [nassoc]; [lhs] and [rhs] are terms. Returns the
   % atomic formula $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure pasf_0mk2(op,lhs);
   % Presburger arithmetic make zero right hand atomic formula for
   % binary operator. [op] is one of the operators [equal], [neq],
   % [div], [sdiv], [assoc], and [nassoc]; [lhs] is a term. Returns
   % the atomic formula $[op]([lhs],0)$.
   {op,lhs,nil};

procedure pasf_mkn(op,argl);
   % Presburger arithmetic make atomic formula for n-ary operator.
   % [op] is one of the operators [equal], [neq], [div], [sdiv],
   % [assoc], and [nassoc]; [argl] is a list $(t_1,t_2)$ of terms.
   % Returns the atomic formula $[op](t_1,t_2)$.
   op . argl;

procedure pasf_mkrng(bv,lr,ur);
   % Presburger arithmetic make range operator. [bv] is the variable
   % to bound; [lr] and [ur] are the bounds. Returns the range formula
   % $[lr] \leq [bv] \leq [ur]$.
   if domainp lr and domainp ur then
      if lr=ur then
	 pasf_mk2('equal,numr simp bv,lr)
      else rl_mkn('and,{
      	 pasf_mk2('geq,numr simp bv,numr simp lr),
      	 pasf_mk2('leq,numr simp bv,numr simp ur)})
   else
      rederr{"pasf_mkrng : Bounds should be domain valued elements"};

procedure pasf_mknrng(bv,lr,ur);
   % Presburger arithmetic make negated range operator. [bv] is the
   % variable to bound; [lr] and [ur] are the bounds. Returns the
   % negated range formula $[lr] \leq [bv] \leq [ur]$.
   if domainp lr and domainp ur then
      rl_mkn('or,{
      	 pasf_mk2('leq,numr simp bv,lr),
      	 pasf_mk2('geq,numr simp bv,ur)})
   else
        rederr{"pasf_mkrng : Bounds should be domain valued elements"};

endmodule;  % [pasf]

end;  % of file
