% Test and demonstration of the ODESolve extension interface

% F.J.Wright@Maths.QMW.ac.uk, Time-stamp: <17 July 2000>

% Load odesolve before inputting this file if not using test interface:
% load_package odesolve;

% Hook into the general ODE solver:

algebraic procedure odesolve_hook_demo (ode, y, x);
   %% For any ODE, if the dependent variable is z then this hook
   %% procedure returns a solution corresponding to ODESolve failing
   %% to find any solution; otherwise it returns nil (nothing) and so
   %% is ignored.
   if y=z then {ode=0};

% Set the hook:
symbolic(odesolve_before_hook := '(odesolve_hook_demo));

% Hook into the nonlinear ODE solver:

algebraic procedure odesolve_non_hook_demo (ode, y, x, n);
   %% If the ODE is nontrivially nonlinear and the order is 3 then
   %% this hook procedure returns a solution corresponding to ODESolve
   %% failing to find any solution; otherwise it returns nil (nothing)
   %% and so is ignored.
   if n=3 then {ode=0};

% Set the hook:
symbolic(odesolve_before_non_hook := '(odesolve_non_hook_demo));

% Hook into the general linear ODE solver:

algebraic procedure odesolve_lin_hook_demo
   (odecoeffs, driver, y, x, n, m);
   %% If the ODE is linear and the order is 3 then this hook procedure
   %% returns a solution corresponding to ODESolve failing to find any
   %% solution; otherwise it returns nil (nothing) and so is ignored.
   %% (NB: Algebraic-mode lists are indexed from 1 in REDUCE!)
   if n=3 then
      {(for i := m : n sum part(odecoeffs,i+1)*df(y,x,i)) = driver};

% Set the hook:
symbolic(odesolve_before_lin_hook := '(odesolve_lin_hook_demo));

% Test all the hooks:

% The general ODE solver:
odesolve(df(y,x));                      % hook ignored
odesolve(df(z,x));                      % hook operates

% The nonlinear ODE solver:
odesolve(y*df(y,x,2)+1);                % hook ignored
odesolve(y*df(y,x,3)+1);                % hook operates

% The general linear ODE solver:
odesolve(df(y,x,2)+1);                  % hook ignored
odesolve(df(y,x,3)+1);                  % hook operates

% Clear the hooks:
symbolic(odesolve_before_hook := nil);
symbolic(odesolve_before_non_hook := nil);
symbolic(odesolve_before_lin_hook := nil);

end;
