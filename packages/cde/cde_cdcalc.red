module cde_cdcalc; % CDE package, calculus with C-differential operators

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
% Procedures for linearization and its adjoint

symbolic procedure ell_scalar_function_odd(fct);
% Linearization of a scalar function in terms of superfunction of the
% corresponding operator. Note that odd variables must be same in number as
% even variables, as the linearization is an operator of the type
% \ell_F : \kappa \to P
begin
  scalar superfun,tempvarmind,tempdvar,tempmind,tempoddvar;
  if not(cde_freeofl(all_parametric_odd!*,fct)) then
    rederr "Linearization only works for even functions";
  if not(eqn(length(dep_var!*),length(odd_var!*))) then
    rederr "Even and odd variables must be the same in number!";
  superfun:=for each el in all_parametric_der!* collect
    <<
      tempvarmind:=idtomind(0,el);
      tempdvar:=car tempvarmind;
      tempmind:=cadr tempvarmind;
      tempoddvar:=nth(odd_var!*,cde_position(tempdvar,dep_var!*));
      aeval list('times,list('df,fct,el),
	mind_to_eid(list(tempoddvar,tempmind))
	  )
    >>;
  if !*checkord then check_letop(superfun);
  return aeval cons('plus,superfun)
end;

symbolic procedure set_op_onearg(op,arg,val);
  % This procedure is needed because REDUCE refuses
  % to define or evaluate an operator in an iteration by a direct call.
  op(arg):=val;

symbolic procedure ell_function_odd(l_fct,name_ell_odd);
  % Given an algebraic list of scalar functions it defines the linearization as
  % an odd function with one argument of the same length as
  % the number of dependent variables and length of target equal to
  % the number of scalar functions.
  begin
    scalar n_dep_var,n_fct,sl_fct,tempexpr;
    if not(cde_alglistp(l_fct)) then
      rederr "The first argument must be a list, ie a vector function";
    sl_fct:=cdr l_fct;
    n_fct:=length(sl_fct);
    n_dep_var:=length(dep_var!*);
    mk_superfun(name_ell_odd,1,list('list,n_dep_var),length(sl_fct));
    for i:=1:n_fct do
      <<
        tempexpr:=ell_scalar_function_odd(nth(sl_fct,i));
        set_op_onearg(name_ell_odd,i,tempexpr);
      >>;
  end;

symbolic operator ell_function_odd;

symbolic procedure ell_function(l_fct,name_ell);
  % Given an algebraic list of scalar functions it defines the linearization as
  % an operator with one argument of the same length as
  % the number of dependent variables and length of target equal to
  % the number of scalar functions.
  begin
    scalar name_ell_sf;
    if not(cde_alglistp(l_fct)) then
      rederr "The first argument must be a list, ie a vector function";
    name_ell_sf:=intern compress append(explode name_ell,'_ . explode 'sf);
    ell_function_odd(l_fct,name_ell_sf);
    return conv_superfun2cdiff(name_ell_sf,name_ell)
  end;

symbolic operator ell_function;

symbolic procedure adjoint_scalar_odd(superfun,ovar);
  % Adjoint of a scalar C-differential operator
  % in terms of its superfunction.
  % Here `ovar' is one odd variable
  begin scalar tallodd,tmind,tcoeff,tindvars,arg1,arg2,tsign,
      superfunadj;
    superfunadj:=nil ./ 1;
    tallodd:=select_all_ders(1,ovar,all_parametric_odd!*);
    for each el in tallodd do
      if not eqn(tcoeff:=coeffn(superfun,el,1),0) then
      <<
        tmind:=cadr idtomind(1,el);
	tindvars:=
	  for i:=1:n_indep_var join list(nth(indep_var!*,i),nth(tmind,i));
	arg1:=cons(aeval list('times,tcoeff,ovar),tindvars);
	tsign:=aeval list('expt, - 1,length_multiindex(tmind));
	arg2:=aeval list('times,tsign,mk!*sq compute_td arg1);
	superfunadj:=addsq(simp arg2,superfunadj);
      >>;
    if !*checkord then check_letop(superfunadj);
    return prepsq superfunadj
  end;

symbolic procedure adjoint_cdiffop(cdiffop,cdadj);
  % Adjoint of a C-differential operator with ONE ARGUMENT
  % in terms of its superfunction.
  % A superfunction cdadj_odd corresponding to the adjoint operator
  % is also defined in the process.
  begin scalar len_arg,n_arg,len_target,len_adj_arg,len_adj_target,index_adj,
      tempop,tempodd,tempadj,tempadj_ij,cdadj_sf;
    check_cdiff_onearg(cdiffop);
    len_arg:=get('cdlarg,cdiffop);
    n_arg:=cadr(len_arg);
    len_target:=get('cdtarget,cdiffop);
    % Note the inversion between target and source
    len_adj_arg:=list('list,len_target);
    len_adj_target:=cadr len_arg;
    mk_cdiffop(cdadj,1,len_adj_arg,len_adj_target);
    index_adj:=cadr(len_adj_arg);
    for i:=1:index_adj do
      for j:=1:len_adj_target do
      <<
	tempodd:=nth(odd_var!*,j);
	tempop:=aeval list(cdiffop,j,i,tempodd);
	tempadj:=simp adjoint_scalar_odd(tempop,tempodd);
	if !*checkord then check_letop(tempadj);
	tempadj_ij:=split_superfun(prepsq tempadj,tempodd);
	define_cdiffop(tempadj_ij,list(cdadj,i,j));
      >>;
     cdadj_sf:=intern compress append(explode cdadj,'_ . explode 'sf);
     conv_cdiff2superfun(cdadj,cdadj_sf)
  end;

symbolic operator adjoint_cdiffop;

symbolic procedure cde_cdcalc();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;