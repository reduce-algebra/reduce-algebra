module f5param;
% f5 parametric. Support collection and output of sufficient conditions
% on parametric coefficients during Groebner basis computation.

revision('f5param, "$Id$");

copyright('f5param, "(c) 2022 A. Demin, T. Sturm, MPI Informatics, Germany");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

% The helper module to keep track of assumptions made in parametric F5 computations.
% Provides functions `param_add*` for recording different kinds of assumptions 
% on polynomial coefficients containing parameters.
% Additionaly, provides function `param_clearAssumptions`, which clears all recorded assumptions,
% and function `param_dumpAssumptions`, which returns all recorded assumptions in a list.
% Currently, 4 types of assumptions are recorded in 4 separate lists:
%  . Assumptions implicitly made from the input (param_assumptionsInput);
%     For example, (1/a)*x in the input will sometimes produce an assumption in case `a` is a parameter.
%  . Assumptions on non-vanishing of leading terms in S-polynomial construction (param_assumptionsSpol);
%     That is, if an S-polynomial of f1,f2 is formed, assumptions on non-vanishing of leading coefficients
%     of f1 and f2 are made.
%  . Assumptions on non-vanishing of leading coefficients in polynomial reductions (param_assumptionsRed);
%  . Assumptions obtained when making polynomials monic/primitive depending on f5fractionfree (param_assumptionsNormalize);
%        (active if f5parametricNormalize is ON)
fluid '(param_assumptionsSpol!* param_assumptionsRed!*
        param_assumptionsInput!* param_assumptionsNormalize!*);

algebraic infix neq;
newtok '((!< !>) neq);
flag('(neq),'spaced);

asserted procedure param_isConstAssumption(poly: SQ): Boolean;
   domainp numr poly;  

asserted procedure param_prepareIneq(poly: SQ): List; 
   begin scalar num;
      num := numr poly;
      % num := quotf(num, sfto_dcontentf num);
      if minusf num then
         num := negf num;
      num := sfto_sqfpartf num;
      return {'neq, prepf num, 0}
   end;

% Add `poly <> 0` to S-polynomial assumptions 
asserted procedure param_addAssumptionSpol(poly: SQ): List;
   if not param_isConstAssumption(poly) then
      param_assumptionsSpol!* := lto_insert(param_prepareIneq(poly), param_assumptionsSpol!*);

% Adds `poly <> 0` to Reduction assumptions 
asserted procedure param_addAssumptionRed(poly: SQ): List;
   if not param_isConstAssumption(poly) then
      param_assumptionsRed!* := lto_insert(param_prepareIneq(poly), param_assumptionsRed!*);

% Adds `poly <> 0` to Input assumptions 
asserted procedure param_addAssumptionInput(poly: SQ): List;
   if not param_isConstAssumption(poly) then
      param_assumptionsInput!* := lto_insert(param_prepareIneq(poly), param_assumptionsInput!*);

% Adds `poly <> 0` to Normalize assumptions 
asserted procedure param_addAssumptionNormalize(poly: SQ): List;
   if not param_isConstAssumption(poly) then
      param_assumptionsNormalize!* := lto_insert(param_prepareIneq(poly), param_assumptionsNormalize!*);

% Clears all assumptions
asserted procedure param_clearAssumptions();
<<
   param_assumptionsSpol!* := nil;
   param_assumptionsRed!* := nil;
   param_assumptionsNormalize!* := nil;
   param_assumptionsInput!* := nil
>>;

% Dumps (returns) all recorded assumptions as a list
% of inequalities
asserted procedure param_dumpAssumptions(): List;
   lto_unionn({param_assumptionsSpol!*, param_assumptionsRed!*,
               param_assumptionsNormalize!*, param_assumptionsInput!*});

endmodule;  % end of module f5param

end;  % of file
