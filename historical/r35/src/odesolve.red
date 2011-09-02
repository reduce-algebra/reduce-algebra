module odesolve;      % Top level ordinary differential equation solver.

Comment on this package:

 a) Title: ODESOLVE

 b) Main Author: Malcolm MacCallum
     [Prof. M.A.H. MacCallum, School of Mathematical Sciences, Queen
     Mary and Westfield College, University of London,  Mile End Road,
     LONDON E1 4NS, U.K.
     E-mail: on JANET (U.K. national network)  mm@uk.ac.qmw.maths
             (Arpa/Internet form: mm@maths.qmw.ac.uk) 
             Relays: ARPA: nsfnet-relay.ac.uk
                     EARN/BITNET: UKACRL
                     uucp/Usenet: ....!mcsun!ukc!maths.qmw.ac.uk!mm
     Telex: 893750 QMCUOL G
     Fax: +44 81 981 9587
     Tel: +44 71 975 5445 or 975 5555 extension 5445]
    Other authors: Alan Barnes, Department of Computer Science,
     University of Aston, Aston triangle, Birmingham, U.K.
      Francis Wright: address as for Malcolm MacCallum

 c) Date: November 1990

 d) Abstract: This is a solver for simple ordinary differential
    equations. The present version solves some well-known simple
    types of first-order equations and higher order linear equations
    with constant coefficients and Euler equations: a full list
    is in the accompanying documentation file. Very much more
    extensive and sophisticated versions are planned.

 e) REDUCE version required: 3.4.

 f) Relevant publications: M.A.H. MacCallum, `An ordinary differential
     solver for REDUCE', Lecture Notes in Computer Science, vol.
     358 [Symbolic and algebraic computation (International symposium
     ISSAC '88], ed. P. Gianni, Springer-Verlag, Berlin and Heidelberg
     pp. 196-205 (1989).

 g) Appropriate keywords: Ordinary differential equations

 This is the source code file odesolve.red. There are also files
 of documentation, test examples and a log of a run of the test
 with extensions .doc .tst and .log;

% If you are not compiling using a module system, comment out all
% 'module' and 'endmodule' statements

% This package has modules odesolve, ode1, testdf, linearn and lccode
% at present. Note that testdf ends with extensions or variations on
% REDUCE functions which may not be required in all implementations or
% REDUCE versions

create!-package('(odesolve ode1 testdf linearn lccode),'(solve));

% Note the following become reserved identifiers used as if they were
% global variables (and there are also the function names of course)
% In a later version this will be redone in functional programming style
%
% odeorder, odedegree, odelinearity, highestderiv, in testdf
% odecoeffs, !!arbconst, arbconst                  in ode1 and linearn
% numfacs!*, denfacs!*, numfactors, denfactors     in ode1
% wronskian (a matrix)                             in lccode
% and the reserved variables associated with solve and coeff will
% be reset by certain of the routines

% Note that no attempt is made to extend the integrator i.e. to solve
% in any improved way the problems discussed by Davenport et al. It
% should extend this solver's capabilities if the Reduce 3.3 algint
% module is used.

% Changes history
% Jan 1990  Enabled input in the form of an equation
%           Changed output format to list of equation (in future,
%              equations?) (calling solve on these was abandoned as it
%              fails in nasty ways)
%           Added trode switch and message function.
%           Altered messages. Removed typing errors. Removed
%              setoperator.
%           Put in check for the factorizer bug (factorize(1) -> {})
%           Declared arbconst algebraic. Changed method of finding
%              argument.
%           Made sortoutode return ode.
%           Removed an argument from lccode
%           
% Planned changes
%           Rewrite in more functional style and remove use of global
%              variables
%           Add extra algorithms (see in the individual module headers)
%           Convert more from algebraic to symbolic mode
%           Other possible changes marked by lines starting % ***

% Tracing switch and function

fluid '(!*trode);

switch trode;

% The following two statements are needed in case SOLVE has not been
% loaded before compiling this package.

global '(multiplicities!*);

flag('(multiplicities!*),'share);

symbolic operator traceode;
symbolic procedure traceode u;
 if !*trode then write u;

% The arbitrary constants in solutions
algebraic operator arbconst;
algebraic (!!arbconst := 0);

algebraic procedure newarbconst();
 <<!!arbconst := !!arbconst +1;
   arbconst(!!arbconst)>>;

% The entry point function
% The procedures called are defined in the appropriate following modules
algebraic procedure odesolve(ode, y, x);
 begin scalar var1,!*evallhseqp;
  symbolic(!*evallhseqp := t);          % Since we wish to evaluation
                                        % LHS of equations.
  var1 := sortoutode(ode, y, x);        % returns ode as an expression
  if odeorder > 1 and odelinearity neq 1 then return odefailure(var1);
  return if odelinearity = 1
               then <<if odeorder = 1 then linear1(var1, y, x)
                                      else linearn(var1,y,x) >>
               else if odeorder = 1 then odesolve1(var1, y, x);
% *** Add entry points for extra methods here
 end;

algebraic procedure odefailure(ode);
 <<traceode
    "This version of ODESOLVE cannot solve equations of the type given";
   {ode=0}>>;

endmodule;              % odesolve


module ode1;            % Routines for first order ODEs 
% ************************************************************

% Author: Malcolm MacCallum
% Some programs for particular cases based on versions by Francis Wright
% January 1988. January 1990

% Basic layout is to test first for well-known special forms
%  namely linear
%         separable
%         (algebraically) homogeneous
%         reducible to homogeneous
%         Bernoulli
%         exact
% and at a later stage of development to add more general cases
%         Riccati
%         Others solvable by Shtokhamer, Glinos, and Caviness method
%         based on Prelle Singer result
%         etc
% Note that all cases of 1st order equations can be considered 
% equivalent to searches for integrating factors (In particular
% Lie methods do not help here)

% ************************************************************
% Solve a linear first-order equation

algebraic procedure linear1(ode,y,x);
 begin scalar rhs!*;
  rhs!* := - (num ode)/lcof(num ode,df(y,x)) + df(y,x);
  if afreeof(rhs!*, y)
    then return {y = quadrature(rhs!*, x) + newarbconst()};
  traceode "This is a first-order linear ODE";
  traceode " solved by the integrating factor method";
  return {y = solvelinear1(rhs!*, y, x)};
 end;

algebraic procedure quadrature(rhs!*, x);
 begin
  traceode "This first-order ODE can be solved by quadrature";
  return int (rhs!*, x);
 end;

% This does not return an equation list so that it can also be called
% within solvebernoulli. solvelinear makes the equation from it.
algebraic procedure solvelinear1(rhs,y,x);
 begin scalar intfactor, b!*, c!*;
  b!* := - lcof(num rhs,y)/den rhs;
  c!* := rhs + (b!*)*y;
  intfactor:=e**int(b!*, x);
  intfactor := resimplify intfactor; % To cure exp(log x) problem
  return  (newarbconst() + int(intfactor*(c!*),x))/intfactor;
        % or that multiplied by intfactor, or num of it?
 end;

% ************************************************************
% Top-level solver for non-linear first-order equations

algebraic procedure odesolve1(ode, y, x);
 begin scalar rhs!*, arbconst!*;
    % Using rhs here seems to lead to trouble!!
  if odedegree neq 1 then return
   <<traceode "ODESOLVE at present only solves first order equations";
     traceode "if degree is 1";
     {ode=0}>>;
% *** replace with call to a suitable function eventually
  arbconst!* := lisp gensym();
  odecoeffs := coeff(num ode, df(y,x));
  rhs!* := - first odecoeffs/second odecoeffs;
%       Following ordering of tests could be altered.
%       If rhs!* or ode is not explicitly passed to the test or solution
%       routines this is because they use odecoeffs, denfactors etc
  if testseparable(rhs!*, y, x) = 0 then return solveseparable(y, x);
  if testhom(rhs!*, y, x, arbconst!*)=0
    then return solvehomde(rhs!*, y, x);
  if testredhom(rhs!*, y, x) = 0 then return solveredhomde(rhs!*, y, x);
  if testbernoulli(rhs!*, y, x)=0 then return solvebernoulli(rhs!*,y,x);
% ***** N.B. Next line re-defines odecoeffs: be careful if re-ordering
  if testexact(ode, y, x) = 0 then return solveexact(y, x);
  return odefailure(ode);
 end;

% ************************************************************
% The separable case 
algebraic procedure testseparable(rhsterm,y,x);
 begin
  clear denfacs!*, denfactors; % may not be set here so lose old values
  numfacs!* := length(numfactors := xfactorize(num rhsterm));
% We will assume there are no common factors in num and den (is this
% dangerous?)
  if testseparable1(y, x, numfacs!*, numfactors) neq 0 then return 1;
  denfacs!* := length (denfactors := xfactorize(den rhsterm));
  return testseparable1(y, x, denfacs!*, denfactors);
 end;

algebraic procedure testseparable1(y, x, number, factorlist);
 begin scalar count!*, temp!*;
   count!* := 1;
a: if count!* > number then return 0;
   temp!* := part(factorlist, count!*);
   count!* := count!* + 1;
   if not (afreeof(temp!*, x) or afreeof(temp!*, y)) then return 1;
   go to a;
 end;

algebraic procedure solveseparable(y, x);
 begin scalar f!*, g!*, temp!*;
  f!*:=g!*:=1;
  for i:=1:numfacs!* do
   <<temp!*:=part(numfactors,i);
     if afreeof(temp!*,y) then f!*:=(f!*)*temp!*
        else g!*:=(g!*)*temp!*;>>;
  for i:=1:denfacs!* do
   <<temp!* := part(denfactors,i);
             if afreeof(temp!*,y) then f!*:=(f!*)/temp!*
        else g!*:=(g!*)/temp!*;>>;
  temp!* := int(1/g!*, y) - int(f!*,x) + newarbconst();
  traceode "This is a first-order separable ODE";
  return {temp!*=0};
  % Cannot trust solve here
 end;

% ************************************************************
algebraic procedure testhom(rhsterm,y,x, arbconst!*);
  resimplify(rhsterm - sub(x=arbconst!**x,y=arbconst!**y,rhsterm));
% Changed 17.10.89

% Solve algebraically homogeneous 1st order ODEs
algebraic procedure solvehomde(rhsterm, y,x);
 begin
  traceode
     "This is a first-order ODE of algebraically homogeneous type";
  traceode " solved by change of variables y = vx method";
  return {solvehomde1(rhsterm, y,x)=0};
 end;

% Also called by the solveredhomde function
algebraic procedure solvehomde1(rhsterm, y, x);
 <<rhsterm := exp(int(1/(sub(y=y*x,rhsterm)-y),y));
  sub(y=y/x, x/resimplify(rhsterm) + newarbconst())>>;

% ************************************************************
% Test if the equation is reducible to homogeneous
% *** Can we use the new pattern matcher here
algebraic procedure testredhom(rhsterm,y,x);
 begin scalar temp!*;
  if not numberp denfacs!*
     then denfacs!* := length (denfactors := xfactorize(den rhsterm));
  if not numberp ((rhsterm)*(part(denfactors,denfacs!*)**(denfacs!*-1))/
                          (part(numfactors,numfacs!*)**(numfacs!*-1)))
     then return 1;
  temp!* := part(numfactors,numfacs!*);
  if not afreeof(temp!*-x*coeffn(temp!*, x,1), x) then return 1;
  if not afreeof(temp!*-y*coeffn(temp!*, y,1), y) then return 1;
  temp!* := part(denfactors,denfacs!*);
  if not afreeof(temp!*-x*coeffn(temp!*, x,1), x) then return 1;
  if not afreeof(temp!*-y*coeffn(temp!*, y,1), y) then return 1;
  return 0;
 end;

algebraic procedure solveredhomde(rhsterm,y,x);
 begin scalar ans!*;
  traceode "This is a first-order ODE reducible to homogeneous type";
  ans!* := solveredhomde1(rhsterm,y,x);
  % return solve(ans!*,y);
  % Solve chokes on this sometimes so leave the user to try it
  return {ans!* = 0};
 end;

algebraic procedure solveredhomde1(rhsterm,y,x);
 begin scalar ans1!*, a1!*, b1!*, a2!*, b2!*;
  a1!* := lcof(part(numfactors,numfacs!*),x);
  b1!* := lcof(part(numfactors,numfacs!*),y);
  a2!* := lcof(part(denfactors,denfacs!*),x);
  b2!* := lcof(part(denfactors,denfacs!*),y);
  if (a1!*)*(b2!*)-(a2!*)*(b1!*) = 0 then return
    <<traceode "belonging to the special case where top and bottom";
      traceode "are parallel lines";
      traceode "solved by new variable and separation";
      rhsterm:=(b1!*)*sub(y=(y-(a1!*)*x)/b1!*, rhsterm) +a1!*;
      ans1!*:=int(1/rhsterm,y)-x+newarbconst();
      sub(y=(a1!*)*x+(b1!*)*y, ans1!*)>>
   else return
    <<traceode "solved by shifting the origin";
      ans1!* := first solve({part(numfactors,numfacs!*),
                               part(denfactors,denfacs!*)},{x,y});
      a1!* := rhs first ans1!*;
      a2!* := rhs second ans1!*;
      rhsterm:=sub(x=x+a1!*,y=y+a2!*, rhsterm);
      ans1!*:=solvehomde1(rhsterm,y,x);
      sub(x=x-a1!*,y=y-a2!*,ans1!*)>>;
 end;

% ************************************************************
algebraic procedure testbernoulli(rhsterm, y,x);
 begin scalar tbnvar;
  tbnvar := deg(den rhsterm, y);
  if not afreeof(lcof(den rhsterm, y), y) then return 1;
  if tbnvar >0 then return testbernoulli1(rhsterm, tbnvar, y, x);
  tbnvar := forcecoeff(rhsterm, y);
  return
    (if afreeof(part(tbnvar, 1), y)
        and afreeof(part(tbnvar, hipow!*+1), y)
        and rhsterm - part(tbnvar,2)*y
               - part(tbnvar,hipow!*+1)*y**(hipow!*)=0
         then 0 else 1);
 end;

algebraic procedure testbernoulli1(rhsterm, degry, y, x);
 begin scalar tb1var;
  if den rhsterm neq lcof(den rhsterm, y)*y**degry then return 1;
  tb1var := testbernoulli(y**2*sub(y=1/y, rhsterm), y, x);
  hipow!* := 2 - hipow!*;
  return tb1var;
 end;

algebraic procedure solvebernoulli(rhsterm, y, x);
 begin
  traceode "This is a first-order ODE of Bernoulli type";
  return {y**(1-hipow!*) =
               solvelinear1(sub(y=y**(1/(1-hipow!*)),
                             (1-hipow!*)*rhsterm/(y**hipow!*)),y,x)};
 end;

% ************************************************************
algebraic procedure testexact(ode, y, x);
 begin scalar m!*,n!*;
  m!* := first odecoeffs/den ode;
  n!* := second odecoeffs/den ode;
  odecoeffs := {m!*, n!*};
  return (sub(df(y,x)=0, df(m!*,y)-df(n!*,x)))
 end;

algebraic procedure solveexact(y, x);
 begin
  traceode "This is an exact first order ODE";
  % return solve(solveexact1(y, x),y);
  % Solve seems to choke on what it gets here
  return {solveexact1(y,x)=0};
 end;

algebraic procedure solveexact1(y, x);
 begin scalar intm, odepl!*;
  intm := forceint(first odecoeffs,x);
  return num (intm + forceint(second odecoeffs - df(intm, y), y)
                   + newarbconst());
 end;

endmodule;              % ode1


module testdf;          % Test an ODE for order, degree etc
% ************************************************************

% Author: Malcolm MacCallum
% January 1988

% Get the order and degree of an ordinary differential equation
% and find out if it is linear
% N.B. No check that it is actually ordinary, in case we later want
% to use this on partial differential equations also

% Some extensions and fixes for REDUCE at the end of the module

% The procedure sortoutode puts the results into variables
% odeorder, odedegree, odelinearity and highestderiv and 
% returns an expression equivalent to the equation.
% *** should return a list of these quantities
% The case where the given 'ode' is not a 
% differential equation sets zero values in all these and
% exits with an error.
%  odeorder is an integer and is 0 if no derivative appears
%  odedegree is an integer which is 0 if the highest derivative
% appears in a transcendental function or to a rational power.
% (Should be the rational number or some info on the dependency)
%  odelinearity is 1 if the equation is linear in the dependent
% variable, 0 if the supposed ode is in fact independent of y,
% a number if y and all derivatives appear to rational powers, and
% otherwise an expression in which y or some derivative appears in
% a transcendental form (but not necessarily the worst such term)

% The arguments to sortoutode are fairly obvious. It is not assumed
% that the ode will be denominator-free but it usually will be the case.
% The dependent and independent variable names (y and x) are given so
% that any name can be used and so that this could be adapted to PDEs

algebraic procedure sortoutode(ode, y, x);
 begin
  highestderiv := odeorder := odelinearity := odedegree := 0;
  % Above line re-initialises externals
  if symbolic (car ode = 'equal) then ode := rhs ode - lhs ode;
  odelinearity := odelinearp(num ode, y, x);
    % odelinearp sets highestderiv and odeorder
  if odeorder = 0 then rederr
   "ODE argument is not a differential equation in the given variables";
  odedegree := deg(num ode, highestderiv);
  % This will be 0 if the derivative is inside a transcendental or
  % algebraic function, rather than in polynomial form
  return ode;
 end;

% We assume the ode is an atom, number, kernel or algebraic
% standard quotient. In the last case we take the numerator 
% which will be a standard form
symbolic operator odelinearp;
symbolic procedure odelinearp(ode, y, x);
 begin
  if atom ode or numberp ode then return 0;
  if kernp ode then return mvardftest(ode, y, x);
  return formdftest(caadr aeval ode, y, x);
 end;

% standard form = () | integer | (term . form) 
% where the dot represents summation
symbolic procedure formdftest(ode, y, x);
 begin scalar fdvar1;
  if fixp car (fdvar1 := formdftest1(ode, y, x))
   then return cdr fdvar1 else return car fdvar1;
 end;

% This returns a pair (worst nonlinearity . total degree in y or
% nonlinearity) as do all sub-procedures with names <junk>dftest
% *** should pass info on odeorder etc around in functional style
% *** not via global variables
symbolic procedure formdftest1(ode,y,x);
 if null ode or domainp ode then '(0 . 0)
  else dftestfn(termdftest(car ode, y, x),
                formdftest1(cdr ode, y, x),
                t);

% term = (power . form) where the . represents multiplication
symbolic procedure termdftest(odeterm, y, x);
 dftestfn(powerdftest(car odeterm, y, x),
          formdftest1(cdr odeterm, y, x),
          nil);

% Find worst of the cars, and apply fn to the cdrs if both are numbers.
symbolic procedure dftestfn(u, v, bool);
 begin scalar dfvar1, dfvar2, dfvar3, dfvar4;
  dfvar1 := car u; dfvar2 :=cdr u; dfvar3 := car v; dfvar4 := cdr v;
  return
   ((if fixp dfvar1 then
       (if fixp dfvar3 then max(dfvar1, dfvar3) else dfvar3)
     else if numberp dfvar1 then
       (if fixp dfvar3 then dfvar1
           else if numberp dfvar3 then max(dfvar1, dfvar3)
            else dfvar3)
     else dfvar1)
   . fixdfcdrs(dfvar2, dfvar4, bool));
 end;

symbolic procedure fixdfcdrs(u, v, bool);
  if numberp u
   then
    (if numberp v then fixdfcdrs1(u, v, bool) else v)
   else u;

symbolic procedure fixdfcdrs1(u, v, bool);
 if bool then max(u, v) else plus(u, v);

% power = (kernel . integer) where the . means exponentiation
symbolic procedure powerdftest(power, y, x);
 begin scalar pdvar1;
  pdvar1 := mvardftest(car power, y, x);
  return (condmult(car pdvar1, cdr power) .
           (condmult (cdr pdvar1, cdr power)));
 end;

symbolic procedure condmult(u, v);
 if numberp u then times(u, v) else u;

% Test the 'mvar' of a REDUCE standard quotient
% This may be a variable, a kernel, or (if exp is off) a standard form 
symbolic procedure mvardftest(kernel, y, x);
 begin
  if (kernel = y) then return '(0 . 1);
  if afreeof(kernel, y) then return '(0 . 0);
  if (not atom car kernel) then return formdftest1(kernel, y, x);
   % This may be relevant if exp is off
  if (car kernel eq 'df) then return getdforder(kernel, y, x);
   % The rest assumes that any other sort of kernel must be non-linear
   % in y or df(y,x)
  finddf(kernel, y, x);
  return (kernel . list (kernel));
 end;

% This returns the order of the dfterm and sets odeorder and
% highestderiv whenever appropriate.
symbolic procedure finddf(exprn, y, x);
 begin
  if null exprn or atom exprn or numberp exprn then return;
  if car exprn eq 'df then return getdforder(exprn, y, x);
  finddf(car exprn, y, x);
  finddf(cdr exprn, y, x);
 end;

symbolic procedure getdforder(dfexprn, y, x);
 begin scalar gdvar1;
  gdvar1 := getdforder1(dfexprn, y, x);
  if gdvar1 = -1 then return '(0 . 1);
  if gdvar1 = 0 then return '(0 . 0);
  if gdvar1 > (algebraic odeorder) then algebraic
   <<odeorder := gdvar1; highestderiv := dfexprn>>;
  return '(1 . 1);
 end;

symbolic procedure getdforder1(dfexprn, y, x);
 begin scalar varlist;
  varlist := cdr dfexprn;
  if not car varlist eq y then return 0;
a: varlist := cdr varlist;
   if null varlist then return -1;
   if not (car varlist eq x) then go to a;
   if null cdr varlist or (not numberp cadr varlist) then return 1
     else return cadr varlist;
 end;

% Fixes to REDUCE: put here because they are needed in several places

% An "apparently free of" function
% Like freeof but not using dependency list depl!*. Could be
% replaced by declaring smember a symbolic operator ?
symbolic operator afreeof;
symbolic procedure afreeof(u,v);
 not smember(v,u);

% An extended REDUCE 3.3 factorize which guarantees a numerical first
% entry in the list returned. Note this assumes IFACTOR is not on.
algebraic procedure xfactorize(exprn);
 begin scalar temp!*;
  temp!* := factorize(exprn);
  if (length temp!* = 0) or (not numberp first temp!*)
    then temp!* := 1 . temp!*;
  return temp!*
 end;

% Needed to force use of simplifications in some places
% (? will all implementations need this)
% *** Replace by calls to rmsubs() ?
symbolic operator resimplify;
symbolic procedure resimplify u;
 mk!*sq simp!* u;

% We have to reset depl!* to avoid complaints about side-relations
% from the integrator and it is global so we do not do this by just
% making it a scalar of the procedure (that works interpreted...!)
% (Could declare it fluid?)
symbolic operator forceint;
symbolic procedure forceint(integrand,x);
 begin scalar odepl!*, temp2!*;
  odepl!* := depl!*;
  depl!* := nil;
  algebraic (temp2!* := int(integrand,x));
  depl!* := odepl!*;
  return temp2!*;
 end;

% In case ratarg is not on
algebraic procedure forcecoeff(exprn, var);
 begin scalar fcovar;
  if symbolic !*ratarg then return coeff(exprn, var);
  on ratarg;
  fcovar := coeff(exprn, var);
  off ratarg;
  return fcovar;
 end;

endmodule;      %testdf


module linearn;
% A solver for linear ordinary differential equations of order > 1
% ************************************************************

% Author: Malcolm MacCallum
% January 1988

% Basic ideas
%  first check for the simple case of linear equations with
%   constant coefficients. Use variation of parameters for the
%   particular integrals (see comments in module lccode),
%    [implemented up to here so far]
%   or if this fails use a Laplace transform ?
%  then look for methods for the variable coefficient case
%   starting with the homogeneous case (Euler equations)
%   [test implemented, solver still being written]
%  and I do not yet know what else....

algebraic procedure linearn(ode, y, x);
 begin scalar ans!*, rhs!*, auxeqn, lcoeff, arbconst!*;
  ans!* := 0;
  ode:=num ode;
  rhs!*:=-sub(y=0,ode);
  auxeqn := ode + rhs!*;
  lcoeff := lcof(auxeqn, df(y, x, odeorder));
  arbconst!* := lisp gensym();
  auxeqn := sub(y=e**(arbconst!**x), auxeqn/lcoeff)/e**(arbconst!**x);
  rhs!* := rhs!*/lcoeff;
   % Should form an equation in 3.3 for the solution (?), or is it
   % better to have an expression easily assigned to a variable ?
  if df(auxeqn, x) = 0 and
     (ans!* := lccode(auxeqn, rhs!*, x, arbconst!*)) neq 0
    then return {y=ans!*};
  odecoeffs := coeff(auxeqn, arbconst!*);
  if testeuler(odecoeffs, x)=0 and
     (ans!* := solveeuler(odecoeffs, rhs!*, y, x, arbconst!*)) neq 0
    then return {y=ans!*};
  return odefailure(ode);
  % The kludgy way of testing if we got anywhere 
  % is to make it easy to add and debug extra cases
  % Note we assume AND only looks at the second part if first succeeds.
 end;

algebraic procedure testeuler(odecoeffs, x);
 begin scalar count!*, teuvar;
   count!* := 0;
a: teuvar := part(odecoeffs, count!*+1) * (x**(odeorder - count!*));
   if not freeof(teuvar, x) then return 1;
   count!* := count!* + 1;
   if not (count!* > odeorder) then go to a;
   traceode "This equation is of the homogeneous (Euler) type";
   return 0;
 end;

algebraic procedure solveeuler(coeffs, driver, y, x, arbconst!*);
 begin scalar sevar, rhs!*;
  sevar := part(coeffs,1)*x**odeorder;
  for i:=1:odeorder do
   sevar := sevar +
       x**(odeorder-i)*part(coeffs,i+1)
            * (for j:=0:i-1 product (arbconst!*-j));
  rhs!* := sub(x=e**x,driver*x**odeorder);
  sevar := lccode1(sevar, rhs!*, x, arbconst!*);
  return if sevar=0 then sevar else sub(x=log x, sevar);
 end;

endmodule;      %linearn


module lccode;
% Procedures for solving linear ordinary differential equations
% with constant coefficients 
% *************************************************************

% Authors: Malcolm MacCallum, Alan Barnes
% January 1988

% There are (at least) 4 ways to get the particular integral (P.I.)
% for a given driving term on the right of the equation
%  1. The method of undetermined coefficients: this is similar to the
% integrator in that for a given driving term one has to find the
% functional form of the P.I. and then solve for the numerical
% coefficients in it. Making it really general is as big a task as
% rewriting the integrator.
%  2. The method of variation of parameters: this expands the P.I.
% as a sum of functions of 'x' times the linearly independent solutions
% in the complementary function (C.F.)
%  3. Factorise the linear operator (done anyway for the C.F.) and
% then apply for each root m the operation
% ans := exp(m*x) * int(ans * exp(-m*x));
% This is a form of the "D-operator method" N.B. Some m are complex
%  4. Use Laplace transforms (and some kind of table lookup for the
% inverse transforms)

% *** So far no comparison of efficiencies has been done. A scheme which
% *** selected among the above methods might be better than any one of
% *** them alone.

% The original version of lccode used in 1987 with an undergraduate
% class used the 'method of undetermined coefficients' but relied on
% user recognition of when this was applicable. Alan Barnes 
% wrote a new version using the method of 'variation of parameters'
% The advantages are that it covers a wider range of driving terms,and
% it is relatively simple to program except for the need for cofactors,
% and the possible disadvantages are (a) it makes several calls
% of int, (b) for large n, the need to evaluate an nxn and
% several (n-1)x(n-1) determinants may cause it to be less efficient,
% and (c) unlike the other methods it can lead to the P.I. containing
% unnecessary multiples of the solutions in the C.F.

% lccode1 provides an entry point for use by other solvers e.g.
% solveeuler.  Value returned is an expression to equate to the `y' or 0
% (if it fails).

algebraic procedure lccode(auxeqn, driver, x, arbconst!*);
 <<traceode "This is a linear ODE with constant coefficients of order ";
    traceode odeorder;
    lccode1(auxeqn, driver, x, arbconst!*)>>;

algebraic procedure lccode1(auxeqn, driver, x, arbconst!*);
 begin scalar auxroots, slcvar, slcvar2, solutions, cf, parti;
  auxroots := solve(auxeqn, arbconst!*);
  slcvar := length auxroots;
  slcvar2 := (for i:=1:slcvar sum part(multiplicities!*, i));
  if odeorder neq slcvar2 then return
   <<traceode "Insufficient roots of auxiliary equation"; 0>>;
  slcvar2 := 1;
a: if lhs part(auxroots, slcvar2) neq arbconst!* then return
    <<traceode "Auxiliary equation could not be solved"; 0>>;
   slcvar2 := slcvar2 + 1;
   if slcvar2 <= slcvar then go to a;
%
% Now we find the complementary function
% 
  solutions := getsolns(auxroots,slcvar,x);
  cf := (for i:=1:odeorder sum newarbconst()*part(solutions,i));
%
% Next the particular integral
%
  if driver=0 then parti := 0 else
   parti := getpartint(auxroots, slcvar, driver, x);
  return cf + parti;
 end;

algebraic procedure getsolns(auxroots,rootcount,x);
 begin scalar ans!*,rootno,test,exppart,nextroot, gtsvar;
  rootno:=1;
  ans!* := {};
  while rootno <= rootcount do
   <<nextroot := rhs part(auxroots, rootno);
     gtsvar := part(multiplicities!*, rootno);
     % Testing for complex roots: negative one is first.
     test:=df(nextroot,i);
     if test=0 then
      <<exppart := e**(nextroot*x);
        for j:=1:gtsvar do ans!*:=append(ans!*,{x**(j-1)*exppart});
        rootno:=rootno+1;>>
      else
      <<exppart:=e**((nextroot-test*i)*x);
        for j:=1:gtsvar do
            ans!* := append(ans!*,{x**(j-1)*cos(-test*x)*exppart,
                                   x**(j-1)*sin(-test*x)*exppart});
        rootno:=rootno+2>> >>;
  return ans!*;
 end;

algebraic procedure getpartint(auxroots, rootcount, driver, x);
 begin scalar ans!*, gpvar;
  ans!* := driver;
  for i:=1:rootcount do
   <<gpvar:= (ans!*)*e**(-(rhs part(auxroots,i))*x);
     for j:=1:part(multiplicities!*,i) do gpvar := int(gpvar,x);
     ans!* := e**((rhs part(auxroots,i))*x)*gpvar;>>;
  return ans!*;
 end;

endmodule;    % lccode


end;
