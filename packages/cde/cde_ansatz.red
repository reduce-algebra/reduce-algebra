module cde_ansatz;
% CDE package, routines that generate ansatz of solutions of equations

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
% Procedures for construction of ansatz to solve
% determining equations. The aim is to generate monomials
% of even or odd variables with specified properties
%-----------------------------------------------------------------------------%

symbolic procedure cde_grading(dindepvar,ddepvar,doddvar);
% Initialize the grading of jetspace variables.
% The input is algebraic lists with the integer gradings of the variables
   begin;
      deg_indep_var!*:=cdr dindepvar;
      deg_dep_var!*:=cdr ddepvar;
      deg_odd_var!*:=if and(odd_var!*,length(doddvar)>1) then cdr doddvar
      else nil;
      if length(deg_indep_var!*) neq length(indep_var!*) then rederr
         "Error: mismatch in degree of independent variables";
      if length(deg_dep_var!*) neq length(dep_var!*) then rederr
         "Error: mismatch in degree of dependent variables";
      if and(odd_var!*,deg_odd_var!*) then
 	if length(deg_odd_var!*) neq length(odd_var!*) then rederr
         "Error: mismatch in degree of odd dependent variables";
   end;

symbolic operator cde_grading;

% Section 1: selects a list of variables
%    by which generates monomials up to a given algebraic degree.


symbolic procedure multmon(var,listmon);
% The following procedure takes a list of monomials `listmon'
% and collects the product of `var' with all mononials in listmon.
   for each el in listmon collect list('times,var,el);

symbolic procedure all_next_mon(fgdo,listmon);
% Makes all possible products of first (algebraic) degree variables
% with a list of monomials in the above format.
  begin scalar montemp;
    for each el in fgdo do
      montemp:=append(multmon(el,listmon),montemp);
    return cde_mkset(montemp)
  end;

symbolic procedure mkallmon0(alg_grad,vars);
% makes a list of lists of all monomials of algebraic degree = k <= alg_grad
% from a list of variables `vars'.
   begin scalar allmon_temp,allmon;
      allmon:=vars;
      allmon_temp:=vars;
      for i:=1:(alg_grad-1) do
      <<
   	 allmon_temp:=all_next_mon(vars,allmon_temp);
   	 allmon:=append(allmon_temp,allmon)
      >>;
      return reverse(allmon)
   end;

symbolic procedure mkallmon(alg_grad,vars);
  begin
    scalar templist;
    templist:=mkallmon0(alg_grad,cdr vars);
    templist:=for each el in templist collect aeval el;
    return 'list . cde_mkset(templist)
  end;

symbolic operator mkallmon;

% Section 2:  selects a list of graded variables
%    by which generates monomials up to a given scale degree.
% Note that it is more convenient to operate on an alist of graded variables.
% This means using pairs of the form {var,scale_deg}.

symbolic procedure deg_der(par,der);
% Next procedure finds the scale degree of a given even or odd
% parametric or principal derivative
% using the degree of independent variables
% and the degree of even or odd variables
% given in deg_indep_var, deg_dep_var, deg_odd_var
   begin scalar der_mind,mind,degvar,dvar;integer deg,dep_var_pos;
      deg:=0;
      der_mind:=idtomind(par,der);
      mind:=cadr der_mind;
      if par=0 then
      <<
         degvar:=deg_dep_var!*;
	 dvar:=dep_var!*
      >>
      else
      <<
	 degvar:=deg_odd_var!*;
	 dvar:=odd_var!*
      >>;
      for i:=1:n_indep_var do
	deg:=deg - nth(mind,i)*nth(deg_indep_var!*,i);
      dep_var_pos:=cde_position(car der_mind,dvar);
      return deg + nth(degvar,dep_var_pos)
   end;

symbolic procedure der2deg(par,vars);
% Given a list of parametric or principal derivatives
% next procedure computes their scale degree and arranges an alist
% of the form variable-degree
   for each el in vars collect list(el,deg_der(par,el));

symbolic procedure order_val(vars2value);
% Given an alist of variables and (integer or float) values orders it
% according with increasing (integer or float) value; it uses quicksort.
begin scalar locless,locequal,locgreater,locpivot;
  if not(vars2value) then return nil else return
  <<
    locpivot:=car vars2value;
    for each el in vars2value do
      if greaterp(cadr(el),cadr(locpivot)) then locgreater:=el . locgreater
      else if eqn(cadr(el),cadr(locpivot)) then locequal:=el . locequal
      else locless:=el . locless;
    append(
      order_val(locless),
      append(locequal,order_val(locgreater))
	)
  >>;
end;

symbolic procedure select_gradmon(gradmon,scale_deg);
% Within a given alist of graded monomials `allgradmon'
% next procedure finds all possible graded monomials of degree = scale_deg
   begin scalar scale_deg_gradmon;
      for each el in gradmon do
      	 if cadr(el)=scale_deg then
      	    scale_deg_gradmon:=car(el) . scale_deg_gradmon;
      return reverse(scale_deg_gradmon)
   end;

symbolic procedure der_deg_ordering(par,list_of_der);
  % When coordinates have STRICTLY POSITIVE DEGREE,
  % the following procedure can be used together with
  % graadlijst and mkvarlist1 in order to produce all graded monomials.
  % It splits lists of parametric derivatives in sublists according with
  % increasing degree starting from degree 1.
  begin scalar listofder_symb,list_of_der_deg,alist_of_der_deg,der_i;
    integer tempind;
    listofder_symb:=cdr list_of_der;
    alist_of_der_deg:=order_val(der2deg(par,cdr listofder_symb));
    if cadr(car(alist_of_der_deg)) <= 0 then
      rederr("Error: parametric derivatives
	do not have strictly positive degree");
    	tempind:=cadr(car(reverse(alist_of_der_deg)));
    	for i:=1:tempind do
    	<<
      	  der_i:=nil;
      	  for each el in listofder_symb do
      	    if eqn(deg_der(par,el),i) then der_i:=el . der_i;
          der_i:='list . reverse(der_i);
      	  list_of_der_deg:=der_i . list_of_der_deg
    	>>;
    	return 'list . reverse(list_of_der_deg)
  end;

symbolic operator der_deg_ordering;

symbolic procedure gradmult(firstmon,secondmon);
% The following procedure yields the graded multiplication of
% two graded monomials.
% Does not work for odd-ext variables.
  list(aeval list('times,car(firstmon),car(secondmon)),
    aeval list('plus,cadr(firstmon),cadr(secondmon)));

symbolic procedure multgradmon(gradvar,alistmon);
% The following procedure is the same as `multmon'
% in the case of alists variable-value,
% where it also takes the sum of the values.
% IMPORTANT: this will not work with odd variables,
% modify it by using super_product for the odd case.
   for each el in alistmon collect gradmult(gradvar,el);

symbolic procedure all_next_gradmon(alistvar,alistmon);
% Makes all possible products of first (algebraic) degree variables
% with an alist of graded monomials.
begin scalar gradmontemp;
  for each el in alistvar do
    gradmontemp:=append(multgradmon(el,alistmon),gradmontemp);
  return cde_mkset(gradmontemp)
end;

symbolic procedure filter_gradmon(alistmon,scale_deg);
% Takes a list graded monomials and produces a pair of lists,
% respectively of `good' monomials having the given scale degree
% and of filtered monomials having scale degree less than the given one.
   begin scalar filtered_gradmon,good_gradmon;
      filtered_gradmon:=reverse(order_val(alistmon));
      while (car(filtered_gradmon) and
      	 (car(car(filtered_gradmon))>scale_deg)) do
      	    filtered_gradmon:=cdr(filtered_gradmon);
      while (car(filtered_gradmon) and
      	 (car(car(filtered_gradmon))=scale_deg)) do
   	 <<
      	    good_gradmon:=car(filtered_gradmon) . good_gradmon;
      	    filtered_gradmon:=cdr(filtered_gradmon)
   	 >>;
      return list(good_gradmon,filtered_gradmon)
   end;

symbolic procedure mkallgradmon(par,vars,alg_deg,scale_deg);
% Makes an alist of all graded monomials
% of algebraic degree <= alg_deg
% and of scale degree = scale_deg
% from a list of variables `vars'.
% Does not work for odd-ext variables.
% Note that the function mkvarlist1 from Twente CDIFF
% does not work if at least one variable for each scale degree is present.
   begin scalar alistvars,gradmon,temp_pair,maxiter,gradmon_temp;
      alistvars:=der2deg(par,vars);
      temp_pair:=filter_gradmon(alistvars,scale_deg);
      gradmon:=car temp_pair;
      alistvars:=cadr temp_pair;
      if alistvars then
      <<
	maxiter:=min(
	  quotient(float scale_deg,float cadr(car(alistvars))),
	  alg_deg - 1
	    );
      	 gradmon_temp:=alistvars;
      	 for i:=1:maxiter do
      	 <<
   	    gradmon_temp:=
               all_next_gradmon(alistvars,gradmon_temp);
            temp_pair:=filter_gradmon(gradmon_temp,scale_deg);
   	    gradmon:=append(gradmon,car(temp_pair));
            gradmon_temp:=cadr temp_pair
      	 >>
      >>;
      return gradmon
   end;

% Section 3:  using previously formed lists of graded even monomials
%    we generate monomials which are linear in odd variables
%    and have a given scale degree

symbolic procedure mklinodd(graadmon,graadlijst_odd,degree);
  % Next function takes an algebraic list of algebraic lists
  % of even monomials `graadmon' of degrees 0,1,... and
  % a list of parametric odd coordinates `graadlijst_odd'
  % of degrees 0,1,...,
  % it multiplies all even monomials with odd coordinates of degree >=1
  % yielding all products of degree equal to `degree' (>=1).
  % It is understood that the first, zero-degree, element of graadlijst_odd
  % is always {1}.
  begin scalar linodd,linodd_temp,grlist_i,grmon_i;
    for i:=1:degree do
    <<
      if eqn(length(nth(graadlijst_odd,i+2)),1) then grlist_i:=nil
	else grlist_i:=cdr nth(graadlijst_odd,i+2);
      for each el in grlist_i do
      <<
	grmon_i:=cdr nth(graadmon,degree-i+2);
	linodd_temp:=for each ell in grmon_i collect list('times,el,ell);
	linodd:=append(linodd,linodd_temp)
      >>
      >>;
    return linodd
  end;

symbolic procedure mkalllinodd(graadmon,graadlijst_odd,degmin,degmax);
% Makes a list of graded monomials, linear in parametric odd coordinates,
% and having degree from degmin to degmax.
  cons('list,for i:=degmin:degmax join mklinodd(graadmon,graadlijst_odd,i));

symbolic operator mkalllinodd;

% Section 4: same procedures as in S.3
% also involving independent variables

symbolic procedure mkallgradmon_ind(alg_deg);
   % This procedure makes all graded monomials {el,deg}
   % where el is a monomial of algebraic degree <= alg_deg
   % of independent variables and deg is an integer.
   begin scalar allgradmon_temp,allgradmon,indep_gradmon;
     indep_gradmon:=for i:=1:n_indep_var collect
       list(nth(indep_var!*,i),nth(deg_indep_var!*,i));
     allgradmon:=list(list(1,0));
     allgradmon_temp:=allgradmon;
     for i:=1:alg_deg do
     <<
       allgradmon_temp:=all_next_gradmon(indep_gradmon,allgradmon_temp);
       allgradmon:=append(allgradmon,allgradmon_temp)
     >>;
     return allgradmon
  end;

symbolic procedure mult_grad(gradmon,lmon);
  for each el in lmon collect aeval list('times,car gradmon,el);

symbolic procedure mkallgradmon_evenind(alg_deg,grmon,degree);
  % takes graded monomials of independent variables constructed by
  % mkallgradmon_ind and multiplies them with even graded monomials
  % of complementary degree, produced by graded_mon, starting from (1 0),
  % in order to yield monomials containing independent variables
  % and having scale degree `degree'.
  begin scalar tempvars,tempdeg,grmon_dep,grmon_ind,n_grmon_dep;
    % clean the algebraic list
    grmon_dep:=cdr grmon;
    grmon_dep:=for each el in grmon_dep collect cdr el;
    n_grmon_dep:=length grmon_dep;
    % prepare the list of graded monomials of independent variables
    grmon_ind:=mkallgradmon_ind(alg_deg);
    for each el in grmon_ind do
    <<
      tempdeg:=degree - cadr el;
      if lessp(tempdeg,n_grmon_dep) then
	tempvars:=append(mult_grad(el,nth(grmon_dep,tempdeg+1)),tempvars)
      else print "Warning: algebraic degree higher than scale degree."
    >>;
    return 'list . tempvars
  end;

symbolic operator mkallgradmon_evenind;

% Section 5: procedures for solving symmetry equations

algebraic procedure splitext_list(l_eq);
  % Split a list of expressions with respect to expressions of the type
  % `ext(a,b,c,...)';
  % designed to split expressions in even-odd variables (superfunctions).
  % Returns a list of coefficients.
  begin;
    scalar ll,l_eq_split;
    l_eq_split:={};
    for each el in l_eq do
      <<
      ll:=operator_coeff(replace_oddext(el),ext);
      l_eq_split:=first(ll) . l_eq_split;
      ll:=rest ll;
      for each ell in ll do l_eq_split:=second(ell) . l_eq_split
      >>;
    return l_eq_split
   end;

algebraic procedure splitext_opequ(op_equ,init_equ,end_equ);
  % The same of splitext_list when equations are the values of an operator
  % with integer indices from init_equ to end_equ.
  begin
    scalar ll,cnt;
    cnt:=end_equ;
    for i:=init_equ:end_equ do
      <<
        ll:=operator_coeff(replace_oddext(op_equ(i)),ext);
        op_equ(cnt:=cnt+1):=first ll;
        ll:=rest ll;
        for each el in ll do op_equ(cnt:=cnt+1):=second el
      >>;
    return cnt
  end;

algebraic procedure splitvars_list(l_eq,l_vars)$
  % Split a list of expressions of the even variables l_vars.
  % Returns a list of coefficients.
  begin
    scalar ll,l_eq_split;
    l_eq_split:={};
    for each el in l_eq do
      <<
      	ll:=multi_coeff(el,l_vars);
        l_eq_split:=first(ll) . l_eq_split;
	ll:=rest(ll);
        for each ell in ll do l_eq_split:=second(ell) . l_eq_split
      >>;
    return l_eq_split
  end;

algebraic procedure splitvars_opequ(op_equ,init_equ,end_equ,l_vars);
  % The same of splitvars_list when equations are the values of an operator
  % with integer indices from init_equ to end_equ.
  begin
    scalar ll,cnt;
    cnt:=end_equ;
    for i:=init_equ:end_equ do
      <<
      ll:=multi_coeff(equ i,l_vars);
      op_equ(cnt:=cnt+1):=first ll;
      ll:=rest ll;
      for each el in ll do op_equ(cnt:=cnt+1):=second el
      >>;
    return cnt
   end;

symbolic procedure filter_eqlist0(l_eq);
  begin
    scalar eq_filtered,first_l_eq,rest_l_eq;
    eq_filtered:={};
    if null(l_eq) then return l_eq else
      if eqn(first_l_eq:=car l_eq,0) then return filter_eqlist0(cdr l_eq) else
      <<
        rest_l_eq:=cdr l_eq;
	eq_filtered:=rest_l_eq;
        for each el in rest_l_eq do
          if not eqn(el,0) and numberp(quotsq(simp el,simp first_l_eq))
            then eq_filtered:=cde_delete(el,eq_filtered)
      >>;
    return first_l_eq . filter_eqlist0(eq_filtered)
end;

symbolic procedure filter_eqlist(l_eq);
  % Filter a list of equations discarding zero or constant multiples.
    'list . filter_eqlist0(cdr l_eq);

symbolic operator filter_eqlist;

% It would be nice to write the name of the unknown in the file.
% Unfortunately it is always evaluated.
%% procedure write_results(filename,results);
%% begin;
%% off nat;
%% off echo;
%% out <<filename>>;
%% write results:=results;
%% shut <<filename>>;
%% on echo;
%% on nat;
%% return;
%% end;

endmodule;

end;
