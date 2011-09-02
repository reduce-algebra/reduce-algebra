module patches; % Patches to correct problems in REDUCE 3.5.

% Author: Anthony C. Hearn.

% Copyright (c) 1994, RAND.  All Rights Reserved.

% Patch date:  28 Nov 1994.

% Bugs fixed by these patches.

% 11 Nov 93. The following revealed bugs in the ALG and SOLVE packages:
%            solve({-1/2*e**((sqrt(3)*i*x + x)/2)*sqrt(3)*x2*i + 1/2*
%                  e**((sqrt(3)*i*x + x)/2)*x2 + 1/2*e**(( - sqrt(3)*i
%                  *x+x)/2)*sqrt(3)*x1*i+1/2*e**((-sqrt(3)*i*x+x)/2)*x1,
%                  1/2*e**((sqrt(3)*i*x + x)/2)*sqrt(3)*x2*i + 1/2*e**
%                  ((sqrt(3)*i*x + x)/2)*x2 - 1/2*e**(( - sqrt(3)*i*x
%                  + x)/2)*sqrt(3)*x1*i + 1/2*e**(( - sqrt(3)*i*
%                  x + x)/2)*x1 - e**x*x},{x1,x2});

% 11 Nov 93. The following gave a wrong result:
%                   on combineexpt; 2^(1/2)*2^(1/3)*2^(1/6);

% 16 Nov 93. The following example did not give the necessary real
%                   roots: roots ((x**2+1)*x); rootsreal;

% 22 Nov 93. With combineexpt on, type errors occurred if structured
%                   domain elements were used.

% 25 Nov 93. With combineexpt on, results could be returned that were
%                   not in lowest terms.

%  3 Dec 93. There was a typo in some of the Bessel and Hankel function
%                   rules.

%  3 Dec 93.  solve(sin x+cos x,x); led to a recursive definition error.

%  3 Dec 93.  With nat off, the tilde in rules was prefixed by a !.

%  6 Dec 93.  The distributed definition of fl2bf in arith.red did not
%             work well on machines, such as the VAX, with small
%             exponent ranges.

% 15 Dec 93.  With rounded on, solving quadratics like x^2+2x+1 would
%               return 0 solutions.

% 16 Dec 93.  LOAD was not defined as an operator.

% 22 Dec 93.  With a high precision, REALROOTS could produce an error
%             "invalid argument to read:num".

% 22 Dec 93.  There was a reference to a (now) obsolete function ERBDCK.

% 22 Dec 93.  With ALGINT loaded, int(x/sqrt(x^4+10x^2-96x-71),x) gave
%             zero divisor errors.

% 30 Dec 93.  With rounded on and print_precision 6, numbers like
%             5.7751435691 rounded up incorrectly to 5.77515.

% 31 Dec 93.  The redefinition of MAPRIN in the ORTHOVEC package caused
%             problems with fancy printing.

% 10 Jan 94.  The absolute value of some complex expressions (e.g.,
%             sqrt(-4)) simplified to zero.

% 11 Jan 94.  Gentran changed to produce upper case code (as per the
%             Fortran 77 standard) and ignore print_precision.

% 14 Jan 94.  The rule for besselY(~n,~z) had the wrong sign.

% 21 Jan 94.  Expressions in some FOR loops were computed once instead
%             of each iteration, e.g., for i:=1:10 do write random 10+1;

% 24 Jan 94.  The following sequence gave a catastrophic error from
%             rounded number inaccuracies in the Bareiss division step:
%             matrix ck(5,5); on rounded; for i:=1 step 1 until 5 do
%             for j:=1 step 1 until 5 do ck(i,j):=1/(i+j);
%             for i:=1 step 1 until 5 do ck(i,i):=ck(i,i)-x; det(ck);

% 25 Jan 94.  Added the switch centered_mod, since the manual
%             incorrectly references this rather than balanced_mod.

% 30 Jan 94.  With Common Lisp, the call to REVERSE in LOWESTDEG in the
%             ASSIST package leads to problems.  In addition, the EQ
%             check for 0 in AR4 in the PM package fails in Common Lisp.

%  1 Feb 94.  The following algebraic system failed because the
%             dependency information got lost inside Groebner:
%             operator f; depend f,x; a:=df(f,x);
%             solve(a**2+2*a+2+b**2+2*b,{a,b});

%  6 Feb 94.  RANK would not work properly with a set of equations.

%  8 Feb 94.  The following sequence gave a catastrophic error from
%             incomplete surd division in the Bareiss division step:
%             matrix trans(5,5); for i:=1:4 do
%              x(i) := sqrt(2*i/(i+1))*(r(i+1)-(for j:=1:i sum r(j))/i);
%             x(5) := (for j:=1:5 sum r(j))/5$ for i:=1:5 do
%              for j:=1:5 do trans(i,j):=df(x(j),r(i)); det(trans);

% 14 Feb 94.  The following sequence did not perform the power substit-
%             ution in the last step: x := aa^6*dd^10$ y := dd^10*rr^6$
%             let dd^2=2-rr^2; x; y;

% 17 Feb 94.  A high energy physics vector substitution such as
%             vector p,q; sub(p=-p,p.q); led to a type conflict error.

% 19 Feb 94.  The following caused a loop in the EZGCD code:
%             on ezgcd; gcd(1206994056701660156250*c(2)^4*
%             (-187500*c(2)*c(0)^5+2475000*c(2)*c(0)^4-11610000*c(2)
%              *c(0)^3+23652000*c(2)*c(0)^2-21772800*c(2)*c(0)
%              +7464960*c(2)+4375*c(0)^6-45000*c(0)^5+5400*c(0)^4
%              +1404000*c(0)^3-5719248*c(0)^2+8024832*c(0)-3732480),625
%              *(625*c(0)^4-5250*c(0)^3+13500*c(0)^2-14040*c(0)+5184);

% 20 Feb 94.  The following sequence revealed problems in the expression
%             caching mechanism: symmetric r3lgr; for all a
%             let r3lgr(a,0)  = 0; r3lgc := 2$ r3lgr(1,1) := 1$
%             procedure r3lgs(a,b); begin if min(a,b)<1 then return 0;
%               while a+b>r3lgc do begin r3lgc := r3lgc+1;
%               for n:=1:r3lgc/2 do r3lgr(n,r3lgc-n):=r3lgr(n-1,r3lgc-n)
%                    -(d-r3lgc-n+1)/(r3lgc-n-1)*r3lgr(n,r3lgc-n-1) end;
%               return r3lgr(a,b) end; r3lgs(3,2);

% 22 Feb 94.  Expressions in FOR loops were not always reduced to lowest
%             terms.

% 23 Feb 94.  The sequence on complex; realvalued a,b,c,d; on factor;
%             repart((a +b*i)*c);  did not lead to a real result.

%  2 Mar 94.  The sequence u:=(x^2+2x*y+y^2)*e^(4t)/z^6; on factor,
%             expandlogs; log u; leads to a syntax error.

%  4 Mar 94.  nullspace mat((-sqrt(3)+1,2,3),(2,-sqrt(3)+3,1),
%                           (3,1,-sqrt(3)+ 2)) gave a null result.

% 12 Mar 94.  Modified patched definition of setk to provide a hook for
%             user-defined code.

% 13 Mar 94.  The following sequence did not yield a result in lowest
%             terms:  a:=1+x/2; let x**2=0; a*a; (or a^2;).

% 14 Mar 94.  The following sequence led to an error in INPRINT:
%             load_package solve; on factor; y:=a*x1+b; solve(y=0,x1);

% 23 Mar 94.  The code handling answers to questions such as CONT?
%             did not handle ends-of-file gracefully.

%  2 Apr 94.  Shared variables were not always updated in loops.

%  2 Apr 94.  Rlisp '88 records could not be used in general symbolic
%             mode.

%  3 Apr 94.  The (silly but correct) rule
%             for all m such that 1 let x=111; gave an error.

%  8 Apr 94.  The calculation of solve(t*exp(a-b*t) = exp(aa),t);
%             caused an endless loop in the pattern matcher.

% 12 Apr 94.  In some systems, the groebnert operator could cause a
%             numerical type error.

% 19 Apr 94.  solve({x^2+y^2+z^2-1,(x-1)^2+y^2+z^2-1,(x-1/2)^2
%             +(y-sqrt(3)/2)^2+z^2-1},{x,y,z}); gave spurious, incorrect
%             solutions.

% 20 Apr 94.  The sequence  on rounded; load_package numeric;
%             num_int(sin x,x=(0 .. 1))$ sum((-1)^k/(2*k+1)^2,k,0,
%             infinity);  gave the incorrect answer 0.

% 21 Apr 94.  The use of list operations, such as first, within a
%             procedure could lead to an erroneous type conflict.

% 24 Apr 94.  The sequence f:=( - 2*x**(2/3)*x + sqrt(x) - 1)/x**(1/4)$
%             g:=( - x**(4/3) + x**(5/6)*x - 2*x**3)/(x**(7/12)*x)$
%             on combineexpt; f-g; did not result in 0.

% 25 Apr 94.  Repeating identical FOR statements could result in
%             infinite loops.

% 28 Apr 94.  The sequence  load_package taylor; u := taylor(x,x,0,2);
%             taylorcombine(u^3); gave the wrong result.

% 29 Apr 94.  The following sequence led to a factorizer error:
%             explog:= {sqrt(e)**(~x*log(~y)/~z) => y**(x/z/2)};
%             on ezgcd,gcd; let explog;
 
%  2 May 94.  Sums with the same argument like sum(k,k,0,0) gave "k"
%             as the result.

%  5 May 94.  An initial WTLEVEL call could lead to a memory violation.

%  7 May 94.  Assgneval, setk and setk0 updated to improve evaluation
%             model.

% 13 May 94.  Added code to enable patch file to be loaded by a user.

% 17 May 94.  The sequence on rational; y^deg(x/2+1,x); gave a spurious
%             "invalid polynomial" error.

% 24 May 94.  The sequence on complex,rounded, solve(x^10-1); would not
%             return results fully simplified.

% 25 May 94.  An expression like let y = cos(x(1,1));  where x is an
%             array, could lead to a memory error on evaluating y.

%  5 Jun 94.  An expression that evaluated to zero (as opposed to zero
%             itself) raised to the zero power wrongly returned 1.

% 11 Jun 94.  The sequence on div; df(((x - 1)/2)**(1/4),x); led to a
%             spurious error.

% 12 Jun 94.  The sequence weight x=1,y=2$ wtlevel 4$ wtest:= (z^4-z^3*y
%             -z^3*x+z^2*y^2+2*z^2*x*y+z^2*x^2-3*z*x^2*y-z*x^3+x^4)/z^5;
%             wtest where z=>a; returns an expression with a non-trivial
%             denominator, which, while formally correct, is confusing.
%             THIS PATCH HAS BEEN WITHDRAWN, SINCE RESULTS ARE CORRECT
%             WITHOUT IT, AND IT CAUSES OTHER PROBLEMS.

% 14 Jun 94.  Square roots in operator arguments were not always
%             replaced in an sub expression,
%             e.g., sub(sqrt 2=s2,atan sqrt 2).

% 15 Jun 94.  In some cases, matrix arguments were not always fully
%             simplified.

% 18 Jun 94.  The evaluation of on complex; factorize (i*(a+1)*(a+b));
%             went into a loop.

% 29 Jun 94.  With FACTOR on or EXP off, COEFF would sometimes not split
%             an expression into its coefficients.

%  1 Jul 94.  With PRECISE on, SQRT of a product or a quotient (e.g.,
%             sqrt(x*y)) was incorrectly simplified.

%  2 Jul 94.  The sequence on limitedfactors; factorize(16x^2+(32i-8)*x
%             -8i-15); resulted in a catastrophic error.

%  3 Jul 94.  Arguments of operators in procedures were not always
%             correctly bound
%             (e.g., procedure op u; <<operator u; noncom u>>;)

%  4 Jul 94.  The GENTRAN/SCOPE optimize code could generate a spurious
%             numerical error.

% 16 Jul 94.  The sequence on modular; setmod 3; factorize(x^2+y^2); led
%             to a stack overflow rather than pointing out that multi-
%             variate modular factorization isn't currently supported.

%  3 Aug 94.  The sequence on complex; (1+i)^(-3); gave a type
%             conversion error.

% 30 Aug 94.  Assignments in Excalc: Any covariant index 0 in the lhs
%             was treated incorrectly. (e.g. v(-0) := 1 resulted in
%             v(0) := 1)
  
%  7 Sep 94.  Some inconsistent equation sets (e.g., {1,2,x,y}) would
%             return wrong results from SOLVE when CRAMER was off.

% 12 Sep 94.  Indexed coordinates in the Excalc coframe statement did
%             not work properly.
  
% 13 Sep 94.  Doing LET on the results of a SOLVE could create
%             non-unique kernels.

% 20 Sep 94.  REMAINDER failed for Gaussian integers, e.g.
%             on complex; remainder(2,1+i);

%  5 Oct 94.  It was possible to define an invalid recursive assignment
%             e.g., x := x+1;

%  6 Oct 94.  With EXP off, some non-zero determinants were returned as
%             0.

% 10 Oct 94.  Determinants of non-square matrices did not always lead to
%             an error.

% 22 Oct 94.  Expressions involving antisymmetric operators did not
%             always have the right sign.

% 19 Nov 94.  LENGTH did not work properly with PART or equations.

% 25 Nov 94.  Incomplete strings in a file could cause system errors.

% 28 Nov 94.  The sequence for all x,y let f(x,y)=(x-sqrt(x**2+y**2))/2;
%             solve(f(-r**3+3*r**2-5*r+2,2-r)=0,r); gave a wrong answer.


patch alg;

% 25 Nov 93.

symbolic procedure formsf(u,v,n);
   % u is either an integer, or a kernel.
   % Creates (u^v)^n as a standard form.
   if fixp u and fixp v then (u^v)^n
    else if v=1 then !*p2f mksp(u,n)
    else !*p2f mksp(list('expt,u,v),n);

symbolic procedure exptchksq u;
   % u is a standard quotient. Result is u with possible expt
   % simplifications.
   if null !*combineexpt then u
    else begin scalar v;
       v :=  exptchk numr u ./ exptchk denr u;
       if u=v or denr v=1 then return v
        % reduce to lowest terms.
        else return multsq(numr v ./1,1 ./denr v)
   end;

% 11 Nov 93.

symbolic procedure exptexpfp u;
   % true if u contains an expt kernel. It depends on ordp definition.
   not domainp u
      and ((eqcar(x,'expt) or exptexpfp lc u or exptexpfp red u)
           where x = mvar u);

%  3 Dec 93.

symbolic procedure tildepri u; <<prin2!* "~"; prin2!* cadr u>>;

% 10 Jan 94.

symbolic procedure rd!-abs u;
   % U is a prefix expression.  If it represents a constant, return the
   % abs of u.
   if !*rounded or not constant_exprp u then nil
    else begin scalar x,y,dmode!*;
            setdmode('rounded,t) where !*msg := nil;
            x := aeval u;
            if evalnumberp x
              then if null !*complex or 0=reval {'impart,x}
                     then y := if evalgreaterp(x,0) then u
                                else if evalequal(x,0) then 0
                                else {'minus,u};
            setdmode('rounded,nil) where !*msg := nil;
            return if y then simp y else nil
       end;

% 14 Feb 94.

symbolic procedure resimp1 u;
   begin
      u := quotsq(subf1(numr u,nil),subf1(denr u,nil));
      !*sub2 := t;
      return u
   end;


% 17 Feb 94.

symbolic procedure subeval2(u,v);
   begin scalar x,y,z;
     for each s in u do
       <<if null(x := getrtype v) then x := '!*sq;
         y := getrtype cdr s;
         if (z := get(x,'nssubfn)) and (z := atsoc(y,z))
            then v := apply2(cdr z,s,v)
          else v := subeval1(list s,v)>>;
     return v
   end;

% 20 Feb 94, 5 Oct 94.

symbolic procedure setk1(u,v,b);
   begin scalar x,y,z,!*uncached;
      !*uncached := t;
      if atom u
        then <<if null b
                 then <<if not get(u,'avalue)
                          then msgpri(nil,u,"not found",nil,nil)
                         else remprop(u,'avalue);
                        return nil>>
                else if (x:= get(u,'avalue)) then put!-avalue(u,car x,v)
                else put!-avalue(u,'scalar,v);
               return v>>
       else if not atom car u
        then rerror(alg,25,"Invalid syntax: improper assignment");
      u := car u . revlis cdr u;
      if null b
        then <<z:=assoc(u,wtl!*);
               if not(y := get(car u,'kvalue))
                  or not (x := assoc(u,y))
                 then << if null z then 
                            msgpri(nil,u,"not found",nil,nil)>>
                else put(car u,'kvalue,delete(x,y));
                if z then wtl!*:=delasc(u,wtl!*);
               return nil>>
       else if not (y := get(car u,'kvalue))
        then put!-kvalue(car u,nil,u,v)
       else <<if x := assoc(u,y)
                then <<updoldrules(u,v); y := delasc(car x,y)>>;
              put!-kvalue(car u,y,u,v)>>;
      return v
     end;

symbolic procedure put!-avalue(u,v,w);
 <<if smember(u,w)
     then msgpri(nil,u,"improperly defined in terms of itself",nil,nil);
   put(u,'avalue,{v,w})>>;

symbolic procedure put!-kvalue(u,v,w,x);
 <<if smember(w,x)
     then msgpri(nil,w,"improperly defined in terms of itself",nil,nil);
   put(u,'kvalue,aconc(v,{w,x}))>>;

% 22 Feb 94, 5 May 94.

symbolic procedure setk0(u,v);
   begin scalar x;
      if not atom u
         and idp car u
         and ((x := getrtype u or get(car u,'rtype))
                and (x := get(x,'setelemfn))
               or (x := get(car u,'setkfn)))
        then <<alglist!* := nil . nil; apply2(x,u,v)>>
       else let2(u,v,nil,t);
      return v
   end;

symbolic procedure formlogterm(sf);
   begin scalar u;
      u := mvar sf;
      if not atom u and (car u member '(times sqrt expt nthroot))
         then u := addsq(simplog2 lc sf,
                         multsq!*(simplogi u,simp!* ldeg sf))
        else if (lc sf iequal 1) and (ldeg sf iequal 1)
         then u := ((mksp(list('log,sfchk u),1) .* 1) .+ nil) ./ 1
        else u := addsq(simptimes list(list('log,sfchk u),ldeg sf),
                        simplog2 lc sf);
      return u
   end;

symbolic procedure sfchk u; if sfp u then prepf u else u;

% 12 Mar 94, 7 May 94.

symbolic procedure setk(u,v);
   if not atom u
     then (if x then setk0(car u . apply1(x,cdr u),v) 
            else setk0(car u . revlis cdr u,v))
           where x=get(car u,'evalargfn)
    else setk0(u,v);

%  3 Apr 94.

symbolic procedure letexprn(u,v,w,x,b,flgg);
   % Replacement of scalar expressions.
   begin scalar y,z;
        if denr x neq 1
          then return let2(let!-prepf numr x,
                           list('times,let!-prepf denr x,v),w,b)
         else if red(x := numr x)
          then return let2(let!-prepf !*t2f lt x,
                           list('difference,v,let!-prepf red x),w,b)
         else if null (y := kernlp x)
          then <<y := term!-split x;
                 return let2(let!-prepf car y,
                            list('difference,v,let!-prepf cdr y),w,b)>>
         else if y neq 1
          then return let2(let!-prepf quotf!*(x,y),
                           list('quotient,v,let!-prepf y),w,b);
        x := klistt x;
        y := list(w . (if mcond!* then mcond!* else t),v,nil);
        if cdr x
          then return <<rmsubs(); !*match:= xadd!*(x . y,!*match,b)>>
         else if null w and cdar x=1    % ONEP
          then <<x := caar x;
                 if null flgg and (null mcond!* or mcond!* eq 't
                        or not smember(x,mcond!*))
                   then <<if atom x
                            then if flagp(x,'used!*) then rmsubs()
                                  else nil
                           else if 'used!* memq cddr fkern x
                            then rmsubs();
                          setk1(x,v,b)>>
                  else if atom x then return errpri1 u
                  else <<rmsubs(); % if get(car x,'klist) then rmsubs();
                                   % the "get" is always true currently.
                         put(car x,
                             'opmtch,
                           xadd!*(cdr x . y,get(car x,'opmtch),b))>>>>
         else <<rmsubs();
                if v=0 and null w and not flgg
                  then <<asymplis!* := xadd(car x,asymplis!*,b);
                         powlis!*
                      := xadd(caar x . cdar x . y,powlis!*,'replace)>>
                 else if w or not cdar y eq t or frasc!*
                  then powlis1!* := xadd(car x . y,powlis1!*,b)
                 else if null b and (z := assoc(caar x,asymplis!*))
                    and z=car x
                  then asymplis!* := delasc(caar x,asymplis!*)
              else <<powlis!* := xadd(caar x . cdar x . y,powlis!*,b);
                   if b then asymplis!* := delasc(caar x,asymplis!*)>>>>
   end;

% 21 Apr 94.

symbolic procedure simp u;
   (begin scalar x,y;
    % This case is sufficiently common it is done first.
    if fixp u
      then if u=0 then return nil ./ 1
            else if not dmode!* then return u ./ 1
            else nil
     else if u member varstack!* then recursiveerror u;
    varstack!* := u . varstack!*;
    if simpcount!*>simplimit!*
      then <<simpcount!* := 0;
             rerror(alg,12,"Simplification recursion too deep")>>
     else if eqcar(u,'!*sq) and caddr u and null !*resimp
      then return cadr u
     else if null !*uncached and (x := assoc(u,car alglist!*))
      then return <<if cadr x then !*sub2 := t; cddr x>>;
    simpcount!* := simpcount!*+1; % undone by returning through !*SSAVE.
    if atom u then return !*ssave(simpatom u,u)
     else if not idp car u
      then if idp caar u and (x := get(caar u,'name))
             then return !*ssave(u,u)     %%% not yet correct
            else if eqcar(car u,'mat)
                and numlis(x := revlis cdr u) and length x=2
             then return !*ssave(simp nth(nth(cdar u,car x),cadr x),u)
            else errpri2(u,t)
     else if flagp(car u,'opfn)
      then if null(y := getrtype(x := opfneval u))
             then return !*ssave(simp_without_resimp x,u)
            else if y eq 'yetunknowntype and null getrtype(x := reval x)
             then return simp x
            else typerr(u,"scalar")
     else if x := get(car u,'psopfn)
      then if getrtype(x := apply1(x,cdr u)) then typerr(u,"scalar")
        else if x=u then return !*ssave(!*k2q x,u)
        else return !*ssave(simp_without_resimp x,u)
     % Note in above that the psopfn MUST return a *sq form,
     % otherwise an infinite recursion occurs.
     else if x := get(car u,'polyfn)
      then return
        <<argnochk u;
          !*ssave(!*f2q lispapply(x,
                            for each j in cdr u collect !*q2f simp!* j),
                  u)>>
     else if get(car u,'opmtch)
        and not(get(car u,'simpfn) eq 'simpiden)
        and (x := opmtch revop1 u)
      then return !*ssave(simp x,u)
     else if x := get(car u,'simpfn)
      then return !*ssave(apply1(x,
                                 if x eq 'simpiden or flagp(car u,'full)
                                   then u
                                 else cdr u),
                          u)
     else if (x := get(car u,'rtype)) and (x := get(x,'getelemfn))
      then return !*ssave(simp apply1(x,u),u)
     else if flagp(car u,'boolean) or get(car u,'infix)
      then typerr(if x := get(car u,'prtch) then x else car u,
              "algebraic operator")
     else if flagp(car u,'nochange)
      then return !*ssave(simp lispeval u,u)
     else if get(car u,'psopfn) or get(car u,'rtypefn)
      then typerr(u,"scalar")
     else <<redmsg(car u,"operator");
        mkop car u;
        varstack!* := delete(u,varstack!*);
        return !*ssave(simp u,u)>>;
   end) where varstack!* = varstack!*;

% 25 Nov 93, 24 Apr 94.

symbolic procedure exptunwind(u,v);
   % u is a standard form, v a list of powers.
   % result is a standard form of product(v) * u.
   % This function is the key to a better treatment of surds.
   begin scalar x,x1,x2,y,z,z2;
  a:  if null v then return u;
      x := caar v;    % kernel in EXPT
      x1 := cadr x;   % expression
      x2 := caddr x;  % exponent
      y := cdar v;   % power
      v := cdr v;
      while (z := assocp1(x1,v)) and
         (z2 := simp {'plus,{'times,x2,y},{'times,caddar z,cdr z}})
        do <<if fixp numr z2 
               then <<x2 := divide(numr z2,denr z2);
                      if car x2>0
                        then <<u := multpf(mksp(x1,car x2),u);
                               z2 := cdr x2 ./ denr z2>>;
                      y := numr z2>>
              else if domainp numr z2 then y := 1
              else <<y := lnc cdr comfac numr z2;
                     if not fixp y then y := 1>>;
             x2 := prepsq(quotf(numr z2,y) ./ denr z2);
             v := delete(z,v)>>;
      if y=1 and fixp x1 then   % Is y=1 necessary?
         <<while (z := assocp2(x2,v)) and cdr z=1 and fixp cadar z do
              <<x1 := cadar z * x1; v := delete(z,v)>>;
           if eqcar(x2,'quotient) and fixp cadr x2 and fixp caddr x2
             then <<z := nrootn(x1**cadr x2,caddr x2);
                    if cdr z = 1 then u := multd(car z,u)
                     else if car z = 1
                      then u := multf(formsf(x1,x2,1),u)
                     else <<u := multd(car z,u);   % Iterate again.
                            v := (list('expt,cdr z,x2) . 1) . v>>>>
            else u := multf(formsf(x1,x2,y),u)>>
       else u := multf(formsf(x1,x2,y),u);
      go to a
   end;

% 29 Apr 94.

symbolic procedure simpexpon u;
   simpexpon1(u,'simp!*);

symbolic procedure simpexpon1(u,v);
   if !*numval and (dmode!* eq '!:rd!: or dmode!* eq '!:cr!:) 
     then apply1(v,u)
    else begin scalar dmode!*,alglist!*; return apply1(v,u) end;

symbolic procedure simpexpt u;
   begin scalar expon;
      expon := simpexpon carx(cdr u,'expt) where kord!*=nil;
      % We still need the right order, else
      % explog := {sqrt(e)**(~x*log(~y)/~z) => y**(x/z/2)};
      % on ezgcd,gcd; let explog; fails.
      expon := simpexpon1(expon,'resimp);
      return simpexpt1(car u,expon,nil)
   end;

%  5 May 94.

symbolic procedure wtlevel u;
   begin integer n; scalar x;
      n := reval car u;
      if not(fixp n and n>=0) then errpri2(n,'hold);
      n := n+1;
      x := atsoc('k!*,asymplis!*);
      if null x then nil
       else if n=cdr x then return nil
       else if n<=cdr x then rmsubs();
      asymplis!* := ('k!* . n) . delasc('k!*,asymplis!*)
   end;

% 25 May 94.

symbolic procedure geteleval u; getel eval carx(u,'getel);

put('getel,'psopfn,'geteleval);

% 14 Jun 94.

symbolic procedure subsublis(u,v);
   begin scalar x;
      return if x := assoc(v,u) then cdr x
              else if eqcar(v,'sqrt)
                 and (x := assoc(list('expt,cadr v,'(quotient 1 2)),u))
               then cdr x
              else if atom v then v
              else if not idp car v
               then for each j in v collect subsublis(u,j)
              else if x := get(car v,'subfunc) then apply2(x,u,v)
              else if get(car v,'dname) then v
              else if car v eq '!*sq then subsublis(u,prepsq cadr v)
              else for each j in v collect subsublis(u,j)
   end;

% 29 Jun 94.

symbolic procedure coeff1(u,v,w);
   (begin scalar !*factor,bool,x,y,z;
        if eqcar(u,'!*sq) and null !*exp
          then <<!*exp := t; u := resimp cadr u>>
         else <<!*exp := t; u := simp!* u>>;
        v := !*a2kwoweight v;
        bool := !*ratarg or freeof(prepf denr u,v);
        if null bool then u := !*q2f u;
        x := updkorder v;
        if null bool then <<y := reorder u; u := 1>>
         else <<y := reorder numr u; u := denr u>>;
        setkorder x;
        if null y then go to a;
        while not domainp y and mvar y=v
           do <<z := (ldeg y . !*ff2a(lc y,u)) . z; y := red y>>;
        if null y then go to b;
    a:  z := (0 . !*ff2a(y,u)) . z;
    b:  lowpow!* := caar z;
        z := reverse z;
        hipow!* := caar z;
        z := multiple!-result(z,w);
        return if null w then z else hipow!*
   end) where !*exp = !*exp;

%  1 Jul 94.

symbolic procedure simpexpt2(u,n,flg);
   begin scalar m,n,x,y;
    if u=1 then return 1 ./ 1
     else if fixp u and u>0 and (u<10000 or !*ifactor)
       and (length(x := zfactor u)>1 or cdar x>1)
      then <<y := 1 ./ 1;
             for each j in x do
                y := multsq(simpexpt list(car j,
                                          prepsq multsq(cdr j ./ 1,n)),
                            y);
             return y>>;
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
     else if car u eq 'quotient and not !*precise
      then <<if not flg and !*mcd then
                return simpexpt1(prepsq simp!* u,n,t);
             n := prepsq n;
             return multsq(simpexpt list(cadr u,n),
                           simpexpt list(caddr u,list('minus,n)))>>>>;
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

% 13 Sep 94.

symbolic procedure remove!-free!-vars!-l u;
   if atom u then u
    else if car u eq '!*sq then remove!-free!-vars!-l prepsq!* cadr u
    else (if x=u then u else x)
         where x=remove!-free!-vars car u . remove!-free!-vars!-l cdr u;

% 22 Oct 94.

symbolic procedure permp(u,v);
   if null u then t
    else if car u=car v then permp(cdr u,cdr v)
    else not permp(cdr u,subst(car v,car u,cdr v));

% 19 Nov 94.

symbolic procedure lengthreval u;
   begin scalar v,w,x;
      if length u neq 1
        then rerror(alg,11,
                    "LENGTH called with wrong number of arguments");
      u := car u;
      if idp u and arrayp u then return 'list . get(u,'dimension);
      v := aeval u;
      if (w := getrtype v) and (x := get(w,'lengthfn))
        then return apply1(x,v)
       else if atom v then return 1
       else if not idp car v or not(x := get(car v,'lengthfn))
        then if w
          then lprie list("LENGTH not defined for argument of type",w)
         else typerr(u,"LENGTH argument")
       else return apply1(x,cdr v)
   end;

put('equation,'lengthfn,'eqnlength);

symbolic procedure eqnlength u;
   length cdr u;

symbolic procedure revalpart u;
   begin scalar !*intstr,expn,v,z;
      !*intstr := t;   % To make following result in output form.
      expn := if (z := getrtype car u) eq 'list then listeval0 car u
               else reval car u;
      !*intstr := nil;
      v := cdr u;
      while v do
         begin scalar x,y;
           if atom expn then parterr(expn,car v)
            else if not numberp(x := reval car v)
             then msgpri("Invalid argument",car v,"to part",nil,t)
            else if (y := get(car expn,'partop))
             then return <<expn := apply2(y,expn,x); v := cdr v>>
            else if x=0
              then return <<expn :=
                              (if (getrtype w eq 'list) and (z := 'list)
                                 then listeval0 w
                                else if z eq 'list
                                 then <<!*intstr := t; w := reval w;
                                        !*intstr := z := nil; w>>
                                else w) where w = car expn;
                           v := nil>>
            else if x<0 then <<x := -x; y := reverse cdr expn>>
            else y := cdr expn;
           if length y<x then parterr(expn,car v)
            else expn := (if (getrtype w eq 'list) and (z := 'list)
                            then listeval0 w
                           else if z eq 'list
                            then <<!*intstr := t; w := reval w;
                                   !*intstr := z := nil; w>>
                           else w) where w = nth(y,x);
           v := cdr v
        end;
      return aeval expn
   end;

endpatch;


patch algint;

% 22 Dec 93.

symbolic procedure elliptic!-add(p1,p2,equation);
begin
  scalar x1,x2,y1,y2,x3,y3,inf,a,b,lhs,rhs;
  a:=car equation;
  b:=cdr equation;
  inf:=!*kk2q 'infinite;
  x1:=car p1;
  y1:=cdr p1;
  x2:=car p2;
  y2:=cdr p2;
  if x1 = x2
    then if y1 = y2
      then <<
    % this is the doubling case.
    x3:= multsq(4 ./ 1,
                !*addsq(b,!*multsq(x1,!*addsq(a, !*exptsq(x1,2)))));
    if null numr x3 then return inf . inf;
    % We doubled a point and got infinity. 
    x3:=!*multsq(!*addsq(!*addsq(!*multsq(a,a),
                     !*exptsq(x1,4)),
                 !*addsq(multsq(-8 ./ 1,!*multsq(x1,b)),
                     !*multsq(!*multsq(x1,x1),
                                              multsq(-2 ./ 1,a)))),
             !*invsq x3);
    y3:=!*addsq(y1,!*multsq(!*multsq(!*addsq(x3,negsq x1),
                     !*addsq(a,multsq(3 ./ 1,
                             !*multsq(x1,x1)))),
                 !*invsq multsq(2 ./ 1,
                                                y1))) >>
      else x3:=(y3:=inf)
    else if x1 = inf
      then <<
        x3:=x2;
        y3:=y2 >>
      else if x2 = inf
        then <<
          x3:=x1;
          y3:=y1 >>
        else <<
      x3:=!*multsq(!*addsq(!*multsq(a,!*addsq(x1,x2)),
                   !*addsq(multsq(2 ./ 1,b),
                       !*addsq(!*multsq(!*multsq(x1,x2),
                            !*addsq(x1,x2)),
                                               multsq(-2 ./ 1,
                            !*multsq(y1,y2))))),
               !*invsq !*exptsq(!*addsq(x1,negsq x2),2));
      y3:=!*multsq(!*addsq(!*multsq(!*addsq(y2,negsq y1),x3),
                   !*addsq(!*multsq(x2,y1),
                       !*multsq(x1,negsq y2))),
               !*invsq !*addsq(x1,negsq x2)) >>;
  if x3 = inf
    then return x3.y3;
  lhs:=!*multsq(y3,y3);
  rhs:=!*addsq(b,!*multsq(x3,!*addsq(a,!*multsq(x3,x3))));
  if numr !*addsq(lhs,negsq rhs) % We can't just compare them
                  % since they're algebraic numbers.
                  % JHD Jan 14th. 1987.
    then <<
      prin2t "Point defined by X and Y as follows:";
      printsq x3;
      printsq y3;
      prin2t "on the curve defined by A and B as follows:";
      printsq a;
      printsq b;
      prin2t "gives a consistency check between:";
      printsq lhs;
      printsq rhs;
      interr "Consistency check failed in elliptic!-add" >>;
  return x3.y3
  end;

%  5 Jun 94.

symbolic procedure simpexpt1(u,n,flg);
   % FLG indicates whether we have done a PREPSQ SIMP!* U or not: we
   % don't want to do it more than once.
   begin scalar m,x,y;
      if onep u then return 1 ./ 1;
      m := numr n;
      if m=1 and denr n=1 then return simp u;
     % this simplifies e^(n log x) -> x^n  for all n,x.
      if u eq 'e and domainp denr n and not domainp m and ldeg m=1
         and null red m and eqcar(mvar m,'log) then return
            simpexpt1(prepsq!* simp!* cadr mvar m,lc m ./ denr n,nil);
      if not domainp m or not domainp denr n
        then return simpexpt2(u,n,flg);
      x := simp u; 
      if null m
        then return if null numr x then rerror(alg,14,"0**0 formed")
                     else 1 ./ 1;
      % We could use simp!* here, except it messes up the handling of
      % gamma matrix expressions.
      return if null numr x
               then if minusp m then rerror(alg,15,"Zero divisor")
                     else nil ./ 1
              else if atom m and denr n=1 and domainp numr x
                 and denr x=1
               then if atom numr x and m>0 then !*d2q(numr x**m)
                     else <<x := !:expt(numr x,m) ./ 1;
                            %remove rationals where possible.
                            if !*mcd then resimp x else x>>
              else if y := domainvalchk('expt,list(x,n)) then y
              else if atom m and denr n=1
               then <<if not m<0 then exptsq(x,m)
                       else if !*mcd then invsq exptsq(x,-m)
                       else multf(expf(numr x,m),mksfpf(denr x,-m))
                               ./ 1>>     % This uses OFF EXP option.
                      % There may be a pattern matching problem though.
     % We need the subs2 in the next line to take care of power and
     % product simplification left over from the call of simp on u.
              else simpexpt2(if flg then u
                              else (prepsq!* subs2 x
                                       where !*sub2 = !*sub2),
                             n,t)
   end;

endpatch;


patch arith;

%  6 Dec 93.

symbolic procedure fl2bf x;
  (if zerop x then bfz!* else
   begin scalar s,r; integer d;
     if x<0 then <<x := -x; s := t>>;
     % convert x to an integer equivalent;
      r := normbf read!:num x;
      d := ep!: r+msd!: mt!: r;
      x := x*2.0**-d; x := x + 0.5/2**!:bprec!:;
      x := fix(x*2**!:bprec!:);
      return make!:ibf (if s then -x else x, d - !:bprec!:) end)
        where !:bprec!:=!!nbfpd;

% 22 Dec 93.

symbolic procedure erbdck u; nil;

% 30 Dec 93.

symbolic procedure bftrim!: v;
   normbf round!:mt(v,!:bprec!: - 3);

endpatch;


patch assist;

% 30 Jan 94.

symbolic procedure lowestdeg(u,v)$
% IT EXTRACTS THE LOWEST DEGREE IN V OUT OF THE POLYNOMIAL U.
% U is the POLYNOMIAL. V is an ID or a KERNEL.
begin scalar x,y,uu,vv;
    uu:=simp!* u$
% It is not yet clear if I should take into account purely numerical
% terms in the polynomial. I opted for YES but if one wants NO then
% it is enough to put a comment sign on the second return.
   if domainp uu then return 0;
    uu:=!*q2f uu;
    vv:=erase_pol_cst uu;
    if vv neq uu then return 0;
    vv:=!*a2k v;
    x:=setkorder list v;
    y:=reorder uu; setkorder x;
    y:=reverse y;
    uu:=mvar y;
    if not atom uu then if car uu eq 'expt then
         rederr("exponents must be integers")$
    if uu neq vv then return 0 else
        return  ldeg y end$

symbolic procedure erase_pol_cst u;
   % u is a standard form.
   if null u or numberp u then nil else lt u . erase_pol_cst red u;

endpatch;


% Excalc declarations.

global '(dimex!* naturalvector2framevector naturalframe2coframe
         coord!* basisforml!* dbaseform2base2form);

patch excalc;

symbolic procedure coframe1 u;
   begin scalar osubfg,scoord,v,y,w;
     osubfg := subfg!*;
     subfg!* := nil;
     v := for each j in u collect
            <<y := partitop j;
              scoord := pickupcoords(y,scoord);
              y>>;
     if null atom car scoord 
        then <<remflag({caar scoord},'covariant);
               scoord := for each j in scoord
                             collect mvar numr lc partitop j;
               v := for each j in u collect partitop j>>;
     if length scoord neq dimex!*
       then rerror(excalc,3,"badly formed basis");
     w := !*pf2matwrtcoords(v,scoord);
     naturalvector2framevector := v;
     subfg!* := nil;
     naturalframe2coframe := pair(scoord,
          for each j in lnrsolve(w,for each k in basisforml!*
                                       collect list !*k2q k)
              collect mk!*sqpf partitsq!* car j);
     subfg!* := osubfg;
     coord!* := scoord;
     dbaseform2base2form := pair(basisforml!*,
          for each j in v collect mk!*sqpf repartit exdfpf j)
   end;

endpatch;


% Ezgcd declarations.

fluid '(!*trfac !*trallfac alphavec bad!-case factor!-level
        factor!-trace!-list fhatvec image!-set max!-unknowns
        number!-of!-factors number!-of!-unknowns predictions
        reduced!-degree!-lclst residue unlucky!-case);

deflist('((factor!-trace
    (lambda (action)
      (prog (stream)
         (cond
            ((or !*trallfac (and !*trfac (equal factor!-level 1)))
               (setq stream (cons nil nil)))
            (t (setq stream (assoc factor!-level factor!-trace!-list))))
         (cond
            (stream
               (progn
                  (setq stream (wrs (cdr stream)))
                  action
                  (wrs stream)))))))),'smacro)$

patch ezgcd;

% 19 Feb 94.

symbolic procedure gcdlist31(l,vlist,gcont,gg,l1);
   begin scalar cofactor,lcg,old!-modulus,prime,w,w1,zeros!-list;
    old!-modulus:=set!-modulus nil; %Remember modulus;
    lcg:=for each poly in l collect lc poly;
    lcg:=gcdlist lcg;
try!-again:
    unlucky!-case:=nil;
    image!-set:=nil;
    set!-modulus(prime:=random!-prime());
    w:=l;
    if not zeros!-list then <<
      image!-set:=
         zeros!-list:=try!-max!-zeros!-for!-image!-set(w,vlist);
      >>;
    gg:=make!-image!-mod!-p(car w,car vlist);
    if unlucky!-case then <<
      go to try!-again >>;
    l1:=list(car w . gg);
make!-images:
    if null (w:=cdr w) then go to images!-created!-successfully;
    l1:=(car w . make!-image!-mod!-p(car w,car vlist)) . l1;
    if unlucky!-case then <<
      go to try!-again >>;
    gg:=gcd!-mod!-p(gg,cdar l1);
    if domainp gg then <<
      set!-modulus old!-modulus;
      return gcont >>;
    go to make!-images;
images!-created!-successfully:
    l1:=reversip l1; % Put back in order with smallest first;
    if ldeg gg=ldeg car l then <<
        gg:=poly!-abs car l;
        go to result >>
    else if (ldeg car l=add1 ldeg gg) and
            (ldeg car l=ldeg cadr l) then <<
        gg := poly!-gcd(lc car l,lc cadr l);
        gg := ezgcd!-pp addf(multf(red car l,
            quotfail1(lc cadr l,gg,
         "Division failure when just one pseudoremainder step needed")),
         multf(red cadr l,negf quotfail1(lc car l,gg,
         "Divison failure when just one pseudoremainder step needed")));
        go to result >>;
    w:=l1;
find!-good!-cofactor:
    if null w then go to special!-case; % No good cofactor available;
    if domainp gcd!-mod!-p(gg,cofactor:=quotient!-mod!-p(cdar w,gg))
      then go to good!-cofactor!-found;
    w:=cdr w;
    go to find!-good!-cofactor;
good!-cofactor!-found:
    cofactor:=monic!-mod!-p cofactor;
    w:=caar w;
    image!-set:=sort(image!-set,function ordopcar);
    gg:=reconstruct!-gcd(w,gg,cofactor,prime,image!-set,lcg);
    if gg='nogood then go to try!-again;
    go to result;
special!-case: % Here I have to do the first step of a PRS method;
    reduced!-degree!-lclst:=nil;
try!-reduced!-degree!-again:
    w1:=reduced!-degree(caadr l1,caar l1);
    w:=car w1; w1:=cdr w1;
    if not domainp w and
       (domainp w1 or ldeg w neq ldeg w1) then go to try!-again;
    if domainp w and not null w then <<
      set!-modulus old!-modulus; return gcont >>;
    if w and ldeg w = ldeg gg then <<
      gg:=w; go to result >>;
    if null w then <<
      l1:=(car l1 . cddr l1);  % discard second poly;
      if null cdr l1 then <<
         gg := poly!-abs caar l1;
         go to result >>;
      go to try!-reduced!-degree!-again >>;
    if ldeg w<=ldeg gg then <<
       gg := poly!-abs w;
       go to result >>
    else if domainp gcd!-mod!-p(gg,cofactor:=quotient!-mod!-p(w1,gg))
     then <<
       w := list list w;
       go to good!-cofactor!-found >>;
    l1:= if ldeg w <= ldeg caar l1 then
      ((w . w1) . (car l1 . cddr l1))
      else (car l1 . ((w . w1) . cddr l1));
    go to try!-reduced!-degree!-again;
result: % Here GG holds a tentative gcd for the primitive parts of
        % all input polys, and GCONT holds a proper one for the content;
    if division!-test(gg,l) then <<
      set!-modulus old!-modulus;
      return multf(gg,gcont) >>;
    go to try!-again
  end;

symbolic procedure solve!-for!-corrections(c,fhatvec,fvec,resvec,vset);
  if null vset then
    for i:=1:number!-of!-factors do
      putv(resvec,i,
        remainder!-mod!-p(
          times!-mod!-p(c,getv(alphavec,i)),
          getv(fvec,i)))
  else (lambda factor!-level; begin
    scalar residue,growth!-factor,f0s,fhat0s,v,
      degbd,first!-time,redc,
      predicted!-forms,max!-unknowns,solve!-count,number!-of!-unknowns,
      correction!-vectors,soln!-matrices,w,previous!-prediction!-holds,
      unknowns!-count!-list,poly!-remaining,
      prediction!-results,one!-prediction!-failed;
    v:=car vset;
    degbd:=get!-degree!-bound car v;
    first!-time:=t;
    growth!-factor:=make!-growth!-factor v;
    poly!-remaining:=c;
    prediction!-results:=mkvect number!-of!-factors;
    redc:=evaluate!-mod!-p(c,car v,cdr v);
    solve!-msg1(c,fvec,v);
    solve!-for!-corrections(redc,
      fhat0s:=reduce!-vec!-by!-one!-var!-mod!-p(
        fhatvec,v,number!-of!-factors),
      f0s:=reduce!-vec!-by!-one!-var!-mod!-p(
        fvec,v,number!-of!-factors),
      resvec,
      cdr vset); % Results left in RESVEC.
    if bad!-case then return;
    solve!-msg2(resvec,v);
    residue:=diff!-over!-k!-mod!-p(difference!-mod!-p(c,
          form!-sum!-and!-product!-mod!-p(resvec,fhatvec,
            number!-of!-factors)),1,car v);
    factor!-trace <<
      printsf residue;
      prin2!* " Now we shall put in the powers of ";
      prinsf growth!-factor;
      prin2!* " to find the a's fully."; terpri!* nil
    >>;
    if not null residue and not zerop cdr v then <<
      w:=atsoc(car v,predictions);
      if w then <<
        previous!-prediction!-holds:=t;
        factor!-trace <<
          prin2!*
             "We shall use the previous prediction for the form of";
          terpri!* nil;
          prin2!* "polynomials wrt "; printvar car v >>;
        w:=cdr w;
        soln!-matrices:=car w;
        predicted!-forms:=cadr w;
        max!-unknowns:=caddr w;
        number!-of!-unknowns:=cadr cddr w >>
      else <<
        factor!-trace <<
     prin2!*
        "We shall use a new prediction for the form of polynomials ";
        terpri!* nil;
        prin2!* "wrt "; printvar car v >>;
        predicted!-forms:=mkvect number!-of!-factors;
        for i:=1:number!-of!-factors do
          putv(predicted!-forms,i,getv(fvec,i));
            % Make a copy of the factors in a vector we shall overwrite.
        make!-predicted!-forms(predicted!-forms,car v);
            % Sets max!-unknowns and number!-of!-unknowns.
        >>;
      solve!-msg3();
      unknowns!-count!-list:=number!-of!-unknowns;
      while unknowns!-count!-list and
         (car (w:=car unknowns!-count!-list))=1 do
        begin scalar i,r,wr,fi;
          unknowns!-count!-list:=cdr unknowns!-count!-list;
          i:=cdr w;
          w:=quotient!-mod!-p(
            wr:=difference!-mod!-p(poly!-remaining,
              times!-mod!-p(r:=getv(resvec,i),getv(fhatvec,i))),
            fi:=getv(fvec,i));
          if null w or not null
            difference!-mod!-p(wr,times!-mod!-p(w,fi)) then
            if one!-prediction!-failed then <<
              factor!-trace <<prin2!* "Predictions are no good.";
                              terpri!* nil>>;
              max!-unknowns:=nil >>
            else <<
              factor!-trace <<
                prin2!* "Guess for a(";
                prin2!* i;
                prin2!* ") was bad."; terpri!* nil >>;
              one!-prediction!-failed:=i >>
          else <<
            putv(prediction!-results,i,r);
            factor!-trace <<
              prin2!* "Prediction for a("; prin2!* i;
              prin2!* ") worked: ";
              printsf r >>;
            poly!-remaining:=wr >>
        end;
      w:=length unknowns!-count!-list;
      if w=1 and not one!-prediction!-failed then <<
        putv(resvec,cdar unknowns!-count!-list,
          quotfail!-mod!-p(poly!-remaining,getv(fhatvec,
            cdar unknowns!-count!-list)));
        go to exit >>
      else if w=0 and one!-prediction!-failed and max!-unknowns then <<
        putv(resvec,one!-prediction!-failed,
          quotfail!-mod!-p(poly!-remaining,getv(fhatvec,
            one!-prediction!-failed)));
        go to exit >>;
      solve!-count:=1;
      if max!-unknowns then
        correction!-vectors:=
           make!-correction!-vectors(resvec,max!-unknowns) >>;
    if not null residue then first!-time:=nil;
    return multihen1(list(residue,
                            growth!-factor,
                            first!-time,
                            fhat0s,
                            f0s,
                            vset,
                            solve!-count,
                            correction!-vectors,
                            unknowns!-count!-list,
                            resvec,
                            v,
                            degbd,
                            soln!-matrices,
                            predicted!-forms,
                            poly!-remaining,
                            prediction!-results,
                            fvec,
                            previous!-prediction!-holds,
                            one!-prediction!-failed),
                            t);
exit:
      multihen!-exit(first!-time,resvec,t);
  end) (factor!-level+1);

endpatch;

remprop('factor!-trace,'smacro)$


% Gentran declarations.

fluid '(!*double !*gentranopt !*gentranseg maxint);

global '(!*currout!* !*posn!* fortlinelen!* gentranlang!*);

patch gentran;

% 11 Jan 94.

symbolic procedure gentran(forms, flist);
begin scalar !:print!-prec!: ; % Gentran ignores print_precision
if flist then
    lispeval list('gentranoutpush, list('quote, flist));
forms := preproc list forms;
gentranparse forms;
forms := lispcode forms;
if !*gentranopt then forms := opt forms;
if !*gentranseg then forms := seg forms;
apply1(get(gentranlang!*,'formatter) or get('fortran,'formatter),
       apply1(get(gentranlang!*,'codegen) or get('fortran,'codegen),
              forms));
if flist then
<<
    flist := car !*currout!* or ('list . cdr !*currout!*);
    lispeval '(gentranpop '(nil));
    return flist
>>
else
    return car !*currout!* or ('list . cdr !*currout!*)
end$

symbolic procedure mkffortliteral args;
   begin scalar !*lower;
      return for each a in args conc
         if a eq 'tab!* then list mkforttab()
          else if a eq 'cr!* then list mkfortterpri()
          else if pairp a then fortexp a
          else list stripquotes a
   end$
 
symbolic procedure procforttem;
   begin scalar c, linelen, !*lower;
      linelen := linelength 150;
      c := procfortcomm();
      while c neq !$eof!$ do
         if c memq '(!F !f !S !s)
           then <<pprin2 c; c := procsubprogheading c>>
          else if c eq !$eol!$
           then <<pterpri(); c := procfortcomm()>>
         else if c eq '!; then c := procactive()
         else <<pprin2 c; c := readch()>>;
      linelength linelen
   end$
 
symbolic procedure formatfort lst;
begin scalar linelen,str,!*lower;
linelen := linelength 300;
!*posn!* := 0;
for each elt in lst do
    if pairp elt then lispeval elt
    else
    << 
        if fixp elt and (elt>maxint or elt<-maxint) then
           elt := cdr i2rd!* elt;
        str:=explode2 elt;
        if floatp elt then
           if !*double then
              if memq('!e,str)
                 then str:=subst('D,'!e,str)
                 else if memq('E,str) % some LISPs use E not e
                      then str:=subst('D,'E,str)
                      else str:=append(str,'(D !0))
           else if memq('!e,str) then
                   str:=subst('E,'!e,str);
           % get the casing conventions correct
        if !*posn!* + length str > fortlinelen!* then
            fortcontline();
        for each u in str do pprin2 u
    >>;
linelength linelen
end$
 
endpatch;


% Groebner declarations.

fluid '(groebroots!* groecontcount!*);

patch groebner;

% 1 Feb 94.

copyd('groesolvepolyv!*,'groesolvepolyv);

algebraic operator !&df;

symbolic procedure groesolvepolyv(p,var);
 if not smemq('df,p) then groesolvepolyv!*(p,var) else 
  begin scalar res,u;
    for each s in groebroots!* do 
       if 0=reval{'difference,p,car s} then res:=cdr s;
      if res then return res;
    p:=subst('!&df,'df,p); u:=subst('!&df,'df,var);
    res := groesolvepolyv!*(p,u);
    rmsubs();
    return subst('df,'!&df,res);
  end;

% 12 Apr 94.

groecontcount!* := 10;

endpatch; 


patch mathpr;

% 31 Dec 93.

if null getd 'reduce!-maprin then copyd('reduce!-maprin,'maprin);

% 22 Feb 94.

symbolic procedure setvars u;
   if atom u then nil
    else if car u memq '(setel setk setk0)
     then lispeval cadr u . setvars caddr u
    else if car u eq 'setq then cadr u . setvars caddr u
    else nil;

endpatch;


% matrix declarations.

fluid '(!*cramer);

patch matrix;

% 24 Jan 94.

symbolic procedure simpdet u;
   if !*cramer or !*rounded then detq matsm carx(u,'det)
    else bareiss!-det u;

% 6 Feb 94.

symbolic procedure rank!-eval u;
   begin scalar n;
      if cdr u then rerror(matrix,17,"Wrong number of arguments")
       else if getrtype (u := car u) eq 'matrix
         then return rank!-matrix matsm u
       else if null eqcar(u := aeval u,'list) then typerr(u,"matrix")
       else return rank!-matrix
         for each row in cdr u collect
           if not eqcar(row,'list)
               then rerror(matrix,15,"list not in matrix shape")
            else <<row := cdr row;
                   if null n then n := length row
                    else if n neq length row
                     then rerror(matrix,151,"list not in matrix shape");
                   for each j in row collect simp j>>
   end;

% 4 Mar 94.

symbolic procedure nullspace!-elim(m,vars);
  begin scalar c,s,x,w,arbvars,depvars,row,res,break;
     while vars and not break do
     <<for each p in m do 
        if domainp numr p then if numr p then break:=t %unsolvable
                                else m:=delete(p,m);
       if not break then
       <<x:=car vars; vars:=cdr vars; row:=nil;
            % select row with x as leading variable.
         for each p in m do 
           if null row and mvar numr p = x then row:=p;
            % if none, then x is a free variable.
        if null row then arbvars:=x.arbvars else
        <<m:=delete(row,m);
          c:=multsq(negf denr row ./1, 1 ./ lc numr row);
          row := multsq(row,c);
            % collect formula for x,
          depvars := (x . (red numr row ./ denr row)) . depvars;
            % and perform elimination with this row.
          m:=for each p in m collect
          <<if mvar numr p=x then
              <<p:=addsq(p, multsq(row,lc numr p ./ denr p));
                 % Simplification for non-numeric coefficients.
                if not domainp (w:=numr p) and not domainp lc w then 
                    p:=subs2!* p>>;
            p>>>>>>>>;
    if break then return nil;
         % Constuct solutions by assigning unit vectors to the
         % free variables and perform backsubstitution.
    for each x in arbvars do
    << s := for each y in arbvars collect
          (y . if y=x then 1 else 0);
       for each y in depvars do
       << s := (car y . prepsq (w:=subsq(cdr y,s))) . s>>;
       res := s . res>>;
    return res;
  end;

% 15 Jun 94.

symbolic procedure matsm!*1 u;
   begin
      u := 'mat . for each j in u collect
                     for each k in j
                         collect !*q2a(subs2 k where !*sub2=t);
      return u
   end;

symbolic procedure bareiss1(u,perm);
  begin scalar aa,c0,ci1,ci2,ik1,ij,kk1,kj,k1j,k1k1,
               ui,u1,x,k1col,kij,flg;
        integer k,k1,col,maxcol;
        %U1 points to K-1th row of U
        %UI points to Ith row of U
        %IJ points to U(I,J)
        %K1J points to U(K-1,J)
        %KJ points to U(K,J)
        %IK1 points to U(I,K-1)
        %KK1 points to U(K,K-1)
        %K1K1 points to U(K-1,K-1)
        %M in comments is number of rows in U
        %N in comments is number of columns in U.
        maxcol := length(u);
        aa := 1;
        k := 2;
        k1 := 1;
        u1 := u;
        go to pivot;
   agn: u1 := cdr u1;
        if null cdr u1 or null cddr u1
          then return if perm and cdr u1 
                         and null car(ij := pnth(nth(u,maxcol),maxcol))
                 then if not allnils cdr ij then nil else (maxcol-1) . u
                 else maxcol . u;
        aa := nth(car u1,k);              % aa := u(k,k).
        k := k+2;
        k1 := k-1;
        u1 := cdr u1;
   pivot:  %pivot algorithm;
        col := k1;
        k1j := k1k1 := pnth(car u1,k1);
  piv1: k1col := pnth(car(u1), col);
        if car k1col then go to l2;
        ui := cdr u1;                    % i := k.
   l:   if null ui then
           if perm
             then if col>=maxcol
                     then <<flg := t;
                            while flg and u1 do
                               <<if not allnils pnth(car u1,maxcol+1)
                                   then flg := nil;
                                 u1 := cdr u1>>;
                            return if null flg then nil
                                    else (k1-1) . u>>
                   else <<col := col+1; go to piv1>>
            else return nil
        else if null car(ij := pnth(car ui,col)) then go to l1;
   l0:  if null ij then go to l2;
        x := car ij;
        rplaca(ij,negf car k1col);
        rplaca(k1col,x);
        ij := cdr ij;
        k1col := cdr k1col;
        go to l0;
   l1:  ui := cdr ui;
        go to l;
   l2:  swapcolumns(u, k1, col, perm);
        col := k;
  piv2: ui := cdr u1;                    % i:= k.
   l21: if null ui then
           if perm then
              if col>=maxcol then <<
                 flg := t;
                 while flg and u1 do <<
                    ik1 := pnth(car(u1), k1);
                    ij := pnth(ik1, maxcol-k1+2);
                    kij := pnth(k1k1, maxcol-k1+2);
                    while flg and ij do
                       if subs2chk addf(multf(car(k1k1),car(ij)),
                                        multf(car(ik1),negf(car(kij))))
                         then flg := nil
                        else ij := cdr(ij);
                    u1 := cdr u1>>;
                 return if flg then (k-1) . u else nil>>
                         else <<col := col+1; go to piv2>>
            else return nil;
        ij := pnth(car ui,k1);
        c0 := addf(multf(car k1k1,nth(ij, col-k+2)),
                  multf(nth(k1k1, col-k+2),negf car ij));
        if subs2chk c0 then go to l3;
        ui := cdr ui;                    % i:= i+1.
        go to l21;
   l3:  swapcolumns(u,k,col,perm);
        c0 := subs2chk quotf!*(c0,aa);
        kk1 := kj := pnth(cadr u1,k1);  % kk1 := u(k,k-1).
        if cdr u1 and null cddr u1 then go to ev0
         else if ui eq cdr u1 then go to comp;
   l31: if null ij then go to comp;     % if i>n then go to comp.
        x := car ij;
        rplaca(ij,negf car kj);
        rplaca(kj,x);
        ij := cdr ij;
        kj := cdr kj;
        go to l31;
    comp:
        if null cdr u1 then go to ev;
        ui := cddr u1;                   % i:= k+1.
    comp1:
        if null ui then go to ev;       % if i>m then go to ev.
        ik1 := pnth(car ui,k1);
        ci1 := quotf!*(addf(multf(cadr k1k1,car ik1),
                            multf(car k1k1,negf cadr ik1)),
                       aa);
        ci2 := quotf!*(addf(multf(car kk1,cadr ik1),
                            multf(cadr kk1,negf car ik1)),
                       aa);
        if null cddr k1k1 then go to comp3; % if j>n then go to comp3.
        ij := cddr ik1;                  % j := k+1.
        kj := cddr kk1;
        k1j := cddr k1k1;
    comp2:
        if null ij then go to comp3;
        rplaca(ij,subs2chk quotf!*(addf(multf(car ij,c0),
                                        addf(multf(car kj,ci1),
                                             multf(car k1j,ci2))),
                                   aa));
        ij := cdr ij;
        kj := cdr kj;
        k1j := cdr k1j;
        go to comp2;
    comp3:
        ui := cdr ui;
        go to comp1;
    ev0:if null c0 then return;
    ev: kj := cdr kk1;
        x := cddr k1k1;                 % x := u(k-1,k+1).
        rplaca(kj,c0);
    ev1:kj:= cdr kj;
        if null kj then go to agn;
        rplaca(kj,subs2chk quotf!*(addf(multf(car k1k1,car kj),
                                        multf(car kk1,negf car x)),
                                   aa));
        x := cdr x;
        go to ev1
   end;

%  6 Oct 94.

symbolic procedure matinv u;
   begin scalar sgn,x,y,z,!*exp;
     integer l,m,lm;
     !*exp := t;
     z := 1;
     lm := length car u;
     for each v in u do
       <<y := 1;
     for each w in v do y := lcm(y,denr w);
     m := lm;
     x := list(nil . (l := l + 1)) .* negf y .+ nil;
     for each j in reverse v do
       <<if numr j then
        x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
         m := m - 1>>;
     z := c!:extmult(x,z)>>;
      if singularchk lpow z then rerror(matrix,13,"Singular matrix");
     sgn := evenp length lpow z;
      return for each k in lpow z collect
          <<sgn := not sgn;
            for each j in lpow z collect mkglimat(k,z,sgn,j)>>
   end;

%  6 Oct 94, 10 Oct 94.

symbolic procedure bareiss!-det u;
   begin scalar nu,bu,n,!*exp;
     !*exp := t;
     nu := matsm car u;
     n := length nu;
      for each x in nu do
        if length x neq n then rederr "Non square matrix";
     if n=1 then return caar nu;
     nu := normmat nu;
     bu := bareiss1(car nu,nil);
     return if bu then cancel(nth(nth(bu,n+1),n) ./ cdr nu)
             else nil ./ 1
   end;

endpatch;


patch misc;

%  2 May 94.

symbolic procedure simp!-sum u;
   begin scalar v,y,upper,lower,lower1,dif;
      y := cdr u;
      u := simp!* car u;
      if null numr u then return (nil ./ 1)
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
          if dif and dif <= 0 then return nil ./ 1;
          if atom cddr y then upper := nil>>;
      v := !*a2k car y;
      return simp!-sum1(u,v,y,upper,lower,lower1,dif)
   end;

endpatch;


patch numeric;

% 20 Apr 94.

symbolic procedure switch!-mode!-rd u;
  begin scalar oldmode,prec,ne;
  if null u then
    <<if not memq(dmode!*,'(!:rd!: !:cr))then
       <<oldmode:=t; setdmode('rounded,t)>>;
     ne := !*noequiv;
     !*noequiv:=t; prec:=precision 0;
     switch!-mode!-rd!-alg 0;
     return list(oldmode,prec,!*roundbf,ne)
    >> else <<
     if car u then setdmode('rounded,nil);
     precision cadr u;
     !*roundbf := caddr u;
     !*noequiv := cadddr u;
     switch!-mode!-rd!-alg 1;
    >>;
  end;

endpatch;


patch orthovec;

% 31 Dec 93.

symbolic procedure maprin u;
   if vectorp u then ov!-maprin u else reduce!-maprin u;

symbolic procedure ov!-maprin u;
   % vectors.
   if vectorp(u) then
     <<prin2!* '[ ;
       for ic:=0:(upbv(u)-1)
           do <<maprint(getv(u,ic),0); oprin '!*comma!* >>;
       maprint(getv(u,upbv(u)),0);
       prin2!* '] >>
   % otherwise original form of maprin.
   else maprint(u,0);

endpatch;


patch pm;

% 30 Jan 94.

symbolic procedure ar4(lst,fn);
   begin scalar s, u, v, w;
      u := caar lst; v := cadar lst; w := caddar lst; lst := cdr lst;
      while u <= v do
      << s := append(s,list u);
         u := u + w>>;
         return if length(lst)=0 then
            if fn eq 'list then 'list . s
            else  map1(fn, 'list . s, 1)
         else 'list . for each j in cdr map1(list(lst, fn),'list . s, 1)
                         collect ar4(car j, cdr j);
   end;

endpatch;


% poly declarations.

fluid '(gdmode!*);

patch poly;

% 25 Jan 94.

switch centered_mod;

put('centered_mod,'simpfg,
    '((t (lprim
            "Please use balanced_mod instead (User's Manual is wrong)")
         (setq !*balanced_mod t))
      (nil (setq !*balanced_mod nil))));

symbolic procedure quotf!*(u,v);
   % We do the rationalizesq step to allow for surd divisors.
   if null u then nil
    else (if x then x
           else (if denr y = 1 then numr y
                  else errach list("DIVISION FAILED",u,v))
                 where y=rationalizesq(u ./ v))
          where x=quotf(u,v);

% 23 Feb 94.

symbolic procedure simprepart u;
   repartsq simp!* car u where !*factor = nil;

symbolic procedure simpimpart u;
   impartsq simp!* car u where !*factor = nil;

symbolic procedure splitcomplex u;
   (begin scalar v;
      v := if idomainp() then expand!-imrepart u
            else <<setkorder('i . kord!*);
                   subs2 expand!-imrepart reorder u>>;
      return take!-realpart v . take!-impart v
    end) where kord!* = kord!*,!*exp = t;

% 13 Mar 94.

symbolic procedure exptsq(u,n);
   begin scalar x;
        if n=1 then return u
         else if n=0
           then return if null numr u
                         then rerror(poly,4," 0**0 formed")
                        else 1 ./ 1
         else if null numr u then return u
         else if n<0 then return simpexpt list(mk!*sq u,n)
         else if null !*exp
          then return mksfpf(numr u,n) ./ mksfpf(denr u,n)
         else if kernp u then return mksq(mvar numr u,n)
         else if domainp numr u
          then return multsq(!:expt(numr u,n) ./ 1,
                             1 ./ exptf(denr u,n))
         else if denr u=1 then return exptf(numr u,n) ./ 1;
        x := u;
        while (n := n-1)>0
           do x := multf(numr u,numr x) ./ multf(denr u,denr x);
        return canonsq x
   end;

symbolic procedure canonsq u;
   if denr u=1 then u
    else if null numr u then nil ./ 1
    else begin scalar x,y;
       if asymplis!* and ((x := gcdf(numr u,denr u)) neq 1)
         then u := quotf(numr u,x) ./ quotf(denr u,x);
        x := lnc denr u;
        if x=1 then return u
         else if atom x then if minusp x
                               then <<u := negf numr u ./ negf denr u;
                                      x := -x>>
                              else nil
         else if apply1(get(car x,'minusp),x)
                               then <<u := negf numr u ./ negf denr u;
                                      x:= apply2(get(car x,'difference),
                                              apply1(get(car x,'i2d),0),
                                                     x)>>;
      return if not numberp x and (y := get(dmode!*,'unitsfn))
            then apply2(y,u,x)
         else if flagp(dmode!*,'field)
            or not atom x and flagp(car x,'field) then fieldconv(x,u)
         else u
   end;

% 8 Apr 94.

symbolic procedure subs3t(u,v);
   % U is a standard term, V a list of matching templates.
   % Value is a standard quotient for the substituted term.
   begin scalar bool,w,x,y,z;
        x := mtchk(car u,if domainp cdr u then sizchk(v,1) else v);
        if null x then go to a                  %lpow doesn't match;
         else if null caar x then go to b;      %complete match found;
        y := subs3f1(cdr u,x,nil);              %check tc for match;
        if mchfg!* then return multpq(car u,y);
    a:  return list u . 1;                      %no match;
    b:  x := cddar x;           %list(<subst value>,<denoms>);
        z := caadr x;           %leading denom;
        mchfg!* := nil;         %initialize for tc check;
        y := subs3f1(cdr u,!*match,nil);
        mchfg!* := t;
        if car z neq caar u then go to e
         else if z neq car u    %powers don't match;
          then y := multpq(caar u .** (cdar u-cdr z),y);
    b1: y := multsq(simpcar x,y);
        x := cdadr x;
        if null x then return y;
        z := 1;                 %unwind remaining denoms;
    c:  if null x then go to d;
        w:= if atom caar x or sfp caar x then caar x else
             ((lambda ww;
                if kernp ww and eqcar(ww := mvar numr ww,car caar x)
                  then ww
                 else revop1 caar x)
               (simp caar x) where subfg!* = nil);
        % In the non-commutative case we have to be very careful about
        % order of terms in a product. Introducing negative powers
        % solves this problem.
        if noncomp w or not !*mcd then bool := t;
%       z := multpf(mksp(w,if null bool then cdar x else -cdar x),z);
%       original line
        z := multf(z,!*p2f mksp(w,
                                if null bool then cdar x else -cdar x));
        % kernel CAAR X is not unique here. Earlier versions used just
        % CAAR X, but this leads to sums of terms in the wrong order.
        % The code here is probably still not correct in all cases, and
        % may lead to unbounded calculations. Maybe SIMP should be used
        % instead of REVOP1, with appropriate adjustments in the code
        % to construct Z.
        x := cdr x;
        go to c;
    d:  return if not bool then car y . multf(z,cdr y)
                else multf(z,car y) . cdr y;
    e:  if simp car z neq simp caar u then errach list('subs3t,u,x,z);
        %maybe arguments were in different order, otherwise it's fatal;
        if cdr z neq cdar u
          then y:= multpq(caar u .** (cdar u-cdr z),y);
        go to b1
   end;

% 17 May 94.

symbolic procedure setdmode1(u,bool);
   begin scalar x,y,z;
      x := get(u,'tag);
      y := dmode!*;
      if null bool
        then return if null y then nil
                     else if u eq (y := get(y,'dname))
                      then <<rmsubs(); gdmode!* := dmode!* := nil; y>>
                     else offmoderr(u,y)
        else <<if u memq '(rounded complex!-rounded) then !!mfefix();
               if x eq y then return x>>;
      if not (z := get(x,'realtype)) then z := x;
      for each j in domainlist!* do
         if j neq '!:gi!: and not(j eq z)
           then set(intern compress
                       append(explode '!*,explode get(j,'dname)),
                    nil);
      rmsubs();
      y := get(y,'dname);
      if y then lprim list("Domain mode",y,"changed to",u);
      gdmode!* := dmode!* := x;
      return y
   end;

symbolic procedure deg(u,kern);
   <<u := simp!* u; tstpolyarg(denr u,u); numrdeg(numr u,kern)>>
   where dmode!* = gdmode!*;

% 11 Jun 94.

symbolic procedure conjcubic(u,v);
   begin scalar c1,c2,c3;
     if ldeg u = 2 then <<c1 := reorder lc u;
                           if degr(red u,v) = 1
                              then <<c2 := reorder lc red u;
                                     c3 := reorder red red u>>
                            else c3 := reorder red u>>
      else <<c2 := reorder lc u;
             c3 := reorder red u>>;
     u := conj2 v;
     v := !*k2f v;
     return addf(multf(exptf(v,2),subtrf(exptf(c2,2),multf(c1,c3))),
                 addf(multf(v,subtrf(multf(u,exptf(c1,2)),
                                     multf(c2,c3))),
                      subtrf(exptf(c3,2),multf(u,multf(c1,c2)))))
  end;

symbolic procedure conj2 u;
   (if not domainp denr v then errach list("conj2",u)
     else if denr v neq 1 then multd(!:recip denr v,numr v)
     else numr v)
   where v = simp cadr u;

symbolic procedure conjquartic(u,v);
   begin scalar c1,c3,c4,q1,q2,q3,q4;
     if ldeg u = 3
        then <<c1 := reorder lc u;
               if degr(red u,v) = 1
                  then <<c3 := reorder lc red u;
                         c4 := reorder red red u>>
                else c4 := reorder red u>>
      else if ldeg u = 1
              then <<c3 := reorder lc u;
                     c4 := reorder red u>>;
     u := conj2 v;
     v := !*k2f v;
     q1 := subtrf(addf(exptf(c3,3),multf(c1,exptf(c4,2))),
                  multf(u,multf(c3,exptf(c1,2))));
     q2 := negf addf(multf(u,multf(c4,exptf(c1,2))),
                     multf(exptf(c3,2),c4));
     q3 := addf(multf(c3,exptf(c4,2)),
                subtrf(multf(exptf(u,2),exptf(c1,3)),
                       multf(u,multf(c1,exptf(c3,2)))));
     q4 := subtrf(multf(u,multf(multd(2,c1),multf(c3,c4))),exptf(c4,3));
     return addf(multf(exptf(v,3),q1),
                 addf(multf(exptf(v,2),q2),addf(multf(v,q3),q4)))
    end;

% 18 Jun 94.

symbolic procedure fctrf1 u;
   begin scalar x,y,z;
      if domainp u then return list u;  % Do this again just in case.
      if flagp(dmode!*,'field) and ((z := lnc u) neq 1)
         then u := multd(!:recip z,u)
       else if dmode!* and (y := get(dmode!*,'unitsfn))
         then <<x := apply2(y,1 . u,lnc u);
                u := cdr x;
                z := !:recip car x>>;
      x := comfac u;
      u := quotf(u,comfac!-to!-poly x);
      y := fctrf1 cdr x;   % factor the content.
      if car x then y := car y . (!*k2f caar x . cdar x) . cdr y;
      if z and (z neq 1) then y := multd(z,car y) . cdr y;
      if domainp u then return multf(u,car y) . cdr y
       else if minusf u
        then <<u := negf u; y := negf car y . cdr y>>;
      return fac!-merge(factor!-prim!-f u,y)
   end;

%  2 Jul 94.

symbolic procedure quadraticf1(a,b,c);
   begin scalar a1,denom,discrim,w;
      if null b and minusf c and not minusf a
       then <<a := rootxf(a,2);
              c := rootxf(negf c,2);
              return if a eq 'failed or c eq 'failed then 'failed
                      else list(1,a,c,a,negf c)>>;
      discrim := powsubsf addf(exptf(b,2),multd(-4,multf(a,c)));
      if null discrim then nil
       else <<if knowndiscrimsign
                then <<if knowndiscrimsign eq 'negative
                         then return 'failed>>
               else if minusf discrim then return 'failed;
             discrim:=rootxf(discrim,2);
             if discrim='failed then return discrim>>;
      denom := multd(4,a);
      a := a1 := multd(2,a);
      w := addf(b,discrim);
      c := addf(b,negf discrim);
      b := w;
      if (w := gcdf(a,b)) neq 1 
        then <<a1 := quotf(a,w); b := quotf(b,w); 
               denom := quotf(denom,w)>>;
      if (w := gcdf(a,denom)) neq 1 and (w := gcdf(c,denom))
        then <<a := quotf(a,w);
               c := quotf(c,w);
               denom := quotf(denom,w)>>;
      return list(denom,a1,b,a,c)
    end;

% 16 Jul 94.

symbolic procedure !:mod!:unitconv(u,v);
  if v=1 then u else
   (if x neq 0 then multd('!:mod!: . x,numr u) ./
                    multd('!:mod!: . x,denr u)
     else u)
    where x = !:mod!:units(current!-modulus,cdr v,0,1);

%  3 Aug 94.

symbolic procedure mkratnum u;
   % U is a domain element. Value is equivalent real or complex 
   % rational number.
   if atom u then !*i2rn u
    else if car u eq '!:gi!:
     then apply1(get('!:gi!:,'!:crn!:),u)
    else apply1(get(car u,'!:rn!:),u);

% 20 Sep 94.

symbolic procedure dcombine(u,v,fn);
   <<u := if atom u
        then apply2(get(car v,fn),apply1(get(car v,'i2d),u),v)
       else if atom v
        then apply2(get(car u,fn),u,apply1(get(car u,'i2d),v))
       else if car u eq car v then apply2(get(car u,fn),u,v) else
      (<<if (not(x and atom x)
             or get(du,'cmpxfn) and not get(dv,'cmpxfn)
             or du memq dl and not(dv memq dl))
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
       if !*rounded and !*roundall then
       int!-equiv!-chk
         if (v := car u) eq '!:rn!: and cddr u neq 1 then !*rn2rd u
         else if v eq '!:crn!: and (cdadr u neq 1 or cdddr u neq 1)
            then !*crn2cr u
         else u
       else if fn eq 'divide then
          int!-equiv!-chk car u . int!-equiv!-chk cdr u
       else int!-equiv!-chk u>>;


endpatch;


patch rlisp;

% 16 Dec 93.

% This properly belongs in module.red.

put('load,'stat,'rlis);

put('load,'formfn,'formload);

symbolic procedure formload(u,vars,mode);
   list(if mode eq 'symbolic then 'evload else 'load!_package,
        mkquote cdr u);

% 21 Jan 94.

symbolic procedure formfor(u,vars,mode);
   begin scalar action,algp,body,endval,incr,initval,var,x;
         scalar !*!*a2sfn;        
        % ALGP is used to determine if the loop calculation must be
        % done algebraically or not.
      !*!*a2sfn := 'aeval!*;
      var := cadr u;
      incr := caddr u;
      incr := list(formc(car incr,vars,mode),
                   formc(cadr incr,vars,mode),
                   formc(caddr incr,vars,mode));
      if not atsoc(var,vars)
        then if intexprnp(car incr,vars) and intexprnp(cadr incr,vars)
               then vars := (var . 'integer) . vars
              else vars := (var . mode) . vars;
      action := cadddr u;
      body := formc(car cddddr u,vars,mode);
      initval := car incr;
      endval := caddr incr;
      incr := cadr incr;
      algp := algmodep initval or algmodep incr or algmodep endval;
      if algp then <<endval := unreval endval; incr := unreval incr>>;
      x := if algp then list('list,''difference,endval,var)
            else list(if !*fastfor then 'idifference else 'difference,
                      endval,var);
      if incr neq 1
        then x := if algp then list('list,''times,incr,x)
                   else list('times,incr,x);
      % We could consider simplifying X here (via reval).
      x := if algp then list('aminusp!:,x)
            else list(if !*fastfor then 'iminusp else 'minusp,x);
      return forformat(action,body,initval,x,
                       if algp
                          then list('aeval!*,list('list,''plus,incr))
                        else list(if !*fastfor then 'iplus2 else 'plus2,
                                  incr),
                       var,vars,mode)
   end;

% 22 Feb 94, 5 May 94, 30 Aug 94.
  
symbolic procedure assgneval u;
   begin scalar x,y;
   a: if atom u then go to b
       else if car u eq 'setq then x := ('setq . cadr u) . x
       else if car u eq 'setel
        then x := ('setel . mkquote lispeval cadr u) . x
       else if car u eq 'setk
        then x := ('setk0 .
                    mkquote if atom (y := lispeval cadr u)
                                       or get(car y,'rtype)
                                     then y
                             else car y .
                               (if z then apply1(z,cdr y)
                                 else revlis cdr y)
                               where z = get(car y,'evalargfn))
                   . x
       else go to b;
      u := caddr u;
      go to a;
   b: u := mkquote lispeval u;
   c: if null x then return(lispeval u . u);
      u := list(caar x,cdar x,u);
      x := cdr x;
      go to c
   end;
  
% 23 Mar 94.

symbolic procedure yesp1;
   begin scalar bool,x,y;
    a:  x := readch();
        if x eq !$eol!$ then go to a;
        if x eq !$eof!$ then eval '(bye)
         else if (y := x eq 'y) or x eq 'n then return y
         else if null bool then <<prin2t "TYPE Y OR N"; bool := t>>;
        go to a
   end;

% 2 Apr 94.

symbolic procedure mksetshare(u,v);
   mksetq(u,list('progn,'(setq alglist!* (cons nil nil)),v));

symbolic procedure formsetq(u,vars,mode);
   begin scalar x,y,z;
     if idp(z := car(u := cdr u)) then y := atsoc(z,vars);
     if eqcar(cadr u,'quote) then mode := 'symbolic;
      % Make target always SYMBOLIC so that algebraic expressions
      % are evaluated before being stored.
      x := convertmode(cadr u,vars,'symbolic,mode);
      return if not atom z
        then if not idp car z then typerr(z,"assignment")
          else if null atom(z := macrochk(z,mode)) and arrayp car z
           then list('setel,intargfn(z,vars,mode),x)
          else if null atom z
               and cdr z and (get(car z,'rtype) eq 'vector
                              or vectorp cadr z
                              or flagpcar(cadr z,'vecfn))
           then putvect(u,vars,mode)
          else if null atom z and (y := get(car z,'setqfn))
           then form1(applsmacro(y,append(cdr z,cdr u),nil),vars,mode)
          else if mode eq 'symbolic
             and (!*rlisp88 or eqcar(z,'structfetch))
          % Allow for Rlisp '88 records in general Rlisp.
           then list('rsetf,form1(z,vars,mode),x)
          else list('setk,form1(z,vars,'algebraic),x)
             % algebraic needed above, since SETK expects it.
    else if not idp z then typerr(z,"assignment")
    else if flagp(z,'reserved) and null atsoc(z,vars) then rsverr z
    else if flagp(z,'share) then mksetshare(symbid(z,vars),x)
    else if mode eq 'symbolic or y or eqcar(x,'quote)
     then mksetq(symbid(z,vars),x)
    else if vectorp cadr u or flagpcar(cadr u,'vecfn)
     then list('setv,mkquote z,cadr u)
    else list('setk,mkquote z,x)
   end;

% 25 Apr 94.

symbolic procedure forformat(action,body,initval,
                             testexp,updform,var,vars,mode);
   begin scalar result;
       % Next test is to correct structure generated by formfor.
      if algmodep updform and length cadr updform > 2
         then <<result:=gensym();
                updform:= list list('lambda,
                                    list result,
                                    list('aeval!*,
                                         caadr updform .
                                              cadadr updform .
                                              result .
                                              cddadr updform))>>;
      result := gensym();
      return
         sublis(list('body2 .
                if mode eq 'symbolic or intexprnp(body,vars)
                  then list(get(action,'bin),body,result)
                 else list('aeval!*,list('list,mkquote get(action,'bin),
                            unreval body,result)),
               'body3 .
                   if mode eq 'symbolic then body
                      else list('getrlist,body),
               'body . body,
               'initval . initval,
               'nillist .
                   if mode eq 'symbolic then nil else '(makelist nil),
               'result . result,
               'initresult . get(action,'initval),
               'resultlist . if mode eq 'symbolic then result
                              else list('cons,''list,result),
               'testexp . testexp,
               'updfn . car updform,
               'updval . cdr updform,
               'var . var),
          if action eq 'do
            then '(prog (var)
                  (setq var initval)
              lab (cond (testexp (return nil)))
                  body
                  (setq var (updfn var . updval))
                  (go lab))
           else if action eq 'collect
            then '(prog (var result endptr)
                  (setq var initval)
                  (cond (testexp (return nillist)))
                  (setq result (setq endptr (cons body nil)))
                looplabel
                  (setq var (updfn var . updval))
                  (cond (testexp (return resultlist)))
                  (rplacd endptr (cons body nil))
                  (setq endptr (cdr endptr))
                  (go looplabel))
           else if action eq 'conc
            then '(prog (var result endptr)
                  (setq var initval)
               startover
                  (cond (testexp (return nillist)))
                  (setq result body)
                  (setq endptr (lastpair resultlist))
                  (setq var (updfn var . updval))
                  (cond ((atom endptr) (go startover)))
                looplabel
                  (cond (testexp (return result)))
                  (rplacd endptr body3)
                  (setq endptr (lastpair endptr))
                  (setq var (updfn var . updval))
                  (go looplabel))
           else '(prog (var result)
                 (setq var initval)
                 (setq result initresult)
              lab1
                 (cond (testexp (return result)))
                 (setq result body2)
                 (setq var (updfn var . updval))
                 (go lab1)))
   end;

%  3 Jul 94.

symbolic procedure formrlis(u,vars,mode);
   if not flagp(car u,'flagop)
     then list(car u,'list .
                  if car u eq 'share then mapcar(cdr u,function mkquote)
                   else formlis(cdr u,vars,'algebraic))
    else if not idlistp cdr u 
     then typerr('!*comma!* . cdr u,"identifier list")
    else list('flag,
              'list . formlis(cdr u,vars,'algebraic),mkquote car u);

% 25 Nov 94.

symbolic procedure token1;
   begin scalar x,y;
        x := crchar!*;
    a:  if seprp x and null(x eq !$eol!$ and !*eoldelimp)
          then progn(x := readch1(), go to a)
         else if digit x then return token!-number x
         else if liter x then go to letter
         else if (y := get(x,'tokprop)) then return lispapply(y,nil)
         else if x eq '!% then go to coment
         else if x eq '!! and null(!*micro!-version and null !*defn)
          then go to escape
         else if x eq '!" then go to string;
        ttype!* := 3;
        if x eq !$eof!$ then prog2(crchar!* := '! ,filenderr());
        nxtsym!* := x;
        if delcp x then crchar!*:= '!  else crchar!*:= readch1();
        if null(x eq '!- and digit crchar!* and !*minusliter)
          then go to c;
        x := token!-number crchar!*;
        if numberp x then return apply1('minus,x);  % For bootstrapping.
        rplaca(cdr x,apply1('minus,cadr x));        % Also for booting.
        return x;
    escape:
        begin scalar raise,!*lower;
           raise := !*raise;
           !*raise := nil;
           y := x . y;
           x := readch1();
           !*raise := raise
        end;
    letter:
        ttype!* := 0;
    let1:
        y := x . y;
        if digit (x := readch1()) or liter x then go to let1
         else if x eq '!! then go to escape
         else if x eq '!- and !*minusliter
          then progn(y := '!! . y, go to let1)
         else if x eq '!_ then go to let1;    % Allow _ as letter.
        nxtsym!* := intern compress reversip!* y;
        crchar!* := x;
    c:  return nxtsym!*;
    string:
        begin scalar raise,!*lower;
           raise := !*raise;
           !*raise := nil;
       strinx:
           y := x . y;
           if (x := readch1()) eq !$eof!$
             then progn(!*raise := raise,
                        crchar!* := '! ,
                        lpriw("***** End-of-file in string",nil),
                        filenderr())
            else if null(x eq '!") then go to strinx;
           y := x . y;
           x := readch1();
           if x eq '!" then go to strinx;
           nxtsym!* := mkstrng compress reversip!* y;
           !*raise := raise
         end;
        ttype!* := 1;
        crchar!* := x;
        go to c;
    coment:
        if null(readch1() eq !$eol!$) then go to coment;
        x := readch1();
        go to a
   end;

endpatch;


% Roots declarations.

fluid '(!*intp !*noeqns !*ratroot !*xnlist);

global '(rootscomplex rootsreal);

patch roots;

% 16 Nov 93.

symbolic procedure bfnump p; numberp p or bfp!: p;

symbolic procedure allout c;
   begin scalar rl,cmp; integer a;
      c := for each j in c collect car j;
      if c and not !*ratroot and
       ((pairp r and (not bfnump r and car r eq '!:dn!:
           or not bfnump car r and caar r eq '!:dn!:)) where r=car c)
        then for each j in c do a := max(a,rrsiz j);
      restorefl(); % precision has been restored to initial value.
      for each x in c do
         if atom x or eqcar(x,'!:dn!:) then rl := x . rl
            else cmp := x . cmp;
      !*msg := t;
   % Increase system precision if too low to print out all roots.
      precmsg a;
   % If system precision is already high, warn about inputting values.
      if a<precision 0 and a>max(rootacc!#!# or 6,!!flprec)
       then msgpri(nil,
        "input of these values may require precision >= ",a,nil,nil);
       !*msg := nil;
      % the following change improves roots, solve interface.
      c := if !*noeqns then
         <<rootscomplex := rootsreal := nil;
           'list . for each j in c collect outmode j>>
         else
           <<rootscomplex := mkequal reversip cmp;
             rootsreal := mkequal reversip rl; mkequal c>>;
      return c end;

% 22 Dec 93.

symbolic procedure bfabs u; if atom u then abs u else abs!: u;

symbolic procedure tighten(i,p,pf,sh);
   begin scalar j,x0,nx,px,sn,x;
      nx := car i;
tht0: j := 4;
tht1: x0 := nx; nx := ratmean(car i,cdr i);
      if (sn := sgn1(!*intp,nx))=0 then
         <<x := r2flbf nx;trmsg1 ('tht,x); go to ret>>;
      if 0=car ratdif(nx,x0) then
         <<x := r2flbf nx;trmsg3 ('tht,x); go to ret>>;
      if sn=sh then rplacd(i,nx) else rplaca(i,nx);
      if (sn := bdstest i) then <<x := r2flbf sn; go to ret>>;
      if (j := j-1)>0 then go to tht1;
      if bndtst (px := rlval(p,x := r2flbf nx)) then go to tht0;
      gfstorval(bfabs px,x);
      % trmsg2('tht,x,px);
      if bfzp px then go to ret
         else if pf and bfleqp(pf,bfabs px) then go to tht0
         else return x;
 ret: !*xnlist := nil; return x end;

endpatch;


patch scope;

symbolic procedure gcd2(a1,a2);
  if not fixp a1 then a2 else if not fixp a2 then a1
   else begin scalar a3;
      while (a3 := remainder(a1,a2)) neq 0 do <<a1 := a2; a2 := a3>>;
      return a2
    end;
 
endpatch;


% Solve declarations.

fluid '(inside!-solveeval solve!-gensymcounter vars!* last!-vars!*
	!!gcd root!-vars!* !*arbvars sub!* !*test_solvealg const!-vars!*
	fv!* inv!* iv!* kl!* uv!*);

patch solve;

% 11 Nov 93.

symbolic procedure solvelnrsys(exlist,varlis);
   % This is hook to general solve package. exlist is a list of
   % standard forms linear in the kernels of list varlis. Result is a
   % tagged standard form for the solutions.
   % If the system is inconsistent, then the second element of
   % the list returned is NIL, so that !*solvelist2solveeqlist
   % gives expr = 0, rather than var = expr.
   % The Bareiss code is not good at handling surds at the moment, hence
   % exptexpflistp test.
   if null !*cramer and null exptexpflistp exlist
     then solvelnrsys1(exlist,varlis)
    else list list(car w,cadr w and varlis,1)
       where w = glnrsolve(exlist,varlis);

symbolic procedure exptexpflistp u;
   %  True if any of u contains an expt kernel.
   u and (exptexpfp car u or exptexpflistp cdr u);

% 15 Dec 93.

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

%  3 Dec 93.

algebraic for all a,b,x clear
   sol(cos a - sin b, x),
   sol(sin a + cos b, x),
   sol(sin a - cos b, x);

% 14 Mar 94.

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
             where inside!-solveeval = t, !*resimp = not !*exp;
      return !*solvelist2solveeqlist u
    end;

% 19 Apr 94.

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
    if null y then last!-vars!* := !&beta . last!-vars!*;
    return solvealgupd(nv,y);
  end;

% 24 May 94.

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

% 28 Nov 94.

!*arbvars :=t;

symbolic procedure solvealgrad(x,n,y);
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
    if null y or y={x} then groebroots!* :=
     ({'plus,{'expt,!&beta,n},reval{'minus,x}}
       .{{{'equal,!&beta,{'expt,x,{'quotient,1,n}}}}}).groebroots!*;
    if null y then last!-vars!* := !&beta . last!-vars!*;
    return solvealgupd(nv,y);
  end;

symbolic procedure solvealginv u;
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
  root!-vars!* := nil;
  return solvealg!-verify(tag,r);
 end;


endpatch;


patch specfn;

%  3 Dec 93, 14 Jan 94.

algebraic let {
     df(besselJ(~n,~z),z)  =>  besselJ(n-1,z) - (n/z) * besselJ(n,z),
     df(besselY(~n,~z),z)  =>  besselY(n-1,z) - (n/z) * besselY(n,z),
     df(hankel1(~n,~z),z)  =>  hankel1(n-1,z) - (n/z) * hankel1(n,z),
     df(hankel2(~n,~z),z)  =>  hankel2(n-1,z) - (n/z) * hankel2(n,z),
     besselY(~n,~z)  =>  - sqrt(2/(pi*z)) * cos(z)
        when numberp n and n = 1/2};

endpatch;

patch taylor;

% 28 Apr 94.

symbolic procedure expttayi(u,i);
  begin scalar v,flg;
    if i<0 then <<i := -i; flg := t>>;
    v := if evenp i
           then {'Taylor!*,
                 {(for each el in caddr u collect
                     nlist(0,length car el))
                   . (1 ./ 1)},
                 caddr u,1 ./ 1,nil}
          else <<i := i - 1; u>>;
    while (i:=i/2)>0 do <<u := multtaylor(u,u);
                          if not evenp i then v := multtaylor(v,u)>>;
    return if flg then invtaylor v else v
  end;

endpatch;

for each p in loaded!-packages!* do
   (if x then eval list x) where x = get(p,'patchfn);

endmodule;

end;
.
