% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-1997 Andreas Dolzmann and Thomas Sturm
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
   rl_copyright!* := "Copyright (c) 1995-1997  A. Dolzmann, T. Sturm"
>>;

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
