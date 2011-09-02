module solve;   % Solve one or more algebraic equations.

% Author: David R. Stoutemyer.
% Major modifications by: David Hartley, Anthony C. Hearn, Herbert
% Melenk, Donald R. Morrison and Rainer Schoepf.

create!-package('(solve solve1 ppsoln solvelnr glsolve solvealg solvetab
		  quartic),nil);

% Other packages needed by solve package.

load!-package 'matrix;

fluid '(!*exp !*ezgcd !*multiplicities !!gcd dmode!* vars!*);

fluid '(inside!-solveeval solve!-gensymcounter);

% solve!-gensymcounter := 1;

global '(multiplicities!* assumptions requirements);

flag('(multiplicities!* assumptions requirements),
     'share);

% Those switches that are on are now set in entry.red.

% !*multiplicities      Lists all roots with multiplicities if on.
%  !!gcd                SOLVECOEFF returns GCD of powers of its arg in
%                       this.  With the decompose code, this should
%                       only occur with expressions of form x^n + c.

algebraic operator one_of;

put('arbint,'simpfn,'simpiden);

% algebraic operator arbreal;

symbolic operator expand_cases;

symbolic procedure simp!-arbcomplex u;
    simpiden('arbcomplex . u) where dmode!*=nil;

deflist('((arbcomplex simp!-arbcomplex)),'simpfn);


% ***** Utility Functions *****

symbolic procedure freeofl(u,v);
   null v or freeof(u,car v) and freeofl(u,cdr v);

symbolic procedure allkern elst;
   % Returns list of all top-level kernels in the list of standard
   % quotients elst.   Corrected 5 Feb 92 by Francis Wright.
   if null elst then nil
    else union(kernels numr car elst, allkern cdr elst);

symbolic procedure topkern(u,x);
   % Returns list of top level kernels in the standard form u that
   % contain the kernel x;
   for each j in kernels u conc if not freeof(j,x) then list j else nil;

symbolic procedure coeflis ex;
   % Ex is a standard form.  Returns a list of the coefficients of the
   % main variable in ex in the form ((expon . coeff) (expon . coeff)
   % ... ), where the expon's occur in increasing order, and entries do
   % not occur of zero coefficients.  We need to reorder coefficients
   % since kernel order can change in the calling function.
   begin scalar ans,var;
      if domainp ex then return (0 . ex);
      var := mvar ex;
      while not domainp ex and mvar ex=var do
	<<ans := (ldeg ex . reorder lc ex) . ans; ex := red ex>>;
      if ex then ans := (0 . reorder ex) . ans;
      return ans
   end;


% ***** Evaluation Interface *****

% Solvemethods!* is a list of procedures which are able to process
% one problem class. Each of its members must check itself
% whether it can be applied or not. The classical equation solver
% is called if none of the methods can contribute.
%
% Protocol:
%
%   input: PSOPFN standard, where the elements of the input list
%          have been passed through REVAL.
%
%   output:
%          'nil: the algorithm cannot be applied because the problem
%               belongs to a different problem class;
%          '(failed): the problem belongs to the class represented
%               by the algorithm but the program has been
%               unable to compute a result. The problem should
%               not be given to any other method - instead the
%               input should be returned.
%          result: the algorithm has been successful and the final
%               result is returned as algebraic form (including an
%               eventually empty result for an "inconsistent" case).

fluid '(solvemethods!*);

put('solve,'psopfn,'solveeval);

symbolic procedure solveeval u;
  begin scalar w,r,m;
    w:=for each q in u collect reval q;
    m:=solvemethods!*;
    while null r and m do
     <<r:=apply1(car m,w); m:=cdr m>>;
    return if null r then solveeval1 w
      else if eqcar(r,'failed) then 'solve.u
      else r;
  end;

% Links to other packages.

symbolic procedure odesolve!* u;
   % 2 arg solve => algebraic always (otherwise cannot algebraically
   % solve an equation involving a derivative!)
   length u neq 2 and smemq('df,u) and
   <<load!-package 'odesolve;
     % Support both "old" ODESOLVE and ODESolve 1.04+:
     if flagp('odesolve, 'opfn) and length u neq 3 then '(failed)
      else aeval('odesolve . u)>>;

solvemethods!* := union('(odesolve!*),solvemethods!*);

symbolic procedure solveeval1 u;
   begin scalar !*ezgcd,!!gcd,vars!*;  integer nargs;
      if atom u then rerror(solve,1,"SOLVE called with no equations")
       else if null dmode!* then !*ezgcd := t;
      nargs := length u;
      if not inside!-solveeval then 
      <<solve!-gensymcounter := 1; 
        assumptions :=requirements:={'list}>>;
      u := (if nargs=1 then solve0(car u,nil)
              else if nargs=2 then solve0(car u, cadr u)
              else <<lprim "Please put SOLVE unknowns in a list";
                     solve0(car u,'list . cdr u)>>)
             where inside!-solveeval = t, !*resimp = not !*exp;
      if not inside!-solveeval then
      <<assumptions := solve!-clean!-info(assumptions,t);
        requirements:= solve!-clean!-info(requirements,nil)>>;
      return !*solvelist2solveeqlist u
    end;

symbolic procedure !*solvelist2solveeqlist u;
   begin scalar x,y,z;
      for each j in u do
         <<if caddr j=0 then rerror(solve,2,"zero multiplicity")
            else if null cadr j
             then  x := for each k in car j collect
                                               list('equal,!*q2a k,0)
            else x := for each k in pair(cadr j,car j)
                          collect list('equal,car k,!*q2a cdr k);
           if length vars!* > 1 then x := 'list . x else x := car x;
           z := (caddr j . x) . z>>;
      z := sort(z,function ordp);
      x := nil;
      if !*multiplicities
	 then <<for each k in z do for i := 1:car k do x := cdr k . x;
		multiplicities!* := nil>>
       else <<for each k in z do << x := cdr k . x; y := car k . y>>;
	      multiplicities!* := 'list . reversip y>>;
      % Now check for redundant solutions.
%     if length vars!*>1 then z := check_solve_redundancy z;
      return 'list . reversip x
   end;

% symbolic procedure check_solve_redundancy u;
%     % We assume all solutions are prefixed by LIST.
%     begin scalar x,y;
%        x := for each j in u collect cdr j;   %  Remove the LIST.
%        for each j in u do if not supersetlist(cdr j,x) then y:= j . y;
%        return reversip!* y
%     end;

% symbolic procedure supersetlist(u,v);
%    % Returns true if u is a non-equal superset of any element of v.
%    v and
%      (u neq car v and null setdiff(car v,u) or supersetlist(u,cdr v));

endmodule;

end;
