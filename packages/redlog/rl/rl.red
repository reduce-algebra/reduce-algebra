% ----------------------------------------------------------------------
% $Id: rl.red,v 1.15 1997/08/12 17:03:51 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995, 1996
% Andreas Dolzmann and Thomas Sturm, Universitaet Passau
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

% $Log: rl.red,v $
% Revision 1.15  1997/08/12 17:03:51  sturm
% Fixed fancy printing for Xr and PC versions.
%
% Revision 1.14  1996/10/23 11:28:08  dolzmann
% Added switch rlqevarsel and corresponding code.
%
% Revision 1.13  1996/10/20 15:55:07  sturm
% Added switches rlnzden, rlposden, and rladdcond and corresponding code
% handling the input of reciprocal terms.
%
% Revision 1.12  1996/10/08 13:54:52  dolzmann
% Renamed "degree parity decomposition" to "parity decomposition".
% Adapted names of procedures and switches accordingly.
%
% Revision 1.11  1996/10/08 13:01:26  dolzmann
% Removed switch rltabcb.
%
% Revision 1.10  1996/10/01 10:25:17  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.9  1996/09/29 14:21:25  sturm
% Removed switch rlqeans. Introduced service rlqea instead.
% Also introduced corresponding service rlgqea.
%
% Revision 1.8  1996/09/05 11:16:37  dolzmann
% Introduced new switch !*rlqegenct.
% Turned on rlsiexpla by default.
% Introduced property cleanupfn on the internal service procedure identifier.
%
% Revision 1.7  1996/07/13 11:22:22  dolzmann
% Introduced new switches rlgsbnf and rlgsutord with default values.
%
% Revision 1.6  1996/07/08 07:18:42  sturm
% ex, all, and !*fof are no longer operators. Consequently, the number
% of arguments of ex and all is checked now.
%
% Revision 1.5  1996/07/02 15:12:21  sturm
% Fixed a bug in length computation.
%
% Revision 1.4  1996/06/24 09:11:44  sturm
% Put 'lengthfn to rtype 'logical instead of tag '!*fof.
%
% Revision 1.3  1996/06/05 15:10:42  sturm
% Turned off rlsimpl and rlsiexpla by default.
% Changed the subfn of the rtype logical to rl_sub!*fof.
%
% Revision 1.2  1996/05/12 08:28:07  sturm
% Introduced new switches rldavgcd and rlsitsqspl.
%
% Revision 1.1  1996/03/22 12:18:24  sturm
% Moved and split.
%
% Revision 1.23  1996/03/18 15:47:20  sturm
% Added service rlatml.
% Made rl_simp apply rl_simpl in dependence on the switch rlsimpl.
% Changed rl_reval to avoid double simplification.
% Removed rl_aeval.
% Major changes in the treatment of switches. Moved default declarations
% from context files to here.
% Major changes in rl_set.
% Removed treatment of several context properties: rl_enterargnum,
% rl_me2tag, rl_tag2me.
% The for loop actions "mkand" and "mkor" flatten the top-level now.
% Moved rl operator classification predicates from module cl to here.
% Rewritten rl_prepfof1, rl_resimp.
% Changed context conversion in rl_simp!*fof.
% Added macros rl_mkbb: black boxes are introduced by this now.
% Added macro rl_mkserv replacing smacro rl_mkinterf. Major changes in
% AM-SM paramter passing routines.
% Changed data-driven code for internal representations. Introduced
% "rl_"-properties on the context tag: rl_lengthat, rl_resimpat, and
% rl_prepat, rl_prepterm, rl_simpterm.
%
% Revision 1.22  1996/03/11 13:19:03  reiske
% Added black boxes fctrat and tordp.
% Added interface for rlapnf and rlifacl.
%
% Revision 1.21  1996/03/10 13:04:09  sturm
% Added switch rlqeheu.
% Added interface for rlmatrix.
%
% Revision 1.20  1996/03/10 12:48:34  dolzmann
% Added new switch !*rlgsvb.
%
% Revision 1.19  1996/03/09 13:37:01  sturm
% Added switch rlqesr.
% Renamed fluid rl_tag!* to rl_cid!*, removed fluid rl_ctag!*.
% Moved rl_updcache1 to rl_updcache.
% Moved the black boxes from module cl to here changing the "cl_"
% prefixes into "rl_".
% Moved the  constructors/access functions from module cl to here
% renaming them as follows:
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
% Overworked structuring into submodules.
% Added primitive support for a subfn.
%
% Revision 1.18  1996/03/04 17:14:14  sturm
% Moved the treatment of the switch !*rlsimpl to rl_mk!*fof and
% rl_prepfof. Turned off !*rlrealtime temporarily for the call to
% rl_simpl.
%
% Revision 1.17  1996/03/04 13:09:39  dolzmann
% Added switch !*rlbnfsac.
% Removed switch !*rlbnfsb.
%
% Revision 1.16  1996/02/26 12:51:38  sturm
% Fixed bugs in rl_updcache1 and rl_mkinterf.
%
% Revision 1.15  1996/02/18 14:07:41  sturm
% Added switches rlsifac and rlqegsd.
% Removed switch rlqesdnf.
% Added optional theory to rlqe. Modified rl_qe!-s2a accordingly.
% Made rlatl available in the AM.
%
% Revision 1.14  1996/02/18 12:42:52  dolzmann
% Fixed a bug in rl_simp.
% Added optional parameters to rlgsc, rlgsd, and rlgsn.
% Added switch rlgserf.
%
% Revision 1.13  1995/11/16  08:12:14  sturm
% Added switch rlsimpl and respective code.
% Added primitive support for Xr.
% Rewritten rl_simpq: Variable lists as first argument are possible now.
% Added module rlfor implementing mkand and mkor actions in for-loops.
% Added an optional parameter to the interface for rlex and rlall.
%
% Revision 1.12  1995/10/18  10:17:59  sturm
% Added switches rlbnfsb and rlbnfsm.
%
% Revision 1.11  1995/09/05  07:59:02  sturm
% Added switches rlqesdnf, rlsipw, rlsipo.
%
% Revision 1.10  1995/08/31  13:57:32  sturm
% Added procedure rl_!*foflength.
% Modified rl_mk!*fof for a more consistent AM representation of atomic
% formulas.
%
% Revision 1.9  1995/08/30  07:44:14  sturm
% Modified rl_set. It accepts and returns a list now. Added fluid
% rl_argl!* for the extra rl_set parameters.
% Removed psopfn rl_set from AM.
% Fixed rlrealtime to nil in rl_identifyonoff.
%
% Revision 1.8  1995/08/08  10:22:39  sturm
% Removed switch rldev and dependent code.
% Renamed rl_ppriand to rl_ppriop. It is now used with all RL infix
% operators.
% Added rl_prepq.
% Fixed a bug in procedure rl_mkinterf1.
% Added extra optional argument to rlsimpl. Extended its AM backconversion.
%
% Revision 1.7  1995/08/03  05:32:52  dolzmann
% Added procedure rlgsn.
%
% Revision 1.6  1995/08/02  07:22:02  sturm
% Added fluid rl_deflang!* and default language code.
% Added switches rlsiidem and rlsiso.
% Changed copyright messages.
%
% Revision 1.5  1995/07/12  15:11:26  sturm
% Added procedure rl_identifyonoff.
%
% Revision 1.4  1995/07/07  11:29:50  sturm
% Removed "_" in switch names and AM interface names.
% Added switches rlrealtime, rlopt1s, renamed switch rl_smsimpl to rlsism.
% Renamed Groebner simplifiers: rl_gbcsimpl to rlgsc and
% rl_gbdsimpl to rlgsd.
% Added procedures rl_simpterm, rl_prepterm, and rl_mkterm.
% Major changes in module rl3 (AM interface), added realtime code.
%
% Revision 1.3  1995/06/21  09:04:37  sturm
% Removed declarations of non-used local variables.
% Commented create!-package out.
% Changed qe inteface, added opt and optgen interfaces.
% Added switches rl_parallel, rl_qeans, rl_qedfs.
% Renamed switches rl_tablib and rl_tablcb to rl_tabib and rl_tabcb resp.
%
% Revision 1.2  1995/06/01  13:36:37  dolzmann
% Renamed switch rl_nocheck to rl_sichk with opposite semantic.
% Added switch rl_gsprod.
% Moved treatment of SQ's from rl_simpatom to rl_simp.
%
% Revision 1.1  1995/05/29  14:47:22  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rl_rcsid!* rl_copyright!*);
   rl_rcsid!* := "$Id: rl.red,v 1.15 1997/08/12 17:03:51 sturm Exp $";
   rl_copyright!* :=
      "Copyright (c) 1995 by A. Dolzmann and T. Sturm, Universitaet Passau"
>>;


% file rl.red
% Reduce logic component.

module rl;
% Reduce logic component.

create!-package('(rl rlami rlsched rlcont),nil);

exports rl_tvalp,rl_quap,rl_junctp,rl_basbp,rl_extbp,rl_boolp,rl_cxp;

fluid '(rl_cid!* rl_argl!* rl_deflang!* rl_ocswitches!* rl_bbl!* rl_servl!*);

switch rlsism,rlsichk,rlsiidem,rlsisqf,rlsipd,rlsiexpl,rlsiexpla,rlsiso,rlsipw,
   rlsipo,rltabib,rlverbose,rlrealtime,rlidentify,rlgssub,rlgsrad,
   rlgsred,rlgsprod,rlqepnf,rlqedfs,rlparallel,rlopt1s,rlbrop,
   rlbnfsm,rlsimpl,rlsifac,rlqegsd,rlgserf,rlbnfsac,rlgsvb,rlqesr,rlqeheu,
   rldavgcd,rlsitsqspl,rlgsbnf,rlgsutord,rlqegenct,rltnft,rlnzden,rlposden,
   rladdcond,rlqevarsel;

on1 'rlbrop;
off1 'rlbnfsm;
on1 'rlbnfsac;
on1 'rlqepnf;
on1 'rlsiso;
on1 'rlsiidem;
off1 'rlidentify;
off1 'rlrealtime;
off1 'rlparallel;
off1 'rlopt1s;
off1 'rlqedfs;
on1 'rlverbose;
on1 'rlsichk;
on1 'rlsism;
off1 'rlsipw;
on1 'rlsipo;
on1 'rltabib;
on1 'rlgssub;
on1 'rlgsrad;
on1 'rlgsred;
on1 'rlgserf;
off1 'rlgsprod;
on1 'rlgsvb;
off1 'rlsimpl;
on1 'rlsisqf;
on1 'rlsipd;
on1 'rlsiexpl;
on1 'rlsiexpla;
on1 'rlsifac;
off1 'rlqesr;
on1 'rlqeheu; 
off1 'rlqegsd;
on1 'rldavgcd;
on1 'rlsitsqspl;
on1 'rlgsbnf;
off1 'rlgsutord;
on1 'rlqegenct;
on1 'rltnft;
on1 'rlqevarsel;
off1 'rlnzden;
off1 'rlposden;
off1 'rladdcond;
	 
put('rlidentify,'simpfg,
   '((t (rl_identifyonoff t)) (nil (rl_identifyonoff nil))));

procedure quotelog(x); 'logical;

put('logical,'evfn,'rl_reval);
put('logical,'subfn,'rl_sub!*fof);
put('logical,'lengthfn,'rl_lengthlogical);

put('!*fof,'prifn,'rl_print!*fof);
put('!*fof,'fancy!-prifn,'rl_print!*fof);
%put('!*fof,'prifn,'prin2!*);
put('!*fof,'rtypefn,'quotelog);
put('!*fof,'rl_simpfn,'rl_simp!*fof);

put('and,'rtypefn,'quotelog);
put('and,'rl_simpfn,'rl_simpbop);
put('and,'rl_prepfn,'rl_prepbop);
put('and,'pprifn,'rl_ppriop);
put('and,'fancy!-pprifn,'rl_fancy!-ppriop);

put('or,'rtypefn,'quotelog);
put('or,'rl_simpfn,'rl_simpbop);
put('or,'rl_prepfn,'rl_prepbop);
put('or,'pprifn,'rl_ppriop);
put('or,'fancy!-pprifn,'rl_fancy!-ppriop);

put('not,'rtypefn,'quotelog);
put('not,'rl_simpfn,'rl_simpbop);
put('not,'rl_prepfn,'rl_prepbop);

algebraic infix impl;
put('impl,'rtypefn,'quotelog);
put('impl,'rl_simpfn,'rl_simpbop);
put('impl,'rl_prepfn,'rl_prepbop);
put('impl,'number!-of!-args,2);
put('impl,'pprifn,'rl_ppriop);
put('impl,'fancy!-infix!-symbol,222);

algebraic infix repl;
put('repl,'rtypefn,'quotelog);
put('repl,'rl_simpfn,'rl_simpbop);
put('repl,'rl_prepfn,'rl_prepbop);
put('repl,'number!-of!-args,2);
put('repl,'pprifn,'rl_ppriop);
put('repl,'fancy!-infix!-symbol,220);

algebraic infix equiv;
put('equiv,'rtypefn,'quotelog);
put('equiv,'rl_simpfn,'rl_simpbop);
put('equiv,'rl_prepfn,'rl_prepbop);
put('equiv,'number!-of!-args,2);
put('equiv,'pprifn,'rl_ppriop);
put('equiv,'fancy!-infix!-symbol,219);

flag('(impl repl equiv and or),'spaced);

precedence equiv,when;
precedence repl,equiv;
precedence impl,repl;
flag('(true false),'reserved);

put('ex,'rtypefn,'quotelog);
put('ex,'rl_simpfn,'rl_simpq);
put('ex,'number!-of!-args,2);
put('ex,'prifn,'rl_priq);
put('ex,'rl_prepfn,'rl_prepq);
put('ex,'fancy!-functionsymbol,36);
put('ex,'fancy!-prifn,'rl_fancy!-priq);

put('all,'rtypefn,'quotelog);
put('all,'rl_simpfn,'rl_simpq);
put('all,'number!-of!-args,2);
put('all,'prifn,'rl_priq);
put('all,'rl_prepfn,'rl_prepq);
put('all,'fancy!-functionsymbol,34);
put('all,'fancy!-prifn,'rl_fancy!-priq);

flag('(rl_simpbop rl_simpq rl_prepbop rl_prepq),'full);

macro procedure rl_mkbb(lst);
   % Make black box.
   begin scalar args,vn,name,n,prgn;
      name := eval cadr lst;
      n := eval caddr lst;
      args := for i := 1:n collect mkid('a,i);
      vn := intern compress nconc(explode name,'(!! !*));
      prgn := {'setq,'rl_bbl!*,{'cons,mkquote vn,'rl_bbl!*}} . prgn;
      prgn := {'put,mkquote name,''number!-of!-args,n} . prgn;
      prgn := {'de,name,args,{'apply,vn,'list . args}} . prgn;
      prgn := {'fluid,mkquote {vn}} . prgn;
      return 'progn . prgn
   end;

macro procedure rl_mkserv(argl);
   begin
      scalar bname,evalfnl,oevalfnl,odefl,resconv,amp,len,
	 args,sm,smv,prgn,am,psval;
      bname := eval nth(argl,2);
      evalfnl := eval nth(argl,3);
      oevalfnl := eval nth(argl,4);
      odefl := eval nth(argl,5);
      resconv := eval nth(argl,6);
      amp := eval nth(argl,7);
      len := length evalfnl + length oevalfnl;
      args := for i := 1:len collect mkid('a,i);
      sm := intern compress append('(!r !l !_),explode bname);
      smv := intern compress nconc(explode sm,'(!! !*));
      prgn := {'setq,'rl_servl!*,{'cons,mkquote smv,'rl_servl!*}} . prgn;
      prgn := {'put,mkquote sm,''number!-of!-args,len} . prgn;
      prgn := {'de,sm,args,{'apply,smv,'list . args}} . prgn;
      prgn := {'fluid,mkquote {smv}} . prgn;
      if amp then <<
      	 am := intern compress append('(!r !l),explode bname);
      	 psval := intern compress nconc(explode sm,'(!! !$));
	 prgn := {'put,mkquote am,''psopfn,mkquote psval} . prgn;
	 prgn := {'put,mkquote psval,''number!-of!-args,1} . prgn;
	 prgn := {'put,mkquote psval,''cleanupfn,''rl_cleanup} . prgn;
	 prgn := {'de,psval,'(argl),{'rl_interf1,mkquote sm,mkquote evalfnl,
	    mkquote oevalfnl,mkquote odefl,mkquote resconv,'argl}} . prgn
      >>;
      return 'progn . prgn
   end;

procedure rl_op(f);
   % Reduce logic operator. [f] is a formula. Returns the top-level
   % operator of [f]. In this sense truth values are operators.
   if atom f then f else car f;

procedure rl_arg1(f);
   % Reduce logic argument of unary operator. [f] is a formula $\tau
   % (\phi)$ with a unary boolean top-level operator $\tau$. Returns
   % the single argument $\phi$ of $\tau$.
   cadr f;

procedure rl_arg2l(f);
   % Reduce logic left hand side argument of binary operator. [f] is a
   % formula $\tau(\phi_1,\phi_2)$ with a binary boolean top-level
   % operator $\tau$. Returns the left hand side argument $\phi_1$ of
   % $\tau$.
   cadr f;

procedure rl_arg2r(f);
   % Reduce logic right hand side argument of binary operator. [f] is
   % a formula $\tau(\phi_1,\phi_2)$ with a binary boolean top-level
   % operator $\tau$. Returns the right hand side argument $\phi_2$ of
   % $\tau$.
   caddr f;

procedure rl_argn(f);
   % Reduce logic argument list of n-ary operator. [f] is a formula
   % $\tau(\phi_1,...)$ with unary, binary, or $n$-ary top-level
   % operator $\tau$. Returns the arguments of $\tau$ as a list
   % $(\phi_1,...)$.
   cdr f;

procedure rl_var(f);
   % Reduce logic variable. [f] is a formula $Q x (\phi)$ where $Q$ is
   % a quantifier. Returns the quantified variable $x$.
   cadr f;

procedure rl_mat(f);
   % Reduce logic matrix. [f] is a formula $Q x (\phi)$ where $Q$ is a
   % quantifier. Returns the matrix $\phi$.
   caddr f;

procedure rl_mk1(uop,arg);
   % Reduce logic make formula for unary operator. [uop] is a unary
   % operator, [arg] is a formula. Returns the formula $[uop]([arg])$
   % with top-level operator [uop] and argument [arg].
   {uop,arg};

procedure rl_mk2(bop,larg,rarg);
   % Reduce logic make formula for binary operator. [bop] is a binary
   % operator, [larg] and [rarg] are formulas. Returns the formula
   % $[bop]([larg],[rarg])$ with top-level operator [bop], left hand
   % side [larg], and right hand side [rarg].
   {bop,larg,rarg};

procedure rl_mkn(nop,argl);
   % Reduce logic make formula for n-ary operator. [nop] is a unary,
   % binary, or $n$-ary operator; [argl] is a list $(\phi_1,...)$ of
   % formulas; for binary or $n$-ary [nop] the length of [argl] is a
   % least 2. Returns the formula $[nop](\phi_1,..)$ with top-level
   % operator [nop], and the elements of [argl] as its arguments.
   nop . argl;

procedure rl_smkn(nop,argl);
   % Reduce logic safe make formula for n-ary operator. [nop] is one
   % of ['and], ['or]; [argl] is a list $(\phi_1,...)$ of formulas.
   % Returns a formula. If [argl] is empty, ['true] is returned for
   % $[nop]=['and]$, and $['false]$ is returned for $[nop]=['or]$. If
   % [argl] is of length 1, its single element $\phi_1$ is returned.
   % Else the formula $[nop](\phi_1,..)$ with top-level operator
   % [nop], and the elements of [argl] as its arguments is returned.
   if argl and cdr argl then
      nop . argl
   else if null argl then
      if nop eq 'and then 'true else 'false
   else
      car argl;

procedure rl_mkq(q,v,m);
   % Reduce logic make quantified formula. [q] is a quantifier, [v] is
   % a variable, [m] is a formula. Returns the formula $[q] [x] ([m])$
   % which is quantified with quantifier [q], quantified variable [v],
   % and matrix [m].
   {q,v,m};

procedure rl_quap(x);
   % Reduce logic quantifier predicate. [x] is any S-expression.
   % Returns non-[nil] iff [x] is a quantifier.
   x eq 'ex or x eq 'all;

procedure rl_junctp(x);
   % Reduce logic junctor predicate. [x] is any S-expression. Returns
   % non-[nil] iff [x] is one of ['and], ['or] which we refer to as
   % junctors.
   x eq 'or or x eq 'and;

procedure rl_basbp(x);
   % Reduce logic basic boolean operator predicate. [x] is any
   % S-expression. Returns non-[nil] iff [x] is a junctor or ['not].
   % We refer to these as basic boolean operators.
   rl_junctp x or x eq 'not;

procedure rl_extbp(x);
   % Reduce logic extended boolean operator predicate. [x] is any
   % S-expression. Returns non-[nil] iff [x] is one of ['impl],
   % ['repl], or ['equiv]. We refer to these as basic boolean
   % operators.
   x eq 'impl or x eq 'repl or x eq 'equiv;

procedure rl_boolp(x);
   % Reduce logic boolean operator predicate. [x] is any S-expression.
   % Returns non-[nil] iff [x] is a boolean operator, i.e. one of
   % ['and], ['or], ['not], ['impl], ['repl], or ['equiv].
   rl_basbp x or rl_extbp x;

procedure rl_tvalp(x);
   % Reduce logic truth value predicate. [x] is any S-expression.
   % Returns non-[nil] iff [x] is one of ['true], ['false].
   x eq 'true or x eq 'false;

procedure rl_cxp(x);
   % Reduce logic complex, i.e., non-atomic, operator predicate.
   rl_tvalp x or rl_boolp x or rl_quap x;

endmodule;  % [rl]

end;  % of file
