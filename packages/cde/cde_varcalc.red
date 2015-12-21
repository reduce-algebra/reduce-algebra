module cde_varcalc; % CDIFF package, calculus of variations
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

% % *****************************************************************
% Author and maintainer: Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo
%
% Version and Date:  2.0, October 2015.
%
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

symbolic procedure schouten_bracket(biv1,biv2);
% Compute the Schouten bracket of two bivectors; bivectors are input
% in ext notation (for the moment ...)
% See Kersten, Krasilshchik and Verbovetsky for formulae
begin scalar tempterm1,tempterm2; integer n_dep_var;
  n_dep_var:=length(dep_var!*);
  if n_dep_var neq length(odd_var!*) then rederr
    "Error: number of even and odd variables mismatch!";
  tempterm1:=for i:=1:n_dep_var collect
   super_product(
     replace_oddext(pvar_df(0,biv1,nth(dep_var!*,i))),
     replace_oddext(pvar_df(1,biv2,nth(odd_var!*,i)))
       );
  tempterm2:=for i:=1:n_dep_var collect
    super_product(
    replace_oddext(pvar_df(0,biv2,nth(dep_var!*,i))),
    replace_oddext(pvar_df(1,biv1,nth(odd_var!*,i)))
      );
  if !*checkord then
  <<
    check_letop(tempterm1);
    check_letop(tempterm2)
  >>;
  return euler_df(aeval cons('plus,append(tempterm1,tempterm2)))
end;

symbolic operator schouten_bracket;

symbolic procedure cde_varcalc();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
