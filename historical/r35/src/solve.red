module solve;   % Solve one or more algebraic equations.

% Author: David R. Stoutemyer.
% Major modifications by: Anthony C. Hearn, Herbert Melenk, Donald R.
% Morrison and Rainer Schoepf.

create!-package('(solve ppsoln solvelnr glsolve solvealg solvetab
                  quartic),nil);

% Other packages needed by solve package.

load!-package 'matrix;

fluid '(!*allbranch !*exp !*ezgcd !*fullroots !*limitedfactors
        !*multiplicities !*nonlnr !*notseparate !*numval !*numval!*
        !*rounded !*solvealgp !*solvesingular !!gcd !:prec!: asymplis!*
        dmode!* kord!* vars!* !*!*norootvarrenamep!*!*);

% NB: !*!*norootvarrenamep!*!* is internal to this module, and should
%     *never* be changed by a user.

fluid '(inside!-solveeval solve!-gensymcounter);

solve!-gensymcounter := 1;

global '(!!arbint multiplicities!*);

switch allbranch,fullroots,multiplicities,solvesingular;   % nonlnr.

put('fullroots,'simpfg,'((t (rmsubs))));

!*nonlnr := t;     % Put it on for now.

flag('(!*allbranch multiplicities!*),'share);

% ***** Some Non-local variables *****

!*allbranch     := t; % Returns all branches of solutions if T.
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

put('solve,'psopfn,'solveeval);

symbolic procedure solveeval u;
   begin scalar !*ezgcd,!!gcd,vars!*;  integer nargs;
      if atom u then rerror(solve,1,"SOLVE called with no equations")
       else if null dmode!* then !*ezgcd := t;
      if not inside!-solveeval then solve!-gensymcounter := 1;
      nargs := length u;
      u := (if nargs=1 then solve0(car u,nil)
              else if nargs=2 then solve0(car u, cadr u)
              else <<lprim "Please put SOLVE unknowns in a list";
                     solve0(car u,'list . cdr u)>>)
             where inside!-solveeval = t;
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
   % vars in xlst, returning either a list of solutions, or a single
   % solution.
   begin scalar !*exp,!*notseparate,w;  integer neqn;
   !*exp := !*notseparate := t;
   % Form a list of equations as expressions.
   elst := for each j in solveargchk elst collect simp!* !*eqn2a j;
   neqn := length elst;   % There must be at least one.
   % Determine variables.
   if null xlst
     then <<vars!* := for each j in allkern elst join
                         if constant_exprp j then nil else list j;
                      % Exclude constant kernels from list.
            terpri();
            if null vars!* then nil
             else if cdr vars!*
              then <<prin2!* "Unknowns: "; maprin('list . vars!*)>>
             else <<prin2!* "Unknown: "; maprin car vars!*>>;
            terpri!* nil>>
    else <<xlst := solveargchk xlst;
           vars!* := for each j in xlst collect !*a2k j>>;
   if length vars!* = 0
     then rerror(solve,3,"SOLVE called with no variables")
    else if neqn = 1
           then if null numr car elst
                  then return if !*solvesingular
                            then list list(for each j in vars!*
                                   collect !*f2q makearbcomplex(),
                                   vars!*,1)
                           else nil
          else if length vars!*=1
           then if solutionp(w := solvesq(car elst,car vars!*,1))
                   or null !*solvealgp
                   or univariatep numr car elst
                  then return w;
   % More than one equation or variable, or single eqn has no solution.
    elst := for each j in elst collect numr j;
    w := solvesys(elst,vars!*);
    if car w eq 't or car w eq 'inconsistent then return cdr w
     else if car w eq 'failed or null car w
      then return for each j in elst collect list(list(j ./ 1),nil,1)
     else errach list("Improper solve solution tag",car w)
   end;

symbolic procedure solutionp u;
   null u or cadar u and not root_of_soln_p caar u and solutionp cdr u;

symbolic procedure root_of_soln_p u;
   null cdr u and kernp (u := car u) and eqcar(mvar numr u,'root_of);

symbolic procedure solveargchk u;
   if getrtype (u := reval u) eq 'list then cdr reval u
    else if atom u or not(car u eq 'lst) then list u
    else cdr u;


% ***** Procedures for solving a single eqn *****

symbolic procedure solvesq (ex,var,mul);
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
          % Inhibit use of principle-of-powers-soln, since solvealg
          % code is more powerful.
%             else if (y := principle!-of!-powers!-soln(e1,x1,var,mu))
%                         neq 'unsolved
%              then y
              else if not smemq('sol,
                        (x1:=simp!* list('sol,mk!*sq(e1 ./ 1), var)))
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
   begin scalar !*numval,b,coefs,hipow;  integer n;
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
      hipow := caar reverse coefs;
      if hipow = 1
        then return begin scalar lincoeff,y,z;
           if null cdr coefs then b := 0
            else b := prepsq quotsq(negsq cdar coefs,cdadr coefs);
           if n neq 1 then b := list('expt,b,list('quotient,1,n));
           % We may need to merge more solutions in the following if
           % there are repeated roots.
           for k := 0:n-1 do   % equation in power of var.
            <<lincoeff := simp!* list('times,b,
                          mkexp list('quotient,list('times,k,2,'pi),n));
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
      if null numr lincoeff then return nil;
      u := car u;
      return if freeof(car u,var)    % c**(...) = b.
    then <<if !*allbranch
                 then <<!!arbint:=!!arbint+1;
            c:=list('times,2,'i,'pi,
                list('arbint,!!arbint))>>
                else c:=0;
                solvesq(subtrsq(simp!* cadr u,
                     quotsq(addsq(solveexpt!-logterm lincoeff,
                                  simp!* c),
                        simp!* list('log,car u))),var,mu)>>
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
    else mkrootsof(subtrsq(simp!*('expt . u),lincoeff),var,mu)
   end;

put('expt,'solvefn,'solveexpt);

symbolic procedure solveexpt!-logterm lincoeff;
  % compute log(lincoeff), ignoring multiplicity and converting
  % log(-a) to log(a) + i pi.
   if not !*allbranch or not minusf numr lincoeff
      then simp!* list('log,mk!*sq lincoeff)
   else
    addsq(simp!*'(times i pi),
          simp!* {'log,mk!*sq(negf numr lincoeff ./ denr lincoeff)});

symbolic procedure solvelog u;
   solvesq(subtrsq(simp!* caar u,simp!* list('expt,'e,mk!*sq cadddr u)),
          cadr u,caddr u);

put('log,'solvefn,'solvelog);

symbolic procedure solveinvpat(u,op);
   begin scalar c,d,z,f;
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
      y := reval list('root_val,mkquote mk!*sq(ex ./ 1));
      if not(car y eq 'list)
       then errach list("incorrect root format",ex);
      return for each z in cdr y collect
       %  if not(car z eq 'equal) or cadr z neq var
       %    then errach list("incorrect root format",ex)
       %   else list(list simp caddr z,list var,mu)
         list(list simp z,list var,mu)
   end;


% ***** Procedures for solving a system of eqns *****

symbolic procedure solvesys(exlist,varlis);
   % Exlist is a list of standard forms, varlis a list of kernels.  If
   % the elements of varlis are linear in the elements of exlist, and
   % further the system of linear eqns so defined is non-singular, then
   % SOLVESYS returns a list of a list of standard quotients which are
   % solutions of the system, ordered as in varlis.
   begin scalar eqtype,oldkord;
      oldkord := setkorder varlis;
      exlist := for each j in exlist collect reorder j;
      % See if equations are linear or non-linear.
      if errorp errorset!*(list('solvenonlnrchk,mkquote exlist,
                                mkquote varlis),nil)
        then eqtype := 'solvenonlnrsys
       else eqtype := 'solvelnrsys;
     % Solve for appropriate equation type.
      if eqtype eq 'solvenonlnrsys and null !*nonlnr
        then <<setkorder oldkord;
               rerror(solve,4,
                  "Non linear equation solving not yet implemented")>>;
      exlist:=errorset!*(list(eqtype,mkquote exlist,mkquote varlis),t);
      setkorder oldkord;
      if errorp exlist then error1()
       else return if eqtype eq 'solvelnrsys then t . car exlist
       else car exlist
   end;

symbolic procedure solvenonlnrchk(exlist,varlis);
   % Returns error if equations are nonlinear.  (Error used to prevent
   % unnecessary computation.)
   for each ex in exlist do
      for each var in varlis do solvenonlnrchk1(ex,var,varlis);

symbolic procedure solvenonlnrchk1(ex,var,varlis);
   if domainp ex then nil
      else <<if mvar ex=var
               then (if ldeg ex>1 or not freeofl(lc ex,varlis)
                       then error1())
              else if not freeofl(mvar ex,varlis)
                 and not(mvar ex member varlis)
               then error1()
              else solvenonlnrchk1(lc ex,var,varlis);
             solvenonlnrchk1(red ex,var,varlis)>>;


% ***** Support for one_of and root_of *****.

symbolic procedure mkrootsof(e1,var,mu);
   begin scalar x;
      x := if idp var then var else 'q_;
      if not !*!*norootvarrenamep!*!*
        then while smember(x,e1) do
             x := intern compress append(explode x,explode '!_);
      e1 := prepsq!* e1;
      if x neq var then e1 := subst(x,var,e1);
      return list list(list !*k2q list('root_of,e1,x),list var,mu)
   end;

put('root_of,'psopfn,'root_of_eval);

symbolic procedure root_of_eval u;
   begin scalar !*!*norootvarrenamep!*!*,x;
      !*!*norootvarrenamep!*!* := t;
      x := solveeval u;
      if eqcar(x,'list) then x := cdr x else typerr(x,"list");
      x := foreach j in x collect if eqcar(j,'equal) then caddr j
                                   else typerr(j,"equation");
      if null x then rederr "solve confusion in root_of_eval"
       else if null cdr x then return car x else return('one_of . x)
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

symbolic procedure one_of_p u;
   % The use of reval is rather heavy handed, but it works.
   (if eqcar(x,'one_of) then x else nil) where x=reval u;

symbolic procedure expand_cases u; makelist expandcase0 cdr u;

symbolic procedure expandcase0 u;
   if null u then nil
    else if eqcar(car u,'list) then expandcase2 u
    else expandcase1 u;

symbolic procedure expandcase1 u;
   % One variable case.
   if null u then nil
    else if not eqcar(car u,'equal) then typerr(car u,"equation")
    else (if x
            then append(for each j in cdr x collect
                           list('equal,cadar u,j),
                        y)
           else car u . y)
          where x=one_of_p caddar u,y=expandcase1 cdr u;

symbolic procedure expandcase2 u;
   % Multiple variable case.
   if null u then nil
    else if not eqcar(car u,'list) then typerr(car u,"list")
    else append(for each j in expandcase22 cdar u collect makelist j,
                expandcase2 cdr u);

symbolic procedure expandcase22 u;
   if null u then list nil else
   if not eqcar(car u,'equal) then typerr(car u,"equation")
    else (if x then for each j in cdr x join
                      for each k in y collect
                                list('equal,cadar u,j)
                                  . subst(j,cadar u,k)
           else for each k in y collect car u . k)
          where x=one_of_p caddar u,y=expandcase22 cdr u;


% Rules for solving inverse trigonometrical functions.

fluid '(solve_invtrig_soln!*);

share solve_invtrig_soln!*;

symbolic procedure check_solve_inv_trig(fn,eq,var);
   begin scalar x,s;
     x := evalletsub2({'(solve_trig_rules),{'simp!*,mkquote {fn,eq}}},
                      nil);
     if errorp x or not ((x := car x) freeof '(asin acos atan))
       then return nil;
     for each sol in cdr solveeval {mk!*sq subtrsq(x,simp!* {fn,0}),
                                    var} do
       if is_solution(sol,eq) then s := caddr sol . s;
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
      return 'unsolved;
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

% Based on code by David R. Stoutemyer modified by Donald R. Morrison.

% Copyright (c) 1993 RAND.  All rights reserved.

% The number of equations and the number of unknowns are arbitrary.
% I.e. the system can be under- or overdetermined.

fluid '(!*cramer !*exp !*solvesingular asymplis!* wtl!*);

symbolic procedure solvelnrsys(exlist,varlis);
   % This is hook to general solve package. exlist is a list of
   % standard forms linear in the kernels of list varlis. Result is a
   % tagged standard form for the solutions.
   % If the system is inconsistent, then the second element of
   % the list returned is NIL, so that !*solvelist2solveeqlist
   % gives expr = 0, rather than var = expr.
   if null !*cramer then solvelnrsys1(exlist,varlis)
    else list list(car w,cadr w and varlis,1)
        where w = glnrsolve(exlist,varlis);

symbolic procedure solvelnrsys1(exlist,varlis);
   begin integer n; scalar mtrx,rhs,ne,nv;
      % Set up coefficient matrix.
      n := length varlis;
      if (ne := length exlist)<(nv := length varlis)
        then for i := 1:(nv-ne) do exlist := nil . exlist
       else if ne > nv
        then for i := 1:(ne-nv) do varlis := nil . varlis;
      for each ex in exlist do
         begin scalar row;
            for each var in varlis do
               if not domainp ex and mvar ex=var
                 then <<row := !*f2q lc ex . row; ex := red ex>>
                else row := !*f2q nil . row;
            rhs := list !*f2q negf ex . rhs;
            mtrx := reversip!* row . mtrx
         end;
      mtrx := tp1 solvelnrsolve(mtrx,rhs,n);
      if cdr mtrx
        then rerror(solve,7,"Invalid linear equation solution");
      mtrx := car mtrx;
      if ne > nv then for i := 1:(ne-nv) do
         <<mtrx := cdr mtrx; varlis := cdr varlis>>;
      return list list(mtrx,varlis,1)
   end;

symbolic procedure solvelnrsolve(u,v,varno);
   % U is a matrix canonical form, v a compatible matrix form and varno
   % the number of SOLVE variables.
   % Result is the solution to the matrix equation u*y=v.  If
   % !*solvesingular is non-nil, introduces arbitrary constants if
   % necessary.  Returns an error if the system represented is
   % inconsistent or if !*solvesingular is nil and u is singular.
   begin integer n; scalar !*exp,perm,temp;
      !*exp := t; n := length u;
      if asymplis!* or wtl!*
        then <<temp := asymplis!* . wtl!*; asymplis!* := wtl!* := nil>>;
      perm := indexlis(1,n);
      u := car normmat augment(u,v);
      u := bareiss1(u,perm);
      if null !*solvesingular and car u<varno
        then rerror(solve,8,"SOLVE given singular equations");
      if u then u := insertarbconsts(cdr(u),car(u)+1,
                                     function makearbcomplex);
      if null u
        then if !*solvesingular
               then rerror(solve,9,"SOLVE given inconsistent equations")
              else rerror(solve,10,
                 "SOLVE given inconsistent or singular equations");
      v := backsub(u,n);
      u := rhside(car v,n);
      v := cdr v;
      if temp
        then <<asymplis!* := car temp;
               wtl!* := cdr temp;
               u := for each j in u collect
                        for each k in j collect resimp subs2!*(k ./ v)>>
       else u := for each j in u collect
                    for each k in j collect subs2!* cancel(k ./ v);
      return restoreperm(u,perm);
   end;

symbolic procedure indexlis(m,n);
   % M,n are integers.  Returns the list (m m+1 m+2 ... n-1 n).
   if m<=n then m . indexlis(m+1,n) else nil;

symbolic procedure insertarbconsts(m,zerorow,arbfn);
   % M is a matrix standard form, representing a matrix which has been
   % row reduced.  All elements below the principal diagonal are
   % implicitly nil, as are all elements in row ZEROROW and below.  It
   % is such a form as is returned by SOLVEBAREISS with a non-nil
   % second argument.  It inserts appropriate arbitrary constants in the
   % inhomogeneous portion, and 1's on the main diagonal except for the
   % last row, which gets the new determinant of the square submatrix.
   % Calls ARBFN to generate arbitrary constants.
   begin scalar u, v, newdet; integer n;
      n := length(m);
      if zerorow<=n then <<
         newdet := 1;
         u := m;
         for i := 1:(zerorow-1) do <<
            newdet := multf(newdet, nth(car(u), i));
            u := cdr(u) >>;
         for i := zerorow:(n-1) do <<
            v := pnth(car(u), i);
            rplaca(v, 1);
            v := cdr(v);
            for j := i+1:n do <<rplaca(v,nil); v := cdr(v)>>;
            while v do <<rplaca(v,!*k2f lispeval list arbfn);
                         v := cdr(v)>>;
            u := cdr(u) >>;
         v := pnth(car(u), n);
         rplaca(v, newdet);
         v := cdr(v);
         while v do <<
            rplaca(v, multf(newdet, !*k2f lispeval list arbfn));
            v := cdr(v) >> >>;
      return m
   end;

symbolic procedure restoreperm(u,v);
   % U is a list. V is a list of the numbers 1,2,...,length u, permuted.
   % Returns a list of the elements of U in the order 1,2,...
   begin integer n; scalar x;
      x := mkvect(n := length u);
      while v do <<putv(x,car v,car u); u := cdr u; v := cdr v>>;
      return for i := 1:n collect getv(x,i)
   end;

endmodule;


module glsolve; % Routines for solving a general system of linear
                % equations using Cramer's rule, realized through
                % exterior multiplication.

% Author: Eberhard Schruefer.
% Modifications by:  D. Hartley and R.W. Tucker.

% The number of equations and the number of unknowns are arbitrary.
% I.e. the system can be under- or overdetermined.

fluid '(!*solvesingular !*solveinconsistent vars!*);

global '(!!arbint);

global '(inconsistent!*); % Flag to show if equations were inconsistent.

flag('(inconsistent!*),'share);

switch solveinconsistent;

% !*solveinconsistent := t; % Default value.

%symbolic procedure solvelnrsys(u,v);
   % This is hook to general solve package. u is a list of polynomials
   % (s.f.'s) linear in the kernels of list v. Result is a tagged
   % standard form for the solutions.
   % If the system is inconsistent, then the second element of
   % the list returned is NIL, so that !*solvelist2solveeqlist
   % gives expr = 0, rather than var = expr.
%   list list(car w,cadr w and v,1) where w = glnrsolve(u,v);

symbolic procedure glnrsolve(u,v);
% glnrsolve(u: list of sf's, v: list of kernels)
% -> (xprs: list of sq's, flg: boolean)
% Adapted by D. Hartley and R.W. Tucker from E. Schruefer's glnrsolve.
% The equations u must be ordered with respect to the kernels v
% If flg is t then xprs is an ordered list of solutions for v.
% If flg is nil then xprs is a list of consistency conditions.
   begin scalar arbvars,sgn,x,y,cnds;
     inconsistent!* := nil;
     while u and null x do
       <<x := !*sf2ex(car u,v);
         if null x then u := cdr u
         else if inconsistency!-chk x then
           <<cnds := car u . cnds; x := nil; u := cdr u>>; >>;
     if null u then       % no consistent non-zero equations
       if cnds then
        <<inconsistent!* := t;   % inconsistent equations
          if null !*solveinconsistent then
             rerror(solve,5,"SOLVE given inconsistent equations") else
          % bump up length of vars!* to fool !*solvelist2solveeqlist
           <<if length cnds > 1 then vars!* := t . vars!*;
             return list(for each j in cnds collect !*f2q j,nil)>>>>
       else               % all equations were zero
         return list(for each j in v collect !*f2q makearbcomplex(),t);
     u := cdr u;
     for each j in u do
       if y := extmult(!*sf2ex(j,v),x) then
          if inconsistency!-chk y then
            cnds := numr cancel(lc y ./ lc x) . cnds
          else
            x := y;
     if cnds then
      <<inconsistent!* := t;
        if null !*solveinconsistent then
          rerror(solve,5,"SOLVE given inconsistent equations")
        else % bump up length of vars!* to fool !*solvelist2solveeqlist
          <<if length cnds > 1 then vars!* := t . vars!*;
            return list(for each j in cnds collect !*f2q j,nil)>>>>;
     arbvars := for each j in setdiff(v,lpow x) collect
                    j . makearbcomplex();
     if arbvars and null !*solvesingular
       then rerror(solve,6,"SOLVE given singular equations");
     if null red x then return
        list(for each j in v collect
               if y := atsoc(j,arbvars) then !*f2q cdr y else nil ./ 1,
             t);
     sgn := evenp length lpow x;
     return list(for each j in v collect
                   if y := atsoc(j,arbvars) then !*f2q cdr y
                   else solve!-mkglsol(j,x,sgn := not sgn,arbvars),
                 t);
   end;

symbolic procedure inconsistency!-chk u;
   null u or ((nil memq lpow u) and inconsistency!-chk red u);

symbolic procedure solve!-mkglsol(u,v,sgn,arbvars);
   % u is the kernel to be solved for, x the exterior product of all
   % independent equations, sgn is the current sgn indicator, arbvars
   % is an a-list (var . arbvar).
   begin scalar s,x,y;
     x := nil ./ 1;
     y := lpow v;
     for each j on red v do
       if s := solve!-glsolterm(u,y,j,arbvars)
          then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;

symbolic procedure solve!-glsolterm(u,v,w,arbvars);
   begin scalar x,y,sgn;
     x := lpow w;
     a: if null x then return
           if null car y then lc w
            else multf(cdr atsoc(car y,arbvars),
                       if sgn then negf lc w else lc w);
        if car x eq u then return nil
         else if car x memq v then <<x := cdr x;
                                     if y then sgn := not sgn>>
         else if y then return nil
               else <<y := list car x; x := cdr x>>;
        go to a
   end;

%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of variables in exterior product
%                   lc   ::= standard form

symbolic procedure !*sf2ex(u,v);
   %Converts standardform u into a form distributed w.r.t. v
%*** Should we check here if lc is free of v?
   if null u then nil
    else if domainp u or null(mvar u memq v) then list nil .* u .+ nil
    else list mvar u .* lc u .+ !*sf2ex(red u,v);

symbolic procedure extmult(u,v);
   % Special exterior multiplication routine.  Degree of form v is
   % arbitrary, u is a one-form.
   if null u or null v then nil
    else (if x then cdr x .* (if car x then negf subs2multf(lc u,lc v)
                               else subs2multf(lc u,lc v))
                          .+ extadd(extmult(!*t2f lt u,red v),
                                    extmult(red u,v))
           else extadd(extmult(red u,v),extmult(!*t2f lt u,red v)))
          where x = ordexn(car lpow u,lpow v);

symbolic procedure subs2multf(u,v);
   % This definition allows for a power substitution that can lead to
   % a denominator in subs2.  There is a possibility that the power
   % substitution won't be made, but there is no example of this yet.
   (if denr y neq 1 then x else numr y)
   where y=subs2(x ./ 1) where x = multf(u,v);

symbolic procedure extadd(u,v);
   if null u then v
    else if null v then u
    else if lpow u = lpow v then
            (lambda x,y; if null x then y else lpow u .* x .+ y)
                (addf(lc u,lc v),extadd(red u,red v))
    else if ordexp(lpow u,lpow v) then lt u .+ extadd(red u,v)
    else lt v .+ extadd(u,red v);

symbolic procedure ordexp(u,v);
   if null u then t
    else if car u eq car v then ordexp(cdr u,cdr v)
    else if null car u then nil
    else if null car v then t
    else ordop(car u,car v);

symbolic procedure ordexn(u,v);
   %u is a single variable, v a list. Returns nil if u is a member
   %of v or a dotted pair of a permutation indicator and the ordered
   %list of u merged into v.
   begin scalar s,x;
     a: if null v then return(s . reverse(u . x))
         else if u eq car v then return nil
         else if u and ordop(u,car v) then
                 return(s . append(reverse(u . x),v))
         else  <<x := car v . x;
                 v := cdr v;
                 s := not s>>;
         go to a
   end;

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

fluid '(!*exptexpand);   % from simp.red

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
         !*expli         % local switch: explicit solution
         groebroots!*    % predefined roots from input surds
         !*test_solvealg % debugging support
       );

fluid '(!*trnonlnr);
  % If set on, the modified system and the Groebner result
  % or the reason for the failure are printed.

global '(loaded!-packages!*);

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
    my!-expt(~a,~b)*a => my!-expt(a,b+1),
    my!-expt(~a,~b)*a => my!-expt(a,b+1)
 %  my!-expt(~a,~b)/my!-expt(a,~c) => my!-expt(a,b-c)
  };

>>;

symbolic procedure solvenonlnrsys(sys,uv);
  % interface to algebraic system solver.
  % factorize the system and collect solutions.
  % After factoring we resimplify with *exptexpand off
  % in order to have exponentials to one basis
  % collected.
  begin scalar q,r,s,tag,!*exptexpand;
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
   return tag.r
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
   if not mvar e1 =x or ldeg e1>1 or
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
 % equation system has been reduced to one. Solve
 % it using solvesq.
  begin scalar q,w;
   w:=solvesq(f ./ 1,x,1);
   if null w then return '(inconsistent);
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
      {s . car q,x . cadr q,caddr q};

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
  begin scalar y,r,s,r0,u,w;
   if null vars then return '(failed) else
   if null cdr eqs then
   <<if not smember(car vars,car eqs) then
        return solvenonlnrsyssep(eqs,cdr vars);
     r:=solvesq(!*f2q car eqs,car vars,1);
     return if r then 't.r else '(failed);
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
   u:=for each s0 in s join
   <<
     w:=for each q in pair(cadr s0,car s0) join
      if not smemq('root_of,cdr q) then
          {car q.prepsq cdr q};
     r0:=subf(r,w);
     r0:=solvesq(r0,y,caddr s0);
     for each r1 in r0 collect
      {caar r1. car s0,y.cadr s0,caddr r1}
   >>;
   return t.u;
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
  (begin scalar iv!*,kl!*,inv!*,fv!*,r,!*solvealgp,solvealgdb!*;
         scalar last!-vars!*,groebroots!*,const!-vars!*,sub!*;
         % hiding dmode because exponentials need integers.
      for each f in system!* do solvealgk0
         (if dmode!* then numr subf(f,nil) where dmode!*=nil else f);
      if !*trnonlnr then print list("original kernels:",kl!*);
      if null cdr system!* then
          if (smemq('sin,system!*)or smemq('cos,system!*)) and
             (r:=solvenonlnrtansub(prepf car system!*,car uv!*))
            then return solvenonlnrtansolve(r,car uv!*)
           else if (smemq('sinh,system!*)or smemq('cosh,system!*)) and
             (r:=solvenonlnrtanhsub(prepf car system!*,car uv!*))
            then return solvenonlnrtanhsolve(r,car uv!*);
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
  begin scalar bas,xp,xpl,nv,q,r,nk,sub;
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
      % prepare roots for simple surds.
    if null y or y={x} then groebroots!* :=
     ({'plus,{'expt,!&beta,n},reval{'minus,x}}
       .{{{'equal,!&beta,{'expt,x,{'quotient,1,n}}}}}).groebroots!*;
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
   operator p_sign;
   let p_sign(~x) = if sign(x)=0 then 1 else sign(x);
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
    s := if x then solvealginner(cadr k,x) else 1;
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
    s := if x then solvealginner(cadr k,x) else 1;
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
  begin scalar nv,m,s;
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
      if not !*expli then noarb := t;
      if !*expli and not noarb then
      << % assign value to free variables;
        for each x in uv!* do
         if solvealgdepends(rh,x) and not member(x,fv!*)
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
    begin scalar min,s,x,cmpl,!*msg;
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
  begin scalar sub,nexpli,x,y,sys,sum,fail;
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

symbolic procedure solvenonlnrtansolve(u,x);
  begin scalar p,v,s,z,r,si,y;
   v:=caar u; u:= prepf numr simp cdr u;
   s:=solveeval {u,'tg!-};
   si:=solveeval {{'equal,v,'!&!&},x};
   for each q in cdr s do
   <<z:=reval caddr q;
     z:=reval sublis(solvenonlnrtansolve1 z,z);
     for each sii in cdr si do
     <<y:=simp subeval1({'!&!& . {'times,2,{'atan,z}}},caddr sii);
       r:=union({{{y},{x},1}},r);
      >>;
   >>;
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

symbolic procedure solvenonlnrtanhsolve(u,x);
  begin scalar p,v,s,z,r,si,y;
   v:=caar u; u:= prepf numr simp cdr u;
   s:=solveeval {u,'tgh!-};
   si:=solveeval {{'equal,v,'!&!&},x};
   for each q in cdr s do
   <<z:=reval caddr q;
     z:=reval sublis(solvenonlnrtanhsolve1 z,z);
     for each sii in cdr si do
     <<y:=simp subeval1({'!&!& . {'times,2,{'atanh,z}}},caddr sii);
       r:=union({{{y},{x},1}},r);
      >>;
   >>;
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

% Modifications by: Anthony C. Hearn, Donald R. Morrison and Rainer
%                   Schoepf.

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
   sol(a*log b + c*log d, x) = b**a*d**c - 1,
   sol(a*log b - c*log d, x) = b**a - d**c;

for all a,b,c,d,f,x such that a freeof x and c freeof x let
   sol(a*log b + c*log d + f, x) = sol(log(b**a*d**c) + f, x),
   sol(a*log b + c*log d - f, x) = sol(log(b**a*d**c) - f, x),
   sol(a*log b - c*log d + f, x) = sol(log(b**a/d**c) + f, x),
   sol(a*log b - c*log d - f, x) = sol(log(b**a/d**c) - f, x);

for all a,b,d,f,x such that a freeof x let
   sol(a*log b + log d + f, x) = sol(log(b**a*d) + f, x),
   sol(a*log b + log d - f, x) = sol(log(b**a*d) - f, x),
   sol(a*log b - log d + f, x) = sol(log(b**a/d) + f, x),
   sol(a*log b - log d - f, x) = sol(log(b**a/d) - f, x),
   sol(log d - a*log b + f, x) = sol(log(d/b**a) + f, x),
   sol(log d - a*log b - f, x) = sol(log(d/b**a) - f, x);

for all a,b,c,d,x such that a freeof x and c freeof x let
   sol(a*log b + c*log d, x) = b**a*d**c - 1,
   sol(a*log b - c*log d, x) = b**a - d**c;

for all a,b,d,x such that a freeof x let
   sol(a*log b + log d, x) = b**a*d - 1,
   sol(a*log b - log d, x) = b**a - d,
   sol(log d - a*log b, x) = d - b**a;

for all a,b,c,x let
   sol(log a + log b + c, x) = sol(log(a*b) + c, x),
   sol(log a - log b + c, x) = sol(log(a/b) + c, x),
   sol(log a + log b - c, x) = sol(log(a*b) - c, x),
   sol(log a - log b - c, x) = sol(log(a/b) - c, x);

for all a,c,x such that c freeof x let
   sol(log a + c, x) = a - e**(-c),
   sol(log a - c, x) = a - e**c;

for all a,b,x let
   sol(log a + log b, x) = a*b - 1,
   sol(log a - log b, x) = a - b,
   sol(cos a - sin b, x) = sol(cos a - cos(pi/2-b), x),
   sol(sin a + cos b, x) = sol(sin a - sin(b-pi/2), x),
   sol(sin a - cos b, x) = sol(sin a - sin(pi/2-b), x),
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
      then for each z in cdr root_val mkpolyexp2(a2,a1,a0)
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
