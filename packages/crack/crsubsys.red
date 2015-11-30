% - new name crsubsys, evtl. die crmain-subsystem procedure mit reinnehmen
% - Massnahmen fuer den Fall 1 ohne flin_ Funktionen anweisen
%********************************************************************
module linalgsys$
%********************************************************************
%  Routines for the memory efficient solution of linear algebraic systems
%  Author: Thomas Wolf
%  December 1998 - ..

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

symbolic fluid '(count_tries tr_subsys max_losof matrix_849)$
lisp(tr_subsys:=nil)$

symbolic procedure add_equ_to_fl(p,fl)$
% add all functions of equation p to the list of functions fl
begin scalar h,cp;
 h:=get(p,'allvarfcts);
 while h do << % update the eqn-list in fl for each function in h
  cp:=fl;
  while cp and (car h neq cadar cp) do cp:=cdr cp;
  if null cp then fl:=cons({1,car h,p},fl) % add car h to fl
             else rplaca(cp,cons(1+caar cp,cons(cadar cp,cons(p,cddar cp))));
  h:=cdr h
 >>;
 return fl
end$

symbolic procedure del_equ_from_fl(p,fl)$
% delete all functions of equation p from fl. This is done by dropping
% those functions where p occurs in the equation list of that function
begin scalar cp;
 cp:=fl;
 while cp do <<
  if not freeof(cddar cp,p) then 
  rplaca(cp,cons(caar cp - 1,cons(cadar cp,delete(p,cddar cp))));
  cp:=cdr cp
 >>;
 return fl
end$

symbolic procedure all_equ_with_any_fl(rsoe,sf)$
% Add all equations from rsoe to nsoe which contain any of the functions sf
begin scalar n,newrsoe,newnsoe;
 n:=0;
 while rsoe do <<
  if freeoflist(get(car rsoe,'allvarfcts),sf) 
  then newrsoe:=cons(car rsoe,newrsoe)
  else <<n:=add1 n;newnsoe:=cons(car rsoe,newnsoe)>>;
  rsoe:=cdr rsoe
 >>;
 return{n,newnsoe,newrsoe}
end$

symbolic procedure err_catch_subsys(pdes)$
begin scalar h,bak,kernlist!*bak,kord!*bak,bakup_bak;
 bak:=max_gc_counter$ max_gc_counter:=my_gc_counter+max_gc_ss;
 kernlist!*bak:=kernlist!*$
 kord!*bak:=kord!*$
 bakup_bak:=backup_;backup_:='max_gc_ss$
 h:=errorset({'show_sub_systems,mkquote pdes},nil,nil)
    where !*protfg=t;
 kernlist!*:=kernlist!*bak$
 kord!*:=kord!*bak;
 erfg!*:=nil; 
 max_gc_counter:=bak;
 backup_:=bakup_bak;
 return if errorp h then nil
                    else car h   
end$

symbolic procedure find_and_use_sub_systems12(arglist)$
fauss1(car arglist,cadr arglist,2)$

symbolic procedure find_and_use_sub_systems13(arglist)$
fauss1(car arglist,cadr arglist,3)$

symbolic procedure find_and_use_sub_systems14(arglist)$
fauss1(car arglist,cadr arglist,4)$

symbolic procedure find_and_use_sub_systems15(arglist)$
fauss1(car arglist,cadr arglist,5)$

symbolic procedure find_and_use_sub_systems22(arglist)$
fauss2(car arglist,cadr arglist,2)$

symbolic procedure find_and_use_sub_systems23(arglist)$
fauss2(car arglist,cadr arglist,3)$

symbolic procedure find_and_use_sub_systems24(arglist)$
fauss2(car arglist,cadr arglist,4)$

symbolic procedure find_and_use_sub_systems25(arglist)$
fauss2(car arglist,cadr arglist,5)$

symbolic procedure determinante(matr)$
begin scalar d$
 d:=aeval list('det, matr)$
 return if pairp d and (car d='!*sq) then cadr d
                                     else simp d
end$

symbolic procedure setzewert(matr,ii,jj,val)$
  setk(list(matr, ii,jj),val)$

symbolic procedure machematrix(matr,idim,jdim)$
  setk(matr,aeval ('mat .(for i:=1:idim collect
             ( for j:=1:jdim collect nil))))$

symbolic procedure fauss1(pdes,forg,ml)$
% find subsystems that do not include any flin_ functions
begin scalar de,odet,n,h$
 max_losof:=ml;

 odet:=spot_over_det(pdes,nil,nil,flin_)$
 if null odet then return nil;
 n:=0;
 write"The following is a list of not underdetermined sub-systems"$
 terpri()$
 for each de in odet do <<  % de = (osoe . osof)
  n:=add1 n;
  write"Sub-system ",n,":"$terpri()$
  plot_dep_matrix(car de,cdr de)$
 >>;

 if null odet then h:=nil
              else repeat <<  % call Groebner Package
  h:=err_catch_groeb({pdes,forg,vl_,caar odet})$
  odet:=cdr odet
 >> until h or null odet$
 return h

end$

symbolic procedure fauss2(pdes,forg,ml)$
% find subsystems using only flin_ functions, one of them non-zero
if flin_ and freeof(last_steps,'sub_sys) then
begin scalar osof,nsof,odet,h,n0flin_,n0flin_cp,ncondi,de,u,v,sysli,sy,
             r,s,some_new,fl1,fl2,f,m,no_of_pdes,sb,ok;
 max_losof:=ml;
 n0flin_:=nil$

 % One wants to find not underdetermined subsystems which include
 % one flin_ function which must not vanish or a set of flin_ functions
 % of which at least one must not vanish. The simplest would be:
 %   for each h in flin_ do
 %   if member(h,ineq_) then n0flin_:=cons(list h,n0flin_);
 % to check for single flin_ functions. What follows is a more general test
 % finding all subsets of flin_ functions (subsets of 1 to m elements) which
 % set to zero would violate one inequality.

 % fl1 is the intersection of ftem_ and flin_ 
 fl1:=setdiff_according_to(ftem_,setdiff_according_to(ftem_,flin_,ftem_),ftem_);

 % In the following it is assumed that all expressions in ineq_ and ineq_or
 % are linear in flin_ functions, i.e. that if such an expression contains
 % k flin_ functions then all k functions are necessary to vanish for this
 % expression to vanish.

 for m:=1:max_losof do << 
  % m is the number of functions in a subset of fl1 of which at least one
  % function must be non-zero

  % at first find an inequality in ineq_ which would be violated
  for each h in ineq_ do <<  
   fl2:=smemberl(fl1,h)$ % fl2 are all fl1-fcts occuring in h
%write"ineq_: h=",h$terpri()$
%write"ineq_: fl2=",fl2$terpri()$
   if length fl2 = m then <<  % if there are m of them in fl2
    n0flin_cp:=n0flin_; 
    while n0flin_cp and 
	  not_included(car n0flin_cp,fl2) do n0flin_cp:=cdr n0flin_cp$
    if null n0flin_cp then << % fl2 does not have a subset of fcts 
			      % already identified
     h:=subsq(h, for each f in fl2 collect (f . 0));
     if sqzerop h then  % setting all fl2-fcts to zero 
				    % violates the identity
     n0flin_:=cons(fl2,n0flin_)
    >>
   >>
  >>$
%write"NOW INEQ_OR"$terpri()$

  % then find an OR-inequality in ineq_or which would be violated
  for each h in ineq_or do <<  % h is one OR-inequality  
%write"ineq_or: h=",h$terpri()$
   fl2:=smemberl(fl1,h)$ % fl2 are all fl1-fcts occuring in h
%write"ineq_or: fl2=",fl2$terpri()$
   if length fl2 = m then <<  % if there are m of them in fl2
    n0flin_cp:=n0flin_; 
    while n0flin_cp and 
	  not_included(car n0flin_cp,fl2) do n0flin_cp:=cdr n0flin_cp$
    if null n0flin_cp then << % fl2 does not have a subset of fcts 
			      % already identified
     sb:=for each f in fl2 collect (f . 0);
     ok:=nil;
     while h do % if u:=car h is non-zero then set ok:=t and h:=nil
                % i.e. at least one of the expressions in h is non-zero
     if <<
      u:=car h;           % u is an expression (i.e. a list of factors)
                          % in the single OR-inequality h. If at least one 
                          % factor is zero then return nil, else t, i.e. 
                          % keep on searching factors until one becomes zero
%write"u=",u$terpri()$
      while u and null sqzerop subsq(car u, sb) do u:=cdr u;
      if u then nil       % the factor car u becomes zero 
           else  t        % no factor becomes zero
     >> then <<ok:=t; h:=nil>>
        else h:=cdr h$

     if null ok then n0flin_:=cons(fl2,n0flin_) % i.e. the OR-inequality
     % car is violated as all its elements become zero, where an
     % element is a list of factors of which at least one becomes zero
    >>
   >>
  >>$

 >>$
%write"n0flin_=",n0flin_$terpri()$

 % Now start of the search of subsystems with all functions from osof
 % and without functions from nsof
 n0flin_cp:=reverse n0flin_; 
 while n0flin_cp do <<
  osof:=car n0flin_cp;
  odet:=spot_over_det(pdes,flin_,osof,nsof)$
  while odet do <<                % for each over-determined system de
   de:=car odet;odet:=cdr odet$   % de = (osoe . osof)
   %plot_dep_matrix(car de,ftem_)$ 
   u:=length car de;              % # of equations in overdet system
   v:=length cdr de;              % # of functions in u
   sysli:=out_off(v,u,car de)$    % a list of all subsets of car de with
                                  % v many equations
   for each sy in sysli do <<     % sy is one of the systems
    if tr_subsys then <<write"sy=",sy$terpri()>>$
    machematrix('matrix_849,v,v);
    for r:=1:v do 
    for s:=1:v do
    setzewert('matrix_849,r,s,
%             coeffn(get(nth(sy,r),'val),nth(cdr de,s),1));
              coeffn({'!*sq,get(nth(sy,r),'sqval),t},nth(cdr de,s),1));
    ncondi:=cons(determinante('matrix_849),ncondi)$
    setk('matrix_849,nil)
   >>
  >>;
  nsof:=append(car n0flin_cp,nsof);
  n0flin_cp:=cdr n0flin_cp
 >>;
 if tr_subsys then <<write"ncondi=",ncondi$ terpri()>>$

 no_of_pdes:=length pdes;
 s:=nil;
 for each h in ncondi do <<
  r:=mkeqsq(h,nil,nil,ftem_,vl_,allflags_,t,list(0),nil,pdes);
  pdes:=eqinsert(r,pdes)$
  s:=cons(r,s)
 >>;
 for each h in s do
 if member(h,pdes) then some_new:=cons(h,some_new);

 if print_ and some_new then <<
  write"New equations due to vanishing coeff. determinants: ",car some_new$
  for each h in cdr some_new do write", ",h
 >>$

 return if some_new or (no_of_pdes neq length pdes) then 
 if in_cycle(<<m:=0;for each r in some_new do m:=m+get(r,'printlength);
               r:=length some_new;
               s:=0;h:=nil;
	       while (s<3) and some_new do <<
		s:=add1 s; 
		h:=cons(get(car some_new,'terms),h);
		some_new:=cdr some_new
	       >>$
	       cons('sub_sys,cons(stepcounter_,cons(r,cons(m,h))))
	     >>) then nil
                 else {pdes,forg} 
                                                    else nil
end$


symbolic procedure show_sub_systems(pdes)$
begin scalar fl,osof,nsof,odet$

  change_prompt_to ""$

  if flin_ and yesp 
  "Shall only functions from the list flin_ be considered?"
  then fl:=flin_$  % assuming they depend on all variables

  if yesp "Are there functions which should appear in the sub-system? "
  then osof:=select_from_list(ftem_,nil)$

  if yesp "Are there functions which should NOT appear in the sub-system? "
  then nsof:=select_from_list(ftem_,nil)$

  if yesp "Is there a maximum of the number of functions in the sub-system? "
  then <<write"What is the maximum? "$max_losof:=termread()>>
  else max_losof:=100000$

  odet:=spot_over_det(pdes,fl,osof,nsof)$

  while odet do <<
   plot_dep_matrix(caar odet,ftem_)$ 
   odet:=cdr odet
  >>$
  restore_interactive_prompt()
end$

symbolic procedure out_off(m,n,l)$
% returns a list of all sublists of l with m elements
% n is the number of elements of l
% m is the number of elements in the return list, m<=n
if m=0 then list nil else
if m=n then list l else 
nconc(out_off(m,n-1,cdr l),
      for each h in out_off(m-1,n-1,cdr l) collect cons(car l,h))$

symbolic procedure spot_over_det(pdes,allf,osof,nsof)$
% find whether there is a subset of pdes which contains in total less
% or equally many allvar-functions than equations
% allf are all the functions to be considered, mostly flin_
% osof are all functions that must appear, like non-zero functions
%     (although only one non-zero function of a linear homogeneous
%      system would be anough to require the coefficient determinant 
%      to vanish)
% nsof (Functions which must not occur, like flin_ if one wants
%       conclusions for the fewer `more valuable' non-flin_ functions
begin scalar p,h,osoe,losoe,nsoe,lnsoe,rsoe,lrsoe,
                 osof,losof,nsof,lnsof,rsof,lrsof$

 if null allf then
 % If not given as parameter then
 % list all functions in all pdes, assumes all functions depend on same var.
 for each p in pdes do allf:=union(get(p,'allvarfcts),allf)$

 % test whether the whole system is not underdetermined
 % if length pdes geq length allf then sysli:=cons({length pdes,pdes},sysli);
 
 lrsoe:=length pdes;
 lrsof:=length allf;

 % assigning osoe, losoe, rsoe, lrsoe, losof, rsof, lrsof
 if osof then <<
  h:=addsoe(pdes,osof,allf)$
  losoe:=car h;
  osoe :=cadr h;
  rsoe:=caddr h;
  lrsoe:=lrsoe-losoe;
  % osof is already known (given)
  losof:=length osof;
  rsof:=setdiff(allf,osof);
  lrsof:=lrsof-losof;
 >>        else <<losoe:=0;osoe:=nil;rsoe:=pdes;losof:=0;rsof:=allf>>$
 
 % assigning nsoe, lnsoe, lnsof, updating the others
 if nsof then <<
  h:=all_equ_with_any_fl(rsoe,nsof)$
  lnsoe:=car h;
  nsoe :=cadr h;
  rsoe :=caddr h;
  lrsoe:=lrsoe-lnsoe;
  % nsof is already known
  lnsof:=length nsof;
  rsof:=setdiff(rsof,nsof);
  lrsof:=lrsof-lnsof
 >>         else <<lnsoe:=0;nsoe:=nil;lnsof:=0>>$

 count_tries:=0;
 return
 try(losoe, osoe,     
     lnsoe, nsoe,    
     lrsoe, rsoe,    
     losof, osof,     
     lnsof, nsof,    
     lrsof, rsof,    
     allf)
end$

symbolic procedure addsoe(rsoe,sf,allf)$
% find all equations from the list rsoe which do not involve other
% allvar-functions than listed in sf
begin scalar n,newsoe,newrsoe$
 n:=0;
 while rsoe do <<
  if not_included(intersection(allf,get(car rsoe,'allvarfcts)),sf) 
  then   newrsoe:=cons(car rsoe,newrsoe)
  else << newsoe:=cons(car rsoe, newsoe); n:=add1 n>>;
  rsoe:=cdr rsoe
 >>;
 return {n,newsoe,newrsoe}
end$

symbolic procedure addnsoe(rsoe,sf)$
% Add all equations from rsoe to nsoe which contain all of the functions sf
begin scalar n,newrsoe,newnsoe$
 n:=0;
 while rsoe do <<
  if not_included(sf,get(car rsoe,'allvarfcts)) 
  then   newrsoe:=cons(car rsoe,newrsoe)
  else <<newnsoe:=cons(car rsoe,newnsoe); n:=add1 n>>;
  rsoe:=cdr rsoe
 >>;
 return {n,newnsoe,newrsoe}
end$

symbolic procedure addsof(rsof,sf)$
% determines the new osof from rsof which are in sf
% returns {number of new osof, new osof, remaining rsof}
begin scalar n,newsof,newrsof;
 n:=0;
 while rsof do <<
  if freeof(sf,car rsof) then newrsof:=cons(car rsof,newrsof)
                         else <<n:=add1 n;newsof:=cons(car rsof,newsof)>>;
  rsof:=cdr rsof
 >>;
 return {n,newsof,newrsof}
end$

symbolic procedure try(losoe,osoe,lnsoe,nsoe,lrsoe,rsoe,
                       losof,osof,lnsof,nsof,lrsof,rsof,allf)$
% osoe, losoe: set of equations to occur, its length
% nsoe, lnsoe: set of equations not to occur, its length
% rsoe, lrsoe: set of equations undecided,its length
% osof, losof: set of functions to occur, its length
% nsof, lnsof: set of functions not to occur,its length
% rsof, lrsof: set of functions undecided, its length

% returns a list of all subsets of equations which are not under-determined

% Principle: It is useful to know about functions which definitly turn
% up which makes losof bigger and equations which do definitely not
% turn up, this makes lnsoe bigger and losoe+lrsoe smaller.

% Failure:
if losof > max_losof then nil else % one could do this line after
                                   % the next one and drop the
                                   % (losof = max_losof) test and get a few more
                                   % free successes but with more functions
% Success:
if osoe and (losoe geq losof) then list(osoe . osof) else
% Failure:
if zerop lrsoe or 
   zerop lrsof or
   (losof = max_losof) or          % because losof>max_losof necessarily later
   (losoe + lrsoe < losof) then nil else

% Undecided:     a choice between two different case distinctions A) and B):

if (lrsof<lrsoe) or
   ((max_losof-losof)<lrsoe) then begin 
 %========== A) decide where the next function car(rsof) is to go
 scalar li,sf,ne;

 count_tries:=count_tries+2;
 if losoe + lrsoe > losof then <<      % A.1): case: car(rsof) goes into osof 
                                       % losoe + lrsoe stays const, losof incr. 
                                       % ==> `>' needed
  if tr_subsys then <<write car(rsof)," goes into osof"$terpri()>>$
  sf:=cons(car rsof,osof);              % the new osof

  %--- Consequence for other equations:
  % All so far undecided equations that contain only sf functions
  % go into osoe as well
  ne:=addsoe(rsoe,sf,allf); 

  %--- Consequence for other functions: ?

  li:=try(losoe+car ne,append(osoe,cadr ne),lnsoe,nsoe,lrsoe-car ne,caddr ne,
          losof+     1,                  sf,lnsof,nsof,lrsof-     1,cdr rsof,
          allf)
 >>;                                   % A.2): case: car(rsof) goes into nsof
				       % not occur in osoe, rsoe may shrink
 if tr_subsys then <<write car(rsof)," goes into nsof"$terpri()>>$

 %--- Consequence for other equations:
 % Add all equations from rsoe to nsoe which contain the function car(rsof)
 ne:=addnsoe(rsoe,list car rsof);     

 %--- Consequence for other functions: ?

 return append(li,
 try(losoe,osoe,lnsoe+car ne,append(nsoe,cadr ne),lrsoe-car ne,caddr ne,
     losof,osof,lnsof+1,cons(car rsof,nsof),lrsof-1,cdr rsof,allf))

end else begin scalar li,sf,ne,nf;
 %========== B) decide where the next equation car(rsoe) is to go

 count_tries:=count_tries+2;
 sf:=setdiff(intersection(allf,get(car rsoe,'allvarfcts)),osof); 
 % all new functions
%########################
 if losoe + lrsoe > losof then <<      % B.1): car(rsoe) goes into nsoe
                                       % losoe, losof stay const, lrsoe shrinks
                                       % ==> `>' needed
  if tr_subsys then <<write car(rsoe)," goes into nsoe:"$terpri()>>$
  %--- Consequence for other equations:
  % All the equations which contain all the functions of car(rsoe) 
  % which are not in osof go into nsoe as well. 
  % Reason: one of the functions of car(rsoe)-sof is
  % the reason for entering nsoe, therefore all equations which have
  % all the functions of car(rsoe)-sof must also enter nsoe.
  ne:=addnsoe(rsoe,sf);   %########################

  %--- Consequence for other functions:
  % At least one of the functions in rsoe is responsible for car(rsoe)
  % going into nsoe and should therefore go itself into nsof. 
  % If there is just one such function then this must be it, otherwise how??
  if (length sf = 1) and freeof(nsof,car sf) then 
  li:=try(losoe,osoe,lnsoe+car ne,append(nsoe,cadr ne),lrsoe-car ne,caddr ne,
          losof,osof,add1 lnsof,cons(car sf,nsof),
          sub1 lrsof,setdiff(rsof,sf),allf)  else
  li:=try(losoe,osoe,lnsoe+car ne,append(nsoe,cadr ne),lrsoe-car ne,caddr ne,
          losof,osof,lnsof,nsof,lrsof,rsof,allf)
 >>;
 if tr_subsys then <<write car(rsoe)," goes into osoe:"$terpri()>>$
                                       % B.2): case: car(rsoe) goes into osoe 
 %--- Consequence for other equations:
 % All equations that do not have other functions than car(rsoe)+sof enter
 % osoe as well
 ne:=addsoe(rsoe,append(sf,osof),allf);   %########################

 %--- Consequence for other functions:
 % All functions which are in rsof that occur in car(rsoe) enter osof
 nf:=addsof(rsof,sf);             

 return append(li,
 try(losoe+car ne,append(osoe,cadr ne),lnsoe,nsoe,lrsoe-car ne,caddr ne,
     losof+car nf,append(osof,cadr nf),lnsof,nsof,lrsof-car nf,caddr nf,allf ))

end$

endmodule$

end$



