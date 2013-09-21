%********************************************************************
module utilities;

%%%%%%%%%%%%%%%%%%%%%%%%%
%  properties of pde's  %
%%%%%%%%%%%%%%%%%%%%%%%%%

%******************************************************************************
%  Routines for finding leading derivatives and others                        *
%  Author: Andreas Brand 1990 1994                                            *
%          Thomas Wolf since 1994                                             *
%******************************************************************************

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

symbolic procedure drop_dec_with(de1,de2,rl);
% drop de1 from the 'dec_with or 'dec_with_rl list of de2
% currently for all orderings
begin scalar a,b,c;
  a:=if rl then get(de2,'dec_with_rl)
           else get(de2,'dec_with);
  for each b in a do << % for each ordering b
    b:=delete(de1,b);
    if length b>1 then c:=cons(b,c);
  >>;
  if rl then put(de2,'dec_with_rl,c)
        else put(de2,'dec_with   ,c)
end;

symbolic procedure add_dec_with(ordering,de1,de2,rl);
% add (ordering de1) to 'dec_with or 'dec_with_rl of de2
begin scalar a,b;
  a:=if rl then get(de2,'dec_with_rl)
           else get(de2,'dec_with);
  b:=assoc(ordering,a);
  a:=delete(b,a);
  if b then b:=cons(ordering,cons(de1,cdr b))
       else b:=list(ordering,de1);
  if rl then put(de2,'dec_with_rl,cons(b,a))
        else put(de2,'dec_with   ,cons(b,a));
end;

symbolic procedure add_both_dec_with(ordering,de1,de2,rl);
% add (ordering de1) to 'dec_with or 'dec_with_rl of de2  and
% add (ordering de2) to 'dec_with or 'dec_with_rl of de1
begin
  add_dec_with(ordering,de1,de2,rl);
  add_dec_with(ordering,de2,de1,rl);
end;

symbolic procedure drop_rl_with(de1,de2);
% drop de1 from the 'rl_with list of de2
put(de2,'rl_with,delete(de1,get(de2,'rl_with)));

symbolic procedure add_rl_with(de1,de2);
% add de1 to 'rl_with of de2 and vice versa
<<put(de2,'rl_with,cons(de1,get(de2,'rl_with)));
  put(de1,'rl_with,cons(de2,get(de1,'rl_with)))>>;

symbolic procedure prevent_simp(v,de1,de2);
% it is df(de1,v) = de2
% add dec_with such that de2
% will not be simplified to 0=0
begin scalar a,b;
  % a:=get(de1,'fcts);
  a:=list(0);   % all orderings for which de1 is used (-->ord)
  for each b in a do if member(v,fctargs(b)) then
  <<add_dec_with(b,de2,de1,nil);add_dec_with(b,de2,de1,t)>>;
  % a:=get(de2,'fcts);
  a:=list(0);   % all orderings for which de2 is used (-->ord)
  for each b in a do if member(v,fctargs(b)) then
  <<add_dec_with(b,de1,de2,nil);add_dec_with(b,de1,de2,t)>>;
end;

symbolic procedure termread;
begin scalar val,!*echo;  % Don't re-echo tty input
again:
 if not null old_history then <<
  val:=car old_history;
  if val='ig then << % ignore 'ig and following comment
   old_history:=cddr old_history;
   goto again
  >>;
  if print_ then <<write"old input: ",val$terpri()>>;
  if old_history then old_history:=cdr old_history
 >>                      else <<
%write"ipl!* 1 = ",ipl!*$terpri();
%write"ifl!* 1 = ",ifl!*$terpri();
  rds nil; wrs nil$         % Switch I/O to terminal
  val := read();
%write"ipl!* 2 = ",ipl!*$terpri();
%write"ifl!* 2 = ",ifl!*$terpri();
  if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
%write"ipl!* 3 = ",ipl!*$terpri();
%write"ifl!* 3 = ",ifl!*$terpri();
%system"sleep 10";
  if ofl!* then wrs cdr ofl!*;
 >>;
 history_:=cons(val,history_);
 return val
end;

symbolic procedure termxread;
begin scalar val, !*echo;  % Don't re-echo tty input
again:
 if not null old_history then <<
  val:=car old_history;
  if val='ig then << % ignore 'ig and following comment
   old_history:=cddr old_history;
   goto again
  >>;
  if print_ then <<write"old input: ",val$terpri()>>;
  old_history:=cdr old_history
 >>                      else <<
  rds nil; wrs nil$         % Switch I/O to terminal
  val := xread(nil);
  if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
  if ofl!* then wrs cdr ofl!*;
 >>;
% history_:=cons(compress(append(explode val,list('$))),history_);
 history_:=cons(val,history_);
 return val
end;

symbolic procedure termlistread();
begin scalar l;
  l:=termxread();
  if (not null l) and
     ((atom l) or
      (pairp l and (car l neq '!*comma!*)))
  then l:=list('!*comma!*,l);
  if l and ((not pairp l) or (car l neq '!*comma!*)) then
  <<terpri()$write"Error: not a legal list of elements.";terpri();
    l:=nil>>
  else if pairp l then l:=cdr l; % dropping '!*comma!*
  return l
end;

!#if (memq 'csl lispsystem!*)

global '(saved_prompt!*);

% [ACN] I am not sure that I understand the subtleties of what the PSL
% code here is doing, but regardless of that the messing with a function
% called update_prompt and a variable called promptstring!* will not be
% useful in CSL.

symbolic procedure change_prompt_to u;
   saved_prompt!* := setpchar u;

symbolic procedure restore_interactive_prompt;
   setpchar saved_prompt!*;

!#else

symbolic procedure change_prompt;
begin scalar !*usermode;
  if null promptstring!* then promptstring!* := "";
  setpchar promptstring!*;
  promptexp!* := promptstring!*
end;

symbolic procedure change_prompt_to u;
   begin scalar oldprompt,!*redefmsg,!*usermode;
     oldprompt := promptstring!*;
     promptstring!* := u;
     copyd('restore_update_prompt,'update_prompt);
     copyd('update_prompt,'change_prompt);
     update_prompt();
     restore_interactive_prompt();
     return oldprompt
   end;

symbolic procedure restore_interactive_prompt;
   begin scalar !*redefmsg,!*usermode;
     copyd('update_prompt,'restore_update_prompt)
   end;

!#endif

symbolic procedure restore_input_file;
% it assumes equations_file to be closed whether eqn_input=nil or not
if (equations_file="") or (eqn_input='done) or
   (null eqn_input and zerop eqn_no) then nil else
begin scalar h,oldinpu,intbak;
 intbak:=!*int$ !*int:=nil;
 eqn_input := open (equations_file,'input);
 oldinpu := rds eqn_input; % backup of old input source
 for h:=1:eqn_no do xread(t);
 rds oldinpu;
 !*int:=intbak
end;

%% currently not used and possibly even not complete:
%symbolic procedure read_ineq(arglist,ineq_file);
%% in contrast to read_equation() in this procedure the file
%begin scalar pdes,forg,oldinpu,l,ine_input,ok,ex,subli,intbak;
% pdes:=car arglist;
% forg:=cadr arglist;
%
% for each h in forg do
% if pairp h and (car h='EQUAL) then subli:=cons(h,subli);
% subli:=cons('LIST,subli);
%
% intbak:=!*int$ !*int:=nil;
% ine_input := open (ineq_file,'input);
% oldinpu := rds ine_input; % backup of old input source
%doitagain:
% ex := xread(t);
% if null ex then
% return <<
%  ex:=xread(t); % strangely needed when somewhere else out(),shut()
%  close ine_input; ine_input:='done; rds oldinpu; !*int:=intbak;
%  list(pdes,forg)
% >>;
% !*uncached:=t;
% algebraic(ex:=num sub(subli,ex));
% if pairp ex and (car ex = 'LIST) then <<
%  ex:=cdr ex;
%  l:=nil;
%  ok:=nil;
%  while ex do
%  if zerop car ex then ex:=cdr ex else
%  if freeoflist(car ex,ftem_) then <<ex:=nil; l:=nil; ok:=t>> else
%  <<l:=cons(car ex,l); ex:=cdr ex>>;
%  if l then if cdr l then ineq_or:=cons(simp l,ineq_or)
%                     else addineq(pdes,car l)
%       else if null ok then contradiction_:=t
% >>                               else addineq(pdes,ex);
%
% if contradiction_ then
% return <<close ine_input; ine_input:='done; rds oldinpu; !*int:=intbak; nil>>;
%
% goto doitagain;
%
%end;

symbolic procedure read_equation(arglist);
% This should come with a higher priority than any module which
% generates case distinctions because when continuing reading
% from the file in a subcase, one can not ga back to the old
% position in the file when completing the subcase.
begin scalar h,oldinpu,ex,pdes,forg,subli,start_no,intbak;
 if ( eqn_input='done                            ) or
    ((eqn_input=nil) and
     ((equations_file="") or null equations_file)) then return nil;

 if null eqn_input then      % necessarily equations_file neq ""
 eqn_input := open (equations_file,'input);

 pdes:=car arglist;
 forg:=cadr arglist;
 oldinpu := rds eqn_input; % backup of old input source

 for each h in forg do
% if pairp h and (car h='EQUAL) then subli:=cons(h,subli);
% subli:=cons('LIST,subli);
 if pairp h and (car h='EQUAL) then subli:=cons((cadr h . {'!*sq,caddr h,t}),subli);

 start_no:=eqn_no;
 intbak:=!*int$ !*int:=nil;
oncemore:
 ex := xread(t);
 if null ex then
 return <<
  ex:=xread(t);             % strangely needed when somewhere else out(),shut()
  close eqn_input; eqn_input:='done; rds oldinpu; !*int:=intbak;
  nil
 >>;
 eqn_no:=add1 eqn_no;
 !*uncached:=t;

 ex:=(numr subsq(simp ex,subli) . 1);
% algebraic(ex:=num sub(subli,ex));
 if contradiction_ then
 return <<close eqn_input; eqn_input:='done; rds oldinpu; !*int:=intbak; nil>>;
 if sqzerop ex then <<
  if print_ then write eqn_no," ";
  goto oncemore
 >>          else <<
  ex:=mkeqSQ(ex,nil,nil,ftem_,vl_,allflags_,t,list(0),nil,pdes);
  h:=eqinsert2(ex,pdes);
  if null h then <<
   if null car recycle_eqns then
   recycle_eqns:=(list cadr recycle_eqns) . (cddr recycle_eqns);
   if print_ then write " (",eqn_no,")";
   goto oncemore
  >>        else <<
   pdes:=h;
   if print_ then <<terpri()$write"Reading ",eqn_no,".equation. ">>
  >>
 >>;
 rds oldinpu;
 !*int:=intbak;
 return list(pdes,forg)
end;

symbolic procedure mkeqSQlist(sqvallist,faclist,pvallist,ftem,vl,flaglist,
                              simp_flag,orderl,pdes);
%  makes a list of equations, currently uses either sqvallist or pvallist
%    sqvallist: list of expressions in sq-form (no prefix sq) or nil
%    faclist:   list of expressions each as list of factors each in sq-form
%    pvallist:  list of expressions in prefix form or nil
%    ftem:      list of functions
%    vl:        list of variables
%    flaglist:  list of flags
%    orderl:    list of orderings where the equations are valid
%    pdes:      list of all equations by name to update inequalities
%                       within updateSQ()
begin scalar l0,l1;
 while (sqvallist or faclist or pvallist) and null contradiction_ do <<
  l0:=mkeqSQ(if sqvallist then car sqvallist else nil,
             if   faclist then car   faclist else nil,
             if  pvallist then car  pvallist else nil,
             ftem,vl,flaglist,simp_flag,orderl,nil,append(l1,pdes));
  if l0 then l1:=eqinsert(l0,l1);
  if sqvallist then sqvallist:=cdr sqvallist;
  if   faclist then   faclist:=cdr   faclist;
  if  pvallist then  pvallist:=cdr  pvallist
 >>;

 return l1
end;

symbolic procedure mkeqSQ(sqval,fac,pval,ftem,vl,flaglist,simp_flag,
                          orderl,hist,pdes);
%  makes a single new equation
%    sqval:    expression in sq-form (see header of updateSQ() )
%    fac:      list of factors in sq-form
%    pval:     expression in prefix-form
%    ftem:     list of functions
%    vl:       list of variables
%    flaglist: list of flags
%    orderl:   list of orderings where the equation is valid
%    hist:     the history of sqval
%    pdes:     list of all equations by name to update inequalities
%              within updateSQ()
%  If the new equation to be made is only to exist temporarily then
%  call mkeqSQ with pdes=nil to avoid lasting effects of the temporary pde.
%
if (sqval and not sqzerop sqval) or fac or not zerop pval then
begin scalar s;
 s:=new_pde();
 if record_hist and hist then put(s,'histry_,reval hist);
 for each a in flaglist do flag1(s,a);
 if not updateSQ(s,sqval,fac,pval,ftem,vl,simp_flag,orderl,pdes) then
 <<drop_pde(s,nil,nil);
   s:=nil>>;
 if record_hist and null hist and s then put(s,'histry_,s);
 return s
end;

symbolic procedure no_of_derivs(equ);
if alg_poly then 0 else
begin scalar h,dl;
 h:=0;
 dl:=get(equ,'derivs);
 while dl do <<
  if (pairp caar dl) and (cdaar dl) then h:=add1 h;
  dl:=cdr dl
 >>;
 return h
end;

symbolic procedure updateSQ(equ,sqval,fac,pval,ftem,vl,simp_flag,orderl,pdes);
% determine the properties of a pde
%   equ:      pde name
%   sqval:    expression in SQ form (preferred) or nil
%   fac:      list of factors in SQ form (2nd best) or nil
%   pval:     expression in prefix form or nil
%             At leastone of the 3 must be neq nil. What are definitely
%             stored are 'sqval and 'fac. 'pval only if input pval is neq nil
%             and if simp_flag=nil .
%   ftem:     list of functions
%   vl:       list of variables
%   orderl:   list of orderings where the equation is valid
%   pdes:     needed in call of addineq at end, has global effects
%
% *** important ***:
% If this is now a new equation one may have to call before:
%    for each h1 in allflags_ do flag1(p,h1);
% and definitely have to call afterwards:
%    drop_pde_from_idties(p,pdes,if record_hist then new_history_in_prefix_form
%                                               else nil) and
%    drop_pde_from_properties()
% ### or should this be included into updateSQ()?  YES
%
% This procedure can produce contradiction_:=t
% --> value of contradiction_ is to be tested afterwards.
%
% If the value is zero then nil is returned and then the equations
% should be dropped from pdes (the list of equations).
%
% This procedure can effect the whole system through changing ineq_ or ineq_or.
% For a definition of properties see crinit.red .
%
% If sqval=nil and null cdr fac (fac has only one factor) then it is assumed
% that it is known for sure that the elements of fs do not factorize,
% as tested with err_catch_fac2().
%
begin scalar l,h,nvars,rational,nonrational,allvarfcts,droped_factors,carl,rati;
  % safety precaution:
  if pairp sqval and car sqval = '!*sq then
  if caddr sqval = t then sqval:=cadr   sqval
                     else sqval:=simp!* sqval
                                       else if sqval then sqval:=subs2 sqval;

  % For now we will always generate the SQ form and try to get away with
  % not generating the prefix form if it does not already exist. Maybe we
  % will have to generate the prefix form always, hopefully not.

  % Should a check for simplification rules be done here ###
  % because it is currently not done in simplifySQ() ?
  % Or, should it be done in simplifySQ()?
  % ruli:=start_let_rules();
  % g:=reval g$  % if reval aeval is needed then inform A. Hearn
  % % g:=doedel3 g;
  % stop_let_rules(ruli);
  put(equ,'terms,nil);
  put(equ,'sqval,nil)$  % maybe not necessary, but safe
  put(equ,'fac  ,nil)$  % maybe not necessary, but safe
  put(equ,'pval ,nil)$  % necessary as this is sometimes not nil
  if null sqval then
  if null fac then <<sqval:=simp!* pval; put(equ,'fac,nil)>>
              else <<
   if null cdr fac then << % known to have only one factor
    put(equ,'fac,2);
    sqval:=subs2 car fac
   >>              else << % more factors
    % put(equ,'fac,fac);
    put(equ,'fac,nil);
    % We throw away the knowledge of factors only because currently we have no
    % way to remember that these factors are themselves not fully factorized
    sqval:=car fac; fac:=cdr fac;
    while fac do <<sqval:=multsq(sqval,car fac);fac:=cdr fac>>;
    sqval:=subs2 sqval;
    fac:=get(equ,'fac)
   >>
  >>;
  if sqval and not sqzerop sqval then <<
   if null simp_flag and (null fac or null cdr fac) then <<

    % If there are factors then they have to be simplified to be
    % be identified and dropped later, in case this factor (in
    % simplified form) should appear later to be non-zero.

    if member(sqval,ineq_) then raise_contradiction({'!*sq,sqval,t},nil);
    if null fac then <<
     put(equ,'terms,no_of_tm_sf numr sqval);
     if (null !*complex and (get(equ,'terms) > max_term_to_fac_real   )) or
        (     !*complex and (get(equ,'terms) > max_term_to_fac_complex))
     then l:=sffac numr sqval
     else <<
      h:=cdr err_catch_fac2 {'!*SQ,(numr sqval . 1),t};
      l:=nil;
      if cdr h or (caddar h>1) then
      while h do <<
       if null domainp numr simp cadar h then <<
	if caddar h > 1 then droped_factors:=t;
	l:=cons(numr cadr cadar h,l)  % cadr instead of simp as it is no number
       >>;
       h:=cdr h
      >>
      % if l and null cdr l then a number factor has been dropped
      % and one might want to change sqval but if simp_flag=nil then
      % it is assumed that sqval shall not be changed (e.g. to admit some
      % special solution of integrating procedure
     >>;
     if l and cdr l
     then put(equ,'fac,for each h in l collect (h . 1))
     else put(equ,'fac,
            if (null !*complex and (get(equ,'terms) > max_term_to_fac_real   )) or
               (     !*complex and (get(equ,'terms) > max_term_to_fac_complex))
            then 1
            else 2)
    >>;
    if pval and null droped_factors then put(equ,'pval,pval)
   >>                else <<
    if null ftem then ftem:=ftem_; % for safety, just in case
    if null fac then l:=simplifySQ(sqval,ftem,t,equ,nil)
                else <<l:=nil;
                       for each f in fac do <<
                         h:=simplifySQ(f,ftem,t,equ,nil);
                         if h neq {(1 . 1)} then l:=union(h,l)
                       >>;
                       if null l then l:={(1 . 1)}
                     >>;
    if l={(1 . 1)} then raise_contradiction({'!*sq,sqval,t},nil);
    sqval:=car l;
    if null cdr l then   put(equ,'fac,1)
                  else <<put(equ,'fac,l);
     % Maybe one could save the effort of having to compute the product? ###
     % A possibility would be to store only 'sqval as list of factors
     % and not have 'fac.
     l:=cdr l;
     while l do <<sqval:=multsq(sqval,car l);l:=cdr l>>
    >>;
    put(equ,'terms,no_of_tm_sf numr sqval);
   >>
  >>;
  depl!*:=delete(assoc(reval equ,depl!*),depl!*);

  if null contradiction_ then
  if null sqval or sqzerop sqval then return nil
                                 else <<
   put(equ,'sqval,sqval);
   put(equ,'kern,union(kernels denr sqval,
                       kernels numr sqval ));
   l:=nil;
   for each v in get(equ,'kern) do
   if pairp v and (car v neq 'DF) and
      member(car v,reducefunctions_) then l:=cons(v,l);
   put(equ,'non_rat_kern,l);
   put(equ,'fct_kern_lin,nil); % determined in add_fct_kern() crshort.red if
   put(equ,'fct_kern_nli,nil); % needed, see def. of prop_list in crinit.red
   ftem:=sort_according_to(smemberl(ftem,get(equ,'kern)),ftem_);
   put(equ,'fcts,ftem);
   put(equ,'fct_hom,smemberl(ftem,fhom_));
   l:=nil;
   for each v in vl do
   if not my_freeof(get(equ,'kern),v) then l:=cons(v,l);
   vl:=sort_according_to(l,vl_);
   put(equ,'vars,vl);
   if null vl then remflag1(equ,'to_diff);
   if vl then
   depl!*:=cons(cons(equ,vl),depl!*)$ % needed in expressions in idnties_
   put(equ,'nvars,length vl);
   put(equ,'level,level_);
   put(equ,'derivs,sort_derivs(if pairp denr sqval then
	             	       union(all_deriv_search_SF(denr sqval,ftem),
				     all_deriv_search_SF(numr sqval,ftem) )
                                                   else
			       all_deriv_search_SF(numr sqval,ftem),ftem,vl));
   if struc_eqn then put(equ,'no_derivs,no_of_derivs(equ));
   put(equ,'fcteval_lin,nil);
   put(equ,'fcteval_nca,nil);
   put(equ,'fcteval_nli,nil);
   put(equ,'fcteval_n2l,nil);
   put(equ,'fct_nli_lin,nil);
   put(equ,'fct_nli_nca,nil);
   put(equ,'fct_nli_nli,nil);
   put(equ,'fct_nli_nus,nil);
   if null get(equ,'terms) then put(equ,'terms,no_of_tm_sf numr sqval
                                            % + no_of_tm_sf denr sqval
                                   );
   %put(equ,'length,pdeweightSF(numr sqval,ftem)+pdeweightSF(denr sqval,ftem));
   put(equ,'length,get(equ,'terms));
   put(equ,'printlength,delengthSQ sqval);
   put(equ,'orderings,orderl)$	% Orderings !

   % rationality test:
   nvars:=get(equ,'nvars);

   if alg_poly then <<
    rational:=ftem;
    nonrational:=nil;
    allvarfcts:=ftem
   >>          else <<
    % make a new copy of ftem
    for each f in reverse ftem do rational:=cons(f,rational);
    rati:=cons(1,rational);
    nonrational:=nil;
    allvarfcts:=nil;
    l:=get(equ,'kern);
    while l do <<
     carl:=car l$ l:=cdr l;
     if atom carl               or
        ((pairp carl    ) and
         (car carl = 'DF) and
         (atom cadr carl)     ) then t else <<
      % Move all functions from rational to non-rational which occur in carl.
      h:=rati;
      while cdr h do
      if not freeof(carl,cadr h) then <<
       % Move cadr h from rational to nonrational:
       nonrational:=cons(cadr h,nonrational);
       h:=rplacd(h,cddr h)
      >>                         else h:=cdr h
     >>
    >>;
    nonrational:=reverse nonrational;
    if nvars=0 then allvarfcts:=rational else
    for each f in reverse rational do
    if fctlength f=nvars then allvarfcts :=cons(f,allvarfcts);

    % The following test for non-polynomiality is not adequate.
    % For example, {'expt,'x,4} would be recognized as polynomial
    % but the kernel would not be an atom or the derivative of an
    % atom that could be decoupled in crdec.red .
    %if l then <<
    % if cdr l then l:=cons('PLUS,l)
    %          else l:=car l;
    % for each f in reverse ftem do
    % if polynop(l,f) then <<
    %  rational:=cons(f,rational);
    %  if fctlength f=nvars then allvarfcts :=cons(f,allvarfcts)
    % >>            else nonrational:=cons(f,nonrational)
    %>>;

   >>;

   for each l in nonrational do rational:=delete(l,rational);

   put(equ,'rational,rational);
   put(equ,'nonrational,nonrational);
   put(equ,'allvarfcts,allvarfcts);

%  put(equ,'degrees,          % too expensive
%   if linear_pr then cons(1,for each l in get(equ,'rational)
%                            collect (l . 1))
%                else fct_degrees(pval,get(equ,'rational))    );
   put(equ,'partitioned,nil);
   put(equ,'case2sep,nil);
   l:=stardep3(get(equ,'vars),get(equ,'kern),get(equ,'derivs));
   if l then <<
    h:=cdr l;
    l:=simp car l;
    if member(l,ineq_) then   put(equ,'starde,({prepsq l} . 0))
                       else <<put(equ,'case2sep,diffsq(l,h));
                              put(equ,'starde,stardep(ftem,vl))>>
   >>   else put(equ,'starde,stardep(ftem,vl));
   flag1(equ,'to_eval);
   if (l:=get(equ,'starde)) then <<
    %remflag1(equ,'to_eval);
    remflag1(equ,'to_int);
    remflag1(equ,'to_fullint);
    if simp_flag and
       (zerop cdr l) then <<flag1(equ,'to_sep)$ flag1(equ,'to_casesep)>>;
    % remflag1(equ,'to_diff)
   >>                       else remflag1(equ,'to_gensep);
   if get(equ,'starde) and
      (zerop cdr get(equ,'starde)) % or (get(equ,'length)<=gensep_))
      then
      else <<remflag1(equ,'to_sep)$ remflag1(equ,'to_casesep)>>;
   if get(equ,'nonrational) then <<%remflag1(equ,'to_decoup);
    if null setdiff(get(equ,'allvarfcts),get(equ,'nonrational)) then
       remflag1(equ,'to_eval)
   >>;
   if (not get(equ,'rational)) or
      ((l:=get(equ,'starde)) and (cdr l = 0)) then remflag1(equ,'to_eval);
   if fhom_ then <<
    l:=find_hom_deg_SF numr sqval;
    put(equ,'hom_deg,l);
%   if car l=1 then << % i.e. linear in flin_
%    l:=get(equ,'derivs);
%    while l and (null linf or (length linf < 3)) do <<
%     if not freeoflist(car l,flin_) then <<
%      linf:=cons(car l,linf);
%      if member(car l,ineq_) then fd1:=car l
%     >>;
%     l:=cdr l
%    >>;
%    if linf and (length linf = 2) and fd1 then <<
%     if NON-ZERO(coeffn(get(equ,'pval),fd1,1)) then <<
%      fd2:=car delete(fd1,linf);
%  braucht pdes, was nicht vorhanden ist
%      addineq(pdes,fd2);
%      addineq(pdes,coeffn(get(equ,'pval),fd2,1))
%     >>
%    >>
%   >>
   >>;
   put(equ,'split_test,nil);
   put(equ,'linear_,
       if nonrational then nil else
       if lin_problem then t else
       if not freeof(denr sqval,ftem) then nil else
       if lin_check_SQ(((first_term_SF numr sqval) . 1),ftem) then
       if lin_check_SQ(sqval,ftem) then t else nil    else nil);
   put(equ,'not_to_eval,nil);

   % The following aims at global lasting effects, so it shall not be
   % run if equation equ is not necessary
   if pdes then <<
    new_ineq_from_equ_SQ(equ,pdes);
    if null cdr pdes then % When the first and so far only equation
                          % was established (created by updatesq)
                          % then pdes was nil before, so it was not
                          % checked before and should be checked now.
    new_ineq_from_equ_SQ(car pdes,pdes);
    if null contradiction_ then simp_all_ineq_with_equ_SQ(equ,pdes);

    % Does the new equation imply a vanishing derivative?
    h:=get(equ,'allvarfcts);
    if h and null cdr h and get(equ,'vars) and
       freeoflist(get(equ,'kern),get(equ,'vars)) then <<
     l:=if freeof(get(equ,'nonrational),car h) then get(equ,'vars)
                                               else nil;
     while l and null member(simp {'df,car h,car l},ineq_) do l:=cdr l;
     if l then <<
      if print_ then <<write"Next comes a separation of equation ",equ,
                            " wrt. ",car h$terpri()>>;
      h:=cdr algebraic(coeff(lisp {'!*sq,get(equ,'sqval),t},lisp car h));

      to_do_list:=
      cons(list('add_eqns,
                for each g in h collect if pairp g and
                                           car g = '!*SQ then cadr g
                                                         else simp g),to_do_list)
     >> else
     to_do_list:=cons(list('add_differentiated_pdes,list equ),
                      to_do_list)
    >>

 >>;

 return equ
>>;
end;

symbolic procedure add_eqns(arglist);
% The 4th element of arglist is a lisp list of standard
% quotient expressions that are to be added as equations.
% This procedure is typically called from to_do when other steps
% found expressions which necessarily vanish but these procedures
% were not able to generate new equations because they did not have
% the pdes variable or could not return it.
begin scalar pdes,eqns,q;
 pdes:=car arglist;
 eqns:=cadddr arglist;
 while eqns and null contradiction_ do <<
  if zerop car eqns then q:=nil else
  q:=mkeqSQ(car eqns,nil,nil,ftem_,vl_,allflags_,t,list(0),nil,nil)$%pdes);
  if q then pdes:=eqinsert(q,pdes);
  eqns:=cdr eqns
 >>;
 return {pdes,cadr arglist}
end;

%symbolic procedure new_ineq_from_pde(equ,pdes);
%% currently only effective for equations with 2 terms
%% If one term of the equation is non-zero then the sum of the
%% remaining terms has to be non-zero too
%if pdes and null lin_problem and (get(equ,'terms)=2) % >1)
%then begin scalar valu;
% valu:=numr get(equ,'sqval);
%% if pairp valu and car valu='QUOTIENT then valu:=cadr valu;
% if not (pairp valu and (car valu='PLUS)) then valu:=reval valu;
% if pairp valu and car valu='QUOTIENT then valu:=cadr valu;
% if not (pairp valu and (car valu='PLUS)) then <<
%  write"err in update:"$terpri();
%  write"equ=",equ$terpri();
%  write"val      =",get(equ,'val)$terpri();
%  write"reval val=",valu$terpri()
% >>                                       else
%%    for each l in cdr valu do
%%    if null may_vanish l then addineq(pdes,reval{'DIFFERENCE,valu,l})
% if null may_vanish cadr  valu then addineq(pdes,caddr valu) else
% if null may_vanish caddr valu then addineq(pdes,cadr  valu)
%end;

%symbolic procedure fct_degrees(pv,ftem)$   % if ever needed then write an
%% ftem are to be the rational functions    % SQ version like lin_check_SQ
%begin                                      % or do a search through the SQ tree
% scalar f,l,ll,h,degs;
% if den pv then pv:=num pv;
% for each f in ftem do <<
%  l:=gensym();
%  ll:=cons((f . l),ll);
%  pv:=subst({'TIMES,l,f},f,pv);
% >>;
% pv:=reval pv;
% for each l in ll do <<
%  degs:=cons((car l . deg(pv,cdr l)),degs);
% >>;
% h:=cdar ll;
% for each l in cdr ll do pv:=subst(h,cdr l,pv);
% pv:=reval pv;
% return cons(deg(pv,h),degs)
%end;

%symbolic procedure pde_degree(pv,ftem);
%% ftem are to be the rational functions
%begin
% scalar f,h;
% if den pv neq 1 then pv:=num pv;
% h:=gensym();
% for each f in ftem do pv:=subst({'TIMES,h,f},f,pv);
% pv:=reval pv;
% return deg(pv,h)
%end;

symbolic procedure pde_degree_SQ(pv,fl);
% fl must be rational functions
begin
 scalar f,sb,k;
 k:=setkorder list lin_test_const;
 sb:=for each f in fl collect (f . {'!*sq,simp {'TIMES,lin_test_const,f},t});
 pv:=subf(numr pv,sb);
 setkorder k;
 return ldeg numr pv
end;

symbolic procedure dfsubst_update(f,der,equ);
%  miniml update of some properties of a pde
%    equ:      pde
%    der:      derivative
%    f:        new function
begin scalar l;
  for each d in get(equ,'derivs) do
    if not member(cadr der,car d) then l:=cons(d,l)
                                  else <<
    l:=cons(cons(cons(f,df_int(cdar d,cddr der)),cdr d),l);
%      put(equ,'val,
%          subst(reval cons('DF,caar l),reval cons('DF,car d),
%                get(equ,'val)))>>;
    put(equ,'kern,
        subst(reval cons('DF,caar l),reval cons('DF,car d),
              get(equ,'kern)));
    put(equ,'sqval,
	subsq(get(equ,'sqval),{((reval cons('DF,car d)) . (reval cons('DF,caar l)))})
       );
  >>;
  put(equ,'fcts,sort_according_to(subst(f,cadr der,get(equ,'fcts)),ftem_));
  put(equ,'allvarfcts,sort_according_to(subst(f,cadr der,get(equ,'allvarfcts)),ftem_));
  if get(equ,'allvarfcts) then flag(list equ,'to_eval);
%  This would reactivate equations which resulted due to
%  substitution of derivative by a function.
%  8.March 98: change again: the line 3 lines above has been reactivated
  put(equ,'rational,subst(f,cadr der,get(equ,'rational)));
  put(equ,'nonrational,subst(f,cadr der,get(equ,'nonrational)));
  put(equ,'derivs,sort_derivs(l,get(equ,'fcts),get(equ,'vars)));
  return equ
end;

symbolic procedure insert_in_eqlist(s,l);
% 26.8.2009: The sorting criterium was 'length but 0=a and 0=a*b
% have both length 1 and 0=a*b may come first although having a
% higher 'printlength and thus 0=a will not be found by module 3
% to be usable for a simplifying substitution. Thus the sorting
% criteria is changed to 'printlength.
if null l then list s else
begin scalar l1,m,n,found1,found2;
 n:=get(s,'printlength);
 return
 if n<=get(car l,'printlength) then <<
  largest_fully_shortened:=nil;
  currently_to_be_substituted_in:=car l;
  cons(s,l)
 >>                            else <<
  l1:=l;
  while cdr l and (null(m:=get(cadr l,'printlength)) or (n>m)) do <<
   if null m then write"### The equation ",cadr l," has no length! ###";
   if car l=largest_fully_shortened then found1:=t;
   if car l=currently_to_be_substituted_in then found2:=t;
   l:=cdr l
  >>;
  if largest_fully_shortened and null found1 then
  largest_fully_shortened:=car l;
  if currently_to_be_substituted_in and null found2 then
  currently_to_be_substituted_in:=car l;

  rplacd(l,cons(s,cdr l));
  l1
 >>
end;

symbolic procedure eqinsert(s,l);
% l is a sorted list
if not (s or get(s,'sqval)) or zerop get(s,'length) or member(s,l) then l
else if not l then list s
else begin scalar l1$ %,n,m;
 l1:=proddel_SQ(s,l);
 if car l1 then <<
%  n:=get(s,'length);
%  l:=cadr l1;
%  l1:=nil;
%  while l and (null(m:=get(car l,'length)) or (n>m)) do
%     <<if m then l1:=cons(car l,l1)
%            else write"### The equation ",car l," has no length! ###";
%       l:=cdr l>>;
%  l1:=append(reverse l1,cons(s,l));
  l1:=insert_in_eqlist(s,cadr l1)
 >>        else if l1 then l1:=cadr l1  % or reverse of it
                      else l1:=l;
 return l1;
end;

symbolic procedure eqinsert2(s,l);
% like eqinsert, but if s is a consequence of l and l is not changed
% (because, for example, some equations of l are simplified because of
% new inequalities coming through s (e.g. if s has only 2 terms and one
% is made from only non-zero factors) and then factors are dropped and
% then some equations of l become obsolete) then nil is returned
if not (s or get(s,'sqval)) or zerop get(s,'length) or member(s,l)
then nil
else if not l then list s
              else begin scalar l1,n,found1,found2;
 l1:=proddel_SQ(s,l);
 if car l1 then <<
  n:=get(s,'length);
  l:=cadr l1;
  l1:=nil;
  while l and (n>get(car l,'length)) do
     <<l1:=cons(car l,l1);
       if car l=largest_fully_shortened then found1:=t;
       if car l=currently_to_be_substituted_in then found2:=t;
       l:=cdr l>>;

  if largest_fully_shortened and null found1 then
  largest_fully_shortened:=if null l1 then nil
                                      else car l1;
  if currently_to_be_substituted_in and null found2 then
  largest_fully_shortened:=s;

  l1:=append(reverse l1,cons(s,l));
 >>        else if not_included(l,cadr l1) then l1:=cadr l1
                                           else l1:=nil;
 return l1;
end;

symbolic procedure not_included(a,b);
% meaning: not_all_a_in_b = setdiff(a,b)
% Are all elements of a also in b? If yes then return nil else t
% This could be done with setdiff(a,b), only setdiff
% copies expressions and needs extra memory whereas here we only
% want to know one bit (included or not)
begin scalar c;
 c:=t;
 while a and c do <<
  c:=b;
  while c and ((car a) neq (car c)) do c:=cdr c;
  % if c=nil then car a is not in b
  a:=cdr a;
 >>;
 return if c then nil
             else t
end;

%symbolic procedure follows_from(p,pdes);
%% determines whether the equation p=0 follows straight forwardly from
%% the list of equation names pdes
%begin scalar p1,follows;
% if pairp p and (car p='TIMES) then p:= cdr p
%                               else p:=list p;
% while pdes do <<
%  if pairp(p1:=get(car pdes,'val)) and (car p1='TIMES) then p1:=cdr  p1
%                                                       else p1:=list p1;
%  if null not_included(p1,p) % p is a consequence of car pdes
%  then <<follows:=t; pdes:=nil>>
%  else pdes:=cdr pdes
% >>;
% return follows
%end;

symbolic procedure follows_fromSQ(pfac,pdes);
% determines whether the equation p=0 where p is a product of all elements
% of pfac follows straight forwardly from the list of equation names pdes
begin scalar p1,follows;
 while pdes do <<
  if not pairp(p1:=get(car pdes,'fac)) then p1:=list get(car pdes,'sqval);
  if null not_included(p1,pfac) % pfac is a consequence of car pdes
  then <<follows:=t; pdes:=nil>>
  else pdes:=cdr pdes
 >>;
 return follows
end;

%symbolic procedure proddel(s,l);
%% delete all pdes from l with s as factor
%% delete s if it is a consequence of any known pde from l
%begin scalar l1,l2,l3,n,lnew,pdes,s_hist;
% if pairp(lnew:=get(s,'val)) and (car lnew='TIMES) then lnew:=cdr lnew
%                                                   else lnew:=list lnew;
% n:=length lnew;
% pdes:=l;
% while l do <<
%  if pairp(l1:=get(car l,'val)) and (car l1='TIMES) then l1:=cdr  l1
%                                                    else l1:=list l1;
%  if n<length l1 then     % s has less factors than car l
%    if not_included(lnew,l1) then
%    l2:=cons(car l,l2)    % car l is not a consequ. of s
%                             else
%    <<l3:=cons(car l,l3); % car l is a consequ. of s
%      drop_pde(car l,nil,{'QUOTIENT,{'TIMES,s,get(car l,'val)},get(s,'val)})
%    >>
%  else <<
%    if null not_included(l1,lnew) then % s is a consequence of car l
%    <<if print_ then <<terpri()$write s," is a consequence of ",car l,".">>;
%      % one could stop here but continuation can still be useful
%      if null s_hist then s_hist:={'QUOTIENT,
%                                   {'TIMES,car l,get(s,'val)},
%                                   get(car l,'val)            };
%    >>;
%    % else
%    if null l3 or (car l3 neq car l) then l2:=cons(car l,l2);
%  >>;
%  l:=cdr l
% >>;
% if print_ and l3 then <<
%  listprint l3;
%  if cdr l3 then write " are consequences of ",s
%            else write " is a consequence of ",s;
%  terpri();
% >>;
% if s_hist then <<drop_pde(s,nil,s_hist);s:=nil>>;
% return list(s,reverse l2);
%end;


symbolic procedure proddel_SQ(s,l);
% delete all pdes from l with s as factor
% delete s if it is a consequence of any known pde from l
begin scalar l1,l2,l3,n,lnew,pdes,s_hist;
 if not pairp(lnew:=get(s,'fac)) then lnew:=list get(s,'sqval);
 n:=length lnew;
 pdes:=l;
 while l do <<
  if not pairp(l1:=get(car l,'fac)) then l1:=list get(car l,'sqval);
  if n<length l1 then     % s has less factors than car l
    if not_included(lnew,l1) then
    l2:=cons(car l,l2)    % car l is not a consequ. of s
                             else
    <<l3:=cons(car l,l3); % car l is a consequ. of s
      drop_pde(car l,nil,
               reval {'!*SQ,quotsq(multsq(simp s,get(car l,'sqval)),
                                   get(s,'sqval)),t})
    >>
  else <<
    if null not_included(l1,lnew) then % s is a consequence of car l
    <<if print_ then <<terpri()$write s," is a consequence of ",car l,".">>;
      % one could stop here but continuation can still be useful
      if null s_hist then
      s_hist:=quotsq(multsq(simp car l,get(s,'sqval)),get(car l,'sqval));
    >>;
    % else
    if null l3 or (car l3 neq car l) then l2:=cons(car l,l2);
  >>;
  l:=cdr l
 >>;
 if print_ and l3 then <<
  listprint l3;
  if cdr l3 then write " are consequences of ",s
            else write " is a consequence of ",s;
  terpri();
 >>;
 if s_hist then <<
 drop_pde(s,nil,reval {'!*SQ,s_hist,t});s:=nil>>;
 return list(s,reverse l2);
end;

symbolic procedure myprin2l(l,trenn);
% myprin2l(l," ") = prin2l(l)  , CSL does not have prin2l.
if l then
   <<if pairp l then
        while l do
          <<write car l;
          l:=cdr l;
          if l then write trenn>>
   else write l>>;

symbolic procedure print_stars(s);
begin scalar b,star,pv,cs;
 pv:=pairp get(s,'fac);
 cs:=get(s,'case2sep);
 star:=get(s,'starde);
 if star or pv or cs then <<
  write "(";
  if pv then write"#";
  if cs then write"!";
  if star then for b:=1:(1+cdr star) do write"*";
  write")";
 >>;
end;

symbolic procedure typeeq(s);
%  print equation
if (null print_) or (get(s,'printlength)>print_) then begin scalar a,b;
  print_stars(s);
  write " ",(a:=get(s,'terms))," terms,";
  if a neq (b:=get(s,'length)) then write" ",b," factors,";
  write" with ";
  if get(s,'vars) then write"derivatives" else write"powers: ";
  if get(s,'starde) then <<
   write": "$ terpri();
   print_derivs(s,nil);
  >>   else <<
   if get(s,'vars) then write" of functions of all variables: ";
   terpri();
   print_derivs(s,t);
  >>
end                     else
mathprint list('EQUAL,0,{'!*SQ,get(s,'sqval),t});

symbolic procedure print_derivs(p,allvarf);
begin scalar a,d,dl,avf;
 dl:=get(p,'derivs);
 if allvarf then <<
  avf:=get(p,'allvarfcts);
  for each d in dl do
  if not freeoflist(d,avf) then a:=cons(d,a);
  dl:=reverse a
 >>;
 dl:=for each d in dl collect <<
  a:=if null cdar d then caar d
                    else cons('DF,car d);
  if cdr d=1 then a else {'EXPT,a,cdr d}
 >>;
 mathprint cons('! ,dl);
 dl:=get(p,'non_rat_kern);
 if dl then mathprint cons('LIST,dl);

% write dl % hard to read
end;

symbolic procedure typeeqlist(l);
%  print equations and their property lists
<<terpri();
for each s in l do
 <<terpri();
 write s," : ";
 if not print_all then typeeq(s)
                  else
 if (null print_) or (get(s,'printlength)>print_) then
 <<write get(s,'terms)," terms"$terpri()>>        else
 mathprint list('EQUAL,0,{'!*SQ,get(s,'sqval),t});
 if print_all then <<
             write "   derivs      : ";
    terpri()$print_derivs(s,nil);
    terpri()$write "   derivs(raw) : ",get(s,'derivs);
    terpri()$write "   fac         : ";
    if pairp get(s,'fac) then <<
     terpri();
     mathprint cons('LIST,for each f in get(s,'fac) collect
                          if (null print_) or
                             (delengthSQ f > print_) then
                    bldmsg("%w%d%w"," ",no_of_tm_sf numr f," terms ")
%{'LIST,no_of_tm_sf numr f," terms"}
                                                     else {'!*SQ,f,t});
%     for each f in get(s,'fac) do
%     if (null print_) or (delengthSQ f > print_)    then
%     <<write no_of_tm_sf numr f," terms"$terpri()>> else
%     mathprint list('EQUAL,0,{'!*SQ,f,t});
    >>                   else write get(s,'fac);
    terpri()$write "   pval        : ",get(s,'pval);
%if get(s,'pval) then "assigned"
%                                                      else "not assigned";
%    terpri()$write "   sqval       : ",get(s,'sqval);
%    terpri()$write "   fac         : ",get(s,'fac);
%    terpri()$write "   pval        : ",get(s,'pval);
    terpri()$write "   partitioned : ",if get(s,'partitioned) then
                                      "not nil"              else
                                      "nil";
    terpri()$write "   kern        : ",get(s,'kern);
    terpri()$write "   non_rat_kern: ",get(s,'non_rat_kern);
    terpri()$write "   fct_kern_lin: ",get(s,'fct_kern_lin);
    terpri()$write "   fct_kern_nli: ",get(s,'fct_kern_nli);
    terpri()$write "   fcts        : ",get(s,'fcts);
    terpri()$write "   fct_hom     : ",get(s,'fct_hom);
    terpri()$write "   vars        : ",get(s,'vars);
    terpri()$write "   nvars       : ",get(s,'nvars);
    terpri()$write "   level       : ",get(s,'level);
    terpri()$write "   terms       : ",get(s,'terms);
    terpri()$write "   length      : ",get(s,'length);
    terpri()$write "   printlength : ",get(s,'printlength);
    terpri()$write "   rational    : ",get(s,'rational);
    terpri()$write "   nonrational : ",get(s,'nonrational);
    terpri()$write "   allvarfcts  : ",get(s,'allvarfcts);
%    terpri()$write "   degrees     : ",get(s,'degrees);
    terpri()$write "   starde      : ",get(s,'starde);
    terpri()$write "   fcteval_lin : ",get(s,'fcteval_lin);
    terpri()$write "   fcteval_nca : ",get(s,'fcteval_nca);
    terpri()$write "   fcteval_nli : ",get(s,'fcteval_nli);
    terpri()$write "   fcteval_n2l : ",get(s,'fcteval_n2l);
    terpri()$write "   fct_nli_lin : ",get(s,'fct_nli_lin);
    terpri()$write "   fct_nli_nca : ",get(s,'fct_nli_nca);
    terpri()$write "   fct_nli_nli : ",get(s,'fct_nli_nli);
    terpri()$write "   fct_nli_nus : ",get(s,'fct_nli_nus);
    terpri()$write "   rl_with     : ",get(s,'rl_with);
    terpri()$write "   dec_with    : ",get(s,'dec_with);
    terpri()$write "   dec_with_rl : ",get(s,'dec_with_rl);
    terpri()$write "   to_int      : ",flagp(s,'to_int);
    terpri()$write "   to_fullint  : ",flagp(s,'to_fullint);
    terpri()$write "   to_sep      : ",flagp(s,'to_sep);
    terpri()$write "   to_casesep  : ",flagp(s,'to_casesep);
    terpri()$write "   to_gensep   : ",flagp(s,'to_gensep);
    terpri()$write "   to_decoup   : ",flagp(s,'to_decoup);
    terpri()$write "   to_drop     : ",flagp(s,'to_drop);
    terpri()$write "   to_eval     : ",flagp(s,'to_eval);
    terpri()$write "   to_diff     : ",flagp(s,'to_diff);
    terpri()$write "   to_under    : ",flagp(s,'to_under);
    terpri()$write "   to_symbol   : ",flagp(s,'to_symbol);
    terpri()$write "   not_to_eval : ",get(s,'not_to_eval);
    terpri()$write "   used_       : ",flagp(s,'used_);
    terpri()$write "   orderings   : ",get(s,'orderings);
    terpri()$write "   split_test  : ",get(s,'split_test);
    terpri()$write "   linear_     : ",get(s,'linear_);
    terpri()$write "   histry_     : ",get(s,'histry_);
    terpri()$write "   hom_deg     : ",get(s,'hom_deg);
    terpri()$write "   case2sep    : ",get(s,'case2sep);
%    if fhom_ then <<
%      terpri()$write "   hom_deg     : ",get(s,'hom_deg)
%    >>;
    terpri()>>
 >> >>;


symbolic procedure rationalp(p,f);
% tests if p (in prfix form) is rational in f and its derivatives
% currently (June 2007) only called from crint.red --> prefix input
not pairp p
or
((car p='QUOTIENT) and
 polynop(cadr p,f) and polynop(caddr p,f))
or
((car p='EQUAL) and
 rationalp(cadr p,f) and rationalp(caddr p,f))
or
polynop(p,f);


symbolic procedure ratexp(p,ftem);
% tests if p (in prfix form) is rational in f of ftem and their derivatives
% currently (June 2007) only called from crint.red --> prefix input
if null ftem then t
             else if rationalp(p,car ftem) then ratexp(p,cdr ftem)
                                           else nil;


symbolic procedure polynop(p,f);
%  tests if p (in prefix form) is a polynomial in f and its derivatives
%    p: expression
%    f: function
if atom p then t else
if (pairp p) and (car p = 'DF) and (atom cadr p) then t else
if my_freeof(p,f) then t else
begin scalar a;
 if member(car p,list('EXPT,'PLUS,'MINUS,'TIMES,'QUOTIENT,'DF)) then
                                        %  erlaubte Funktionen
        <<if (car p='PLUS) or (car p='TIMES) then
                <<p:=cdr p;
                while p do
                    if a:=polynop(car p,f) then p:=cdr p
                                           else p:=nil>>
        else if (car p='MINUS) then
                a:=polynop(cadr p,f)
        else if (car p='QUOTIENT) then
                <<if freeof(caddr p,f) then a:=polynop(cadr p,f)>>
        else if car p='EXPT then        %  Exponent
                <<if (fixp caddr p) then
                   if caddr p>0 then a:=polynop(cadr p,f)>>
        else if car p='DF then          %  Ableitung
                if (cadr p=f) or freeof(cadr p,f) then a:=t>>
 else a:=(p=f);
 return a
end;

symbolic procedure stardep3(vl,ker,drv);
% If there is a variable v which does not occur explicitly and only one
% function with only one derivative df occurs then (df . v) is returned else nil
begin scalar v,dfc, % the function or derivative (without df)
             dfcp,         % the exponent
             drvcp,        % a copy of drv
             caa;
 while vl and null dfc do <<
  v:=car vl; vl:=cdr vl;
  if freeof(ker,v) then <<
   drvcp:=drv;
   while drvcp do <<
    caa:=caar drvcp;  % e.g.  caa = (h x)
    if caa=dfc then if cdar drvcp>dfcp then dfcp:=cdar drvcp else
               else % car drv is a different power of dfc
    if member(v,fctargs car caa) then % car caar depends on v
    if null dfc then <<dfc:=caa;dfcp:=cdar drvcp>> else <<drvcp:={1}; dfc:=nil>>;
    drvcp:=cdr drvcp;
   >>
  >>
 >>;
 return if (null dfc) or (dfcp=1) then nil else
        if null cdr dfc then cons(car dfc,v) else cons(cons('DF,dfc),v)
end;


symbolic procedure starp(ft,n);
%  yields t if
%  - one function is known to depend on one variable
%  - and this variable does only come up in this function,
%    not explicitly nor in any other function, or
%  if all functions from ft have less than n arguments
begin scalar b;
  while not b and ft do                % searching a fct of all vars
  if fctlength car ft=n then b:=t
			else ft:=cdr ft;
  return not b
end;


symbolic procedure stardep(ftem,vl);
%  yields: nil, if a function (from ftem) in p depends
%               on all variables (from vl)
%          cons(v,n) otherwise, with v being the list of variables
%               which occur in a minimal number of n functions
begin scalar b,v,n;
  if starp(ftem,length vl) then
  <<n:=sub1 length ftem;
    while vl do                    % searching var.s on which depend
			           % a minimal number of functions
    <<if n> (b:=for each h in ftem sum
                if member(car vl,fctargs h) then 1 else 0)
      then <<n:=b$v:=list car vl>> % a new minimum
      else if b=n then v:=cons(car vl,v);
      vl:=cdr vl>> >>;
  return if v then cons(v,n)       % on each varible from v depend n
		  	           % functions
	      else nil
end;


%symbolic procedure no_of_sep_var(ftem);
%% assuming ftem are all functions from an ise
%% How many are there indirectly separable variables?
%% If just two then the new indirect separation is possible
%begin scalar v,vs;
%  vl:=argset(ftem);
%  for each f in ftem do
%  vs:=union(setdiff(vl,fctargs f),vs);
%  return vs
%end;

put('parti_fn,'psopfn,'parti_fncts);

symbolic procedure parti_fncts(inp);
% inp= (fl,el)
% fl ... alg. list of functions, el ... alg. list of equations
% partitions fl such that all functions that are somehow dependent on
% each other through equations in el are grouped in lists,
% returns alg. list of these lists

if length inp neq 2 then <<
 terpri();
 write"PARTI_FNCTS DOES NOT HAVE 2 ARGUMENTS.";
>>                  else
begin
 scalar fl,f1,f2,f3,f4,f5,el,e1,e2;

 fl := cdr reval  car inp;
 el := cdr aeval cadr inp;

 while fl do <<
  f1:=nil;         % f1 is the sublist of functions depending on each other
  f2:=list car fl; % f2 ... func.s to be added to f1, not yet checked
  fl:=cdr fl;
  while f2 and fl do <<
   f3:=car f2; f2:=cdr f2;
   f1:=cons(f3,f1);
   for each f4 in
   % smemberl will be all functions not registered yet that occur in
   % an equation in which the function f3 occurs
   smemberl(fl,    % fl ... the remaining functions not known yet to depend
            <<e1:=nil;  % equations in which f3 occurs
              for each e2 in el do
              if smember(f3,e2) then e1:=cons(e2,e1);
              e1
            >>
           )        do <<
    f2:=cons(f4,f2);
    fl:=delete(f4,fl)
   >>
  >>;
  if f2 then f1:=append(f1,f2);
  f5:=cons(cons('LIST,f1),f5)
 >>;
 return cons('LIST,f5)
end;


symbolic procedure plot_dependencies(pdes);
begin scalar fl;
  change_prompt_to "";
  fl:=ftem_;
  if flin_ and yesp
  "Shall only functions from the linear list flin_ be considered? "
  then fl:=setdiff(fl,setdiff(fl,flin_));
  restore_interactive_prompt();
  plot_dep_matrix(pdes,fl)
end;

symbolic procedure plot_dep_matrix(pdes,allf);
begin scalar f,ml,lf,fl,h,lh,lco,n,m,h,ll,gcbak;

!#if (memq 'csl lispsystem!*)
  gcbak := verbos 0;
!#else
  gcbak:=!*gc;
  if gcbak then algebraic(off gc);
!#endif

  ml:=0;                % the maximal length of all variable names
  lf:=length allf;
  for each f in reverse allf do <<
    h:=explode f;
    lh:=length h;
    if lh>ml then ml:=lh;
    lco:=cons(h,lco);
  >>;

  ll:=linelength (lf+6);
  terpri();
  write "Horizontally: function names (each vertical),  ",
        "Vertically: equation indices";
  terpri();

  % print the variable names
  for n:=1:ml do <<
    terpri()$ write"     ";
    for m:=1:lf do write <<
      h:=nth(lco,m);
      if n>length h then " "
                    else nth(nth(lco,m),n)
    >>
  >>;

  m:=add1 add1 ml;
  terpri()$terpri();
  for each p in pdes do
  if m>=0 then <<
   h:=explode p;
   for n:=3:length h do write nth(h,n);
   for n:=(sub1 length(h)):5 do write" ";
   fl:=get(p,'fcts);
   if (not get(p,'fcteval_lin)) and
      (not get(p,'fcteval_nca)) and
      (not get(p,'fcteval_nli)) then fcteval(p)$ % for writing "s"
   for each f in allf do
   if freeof(fl,f) then write" " else
   if solvable_case(p,f,'fcteval_lin) or
      solvable_case(p,f,'fcteval_nca) then write"s"
                       	              else write"+";
   terpri();
   m:=add1 m;
%   if m=23 then if not yesp "Continue ?" then m:=-1
%                                         else m:=0
  >>;
!#if (memq 'csl lispsystem!*)
  verbos gcbak;
!#else
  if gcbak then algebraic(on gc);
!#endif
  linelength ll
end;

symbolic procedure plot_statistics(size_history);
begin scalar s,h,k,n,pl,sf,tl,proli,plcp,newplcp,
             time_offset,next_time,old_time,mint,maxt,quick,
             maxmeth,maxfl,maxpdes,maxterms,maxfactperterm,maxcells;
 change_prompt_to "";

 h:=size_history;
 while h do <<
  k:=car h;   h:=cdr h;
  if car k = 'CP then
  if null plcp then plcp:=cdr k
               else << % merge plcp and cdr k
   newplcp:=nil;
   k:=cdr k;
   while k or plcp do <<
    if k and not freeof(newplcp,car k) then k:=cdr k else
    if plcp and not freeof(newplcp,car plcp) then plcp:=cdr plcp else
    if null k then <<
     newplcp:=cons(car plcp,newplcp);
     plcp:=cdr plcp
    >>        else
    if null plcp then <<
     newplcp:=cons(car k,newplcp);
     k:=cdr k
    >>           else
    if car k = car plcp then <<
     newplcp:=cons(car k,newplcp);
     k:=cdr k;plcp:=cdr plcp
    >>                  else
    if freeof(k,car plcp) then <<
     newplcp:=cons(car plcp,newplcp);
     plcp:=cdr plcp
    >>                    else
    if freeof(plcp,car k) then <<
     newplcp:=cons(car k,newplcp);
     k:=cdr k
    >>                    else <<
     newplcp:=cons(car k,cons(car plcp,newplcp));
     k:=cdr k;plcp:=cdr plcp
    >>
   >>;
   plcp:=reverse newplcp
  >>
 >>;

 s:=0;
 while plcp do <<
  s:=add1 s;
  proli:=cons(cons(car plcp,s),proli);
  plcp:=cdr plcp
 >>;

 maxmeth:=0;
 maxfl:=0;
 maxpdes:=0;
 maxterms:=0;
 maxfactperterm:=0;
 maxcells:=0;
 proli:=reverse proli;
 time_offset:=0;
 old_time:=-1;
 s:="schrott.tmp";
 out s;
 for each h in reverse size_history do
 if (fixp car h) and (cdddr cdddr h) % nothing is missing
 then <<
  if old_time=-1 then old_time:=caddr h;
  next_time:=time_offset+caddr h;
  if next_time<old_time then <<
   time_offset:=time_offset+(old_time-next_time);
   next_time:=old_time
  >>;
  write next_time," ",     % time
        if (n:=assoc(car h,proli)) then cdr n
                                   else 0," ",  % method
        cadddr h," ",      % # of remaining unknowns
        cadddr cdr h," ",  % # of pdes
        cadddr cddr h," ", % # of terms
        cadddr cdddr h," ",% total length of pdes
        cadddr cddddr h$   % last_free_cells
      % cadr h," ",        % stepcounter_
  old_time:=next_time;
  if n and cdr n>maxmeth then maxmeth:=cdr n;
  if cadddr h>maxfl then maxfl:=cadddr h;
  if cadddr cdr h>maxpdes then maxpdes:=cadddr cdr h;
  if cadddr cddr h>maxterms then maxterms:=cadddr cddr h;
  if (100*(cadddr cdddr h)) > maxfactperterm*(cadddr cddr h) then
     maxfactperterm:=(100*(cadddr cdddr h))/(cadddr cddr h);
  if (fixp cadddr cddddr h) and
     (cadddr cddddr h>maxcells) then maxcells:=cadddr cddddr h;
  terpri();
 >>;
 shut s;

 pl:=nil;
 if yesp "Do you want a quick overview on the screen? " then quick:=t;
 if quick then <<
  terpri();
  write"Here are the maximal values scaled to 1 in the diagram:"$terpri();
  % write"max method index:      ",maxmeth$terpri();
  write"max # of unknows:      ",maxfl$terpri();
  write"max # of equations:    ",maxpdes$terpri();
  write"max # of terms:        ",maxterms$terpri();
  write"max # of factors/term: ",maxfactperterm,"/100"$terpri();
  write"max # of free cells:   ",maxcells$terpri();

  % If the method shall be plotted then these 4 lines:
  %pl:=bldmsg("%w%w%w%d%w",
  %   "plot '",s,"' using ($1/60000):($2/",maxmeth ,") title ""method      :"" with lines");
  %pl:=bldmsg("%w%w%w%w%d%w",pl,
  %	", '",s,"' using ($1/60000):($3/",maxfl   ,") title ""unknowns    :"" with lines");
  %                                else the following 4 lines:
  pl:=bldmsg("%w",
     "plot '");
  pl:=bldmsg("%w%w%w%d%w",pl,
        s,"' using ($1/60000):($3/",maxfl   ,") title ""unknowns    :"" with lines");

  pl:=bldmsg("%w%w%w%w%d%w",pl,
	", '",s,"' using ($1/60000):($4/",maxpdes ,") title ""equations   :"" with lines");
  pl:=bldmsg("%w%w%w%w%d%w",pl,
	", '",s,"' using ($1/60000):($5/",maxterms,") title ""all terms   :"" with lines");
  pl:=bldmsg("%w%w%w%w%d%w",pl,
	", '",s,"' using ($1/60000):(100*$6/$5/",maxfactperterm ,") title ""factors/term:"" with lines");
  pl:=bldmsg("%w%w%w%w%d%w",pl,
	", '",s,"' using ($1/60000):($7/",maxcells,") title ""free cells  :"" with lines");
  pl:=bldmsg("%w%w%w%w",pl,
	", '",s,"' using ($1/60000):(0) title ""step        :""");
 >>       else
 repeat <<
  write"Do you want to add to the plot a graph for the "$terpri();
  write"  - method used at each step:   1"$terpri();
  write"  - number of unknowns:         2"$terpri();
  write"  - number of pdes:             3"$terpri();
  write"  - number of terms:            4"$terpri();
  write"  - number of factors/term:     5"$terpri();
  write"  - number of last free cells:  6"$terpri();
  write"or add no further graphs:       n          ";
  h:=termread();
  if (h=1) or (h=2) or (h=3) or (h=4) or (h=5) or (h=6) then <<
   write"What is the scaling factor for this graph? ";
   repeat sf:=termread() until fixp sf;
   if null pl then  pl:="plot "
              else  pl:=bldmsg("%w%w",pl,",");
   if h=1 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$2) title ""method      :""") else
   if h=2 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$3) title ""unknowns    :""") else
   if h=3 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$4) title ""equations   :""") else
   if h=4 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$5) title ""all terms   :""") else
   if h=5 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$6/$5) title ""factors/term:""") else
   if h=6 then pl:=bldmsg("%w%w%w%w%d%w",pl,"'",s,"' using ($1/60000):(",
                          sf,"*$7) title ""free cells  :""");
  >>;
 >> until h='N;

 % Generating the headline
 tl:="set title ""Modules in order of their priority: ";
 for each h in proli do tl:=bldmsg("%w%d%w",tl,car h," ");
 tl:=bldmsg("%w%w",tl,""" ");
 algebraic(gnuplot(lisp tl));

 if quick or
    yesp "Do you want the x-range to be determined automatically? " then <<
  algebraic(gnuplot("set autoscale x"));
  algebraic(gnuplot("set autoscale y"));
 >>                                                                 else <<
  write "What is the minimal value of x (time in minutes) ? ";
  mint:=termread()$     %mint:=mint*60000;
  write "What is the maximal value of x (time in minutes) ? ";
  maxt:=termread()$     %maxt:=maxt*60000;
  tl:=bldmsg("%w%d%w%d%w","set xrange [",mint,":",maxt,"]");

  algebraic(gnuplot("set noautoscale"));
  algebraic(gnuplot("set autoscale y"));
  %  algebraic(gnuplot("set autoscale xmin"));
  %  algebraic(gnuplot("set xrange [mint:maxt]"));
  algebraic(gnuplot(lisp tl));
 >>;

 algebraic(gnuplot("set key Left"));

 if quick or
    yesp "Do you want to display the plot on the screen? " then <<
 >>                                                        else
 if yesp "Do you want to print the plot? " then <<
  lisp setq(plotheader!*,"");
  algebraic(gnuplot("set output '|lpr -Pmath4'"));
  algebraic(gnuplot("set terminal postscript eps 22"));
 >>                                        else <<
  write"Give the file name in which to save the plot in "" "": ";
  tl:=termread();
  tl:=bldmsg("%w%w%w","set output '",tl,"'");
  lisp setq(plotheader!*,"");
  algebraic(gnuplot(lisp tl));
  algebraic(gnuplot("set terminal postscript eps 22"));
 >>;
 algebraic(gnuplot(lisp pl));
 algebraic lisp null eval '(plotshow);

 % doing: out s; shut s; gives an error with gnuplot
 restore_interactive_prompt()
end;


symbolic operator plot_stat;
symbolic procedure plot_stat;
begin scalar s,ask;
 change_prompt_to "";
 if null session_ then ask:=t else <<
  write "Do you want to plot statistics of this session,";
  terpri();
  if not yesp "i.e. since loading CRACK the last time? " then ask:=t;
  % terpri()
 >>;
 if ask then <<
  ask_for_session();
  setq(s,bldmsg("%w.%w",session_,"size_hist"));
  in s
 >>;
 plot_statistics(size_hist);
 restore_interactive_prompt()
end;


symbolic procedure list_cases(size_history);
begin scalar s,m,n,p,h,cntr,laststep,lastp,ll,sh;
 ll:=linelength(250);
 change_prompt_to "";
 algebraic(off nat);

 if size_watch neq t then <<
  write"Warning: Because the parameter size_watch was set to ",size_watch;
  terpri();
  write"(to save memory in long computations) only the last ",size_watch," steps";
  terpri();
  write"are recorded, i.e. early cases may be missing in this listing.";
  terpri()$terpri();
 >>;

 write"Start"$ cntr:=0$laststep:=0$lastp:=nil;
 n:=0;
 sh:=reverse size_history;
 while sh do <<
  p:=caar sh;
  if p='A then <<
   h:=laststep - cntr;
   write" : ",h,if h=1 then " step" else " steps";
   terpri();
   cntr:=laststep;
   n:=add1 n;
   h:=cadddr car sh;
   s:="";
   for each m in caddr car sh do setq(s,bldmsg("%w%d",s,m));
   write s;
   if h then
   if atom h then write h
             else
   repeat <<
    if caar h = 'EQUAL then <<write" 0=" $maprin caddr car h>> else
    if caar h = 'INEQ  then <<write" 0<>"$maprin caddr car h>>;
    h:=cdr h;
    if h then <<
     s:="";
     for each m in caddr car sh do setq(s,bldmsg("%w%w",s," "));
     write s
    >>
   >> until null h
  >>      else
  if p='Z then <<
   n:=sub1 n;
   if lastp neq 'z then write", ",cadddr car sh," soln"
  >>      else
  if numberp caar sh then laststep:=cadar sh;

  if (size_watch=t) and
     ((p='A) or (p='Z)) and
     (n neq length caddar sh) then
  <<write"Somthing is wrong with level counting in size_hist"$terpri();
    write"n=",n," level:",caddar sh$terpri();
  >>;
  lastp:=p;
  sh:=cdr sh
 >>;
 terpri();
 algebraic(on nat);
 restore_interactive_prompt();
 linelength(ll)
end;


symbolic procedure list_global_crack_variables;
for each h in '(!*allowdfint_bak !*dfprint_bak !*diffelimverbosity!*
!*exp_bak !*ezgcd_bak !*fullroots_bak !*gcd_bak !*mcd_bak !*nopowers_bak
!*ratarg_bak !*rational_bak !*batch_mode alg_poly adjust_fnc allflags_
auto_para_mode batchcount_ backup_ batch_mode_sub call_crack_out case_list
choose_6_20_max_ftem choose_6_20_max_terms choose_27_8_16_max
choose_30_47_21_max choose_70_65_8_47_origmem choose_70_65_8_47_origterms
choose_70_65_8_47_ratiomem choose_70_65_8_47_ratioterms choose_30_47_72_eqn
choose_11_30_max_11 choose_11_30_max_30 collect_sol confirm_subst cont_
contradiction_ cost_limit5 crack_download_add crack_ini_file
crack_load_command currently_to_be_substituted_in default_proc_list_
diffelim_steps do_recycle_eqn do_recycle_fnc done_trafo eqname_ eqn_input
eqn_no eqn_to_be_gen equations_file expert_mode explog_ facint_ fhom_ flin_
force_sep form_comp form_eqn_idx form_eqn_on_disk form_max_read form_pipe
form_tmp_dir fname_ fnew_ freeabs_ freeint_ fsub_ ftem_ full_proc_list_
gcfree!* genint_ global_list_integer global_list_ninteger global_list_float
groeb_diff_max groeb_solve high_gensep history_ idname_ idnties_ independence_
ineq_ ineq_or inter_divint keep_case_tree keep_parti
inverse_trafo_list_incomplete largest_fully_shortened last_free_cells
last_steps lazy_eval length_inc_alg length_inc_dec level_ lex_df lex_fc
limit_time lin_problem lin_test_const logoprint_ low_gensep max_coeff_len
max_eqn_to_conti max_gc_counter max_gc_elimin max_gc_fac max_gc_gb max_gc_int
max_gc_minsub max_gc_ode max_gc_red_len max_gc_short max_gc_ss max_proc_no
max_red_len maxalgsys_ max_term_to_fac_complex max_term_to_fac_real
max_term_to_pred mem_eff min_nu_of_eqn my_gc_counter nequ_ new_gensep nfct_
nid_ odesolve_ old_history one_argument_functions_ para_case_dir
paracrack_initialized pass_back pass_on poly_only potint_ print_ print_all
print_more proc_list_ process_counter prop_list pvm_able quick_decoup
record_hist recycle_eqns recycle_fcts recycle_ids reduce_call reducefunctions_
reducerc_initialized repeat_mode safeint_ session_ singular_call singular_lib
singular_time size_hist size_watch sol_list solvealg_ stepcounter_
struc_eqn subst_0 subst_1 subst_2 subst_3 subst_4 switch_list
target_limit_0 target_limit_1 target_limit_2 target_limit_3 time_ time_limit
to_do_list tr_decouple tr_genint tr_gensep tr_main tr_orderings tr_redlength
tr_short ud_1 ud_2 ud_3 ud_4 userrules_ verify_end_of_parallel_run vl_) do <<
  terpri();
  write "variable: ",h," |  value: ",eval h," | description: ",get(h,'description);
  if freeof(pass_on,h) and
     freeof(pass_back,h) then write" | not in pass_..";
  terpri()
>>;

symbolic operator print_tree;
symbolic procedure print_tree;
%               (a "Start of " (1 1 1 1 1 1 1 1 1 2 2) assumption)
%               (z "Back to "  (1 1 1 1 1 1 1 1 1 2) 1)
begin scalar s,ask;
 change_prompt_to "";
 if null session_ then ask:=t else <<
  write "Do you want to print the tree of cases of this session,";
  terpri();
  if not yesp "i.e. since loading CRACK the last time? " then ask:=t;
  terpri()
 >>;
 if ask then <<
  ask_for_session();
  setq(s,bldmsg("%w.%w",session_,"size_hist"));
  in s
 >>;
 list_cases(size_hist);
 restore_interactive_prompt()
end;


symbolic procedure modify_proc_list(method,revsl);
% e.g.: method='choose_30_47_72 and revsl is the list of module
% names for 30,47,72 but in reverse order of order to be called
begin scalar plbak,plcop,ok;

 %******* Start of modification of proc_list_ *******
 plbak:=proc_list_;

 %*** copy everything before 'method'
 ok:=t;
 while ok and proc_list_ and (car proc_list_ neq method) do
 if not freeof(revsl,car proc_list_) then <<
  write"*** Mis-use of ",method$terpri();
  write"*** ",car proc_list_," came before ",method," in proc_list_ !";
  terpri();
  proc_list_:=plbak;
  ok:=nil
 >>     else <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;

 if ok then <<
  plcop:=cons(method,plcop);

  % delete method from proc_list_
  if proc_list_ then proc_list_:=cdr proc_list_;

  % the crucial part: adding re-ordered procedures
  plcop:=append(revsl,plcop);

  % jump the steps we re-order in the remainder of proc_list_
  while proc_list_ and member(car proc_list_,revsl) do proc_list_:=cdr proc_list_;

  % add the remainder
  while proc_list_ do <<
   % if freeof(plcop,car proc_list_) then
   plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;

  proc_list_:=reverse plcop;
  if print_more then <<
   write"New proc_list_ based on ",method$terpri()
  >>
 >>
end$  % of modify_proc_list

symbolic procedure choose_6_20(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 It assumes that in proc_list_ the entry 'choose_6_20 is
 followed by either 'subst_level_45 (6) or 'subst_level_35 (20).
 If it is 6 and proc_list_ includes no 20 and if the problem is
 by now small enough then it is changed to 20 which is more
 aggressive and for large systems potentially explosive. The
 procedure uses the last entry of size_hist which is taken to
 be a list of elements
    {method
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes
    }
 If size_hist does not exist then data are actively gathered.

 Parameters:
 Currently there are only:
 choose_6_20_max_ftem=20, choose_6_20_max_terms=4000

 Improvements:
 One could make it dependent not only on #(ftem_) but #(ftem\flin_),...
;

if freeof(proc_list_,'subst_level_35) then begin
 scalar allterms,unkn,plbak,plcop,p,ok,shcop;

 % parameters:
 % choose_6_20_max_ftem:=20$ choose_6_20_max_terms:=4000;
 % initialized in crinit.red

 % obtaining values
 if size_watch then <<
  shcop:=size_hist;
  while shcop and not fixp caar shcop do shcop:=cdr shcop
 >>;
 if null shcop then <<
  unkn:=length ftem_;
  allterms:=for each p in car arglist sum get(p,'terms)
 >>            else <<
  unkn:=cadddr car shcop;
  allterms:=cadddr cddar shcop
 >>;

 % changing proc_list_
 if (unkn<=choose_6_20_max_ftem) and (allterms<=choose_6_20_max_terms) then <<

  % Start of modification of proc_list_
  plbak:=proc_list_;

  % copy everything before 'choose_6_20'
  ok:=t;
  while ok and proc_list_ and (car proc_list_ neq 'choose_6_20) do
  if car proc_list_='subst_level_45 then <<
   write"*** Mis-use of choose_6_20"$terpri();
   write"*** subst_level_45 came before choose_6_20 in proc_list_ !";
   terpri();
   proc_list_:=plbak;
   ok:=nil
  >>   else <<
   plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;
  if ok then <<

   % do not copy choose_6_20 and not subst_level_45
   if proc_list_ then proc_list_:=cddr proc_list_;

   % but include now subst_level_35 (20)
   plcop:=cons('subst_level_35,plcop);

   % add the remainder
   while proc_list_ do <<
    if freeof(plcop,car proc_list_) then plcop:=cons(car proc_list_,plcop);
    proc_list_:=cdr proc_list_
   >>;

   proc_list_:=reverse plcop;
   if print_more then <<
    write"proc_list_ has been automatically changed."$terpri();
    write"6 is changed to 20."$terpri()
   >>
  >>
 >>

 % returns always nil
end;


symbolic procedure choose_27_8_16(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 It assumes that in proc_list_ the entry 'choose_27_8_16
 is followed by 'diff_length_reduction,'factorize_to_substitute,'subst_level_3
 in any order. The order of these 3 entries is freshly
 determined in this procedure on the basis of recent
 entries in size_hist which is taken to be a list of elements
    {method
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes
    }
 If anything goes wrong or anything unexpected happens then
 the order becomes 27,8,16.

 Parameters:
 Currently there is only one parameter: choose_27_8_16_max

 Improvements:
 One may want to have some rules what has a higher priority: 8 or 16.
;

begin
 scalar too_much_27,shcp,sh1,sh2,n,h,plbak,plcop,ok;

 if null size_watch then <<
  write"*** choose_27_8_16 needs size_watch=t !"$terpri()
 >>                 else <<
  shcp:=size_hist;
  while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
  if shcp and (caar shcp=27) then <<
   sh1:=car shcp;  shcp:=cdr shcp;

   while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
   if shcp and (caar shcp=27) then <<
    sh2:=car shcp;  shcp:=cdr shcp;

    % main parameter
    % choose_27_8_16_max:=15$  % initialized in crinit.red

    % should a case-generating step 8 or 16 be done before 27?
    % typical order:  1 3 11 6 27 8 20 30 47 21 38
    n:=0;

    while sh2 and (car sh2 = 27) do <<
     % compared to choose_30_47_16 we do not check whether the
     % number of terms increases as it decreases

     % if the last diff_length_reduction step took very long, e.g. because
     % of a long generated equation or stopped elimin calls then
     % inc n by the minutes
     h:= caddr sh1 - caddr sh2;
     n:=n+(h/60000);

     % Are there enough reasons to do a factorization or case generating
     % substitution now?
     if n>=choose_27_8_16_max then too_much_27:=t;
     sh1:=sh2;
     while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
     if null shcp then   sh2:=nil
                  else <<sh2:=car shcp; shcp:=cdr shcp>>
    >>
   >>
  >>;
 >>;

 %******* Start of modification of proc_list_ *******
 plbak:=proc_list_;

 % copy everything before 'choose_27_8_16'
 ok:=t;
 while ok and proc_list_ and (car proc_list_ neq 'choose_27_8_16) do
 if not freeof({'diff_length_reduction,'subst_level_3,'factorize_to_substitute},car proc_list_)
 then <<
  write"*** Mis-use of choose_27_8_16"$terpri();
  write"*** ",car proc_list_," came before choose_27_8_16 in proc_list_ !";
  terpri();
  proc_list_:=plbak;
  ok:=nil
 >>     else <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;

 if ok then <<

  % copy 'choose_27_8_16'
  plcop:=cons('choose_27_8_16,plcop);
  if proc_list_ then proc_list_:=cdr proc_list_;

  % the crucial part of the procedure: reordering proc_list_
  if too_much_27       then      % add 8,16,27
  plcop:=append({'diff_length_reduction,'subst_level_3,'factorize_to_substitute},
                plcop) else      % add 27,8,16
  plcop:=append({'subst_level_3,'factorize_to_substitute,'diff_length_reduction},
                plcop);

  % add the remainder
  while proc_list_ do <<
   if freeof(plcop,car proc_list_) then plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;

  proc_list_:=reverse plcop;
  if print_more then <<
   write"proc_list_ has been automatically changed."$terpri();
   if too_much_27 then write"The order is 8,16,27."
                  else write"The order is 27,8,16.";
   terpri()
  >>
 >>;
 arglist:=nil % to avoid compiler warnings
 % nil is always returned
end;


symbolic procedure choose_30_47_21(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 It assumes that in proc_list_ the entry 'choose_30_47_21
 is followed by 'decoupling,'factorize_any,'subst_level_4
 in any order. The order of these 3 entries is freshly
 determined in this procedure on the basis of recent
 entries in size_hist which is taken to be a list of elements
    {method
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes
    }
 If anything goes wrong or anything unexpected happens then
 the order becomes 30,47,21.

 Parameters:
 Currently there is only one parameter: choose_30_47_21_max

 Improvements:
 One may want to have some rules what has a higher priority: 47 or 21.
;

begin
 scalar too_much_30,shcp,sh1,sh2,n,h,plbak,plcop,ok,shcop,unkn,allterms,p;

 if null size_watch then <<
  write"*** choose_30_47_21 needs size_watch=t !"$terpri()
 >>                 else <<
  shcp:=size_hist;
  while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
  if shcp and (caar shcp=30) then <<
   sh1:=car shcp;  shcp:=cdr shcp;

   while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
   if shcp and (caar shcp=30) then <<
    sh2:=car shcp;  shcp:=cdr shcp;

    % main parameter
    % choose_30_47_21_max:=10$ % initialized in crinit.red

    % should a case-generating step 47 or 21 be done before 30?
    % typical order:  1 3 11 6 27 8 20 30 47 21 38
    n:=0;

    while sh2 and (car sh2 = 30) do <<
     % if the number of equations did not shrink then increase n by 1
     % if the number of equations did increase then increase n by 2
     if cadddr cdr sh1 >= cadddr cdr sh2 then <<
      n:=add1 n;
      if cadddr cdr sh1  > cadddr cdr sh2 then n:=add1 n;
      % if the last decoupling step took very long, e.g. because
      % of a long generated equation or stopped elimin calls then
      % inc n by the minutes
      h:= caddr sh1 - caddr sh2;
      n:=n+(h/60000);

      % Are there enough reasons to do a factorization or case generating
      % substitution now?
      if n>=choose_30_47_21_max then too_much_30:=t
     >>;
     sh1:=sh2;
     while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
     if null shcp then   sh2:=nil
                  else <<sh2:=car shcp; shcp:=cdr shcp>>
    >>
   >>
  >>;
 >>;

 %******* Start of modification of proc_list_ *******
 plbak:=proc_list_;

 % copy everything before 'choose_30_47_21'
 ok:=t;
 while ok and proc_list_ and (car proc_list_ neq 'choose_30_47_21) do
 if not freeof({'decoupling,'subst_level_4,'factorize_any},car proc_list_)
 then <<
  write"*** Mis-use of choose_30_47_21"$terpri();
  write"*** ",car proc_list_," came before choose_30_47_21 in proc_list_ !";
  terpri();
  proc_list_:=plbak;
  ok:=nil
 >>     else <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;

 if ok then <<

  plcop:=cons('choose_30_47_21,plcop);

  if member('external_groebner,proc_list_) then <<
   proc_list_:=delete('external_groebner,proc_list_);
   h:=length ftem_;
   if h <= groeb_diff_max then plcop:=cons('external_groebner,plcop)
  >>;

  % delete 'choose_30_47_21' from proc_list_
  if proc_list_ then proc_list_:=cdr proc_list_;

  % the crucial part of the procedure: reordering proc_list_
  if too_much_30 then <<

   % obtaining values
   if size_watch then <<
    shcop:=size_hist;
    while shcop and not fixp caar shcop do shcop:=cdr shcop
   >>;
   if null shcop then <<
    unkn:=length ftem_;
    allterms:=for each p in car arglist sum get(p,'terms)
   >>            else <<
    unkn:=cadddr car shcop;
    allterms:=cadddr cddar shcop
   >>;

   if (unkn<=choose_6_20_max_ftem) and
      (allterms<=choose_6_20_max_terms) then   % add 47,21,30
   plcop:=append({'decoupling,'subst_level_4,'factorize_any},plcop)
                                        else   % add 47,30,21
   plcop:=append({'subst_level_4,'decoupling,'factorize_any},plcop)
  >>             else      % add 30,47,21
  plcop:=append({'subst_level_4,'factorize_any,'decoupling},plcop);

  % add the remainder
  while proc_list_ do <<
   if freeof(plcop,car proc_list_) then plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;

  proc_list_:=reverse plcop;
  if print_more then <<
   write"proc_list_ has been automatically changed."$terpri();
   if too_much_30 then write"The order is 47,21,30."
                  else write"The order is 30,47,21.";
   terpri()
  >>
 >>;
 arglist:=nil % to avoid compiler warnings
 % nil is always returned
end;

symbolic procedure choose_70_65_8_47(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 The idea is to simplify the system through a case splitting if
 it gets too difficult. The decision is based on the last
 entry in the list size_hist which is taken to be a list of elements
    {method,
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes,
     number of remaining free cells
    }
 This module should be placed before unconditional substitution (20).

 Parameters:
 Currently the used parameters are:
 choose_70_65_8_47_origterms  .. the original number of terms
 choose_70_65_8_47_origmem    .. the original free cells
 choose_70_65_8_47_ratioterms .. percentage of increase of terms
 choose_70_65_8_47_ratiomem   .. percentage of left free mem

 Improvements:
 One could consider simplifying the system if computing times between
 individual steps grew too large or substituted equations become too large.
;

begin scalar csh,plbak,ok,plcop,do_split,sl,shcp;
 shcp:=size_hist;
 while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
 if shcp then <<
  sl:={'pre_determined_case_splits,'case_on_most_frequ_fnc,
       'factorize_to_substitute,'factorize_any};

  csh:=car size_hist;
  if ((100*cadr   cddddr csh) >
      (choose_70_65_8_47_ratioterms*choose_70_65_8_47_origterms)   ) or
     ((100*cadddr cddddr csh) <
      (choose_70_65_8_47_ratiomem  *choose_70_65_8_47_origmem)     ) then do_split:=t;

  %******* Start of modification of proc_list_ *******
  plbak:=proc_list_;

  % copy everything before 'choose_70_65_8_47'
  ok:=t;
  while ok and proc_list_ and (car proc_list_ neq 'choose_70_65_8_47) do
  if not freeof(sl,car proc_list_) then <<
   write"*** Mis-use of choose_70_65_8_47"$terpri();
   write"*** ",car proc_list_," came before choose_70_65_8_47 in proc_list_ !";
   terpri();
   proc_list_:=plbak;
   ok:=nil
  >>     else <<
   plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;

  if ok then <<

   plcop:=cons('choose_70_65_8_47,plcop);

   % delete 'choose_70_65_8_47' from proc_list_
   if proc_list_ then proc_list_:=cdr proc_list_;

   % the crucial part of the procedure: reordering proc_list_
   if do_split then
   plcop:=append(sl,plcop);

   % jump case-splitting steps in proc_list_
   while proc_list_ and member(car proc_list_,sl) do proc_list_:=cdr proc_list_;

   % add the remainder
   while proc_list_ do <<
    % if freeof(plcop,car proc_list_) then
    plcop:=cons(car proc_list_,plcop);
    proc_list_:=cdr proc_list_
   >>;

   proc_list_:=reverse plcop;
   if print_more and do_split then <<
    write"proc_list_ has been automatically changed."$terpri();
    write"70,8,47 has been inserted."$terpri()
   >>
  >>
 >>;
 arglist:=nil % to avoid compiler warnings
 % nil is always returned
end;

symbolic procedure choose_30_47_72(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 The idea is for huge and highly overdetermined systems to balance
 reading in of equations, to do substitutions, decoupling and
 different kinds of factorizations (8,47). The decision is partially
 based on the last entry in the list size_hist which is taken to be
 a list of elements
    {method,
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes,
     number of remaining free cells
    }
 The following procedures should have a higher priority
 than this procedure:
 subst_level_0            (3)
 alg_length_reduction    (11)  (to be tried out, not for very many eqns.)
 factorize_to_substitute  (8)
 subst_level_35          (20)  (for very overdetermined systems)

 Parameters:
 Currently the used parameters are:
 choose_30_47_72_origterms  .. the original number of terms

 Improvements:
;

begin scalar shcp,csh,revsl;
 shcp:=size_hist;
 while shcp and (not fixp caar shcp) do shcp:=cdr shcp;
 if shcp then <<

  %******* Decide on the ordering by preparing the reverse list revsl of procedures
  csh:=car size_hist;

  %******* If no equations then read in an equation
  if car cddddr csh = 0 then revsl:={'read_equation} else
  %******* If only few equations and last was not
  if car cddddr csh < choose_30_47_72_eqn            then
  revsl:={'decoupling,'factorize_any,'read_equation} else
  %******* If many equations then
  %        if last two were no decouplings, then decoupling first,
  %                                         else factorization first
  if car csh neq 30 and pairp cdr shcp and caadr shcp neq 30 then
  revsl:={'read_equation,'factorize_any,'decoupling}         else
  revsl:={'read_equation,'decoupling,'factorize_any};

  %******* Do the change
  modify_proc_list('choose_30_47_72,revsl);
 >>;
 arglist:=nil % to avoid compiler warnings
 % nil is always returned
end;


symbolic procedure choose_11_30(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 It assumes that in proc_list_ the entry 'choose_11_30 is
 followed by either 'alg_length_reduction (11) or 'decoupling (30).
 The procedure uses the last entries of size_hist which is taken to
 be a list of elements
    {method
     stepcounter_,
     time(),
     number of remaining unknowns,
     number of pdes,
     number of terms,
     total length of pdes
    }
 If size_hist does not exist then data are actively gathered.

 Parameters:
 Currently there are only:
 choose_11_30_max_11=10, choose_11_30_max_30=3
;

if size_watch then begin
 scalar shcop,n11,n30,ok,plbak,plcop,last_11_time,last_30_time,last_size,steps_ago;

 % obtaining values
 shcop:=size_hist;
 n11:=0; n30:=0; steps_ago:=0;

 last_size:=get_statistic(car arglist,append(cadr arglist,setdiff(ftem_,cadr arglist)));
 % last_size has same format as car shcop apart from the first element (method)

 % When searching backwards one should not consider irrelevant other subcases
 while shcop and
       ((caar shcop neq 72) or (null last_11_time) or (null last_30_time)) and
       (not fixp caar shcop or
        (n11 <  choose_11_30_max_11) or
        (n30 <= choose_11_30_max_30)    ) do <<
  if fixp caar shcop then <<
   steps_ago:=add1 steps_ago;
   if caar shcop = 11 then <<
    n11:=add1 n11;
    if null last_11_time then
    last_11_time:=((cadr last_size) - (caddar shcop))*50/(50+steps_ago);
    % i.e. after 50 steps the time is halved to give it a new chance
   >>                 else
   if caar shcop = 30 then <<
    n30:=add1 30;
    if null last_30_time then
    last_30_time:=((cadr last_size) - (caddar shcop))*50/(50+steps_ago);
   >>;
   last_size:=cdar shcop
  >>;
  shcop:=cdr shcop
 >>;
 if null last_11_time then last_11_time:=0;
 if null last_30_time then last_30_time:=0;

 % Start of modification of proc_list_
 plbak:=proc_list_;

 % copy everything before 'choose_11_30'
 ok:=t;
 while ok and proc_list_ and (car proc_list_ neq 'choose_11_30) do
 if (car proc_list_='alg_length_reduction) or
    (car proc_list_='decoupling) then <<
  write"*** Mis-use of choose_11_30"$terpri();
  write"*** alg_length_reduction (11) or decoupling (30)"$terpri();
  write"*** came before choose_11_30 in proc_list_ !"$terpri();
  terpri();
  proc_list_:=plbak;
  ok:=nil
 >>   else <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;
 if ok then <<

  while proc_list_ and
        ((car proc_list_ = 'choose_11_30) or
         (car proc_list_ = 'alg_length_reduction) or
         (car proc_list_ = 'decoupling)              ) do
  proc_list_:=cdr proc_list_;

  plcop:=cons('choose_11_30,plcop);
  % These 2 lines can use a bit more sophistication
  if (last_11_time<4000) and % 4 seconds time limit
     (n11<choose_11_30_max_11) then plcop:=cons('alg_length_reduction,plcop);
  if (last_30_time<2000) and % 2 seconds time limit
     (n30<choose_11_30_max_30) then plcop:=cons('decoupling,plcop);

  % add the remainder
  while proc_list_ do <<
   if freeof(plcop,car proc_list_) then plcop:=cons(car proc_list_,plcop);
   proc_list_:=cdr proc_list_
  >>;

  proc_list_:=reverse plcop;
  if print_more then <<
   write"proc_list_ has been automatically updated."$terpri();
  >>
 >>;

 arglist:=nil % to avoid compiler warnings
 % returns always nil
end;

symbolic procedure try_other_ordering(arglist);
comment
 This procedure is for automatic runs, not interactive use.
 It assumes that in proc_list_ there is 'decoupling (30)
 and that this procedure comes definitely after 30 and pretty
 much at the end of proc_list_.;
begin scalar plcop,pdes,s;
 pdes:=car arglist;

 % no action if only one equation left
 if null pdes or null cdr pdes then return nil;

 % copy everything before 'try_other_ordering'
 while proc_list_ and (car proc_list_ neq 'try_other_ordering) do <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;

 % modification of the ordering or of proc_list_
 if proc_list_ then << % This is the case if the procedure was called automatically
  if not lex_df then <<
   lex_df:=t;
   if print_ then <<terpri()$write"From now on lexicographic ordering of derivatives.">>;
   plcop:=cons(car proc_list_,plcop); % i.e. adding 'try_other_ordering
  >>            else <<
   if print_ then <<terpri()$write"The current variable ordering is going to be reversed.">>;
   vl_ := reverse vl_;
   for each s in pdes do put(s,'vars,sort_according_to(get(s,'vars),vl_));
   % 'try_other_ordering is not added again to proc_list_ to terminate afterall
  >>;
  pdes := change_derivs_ordering(pdes,ftem_,vl_);
  proc_list_:=cdr proc_list_$ % dropping 'try_other_ordering
 >>;

 % copying of the rest of proc_list_
 while proc_list_ do <<
  plcop:=cons(car proc_list_,plcop);
  proc_list_:=cdr proc_list_
 >>;
 proc_list_:=reverse plcop;
 return cons(pdes,cdr arglist)
end;

symbolic procedure solvable_case(p,f,case);
begin scalar fe;
 fe:=get(p,case);
 while fe and (cdar fe neq f) do fe:=cdr fe;
 return fe
end;

%symbolic procedure lin_check(pde,fl);
%begin scalar subpde,
% while fl and <<
%  subpde:=subst({'TIMES,lin_test_const,car fl},car fl,pde);
%  freeof(reval {'QUOTIENT,subpde,lin_test_const},lin_test_const)
% >> do fl:=cdr fl;
% return if fl then nil
%              else t
%end;

symbolic procedure add2flin(pdes,f);
% returns t if the function/constant f appears linearly in all pdes
% in addition to the flin_ functions/constants
% and in that case inserts f into flin_.

begin scalar pcp,nonli,h,p,fl,f0;

 % at first check that f comes only with 1st degree
 while pdes do << % continue until a non-linearity is found
  p:=car pdes;
  if freeof(get(p,'fcts),f) then pdes:=cdr pdes
                            else <<
   pcp:=cons(p,pcp);
   h:=get(p,'derivs);
   while h and
         ((cdar h = 1) or (caaar h neq f)) do h:=cdr h;
   if h then <<nonli:=t;pdes:=nil>>
        else pdes:=cdr pdes
  >>
 >>;

 % then check that it does not appear as factor to flin_'s
 if null nonli and flin_ then <<
  f0:=for each fl in flin_ collect (fl . 0);

  while pcp do
  if not freeof(denr get(car pcp,'sqval),f) then
  <<nonli:=t;pcp:=nil>>                     else <<
   h:=subtrsq(      get(car pcp,'sqval)    ,
              subsq(get(car pcp,'sqval),f0) );
   if not freeof(h,f) then <<nonli:=t;pcp:=nil>>
                      else pcp:=cdr pcp
  >>
 >>;
 if null nonli then
 flin_:=sort_according_to(f . flin_, ftem_);

 return null nonli
end;

symbolic procedure lin_check_SQ(sqval,fl);
% returns t iff standard quotient sqval is homogeneously or
% inhomogeneously linear in the elements of fl
if denr sqval neq 1 and not freeoflist(sqval,fl) then nil else
begin scalar k,f,nu,sb;
 k:=setkorder list lin_test_const;
 sb:=for each f in fl collect (f . {'TIMES,lin_test_const,f});
 nu:=numr subf(numr sqval,sb);
 setkorder k;
 return if domainp nu or
           (lin_test_const neq mvar nu) or
           (2>ldeg nu) then t
                       else nil
end;

symbolic procedure lin_check(pde,fl);
% This needs pde to have prefix form. It tests not only whether each
% single function occurs linearly but also whether in products of them
begin scalar a,f;
 a:=pde;
 for each f in fl do a:=err_catch_sub(f,0,a);
 return
 if a then <<
  for each f in fl do pde:=subst({'TIMES,lin_test_const,f},f,pde);
  freeof(reval {'QUOTIENT,{'DIFFERENCE,pde,a},lin_test_const},lin_test_const)
 >>   else nil
end;

symbolic procedure symbol_explanation$ <<
 write"+------------------------------------------------------------------------------+"$terpri();
 write"|CHARACTERIZING FUNCTIONS:                                                     |"$terpri();
 write"|flin_: The function occurs linear and is element of the global list flin_.    |"$terpri();
 write"|fhom_: The function is one of a set of homogeneously occuring functions fhom_.|"$terpri();
 write"| <>0 : The function is known to be non-zero, i.e. it is an element of ineq_.  |"$terpri();
 write"| n2l : The function is not linearly occuring but the equation involves        |"$terpri();
 write"|       linearly occuring functions.                                           |"$terpri();
 write"|CHARACTERIZING SUBSTITUTIONS:                                                 |"$terpri();
 write"| (+) : a favourable substitution                                              |"$terpri();
 write"| (-) : an unfavourable substitution                                           |"$terpri();
 write"| const coeff     : substitution generates no cases                            |"$terpri();
 write"| no cases        : no cases but coefficient involves unknowns                 |"$terpri();
 write"| case generating : substitution generates cases                               |"$terpri();
 write"+------------------------------------------------------------------------------+"$terpri();
>>;

symbolic procedure list_all_subs(txt,sl,s);
if sl then
begin scalar h;
 write txt,": "$  terpri();
 while sl do <<
  write cdar sl," :";
  if member(cdar sl,flin_) then write" flin_(+)" else
  if not freeoflist(flin_,get(s,'fcts)) then write" n2l(-)";
  if member(cdar sl,fhom_) then write" fhom_(+)";
  if member(simp cdar sl,ineq_) then write" <>0(-)";
  if (h:=(  delengthSF numr caar sl
          + delengthSF denr caar sl))>print_ then
  write" coeff: (print length = ",h,")"      else
  write" coeff: ",prepsq caar sl$terpri();
  %  mathprint caar sl;
  sl:=cdr sl
 >>
end;

symbolic procedure list_possible_subs(s);
% list all substitutions with all their advantages and disadvantages
begin
 fcteval(s)$terpri();
 list_all_subs("const coeff substitutions",    get(s,'fcteval_lin),s);
 list_all_subs("no cases substitutions",       get(s,'fcteval_nca),s);
 list_all_subs("case generating substitutions",get(s,'fcteval_nli),s);
end;

symbolic procedure plot_non0_separants(s);
% One could think of storing all leading derivatives for which
% the symbol is non-zero.
begin scalar dv,dl,dlc,dr,fdl,avf,ur;
 if (userrules_ neq {'LIST}) and
    (zerop reval {'DIFFERENCE,
                  car  cdadr userrules_,
                  cadr cdadr userrules_})
 then <<ur:=t; algebraic (clearrules lisp userrules_) >>;

 dv:=get(s,'derivs);
 avf:=get(s,'allvarfcts);
 while dv do <<
  dr:=caar dv;    % the derivative without 'DF  (and no power)
  dv:=cdr dv;
  if member(car dr,avf) then <<
   dlc:=dl;       % dl will be the derivative list
   while dlc and ((caar dlc neq car dr) or
                  which_deriv(car dlc,dr)  ) do dlc:=cdr dlc;
   if null dlc then dl:=cons(dr,dl);
   % which_deriv(a,b) takes two lists of derivatives and returns how
   % often you need to diff. a in order to get at least the
   % derivatives in b. e.g. which_deriv((x 2 y), (x y 2)) returns y
  >>
 >>;
 for each dr in dl do <<
  dr:=if null cdr dr then car dr
                     else cons('DF,dr);
  dr:=mvar car mksq(dr,1);
  if get(s,'linear_) or
     can_not_become_zeroSQ(diffsq(get(s,'sqval),dr),get(s,'fcts))
  then fdl:=cons(dr,fdl)
 >>;
 terpri();
 if fdl then <<
  write "Leading derivatives with non-zero separant: ";
  % terpri()$ mathprint cons('! ,fdl);
  write cdr reval cons('LIST,fdl);
 >>     else
 write "No leading derivative with non-zero separant. ";
 if ur then algebraic(let lisp userrules_)
end;


symbolic procedure rule_from_pde(s);
% s is the name of a PDE that is to be converted to a rule
begin scalar dv,dl,dlc,dr,fdl,avf,l;
 dv:=get(s,'derivs);
 avf:=get(s,'allvarfcts);
 while dv do <<
  dr:=caar dv;
  if member(car dr,avf) then <<
   dlc:=dl;
   while dlc and ((caaar dlc neq car dr) or
                  which_deriv(caar dlc,dr)  ) do dlc:=cdr dlc;
   if null dlc then dl:=cons(car dv,dl);
   % which_deriv(a,b) takes two lists of derivatives and returns how
   % often you need to diff. a in order to get at least the
   % derivatives in b. e.g. which_deriv((x 2 y), (x y 2)) returns y
  >>;
  dv:=cdr dv
 >>;
 for each dv in dl do <<
  dr:=if null cdar dv then caar dv
                      else cons('DF,car dv);
  if get(s,'linear_) or
     can_not_become_zeroSQ(<<l:=coeffn(get(s,'sqval),dr,cdr dv);
                             if pairp l then cadr l
                                        else simp l>>,
                           get(s,'fcts)) then
%     freeofzero(coeffn(get(s,'val),dr,cdr dv),get(s,'fcts),
%                get(s,'vars),get(s,'nonrational)) then
  if cdr dv=1 then fdl:=cons(dr,fdl)
              else fdl:=cons({'EXPT,dr,cdr dv},fdl)
 >>;
 if null fdl then <<
  write"No leading derivative has a non-zero coefficient."$ terpri()
 >>          else
 if cdr fdl then <<
  write"Which term shall be substituted by the rule?"$ terpri();
  mathprint cons('! ,fdl);
  write"Input its number + Enter: ";
  l:=termread();
  if not fixp l then <<
   fdl:=nil;
   write"Input is not a number!"$terpri()
  >>            else
  if l > length fdl then <<
   fdl:=nil;
   write"This number is too big."$terpri()
  >>                else fdl:={nth(fdl,l)}
 >>;
 if fdl then <<
  l:=get(s,'sqval);
  if pairp car fdl and (caar fdl = 'EXPT) then dv:=coeffn({'!*SQ,l,t},cadar fdl,caddar fdl)
                                          else dv:=coeffn({'!*SQ,l,t},  car fdl,1);
  dv:=if pairp dv then cadr dv
                  else simp dv;
  userrules_:=cons('LIST,
%                         reval {'DIFFERENCE,car fdl,{'QUOTIENT,l,dv}}},
                   cons({'REPLACEBY,car fdl,
                         {'!*SQ,quotsq(subtrsq(multsq(simp car fdl,dv),l),dv),t}},
                         cdr userrules_));
  algebraic (write "The new list of user defined rules: ",
                   lisp userrules_);
  terpri()
 >>
end;

%symbolic procedure addup(ex);
%if pairp ex then <<addup(car ex);addup(cdr ex)>> else
%if ex and not numberp ex then begin scalar h;
% h:=backup_;
% while h and cdar h neq ex do h:=cdr h;
% if h then rplaca(h,(add1 caar h . cdar h))
%end;

symbolic procedure how_often(pdes);
% returns an assoc list of the number of terms in the numerators
% of all equations in which each function turns up
begin scalar f,n,equn;
 backup_:=nil;
% for each f in ftem_ do
% %if not member(f,ineq_) then
% backup_:=cons((0 . f),backup_);
% if null backup_ then return nil;
% for each p in pdes do addup(get(p,'val));
 for each f in ftem_ do <<
  n:=0;
  for each p in pdes do
  n:=n + get(p,'terms) - no_of_tm_sf numr subf(numr get(p,'sqval),{(f . 0)});
  backup_:=cons((n . f),backup_);
 >>;

 backup_:=rev_idx_sort backup_;
 for each f in ftem_ do <<
  n:=0;
  for each p in pdes do if member(f,get(p,'fcts)) then n:=add1 n;
  equn:=cons((n . f),equn);
 >>;
 equn:=rev_idx_sort(equn);
 if print_ then <<
  write"Total number of occurences of all unknowns in all equations:"$terpri();
  prettyprint backup_;
  write"Total number of equations in which unknowns occur:"$terpri();
  prettyprint equn;
 >>;
 return backup_
end;

symbolic procedure case_on_most_frequ_fnc(arglist);
begin scalar h;
 h:=how_often(car arglist);
 while h and member(simp cdar h,ineq_) and not zerop(caar h) do h:=cdr h;
 return
 if h and not zerop(caar h) then split_into_cases({car arglist,cadr arglist,
                                                   caddr arglist,cdar h})
                            else nil
end;

symbolic procedure pre_determined_case_splits(arglist);
begin scalar h,carh;
 h:=cdr case_list;
 while h do <<
  carh:=simp car h;
  if freeoflist(carh,ftem_) or member(carh,ineq_) then <<carh:=nil;h:=cdr h>>
                                                  else             h:=nil;
  case_list:=cons('LIST,cddr case_list)
 >>;
 return
 if carh then split_into_cases({car arglist,cadr arglist,caddr arglist,carh})
         else nil
end;

symbolic procedure ftem_sorted_by_index;
begin scalar h,h1,h2,h3,h4,h5;
 % ftem_ functions are sorted by the following criteria:
 % 1. possibly zero flin_
 % 2. non-zero flin_
 % 3. possibly zero non-flin_
 % 4. non-zero non-flin_
 % Each of these groups is sorted by decreasing frequency.

 if flin_ then
 while backup_ do <<
  if member(cdar backup_,flin_) then h1:=cons(car backup_,h1)
                                else h2:=cons(car backup_,h2);
  backup_:=cdr backup_
 >>       else
 while backup_ do <<h1:=cons(car backup_,h1);backup_:=cdr backup_>>;

 for each h3 in ineq_ do if atom h3 and member(h3,ftem_) then
 if member(h3,flin_) then <<
  h:=h1;
  while h and cdar h neq h3 do h:=cdr h;
  if h then <<h1:=delete(car h,h1);h4:=cons(car h,h4)>>
 >>                  else <<
  h:=h2;
  while h and cdar h neq h3 do h:=cdr h;
  if h then <<h2:=delete(car h,h2);h5:=cons(car h,h5)>>
 >>;
 h3:=append(append(h1,idx_sort h4),
            append(h2,idx_sort h5) );
 return for each h in h3 collect cdr h
end;

%%%%%%%%%%%%%%%%%%%%%%%%%
%  leading derivatives  %
%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure listrel(a,b,l);
%   a>=b  w.r.t list l; e.g. l='(a b c) ->  a>=a, b>=c
member(b,member(a,l));

symbolic procedure abs_dfrel(p,q,vl);
% returns t if derivative of p is lower than derivative of q
%         0         "             equal          "
%        nil        "             higher         "
% p,q  : derivatives or functions from ftem like ((f x 2 y z 3) . 2)
% ftem : list of fcts
% vl   : list of vars
begin scalar a;
return
if lex_df then dfrel2(p,q,vl) else
if zerop (a:=absodeg(cdar p)-absodeg(cdar q)) then dfrel2(p,q,vl)
else a<0;
end;

symbolic procedure mult_derivs(a,b);
% multiplies deriv. of a and b
% a,b list of derivs of the form ((fct var1 n1 ...).pow)
begin scalar l;
 return
  if not b then a
  else if not a then b
  else
   <<
   for each s in a do
      for each r in b do
        if car s=car r then l:=union(list cons(car r,plus(cdr r,cdr s)),l)
                       else l:=union(list(r,s),l);
   l>>;
end;


%symbolic procedure all_deriv_search_SF(p,ftem);
% Is simpler but also slower than version below.
%% (((mvar . ldeg) . lc) . red)
%if pairp p and pairp car p and not domainp p % pairp caar p
%then begin scalar a,b;
% a:=mvar p;
%%write"a=",a$terpri();
%%write"red p=",red p$terpri();
%%write"lc p=",lc p$terpri();
% b:=union(all_deriv_search_SF(red p,ftem),
%          all_deriv_search_SF(lc  p,ftem) );
% return
% if atom a and member(a,ftem) then cons(({a} . ldeg p),b) else
% if pairp a and car a = 'DF and
%    member(cadr a,ftem)       then cons((cdr a . ldeg p),b)
%                              else b
%end;


symbolic procedure all_power_search_SF(p);
if pairp p and pairp car p and not domainp p % pairp caar p
then begin scalar a,b,lcp;
 a:=mvar p;
 lcp:=all_power_search_SF lc p;
 b:=if atom a then ({a} . ldeg p) else
    if pairp a and car a = 'DF then (cdr a . ldeg p);
 while pairp       red p and
       pairp car   red p and
       not domainp red p do
 if a eq mvar red p then <<if b then lcp:=cons((car b . ldeg red p),lcp);
                           lcp:=union(all_power_search_SF lc red p,lcp); p:=red p      >>
                    else <<lcp:=union(all_power_search_SF    red p,lcp); p:={nil . nil}>>;
 return if b then cons(b,lcp)
             else lcp
end;

symbolic procedure all_deriv_search_SF(p,ftem);
begin scalar h,ad;
 for each h in all_power_search_SF p do
 if member(caar h,ftem) then ad:=cons(h,ad);
 return ad
end;

symbolic procedure all_deriv_search(p,ftem)$  % currently (July 2007) only used in crident.red
%  yields all derivatives occuring polynomially in a pde  p
begin scalar a;
 if not pairp p then <<if member(p,ftem) then a:=list cons(list p,1)>>
                else <<if member(car p,'(PLUS QUOTIENT EQUAL)) then
    for each q in cdr p do
	  a:=union(all_deriv_search(q,ftem),a)
  else if car p='MINUS then a:=all_deriv_search(cadr p,ftem)
  else if car p='TIMES then
    for each q in cdr p do
	  a:=mult_derivs(all_deriv_search(q,ftem),a)
  else if (car p='EXPT) and numberp caddr p then
      for each b in all_deriv_search(cadr p,ftem) do
          <<if numberp cdr b then
               a:=cons(cons(car b,times(caddr p,cdr b)),a)>>
  else if (car p='DF) and member(cadr p,ftem) then a:=list cons(cdr p,1)
 >>;
 return a
end;

symbolic procedure abs_ld_deriv(p);
if get(p,'derivs) then reval cons('DF,caar get(p,'derivs));

symbolic procedure abs_ld_deriv_pow(p);
if get(p,'derivs) then cdar get(p,'derivs)
                  else 0;

symbolic procedure which_first(a,b,l);
if null l then nil else
if a = car l then a else
if b = car l then b else which_first(a,b,cdr l);


symbolic procedure total_less_dfrel(a,b,ftem,vl);
% = 0 if a=b, =t if a<b, = nil if a>b
begin scalar fa,ad,al,bl;
  fa:=caar a;
  return
  if a=b then 0 else
  if lex_fc then % lex. order. of functions has highest priority
  if fa=caar b then
  if (ad:=abs_dfrel(a,b,vl))=0 then             % power counts
  if cdr a < cdr b then t
                   else nil
                               else
  if ad then t
        else nil
               else
  if fa=which_first(fa,caar b,ftem) then nil
                                    else t
            else % order. of deriv. has higher priority than fcts.
                 % number of variables of functions has still higher priority
  if (al:=fctlength fa) > (bl:=fctlength caar b) then nil
                                                 else
  if bl>al then t
           else
  if (ad:=abs_dfrel(a,b,vl))=0 then
  if fa=caar b then
  if cdr a < cdr b then t
                   else nil
               else
  if fa=which_first(fa,caar b,ftem) then nil
                                    else t
                               else
  if ad then t
        else nil
end;

symbolic procedure sort_derivs(l,ftem,vl);
% yields a sorted list of all derivatives in l using quicksort
begin scalar l1,l2,a;
 return
 if null l then nil
           else <<
  a:=car l;
  l:=cdr l;
  while l do <<
     if a neq car l then
     if total_less_dfrel(a,car l,ftem,vl) then l1:=cons(car l,l1)
                                          else l2:=cons(car l,l2);
     l:=cdr l
  >>;
  append(sort_derivs(l1,ftem,vl),cons(a,sort_derivs(l2,ftem,vl)))>>
end;

symbolic procedure dfmax(p,q,vl);
%   yields the higher derivative
%   vl list of variables e.g. p=((x 2 y 3 z).2), q=((x y 4 z).1)
%                             df(f,x,2,y,3,z)^2, df(f,x,y,4,z)
if dfrel(p,q,vl) then q
		 else p;

symbolic procedure dfrel(p,q,vl);
%   the relation "p is lower than q"
%   vl list of vars e.g. p=((x 2 y 3 z).2), q=((x y 4 z).1)
if lex_df then dfrel1(p,q,vl)
          else begin scalar a;
 return
  if zerop(a:=absodeg(car p)-absodeg(car q)) then dfrel1(p,q,vl)
                                             else if a<0 then t
                                                         else nil
end;

symbolic procedure diffrelp(p,q,v);
% gives  t  when p "<" q
%       nil when p ">" q
%        0  when p  =  q
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
if cdr p='infinity then nil else
if cdr q='infinity then t   else dfrel(p,q,v);
% 8.6.2006: changed from dfrel1 to dfrel as diffrelp() must use same
% ordering of derivatives as lderiv() for intpde_() to work properly.
% dfrel1 uses only lex-ordering whereas dfrel also totdeg-ordering.

symbolic procedure dfrel1(p,q,v);
% p,q like ((f x 2 y z 3) . 2)
if null v then
   if cdr p='infinity then nil else % #+#
   if cdr q='infinity then t   else % #+#
   if cdr p>cdr q then nil else         %  same derivatives,
   if cdr p<cdr q then t   else 0       %  considering powers
   % for termorderings of non-linear problems the last 2 lines
   % have to be extended
else begin
	scalar a,b;
	a:=dfdeg(car p, car v);
	b:=dfdeg(car q, car v);
	return if a<b then t
	else   if b<a then nil
	else dfrel1(p,q,cdr v)  %  same derivative w.r.t car v
end;

symbolic procedure dfrel2(p,q,v);
% p,q like ((f x 2 y z 3) . 2)
if null v then 0
else begin
	scalar a,b;
	a:=dfdeg(car p, car v);
	b:=dfdeg(car q,car v);
	return if a<b then t
	else   if b<a then nil
	else dfrel2(p,q,cdr v)  %  same derivative w.r.t car v
end;

symbolic procedure absodeg(p);
if not pairp p then 0
else eval cons('PLUS,for each v in p collect if fixp(v) then sub1(v)
                                                        else 1);

symbolic procedure maxderivs(numberlist,deriv,varlist);
if null numberlist then
 for each v in varlist collect dfdeg(deriv,v)
else begin scalar l;
 for each v in varlist do
  <<l:=cons(max(car numberlist,dfdeg(deriv,v)),l);
  numberlist:=cdr numberlist>>;
 return reverse l
end;

symbolic procedure dfdeg(p,v);
%   yields order of deriv. wrt. v;
%   e.g p='(x 2 y z 3), v='x --> 2
if null(p:=member(v,p)) then 0
else if null(cdr p) or not fixp(cadr p)
        then 1                          %  v without order
        else cadr p$                    %  v with order

symbolic procedure lower_deg(p,v);
%  reduces the order of the derivative p wrt. v by one
%   e.g p='(x 2 y z 3), v='z --> p='(x 2 y z 2)
%   e.g p='(x 2 y z 3), v='y --> p='(x 2 z 3)
%  returns nil if no v-derivative
begin scalar newp;
 while p and (car p neq v) do <<newp:=cons(car p,newp);p:=cdr p>>;
 if p then
 if null(cdr p) or not fixp(cadr p) then p:=cdr p
                                    else <<
  newp:=cons(sub1 cadr p,cons(car p,newp));
  p:=cddr p
 >> else newp:=nil;
 while p do <<newp:=cons(car p,newp);p:=cdr p>>;
 return reverse newp
end;

symbolic procedure df_int(d1,d2);
begin scalar n,l;
return
 if d1 then
  if d2 then
   <<n:=dfdeg(d1,car d1)-dfdeg(d2,car d1);
   l:=df_int(if cdr d1 and numberp cadr d1 then cddr d1
                                           else cdr d1 ,d2);
   if n<=0 then l
   else if n=1 then cons(car d1,l)
   else cons(car d1,cons(n,l))
   >>
  else d1;
end;

symbolic procedure alg_linear_fct(p,f);
begin scalar l;
 l:=ld_deriv(p,f);
 return l and ((car l=f) and (cdr l=1))
end;

% not used anymore:
%
%symbolic procedure dec_ld_deriv(p,f,vl);
%%  gets leading derivative of f in p wrt. vars order vl
%%  result: derivative , e.g. '(x 2 y 3 z)
%begin scalar l,d,ld;
% l:=get(p,'derivs);
% vl:=intersection(vl,get(p,'vars));
% while caaar l neq f do l:=cdr l;
% ld:=car l$l:=cdr l;
% % --> if lex_df then dfrel1() else
% d:=absodeg(cdar ld);
% while l and (caaar l=f) and (d=absodeg cdaar l) do
%   <<if dfrel1(ld,car l,vl) then ld:=car l;
%   l:=cdr l>>;
% return cdar ld;
%end;

symbolic procedure ld_deriv(p,f);
%  gets leading derivative of f in p
%  result: derivative + power , e.g. '((DF f x 2 y 3 z) . 3)
begin scalar l;
 return
 if l:=get(p,'derivs) then <<
  while l and (caaar l neq f) do l:=cdr l;
  if l then cons(reval cons('DF,caar l),cdar l)
 >>                   else cons(nil,0)
end;

symbolic procedure ldiffp(p,f);
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ld_deriv_search(p,f,fctargs f);

symbolic procedure ld_deriv_search(p,f,vl);
%  gets leading derivative of function f in expr. p w.r.t
%  list of variables vl
begin scalar a;
if p=f then a:=cons(nil,1)
else
<<a:=cons(nil,0);
if pairp p then
  if member(car p,'(PLUS TIMES QUOTIENT EQUAL)) then
     <<p:=cdr p;
       while p do
	 <<a:=dfmax(ld_deriv_search(car p,f,vl),a,vl);
	   %if cdr a='infinity then p:=nil
	   %                   else
           p:=cdr p
	 >>
     >>
  else if car p='MINUS then a:=ld_deriv_search(cadr p,f,vl)
  else if car p='EXPT then
     <<a:=ld_deriv_search(cadr p,f,vl);
       if numberp cdr a then
	  if numberp caddr p
	  then a:=cons(car a,times(caddr p,cdr a))
	  else if not zerop cdr a
	    then a:=cons(nil,'infinity)
	    else if not my_freeof(caddr p,f)
	            then a:=cons(nil,'infinity)
     >>
  else if car p='DF then
	   if cadr p=f then a:=cons(cddr p,1)
	   else if my_freeof(cadr p,f)
		then a:=cons(nil,0)                       %  a constant
		else a:=cons(nil,'infinity)
  else if my_freeof(p,f) then a:=cons(nil,0)
  else if member(car p,ONE_ARGUMENT_FUNCTIONS_) then
           a:=cons(car ld_deriv_search(cadr p,f,vl),'infinity)
  else a:=cons(nil,'infinity)
>>;
return a
end;

symbolic procedure lderiv(p,f,vl);
%  fuehrende Ableitung in LISP-Notation mit Potenz (als dotted pair)
begin scalar l;
l:=ld_deriv_search(p,f,vl);
return cons(if car l then cons('DF,cons(f,car l))
		  else if zerop cdr l then nil
			  else f
		,cdr l)
end;

symbolic procedure splitinhom(q,ftem,vl);
% Splitting the equation q into the homogeneous and inhom. part
% returns dotted pair qhom . qinhom
begin scalar qhom,qinhom,denm;
  vl:=varslist(q,ftem,vl);
  if pairp q and (car q = 'QUOTIENT) then
  if starp(smemberl(ftem,caddr q),length vl) then
  <<denm:=caddr q; q:=cadr q>>               else return (q . 0)
                                     else denm:=1;

  if pairp q and (car q = 'PLUS) then q:=cdr q
				 else q:=list q;
  while q do <<
   if starp(smemberl(ftem,car q),length vl) then qinhom:=cons(car q,qinhom)
      	       	     	      	            else qhom  :=cons(car q,qhom);
   q:=cdr q
  >>;
  if null qinhom then qinhom:=0
		 else
  if length qinhom > 1 then qinhom:=cons('PLUS,qinhom)
		       else qinhom:=car qinhom;
  if null qhom then qhom:=0
	       else
  if length qhom   > 1 then qhom:=cons('PLUS,qhom)
		       else qhom:=car qhom;
  if denm neq 1 then <<qhom  :=list('QUOTIENT,  qhom,denm);
                       qinhom:=list('QUOTIENT,qinhom,denm)>>;
  return qhom . qinhom
end;

symbolic procedure search_den(l);
% get all denominators and arguments of LOG,... anywhere in a list l
begin scalar l1;
if pairp l then
 if car l='quotient then
  l1:=union(cddr l,union(search_den(cadr l),search_den(caddr l)))
 else if member(car l,'(log ln logb log10)) then
  if pairp cadr l and (caadr l='QUOTIENT) then
   l1:=union(list cadadr l,search_den(cadr l))
  else l1:=union(cdr l,search_den(cadr l))
 else l1:=union(search_den(car l),search_den(cdr l));
 return l1;
end;

symbolic procedure zero_den(l,ftem);
% l is in prefix form, each element of the returned list cases is in SQ-form
begin scalar cases,carl;
 l:=search_den(l);
 while l do <<
  carl:=simp car l;
  if null can_not_become_zeroSQ(carl,ftem)
%  if not freeofzero(car l,ftem,vl,ftem)
  then cases:=cons(carl,cases);
  l:=cdr l
 >>;
 return cases
end;

symbolic procedure forg_int(forg,fges);
for each ex in forg collect
 if pairp ex and pairp cadr ex then forg_int_f(ex,smemberl(fges,ex))
                               else ex;

symbolic procedure forg_int_f(ex,fges);
% try to integrate expr. ex of the form df(f,...)=p .
begin scalar p,h,f;
 p:={'!*SQ,caddr ex,t};
 f:=cadadr ex;
 if pairp p and (car p='PLUS)
    then p:=reval cons('PLUS,cons(list('MINUS,cadr ex),cdr p))
    else p:=reval list('DIFFERENCE,p,cadr ex);
 p:=integratepde(p,cons(f,fges),nil,nil,nil);
 if p and (car p) and not cdr p then
    <<h:=car lderiv(car p,f,fctargs f);
    p:=reval list('PLUS,car p,h);
    for each ff in fnew_ do
      if not member(ff,ftem_) then ftem_:=fctinsert(ff,ftem_);
    ex:=list('EQUAL,h,p)>>;
 return ex
end;

%symbolic operator total_alg_mode_deriv;
%symbolic procedure total_alg_mode_deriv(f,x);
%begin scalar tdf$ %,u,uli,v,vli;
% tdf:={'DF,f,x};
%% explicit program for chain rule of differentiation which is not used
%% as currently f=f(u), u=u(x) gives df(f**2,x)=2*f*df(f,x)
%%
%% for each u in depl!* do
%% if not freeof(cdr u,x) then uli:=cons(car u,uli);
%% for each u in uli do <<
%%  vli:=nil;
%%  for each v in depl!* do
%%  if not freeof(cdr v,u) then vli:=cons(car v,vli);
%%  algebraic ( tdf:=tdf+df(f,v)*df(v,u)*df(u,x) );
%% >>;
% return reval tdf
%end;

put('total_alg_mode_deriv,'psopfn,'tot_alg_deri);
symbolic procedure tot_alg_deri(inp);
begin scalar s;
 return
 {'!*SQ,diffsq(<<s:=aeval car inp;
          if pairp s and (car s='!*SQ) then cadr s
                                       else simp s>>,reval cadr inp),t}
end;

symbolic procedure no_of_v(v,l);
% v is a variable name, l a list of derivatives like (x 2 y z 3)
% it returns the order of v-derivatives
<<while l and car l neq v do l:=cdr l;
  if null l then 0 else
  if null cdr l or not fixp cadr l or (cadr l = 1) then 1 else
  cadr l
>>;

symbolic procedure multiple_diffsq(p,h);
% multiple differentiation of p in sq-form eg. wrt h=(x 2 y)
begin scalar v,m,n;
 while h do <<
  v:=car h$  h:=cdr h;
  v:=mvar car mksq(v,1);
  if null h then n:=1 else
  if fixp car h then <<n:=car h; h:=cdr h>> else n:=1;
  for m:=1:n do p:=diffsq(p,v)
 >>;
 return p
end;

symbolic procedure cp_sq2p_val(p);
if null get(p,'pval) then put(p,'pval,prepsq get(p,'sqval));

%symbolic procedure cp_p2sq_val(p);
% % if ever needed then it should also assign 'fac
%put(p,'sqval,simp get(p,'pval));

symbolic procedure sqzerop(p);
% p is recognized as zero if p=0 or (nil . 1) or (0 . 1) or {!*SQ,(nil . 1),t}
% and NOT if p=nil (because atom nil = t and zerop nil = nil.
if atom p then zerop p else
if  car p neq '!*SQ then null  numr p or
                         zerop numr p
                    else null numr cadr p or
                         (domainp caadr p and not atom caadr p and
                          apply1(get(car caadr p,'zerop),caadr p));

%symbolic procedure sqzerop(p);
%% p is recognized as zero if p=0 or (nil . 1) or (0 . 1) or {!*SQ,(nil . 1),t}
%% and NOT if p=nil (because atom nil = t and zerop nil = nil.
%if atom p then zerop p else
%if  car p neq '!*SQ then null  numr p or
%                         zerop numr p
%                    else null numr cadr p or
%                         (dmode!* and domainp caadr p and
%                          apply(get(dmode!*,'zerop),list caadr p));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  general purpose procedures  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure memberl(a,b);
%  member for a list
if a and b then
if member(car a,b) then cons(car a,memberl(cdr a,b))
                   else memberl(cdr a,b);

symbolic procedure smemberl(fl,ex);
%  smember for a list
if fl and ex then
if smember(car fl,ex) then cons(car fl,smemberl(cdr fl,ex))
                      else smemberl(cdr fl,ex);

symbolic operator my_freeof;
symbolic procedure my_freeof(u,v);
%  a patch for FREEOF in REDUCE 3.5
not(smember(v,u)) and freeofdepl(depl!*,u,v);

lisp flag('(my_freeof),'BOOLEAN);

symbolic procedure freeoflist(l,m);
%   liefert t, falls kein Element aus m in l auftritt
if null m then t
else if freeof(l,car m) then freeoflist(l,cdr m)
                        else nil;

symbolic procedure freeofdepl(de,u,v);
if null de then t
else if smember(v,cdar de) and smember(caar de,u) then nil
else freeofdepl(cdr de,u,v);

symbolic procedure fctins(f,flen,ftem);
if null ftem then list f else
if fctlength car ftem < flen then cons(f,ftem)
else cons(car ftem,fctinsert(f,cdr ftem));

symbolic procedure fctinsert(f,ftem);
% isert a function f in the function list ftem
if freeof(ftem,f) then fctins(f,fctlength f,ftem)
                  else ftem;

symbolic procedure newfct(id,l,nfct);
begin scalar f;
 % Only in the top level function names may be recycled otherwise
 % name clashes occur when passing back solutions with new functions
 % of integration but old used names
 if (null level_) and (id=fname_) and recycle_fcts then <<
  f:=car recycle_fcts;
  recycle_fcts:=cdr recycle_fcts
 >>                              else
 f:=mkid(id,nfct);
 depl!*:=delete(assoc(f,depl!*),depl!*);
 %put(f,'simpfn,'simpiden);
 %if pairp l then f:=cons(f,l);
 if pairp l then depl!*:=cons(cons(f,l),depl!*);
 if print_ then
   <<terpri();
   if pairp l then
     <<write "new function: ";
     fctprint list f>>
   else
     write "new constant: ",f>>;
 return f;
end;

symbolic procedure drop_fct(f);
% check before that f is not one of the forg functions!
% check dropping f also from ftem_
<<if do_recycle_fnc then recycle_fcts:=f . recycle_fcts;
  depl!*:=delete(assoc(reval f,depl!*),depl!*)
>>;

symbolic procedure varslist(p,ftem,vl);
begin scalar l;
ftem:=argset smemberl(ftem,p);
for each v in vl do
  if not my_freeof(p,v) or member(v,ftem) then l:=cons(v,l);
return reverse l;
end;

symbolic procedure var_list(pdes,forg,vl);
begin scalar l,l1;
for each p in pdes do l:=union(get(p,'vars),l);
for each v in vl do
  if member(v,l) or not my_freeof(forg,v) then l1:=cons(v,l1);
return reverse l1;
end;

symbolic procedure f_update(pdes,forg);
begin scalar fdrop,p,f;
 fdrop:=ftem_;
 for each p in pdes do fdrop:=setdiff_according_to(fdrop,get(p,'fcts),ftem_);
 for each f in ftem_ do if not freeof(forg,f) then fdrop:=delete(f,fdrop);
 if fsub_ then
 for each f in ftem_ do if not freeof(fsub_,f) then fdrop:=delete(f,fdrop);
 %% The following test is dropped because there could be functions to be
 %% computed which do not turn up in any equation.
 % for each f in forg do
 %     if not pairp f and not member(f,ftem_) then
 %     <<p:=0$ write"***** ERROR: forg not in ftem_ !!!"$1/p>>;
 for each f in fdrop do drop_fct(f);
 flin_:=setdiff_according_to(flin_,fdrop,ftem_);
 ftem_:=setdiff_according_to(ftem_,fdrop,ftem_)
end;

symbolic operator fargs;
symbolic procedure fargs f;
cons('LIST,fctargs if pairp f and car f='!*SQ then reval f else f);

symbolic procedure fctargs f;
%  arguments of a function
if (f:=assoc(f,depl!*)) then cdr f;

symbolic procedure fctlength f;
%  number of arguments
length fctargs f;

symbolic procedure fctsort(l);
% list sorting
begin scalar l1,l2,l3,m,n;
return
if null l then nil
else
<<n:=fctlength car l;
  l2:=list car l;
  l:=cdr l;
  while l do
   <<m:=fctlength car l;
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2);
   l:=cdr l>>;
  append(fctsort reversip l3,append(reversip l2,fctsort reversip l1))>>
end;

symbolic procedure listprint(l);
%   print elements of a lisp list
if pairp l then <<
 prin1 car l;
 for each v in cdr l do <<prin2 ","$prin1 v>>
>>;

symbolic procedure fctprint1(f);
%   print a function
begin scalar vl;
if f then
 if pairp f then <<
  write car f;
  if pairp cdr f then <<
   for each a in vl_ do
   if not freeof(cdr f,a) then vl:=cons(a,vl);
   write "(";
%   listprint cdr f;
   listprint append(setdiff(cdr f,vl),reverse vl);
   write ")">>
  >>
 else write f;
end;

symbolic procedure fctprint(fl);
%  printing the functions of the lisp list fl of elements:
%  - {EQUAL,f,...} where the rhs is in prefix or {'!*SQ,..,t} form or
%  - f           or
%  - {f,x,y,z}
begin scalar l,f,a,n,nn;
  n:=0;
  while fl do <<
    f:=car fl;
    fl:=cdr fl;
    if pairp f then
      if car f='EQUAL then <<
        n:=if (pairp caddr f) and
              (car caddr f='!*SQ) then no_of_tm_sq cadr caddr f
                                  else no_of_terms      caddr f;
        if (null print_) or (n>print_) then <<
          terpri()$write cadr f,"= expr. with ",n," terms";
          if (l:=get(cadr f,'fcts)) then <<write " in "$myprin2l(l,", ")>>;
          terpri()
        >>
        else mathprint f$     % not too long
        n:=0
      >>              else << % pairp but not {'EQUAL,...}
        if n = 4 then <<terpri()$n:=0>>$  % i.e. 4 in a row
        fctprint1 f;
        if fl then write ", ";
        n:=add1 n
      >>
    else <<                   % not pairp
      nn:=reval {'PLUS,4,length explode f,
                 for each a in fctargs f sum add1 length explode a};
      if nn+n > 79 then <<terpri()$n:=0>>;
      l:=assoc(f,depl!*);
      fctprint1 if l then l
                     else f;
      if fl then write ", ";
      n:=nn+n
    >>
  >>;
end;

symbolic procedure fctprint_SQ(fl);
%  printing the functions of the lisp list fl of elements:
%  - {EQUAL,f,...} where the rhs is in SQ form or
%  - f                                         or
%  - {f,x,y,z}
begin scalar l,f,a,n,nn;
  n:=0;
  while fl do <<
    f:=car fl;
    fl:=cdr fl;
    if pairp f then
      if car f='EQUAL then <<
        n:=no_of_tm_sq caddr f;
        if (null print_) or (n>print_) then <<
          terpri()$write cadr f,"= expr. with ",n," terms";
          if (l:=get(cadr f,'fcts)) then <<write " in "$myprin2l(l,", ")>>;
          terpri()
        >>                             else % not too long
        mathprint {'EQUAL, cadr f,
                   if null numr caddr f then 0
                                        else{'!*SQ,caddr f,t}};
        n:=0
      >>              else <<                 % pairp but not {'EQUAL,...}
        if n = 4 then <<terpri()$n:=0>>$  % i.e. 4 in a row
        fctprint1 f;
        if fl then write ", ";
        n:=add1 n
      >>
    else <<                                   % not pairp
      nn:=reval {'PLUS,4,length explode f,
                 for each a in fctargs f sum add1 length explode a};
      if nn+n > 79 then <<terpri()$n:=0>>;
      l:=assoc(f,depl!*);
      fctprint1 if l then l
                     else f;
      if fl then write ", ";
      n:=nn+n
    >>
  >>;
end;

symbolic operator fdep;
symbolic procedure fdep(fl);
% fl is an algebraic list of function names. fdep prints their dependencies
begin scalar l,f;
 terpri();
 fl:=cdr reval fl;
 while fl do <<
  f:=car fl; fl:=cdr fl;
  l:=assoc(f,depl!*);
  write f;
  if l and cdr l then <<write"="$fctprint1 if l then l else f>>;
  if fl then write ", "
 >>;
 terpri()
end;

symbolic procedure deprint(l);
%   Ausdrucken der Gl. aus der Liste l
if l and print_ then for each x in l do eqprint list('EQUAL,0,x);

symbolic procedure eqprint(e);
%  Ausdrucken der Gl. e
%  e must be in prefix form or {'!*sq, .. ,t} form
if print_ then
begin scalar n;
 n:=if not pairp e then 1 else
    if (car e =  '!*SQ) then delengthSQ cadr e else
    if (car e = 'EQUAL) then if not pairp caddr e then 1 else
                             if (caaddr e = '!*SQ) then delengthSQ cadr caddr e
                                                   else delength        caddr e
                        else delength e;
 if n>print_ then
        <<write %"expr. with ",
                n," factors in ",
    if not pairp e then 1 else
    if (car e =  '!*SQ) then no_of_tm_sq cadr e else
    if (car e = 'EQUAL) then if not pairp caddr e then 1 else
                             if (caaddr e = '!*SQ) then no_of_tm_sq cadr caddr e
                                                   else no_of_terms      caddr e
                        else no_of_terms e,
                " terms";
          terpri()
        >>   else
 if sqzerop e then mathprint 0 else
 if pairp e and
    car e='EQUAL and
    sqzerop caddr e then mathprint {'EQUAL,cadr e,0}
                    else mathprint e;
end;

symbolic procedure print_level(mode);
if print_ and level_ then <<
 terpri();
 if mode=2 then write "New level :     " else
 if mode=1 then write "Current level : " else
                write "Back to level : ";
 for each m in reverse level_ do write m,".";
 terpri()
>>;

symbolic procedure start_level(n,new_assumption);
<<level_:=cons(n,level_);
  CaseTree(if null new_assumption then {nil} % simply nil would mean
                                             % that a case is finished
                                  else new_assumption);
  print_level(2);
  if size_watch and not fixp size_watch then % otherwise avoid growth
  history_:=cons(bldmsg("%w%w","Start of level ",level_string(nil)),
                 cons('ig,history_));
  if size_watch then size_hist:=cons({'A,"Start of ",reverse level_,
                                      new_assumption},size_hist);
>>;

symbolic procedure finish_level(no_of_sol);
begin scalar s;
 delete_backup();
 CaseTree(no_of_sol);
 if size_watch and not fixp size_watch then <<% otherwise avoid growth
  s:=level_string(nil);
  s:=bldmsg("End of level %w, %d solution(s)",s,no_of_sol);
  history_:=cons(s,cons('ig,history_))
 >>;
 level_:=cdr level_;
 print_level(0);
 if size_watch then
 size_hist:=cons({'Z,"Back to ",reverse level_,no_of_sol},size_hist);
 % change switches back
 s:=switch_list;
 while s do <<
  if length car s > length level_ then << % switch back
   if caddar s then on1  cadar s
               else off1 cadar s;
   s:=cdr s;
   switch_list:=cdr switch_list
  >>                              else s:=nil
 >>
end;

symbolic procedure print_statistic(pdes,fcts);
if print_ then begin
 integer j,k,le,r,s;
 scalar n,m,p,el,fl,vl,pl,st;

 %--- printing the stats of equations:
 if pdes then <<
  if equations_file neq "" then <<
   terpri()$write"equations read from disk : ",eqn_no;
   st:="     ";
  >>                       else
  if null lin_problem then st:="     "
                      else st:="";
  terpri()$write "number of equations ",st,": ",length pdes;
  if null lin_problem then <<
   j:=0;
   for each p in pdes do
   if get(p,'linear_) then j:=add1 j;
   terpri()$write "number of lin. equations : ",j;
  >>;
  terpri()$write "total no of terms   ",st,": ",
  j:=for each p in pdes sum get(p,'terms);
  k:=for each p in pdes sum get(p,'length);
  if k neq j then <<terpri();
  write          "total no of factors ",st,": ",k>>;
  while pdes do <<
   j:=0;
   el:=nil;
   for each p in pdes do <<
    vl:=get(p,'vars);
    if vl then le:=length vl
          else le:=0;
    if ((j=0) and null vl) or
       (j=le) then el:=cons(p,el)
              else if j<le then <<
     j:=le;
     el:=list(p)
    >>
   >>;
   pdes:=setdiff(pdes,el);
   if el then <<
    n:=length el;
    terpri()$write n," equation";
    if n>1 then write"s"$write" in ",j," variable";
    if j neq 1 then write"s";
    write": ";

    if struc_eqn then el:=sort_deriv_pdes(el);
    repeat <<
     if struc_eqn then <<
      pl:=first el; el:=cdr el;
      terpri();
      write length cdr pl," equations with ",car pl," derivative",
            if car pl = 1 then ":" else "s:";
      pl:=cdr pl
     >>           else <<pl:=el;el:=nil>>;
     terpri();
     k:=0;
     while pl do <<
      if (k geq 70) then <<k:=0;terpri()>>;
      k:=k+4+length explode car pl + length explode get(car pl,'terms);
      write car pl,"(",get(car pl,'terms);
      if (s:=get(car pl,'starde)) then <<
       for r:=1:(1+cdr s) do write"*";
       k:=k+1+cdr s;
      >>;
      if pairp get(car pl,'fac) then write"#";
      if get(car pl,'case2sep) then write"!";
      if flin_ and get(car pl,'allvarfcts) and
         freeoflist(get(car pl,'allvarfcts),flin_) then write"a";
      if null lin_problem and get(car pl,'linear_) then write"l";
      write")";
      pl:=cdr pl;
      if pl then write",";
     >>;

    >> until null el;

   >>;
   j:=add1 j;
  >>
 >>
 else <<terpri()$write "no equations">>;
 %--- printing the stats of functions:
 for each f in fcts do if not pairp f then fl:=cons(f,fl);
 for each f in fsub_ do fl:=delete(car f,fl);

 if fl then <<
  fl:=fctsort fl;
  m:=fctlength car fl;
  while m>=0 do <<
   n:=0;
   el:=nil;
   while fl and (fctlength car fl=m) do <<
    n:=add1 n;
    el:=cons(car fl,el);
    fl:=cdr fl
   >>;
   if n>0 then
   if m>0 then <<
    terpri();
    write n," function";
    if n>1 then write"s";
    write" with ",m," argument",if m>1 then "s : "
                                       else "  : "
   >>     else <<
    terpri();
    write n," constant";
    if n>1 then write"s";
    write" : "
   >>;
   k:=0;
   el:=sort_according_to(el,ftem_);
   while el do <<
    if k=10 then <<k:=0;terpri()>>
            else k:=add1 k;
    write car el;
    el:=cdr el;
    if el then write",";
   >>;
   m:=if fl then fctlength car fl
            else -1
  >>
 >>    else <<terpri()$write "no functions or constants">>;
 terpri();
end;

symbolic procedure get_statistic(pdes,fcts);
 % returns:    {stepcounter_,
 %              time(),
 %              number of remaining unknowns,
 %              number of pdes,
 %              number of terms,
 %              total length of pdes,
 %              last_free_cells
 %           %   {{no of eq, no of var in eq}, ...}
 %           %   {{no of fc, no of var in fc}, ...}
 %             }
if contradiction_ then "contradiction" else
begin
 integer j,le;
 scalar n,p,el,fl,vl,li,stats;

 stats:={last_free_cells,
         for each p in pdes sum get(p,'length),
         for each p in pdes sum get(p,'terms),
         length pdes,
         length ftem_,
         time(),
         stepcounter_};

 if null vl_ then return reverse stats;

 %--- the statistics of equations:
 while pdes do <<
  % j is number of variables and el the list of equations
  j:=0;
  el:=nil;
  for each p in pdes do <<
   vl:=get(p,'vars);
   if vl then le:=length vl
         else le:=0;
   if ((j=0) and null vl) or
      (j=le) then el:=cons(p,el)
             else if j<le then <<
    j:=le;
    el:=list(p)
   >>
  >>;
  pdes:=setdiff(pdes,el);
  li:=cons({length el,j},li)
  % length el equations in j variables
 >>;
 stats:=cons(li,stats);
 li:=nil;

 %--- the statistics of functions:
 for each f in fcts do if not pairp f then fl:=cons(f,fl);
 if fl then <<
  fl:=fctsort reverse fl;
  j:=fctlength car fl;
  while j>=0 do <<
   n:=0;
   while fl and (fctlength car fl=j) do <<n:=add1 n$ fl:=cdr fl>>;
   li:=cons({n,j},li);
   % n functions of j variables
   j:=if fl then fctlength car fl
            else -1
  >>
 >>;
 stats:=cons(li,stats);

 return reverse stats
end;

symbolic procedure sort_deriv_pdes(pdes);
begin scalar max_no_deri,cp,pl,res;
 max_no_deri:=0;
 cp:=pdes;
 while cp do <<
  if get(car cp,'no_derivs)>max_no_deri then
  max_no_deri:=get(car cp,'no_derivs);
  cp:=cdr cp
 >>;
 repeat <<
  pl:=nil;
  cp:=pdes;
  while cp do <<
   if get(car cp,'no_derivs)=max_no_deri then pl:=cons(car cp,pl);
   cp:=cdr cp
  >>;
  if pl then res:=cons(cons(max_no_deri,reverse pl),res);
  pdes:=setdiff(pdes,pl);
  max_no_deri:=if zerop max_no_deri then nil
                                    else sub1(max_no_deri);
 >> until (null max_no_deri) or (null pdes);
 return res
end;

symbolic procedure print_pdes(pdes);
% print all pdes up to some size
begin scalar pl,n,pdecp;
  terpri();
  if pdes then <<
   if (null !*batch_mode) and
      (batchcount_<stepcounter_) and
      (cdr pdes) then << % if more than one pde
    n:=1000000000;
    if nil then
    repeat <<
     write"What is the maximal number of terms of equations to be shown? ";
     change_prompt_to "";
     terpri()$n:=termread();
     restore_interactive_prompt()
    >> until fixp n;
    for each pl in pdes do
    if get(pl,'terms)<=n then pdecp:=cons(pl,pdecp);
    pdecp:=reverse pdecp;
   >>          else pdecp:=pdes;

   write "equations : ";
   if struc_eqn then <<
    pl:=sort_deriv_pdes(pdecp);
    while pl do <<
     terpri();
     write length cdar pl," equations with ",caar pl," derivatives:";
     typeeqlist(cdar pl);
     pl:=cdr pl
    >>
   >>           else typeeqlist(pdecp)
  >>      else <<write "no equations"$ terpri()>>;
end;

symbolic procedure print_ineq(ineqs);
% print all ineqs where ineqs=(ineq_ . ineq_or)
begin scalar a,b,c,d,h;
 terpri();
 if car ineqs then <<
  terpri()$write "Non-vanishing expressions: ";
  for each a in car ineqs do
  if no_number_atom_SQ a then c:=cons(mvar numr a,c)
                         else b:=cons({'!*SQ,a,t},b);
  listprint c;terpri();
  for each a in b do eqprint a
 >>;
 if cdr ineqs then <<
  terpri()$write "Lists with at least one non-vanishing sub-list ";
  terpri()$write "(ie. a sub-list of which no element vanishes.): "$terpri();
  for each a in cdr ineqs do <<
   write"{"$             % a is an or-inequality
   for each h in a do << % h is a potentially non-vanishing expression, i.e. list of factors
    write"{";

    c:=nil; b:=nil;
    for each d in h do   % b,c will be lists of factors of h
    if no_number_atom_SQ d then c:=cons(mvar numr d,c)
                           else b:=cons({'!*SQ,d,t},b);
    listprint c;

    if not null b then <<
     if c then <<write","$terpri()>>;
     for each d in b do eqprint d
    >>;
    write"}"$%terpri();
   >>$    % of for each h
   write"}"$terpri();
  >>     % of for each a
 >>     % of cdr ineqs
end;

symbolic procedure print_fcts(pdes,fcts);
% print all fcts that are not evaluated as something and prints vars
begin scalar dflist,dfs,f,p,cp,h,hh,showcoef;

 for each h in fcts do if not pairp h then hh:=cons(h,hh);
 change_prompt_to "";

 fcts:=select_from_list(hh,nil);
 pdes:=select_from_list(pdes,nil);

 write"Do you want to see the coefficients of all derivatives in all equations";
 terpri();
 write"in factorized form which may take relatively much time? y/n";
 terpri();
 repeat
  h:=termread()
 until (h='y) or (h='n);
 if h='n then showcoef:=nil else showcoef:=t;

 restore_interactive_prompt();

 while fcts do
 if pairp car fcts then fcts:=cdr fcts
                   else <<
  f:=car fcts;  fcts:=cdr fcts;
  dflist:=nil;
  for each p in pdes do if not freeof(get(p,'fcts),f) then <<
   dfs:=get(p,'derivs);
   while dfs do <<
    if caaar dfs=f then <<
     cp:=dflist;
     while cp and (caar cp neq caar dfs) do cp:=cdr cp;
     if cdaar dfs then h:=cons('DF,caar dfs)
                  else h:=caaar dfs;
     if showcoef then
     if null cp then dflist:=cons({caar dfs,
                                   {'LIST,p,
                                    err_catch_fac coeffn({'!*SQ,get(p,'sqval),t},h,1)}},dflist)
                else rplaca(cp,cons(caar cp,
                                    cons({'LIST,p,
                                          err_catch_fac coeffn({'!*SQ,get(p,'sqval),t},h,1)},
                                         cdar cp)))
               else
     if null cp then dflist:=cons({caar dfs,p},dflist)
                else rplaca(cp,cons(caar cp,cons(p,cdar cp)))
    >>;
    dfs:=cdr dfs
   >>;
  >>;
  while dflist do <<
   dfs:=car dflist;dflist:=cdr dflist;
   if cdar dfs then h:=cons('DF,car dfs)
               else h:=caar dfs;
   if showcoef then algebraic <<write h,": ",lisp cons('LIST,cdr dfs)>>
               else <<write h,": "$ print cdr dfs$ terpri()>>
  >>;
 >>;
end;

symbolic procedure print_forg(fcts,vl);
% print all fcts and vars
<<if fsub_ then <<
   terpri()$write "Eliminations not yet used for substitutions : "$terpri();
   for each p in fsub_ do algebraic(write lisp car p, " = ",lisp reval cdr p)
  >>;
  if fcts then <<
   terpri()$write "Functions : ";
   fctprint_SQ(fcts)$ terpri();
   write "with ",
   for each p in fcts sum
   if pairp p and (car p = 'EQUAL) then no_of_tm_sq caddr p
                                   else 1                  ," terms";
   terpri();
  >>;
  if vl then <<terpri()$write "Variables : "$ fctprint(vl)>>;
>>;

symbolic procedure print_pde_forg_ineq(pdes,ineqs,fcts,vl);
% print all pdes, ineqs and fcts which if {EQUAL,f,x} have x in SQ-form (forg)
if print_ then begin;
 print_pdes(pdes);
 print_ineq(ineqs);
 print_forg(fcts,vl);
 print_statistic(pdes,fcts)
end;

symbolic procedure no_of_terms(d);
if not pairp d then if (null d) or (zerop d) then 0
                                             else 1 else
if car d='PLUS then length d - 1            else
if car d='EQUAL then no_of_terms(cadr  d) +
                     no_of_terms(caddr d)   else
if (car d='MINUS) or (car d='QUOTIENT) then
   no_of_terms(cadr d)                 else
if car d='EXPT then
if (not fixp caddr d) or (caddr d < 2) then 1 else
% number of terms of (a1+a2+..+an)**r = n+r-1 over r
begin scalar h,m,q;
 m:=no_of_terms(cadr d)-1;
 h:=1;
 for q:=1:caddr d do h:=h*(m+q)/q;
 return h
end            else
if car d='TIMES then begin scalar h,r;
 h:=1;
 for each r in cdr d do h:=h*no_of_terms(r);
 return h
end             else 1;

symbolic procedure no_of_tm_sf s;
% input is a standard form s
% counts no of terms
if null s then 0 else
if (not pairp s) or (not pairp car s) then 1 % an integer number
                                      else
no_of_tm_sf(cdar s)+no_of_tm_sf(cdr s);

symbolic procedure no_of_tm_sf_limited(s,x);
% input is a standard form s
% counts no of terms up to x
if null s then 0 else
if (not pairp s) or (not pairp car s) then 1 % an integer number
                                      else
begin scalar r;
 r:=no_of_tm_sf_limited(cdar s,x);
 return
 if r>x then r
        else r+no_of_tm_sf_limited(cdr s,x)
end;

symbolic procedure more_than_x_terms(s,x);
% input is a standard form s
% it checks whether s includes more than x terms
% counts no of terms until it reaches x
begin scalar y;
 return
 if null s then nil else
 if (not pairp s) or (not pairp car s) then   % 1 term
 if x=0 then t else nil
                                       else <<
  y:=no_of_tm_sf_limited(cdar s,x);
  if y<=x then y:=y+no_of_tm_sf_limited(cdr s,x);
  y>x
 >>
end;

% not used so far:
%symbolic procedure no_of_fac_sf s;
%% input is a standard form s
%% counts no of factors, powers count as one
%if null s then 0 else
%if s eq 1 then 0 else
%if not pairp s then 1 % an integer number
%               else 1+no_of_fac_sf(cdar s)+
%if cdr s eq 1 then 1
%              else no_of_fac_sf(cdr s);

symbolic procedure no_of_tm_sq s;
% input is a standard quotient form s
% counts no of terms
no_of_tm_sf numr s + if denr s = 1 then 0
                                   else no_of_tm_sf denr s;

symbolic procedure no_number_atom_SF(sf);
if pairp sf and
   null red sf and
   lc sf = 1 and
   ldeg sf = 1 and
   null pairp mvar sf then t
                      else nil;

symbolic procedure no_number_atom_SQ(sq);
no_number_atom_SF numr sq;

symbolic procedure one_termpSF(sf);
% returns nil if sf has more than one term
if domainp sf then t else
if red sf then nil else one_termpSF lc sf;

symbolic procedure first_term_SF(sf);
% returns first term of standard form sf in standard form
% (((mvar . ldeg) . lc) . red)  or
% ((    lpow      . lc) . red)
if domainp sf then sf else
{(lpow sf . first_term_SF lc sf)};

symbolic procedure num_term_SF(sf);
% returns purely numerical term of standard form sf if there is one
% (((mvar . ldeg) . lc) . red)  or
% ((    lpow      . lc) . red)
if sf then if domainp sf then sf
                         else num_term_SF red sf;

symbolic procedure lmon_SF(sf);
% returns the leading monomial of standard form sf in standard form
% (((mvar . ldeg) . lc) . red)  or
% ((    lpow      . lc) . red)
if domainp sf then 1 else
{(lpow sf . lmon_SF lc sf)};

symbolic procedure nco_SQ(h);
% returns the numerical coefficient of the leading term
% of the standard quotient h
begin scalar d;
 % h:=cadr aeval h;
 d:=cdr h;
 h:=car h;
 while pairp h and not domainp car h do h:=lc h;
 if pairp h then h:={'QUOTIENT,cadr h,cddr h};
 if d neq 1 then h:={'QUOTIENT,h,d};
 return h
end;

put('numcoeff,'psopfn,'numco)$ % currently (11.6.08) used in sstools
symbolic procedure numco(h);
% returns the numerical of the first term of the expression h
begin
 h:=car cadr aeval car h;
 while pairp h and not domainp car h do h:=lc h;
 if pairp h then h:={'QUOTIENT,cadr h,cddr h};
 return h
end;

%--------

symbolic procedure mymemq (u , v, v1);
% EQ version of Member
% hard truncating the list in front of the item found
if not pairp v  then nil
   else if eq( u ,car v) then << if v1 then rplacd(v1,nil) ; v>>
   else mymemq(u ,cdr v, v);

%>>>>>>>>>> The normal REDUCE algebraic mode function cons
% converts standard quotient lists into prefix form which to
% convert back into standard quotient form would take very very long
% for large expressions. The new function sqcons returns
% a list of standard quotient expressions.

symbolic procedure sq!*cons(x);
<< 'list .  cons (aeval car x, cdr aeval cadr x)>>;
put('sqcons,'psopfn,'sq!*cons);

%--------
symbolic procedure sq!*length(x);
((length aeval car x) - 1);
put('sqlength,'psopfn,'sq!*length);

%--------
symbolic procedure sq!*rest(x);
<< 'list . cddr aeval car x>>;
put('sqrest,'psopfn,'sq!*rest);

%--------
symbolic procedure sq!*first(x);
cadr aeval car x;
put('sqfirst,'psopfn,'sq!*first);

%--------
symbolic procedure sq!*second(x);
caddr aeval car x;
put('sqsecond,'psopfn,'sq!*second);

%--------
symbolic procedure sq!*third(x);
cadddr aeval car x;
put('sqthird,'psopfn,'sq!*third);

%--------
symbolic procedure sq!*part(x);
% This procedure is only equivalent to part(a,b) if the first
% argument to sqpart is an algebraic list and it the second
% argument is not 0.
begin scalar c1,c2;
 c1:=aeval car x;
 c2:=aeval cadr x;
 return
 if (c2=0) and not pairp c1 then -1
                            else nth(c1,add1 c2);
end;
put('sqpart,'psopfn,'sq!*part);

%--------
symbolic procedure sq!*reverse(x);
<< 'list . reverse cdr aeval car x>>;
put('sqreverse,'psopfn,'sq!*reverse);

%--------
symbolic procedure sq!*append(x);
<< 'list . append(cdr aeval car x,cdr aeval cadr x)>>;
put('sqappend,'psopfn,'sq!*append);

%--------

symbolic procedure delengthSF(d);
% counting all factors, even numbers in the standard form d
if (not pairp d) or (not pairp car d) or (not pairp caar d)
then if domainp d then 0
                  else 1
else ldeg d + delengthSF(lc d) + delengthSF(red d);

symbolic procedure delengthSQ(d);
% counting all factors, even numbers in the standard quotient form
(if numr d = 1 then 0 else delengthSF numr d) +
(if denr d = 1 then 0 else delengthSF denr d)   ;

symbolic procedure delength(d);
%   Laenge eines Polynoms in prefix Form
if not pairp d then
 if d then 1
      else 0
else
if (car d='PLUS) or (car d='TIMES) or (car d='QUOTIENT)
   or (car d='MINUS) or (car d='EQUAL)
   then for each a in cdr d sum delength(a)
else 1;

symbolic procedure pdeweightSF(d,ftem);
% determines the total number of factors of elements of ftem
% in the standard form d which has structure:  (((mvar . ldeg) . lc) . red)
% This version does not count ftem in exponents

if (not pairp d) or (not pairp car d) or (not pairp caar d) then 0 else
if freeoflist(mvar d,ftem) then
         pdeweightSF(lc d,ftem) + pdeweightSF(red d,ftem)
                           else
ldeg d + pdeweightSF(lc d,ftem) + pdeweightSF(red d,ftem);
% assuming that ldeg d is an integer

symbolic procedure pdeweight(d,ftem);
%   Laenge eines Polynoms in LISP - Notation
if not smemberl(ftem,d) then 0
else if not pairp d then 1
else if (car d='PLUS) or (car d='TIMES) or (car d='EQUAL)
        or (car d='QUOTIENT) then
         for each a in cdr d sum pdeweight(a,ftem)
else if (car d='EXPT) then
        if numberp caddr d then
         caddr d*pdeweight(cadr d,ftem)
                           else
        pdeweight(caddr d,ftem)+pdeweight(cadr d,ftem)
else if (car d='MINUS) then pdeweight(cadr d,ftem)
else 1;

symbolic procedure desort(l);
% sort expressions in prefix form hat are the elements of the list l by size
% currently called only once in liepde.red
for each a in idx_sort for each b in l collect cons(delength b,b)
collect cdr a;

symbolic procedure idx_sort(l);
% All elements of l have a numerical first element and are sorted
% by quicksort according to that number, lowest first
if null l then nil else
begin scalar l1,l2,l3,m,n;
 return
 <<n:=caar l;
  l2:=list car l;
  l:=cdr l;
  while l do
   <<m:=caar l;
   if m<n then l1:=cons(car l,l1)
   else if m>n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2);
   l:=cdr l>>;
  append(idx_sort(l1),append(l2,idx_sort(l3)))
 >>
end;

symbolic procedure rev_idx_sort(l);
% All elements of l have a numerical first element and are sorted
% by quicksort according to that number, highest first
if null l then nil else
begin scalar l1,l2,l3,m,n;
 return
 <<n:=caar l;
  l2:=list car l;
  l:=cdr l;
  while l do
   <<m:=caar l;
   if m>n then l1:=cons(car l,l1)
   else if m<n then l3:=cons(car l,l3)
   else l2:=cons(car l,l2);
   l:=cdr l>>;
  append(rev_idx_sort(l1),append(l2,rev_idx_sort(l3)))
 >>
end;

symbolic procedure rat_idx_sort(l);
% All elements of l have a rational number first element
% and are sorted by quicksort according to that number
% The rational number has to be reval-ed !
begin scalar l1,l2,l3,m,n;
return
if null l then nil
else
<<n:=caar l;
  l2:=list car l;
  l:=cdr l;
  while l do
   <<m:=caar l;
   if rational_less(m,n) then l1:=cons(car l,l1)
   else if rational_less(n,m) then l3:=cons(car l,l3)
   else l2:=cons(car l,l2);
   l:=cdr l>>;
  append(rat_idx_sort(l1),append(l2,rat_idx_sort(l3)))>>
end;

symbolic procedure sort_eq_by_length(pdes);
<<largest_fully_shortened:=nil;
  currently_to_be_substituted_in:=nil;
  for each p in
  idx_sort(for each p in pdes collect (get(p,'terms) . p) )
  collect cdr p>>;

symbolic procedure update_eq_sort_by_length(pdes);
% update the list pdes to have a monotonic increase of
% the number of terms
if null pdes or null cdr pdes then pdes else
begin scalar p,q,carpt,cadrpt,cadrp;
 p:=pdes;
 carpt:=get(car p,'terms);
 while cdr p do <<
  cadrpt:=get(cadr p,'terms);
  if carpt<=cadrpt then <<carpt:=cadrpt; p:=cdr p>>
                   else <<
   % take out cadr p
   cadrp:=cadr p;
   rplacd(p,cddr p);
   if cadrpt<=get(car pdes,'terms) then pdes:=cons(cadrp,pdes)
                                   else <<
    q:=pdes;
    while cdr q and (cadrpt>get(cadr q,'terms)) do q:=cdr q;
    % insert cadrp
    rplacd(q,cons(cadrp,cdr q));
   >>
  >>
 >>;
 return pdes
end;

symbolic procedure kernel_sort(l);
% All elements of l are kernels to be sorted by quicksort
if null l then nil else
if null cdr l then l else
begin scalar n,l1,l2;
 return
 <<n:=car l;
  l2:=list n;
  l:=cdr l;
  while l do <<
   if ordp(car l,n) then l1:=cons(car l,l1)
                    else l2:=cons(car l,l2);
   l:=cdr l
  >>;
  %append(kernel_sort(l1),kernel_sort(l2))
  nconc(kernel_sort(l1),kernel_sort(l2)) % should work as l1,l2 are defined locally
 >>
end;

symbolic procedure argset(ftem);
%  List of arguments of all functions in ftem
if ftem then union(reverse fctargs car ftem,argset(cdr ftem))
        else nil;

symbolic procedure no_fnc_of_v;
begin scalar vl,v,nofu,f,nv;
  % How many functions do depend on each variable?
  vl:=argset(ftem_);
  for each v in vl do <<
    nofu:=0;  % the number of functions v occurs in
    for each f in ftem_ do
    if not freeof(fctargs f,v) then nofu:=add1 nofu;
    nv:=cons((v . nofu),nv);
  >>;
  return nv
end;

procedure push_vars(liste);
for each x in liste collect
if not boundp x then x else eval x$ % valuecell x;

symbolic procedure backup_pdes(pdes,forg);
%  returns a list with all data that are passed on to a separate
%  computation and which are not received back, therefore this
%  backup is made.
begin scalar allfl;
 return
 list(push_vars pass_on,
      for each p in pdes collect
      list(p,
           for each q in prop_list collect cons(q,get(p,q)),
           <<allfl:=nil;
             for each q in allflags_ do
             if flagp(p,q) then allfl:=cons(q,allfl);
             allfl>>),
      for each f in forg collect
           if pairp f then cons(f,get(cadr f,'fcts))
                      else cons(f,get(     f,'fcts)),
      for each id in idnties_ collect
      list(id,get(id,'val),flagp(id,'to_int),flagp(id,'to_subst))
     )
end;

%symbolic procedure backup_pdes(pdes,forg);
%%  make a backup of all pdes
%begin scalar cop;
% cop:=list(nequ_,
%           for each p in pdes collect
%               list(p,
%                    for each q in prop_list collect cons(q,get(p,q)),
%                    for each q in allflags_ collect if flagp(p,q) then q),
%           for each f in forg collect
%               if pairp f then cons(cadr f,get(cadr f,'fcts))
%                          else cons(f,get(f,'fcts)),
%           ftem_,
%           ineq_,
%           recycle_ens,
%           recycle_fcts);
% return cop
%end;

symbolic procedure pop_vars(liste,altewerte);
foreach x in liste do <<set (x,car altewerte);
                        altewerte := cdr altewerte>>;

symbolic procedure restore_pdes(bak);
%  restore all data: pass_on, pdes, forg
begin scalar pdes,forg,!*complex_bak;

  % recover values of global variables
  !*complex_bak:=!*complex;
  pop_vars(pass_on,car bak);
  % For some switches it is not enough to set the !*.. value.
  if !*complex_bak and null !*complex then <<
   !*complex:=t;
   algebraic(off complex);
  >>;

  % recover the pdes
  for each c in cadr bak do <<
    pdes:=cons(car c,pdes);
    for each s in cadr  c do put(car c,car s,cdr s);
    for each s in caddr c do flag1(car c,s)
  >>;

  % recover the properties of forg
  for each c in caddr bak do <<
    forg:=cons(car c,forg);
    if pairp car c then put(cadar c,'fcts,cdr c)
  >>;

  % recover the properties of idnties_
  if cdddr bak then
  for each c in cadddr bak do <<
    put(car c,'val,cadr c);
    if caddr c then flag1(car c,'to_int)
               else if flagp(car c,'to_int) then remflag(car c,'to_int);
    if caddr c then flag1(car c,'to_subst)
               else if flagp(car c,'to_subst) then remflag(car c,'to_subst);
  >>;

  UniquifyAll(pdes,forg);

  return {reverse pdes,reverse forg};
end;

symbolic procedure deletepde(pdes);
begin scalar s,l;
 change_prompt_to "";
 terpri();
 write "Equations to be deleted: ";
 l:=select_from_list(pdes,nil);
 restore_interactive_prompt();
 for each s in l do
 if member(s,pdes) then pdes:=drop_pde(s,pdes,nil);
 f_update(pdes,nil);
 return pdes
end;

symbolic procedure new_pde();
begin scalar s;

 if null car recycle_eqns and cdr recycle_eqns then
 clean_prop_list(cdr recycle_eqns);

 if null car recycle_eqns then <<
  s:=mkid(eqname_,nequ_);
  nequ_:=add1 nequ_;
 >>                       else <<
  s:=caar recycle_eqns;
  recycle_eqns:=(cdar recycle_eqns) . (cdr recycle_eqns)
 >>;
 setprop(s,nil);
 return s
end;

symbolic procedure drop_pde_from_properties(p,pdes);
begin
 put(p,'dec_with,nil);
 put(p,'dec_with_rl,nil);
 put(p,'rl_with,nil);
 for each q in pdes do if q neq p then <<
  drop_dec_with(p,q,t);
  drop_dec_with(p,q,nil);
  drop_rl_with(p,q)
 >>
end;

symbolic procedure drop_pde_from_idties(p,pdes,phist);
% to be used whenever the equation p is dropped or changed and
% afterwards newly characterized in update,
% phist is the new value of p in terms of other equations,
% if this is unknown then phist=nil,
% to be done before setprop(p,nil)
begin scalar q,newidval,idnt;
 for each q in pdes do if q neq p then
 if not freeof(get(q,'histry_),p) then
 put(q,'histry_, if null phist then q
                               else subst(phist,p,get(q,'histry_)));

 if record_hist and (getd 'show_id) then <<

  % update of all identities involving p
  idnt:=idnties_;
  while idnt do <<
   if not freeof(get(car idnt,'val),p) then
   if null phist then drop_idty(car idnt)
                                       else <<
    % Once pdes_ is available as global variable then simplify 'val
    % before put()
    newidval:=reval subst(phist,p,get(car idnt,'val));
    if trivial_idty(pdes,newidval) then drop_idty(car idnt)
                                   else <<
     put(car idnt,'val,newidval);
     flag1(car idnt,'to_subst);
     flag1(car idnt,'to_int)
    >>
   >>;
   idnt:=cdr idnt
  >>;

  % adding a new identity based on phist and the 'histry_ entry of p
  if phist and not zerop phist and (p neq get(p,'histry_)) then <<
   idnt:=reval {'PLUS,get(p,'histry_),{'MINUS,phist}};
   if pairp idnt and car idnt='QUOTIENT then idnt:=cadr idnt;
   if not zerop idnt then
   new_idty(idnt,pdes,if pdes then t else nil)
  >>
 >>
end;

symbolic procedure drop_pde(p,pdes,phist);
% phist is the value of p in terms of other equations,
% (this is needed for substitution of p in identities)
% if phist=nil then unknown
% pdes should be a list of all currently used pde-names
if p then begin scalar l;
 if do_recycle_eqn and freeof(car recycle_eqns,p) then
 recycle_eqns:=(car recycle_eqns) . union({p},cdr recycle_eqns);
 depl!*:=delete(assoc(reval p,depl!*),depl!*);
 drop_pde_from_idties(p,pdes,phist);
 setprop(p,nil);
 if (p=largest_fully_shortened) or
    (p=currently_to_be_substituted_in) then
 if (null pdes) or (p=car pdes) then <<
  if p=largest_fully_shortened then
  largest_fully_shortened:=nil;
  if p=currently_to_be_substituted_in then
  currently_to_be_substituted_in:=nil
 >>            else <<
  l:=pdes;
  while cdr l and (p neq cadr l) do l:=cdr l;
  if p=largest_fully_shortened then largest_fully_shortened:=car l;
  if p=currently_to_be_substituted_in then
  currently_to_be_substituted_in:=if cdr l and cddr l then caddr l
                                                      else car l
 >>;
 return delete(p,pdes)
end;

symbolic procedure drop_all_pdes(pdes);
begin scalar p;
 if do_recycle_eqn then
 recycle_eqns:=union(pdes,car recycle_eqns) .
               setdiff(cdr recycle_eqns,pdes);
 for each p in pdes do <<
  depl!*:=delete(assoc(reval p,depl!*),depl!*);
  setprop(p,nil)
 >>;
 % dropping all identities
 while idnties_ do drop_idty(car idnties_)
end;

symbolic procedure change_pde_flag(pdes);
begin scalar p,ty,h;
 terpri()$ write"At first we need the list of equations for which ";
 terpri()$ write"you want to change properties.";
 pdes:=select_from_list(pdes,nil);
 terpri();
 write"Type in one of the following flags that is to be flipped ";
 terpri();
 write"(e.g. to_int <ENTER>): ";
 terpri()$terpri();
 write allflags_;
 terpri()$terpri();
 write"or type in one of the following properties that is to be changed";
 terpri();
 write"(e.g. vars <ENTER>): ";
 terpri()$terpri();
 write prop_list;
 terpri()$terpri();
 change_prompt_to "";
 ty:=termread();
 if member(ty,allflags_) then <<
  terpri()$ write"Shall the flag be set (Y) ";
  terpri()$ write"or be removed ?       (N) ";
  h:=termread();
  for each p in pdes do if h='y then    flag1(p,ty)
                                else remflag1(p,ty)
 >>                      else
 if member(ty,prop_list) then <<
  terpri()$ write"Shall the property list for all equations be set to nil (Y/N) ";
  h:=termread();
  if h='y then for each p in pdes do put(p,ty,nil)
          else for each p in pdes do <<
   terpri();
   write"current value for ",p,": ",get(p,ty);
   terpri();
   write"new value (e.g. (x y z) ENTER): ";
   terpri();
   h:=termread();
   put(p,ty,h);
   write"The new value of ",ty,": ",get(p,ty)
  >>;
  if ty='rl_with then largest_fully_shortened:=nil
 >>                      else write"Input not recognized.";
 terpri();
 restore_interactive_prompt()
end;

symbolic procedure restore_backup_from_file(pdes,forg,nme);
% This procedure restores the pass_on AND the pass_back variables
% from the old session as stored in the backup file. So one should use
% this procedure if nothing should be passed back from the current
% computation, i.e. when the new computation is just a side computation
% which, for example,  does not pass back solutions with newly generated
% functions. If on the other hand newly generated functions,... should
% be passed back then the procedure  restore_and_merge() should be
% called which passes back, i.e. keeps, the pass_back variable values.
begin scalar s,p,echo_bak,semic_bak,flist,n,h,fi,oldsession,old_sol_li;
  if nme=t then <<
   change_prompt_to "";
   terpri();
   write"Please give the name of the file in double quotes"$terpri();
   write"without `;' : ";
   s:=termread();
   restore_input_file()$  % in case
   p:=explode s;
   if member('!*,p) or member('!?,p) then <<
    p := pipe!-open(bldmsg("ls %w",s), 'input);
    fi:="";
    repeat <<
     h:=channelreadchar(p);
     if h  = 10 then <<flist:=cons(fi,flist);fi:="">> else
     if h neq 4 then fi:=bldmsg("%w%w",fi,int2id h)
    >> until h=4;
    if fi neq "" then flist:=cons(fi,flist); % should not occur
    close p;
    if flist then <<
     n:=0;
     p:=flist;
     while p do <<
      n:=add1 n;
      write n,": ",car p$terpri();
      p:=cdr p
     >>;
     terpri();
     write"Indicate the file you want to load by"$terpri();
     write"entering the corresponding number: ";
     p:=termread();
     while (not numberp p) or (p<0) or (p>length flist) do <<
      write"This is not a number >0 and <=",length flist,"! Try again: ";
      p:=termread()
     >>;
     s:=nth(flist,p)
    >>
   >>;
   restore_interactive_prompt()
  >>     else
  if nme then s:=nme
         else s:=level_string(session_);
  %-- infile s;
  if null sol_list % and (stepcounter_=0)
  then <<
    old_sol_li:=bldmsg("%w%w",session_,"sol_list");
    if filep old_sol_li then oldsession:=session_
  >>;
  % to delete the current bu*-sol_list file which has been created
  % when the current session was started

  echo_bak:=!*echo; semic_bak:=semic!*;
  semic!*:='!$; in s;
  !*echo:=echo_bak; semic!*:=semic_bak;
  %-- cleaning up:
  for each p in pdes do setprop(p,nil);
  for each p in forg do if pairp p then put(cadr p,'fcts,nil);
  %-- assigning the new values:
  pop_vars(pass_back,car backup_)$  %1
  uniquifykord kord!*;
  uniquifydepl depl!*;
  uniquifyasymplis asymplis!*;
  if eqn_input and (eqn_input neq 'done) then close eqn_input;
  s:=restore_pdes(cdr backup_)$     %1
  backup_:=nil;
  % orderings_:=car orderings_;
  if oldsession and (oldsession neq session_) then
  delete!-file!-exact old_sol_li;

  return s
end;

symbolic procedure level_string(s);
begin scalar m;
 for each m in reverse level_ do
 setq(s,if s then if fixp m then if m<10 then bldmsg("%w%d",s,m)
                                         else bldmsg("%w.%d.",s,m)
                            else bldmsg("%w%w.",s,m)
             else if fixp m then if m<10 then bldmsg("%d",m)
                                         else bldmsg(".%d.",m)
                            else bldmsg("%w.",m));
 return s
end;

symbolic procedure backup_to_file(pdes,forg,nme);
% saves all data to a file which might have changed since the
% initialization of global variables when loading CRACK
% This includes data which are passed back in a serial
% computation (pass_back) and those not (pass_on)
begin scalar s,a,save,ofl!*bak,!*natbat$ %,levelcp;
  if nme=t then <<
    change_prompt_to "";
    terpri();
    write"Please give the name of the file in double quotes"$terpri();
    write"without `;' : ";
    s:=termread();
    restore_interactive_prompt()
  >>     else
  if nme then s:=nme
         else s:=level_string(session_);
  a := open(s, 'output);
  ofl!*bak:=ofl!*;
  ofl!*:=s$  % any value neq nil, to avoid problem with redfront
  save:=wrs a;
  % The above 2 lines instead of `out s;' allow to return
  % below after `close a;' (instead of `shut a;') to write
  % again automatically to the same file as before
  !*natbat:=!*nat;
  off nat;
  % orderings_:=list orderings_;
  write"off echo$";
  write "backup_:='"$terpri();
  print cons(push_vars pass_back,backup_pdes(pdes,forg))$  %1
  write"$"$terpri();
  write "end$"$terpri();
  wrs save;
  ofl!*:=ofl!*bak;
  close a;
  if !*nat neq !*natbat then on nat
end;

symbolic procedure delete_backup;
begin scalar s;
 % at first delete the bu.. file
 s:=level_string(session_);
 delete!-file!-exact s;

 % then the cd..* files
 s:=explode s;
 s:=reverse cons(car s,cons('*,cdr reverse s));
 s:=cons(car s,cons('c,cons('d,cdddr s)));
 delete!-file!-match compress s;

 % then the ie..* files
 s:=cons(car s,cons('i,cons('e,cdddr s)));
 delete!-file!-match compress s;
end;

symbolic procedure merge_crack_returns(r1,r2);
if (null collect_sol) and
   ((null r1) or (fixp car r1)) and
   ((null r2) or (fixp car r2)) then
if null r1 then r2 else
if null r2 then r1 else list((car r1) + (car r2))
                                else union(r1,r2);

symbolic procedure restore_and_merge(soln,pdes,forg);
% pdes, forg are cleaned up
% one could just use restore_pdes without assigning bak
% but then it would not be stored in a file, such that
% rb can reload the file
begin scalar bak,newfdep,sol,f,h;

 % store ongoing global values in bak
 newfdep:=nil;
 for each sol in soln do
 if pairp sol then <<
   for each f in caddr sol do
   if h:=assoc(f,depl!*) then newfdep:=cons(h,newfdep);
 >>;
 bak:={push_vars pass_back,newfdep};  % to be used 2 lines below
 h:=restore_backup_from_file(pdes,forg,nil);

 % actually merging of depl!* with newfdep need only be done if non-parallel
 pop_vars(pass_back,car bak);

 % actually merging of depl!* with newfdep need only be done if collect_sol=t
 depl!*:=append(depl!*,cadr bak);

 return h
end;

symbolic operator write_stat_in_file;
symbolic procedure write_stat_in_file;
if null size_watch then <<
 write"No statistical history is recorded."$terpri();
 write"To record one enter: as {size_watch,t};"$terpri();
>>                 else
begin scalar s;
 change_prompt_to "";
 setq(s,bldmsg("%w.%w",session_,"size_hist"));
 out s;
 write"size_hist:='";
 prettyprint size_hist;
 write"$end$"$terpri();
 shut s;
 restore_interactive_prompt()
end;

symbolic procedure write_in_file(pdes,forg);
begin scalar p,pl,s,h,wn,vl,v,ll;
  ll:=linelength 79;
  change_prompt_to "";
  terpri();
  write "Enter a list of equations, like e2,e5,e35; from: "$terpri();
  listprint(pdes);
  terpri()$write "To write all equations just enter ; "$terpri();
  repeat <<
    s:=termlistread();
    h:=s;
    if s=nil then pl:=pdes else <<
      pl:=nil;h:=nil;
      if (null s) or pairp s then <<
        for each p in s do
        if member(p,pdes) then pl:=cons(p,pl);
        h:=setdiff(pl,pdes);
      >> else h:=s;
    >>;
    if h then <<write "These are no equations: ",h,"   Try again."$terpri()>>;
  >> until null h;
  write"Shall the name of the equation be written? (y/n) ";
  repeat s:=termread()
  until (s='y) or (s='Y) or (s='n) or (s='N);
  if (s='y) or (s='Y) then wn:=t;
  write"Please give the name of the file in double quotes"$terpri();
  write"without `;' : ";
  s:=termread();
  out s;
  off nat;

  write"% Modify the following load command by adding the"$terpri();
  write"% directory name in which crack is stored, for example:"$terpri();
  write"% load ""~/crack/crack""$"$terpri();
  write"load crack$"$terpri();
  write"lisp(nfct_:=",nfct_,")$"$terpri();
  if wn then write"lisp(nequ_:=",nequ_,")$"$terpri();
  write"off batch_mode$"$terpri();
  for each p in pl do <<h:=get(p,'vars);if h then vl:=union(h,vl)>>;
  write"list_of_variables:=";
  algebraic write lisp cons('LIST,vl);

  write"list_of_functions:=";
  algebraic write lisp cons('LIST,ftem_);

  if flin_ then <<
   write"% linearly occuring functions:"$terpri();
   write"lisp(flin_:='("$terpri();
   for each h in flin_ do <<write h$terpri()>>;
   write"))$"$terpri()
  >>;

  if fhom_ then <<
   write"% homogeneous functions:"$terpri();
   write"lisp(fhom_:='("$terpri();
   for each h in fhom_ do <<write h$terpri()>>;
   write"))$"$terpri()
  >>;

  for each h in ftem_ do
  if assoc(h,depl!*) then <<
%    p:=pl;
%    while p and freeof(get(car p,'sqval),h) do p:=cdr p;
%    if p then <<
     % The above 3 lines make only sense if get(p,'fcts) is not accurate
      write "depend ",h;
      for each v in cdr assoc(h,depl!*) do <<write ","$print v>>;
      write "$"$terpri();
%    >>
  >>;
  if wn then <<
    for each h in pl do algebraic (write h,":=",lisp {'!*SQ,get(h,'sqval),t});
    write"list_of_equations:=";
    algebraic write lisp cons('LIST,pl)
  >>    else <<
    write"list_of_equations:=";
    algebraic write lisp cons('LIST,
       for each h in pl collect {'!*SQ,get(h,'sqval),t});
  >>;

  write"list_of_inequalities:=";
  algebraic write lisp(
   cons('LIST,append(for each p in ineq_ collect {'!*SQ,p,t},
                     if null ineq_or then nil else
                     for each h in ineq_or collect
                          cons('LIST,for each p in h collect
                                     {'!*SQ,if null cdr p then car p else
                                            <<v:=car p; p:=cdr p;
                                              while p do<<v:=multsq(v,car p);
                                                          p:= cdr p>>;
                                              v>>
                                           ,t}))
       )              );

  terpri()$ write"solution_:=crack(list_of_equations,";
  terpri()$ write"                 list_of_inequalities,";
  terpri()$ write"                 list_of_functions,";
  terpri()$ write"                 list_of_variables)$";
  terpri();

  for each h in forg do <<
   if pairp h and (car h = 'EQUAL) then <<
    terpri();
    algebraic
    write lisp(cadr  h)," := sub(second first solution_,",
          lisp({'!*SQ,caddr h,t}),")"
   >>
  >>;
  terpri();
  write"end$"$terpri()$terpri();
  write"These data were produced with the following input:"$terpri()$terpri();
  write"lisp( old_history := "$terpri();
  write"'",reverse history_,")$"$terpri();
  shut s;
  on nat;
  restore_interactive_prompt();
  linelength ll
end;


symbolic procedure give_low_priority(pdes,f);
% It assumes that
% - f is in prefix form (f is just an atom),
% - f is element of ftem_,
% - flin_ functions come first in each group of functions with
%   the same number of independent variables.
% If f is element of flin_ then f is put at the end of the flin_
% functions with equally many variables but before the first functions
% that occur in ineq_ in order to change ftem_ as little as possible
% not to invalidate previous decoupling.

begin scalar ftemcp,ano,h,s,fli;
 ftemcp:=ftem_;
 while ftemcp and (car ftemcp neq f) do <<
  h:=cons(car ftemcp,h);
  ftemcp:=cdr ftemcp
 >>;
 % Is there an element of the remaining ftemcp with the same no of
 % variables and that is not in ineq_ ?

 if ftemcp then <<
  ftemcp:=cdr ftemcp;
  ano:=fctlength f;
  if member(f,flin_) then fli:=t;
  while ftemcp do
  if (ano > (fctlength car ftemcp)) or
     (fli and (not member(car ftemcp,flin_))) then ftemcp:=nil else <<
   h:=cons(car ftemcp,h);
   ftemcp:=cdr ftemcp;
   if not member(simp car h,ineq_) then <<
    while ftemcp and
          (ano = (fctlength car ftemcp)) and
          (not member(simp car ftemcp,ineq_)) and
          ((not fli) or member(car ftemcp,flin_)) do <<
     h:=cons(car ftemcp,h);
     ftemcp:=cdr ftemcp
    >>;

    if print_ or tr_orderings then <<
     write"The lexicographical ordering of unknowns is changed";
     terpri();
     write"because ",f," has to be non-zero, giving ",f," a low priority.";
     terpri();
     write "Old ordering: ";
     s:=ftem_;
     while s do <<write car s$ s:=cdr s$ if s then write",">>;
     terpri();
     write "New ordering: ";
     s:=append(reverse h,cons(f,ftemcp));
     while s do <<write car s$ s:=cdr s$ if s then write",">>;
     terpri();

    >>;
    change_fcts_ordering(append(reverse h,cons(f,ftemcp)),pdes,vl_);
    ftemcp:=nil
   >>  % of not member(simp car h,ineq_)
  >>   % of ano > (fctlength car ftemcp)
 >>    % of ftemcp
end;


% symbolic procedure drop_factor(h,pro);
% % This procedure drops a factor h or its negative from an expression pro
% begin scalar hs,newpro,mi;
%  hs:=signchange(h);
%  if pairp pro and (car pro='MINUS) then <<pro:=cadr pro; mi:=t>>;
%  if pro = h  then newpro:= 1 else
%  if pro = hs then newpro:=-1 else
%  if pairp pro and (car pro = 'TIMES) then
%  if member(h ,pro) then newpro:=reval delete(h ,pro) else
%  if member(hs,pro) then newpro:=reval list('MINUS,delete(hs,pro));
%  if mi and newpro then newpro:=reval list('MINUS,newpro)
%  return newpro
% end;


symbolic procedure updateSQfcteval(pdes,newineq);
% newineq is a new (scalar) inequality in SQ form
begin scalar p,pv,ps,hist,h1;
 for each p in pdes do
 if null contradiction_ then
 if newineq=get(p,'sqval) then raise_contradiction({'!*SQ,newineq,t},nil)
                          else <<
  pv:=get(p,'fac);
  if pairp pv and member(newineq,pv) then <<
   if record_hist then hist:=reval {'QUOTIENT,get(p,'histry_),reval {'!*SQ,newineq,nil}};

   for each h1 in allflags_ do flag1(p,h1)$ % <-- to be added because this was
   % in contradictioncheck() which is now fully covered by this procedure
   updateSQ(p,quotsq(get(p,'sqval),newineq),nil,nil,get(p,'fcts),
            get(p,'vars),t,list(0),pdes);
   % pdes:=insert_in_eqlist(p,delete(p,pdes))$  %<=<=<=<=
   drop_pde_from_idties(p,pdes,hist);
   drop_pde_from_properties(p,pdes)
  >> else <<
   % h1 will be the list of functions of p occuring in the inequality.
   % If anyone of them occurs in a coefficient of a case-generating
   % substitution then new determination of all possible substitutions using p.

   ps:=get(p,'fcteval_nli);
   if ps and (h1:=smemberl(get(p,'fcts),newineq)) then <<

    while ps and freeoflist(caar ps,h1) do ps:=cdr ps;

    % The following is the old code based on prefix form. It has been
    % commented out for simplicity for now. It would need a factorization of
    % the coefficients to test whether newineq is contained as a factor.

    %while ps and
    % <<h1:=caar ps;
    %   h2:=signchange(h1);
    %   (not ((newineq=h1              ) or
    %         (pairp h1            and
    %          (car h1 = 'TIMES)   and
    %           member(newineq,h1)     )    )) and
    %   (not ((newineq=h2              ) or
    %         (pairp h2            and
    %          (car h2 = 'TIMES)   and
    %           member(newineq,h2)     )    ))
    % >> do ps:=cdr ps;

    if ps then << % simple but more expensive fix:
     flag1(p,'to_eval);
     put(p,'fcteval_lin,nil);
     put(p,'fcteval_nca,nil);
     put(p,'fcteval_nli,nil);
     put(p,'fcteval_n2l,nil);
     put(p,'fct_nli_lin,nil);
     put(p,'fct_nli_nca,nil);
     put(p,'fct_nli_nli,nil);
     put(p,'fct_nli_nus,nil);
    >>
   >>
  >>
 >>;
 %return pdes %<=<=<=<=
end;

symbolic procedure addfunction(ft);
begin scalar f,ff,l,ok;
 change_prompt_to "";
 ff:=mkid(fname_,nfct_);
 repeat <<
  ok:=t;
  terpri();
  write "What is the name of the new function?";
  terpri();
  write "If the name is ",fname_,"+digits then use ",ff,". Terminate with <ENTER>: ";
  f:=termread();
  if f=ff then nfct_:=add1 nfct_
          else if member(f,ft) then <<
   terpri();
   write"Choose another name. ",f," is already in use.";
   ok:=nil
  >>;
 >> until ok;
 depl!*:=delete(assoc(f,depl!*),depl!*);
 terpri();
 write "Give a list of variables ",f," depends on, for example x,y,z;  ";
 terpri();
 write "For constant ",f," input a `;'  ";
 l:=termxread();
 if (pairp l) and (car l='!*comma!*) then l:=cdr l;
 if pairp l then depl!*:=cons(cons(f,l),depl!*) else
 if l then depl!*:=cons(list(f,l),depl!*);
 ft:=fctinsert(f,ft);
 ftem_:=fctinsert(f,ftem_);
 restore_interactive_prompt();
 return (ft . f)
end;

symbolic procedure reducepde(pdes,ftem,vl);
begin scalar p,q,ex;
 change_prompt_to "";
 terpri();
 write "Which equation is to be simplified? ";
 p:=termread();
 if not member(p,pdes) then write"This is not the name of an equation!"
                       else <<
  ex:=get(p,'sqval);
  pdes:=drop_pde(p,pdes,nil);
  q:=mkeqSQ(ex,nil,nil,ftem,vl,allflags_,t,list(0),nil,pdes);
  terpri()$write q," replaces ",p;
  pdes:=eqinsert(q,pdes);
  if member(q,pdes) then <<terpri()$write q," : "$ typeeq(q)$ plot_non0_separants(q)>>
 >>;
 restore_interactive_prompt();
 return list(pdes,ftem)
end;

symbolic procedure replacepde(pdes,ftem,vl);
begin scalar p,q,ex,h,newft,again;
 change_prompt_to "";
 repeat <<
  terpri();
  write "Is there a";
  if again then write" further";
  write" new function in the changed/new PDE that";
  terpri();
  write "is to be calculated (y/n)? ";
  p:=termread();
  if (p='y) or (p='Y) then <<
   h:=addfunction(ftem);
   ftem:=car h;
   if cdr h then newft:=cons(cdr h,newft)
  >>;
  again:=t
 >> until (p='n) or (p='N);
 terpri();
 write "If you want to replace a pde then type its name, e.g. e_23 <ENTER>.";
 terpri();
 write "If you want to add a pde then type `new_pde' <ENTER>. ";
 p:=termread();
 if (p='NEW_PDE) or member(p,pdes) then
  <<terpri()$write "Input of a value for ";
  if p='new_pde then write "the new pde."
                else write p,".";
  terpri();
  write "You can use names of other pds, e.g. 3*e_12 - df(e_13,x); ";
  terpri();
  write "Terminate the expression with ; or $ : ";
  terpri();
  ex:=termxread();
%  for each a in pdes do ex:=subst(get(a,'val),a,ex);
%  for each a in pdes do ex:=subsq(ex,{(a . {'!*sq,get(a,'sqval),t})});
  for each a in pdes do
  if not freeof(ex,a) then <<
   if null get(a,'val) then put(a,'val,prepsq get(a,'sqval));
   ex:=subst(get(a,'val),a,ex);
  >>;
  ex:=simp ex;
  terpri();
  write "Do you want the equation to be"$terpri();
%  write "- left completely unchanged";
%  terpri();
%  write "  (e.g. to keep the structure of a product to ";
%  terpri();
%  write "   investigate subcases)                        (1)";
%  terpri();
  write "- simplified (e.g. e**log(x) -> x) without";
  terpri();
  write "  dropping non-zero factors and denominators";
  terpri();
  write "  (e.g. to introduce integrating factors)       (1)";
  terpri();
  write "- simplified completely                         (2) ";
  h:=termread();
%  if h=2 then ex:=reval ex;
%  if h<3 then h:=nil
%         else h:=t;
  if h=1 then h:=nil else h:=t;
  if p neq 'NEW_PDE then
  % pdes:=drop_pde(p,pdes,{'QUOTIENT,{'TIMES,p,prepsq ex},prepsq get(p,'sqval)});
  %### 18.6.07 this drop_pde does not make much sense to me
  pdes:=drop_pde(p,pdes,nil);
  if flin_ then % so that these functions are not the only linear ones
                % for example, when adding g=newf*h to a homogeneous
                % system, g as non-flin_ could not be solved for if
                % newf would be in flin_ .
  for each q in newft do
  if lin_check_SQ(ex,{q}) then flin_:=sort_according_to(cons(q,flin_),ftem_);
  q:=mkeqSQ(ex,nil,nil,ftem,vl,allflags_,h,list(0),nil,pdes);
  % A new equation with a new function appearing linear and only
  % algebraically can only have the purpose of a transformation
  % in which case the new equation should not be solved for the
  % new function as this would just mean dropping the new equation:
  if (p='NEW_PDE) and newft then
  put(q,'not_to_eval,newft);
  terpri()$write q;
  if p='NEW_PDE then write " is added"
                else write " replaces ",p;
  pdes:=eqinsert(q,pdes)>>
 else <<terpri();
        write "A pde ",p," does not exist! (Back to previous menu)">>;
 restore_interactive_prompt();
 return list(pdes,ftem)
end;

symbolic procedure select_from_list(liste,n);
begin scalar s;
 change_prompt_to "";
 terpri();
 if n then write"Pick ",n," from this list:"
      else write"Pick from this list";
 terpri();
 listprint(liste)$write";"$terpri();
 if null n then <<
  write"a sublist and input it in the same form. Enter ; to choose all.";
  terpri();
 >>;
 s:=termlistread();
 if n and n neq length s then <<
  write "Wrong number picked."$terpri();
  s:=nil;
 >>                      else
 if null s then s:=liste else
 if not_included(s,liste) then <<
  write setdiff(s,liste)," is not allowed."$terpri();
  s:=nil;
 >>;
 restore_interactive_prompt();
 return s
end;

symbolic procedure selectpdes(pdes,n);
% interactive selection of n pdes
% n may be an integer or nil. If nil then the
% number of pdes is free.
if pdes then
begin scalar l,s,m;
 change_prompt_to "";
 terpri();
 if null n then <<
  write "How many equations do you want to select? "$terpri();
  write "(number <ENTER>) : "$terpri();
  n:=termread();
 >>;
 write "Please select ",n," equation";
 if n>1 then write "s"$write " from: ";
 write pdes;
 terpri();
 m:=0;
 s:=t;
 while (m<n) and s do
  <<m:=add1 m;
  if n>1 then write m,". ";
  write "pde: ";
  s:=termread();
  while not member(s,pdes) do <<
   if size_watch and not fixp size_watch then % otherwise avoid growth
   history_:=cons("*** Invalid input.",cons('ig,history_));
   write "Error!!! Please select a pde from: ";
   write pdes;
   terpri()$if n>1 then write m,". ";
   write "pde: ";
   s:=termread()>>;
  if s then <<
   pdes:=delete(s,pdes);
   l:=cons(s,l)
  >>
 >>;
 restore_interactive_prompt();
 return reverse l;
end;

symbolic procedure depnd(y,xlist);
% xlist is a list of list of new dependencies
for each xx in xlist do
for each x  in xx    do depend y,x;

symbolic operator nodependlist;
symbolic procedure nodependlist(fl);
% deleting all dependencies of the list fl which
% can be a lisp list or an algebraic mode list
for each f in fl do
if f neq 'LIST then <<
 f:=reval f;   depl!*:=delete(assoc(f,depl!*),depl!*);
 f:=mkid(f,'_);depl!*:=delete(assoc(f,depl!*),depl!*)
>>;

algebraic procedure dependlist(y,xlist);
% adding the dependence of y on all elements of all algebraic
% sublists of the algebraic list xlist
for each xx in xlist do
for each x  in xx    do depend y,x;

fluid '(errorset_control);
errorset_control := nil;

symbolic procedure err_catch_groeb(arglist);
% The purpose of this procedure is only to allow manual interrupts
% without crashing the whole computation.
if cadddr arglist and
   (length cadddr arglist > 1) then
begin scalar h;
 h:=errorset({'comp_groebner_basis,mkquote arglist},errorset_control,errorset_control)
 where !*protfg=t;
 erfg!*:=nil;
 return if null h or errorp h then nil
                              else car h
end;

symbolic operator err_catch_readin;
symbolic procedure err_catch_readin(fname,in_mode);
if null filep fname then nil else
begin scalar h,mode_bak,echo_bak,semic_bak;
 mode_bak:=!*mode; % if the file to read starts with 'lisp;'
 echo_bak:=!*echo; semic_bak:=semic!*;
 semic!*:='!$;
 !*mode := if in_mode='algebraic then 'algebraic else 'symbolic;
 h:= errorset({'in,mkquote {fname}},errorset_control,errorset_control)
     where !*protfg=t;
 !*echo:=echo_bak; semic!*:=semic_bak;
 erfg!*:=nil; !*mode:=mode_bak;
 return not errorp h
end;

symbolic procedure err_catch_solve(eqs,fl);
% fl='(LIST x y z);    eqs='(LIST expr1 expr2 .. )
begin scalar h;
 h:=errorset({'solveeval,mkquote{eqs, fl}},errorset_control,errorset_control)
 where !*protfg=t;
 erfg!*:=nil;
 return if errorp h then nil
                    else cdar h    % cdr for deleting 'LIST
end;

symbolic procedure err_catch_odesolve(eqs,y,x);
begin scalar h,k,bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_ode;
 bakup_bak:=backup_;backup_:='max_gc_ode;
 k:=setkorder nil;
 h:=errorset({'odesolve,mkquote reval eqs,mkquote reval y,mkquote reval x},errorset_control,errorset_control)
 where !*protfg=t;
 erfg!*:=nil;
 setkorder k;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then {'LIST,nil}
                    else car h
end;

symbolic procedure err_catch_minsub(pdes,l1,cost_limit,no_cases);
begin scalar h,bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_minsub;
 bakup_bak:=backup_;backup_:='max_gc_minsub;
 h:=errorset({'search_subs,mkquote pdes,mkquote l1,
                           mkquote cost_limit,mkquote no_cases},errorset_control,errorset_control)
    where !*protfg=t;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h
end;

symbolic procedure err_catch_gb(pdes);
begin scalar h,p,bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_gb;
 bakup_bak:=backup_;backup_:='max_gc_gb;
 h:=errorset(
     {'groebnerfeval,
      mkquote{cons('LIST,for each p in pdes  collect {'!*SQ,get(p,'sqval),t}),
              cons('LIST,ftem_),
              cons('LIST,for each p in ineq_ collect {'!*SQ,p,t}) }},errorset_control,errorset_control)
 where !*protfg=t;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h
end;

symbolic operator err_catch_sub;
symbolic procedure err_catch_sub(h2,h6,h3);
% do sub(h2=h6,h3) with error catching
% prefix version
begin scalar h4,h5;
 h4 := list('EQUAL,h2,h6);
 h5:=errorset({'subeval,mkquote{reval h4,
                                reval h3 }},errorset_control,errorset_control)
     where !*protfg=t;
 erfg!*:=nil;
 return if errorp h5 then nil
                     else car h5
end;


put('err_catch_sub_SQ,'psopfn,'ecs_SQ);
symbolic procedure ecs_SQ(inp);
% This is a psopfn procedure which does not evaluate the arguments
% automatically, this is done at the start of .
% The input equations should be in {!*sq,..,t} form (fast) but can be
% in prefix form (slow).
% inp is a lisp list of 3 expressions h2,h6,h3 for performing sub(h2=h6,h3)
% The procedure returns nil or {'!*SQ,..,t}
%
begin scalar h2,h3,h5,h6;
 if length inp neq 3 then <<
  terpri();
  write"SPLIT_SIMPLIFY DOES NOT HAVE 3 ARGUMENTS.";
 >>;
 h2:=     reval   car inp;
 h6:=     aeval  cadr inp$  % including {'!*SQ,..
 h3:=cadr aeval caddr inp$  % excluding {'!*SQ,..
 h5:=errorset({'subsq,mkquote h3,mkquote {(h2 . h6)}},errorset_control,errorset_control)
     where !*protfg=t;
 erfg!*:=nil;
 return if errorp h5 then nil
                     else {'!*SQ,car h5,t}
end;

symbolic operator err_catch_int;
symbolic procedure err_catch_int(h2,h3);
% do int(h2,h3) with error catching
begin scalar h5,bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_int;
 bakup_bak:=backup_;backup_:='max_gc_int;
 h5:=errorset({'simpint,mkquote{reval h2,
                                reval h3 }},errorset_control,errorset_control)
     where !*protfg=t;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h5 then nil
%                     else
% if not freeof(car h5,'INT) then nil
%
% It is useful to have this formal integral included because in the
% call in intpde_ not all functions are listed in the parameter listing
% functions so terms involving these unknown functions would get
% integrated this way. Also, if expressions are too large then
% errorp h5 is true and then it would not jam the following computation.
%
                            else prepsq car h5
end;

symbolic procedure err_catch_reval(h);
% do reval h with error catching
begin scalar h2,bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_int;
 bakup_bak:=backup_;backup_:='max_gc_int;
 h2:=errorset({'reval,mkquote h},errorset_control,errorset_control)
     where !*protfg=t;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h2 then nil
                     else car h2
end;

symbolic procedure check_stop;
  if filep "stop_now" then <<
    !*batch_mode := nil;
    old_history := nil;
    batchcount_ := sub1 stepcounter_;
    repeat_mode:=1 >>;

!*gc!-hook!* := 'csl_aftergcuserhook;

symbolic procedure csl_aftergcuserhook u;
 << aftergcsystemhook u;       % The handler in rlisp/inter.red
    if u then aftergcuserhook() else nil >>;

symbolic procedure aftergcuserhook;
  begin scalar li;
!#if (memq 'psl lispsystem!*)
    last_free_cells := if boundp 'gcfree!* then gcfree!*
                       else known!-free!-space();
!#else
    last_free_cells := 1000000;
!#endif
    li := {'max_gc_elimin,'max_gc_fac,'max_gc_gb,'max_gc_int,'max_gc_minsub,
           'max_gc_ode,'max_gc_red_len,'max_gc_short,'max_gc_ss};
    my_gc_counter := add1 my_gc_counter;
    if !*gc and member(backup_, li) then <<
      write backup_,
        " : ",
        if backup_='max_gc_elimin       then max_gc_elimin
        else if backup_='max_gc_fac     then max_gc_fac
        else if backup_='max_gc_gb      then max_gc_gb
        else if backup_='max_gc_int     then max_gc_int
        else if backup_='max_gc_minsub  then max_gc_minsub
        else if backup_='max_gc_ode     then max_gc_ode
        else if backup_='max_gc_red_len then max_gc_red_len
        else if backup_='max_gc_short   then max_gc_short
        else if backup_='max_gc_ss      then max_gc_ss,
        "  max # of GC's left to do: ",
        1+max_gc_counter-my_gc_counter;
    terpri() >>;
    if member(backup_,li) and
      ((my_gc_counter > max_gc_counter) or
       (last_free_cells<100000)) then <<
      if print_ then <<
        % and print_more (User must know that not all is computed.)
        write "Stop of ",
         if backup_='max_gc_elimin       then "an elimination"
         else if backup_='max_gc_fac     then "a factorization"
         else if backup_='max_gc_gb      then "a groebner basis computation"
         else if backup_='max_gc_int     then "an integration"
         else if backup_='max_gc_minsub  then "a minimal growth substitution"
         else if backup_='max_gc_ode     then "solving an ODE"
         else if backup_='max_gc_red_len then "a length reducing decoupling step"
         else if backup_='max_gc_short   then "a shortening step"
         else if backup_='max_gc_ss      then "searching a sub-system"
         else                                 "an unknown step",
         " due to ",
         if last_free_cells<100000 then "less than 100000 free cells."
         else "reaching the limit of garbage collections.";
        terpri() >>;
        rederr "Heidadeife " >>
    else if print_ and (last_free_cells<100000) then
      write"Memory seems to run out. Less than 100000 free cells!"
  end;

symbolic operator err_catch_fac;

symbolic procedure err_catch_fac(a);
% converts input into prfix form through call of symbolic operator
% and returns prefix form
% prefix form is currently needed at least in the calls from crint.red
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak,
             no_powers_changed,rational_changed;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_fac;
 kernlist!*bak:=kernlist!*;
 kord!*bak:=kord!*;
 bakup_bak:=backup_;backup_:='max_gc_fac;
 if null !*nopowers then <<algebraic(on nopowers);
                           no_powers_changed:=t>>;
 if null !*rational and not freeof(a,'!:rn!:)
                    and (null !*complex or not freeof(a,'!:gi!:))
 then <<off msg$ algebraic(on rational)$ on msg;
        rational_changed:=t>>;
 % 8.9.04: This became necessary due to a strange factorizer bug
 % ` Non-numerical ... in arithmetic (or so)
 % 12.7.08: The same error occurs when on complex and an expression
 % contains '!:gi!: and then on rational is done and factorize.
 h:=errorset({'reval,list('FACTORIZE,mkquote a)},errorset_control,errorset_control)  % reval --> aeval for speedup
    where !*protfg=t;
 if rational_changed then <<off msg$ algebraic(off rational)$ on msg>>;
 if no_powers_changed then algebraic(off nopowers);
 kernlist!*:=kernlist!*bak;
 kord!*:=kord!*bak;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h or
           (pairp h and pairp car h and
            cdar h and null cadar h) % seems a REDUCE bug
        then {'LIST,a}
        else car h
end;

symbolic procedure err_catch_fac2(a);
% a is in prefixed SQ-form or prefix form
% returns list of factors, i.e. works under off nopowers
% The first factor may be numeric, e.g. 1/2.
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak,
             no_powers_changed,rational_changed;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_fac;
 kernlist!*bak:=kernlist!*;
 kord!*bak:=kord!*;
 bakup_bak:=backup_;backup_:='max_gc_fac;
 if !*nopowers then <<algebraic(off nopowers);
                      no_powers_changed:=t>>;
 if null !*rational and not freeof(a,'!:rn!:)
                    and (null !*complex or not freeof(a,'!:gi!:))
 then <<off msg$ algebraic(on rational)$ on msg;
        rational_changed:=t>>;
 % 8.9.04: This became necessary due to a strange factorizer bug
 % ` Non-numerical ... in arithmetic (or so)
 % 12.7.08: The same error occurs when on complex and an expression
 % contains '!:gi!: and then on rational is done and factorize.
 h:=errorset(list('FACTORIZE,mkquote a),errorset_control,errorset_control) where !*protfg=t;
 if rational_changed then <<off msg$ algebraic(off rational)$ on msg>>;
 if no_powers_changed then algebraic(on nopowers);
 kernlist!*:=kernlist!*bak;
 kord!*:=kord!*bak;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h or
           (pairp h and pairp car h and
            cdar h and null cadar h) % seems a REDUCE bug
        then {'LIST,{'LIST,a,1}}
        else car h
end;

symbolic procedure err_catch_fac3(a);
% a is in standard form format
% returns list of factors in special format
% the first factor is numeric
% or (1 . nil) if error
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak,
             no_powers_changed,rational_changed;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_fac;
 kernlist!*bak:=kernlist!*;
 kord!*bak:=kord!*;
 bakup_bak:=backup_;backup_:='max_gc_fac;
 if !*nopowers then <<algebraic(off nopowers);
                      no_powers_changed:=t>>;
 if null !*rational and not freeof(a,'!:rn!:)
                    and (null !*complex or not freeof(a,'!:gi!:))
 then <<off msg$ algebraic(on rational)$ on msg;
        rational_changed:=t>>;
 % 8.9.04: This became necessary due to a strange factorizer bug
 % ` Non-numerical ... in arithmetic (or so)
 % 12.7.08: The same error occurs when on complex and an expression
 % contains '!:gi!: and then on rational is done and factorize.
 h:=errorset(list('fctrf ,mkquote a),errorset_control,errorset_control) where !*protfg=t;
 if rational_changed then <<off msg$ algebraic(off rational)$ on msg>>;
 if no_powers_changed then algebraic(on nopowers);
 kernlist!*:=kernlist!*bak;
 kord!*:=kord!*bak;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then cons(1,nil)
                    else car h
end;

symbolic procedure err_catch_gcd(a,b);
% a and b must have form {'!*sq, .. ,t} (or prefix form which is
% infinitely slower for large expressions)
% returns GCD in {'!*SQ,..,t}-form
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak;
 bak:=max_gc_counter;
 max_gc_counter:=my_gc_counter+max_gc_fac;
 kernlist!*bak:=kernlist!*;
 kord!*bak:=kord!*;
 bakup_bak:=backup_;backup_:='max_gc_fac;
 h:=errorset({'aeval,list('list,''GCD,mkquote a,mkquote b)},errorset_control,errorset_control)
    where !*protfg=t;
 kernlist!*:=kernlist!*bak;
 kord!*:=kord!*bak;
 erfg!*:=nil;
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 % return if errorp h then 1     % --> previous prefix form
 %                    else car h
 return if errorp h then {'!*SQ,(1 . 1),t}
                    else car h
end;

symbolic procedure err_catch_preduce(a,b);
begin scalar h,k;
 k:=setkorder nil;
 h:= errorset({'aeval , mkquote {'preduce,mkquote a,mkquote b}},errorset_control,errorset_control)
 where !*protfg=t;
 erfg!*:=nil;
 setkorder k;
 return if errorp h then nil
                    else car h
end;


symbolic procedure find_factorization(arglist);
% finding a PDE that is not thoroughly tested for factorization and that factorizes
begin scalar l,g,h,k,m,new_sqval,fs,dropped_factors,mb,pdes,pdecp,dropped_eqn;
 pdes:=car arglist;
 if expert_mode then l:=selectpdes(pdes,1)
                else l:=cadddr arglist;
 % fs is list of factors, i.e. fs neq nil means factorization was successful
 while l and null fs
         and null contradiction_
         and null dropped_eqn do << % find only one successful factorization
  h:=get(car l,'fac);
  if null h or (fixp h and (h<2)) then <<
   h:=cdr err_catch_fac2 {'!*SQ,(numr get(car l,'sqval) . 1),t};
   if pairp h and (cdr h or (caddar h>1)) then
   while h and null dropped_eqn do <<
    g:=simp cadar h;
    if domainp numr g then h:=cdr h
                      else <<
     mb:=can_not_become_zeroSQ(g,ftem_);
     if (caddar h > 1) or mb then <<
      dropped_factors:=t;
      if null new_sqval then new_sqval:=get(car l,'sqval);
      k:=caddar h; % caddar h is the power of this factor
      if not mb then k:=sub1 k; % k is the power of the factor that is dropped
      for m:=1:k do new_sqval:=quotsq(new_sqval,g)
     >>;
     if mb then h:=cdr h
           else << % Check whether the factor is = +/- an equation
      g:=numr cadr cadar h;
      k:=no_of_tm_sf g;
      pdecp:=pdes;
      while pdecp and h do
      if (get(car pdecp,'terms)=k) and
         (car pdecp neq car l) and
         ((g=numr       get(car pdecp,'sqval)) or
          (g=numr negsq get(car pdecp,'sqval))    )
      then <<dropped_eqn:=car pdecp;h:=nil>>
      else pdecp:=cdr pdecp;
      if h then <<fs:=cons((g . 1),fs);h:=cdr h>>
     >>
    >>
   >>;

   if dropped_eqn then <<
    pdes:=drop_pde(car l,pdes,{'times,dropped_eqn,
                                      {'QUOTIENT,prepsq get(car l,'sqval),
                                                 prepsq get(dropped_eqn,'sqval)}});
    drop_pde_from_properties(car l,pdes)
   >>             else
   if null dropped_factors and (null fs or null cdr fs) then <<
    fs:=nil;
    put(car l,'fac,2)
   >>                                                   else
   if null dropped_factors then put(car l,'fac,fs)
                           else <<  % factors are dropped -> new equation -> updatesq()
    for each f in allflags_ do flag1(car l,f);
    if record_hist then h:=get(car l,'sqval);
    updateSQ(car l,new_sqval,fs,nil,get(car l,'fcts),get(car l,'vars),t,list(0),pdes);
    % The updateSQ-call is correct whether fs holds only one factor or more than one
    drop_pde_from_idties(car l,pdes,if record_hist then reval
                {'TIMES,get(car l,'hist),{'QUOTIENT,prepsq get(car l,'sqval),prepsq h}}
                                                          else nil);
    drop_pde_from_properties(car l,pdes);
    if null contradiction_ then
    pdes:=eqinsert(car l,delete(car l,pdes));
   >>
  >>;
  if print_ and ((fs or dropped_eqn) or contradiction_) then <<
   write"Equation ",car l," factorized."$terpri();
   if contradiction_ then write"This leads to a contradiction!" else
   if dropped_eqn then write"It is a consequence of ",dropped_eqn,"."
  >>;
  l:=cdr l
 >>;
 return
 if contradiction_ then nil else
 if dropped_eqn or dropped_factors then {pdes,cadr arglist} else
 if fs then arglist
end;


%symbolic procedure factored_form(a);
%% a is expected to be in prefix form
%begin scalar b;
% if (pairp a) and (car a = 'PLUS) then <<
%  b:=err_catch_fac a;
%  if b and (length b > 2) then a:=cons('TIMES,cdr b)
% >>;
% return a
%end;

symbolic procedure leading_factors(u);
% called from sffac()
% u is a standard form
% returns a list: first element is what can not be factorized,
%                 i.e. either 1 or a sum followed by monomial factors,
%                 each as a standard form, also numbers, like 7 or  (!:rn!: 1 . 12)
begin scalar fli,v,w;
 while pairp u    and
       null cdr u and
       not domainp car u do <<  % last test should already be included in 2nd test
  fli := cons(numr mksq(mvar u,ldeg u), fli);
  u   := lc u
 >>;

 if domainp u then fli:=cons(u,fli)
              else << % find the numerical coefficient of the leading term
  v:=u;
  while pairp v and not domainp car v do v:=lc v;

  if v=1 then fli:=cons(u,fli)
         else <<
   w:=quotsq((u . 1),(v . 1));
   %w:=simpquot {{'!*SQ,(u . 1),t},{'!*SQ,(v . 1),t}};
   if denr w = 1 then fli:=cons(numr w,cons(v,fli))
                 else fli:=cons(u,fli)
  >>
 >>;
 return fli
end;

symbolic procedure sffac(u);
% u is a standard form (not standard quotient)
% returns nil or fli - a list of standard forms, each being a factor
begin scalar u1,u2,u3,fli,v;

 % at first splitting u into list of monomial factors and remainder
 % remainder coming first
 fli:=leading_factors(u);
 u:=car fli;
 fli:=cdr fli;

 % then computing the GCD of all coefficients of the leading variable
 if not domainp u then << % u must be a sum with different powers of mvar u

  v:=mvar u;
  %  u1:=u;
  %  while u1 do
  %  if domainp u1 or (v neq mvar u1) then <<u2:=   u1 . u2;u1:=   nil>>
  %                                   else <<u2:=lc u1 . u2;u1:=red u1>>;
  %  % u2 is now a list of coefficients of different powers
  %  % u1:=1;
  %  % u1:=gcdlist u2; % gave sometimes error with rational numbers occuring in u2
  %  % but then gcdf() in fixes.red was fixed and now gcdlist is re-activated 9.12.07
  %  % u1:=gcdlist_aux u2;   % temporarily when gcdlist gave errors
  %  % 14 March 2012: gcdlist crashed when there were complex numbers ( :gi: )
  %  % involved. comfac did not crash, so now compfac is used

  % comfac nimmt den gcd aller Koeffizienten der Potenzen der leading Variable
  % des Input Polynoms. Der gcd Algorithmus wird allerdings bestimmt durch den
  % Domainmode. Also wenn man z.B. 'on complex' gemacht hat, dann wird der gcd
  % auch ueber der Domaene des Rings der Gaussian Integer gemacht (was relativ
  % teuer ist). gcdlist hingegen ist eine Unterprozedur des 'extended Zassenhaus
  % gcd' Algorithmus und funktioniert daher nur ueber dem Ring Integer.

  u1 := cdr comfac u;
  if (domainp u1) and (u neq 1) then fli:=cons(numr quotsq((u . 1),(u1 . 1)),cons(u1,fli))
                  	        else <<
   u2:=sffac u1;

   if null u2 then u2:=list u1;
   for each u3 in u2 do % if not domainp u3 then
   <<
    v:=quotsq((u . 1),(u3 . 1))$                   % it should be denr v = 1
    if denr v = 1 then <<fli:=cons(u3,fli)$u:=numr v>>
   >>;
   fli:=cons(u,fli)
  >>
 >>;

 %write"factors:";
 %for each u in fli do mathprint {'!*sq, (u . 1), t};
 %write"============================";

 return fli
end;

!#if (memq 'psl lispsystem!*) % PSL does not have a function oblist(), therefore:

symbolic lispeval '(putd 'countids 'expr
          '(lambda nil (prog (nn) (setq nn 0)
                (mapobl (function (lambda (x) (setq nn (plus2 nn 1)))))
                                  (return nn))));

!#else

symbolic procedure countids$ length oblist();

!#endif

symbolic operator low_mem;
% if garbage collection recovers only 500000 cells then backtrace
% to be used only on workstations, not PCs i.e. under LINUX, Windows

%symbolic procedure newreclaim();
%   <<oldreclaim();
%     if (known!-free!-space() < 500000 ) then backtrace()
%   >>;

symbolic procedure low_mem();
if not( getd 'oldreclaim) then <<
    copyd('oldreclaim,'!%reclaim);
    copyd('!%reclaim,'newreclaim);
>>;

symbolic operator polyansatz;
symbolic procedure polyansatz(ev,iv,fn,degre,homo);
% - ev, iv are algebraic mode lists
% - generates a polynomial in the variables ev of degree degre
%   with functions with name fn_index of the variables iv
% - if homo then a homogeneous polynomial
% - generates and returns polynomial in prefix form which could
%   be speeded up to SQ-form if needed.
begin scalar a,fi,el1,el2,f,fl,p,pr;
 a:=reval list('EXPT,cons('PLUS,if homo then cdr ev
                                        else cons(1,cdr ev)),degre);
 a:=reverse cdr a;
 fi:=0;
 iv:=cdr iv;
 for each el1 in a collect <<
  if (not pairp el1) or
     (car el1 neq 'TIMES) then el1:=list el1
                          else el1:=cdr el1;
  f:=newfct(fn,iv,fi);
  fi:=add1 fi;
  fl:=cons(f,fl);
  pr:=list f;
  for each el2 in el1 do
  if not fixp el2 then pr:=cons(el2,pr);
  if length pr>1 then pr:=cons('TIMES,pr)
                 else pr:=car pr;
  p:=cons(pr,p)
 >>;
 p:=reval cons('PLUS,p);
 return list('LIST,p,cons('LIST,fl))
end;

symbolic operator polyans;
symbolic procedure polyans(ordr,dgr,x,y,d_y,fn);
% - generates a polynom
%   for i:=0:dgr sum fn"i"(x,y,d_y(1),..,d_y(ordr-1))*d_y(ordr)**i
%   with fn as the function names and d_y as names or derivatives
%   of y w.r.t. x
% - generates and returns polynomial in prefix form which could
%   be speeded up to SQ-form if needed.
% - this is an older function hardly used anymore
begin scalar ll,fl,a,i,f;
    i:=sub1 ordr;
    while i>0 do
	  <<ll:=cons(list(d_y,i),ll);
	  i:=sub1 i>>;
    ll:=cons(y,ll);
    ll:=reverse cons(x,ll);
    fl:=nil;
    i:=0;
    while i<=dgr do
    <<f:=newfct(fn,ll,i);
      fl:=(f . fl);
      a:=list('PLUS,list('TIMES,f,list('EXPT,list(d_y,ordr),i)),a);
      i:=add1 i>>;
    return list('list,reval a,cons('list,fl))
end$ % of polyans

symbolic operator sepans;
symbolic procedure sepans(kind,v1,v2,fn);
% Generates a separation ansatz
% v1,v2 = lists of variables, fn = new function name + index added
% The first variable of v1 occurs only in one sort of the two sorts of
% functions and the remaining variables of v1 in the other sort of
% functios.
% The variables of v2 occur in all functions.
% Returned is a sum of products of each one function of both sorts.
% form: fn1(v11;v21,v22,v23,..)*fn2(v12,..,v1n;v21,v22,v23,..)+...
% the higher "kind", the more general and difficult the ansatz is
% kind = 0 is the full case
begin scalar n,vl1,vl2,h1,h2,h3,h4,fl;
  if cdr v1 = nil then <<vl1:=cdr v2$vl2:=cdr v2>>
		  else <<vl1:=cons(cadr v1,cdr v2);
			 vl2:=append(cddr v1,cdr v2)>>;
  return
  if kind = 0 then <<vl1:=append(cdr v1,cdr v2);
		     h1:=newfct(fn,vl1,'_);
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 1 then <<h1:=newfct(fn,vl1,1);
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 2 then <<h1:=newfct(fn,vl2,1);
		     list('LIST,h1,list('LIST,h1))>>
  else
  if kind = 3 then <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     list('LIST,reval list('PLUS,h1,h2),
			  list('LIST,h1,h2))>>
  else
  if kind = 4 then <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     list('LIST,reval list('TIMES,h1,h2),
			  list('LIST,h1,h2))>>
  else
  if kind = 5 then <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     h3:=newfct(fn,vl1,3);
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
			  list('LIST,h1,h2,h3))>>
  else
  if kind = 6 then <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     h3:=newfct(fn,vl2,3);
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),h3),
			  list('LIST,h1,h2,h3))>>
  else
  if kind = 7 then <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     h3:=newfct(fn,vl1,3);
		     h4:=newfct(fn,vl2,4);
		     list('LIST,reval list('PLUS,
			  list('TIMES,h1,h2),h3,h4),
			  list('LIST,h1,h2,h3,h4))>>
  else
% ansatz of the form FN = FN1(v11,v2) + FN2(v12,v2) + ... + FNi(v1i,v2)
  if kind = 8 then <<n:=1$ vl1:=cdr v1$ vl2:=cdr v2;
		    fl:=();
		     while vl1 neq () do <<
		       h1:=newfct(fn,cons(car vl1,vl2),n);
		       vl1:=cdr vl1;
		       fl:=cons(h1, fl);
		       n:=n+1
		     >>;
		     list('LIST, cons('PLUS,fl), cons('LIST,fl))>>
		

  else
		   <<h1:=newfct(fn,vl1,1);
		     h2:=newfct(fn,vl2,2);
		     h3:=newfct(fn,vl1,3);
		     h4:=newfct(fn,vl2,4);
		     list('LIST,reval list('PLUS,list('TIMES,h1,h2),
						 list('TIMES,h3,h4)),
			  list('LIST,h1,h2,h3,h4))>>
end$ % of sepans

%
% Orderings support!
%
% change_derivs_ordering(pdes,fl,vl) changes the ordering of the
% list of derivatives depending on the current ordering (this
% is detected "automatically" by sort_derivs using the lex_df flag to
% toggle between total-degree and lexicographic.
%
symbolic procedure change_derivs_ordering(pdes,fl,vl);
begin scalar p, dl;
 for each p in pdes do <<
  if tr_orderings then <<
   terpri();
   write "Old: ", get(p,'derivs);
  >>;
  dl := sort_derivs(get(p,'derivs),fl,vl);
  if tr_orderings then <<
   terpri();
   write "New: ", dl;
  >>;
  put(p,'derivs,dl);
  put(p,'dec_with,nil)$    % only if orderings are not
                           % investigated in parallel (-->ord)
  put(p,'dec_with_rl,nil)$ % only if orderings are not ..
  flag1(p,'to_symbol)$     % df(p,lead_deriv) has to be updated if needed
 >>;
 return pdes
end;

symbolic procedure sort_according_to(r,s);
% All elements in r that are in s are sorted according to their order in s.
% This assumes that r is a subset of s.
begin scalar ss,h;
 for each ss in s do
 if member(ss,r) then h:=cons(ss,h);
 return reverse h
end;

symbolic procedure a_before_b_according_to_c(a,b,s);
% determines whether a comes before b in the list s
% returns nil if a=b or if a and b are not in s
if not pairp s then nil else
if b=car s then nil else
if a=car s then t else a_before_b_according_to_c(a,b,cdr s);

symbolic procedure change_fcts_ordering(newli,pdes,vl);
begin scalar s;
 ftem_:=newli;
 flin_:=sort_according_to(flin_,ftem_);
 for each s in pdes do <<
  put(s,'fcts,sort_according_to(get(s,'fcts),ftem_));
  put(s,'allvarfcts,sort_according_to(get(s,'allvarfcts),ftem_));
 >>;
 pdes := change_derivs_ordering(pdes,ftem_,vl);
 if tr_orderings then <<
  terpri();
  write "New functions list: ", ftem_;
 >>
end;

symbolic procedure search_li(l,care);
% Find the cadr of all sublists which have 'care' as car (no nesting)
if pairp l then
if car l = care then {cadr l}
                else begin
 scalar b,resul;
 while pairp l do <<
  if b:=search_li(car l,care) then resul:=union(b,resul);
  l:=cdr l
 >>;
 return resul
end;

symbolic procedure search_li2(l,care);
% Find all sublists which have 'care' as car (no nesting)
if pairp l then
if car l = care then list l
                else begin
 scalar b,resul;
 while pairp l do <<
  if b:=search_li2(car l,care) then resul:=union(b,resul);
  l:=cdr l
 >>;
 return resul
end;

symbolic operator filter;
% an algebraic mode function to return a list of all occurences of operator care
% no reval needed as call of symbolic operator converts to prefix form
symbolic procedure filter(l,care);
cons('LIST,search_li2(l,care));

symbolic operator backup_reduce_flags;
symbolic procedure backup_reduce_flags;
% !*nopowers   = t  to have output of FACTORIZE like in Reduce 3.6
% !*allowdfint = t  moved here from crintfix, to enable simplification
%                   of derivatives of integrals
begin
 !*dfprint_bak   := cons(!*dfprint,!*dfprint_bak);
 !*exp_bak       := cons(!*exp,!*exp_bak);
 !*ezgcd_bak     := cons(!*ezgcd,!*ezgcd_bak);
 !*fullroots_bak := cons(!*fullroots,!*fullroots_bak);
 !*gcd_bak       := cons(!*gcd,!*gcd_bak);
 !*mcd_bak       := cons(!*mcd,!*mcd_bak);
 !*ratarg_bak    := cons(!*ratarg,!*ratarg_bak);
 !*rational_bak  := cons(!*rational,!*rational_bak);

 if null !*dfprint   then algebraic(on  dfprint);
 if null !*exp       then algebraic(on  exp);
 if null !*ezgcd     then algebraic(on  ezgcd);
 if null !*fullroots then algebraic(on  fullroots);
 if      !*gcd       then algebraic(off gcd);
 if null !*mcd       then algebraic(on  mcd);
 if null !*ratarg    then algebraic(on  ratarg);
% if null !*rational  then algebraic(on  rational);

 !#if (neq version!* "REDUCE 3.6")
  !*nopowers_bak   := cons(!*nopowers,!*nopowers_bak);
  !*allowdfint_bak := cons(!*allowdfint,!*allowdfint_bak);
  if null !*nopowers   then algebraic(on nopowers);
  if null !*allowdfint then algebraic(on allowdfint);
 !#endif

end;

symbolic operator recover_reduce_flags;
symbolic procedure recover_reduce_flags;
begin

 if !*dfprint neq car !*dfprint_bak then
 if !*dfprint then algebraic(off dfprint) else algebraic(on dfprint);
 !*dfprint_bak:= cdr !*dfprint_bak;

 if !*exp neq car !*exp_bak then
 if !*exp then algebraic(off exp) else algebraic(on exp);
 !*exp_bak:= cdr !*exp_bak;

 if !*ezgcd neq car !*ezgcd_bak then
 if !*ezgcd then algebraic(off ezgcd) else algebraic(on ezgcd);
 !*ezgcd_bak:= cdr !*ezgcd_bak;

 if !*fullroots neq car !*fullroots_bak then
 if !*fullroots then algebraic(off fullroots) else algebraic(on fullroots);
 !*fullroots_bak:= cdr !*fullroots_bak;

 if !*gcd neq car !*gcd_bak then
 if !*gcd then algebraic(off gcd) else algebraic(on gcd);
 !*gcd_bak:= cdr !*gcd_bak;

 if !*mcd neq car !*mcd_bak then
 if !*mcd then algebraic(off mcd) else algebraic(on mcd);
 !*mcd_bak:= cdr !*mcd_bak;

 if !*ratarg neq car !*ratarg_bak then
 if !*ratarg then algebraic(off ratarg) else algebraic(on ratarg);
 !*ratarg_bak:= cdr !*ratarg_bak;

 if !*rational neq car !*rational_bak then
 if !*rational then algebraic(off rational) else algebraic(on rational);
 !*rational_bak:= cdr !*rational_bak;

 !#if (neq version!* "REDUCE 3.6")
  if !*nopowers neq car !*nopowers_bak then
  if !*nopowers then algebraic(off nopowers) else algebraic(on nopowers);
  !*nopowers_bak:= cdr !*nopowers_bak;
  if !*allowdfint neq car !*allowdfint_bak then
  if !*allowdfint then algebraic(off allowdfint) else algebraic(on allowdfint);
  !*allowdfint_bak:= cdr !*allowdfint_bak;
 !#endif
end;

algebraic procedure maklist(ex);
% making a list out of an expression if not already
if lisp(atom algebraic ex) then {ex} else
if lisp(car algebraic ex neq 'LIST) then ex:={ex}
                                    else ex;

% older slower version:
%symbolic procedure add_to_last_steps(h);
%if length last_steps < 50 then last_steps:=cons(h,last_steps) else
%last_steps:=cons(h,reverse cdr reverse last_steps);

% newer faster version:
symbolic procedure add_to_last_steps(h);
begin scalar n,max_steps;
 last_steps:=cons(h,last_steps);
 n:=0;
 h:=last_steps;
 max_steps:=if fixp size_watch then size_watch
                               else 100000;
 while n<max_steps and cdr h do <<n:=add1 n;h:=cdr h>>;
 if cdr h then rplacd(h,nil)
end;

symbolic procedure same_steps(a,b);
if (car a = car b              ) and
   ((cddr a = cddr b) or  % full equality apart from stepcounter_
    ((car a neq 'subst  ) and
     (car a neq   27    ) and
     (car a neq   11    ) and
     (car a neq   59    ) and
     (car a neq 'sub_sys)     )) then t
                                 else nil;

symbolic procedure in_cycle(h);
% h={'number of module',stepcounter_,'more parameter(s)}
begin scalar cpls1,cpls2,n,cycle;
 cpls1:=last_steps;
 if car h='subst then <<
  n:=0;
  while cpls1 do <<
   if same_steps(h,car cpls1) then n:=add1 n;
   cpls1:=cdr cpls1
  >>;
  cycle:=
  if n>2 then << % the subst. had been done already >=3 times
   write"A partial substitution has been repeated too often."$ terpri();
   write"It will now be made rigorously."$ terpri();
   t
  >>     else nil
  % add_to_last_steps(h) is done outside for substitutions as it is not
  % clear at this stage whether the substitution will be performed
 >>                         else
 if (car h=59) and cpls1 and same_steps(h,car cpls1) then cycle:=t
                                                     else <<
  n:=1;
  % Exactly the same step taken repeatedly one directly after another is not a
  % cycle (unless the last step is a step dealing with the whole problem, like
  % module 59 (computing a Groebner Basis). --> Go back as long as the same
  % steps were done one after another.
  while cpls1 and (car h = caar cpls1) and zerop(cadr h - n - cadar cpls1) do
  <<n:=add1 n;cpls1:=cdr cpls1>>;

  while cpls1 and (not same_steps(h,car cpls1)) do
  <<n:=add1 n;cpls1:=cdr cpls1>>;
  if null cpls1 or
     ((reval {'PLUS,n,n})>length last_steps) then cycle:=nil
                                             else <<
   cpls1:=cdr cpls1;
   cpls2:=last_steps;
   while (n>0) and same_steps(car cpls2,car cpls1) do
   <<cpls1:=cdr cpls1;cpls2:=cdr cpls2;n:=sub1 n>>;
   if (n=0) and print_ then <<
    write if car h = 'sub_sys then "A step to find overdet. sub-systems (" else
          if car h =  9 then "A derivative replacement (" else
          if car h = 11 then "An algebraic length reduction (" else
          if car h = 27 then "A length reducing simplification (" else
          if car h = 59 then "A Groebner Basis computation (" else
                             "A step (",
          car h,") was prevented"$    terpri();
    write"to avoid a cycle."$  terpri();
   >>;
   cycle:=if n>0 then nil else t
  >>;
  if null cycle then add_to_last_steps(h);
 >>;
 return cycle
end;

symbolic procedure switchp (x);
% When called through:   mapobl function switchp
% then this procedure lists all switch settings.
if idp x then if flagp(x ,' switch) then <<
 x := intern bldmsg("*%w",x);
 if boundp x then print list(x, eval x)
>>;

endmodule;

%********************************************************************
module solution_handling;
%********************************************************************
%  Routines for storing, retrieving, merging and displaying solutions
%  Author: Thomas Wolf Dec 2001

symbolic procedure save_solution(eqns,assigns,freef,ineq,ineqor,file_name);
% input lists are in symbolic mode, i.e. without 'LIST at start
% eqns    .. list of remaining unsolved equations
% assigns .. list of computed assignments of the form `function = expression'
% freef   .. list of functiones either free or in eqns
% ineq    .. list of inequalities
% ineqor  .. list of OR-inequalities
begin scalar s,h,p,conti;
  if file_name then s:=file_name
               else <<
   s:=level_string(session_);
   s:=explode s;
   s:=compress cons(car s,cons('s,cons('o,cdddr s)));
  >>;

  sol_list:=union(list s,sol_list);

  out s;
  write"off echo$ ";
  write"backup_:='("$terpri();

  for each h in freef do
  if p:=assoc(h,depl!*) then conti:=cons(p,conti);

  % The first sub-list is a  list of dependencies, like ((f x y) (g x))
  write"% A list of dependencies, like ((f x y) (g x))"$terpri();
  print conti$write" "$terpri();

  % The next sublist is a list of unsolved equations
  write"% A list of unsolved equations"$terpri();
  print eqns$write" "$terpri();

  % The next sublist is a list of assignments
  write"% A list of assignments"$terpri();
  % For algebraic problems one might want to reduce the rhs
  % modulo eqns (see end of merge_two() ).
  print assigns$write" "$terpri();

  % The next sublist is a list of free or unresolved functions
  write"% A list of free or unresolved functions"$terpri();
  print freef$write" "$terpri();

  % The next sublist is a list of non-vanishing expressions
  write"% A list of non-vanishing expressions."$terpri();
  print ineq$write" "$terpri();

  % The next sublist is a list of or-lists. Each or-list has
  % elements that are factor-lists, such that for each or-list
  % at least from one factor-list all elements must be non-zero.
  write"% A list of or-lists. Each or-list has elements that "$terpri();
  write"% are factor-list, such that for each or-list at least"$terpri();
  write"% from one factor-list all elements must be non-zero. "$terpri();
  print ineqor$write" "$terpri();

  terpri();

  write")$";

  write "end$"$terpri();
  shut s;

  return s
end;

symbolic procedure print_indexed_list(li);
begin scalar a,h;
 terpri();
 h:=0;
 for each a in li do <<
  h:=add1 h;
  write"[",h,"]";terpri();
  mathprint a
 >>
end;

symbolic procedure printDHMStime(a);
% print how many days, hours, minutes and seconds a is
begin scalar b;
 if a>10000 then <<
  write" = ";
  if a>=86400000 then <<
   b:=floor(a/86400000);
   write b,if b=1 then " day " else " days  ";
   a:=a-b*86400000
  >>;
  if a>=3600000 then <<
   b:=floor(a/3600000);
   write b,if b=1 then " hour " else " hours  ";
   a:=a-b*3600000
  >>;
  if a>=60000 then <<
   b:=floor(a/60000);
   write b,if b=1 then " minute " else " minutes  ";
   a:=a-b*60000
  >>;
  if a>=1000 then <<
   b:=floor(a/1000);
   write b,if b=1 then " seccond " else " seconds  ";
   a:=a-b*1000
  >>;
  if a neq 0 then write a," msec "
 >>
end;

symbolic procedure sub_list(sb,aim,tr_merge);
% sb is a list of substitutions to be done safely in aim
begin scalar a,b;
 while sb and aim do <<
  % By not computing the numerator we get a sufficient test
  %  aim:=cons('LIST,for each a in cdr aim collect
  %                  algebraic(num(lisp(aim))));
  a:=car sb; sb:=cdr sb;
  if tr_merge then b:=aim;
  aim:=err_catch_sub(cadr a,caddr a,aim);
  if tr_merge and null aim then <<
   write"Sub: ";mathprint a;
   write"in: ";mathprint b;
   write"gives a singular result."$terpri()
  >>
 >>;
 if null aim then <<
  write"Substitutions give singularities."$ terpri();
  %  write"Even substitutions in the numerator "$      terpri();
  %  write"are giving singularities like for log(0)."$ terpri();
 >>;
 return aim
end;

symbolic procedure merge_two(s1,sol1,s2,sol2,absorb);
% Is sol1 a special case of sol2 ?
% If yes, return the new generalized solution sol2 with one less inequality.
% If absorb then modify s2 and sol2 if s1 can be absorbed
% ineqor lists are currently not considered nor modified if absorb

begin scalar eli_2,singular_eli,regular_eli,a,b,cond2,sb,remain_sb,
             singular_sb,regular_sb,c2,remain_c2,remain_num_c2,h,hh,
             try_to_sub,try_to_sub_cp,num_sb,singular_ex,new_eqn,
             singular_ex_cp,ineq2,ine,ineqnew,ineqdrop,tr_merge,
             extra_par_in_s1,gauge_of_s2,gauge_of_s2_cp,did_trafo,n,
             remain_c2_cp,dropped_assign_in_s2,new_assign_in_s2,ass1,
             ass2,sol1_eqn,sol2_eqn,gb$ %num_sb_quo,

%tr_merge:=t;
 if tr_merge then <<
  write"*** sol1 ***: ",s1$ terpri();
  if cadr sol1 then <<write"Remaining equations:"$deprint(cadr sol1)>>;
  print_indexed_list(caddr sol1);

  write"*** sol2 ***: ",s2$ terpri();
  if cadr sol2 then <<write"Remaining equations:"$deprint(cadr sol2)>>;
  print_indexed_list(caddr sol2);
  write"free param in sol1: ",cadddr sol1$terpri();
  write"free param in sol2: ",cadddr sol2$terpri()>>;

 % We drop all assignments like a6=a6 from both sets of assignments
 ass1:=caddr sol1$ for each a in cadddr sol1 do ass1:=delete({'EQUAL,a,a},ass1);
 ass2:=caddr sol2$ for each a in cadddr sol2 do ass2:=delete({'EQUAL,a,a},ass2);

 % 1. We check whether all remaining equations of sol2 are
 % either fulfilled by assignments of sol1 or if after these
 % assignments the remaining equations of sol2 are in the ideal of the
 % remaining equations of sol1. In a first implementation we simply
 % check whether both remaining systems are the same.
 sol1_eqn:=cons('LIST,cadr sol1)$  % unsolved equations in sol1
 sol2_eqn:=cons('LIST,cadr sol2)$  % unsolved equations in sol2

 % 1.1. We do all substitutions of assignments of sol2 in sol2_eqn and
 % similar for sol1 as some substitutions may not have been fully
 % performed during the computation of the solutions as they were too
 % expensive at the time.
 % At first for the unsolved equations of sol1:
 if cdr sol1_eqn then <<
  if tr_merge then <<write"Initial preparation of unsolved eqn in sol1";
                     terpri()>>;
  if null (sol1_eqn:=sub_list(ass1,sol1_eqn,tr_merge)) then return nil;
 >>;

 % And now for the unsolved equations of sol2:
 if cdr sol2_eqn then <<
  if tr_merge then <<write"Initial preparation of unsolved eqn in sol2";
                     terpri()>>;
  if null (sol2_eqn:=sub_list(ass2,sol2_eqn,tr_merge)) then return nil;
 >>;

 % 1.2. We do all substitutions of sol1 in sol2_eqn, always
 % taking the numerator after each substitution.
 if cdr sol2_eqn then <<
  if tr_merge then <<write"sol1 substitutions in sol2";
                     terpri()>>;
  if null (sol2_eqn:=sub_list(ass1,sol2_eqn,tr_merge)) then return nil;
 >>;
 % If sol1 had no remaining equations then after these substitutions
 % there should be no equations from sol2 left.
 if null cdr sol1_eqn and cdr sol2_eqn then return nil;

 % If sol1 has remaining equations (i.e. if cdr sol1_eqn <> nil
 % then from now onwards, everything has to be satisfied modulo
 % this set of equations (called gb below).

 % 1.3. If the remaining equations sol2_eqn are not solved then they
 % should be in the ideal of sol1_eqn. If not then sol1 can not be
 % merged to sol2.

 % 1.3.1. Bring sol1_eqn into the form of a Groebner Basis gb
 if cdr sol1_eqn then algebraic <<
  torder(lisp(cons('LIST,cadddr sol1)),lex);
  gb:=groebner sol1_eqn;  % maybe covering this in a shell in case it
                          % takes too long
  if tr_merge then write "gb=",gb;
  % 1.3.2. Check whether each equation of sol2_eqn is in the ideal of gb
  while (sol2_eqn neq {}) and
        (preduce(num first sol2_eqn,gb)=0) do sol2_eqn:=rest sol2_eqn
 >>;
 sol2_eqn:=cdr sol2_eqn;

 if tr_merge then
 if null sol2_eqn then <<
  write "The remaining equations of solution sol2 are in the"$ terpri();
  write "ideal of the remaining equations of solution sol1."$  terpri()
 >>               else <<
  write"Equation "$mathprint car sol2_eqn;
  write"of solution sol2 is not in the ideal of"$   terpri();
  write"the remaining equations of solution sol1."$ terpri();
  write"--> sol1 is not a special case of sol2."$terpri();
 >>;
 if sol2_eqn then return nil;

 % 2. We list all lhs y_i in assignments y_i=... in sol2
 eli_2:=for each a in ass2 collect cadr a;

 % writing assignments of solution 2 as expressions to vanish,
 % no numerator taken yet
 cond2:=for each a in ass2
        collect {'PLUS,cadr a,{'MINUS,caddr a}};

 % Do all substitutions a=... from sol1 for which there is an
 % assignment a=... in sol2 and collect the other substitutions as remain_sb.
 % These are straight forward substitutions not to be debated.
 cond2:=cons('LIST,cond2);  % because of use of subeval in substitution
 sb:=ass1; % all assignments of solution 1
 while sb do <<
  a:=car sb; sb:=cdr sb;
  if member(cadr a,eli_2) then <<
   eli_2:=delete(cadr a,eli_2);
   cond2:=err_catch_sub(cadr a,caddr a,cond2)
  >>                      else remain_sb:=cons(a,remain_sb)
 >>;

 % eli_2 becomes now the list of new sol2 parameters
 eli_2:=append(eli_2,cadddr sol2)$ % needed only much further below

 % The same again, now taking only numerators and only the remaining
 % substitutions are done in the remaining not identically zero
 % conditions from sol2. In remain_num_c2 are all those non-vanishing,
 % denominator free conditions of sol2 collected which give a
 % singularity for the remaining sol1-substitutions. If there is
 % anyone of these then stop --> sol1 is not a specialized solution of
 % sol2. If after all substitutions one numerator is not zero then
 % stop --> sol1 can not be merged to sol2.

 remain_c2:=cond2;  % remain_c2 to be used later

 cond2:=cdr cond2;
 c2:=nil;
 h:=0;
 while cond2 and (null c2 or zerop c2) do <<
  c2:=car cond2;
  h:=add1 h;
  if tr_merge then <<write"[",h,"]"$terpri()$mathprint c2>>;

  % Is the numerator of c2 fulfilled by assignments of solution 1?
  sb:=remain_sb;               % all remaining assignments of solution 1
  while sb and c2 and not zerop c2 do <<
   a:=car sb; sb:=cdr sb;
   c2:=algebraic(num(lisp(c2)));
   if tr_merge then b:=c2;
   c2:=err_catch_sub(cadr a,caddr a,c2);
   if tr_merge and (b neq c2) then <<
    write"Sub: ";mathprint a;
    if c2 then <<write"new value="$mathprint c2>>
          else <<write"singular result"$terpri()>>
   >>;
   if c2 and not zerop c2 and gb then <<
    c2:=algebraic(preduce(num c2,gb));
    if tr_merge then <<
     if zerop c2                                                        then
     write"which vanishes modulo the remaining eqn.s of sol1."          else
     write"which does not vanish modulo the remaining eqn.s of sol1.";
     terpri();
    >>
   >>
  >>;
  if null c2 then remain_num_c2:=cons(car cond2,remain_num_c2);
  cond2:=cdr cond2
 >>;

 if c2 and not zerop c2 then return nil; % sol1 is not special case of sol2
 if remain_num_c2 then << % can only occur if there were singular subst.
  write"Even substitutions in the numerator is giving "$terpri();
  write"singularities like log(0)."$                    terpri();
  return nil
 >>;

 write"Substitutions in numerators give all zero"$terpri();

 % Data used below are remain_sb which are the remaining substitutions
 % in sol1, remain_c2 which are the remaining conditions in sol2 and
 % eli_2 the list of so far not determined functions in sol2.

 % We now want to find a different order of substitutions, especially
 % substituting for the free parameter functions of sol2
 % based on remain_sb to be done in remain_c2.

 % At first we sort all sol1 assignments into regular_sb and singular_sb.
 % remain_c2 is not changed in this
 sb:=remain_sb;               % all remaining assignments of solution 1
 while sb do <<
  a:=car sb; sb:=cdr sb;
  h:=err_catch_sub(cadr a,caddr a,remain_c2);
  if null h then singular_sb:=cons(a,singular_sb)
            else regular_sb:=cons(a,regular_sb)
 >>;
 if tr_merge then <<terpri();
                    write"regular_sb: "$mathprint cons('LIST,regular_sb)>>;
 if tr_merge then <<write"singular_sb: "$mathprint cons('LIST,singular_sb)>>;

 if singular_sb then <<
  write"Substitutions lead to singularities."$terpri();
  write"Solution ",s2," has to be transformed."$terpri()
 >>;

 % We now make a list of vanishing expressions based on singular_sb
 % which when replaced by 0 in remain_c2 give singularities
 singular_ex:=for each a in singular_sb
              collect reval {'PLUS,cadr a,{'MINUS,caddr a}};
 if tr_merge then <<
  write"The following are expressions which vanish due to sol1 and";
  terpri();
  write"which lead to singularities when used for substitutions in sol2";
  terpri();
  mathprint cons('LIST,singular_ex)
 >>;

 if tr_merge then <<
  write"The following are all free parameters in sol2 for which there are";
  terpri();
  write"substitutions in sol1"$ terpri();
 >>;
 singular_eli:=for each a in singular_sb collect cadr a;
 regular_eli:=for each a in regular_sb collect cadr a;
 if tr_merge then <<terpri();
                    write"singular_eli: "$mathprint cons('LIST,singular_eli)>>;
 if tr_merge then <<write"regular_eli: "$mathprint cons('LIST,regular_eli)>>;

 % Before continuing we want to check whether the supposed to be more special
 % solution sol1 has free parameters which are not free parameters in the more
 % general solution sol2. That can cause problems, i.e. division through 0
 % and non-includedness when in fact sol1 is included in sol2.

 extra_par_in_s1:=setdiff(cadddr sol1,cadddr sol2);
 if tr_merge then <<write"Param in sol1 and not in sol2: ",extra_par_in_s1;
                    terpri()>>;

 for each a in extra_par_in_s1 do <<
  h:=ass2;
  while h and cadar h neq a do h:=cdr h;
  if null h then write"ERROR, there must be an assignment of a in sol2!"
            else <<
   if tr_merge then <<
    write"Assignment in ",s2," of a variable that is a free parameter in ",
         s1," :";
    terpri();
    mathprint car h;
   >>;
   dropped_assign_in_s2:=cons(car h,dropped_assign_in_s2);
   gauge_of_s2:=cons(algebraic(num(lisp({'PLUS,cadr car h,
                                         {'MINUS,caddr car h}}))),
                     gauge_of_s2)
  >>
 >>;

 gauge_of_s2:=cons('LIST,gauge_of_s2);

 if tr_merge then <<write"gauge_of_s2="$mathprint gauge_of_s2>>;

 % We should not do all regular substitutions in gauge_of_s2 (tried that)
 % because some of them may set variables to zero which limits the
 % possibilities of doing transformations of remain_c2

 % We now search for a substitution based on one of the equations
 % gauge_of_s2. The substitution is to be performed on remain_c2.

 % One sometimes has to solve for regular_eli as singular_eli
 % might appear only non-linearly.
 % try_to_sub:=append(regular_eli,singular_eli);
 try_to_sub:=append(singular_eli,regular_eli);

 % Successful re-parametrizing transformations are not unique. Those
 % are given a higher priority who preserve linearity of unknowns
 % and parameters. This matters if, for example, symmetries and
 % conservation laws are determined and each arbitrary parameter of flin_
 % corresponds to one such conservation law, but only if they remain to
 % appear linearly after the re-parametrization.
 h:=reverse try_to_sub;
 for each a in h do
 if (flin_ and (not freeof(flin_,a))) or
    (not flin_ and <<cond2:=remain_c2;
     while cond2 and lin_check(car cond2,{a}) do cond2:=cdr cond2;
     null cond2
    >>) then <<
  if tr_merge then <<
   write"Because ",a," is either in flin_ or appears linearly in sol2,";
   terpri();
   write"it gets a higher priority."$terpri();
  >>;
  try_to_sub:=cons(a,delete(a,try_to_sub))
 >>;

 n:=1;
 repeat <<
  did_trafo:=nil;
  gauge_of_s2_cp:=cdr gauge_of_s2;
  while gauge_of_s2_cp do <<
   sb:=reval car gauge_of_s2_cp;
   gauge_of_s2_cp:=cdr gauge_of_s2_cp;
   if not zerop sb then <<
    try_to_sub_cp:=try_to_sub;
    if tr_merge then <<write"next relation to be used: 0="$mathprint sb;
                       write"try_to_sub=",try_to_sub$terpri()>>;
    h:=err_catch_fac(sb);
    if h then <<
     sb:=nil;
     h:=cdr h;
     while h do <<
      if pairp car h then
      if not((caar h = 'QUOTIENT) and (fixp cadar h) and (fixp caddar h)) then
      if caar h='LIST then
      if pairp cadar h then sb:=cons(cadar h,sb) else
                      else sb:=cons(car h,sb);
      h:=cdr h;
     >>
    >>;

    % From the next condition 0=sb we drop all factors which are
    % single variables which set to zero would be a limitation
    if tr_merge then <<write"After dropping single variable factors ",
                             length sb," factor(s) remain"$terpri()>>;
    sb:=reval cons('TIMES,cons(1,sb)); % to re-gain a product from the factors
    if tr_merge then <<write"New relation used for substitution: sb=";
                       mathprint sb$terpri()>>;

    % If sb contains flin_ unknowns then only those should be solved
    % for to have them not to turn up in denominators, so that they
    % can be set to zero in crack_out when extracting single first integrals,..
    if flin_ and not freeoflist(sb,flin_) then <<
     h:=nil;
     for each a in try_to_sub_cp do
     if not freeof(flin_,a) then h:=cons(a,h);
     try_to_sub_cp:=h
    >>;

    % Now start to find a good transformation
    while try_to_sub_cp do <<
     a:=car try_to_sub_cp; try_to_sub_cp:=cdr try_to_sub_cp;
     if tr_merge then <<write"try to sub next: ",a$terpri()>>;
     if not freeof(sb,a) and lin_check(sb,{a}) then <<
      num_sb:=reval {'DIFFERENCE, sb,{'TIMES,a,coeffn(sb,a,1)}};
      if tr_merge then <<write"num_sb="$mathprint num_sb>>;
%      singular_ex_cp:=singular_ex;
%      while singular_ex_cp do <<
%       if tr_merge then <<write"car singular_ex_cp=",car singular_ex_cp;
%                          terpri()>>;
       % Check whether any one of the expressions (from denom-free A_1)
       % which causes a singular substitution is a factor of the substituted
       % expression for a, i.e. a factor of num_sb

       % sb=0 is the equation from which to get now a re-parametrization
       % It is sb = a*..+num_sb
%       num_sb_quo:=reval {'QUOTIENT,num_sb,car singular_ex_cp};
%       if tr_merge then <<write"num_sb_quo="$mathprint num_sb_quo>>;
%       % if (not pairp num_sb_quo) or
%       %    (car num_sb_quo neq 'QUOTIENT) then <<
       if t then <<
        eli_2:=delete(a,eli_2);
        % i.e. num_sb is a multiple of one of members of singular_ex, HURRAY!
        % Do the substitution in remain_c2
        b:=cadr solveeval list(sb,a);
        h:=err_catch_sub(cadr b,caddr b,remain_c2);
        if tr_merge and null h then <<
         write"Trafo "$mathprint b$write" was singular."$ terpri()
        >>;
        if h then <<
         % Is that test a good success?
         % a is an unknown that got assigned in sol1 (because a is
       	 % element of try_to_sub=append(singular_eli,regular_eli) )
         % and was a parameter in sol2. If it is assigned in sol2 as
	 % well then this is a good sign. If a was in regular_eli
	 % then the regular substitution of a in remain_c2 is not so
	 % surprising but rhs of a=.. in regular_sb or singular_sb
	 % minus the rhs of the re-parametrization assignment a=.. is appended
	 % to remain_c2 and must be made to zero finally.
	 % The only improvement would be to try all combinations of all
	 % possible assignments from all gauge_of_s2 and check for which
	 % of them all sol1 assignments become regular. If in
         % applications it should turn out that some mergings are missed
         % then a complete investigation of all possible
         % re-parametrizations should be considered.

         % next substitution must work because gauge_of_s2 is denom-free
         gauge_of_s2:=err_catch_sub(cadr b,caddr b,gauge_of_s2);
         gauge_of_s2:=cons('LIST, for each gauge_of_s2_cp in cdr gauge_of_s2
                           collect algebraic(num(lisp(gauge_of_s2_cp))));
         gauge_of_s2_cp:=nil;
         new_assign_in_s2:=cons(b,new_assign_in_s2);
         did_trafo:=t;
         write"In order to avoid a singularity when doing substitutions";
         terpri();
         write"the supposed to be more general solution was transformed using:";
         terpri();
         mathprint b;
         if tr_merge then <<write"The new gauge_of_s2: ";
                            mathprint gauge_of_s2>>;

         remain_c2:=h;  % after the new re-parametrization was done

         h:=append(regular_sb,singular_sb);
         while h and a neq cadar h do h:=cdr h;
         if h then remain_c2:=append(remain_c2,list {'DIFFERENCE,caddar h,caddr b});
	 if tr_merge then <<write"remain_c2="$print_indexed_list(cdr remain_c2)>>;
         singular_ex_cp:=nil;
         try_to_sub:=delete(a,try_to_sub);
         try_to_sub_cp:=nil;
         n:=n+1
        >> %  else singular_ex_cp:=cdr singular_ex_cp
       >>  %                              else singular_ex_cp:=cdr singular_ex_cp
%      >>    % while singular_ex_cp
     >>    % if car try_to_sub_cp passes first test
    >>$   % while try_to_sub_cp
   >>    % if not zerop sb
  >>$   % while gauge_of_s2_cp
 >> until (did_trafo=nil);

 if tr_merge then <<
  write"After completing the trafo the new list of parameters of";
  terpri();
  write"sol2 is: ",eli_2$terpri();
  write"sol1 has free parameters: ",cadddr sol1$terpri()
 >>;

 if not_included(cadddr sol1,eli_2) then return <<
  write"Something seems wrong in merge_sol(): after the transformation of";
  terpri();
  write"sol2, all free parameters of sol1 should be free parameters of sol2.";
  terpri();
  nil
 >>                                else <<
  if tr_merge then <<
   write"All free parameters of sol1 are free parameters of sol2";
   terpri()
  >>
 >>;

 % Now all in remain_c2 has to become zero by using first substitutions
 % from regular_sb and substituting parameters from sol2 such that
 % the substituted expression has one of the singular_ex as factor.

 % We seek global substitutions, i.e. substitutions based on sol1
 % which satisfy all sol2 conditions and not for each sol2 condition a
 % different set of sol1 based substitutions. Therefore substitutions
 % are done in the whole remain_c2.

 % try_to_sub are free parameters in sol2 that are contained in
 % regular_eli and which are therefore not in singular_eli and not free
 % parameters in sol1. They are to be substituted next because sol1 is
 % obviously singularity free, so we have to express sol2 in the same
 % free parameters, so we have to substitute for the free parameters fo
 % sol2 which are not free parameters of sol1. But we must not use the
 % same substitutions regular_sb which substitute for them as they lead
 % to singular substitutions afterwards.

% try_to_sub:=memberl(cadddr sol2,regular_eli);
%
% write"try_to_sub=",try_to_sub$terpri();
%
% % We now search for a substitution in regular_sb which leads to a
% % substitution of a member of try_to_sub, say p, ...
% b:=regular_sb;
% for each sb in b do <<
%  sb_cp:=algebraic(num(lisp({'PLUS,cadr sb,{'MINUS,caddr sb}})));
%  try_to_sub_cp:=delete(cadr sb,try_to_sub); % ... but the substitution
%                                             % does not originally
%                                             % have the form p=...  .
%  while try_to_sub_cp do <<
%   a:=car try_to_sub_cp; try_to_sub_cp:=cdr try_to_sub_cp;
%   if not freeof(sb_cp,a) and lin_check(sb_cp,{a}) then <<
%    num_sb:={'DIFFERENCE, sb_cp,{'TIMES,a,coeffn(sb_cp,a,1)}};
%
%    singular_ex_cp:=singular_ex;
%    while singular_ex_cp do <<
%     % Search for an expression causing a singular substitution
%     % which is a factor of the substituted expression for a
%     num_sb_quo:=reval {'QUOTIENT,num_sb,car singular_ex_cp};
%     if (not pairp num_sb_quo) or
%        (car num_sb_quo neq 'QUOTIENT) then <<
%      % i.e. num_sb is a multiple of one of members of singular_ex, HURRAY!
%      % Do the substitution in remain_c2
%      h:=err_catch_sub(cadr sb,caddr sb,remain_c2);
%      if h then <<
%       write"In order to avoid a singularity when doing substitutions";
%       terpri();
%       write"the supposed to be more general solution was transformed:";
%       terpri();
%       mathprint sb;
%       remain_c2:=h;
%       singular_ex_cp:=nil;
%       regular_sb:=delete(sb,regular_sb);
%       try_to_sub:=delete(a,try_to_sub);
%       try_to_sub_cp:=nil;
%      >>   else singular_ex_cp:=cdr singular_ex_cp
%     >>                                else singular_ex_cp:=cdr singular_ex_cp
%    >>    % while singular_ex_cp
%   >>    % if car try_to_sub_cp passes first test
%  >>$   % while try_to_sub_cp
% >>$   % for each sb

 % Do the remaining assignments of solution 1
 sb:=append(regular_sb,singular_sb); % all remaining assignments of solution 1
 while sb and remain_c2 do <<
  a:=car sb; sb:=cdr sb;
  remain_c2_cp:=remain_c2;
  remain_c2:=err_catch_sub(cadr a,caddr a,remain_c2);
  if tr_merge then
  if null remain_c2 then
  <<write"The following subst. was singular: "$mathprint a>>
                    else <<
   write"Remaining substitution: ";mathprint a;
   %write"remain_c2="$mathprint remain_c2
  >>
 >>;

 if null remain_c2 then remain_c2:=remain_c2_cp
                   else remain_c2_cp:=remain_c2;

 % Compute all values modulo gb, drop all zeros
 remain_c2_cp:=cdr remain_c2_cp;
 while remain_c2_cp and
       (zerop car remain_c2_cp or
        (gb and zerop algebraic(preduce(num lisp car remain_c2_cp,gb)))) do
 remain_c2_cp:=cdr remain_c2_cp;

 if remain_c2_cp then <<     % s1 is NOT a special case of s2

  remain_c2_cp:=remain_c2;
  if tr_merge then <<write"remain_c2=";
                     print_indexed_list(cdr remain_c2_cp)>>;

  % Is there a contradiction of the type that the equivalence of two
  % assignments, a8=A (from sol1), a8=B (from sol2) requires 0=A-B
  %  which got transformed into an expression C which is built only
  % from free parameters of sol1 and therefore should not vanish?

  h:=cadddr sol1; % all free parameters in sol1
  while h and <<
   if tr_merge then write"Substitution of ",car h," by: ";
   repeat <<     % find a random integer for the free parameter
    a:=1+random(10000);   % that gives a regular substitution
    if tr_merge then <<write a$terpri()>>;
    a:=err_catch_sub(car h,a,remain_c2_cp)
   >> until a;
   remain_c2_cp:=a;
   while a and ((not numberp car a) or (zerop car a)) do a:=cdr a;
   not a
  >> do h:=cdr h;

  if h then return <<
   write"In the following S1 stands for ",s1,"and S2 stands for ",s2," . ",
        "Solution S1 fulfills all conditions of solution S2 when conditions",
        "are made denominator free. But, after rewriting solution S2 so that",
        "all free parameters of solution S1 are also free parameters of S2",
        "then the new solution S2 now requires the vanishing of an expression",
        "in these free parameters which is not allowed by S1. Therefore S1",
        "is not a special case of S2.";
   nil
  >>;

  if tr_merge and remain_c2_cp then
  <<write"remain_c2_cp after subst = "$mathprint cons('LIST,remain_c2)>>;
  write"Solution ",s1," is not less restrictive than solution"$terpri();
  write s2," and fulfills all conditions of solution ",s2," ."$terpri();
  write"But it was not possible for the program to re-formulate solution ";
  terpri()$ write s2," to include both solutions in a single set of"$terpri();
  write"assignments without vanishing denominators. :-( ";
  terpri();
  return nil

 >>              else return <<  % return the new s2 as s1 IS a special case of s2

  % Which inequality is to be dropped?
  ineq2:=car cddddr sol2;

  while ineq2 do <<
   ine:=car ineq2;
   % ine should not have denominators, so no extra precautions for substitution:
   for each a in ass1 do ine:=reval(subst(caddr a,cadr a,ine));
   if not zerop reval ine then ineqnew:=cons(car ineq2,ineqnew)
                          else ineqdrop:=cons(car ineq2,ineqdrop);
   ineq2:=cdr ineq2
  >>;

  if absorb then <<

   % transform the general solution if that was necessary and
   % updating the list of free parameters
   h:=cons('LIST,ass2);
   b:=cadddr sol2;
   if tr_merge then <<
    write"h0="$print_indexed_list(h);
    write"dropped_assign_in_s2="$print_indexed_list(dropped_assign_in_s2);
    write"new_assign_in_s2="$print_indexed_list(new_assign_in_s2);
   >>;
   for each a in dropped_assign_in_s2 do
   <<h:=delete(a,h);b:=cons(reval cadr a,b)>>;
   if tr_merge then <<write"h1="$print_indexed_list(h)>>;
   new_eqn:=cons('LIST,cadr sol2);
   for each a in reverse new_assign_in_s2 do if h then <<
    b:=delete(reval cadr a,b);
    if tr_merge then <<write"a=",a$terpri()$write"h2="$print_indexed_list(h)>>;
    h:=err_catch_sub(cadr a,caddr a,h);
    new_eqn:=err_catch_sub(cadr a,caddr a,new_eqn);
    if null new_eqn then h:=nil
                    else
    new_eqn:=algebraic(for each hh in new_eqn collect num hh);
    if h then h:=reval append(h,list a)
   >>;
   if null h then
   write"A seemingly successful transformation of ",s2,
        "went singular when performing the transformation ",
        "finally on the whole solution."
             else <<
    % the following is an improvement even on the original solution:
    % reduce the rhs of assignments with the remaining equations

    % Bring the new set of remaining equations into the form of a Groebner Basis
    if cdr new_eqn then algebraic <<
     if length new_eqn > 1 then <<
      torder(lisp(cons('LIST,b)),lex);
      gb:=groebner new_eqn;  % maybe covering this in a shell in case it
	 		     % takes too long
      if tr_merge then write "gb=",gb;
     >>;
     % Simplifying each rhs of h using gb
     lisp (h:=cons('LIST,for each hh in cdr h collect
                         if (pairp caddr hh) and
                            ((caaddr hh = 'QUOTIENT) or
                             ((caaddr hh = '!*SQ) and (denr cadr caddr hh neq 1))
                            ) then hh else
			 {'EQUAL,cadr hh,algebraic preduce(lisp caddr hh,gb)}));
    >>;

    % delete the redundant solution
    sol_list:=delete(s1,sol_list);
    prin2 "Should I delete "; prin s1; prin2 " perhaps?"; terpri(); %@@@@@
    % delete!-file!-exact s1;

    % save the generalized solution (ineqor of sol2 untouched)
    save_solution(cdr new_eqn,cdr h,b,ineqnew,cadr cddddr sol2,s2);

   >>
  >>;

  if absorb and null h then nil
                       else <<
   % report the merging
   if null ineqdrop then <<
    write"Strange: merging ",s1," and ",s2," without dropping inequalities!";
    terpri();
    write"Probably ",s2," had already been merged with ",s1,
         " or similar before."$ terpri()
   >>               else
   if print_ then <<
    write"Solution ",s2," includes ",s1," by dropping ";
    if length ineqdrop = 1 then write"inequality"
                           else write"inequalities"$terpri();
    for each ine in ineqdrop do mathprint ine
   >>;
   s2 % the more general solution
  >>
 >>
end;

symbolic procedure prepare_sol_list;
% Clarifies which list of solutions to be used for merging or printing
begin scalar s,h;

 change_prompt_to "";

 % reading in sol_list
 setq(s,bldmsg("%w%w",session_,"sol_list"));
 if not filep s then list_sol_on_disk() else <<
  in s;
  if null sol_list or zerop length sol_list then list_sol_on_disk() else <<
   h:=length sol_list;
   write"Do you want to see the list of names of the ";
   if h=1 then write"single solution? "
          else write h," solutions? (y/n) ";
   h:=termread();
   if h='y then <<terpri()$ write sol_list$terpri()$ terpri()>>;
   write"Is this the list to work on                           (Y)  "$terpri();
   write"or shall all solution files of this session in the "$        terpri();
   write"current directory be collected and used?              (N): ";
   h:=termread();
   if h='n then <<
    list_sol_on_disk();
    write"The following list is used:"$terpri()$ terpri();
    write sol_list$terpri()$ terpri()
   >>
  >>
 >>;
 restore_interactive_prompt();
end;

symbolic operator merge_sol;
symbolic procedure merge_sol;
begin scalar sol_cp,sl1,sl2,s1,s2,s3,sol1,sol2,echo_bak,semic_bak;

 if null session_ then ask_for_session() else <<
  write "Do you want to merge solutions computed in this session,";
  terpri();
  if not yesp "i.e. since loading CRACK the last time? " then
  ask_for_session()
 >>;

 prepare_sol_list();

 % % At fist sort sol_list by the number of free unknowns
 % for each s1 in sol_list do <<
 %  in s1;
 %  s2:=if null cadddr backup_ then 0 else length cadddr backup_;
 %  if cadr backup_ then s2:=s2 - length cadr backup_;
 %  sol_cp:=cons((s2 . s1),sol_cp)
 % >>;
 % sol_cp:=idx_sort(sol_cp);
 % while sol_cp do <<sl1:=cons(cdar sol_cp,sl1);sol_cp:=cdr sol_cp>>;

 sol_cp:=sol_list;
 sl1:=sol_cp;

 if sl1 then
 while sl1 and cdr sl1 do <<
  s1:=car sl1; sl1:=cdr sl1;
  %infile s1;
  echo_bak:=!*echo; semic_bak:=semic!*;
  semic!*:='!$; in s1;
  !*echo:=echo_bak; semic!*:=semic_bak;
  sol1:=backup_;
  if print_ then <<write"Comparing ",s1," with:"$terpri()>>;

  sl2:=sl1;
  while sl2 do <<
   s2:=car sl2; sl2:=cdr sl2;
   %infile s2;
   echo_bak:=!*echo; semic_bak:=semic!*;
   semic!*:='!$; in s2;
   !*echo:=echo_bak; semic!*:=semic_bak;
   sol2:=backup_;
   if print_ then <<write"  ",s2$terpri()>>;

   if (null car sol1) and (null car sol2) then % no dependencies, ie alg. problem
   % We assume that each remaining equation determines one unknown
   if (length cadddr sol1 - length cadr sol1) <
      (length cadddr sol2 - length cadr sol2) then s3:=merge_two(s1,sol1,s2,sol2,t)
   else
   if (length cadddr sol1 - length cadr sol1) >
      (length cadddr sol2 - length cadr sol2) then s3:=merge_two(s2,sol2,s1,sol1,t)
   else <<
    if null (s3:=merge_two(s1,sol1,s2,sol2,t)) then
             s3:=merge_two(s2,sol2,s1,sol1,t);
    if s3 then <<
     write"Strange: ",s1," is contained in ",s2$terpri();
     write"but both have same number of free unknowns!"$terpri();
     write"One of them has probably undergone earlier merging";
     terpri();
    >>
   >>;
   if s3=s1 then sl1:=delete(s2,sl1) else % not to pair s2 later
   if s3=s2 then sl2:=nil                 % to continue with next element in sl1
  >>
 >>;

 save_sol_list()
end;

symbolic procedure save_sol_list;
% write the content of sol_list in the bu???-sol_list file.
begin scalar s;
 setq(s,bldmsg("%w%w",session_,"sol_list"));
 out s;
 write"off echo$ "$ terpri();
 if null sol_list then write"sol_list:=nil"
                  else <<
  write"sol_list:='";
  print sol_list;
 >>;
 write"$"$terpri();
 write"end$"$terpri();
 shut s
end;

symbolic procedure delete_empty_sol_list_file();
if null sol_list and
   not filep process_counter and
   null reduce_call
then delete!-file!-exact bldmsg ("%w%w",session_,"sol_list");

symbolic procedure add_to_sol_list$  % Sergey's version
  if sol_list then
  begin
    scalar fl,fpid,file,pipein,st,cnt; %,fd
    file := bldmsg("%wsol_list", session_);
    fpid := bldmsg("%s.%w", file, getpid());

    fl:=1; cnt:=0;
    repeat <<
      fl := rename!-file(file, fpid);
      if null fl then <<  % file does not exist, is it currently changed?
        pipein:=pipe!-open(bldmsg("ls %s*",file),'input);
% The next line seems to be PSL specific...
        st:=channelreadline pipein;  %st="bu123456-sol_list11221121"
        close pipein;

        if st neq "" then sleep 1 % file is currently changed
        else if cnt<4 then <<    % file does not seem to exist nor being changed
          cnt:=add1 cnt;
          sleep 1 >>
        else <<    % file has most likely never existed --> create fpid
          out fpid;
          write"off echo$ ";
          terpri();
          write"sol_list:='";
          print sol_list;
          write"$";
          terpri();
          write"end$";
          terpri();
          shut fpid;
          fl:=t >> >>
     >> until fl;
%we have successfully renamed (or created) the file
    backup_:=sol_list;
    in fpid;

    sol_list:=union(sol_list,backup_);

    out fpid;
    write"off echo$ ";
    terpri();
    write"sol_list:='";
    print sol_list;
    write"$";
    terpri();
    write"end$";
    terpri();
    shut fpid;

    fl:=1;
    repeat <<
      fl := rename!-file(fpid, file);
      if null fl then sleep 1
    >> until fl;

% fd := nil;
% while not fd do <<
%  sleep 1;
%  fl := system bldmsg ("cp %s %s",fpid,file);
%  fd := if fl = 0 then t else nil;
%  if fd then fd := filestatus(file,nil)
% >>;

% fd := nil;
% while not fd do <<
%  sleep 1;
%  fl := delete!-file!-exact fpid;
%  fd := if fl = 0 then t else nil
% >>;
  end;

symbolic procedure ask_for_session;
<<change_prompt_to "Name of the session in double quotes (e.g. ""bu263393-""): ";
  terpri();
  session_:=termread();
  restore_interactive_prompt()
>>;

symbolic operator pri_sol;
symbolic procedure pri_sol(sin,assgn,crout,html,solcount,fname,prind);
% print the single solution sin
begin scalar a,b,c,sout,echo_bak,semic_bak;
 echo_bak:=!*echo; semic_bak:=semic!*;
 semic!*:='!$; in sin;
 !*echo:=echo_bak; semic!*:=semic_bak;

 if html then <<
  setq(sout,bldmsg("%w%w%d%w",fname,"-s",solcount,".html"));
  out sout;

  write"<html>"$terpri();
  terpri();
  write"<head>"$terpri();
  write"<meta http-equiv=""Content-Type"" content=""text/html;"$terpri();
  write"charset=iso-8859-1"">"$terpri();
  write"<title>Solution ",solcount," to problem ",prind,"</title>"$terpri();
  write"</head>"$terpri();
  terpri();
  write"<BODY TEXT=""#000000"" BGCOLOR=""#FFFFFF"">"$terpri();
  terpri();
  write"<CENTER><H2>Solution ",solcount," to problem ",prind,"</H2>"$terpri();
  write"<HR>"$terpri();
  if cadr backup_ then <<write"<A HREF=""#1"">Remaining equations</A> | ";
                         terpri()>>;
  write"<A HREF=""#2"">Expressions</A> | "$terpri();
  write"<A HREF=""#3"">Parameters</A> | "$terpri();
  write"<A HREF=""#4"">Inequalities</A> | "$terpri();
  write"<A HREF=""#5"">Relevance</A> | "$terpri();
  write"<A HREF=",prind,".html>Back to problem ",prind,"</A> ";
  write"</CENTER>"$terpri();
  terpri()
 >>;
 for each a in car backup_ do
 for each b in cdr a do
 algebraic(depend(lisp(car a),lisp b));
 backup_:=cdr backup_;
 terpri();
 if html then write"<!-- ";
 write">>>=======>>> SOLUTION ",sin," <<<=======<<<";
 if html then write" --> ";
 terpri()$terpri();

 if assgn or html then <<
  if car backup_ then <<
   if html then <<
    write"<HR><A NAME=""1""></A><H3>Equations</H3>"$terpri();
    write"The following unsolved equations remain:"$terpri();
    write"<pre>";
   >>      else write"Equations:";
   for each a in car backup_ do mathprint {'EQUAL,0,a};
   if html then <<write"</pre>"$terpri()>>
  >>;

  if html then <<
   write"<HR><A NAME=""2""></A><H3>Expressions</H3>"$terpri();
   write"The solution is given through the following expressions:"$terpri();
   write"<pre>"$terpri();
   for each a in cadr backup_ do mathprint a;
   write"</pre>"$terpri()
  >>      else <<
   b:=nil;
   for each a in cadr backup_ do
%   if not sqzerop caddr a then
   b:=cons({'EQUAL,cadr a,
            if pairp caddr a and car caddr a='!*SQ then cadr caddr a
                                                   else simp caddr a},b);
   print_forg(b,nil)
  >>;
  terpri();

  if html then <<
   write"<HR><A NAME=""3""></A><H3>Parameters</H3>"$terpri();
   write"Apart from the condition that they must not vanish to give"$terpri();
   write"a non-trivial solution and a non-singular solution with"$terpri();
   write"non-vanishing denominators, the following parameters are free:"$terpri();
   write"<pre> ";
   fctprint caddr backup_;
   write"</pre>"$terpri()
  >>      else <<
   write length caddr backup_," free unknowns: "$ listprint caddr backup_;
   print_ineq ((for each a in     cadddr backup_ collect simp a) .
               (for each a in car cddddr backup_ collect % each a is an or-inequality
                for each b in a collect % each b represents an expression
                for each c in b collect % in form of factors c
                simp c));
  >>;

  if html then <<
   write"<HR><A NAME=""4""></A><H3>Inequalities</H3>"$terpri();
   write"In the following not identically vanishing expressions are shown."$  terpri();
   write"<pre> ";
   mathprint cons('LIST,cadddr backup_);
   write"</pre>"$terpri();

   if cddddr backup_ and car cddddr backup_ then <<
    write"Next come so-called OR-lists of FACTOR-lists in the following sense."$terpri();
    write"Each FACTOR-list represents the factors of an expression and at least one of"$terpri();
    write"these expressions must not vanish in each OR-list. In other words, in each"$terpri();
    write"OR-list at least one FACTOR-list must not vanish, i.e. none of the expressions"$terpri();
    write"in the FACTOR-list may vanish.<BR>"$terpri();

    for each a in car cddddr backup_ do <<
     write"OR-list:"$terpri();
     write"<pre> ";
     mathprint cons('LIST,for each b in a collect cons('LIST,b));
     write"</pre>"$terpri()
    >>

   >>

  >>;
 >>;

 if html then <<
  write"<HR><A NAME=""5""></A><H3>Relevance for the application:</H3>";
  terpri();
  % A text for the relevance should be generated in crack_out()
  write"<pre>"
 >>;
 if crout or html then <<
  algebraic (
  crack_out(lisp cons('LIST,car backup_),
            lisp cons('LIST,cadr backup_),
            lisp cons('LIST,caddr backup_),
            lisp cons('LIST,cadddr backup_),
            lisp solcount));
 >>;
 if html then <<
  write"</pre>"$terpri();
  write"<HR>"$terpri();
  write"</body>"$terpri();
  write"</html>"$terpri();
  shut sout
 >>
end;

symbolic operator print_all_sol;
symbolic procedure print_all_sol;
begin scalar a,assgn,crout,natbak,print_more_bak,fname,solcount,
             html,prind;

 write"This is a reminder for you to read in any file CRACK_OUT.RED";
 terpri();
 write"with a procedure CRACK_OUT() in case that is necessary to display";
 terpri();
 write"results following from solutions to be printed.";
 terpri()$ terpri();

 if null session_ then ask_for_session() else <<
  write "Do you want to print solutions computed in this session,";
  terpri();
  if not yesp "i.e. since loading CRACK the last time? " then
  ask_for_session();
 >>;

 prepare_sol_list();

 natbak:=!*nat$ print_more_bak:=print_more$ print_more:=t;
 if yesp "Do you want to generate an html file for each solution? "
 then <<
  html:=t;
  terpri();
  write "What is the file name (including the path)";
  terpri();
  write "that shall be used (in double quotes) ? ";
  terpri();
  write "(A suffix '-si'  will be added for each solution 'i'.) ";
  change_prompt_to "";
  fname:=termread()$terpri();
  write "What is a short name for the problem? ";
  prind:=termread();
  restore_interactive_prompt();
  terpri();
 >> else <<
  if yesp "Do you want to see the computed value of each function? "
  then assgn:=t;
  if yesp "Do you want procedure `crack_out' to be called? " then <<
   crout:=t;
   if flin_ and fhom_ then
   if yesp "Do you want to print less (e.g. no symmetries)? "
   then print_more:=nil;
   if not yesp
   "Do you want natural output (no if you want to paste and copy)? "
   then !*nat:=nil;
  >>;
 >>;
 solcount:=0;
 fsub_:=nil$ % in case a computation has been interrupted
             % fsub_ may not be nil but should be nil for
             % printing the assignments in each solution
 for each a in sol_list do <<
  solcount:=add1 solcount;
  pri_sol(a,assgn,crout,html,solcount,fname,prind);
 >>;
 !*nat:=natbak;
 print_more:=print_more_bak
end;

symbolic procedure frequent_factors(pdes);
% look for pde in pdes which can be factorized
begin scalar p,pv,f,fcl,fcc,h,nf$ %,h1;

 for each p in pdes do <<
  pv:=get(p,'fac);
  if pairp pv then <<
   % pv:=cdr pv$  % drop 'TIMES to get the list of factors in p

   nf:=length pv$ % the number of factors
   % increment the counter of appearances of each factor
   % the minimal number of factors of an equation of which f is a factor
   % and the number of such equations
   % fcc={ {# of appearences of factor,
   %        {min # of factors of an equation of which f is a factor,
   %         # of such equations},
   %        the factor now in SQ-form
   %       }, ...}
%   h1:=pv;
%   while h1 do <<  % for each factor
   while pv do <<  % for each factor
%    f:=car h1; h1:=cdr h1;
    f:=car pv; pv:=cdr pv;

    fcc:=fcl;

    % fcl is list of lists, see above
    while fcc and (caddar fcc neq f) do fcc:=cdr fcc;

    if fcc then <<      % factor had already appeared
     h:={add1 caar fcc,
         if nf<caadar fcc then {nf,1} else
	 if nf=caadar fcc then {nf,add1 cadr cadar fcc} else
	 cadar fcc,
	 f};
     rplaca(fcc,h);
    >>     else         % factor is new
    fcl:=cons({1,{nf,1},f},fcl)
   >>$    % done for all factors
  >>
 >>$  % looked at all factorizable equations
 return rev_idx_sort fcl;
end$ % of frequent_factors

symbolic procedure print_factors(pdes);
begin scalar fcl,p,q;
 fcl:=reverse frequent_factors pdes;
 write"Number of occurences, eqn of fewest # of factors, the factor: "$terpri();
 for each p in fcl do
 if (q:=pdeweightSF(numr caddr p,ftem_))>print_ then
 <<write car p,",",cadr p," : ",no_of_tm_sf numr caddr p," terms"$terpri()>>
                                                else
 <<write car p,",",cadr p," : ";
   p:={'!*sq,caddr p,t};
   if q=1 then <<write reval p$terpri()>>
          else mathprint p
 >>
end;

symbolic procedure case_on_most_frequ_factors(arglist);
begin scalar h,maxf,best,h3,h4;
 h:=frequent_factors car arglist;
 if null h then return nil;
 maxf:=caar h;

 % find a factor which has at least 20% of the max number of
 % appearences of the most frequent factor but occurs in an
 % equation with the fewest factors
% best:=car h; h:=cdr h;
 while h and (((caar h)*10-maxf*2)>0) do <<

  % Check whether this factor set to zero provides a substitution
  % without case distinction
  if not pairp caddar h then h4:=t
                        else <<
   h3:=mkeqSQ(caddar h,nil,nil,ftem_,vl_,allflags_,t,list(0),errorset_control,errorset_control);
   % the last argument is nil to avoid having a lasting effect on pdes
   fcteval(h3);
   h4:=get(h3,'fcteval_lin) or get(h3,'fcteval_nca);
   drop_pde(h3,nil,nil);
  >>;

  % Check whether this factor set to non-zero changes a substitution from
  % needing a case distinction to not needing a case distinction
  % ... to be done

  if h4 and
     ((null best                     ) or
      ( (caadar h)<(caadr best)      ) or
      (((caadar h)=(caadr best)) and
       ((cadadr car h)>(cadadr best)))    )
  then best:=car h;
  h:=cdr h
 >>;

 return
 if best then split_into_cases({car arglist,cadr arglist,
                                caddr arglist,caddr best})
         else nil
end;

symbolic procedure sol_in_list(set1,set2,sol_list2);
begin scalar set2cp,s1,s2,found,sol1,sol2,same_sets,echo_bak,semic_bak;
 while set1 do <<
  s1:=car set1; set1:=cdr set1;
  %infile s1;
  echo_bak:=!*echo; semic_bak:=semic!*;
  semic!*:='!$; in s1;
  !*echo:=echo_bak; semic!*:=semic_bak;
  sol1:=backup_;
  set2cp:=set2;
  found:=nil;
  while set2cp and not found do <<
   s2:=car set2cp; set2cp:=cdr set2cp;
   %infile s2;
   echo_bak:=!*echo; semic_bak:=semic!*;
   semic!*:='!$; in s2;
   !*echo:=echo_bak; semic!*:=semic_bak;
   sol2:=backup_;
   found:=merge_two(s1,sol1,s2,sol2,nil);
  >>;
  if not found then <<
   same_sets:=nil;
   if print_ then <<
    write"Solution ",s1," is not included in ",sol_list2;
    terpri()
   >>
  >>
 >>;
 return same_sets
end;

symbolic operator same_sol_sets;
symbolic procedure same_sol_sets;
begin scalar session_bak,set1,set2,sol_list1,sol_list2,echo_bak,semic_bak;
 session_bak:=session_;
 write"Two sets of solutions are compared whether they are identical.";

 write"What is the name of the session that produced the first set of solutions?";
 terpri();
 write"(CRACK will look for the file `sessionname'+`sol_list'.)"$terpri();
 ask_for_session();

 % reading in sol_list
 setq(sol_list1,bldmsg("%w%w",session_,"sol_list"));
 %infile sol_list1;
 echo_bak:=!*echo; semic_bak:=semic!*;
 semic!*:='!$; in sol_list1;
 !*echo:=echo_bak; semic!*:=semic_bak;
 set1:=sol_list;

 write"What is the name of the session that produced the second set of solutions?";
 terpri();
 ask_for_session();

 % reading in sol_list
 setq(sol_list2,bldmsg("%w%w",session_,"sol_list"));
 %infile sol_list2;
 echo_bak:=!*echo; semic_bak:=semic!*;
 semic!*:='!$;
 in sol_list2;
 !*echo:=echo_bak; semic!*:=semic_bak;
 set2:=sol_list;

 session_:=session_bak;

 % 1. Check that all solutions in set1 are included in set2.

 sol_in_list(set1,set2,sol_list2);
 sol_in_list(set2,set1,sol_list1);

end;

symbolic operator clear_files;

symbolic procedure clear_files;
  begin scalar s;
    s:=explode session_;
    s:=compress cons(car s,cdddr s);
    delete!-file!-match bldmsg("%w%w%w","??",s,"*");
  end;

symbolic procedure list_sol_on_disk;
% Find all so* solution files with the current session_ number in
% the current directory and write them into the bu????-sol_list file.
  begin
    scalar s,chn,xx,oldcase;
    s:=level_string(session_);
    s:=explode s;
    s:=compress cons(car s,cons('s,cons('o,cdddr s)));
!#if (memq 'csl lispsystem!*)
    rederr "non-portable code encountered in list_sol_on_disk";
!#endif
    system bldmsg("ls %s* > %w%w",s,session_,"sol_list");
    chn := open(bldmsg("%w%w",session_,"sol_list"),'input);
    chn := rds chn;
    sol_list:=nil;
% input!-case is a PSLism.
    oldcase := input!-case  NIL;
    while (xx := read()) and (xx neq int2id 4) do
    sol_list:=cons(bldmsg("%w",xx),sol_list);
    close rds chn;
    save_sol_list();
    input!-case oldcase;
  end;

symbolic procedure fnc_of_new_var;
% input: global variables: done_trafo,depl!*
% output: all functions depending on (new) lhs variables in done_trafo
begin scalar h4,h5,h6;
 h4:=for each h5 in cdr done_trafo join
     for each h6 in cdr h5 collect cadr h6;
%write"h4=",h4$ terpri();
%write"depl!*=",depl!*$  terpri();
 % then find all functions of these new variables
 h5:=nil;
 for each h6 in depl!* do
 if not freeoflist(h6,h4) then h5:=cons(car h6,h5);
 return h5
end;


% to allow special characters in file name, like space

!#if (memq 'csl lispsystem!*)

% CSL can do the simpler case directly.
symbolic procedure delete!-file!-exact fi;
  delete!-file fi;

!#else

symbolic procedure delete!-file!-exact fi;
  if (memq('linux!-gnu, lispsystem!*) or
      memq('cygwin, lispsystem!*) or
      memq('unix, lispsystem!*)) and
     not memq('win32, lispsystem!*) and
     not memq('win64, lispsystem!*) then system bldmsg("rm -f %s", fi)
% On Windows I only delete the file if it exists, so that I avoid messages
% that otherwise intrude.
  else if filep fi then system bldmsg("del ""%s""", fi);

!#endif

% To have ? or * actively matching in file name

!#if (and (memq 'csl lispsystem!*) (not (memq 'jlisp lispsystem!*)))

% If I assume that Java 7 with its version of the nio package is
% available then supporting this in Jlisp would be easy. However I will
% wait before I move to that.

symbolic procedure delete!-file!-match fi;
  delete!-wildcard fi;

!#else

symbolic procedure delete!-file!-match fi;
% Note that a Macintosh is "unix" for the purposes of the test here.
  if (memq('linux!-gnu, lispsystem!*) or
      memq('cygwin, lispsystem!*) or
      memq('unix, lispsystem!*)) and
     not memq('win32, lispsystem!*) and
     not memq('win64, lispsystem!*) then system bldmsg("rm -f %s", fi)
% On Windows if there are no files matching the pattern you specify you will
% get an ugly message saying "Could Not Find FILE". I hope that the quote
% marks I put in protect any whitespace within the pathname used, but
% neverthless allow wildcards to be interpreted.
  else begin
% On Windows if you go "del" with a pattern that does not match any files
% then an unwanted message is displayed. To avoid that I will create a file
% that matches the pattern so that there is always something worth deleting.
    scalar u;
% I will turn every "?" or "*" into an "x" to get a name suitable for a
% single file.
    for each c in explode fi do
      if c = '!? or c = '!* then u := 'x . u
      else u := c . u;
    u := compress reverse u;
% Opening the file for output and then closing the stream should leave
% an empty file for me to delete.
    u := open(u, 'output);
    if u then close u;
    return system bldmsg("del ""%s""", fi)
  end;

!#endif

!#if (memq 'psl lispsystem!*)

% Rename fromname to toname and return t on success.

symbolic procedure rename!-file(fromname, toname);
  begin
    if system bldmsg("mv %w %w", fromname, toname) = 0 then return t
    else return nil
  end;

!#endif

endmodule;

%********************************************************************
module uniquify;
%********************************************************************
%  Routines to replace kernels by unique instances in 'standard' expressions.
%  Replacement is done in place for performance and space savings.
%  Author: Eberhard Schruefer, Oct 2007

symbolic procedure uniquifysq u;
   begin
     uniquifyf numr u;
     uniquifyf denr u;
     return u
   end;

symbolic procedure uniquifyf u;
   begin
     if domainp u then return nil
      else if atom mvar u then nil
      else rplaca(lpow u,uniquifyk mvar u);
     uniquifyf lc u;
     uniquifyf red u;
     return u
   end;

%symbolic procedure uniquifyk u;
%   begin scalar x;
%     x := fkern u;
%     if memq('used!*,cddr x) then return car x
%      else aconc(x,'used!*);
%     for each arg in cdr u do
%       if atom arg then nil
%        else uniquifyk arg;
%     return car x
%   end;

symbolic procedure uniquifyk u;
   begin scalar x;
     if sfp u then uniquifyf u;
     x := fkern u;
     if sfp car x then return car x;
     if memq('used!*,cddr x) then return car x
      else aconc(x,'used!*);
     for each arg in cdr u do
       if atom arg then nil
        else uniquifyk arg;
     return car x
   end;

symbolic procedure uniquifykord u;
   for each j in u collect if atom j then j
                            else uniquifyk j;

symbolic procedure uniquifydepl u;
   for each j in u collect if atom car j then j
                            else (uniquifyk car j . cdr j);

symbolic procedure uniquifyasymplis u;
   for each j in u collect if atom car j then j
                            else (uniquifyk car j . cdr j);

symbolic procedure uniquenesssq u;
<<uniquenessf numr u;
  uniquenessf denr u;
>>;

symbolic procedure UniquifyAll(pdes,forg);
begin scalar a,b,c;
 for each a in pdes do <<
  uniquifysq get(a,'sqval);
  if pairp get(a,'fac) then
  for each b in get(a,'fac) do uniquifysq b;
  for each b in get(a,'fcteval_lin) do uniquifysq car b;
  for each b in get(a,'fcteval_nca) do uniquifysq car b;
  for each b in get(a,'fcteval_nli) do uniquifysq car b;
  for each b in get(a,'fct_nli_lin) do uniquifysq car b;
  for each b in get(a,'fct_nli_nca) do uniquifysq car b;
  for each b in get(a,'fct_nli_nli) do uniquifysq car b;
  for each b in get(a,'fct_nli_nus) do uniquifysq car b
 >>;
 for each a in forg do if pairp a and car a = 'EQUAL then uniquifysq caddr a;
 for each a in ineq_ do uniquifysq a;
 for each a in ineq_or do
  for each b in a do
   for each c in b do uniquifysq c
end;

symbolic procedure uniquenessf u;
begin
 if domainp u then return;
 if null domainp u
 and null atom mvar u
 then if null atsoc(mvar u,get(car mvar u,'klist))
 then write "head kernel of ",u," is not unique!";
 uniquenessf lc u;
 uniquenessf red u;
end;

endmodule;

%********************************************************************
module parseformoutput;
%********************************************************************
%  Parser for polynomials generated by FORM.
%  Parses directly into REDUCE standard forms.
%  For this to be correct kernel ordering in FORM
%  and REDUCE must be the same and 'on highfirst;'
%  must be isssued in generating FORM output.
%
%  Syntax: formoutputread <filename>;
%  Alternate syntax:  formoutput <FORM polynomial>; (currently not maintained)
%  Result: REDUCE prefix sq.
%
%  Author: Eberhard Schruefer, Oct 2007
%
%  Needs module uniquify.

fluid '(!*msg !*int semic!*);

global '(cursym!* nxtsym!*);

symbolic procedure formoutstat;
   begin scalar x,y,s,!*msg;
     newtok '((!+) formoutplus);
     newtok '((!-) formoutminus);
     flag('(formoutplus),'delim);
     flag('(formoutminus),'delim);
     if nxtsym!* eq '!- then scan();
     if cursym!* eq 'formoutminus then s := -1
      else s := 1;
     x := y := formoutterm(s,xread t);
     if cursym!* eq '!*semicol!* then go to b;
   a: if cursym!* eq 'formoutminus then s := -1
       else s := 1;
      plantlowerterm(y,formoutterm(s,xread t));
      if null domainp y and red y then y := red y;
      if null(cursym!* eq '!*semicol!*) then go to a;
   b: remflag('(formoutplus),'delim);
      remflag('(formoutminus),'delim);
      newtok '((!+) plus);
      newtok '((!-) difference);
%  write x;
%   return mkquote x
   end;

put('formoutput,'stat,'formoutstat);

symbolic procedure formoutputread u;
   begin scalar x,y,s,!*msg,ichan,oldichan,!*int,semic;
     ichan := open(mkfil!* u,'input);
     oldichan := rds ichan;
     newtok '((!+) formoutplus);
     newtok '((!-) formoutminus);
     flag('(formoutplus),'delim);
     flag('(formoutminus),'delim);
     semic := semic!*;
     scan();
     if cursym!* eq 'formoutminus then <<s := -1; scan()>>
      else s := 1;
     x := y := formoutterm(s,xread1 t);
     if cursym!* eq '!*semicol!* then go to b;
   a: if cursym!* eq 'formoutminus then s := -1
       else s := 1;
      plantlowerterm(y,formoutterm(s,xread t));
      if null domainp y and red y then y := red y;
      if null(cursym!* eq '!*semicol!*) then go to a;
   b: remflag('(formoutplus),'delim);
      remflag('(formoutminus),'delim);
      newtok '((!+) plus);
      newtok '((!-) difference);
      rds oldichan;
      close ichan;
      semic!* := semic;
     return if domainp x then x else mk!*sq((if alg_poly then         x
                                                         else reorder x) ./ 1)
 % alg_poly test only if FORM does not use REDUCE ordering of non-atomar kernels.

   end;


symbolic procedure formoutterm(s,u);
   begin scalar numc;
     if null eqcar(u,'times)
        then return if numberp u then u*s
                     else if atom u then u .** 1 .* s .+ nil
                     else if car u eq 'quotient then '!:rn!: . (cadr u ./ caddr u)
                     else if car u eq 'expt
                       then (if atom cadr u then cadr u
                              else uniquifyk cadr u) .** caddr u .* s .+ nil
                     else uniquifyk u .** 1 .* s .+ nil;
     u := cdr u;
     numc := s;
     if numberp car u then <<numc := s*car u; u := cdr u>>;
     if eqcar(car u,'quotient) then <<numc := '!:rn!: . ((s*cadar u) ./ caddar u);
                                      u := cdr u>>;
     return formoutnestterm(u,numc)
   end;

symbolic procedure formoutnestterm(u,numc);
   if null u then numc
    else if atom car u then car u .** 1 .* formoutnestterm(cdr u,numc) .+ nil
    else if caar u eq 'expt
      then (if atom cadar u then cadar u else uniquifyk cadar u) .** caddar u .*
           formoutnestterm(cdr u,numc) .+ nil
    else uniquifyk car u .** 1 .* formoutnestterm(cdr u,numc) .+ nil;

symbolic procedure plantlowerterm(u,v);
   if domainp v then rplacd(u,v)
    else if (mvar u eq mvar v) and (ldeg u = ldeg v)
            then begin
                   a: if domainp v then go to c;
                      v := lc v; u := lc u;
                      if (mvar u eq mvar v) and (ldeg u = ldeg v)
                         then go to a;
                      c: if null red u then return rplacd(u,v);
                      b: u := red u;
                         go to c;
                  end
          else rplacd(u,v);

endmodule;

%********************************************************************
module writefrm;
%********************************************************************
%  Very raw printing functions for SQ's, intended for generating input
%  to FORM. The written expression is terminated by a semicolon.
%  Only rational numbers are supported as domain.
%
%  Syntax: writesqfrm <standard quotien>;
%
%  Author: Eberhard Schruefer, Nov 2007, with a modification by
%  Winfried Neun to allow piping (to FORM)

symbolic procedure writesqfrm u;
   begin
     if denr u = 1 then <<writefrm numr u; prin2t ";">>
      else if numberp denr u
              then if red numr u
                      then <<prin2 "("; writefrm numr u; prin2 ")/";
                             writefrm denr u; prin2t ";">>
                    else <<writefrm numr u; prin2 "/";
                           writefrm denr u; prin2 ";">>
      else if numberp numr u or null red numr u
        then <<writefrm numr u; prin2 "/(";
               writefrm denr u; prin2t ");">>
      else <<prin2 "("; writefrm numr u; prin2 ")/(";
             writefrm denr u; prin2t ");">>
   end;

symbolic procedure writesffrm u;
   begin <<writefrm u; prin2t ";">> end;

symbolic procedure writefrm1 u;
   begin scalar y;
     if domainp u then return if u = 1 then prin2 u
                               else writedomain u;
     if atom mvar u then prin2 mvar u else writekern mvar u;
     if not(ldeg u = 1) then <<prin2 "^"; prin2 ldeg u>>;
     y := lc u;
     if domainp y then return if y = 1 then prin2 " "
                               else <<prin2 " * ";
                                      writedomain y;
                                      prin2 " " >>;
     if null red y then return <<prin2 " * "; writefrm1 y>>;
     prin2 "* (";
     a: writefrm1(lt y .+ nil);
        y := red y;
        if domainp y then go to b;
        if y then prin2 " + ";
        go to a;
     b: if numberp y and minusp y then <<prin2 " - "; y := -y>>
         else if y then prin2 " + ";
        if y then writefrm1 y;
        if y then prin2 ") " else prin2 ")"
    end;

symbolic procedure writefrm u;
   begin
     a: if domainp u then go to b;
        writefrm1(lt u .+ nil);
        u := red u;
        if numberp u and minusp u
           then <<prin2 " - "; u := -u>>
         else  if u then prin2 " + ";
        go to a;
     b: if u then prin2 u;
   end;

symbolic procedure writekern u;
   begin
     prin2 car u;
     prin2 "(";
     a: u := cdr u;
        if null u then go to b;
        if atom car u or numberp car u then prin2 car u
         else writekern car u;
        if cdr u then prin2 ",";
        go to a;
     b: prin2 ")"
   end;

symbolic procedure writedomain u;
   begin
     if numberp u and minusp u
        then << prin2 "("; prin2 u; prin2 ")">>
      else if eqcar(u,'!:rn!:)
        then << prin2 "("; prin2 cadr u; prin2 "/";
                prin2 cddr u; prin2 ")">>
      else prin2 u
   end;


endmodule;

%********************************************************************
module consistency_checks;
%********************************************************************
%  Routines for checking integrity of data
%  Author: Thomas Wolf Dec 2001

% old prefix form:
%symbolic procedure check_history(pdes);
%begin scalar p,q,h,k;
% for each p in pdes do <<
%  h:=get(p,'histry_);
%  for each q in pdes do
%  h:=subst(prepsq get(q,'sqval),q,h);
%  if not zerop reval {'DIFFERENCE,prepsq get(p,'sqval),h} then <<
%   write"The history value of ",p," is not correct!";
%   k:=t;
%   terpri()
%  >>
% >>;
% if null k then <<write"History data are consistent."$ terpri()>>
%end;

% new sq-from:
symbolic procedure check_history(pdes);
begin scalar p,q,h,k;
 for each p in pdes do <<
  h:=simp get(p,'histry_);
  for each q in pdes do
  h:=subsq(h,{(q . {'!*SQ,get(q,'sqval),t})});
  if not sqzerop subtrsq(get(p,'sqval),h) then <<
   write"The history value of ",p," is not correct!";
   k:=t;
   terpri()
  >>
 >>;
 if null k then <<write"History data are consistent."$ terpri()>>
end;

%-------------------------------

symbolic procedure check_globals;
% to check validity of global variables at start of CRACK
begin scalar flag, var;

 % The integer variables
 foreach var in global_list_integer do
 if not fixp eval(var) then <<
  terpri();
  write var, " needs to be an integer: ", eval(var)," is invalid";
  flag := var
 >>;

 % Now for integer variables allowed to be nil
 foreach var in global_list_ninteger do
 if not fixp eval(var) and eval(var) neq nil then <<
  terpri();
  write var, " needs to be an integer or nil: ",
  eval(var)," is invalid";
  flag := var
 >>;

 % Finally variables containing any number
 foreach var in global_list_float do
 if not numberp eval(var) then <<
  terpri();
  write var, " needs to be a number: ", eval(var)," is invalid";
  flag := var
 >>;

 return flag
end;

%-------------------------------

symbolic procedure InternTest(pdes,forg);
begin scalar a,b,c;
 for each a in pdes do <<
  uniquenesssq get(a,'sqval);
  if pairp get(a,'fac) then
  for each b in get(a,'fac) do uniquenesssq b;
  for each b in get(a,'fcteval_lin) do uniquenesssq car b;
  for each b in get(a,'fcteval_nca) do uniquenesssq car b;
  for each b in get(a,'fcteval_nli) do uniquenesssq car b;
  for each b in get(a,'fct_nli_lin) do uniquenesssq car b;
  for each b in get(a,'fct_nli_nca) do uniquenesssq car b;
  for each b in get(a,'fct_nli_nli) do uniquenesssq car b;
  for each b in get(a,'fct_nli_nus) do uniquenesssq car b
 >>;

 for each a in forg do if pairp a and car a = 'EQUAL then uniquenesssq caddr a;
 for each a in ineq_ do uniquenesssq a;
 for each a in ineq_or do
  for each b in a do
   for each c in b do uniquenesssq c
end;

%-------------------------------

endmodule;

%********************************************************************
module treeofcases;
%********************************************************************
%  Routines for storeing and updating the tree of cases
%  Author: Thomas Wolf, May 2010

%------------
% to speed up
% - the calls of consistenttree() can be commented out
% - the line with @@@@@ can be un-commented to cut the completely
%   solved branches out of the case tree
%------------

symbolic procedure consistenttree(ct,lv);
% - It can not be that a case is solved if at least
%   one of its sub-cases is unsolved.
% - It can not be that a case is not completely solved but the
%   crack backup file does not exist.

if ct and cddddr ct then
if zerop cadddr ct then
write "### ERROR in CaseTree: Case ",append(lv,{car ct})," has not started",
      " but has already sub-cases!"
                   else
begin scalar ctc,un;
 ctc:=cddddr ct;
 lv:=append(lv,{car ct});
 while ctc do <<
  consistenttree(car ctc,lv);
  if cadddr car ctc < 2 then un:=t;
  ctc:=cdr ctc
 >>;
 % The following situation happens regularly when the last subcase
 % has just been completed and should therefore not be reported.
 % if cadddr ct < 2 and null un then
 % write "### ERROR in CaseTree: Case ",lv," is not finished",
 %       " but all subcases are completed!";
 if cadddr ct > 1 and un then
 write "### ERROR in CaseTree: Case ",lv," is completed",
       " but not all subcases are completed!";
end;

%===========

symbolic procedure CaseTree(inp);
% inp is of one of the 3 types:
%  {{'EQUAL,0,pf}} : a new case pf= 0 is to start
%  {{'INEQ ,0,pf}} : a new case pf<>0 is to start
%  n (a digit)     : the current case is to be closed, n = # of solutions

if session_ and % Otherwise the current computation is a side computation
                % which should not interfere with the case tree.
   keep_case_tree then
begin
 comment
  The stored list is nil, or no file is stored if no case
  distinction has happened yet.

  A single subcase has the structure:  {a1,a2,a3,a4[,a5[,..]]}
  These are recursively nested.

  a1 : the number of the subcase, i.e.
       1 : the first subcase, or
       2 : the second subcase, or (rarely)
       "2c1." : the 1st copy of the 2nd subcase
  a2 : if not nil then this is the expression assumed TO VANISH
       in this subcase, form: prefix form or prefixed SQ-form
  a3 : if not nil then this is the expression assumed NOT TO VANISH
       in this subcase, form: prefix form or prefixed SQ-form
  a4 : work status, i.e.
       0  : not started yet
       1  : has been started
       >1 : completed, is the number of solutions + 2
  a5,... : sub-cases of this case, non if a4=0 or a=1 and no yet splitted

  global variables used:
  session_                   = "bu626868-"
  level_                     = (3 "c2" 1 1)
 ;

 scalar lv,ct,ctc,ctf,echo_bak,semic_bak,fl,fpid,newsplit,newfile,maxtries;

 if pairp inp and % i.e. this update is not about a subcase being finished
    car level_ = 1 then <<  % a new splitting into sub-cases is started
  newsplit:=t;
  lv:=reverse cdr level_;
 >>                else lv:=reverse level_;

 % ct is the case tree

 % the file name
 ctf:=explode session_;
 ctf:=bldmsg("%w",compress cons(car ctf,cons('c,cons('t,cdddr ctf))));

 if null lv and
    null filep ctf then <<newfile:=t;ct:={nil,nil,nil,1}>> % i.e. no subcases yet
                   else <<

  % move file
  fpid := bldmsg("%s.%w",ctf,getpid());
  fl:=1; maxtries:=0;
  repeat <<
   fl := rename!-file(ctf, fpid);
   maxtries:=add1 maxtries;
% Making 5 attempts with a half-second delay between them feels
% pretty dubious to me...
   if not fl then sleep 0.5
  >> until fl or (maxtries=5);
  if maxtries=10 then return <<
   write"### ERROR in CaseTree: file ",ctf," not found."$ terpri();
   write"--> No more tries. (keep_case_tree:=nil)"$terpri();
   nil
  >>;

  % read case tree ct from file
  echo_bak:=!*echo; semic_bak:=semic!*;
  semic!*:='!$; in fpid;
  !*echo:=echo_bak; semic!*:=semic_bak;
  ct:=backup_;

 >>;

 ctc:=ct;
 while lv do <<
  ctc:=cdddr ctc;
  while cdr ctc and caadr ctc neq car lv do ctc:=cdr ctc;
  if null cdr ctc then <<write"### ERROR in CaseTree: case not found in ct, lv=",lv;
                         terpri()>>
                  else <<
   ctc:=cadr ctc;
   lv:=cdr lv
  >>
 >>;

 ctc:=cdddr ctc;

 % now is lv=nil
 % adding a new case distinction:
 if pairp inp and % this case is started now, but ..
    cdr ctc       % subcases of this have already been allocated before
 then <<write"### ERROR in CaseTree: lv=nil, cdr ctc=",cdr ctc$ terpri()>>
 else
 if newsplit then
 if caar inp = 'EQUAL then
 if zerop cadar inp then rplacd(ctc,{{1,caddar inp,nil,1},{2,nil,caddar inp,0}})
                    else rplacd(ctc,{{1,cadar  inp,nil,1},{2,nil,cadar  inp,0}})
                      else
 if zerop cadar inp then rplacd(ctc,{{1,nil,caddar inp,1},{2,caddar inp,nil,0}})
                    else rplacd(ctc,{{1,nil,cadar  inp,1},{2,cadar  inp,nil,0}})
             else
 if pairp inp then rplaca(ctc,1) % this case is now started
              else <<
  if null inp then rplaca(ctc,2)      % this case is finished it
              else rplaca(ctc,2+inp)$ % has inp-many solutions
  % rplacd(ctc,nil) % @@@@@  This line deletes completed cases. It should be
                  %          commented out if a statistics about successful
                  %          assumptions shall be performed
 >>;
 %write"ct = "$terpri();
 %prettyprint ct$ terpri();

 consistenttree(ct,nil);

 if newfile then << % write the file
  out ctf;
  write"off echo$ ";
  write"backup_:= '";
  print ct;
  write" $"$         terpri();
  write"end$"$       terpri();
  shut ctf
 >>                            else <<
  % write renamed file
  out fpid;
  write"off echo$ ";
  write"backup_:= '";
  print ct;
  write" $"$         terpri();
  write "end$"$      terpri();
  shut fpid;

  % move back renamed file
  fl:=1;
  repeat <<
   fl := rename!-file(fpid, ctf);
% The code here would try an unlimited number of times (ie it could
% get stuck!) and it waits a second between attempts whereas earlier the
% delat was just half a second. The inconsistency seems unsatisfactory.
   if null fl then sleep 1
  >> until fl

 >>
end;

%===========

symbolic procedure find_unsolved_case;
% uses global variables session_ (input) and level_ (output)
begin scalar ctf,fpid,fl,ct,ctc,ctcc,soln,condi,echo_bak,semic_bak,
      maxtries;

 % the file name
 ctf:=explode session_;
 ctf:=bldmsg("%w",compress cons(car ctf,cons('c,cons('t,cdddr ctf))));

 % move file
 fpid := bldmsg("%s.%w",ctf,getpid());
 fl:=1; maxtries:=0;
 repeat <<
  fl := rename!-file(ctf, fpid);
  maxtries:=add1 maxtries;
  if null fl then sleep 1
 >> until fl or (maxtries=5);
 if maxtries=5 then return <<
  write"### ERROR in CaseTree: file ",ctf," not found";
  nil
 >>;

 % read case tree ct from file
 echo_bak:=!*echo; semic_bak:=semic!*;
 semic!*:='!$; in fpid;
 !*echo:=echo_bak; semic!*:=semic_bak;
 ct:=backup_;

 if cadddr ct>1 then goto fino; % The whole computation is completed.

 again1: % Search re-starts here if a case has been found, which has
         % all its sub-cases solved but the case itself has not been
         % marked yet as completely solved. Then this case is marked
         % as solved and search starts again here from the root of
         % the case tree.

 level_:=nil;
 ctc:=ct;

 again2: % to be jumped to when one goes deeper into an unsolved
         % subcase

 % it is known that cadddr ctc < 2, i.e. that this case is not yet completely
 % solved which is definitely true for the root
 if cddddr ctc then <<      % i.e. if subcases have been generated
                            % then find an unsolved subcase.
  ctcc:=cddddr ctc;         % ctcc is the list of subcases
  soln:=0;                  % the total # of solutions found in subcases
                            % to be used if all subcases are solved
  while ctcc and cadddr car ctcc > 1 do << % step through all solved cases
   soln:=soln+cadddr car ctcc - 2;
   ctcc:=cdr ctcc
  >>;
  if null ctcc then <<      % all subcases have been solved

   delete!-file!-exact level_string(session_);
   if ctc=ct then goto fino % the whole problem is solved
             else <<        % this case is solved
    rplaca(cdddr ctc,soln+2)$% mark this case as solved
    goto again1             % start seaarching again from root
   >>
  >>           else <<      % an unsolved subcase is found
   ctc:=car ctcc;
   level_:=cons(car ctc,level_);
   goto again2
  >>
 >>;

 condi:= if cadr ctc then {'EQUAL,cadr ctc,0}
                     else {'NEQ, caddr ctc,0};
 if cadddr ctc = 0 then rplaca(cdddr ctc,1)$ % as this computation
                                             % is about to start
 consistenttree(ct,nil);

 % write renamed file
 out fpid;
 write"off echo$ ";
 write"backup_:= '";
 print ct;
 write" $"$         terpri();
 write "end$"$      terpri();
 shut fpid;

 fino:

 % move back renamed file
 fl:=1;
 repeat <<
  fl := rename!-file(fpid, ctf);
  if not fl then sleep 1
 >> until fl;

 return condi

end;



%===========

symbolic operator crackpickup;
symbolic procedure crackpickup;
begin scalar s,level_bak,levstri;
 terpri();
 old_history:=nil;
 if null session_ then ask_for_session() else <<
  write "Do you want to compute remaining cases left over in this session,";
  terpri();
  if not yesp "i.e. since loading CRACK the last time? " then
  ask_for_session();
 >>;

 while s:=find_unsolved_case() do <<

  level_bak:=level_;
  level_:=cdr level_;
  write"Computation of the case ",reverse level_bak$ terpri();
  levstri:=level_string(session_);

  old_history:=
  if car s = 'NEQ then {'rb,levstri,
                        'as,'level_,{'quote,level_bak},
                        'n,cadr s}
                  else {'rb,levstri,
                        'as,'level_,{'quote,level_bak},
                        'r,'n,'new_pde,cadr s,2};

  algebraic(off batch_mode);
  algebraic(crack({},{},{},{}));

 >>

end;


endmodule;

end;
