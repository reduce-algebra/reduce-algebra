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
 begin scalar M!*,N!*;
  M!* := first odecoeffs/den ode;
  N!* := second odecoeffs/den ode;
  odecoeffs := {M!*, N!*};
  return (sub(df(y,x)=0, df(M!*,y)-df(N!*,x)))
 end;

algebraic procedure solveexact(y, x);
 begin
  traceode "This is an exact first order ODE";
  % return solve(solveexact1(y, x),y);
  % Solve seems to choke on what it gets here
  return {solveexact1(y,x)=0};
 end;

algebraic procedure solveexact1(y, x);
 begin scalar intM, odepl!*;
  intM := forceint(first odecoeffs,x);
  return num (intM + forceint(second odecoeffs - df(intM, y), y) 
                   + newarbconst());
 end;

endmodule;              % ode1

end;
