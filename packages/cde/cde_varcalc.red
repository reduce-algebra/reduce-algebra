module cde_varcalc; % CDE package, calculus of variations
                    % with anticommuting variables

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

%
%-----------------------------------------------------------------------------%
% Calculus of variations with anticommuting variables
%-----------------------------------------------------------------------------%
%

symbolic procedure pvar_df(par,density_odd,component);
% Definition of the partial Euler-Lagrange operator.
% It is of the form (-1)^abs(sigma)*D_sigma df(,u^i_sigma)
% where u^i=component and sigma is such that u^i_sigma is parametric.
% When the equation is evolutionary the component of sigma
% corresponding to the evolutionary variable is zero.
% In this case the partial Euler-Lagrange operator yields
% generating functions of conservation laws.
% When the equation is empty we have the full Euler-Lagrange operator.
% NOTE: the input density density_odd and the component
% must be in odd variables!
begin scalar result;
  if par=0 then result:=pvar_df0(density_odd,component)
  else result:=pvar_df1(density_odd,component);
  return replace_extodd(aeval cons('plus,result))
end;

symbolic procedure pvar_df0(density_odd,component);
  begin scalar density_ext,tempvar,tempmind,exprtemp,result;
  density_ext:=replace_oddext(density_odd);
  for each el in all_parametric_der!* do
    <<
      tempvar:=idtomind(0,el);
      if equal(car tempvar,component) then
      <<
        tempmind:=cadr tempvar;
        exprtemp:=
          aeval list('times,
	    list('expt, - 1,length_multiindex(tempmind)),
	    list('df,density_ext,el)
	      );
        for i:=1:n_indep_var do
          for j:=1:nth(tempmind,i) do
            exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
	if !*checkord then check_letop(exprtemp);
        result:=exprtemp . result
      >>
    >>;
    return result
end;

symbolic procedure pvar_df1(density_odd,component);
begin scalar tempvar,tempmind,exprtemp,density_ext,result;
  density_ext:=replace_oddext(density_odd);
  for each el in all_parametric_odd!* do
  <<
    tempvar:=idtomind(1,el);
    if equal(car tempvar,component) then
    <<
      tempmind:=cadr tempvar;
      exprtemp:=
	aeval list('times,
	  list('expt, - 1,length_multiindex(tempmind)),
	  list('df_ext,density_ext,oddext(el))
	    );
      for i:=1:n_indep_var do
        for j:=1:nth(tempmind,i) do
          exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
      if !*checkord then check_letop(exprtemp);
      result:=exprtemp . result;
    >>
  >>;
  return result
end;

symbolic operator pvar_df;

symbolic procedure euler_df(density);
% Computes the Euler operator of a (possibly odd) density
% The output is in the form of an ALGEBRAIC list of two sublists,
% the first contains variational derivatives with respect to even variables,
  % the second contains variational derivatives with respect to odd variables.
  begin scalar templist1,templist2;
    templist1:='list . for each el in dep_var!* collect pvar_df(0,density,el);
    templist2:='list . for each ell in odd_var!* collect pvar_df(1,density,ell);
    return cons('list,list(templist1,templist2));
  end;

symbolic operator euler_df;

symbolic procedure schouten_bracket_expr(mve1,parity1,mve2,parity2);
  % Compute the expression of the Schouten bracket of two multivectors;
  % mve1, mve2 are two multivectors in odd variable notation;
  % they are converted into ext variable notation befor computing by `pvar'.
  begin scalar tempterm1,tempterm2,tempsign,n_dep_var;
  n_dep_var:=length(dep_var!*);
  if n_dep_var neq length(odd_var!*) then rederr
    "Error: number of even and odd variables mismatch!";
  tempterm1:=for i:=1:n_dep_var collect
   super_product(
     aeval cons('plus,pvar_df0(mve2,nth(dep_var!*,i))),
     aeval cons('plus,pvar_df1(mve1,nth(odd_var!*,i)))
       );
  tempsign:=aeval list('times,-1,list('expt, - 1,
    list('times,parity1 + 1,parity2 + 1)
      ));
%  print tempsign;
  tempterm2:=for i:=1:n_dep_var collect
    aeval list('times,tempsign,super_product(
    aeval cons('plus,pvar_df0(mve1,nth(dep_var!*,i))),
    aeval cons('plus,pvar_df1(mve2,nth(odd_var!*,i)))
      ));
  if !*checkord then
  <<
    check_letop(tempterm1);
    check_letop(tempterm2)
  >>;
  return replace_extodd(aeval cons('plus,append(tempterm1,tempterm2)))
  end;

symbolic procedure schouten_bracket(mv1,mv2,mv3);
  % Compute the Schouten bracket of two multivectors [mv1,mv2]=mv3.
  % An initial check is performed, then the arguments are passed to
  % to schouten_bracket_expr for actual computation.
  % Multivectors must be input (and declared!)
  % as homogeneous superfunctions of odd degree k
  % See Kersten, Krasilshchik and Verbovetsky, J. Geom. Phys. 2003 for formulae
  begin
    scalar parity1,parity2,n_odd_var;
    n_odd_var:=length(odd_var!*);
    parity1:=get('sfnarg,mv1);
    parity2:=get('sfnarg,mv2);
    check_superfun_scalar(mv1);
    check_superfun_scalar(mv2);
    mk_superfun(mv3,
      parity1 + parity2 - 1
%     ,cons('list,for i:=1:(parity1+parity2-1) collect n_odd_var)
	,1);
    mv3(1):=schouten_bracket_expr(aeval list(mv1,1),parity1,
      aeval list(mv2,1),parity2);
  end;

symbolic operator schouten_bracket;

symbolic procedure iszero_schouten_bracket(mv1,mv2,mv3);
  begin
    schouten_bracket(mv1,mv2,mv3);
    return euler_df(aeval list(mv3,1))
  end;

symbolic operator iszero_schouten_bracket;

%% symbolic procedure schouten_bracket_old(biv1,biv2);
%% % Compute the Schouten bracket of two bivectors; bivectors are input
%% % in ext notation (for the moment ...)
%% % See Kersten, Krasilshchik and Verbovetsky for formulae
%% begin scalar tempterm1,tempterm2; integer n_dep_var;
%%   n_dep_var:=length(dep_var!*);
%%   if n_dep_var neq length(odd_var!*) then rederr
%%     "Error: number of even and odd variables mismatch!";
%%   tempterm1:=for i:=1:n_dep_var collect
%%    super_product(
%%      replace_oddext(pvar_df(0,biv1,nth(dep_var!*,i))),
%%      replace_oddext(pvar_df(1,biv2,nth(odd_var!*,i)))
%%        );
%%   tempterm2:=for i:=1:n_dep_var collect
%%     super_product(
%%     replace_oddext(pvar_df(0,biv2,nth(dep_var!*,i))),
%%     replace_oddext(pvar_df(1,biv1,nth(odd_var!*,i)))
%%       );
%%   if !*checkord then
%%   <<
%%     check_letop(tempterm1);
%%     check_letop(tempterm2)
%%   >>;
%%   return euler_df(aeval cons('plus,append(tempterm1,tempterm2)))
%% end;
%% 
%% symbolic operator schouten_bracket_old;

symbolic procedure cartan_df_expr(sfun_expr);
  % Compute the expression of the Cartan differential, see below
  begin
    scalar sfun_out_list,tempvar_mind,tempevar,tempmind,tempovar;
    sfun_out_list:=for each el in all_parametric_der!* collect
    <<
      tempvar_mind:=idtomind(0,el);
      tempevar:=car tempvar_mind;
      tempmind:=cadr tempvar_mind;
      tempovar:=nth(odd_var!*,cde_position(tempevar,dep_var!*));
      odd_product(
	mind_to_eid(list(tempovar,tempmind)),
	aeval list('df,sfun_expr,el)
	  )
    >>;
    return aeval cons('plus,sfun_out_list)
  end;

symbolic procedure cartan_df(sfun,sfun_out);
  % Compute the Cartan, or vertical, differential of a skew-symmetric
  % form with values in densities which is identified with a superfunction
  % with one-dimensional target.
  % The cartan differential can be used to compute the
  % variational differential e_1
  begin
    check_superfun_scalar(sfun);
    mk_superfun(sfun_out,
      1+get('sfnarg,sfun)
%	,
%      reverse(cons(length(odd_var!*),reverse(get('sflarg,sfun))))
	,1);
    sfun_out(1):=cartan_df_expr(aeval list(sfun,1));
  end;

symbolic operator cartan_df;

symbolic procedure variational_df_expr(sfun_expr);
  begin
    scalar sfun_out_list,tempvar_mind,tempvars,tempmind,tempovar,exprtemp;
    sfun_out_list:=for each el in odd_var!* join
    <<
      tempvars:=select_all_ders(1,el,all_parametric_odd!*);
      for each ell in tempvars collect
      <<
	tempvar_mind:=idtomind(1,ell);
	tempovar:=car tempvar_mind;
	tempmind:=cadr tempvar_mind;
	exprtemp:=
	  aeval list('times,
	    list('expt, - 1,length_multiindex(tempmind)),
	    df_odd(sfun_expr,ell)
	      );
	for i:=1:n_indep_var do
	  for j:=1:nth(tempmind,i) do
	    exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
	if !*checkord then check_letop(exprtemp);
	odd_product(tempovar,exprtemp)
      >>
    >>;
    return aeval cons('plus,sfun_out_list)
  end;

symbolic procedure variational_df(sfun,sfun_out);
  % Computes the variational differential e_1
  begin
    check_superfun_scalar(sfun);
    mk_superfun(sfun_out,
      1+get('sfnarg,sfun)
%	,
%      reverse(cons(length(odd_var!*),reverse(get('sflarg,sfun))))
	,1);
    sfun_out(1):=variational_df_expr(cartan_df_expr(aeval list(sfun,1)));
  end;

symbolic operator variational_df;

% Procedures for the variational Nijenhuis bracket

symbolic procedure ev_superfun_even(superf1,superf_scal);
  % Computes the even summand of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket!
  begin
    scalar tempvar,tempmind,tempdvar,ntempdvar,tempres,der_even, exprtemp;
    tempres:=
    for each el in all_parametric_der!* collect
    <<
      der_even:=aeval list('df,replace_oddext(superf_scal),el);
      if equal(der_even,0) then 0 else
	<<
          tempvar:=idtomind(0,el);
          tempmind:=cadr tempvar;
          tempdvar:=car tempvar;
          ntempdvar:=cde_position(tempdvar,dep_var!*);
          exprtemp:=replace_oddext(aeval list(superf1,ntempdvar));
          for i:=1:n_indep_var do
          for j:=1:nth(tempmind,i) do
          exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
          if !*checkord then check_letop(exprtemp);
          super_product(exprtemp,der_even)
	>>
    >>;
    return aeval cons('plus,tempres)
  end;

symbolic procedure ev_superfun_odd(superf1,superf_scal);
  % Computes the odd summand of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket!
  begin
    scalar tempovar,tempmind,ntempovar,tempres,der_odd,exprtemp;
    tempres:=
    for each el in all_parametric_odd!* collect
    <<
      der_odd:=coeffn(superf_scal,el,1);
      if equal(der_odd,0) then 0 else
	<<
          tempovar:=idtomind(1,el);
          tempmind:=cadr tempovar;
          tempovar:=car tempovar;
          ntempovar:=cde_position(tempovar,odd_var!*);
          % Next expression is X(superf_scalar), which is equivalent
          % to the Cartan differential of the superfunction
          exprtemp:=replace_oddext(
	    cartan_df_expr(aeval list(superf1,ntempovar))
	  );
          for i:=1:n_indep_var do
            for j:=1:nth(tempmind,i) do
              exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
          if !*checkord then check_letop(exprtemp);
          aeval list('times,der_odd,exprtemp)
	>>
    >>;
    return aeval list('times,-1,cons('plus,tempres))
  end;

symbolic procedure ev_superfun(superf1,superf_scal);
  % Computes the essential part of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket
  aeval list('plus,
    ev_superfun_even(superf1,superf_scal),
    ev_superfun_odd(superf1,superf_scal)
  );

symbolic procedure nijenhuis_bracket(superf1,superf2,superf3);
  % Procedure for the Nijenhuis bracket of two local operators.
  % There is an argument check and then the actual computation
  % is performed by ev_superfun.
  begin
    scalar n_dep_var;
    if not(length(dep_var!*)=length(odd_var!*)) then
      rederr "The bracket can be computed only if even and odd variables
        are in equal number";
    n_dep_var:=length(dep_var!*);
    if not superfunp(superf1) then
      rederr "The first argument must be a declared superfunction";
    if not(get('sfnarg,superf1)=1) then
      rederr "The first argument must be a linear function of odd variables";
    if not(get('sftarget,superf1)=length(dep_var!*)) then
      rederr "The first argument must be a vector-valued function with m args";
    if not superfunp(superf2) then
      rederr "The second argument must be a declared superfunction";
    if not(get('sfnarg,superf2)=1) then
      rederr "The second argument must be a linear function of odd variables";
    if not(get('sftarget,superf2)=length(dep_var!*)) then
      rederr "The second argument must be a vector-valued function with m args";
    mk_superfun(superf3,2,n_dep_var);
    for j:=1:n_dep_var do
      superf3(j):=replace_extodd(
	aeval list('plus,
	ev_superfun(superf1,aeval list(superf2,j)),
 	ev_superfun(superf2,aeval list(superf1,j))
	  )
	    );
  end;

symbolic operator nijenhuis_bracket;

symbolic procedure cde_varcalc();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
