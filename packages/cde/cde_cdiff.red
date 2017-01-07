module cde_cdiff; % CDE package, data structure for C-differential operators
                  % in operatorial and odd variable language, with conversions.

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
%
% Version and Date:  2.0, October 2015.
%
% ===============================================================

% A C-differential operator can have two equivalent forms:
% 1 - an operatorial representation.
% 2 - an odd variable representation,
% A C-differential operator must be declared as such,
% both forms have the same declaration.

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

symbolic procedure mk_superfun(superfun,num_arg,len_arg,len_target);
  % This procedures creates the superfunction of a
  % C-differential operator, superfun, and associates with the operator,
  % EXACTLY as in the standard C-diff. op. case,
  % 1 - the number of its arguments num_arg
  % 2 - the algebraic list of lengths of each of its arguments len_arg,
  % 3 - the length of the image vectors in the target space len_target
  % NOTE: to get the number of arguments do get('sfnarg,superfun);
  % to get the length of each of its argumens do get('sflarg,superfun);
  % to get the length of vectors in the target space do get('sftarget,superfun);
  % to see if an identifier is a superfun do get('sfun,superfun);
begin
  mkop superfun;
  put('sfun,superfun,t);
  if not numberp num_arg then rederr "Error in the number of arguments";
  put('sfnarg,superfun,num_arg);
  if not fixp num_arg then
    rederr "Error: number of arguments must be an integer";
  if not cde_alglistp(len_arg) then
    rederr "Error in the list of lengths of arguments";
  put('sflarg,superfun,len_arg);
  if not fixp len_target then
    rederr "Error: the length of image vectors must be an integer";
  put('sftarget,superfun,len_target);
end;

symbolic operator mk_superfun;

symbolic procedure superfunp(superfun);
  get('sfun,superfun);

symbolic procedure check_superfun_onearg(superfun);
  % Checks if the superfunction of a CDiff operator
  % has exactly one argument.
  begin
    scalar len_arg;
    integer num_arg,n_arg,len_target;
    if not superfunp(superfun) then
      rederr "Error: the first argument must be a declared CDiff operator";
    if not eqn(num_arg:=get('sfnarg,superfun),1) then
      rederr "Error: the operator must have exactly one argument";
    if not cde_alglistp(len_arg:=get('sflarg,superfun)) then
      rederr "Error: the length of arguments must be an algebraic list";
    if not eqn(length(len_arg),2) then
      rederr "Error: the operator must have exactly one argument";
    if not fixp(n_arg:=cadr(len_arg)) then
      rederr "Error: the dimension of the argument space must be an integer";
    if not fixp(len_target:=get('sftarget,superfun)) then
      rederr "Error: the length of image vectors must be an integer";
  end;

symbolic procedure check_superfun_scalar(superfun);
  % Checks if the superfunction of a CDiff operator has one-dimensional target.
  begin
    integer len_target;
    if not superfunp(superfun) then
      rederr "Error: the first argument must be a declared superfunction";
    if not fixp(len_target:=get('sftarget,superfun)) then
      rederr "Error: the dimension of the target space must be an integer";
    if not eqn(len_target,1) then
      rederr "Error: the dimension of the target space must be one";
  end;

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
  len_target:=get('cdtarget,cdiff_op);
  if not eqn(cadr len_arg,len_target) then
    rederr "dependent variables and target space dimension mismatch";
  mk_superfun(superfun,1,len_arg,len_target);
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

symbolic procedure conv_genfun2vform(genfun_odd,vform);
  % Convert a superfunction of a CDiff-operator in one argument, i.e.  a
  % linear function on odd variables, into a variational 2-form
  % by odd left multiplication by the vector of odd variables.
begin scalar len_arg,len_target,num_arg;
  check_superfun_onearg(genfun_odd);
  num_arg:=get('sfnarg,genfun_odd);
  len_arg:=get('sflarg,genfun_odd);
  len_target:=get('sftarget,genfun_odd);
  if not eqn(len_target,length(odd_var!*)) then rederr
    "Error: The number of components is not equal to the number of odd vars";
  mk_superfun(vform,
    1+num_arg,
    reverse(cons(length(odd_var!*),reverse(len_arg))),
    1);
  vform(1):=replace_extodd aeval cons('plus,
    for i:=1:len_target collect
      odd_product(nth(odd_var!*,i),aeval list(genfun_odd,i))
     );
end;

symbolic operator conv_genfun2vform;

symbolic procedure conv_genfun2biv(genfun_odd,biv);
  % Convert a superfunction of a CDiff-operator in one argument, i.e.  a
  % linear function on odd variables, into a bivector by odd multiplication by
  % the vector of odd variables.
begin scalar len_arg,len_target,num_arg;
  check_superfun_onearg(genfun_odd);
  num_arg:=get('sfnarg,genfun_odd);
  len_arg:=get('sflarg,genfun_odd);
  len_target:=get('sftarget,genfun_odd);
  if not eqn(len_target,length(odd_var!*)) then rederr
    "Error: The number of components is not equal to the number of odd vars";
  mk_superfun(biv,
    1+num_arg,
    reverse(cons(length(odd_var!*),reverse(len_arg))),
    1);
  biv(1):=replace_extodd aeval cons('plus,
    for i:=1:len_target collect
      odd_product(aeval list(genfun_odd,i),nth(odd_var!*,i))
     );
end;

symbolic operator conv_genfun2biv;

symbolic procedure define_cdiffop(superfun_ij,cdiff_op_list);
  % cdiff_op_list must be of the type (cdiff_op ii jj);
  % This procedure defines a scalar operator from a superfunction
  % which is linear in one single odd variable and its derivatives.
  % Warning: no check is performed on arguments!
    begin
      scalar cdiffopn,cdiffopind,exprop,phi,tempcoeff,tempoddvar,tempmind,
	change_expand_td,tempivars;
      cdiffopn:=car cdiff_op_list;
      cdiffopind:=cdr cdiff_op_list;
      phi:=gensym();
      exprop:=nil ./ 1;
      change_expand_td:=0;
      if eq(get('td,'simpfn),'compute_td) then
      <<
	change_expand_td:=1;
	noexpand_td()
      >>;
      for each el in superfun_ij do
      <<
	tempcoeff:=car el;
        tempoddvar:=cadr el;
        tempmind:=cadr idtomind(1,tempoddvar);
	tempivars:=for i:=1:n_indep_var join
	  list(nth(indep_var!*,i),nth(tempmind,i));
	exprop:=addsq(
	  simp aeval list('times,tempcoeff,append(list('td,phi),tempivars)),
	    exprop
	      );
      >>;
      cde_ev_forall cde_forall_form(
	cdiffopn,cdiffopind,list(phi),mk!*sq exprop
	  );
      return if eqn(change_expand_td,1) then expand_td()
    end;

symbolic procedure split_superfun(superfun,oddvar);
  % Given a scalar superfunction and an odd variable
  % returns an alist of identifiers of one odd variable in superfun paired
  % with its coefficient.
  begin
    scalar tempoddvars,superfun_split,tempcoeff;
%    tempoddvars:=select_all_ders(1,oddvar,all_parametric_odd!*);
    tempoddvars:=select_all_ders(1,oddvar,all_odd_id!*);
    superfun_split:=nil;
    for each el in tempoddvars do
      if not(eqn(tempcoeff:=coeffn(superfun,el,1),0))
      then superfun_split:=list(tempcoeff,el) . superfun_split;
    return superfun_split
  end;

symbolic procedure conv_superfun2cdiff(superfun,cdiff_op);
  % Inverse function to conv_cdiff2superfun;
  % for the moment it works only for superfunctions with one argument!
  % For any indices i,j, constructs the element a^j_{i,sigma}
  % as a superfunction of a scalar operator in the format of
  % an alist of identifiers of one odd variable paired with its coefficient
  % The alist is passed to define_cdiffop.
begin
  scalar len_arg,len_oddvar,superfun_ij;
  integer num_arg,n_arg,len_target;
  check_superfun_onearg(superfun);
  num_arg:=get('sfnarg,superfun);
  len_arg:=get('sflarg,superfun);
  n_arg:=cadr(len_arg);
  len_target:=get('sftarget,superfun);
  len_oddvar:=length(odd_var!*);
  mk_cdiffop(cdiff_op,1,len_arg,len_target);
  for j:=1:len_oddvar do
    for i:=1:len_target do
    <<
      superfun_ij:=split_superfun(aeval list(superfun,i),nth(odd_var!*,j));
      define_cdiffop(superfun_ij,list(cdiff_op,i,j))
    >>;
end;

symbolic operator conv_superfun2cdiff;

symbolic procedure cde_cdiff();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
