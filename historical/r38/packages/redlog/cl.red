% ----------------------------------------------------------------------
% $Id: cl.red,v 1.14 2002/08/23 12:32:10 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: cl.red,v $
% Revision 1.14  2002/08/23 12:32:10  dolzmann
% Added local quantifier elimination.
%
% Revision 1.13  2002/05/28 13:21:54  sturm
% Added black box rl_fbqe() and corresponding switch rlqefb.
% That is, for ofsf, rlqe uses rlcad in case of failure now.
%
% Revision 1.12  1999/04/13 13:17:57  sturm
% Reformatted one comment.
%
% Revision 1.11  1999/04/12 09:28:16  sturm
% Updated comments for exported procedures.
%
% Revision 1.10  1999/03/22 17:06:09  dolzmann
% Changed copyright information.
% Added list of exported procedures.
% Reformatted comments.
%
% Revision 1.9  1997/08/24 16:18:47  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.8  1996/10/23 11:27:11  dolzmann
% Added switch rlqevarsel and corresponding code.
%
% Revision 1.7  1996/10/10 10:14:27  sturm
% Added missing fluid declarations for !*rlsipw and !*rlsipo.
%
% Revision 1.6  1996/10/01 10:24:53  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.5  1996/09/26 11:50:23  dolzmann
% Fixed a bug in the fluid declaration.
%
% Revision 1.4  1996/09/05 11:11:06  dolzmann
% Added fluid declaration of !*rlbnfsac and !*rltabib.
%
% Revision 1.3  1996/06/07 08:52:14  sturm
% Do not load assist anymore.
%
% Revision 1.2  1996/05/12 08:26:33  sturm
% Loading rltools now.
% Introduced new internal switch !*rlqegen.
%
% Revision 1.1  1996/03/22 10:31:24  sturm
% Moved and split.
%
% Revision 1.22  1996/03/18 15:45:28  sturm
% Moved rl operator classification predicates to module rl.
% Added procedure cl_atml.
% Changed specification of rl_fctrat: the content is dropped now.
%
% Revision 1.21  1996/03/11 13:18:40  reiske
% Added procedures cl_apnf, cl_freevp, and cl_ifacl.
%
% Revision 1.20  1996/03/10 13:03:15  sturm
% Changed verbosity output in module clqe. Added switch !*rlqeheu and
% corresponding code there.
%
% Revision 1.19  1996/03/10 12:48:12  dolzmann
% Minor changes in module clbnf. Procedures use the rl access functions
% for handling strict normal forms.
% Bug fixes in code for order theoretical subsumption and cut.
%
% Revision 1.18  1996/03/09 13:34:07  sturm
% Added procedure cl_matrix.
% Modification in module clqe: pass the ans flag to the "trygauss" black
% box, and via cl_qeatal to the "translat" black box.
% Turned black box smacros into procedures and moved them to the module
% rl changing the "cl_" prefixes into "rl_" accordingly.
% Moved the constructors and access functions to module rl. They have
% been renamed according to the following table:
%  cl_op       -> rl_op
%  cl_arg1     -> rl_arg1
%  cl_arg2l    -> rl_arg2l
%  cl_arg2r    -> rl_arg2r
%  cl_argn     -> rl_argn
%  cl_var      -> rl_var
%  cl_mat      -> rl_mat
%  cl_constr1  -> rl_mk1
%  cl_constr2  -> rl_mk2
%  cl_constrn  -> rl_mkn
%  cl_sconstrn -> rl_smkn
%  cl_constrq  -> rl_mkq
% Renamed the operator test predicates as follows:
%  cl_quantifierp -> cl_quap
%  cl_junctorp    -> cl_junctp
%  cl_basboolopp  -> cl_basbp
%  cl_extboolopp  -> cl_extbp
%  cl_boolopp     -> cl_boolp
%  cl_truthvalp   -> cl_tvalp
%  cl_opp         -> cl_cxp
% Renamed formula test predicates:
%  cl_cop  -> cl_cxfp
%  cl_atp  -> cl_atfp
%  cl_atlp -> cl_atflp
%
% Revision 1.17  1996/03/04 17:00:56  sturm
% Added loading of assist package.
% Changes in module clqe:
% Added black boxes updatr, transform.
% Modified container data structure and added constructors and access
% functions.
% Modified QE code for handling answer transformations.
% Made requantification work.
% Renamed procedure cl_alist!-union to cl_alpunion.
%
% Revision 1.16  1996/03/04 13:08:55  dolzmann
% Added switch !*rlbnfsac.
% Removed switch !*rlbnfsm.
% Addes black boxes sacat, sacatlp, bnfsimpl.
% Added procedures cl_atlp, cl_ncflp, cl_dnfp, cl_cnfp, cl_bnfp.
% Removed treatment of !*rlbnfsb in cl_gdnf.
% Added procedure cl_sac.
%
% Revision 1.15  1996/02/28 13:13:29  sturm
% Major changes in cl_atl. Now available: cl_atl, cl_atl1, cl_atml1.
%
% Revision 1.14  1996/02/26 12:34:43  sturm
% Moved treatment of elimination failures from the black box translat to
% cl_qeatal1.
%
% Revision 1.13  1996/02/18 13:48:47  sturm
% Added theory to black boxes cl_translat and cl_varsel.
% Added black box cl_trygauss.
% Added switch !*rlqegsd and corresonding call to ofsf_gsd in QE, Dirty!
% Removed superfluous scalars from cl_simpl1.
% Major changes in module clqe: Added theory and prepared for quadratic
% elimination.
%
% Revision 1.12  1996/02/18 12:35:28  dolzmann
% Modified cl_gdnf: Turned on !*rlidentify in dependence on !*rlbnfsb.
% Additionally, turned on !*rlsiso then.
%
% Revision 1.11  1995/11/16  08:03:56  sturm
% Added extra parameter to cl_closure, cl_ex, and cl_all.
% Modified module clqe: The all case is handled by explicit negation now.
% Removed module clxr.
%
% Revision 1.10  1995/10/18  08:38:34  sturm
% Added switches rlbnfsb, rlbnfsm, parameter rlsubsumption!*, and
% respective code.
%
% Revision 1.9  1995/09/05  08:02:20  sturm
% Reimplemented parts of smart simplification. Support for switches
% rlsipo, rlsipw; fixed a bug in smart simplification of impl.
%
% Revision 1.8  1995/08/30  07:58:37  sturm
% Added procedure cl_cop.
% Changes in cl_simpl. Added parameter rl_smsimpl!-equiv1!*.
% Renamed scalar help to hlp in cl_setrel for DOS compatibility.
% Renamed procedure cl_qe!-atfal to cl_qeatal.
% Added switch rlqepnf.
% Started reimplementation of tableau methods (not available in AM).
%
% Revision 1.7  1995/08/08  10:12:05  sturm
% Changes in smart simplification: Added treatment of quantifiers,
% atomic formulas, impl, repl, and equiv.
%
% Revision 1.6  1995/08/02  07:42:29  sturm
% Rewritten simplifier.
% Changed copyright messages.
%
% Revision 1.5  1995/07/12  15:02:57  sturm
% Major changes in module clbnf.
% Added parameter function rl_ordatp!*.
% Added identification of atomic formulas to cl_smsimpl.
% Added procedure cl_identifyonoff and changed some local bindings of
% !*rlidentify to applications of on1 and off1.
%
% Revision 1.4  1995/07/07  10:53:13  sturm
% Removed remflag statement for load!-package.
% Removed "_" in switch names, renamed switch rl_smsimpl to rlsism,
% added switch rlqeans.
% Changes cl_qe, added parameter function rl_qemkans!*.
% Changed cl_pnf, its argument formula is now made positive first.
% Removed cl_terpri and cl_prinf.
%
% Revision 1.3  1995/06/21  07:28:56  sturm
% Removed module tri.
% Adapted preceedence of not to REDUCE 3.6.
% Removed declarations of non-used local variables.
% Minor changes in verbosity output of module qe.
% Commented create!-package out.
%
% Revision 1.2  1995/06/01  13:26:41  dolzmann
% Rewritten procedure cl_gand!-col. Renamed switch rl_nocheck to
% rl_sichk with opposite semantic.
% Fixed a bug in cl_nnf1.
%
% Revision 1.1  1995/05/29  14:47:17  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(cl_rcsid!* cl_copyright!*);
   cl_rcsid!* := "$Id: cl.red,v 1.14 2002/08/23 12:32:10 dolzmann Exp $";
   cl_copyright!* := "(c) 1995-1999 A. Dolzmann and T. Sturm"
>>;

module cl;
% Common logic. Generic functions on first order formulas. This module
% contains context independent code possibly addressing some black
% boxes.

create!-package('(cl clsimpl clbnf clnf clqe cltab clmisc),nil);

load!-package 'rltools;

exports cl_atfp,cl_cxfp,cl_atflp,cl_ncflp,cl_dnfp,cl_cnfp,cl_bnfp,cl_simpl,
   cl_sitheo,cl_ordp,cl_smcpknowl,cl_smrmknowl,cl_smupdknowl,cl_smmkatl,
   cl_smsimpl!-impl,cl_smsimpl!-equiv1,cl_siaddatl,cl_susimkatl,cl_susicpknowl,
   cl_susiupdknowl,cl_dnf,cl_cnf,cl_bnf!-cartprod,cl_bnfsimpl,cl_sacatlp,
   cl_sacat,cl_expand!-extbool,cl_nnf,cl_nnfnot,cl_pnf,cl_rename!-vars,cl_fvarl,
   cl_fvarl1,cl_bvarl,cl_bvarl1,cl_varl,cl_varl1,cl_apnf,cl_freevp,cl_tnf,
   cl_gqe,cl_gqea,cl_qe,cl_qea,cl_qeipo,cl_qews,cl_trygauss,cl_specelim,cl_tab,
   cl_atab,cl_itab,cl_gentheo,cl_apply2ats,cl_apply2ats1,cl_apply2ats2,cl_atnum,
   cl_f2ml,cl_atml,cl_atml1,cl_atl,cl_atl1,cl_identifyonoff,cl_ifacml,
   cl_ifacml1,cl_ifacl,cl_ifacl1,cl_matrix,cl_closure,cl_all,cl_ex,cl_flip,
   cl_cflip,cl_subfof,cl_termml,cl_termml1,cl_terml,cl_terml1,cl_struct,
   cl_ifstruct,cl_surep,cl_splt;

imports rltools;

fluid '(cl_identify!-atl!* cl_pal!* cl_lps!* cl_theo!*
   !*rlidentify !*rlsichk !*rlsism !*rlsiexpla !*rlbnfsm !*rlverbose
   !*rlsiidem !*rlsiso !*rlqepnf !*rlqedfs !*rlqeans !*rlqegsd !*rlqeheu
   !*rlqegen !*rlbnfsac !*rltabib !*rltnft !*rlsipw !*rlsipo !*rlqevarsel
   !*rlspgs !*rlsithok !*rlqefb !*rlqelocal);

procedure cl_atfp(x);
   % Common logic atomic formula predicate. [x] is a formula. Returns
   % non-[nil] iff [x] is an atomic formula.
   not rl_cxp rl_op x;

procedure cl_cxfp(x);
   % Common logic complex formula predicate. [x] is a formula. Returns
   % non-[nil] iff [x] is a complex, i.e. non-atomic, formula.
   rl_cxp rl_op x;

procedure cl_atflp(fl);
   % Common logic atomic formula list predicate. [fl] is a list of
   % formulas. Returns [T] or [nil]. [T] is returned if and only if
   % [fl] is a list of atomic formulas.
   null fl or (cl_atfp car fl and cl_atflp cdr fl);

procedure cl_ncflp(fl);
   % Common logic non-complex formula list predicate. [fl] is a list
   % of formulas. Returns [T] or [nil]. [T] is returned if and only if
   % [fl] is a list of atomic formulas and truth values.
   null fl or ((cl_atfp car fl or rl_tvalp car fl) and cl_ncflp cdr fl);

procedure cl_dnfp(f);
   % Common logic disjunctive normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in disjunctive
   % normal form.
   (rl_tvalp f) or (cl_atfp f) or (rl_op f eq 'and and cl_ncflp rl_argn f)
      or ((rl_op f eq 'or) and cl_dnfp1 rl_argn f);

procedure cl_dnfp1(fl);
   % Common logic disjunctive normal form predicate subroutine. [f] is
   % a formula. Returns [T] or [nil].
   (null fl) or ((rl_tvalp car fl) or (cl_atfp car fl) or
      ((rl_op car fl eq 'and) and (cl_ncflp rl_argn car fl))) and
	 (cl_dnfp1 cdr fl);

procedure cl_cnfp(f);
   % Common logic conjunctive normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in conjunctive
   % normal form.
   (rl_tvalp f) or (cl_atfp f) or (rl_op f eq 'or and cl_ncflp rl_argn f)
      or ((rl_op f eq 'and) and cl_cnfp1 rl_argn f);

procedure cl_cnfp1(fl);
   % Common logic conjunctive normal form predicate subroutine . [f]
   % is a formula. Returns [T] or [nil]. [T] is returned iff [f] is in
   % conjunctive normal form.
   (null fl) or ((rl_tvalp car fl) or (cl_atfp car fl) or
      ((rl_op car fl eq 'or) and (cl_ncflp rl_argn car fl))) and
	 (cl_cnfp1 cdr fl);

procedure cl_bnfp(f);
   % Common logic boolean normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in disjunctive
   % or conjunctive normal form.
   (rl_tvalp f) or (cl_atfp f) or (cl_ncflp rl_argn f)
      or ((rl_op f eq 'and) and cl_cnfp1 rl_argn f) or
	 ((rl_op f eq 'or) and cl_dnfp1 rl_argn f);

endmodule;  % [cl]

end;  % of file
