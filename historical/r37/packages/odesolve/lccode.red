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
