module cde_diffcon; % CDIFF package, computation of the
                    % differential consequences of the initial system of PDEs.

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
% Computation of differential consequences of E=0
%-----------------------------------------------------------------------------%
%
% We compute differential consequences as total derivatives
% (on the free jetspace!) of de and de_odd,
% then we solve the system of differential consequences
% in terms of parametric derivatives only.
% While solving, other principal derivatives could be needed and computed.

symbolic procedure order_diffcon(par,dcon_temp);
   % Given an alist of differential consequences it will be ordered
   % according with decreasing order of principal derivative.
   % It uses quicksort.
   % The only purpose of this function is to order initial equations
   % according with decreasing order of derivatives.
begin
  scalar locless,locequal,locgreater,locpivot;
  if not(dcon_temp) then return nil else return
  <<
    locpivot:=car dcon_temp;
    for each el in dcon_temp do
      if lessp(order_of_der(par,car el),order_of_der(par,car locpivot))
        then locless:=el . locless
      else if eqn(order_of_der(par,car el),order_of_der(par,car locpivot))
        then locequal:=el . locequal
      else locgreater:=el . locgreater;
    append(
      append(locequal,order_diffcon(par,locgreater)),
      order_diffcon(par,locless)
    	)
  >>;
end;

symbolic procedure diff_vars(var1,var2);
   % takes the difference of two variables in multiindex notation;
   % returns -1 if the dependent part is different
   % or if the difference of multiindexes contains negative entries;
   % return the difference of the corresponding multiindexes in other cases.
  begin scalar m_n,mmn; integer mmni;
    if neq(car var1,car var2) then return (-1);
    m_n:=pair(cadr var1,cadr var2);
    for each el in m_n do
    <<
      mmni:=car el - cdr el;
      if mmni >=0 then mmn:=mmni . mmn
    >>;
    if length(mmn)<n_indep_var then return (-1)
    else return reverse mmn
  end;

symbolic procedure add_diffcon(par,dcon);
   % Adds the expression of the differential consequences
   % corresponding to the list of principal derivatives `dcon'
   % We assume that diffcon_der!* and diffcon_odd!*
   % are made of derivatives in decreasing order
   begin scalar diffcontemp,vartemp,pder,exprtemp; integer ordtemp,dmind,cnt;
      if par=0 then diffcontemp:=diffcon_der!* else diffcontemp:=diffcon_odd!*;
      for each el in dcon do
      <<
         vartemp:=idtomind(par,el);
         ordtemp:=order_of_der(par,el);
         dmind:=-1;
         cnt:=1;
         % Next loop searches the starting point of differential consequence
         % of order less than the order of the variable `el'.
         while order_of_der(par,car nth(diffcontemp,cnt))>=ordtemp do
            cnt:=cnt+1;
         % Next loop searches for a variable with the same dependent part
         % of the given one and a multiindex which has positive difference
         % with the given one.
         while dmind=-1 do
         <<
	   pder:=car nth(diffcontemp,cnt);
           dmind:=diff_vars(vartemp,idtomind(par,pder));
           cnt:=cnt+1
         >>;
         exprtemp:=cadr nth(diffcontemp,cnt-1);
         for i:=1:n_indep_var do
            for j:=1:nth(dmind,i) do
	      exprtemp:=aeval list(nth(tot_der!*,i),exprtemp);
         if not freeof(exprtemp,'letop) then exprtemp:=aeval 'letop;
	 % we insert the differential consequence
         % in such a way to preserve the ordering
         cnt:=1;
         while order_of_der(par,el) <
	    order_of_der(par,car nth(diffcontemp,cnt)) do cnt:=cnt+1;
         diffcontemp:=cde_insert(list(el,exprtemp),diffcontemp,cnt);
      >>;
      if par=0 then diffcon_der!*:=diffcontemp
      else diffcon_odd!*:=diffcontemp;
      if par=0 then
         diffcon_comp_der!*:=for each el in diffcon_der!* collect car el
      else
         diffcon_comp_odd!*:=for each el in diffcon_odd!* collect car el;
   end;

symbolic procedure check_diffcon(dc_der,dc_odd);
  begin scalar dc_extra_der,dc_extra_odd,dc_new_der,dc_new_odd,
      ell_ext,exprtemp;
    % check if computed differential consequences
    % depend on non-computed (extra) differential consequences.
    % If such non-computed differential consequences exist, compute them.
    dc_extra_der:=cde_diffset(all_principal_der!*,diffcon_comp_der!*);
    dc_extra_odd:=cde_diffset(all_principal_odd!*,diffcon_comp_odd!*);
    for each el in dc_der do
    <<
      exprtemp:=cadr assoc(el,diffcon_der!*);
      for each ell in dc_extra_der do
	if not freeof(exprtemp,ell) then dc_new_der:=ell . dc_new_der
    >>;
    for each el in dc_odd do
    <<
      exprtemp:=cadr assoc(el,diffcon_odd!*);
      for each ell in dc_extra_der do
	if not freeof(exprtemp,ell) then dc_new_der:=ell . dc_new_der;
      for each ell in dc_extra_odd do
      <<
	ell_ext:=oddext(ell);
	if not freeof(exprtemp,ell_ext) then
	  dc_new_odd:=ell . dc_new_odd
      >>
    >>;
    return list(cde_mkset(dc_new_der),cde_mkset(dc_new_odd))
  end;

symbolic procedure generate_diffcon();
   % Starting from the primary differential consequences, the code:
   % 1 adds all expressions of differential consequences;
   % 2 makes a scan of them in order to find
   %   secondary differential consequences;
   % 3 if there are secondary diff. cons, it adds all differential consequences
   %   and goes to item 2.
   begin scalar dcon_der,dcon_odd,tempder; integer dependency,n_dcon;
      % Initialization of the differential consequences.
      % These are lists of even (odd) principal derivatives
      % paired with their expression.
      % The lists are ordered according with decreasing order of derivatives.
      diffcon_der!*:=
	order_diffcon(0,pair(principal_der!*,
	  for each el in de!* collect list(el)));
      diffcon_odd!*:=
	order_diffcon(1,pair(principal_odd!*,
	  for each el in de_odd!* collect list(replace_oddext(el))));
      diffcon_comp_der!*:=for each el in diffcon_der!* collect car el;
      diffcon_comp_odd!*:=for each el in diffcon_odd!* collect car el;
      dependency:=1;
      dcon_der:=primary_diffcon_der!*;
      dcon_odd:=primary_diffcon_odd!*;
      n_dcon:=1;
      while dependency=1 do
      <<
         % compute current differential consequences;
         % it could be that one of the current dcon files is empty.
         if dcon_der then add_diffcon(0,dcon_der);
         if dcon_odd then add_diffcon(1,dcon_odd);
         tempder:=check_diffcon(dcon_der,dcon_odd);
         dcon_der:=car tempder;
         dcon_odd:=cadr tempder;
         if and(not(dcon_der),not(dcon_odd)) then dependency:=0
	 else
	 <<
	   n_dcon:=n_dcon+1;
	   prin2 "Presence of ";prin1 n_dcon;
	   prin2t "-ary differential consequences";
	 >>
      >>;
   end;

symbolic procedure replace_diffcon_totder(even_diffcon_tot,odd_diffcon_tot,
    prin_param_der,prin_param_ext);
    begin
      for each el in even_diffcon_tot do
      	set_svf(car el,0,caddr el,
          cdr assoc(car reverse el,prin_param_der)
      	    );
      for each el in odd_diffcon_tot do
	set_svf(car el,1,caddr el,
	  cdr assoc(oddext(car reverse el),prin_param_ext)
      	    );
    end;

symbolic procedure cde_differential_consequences();
  begin scalar templdcon,diffcon_comp_der_paramexpr,diffcon_comp_ext_expr,
      diffcon_comp_ext_evenparamexpr,diffcon_comp_ext_paramexpr;
    % We start by generating differential consequences.
    prin2t "   a - Calculating differential consequences ...";
    generate_diffcon();
    prin2t "   b - Solving the system of differential consequences ...";
    % We solve the system of differential consequences in order
    % to obtain principal derivatives only on the lhs.
    % We do it in steps in order to limit memory occupation.
    % 0 - First of all we prepare new lists of variables
    %     and corresponding expressions:
    diffcon_comp_ext!*:=for each el in diffcon_comp_odd!* collect oddext(el);
    diffcon_comp_ext_expr:=for each el in diffcon_odd!* collect cadr el;
    %
    % 1 - replaces all computed even principal derivatives in the rhs
    %     in order to obtain a 'clean' system:
    %     even principal derivatives=even parametric expressions;
    repprincparam_der:=for each el in diffcon_der!* collect
      list('replaceby,car el,cadr el);
    diffcon_comp_der_paramexpr:=cdr evalwhereexp(
      list('list . repprincparam_der,'list . diffcon_comp_der!*)
    	);
    diffcon_param_der!*:=pair(diffcon_comp_der!*,diffcon_comp_der_paramexpr);
    % renews repprincparam_der in order to have a 'clean' replacement list:
    repprincparam_der:=for each el in diffcon_param_der!* collect
      list('replaceby,car el,cdr el);
    %
    % 2 - replaces all even principal derivatives into the prolongation of
    %     odd equations and prepares the substitution list;
%%     prin2t "repprincparam_der:=";
%%     prin1 repprincparam_der;terpri();
%%     prin2t "diffcon_comp_ext_expr:";
%%     prin1 diffcon_comp_ext_expr;terpri();
    diffcon_comp_ext_evenparamexpr:=
%      for each el in diffcon_comp_ext_expr collect
%      cdr evalwhereexp(list('list . repprincparam_der,'list . list(el)));
      cdr evalwhereexp(
	list('list . repprincparam_der,'list . diffcon_comp_ext_expr)
      );
    %
    % 3 - replaces all computed odd principal derivatives on the rhs
    %     in order to obtain a 'clean' system:
    %     odd principal derivatives=odd parametric expressions;
    templdcon:=pair(diffcon_comp_ext!*,diffcon_comp_ext_evenparamexpr);
    repprincparam_ext:=for each el in templdcon collect
      list('replaceby,car el,cdr el);
    diffcon_comp_ext_paramexpr:=
      cdr evalwhereexp(
	list('list . repprincparam_ext,'list . diffcon_comp_ext!*)
	  );
    diffcon_param_ext!*:=
      pair(diffcon_comp_ext!*,diffcon_comp_ext_paramexpr);
    % Renew repprincparam_ext in order to have a `clean' replacement list
    repprincparam_ext:=for each el in diffcon_param_ext!* collect
      list('replaceby,car el,cdr el);
    % Define an odd version of repprincparam_ext
    repprincparam_odd:=for each el in diffcon_param_ext!* collect
      list('replaceby,extodd(car el),replace_extodd(cdr el));
    % Redefine repprincparam_der and repprincparam_ext to be algebraic lists
    repprincparam_der:='list . repprincparam_der;
    repprincparam_odd:='list . repprincparam_odd;
    % Finally, we replace the differential consequences
    % in the expression of total derivatives
    prin2t "   c - Replacing differential cons. in total derivatives ...";
    replace_diffcon_totder(primary_diffcon_der_tot!*,primary_diffcon_odd_tot!*,
      diffcon_param_der!*,diffcon_param_ext!*);
  end;

algebraic procedure restrict_to_equation(fct);
  begin
    return (fct where repprincparam_der)
  end;

endmodule;

end;
