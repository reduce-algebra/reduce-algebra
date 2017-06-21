%**********************************************************************
module poly_GB$
%**********************************************************************
%  Interface subroutines to the F4 package of J P Faugere
%  Authors: Winfried Neun, May 2003, Thomas Wolf since 2003

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

symbolic procedure find_Singular$
   % Check the installation of Singular
   % Singular is not distributed together with Crack and thus the
   % installation directory is not known to Crack unlike the package
   % DiffElim which is distributed together with Crack.
begin scalar h1$

 if null singular_call then <<
  singular_call:=getenv "SingularCall"$
  if not filep singular_call then singular_call:=nil$
 >>$

 if null singular_call then
 if null filep (singular_call:="/usr/bin/Singular") then % lie, Eee, sente, gote, miai, tenuki, silo
 if null filep (singular_call:="/home/syam/Singular/3-0-4/x86_64-Linux/Singular") then % on SharcNet
 if null filep (singular_call:="/usr/local/share/Singular/3-1-6/x86_64-Linux/Singular") then % on sharc-198
 if null filep (singular_call:="/usr/local/Singular4/bin/Singular") then % goedel
 if null filep (singular_call:="/usr/local/bin/Singular") then % power mac
 singular_call:=nil;

 if singular_call then <<
  if print_ or null old_history then <<
   write"Singular will be called by ",singular_call$ terpri()$
   write"If this is not the correct call then input the command: "$terpri()$
   write"as  singular_call  ""path/Singular"""$terpri()$terpri()
  >>
 >>               else <<
  if print_ or null old_history then <<
   write"For calling Singular the program needs to know the calling command."$terpri()$
   write"The command 'which Singular' gives:"$terpri()$
   system"which Singular"$
   write"Please input this call if it is valid or another working call, like ""/usr/bin/Singular"": "$
   terpri()$
  >>$
  change_prompt_to ""$
  h1:=termread()$
  restore_interactive_prompt()$
  singular_call:=bldmsg("%w",h1)$
  restore_interactive_prompt()$ 
 >>$

 if null singular_lib then <<
  singular_lib:=getenv "SingularLib"$
  if not filep singular_lib then singular_lib:=nil$
 >>$

 if null singular_lib then 
 if null filep (singular_lib:="/usr/share/Singular/LIB") then % on Eee PC, sente, gote, tenuki, silo
 if null filep (singular_lib:="/usr/share/singular/LIB") then % miai
 if null filep (singular_lib:="/home/syam/Singular/3-0-4/LIB") then % on SharcNet
 if null filep (singular_lib:="/usr/local/share/Singular/3-1-6/LIB") then % on sharc-198
 if null filep (singular_lib:="/usr/local/Singular4/share/singular/LIB") then % on goedel
 if null filep (singular_lib:="/usr/local/share/singular/LIB") then % on power mac
 singular_lib:=nil;

 if singular_lib then <<
  if print_ or null old_history then <<
   write"The Singular library is assumed to be in ",singular_lib$ terpri()$
   write"If this is not the correct path then input the command: "$terpri()$
   write"as  singular_lib  ""path/LIB"""$terpri()$terpri()
  >>
 >>              else <<
  if print_ or null old_history then <<
   terpri()$
   write"For Singular to access its libraries it needs to know the library address."$
   terpri()$
   write"Please input the library directory with its path, e.g."$terpri()$
   write"If you do not know it, then input """"."$terpri()$
  >>;
  change_prompt_to ""$
  h1:=termread()$
  restore_interactive_prompt()$
  singular_lib:=bldmsg("%w",h1)$
 >>$

end$ % of find_Singular

symbolic procedure comp_groebner_basis(arglist)$
% This procedure is called from the procedure err_catch_groeb()
% in file crutil.red . err_catch_groeb() is called from
% alg_groebner() in crmain.red .

begin scalar pdes,forg,sol,n,result,l1,h1,h2,psys,kept_pdes,use,
      rational_bak,resimpli,rat_ineq$

  pdes:=car arglist$
  h1:=car arglist$
  if car arglist neq cadddr arglist then <<
   kept_pdes:=h1;
   h1:=cadddr arglist;
  >>$

  for each p in h1 do <<
   if get(p,'non_rat_kern) then use:=nil else 
   if (null vl_) or (groeb_solve = 'DiffElim) then use:=t else <<
    h2:=get(p,'kern);
    while h2 and not pairp car h2 do h2:=cdr h2;
    if null h2 then use:=t else use:=nil
   >>$

   if use then psys:=cons(p,psys)
          else <<
    kept_pdes:=union({p},kept_pdes);
    if print_ then <<
     write"Equation ",p," is "$
     if get(p,'non_rat_kern) then write"non-polynomial"
                             else write"differential"$
     write" and ignored in calling the external package."$
     terpri()
    >>
   >>
  >>$

  sol:=
  if groeb_solve = 'DiffElim then <<
   % The environment variable DiffElimCall has to be set.
   rational_bak:=!*rational; 
   if !*rational then <<resimpli:=t;algebraic (off rational)>>;
   % Even if currently is !*rational=nil, it still seems possible that
   % rational numbers appear in the equations --> always treat equations:
   resimpli:=t$

   % filter out all non-rational inequalities
   for each h1 in ineq_ do <<
    h2:=union(kernels denr h1,kernels numr h1);
    while h2                              and 
          ((atom car h2)             or 
           ((pairp car h2    ) and 
            (car car h2 = 'df) and 
            (atom cadr car h2)     )    )     do h2:=cdr h2;
    if null h2 then rat_ineq:=cons(h1,rat_ineq)
   >>$

   h1:=
   call_diffelim(
        % the list of equations:
    for each p in psys collect 
    if resimpli then (numr resimp get(p,'sqval) . 1)
                else              get(p,'sqval)      ,
        % the list of unknowns with different options:
%    nil,      % automatic mode
%    {ftem_}, % all unknowns in one group
    % {flin_,setdiff(ftem_,flin_)}, % preserving partial linearity
    % functions of same number of indep. variables in one group
    <<for each p in psys do l1:=union(get(p,'fcts),l1);
      l1:=sort_according_to(l1,ftem_)$
      n:=fctlength car l1$
      h1:=nil$
      while l1 do <<
        h2:=nil;
        while l1 and (fctlength car l1=n) do <<h2:=cons(car l1,h2); l1:=cdr l1>>$
        if l1 then n:=fctlength car l1$
        h1:=cons(reverse h2,h1)
      >>;
      reverse h1
    >>,
        % the list of known inequalities
    rat_ineq,
        % the maximal number of steps
    diffelim_steps
   );

   if !*rational neq rational_bak then
   if null rational_bak then algebraic (off rational)
                        else algebraic (on  rational)$

   if (null nth(h1,4)) and (null nth(h1,5)) and (zerop nth(h1,6)) then
   if print_ then <<write "The DiffElim computation is complete."$terpri()>>
             else                                                else <<
    if print_ then <<
     write "The DiffElim computation is not complete."$terpri()$
     write "One could increase diffelim_steps with the interactive"$terpri()$
     write "'as' command. Currently diffelim_steps = ",diffelim_steps$terpri()
    >>$
    kept_pdes:=car arglist  % Actually all returned equations should be
                            % equivalent to the equations read into DiffElim.
   >>$

   % DiffElim returns 5 lists: g,ot,n,u,b of which g,ot,u,b are lists
   % of expressions to vanish and n is a list of potentially new inequalities.
   % g,ot,u,b are appended and returned. The elements of the list n are already
   % here added to ineq_ and not below because the packages Singular,
   % GB (?) and groebner (REDUCE) to not generate new inequalities.

   for each h2 in caddr h1 do addSQineq(pdes,h2,t)$ % adding potentially new inequalities
   h1:={'list,cons('list,nconc(car h1,nconc(cadr h1,
                         nconc(cadddr h1,car cddddr h1))))}$
   h1
  >> else

  if ((groeb_solve = 'sl_lex) or
      (groeb_solve = 'sl_grad) or
      (groeb_solve = 'sl_revgrad)) then <<

   find_Singular()$
   if (null singular_call) or (null singular_lib) then nil else 
   if groeb_solve = 'sl_lex     then call_sing(ftem_,psys,'lex) else 
   if groeb_solve = 'sl_grad    then call_sing(ftem_,psys,'gradlex) else 
   if groeb_solve = 'sl_revgrad then call_sing(ftem_,psys,'revgradlex) 
  >>                               else
  if groeb_solve = 'gb_lex then
  algebraic {call_gb(lisp(cons('list,ftem_)),
                     lisp(cons('list,for each p in psys collect(
                                     reval {'!*sq,get(p,'sqval),t}))),
                     lisp 'lex)}
  else
  if groeb_solve = 'gb_revgrad then
  algebraic {call_gb(lisp(cons('list,ftem_)),
                     lisp(cons('list,for each p in psys collect(
                                     reval {'!*sq,get(p,'sqval),t}))),
                     lisp 'revgradlex)}
  else <<
   write"Situation before call of Groebner:"$terpri()$
   print_statistic(pdes,append(cadr arglist,setdiff(ftem_,cadr arglist)))$
   err_catch_gb(psys)$ % groeb_solve='REDUCE
  >>$

  if print_ then <<
   terpri()$
   if groeb_solve = 'DiffElim                        then 
   write"A differential Groebner basis computation " else 
   write"An algebraic Groebner basis computation "
  >>$
  return
  if null sol or (sol={'list,nil}) then <<
    if print_ then <<write"was not successful."$terpri()>>$
    nil
  >>                               else
  if (sol={'list,{'list,1}}) or 
     (sol={'list,{'list,(1 . 1)}}) then <<
    if print_ then write"yields a contradiction."$
    contradiction_:=t$
    nil
  >>                               else <<
    % We replace all equations. An alternative would be only to add those 
    % resulting equations for which all functions of flin_ are still linear.
    if null kept_pdes then <<
      drop_all_pdes(pdes)$
      pdes:=nil
    >>$
    sol:=cdr sol;
    if null cdr sol then << % only one solution
      sol:=cdar sol;        % a lisp list of necessarily vanishing expressions
      if print_ then <<
        terpri()$
        write"yields a single new system of conditions."$
        terpri()$
        if null kept_pdes then write"All previous equations are dropped."
                          else write"New equations are added."$
        terpri()$
        write"The new equations are:"$
      >>$
      if groeb_solve = 'DiffElim then % call_diffelim
      pdes:=mkeqSQlist(sol,nil,nil,ftem_,vl_,allflags_,t,
                       list(0),nil)
                 else % algebraic system
      pdes:=mkeqSQlist(nil,nil,sol,ftem_,vl_,allflags_,t,
                       list(0),nil)$

      % take those functions out of flin_ which are 
      % not occuring linearly everywhere anymore
      if flin_ and null lin_problem then <<
       for each p in pdes do 
       if null get(p,'linear_) then
       for each h1 in get(p,'fcts) do 
       if member(h1,flin_) and
	  (null lin_check_SQ(((first_term_SF numr get(p,'sqval)) . 1),{h1}) or
	   null lin_check_SQ(get(p,'sqval),{h1})) then
       flin_:=delete(h1,flin_)
      >>$

      for each p in kept_pdes do pdes:=eqinsert(p,pdes);
      listprint(pdes)$
      if contradiction_ then nil 
                        else {pdes,cadr arglist}
    >>              else << % more than one solution
      if print_ then <<
        terpri()$
        write length sol,"yields cases. All previous equations are dropped."$
      >>$
      n:=0$
      forg:=cadr arglist$
      backup_to_file(pdes,forg,nil)$  % with all pdes deleted
      while sol do <<
        n:=n+1$
        start_level(n,for each l1 in cdar sol collect {'equal,0,reval l1})$ 
                      % "A case of a Groebner computation"
%#        level_:=cons(n,level_)$
        if print_ then <<
%#          print_level(t)$
          terpri()$write "CRACK is now called with a case resulting "$
          terpri()$write "from a Groebner Basis computation : "
        >>;
        % further necessary step to call crackmain():
        recycle_fcts:=nil$  % such that functions generated in the sub-call 
                            % will not clash with existing functions
        if groeb_solve = 'DiffElim then % call_diffelim
        pdes:=mkeqSQlist(nil,nil,cdar sol,ftem_,vl_,allflags_,t,
                         list(0),nil)
                                   else % algebraic problem
        pdes:=mkeqSQlist(nil,nil,cdar sol,ftem_,vl_,allflags_,t,
                         list(0),nil)$

        % take those functions out of flin_ which are 
        % not occuring linearly everywhere anymore
        if flin_ and null lin_problem then <<
         for each p in pdes do 
         if null get(p,'linear_) then
         for each h1 in get(p,'fcts) do 
         if member(h1,flin_) and
	    (null lin_check_SQ(((first_term_SF numr get(p,'sqval)) . 1),{h1}) or
	     null lin_check_SQ(get(p,'sqval),{h1})) then
         flin_:=delete(h1,flin_)
        >>$

        sol:=cdr sol;
        l1:=crackmain_if_possible_remote(pdes,forg)$
        if l1 and not contradiction_ then result:=merge_crack_returns(l1,result);
        contradiction_:=nil$ 
        if sol then <<
          l1:=restore_backup_from_file(pdes,forg,nil)$
          pdes:=car l1;  forg:=cadr l1;
        >>
      >>;
      delete_backup()$
      list result
    >>
  >>
end$

endmodule$

%**********************************************************************
module Faugere$
%**********************************************************************
%  Interface subroutines to the F4 package of J P Faugere
%  Author: Winfried Neun, May 2003 

fluid '(!*gb_fileout !*gb_filein)$

algebraic procedure call_gb (vars,polys,oder)$
begin scalar ll,xx,chnout,filein, fileout,ofl!*bak;
 lisp <<filein := !*gb_filein  or if filep ("/tmp")                     then 
                  bldmsg("%w%w",  "/tmp/gb_a1_",level_string(session_)) else 
                  bldmsg("%w%w","%temp%\gb_a1_",level_string(session_));
	fileout:= !*gb_fileout or if filep ("/tmp")                     then 
                  bldmsg("%w%w","/tmp/gb_a2_",level_string(session_))   else 
                  bldmsg("%w%w","%temp%\gb_a2_",level_string(session_));
	if not listp vars or 
           not listp polys then return 
        rederr("Vars and Polys must be lists",t,t);
        %<<
        % write "Vars and Polys must be lists";
        % rederr("Stop due to error.")
        %>>;
	chnout := open(filein,'output);
        ofl!*bak:=ofl!*$
        ofl!*:=filein$  % any value neq nil, to avoid problem with redfront
        chnout := wrs chnout >>;

 ll := linelength 10000000;
 gb_vars vars;
 gb_polys polys;
 lisp  <<ofl!*:=ofl!*bak;close wrs chnout>>$
 linelength ll;

 if oder = lex then lisp (xx := system bldmsg
 ("/home/neun/gb/serveur__DMP__Lexp__INT -read %w > %w",filein,fileout))  % <-- on SHARCNET
% ("/usr/local/gb/serveur__DMP__Lexp__INT -read %w > %w",filein,fileout))  % <-- on Brock beowulf,...
               else 
 if oder=revgradlex then lisp (xx := system bldmsg
 ("/home/neun/gb/serveur__DMP__Dexp__INT -read %w > %w",filein,fileout))  % <-- on SHARCNET
% ("/usr/local/gb/serveur__DMP__Dexp__INT -read %w > %w",filein,fileout))  % <-- on Brock beowulf,...
                    else lisp 
 rederr("Unknown Order in call_gb",t,t)$
 %<<
 % write"Unknown Order in call_gb";terpri()$
 % rederr("Stop due to error.")
 %>>$

 return if xx = 0 then read_bg_output (fileout) 
                  else rederr(xx,t,t)
%<<write "Call of GB returns error: ",xx$rederr xx >>
end$
        
algebraic procedure read_bg_output (file)$
begin scalar xx,chn,chnout,filenam,!*echo,ofl!*bak;
 lisp <<filenam := if filep("/tmp")                                 then 
        bldmsg("%w%w",   "/tmp/gb_hihihi_",level_string(session_))  else 
        bldmsg("%w%w","%tTEMP%\gb_hihihi_",level_string(session_));
        off echo;
	chn := open(file,'input);
        chn := rds chn; 
        while (xx := read()) neq 'output!: do nil;
   % Found Output!:
        readch(); readch();
        chnout := open (filenam,'output);
        ofl!*bak:=ofl!*$
        ofl!*:=filenam$  % any value neq nil, to avoid problem with redfront
        chnout := wrs chnout;
        prin2 "algebraic << gb_result :={"; terpri();
        while (xx := readch()) neq '!] do
		<< writechar xx>>;
        prin2 "} >> $ END;"; terpri();
        ofl!*:=ofl!*bak$
        close wrs chnout;
        close rds chn;
      >>;
 lisp << !*uncached := t; infile filenam >>$
 return gb_result;
end$

algebraic procedure gb_vars(li)$
lisp <<
 li := foreach ll in li join {'!, , ll};
 myprin2l (("#vars [" . cdddr li)," ");
 prin2 "]";
 terpri()>>$

algebraic procedure gb_polys(li)$
begin scalar !*nat;
 lisp <<
  li := foreach ll in li join {'!, , ll};
  prin2 "#list [" ;
  foreach ll in cdddr li do <<maprin ll; terpri()>>;  %#?#
  prin2 "]";
  terpri()
 >>;
 return nil;
end$

endmodule$

%**********************************************************************
module singular$
%**********************************************************************
%  Interface subroutines to the package Singular
%  Author: Winfried Neun, October 2003 

fluid '(!*singular_fileout !*singular_filein sublis_list)$
put('call_singular,'psopfn,'call_sing)$

symbolic procedure call_sing(vars,polys,oder)$
begin scalar ll,xx,chnout,filein,fileout,ofl!*bak,cpu,gc,p$

 vars:='list . vars$
 polys:=cons('list,for each p in polys collect(reval {'!*sq,get(p,'sqval),t}));

 filein := !*singular_filein  or if filep ("/tmp")                 then 
       bldmsg("%w%w",  "/tmp/singular_a1_",level_string(session_)) else 
       bldmsg("%w%w","%temp%\singular_a1_",level_string(session_));
 fileout:= !*singular_fileout or if filep ("/tmp")                 then 
       bldmsg("%w%w",  "/tmp/singular_a2_",level_string(session_)) else 
       bldmsg("%w%w","%temp%\singular_a2_",level_string(session_));
% if not listp vars or 
%    not listp polys then return rederr("Stop due to error.",t,t)$
 ll:=linelength 10000000$
 chnout := open(filein,'output);
 ofl!*bak:=ofl!*$
 ofl!*:=filein$  % any value neq nil, to avoid problem with redfront
 chnout := wrs chnout$

 singular_vars (vars,oder,polys);
 singular_polys polys;

 linelength ll;

 % options/flags:
 prin2 "short=0;" ;
 prin2 "   option(redSB); " ;
 % prin2 "   option(redTail); ";
 prin2 "   option(prot); ";

 % alternative calls:
 % prin2 "   std(idee); ";
 % prin2 "   groebner(idee); ";
 % prin2 "   facstd(idee); ";  % <-- generates cases, output is like:
          %  [1]:
          %     _[1]=...
          %     _[2]=...
          %     ...
          %  [2]:
          %     _[1]=...
          %     _[2]=...
          %     ...
          % READING of SUCH A result is currently not supported.

 % Some of the following 20 lines are marked <--- old and <--- new .
 % The new version is writing to stdout the comments and the progress
 % report generated from   option(prot);   and into the file fileout
 % the result, but as a single string with comma separated expressions
 % which can currently not be read by the procedure read_singular_output().

 prin2 "   slimgb(idee); ";          % <--- old

 % prin2 "   write("":w ";           % <--- new
 % prin2 fileout;                    % <--- new
 % prin2 """,slimgb(idee)); ";       % <--- new
 prin2 "   quit; ";
  
 ofl!*:=ofl!*bak$ close wrs chnout$
 if print_ then <<
  write"Start of the Singular computation, time limit: ",singular_time," sec."$
  terpri()
 >>$
 cpu:=time()$ gc:=gctime()$
 xx := system bldmsg
       ("cd %w; %w < %w > %w",singular_lib,singular_call,filein,fileout);    % <--- old
 system bldmsg ("mv %w %w_1;  sed 's/_\[/%%\[/g' %w_1 >  %w",
                fileout,fileout,fileout,fileout);
 if print_ then <<
  write"The Singular computation finished."$terpri()$
  write"Time: ",time()-cpu," ms,  GC: ",gctime()-gc," ms"$ terpri()
 >>$ 
 return if xx = 0 then {'list,algebraic(read_singular_output (fileout))} else nil

end$

fluid '(sing_minpoly_sing)$

symbolic procedure singular_vars(li,oder,polys)$
begin scalar minpoly, !*nat, li2,h1,h2,h3,flin_bak$
 sublis_list:= nil;
 if smember('i , cdr polys) then 
 polys := 'i . setdiff(gvarlis(cdr polys),li)          
   else 
 polys := setdiff(gvarlis(cdr polys),li);    
 li := foreach ll in li join {'!, , ll};
 li2 := intern bldmsg("system(""alarm"",%d);",singular_time);
 prin2 li2; terpri();
 li2:=nil;

 if polys then << % params presents

  prin2 "ring rng=(0";
  foreach pa in polys do <<
   if eqcar(pa,'sqrt) then <<
    li2 := intern bldmsg("wurz%d",cadr pa) . li2;
    sublis_list :=  ((  pa . intern bldmsg("wurz%d",cadr pa)) . sublis_list);
    minpoly := cons (list ('difference , cadr pa,
		 list('expt , intern bldmsg("wurz%d",cadr pa), 2)) ,minpoly );
   >>                 else   
   if pa = 'i then <<  li2 :=  'complex_i .  li2;
    sublis_list :=  (  pa . 'complex_i) . sublis_list;
    minpoly := cons( list ('plus, 1 , '(expt complex_i 2)) , minpoly) 
   >>         else << % parameters
    prin2 " , "; 
    prin2 pa 
   >>
  >>;

  prin2 ") , ( ";

  % newly introduced variables have highest priority
  foreach lll in li2 do << prin2 lll ; prin2 " , ";>>;

  % the 'normal' variables
  prin2  cdddr li; terpri()$
  prin2 "),"; 

 >>             else <<
  prin2 "ring rng=(0),"$ prin2 cdddr li; prin2 ","$
 >>$

 h1:=fctlength car ftem_;
 h2:=fctlength car reverse ftem_;
 if h1 neq h2 then <<
  flin_bak:=flin_; flin_:=nil;
  h3:=ftem_;
  while h3 and (fctlength car h3 = h1) do <<
   flin_:=cons(car h3,flin_); h3:=cdr h3
  >>;
  flin_:=reverse flin_
 >>$

 % determination and printing of the ordering
 if li2 or (flin_ and (length flin_ neq length ftem_)) then <<   

  % a product ordering is necessary
  prin2 "("$ 

  % new variables (complex_i, wurz..) just defined
  if li2 then prin2 bldmsg("dp(%w),",length li2);

  % ftem_ variables with flin_ variables coming first
  oder := 
  if oder = 'lex then bldmsg("lp(%w)",length ftem_) else 
  if oder = 'revgradlex then 
  if flin_ then bldmsg("dp(%w),dp(%w)",length flin_,
                       length ftem_ - length flin_)
           else bldmsg("dp(%w)",length ftem_)
                        else 
  if oder = 'gradlex then 
  if flin_ then bldmsg("!Dp(%w),!Dp(%w)",length flin_,
                       length ftem_ - length flin_)
           else '!Dp
                     else rederr("Unknown Order in call_singular",t,t)$
  %<<
  % write"Unknown Order in call_singular";terpri()$
  % rederr("Stop due to error.")
  %>>$

  prin2 oder; 

  prin2 ")"$  % a product ordering was necessary
 >>                     else <<  % no product ordering
  oder := 
  if oder = 'lex        then 'lp else
  if oder = 'revgradlex then 'dp else
  if oder = 'gradlex    then '!Dp
                        else rederr("Unknown Order in call_singular",t,t)$
  %<<
  % write"Unknown Order in call_singular";terpri()$
  % rederr("Stop due to error.")
  %>>$

  prin2 oder; 
 >>$

 if h1 neq h2 then flin_:=flin_bak;

 % completing the ring definition
 prin2 ";";

% if not (minpoly = '(1)) then <<
%                prin2 "minpoly = "; 
%		maprin reval ('times . minpoly);
%          prin2 ";" >>;
  
 terpri();
 sing_minpoly_sing := minpoly;

end$


symbolic procedure singular_polys(li)$
begin scalar !*nat;
 li := foreach ll in li join {'!, , sublis(sublis_list,ll)};
 prin2 "ideal idee = " ;
 foreach ll in cdddr li do <<maprin ll; terpri()>>;     %#?#
  li := foreach ll in  sing_minpoly_sing join {'!, , ll };
   foreach ll in li  do <<maprin ll; terpri()>>;
 prin2 ";";
 terpri();
 return nil;
end$


algebraic procedure read_singular_output (file)$           
begin scalar xx,chn,chnout,filenam,ofl!*bak$
 lisp << 
  filenam := if filep("/tmp")                                               then
             bldmsg("%w%w", "/tmp/singular_helpus_",level_string(session_)) else
             bldmsg("%w%w","%tTEMP%\singular_helpus_",level_string(session_));
  chn := open(file,'input);
  chn := rds chn;
  off echo;
  while (xx := readch()) neq '!% do nil;
   % Found Output!:
  read();readch();
  chnout := open (filenam,'output);
  ofl!*bak:=ofl!*$
  ofl!*:=filenam$  % any value neq nil, to avoid problem with redfront
  chnout := wrs chnout;
  prin2 "algebraic << singular_result :={"; terpri();
  while (((xx := readch()) neq !$eof!$) and (xx neq '!>)) do
% output is    _[nn]= etc and %[nn] after sed to allow for _ in names
  << if xx = '!% then <<read(); readch(); xx :='!,>>; tyo id2int xx >>;
  prin2 "} >> $ END;"; terpri();
  on echo;
  ofl!*:=ofl!*bak$
  close wrs chnout;
  close rds chn;
 >>;
 system lisp
 bldmsg("%w%w%w%w%w","cp /tmp/singular_helpus_",level_string(session_),
               " /tmp/singular_help_",level_string(session_),";");
 system lisp
 bldmsg("%w%w%w%w%w%w",
        "sed -e 's/auf wiedersehen\.//g' -e 's/wurz\([0-9]*\)/sqrt(\1)/g' ",
        " -e 's/complex_i/i/g' ",
        "/tmp/singular_help_",
% bldmsg("%w%w%w%w","sed -e 's/auf wiedersehen\.//g' /tmp/singular_help_",
        level_string(session_)," > /tmp/singular_helpus_",
        level_string(session_));
 lisp << !*uncached := t; infile filenam >>$
 return singular_result   
end$
                                                                                
                                                                                
endmodule$

end$

% tr comp_groebner_basis
% tr call_gb
% tr read_bg_output
% tr gb_vars
% tr gb_polys
% tr call_singular
% tr call_diffelim
% tr read_singular_output
% tr singular_vars
% tr singular_polys
