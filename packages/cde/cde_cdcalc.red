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

% $Id$
% % *****************************************************************
% Author and maintainer: Raffaele Vitolo
% Dipartimento di Matematica, Universita' del Salento (Lecce, Italy)
% email: raffaele.vitolo@unisalento.it
% web: http://poincare.unisalento.it/vitolo
% ===============================================================
%
% Procedures for operations on C-Differential operators:
% sum, multiplication by scalars, composition, linearization and its adjoint
% many operations are still in development

% Procedures for the standard vector space operations between operators

symbolic procedure sum_cdiffop(cd1,cd2,cd3);
  % Sums the values of cd1 and cd2 into cd3
  begin
    scalar parity1,largcd1,target1;
    check_cdiff_sametype(cd1,cd2);
    parity1:=get('cdnarg,cd1);
    largcd1:=get('cdlarg,cd1);
    target1:=get('cdtarget,cd1);
    mk_cdiffop(cd3,parity1,largcd1,target1);
    % Sistemare questa parte di codice con la definizione di somma
  % cde_ev_forall cde_forall_form(opname,lpars,lfvars,rhs_opdef);
  % Given a list of indices lpars:=(j,i1,i2,...)
  % and a list of free variables lfvars:=(phi1,phi2,...)
  % and an operator name opname
  % create a list u such that the evaluation of forall u
  % will be the same as the evaluation of the algebraic statement
  % for all phi1,phi2,... let opname(phi1,phi2,...)=rhs_opdef;
  end;

symbolic operator sum_cdiffop;

symbolic procedure scalarmult_cdiffop(cfm,cd1,cd2);
  % Multiply the values of cd1 by the symbolic expression cfm
  begin
    scalar parity1,largcd1,target1;
    parity1:=get('cdnarg,cd1);
    largcd1:=get('cdlarg,cd1);
    target1:=get('cdtarget,cd1);
    mk_cdiffop(cd2,parity1,largcd1,target1);
    return cfm
    % Sistemare questa parte di codice con la definizione di prodotto
  % cde_ev_forall cde_forall_form(opname,lpars,lfvars,rhs_opdef);
  % Given a list of indices lpars:=(j,i1,i2,...)
  % and a list of free variables lfvars:=(phi1,phi2,...)
  % and an operator name opname
  % create a list u such that the evaluation of forall u
  % will be the same as the evaluation of the algebraic statement
  % for all phi1,phi2,... let opname(phi1,phi2,...)=rhs_opdef;
  end;

% Procedures for the composition of C-Differential operators

% Procedures for linearization of a vector function

symbolic procedure ell_scalar_function_odd(fct);
% Linearization of a scalar function in terms of superfunction of the
% corresponding operator. Note that odd variables must be same in number as
% even variables, as the linearization is an operator of the type
% \ell_F : \kappa \to P
begin
  scalar superfun,tempvarmind,tempdvar,tempmind,tempoddvar;
  if not(cde_freeofl(fct,all_parametric_odd!*)) then
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
    mk_superfun(name_ell_odd,1
    %      ,list('list,n_dep_var)
    ,length(sl_fct));
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

% Procedures for the adjoint of a differential operator in one argument

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
  % A superfunction cdadj_sf corresponding to the adjoint operator
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

% Procedures for supercalculus: linearization of supermaps and
% adjoints of super-C-differential operators.

symbolic procedure index_par(ind);
  % Calculate the parity of an index
  begin
    scalar l_dv,retval;
    l_dv:=length(dep_var!*);
    if ind <= l_dv then retval:=0 else retval:=1;
    return retval
  end;

symbolic procedure ell_supermap(sm_name,scdop);
  % We calculate the linearization of a super vector function and
  % define it to be a new super-CDiff operator `scdop'
  % i is the row (upper) index, j is the column (lower) index
  begin
    scalar par_sm,l_even,l_odd,l_dv,l_ov,l_tot_i,l_tot_j,tempsign;
    if not(supermapp(sm_name)) then rederr
      "Error: the argument must be a declared supermap";
    par_sm:=get('smpar,sm_name);
    l_even:=get('smapecomp,sm_name);
    l_odd:=get('smapocomp,sm_name);
    l_dv:=length(dep_var!*);
    l_ov:=length(odd_var!*);
    l_tot_i:=aeval list('plus,l_even,l_odd);
    l_tot_j:=aeval list('plus,l_dv,l_ov);
    mk_scdiffop(scdop,par_sm,1,
      list('list,list('list,l_dv,l_ov)),
      list('list,l_even,l_odd));
    for i:=1:l_tot_i do for j:=1:l_tot_j do
    <<
      tempsign:=aeval list('expt, - 1,
	list('times,list('plus,par_sm,index_par(i),1),index_par(j))
	  );
%      print i;
%      print j;
%      print tempsign;
      define_component_ell_supermap(sm_name,i,j,tempsign,scdop)
    >>;
  end;

symbolic procedure define_component_ell_supermap(sm_name,i,j,tempsign,scdop);
  begin
    scalar tempvar,temppar,templvar,tempmind,tempdername,tempcf,l_coeff;
    temppar:=index_par(j);
    if eqn(temppar,0) then
    <<
      tempvar:=nth(dep_var!*,j);
      templvar:=select_all_ders(temppar,tempvar,all_parametric_der!*);
      tempdername:='df
    >>
    else
    <<
      tempvar:=nth(odd_var!*,j - length(dep_var!*));
      templvar:=select_all_ders(temppar,tempvar,all_parametric_odd!*);
      tempdername:='df_odd
    >>;
    l_coeff:=list();
    for each el in templvar do
    <<
      tempmind:=cadr idtomind(temppar,el);
      tempcf:=aeval list('times,
	tempsign,
	list(tempdername,aeval list(sm_name,i),el)
	  );
      l_coeff:=list('list,tempcf,cons('list,tempmind)) . l_coeff;
    >>;
    load_cdiffop0(scdop,list(i,j),l_coeff)
  end;

symbolic operator ell_supermap;

symbolic procedure load_adj_cdiffop0(opname,par,inds,l_coeff);
  % Defines an entry of the adjoint of a sCDiff-op
  % (probably also good for a CDiffop)
  % inds is a list with two indices (i,j)
  % l_coeff is a list of algebraic lists {cf,mind}
  % where cf is a coefficient and mind is a multiindex
  % It only works for operators with one argument.
  begin
    scalar phi,sign_comp,tempexp,tempcf,templmind,tempsign,change_expand_td;
    phi:=gensym();
    change_expand_td:=0;
    if eq(get('td,'simpfn),'compute_td) then
    <<
      change_expand_td:=1;
      noexpand_td()
    >>;
    % Evaluate odd_product to itself
    put('oddprod!*,'simpfn,'simpiden);
    % Remember: el={{arg1,mind1},{arg2,mind2},...} is an algebraic list below.
    sign_comp:=aeval list('expt,-1,
      aeval list('times,
      aeval list('plus,par,index_par(car inds)),
      aeval list('plus,index_par(car inds),index_par(cadr inds))
	)
	  );
    tempexp:=list();
    for each el in l_coeff do
    <<
      tempcf:=cadr el;
      templmind:=caddr el;
      tempsign:=aeval list('expt, - 1,length_multiindex(cdr templmind));
      tempexp:=
        cons(
            aeval list('times,tempsign,
	    aeval list('td_mind,aeval list('oddprod!*,tempcf,phi),templmind)
	    ),
	  tempexp);
    >>;
    tempexp:=aeval list('times,sign_comp,aeval cons('plus,tempexp));
    %    if not(eq(aeval mk!*sq exprop,0)) then
    cde_ev_forall cde_forall_form(
	opname,inds,list(phi),tempexp
	  );
    put('oddprod!*,'simpfn,'ev_odd_product);
    return if eqn(change_expand_td,1) then expand_td()
  end;

symbolic procedure adjoint_scdiffop(scdop,adj_scdop);
  begin
    scalar l_arg,l_tar,par,l_coeff,l_arg_adj,l_tar_adj,tot_i,tot_j,inds;
    check_scdiff_onearg(scdop);
    l_arg:=get('scdlarg,scdop);
    l_tar:=get('scdtarget,scdop);
    l_arg_adj:=list('list,l_tar);
    l_tar_adj:=cadr l_arg;
    par:=get('scdpar,scdop);
    mk_scdiffop(adj_scdop,par,1,l_arg_adj,l_tar_adj);
    % clean algebraic lists
    l_arg_adj:=cdr cadr l_arg_adj;
    l_tar_adj:=cdr l_tar_adj;
    tot_i:=aeval list('plus,car l_arg_adj,cadr l_arg_adj);
    tot_j:=aeval list('plus,car l_tar_adj,cadr l_tar_adj);
    l_coeff:=cdr all_coeff_scdiffop(scdop);
    % Remember: l_coeff={{inds1,{cf11,mind11},{cf12,mind12},...},
    % {inds2,{cf21,mind21},{cf22,mind22},...}
    % all-algebraic lists!
    for each el in l_coeff do
    <<
      inds:=reverse cdr cadr el;
%      print "el:=";
%      print el;
%      print "inds:=";
%      print inds;
      load_adj_cdiffop0(adj_scdop,par,inds,cddr el);
    >>;
  end;

symbolic operator adjoint_scdiffop;

symbolic procedure cde_cdcalc();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;