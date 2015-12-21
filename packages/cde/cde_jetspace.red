module cde_jetspace; % CDIFF package, routines for the definition of jetspace

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
% Jetspace coordinates
%-----------------------------------------------------------------------------%

% Here we introduce all jet coordinates up to the order specified
% in the parameter total_order.

% Coordinates are introduced in two formats,
% which have the same name with termination `_mind' or `_id'
% depending on if coordinates are of the form
% {u,{1,2,0}} (multiindex notation)
% or u_x1y2z0 (identifier notation).
% The two formats are necessary for all computations which depend
% on the numeric value of the multiindex.

% We also define odd coordinates, to be used on tangent or cotangent coverings.
% Odd coordinates have the identifier notation and the ext notation,
% to be used in internal computations.

% We also define a number of useful procedures to be used throughout
% the program.

symbolic procedure jet_fiber_dim(jorder);
% Compute the number of derivatives of order exactly equal to 'jorder'
% for a jet space with n_ivar indep. vars and n_dvar dep. vars
begin scalar n_ivar,n_dvar;
   n_dvar:=length(dep_var!*);
   n_ivar:=length(indep_var!*);
   if eqn(jorder,0) then return n_dvar else return
     n_dvar*(factorial(n_ivar+jorder-1))/
     (factorial(jorder)*factorial(n_ivar-1))
end;

symbolic operator jet_fiber_dim;

symbolic procedure jet_dim(jorder);
% Compute the sum of the number of independent variables plus the number
% of all derivative coordinates from the order 0 up to order 'jorder'
% for a jet space with n_ivar indep. vars and n_dvar dep. vars
begin scalar n_ivar,n_dvar;
   n_dvar:=length(dep_var!*);
   n_ivar:=length(indep_var!*);
   if eqn(jorder,0) then return n_ivar + n_dvar else return
     n_ivar +
     n_dvar*(factorial(n_ivar+jorder))/(factorial(n_ivar)*factorial(jorder));
end;

symbolic operator jet_dim;

symbolic procedure length_multiindex lm;
   % Finds the length of a multiindex
   for each el in lm sum el;

symbolic procedure factorial_multiindex lm;
   % Finds the factorial of a multiindex
   for each el in lm product factorial(el);

symbolic procedure generate_multiindex m;
   % for a given multiindex m generates all multiindexes
   % strictly containing m with length = length m + 1
   % new multiindex appear in the following order:
   % each index is incremented starting from left to right
   % with respect to the order of independent variables.
   for i:=1:n_indep_var collect cde_replace_nth(m,i,nth(m,i)+1);

symbolic procedure generate_prolongation_table(m,total_order);
   % for a given multiindex m generates a table of the form
   % {mind,list_of_first_prol}
   % where |m| <= total_order
   begin scalar temp_m_list,temp_table_rows,all_table_rows;
      temp_m_list:=copy list(m);
      while length_multiindex(car temp_m_list)<total_order do
      <<
	 temp_table_rows:=for each el in temp_m_list collect
	    list(el,generate_multiindex(el));
	 temp_m_list:=cde_mkset(
          for each ell in temp_table_rows join cadr ell
         );
         all_table_rows:=append(all_table_rows,temp_table_rows);
      >>;
      temp_m_list:=for each elll in temp_m_list collect list(elll,nil);
      return append(all_table_rows,temp_m_list)
   end;

symbolic procedure join_dvar_mind(dvar,tm);
   % From a list of dependent variables and a table of multiindexes
   % produces a list with all derivative coordinates in multiindex notation
   % the list is ordered according with the length of multiindexes and dvar
   for each el in tm join
      for each ell in dvar collect list(ell,car el);

symbolic procedure mind_to_eid der;
   % converts a derivative coordinate from the multiindex notation
   % to the external identifier notation - ex.: u_t2x
   begin scalar mip,tempind;
      mip:=for i:=1:n_indep_var join
      <<
         tempind:=nth(cadr der,i);
         if tempind=0 then nil
            else if tempind=1 then list(nth(indep_var!*,i))
            else list(tempind,nth(indep_var!*,i))
      >>;
      return
         if not(mip) then car der else cde_list2id(car der . ('_ . mip))
   end;

symbolic procedure idtomind(par,der_id);
   % given a derivative coordinate in identifier notation, finds the
   % corresponding multiindex notation. Works for even (par=0) and odd (par=1)
   % jetspace coordinates.
   if par=0 then cdr assoc(der_id,i2m_jetspace!*)
    else cdr assoc(der_id,i2m_jetspace_odd!*);

symbolic procedure order_of_der_mind(der_mind);
   % finds the order of a given (odd) jetspace coordinate
   % in multiindex notation
   length_multiindex(cadr der_mind);

symbolic procedure order_of_der(par,der_id);
   % finds the order of a given (odd) jetspace coordinate
   if par=0 then cdr assoc(der_id,i2o_jetspace!*)
    else cdr assoc(der_id,i2o_jetspace_odd!*);

symbolic operator order_of_der;

symbolic procedure select_all_ders(par,var,l_vars);
  % Select inside l_vars the derivative variables of var.
  % l_vars must be an all-even or all-odd coordinate list!
  begin
    scalar tempoddvars;
    for each el in l_vars do
      if eq(car idtomind(par,el),var) then tempoddvars:=el . tempoddvars;
    return tempoddvars
  end;

symbolic procedure selectvars0(par,orderofder,sdepvars,svars);
  % The symbolic version of selectvars
  begin scalar fdo;
    for each el in svars do
      if and(member(car idtomind(par,el),sdepvars),
	eqn(order_of_der(par,el),orderofder)) then
	  fdo:=el . fdo;
    return reverse(fdo)
  end;

symbolic procedure selectvars(par,orderofder,depvars,vars);
  % From a set of (even or odd) parametric derivatives `vars' collects
  % derivative coordinates of some given dependent variables `depvars'
  % and of order equal to `orderofder'
  cons('list,selectvars0(par,orderofder,cdr depvars,cdr vars));

symbolic operator selectvars;

symbolic procedure cde_jetspace();
   begin scalar all_mind!*;
      n_indep_var:=length(indep_var!*);
      if n_indep_var equal 0 then rederr "Error: missing dependent variables";
      % produces a list of all multiindexes obtained from the zero multiindex
      % and fulfilling the condition length<=total_order
      % then generates all derivative coordinates in multiindex notation
      all_mind_table!*:=
       	generate_prolongation_table(cde_mkzero(length(indep_var!*)),
	  total_order);
      all_der_mind!*:=join_dvar_mind(dep_var!*,all_mind_table!*);
      all_odd_mind!*:=join_dvar_mind(odd_var!*,all_mind_table!*);
      all_mind!*:=for each el in all_mind_table!* collect car el;
      % produces lists with all derivative coordinates
      % of dependent and odd coordinates in identifier notation
      all_der_id!*:=for each el in all_der_mind!* collect mind_to_eid(el);
      all_der_id:='list . all_der_id!*;
      all_odd_id!*:=for each el in all_odd_mind!* collect mind_to_eid(el);
      all_odd_id:='list . all_odd_id!*;
      % the number of all ext variables
      n_all_ext:=length(all_odd_id!*);
      % makes association lists which are used for conversion
      % from identifiers to multiindexes.
      i2m_jetspace!*:=pair(all_der_id!*,all_der_mind!*);
      i2m_jetspace_odd!*:=pair(all_odd_id!*,all_odd_mind!*);
      % makes association lists which are used
      % for the computation of the order of a multiindex or
      % a derivative coordinate
%      m2o_jetspace!*:=pair(all_mind!*,
%       for each el in all_mind!* collect length_multiindex(el)
%      );
      i2o_jetspace!*:=pair(all_der_id!*,
       for each el in all_der_mind!* collect order_of_der_mind(el)
      );
      i2o_jetspace_odd!*:=pair(all_odd_id!*,
       for each el in all_odd_mind!* collect order_of_der_mind(el)
      );
   end;

endmodule;

end;