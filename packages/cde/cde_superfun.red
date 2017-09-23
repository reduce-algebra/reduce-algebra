module cde_superfun; % CDE package, data structure for superfunctions

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

symbolic procedure mk_superfun(superfun,num_arg,len_target);
  % This procedures creates a vector superfunction
  % and associates with it the following properties:
  % 1 - the parity, or number of odd variable factors, num_arg
  % 2 - the length of the target space, len_arg.
  % The odd variables involved are all_parametric_odd!*
  % NOTE: to get the number of arguments do get('sfnarg,superfun);
  % to get the length of vectors in the target space do get('sftarget,superfun);
  % to see if an identifier is a superfun do get('sfun,superfun) or
  % superfunp(superfun);
begin
  mkop superfun;
  put('sfun,superfun,t);
  if not numberp num_arg then rederr "Error in the number of arguments";
  put('sfnarg,superfun,num_arg);
  if not fixp num_arg then
    rederr "Error: number of arguments must be an integer";
  if not fixp len_target then
    rederr "Error: the length of image vectors must be an integer";
  put('sftarget,superfun,len_target);
end;

symbolic operator mk_superfun;

symbolic procedure superfunp(superfun);
  get('sfun,superfun);

symbolic procedure check_superfun_degone(superfun);
  % Checks if a superfunction has odd degree one
  begin
    scalar num_arg,len_target;
    if not superfunp(superfun) then
      rederr "Error: the first argument must be a declared superfunction";
    if not eqn(num_arg:=get('sfnarg,superfun),1) then
      rederr "Error: the operator must have exactly one argument";
    if not fixp(len_target:=get('sftarget,superfun)) then
      rederr "Error: the length of image vectors must be an integer";
  end;

symbolic procedure check_superfun_scalar(superfun);
  % Checks if the superfunction of a CDiff operator has one-dimensional target.
  begin
    integer len_target;
    if not superfunp(superfun) then
      rederr "Error: the first argument must be a declared superfunction";
    if not fixp(len_target:=get('sftarget,superfun)) then
      rederr "Error: the dimension of the target space must be an integer";
    if not eqn(len_target,1) then
      rederr "Error: the dimension of the target space must be one";
  end;

symbolic procedure check_superfun_sametype(sf1,sf2);
  begin
    scalar parity1,parity2,target1,target2;
    if not superfunp(sf1) then rederr
      "The first argument must be a declared superfunction";
    if not superfunp(sf2) then rederr
      "The second argument must be a declared superfunction";
    parity1:=get('sfnarg,sf1);
    parity2:=get('sfnarg,sf2);
    if not eqn(parity1,parity2) then rederr
      "The number of arguments of the superfunctions must be the same";
    target1:=get('sftarget,sf1);
    target2:=get('sftarget,sf2);
    if not eqn(target1,target2) then rederr
      "The length of vectors in the target space must be the same";
  end;

% The procedure below has been superseded by the redefinition of superfunctions
% Now any superfunction is assumed to be built with all available odd variables
% from all_parametric_odd!*
%% symbolic procedure check_superfun_args(superfun);
%%   % Checks if  superfunction has all arguments of length
%%   % equal to the number of odd variables.
%%   begin
%%     scalar n_odd_var,len_arg;
%%     n_odd_var:=length(odd_var!*);
%%     if not superfunp(superfun) then
%%       rederr "Error: the first argument must be a declared superfunction";
%%     len_arg:=cdr get('sflarg,superfun);
%%     for each el in len_arg do if not eqn(el,n_odd_var) then
%%       rederr "Error: dimension of arguments non-conformant to odd variables";
%%   end;

symbolic procedure conv_genfun2vform(genfun_odd,vform);
  % Convert a superfunction of odd degree one, i.e. a
  % linear function on odd variables, into a variational 2-form
  % by odd left multiplication by the vector of odd variables.
begin scalar num_arg,len_target;
  check_superfun_degone(genfun_odd);
  num_arg:=get('sfnarg,genfun_odd);
  len_target:=get('sftarget,genfun_odd);
  if not eqn(len_target,length(odd_var!*)) then rederr
    "Error: The number of components is not equal to the number of odd vars";
  mk_superfun(vform,1+num_arg,1);
  vform(1):=replace_extodd aeval cons('plus,
    for i:=1:len_target collect
      odd_product(nth(odd_var!*,i),aeval list(genfun_odd,i))
     );
end;

symbolic operator conv_genfun2vform;

symbolic procedure conv_genfun2biv(genfun_odd,biv);
  % Convert a superfunction of odd degree one,
  % i.e. a linear function on odd variables,
  % into a bivector by odd multiplication by
  % the vector of odd variables.
begin scalar num_arg,len_target;
  check_superfun_degone(genfun_odd);
  num_arg:=get('sfnarg,genfun_odd);
  len_target:=get('sftarget,genfun_odd);
  if not eqn(len_target,length(odd_var!*)) then rederr
    "Error: The number of components is not equal to the number of odd vars";
  mk_superfun(biv,1+num_arg,1);
  biv(1):=replace_extodd aeval cons('plus,
    for i:=1:len_target collect
      odd_product(aeval list(genfun_odd,i),nth(odd_var!*,i))
     );
end;

symbolic operator conv_genfun2biv;

symbolic procedure define_cdiffop(superfun_ij,cdiff_op_list);
  % cdiff_op_list must be of the type (cdiff_op ii jj);
  % This procedure defines a scalar operator from a superfunction
  % which is linear in one single odd variable and its derivatives.
  % Warning: no check is performed on arguments!
    begin
      scalar cdiffopn,cdiffopind,exprop,phi,tempcoeff,tempoddvar,tempmind,
	change_expand_td,tempivars;
      cdiffopn:=car cdiff_op_list;
      cdiffopind:=cdr cdiff_op_list;
      phi:=gensym();
      exprop:=nil ./ 1;
      change_expand_td:=0;
      if eq(get('td,'simpfn),'compute_td) then
      <<
	change_expand_td:=1;
	noexpand_td()
      >>;
      for each el in superfun_ij do
      <<
	tempcoeff:=car el;
        tempoddvar:=cadr el;
        tempmind:=cadr idtomind(1,tempoddvar);
	tempivars:=for i:=1:n_indep_var join
	  list(nth(indep_var!*,i),nth(tempmind,i));
	exprop:=addsq(
	  simp aeval list('times,tempcoeff,append(list('td,phi),tempivars)),
	    exprop
	      );
      >>;
      cde_ev_forall cde_forall_form(
	cdiffopn,cdiffopind,list(phi),mk!*sq exprop
	  );
      return if eqn(change_expand_td,1) then expand_td()
    end;

symbolic procedure split_superfun(superfun,oddvar);
  % Given a linear (ie, odd degree one) scalar superfunction and an odd variable
  % returns an alist of identifiers of one odd variable in superfun paired
  % with its coefficient.
  % NOTE: works with linear superfunctions!
  begin
    scalar tempoddvars,superfun_split,tempcoeff;
%    tempoddvars:=select_all_ders(1,oddvar,all_parametric_odd!*);
    tempoddvars:=select_all_ders(1,oddvar,all_odd_id!*);
    superfun_split:=nil;
    for each el in tempoddvars do
      if not(eqn(tempcoeff:=coeffn(superfun,el,1),0))
      then superfun_split:=list(tempcoeff,el) . superfun_split;
    return superfun_split
  end;

symbolic procedure conv_superfun2cdiff(superfun,cdiff_op);
  % Inverse function to conv_cdiff2superfun;
  % for the moment it works only for superfunctions of odd degree one!
  % For any indices i,j, constructs the element a^j_{i,sigma}
  % as a superfunction of a scalar operator in the format of
  % an alist of identifiers of one odd variable paired with its coefficient
  % The alist is passed to define_cdiffop.
begin
  scalar len_oddvar,num_arg,len_arg,len_target,superfun_ij;
  check_superfun_degone(superfun);
  len_oddvar:=length(odd_var!*);
  num_arg:=get('sfnarg,superfun);
  len_arg:='list . list(len_oddvar);
  len_target:=get('sftarget,superfun);
  mk_cdiffop(cdiff_op,1,len_arg,len_target);
  for j:=1:len_oddvar do
    for i:=1:len_target do
    <<
      superfun_ij:=split_superfun(aeval list(superfun,i),nth(odd_var!*,j));
      define_cdiffop(superfun_ij,list(cdiff_op,i,j))
    >>;
end;

symbolic operator conv_superfun2cdiff;

symbolic procedure cde_superfun();
% Here initialization routines might be added if needed.
  prin2 "";

endmodule;

end;
