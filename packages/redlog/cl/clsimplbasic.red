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
      cl_basicSimplify1(f, n, nil)
   >>;

asserted procedure cl_basicSimplify1(f: Formula, n: Integer, sop: Id): Formula;
   % Common logic basic simplify. [f] is a formula; [n] is an integer; [sop] is
   % a CL operator. Returns a formula. Simplifies [f] recursively.
   begin scalar op;
      if eqn(n, 0) then
         return f;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if op eq 'not then
         return cl_basicSimplifyNot(rl_arg1 f, n);
      if rl_junctp op then
         return cl_basicSimplifyGenericAnd(f, n);
      if rl_quap op then
         return cl_basicSimplifyQuantifier(f, n);
      if op eq 'impl then
         return cl_basicSimplifyImplication(rl_arg2l f, rl_arg2r f, n);
      if op eq 'repl then
         return cl_basicSimplifyImplication(rl_arg2r f, rl_arg2l f, n);
      if op eq 'equiv then
         return cl_basicSimplifyEquivalence(f, n);
      if rl_bquap op then
         return cl_basicSimplifyBoundedQuantifier(f, n);
      ASSERT( cl_atfp f );
      return cl_simplat(f, sop)
   end;

asserted procedure cl_basicSimplifyNot(f: Formula, n: Integer): List;
   begin scalar result;
      result := cl_basicSimplify1(rl_arg1 f, n-1, 'not);
      if rl_tvalp result then
         return cl_flip result;
      if cl_atfp result then
         return rl_negateat result;
      return cl_involutiveNot result
   end;

asserted procedure cl_basicSimplifyGenericAnd(f: Formula, n: Integer): Formula;
   % Common logic simplify generic and. The operator of f is 'and or 'or.
   % Returns a simplified equivalent of f. Simplifications proceeds
   % recursively and recognizes 'true, 'false, duplicate siblings, and nested
   % occurrences of 'and, 'or, respectively.
   begin scalar gand, gtrue, gfalse, result, al, a;
      gand := rl_op f;
      if gand eq 'and then <<
         gtrue := 'true;
         gfalse := 'false
      >> else <<
         gtrue := 'false;
         gfalse := 'true
      >>;
      al := rl_argn f;
   next: 
      while al do <<
         a := cl_basicSimplify1(pop al, n-1, gand);
         if a eq gtrue then
            goto next;
         if a eq gfalse then <<
            result := {gfalse};
            goto exit
         >>;
         if rl_op a eq gand then <<
            for each subf in rl_argn a do
               result := lto_insert(subf, result);
            goto next
         >>;
         result := lto_insert(a, result)
      >>;
   exit:
      return rl_smkn(gand, reversip result)
   end;

asserted procedure cl_basicSimplifyQuantifier(f: Formula, n: Integer): Formula;
   begin scalar q, x, w;
      q := rl_op f;
      x := rl_var f;
      w := cl_basicSimplify1(rl_mat f, n-1, q);
      if not (x memq cl_fvarl1 w) then
         return w;
      return rl_mkq(q, x, w)
   end;

asserted procedure cl_basicSimplifyBoundedQuantifier(f: Formula, n: Integer): Formula;
   begin scalar q, x, b, w;
      q := rl_op f;
      x := rl_var f;
      b := rl_bound f;
      w := cl_basicSimplify1(rl_mat f, n-1, q);
      return rl_mkbq(q, x, b, w)
   end;

asserted procedure cl_basicSimplifyImplication(prem: Formula, concl: Formula, n: Integer): Formula;
   begin
      prem := cl_basicSimplify1(prem, n-1, 'prem);
      if prem eq 'false then
         return 'true;
      concl := cl_basicSimplify1(concl, n-1, 'concl);
      if concl eq 'true then
         return 'true;
      if prem eq 'true then
         return concl;
      if concl eq 'false then
         return cl_basicSimplify1(rl_mk1('not, prem), 1, nil);
      if prem = concl then
         return 'true;
      return rl_mk2('impl, prem, concl)
   end;

asserted procedure cl_basicSimplifyEquivalence(f: Formula, n: Integer): Formula;
   begin scalar lhs, rhs;
      lhs := cl_basicSimplify1(rl_arg2l f, n-1, 'equiv);
      rhs := cl_basicSimplify1(rl_arg2r f, n-1, 'equiv);
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
