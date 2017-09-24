module cde_vectorfield;
% CDE package, data structure for vector fields on jet spaces.

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

% An evolutionary vector field is represented as a 'special' Reduce operator.
% It has the same number of even components as dependent variables
% and the same number of odd components as odd variables.

symbolic procedure mk_evfield(ev_field);
  begin
    super_vectorfield(ev_field,dep_var,replace_oddext(odd_var));
    put('evfield,ev_field,t);
  end;

symbolic operator mk_evfield;

symbolic procedure evfieldp(ev_field);
  get('evfield,ev_field);

symbolic procedure partial_even_jbracket(evfield1,evfield2,par,i,evenvar);
  begin
    scalar tempvar,tempmind,tempdvar,ntempdvar,exprtemp1,exprtemp2;
    tempvar:=idtomind(0,evenvar);
    tempmind:=cadr tempvar;
    tempdvar:=car tempvar;
    ntempdvar:=cde_position(tempdvar,dep_var!*);
    exprtemp1:=aeval list(evfield1,0,ntempdvar);
    exprtemp2:=aeval list(evfield2,0,ntempdvar);
    for i:=1:n_indep_var do
      for j:=1:nth(tempmind,i) do
        exprtemp1:=aeval list(nth(tot_der!*,i),exprtemp1);
    for i:=1:n_indep_var do
      for j:=1:nth(tempmind,i) do
        exprtemp2:=aeval list(nth(tot_der!*,i),exprtemp2);
    exprtemp1:=
      aeval list('times,exprtemp1,
	list('df,list(evfield2,par,i),evenvar));
    if !*checkord then check_letop(exprtemp1);
    exprtemp2:=
      aeval list('times,exprtemp2,
	list('df,list(evfield1,par,i),evenvar));
    if !*checkord then check_letop(exprtemp2);
    return aeval list('plus,exprtemp1,aeval list('times,-1,exprtemp2))
  end;

symbolic procedure partial_odd_jbracket(evfield1,evfield2,par,i,oddvar);
  begin
    scalar tempvar,tempmind,tempdvar,ntempdvar,exprtemp1,exprtemp2;
    tempvar:=idtomind(1,oddvar);
    tempmind:=cadr tempvar;
    tempdvar:=car tempvar;
    ntempdvar:=cde_position(tempdvar,odd_var!*);
    exprtemp1:=aeval list(evfield1,1,ntempdvar);
    exprtemp2:=aeval list(evfield2,1,ntempdvar);
    for i:=1:n_indep_var do
      for j:=1:nth(tempmind,i) do
        exprtemp1:=aeval list(nth(tot_der!*,i),exprtemp1);
    for i:=1:n_indep_var do
      for j:=1:nth(tempmind,i) do
        exprtemp2:=aeval list(nth(tot_der!*,i),exprtemp2);
    exprtemp1:=
      aeval list('times,exprtemp1,
	list('df_ext,list(evfield2,par,i),oddext(oddvar)));
    if !*checkord then check_letop(exprtemp1);
    exprtemp2:=
      aeval list('times,exprtemp2,
	list('df_ext,list(evfield1,par,i),oddext(oddvar)));
    if !*checkord then check_letop(exprtemp2);
    return aeval list('plus,exprtemp1,aeval list('times,-1,exprtemp2))
  end;

symbolic procedure jacobi_bracket(ev_field1,ev_field2,ev_field3);
  begin
    scalar n_dep_var,n_odd_var,cnt,tempeven,tempodd;
    n_dep_var:=length(dep_var!*);
    n_odd_var:=length(odd_var!*);
    if not evfieldp(ev_field1) then
      rederr "Error: the first argument must be a declared evolutionary field";
    if not evfieldp(ev_field2) then
      rederr "Error: the second argument must be a declared evolutionary field";
    mk_evfield(ev_field3);
    for par:=0:1 do
    <<
      if eqn(par,0) then cnt:=n_dep_var else cnt:=n_odd_var;
      for i:=1:cnt do
      <<
	tempeven:=
	  for each el in all_parametric_der!* collect
 	    partial_even_jbracket(ev_field1,ev_field2,par,i,el);
	tempodd:=
	  for each el in all_parametric_odd!* collect
 	    partial_odd_jbracket(ev_field1,ev_field2,par,i,el);
	set_svf(ev_field3,par,i,aeval cons('plus,append(tempeven,tempodd)))
      >>;
    >>;
  end;

symbolic operator jacobi_bracket;

symbolic procedure cde_vectorfield();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
