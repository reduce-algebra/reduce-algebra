module solve;   % Solve one or more algebraic equations.

% Author: David R. Stoutemyer.
% Modifications by: Anthony C. Hearn and Donald R. Morrison.

fluid '(!*exp asymplis!*);

global '(!!arbint
         !!gcd
         !*allbranch
         !*micro!-version
         !*nonlnr
         !*ppsoln
         !*solveinterval
         !*solvesingular
         multiplicities!*);

switch allbranch,solvesingular;   % solveinterval.

flag('(multiplicities!*),'share);

% ***** Global Declarations *****

array !!cf(12), !!interval(10,2), !!exact(10);

!*allbranch     := t;  % Returns all branches of solutions if T;
%!*solveinterval = nil;% Attempts to isolate insoluble, real roots if T;
!*solvesingular := t;  % Default value.
%  !!gcd     SOLVECOEFF returns GCD of powers of its arg in this
%  !!cf    : Array of coeffs from SOLVECOEFF

algebraic operator arbint, arbreal, intervl, list;

% algebraic operator arbcomplex;

% Done this way since it's also defined in the glmat module.

deflist('((arbcomplex simpiden)),'simpfn);

% ***** Utility Functions *****

symbolic procedure freeofl(u,v);
   null v or freeof(u,car v) and freeofl(u,cdr v);

symbolic procedure ratnump x;
   % Returns T iff any prefix expression x is a rational number.
   atom numr(x := simp!* x) and atom denr x;

flag ('(ratnump), 'direct);

symbolic procedure allkern elst;
   % Returns list of all top-level kernels in the list of standard
   % forms elst.
   if null elst then nil
    else union(kernels car numr elst, allkern cdr elst);

symbolic procedure topkern(u,x);
   % Returns list of top level kernels in the standard form u that
   % contain the kernel x;
   for each j in kernels u conc if not freeof(j,x) then list j else nil;

symbolic procedure coeflis ex;
   % Ex is a standard form.  Returns a list of the coefficients of the
   % main variable in ex in the form ((expon . coeff) (expon . coeff)
   % ... ), where the expon's occur in increasing order, and entries do
   % not occur of zero coefficients.
   begin scalar ans,var;
      if domainp(ex) then return (0 . ex);
      var := mvar(ex);
      while (not domainp(ex)) and mvar(ex)=var do 
        <<ans := (ldeg(ex) . lc(ex)) . ans; ex := red(ex) >>;
      if ex then ans := (0 . ex) . ans;
      return ans
   end;


% ***** Evaluation Interface *****

symbolic procedure solveeval u;
    begin scalar arglist;  integer nargs;
        arglist := u;
        nargs := length(arglist);       
        u := if nargs=1 then solve0(car arglist,nil)
              else if nargs=2
               then solve0(car arglist, cadr arglist)
             else solve0(car arglist,'list . cdr arglist);
      return !*solvelist2solveeqlist u
    end;

put('solve,'psopfn,'solveeval);

symbolic procedure !*solvelist2solveeqlist u;
   begin scalar x,y,z;
      for each j in u do
         <<if caddr j=0 then rederr "zero multiplicity"
            else if null cadr j
             then  x := for each k in car j collect
                                               list('equal,mk!*sq k,0)
            else x := for each k in pair(cadr j,car j)
                          collect list('equal,car k,mk!*sq cdr k);
           if length x > 1 then z := ('list . x) . z
            else z := car x . z;
           y := caddr j . y>>;
      multiplicities!* := 'list . y;
      return 'list . z
   end;

% ***** Fundamental SOLVE Procedures *****

comment these procedures return the solution of a list of equations as a
   list of elements with three fields: the solutions, the variables (or
   NIL if the equations could not be solved) and the multiplicity;

symbolic procedure solve0(elst, xlst);
   % elst is any prefix expression, including the kernel named LST with
   % any number of arguments.  XLST is a kernel, perhaps named LIST with
   % any number of arguments.  Solves eqns in ELST for vars in XLST,
   % returning either a list of solutions, or a single solution;
   begin scalar !*exp,vars;  integer neqn;
   !*exp := t;
   elst := for each j in solveargchk elst 
              collect simp!* if eqexpr j then !*eqn2a j else j;
   neqn := length elst;
   if neqn = 0 then rederr "SOLVE called with no equations";
   if null xlst 
     then <<vars := allkern elst;
            terpri();
            if null vars then nil
             else if cdr vars
              then <<prin2!* "Unknowns: "; maprin('list . vars)>>
             else <<prin2!* "Unknown: "; maprin car vars>>;
            terpri!* nil>>
    else <<xlst := solveargchk xlst;
           vars := for each j in xlst collect !*a2k j>>;
   if length vars = 0 then rederr "SOLVE called with no variables"
    else if neqn = 1
           then if null numr car elst
                  then return if !*solvesingular
                            then list list(list (makearbcomplex() ./ 1),
                                           vars,1)
                           else nil
          else if length vars=1
           then return solvesq(car elst,car vars,1);
   % more than one equation or variable.
    elst := solvesys(for each j in elst collect numr j,vars);
    return if null elst then nil
     else if null cdr elst then list list(car elst,vars,1)
     else if null !*nonlnr then rederr "Unbalanced SOLVE equations"
     else elst
   end;

symbolic procedure solveargchk u;
   if getrtype u eq 'list then cdr reval u
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
     begin scalar e1,x1,y,z;  integer mu;
      ex := numr ex;
      if null topkern(ex,var) then return nil;
      ex := fctrf ex;
      % now process monomial.
      if domainp car ex then ex := cdr ex 
       else ex := (car ex . 1) . cdr ex;
      for each j in ex do 
        <<e1 := car j;
          x1 := topkern(e1,var);
          mu := mul*cdr j;
          if x1
            then z := append(
             if null cdr x1 then solve1(e1,car x1,var,mu)
              else if (y := principal!-of!-powers!-soln(e1,x1,var,mu))
                          neq 'unsolved
               then y
              else if not smemq('sol,
                        (x1:=simp!* list('sol,mk!*sq(e1 ./ 1), var)))
               then solvesq(x1,var,mu)
              else list list(list(e1 ./ 1),nil,mu),
                 z)>>;
      return z
   end;

symbolic procedure principal!-of!-powers!-soln(ex,x1,var,mu);
   % Finds solutions of ex=0 by the principal of powers method, or
   % NIL if no such solutions exist.
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
      oldkord := setkorder list y;
      z := reorder ex;
      setkorder oldkord;
      if ldeg z neq 1 then return 'unsolved;
      z := coeflis z;
      if length z neq 2 or caar z neq 0
        then errach list("solve confused",ex,z);
      z := exptsq(quotsq(negsq(cdar z ./ 1),cdadr z ./ 1),
            caddr caddr y);
      z := solvesq(subs2 addsq(simp!* cadr y,negsq z),var,mu);
      z := check!-solutions(z,ex);
      return z
   end;

symbolic procedure check!-solutions(z,ex);
   begin scalar x,y;
      while z do
         if null cadar z then <<z := nil; x := 'unsolved>>
          else if null (y := numr subf(ex,list(caadar z .
                                               mk!*sq caaar z)))
             or null numvalue y
           then <<x := car z . x; z := cdr z>>
          else z := cdr z;
      return x
   end;

symbolic procedure numvalue u;
   % Find floating point value of sf u.
   begin scalar !*numval,x;
      !*numval := t;
      x := setdmode('float,t);
      u := numr simp prepf u;
      if x then setdmode(x,t) else setdmode('float,nil);
      return if eqcar(u,'!:ft!:) and 1000000*abs cdr u < 1 then nil
              else u
   end;

symbolic procedure suitable!-expt u;
   eqcar(u,'expt) and eqcar(caddr u,'quotient) and cadr caddr u = 1
      and fixp caddr caddr u;

symbolic procedure solve1(e1,x1,var,mu);
   comment e1 is a standard form, non-trivial in the kernel x1,
      which is itself a function of var, mu is an integer.
      Uses roots of unity, known solutions, 
      inverses, together with quadratic, cubic and quartic
      formulas, treating other cases as unsolvable.  Returns nil;
   begin scalar b,c,coeffs,hipow;  integer n;
      hipow := errorset(solvecoeff(e1, x1),nil,nil);
      if atom hipow then return list list(list(e1 . 1),nil,mu);
          % solvecoeff problem - no soln.
      hipow := car hipow;
      n:= !!gcd;   % numerical gcd of powers.
      for i := 0:hipow do
                 coeffs := nilchk getelv list('!!cf,i) . coeffs;
      if hipow = 1
        then return begin scalar lincoeff,y,z;
           b:=prepsq quotsq(negsq cadr coeffs,car coeffs);
           if n neq 1 then b := list('expt,b,list('quotient,1,n));
           % We may need to merge more solutions in the following if
           % there are repeated roots.
           for k := 0:n-1 do   % equation in power of var.
            <<lincoeff := simp!* list('times,b,
                          mkexp list('quotient,list('times,k,2,'pi),n));
              if x1=var
                then y := solnmerge(list lincoeff,list var,mu,y)
               else if not idp (z := car x1)
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
   then return <<x1 := exptsq(simp!* x1,n); % allows for power variable
                 for each j in apply('solvequadratic,coeffs)
                     conc solvesq(subtrsq(x1,j),var,mu)>>
  else return begin scalar d,f,rcoeffs;
      % At this point, we cannot write down the solution directly, so
      % we look for various forms that we know how to solve.
      f:=(hipow+1)/2;
      d:=exptsq(simp!* x1,n);
      rcoeffs := reverse coeffs;
      return if solve1test1(coeffs,rcoeffs,f)  % coefficients symmetric
        then if f+f=hipow+1   % odd 
               then <<c:=addsq(d, 1 ./ 1);
                      append(solvesq(c,var,mu),
                             solvesq(quotsq(e1 ./ 1, c),var,mu))>>
              else <<setelv(list('!!cf,0),2 ./ 1);
                     setelv(list('!!cf, 1), simp!* '!!x);
                     c:=addsq(multsq(getelv(list('!!cf,f+1)),
                                     getelv(list('!!cf,1))),
                              getelv(list('!!cf,f)));
                     for j:=2:f do <<
                         setelv(list('!!cf, j),
                            subtrsq(multsq(getelv(list('!!cf,1)),
                                           getelv(list('!!cf,j-1))),
                                    getelv(list('!!cf,j-2))));
                         c:=addsq(c,multsq(getelv(list('!!cf,j)),
                                           getelv(list('!!cf,f+j))))>>;
                     for each j in solvesq(c,'!!x,mu) conc
                      solvesq(addsq(1 ./ 1,multsq(d,subtrsq(d,caar j))),
                                var,caddr j)>>
       else if solve1test2(coeffs,rcoeffs,f)
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
       else if hipow=3 and null !*micro!-version
        then for each j in apply('solvecubic,coeffs)
                       conc solvesq(subtrsq(d,j),var,mu)
       else if hipow=4 and null !*micro!-version
        then for each j in apply('solvequartic,coeffs)
                       conc solvesq(subtrsq(d,j),var,mu)
       else if !*solveinterval and univariatep e1
        then solveinterval(e1,var,mu)
       else list list(list(e1 ./ 1),nil,mu)
          % We can't solve quintic and higher
      end
  end;

symbolic procedure solnmerge(u,varlist,mu,y);
   % Merge solutions in case of multiplicities. It may be that this is
   % only needed for the trivial solution x=0.
   if null y then list list(u,varlist,mu)
    else if u = caar y and varlist = cadar y
           then list(caar y,cadar y,mu+caddar y) . cdr y
    else car y . solnmerge(u,varlist,mu,cdr y);

symbolic procedure nilchk u; if null u then !*f2q u else u;

symbolic procedure solve1test1(coeffs,rcoeffs,f);
   % True if equation is symmetric in its coefficients. f is midpoint.
   begin integer j;
   a: if j>f then return t
       else if car coeffs neq car rcoeffs then return nil;
      coeffs := cdr coeffs;
      rcoeffs := cdr rcoeffs;
      j := j+1;
      go to a
   end;

symbolic procedure solve1test2(coeffs,rcoeffs,f);
   % True if equation is antisymmetric in its coefficients. f is
   %  midpoint.
   begin integer j;
   a: if j>f then return t
       else if numr addsq(car coeffs,car rcoeffs) then return nil;
      coeffs := cdr coeffs;
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
                          c := mkexp list('times,
                                          list('arbreal,!!arbint))>>
                  else c:=1;
                 solvesq(subtrsq(simp!* car u,
                                multsq(simp!* list('expt,
                                                   mk!*sq lincoeff,
                                                   mk!*sq invsq
                                                      simp!* cadr u),
                                       simp!* c)),var,mu)>>
        %  (...)**(...) = b : transcendental.
        else list list(list subtrsq(simp!*('expt . u),lincoeff),nil,mu)
   end;

symbolic procedure solve!-fractional!-power(u,x,var,mu);
   % attempts solution of equation car u**cadr u=x with respect to
   % kernel var and with multiplicity mu, where cadr u is a rational
   % number.
   begin scalar v,w,z;
      v := simp!* car u;
      w := simp!* cadr u;
      z := solvesq(subs2 subtrsq(exptsq(v,numr w),exptsq(x,denr w)),
                   var,mu);
      w := subtrsq(simp('expt . u),x);
      z := check!-solutions(z,numr w);
      return if z eq 'unsolved then list list(list w,nil,mu) else z
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
   % ex is a standard form and var a kernel. Puts the coefficients
   % (as standard quotients) of var in ex into the elements of !!cf,
   % with index equal to the exponent divided by the gcd of all the
   % exponents.  This GCD is put into !!GCD, and the highest power
   % divided by the gcd is put into hipow.  Returns hipow.  Note that
   % !!cf (an array), !!gcd a global.
begin scalar clist,hipow,oldkord;
   oldkord := setkorder list var;
   clist := reorder ex;
   setkorder oldkord;
   hipow := ldeg clist;
   clist := coeflis clist;
   !!gcd := caar clist;
   for each x in cdr clist do !!gcd := gcdn(car x, !!gcd);
   for i := 0:(car(dimension('!!cf))-1) do setelv(list('!!cf, i), nil);
   for each x in clist do setelv(list('!!cf, car x/!!gcd),cdr x ./ 1);
   hipow := hipow/!!gcd;
   return hipow
end;

symbolic procedure solveinterval(ex,var,mu);
   % ex is a standard form, var the relevant variable and mu the root
   % multiplicity. Isolates insoluble, real roots of EX in rational
   % intervals, returning solutions in terms of INTERVL(Lowlim,Highlim).
   begin scalar z;
      realroot(prepf ex,prepsq !*k2q mvar ex,'!!interval,'!!exact);
      for i := 1:getelv list('!!exact,0) do
         z := list(list simp!* getelv list('!!exact,i),list var,mu) . z;
      for i := 1:getelv list('!!interval,0,0) do
              z :=  list(list simp!* list('intervl,
                         getelv list('!!interval,i,1),
                         getelv list('!!interval,i,2)),
                   list var,mu). z;
      return z
   end;

symbolic procedure realroot(u,v,w,x);
   rederr("Real root finding not yet implemented");


% ***** Procedures for solving a system of eqns *****

symbolic procedure solvesys(exlist,varlis);
   % exlist is a list of standard forms, varlis a list of kernels.  If
   % the elements of varlis are linear in the elements of exlist, and
   % further the system of linear eqns so defined is non-singular, then
   % SOLVESYS returns a list of a list of standard quotients which are
   % solutions of the system, ordered as in varlis.  Otherwise an error
   % results.
   begin scalar eqtype,oldkord;
      oldkord := setkorder varlis;
      exlist := for each j in exlist collect reorder j;
      % See if equations are linear or non-linear.
      eqtype := 'solvelnrsys;
      for each ex in exlist do
         for each var in varlis do
            if not domainp ex and mvar ex=var
              then if ldeg ex>1 or not freeofl(lc ex,varlis)
                     then eqtype := 'solvenonlnrsys
             else ex := red ex;
      if eqtype eq 'solvenonlnrsys and null !*nonlnr
        then rederr "Non linear equation solving not yet implemented";
      exlist:=errorset(list(eqtype,mkquote exlist,mkquote varlis),t,t);
      setkorder oldkord;
      if errorp exlist then error1() else return car exlist
   end;

endmodule;


module glsolve; % Routines for solving a general system of linear eqns.

% Author: Eberhard Schruefer.

%**********************************************************************
%*** The number of equations and the number of unknowns are         ***
%*** arbitrary i.e. the system can be under- or overdetermined.     ***
%*** Method used is Cramer's rule, realized through exterior        ***
%*** multiplication.                                                ***
%**********************************************************************

fluid '(kord!*);

global '(!!arbint !*solvesingular);

% algebraic operator arbcomplex; % Already defined in main solve module.

symbolic procedure glsolve!-eval(u,bool);
   % This allows glsolve to be called at the user level. I'm not
   % sure this is now a good idea, since this code does not check
   % for non-linear equations and so on.
   begin scalar unknowns,equations,okord,solutions;
     if cdr u then
        unknowns := for each j in cdadr u collect !*a2k j;
           okord := setkorder append(unknowns,kord!*);
       equations := for each j in cdar u collect
                        reorder numr simp!* j;
     if null unknowns then unknowns := allkernf equations;
     solutions := glnrsolve(equations,unknowns);
     setkorder okord;
     if null solutions then return '(list); % empty list.
     solutions := nil . solutions;
     return 'list .
             for each j in unknowns collect
                 list('equal,j,mk!*sq car(solutions := cdr solutions))
   end;

symbolic procedure allkernf u;
   if null u then nil else union(kernels car u,allkernf cdr u);

put('glsolve,'psopfn,'glsolve!-eval);

symbolic procedure solvelnrsys(u,v);
   % This is hook to general solve package. u is a list of polynomials
   % (s.f.'s) linear in the kernels of list v. Result is a matrix
   % standard form for the solutions.
   list glnrsolve(u,v);

symbolic procedure glnrsolve(u,v);
   %u is a list of polynomials (s.f.'s) linear in the kernels
   %of list v. Result is an untagged list of solutions.
   begin scalar arbvars,sgn,x,y;
     x := !*sf2ex(car u,v);
     u := cdr u;
     for each j in u do
        if y := extmult(!*sf2ex(j,v),x)
           then x := y;
     if inconsistency!-chk x
       then rederr "SOLVE given inconsistent equations";
     arbvars := for each j in setdiff(v,lpow x) collect
                    j . makearbcomplex();
     if arbvars and null !*solvesingular
       then rederr "SOLVE given singular equations";
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
   %Special exterior multiplication routine. Degree of form v is
   %arbitrary, u is a one-form.
   if null u or null v then  nil
    else (if x then cdr x .* (if car x then negf multf(lc u,lc v)
                               else multf(lc u,lc v))
                          .+ extadd(extmult(!*t2f lt u,red v),
                                    extmult(red u,v))
           else extadd(extmult(red u,v),extmult(!*t2f lt u,red v)))
          where x = ordexn(car lpow u,lpow v);

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


module quartic;  % Procedures for solving cubic, quadratic and quartic
                 % eqns.

% Author: Anthony C. Hearn.

fluid '(!*sub2);

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
   simpexpt list(mk!*sq subs2!* u,'(quotient 1 3));
   % SIMPRAD(U,3);

symbolic procedure sqrtq u;
   simpexpt list(mk!*sq subs2!* u,'(quotient 1 2));
   % SIMPRAD(U,2);

symbolic procedure subs2!* u; <<!*sub2 := t; subs2 u>>;

symbolic procedure solvequadratic(a2,a1,a0);
   % a2, a1 and a0 are standard quotients.
   % solves a2*x**2+a1*x+a0=0 for x.
   % returns a list of standard quotient solutions.
   begin scalar d;
      d := sqrtq subtrsq(quotsqf(exptsq(a1,2),4),multsq(a2,a0));
      a1 := quotsqf(negsq a1,2);
      return list(subs2!* quotsq(addsq(a1,d),a2),
                  subs2!* quotsq(subtrsq(a1,d),a2))
   end;
   
symbolic procedure solvecubic(a3,a2,a1,a0);
   % a3, a2, a1 and a0 are standard quotients.
   % solves a3*x**3+a2*x**2+a1*x+a0=0 for x.
   % returns a list of standard quotient solutions.
   % See Abramowitz and Stegun, Sect. 3.8.2, for details.
   begin scalar q,r,sm,sp,s1,s2,x;
      a2 := quotsq(a2,a3);
      a1 := quotsq(a1,a3);
      a0 := quotsq(a0,a3);
      q := subtrsq(quotsqf(a1,3),quotsqf(exptsq(a2,2),9));
      r := subtrsq(quotsqf(subtrsq(multsq(a1,a2),multfq(3,a0)),6),
                   quotsqf(exptsq(a2,3),27));
      x := sqrtq addsq(exptsq(q,3),exptsq(r,2));
      s1 := cubertq addsq(r,x);
      s2 := if numr s1 then negsq quotsq(q,s1)
             else cubertq subtrsq(r,x);
         % This optimization only works if s1 is non zero.
      sp := addsq(s1,s2);
      sm := quotsqf(multsq(simp '(times i (sqrt 3)),subtrsq(s1,s2)),2);
      x := subtrsq(sp,quotsqf(a2,3));
      sp := negsq addsq(quotsqf(sp,2),quotsqf(a2,3));
      return list(subs2!* x,subs2!* addsq(sp,sm),
                  subs2!* subtrsq(sp,sm))
   end;
      
symbolic procedure solvequartic(a4,a3,a2,a1,a0);
   % Solve the quartic equation a4*x**4+a3*x**3+a2*x**2+a1*x+a0 = 0,
   % where the ai are standard quotients, using technique described in
   % Section 3.8.3 of Abramowitz and Stegun;
   begin scalar x,y,z;
      % Convert equation to monomial form.
      a3 := quotsq(a3,a4);
      a2 := quotsq(a2,a4);
      a1 := quotsq(a1,a4);
      a0 := quotsq(a0,a4);
      % Build and solve the resultant cubic equation.  We select an
      % arbitrary member of its set of solutions.  Ideally we should
      % only generate one solution, which should be the simplest.
      y := subtrsq(exptsq(a3,2),multfq(4,a2));
      % note that only first cubic solution is used here. We could save
      % computation by using this fact.
      x := car solvecubic(!*f2q 1,
                      negsq a2,
                      subs2!* subtrsq(multsq(a1,a3),multfq(4,a0)),
                      subs2!* negsq addsq(exptsq(a1,2),
                                          multsq(a0,y)));
      % Now solve the two equivalent quadratic equations.
      y := sqrtq addsq(quotsqf(y,4),x);
      z := sqrtq subtrsq(quotsqf(exptsq(x,2),4),a0);
      a3 := quotsqf(a3,2);
      x := quotsqf(x,2);
      return append(solvequadratic(!*f2q 1,addsq(a3,y),subtrsq(x,z)),
                    solvequadratic(!*f2q 1,subtrsq(a3,y),addsq(x,z)))
   end;

endmodule;


module solvetab;   % Simplification rules for SOLVE.

% Author: David R. Stoutemyer.
% Modifications by: Anthony C. Hearn and Donald R. Morrison;

algebraic operator sol;

put('asin, 'inverse, 'sin);

put('acos, 'inverse, 'cos);

algebraic;

comment Rules for reducing the number of distinct kernels in an
   equation;

for all a,b,x such that ratnump c and ratnump d let
   sol(a**c-b**d, x) = a**(c*lcm(c,d)) - b**(d*lcm(c,d));

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
   sol(log a + c, x) = a - e**c,
   sol(log a - c, x) = a - e**(-c);

for all a,b,x let
   sol(log a + log b, x) = a*b - 1,
   sol(log a - log b, x) = a - b,
   sol(cos a - sin b, x) = sol(cos a - cos(pi/2-b), x),
   sol(sin a + cos b, x) = sol(sin a - sin(b-pi/2), x),
   sol(sin a - cos b, x) = sol(sin a - sin(pi/2-b), x),
   sol(sin a + sin b, x) = sol(sin a - sin(-b), x),
   sol(sin a - sin b, x) = if !*allbranch then sin((a-b)/2)*
       cos((a+b)/2)  else a-b,
   sol(cos a + cos b, x) = if !*allbranch then cos((a+b)/2)*
       cos((a-b)/2)  else a+b,
   sol(cos a - cos b, x) = if !*allbranch then sin((a+b)/2)*
       sin((a-b)/2)  else a-b,
   sol(asin a - asin b, x) = a-b,
   sol(asin a + asin b, x) = a+b,
   sol(acos a - acos b, x) = a-b,
   sol(acos a + acos b, x) = a+b;

symbolic;

endmodule;


end;
