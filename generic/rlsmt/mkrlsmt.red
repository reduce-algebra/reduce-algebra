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
	    w := rl_smt2Read cadr inp;
 	    phil := w . phil;
	 >>;
      w := cl_ex(rl_smkn('and, phil),nil);
      if !*smt2_debug then prin2t w;
      res := ofsf_qe(w, nil);
      if !*smt2_debug then prin2t res;
      prin2t if res eq 'true then 'sat else 'unsat;
      quit
   end;

lisp procedure cl_smt2ReadError(l);
   begin scalar w;
      w := wrs errout!*;
      for each x in l do prin2 x;
      terpri();
      wrs w;
      quit
   end;

lisp savesystem("REDSMT", "rlsmt", '((smt2_repl)));

quit;
