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

% flag('(pasf_simpmoddivc), 'full);
algebraic infix divc;
% put('divc, 'number!-of!-args, 2);
% put('divc, 'pasf_simpfn, 'pasf_simpmoddivc);
algebraic infix modc;
% put('modc, 'number!-of!-args, 2);
% put('modc, 'pasf_simpfn, 'pasf_simpmoddivc);

precedence divc, modc;
precedence modc, times;
% TODO: adjust precedence. Now a modc b > 0 is parsed correctly but a divc b > 0
% is not.

procedure pasf_rxffn!-modc(op, argl, condl, qll);
   begin scalar w, a, k;
      w := gensym();
      a := car argl;
      k := cadr argl;
      return {rc_mk(
	 w,
	 'and . {'cong, {'difference, w, a}, 0, k} .
	    {'geq, w, 0} . {'lessp, {'difference, w, k}, 0}  . condl,
	 ('ex . w) . lto_appendn qll)}
   end;

procedure pasf_rxffn!-divc(op, argl, condl, qll);
   begin scalar w, a, k;
      w := gensym();
      a := car argl;
      k := cadr argl;
      return {rc_mk(
	 w,
	 'and . {'leq, {'difference, {'times, w, k}, a}, 0} .
	    {'greaterp, {'plus, k, {'times, w, k}, {'minus, a}}, 0} . condl,
	 ('ex . w) . lto_appendn qll)};
   end;

% asserted procedure pasf_simpmoddivc(a: List): SF;
%    <<
%       if not numberp caddr a then
% 	 rederr "TODO!";
%       simpiden a
%    >>;

switch rlpasfdotrw;
on1 'rlpasfdotrw;

symbolic operator rlmdres;

procedure rlmdres(f);
   rl_prepfof pasf_mdres(rl_simp f);

asserted procedure pasf_mdres(f: List): List;
   % PASF mod div resolve. [f] is PASF formula. Returns equivalent PASF formula
   % without mod div symbols.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
	 return op;
      if rl_quap op then
	 return {op, rl_var f, pasf_mdres rl_mat f};
      if rl_bquap op then
     	 rederr{"pasf_mdres: Bounded quantifiers are not allowed."};
	 % return {op, rl_var f, pasf_mdres rl_mat f, rl_b f};
      if rl_boolp op then
	 return op . for each x in rl_argn f collect pasf_mdres x;
      % [f] is atomic PASF formula.
      return pasf_mdresat f
   end;

asserted procedure pasf_mdresat(atf: List): List;
   % PASF mod div resolve atomic formula. [atf] is PASF atomic formula. Returns
   % PASF formula.
   begin scalar op, w, nlhs, conds, res;
      % TODO: - Handle congruences separately, possibly allowing expressions in
      % moduli.
      op := pasf_op atf;
      w := pasf_mdressf pasf_arg2l atf;
      nlhs := car w;
      conds := cadr w;
      res := pasf_0mk2(op, nlhs);
      for each p in conds do
	 res := rl_mk2('and, res, caddr p);
      for each p in conds do
	 if not null cadr p then
	    res := rl_mkbq('bex, car p, cadr p, res)
	 else
	    res := rl_mkq('ex, car p, res);
      return res
   end;

asserted procedure pasf_mdressf(sf: SF): List2;
   % PASF mod div resolve standard form. Resolves [sf] removing mod div symbols
   % from it. Returns: first element of the returned list is new SF and the
   % second is a list of List3 {kernel, f1 / nil, f2}. [f1] will be put into
   % bound of a bounded quantifier. [f2] is an formula which will be added
   % conjunctively to the result.
   begin scalar w, newsf, prfal, sfal;
      if !*rlpasfdotrw then
	 w := pasf_mdrespf reval pasf_mdrestrw prepf sf
      else
      	 w := pasf_mdrespf prepf sf;
      newsf := numr simp car w;
      prfal := cadr w;
      while not null prfal do <<
	 sfal := pasf_mdreseqn car prfal . sfal;
	 prfal := cdr prfal
      >>;
      return {newsf, sfal}
   end;

asserted procedure pasf_mdrespf(pf: Any): List2;
   % PASF mod div resolve lisp prefix. Returns a 2 element list: 1st element is
   % a "purified" term and 2nd is an alist containing elements of the form
   % (kernel . lisp prefix) where lisp prefix contains exactly one mod div
   % symbol at topmost position.
   begin scalar op, argl, nargl, nal, w, nvar;
      if atom pf then
	 return {pf, nil};
      op := car pf;
      argl := cdr pf;
      while not null argl do <<
	 w := pasf_mdrespf car argl;
	 nargl := car w . nargl;
	 nal := nconc(nal, reversip cadr w);
	 argl := cdr argl
      >>;
      nargl := reversip nargl;
      if op memq '(modc divc) then <<
	 nvar := gensym();
	 w := op . nargl;
	 return {nvar, (nvar . w) . nal}
      >>;
      return {op . nargl, nal}
   end;

% x = (mod a b) equiv cong(x, a, b) and 0 <= x and x < b
% x = (div a b) equiv b*x <= a and a < b*(x+1)

asserted procedure pasf_mdreseqn(p: List2): List3;
   % PASF mod div resolve equation. [p] is a list, first element is a kernel and
   % the following elements are lisp prefix of the form (mod a b) or (div a b).
   % Returns a List3, first element is a kernel, second is a quantifier-free
   % PASF formula (bound) or nil, third is a quantifier-free PASF formula.
   begin scalar varsf, op, a, b, f;
      varsf := numr simp car p;
      op := cadr p;
      a := numr simp caddr p;
      b := numr simp cadddr p;
      if op eq 'modc then
	 return {car p,
	    rl_mk2('and, pasf_0mk2('geq, varsf),
	       pasf_mk2('lessp, varsf, b)),
	    pasf_mk2(pasf_mkop('cong, b), varsf, a)};
      if op eq 'divc then
	 return {car p,
	    nil,
	    rl_mk2('and,
	       pasf_mk2('leq, multf(b, varsf), a),
	       pasf_mk2('lessp, a, multf(b, addf(varsf, 1))))};
      % This should NOT happen!
      return nil
   end;

asserted procedure pasf_mdrestrw(pf: Any): Any;
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

endmodule;

end; % of file
