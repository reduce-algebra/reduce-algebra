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

% asserted procedure pasf_simpmoddivc(a: List): SF;
%    <<
%       if not numberp caddr a then
% 	 rederr "TODO!";
%       simpiden a
%    >>;

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
      if rl_boolp op then
	 return op . for each x in rl_argn f collect pasf_mdres x;
      % [f] is atomic PASF formula.
      return pasf_mdresat f
   end;

asserted procedure pasf_mdresat(atf: List): List;
   % PASF mod div resolve atomic formula. [atf] is PASF atomic formula. Returns
   % PASF formula.
   begin scalar op, w, nlhs, nrhs, ncond, res;
      % TODO: - Handle congruences separately, possibly allowing expressions in
      % moduli.
      op := pasf_op atf;
      w := pasf_mdressf pasf_arg2l atf;
      nlhs := car w;
      ncond := cadr w;
      w := pasf_mdressf pasf_arg2r atf;
      nrhs := car w;
      ncond := nconc(ncond, cadr w);
      res := pasf_mk2(op, nlhs, nrhs);
      for each p in ncond do
	 res := rl_mk2('and, res, cadr p);
      for each p in ncond do
	 res := rl_mkq('ex, car p, res);
      return res
   end;

asserted procedure pasf_mdressf(sf: SF) : List2;
   % PASF mod div resolve standard form. Resolves [sf] removing mod div symbols
   % from it. Returns: first element of the returned list is new SF and the
   % second is a list of pairs (kernel . first-order formula).
   begin scalar tmp, newsf, prfal, sfal;
      tmp := pasf_mdrespf prepf sf;
      newsf := numr simp car tmp;
      prfal := cadr tmp;
      sfal := {};
      while not null prfal do <<
	 sfal := pasf_mdreseqn(car prfal) . sfal;
	 prfal := cdr prfal
      >>;
      return {newsf, sfal}
   end;

asserted procedure pasf_mdrespf(pf: Any): List2;
   % PASF mod div resolve lisp prefix. Returns a 2 element list: 1st element is
   % a "purified" term and 2nd is an alist containing elements of the form
   % (kernel . lisp prefix) where lisp prefix contains exactly one mod div
   % symbol at topmost position.
   begin scalar op, argl, nargl, nal, tmp, a;
      if atom pf then
	 return {pf, {}};
      op := car pf;
      argl := cdr pf;
      nargl := {};
      nal := {};
      while not null argl do <<
	 tmp := pasf_mdrespf car argl;
	 nargl := car tmp . nargl;
	 nal := append(nal, cadr tmp);
	 argl := cdr argl
      >>;
      nargl := reverse nargl;
      if op memq '(modc divc) then <<
	 a := gensym();
	 tmp := op . nargl;
	 return {a, (a . tmp) . nal}
      >>;
      return {op . nargl, nal}
   end;

% x = (mod a b) equiv cong(x, a, b) and 0 <= x and x < b
% x = (div a b) equiv b*x <= a and a < b*(x+1)

asserted procedure pasf_mdreseqn(p: List2): List2;
   % PASF mod div resolve equation. [p] is a list, first element is a kernel and
   % second list prefix of the form (mod a b) or (div a b). Returns a List2,
   % first elements is a kernel, second is quantifier-free PASF formula.
   begin scalar var, op, a, b, f;
      var := numr simp car p;
      op := cadr p;
      a := numr simp caddr p;
      b := numr simp cadddr p;
      if op eq 'modc then <<
	 f := rl_mkn('and, {pasf_mk2(pasf_mkop('cong, b), var, a),
	    pasf_mk2('leq, 0, var),
	    pasf_mk2('lessp, var, b)});
	 return {car p, f}
      >>;
      if op eq 'divc then <<
	 f := rl_mkn('and, {pasf_mk2('leq, multf(b, var), a),
	    pasf_mk2('lessp, a, multf(b, addf(var, 1)))});
	 return {car p, f}
      >>;
      % This should NOT happen!
      return nil
   end;

endmodule;

end; % of file
