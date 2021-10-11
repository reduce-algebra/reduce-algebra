module odepatch$  % Patches to standard REDUCE facilities

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id$

% F.J.Wright@Maths.QMW.ac.uk, Time-stamp: <18 September 2000>

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Integrator patches
% ==================

% Avoid trying to integrate an integral to speed up some odesolve
% calls.

% NB: subst copies, even if no substitution is made.  It is therefore
% very likely to destroy uniqueness of kernels!

packages_to_load int$                   % not at compile time!

global '(odesolveoldsimpint)$
(if not(s eq 'nointint_simpint) then odesolveoldsimpint := s) where
   s = get('int, 'simpfn)$              % to allow reloading
put('int, 'simpfn, 'nointint_simpint)$

fluid '(!*NoInt !*odesolve_noint !*df_partial)$

symbolic procedure nointint_simpint u;
   %% Patch to avoid trying to re-integrate symbolic integrals in the
   %% integrand, because it can take forever and achieve nothing!
   if !*NoInt then
   begin scalar v, varstack!*;
      % Based on int/driver/simpint1.
      % Varstack* rebound, since FORMLNR use can create recursive
      % evaluations.  (E.g., with int(cos(x)/x**2,x)).
      u := 'int . u;
      return if (v := formlnr u) neq u then <<
         v := simp subst('int!*, 'int, v);
         remakesf numr v ./ remakesf denr v
      >> else !*kk2q u
   end
   else
   if atom u or null cdr u or cddr u and (null cdddr u or cddddr u)
     then rerror(int,1,"Improper number of arguments to INT")
    else if cddr u then simpdint u      % header from simpint
   else begin scalar car_u, result;
      %% put('int, 'simpfn, 'SimpNoInt);
      car_u := mk!*sq simp!* car u;
      %% car_u := subeval{{'equal, 'Int, 'NoInt}, car_u};
      car_u := subst('noint, 'int, car_u);
      u := car_u . !*a2k cadr u . nil;
      %% Prevent SimpInt from resetting itself!
      put('int, 'simpfn, odesolveoldsimpint);    % assumed & RESET by simpint
      result := errorset!*({odesolveoldsimpint, mkquote u}, t);
      put('int, 'simpfn, 'nointint_simpint); % reset INT interface
      if errorp result then error1();
      return noint2intsq car result;
      %% Does this cause non-unique kernels?
   end$

algebraic operator noint$               % Inert integration operator

symbolic operator odesolve!-int$
symbolic procedure odesolve!-int(y, x);
   %% Used in SolveLinear1 on ode1 to control integration.
   if !*odesolve_noint then formlnr {'noint, y, x}
   else mk!*sq nointint_simpint{y, x}$  % aeval{'int, y, x}$

symbolic procedure noint2intsq u;
   noint2intf numr u ./ noint2intf denr u;

symbolic procedure noint2intf u;
  if domainp u then u
  else begin
    scalar k, c, r, p, t1;
    k := noint2intk mvar u;
    c := noint2intf lc u;
    r := noint2intf red u;
    if k eq mvar u then p := lpow u
    else p := k . ldeg u;
    if p eq lpow u and c eq lc u then t1 := lt u
    else t1 := p .* c;
    if t1 eq lt u and r eq red u then return u
    else return t1 .+ r
  end;

symbolic procedure noint2intk k;
  if not eqcar(k, 'noint) then k
  else fkern ('int . foreach a in cdr k collect noint2int a);

symbolic procedure noint2int u;
   %% Convert all NoInt's back to Int's, without algebraic evaluation.
   if atom u then u
   else if car u = 'noint then
      'int . for each a in cdr u collect noint2int a
   else if car u = '!*sq then mk!*sq noint2intsq cadr y 
   else begin
      scalar sa, sd;
      sa := noint2int car u;
      sd := noint2int cdr u;
      if sa eq car u and sd eq cdr u then return u
      else return sa . sd
   end;


switch nointint$  !*nointint := t$
put('nointint, 'simpfg,
   '((nil (put 'int 'simpfn 'simpint) (rmsubs))
     (t (put 'int 'simpfn 'nointint_simpint))))$


% NB: `ON' is flagged ignore and so not compiled, so...
on1 'allowdfint$


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

endmodule$
end$

%                ***** NOT INSTALLED AT PRESENT *****

% Solve patches
% =============

% Needed for definition of `mkrootsoftag' function.
packages_to_load solve$                 % not at compile time!

%% An algebraic solver appropriate to ODESolve, that never returns
%% implicit solutions and returns nil when it fails.  Also, it solves
%% quadratics in terms of plus_or_minus.

%% *** NB: This messes up `root_multiplicities'. ***

%% (Later also use the root_of_unity operator where appropriate.
%% Could do this by a wrapper around `solvehipow' in solve/solv1.)

% This switch controls `solve' globally once this file has been
% loaded:
switch plus_or_minus$                   % off by default

%% The integrator does not handle integrands containing the
%% `plus_or_minus' operator at all well.  This may require some
%% re-writing of the integrator (!).  Temporarily, just turn off the
%% use of the `plus_or_minus' operator when necessary.

% This switch controls some `solve' calls locally within `ODESolve':
switch odesolve_plus_or_minus$          % TEMPORARY
% off by default -- it's to odangerous at present!
% !*odesolve_plus_or_minus := t$          % TEMPORARY

symbolic operator algsolve$
symbolic procedure algsolve(u, v);
   %% Return either a list of EXPLICIT solutions of a single scalar
   %% expression `u' for variable `v' or nil.
   begin scalar soln, tail, !*plus_or_minus;
      !*plus_or_minus := t;
      tail := cdr(soln := solveeval1{u, v});
      while tail do
         if car tail eq v then tail := cdr tail
         else tail := soln := nil;
      return soln
   end$

algebraic procedure solvepm(u, v);
   %% Solve a single scalar expression `u' for variable `v', using the
   %% `plus_or_minus' operator in the solution of quadratics.
   %% *** NB: This messes up `root_multiplicities'. ***
   symbolic(solveeval1{u, v}
      where !*plus_or_minus := !*odesolve_plus_or_minus)$

%% This is a modified version of a routine in solve/quartic

symbolic procedure solvequadratic(a2,a1,a0);
   % A2, a1 and a0 are standard quotients.
   % Solves a2*x**2+a1*x+a0=0 for x.
   % Returns a list of standard quotient solutions.
   % Modified to use root_val to compute numeric roots.  SLK.
   if !*rounded and numcoef a0 and numcoef a1 and numcoef a2
      then for each z in cdr root_val list mkpolyexp2(a2,a1,a0)
         collect simp!* (if eqcar(z,'equal) then caddr z
                          else errach {"Quadratic confusion",z})
    else begin scalar d;
      d := sqrtq subtrsq(quotsqf(exptsq(a1,2),4),multsq(a2,a0));
      a1 := quotsqf(negsq a1,2);
      return
         if !*plus_or_minus then        % FJW
            list(subs2!* quotsq(addsq(a1,
               multsq(!*kk2q newplus_or_minus(),d)),a2))
                  %% Must uniquefy here until newplus_or_minus does it
                  %% for itself!
         else
            list(subs2!* quotsq(addsq(a1,d),a2),
               subs2!* quotsq(subtrsq(a1,d),a2))
   end$

endmodule$
end$
