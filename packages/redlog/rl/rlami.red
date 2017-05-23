module rlami;
% Reduce logic component algebraic mode interface. Submodule of [redlog].

revision('rlami, "$Id$");

copyright('rlami, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2017 T. Sturm");

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

procedure rl_mk!*fof(u);
   % Reduce logic make tagged form of first-order formula. [u] is a
   % first-order formula. Returns pseudo Lisp prefix of [u]. This is
   % analogous to [mk!*sq] in [alg.red].
   rl_mk!*fof1 rl_csimpl u;

procedure rl_mk!*fof1(u);
   % Reduce logic make tagged form of first-order formula subroutine.
   % [u] is a first-order formula. Returns pseudo Lisp prefix of [u].
   % This is analogous to [mk!*sq] in [alg.red].
   if rl_tvalp u then
      u
   else if eqcar(u,'equal) then
      rl_prepfof1 u
   else
      '!*fof . rl_cid!* . u . if !*resubs then !*sqvar!* else {nil};

procedure rl_reval(u,v);
   % Reduce logic [reval]. [u] is a formula in some mixed pseudo Lisp
   % prefix form where [car u] is either ['!*fof] or a first-order
   % operator; [v] is bool. Returns Lisp prefix of [u] in case [v] is
   % non-[nil], and pseudo Lisp prefix of [u] else.
   if v then rl_prepfof rl_simp1 u else rl_mk!*fof rl_simp1 u;

procedure rl_csimpl(u);
   % Conditional simplify.
   if !*rlsimpl and getd 'rl_simpl then %???
      rl_simpl(u,{},-1)
   else
      u;

procedure rl_prepfof(f);
   % [prep] first-order with bounded quantifers formula.
   rl_prepfof1 rl_csimpl f;

procedure rl_prepfof1(f);
   % [prep] first-order formula with bounded quantifers subroutine.
   begin scalar op,w;
      op := rl_op f;
      if rl_tvalp op then
 	 return op;
      if rl_quap op then
	 return {op,rl_var f,rl_prepfof1 rl_mat f};
      if rl_bquap op then
	 return {op,rl_var f,rl_prepfof1 rl_b f,rl_prepfof1 rl_mat f};
      if rl_boolp op then
	 return op . for each x in rl_argn f collect rl_prepfof1 x;
      if (w := rl_external(op,'rl_prepfof1)) then
	 return apply(w,{f});
      % [f] is atomic.
      return apply(get(car rl_cid!*,'rl_prepat),{f})
   end;

asserted procedure rl_cleanup(u: Any, v: ExtraBoolean): Any;
   % This is bound to the property [cleanupfn] of the rl_service!$ functions
   % that are in turn the [psopfn] of the corresponding rlservice AM
   % entrypoints. The [cleanupfn] is used with the evaluation of [psopfn] in
   % [reval1] in [alg/reval.red], where it converts - in the right moment - the
   % result of of rl_service!$ to Lisp prefix so that [part(rlservice(...),
   % ...)] works properly. However, the final evaluation result is generally
   % Pseudo Lisp Prefix.
   reval1(u,v);

procedure rl_simpa(u);
   % simp an answer structure
   for each a in cdr reval u collect
      {rl_simp cadr a,
	 for each b in cdaddr a collect
	    rl_simp b, cdr cadddr a};

procedure rl_simp(u);
   % [simp] first-order formula.
   rl_csimpl rl_simp1 u;

procedure rl_simp1(u);
   % Reduce logic [simp]. [u] is (pseudo) Lisp prefix of a formula.
   % Returns the formula encoded by [u].
   begin scalar w, h;
      if null rl_cid!* then rederr {"select a context"};
      if atom u then
 	 return rl_simpatom u;
      argnochk u where !*strict_argcount = t;
      if (w := get(car u, 'rl_simpfn)) then
 	 return if flagp(w, 'full) then apply(w, {u}) else apply(w, {cdr u});
      if (w := get(car u, get(car rl_cid!*, 'simpfnname))) then
	 return if flagp(w, 'full) then apply(w, {u}) else apply(w, {cdr u});
      if (w := get(car u, 'psopfn)) then <<
	 % u = (replaceby x 1) will return itself via a psopfn equalreplaceby.
	 h := apply1(w, cdr u);
	 if h neq u then
 	    return rl_simp1 h
      >>;
      if flagp(car u, 'opfn) then
	 return rl_simp1 apply(car u, for each x in cdr u collect reval x);
      if (w := get(car u, 'prepfn2)) then
 	 return rl_simp1 apply(w, {u});
      h := ioto_form2str car u;
      if (w := get(car u, 'prtch)) then
	 h := lto_sconcat {ioto_form2str w, " (", h, ")"};
      redmsg(h, "predicate");
      put(car u, get(car rl_cid!*, 'simpfnname), get(car rl_cid!*, 'simpdefault));
      return rl_simp1(u)
   end;

procedure rl_simpatom(u);
   % Reduce logic simp atom. [u] is an atom.
   begin scalar w;
      if null u then typerr("nil","logical");
      if numberp u then typerr({"number",u},"logical");
      if stringp u then typerr({"string",u},"logical");
      if rl_tvalp u then return u;
      if (w := rl_gettype(u)) then <<
	 if w memq '(logical equation scalar slprog) then
	    return rl_simp1 cadr get(u,'avalue);
	 typerr({w,u},"logical")
      >>;
      % [u] algebraically unbound.
      if boundp u then return rl_simp1 eval u;
      typerr({"unbound id",u},"logical")
   end;

procedure rl_simpbop(f);
   % Reduce logic simp boolean operator.
   rl_mkn(car f,for each x in cdr f collect rl_simp1 x);

procedure rl_simpq(f);
   % Reduce logic simp quantifier.
   begin scalar vl,w;
      vl := reval cadr f;
      if eqcar(vl,'list) then
	 vl := cdr vl
      else
	 vl := {vl};
      w := rl_simp1 caddr f;
      for each x in reverse vl do <<
      	 rl_qvarchk x;
	 w := rl_mkq(car f,x,w)
      >>;
      flag(vl,'used!*);
      return w
   end;

procedure rl_simpbq(f);
   % Reduce logic simp bounded quantifier. [f] is a list [(Q,x,b,f)]
   % where [Q] is a quantifier, [x] is an id, and [b] and [f] are
   % lisp-prefix. Returns a bounded quantifier headed formula.
   begin scalar x,wb,wf;
      if car rl_cid!* neq 'pasf then
	 rederr "boundend quantifiers only allowed within PASF context";
      x := reval cadr f;
      if not idp x then typerr("not identifer","bounded quantified variable");
      wb := rl_simp1 caddr f;
      %%% test, wether x is the only free variable in [wb].
      wf := rl_simp1 cadddr f;
      % Test, wether the bounded quantifier has a finite solution set.
      % rl_bsatp fails per definition if that is not the case.
      rl_bsatp(wb,x);
      flag({x},'used!*);
      return rl_mkbq(car f,x,wb,wf)
   end;

procedure rl_qvarchk(v);
   % Syntax-check quantified variable.
   if not sfto_kernelp v or (!*rlbrkcxk and pairp v) then
      typerr(v,"quantified variable");

procedure rl_simp!*fof(u);
   % Reduce logic simp [!*fof] operator. [u] is of the form
   % $([tag],f,[!*sqvar!*])$ where [tag] is a context tag and $f$ is a
   % formula.
   begin scalar tag,f,w;
      if caddr u then return cadr u;  % [!*sqvar!*=T]
      tag := car u;
      f := cadr u;
      if tag neq rl_cid!* then <<
	 w := rl_set tag where !*msg=nil;
	 f := rl_prepfof f;
	 rl_set w where !*msg=nil;
	 return rl_simp f
      >>;
      return rl_resimp f
   end;

procedure rl_resimp(u);
   % Reduce logic resimp. [u] is a formula.
   begin scalar op,w;
      op := rl_op u;
      if rl_tvalp op then
	 return u;
      if rl_quap op then <<
      	 if (w := rl_gettype(rl_var u)) then
 	    typerr({w,rl_var u},"quantified variable");
	 rl_qvarchk rl_var u;
      	 return rl_mkq(op,rl_var u,rl_resimp rl_mat u)
      >>;
      if rl_bquap op then <<
      	 if (w := rl_gettype(rl_var u)) then
 	    typerr({w,rl_var u},"quantified variable");
      	 return rl_mkbq(op,rl_var u,rl_resimp rl_b u,rl_resimp rl_mat u)
      >>;
      if rl_boolp op then
	 return rl_mkn(op,for each x in rl_argn u collect rl_resimp x);
      if (w := rl_external(op,'rl_resimp)) then
	 return apply(w,{u});
      return apply(get(car rl_cid!*,'rl_resimpat),{u})
   end;

procedure rl_gettype(v);
   % Get type. Return type information if present. Handle scalars
   % properly.
   (if w then car w else get(v,'rtype)) where w = get(v,'avalue);

procedure rl_lengthlogical(u);
   rl_lengthfof rl_simp u;

procedure rl_lengthfof(f);
   % First order formula length. [u] is a formula. Returns the number
   % of top-level constituents of [u].
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
	 return 1;
      if rl_quap op then
	 return 2;
      if rl_bquap op then
	 return 3;
      if rl_cxp op then
	 return length rl_argn f;
      % [f] is atomic.
      return apply(get(car rl_cid!*,'rl_lengthat),{f})
   end;

procedure rl_sub!*fof(al,f);
   rl_mk!*fof rl_subfof(al,rl_simp f);


foractions!* := 'mkand . 'mkor . foractions!*;
deflist('((mkand rlmkand) (mkor rlmkor)),'bin);
deflist('((mkand (quote true)) (mkor (quote false))),'initval);

symbolic operator rlmkor,rlmkand;

procedure rlmkor(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkor' invalid in symbolic mode"
   else <<
      if null a then a := 'false;
      if null b then b := 'false;
      a := if eqcar(a,'or) then cdr a else {a};
      b := if eqcar(b,'or) then cdr b else {b};
      'or . nconc(b,a)
   >>;

procedure rlmkand(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkand' invalid in symbolic mode"
   else <<
      if null a then a := 'true;
      if null b then b := 'true;
      a := if eqcar(a,'and) then cdr a else {a};
      b := if eqcar(b,'and) then cdr b else {b};
      'and . nconc(b,a)
   >>;

endmodule;  % [rlami]

end;  % of file
