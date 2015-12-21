module cde_totalder; % CDIFF package, definition of total derivatives

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

%-----------------------------------------------------------------------------%
% Procedures for the definition of total derivatives
%-----------------------------------------------------------------------------%

symbolic procedure set_svf(comp,i,j,val);
   % This procedure is needed because REDUCE refuses
   % to define or evaluate an operator in an iteration by a direct call.
   comp(i,j):=val;

symbolic procedure coeff_totder(par,var,i);
   % this procedure finds the coefficient u^a_{\sigma i}
   % of \pd{}{u^a_\sigma}, where u^a_\sigma is an element of a list
   % of variables `variables'. A similar procedure is introduced
   % for odd coordinates. Does not work with ext!
   begin scalar var_mind,vartemp,miptemp;
     var_mind:=idtomind(par,var);
      vartemp:=car var_mind;
      miptemp:=cadr assoc(cadr var_mind,all_mind_table!*);
      if miptemp then
        if par=0 then
          return
 	    car cde_lassoc2(list(vartemp,nth(miptemp,i)),i2m_jetspace!*)
        else
          return
 	    car cde_lassoc2(list(vartemp,nth(miptemp,i)),i2m_jetspace_odd!*)
      else return 'letop;
   end;

symbolic procedure initialize_td_indep_var(td);
begin scalar ddtemp;
  % Initialization of the independent variable part of all total derivatives
  return for i:=1:n_indep_var do
  <<
    ddtemp:=nth(td,i);
    for j:=1:n_indep_var do
      if i=j then set_svf(ddtemp,0,j,1) else set_svf(ddtemp,0,j,0)
  >>
end;

symbolic procedure initialize_td_even_var(td,param_der,princ_der);
  begin scalar ddtemp,dcon,var_i; integer j,n_param_der;
    n_param_der:=length(param_der);
    for i:=1:n_indep_var do
    <<
      ddtemp:=nth(td,i);
      j:=0;
      for each el in param_der do
      <<
	j:=j+1;
	var_i:=coeff_totder(0,el,i);
	if member(var_i,all_principal_der!*) then
	  dcon:=list(ddtemp,0,j+n_indep_var,var_i) . dcon;
	set_svf(ddtemp,0,j+n_indep_var,var_i)
      >>;
      j:=0;
      for each el in princ_der do
      <<
	j:=j+1;
	var_i:=coeff_totder(0,el,i);
	set_svf(ddtemp,0,j+n_indep_var+n_param_der,var_i)
      >>
    >>;
    return dcon
  end;

symbolic procedure initialize_td_odd_var(td,param_ext,princ_ext);
  begin scalar ddtemp,dcon_odd,ovar_i; integer j,n_param_ext;
    n_param_ext:=length(param_ext);
    for i:=1:n_indep_var do
    <<
      ddtemp:=nth(td,i);
      j:=0;
      for each el in param_ext do
      <<
	j:=j+1;
	ovar_i:=coeff_totder(1,extodd(el),i);
	if not equal(ovar_i,'letop) then
	<<
	  if member(ovar_i,all_principal_odd!*) then
	    dcon_odd:=list(ddtemp,1,j,ovar_i) . dcon_odd;
	  set_svf(ddtemp,1,j,oddext(ovar_i))
	>>
	else set_svf(ddtemp,1,j,'letop)
      >>;
      j:=0;
      for each el in princ_ext do
      <<
	j:=j+1;
	ovar_i:=coeff_totder(1,extodd(el),i);
	if not equal(ovar_i,'letop) then
	  set_svf(ddtemp,1,j+n_param_ext,oddext(ovar_i))
	else set_svf(ddtemp,1,j+n_param_ext,'letop)
      >>
    >>;
    return dcon_odd;
  end;

symbolic procedure cde_odd_derivatives(ext_vars);
  % Definition of the derivatives with respect to parametric odd variables.
  % Introducing vector fields `svf_ext'(i) where i stands for the number
  % of the ext variable.
  % It will be used in the definition of the variational derivative,
  % this is why we only need parametric odd derivatives.
begin scalar svf_temp; integer n_ext;
  n_ext:=n_all_parametric_ext + n_all_principal_ext;
  return for i:=1:n_ext do
  <<
    svf_temp:=mkid('svf_ext,i);
    super_vectorfield(svf_temp,{},ext_vars);
    for j:=1:n_ext do
      set_svf(svf_temp,1,j,if eqn(i,j) then 1 else 0)
  >>
end;

symbolic procedure df_odd(expr_odd,oddvar);
  % Definition of the derivative operator with respect to odd variables.
  % Everything is converted in the internal ext notation,
  % then back to external.
%%   begin scalar result;
    aeval list(
      mkid('svf_ext,cadr oddext(oddvar)),
      replace_oddext(expr_odd)
    	);
%%     if !*checkord then
%%       if not freeof(result,'letop) then
%%  	rederr "Presence of letop, jetspace too small!";
%%     return result
%%   end;

symbolic operator df_odd;

symbolic procedure df_ext(expr_ext,extvar);
  % Definition of the derivative operator with respect to odd variables.
  % Everything is in the internal ext notation, should be faster than df_odd
%%   begin scalar result;
    aeval list(mkid('svf_ext,cadr extvar),expr_ext);
%%     if !*checkord then
%%       if not freeof(result,'letop) then
%%  	rederr "Presence of letop, jetspace too small!";
%%     return result;
%%   end;

symbolic operator df_ext;

symbolic procedure iter_dd(dd_name,arg_ext,n);
  if eqn(n,0) then arg_ext
    else list(dd_name,iter_dd(dd_name,arg_ext,n-1));

% The following code works to compute td, but I want more!

%% symbolic procedure td(arg,indvar,ord);
%%   % Define total derivative with name `td'(var)
%%   if !*expand_td then
%%   begin scalar arg_ext,tdres,dd_name;
%%     arg_ext:=replace_oddext0(arg);
%%     dd_name:=nth(tot_der!*,cde_position(indvar,indep_var!*));
%%     tdres:=aeval iter_dd(dd_name,arg_ext,ord);
%%     if !*checkord then
%%       if not freeof(tdres,'letop) then
%%  	rederr "Presence of letop, jetspace too small!";
%%     return replace_extodd0(tdres)
%%   end
%%   else simpiden list(td,arg,indvar,ord);
%%
%% symbolic operator td;

symbolic procedure compute_td u; %(arg,indvar,ord);
  % Define total derivative with name `td'(var)
  begin scalar indvars,temppos,tempivar,tempindex,tdres,dd_name;
    tdres:=replace_oddext0(car u);
    indvars:=cdr u;
    while not(null(indvars)) do
    <<
      if not(null(temppos:=cde_position(tempivar:=car indvars,indep_var!*)))
      then
	<<
          dd_name:=nth(tot_der!*,temppos);
          if not(null(cdr indvars)) and fixp(tempindex:=cadr indvars) then
	  <<
	    tdres:=aeval iter_dd(dd_name,tdres,tempindex);
	    indvars:=cddr indvars
	  >>
	  else
	  <<
	    tdres:=aeval list(dd_name,tdres);
	    indvars:=cdr indvars
	  >>;
	>>
      else rederr "Wrong number of arguments to `td'"
    >>;
    if !*checkord then check_letop(tdres);
    return simp replace_extodd0(tdres)
  end;

algebraic operator td;
% The operator td defaults to expanding total derivatives:
put('td,'simpfn,'compute_td);

%% Code for total derivative with multiindexes
%% 
%% symbolic procedure iter_td(mind,arg);
%%   % Computes the total derivative D_mind(arg)
%%   begin
%%     for i:=1:n_indep_var do
%%     <<
%%       arg:=simp aeval iter_dd(nth(tot_der!*,i),arg,nth(mind,i));
%%     >>;
%%     print arg;
%%      if !*checkord then
%%       if not freeof(arg,'letop) then
%%  	rederr "Presence of letop, jetspace too small!";
%%     return arg
%%   end;
%% 
%% symbolic procedure compute_td_mind u; %u:(mind,arg),
%%   % where mind is an algebraic multiindex and arg is an odd var
%%   % replace_extodd iter_td(cdar u,<<prin2t cadr u; replace_oddext(cadr u)>>);
%%   begin
%%     scalar val;
%%     val:=iter_td(cdar u,simp replace_oddext(cadr u));
%%     prin2t "ora valuto replace_extodd...";
%%     return simp replace_extodd0(val);
%%   end;
%% 
%% algebraic operator td_mind;
%% The operator td_mind defaults to expanding total derivatives:
%% put('td_mind,'simpfn,'compute_td_mind);

% Go with one of the following when you need to change the behaviour

algebraic procedure expand_td();
%%  <<put('td,'simpfn,'compute_td); put('td_mind,'simpfn,'compute_td_mind)>>;
  put('td,'simpfn,'compute_td);

algebraic procedure noexpand_td();
%%  <<put('td,'simpfn,'simpiden); put('td_mind,'simpfn,'simpiden)>>;
  put('td,'simpfn,'simpiden);

symbolic procedure cde_total_derivatives();
begin scalar tempprinc_der,tempprinc_odd,all_ext;
   % Definition of the total derivatives vector fields,
   % together with the lists of all even and odd principal derivatives
   % which are components of parametric derivatives.
   % Definition of derivatives with respect to single odd variables.
   %
   % Total derivatives identifiers (ext notation): ddx, ddt,...,
   % NOTE: if you wish to change the prefix, change the variable id_tot_der
   tot_der!*:=for i:=1:n_indep_var collect
     mkid(id_tot_der!*,nth(indep_var!*,i));
   % Total derivatives: declaration.
   n_all_ext:=n_all_parametric_ext + n_all_principal_ext;
   all_ext:=for i:=1:n_all_ext collect list('ext,i);
   for i:=1:n_indep_var do
   <<
     % Auxiliary variable `letop'. It appears
     % in computations where total_order is too low.
     algebraic depend letop,part(indep_var,i);
     % Initialize total derivatives in ext variables
     super_vectorfield(nth(tot_der!*,i),
       append(indep_var!*,append(all_parametric_der!*,all_principal_der!*)),
       all_ext
     	 )
   >>;
   % Definition of total derivatives.
   % The output format of initialize_td is a list of two elements.
   % The first element is a list of elements of the form
   % {ddtemp,0,j+n_indep_var,var_i}
   % The second element is a list of elements of the form
   % {ddtemp,1,j,ovar_i}
   initialize_td_indep_var(tot_der!*);
   primary_diffcon_der_tot!*:=reverse initialize_td_even_var(
     tot_der!*,all_parametric_der!*,all_principal_der!*
       );
   primary_diffcon_odd_tot!*:=reverse initialize_td_odd_var(
     tot_der!*,
     for i:=1:n_all_parametric_ext collect list('ext,i),
     for i:=1:n_all_principal_ext collect list('ext,i+n_all_parametric_ext)
       );
   % In the following lists, initial principal derivatives are removed
   % because we do not need to compute their expression.
   % Such lists are said to be `primary differential consequences'
   tempprinc_der:=cde_mkset(for each el in primary_diffcon_der_tot!*
     collect car reverse el);
   primary_diffcon_der!*:=cde_diffset(tempprinc_der,principal_der!*);
   tempprinc_odd:=cde_mkset(for each el in primary_diffcon_odd_tot!*
     collect car reverse el);
   primary_diffcon_odd!*:=cde_diffset(tempprinc_odd,principal_odd!*);
   % Defines the vector fields `svf_ext'(i) which are used to take derivatives
   % with respect to odd coordinates.
   cde_odd_derivatives(all_ext);
end;

endmodule;

end;
