module /ure solsolve;   % Solve one or more algebraic equations.

% Author: David R. Stoutemyer.
% Major modifications by: David Hartley, Anthony C. Hearn, Herbert
% Melenk, Donald R. Morrison and Rainer Schoepf.

create!-package('(solve ppsoln solvelnr glsolve solvealg solvetab
                  quartic),nil);

% Other packages needed by solve package.

load!-package 'matrix;

fluid '(!*allbranch !*arbvars !*exp !*ezgcd !*fullroots !*limitedfactors
        !*multiplicities !*notseparate !*numval !*numval!* !*rounded
        !*solvealgp !*solvesingular !*varopt !!gcd !:prec!: asymplis!*
        alglist!* dmode!* kord!* vars!* !*!*norootvarrenamep!*!*);

% NB: !*!*norootvarrenamep!*!* is internal to this module, and should
%     *never* be changed by a user.

fluid '(inside!-solveeval solve!-gensymcounter);

solve!-gensymcounter := 1;

global '(!!arbint multiplicities!* assumptions requirements);

switch allbranch,arbvars,fullroots,multiplicities,solvesingular;
       % varopt,nonlnr.

!*varopt := t;

put('fullroots,'simpfg,'((t (rmsubs))));

flag('(!*allbranch multiplicities!* assumptions requirements),
     'share);

% ***** Some Non-local variables *****

!*allbranch     := t; % Returns all branches of solutions if T.
!*arbvars       := t; % Presents solutions to singular systems
                      % in terms of original variables if NIL
% !*multiplicities      Lists all roots with multiplicities if on.
% !*fullroots   := t; % Computes full roots of cubics and quartics.
!*solvesingular := t; % Default value.
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

put('solve,'psopfn,'solvemaster);

symbolic procedure solvemaster u;
  begin scalar w,r,m;
    w:=for each q in u collect reval q;
    m:=solvemethods!*;
    while null r and m do
     <<r:=apply1(car m,w); m:=cdr m>>;
    return if null r then solveeval w
      else if eqcar(r,'failed) then 'solve.u
      else r;
  end;

symbolic procedure solveeval u;
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

symbolic procedure solve!-gensym();
  begin
    scalar w;
    w := explode solve!-gensymcounter;
    solve!-gensymcounter := solve!-gensymcounter+1;
    while length w < 4 do w := '!0 . w;
    % If users have things to solve with names like G0001 in them, there
    % could be confusion.
    return compress ('g . w)
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

symbolic procedure supersetlist(u,v);
   % Returns true if u is a non-equal superset of any element of v.
   v and
     (u neq car v and null setdiff(car v,u) or supersetlist(u,cdr v));


% ***** Fundamental SOLVE Procedures *****

Comment most of these procedures return a list of "solve solutions".  A
   solve solution is a list with three fields: the list of solutions,
   the corresponding variables (or NIL if the equations could not be
   solved --- in which case there is only one solution in the first
   field) and the multiplicity;

symbolic procedure solve0(elst,xlst);
   % This is the driving function for the solve package.
   % Elst is any prefix expression, including a list prefixed by LIST.
   % Xlst is a kernel or list of kernels.  Solves eqns in elst for
   % vars in xlst, returning either a list of solutions, a single
   % solution, or NIL if the solutions are inconsistent.
   begin scalar !*exp,!*notseparate,w;  integer neqn;
   !*exp := !*notseparate := t;
   % Form a list of equations as expressions.
   elst := for each j in solveargchk elst collect simp!* !*eqn2a j;
   neqn := length elst;   % There must be at least one.
   % Determine variables.
   if null xlst
     then <<vars!* := solvevars elst;
            terpri();
            if null vars!* then nil
             else if cdr vars!*
              then <<prin2!* "Unknowns: "; maprin('list . vars!*)>>
             else <<prin2!* "Unknown: "; maprin car vars!*>>;
            terpri!* nil>>
    else <<xlst := solveargchk xlst;
           vars!* := for each j in xlst collect !*a2k j>>;
   if length vars!* = 0
     then rerror(solve,3,"SOLVE called with no variables");
   if neqn = 1 and length vars!* = 1
      then if null numr car elst
              then return if !*solvesingular
                          then {{{!*f2q makearbcomplex()},vars!*,1}}
                          else nil
              else if solutionp(w := solvesq(car elst,car vars!*,1))
                      or null !*solvealgp
                      or univariatep numr car elst
                      then return w;
   % More than one equation or variable, or single eqn has no solution.
    elst := for each j in elst collect numr j;
    w := solvesys(elst,vars!*);
    if null w then return nil;
    if car w memq {'t,'inconsistent,'singular} then return cdr w
     else if car w eq 'failed or null car w
      then return for each j in elst collect list(list(j ./ 1),nil,1)
     else errach list("Improper solve solution tag",car w)
   end;

symbolic procedure basic!-kern u;
   <<for each k in u do w:=union(basic!-kern1 k,w); w>> where w=nil;

symbolic procedure basic!-kern1 u;
   % Expand a composite kernel.
   begin scalar w;
      if atom u then return {u} else
       if algebraic!-function car u and
        (w := allbkern for each q in cdr u collect simp q)
        then return w
       else return {u}
   end;

symbolic procedure algebraic!-function q;
 % Returns T if q is a name of an operator with algebraic evaluation
 % properties.
   flagp(q,'realvalued) or
      flagp(q,'alwaysrealvalued) or
      get(q,'!:rd!:) or
      get(q,'!:cr!:) or
      get(q,'opmtch);

symbolic procedure allbkern elst;
 % extract all elementary kernels from list of quotients.
  if null elst then nil else
   union(basic!-kern kernels numr car elst, allbkern cdr elst);

symbolic procedure solvevars elst;
 <<for each j in allbkern elst do
      if not constant_exprp j then s := ordad(j,s);
   s>> where s=nil;

symbolic procedure solutionp u;
   null u or cadar u and not root_of_soln_p caar u and solutionp cdr u;

symbolic procedure root_of_soln_p u;
   null cdr u and kernp (u := car u) and eqcar(mvar numr u,'root_of);

symbolic procedure solveargchk u;
   if getrtype (u := reval u) eq 'list then cdr reval u
    else if atom u or not(car u eq 'lst) then list u
    else cdr u;


% ***** Procedures for collecting side information about the solution.

symbolic procedure solve!-clean!-info(fl,flg);
   % Check for constants and multiples in side relations fl.
   % If flg is t then relations are factorised and constants removed.
   % Otherwise the relations are autoreduced and the presence of a
   % constant truncates the whole list.
  begin scalar r,w,p;
     for each form in cdr fl do if not p then
        if constant_exprp(form:=reval form) then
          (if not flg then p:= r:={1})
        else
          if flg then
            for each w in cdr fctrf numr simp form do
             <<w := absf car w;
               if not member(w,r) then r := w . r>>
          else
             <<w:= sqfrf!* absf numr simp{'nprimitive,form};
               for each z in r do if w then
                 if null cdr qremf(z,w) then r:=delete(z,r)
                  else if null cdr qremf(w,z) then w:=nil;
               if w then r:=w.r
             >>;
     return 'list.for each q in r collect prepf q;
  end;


% ***** Procedures for solving a single eqn *****

%symbolic procedure solvesq (ex,var,mul);
%  begin scalar r;
%   r:= for each w in solvesq1(ex,var,mul) join
%     if null cadr w
%        or numr subf(denr ex,{caadr w.prepsq caar w}) then {w};
%   if r and not domainp denr ex then
%        assumptions:=append(assumptions,{prepf denr ex});
%   return r;
%  end;

% Patch from 12 Feb 05

symbolic procedure solvesq (ex,var,mul);
   begin scalar r,x;
      r:= for each w in solvesq1(ex,var,mul) join
        if null cadr w
           or eqcar(x := prepsq caar w,'root_of)
           or numr subfx(denr ex,{caadr w . x}) then {w};
      if r and not domainp denr ex then
           assumptions:=append(assumptions,{prepf denr ex});
      return r
  end;

symbolic procedure solvesq1 (ex,var,mul);
   % Attempts to find solutions for standard quotient ex with respect to
   % top level occurrences of var and kernels containing variable var.
   % Solutions containing more than one such kernel are returned
   % unsolved, and solve1 is applied to the other solutions.  Integer
   % mul is the multiplicity passed from any previous factorizations.
   % Returns a list of triplets consisting of solutions, variables and
   % multiplicity.
     begin scalar e1,oldkorder,x1,y,z;  integer mu;
      ex := numr ex;
      if null(x1 := topkern(ex,var)) then return nil;
      oldkorder := setkorder list var;
      % The following section should be extended for other cases.
      e1 := reorder ex;
      setkorder oldkorder;
      if !*modular then
      <<load!_package 'modsr; return msolvesys({e1},x1,nil)>>;
      if mvar e1 = var and null cdr x1 and ldeg e1 =1
        then return {{{quotsq(negf reorder red e1 ./1,
                              reorder lc e1 ./ 1)},
                     {var},mul}};
     % don't call fctrf here in rounded mode, so polynomial won't get
     % rounded (since factoring isn't going to succeed)
      ex := if !*rounded then {1,ex . 1} else fctrf ex;
      % Now process monomial.
      if domainp car ex then ex := cdr ex
       else ex := (car ex . 1) . cdr ex;
      for each j in ex do
        <<e1 := car j;
          x1 := topkern(e1,var);
          mu := mul*cdr j;
          % Test for decomposition of e1.  Only do if rounded is off.
          if null !*rounded and length x1=1 and length kernels e1<5
             and length(y := decomposef1(e1,nil))>1
             and (y := solvedecomp(reverse y,car x1,mu))
            then z := append(y,z)
           else if (degr(y := reorder e1,var) where kord!*={var}) = 1
              and not smemq(var,delete(var,x1))
            then <<y := {{quotsq(!*f2q negf reorder red y,
                                 !*f2q reorder lc y)},
                         {var},mu};
                   z := y . z>>
           else if x1
            then z := append(
             if null cdr x1 then solve1(e1,car x1,var,mu)
              else if (y := principle!-of!-powers!-soln(e1,x1,var,mu))
                          neq 'unsolved
               then y
              else if not smemq('sol,x1 := solve!-apply!-rules(e1,var))
               then solvesq(x1,var,mu)
%             else list list(list(e1 ./ 1),nil,mu),
              else mkrootsof(e1 ./ 1,var,mu),
                 z)>>;
      return z
   end;

symbolic procedure solvedecomp(u,var,mu);
   % Solve for decomposed expression.  At the moment, only one
   % level of decomposition is considered.
   begin scalar failed,x;
      if length(x := solve0(car u,cadadr u))=1 then return nil;
      u := cdr u;
      while u do
       <<x := for each j in x conc
                 if caddr j neq 1 or null cadr j
                   then <<lprim list("Tell Hearn solvedecomp",x,u);
                          failed := t;
                          nil>>
                  else solve0(list('difference,prepsq caar j,caddar u),
                                 if cdr u then cadadr u else var);
         if failed then u := nil else u := cdr u>>;
      return if failed then nil else adjustmul(x,mu)
   end;

symbolic procedure adjustmul(u,n);
   % Multiply the multiplicities of the solutions in u by n.
   if n=1 then u
    else for each x in u collect list(car x,cadr x,n*caddr x);

symbolic procedure solve1(e1,x1,var,mu);
   Comment e1 is a standard form, non-trivial in the kernel x1, which
      is itself a function of var, mu is an integer.  Uses roots of
      unity, known solutions, inverses, together with quadratic, cubic
      and quartic formulas, treating other cases as unsolvable.
      Returns a list of solve solutions;
   begin scalar !*numval!*;
      !*numval!* := !*numval;    % Keep value for use in solve11.
      return solve11(e1,x1,var,mu)
   end;

symbolic procedure solve11(e1,x1,var,mu);
   begin scalar !*numval,b,coefs,hipow,w;  integer n;
      % The next test should check for true degree in var.
      if null !*fullroots and null !*rounded and numrdeg(e1,var)>2
        then return mkrootsof(e1 ./ 1,var,mu);
      !*numval := t;   % Assume that actual numerical values wanted.
      coefs:= errorset!*(list('solvecoeff,mkquote e1,mkquote x1),nil);
%     if atom coefs then return list list(list(e1 . 1),nil,mu);
      if atom coefs or atom x1 and x1 neq var
        then return mkrootsof(e1 ./ 1,var,mu);
          % solvecoeff problem - no soln.
      coefs := car coefs;
      n:= !!gcd;   % numerical gcd of powers.
      hipow := car(w:=car reverse coefs);
      if not domainp numr cdr w then
        assumptions:=append(assumptions,{prepf numr cdr w});
      if not domainp denr cdr w then
        assumptions:=append(assumptions,{prepf denr cdr w});
      if hipow = 1
        then return begin scalar lincoeff,y,z;
           if null cdr coefs then b := 0
            else b := prepsq quotsq(negsq cdar coefs,cdadr coefs);
           if n neq 1 then b := list('expt,b,list('quotient,1,n));
           % We may need to merge more solutions in the following if
           % there are repeated roots.
           for k := 0:n-1 do   % equation in power of var.
            <<lincoeff := list('times,b,
                          mkexp list('quotient,list('times,k,2,'pi),n));
              lincoeff := simp!* lincoeff where alglist!* = nil . nil;
              if x1=var
                then y := solnmerge(list lincoeff,list var,mu,y)
               else if not idp(z := car x1)
                then typerr(z,"solve operator")
               else if z := get(z,'solvefn)
                then y := append(apply1(z,list(cdr x1,var,mu,lincoeff))
                                 ,y)
               else if (z := get(car x1,'inverse))   % known inverse
                then y := append(solvesq(subtrsq(simp!* cadr x1,
                                 simp!* list(z,mk!*sq lincoeff)),
                                 var,mu),y)
               else y := list(list subtrsq(simp!* x1,lincoeff),nil,mu)
                            . y>>;
         return y
        end
       else if hipow=2
        then return <<x1 := exptsq(simp!* x1,n);
                      % allows for power variable
                      for each j in solvequadratic(getcoeff(coefs,2),
                                    getcoeff(coefs,1),getcoeff(coefs,0))
                                conc solvesq(subtrsq(x1,j),var,mu)>>
       else return solvehipow(e1,x1,var,mu,coefs,hipow)
 end;

symbolic procedure getcoeff(u,n);
   % Get the nth coefficient in the list u as a standard quotient.
   if null u then nil ./ 1
    else if n=caar u then cdar u
    else if n<caar u then nil ./ 1
    else getcoeff(cdr u,n);

symbolic procedure putcoeff(u,n,v);
   % Replace the nth coefficient in the list u by v.
   if null u then list(n . v)
    else if n=caar u then (n . v) . cdr u
    else if n<caar u then (n . v) . u
    else car u . putcoeff(cdr u,n,v);

symbolic procedure solvehipow(e1,x1,var,mu,coefs,hipow);
   % Solve a system with degree greater than 2.  Since we cannot write
   % down the solution directly, we look for various forms that we
   % know how to solve.
   begin scalar b,c,d,f,rcoeffs;
      f:=(hipow+1)/2;
      d:=exptsq(simp!* x1,!!gcd);
      rcoeffs := reverse coefs;
      return if solve1test1(coefs,rcoeffs,f)  % Coefficients symmetric.
        then if f+f=hipow+1   % odd
               then <<c:=addsq(d, 1 ./ 1);
                      append(solvesq(c,var,mu),
                             solvesq(quotsq(e1 ./ 1, c),var,mu))>>
              else <<coefs := putcoeff(coefs,0,2 ./ 1);
                     coefs := putcoeff(coefs,1,simp!* '!!x);
                     c:=addsq(multsq(getcoeff(coefs,f+1),
                                     getcoeff(coefs,1)),
                              getcoeff(coefs,f));
                     for j:=2:f do <<
                         coefs := putcoeff(coefs,j,
                            subtrsq(multsq(getcoeff(coefs,1),
                                           getcoeff(coefs,j-1)),
                                    getcoeff(coefs,j-2)));
                         c:=addsq(c,multsq(getcoeff(coefs,j),
                                           getcoeff(coefs,f+j)))>>;
                     for each j in solvesq(c,'!!x,mu) conc
                      solvesq(addsq(1 ./ 1,multsq(d,subtrsq(d,caar j))),
                                var,caddr j)>>
       else if solve1test2(coefs,rcoeffs,f)
          % coefficients antisymmetric
        then <<c:=addsq(d,(-1 ./1));
               b := solvesq(c,var,mu);
               e1 := quotsq(e1 ./ 1, c);
               if f+f = hipow
                then <<c := addsq(d,(1 ./ 1));
                       b := append(solvesq(c,var,mu),b);
                       e1 := quotsq(e1,c)>>;
               append(solvesq(e1,var,mu),b)>>
          % equation has no symmetry
          % now look for real roots before cubics or quartics.  We must
          % reverse the answer from solveroots so that roots come out
          % in same order from SOLVE.
%      else if !*numval!* and dmode!* memq '(!:rd!: !:cr!:)
      % this forces solveroots independent of numval.
       else if !*rounded and univariatep e1
        then reversip solveroots(e1,var,mu)
       else if null !*fullroots then mkrootsof(e1 ./ 1,var,mu)
       else if hipow=3
        then for each j in solvecubic(getcoeff(coefs,3),
                                      getcoeff(coefs,2),
                                      getcoeff(coefs,1),
                                      getcoeff(coefs,0))
                       conc solvesq(subtrsq(d,j),var,mu)
       else if hipow=4
        then for each j in solvequartic(getcoeff(coefs,4),
                                        getcoeff(coefs,3),
                                        getcoeff(coefs,2),
                                        getcoeff(coefs,1),
                                        getcoeff(coefs,0))
                       conc solvesq(subtrsq(d,j),var,mu)
%      else list list(list(e1 ./ 1),nil,mu)
       else mkrootsof(e1 ./ 1,var,mu)
          % We can't solve quintic and higher.
   end;

symbolic procedure solnmerge(u,varlist,mu,y);
   % Merge solutions in case of multiplicities. It may be that this is
   % only needed for the trivial solution x=0.
   if null y then list list(u,varlist,mu)
    else if u = caar y and varlist = cadar y
           then list(caar y,cadar y,mu+caddar y) . cdr y
    else car y . solnmerge(u,varlist,mu,cdr y);

symbolic procedure nilchk u; if null u then !*f2q u else u;

symbolic procedure solve1test1(coefs,rcoeffs,f);
   % True if equation is symmetric in its coefficients. f is midpoint.
   begin integer j,p;
      if null coefs or caar coefs neq 0 or null !*fullroots
        then return nil;
      p := caar coefs + caar rcoeffs;
   a: if j>f then return t
       else if (caar coefs + caar rcoeffs) neq p
               or cdar coefs neq cdar rcoeffs then return nil;
      coefs := cdr coefs;
      rcoeffs := cdr rcoeffs;
      j := j+1;
      go to a
   end;

symbolic procedure solve1test2(coefs,rcoeffs,f);
   % True if equation is antisymmetric in its coefficients. f is
   %  midpoint.
   begin integer j,p;
      if null coefs or caar coefs neq 0 or null !*fullroots
        then return nil;
      p := caar coefs + caar rcoeffs;
   a: if j>f then return t
       else if (caar coefs + caar rcoeffs) neq p
          or numr addsq(cdar coefs,cdar rcoeffs) then return nil;
      coefs := cdr coefs;
      rcoeffs := cdr rcoeffs;
      j := j+1;
      go to a
   end;

symbolic procedure solveabs u;
   begin scalar mu,var,lincoeff;
      var := cadr u;
      mu := caddr u;
      lincoeff := cadddr u;
      u := simp!* caar u;
      return append(solvesq(addsq(u,lincoeff),var,mu),
                    solvesq(subtrsq(u,lincoeff),var,mu))
   end;

put('abs,'solvefn,'solveabs);

symbolic procedure solveexpt u;
   begin scalar c,mu,var,lincoeff;
      var := cadr u;
      mu := caddr u;
      lincoeff := cadddr u;
%       the following line made solve(x^(1/2)=0) etc. wrong
%      if null numr lincoeff then return nil;
      u := car u;
      return if freeof(car u,var)    % c**(...) = b.
    then if null numr lincoeff then nil else
        <<if !*allbranch
                 then <<!!arbint:=!!arbint+1;
            c:=list('times,2,'i,'pi,
                list('arbint,!!arbint))>>
                else c:=0;
                solvesq(subtrsq(simp!* cadr u,
                     quotsq(addsq(solveexpt!-logterm lincoeff,
                                  simp!* c),
                        simp!* list('log,car u))),var,mu)>>
       else if freeof(cadr u,var) and null numr lincoeff  %(...)**b=0.
        then if check!-condition {'equal,{'sign,cadr u},1}
                 then solvesq(simp!* car u,var,mu)
                else solveexpt!-rootsof(u,lincoeff,var,mu)
       else if freeof(cadr u,var)   %  (...)**(m/n) = b;
        then if ratnump cadr u
           then solve!-fractional!-power(u,lincoeff,var,mu)
          else <<   %  (...)**c = b.
                 if !*allbranch
                   then <<!!arbint:=!!arbint+1;
                          c := mkexp list('quotient,
                                          list('times,2,'pi,
                                               list('arbint,!!arbint)),
                                               cadr u)>>
%                         c := mkexp list('times,
%                                         list('arbreal,!!arbint))>>
                  else c:=1;
                 solvesq(subtrsq(simp!* car u,
                multsq(simp!* list('expt,
                           mk!*sq lincoeff,
                           mk!*sq invsq
                              simp!* cadr u),
                       simp!* c)),var,mu)>>
        %  (...)**(...) = b : transcendental.
%   else list list(list subtrsq(simp!*('expt . u),lincoeff),nil,mu)
    else solveexpt!-rootsof(u,lincoeff,var,mu)
   end;

symbolic procedure solveexpt!-rootsof(u,lincoeff,var,mu);
    mkrootsof(subtrsq(simp!*('expt . u),lincoeff),var,mu);

put('expt,'solvefn,'solveexpt);

symbolic procedure solveexpt!-logterm lincoeff;
  % compute log(lincoeff), ignoring multiplicity and converting
  % log(-a) to log(a) + i pi.
   simp!* list('log,mk!*sq lincoeff);
%  if not !*allbranch or not minusf numr lincoeff
%     then simp!* list('log,mk!*sq lincoeff)
%  else
%   addsq(simp!*'(times i pi),
%         simp!* {'log,mk!*sq(negf numr lincoeff ./ denr lincoeff)});

symbolic procedure solvelog u;
   solvesq(subtrsq(simp!* caar u,simp!* list('expt,'e,mk!*sq cadddr u)),
          cadr u,caddr u);

put('log,'solvefn,'solvelog);

symbolic procedure solveinvpat(u,op);
   begin scalar c,f;
      f:=get(op,'solveinvpat);
      if smemq('arbint,f) then f:=subst(
         if !*allbranch then list('arbint,!!arbint:=!!arbint+1) else 0,
          'arbint,f);
      if not !*allbranch then f:={car f};
      return
       for each c in reverse f join
         solvesq(simp!*
                    subst(caar u,'(~v),subst(mk!*sq cadddr u,'(~r),c)),
                 cadr u,caddr u)
   end;


put('cos,'solveinvpat,
{ quote (- ~v + acos(~r) + 2*arbint*pi),
  quote (- ~v - acos(~r) + 2*arbint*pi) });

put('cos,'solvefn, '(lambda(u) (solveinvpat u 'cos)));

put('sin,'solveinvpat,
{ quote (- ~v + asin(~r) + 2*arbint*pi),
  quote (- ~v - asin(~r) + 2*arbint*pi + pi) });

put('sin,'solvefn, '(lambda(u) (solveinvpat u 'sin)));

put('sec,'solveinvpat,
{ quote (- ~v + asec(~r) + 2*arbint*pi),
  quote (- ~v - asec(~r) + 2*arbint*pi) });

put('sec,'solvefn, '(lambda(u) (solveinvpat u 'sec)));

put('csc,'solveinvpat,
{ quote (- ~v + acsc(~r) + 2*arbint*pi),
  quote (- ~v - acsc(~r) + 2*arbint*pi + pi) });

put('csc,'solvefn, '(lambda(u) (solveinvpat u 'csc)));

put('tan,'solveinvpat, { quote (- ~v + atan(~r) + arbint*pi)});

put('tan,'solvefn, '(lambda(u) (solveinvpat u 'tan)));

put('cot,'solveinvpat, { quote (- ~v + acot(~r) + arbint*pi)});

put('cot,'solvefn, '(lambda(u) (solveinvpat u 'cot)));

put('cosh,'solveinvpat,
{ quote (- ~v + acosh(~r) + 2*arbint*i*pi),
  quote (- ~v - acosh(~r) + 2*arbint*i*pi) });

put('cosh,'solvefn, '(lambda(u) (solveinvpat u 'cosh)));

put('sinh,'solveinvpat,
{ quote (- ~v + asinh(~r) + 2*arbint*i*pi),
  quote (- ~v - asinh(~r) + 2*arbint*i*pi + i*pi) });

put('sinh,'solvefn, '(lambda(u) (solveinvpat u 'sinh)));

put('sech,'solveinvpat,
{ quote (- ~v + asech(~r) + 2*arbint*i*pi),
  quote (- ~v - asech(~r) + 2*arbint*i*pi) });

put('sech,'solvefn, '(lambda(u) (solveinvpat u 'sech)));

put('csch,'solveinvpat,
{ quote (- ~v + acsch(~r) + 2*arbint*i*pi),
  quote (- ~v - acsch(~r) + 2*arbint*i*pi + i*pi) });

put('csch,'solvefn, '(lambda(u) (solveinvpat u 'csch)));

put('tanh,'solveinvpat, { quote (- ~v + atanh(~r) + arbint*i*pi)});

put('tanh,'solvefn, '(lambda(u) (solveinvpat u 'tanh)));

put('coth,'solveinvpat, { quote (- ~v + acoth(~r) + arbint*i*pi)});

put('coth,'solvefn, '(lambda(u) (solveinvpat u 'coth)));

symbolic procedure mkexp u;
   reval(aeval!*({'plus,{'cos,x},{'times,'i,{'sin,x}}}
            where x = reval u)
          where !*rounded = nil,dmode!* = nil);

symbolic procedure solvecoeff(ex,var);
   % Ex is a standard form and var a kernel.  Returns a list of
   % dotted pairs of exponents and coefficients (as standard quotients)
   % of var in ex, lowest power first, with exponents divided by their
   % gcd. This gcd is stored in !!GCD.
   begin scalar clist,oldkord;
      oldkord := updkorder var;
      clist := reorder ex;
      setkorder oldkord;
      clist := coeflis clist;
      !!gcd := caar clist;
      for each x in cdr clist do !!gcd := gcdn(car x,!!gcd);
      for each x in clist
         do <<rplaca(x,car x/!!gcd); rplacd(x,cdr x ./ 1)>>;
      return clist
   end;

symbolic procedure solveroots(ex,var,mu);
   % Ex is a square and content free univariate standard form, var the
   % relevant variable and mu the root multiplicity.  Finds insoluble,
   % complex roots of EX, returning a list of solve solutions.
   begin scalar y;
      y := reval list('root_val,mk!*sq(ex ./ 1));
      if not(car y eq 'list)
       then errach list("incorrect root format",ex);
      return for each z in cdr y collect
       %  if not(car z eq 'equal) or cadr z neq var
       %    then errach list("incorrect root format",ex)
       %   else list(list simp caddr z,list var,mu)
         list(list simp z,list var,mu)
   end;


% ***** Procedures for solving a system of eqns *****

Comment. The routines for solving systems of equations return a "tagged
solution list", where

        tagged solution list ::= tag . list of solve solution
        tag ::= t | nil | 'inconsistent | 'singular | 'failed
        solve solution ::= {solution rhs,solution lhs,multiplicity} |
                           {solution rhs,nil,multiplicity}
        solution rhs ::= list of sq
        solution lhs ::= list of kernel
        multiplicity ::= posint

If the tag is anything but t, the list of solve solutions is empty. See
solvenonlnrsys for more about the tags;

symbolic procedure solvesys(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvesys: tagged solution list
   % The expressions in exlis are reordered wrt the kernels in varlis,
   % and solved. For some switch settings, the internal
   % solve procedure may produce an error, leaving the kernel order
   % disturbed, so an errorset is used here.
   begin scalar oldkord;
        % The standard methods for linear and polynomial system
        % don't work for non-prime modulus.
      if !*modular then
        <<load!-package 'modsr; return msolvesys(exlis,varlis,t)>>;
      oldkord := setkorder varlis;
      exlis := for each j in exlis collect reorder j;
      exlis := errorset!*({'solvemixedsys,mkquote exlis,mkquote varlis},
                          t);
      setkorder oldkord;
      if errorp exlis then error1();
      return car exlis;
   end;

symbolic procedure solvemixedsys(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvemixedsys: tagged solution list
   % Solve a mixed linear/nonlinear system, solving the linear
   % part and substituting into the nonlinear until a core nonlinear
   % system remains. Assumes solvenonlnrsys and solvelnrsys both handle
   % all trivial cases properly.
   if null cadr(exlis := siftnonlnr(exlis,varlis)) then % linear
      solvelnrsys(car exlis,varlis)
   else if null car exlis then                          % nonlinear
      solvenonlnrsys(cadr exlis,varlis)
   else                                                 % mixed
      begin scalar x,y,z;
      x := solvelnrsys(car exlis,varlis) where !*arbvars = nil;
      if car x = 'inconsistent then return x
      else x := cadr x;
      z := pair(cadr x,foreach ex in car x collect mk!*sq ex);
      exlis := foreach ex in cadr exlis join
                  if ex := numr subf(ex,z) then {ex}; % resimp??
      varlis := setdiff(varlis,cadr x); % remaining free variables
      y := solvemixedsys(exlis,varlis);
      if car y memq {'inconsistent,'singular,'failed,nil} then return y
      else return t . foreach s in cdr y collect
            <<z := foreach pr in pair(cadr s,car s) join
                      if not smemq('root_of,cdr pr) then
                         {car pr . mk!*sq cdr pr};
              {append(car s,foreach ex in car x collect subsq(ex,z)),
               append(cadr s,cadr x),caddr s}>>;
      end;

symbolic procedure siftnonlnr(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> siftnonlnr: {list of sf, list of sf}
   % separate exlis into {linear,nonlinear}
   begin scalar lin,nonlin;
   foreach ex in exlis do
      if nonlnr(ex,varlis) then nonlin := ex . nonlin
      else lin := ex . lin;
   return {reversip lin,reversip nonlin};
   end;

symbolic procedure nonlnrsys(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> nonlnrsys: bool
   if null exlis then nil
   else nonlnr(car exlis,varlis) or nonlnrsys(cdr exlis,varlis);


symbolic procedure nonlnr(ex,varlis);
   % ex: sf, varlis: list of kernel -> nonlnr: bool
   if domainp ex then nil
   else if mvar ex member varlis then
        ldeg ex>1 or not freeofl(lc ex,varlis) or
        nonlnr(red ex,varlis)
   else not freeofl(mvar ex,varlis) or
        nonlnr(lc ex,varlis) or
        nonlnr(red ex,varlis);


% ***** Support for one_of and root_of *****.

symbolic procedure mkrootsoftag();
   begin scalar name; integer n;
 loop: n:=n #+1;
    name := intern compress append('(t a g _),explode n);
    if flagp(name,'used!*) then go to loop;
    return reval name;
  end;

symbolic procedure mkrootsof(e1,var,mu);
   begin scalar x,name;
      x := if idp var then var else 'q_;
      name := !*!*norootvarrenamep!*!* or mkrootsoftag();
      if not !*!*norootvarrenamep!*!*
        then while smember(x,e1) do
             x := intern compress append(explode x,explode '!_);
      e1 := prepsq!* e1;
      if x neq var then e1 := subst(x,var,e1);
      return list list(list !*k2q list('root_of,e1,x,name),list var,mu)
   end;

put('root_of,'psopfn,'root_of_eval);

symbolic procedure root_of_eval u;
   begin scalar !*!*norootvarrenamep!*!*,x,n;
      n := if cddr u then caddr u else mkrootsoftag();
      !*!*norootvarrenamep!*!* := n;
      x := solveeval{car u,cadr u};
      if eqcar(x,'list) then x := cdr x else typerr(x,"list");
      x := foreach j in x collect if eqcar(j,'equal) then caddr j
                                   else typerr(j,"equation");
      if null x then rederr "solve confusion in root_of_eval"
       else if null cdr x then return car x
       else return{'one_of, 'list . x,n}
   end;

put('root_of,'subfunc,'subrootof);

symbolic procedure subrootof(l,expn);
   % Sets up a formal SUB expression when necessary.
   begin scalar x,y;
      for each j in cddr expn do
         if (x := assoc(j,l)) then <<y := x . y; l := delete(x,l)>>;
      expn := sublis(l,car expn)
                 . for each j in cdr expn collect subsublis(l,j);
        %to ensure only opr and individual args are transformed;
      if null y then return expn;
      expn := aconc!*(for each j in reversip!* y
                     collect list('equal,car j,aeval cdr j),expn);
      return if l then subeval expn
              else mk!*sq !*p2q mksp('sub . expn,1)
   end;

%-(algebraic <<
%-
%-depend(!~p,!~x); % Needed for the simplification of the rule pattern.
%-
%-let root_of(~p,~x,~tg)^~n =>
%-       sub(x=root_of(p,x,tg),
%-           -reduct(p,x)/coeffn(p,x,deg(p,x))) ^ (n-deg(p,x)+1)
%-               when fixp n and deg(p,x)>=1 and n>=deg(p,x);
%-
%-nodepend(!~p,!~x);
%-
%->>) where dmode!*=nil,!*modular=nil,!*rounded=nil,!*complex=nil;


symbolic procedure polyp(p,f)$
%  tests if p is a polynomial in f and its derivatives
%    p: expression
%    f: function
if my_freeof(p,f) then t
else
begin scalar a$
if atom p then a:=t
else
if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,'QUOTIENT,'DF)) then
                                        %  erlaubte Funktionen
        <<if (car p='PLUS) or (car p='TIMES) then
                <<p:=cdr p$
                while p do
                    if a:=polyp(car p,f) then p:=cdr p
                                         else p:=nil>>
        else if (car p='MINUS) then
                a:=polyp(cadr p,f)
        else if (car p='QUOTIENT) then
                <<if freeof(caddr p,f) then a:=polyp(cadr p,f)>>
        else if car p='EXPT then        %  Exponent
                <<if (fixp caddr p) then
                   if caddr p>0 then a:=polyp(cadr p,f)>>
        else if car p='DF then          %  Ableitung
                if (cadr p=f) or freeof(cadr p,f) then a:=t>>
else a:=(p=f)$
return a
end$

symbolic procedure polypeval u;
   begin scalar bool,v;
      v := cadr u;
      u := simpcar u;
      if cdr u neq 1 then return nil else u := kernels car u;
      while u and null bool do
        <<if v neq car u and smember(v,car u) then bool := t;
          u := cdr u>>;
      return null bool
   end;

put('polyp,'psopfn,'polypeval);

(algebraic <<

depend(!~p,!~x);

let root_of(~p,~x,~tg)^~n =>
       sub(x=root_of(p,x,tg),
           -reduct(p,x)/coeffn(p,x,deg(p,x))) ^ (n-deg(p,x)+1)
               when polyp(p,x) and fixp n and deg(p,x)>=1 and n>=deg(p,x);

nodepend(!~p,!~x);

>>) where dmode!*=nil,!*modular=nil,!*rounded=nil,!*complex=nil;


symbolic procedure expand_cases u;
   begin scalar bool,sl,tags;
      sl:=list nil; tags:=list nil;
      u := reval u;
      if not eqcar(u,'list) then typerr(u,"equation list")
        else u := cdr u;
      if eqcar(car u,'list)
        then <<u := for each j in u collect
                        if eqcar(j,'list) then cdr j
                         else typerr(j,"equation list");
               bool := t>>
       else u := for each j in u collect {j};
      u := for each j in u join expand_case1(j,sl,tags);
      return 'list .
         for each j in u collect if null bool then car j else 'list . j
   end;

symbolic procedure expand_case1(u,sl,tags);
   if null u then nil
    else expand_merge(expand_case2(car u,sl,tags),
                      expand_case1(cdr u,sl,tags));

symbolic procedure expand_merge(u,v);
   if null v then for each j in u collect {j}
    else for each j in u join for each k in v collect j . k;

symbolic procedure expand_case2(u,sl,tags);
   begin scalar tag,v,var;
      var := cadr u; v := caddr u;
      if eqcar(v,'one_of)
        then <<tag := caddr v;
               if tag member tags then typerr(tag,"unique choice tag")
                 else if null assoc(tag,sl)
                  then cdr sl := (tag . cdadr v) . cdr sl;
               return if eqcar(cadr v,'list)
                      then for each j in cdadr v collect {'equal,var,j}
                      else typerr(cadr v,"list")>>
      % The next section doesn't do anything currently since root_of
      % is wrapped in a !*sq at this point.
       else if eqcar(v,'root_of)
        then <<tag := cadddr v;
               cdr tags := tag . cdr tags;
               if assoc(tag,sl) then typerr(tag,"unique choice tag")>>;
      return {u}
   end;

% Rules for solving inverse trigonometrical functions.

fluid '(solve_invtrig_soln!*);

share solve_invtrig_soln!*;

symbolic procedure check_solve_inv_trig(fn,equ,var);
   begin scalar x,s;
     x := evalletsub2({'(solve_trig_rules),{'simp!*,mkquote {fn,equ}}},
                      nil);
     if errorp x or not ((x := car x) freeof '(asin acos atan))
       then return nil;
     for each sol in cdr solveeval {mk!*sq subtrsq(x,simp!* {fn,0}),
                                    var} do
       if is_solution(sol,equ) then s := caddr sol . s;
     if null s then <<solve_invtrig_soln!* := 1;
                      return t>> % no solution found
      else if null cdr s then s := car s     % one solution
      else s := 'one_of . s;
     solve_invtrig_soln!* := {'difference,var,s};
     return t
   end;

flag('(check_solve_inv_trig),'boolean);

symbolic procedure is_solution(sol,equ);
   begin scalar var,s,rhs,result;
     var := cadr sol;
     rhs := caddr sol;
     equ := numr simp!* equ;
     if eqcar(rhs,'one_of)
       then result := check!-solns(for each s in cdr rhs collect
                                     {{simp!* s},{var},1},
                                   equ,var)
      else if eqcar(rhs,'root_of) then result := t
      else result := check!-solns({{{simp!* rhs},{var},1}},equ,var);
     return if not (result eq 'unsolved) then result else nil
   end;

symbolic procedure check!-condition u;
   null !*precise or eval formbool(u,nil,'algebraic);

endmodule;


module ppsoln;  % Solve surd eqns, mainly by principle of powers method.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

fluid '(!*complex !*msg !*numval !*ppsoln);

global '(bfone!*);

!*ppsoln := t;   % Keep this as internal switch.

symbolic procedure solve!-fractional!-power(u,x,var,mu);
   % Attempts solution of equation car u**cadr u=x with respect to
   % kernel var and with multiplicity mu, where cadr u is a rational
   % number.
   begin scalar v,w,z;
      v := simp!* car u;
      w := simp!* cadr u;
      z := solvesq(subs2 subtrsq(exptsq(v,numr w),exptsq(x,denr w)),
                   var,mu);
      w := subtrsq(simp('expt . u),x);
      z := check!-solns(z,numr w,var);
%     return if z eq 'unsolved then list list(list w,nil,mu) else z
      return if z eq 'unsolved then mkrootsof(w,var,mu) else z
   end;

symbolic procedure principle!-of!-powers!-soln(ex,x1,var,mu);
   % Finds solutions of ex=0 by the principle of powers method.  Return
   % 'unsolved if solutions can't be found.
   begin scalar z;
   a: if null x1 then return 'unsolved
       else if suitable!-expt car x1
          and not((z := pr!-pow!-soln1(ex,car x1,var,mu)) eq 'unsolved)
         then return z;
      x1 := cdr x1;
      go to a
   end;

symbolic procedure pr!-pow!-soln1(ex,y,var,mu);
   begin scalar oldkord,z;
      oldkord := updkorder y;
      z := reorder ex;
      setkorder oldkord;
      if ldeg z neq 1 then return 'unsolved;
      z := coeflis z;
      if length z neq 2 or caar z neq 0
        then errach list("solve confused",ex,z);
      z := exptsq(quotsq(negsq(cdar z ./ 1),cdadr z ./ 1),
            caddr caddr y);
      z := solvesq(subs2 addsq(simp!* cadr y,negsq z),var,mu);
      z := check!-solns(z,ex,var);
      return z
   end;

symbolic procedure check!-solns(z,ex,var);
   begin scalar x,y,fv,sx,vs;
      fv := freevarl(ex,var);
      for each z1 in z do
        fv := union(fv,union(freevarl(numr caar z1,var),
                             freevarl(denr caar z1,var)));
      fv := delete('i,fv);
     % this does only one random setting!!
      if fv then for each v in fv do
        if not flagp(v,'constant) then
           vs := (v . list('quotient,1+random 999,1000)) . vs;
      sx := if vs then numr subf(ex,vs) else ex;
      while z do
         if null cadar z then <<z := nil; x := 'unsolved>>
         else if
           <<y := numr subf(ex,list(caadar z . mk!*sq caaar z));
             null y
        % to do multiple random tests, the vs, sx setting and testing
        % would be moved here and done in a loop.
             or fv and null(y := numr subf(sx,list(caadar z .
                   mk!*sq subsq(caaar z,vs))))
             or null numvalue y>>
           then <<x := car z . x; z := cdr z>>
          else z := cdr z;
      return if null x then 'unsolved else x
   end;

symbolic procedure suitable!-expt u;
   eqcar(u,'expt) and eqcar(caddr u,'quotient) and cadr caddr u = 1
      and fixp caddr caddr u;

symbolic procedure freevarl(ex,var);
 <<for each k in allkern list(ex ./ 1) do l := union(l,varsift(k,var));
   delete(var,l)>>
   where l=if var then list var else nil;

symbolic procedure varsift(a,var);
   if atom a then
      if not(null a or numberp a or a eq var) then list a else nil
   else if get(car a,'dname) then nil
   else if car a memq '(arbint arbcomplex) then list a
   else if car a eq '!*sq then varsift(prepsq cadr a,var)
   else for each c in cdr a join varsift(c,var);

symbolic procedure numvalue u;
   % Find floating point value of sf u.
   begin scalar !*numval,x,c,cp,p,m;
      m := !*msg; !*msg := nil;
      !*numval := t;
      c := ('i memq freevarl(u,nil));
      if (cp := !*complex) then off complex;
      x := setdmode('rounded,t); p := precision 10;
      if x eq '!:rd!: then x := 'rounded;  % <==== to avoid error later
      if c then on complex;
      !*msg := m;
      u := numr simp prepf u;
      !*msg := nil;
      if c then off complex;
      if x then setdmode(x,t) else setdmode('rounded,nil);
      if cp then on complex; precision p;
      !*msg := m;
      return
        if eqcar(u,'!:rd!:) and (numvchk(100,z) where z=round!* u)
        or eqcar(u,'!:cr!:) and (numvchk(10,z) where z=retag crrl u)
           and (numvchk(10,z) where z=retag crim u)
            then nil else u
   end;

symbolic procedure numvchk(fact,z);
   if atom z then fact*abs z<1
   else lessp!:(timbf(bfloat fact,abs!: z),bfone!*);

endmodule;


module solvelnr; % Code for solving a general system of linear eqns.

% Authors: Anthony C. Hearn and Eberhard Schruefer.
% Modifications by: David Hartley.

% Based on code by David R. Stoutemyer modified by Donald R. Morrison.

% Copyright (c) 1993 RAND.  All rights reserved.

% The number of equations and the number of unknowns are arbitrary.
% I.e. the system can be under- or overdetermined.

fluid '(!*cramer !*exp !*solvesingular asymplis!* wtl!*
        !*arbvars !*trsparse !*varopt bareiss!-step!-size!*);

% switch solveinconsistent;

% !*solveinconsistent := t; % Default value.

symbolic procedure solvelnrsys(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvelnrsys: tagged solution list
   % Check the system for sparsity, then decide whether to use the
   % Cramer or Bareiss method.  Using the Bareiss method on sparse
   % systems, 4-step elimination seems to be faster than 2-step.
   % The Bareiss code is not good at handling surds at the moment,
   % hence exptexpflistp test.
   begin scalar w,method;
   if w := solvesparsecheck(exlis,varlis) then exlis := w
     else exlis := exlis . varlis;
   if null !*cramer and null exptexpflistp exlis
      then method := 'solvebareiss
     else method := 'solvecramer;
   exlis := apply2(method,car exlis,cdr exlis)
               where bareiss!-step!-size!* = if w then 4 else 2;
   return solvesyspost(exlis,varlis);
   end;


symbolic procedure exptexpflistp u;
   %  True if any of u contains an expt kernel.
   u and (exptexpfp car u or exptexpflistp cdr u);


symbolic procedure solvesyspost(exlis,varlis);
   % exlis: tagged solution list, varlis: list of kernel
   %  -> solvesyspost: tagged solution list
   % Insert arbitrary constants and present
   % solutions in same order as in varlis.
   % Also reorders expressions to prevailing kernel order.
   car exlis . foreach s in cdr exlis collect
      if car s and null cadr s then s else
      begin scalar arbvars,z;
      if !*arbvars or (null cadr s and length varlis = 1) then
         arbvars := foreach v in setdiff(varlis,cadr s) collect
                       v . mvar makearbcomplex()
      else
         varlis := intersection(varlis,cadr s);
      z := pair(cadr s,sublis(arbvars,car s));
      z := append(z,foreach p in arbvars collect car p . !*k2q cdr p);
      return {foreach v in varlis collect reordsq cdr atsoc(v,z),
              varlis,caddr s};
      end;

symbolic procedure solvecramer(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvecramer: tagged solution list
   % Just a different name at the moment.
   glnrsolve(exlis,varlis);

symbolic procedure solvesparsecheck(sys,vl);
   % sys: list of sf, vl: list of kernel
   % -> solvesparsecheck: nil or {list of sf,list of kernel}
   % This program checks for a sparse linear system. If the
   % system is sparse enough, it returns (exlis.varlis) reordered
   % such that a maximum triangular upper diagonal form is
   % established. Otherwise the result is NIL.
   begin scalar vl1,xl,sys1,q,x,y;
         integer sp;

   % First collect a list vl1 where each variable is followed
   % by the number of equations where it occurs, and then
   % by the number of other variables which occur in these
   % equations (connectivity). At the same time, collect a measure
   % of the sparsity.
   sp:=0;
   vl1:= for each x in vl collect x . 0 . nil;
   foreach q in sys do
      foreach x in (xl := intersection(topkerns q,vl)) do
       <<y := assoc(x,vl1);
         cdr y := (cadr y + 1) . union(xl,cddr y);
         sp := sp + 1>>;
   foreach p in vl1 do
      cddr p := length cddr p - 1; % could drop the -1

   % Drop out if density > 80%
   if sp > length sys * length vl * 0.8 then
    <<if !*trsparse then prin2t "System is not very sparse";
      return nil>>;

   % Sort variables first by least occurrences and then least
   %  connectivity.
   % Reset kernel order and reorder equations.
   if !*trsparse then
     solvesparseprint("Original sparse system",sys,vl);

   vl1:=foreach x in if not !*varopt then vl1 else
           sort(vl1,function (lambda(x,y);
                               cadr x<cadr y
                               or cadr x=cadr y and cddr x < cddr y))
           collect car x;
   if !*varopt then
    <<foreach k in reverse vl1 do updkorder k;
      sys := for each q in sys collect reorder q>>;

   % Next sort equations in ascending order of their first variable
   % and then descending order of the next variable.
   sys1:= (nil . nil) . foreach x in vl1 collect x . nil;
   foreach q in sys do
      <<if domainp q or not member(mvar q,vl1) then y := assoc(nil,sys1)
        else y := assoc(mvar q,sys1);
        cdr y := q . cdr y>>;
   foreach p in cdr sys1 do
      if cdr p then cdr p := sort(cdr p, function solvesparsesort);

   % Finally split off a leading diagonal system and push the remaining
   % equations down.
   sys := nconc(foreach p in sys1 join if cdr p then {cadr p},
                reversip foreach p in sys1 join if cdr p then cddr p);
   if !*trsparse then
      solvesparseprint("Variables and equations rearranged",sys,vl1);
   return sys.vl1;
   end;

symbolic procedure solvesparseprint(text,sys,vl);
   <<terpri(); prin2t text;
     for each e in sys do
       << e := topkerns e;
          for each x in vl do
          if memq(x,e) then prin2 "*"  else prin2 "-";
          terpri()>>>>;

symbolic procedure topkerns u;
   % u:sf -> topkerns:list of kernel
   % kernels in top level of u
   if domainp u then nil else mvar u . topkerns red u;


symbolic procedure solvesparsesort(x,y);
   % x,y: sf -> solvesparsesort: bool
   if domainp x then nil
   else if domainp y then t
   else if mvar x = mvar y then solvesparsesort(red y,red x)
   else if ordop(mvar x,mvar y) then t
   else nil;

endmodule;


module glsolve; % Routines for solving a general system of linear
                % equations using Cramer's rule, realized through
                % exterior multiplication.

% Author: Eberhard Schruefer.
% Modifications by:  D. Hartley and R.W. Tucker.

% The number of equations and the number of unknowns are arbitrary.
% I.e. the system can be under- or overdetermined.

fluid '(!*solvesingular vars!*);  % !*solveinconsistent

global '(!!arbint assumptions requirements);

symbolic procedure glnrsolve(u,v);
% glnrsolve(u: list of sf's, v: list of kernels)
% -> (xprs: list of sq's, flg: boolean)
% Adapted by D. Hartley and R.W. Tucker from E. Schruefer's glnrsolve.
% The equations u must be ordered with respect to the kernels v
   begin scalar sgn,x,y,cnds;
     if null u then go to b;
     a: x := !*sf2ex(car u,v);
        if null x then u := cdr u
         else if inconsistency!-chk x then
                 <<cnds := car u . cnds; x := nil; u := cdr u>>;
        if u and null x then go to a;
     b:
     if null u then       % no consistent non-zero equations
       if cnds then go to d
       else return t . {{nil,nil,1}};  % all equations were zero
     if null(u := cdr u) then go to d;
     c: if y := subs2chkex extmult(!*sf2ex(car u,v),x)
          then if inconsistency!-chk y
                  then cnds :=  numr cancel(lc y ./ lc x) . cnds
                  else <<assumptions :=
                            'list . mk!*sq !*f2q lc y .
                        (pairp assumptions and cdr assumptions);
                         x := y>>;
        if (u := cdr u) then go to c;
     d:
     for each j in cnds do
        requirements := 'list . mk!*sq !*f2q j .
                           (pairp requirements and cdr requirements);
     if cnds then return 'inconsistent . nil;
     if setdiff(v,lpow x) and not !*solvesingular then
        return 'singular . {};
     if null red x then return
        t . {{for each j in lpow x collect nil ./ 1,lpow x,1}};
     y := lc x; sgn := evenp length lpow x;
     u := foreach j in lpow x collect
             (if (sgn := not sgn) then negf f else f)
              where f = !*ex2sf innprodpex(delete(j,lpow x),red x);
     return t . {{foreach f in u collect cancel(f ./ y),lpow x,1}};
   end;

symbolic procedure inconsistency!-chk u;
   null u or ((nil memq lpow u) and inconsistency!-chk red u);


endmodule;


module solvealg;  % Solution of equations and systems which can
                  % be lifted to algebraic (polynomial) systems.

% Author: Herbert Melenk.

% Copyright (c) 1992 The RAND Corporation and Konrad-Zuse-Zentrum.
% All rights reserved.

% August 1992: added material for
%    rule set for reduction of trig. polynomial terms to
%      elementary expressions in sin and cos,
%    constant expressions in sin, cos and constant roots,
%    closed form results for trigonometric systems.
%    general exponentials.
%    avoiding false solutions with surds.
%
% May 1993: better handling of products of exponentials
%       with common base,
%    additional computation branch for linear parts of
%       nonlinear systems.

fluid '(!*expandexpt);   % from simp.red

fluid '( system!*        % system to be solved
         osystem!*       % original system on input
         uv!*            % user supplied variables
         iv!*            % internal variables
         fv!*            % restricted variables
         kl!*            % kernels to be investigated
         sub!*           % global substitutions
         inv!*           % global inverse substitutions
         depl!*          % REDUCE dependency list
         !*solvealgp     % true if using this module
         solvealgdb!*    % collecting some data
         last!-vars!*    % collection of innermost aux variables
         const!-vars!*   % variables representing constants
         root!-vars!*    % variables representing root expressions
         !*expli         % local switch: explicit solution
         groebroots!*    % predefined roots from input surds
         !*test_solvealg % debugging support
         !*arbvars
       );

fluid '(!*trnonlnr);
  % If set on, the modified system and the Groebner result
  % or the reason for the failure are printed.

global '(loaded!-packages!* !!arbint);

switch trnonlnr;

!*solvealgp := t;

%     Solvenonlnrsys receives a system of standard forms and
%     a list of variables from SOLVE. The system is lifted to
%     a polynomial system (if possible) in substituting the
%     non-atomic kernels by new variables and appending additonal
%     relations, e.g.
%         replace                        add
%       sin u,cos u  -> su,cu        su^2+cu^2-1
%         u^(1/3)    -> v            v^3 - u
%          ...
%     in a recursive style. If completely successful, the
%     system definitely can be treated by Groebner or any
%     other polynomial system solver.
%
%     Return value is a pair
%          (tag . res)
%     where "res" is nil or a structure for !*solvelist2solveeqlist
%     and "tag" is one of the following:
%
%       T             a satisfactory solution was generated,
%
%       FAILED        the algorithm cannot be applied (res=nil)
%
%       INCONSISTENT  the algorithm could prove that the
%                     the system has no solution (res=nil)
%
%       NIL           the complexity of the system could
%                     be reduced, but some (or all) relations
%                     remain still implicit.

% rules to be applied locally for converting composite transcendental
% function forms into simpler ones

algebraic <<
solvealg!-rules1:=
{ sin(~alpha + ~beta) => sin(alpha)*cos(beta) + cos(alpha)*sin(beta),
  cos(~alpha + ~beta) => cos(alpha)*cos(beta) - sin(alpha)*sin(beta),
  sin(~n*~alpha) => sin(alpha)*cos((n-1)*alpha)
                  + cos(alpha)*sin((n-1)*alpha) when fixp n,
  cos(~n*~alpha) => cos(alpha)*cos((n-1)*alpha)
                  - sin(alpha)*sin((n-1)*alpha) when fixp n,
  sin(~alpha)**2 => 1 - cos(alpha)**2,
  sinh(~alpha+~beta) => sinh(alpha)*cosh(beta) + cosh(alpha)*sinh(beta),
  cosh(~alpha+~beta) => cosh(alpha)*cosh(beta) + sinh(alpha)*sinh(beta),
  sinh(~n*~alpha) => sinh(alpha)*cosh((n-1)*alpha)
                   + cosh(alpha)*sinh((n-1)*alpha) when fixp n,
  cosh(~n*~alpha) => cosh(alpha)*cosh((n-1)*alpha)
                   + sinh(alpha)*sinh((n-1)*alpha) when fixp n,
  sinh(~alpha)**2 => cosh(alpha)**2 - 1};

solvealg!-rules2:=
{ tan(~alpha) => sin(alpha)/cos(alpha),
  cot(~alpha) => cos(alpha)/sin(alpha),
  tanh(~alpha) => sinh(alpha)/cosh(alpha),
  coth(~alpha) => cosh(alpha)/sinh(alpha) } ;

solvealg!-rules3:=
{ sin(~alpha)**2 => 1 - cos(alpha)**2,
  sinh(~alpha)**2 => cosh(alpha)**2 - 1};

% Artificial operator for matching powers in a
% product.

operator my!-expt;

solvealg!-rules4:=
 {  my!-expt(~a,~b)*my!-expt(a,~c) => my!-expt(a,b+c),
    my!-expt(~a,~b)*a => my!-expt(a,b+1)
 %  my!-expt(~a,~b)/my!-expt(a,~c) => my!-expt(a,b-c)
  };

>>;

symbolic procedure solvenonlnrsys(sys,uv);
  % interface to algebraic system solver.
  % factorize the system and collect solutions.
  % After factoring we resimplify with *expandexpt off
  % in order to have exponentials to one basis
  % collected.
  begin scalar q,r,s,tag,!*expandexpt;
   s:='(nil);
   if solve!-psysp(sys,uv) then
    s:={sys} else
   for each p in sys do
   <<r:= nil;
    for each q in cdr fctrf p do
     for each u in s do r:= (car q.u).r;
    s:=r;
   >>;
   tag:='failed; r:=nil;
   for each u in s do
   <<% collect exponentials with same base.
     u := solvenonlnrcollectexpt u;
     q:=solvenonlnrsys1(u,uv);
     if eqcar(q,'failed) then
              q:=solvenonlnrsyssep(u,uv);
     if eqcar(q,'failed) then
              q:=solvenonlnrsyslin(u,uv,nil);
     if eqcar(q,'not) then
              q:=solvenonlnrsyslin(u,uv,t);
     if eqcar(q,'not) then q:='(failed);
     if car q and car q neq 'failed then tag:=car q;
     q:= if car q neq 'failed then cdr q else
       for each j in u collect {{j ./ 1},nil,1};
     r:=union(q,r);
   >>;
   return if tag eq 'inconsistent or tag eq 'failed then {tag}
       else tag.r
  end;

symbolic procedure solvenonlnrcollectexpt u;
  % u is a list of standard forms. Reform these
  % such that products of exponentials with same basis
  % are collected.
   if not smemq('expt,u) then u else
   <<eval'(let0 '(solvealg!-rules4));

     u:=for each q in u collect
        numr simp subst('expt,'my!-expt,
          reval prepf subst('my!-expt,'expt,q));
     eval'(clearrules '(solvealg!-rules4));
     u>>;

symbolic procedure solvenonlnrsyslin(eqs,vars,mode);
 % Eqs is a system of equations (standard forms,
 % implicitly equated to zero); this routine tries
 % to reduce the system recursively by separation,
 % if one variable occurs in one equation only linearly.
 % Mode=NIL: simple version: only pure linear variables
 %           are substituted.
 %      T:   extended version: replacing variables with
 %           degree 1 and potentially complicated
 %           coefficients.
 % Returns solution or
 %     '(not)   if not applicable
 %     '(failed) if applicable but solution failed.
  begin scalar d,e,e1,n,s,q,x,v,w,w1,neqs,nvars;
   v:=vars;
 var_loop:
   if null v then return '(not);
   x:=car v; v:=cdr v;
   w:=eqs;
 eqn_loop:
   if null w then goto var_loop;
   e:=car w; w:=cdr w;
   if null e then goto eqn_loop;
   if domainp e then return '(inconsistent);
   e1:= reorder e where kord!*={x};
   if not(mvar e1 =x) or ldeg e1>1 or
     smemq(x,d:=lc e1) or smemq(x,n:=red e1) then goto eqn_loop;
   if not mode then
   <<w:=nil;
     for each y in vars do w:=w or smemq(y,d);
     if w then return '(not); >>;
    % linear form found: n*x+d=0. This is basis for a solution
    % x=-n/d. In a second branch the case {n=0,d=0} has to
    % be considered if n and d are not constants.
   n := reorder n; d:=reorder d;
    % Step 1: substitute in remaining equations, solve
    % and add linear formula to result.
   s:= quotsq(negf n ./ 1, d ./ 1);
   neqs := for each eqn in delete(e,eqs) join
     <<q:=numr subf(eqn,{x.prepsq s}); if q then {q}>>;
   nvars:=for each y in delete(x,vars) join
    if smemq(y,neqs) then {y};
   w:= if null neqs then '(t (nil nil 1)) else
    if null nvars then '(inconsistent) else
    if cdr neqs then solvenonlnrsys(neqs,nvars)
    else solvenonlnrsysone(car neqs,car nvars);
   if car w eq 'failed then return w;
   w:=add!-variable!-to!-tagged!-solutions(x,s,w);
    % Step 2: add an eventual solution for n=0,d=0;
   if domainp d or not mode then return w;
   w1:=solvenonlnrsys(n.d.eqs,vars);
   return merge!-two!-tagged!-solutions(w,w1);
 end;

symbolic procedure solvenonlnrsysone(f,x);
 % equation system has been reduced to one. Using solvesq.
  begin scalar w;
   w:=solvesq(f ./ 1,x,1);
   if null w then return '(inconsistent)
   else if null cadr car w then return '(failed);
%  if not smemq('root_of,w) then goto ret;
%    % here we try to find out whether a root_of
%    % expression is a useful information or whether
%    % it is simply an echo of the input.
%  if cdr w then goto ret; % multiple branches: good.
%  q := prepsq caar car w;
%  if not eqcar(q,'root_of) % not on top level: good.
%     then goto ret;
%  q:=subst(x,caddr q,cadr q);
%  if f = numr simp q then return '(failed);
%ret:
   return t.w;
  end;

symbolic procedure add!-variable!-to!-tagged!-solutions(x,s,y);
  % Y is a tagged solution. Add equation x=s to all members.
  if eqcar(y,'inconsistent) then y else
  if null y or null cdr y then {t,{{s},{x},1}} else
  car y . for each q in cdr y collect
   % Put new solution into the last position.
     {append(car q,{s}),append(cadr q,{x}),caddr q};

symbolic procedure merge!-two!-tagged!-solutions(w1,w2);
  % w1 and w2 are tagged solution sets. Merge these and
  % eliminated inconsistent cases.
  if car w1='failed or car w2='failed then '(failed) else
  if car w1='inconsistent then w2 else
  if car w2='inconsistent then w1 else
  car w1 . append(cdr w1,cdr w2);


symbolic procedure solvenonlnrsyssep(eqs,vars);
 % Eqs is a system of equations (standard forms,
 % implicitly equated to zero); this routine tries
 % to reduce the system recursively by separation,
 % if one variable occurs only in one equation.
  begin scalar y,r,s,r0,u,w,tag;
   if null vars then return '(failed) else
   if null cdr eqs then
   <<if not smember(car vars,car eqs) then
        return solvenonlnrsyssep(eqs,cdr vars);
     r:=solvesq(!*f2q car eqs,car vars,1);
     return if r and cadr car r then 't.r else '(failed);
   >>;
   for each x in vars do if null y then
   <<r:=nil;
     for each u in eqs do if smember(x,u) then
       r:=u.r;
     if r and null cdr r then y:=x;
   >>;
   if null y then return '(failed);
   r:=car r;
   s:=solvenonlnrsys(delete(r,eqs),delete(y,vars));
   if car s='failed then return s else s:=cdr s;
   tag := t;
   u:=for each s0 in s join
   <<
     w:=for each q in pair(cadr s0,car s0) join
      if not smemq('root_of,cdr q) then
          {car q.prepsq cdr q};
     r0:=subf(r,w);
     r0:=solvesq(r0,y,caddr s0);
     if null r0 or null cadr car r0 then tag:='failed;
     for each r1 in r0 collect
      {caar r1. car s0,y.cadr s0,caddr r1}
   >>;
   return tag.u;
 end;

symbolic procedure solve!-psysp(s,uv);
  % T if s is a pure polynomial system.
 null s or (solve!-psysp1(car s,uv) and solve!-psysp(cdr s,uv));

symbolic procedure solve!-psysp1(f,uv);
  domainp f or
  ((member(mvar f,uv) or solve!-psysp2(mvar f,uv))
     and solve!-psysp1(lc f,uv) and solve!-psysp1(red f,uv));

symbolic procedure solve!-psysp2(v,uv);
  % t if there is no interaction between v and uv.
 null uv or (not smember(car uv,v) and solve!-psysp2(v,cdr uv));

symbolic procedure solvenonlnrsys1(system!*,uv!*);
  % solve one system.
  begin scalar r,rules;
    osystem!* := system!*;
    if solvealgtrig0 system!* then rules:='(solvealg!-rules1);
    if smemq('tan,system!*) or smemq('cot,system!*) or
       smemq('tanh,system!*) or smemq('coth,system!*) then
      rules:='solvealg!-rules2.rules;
    r := evalletsub2({rules,'(solvenonlnrsyspre)},nil);
    if errorp r then return '(failed) else system!* := car r;
    r := solvenonlnrsys2();
    return r;
  end;

symbolic procedure solvenonlnrsyspre();
   (for each p in system!* collect numr simp prepf p)
      where dmode!* = nil;

symbolic procedure solvenlnrsimp(u);
 % a prepsq including resimplification with additional rules.
% begin scalar r;
%   r := evalletsub2({'(solvealg!-rules3),
%                      {'simp!* ,mkquote u}},nil);
%   if errorp r then error(99,list("error during postprocessing simp"));
%   return car r;
% end;
      simp!* u;

symbolic procedure solvenonlnrsys2();
  % Main driver. We need non-local exits here
  % because of possibly hidden non algebraic variable
  % dependencies.
  if null !*solvealgp then system!*:='(failed) else % against recursion.
  (begin scalar iv!*,kl!*,inv!*,fv!*,r,w,!*solvealgp,solvealgdb!*,sub!*;
         scalar last!-vars!*,groebroots!*,const!-vars!*,root!-vars!*;
         % preserving the variable sequence if *varopt is off
      if not !*varopt then depl!* :=
        append(pair(uv!*,append(cdr uv!*,{gensym()})),depl!*);
         % hiding dmode because exponentials need integers.
      for each f in system!* do solvealgk0
         (if dmode!* then numr subf(f,nil) where dmode!*=nil else f);
      if !*trnonlnr then print list("original kernels:",kl!*);
      if null cdr system!* then
          if (smemq('sin,system!*)or smemq('cos,system!*)) and
             (r:=solvenonlnrtansub(prepf(w:=car system!*),car uv!*))
             and car r
            then return solvenonlnrtansolve(r,car uv!*,w)
           else if (smemq('sinh,system!*)or smemq('cosh,system!*)) and
             (r:=solvenonlnrtanhsub(prepf(w:=car system!*),car uv!*))
             and car r
            then return solvenonlnrtanhsolve(r,car uv!*,w);
      if atom (errorset('(solvealgk1),!*trnonlnr,nil)) where dmode!*=nil
         then return (system!*:='(failed));
      system!*:='list.for each p in system!* collect prepf p;
      if not('groebner memq loaded!-packages!*)
        then load!-package 'groebner;
      for each x in iv!* do if not member(x,last!-vars!*) then
        for each y in last!-vars!* do depend1(x,y,t);
      iv!* := sort(iv!*,function (lambda(a,b);depends(a,b)));
      if !*trnonlnr then
      <<  prin2t "Entering Groebner for system";
          writepri(mkquote system!*,'only);
          writepri(mkquote('list.iv!*), 'only);
      >>;
      r := list(system!*,'list.iv!*);
      r := groesolveeval r;
      if !*trnonlnr then
      <<  prin2t "leaving Groebner with intermediate result";
          writepri(mkquote r,'only);
          terpri(); terpri();
      >>;
      if 'sin memq solvealgdb!* then r:=solvealgtrig2 r;
      if 'sinh memq solvealgdb!* then r:=solvealghyp2 r;
      r:= if r='(list) then '(inconsistent) else solvealginv r;
      system!* := r;  % set value aside
      return r;
  end) where depl!*=depl!* ;

symbolic procedure solvealgk0(p);
   % Extract new top level kernels from form p.
    if domainp p then nil else
    <<if not member(mvar p,kl!*)
       and not member(mvar p,iv!*)
             then kl!*:=mvar p.kl!*;
      solvealgk0(lc p);
      solvealgk0(red p)>>;

symbolic procedure solvealgk1();
   % Process all kernels in kl!*. Note that kl!* might
   % change during processing.
    begin scalar k,kl0,kl1;
      k := car kl!*;
      while k do
       <<kl0 := k.kl0;
         solvealgk2(k);
         kl1 := kl!*; k:= nil;
         while kl1 and null k do
          if not member(car kl1,kl0) then k:=car kl1
              else kl1:=cdr kl1;
       >>;
    end;

symbolic procedure solvealgk2(k);
   % Process one kernel.
     (if member(k,uv!*) then solvealgvb0 k and (iv!*:= k.iv!*) else
      if atom k then t else
      if eq(car k,'expt) then solvealgexpt(k,x) else
      if memq(car k,'(sin cos tan cot)) then
            solvealgtrig(k,x) else
      if memq(car k,'(sinh cosh tanh coth)) then
            solvealghyp(k,x) else
      if null x then t else
         solvealggen(k,x)
      ) where x=solvealgtest(k);

symbolic procedure solvealgtest(k);
  % Test if the arguments of a composite kernel interact with
  % the variables known so far.
   if atom k then nil else solvealgtest0(k);

symbolic procedure solvealgtest0(k);
  % Test if kernel k interacts with the known variables.
   solvealgtest1(k,iv!*) or solvealgtest1(k,uv!*);

symbolic procedure solvealgtest1(k,kl);
  % list of those kernels in list kl, which occur somewhere
  % in the composite kernel k.
  if null kl then nil else
  if member(k,kl) then list k else
  if atom k then nil else
  union(if smember(car kl,cdr k) then list car kl else nil,
        solvealgtest1(k,cdr kl));

symbolic procedure solvealgvb k;
  % Restricted variables are those which might establish
  % non-algebraic relations like e.g. x + e**x. Test k
  % and add it to the list.
       fv!* := append(solvealgvb0 k,fv!*);

symbolic procedure solvealgvb0 k;
 % test for restricted variables.
   begin scalar ak;
    ak := allkernels(k,nil);
    if intersection(ak,iv!*) or intersection(ak,fv!*) then
     error(99,list("transcendental variable dependency from",k));
    return ak;
   end;

symbolic procedure allkernels(a,kl);
  % a is an algebraic expression. Extract all possible inner
  % kernels of a and collect them in kl.
   if numberp a then kl else
   if atom a or a member uv!*
        then if not member(a,kl) then a.kl else kl else
   <<for each x in cdr a do
       kl := allkernels1(numr s,allkernels1(denr s,kl))
               where s=simp x;
     kl>>;

symbolic procedure allkernels1(f,kl);
   if domainp f then kl else
   <<if not member(mvar f,kl) then
       kl:=allkernels(mvar f,mvar f . kl);
     allkernels1(lc f, allkernels1(red f,kl)) >>;

symbolic procedure solvealgexpt(k,x);
   % kernel k is an exponential form.
  ( if eqcar(m,'quotient) and fixp caddr m then
         if cadr m=1 then solvealgrad(cadr k,caddr m,x)
            else solvealgradx(cadr k,cadr m,caddr m,x)
    else if null x then solvealgid k
    else if ((null intersection(w,uv!*) and
              null intersection(w,iv!*) and
              null intersection(w,fv!*))
         where w=allkernels(m,nil))
      then solvealggen(k,x)
    else solvealgexptgen(k,x)
     ) where m = caddr k;

symbolic procedure solvealgexptgen(k,x);
   % Kernel k is a general exponentiation u ** v.
  begin scalar bas,xp,nv;
     bas := cadr k; xp := caddr k;
     if solvealgtest1(xp,uv!*) then return solvealgexptgen1(k,x)
       else if solvealgtest1(bas,uv!*) then return solvealggen(k,x);
     % remaining case: "constant" exponential expression to
     % replaced by an id for syntatical reasons
   nv := '(
       % old kernel
      ( (expt !&alpha n))
       % new variable
      ( !&beta)
       % substitution
      ( ((expt !&alpha n) . !&beta) )
       % inverse
      ( (!&beta (expt !&alpha n) !& ))
       % new equations
      nil
          );
    nv:=subst(bas,'!&alpha,nv);
    nv:=subst(solve!-gensym(),'!&beta,nv);
    nv:=subst(xp,'n,nv);
    return solvealgupd(nv,nil);
   end;

symbolic procedure solvealgexptgen1(k,x);
   % Kernel k is a general exponentiation u ** v.
   % where v is an expression in a solution variable, u
   % is constant. Transform all kernels with same basis
   % and compatible exponent to common exponent denominator
   % form.
  begin scalar bas,xp,xpl,q,r,nk,sub;
     bas := cadr k; xp := caddr k;
      % collect all exponentials with this basis.
     xpl:={(1 ./ 1).xp};
     for each k in kl!* do
       if eqcar(k,'expt) and cadr k=bas and
        <<q:=simp{'quotient,r:=caddr k,xp};
          fixp numr q and fixp denr q>> then
       <<kl!*:=delete(k,kl!*); xpl:=(q.r).xpl>>;
       % compute common denominator.
     q:=1; for each e in xpl do q:=lcm(q,denr car e);
       % the new artificial kernel.
     nk:=reval{'expt,bas,{'quotient,xp,q}};
     sub := for each e in xpl collect
       {'expt,bas,cdr e}.
       {'expt,nk,numr car e * q/denr car e};
     system!*:=sublis(sub,system!*);
     return solvealggen(nk,x);
 end;

symbolic procedure solvealgradx(x,m,n,y);
   %   error(99,"forms e**(x/2) not yet implemented");
   solvealgexptgen1({'expt,x,{'quotient,m,n}},y);

symbolic procedure solvealgrad(x,n,y);
  % k is a radical exponentiation expression x**1/n.
  begin scalar nv,m,!&beta;
    !&beta := solve!-gensym();
    nv:= '(
       % old kernel
      ( (expt !&alpha (quotient 1 !&n)))
       % new variable
      ( !&beta)
       % substitution
      ( ((expt !&alpha (quotient 1 !&n)) . !&beta) )
       % inverse
  %   ( (!&beta !&alpha (expt !& !&n)) )
  nil
       % new equation
      ( (difference (expt !&beta !&n) !&alpha) )
          );
    m := list('!&alpha.x,'!&beta.!&beta,'!&n.n);
    nv := subla(m,nv);
    root!-vars!* := !&beta . root!-vars!*;
      % prepare roots for simple surds.
    if null y or y={x} then groebroots!* :=
     ({'plus,{'expt,!&beta,n},reval{'minus,x}}
       .{{{'equal,!&beta,{'expt,x,{'quotient,1,n}}}}}).groebroots!*;
    if null y then last!-vars!* := !&beta . last!-vars!*;
    return solvealgupd(nv,y);
  end;

symbolic procedure solvealgtrig0(f);
  % examine if sin/cos identies must be applied.
  begin scalar args,r,c;
   args :=for each a in solvealgtrig01(f,nil) collect
     (union(kernels numr q,kernels denr q) where q=simp a);
   while args do
   <<c:=car args;args:=cdr args;
     for each q in args do r:=r or intersection(c,q)>>;
   return r;
  end;

symbolic procedure solvealgtrig01(f,args);
  if atom f then args else
  if memq(car f,'(sin cos tan cot sinh cosh tanh coth)) then
     if constant_exprp cadr f then args else union({cadr f},args)
  else solvealgtrig01(cdr f,solvealgtrig01(car f,args));

algebraic <<
   operator p_sign,the_1;
   let p_sign(~x) => if sign(x)=0 then 1 else sign(x);
   let the_1(~x) =>1;
          >>;

symbolic procedure solvealgtrig(k,x);
  % k is a trigonometric function call.
  begin scalar nv,m,s,!&alpha,!&beta;
    solvealgdb!* := union('(sin),solvealgdb!*);
    if x then
      if cdr x then
       error(99,"too many variables in trig. function")
      else x := car x;
    solvealgvb k;
    nv := '(
       % old kernels
      ( (sin !&alpha)(cos !&alpha)(tan !&alpha)(cot !&alpha) )
       % new variables
      ( (sin !&beta) (cos !&beta) )
       % substitutions
      ( ((sin !&alpha) . (sin !&beta))
        ((cos !&alpha) . (cos !&beta))
        %%% these should be handled now by the ruleset.
        %%% ((tan !&alpha) . (quotient (sin !&beta) (cos !&beta)))
        %%% ((cot !&alpha) . (quotient (cos !&beta) (sin !&beta)))
      )
       % inverses
      (
            ((sin !&beta)
             (cond ((and !*expli (test_trig))
                         '(!&loc (p_sign (!&!& !&))))
                   (t    '(!&x (!&!& (root_of (equal (sin !&alpha)
                                        !&) !&x))))))
            ((cos !&beta)
             (cond ((and !*expli (test_trig))
                         '(!&x (plus (!&!& (times !&loc (acos !&)))
                           (times 2 pi !&arb))))
                   (t    '(!&x (!&!& (root_of (equal (cos !&alpha)
                                               !&) !&x))))))
      )
       % new equation
      ( (plus (expt (sin !&beta) 2)(expt (cos !&beta) 2) -1) )
          );
     % invert the inner expression.
    s := if x then solvealginner(cadr k,x) else 'the_1;
    !&beta := solve!-gensym();
    m := list('!&alpha . (!&alpha:=cadr k),
              '!&beta . !&beta,
              '!&loc . solve!-gensym(),
              '!&arb . {'arbint,!!arbint:=!!arbint+1},
              '!&x    . x,
              '!&!& . s);
    nv:=sublis!-pat(m , nv);
    if x then last!-vars!*:=
        append(last!-vars!*,{{'sin,!&beta},{'cos,!&beta}})
      else const!-vars!* :=
        append(const!-vars!*,{{'sin,!&beta}.{'sin,!&alpha},
                  {'cos,!&beta}.{'cos,!&alpha}});
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealghyp(k,x);
  % k is a hyperbolic function call.
  begin scalar nv,m,s,!&alpha,!&beta;
    solvealgdb!* := union('(sinh),solvealgdb!*);
    if x then
      if cdr x then
       error(99,"too many variables in hyp. function")
      else x := car x;
    solvealgvb k;
    nv := '(
       % old kernels
      ( (sinh !&alpha)(cosh !&alpha)(tanh !&alpha)(coth !&alpha) )
       % new variables
      ( (sinh !&beta) (cosh !&beta) )
       % substitutions
      ( ((sinh !&alpha) . (sinh !&beta))
        ((cosh !&alpha) . (cosh !&beta))
      )
       % inverses
      (
            ((sinh !&beta)
             (cond ((and !*expli (test_hyp))
                         '(!&loc (p_sign (!&!& !&))))
                   (t    '(!&x (!&!& (root_of (equal (sinh !&alpha)
                                        !&) !&x))))))
            ((cosh !&beta)
             (cond ((and !*expli (test_hyp))
                         '(!&x (plus (!&!& (times !&loc (acosh !&)))
                           (times 2 pi i !&arb))))
                   (t    '(!&x (!&!& (root_of (equal (cosh !&alpha)
                                               !&) !&x))))))
      )
       % new equation
      ( (plus (minus (expt (sinh !&beta) 2))(expt (cosh !&beta) 2) -1) )
          );
     % invert the inner expression.
    s := if x then solvealginner(cadr k,x) else 'the_1;
    !&beta := solve!-gensym();
    m := list('!&alpha . (!&alpha:=cadr k),
              '!&beta . !&beta,
              '!&loc . solve!-gensym(),
              '!&arb . {'arbint,!!arbint:=!!arbint+1},
              '!&x    . x,
              '!&!& . s);
    nv:=sublis!-pat(m , nv);
    if x then last!-vars!*:=
        append(last!-vars!*,{{'sinh,!&beta},{'cosh,!&beta}})
      else const!-vars!* :=
        append(const!-vars!*,{{'sinh,!&beta}.{'sinh,!&alpha},
                  {'cosh,!&beta}.{'cosh,!&alpha}});
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealgtrig2 u;
  % r is a result from goesolve; remove trivial relations
  % like sin^2 + cos^2 = 1.
  begin scalar r,w,op,v,rh;
   for each s in cdr u do
   <<w := nil;
     for each e in s do
         % delete "sin u = sqrt(-cos u^2+1)" etc
      if eqcar(e,'equal) and
         (eqcar(cadr e,'sin) or eqcar(cadr e,'cos)) and
         (op := caadr e) and (v := cadr cadr e) and
         member(if eqcar(rh:=caddr e,'!*sq!*) then cadr rh else rh,
          subst({if op='sin then 'cos else 'sin,v},'!-form!-,
               '((minus (sqrt (plus (minus (expt !-form!- 2)) 1)))
                 (sqrt (plus (minus (expt !-form!- 2)) 1)))))
          then nil
       else w:=e.w;
     w := reverse w;
     if not member(w,r) then r:=w.r;
    >>;
    return 'list . reverse r;
  end;

symbolic procedure solvealghyp2 u;
  % r is a result from goesolve; remove trivial relations
  % like cosh^2 - sinh^2 = 1.
  begin scalar r,w,op,v,rh;
   for each s in cdr u do
   <<w := nil;
     for each e in s do
        % delete "sinh u = sqrt(cosh u^2-1)","cosh u = sqrt(sinh u^2+1)"
      if eqcar(e,'equal) and
         (eqcar(cadr e,'sinh) or eqcar(cadr e,'cosh)) and
         (op := caadr e) and (v := cadr cadr e) and
         member(if eqcar(rh:=caddr e,'!*sq!*) then cadr rh else rh,
          if op='sinh then
            subst({'cosh,v},'!-form!-,
                  '((minus (sqrt (plus (expt !-form!- 2) 1)))
                    (sqrt (plus (expt !-form!- 2) 1))))
           else
            subst({'sinh,v},'!-form!-,
                  '((minus (sqrt (plus (expt !-form!- 2) (minus 1))))
                    (sqrt (plus (expt !-form!- 2) (minus 1))))))
         then nil
       else w:=e.w;
     w := reverse w;
     if not member(w,r) then r:=w.r;
    >>;
    return 'list . reverse r;
  end;

symbolic procedure solvealggen(k,x);
  % k is a general function call; processable if SOLVE
  % can invert the function.
  begin scalar nv,m,s;
    if cdr x then
       error(99,"too many variables in function expression");
    x := car x;
    solvealgvb k;
    nv := '(
       % old kernels
      ( !&alpha )
       % new variables
      ( !&beta )
       % substitutions
      ( ( !&alpha . !&beta) )
       % inverses
      (( !&beta '(!&x (!&!& !&))))
       % new equation
      nil);
     % invert the kernel expression.
    s :=  solvealginner(k,x);
    m := list('!&alpha .  k,
              '!&beta . solve!-gensym(),
              '!&x    . x,
              '!&!& . s);
    nv:=sublis!-pat(m , nv);
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealgid k;
  % k is a "constant" kernel, however in a syntax unprocessable
  % for Groebner (e.g. expt(a/2)); replace temporarily
  begin scalar nv,m;
    nv := '(
       % old kernels
      ( !&alpha )
       % new variables
      ( )
       % substitutions
      ( ( !&alpha . !&beta) )
       % inverses
      (( !&beta nil . !&alpha))
       % new equation
      nil);
     % invert the kernel expression.
    m := list('!&alpha .  k, '!&beta . solve!-gensym());
    nv:=sublis(m , nv);
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealginner(s,x);
   <<s := solveeval list(list ('equal,s,'!#), list('list,x));
    s := reval cadr s;
    if not eqcar(s,'equal) or not equal(cadr s,x) then
        error (99,"inner expression cannot be inverted");
    {'lambda,'(!#),caddr s}>>;

symbolic procedure solvealgupd(u,innervars);
  % Update the system and the structures.
  begin scalar ov,nv,sub,inv,neqs;
    ov := car u; u := cdr u;
    nv := car u; u := cdr u;
    sub:= car u; u := cdr u;
    inv:= car u; u := cdr u;
    neqs:=car u; u := cdr u;
    for each x in ov do kl!*:=delete(x,kl!*);
    for each x in innervars do
      for each y in nv do depend1(y,x,t);
    sub!* := append(sub,sub!*);
    iv!* := append(nv,iv!*);
    inv!* := append(inv,inv!*);
    system!* := append(
      for each u in neqs collect
        <<u:= numr simp u; solvealgk0 u; u>>,
      for each u in system!* collect numr subf(u,sub) );
    return t;
  end;

symbolic procedure solvealginv u;
  % Reestablish the original variables, produce inverse
  % mapping and do complete value propagation.
 begin scalar v,r,s,m,lh,rh,y,z,tag,sub0,sub,!*expli,noarb,arbs;
       scalar abort;
      integer n;
 sub0 := for each p in sub!*  collect (cdr p.car p);
 tag := t;
 r := for each sol in cdr u join
  <<sub := sub0; abort := v:= r:= s:= noarb :=arbs :=nil;
    if !*test_solvealg then
    <<prin2t "================================";
      prin2t const!-vars!*;
      prin2t " next basis:";
      writepri(mkquote sol,'only);
    >>;
    for each eqn in reverse cdr sol do
    <<lh := cadr eqn; rh := subsq(simp!* caddr eqn,s);
      if !*test_solvealg then
          writepri(mkquote {'equal,lh,prepsq rh},'only);
      !*expli:=member(lh,iv!*);
        % look for violated constant relations.
      if (y:=assoc(lh,const!-vars!*)) and constant_exprp prepsq rh
         and numr subtrsq(rh,simp cdr y) then abort := t;
        % look for a "negative" root.
      if memq(lh,root!-vars!*) and numberp(y:=reval{'sign,prepsq rh})
        and y<0 then abort := t;
      if not !*expli then noarb := t;
      if !*expli and not noarb then
      << % assign value to free variables;
        for each x in uv!* do
         if !*arbvars and solvealgdepends(rh,x) and not member(x,fv!*)
             and not member(x,arbs) then
           <<z := mvar makearbcomplex();
             y := z; v := x . v; r := simp y . r;
          %  rh := subsq(rh,list(x.y));
          %  s := (x . y) . s;
             arbs:=x.arbs;
           >>;
       if not smemq('root_of,rh) then
               s:=(lh.prepsq rh).s
           else fv!*:=lh.fv!*;
      >>;
      if (m:=assoc(lh,inv!*))then
      <<m:=cdr m; lh :=car m; kl!* := eqn;
        if eqcar(lh,'cond) or eqcar(lh,'quote) then
              lh:=car(m:=eval lh);
        rh:=solvenlnrsimp subst(prepsq rh,'!&,cadr m)>>;
          % if local variable, append to substitution.
      if not member(lh,uv!*) and !*expli then
      << sub:=append(sub,{lh .(z:=prepsq subsq(rh,sub))});
         if smember(lh,r) then r:=subst(z,lh,r)
      >>;
          % append to the final output.
      if (member(lh,uv!*) or not !*expli)
               % inhibit repeated same values.
            and not<< z:=subsq(rh,sub);
                      n:=length member(z,r);
                      n>0 and lh=nth(v,length v + 1 - n)>>
         then <<r:=z.r; v:=lh.v;>>;
    >>;
      % Classify result.
  % for each x in uv!* do
  %   if tag and not member(x,v) and smember(x,r) then tag:=nil;
    if !*test_solvealg then
     if abort then yesp "ABORTED" else
    <<prin2t " --------> ";
      writepri(mkquote ('list .for each u in pair(v,r) collect
                {'equal,car u,prepsq cdr u}) ,'only);
      prin2t "================================";
      yesp "continue?";
    >>;
    if not abort then {reverse r . reverse v}
  >>;
  return solvealg!-verify(tag,r);
 end;

symbolic procedure solvealgdepends(u,x);
   % inspect u for explicit dependency of x, being careful for
   % root_of subexpressions.
  if u=x then t else if atom u then nil else
  if eqcar(u,'root_of) then
      if x=caddr u then nil else solvealgdepends(cadr u,x) else
    solvealgdepends(car u,x) or solvealgdepends(cdr u,x);

symbolic procedure test_trig();
  begin scalar lh,rh,r;
   lh := cadr kl!*; rh:= caddr kl!*;
   if member(lh . nil, solvealgdb!*) then return nil;
   r := not !*complex and not smemq('i,kl!*) and
      not smemq('!:gi!:,kl!*) and not smemq('!:cr!:,kl!*) and
      not smemq('root_of,kl!*);
   if not r then solvealgdb!* :=
     append(solvealgdb!*,{('sin.cdr lh).nil,('cos.cdr lh).nil});
   return r;
  end;

symbolic procedure test_hyp();
  begin scalar lh,rh,r;
   lh := cadr kl!*; rh:= caddr kl!*;
   if member(lh . nil, solvealgdb!*) then return nil;
   r := not !*complex and not smemq('i,kl!*) and
      not smemq('!:gi!:,kl!*) and not smemq('!:cr!:,kl!*) and
      not smemq('root_of,kl!*);
   if not r then solvealgdb!* :=
     append(solvealgdb!*,{('sinh.cdr lh).nil,('cosh.cdr lh).nil});
   return r;
  end;

fluid '(!*solvealg_verify);

% the idea of the following procedure is to exclude isolated
% solutions which give a substantial residue when subsituted
% into the equation system under "on rounded"; as long as no
% good criterion for a residue to be small has been found, this
% step is disabled.

symbolic procedure solvealg!-verify(tag,r);
  <<if !*rounded and !*solvealg_verify then
    begin scalar min,s,cmpl,!*msg;
     % exclude solutions with a residue substantially
     % above the minimum of all nonzero residues.
      cmpl:=!*complex;
      if not cmpl then setdmode('complex,!*complex:=t);
      s := for each u in r collect solvealg!-verify1 u.u;
      min:=simp'(quotient 1 100);
      r:= for each u in s join
       if null car u or minusf numr subtrsq(car u,min) then {cdr u};
      if not cmpl then
       <<setdmode('complex,nil); !*complex:=nil>>;
     end;
    tag . for each q in r collect car q . cdr q . list 1
  >>;

symbolic procedure solvealg!-verify1 s;
  % verify solution s for the current equation system.
  begin scalar sub,nexpli,x,y,sum,fail;
   sub:= for each u in pair(cdr s,car s) collect if not nexpli then
   <<y:=prepsq cdr u;
     if not (domainp y or constant_exprp y) then nexpli:=t;
     car u.y>>;
     % a non explicit solution cannot be tested.
   if nexpli then return nil;
   sum := nil ./ 1;
   for each u in osystem!* do if not fail then
    <<x:=subf(u,sub);
      if domainp numr x then
      sum:=addsq(sum,absf numr x ./ denr x)
        else fail := t;
    >>;
   return if fail then nil else sum;
  end;

symbolic procedure sublis!-pat(a,u);
  % like sublis, but replace lambda expressions by matching their
  % actual arguments.
  begin scalar v;
   if atom u then return
   <<v:=assoc(u,a); if v then sublis!-pat(a,cdr v) else u>>;
   v:=assoc(car u,a);
   if v and (v:=cdr v) and eqcar(v,'lambda) then return
      sublis!-pat((caadr v.cadr u).a,caddr v);
   return sublis!-pat1(a,u);
  end;

symbolic procedure sublis!-pat1(a,l);
  if null l then nil else
  if atom l then sublis!-pat(a,l) else
  sublis!-pat(a,car l) . sublis!-pat1(a,cdr l);

%----------------------------------------------------------------
% section for single trigonometric polynomials
%----------------------------------------------------------------

symbolic procedure solvenonlnrtansub(p,x);
  % Perform tangent substitution.
  if not smemq('sin,p) and not smemq('cos,p) then
    if smemq(x,p) then nil else nil.p
  else if car p='cos then
    if smemq(x,cdr p) then (cdr p).
       '(quotient (difference 1(expt tg!- 2)) (plus 1(expt tg!- 2)))
        else nil.p
  else if car p='sin then
    if smemq(x,cdr p) then (cdr p).
           '(quotient (times 2 tg!-) (plus 1(expt tg!- 2)))
        else nil.p
  else
  (if ca and cd and
     (car ca = car cd or null car ca or null car cd)
         then (car ca or car cd).(cdr ca.cdr cd))
       where ca=solvenonlnrtansub(car p,x),
             cd=solvenonlnrtansub(cdr p,x);

symbolic procedure solvenonlnrtansolve(u,x,w);
  begin scalar v,s,z,r,y;
    integer ar;
    % We reset arbint for each solve call such that equal forms can
    % be recognized by the function union.
   ar := !!arbint;
   v:=caar u; u:= prepf numr simp cdr u;
   s:=solveeval {u,'tg!-};
   !!arbint:=ar;
   for each q in cdr s do
   <<z:=reval caddr q;
     z:=reval sublis(solvenonlnrtansolve1 z,z);
     !!arbint:=ar;
     y:=solve0({'equal,{'tan,{'quotient,v,2}},z},x);
     r:=union(y,r);
   >>;
    % test for the special cases x=pi(not covered
    % by tangent substitution).
   if null numr subf(w,{x.'pi})
     then <<!!arbint:=ar; r:=union(solve0({'equal,{'cos,x},-1},x),r)>>;
   return t.r;
  end;

symbolic procedure solvenonlnrtansolve1 u;
  % Find all cos**2.
  if atom u then nil else
  if car u='expt and eqcar(cadr u,'cos) and caddr u=2 then
     {u . {'difference,1,{'expt,{'sin,cadr cadr u},2}}}
  else union(solvenonlnrtansolve1 car u,solvenonlnrtansolve1 cdr u);

%----------------------------------------------------------------
% section for single hyperbolic polynomials
%----------------------------------------------------------------

symbolic procedure solvenonlnrtanhsub(p,x);
  % Perform hyperbolic tangent substitution.
  if not smemq('sinh,p) and not smemq('cosh,p) then
    if smemq(x,p) then nil else nil.p
  else if car p='cosh then
    if smemq(x,cdr p) then (cdr p).
       '(quotient (plus 1(expt tgh!- 2)) (difference 1(expt tgh!- 2)))
        else nil.p
  else if car p='sinh then
    if smemq(x,cdr p) then (cdr p).
           '(quotient (times 2 tgh!-) (difference 1(expt tgh!- 2)))
        else nil.p
  else
  (if ca and cd and
     (car ca = car cd or null car ca or null car cd)
         then (car ca or car cd).(cdr ca.cdr cd))
       where ca=solvenonlnrtanhsub(car p,x),
             cd=solvenonlnrtanhsub(cdr p,x);

symbolic procedure solvenonlnrtanhsolve(u,x,w);
  begin scalar v,s,z,r,y,ar;
   ar := !!arbint;
   v:=caar u; u:= prepf numr simp cdr u;
   s:=solveeval {u,'tgh!-};
   ar := !!arbint;
   for each q in cdr s do
   <<z:=reval caddr q;
     z:=reval sublis(solvenonlnrtanhsolve1 z,z);
     !!arbint:=ar;
     y:=solve0({'equal,{'tanh,{'quotient,v,2}},z},x);
     r:=union(y,r);
   >>;
   if !*complex and null numr subf(w,{x.'(times pi i)})
     then <<!!arbint:=ar; r:=union(solve0({'equal,{'cosh,x},-1},x),r)>>;
   return t.r;
  end;

symbolic procedure solvenonlnrtanhsolve1 u;
  % Find all cosh**2.
  if atom u then nil else
  if car u='expt and eqcar(cadr u,'cosh) and caddr u=2 then
     {u . {'plus,1,{'expt,{'sinh,cadr cadr u},2}}}
  else union(solvenonlnrtanhsolve1 car u,solvenonlnrtanhsolve1 cdr u);

endmodule;


module solvetab;   % Simplification rules for SOLVE.

% Author: David R. Stoutemyer.

% Modifications by: Anthony C. Hearn, Donald R. Morrison, Rainer
%                   Schoepf and Herbert Melenk.

put('asin, 'inverse, 'sin);

put('acos, 'inverse, 'cos);

put('atan,'inverse,'tan);

put('acot,'inverse,'cot);

put('asec,'inverse,'sec);

put('acsc,'inverse,'csc);

algebraic;

Comment Rules for reducing the number of distinct kernels in an
   equation;

operator sol;

% for all a,b,c,d,x such that ratnump c and ratnump d let
%    sol(a**c-b**d, x) = a**(c*lcm(c,d)) - b**(d*lcm(c,d));

for all a,b,c,d,x such that not fixp c and ratnump c and
                            not fixp d and ratnump d let
   sol(a**c-b**d, x) = a**(c*lcm(den c,den d))
                     - b**(d*lcm(den c,den d));

for all a,b,c,d,x such that a freeof x and c freeof x let
   sol(a**b-c**d, x) = e**(b*log a - d*log c);

for all a,b,c,d,x such that a freeof x and c freeof x let
   sol(a*log b + c*log d, x) = b**a*d**c - 1;
%% sol(a*log b - c*log d, x) = b**a - d**c


for all a,b,c,d,f,x such that a freeof x and c freeof x let
   sol(a*log b + c*log d + f, x) = sol(log(b**a*d**c) + f, x);
%% sol(a*log b + c*log d - f, x) = sol(log(b**a*d**c) - f, x),
%% sol(a*log b - c*log d + f, x) = sol(log(b**a/d**c) + f, x),
%% sol(a*log b - c*log d - f, x) = sol(log(b**a/d**c) - f, x)


for all a,b,d,f,x such that a freeof x let
   sol(a*log b + log d + f, x) = sol(log(b**a*d) + f, x),
%% sol(a*log b + log d - f, x) = sol(log(b**a*d) - f, x),
   sol(a*log b - log d + f, x) = sol(log(b**a/d) + f, x);
%% sol(a*log b - log d - f, x) = sol(log(b**a/d) - f, x),
%% sol(log d - a*log b + f, x) = sol(log(d/b**a) + f, x),
%% sol(log d - a*log b - f, x) = sol(log(d/b**a) - f, x)


%%%%for all a,b,c,d,x such that a freeof x and c freeof x let
%%%%   sol(a*log b + c*log d, x) = b**a*d**c - 1,
%%%%   sol(a*log b - c*log d, x) = b**a - d**c;

for all a,b,d,x such that a freeof x let
   sol(a*log b + log d, x) = b**a*d - 1,
   sol(a*log b - log d, x) = b**a - d;
%% sol(log d - a*log b, x) = d - b**a;

for all a,b,c,x let
   sol(log a + log b + c, x) = sol(log(a*b) + c, x),
   sol(log a - log b + c, x) = sol(log(a/b) + c, x);
%% sol(log a + log b - c, x) = sol(log(a*b) - c, x),
%% sol(log a - log b - c, x) = sol(log(a/b) - c, x)


for all a,c,x such that c freeof x let
   sol(log a + c, x) = a - e**(-c);
%% sol(log a - c, x) = a - e**c;

for all a,b,x let
   sol(log a + log b, x) = a*b - 1,
   sol(log a - log b, x) = a - b,
%  sol(cos a - sin b, x) = sol(cos a - cos(pi/2-b), x),
%  sol(sin a + cos b, x) = sol(sin a - sin(b-pi/2), x),
%  sol(sin a - cos b, x) = sol(sin a - sin(pi/2-b), x),
   sol(sin a + sin b, x) = if !*allbranch then sin((a+b)/2)*
       cos((a-b)/2) else a+b,
   sol(sin a - sin b, x) = if !*allbranch then sin((a-b)/2)*
       cos((a+b)/2)  else a-b,
   sol(cos a + cos b, x) = cos((a+b)/2)*cos((a-b)/2),
   sol(cos a - cos b, x) = if !*allbranch then sin((a+b)/2)*
       sin((a-b)/2)  else a-b,
   sol(asin a - asin b, x) = a-b,
   sol(asin a + asin b, x) = a+b,
   sol(acos a - acos b, x) = a-b,
   sol(acos a + acos b, x) = a-b;

solve_trig_rules := {sin(~x + ~y) => sin x * cos y + cos x * sin y,
                     sin(~x - ~y) => sin x * cos y - cos x * sin y,
                     cos(~x + ~y) => cos x * cos y - sin x * sin y,
                     cos(~x - ~y) => cos x * cos y + sin x * sin y};

fluid '(solve_invtrig_soln!*);

share solve_invtrig_soln!*;

clear solve_invtrig_soln!*;

invtrig_solve_rules := {
   sol(asin(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,asin(x) + y,z),
   sol(acos(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,acos(x) + y,z),
   sol(atan(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('tan,atan(x) + y,z),
   sol(acos(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,acos(x) + y,z),
   sol(atan(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,atan(x) + y,z),
   sol(asin(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,asin(x) + y,z),
   sol(atan(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,atan(x) + y,z),
   sol(~n*asin(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,n*asin(x) + y,z),
   sol(~n*acos(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,n*acos(x) + y,z),
   sol(~n*acos(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,n*acos(x) + y,z),
   sol(~n*atan(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('sin,n*atan(x) + y,z),
   sol(~n*asin(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,n*asin(x) + y,z),
   sol(~n*atan(~x) + ~y,~z) => solve_invtrig_soln!*
                 when check_solve_inv_trig('cos,n*atan(x) + y,z)
};

let invtrig_solve_rules;

% The following rules allow REDUCE to solve some classes of equations
% where a variable appears inside and outside a log or an exponential.
% The results are based on Lambert's W (Omega) function which is fully
% supported in the specfn package. The ruleset has one central rule
% which produces the Omega function expression in the simplest (rather
% special) form, while the more general cases are mapped towards this
% rule by reforming the equation algebraically or by variable
% transformations.

lambert_rules := {
          % Basic solution of x=log(c*x/d)

    sol(~x + log(~~c*~x/~~d),~x) => x - lambert_w(d/c)
         when c freeof x and d freeof x,


          % General forms transformed to simpler ones.

    sol(~~a*~x + ~~b*log(~c) + ~w,x)
             => sol(a*x + b*log(c*e^(w/b)), x)
         when a freeof x and b freeof x and w freeof x
            and not(c freeof x),

    sol(~~a*~x + ~~b*log(~~c*x/~~d),x)
             => sub(x=a*x/b, sol(x + log(c*b*x/(a*d)),x))
         when (a neq 1 or b neq 1) and
          a freeof x and b freeof x and c freeof x and d freeof x,

    sol(~~a*~x + ~~b*log((~~c*x + ~u)/~~d),x)
             => sub(x=x+u/c, sol(num(a*(x-u/c) + b*log(c*x/d)),x))
         when
          a freeof x and b freeof x and c freeof x
             and d freeof x and u freeof x,

    sol(~~a*~x + ~~b*log((~~c*x^~n)/~~d),x)
             =>
               sol(num(a*x + n*b*log x + 1/n*log(c/d)),x)
         when
          a freeof x and b freeof x and c freeof x
             and d freeof x and n freeof x,

    sol(~~a*~x^~~n + ~~b*e^(~~c*~x/~~d),x)
            => sol(num(log(a) + n*log(x) - (log(-b)*d + c*x)/d), x)
         when
          a freeof x and b freeof x and c freeof x
             and d freeof x and n freeof x,

    sol(~~a*~x + ~~b*e^(~~c*~x/~~d) + ~f,x)
        => sub(x=a*x+f/a,sol(num(x + b*e^(-c*f/(a*d))*e^(c*x/(a*d))),x))
         when
          a freeof x and b freeof x and c freeof x
             and d freeof x and f freeof x
}$

% let lambert_rules;

symbolic procedure lambertp(e1,x);
        smemq('log,e1) or smemq('expt,e1);

symbolic;

fluid '(sol!-rulesets!*);

sol!-rulesets!*:={{'lambertp,'lambert_rules}};

symbolic procedure solve!-apply!-rules(e1,var);
  begin scalar rules,u;
    u:=list('sol,mk!*sq(e1 ./ 1), var);
    for each r in sol!-rulesets!* do
      if apply(car r,{e1,var}) then rules := cadr r . rules;
    if null rules then return simp!* u;
    return car evalletsub2({rules,{'simp!*, mkquote u}},nil);
  end;

endmodule;


module quartic;  % Procedures for solving cubic, quadratic and quartic
                 % eqns.

% Author: Anthony C. Hearn.
% Modifications by: Stanley L. Kameny.

fluid '(!*sub2 !*rounded !*trigform dmode!*);

!*trigform := t;   % Default value.

switch trigform;

symbolic procedure multfq(u,v);
   % Multiplies standard form U by standard quotient V.
   begin scalar x;
      x := gcdf(u,denr v);
      return multf(quotf(u,x),numr v) ./ quotf(denr v,x)
   end;

symbolic procedure quotsqf(u,v);
   % Forms quotient of standard quotient U and standard form V.
   begin scalar x;
      x := gcdf(numr u,v);
      return quotf(numr u,x) ./ multf(quotf(v,x),denr u)
   end;

symbolic procedure cubertq u;
   % Rationalizing the value in this and the following function leads
   % usually to neater results.
%  rationalizesq
      simpexpt list(mk!*sq subs2!* u,'(quotient 1 3));
   % simprad(u,3);

symbolic procedure sqrtq u;
%  rationalizesq
      simpexpt list(mk!*sq subs2!* u,'(quotient 1 2));
   % simprad(u,2);

% symbolic procedure subs2!* u; <<!*sub2 := t; subs2 u>>;

symbolic procedure solvequadratic(a2,a1,a0);
   % A2, a1 and a0 are standard quotients.
   % Solves a2*x**2+a1*x+a0=0 for x.
   % Returns a list of standard quotient solutions.
   % Modified to use root_val to compute numeric roots.  SLK.
   if !*rounded and numcoef a0 and numcoef a1 and numcoef a2
      then for each z in cdr root_val list mkpolyexp2(a2,a1,a0)
         collect simp!* z else
   begin scalar d;
      d := sqrtq subtrsq(quotsqf(exptsq(a1,2),4),multsq(a2,a0));
      a1 := quotsqf(negsq a1,2);
      return list(subs2!* quotsq(addsq(a1,d),a2),
                  subs2!* quotsq(subtrsq(a1,d),a2))
   end;

symbolic procedure numcoef a; denr a = 1 and domainp numr a;

symbolic procedure mkpolyexp2(a2,a1,a0);
  % The use of 'x is arbitrary here, since it is not used by root_val.
   <<a0 := numr a0;
     if numr a1 then a0 := (('x . 1) . numr a1) . a0;
     mk!*sq(((('x . 2) . numr a2) . a0) . 1)>>;

symbolic procedure solvecubic(a3,a2,a1,a0);
   % A3, a2, a1 and a0 are standard quotients.
   % Solves a3*x**3+a2*x**2+a1*x+a0=0 for x.
   % Returns a list of standard quotient solutions.
   % See Abramowitz and Stegun, Sect. 3.8.2, for details.
   begin scalar q,r,sm,sp,s1,s2,x;
      a2 := quotsq(a2,a3);
      a1 := quotsq(a1,a3);
      a0 := quotsq(a0,a3);
      q := subtrsq(quotsqf(a1,3),quotsqf(exptsq(a2,2),9));
      r := subtrsq(quotsqf(subtrsq(multsq(a1,a2),multfq(3,a0)),6),
                   quotsqf(exptsq(a2,3),27));
      if null numr q or not !*trigform or not all_real(a0,a1,a2)
        then go to cbr;
    % this section uses trig functions, but only when a0,a1,a2 are real.
      x := sqrtq negsq addsq(exptsq(q,3),exptsq(r,2));
      if one_real simp list('times,'i,mk!*sq x) and not pos_num q
         then x := negsq x;
      s1 := quotsqf(atan2q(x,r),3);
      s2 := negsq sqrtq negsq q;
      sp := negsq multfq(2,multsq(s2,cossq s1));
      sm := multsq(simp '(sqrt 3),multsq(s2,sinsq s1));
   % sp := -2*sqrt(-q)*cos(atan2(sqrt( - q**3 - r**2),r)/3)$
   % sm :=  - sqrt(-q)*sqrt(3)*sin(atan2(sqrt( - q**3 - r**2),r)/3)$
      go to com;
 cbr: x := sqrtq addsq(exptsq(q,3),exptsq(r,2));
      s1 := cubertq addsq(r,x);
      s2 := if numr s1 then negsq quotsq(q,s1)
             else cubertq subtrsq(r,x);
         % This optimization only works if s1 is non zero.
      sp := addsq(s1,s2);
      sm := quotsqf(multsq(simp '(times i (sqrt 3)),subtrsq(s1,s2)),2);
 com: x := subtrsq(sp,quotsqf(a2,3));
      sp := negsq addsq(quotsqf(sp,2),quotsqf(a2,3));
      return list(subs2!* x,subs2!* addsq(sp,sm),
                  subs2!* subtrsq(sp,sm))
   end;

symbolic procedure pos_num a;
   begin scalar r,dmode,!*msg,!*numval;
      dmode := dmode!*;
      !*numval := t;
      on rounded,complex;
      a := resimp a;
      a := real_1 a and (numr simp list('sign,mk!*sq a)=1);
      off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      return a end;

symbolic procedure sinsq a;
   simpiden list('sin,mk!*sq subs2!* a);

symbolic procedure cossq a;
   simpiden list('cos,mk!*sq subs2!* a);

symbolic procedure all_real(a,b,c);
   begin scalar r,dmode,!*msg,!*numval;
      dmode := dmode!*;
      !*numval := t;
      on complex,rounded;
      a := resimp a; b := resimp b; c := resimp c;
      a := real_1 a and real_1 b and real_1 c;
      off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      return a end;

symbolic procedure real_1 x;
   numberp denr x and domainp numr x and null numr impartsq x;

symbolic procedure one_real a;
   begin scalar r,dmode,!*msg,!*numval;
      dmode := dmode!*;
      !*numval := t;
      on complex,rounded;
      a := real_1 resimp a;
      off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      return a end;

symbolic procedure atan2q(b,a);
  % Used by solvecubic to set up trig form expressions for atan2 in
  % terms of atan and, where necessary, a bias of +/- pi; or to call
  % atan2 directly if numerical solution is called for.
  ((begin scalar !*msg,x,y,r,dmode,q,fg,s1,s2,s3,s4,s5;
      y := b := simp!*(b := mk!*sq subs2!* b);
      x := a := simp!*(a := mk!*sq subs2!* a);
      if domainp numr y and domainp numr x
         and numberp denr y and numberp denr x then go to aret;
      dmode := dmode!*;
      on complex,rounded;
      y := resimp b; x := resimp a;
      if not(domainp numr y and domainp numr x
         and numberp denr y and numberp denr x) then go to ret;
      q := sqrtq addsq(exptsq(x,2),exptsq(y,2));
      x := quotsq(x,q); y := quotsq(y,q);
      if null numr x then
         <<s1 := t;
           if numr simp list('sqn,list('repart,mk!*sq y))=-1
              then s2 := t;
           go to ret>>;
      s3 := t;
      x := numr simp list('sign,list('repart,mk!*sq x));
      if x=-1 then
         <<y := numr simp list('sign,list('repart,mk!*sq y));
           if y=-1 then s4 := t else s5 := t>>;
 ret: off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      if s1 then
         fg := quotsqf(simp 'pi,2);
      if s2 then fg := negsq fg;
      if s3 then fg := simpiden list('atan,mk!*sq quotsq(b,a));
      if s4 then fg := subtrsq(fg,simp 'pi);
      if s5 then fg := addsq(fg,simp 'pi);
aret: return if fg then fg else
         simpiden list('atan2,mk!*sq b,mk!*sq a) end)
    where !*numval=t);

symbolic procedure solvequartic(a4,a3,a2,a1,a0);
   % Solve the quartic equation a4*x**4+a3*x**3+a2*x**2+a1*x+a0 = 0,
   % where the ai are standard quotients, using technique described in
   % Section 3.8.3 of Abramowitz and Stegun;
   begin scalar x,y,yy,cx,z,s,l,zz1,zz2,r,dmode,neg,!*msg,!*numval;
      % Convert equation to monomial form.
      dmode := dmode!*;
      a3 := quotsq(a3,a4);
      a2 := quotsq(a2,a4);
      a1 := quotsq(a1,a4);
      a0 := quotsq(a0,a4);
      % Build and solve the resultant cubic equation.  We select the
      % real root if there is only one; or if there are three, we choose
      % one that yields real coefficients for the quadratics.  If no
      % roots are known to be real, we use an arbitrary one.
      yy := subtrsq(exptsq(a3,2),multfq(4,a2));
      x := solvecubic(!*f2q 1,
                      negsq a2,
                      subs2!* subtrsq(multsq(a1,a3),multfq(4,a0)),
                      subs2!* negsq addsq(exptsq(a1,2),
                                          multsq(a0,yy)));
      cx := car x;
      % Now check for real roots of the cubic.
      for each rr in x do if one_real rr then s := append(s,list rr);
      x := if (l := length s)=1 then car s else cx;
      % Now solve the two equivalent quadratic equations.
      a3 := quotsqf(a3,2); yy := quotsqf(yy,4);
      % select real coefficient for quadratic if possible.
      y := addsq(yy,x);
      if l<2 then go to zz;
loop: if not pos_num negsq y then go to zz else if l=1 then
        <<x := cx; y := addsq(yy,x); go to zz>>;
      l := l-1; s := cdr s; x := car s;
      y := addsq(yy,x); go to loop;
  zz: y := sqrtq y;
      x := quotsqf(x,2);
      z := sqrtq subtrsq(exptsq(x,2),a0);
     % the following test is needed, according to some editions of
     % Abramowitz and Stegun, to select the correct signs
     % (for the terms z) in the quadratics to produce correct roots.
     % Unfortunately, this test may fail for coefficients which are not
     % numeric because of the inability to recognize zero.
      !*numval := t;
      on rounded,complex;
      if null numr
         (zz1 :=
           resimp subtrsq(a1,addsq(multsq(subtrsq(a3,y),addsq(x,z)),
                 multsq(addsq(a3,y),subtrsq(x,z))))) then go to rst;
      if null numr
         (zz2 :=
           resimp subtrsq(a1,addsq(multsq(subtrsq(a3,y),subtrsq(x,z)),
                 multsq(addsq(a3,y),addsq(x,z)))))
         then <<neg := t; go to rst>>;
      if domainp numr zz1 and domainp numr zz2
             and numberp denr zz1 and numberp denr zz2 and
         numr simp list('sign,list('difference,list('norm,mk!*sq zz1),
           list('norm,mk!*sq zz2)))=1 then neg := t;
 rst: off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      if neg then z := negsq z;
      return append(solvequadratic(!*f2q 1,subtrsq(a3,y),subtrsq(x,z)),
                    solvequadratic(!*f2q 1,addsq(a3,y),addsq(x,z)))
   end;

endmodule;


end;
