% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
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

lisp <<
   fluid '(rl_rcsid!* rl_copyright!*);
   rl_rcsid!* := "$Id$";
   rl_copyright!* := "Copyright (c) 1995-2009 A. Dolzmann and T. Sturm"
>>;

module redlog;
% Reduce logic component.

create!-package('(redlog rlami rlsched rlcont rlhelp),nil);

load!-package 'rltools;  % rlhelp needs ioto.

exports quotelog,rl_mkbb,rl_mkserv,rl_op,rl_arg1,rl_arg2l,rl_arg2r,rl_argn,
   rl_var,rl_mat,rl_mk1,rl_mk2,rl_mkn,rl_smkn,rl_mkq,rl_quap,rl_junctp,rl_basbp,
   rl_extbp,rl_boolp,rl_tvalp,rl_cxp,rl_mk!*fof,rl_reval,rl_prepfof,rl_cleanup,
   rl_simp,rl_simpbop,rl_simpq,rl_simp!*fof,rl_lengthlogical,rl_sub!*fof,
   rl_print!*fof,rl_priq,rl_ppriop,rl_fancy!-ppriop,rl_fancy!-priq,
   rl_interf1,rl_a2s!-decdeg1,rl_a2s!-varl,rl_a2s!-number,rl_a2s!-id,
   rl_a2s!-atl,rl_a2s!-posf,rl_s2a!-simpl,rl_s2a!-gqe,rl_s2a!-gqea,rl_s2a!-qea,
   rl_s2a!-opt,rl_s2a!-atl,rl_s2a!-ml,rl_s2a!-term,rl_s2a!-decdeg1,
   rl_a2s!-targfn,rl_a2s!-terml,rl_s2a!-terml,rl_a2s!-term,rl_s2a!-varl,
   rl_s2a!-fbvarl,rl_s2a!-struct,rlmkor,rlmkand,rl_set!$,rl_set,rl_exit,
   rl_enter,rl_onp,rl_vonoff,rl_updcache,rl_serviadd,rl_bbiadd;

fluid '(rl_cid!* rl_argl!* rl_usedcname!* rl_deflang!* rl_ocswitches!*
   rl_bbl!* rl_servl!* !*utf8);

fluid '(fancy!-line!* fancy!-pos!*);

switch rlsism,rlsichk,rlsiidem,rlsiatadv,rlsipd,rlsiexpl,rlsiexpla,rlsiso,
   rlsipw,rlsipo,rltabib,rlverbose,rlrealtime,rlidentify,rlgssub,rlgsrad,
   rlgsred,rlgsprod,rlqepnf,rlqedfs,rlparallel,rlopt1s,rlbrop,
   rlbnfsm,rlsimpl,rlsifac,rlqegsd,rlgserf,rlbnfsac,rlgsvb,rlqesr,rlqeheu,
   rldavgcd,rlsitsqspl,rlgsbnf,rlgsutord,rlqegenct,rltnft,rlnzden,rlposden,
   rladdcond,rlqevarsel,rlqeqsc,rlqesqsc,rlsusi,rlsusimult,rlsusigs,rlsusiadd,
   rlcadfac,rlcaddnfformula,rlcadprojonly,rlcadpreponly,rlcadbaseonly,
   rlcadextonly,rlcadverbose,rlcadfasteval,rlcaddebug,rlcadpartial,
   rlcadfulldimonly,rlcadtrimtree,rlcadrawformula,rlcadisoallroots,rlcadaproj,
   rlcadaprojalways,rlcadhongproj,rlanuexverbose,rlanuexdifferentroots,
   rlanuexdebug,rlanuexpsremseq,rlanuexgcdnormalize,rlanuexsgnopt,rlcaddecdeg,
   rlcadte,rlcadpbfvs,rlqefb,rlxopt,rlxoptsb,rlxoptpl,rlxoptri,rlxoptric,
   rlxoptses,rlxoptrir,rlourdet,rlvmatvb,rlhqetfcsplit,rlhqetfcfullsplit,
   rlhqetfcfast,rlhqevb,rlhqevarsel,rlhqevarselx,rlhqedim0,rlhqetheory,
   rlhqegbred,rlhqeconnect,rlhqestrconst,rlhqegbdimmin,rlresi,rlqeasri,
   rlqeaprecise,rlqefilterbounds,rlsifaco,rlqelog,rlqeprecise,rlqevarseltry;

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
off1 'rlverbose;
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
on1 'rlsiatadv;
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
off1 'rlqeqsc;
off1 'rlqesqsc;
off1 'rlsusi;
on1 'rlsusimult;  
off1 'rlsusigs;   
on1 'rlsusiadd;
on1  'rlcadfac;
on1 'rlcaddnfformula;
off1 'rlcadpreponly;
off1 'rlcadprojonly;
off1 'rlcadbaseonly;
off1 'rlcadextonly;
on1 'rlcadverbose;
on1  'rlcadfasteval;
off1 'rlcaddebug;
on1 'rlcadpartial;
off1 'rlcadfulldimonly;
on1  'rlcadtrimtree;
off1 'rlcadrawformula;
off1 'rlcadisoallroots;
off1 'rlcadaproj;
off1 'rlcadaprojalways;
on1 'rlcadhongproj;
off1 'rlanuexverbose;
on1 'rlanuexdifferentroots;
off1 'rlanuexdebug;
off1 'rlanuexpsremseq;
on1 'rlanuexgcdnormalize;
off1 'rlanuexsgnopt;
off1 'rlcaddecdeg;
on1 'rlcadte;
on1 'rlcadpbfvs;
on1 'rlqefb;
on1 'rlxopt;
on1 'rlxoptsb;    % select boundary type
on1 'rlxoptpl;    % passive list
on1 'rlxoptri;    % result inheritance
off1 'rlxoptric;  % result inheritance to conatiner
off1 'rlxoptrir;  % result inheritance to result
on1 'rlxoptses;   % structural elimination sets.
off1 'rlourdet;
off1 'rlvmatvb;  % Fixied switch, provides debugging within ofsfdet
on1 'rlhqetfcsplit;  % Splits type formula computation up to degree 4.
off1 'rlhqetfcfast;  % Splits type formula computation unconditionally.
off1 'rlhqetfcfullsplit;  % Compute case distinctions only for unknown signs.

off1 'rlhqevb;          % More verbose output.
on1 'rlhqevarsel;       % Optimize variable selection in the case dim I=n.
on1 'rlhqevarselx;      % Advances optimization with more computational effort.
on1 'rlhqetheory;       % Use initial conditions for CGB computation.
off1 'rlhqedim0;        % Only zero dimensional branches.
off1 'rlhqegbred;       % Use reduced Groebner systems.
off1 'rlhqeconnect;     % Connect branches which differs only in the theory.
on1 'rlhqestrconst;     % Use combined structure constants.
on1 'rlhqegbdimmin;     % Choose maximal independent variable set with
                        % minimal cardinality in the case 0<dim<n.
on1 'rlresi;            % Implicit (local) simplification for rlresolve.
on1 'rlqeasri;          % Simplifier-recognized implication for pasf answers.
off1 'rlqeaprecise;     % Possibly avoid epsilon and infinity with rlqea.
on1 'rlqefilterbounds;  % Remove bounds w false guards before counting.
off1 'rlsifaco;         % Factorize lhs of ordering inequalities in simplat.
off1 'rlqelog;          % Hack by TS to look into elimination set generation.
off1 'rlqeprecise;      % Possibly avoid epsilon and infinity with rlqe.
off1 'rlqevarseltry;    % Allow rl_varsel to return several variables.

put('rlidentify,'simpfg,
   '((t (rl_identifyonoff t)) (nil (rl_identifyonoff nil))));

procedure quotelog(x); 'logical;

procedure rl_texmacsp();
   get('tmprint,'package);

put('logical,'tag,'!*fof);
put('logical,'evfn,'rl_reval);
put('logical,'subfn,'rl_sub!*fof);
put('logical,'lengthfn,'rl_lengthlogical);

put('!*fof,'prifn,'rl_print!*fof);
put('!*fof,'fancy!-prifn,'rl_print!*fof);
put('!*fof,'fancy!-setprifn,'rl_setprint!*fof);
%put('!*fof,'prifn,'prin2!*);
put('!*fof,'rtypefn,'quotelog);
put('!*fof,'rl_simpfn,'rl_simp!*fof);

put('and,'rtypefn,'quotelog);
put('and,'rl_simpfn,'rl_simpbop);
put('and,'rl_prepfn,'rl_prepbop);
put('and,'pprifn,'rl_ppriop);
put('and,'fancy!-pprifn,'rl_fancy!-ppriop);
if rl_texmacsp() then
   put('and,'fancy!-infix!-symbol,"\,\wedge\, ");

put('or,'rtypefn,'quotelog);
put('or,'rl_simpfn,'rl_simpbop);
put('or,'rl_prepfn,'rl_prepbop);
put('or,'pprifn,'rl_ppriop);
put('or,'fancy!-pprifn,'rl_fancy!-ppriop);
if rl_texmacsp() then
   put('or,'fancy!-infix!-symbol,"\,\vee\, ");

put('not,'rtypefn,'quotelog);
put('not,'rl_simpfn,'rl_simpbop);
put('not,'rl_prepfn,'rl_prepbop);

algebraic infix impl;
put('impl,'rtypefn,'quotelog);
put('impl,'rl_simpfn,'rl_simpbop);
put('impl,'rl_prepfn,'rl_prepbop);
put('impl,'number!-of!-args,2);
put('impl,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('impl,'fancy!-infix!-symbol,"\,\longrightarrow\, ")
else
   put('impl,'fancy!-infix!-symbol,222);

algebraic infix repl;
put('repl,'rtypefn,'quotelog);
put('repl,'rl_simpfn,'rl_simpbop);
put('repl,'rl_prepfn,'rl_prepbop);
put('repl,'number!-of!-args,2);
put('repl,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('repl,'fancy!-infix!-symbol,"\,\longleftarrow\, ")
else
   put('repl,'fancy!-infix!-symbol,220);

algebraic infix equiv;
put('equiv,'rtypefn,'quotelog);
put('equiv,'rl_simpfn,'rl_simpbop);
put('equiv,'rl_prepfn,'rl_prepbop);
put('equiv,'number!-of!-args,2);
put('equiv,'pprifn,'rl_ppriop);
if rl_texmacsp() then
   put('equiv,'fancy!-infix!-symbol,"\,\longleftrightarrow\, ")
else
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
put('ex,'fancy!-prifn,'rl_fancy!-priq);
if rl_texmacsp() then
   put('ex,'fancy!-functionsymbol,"\exists ")
else
   put('ex,'fancy!-functionsymbol,36);

put('all,'rtypefn,'quotelog);
put('all,'rl_simpfn,'rl_simpq);
put('all,'number!-of!-args,2);
put('all,'prifn,'rl_priq);
put('all,'rl_prepfn,'rl_prepq);
put('all,'fancy!-prifn,'rl_fancy!-priq);
if rl_texmacsp() then
   put('all,'fancy!-functionsymbol,"\forall ")
else
   put('all,'fancy!-functionsymbol,34);

put('bex,'rtypefn,'quotelog);
put('bex,'rl_simpfn,'rl_simpbq);
put('bex,'number!-of!-args,3);
put('bex,'prifn,'rl_pribq);
put('bex,'rl_prepfn,'rl_prepbq); % semms not to be used!
%put('bex,'fancy!-functionsymbol,36);
put('bex,'fancy!-prifn,'rl_fancy!-pribq);
if rl_texmacsp() then
   put('bex,'fancy!-functionsymbol,"\bigsqcup ")
else
   put('bex,'fancy!-functionsymbol,36); %%% 36 okay?

put('ball,'rtypefn,'quotelog);
put('ball,'rl_simpfn,'rl_simpbq);
put('ball,'number!-of!-args,3);
put('ball,'prifn,'rl_pribq);
put('ball,'rl_prepfn,'rl_prepbq);
%put('ball,'fancy!-functionsymbol,34);
put('ball,'fancy!-prifn,'rl_fancy!-pribq);
if rl_texmacsp() then
   put('ball,'fancy!-functionsymbol,"\bigsqcap ")
else
   put('ball,'fancy!-functionsymbol,34); %%% 34 okay?

flag('(rl_simpbop rl_simpq rl_simpbq rl_prepbop rl_prepq rl_prepbq),'full);

macro procedure rl_getversion(argl);
   begin scalar v,w;
      v := getenv("REDLOGVERSION") or "DEVELOPMENT VERSION";
      w := getenv("REDLOGDATE") or date();
      return lto_sconcat {"REDLOG ",v,", ",w}
   end;

operator rlabout;

procedure rlabout();
   <<
      ioto_tprin2t rl_getversion();
      if !*utf8 then <<
%	 tyo 226; tyo 146; tyo 184
	 tyo 194; tyo 169
      >> else
	 ioto_prin2 "(C)";
      ioto_prin2t " 1995-2009 A. Dolzmann and T. Sturm";
      ioto_tprin2t "http://www.redlog.eu/"
   >>;

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

procedure rl_b(f);
   % Reduce logic bound. [f] is a formula starting with a bounded
   % quantifier. Returns the bound.
   cadddr f;

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

procedure rl_mkbq(q,v,b,m);
   % Reduce logic make quantified formula. [q] is a quantifier, [v] is
   % a variable, [b] is a fof with x as only free variable, [m] is a
   % formula. Returns a formula which is quantified with quantifier
   % [q], quantified variable [v], which is restricted by [b] and
   % matrix [m].
   {q,v,m,b};

procedure rl_quap(x);
   % Reduce logic quantifier predicate. [x] is any S-expression.
   % Returns non-[nil] iff [x] is a quantifier.
   x eq 'ex or x eq 'all;

procedure rl_bquap(x);
   % Reduce logic bounded quantifier predicate. [x] is any
   % S-expression. Returns non-[nil] iff [x] is a bounded quantifier.
   x eq 'bex or x eq 'ball;

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
   rl_tvalp x or rl_boolp x or rl_quap x or rl_bquap x;

endmodule;  % [redlog]

end;  % of file
