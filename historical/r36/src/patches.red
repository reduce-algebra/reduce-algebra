module patches; % Patches to correct problems in current release.

% Author: Anthony C. Hearn.

% Copyright (c) 1998 Anthony C. Hearn.  All Rights Reserved.

global '(patch!-date!*);

patch!-date!* := "30 Aug 98";

% Bugs fixed by these patches.

% 30 Aug 95.  With depend statements, groesolve did not always eliminate
%             the required variable.

% 10 Nov 95.  Default value of evallhseqp changed to on, responding to
%             user complaints that the "off" setting was not natural.

% 20 Nov 95.  Expressions like int((1/log 2)^x,x) would not return a
%             closed form.

% 21 Nov 95.  Calling SUB with the wrong number of arguments could lead
%             to a confusing error.

% 22 Nov 95.  The modular factorizer code only works for small moduli,
%             and gave strange errors if a large modulus was used.

% 27 Nov 95.  Expressions like prod(k+i,i,0,0) contained "i" in the
%             result.  This could also cause a problem with ztrans.

%  1 Dec 95.  The integral of csc(x) was not correct due to an error
%             in a pattern transformation.

%  3 Dec 95.  Empty rule lists led to an error.

%  4 Dec 95.  On some systems, "yesp" would not respond to uppercase
%             letters.

% 10 Dec 95.  Primep was unnecessarily inefficient for some ranges of
%             numbers.

% 12 Dec 95.  The expression solve((x-i)^2,x); did not correctly show
%             root multiplicity (along we several other cases).

% 18 Dec 95.  In EXCALC, an index -0 could be simplified to 0.

% 19 Dec 95.  Higher order partial derivatives would not simplify
%             properly in EXCALC. E.g., @(f,x,y) := x**2+y**2;
%             @(f,y,y,x); @(f,x,y,y); @(f,x,x,y); @(f,x,y,x);

% 27 Dec 95.  REPART and IMPART didn't always compute the correct value.

% 28 Dec 95.  On rare occasions, SOLVE could try to convert a rounded
%             number to modular form.

%  5 Jan 96.  Integrals involving i, e.g., int(i*e**(i*x)*cos(x),x)
%             could generate a spurious "zero divisor" message.

%  6 Jan 96.  With ROUNDED on, SOLVE could return erroneous solutions
%             for problems involving elementary function expressions.

% 10 Jan 96.  With ROUNDED on and SPECFN loaded, erf(-1.0) returned 0.

% 11 Jan 96.  The sequence depend y,x; df(df(y,x)+3*df(y,x,2),x);
%             did not recognize the dependency and returned 0.

% 12 Jan 96.  solve(y*(x^x*x-1),x) produced the spurious solution y=0.

% 16 Jan 96.  With SPECFN loaded, negative gamma function values could
%             occur (e.g., with binomial(5,-5)).

% 17 Jan 96.  The sequence let x^2=0; (1/x)^2; returned 1/0.

% 18 Jan 96.  The GC switch was not defined in the CSL version.

% 26 Jan 96.  The sequence load_package solve; depend y,x;
%             root_of(df(y_,x)-x*y_+2,y_,tag); lost the derivative.

% 11 Feb 96.  DCOMBINE would not handle TPS expressions correctly in
%             some domains.

% 15 Feb 96.  Integrals like int((cos(7*x))/e**(2*i*x),x) would not
%             return a closed form.

% 17 Feb 96.  Some output options would not work well in CSL-based
%             window systems.

% 18 Feb 96.  The sequence "count:=0; equ(count:=count+1):=peter;"
%             set count to 2 rather than 1.

% 19 Feb 96.  With some substitutions active, DET could give a
%             catastrophic error.

% 25 Feb 96.  Depend/nodepend updated to handle lists in first argument.

% 26 Feb 96.  The following example gave incorrect zero solutions:
%             solve(({ex*z+y*b1-x*b2,-z*b1+ex*y+x*b3,z*b2-y*b3+ex*x}
%             where ex=sqrt(-b1**2-b2**2-b3**2)),{x,y,z});

% 27 Feb 96.  With small modular coefficients, Groebner calculations
%             could normalize coefficients incorrectly.

%  5 Mar 96.  The sequence "load_package excalc; pform o(i,j)=0;
%             o(1,20);" gave an error.

%  6 Mar 96.  Errors could occur with "on ezgcd" in rounded or rational
%             modes.

% 11 Mar 96.  INT could fail with"on nolnr" (e.g. int(-exp(x^2), x)).

% 28 Mar 96.  "on complex; e^repart x;" went into a loop.

% 15 Apr 96.  The sequence "vector v1,v2; index i1,i2; nospur f;
%             (v1.i1*v2.i2-v1.i2*v2.i1)*(g(f,i1,i2)-g(f,i2,i1));"
%             had uncollected equal terms.

% 20 Apr 96.  In rare cases, a solvable system of equations would not
%             produce a solution.

% 21 Apr 96.  In EXCALC, indexrange 1,2,3; and indexrange {i,j,k}=
%             {1,2,3}; did not produce identical orders.

% 22 Apr 96.  In EXCALC, exterior products of indexed forms did not
%             respect korder settings.

% 23 Apr 96.  VAROPT was not declared a switch in the solve package.

% 25 Apr 96.  Some expressions involving non-commuting objects did not
%             reduce to lowest terms.

% 27 Apr 96.  Numerical factors were not always cancelled in numerators
%             and denominators of non-commuting expressions.

% 28 Apr 96.  With PRI off, non-commuting expressions were printed in
%             the reverse order.

% 30 Apr 96.  primep of a large prime could sometimes give an error
%             " Overlarge modulus".

%  3 May 96.  int(1/(x**2*y0+x**2+x*y0**2+3*x*y0+x+y0**2+y0),x) was
%             returned in terms of complex expressions rather than real.

%  9 May 96.  With non-id kernels, SOLVE did not always return a closed
%             form when one existed (e.g., solve(-2*sqrt(x)*a
%             + log(sqrt(y(x)**2 - 1) + y(x))=0, y(x))).

% 19 May 96.  Solutions of some equations were not complete, e.g.,
%             solve((2*y^(2/3)*a*c+2*y^(2/3)*a*x+3)/(2*y^(2/3)*a)=0,y);

% 20 May 96.  The sequence load numeric;fktn:=100*(x1**2-x2)^2+(1-x1)^2;
%             num_min(fktn,x1=-1.2,x2=1,iterations=200); gave wrong
%             results.

% 21 May 96.  The sequence "let x^3=0;on factor; x^3;" did not return 0.

% 22 May 96.  Some non-commuting expressions had terms in wrong order
%             after the patch of 25 Apr 96,
%             e.g., noncom u,v; (u(-1)*b(1) + u(-1)*v(-1))*u(1)*b(1).

% 27 May 96.  df((1/x)**(2/3),x); led to an infinite loop.

%  4 Jun 96.  Solutions of some nonlinear systems were not returned in
%             closed form even though straightforward solutions existed.

% 15 Jun 96.  Making evallhseqp on by default caused problems in NCPOLY.

% 16 Jul 96.  The sequence precision 16; on rounded;
%             gcd((x-3*y)*(x-y)^5,(x-3*y)^5); returned 1.

% 17 Jul 96.  det mat((0,0,a),(0,b,0),(c,0,0)); had the wrong sign.

% 18 Jul 96.  Ordering problems still occurred in products that
%             included noncommuting objects.

% 19 Jul 96.  Some switch combinations did not simplify enough.
%             e.g., off precise; on div; sqrt((a-b)/a);

% 21 Jul 96.  With EXP off, df(atan((( - x + 1)/x)**0.5),x); had
%             unsimplified terms.

% 27 Jul 96.  Ratios of expressions with non-commuting terms were not
%             always reduced to lowest terms.

%  4 Aug 96.  If "factor" was used, some non-commuting expressions
%             evaluations would result in an infinite loop.

%  5 Aug 96.  The sequence "vector p,q; q.q where q=>p;" caused q to
%             lose its vector property.

% 19 Aug 96.  The sequence "p 2:= sqrt(1-p^2);" resulted in a recursive
%             error.

% 11 Sep 96.  The sequence "load_package arnum; on complex; on arnum;
%             off arnum;" lead to a nonsensical error.

% 12 Sep 96.  In very rare cases, the integration code could make an
%             invalid datastructure.

%  3 Nov 96.  The sequence on rational; lcof(1/2,x)+y; led to a spurious
%             error.

%  2 Dec 96.  sub(x=5,sqrt(x+8-6*sqrt(x-1))); returned -1 instead of 1.

% 21 Dec 96.  The sequence "on evallhseqp; depend y,x; off mcd;
%             {df(y,x)=(sqrt(x^4-x^2*y^2-x^2+y^2)+x^2*y-y)/(x^3-x)};"
%             lead to a catastrophic error.

% 22 Dec 96.  The sequence "on rounded; df(sin x,x,3.0);" gave an error.

% 20 Jan 97.  solve({0,x^2},x); gave {}, not {x=0}.

% 29 Jan 97.  The sequence "precision 16; on rounded,complex;
%             solve({-x^3,1.002*x});" gave a system error.

% 30 Jan 97.  The sequence "on rational; symbolic !:quotient(2,1);" gave
%             a system error.

% 31 Jan 97.  The sequence "on rounded; solve({1,1.002*x});" gave a
%             system error.

% 20 Feb 97.  setmod 11; on modular; solve(x=y,x); did not give a
%             result in lowest terms.

% 21 Feb 97.  pf(1/(x-1)^2/(x-2)/m^2,x) gave a wrong result.

% 22 Feb 97.  The factorization routines did not recognize balanced_mod.

% 23 Feb 97.  The sequence "on rounded; solve({1.002,0.002*x});" gave a
%             system error.

%  2 Apr 97.  Determinants of matrices involving surds could produce a
%             catastrophic error.

%  9 Apr 97.  Evaluation of some non-commuting expressions could lead to
%             an infinite loop.

%  9 Aug 97.  Some definite integrals were not computed to sufficient
%             precision.

%  1 Sep 97.  Some zero-valued expressions would not reduce properly.
%             e.g., 2783/1162261467*59049**((-6)/17)*
%                  127173474825648610542883299603**(23/68)*
%                  43498407522777568690053259202734931579**(6/17)*
%                  43498407522777568690053259202734931579**((-23)/68)
%                  - 2783/9*7625597484987**((-1)/34)
%                  *127173474825648610542883299603**(1/68)*
%                  43498407522777568690053259202734931579**(6/17)*
%                  43498407522777568690053259202734931579**((-23)/68);

% 21 Oct 97.  Depend did not clear the algebraic cache.

% 29 Nov 97.  A statement "noncom e;" incorrectly applied to the
%             variable e.

% 24 Dec 97.  The sequence "on complex; factorize(i*c^3+3c^2-c^2*q-3i*c
%             +2i*c*q+q-1);" dropped a factor of i.

% 29 Dec 97.  Expressions involving "roots_of" were not always reduced
%             to lowest terms (e.g., s:=solve(p:=x^5-x+1,x); sub(s,p);
%             sub(s,p)).

% 30 Dec 97.  Floating point numbers with the "part" operator could
%             cause a memory exception (e.g., 0.5*part({1,2},1);).

% 31 Dec 97.  Successive calls of "random" did not always lead to a new
%`            value.

%  1 Jan 98.  The sequence "let (~x)^(~y) => ee^((~y)*log(~x)) when
%             ((freeof(~x,e)) and not(numberp(~y)) and (freeof(~x,ee)));
%             off mcd; (1/x-1)^-1;" gave a syntax error.

%  2 Jan 98.  Some expressions with NOSPUR lines did not simplify
%             completely (e.g., vector p,q; nospur l; v1 := g(l,a,p);
%             v2 := g(l,a,q); v1*v2;)

%  9 Jan 98.  A Hodge dual using EXCALC could include a spurious "sgn"
%             term (e.g., coframe o 1 = d t, o 2 = d x; # 1;).

% 17 Jan 98.  "On ezgcd" doesn't work with the complex domain. (e.g.,
%              on ezgcd,complex; ( - i*m*n**3 + 3*i*m*n*q**2 + 3*i*n**3*q
%              - i*n*q**3 + 3*m*n**2*q - m*q**3 + n**4 - 3*n**2*q**2)
%              /(n**6 + 3*n**4*q**2 + 3*n**2*q**4 + q**6);

% 18 Jan 98.  An expression like "x-y:=0" would print as "y-y:=0".

% 19 Jan 98.  Matrix exponents with modular on were reduced with
%             respect to the modulus.

% 21 Jan 98.  With defint loaded, int(sin(y),y,0,pi) did not evaluate
%             correctly.

% 24 Jan 98.  The sequence "load_package excalc; pform u k=l; setmod 2;
%             on modular; u(-k);" resulted in u(k) rather than u(-k).

% 27 Jan 98.  In rare cases, determinants in the CSL version could have
%             the wrong sign.

% 31 Jan 98.  With rationalize on, expressions didn't always reduce as
%             expected.

%  1 Feb 98. Some "where" statements didn't simplify fully, e.g.,
%            x:= (e^(12i*pi/5) - e^(8i*pi/5) + 4e^(6i*pi/5) - e^(4i*pi/5)
%            - 2e^(2i*pi/5) - 1)/(16e^(6i*pi/5)); y:= {e^(~a*i*pi/~(~ b))
%            => e^((a - b)/b*i*pi) when numberp a and numberp b and a>b};
%            x where y;

%  4 Feb 98. The sequence "on combineexpt,rational; 1/sqrt(2)*(rt^(2/3)
%              *m^(1/3)*3^(2/3))/2^(5/6);" never completed.

% 18 Feb 98. Factorization of expressions using domains with multiple
%            units could omit one of those units. E.g., on complex;
%            factorize(a*( - cos(th)*a - i*r));

% 19 Feb 98. A mismatch of the dimension of a coframe basis and a
%            signature gave a very confusing error message.
%            E.g. coframe e 0 = d t, e 1 = d x with signature -1,1,1;

% 22 Mar 98. With precise on, some expressions were not returned as an
%            absolute value (e.g., sqrt(e^(2z)/((e^(2z)+1)^2*a^2))).

% 27 Mar 98. Without the algebraic integrator loaded, some integrals of
%            expressions involving fractional powers were wrong (e.g.,
%            a:=r**(-3/2)*(1-r)**(-1/2)).

% 31 Mar 98. A "sqfrf failure" error could occur in some cases.

%  6 Apr 98. With algint on, some integrals could cause a catastrophic
%            error (e.g., int(-2x/(sqrt(2x^2+1)-2x^2+1),x)).

% 12 May 98. The sequence k := 1; limit(k,k,0); gave the wrong value 1.
%            It now gives a kernel error on k.

% 20 Jul 98. Some non-commuting expressions did not reduce to lowest
%            terms (e.g., noncom p,q;for all x let p(x)*q(x)=q(x)*p(x)-i;
%            cos(t)*p(x)^2*q(x)^3 - q(x)^3*cos(t)*p(x)^2;)

% 23 Jul 98. Non-commuting terms in an integrand were sometimes returned
%            in the wrong order.

% 31 Jul 98. Excalc used the function oddp incorrectly.

% 30 Aug 98. Some non-commuting expression simplifications could lead to
%            a catastrophic error in the gcd code.


% Alg declarations.

fluid '(!*nospurp props!*);

patch alg;

% 10 Nov 95.

on evallhseqp;

% 21 Nov 95.

symbolic procedure subeval u;
   begin scalar x,y,z,ns;
      if null(u and cdr u)
       then rederr "SUB requires at least 2 arguments";
      (while cdr u do
          <<x := reval car u;
            if getrtype x eq 'list then u := append(cdr x,cdr u)
             else <<if not eqexpr x then errpri2(car u,t);
                    y := cadr x;
                    if null getrtype y then y := !*a2kwoweight y;
                    if getrtype caddr x then ns := (y . caddr x) . ns
                     else z := (y . caddr x) . z;
                    u := cdr u>>>>) where !*evallhseqp=nil;
      x := aeval car u;
      if ns then x := subeval2(ns,x);
      return subeval1(z,x)
   end;

%  3 Dec 95.

symbolic procedure rule!-list(u,type);
   begin scalar v,x,y,z;
   a: frasc!* := nil;
      if null u or u = {{}} then return (mcond!* := nil);
      mcond!* := t;
      v := car u;
      if idp v
        then if (x := get(v,'avalue)) and car x eq 'list
               then <<u := append(reverse cdadr x,cdr u); go to a>>
              else typerr(v,"rule list")
       else if car v eq 'list
          then <<u := append(cdr v,cdr u); go to a>>
       else if car v eq 'equal
        then lprim "Please use => instead of = in rules"
       else if not(car v eq 'replaceby) then typerr(v,"rule");
      y := remove!-free!-vars cadr v;
      if eqcar(caddr v,'when)
        then <<mcond!* := formbool(remove!-free!-vars!* caddr caddr v,
                                   nil,'algebraic);
               z := remove!-free!-vars!* cadr caddr v>>
       else z := remove!-free!-vars!* caddr v;
      rule!*(y,z,frasc!*,mcond!*,type);
      u := cdr u;
      go to a
   end;

symbolic procedure validrule1 u;
   if atom u then nil
    else if car u eq 'list
     then if null cdr u then {{}}
           else for each j in cdr u collect validrule1 j
    else if car u eq 'replaceby then u
    else if car u eq 'equal then 'replaceby . cdr u
    else nil;

% 10 Dec 95.

symbolic procedure primep n;
   if not fixp n then typerr(n,"integer")
    else if n<0 then primep(-n)
    else if n=1 then nil
    else if n<=!*last!-prime!-in!-list!* then n member !*primelist!*
    else begin scalar p;
       p := !*primelist!*;
       while p and remainder(n,car p) neq 0 do p := cdr p;
       return if p then nil
               else if isqrt n<!*last!-prime!-in!-list!* then t
               else (if n>largest!-small!-modulus then general!-primep n
                      else small!-primep n)
                    where current!-modulus=current!-modulus
     end;

% 26 Jan 96, 25 Feb 96, 21 Oct 97.

symbolic procedure depend u;
   depend0(u,t);

symbolic procedure nodepend u;
   <<rmsubs(); depend0(u,nil)>>;

symbolic procedure depend0(u, bool);
 <<alglist!* := nil . nil;
   while u do
      begin scalar v;
         v := cdr u;
         while v and not rlistp car v do v := cdr v;
         for each y in (if rlistp car u then cdar u else {car u}) do
            begin scalar x;
               x := u;
               while not((x := cdr x) eq v) do depend1(y,car x,bool);
               if idp y
                 then <<y := intern compress append(explode y,'(!! !_));
                        x := u;
                        while not((x := cdr x) eq v) do
                           depend1(y,car x,bool)>>
            end;
         u := v
      end>>;

% 15 Apr 96.

symbolic procedure ordpp(u,v);
   begin scalar x;
        if car u eq car v then return cdr u>cdr v;
        x := kord!*;
        u := car u;
        v := car v;
    a:  if null x then return ordpa(u,v)
         else if u eq car x then return t
         else if v eq car x then return nil;
        x := cdr x;
        go to a
   end;

symbolic procedure ordpa(u,v);
   if null u then null v
    else if null v then t
    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
    else if atom u
       then if atom v
                then if numberp u then numberp v and not(u<v)
                      else if idp v then orderp(u,v)
                      else numberp v
             else nil
    else if atom v then t
    else if car u=car v then ordpa(cdr u,cdr v)
    else ordpa(car u,car v);

% 25 Apr 96, 18 Jul 96, 29 Nov 97.

symbolic procedure ordp(u,v);
   if null u then null v
    else if null v then t
    else if vectorp u then if vectorp v then ordpv(u,v) else atom v
    else if atom u
       then if atom v
                then if numberp u then numberp v and not(u<v)
                      else if idp v then orderp(u,v)
                      else numberp v
             else nil
    else if atom v then t
    else if car u=car v then flagp(car u,'noncom) or ordpl(cdr u,cdr v)
    else if flagp(car u,'noncom)
     then if flagp(car v,'noncom) then ordp(car u, car v) else t
    else if flagp(car v,'noncom) then nil
    else ordp(car u,car v);

symbolic procedure ordpl(u,v);
   if atom u then ordp(u,v)
    else if atom v then t
    else if car u=car v then ordpl(cdr u,cdr v)
    else ordp(car u,car v);

% 30 Apr 96.

symbolic procedure set!-modulus p; set!-general!-modulus p;

symbolic procedure set!-general!-modulus p;
  if not numberp p or p=0 then current!-modulus
   else begin
     scalar previous!-modulus;
     previous!-modulus:=current!-modulus;
     current!-modulus:=p;
     modulus!/2 := p/2;
     if p <= largest!-small!-modulus then set!-small!-modulus p;
     return previous!-modulus
  end;

% 19 May 96.

% 2 Jun 96:  added test for numerical denom in quotient test.

symbolic procedure simpexpt2(u,n,flg);
   begin scalar m,n,x,y;
    if u=1 then return 1 ./ 1;
    m:=numr n;
    if pairp u then <<
     if car u eq 'expt
      then <<n:=multsq(m:=simp caddr u,n);
             if !*precise
                and numberp numr m and evenp numr m
               then u := list('abs,cadr u)
              else u := cadr u;
             return simpexpt1(u,n,flg)>>
     else if car u eq 'sqrt and not !*keepsqrts
      then return simpexpt2(cadr u, multsq(1 ./ 2,n),flg)
     else if car u eq 'times and not !*precise
      then <<x := 1 ./ 1;
             for each z in cdr u do x := multsq(simpexpt1(z,n,flg),x);
             return x>>
     else if car u eq 'times and (y:=split!-sign cdr u) and car y
      then <<x := simpexpt1(retimes append(cadr y,cddr y),n,flg);
             for each z in car y do x := multsq(simpexpt1(z,n,flg),x);
             return x>>
     else if car u eq 'quotient
        and (not !*precise or numberp caddr u and caddr u>0)
      then <<if not flg and !*mcd then
                return simpexpt1(prepsq simp!* u,n,t);
             n := prepsq n;
             return quotsq(simpexpt{cadr u,n},simpexpt{caddr u,n})>>>>;
    if null flg
      then <<if null(dmode!* and idp u and get(u,dmode!*))
               then u := prepsq simp!* u;
             return simpexpt1(u,n,t)>>
     else if numberp u and zerop u then return nil ./ 1
     else if not numberp m then m := prepf m;
    n := prepf denr n;
    if m memq frlis!* and n=1 then return list ((u . m) . 1) . 1;
    if !*mcd or not numberp m or n neq 1
      or atom u or denr simp!* u neq 1 then return simpx1(u,m,n)
      else return mksq(u,m)
   end;

% 27 May 96.

symbolic procedure mkrootsq(u,n);
   if u=1 then !*d2q 1
    else if n=2 and (u= -1 or u= '(minus 1)) then simp 'i
    else if eqcar(u,'expt) and fixp caddr u
     then exptsq(mkrootsq(cadr u,n),caddr u)
    else begin scalar x,y;
            if fixp u and not minusp u
                      and (u<factorbound!* or !*ifactor)
                      and (length(x := zfactor u)>1 or cdar x>1)
              then return mkrootsql(x,n);
            x := if n=2 then mksqrt u
                  else list('expt,u,list('quotient,1,n));
            if y := opmtch x then return simp y
             else return mksq(x,1)
         end;

% 19 Jul 96.

symbolic procedure simpexpt1(u,n,flg);
   begin scalar !*allfac,!*div,m,x,y;
      if onep u then return 1 ./ 1;
      !*allfac := t;
      m := numr n;
      if m=1 and denr n=1 then return simp u;
      if u eq 'e and domainp denr n and not domainp m and ldeg m=1
         and null red m and eqcar(mvar m,'log) then return
            simpexpt1(prepsq!* simp!* cadr mvar m,lc m ./ denr n,nil);
      if not domainp m or not domainp denr n
        then return simpexpt11(u,n,flg);
      x := simp u;
      if null m
        then return if null numr x then rerror(alg,14,"0**0 formed")
                     else 1 ./ 1;
      return if null numr x
               then if domainp m and minusf m
                      then rerror(alg,15,"Zero divisor")
                     else nil ./ 1
              else if atom m and denr n=1 and domainp numr x
                 and denr x=1
               then if atom numr x and m>0 then !*d2q(numr x**m)
                     else <<x := !:expt(numr x,m) ./ 1;
                            if !*mcd then resimp x else x>>
              else if y := domainvalchk('expt,list(x,n)) then y
              else if atom m and denr n=1
               then <<if not(m<0) then exptsq(x,m)
                       else if !*mcd then invsq exptsq(x,-m)
                       else multf(expf(numr x,m),mksfpf(denr x,-m))
                               ./ 1>>
              else simpexpt11(if flg then u else prepsq!* subs2!* x,n,t)
   end;

%  5 Aug 96.

symbolic procedure evalletsub2(u,v);
   begin scalar !*resimp,newrule!*,oldrules!*,props!*,x,y,z,z1;
      x:=car u; u:=cadr u;
      for each j in x do
         if eqcar(j,'replaceby) then z := j . z
          else if null v and eqcar(j,'equal)
           then <<lprim "Please use => instead of = in rules";
                  z := ('replaceby . cdr j) . z>>
          else if (y := validrule j) or (y := validrule reval j)
           then (y:=reverse car y) and <<rule!-list(y,t); z1 := y . z1>>
          else typerr(j,"rule list");
      rule!-list(z,t);
      !*resimp := t;
      u := errorset!*(u,nil);
      !*resimp := nil;
      for each j in z . z1 do rule!-list(j,nil);
      for each j in oldrules!*
          do if atom cdar j
               then if idp cdar j
                      then if cdar j eq 'scalar
                             then let3(caar j,cadr j,nil,t,nil)
                            else typelet(caar j,cadr j,nil,t,cdar j)
                     else nil
              else rule!*(car j,cadr j,caddr j,cadddr j,'old);
      restore_props();
      return u
   end;

symbolic procedure rule!*(u,v,frasc,mcond,type);
   begin scalar x;
      frasc!* := frasc;
      mcond!* := mcond eq t or subla(frasc,mcond);
      if type and type neq 'old
        then <<newrule!* := list(u,v,frasc,mcond);
               if idp u
                 then <<if x := get(u,'rtype)
                          then <<props!*:= (u . ('rtype . x)) . props!*;
                                 remprop(u,'rtype)>>;
                        if x := get(u,'avalue)
                          then <<updoldrules(x,nil);
                                 remprop(u,'avalue)>>>>;
               if v=0 and eqcar(u,'expt) and idp cadr u
                  and numberp caddr u
                  and (x := assoc(cadr u,asymplis!*))
                then updoldrules(x,nil)>>;
      return rule(u,v,frasc,if type eq 'old then t else type)
   end;

symbolic procedure restore_props;
   for each j in props!* do
      if pairp cdr j then put(car j,cadr j,cddr j)
       else flag({car j},cdr j);

% 19 Aug 96.

symbolic procedure put!-kvalue(u,v,w,x);
   if (if eqcar(x,'!*sq) then sq_member(w,cadr x) else smember(w,x))
     then recursiveerror w
    else put(u,'kvalue,aconc(v,{w,x}));

%  2 Dec 96.

symbolic procedure unnest!-sqrt!-sqrt(a,b,r); nil;

% 21 Dec 96, 22 Mar 98.

symbolic procedure radf(u,n);
   begin scalar ipart,rpart,x,y,z,!*gcd,!*mcd;
      if null u then return list u;
      !*gcd := !*mcd := t;
      ipart := 1;
      z := 1;
      while not domainp u do
     <<y := comfac u;
       if car y
         then <<x := divide(pdeg car y,n);
            if car x neq 0
              then ipart := multf(
                   if evenp car x
                      then !*p2f(mvar u .** car x)
                    else if !*precise
                     then !*p2f mksp(mvar numr
                                     simp list('abs,if sfp mvar u
                                                      then prepf mvar u
                                                     else mvar u),
                                       car x)
                    else check!-radf!-sign(!*p2f(mvar u .** pdeg car y),
                                           !*p2f(mvar u .** car x),
                                           n),
                    ipart);
            if cdr x neq 0
              then rpart := mkexpt(sfchk mvar u,cdr x) . rpart>>;
       x := quotf(u,comfac!-to!-poly y);
       u := cdr y;
       if !*reduced and minusf x
         then <<x := negf x; u := negf u>>;
       if flagp(dmode!*,'field) then
          <<y := lnc x;
                if y neq 1 then <<x := quotf(x,y); z := multd(y,z)>>>>;
       if x neq 1
         then <<x := radf1(sqfrf x,n);
                y := car x;
                if y neq 1 then
                   <<if !*precise and evenp n
                       then y := !*kk2f {'abs,prepf y};
                     ipart := multf(y,ipart)>>;
                rpart := append(rpart,cdr x)>>>>;
      if u neq 1
    then <<x := radd(u,n);
           ipart := multf(car x,ipart);
           rpart := append(cdr x,rpart)>>;
      if z neq 1
    then if !*numval
        and (y := domainvalchk('expt,
                       list(!*f2q z,!*f2q !:recip n)))
           then ipart := multd(!*q2f y,ipart)
          else rpart := prepf z . rpart;
      return ipart . rpart
   end;

% 29 Jan 97.

symbolic procedure constant_expr_listp u;
   if atom u
     then numberp u or flagp(u,'constant) or u eq 'i and idomainp()
    else constant_exprp car u and constant_expr_listp cdr u;

%  1 Sep 97.

symbolic procedure exptchksq u;
   (if u=v or denr v=1 then v
     else multsq(numr v ./1,1 ./denr v))
    where v = (exptchk numr u ./ exptchk denr u);

% 1 Sep 97, 4 Feb 98.

symbolic procedure exptunwind(u,v);
   begin scalar x,x1,x2,y,z,z2;
  a:  if null v then return u;
      x := caar v;
      x1 := cadr x;
      x2 := caddr x;
      y := cdar v;
      v := cdr v;
      while (z := assocp1(x1,v)) and
         (z2 := simp {'plus,{'times,x2,y},{'times,caddar z,cdr z}})
         and (!*combineexpt or (fixp numr z2 and fixp denr z2))
        do <<if fixp numr z2 
               then <<x2 := divide(numr z2,denr z2);
                      if car x2>0
                        then <<if fixp x1 then u := multf(x1**car x2,u)
                                else u := multpf(mksp(x1,car x2),u);
                               z2 := cdr x2 ./ denr z2>>;
                      y := numr z2>>
              else if domainp numr z2 then y := 1
              else <<y := lnc cdr comfac numr z2;
                     if not fixp y then y := 1>>;
             x2 := prepsq(quotf(numr z2,y) ./ denr z2);
             v := delete(z,v)>>;
      if !*combineexpt and y=1 and fixp x1 then
         <<while (z := assocp2(x2,v)) and cdr z=1 and fixp cadar z do
              <<x1 := cadar z * x1; v := delete(z,v)>>;
           if eqcar(x2,'quotient) and fixp cadr x2 and fixp caddr x2
                and cadr x2<caddr x2
             then <<z := nrootn(x1**cadr x2,caddr x2);
                    if cdr z = 1 then u := multd(car z,u)
                     else if car z = 1
                      then u := multf(formsf(x1,x2,1),u)
                     else <<u := multd(car z,u);
                            v := (list('expt,cdr z,x2) . 1) . v>>>>
            else u := multf(formsf(x1,x2,y),u)>>
       else u := multf(formsf(x1,x2,y),u);
      go to a
   end;

symbolic procedure zfactor n; zfactor1(n,t);

symbolic procedure zfactor1(n,bool);
   if n<0 then ((-1) . 1) . zfactor1(-n,bool)
    else if n<4 then list(n . 1)
    else begin scalar primelist,factor!-list,p,qr;
       primelist := !*primelist!*;
       factor!-list := nil;
       while primelist do
        <<p := car primelist; primelist := cdr primelist;
          while cdr(qr := divide(n, p)) = 0 do
            <<n:= car qr; factor!-list:= add!-factor(p,factor!-list)>>;
       if n neq 1 and p*p>n
         then <<primelist := nil;
                factor!-list:=add!-factor(n,factor!-list);
                n := 1>>>>;
       if n=1 then return factor!-list;
       return if null bool then (n . 1) . factor!-list
               else mcfactor!*(n,factor!-list)
     end;

symbolic procedure mkrootsq(u,n);
   % U is a prefix expression, N an integer.
   % Value is a standard quotient for U**(1/N).
   if u=1 then !*d2q 1
    else if n=2 and (u= -1 or u= '(minus 1)) then simp 'i
    else if eqcar(u,'expt) and fixp caddr u
     then exptsq(mkrootsq(cadr u,n),caddr u)
    else begin scalar x,y;
            if fixp u and not minusp u
                      and (length(x := 
                            zfactor1(u,u<factorbound!* or !*ifactor))>1
                           or cdar x>1)
              then return mkrootsql(x,n);
            x := if n=2 then mksqrt u
                  else list('expt,u,list('quotient,1,n));
            if y := opmtch x then return simp y
             else return mksq(x,1)
         end;

% 30 Dec 97.

symbolic procedure eval!-yetunknowntypeexpr(u,v);
   if atom u 
      then ((if w then eval!-yetunknowntypeexpr(cadr w,v)
              else u)
            where w = get(u,'avalue))
    else if car u eq '!*sq or get(car u,'dname) or car u eq '!:dn!:
     then u
    else ((if x and (getrtype u eq 'yetunknowntype)
              then apply1(x,cdr u)
            else car u . for each j in cdr u collect
                             eval!-yetunknowntypeexpr(j,v))
          where x = get(car u,'psopfn));

% 2 Jan 98.

symbolic procedure simp!* u;
   begin scalar !*asymp!*,x;
        if eqcar(u,'!*sq) and caddr u and null !*resimp
          then return cadr u;
        x := mul!* . !*sub2;
        mul!* := nil;
        u:= simp u;
        if !*nospurp then mul!* := union(mul!*,'(isimpq));
        for each j in mul!* do u:= apply1(j,u);
        mul!* := car x;
        u := subs2 u;
        if !*combinelogs then u := clogsq!* u;
        if dmode!* eq '!:gi!: and not !*norationalgi
          then u := girationalize!: u
          else if !*rationalize then u := rationalizesq u;
        !*sub2 := cdr x;
        if !*asymp!* and !*rationalize then u := gcdchk u;
        return u
   end;

% 19 Jan 98.

symbolic procedure dsimp(u,v);
   if numberp u then list list u
    else if atom u
     then (if x and subfg!* then dsimp(cadr x,v)
            else if flagp(u,'share) then dsimp(lispeval u,v)
            else <<flag(list u,'used!*); list list u>>)
      where x= get(u,'avalue)
    else if car u eq 'plus
     then for each j in cdr u join dsimp(j,v)
    else if car u eq 'difference
     then nconc!*(dsimp(cadr u,v),
                dsimp('minus . cddr u,v))
    else if car u eq 'minus
     then dsimptimes(list(-1,carx(cdr u,'dsimp)),v)
    else if car u eq 'times then dsimptimes(cdr u,v)
    else if car u eq 'quotient
     then dsimptimes(list(cadr u,list('recip,carx(cddr u,'dsimp))),v)
    else if not(getrtype u eq v) then list list u
    else if car u eq 'recip
     then list list list('!*div,carx(cdr u,'dsimp))
    else if car u eq 'expt then (lambda z;
       if not numberp z then errpri2(u,t)
        else if z<0
         then list list list('!*div,'times . nlist(cadr u,-z))
         else if z=0 then list list list('!*div,cadr u,1)
        else dsimptimes(nlist(cadr u,z),v))
      reval_without_mod caddr u
    else if flagp(car u,'noncommuting) then list list u
    else if arrayp car u
       then dsimp(getelv u,v)
    else (lambda x; if x then dsimp(x,v)
                     else (lambda y; if y then dsimp(y,v)
                                          else list list u)
                                opmtch revop1 u)
        opmtch u;

symbolic procedure reval_without_mod u;
   if dmode!* eq '!:mod!: then (reval u where dmode!* = nil)
    else reval u;

%  1 Feb 98.

symbolic procedure evalletsub1(u,v);
  begin scalar x,w;
     x:=car u;
     u:=carx(cdr u,'simpletsub);
     if eqcar(x,'list) then x := cdr x else errach 'simpletsub;
     w:=evalletsub2({x,{'aeval,mkquote{'aeval,u}}},v);
     return if errorp w then rerror(alg,24,"Invalid simplification")
      else car w
  end;

flag('(aeval),'opfn);

endpatch;


patch defint;

% 21 Jan 98.

symbolic procedure new_meijer(u);
begin scalar f,y,mellin,new_mellin,m,n,p,q,old_num,old_denom,temp,a1,
b1,a2,b2,alpha,num,denom,n1,temp1,temp2,coeff,v,var,new_var,new_y,
new_v,k;
f := prepsq simp car u;
y := caddr u;
mellin := bastab(car f,cddr f);
temp := car cddddr mellin;
var := cadr f;
temp := reval algebraic(sub(x=var,temp));
mellin := {car mellin,cadr mellin,caddr mellin,cadddr mellin,temp};
temp := reduce_var(cadr u,mellin,var);
alpha := simp!* car temp;
new_mellin := cdr temp;
if car cddddr new_mellin neq car cddddr mellin then
        << k := car cddddr mellin;
           y := reval algebraic(sub(var=y,k));
           new_y := simp y>>
else
<< new_var := car cddddr new_mellin;
   new_y := simp reval algebraic(sub(x=y,new_var))>>;
n1 := addsq(alpha,'(1 . 1));
temp1 := {'expt,y,prepsq n1};
temp2  := cadddr new_mellin;
coeff := simp!* reval algebraic(temp1*temp2);
m := caar new_mellin;
n := cadar new_mellin;
p := caddar new_mellin;
q := car cdddar new_mellin;
old_num := cadr new_mellin;
old_denom := caddr new_mellin;
for i:=1 :n do
<< if old_num = nil then a1 := append(a1,{simp!* old_num })
   else <<  a1 := append(a1,{simp!* car old_num});
            old_num := cdr old_num>>;
>>;
for j:=1 :m do
<< if old_denom = nil then b1 := append(b1,{simp!*  old_denom })
   else <<  b1 := append(b1,{simp!* car old_denom});
            old_denom := cdr old_denom>>;
>>;
a2 := listsq old_num;
b2 := listsq old_denom;
if a1 = nil and a2 = nil then
    num := list({negsq alpha})
else if a2 = nil then num := list(append(a1,{negsq alpha}))
else
<< num := append(a1,{negsq alpha}); num := append({num},a2)>>;
if b1 = nil and b2 = nil then
    denom := list({subtrsq(negsq alpha,'(1 . 1))})
else if b2 = nil then
    denom := list(b1,subtrsq(negsq alpha,'(1 . 1)))
else
<< denom := list(b1,subtrsq(negsq alpha,'(1 . 1)));
   denom := append(denom,b2)>>;
v := gfmsq(num,denom,new_y);
if v = 'fail then return simp 'fail
else v := prepsq v;
if eqcar(v,'meijerg) then new_v := v else new_v := simp v;
return multsq(new_v,coeff);
end$

symbolic procedure reduce_var(u,v,var1);
begin scalar var,m,n,coef,alpha,beta,alpha1,alpha2,expt_flag,k,temp1,
            temp2,const,new_k;
var := car cddddr(v);
beta := 1;
if length var = 0 then return u . v
else
<< k := u; coef := cadddr v;
   for each i in var do
   << if listp i then
      << if car i = 'expt then
         << alpha := caddr i; expt_flag := 't>>
         else if car i = 'sqrt then
         << beta := 2; alpha := 1; expt_flag := 't>>
         else if car i = 'times then
         << temp1 := cadr i; temp2 := caddr i;
            if listp temp1 then
            << if  car temp1 = 'sqrt then
               << beta := 2; alpha1 := 1; expt_flag := 't>>
               else if car temp1 = 'expt and listp caddr temp1 then
                  << beta := cadr cdaddr temp1;
                     alpha1 := car cdaddr temp1;
                     expt_flag := 't>>;
            >>;
            if listp temp2 and car temp2 = 'expt then
            << alpha2 := caddr temp2; expt_flag := 't>>;
            if alpha1 neq 'nil then
     alpha := reval algebraic(alpha1 + beta*alpha2)
            else alpha := alpha2;
         >>;
      >>
      else
      << if i = 'expt then << alpha := caddr var; expt_flag := 't>>;
      >>;
   >>;
   if expt_flag = nil then return u . v
   else
   << if listp alpha then << m := cadr alpha; n := caddr alpha;
                             n := reval algebraic(beta*n)>>
      else << m := alpha; n := beta>>;
      const := reval algebraic(sub(var1=1,var));
      const := reval algebraic(1/(const^(n/m)));
      new_k := reval algebraic(((k + 1)*n - m)/m);
      coef := reval algebraic((n/m)*coef*(const)^(k+1));
      var := reval algebraic(var^(n/m));
      return {new_k,car v,cadr v, caddr v,coef,var}>>;
>>;
end$

endpatch;


patch dipoly;

% 27 Feb 96.

symbolic procedure bcfi a;
   (if u<0 then current!-modulus+u else u)
    where u=remainder(a,current!-modulus);

endpatch;


% Excalc declarations.

fluid '(fancy!-pos!* fancy!-line!*);

global '(indxl!* keepl!* detm!* basisforml!*);

global '(basisvectorl!* dimex!* metricd!* metricu!*);

symbolic macro procedure fancy!-level u;
 % unwind-protect for special output functions.
  {'prog,'(pos fl w),
      '(setq pos fancy!-pos!*),
      '(setq fl fancy!-line!*),
      {'setq,'w,cadr u},
      '(cond ((eq w 'failed)
              (setq fancy!-line!* fl)
              (setq fancy!-pos!* pos))),
       '(return w)};

symbolic smacro procedure lowerind u; list('minus,u);

symbolic smacro procedure wedgeordp(u,v); worderp(u,v);

symbolic smacro procedure !*k2pf u; u .* (1 ./ 1) .+ nil;

patch excalc;

% 18 Dec 95.

symbolic procedure putform(u,v);
   if atom u then <<if flagp(u,'reserved)
                       then <<remflag({u},'reserved);
                              lpri {"***Warning: reserved variable",
                                    u,"declared exterior form"}>>;
                    put(u := !*a2k u,'fdegree,list !*q2f simp v);
                            put(u,'clearfn,'clearfdegree)>>
    else begin scalar x,y; integer n;
           n := length cdr u;
           if (x := get(car u,'ifdegree)) and (y := assoc(n,x))
              then x := delete(y,x);
           put(car u,'ifdegree,if x then (n . !*q2f simp v) . x
                                else list(n . !*q2f simp v));
           x := car u;
           flag(list x,'indexvar); 
           put(x,'rtype,'indexed!-form);
           put(x,'simpfn,'simpindexvar);
           put(x,'partitfn,'partitindexvar);
           put(x,'evalargfn,'revalindl);
           flag(list x,'full);
           put(x,'prifn,'indvarprt);
           put(x,'fancy!-pprifn,'xindvarprt);
           remflag('(minus),'intfn);
           if null numr simp v then flag(list x,'covariant)
         end;

% 19 Dec 95.

symbolic procedure partdfpow(u,v);
   begin scalar x,z; integer n;
       n := cdr u;
       u := car u;
       z := nil ./ 1;
       if u eq v then z := 1 ./ 1
        else if atomf u then
                if x := assoc(u,keepl!*) then
                       begin scalar alglist!*;
                         z := partdfsq(simp0 cdr x,v)
                       end
                 else if ndepends(if x := get(lid u,'varlist)
                                     then lid u . cdr x
                                   else lid u,v)
                      then z := mksq(list('partdf,u,v),1)
                 else return nil ./ 1
        else if sfp u then z := partdff(u,v)
        else if car u eq '!*sq then z := partdfsq(cadr u,v)
        else if x := get(car u,dfn_prop u) then
                 for each j in
                    for each k in cdr u collect partdfsq(simp k,v)
                  do <<if numr j then
                        z := addsq(multsq(j,simp
                                     subla(pair(caar x,cdr u),cdar x)),
                                   z);
                 x := cdr x>>
        else if car u eq 'partdf then
                if ndepends(lid cadr u,v) then
                   if x := partdfsplit(u,v,get('partdf,'kvalue)) then
                       <<z := mksq(car x,1);
                         for each j in cdr x do
                             z := partdfsq(z,j)>>
                    else
                       <<z := 'partdf . cadr u . ordn(v . cddr u);
                         z := if x := opmtch z then simp x
                               else mksq(z,1)>>
                 else return nil ./ 1;
       if x := atsoc(u,wtl!*) then z := multpq('k!* to (-cdr x),z);
       return if n=1 then z else multsq(!*t2q((u to (n-1)) .* n),z)
   end;


symbolic procedure partdfsplit(u,v,k);
   if null k then nil
   else if cadr caar k eq cadr u and
           v memq cddr caar k and
           sublistp(delete(v,cddr caar k),cddr u) then 
      caar k . listdiff(cddr u,delete(v,cddr caar k))
   else partdfsplit(u,v,cdr k);


symbolic procedure sublistp(x,y);
   null x or car x member y and sublistp(cdr x,delete(car x,y));


symbolic procedure listdiff(x,y);
   if null y then x
   else if null x then nil
   else listdiff(delete(car y,x),cdr y);

%  5 Mar 96.

symbolic procedure xindvarprt(l,p);
  fancy!-level
  ( if not(get('expt,'infix)>p) then
    fancy!-in!-brackets(
       {'xindvarprt,mkquote l,0}, '!(,'!))
    else
   begin scalar w,x,b,s;
     w:=fancy!-prefix!-operator car l;
     if w eq 'failed then return w;
     l := xindxlfix cdr l;
     while l and w neq 'failed do
     <<if b then fancy!-prin2!*("{}",0);
       b := t;
       if atom car l
          then (if s eq '!^
                  then x := car l . x
                else <<if s then
                   <<w := fancy!-print!-indexlist1(reversip x,s,nil);
                     fancy!-prin2!*("{}",0)>>;
                   x := {car l};
                   s := '!^>>)
        else (if s eq '!_
                  then x := cadar l . x
                else <<if s then
                   <<w := fancy!-print!-indexlist1(reversip x,s,nil);
                     fancy!-prin2!*("{}",0)>>;
                   x := {cadar l};
                   s := '!_>>);
       l := cdr l>>;
       w := fancy!-print!-indexlist1(reversip x,s,nil);
     return w
   end);

symbolic procedure xindxlfix u;
   if null u then nil
   else if atom car u then xindxfix car u . xindxlfix cdr u
   else {'minus,xindxfix cadar u} . xindxlfix cdr u;

symbolic procedure xindxfix x;
   begin scalar xx;
   xx := explode x;
   while xx and car xx = '!! do xx := cdr xx;
   return if xx and numberp(xx := compress xx) then xx
          else x;
   end;

symbolic procedure !*num2id u;
   if u<10 then intern cdr assoc(u,
             '((0 . !0) (1 . !1) (2 . !2) (3 . !3) (4 . !4)
               (5 . !5) (6 . !6) (7 . !7) (8 . !8) (9 . !9)))
    else intern compress('!! . explode u);

% 21 Apr 96.

symbolic procedure indexrange u;
   begin
   if null eqcar(car u,'equal)
      then indxl!* := mkindxl u
    else for each j in u do
           begin scalar names,range;
             names := cadr j;
             range := caddr j;
             if atom names then names := list names
              else if null(car names eq 'list)
                      then rerror(excalc,11,
                                  "badly formed indexrangelist")
                    else names := cdr names;
             if atom range then range := list range
              else if null(car range eq 'list)
                      then rerror(excalc,11,
                                  "badly formed indexrangelist")
                    else range := cdr range;
              range := mkindxl range;
              indxl!* := reverse union(range,reverse indxl!*);
              for each k in names do
                  put(k,'indexrange,range)
            end
    end;
    
% 22 Apr 96.

symbolic procedure indexvarordp(u,v);
   if not(car u eq car v) or (u memq kord!*) or (v memq kord!*) then
      ordop(u,v)
   else ((if boundindp(x,indxl!*) then 
      if boundindp(y,indxl!*) then indordlp(cdr u,cdr v)
      else t
   else if boundindp(y,indxl!*) then nil
   else ordop(u,v))
      where x = flatindxl cdr u, y = flatindxl cdr v);

%  9 Jan 98.

symbolic procedure dual0 u;
   (multpfsq(mkwedge ('wedge . basisforml!*),
             simpexpt list(mk!*sq(absf!* numr x ./
                                  absf!* denr x),'(quotient 1 2))))
    where x = simp!* detm!*;
    
% 24 Jan 98.

symbolic procedure revalind u;
   begin scalar x,y,alglist!*,dmode!*;
     x := subfg!*;
     subfg!* := nil;
     u := subst('!0,0,u);
     % The above line is used to avoid the simplifaction of -0 to 0.
     y := prepsq simp u;
     subfg!* := x;
     return y
   end;
   
% 19 Feb 98.

symbolic procedure cofram(u,v);
   begin scalar alglist!*;
     rmsubs();
     u := for each j in u collect
              if car j eq 'equal then cdr j else list j;
     putform(caar u,1);
     basisforml!* := for each j in u collect !*a2k car j;
     indxl!* := for each j in basisforml!* collect cadr j;
     dimex!* := length u;
     basisvectorl!* := nil;
     if null v then
          metricd!* := nlist(1,dimex!*)
      else if car v eq 'signature
              then if dimex!* neq length cdr v
              then rerror(excalc,12,     
              "Dimension of coframe and metric are inconsistent.")
            else metricd!* := for each j in cdr v collect aeval j;
     if null v or (car v eq 'signature) then
       <<detm!* := simp car metricd!*;
         for each j in cdr metricd!* do
             detm!* := multsq(simp j,detm!*);
           detm!* := mk!*sq detm!*;
           metricu!* := metricd!*:= pair(indxl!*,for each j in
                           pair(indxl!*,metricd!*) collect list j)>>
      else mkmetric v;
     if flagp('partdf,'noxpnd) then remflag('(partdf),'noxpnd);
     putform('eps . indxl!*,0);
     put('eps,'indxsymmetries,
         list list('lambda,'(indl),list('tot!-asym!-indp,
                   list('evlis,mkquote for j := 1:dimex!* collect
                                        list('nth,'indl,j)))));
     put('eps,'indxsymmetrize,
         list list('lambda,'(indl),list('asymmetrize!-inds,
                   mkquote(for j := 1: dimex!* collect j),'indl)));
     flag('(eps),'covariant);
     setk('eps . for each j in indxl!* collect lowerind j,1);
     if null cdar u then return;
     keepl!* := append(for each j in u collect
                         !*a2k car j . cadr j,keepl!*);
     coframe1 for each j in u collect cadr j
  end;

% 31 Jul 98.

symbolic procedure wedgek2(u,v,w);
   if u eq car v and null eqcar(u,'wedge)
      then if fixp deg!*form u and oddp deg!*form u then nil
            else multpfsq(wedgef(u . v),mksgnsq w)
    else if eqcar(car v,'wedge) then wedgek2(u,cdar v,w)
    else if eqcar(u,'wedge)
            then multpfsq(wedgewedge(cdr u,v),mksgnsq w)
    else if wedgeordp(u,car v)
            then multpfsq(wedgef(u . v),mksgnsq w)
    else if cdr v
            then wedgepf2(!*k2pf car v,
                          wedgek2(u,cdr v,addf(w,multf(deg!*form u,
                                                   deg!*form car v))))
    else multpfsq(wedgef list(car v,u),
                  mksgnsq addf(w,multf(deg!*form u,deg!*form car v)));

endpatch;


patch factor;

% 22 Feb 97.

symbolic procedure pfactor(q,p);
   begin scalar user!-prime,current!-modulus,modulus!/2,r,x;
    if not numberp p then typerr(p,"number")
     else if not primep p then typerr(p,"prime")
     else if p>largest!-small!-modulus
      then rederr {p,"too large a modulus for factorization"};
    user!-prime:=p;
    set!-modulus p;
    if domainp q or null reduce!-mod!-p lc q then
       prin2t "*** Degenerate case in modular factorization";
    if not (length variables!-in!-form q=1) then
       return fctrfkronm q;
    r:=reduce!-mod!-p q;
    x := lnc r;
    r :=monic!-mod!-p r;
    r:=errorset!*(list('factor!-form!-mod!-p,mkquote r),t);
    if not errorp r
      then return x . for each j in car r
                          collect mod!-adjust car j . cdr j;
    prin2t "****** FACTORIZATION FAILED******";
    return list(1,prepf q)
  end;

symbolic procedure mod!-adjust u;
   % Make sure any modular numbers in u are in the right range.
   if null !*balanced_mod then u else mod!-adjust1 u;

symbolic procedure mod!-adjust1 u;
   if domainp u
     then if fixp u then !*modular2f u
           else if eqcar(u,'!:mod!:) then !*modular2f cdr u
           else typerr(u,"modular number")
    else lpow u .* mod!-adjust1 lc u .+ mod!-adjust1 red u;

endpatch;


% Groebner declarations.

fluid '(!*trgroeb intvdpvars!*);

patch groebner;

% 30 Aug 95.

symbolic procedure vdpvordopt (w,vars);
  begin; scalar c;
        vars := sort(vars,'ordop);
        c := for each x in vars collect x . 0 . 0;
        for each poly in w do vdpvordopt1 (poly,vars,c);
        c := sort(c,function vdpvordopt2);
        intvdpvars!* := for each v in c collect car v;
        vars := vdpvordopt31 intvdpvars!*;
        if !*trgroeb then
        <<prin2 "optimized sequence of kernels: "; prin2t vars>>;
        return (for each poly in w collect reorder poly) . vars;
  end;
 
symbolic procedure vdpvordopt31 u;
   begin scalar v,y;
   if null u then return nil;
   v := foreach x in u join
        << y := assoc(x,depl!*);
           if null y or null xnp(cdr y,u) then {x} >>;
   return nconc(vdpvordopt31 setdiff(u,v),v);
   end;

endpatch;

patch hephys;

% 2 Jan 98.

remflag('(nospur),'flagop);

symbolic procedure nospur u; <<!*nospurp := t; flag(u,'nospur)>>;

endpatch;

% Int declarations.

fluid '(!*trint intvar lorder power!-list!* lhs!* rhs!* ulist zlist);

fluid '(!*galois !*hyperbolic !*pvar listofnewsqrts);

fluid '(!*algint !*purerisch !*trdint gaussiani sqrt!-places!-alist);

global '(!*number!* !*statistics);

symbolic smacro procedure argof u; cadr u;

patch int;

% 20 Nov 95.

symbolic procedure exportan dl;
    if atom dl then nil
     else begin
        if eq(car dl,'tan) then return t;
   nxt: if not eq(car dl,'expt) then return nil;
        dl:=cadr dl;
        if atom dl or not smember(intvar,dl) then return t;
        go to nxt
    end;

%  1 Dec 95.

symbolic procedure hfaglk(k,x);
   begin
      scalar kt;
      if atom k or not member(x,flatten(cdr(k))) then return !*k2q k;
      k := car(k) . hfaglargs(cdr(k), x);
      if cadr k eq 'pi then return !*k2q k;
      kt := simp list('tan, list('quotient, cadr(k), 2));
      return if car(k) = 'sin
       then quotqq(multsq(!*int2qm(2),kt), addsq(!*int2qm(1),
                            exptsq(kt,2)))
      else if car(k) = 'cos
       then quotqq(!*subtrq(!*int2qm(1),exptsq(kt,2)),addsq(!*int2qm(1),
         exptsq(kt,2)))
      else if car(k) = 'tan
       then quotqq(multsq(!*int2qm(2),kt), !*subtrq(!*int2qm(1),
                            exptsq(kt,2)))
      else if car(k) = 'cot
       then quotqq(!*subtrq(!*int2qm(1),
                   exptsq(kt,2)),multsq(!*int2qm(2),kt))
      else if car(k) = 'sec
       then quotqq(addsq(!*int2qm(1), exptsq(kt,2)),
                   !*subtrq(!*int2qm(1),exptsq(kt,2)))
      else if car(k) = 'csc
       then quotqq(addsq(!*int2qm(1),exptsq(kt,2)),
                   multsq(!*int2qm(2),kt))
      else if car(k) = 'sinh then
        quotqq(!*subtrq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), multsq(!*int2qm(2),
                             !*p2q mksp('expt . ('e . cdr(k)),1)))
      else if car(k) = 'cosh then
        quotqq(addsq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), multsq(!*int2qm(2),
                             !*p2q mksp('expt . ('e . cdr(k)),1)))
      else if car(k) = 'tanh then
        quotqq(!*subtrq(!*p2q mksp('expt.('e. cdr k),2),
        !*int2qm(1)), addsq(!*p2q mksp ('expt.('e.cdr(k)),2),
        !*int2qm(1)))
      else if car(k) = 'coth then
        quotqq(addsq(!*p2q mksp('expt.('e.cdr(k)),2), !*int2qm(1)),
              !*subtrq(!*p2q mksp('expt.('e . cdr k),2),!*int2qm(1)))
      else if car(k) = 'acot then
        !*p2q mksp(list('atan, list('quotient, 1, cadr k)),1)
      else !*k2q(k);
   end;

%  5 Jan 96.

symbolic procedure solve!-for!-u(rhs!*,lhs!*,ulist);
   begin
   top:
      if null lhs!* then return ulist
       else begin scalar u,lpowlhs;
         lpowlhs := lpow lhs!*;
         begin scalar ll,m1,chge;
           ll:=maxorder(power!-list!*,zlist,0);
           m1:=lorder;
           while m1 do << if car ll < car m1 then
                   << chge:=t; rplaca(m1,car ll) >>;
               ll:=cdr ll; m1:=cdr m1 >>;
           if !*trint and chge then <<
              princ
           "Maximum order for undetermined coefficients is reduced to ";
              printc lorder >>
         end;
         u:=pickupu(rhs!*,lpow lhs!*,t);
         if null u then
         << if !*trint then <<
                printc "***** Equation for a constant to be solved:";
                printsf numr lc lhs!*;
                printc "    = 0";
                printc " ">>;
           if gausselimn(numr lc lhs!*,lt lhs!*) then <<
                    lhs!*:=squashconstants(red lhs!*); u := t >>
           else lhs!*:=red lhs!* >>
         else
         << ulist:=(car u .
              subs2q multsq(coefdf(lhs!*,lpowlhs),invsq cdr u)).ulist;
           if !*statistics then !*number!*:=!*number!*+1;
            if !*trint then <<
                printc "A coefficient of numerator has been determined";
                   prin2 "***** U"; prin2 car u; prin2t " =";
                   printsq multsq(coefdf(lhs!*,lpowlhs),invsq cdr u);
                   printc " ">>;
            lhs!*:=plusdf(lhs!*,
                   negdf multdfconst(cdar ulist,uterm(car u,rhs!*)))>>;
         if !*trint and u
           then <<printc "Terms remaining are:"; printdf lhs!*;
                  printc " ">>
      end;
      go to top
   end;

% 15 Feb 96.

symbolic procedure multdfconst(x,u);
   if null u or null numr x then nil
    else lpow u .* subs2q multsq(x,lc u) .+ multdfconst(x,red u);

% 11 Mar 96.

symbolic procedure simpint!* u;
   begin scalar x;
      return if (x := opmtch('int . u)) then simp x
              else simpiden('int!* . u)
   end;

% 3 May 96.

symbolic procedure int!-quadterm(pol,var);
   begin scalar a,b,c,discrim,kord,res,w;
      kord := setkorder(var . kord!*);
      c := reorder pol;
      if ldeg c neq 2
        then <<setkorder kord;
               rerror(int,5,"Invalid polynomial in int-quadterm")>>;
      a := lc c;
      c := red c;
      if not domainp c and mvar c = var and ldeg c = 1
        then <<b := lc c; c := red c>>;
      setkorder kord;
      discrim := powsubsf addf(multf(b,b),multd(-4,multf(a,c)));
      if null discrim then interr "discrim is zero in quadterm";
      w := rootxf!*(negf discrim,2);
      if not(w eq 'failed) then go to atancase;
      w := rootxf!*(discrim,2);
      if w eq 'failed then return list ('log . !*f2q pol);
      discrim := w;
      w := multpf(mksp(var,1),a);
      w := addf(multd(2,w),b);
      a := addf(w,discrim);
      b := addf(w,negf discrim);
      a := quotf(a,cdr comfac a);
      b := quotf(b,cdr comfac b);
      return ('log . !*f2q a) . ('log . !*f2q b) . res;
   atancase:
      res := ('log . !*f2q pol) . res;
      a := multpf(mksp(var,1),a);
      a := addf(b,multd(2,a));
      a := fquotf(a,w);
      return ('atan . a) . res
   end;

symbolic procedure rootxf!*(u,n);
   (if x eq 'failed or smemq('i,x) and not smemq('i,u)
      then (rootxf(u,n) where !*surds=nil)
     else x)
    where x=rootxf(u,n);

% 12 Sep 96.

symbolic procedure rootextractf v;
   if domainp v then v
    else begin scalar u,r,c,x,p;
      u := mvar v;  p := ldeg v;
      r := rootextractf red v;
      c := rootextractf lc v;
      if null c then return r
       else if atom u then return (lpow v .* c) .+ r
       else if car u eq 'sqrt
        or car u eq 'expt and eqcar(caddr u,'quotient)
           and car cdaddr u = 1 and numberp cadr cdaddr u
        then <<p := divide(p,if car u eq 'sqrt then 2
                              else cadr cdaddr u);
      if car p = 0 
        then return if null c then r else (lpow v .* c) .+ r
       else if numberp cadr u
        then <<c := multd(cadr u ** car p,c); p := cdr p>>
       else <<x := simpexpt list(cadr u,car p);
              if denr x = 1 then <<c := multf(numr x,c); p := cdr p>>
               else p := ldeg v>>>>;
      return if p=0 then addf(c,r)
              else if null c then r
              else ((u to p) .* c) .+ r
   end;

% 27 Mar 98.

symbolic procedure look_for_quad(integrand, var, zz);
if !*algint then nil
else begin
  if (car zz = 'sqrt and listp cadr zz and caadr zz = 'plus) or
     (car zz = 'expt and listp cadr zz and caadr zz = 'plus and
      listp caddr zz and car caddr zz = 'quotient
         and fixp caddr caddr zz)
   then <<
    zz := simp cadr zz;
    if (cdr zz = 1) then <<
        zz := cdr coeff1(prepsq zz, var, nil);
        if length zz = 2 then return begin
          scalar a, b;
          scalar nvar, res, ss;
          a := car zz; b := cadr zz;
          if (depends(a,var) or depends(b,var)) then return nil;
          nvar := gensym();
          if !*trint then <<
                prin2 "Linear shift suggested ";
                prin2 a; prin2 " "; prin2 b; terpri();
          >>;
          integrand := subsq(integrand,
                             list(var . list('quotient,
                                             list('difference,
                                                  list('expt,nvar,2),a),
                                                  b)));
          integrand := multsq(integrand,
                              simp list('quotient,list('times,nvar,2),
                                        b));
          if !*trint then <<
                prin2 "Integrand is transformed by substitution to ";
                printsq integrand;
                prin2 "using substitution "; prin2 var; prin2 " -> ";
                printsq simp list('quotient,
                                 list('difference,list('expt,nvar,2),a),
                                 b);
           >>;
           res := integratesq(integrand, nvar, nil, nil);
           ss := list(nvar . list('sqrt,list('plus,list('times,var,b),
                                  a)));
           res := subsq(car res, ss) .
                  subsq(multsq(cdr res, simp list('quotient,b,
                                                  list('times,nvar,2))), ss);
           return res;
        end
        else if length zz = 3 then return begin
          scalar a, b, c;
          a := car zz; b := cadr zz; c:= caddr zz;
          if (depends(a,var) or depends(b,var) or depends(c,var)) then
                return nil;
          a := simp list('difference, a,
                         list('times,b,b,
                         list('quotient,1,list('times,4,c))));
          if null numr a then return nil;
          b := simp list('quotient, b, list('times, 2, c));
          c := simp c;
          return
           if minusf numr c then <<
           if minusf numr a then  begin
                            scalar !*hyperbolic;
                            !*hyperbolic := t;
                            return
                                look_for_invhyp(integrand,nil,var,a,b,c)
                        end
            else                look_for_asin(integrand,var,a,b,c)>>
          else <<
            if minusf numr a then look_for_invhyp(integrand,t,var,a,b,c)
          else                  look_for_invhyp(integrand,nil,var,a,b,c)
          >>
        end
        else if length zz = 5 then return begin
          scalar a, b, c, d, e, nn, dd, mm;
          a := car zz; b := cadr zz; c:= caddr zz;
          d := cadddr zz; e := car cddddr zz;
          if not(b = 0) or not(d = 0) then return nil;
          if (depends(a,var) or depends(c,var)) or depends(e,var) then
                return nil;
          nn := numr integrand;  dd := denr integrand;
          if denr(mm :=quotsq(nn ./ 1, !*kk2q var)) = 1 and
             even_power(numr mm, var) and even_power(dd, var) then <<
              return sqrt_substitute(numr mm, dd, var);
          >>;
          if denr(mm :=quotsq(dd ./ 1, !*kk2q var)) = 1 and
             even_power(nn, var) and even_power(numr mm, var) then <<
              return sqrt_substitute(nn, multf(dd,!*kk2f var), var);
          >>;
          return nil;
        end;
  >>>>;
  return nil;
end;

symbolic procedure look_for_invhyp(integrand, do_acosh, var, a, b, c);
begin
    scalar newvar, res, ss, sqmn, onemth, m, n, realdom;
    m := prepsq a;
    n := prepsq c;
    b := prepsq b;
    newvar := gensym();
    if do_acosh then <<
      sqmn := prepsq apply1(get('sqrt, 'simpfn),
                            list list('quotient, n, list('minus, m)));
      onemth := list('sinh, newvar);
      ss := list('cosh, newvar)
    >>
    else <<
      sqmn:= prepsq apply1(get('sqrt,'simpfn),list list('quotient,n,m));
      onemth := list('cosh, newvar);
      ss := list('sinh, newvar)
    >>;
    powlis!* := list(ss, 2, '(nil . t),
                     list((if do_acosh then 'plus else 'difference),
                          list('expt, onemth, 2),1),
                     nil) .
                powlis!*;
    integrand := subs2q
        multsq(subsq(integrand,
               list(var . list('difference,list('quotient,ss,sqmn),b))),
               quotsq(onemth := simp onemth, simp sqmn));
    if !*trint then <<
        prin2 "Integrand is transformed by substitution to ";
        printsq integrand;
        prin2 "using substitution "; prin2 var; prin2 " -> ";
        printsq simp list('difference, list('quotient, ss, sqmn), b);
    >>;
    realdom := not smember('(sqrt -1),integrand);
    res := integratesq(integrand, newvar, nil, nil);
    powlis!* := cdr powlis!*;
    if !*hyperbolic then <<
      ss := list(if do_acosh then 'acosh else 'asinh,
                 list('times,list('plus,var,b), sqmn));
    >>
    else <<
      ss := list('times,list('plus,var,b), sqmn);
      ss := if do_acosh then
        subst(ss,'ss,
              '(log (plus ss (sqrt (difference (times ss ss) 1)))))
      else
        subst(ss,'ss,'(log (plus ss (sqrt (plus (times ss ss) 1)))))
    >>;
    ss := list(newvar . ss);
    res := sqrt2top subsq(car res, ss) .
           sqrt2top subsq(quotsq(cdr res, onemth), ss);
    if !*trint then <<
        printc "Transforming back...";
        printsq car res;
        prin2 " plus a bad part of ";
        printsq cdr res
    >>;
    if (car res = '(nil . 1)) then return nil;
    if realdom and smember('(sqrt -1),res) then <<
        if !*trint then print "Wrong sheet"; return nil;
    >>;
    return res
end;

%  6 Apr 98.

symbolic procedure mknewsqrt u;
   begin scalar v,w;
     if not !*galois then go to new;
     v:=addf(!*p2f mksp(!*pvar,2),negf !*q2f tidysqrt simp u);
     w:=errorset!*(list('afactor,mkquote v,mkquote !*pvar),t);
     if atom w then go to new
       else w:=car w;
     if cdr w then go to notnew;
   new:
     w := mksqrt reval u;
     listofnewsqrts:=w . listofnewsqrts;
     return !*kk2f w;
   notnew:
     w:=car w;
     v:=stt(w,!*pvar);
     if car v neq 1 then errach list("Error in mknewsqrt: ",v);
     w:=addf(w,multf(cdr v,(mksp(!*pvar,car v) .* -1) .+nil));
     v:=sqrt2top(w ./ cdr v);
     w:=quotf(numr v,denr v);
     if null w
       then begin scalar oldprop;
               oldprop := get('sqrt,'simpfn);
               put('sqrt,'simpfn,'simpsqrt);
               v := simp prepsq v;
               put('sqrt,'simpfn,oldprop);
               if denr v = 1 then w := numr v
            end;
     if null w then errach list("Division failure in mknewsqrt",u);
     return w
  end;

% 23 Jul 98.

symbolic procedure !*multf(u,v);
  begin scalar x,y;
      if null u or null v then return nil
      else if u=1 then return squashsqrt v
        else if v=1 then return squashsqrt u
        else if domainp u then return multd(u,squashsqrt v)
        else if domainp v then return multd(v,squashsqrt u)
        else if noncomfp u or noncomfp v then return multf(u,v);
      x:=mvar u;
      y:=mvar v;
      if x eq y then go to c else if ordop(x,y) then go to b;
      x:=!*multf(u,lc v);
      y:=!*multf(u,red v);
      return if null x then y
              else if not domainp lc v
                and mvar u eq mvar lc v
                and not atom mvar u
                and car mvar u memq '(expt sqrt)
               then addf(!*multf(x,!*p2f lpow v),y)
              else makeupsf(lpow v,x,y);
  b:  x:=!*multf(lc u,v);
      y:=!*multf(red u,v);
      return if null x then y
              else if not domainp lc u
                and mvar lc u eq mvar v
                and not atom mvar v
                and car mvar v memq '(expt sqrt)
               then addf(!*multf(!*p2f lpow u,x),y)
              else makeupsf(lpow u,x,y);
  c:  y:=addf(!*multf(list lt u,red v),!*multf(red u,v));
      if eqcar(x,'sqrt)
        then return addf(squashsqrt y,!*multfsqrt(x,
                        !*multf(lc u,lc v),ldeg u + ldeg v))
        else if eqcar(x,'expt) and prefix!-rational!-numberp caddr x
          then return addf(squashsqrt y,!*multfexpt(x,
                        !*multf(lc u,lc v),ldeg u + ldeg v));
      x:=mkspm(x,ldeg u + ldeg v);
      return if null x or null (u:=!*multf(lc u,lc v))
               then y
               else addf(multpf(x,u),y)
    end;

% 23 Jul 98.

symbolic procedure simpint u;
   if atom u or null cdr u or cddr u and (null cdddr u or cddddr u)
     then rerror(int,1,"Improper number of arguments to INT")
    else if cddr u then simpdint u
    else begin scalar ans,dmod,expression,variable,loglist,oldvarstack,
                 !*intflag!*,!*purerisch,intvar,listofnewsqrts,
                 listofallsqrts,sqrtfn,sqrt!-intvar,sqrt!-places!-alist,
                 basic!-listofallsqrts,basic!-listofnewsqrts,coefft,w;
    !*intflag!* := t;
    variable := !*a2k cadr u;
    if not(idp variable or pairp variable and numlistp cdr variable)
      then typerr(variable,"integration variable");
    intvar := variable;
    w := cddr u;
    if w then rerror(int,3,"Too many arguments to INT");
    listofnewsqrts:= list mvar gaussiani;
    listofallsqrts:= list (argof mvar gaussiani . gaussiani);
    sqrtfn := get('sqrt,'simpfn);
    put('sqrt,'simpfn,'proper!-simpsqrt);
    if dmode!* then onoff(dmod := get(dmode!*,'dname),nil)
       where !*msg := nil;
    begin scalar dmode!*,!*exp,!*gcd,!*keepsqrts,!*limitedfactors,!*mcd,
                 !*rationalize,!*structure,!*uncached,kord!*,
                 ans1,denexp,badbit,nexp,oneterm,!*precise;
       !*keepsqrts := !*limitedfactors := t;
       !*exp := !*gcd := !*mcd := !*structure := !*uncached := t;
       dmode!* := nil;
       if !*algint
         then <<
            !*precise := t;
            sqrt!-intvar:=!*q2f simpsqrti variable;
            if (red sqrt!-intvar) or (lc sqrt!-intvar neq 1)
                or (ldeg sqrt!-intvar neq 1)
              then interr "Sqrt(x) not properly formed"
              else sqrt!-intvar:=mvar sqrt!-intvar;
            basic!-listofallsqrts:=listofallsqrts;
            basic!-listofnewsqrts:=listofnewsqrts;
            sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,
                         list(variable . variable))>>;
       coefft := (1 ./ 1);
       expression := int!-simp car u;
       denexp := 1 ./ denr expression;
       nexp := numr expression;
       while not atom nexp and null cdr nexp and
          not depends(mvar nexp,variable) do
              <<coefft := multsq(coefft,(((caar nexp) . 1) . nil) ./ 1);
                nexp := lc nexp>>;
       ans1 := nil;
       while nexp do begin
           scalar x,zv,tmp;
           if atom nexp then << x:=!*f2q nexp; nexp:=nil >>
           else << x:=!*t2q car nexp; nexp:=cdr nexp >>;
           x := multsq(x,denexp);
           zv := findzvars(getvariables x,list variable,variable,nil);
           begin scalar oldzlist;
               while oldzlist neq zv do <<
                    oldzlist := zv;
                    foreach zz in oldzlist do
                    zv:=findzvars(distexp(pseudodiff(zz,variable)),
                                  zv,variable,t)>>;
               zv := sort(zv, function ordp)
           end;
           tmp := ans1;
           while tmp do
              <<if zv=caar tmp
                  then <<rplacd(car tmp,addsq(cdar tmp,x));
                         tmp := nil; zv := nil>>
                 else tmp := cdr tmp>>;
           if zv then ans1 := (zv . x) . ans1
       end;
       if length ans1 = 1 then oneterm := t;
       nexp := ans1;
       ans := nil ./ 1;
       badbit:=nil ./ 1;
       while nexp do
        <<u := cdar nexp;
          if !*trdint
            then <<princ "Integrate"; printsq u;
                   princ "with Zvars "; print caar nexp>>;
          ans1 := errorset!*(list('integratesq,mkquote u,
                             mkquote variable,mkquote loglist,
                             mkquote caar nexp),
                             !*backtrace);
          nexp := cdr nexp;
          if errorp ans1 then badbit := addsq(badbit,u)
           else <<ans := addsq(caar ans1, ans);
                  badbit:=addsq(cdar ans1,badbit)>>>>;
       if !*trdint
         then <<prin2 "Partial answer="; printsq ans;
                prin2 "To do="; printsq badbit>>;
       if badbit neq '(nil . 1)
         then <<setkorder nil;
                badbit := reordsq badbit;
                ans := reordsq ans;
                coefft := reordsq coefft;
          if !*trdint then <<princ "Retrying..."; printsq badbit>>;
          if oneterm and ans = '(nil . 1) then ans1 := nil
            else ans1 := errorset!*(list('integratesq,mkquote badbit,
                                  mkquote variable,mkquote loglist,nil),
                                  !*backtrace);
          if null ans1 or errorp ans1
            then ans := addsq(ans,simpint1(badbit . variable . w))
           else <<ans := addsq(ans,caar ans1);
                  if cdar ans1 neq '(nil . 1)
                    then ans := addsq(ans,
                                    simpint1(cdar ans1 . variable . w))
                >>>>;
    end;
    ans := multsq(coefft,ans);
   if !*trdint then << printc "Resimp and all that"; printsq ans >>;
    put('int,'simpfn,'simpiden);
    put('sqrt,'simpfn,sqrtfn);
    if dmod then onoff(dmod,t) where !*msg := nil;
    oldvarstack := varstack!*;
    varstack!* := nil;
    ans := errorset!*(list('resimp,mkquote ans),t);
    put('int,'simpfn,'simpint);
    varstack!* := oldvarstack;
    return if errorp ans then error1() else car ans
   end;

endpatch;


patch mathpr;

% 17 Feb 96.

symbolic procedure fvarpri(u,v,w);
   begin integer scountr,llength,nchars; scalar explis,fvar,svar;
        fortlang!* := reval fort_lang;
        if not(fortlang!* memq '(fort c)) then
           typerr(fortlang!*,"target language");
        if not posintegerp card_no
          then typerr(card_no,"FORTRAN card number");
        if not posintegerp fort_width
          then typerr(fort_width,"FORTRAN line width");
        llength := linelength fort_width;
        if stringp u
          then return <<fprin2!* u;
                        if w eq 'only then fterpri(t);
                        linelength llength>>;
        if eqcar(u,'!*sq) then u := prepsq!* sqhorner!* cadr u;
        scountr := 0;
        nchars := if fortlang!* = 'c then 999999
            else ((linelength nil-spare!*)-12)*card_no;
        svar := varnam!*;
        fvar := if null v then (if fortlang!*='fort then svar else nil)
                 else car v;
        if posn!*=0 and w then fortpri(fvar,u,w)
         else fortpri(nil,u,w);
        linelength llength
   end;

% 28 Apr 96.

symbolic procedure xprinf(u,v,w);
   begin
      while not domainp u do <<xprint(lt u,v); u := red u; v := t>>;
      if null u then return nil
       else if minusf u then <<oprin 'minus; u := !:minus u>>
       else if v then oprin 'plus;
      if atom u then prin2!* u else maprin u
   end;

symbolic procedure xprint(u,flg);
   begin scalar v,w;
      v := tc u;
      u := tpow u;
      if (w := kernlp v) and w neq 1
        then <<v := quotf(v,w);
               if minusf w
                 then <<oprin 'minus; w := !:minus w; flg := nil>>>>;
      if flg then oprin 'plus;
      if w and w neq 1 then <<prin2!* w; oprin 'times>>;
      xprinp u;
      if v neq 1
        then <<oprin 'times;
               if red v then prin2!* "(";
               xprinf(v,nil,nil);
               if red v then prin2!* ")">>
   end;

symbolic procedure xprinp u;
   begin
      if atom car u then prin2!* car u
       else if not atom caar u or caar u eq '!*sq then <<
          prin2!* "(";
          if not atom caar u then xprinf(car u,nil,nil)
           else sqprint cadar u;
          prin2!* ")" >>
       else if caar u eq 'plus then maprint(car u,100)
       else maprin car u;
      if (u := cdr u)=1 then return nil
       else if !*nat and !*eraise
        then <<ycoord!* := ycoord!*+1;
               if ycoord!*>ymax!* then ymax!* := ycoord!*>>
       else prin2!* get('expt,'prtch);
      prin2!* if numberp u and minusp u then list u else u;
      if !*nat and !*eraise
        then <<ycoord!* := ycoord!*-1;
               if ymin!*>ycoord!* then ymin!* := ycoord!*>>
   end;

% 18 Jan 98.

symbolic procedure evalvars u;
   if null u then nil
    else if atom car u or flagp(caar u,'intfn)
     then car u . evalvars cdr u
    else (caar u . revlis cdar u) . evalvars cdr u;

endpatch;


% Matrix declarations.

fluid '(bareiss!-step!-size!*);

global '(assumptions requirements);

patch matrix;

% 19 Feb 96, 27 Jan 98.

symbolic procedure bareiss!-det u;
   begin scalar nu,bu,n,ok,temp,v,!*exp;
   !*exp := t;
   nu := matsm car u;
   n := length nu;
   for each x in nu do
      if length x neq n then rederr "Non square matrix";
   if n=1 then return caar nu;
   if asymplis!* or wtl!* then
    <<temp := asymplis!* . wtl!*;
      asymplis!* := wtl!* := nil>>;
   nu := normmat nu;
   v := for i:=1:n collect intern gensym();
   ok := setkorder append(v,kord!*);
   car nu := foreach r in car nu collect prsum(v,r);
   begin scalar powlis,powlis1;
      powlis := powlis!*; powlis!* := nil;
      powlis1 := powlis1!*; powlis1!* := nil;
      bu := cdr sparse_bareiss(car nu,v,bareiss!-step!-size!*);
      powlis!* := powlis; powlis1!* := powlis1;
   end;
   bu := if length bu = n then (lc car bu ./ cdr nu) else (nil ./ 1);
   setkorder ok;
   if temp then <<asymplis!* := car temp; wtl!* := cdr temp>>;
   return resimp bu
   end;

% 17 Jul 96.

symbolic procedure sparse_bareiss(u,v,k);
   begin scalar p,d,w,pivs,s;
   d := 1;
   u := foreach f in u join if f then {!*sf2ex(f,v)};
   while p := choose_pivot_rows(u,v,k,d) do
      begin
      u := car p; v := cadr p;
      p := cddr p;
      pivs := lpow car p;
      u := foreach r in u join
              begin
              r := splitup(r,v);
              r := extadd(extmult(cadr r,car p),extmult(car r,cadr p));
              if null (r := subs2chkex r) then return nil;
              r := innprodpex(pivs,quotexf!*(r,d));
              if not evenp length pivs then r := negex r;
              return {r};
              end;
      d := lc car p;
      assumptions := 'list . mk!*sq !*f2q d .
                            (pairp assumptions and cdr assumptions);
      p := extadd(car p,cadr p);
      s := evenp length pivs;
      foreach x in pivs do
         w := if (s := not s) then innprodpex(delete(x,pivs),p) . w
              else negex innprodpex(delete(x,pivs),p) . w;
      end;
   foreach f in u do
      requirements := 'list . mk!*sq !*f2q !*ex2sf f .
                          (pairp requirements and cdr requirements);
   return if u then 'inconsistent . nil
          else t . foreach f in w collect !*ex2sf f;
   end;

symbolic procedure choose_pivot_rows(u,v,k,d);
   if null u or null v then nil else
   begin scalar w,s,ss,p,x,y,rows,pivots;
   w := u;
   for i:=1:k do if v then v := cdr v;
   while k neq 0 do
      if null u then
         if null v or null w or pivots then k := 0
         else
         << for i:=1:k do if v then v := cdr v; s := nil; u := w>>
      else if car(x := splitup(car u,v)) and
              (y := if null pivots then car x
                    else subs2chkex extmult(car x,car pivots)) then
         begin
         rows := x . rows;
         pivots := (if null pivots then y else quotexf!*(y,d)) . pivots;
         if s then ss := not ss;
         w := delete(car u,w); u := cdr u; k := k - 1;
         end
      else <<u := cdr u; s := not s>>;
   if null pivots then return;
   if remainder(length lpow car pivots,4) member {2,3} then
      ss := not ss;
   rows := reverse rows;
   pivots := reverse pivots;
   p := car rows;
   foreach r in cdr rows do
      p := {car(pivots := cdr pivots),
            quotexf!*(extadd(extmult(cadr r,car p),
                             extmult(car r,cadr p)),d)};
   return w . v . if ss then {negex car p,negex cadr p} else p;
   end;

%  2 Apr 97.

symbolic procedure simpdet u;
   begin scalar x,!*protfg;
      !*protfg := t;
      return if !*cramer or !*rounded or
                errorp(x := errorset({'bareiss!-det,mkquote u},nil,nil))
               then detq matsm carx(u,'det)
              else car x
   end;

symbolic procedure quotexf!*(u,v);
   if null u then nil
   else lpow u .* quotfexf!*1(lc u,v) .+ quotexf!*(red u,v);

symbolic procedure quotfexf!*1(u,v);
   if null u then nil
    else (if x then x
           else (if denr y = 1 then numr y
                  else rerror(matrix,11,"Bareiss division failure"))
                 where y=rationalizesq(u ./ v))
          where x=quotf(u,v);

endpatch;


patch misc;

% 27 Nov 95.

symbolic procedure simp!-prod u;
   begin scalar v,y,upper,lower,lower1,dif;
      y := cdr u;
      u := simp!* car u;
      if null numr u then return (1 ./ 1)
       else if atom y then return u;
      if not atom cdr y then <<
          lower := cadr y;
          lower1 := if numberp lower then lower - 1
                     else list('plus,lower,-1);
          upper := if not atom cddr y then caddr y else car y;
          dif := addsq(simp!* upper, negsq simp!* lower);
          if denr dif = 1 then
              if null numr dif
                then return subsq(u,list(!*a2k car y . upper))
                else if fixp numr dif then dif := numr dif
                else dif := nil
           else dif := nil;
          if dif and dif <= 0 then return 1 ./ 1;
          if atom cddr y then upper := nil>>;
      v := !*a2k car y;
      return simp!-prod1(u,v,y,upper,lower,lower1,dif)
   end;

% 21 Feb 97.

symbolic procedure pf(u,var);
   begin scalar !*exp,!*gcd,kord!*,!*limitedfactors,polypart,rfactor,
                u1,u2,u3,u4,var,x,xx,y;
      !*exp := !*gcd := t;
      xx := updkorder var;
      x := subs2 resimp simp!* u;
      u1 := denr x;
      if degr(u1,var) = 0 then <<setkorder xx; return list('list,u)>>;
      u2 := qremsq(!*f2q numr x,!*f2q u1,var);
      if caar u2 then polypart := car u2;
      rfactor := 1 ./ 1;
      u2 := cdr u2;
      u3 := fctrf u1;
      x := cdr u3;
      u3 := car u3;
      while not domainp u3 do
       <<if mvar u3 eq var then x := (!*k2f mvar u3 . ldeg u3) . x
          else <<u4 := !*p2f lpow u3;
                 rfactor := numr rfactor ./ multf(u4,denr rfactor);
                 u1 := quotf(u1,u4)>>;
         u3 := lc u3>>;
      if u3 neq 1 then <<rfactor := numr rfactor
                                       ./ multf(u3,denr rfactor);
                         u1 := quotf(u1,u3)>>;
      while length x>1 do
       <<u3 := exptf(caar x,cdar x);
         u1 := quotf(u1,u3);
         if degr(u3,var)=0
           then rfactor := numr rfactor ./ multf(u3,denr rfactor)
          else <<u4 := xeucl(u1,u3,var);
                 y := (multsq(remsq(multsq(car u4,u2),!*f2q u3,var),
                              rfactor) . car x)
                        . y;
                 u2 := multsq(cdr u4,u2)>>;
         x := cdr x>>;
      u3 := exptf(caar x,cdar x);
      if u2 = (nil ./ 1) then nil
       else if degr(u3,var)=0
        then rfactor := numr rfactor ./ multf(u3,denr rfactor)
       else y := (multsq(rfactor,remsq(u2,!*f2q u3,var)) . car x) . y;
      x := nil;
      for each j in y do
         if cddr j =1 then x := j . x
          else x := append(pfpower(car j,cadr j,cddr j,var),x);
      x := for each j in x
              collect list('quotient,prepsq!* car j,
                           if cddr j=1 then prepf cadr j
                            else list('expt,prepf cadr j,cddr j));
      if polypart then x := prepsq!* polypart . x;
      setkorder xx;
      return 'list . x
   end;

% 11 May 98.

symbolic procedure simplimit u;
   begin scalar fn,exprn,var,val,old,v,!*protfg;
     if length u neq 4
       then rerror(limit,1,
                   "Improper number of arguments to limit operator");
     fn:= car u; exprn := cadr u; var := !*a2k caddr u; val := cadddr u;
     !*protfg := t;
     old := get('cot,'opmtch);
     put('cot,'opmtch,
         '(((!~x) (nil . t) (quotient (cos !~x) (sin !~x)) nil)));
     v := errorset!*({'apply,mkquote fn,mkquote {exprn,var,val}},nil);
     put('cot,'opmtch,old);
     !*protfg := nil;
     return if errorp v or (v := car v) = aeval 'failed then mksq(u,1)
             else simp!* v
   end;

endpatch;


% Numeric declarations.

fluid '(!*noequiv);

global '(iterations!*);

symbolic macro procedure dmx!: u;
  subla('((plus2 . !:plus)(times2 . !:times)
          (quotient . !:!:quotient)
          (difference . !:difference)
          (minus . !:minus)
          (lessp . (lambda(a b)(!:minusp (!:difference a b))))
          (greaterp . (lambda(a b)(!:minusp (!:difference b a))))
          (abs . absf)),
         cadr u);

patch numeric;

%  9 Aug 97.

symbolic procedure intrduni(e,p,acc);
 dmx!:
  begin scalar lo,hi,x,u,eps,i,il,int;
     integer n,k;
    x := car p; p:= cdr p;
    lo := cadr x; hi := cddr x; x := car x;
    lo:=force!-to!-dm lo; hi:=force!-to!-dm hi;
    if hi=lo then return force!-to!-dm nil;
    il := list intrdmkinterval(e,x,
               (lo.intevaluate1(e,x,lo)),
               (hi.intevaluate1(e,x,hi)),1);
    int:=car lastpair car il;
  loop:
    k:=add1 k; n:=add1 n;
    if remainder(n,25)=0 then intrdmess(n,il);
    i:=car il; il:=cdr il; u:=intrdintersect(e,x,i);
    if null u then
        <<il:=i.il;
          intrdabortmsg(list car cadr i,list x,intcollecteps il);
           goto ready>>;
    for each q in u do il := intrdsortin(q,il);
    if k<5 then goto loop;
    int:=intcollectint il;
    k:=0; eps := intcollecteps il;
    if eps>(acc* abs int) then goto loop;
  ready:
    return intcollectint il;
  end;

symbolic procedure intrdmulti(e,p,acc);
 dmx!:
  begin scalar vars,u,eps,i,il,int;
     integer n,k,dim;
    if smemq('infinity,p) then
      rederr "no support for infinity in multivariate integrals";
    dim:=length p;
    il:=intrdmkinitcube(e,p);
    vars := car il; il:= cdr il;
  loop:
    k:=add1 k; n:=add1 n;
    if remainder(n,25)=0 then intrdmess(n,il);
    i:=car il; il:=cdr il; u:=intrdrefinecube(e,vars,i);
    if null u then
        <<il:=i.il;
          intrdabortmsg(car cadr i,vars,intcollecteps il);
           goto ready>>;
    for each q in u do il := intrdsortin(q,il);
    if k<5 then goto loop;
    int:=intcollectint il;
    k:=0; eps := intcollecteps il;
    if eps>(acc* abs int) then goto loop;
  ready:
    return intcollectint il;
  end;

symbolic procedure rdmineval u;
  begin scalar e,vars,x,y,z,oldmode,p,!*noequiv;
    oldmode:=steepdecedmode(nil,nil);
    u := for each x in u collect reval x;
    u := accuracycontrol(u,6,40);
    e :=car u; u :=cdr u;
    if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if eqcar(x,'equal) then
       <<z:=cadr x; y:=caddr x>> else <<z:=x; y:=random 100>>;
       vars:=z . vars; p := y . p>>;
    vars := reversip vars; p := reversip p;
    x := steepdeceval1(e,vars,p,'num_min);
    steepdecedmode(t,oldmode);
    return list('list, car x, 'list.
       for each p in pair(vars,cdr x) collect
          list('equal,car p,cdr p));
  end;

symbolic procedure steepdec2(f,grad,vars,acc,x,mode);
 dmx!:
  begin scalar e0,e00,e1,e2,a,a1,a1a1,a2,a2a2,x1,x2,g,h,dx,
      delta,limit,gold,gnorm,goldnorm,multi;
    integer count,k,n;
    n:=length grad; multi:=n>1; n:=10*n;
    e00 := e0 := evaluate(f,vars,x);
    a1 := 1;
  init:
    k:=0;
    g := for each v in grad collect -evaluate(v,vars,x);
    gnorm := normlist g; h:=g;
  loop:
    count := add1 count; k:=add1 k;
    if count>iterations!* then
    <<lprim "requested accuracy not reached within iteration limit";
      goto ready>>;
    a2 := nil;
   l1:
    x1 := list!+list(x, scal!*list(a1,h));
    e1 := evaluate(f,vars,x1);
    if e1>e0 then <<a2:=a1; x2:=x1; e2:=e1;
            a1 := a1/2; goto l1>>;
    if a2 then goto alph;
   l2:
    a2 := a1+a1;
    x2 := list!+list(x, scal!*list(a2,h));
    e2 := evaluate(f,vars,x2);
    if e2<e1 then <<a1:=a2; e1:=e2; goto l2>>;
   alph:
    if abs(e1-e2)<acc then goto ready;
    a1a1:=a1*a1; a2a2:=a2*a2;
    a:= (a1a1-a2a2)*e0 + a2a2*e1 - a1a1*e2 ;
    a:= a/((a1-a2)*e0 + a2*e1-a1*e2);
    a:= a/2;
    dx:=scal!*list(a,h); x:=list!+list(x, dx);
    e0 := evaluate(f,vars,x);
    if e0>e1 then
    <<dx:=scal!*list(a1-a ,h); x:=list!+list(x,dx);
      e0 := e1; dx:=scal!*list(a1,h)>>;
    delta:= normlist dx;
    steepdecprintpoint(count,x,delta,e0,gnorm);
    update!-precision list(delta,e0,gnorm);
    if k>n then goto init;
    gold := g; goldnorm:= gnorm;
    g := for each v in grad collect -evaluate(v,vars,x);
    gnorm := normlist g;
    if gnorm<limit then goto ready;
    h := if not multi then g else
        list!+list(g,scal!*list(gnorm/goldnorm,h));
    if mode='num_min and gnorm > acc or
       mode='root and e0 > acc then goto loop;
  ready:
    if mode='root and not(abs e0 < acc) then
     <<lprim "probably fallen into local minimum of f^2";
        return nil>>;
    return e0 . x;
  end;

endpatch;

% Ncpoly declarations.

fluid '(ncpi!-brackets!* ncpi!-comm!-rules!* ncpi!-name!-rules!*
        ncpi!-names!* !*ncg!-right);

flag('(ncpi!-brackets!* ncpi!-comm!-rules!* ncpi!-name!-rules!*),
     'share);

patch ncpoly;

% 15 Jun 96.

symbolic procedure ncpi!-setup u;
  begin scalar vars,al,b,b0,f,m,rs,rn,na,rh,lh,s,x,y,w,!*evallhseqp;
   if (w:=member('left,u)) or (w:=member('right,u)) then
   <<u:=delete(car w,u); !*ncg!-right:=car w='right>>;
   if length u > 2 then rederr "illegal number of arguments";
   if ncpi!-name!-rules!* then 
      algebraic clearrules ncpi!-comm!-rules!*,ncpi!-name!-rules!*;   
   u:=sublis(ncpi!-names!*,u);   
   for each x in cdr listeval(car u,nil) collect
   <<x:=reval x;  y:={'nc!*,mkid('!_,x)}; na:=(y.x).na;
     rn:={'replaceby,x,y}.rn; al:=(x.y).al;vars:=append(vars,{y})>>;
   ncpi!-names!*:=na;
   ncpi!-name!-rules!*:='list.rn;
   m:=for i:=1:length vars -1 join
     for j:=i+1:length vars collect nth(vars,i).nth(vars,j); 
   if cdr u then ncpi!-brackets!*:=listeval(cadr u,nil);
   if null ncpi!-brackets!* then
       rederr "commutator relations missing";
   for each b in cdr ncpi!-brackets!* do
   <<b0:=sublis(al,b);
     w:= eqcar(b0,'equal) and (lh:=cadr b0) and (rh:=caddr b0)
      and eqcar(lh,'difference) and (f:=cadr lh) and (s:=caddr lh)
      and eqcar(f,'times) and eqcar(s,'times) 
      and (x:=cadr f) and (y:=caddr f) and member(x,vars)
          and member(y,vars)
      and x=caddr s and y=cadr s;
     if not w then typerr(b,"commutator relation");
     if member(x.y,m) then <<w:=x;x:=y;y:=w; rh:={'minus,rh}>>;
     m:=delete(y.x,m);
     rs:={'replaceby,{'times,x,y},{'plus,{'times,y,x},rh}} .rs>>;
   ncdsetup!*{'list.vars,'list.rs};
   apply('korder,{vars});
   apply('order,{vars});
   for each c in m do
     rs:={'replaceby,{'times,cdr c,car c},{'times,car c,cdr c}}. rs;
   ncpi!-comm!-rules!*:='list.rs;
   algebraic let ncpi!-comm!-rules!*,ncpi!-name!-rules!*;
  end;

endpatch;


% Poly declarations.

fluid '(!*algint !*!*processed);

patch poly;

% 27 Dec 95, 28 Mar 96.

symbolic procedure repartf u;
  (if domainp u
      then if atom u then u
            else if get(car u,'cmpxfn)
              then int!-equiv!-chk(car u . cadr u .
                        cadr apply1(get(car u,'i2d),0))
       else u
    else if mvar u eq 'i then repartf red u
    else addf(multpf(lpow u,repartf lc u),repartf red u))
       where u = reorder u where kord!* = 'i . kord!*;

% 27 Dec 95.

symbolic procedure impartf u;
  (if domainp u
     then if atom u then nil
           else if get(car u,'cmpxfn)
             then int!-equiv!-chk(car u . cddr u .
                                  cadr apply1(get(car u,'i2d),0))
       else nil
    else if mvar u eq 'i then addf(lc u,impartf red u)
    else if null dmode!* then impartf red u
    else addf(multpf(lpow u,impartf lc u),impartf red u))
       where u = reorder u where kord!* = 'i . kord!*;

%  6 Jan 96.

symbolic procedure factorf u;
  (begin scalar m!-image!-variable,new!-korder,old!-korder,sign,v,w;
      if domainp u then return list u;
      new!-korder:=kernord(u,nil);
      if !*kernreverse then new!-korder:=reverse new!-korder;
      old!-korder:=setkorder new!-korder;
      u := reorder u;
      if minusf u then <<sign := not sign; u := negf u>>;
      v := comfac u;
      u := quotf1(u,cdr v);
      if domainp u then errach list("Improper factors in factorf");
      w := car v;
      v := fctrf1 cdr v;
      if w then v := car v . (!*k2f car w . cdr w) . cdr v;
      m!-image!-variable := mvar u;
      u :=
        distribute!.multiplicity(factorize!-primitive!-polynomial u,1);
      setkorder old!-korder;
      if sign then u := (negf caar u . cdar u) . cdr u;
      u := fac!-merge(v,1 . u);
      return car u . for each w in cdr u collect (reorder car w . cdr w)
   end) where current!-modulus = current!-modulus;

% 11 Jan 96.

symbolic procedure diffp(u,v);
   begin scalar n,w,x,y,z; integer m;
        n := cdr u;
        u := car u;
        if u eq v and (w := 1 ./ 1) then go to e
         else if atom u then go to f
         else if (not atom car u and (w:= difff(u,v)))
                  or (car u eq '!*sq and (w:= diffsq(cadr u,v)))
          then go to c
         else if x := get(car u,'dfform) then return apply3(x,u,v,n)
         else if x:= get(car u,dfn_prop u) then nil
         else if car u eq 'plus and (w := diffsq(simp u,v))
          then go to c
         else go to h;
        y := x;
        z := cdr u;
    a:  w := diffsq(simp car z,v) . w;
        if caar w and null car y then go to h;
        y := cdr y;
        z := cdr z;
        if z and y then go to a
         else if z or y then go to h;
        y := reverse w;
        z := cdr u;
        w := nil ./ 1;
    b:  if caar y
          then w := addsq(multsq(car y,simp subla(pair(caar x,z),
                                                   cdar x)),
                          w);
        x := cdr x;
        y := cdr y;
        if y then go to b;
    c:
    e:  if (x := atsoc(u,wtl!*))
          then w := multpq('k!* .** (-cdr x),w);
        m := n-1;
        return rationalizesq if n=1 then w
                else if flagp(dmode!*,'convert)
                     and null(n := int!-equiv!-chk
                                           apply1(get(dmode!*,'i2d),n))
                 then nil ./ 1
                else multsq(!*t2q((u .** m) .* n),w);
    f:  if not depends(u,v)
           and (not (x:= atsoc(u,powlis!*))
                 or not depends(cadddr x,v))
          then return nil ./ 1;
        w := list('df,u,v);
        w := if x := opmtch w then simp x else mksq(w,1);
        go to e;
    h:  if car u eq 'df
          then if depends(cadr u,v)
             and not(cadr u eq v and not depends(v,caddr u))
                 then
          <<if !*fjwflag and eqcar(cadr u, 'int) then
              if caddr cadr u eq v then
                 << w := 'df . cadr cadr u . cddr u;  go to j >>
              else if !*allowdfint and
                 not_df_p(w := diffsq(simp!* cadr cadr u, v))
              then <<
                 w := aeval{'int, mk!*sq w, caddr cadr u} . cddr u;
                 go to j >>;
           if (x := find_sub_df(w:= cadr u . derad(v,cddr u),
                                           get('df,'kvalue)))
                          then <<w := simp car x;
                                 for each el in cdr x do
                                    for i := 1:cdr el do
                                        w := diffsq(w,car el);
                                 go to e>>
                       else w := 'df . w
                >>
                else return nil ./ 1
         else w := list('df,u,v);
   j:   if (x := opmtch w) then w := simp x
         else if not depends(u,v) then return nil ./ 1
         else w := mksq(w,1);
      go to e
   end;

% 17 Jan 96.

symbolic procedure exptsq(u,n);
   begin scalar x;
      if n=1 then return u
       else if n=0
         then return if null numr u then rerror(poly,4," 0**0 formed")
                      else 1 ./ 1
       else if null numr u then return u
       else if n<0 then return simpexpt list(mk!*sq u,n)
       else if null !*exp
        then return mksfpf(numr u,n) ./ mksfpf(denr u,n)
       else if kernp u then return mksq(mvar numr u,n)
       else if denr u=1 then return exptf(numr u,n) ./ 1
       else if domainp numr u
        then x := multsq(!:expt(numr u,n) ./ 1,1 ./ exptf(denr u,n))
       else <<x := u;
              while (n := n-1)>0
                 do x := multf(numr u,numr x) ./ multf(denr u,denr x);
              x := canonsq x>>;
      if null cdr x then rerror(poly,101,"Zero divisor");
      return x
   end;

% 11 Feb 96.

symbolic procedure dcombine(u,v,fn);
   <<u := if atom u
        then apply2(get(car v,fn),apply1(get(car v,'i2d),u),v)
       else if atom v
        then apply2(get(car u,fn),u,apply1(get(car u,'i2d),v))
       else if car u eq car v then apply2(get(car u,fn),u,v) else
      (<<if (not(x and atom x)
             or (get(du,'cmpxfn) and not get(dv,'cmpxfn)
             or du memq dl and not(dv memq dl)) and dv neq '!:ps!:)
            and not flagp(dv,'noconvert) then
            <<if du memq dml and dv eq '!:rd!:
                 or du eq '!:rd!: and dv memq dml then
                 <<u := apply1(get(du,'!:cr!:),u); du := '!:cr!:>>
              else if du eq '!:rn!: and dv eq '!:gi!:
                 or du eq '!:gi!: and dv eq '!:rn!: then
                 <<u := apply1(get(du,'!:crn!:),u); du := '!:crn!:>>;
              v := apply1(get(dv,du),v); x := get(du,fn)>>
            else <<u := apply1(x,u); x := get(dv,fn)>>;
         apply2(x,u,v)>>
       where x=get(du,dv),dml='(!:crn!: !:gi!:),dl='(!:rd!: !:cr!:))
       where du=car u,dv=car v;
       if !*rounded and !*roundall and not atom u then 
       int!-equiv!-chk
         if (v := car u) eq '!:rn!: and cddr u neq 1 then !*rn2rd u
         else if v eq '!:crn!: and (cdadr u neq 1 or cdddr u neq 1)
            then !*crn2cr u
         else u
       else if fn eq 'divide then
          int!-equiv!-chk car u . int!-equiv!-chk cdr u
       else int!-equiv!-chk u>>;

%  6 Mar 96, 16 Jul 96, 17 Jan 98.

symbolic procedure gcdf(u,v);
   begin scalar !*exp, !*rounded;
      !*exp := t;
      u := if domainp u or domainp v or not !*ezgcd
              or dmode!*
              or free!-powerp u or free!-powerp v
             then gcdf1(u,v)
            else ezgcdf(u,v);
      return if minusf u then negf u else u
   end;

symbolic procedure gcdnx(u,v);
   if domainp u then gcdfd(u,v)
    else if domainp v then gcdfd(v,u)
    else if null red u then gcdnx(lc u,v)
    else gcdnx(lc u,gcdnx(red u,v));

% 21 May 96.

symbolic procedure mksfpf(u,n);
   (if n=1 then x
     else if domainp x then !:expt(x,n)
     else if n>=0 and onep lc x and null red x
      then (((if z and cdr z<=m then nil else !*p2f mksp(y,m))
            where z=assoc(y,asymplis!*)) where m=ldeg x*n,y=mvar x)
     else exptf2(x,n))
    where x=mkprod u;

% 22 May 96, 20 Jul 98.

symbolic procedure multf(u,v);
   begin scalar x,y;
    a:  if null u or null v then return nil
         else if u=1 then return v
         else if v=1 then return u
         else if domainp u then return multd(u,v)
         else if domainp v then return multd(v,u)
         else if not(!*exp or ncmp!* or wtl!* or x)
          then <<u := mkprod u; v := mkprod v; x := t; go to a>>;
        x := mvar u;
        y := mvar v;
        if noncomfp v and (noncomp x or null !*!*processed)
          then return multfnc(u,v)
         else if x eq y
          then <<if not fixp ldeg u or not fixp ldeg v
                   then x := x .** reval list('plus,ldeg u,ldeg v)
                  else x := mkspm(x,ldeg u+ldeg v);
                 y := addf(multf(red u,v),multf(!*t2f lt u,red v));
                 return if null x or null(u := multf(lc u,lc v))
                    then <<!*asymp!* := t; y>>
                   else if x=1 then addf(u,y)
                   else if null !*mcd then addf(!*t2f(x .* u),y)
                   else x .* u .+ y>>
         else if ordop(x,y)
          then <<x := multf(lc u,v);
                 y := multf(red u,v);
                 return if null x then y else lpow u .* x .+ y>>;
        x := multf(u,lc v);
        y := multf(u,red v);
        return if null x then y else lpow v .* x .+ y
   end;

symbolic procedure noncomfp u;
   not domainp u and (noncomp mvar u or noncomfp lc u or noncomfp red u);

symbolic procedure multfnc(u,v);
   begin scalar x,y;
      x := multf(lc u,!*t2f lt v);
      if null x then nil
       else if not domainp x and mvar x eq mvar u
        then x := addf(if null (y := mkspm(mvar u,ldeg u+ldeg x))
                         then nil
                        else if y = 1 then lc x
                        else !*t2f(y .* lc x),
                       multf(!*p2f lpow u,red x))
       else if noncomp mvar u then x := !*t2f(lpow u .* x)
       else x := multf(!*p2f lpow u,x) where !*!*processed=t;
      return addf(x,addf(multf(red u,v),multf(!*t2f lt u,red v)))
   end;

% 26 May 96, 1 Sep 97, 31 Jan 98.

symbolic procedure rationalizesq u;
   begin scalar !*structure,!*sub2,v,x;
      if x := get(dmode!*,'rationalizefn) then u := apply1(x,u);
      v := subs2q u;
      return if domainp denr v then v
              else if (x := rationalizef denr v) neq 1
               then <<v := multf(numr v,x) ./ multf(denr v,x);
                      if null !*algint and null !*rationalize 
                        then v := gcdchk v;
                      v := subs2q v;
                      if not domainp numr quotsq(u,v)
                        then rationalizesq v else v>>
             else u
   end;

% 21 Jul 96.

symbolic procedure mkprod u;
   begin scalar w,x,y,z,!*exp,!*sub2;
      if null u or kernlp u then return u;
      !*sub2 := t;
      x := subs2(u ./ 1);
      if denr x neq 1 then return u
       else if numr x neq u
        then <<u := numr x; if null u or kernlp u then return u>>;
      !*exp := t;
      w := ckrn u;
      u := quotf(u,w);
      x := expnd u;
      if null x or kernlp x then return multf(w,x);
      if !*mcd and (!*sqfree or !*factor or !*gcd)
        then y := fctrf x
       else <<y := ckrn x; x := quotf(x,y); y := list(y,x . 1)>>;
      if cdadr y>1 or cddr y
        then <<z := car y;
               for each j in cdr y do
                  z := multf(mksp!*(car j,cdr j),z)>>
       else if not !*group and tmsf u>tmsf caadr y
        then z := multf(mksp!*(caadr y,cdadr y),car y)
       else z := mksp!*(u,1);
      return multf(w,z)
   end;

% 27 Apr 96, 27 Jul 96.

symbolic procedure gcdf2(u,v);
   begin scalar asymplis!*,w,z;
      if not num!-exponents u or not num!-exponents v then return 1;
      if !*gcd and length(w := kernord(u,v))>1
        then <<w := list setkorder w;
               u := reorder u;
               v := reorder v>>
       else w := nil;
      if mvar u eq mvar v
        then begin scalar x,y;
                x := comfac u;
                y := comfac v;
                z := gcdf1(cdr x,cdr y);
                u := quotf1(u,comfac!-to!-poly x);
                v := quotf1(v,comfac!-to!-poly y);
                if !*gcd then z := multf(gcdk(u,v),z)
                 else if v and quotf1(u,v) then z := multf(v,z)
                 else if u and quotf1(v,u) then z := multf(u,z);
                if car x and car y
                  then if pdeg car x>pdeg car y
                         then z := multpf(car y,z)
                        else z := multpf(car x,z)
             end
       else if ordop(mvar u,mvar v) then z := gcdf1(cdr comfac u,v)
       else z := gcdf1(cdr comfac v,u);
      if w then <<setkorder car w; z := reorder z>>;
      return z
   end;

% 27 Jul 96.

symbolic procedure quotf1(p,q);
   if null p then nil
    else if p=q then 1
    else if q=1 then p
    else if domainp q then quotfd(p,q)
    else if domainp p then nil
    else if mvar p eq mvar q
     then begin scalar u,v,w,x,xx,y,z,z1; integer n;
    a:if idp(u := rank p) or idp(v := rank q) or u<v then return nil;
        u := lt!* p;
        v := lt!* q;
        w := mvar q;
        x := quotf1(tc u,tc v);
        if null x then return nil;
        n := tdeg u-tdeg v;
        if n neq 0 then y := w .** n;
        xx := multf(negf x,red q);
        p := addf(red p,if n=0 then xx else multpf(y,xx));
        if p and (domainp p or not(mvar p eq w)) then return nil
         else if n=0 then go to b;
        z := aconc!*(z,y .* x);
        if null p then return if z1 then rnconc(z,z1) else z;
        go to a;
    b:  if null p then return rnconc(z,x)
         else if !*mcd then return nil
         else z1 := x;
        go to a
   end
    else if ordop(mvar p,mvar q) then quotk(p,q)
    else nil;

%  4 Aug 96, 30 Aug 98.

symbolic procedure rnconc(u,v);
   if null u then v
    else if noncomfp u and noncomfp v then addf(u,v)
    else begin scalar w;
            w := u;
            while cdr w do <<w := cdr w>>;
            rplacd(w,v);
            return u
         end;

symbolic procedure noncomfp u;
   not domainp u and (noncomp mvar u or noncomfp lc u or noncomfp red u);

% 11 Sep 96.

symbolic procedure setcmpxmode(u,bool);
   begin scalar x,y;
      x := get(u,'tag);
      if u eq 'complex
        then if null dmode!*
               then return if null bool then nil
                else <<put('i,'idvalfn,'mkdgi);
                       setdmode1('complex,bool)>>
         else if null bool
                then return if null !*complex then nil
                else if get(dmode!*,'dname) eq 'complex
                      then <<remprop('i,'idvalfn);
                             setdmode1('complex,nil)>>
                     else <<remprop('i,'idvalfn);
                           setdmode1(get(get(dmode!*,'realtype),'dname),
                                       t)>>
         else if dmode!* eq '!:gi!: or get(dmode!*,'realtype)
            then return nil
         else if not (y := get(dmode!*,'cmpxtype))
               then dmoderr(dmode!*,x)
         else <<put('i,'idvalfn,get(y,'ivalue));
                     return setdmode1(get(y,'dname),bool)>>
      else if null bool then
         if u eq (y := get(get(dmode!*,'realtype),'dname)) then
            <<put('i,'idvalfn,'mkdgi); return setdmode1('complex,t)>>
            else if null y then return nil
            else offmoderr(u,y)
      else <<u := get(u,'tag);
             y := get(u,'cmpxtype);
             if null y then dmoderr(u,'!:gi!:);
             put('i,'idvalfn,get(y,'ivalue));
             return setdmode1(get(y,'dname),bool)>>
   end;

%  3 Nov 96.

symbolic procedure lcofeval u;
   begin scalar kern,x,y;
      if null u or null cdr u or not null cddr u
        then rerror(poly,280,
                    "LCOF called with wrong number of arguments");
      kern := !*a2k cadr u;
      u := simp!* car u;
      y := denr u;
      tstpolyarg(y,u);
      u := numr u;
      if domainp u then return if null u then 0 else mk!*sq (u . 1)
       else if mvar u eq kern then return !*ff2a(lc u,y);
      x := updkorder kern;
      u := reorder u;
      if mvar u eq kern then u := lc u;
      setkorder x;
      return if null u then 0 else !*ff2a(u,y)
   end;

% 22 Dec 96.

symbolic procedure simpdf u;
   begin scalar v,x,y,z;
      if null subfg!* then return mksq('df . u,1);
      v := cdr u;
      u := simp!* car u;
  a:  if null v or null numr u then return u;
      x := if null y or y=0 then simp!* car v else y;
      if denr x neq 1 or atom numr x
        then typerr(prepsq x,"kernel or integer")
       else (if domainp z
               then if get(car z,'domain!-diff!-fn)
                       then begin scalar dmode!*,alglist!*;
                              x := prepf z;
                              if null prekernp x
                                then typerr(x,"kernel")
                            end
                     else typerr(prepf z,"kernel")
              else if null red z and lc z = 1 and ldeg z = 1
                      then x := mvar z
              else typerr(prepf z,"kernel")) where z = numr x;
      v := cdr v;
      if null v then <<u := diffsq(u,x); go to a>>;
      y := simp!* car v;
      if null numr y then <<v := cdr v; y := nil; go to a>>
       else if not(z := d2int y) then <<u := diffsq(u,x); go to a>>;
      v := cdr v;
      for i:=1:z do u := diffsq(u,x);
      y := nil;
      go to a
   end;

symbolic procedure d2int u;
   if denr u neq 1 then nil
    else if numberp(u := numr u) then u
    else if not domainp u or not(car u eq '!:rd!:) then nil
    else (if abs(float x - u)<!!fleps1 then x else nil)
          where x=fix u where u=rd2fl u;

% 30 Jan 97.

symbolic procedure !:quotient(u,v);
   if null u or u=0 then nil
    else if null v or v=0 then rerror(poly,12,"Zero divisor")
    else if atom u and atom v
     % We might also check that remainder is zero in integer case.
     then if null dmode!* then u/v else
        (if atom recipv then u*recipv else dcombine(u,recipv,'times))
                where recipv=!:recip v
    else dcombine(u,v,'quotient);

%  9 Apr 97.

symbolic procedure comfac p;
   begin scalar x,y;
        if flagp(dmode!*,'field) and ((x := lnc p) neq 1)
          then p := multd(!:recip x,p);
        if null red p then return lt p;
        x := lc p;
        y := mvar p;
    a:  p := red p;
        if degr(p,y)=0
          then return nil
            . if domainp p or not(noncomp y and noncomp mvar p)
                then gcdf(x,p)
               else 1
         else if null red p then return lpow p . gcdf(x,lc p)
         else x := gcdf(lc p,x);
        go to a
   end;

% 24 Dec 97, 18 Feb 98, 31 Mar 98.

symbolic procedure sqfrf u;
   begin integer n; scalar !*gcd,v,w,x,y,z,!*msg,r;
      !*gcd := t;
      if (r := !*rounded) then
         <<on rational; u := numr resimp !*f2q u>>;
      n := 1;
      x := mvar u;
      v := gcdf(u,diff(u,x));
      u := quotf(u,v);
      if flagp(dmode!*,'field) and ((y := lnc u) neq 1)
        then <<u := multd(!:recip y,u); v := multd(y,v)>>
       else if (w := get(dmode!*,'units)) and (w := assoc(y:= lnc u,w))
        then <<u := multd(cdr w,u); v := multd(y,v)>>;
      while degr(v,x)>0 do
       <<w := gcdf(v,u);
         if u neq w then z := (quotf(u,w) . n) . z;
         v := quotf(v,w);
         u := w;
         n := n + 1>>;
         if r then
            <<on rounded;
              u := numr resimp !*f2q u;
              z := for each j in z
                       collect numr resimp !*f2q car j . cdr j>>;
      if v neq 1 then if n=1 then u := multf(v,u)
       else if (w := rassoc(1,z)) then rplaca(w,multf(v,car w))
       else if null z and not domainp v then z := {v . 1}
       else if null z and ((w := rootxf(v,n)) neq 'failed)
        then u := multf(w,u)
       else errach {"sqfrf failure",u,n,z};
      return (u . n) . z
   end;

% 18 Feb 98.

symbolic procedure factor!-prim!-f u;
   begin scalar v,w,x,y;
      if ncmp!* then return list(1,u . 1);
      if dmode!* and (x := get(dmode!*,'sqfrfactorfn))
        then if !*factor then v := apply1(x,u) else v := list(1,u . 1)
       else if flagp(dmode!*,'field) and ((w := lnc u) neq 1)
        then v := w . sqfrf multd(!:recip w,u)
       else if (w := get(dmode!*,'units)) and (w := assoc(y := lnc u,w))
        then v := y . sqfrf multd(cdr w,u)
       else v := 1 . sqfrf u;
      if x and (x eq get(dmode!*,'factorfn))
        then return v;
      w := list car v;
      for each x in cdr v
         do w := fac!-merge(factor!-prim!-sqfree!-f x,w);
      return w
   end;

% 30 Aug 98.

symbolic procedure gcdf1(u,v);
   begin scalar w;
      if null u then return v
       else if null v then return u
       else if u=1 or v=1 then return 1
       else if domainp u then return gcdfd(u,v)
       else if domainp v then return gcdfd(v,u)
       else if not num!-exponents u or not num!-exponents v then 1
       else if quotf1(u,v) then return v
       else if quotf1(v,u) then return u;
      w := gcdf2(u,v);
      if !*gcd and not(dmode!* memq '(!:rd!: !:cr!:))
          and (null quotf1(u,w) or null quotf1(v,w))
        then if noncomf u or noncomf v then return 1
              else errach list("gcdf failed",prepf u,prepf v);
      return w
   end;

endpatch;


patch rlisp;

%  4 Dec 95.

symbolic procedure yesp1;
   begin scalar bool,x,y;
    a:  x := readch();
        if x eq !$eol!$ then go to a
         else if x eq !$eof!$ then eval '(bye)
         else if (y := x memq '(!y !Y)) or x memq '(!n !N)
          then return y
         else if null bool then <<prin2t "Type Y or N"; bool := t>>;
        go to a
   end;

% 18 Dec 96.

if 'csl memq lispsystem!*
   then <<put('gc,'simpfg,'((t (verbos t)) (nil (verbos nil))));
          switch gc>>;

% 18 Feb 96.

symbolic procedure getsetvarlis u;
   if null u then nil
    else if atom u then errach list("getsetvarlis",u)
    else if atom car u then car u . getsetvarlis cdr u
    else if caar u memq '(setel setk)
     then getsetvarlis cadar u . getsetvarlis cdr u
    else if caar u eq 'setq then mkquote cadar u . getsetvarlis cdr u
    else car u . getsetvarlis cdr u;

symbolic procedure getsetvars u;
   if atom u then nil
    else if car u memq '(setel setk)
     then getsetvarlis cadr u . getsetvars caddr u
    else if car u eq 'setq then mkquote cadr u . getsetvars caddr u
    else nil;

% 31 Dec 97.

symbolic procedure !*!*a2s(u,vars);
    if null u or constantp u and null fixp u
      or intexprnp(u,vars) and null !*composites
                 and null current!-modulus
      or flagpcar(u,'nochange) and not(car u eq 'getel)
     then u
    else if smember('random,u) then
     list(list('lambda,'(!*uncached),list(!*!*a2sfn,u)),t)
    else list(!*!*a2sfn,u);

% 1 Jan 98.

symbolic procedure formc!*(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'revalx;
      return formc(u,vars,mode)
   end;

symbolic procedure revalx u;
   reval if not atom u and not atom car u then prepf u else u;

endpatch;


patch scope;

% 17 Feb 96.

symbolic procedure primat;
   begin scalar l;
     l := linelength(120);
     terpri();
     prin2 "Sumscheme :";
     prischeme('plus);
     terpri();
     terpri();
     terpri();
     prin2 "Productscheme :";
     prischeme('times);
     linelength(l);
   end;

endpatch;


% Solve declarations.

fluid '(!*fullroots !*solvealgp !*solvesingular !!gcd vars!*
        !*!*norootvarrenamep!*!*);

global '(assumptions);

patch solve;

% 20 Apr 96.

symbolic procedure solvemixedsys(exlis,varlis);
   if null cadr(exlis := siftnonlnr(exlis,varlis)) then
      solvelnrsys(car exlis,varlis)
   else if null car exlis then
      solvenonlnrsys(cadr exlis,varlis)
   else
      begin scalar x,y,z;
      x := solvelnrsys(car exlis,varlis) where !*arbvars = nil;
      if car x = 'inconsistent then return x
      else x := cadr x;
      z := pair(cadr x,foreach ex in car x collect mk!*sq ex);
      exlis := foreach ex in cadr exlis join
                  if ex := numr subs2 resimp subf(ex,z) then {ex};
      varlis := setdiff(varlis,cadr x);
      y := solvemixedsys(exlis,varlis);
      if car y memq {'inconsistent,'singular,'failed,nil} then return y
      else return t . foreach s in cdr y collect
            <<z := foreach pr in pair(cadr s,car s) join
                      if not smemq('root_of,cdr pr) then
                         {car pr . mk!*sq cdr pr};
              {append(car s,foreach ex in car x collect subsq(ex,z)),
               append(cadr s,cadr x),caddr s}>>;
      end;

% 12 Dec 95, 9 May 96.

symbolic procedure solvesq1 (ex,var,mul);
     begin scalar e1,oldkorder,x1,y,z;  integer mu;
      ex := numr ex;
      if null(x1 := topkern(ex,var)) then return nil;
      oldkorder := setkorder list var;
      e1 := reorder ex;
      setkorder oldkorder;
      if !*modular then
      <<load!_package 'modsr; return msolvesys({e1},x1,nil)>>;
      if mvar e1 = var and null cdr x1 and ldeg e1 =1
        then return {{{quotsq(negf reorder red e1 ./1,
                              reorder lc e1 ./ 1)},
                     {var},mul}};
      ex := if !*rounded then {1,ex . 1} else fctrf ex;
      if domainp car ex then ex := cdr ex
       else ex := (car ex . 1) . cdr ex;
      for each j in ex do
        <<e1 := car j;
          x1 := topkern(e1,var);
          mu := mul*cdr j;
          if null !*rounded and length x1=1 and length kernels e1<5
             and length(y := decomposef1(e1,nil))>1
             and (y := solvedecomp(reverse y,car x1,mu))
            then z := append(y,z)
           else if (degr(y := reorder e1,var) where kord!*={var}) = 1
              and not smember(var,delete(var,x1))
            then <<y := {{quotsq(!*f2q negf reorder red y,
                                 !*f2q reorder lc y)},
                         {var},mu};
                   z := y . z>>
           else if x1
            then z := solnsmerge(
             if null cdr x1 then solve1(e1,car x1,var,mu)
              else if (y := principle!-of!-powers!-soln(e1,x1,var,mu))
                          neq 'unsolved
               then y
              else if not smemq('sol,x1 := solve!-apply!-rules(e1,var))
               then solvesq(x1,var,mu)
              else mkrootsof(e1 ./ 1,var,mu),
                 z)>>;
      return z
   end;

symbolic procedure solve11(e1,x1,var,mu);
   begin scalar !*numval,b,coefs,hipow,w;  integer n;
      if null !*fullroots and null !*rounded and numrdeg(e1,var)>2
        then return mkrootsof(e1 ./ 1,var,mu);
      !*numval := t;
      coefs:= errorset!*(list('solvecoeff,mkquote e1,mkquote x1),nil);
      if atom coefs or atom x1 and x1 neq var
        then return mkrootsof(e1 ./ 1,var,mu);
      coefs := car coefs;
      n:= !!gcd;
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
           for k := 0:n-1 do
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
               else if (z := get(car x1,'inverse))
                then y := append(solvesq(subtrsq(simp!* cadr x1,
                                 simp!* list(z,mk!*sq lincoeff)),
                                 var,mu),y)
               else y := list(list subtrsq(simp!* x1,lincoeff),nil,mu)
                            . y>>;
         return y
        end
       else if hipow=2
        then return <<x1 := exptsq(simp!* x1,n);
                      w := nil;
                      for each j in solvequadratic(getcoeff(coefs,2),
                                    getcoeff(coefs,1),getcoeff(coefs,0))
                         do w :=
                            solnsmerge(solvesq(subtrsq(x1,j),var,mu),w);
                      w>>
       else return solvehipow(e1,x1,var,mu,coefs,hipow)
 end;

symbolic procedure solnsmerge(u,v);
   if null u then v
    else solnsmerge(cdr u,solnmerge(caar u,cadar u,caddar u,v));

symbolic procedure solvehipow(e1,x1,var,mu,coefs,hipow);
   begin scalar b,c,d,f,rcoeffs,z;
      f:=(hipow+1)/2;
      d:=exptsq(simp!* x1,!!gcd);
      rcoeffs := reverse coefs;
      return if solve1test1(coefs,rcoeffs,f)
        then if f+f=hipow+1
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
                     for each j in solvesq(c,'!!x,mu) do z :=
                      solnsmerge(
                      solvesq(addsq(1 ./ 1,multsq(d,subtrsq(d,caar j))),
                                var,caddr j),z);
                     z>>
       else if solve1test2(coefs,rcoeffs,f)
        then <<c:=addsq(d,(-1 ./1));
               b := solvesq(c,var,mu);
               e1 := quotsq(e1 ./ 1, c);
               if f+f = hipow
                then <<c := addsq(d,(1 ./ 1));
                       b := append(solvesq(c,var,mu),b);
                       e1 := quotsq(e1,c)>>;
               append(solvesq(e1,var,mu),b)>>
       else if !*rounded and univariatep e1
        then reversip solveroots(e1,var,mu)
       else if null !*fullroots then mkrootsof(e1 ./ 1,var,mu)
       else if hipow=3
        then <<for each j in solvecubic(getcoeff(coefs,3),
                                        getcoeff(coefs,2),
                                        getcoeff(coefs,1),
                                        getcoeff(coefs,0))
                     do z := solnsmerge(solvesq(subtrsq(d,j),var,mu),z);
                z>>
       else if hipow=4
        then <<for each j in solvequartic(getcoeff(coefs,4),
                                          getcoeff(coefs,3),
                                          getcoeff(coefs,2),
                                          getcoeff(coefs,1),
                                          getcoeff(coefs,0))
                     do z := solnsmerge(solvesq(subtrsq(d,j),var,mu),z);
                z>>
       else mkrootsof(e1 ./ 1,var,mu)
   end;

% 28 Dec 95.

symbolic procedure all_real(a,b,c);
   begin scalar dmode,!*ezgcd,!*msg,!*numval;
      dmode := dmode!*;
      !*numval := t;
      on complex,rounded;
      a := real_1(a := resimp a) and real_1(b := resimp b)
           and real_1(c := resimp c);
      off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      return a
   end;

%  6 Jan 96.

symbolic procedure solveroots(ex,var,mu);
   begin scalar x,y;
      x := reval list('roots_at_prec,mk!*sq(ex ./ 1));
      if not(car x eq 'list)
        then errach list("incorrect root format",ex);
      for each z in cdr x do
         y := solnsmerge(
                 solvesq(if not(car z eq 'equal)
                           then errach list("incorrect root format",ex)
                          else simpplus {cadr z,{'minus,caddr z}},
                         var,mu),
                         y);
      return y
   end;

% 12 Jan 96, 4 Jun 96.

symbolic procedure solvenonlnrsys(sys,uv);
  begin scalar q,r,s,tag,!*expandexpt;
   s := '(nil);
   if solve!-psysp(sys,uv) then s := {sys} else
      for each p in sys do
         <<r := nil;
           for each q in cdr fctrf p do
              if topkernlis(car q,uv)
                then for each u in s do r := (car q . u) . r;
          s := r>>;
   tag := 'failed; r := nil;
   for each u in s do 
      <<u := solvenonlnrcollectexpt u;
        q := solvenonlnrsys1(u,uv);
        if eqcar(q,'failed) then q := solvenonlnrsyssep(u,uv);
        if eqcar(q,'failed) then q := solvenonlnrsyslin(u,uv,nil);
        if eqcar(q,'not) then q := solvenonlnrsyslin(u,uv,t);
        if eqcar(q,'not) then q := '(failed);
        if car q and car q neq 'failed then tag := car q;
        q := if car q neq 'failed then cdr q else
                for each j in u collect {{j ./ 1},nil,1};
        r := union(q,r)>>;
   return if tag eq 'inconsistent or tag eq 'failed then {tag}
       else tag . r
  end;

symbolic procedure topkernlis(u,v);
   v and (topkern(u,car v) or topkernlis(u,cdr v));

% 26 Feb 96.

symbolic procedure solve0(elst,xlst);
   begin scalar !*exp,!*notseparate,w;  integer neqn;
   !*exp := t;
   elst := for each j in solveargchk elst collect simp!* !*eqn2a j;
   neqn := length elst;
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
    elst := for each j in elst collect numr j;
    w := solvesys(elst,vars!*);
    if null w then return nil;
    if car w memq {'t,'inconsistent,'singular} then return cdr w
     else if car w eq 'failed or null car w
      then return for each j in elst collect list(list(j ./ 1),nil,1)
     else errach list("Improper solve solution tag",car w)
   end;
 
% 23 Apr 96.

switch varopt;

% 9 May 96.

symbolic procedure varsift(a,var);
   if atom a then
      if not(null a or numberp a or a eq var) then list a else nil
   else if get(car a,'dname) then nil
   else if car a memq '(arbint arbcomplex)
    or (get(car a,'simpfn) eq 'simpiden and not smember(var,a))
    then list a
   else if car a eq '!*sq then varsift(prepsq cadr a,var)
   else for each c in cdr a join varsift(c,var);

% 20 Jan 97.

symbolic procedure siftnonlnr(exlis,varlis);
   begin scalar lin,nonlin;
   foreach ex in exlis do
      if ex then
         if nonlnr(ex,varlis) then nonlin := ex . nonlin
         else lin := ex . lin;
   return {reversip lin,reversip nonlin};
   end;

% 31 Jan 97.

symbolic procedure solve!-clean!-info(fl,flg);
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
             <<w:= absf numr simp{'nprimitive,form};
               if not domainp w then w := sqfrf!* w;
               for each z in r do if w then
                 if null cdr qremf(z,w) then r:=delete(z,r)
                  else if null cdr qremf(w,z) then w := nil;
               if w then r := w . r>>;
     return 'list . for each q in r collect prepf q
  end;

% 20 Feb 97.

symbolic procedure safe!-modrecip u;
   begin scalar q,!*msg,!*protfg;
      !*msg := nil; !*protfg := t;
      if eqcar(u,'!:mod!:) then u := cdr u;
      q := errorset({'general!-modular!-reciprocal, u},nil,nil);
      erfg!* := nil;
      return if errorp q then nil else car q
   end;

% 23 Feb 97.

symbolic procedure solvelnrsys(exlis,varlis);
   begin scalar w,method;
   if w := solvesparsecheck(exlis,varlis) then exlis := w
     else exlis := exlis . varlis;
   if null !*cramer and null exptexpflistp car exlis
      then method := 'solvebareiss
     else method := 'solvecramer;
   exlis := apply2(method,car exlis,cdr exlis)
               where bareiss!-step!-size!* = if w then 4 else 2;
   return solvesyspost(exlis,varlis);
   end;

% 29 Dec 97.

symbolic procedure mkrootsof(e1,var,mu);
   begin scalar x,name;
      x := if idp var then var else 'q_;
      name := !*!*norootvarrenamep!*!* or mkrootsoftag();
      if not !*!*norootvarrenamep!*!*
        then while smember(x,e1) do
             x := intern compress append(explode x,explode '!_);
      e1 := prepsq!* e1;
      if x neq var then e1 := subst(x,var,e1);
      return list list(list !*kk2q list('root_of,e1,x,name),list var,mu)
   end;

endpatch;


patch specfn;

% 10 Jan 96.

algebraic procedure compute_int_functions(x,f);
   begin scalar pre,!*uncached,scale,term,n,precis,result,interm;
   pre := precision 0; precision pre;
   precis := 10^(-2 * pre);
   lisp (!*uncached := t);
    if f = Si then 
           if x < 0 then result := 
                        - compute_int_functions(-x,f) else
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
    else if f = Ci then
           if x < 0 then result :=
                         - compute_int_functions(-x,f) -i*pi else
              << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else  if f = Ei then
          << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := (term * x)/n;
                    result := result + term/n;
                    n := n + 1>>; >>
    else  if f = Shi then
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
    else  if f = Chi then
            << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else if f = erf then
           if x < 0 then result := - compute_int_functions(-x,f) else
            << n:=1; term := x; result := x;
               if floor(x*7) > pre then precision  floor(x*7);
               interm := -1 *  x*x;
               while abs(term) > precis do
                 << term := (term * interm)/n;
                    result := result + term/(2n+1);
                    n := n + 1>>;  
               precision pre;
               result := result*2/sqrt(pi) ;>>
    else  if f = Fresnel_S then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x^3*pi/2; result := term/3;
                         interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n+1));
                    result := result + term/(4n+3);
                    n := n + 1>>; >>
    else  if f = Fresnel_C then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x; result := x; interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n-1));
                    result := result + term/(4n+1);
                    n := n + 1>>;  >>;
    precision pre;
    return result
  end;

% 16 Jan 96.

algebraic << 
 let { binomial (~n,~k) => ((for l:=0:(k-1) product (n-l))/factorial k)
                        when fixp n and fixp k and  k >=0,
       binomial (~n,~k) => 1
                when fixp n and fixp k and n >= k and k=0,
       binomial (~n,~k) => 0 
                when fixp n and fixp k and n<k and n >=0,
       binomial (~n,~k) => 0
                when fixp n and fixp k and k < 0,
       binomial (~n,~k) => Gamma(n+1) / Gamma (k+1) / Gamma(n-k+1)
                when numberp n and  numberp k and not(fixp (n - k) and
                (n-k) < 0),
       df(binomial(~c,~k),c) => binomial(c,k)*(Psi(1+c)-Psi(1+c-k))
     } >>;

endpatch;


patch ztrans;

% 27 Nov 95.

algebraic let {binomial(~n,~k)=>
       (for i:=0:k-1 product n-i)/factorial(k) when fixp(k)};

endpatch;

endmodule;

end;
