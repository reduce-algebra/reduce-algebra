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

% $Id$
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

% Procedures for loading an operator defined by its coefficients
% Format of the algebraic list of coefficients of a scalar CDiff-operator:
% {{coeff1,arg1_mind,arg2_mind,...},{coeff2,arg1_mind,arg2_mind,...},...}
% The external list must have the same namber as
% the number of arguments of `opname'

algebraic operator oddprod!*;
% The operator oddprod defaults to computing odd products
% For internal use only
put('oddprod!*,'simpfn,'ev_odd_product);

symbolic procedure ev_odd_product u;
simp odd_product(car u,cadr u);

symbolic procedure load_cdiffop0(opname,inds,l_coeff);
  % Defines an entry of a CDiff-op or a sCDiff-op
  begin
    scalar argprop,narg,l_phi,exprop,tempexp,tempcf,templmind,change_expand_td;
    if cdiffp(opname) then argprop:='cdnarg else
      if scdiffp(opname) then argprop:='scdnarg;
    narg:=get(argprop,opname);
    l_phi:=for i:=1:narg collect gensym();
    exprop:=0;
    change_expand_td:=0;
    if eq(get('td,'simpfn),'compute_td) then
    <<
      change_expand_td:=1;
      noexpand_td()
    >>;
    % Evaluate odd_product to itself
    put('oddprod!*,'simpfn,'simpiden);
    % Remember: el={arg,mind1,mind2,...} is an algebraic list below.
    for each el in l_coeff do
    <<
      tempexp:=1;
      tempcf:=cadr el;
      if not(eq(tempcf,0)) then
	<<
          templmind:=cddr el;
          for i:=1:narg do
            tempexp:=
	      aeval list('oddprod!*,
	        list('td_mind,nth(l_phi,i),nth(templmind,i)),
	        tempexp
	          );
          tempexp:=aeval list('oddprod!*,tempcf,tempexp);
          exprop:=aeval list('plus,tempexp,exprop);
	>>;
    >>;
    %    if not(eq(aeval mk!*sq exprop,0)) then
    cde_ev_forall cde_forall_form(
	opname,inds,l_phi,exprop
	  );
    put('oddprod!*,'simpfn,'ev_odd_product);
    return if eqn(change_expand_td,1) then expand_td()
  end;

symbolic procedure load_cdiffop(opname,inds,l_coeff);
  % Loads and defines a CDiff-operator `opname'
  % that was previously defined as such by mk_cdiffop.
  % Uses `inds' as the algebraic list of indices
  % and l_coeff as the list of coefficients of each total derivative
  % Format of the algebraic list of coefficients of a scalar CDiff-operator:
  % {{coeff1,arg1_mind,arg2_mind,...},{coeff2,arg1_mind,arg2_mind,...},...}
  % The external list must have the same namber as
  % the number of arguments of `opname'
  begin
    scalar narg;
    if not cdiffp(opname) then rederr
      "The first argument must be a declared C-Differential operator";
    narg:=get('cdnarg,opname);
    if not eqn(narg,length(inds)-2) then rederr
      "Second argument: wrong number of indices";
    for each el in cdr(l_coeff) do
      if not eqn(narg,length(el) - 2) then rederr
      	"Third argument: wrong number of arguments";
    load_cdiffop0(opname,cdr inds,cdr replace_oddext(l_coeff));
  end;

symbolic operator load_cdiffop;

% Procedures for getting all coefficients of a CDiff op.
% The format is described above.

symbolic procedure coeff_cdiffop0(cdop,l_ind,mind);
  % Extract the coefficient of `cdop(i,j_1,...,j_k,*)'
  % with respect to a multiindex `mind'.
  % Algorithm: compute cdop(l_ind,(1/mind!)x^mind);
  % substitute zero to all independent values.
  % NOTE: at the moment it will work with operators with one argument only
  begin
    scalar tempmon,zero_indep_var;
    for i:=1:n_indep_var do
      tempmon:=cons(aeval list('expt,nth(indep_var!*,i),nth(mind,i)),
 	tempmon);
    tempmon:=cons(aeval list('expt,factorial_multiindex(mind),-1),tempmon);
    tempmon:=aeval cons('times,tempmon);
    zero_indep_var:=for each el in indep_var!* collect
      list('replaceby,el,0);
    return cadr evalwhereexp(
      list('list . zero_indep_var,
	list('list,aeval(append(cons(cdop,l_ind),list(tempmon)))))
    	);
  end;

symbolic procedure coeff_cdiffop(cdop,l_ind,mind);
  replace_extodd(coeff_cdiffop0(cdop,cdr l_ind,cdr mind));

symbolic operator coeff_cdiffop;

symbolic procedure all_coeff_cdiffop0(cdop);
  % Extract all coefficients of a CDiff operator with one argument
  begin
    scalar listcoeff0,l_arg,l_tar,tempcf,tlist;
    listcoeff0:=list();
    check_cdiff_onearg(cdop);
    l_arg:=cadr get('cdlarg,cdop);
    l_tar:=get('cdtarget,cdop);
    for i:=1:l_tar do
      for j:=1:l_arg do
      <<
	tlist:=list();
	for each mind in all_mind!* do
	  if not(eqn(tempcf:=coeff_cdiffop0(cdop,list(i,j),mind),0)) then
	    tlist:=cons(cde_mal(list(tempcf,cde_mal(mind))),tlist);
	if not(tlist) then
 	  tlist:=list('list,cde_mal(list(0,cde_mal(nth(all_mind!*,1)))))
	else tlist:=cde_mal(cons(cde_mal(list(i,j)),tlist));
	listcoeff0:=cons(tlist,listcoeff0)
      >>;
    return cde_mal(listcoeff0)
  end;

symbolic procedure all_coeff_cdiffop(cdop);
  all_coeff_cdiffop0(cdop);

symbolic operator all_coeff_cdiffop;

symbolic procedure coeff2cdiffop_entry(cdop,ind_par);
  % Defines one entry of a CDiffop `cdop',
  % ind_par must be in the format of the algebraic list
  % {{i,j},{coeff,mind},{coeff2,mind2},...}
  % NOTE: it works for operators with one argument only!
  begin
    scalar ind_par0,exprop,phi,t_ind,t_allcoeff,
      t_coeff0;
    ind_par0:=cdr ind_par;
    phi:=gensym();
    exprop:=0;
    t_ind:=cdar ind_par0;
    t_allcoeff:=cdr ind_par0;
    for each t_coeff in t_allcoeff do
    <<
      t_coeff0:=cdr t_coeff;
%      exprop:=addsq(
%        simp aeval list('times,car t_coeff0,list('td_mind,phi,cadr t_coeff0)),
%          exprop
%            );
       exprop:=aeval list('plus,
         list('oddprod!*,car t_coeff0,aeval list('td_mind,phi,cadr t_coeff0)),
          exprop
            );
    >>;
    cde_ev_forall cde_forall_form(
      cdop,t_ind,list(phi),exprop
      );
  end;

symbolic procedure coeff2cdiffop(cdop,l_par);
  % Loads the definition of a CDiffop by the list of its coefficients
  % cdop must be a defined CDiff operator
  % l_par must be an algebraic list of elements of the form
  % {{i,j},{coeff1,mind1},{coeff2,mind2}...}
  % NOTE: it works for operators with one argument only!
    begin
      scalar l_par0,change_expand_td;
      check_cdiff_onearg(cdop);
      l_par0:=cdr replace_oddext(l_par);
      change_expand_td:=0;
      if eq(get('td,'simpfn),'compute_td) then
      <<
        change_expand_td:=1;
        noexpand_td()
      >>;
      put('oddprod!*,'simpfn,'simpiden);
      for each ind_par in l_par0 do coeff2cdiffop_entry(cdop,ind_par);
      put('oddprod!*,'simpfn,'ev_odd_product);
      if eqn(change_expand_td,1) then expand_td();
    end;

symbolic operator coeff2cdiffop;

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

%% Procedures for super-C-differential operators

symbolic procedure al_numberp(l);
  for each el in cdr l do if not(numberp(el)) then rederr
    "Error: the argument is not a list of integers";

symbolic procedure mk_scdiffop(scdiff_op,par,num_arg,len_arg,len_target);
% This procedures creates a super-C-differential operator cdiff_op
  % and associates with the operator:
  % 0 - the parity of the super-operator par
  % 1 - the number of its arguments num_arg
% 2 - the algebraic list of lengths of each of its arguments len_arg;
%  each length is a superdimension {p,q}
% 3 - the length of the image vectors in the target space len_target;
% it is a superdimension {p,q}
% For the moment we will restrict to super-C-differential operators
% with one argument. Such a super-C-differential operator is
% a supermatrix of scalar C-differential operators. Example:
% opname(i_t,i_a,psi)
% NOTE:
% to get the parity of the operator do get('scdpar,scdiff_op);
% to get the number of arguments do get('scdnarg,scdiff_op);
% to get the superlength of each of its argumens do
% get('scdlarg,scdiff_op);
% to get the superlength of vectors in the target space do
% get('scdtarget,scdiff_op);
% to see if an identifier is a cdop do get('scdop,scdiff_op);
begin
  mkop scdiff_op;
  put('scdop,scdiff_op,t);
  if not(numberp(par)) then rederr
    "Error: the parity must be an integer";
  put('scdpar,scdiff_op,par);
  if not(numberp(num_arg)) then rederr
    "Error: the number of arguments must be an integer";
  put('scdnarg,scdiff_op,num_arg);
  for each el in cdr len_arg do al_numberp(el);
  put('scdlarg,scdiff_op,len_arg);
  al_numberp(len_target);
  put('scdtarget,scdiff_op,len_target);
end;

symbolic operator mk_scdiffop;

symbolic procedure scdiffp(scdiff_op);
  get('scdop,scdiff_op);

symbolic procedure check_scdiff_onearg(scdiff_op);
  % Checks if the sCDiff operator has exactly one argument.
  begin
    scalar num_arg;
    if not scdiffp(scdiff_op) then
      rederr "Error: the first argument must be a declared s-CDiff operator";
    if not eqn(num_arg:=get('scdnarg,scdiff_op),1) then
      rederr "Error: the operator must have exactly one argument";
  end;

symbolic procedure load_scdiffop(opname,inds,l_coeff);
  % Loads and defines a super-CDiff-operator `opname'
  % that was previously defined as such by mk_scdiffop.
  % Uses `inds' as the algebraic list of indices
  % and l_coeff as the list of coefficients of each total derivative
  % Format of the algebraic list of coefficients of a scalar CDiff-operator:
  % {{coeff1,arg1_mind,arg2_mind,...},{coeff2,arg1_mind,arg2_mind,...},...}
  % The external list must have the same namber as
  % the number of arguments of `opname'
  begin
    scalar narg;
    if not scdiffp(opname) then rederr
      "The first argument must be a declared super-C-Differential operator";
    narg:=get('scdnarg,opname);
    if not eqn(narg,length(inds) - 2) then rederr
      "Second argument: wrong number of indices";
    for each el in cdr(l_coeff) do
      if not eqn(narg,length(el) - 2) then rederr
      	"Third argument: wrong number of arguments";
    load_cdiffop0(opname,cdr inds,cdr replace_oddext(l_coeff));
  end;

symbolic operator load_scdiffop;

% Extracting coefficients of super-C-differential operators

symbolic procedure all_coeff_scdiffop0(scdop);
  % Extract all coefficients of a sCDiff operator with one argument
  begin
    scalar listcoeff0,l_arg,l_tar,l_arg_tot,l_tar_tot,tempcf,tlist;
    listcoeff0:=list();
    check_scdiff_onearg(scdop);
    l_arg:=cadr get('scdlarg,scdop);
    l_tar:=get('scdtarget,scdop);
    l_arg_tot:=for each el in cdr l_arg sum el;
    l_tar_tot:=for each el in cdr l_tar sum el;
    for i:=1:l_tar_tot do
      for j:=1:l_arg_tot do
      <<
	tlist:=list();
	for each mind in all_mind!* do
	  if not(eqn(tempcf:=coeff_cdiffop0(scdop,list(i,j),mind),0)) then
	    tlist:=cons(cde_mal(list(tempcf,cde_mal(mind))),tlist);
	if not(tlist) then
 	  tlist:=list(cde_mal(list(0,cde_mal(nth(all_mind!*,1)))));
	tlist:=cde_mal(cons(cde_mal(list(i,j)),tlist));
	listcoeff0:=cons(tlist,listcoeff0)
      >>;
    return cde_mal(listcoeff0)
  end;

symbolic procedure all_coeff_scdiffop(cdop);
  replace_extodd(all_coeff_scdiffop0(cdop));

symbolic operator all_coeff_scdiffop;

symbolic procedure coeff2scdiffop(cdop,l_par);
  % Loads the definition of a sCDiffop by the list of its coefficients
  % cdop must be a defined sCDiff operator
  % l_par must be an algebraic list of elements of the form
  % {{i,j},{coeff1,mind1},{coeff2,mind2}...}
  % NOTE: it works for operators with one argument only!
    begin
      scalar l_par0,change_expand_td;
      check_scdiff_onearg(cdop);
      l_par0:=cdr replace_oddext(l_par);
      change_expand_td:=0;
      if eq(get('td,'simpfn),'compute_td) then
      <<
        change_expand_td:=1;
        noexpand_td()
      >>;
      put('oddprod!*,'simpfn,'simpiden);
      for each ind_par in l_par0 do coeff2cdiffop_entry(cdop,ind_par);
      put('oddprod!*,'simpfn,'ev_odd_product);
      if eqn(change_expand_td,1) then expand_td();
    end;

symbolic operator coeff2scdiffop;

symbolic procedure cde_cdiff();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
