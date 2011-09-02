module primitive; % Include primitive module alterations to solve.

fluid '(!*cramer bareiss!-step!-size!*);

symbolic procedure primitivesf(xl,vl);
   % xl:list of sf, vl:list of kernel -> primitivesf:sf
   % Returns each x in xl divided by gcd of the coefficients of vl.
   % x is ordered wrt vl, and linear in vl.
   foreach x in xl collect
      quotf!*(x,coeffgcd(x,vl));

symbolic procedure coeffgcd(x,vl);
   % x:sf, vl:list of kernel -> coeffgcd:sf
   % returns gcd of coefficients of vl (including degree 0) in x
   if domainp x or not(mvar x memq vl) then x
   else if null red x then lc x
   else gcdf(lc x,coeffgcd(red x,vl));

symbolic procedure solvelnrsys(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvelnrsys: tagged solution list
   % Check the system for sparsity, then decide whether to use the
   % Cramer or Bareiss method.  Using the Bareiss method on sparse
   % systems, 4-step elimination seems to be faster than 2-step.
   % The Bareiss code is not good at handling surds at the moment,
   % hence exptexpflistp test.
   begin scalar w,method;
   exlis := primitivesf(exlis,varlis);
   if w := solvesparsecheck(exlis,varlis) then exlis := w
     else exlis := exlis . varlis;
   if null !*cramer and null exptexpflistp exlis
      then method := 'solvebareiss
     else method := 'solvecramer;
   exlis := apply2(method,car exlis,cdr exlis)
	       where bareiss!-step!-size!* = if w then 4 else 2;
   return solvesyspost(exlis,varlis);
   end;

endmodule;

end;
