% ----------------------------------------------------------------------
% $Id: ofsf.red,v 1.24 1999/03/23 12:26:33 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: ofsf.red,v $
% Revision 1.24  1999/03/23 12:26:33  sturm
% Renamed switch rlsisqf to rlsiatadv.
%
% Revision 1.23  1999/03/23 07:40:16  dolzmann
% Changed copyright information.
% Added list of exported procedures and import list.
%
% Revision 1.22  1999/03/21 13:37:18  dolzmann
% Use cl_bnfsimpl instead of acfsf_bnfsimpl.
% Removed black box rl_zero.
%
% Revision 1.21  1999/03/18 14:08:20  sturm
% Added new service rl_specelim!* in cl_qe for covering the "super
% quadratic special case' for ofsf. This method is toggled by switch
% rlsqsc, which is off by default. Context dvfsf uses cl_specelim which
% is constantly "false." Context acfsf does not use cl_qe at all.
%
% Revision 1.20  1998/04/09 11:00:03  sturm
% Added switch rlqeqsc for quadratic special case. This now OFF by default!
%
% Revision 1.19  1997/08/24 16:18:50  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.18  1997/08/14 10:10:30  sturm
% Renamed rldecdeg to rldecdeg1.
% Added service rldecdeg.
%
% Revision 1.17  1997/08/13 12:44:38  dolzmann
% Introduced service rldecdeg.
%
% Revision 1.16  1996/10/23 11:24:48  dolzmann
% Added procedure ofsf_mkstrict.
%
% Revision 1.15  1996/10/20 15:54:57  sturm
% Added switches rlnzden, rlposden, and rladdcond and corresponding code
% handling the input of reciprocal terms.
%
% Revision 1.14  1996/10/17 13:52:07  sturm
% Introduced services rlvarl, rlfvarl, and rlbvarl. Renamed cl_varl to
% cl_varl1 for this.
%
% Revision 1.13  1996/10/14 16:03:08  sturm
% Declared !*rlqeheu fluid for the optimizer.
%
% Revision 1.12  1996/10/08 13:54:33  dolzmann
% Renamed "degree parity decomposition" to "parity decomposition".
% Adapted names of procedures and switches accordingly.
%
% Revision 1.11  1996/10/01 10:23:07  reiske
% Added ofsf services rlqews and rlqeipo.
% Introduced new service rltnf and related code.
%
% Revision 1.10  1996/09/30 16:55:30  sturm
% Switched to new tableau code.
%
% Revision 1.9  1996/09/29 14:22:57  sturm
% Introduced services rlqea and rlgqea.
%
% Revision 1.8  1996/09/26 11:48:55  dolzmann
% Do not use T as formal parameter.
%
% Revision 1.7  1996/09/05 11:14:46  dolzmann
% Introduced new switch !*rlqegenct.
% Using cl black box implementation for black box rl_trygauss.
% Introduced new black boxes rl_qefsolset, rl_bettergaussp!*, rl_bestgaussp,
% rl_esetunion, rl_structat, rl_ifstructat, and rl_termmlat.
% Introduced new services rl_ifacml, rl_struct, rl_ifstruct, rl_termml, and
% rl_terml.
% Added lost procedure ofsf_simpterm.
%
% Revision 1.6  1996/08/01 11:45:27  reiske
% Added services rl_natab, rl_nitab, and rl_gentheo.
% Added black boxes rl_a2cdl and rl_getineq.
%
% Revision 1.5  1996/07/13 11:09:33  dolzmann
% Introduced new switches !*rlgsbnf and !*rlgsutord.
% Using cl black box implementations for black boxes rl_smsimpl!-impl
% and rl_smsimpl!-equiv1.
%
% Revision 1.4  1996/07/07 14:38:14  sturm
% Introduced new service rl_nnfnot.
% Introduced new black box rl_eqnrhskernels.
%
% Revision 1.3  1996/05/21 17:14:07  sturm
% Added service rl_subfof and black boxes rl_subat, rl_subalchk.
%
% Revision 1.2  1996/05/12 08:27:19  sturm
% Loading rltools now.
% Introduced new switch rlsitsqspl.
% Introduced internal switch !*rlqegen.
% Removed context control for switch ezgcd.
% Introduced new services rl_thsimpl and rl_gqe.
%
% Revision 1.1  1996/03/22 12:13:59  sturm
% Moved and split.
%
% Revision 1.25  1996/03/18 15:46:31  sturm
% Moved switch defaults to module rl.
% Removed ofsf_enter, ofsf_exit, and ofsf_svezgcd!*. The ezgcd is treated
% as context switch now.
% Added service rl_atml.
% Removed properties ofsf_prepfn from the ofsf predicates.
% Removed properties "prepfnname", "prepdefault", "resimpfnname", and
% "resimpdefault" from "ofsf."
% Added property "rl_prepat" to "ofsf."
% Added procedures ofsf_prepat, ofsf_resimpat, ofsf_lengthat,
% Added service rl_atml.
% Removed procedure ofsf_tordp.
% Adapted black box implementation ofsf_fctrat: the content is dropped now.
%
% Revision 1.24  1996/03/11 13:19:23  reiske
% Added black box implementations ofsf_fctrat and ofsf_tordp.
%
% Revision 1.23  1996/03/10 13:03:49  sturm
% Added default setting for switch !*rlqeheu.
% Added service rl_matrix.
% Changed verbosity output in module ofsfqe.
% Removed Gauss code that was commented out previously.
%
% Revision 1.22  1996/03/10 12:48:54  dolzmann
% Set services rl_dnf to ofsf_dnf and rl_cnf to ofsf_cnf respectively.
% Added procedures ofsf_dnf, ofsf_cnf. These procedures call
% cl_cnf/cl_cnf with !*rlsiso on where necessary.
% Introduced new switch !*rlgsvb and corresponding code. Groebner
% simplifier gives verbosity output only with both !*rlverbose and
% !*rlgsvb on.
%
% Revision 1.21  1996/03/09 13:36:02  sturm
% Added switch rlqesr and corresponding code.
% Renamed constructors:
%  ofsf_constr2 -> ofsf_mk2
%  ofsf_0constr2 -> ofsf_0mk2
%  ofsf_constrn -> ofsf_mkn
% Changes in module ofsfqe:
% Added procedures ofsf_qesubcr1, ofsf_qesubcrpe1 and ofsf_qesubcrme1.
% Added parameter "ans" to procedures ofsf_translat, ofsf_trygauss, and
% ofsf_findeqsol.
% Fixed a bug in (former) ofsf_qemkans.
% Added procedures ofsf_qemkans1 and ofsf_qebacksub for answer
% back-substitution.
%
% Revision 1.20  1996/03/04 17:11:41  sturm
% Added ofsf_enter, ofsf_exit, and fluid ofsf_svezgcd!* for turning on
% ezgcd while in ofsf context.
% Added black box implementations ofsf_transform, ofsf_updatr.
% Fixed a bug in ofsf_qscp.
% Added detection of formulas that are linear after factorization to
% ofsf_varsel. The same for quadratic formulas.
% Added handling of answer transformations to ofsf_qemkans.
% Moved ofsf_reorder to module sfto.
%
% Revision 1.19  1996/03/04 13:09:19  dolzmann
% Removed loading of groebner packages.
% Added switch !*rlbnfsac.
% Added black box implementations ofsf_bnfsimpl, ofsf_sacat, ofsf_sacatlp.
% New module ofsf_bnf. Moved code for bnf computation from ofsf_below to
% ofsf_bnf.
% Turned off !*rlsiexpla with groebner simplifier
% Moved procedures gs_groebnerf, gs_preducef, gs_greducef to module sfto.
% Moved procedure ofsf_gsatlp to module cl.
%
% Revision 1.18  1996/02/28 13:15:24  sturm
% Added quadratic special case detection to ofsf_varsel.
% Fixed bugs in elimination set computation.
%
% Revision 1.17  1996/02/26 12:46:51  sturm
% Started the implementation of a proper ofsf_varsel.
% Added factorization to the ofsf_translat and ofsf_trygauss black box
% implementations. Degree violations are communicated to the module cl
% now.
% Fixed a bug in ofsf_elimsetscl.
% Removed treatment of ...2q keys from the elimination set computation.
%
% Revision 1.16  1996/02/18 15:55:14  sturm
% Turned rlsiexpla on by default.
%
% Revision 1.15  1996/02/18 14:27:58  sturm
% Updated export list.
% Added factorization to ofsf_simplequal and ofsf_simplneq. Added
% corresponding switch !*rlsifac.
% Removed switch !*rlsdnf.
% Added black box implementation ofsf_trygauss.
% Changed default settings for the switches !*rlqedfs and !*rlsimpl.
% Added service rlatl.
% Added procedures ofsf_rotrel, ofsf_crotrel, and ofsf_reorder.
% Moved ofsf_splitterm and ofsf_mksol from module ofsfqe to
% ofsf_optsplitterm and ofsf_optmksol resp. in module ofsfopt.
% Rewritten module ofsfqe. Implemented quadratic elimination. This module
% is under development.
%
% Revision 1.14  1996/02/18 12:46:07  dolzmann
% Added default value for switch !*rlgserf.
% Rewritten module ofsfgs.
%
% Revision 1.13  1995/11/16  08:06:36  sturm
% Added default setting for switch rlsimpl.
%
% Revision 1.12  1995/10/18  08:53:05  sturm
% Added switches rlbnfsb, rlbnfsm, parameter rlsubsumption!*, and
% respective code.
% Bug fix: atomic formulas are made unique in ofsf_entry2at now.
% Made ofsf_gsd use DNF computation.
%
% Revision 1.11  1995/09/05  08:05:15  sturm
% Reimplemented parts of smart simplification. Added switches rlsipo,
% rlsipw; fixed a bug in smart simplification of impl.
% Modified procedure ofsf_esaord: improved substitution, added switch
% rlqesdnf.
%
% Revision 1.10  1995/08/31  08:40:47  sturm
% Added RTYPEFN property to all relations except equal.
%
% Revision 1.9  1995/08/30  08:09:15  sturm
% Moved interface code to file rlsf and adapted the tag properties.
% Fixed a bug: renamed cl_smsimpl!-equiv to ofsf_smsimpl!-equiv1.
% Major changes in module ofsfopt:
%   Added BFS option to ofsf_opt2 using switch rlqedfs.
%   Changed return protocol in ofsf_opt2.
%   Added elimination set computation wrt. "z". Code contains some
%   experimental switches.
%   Added counting of tree nodes with verbose output.
%
% Revision 1.8  1995/08/08  10:18:18  sturm
% Added smart simplification code for impl and equiv.
% Adapted calls to cl_simpl to the new knowl argument.
%
% Revision 1.7  1995/08/03  05:39:06  dolzmann
% Added procedures ofsf_gsn, ofsf_gsatlp.
%
% Revision 1.6  1995/08/02  08:19:08  sturm
% Split module ofsfsimpl into ofsfsimplat and ofsfsmsimpl. Rewritten
% smart simplification code.
% Minor changes in module ofsfgs; fixed term ordering to REVGRADLEX.
% Changed copyright messages.
%
% Revision 1.5  1995/07/12  15:08:54  sturm
% Added procedure ofsf_optsubstat to module ofsfopt.
% Added procedures ofsf_ordatp and ofsf_ordrelp.
% Set service rl_identifyonoff to cl_identifyonoff.
%
% Revision 1.4  1995/07/07  11:12:25  sturm
% Removed remflag statement for load!-package.
% Removed "_" in switch names.
% Added export statement.
% Added switch rlopt1s.
% Added procedures ofsf_qemkans (parameter function), ofsf_simpterm,
% ofsf_prepterm, and ofsf_mkterm.
% Added comments.
% Changes in module ofsfopt.
% Renamed Groebner simplifiers: ofsf_gbcsimpl to ofsf_gsc and
% ofsf_gbdsimpl to ofsf_gsd.
% Changed verbosity output, ioto is used now.
%
% Revision 1.3  1995/06/21  10:42:02  sturm
% Removed declarations of non-used local variables.
% Turned on switch rl_tabib by default.
% Updated create!-package commented it out.
% Many changes in module ofsfqe.
% Added smart simplification code in module ofsfsimpl; ofsf_simpl1 is
% used instead of of_simpl1 now.
% Added module ofsfopt.
%
% Revision 1.2  1995/06/01  13:54:04  dolzmann
% Added switch rl_verbose.
% Fixed bugs in ofsf_simplleq and ofsf_simplgreaterp.
% Added module ofsfgs containing a Groebner simplifier. Parts of the
% interface have already been part of the previous revision.
%
% Revision 1.1  1995/05/29  14:47:21  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ofsf_rcsid!* ofsf_copyright!*);
   ofsf_rcsid!* := "$Id: ofsf.red,v 1.24 1999/03/23 12:26:33 sturm Exp $";
   ofsf_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module ofsf;
% Ordered field standard form. Main module. Algorithms on first-order
% formulas over ordered fields. The language contains binary relations
% ['equal], ['neq], ['greaterp], ['lessp], ['geq], ['leq].

create!-package('(ofsf ofsfsiat ofsfsism ofsfbnf ofsfqe ofsfopt ofsfgs
   ofsfmisc),nil);

load!-package 'cl;
load!-package 'rltools;

exports ofsf_simpterm,ofsf_prepat,ofsf_resimpat,ofsf_lengthat,ofsf_chsimpat,
   ofsf_simpat,ofsf_op,ofsf_arg2l,ofsf_arg2r,ofsf_argn,ofsf_mk2,ofsf_0mk2,
   ofsf_mkn,ofsf_opp,ofsf_mkstrict,ofsf_simplat1,ofsf_smrmknowl,ofsf_smcpknowl,
   ofsf_smupdknowl,ofsf_smmkatl,ofsf_dnf,ofsf_cnf,ofsf_subsumption,
   ofsf_sacatlp,ofsf_sacat,ofsf_varsel,ofsf_qesubcr1,ofsf_qesubcr2,ofsf_qesubr,
   ofsf_qesubcq,ofsf_qesubq,ofsf_qesubi,ofsf_qesubcrpe1,ofsf_qesubcrme1,
   ofsf_qesubcrpe2,ofsf_qesubcrme2,ofsf_qesubrpe,ofsf_qesubrme,ofsf_qesubcqpe,
   ofsf_qesubcqme,ofsf_qesubqpe,ofsf_qesubqme,ofsf_valassp,ofsf_translat,
   ofsf_surep,ofsf_elimset,ofsf_bettergaussp,ofsf_esetunion,ofsf_bestgaussp,
   ofsf_qefsolset,ofsf_qemkans,ofsf_preprexpr,ofsf_decdeg,ofsf_decdeg1,
   ofsf_transform,ofsf_updatr,ofsf_thsimpl,ofsf_specelim,ofsf_opt,ofsf_gsn,
   ofsf_gsc,ofsf_gsd,ofsf_gssimplify,ofsf_gssimplify0,ofsf_termprint,
   ofsf_canegrel,ofsf_anegrel,ofsf_clnegrel,ofsf_lnegrel,ofsf_fctrat,
   ofsf_negateat,ofsf_varlat,ofsf_varsubstat,ofsf_ordatp,ofsf_ordrelp,
   ofsf_a2cdl,ofsf_t2cdl,ofsf_subat,ofsf_subalchk,ofsf_eqnrhskernels,
   ofsf_getineq,ofsf_structat,ofsf_ifstructat,ofsf_termmlat,ofsf_multsurep;

imports cl,rltools;

fluid '(!*rlsiatadv !*rlsipd !*rlsiexpl !*rlsiexpla !*rlgssub !*rlsiso !*rlqesr
   !*rlgsrad !*rlgsred !*rlgsprod !*rlgserf !*rlverbose !*rlqedfs !*rlsipw
   !*rlsipo !*rlparallel !*rlopt1s !*rlsifac !*rlbnfsac !*rlgsvb !*rlqegen
   !*rlsitsqspl !*rlgsbnf !*rlgsutord !*rlqegenct !*rlqeheu !*rlnzden
   !*rlposden !*rladdcond !*rlqeqsc !*rlqesqsc !*rlsusi);

flag('(ofsf),'rl_package);

% Parameters
put('ofsf,'rl_params,'(
   (rl_subat!* . ofsf_subat)
   (rl_subalchk!* . ofsf_subalchk)
   (rl_eqnrhskernels!* . ofsf_eqnrhskernels)
   (rl_ordatp!* . ofsf_ordatp)
   (rl_qemkans!* . ofsf_qemkans)
   (rl_simplat1!* . ofsf_simplat1)
   (rl_smupdknowl!* . ofsf_smupdknowl)
   (rl_smrmknowl!* . ofsf_smrmknowl)
   (rl_smcpknowl!* . ofsf_smcpknowl)
   (rl_smmkatl!* . ofsf_smmkatl)
   (rl_smsimpl!-impl!* . cl_smsimpl!-impl)
   (rl_smsimpl!-equiv1!* . cl_smsimpl!-equiv1)
   (rl_negateat!* . ofsf_negateat)
   (rl_varlat!* . ofsf_varlat)
   (rl_varsubstat!* . ofsf_varsubstat)
   (rl_translat!* . ofsf_translat)
   (rl_elimset!*. ofsf_elimset)
   (rl_trygauss!* . cl_trygauss)
   (rl_varsel!* . ofsf_varsel)
   (rl_subsumption!* . ofsf_subsumption)
   (rl_bnfsimpl!* . cl_bnfsimpl)
   (rl_sacat!* . ofsf_sacat)
   (rl_sacatlp!* . ofsf_sacatlp)
   (rl_fctrat!* . ofsf_fctrat)
   (rl_tordp!* . ordp)
   (rl_transform!* . ofsf_transform)
   (rl_updatr!* . ofsf_updatr)
   (rl_a2cdl!* . ofsf_a2cdl)
   (rl_t2cdl!* . ofsf_t2cdl)
   (rl_getineq!* . ofsf_getineq)
   (rl_qefsolset!* . ofsf_qefsolset)
   (rl_bettergaussp!* . ofsf_bettergaussp)
   (rl_bestgaussp!* . ofsf_bestgaussp)
   (rl_esetunion!* . ofsf_esetunion)
   (rl_structat!* . ofsf_structat)
   (rl_ifstructat!* . ofsf_ifstructat)
   (rl_termmlat!* . ofsf_termmlat)
   (rl_multsurep!* . ofsf_multsurep)
   (rl_specelim!* . ofsf_specelim)));

% Services
put('ofsf,'rl_services,'(
   (rl_subfof!* . cl_subfof)
   (rl_identifyonoff!* . cl_identifyonoff)
   (rl_simpl!* . cl_simpl)
   (rl_thsimpl!* . ofsf_thsimpl)
   (rl_nnf!* . cl_nnf)
   (rl_nnfnot!* . cl_nnfnot)
   (rl_pnf!* . cl_pnf)
   (rl_cnf!* . ofsf_cnf)
   (rl_dnf!* . ofsf_dnf)
   (rl_all!* . cl_all)
   (rl_ex!* . cl_ex)
   (rl_atnum!* . cl_atnum)
   (rl_tab!* . cl_tab)
   (rl_atab!* . cl_atab)
   (rl_itab!* . cl_itab)
   (rl_gsc!* . ofsf_gsc)
   (rl_gsd!* . ofsf_gsd)
   (rl_gsn!* . ofsf_gsn)
   (rl_qe!* . cl_qe)
   (rl_qea!* . cl_qea)
   (rl_gqe!* . cl_gqe)
   (rl_gqea!* . cl_gqea)
   (rl_qeipo!* . cl_qeipo)
   (rl_qews!* . cl_qews)
   (rl_opt!* . ofsf_opt)
   (rl_ifacl!* . cl_ifacl)
   (rl_ifacml!* . cl_ifacml)
   (rl_matrix!* . cl_matrix)
   (rl_apnf!* . cl_apnf)
   (rl_atml!* . cl_atml)
   (rl_tnf!* . cl_tnf)
   (rl_atl!* . cl_atl)
   (rl_struct!* . cl_struct)
   (rl_ifstruct!* . cl_ifstruct)
   (rl_termml!* . cl_termml)
   (rl_terml!* . cl_terml)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_gentheo!* . cl_gentheo)
   (rl_decdeg!* . ofsf_decdeg)
   (rl_decdeg1!* . ofsf_decdeg1)
   (rl_surep!* . cl_surep)
   (rl_siaddatl!* . cl_siaddatl)));

% Admin
put('ofsf,'simpfnname,'ofsf_simpfn);
put('ofsf,'simpdefault,'ofsf_simprel);

put('ofsf,'rl_prepat,'ofsf_prepat);
put('ofsf,'rl_resimpat,'ofsf_resimpat);
put('ofsf,'rl_lengthat,'ofsf_lengthat);

put('ofsf,'rl_prepterm,'prepf);
put('ofsf,'rl_simpterm,'ofsf_simpterm);

algebraic infix equal;
put('equal,'ofsf_simpfn,'ofsf_chsimpat);
put('equal,'number!-of!-args,2);

algebraic infix neq;
put('neq,'ofsf_simpfn,'ofsf_chsimpat);
put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq);

algebraic infix leq;
put('leq,'ofsf_simpfn,'ofsf_chsimpat);
put('leq,'number!-of!-args,2);
put('leq,'rtypefn,'quotelog);

algebraic infix geq;
put('geq,'ofsf_simpfn,'ofsf_chsimpat);
put('geq,'number!-of!-args,2);
put('geq,'rtypefn,'quotelog);

algebraic infix lessp;
put('lessp,'ofsf_simpfn,'ofsf_chsimpat);
put('lessp,'number!-of!-args,2);
put('lessp,'rtypefn,'quotelog);

algebraic infix greaterp;
put('greaterp,'ofsf_simpfn,'ofsf_chsimpat);
put('greaterp,'number!-of!-args,2);
put('greaterp,'rtypefn,'quotelog);

flag('(equal neq leq geq lessp greaterp),'spaced);
flag('(ofsf_chsimpat),'full);

procedure ofsf_simpterm(u);
   numr simp u;

procedure ofsf_prepat(f);
   {ofsf_op f,prepf ofsf_arg2l f,prepf ofsf_arg2r f};

procedure ofsf_resimpat(f);
   ofsf_mk2(ofsf_op f,
      numr resimp !*f2q ofsf_arg2l f,numr resimp !*f2q ofsf_arg2r f);

procedure ofsf_lengthat(f);
   2;

procedure ofsf_chsimpat(u);
   rl_smkn('and,for each x in ofsf_chsimpat1 u collect ofsf_simpat x);

procedure ofsf_chsimpat1(u);
   begin scalar leftl,rightl,lhs,rhs;
      lhs := cadr u;
      if pairp lhs and ofsf_opp car lhs then <<
	 leftl := ofsf_chsimpat1 lhs;
	 lhs := caddr lastcar leftl
      >>;
      rhs := caddr u;
      if pairp rhs and ofsf_opp car rhs then <<
	 rightl := ofsf_chsimpat1 rhs;
	 rhs := cadr car rightl
      >>;
      return nconc(leftl,{car u,lhs,rhs} . rightl)
   end;

procedure ofsf_simpat(u);
   % Ordered field simp atomic formula. [u] is Lisp prefix. Returns an
   % atomic formula.
   begin scalar op,lhs,rhs,nlhs,f;
      op := car u;
      lhs := simp cadr u;
      if not (!*rlnzden or !*rlposden or (domainp denr lhs)) then
 	 typerr(u,"atomic formula");
      rhs := simp caddr u;
      if not (!*rlnzden or !*rlposden or (domainp denr rhs)) then
 	 typerr(u,"atomic formula");
      lhs := subtrsq(lhs,rhs);
      nlhs := numr lhs;
      if !*rlposden and not domainp denr lhs then <<
	 f := ofsf_0mk2(op,nlhs);
	 if !*rladdcond then
	    f := if op memq '(lessp leq greaterp geq) then
	       rl_mkn('and,{ofsf_0mk2('greaterp,denr lhs),f})
	    else
	       rl_mkn('and,{ofsf_0mk2('neq,denr lhs),f});
	 return f
      >>;
      if !*rlnzden and not domainp denr lhs then <<
	 if op memq '(lessp leq greaterp geq) then
	    nlhs := multf(nlhs,denr lhs);
	 f := ofsf_0mk2(op,nlhs);
	 if !*rladdcond then
	    f := rl_mkn('and,{ofsf_0mk2('neq,denr lhs),f});
	 return f
      >>;
      return ofsf_0mk2(op,nlhs)
   end;

procedure ofsf_op(atf);
   % Ordered field operator. [atf] is an atomic formula
   % $R(t_1,t_2)$. Returns $R$.
   car atf;

procedure ofsf_arg2l(atf);
   % Ordered field binary operator left hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure ofsf_arg2r(atf);
   % Ordered field binary operator right hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure ofsf_argn(atf);
   % Ordered field binary operator right hand side argument. [atf] is
   % an atomic formula $R(t_1,t_2)$. Returns the list $(t_1,t_2)$.
   {cadr atf,caddr atf};

procedure ofsf_mk2(op,lhs,rhs);
   % Ordered field constructor for binary operator. [op] is a relation
   % [lhs] and [rhs] are terms. Returns the atomic formula
   % $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure ofsf_0mk2(op,lhs);
   % Ordered field zero constructor for binary operator. [op] is a
   % relation [lhs] is a term. Returns the atomic formula
   % $[op]([lhs],0)$.
   {op,lhs,nil};

procedure ofsf_mkn(op,argl);
   % Ordered field constructor for binary operator. [op] is a relation
   % [argl] is a list $(t_1,t_2)$ of terms. Returns the atomic formula
   % $[op](t_1,t_2)$.
   {op,car argl,cadr argl};

procedure ofsf_opp(op);
   % Orderd field standard form operator predicate. [op] is an
   % S-expression. Returns [nil] if op is not a relation.
   op memq '(lessp leq equal neq geq greaterp);

procedure ofsf_mkstrict(r);
   % Ordered field standard form make strict. [r] is an ordering
   % relation. Returns the strict part of [r].
   if r eq 'leq then 'lessp else if r eq 'geq then 'greaterp else r;

endmodule;  % [ofsf]

end;  % of file
