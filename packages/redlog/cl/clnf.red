module clnf;  % Common logic normal forms. Submodule of [cl].

revision('clnf, "$Id$");

copyright('clnf, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010-2011 T. Sturm");

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

procedure cl_expand!-extbool(f);
   % Common logic expand extended boolean operators. [f] is a formula.
   % Returns a formula equivalent to [f] that does not contain any
   % extended boolean operator.
   begin scalar op;
      op := rl_op f;
      if rl_quap op then
    	 return rl_mkq(op,rl_var f,cl_expand!-extbool(
      	    rl_mat f));
      if rl_basbp op then
    	 return rl_mkn(op,for each subf in rl_argn f collect
      	    cl_expand!-extbool(subf));
      if op eq 'impl then
    	 return cl_expand!-extbool(rl_mk2('or,
	    rl_mk1('not,rl_arg2l f),rl_arg2r f));
      if op eq 'repl then
    	 return cl_expand!-extbool(rl_mk2('or,
	    rl_arg2l f,rl_mk1('not,rl_arg2r f)));
      if op eq 'equiv then
    	 return cl_expand!-extbool(rl_mkn('and,{
      	    rl_mk2('impl,rl_arg2l f,rl_arg2r f),
      	       rl_mk2('repl,rl_arg2l f,rl_arg2r
		  f)}));
      return f;
   end;

asserted procedure cl_nnf(f: Formula): Formula;
   % Common logic negation normal form. [f] is a formula. Returns a
   % formula equivalent to [f] that does not contain the operator
   % [not].
   cl_nnf1(f,t);

procedure cl_nnfnot(f);
   % Common logic negation normal form not. [f] is a formula. Returns
   % a formula equivalent to $\lnot [f]$ that does not contain the
   % operator [not].
   cl_nnf1(f,nil);

procedure cl_nnf1(f,flag);
   % Common logic negation normal form. [f] is a formula; [flag] is
   % bool. Returns a formula $\phi$ that does not contain the operator
   % [not]. In case $[flag]$ is non-[nil] we have $\phi$ equivalent to
   % [f], else we have $\phi$ equivalent to $\lnot [f]$.
   begin scalar op;
      op := rl_op f;
      if op eq 'not then
    	 return cl_nnf1(rl_arg1 f,not flag);
      if op eq 'impl then
	 return rl_mkn(cl_cflip('or,flag),
	    {cl_nnf1(rl_arg2l f,not flag),cl_nnf1(rl_arg2r f,flag)});
      if op eq 'repl then
	 return rl_mkn(cl_cflip('or,flag),
	    {cl_nnf1(rl_arg2l f,flag),cl_nnf1(rl_arg2r f,not flag)});
      if op eq 'equiv then
	 return rl_mkn(cl_cflip('or,flag),{
	    rl_mkn(cl_cflip('and,flag),{
	       cl_nnf1(rl_arg2l f,flag),cl_nnf1(rl_arg2r f,flag)}),
            rl_mkn(cl_cflip('and,flag),{
	       cl_nnf1(rl_arg2l f,not flag),cl_nnf1(rl_arg2r f,not flag)})});
      if rl_tvalp op then
    	 return cl_cflip(f,flag);
      if rl_quap op then
	 return rl_mkq(cl_cflip(op,flag),rl_var f,cl_nnf1(rl_mat f,flag));
      if rl_bquap op then % don't flip within bound
	 return rl_mkbq(cl_cflip(op,flag),rl_var f,cl_nnf1(rl_b f,t),
	    cl_nnf1(rl_mat f,flag));
      if rl_junctp op then
	 return rl_mkn(
	    cl_cflip(op,flag),for each subf in rl_argn f collect
	       cl_nnf1(subf,flag));
      return if flag then f else rl_negateat f
   end;

procedure cl_pnf(phi);
   % Common logic prenex normal form. [phi] is a formula. Returns a
   % prenex formula equivalent to [phi]. The number of quantifier
   % changes in the result is minimal among all formulas that can be
   % obtained from [phi] by moving quantifiers to the outside.
   cl_pnf1 rl_nnf phi;

procedure cl_pnf1(phi);
   % Common logic prenex normal form subroutine. [phi] is a positive
   % formula that does not contain any extended boolean operator.
   % Returns a prenex formula equivalent to [phi]. The number of
   % quantifier changes in the result is minimal among all formulas
   % that can be obtained from [phi] by moving quantifiers to the
   % outside.
   <<
      if null cdr erg or cl_qb car erg < cl_qb cadr erg then
 	 car erg
      else
 	 cadr erg
   >> where erg=cl_pnf2(cl_rename!-vars(phi));

procedure cl_pnf2(phi);
   begin scalar op,w;
      op := rl_op phi;
      if rl_quap op then
 	 return cl_pnf2!-quantifier(phi);
      if rl_junctp op then
 	 return cl_pnf2!-junctor(phi);
      if rl_tvalp op then
 	 return {phi};
      if (w := rl_external(op,'cl_pnf2)) then
	 return apply(w,{phi});
      if rl_cxp op then
 	 rederr{"cl_pnf2():",op,"invalid as operator"};
      return {phi}
   end;

procedure cl_pnf2!-quantifier(phi);
   <<
      if (null cdr e) or (rl_op phi eq rl_op car e) then
 	 {rl_mkq(rl_op phi,rl_var phi,car e)}
      else
 	 {rl_mkq(rl_op phi,rl_var phi,cadr e)}
   >> where e=cl_pnf2 rl_mat phi;

procedure cl_pnf2!-junctor(phi);
   begin scalar junctor,e,l1,l2,onlyex,onlyall,phi1,phi2; integer m,qb;
      junctor := rl_op phi;
      e := for each f in rl_argn phi collect cl_pnf2(f);
      onlyex := t; onlyall := t;
      for each ej in e do <<
    	 qb := cl_qb car ej;
    	 if qb > m then <<
 	    m := qb; onlyex := t; onlyall := t
 	 >>;
    	 if cdr ej then <<
 	    l1 := (car ej) . l1;
 	    l2 := (cadr ej) . l2
 	 >> else <<
 	    l1 := (car ej) . l1;
 	    l2 := (car ej) . l2
 	 >>;
    	 if eqn(m,qb) then <<
      	    if rl_op car l1 eq 'all then onlyex := nil;
      	    if rl_op car l2 eq 'ex then onlyall := nil
    	 >>;
      >>;
      l1 := reversip l1;
      l2 := reversip l2;
      if eqn(m,0) then return {phi};
      if onlyex neq onlyall then
    	 if onlyex then
 	    return {cl_interchange(l1,junctor,'ex)}
    	 else  % [onlyall]
 	    return {cl_interchange(l2,junctor,'all)};
      phi1 := cl_interchange(l1,junctor,'ex);
      phi2 := cl_interchange(l2,junctor,'all);
      if car phi1 eq car phi2 then
 	 return {phi1}
      else
 	 return {phi1,phi2}
   end;

procedure cl_qb(phi);
   begin scalar q,scan!-q; integer qb;
      while rl_quap(scan!-q := rl_op phi) do <<
    	 if scan!-q neq q then <<
      	    qb := qb + 1;
      	    q := scan!-q
    	 >>;
    	 phi := rl_mat phi
      >>;
      return qb
   end;

procedure cl_interchange(l,junctor,a);
   begin scalar ql,b,result;
      while cl_contains!-quantifier(l) do <<
    	 l := for each f in l collect <<
      	    while rl_op f eq a do <<
               b := (rl_var f) . b;
               f := rl_mat f
      	    >>;
      	    f
    	 >>;
    	 ql := b . ql;
    	 b := nil;
    	 a := cl_flip a
      >>;
      a := cl_flip a;
      result := rl_mkn(junctor,l);
      for each b in ql do <<
    	 for each v in b do result := rl_mkq(a,v,result);
    	 a := cl_flip a
      >>;
      return result
   end;

procedure cl_contains!-quantifier(l);
   l and (rl_quap rl_op car l or cl_contains!-quantifier(cdr l));

asserted procedure cl_rename!-vars(f: Formula): Formula;
   % Common logic rename variables. [f] is a formula. Returns an equivalent
   % formula in which each quantified variable is unique, i.e., occurs neither
   % boundly nor freely elsewhere in [f].
   car cl_rename!-vars1(f, cl_replace!-varl f);

asserted procedure cl_replace!-varl(f: Formula): DottedPair;
   begin scalar fvl, bvl, avl, x, replacel;
      fvl . bvl := cl_varl1 f;  % We assume that [fvl] and [bvl] do not contain duplicates.
      avl := append(fvl, bvl);
      while bvl do <<
	 x := pop bvl;
      	 if x memq fvl then
      	    push(x . 1, replacel)
	 else
      	    push(x . 0, replacel)
      >>;
      return avl . replacel
   end;

asserted procedure cl_rename!-vars1(f: Formula, vl: DottedPair): DottedPair;
   begin scalar op, w, rnf, rnb, nvar;
      op := rl_op f;
      if rl_boolp op then <<
	 for each ff in rl_argn f do <<
	    rnf . vl := cl_rename!-vars1(ff, vl);
	    push(rnf, w)
	 >>;
      	 return rl_mkn(op, reversip w) . vl
      >>;
      if rl_quap op then <<
	 rnf . vl := cl_rename!-vars1(rl_mat f, vl);
	 w := assoc(rl_var f, cdr vl);
	 if w then <<
	    if eqn(cdr w, 0) then <<
	       cdr w := 1;
	       return rl_mkq(op, rl_var f, rnf) . vl
	    >>;
	    repeat <<
	       nvar := mkid(car w, cdr w);
	       cdr w := cdr w + 1
	    >> until not (nvar memq car vl or get(nvar, 'avalue));
	    push(nvar, car vl);
	    rnf := cl_apply2ats1(rnf, 'rl_varsubstat, {nvar, car w});
	    return rl_mkq(op, nvar, rnf) . vl
	 >>;
	 return rl_mkq(op, rl_var f, rnf) . vl
      >>;
      if rl_bquap op then <<  % a bounded quantifier in PASF
	 rnf . vl := cl_rename!-vars1(rl_mat f, vl);
	 w := assoc(rl_var f, cdr vl);
	 if w then <<
	    if eqn(cdr w, 0) then <<
	       cdr w := 1;
	       return rl_mkbq(op, rl_var f, rl_b f, rnf) . vl
	    >>;
	    repeat <<
	       nvar := mkid(car w, cdr w);
	       cdr w := cdr w + 1
	    >> until not (nvar memq car vl or get(nvar,'avalue));
	    push(nvar, car vl);
	    rnb := cl_apply2ats1(rl_b f, 'rl_varsubstat, {nvar, car w});
	    rnf := cl_apply2ats1(rnf, 'rl_varsubstat, {nvar, car w});
	    return rl_mkbq(op, nvar, rnb, rnf) . vl
	 >>;
	 return rl_mkbq(op, rl_var f, rl_b f, rnf) . vl
      >>;
      % [f] is a truth value or an atomic formula.
      return f . vl
   end;

procedure cl_fvarl(f);
   % Common logic free variable list. [f] is a formula. Returns the
   % list of variables occurring freely in [f] sorted wrt. [ordp].
   sort(cl_fvarl1 f,'ordp);

procedure cl_fvarl1(f);
   % Common logic free variable list subroutine. [f] is a formula.
   % Returns the list of variables occurring freely in [f].
   car cl_varl1 f;

procedure cl_bvarl(f);
   % Common logic bound variable list. [f] is a formula. Returns the
   % list of variables occurring boundly in [f] sorted wrt. [ordp].
   sort(cl_bvarl1 f,'ordp);

procedure cl_bvarl1(f);
   % Common logic bound variable list subroutine. [f] is a formula.
   % Returns the list of variables occurring boundly in [f].
   cdr cl_varl1 f;

asserted procedure cl_varl(f: Formula): DottedPair;
   % Common logic variable lists. [f] is a formula. Returns a pair
   % $(V_f . V_b)$ of variable lists. $V_f$ contains the variables
   % occurring freely in [f], and $V_b$ contains the variables
   % occurring boundly in [f]. Both lists are sorted wrt. the current
   % kernel order [ordp].
   (sort(car w,'ordp) . sort(cdr w,'ordp)) where w = cl_varl1 f;

asserted procedure cl_varl1(f: Formula): DottedPair;
   % Common logic variable lists. [f] is a formula. Returns a pair
   % $(V_f . V_b)$ of variable lists. $V_f$ contains the variables
   % occurring freely in [f], and $V_b$ contains the variables
   % occurring boundly in [f].
   cl_varl2(f,nil,nil,nil);

asserted procedure cl_varl2(f: Formula, fvl: KernelL, cbvl: KernelL, bvl: KernelL): DottedPair;
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
 	 return fvl . bvl;
      if rl_boolp op then <<
    	 for each s in rl_argn f do
      	    fvl . bvl := cl_varl2(s, fvl, cbvl, bvl);
      	 return fvl . bvl
      >>;
      if rl_quap op then
      	 return cl_varl2(rl_mat f, fvl, lto_insertq(rl_var f, cbvl), bvl);
      if rl_bquap op then <<
	 cbvl := lto_insertq(rl_var f, cbvl);
	 fvl . bvl := cl_varl2(rl_b f, fvl, cbvl, bvl);
      	 return cl_varl2(rl_mat f, fvl, lto_insertq(rl_var f, cbvl), bvl)
      >>;
      % [f] is an atomic formula.
      for each v in rl_varlat f do
	 if v memq cbvl then
	    bvl := lto_insertq(v, bvl)
	 else
	    fvl := lto_insertq(v, fvl);
      return fvl . bvl
   end;

asserted procedure cl_qvarl(f: Formula): KernelL;
   sort(cl_qvarl1 f, function ordp);

asserted procedure cl_qvarl1(f: Formula): KernelL;
   begin scalar op, qvl;
      op := rl_op f;
      if rl_quap op or rl_bquap op then
	 return lto_insertq(rl_var f, cl_qvarl1 rl_mat f);
      if rl_boolp op then <<
    	 for each s in rl_argn f do
	    qvl := union(qvl, cl_qvarl1 s);
      	 return qvl
      >>;
      % tval or atomic formula
      return nil
   end;

rl_provideService rl_miniscope = cl_apnf using rl_varlat;

asserted procedure cl_apnf(phi: Formula): Formula;
   % Common logic anti-prenex normal form. [phi] is a formula. Returns a
   % positive formula equivalent to [phi], where all quantifiers are moved to
   % the inside as far as possible.
   begin scalar op;
      phi := rl_nnf phi;
      op := rl_op phi;
      if op eq 'ex then
         return cl_apnf1(rl_var phi,cl_apnf rl_mat phi);
      if op eq 'all then
         return rl_nnfnot cl_apnf1(rl_var phi,cl_apnf rl_mat rl_nnfnot phi);
      if rl_junctp op then
	 return rl_mkn(op,for each subf in rl_argn phi collect cl_apnf subf);
      % [phi] is atomic.
      return phi
   end;

procedure cl_apnf1(var,phi);
   % Common logic anti-prenex normal form subroutine. [var] is a
   % variable. [phi] is a positive formula with all quantifiers
   % already moved to the inside as far as possible. Returns a
   % positive formula equivalent to [phi] with the existentially
   % quantified [var] moved to the inside as far as possible.
   begin scalar op,nf,occurl,noccurl;
      op := rl_op phi;
      if rl_tvalp op then
	 return phi;
      if op eq 'ex then
	 return rl_mkq('ex,rl_var phi,cl_apnf1(var,rl_mat phi));
      if op eq 'all then
	 return if cl_freevp(var,phi) then
	    rl_mkq('ex,var,phi)
	 else
	    phi;
      if op eq 'or then <<
	 nf := for each subf in rl_argn phi collect cl_apnf1(var,subf);
	 return rl_mkn('or,nf)
      >>;
      if op eq 'and then <<
	 for each subf in rl_argn phi do
	    if cl_freevp(var,subf) then
	       occurl := subf . occurl
	    else
	       noccurl := subf . noccurl;
	 if occurl then <<
	    nf := if cdr occurl then
	       rl_mkq('ex,var,rl_mkn('and,reversip occurl))
	    else
	       cl_apnf1(var,car occurl);
	    noccurl := nf . noccurl
	 >>;
	 return rl_smkn('and,reversip noccurl)
      >>;
      % [phi] is atomic.
      if var memq rl_varlat phi then
	 return rl_mkq('ex,var,phi);
      return phi
   end;

procedure cl_freevp(var,phi);
   % Common logic free variable predicate. [var] is a variable, [phi]
   % is a formula. Returns non-[nil] iff [var] occurs freely in [phi].
   begin scalar argl,flag;
      if rl_quap rl_op phi then <<
 	 if var eq rl_var phi then
	    return nil;
	 return cl_freevp(var,rl_mat phi)
      >>;
      if cl_atfp phi then
	 return var memq rl_varlat phi;
      argl := rl_argn phi;
      while argl do
	 if cl_freevp(var,car argl) then <<
	    flag := t;
	    argl := nil
	 >> else
	    argl := cdr argl;
      return flag
   end;

rl_provideService rl_tnf = cl_tnf using rl_t2cdl;

procedure cl_tnf(f,terml);
   % Common logic tree normal form. [f] is a formula, [terml] is a
   % list of terms. Returns a big formula. Depends on the switch
   % [rltnft].
   if !*rltnft then cl_tnft(f,terml) else cl_tnff(f,terml);

procedure cl_tnff(f,terml);
   % Common logic tree normal form flat. [f] is a formula, [terml] is
   % a list of terms. Returns a big formula.
   begin scalar w,theol,resl,dpth;
      theol := cl_bnf!-cartprod for each term in terml collect
	 rl_t2cdl term;
      if !*rlverbose then dpth := length theol;
      for each theo in theol do <<
      	 if !*rlverbose then <<
	    ioto_prin2 {"[",dpth};
	    dpth := dpth - 1
	 >>;
 	 w := rl_simpl(f,theo,-1);
	 if w eq 'true then <<
	    resl := rl_smkn('and,theo) . resl;
	    if !*rlverbose then ioto_prin2 "+] "
	 >> else if w eq 'inctheo then
	    (if !*rlverbose then ioto_prin2 "!] ")
	 else if w neq 'false then <<
	    resl := rl_smkn('and,w . theo) . resl;
	    if !*rlverbose then ioto_prin2 ".] "
	 >> else if !*rlverbose then
	    ioto_prin2 "-] "
      >>;
      return rl_smkn('or,resl)
   end;

procedure cl_tnft(f,terml);
   % Common logic tree normal form tree. [f] is a formula, [terml] is
   % a list of terms. Returns a big formula.
   begin scalar w,cdl,cd,rvl;
      if null terml then return f;
      cdl := rl_t2cdl car terml;
      while cdl do <<
	 cd := car cdl;
	 cdl := cdr cdl;
	 w := rl_simpl(rl_mk2('and,cd,f),nil,-1);
	 if w eq 'true then <<
	    rvl := '(true);
	    cdl := nil
	 >> else if w neq 'false then
	    rvl := cl_tnft(w,cdr terml) . rvl
      >>;
      return rl_simpl(rl_smkn('or,rvl),nil,-1)
   end;

endmodule;  % [clnf]

end;  % of file
