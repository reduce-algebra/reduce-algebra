on comp;

on lessspace;

load_package redlog;
rlset r;

lisp (switch smt2_debug);

lisp procedure setpchar(c);
   promptstring!* := "";

lisp procedure smt2_repl();
   begin scalar inp, w, phil, res;
      while (inp := read()) neq '(check!-sat) do
	 if eqcar(inp, 'assert) then <<
	    w := smt2_f2qff cadr inp;
 	    phil := w . phil;
	 >>;
      w := cl_ex(rl_smkn('and, phil),nil);
      if !*smt2_debug then prin2t w;
      res := ofsf_qe(w, nil);
      if !*smt2_debug then prin2t res;
      prin2t if res eq 'true then 'sat else 'unsat;
      quit
   end;

lisp procedure smt2_f2qff(form);
   begin scalar op, w;
      op := car form;
      if op eq '!=!> then
 	 op := 'impl;
      if op memq '(not impl) then
	 return rl_mkn(op, for each arg in cdr form collect smt2_f2qff arg);
      if op memq '(and or) then
	 return rl_smkn(op, for each arg in cdr form collect smt2_f2qff arg);
      w := atsoc(op, '((!>!= . geq) (!<!= . leq) (!< . lessp) (!> . greaterp)
   	 (!= . equal)));
      if not w then <<
	 smt2_errprin2 "error: expecting logical symbol but found ";
	 smt2_errprin2t op;
	 quit
      >>;
      op := cdr w;
      return ofsf_0mk2(op, addf(smt2_t2sf cadr form, negf(smt2_t2sf caddr form)))
   end;

lisp procedure smt2_t2sf(u);
   numr simp smt2_t2sf1(u);


lisp procedure smt2_t2sf1(u);
   begin scalar op, w;
      if atom u then
 	 return u;
      op := car u;
      w := atsoc(op, '((!+ . plus) (!- . minus) (!* . times)));
      if not w then <<
	 smt2_errprin2 "error: expecting arithmetic symbol but found ";
	 smt2_errprin2t op;
	 quit
      >>;
      op := cdr w;
      if op eq 'minus and cddr u then <<
	 smt2_errprin2t "error: found non-unary '-'";
	 quit
      >>;
      return op . for each arg in cdr u collect smt2_t2sf1 arg
   end;

lisp procedure smt2_errprin2(x);
   begin scalar w;
      w := wrs errout!*;
      prin2 x;
      wrs w
   end;

lisp procedure smt2_errprin2t(x);
   begin scalar w;
      w := wrs errout!*;
      prin2t x;
      wrs w
   end;

lisp savesystem("REDSMT", "rlsmt", '((smt2_repl)));

quit;
