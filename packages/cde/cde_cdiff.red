module cde_cdiff; % CDE package, data structure for C-differential operators

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

% % *****************************************************************
% Author and maintainer: Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo
% ===============================================================

% A C-differential operator is represented as a 'special' Reduce operator.
% If the C-differential operator is skew, then it can also be represented
% through odd variables as a superfunction.

symbolic procedure mk_cdiffop(cdiff_op,num_arg,len_arg,len_target);
% This procedures creates a C-differential operator cdiff_op
% and associates with the operator:
% 1 - the number of its arguments num_arg
% 2 - the algebraic list of lengths of each of its arguments len_arg,
% 3 - the length of the image vectors in the target space len_target
% In other words, a C-differential operator is an indexed family of
% scalar C-differential operators, each applied to a fixed vector
% of arguments. Example:
% opname(i_t,ia_1,...,ia_k,psi_1,...psi_k)
% NOTE: to get the number of arguments do get('cdnarg,cdiff_op);
% to get the length of each of its argumens do get('cdlarg,cdiff_op);
% to get the length of vectors in the target space do get('cdtarget,cdiff_op);
% to see if an identifier is a cdop do get('cdop,cdiff_op);
begin
  mkop cdiff_op;
  put('cdop,cdiff_op,t);
  if not numberp num_arg then rederr "Error in the number of arguments";
  put('cdnarg,cdiff_op,num_arg);
  if not fixp num_arg then
    rederr "Error: number of arguments must be an integer";
  if not cde_alglistp(len_arg) then
    rederr "Error in the list of lengths of arguments";
  put('cdlarg,cdiff_op,len_arg);
  if not fixp len_target then
    rederr "Error: the length of image vectors must be an integer";
  put('cdtarget,cdiff_op,len_target);
end;

symbolic operator mk_cdiffop;

symbolic procedure cdiffp(cdiff_op);
  get('cdop,cdiff_op);

symbolic procedure check_cdiff_onearg(cdiff_op);
  % Checks if the CDiff operator has exactly one argument.
  begin
    scalar len_arg;
    integer num_arg,n_arg,len_target;
    if not cdiffp(cdiff_op) then
      rederr "Error: the first argument must be a declared CDiff operator";
    if not eqn(num_arg:=get('cdnarg,cdiff_op),1) then
      rederr "Error: the operator must have exactly one argument";
    if not cde_alglistp(len_arg:=get('cdlarg,cdiff_op)) then
      rederr "Error: the length of arguments must be an algebraic list";
    if not eqn(length(len_arg),2) then
      rederr "Error: the operator must have exactly one argument";
    if not fixp(n_arg:=cadr(len_arg)) then
      rederr "Error: the dimension of the argument space must be an integer";
    if not fixp(len_target:=get('cdtarget,cdiff_op)) then
      rederr "Error: the length of image vectors must be an integer";
  end;

symbolic procedure check_cdiff_scalar(cdiff_op);
  % Checks if the CDiff operator is a scalar operator.
  begin
    scalar len_arg;
    integer len_target;
    if not cdiffp(cdiff_op) then
      rederr "Error: the first argument must be a declared CDiff operator";
    if not cde_alglistp(len_arg:=get('cdlarg,cdiff_op)) then
      rederr "Error: the length of arguments must be an algebraic list";
    if not eqn(len_target:=get('cdtarget,cdiff_op),1) then
      rederr "Error: the length of image must be 1 for scalar operators";
  end;

symbolic procedure check_cdiff_sametype(cd1,cd2);
  begin
    scalar parity1,parity2,largcd1,largcd2,target1,target2;
    if not cdiffp(cd1) then rederr
      "The first argument must be a declared C-Differential operator";
    if not cdiffp(cd2) then rederr
      "The second argument must be a declared C-Differential operator";
    parity1:=get('cdnarg,cd1);
    parity2:=get('cdnarg,cd2);
    if not eqn(parity1,parity2) then rederr
      "The number of arguments of the operators must be the same";
    largcd1:=get('cdlarg,cd1);
    largcd2:=get('cdlarg,cd2);
    if not(equal(largcd1,largcd2)) then rederr
      "The length of all arguments of the operators must be the same";
    target1:=get('cdtarget,cd1);
    target2:=get('cdtarget,cd2);
    if not eqn(target1,target2) then rederr
      "The length of vectors in the target space must be the same";
  end;

% INSERT HERE: a procedure for getting all coefficients of a C-Diff-op.

symbolic procedure conv_cdiff2superfun(cdiff_op,superfun);
  % Convert a C-differential operator into the corresponding superfunction.
  % I assume that the operator has just ONE argument!
  % Indeed using more arguments one would need a skew-adjointness test
  % and a super-product between the derivatives of odd variables.
  % The conversion assumes that the argument is the vector of odd variables.
  % For example, this function gives the correct result when the operator
  % to be converted is
  % 1 - the linearization and odd variables are those of the tangent covering
  % \ell_F: \kappa \to P;
  % 2 - the adjoint linearization and odd variables are those of the cotangent
  % covering: \ell_F^*: \hat P \to \hat\kappa;
begin scalar len_arg,tempsuperfun;
  integer num_arg,n_arg,len_target;
  check_cdiff_onearg(cdiff_op);
  num_arg:=get('cdnarg,cdiff_op);
  len_arg:=get('cdlarg,cdiff_op);
  n_arg:=cadr(len_arg);
  % Superfunctions are constructed with ALL odd variables
  if not eqn(n_arg,length(odd_var!*)) then rederr
    "dimension of the arguments different from the number of odd variables";
  len_target:=get('cdtarget,cdiff_op);
% The test below is not strictly needed
%  if not eqn(cadr len_arg,len_target) then
%    rederr "dependent variables and target space dimension mismatch";
  mk_superfun(superfun,1,len_target);
  for i:=1:len_target do
    superfun(i):=
      <<
        tempsuperfun:=for j:=1:n_arg collect
	  aeval list(cdiff_op,i,j,nth(odd_var!*,j));
        if !*checkord then check_letop(tempsuperfun);
        aeval cons('plus,tempsuperfun)
      >>;
end;

symbolic operator conv_cdiff2superfun;

symbolic procedure cde_cdiff();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
