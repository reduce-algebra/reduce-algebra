module cde_weaklynl;
% CDE package, Schouten bracket
% of weakly nonlocal skew-adjoint
% C-differential operators
% in one independent variable.

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

%
%-----------------------------------------------------------------------------%
% Schouten bracket of weakly nonlocal Hamiltonian operators.
%-----------------------------------------------------------------------------%
%

symbolic procedure mk_wnlop(c,w,n_tail);
  % This procedures defines the elements of the nonlocal part
  % of a weakly nonlocal C-differential operator
  % and associates with both c and w the number of the tail summands.
  % Syntax:
  % c: coefficient matrix (operator)
  % w: tail vectors
  % n_tail: number of tail vectors
  % NOTE: to get the number of tail vectors do
  % get('wnl_ntail,c); or
  % get('wnl_ntail,w);
begin
  mkop c;
  mkop w;
  put('wnl_coeff,c,t);
  put('wnl_narg,c,n_tail);
  put('wnl_tail,w,t);
  put('wnl_narg,w,n_tail);
  if not fixp n_tail then
    rederr "Error: number of tail vectors must be an integer";
end;

symbolic operator mk_wnlop;

symbolic procedure wnl_coeffp(c);
  get('wnl_coeff,c);

symbolic procedure wnl_tailp(w);
  get('wnl_tail,w);

symbolic procedure cdwnl2vec(cdl_op,c,w,loc_arg,nloc_arg);
  % Creating a part of the Dubrovin-Zhang formula:
  % one CDiff-operator applied to one argument, yielding a vector (list).
  begin
    scalar largcd,ntarget,ntail,temploc,tempnloc;
    largcd:=cadr get('cdlarg,cdl_op);
    ntarget:=get('cdtarget,cdl_op);
    ntail:=get('wnl_narg,c);
    ntail:=get('wnl_narg,w);
    if not(eqn(largcd,ntarget)) then rederr
      "Non-conformant length of argument and dimension of target";
    return for i:=1:largcd collect
      <<
        temploc:=for j:=1:ntarget collect
          aeval list(cdl_op,i,j,nth(loc_arg,j));
	tempnloc:=for a:=1:ntail join for b:=1:ntail collect
	  aeval list('times,
	    list('c,a,b),list('w,i,a),nth(nloc_arg,b)
	      );
	aeval cons('plus,append(temploc,tempnloc))
      >>
  end;

symbolic procedure l_summand(cdop_loc_cf,loc_arg_1,vec_op2_2,loc_arg_3,
    all_parder);
  % First summand of the Dubrovin-Zhang formula:
  % linearization of the local part of one operator
  begin
    scalar op_i,op_j,templterms,lin_coeff,var_m,var_id,m_ind;
    return for each op_entry in cdr(cdop_loc_cf) join
    <<
        op_i:=cadr cadr op_entry;
        op_j:=caddr cadr op_entry;
	templterms:=cddr op_entry;
	for each op_term in templterms join
	  for each var in all_parder collect
	  <<
            % Linearization of coeff
	    lin_coeff:=aeval list('df,cadr op_term,var);
	    if not(eqn(lin_coeff,0)) then
	    <<
	      var_m:=idtomind(0,var);
              var_id:=car var_m;
              m_ind:='list . cadr var_m;
	      aeval list('times,
	        lin_coeff,
	        % \partial_\sigma \psi^1_j
	        aeval list('td_mind,nth(loc_arg_1,op_j),caddr op_term),
	        % \partial_\tau Q^k(\psi^2)
	        aeval list('td_mind,
		  nth(vec_op2_2,cde_position(var_id,dep_var!*)),m_ind),
	        % \psi^3_i
	        nth(loc_arg_3,op_i)
		  )
	    >>
	  >>
      >>
  end;

symbolic procedure nl_summand_1(c,w,vec_op2_2,nloc_arg_1,loc_arg_3,all_parder);
  % Second summand of the Dubrovin-Zhang formula:
  % linearization of the coefficient of the nonlocal part of one operator
  begin
    scalar ntail,lin_coeff,var_m,var_id,m_ind;
    ntail:=get('wnl_narg,c);
    return for alpha:=1:ntail join for beta:=1:ntail join
      for i:=1:length(loc_arg_3) join
      for each var in all_parder collect
      <<
        % Linearization of coeff
	lin_coeff:=aeval list('df,aeval list(w,i,alpha),var);
	if not(eqn(lin_coeff,0)) then
	<<
	  var_m:=idtomind(0,var);
          var_id:=car var_m;
          m_ind:='list . cadr var_m;
	  aeval list('times,
            % tail coefficient
	    aeval list(c,alpha,beta),
	    % linearization of the tail coefficient
	    lin_coeff,
	    % \partial_\tau Q^k(\psi^2)
	    aeval list('td_mind,
	      nth(vec_op2_2,cde_position(var_id,dep_var!*)),m_ind),
	    % \tilde{\psi}^1_\beta
	    nth(nloc_arg_1,beta),
	    % \psi^3_i
	    nth(loc_arg_3,i)
	  )
	>>
      >>
  end;

symbolic procedure nl_summand_2(c,w,nloc_arg_3,vec_op2_2,loc_arg_1,all_parder);
  % Third summand of the Dubrovin-Zhang formula:
  % linearization of the integrand of the nonlocal part of one operator
  begin
    scalar ntail,lin_coeff,var_m,var_id,m_ind;
    ntail:=get('wnl_narg,c);
    return for alpha:=1:ntail join for beta:=1:ntail join
      for j:=1:length(loc_arg_1) join
      for each var in all_parder collect
      <<
        % Linearization of coeff
	lin_coeff:=aeval list('df,aeval list(w,j,beta),var);
	if not(eqn(lin_coeff,0)) then
	<<
	  var_m:=idtomind(0,var);
          var_id:=car var_m;
          m_ind:='list . cadr var_m;
	  aeval list('times,
	    % sign
	    - 1,
            % tail coefficient
	    aeval list(c,alpha,beta),
	    % \tilde{\psi}^3_\alpha
	    nth(nloc_arg_3,alpha),
	    % linearization of the tail coefficient
	    lin_coeff,
	    % \partial_\tau Q^k(\psi^2)
	    aeval list('td_mind,
	      nth(vec_op2_2,cde_position(var_id,dep_var!*)),m_ind),
	    % \psi^1_j
	    nth(loc_arg_1,j)
	  )
	>>
      >>
  end;

symbolic procedure dubrovin_zhang_expr(ham1_l,c,w,ham2_l,d,z,
  dep_var_equ,
  loc_arg_1,loc_arg_2,loc_arg_3,
  nlargw_1,nlargw_2,nlargw_3,
  nlargz_1,nlargz_2,nlargz_3);
  begin
    scalar vec_op1_1,vec_op1_2,vec_op1_3,vec_op2_1,vec_op2_2,vec_op2_3,
      ham1_l_coeff,ham2_l_coeff,
      all_parder,
      l_h1_h2_123,l_h1_h2_312,l_h1_h2_231,
      l_h2_h1_123,l_h2_h1_312,l_h2_h1_231;
    % Transforming operators into vector-valued expressions
    vec_op1_1:=cdwnl2vec(ham1_l,c,w,loc_arg_1,nlargw_1);
    vec_op1_2:=cdwnl2vec(ham1_l,c,w,loc_arg_2,nlargw_2);
    vec_op1_3:=cdwnl2vec(ham1_l,c,w,loc_arg_3,nlargw_3);
    vec_op2_1:=cdwnl2vec(ham2_l,d,z,loc_arg_1,nlargz_1);
    vec_op2_2:=cdwnl2vec(ham2_l,d,z,loc_arg_2,nlargz_2);
    vec_op2_3:=cdwnl2vec(ham2_l,d,z,loc_arg_3,nlargz_3);
    % Taking coefficients of the local operators in view of the linearization
    ham1_l_coeff:=all_coeff_cdiffop0(ham1_l);
    ham2_l_coeff:=all_coeff_cdiffop0(ham2_l);
    % Collecting a set of variables for the linearization
    all_parder:=for each var in dep_var_equ join
      reverse select_all_ders(0,var,all_parametric_der!*);
    % Linearization of the first operator applied to the second one.
    l_h1_h2_123:=
      append(
	l_summand(ham1_l_coeff,loc_arg_1,vec_op2_2,loc_arg_3,all_parder),
	append(nl_summand_1(c,w,vec_op2_2,nlargw_1,loc_arg_3,all_parder),
	  nl_summand_2(c,w,nlargw_3,vec_op2_2,loc_arg_1,all_parder))
	    );
%%  return aeval cons('plus,l_h1_h2_123)
    l_h1_h2_312:=
      append(
	l_summand(ham1_l_coeff,loc_arg_3,vec_op2_1,loc_arg_2,all_parder),
	append(nl_summand_1(c,w,vec_op2_1,nlargw_3,loc_arg_2,all_parder),
	  nl_summand_2(c,w,nlargw_2,vec_op2_1,loc_arg_3,all_parder))
	    );
    l_h1_h2_231:=
      append(
	l_summand(ham1_l_coeff,loc_arg_2,vec_op2_3,loc_arg_1,all_parder),
	append(nl_summand_1(c,w,vec_op2_3,nlargw_2,loc_arg_1,all_parder),
	  nl_summand_2(c,w,nlargw_1,vec_op2_3,loc_arg_2,all_parder))
	    );
    % Linearization of the second operator applied to the first one.
    l_h2_h1_123:=
      append(
	l_summand(ham2_l_coeff,loc_arg_1,vec_op1_2,loc_arg_3,all_parder),
	append(nl_summand_1(d,z,vec_op1_2,nlargz_1,loc_arg_3,all_parder),
	  nl_summand_2(d,z,nlargz_3,vec_op1_2,loc_arg_1,all_parder))
	    );
    l_h2_h1_312:=
      append(
	l_summand(ham2_l_coeff,loc_arg_3,vec_op1_1,loc_arg_2,all_parder),
	append(nl_summand_1(d,z,vec_op1_1,nlargz_3,loc_arg_2,all_parder),
	  nl_summand_2(d,z,nlargz_2,vec_op1_1,loc_arg_3,all_parder))
	    );
    l_h2_h1_231:=
      append(
	l_summand(ham2_l_coeff,loc_arg_2,vec_op1_3,loc_arg_1,all_parder),
	append(nl_summand_1(d,z,vec_op1_3,nlargz_2,loc_arg_1,all_parder),
	  nl_summand_2(d,z,nlargz_1,vec_op1_3,loc_arg_2,all_parder))
	    );
    return aeval cons('plus,
       append(l_h1_h2_123,append(l_h1_h2_312,append(l_h1_h2_231,
 	append(l_h2_h1_123,append(l_h2_h1_312,l_h2_h1_231)))))
 	  )
  end;

symbolic procedure integrate_by_parts(bad_term,el);
  % Here I integrate by parts one term in the expression of the Schouten br.
  begin
    scalar var_m,var_id,mind_val,m_ind;
    var_m:=idtomind(0,el);
    var_id:=car var_m;
    mind_val:=caadr var_m;
    m_ind:='list . list(mind_val);
    return aeval list('times,
      var_id,
      list('expt,-1,mind_val),
      list('td_mind,bad_term,m_ind)
	);
  end;

symbolic procedure nonlocal_reduction(sb_expr,
  nloc_arg_1,loc_arg_2,loc_arg_3);
  begin
    scalar der_arg_3,tempdvar,tempterm_1,tempterm_2,reduced_expr;
    reduced_expr:=nil;
    der_arg_3:=nil;
    for each var in loc_arg_3 do
      for each el in all_parametric_der!* do
      <<
        tempdvar:=idtomind(0,el);
        if
	  eq(car tempdvar,var) and lessp(0,caadr tempdvar)
 	then
	  der_arg_3:=el . der_arg_3
      >>;
    der_arg_3:=reverse der_arg_3;
    for each nla_1 in nloc_arg_1 do
      for each la_2 in loc_arg_2 do
	for each dla_3 in der_arg_3 do
          if not(
	    eqn(tempterm_1:=
	      coeffn(coeffn(coeffn(sb_expr,dla_3,1),la_2,1),nla_1,1),0)
		)
	  then
	  <<
	    tempterm_2:=integrate_by_parts(
	      aeval list('times,tempterm_1,nla_1,la_2)
		,dla_3);
	    reduced_expr:=aeval list('plus,
	      list('times,-1,tempterm_1,nla_1,la_2,dla_3),
	      tempterm_2,reduced_expr)
	  >>;
    return aeval list('plus,reduced_expr,sb_expr)
  end;

symbolic procedure local_reduction(sb_expr,
    loc_arg_1,loc_arg_2,loc_arg_3);
    begin
      scalar der_arg_3,der_loc_arg_1,der_loc_arg_2,
	tempdvar,tempterm_1,tempterm_2,reduced_expr;
      reduced_expr:=nil;
      der_arg_3:=nil;
      for each var in loc_arg_3 do
        for each el in all_parametric_der!* do
        <<
          tempdvar:=idtomind(0,el);
          if
	    eq(car tempdvar,var) and lessp(0,caadr tempdvar)
 	  then
 	    der_arg_3:=el . der_arg_3
        >>;
      der_arg_3:=reverse der_arg_3;
      der_loc_arg_1:=for each el in loc_arg_1 join
 	select_all_ders(0,el,all_parametric_der!*);
      der_loc_arg_2:=for each el in loc_arg_2 join
 	select_all_ders(0,el,all_parametric_der!*);
      for each dla_1 in der_loc_arg_1 do
        for each dla_2 in der_loc_arg_2 do
  	  for each dla_3 in der_arg_3 do
            if not(
              eqn(tempterm_1:=
	        coeffn(coeffn(coeffn(sb_expr,dla_3,1),dla_2,1),dla_1,1),0)
		  )
	    then
	    <<
	      tempterm_2:=integrate_by_parts(
		aeval list('times,tempterm_1,dla_1,dla_2),
		dla_3);
	      reduced_expr:=aeval list('plus,
		list('times,-1,tempterm_1,dla_1,dla_2,dla_3),
		tempterm_2,reduced_expr)
	    >>;
    return aeval list('plus,reduced_expr,sb_expr)
    end;

symbolic procedure generate_nlarg(w,nloc_arg,i);
  % Lists of nonlocal-w variables with respect to the argument psi^i
  begin
    scalar ntail_w,nlarg_i;
    ntail_w:=get('wnl_narg,w);
    for alp:=1:ntail_w do
      for each el in nloc_arg do
        if equal(nth(el,3),w) and eqn(nth(el,4),alp) then
          nlarg_i:=cons(cde_list2id(list(nth(el,2),'!_,alp,i)),nlarg_i);
    return reverse(nlarg_i)
  end;

symbolic procedure sb_wnl_algorithm(ham1_l,c,w,ham2_l,d,z,
    dep_var_equ,loc_arg,nloc_arg);
  % Unfolding the variables and passing them to the procedure
  % that calculates the expression of the bracket.
  % See Casati, Lorenzoni, Vitolo, Studies in Appl. Math. (2020)
  % for details on the algorithm.
    begin
      scalar loc_arg_1,loc_arg_2,loc_arg_3,
      nlargw_1,nlargw_2,nlargw_3,
      nlargz_1,nlargz_2,nlargz_3,
      	dz,first_step;
      % Defining the three lists of the three local arguments of [P,Q]
      loc_arg_1:=for each el in loc_arg collect mkid(el,1);
      loc_arg_2:=for each el in loc_arg collect mkid(el,2);
      loc_arg_3:=for each el in loc_arg collect mkid(el,3);
      % Generating the three lists of the three nonlocal-w arguments of [P,Q]
      nlargw_1:=generate_nlarg(w,nloc_arg,1);
      nlargw_2:=generate_nlarg(w,nloc_arg,2);
      nlargw_3:=generate_nlarg(w,nloc_arg,3);
      nlargz_1:=generate_nlarg(z,nloc_arg,1);
      nlargz_2:=generate_nlarg(z,nloc_arg,2);
      nlargz_3:=generate_nlarg(z,nloc_arg,3);
      % Computing Dubrovin-Zhang formula
      dz:=dubrovin_zhang_expr(ham1_l,c,w,ham2_l,d,z,
      	dep_var_equ,
      	loc_arg_1,loc_arg_2,loc_arg_3,
      	nlargw_1,nlargw_2,nlargw_3,
	nlargz_1,nlargz_2,nlargz_3);
%%      return dz;
      % First step of the algorithm: nonlocal reduction
      % Integrating Coeff * tpsi^1_w,\a * psi^2_p * d^k_x psi^3_i, k>0
      first_step:=nonlocal_reduction(dz,
      	nlargw_1,loc_arg_2,loc_arg_3);
%%      return list('list,dz,first_step);
      % Integrating Coeff * tpsi^1_z,\a * psi^2_p * d^k_x psi^3_i, k>0
      first_step:=nonlocal_reduction(first_step,
      	nlargz_1,loc_arg_2,loc_arg_3);
      % Integrating Coeff * tpsi^2_w,\a * psi^3_p * d^k_x psi^1_i, k>0
      first_step:=nonlocal_reduction(first_step,
      	nlargw_2,loc_arg_3,loc_arg_1);
      % Integrating Coeff * tpsi^2_z,\a * psi^3_p * d^k_x psi^1_i, k>0
      first_step:=nonlocal_reduction(first_step,
      	nlargz_2,loc_arg_3,loc_arg_1);
      % Integrating Coeff * tpsi^3_w,\a * psi^1_p * d^k_x psi^2_i, k>0
      first_step:=nonlocal_reduction(first_step,
      	nlargw_3,loc_arg_1,loc_arg_2);
      % Integrating Coeff * tpsi^3_z,\a * psi^1_p * d^k_x psi^2_i, k>0
      first_step:=nonlocal_reduction(first_step,
      	nlargz_3,loc_arg_1,loc_arg_2);
      % Second step of the algorithm: local reduction
      % Integrating Coeff * d^k_x psi^3_i, k>0
      return local_reduction(first_step,
      	loc_arg_1,loc_arg_2,loc_arg_3)
    end;

symbolic procedure schouten_bracket_wnl(ham1,ham2,
    dep_var_equ,loc_arg,nloc_arg);
  % Consistency checks on the input, then calling the algorithm
  % Syntax:
  % ham1:={ham1_l,c,w};
  % ham1_l: the local operator
  % c: coefficient matrix, syntax: c^{alpha,beta} = c(alpha,beta)
  % w: tail vectors, syntax: w^i_\alpha = w(i,alpha)
  % same for ham2
  % dep_var_equ,loc_arg,nloc_arg: algebraic lists of variables and arguments
  begin
    scalar ham1_l,c,w,ham2_l,d,z,ntail_w,ntail_z;
    ham1_l:=nth(ham1,2);
    c:=nth(ham1,3);
    w:=nth(ham1,4);
    ham2_l:=nth(ham2,2);
    d:=nth(ham2,3);
    z:=nth(ham2,4);
    check_cdiff_onearg(ham1_l);
    check_cdiff_onearg(ham2_l);
    check_cdiff_sametype(ham1_l,ham2_l);
    if not eqn(get('cdlarg,ham1_l),get('cdlarg,ham2_l)) then
      rederr "Error: non-conformant C-Differential operators";
    dep_var_equ:=cdr dep_var_equ;
    loc_arg:=cdr loc_arg;
    nloc_arg:=cdr nloc_arg;
    if not wnl_coeffp(c) then
      rederr "Error: not a valid tail coefficient matrix";
    if not wnl_tailp(w) then
      rederr "Error: not a valid tail vector";
    if not wnl_coeffp(d) then
      rederr "Error: not a valid tail coefficient matrix";
    if not wnl_tailp(z) then
      rederr "Error: not a valid tail vector";
    if not eqn(length(loc_arg),length(dep_var_equ)) then
      rederr "Error: invalid list of arguments";
    ntail_w:=get('wnl_narg,w);
    if not eqn(get('wnl_narg,c),ntail_w) then
      rederr "Error: non-conformant tail vector and coefficients";
    ntail_z:=get('wnl_narg,z);
    if not eqn(get('wnl_narg,d),ntail_z) then
      rederr "Error: non-conformant tail vector and coefficients";
    % Generating all local and nonlocal arguments for both operators
    % All lists below are lisp.
    return sb_wnl_algorithm(ham1_l,c,w,ham2_l,d,z,
      dep_var_equ,loc_arg,nloc_arg);
  end;

symbolic operator schouten_bracket_wnl;

symbolic procedure cde_weaklynl(indep_var,dep_var_equ,loc_arg,nloc_arg,
    total_order);
  % Compute local and nonlocal arguments for the expression of [P,Q].
  % Call CDE in order to generate the corresponding jetspace.
  % Return the list of all dependent local and nonlocal variables.
  begin
    scalar n_dv,loc_arg!*,loc_arg_3,nloc_arg_3,
      tail_vec,alp,nlvar_temp,pder_temp,de_temp,
      dep_var_tot,dep_var_jetspace,principal_der,de;
    loc_arg!*:=cdr(loc_arg);
    n_dv:=length(cdr(dep_var_equ));
    nloc_arg_3:=nil;
    principal_der:=nil;
    de:=nil;
    if not(eqn(n_dv,length(loc_arg!*))) then
      rederr "Error: length of dependent variables and arguments mismatch";
    % Repeating the local argument variable three times: psi^1,psi^2,psi^3
    loc_arg_3:=for i:=1:3 join
      for each el in loc_arg!* collect mkid(el,i);
    % Preparing the list of nonlocal variables for the CDE call
    for i:=1:3 do for each el in cdr(nloc_arg) do
    <<
      tail_vec:=nth(el,3);
      alp:=nth(el,4);
      nlvar_temp:=cde_list2id(list(nth(el,2),'!_,alp,i));
      pder_temp:=mkid(nlvar_temp,'!_x);
      de_temp:=for j:=1:n_dv collect
	list('times,list(tail_vec,j,alp),mkid(nth(loc_arg!*,j),i));
      nloc_arg_3:=cons(nlvar_temp,nloc_arg_3);
      principal_der:=cons(pder_temp,principal_der);
      de:=cons(aeval cons('plus,de_temp),de)
    >>;
    nloc_arg_3:=reverse(nloc_arg_3);
    principal_der:='list . reverse(principal_der);
    de:='list . reverse(de);
    % Preparing the lists as arguments for the CDE call
    dep_var_jetspace:=append(dep_var_equ,append(loc_arg_3,nloc_arg_3));
    cde(list('list,indep_var,dep_var_jetspace,list('list),total_order),
      list('list,principal_der,de,list('list),list('list)));
    % Output: an algebraic list of four algebraic lists
    % of local and nonlocal variables.
    dep_var_tot:=
      list('list,dep_var_equ,
	cons('list,loc_arg_3),
	cons('list,nloc_arg_3));
    return dep_var_tot
  end;

symbolic operator cde_weaklynl;

endmodule;

end;

