%********************************************************************
module shortening$
%********************************************************************
%  Routines for algebraically combining de's to reduce their length
%  Author: Thomas Wolf
%  Jan 1998
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

symbolic procedure alg_length_reduction(arglist)$  
% Do one length-reducing combination of two equations
% If cadddr arglist(=:p) is =pdes or =nil then shorten anyone with anyone
% else shorten only elements (i.e. equations) of cadddr arglist

begin scalar pdes,l,l1,p,cpu,gc$
 cpu:=time()$ gc:=gctime()$
 pdes:=car arglist$

 if expert_mode then <<l:=selectpdes(pdes,2); p:=nil>>
                else <<
  l:=pdes; p:=cadddr arglist;  % which may be nil
  if l eq p then p:=nil;       % then no selective reduction of only one PDE
                               % i.e. shorten any one with any one 
 >>;
 !*rational_bak  := cons(!*rational,!*rational_bak)$   
 if !*rational then algebraic(off rational)$
 if struc_eqn then <<
  while l do <<
   if is_algebraic(car l) then l1:=cons(car l,l1);
   l:=cdr l
  >>$
  l:=reverse l1
 >>$
 if l and cdr l and (l1:=err_catch_short(pdes,l,p)) then
      <<for each a in cdr l1 do pdes:=drop_pde(a,pdes,nil)$
        for each a in car l1 do 
        if a then pdes:=eqinsert(a,pdes)$
        % checking whether a new equation contains a function which occurs
	% only there, then not decoupling this equation anymore:
        for each a in car l1 do 
        if a then dec_fct_check(a,pdes)$
        l:=nil;
        for each a in car l1 do if a then l:=cons(a,l);
        l:=list(pdes,cadr arglist,l)>>
 else l:=nil$

 if print_ and !*time then <<
  write " time : ", time() - cpu,
        " ms    GC time : ", gctime() - gc," ms.      "
 >>$

 if !*rational neq car !*rational_bak then
 if !*rational then algebraic(off rational) else algebraic(on rational)$
 !*rational_bak:= cdr !*rational_bak$ 

 return l$
end$

%-------------------

symbolic procedure err_catch_short(allpdes,pdes,p2)$  
% allpdes is the complete list of pdes as needed in mkeqSQ
% pdes are the ones to be used for shortening
% if p2 neq nil then only p2 shall be reduced else any one in pdes
begin scalar g,h,bak,kernlist!*bak,kord!*bak,mi,newp,p1,bakup_bak,s;

 if t then << % wrap up in an errorset shell
  bak:=max_gc_counter$ max_gc_counter:=my_gc_counter+max_gc_short;
  bakup_bak:=backup_; backup_:='max_gc_short$
  kernlist!*bak:=kernlist!*$
  kord!*bak:=kord!*$
  h:=errorset({'shorten_pdes,mkquote pdes,mkquote p2},nil,nil) 
     where !*protfg=t;                             
  kord!*:=kord!*bak;
  kernlist!*:=kernlist!*bak$
  erfg!*:=nil; 
  backup_:=bakup_bak;
  max_gc_counter:=bak;
  if (errorp h) or (car h=nil) then return nil;    
  h:=car h
 >>   else <<
  h:=shorten_pdes(pdes,p2)$
  if null h then return nil
 >>;

 mi:=car h;   % mi  ={list of 2 used eqns} 
 newp:=cdr h; % newp=({list of new values} . {list of eqns to be dropped})
 p1:=0;
 for each pc in cdr newp do p1:=p1+get(pc,'terms);
 h:=for each pc in car newp collect
    if sqzerop pc then <<nequ_:=add1 nequ_;nil>> 
                  else mkeqSQ(pc,nil,nil,fctsort union(get(car  mi,'fcts),
                                                       get(cadr mi,'fcts)),
                              union(get(car  mi,'vars),
                                    get(cadr mi,'vars)),allflags_,t,list(0),nil,allpdes);
 for each pc in h do if pc then p1:=p1-get(pc,'terms);
 s:=(h . cdr newp);  % = ({list of new eqn names} . {list of eqns to be dropped})

if nil then
 if print_ then <<
  if tr_short then <<
   for each g in cdr newp do <<write g,": "$typeeq g>>$
   for each g in h do if null g then 
   <<write "This gives identity 0=0."$terpri()>>
                                     else
   <<write g,": "$typeeq g>>$
  >>$
  if p1>=0 then write "shortening by ",p1," term" else 
  if p1< 0 then write "increasing by ",-p1," term"$
  if (p1 neq 1) and (p1 neq -1) then write"s"$

  % h is the list of new equations: if there is exactly one eqn then
  if h and car h and null cdr h then <<
   write" to now ",g:=get(car h,'terms)," term"$
   if g neq 1 then write"s"$
   write"."$ terpri()$
  >>                            else
  if null h then <<
   write" to 0=0 ."$ terpri()
  >>

 >>;
 
 if p1>0 then for each pc in cdr newp do drop_pde(pc,nil,nil)
         else for each pc in h do if pc then <<
  % so that no cycle happens and the equation is
  % back length reduced with the same equations
  add_rl_with(car  mi,pc);
  add_rl_with(cadr mi,pc)
 >>$

 return s
end$

%-------------------

symbolic procedure alg_length_reduce_1(arglist)$   
% Do one length-reducing combination of a single equation wrt all others
begin scalar p,q,h,p_to_eval,hcp$ %,cpu,gc$ %,toevalcp
%  cpu:=time()$ gc:=gctime()$
 if !*batch_mode then return nil;
 if print_ or null old_history then <<
  terpri()$
  change_prompt_to ""$ 
  write"All equations:"$terpri()$
  listprint(car arglist)$terpri()$terpri()$
  write"Which equation should be length reduced: "$
 >>$
 p:=termread()$

% if print_ or null old_history then <<
%  write"Specify a list of equations to be used to reduce ",p$terpri()$
%  write"Input `;' to select all equations apart from ",p,": "$
% >>$
% l:=termlistread()$
% if l=nil then l:=car arglist;
% l:=delete(p,l);
% toevalcp:=for each h in l collect (h . flagp(h,'to_eval))$
% for each h in l do remflag1(h,'to_eval)$
 p_to_eval:=flagp(p,'to_eval)$
 flag1(p,'to_eval)$

 % the complete list of pdes is needed in 
 % alg_length_reduction() because mkeqSQ() needs it


 repeat <<
  h:=alg_length_reduction({car arglist,cadr arglist,caddr arglist,p})$

  if h then <<
   q:=setdiff(car h,cons(p,car arglist)); 
   if q then <<arglist:=h; p:=car q>>;
   hcp:=h;
  >>
 >> until null h or freeof(car h,p);
% for each q in toevalcp do if cdr q then flag1(car q,'to_eval)$
 if not p_to_eval and h and not freeof(car h,p) then remflag1(p,'to_eval)$
 restore_interactive_prompt()$ 
 return hcp
end$

%-------------------

symbolic procedure is_algebraic(p)$     
if get(p,'no_derivs) then t else nil$

%-------------------

symbolic procedure shorten_pdes(des,p2)$ 
% uses global variable largest_fully_shortened which is the name of the
% equation furthest in pdes (largest number of terms) that is fully
% simplified wrt. all earlier equations
% returns (mi . output_of_shorten)
if not pairp des or not pairp cdr des then (nil . nil) else
begin scalar p2rl,p,pc,pcc,newp,ineq_pre$ %,p2_to_eval$
 for each p1 in ineq_ do
 if one_termpSF(numr p1) then ineq_pre:=cons(prepsq p1,ineq_pre)$
 if alg_poly then ineq_pre:=sort_according_to(ineq_pre,ftem_)$

 % find the pair of pdes not yet reduced with each other
 % with the lowest product of their number of terms % printlength's
 % mi is a list of 2 integers, composing a rational number which is
 % supposed to be minimal for the 2 equations to be shortened.

 if p2 then <<
  if print_ and tr_short then <<
   write"Trying to shorten the following equation: "$%terpri()
  >>$
  % try only to shorten p2 wrt. to equations with at most twice as many terms.
  p2rl:=2*get(p2,'terms)$
  for each p in des do 
  if (p neq p2) and get(p,'terms)<=p2rl then newp:=cons(p,newp);
  if null newp then return nil;
  des:=reversip newp$
  pcc:={p2}$
  des:=nconc(des,pcc);
  pcc:=cons(1,pcc);
  newp:=nil;
  p2rl:=nil;
 >>    else <<
  if print_ and tr_short then <<
   write"Trying to shorten the following equations: "$%terpri()
  >>$
  pcc:=des;
  if largest_fully_shortened then <<
   while pcc and largest_fully_shortened neq car pcc do pcc:=cdr pcc;
   if null pcc or null cdr pcc then return nil
  >>
 >>$
 if null cdr pcc then return nil;

 repeat <<
  pcc:=cdr pcc$
  p2:=car pcc$
  if print_ and tr_short then write p2,"(",get(p2,'terms),") "$
%  p2_to_eval:=flagp(p2,'to_eval)$
  p2rl:=get(p2,'rl_with)$

  pc:=des;
  while null newp and not(pc eq pcc) do <<
   if (not member(car pc, p2rl))           % and 
      % We do not test (not member(p2,get(car pc,'rl_with))) because both
      % ways of reduction are tested and in add_rl_with() are stored.
   then <<if (backup_='max_gc_short) and (my_gc_counter > max_gc_counter) then
          rederr "Stop in shorten_pdes()."$
          newp:=shorten(car pc,p2,ineq_pre);
          if null newp then <<add_rl_with(car pc,p2);pc:=cdr pc>>
        >>
   else pc:=cdr pc
  >>;
  if null newp then largest_fully_shortened:=car pcc
 >> until newp or null cdr pcc$

 return if newp then ({car pc,p2} . newp)
                else nil
end$

%-------------------

symbolic procedure partition_3(de,AnB,A)$
% l is an equation in SQ-form, 
% returning {(#_of_terms_in_1         . (  1    . inhomog  )),
%            (#_of_terms_in_SFcoeff_1 . (flin_1 . SFcoeff_1)),...}
% where flin_1,.. are in AnB (in A and in B, i.e. intersection of A and B) 
% and the leading term of inhomog must not be in A.
% It is assumed that l in linear on all variables of A.
%
begin scalar l,l1,mv;
 l:=reorder numr get(de,'sqval);
 while l and not domainp l and member(mv:=mvar l,AnB) do <<
  l1:=cons(cons(no_of_tm_sf lc l,cons(mv,lc l)), l1)$
  l:=red l
 >>;
 while l and not domainp l and member(mvar l,A) do l:=red l;  
 return if l then cons(cons(no_of_tm_sf l,cons(1,l)), l1) % inhom case
             else l1                                      % homog case
end$

%-------------------

symbolic procedure setdiff_according_to(a,b,ft)$
% Computes a\b where a and b are subsets of ft and are
% sorted according to ft.
% exception: partial differential equations, when elements of a,b
% include derivatives, then ft is not used and execution is slower 
% which does not matter for fewer functions
begin scalar amb,noft,bcp$
 while a and b do
 if car a eq car b then <<a:=cdr a;b:=cdr b;ft:=cdr ft>> else <<

  if null noft and (pairp car a or pairp car b) then noft:=t;
  if noft then <<
   bcp:=b$   
   while bcp and (car a neq car bcp) do bcp:=cdr bcp;
   if null bcp then amb:=cons(car a,amb);
   a:=cdr a
  >>      else <<
   while car ft neq car a and 
         car ft neq car b do ft:=cdr ft;

   if car ft eq car a then <<
    amb:=cons(car a,amb);
    a:=cdr a
   >>                 else b:=cdr b;
   ft:=cdr ft
  >>
 >>$  
 return 
 if a then nconc(reversip amb,a)
      else reversip amb
end$

%-------------------

symbolic procedure add_fct_kern(de,ineq_pre)$
if alg_poly then 
 if lin_problem then (get(de,'fcts) . nil) % algebraic linear
                else
 if flin_ then begin scalar l,n;           % algebraic partially linear
  l:=get(de,'fct_kern_lin)$
  n:=get(de,'fct_kern_nli)$
  if null l and null n then <<        
   n:=setdiff_according_to(l:=get(de,'fcts),flin_,ftem_);
   l:=setdiff_according_to(l,n,ftem_);                   
   n:=setdiff_according_to(n,ineq_pre,ftem_);             
   put(de,'fct_kern_lin,l);
   put(de,'fct_kern_nli,n)
  >>;
  return (l . n)
 end      else begin scalar n;             % algebraic fully non-linear
  n:=get(de,'fct_kern_nli)$
  if null n then <<
   n:=setdiff_according_to(get(de,'fcts),ineq_pre,ftem_);  
   put(de,'fct_kern_nli,n);
  >>;
  return (nil . n)
 end        
else % not alg_poly
 if lin_problem then begin scalar l,r,s;   % differential linear 
  l:=get(de,'fct_kern_lin);
  if null l then <<
   r:=get(de,'fcts);
   for each s in get(de,'kern) do 
   if not freeoflist(s,r) then l:=cons(s,l);
   put(de,'fct_kern_lin,l);
  >>;
  return (l . nil)
 end            else
 if flin_ then begin scalar l,n,r,s;       % differential partially linear 
  l:=get(de,'fct_kern_lin)$
  n:=get(de,'fct_kern_nli)$
  if null l and  null n then <<
   r:=get(de,'fcts);
   for each s in get(de,'kern) do 
   if not freeoflist(s,r) then
   if not freeoflist(s,flin_) then l:=cons(s,l)
                              else if not member(s,ineq_pre) then n:=cons(s,n);
   put(de,'fct_kern_lin,l);
   put(de,'fct_kern_nli,n)
  >>;
  return (l . n)
 end      else begin scalar n,r,s;         % differential fully non-linear
  n:=get(de,'fct_kern_nli)$
  if null n then <<
   r:=get(de,'fcts);
   for each s in get(de,'kern) do 
   if not freeoflist(s,r) and not member(s,ineq_pre) then n:=cons(s,n);
   put(de,'fct_kern_nli,n)
  >>;
  return (nil . n)
 end$

%-------------------

symbolic procedure shorten(de1,de2,ineq_pre)$
% shorten the two pdes with each other
% returns a dotted pair, where car is a list of the values of new pdes 
% (currently only one) and cdr is a list of names of pdes to be dropped 
% (currently also only one)
begin scalar a,b,r,l1,l2,nl1,nl2,l1ul2,l1ml2,l2ml1,l1il2,oldorder,
      de1p,de2p,termsof1,termsof2,flip,m1,m2,n1,n2,ql,ql1,ql2,maxcancel,
      take_first,tr_short_local,no_factors_x_1,no_factors_x_2,homo,
      changed_korder,DoNotReplace1,DoNotReplace2,tryboth,replace1,bestq;
      % ,max_success; 

 % take_first:=t; 
 % =t is not so radical, --> resulting eqn.s may be longer in total 
 % so the complete crack computation tends to be slower.

 % tr_short_local:=t; 
 if tr_short_local then deprint list({'!*sq,get(de1,'sqval),t},
                                     {'!*sq,get(de2,'sqval),t} )$

 % 15.12.07: The homogeneity test is replaced by the more general concept of
 % strictly linearly occuring functions flin_, so the following is commented out

 if fhom_ and (1=car get(de1,'hom_deg)      ) 
          and (1=car get(de2,'hom_deg)      ) 
 %        and ((cadr get(de1,'hom_deg)) neq 
 %             (cadr get(de2,'hom_deg))     ) % changed when it didn't work
 % for two factorizable equations with same flin_ factor and same degree 
 %non-flin_factors
 then homo:=t;

 % Which equation can be replaced?

 termsof1:=get(de1,'terms)$
 termsof2:=get(de2,'terms)$

 if null flagp(de1,'to_eval) or  
    (homo and (cadr get(de1,'hom_deg)<cadr get(de2,'hom_deg))) or
    (2*termsof1<termsof2) then DoNotReplace1:=t;

 if null flagp(de2,'to_eval) or  
    (homo and (cadr get(de2,'hom_deg)<cadr get(de1,'hom_deg))) or
    (2*termsof2<termsof1) then DoNotReplace2:=t;

 if DoNotReplace1 and DoNotReplace2 then return nil$

 %---- determination of l1,l2 nl1,nl2
 % In the following l1 and l2 are all functions and their derivatives in 
 % de1, resp. de2 which definitely turn up linearly in both equations
 % (maybe there are even more) and which can not be multipliers such that it
 % is possible to partition both equations. This is the case if the problem
 % is linear or in the case of non null flin_ which shall stay linear.
 % nl1, nl2 are the kernels in d1,d2 which do involve ftem_ but not flin_
 % and not ineq_ kernels.

 nl1:=add_fct_kern(de1,ineq_pre)$   l1:=car nl1$   nl1:=cdr nl1$
 nl2:=add_fct_kern(de2,ineq_pre)$   l2:=car nl2$   nl2:=cdr nl2$

 if l1 and l2 then << % fully linear or at least partially linear with flin_

  %---- partitioning both equations into subexpressions
  %     which have a chance to cancel each other
  l1ml2:=setdiff_according_to(l1,l2,ftem_);    % l1 - l2 
  l1il2:=setdiff_according_to(l1,l1ml2,ftem_); % intersection 
  if null l1il2 then return nil$
  l2ml1:=setdiff_according_to(l2,l1,ftem_);    % l2 - l1
  l1ul2:=union(l1,l2);      % union
  
  %---- writing both equations as polynomials in elements of l1ul2
  oldorder:=setkorder append(l1il2,append(l1ml2,l2ml1)); changed_korder:=t$
  de1p:=partition_3(de1,l1il2,l1ml2)$
  de2p:=partition_3(de2,l1il2,l2ml1)$
  setkorder oldorder;

  %---- drop inhomogeneity part if only one equation is inhomogeneous
  if (null de1p) or (null de2p) then return nil;
  if (cadar de1p = 1) and (cadar de2p neq 1) then 
  if null de1p then return nil
               else de1p:=cdr de1p;
  if (cadar de2p = 1) and (cadar de1p neq 1) then 
  if null de2p then return nil 
               else de2p:=cdr de2p;

  % Now comes a stronger restriction: The maximum that can be canceled
  % is sum of the minima of terms of each pair of the de1p,de2p sublists
  % corresponding to the coefficients of different ftem functions/deriv.

  a:=de1p; b:=de2p; n2:=nil;
  while a do <<
   n1:=if (caar a)<(caar b) then caar a else caar b; 
   % n1 is min of terms of the coefficients of the same ftem function/der.
   n2:=cons(2*n1,n2);
   a:=cdr a; b:=cdr b;
  >>$

  % maxcancel is the maximal number of cancellations in all the remaining
  % runs of short() (which of course decreases from run to run).

  maxcancel:=list(0);
  n1:=0;
  while n2 do <<
   n1:=n1+car n2;
   n2:=cdr n2;
   maxcancel:=cons(n1,maxcancel);
  >>;

  if tr_short_local then <<
   write"-----"$terpri()$
   write"flin_=",flin_$terpri()$
   write"flin_\ftem_=",setdiff_according_to(flin_,ftem_,ftem_)$
   write"ftem_\flin_=",setdiff_according_to(ftem_,flin_,ftem_)$
   write"get(de1,'fcts)=",get(de1,'fcts)$terpri()$
   write"get(de2,'fcts)=",get(de2,'fcts)$terpri()$
   write"l1=",l1$terpri()$
   write"nl1=",nl1$terpri()$
   write"l2=",l2$terpri()$
   write"nl2=",nl2$terpri()$
   write"l1ml2=",l1ml2$terpri()$
   write"l2ml1=",l2ml1$terpri()$
   write"l1il2=",l1il2$terpri()$
   write"length de1p=",length de1p$terpri()$
   write"length de2p=",length de2p$terpri()$
   write"de1p=",de1p$terpri()$
   write"de2p=",de2p$terpri()$
   write"---------"$terpri()$
   write"de1:",de1," with ",termsof1," terms"$terpri()$
   a:=de1p;
   while a do <<
    write "caar  a=", caar a;terpri()$ 
    write "cadar a=",cadar a;terpri()$ 
    write "cddar a=",cddar a;terpri()$ 
    write "cddar a="$algebraic write lisp {'!*SQ,(cddar a . 1),t};
    a:=cdr a;    
   >>;terpri()$
   write"de2:",de2," with ",termsof2," terms"$terpri()$
   a:=de2p;
   while a do <<
    write "caar  a=", caar a;terpri()$ 
    write "cadar a=",cadar a;terpri()$ 
    write "cddar a=",cddar a;terpri()$ 
    write "cddar a="$algebraic write lisp {'!*SQ,(cddar a . 1),t};
    a:=cdr a;    
   >>;terpri()$
  >>
 >>          else << % fully non-linear, i.e. at least one equation has no flin_
  de1p:=list cons(termsof1,cons(1,numr get(de1,'sqval)))$
  de2p:=list cons(termsof2,cons(1,numr get(de2,'sqval)))$
  maxcancel:=if termsof1<termsof2 then {2*termsof1,0}
                                  else {2*termsof2,0}
 >>$

 if ((car maxcancel)<termsof1) then if DoNotReplace1 then return nil
                                                     else DoNotReplace2:=t$
 if ((car maxcancel)<termsof2) then if DoNotReplace2 then return nil
                                                     else DoNotReplace1:=t$

 % flip is determined, so that after a flip (if necessary) de2 is replaced,
 % i.e. if n1 is the number of terms of de1 then at least n1 terms must be
 % canceled so that the sum a*de1+b*de2 has not more terms than de2.
 % This would be achieved if at least n1/2 pair-cancellations would occur.

 % Although nl1,2 are not used further below, the use of nconc instead of
 % append let once to a wrong 'fcts and 'fct_kern_nli property of an equation
 if DoNotReplace2 or (termsof2<termsof1) then <<
  flip:=t;
  a:=de1p; de1p:=de2p; de2p:=a;
  no_factors_x_2:=if l1 or null l2 then nl2 
                  else append(nl2,setdiff_according_to(l2,ineq_pre,ftem_));
  no_factors_x_1:=if l2 or null l1 then nl1 
                  else append(nl1,setdiff_according_to(l1,ineq_pre,ftem_));
  n1:=termsof2;
  n2:=termsof1
 >>      else <<
  no_factors_x_1:=if l1 or null l2 then nl2 
                  else append(nl2,setdiff_according_to(l2,ineq_pre,ftem_));
  no_factors_x_2:=if l2 or null l1 then nl1 
                  else append(nl1,setdiff_according_to(l1,ineq_pre,ftem_));
  n1:=termsof1;
  n2:=termsof2
 >>;

 if null DoNotReplace1 and null DoNotReplace2 then tryboth:=t;
% max_success:=if tryboth then if termsof1<termsof2 then 2*termsof1 
%                                                   else 2*termsof2
%                         else 2*termsof1$

 % To allow the generation of new *length increased* equations
 % which have to be *added* and which should not be shortened again
 % (not to get into a cycle) , i.e. 'to_eval=nil, one has to lower 
 % n1 here. n1 is the length of the equation to be kept.
 % n1:=n1-4$

 if length_inc_alg neq 1.0 then <<
  m1:=reval algebraic(ceiling lisp {'QUOTIENT,n1,length_inc_alg});
  m2:=reval algebraic(ceiling lisp {'QUOTIENT,n2,length_inc_alg})
 >>                                    else <<
  m1:=n1;
  m2:=n2
 >>;

 repeat << % one shortening
  b:=short(ql1,ql2,cddar de1p,cddar de2p,m1,m2,2*(caar de1p),
           car maxcancel-cadr maxcancel,cadr maxcancel,%max_success,
           take_first,no_factors_x_1,no_factors_x_2,tryboth)$
  % take_first:=car b; b:=cdr b; % to activate see end of short()
  if b then <<
   ql1:=car b;
   ql2:=cadr b;
   a:=cddr b;
   if a and take_first then <<     % the result
     de1p:=car a;                  % numerator   of a successful quotient
     de2p:=cdr a;                  % denominator of a successful quotient
   >>   else <<                    % the next pairing
     de1p:=cdr de1p;
     de2p:=cdr de2p;
   >>;
   maxcancel:=cdr maxcancel;
  >>   else a:=nil;
 >> until (null b)           or % failure
          (a and take_first) or % early success
          null de1p$            % end of all possible run --> needs check

 if b and (null take_first) then <<
  % search of the best shortening
  % car find..: highest number of saved terms in the quotient list
  % de1p: numerator   of the best quotient so far
  % de2p: denominator of the best quotient so far

  if null ql2 and (null tryboth or null ql1) then <<
   write"##### SOMETHING IS WRONG ###"$terpri()$
   write" short() should have recognized that there is no successful quotient."$
   terpri()
  >>$

%write"ql2="$prettyprint ql2$
%write"ql1="$prettyprint ql1$

  ql2:=find_best_quotient(ql2)$   % works also if ql2=nil
  ql1:=find_best_quotient(ql1)$
  % ql1 and ql2 are now of different structure, see find_best_quotient()

%write"n1=",n1$terpri()$
%write"n2=",n2$terpri()$
%write"flip=",flip$terpri()$
%write"de1=",de1," de2=",de2$terpri()$
%write"car ql1=",car ql1$terpri()$
%write"car ql2=",car ql2$terpri()$
%write"replace1-1 = ",replace1$terpri()$

  if (caar ql1 - n2) >        % at least n2 terms would have to be dropped
     (caar ql2 - n1) then <<  % at least n1 terms would have to be dropped
   replace1:=t$
   ql:=ql1
  >>                else ql:=ql2;           
  bestq:=car ql;
  r:=n1+n2-car bestq;         % the new number of terms
  de1p:=cadr bestq;         
  de2p:=cddr bestq;
  ql:=cdr ql             % remaining multipliers

 >>;
%write"replace1-2 = ",replace1$terpri()$

 return
 if null b or 
    (take_first and null a) then nil else % num and denom are de1p, de2p
% if t then 
<< 
  %--- computing the shorter new equation 
  %    (local variables l1,l2,nl1,nl2,m1,m2 are re-used)
  % nl2 shall be the name and l2 the value of the equation to be replaced
  % nl1 shall be the name and l1 the value of the other equation
  % m1 shal be the sum of rational multipliers to l1
  nl2:=if replace1 then if flip then de2 else de1
                   else if flip then de1 else de2;
%write"nl2=",nl2$
  nl1:=if nl2=de2 then de1 else de2;
  l1:=get(nl1,'sqval);  l2:=get(nl2,'sqval);

  m1:=if nl2=de2 then if flip then (de1p . de2p) else (de2p . de1p)  % m1 is the multiplier to equation nl1
                 else if flip then (de2p . de1p) else (de1p . de2p);
  l2:=subtrsq(l2,multsq(m1,l1));

%%%% TEST:
%if nil then
if null take_first and (r neq (m2:=no_of_tm_sf numr l2)) then <<
 write"##############################################################################"$
 write"Wrong expected length value:"$terpri()$
 write"expected value: r=",r$terpri()$
 write"real no of terms: ",m2$terpri()$
 
 algebraic<<
  off nat$
  write"de1:=",lisp {'!*SQ,get(de1,'sqval),t}$
  write"de2:=",lisp {'!*SQ,get(de2,'sqval),t}$
  write"m1 =",lisp {'!*SQ,m1,t}$
  on nat
 >>;
 write"ql="$terpri()$
 prettyprint ql
>>;

  if take_first then r:=no_of_tm_sf numr l2 
                else 
  while ql do << % r is the current length and ql is a list of further multipliers
   if bestq neq car ql then <<
    m2:=if nl2=de2 then if flip then ((cadar ql) . (cddar ql)) else ((cddar ql) . (cadar ql))
                   else if flip then ((cddar ql) . (cadar ql)) else ((cadar ql) . (cddar ql));
    a:=subtrsq(l2,multsq(m2,l1));
    b:=no_of_tm_sf numr a;
    if b<r then <<l2:=a; r:=b; m1:=addsq(m1,m2)>>
   >>;
   ql:=cdr ql;
  >>$
  if in_cycle({11,stepcounter_,
               get(l1,'printlength),length get(l1,'fcts),numr m1,
               get(l2,'printlength),length get(l2,'fcts),denr m1 }) then <<
   if print_ and tr_short then <<
    write"To avoid a loop, a possible shortening was not performed."$
    terpri()
   >>;
   nil
  >>                                                                else <<
   if print_ then <<
    a:=get(nl2,'terms); b:=a-r;
    if null tr_short then write"Shortening by ",b,if b=1 then " term" else " terms",
                               " to now ",r,if r=1 then " term." else " terms."
                     else <<
     terpri()$
     if r=0 then <<
      write"Equation ",nl2,"(",a,") is deleted as it is a consequence of ",nl1,"(",
            get(nl1,'terms),") :"$
      algebraic(write " 0 = ",lisp {'!*SQ,(numr subtrsq(mksq(nl2,1),multsq(m1,mksq(nl1,1))) . 1),t})

     >>     else <<
      if null car recycle_eqns then m2:=mkid(eqname_,nequ_)
			       else m2:=caar recycle_eqns$
      % m2 is the name of the new equation. The same name will be generated 
      % in err_catch_short() which calls mkeqSQ() which calls new_pde().
      write"Equation ",nl2,"(",a,") is shortened by ",b,if b=1 then " term" else " terms",
	   " using ",nl1,"(",get(nl1,'terms),") ","and ","is ","replaced by:"$
      algebraic(write lisp m2,"(",r,") = ",
                      lisp {'!*SQ,(numr subtrsq(mksq(nl2,1),multsq(m1,mksq(nl1,1))) . 1),t})
     >>
    >>
   >>;
   ({l2} . {nl2})
  >>
 >> 
%  else << 
%  if flip then <<a:=get(de2,'sqval);  b:=get(de1,'sqval)>>
%          else <<a:=get(de1,'sqval);  b:=get(de2,'sqval)>>$
%  if print_ and tr_short then <<
%   if null car recycle_eqns then n1:=mkid(eqname_,nequ_)
%                            else n1:=caar recycle_eqns$
%   algebraic write "The new equation ",n1," = ",
%   lisp {'DIFFERENCE,{'TIMES,!*f2a de2p,if flip then de2 else de1},
%                     {'TIMES,!*f2a de1p,if flip then de1 else de2} },
%   "  replaces  "
%  >>$
%  a:=subtrsq(if de2p=1 then a
%                       else multsq((de2p . 1),a),
%             if de1p=1 then b
%                       else multsq((de1p . 1),b) )$
%
%  if in_cycle(cons(11,cons(stepcounter_,if flip then {
%     get(de2,'printlength),length get(de2,'fcts),de2p,
%     get(de1,'printlength),length get(de1,'fcts),de1p }
%                                                else {
%     get(de1,'printlength),length get(de1,'fcts),de1p,
%     get(de2,'printlength),length get(de2,'fcts),de2p })))
%  then nil
%  else (list a . list(if replace1 then if flip then de2 else de1
%                                  else if flip then de1 else de2))
% >>
end$  % of shorten

%-------------------

symbolic procedure clean_num(qc,j)$
begin
 scalar qc1,nall$
 return
 if 2*(cdaar qc)<=j then t else <<
  qc1:=car qc;  % the representative and list to proportional factors
  nall:=cdar qc1;
  while cdr qc1 do
  if (cdadr qc1)+nall<=j then rplacd(qc1,cddr qc1)
                         else qc1:=cdr qc1;
  if qc1=car qc then t else nil  % whether empty or not after cleaning
 >>
end$     

%--------------------

symbolic procedure clean_den(qc,j)$
begin
 scalar qcc$
 qcc:=qc$
 while cdr qc do
 if clean_num(cdr qc,j) then rplacd(qc,cddr qc)
                        else qc:=cdr qc$
 return null cdr qcc % Are there any numerators left?
end$

%-------------------

symbolic procedure find_best_quotient(ql)$
% - ql is a list of denominator classes: (dcl1 dcl2 dcl3 ...)
%   - each denominator class dcli is a dotted pair (di . nclist) where
%     - di is the denominator and 
%     - nclist is a list of numerator classes.
%       Each numerator class is a list with
%       - first element: (ncl . n) where ncl is the numerator
%         up to a rational numerical factor and n is the number of
%         occurences of ncl (up to a rational numerical factor)      
%       - further elements: (nfi . ni) where nfi is the numerical
%         proportionality factor and ni the number of occurences
%         of this factor
begin scalar %r,
             s,cp,n,m,qlist,bestnu,bestq;
% r:=0;
 bestq:=(0 . (nil . nil));
 while ql do <<
%write"denumerator=",caar ql$terpri()$
  s:=cdar ql;              % the numerator list of the first denominator class
  while s do <<            % for each numerator class
   cp:=car s;   s:=cdr s;  % cp is the first numerator class
   n:=cdar cp;             % n is the sum of occurences of all numerators in this class
%write"numerator=",caar cp$terpri()$
%write"numerator frequency=",n$terpri()$
%for each m in cdr cp do write"num fac=",car m," frequency=",cdr m$terpri()$

   % finding the best numerical factor bestnu in the numerator class
   bestnu:=cdr cp;
%write"bestnu1=",bestnu$terpri()$
   while cdr bestnu do  
   if cdar bestnu <= cdadr bestnu then bestnu:=cdr bestnu
                                  else rplacd(bestnu,cddr bestnu);
%write"bestnu2=",bestnu$terpri()$
   % multiplying 
   % the  numerator of the numerical factor to the  numerator of the quotient and
   % the denomiator of the numerical factor to the denomiator of the quotient 

   m:=n + cdar bestnu;
%write"m=",m$terpri()$
%   qlist:=cons((m .                                                   % saving
%                ((if caaar bestnu=1 then       caar cp
%                                    else multf(caar cp,caaadr cp)) .    % numerator
%                 (if cdaar bestnu=1 then       caar ql
%                                    else multf(caar ql,cdaadr cp))  )), % denominator
%               qlist);

   qlist:=cons((m .                                                   % saving
                ((if caaar bestnu=1 then       caar cp
                                    else multf(caar cp,caaar bestnu)) .    % numerator
                 (if cdaar bestnu=1 then       caar ql
                                    else multf(caar ql,cdaar bestnu))  )), % denominator
               qlist);

%   if m>r then <<r:=m;bestq:=cdar qlist>> 
%write"qlist=",qlist$terpri()$
%write"bestq1=",bestq$terpri()$
   if m>car bestq then bestq:=car qlist
%;write"bestq2=",bestq$terpri()$
  >>;
  ql:=cdr ql
 >>;
%write"r=",r,"  bestq=",bestq$terpri()$
 return (bestq . qlist)
end$

%--------------------

symbolic procedure short(ql1,ql2,d1,d2,n1,n2,n1_now,max_save_now,max_save_later,
                         %max_success,
                         take_first,no_factors_x_1,no_factors_x_2,tryboth)$
 % - ql1,ql2 are lists of quotients so far determined where de1 will be 
 %   multiplied with the denominator of `the' quotient and de2 is multiplied 
 %   with the numerator of that quotient. if tryboth=nil then ql1=nil.
 %   Numerators of ql2 do not depend on no_factors_x_2 so that these quotients
 %   are used to replace de2 and denominators of ql1 do not depend on
 %   no_factors_x_1 so that these quotients are used to replace de1.
 % - d1,d2 are two subexpressions of de1, de2.
 % - The full equations de1,de2 have n1,n2 terms. n1 many must be saved in total
 %   if de2 is to be replaced and n2 many must be saved if de1 is to be replaced.
 % - n1_now is 2 times the number of terms of the input expression d1.
 % - max_save_now is the maximum number of cancellations in this 
 %   run of short() based on 2*min(terms of d1, terms of d2)
 % - max_save_later is the maximal number of terms that could be saved in all
 %   the remaining short() runs under this shorten() call.
 % - if no_factors_x_i <> nil if non-linear equations --> must check that di 
 %                        is not multiplied with a factor from no_factors_x_i
 % - if tryboth=t then try to shorten any one of both equations, else try only
 %                to shorten de2, i.e. the mother of d2.
begin
 scalar LastQSuccess,d2cop,j1,j2,e1,e2,q,dcl,nu,ldcl,lnu,h,repl1,repl2,allowedq
        ,max_coeff_len_reached
%,bynow1,bynow2
%,qisnumber,qcount
; 
 % tr_short_local:=t;
 % - n1_now is the maximum number of terms cancelling each other
 %   in this run of short, based on 2*(number of remaining terms of d1
 %   still to check). Initially n1_now=max_save_now or n1_now>max_save_now
 %   but as the computation goes on, n1_now decreases, so eventually it will
 %   be less than max_save_now.

%n1:=reval n1;
%n2:=reval n2;
 j1:=max_save_later + max_save_now$   
 j2:=n1-j1$                                                    
 j1:=n2-j1$                                                    
 % - The following j2-value is the minimal number of cancellations that 
 %   should already have been found to have a chance to replace de2.
 % - The following j1-value is the minimal number of cancellations that
 %   should already have been found to have a chance to replace de1.
 % - LastQSuccess = t iff the last quotient gives a length reduction.
 %   This is the case if >n1 terms are killed for a deletion of de2 or >n2
 %   terms are killed for a deletion of de1.
%bynow1:=0; bynow2:=0; qcount:=0;
 repeat <<  % for each term e1 of d1
  n1_now:=n1_now-2;                                                   
  e1:=first_term_SF d1; d1:=subtrf(d1,e1);
  %---- divide each term e1 of d1 through all terms e2 of d2 
  d2cop:=d2;
  %---- continue as long as possible and un-successful 
  while d2cop and not(take_first and LastQSuccess) do << % correct version, 3% slower than:
% while d2cop and null LastQSuccess do << % The first quotient which proves to be
                                          % beneficial is nearly always the best
   e2:=first_term_SF d2cop; d2cop:=subtrf(d2cop,e2);
   q:=cancel(e1 ./ e2);         % otherwise already successful

%qcount:=add1 qcount$
%if q neq resimp q then <<
%write"###### q <> q !!!. "$terpri()$
%write"qold=",q$terpri()$
%write"qnew=",resimp quotsq((e1 . 1),(e2 . 1))$terpri()$
%write"qnew=",simp reval {'!*SQ,quotsq((e1 . 1),(e2 . 1)),nil}$terpri()$
%write"re1=",reval {'!*SQ,q,nil}$terpri()$
%write"re2=",reval {'!*SQ,(e1 . 1),(e2 . 1),nil}$terpri()$
%>>$

%if (denr q = 1) and (domainp numr q) then <<
% qisnumber:=t;
% bynow1:=add1 bynow1;
% if 5184 = car q then bynow2:=add1 bynow2;
%>>           else qisnumber:=nil;
%%if qisnumber then write"t " else write "n "$

   %---- Determination of 
   %     ldcl: the numerical factor of the denominator
   %      dcl: the rest of the denominator
   dcl:=cdr q;        % dcl is the denominator of the current quotient
   repl1:=tryboth;
%   if numberp dcl or (pairp dcl and car dcl= '!:GI!:) then <<ldcl:=dcl;dcl:=1>>
   if domainp dcl then <<ldcl:=dcl;dcl:=1>>
                  else <<
    if repl1 and no_factors_x_1 and not freeoflist(dcl,no_factors_x_1) then repl1:=nil;
    h:=dcl;
%    while <<ldcl:=lc h; not(numberp ldcl or car ldcl = '!:GI!:)>> do h:=ldcl;
    while not domainp(ldcl:=lc h) do h:=ldcl;
    rplacd(car h,1)$ % This seems to work reliably, i.e. we do not need here:
    % if ldcl neq 1 then dcl:=numr cancel(dcl ./ ldcl)
   >>;

   %---- Determination of 
   %     lnu: the numerical factor of the numerator
   %      nu: the rest of the numerator
   nu:=car q;         % nu is the numerator of the current quotient
%   if numberp nu or (pairp nu and car nu= '!:GI!:) then <<lnu:=nu;nu:=1;repl2:=t;allowedq:=t>> 
   if domainp nu then <<lnu:=nu;nu:=1;repl2:=t;allowedq:=t>> 
                 else <<
    if no_factors_x_2 and not freeoflist(nu,no_factors_x_2) then <<
     allowedq:=repl1;
     repl2:=nil
    >>                                                      else <<repl2:=t;allowedq:=t>>$
    if allowedq then <<   
     h:=nu;
%     while <<lnu:=lc h; not(numberp lnu or car lnu = '!:GI!:)>> do h:=lnu;
     while not domainp(lnu:=lc h) do h:=lnu;
     % rplacd(car h,1)$ % is not possible as it might change e1 (as it has occured)
     if lnu neq 1 then nu:=numr cancel(nu ./ lnu)
    >>
   >>;

   %---- Do numerical coefficients get too long?
   if allowedq and 
      ((numberp  lnu  and (( lnu>max_coeff_len) or ( lnu<-max_coeff_len))) or
       (pairp  lnu and (car  lnu='!:GI!:) and 
	((cadr  lnu>max_coeff_len) or (cadr  lnu<-max_coeff_len) or
	 (cddr  lnu>max_coeff_len) or (cddr  lnu<-max_coeff_len)    )    ) or
       (numberp ldcl  and ((ldcl>max_coeff_len) or (ldcl<-max_coeff_len))) or
       (pairp ldcl and (car ldcl='!:GI!:) and 
	((cadr ldcl>max_coeff_len) or (cadr ldcl<-max_coeff_len) or
	 (cddr ldcl>max_coeff_len) or (cddr ldcl<-max_coeff_len)    )    )    ) then <<
    if tr_short and null max_coeff_len_reached then <<
     write"### Num. factors grew too large in shortening."$
     terpri()$
%     write"N"
    >>;
    max_coeff_len_reached:=t
   >>                                                                           else

   %---- Record the quotient, check whether it is successful
   if null allowedq then LastQSuccess:=nil
                    else 
   if repl1 and (null repl2 or (n1>n2)) then <<  % to replace de1
%if qisnumber then write"###### wrongly adding to ql1!"$
    h:=add_quotient(ql1,nu,lnu,dcl,ldcl,j1)$
    if car h > n2 then LastQSuccess:=t
                  else LastQSuccess:=nil$
    ql1:=cdr h
   >>                                   else <<  % to replace de1
    h:=add_quotient(ql2,nu,lnu,dcl,ldcl,j2)$
    if car h > n1 then LastQSuccess:=t
                  else LastQSuccess:=nil$
    ql2:=cdr h
   >>

  >>$   % all terms of d2

  % Computing updated values of j1,j2 as n1_now has
  % been lowered and may now be < max_save_now
  if n1_now<max_save_now then <<
   j1:=max_save_later + n1_now;
   j2:=n1-j1$                                                      
   j1:=n2-j1$

   % Deleting quotients that have no chance.
   if j1>0 then ql1:=clean_ql(ql1,j1)$
   if j2>0 then ql2:=clean_ql(ql2,j2)$
  >>$

 >>    % all terms of d1
 until (null d1                             ) or % everything divided
       (take_first and LastQSuccess         ) or % successful: saving > cost 
       (((null tryboth           ) or 
         ((j1 > 0) and (null ql1))    ) and 
        (  j2 > 0) and (null ql2)           )$   % all quotients are too rare 

% write"bynow1=",bynow1,"  bynow2=",bynow2,"  qcount=",qcount$terpri()$

 return
 if ((null tryboth           ) or
     ((j1 > 0) and (null ql1))    ) and
    (  j2 > 0) and (null ql2      )     then nil                 else
 if null d1                             then (ql1 . (ql2 . nil)) else
                                             (ql1 . (ql2 .  q ));
                                                 % take_first and LastQSuccess

end$ % of short

%--------------------

symbolic procedure clean_ql(ql,j)$
begin scalar qc;
 while ql and clean_den(car ql,j) do ql:=cdr ql;                
 if ql then << 
  qc:=ql;
  while cdr qc do 
  if clean_den(cadr qc,j) then rplacd(qc,cddr qc)               
                          else qc:=cdr qc
 >>;
 return ql
end$

%--------------------

symbolic procedure add_quotient(ql,nu,lnu,dcl,ldcl,j)$
% - ql is a list of denominator classes: (dcl1 dcl2 dcl3 ...)
%   - each denominator class dcli is a dotted pair (di . nclist) where
%     - di is the denominator and 
%     - nclist is a list of numerator classes.
%       Each numerator class is a list with
%       - first element: (ncl . n) where ncl is the numerator
%         up to a rational numerical factor and n is the number of
%         occurences of ncl (up to a rational numerical factor)      
%       - further elements: (nfi . ni) where nfi is the numerical
%         proportionality factor and ni the number of occurences
%         of this factor
% - lnu is the numerical factor of the numerator and
%    nu is the rest of the numerator
% - ldcl is the numerical factor of the denominator
%    dcl is the rest of the denominator
% - The j-value is the minimal number of cancellations that should
%   already have been found (including cancellations from this quotient)
%   to have a chance for shortening.
%
% It returns (number_of_saved_terms_by_this_quotient_as_known_so_far . 
%             quotient_list)  

begin scalar nall,m,qc,qq,preqc$

 if null !*complex then <<  % This case handles rational although 
                            % they are not supposed to come up
  if pairp ldcl then <<
   write"####### ldcl=",ldcl," is not an integer!"$ terpri()
  >>$
  if pairp lnu and car lnu neq '!:RN!: then <<
   write"####### lnu=",lnu," is not rational!"$ terpri()
  >>$
  if fixp lnu then qq:=(lnu . ldcl) else 
  % all following under the assumption:  car lnu=!:RN!:
  if ldcl=1 then qq:=cdr lnu 
            else <<m:=cancel (cadr lnu ./ ldcl);
                   qq:=(car m . (cddr lnu * cdr m))>>
 >>                else % ON COMPLEX, lnu and ldcl could both be Gaussian 
                        % integers but without real common integer factor 
                        % --> no need to do cancel( ./ )
 if fixp ldcl then qq:=(lnu . ldcl) 
              else qq:=quotsq((lnu . 1),(ldcl . 1));

%if domainp ldcl and (ldcl neq 1) then <<
%write"***** ldcl=",ldcl," lnu=",lnu$
%algebraic(on rational);
%m:=quotsq((lnu . 1),(ldcl . 1));
%lnu:=numr m;
%ldcl:=denr m; m:=nil;
%write" | ldcl=",ldcl," lnu=",lnu$terpri()$
%>>;

 %---- search for the denominator class
 qc:=ql;    
 while qc and (dcl neq caar qc) do qc:=cdr qc;


 if null qc then    % denominator class not found
 if j <= 0 then <<  % add denominator class
  nall:=2;          % to give a sum of 2        
  ql:=cons((dcl . list(list((nu . 1),(qq . 1)))), ql) 
 >>        else nall:=0 % too late to add this denominator
            else << % denominator class has been found

  %---- now search of the numerator class
  qc:=cdar qc;      % qc is the list of numerator classes nclist 
  while qc and (nu neq caaar qc) do <<preqc:=qc; qc:=cdr qc>>;

  if null qc then   % numerator class not found
  if j <= 0   then << % add numerator class                             %@@@@
   nall:=2;   
   rplacd(preqc,list(list((nu . 1),(qq . 1))) )
  >>          else nall:=0 % too late to add this numerator
             else <<% numerator class found
   nall:=add1 cdaar qc;   % increasing the total number of occur.
   rplacd(caar qc,nall);

   %---- now search for the numerical factor
   qc:=cdar qc;
   while qc and (qq neq caar qc) do <<preqc:=qc;qc:=cdr qc>>;
   if null qc then << % numerical factor not found
    rplacd(preqc,list((qq . 1)));
%;if (nu=1) and (dcl=1) then 
%if nall neq bynow1 or ((lnu=5184) and (bynow2 neq 1)) then <<
%write"&&&&&& bynow1=",bynow1," nall=",nall," bynow2=",bynow2," m=",1," q=",q$terpri()
%>>$
    nall:=add1 nall
   >>         else <<
    m:=add1 cdar qc$ 
    rplacd(car qc,m);
%;if (nu=1) and (dcl=1) then
%if nall neq bynow1 or ((lnu=5184) and (bynow2 neq m)) then <<
%write"&&&&&& bynow1=",bynow1," nall=",nall," bynow2=",bynow2," m=",m," q=",q$terpri()
%>>$
    nall:=nall+m
   >>
  >> % numerator class found 
 >>$ % denominator class found
 return (nall . ql)
end$  % of add_quotient

%--------------------

symbolic procedure drop_lin_dep(arglist)$
% drops linear dependent equations
begin scalar pdes,tr_drop,p,cp,incre,newpdes,m,h,s,r,a,v,
             vli,indp,indli,conli,mli,success$
 % the pdes are assumed to be sorted by the number of terms, 
 % shortest come first
 % vli is the list of all `independent variables' v in this lin. algebra
 %     computation, i.e. a list of all different products of powers of
 %     derivatives of ftem functions and constants
 %     format: ((product1, v1, sum1),(product2, v2, sum2),...)
 %     where sumi is the sum of all terms of all equations multiplied
 %     with the multiplier of that equation
 % indli is a list marking whether equations are necessarily lin
 %     indep. because they involve a `variable' v not encountered yet
 % mli is the list of multipliers of the equations
 pdes:=car arglist$
 % tr_drop:=t$
 if pdes and cdr pdes then <<
  while pdes do <<
   p:=car pdes; pdes:=cdr pdes; newpdes:=cons(p,newpdes);
   m:=gensym()$
   a:=sort_partition(p,nil,get(p,'fcts),nil);
   if tr_drop then <<write "new eqn:"$prettyprint a;
    write"multiplier for this equation: m=",m$terpri()
   >>$
   indp:=nil;
   for each h in a do <<
    s:=car h;
    % Does s occur in vli?
    % Adding the terms multiplied with the multiplier to the corresp. sum
    cp:=vli;
    while cp and (s neq caar cp) do cp:=cdr cp;
    if tr_drop then <<
     write"searched for: s=",s$terpri();
     if cp then write"found: car cp=",car cp$terpri()$
    >>$
    if cp then <<r:=cadar cp;
                 incre:=reval {'QUOTIENT,
                               {'TIMES,m,r,    
                                if cadr h>1 then cons('PLUS,caddr h)
                                            else caaddr h},
                               s};
                 rplaca(cddar cp,cons(incre,caddar cp))
               >>  
          else <<r:=if (pairp s) or (numberp s) then gensym() else s;
                 indp:=s;
                 incre:=reval {'QUOTIENT,
                               {'TIMES,m,r,   
                                if cadr h>1 then cons('PLUS,caddr h)
                                            else caaddr h},
                               s};
                 vli:=cons({s,r,{incre}},vli)
               >>;
    if tr_drop then <<
     write"corresponding symbol: r=",r$terpri()$

     write"upd: incre=",incre$terpri()$
     write"vli="$prettyprint vli
    >>$
   >>; 
   mli:=cons(m,mli);
   indli:=cons(indp,indli)
  >>$

  % Formulating a list of conditions
  while vli do <<
   v:=caddar vli; vli:=cdr vli;
   conli:=cons(if cdr v then cons('PLUS,v)
                        else car v,
               conli)
  >>;

  % Now the investigation of linear independence
  pdes:=nil;  % the new list of lin. indep. PDEs
  while cdr newpdes do <<
   if tr_drop then <<
    terpri()$
    if car indli then write"lin. indep. without search of ",car newpdes,
                           " due to the occurence of ",car indli
                 else write"lin. indep. investigation for ",car newpdes$
   >>; 
   if car indli then pdes:=cons(car newpdes,pdes)
                else <<
    s:=cdr solveeval {cons('LIST,subst(1,car mli,conli)),cons('LIST,cdr mli)};
    if s then <<drop_pde(car newpdes,nil,nil)$  % lin. dep.
                success:=t$
                if print_ then <<
                 terpri()$
                 write"Eqn. ",car newpdes,
                      " has been dropped due to linear dependence."$
                >>
              >>
         else <<pdes:=cons(car newpdes,pdes);   % lin. indep.
                if tr_drop then <<
                 terpri()$
                 write"Eqn. ",car newpdes," is lin. indep."$
                >>
              >>; 
   >>;
   newpdes:=cdr newpdes;
   indli:=cdr indli;
   conli:=subst(0,car mli,conli);
   mli:=cdr mli   
  >>;
  pdes:=cons(car newpdes,pdes)
 >>;
 return if success then list(pdes,cadr arglist)
                   else nil
end$

%--------------------

symbolic procedure find_1_term_eqn(arglist)$
% checks whether a linear combination of the equations can produce
% an equation with only one term
if not lin_problem then nil else
begin scalar pdes,tr_drop,p,cp,incre,m,h,s,r,a,v,
             vli,indp,indli,conli,mli,mpli,success,
             sli,slilen,maxlen,newconli,newpdes,newp,fl,vl$
%tr_drop:=t$
 if tr_drop then terpri()$
 pdes:=car arglist$
 newpdes:=pdes$
%---------------------------------
% if struc_eqn then <<
%  cp:=pdes;
%  while cp do <<
%   if is_algebraic(car cp) then r:=cons(car cp,r)
%                           else s:=cons(car cp,s);
%   cp:=cdr cp
%  >>;
%  r:=nil;
%  s:=nil;
% >>$
% Drop all PDEs which have at least two derivs which no other have
%---------------------------------
 if pdes and cdr pdes then <<
  while pdes do <<
   p:=car pdes; pdes:=cdr pdes;
   m:=gensym()$
   if tr_drop then <<terpri()$write"multiplier m=",m$terpri()>>$
   a:=sort_partition(p,nil,get(p,'fcts),nil);
   for each h in a do <<
    s:=car h;
    % Does s occur in vli?
    % Adding the terms multiplied with the multiplier to the corresp. sum
    cp:=vli;
    while cp and (s neq caar cp) do cp:=cdr cp;
    if tr_drop then <<
     write"searched for: s=",s$terpri();
     if cp then <<write"found: car cp=",car cp$terpri()$>>
    >>$
    if cp then <<r:=cadar cp;
                 incre:=reval {'QUOTIENT,
                               {'TIMES,m,%r,    
                                if cadr h>1 then cons('PLUS,caddr h)
                                            else caaddr h},
                               s};
                 rplaca(cddar cp,cons(incre,caddar cp))
               >>  
          else <<r:=if (pairp s) or (numberp s) then gensym() else s;
                 indp:=s;
                 incre:=reval {'QUOTIENT,
                               {'TIMES,m,%r,   
                                if cadr h>1 then cons('PLUS,caddr h)
                                            else caaddr h},
                               s};
                 vli:=cons({s,r,{incre}},vli)
               >>;
    if tr_drop then <<
     write"corresponding symbol: r=",r$terpri()$

     write"upd: incre=",incre$terpri()$
     write"vli="$prettyprint vli
    >>$
   >>; 
   mli:=cons(m,mli);
   mpli:=cons((m . p),mpli);
   indli:=cons(indp,indli)
  >>$

  % Formulating a list of conditions
  while vli do <<
   sli:=cons(caar vli,sli);
   v:=caddar vli; vli:=cdr vli;
   conli:=cons(if cdr v then cons('PLUS,v)
                        else car v,
               conli)
  >>;

  % Now the investigation of the existence of equations with only one
  % term
  slilen:=length sli;
  mli  :=cons('LIST,  mli);
  conli:=cons('LIST,conli);
  if tr_drop then <<
   write"sli=",sli$terpri()$
   algebraic(write"mli=",mli)$
   algebraic(write"conli=",conli)$
   write"mpli=",mpli$terpri()$
  >>;
  for h:=1:slilen do <<             % for each possible single term
   newp:=car sli;sli:=cdr sli;
   pdes:=newpdes;
   while pdes and 
         ((get(car pdes,'terms)>1) or 
          (not zerop reval {'DIFFERENCE,get(car pdes,'val),newp})) do
   pdes:=cdr pdes;
   if null pdes then <<
    cp:=conli;
    for s:=1:h do cp:=cdr cp;
    rplaca(cp,reval {'PLUS,1,car cp});
    if tr_drop then <<
     write"h=",h$terpri()$
     algebraic(write"new conli=",conli)$
    >>;

    s:=cdr solveeval {conli,mli};
    if (null s) and tr_drop then <<write"no success"$terpri()>>$
    if s then <<                     % found 1-term equation
     if null success then 
     for each p in newpdes do <<
      fl:=union(get(p,'fcts),fl);
      vl:=union(get(p,'vars),vl) 
     >>$
     success:=t$
     maxlen:=0$
     s:=cdar s; % first solution (lin. system), dropping 'LIST

     % now find the equation to be replaced by the 1-term-equation
     % find the non-vanishing m in s, such that the corresponding p in
     % mpli has a maximum number of terms
     while s do <<
      if caddar s neq 0 then <<
       r:=cadar s;
       cp:=mpli; 
       while caar cp neq r do cp:=cdr cp;
       if get(cdar cp,'terms)>maxlen then <<
	p:=cdar cp;              % p will be the equation to be replaced
	m:=r;
	maxlen:=get(p,'terms);
       >>
      >>$
      s:=cdr s
     >>$    

     % Now replacing the old equation p by the new 1-term equation in conli:
     r:=0;
     newconli:=nil$
     while conli do <<
      v:=subst(0,m,car conli)$
      conli:=cdr conli$
      if r=h then <<
       v:=reval {'PLUS,{'TIMES,m,newp},v}$
      >>$
      newconli:=cons(v,newconli);
      r:=add1(r)
     >>$
     conli:=reverse newconli$

     % the new equation:
     newp:=mkeqSQ(nil,nil,newp,fl,vl,allflags_,t,list(0),nil,newpdes);
     % last argument is nil as no new inequalities can result
     % if new equation has only one term
     % --> has been changed as this may change, e.g. ineq_or
     newpdes:=cons(newp,newpdes);
     if print_ then <<
      terpri()$
      write"The new equation ",newp$ typeeq newp$
      write" replaces ",p$           typeeq p$
     >>;
     drop_pde(p,nil,nil)$  
     newpdes:=delete(p,newpdes);

     % update of mpli:
     mpli:=subst(newp,p,mpli)$

     if tr_drop then <<
      write"mpli=",mpli$terpri()$
     >>;

    >>;                        % end of successful find
    cp:=conli;
    for s:=1:h do cp:=cdr cp;
    rplaca(cp,reval {'PLUS,-1,car cp});
   >>                          % if the 1-term PDE is not already known
  >>$                          % for each possible single term

 >>;
 return if success then list(newpdes,cadr arglist)
                   else nil
end$

endmodule$

end$

%-----------------------------------------------------------------------------------
% (although this is after the "end$" I prefer that it is comment not raw text
% so that simple source analysis tools do not get confused. ACN. March 2015)
%
%Possible Improvements:
%
% - auch subtrahieren, wenn 0 Gewinn (Zyklus!)
% - kann Zyklus mit decoupling geben
% - Erweiterung auf mehrere Gleichungen
% - counter example:
%   0 = +a+b+c
%   0 =   -b  +d+e
%   0 =     -c-d  +f
%   0 = -a      -e-f
%   combining any 2 gives a longer one, summing 3 an equally long one and
%   the sum of all 4 is even zero.
% - In order not to run into a cycle with decouple one could use
%   dec_hist_list but that costs memory.
% ---------
%
%    DONE
%    - when a ftem_ function becomes non-zero then drop all equations from the rl_with lists
%      which involve this function
%
%    DONE:
%    - Another problem with allowing some non-zero multipliers and others not:
%      0 =   a +   b +   c +   d + g
%      0 = e*a + e*b + e*c + f*d
%      Here the SHORTER one could and should be replaced by 0 = f*d - e*d - e*g using
%      the longer first one.
%
% - Parallelize the shortening
% - It could be beneficial to produce and ADD new equations if they are short, eg
%   0 = a*g + a*h + b*c \____  b**2*c - a**2*c = c*(a-b)*(a+b) = 0
%   0 = b*g + b*h + a*c /
%   Disadvantage: Checking ALL quotients takes much longer.
% - If a new equation is slightly longer than the one to be replaced (de2) then one
%   could ADD this new equation and mark it as redundant (and check whether it has
%   any useful properties, e.g. factorizability, involving only few ftem_, or being
%   an ODE when de1,de2 were PDEs.
% - perhaps return in shorten() and shorten_pdes() only a single new and to delete PDE,
%   not lists with each only one element
% - One probably could speed up the shortening of homogeneous polynomials
%   if the degree of both polynomials are equal.
%   This would need a modification of partition_3 and inputting all 'fcts as
%   2nd parameter.
% - test adding some extra length allowance to the new generated equation
% - try take_first=t
% - stop when take_first=nil and max_reduction = 2*min(n1,n2) is achieved
%
%    DONE:
%    - When one equation has no flin_ and the other has then treat both as having
%      no flin_.
%
% - How can the knowledge of factors be used for shortening, especially if they
%   have more than one term?
%   E.g. if both equations have common factors, or one is factorizable and the other
%   not, or both are factorizable.
% - Write procedures that plot the size of equations that were shortened over the step number,
%   and `number of terms in all equations' over 'length interval of equations'
% - produce plots for different degrees of overdetermination.
%
% - About rounding:
%   "also im lisp mode macht quotient einfach division ohne rest
%   und Ruecksicht auf Umstehende.Da ist ceiling auch simpel
%   gestrickt.Das macht das LISP system.
%
%   Im Algebraic mode ist das anders. Da machen quotient
%   und ceiling schon mehr.
%
%   Die Wandlung machst Du am einfachsten mit
%
%   simpquot '(quotient 4 5);
%
%   bzw round!* falls Du die nackte float haben willst.
%
%   round!*  '(!:rd!: . 0.8);
%   "
% - The memory to store which equation has already been length reduced wrt to which
%   equation grows quadratically with the number of equations and becomes the more
%   serious the more equations one has. Perhaps one could delete all rl_with entries
%   of all equations coming in the list of equations before largest_fully_shortened.
%   This has the consequence that one has to look up the rl_with information at the
%   larger of both equations. But then, why not just storing this information only
%   for the larger of both equations?
%
%    DONE:
%    - When shortening a single equation wrt all others, then consider also longer equations
%      which are less than 2 times as long as the equation to be shortened.
%
% - Because the order of pairing equations for shortening does depend on the number of terms
%   and the place of the equation in the list pdes of equations, it should be fixed some
%   time that when multi-term factors are dropped and the number of terms of the equation
%   is dropped than they should get a new place in pdes, moving more to the start.
%
% - load trysub22
%then do
%
% s 20 l 11 10 30 30 30 11 11 11 11 11 11 11 11 l 11 10 td 30)
%
%and get:
%
%next: tr_decouple is now on.
%next: 30
%
%Step 41352:
%*** Garbage collection starting
%*** GC 679: 13-Jan-2008 02:09:54 (~ 11358250 ms cpu time, gc : 3 %)
%*** time 1340 ms, 56164584 occupied, 318491626 recovered, 318491666 free
%
%  first pde e_1659:  6 terms, 28 factors, with derivatives
% of functions of all variables:
%
%    3   2       2   7
% (p9 ,p9 ,p9,p24 ,p3 ,p3)
%
%is not differentiated,  second pde e_837:  9 terms, 44 factors, with derivatives
% of functions of all variables:
%
%    3   2       2   8   5   2
% (p9 ,p9 ,p9,p24 ,p3 ,p3 ,p3 )
%
%is not differentiated, to eliminate
%p9
%
%
%e_1659 (resp its derivative) is multiplied with
%***** Non-numeric argument in arithmetic
%
% - A serious problem is that numerical factors may grow too large.
%   Maybe this is unavoidable. One should have a constant for the
%   largest numerical factor so that one can change this easily.
%
% - Is there a bug when equations are shortened by 0 terms?
%   Shall one ignore it, or use it for replacing the previous equation or add it?
%
% - Is it useful to add many short equations in order to reduce larger ones better?
%
% - maybe one should inspect new equations and stop shortening them it they have
%   too long numerical coefficients? That would be better than trying to shorten
%   this equation when there is not a chance anyway?
%
% - Or should one have a counter of how often a quotient is disregarded because of too
%   large numerical coefficients and when this counter gets too large, then stop
%   shortening this equation?
%
% - Larger equations are reduced for a while but then not anymore because their
%   Num factors grow too large. But then they do not shrink and can not become
%   very short to shorten other and/or to provide a breakthrough with very short
%   equations.
%
% - When shortening a single equation, ak how often maximally.
%
%-----------------------------------------------------------------------------------
%alg_length_reduction    % interface to crack
%  err_catch_short       % wrap up
%    mkeqSQ
%    shorten_pdes        % find a pair of equations
%      shorten           % shorten two pdes given by names with each other
%			% returns a dotted pair, where car is a list of the values
%                        % of new pdes (only one) and cdr is a list of names of pdes
%                        % to be dropped (also only one)
%        sort_partition  % in crint.red
%        partition_1
%        partition_2
%        short
%          clean_den(qc,j)$
%            clean_num(qc,j)$
%
%
%
%alg_length_reduce_1  % Do one length-reducing combination of a single equation wrt all others
%
%  alg_length_reduction
%
%is_algebraic % very short test
%
%
%drop_lin_dep(arglist)$       % module 12
%% drops linear dependent equations
%     Calls: drop_pde neq reval solveeval sort_partition !~prettyprint
%
%find_1_term_eqn(arglist)$    % module 13
%% checks whether a linear combination of the equations can produce
%% an equation with only one term
%     Calls: aeval aeval!* assgnpri drop_pde mkeq neq reval
%            solveeval sort_partition typeeq union !~prettyprint
%
%
%tr alg_length_reduction
%tr err_catch_short
%tr mkeqSQ
%tr shorten_pdes
%tr shorten
%tr sort_partition
%tr short
%tr clean_den
%tr clean_num
%
