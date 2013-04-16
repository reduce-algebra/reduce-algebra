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

precedence divc, modc;
precedence modc, times;
% TODO: adjust precedence. Now a modc b > 0 is parsed correctly but a divc b > 0
% is not.

% Term rewriting before resolving.
switch rlresolvetrw;
off1 'rlresolvetrw;

% If on, universal quantifiers will be used in equivalent output formula.
% WARNING: in combination with other (except of modc and divc) function symbols
% this can lead to resolved output which is not equivalent with its non-resolved
% counterpart!
switch rlresolveuniversal;
off1 'rlresolveuniversal;

procedure pasf_resolve(f);
   cl_apply2ats(f, 'pasf_resolveat);

procedure pasf_resolveat(atf);
   begin scalar w;
      w := rl_simp pasf_resolveat1 rl_prepfof atf;
      return if !*rlresi then cl_simpl(w,nil,-1) else w
   end;

procedure pasf_resolveat1(lpf);
   % lpf is an atomic formula in lisp prefix representation. returns a
   % lisp prefix formula without extended functions.
   begin scalar op,lhs,rrv;
      op := car lpf;
      lhs := cadr lpf;
      if !*rlresolvetrw then % Rewrite mods using divs
	 lhs := prepf numr simp pasf_mdrestrw lhs;
      rrv := pasf_resolveterm lhs;
      % reason for distinction between (n)cong and others is arity
      if op memq '(ncong cong) then
	 op := op . cadddr lpf;
      if cdr rrv then
      	 return 'or . for each rc in rrv collect
	    pasf_transrc(op,rc);
      return pasf_transrc(op,car rrv)
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
	 if atom op then % if op is not (n)cong
	    {op, rc_term rc, 0}
	 else % op is (n)cong
	    {car op, rc_term rc, 0, cdr op}};

procedure pasf_resolveterm(lpf);
   % lpf is a lisp prefix form of a term including extended functions.
   % Returns a RRV.
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

procedure pasf_mdrestrw(pf);
   % PASF mod div resolve term rewriting procedure. [pf] is lisp prefix. Returns
   % lisp prefix representing term after the application of the rewrite rules.
   begin scalar op, argl, nargl, res;
      if atom pf then
	 return pf;
      op := car pf;
      argl := cdr pf;
      while not null argl do <<
	 nargl := pasf_mdrestrw(car argl) . nargl;
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



endmodule;

end; % of file
