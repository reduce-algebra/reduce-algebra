%**********************************************************************
module crackstar$
%**********************************************************************
%  Main program 
%  Author: Andreas Brand 1995, updates and extensions by Thomas Wolf
%
% $Id: crmain.red,v 1.34 1998/06/25 18:17:32 tw Exp tw $
%

symbolic operator crack$
symbolic procedure crack(el,il,fl,vl)$
begin scalar l,l1,l2,n,m,ezgcdold,mcdold,gcdold,expold,ratold,
             ratargold$
 if not check_globals() then
 <<
    rederr "Some global variables have incorrect values, please check!"$
 >>$
 if print_ and logoprint_ then <<
  terpri()$
  write
  "This is CRACK - a solver for overdetermined partial ",
  "differential equations"$
  terpri()$
  write "$Revision: 1.34 $ ($Date: 1998/06/25 18:17:32 $)"$terpri()$
  write "**********************************************************",
  "****************"$
  terpri()$
 >>$
 rulelist_:=if pairp userrules_ then
             if pairp crackrules_ 
              then list('LIST,userrules_,crackrules_)
              else list('LIST,userrules_)
            else 
            if pairp crackrules_ then 
             list('LIST,crackrules_)
                                 else nil$
 ezgcdold:=!*ezgcd$
 gcdold:=!*gcd$
 expold:=!*exp$
 mcdold:=!*mcd$
 ratold:=!*rational$
 ratargold:=!*ratarg$
 !*ezgcd:=t$
 !*gcd:=nil$
 !*exp:=t$
 !*mcd:=t$
 !*rational:=t$
 !*ratarg:=t$
 fnew_:=nil$
 ftem_:=nil$
 stop_:=nil$
 dec_hist_list:=nil$
 level_:=nil$
 stepcounter_:=0$
 batchcount_:=-1$
 n:=time()$
 m:=gctime()$
 if pairp el and (car el='LIST) then el:=cdr el
                                else el:=list el$
 if pairp fl and (car fl='LIST) then fl:=cdr fl
                                else fl:=list fl$
 if pairp vl and (car vl='LIST) then vl:=cdr vl
                                else vl:=list vl$
 if pairp il and (car il='LIST) then il:=cdr il
                                else il:=list il$
 l1:=el$
 for each p in il do l2:=union(ineqsplit(p,fl),l2)$
 il:=l2$
 vl:=union(reverse argset fl,vl)$
 fl:=fctlist(nil,nil,union(fl,nil))$
 orderings_:=make_orderings(fl, vl)$	% Orderings support!
 if not !*batch_mode then printmenu_:=t$
 history_:=nil;
 %
 % Orderings Note: orderings_prop_list_all() inserts all the valid
 % orderings into each of the initial equations, i.e. all equations
 % are in all orderings
 %
 l:=crackmain(mkeqlist(el,fl,vl,allflags_,t,orderings_prop_list_all()),
       	      il,fl,vl)$
 if l=list(nil) then l:=nil$
 l:=union(l,nil)$
 if !*time or time_ then
 <<terpri()$write "CRACK needed :  ",time()-n," ms    GC time : ",
                  gctime()-m," ms">>$ 
 for i:=1:nequ_ do  setprop(mkid(eqname_,i),nil)$
 l:=for each a in l collect
      <<l1:=nil$
	l2:=caddr a$
	for each b in cadr a do
	 if (pairp b) and (car b = 'EQUAL) then l1:=cons(b,l1)
					   else l2:=cons(b,l2)$
	list(car a,l1,l2,cadddr a)>>$
 if adjust_fnc and null stop_ then
    l:=for each a in l collect if l1:=dropredund(a,fl,vl) then cdr l1
							  else a$
 !*ezgcd:=ezgcdold$
 !*gcd:=gcdold$
 !*exp:=expold$
 !*mcd:=mcdold$
 !*rational:=ratold$
 !*ratarg:=ratargold$
 if print_ and logoprint_ then <<
  terpri()$
  write "This is the end of the CRACK run"$
  terpri()$
  write "**********************************************************",
        "****************"$
  terpri()$
 >>$
 return if l then
	cons('LIST,for each a in l collect 
                   list('LIST,cons('LIST,car a),
                              cons('LIST,cadr a),
                              cons('LIST,caddr a),
                              cons('LIST,cadddr a)))
	     else list('LIST)
end$

symbolic procedure crackmain(pdes,ineq,forg,vl)$
%   Main program
begin scalar result,l,pl,dec_hist_list_copy,%cases_copy,
             s,ps,batch_one_step,expert_mode_copy,
      	     loopcount,level_length,optionsl$
   level_length:=length level_;
   if tr_main and print_ then
      <<terpri()$write "start of the main procedure">>$
   depl_copy_:=depl!*$
   dec_hist_list_copy:=dec_hist_list$
   expert_mode_copy:=expert_mode$
   contradiction_:=nil$
   ineq_:=ineq$                         % global list of nonvanishing de's
   ftem_:=fctlist(ftem_,pdes,forg)$     % global list of free functions
   if printmenu_ then printmainmenu()$
   printmenu_:=nil$
   repeat
    <<pl:=proc_list_$           % global list of procedures
    stop_:=nil$
    ftem_:=fctlist(ftem_,pdes,forg)$
    vl:=var_list(pdes,forg,vl)$
    if !*batch_mode or batch_one_step or (batchcount_>=stepcounter_) then
    <<if !*batch_mode then
      if print_more then
         print_pde_fct_ineq(pdes,ineq_,
                            append(forg,setdiff(ftem_,forg)),vl)
      else print_statistic(pdes,append(forg,setdiff(ftem_,forg)))$
      stepcounter_:=add1 stepcounter_$
      if tr_main and print_ then 
       <<terpri()$terpri()$write "Step ",stepcounter_,":"$terpri()>>$
      batch_one_step:=nil$
      expert_mode:=nil$
      while pl do <<
        if tr_main and print_ and print_more then
        if pairp(l:=get(car pl,'description)) then <<
          for each a in l do if a then write a$
          write " : "
        >>                                    else 
        write "trying ",car pl," : "$
        l:=apply(car pl,list list(pdes,forg,vl,pdes))$
        if l and not contradiction_ then <<
          if length l = 1      % before the test was: if cases_ 
          then result:= car l  % car l is a list of crackmain results
                               % resulting from investigating subcases 
          else <<pdes:=car l$ forg:=cadr l>>$  % no case-splitting
          pl:=nil$
        >>                          else 
        if contradiction_ then pl:=nil
                          else <<
          pl:=cdr pl$
          if tr_main and print_ and print_more then 
          <<write " no success"$terpri()>>$
          if not pl then stop_:=t
        >> 
      >>
    >>
    else
      <<rds nil$wrs nil$
      ps:=promptstring!*$
      promptstring!*:="selected item: "$ 
      terpri()$s:=termread()$
      expert_mode:=expert_mode_copy$
      if s='m then printmainmenu()
      else if s='h then printhelp()
      else if s='a then batch_one_step:=t
      else if s='e then <<expert_mode:=not expert_mode$
                          expert_mode_copy:=expert_mode>>
      else if s='l then <<repeat_mode:=not repeat_mode>>
      else if s='g then 
       <<promptstring!*:="number of steps: "$
        s:=termread()$
        promptstring!*:="selected item: "$
        if fixp(s) then batchcount_:=sub1 stepcounter_+s
        else <<write "wrong input!!!"$terpri()>>
       >> 
      else if s='q then stop_:=t
      else if s='x then !*batch_mode:=t
      else if s='p then 
        print_pde_ineq(if expert_mode then selectpdes(pdes,1)
                                      else pdes,
                       ineq_)
      else if s='o then
      <<
	 % Orderings support!
 	 % Added return value to optionsmenu to allow changing of the
	 % variables list and pdes list
	 if tr_orderings then
	 <<
	    terpri()$ write "vl    : ", vl$
	    terpri()$ write "ftem_ : ", ftem_$
	 >>$
	 optionsl := optionsmenu(vl,pdes)$
	 vl := car optionsl$
	 pdes := cdr optionsl$
	 if tr_orderings then
	 <<
	    terpri()$ write "pdes  : ", pdes$
	    terpri()$ write "vl    : ", vl$
	    terpri()$ write "ftem_ : ", ftem_$
	 >>$
      >>
      else if s='c then change_pde_flag(pdes)
      else if s='w then write_in_file(pdes,ftem_)
      else if s='proc then printproclist()
      else if s='f then 
        <<print_fcts(append(forg,setdiff(ftem_,forg)),vl)$
        terpri()>>
      else if s='s then <<
        print_level()$
        print_statistic(pdes,append(forg,setdiff(ftem_,forg)))
      >>
      else if s='d then 
        pdes:=deletepde(pdes)
      else if s='r then 
        <<pdes:=replacepde(pdes,ftem_,vl);
        ftem_:=cadr pdes;
        pdes:=car pdes>>
      else if numberp s and (s>0) and (s<=length proc_list_) then
	<<loopcount:=0; 
      	repeat
          <<l:=apply(nth(pl,s),list list(pdes,forg,vl,pdes))$
          if l and not contradiction_ then 
            <<stepcounter_:=add1 stepcounter_$
            loopcount:=add1 loopcount$
            if length l = 1     % before the test was: if cases_ 
            then result:=car l  % car l is a list of crackmain results
                                % resulting from investigating subcases 
            else <<pdes:=car l$ forg:=cadr l>>$  % no case-splitting
            terpri()>>
          else if (not contradiction_) and (loopcount=0) then 
            <<write "no success"$terpri()>>
          >>
        until not repeat_mode or not l or contradiction_>>
      else 
	<<write "illegal input: '",s,"'"$terpri()>>$
      promptstring!*:=ps$
      if ifl!* then rds cadr ifl!*$ 
      if ofl!* then wrs cdr ofl!*$
     >>
    >>
   until contradiction_ or result or stop_ or not pdes$

   if not (contradiction_ or result) then <<
     if print_ then <<terpri()$
       terpri()$ write">>>>>>>>> Solution"$
       if level_ then <<
         write" of level "$
         for each m in reverse level_ do write m,"."$
       >>$
       write" : "$
     >>$
     ftem_:=fctlist(ftem_,pdes,forg)$
     forg:=forg_int(forg,ftem_)$
     print_pde_fct_ineq(pdes,ineq_,append(forg,setdiff(ftem_,forg)),vl)$      
     algebraic 
     crack_out(lisp(cons('LIST,for each a in pdes collect get(a,'val))),
               lisp(cons('LIST,setdiff(forg,ftem_))),
               lisp(cons('LIST,ftem_)),
               lisp(cons('LIST,ineq_)))$
     result:=if collect_sol then
             list list(for each a in pdes collect get(a,'val),
                       forg,setdiff(ftem_,forg),ineq_)
                            else list(nil)$
   >>$
   dec_hist_list:=dec_hist_list_copy$
   if tr_main and print_ then
      <<terpri()$write "end of the main procedure"$terpri()>>$
   l:=(length level_)+1-level_length;
   for s:=1:l do if level_ then level_:=cdr level_$
   return result$
end$

algebraic procedure crack_out(eqns,asigns,freef,ineq)$
begin
end$

symbolic procedure priproli(proclist)$
begin integer i$
      scalar l$
 for each a in proclist do
  <<i:=add1 i$
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
     if (i<10) then write " "$
     if i=((i/30)*30) then terpri()$
     write i>>$
  >>$
 terpri()$
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
   terpri()$write"The current list is:"$
   priprolinr(proc_list_,full_proc_list_)$
   l:=termxread()$
   if fixp l and 
      l <= length full_proc_list_ then l:=list('!*comma!*,l);
   if (not pairp l) or
      (car l neq '!*comma!*) 
   then
      <<terpri()$write"Error: not a legal list of elements.";
      err:=t>>
   else <<
     l:=cdr l;
     while l do <<
       if (not fixp car l) or
          (car l > length full_proc_list_) 
       then 
	  <<terpri()$write "Error: ",car l," is not an element number.";
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
     terpri()$write"The new order of procedures:"$
     priproli(proc_list_)>>
  else
     <<terpri()$write "The procedure list is still unchanged."$terpri()>>
end$

symbolic procedure printproclist()$
begin
 terpri()$
 write "Please select one of the following items"$
 priproli(proc_list_)
end$

symbolic procedure printmainmenu()$
<<printproclist()$
write "f  : Print functions and variables"$
terpri()$write "p  : Print pdes"$
terpri()$write "s  : Print statistics"$
terpri()$write "x  : Exit interactive mode"$
terpri()$write "q  : Quit"$
terpri()$write "h  : Help"$terpri()>>$

symbolic procedure printhelp()$
<<
terpri()$write "proc : Print list of procedures"$
terpri()$write "f    : Print functions and variables"$
terpri()$write "p    : Print pdes"$
terpri()$write "s    : Print statistics"$
terpri()$write "a    : Do one step automatically"$
terpri()$write "g    : Go on for a number of steps automatically"$
terpri()$write "l    : Toggle repeating mode to : "$
 if repeat_mode then write "SINGLE"
                else write "LOOP"$
terpri()$write "e    : Toggle equation selection to : "$
 if expert_mode then write "AUTOMATIC"
                else write "USER"$
terpri()$write "d    : Delete one pde"$
terpri()$write "r    : Replace or add one pde"$
terpri()$write "c    : Change a flag of one pde"$
terpri()$write "w    : Write equations into a file"$
terpri()$write "x    : Exit interactive mode"$
terpri()$write "o    : Enter a menu for the setting of options & flags"$
terpri()$write "q    : Quit crack"$
terpri()$write "m    : Menu"$
terpri()$write "h    : Help"$terpri()>>$

%
% Orderings support!
%
% For orderings we need to modify pdes and vl which means that we
% require them as options. We return a list (vl, pdes) with the
% possibly modified values.
%
symbolic procedure optionsmenu(vl,pdes)$
begin scalar s,ps,newvl,newftem$
 ps:=promptstring!*$
 while s neq 'x do
  <<
  terpri()$
  write "cp : Change the priorities of procedures"$
  terpri()$
  % Orderings support!
  write "o  : Toggle ordering (",
     if lex_ then "Lexicographic" else "Total-degree",
     " ordering in use)"$
  terpri()$
  write "ov : Change ordering on variables"$
  terpri()$
  write "of : Change ordering on functions"$
  terpri()$
  write "op : Print current ordering"$
  terpri()$
  % END Orderings support!
  write "p  : Maximal length of an expression to be printed (",print_,")"$
  terpri()$
  write "pm : ",
   if print_more then "Do not p" else "P",
   "rint more informations about the pdes"$
  terpri()$
  write "pa : ",
   if print_all then "Do not p" else "P",
   "rint all informations about the pdes"$
  terpri()$
  write "e  : Basic name of new generated equations (",eqname_,")"$
  terpri()$
  write "f  : Basic name of new functions and constants (",fname_,")"$
  terpri()$
  write "tm : ",
   if tr_main then "Do not t" else "T",
   "race main procedure"$
  terpri()$
  write "ts : ",
   if tr_gensep then "Do not t" else "T",
   "race generalized separation"$
  terpri()$
  write "ti : ",
   if tr_genint then "Do not t" else "T",
   "race generalized integration"$
  terpri()$
  write "td : ",
   if tr_decouple then "Do not t" else "T",
   "race decoupling process"$
  terpri()$
  write "tr : ",
   if tr_redlength then "Do not t" else "T",
   "race length reduction process"$
  terpri()$
  % Orderings support!
  write "to : ",
     if tr_orderings then "Do not t" else "T",
     "race orderings process"$
  terpri()$
  write "na : Change output to "$
  if !*nat then write "OFF nat"
           else write "ON nat"$
  terpri()$
  write "fc : Print no of free cells"$
  terpri()$
  write "br : Break"$
  terpri()$
  write "r  : Input of an assignment"$
  terpri()$
  write "x  : Exit this options menu"$
  terpri()$terpri()$
  s:=termread()$
  if s='cp then changeproclist()
  else if s='p then
   <<promptstring!*:="Print length : "$
   s:=termread()$
   if not s or fixp(s) then print_:=s
   else 
    <<terpri()$write "Print length must be NIL or an integer!!!"$terpri()>>
   >>
  % Orderings support!
  else if s='o then <<
     lex_:=not lex_$
     %
     % Go through the list of equations and change all the 
     % list of derivatives using sort_derivs() [new version
     % by Thomas]
     %
     pdes := change_derivs_ordering(pdes,ftem_,vl)$
  >>
  else if s='op then <<
     terpri()$
     write "Current orderings are :"$
     terpri()$
     write "Functions : ", ftem_$
     terpri()$
     write "Variables : ", vl$
  >>
  else if s='ov then <<
     terpri()$
     write "Current variable ordering is :", vl$
     terpri()$
     promptstring!*:="New variable ordering : "$
     newvl := termxread()$
     % !FIXME! Now we need to convert it to the correct form for vl
     vl := cdr newvl$
     % !FIXME! Do we need to change the derivs too?
     pdes := change_derivs_ordering(pdes,ftem_,vl)$
     if tr_orderings then <<
	terpri()$
     	write "New variable list: ", vl$
     >>$
  >>
  else if s='of then <<
     terpri()$
     write "Current function ordering is :", ftem_$
     terpri()$
     promptstring!*:="New function ordering : "$
     newftem := termxread()$
     % !FIXME! Now we need to convert it to the correct form for ftem_
     ftem_ := cdr newftem$
     % !FIXME! Do we need to change the derivs too?
     pdes := change_derivs_ordering(pdes,ftem_,vl)$
     if tr_orderings then <<
	terpri()$
     	write "New functions list: ", ftem_$
     >>
  >>
  else if s='to then tr_orderings:=not tr_orderings
  %
  else if s='pm then print_more:=not print_more
  else if s='pa then print_all:=not print_all
  else if s='tm then tr_main:=not tr_main
  else if s='ts then tr_gensep:=not tr_gensep
  else if s='ti then tr_genint:=not tr_genint
  else if s='td then tr_decouple:=not tr_decouple
  else if s='tr then tr_redlength:=not tr_redlength
  else if s='e then
   <<promptstring!*:="Equation name : "$
   s:=termread()$
   if s and idp s
    then eqname_:=s
   else 
    <<terpri()$write "Equation name must be an identifier!!!"$terpri()>>
   >>
  else if s='f then
   <<promptstring!*:="Function name : "$
   s:=termread()$
   if s and idp s
    then fname_:=s
   else 
    <<terpri()$write "Function name must be an identifier!!!"$terpri()>>
   >>
  else if s='na then !*nat:=not !*nat
  else if s='fc then <<
   reclaim()$            % do garbage collection
   terpri()$write known!-free!-space()," free cells"$terpri()
  >>
  else if s='br then <<
    terpri()$write"This is Standard Lisp. Return to Reduce by Ctrl D."$
    terpri()$
    standardlisp()
  >>
  else if s='r then
   <<write "Type in any R-Lisp assignment of the form";terpri()$
     write "LIST('SETQ,'variable_name,value) "$      terpri()$
   promptstring!*:="The expression: "$
   s:=termxread()$
   if pairp s and (car s='SETQ) and idp cadr s  
   then set(cadr s,eval quote reval caddr s)>>$
  promptstring!*:=ps$ 
  >>$
  % Orderings Support!
  return vl . pdes
end$

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
    l:=apply(car p,list(list(car arglist,cadr arglist,
                             caddr arglist,cadddr cdr p)))$
    if not l then l:=arglist$
    return l$
  end$

symbolic procedure subst_derivative(arglist)$
% Substitution of a derivative of a function by an new function
% in all pdes and in forg
begin scalar f,l,q,g,h,pdes,forg$
  pdes:=car arglist$
  forg:=cadr arglist$
  l:=check_subst_df(pdes,forg)$
  for each d in l do
    <<f:=newfct(fname_,fctargs cadr d,nfct_)$
    nfct_:=add1 nfct_$
    ftem_:=reverse fctinsert(f,reverse delete(cadr d,ftem_))$
    if print_ then
      <<terpri()$write "replacing "$
        fctprint1 d$
        write " by "$fctprint list f>>$
    for each s in pdes do dfsubst_update(f,d,s)$
    % integrating f in order to substitute for cadr d
    % in ineq_
    h:=cddr d;
    g:=f;
    while h do <<
      for r:=1:(if (length h =1) or
                   ((length h > 1) and (not fixp cadr h))
                then 1
                else (cadr h) 
               )   do 
      g:=list('PLUS,gensym(),list('INT,g,car h));
      h:=cdr h;
      if h and (fixp car h) then h:=cdr h
    >>;
    % now the substitution in ineq_
    ineq_:=for each s in ineq_ collect reval subst(g,cadr d,s);
    if member(cadr d,forg) then 
       <<q:=mkeq(list('PLUS,d,list('MINUS,f)),
                 list(f,cadr d),fctargs f,allflags_,nil,list(0))$
       remflag1(q,'to_eval)$
       put(q,'not_to_eval,f)$
       pdes:=eqinsert(q,pdes)>>$
    forg:=dfsubst_forg(f,g,cadr d,forg)$
    >>$
  return if l then list(pdes,forg)
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

symbolic procedure subst_level_0(arglist)$
% Substitution of a function by an expression of at most length subst_0
% depending on less variables than the function, 
% not allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_0,pdelimit_0,t,nil,t,nil,nil,nil)$

symbolic procedure subst_level_05(arglist)$
% Substitution of a function by an expression of at most length subst_0
% depending on less variables than the function, 
% not allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_0,pdelimit_0,nil,t,t,nil,nil,nil)$

symbolic procedure subst_level_1(arglist)$
% Substitution of a function by an expression of at most length subst_1
% depending on less variables than the function, 
% allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_1,pdelimit_1,t,nil,nil,nil,nil,nil)$

symbolic procedure subst_level_2(arglist)$
% Substitution of a function by an expression of at most length subst_2
% depending on less variables than the function, 
% allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_2,pdelimit_2,t,nil,nil,nil,nil,nil)$

symbolic procedure subst_level_3(arglist)$
% Substitution of a function by an expression of at most length subst_1
% depending on all variables, 
% allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_3,pdelimit_3,nil,nil,nil,nil,nil,nil)$

symbolic procedure subst_level_33(arglist)$
% Substitution of a function by an expression of at most length subst_2
% depending on all variables, 
% not giving case distinctions, 
% no ftem-dep. coefficient
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_4,pdelimit_4,nil,nil,t,t,nil,nil)$

symbolic procedure subst_level_35(arglist)$
% Substitution of a function by an expression of at most length subst_2
% depending on all variables, 
% not giving case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_4,pdelimit_4,nil,nil,t,nil,nil,nil)$

symbolic procedure subst_level_4(arglist)$
% Substitution of a function by an expression of at most length subst_2
% depending on all variables, 
% allowing case distinctions, 
% ftem-dep. coefficient allowed
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_4,pdelimit_4,nil,nil,nil,nil,nil,nil)$

symbolic procedure subst_level_45(arglist)$
% Substitution of a function by an expression 
% such that the growth of all equations is minimal
% with some penalty for non-linearity increasing substitutions
% no substitutions introducing case distinctions
% no growth of total length of all equations
% good for algebraic problems
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_4,pdelimit_4,nil,nil,t,nil,t,0)$

symbolic procedure subst_level_5(arglist)$
% Substitution of a function by an expression 
% such that the growth of all equations is minimal
% with some penalty for non-linearity increasing substitutions
% and substitutions introducing case distinctions
% good for algebraic problems
 make_subst(car arglist,cadr arglist,caddr arglist,cadddr arglist,
            subst_4,pdelimit_4,nil,nil,nil,nil,t,cost_limit5)$

symbolic procedure factorization(arglist)$
% Factorization of a pde and investigation of the resulting subcases
begin scalar ineq,l$
 ineq:=ineq_$
 if expert_mode then l:=selectpdes(car arglist,1)
                else l:=cadddr arglist$
 return split_and_crack(get_fact_pde(l),
       	     	        car arglist,ineq,cadr arglist,caddr arglist)$
end$

symbolic procedure separation(arglist)$
% Direct separation of a pde
begin scalar p,l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 if (p:=get_separ_pde(l1)) then
    <<l:=separate(p)$
      if l and
         ((length l>1) or
          ((length l = 1) and (car l neq p))) then
         <<pdes:=delete(p,pdes)$ 
           while l do 
              <<pdes:=eqinsert(car l,pdes)$
                l:=cdr l>>$
           l:=list(pdes,forg)>> >>$
 return l$
end$

symbolic procedure alg_solve_system(arglist)$
begin scalar pdes,l1,l2,l3,l4,fl,vl,zd$
 pdes:=car arglist$
 l1:=selectpdes(pdes,nil)$
 for each l2 in l1 do vl:=union(get(l2,'vars),vl);
 for each l2 in l1 do fl:=union(get(l2,'fcts),fl);
 l1:=for each l2 in l1 collect get(l2,'val)$
 write"Please give a list of constants, functions or derivatives"$
 terpri()$
 write"of functions to be solved algebraically, like f,g,df(g,x,2);"$
 terpri()$
 l2:=termxread()$
write"l2=",l2$terpri()$
 if l2 then <<
  l2:=if (pairp l2) and (car l2='!*comma!*) then cdr  l2
                                            else list l2;
  l3:=cdr solveeval list(cons('LIST,l1),cons('LIST,l2));
  % cdr to drop 'LIST

%write"l3=",l3$terpri()$
%algebraic write"l3=",cons('LIST,l3)$
%write"fl=",fl$terpri()$
%write"vl=",vl$terpri()$

  if null l3 then << 
   write"There is no solution."$ 
   terpri()
  >> else
  if length l3 > 1 then <<
   write"can currently not handle 2 solutions"$
   terpri()
  >> else <<
   l3:=for each l4 in l3 collect <<        % for each solution l4
    l4:=for each l5 in cdr l4 collect <<
     zd:=union(zero_den(reval l5,fl,vl),zd)$
     {'PLUS,cadr l5,{'MINUS,caddr l5}}
    >>       % l4 is now a list of expressions to vanish
   >>;
   if length l3 = 1 then << %######### 1 solution - a restriction for now
    l4:=car l3;              % the solution
    for each l5 in l4 do <<
     l5:=mkeq(if zd then cons('TIMES,append(zd,list l5))
                    else l5,
              fl,vl,allflags_,nil,list(0))$
     pdes:=eqinsert(l5,pdes)$
    >>;
    return {pdes,cadr arglist}
   >>
  >> 
 >>
end$

symbolic procedure alg_solve_deriv(arglist)$
% Solving an equation that is algebraic for a function
% or a derivative of a function,
% So far no flag is installed to remember a corresponding
% investigation because the check is quick and done very
% rarely with lowest priority.
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 if (l:=algsolvederiv(l1)) then 
    <<pdes:=delete(car l,pdes)$
      pdes:=eqinsert(cdr l,pdes)$
      to_do_list:=cons(list('factorization,pdes,forg,caddr arglist,list cdr l),
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

symbolic procedure algsolvederiv(l)$
begin scalar d,p$
 while l and null (d:=alg_for_deriv(car l)) do l:=cdr l;
 if d then <<
  p:=cdr d$
  d:=solveeval list(get(car l,'val), 
                    if 1=length car d then caar d 
                                      else cons('DF,car d));
  if d and (car d='LIST) and (length d = p+1) then
  p:=for each el in cdr d collect if car el='EQUAL   then
     reval list('PLUS,cadr el,list('MINUS,caddr el)) else d:=nil
                                              else d:=nil;
  if d then <<
   d:=cons('TIMES,p);
   p:=car l;
   d:=mkeq(d,get(p,'fcts),get(p,'vars),allflags_,nil,get(p,'orderings))$
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
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_int)>>
                else l1:=cadddr arglist$
 if (l:=quick_integrate_one_pde(l1)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in l do 
        to_do_list:=cons(list('subst_level_4,pdes,forg,caddr arglist,list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
 return l$
end$

symbolic procedure full_integration(arglist)$
% Integration of a pde 
% only if then a function can be substituted
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_int)>>
                else l1:=cadddr arglist$
 if (l:=integrate_one_pde(l1,genint_,t)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in cdr l do 
        to_do_list:=cons(list('subst_level_4,pdes,forg,caddr arglist,list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
 return l$
end$

symbolic procedure integration(arglist)$
% Integration of a pde 
begin scalar l,l1,pdes,forg$
 pdes:=car arglist$
 forg:=cadr arglist$
 if expert_mode then <<l1:=selectpdes(pdes,1);flag(l1,'to_int)>>
                else l1:=cadddr arglist$
 if (l:=integrate_one_pde(l1,genint_,nil)) then
    <<pdes:=delete(car l,pdes)$
      for each s in l do pdes:=eqinsert(s,pdes)$
      for each s in cdr l do 
        to_do_list:=cons(list('subst_level_4,pdes,forg,caddr arglist,list s),
                         to_do_list)$
      l:=list(pdes,forg)>>$
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
     <<stem:=cons(get(p,'val),stem)$
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
      ftem_:=reverse ftem_$
      for each f in reverse fnew_ do
        ftem_:=fctinsert(f,ftem_)$
      ftem_:=reverse ftem_$
      ftem:=union(fnew_,ftem)$
      fnew_:=nil$
      pdes:=eqinsert(mkeq(l,smemberl(ftem_,ftem),vl,allflags_,t,list(0)),
                     pdes)$
      vl1:=nil$ 
      l:=list(pdes,forg)>>
  else vl1:=cdr vl1$
 return l$
end$

symbolic procedure length_reduction_2(arglist)$
% Do one length reduction step
begin scalar l$
 l:=dec_one_step(car arglist,ftem_,caddr arglist,t)$ 
 % t --> length must reduce
 if l then l:=list(l,cadr arglist)$
 return l$
end$

symbolic procedure decoupling(arglist)$
% Do one decoupling step
begin scalar l$
 l:=dec_one_step(car arglist,ftem_,caddr arglist,nil)$
 % nil --> length need not reduce
 if l then l:=list(l,cadr arglist)$
 return l$
end$

symbolic procedure clean_up(pdes)$
begin scalar newpdes;
  while pdes do <<
    if flagp(car pdes,'to_drop) then 
    setprop(car pdes,nil)       else 
    newpdes:=cons(car pdes,newpdes);
    pdes:=cdr pdes
  >>;
  return reverse newpdes
end$

symbolic procedure gen_separation(arglist)$
% Indirect separation of a pde
begin scalar p,l,l1,pdes$
 % pdes:=clean_up(car arglist)$
 % if pdes then l:=list(pdes,cadr arglist)$ 
 % because the bookeeping of to_drop is not complete instead:
 pdes:=car arglist$
 % to return the new list of pdes in case gensep is not successful
 if expert_mode then <<
   l1:=selectpdes(pdes,1);
   if get(car l1,'starde) then flag(l1,'to_gensep)
 >>             else l1:=cadddr arglist$
 if (p:=get_gen_separ_pde(l1)) then
    <<l:=gensep(p)$
      pdes:=delete(p,pdes)$
      for each a in l do pdes:=eqinsert(a,pdes)$
      l:=list(pdes,cadr arglist)>>$
 return l$
end$

symbolic procedure add_differentiated_pdes(arglist)$
% all pdes in which the leading derivative of a function of all
% vars occurs nonlinear will be differentited w.r.t all vars and
% the resulting pdes are added to the list of pdes
begin scalar pdes,l,l1,q$
 pdes:=car arglist$
 if expert_mode then l1:=selectpdes(pdes,1)
                else l1:=cadddr arglist$
 for each p in l1 do
  if flagp(p,'to_diff) then
% --------------- it should be differentiated only once
    <<for each f in get(p,'allvarfcts) do
       if (cdr ld_deriv(p,f)>1) then
         <<if print_ then
             <<terpri()$
             write "differentiating ",p," w.r.t. "$
             listprint fctargs f$
             write " we get the new equations : ">>$
         for each v in fctargs f do
           <<q:=mkeq(list('DF,get(p,'val),v),get(p,'fcts),get(p,'vars),
                     delete('to_int,delete('to_diff,allflags_)),t,list(0))$
           prevent_simp(v,p,q)$
           if print_ then write q," "$
           pdes:=eqinsert(q,pdes)>>$
         remflag1(p,'to_diff)$
         l:=cons(pdes,cdr arglist)>>
    >>$
 return l$
end$

symbolic procedure add_diff_star_pdes(arglist)$
% a star-pde is differentiated and then added
begin scalar pdes,l,l1,q$
  pdes:=car arglist$
  if expert_mode then l1:=selectpdes(pdes,1)
                 else l1:=cadddr arglist$
  for each p in l1 do
  if (null l) and flagp(p,'to_diff) and get(p,'starde) then << 
    if print_ then
    <<terpri()$
      write "differentiating ",p," w.r.t. "$
      listprint get(p,'vars)$
      write " we get the new equations : "
    >>$
    for each v in get(p,'vars) do
    <<q:=mkeq(list('DF,get(p,'val),v),get(p,'fcts),get(p,'vars),
              delete('to_int,allflags_),t,get(p,'orderings))$
      if null get(q,'starde) then flag(list q,'to_int)$
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

symbolic procedure split_and_crack(p,pdes,ineq,forg,vl)$
%  for each factor of p CRACKMAIN is called
if p then
begin scalar l,l1,q,contrad,result,n,cop,s$
   n:=0$
   l:=cdr get(p,'val)$                 %  list of factors of p
   contrad:=t$
   if print_ then
      <<terpri()$
      write "factorizing ",p$
      write " we get the alternative equations : "$
      deprint(l)>>$
   for each d in l do
     if not member(d,ineq) and not contradictioncheck(s,pdes)
     then
       <<n:=n+1$
       level_:=cons(n,level_)$
       if print_ then
            <<print_level()$
            terpri()$
            write "CRACK is now called with the assumtion : "$
            deprint(list d)>>$
       q:=mkeq(d,get(p,'fcts),get(p,'vars),allflags_,nil,get(p,'orderings))$
       cop:=backup_pdes(pdes,forg)$
       l1:=crackmain(eqinsert(q,delete(p,pdes)),ineq,forg,vl)$
       pdes:=restore_pdes(cop)$
       if not member(d,ineq) then
        <<ineq:=cons(d,ineq)$
        s:=d>>
       else s:=nil$
       if not contradiction_ then contrad:=nil$ 
       if l1 and not contradiction_ then
          result:=union(l1,result);
       contradiction_:=nil$                           % <--- neu
       >>$
   contradiction_:=contrad$ 
   if contradiction_ then result:=nil$
return if null result then nil
                      else list result
% by returning list result and not just result, what is returned
% is a list with only a single element. This is indicating that the
% content of what is returned from this procedure is a list of
% crackmain returns and not (pdes,forg) which is returned from
% other modules and which is a list of more than one element.
end$

symbolic procedure stop_batch(arglist)$
begin
% !*batch_mode:=nil$
 batchcount_:=stepcounter_ - 2$
 return {car arglist,cadr arglist}  % only to have arglist involved
end$


endmodule$

end$
