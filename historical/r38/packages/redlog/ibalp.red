% ----------------------------------------------------------------------
% $Id: ibalp.red,v 1.33 2003/09/25 07:47:58 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: ibalp.red,v $
% Revision 1.33  2003/09/25 07:47:58  sturm
% Removed conflicts. Probably no change.
%
% Revision 1.32  2003/09/25 07:30:35  seidl
% Pretty printing for TeXmacs.
%
% Revision 1.31  2003/07/11 17:16:06  sturm
% New service rlqnum (number of quantifiers).
%
% Revision 1.30  2003/06/11 08:45:49  dolzmann
% Added black box rl_qssimpl.
%
% Revision 1.29  2003/06/03 11:19:58  dolzmann
% Removed unused variables from ibalp_simplat1.
% Added black box definitions.
%
% Revision 1.28  2003/05/27 07:32:31  dolzmann
% Added black block implementation for ibalp_qssubat.
%
% Revision 1.27  2003/05/23 16:01:31  dolzmann
% Added implementation of black-box ibalp_qscsaat.
%
% Revision 1.26  2003/05/21 09:05:03  dolzmann
% Added service rlquine.
%
% Revision 1.25  2003/05/03 20:47:36  sturm
% Fixed a bug in ibalp_simpatom.
% Fixed a bug in ibalp_varsel (and the same in ibalp_badvarsel).
%
% Revision 1.24  2003/05/03 18:29:42  sturm
% Implemented an improved ibalp_qevarsel.
% Fixed a bug in ibalp_varlt1 (could not cause wrong results).
%
% Revision 1.23  2003/05/03 16:03:26  sturm
% Implemented procedure ibalp_prepterm.
% Added definition for parameter rl_tordp!*, s.t. service rl_termml!* works.
%
% Revision 1.22  2003/05/03 14:51:53  sturm
% Added development switch ibalpbadvarsel for dual strategy.
%
% Revision 1.21  2003/05/03 14:44:18  sturm
% Added variable selection strategy.
% Added verbose output for case that elimination set contains only one
% variable.
%
% Revision 1.20  2003/05/03 12:33:28  sturm
% Added tableaux methods.
%
% Revision 1.19  2003/05/03 12:07:30  sturm
% Replaced parameter function cl_sacat by ibalp_sacat.
% Made some fluid declarations.
%
% Revision 1.18  2003/05/01 18:56:54  sturm
% Added substitution and Boolean normal forms.
%
% Revision 1.17  2003/05/01 17:22:45  sturm
% Fixed a missing scalar declaration in ibalp_simpterm. This led to
% semantic errors!
%
% Revision 1.16  2003/05/01 08:48:31  sturm
% Rewritten ibalp_simpterm/ibalp_resimpterm.
%
% Revision 1.15  2003/04/25 11:57:17  seidl
% Modified ibalp_simplat1 so it works with smart simplification.
%
% Revision 1.14  2003/04/24 17:20:47  sturm
% Fixed procedures ibalp_simpterm, ibalp_resimpterm, etc.
% Added procedure ibalp_opp.
% Added procedure ibalp_ordatp.
%
% Revision 1.13  2003/04/24 16:32:07  seidl
% Smart simplification now available, rlsism is on now by default.
% Changed ibalp_ordatp; still we need a better predicate, one which
% sorts in addition by variable name (this is needed for commutative
% law).
%
% Revision 1.12  2003/04/23 11:02:40  sturm
% Rewritten ibalp_negateat.
% Provided rlqea.
%
% Revision 1.11  2003/04/17 16:52:47  seidl
% Added ibalp_termmlat and declared various services.
%
% Revision 1.10  2003/04/17 15:22:31  sturm
% Fixed bugs in QE code.
% Added services rl_ex!* and rl_all!*.
%
% Revision 1.9  2003/04/17 14:48:02  seidl
% Removed bug from ibalp_varlt1.
%
% Revision 1.8  2003/04/17 13:34:52  sturm
% Quantifier elimination should work.
%
% Revision 1.7  2003/04/17 12:13:32  seidl
% After simplification, atoms are of the form a=1 or a=0 now, and NNF works
% as it should, i.e. there is no "not" in the result.
%
% Revision 1.6  2003/04/15 14:02:17  seidl
% Simplified result has now always atoms of the form a=1. This is needed
% for rlpcprint.
%
% Revision 1.5  2003/04/10 18:34:22  seidl
% Changed <=>, =>, <= to <->, ->, <- to avoid conflict with lessequal.
% Simplification (including term expansion) implemented. Modified
% ibalp_negateat, added ibalb_flip01, ibalp_simplat1 ibalp_term2fo and
% ibalp_ordatp.
%
% Revision 1.4  2003/03/27 13:12:03  sturm
% Clean treatment of static case sensitivity.
%
% Revision 1.3  2003/03/27 12:53:10  sturm
% Fixed a buig in ibalp_priequal.
%
% Revision 1.2  2003/03/27 12:38:41  sturm
% Implemented printing for bnot.
% Added procedures ibalp_upcase, ibalp_downcase, ibalp_uppercasep.
% Added procedures ibalp_pcvar,ibalp_pcvarp.
% Implemented rlpcvar, which is stat rlis, i.e., has sytax like e.g. "tr".
%
% Revision 1.1  2003/03/26 18:20:44  seidl
% Initail check-in. Syntax works.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ibalp_rcsid!* ibalp_copyright!*);
   ibalp_rcsid!* := "$Id: ibalp.red,v 1.33 2003/09/25 07:47:58 sturm Exp $";
   ibalp_copyright!* :=
      "Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module ibalp;
% Initial Boolean Algebra Lisp Prefix Form. Provides for
% Propositional Logic as well.

off raise;  % static case sensitivity for compilation

create!-package('(ibalp),nil);

load!-package 'cl;
load!-package 'rltools;

imports rltools,cl;

fluid '(!*rlverbose !*rlbnfsac !*rlpcprint !*rlsiso);

flag('(ibalp),'rl_package);

% Switches
switch rlpcprint;

% Parameters
put('ibalp,'rl_params,'(
   (rl_tordp!* . ibalp_ordp)
   (rl_a2cdl!* . ibalp_a2cdl)
   (rl_subsumption!* . ibalp_subsumption)
   (rl_bnfsimpl!* . cl_bnfsimpl)
   (rl_sacatlp!* . cl_sacatlp)
   (rl_sacat!* . ibalp_sacat)
   (rl_subat!* . ibalp_subat)
   (rl_subalchk!* . ibalp_subalchk)
   (rl_eqnrhskernels!* . ibalp_eqnrhskernels)
   (rl_smupdknowl!* . cl_smupdknowl)
   (rl_smrmknowl!* . cl_smrmknowl)
   (rl_smcpknowl!* . cl_smcpknowl)
   (rl_smmkatl!* . cl_smmkatl)
   (rl_smsimpl!-impl!* . cl_smsimpl!-impl)
   (rl_smsimpl!-equiv1!* . cl_smsimpl!-equiv1)
   (rl_elimset!* . ibalp_elimset)
   (rl_translat!* . ibalp_translat)
   (rl_varsel!* . ibalp_varsel)
   (rl_transform!* . ibalp_transform)
   (rl_trygauss!* . ibalp_trygauss)
   (rl_specelim!* . ibalp_specelim)
   (rl_simplat1!* . ibalp_simplat1)
   (rl_ordatp!* . ibalp_ordatp)
   (rl_termmlat!* . ibalp_termmlat)
   (rl_op!* . ibalp_op) 
   (rl_varsubstat!* . ibalp_substat) 
   (rl_negateat!* . ibalp_negateat) 
   (rl_qemkans!* . ibalp_qemkans)
   (rl_varlat!* . ibalp_varlat)
   (rl_qstrycons!* . cl_qstrycons)
   (rl_qscsaat!* . ibalp_qscsaat)
   (rl_qssubat!* . ibalp_qssubat)
   (rl_qsconsens!* . cl_qs1consens)
   (rl_qsimpltestccl!* . cl_qsimpltestccl)
   (rl_qssubsumep!* . cl_qssusubymem)
   (rl_qstautp!* . cl_qstautp)
   (rl_qssimpl!* . cl_qssibysimpl)
));

% Services
put('ibalp,'rl_services,'(
   (rl_tab!* . cl_tab)
   (rl_atab!* . ibalp_atab)
   (rl_itab!* . ibalp_itab)
   (rl_cnf!* . ibalp_cnf)
   (rl_dnf!* . ibalp_dnf)
   (rl_subfof!* . cl_subfof)
   (rl_identifyonoff!* . cl_identifyonoff)
   (rl_ex!* . cl_ex)
   (rl_all!* . cl_all)
   (rl_simpl!* . cl_simpl)
   (rl_atnum!* . cl_atnum)
   (rl_qnum!* . cl_qnum)
   (rl_matrix!* . cl_matrix)
   (rl_atl!* . cl_atl)
   (rl_atml!* . cl_atml)
   (rl_pnf!* . cl_pnf)
   (rl_nnf!* . cl_nnf)
   (rl_nnfnot!* . cl_nnfnot) % not available in algebraic mode
   (rl_termml!* . cl_termml)
   (rl_terml!* . cl_terml)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_quine!* . cl_quine) 
   (rl_qe!* . cl_qe)
   (rl_qea!* . cl_qea)));

% Switches
put('ibalp,'rl_cswitches,'(
   (rlsism . t)
   (raise . nil)));

% Admin
put('ibalp,'simpfnname,'ibalp_simpfn);

put('ibalp,'rl_prepat,'ibalp_prepat);
put('ibalp,'rl_resimpat,'ibalp_resimpat);
put('ibalp,'rl_lengthat,'ibalp_lengthat);

put('ibalp,'rl_prepterm,'ibalp_prepterm);
put('ibalp,'rl_simpterm,'ibalp_simpterm);

algebraic infix equal;
put('equal,'prifn,'ibalp_priequal);
put('equal,'fancy!-prifn,'ibalp_fancy!-priequal);
put('equal,'ibalp_simpfn,'ibalp_simpat);
put('equal,'fancy!-prifn,'ibalp_fancy!-priequal);
put('equal,'number!-of!-args,2);

procedure ibalp_priequal(f);
   % Print equal. [f] is of the form $([equal] s t)$. Returns in
   % identifier. Provided that switches [nat] and [rlpcprint] are on:
   % If $s$ is and identifier and the corresponding uppercase
   % identifier is $S$ is a PC variable, then print $S$. Else returns
   % ['failed] and leave printing to [maprin].
   begin scalar w,rhs;
      f := reval f;
      if not !*nat or not !*rlpcprint then
      	 return 'failed;
      rhs := caddr f;
      if not eqn(rhs,1) and not eqn(rhs,0) then
	 return 'failed;
      w := cadr f;
      if not idp w then
	 return 'failed;
      w := ibalp_upcase w;
      if not ibalp_pcvarp w then
	 return 'failed;
      if eqn(rhs,0) then
	 prin2!* "not(";
      prin2!* w;
      if eqn(rhs,0) then
	 prin2!* ")"
   end;

procedure ibalp_fancy!-priequal(c);
   begin scalar w,rhs;
      c := reval c;
      rhs := caddr c;
      if not !*nat or not !*rlpcprint or not (eqn(rhs,1) or eqn(rhs,0)) then <<
	 maprin cadr c;
	 fancy!-prin2 "=";
	 maprin rhs;
	 return ;
      >>;
      %if not eqn(rhs,1) and not eqn(rhs,0) then return 'failed;
      w := cadr c;
      if not idp w then
	 return 'failed;
      w := ibalp_upcase w;
      if not ibalp_pcvarp w then
	 return 'failed;
      if caddr c eq 0 then fancy!-prin2 "\overline{";
      fancy!-prin2 w;
      if caddr c eq 0 then fancy!-prin2 "}"
   end;

algebraic infix neq;
put('neq,'ibalp_simpfn,'ibalp_simpat);
put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq);

algebraic operator bnot;
put('bnot,'number!-of!-args,1);
put('bnot,'prifn,'ibalp_pribnot);
put('bnot,'fancy!-prifn,'pasf_fancy!-pribnot);
newtok '((!~) bnot);

procedure ibalp_pribnot(u);
   <<
      prin2!* " ";
      prin2!* get(car u,'prtch);
      prin2!* " ";
      if pairp cadr u and get(caadr u,'infix) then <<
	 prin2!* "(";
	 maprin cadr u;
	 prin2!* ")"
      >> else
      	 maprin cadr u
   >>;

symbolic procedure pasf_fancy!-pribnot(u);
   <<
      fancy!-prin2 "(";
      fancy!-prin2 "\~{}"; % \char126
      maprin cadr u;
      fancy!-prin2 ")";
   >>;

algebraic infix bequiv;
put('bequiv,'number!-of!-args,2);
put('bequiv,'fancy!-prifn,'pasf_fancy!-pribequiv);
newtok '((!< !- !>) bequiv);
put('bequiv,'fancy!-infix!-symbol,"\leftrightarrow ");
precedence bequiv,neq;

symbolic procedure pasf_fancy!-pribequiv(u);
   <<
      fancy!-prin2 "(";
      maprin cadr u;
      fancy!-prin2 "\leftrightarrow{}";
      maprin caddr u;
      fancy!-prin2 ")";
   >>;

algebraic infix bimpl;
put('bimpl,'number!-of!-args,2);
put('bimpl,'fancy!-prifn,'pasf_fancy!-pribimpl);
newtok '((!- !>) bimpl);
put('bimpl,'fancy!-infix!-symbol,"\rightarrow ");
precedence bimpl,bequiv;

symbolic procedure pasf_fancy!-pribimpl(u);
   <<
      fancy!-prin2 "(";
      maprin cadr u;
      fancy!-prin2 "\rightarrow{}";
      maprin caddr u;
      fancy!-prin2 ")";
   >>;

algebraic infix brepl;
put('brepl,'number!-of!-args,2);
put('brepl,'fancy!-prifn,'pasf_fancy!-pribrepl);
newtok '((!< !-) brepl);
put('brepl,'fancy!-infix!-symbol,"\leftarrow");
precedence brepl,bimpl;

symbolic procedure pasf_fancy!-pribrepl(u);
   <<
      fancy!-prin2 "(";
      maprin cadr u;
      fancy!-prin2 "\leftarrow{}";
      maprin caddr u;
      fancy!-prin2 ")";
   >>;

algebraic infix bor;
flag('(bor),'nary);
put('bor,'fancy!-prifn,'pasf_fancy!-pribor);
newtok '((!|) bor);
put('bor,'fancy!-infix!-symbol,"\|");
precedence bor,bimpl;

symbolic procedure pasf_fancy!-pribor(u);
   begin scalar w;
      fancy!-prin2 "(";
      w := cdr u; % the arguments
      maprin car w;
      w := cdr w;
      while w do <<
	 fancy!-prin2 "|";
	 maprin car w;
	 w := cdr w;
      >>;
      fancy!-prin2 ")";
   end;

algebraic infix band;
flag('(band),'nary);
put('band,'fancy!-prifn,'pasf_fancy!-priband);
newtok '((!&) band);
put('band,'fancy!-infix!-symbol,"\&");
precedence band,bor;

symbolic procedure pasf_fancy!-priband(u);
   begin scalar w;
      fancy!-prin2 "(";
      w := cdr u; % the arguments
      maprin car w;
      w := cdr w;
      while w do <<
	 fancy!-prin2 "\&{}";
	 maprin car w;
	 w := cdr w;
      >>;
      fancy!-prin2 ")";
   end;

flag('(band bor bimpl brepl bequiv equal neq),'spaced);

flag('(ibalp_simpat),'full);

flag('(ibalp_pcstat),'endstatfn);

procedure ibalp_pcstat();
   begin scalar x;
      x := cursym!*;
      scan();
      return {x}
   end;

procedure ibalp_pcform(form,an!-empty!-al,mode);
   if mode eq 'symbolic then
      mkquote intern car form  % we mean the identifier then
   else  % we know [mode eq 'algebraic]
      mkquote {'equal,ibalp_downcase car form,1};

put('rlpcvar,'stat,'rlis);
put('rlpcvar,'formfn,'ibalp_pcvarform);

procedure ibalp_pcvarform(vl,an!-empty!-al,mode);
   <<
      ibalp_pcvar for each v in cdr vl join <<
      	 if pairp v and ibalp_pcvarp car v then <<
	    lprim {"ignoring",car v,"- already declared pcvar"};
	    nil
      	 >> else if not ibalp_uppercasep v then <<
	    lprim{"ignoring",v,"- not an uppercase identifier"};
	    nil
      	 >> else
	    {v}
      >>;
      mkquote nil
   >>;

procedure ibalp_pcvar(vl);
   for each v in vl do <<
      put(v,'stat,'ibalp_pcstat);
      put(v,'formfn,'ibalp_pcform)
   >>;

procedure ibalp_uppercasep(id);
   id = ibalp_upcase id;

procedure ibalp_pcvarp(id);
   get(id,'stat) eq 'ibalp_pcstat;

procedure ibalp_upcase(id);
   intern compress for each c in explode id collect red!-char!-upcase c;

procedure ibalp_downcase(id);
   intern compress for each c in explode id collect red!-char!-downcase c;

ibalp_pcvar '(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z);

procedure ibalp_subat(al,at);
   ibalp_mk2(ibalp_op at,
      ibalp_subt(al,ibalp_arg2l at),ibalp_subt(al,ibalp_arg2r at));

procedure ibalp_subt(al,u);
   begin scalar w;
      if idp u and (w := atsoc(u,al)) then
      	 return cdr w;
      if atom u then
      	 return u;
      return car u . for each arg in cdr u collect ibalp_subt(al,arg)
   end;

procedure ibalp_subalchk(al);
   ;

procedure ibalp_eqnrhskernels(x);
   ibalp_varlt cdr x;

procedure ibalp_simpterm(u);
   % Simplify term. [u] is Lisp Prefix. Returns the [u] as a IBALP
   % term.
   begin scalar op;
      if atom u then
      	 return ibalp_simpatom u;
      op := car u;
      if ibalp_boolfp op then
 	 return op . for each arg in cdr u collect ibalp_simpterm arg;
      u := reval u;
      if eqcar(u,op) then
	 typerr(op,"Boolean function");
      return ibalp_simpterm u  % terminates because reval is idempotent
   end;

procedure ibalp_simpatom(u);
   begin scalar w;
      if u = 0 or u = 1 then
	 return u;
      if idp u then <<
      	 if (w := rl_gettype u) then
	    return ibalp_simpterm reval u;
	 flag({u},'used!*);
	 return u
      >>;
      if null u then
	 typerr("nil","Boolean term");
      if numberp u then
 	 typerr({"number",u},"Boolean term");
      if stringp u then
 	 typerr({"string",u},"Boolean term")
   end;

procedure ibalp_prepterm(u);
   u;

procedure ibalp_boolfp(op);
   op memq '(bnot band bor bimpl brepl bequiv);

procedure ibalp_resimpterm(u);
   ibalp_simpterm u;

procedure ibalp_prepat(f);
   % Prep atomic formula. [f] is a IBALP atomic formula. Returns [f]
   % in Lisp prefix form.
   f;
   
procedure ibalp_resimpat(f);
   % Resimp atomic formula. [f] is an IBALP atomic formula. Returns the
   % atomic formula [f] with resimplified terms.
   ibalp_mk2(ibalp_op f,ibalp_resimpterm ibalp_arg2l f,
      ibalp_resimpterm ibalp_arg2r f);

procedure ibalp_lengthat(f);
   % Length of atomic formula. [f] is an
   % atomic formula. Returns a number, the length of [f].
   length ibalp_argn f;

procedure ibalp_simpat(u);
   % Simp atomic formula. [u] is Lisp prefix. Returns [u] as an atomic
   % formula.
   ibalp_mk2(car u,ibalp_simpterm cadr u,ibalp_simpterm caddr u);

procedure ibalp_op(atf);
   % Get operator. [atf] is an atomic formula $(R,t_1,t_2)$. Returns
   % $R$ which is $=$.
   car atf;

procedure ibalp_atfp(f);
   % Atomic formula predicate. [f] is a
   % formula. Returns t is and only if [f] is an atomic formula.
   ibalp_op f memq '(equal neq); 

procedure ibalp_arg1(atf);
   % Unary operator argument. [atf] is an atomic formula $R(t)$.
   % Returns $t$.
   cadr atf;

procedure ibalp_arg2l(atf);
   % Binary operator left hand side argument. [atf] is an atomic
   % formula $R(t_1,t_2)$. Returns $t_1$.
   cadr atf;

procedure ibalp_arg2r(atf);
   % Binary operator right hand side argument. [atf] is an atomic
   % formula $R(t_1,t_2)$. Returns $t_2$.
   caddr atf;

procedure ibalp_argn(atf);
   % n-ary operator argument list. [atf] is an atomic formula
   % $(R,t_1,...,t_n)$. Returns the list $(t_1,...,t_n)$.
   cdr atf;

procedure ibalp_mk2(op,lhs,rhs);
   % Make atomic formula for binary operator. [op] is one of the
   % operators [equal], [neq]; [lhs] and [rhs] are terms. Returns the
   % atomic formula $[op]([lhs],[rhs])$.
   {op,lhs,rhs};

procedure ibalp_1mk2(op,lhs);
   % Make zero right hand atomic formula for binary operator. [op] is
   % the operator [equal]. Returns the atomic formula $[op]([lhs],0)$.
   {op,lhs,1};

procedure ibalp_mkn(op,argl);
   % Make atomic formula for n-ary operator. [op] is one of the
   % operators [equal], [neq]; [argl] is a list $(t_1,t_2)$ of terms.
   % Returns the atomic formula $(op,t_1,t_2)$.
   op . argl;

%%% --- this part might become ibalpbnf.red --- %%%

procedure ibalp_dnf(f);
   % Disjunctive normal form. [f] is a formula. Returns a DNF of [f].
   if !*rlbnfsac then
      (cl_dnf f) where !*rlsiso=t
   else
      cl_dnf f;

procedure ibalp_cnf(f);
   % Conjunctive normal form. % [f] is a formula. Returns a CNF of
   % [f].
   if !*rlbnfsac then
      (cl_cnf f) where !*rlsiso=t
   else
      cl_cnf f;

procedure ibalp_subsumption(l1,l2,gor);
   % Discretely valued field standard form subsume. [l1] and [l2] are
   % lists of atomic formulas. Returns one of [keep1], [keep2], [nil].
   if gor eq 'or then (
      if ibalp_subsumep!-and(l1,l2) then
 	 'keep2
      else if ibalp_subsumep!-and(l2,l1) then
	 'keep1
   ) else  % [gor eq 'and]
      if ibalp_subsumep!-or(l1,l2) then
	 'keep1
      else if ibalp_subsumep!-or(l2,l1) then
	 'keep2
      else
	 nil;

procedure ibalp_subsumep!-and(l1,l2);
   % Subsume [and] case. [l1] and [l2] are lists of atomic formulas.
   begin scalar a;
      while l2 do <<
	 a := car l2;
	 l2 := cdr l2;
	 if cl_simpl(a,l1,-1) neq 'true then a := l2 := nil
      >>;
      return a
   end;

procedure ibalp_subsumep!-or(l1,l2);
   % Subsume [or] case. [l1] and [l2] are lists of atomic formulas.
   begin scalar a;
      while l1 do <<
	 a := car l1;
	 l1 := cdr l1;
	 if cl_simpl(rl_smkn('or,l2),{a},-1) neq 'true then a := l1 := nil
      >>;
      return a
   end;

procedure ibalp_sacat(a1,a2,gor);
   % Subsume and cut atomic formula. [a1] and [a2] are atomic
   % formulas; [gor] is one of [or], [and]. Returns [nil], ['keep],
   % ['keep2], ['keep1], ['drop], or an atomic formula. If [nil] is
   % returned then neither a cut nor a subsumption can be applied, if
   % [keep] is returned then the atomic formulas are identical, in the
   % case of [keep1] or [keep2] the respective atomic formula must be
   % kept but the other can be dropped. If an atomic formula $a$ is
   % returned then it is the result of the cut beween [a1] and [a2],
   % if ['drop] is returned, a cut with result ['true] or ['false] can
   % be performed.
   begin scalar rhs1,rhs2;
      if ibalp_arg2l a1 neq ibalp_arg2l a2 then
	 return nil;
      rhs1 := ibalp_arg2r a1;
      rhs2 := ibalp_arg2r a2;
      if rhs1 = rhs2 then
	 return 'keep;
      if rhs1 = 0 and rhs2 = 1 or rhs1 = 1 and rhs2 = 0 then
	 return 'drop;
      return nil
   end;

%%% --- this part might become ibalpmisc.red --- %%%

procedure ibalp_atab(f);
   cl_atab cl_simpl(f,nil,-1);

procedure ibalp_itab(f);
   cl_itab cl_simpl(f,nil,-1);

procedure ibalp_a2cdl(atml);
   % Atomic to case distinction list. [atml] is a list of atomic
   % formulas with multiplicity, the right hand side of which is
   % always zero. Returns a list, each containing a list of case
   % distinction w.r.t. the term $t$, i.e. ${t<0,t=0,t>0}$ resp.
   % ${t=0,t neq 0}$.
   for each pr in atml collect
      {ibalp_mk2('equal,w,0),ibalp_mk2('equal,w,1)} where w=ibalp_arg2l car pr;

procedure ibalp_substat(atf,new,old);
   % Substitute into atomic formula. [atf] is an atomic formula; [old]
   % is a variable; [new] is a term.
   ibalp_mk2(ibalp_op atf,ibalp_qesubt(ibalp_arg2l atf,old,new),
      ibalp_qesubt(ibalp_arg2r atf,old,new));

procedure ibalp_ordatp(a1,a2);
   % Ordered atomic formula predicate. [a1] and [a2] are atomic
   % formulas. Returns [t] iff [a1] is less than [a2].
   begin scalar u1,u2;
      u1 := ibalp_arg2l a1;
      u2 := ibalp_arg2l a2;
      if u1 neq u2 then return ibalp_ordp(u1,u2);
      u1 := ibalp_arg2r a1;
      u2 := ibalp_arg2r a2;
      if u1 neq u2 then return ibalp_ordp(u1,u2);
      return ibalp_ordrelp(ibalp_op a1,ibalp_op a2)
   end;

procedure ibalp_ordp(u1,u2);
   ordp(!*k2f u1,!*k2f u2);

procedure ibalp_ordrelp(r1,r2);
   not not (r2 memq (r1 memq '(equal neq)));

procedure ibalp_negateat(atf);
   % Negate atomic formula. [atf] is an atomic formula.
   % Returns an atomic formula equivalent to $\lnot [atf]$.
   ibalp_mk2(ibalp_op atf,ibalp_arg2l atf,ibalp_negatet ibalp_arg2r atf);

procedure ibalp_negatet(u);
   if u = 0 then 1 else if u = 1 then 0 else {'bnot,u};

procedure seidl_negateat(atf);
   % Negate atomic formula. [atf] is an atomic formula.
   % Returns an atomic formula equivalent to $\lnot [atf]$. The
   % relation is left unchanged, and ibalb_cveq relies on this.
   begin scalar lhs,rhs,rel,op;
      rhs := ibalp_arg2r atf;
      lhs := ibalp_arg2l atf;
      rel := ibalp_op atf;
      % flip 0 and 1, if possible
      if rhs member {0,1} then
	 return ibalp_mk2(rel,lhs,ibalp_flip01 rhs);
      if lhs member {0,1} then
      	 return ibalp_mk2(rel,ibalp_flip01 lhs,rhs);
      % drop a bnot, if possible
      op := ibalp_op rhs;
      if op equal 'bnot then
	 return ibalp_mk2(rel,lhs,ibalp_arg1 rhs);
      op := ibalp_op lhs;
      if op equal 'bnot then
	 return ibalp_mk2(rel,ibalp_arg1 lhs,rhs);
      % otherwise: negate left side
      return ibalp_mk2(rel,ibalp_mk1('bnot,rhs),rhs);
   end;

procedure ibalp_flip01(n);
   if n = 1 then 0 else if n = 0 then 1 else
      rederr{"ibalb_flip01: cannot flip",n};

procedure ibalp_cveq(a);
   % Convert to equation. [a] is an atom. Returns an atom.
   if ibalp_op a eq 'equal then
      a
   else
      ibalp_mk2('equal,ibalp_arg2l w,ibalp_arg2r w)
	 where w=ibalp_negateat(a);

procedure ibalp_termmlat(at);
   % Term multiplicity list of atomic formula. [at] is an atomic
   % formula. Returns the multiplicity list off all non-zero terms in
   % [at].
   begin scalar lhs,rhs;
      lhs := ibalp_arg2l at;
      rhs := ibalp_arg2r at;
      if lhs = 0 and rhs = 0 then return nil;
      if lhs = 0 then return {rhs . 1};
      if rhs = 0 then return {lhs . 1};
      if lhs = rhs then return {lhs . 2};
      return {lhs . 1,rhs . 1}
   end;
      
%(rl_varlat!* . ibalp_varlat))); %%% needs to be written in ibalpmisc.red

%%% --- this part might become ibalpsiat.red --- %%%

procedure ibalp_simplat1(f,sop);
   % Simplify atomic formula. [f] is an atomic formula; [sop] is the
   % boolean operator [f] occurs with or [nil]. Maybe later: accesses
   % switches [rlsiatadv], [rlsipd], [rlsiexpl], and [rlsiexpla].
   % Returns a quantifier-free formula that is a simplified equivalent
   % of [f].
   begin scalar lhs,rhs;
      if not (ibalp_op f memq '(equal neq)) then return nil; % why not error?
      % left-hand side domain element: switch sides for pcprint
      lhs := ibalp_arg2l f;
      rhs := ibalp_arg2r f;
      if numberp lhs then f := ibalp_mk2(ibalp_op f,rhs,lhs);
      f := ibalp_cveq f;
      % from now on, we have an equation
      lhs := ibalp_arg2l f;
      rhs := ibalp_arg2r f;
      % two numbers
      if numberp lhs and numberp rhs then
	 return if lhs eq rhs then 'true else 'false;
      % if we have a "propositional variable", we're done:
      if idp lhs and numberp rhs then return f;
      % from now on we have a complex term (longer than a "propositional
      % variable") to expand, and to simplify.
      lhs := ibalp_term2fo lhs;
      rhs := ibalp_term2fo rhs;
      return cl_simpl(cl_nnf rl_mk2('equiv,lhs,rhs),nil,-1)
   end;

procedure ibalp_term2fo(term);
   % Convert term to Formula. [term] is a lisp-prefix expression over
   % the language of initial boolean algebras. Returns a formula, with
   % atoms being only of the form [a=1].
   begin scalar rel;
      if numberp term then return if term = 0 then 'false else 'true;
      if idp term then return ibalp_mk2('equal,term,1);
      rel := ibalp_op(term);
      if rel eq 'bnot then return rl_mk1('not,ibalp_term2fo ibalp_arg1 term);
      if rel eq 'band then return
	 rl_mkn('and,for each a in ibalp_argn term collect
	    ibalp_term2fo a);      
      if rel eq 'bor then return
	 rl_mkn('or,for each a in ibalp_argn term collect
	    ibalp_term2fo a);      
      if rel eq 'bimpl then return rl_mk2('impl,ibalp_term2fo ibalp_arg2l term,
	 ibalp_term2fo ibalp_arg2r term);
      if rel eq 'brepl then return rl_mk2('repl,ibalp_term2fo ibalp_arg2l term,
	 ibalp_term2fo ibalp_arg2r term);
      if rel eq 'bequiv then return rl_mk2('equiv,
	 ibalp_term2fo ibalp_arg2l term, ibalp_term2fo ibalp_arg2r term);
      rederr {"ibalp_term2fo: unknown symbol:",rel}
   end;

procedure ibalp_varlat(a);
   % Variable list atomic formlua. [a] is an atomic formula. Returns a
   % list of identifiers. The set of variables ocurring in [a].
   union(ibalp_varlt ibalp_arg2l a,ibalp_varlt ibalp_arg2r a);

procedure ibalp_varlt(u);
   % Variable list term. [u] is an IBALP term. Returns a list of
   % identifiers. The set of variables ocurring in [u].
   ibalp_varlt1(u,nil);

procedure ibalp_varlt1(u,vl);
   % Variable list term. [u] is an IBALP term; [vl] is a list of
   % identifiers. Returns a list of identifiers. The set of variables
   % ocurring in [u] added to [vl].
   begin
      if u = 0 or u = 1 then
	 return nil;
      if idp u then
      	 return lto_insertq(u,vl);
      for each arg in ibalp_argn u do
      	 vl := ibalp_varlt1(arg,vl);
      return vl
   end;

procedure ibalp_transform(f,v);
   % Transform formula. [f] is a quantifier-free formula; [v] is a
   % variable. Returns $([f] . nil)$. This behavior informs [cl_qe]
   % that there no transformation possible.
   f . nil;

procedure ibalp_trygauss(f,v);
   % Try Gauss. [f] is a quantifier-free formula; [v] is a variable.
   % Returns [failed]. This behavior informs [cl_qe] that there no
   % Gauss elimination possible.
   'failed;

procedure ibalp_specelim(f,vl,theo,ans,bvl);
   % Special elimination. [f] is a quantifier-free formula; [vl] is a
   % list of variables; [theo] is a theory; [ans] is Bool; [bvl] is
   % the list of bound variables. Returns [failed]. This behavior
   % informs [cl_qe] that there no special elimination possible.
   'failed;

switch ibalpbadvarsel;

procedure ibalp_varsel(f,vl,theo);
   % Variable selection. [vl] is a list of variables; [f] is a
   % quantifier-free formula; [theo] is the current theory. Returns a
   % variable.
   begin scalar v; integer n;
      if not !*rlqevarsel then
 	 return car sort(vl,'ibalp_ordp);
      if !*ibalpbadvarsel then
	 return ibalp_badvarsel(f,vl);
      for each pr in cl_termml f do
	 if car pr memq vl and cdr pr > n then <<
	    v := car pr;
	    n := cdr pr
	 >>;
      return v or car sort(vl,'ibalp_ordp)
   end;

procedure ibalp_badvarsel(f,vl);
   begin scalar v; integer n;
      for each pr in cl_termml f do
	 if car pr memq vl and - cdr pr < n then <<
	    v := car pr;
	    n := cdr pr
	 >>;
      return v or car sort(vl,'ibalp_ordp)
   end;
      
%
% procedure ibalp_varsel(f,vl,theo);
%    % Variable selection. [vl] is a list of variables; [f] is a
%    % quantifier-free formula; [theo] is the current theory. Returns a
%    % variable.
%    begin scalar v,found,gvp;
%       if not !*rlqevarsel then
% 	 return car vl;
%       while reverse vl and not found do <<
% 	 v := car vl;
% 	 vl := cdr vl;
% 	 gvp := not ibalp_goodvarp(f,v,{0,1});  % good var is bad var once more
% 	 if !*ibalpbadvarsel then
% 	    gvp := not gvp;
% 	 if gvp then  
% 	    found := t
%       >>;
%       return v
%    end;

% procedure ibalp_goodvarp(f,v,l);
%    begin scalar argl;
%       if rl_cxp rl_op f then <<
% 	 argl := rl_argn f;
% 	 while argl and l do <<
% 	    l := ibalp_goodvarp(car argl,v,l);
% 	    argl := cdr argl
% 	 >>;
% 	 return l
%       >>;
%       if ibalp_arg2l f eq v then
% 	 return deletip(ibalp_arg2r f,l);
%       return l
%    end;
	 
procedure ibalp_translat(atf,v,theo,pos,ans);
   % Translate atomic formula. [atf] is an atomic formula $\rho(t,0)$;
   % [v] is a variable; [theo] is the current theory; [pos], [ans] are
   % Bool. Returns an ALP.
   if ibalp_arg2l atf neq v then
      nil . nil
   else if pos then
      ibalp_mkalp('equal,{ibalp_arg2r atf})
   else if ibalp_arg2r atf = 1 then
      ibalp_mkalp('equal,{0})
   else
      ibalp_mkalp('equal,{1});

procedure ibalp_mkalp(tag,l);
   % Make alist pair. [tag] is a key; [l] is an entry. Returns an ALP.
   {tag . l} . {tag . 1};

%DS elimination_set
% A list $(...,(p . (l_1,...,l_n)),...)$ where the $p$ are procedures
% and the $l_i$ are parameter lists $(l_{i1},...,l_{im})$ such that
% there is $p(bvl,theo,f,v,l_{i1},...,l_{im})$ called for
% substitution, where $f$ is the considered formula, and $v$ the
% considered variable.

procedure ibalp_elimset(v,alp);
   % Elimination set. [v] is a variable; [alp] is a pair of alists.
   % Returns an elimination set.
   <<
      if !*rlverbose and not cdr cdaar alp then
      	 ioto_prin2 "S";
      {'ibalp_qesub . for each bconst in cdaar alp collect {bconst}}
   >>;

procedure ibalp_qesub(bvl,theo,f,v,bconst);
   theo . cl_apply2ats1(f,'ibalp_qesubat,{v,bconst});

procedure ibalp_qesubat(atf,v,bconst);
   ibalp_mk2(ibalp_op atf,
      ibalp_qesubt(ibalp_arg2l atf,v,bconst),ibalp_arg2r atf);

procedure ibalp_qesubt(u,v,bconst);
   if u eq v then
      bconst
   else if atom u then
      u
   else
      car u . for each arg in cdr u collect ibalp_qesubt(arg,v,bconst);

procedure ibalp_qemkans(an,atr);
   sort(for each x in an collect {'equal,car x,car caddr x},
      function(lambda(x,y); ordp(!*k2f cadr x,!*k2f cadr y)));

procedure ibalp_qscsaat(at);
   if not(idp ibalp_arg2l at and ibalp_arg2r at memq '(1 0)) then
      rederr {"ibalp_qscsaat: cannot process",at}
   else
      (ibalp_arg2l at . ibalp_arg2r at );

procedure ibalp_qssubat(pl,at);
   begin scalar w;
      if not(idp ibalp_arg2l at and ibalp_arg2r at memq '(1 0)) then
      	 rederr {"ibalp_qssubat: cannot process",at};
      w := assoc(ibalp_arg2l at,pl);
      if w then
	 return ibalp_mk2(ibalp_op at,cdr w,ibalp_arg2r at);
      return at
   end;

on raise;  % static case sensitivity was for compilation only

endmodule;  % [ibalp]

end;  % of file
