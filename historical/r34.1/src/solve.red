module solve;   % Solve one or more algebraic equations.

% Author: David R. Stoutemyer.
% Major modifications by: Anthony C. Hearn and Donald R. Morrison.

create!-package('(solve ppsoln glsolve solvealg solvetab quartic),nil);

% Other packages needed by solve package.

load!-package 'matrix;

fluid '(!*allbranch !*exp !*ezgcd !*fullroots !*limitedfactors
        !*multiplicities !*nonlnr !*notseparate !*numval !*numval!*
        !*rounded !*solvealgp !*solvesingular !!gcd !:prec!: asymplis!*
        dmode!* vars!*);

global '(!!arbint multiplicities!*);

switch allbranch,fullroots,multiplicities,nonlnr,solvesingular;

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

algebraic operator arbint,arbreal,one_of;

symbolic operator expand_cases;

% algebraic operator arbcomplex;

% Done this way since it's also defined in the glmat module.

deflist('((arbcomplex simpiden)),'simpfn);

% ***** Utility Functions *****

symbolic procedure freeofl(u,v);
   null v or freeof(u,car v) and freeofl(u,cdr v);

symbolic procedure ratnump x;
   % Returns T iff any prefix expression x is a rational number.
   atom numr(x := simp!* x) and atom denr x;

flag ('(ratnump), 'boolean);

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

symbolic procedure solveeval u;
    begin scalar !!gcd,vars!*;  integer nargs;
      if atom u then rerror(solve,1,"SOLVE called with no equations");
      nargs := length u;
      u := if nargs=1 then solve0(car u,nil)
            else if nargs=2 then solve0(car u, cadr u)
            else solve0(car u,'list . cdr u);
      return !*solvelist2solveeqlist u
    end;

put('solve,'psopfn,'solveeval);

symbolic procedure !*solvelist2solveeqlist u;
   begin scalar x,y,z;
      for each j in u do
         <<if caddr j=0 then rerror(solve,2,"zero multiplicity")
            else if null cadr j
             then  x := for each k in car j collect
                                               list('equal,!*q2a k,0)
            else x := for each k in pair(cadr j,car j)
                          collect list('equal,car k,!*q2a cdr k);
%          if length x > 1 then x := 'list . x else x := car x;
           if length vars!* > 1 then x := 'list . x else x := car x;
           if !*multiplicities then x := nlist(x,caddr j)
            else <<x := list x; y := caddr j . y>>;
           z := nconc!*(x,z)>>;
      if !*multiplicities then multiplicities!* := nil
       else multiplicities!* := 'list . y;
      % Now check for redundant solutions.
%     if length vars!*>1 then z := check_solve_redundancy z;
      return 'list . z
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
     then <<vars!* := allkern elst;
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
   null u or cadar u;

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
     begin scalar !*ezgcd,e1,x1,y,z;  integer mu;
      ex := numr ex;
      if null topkern(ex,var) then return nil;
      if null !*limitedfactors and null dmode!* then !*ezgcd := t;
      ex := fctrf ex;
      % Now process monomial.
      if domainp car ex then ex := cdr ex
       else ex := (car ex . 1) . cdr ex;
      for each j in ex do
        <<e1 := car j;
          x1 := topkern(e1,var);
          mu := mul*cdr j;
          % Test for decomposition of e1.
          if length x1=1
             and length(y := decomposef1(e1,nil))>1
             and (y := solvedecomp(reverse y,car x1,mu))
            then z := append(y,z)
           else if x1
            then z := append(
             if null cdr x1 then solve1(e1,car x1,var,mu)
              else if (y := principal!-of!-powers!-soln(e1,x1,var,mu))
                          neq 'unsolved
               then y
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
      if atom coefs then return mkrootsof(e1 ./ 1,var,mu);
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
                     quotsq(addsq(simp!* list('log,mk!*sq lincoeff),
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

symbolic procedure solvelog u;
   solvesq(subtrsq(simp!* caar u,simp!* list('expt,'e,mk!*sq cadddr u)),
          cadr u,caddr u);

put('log,'solvefn,'solvelog);

symbolic procedure solvecos u;
   begin scalar c,d,z;
      if !*allbranch
        then <<!!arbint:=!!arbint+1;
               c:=list('times,2,'pi,list('arbint,!!arbint))>>
       else c:=0;
      c:=subtrsq(simp!* caar u,simp!* c);
      d:=simp!* list('acos,mk!*sq cadddr u);
      z := solvesq(subtrsq(c,d), cadr u,caddr u);
      if !*allbranch
        then z := append(solvesq(addsq(c,d), cadr u,caddr u),z);
      return z
   end;

put('cos,'solvefn,'solvecos);

symbolic procedure solvesin u;
   begin scalar c,d,f,z;
      if !*allbranch
        then <<!!arbint:=!!arbint+1;
               f:=list('times,2,'pi,list('arbint,!!arbint))>>
       else f:=0;
      c:=simp!* caar u;
      d:=list('asin,mk!*sq cadddr u);
      z := solvesq(subtrsq(c,simp!* list('plus,d,f)),cadr u,caddr u);
      if !*allbranch
        then z := append(solvesq(subtrsq(c,simp!* list('plus,'pi,
                                    mk!*sq subtrsq(simp!* f,simp!* d))),
                    cadr u,caddr u),z);
      return z
   end;

put('sin,'solvefn,'solvesin);

symbolic procedure mkexp u;
   list('plus,list('cos,x),list('times,'i,list('sin,x)))
    where x = reval u;

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
    else if mvar ex=var
     then (if ldeg ex>1 or not freeofl(lc ex,varlis) then error1())
    else if not freeofl(mvar ex,varlis) and not(mvar ex member varlis)
     then error1()
    else <<solvenonlnrchk1(lc ex,var,varlis);
           solvenonlnrchk1(red ex,var,varlis)>>;


% ***** Support for one_of and root_of *****.

symbolic procedure mkrootsof(e1,var,mu);
   begin scalar x;
      x := var;
      while smember(x,e1) do
         x := intern compress append(explode x,explode '!_);
      e1 := subst(x,var,prepsq!* e1);
      return list list(list !*k2q list('root_of,e1,x),list var,mu)
   end;

put('root_of,'psopfn,'root_of_eval);

symbolic procedure root_of_eval u;
   begin scalar x;
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

endmodule;


module ppsoln;  % Solve surd eqns, mainly by principal of powers method.

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

symbolic procedure principal!-of!-powers!-soln(ex,x1,var,mu);
   % Finds solutions of ex=0 by the principal of powers method.  Return
   % 'unsolved if solutions can't be found.
   begin scalar z;
      if null !*ppsoln then return 'unsolved;
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
      fv := delete('i,freevarl(ex,var));
     % this does only one random setting!!
      if fv then for each v in fv do
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
   else for each c in cdr a join varsift(c,var);

symbolic procedure numvalue u;
   % Find floating point value of sf u.
   begin scalar !*numval,x,c,cp,p,m;
      m := !*msg; !*msg := nil;
      !*numval := t;
      c := ('i memq freevarl(u,nil));
      if (cp := !*complex) then off complex;
      x := setdmode('rounded,t); p := precision 10;
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


module glsolve; % Routines for solving a general system of linear eqns.

% Author: Eberhard Schruefer.

%**********************************************************************
%*** The number of equations and the number of unknowns are         ***
%*** arbitrary i.e. the system can be under- or overdetermined.     ***
%*** Method used is Cramer's rule, realized through exterior        ***
%*** multiplication.                                                ***
%**********************************************************************

fluid '(!*solvesingular kord!*);

global '(!!arbint);

% algebraic operator arbcomplex; % Already defined in main solve module.

symbolic procedure solvelnrsys(u,v);
   % This is hook to general solve package. u is a list of polynomials
   % (s.f.'s) linear in the kernels of list v. Result is a tagged
   % standard form for the solutions.
   list list(glnrsolve(u,v),v,1);

symbolic procedure glnrsolve(u,v);
   % U is a list of polynomials (s.f.'s) linear in the kernels of list
   % v.  Result is an untagged list of solutions.
   begin scalar arbvars,sgn,x,y;
     while u and null(x := !*sf2ex(car u,v)) do u :=cdr u;
     for each j in u do if y := extmult(!*sf2ex(j,v),x) then x := y;
     if null x        % all equations were zero.
      then return for each j in v collect !*f2q makearbcomplex();
     if inconsistency!-chk x
       then rerror(solve,5,"SOLVE given inconsistent equations");
     arbvars := for each j in setdiff(v,lpow x) collect
                    j . makearbcomplex();
     if arbvars and null !*solvesingular
       then rerror(solve,6,"SOLVE given singular equations");
     if null red x then return
        for each j in v collect
            if y := atsoc(j,arbvars) then !*f2q cdr y else nil ./ 1;
     sgn := evenp length lpow x;
     return for each j in v collect if y := atsoc(j,arbvars)
                                       then !*f2q cdr y
                      else mkglsol(j,x,sgn := not sgn,arbvars)
   end;

symbolic procedure inconsistency!-chk u;
   null u or ((nil memq lpow u) and inconsistency!-chk red u);

symbolic procedure mkglsol(u,v,sgn,arbvars);
   % u is the kernel to be solved for, x the exterior product of all
   % independent equations, sgn is the current sgn indicator, arbvars
   % is an a-list (var . arbvar).
   begin scalar s,x,y;
     x := nil ./ 1;
     y := lpow v;
     for each j on red v do
       if s := glsolterm(u,y,j,arbvars)
          then x := addsq(cancel(s ./ lc v),x);
     return if sgn then negsq x else x
   end;

symbolic procedure glsolterm(u,v,w,arbvars);
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

% Copyright (c) 1990 The RAND Corporation and Konrad-Zuse-Zentrum. 
% All rights reserved.

fluid '( system!*        % system to be solved
         uv!*            % user supplied variables
         iv!*            % internal variables
         fv!*            % restricted variables
         kl!*            % kernels to be investigated
         sub!*           % global substitutions
         inv!*           % global inverse substitutions
         depl!*          % REDUCE dependency list
         !*solvealgp     % true if using this module
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

symbolic procedure solvenonlnrsys(system!*,uv!*);
  % Main driver. We need non-local exits here
  % because of possibly hidden non algebraic variable
  % dependencies.
  if null !*solvealgp then '(failed) else  % against recursion.
  (begin scalar iv!*,kl!*,inv!*,fv!*,r,!*solvealgp;
      for each f in system!* do solvealgk0 f;
      if !*trnonlnr then print list("original kernels:",kl!*);
      if atom errorset('(solvealgk1),!*trnonlnr,nil)
         then return '(failed);
      system!*:='list.for each p in system!* collect prepf p;
      if !*trnonlnr then
      <<  prin2t "Entering Groebner for system";
          writepri(mkquote system!*,'only);
          writepri(mkquote('list.iv!*), 'only);
      >>;
      if not('groebner memq loaded!-packages!*)
        then load!-package 'groebner;
      r := list(system!*,'list.iv!*);
      r := groesolveeval r;
      if !*trnonlnr then
      <<  prin2t "leaving Groebner with intermediate result";
          writepri(mkquote r,'only);
          terpri(); terpri();
      >>;
      return if r='(list) then '(inconsistent) else
                          solvealginv r;
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
      if null x then t else
      if memq(car k,'(sin cos tan cot)) then
            solvealgtrig(k,x) else
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
  if null x then solvealgid k else
  ( if eqcar(m,'quotient) and fixp caddr m then
         if cadr m=1 then solvealgrad(cadr k,caddr m,x)
            else solvealgradx(cadr k,cadr m,caddr m,x)
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
     if solvealgtest1(xp,uv!*) or solvealgtest1(bas,uv!*)
       then return solvealggen(k,x);
     % remaining case: "constant" exponential expression to
     % replaced by an id for syntatical reasons
   nv := '(
       % old kernel
      ( (expt alpha n))
       % new variable
      ( beta)
       % substitution
      ( ((expt alpha n) . beta) )
       % inverse
      ( (beta (expt alpha n) !& ))
       % new equations
      nil
          );
    nv:=subst(bas,'alpha,nv);
    nv:=subst(gensym(),'beta,nv);
    nv:=subst(xp,'n,nv);
    return solvealgupd(nv,nil);
   end;

symbolic procedure solvealgradx(x,m,n,y);
   error(99,"forms e**(x/2) not yet implemented");

symbolic procedure solvealgrad(x,n,y);
  % k is a radical exponentiation expression x**1/n.
  begin scalar nv,m;
    nv:= '(
       % old kernel
      ( (expt alpha (quotient 1 !&n)))
       % new variable
      ( beta)
       % substitution
      ( ((expt alpha (quotient 1 !&n)) . beta) )
       % inverse
      ( (beta alpha (expt !& !&n)) )
       % new equation
      ( (difference (expt beta !&n) alpha) )
          );
    m := list('alpha.x,'beta.gensym(),'!&n.n);
    nv := subla(m,nv);
    return solvealgupd(nv,y);
  end;

symbolic procedure solvealgtrig(k,x);
  % k is a trigonometric function call.
  begin scalar nv,m,s;
    if cdr x then
       error(99,"too many variables in trig. function");
    x := car x;
    solvealgvb k;
    nv := '(
       % old kernels
      ( (sin alpha)(cos alpha)(tan alpha)(cot alpha) )
       % new variables
      ( (sin beta) (cos beta) )
       % substitutions
      ( ((sin alpha) . (sin beta))
        ((cos alpha) . (cos beta))
        ((tan alpha) . (quotient (sin beta) (cos beta)))
        ((cot alpha) . (quotient (cos beta) (sin beta))) )
       % inverses
      ( ((sin beta) !&x (sol (list (equal (sin alpha) !&!&))
                             (list !&x)))
        ((cos beta) !&x (sol (list (equal (cos alpha) !&!&))
                             (list !&x))))
       % new equation
      ( (plus (expt (sin beta) 2)(expt (cos beta) 2) -1) )
          );
     % invert the inner expression.
    s :=  solvealginner(cadr k,x);
    m := list('alpha . cadr k,
              'beta . gensym(),
              '!&x    . x,
              '!&!& . s);
    nv:=sublis(m , nv);
    return solvealgupd(nv,nil);
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
      ( alpha )
       % new variables
      ( beta )
       % substitutions
      ( ( alpha . beta) )
       % inverses
      (( beta !&x !&!&))
       % new equation
      nil);
     % invert the kernel expression.
    s :=  solvealginner(k,x);
    m := list('alpha .  k,
              'beta . gensym(),
              '!&x    . x,
              '!&!& . s);
    nv:=sublis(m , nv);
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealgid k;
  % k is a "constant" kernel, however in a syntax unprocessable
  % for Groebner (e.g. expt(a/2)); replace temporarily
  begin scalar nv,m,s;
    nv := '(
       % old kernels
      ( alpha )
       % new variables
      ( )
       % substitutions
      ( ( alpha . beta) )
       % inverses
      (( beta nil . alpha))
       % new equation
      nil);
     % invert the kernel expression.
    m := list('alpha .  k, 'beta . gensym());
    nv:=sublis(m , nv);
    return solvealgupd(nv,nil);
  end;

symbolic procedure solvealginner(s,x);
   <<s := solveeval list(list ('equal,s,'!&), list('list,x));
    s := reval cadr s;
    if not eqcar(s,'equal) or not equal(cadr s,x) then
        error (99,"inner expression cannot be inverted");
    caddr s>>;

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
 begin scalar v,r,s,m,lh,rh,y,z,tag,sub,expli,noarb,arbs;
      integer n;
 sub := for each p in sub!*  collect (cdr p.car p);
 tag := t;
 return
  tag .
  (for each sol in cdr u collect
  <<v:= r:= s:= noarb :=arbs :=nil;
    for each eqn in reverse cdr sol do
    <<lh := cadr eqn; rh := subsq(simp!* caddr eqn,s);
      expli:=member(lh,iv!*);
      if not expli then noarb := t;
      if expli and not noarb then
      << % assign value to free variables;
        for each x in uv!* do
         if smember(x,rh) and not member(x,fv!*)
                        and not member(x,arbs)then
           <<z := mvar makearbcomplex();
             y := z; v := x . v; r := simp y . r;
          %  rh := subsq(rh,list(x.y));
          %  s := (x . y) . s;
             arbs:=x.arbs;
           >>;
       if not smemq('root_of,rh) then s:=(lh.prepsq rh).s
           else fv!*:=lh.fv!*;
      >>;
      if (m:=assoc(lh,inv!*))then
      <<lh :=cadr m;
        rh:=simp!* subst(prepsq rh,'!&,caddr m)>>;
          % append to the final output.
      if (member(lh,uv!*) or not expli)
               % inhibit repeated same values.
            and not<< z:=subsq(rh,sub);
                      n:=length member(z,r);
                      n>0 and lh=nth(v,length v + 1 - n)>>
         then <<r:=z.r; v:=lh.v;>>;
    >>;
      % Classify result.
    for each x in uv!* do
      if tag and not member(x,v) and smember(x,r) then tag:=nil;
    reverse r . reverse v . list 1
  >>);
 end;

endmodule;


module solvetab;   % Simplification rules for SOLVE.

% Author: David R. Stoutemyer.
% Modifications by: Anthony C. Hearn and Donald R. Morrison.

put('asin, 'inverse, 'sin);

put('acos, 'inverse, 'cos);

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
   sol(sin a + sin b, x) = sol(sin a - sin(-b), x),
   sol(sin a - sin b, x) = if !*allbranch then sin((a-b)/2)*
       cos((a+b)/2)  else a-b,
   sol(cos a + cos b, x) = cos((a+b)/2)*cos((a-b)/2),
   sol(cos a - cos b, x) = if !*allbranch then sin((a+b)/2)*
       sin((a-b)/2)  else a-b,
   sol(asin a - asin b, x) = a-b,
   sol(asin a + asin b, x) = a+b,
   sol(acos a - acos b, x) = a-b,
   sol(acos a + acos b, x) = a-b;

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

symbolic procedure subs2!* u; <<!*sub2 := t; subs2 u>>;

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
      if not !*trigform or not all_real(a0,a1,a2) then goto cbr;
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
      a := real_1 a and (numr simp list('sgn,mk!*sq a)=1);
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
      x := numr simp list('sgn,list('repart,mk!*sq x));
      if x=-1 then
         <<y := numr simp list('sgn,list('repart,mk!*sq y));
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
         numr simp list('sgn,list('difference,list('norm,mk!*sq zz1),
           list('norm,mk!*sq zz2)))=1 then neg := t;
 rst: off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      if neg then z := negsq z;
      return append(solvequadratic(!*f2q 1,subtrsq(a3,y),subtrsq(x,z)),
                    solvequadratic(!*f2q 1,addsq(a3,y),addsq(x,z)))
   end;

endmodule;


end;
