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
  if not(car varlist eq y) then return 0;
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

fluid '(!*nopowers);                    % FJW, 13/1/1998

algebraic procedure xfactorize(exprn);
   % An extended factorize which guarantees a numerical first
   % entry in the list returned. Note this assumes IFACTOR is not on.
   begin scalar temp!*;
      temp!* := old_factorize exprn;
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

end;
