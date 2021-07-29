% Procedures for the Nijenhuis bracket of two recursion operators

% Author: R Vitolo

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

% $Id: $



symbolic procedure ev_superfun_even(superf1,superf_scal);
  % Computes the even summand of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket!
  begin
    scalar tempvar,tempmind,tempdvar,ntempdvar,exprtemp1,exprtemp2,tempres;
    tempres:=
    for each el in all_parametric_der!* collect
    <<
      tempvar:=idtomind(0,el);
      tempmind:=cadr tempvar;
      tempdvar:=car tempvar;
      ntempdvar:=cde_position(tempdvar,dep_var!*);
      exprtemp2:=aeval list('df,replace_oddext(superf_scal),el);
      if exprtemp2=0 then 0 else
      <<
        exprtemp1:=replace_oddext(aeval list(superf1,ntempdvar));
        for i:=1:n_indep_var do
        for j:=1:nth(tempmind,i) do
          exprtemp1:=aeval list(nth(tot_der!*,i),exprtemp1);
        if !*checkord then check_letop(exprtemp1);
        super_product(exprtemp1,exprtemp2)
      >>
    >>;
    return aeval cons('plus,tempres)
  end;

symbolic procedure ev_superfun_odd(superf1,superf_scal);
  % Computes the odd summand of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket!
  begin
    scalar tempovar,tempmind,tempovar,ntempovar,tempcoeff,exprtemp,tempres;
    tempres:=
    for each el in all_parametric_odd!* collect
    <<
      tempovar:=idtomind(1,el);
      tempmind:=cadr tempovar;
      tempovar:=car tempovar;
      ntempovar:=cde_position(tempovar,odd_var!*);
      tempcoeff:=aeval list('df,superf_scal,el);
      % Next expression is X(superf_scalar), which is equivalent
      % to the Cartan differential of the superfunction
      exprtemp:=replace_oddext(
	cartan_df_expr(aeval list(superf1,ntempovar))
	  );
      if exprtemp=0 then 0 else
      <<
        for i:=1:n_indep_var do
        for j:=1:nth(tempmind,i) do
          exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
        if !*checkord then check_letop(exprtemp);
        aeval list('times,tempcoeff,exprtemp)
      >>
    >>;
    return aeval list('times,-1,aeval cons('plus,tempres))
  end;

symbolic procedure ev_superfun(superf1,superf_scal);
  % Computes the essential part of the Nijenhuis bracket.
  % The superfunctions must have been checked in the procedure
  % nijenhuis_bracket!
  aeval list('plus,
    ev_superfun_even(superf1,superf_scal),
    ev_superfun_odd(superf1,superf_scal)
  );

symbolic procedure nijenhuis_bracket(superf1,superf2,superf3);
  % Procedure for the Nijenhuis bracket of two local operators.
  % There is an argument check and then the actual computation
  % is performed by ev_superfun.
  begin
    scalar n_dep_var,tempexpr1,tempexpr2;
    n_dep_var:=length(dep_var!*);
    if not(n_dep_var=length(odd_var!*)) then
      rederr "The bracket can be computed only if even and odd variables are in equal number";
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
    <<
      tempexpr1:=aeval list(superf1,j);
      tempexpr2:=aeval list(superf2,j);
      superf3(j):=
	replace_extodd(
	aeval list('plus,
	ev_superfun(superf1,tempexpr2),
 	ev_superfun(superf2,tempexpr1)
	  ));
    >>;
  end;

symbolic operator nijenhuis_bracket;

end;
