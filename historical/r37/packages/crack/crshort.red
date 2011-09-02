%********************************************************************
module shortening$
%********************************************************************
%  Routines for algebraically combining de's to reduce their length
%  Author: Thomas Wolf
%  Jan 1998
%

symbolic procedure length_reduction_1(arglist)$
% Do one length-reducing combination of two equations
begin scalar pdes,l,l1,cpu,gc$
 cpu:=time()$ gc:=gctime()$
 pdes:=car arglist$
 if expert_mode then l:=selectpdes(pdes,2)
                else l:=pdes$
 if (l1:=shorten_pdes(l,caddr arglist)) then
      <<for each a in cdr l1 do pdes:=delete(a,pdes)$                        
        for each a in car l1 do 
        if a then pdes:=eqinsert(a,pdes)$
        for each a in car l1 do 
        if a then dec_fct_check(a,pdes)$
        l:=list(pdes,cadr arglist)>>
 else l:=nil$
 %if print_ and !*time then <<
 % write " time : ", time() - cpu,
 %       " ms    GC time : ", gctime() - gc," ms "
 %>>$
 return l$
end$

%-------------------

symbolic procedure shorten_pdes(des,vl)$
begin scalar mi,h,p1,p1rl,p1le,p2,pc,newp$
 if pairp des and pairp cdr des then <<
  repeat <<
   % find the pair of pdes not yet reduced with each other
   % with the lowest product of their number of terms % printlength's
   mi:=nil;
   pc:=des;
   while cdr pc do <<
    p1:=car pc;pc:=cdr pc;
    if flagp(p1,'to_eval) then <<
     p1rl:=get(p1,'rl_with);
%     p1le:=get(p1,'printlength);
     p1le:=get(p1,'terms);
     for each p2 in pc do
     if flagp(p2,'to_eval) and
        (not member(p2,p1rl)) and
        ((null mi) or
%         (car mi > (p1le*get(p2,'printlength))))
%     then mi:=list(p1le*get(p2,'printlength),p1,p2)
         (car mi > (p1le*get(p2,'terms))))
     then mi:=list(p1le*get(p2,'terms),p1,p2)
    >>
   >>$
   if mi then <<
    newp:=shorten(cadr mi,caddr mi);
    if null newp then add_rl_with(cadr mi,caddr mi);
   >>
  >> until (null mi) or newp; % if not possible then already returned with nil
  if mi then <<
   p1:=0;
%   for each pc in cdr newp do p1:=p1+get(pc,'length);
   for each pc in cdr newp do p1:=p1+get(pc,'terms);
   mi:=(<<h:=for each pc in car newp collect
             if zerop pc then <<nequ_:=add1 nequ_;nil>> else
                mkeq(pc,fctsort union(get(cadr mi,'fcts),
                                      get(caddr mi,'fcts)),
                     vl,allflags_,t);
%          for each pc in h do if pc then p1:=p1-get(pc,'length);
          for each pc in h do if pc then p1:=p1-get(pc,'terms);
          h 
        >> . cdr newp);
   if print_ then <<
    for each h in cdr newp do <<write h," "$typeeq h>>$
    for each h in car mi do if null h then 
    <<write "This gives identity 0=0."$terpri()>>
                                      else
    <<write h," "$typeeq h>>$
    write "Length reduction is ",p1," term"$
    if p1 neq 1 then write"s"
   >>;
   for each pc in cdr newp do setprop(pc,nil);
  >>;
 >>;
 return mi
end$

%-------------------

symbolic procedure partition_1(l,la)$
% l is an equation, 
% returning (l1 . l2) where
% l1=partitioning of equation l into ((lpow1.lc1),(lpow2.lc2),...)
% l2=(lpow1,lpow2,...)
% This works currently only for l that are linear in elem. of la
begin scalar l1,l3;
 l:=reorder !*a2f l;
 while pairp l and member(l3:=car lpow l,la) do <<
  l1:=cons((l3 . !*f2a lc l), l1)$
  l:= red l;  
 >>;
 return if l then (append(l1,list(1 . !*f2a l)) .
                   append(la,list(1))) % inhomogeneous case
             else (l1 . la)            %   homogeneous case
end$

%-------------------

symbolic procedure partition_2(de,l)$
% dropping from de all parts that can not be matched by the other
% equation, a list of ftem-functions and their derivatives from
% the other equation is l
begin scalar newde,dropped,n;
 % dropped is the number of terms that can not be matched and 
 % which are therefore dropped
 dropped:=0$
 while de do <<
  n:=no_of_terms cdar de$
  if member(caar de,l) then newde:=cons(cons(n,car de),newde)
                       else dropped:=dropped+n;
  de:=cdr de
 >>;
 return (dropped . newde)
end$

%-------------------

symbolic procedure strip(d)$
begin
 scalar h;
 d:= if not pairp d then list d else
     if car d='QUOTIENT then cadr d else
     if car d = 'PLUS then cdr d
                      else list(d)$
 return
 for each h in d collect !*a2f h
end$

%-------------------

symbolic procedure shorten(de1,de2)$
% shorten the two pdes with each other
% returns a dotted pair, where car is a list of the values of new pdes
% and cdr is a list of names of pdes to be dropped
begin scalar a,b,l1,l2,l1ul2,l1ml2,l2ml1,l1il2,oldorder,
      de1p,de2p,dropped1,dropped2,termsof1,termsof2,tr_short,
      dne,flip,n1,n2,ql,maxcancel;
%tr_short:=t;
 l1:=for each a in get(de1,'derivs) collect
     if length car a = 1 then caar a else cons('DF,car a)$ % all derivs of de1
 l2:=for each a in get(de2,'derivs) collect
     if length car a = 1 then caar a else cons('DF,car a)$ % all derivs of de2
 de1p:=get(de1,'val)$
 de2p:=get(de2,'val)$
 l1ml2:=setdiff(l1,l2);    % l1 - l2 
 l2ml1:=setdiff(l2,l1);    % l2 - l1
 l1il2:=setdiff(l1,l1ml2); % intersection 
 l1ul2:=union(l1,l2);      % union
 if tr_short then <<
  write"before substitution:"$terpri()$
  write"l1=",l1$ terpri()$
  write"l2=",l2$ terpri()$
  write"de1p=",de1p$terpri()$
  write"de2p=",de2p$terpri()$
  write"l1ml2=",l1ml2$terpri()$
  write"l2ml1=",l2ml1$terpri()$
  write"l1il2=",l1il2$terpri()$
  write"l1ul2=",l1ul2$terpri()$
 >>;

 % substituting derivatives by a new variable to become kernels
 for each a in l1ml2 do if pairp a then <<
  b:=gensym()$ 
  l1:=subst(b,a,l1)$ 
  l1ul2:=subst(b,a,l1ul2)$ 
  de1p:=subst(b,a,de1p)
 >>$
 for each a in l2ml1 do if pairp a then <<
  b:=gensym()$
  l2:=subst(b,a,l2)$ 
  l1ul2:=subst(b,a,l1ul2)$ 
  de2p:=subst(b,a,de2p)
 >>$
 for each a in l1il2 do if pairp a then <<
  b:=gensym()$
  l1:=subst(b,a,l1)$ 
  l2:=subst(b,a,l2)$ 
  l1ul2:=subst(b,a,l1ul2)$ 
  de1p:=subst(b,a,de1p)$
  de2p:=subst(b,a,de2p)
 >>$
 if tr_short then <<
  write"after substitution:"$terpri()$
  write"l1=",l1$ terpri()$
  write"l2=",l2$ terpri()$
  write"de1p=",de1p$terpri()$
  write"de2p=",de2p$terpri()$
  write"l1ml2=",l1ml2$terpri()$
  write"l2ml1=",l2ml1$terpri()$
  write"l1il2=",l1il2$terpri()$
  write"l1ul2=",l1ul2$terpri()$
 >>;

 %--- writing both equations as polynomials in elements of l1ul2
 oldorder:=setkorder l1ul2;
 de1p:=partition_1(de1p,l1); l1:=cdr de1p; de1p:=car de1p;
 de2p:=partition_1(de2p,l2); l2:=cdr de2p; de2p:=car de2p;
 setkorder oldorder;

 %--- l1,l2 can now have the element 1 in case of inhomogeneous de's
 l1ul2:=nil;
 l1il2:=nil;

 %--- Partitioning each equation into 2 parts, one part that can
 %--- be matched by the other equation and one that can not.

 de1p:=partition_2(de1p,l2)$ dropped1:=car de1p; de1p:=cdr de1p;
 de2p:=partition_2(de2p,l1)$ dropped2:=car de2p; de2p:=cdr de2p;

 termsof1:=no_of_terms get(de1,'val)$
 termsof2:=no_of_terms get(de2,'val)$

 if tr_short then <<
  write"---------"$terpri()$
  write"de1:",de1," with ",termsof1," terms"$terpri()$
  write"dropped:",dropped1$terpri()$
  a:=de1p;
  while a do <<
   write "caar =",caar a;terpri()$ 
   write "cadar=",cadar a;terpri()$ 
   write "cddar=", algebraic write lisp cddar a;terpri()$ 
   a:=cdr a;    
  >>;terpri()$
  write"de2:",de2," with ",termsof2," terms"$terpri()$
  write"dropped:",dropped2$terpri()$
  a:=de2p;
  while a do <<
   write "caar =",caar a;terpri()$ 
   write "cadar=",cadar a;terpri()$ 
   write "cddar=",algebraic write lisp cddar a;terpri()$ 
   a:=cdr a;    
  >>;terpri()$
 >>;

 % One can do a stronger restriction:% The maximum that can be 
 % canceled is sum of min of terms ofthe de1p,de2p sublists
 % corresponding to the coefficients of different ftem functions/deriv.

 a:=de1p; b:=de2p; n2:=nil;
 while a do <<
  n1:=if (caar a)<(caar b) then caar a else caar b; 
  % n1 is min of terms of the coefficients of the same ftem function/der.
  n2:=cons(2*n1,n2);
  a:=cdr a; b:=cdr b;
 >>$

 % maxcancel is the maximal number of cancellations in all the
 % remaining runs of short depending on the current run.

 maxcancel:=list(0);
 n1:=0;
 while n2 do <<
  n1:=n1+car n2;
  n2:=cdr n2;
  maxcancel:=cons(n1,maxcancel);
 >>;

 if (null de1p) or (null de2p) or
    (((car maxcancel)<termsof1) and 
     ((car maxcancel)<termsof2)     ) then return nil;
  
 if termsof1<termsof2 then <<
  dne:=dropped1;
  n1:=termsof1;
  n2:=termsof2
 >>                         else <<
  flip:=t;
  a:=de1p; de1p:=de2p; de2p:=a;
  dne:=dropped2;
  n1:=termsof2;
  n2:=termsof1
 >>$

 if n1=1 then <<    % one equation has only a single term
  a:=cadar de1p;    % e.g. g0030
  b:=de2p;
  while b and (cadar b neq a) do b:=cdr b;
  a:=if null b then nil  % that term does not turn up in other equation
               else <<   % it does turn up --> success
    de1p:=cddar de1p;
    de2p:=cddar b;
    t
  >>
 >>      else
 repeat << % one shortening
  if tr_short then <<write"cadar de1p=",cadar de1p$terpri()>>$

  b:=short(ql,strip cddar de1p,strip cddar de2p,n1,
           2*(caar de1p),car maxcancel-cadr maxcancel,cadr maxcancel)$

  if b then <<
   ql:=car b;
   a:=cdr b;
   if a then <<     % the result
     de1p:=!*f2a car a;
     de2p:=!*f2a cdr a;
   >>   else <<
     de1p:=cdr de1p;
     de2p:=cdr de2p;
   >>;
   maxcancel:=cdr maxcancel;
  >>   else a:=nil;
 >> until (null b) or % failure
          a        or % success
          null de1p$  % the case of exact balance
 return
 if null a then nil
           else <<  % numerator and denominator are de1p, de2p

  %--- computing the shorter new equation
  if flip then <<a:=get(de2,'val);  b:=get(de1,'val)>>
          else <<a:=get(de1,'val);  b:=get(de2,'val)>>$
  ql:=if termsof1>termsof2 then de1
                           else de2;
  if print_ then <<
   n1:=mkid(reval eqname_,reval nequ_)$
   algebraic write"The new equation  ",n1," := ",
                  de2p*(if flip then de2 else de1) -
                  de1p*(if flip then de1 else de2),"  replaces  "
  >>$
  a:=reval list('PLUS, 
                list('MINUS,
                     if de1p=1 then b
                               else list('TIMES,de1p,b)),
                if de2p=1 then a
                          else list('TIMES,de2p,a)       )$
  (list a . list(ql))
 >>
end$

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

%--------------------

symbolic procedure short(ql,d1,d2,n1,n1_now,max_save_now,
                         max_save_later)$
begin
 % d1,d2 are two subexpressions of two expressions with n1,n2 terms
 % ql is the list of quotients
 % drp is the number of terms dropped as they can not cancel anything
 % dne is the number terms of d1 already done, including those dropped
 % mi is the minimum of n1,n2
 scalar nall,d1cop,d2cop,m,j,e1,q,qq,qc,dcl,nu,preqc,ldcl,lnu,tr_short,mi$

%tr_short:=t;
 mi:=n1;
 m:=0;
 nall:=0;
 d1cop:=d1;
 % n1_now is the maximum number of terms cancelling each other
 % in this run of short based on 2*(number of remaining terms of d1
 % still to check).
 % max_save_now is the maximum number of cancellations based
 % on 2*min(terms of d1, min terms of d2)
 j:=if n1_now<max_save_now then n1_now
                           else max_save_now$
 % The following j-value is the minimal number of cancellations
 % of a quotient by now in order to lead to a reduction.
 % mi is the minimal umber of cancelled terms at the end = number
 % of terms of the shorter equation.
 % max_save_later is the maximal number of cancelling terms in all
 % later runs of short.
 j:=mi-j-max_save_later$
 repeat <<                             % for each term of d1
  n1_now:=n1_now-2;
  e1:=car d1cop; d1cop:=cdr d1cop;
  d2cop:=d2;
  while d2cop and (nall+m<=n1) do <<   % for each term of d2
   q:=cancel(e1 ./ car d2cop);         % otherwise already successful
   d2cop:=cdr d2cop;
   %--- dropping a numerical factors
   dcl:=cdr q;        % dcl is the denominator of the current quotient
   if numberp dcl then <<ldcl:=dcl;dcl:=1>>
                  else <<
    ldcl:=dcl;
    repeat ldcl:=lc ldcl until numberp ldcl$% or car ldcl = '!:RN!:$
    dcl:=car cancel(dcl ./ ldcl)
   >>;
   nu:=car q;         % nu is the numerator of the current quotient
   if numberp nu then <<lnu:=nu;nu:=1>>
                 else <<
    lnu:=nu;
    repeat lnu:=lc lnu until numberp lnu$% or car ldcl = '!:RN!:$
    nu:=car cancel(nu ./ lnu)
   >>;

   % - ql is a list of denominator classes: (dcl1 dcl2 dcl3 ...)
   % - each denominator class dcli is a dotted pair (di . nclist) where
   %   - di is the denominator and 
   %   - nclist is a list of numerator classes.
   %     Each numerator class is a list with
   %     - first element: (ncl . n) where ncl is the numerator
   %       up to a rational numerical factor and n is the number of
   %       occurences of ncl (up to a rational numerical factor)      
   %     - further elements: (nfi . ni) where nfi is the numerical
   %       proportionality factor and ni the number of occurences
   %       of this factor
   
   %---- search for the denominator class
   qc:=ql;       
   while qc and (dcl neq caar qc) do qc:=cdr qc;

   if null qc then     % denominator class not found
   if j <= 0 then      % add denominator class, here nall,m are not
                       % assigned as it would only play a role if
                       % one equation had only one term but that
                       % is covered as special case
   ql:=cons((dcl . list(list((nu . 1),((lnu . ldcl) . 1)))), ql) 
             else      % too late to add this denominator
              else <<  % denominator class has been found

    %---- now search of the numerator class
    qc:=cdar qc;      % qc is the list of numerator classes nclist 
    while qc and (nu neq caaar qc) do <<preqc:=qc; qc:=cdr qc>>;

    if null qc then   % numerator class not found
    if j leq 0 then % add numerator class
    rplacd(preqc,list(list((nu . 1),((lnu . ldcl) . 1))) )
                 else % too late to add this numerator
               else <<% numerator class found
     nall:=cdaar qc + 1;   % increasing the total number of occur.
     rplacd(caar qc,nall);

     %---- now search for the numerical factor
     qq:=(lnu . ldcl);
     qc:=cdar qc;
     while qc and (qq neq caar qc) do <<preqc:=qc;qc:=cdr qc>>;
     if null qc then << % numerical factor not found
      m:=1;            rplacd(preqc,list((qq . 1)))
     >>         else <<
      m:=add1 cdar qc$ rplacd(car qc,m)
     >>
    >> % numerator class found   
   >>  % denominator class found
  >>$  % all terms of d2
  j:=if n1_now<max_save_now then n1_now
                            else max_save_now$
  j:=mi-j-max_save_later$
  if j>0 then <<
   while ql and clean_den(car ql,j) do ql:=cdr ql;
   if ql then << 
    qc:=ql;
    while cdr qc do 
    if clean_den(cadr qc,j) then rplacd(qc,cddr qc)
                            else qc:=cdr qc
   >>
  >>;
  if tr_short then <<  
   terpri();write length ql," denominators"; 
  >>
 >>    % all terms of d1
 until (null d1cop) or % everything divided
       (nall+m>n1) or % successful: saving > cost 
       ((j > 0) and (null ql))$    
       % all denominators are too rare and are canceled 

 return
 if ((j > 0) and (null ql)) then nil
                            else
 if m+nall<=mi then (ql . nil)
               else (ql . q)
end$ % of short

endmodule$
%tr length_reduction_1$
%tr shorten_pdes$
%tr shorten$
%tr short$
%tr partition_1,partition_2$
end$

% moegliche Verbesserungen:
% - auch subtrahieren, wenn 0 Gewinn (Zyklus!)
% - kann Zyklus mit decoupling geben
% - evtl erst alle Quotienten bestimmen, dann die Heuristik:
%   . erst wo nur die kleinere Gleichung mit ftem-Funktionen multipliziert
%     wird
%   . wo nur die kleinere Gleichung multipliziert wird
%   . alle Quotienten werden auf Hauptnenner gebracht und der mit der
%     groessten Potenz mit der die kuerzere Gleichung multipliziert wird,
%     ist der erste
% - Erweiterung auf nichtlin. Probleme
% - Erweiterung auf mehrere Gleichungen
% - counter example: 
%   0 = +a+b+c        
%   0 =   -b  +d+e
%   0 =     -c-d  +f
%   0 = -a      -e-f
%   combining any 2 gives a longer one
%   the sum of all 4 is even zero.
% - In order not to run into a cycle with decouple one could use
%   dec_hist_list but that costs memory.
