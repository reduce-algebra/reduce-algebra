module clsimplbasic;
% Common logic basic simplification. We eliminate duplicate subformulas, and
% treat "true" and "false" appropriately, but not much more. The motivation
% is that this is fast, and there is a chance that information from the input
% remains recognizable in the output. More sophisticated simplifications are
% implemented in module clsimpl.

revision('clsimplbasic, "$Id$");

copyright('clsimplbasic, "(c) 1995-2021 A. Dolzmann, T. Sturm");

rl_provideService rl_simplbasic = cl_simplbasic using rl_negateat, rl_simplat1;

asserted procedure cl_simplbasic(f: Formula, theory: List, n: Integer): Formula;
   <<
      ASSERT( not theory );
      cl_simplbasic1(f, n, nil)
   >>;

asserted procedure cl_simplbasic1(f: Formula, n: Integer, sop: Id): Formula;
   % Common logic basic simplify. [f] is a formula; [n] is an integer; [sop] is
   % a CL operator. Returns a formula. Simplifies [f] recursively.
   begin scalar op;
      if eqn(n,0) then
         return f;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if op eq 'not then
         return cl_simplbasic!-not(rl_arg1 f, n);
      if rl_junctp op then
         return cl_simplbasic!-gand(rl_argn f, n, op);
      if rl_quap op then
         return cl_simplbasic!-qua(rl_var f, rl_mat f, n, op);
      if op eq 'impl then
         return cl_simplbasic!-impl(rl_arg2l f, rl_arg2r f, n);
      if op eq 'repl then
         return cl_simplbasic!-impl(rl_arg2r f, rl_arg2l f, n);
      if op eq 'equiv then
         return cl_simplbasic!-equiv(rl_arg2l f, rl_arg2r f, n);
      if rl_bquap op then
         return cl_simplbasic!-bqua(rl_var f, rl_b f, rl_mat f, n, op);
      return cl_simplat(f,sop)
   end;

asserted procedure cl_simplbasic!-not(arg: Formula, n: Integer): List;
   begin scalar result;
      result := cl_simplbasic1(arg, n-1, 'not);
      if rl_tvalp result then
         return cl_flip result;
      if cl_atfp result then
         return rl_negateat result;
      return cl_involutiveNot result
   end;

asserted procedure cl_simplbasic!-gand(fl: List, n: Integer, gand: Id): List;
   % Common logic simplify generic ['and]. [fl] is a list of formulas; [n] is an
   % integer; [gand] is one of ['and], ['or]. Returns a list $l$ of simplified
   % formulas such that $[gand](l)$ is equivalent to $[gand]([fl])$. Moreover
   % there are no truth values in $l$, and no element of $l$ has [gand] as its
   % top-level operator.
   begin scalar result, a, gtrue, gfalse;
      gtrue := cl_cflip('true, gand eq 'and);
      gfalse := cl_flip gtrue;
      while fl do <<
         a := cl_simplbasic1(pop fl, n-1, gand);
         if a eq gfalse then <<
            result := {gfalse};
            fl := nil
         >> else if a neq gtrue then
            if rl_op a eq gand then
               for each subf in rl_argn a do
                  result := lto_insert(subf, result)
            else
               result := lto_insert(a, result)
      >>;
      return rl_smkn(gand, reversip result)
   end;

asserted procedure cl_simplbasic!-qua(x: Id, mtx: Formula, n: Integer, q: Id): List;
   begin scalar result;
      result := cl_simplbasic1(mtx, n-1, q);
      if not (x memq cl_fvarl1 result) then
         return result;
      return rl_mkq(q, x, result)
   end;

asserted procedure cl_simplbasic!-bqua(x: Id, b: Formula, mtx: Formula, n: Integer, q: Id): List;
   begin scalar result;
      result := cl_simplbasic1(mtx, n-1, q);
      return rl_mkbq(q, x, b, result)
   end;

asserted procedure cl_simplbasic!-impl(prem: Formula, concl: Formula, n: Integer): Formula;
   begin
      prem := cl_simplbasic1(prem, n-1, 'prem);
      if prem eq 'false then
         return 'true;
      concl := cl_simplbasic1(concl, n-1, 'concl);
      if concl eq 'true then
         return 'true;
      if prem eq 'true then
         return concl;
      if concl eq 'false then
         return cl_simplbasic1(rl_mk1('not, prem), 1, nil);
      if prem = concl then
         return 'true;
      return rl_mk2('impl, prem, concl)
   end;

asserted procedure cl_simplbasic!-equiv(lhs: Formula, rhs: Formula, n: Integer): Formula;
   begin
      lhs := cl_simplbasic1(lhs, n-1, 'equiv);
      rhs := cl_simplbasic1(rhs, n-1, 'equiv);
      if lhs eq 'true then
         return rhs;
      if rhs eq 'true then
         return lhs;
      if lhs eq 'false then
         return cl_involutiveNot rhs;
      if rhs eq 'false then
         return cl_involutiveNot lhs;
      if lhs = rhs then
         return 'true;
      return rl_mk2('equiv, lhs, rhs)
   end;

endmodule;

end;
