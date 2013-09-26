% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2013 M. Kosta, T. Sturm
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

module pasfresolve;

algebraic infix divc;
algebraic infix modc;

precedence modc, times;
precedence divc, modc;

% TODO: Define these two as redlog services.
symbolic operator rlelimmod;
symbolic operator rlelimcong;

procedure rlelimmod(f);
   rl_prepfof pasf_elimmod rl_simp f;

procedure rlelimcong(f);
   rl_prepfof pasf_elimcong rl_simp f;

% If on, universal quantifiers will be used in equivalent output formula.
% WARNING: in combination with other (except of modc and divc) function symbols
% this can lead to resolved output which is not equivalent with its non-resolved
% counterpart!
switch rlresolveuniversal;
off1 'rlresolveuniversal;

procedure pasf_resolve(f);
   % [f] is a PASF formula. Returns a PASF formula which does not contain
   % extended functions.
   cl_apply2ats(f, 'pasf_resolveat);

procedure pasf_resolveat(atf);
   % [f] is an atomic PASF formula. Returns a PASF formula which does not
   % contain extended functions.
   begin scalar w;
      w := rl_simp pasf_resolveat1 rl_prepfof atf;
      return if !*rlresi then cl_simpl(w,nil,-1) else w
   end;

procedure pasf_resolveat1(lpf);
   % [lpf] is a Presburger atomic formula in lisp prefix. Returns a Presburger
   % formula in lisp prefix without extended functions.
   begin scalar op,lhs,rrv;
      op := car lpf;
      lhs := cadr lpf;
      rrv := pasf_resolveterm lhs;
      % Reason for distinction between (n)cong and others is arity.
      if op memq '(ncong cong) then
	 op := op . cadddr lpf;
      if cdr rrv then
      	 return 'or . for each rc in rrv collect
	    pasf_transrc(op,rc);
      return pasf_transrc(op,car rrv)
   end;

procedure pasf_resolveterm(lpf);
   % [lpf] is a lisp prefix form of a term including extended functions. Returns
   % a RRV. See module clresolve for definition of RRV data structure.
   begin scalar op,fn,cprodl;
      if atom lpf then
	 return {rc_mk(lpf, 'true, nil)};
      op := car lpf;
      cprodl := cl_cartprod
	 for each arg in cdr lpf collect pasf_resolveterm arg;
      fn := rl_rxffn op;
      if not fn then
	 return cl_resolve!-simple(op, cprodl);
      return cl_resolve!-xfn(op, fn, cprodl)
   end;

procedure pasf_transrc(op,rc);
   begin scalar w;
      w := pasf_transrc1(op,rc);
      for each p in reverse rc_ql rc do
	 w := {car p,cdr p,w};
      return w
   end;

procedure pasf_transrc1(op,rc);
   if op memq '(equal neq) then
      {if !*rlresolveuniversal then 'impl else 'and,
	 rc_guard rc,
	 {op,rc_term rc,0}}
   else
      {if !*rlresolveuniversal then 'impl else 'and,
	 rc_guard rc,
	 if atom op then  % if op is not (n)cong
	    {op, rc_term rc, 0}
	 else  % op is (n)cong
	    {car op, rc_term rc, 0, cdr op}};

procedure pasf_rxffn(op);
   if op eq 'max then
      'cl_rxffn!-max
   else if op eq 'min then
      'cl_rxffn!-max
   else if op eq 'abs then
      'cl_rxffn!-abs
   else if op eq 'sign then
      'cl_rxffn!-sign
   else if op eq 'sqrt then
      'cl_rxffn!-sqrt
   else if op eq 'divc then
      'pasf_rxffn!-divc
   else if op eq 'modc then
      'pasf_rxffn!-modc
   else
      nil;

procedure pasf_rxffn!-modc(op, argl, condl, qll);
   begin scalar w, a, k, quant;
      w := gensym();
      a := car argl;
      k := cadr argl;
      quant := if !*rlresolveuniversal then 'all . w else 'ex . w;
      return {rc_mk(
	 w,
	 'and . {'greaterp, k, 0} .
	    {'cong, {'difference, w, a}, 0, k} .
	    {'geq, w, 0} . {'lessp, {'difference, w, k}, 0} . condl,
	 quant . lto_appendn qll)}
   end;

procedure pasf_rxffn!-divc(op, argl, condl, qll);
   begin scalar w, a, k, quant;
      w := gensym();
      a := car argl;
      k := cadr argl;
      quant := if !*rlresolveuniversal then 'all . w else 'ex . w;
      return {rc_mk(
	 w,
	 'and . {'greaterp, k, 0} .
	    {'leq, {'difference, {'times, w, k}, a}, 0} .
	    {'greaterp, {'plus, k, {'times, w, k}, {'minus, a}}, 0} . condl,
	 quant . lto_appendn qll)};
   end;

procedure pasf_elimmod(f);
   % [f] is a PASF formula. Returns a PASF formula which does not contain mod
   % function.
   cl_apply2ats(f, 'pasf_elimmodat);

procedure pasf_elimmodat(atf);
   % [f] is an atomic PASF formula. Returns a PASF formula which does not
   % mod function.
   begin scalar w;
      w := rl_simp pasf_elimmodat1 rl_prepfof atf;
      return if !*rlresi then cl_simpl(w,nil,-1) else w
   end;

procedure pasf_elimmodat1(lpf);
   % [lpf] is a Presburger atomic formula in lisp prefix. Returns a Presburger
   % formula in lisp prefix without mod function.
   begin scalar op, nlhs;
      op := car lpf;
      nlhs := pasf_elimmodterm cadr lpf;
      if op memq '(ncong cong) then
	 return {op, nlhs, 0, cadddr lpf};
      return {op, nlhs, 0}
   end;

procedure pasf_elimmodterm(pf);
   % PASF modulo elimination procedure. [pf] is a Presburger term in lisp
   % prefix. Returns a lisp prefix term which does not contain mod function.
   % Equation mod_k a = a - k*div_k a is used for this.
   begin scalar op, argl, nargl, res;
      if atom pf then
	 return pf;
      op := car pf;
      argl := cdr pf;
      while not null argl do <<
	 nargl := pasf_elimmodterm(car argl) . nargl;
	 argl := cdr argl
      >>;
      nargl := reverse nargl;
      % (modc a k) -> (difference a (times k (divc a k)))
      if op eq 'modc then <<
	 res := 'times . cadr(nargl) . {{'divc, car nargl, cadr nargl}};
	 res := 'difference . car(nargl) . {res};
	 return res
      >>;
      return op . nargl
   end;

procedure pasf_elimcong(f);
   % [f] is a PASF formula. Returns a PASF formula which does not contain cong
   % and ncong predicates.
   cl_apply2ats(f, 'pasf_elimcongat);

procedure pasf_elimcongat(atf);
   % [f] is an atomic PASF formula. Returns a PASF formula which does not
   % contain cong and ncong predicates.
   begin scalar w;
      w := pasf_elimcongat1 atf;
      return if !*rlresi then cl_simpl(w,nil,-1) else w
   end;

procedure pasf_elimcongat1(atf);
   % [f] is an atomic PASF formula. Returns a PASF formula which does not
   % contain cong and ncong predicates.
   begin scalar w, nlhs, m, res;
      if not pasf_congp atf then
	 return atf;
      w := gensym();
      m := pasf_m atf;
      nlhs := addf(pasf_arg2l atf, negf multf(m, !*k2f w));
      if pasf_opn atf eq 'cong then
      	 return rl_mkq('ex, w, pasf_0mk2('equal, nlhs));
      return rl_mkq('all, w, pasf_0mk2('neq, nlhs))
   end;

procedure pasf_elimcongat2(lpf);
   % [f] is an atomic Presburger formula in lisp prefix. Returns a Presburger
   % formula which does not contain cong and ncong predicates.
   begin scalar op, m, var, nlhs;
      op := car lpf;
      if not (op memq '(cong ncong)) then
	 return lpf;
      m := cadddr lpf;
      var := gensym();
      nlhs := {'difference, cadr lpf, caddr lpf};
      if op eq 'cong then
	 return {'ex, var, {'equal, nlhs, {'times, var, m}}};
      return {'all, var, {'neq, nlhs, {'times, var, m}}}
   end;

endmodule;

end; % of file
