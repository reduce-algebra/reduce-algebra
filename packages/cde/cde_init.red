module cde_init; % CDE package initialization file

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
% Master procedures: creating the environment and saving it.
%-----------------------------------------------------------------------------%
%

symbolic procedure cde_init_jetspace(jetspace);
% Here I setup the jetspace and initialize symbolic equivalents
% of global algebraic lists in input.
begin
      scalar jetspace_first,jetspace_second,jetspace_third;
      % Processing the first argument of cde(jetspace,equation)
      if not(cde_alglistp(jetspace) and eqn(length(jetspace),5))
       then
        rederr "Error: first argument must be an algebraic list of 4 elements";
      jetspace_first:=<<jetspace:=cdr jetspace; car jetspace>>;
      if not(cde_alglistp(jetspace_first) and length(jetspace_first) > 1)
       then rederr "Error: missing list of independent variables";
      indep_var!*:=clean_algebraic_list(jetspace_first);
      jetspace_second:=<<jetspace:=cdr jetspace; car jetspace>>;
      if not(cde_alglistp(jetspace_second) and length(jetspace_second) > 1)
       then rederr "Error: missing list of dependent variables";
      dep_var!*:=clean_algebraic_list(jetspace_second);
      jetspace_third:=<<jetspace:=cdr jetspace; car jetspace>>;
      if not(cde_alglistp(jetspace_third)) then rederr
        "Error: first argument must be an algebraic list of 4 lists";
      odd_var!*:=clean_algebraic_list(jetspace_third);
      if eqn(length(odd_var!*),0) then
      <<
        prin2t "No odd variables - working with even variables only,
          as requested.";
        odd_var!*:=list(gensym());
        principal_odd!*:=odd_var!*;
        de_odd:=list(0)
      >>;
      total_order:=cadr jetspace;
      if not fixp total_order then rederr
        "Error: missing maximal order of jetspace";
end;

symbolic procedure init_empty_equation();
  begin
    prin2t "Warning: even and odd equation missing;";
    prin2t "Working on jetspace as requested ...";
    principal_der!*:=
      list(
	cde_list2id(list(car dep_var!*,'_,total_order,car indep_var!*))
	  );
    de!*:=list('letop);
    principal_odd!*:=
      list(
	cde_list2id(list(car odd_var!*,'_,total_order,car indep_var!*))
	  );
    de_odd!*:=list('letop)
  end;

symbolic procedure check_empty(sequation);
  % Check if a list is made by empty lists.
  % In positive case it returns 1.
  begin
    scalar tempbool;
    tempbool:=1;
    for each el in sequation do
      if cde_alglistp(el) and not(null(cdr el)) then tempbool:=0;
    return tempbool
  end;

symbolic procedure init_empty_even_equation(equation_odd);
  begin
    scalar equation_odd_first,equation_odd_second;
    % Parsing even equations
    prin2t "Warning: even equation missing.";
    principal_der!*:=
      list(
        cde_list2id(list(car dep_var!*,'_,total_order,car indep_var!*))
	  );
    de!*:=list('letop);
    % Parsing odd equations
    equation_odd_first:=car equation_odd;
    if not(cde_alglistp(equation_odd_first)) then
      rederr "Error: principal odd derivatives must be in an algebraic list";
    principal_odd!*:=cdr equation_odd_first;
    equation_odd_second:=cadr equation_odd;
    if not(cde_alglistp(equation_odd_second)) then
      rederr "Error: rhs of odd equations must be in an algebraic list";
    de_odd!*:=cdr equation_odd_second;
    if length(de_odd!*) neq length(principal_odd!*) then rederr
      "Error: odd DE mismatch";
  end;

symbolic procedure init_empty_odd_equation(equation_even);
  begin
    scalar equation_even_first,equation_even_second;
    equation_even_first:=car equation_even;
    if not(cde_alglistp(equation_even_first)) then rederr
      "Error: even principal derivatives must be in an algebraic list";
    principal_der!*:=cdr equation_even_first;
    equation_even_second:=cadr equation_even;
    if not(cde_alglistp(equation_even_second)) then rederr
      "Error: rhs of even equations must be in an algebraic list";
    de!*:=cdr(equation_even_second);
    if length(de!*) neq length(principal_der!*) then rederr
      "Error: even DE mismatch";
    prin2t "Warning: odd equation missing.";
    principal_odd!*:=
	list(
	  cde_list2id(list(car odd_var!*,'_,total_order,car indep_var!*))
	    );
    de_odd!*:=list('letop);
  end;

symbolic procedure init_even_odd_equation(equation_even,equation_odd);
  begin
    scalar equation_even_first,equation_even_second,
      equation_odd_first,equation_odd_second;
    % Parsing even equations
    equation_even_first:=car equation_even;
    if not(cde_alglistp(equation_even_first)) then rederr
      "Error: even principal derivatives must be in an algebraic list";
    principal_der!*:=cdr equation_even_first;
    equation_even_second:=cadr equation_even;
    if not(cde_alglistp(equation_even_second)) then rederr
      "Error: rhs of even equations must be in an algebraic list";
    de!*:=cdr(equation_even_second);
    if length(de!*) neq length(principal_der!*) then rederr
      "Error: even DE mismatch";
    % Parsing odd equations
    equation_odd_first:=car equation_odd;
    if not(cde_alglistp(equation_odd_first)) then
      rederr "Error: principal odd derivatives must be in an algebraic list";
    principal_odd!*:=cdr equation_odd_first;
    equation_odd_second:=cadr equation_odd;
    if not(cde_alglistp(equation_odd_second)) then
      rederr "Error: rhs of odd equations must be in an algebraic list";
    de_odd!*:=cdr equation_odd_second;
    if length(de_odd!*) neq length(principal_odd!*) then rederr
      "Error: odd DE mismatch";
  end;

symbolic procedure cde_init_equation(equation);
% Here I setup the differential equation
% (ordinary or partial, scalar or system)
begin
      scalar equation_even,equation_odd;
      % Processing the second argument of cde(jetspace,equation)
      % If equation is missing:
      if not(cde_alglistp(equation) and (length(equation) equal 5)) then
	init_empty_equation()
      else if eqn(check_empty(cdr equation),1) then init_empty_equation()
      else
      <<
	equation_even:=list(nth(equation,2),nth(equation,3));
	equation_odd:=list(nth(equation,4),nth(equation,5));
	if eqn(check_empty(equation_even),1) then
 	  init_empty_even_equation(equation_odd)
        else if eqn(check_empty(equation_odd),1) then
 	  init_empty_odd_equation(equation_even)
	else init_even_odd_equation(equation_even,equation_odd)
      >>;
      % Change next identifiers if you wish to change prefix
      % to total derivatives
      id_tot_der!*:='dd;
end;

symbolic procedure cde_exec_modules();
begin
      prin2t "Loading cde tools ... ";
      cde_tools();
      prin2t "Building cde data structure in 4 steps:";
      prin2t "1 - Building jetspace ...";
      cde_jetspace();
      prin2t "2 - Building principal and parametric derivatives ...";
      cde_principal_parametric_derivatives(total_order);
      prin2t "3 - Building total derivatives ...";
      cde_total_derivatives();
      prin2t "4 - Building differential consequences in 3 steps:";
      cde_differential_consequences();
      prin2t "5 - Defining C-differential operators ...";
      cde_cdiff();
      prin2t "6 - Defining superfunctions ...";
      cde_superfun();
      prin2t "7 - Defining operations on C-differential operators ...";
      cde_cdcalc();
      prin2t "8 - Defining calculus of variations ...";
      cde_varcalc();
   end;

symbolic procedure cde(jetspace,equation);
      % Initialization of global variables
   begin
      cde_init_jetspace(jetspace);
      cde_init_equation(equation);
      cde_exec_modules();
   end;

symbolic operator cde;

symbolic procedure save_cde_state(statefilename);
   begin scalar n_all_principal_der,n_all_parametric_der,
      n_all_principal_odd,n_all_parametric_odd;
      if (not stringp statefilename) then rederr
      	 "Error: save_cde_state parameter must be a string!";
      off echo;
      off nat;
      out <<statefilename>>;
      prin2t "% CDE state file -- use for debugging purposes";
      prin2t "% even equation:";
      prin2 "principal_der!*:=";prin2t principal_der!*;
      prin2 "de!*:=";prin2t de!*;
      prin2t "% odd equation";
      prin2 "principal_odd!*:=";prin2t principal_odd!*;
      prin2 "de_odd!*";prin2t de_odd!*;
      prin2t "% Settings:";
      prin2 "indep_var!*:=";prin2t indep_var!*;
      prin2 "dep_var!*:=";prin2t dep_var!*;
      prin2 "odd_var!*:=";prin2t odd_var!*;
      prin2 "deg_indep_var!*:=";prin2t deg_indep_var!*;
      prin2 "deg_dep_var!*:=";prin2t deg_dep_var!*;
      prin2 "deg_odd_var!*:=";prin2t deg_odd_var!*;
      prin2 "total_order:=";prin2t total_order;
      prin2 "id_tot_der!*:=";prin2t id_tot_der!*;
      prin2t "% Here starts the output of computations of the program.";
      prin2t "% number of independent variables:";
      prin2 "n_indep_var:=";prin2t n_indep_var;
      prin2t "% all multiindexes in table format:";
      prin2 "all_mind_table!*:=";prin2t all_mind_table!*;
      prin2t "% all even derivatives in multiindex notation:";
      prin2 "all_der_mind!*:=";prin2t all_der_mind!*;
      prin2t "% all odd derivatives in multiindex notation:";
      prin2 "all_odd_mind!*:=";prin2t all_odd_mind!*;
      prin2t "% all even derivatives in identifier notation:";
      prin2 "all_der_id!*:=";prin2t all_der_id!*;
      prin2t "% all odd derivatives in identifier notation:";
      prin2 "all_odd_id!*:=";prin2t all_odd_id!*;
      prin2t "% number of all ext symbols:";
      prin2 "n_all_ext:=";prin2t n_all_ext;
      prin2t "% alist of even derivative coordinates:";
      prin2 "i2m_jetspace!*:=";prin2t i2m_jetspace!*;
      prin2t "% alist of odd derivative coordinates:";
      prin2 "i2m_jetspace_odd!*:=";prin2t i2m_jetspace_odd!*;
      prin2t "% alist of even derivative coordinates - order of derivative:";
      prin2 "i2o_jetspace!*:=";prin2t i2o_jetspace!*;
      prin2t "% alist of odd derivative coordinates - order of derivative:";
      prin2 "i2o_jetspace_odd!*:=";prin2t i2o_jetspace_odd!*;
      prin2t "% list of even principal derivatives:";
      prin2 "all_principal_der!*:=";prin2t all_principal_der!*;
      prin2t "% list of even parametric derivatives:";
      prin2 "all_parametric_der!*:=";prin2t all_parametric_der!*;
      prin2t "% list of odd principal derivatives:";
      prin2 "all_principal_odd!*:=";prin2t all_principal_odd!*;
      for each el in all_principal_odd!* do
	<<prin2 el;prin2 " = ";prin2t !*a2k(replace_oddext(el))>>;
      prin2t "% list of odd parametric derivatives:";
      prin2 "all_parametric_odd!*:=";prin2t all_parametric_odd!*;
      for each el in all_parametric_odd!* do
	<<prin2 el;prin2 " = ";prin2t !*a2k(replace_oddext(el))>>;
      prin2t "% number of ext principal derivatives:";
      prin2 "n_all_principal_ext:=";prin2t n_all_principal_ext;
      prin2t "% number of ext parametric derivatives:";
      prin2 "n_all_parametric_ext:=";prin2t n_all_parametric_ext;
      prin2t "% set of identifiers for total derivatives:";
      prin2 "tot_der!*:=";prin2t tot_der!*;
%      prin2t "% set of identifiers for total derivatives for external use:";
      prin2t "% set up the auxiliary variable `letop'";
      prin2 "for each el in indep_var do depend letop,el;";
      prin2t "% Characterization of primary differential consequences:";
      prin2 "primary_diffcon_der_tot!*:=";prin2t primary_diffcon_der_tot!*;
      prin2 "primary_diffcon_odd_tot!*:=";prin2t primary_diffcon_odd_tot!*;
      prin2 "primary_diffcon_der!*:=";prin2t primary_diffcon_der!*;
      prin2 "primary_diffcon_odd!*:=";prin2t primary_diffcon_odd!*;
      prin2t "% Alists of differential conseq. needed in total derivatives:";
      prin2 "diffcon_der!*:=";prin2t diffcon_der!*;
      prin2 "diffcon_odd!*:=";prin2t diffcon_odd!*;
      prin2t "% Principal derivatives computed:";
      prin2 "diffcon_comp_der!*:=";prin2t diffcon_comp_der!*;
      prin2 "diffcon_comp_odd!*:=";prin2t diffcon_comp_odd!*;
      prin2 "diffcon_comp_ext!*:=";prin2t diffcon_comp_ext!*;
      prin2t "% Alists of principal derivatives in terms of parametric expr.:";
      prin2 "diffcon_param_der!*:=";prin2t diffcon_param_der!*;
      prin2 "diffcon_param_ext!*:=";prin2t diffcon_param_ext!*;
%      prin2t "% Total derivatives declarations:";
%      prin2 "for i:=1:n_indep_var do
% super_vectorfield(nth(tot_der!*,i),append(indep_var!*,all_der_id!*),all_ext)";
      prin2t "% Coefficients of total derivatives:";
      n_all_parametric_der:=length(all_parametric_der!*);
      n_all_principal_der:=length(all_principal_der!*);
      n_all_parametric_odd:=length(all_parametric_odd!*);
      n_all_principal_odd:=length(all_principal_odd!*);
      for i:=1:n_indep_var do
   	 <<
      	    for j:=1:n_indep_var do
      	    <<
	      prin2 "% component of ";
	      prin2 nth(tot_der!*,i);
	      prin2 " w.r.t. ";
              prin2t nth(indep_var!*,j);
	      prin2 nth(tot_der!*,i);
	      prin2 "("; prin2 0;prin2 ",";prin2 j;prin2 "):=";
   	      prin2t aeval list(nth(tot_der!*,i),nth(indep_var!*,j));
      	    >>;
      	    for j:=1:n_all_parametric_der do
      	    <<
	      prin2 "% component of ";
	      prin2 nth(tot_der!*,i);
	      prin2 " w.r.t. ";
              prin2t nth(all_parametric_der!*,j);
	      prin2 nth(tot_der!*,i);
	      prin2 "(";prin2 0;prin2 ","; prin2(n_indep_var+j);prin2 "):=";
   	      prin2t aeval list(nth(tot_der!*,i),nth(all_parametric_der!*,j));
      	    >>;
      	    for j:=1:n_all_principal_der do
      	    <<
	      prin2 "% component of ";
	      prin2 nth(tot_der!*,i);
	      prin2 " w.r.t. ";
              prin2t nth(all_principal_der!*,j);
	      prin2 nth(tot_der!*,i);
              prin2 "(";prin2 0;prin2 ",";
	      prin2(n_indep_var+n_all_parametric_der+j);prin2 "):=";
   	      prin2t aeval list(nth(tot_der!*,i),nth(all_principal_der!*,j));
      	    >>;
      	    for j:=1:n_all_parametric_odd do
      	    <<
	      prin2 "% component of ";
	      prin2 nth(tot_der!*,i);
	      prin2 " w.r.t. ";
   	      prin2t nth(all_parametric_odd!*,j);
	      prin2 nth(tot_der!*,i);
	      prin2 "(";prin2 1;prin2 ",";prin2 j;prin2 "):=";
   	      prin2t aeval list(nth(tot_der!*,i),
 		replace_oddext(nth(all_parametric_odd!*,j)));
      	    >>;
            for j:=1:n_all_principal_odd do
      	    <<
	      prin2 "% component of ";
	      prin2 nth(tot_der!*,i);
	      prin2 " w.r.t. ";
   	      prin2t nth(all_principal_odd!*,j);
	      prin2 nth(tot_der!*,i);
	      prin2 "("; prin2 1; prin2 ",";
	      prin2(n_all_parametric_odd+j); prin2 "):=";
   	      prin2t aeval list (nth(tot_der!*,i),
 		replace_oddext(nth(all_principal_odd!*,j)));
      	    >>;
   	 >>;
   	 prin2t ";end;";
   	 shut <<statefilename>>;
   	 on echo;
   	 on nat;
   end;

symbolic operator save_cde_state;

endmodule;

end;
