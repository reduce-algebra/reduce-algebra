module ofsfmisc;  % Ordered field standard form miscellaneous

revision('ofsfmisc, "$Id$");

copyright('ofsfmisc, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010-2017 T. Sturm");

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

procedure ofsf_termprint(u);
   % Ordered field standard form term print term. [u] is a SF. The
   % return value is not specified. Prints [u] AM-like.
   <<
      sqprint !*f2q u where !*nat=nil;
      ioto_prin2 nil
   >>;

procedure ofsf_canegrel(r,flg);
   % Ordered field standard form conditionally algberaically negate
   % relation. [r] is a relation. Returns a relation $R$. If [flg] is
   % non-[nil], then $[R]=[r]$. If [flg] is [nil], then [R] is a
   % relation, such that $R(-t,0)$ is equivalent to $[r](t,0)$ for
   % every term $t$.
   if flg then r else ofsf_anegrel r;

procedure ofsf_anegrel(r);
   % Ordered field standard form algebraically negate relation. [r] is
   % a relation. Returns a relation $R$ such that $R(-t,0)$ is
   % equivalent to $[r](t,0)$ for a term $t$.
   cdr atsoc(r,'((equal . equal) (neq . neq) (leq . geq) (geq . leq)
      (lessp . greaterp) (greaterp . lessp)))
         or rederr {"ofsf_anegrel: unknown operator ",r};

procedure ofsf_clnegrel(r,flg);
   % Ordered field standard form conditionally logically negate
   % relation. [r] is a relation; [flg] is bool. Return a relation
   % $R$. If [flg] is non-[nil] [r] is returned. Othewise a relation
   % $R$ is returned such that for terms $t_1$, $t_2$ we have
   % $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if flg then r else ofsf_lnegrel r;

procedure ofsf_lnegrel(r);
   % Ordered field standard form logically negate relation. [r] is a
   % relation. Returns a relation $R$ such that for terms $t_1$, $t_2$
   % we have $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if r eq 'equal then 'neq
   else if r eq 'neq then 'equal
   else if r eq 'leq then 'greaterp
   else if r eq 'lessp then 'geq
   else if r eq 'geq then 'lessp
   else if r eq 'greaterp then 'leq
   else rederr {"ofsf_lnegrel: unknown operator ",r};

procedure ofsf_fctrat(atf);
   % Ordered field standard form factorize atomic formula. [atf] is an
   % atomic formula $l \mathrel{\varrho} 0$. Returns a list $(...,(f_i
   % . d_i),...)$, where $f$ is an irreducible SF and $d$ is a
   % positive integer. We have $l=c \prod_i g_i^{d_i}$ for an integer
   % $c$.
   cdr sfto_fctrf ofsf_arg2l atf;

procedure ofsf_negateat(f);
   % Ordered field standard form negate atomic formula. [f] is an
   % atomic formula. Returns an atomic formula equivalent to $\lnot
   % [f]$.
   ofsf_mkn(ofsf_lnegrel ofsf_op f,ofsf_argn f);

procedure ofsf_varlat(atform);
   % Ordered field standard form atomic formula list of variables.
   % [atform] is an atomic formula. Returns the variables contained in
   % [atform] as a list.
   begin scalar vl;
      vl := kernels ofsf_arg2l atform;
      if !*rlbrkcxk then
         vl := for each v in vl join
            lto_lpvarl v;
      return vl
   end;

procedure ofsf_varsubstat(atf,new,old);
   % Ordered field standard form substitute variable for variable in
   % atomic formula. [atf] is an atomic formula; [new] and [old] are
   % variables. Returns an atomic formula equivalent to [atf] where
   % [old] is substituted with [new].
   ofsf_0mk2(ofsf_op atf,numr subf(ofsf_arg2l atf,{old . new}));

procedure ofsf_ordatp(a1,a2);
   % Ordered field standard form atomic formula predicate. [a1] and
   % [a2] are atomic formulas. Returns [t] iff [a1] is less than [a2].
   begin scalar lhs1,lhs2;
      lhs1 := ofsf_arg2l a1;
      lhs2 := ofsf_arg2l a2;
      if lhs1 neq lhs2 then return not ordp(lhs1,lhs2);
      return ofsf_ordrelp(ofsf_op a1,ofsf_op a2)
   end;

procedure ofsf_ordrelp(r1,r2);
   % Ordered field standard form relation order predicate.
   % [r1] and [r2] are ofsf-relations. Returns a [T] iff $[r1] < [r2]$.
   r2 memq cdr (r1 memq '(equal neq leq lessp geq greaterp));

procedure ofsf_a2cdl(atml);
   % Ordered field standard form atomic to case distinction list.
   % [atml] is a list of atomic formulas with multiplicity, the right
   % hand side of which is always zero. Returns a list, each
   % containing a list of case distinction w.r.t. the term $t$, i.e.
   % ${t<0,t=0,t>0}$ resp. ${t=0,t neq 0}$.
   begin scalar atf,terml,flag;
      while atml do <<
         atf := caar atml;
         atml := cdr atml;
         terml := ofsf_arg2l atf . terml;
         if not(ofsf_op atf memq '(equal neq)) then flag := t
      >>;
      return for each x in terml collect
         if flag then
            {ofsf_0mk2('lessp,x),ofsf_0mk2('equal,x),ofsf_0mk2('greaterp,x)}
         else
            {ofsf_0mk2('equal,x),ofsf_0mk2('neq,x)}
   end;

procedure ofsf_t2cdl(term);
   % Ordered field standard form term to case distinction list. [term]
   % is a term. Returns a list of full case distinctions w.r.t. the
   % term, i.e. ${[term]<0,[term]=0,[term]>0}$.
   {ofsf_0mk2('lessp,term),ofsf_0mk2('equal,term),ofsf_0mk2('greaterp,term)};

procedure ofsf_vsubat(v, u, f);
   if u eq 'epsilon then
      ofsf_qesubqpe(f, v, '(nil . 1))
   else if u = '(minus epsilon) then
      ofsf_qesubqme(f, v, '(nil . 1))
   else if u eq 'infinity then
      ofsf_qesubiat(f, v, 'pinf)
   else if u = '(minus infinity) then
      ofsf_qesubiat(f, v, 'minf)
   else if eqcar(u, 'list) then
      ofsf_qesubrat(f, v, for each p in cdr u collect numr simp p)
   else
      rederr {"ofsf_vsubat: unexpected term", u};

procedure ofsf_subat(al,f);
   ofsf_simpat {ofsf_op f,ofsf_suba(al,prepf ofsf_arg2l f),0};

procedure ofsf_suba(al,f);
   % Substitute algebraically. [f] is Lisp prefix. Returns Lisp
   % prefix.
   if atom f then
      lto_catsoc(f,al) or f
   else
      car f . for each arg in cdr f collect ofsf_suba(al,arg);

procedure ofsf_subalchk(al);
   % Formerly cheked for parametric denominators, but we correctly handle them
   % in ofsf_subat now. Also, a rederr here causes and error message "*****
   % sub", probably due to some errorset in subeval.
   if not !*rlnzden and not !*rlposden then
      for each pr in al do
         if not domainp denr simp cdr pr then
            rederr "parametric denominator in substituted expression";

procedure ofsf_eqnrhskernels(x);
   nconc(kernels numr w,kernels denr w) where w=simp cdr x;

procedure ofsf_vsubalchk(al);
   for each pr in al do
      if not ofsf_nstdp pr then
         rederr {"illegal term", cdr pr, "in vsub"};

procedure ofsf_nstdp(u);
   begin scalar cnt;
      u := cdr u;
      if u member '(epsilon (minus epsilon) infinity (minus infinity)) then
         return t;
      if not eqcar(u, 'list) or length cdr u neq 4 then
         return nil;
      u := cdr u;
      cnt := t; while cnt and u do
         if denr simp car u neq 1 then
            cnt := nil
         else
            u := cdr u;
      return cnt
   end;

procedure ofsf_getineq(f,bvl);
   % Generate theory get inequalities. [f] is a formula, the right
   % hand side is always zero; [bvl] is a list of variables. Returns
   % the list of all inequalities occuring in [f] not containing any
   % variables from [bvl].
   begin scalar atml,atf,cdl;
      atml := cl_atml f;
      while atml do <<
         atf := caar atml;
         atml := cdr atml;
         if ofsf_op atf memq '(neq) and
            null intersection(bvl, kernels ofsf_arg2l atf) then
            cdl := atf . cdl
      >>;
      return cdl
   end;

procedure ofsf_structat(at,al);
   % Orederd field standard form structure of an atomic formula. [at]
   % is an atomic formula $([op],l,0)$; [al] is an ALIST. Returns an
   % atomic formula. [al] is of the form $(...,(f_i . v_i),...)$ where
   % $f_i$ is an SF and $v_i$ is a variable. The left hand side of
   % [at] occurs as a key in [al]. Returns the atomic formula
   % $[op](v_i,0)$, provided $l=f_i$.
   begin scalar lhs;
      lhs := ofsf_arg2l at;
      if domainp lhs then
         return at;
      return ofsf_0mk2(ofsf_op at, numr simp cdr assoc(lhs,al))
   end;

procedure ofsf_ifstructat(at,al);
   begin scalar w,r;
      w := sfto_fctrf ofsf_arg2l at;
      r := car w;
      for each x in cdr w do
         r := multf(r,expf(numr simp cdr assoc(car x,al),cdr x));
      return ofsf_0mk2(ofsf_op at,r)
   end;

procedure ofsf_termmlat(at);
   % Ordered field standard form term multiplicity list of atomic
   % formula. [at] is an atomic formula. Returns the multiplicity list
   % off all non-zero terms in [at].
   if ofsf_arg2l at then
      {(ofsf_arg2l at . 1)};

procedure ofsf_multsurep(at,atl);
   % Multiplicative sure predicate.
   if ofsf_op at eq 'equal then
      ofsf_multsurep!-equal(at,atl)
   else
      ofsf_multsurep!-neq(at,atl);

procedure ofsf_multsurep!-equal(at,atl);
   begin scalar c,a;
      c := ofsf_arg2l at;
      while atl do <<
         a := car atl;
         atl := cdr atl;
         if ofsf_op a eq 'equal and quotf(c,ofsf_arg2l a) then <<
            a := 'found;
            atl := nil
         >>
      >>;
      return a eq 'found
   end;

procedure ofsf_multsurep!-neq(at,atl);
   begin scalar c,a;
      c := ofsf_arg2l at;
      while atl do <<
         a := car atl;
         atl := cdr atl;
         if ofsf_op a eq 'neq and quotf(ofsf_arg2l a,c) then <<
            a := 'found;
            atl := nil
         >>
      >>;
      return a eq 'found
   end;

procedure ofsf_posvarp(f,v);
   % Positive variable predicate. [f] is a quanitfier-free formula, [v] is a
   % variable. Returns extended Boolean. Returns ['greaterp] (['geq]) if [f]
   % states that [v] is positive (non-negative), returns [nil] else.
   begin scalar op, argl, a, res;
      op := rl_op f;
      if op eq 'and then <<
         argl := rl_argn f;
         while not res and argl do <<
            a := pop argl;
            if not rl_cxp f then
               res := ofsf_posvarpat(a,v);
         >>;
         return res
      >>;
      return ofsf_posvarpat(f,v)
   end;

procedure ofsf_posvarpat(a,v);
   % Positive variable predicate atomic formula. [a] is an atomic formula, [v]
   % is a variable. Returns extended Boolean. Returns ['greaterp] (['geq]) if
   % [a] states that [v] is positive (non-negative), returns [nil] else.
   begin scalar op;
      op := rl_op a;
      if not memq(op,'(greaterp geq)) then
         return nil;
      if sfto_varp ofsf_arg2l a eq v then
         return op
   end;

procedure ofsf_posprep(f,resfnchkp);
   begin scalar op,posconds,qvl;
      f := cl_pnf f;
      while rl_quap(op := rl_op f) do <<
         if op eq 'all then
            rederr "pos methods admit only one existential quantifier block";
         qvl := rl_var f . qvl;
         f := rl_mat f
      >>;
      posconds := ofsf_posconds(cl_fvarl f,resfnchkp);
      f := rl_mkn('and,f . posconds);
      for each v in qvl do
         f := rl_mkq('ex,v,f);
      return f
   end;

procedure ofsf_posconds(l,resfnchkp);
   for each v in l join
      if resfnchkp and pairp v and ofsf_rxffn car v then
         for each w in lto_list2set ofsf_lpvarl v collect
            ofsf_0mk2('greaterp,!*k2f w)
      else
         {ofsf_0mk2('greaterp,!*k2f v)};

procedure ofsf_lpvarl(u);
   if idp u then
      {u}
   else if pairp u then
      if not (ofsf_opp car u or ofsf_arithp car u or ofsf_rxffn car u) then
         {!*a2k u}
      else
         for each arg in cdr u join
            ofsf_lpvarl arg;

procedure ofsf_arithp(op);
   op memq '(plus minus times expt quotient);

procedure ofsf_resolve(f);
   ofsf_resolve21(f,nil);

procedure ofsf_posresolve(f);
   ofsf_resolve21(ofsf_posprep(f,t),t);

procedure ofsf_resolve21(f,posp);
   begin scalar w;
      w := cl_apply2ats(f,function ofsf_resolve2topminmax);
      w := cl_simpl(w,nil,-1);
      % In the following line I rely on cl_resolve not to call
      % cl_simpl with non-resolved formulas. Otherwise, e.g.,
      % max(x+y,y+z)=0 would become false.
      w := cl_resolve w where !*rlpos=posp;
      w := cl_simpl(w,nil,-1) where !*rlpos=posp;
      return w
   end;

procedure ofsf_resolve2topminmax(at);
   begin scalar lhs,rel,op;
      rel := ofsf_op at;
      lhs := prepf ofsf_arg2l at;
      if not pairp lhs then
         return at;
      op := car lhs;
      if op eq 'minus then <<
         rel := ofsf_anegrel rel;
         lhs := cadr lhs;
         if not pairp lhs then
            return at;
         op := car lhs
      >>;
      if not (op memq '(min max) and rel memq '(lessp greaterp leq geq)) then
         return at;
      return ofsf_resolveminmax(rel,op,cdr lhs)
   end;

procedure ofsf_resolveminmax(rel,op,argl);
   begin scalar bop;
      bop := if op eq 'min and rel memq '(lessp leq) or
         op eq 'max and rel memq '(greaterp geq)
      then
         'or
      else
         'and;
      return rl_mkn(bop,for each arg in argl collect
         rl_simp {rel,arg,0})
   end;

procedure ofsf_rxffn!-abs(op,argl,condl,qll);
   if cdr argl then
      rederr {"ofsf_rxffn!-abs: length(argl)=",length argl}
   else if ofsf_surep(ofsf_0mk2('geq,ofsf_simpterm car argl),nil) then
      {rc_mk(car argl,'and . condl,lto_appendn qll)}
   else if ofsf_surep(ofsf_0mk2('lessp,ofsf_simpterm car argl),nil) then
      {rc_mk({'minus,car argl},'and . condl,lto_appendn qll)}
   else
      {rc_mk(
         car argl,
         'and . {'geq,car argl,0} . condl,
         lto_appendn qll),
       rc_mk(
         {'minus,car argl},
         'and . {'leq,car argl,0} . condl,
         lto_appendn qll)};

procedure ofsf_rxffn(op);
   if op eq 'max then
      'cl_rxffn!-max
   else if op eq 'min then
      'cl_rxffn!-max
   else if op eq 'abs then
      'ofsf_rxffn!-abs
   else if op eq 'sign then
      'cl_rxffn!-sign
   else if op eq 'sqrt then
      'cl_rxffn!-sqrt
   else
      nil;

procedure ofsf_tan2(f);
   cl_apply2ats(f,function ofsf_tan2at);

procedure ofsf_tan2at(f);
   ofsf_0mk2(ofsf_op f,numr ofsf_tan2f ofsf_arg2l f);

operator tan2;

procedure tan2(u);
   mk!*sq quotsq(ofsf_tan2f numr w,ofsf_tan2f denr w) where w=simp u;

procedure ofsf_tan2f(u);
   % Returns an SQ.
   if domainp u then
      !*f2q u
   else
      addsq(multsq(ofsf_tan2f lc u,exptsq(ofsf_tan2k mvar u,ldeg u)),
            ofsf_tan2f red u);

procedure ofsf_tan2k(k);
   if eqcar(k,'sin) then
      simp ofsf_tan2k!-sin k
   else if eqcar(k,'cos) then
      simp ofsf_tan2k!-cos k
   else if eqcar(k,'tan) then
      simp ofsf_tan2k!-tan k
   else if eqcar(k,'cot) then
      simp ofsf_tan2k!-cot k
   else if eqcar(k,'sec) then
      simp ofsf_tan2k!-sec k
   else if eqcar(k,'csc) then
      simp ofsf_tan2k!-csc k
   else
      !*k2q k;

procedure ofsf_tan2k!-sin(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'times,2,tt},{'plus,1,{'expt,tt,2}}}
   end;

procedure ofsf_tan2k!-cos(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'difference,1,{'expt,tt,2}},{'plus,1,{'expt,tt,2}}}
   end;

procedure ofsf_tan2k!-tan(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'times,2,tt},{'difference,1,{'expt,tt,2}}}
   end;

procedure ofsf_tan2k!-cot(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'difference,1,{'expt,tt,2}},{'times,2,tt}}
   end;

procedure ofsf_tan2k!-sec(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'plus,1,{'expt,tt,2}},{'difference,1,{'expt,tt,2}}}
   end;

procedure ofsf_tan2k!-csc(k);
   begin scalar tt;
      tt := ofsf_mktan2 cadr k;
      return {'quotient,{'plus,1,{'expt,tt,2}},{'times,2,tt}}
   end;

algebraic operator tn;

procedure ofsf_mktan2(phi);
   {'tan,{'quotient,phi,2}};

procedure ofsf_dfgPrintV(v);
   % DFG print variable.
   <<
      prin2 v;
      prin2 ":Real"
   >>;

procedure ofsf_dfgPrintAt(f);
   begin scalar opal,op,lhs,w;
      op := rl_op f;
      lhs := prepf ofsf_arg2l f;
      if op eq 'neq then
         cl_dfgPrintQff rl_mk1('not,ofsf_0mk2('equal, ofsf_arg2l f))
      else <<
         opal := '((lessp . ls) (leq . le) (greaterp . gs) (geq . ge));
         prin2(if w := atsoc(op,opal) then cdr w else op);
         prin2 "(";
         ofsf_dfgPrintT lhs;
         prin2 ",";
         prin2 "0)"
      >>
   end;

procedure ofsf_dfgPrintT(u);
   if numberp u or idp u then
      prin2 u
   else
      ofsf_dfgPrintT1(car u,cdr u);

procedure ofsf_dfgPrintT1(op,argl);
   if op eq 'minus then <<
      prin2 "minus(";
      prin2 "0";
      prin2 ",";
      ofsf_dfgPrintT car argl;
      prin2 ")"
   >> else if op eq 'difference then <<
      prin2 "minus(";
      ofsf_dfgPrintT car argl;
      prin2 ",";
      ofsf_dfgPrintT cadr argl;
      prin2 ")"
   >> else if op eq 'expt then <<
      prin2 "pow(";
      ofsf_dfgPrintT car argl;
      prin2 ",";
      ofsf_dfgPrintT cadr argl;
      prin2 ")"
   >> else <<  % op is plus or times
      if not cdr argl then
         ofsf_dfgPrintT car argl
      else <<
         prin2 if op eq 'times then "mult" else op;
         prin2 "(";
         ofsf_dfgPrintT car argl;
         prin2 ",";
         ofsf_dfgPrintT1(op,cdr argl);
         prin2 ")"
      >>
   >>;

procedure ofsf_smt2PrintLogic();
   prin2t "(set-logic QF_NRA)";

procedure ofsf_smt2PrintAt(f);
   begin scalar opal,op,lhs,w;
      op := rl_op f;
      lhs := prepf ofsf_arg2l f;
      if op eq 'neq then
         cl_smt2PrintQff rl_mk1('not,ofsf_0mk2('equal,ofsf_arg2l f))
      else <<
         opal := '((lessp . "<") (leq . "<=") (greaterp . ">") (geq . ">=")
            (equal . "="));
         prin2 "(";
         prin2(if w := atsoc(op,opal) then cdr w else op);
         prin2 " ";
         ofsf_smt2PrintT lhs;
         prin2 " 0)"
      >>
   end;

procedure ofsf_smt2PrintT(u);
   if numberp u or idp u then
      prin2 u
   else
      ofsf_smt2PrintT1(car u,cdr u);

procedure ofsf_smt2PrintT1(op,argl);
   if op eq 'difference then <<
      prin2 "(- ";
      ofsf_smt2PrintT car argl;
      prin2 " ";
      ofsf_smt2PrintT cadr argl;
      prin2 ")"
   >> else if op eq 'minus then <<
      prin2 "(- ";
      ofsf_smt2PrintT car argl;
      prin2 ")"
   >> else if op eq 'plus then <<
      prin2 "(+ ";
      for each rargl on argl do <<
         ofsf_smt2PrintT car rargl;
         if cdr rargl then
            prin2 " "
      >>;
      prin2 ")"
   >> else if op eq 'times then <<
      prin2 "(* ";
      for each rargl on argl do <<
         ofsf_smt2PrintT car rargl;
         if cdr rargl then
            prin2 " "
      >>;
      prin2 ")"
   >> else if op eq 'expt then
      ofsf_smt2PrintT1('times, for i:=1:cadr argl collect car argl);

procedure ofsf_smt2ReadAt(form);
   begin scalar op, w, lhs, rhs;
      op := car form;
      w := atsoc(op, '((!>!= . geq) (!<!= . leq) (!< . lessp) (!> . greaterp)
         (!= . equal)));
      if not w then
         error(99, lto_sconcat2(
            "expecting logic symbol but found ", id2string op));
      op := cdr w;
      lhs := ofsf_smt2ReadTerm cadr form;
      rhs := ofsf_smt2ReadTerm caddr form;
      return ofsf_0mk2(op, numr subtrsq(lhs, rhs))
   end;

procedure ofsf_smt2ReadTerm(u);
   simp ofsf_smt2ReadTerm1 u;

procedure ofsf_smt2ReadTerm1(u);
   begin scalar op, w;
      if atom u or eqcar(u, '!:dn!:) or eqcar(u, '_) then
         return u;
      op := car u;
      w := atsoc(op, '((!+ . plus) (!- . minus) (!* . times) (!/ . quotient)));
      if not w then
         error(99, lto_sconcat2(
            "expecting arithmetic symbol but found ", id2string op));
      op := cdr w;
      if op eq 'minus and cddr u then
         op := 'difference;
      return op . for each arg in cdr u collect ofsf_smt2ReadTerm1 arg
   end;

procedure ofsf_float2dn(x);
   begin scalar w; integer dotpos;
      w := explode x;
      dotpos := length memq('!., w);
      prin2t w;
      return '!:dn!: . compress(for each d in w join if not (d eq '!.) then {d}) . -dotpos
   end;

rl_provideService rl_dima = ofsf_dima;

procedure ofsf_dima(ql, p);
   % [ql] is a list of SF, [p] is an SF.
   begin scalar w, xl, yl, pt, qtl, ptt, sys, sl0, sl; integer k, n;
      for each q in ql do
         xl := union(kernels q, xl);
      xl := sort(xl, 'ordp);
      n := length xl;
      yl := kernels p;
      k := length yl;
      if k neq length ql then
         rederr {"size of Q does not match number of vars in P", k, length yl};
      if (w := intersection(xl, yl)) then
         rederr {w, "occur in both Q and P"};
      % Step 1:
      {xl, ql, yl, pt} := ofsf_dima!-p1(xl, ql, yl, p);  % (T1)
      qtl := ofsf_dima!-p2(xl, ql, k);  % (T2)
      ptt := ofsf_dima!-subf(pt, yl, qtl);  % (T3)
      ptt := addf(ptt, negf !*k2f 'epsilon1);
      % Step 2:
      sys := ofsf_dima!-mksys(xl, qtl, yl, pt);
      % Step 3:
      sl0 := ofsf_dima!-pgauss(sys, xl);
      % Step 4:
      sl := ofsf!-dima!-sol2formulas(ptt, sl0, yl);
      return sl
   end;

procedure ofsf_dima!-subf(f, vl, fl);
   begin scalar al, v, f1;
      while vl and fl do <<
         v := pop vl;
         f1 := !*f2q pop fl;
         al := (v . f1) . al
      >>;
      assert(null vl and null fl);
      return numr ofsf_siatsubf(f, al)
   end;

procedure ofsf_dima!-p1(xl, ql, yl, p);
   begin scalar y0, x0, pt, q0, s;
      y0 := '!_y0;  % intern gensym();
      yl := y0 . yl;
      pt := addf(exptf(!*k2f y0, 2), p);
      x0 := '!_x0;  % intern gensym();
      xl := x0 . xl;
      s := ofsf_dima!-sigma(for each x in xl collect 1, xl);
      q0 := addf(1, negf multf(exptf(!*k2f 'epsilon0, 2), s));
      ql := q0 . ql;
      return {xl, ql, yl, pt}
   end;

procedure ofsf_dima!-sigma(cl,xl);
   begin scalar xsql, s;
      xsql := for each x in xl collect exptf(!*k2f x, 2);
      while cl and xsql do
         s := addf(s, multf(pop cl, pop xsql));
      assert(null cl and null xsql);
      return s
   end;

procedure ofsf_dima!-p2(xl, ql, k);
   begin scalar qtl, cl; integer j, tn;
      tn := length xl;
      qtl := for j := 0:k collect <<
         cl := for i:=1 : tn collect i^j;
         addf(pop ql, multf(!*k2f 'epsilon2, ofsf_dima!-sigma(cl, xl)))
      >>;
      assert null ql;
      return qtl
   end;

switch rldimaincludefirst;

procedure ofsf_dima!-mksys(xl, qtl, yl, pt);
   begin scalar nablaqtl, nablapt, sys0, sys, llambda;
      nablapt := ofsf_dima!-gradient(pt, yl);
      nablaqtl := for each x in xl collect
         ofsf_dima!-partiall(qtl, x);
      sys0 := for each pvec in nablaqtl collect
         ofsf_dima!-sprod(nablapt, pvec);
      sys := for each f in cdr sys0 collect
         ofsf_0mk2('equal, f);
      if !*rldimaincludefirst then <<
         llambda := !*k2f intern gensym();
         sys := ofsf_0mk2('equal, addf(car sys0, negf llambda)) . sys
      >>;
      return sys
   end;

procedure ofsf_dima!-gradient(p, vl);
   for each v in vl collect diff(p,v);

procedure ofsf_dima!-partiall(pl, v);
   for each p in pl collect diff(p,v);

procedure ofsf_dima!-sprod(l1, l2);
   begin scalar sp;
      for each p in lto_zip(l1, l2, function multf) do
         sp := addf(sp,p);
      return sp
   end;

procedure ofsf_dima!-pgauss(eql, vl);
   begin scalar !*pgspsimpl, !*pgnoarbcomplex;
      !*pgspsimpl := t;
      !*pgnoarbcomplex := t;
      return pg_gauss!-sym(for each eq in eql collect rl_prepfof eq, vl)
   end;


procedure ofsf!-dima!-sol2formulas(ptt, sl0, yl);
   begin scalar phi, xl, vl, sl, w;
%%       xl := lto_list2set for each s in sl0 join
%%       for each pr in cdr s join
%%          nconc(kernels numr cdr pr, kernels denr cdr pr);
%%       vl := reversip append(yl, xl);
      sl := for each s in sl0 collect <<
         w :=  numr ofsf_siatsubf(ptt, cdr s);
         phi := rl_smkn('and, reverse(ofsf_0mk2('equal,w) . car s));
%%       for each v in vl do
%%          phi := rl_mkq('ex, v, phi);
         rl_ex(phi, '(epsilon0 epsilon1 epsilon2))
      >>;
      return sl
   end;

asserted procedure ofsf_symbolify(f: Formula): List2;
   begin scalar w;
      w := ofsf_symbolify1(f, 0, nil);
      return car w . reversip caddr w
   end;

asserted procedure ofsf_symbolify1(f: Formula, c: Integer, subl: Alist): List3;
   begin scalar op, w, nargl; integer c;
      op := rl_op f;
      if rl_tvalp op then
         return {f, c, subl};
      if rl_quap op then <<
         {w, c, subl} := ofsf_symbolify1(rl_mat f, c, subl);
         return {rl_mkq(op, rl_var f, w), c, subl}
      >>;
      if rl_boolp op then <<
         nargl := for each arg in rl_argn f collect <<
            {w, c, subl} := ofsf_symbolify1(arg, c, subl);
            w
         >>;
         return {rl_mkn(op, nargl), c, subl}
      >>;
      % [f] is an atomic formula.
      {w, c, subl} := sfto_symbolify1(ofsf_arg2l f, 'i, c, subl);
      return {ofsf_0mk2(op, w), c, subl}
   end;

rl_provideService rl_dump = ofsf_dump;

asserted procedure ofsf_dump(f: Formula, format: Id, fn: String);
   if format eq 'qepcad then
      qepcad_dump(f, fn, function qepcad_printer)
   else if format eq 'slfq then
      qepcad_dump(f, fn, function(lambda(x); mathprint rl_prepfof x))
   else if format eq 'mathematica then
      qepcad_dump(f, fn, function mma_printer)
   else if format eq 'dfg then
      cl_dfgPrint(f, fn)
   else if format eq 'smt2 then
      cl_smt2Print(f, fn, nil)
   else
      rederr {"rl_dump: format", format, "not known for domain real"};

endmodule;  % [ofsfmisc]

end;  % of file
