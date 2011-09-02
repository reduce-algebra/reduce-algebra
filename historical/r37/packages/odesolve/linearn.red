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

end;
