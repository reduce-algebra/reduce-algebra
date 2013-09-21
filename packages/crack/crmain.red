%******************************************************************************
module crackstar$
%******************************************************************************
% Main program 
% Authors: Thomas Wolf since 1996
%          Andreas Brand 1995-97
%
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

% In earlier versions of crack the operation of copying a file was
% performed as (system bldmsg("cp %w %w", n1, n2)) which is concise,
% however I believe that the overhead in calling "system" can be extreme
% and the issues of Windows vs Unix/Linux/MacOSX comaptibility can be
% bad, so this might be safer and could even end up faster.

% This returns T on success or NIL on failure...

symbolic procedure copy!-file(n1, n2);
  begin
    scalar f1, f2, c, saveraise;
    saveraise := !*raise . !*lower;
    !*raise := !*lower := nil;
    if null (f1 := open(f1, 'input)) then return nil;
    if null (f2 := open(f2, 'output)) then <<
      close f1;
      return nil >>;
    f1 := rds f1;
    f2 := wrs f2;
    while (c := readch()) neq !$eof!$ do prin2 c;
    close rds f1;
    close wrs f2;
    !*raise := car saveraise;
    !*lower := cdr saveraise;
    return t;
  end;

symbolic operator crackshell$
symbolic procedure crackshell$
begin scalar s$ 
 if null proc_list_ then setcrackflags()$ % to make sure crack is
                               % initialized if CSL Reduce is run
 terpri()$
 if null old_history then <<
  stepcounter_:=-1$
  batchcount_:=-1$
  check_stop()$ 
  if batchcount_=-2 then return <<
   write"Before running crackshell() you need to delete the file"$terpri()$
   write"'stop_now' from the current directory."$terpri()$nil
  >>$

  change_prompt_to ""$ 
  write"Please give the name of the file in double quotes"$terpri()$
  write"(no ;) from which the session is to be restored: "$
  s:=termread()$  
  old_history:={'rb,s};
  restore_interactive_prompt() 
 >>$
 !*batch_mode:=nil;
 return algebraic(crack({},{},{},{})); 
end$

put('crack,'psopfn,'sq!*crack)$

symbolic procedure sq!*crack(inp)$
% For non-linear problems it is useful to have flin_ assigned
% before calling crack.
begin scalar el,il,fl,vl,l,l1,l2,a,b,n,m,k,p,pdes$

 if null proc_list_ then setcrackflags()$ % to make sure crack is
                               % initialized if CSL Reduce is run
 if l:=check_globals() then <<
   write"The global variable ",l," has an incorrect value, please check!"$
   rederr " "
 >>$

 if print_ and logoprint_ then <<terpri()$
  write "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"$ terpri()$
  write "This is CRACK - a solver for overdetermined partial ",
                  "differential equations"     $ terpri()$ 
 >>$
 if not !*batch_mode and null old_history then <<
   if not print_ then <<terpri()$print_:=8>>$
   write"Enter `h' for help."$ terpri()$
 >>$
 backup_reduce_flags();   % backup of REDUCE flags

 % initializations of global CRACK variables 
 contradiction_:=nil$
 to_do_list:=nil$
 fnew_:=nil$
 vl_:=nil$
 % stop_:=nil$
 % dec_hist_list:=nil$
 level_:=nil$
 stepcounter_:=0$
 batchcount_:=-1$
 recycle_eqns:=nil . nil$
 recycle_fcts:=nil$
 recycle_ids:=nil$
 largest_fully_shortened:=nil$
 currently_to_be_substituted_in:=nil$
 % size_watch assigned below

 n:=time()$
 m:=gctime()$

 el:=aeval    car inp$
 il:=aeval   cadr inp$
 fl:=reval  caddr inp$
 vl:=reval cadddr inp$
 el:=if pairp el and 
        (car el='LIST) then 
     for each p in cdr el collect 
     if pairp p and car p='!*SQ then cadr p 
                                else simp!* p
                       else if pairp el and 
                               car el='!*SQ then list cadr el
                                            else list simp!* el$ 
 % el is now a list of standard quotients
 fl:=if pairp fl and (car fl='LIST) then cdr fl else list fl$
 vl:=if pairp vl and (car vl='LIST) then cdr vl else list vl$
 il:=if pairp il and (car il='LIST) then cdr il else list il$
 vl_:=union(argset fl,vl)$  vl:=nil;
 % orderings_:=make_orderings(fl, vl_)$        % Orderings support!
 if vl_ then fl:=fctsort fl$
 fsub_:=nil$                   

 if null flin_ then ftem_:=fl
               else <<
  % Sort ftem_ functions such that in each group of functions with the same
  % number of variables, flin_ functions come first.
  ftem_:=nil;
  while fl do <<
   m:=fctlength car fl$
   l:=nil;
   while fl and (m=fctlength car fl) do <<
    if freeof(flin_,car fl) then l:=cons(car fl,l)
                            else ftem_:=cons(car fl,ftem_);
    fl:=cdr fl
   >>;
   ftem_:=append(l,ftem_)
  >>$
  ftem_:=reversip ftem_$

  % Now sort flin_
  flin_:=sort_according_to(flin_, ftem_);
 >>$

 % Start of the FORM computer algebra system for large computations
 if form_comp and form_pipe then system "./form_start < formin > formout &"$

 % We put all denominators into ineq_, 
 % checking for complex input (needed in shortening)
 ineq_:=nil; ineq_or:=nil;
 el:=for each p in el collect <<
      if null !*complex and
         ((not freeof(numr p,'i)) or (not freeof(numr p,'!:gi!:))) then
      algebraic(ON COMPLEX)$
      if not freeoflist(denr p,ftem_) then addSQineq(nil,(denr p ./ 1),t)$
      (numr p ./ 1)
     >>$
 for each p in il do 
 if pairp p and (car p = 'LIST) then <<
  p:=cdr p;   
  % p is now a lisp list of expressions of which at least one must not vanish
  l:=if null p then 1
               else nil;
  while p do % car p = {'!*sq, .., t}
  if sqzerop car p then p:=cdr p      
                   else 
  if freeoflist(car p,ftem_) then <<p:=nil; l:=1>> 
                             else <<l:=cons({cadr car p},l); p:=cdr p>>; 
      % {} because each element of ineq_or (i.e. l) is a list of factors 

  if l = 1 then                     % the or-inequality is already fulfilled
           else
  if null l then contradiction_:=t  % all expressions are zero
            else
  if cdr l then ineq_or:=cons(l,ineq_or)
           else addSQineq(nil,caar l,t)   
 >>                             else 
 addSQineq(nil,if pairp p and (car p='!*SQ) then cadr p
                                            else simp p,t); 
 simpSQineq_or_adhoc(nil)$  % the initial simplification of ineq_or
                            % nil because no pdes (yet) assigned
 il:=nil$
 history_:=nil;
 sol_list:=nil;

 % necessary initializations in case structural equations are to solve:
 if struc_eqn then ini_struc()$

 % Orderings Note: orderings_prop_list_all() inserts all the valid
 % orderings into each of the initial equations, i.e. all equations
 % are in all orderings

 % each equation gets a property list
 pdes:=mkeqSQlist(el,nil,nil,ftem_,vl_,
                  allflags_,t,%orderings_prop_list_all(),
                  list(0),nil)$
 if contradiction_ then return {'LIST}$

 if equations_file="" then <<
  l:=pdes;
  while l and get(car l,'linear_) do l:=cdr l;
  if l then lin_problem:=nil else lin_problem:=t;
  if lin_problem and null flin_ then flin_:=ftem_; 
 >>$

 % Is the system algebraic and polynomial?
 l:=pdes$
 alg_poly:=if vl_ then nil else t$
 while l and alg_poly do <<
  if get(car l,'nonrational) then alg_poly:=nil else <<
   el:=get(car l,'derivs);
   while el and (length(caar el)=1) do el:=cdr el;
   if el then alg_poly:=nil
  >>$
  l:=cdr l;
 >>$

 el:=nil$ % to free memory
 if size_watch then 
 size_hist:=list(cons('CP,for each l in proc_list_ collect get(l,'no)))$
 % size_hist:=nil$
 % size_hist:=if size_watch then {cons(0,get_statistic(pdes,ftem_))}
 %                          else nil$

 name_session()$

 % the computation:
 l:=crackmain(pdes,ftem_)$
 if pairp l and (fixp car l) then l:=nil$
 % i.e. if collect_sol=nil then either l=nil or l=(# of solutions)
 % if l=list(nil) then l:=nil$
 % l:=union(l,nil)$
 if !*time or time_ then
 <<terpri()$
   a:=time()-n$
   write "CRACK needed : ",a," ms "$
   printDHMStime(a)$ terpri()$
   a:=gctime()-m$
   write "GC time : ",a," ms "$
   printDHMStime(a)
 >>$ 

 % dropping redundant functions/constants now done at end of crackmain
 l:=cons('LIST,
    for each a in l collect % i.e. for each solution a
    <<l1:=nil$      % to be the list of computed assignments
      l2:=caddr a$  % to be the list of free or not yet determined unknowns
      for each b in cadr a do
      if (pairp b) and 
         (car b = 'EQUAL) then l1:=cons({'EQUAL,cadr b,
                                          aeval {'!*SQ,caddr b,nil}},l1)
                          else l2:=cons(b,l2)$
      {'LIST,
       cons('LIST,for each m in car a collect {'!*SQ,m,t}),
       cons('LIST,l1),
       cons('LIST,l2),
       cons('LIST,append(for each m in     cadddr a collect aeval {'!*sq,m,nil},
                         for each m in car cddddr a collect 
                           cons('LIST,for each n in m collect <<
                                        p:=simp 1;
                                        for each k in n do p:=multsq(k,p);
                                        aeval {'!*sq,p,nil}
                                      >>)))}>>)$

 if null collect_sol then add_to_sol_list()$

 % delete file with empty sol_list
 if null collect_sol then delete_empty_sol_list_file()$

 % statements to free space and to make later crack-calls more natural
 nequ_:=1$
 recycle_eqns:=nil . nil$
 recycle_fcts:=nil$
 recycle_ids:=nil$
 old_history:=nil$
 flin_:=nil$

 % close the equation input file
 if eqn_input='done then eqn_input:=nil else
 if eqn_input then <<close eqn_input; eqn_input:=nil>>;

 recover_reduce_flags()$   % giving the REDUCE flags their backup value

 % Stop of the FORM computer algebra system which was
 % started at the start of this procedure. Either send:
 %   skip;
 %   .end
 % or delete the file `formin' .
 if form_comp and form_pipe then << >>;

 if print_ and logoprint_ then <<
  terpri()$
  write "This is the end of the CRACK run"$
  terpri()$
  write  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
         "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"$
  terpri()$
 >>$
 return l 

end$

!#if (memq 'csl lispsystem!*)    
symbolic fluid '(!*used!-space!* !*avail!-space!*)$ 
!#endif

symbolic procedure crackmain(pdes,forg)$
% Main program
% > not to be called from algebraic mode
% > it returns
%   - nil   if no solution exists or no solution was collected,
%   - {nil} if successful but no solutions are collected (collect_sol=nil),
%   - {sol1,sol2,...}  list of solutions
%     each solution has the form
%            if not collect_sol then list(1) else    % 1 = # of solutions
%            list list(for each a in pdes collect get(a,'sqval),
%                      forg,
%                      setdiff(ftem_,forg),
%                      append(ineq_,
%                             if null ineq_or then nil 
%                                             else for each a in ineq_or 
%                                                  collect cons('LIST,a)))
%   The reason for this format is such that the result can be passed on as the
%   result of crack() to algebraic mode. The left hand side of equations
%   {'EQUAL,..,..} in forg is converted to {!*sq,..,t} automatically when
%   the result is passed on to algebraic mode.
% > The result that is returned is contained completely in the
%   returned value (list) only apart from the variable dependencies
%   of the free functions which is contained in depl!*.
% > apply-calls made within must return either 
%   nil or {pdes,forg} or {{sol1,sol2,...}} 
% > In the case of more than one solution of an apply call, all of them
%   must be computed because crackmain terminates after such an apply
%   call that returns a list with a single element which then always is
%   treated as a list of solutions.
% > Currently ftem_, ineq_, ineq_or, vl_, flin_, fsub_, session_ are
%   essential  (but hidden) input parameters (as well as the properties
%   of the pdes and forg) and all the global variables *_* assigned in sq!*crack
% > crackmain() sets the global variable contradiction_.
% > At the end of crackmain at least the first element of the list level_
%   is taken off but it is added before calling crackmain. Thus, if for some
%   reason, crackmain is not called after level_ has already been extended,
%   level_ needs to be reduced with finish_level(0) instead of calling crackmain
begin scalar result,l,carpl,unsolvable, % dec_hist_list_copy,
             s,h,pl,ps,batch_one_step,expert_mode_copy,fnc_to_adjust,stop_,
             fnc_adjusted,loopcount,level_length,newli,full_proc_list_length,
!#if (memq 'psl lispsystem!*)
             processes,
!#endif
             si_hi,plcnt,no_of_children,pt2ineq$

  no_of_children:=0;
  level_length:=length level_;
  full_proc_list_length:=length full_proc_list_$
  choose_70_65_8_47_origterms:=nil$
  if tr_main and print_ then
    <<terpri()$write "start of the main procedure">>$
  % depl_copy_:=depl!*$
  % dec_hist_list_copy:=dec_hist_list$
  fnc_to_adjust:=adjust_fnc;
  if contradiction_ then rederr"** CONTRADICTION_ AT START OF CRACKMAIN()! **"$
  contradiction_:=nil$
  f_update(pdes,forg)$     % global list of free functions
  % Because the list pdes of all equations is not a global variable, when
  % a new multi-term inequality is found and dropped as a factor from equations
  % then equations can not be re-sorted by size where the factors are dropped.
  % So to know when equations have to be re-sorted by size, a pointer pt2ineq
  % indicates whether ineq_ has changed and therefore equations should be
  % re-sorted by size.
  pt2ineq:=ineq_;
again:
  repeat <<
    stop_:=nil$
    check_stop()$ 
%    if to_do_list then batchcount_:=add1 batchcount_$  % moved here from below
    f_update(pdes,forg)$   % ############# should only be done if necessary, expensive?
    vl_:=var_list(pdes,forg,vl_)$
    if not (pt2ineq equal ineq_) then <<
     % write"equations are re-sorted by size";terpri()$
     % pdes:=sort_eq_by_length pdes;
     pt2ineq:=ineq_
    >>;
    pdes:=update_eq_sort_by_length(pdes)$ % supposed to be fast
    if time_limit then <<
      l:=time(); 
      if (time_limit=2) and % i.e. terminate with error
         (limit_time<l) then rederr "PREMATURE STOP DUE TO TIME CONSTRAINT!"
    >>$

    if !*batch_mode or 
       to_do_list or 
       batch_one_step or 
       (( batchcount_>=stepcounter_         ) and
        ((time_limit=nil) or (limit_time>=l))     ) then

    % automatic part: -----------------------
    <<if !*batch_mode then
      if print_more then
         print_pde_forg_ineq(pdes,(ineq_ . ineq_or),
                             append(forg,setdiff(ftem_,forg)),vl_)$
      if size_watch then 
      si_hi:=get_statistic(pdes,append(forg,setdiff(ftem_,forg)))$
      stepcounter_:=add1 stepcounter_$
      clean_prop_list(pdes)$
      %if evenp(stepcounter_) and 
      %   evenp(stepcounter_/2) then 
      if print_ then 
       <<terpri()$write "Step ",stepcounter_,": "$
         if print_more then terpri()>>$
      batch_one_step:=nil$
      expert_mode_copy:=expert_mode$
      if (null to_do_list) or 
         (caar to_do_list neq 'split_into_cases) then expert_mode:=nil$
      plcnt:=1;
      while plcnt<=length(proc_list_) do <<
        carpl:=nth(proc_list_,plcnt)$
        if print_ and print_more then
        if pairp(l:=get(carpl,'description)) then <<
          for each a in l do if a then write a$
          write " : "
        >>                                    else 
        write "trying ",carpl," : "$
        l:=apply(carpl,list list(pdes,forg,vl_,pdes))$  % ###### vl_ for historical reasons, 
                                                        %        to be cleaned up some time 
        if size_watch and (contradiction_ or (l and (length l > 1))) then
        size_hist:=cons(cons(get(carpl,'no),si_hi),size_hist);
        if (fixp size_watch) and  
           ((stepcounter_-size_watch*(stepcounter_/size_watch))=0) then 
        cut_size_hist();
        if null choose_70_65_8_47_origterms and size_hist then <<
         s:=size_hist;
         while s and not fixp caar s do s:=cdr s;
         choose_70_65_8_47_origterms:=if s then caddr cdddar s
                                           else 1000
        >>$

        if (length l = 1) and (null car l) then contradiction_:=t;
        if l and not contradiction_ then <<
          if length l = 1      % before the test was: if cases_ 
          then result:= car l  % car l is a list of crackmain results
                               % resulting from investigating subcases 
          else <<pdes:=car l$ forg:=cadr l>>$  % no case-splitting
          plcnt:=100000
        >>                          else 
        if contradiction_ then plcnt:=100000
                          else 
        % not yet used but a possible extension (unless the task in to_do_list is
        % unsuccessful and then an endless loop could occur):
        %% the case that no computation was performed 
        %% but to_do_list was assigned:
        %if to_do_list then <<
        %  plcnt:=1$
        %  if print_ and print_more then 
        %  <<write " --- An urgent task was generated."$terpri()>>
        %>>            else 
        <<
          plcnt:=add1 plcnt$
          if print_ and print_more then 
          <<write " --- "$terpri()>>$
          if (plcnt>length(proc_list_)) and
             (null eqn_to_be_gen) then unsolvable:=t
        >> 
      >>;
      expert_mode:=expert_mode_copy$
    >>
    else % interactive part: -----------------------
    <<if print_ and time_limit and (limit_time<l) then <<
        write"The time limit for automatic execution has been reached."$
        terpri()
      >>$
      rds nil$wrs nil$
      change_prompt_to "next: "; 
      if print_ or null old_history then terpri()$
      s:=termread()$
      % expert_mode:=expert_mode_copy$
      if (s='h) or (s='help) or (s='?) or (s=nil) then printmainmenu()
      else if s='hd then print_hd()
      else if s='hp then print_hp()
      else if s='hf then print_hf()
      else if s='hc then print_hc()
      else if (s='hi) and (getd 'show_id) then print_hi()
      else if s='hb then print_hb()      
      else if (s='hl) and (memq('unix,lispsystem!*) or
                           memq('linux!-gnu,lispsystem!*)) then print_hl()
      else if s='he then print_he()
      % to inspect data -----------------------
      else if s='e then 
        if expert_mode then print_pdes(selectpdes(pdes,1))
                       else print_pdes(pdes)
      else if s='eo then <<
        ps:=print_;print_:=1;
        symbol_explanation()$
        for each s in pdes do <<terpri()$
          write s," : "$ 
          typeeq(s)$
          plot_non0_separants(s)$
          list_possible_subs(s)
        >>$
        print_:=ps
      >>
      else if s='pi then print_ineq((ineq_ . ineq_or))
      else if s='f then 
        <<print_forg(append(setdiff(forg,ftem_),ftem_),vl_)$
           terpri()>>
      else if s='v then 
        <<print_fcts(pdes,append(forg,setdiff(ftem_,forg)))$
        terpri()>>
      else if s='s then <<
        print_level(1)$
        print_statistic(pdes,append(forg,setdiff(ftem_,forg)))
      >>
      else if s='fc then <<
        reclaim()$terpri()$            % do garbage collection
!#if (memq 'psl lispsystem!*)          % PSL:
        write if boundp 'gcfree!* then gcfree!* 
                                  else known!-free!-space(),
              " free cells"$
!#else                                 % CSL:
        write"Used memory: ",!*used!-space!*,"KB"$terpri()$
        write"Free memory (without requesting more): ",!*avail!-space!*,"KB"$
!#endif
        terpri()$write countids()," identifiers in use"$;
        terpri()
      >>
      else if s='pe then <<
        change_prompt_to ""$ 
        terpri()$
        write "Which expression do you want to print?"$
        terpri()$
        write "You can use names of equations, e.g. coeffn(e_12,df(f,x,y),2); "$
        terpri()$
        write "Terminate the expression with ; "$
        terpri()$
        l:=termxread()$
        for each s in pdes do 
        if not freeof(l,s) then l:=subst({'!*sq,get(s,'sqval),t},s,l)$
        for each s in forg do 
        if (pairp s) and (car s='EQUAL) then l:=subst({'!*sq,caddr s,t},cadr s,l)$
	terpri()$
        mathprint(reval l)
      >>
      else if s='ph then <<
        terpri()$
        l:=reverse history_;
        while l do 
        if cdr l and (cadr l = 'ig) then <<
         terpri()$ 
         prin1 car l$ prin2 " "$ prin1 cadr l$ prin2 " "$ prin1 caddr l$terpri()$  
         l:=cdddr l
        >>                          else <<
         prin1 car l$ prin2 " "$ l:=cdr l
        >>
      >>
      else if s='pv then <<
        write "Type in a variable from which you want to know its value: ";
        change_prompt_to ""$ 
        s:=termread()$
        if not atom s then write"This is not a variable name." else
        if null boundp s then write s," has no value" 
                         else <<write s," = "$prettyprint eval s>>
      >>
      else if s='pf then how_often(pdes)
      else if s='po then print_factors(pdes)
      else if s='pr then <<
        write"The currently active substitution rules: "$ terpri()$
        algebraic (write lisp userrules_); terpri()
      >>
      else if s='pd then plot_dependencies(pdes)
      else if s='ps then plot_statistics(size_hist) 
      else if s='lc then list_cases(size_hist) 
      else if s='ws then write_stat_in_file()
      else if s='sn then <<write"The name of this session is: """,session_,""""$
                           terpri()>>
      else if s='ss then err_catch_subsys(pdes)
      else if s='w then write_in_file(pdes,forg)
      % to proceed -----------------------
      else if s='a then batch_one_step:=t
      else if s='g then <<
        change_prompt_to "number of steps: "$ 
        s:=termread()$
  %      restore_interactive_prompt()$ 
  %      change_prompt_to "next: "$ 
        if fixp(s) then batchcount_:=sub1 stepcounter_+s
        else <<write "wrong input!!!"$terpri()>> >> 
      else if s='t then <<
        expert_mode:=not expert_mode$
        if expert_mode then 
        write"The user will choose equations from now on."
                       else
        write"The program will choose equations from now on.";
        expert_mode_copy:=expert_mode
      >>
      else if s='p1 then printproclist()
      else if s='p2 then printfullproclist()
      else if s='# then <<
         write"Type in a number instead of `#' to ",
              "execute a specific module."$
        terpri()
      >>
      else if (s='l) or numberp s then
      <<last_steps:=nil$ % so that in_cycle does not prevent
                         % repeating interactive commands
        if s='l then <<
          repeat_mode:=t;
          if print_ or null old_history then <<
           change_prompt_to ""$ 
           write "Select a method by its number that is to be executed ",
                 "repeatedly:"$terpri()$
          >>$
          s:=termread()$
          if print_ or null old_history then <<
           terpri()$
           write "To repeat this method as often as possible, enter `;' "$
           terpri()$   
           write "To repeat this method as often as possible, ",
                 "but at most a number of n times, enter n :"$
           terpri()$   
          >>$
          repeat_mode:=termread()$
          if not numberp repeat_mode then repeat_mode:=t
        >>;
        if (s<=0) or (s>full_proc_list_length) then 
        if print_ then <<
          if size_watch and not fixp size_watch then % otherwise avoid growth
          history_:=cons("*** The number is not in the allowed interval.",
                         cons('ig,history_))$
          write"The number must be in 1 .. ",full_proc_list_length," ."$
          terpri()
        >>        else                         else
        <<
          loopcount:=0; 
          if size_watch then 
          si_hi:=get_statistic(pdes,append(forg,setdiff(ftem_,forg)))$
          stepcounter_:=add1 stepcounter_$
          clean_prop_list(pdes)$
          if print_ then 
          <<terpri()$write "Step ",stepcounter_,": ">>$
          repeat <<
            if to_do_list then loopcount:=sub1 loopcount$
            ps:=if to_do_list then 'to_do
                              else nth(full_proc_list_,s);
            l:=apply(ps,list list(pdes,forg,vl_,pdes))$

            if (repeat_mode neq t) and null l and null contradiction_ and 
               size_watch and not fixp size_watch then % otherwise avoid growth
            history_:=cons(bldmsg("*** %w un-succ.",ps),cons('ig,history_))$

            if size_watch and (l or contradiction_) then 
            size_hist:=cons(cons(s,si_hi),size_hist);

            if (fixp size_watch) and (loopcount neq 0) and 
               ((loopcount-size_watch*(loopcount/size_watch))=0) then 
            cut_size_hist();
            if null choose_70_65_8_47_origterms and size_hist then <<
             ps:=size_hist;
             while ps and not fixp caar ps do ps:=cdr ps;
             choose_70_65_8_47_origterms:=if ps then caddr cdddar ps
                                                else 1000
            >>$
            if (length l = 1) and (null car l) then contradiction_:=t;
            if l and not contradiction_ then <<
              loopcount:=add1 loopcount$
              if length l = 1     % before the test was: if cases_ 
              then result:=car l  % car l is a list of crackmain results
                                  % resulting from investigating subcases 
              else <<pdes:=car l$ forg:=cadr l>>$  % no case-splitting
              if print_ then terpri()$

              check_stop()$ 
              if to_do_list and numberp repeat_mode then 
              repeat_mode:=add1 repeat_mode;

              if repeat_mode=1 then repeat_mode:=nil
                               else if repeat_mode then <<
                if numberp repeat_mode then repeat_mode:=sub1(repeat_mode);
                if size_watch then 
                si_hi:=get_statistic(pdes,append(forg,setdiff(ftem_,forg)))$
                stepcounter_:=add1 stepcounter_$
                clean_prop_list(pdes)$
                if print_ then 
                <<terpri()$$write "Step ",stepcounter_,": ">>$
              >>
            >>
            else if (not contradiction_) and (loopcount=0) and 
                 (print_ or null old_history) then 
              <<write "no success"$terpri()>>
          >>
          until (not repeat_mode) or result or (not l) or contradiction_ or
                  (time_limit and <<ps:=time();limit_time < ps >>);
        >>;
        repeat_mode:=nil
      >>
      else if s='sb then backup_to_file(pdes,forg,t)
      else if s='rb then <<
        l:=restore_backup_from_file(pdes,forg,t)$
        pdes:=car l;forg:=cadr l;
        level_length:=1 + length level_; % not to delete backup files at end
        if null auto_para_mode then  % assumed not to be started from PVM
        batchcount_:=sub1 stepcounter_
      >>
      else if s='an then pdes:=flin_non_triv_cond pdes
      else if s='rs then pdes:=comp_resultant(pdes)
      else if (s='x) or (s=int2id 4) % i.e. if interactive session is submitted
                          % as a job and no more interactive input, ie s=ctrl d
      then !*batch_mode:=t
      else if s='q then <<
       if eqn_to_be_gen and eqn_input and (eqn_input neq 'done) then <<
        close eqn_input; eqn_input:='done
       >>$
       stop_:=t
      >>
      % to change flags & parameters -----------------------
      else if s='pl then <<
        change_prompt_to "Print length : "$ 
        s:=termread()$
        if not s or fixp(s) then print_:=s
                            else <<
          terpri()$write "Print length must be NIL or an integer!!!"$ 
          terpri()
        >>
      >>
      else if s='pm then <<
        print_more:=not print_more;
        if print_more then write"More details will be printed."
                      else write"Fewer details will be printed.";
        terpri()
      >>
      else if s='pa then <<
        print_all:=not print_all;
        if print_all then write"All equation properties will be printed."
                     else write"No equation properties will be printed.";
        terpri()
      >>
      else if s='cp then changeproclist()
      else if s='og then <<
        lex_fc:=not lex_fc$
        if lex_fc then 
        write"Lex. ordering of functions has now highest priority."
                  else
        write"Lex. ordering of functions is not of highest priority anymore."$
        terpri()$
        pdes := change_derivs_ordering(pdes,ftem_,vl_)$
      >>
      else if s='od then <<
        lex_df:=not lex_df$
        if lex_df then 
        write"From now on lexicographic ordering of derivatives."
                  else
        write"From now on total-degree ordering of derivatives.";
        terpri()$
        pdes := change_derivs_ordering(pdes,ftem_,vl_);
      >>
      else if s='oi then <<
        terpri()$
        write "Current variable ordering is : "$
        s:=vl_;
        while s do <<write car s$ s:=cdr s$ if s then write",">>$
        write";"$terpri()$
        change_prompt_to "New variable ordering : "$ 
        newli := termlistread()$
        if newli then <<
          if not_included(vl_,newli) then <<
           write"Not all variables appear in the new list."$
           terpri()
          >>                         else
          if not_included(newli,vl_) then <<
           write"The new list has extra ariables."$
           terpri()
          >>                         else <<
            vl_ := newli$
            for each s in pdes do 
            put(s,'vars,sort_according_to(get(s,'vars),vl_));
            pdes := change_derivs_ordering(pdes,ftem_,vl_)$
            if tr_orderings then <<
              terpri()$
              write "New variable list: ", vl_$
            >>
          >>$
        >>$
      >>
      else if s='or then <<
        terpri()$
        write "The current variable ordering is going to be reversed. "$
        vl_ := reverse vl_$
        for each s in pdes do 
        put(s,'vars,sort_according_to(get(s,'vars),vl_));
        pdes := change_derivs_ordering(pdes,ftem_,vl_)$
        if tr_orderings then <<
          terpri()$
          write "New variable list: ", vl_$
        >>
      >>
      else if s='om then <<
        terpri()$
        write "The current variable ordering is going to be mixed. "$
        s:=vl_; vl_:=nil;
        while s do <<
          l:=nth(s,add1 random length s)$
          s:=delete(l,s);
          vl_:=cons(l,vl_);
        >>;
        for each s in pdes do 
        put(s,'vars,sort_according_to(get(s,'vars),vl_));
        pdes := change_derivs_ordering(pdes,ftem_,vl_)$
        if tr_orderings then <<
          terpri()$
          write "New variable list: ", vl_$
        >>
      >>
      else if s='of then <<
        terpri()$
        write "Current function ordering is : "$
        s:=ftem_;
        while s do <<write car s$ s:=cdr s$ if s then write",">>$
        write";"$terpri()$
        if null vl_ then <<
         write "If you want to sort functions according to frequency, rare"$
         terpri()$
         write "functions first, then type:    sort_by_frequency;"$terpri()$
         write "If you want to sort functions randomly, flin_ first and"$
         terpri()$
         write "non-vanishing last, then type:    sort_randomly;"$terpri()$
         write "else type the new list."$terpri()
        >>$
        change_prompt_to "New function ordering : "$ 
        newli := termlistread()$

        if null vl_ and newli and (car newli='sort_by_frequency) then <<
         how_often(pdes);
         newli:=ftem_sorted_by_index()
        >>                                else 
        if null vl_ and newli and (car newli='sort_randomly) then <<
         s:=ftem_;
         backup_:=nil;
         h:=length ftem_;
         while h>1 do << 
          l:=nth(s,1+random h)$
          backup_:=cons((h . l),backup_);
          s:=delete(l,s);
          h:=h - 1
         >>$
         backup_:=cons((1 . car s),backup_);
         newli:=ftem_sorted_by_index()
        >>                                else       
        if newli and (not_included(ftem_,newli) or  
                      not_included(newli,ftem_)    ) then newli:=nil;
        if newli then change_fcts_ordering(newli,pdes,vl_)
      >>
      else if s='op then <<
        terpri()$
        write "Current orderings are :"$
        terpri()$
        write "Functions : ", ftem_$
        terpri()$
        write "Variables : ", vl_$
      >>
      else if s='ne then <<
        change_prompt_to "Equation name : "$ 
        s:=termread()$
        if s and idp s then eqname_:=s
                       else 
        <<terpri()$write "Equation name must be an identifier!!"$terpri()>>
      >>
      else if s='nf then <<
        change_prompt_to "Function name : "$ 
        s:=termread()$
        if s and idp s then fname_:=s
                       else 
        <<terpri()$write "Function name must be an identifier!!"$terpri()>>
      >>
      else if s='ni then <<
        change_prompt_to "Identity name : "$ 
        s:=termread()$
        if s and idp s then idname_:=s
                       else 
        <<terpri()$write "Identity name must be an identifier!!"$terpri()>>
      >>
      else if s='na then <<!*nat:=not !*nat;
        if !*nat then write"NAT is now on." 
                 else write"NAT is now off.">>
      else if s='as then <<
        change_prompt_to "The variable name to be assigned: "$ 
        s:=termread()$
        write "What is the value to be assigned to that variable?"$terpri()$
        change_prompt_to "Please terminate this input with ';'  : "$ 
        l:=termxread()$
        if s='collect_sol and l=nil and collect_sol then save_sol_list() else
        if s='session_ then
           copy!-file(bldmsg("%wsol_list", session_),
                      bldmsg("%wsol_list", l));
        % i.e. create a sol_list file
        set(s,reval l)$
      >> 
      else if s='ke then 
      if keep_parti then <<
        keep_parti:=nil;
        for each l in pdes do put(l,'partitioned,nil)
      >>            else keep_parti:=t
      else if s='fi then <<
        freeint_:=not freeint_;
        if freeint_ then write"Integration only if result free ",
                              "of explicit integral from now on."
                    else write"Integration result may involve ",
                              "explicit integral from now on.";
      >>
      else if s='fa then <<
        freeabs_:=not freeabs_;
        if freeabs_ then 
        write"Integration only if result free of abs() from now on."
                    else 
        write"Integration result may involve abs() from now on.";
      >>
      else if s='cs then <<
        confirm_subst:=not confirm_subst;
        if confirm_subst then 
        write"The user will confirm substitutions from now on."
                         else 
        write"No user confirmation of substitutions from now on.";
      >> 
      else if s='fs then <<
        force_sep:=not force_sep;
        if force_sep then write"Separation will be inforced from now on."
                     else write"Separation will not be inforced from now on.";
      >>
      else if s='ll then <<
        write "What is the new line length? ";
        change_prompt_to "What is the new line length? "$ 
        repeat l:=termread() until fixp l;
        linelength l
      >>
      else if s='re then <<
        do_recycle_eqn:=not do_recycle_eqn$
        if do_recycle_eqn then 
        write"Equation names will be re-used once the equation is dropped."
                          else
        write"Equation names will not be re-used once the equation is dropped."
      >>
      else if s='rf then <<
        do_recycle_fnc:=not do_recycle_fnc$
        if do_recycle_fnc then 
        write"Function names will be re-used once the function",
             " is substituted."
                          else
        write"Function names will not be re-used once the function",
             " is substituted."
      >>
      else if s='st then <<
        batchcount_:=sub1 stepcounter_$
        if time_limit then <<
          l:=limit_time - time()$
          if l<0 then write"The time-limit has expired."
                 else <<
            l:=algebraic(round(l/60000))$
            write"The current CPU time limit for automatic ",
                 "execution to stop is: "$
            s:=algebraic(floor(l/60));
            if s>0 then <<terpri()$write s," hours and ">>$
            write algebraic(l-60*s)," minutes. "$
                 >>
        >>            else write"There is no time-limit set currently."$
        terpri()$
        change_prompt_to ""$ 
        if yesp "Do you want to impose a CPU time-limit? " then <<
          repeat <<
            write"After time has expired,"$terpri()$
            write"   shall CRACK go into interactive mode (1)"$terpri()$
            write"   or shall CRACK terminate with error  (2) ? "$terpri()$
            time_limit:=termread() 
          >> until (time_limit=1) or (time_limit=2)$
%          time_limit:=t$
          write"How many hours? "$    s:=termread()$
          write"How many minutes? "$  l:=termread()$
          if not numberp s then s:=0$
          if not numberp l then l:=0$
          limit_time:=reval algebraic (round (s*3600000+l*60000+lisp time()))$
        >>   else time_limit:=nil$
      >>
      else if s='cm then <<
        % do nothing, the input is added as a comment to history_
        change_prompt_to ""$ 
        write"Please type your comment in "" "" for the history_ list: "$
        terpri()$
        l:=termread()$
        terpri()$
      >>
      else if s='ig then % ignore (starts automatic comments written into history_)
      else if s='lr then <<
        change_prompt_to ""$ 
        write"In the LET-rule you are going to add you can not introduce "$
        terpri()$
        write"new functions to be computed. If your LET-rules involve "$
        terpri()$
        write"such functions then you have to add equations before which "$
        terpri()$
        write"involve these functions in order to introduce the functions "$
        terpri()$
        write"to the program. "$terpri()$ terpri()$
        write"You can either"$ terpri()$
        write"- give the name (terminated by ;) of a rule list to be "$terpri()$
        write"  activated that has been defined before the call of CRACK, or"$
        terpri()$
        write"- give the name (terminated by ;) of an equation which "$terpri()$
        write"  is to be converted to a LET rule, or"$terpri()$
        write"- type in the new LET-rule in the form like"$terpri()$
        write"  sqrt(e)**(-~x*log(~y)/~z) => y**(-x/z/2);   : "$terpri()$
        l:=termxread()$
        if atom l then 
        if member(l,pdes) then rule_from_pde(l)
                          else algebraic(let lisp l) 
                  else <<
         userrules_:=cons('LIST,cons(l,cdr userrules_))$
         algebraic (write "The new list of user defined rules: ",
                          lisp userrules_)$
         terpri()$
        >>$
        write"Shall all current LET-rules be applied to all current ",
             "equations (y/n)? "$
        l:=termread()$
        if (l='y) or (l='Y) then <<
         algebraic(let lisp userrules_);
         s:=pdes;
         for each h in s do <<
          l:=mkeqSQ(get(h,'sqval),nil,nil,get(h,'fcts),get(h,'vars),
                    allflags_,t,list(0),nil,pdes)$
          pdes:=drop_pde(h,pdes,nil)$
          pdes:=eqinsert(l,pdes)
         >>$
         algebraic(clearrules lisp userrules_)
        >>$
        write"Warning: Changes of equations based on LET-rules"$terpri()$
        write"are not recorded in the history of equations."$terpri()$
      >>
      else if s='cr then <<
        change_prompt_to ""$ 
        write"These are all the user defined rules: "$      terpri()$
        algebraic (write lisp userrules_);
        write"You can either"$ terpri()$
        write"- give the number of a rule above to be dropped, or "$ terpri()$
        write"- give the name of a rule list activated before "$ terpri()$
        write"  the call of CRACK which should be disabled: "$
        l:=termread()$
        if not fixp l then <<
         algebraic(clearrules lisp l)$
         write"Rule list ",l," has been disabled."$terpri()
        >>            else
        if l > sub1 length userrules_ then <<
         write"This number is too big."$terpri()
        >>                            else <<
         s:=nil;userrules_:=cdr userrules_;
         while l>1 do <<
          l:=sub1 l;s:=cons(car userrules_,s);userrules_:=cdr userrules_
         >>;
         algebraic(clearrules lisp {'LIST,car userrules_});
         userrules_:=cons('LIST,append(reverse s,cdr userrules_));
         algebraic (write lisp userrules_);
         terpri()$
        >>
      >>
      else if s='ap then 
      if alg_poly then
      <<        change_prompt_to ""$ 
	% set_bndstk_size 50000$
	% off allfac$
	% lisp (simplimit!* := 5000);

        if fhom_ then <<
         write"Is the system homogeneous in the following functions/unknowns? (y/n) "$
         listprint(fhom_)$terpri()$
         l:=termread()$
         if l='n then fhom_:=nil
        >>$
        if null fhom_ then <<
         write"Is the system homogeneous in some functions/unknowns? (y/n) "$
         l:=termread()$
         if l='y then <<
          write"Give a list of functions/unknowns (terminated by ; )"$terpri()$
          write"such that all equations in which anyone of these"$terpri()$
          write"functions occurs is homomogeneous wrt. all of them."$terpri()$
          write"The following is a list of all current unknowns."$terpri()$
          listprint(ftem_)$terpri()$
          write"To select all, enter only  ;  : "$
          fhom_:=termlistread()$
          if null fhom_ then fhom_:=ftem_;
          for each s in pdes do <<
           put(s,'fct_hom,smemberl(get(s,'fcts),fhom_));
           put(s,'hom_deg,find_hom_deg_SF(numr get(s,'sqval)))
          >>
         >>      else fhom_:=nil
        >>$

        write"Should solutions be stored as files? (y/n) "$
        l:=termread()$
        if l='y then <<
         if collect_sol then save_sol_list()$ % to create a sol_list file
         collect_sol:=nil 
        >>      else collect_sol:=t$

        write"Should FORM be used for long computations? (y/n) "$
        l:=termread()$
        if l='y then form_comp:=t else form_comp:=nil$

        groeb_solve:=<<
         write"Should Singular be used for computing Groebner bases? (y/n) "$
         l:=termread()$
         if l='y then <<
          write"Use reverse total degree ordering? (y/n) "$ 
          l:=termread()$
          if l='y then 'SL_REVGRAD 
                  else <<
           write"Pure lexicographical ordering is used."$terpri()$
           'SL_LEX
          >>                                                         
         >>      else <<
          write"Should the GB package of J.C.Faugere be used? (y/n) "$
          l:=termread()$
          if l='y then <<
           write"Use reverse total degree ordering? (y/n) "$
           l:=termread()$
           if l='y then 'GB_REVGRAD 
                   else <<
            write"Pure lexicographical ordering is used."$terpri()$
            'GB_LEX 
           >>
          >>      else <<
           write"The REDUCE Groebner package is used."$terpri()$
           'REDUCE
          >>
         >>
        >>$

        if null size_watch then <<
         write"Will the computation involve 1000's of steps, so that the recording"$
         terpri()$
         write"    of the history of the computation should be limited (y/n)? "$
         l:=termread()$
         if l='n then size_watch:=t else <<
          repeat <<
           write"About how many last steps shall statistical data be stored? (at least 50) "$
           size_watch:=termread()$
          >> until fixp size_watch
         >>
        >>$

        print_more:=nil;
        record_hist:=nil;  % =t for integrating syzygies, would give too long
                           % expressions in prefix form --> too slow
        %max_gc_short:=25;   % 5   % 25;
        max_gc_elimin:=5$
        max_gc_red_len:=1; % 4
        if null size_watch then 
        size_hist:=list(cons('CP,for each l in proc_list_ collect get(l,'no)))$
        max_gc_fac:=4;    
        choose_6_20_max_ftem:=25;   
        choose_6_20_max_terms:=5000;
        choose_27_8_16_max:=15; 
        choose_30_47_21_max:=10;    
        % max_eqn_to_conti:=1;  % used in stop_batch() to stop only if more
        %                       % than max_eqn_to_conti equations are unsolved
        proc_list_:='(to_do
                      separation
                      subst_level_0
                      alg_length_reduction 
                      choose_6_20    
                      subst_level_45
                      choose_27_8_16
                      diff_length_reduction
                      factorize_to_substitute
                      subst_level_3
                      choose_30_47_21
                      decoupling 
                      factorize_any
                      subst_level_4
                       % alg_solve_single
                       stop_batch 
                     )$
       write"proc_list_ has been changed, see p1."$terpri()$
      >> else
      else if s='ho then find_homo_weights(pdes)
      % to change data of equations -----------------------
      else if s='r then <<pdes:=replacepde(pdes,ftem_,vl_);
                          ftem_:=cadr pdes; pdes:=car pdes>>
      else if s='rd then <<pdes:=reducepde(pdes,ftem_,vl_);
                           ftem_:=cadr pdes; pdes:=car pdes>>
      else if s='n then newinequ(pdes)
      else if s='de then pdes:=deletepde(pdes)
      else if s='di then delete_ineq(pdes)
      else if s='c then change_pde_flag(pdes)
      else if s='pt then <<l:=General_Trafo({pdes,forg})$
                           if l then <<pdes:=car l$ forg:=cadr l>> >>
      % else if s='se then pdes:=sort_eq_by_length pdes
      % (not needed anymore, done by default more efficiently)
      % to work with identities -----------------------
      else if s='i  and getd 'show_id then show_id()
      else if s='id and getd 'show_id then 
           if l:=del_red_id(pdes) then pdes:=l else
      else if s='iw and getd 'show_id then write_id_to_file(pdes)
      else if s='ir and getd 'show_id then remove_idl()
      else if s='ia and getd 'show_id then replace_idty()
      else if s='ih and getd 'show_id then start_history(pdes)
      else if s='is and getd 'show_id then stop_history(pdes)
      else if s='ii and getd 'show_id then 
           if l:=integrate_idty(nil,pdes,%forg,
                                ftem_,vl_) then pdes:=l else
           <<write " no success"$terpri()>>
      else if s='ic then check_history(pdes)
      else if s='iy then 
           for each l in pdes do mathprint {'EQUAL,l,get(l,'histry_)}
      % to trace and debug -----------------------
      else if s='tm then <<tr_main:=not tr_main;
        if tr_main then write"tr_main is now on." 
                   else write"tr_main is now off.">>
      else if s='tg then <<tr_gensep:=not tr_gensep;
        if tr_gensep then write"tr_gensep is now on." 
                     else write"tr_gensep is now off.">>
      else if s='ti then <<tr_genint:=not tr_genint;
        if tr_genint then write"tr_genint is now on." 
                     else write"tr_genint is now off.">>
      else if s='td then <<tr_decouple:=not tr_decouple;
        if tr_decouple then write"tr_decouple is now on." 
                       else write"tr_decouple is now off.">>
      else if s='tl then <<tr_redlength:=not tr_redlength;
        if tr_redlength then write"tr_redlength is now on." 
                        else write"tr_redlength is now off.">>
      else if s='ts then <<tr_short:=not tr_short;
        if tr_short then write"tr_short is now on." 
                    else write"tr_short is now off.">>
      else if s='to then <<tr_orderings:=not tr_orderings;
        if tr_orderings then write"tr_orderings is now on." 
                        else write"tr_orderings is now off.">>
      else if s='tr then <<
        change_prompt_to ""$ 
        write"Please type the name of the procedure to trace: "$
        l:=termread()$
        terpri()$
        eval {'tr,l}
      >>
      else if s='ut then <<
        change_prompt_to ""$ 
        write"Please type the name of the procedure to trace: "$
        l:=termread()$
        terpri()$
        evuntr list l
      >>
      else if s='br then <<
        terpri()$write"This is Standard Lisp. Return to Reduce by Ctrl D."$
        terpri()$
        break()
%        standardlisp()
      >>
      else if s='pc then <<
       change_prompt_to "The function name: "$ 
       s:=termread();
       change_prompt_to "The argument list in the form {arg1,...};  : "$ 
       l:=termxread();
       if (pairp l) and (car l = ' list) and idp s then
          prin2t list ("Result: ", apply(s,cdr l))
      >>
      else if s='in then <<
        change_prompt_to ""$ 
        write"Please give the name of the file to be read in"$terpri()$
        write"double quotes (no ;) : "$                        
        l:=termread()$
        terpri()$
        in l
      >>
      else if s='cu then InternTest(pdes,forg)
      else if s='qt then <<
        change_prompt_to ""$ 
        terpri()$
        write "Please type in a list of procedure names, like:  gcdf, .., reval;"$
        terpri()$
        write "which should be profiled: "$  terpri()$
        l:=termlistread()$
%        for each h in l do apply('qualtime,h)
%write"h=",h$
%qualtime bldmsg("%w",h)
      >>
      else if s='pq then 
        if getd 'print!-qualtime then print!-qualtime()
                                 else write"*** Load package qualified-timing first! ***"
      else if s='so then <<
        change_prompt_to ""$ 
        write"Please give the name of the switch to be switched ON: "$
        l:=termread()$
        terpri()$
        s:=eval intern compress append(explode '!*,explode l);
        if null s then <<
         switch_list:=cons({level_,l,s},switch_list);
         on1 l
        >>
      >>
      else if s='sf then <<
        change_prompt_to ""$ 
        write"Please give the name of the switch to be switched OFF: "$
        l:=termread()$
        terpri()$
        s:=eval intern compress append(explode '!*,explode l);
        if s then <<
         switch_list:=cons({level_,l,s},switch_list);
         off1 l
        >>
      >>
!#if (memq 'psl lispsystem!*)
      else if s='ls then mapobl function switchp
!#else                         % for CSL REDUCE
      else if s='ls then for each x in oblist() do switchp x
!#endif
      else if s='lg then list_global_crack_variables() 
      % to parallelize -----------------------
      else if (s='xp) or (s='sp) or (s='jp) or (s='pp) then 
      if ini_check_of_parallel_crack() then <<
       % Open new duplicate process
       no_of_children:=add1 no_of_children;
       level_:=cons(bldmsg("c%d",no_of_children),level_)$
       l:=!*iconic;
       !*iconic:=nil$  % --> a window opens
       if s='xp then <<
        write"Duplicating process under new xterm."$terpri()$
        add_session(pdes,forg,1)
       >>       else
       if s='sp then <<
        write"Duplicating process under new screen."$terpri()$
        write"Hint: For this to work, this computation must run on the"$
        terpri()$
        write"same computer/node on which this screen has started."$
        terpri()$
        add_session(pdes,forg,2)
       >>       else
        if s='jp then <<
        write"Duplicating process as batch job."$terpri()$
        add_session(pdes,forg,3)
       >>       else << % s='pp
!#if (memq 'psl lispsystem!*)
        if ini_check_of_parallel_crack() and pvm_active() then <<
         write"Duplicating process under PVM."$terpri()$
         processes:=add_process(processes,pdes,forg)$
        >>$
!#else                    
        write"PVM is currently only available in PSL Reduce,"$terpri()$
        write"not in the Lisp system used in this session."$terpri()$
!#endif
       >>$
       !*iconic:=l$
       level_:=cdr level_
      >>                               else
      else if (s='wp) or (s='yp) or (s='zp) or (s='vp) then <<
       if collect_sol then <<
        write"### Currently is collect_sol=t. Therefore parallel case"$terpri()$
        write"### solving is not enabled because solutions would not"$terpri()$
        write"### be collected. You could set collect_sol to nil using"$terpri()$
        change_prompt_to ""$ 
        write"Shall solutions from now on be stored exclusively in files (Y/N) ? "$
        repeat l:=termread() until (l='y) or (l='n)$
        if l='y then collect_sol:=nil
                else collect_sol:=t
       >>;
       if null(collect_sol) and 
          ini_check_of_parallel_crack() then <<
        crack_load_cmd()$
        setq(l,bldmsg("%w%w",session_,"sol_list"));
        if not filep l then save_sol_list()$

        % Enable parallel treatment of cases
        if s='wp then <<
         auto_para_mode:=1;
         write"From now on parallel case solving with extra xterm's."$
         terpri()$
         change_prompt_to ""$ 
	 write"Shall xterms start as icons (Y/N) ? "$
 	 repeat l:=termread() until (l='y) or (l='n)$
	 if l='y then !*iconic:=t
		 else !*iconic:=nil;
        >>       else  
        if s='yp then <<
         auto_para_mode:=2;
         write"From now on parallel case solving with extra screens."$
         terpri()
        >>       else  
        if s='zp then <<
         auto_para_mode:=3;
         write"From now on parallel case solving by submitting jobs."$
         terpri()
        >>       else <<
         pvm_activate()$
         terpri()$
         if pvm_able then <<
          auto_para_mode:=4;
          write"From now on parallel case solving under PVM."$
          terpri()
         >>          else write"PVM is not active on this computer."
        >>
       >>
      >>
      else if s='np then <<
       write"The counter of additional parallel REDUCE processes which is stored"$
       terpri()$
       write"in the file ",process_counter," is set to zero."$
       terpri()$
% The next line needs review - it is certainly not portable (eg to Windows).
       system bldmsg("touch %w",process_counter)$ % creating file if necessary
       proczaehler(process_counter,'init)$        % setting counter to zero
      >>
      else if s='mp then <<
       change_prompt_to ""$ 
       write"The new maximal number of parallel processes (currently ",max_proc_no,"): "$
       max_proc_no:=termread()
      >>
      else if s='tp then <<
       change_prompt_to "The directory name for storing case files: "$ 
       para_case_dir:=termread()
      >>
      else if s='dp then <<pvm_able:=nil; auto_para_mode:=nil>>
      % Disable parallel treatment of cases
      %else if (s='kp) and pvm_active() then processes:=drop_process(processes)
       % Kill a parallel PVM process
      else if s='fo then <<
       form_comp:=t$
       change_prompt_to ""$ 
       write"Do you want to interface with FORM through pipes (Y/N)? "$
       repeat s:=termread() until (s='y) or (s='n)$
       if s='y then form_pipe:=t
               else form_pipe:=nil$
       write"Shall the temporary FORM directory be """,form_tmp_dir,"""  (Y/N)? "$
       repeat s:=termread() until (s='y) or (s='n)$
       if s='n then <<
        write"Please input the directory for temporary FORM computations in ""..."" : "$
        form_tmp_dir:=termread();
        write"The temporary FORM directory is now ",form_tmp_dir$
       >>;
       write"What is the maximal number of terms of an equations"$terpri()$
       write"computed by FORM that shall be read into REDUCE?"$terpri()$
       write"(Its current value is ",form_max_read,".)  : "$
       form_max_read:=termread();
      >>
      else if s='ff then form_comp:=nil
      else if s='gs then groeb_solve:=<<
       change_prompt_to ""$ 

       find_Singular()$
       if singular_call and singular_lib then <<
        repeat <<
         write"What is the max time allowed in seconds? "$ 
         l:=termread()$
        >> until fixp l$
        singular_time:=l$
        write"Use reverse total degree ordering? (y/n) "$ 
        l:=termread()$
        if l='y then 'SL_REVGRAD 
                else <<
         write"Pure lexicographical ordering is used."$terpri()$
         'SL_LEX
        >>
       >>
      >>
      else if s='gg then <<
       change_prompt_to "Use reverse total degree ordering? (y/n) "$ 
       l:=termread()$
       if l='y then 'GB_REVGRAD 
               else <<
        write"Pure lexicographical ordering is used."$terpri()$
        'GB_LEX 
       >> 
      >>
      else if s='gr then groeb_solve:='REDUCE
      else if s='df then groeb_solve:='DiffElim
      % otherwise -------------------------------------
      else <<
       if size_watch and not fixp size_watch then % otherwise avoid growth
       history_:=cons(bldmsg("*** %w previous input is illegal",ps),
                             cons('ig,history_))$
       write "illegal input: '",s,"'"$terpri()
      >>$
      restore_interactive_prompt()$ 

      if ifl!* then rds cadr ifl!*$ 
      if ofl!* then wrs cdr ofl!*$
     >>;
     if (not pdes) and fnc_to_adjust then
     if fnc_adjusted then <<adjust_fnc:=t; % back to original value
                            fnc_to_adjust:=nil>> 
                     else
     if contradiction_ or result then fnc_to_adjust:=nil 
                                 else <<
       to_do_list:=cons(list('del_redundant_fc,list nil),
                        to_do_list);
       adjust_fnc:=nil;  % in order not to run in a loop
       fnc_adjusted:=t
     >>
    >>
  until contradiction_ or result or stop_ or unsolvable 
        or (not pdes and not fnc_to_adjust and not eqn_to_be_gen 
            and ((equations_file="") or (eqn_input='done)))$

  % This is not needed anymore as ineq_ gets constantly updated:
  %  ineq_:=drop_triv_ineq(ineq_);

  if not (contradiction_ or result) then <<
    if (print_ or null collect_sol) and not stop_ then <<terpri()$
      terpri()$ write">>>>>>>>> Solution"$
      if level_ then write" of level ",level_string(nil)$
      write" : "$
    >>$

    forg:=sub_fsub_in_itself_and_in_forg(forg)$ 

    % updating ftem_, flin_, fhom_:
    f_update(pdes,forg)$
    % integrating df(f,..)=.. :
    forg:=forg_int(forg,ftem_)$

    if null collect_sol then <<s:=print_;print_:=100>>$
    print_pde_forg_ineq(pdes,(ineq_ . ineq_or),
                        append(forg,setdiff(ftem_,forg)),vl_)$
    if null collect_sol then print_:=s$
    if not stop_ then <<
      % The following is a procedure the user can define to do
      % specific operations with each solution, e.g. substitution of
      % original equations, substitution into formulae,...
      % This became necessary when for non-linear problems non-solutions
      % were introduced.
      l:=if null sol_list then 1
                          else add1 length sol_list;
      if not null(getd 'crack_out) and call_crack_out then algebraic 
      (s:=crack_out(
           lisp cons('LIST,for each a in pdes collect {'!*SQ,get(a,'sqval),t}),
           lisp cons('LIST,for each a in setdiff(forg,ftem_) collect
                           {'EQUAL,cadr a,aeval {'!*SQ,caddr a,nil}}),
           lisp cons('LIST,ftem_),
           lisp cons('LIST,append(for each a in ineq_ collect aeval {'!*SQ,a,nil},
                           if null ineq_or then nil else
                           cons('LIST,for each a in ineq_or collect 
                                      % each a is a single or-inequality
                                      cons('LIST,for each b in a collect 
                                                 % each b is a single expression 
                                                 % in an or-inequality
                                                 cons('LIST,for each c in b 
                                                      collect aeval 
                                                      {'!*SQ,c,nil}))))),
           lisp l))                                   else s:=nil;
      % If s is not null then s is expected to be an algebraic list of
      % expressions that should be zero but are not and therefore make
      % a new start necessary. This is only relevant for non-linear
      % problems.
      if s and (cdr s) and null lin_problem then <<        

        % the original PDEs under the current case conditions
        for each l in pdes do <<
         h:=simplifypdeSQ(get(l,'sqval),ftem_,t,l,t)$
         put(l,'sqval,car h)$
         put(l,'fac,cdr h)
        >>$

        % the conditions returned from crack_out()
        pl:=pdes;        
        for each l in cdr s do
        pdes:=eqinsert(mkeqSQ(<<h:=aeval l;
                                if pairp h and (car h='!*SQ) then cadr h
                                                             else simp h>>,
                              nil,nil,ftem_,vl_,allflags_,
                              t,list(0),nil,pdes),pdes)$
        if setdiff(pdes,pl) then <<
          if print_ then <<
            write"Not all conditions are solved."$terpri()$
            write" --> RESTART with extra conditions ",setdiff(pdes,pl)$
            terpri()>>$
          unsolvable:=nil$
          goto again
        >>
      >>
    >>$

    if session_ and null collect_sol then <<
     % determining all non-assignments in forg (this can not be done 
     % with setdiff(forg,ftem_) as some non-assigned f's in forg may not
     % appear in remaining equations and thus not be in ftem_ anymore.
     s:=nil$
     for each l in forg do 
     if not pairp l or car l neq 'EQUAL then s:=cons(l,s)$

     save_solution(for each a in pdes collect prepsq get(a,'sqval),
                   for each a in setdiff(forg,s) collect {'EQUAL,cadr a,prepsq caddr a},
                   union(s,ftem_),
                   for each a in ineq_   collect prepsq a,
                   for each a in ineq_or collect 
                       for each l in a     collect 
                           for each s in l   collect prepsq s,
                   nil);                     % nil:file_name unsp.

     if pdes and (length pdes > 1) then <<
      if level_ then
      s:=append(reverse cdr reverse explode session_,
                cdr explode level_string(nil))
                else s:=explode session_;
      s:=compress cons(car s,cons('u,cons('s,cdddr s)));
      backup_to_file(pdes,forg,s)
     >>
    >>$
    result:=if not collect_sol then list(1) else    % 1 = # of solutions
            list list(for each a in pdes collect get(a,'sqval),
                      forg,
                      setdiff(ftem_,forg),
                      ineq_,
                      ineq_or)
  >>$

  % dec_hist_list:=dec_hist_list_copy$
  if tr_main and print_ then
     <<terpri()$write "end of the main procedure"$terpri()>>$
  l:=(length level_)+1-level_length;

  for s:=1:l do if level_ then 
  finish_level(%  the # of solutions
               if null result then 0 else
               if collect_sol or (not pairp result) or 
                  (not fixp car result) then length result
                                        else if null car result then 0
                                                                else car result
              )$

  % delete property lists
  % It would take way too long and would be inefficient to do:
  % for l:=1:(sub1 nequ_) do drop_pde(mkid(eqname_,l),pdes,nil)$
  drop_all_pdes(pdes)$

  %<<<<<<< To be replaced by a check whether any of these PDEs
  % has still any property
  for l:=1:(sub1 nequ_) do <<
   s:=mkid(eqname_,l);
   if prop s then <<
    % write"Equation ",s," has properties although it should not."$terpri()$
    setprop(s,nil)
   >>
  >>$ 

  for each l in forg do
  if pairp l then setprop(cadr l,nil)
             else setprop(     l,nil)$

  return result
end$ % of crackmain


symbolic procedure sub_fsub_in_itself_and_in_forg(forg)$ 
if null fsub_ then forg else 
begin scalar l,s$
 % Performing the substitutions collected in fsub_ in forg
 l:=fsub_;
 while cdr l do << % use substitution car l in all of cdr l
  s:=cdr l;
  while s do <<
   rplaca(s,(caar s . {'!*SQ,subsq(cadr cdar s,{car l}),t}))$
   s:=cdr s
  >>$
  l:=cdr l
 >>$
 while fsub_ do <<
  forg:=car sub_in_forg(caar fsub_,cdar fsub_,forg);
  fsub_:=cdr fsub_
 >>$
 return forg
end$


%symbolic procedure sub_fsub_in_forg(forg)$
%% This procedure returns forg after all substitutions in fsub_ had been done
%% This does not do substitutions within fsub_.
%<<for each s in reverse fsub_ do 
%  forg:=car sub_in_forg(car s,cdr s,forg);
%  forg
%>>$


%algebraic procedure crack_out(eqns,assigns,freef,ineq,solno)$
% eqns    .. list of remaining unsolved equations
% assigns .. list of computed assignments of the form `function = expression'
% freef   .. list of list of functions either free or in eqns
% ineq    .. list of inequalities
% solno   .. number of the solution
% 
% If anything other than nil is returned then this is expected to be
% an algebraic list of expressions that should be zero but are not and
% therefore make a new start necessary. This is only relevant for
% non-linear problems.
%begin
% % If a call of crack is made from this procedure then one should have:
% % scalar call_crack_out_bak,session_bak,collect_sol_bak,sol_list_bak$
% lisp<<
%  collect_sol_bak:=collect_sol$
%  collect_sol:=t$
%  sol_list_bak:=sol_list$
%  session_bak:=session_
% >>$
% crack()$
% lisp<<
%  collect_sol:=collect_sol_bak$
%  sol_list:=sol_list_bak$
%  session_:=session_bak$
% >>
%end$

symbolic procedure priproli(proclist)$
begin integer i$
      scalar l,cpy$
 for each a in proclist do <<
  cpy:=full_proc_list_;
  i:=1;
  while a neq car cpy do <<i:=add1 i;cpy:=cdr cpy>>$
  if null cpy then i:=0;
  terpri()$
  if i<10 then write " "$
  write i$
  write " : "$
  if pairp(l:=get(a,'description)) then
     (for each s in l do if s then write s)
  else write a>>$
 terpri()$
end$

symbolic procedure priprolinr(proclist,fullproclist)$
begin integer i,j$
 scalar cfpl$
 j:=0;
 for each a in proclist do <<
  j:=j+1;
  i:=1;
  cfpl:=fullproclist;
  while cfpl and (a neq car cfpl) do <<i:=add1 i$cfpl:=cdr cfpl>>$
  if cfpl then <<if (j>1) then write ","$
     if j>21 then <<j:=1;terpri()>>$
     write i>>$
  >>$
 write";"$terpri()$
end$

symbolic procedure changeproclist()$
begin scalar l,p,err;
   terpri()$
   write "Please type in a list of the numbers 1 .. ",
          length full_proc_list_,", like 1,2,5,4,..,15; which"$
   terpri()$
   write"will be the new priority list of procedures done by CRACK."$
   terpri()$
   write"Numbers stand for the following actions:"$terpri()$
   priproli(full_proc_list_)$
   terpri()$write"The list so far was: "$
   priprolinr(proc_list_,full_proc_list_)$
   change_prompt_to "The new list: "$  
   l:=termlistread()$
   restore_interactive_prompt()$
   if null l then err:=t
             else <<
     while l do <<
       if (not fixp car l) or
          (car l > length full_proc_list_) 
       then 
          <<terpri()$write "Error: ",car l,
                           " is not one of the possible numbers.";
          l:=nil$
          err:=t>>
       else <<
         p:=union(list nth(full_proc_list_,car l),p);
         l:=cdr l
       >>
     >>;
   >>;
   if not err then 
     <<proc_list_:=reverse p;
     if null proc_list_ or ('to_do neq car proc_list_) then <<
      proc_list_:=cons('to_do,proc_list_)$
      write"The first number must be 1 (to do most urgent steps first)."$
      terpri()
     >>$
     if size_watch then 
     size_hist:=cons(cons('CP,for each l in proc_list_ collect get(l,'no)),
                     size_hist);
     %terpri()$write"The new order of procedures:"$ priproli(proc_list_)
     >>
   else
     <<terpri();write "The procedure list is still unchanged."$terpri()>>
end$

symbolic procedure printproclist()$
begin
 terpri()$
 write "Procedures used currently for automatic execution:"$
 priproli(proc_list_)
end$

symbolic procedure printfullproclist()$
begin
 terpri()$
 write "The complete list of available procedures:"$
 priproli(full_proc_list_)
end$

symbolic procedure printmainmenu()$
<<terpri()$
  write "hd : Help to inspect data"$terpri()$
  write "hp : Help to proceed"$terpri()$
  write "hf : Help to change flags & parameters"$terpri()$
  write "hc : Help to change data of equations"$terpri()$
  if getd 'show_id then 
  write "hi : Help to work with identities"$terpri()$
  write "hb : Help to trace, debug and configure"$terpri()$
  write "hl : Help to duplicate and parallelize runs"$terpri()$
  write "he : Help to use external systems"$terpri()$
>>$

symbolic procedure print_hd()$
<<terpri()$
  write "e  : Print equations"$                             terpri()$
  write "eo : Print overview of functions in equations"$    terpri()$
  write "pi : Print inequalities"$                          terpri()$
  write "f  : Print functions and variables"$               terpri()$
  write "v  : Print all derivatives of all functions"$      terpri()$
  write "s  : Print statistics"$                            terpri()$
  write "fc : Print no of free cells"$                      terpri()$
  write "pe : Print an algebraic expression"$               terpri()$
  write "ph : Print history of interactive input"$          terpri()$
  write "pv : Print value of any lisp variable"$            terpri()$
  write "pf : Print no of occurences of each function"$     terpri()$
  write "po : Print no of occurences of each factor"$       terpri()$
  write "pr : Print active substitution rules"$             terpri()$
  write "pd : Plot the occurence of functions in equations"$terpri()$
  write "ps : Plot a statistical history"$                  terpri()$
  write "lc : List all case distinctions"$                  terpri()$
  write "ws : Write statistical history in file"$           terpri()$
  write "sn : Show name of session"$                        terpri()$
  write "ss : Find and print sub-systems"$                  terpri()$
  write "w  : Write equations into a file"$                 terpri()$
>>$

symbolic procedure print_hp()$
<<terpri()$
  write "a  : Do one step automatically"$                   terpri()$
  write "g  : Go on for a number of steps automatically"$   terpri()$
  write "t  : Toggle equation selection to : "$
              if expert_mode then write "AUTOMATIC"
                             else write "USER"$             terpri()$
  write "p1 : Print a list of all modules in batch mode"$   terpri()$
  write "p2 : Print a complete list of all modules"$        terpri()$
  write "#  : Execute the module with the number `#' once"$ terpri()$
  write "l  : Execute a specific module repeatedly"$        terpri()$
  write "sb : Save complete backup to file"$                terpri()$
  write "rb : Read backup from file"$                       terpri()$
%  write "ep : Enable parallelism"$                          terpri()$
%  write "dp : Disable parallelism"$                         terpri()$
%  write "pp : Start an identical parallel process"$         terpri()$
%  write "kp : Kill a parallel process"$                     terpri()$
  write "an : Add non-triviality conditions for param. lin. sys."$
                                                            terpri()$
  write "rs : Compute resultant of two polynomials"$        terpri()$
  write "x  : Exit interactive mode for good"$              terpri()$
  write "q  : Quit current level or crack if in level 0"$   terpri()$
>>$

symbolic procedure print_hf()$
<<terpri()$
  write "pl : Maximal length of an expression to be printed (",
              print_,")"$                                   terpri()$
  write "pm : ",if print_more then "Do not p" else "P",
              "rint more information about the pdes"$       terpri()$
  write "pa : ",if print_all then "Do not p" else "P",
              "rint all information about the pdes"$        terpri()$
  write "cp : Change the priorities of procedures"$         terpri()$
  write "og : Toggle ordering to ",
              if lex_fc then "derivatives > functions" 
                        else "functions > derivatives"$     terpri()$
  write "od : Toggle ordering of derivatives to ",
              if lex_df then "total-degree" 
                        else "lexicographic"$               terpri()$
  write "oi : Interactive change of ordering on variables"$ terpri()$
  write "or : Reverse ordering on variables"$               terpri()$
  write "om : Mix randomly ordering on variables"$          terpri()$
  write "of : Interactive change of ordering on functions"$ terpri()$
  write "op : Print current ordering"$  terpri()$
  write "ne : Root of the name of new generated equations (",
              eqname_,")"$                                  terpri()$
  write "nf : Root of the name of new functions and constants (",
              fname_,")"$                                   terpri()$
  write "ni : Root of the name of new identities (",
              idname_,")"$                                  terpri()$
  write "na : Change output to "$
              if !*nat then write "OFF NAT"
                       else write "ON NAT"$                 terpri()$
  write "as : Input of an assignment"$                      terpri()$
%  write "kp : ",if keep_parti then "Do not keep"
  write "ke : ",if keep_parti then "Do not keep"
                              else "Keep",
              " a partitioned copy of each equation"$       terpri()$
  write "fi : ",if freeint_ then "Allow unresolved integrals"
              else "Forbid unresolved integrals"$           terpri()$
  write "fa : ",if freeabs_ then "Allow solutions of ODEs with ABS()"
              else "Forbid solutions of ODEs with ABS()"$   terpri()$
  write "cs : ",if confirm_subst then 
              "No confirmation of intended substitutions/factorizations"
                                 else 
              "Confirmation of intended substitutions/factorizations"$
                                                            terpri()$
  write "fs : ",if force_sep
                then "Do not enforce direct separation"
                else "Enforce direct separation"$           terpri()$
  write "ll : change of the line length"$                   terpri()$
  write "re : ",if do_recycle_eqn then "Do not re-cycle equation names."
                                  else "Do re-cycle equation names."$
                                                            terpri()$
  write "rf : ",if do_recycle_fnc then "Do not re-cycle function names."
                                  else "Do re-cycle function names."$
                                                            terpri()$
  write "st : Setting a CPU time limit for un-interrupted run"$ 
                                                            terpri()$
  write "cm : Adding a comment to the history_ list"$       terpri()$
  write "lr : Adding a LET-rule"$                           terpri()$
  write "cr : Clearing a LET-rule"$                         terpri()$
  write "ap : Adapting the setting to the system to be solved"$ terpri()$
  write "ho : Find all homogeneities of the system"$        terpri()$
>>$

symbolic procedure print_hc()$
<<terpri()$
  write "r  : Replace or add one equation"$                 terpri()$
  write "rd : Reduce an equation modulo LET rules"$         terpri()$
  write "n  : Add one inequality"$                          terpri()$
  write "de : Delete equations"$                            terpri()$
  write "di : Delete one inequality"$                       terpri()$
  write "c  : Change a flag or property of one pde"$        terpri()$
  write "pt : Perform a transformation of functions and variables"$ 
                                                            terpri()$
  % write "se : Sort equation list by size"$                  terpri()$
>>$

symbolic procedure print_hi()$
if getd 'show_id then 
<<terpri()$
  write "i  : Print identities between equations"$          terpri()$
  write "id : Delete redundand equations"$                  terpri()$
  write "iw : Write identities to a file"$                  terpri()$
  write "ir : Remove list of identities"$                   terpri()$
  write "ia : Add or replace an identity"$                  terpri()$
  write "ih : Start recording histories and identities"$    terpri()$
  write "is : Stop recording histories and identities"$     terpri()$
  write "ii : Integrate an identity"$                       terpri()$
  write "ic : Check the consistency of identity data"$      terpri()$
  write "iy : Print the history of equations"$              terpri()$
>>$

symbolic procedure print_hb()$
<<terpri()$
  write "tm : ",if tr_main then "Do not t" else "T",
              "race main procedure"$                        terpri()$
  write "tg : ",if tr_gensep then "Do not t" else "T",
              "race generalized separation"$                terpri()$
  write "ti : ",if tr_genint then "Do not t" else "T",
              "race generalized integration"$               terpri()$
  write "td : ",if tr_decouple then "Do not t" else "T",
              "race decoupling process"$                    terpri()$
  write "tl : ",if tr_redlength then "Do not t" else "T",
              "race decoupling length reduction"$           terpri()$
  write "ts : ",if tr_short then "Do not t" else "T",
              "race algebraic length reduction"$            terpri()$
  write "to : ",if tr_orderings then "Do not t" else "T",
              "race orderings process"$                     terpri()$
!#if (memq 'psl lispsystem!*)
  write "tr : Trace an arbitrary procedure"$                terpri()$
!#endif
  write "ut : Untrace a procedure"$                         terpri()$
  write "br : Break"$                                       terpri()$
  write "pc : Do a function call"$                          terpri()$
  write "in : Reading in a REDUCE file"$                    terpri()$
  write "cu : Check uniqueness of all standard quotients"$  terpri()$
  write "qt : Choose functions to profile"$                 terpri()$
  write "pq : Show profiling result"$                       terpri()$
  write "so : Switch a switch ON"$                          terpri()$
  write "sf : Switch a switch OFF"$                         terpri()$
  write "ls : List REDUCE switch settings"$                 terpri()$
  write "lg : List global CRACK variables"$                 terpri()$
>>$

symbolic procedure print_hl()$
<<terpri()$
  write "xp : Duplicate process under new xterm"$           terpri()$
  write "sp : Duplicate process under new screen"$          terpri()$
  write "jp : Duplicate process submitted as offline job"$  terpri()$
  write "pp : Duplicate process under PVM"$                 terpri()$

  write "wp : Perform parallel case solving with xterm's"$  terpri()$
  write "yp : Perform parallel case solving with screen's"$ terpri()$
  write "zp : Perform parallel case solving with jobs"$     terpri()$
  write "vp : Perform parallel case solving under PVM"$     terpri()$

  write "np : Set counter of parallel processes to zero"$   terpri()$
  write "mp : Specify max. number of parallel processes"$   terpri()$
  write "tp : Specify directory for storing cases"$         terpri()$
  write "dp : Disable parallel case solving"$               terpri()$
%  write "kp : Kill a parallel PVM process"$                 terpri()$
% not working as 'processes' is not global variable and not yet
% supported by auto_para_mode=1..3
>>$

symbolic procedure print_he()$
<<terpri()$
  write "fo : Select FORM for computing S-polynomials"$     terpri()$
  write "ff : Do not use FORM"$                             terpri()$
  write "gs : Select Singular for Groebner bases"$          terpri()$
  write "gg : Select GB package of J.C.Faugere for Groebner b."$terpri()$
  write "gr : Select REDUCE package for Groebner bases"$    terpri()$
  write "df : Select DiffElim for diff. Groebner bases"$    terpri()$
>>$

symbolic procedure to_do(arglist)$
if to_do_list then
  begin scalar p,l$
    p:=car to_do_list;
    to_do_list:=cdr to_do_list;
    if tr_main and print_ and print_more then
      if pairp(l:=get(car p,'description)) then 
         <<for each a in l do if a then write a$
         write " : ">>                                    
      else write "trying ",car p," : "$
    l:=apply(car p,list(cons(car arglist,cons(cadr arglist,
                             cons(caddr arglist, cdr p)))))$
    if not l then l:=arglist$
    return l$
  end$

symbolic procedure subst_derivative(arglist)$
% Substitution of a derivative of a function by an new function
% in all pdes and in forg
begin scalar f,l,q,g,h,pdes,forg,found_sub$
  pdes:=car arglist$
  forg:=cadr arglist$
  l:=check_subst_df(pdes,forg)$
  for each d in l do
  if not in_cycle({9,stepcounter_,d}) then <<
    found_sub:=t$
    f:=newfct(fname_,fctargs cadr d,nfct_)$
    nfct_:=add1 nfct_$
    ftem_:=fctinsert(f,delete(cadr d,ftem_))$
    if flin_ and not freeof(flin_,cadr d) then 
    flin_:=sort_according_to(f . flin_, ftem_);
    if print_ then
      <<terpri()$write "replacing "$
        fctprint1 d$
        write " by "$fctprint list f$terpri()>>$
    for each s in pdes do dfsubst_update(f,d,s)$
    % integrating f in order to substitute for cadr d
    % in ineq_
    h:=cddr d;
    g:=simp f;
    while h do <<
      for r:=1:(if (length h =1) or
                   ((length h > 1) and (not fixp cadr h))
                then 1
                else (cadr h) 
               )   do 
      g:=addsq(simp gensym(),mksq(list('INT,prepsq g,car h),1));  
      h:=cdr h;
      if h and (fixp car h) then h:=cdr h
    >>;
    % now the substitution in ineq_
    ineq_:=for each s in ineq_ collect subsq(s,{(cadr d . {'!*sq,g,t})}); 
                                     % reval subst(g,cadr d,s);
    % now the substitution in fsub_
    fsub_:=for each s in fsub_ collect 
           (car s . {'!*SQ,subsq(caddr s,{(cadr d . {'!*sq,g,t})}),t});

    if member(cadr d,forg) then <<
       ftem_:=fctinsert(cadr d,ftem_)$ % puting cadr d back into ftem_
       q:=mkeqSQ(subtrsq(simp d,simp f),nil,nil,
                   %list('PLUS,d,list('MINUS,f)),
                   list(f,cadr d),fctargs f,allflags_,nil,list(0),nil,pdes)$
       remflag1(q,'to_eval)$
       put(q,'not_to_eval,cons(f,get(q,'not_to_eval)))$
       pdes:=eqinsert(q,pdes)>>$
    forg:=dfsubst_forg(f,g,cadr d,forg)$
    >>$
  return if found_sub then list(pdes,forg)
                      else nil
end$ 
 
symbolic procedure undo_subst_derivative(arglist)$
% undo Substitution of a derivative of a function by an new function
% in all pdes and in forg
begin scalar success$
 for each p in car arglist do 
     if get(p,'not_to_eval) then 
        <<remprop(p,'not_to_eval)$
        flag(list p,'to_eval)$
        success:=t>>$
 return if success then arglist
                   else nil
end$


symbolic procedure subst_power(arglist)$
% yields a list of unknowns and their lowest degree 
begin scalar pdes,s,a,al,d,f,p,q,newf,sb,new_eq,old_eq,ok;
 pdes:=car arglist;

 % al is an assoc list of constant unknowns, their lowest degrees and
 % their number of appearences
 % al=({a3,2,5) (a1,1,3) (a2,3,1))
 % Find the smallest degree of each entry of 'derivs in any equation
 % If the degree is not a multiple of the so far lowest degree then
 % the lowest degree is set to 1 if it is not already one.
 % Substitutions are done only for unknowns with lowest degree>1, and
 % with >1 appearences.

 for each s in pdes do 
 if get(s,'nvars)=0 then  % <-- actually in all equations but only for constants
 for each d in get(s,'derivs) do <<
  a:=al; f:=caar d; p:=cdr d;
  while a and f neq caar a do a:=cdr a;
  if null a then al:=cons({f,p,1},al) else 
  if cadar a neq 1 then
  if p=1 then rplacd(car a,{1,1}) else
  if cadar a = p then rplacd(car a,{cadar a,add1 caddar a}) 
                 else rplacd(car a,{gcdf(cadar a,p),add1 caddar a})
 >>;
 
 % Drop all entries of degree 1
 while al and ((cadar al = 1) or (caddar al = 1)) do al:=cdr al;
 if al then <<
  a:=al;
  while cdr a do
  if (cadar cdr a = 1) or (caddar cdr a = 1) then rplacd(a,cddr a)
                                             else a:=cdr a
 >>$

 if null al then return nil;

 while al do << % handle each power replacement
  a:=car al;  al:=cdr al;
  newf:=newfct(fname_,nil,nfct_)$ nfct_:=add1 nfct_;
  ftem_:=fctinsert(newf,ftem_)$
  f:=car a;

  % formulating a LET-rule for the substitution
  sb:={'REPLACEBY,{'EXPT,car a,cadr a},newf};
  algebraic(let lisp sb);

  new_eq:=nil;
  old_eq:=nil;
  ok:=t;

  p:=pdes;
  while p and ok do 
  if freeof(get(car p,'fcts),f) then p:=cdr p
                                else <<
   q:=mkeqSQ(get(car p,'sqval),nil,nil,cons(newf,get(car p,'fcts)),
             get(car p,'vars),allflags_,t,list(0),nil,pdes);
   if not freeof(get(q,'fcts),f) then ok:=nil
                                 else <<
    new_eq:=cons(q,new_eq);
    old_eq:=cons(car p,old_eq);
    p:=cdr p
   >>
  >>;

  if null ok then for each q in new_eq do drop_pde(q,pdes,nil)
             else <<
   algebraic(clear lisp sb);

   % adding new and deleting old equations
   for each q in new_eq do pdes:=eqinsert(q,pdes);
   for each q in old_eq do pdes:=drop_pde(q,pdes,nil);

   % generating the new equation and adding all to pdes
   q:=mkeqSQ(nil,nil,{'DIFFERENCE,newf,{'EXPT,car a,cadr a}},{newf,f},nil,allflags_,nil,
             list(0),nil,pdes);
   put(q,'not_to_eval,{newf})$
   pdes:=eqinsert(q,pdes)

  >>
 >>$  % end of: while al do ..

 return cons(pdes,cdr arglist)

end$


symbolic procedure factorize_any(arglist)$
% Factorization of a pde and investigation of the resulting subcases
begin scalar h,l$
 if expert_mode then l:=selectpdes(car arglist,1)
                else l:=cadddr arglist$
 l:=get_fact_pde(l,nil)$
 if l then h:=get(l,'case2sep)$

 return
 if h then split_into_cases {car arglist, cadr arglist, caddr arglist, h} else 
 if l then split_into_cases {car arglist, cadr arglist, caddr arglist, car get(l,'fac)} else 
 nil

end$

symbolic procedure factorize_to_substitute(arglist)$
% Factorization of a pde and investigation of the resulting subcases
begin scalar l$
 if expert_mode then l:=selectpdes(car arglist,1)
                else l:=cadddr arglist$
 l:=get_fact_pde(l,t)$
 return 
 if l then split_into_cases {car arglist, cadr arglist, caddr arglist, car get(l,'fac)}
      else nil
end$

symbolic procedure separation(arglist)$
% Direct separation of a pde
if vl_ then % otherwise not possible --> save time
begin scalar p,l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 if (p:=get_separ_pde(l1)) then
    <<l:=separate(p,pdes)$
      % if l=1 then a case distinction has been put on to_do_list 
      % and simply the input has to be returned from this procedure
      % to start to_do next
      if l=1 then l:=list(pdes,forg) else
      if l and
         ((length l>1) or
          ((length l = 1) and (car l neq p))) then
         <<pdes:=drop_pde(p,pdes,nil)$ 
           while l do <<pdes:=eqinsert(car l,pdes)$ l:=cdr l>>$
           l:=list(pdes,forg)
         >> 
 >>$
 return l$
end$

symbolic procedure case_separation(arglist)$
% does a separation of expressions where the unknowns may occur 
% as exponents, may generate case distinctions,
% in order not to run in cirles some substitution needs a higher priority
if null lin_problem then
begin scalar force_sep_bak,h$
 force_sep_bak:=force_sep$ force_sep:=t$
 h:=separation(arglist)$
 force_sep:=force_sep_bak$
 return h
end$

symbolic procedure alg_solve_system(arglist)$
begin scalar pdes,l1,l2,l3,l4,l5,l6,fl,vl,zd,pdes2$
 pdes:=car arglist$
 %l1:=selectpdes(pdes,nil)$
 l1:=select_from_list(pdes,nil)$
 if null l1 then return nil;
 for each l2 in l1 do vl:=union(get(l2,'vars),vl);
 for each l2 in l1 do fl:=union(get(l2,'fcts),fl);
 l1:=for each l2 in l1 collect get(l2,'sqval)$
 write"Please give a list of constants, functions or derivatives"$
 terpri()$
 write"of functions to be solved algebraically, like f,g,df(g,x,2);"$
 terpri()$
 l2:=termlistread()$
 if l2 then <<
  l3:=cdr solveeval list(cons('LIST,l1),cons('LIST,l2));
  % We don't check for complex solutions and add ON COMPLEX because
  % only the linear case is used below.
  % solveeval liefert eg: (list (list (equal x -3) (equal y -3)))
  if null l3 then << 
   write"There is no solution."$ 
   terpri()
  >> else
  if length l3 > 1 then <<  %######### 1 solution - a restriction for now
   write"can currently not handle more than 1 solution"$
   terpri()
  >> else <<
   l3:=for each l4 in l3 collect <<        % for each solution l4
    l4:=for each l5 in cdr l4 collect <<
     zd:=union(zero_den(reval l5,fl),zd)$
     l6:=reval {'PLUS,cadr l5,{'MINUS,caddr l5}}$
     if pairp l6 and (car l6 = 'QUOTIENT) then cadr l6
                                          else l6 
    >>       % l4 is now a list of expressions to vanish
   >>;
   if length l3 = 1 then << % should be quaranteed from above
    l4:=car l3;             % the solution
    pdes2:=pdes;
    for each l5 in l4 do <<
     l5:=if zd then mkeqSQ(nil,cons(simp l5,zd),nil,
                           fl,vl,allflags_,nil,list(0),nil,pdes)
               else mkeqSQ(nil,nil,l5,
                           fl,vl,allflags_,nil,list(0),nil,pdes)$
     pdes:=eqinsert(l5,pdes)$
    >>;
    if print_ then <<
     pdes2:=setdiff(pdes,pdes2);
     write"New equations: ",pdes2$terpri()$
    >>$
    return {pdes,cadr arglist}
   >>
  >> 
 >>
end$

symbolic procedure alg_solve_single(arglist)$
% Solving an equation that is algebraic for a function
% or a derivative of a function,
% So far no flag is installed to remember a corresponding
% investigation because the check is quick and done very
% rarely with lowest priority.
% Because standard quotient operations, like multsq do not
% simplify i^2 --> -1, also not simp or reval this leads to
% problems when ineq_ expressions are not properly simplified
% which then may be zero leading to zero denominators.
% Therefore it is advisable to give this module only a
% very low priority, just before 38.

begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 if (l:=algsolvederiv(l1,pdes)) then 
    <<pdes:=drop_pde(car l,pdes,nil)$
      pdes:=eqinsert(cdr l,pdes)$
      to_do_list:=cons(list('factorize_any,%pdes,forg,caddr arglist,
                            list cdr l),
                       to_do_list);
      l:=list(pdes,forg);
    >>$
 return l
end$

symbolic procedure alg_for_deriv(p)$
% find the first function with only one sort of derivative
% which in addition occurs non-linear
begin scalar dl,d,f$
 dl:=get(p,'derivs);

 % NEW 19.5.07: only 2 different functions/derivatives:
 % if null dl or (length get(p,'allvarfcts) > 2) then return nil$
 % VARIED 28.11.07:  in order not to get non-rational expressions
 % if null dl or (fhom_ and (length get(p,'allvarfcts) > 2)) then return nil$
 % VARIED 11.4.08: in an application more general solutions were needed
 % and because complex numbers can appear only at the end anyway and at the end
 % it does not matter if non-rational solutions are generated
 % if null dl then return nil$
 % dropped again as it gave far too complicated solutions which could not
 % be used for anything.
 % VARIED 27.10.2008: For the z3z3 application a version is needed that
 % runs automatically. Homogeneous algebraic equations are supposed to be delt
 % with module 78
 if null dl or (length get(p,'allvarfcts) > 1) then return nil$

 % NEW 19.5.07: only quadratic homogeneous equations if computation is 
 % supposed to be exact:
 % if get(p,'hom_deg) neq {0,2} then return nil$
 % VARIED 28.11.07:
 if flin_ and not freeoflist(get(p,'allvarfcts),flin_) then return nil$

 % because an flin_ function could not occur non-linearly
 % and a non-flin_ function could not be solved for in terms of 
 % an flin_ function

 while dl and null d do <<  % for each function
  d:=car dl$     % d is the leading power of the leading deriv. of f
  f:=caar d;     % the next function f
  if fctlength f < get(p,'nvars) then <<d:=nil;dl:=nil>>
                                 else <<
   dl:=cdr dl;
   if cdr d = 1 then d:=nil; % must not be linear in lead. deriv.
   while dl and (f = caaar dl) do <<
    if d and (car d neq caar dl) then d:=nil;
    dl:=cdr dl
   >>
  >>
 >>;
 return d
end$

symbolic procedure algsolvederiv(l,pdes)$
begin scalar d,p,q,drop,fctrl$
 while l and null (d:=alg_for_deriv(car l)) do l:=cdr l;
 if d then <<
  p:=cdr d$
  d:=solveeval list({'!*SQ,get(car l,'sqval),t},
                    if 1=length car d then caar d
                                      else cons('DF,car d));
  % 30.11.08: To avoid difficult solutions which do not simplify
  % but crash future computations:
  if p>2 then
  if not freeoflist(d,{'ROOT_OF,'COS,'SIN,'SINH,'COSH,'TAN,
                       'ACOSH,'ASIN,'ATAN,'ASINH,'ACOSH}) then d:=nil
                                                          else <<
   q:=search_li(d,'SQRT)$ % Find the cadr of all sublists which have 'SQRT as car

   while q and null drop do
   if pairp car q then <<drop:=t;q:={'sqrt,car q}>>
                            else q:=cdr q;

   if null drop then <<
    q:=search_li2(d,'EXPT)$ % Find all sublists which have 'EXPT as car
    while q and null drop do
    if not fixp caddar q and pairp cadar q then <<drop:=t;q:=car q>>
                                           else q:=cdr q
   >>;

   if drop then <<
    write"The solution "$
    mathprint d$
    write"of the equation "$
    mathprint {'!*SQ,get(car l,'sqval),t}$
    write"was ignored because of the term"$
    mathprint q$
    d:=nil
   >>;

  >>;

  if (not freeof(d,'i)) or (not freeof(d,'!:gi!:)) then algebraic(ON COMPLEX)$
  
  if not freeof(d,'abs) then <<
   algebraic (let abs_);
   d:=algebraic lisp d;
   algebraic(clearrules abs_);
  >>$

  if d and (car d='LIST) % and (length d = p+1) taken out beause of multi. roots
  then <<
   p:=simp 1;
   
   for each el in cdr d do
   if car el='EQUAL then <<
    fctrl:=cons(subtrsq(simp cadr el, simp caddr el),fctrl);
    p:=multsq(car fctrl,p)
   >>               else d:=nil

  >>                                          else d:=nil;

  if d then <<
%   d:=cons('TIMES,p);
   d:=p;
   p:=car l;
   d:=mkeqSQ(d,fctrl,nil,get(p,'fcts),get(p,'vars),allflags_,
             nil,get(p,'orderings),nil,pdes)$
   % last argument is nil as no new inequalities are to be expected.
   % but that has been changed as one never knows and it does not do
   % harm, can only be beneficial
   if print_ then write p," factorized to ",d
  >>
 >>;
 return if d then p . d
             else nil
end$

symbolic procedure quick_integration(arglist)$
% Integration of a short first order de with at most two terms
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then 
 <<l1:=selectpdes(pdes,1);flag(l1,'to_int);flag(l1,'to_fullint)>>
                else l1:=cadddr arglist$
 if (l:=quick_integrate_one_pde(l1)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in l do 
        to_do_list:=cons(list('subst_level_35,%pdes,forg,caddr arglist,
                              list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
 if null l and to_do_list then << % case invest. issued in odeconvert 
  l:=arglist$
  flag(l1,'to_int);
  flag(l1,'to_fullint)
 >>$
 return l$
end$

symbolic procedure full_integration(arglist)$
% Integration of a pde 
% only if then a function can be substituted
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then 
 <<l1:=selectpdes(pdes,1);flag(l1,'to_int);flag(l1,'to_fullint)>>
                else l1:=cadddr arglist$
 if (l:=integrate_one_pde(l1,genint_,t)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in l do 
      if not freeof(pdes,s) then 
        to_do_list:=cons(list('subst_level_35,%pdes,forg,caddr arglist,
                              list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
 if null l and to_do_list then << % case invest. issued in odeconvert 
  l:=arglist$
  flag(l1,'to_int);
  flag(l1,'to_fullint)
 >>$
 return l$
end$

symbolic procedure integration(arglist)$
% Integration of a pde 
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then 
 <<l1:=selectpdes(pdes,1);flag(l1,'to_int);flag(l1,'to_fullint)>>
                else l1:=cadddr arglist$
 if (l:=integrate_one_pde(l1,genint_,nil)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in cdr l do 
      if not freeof(pdes,s) then 
        to_do_list:=cons(list('subst_level_35,%pdes,forg,caddr arglist,
                              list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
 if null l and to_do_list then << % case invest. issued in odeconvert 
  l:=arglist$
  flag(l1,'to_int);
  flag(l1,'to_fullint)
 >>$
 return l$
end$

symbolic procedure multintfac(arglist)$
% Seaching of an integrating factor for a set of pde's
begin scalar pdes,forg,l,stem,ftem,vl,vl1$
 pdes:=car arglist$
 if null pdes or (length pdes=1) then return nil$
 forg:=cadr arglist$
 for each p in pdes do
   if not (get(p,'starde) or get(p,'nonrational)) then
     <<stem:=cons(prepsq get(p,'sqval),stem)$
       ftem:=union(get(p,'fcts),ftem)$
       vl:=union(get(p,'vars),vl)
     >>$
 vl1:=vl$   
 fnew_:=nil$
 while vl1 do
  if (l:=findintfac(stem,ftem,vl,car vl1,nil,nil,nil,nil)) then
    <<ftem:=smemberl(ftem,car l)$
      vl:=union(smemberl(vl,car l),argset ftem)$
      l:=addintco(car l, ftem, nil, vl, car vl1)$
      for each f in fnew_ do
        ftem_:=fctinsert(f,ftem_)$
      ftem:=union(fnew_,ftem)$
      fnew_:=nil$
      pdes:=eqinsert(mkeqSQ(nil,nil,l,smemberl(ftem_,ftem),vl,
                            allflags_,t,list(0),nil,pdes),
                     pdes)$
      vl1:=nil$ 
      l:=list(pdes,forg)>>
  else vl1:=cdr vl1$
 return l$
end$

symbolic procedure diff_length_reduction(arglist)$
% Do one length reduction step
begin scalar l$
 l:=dec_and_red_len_one_step(car arglist,ftem_,%cadr arglist,
                             caddr arglist,0)$
 % 0 for ordering
 if l then l:=list(l,cadr arglist)$
 return l$
end$

symbolic procedure high_prio_decoupling(arglist)$
% Do one decoupling step
begin scalar l$
 l:=dec_one_step(car arglist,ftem_,%cadr arglist,
                 caddr arglist,t,0)$ 
 % 0 for ordering
 if l then l:=list(l,cadr arglist)$
 return l$
end$

symbolic procedure decoupling(arglist)$
% Do one decoupling step
begin scalar l$
 l:=dec_one_step(car arglist,ftem_,%cadr arglist,
                 caddr arglist,nil,0)$ 
 % 0 for ordering
 if l then l:=list(l,cadr arglist)$
 return l$
end$

symbolic procedure clean_dec(p,pdes,flg)$
begin scalar propty,el,nl,newpropty$
 propty:=get(p,flg)$
 for each el in propty do <<
  nl:=intersection(cdr el,pdes);
  if nl then newpropty:=cons(cons(car el,nl),newpropty)
 >>$
 put(p,flg,reverse newpropty)
end$

symbolic procedure clean_prop_list(pdes)$ 
if null car recycle_eqns          and 
        cdr recycle_eqns          and 
   (length cdr recycle_eqns > 50) then 
<<for each p in pdes do <<
    clean_dec(p,pdes,'dec_with)$
    clean_dec(p,pdes,'dec_with_rl)$
  % clean_rl(p,pdes) :
    put(p,'rl_with,intersection(pdes,get(p,'rl_with)))$
  >>$
  % recycle_eqns is a pair of 2 lists: 
  % (ready to use eqn. names) . (free eqn. names which still 
  %                              may occur in prob_list)
  recycle_eqns:=append(car recycle_eqns,reverse cdr recycle_eqns) . nil;
  nil
>>$

symbolic procedure clean_up(pdes)$
begin scalar newpdes;
  while pdes do <<
    if flagp(car pdes,'to_drop) then 
    drop_pde(car pdes,nil,nil)  else 
    newpdes:=cons(car pdes,newpdes);
    pdes:=cdr pdes
  >>;
  return reverse newpdes
end$

symbolic procedure cut_size_hist$
if fixp size_watch then 
begin scalar n,sh,l;
 n:=0;
 sh:=size_hist;
 while (n<size_watch) and sh do <<n:=add1 n; sh:=cdr sh>>$
 if sh then <<
  rplacd(sh,nil);
  rplaca(sh,cons('CP,for each l in proc_list_ collect get(l,'no)))
 >>
end$

symbolic procedure add_differentiated_pdes(arglist)$
% all pdes in which the leading derivative of a function of all
% vars occurs nonlinear will be differentited w.r.t all vars and
% the resulting pdes are added to the list of pdes
begin scalar pdes,l,l1,l2,q$
 pdes:=car arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 for each p in l1 do
 if flagp(p,'to_diff) then <<
   % --- it should be differentiated only once
   for each f in get(p,'allvarfcts) do <<
     l2:=ld_deriv(p,f)$
     if l2 and (cdr l2 > 1) then <<
       if print_ then <<
         terpri()$
         write "differentiating ",p," w.r.t. "$
         listprint fctargs f$
         write " we get the new equations : "
       >>$
       for each v in fctargs f do <<
         q:=mkeqSQ(diffsq(get(p,'sqval),v),nil,nil,get(p,'fcts),get(p,'vars),
                   delete('to_diff,allflags_),t,list(0),nil,pdes)$
         if q then <<
           if get(q,'terms)>1 then <<
             remflag1(q,'to_int)$
             remflag1(q,'to_fullint)
           >>$
           prevent_simp(v,p,q)$
           if print_ then write q," "$
           pdes:=eqinsert(q,pdes)
         >>
       >>$
       remflag1(p,'to_diff)$
       l:=cons(pdes,cdr arglist)
     >>
   >>
 >>$
 return l$
end$

symbolic procedure add_diff_ise(arglist)$
% a star-pde is differentiated and then added
begin scalar pdes,l,l1,q,vli$
  pdes:=car arglist$
  if expert_mode then l1:=selectpdes(pdes,1)
                 else l1:=cadddr arglist$
  for each p in l1 do
  if flagp(p,'to_diff) 
     and (null l) 
     and get(p,'starde)
  then << 
    vli:=if expert_mode then select_from_list(get(p,'vars),nil)
                        else get(p,'vars);
    if print_ then
    <<terpri()$
      write "differentiating ",p," w.r.t. "$
      listprint vli$
      write " we get the new equations : "
    >>$
    for each v in vli do
    <<q:=mkeqSQ(diffsq(get(p,'sqval),v),nil,nil,get(p,'fcts),get(p,'vars),
                delete('to_fullint,delete('to_int,allflags_)),
                t,get(p,'orderings),nil,pdes)$
      if null get(q,'starde) then <<
        flag(list q,'to_fullint)$
        flag(list q,'to_int)$
      >>$
      prevent_simp(v,p,q)$
      %check whether q really includes 'fcts and 'vars: should be ok
      if print_ then write q," "$
      pdes:=eqinsert(q,pdes)$
    >>$
    remflag1(p,'to_diff)$
    l:=cons(pdes,cdr arglist)$
  >>$
  return l$
end$

symbolic procedure external_groebner(arglist)$
if car arglist and (length car arglist > 1) and
   not in_cycle({59,stepcounter_,groeb_solve,singular_time,
                 length car arglist,length cadr arglist,
                 for each h in car arglist sum get(h,'terms),
                 for each h in car arglist sum get(h,'length)}) then 
err_catch_groeb(arglist)$


symbolic procedure split_into_cases(arglist)$
% programmed or interactive introduction of two cases whether a 
% given expression is zero or not. If called automatically then
% this expression is cadddr arglist. It must be in sq-form.
if not contradiction_ then % that should always be the case
begin scalar h,hh,s,pdes,forg,contrad,n,pf,q,sqf,l1,l2,result,intact,
             print_bak,enlarged_depl!*,sqf_must_be_zero$ 
             %,contra_bak,newfdep,bak,sol,f,depl
  pdes:=car arglist$
  forg:=cadr arglist$
  if cdddr arglist then h:=cadddr arglist$
  if h=pdes then << % interactive call
    intact:=t$
    terpri()$
    write "Type in the expression for which its vanishing and"$
    terpri()$
    write "non-vanishing should be considered."$
    terpri()$
    write "You can use names of pds, e.g.: "$terpri()$
    write "coeffn(e_12,df(f,x,2),1);    or   df(e_12,df(f,x,2));"$
    terpri()$
    change_prompt_to "the expression: "$  
    h:=termxread()$
    restore_interactive_prompt()$ 
    for each hh in pdes do 
    if not freeof(h,hh) then <<
     if null get(hh,'val) then put(hh,'val,prepsq get(hh,'sqval));
     h:=subst(get(hh,'val),hh,h)$ 
    >>$
    h:=simp h
    % bracket from below under the (checked) assumption that h can involve
    % equation names only if h is specified interactively.
  >>$  

  % Preliminary contradiction tests

  %% 20.11.2006: One should have only simplifypde() OR may_vanish()
  %% because both factorize
  % if not may_vanish(h) then return <<

  print_bak:=print_$ print_:=nil$ % not to print the finding of a contradiction
% h:=simplifypde(h,smemberl(ftem_,h),t,nil)$     % (h,ftem,tofactor,eqn_name)$
  hh:=simplifySQ(h,smemberl(ftem_,h),t,nil,t)$ % (p,ftem,fctr,en,sep)$ 
  if hh={(1 . 1)} then contradiction_:=t$
  print_:=print_bak$

  if contradiction_ then return <<
    contradiction_:=nil$  % already assigned here as it may 
                          % again be set by addineq below
    if intact then <<
      write"According to the known inequalities, ",
           "this expression can not vanish!"$
      terpri()$
      write" --> Back to main menu."$terpri()$
      nil
    >>        else <<
      for each l2 in hh do if l2 neq (1 . 1) then addSQineq(pdes,l2,nil)$ 
      addSQineq(pdes,h,nil)$  % no simplification as simplification
                              % obviously simplifies to (1 . 1) whereas
                              % it was obviously not known that h neq 0
      {pdes,forg}  
    >>
  >>$

  if intact then << 
    write"If you first want to consider this expression to vanish and"$ 
    terpri()$
    write"afterwards it to be non-zero then input t"$ terpri()$
    write"                        otherwise input nil : "$
    change_prompt_to ""$  
    s:=termread()$
    restore_interactive_prompt()$ 
  >>        else s:=nil$  % s=t is the default case, ie.   1. h=0,   2. h<>0

  contrad:=t$ 
  n:=0$
  %-------------------
  backup_to_file(pdes,forg,nil)$ 
  % It is necessary to collect the new dependencies from the first run
  % to know them after the 2nd run. This would be accomplished by moving
  % the backup_to_file() command directly after `again:'. Here we do it 
  % cheaper by storing it in enlarged_depl!* .

  sqf:=car hh; 
  for each q in cdr hh do sqf:=multsq(q,sqf)$
  pf:=prepsq sqf$
  q:=nil$ % should not be necessary

  % sgf is the product of the list of factors hh resultinng from simplification
  % of the expressions h which is to be considered to be zero or not.

again:

  n:=add1 n$
  if s then <<   %====== the case that the expression h vanishes
    start_level(n,list {'EQUAL,0,pf})$ if print_ then terpri()$

    if sqf_must_be_zero then <<
      % find and delete all equations which have sqf or one of the elements
      % of hh as a factor
      for each q in pdes do <<
        l1:=get(q,'fac);
        if member(h,l1) % or member(sqf,l1) or not freeoflist(l1,hh) 
        then l2:=cons(q,l2)
      >>$
      for each q in l2 do <<
        if print_ then <<
          write"Equation ",q," is deleted because it has a vanishing factor."$ 
          terpri()
        >>$
        pdes:=drop_pde(q,pdes,nil)
        % last argument phist=nil because it had been found somewhere in
        % addSQineq that a factor of sqf must vanish which has not been recorded
      >>$
      q:=l1:=l2:=nil$ % should not be necessary
    >>                  else <<
      q:=mkeqSQ(sqf,hh,pf,ftem_,vl_,allflags_,t,list(0),nil,pdes)$
      if print_ then 
      if contradiction_ then <<
        write "The case"$
        deprint(list pf)$
        write "contradicts inequalities and is not further investigated."$
      >>                else <<
        write "CRACK is now called with the assumption 0 = ",q," : "$
        deprint(list pf)$
      >>
    >>
  >>   else <<   %====== the case that h does not vanish identically
    start_level(n,list {'INEQ,0,pf})$
    if print_ then <<
      terpri()$
      write "CRACK is now called with assuming  "$terpri()$
      mathprint pf$
      write" to be nonzero. "$
    >>$

    for each l2 in hh do addSQineq(pdes,l2,nil)$ 
    if contradiction_ then <<
      if print_ then 
      write"According to the system of equations, this expression must be zero!"$
      sqf_must_be_zero:=t
    >>
  >>$
  % necessary steps to call crackmain():

  if contradiction_ then <<  % skip this case
    if print_ then <<
      terpri()$
      if n=1 then write" --> Next case."
             else write" --> Case splitting completed."$
    >>$
    contradiction_:=nil$
    l1:=nil$
    finish_level(0)
  >>                      else <<
    recycle_fcts:=nil$  % such that functions generated in the sub-call 
                        % will not clash with existing functions
    l1:=crackmain_if_possible_remote(if null s or sqf_must_be_zero
                                     then pdes 
                                     else eqinsert(q,pdes),forg)
  >>;

  forg:=restore_and_merge(l1,pdes,forg)$  % also necessary if l1=nil
  pdes:= car forg; 
  forg:=cadr forg;

  if not contradiction_ then contrad:=nil$ 
  if l1 and not contradiction_ then result:=merge_crack_returns(l1,result);
  contradiction_:=nil$ 

  if n=1 then <<
   enlarged_depl!*:=depl!*$
   s:=not s; 
   goto again 
  >>     else depl!*:=union(depl!*,enlarged_depl!*)$

  delete_backup()$
  contradiction_:=contrad$            % =t only if all cases give contradiction
  if contradiction_ then result:=nil$
  if print_ then <<
    terpri()$
    write"This completes the investigation of all cases of a case-distinction."$
    terpri()$
  >>$
  return list result
  % by returning `list result' and not just `result', what is returned
  % is a list with only a single element. This is indicating that the
  % content of what is returned from this procedure is a list of
  % crackmain returns and not (pdes,forg) which is returned from
  % other modules and which is a list of more than one element.
end$


symbolic procedure stop_batch(arglist)$
begin scalar s;
 if !*batch_mode then <<
  write"Drop this point from the proc_list_ with 'o, 'cp or quit with 'q."$
  terpri()$
  !*batch_mode:=nil$
 >>$
 s:=length car arglist;
 if (max_eqn_to_conti=0) or
    (car arglist and (length car arglist>max_eqn_to_conti)) then return <<
  % The above test has been included, so that having stop_batch as
  % last module in the proc_list_ one can have it stop only if at
  % least 2 equations are unsolved by setting globally max_eqn_to_conti:=1
  if null print_ then print_:=8$
  terpri()$
  write"The program changes now into interactive mode because there "$terpri()$
  if s=1 then write"is 1 equation"
         else write"are ",s," equations"$
  write" left to be solved which could not be solved"$terpri()$
  write"with the steps preceeding this step 38. If you want to finish the"$terpri()$
  write"computation in cases that not more than n equations are unsolved"$terpri()$
  write"then do 'as max_eqn_to_conti n;' where n is an integer."$terpri()$
  batchcount_:=stepcounter_ - 2$
  arglist
 >>
end$

symbolic procedure user_defined(arglist)$
begin
 arglist:=nil;  % only to use arglist
end$

symbolic procedure back_up(arglist)$
backup_to_file(car arglist,cadr arglist,nil)$


symbolic procedure sub_problem(arglist)$
begin scalar s,h,fl,newpdes,sol,pdes,bak,newfdep,f,sub_afterwards,
      session_bak,level_bak,lazy_eval_bak$

 if !*batch_mode then return nil;
 terpri()$
 change_prompt_to ""$
 if null lin_problem then <<
  write"This module so far works only if the solution of the"$terpri()$
  write"sub-problem does not lead into case distinctions."$terpri()$
  write"Do you want to continue (Y/N)? "$
  repeat s:=termread() until (s='y) or (s='n)$
  if s='n then <<
   restore_interactive_prompt()$ 
   return nil
  >>
 >>$
 terpri()$
 % Choice
 write"Do you want all linear equations to be solved first    --> Enter 1"$
 terpri()$
 write"Do you want to specify a set of equations to be solved --> Enter 2"$
 terpri()$
 write"or a set of functions (and then all equations containing"$
 terpri()$
 write"ONLY these functions are selected)                     --> Enter 3"$
 terpri()$
 write"or a set of functions (and then all equations containing"$
 terpri()$
 write"NOT these functions are selected)                      --> Enter 4"$
 write"or a set of variables (and then all equations containing"$
 terpri()$
 write"only derivatives w.r.t. these variables are selected)  --> Enter 5: "$

 repeat h:=termread() until ((fixp h) and (1<=h) and (h<=5))$

 terpri()$
 if h=1 then <<  %------ subset of all linear equations
  for each s in car arglist do
  if get(s,'linear_) then newpdes:=cons(s,newpdes)$
  newpdes:=reverse newpdes;
  if null newpdes then <<
   write"There are no linear equations in the system."$
   terpri()
  >>              else
  for each s in newpdes do fl:=union(fl,get(s,'fcts));
 >>     else
 if h=2 then <<  %------ Input of a subset of equations
  write"Specify a subset of equations to be solved in the form:  "$
  listprint(car arglist)$
  write";"$ terpri()$ 
  s:=termlistread()$
  h:=setdiff(s,car arglist);
  if s=nil then newpdes:=nil else 
  if h then <<
   write"Equations ",h," are not valid."$ terpri()$
   newpdes:=nil
  >>                             else <<
   for each h in s do fl:=union(fl,get(h,'fcts));
   newpdes:=s
  >>
 >>     else 
 if h=3 then <<  %------ Input of a subset of functions to occur
  write"Specify a subset of functions to be solved in the form:  "$
  listprint(ftem_)$
  write";"$ terpri()$ 
  s:=termlistread()$
  h:=setdiff(s,ftem_);
  if s=nil then newpdes:=nil else 
  if h then <<
   write"Functions ",h," are not valid."$
   terpri()$
   newpdes:=nil
  >>                             else <<
   fl:=s;
   % Determining a subset of equations containing only these functions
   for each s in car arglist do
   if null setdiff(get(s,'fcts),fl) then newpdes:=cons(s,newpdes)$
   if null newpdes then <<
    write"There is no subset of equations containing only these functions."$
    terpri()
   >>
  >>
 >>     else   
 if h=4 then <<  %------ Input of a subset of functions not to occur
  write"Specify a subset of functions to be avoided in the form:  "$
  listprint(ftem_)$
  write";"$ terpri()$ 
  s:=termlistread()$
  h:=setdiff(s,ftem_);
  if s=nil then newpdes:=nil else 
  if h then <<
   write"Functions ",h," are not valid."$
   terpri()$
   newpdes:=nil
  >>                             else <<
   fl:=s;
   % Determining a subset of equations not containing these functions
   for each s in car arglist do
   if freeoflist(get(s,'fcts),fl) then newpdes:=cons(s,newpdes)$
   if null newpdes then <<
    write"There is no subset of equations not containing these functions."$
    terpri()
   >>
  >>
 >>     else <<
  write"Specify a subset of variables in the form:  "$
  listprint(vl_)$
  write";"$ terpri()$ 
  s:=termlistread()$
  h:=setdiff(s,vl_);
  if s=nil then newpdes:=nil else 
  if h then <<
   write"Variables ",h," are not valid."$
   terpri()$
   newpdes:=nil
  >>   else <<
   fl:=setdiff(vl_,s);
   % Determining a subset of equations containing only derivatives wrt. these variables
   for each s in car arglist do
   if freeoflist(get(s,'derivs),fl) then newpdes:=cons(s,newpdes)$
   if null newpdes then <<
    write"There is no subset of equations containing only derivatives wrt. these variables."$
    terpri()
   >>;
   fl:=nil$
   for each s in newpdes do fl:=union(fl,get(s,'fcts));
  >>
 >>;
 if null newpdes then return nil;

 terpri()$
 write "Do you want an automatic substitution "$terpri()$
 write "of computed functions afterwards (Y/N)? "$
 repeat s:=termread() until (s='y) or (s='n)$
 if s='y then sub_afterwards:=t
         else sub_afterwards:=nil;

 restore_interactive_prompt()$ 
 write"CRACK is now called with the following subset of equations"$
 terpri()$
 write newpdes$ terpri()$
 write"!!!!! HINT: "$ terpri()$
 write"Because the current system to solve is only a subsystem,"$terpri()$
 write"--> it may have more solutions --> it is harder to solve"$terpri()$
 write"--> do not try to solve it completely using decoupling"$terpri()$
 write"--> use CP to change the priority list and use only fast"$terpri()$
 write"    and safe steps and use 38 as last step."$terpri()$
 write"--> Example: cp   1,2,3,4,20,7,24,27,38;"$terpri()$terpri()$

 bak:=backup_pdes(car arglist,cadr arglist)$
 collect_sol:=t$ % is backed up
 session_bak:=session_$
 session_:=nil$  % to prevent interference with solutions and the casetree
 level_bak:=level_$
 lazy_eval_bak:=lazy_eval; lazy_eval:=nil;

 % After solving the subsystem, the modified inequalities are currently (May 2012)
 % discarted, and currently only linear subsystems are solved so to speed up
 % the solution of the subsystem, ineq_ and ineq_or are set to nil.
 ineq_:=ineq_or:=nil$

 % reduce ftem_ to only the unknowns that appear
 h:=nil;
 for each s in newpdes do h:=union(h,get(s,'fcts))$
 ftem_:=sort_according_to(h,ftem_)$
 fl:=sort_according_to(fl,ftem_)$
 lin_problem:=t$
 flin_:=nil$ 
 fhom_:=nil$

 sol:=crackmain(newpdes,fl)$
 % Returned inequalities are currently not taken care of!
 newfdep:=nil$
 batchcount_:=sub1 stepcounter_$

 for each s in sol do
 if pairp s then <<
  for each f in caddr s do 
  if h:=assoc(f,depl!*) then newfdep:=cons(h,newfdep);
 >>;
 session_:=session_bak$
 level_:=level_bak$
 lazy_eval:=lazy_eval_bak;

 % newfdep are additional dependencies of the new functions in l1
 pdes:=car restore_pdes(bak)$   % to restore all global variables and pdes
 depl!*:=append(depl!*,newfdep);
 ftem_:=union(ftem_,caddar sol)$
 % Test for contradiction or more than one solution
 % to be investigated further
 for each s in caar  sol do 
 pdes:=eqinsert(mkeqSQ(s,nil,nil,ftem_,vl_,allflags_,t,list(0),nil,pdes),
                pdes)$
 for each s in cadar sol do 
 if pairp s and (car s='EQUAL) then <<
  h:=mkeqSQ(subtrsq(caddr s,simp cadr s),nil,nil,
            ftem_,vl_,allflags_,t,list(0),nil,pdes);
  pdes:=eqinsert(h,pdes)$
  if sub_afterwards then  
  to_do_list:=cons(list('subst_level_35,%pdes,cadr arglist,caddr arglist,
                        list h),
                   to_do_list)
 >>$
 ftem_:=union(ftem_,caddar sol)$

 return {pdes,cadr arglist}
end$


symbolic procedure first_int_for_ode(arglist)$  
begin
 arglist:=cdr arglist$ % only to avoid warning
 if print_ then <<
  write"Unfortunately this module is not completely implemented yet."$
  terpri()
 >>$
 return nil
end$

endmodule$

end$
