module cde_parametric; % CDE package, routines for the computation
                     % of principal and parametric derivatives.

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

%-----------------------------------------------------------------------------%
% Computation of all parametric (and principal) derivatives (even and odd)
%-----------------------------------------------------------------------------%
symbolic procedure process_principal_der(par,l_var);
   % It is used to generate all principal derivatives.
   % It takes a list of derivative coordinates and returns a list of lists,
   % each sublist is a list of derivatives of the same dependent coordinate
   % in multiindex notation. Since it is used on initial principal derivatives
   % (lhs of given equations) there is no need to optimize it.
   begin scalar l_mind,dep_var_temp,l_temp,l_var_processed;
      l_mind:=for each el in l_var collect idtomind(par,el);
      if par=0 then dep_var_temp:=dep_var!* else dep_var_temp:=odd_var!*;
      for each el in dep_var_temp do
      <<
      	 l_temp:={};
      	 for each ell in l_mind do
            if el=car ell then l_temp:=ell . l_temp;
      	 if l_temp then
         <<
            l_temp:=reverse(l_temp);
            l_var_processed:=l_temp . l_var_processed
         >>
      >>;
      return reverse(l_var_processed)
   end;

symbolic procedure generate_principal_subtable(list_pd,total_order);
   % Given a list of principal derivatives of a single dependent variable
   % in multiindex notation, it generates all differential consequences
   % (i.e. the output of process_principal_der)
   % in the form of a pair of the given dep. var.
   % and a subtable element of all_mind_table
   begin scalar dep_var_temp,principal_mtable_temp,principal_mtable_ord,ord_el;
      dep_var_temp:=caar list_pd;
      principal_mtable_temp:=cde_mkset(
         for each el in list_pd join
            generate_prolongation_table(cadr el,total_order)
            );
      principal_mtable_ord:=for i:=0:total_order collect {};
      for each el in principal_mtable_temp do
      <<
         ord_el:=length_multiindex(car el)+1;
         principal_mtable_ord:=cde_replace_nth(principal_mtable_ord,ord_el,
            el . nth(principal_mtable_ord,ord_el))
      >>;
      return list(dep_var_temp,principal_mtable_ord)
   end;

symbolic procedure generate_all_principal_subtables(par,prin_der,total_order);
   % Makes a subtable for each dependent variable for which
   % a principal derivative is given
   begin scalar principal_der_split;
      principal_der_split:=process_principal_der(par,prin_der);
      return for each el in principal_der_split collect
         generate_principal_subtable(el,total_order)
   end;

symbolic procedure generate_all_principal_der(par,split_subtable,total_order);
   % Generates principal derivatives from subtables
   begin scalar dep_var_temp,principal_mtable_temp,principal_der_temp,
         i2m_temp,apd,apd_tot;
      if par=0 then i2m_temp:=i2m_jetspace!* else i2m_temp:=i2m_jetspace_odd!*;
      for each el in split_subtable do
      <<
         dep_var_temp:=car el;
         principal_mtable_temp:=cadr el;
         principal_der_temp:=for i:=0:total_order collect {};
         for i:=0:total_order do
            if nth(principal_mtable_temp,i+1) then
               principal_der_temp:=cde_replace_nth(principal_der_temp,i+1,
               	  (for each ell in nth(principal_mtable_temp,i+1) collect
                     car cde_lassoc2({dep_var_temp,car ell},i2m_temp))
               );
         apd:=principal_der_temp . apd
      >>;
      apd:=reverse apd;
      apd_tot:=for i:=0:total_order collect {};
      for i:=0:total_order do apd_tot:=cde_replace_nth(apd_tot,i+1,
         for each el in apd join nth(el,i+1)
         );
      return apd_tot
   end;

symbolic procedure cde_principal_parametric_derivatives(total_order);
begin scalar all_principal_der_subtables,all_principal_der_split,
      all_principal_odd_subtables,all_principal_odd_split;
   % Even variables:
   all_principal_der_subtables:=
      generate_all_principal_subtables(0,principal_der!*,total_order);
   all_principal_der_split:=
      generate_all_principal_der(0,all_principal_der_subtables,total_order);
   all_principal_der!*:=for each el in all_principal_der_split join el;
   all_principal_der:='list . all_principal_der!*;
   all_parametric_der!*:=cde_diffset(all_der_id!*,all_principal_der!*);
   all_parametric_der:='list . all_parametric_der!*;
   % Odd variables:
   all_principal_odd_subtables:=
      generate_all_principal_subtables(1,principal_odd!*,total_order);
   all_principal_odd_split:=
      generate_all_principal_der(1,all_principal_odd_subtables,total_order);
   all_principal_odd!*:=for each el in all_principal_odd_split join el;
   all_principal_odd:='list . all_principal_odd!*;
   all_parametric_odd!*:=cde_diffset(all_odd_id!*,all_principal_odd!*);
   all_parametric_odd:='list . all_parametric_odd!*;
   % Ext variables:
   n_all_parametric_ext:=length(all_parametric_odd!*);
   n_all_principal_ext:=length(all_principal_odd!*);
end;

% Beginning of procedures for replacements
% of odd coordinates with ext coordinates and back.

symbolic procedure extodd(ext_var);
% replacement of a single ext variable with exactly one odd argument
begin integer n_ext;
  if car ext_var neq 'ext then
    rederr "the argument of extodd must be an ext variable";
  n_ext:=cadr ext_var;
  if numberp n_ext then return
    if n_ext > n_all_parametric_ext then
      nth(all_principal_odd!*,(n_ext - n_all_parametric_ext))
      else nth(all_parametric_odd!*,n_ext);
  if member(n_ext,all_parametric_odd!*) or member(n_ext,all_principal_odd!*)
  then return n_ext else
    rederr "the argument of extodd must be an ext variable";
end;

symbolic procedure long_extodd(long_ext_var);
% replacement of a single ext variable with more than one odd argument
  'ext . for each el in cdr(long_ext_var) collect
    if numberp el then extodd(list('ext,el))
    else if member(el,all_parametric_odd!*) or member(el,all_principal_odd!*)
    then el else rederr "ext must contain only numbers or odd variables";

symbolic procedure replace_extodd0(listexpr);
% replacement of ext with odd variables in the expression
% (or list of expressions) listexpr
begin scalar templist,templist2,temp_repextodd;
  % Remember: get_kernels yields an algebraic list
  templist:=cdr cdiff_get_kernels(listexpr,'ext);
  for each el in templist do
    if eqn(length(el),2) then temp_repextodd:=
      list('replaceby,el,extodd(el)) . temp_repextodd
      else templist2:=el . templist2;
  temp_repextodd:='list . append(
    for each el in templist2 collect list('replaceby,el,long_extodd(el)),
      temp_repextodd);
  return algebraic sub(temp_repextodd,listexpr)
end;

symbolic procedure replace_extodd(listexpr);
  if atom listexpr then replace_extodd0(listexpr)
  else if cde_alglistp(listexpr) then
  cons('list,for each el in cdr listexpr collect replace_extodd(el))
  else replace_extodd0(listexpr);

symbolic operator replace_extodd;

symbolic procedure oddext(odd_var);
% replacement of a single odd variable with the corresponding ext expression
  if member(odd_var,all_parametric_odd!*) then
    list('ext,cde_position(odd_var,all_parametric_odd!*))
  else if member(odd_var,all_principal_odd!*) then
    list('ext,n_all_parametric_ext + cde_position(odd_var,
      all_principal_odd!*))
  else rederr "the argument of oddext must be an odd variable";

symbolic procedure long_oddext(ext_odd_var);
% replacement of an ext variable in odd notation
% by an ext variable with numeric arguments
  'ext . for each el in cdr ext_odd_var collect
    if numberp el then el else if member(el,all_parametric_odd!*) then
      cde_position2(el,all_parametric_odd!*)
    else if member(el,all_principal_odd!*) then
      n_all_parametric_ext + cde_position2(el,all_principal_odd!*)
    else rederr "ext must contain only numbers or odd variables";

symbolic procedure replace_oddext0(listexpr);
% Replace odd variables into ext variables.
begin scalar templist,templist_odd,templist2,templist3,temp_repoddext;
  % Note that this will only work for algebraic expressions
  % which are polynomial in ext variables; next command
  % takes only the numerator of a sq.
  templist:=kernels(numr simp listexpr);
  % We first replace odd variables of the type  ext(p), ext(p,p_x), ...
  % into 'pure' ext variables of the type ext(1), ext(1,2), ...
  % Warning: there is no check about mixed type ext variables ext(1,p) ...
  % such variables should not appear in any expression.
  for each el in templist do
    if and(listp el,equal(car el,'ext),not(fixp(cadr el))) then
      templist2:=el . templist2
    else if member(el,all_odd_id!*) then templist_odd:=el . templist_odd;
%  prin2t templist2;terpri();
  if templist2 then
  <<
    for each el in templist2 do
      if eqn(length(el),2) then	temp_repoddext:=
      	  list('replaceby,el,oddext(cadr el)) . temp_repoddext
      else templist3:=el . templist3;
    temp_repoddext:=append(
    for each el in templist3 collect list('replaceby,el,long_oddext(el)),
      temp_repoddext);
  >>;
  if templist_odd then
    temp_repoddext:=append(
      for each el in templist_odd collect list('replaceby,el,oddext(el)),
      temp_repoddext);
  if temp_repoddext then return algebraic sub('list . temp_repoddext,listexpr)
  else return listexpr;
end;

symbolic procedure replace_oddext(listexpr);
  if atom listexpr then replace_oddext0(listexpr)
  else if cde_alglistp(listexpr) then
  cons('list,for each el in cdr listexpr collect replace_oddext(el))
  else replace_oddext0(listexpr);

symbolic operator replace_oddext;

symbolic procedure odd_product(arg1,arg2);
  replace_extodd(super_product(replace_oddext(arg1),replace_oddext(arg2)));

symbolic operator odd_product;

endmodule;

end;