%*********************************************************************
module integration$
%*********************************************************************
%  Routines for integration of pde's
%  Authors: Andreas Brand 1993 1995
%           Thomas Wolf since 1993

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

% $Id$
symbolic procedure ldlist(p,f,vl)$
% provides a reverse list of leading derivatives of f in p, vl is list
% of variables
begin scalar a$
  if not atom p then
  if member(car p,list('expt,'plus,'minus,'times,'quotient,'df,'equal))
  then <<
    if (car p='plus) or (car p='times) or
       (car p='quotient) or (car p='equal) then
    <<p:=cdr p$
      while p do
      <<a:=diffincl(a,ldlist(car p,f,vl))$
        p:=cdr p>>
    >>                                     else
    if car p='minus then a:=ldlist(cadr p,f,vl) else
    if car p='expt         then   % if numberp caddr p then
    a:=ldlist(cadr p,f,vl) else   % fuehrende Abl. aus der Basis
                                  % else a:=nil
    if car p='df then if cadr p=f then
    <<p:=cddr p;
      while vl do
      <<a:=cons(dfdeg(p,car vl),a);
        vl:=cdr vl>>;
      a:=list a
    >>
  >>$
  return a
end$

symbolic procedure diffincl(a,b)$
% a,b are lists of leading derivatives which are to be united
begin
  scalar p;
  while a and b do
  <<a:=ddroplow(a,car b);
    if car a then p:=cons(car a,p);
    a:=cdr a;
    b:=cdr b>>;
  return
  if null a then if p then nconc(p,b)
                      else b
            else if p then a:=nconc(p,a)
                      else a
end$

symbolic procedure ddroplow(a,cb)$
% loescht Elemente von a, von denen cb eine Ableitung ist, loescht cb,
% wenn ein Element von a eine Ableitung von cb ist
begin
  scalar h;
  return
  if null a then list(cb)
            else
  <<h:=compdiffer(car a,cb);
    if numberp(h) then if h>0 then cons(nil,a)        % car a=df(cb,..
                              else ddroplow(cdr a,cb) % cb=df(car a,..
                  else <<h:=ddroplow(cdr a,cb);       % neither
                         cons(car h,cons(car a,cdr h))>>
  >>
end$

symbolic procedure compdiffer(p,q)$
% finds whether p is a derivative of q or q of p or neither
begin
  scalar p!>q,q!>p;
  while p and ((null p!>q) or (null q!>p)) do
  <<if car p>car q then p!>q:=t else  % compare orders of derivatives
    if car p<car q then q!>p:=t;
    p:=cdr p;q:=cdr q
  >>;
  return
  if q!>p then if p!>q then nil     %  neither
                       else 0       %  q is derivative of p
          else if p!>q then 2       %  p is derivative of q
                       else 1       %  p equal q
end$


symbolic procedure ldintersec(a)$
% determines the intersection of derivatives in the list a
begin
  scalar b;
  return
  if null a then nil else
  <<b:=car a;a:=cdr a;
    while a do
    <<b:=isec(b,car a)$
      a:=cdr a
    >>;
    b
  >>
end$


symbolic procedure isec(ca,b)$
% determines the minimum derivatives between ca and b
begin
  scalar newb;
  while ca do
  <<newb:=cons(if car b<car ca then car b else car ca, newb);
    ca:=cdr ca;b:=cdr b
  >>;
  return reverse newb
end$


symbolic procedure disjun(a,b)$
<<while a do
  if (car a neq 0) and (car b neq 0) then a:=nil
                                     else <<a:=cdr a;b:=cdr b>>;
  if b then nil else t
>>$


symbolic procedure ddrophigh(a,cb)$
% loescht Elemente von a, die Ableitung von cb sind,
% loescht cb, wenn cb Ableitung eines Elements von a ist oder =a ist,
% haengt cb ansonsten an
begin
  scalar h;
  return
  if null a then list(cb)
            else
  <<h:=compdiffer(car a,cb);
    if numberp(h) then if h<2 then a         % cb is deriv or = car a
                              else ddrophigh(cdr a,cb) % car a=df(cb,..
                  else cons(car a,ddrophigh(cdr a,cb)) % neither
  >>
end$


symbolic procedure elibar(l1,l2,lds)$
begin
  scalar found1,found2,h;
  % found1=t if an LD=l1 is found, found2=t if contradiction found
  while lds and (not found2) do
  <<if car lds=l1 then found1:=t else
    <<h:=compdiffer(l2,car lds);
      if (null h) or (h = 2) then found2:=t
    >>;
    lds:=cdr lds
  >>;
  return found1 and (not found2)
end$

symbolic procedure intminderiv(p,ftem,vlrev,maxvanz,nfsub)$
% yields a list {nv1,nv2, ... } such that nvi is the minimum
% of the highest derivatives w.r.t. vi of all the leading derivatives
% of all functions of ftem which are functions of all maxvanz variables.
% Only those are kept for which nvi>0.
% further a list ((f1 ld's of f1) (f2 ld's of f2)...),
begin scalar l,a,listoflds$
  while ftem do
  <<if (maxvanz=(fctlength car ftem)) or (nfsub=0) then
    <<l:=ldlist(p,car ftem,vlrev);
      listoflds:=cons(cons(car ftem,l),listoflds)$
      a:=if a then ldintersec(cons(a,l))
              else ldintersec(l)
    >>$
    ftem:=cdr ftem
  >>$
  return list(a,listoflds)
end$


symbolic procedure potintegrable(listoflds)$
begin
  scalar h,l1,l2,f,n,lds,f1,f2$
  if tr_genint then write "Does a potential exist?"$
  %------- Determining 2 minimal sets of integration variables
  % There must be two disjunct LDs such that all others are in their
  % ideal. This is necessary if we want to eliminate 2 functions.
  h:=listoflds;
  l1:=nil;
  while h do
  <<l2:=cdar h; % the list of LDs for the function caar h
    while l2 do
    <<l1:=ddrophigh(l1,car l2)$
      l2:=cdr l2>>;
    h:=cdr h
  >>;
  return
  if length l1 neq 2 then nil else
  if not disjun(car l1,cadr l1) then nil else
  % if there would be an overlap between l1 and l2 then it would have
  % to be integrated for elimination but it cannot --> no overlap
  % possible
  <<% selecting interesting functions for which one LD is = l1 and all
    % others are derivatives of l2 or equal l2 and vice versa. Two
    % necessary (one with an LD=l1 and one with an LD=l2) from which at
    % least one function (f) has no further LD.
    % Exception: 2 functions with each 2 LDs equal to (l1,l2) (these
    % functions are counted by n)
    l2:=cadr l1;l1:=car l1;
    f:=nil;f1:=nil;f2:=nil;n:=0;
    h:=listoflds;
    while h and ((not f1) or (not f2) or ((not f) and (n neq 2))) do
    <<lds:=cdar h;
      if (not f1) or (not f) then
      if elibar(l1,l2,lds) then
      <<f1:=cons(caar h,f1);
        if length lds = 1 then f:=caar h else
        if length lds = 2 then
        if (car lds = l2) or (cadr lds = l2) then n:=n+1
      >>;
      if (not f2) or (not f) then
      if elibar(l2,l1,lds) then
      <<f2:=cons(caar h,f2);
        if length lds = 1 then f:=caar h
      >>;
      h:=cdr h
    >>;
    if f1 and ((n>1) or (f2 and f)) then list(l1,l2)
                                    else nil
  >>
end$ % of potintegrable

symbolic procedure vlofintlist(vl,intlist)$
% provides a list of elements of vl for which the corresponding
% elements of intlist are non-zero
begin scalar a;
  while intlist do
  <<if (car intlist) and (not zerop car intlist) then a:=cons(car vl,a);
    vl:=cdr vl;
    intlist:=cdr intlist
  >>;
  return a
end$

symbolic procedure vlofintfaclist(vl,intfaclist)$
% determining the list of all variables of vl in intfaclist
begin scalar e1,a;
  for each e1 in vl do
  if not my_freeof(intfaclist,e1) then a:=cons(e1,a);
  return a
end$

symbolic procedure multipleint(intvar,ftem,q,vari,vl,genflag,
                               potflag,partial,doneintvar)$
% multiple integration of q wrt. variables in vl, max. number of
% integrations specified by intvar
% integrating factors must not depend on doneintvar, doneintvar is
% a list of integration variables so far
% partial=t then as much as possible of an expression is integrated
% even if there is a remainder
begin
  scalar pri,vlcop,v,nmax,geni,intlist,iflag,n,nges,newcond,
         intfaclist,ph,pih,qh,qih,intfacdepnew,intfacdep$
  % intfacdep is a list of variables on which factors of integration
  % depend so far, other than the integration variable in their
  % integration --> no integration wrt. these variables by potint
  % because there the diff. operators wrt. to different variables 
  % need not commute because the integrations are not done

  % pri:=t$  
  if (not vari) and (zerop q) then return nil;
  nges:=0;
  vlcop:=vl;
  pih:=t;

  % Splitting of the equation into the homogeneous and inhomogeneous
  % part which is of advantage for finding integrating factors
  q:=splitinhom(q,ftem,vl)$
  qh:=car q; qih:=cdr q; q:=nil;
  
  while (vari or vlcop) and (pih or (not potflag)) do
  %------- if for potflag=t one variable can not be integrated the
  %------- maximal number of times (nmax) then immediate stop because
  %------- then no elimination of two functions will be possible
  << %-- The next integration variable: v, no of integrations: nmax
    if vari then <<v:=vari;nmax:=1>>
            else <<v:=car vlcop;     vlcop:=cdr vlcop;
                   nmax:=car intvar; intvar:=cdr intvar>>;

    if zerop nmax then intlist:=cons(nil,intlist)
                  else
    <<if pri then write"anf: intvar=",intvar," vari=",vari," q=",q,
                       " v =",v," vl =",vl$
      if vari and (not member(v,vl)) then
      <<%qh :=reval list('INT,qh,v)$
        qh :=err_catch_int(qh,v)$          % changed 23.1.08
        if null qh then iflag:=nil else    % changed 23.1.08
        if freeof(qh,'int) then <<
          %qih:=reval list('INT,qih,v)$
          qih:=err_catch_int(qih,v)$       % changed 23.1.08        
          iflag:=if null qih then nil else % changed 23.1.08        
                 if freeint_ and 
                    (null freeof(qih,'int)) then nil else
                 if freeabs_ and 
                    (null freeof(qih,'abs)) then nil else <<
                   intlist:=cons(list(1),intlist)$
                   'success>>$
          if pri then <<write"232323 qh=",qh;terpri();
                        write"qih=",qih;terpri()>> 
        >>
      >>                             else
      <<n:=0$
        if pri then write"333"$
        intfaclist:=nil; %-- the list of integr. factors in v-integr.
        if potflag or my_freeof(intfacdep,v) then
        % otherwise v-integration not allowed because one integrating
        % factor already depends on v
        % for potflag=t this `commutativity'-demand plays no role
        repeat << %--- max nmax integrations of qh and qih wrt. v
          if pri then <<write"444  vor intpde:"$eqprint q$terpri()$
                        write"potflag=",potflag," v=",v,
                        "  ftem=",ftem>>$
          % At first trying a direct integration of the homog. part qh
          ph:=intpde(qh,ftem,vl,v,partial)$  % faster if potflag=nil
          if pri then <<write"nach intpde(qh):"$deprint ph>>$

          %------ At first the integration of the homogeneous part
          intfacdepnew:=intfacdep;
          if ph and (partial or (zerop cadr ph)) then <<
            %---- For the homogen. part cadr ph must be zero
            intfaclist:=cons(1,intfaclist);
            ph:=car ph;
            if pri then <<write"565656 ph=",ph;terpri()>>;
          >>                                     else
          if vari then ph:=nil
                  else
          if facint_ then <<
            ph:=findintfac(list(qh),ftem,vl,v,doneintvar,intfacdep,
                           not zerop n,not potflag); 
            % factorize before ivestig., no report of int. factors
            if ph then << %--- Complete integr. of qh was possible
              if pri then <<write"of the homogeneous part"$terpri()>>$
              %--- update the list of variables on which all integr.
              %--- factors depend apart from the integration variable
              intfacdepnew:=caddr ph;
              %--- extend the list of integrating factors, cadr ph
              %--- is a list of integr. factors, here only one
              intfaclist:=cons(caadr ph,intfaclist);
              %--- multiply the inhomogeneous part with integ. factor
              qih:=reval reval reval list('times,car intfaclist,qih);
              if pri then <<write"454545 qih=",qih;terpri()>>;
              ph:=car ph  % the integral of qh
            >>
          >>;

          %------ Now the integration of the inhomogeneous part
          if not ph then pih:=nil %--- no integration possible
                    else <<
            if zerop qih then pih:=list(0,0) else
            pih:=intpde(qih,ftem,vl,v,t)$ % partial set =t on 14.6.04 
                           % to generalize integrate for inhom. terms
            if print_ and null pih then <<
              terpri()$
              write"Inhomogeneous part: "$
%              mathprint qih$ %@!@!@!@!
              type_pre_ex qih$
              write"can not be integrated explicitly wrt. ",v$
            >>$
            if pri then <<write"nach intpde(qih):",pih$terpri()$
                          write"genflag=",genflag$terpri()>>$
            if pih then
            if zerop cadr pih then
            <<qih:=car pih$n:=add1 n$iflag:='success$
              if pri then write" success "$
            >>
                              else if not genflag then pih:=nil
                                                  else
            <<if pri then write"555"$
              geni:=partint(cadr pih,smemberl(ftem,cadr pih),
                            vl,v,genflag)$
              if geni then 
              <<qih:=reval list('plus,car pih,car geni)$
                n:=add1 n$
                ftem:=union(fnew_,ftem)$
                newcond:=append(cdr geni,newcond)$  % additional de's
                if pri then
                <<terpri()$write"nach gen newcond:",newcond>>$
                iflag:='genint
              >>                       else
              if partial then qih:=car pih
                         else pih:=nil
            >>;
            if pih then <<
              if pri then write"AAA"$
               qh:=ph;
              if (not potflag) and (n neq 1) then
              intfacdep:=intfacdepnew
              %-The first integr. factor of all v-integrations does not
              % depend on any earlier integration variables and can
              % therefore be taken out of all integrals --> no incease
              % of intfacdep for n=1.
              %-For potential integration the integration variables and
              % extra-dependencies-variables of integr. factors need not
              % be disjunct therefore the intfacdep-update only for
              % not-potflag
            >>     else <<
              if pri then write"BBB"$
              % inhomogeneous part can not be integrated therefore
              % reversing the succesful integration of the hom. part
              if car intfaclist neq 1 then
              qih:=reval list('quotient,qih,car intfaclist);
              intfaclist:=cdr intfaclist
            >>;
          >>; %-- end of the integration of the inhomog. part
          if pri then write"n=",n," nmax=",nmax," not pih=",not pih$
        >> until (n=nmax) or (not pih)$ %---- end of v-integration
        %------- variables of done integrations are collected for
        %------- determining integrating factors in later integr.
        if not zerop n then doneintvar:=cons(v,doneintvar)$
        nges:=nges+n;
        intlist:=cons(intfaclist,intlist)
      >>$  % of    not ( vari and (not member(v,vl)))
      if vari then <<vari:=nil;vlcop:=nil>>;
      if pri then write"ende: intvar=",intvar," vari=",vari,
      "    qh=",qh,"   qih=",qih$
    >> % of (nmax neq zero)
  >>$  % of ( while (vari or vlcop) and (pih or (not potflag)) )

  % intlist and its elements intfaclist are in the inverse order
  % to vl and the sequence of integrations done
  q:=reval list('plus,qh,qih)$ %--- adding homog. and inhomog. part
  if pri then <<terpri()$write"\\\  newcond:"$deprint newcond;
    write"multiple result:",if null iflag then nil
    else list(q,intlist,newcond,nges)
  >>;
  return if null iflag then nil
                       else list(q,intlist,newcond,nges)
end$  % of multipleint

symbolic procedure uplistoflds(intlist,listoflds)$
begin
  scalar f,h1,h2,h3,h4,lds,itl;
  while listoflds do
  <<f:=caar listoflds;
    lds:=cdar listoflds;
    listoflds:=cdr listoflds;
    h2:=nil;            % h2 becomes the new list of lds of f
    while lds do
    <<h3:=car lds; lds:=cdr lds;
      itl:=intlist;
      h4:=nil;          % h4 becomes one new ld of f
      while h3 do
      <<h4:=cons(car h3 - if null car itl then 0
                                          else length car itl, h4);
        h3:=cdr h3;itl:=cdr itl
      >>;
      h2:=cons(reverse h4,h2)
    >>;
    h1:=cons(cons(f,h2),h1)
  >>;
  return h1  % updated listoflds
end$ % of uplistoflds

symbolic procedure ProportionalityConditions(ex,fl,x)$
% This procedure collects cases that lead to at least
% two coefficients of two elements of fl in ex being
% proportional to each other by an x-independent multiplier.
if fl then
begin scalar flo,f1,f2,flc,s1,s2,c1,condi$
 flo:=fl$
 while cdr fl do <<
  f1:=car fl; fl:=cdr fl;
  s1:=coeffn(ex,f1,1)$
  if not zerop s1 then <<
   flc:=fl;
   while flc do <<
    f2:=car flc; flc:=cdr flc;
    s2:=coeffn(ex,f2,1)$
    if not zerop s2 then <<

     % condition for checking a special case:
     c1:=reval {'df,{'quotient,s1,s2},x};
     c1:=simplifySQ(simp c1,ftem_,t,nil,t)$
     if (c1 neq {(1 . 1)}) and (not freeoflist(c1,ftem_)) then
     condi:=union(c1,condi)
    >>
   >>
  >>
 >>$
 return condi
end$

symbolic procedure addintco(q, ftem, ifac, vl, vari)$
begin scalar v,f,l,vl1,j,ftemcp,fnewcp;
  % multi.ing factors to the constants/functions of integration
  ftemcp:=ftem; 
  if zerop q then l:=1
             else
  <<ftem:=fctsort ftem$
    while ftem do
    if fctlength car ftem<length vl then ftem:=nil
                                    else if fctlinear(q,f)          then
                                         <<f:=car ftem$ ftem:=nil>> else
                                         ftem:=cdr ftem$
    if f then
    <<l:=lderiv(q,f,fctargs f)$
      l:=reval coeffn(q,reval car l,cdr l)$
      % l is a coeffient of the leading derivative. By multiplying to the
      % constant(function) of integration, the factor will dissappear when
      % a substitution will be made. This may be dangerous because it
      % may hide the case when the factor becomes zero (although no division
      % may be performed through a factor which might become zero). But even
      % when no division is performed then the constant of integration may
      % dissappear when this factor becomes zero and thus solutions be lost.
      % Therefore:
      if not freeoflist(l,ftem) then l:=1
    >>   else l:=1
  >>;
  % the constants and functions of integration
  if vari then q:=list('plus,q,intconst(l,vl,vari,list(1)))
  % The coefficient is 1 so no testing of case splitting due to
  % specific parameter values is done.
          else
  <<vl1:=vl;
    while vl1 and null j do      % j = list of case distinctions to do
    <<v:=car vl1; vl1:=cdr vl1;
      fnewcp:=fnew_;
      if car ifac then 
      q:=list('plus,q,intconst(l,vl,v,car ifac))$
      % l..product of factors in the coefficient of the function to be
      % eliminated, car ifac .. list of integrating factors

      % All integrations wrt. v are done and now the independence of special
      % solutions and the absence of singularities has to be tested. Both
      % would give rise to more case distinctions.
      % singularity check:
      j:=zero_den(q,ftemcp); 
      % proportionality check:
      if null j then j:=ProportionalityConditions(q,setdiff(fnew_,fnewcp),v)$

      ifac:=cdr ifac; 
    >>
  >>$

  return 
  if null j then reval q
            else <<      % case distinctions need to be made
   if freeoflist(j,fnew_) then
   % Otherwise conditions contain new constants of integration which
   % are not known later after the integration module is left
   % (see 30.1.2015)
   for each h in j do 
   to_do_list:=cons(list('split_into_cases,h),to_do_list);
   nil
  >>

end$ % of addintco

symbolic procedure integratepde(p,ftem,vari,genflag,potflag)$
%  Generalized integration of the expression p
%     if not genflag then "normal integration"
%  Equation p must not be directly separable, otherwise the depen-
%  dencies of functions of integration on their variables is wrong,
%  i.e. no dependence on explicit variables
%  ftem are all functions from the `global' ftem which occur in p, i.e.
%  ftem:=smemberl(ftem,p)$
%  if vari=nil then integration w.r.t. all possible variables within
%                   the equation
%              else only w.r.t. vari one time

begin
  scalar vl,vlrev,v,intlist,
  ili1a,ili2a,maxvanz,fsub,h,hh,nfsub,iflag,newcond,
  n1,n2,pot1,pot2,p1,p2,listoflds,secnd,ifac0,
  ifac1a,ifac1b,ifac2a,ifac2b,cop,v1a,v2a,pri,aic,pnew$

% pri:=t;
  if pri then <<terpri()$write"Start Integratepde">>$
  vl:=argset ftem$
  vlrev:=reverse vl;
  if vari then <<potflag:=nil;
                 if zerop p then iflag:='success>>
          else
  <<%------- determining fsub=list of functions of all variables
    maxvanz:=length vl$
    fsub:=nil;
    h:=ftem;
    while h do
    <<if fctlength car h=maxvanz then
      fsub:=cons(car h,fsub)$
      h:=cdr h
    >>$
    nfsub:=length fsub$  % must be >1 for potential-integration
    h:=intminderiv(p,ftem,vlrev,maxvanz,nfsub)$ % fsub is also for below
    intlist:=car h$
    %-- list of necessary integrations of the whole equation to solve
    %-- for a function of all variables
    listoflds:=cadr h$ %-- list of leading derivatives
  >>$
  if pri then <<terpri()$
                write"complete integrations:",intlist," for:",vl>>;
  %-- n1 is the number of integrations which must be done to try
  %-- potential integration which must enable to eliminate 2 functions
  %-- n2 is the number of integrations actually done
  n1:=for each h in intlist sum h;
  if (not vari) and (zerop n1) then
  <<n2:=0;
    if potflag then % else not necessary
    for h:=1:(length vl) do ifac0:=cons(nil,ifac0)
  >>                           else
  <<if tr_genint then
    <<terpri()$write "integration of the expression : "$
      eqprint p>>$
    if pri then
    <<terpri()$write"at first all multiple complete integration">>;
    %-- At first if possible n2 integrations of the whole equation
    h:=multipleint(intlist,ftem,p,vari,vl,genflag,nil,nil,nil)$
                   % potflag=nil, partial=nil, doneintvar=nil
    if h then
    <<p:=car h;
      ifac0:=cadr h;  % ifac0 is the list of lists of integr. factors
      newcond:=caddr h;
      n2:=cadddr h;   % number of done integrations
      % doneintvar & intfacdep for the two halfs of integrations
      % from the two parts of ifac0
      h:=nil;
      iflag:='success;
    >>   else n2:=0;
    ftem:=union(fnew_,ftem)$
  >>;
  %------------ Existence of a potential ?
  if (n1=n2) and potflag and (nfsub>1) then
  %---- at least 2 functions to solve for
  <<if not zerop n2 then            %---- update listoflds
    listoflds:=uplistoflds(reverse ifac0,listoflds)$
    if pri then <<terpri()$write"uplistoflds:",listoflds>>$
    if h:=potintegrable(listoflds) then
    <<ili1a:=car h; ili2a:=cadr h;
      % The necess. differentiations of the potential
      if pri then
      <<terpri()$write"potintegrable:",ili1a,"  ",ili2a>>$

      if pri then <<write"+++ intlist=",intlist,
                           "    ili1a=",ili1a,
                           "    ili2a=",ili2a>>$
      %-- distributing the integrating factors of ifac0 among
      %-- the two lists ifac1b and ifac2b which are so far nil
      %-- such that (ifac1b and ili1a are disjunct) and
      %--           (ifac2b and ili2a are disjunct)
      v1a:=vlofintlist(vl,ili1a);
      v2a:=vlofintlist(vl,ili2a);

      hh:=t;
      cop:=reverse ifac0;
      ifac1a:=ili1a;ifac2a:=ili2a;
      while hh and cop do <<
        % cop is a list of lists of integr. factors
        if car cop then h:=vlofintfaclist(vl,cdar cop)
                   else h:=nil;
        if freeoflist(h,v2a) and (car ifac2a=0) then <<
          ifac1b:=cons( nil, ifac1b);
          ifac2b:=cons( reverse car cop, ifac2b)
        >>                   else
        if freeoflist(h,v1a) and (car ifac1a=0) then <<
          ifac2b:=cons( nil, ifac2b);
          ifac1b:=cons( reverse car cop, ifac1b)
        >>                   else 
        if car cop then hh:=nil;
        ifac1a:=cdr ifac1a;
        ifac2a:=cdr ifac2a;
        cop:=cdr cop;
      >>;
      % the elements of ifac1b,ifac2b are in reverse order to 
      % ifac1a,ifac2a and are in the same order as vl, also
      % the elements in the infac-lists are in inverse order,
      % i.e. in the order the integrations have been done
      if pri then <<terpri()$
                    write  "ifac1a=",ifac1a,"  ifac1b=",ifac1b,
                    "  ifac2a=",ifac2a,"  ifac2b=",ifac2b >>$

      %-- lists of integrations to be done to both parts
      if hh then
      repeat % possibly a second try with part2 integrated first
      <<n1:=for each n1 in ili1a sum n1;
        % n1 .. number of remaining integrations of the first half
        p1:=multipleint(ili1a,ftem,p,nil,vl,genflag,t,t,
                        % potflag=t, partial=t
                        union(vlofintlist(vl,ili2a),
                              vlofintlist(vl,ifac1b)))$
        % that the variables of integration are not in ifac1b
        % was already checked. Only restriction: the integrating
        % factors must not depend on the last argument.

        ftem:=union(fnew_,ftem)$
        if p1 then <<
          ifac1a:=cadr p1;
          % ifac1a is now the list of integrating factors
          if newcond then newcond:=nconc(newcond,caddr p1)
                     else newcond:=caddr p1;
          if pri then <<terpri()$write"mul2: newcond=",newcond>>$
          n2:=cadddr p1;
          p1:=car p1
        >>;
        if p1 and (n1=n2) then
        %--- if the first half has been integrated suff. often
        <<%--- integrating the second half sufficiently often
          n1:=for each n1 in ili2a sum n1;
          % calculation of the 2. part which is not contained in p1
          p2:=p1;
          cop:=ifac1a; hh:=vlrev; % because ifac1a is reversed
          while cop do <<
            h:=car cop;cop:=cdr cop;
            v:=car hh;hh:=cdr hh;
            % h is the list of integrating factors of the v-integr.
            while h do <<
              p2:=reval list('quotient,list('df,p2,v),car h);
              h:=cdr h
            >>
          >>;
          p2:=reval reval list('plus,p,list('minus,p2));
          p2:=multipleint(ili2a,ftem,p2,nil,vl,genflag,t,nil,
                          % potflag=t, partial=nil
                          union(vlofintlist(vl,ili1a),
                                vlofintlist(vl,ifac2b)))$
          ftem:=union(fnew_,ftem)$
          if p2 then <<
            ifac2a:=cadr p2;
            % ifac2a is now list of integrating factors
            if newcond then newcond:=nconc(newcond,caddr p2)
                       else newcond:=caddr p2;
            if pri then <<terpri()$write"mul3: newcond=",newcond>>$
            n2:=cadddr p2;
            p2:=car p2
          >>;
          if p2 and (n1=n2) then
          % if the second half has been integrated sufficiently often
          <<% can both halfes be solved for different functions
            % i.e. are they algebraic and linear in different functions?
            pot1:=nil;
            pot2:=nil;
            for each h in fsub do <<
              if ld_deriv_search(p1,h,vl) = (nil . 1) then 
              pot1:=cons(h,pot1);
              if ld_deriv_search(p2,h,vl) = (nil . 1) then 
              pot2:=cons(h,pot2);
            >>$
            if (null not_included(pot1,pot2)) or
               (null not_included(pot2,pot1)) then p2:=nil
          >>$ 
          if p2 and (n1=n2) then
          <<% ifac1b,ifac2b are in reverse order to ifac1a,ifac2a!
            pot1:=newfct(fname_,vl,nfct_)$  % the new potential fct.
            pot2:=pot1;
            nfct_:=add1 nfct_$
            fnew_:=cons(pot1,fnew_);
            flin_:=fctinsert(pot1,flin_)$
            v:=vlrev;
            while v do
            <<cop:=car ifac1a; ifac1a:=cdr ifac1a;
              while cop do <<
                pot1:=reval list('quotient,list('df,pot1,car v),car cop);
                cop:=cdr cop
              >>;
              cop:=car ifac2a; ifac2a:=cdr ifac2a;
              while cop do <<
                pot2:=reval list('quotient,list('df,pot2,car v),car cop);
                cop:=cdr cop
              >>;
              v:=cdr v;
            >>;
            pnew:=addintco(list('plus,p1,reval pot2),
                           ftem,ifac1b,vlrev,nil)$
            % This value is called pnew and not p because if secnd=nil then
            % if pnew=nil or aic=nil below then another try can be done 
            % by integrating in a different order and then the former value 
            % of p is still needed.
            % BUT, if pnew=nil or aic=nil then case-distinctions have
            % already been booked in addintco() (in to_do_list) and then
            % repeating in a different order would perhaps book the same
            % case distinctions again which would not be good --> we set
            % secnd:=t.

            if null pnew then secnd:=t
                         else <<
              aic:=addintco(list('plus,p2,list('minus,reval pot1)),
                            ftem,ifac2b,vlrev,nil)$
              if null aic then secnd:=t
                          else <<
                newcond:=cons(aic,newcond)$ % vari=nil
                iflag:='potint % i.e. success by integration with potential 
              >>
            >>
          >>
          ;if pri then write":::"$
        >>;
        % Before the following assignment it is secnd=t if this is the 
        % second time this loop is run and then no more run.
        secnd:=not secnd;
        % retry in different order of integration, p is still the same
        if (iflag neq 'potint) and secnd then
        <<cop:=ili1a;ili1a:=ili2a;ili2a:=cop>>
      >> until (iflag eq 'potint) % success
            or (not secnd)        % no success (iflag=nil)
    >>;
  >>$

  %--------- returning the result
  return if null iflag then nil
                       else
  <<if iflag='potint then % pnew with contants of integration is computed.
                     else % add constants of integration
    pnew:=addintco(p, ftem, % the completely reversed ifac0
                   <<h:=nil;
                     while ifac0 do <<h:=cons(reverse car ifac0,h);
                                      ifac0:=cdr ifac0>>;
                     h
                   >>, vl, vari)$

    % If the terms involving constants of integration are not unique
    % because their structure depends on the value of parameters
    % (like int(x^n,x) = x^(n+1)/(n+1) or log(x) for n=-1) then 
    % case distinctions have been booked and then p=nil:
    if null pnew then nil
                 else <<
      if pri then <<terpri()$write"ENDE INTEGRATEPDE"$
                    deprint(cons(pnew,newcond))>>$
      cons(pnew,newcond)
    >>
  >>
end$ % of integratepde


symbolic procedure intpde(p,ftem,vl,x,potint)$
begin scalar ft,ip,h,itgl1,itgl2$

 if potint or null lin_problem then return intpde_(p,ftem,vl,x,potint)$ 
 % test null lin_problem added 28.5.03

 % ft are functions of x
 for each h in ftem do 
 if not freeof(assoc(h,depl!*),x) then ft:=cons(h,ft);

 ip:=int_partition(p,ft,x)$
 if null cdr ip then return intpde_(p,ftem,vl,x,potint)$

 while ip do <<
  h:=intpde_(car ip,ftem,vl,x,potint)$
  if null h then <<
   ip:=nil; 
   itgl1:=nil;
   itgl2:=nil
  >>        else <<
   % itgl1:=cons(car  h,itgl1);
   % itgl2:=cons(cadr h,itgl2);
   itgl1:=nconc(list(car  h),itgl1);
   itgl2:=nconc(list(cadr h),itgl2);
   ip:=cdr ip
  >>;
 >>$

 if itgl1 then <<itgl1:=reval cons('plus,itgl1);
                 itgl2:=reval cons('plus,itgl2) >>$

 return if null itgl1 then nil
                      else {itgl1,itgl2}
end$


symbolic procedure drop_x_dif(der,x)$
begin scalar dv,newdv$
 % der is a derivative like {'df,f,u,2,x,3,y,z,2} or {'df,f,u,2,x,y,z,2}
 % drops the x-derivative(s)
 dv:=cddr der;
 while dv do <<
  if car dv=x then if cdr dv and fixp cadr dv then dv:=cdr dv
                                              else
              else newdv:=cons(car dv,newdv);
   dv:=cdr dv
 >>;
 return if newdv then cons('df,cons(cadr der,reverse newdv))
                 else cadr der
end$


symbolic procedure strip_x(ex,ft,x)$
begin scalar tm,cex$
 % ex is a term
 % ft is a list of all functions of x which possibly occur in ex
 return
 if freeoflist(ex,ft) then 1 else
 if not pairp ex then ex else
 if car ex='minus then strip_x(cadr ex,ft,x) else
 if car ex='df then drop_x_dif(ex,x) else
 if car ex='expt then if not pairp cadr ex then ex else
                      if caadr ex='df then
                      {'expt,drop_x_dif(cadr ex,x),caddr ex} else 1 % strange
                 else
 if car ex='times then <<
  ex:=cdr ex;
  while ex do <<
   cex:=car ex; ex:=cdr ex;
   if not freeoflist(cex,ft) then 
   if not pairp cex then tm:=cons(cex,tm) else
   if car cex='df then tm:=cons(drop_x_dif(cex,x),tm) else
   if car cex='expt then if not pairp cadr cex then tm:=cons(cex,tm) else
                         if caadr cex='df then
                         tm:=cons({'expt,drop_x_dif(cadr cex,x),caddr cex},tm) 
                    % else strange - no polynomial in ft
  >>;
  if null tm then 1 % strange
             else 
  if length tm > 1 then reval cons('times,tm)  % product of factors
                   else car tm                 % single factor
 >>               else 1 % strange
end$

symbolic procedure sort_partition(pname,p,ft,x)$
% The equation is either given by its name pname or its value p
% if keep_parti=t then the partitioning will be stored
begin scalar stcp,pcop,parti;
 % parti will be the list of partial sums
 if pname then
 if get(pname,'partitioned) then return get(pname,'partitioned)
                            else <<cp_sq2p_val(pname)$p:=get(pname,'pval)>>$
 if (not pairp p) or (car p neq 'plus) then p:=list p 
                                       else p:=cdr p;
 if null ft then parti:={{1,1,p}} else
 while p do <<                % sort each term into a partial sum
  stcp:=strip_x(car p,ft,x);  % first strip off x_dependent details
  pcop:=parti;                % search for the label in parti
  while pcop and 
        caar pcop neq stcp do pcop:=cdr pcop;
  if null pcop then parti:=cons({stcp,1,{car p}},parti)  
                              % open a new partial sum
               else rplaca(pcop,{stcp,add1 cadar pcop,
                                 cons(car p,caddar pcop)});
                              % add the term to an existing partial sum
  p:=cdr p
 >>;
 if pname and keep_parti then put(pname,'partitioned,parti)$
 return parti
end$ % of sort_partition

symbolic procedure int_partition(p,ft,x)$
begin scalar parti,ft,pcop;

 % the special case of a quotient
 if (pairp p) and (car p='quotient) then return 
 if not freeoflist(caddr p,ft) then list p
                               else <<
  pcop:=int_partition(cadr p,ft,x)$
  for each h in pcop collect {'quotient,h,caddr p}
 >>$
 parti:=sort_partition(nil,p,ft,x)$
 parti:=idx_sort for each h in parti collect cdr h;
 return for each h in parti collect
        if car h = 1 then caadr h
                     else cons('plus,cadr h) 

end$

symbolic procedure intpde_(p,ftem,vl,x,potint)$
% integration of an polynomial expr. p w.r.t. x
begin scalar f,ft,l,l1,l2,l3,l4,vl,k,s,a,iflag,flag$
  ft:=ftem$
  vl:=cons(x,delete(x,vl))$
  while ftem and not flag do
  <<f:=car ftem$ % integrating all terms including car ftem
    if member(x,fctargs f) then
    <<if (pairp p) and (car p = 'quotient) then <<
        l1:=lderiv(cadr  p,f,vl)$ % numerator
        if cdr l1 neq 'infinity then <<
          l2:=lderiv(caddr p,f,vl)$ % denomiator
          if cdr l2 = 'infinity then l1:=l2 
                                else <<
            if car l1 and (car l1=car l2) then l1:=(car l1 . 2) % nonlinearity
                                          else <<
              l:=lderiv({'plus,car l1,car l2},f,vl)$ % comparison of both
              if car l2 % changed from car l1 as car l1 gives endless loops with
                 % call intpde((quotient (minus 1) (df u y)),(u),(y x t),y,nil)
                 and (car l = car l2) then l1:=(car l2 . -1)
            >>
          >>
        >>;
        l:=l1;
      >>                                   else
      l1:=l:=lderiv(p,f,vl)$
      while not (flag or <<
        iflag:=intlintest(l,x);
        if (iflag='noxdrv) or (iflag='nodrv) then <<
          l2:=start_let_rules()$
          p:=reval p$
          stop_let_rules(l2)$
          l:=lderiv(p,f,vl)$
          iflag:=intlintest(l,x)
        >>                                   else
        if potint and (iflag='nonlin) and (pairp p) and 
           (car p='plus) and null l3 and (cdr l neq 'infinity) then <<
          l3:=t; l4:=l;
          l:=car l . 1;
          iflag:=intlintest(l,x);
          l:=l4
        >>;
        iflag
      >>        ) do
      <<if (pairp p) and (car p = 'quotient) then
        k:=reval {'quotient,coeffn(cadr p,car l,cdr l),caddr p}
                                             else
        k:=reval coeffn(p,car l,cdr l)$
        if intcoefftest(car lderiv(k,f,vl),car l,vl) then
        <<a:=decderiv(car l,x)$
          %k:=reval list('int,subst('v_a_r_,a,k),'v_a_r_)$   
          k:=err_catch_int(subst('v_a_r_,a,k),'v_a_r_)$   
          if null k then <<k:=0;flag:='too_slow>>;
          if lin_problem then l4:=nil
                         else l4:=zero_den(k,ft);
          if l4 then <<
            % no constants of integration have been added yet so 
            % added cases do not involve constants of integration
            % for each l2 in l4 do 
            % to_do_list:=union(list(list('split_into_cases,l2)),to_do_list);

            % The above to_do_list:=.. statement can only be issued if
            % that expression ex is known not to be an equation or
            % equal zero modulo equations.  Reason: If the equation
            % ex=0 exists then the case ex <> 0 is quickly lead to a
            % conradiction and the case ex=0 does not give anything
            % new and will execute again the same integration and the
            % same case distinction.

            flag:='needs_case_split
          >>    else <<
            k:=reval subst(a,'v_a_r_,k)$
            s:=cons(k,s)$
            p:=list('difference,p,list('df,k,x))$  %#####  This can take long to simplify
            p:=err_catch_reval p$
            if null p then flag:='reval_too_slow else
            if diffrelp(l1,(l:=lderiv(p,f,vl)),vl) then flag:='neverending
                                                   else l1:=l
          >>
        >>                                        else
        flag:='coeffld
      >>$
      % iflag='nofct is the so far integrable case
      % the non-integrable cases are: flag neq nil,
      % (iflag neq nil) and (iflag neq 'nofct), an exception to the
      % second case is potint where non-integrable rests are allowed
      if (flag neq 'reval_too_slow) and
         (flag neq 'neverending)    then % because in these cases p is lost,
                                         % it would need to be programmed that 
                                         % a trial integration is done. 
                                         % no time for doing that now (19.4.2014)
      if iflag='nofct then ftem:=smemberl(ftem,p)
                      else if potint or (fctlength f<length vl) then
                           <<ftem:=cdr ftem$flag:=nil>>         else
                           flag:=(iflag or flag)
    >>                     else
    ftem:=cdr ftem
  >>$
  return
  if flag then nil else
  <<
    l:=explicitpart(p,ft,x)$
    %l1:=list('INT,l,x)$
    l1:=err_catch_int(l,x)$
    if null l1 then nil
               else <<
      s:=reval cons('plus,cons(l1,s))$
      if lin_problem then l4:=nil
                     else l4:=zero_den(s,ft);
      if l4 then <<
        % no constants of integration have been added yet so 
        % added cases do not involve constants of integration
        for each l2 in l4 do 
        % <<write"CCCC"$terpri()$
        to_do_list:=union(list(list('split_into_cases,l2)),to_do_list);
        % >>$
        nil
      >>    else
      if freeint_ and (null freeof(s,'INT)) then nil else
      if freeabs_ and (null freeof(s,'ABS)) then nil else <<
        k:=start_let_rules()$
        l2 := reval {'df,l1,x} where !*precise=nil;
        if 0 neq (reval {'difference,l,l2} where !*precise=nil) then <<
          write"REDUCE integrator error:"$terpri()$
          algebraic write "int(",l,",",x,") neq ",l1;terpri()$
          write"Result ignored.";terpri()$
          stop_let_rules(k)$
          nil
        >> else <<
          p:=reval list('difference,p,l2)$
          stop_let_rules(k)$
          if poly_only then if ratexp(s,ft) then list(s,p)
                                            else nil
                        else list(s,p)
        >>
      >>
    >>
  >>
end$ % of intpde_

symbolic procedure explicitpart(p,ft,x)$
% part of a sum p which only explicitly depends on a variable x
begin scalar l$
  if not member(x,argset smemberl(ft,p)) then l:=p
                                         else if pairp p then
  <<if car p='minus then l:=reval list('minus,explicitpart(cadr p,ft,x))$
    if (car p='quotient) and not member(x,argset smemberl(ft,caddr p)) then
       l:=reval list('quotient,explicitpart(cadr p,ft,x),caddr p)$
    if car p='plus then <<
      for each a in cdr p do
      if not member(x,argset smemberl(ft,a)) then l:=cons(a,l)$
      if pairp l then l:=reval cons('plus,l)>> >>$
  if not l then l:=0$
  return l$
end$

symbolic procedure intconst(co,vl,x,ifalist)$
% The factors in ifalist must be in the order of integrations done
if null ifalist then 0 else
begin scalar l,l2,f,coli,cotmp$
  while ifalist do <<
    cotmp:=coli;
    coli:=nil;
    while cotmp do <<
      coli:=cons(list('int,list('times,car ifalist,car cotmp),x),coli);
      cotmp:=cdr cotmp
    >>;
    coli:=cons(1,coli);
    ifalist:=cdr ifalist
  >>;

  while coli do
  <<f:=newfct(fname_,delete(x,vl),nfct_)$
    nfct_:=add1 nfct_$
    fnew_:=cons(f,fnew_)$
    flin_:=fctinsert(f,flin_)$
    l:=cons(list('times,f,car coli),l)$
    coli:=cdr coli
  >>$
  if length l>1 then l:=cons('plus,l)
                else if pairp l then l:=car l
                                else l:=0$
  if co and co neq 1 then
  if pairp co then
  <<if car co='times then co:=cdr co
                     else co:=list co$
    while co do <<if my_freeof(car co,x) then l2:=cons(car co,l2)$
                  co:=cdr co>>
  >>
              else if co neq x then l2:=list co$
  return reval if l2 then cons('times,cons(l,l2))
                     else l
end$

symbolic procedure intcoefftest(l,l1,vl)$
begin scalar s$
return if not pairp l then t
       else if car l='df then
               <<s:=decderiv(l1,car vl)$
               if pairp s and pairp cdr s then s:=cddr s
                                          else s:=nil$
               if diffrelp(cons(cddr l,1),cons(s,1),vl) then t
                                                       else nil>>
else t$
end$

symbolic procedure fctlinear(p,f)$
<<p:=ldiffp(p,f)$
(null car p) and (cdr p=1)>>$

symbolic procedure intlintest(l,x)$
%  Test,ob in einem Paar (fuehrende Ableitung.Potenz)
%  eine x-Ableitung linear auftritt
if not car l then
   if zerop cdr l then 'nofct
                  else 'nonlin
else                                    %  Fkt. tritt auf
  if (car l) and (cdr l=1) then         %  fuehr. Abl. tritt linear auf
                if pairp car l then     %  Abl. der Fkt. tritt auf
                    if caar l='df then
                        if member(x,cddar l) then nil
                                        %  x-Abl. tritt auf
                        else if member(x,fctargs cadar l) then 'noxdrv
                                else 'noxdep
                    else 'nodrv
                else 'nodrv
  else 'nonlin$

symbolic procedure decderiv(l,x)$
%  in Diff.ausdr. l wird Ordn. d. Abl. nach x um 1 gesenkt
begin scalar l1$
return if l then if car l='df then
        <<l1:=decderiv1(cddr l,x)$
        if l1 then cons('df,cons(cadr l,l1))
                 else cadr l>>
                            else l
           else nil$
end$

symbolic procedure decderiv1(l,x)$
if null l then nil
else
if car l=x then
     if cdr l then
            if numberp cadr l then
                  if cadr l>2 then cons(car l,cons(sub1 cadr l,cddr l))
                  else cons(car l,cddr l)
            else cdr l
     else nil
else cons(car l,decderiv1(cdr l,x))$

symbolic procedure integratede(q,ftem,genflag)$
%  Integration of a de
%  result: newde if successfull, nil otherwise
begin scalar l,l1,l2,fl,ltdl$
 ftem:=smemberl(ftem,q)$
 ltdl:=length to_do_list$

 again:
 if l1:=integrableode(q,ftem) then     % looking for an integrable ode
 if l1:=integrateode(q,car l1,cadr l1,caddr l1,ftem) then
                                       % trying to integrate it
 <<l:=append(cdr l1,l);
   q:=prepsq car simplifypdeSQ(simp car l1,ftem,nil,nil,nil)$  
   ftem:=smemberl(union(fnew_,ftem),q)$
   fl:=t
 >>                                                  else 
 if (ltdl < length to_do_list) and 
    (caar to_do_list = 'split_into_cases) then 
 return nil$ % because the ODE involves parameters and the solution 
 % depends on the value of parameters leading to case distinctions.
 % Continuing the integration with other methods would most likely
 % lead to the same case distinctions which are to be made next.

 if l1:=integratepde(q,ftem,nil,genflag,potint_) then
                                       % trying to integrate a pde
 <<q:=car l1$
   for each a in cdr l1 do
   <<ftem:=union(fnew_,ftem)$
     if (l2:=integratede(a,ftem,nil)) then l:=append(l2,l)
                                      else l:=cons(a,l)
   >>$
   fl:=t$
   if null genflag then l1:=nil$
   ftem:=smemberl(union(fnew_,ftem),q);
   goto again
 >>$

 if fl then
 <<l:=cons(q,l)$
   l:=for each a in l collect reval a$
   l:=for each a in l collect
          if pairp a and (car a='quotient) then cadr a
                                           else a>>$
 return l$
end$

symbolic procedure intflagtest(q,fullint)$  
if flagp(q,'to_int) then
 if fullint then
  if (null flagp(q,'to_fullint)) then nil else
  if get(q,'starde) then nil else 
  if (null get(q,'allvarfcts)) 
     % or (cdr  get(q,'allvarfcts)) % if more than one allvar-function
  then nil else                            
  begin scalar fl,vl,dl,l,n,mi$
   n:=get(q,'nvars)$
   for each f in get(q,'rational) do            % only rational fcts
       if fctlength f=n then fl:=cons(f,fl)$
   if null fl then return nil$
   vl:=get(q,'vars)$
   dl:=get(q,'derivs)$
   for each d in dl do
    if member(caar d,fl) then
       put(caar d,'maxderivs,maxderivs(get(caar d,'maxderivs),cdar d,vl))$
   dl:=fl$
   while vl do
    <<mi:=car get(car fl,'maxderivs)$
    l:=list car fl$
    put(car fl,'maxderivs,cdr get(car fl,'maxderivs))$
    for each f in cdr fl do
      <<if (n:=car get(f,'maxderivs))=mi then l:=cons(f,l)
        else if n<mi then 
          <<l:=list f$
          mi:=n>>$
        put(f,'maxderivs,cdr get(f,'maxderivs))
      >>$
    dl:=intersection(l,dl)$
    if dl then vl:=cdr vl
          else vl:=nil>>$
   for each f in fl do remprop(f,'maxderivs)$
   if fullint and (null dl) then remflag1(q,'to_fullint)$
   return dl
  end      
 else t$
       

symbolic procedure integrate(q,genintflag,fullint,pdes)$  
%  integrate pde q; if genintflag is not nil then indirect
%  integration is allowed
%  if fullint is not nil then only full integration is allowed which
%  in addition leads to a substitution
%  Currently not used if functions occur 
%  Currently not used:Es wird noch nicht ausgenutzt: 
%    1) functions that occur rationally,
%    2) starde
%  parameter pdes only for drop_pde_from_idties(), drop when pdes_ global
%                 and for mkeqSQlist() for adding inequalities 
begin scalar l,fli,fnew_old,h,loftolist$
  if fli:=intflagtest(q,fullint) then
  <<if fullint then <<fnew_old:=fnew_;fnew_:=nil>>$
    cp_sq2p_val(q)$
    loftolist:=length to_do_list$
    if (l:=integratede(get(q,'pval),get(q,'fcts),genintflag)) then <<
      if fullint then 
      while fli and 
            (not null car (h:=ldiffp(car l,car fli)) or
             cdr h neq 1 or <<
               h:=coeffn(car l,car fli,1);
               if domainp h then nil 
                            else <<
                 h:=simplifySQ(cadr h,get(q,'fcts),t,nil,t)$
                 if h={(1 . 1)} then t else nil
               >>
             >>
            ) do fli:=cdr fli;
      if null fli then <<
        remflag1(q,'to_fullint);
        for each f in fnew_ do drop_fct(f)$
        fnew_:=fnew_old;
        l:=nil;
        if print_ then <<
          terpri()$write"Not enough integrations to solve for a function"$
          if null lin_problem then <<
           write", or,"$terpri()$write"substitution prevented through non-linearity."
          >>                  else write"."
        >>
      >>                                                else
      <<fnew_:=union(fnew_old,fnew_)$
        for each f in fnew_ do <<
          ftem_:=fctinsert(f,ftem_)$
          flin_:=cons(f,flin_)       
        >>$
        flin_:=sort_according_to(flin_,ftem_);
        fnew_:=nil$

        % Is the old equation to be kept because the new integrated (non-linear)
        % equation is sufficient but not necessary? (possible outcome of odeconvert)
        h:=cdr l;
        while h and (car h neq get(q,'pval)) do h:=cdr h;
        if h then << % equation q is to be kept
          l:=delete(get(q,'pval),l);
          l:=cons(q,mkeqSQlist(nil,nil,l,ftem_,get(q,'vars),
                               allflags_,t,get(q,'orderings),pdes))$
          if print_ then <<
            terpri()$
            if l and cdr l and cddr l then <<
              write"The equation ",q," is kept and an additional sufficient"$terpri()$
              write"integral with conditions ",cdr l," are added."
            >>                        else <<
              write"The equation ",q," is kept and an additional sufficient"$terpri()$
              write"integral ",cadr l," is added."
            >>$
            terpri()
          >>
        >>   else <<
          flag1(q,'to_eval)$
          updateSQ(q,nil,nil,car l,ftem_,get(q,'vars),t,list(0),nil)$
          drop_pde_from_idties(q,pdes,nil)$
          drop_pde_from_properties(q,pdes)$
          l:=cons(q,mkeqSQlist(nil,nil,cdr l,ftem_,get(q,'vars),
                               allflags_,t,get(q,'orderings),pdes))$
          put(q,'dec_with,nil);     % 23.3.99 added --> cycling?
          put(q,'dec_with_rl,nil);  %    "    added --> cycling?
          if print_ then <<
            terpri()$
            if cdr l then 
            if get(q,'nvars)=get(cadr l,'nvars)              then 
            write "Potential integration of ",q," yields ",l else
            write "Partially potential integration of ",q," yields ",l 
                     else write "Integration of ",q$
            terpri()
          >>
        >>$

        % In order not to re-investigate q for integrability either
        % new cases have been added or the integrability is decided:
        if loftolist=length to_do_list then <<
          remflag1(q,'to_fullint)$
          remflag1(q,'to_int)
        >>
      >>
    >>                                                       else <<
      remflag1(q,'to_fullint)$
      remflag1(q,'to_int)
    >>
  >>$
  return l$
end$

symbolic procedure quick_integrate_one_pde(pdes)$
begin scalar q,p,r,v,nv,nvc,minv,miordr,minofu,minodv,ordr,nofu,nodv$ % ,nvmax$
  % nvmax:=0;
  % for each q in ftem_ do if (r:=fctlength q)>nvmax then nvmax:=r;

  nv:=no_fnc_of_v()$ % the number of functions for each variable

  % find the lowest order derivative wrt. only one variable
  miordr:=10000;  % the order of the currently best equation
  minofu:=10000;  % the number of functions depending on the
                  % variable wrt. which shall be integrated
  minodv:=10000;  % the number of differentiation variables of
                  % the so far best equation
  while pdes and 
        (get(car pdes,'length) = 1) do <<  % only 1 term
    q:=get(car pdes,'derivs)$
    if q and    % (get(car pdes,'nvars) = nvmax) 
       cdaar q  % any differentiations at all
    then <<
      q:=caar q$
      nodv:=0$           % no of differentiation variables
      ordr:=0$           % total order of the derivative
      r:=cdr q;
      v:=cadr q$
      while r do <<
        if fixp car r then ordr:=ordr-1+car r
                      else <<ordr:=add1 ordr;nodv:=add1 nodv>>;
        r:=cdr r
      >>$
      if nodv>1 then nofu:=10000 % nodv = no of functions depending 
                else <<          %        on the integration variable
        nvc:=nv;
        while v neq caar nvc do nvc:=cdr nvc;
        nofu:=cdar nvc;  
      >>$                  % no of fncs of v

      if nodv=1 then
      if ((ordr=1) and (miordr>1)) or
         (a_before_b_according_to_c(v,minv,vl_) and (ordr<=miordr)) or 
         ((v=minv) and
          (ordr<miordr) or ((ordr=miordr) and
          (nodv<minodv) or ((nodv=minodv) and
          (nofu<minofu)))) then
      <<p:=car pdes;
        minv:=v;
        minofu:=nofu;
        miordr:=ordr;
        minodv:=nodv
      >>;
    >>$
    pdes:=cdr pdes
  >>$
  if p then p:=integrate(p,nil,t,pdes)$
  return p
end$

symbolic procedure integrate_one_pde(pdes,genintflag,fullint)$  
%  trying to integrate one pde
begin scalar l,l1,m,p,pdescp,tdlcp$ % ,nvmax,h,f$

  % For non-linear differential equations it can happen, that integrations 
  % of, for example inhomogeneous term lead to case distinctions on
  % constants/functions which have been the result of earlier integrations. 
  % But if the integration is afterall not completed and therefore not done, 
  % and therefore no additions should have been added to to_do_list which
  % involve only new constants/functions.
  tdlcp:=to_do_list$

  % nvmax:=0;
  % for each f in ftem_ do if (h:=fctlength f)>nvmax then nvmax:=h;
  % at first selecting all eligible de's
  m:=-1$
  pdescp:=pdes$
  while pdescp do <<
    if flagp(car pdescp,'to_int) and not(get(car pdescp,'starde)) and
       (null fullint or lin_problem or
        get(car pdescp,'linear_) or 
%       not pairp get(car pdescp,'val) or 
%       car get(car pdescp,'val) neq 'times
        not pairp get(car pdescp,'fac)
       ) then <<
      l:=cons(car pdescp,l);
      if get(car pdescp,'nvars)>m then m:=get(car pdescp,'nvars)$
    >>;
    pdescp:=cdr pdescp
  >>;

  l:=reverse l;

  if mem_eff then % try the shortest equation first
  while l do
  if p:=integrate(car l,genintflag,fullint,pdes) then l:=nil
                                                 else l:=cdr l
             else
  % find an equation to be integrated with as many as possible variables
  % if (m=nvmax) or (null fullint) then
  while m>=0 do <<
    l1:=l$
    while l1 do
    if (get(car l1,'nvars)=m) and 
       (p:=integrate(car l1,genintflag,fullint,pdes)) then <<
      m:=-1$
      l1:=nil
    >>                                                else l1:=cdr l1$
    % if fullint then m:=-1 else 
    m:=sub1 m
  >>$

  if null p then <<
    to_do_list:=cons(1,to_do_list);
    L:=to_do_list;
    while cdr l neq tdlcp do
    if freeoflist(cadr l,ftem_) then rplacd(l,cddr l)
                                else l:=cdr l;
    to_do_list:=cdr to_do_list$
  >>$
return p$
end$

endmodule$

%********************************************************************
module generalized_integration$
%********************************************************************
%  Routines for generalized integration of pde's containing unknown
%  functions
%  Author: Andreas Brand
%  December 1991

symbolic procedure gintorder(p,vl,x)$
%symbolic procedure gintorder(p,ftem,vl,x)$
%  reorder equation p
begin scalar l,l1,q,m,b,c,q1,q2$
  if pairp(p) and (car p='quotient) then <<
   q:=caddr p$
   p:=cadr p$
   l1:=gintorder1(q,x,t)$
%   l1:=gintorder1(q,ftem,x,t)$
%   if DepOnAllVars(car l1,x,vl) then return nil;
   q1:=car l1;
   q2:=cadr l1;
  >>$
  if pairp(p) and (car p='plus) then p:=cdr p   % list of summands
                                else p:=list p$
  while p do
  <<l1:=gintorder1(car p,x,nil)$
%  <<l1:=gintorder1(car p,ftem,x,nil)$
    if DepOnAllVars(if q1=1 then car l1
                            else cons('times,
                    append(if pairp q1 and car q1='times then cdr q1 
                                                         else list q1,
                           if pairp car l1 and caar l1='times then cdar l1
                                                              else list car l1)),
                    x,vl) then l:=p:=nil
                          else <<l:=termsort(l,l1)$p:=cdr p>> >>$
  if l then
  <<l:=for each a in l collect if cddr a then
               <<b:=car a$
                 c:=cdr reval coeff1(cons('plus,cdr a),x,nil)$
                 m:=0$
                 while c and (car c=0) do <<c:=cdr c$m:=add1 m>>$
                 if m>0 then b:=list('times,list('expt,x,m),b)$
                 cons(reval b,c)>>
                                         else
                 cons(reval car a,cdr reval coeff1(cadr a,x,nil))$
    if q then <<
       l:=for each a in l collect
              cons(car a,for each s in cdr a collect
                             reval list('quotient,s,q2))$
       l:=for each a in l collect
              cons(reval list('quotient,car a,q1),cdr a)
    >>$
>>$
return l$
end$

symbolic procedure DepOnAllVars(c,x,vl)$
% tests for occurence of vars from vl in factors of c depending on x
begin scalar l$
if pairp c and (car c='times) then c:=cdr c
                              else c:=list c$
while c and vl do
<<if not my_freeof(car c,x) then 
     for each v in vl do if not my_freeof(car c,v) then l:=cons(v,l)$
  vl:=setdiff(vl,l)$
  c:=cdr c
>>$
return (null vl)$
end$

symbolic procedure gintorder1(p,x,mode2)$
%symbolic procedure gintorder1(p,ftem,x,mode2)$
%  reorder a term p
begin scalar l1,l2,sig$      
% mode2 = nil then
%    l2: list of factors of p not depending on x 
%        or being a power of x
%    l1: all other factors
% mode2 = t then
%    l2: list of factors of p not depending on x 
%    l1: all other factors

if pairp p and (car p='minus) then <<sig:=t$p:=cadr p>>$
if pairp p and (car p='times) then p:=cdr p
                              else p:=list p$
for each a in p do
   <<if my_freeof(a,x) then l2:=cons(a,l2)
     % 14 April 2013: dropped 'and freeoflist(a,ftem)' in above if statement
     % because then new functions introduced in generalized integrations
     % may depend on all variables if all functions in the factors not
     % depending on x may depend on all variables apart of x
     %
     % Example: 0=a(x,y)*b(y,z)-df(c(x,y,z),z)
     % If there is 'and freeoflist(a,ftem)' then integration gives
     % 0=h(x,y,z)     -c(x,y,z)+c_1(x,y),  df(h,z)=a*b
     % which is useless as the new function has all variables
     % and without 'and freeoflist(a,ftem)' integration gives
     % 0=a(x,y)*h(y,z)-c(x,y,z)+c_1(x,y),  df(h,z)=b
     % which is useful as the new function has less variables 
     %
     else if mode2 then l1:=cons(a,l1)
     else if a=x then l2:=cons(a,l2)
     else if pairp a and (car a='expt) and (cadr a=x) and fixp caddr a
     then l2:=cons(a,l2)
     else l1:=cons(a,l1)>>$
if pairp l1 then
   if cdr l1 then l1:=cons('times,l1)
             else l1:=car l1$
if pairp l2 then
   if cdr l2 then l2:=cons('times,l2)        
             else l2:=car l2$ 
if sig then if l2 then l2:=list('minus,l2)
                  else l2:=list('minus,1)$
return list(if l1 then l1 else 1,if l2 then l2 else 1)$
end$

symbolic procedure partint(p,ftem,vl,x,genint)$
% genint is the maximal number of terms to be generalized integrated
begin scalar f,neg,l1,l2,n,k,l,h$
  if tr_genint then <<
    terpri()$
    write "generalized integration of the unintegrated rest : "$
    eqprint p
  >>$
  l:=gintorder(p,vl,x)$
%  l:=gintorder(p,ftem,vl,x)$
  % would too many new equations and functions be necessary?  
  if pairp(l) and (length(l)>genint) then return nil;
  l:=for each s in l collect <<
    h:=varslist(car s,ftem,vl)$
    if h=nil then <<
      list('times,x,car s,cons('plus,cdr s))
    >>       else <<
      f:=newfct(fname_,h,nfct_)$
      nfct_:=add1 nfct_$
      fnew_:=cons(f,fnew_)$
      flin_:=fctinsert(f,flin_)$
      neg:=t$
      n:=sub1 length cdr s$
      k:=-1$
      if (pairp car s) and (caar s='df) then
        <<h:=reval reval list('difference,cadar s,list('df,f,x,add1 n))$
        if not zerop h then l1:=cons(h,l1)$
        l2:=cddar s>>
      else
        <<h:=signchange reval reval list('difference,car s,
                                   list('df,f,x,add1 n))$
        if not zerop h then l1:=cons(h,l1)$
        l2:=nil>>$
      reval cons('plus, for each sk on cdr s collect
                 <<neg:=not neg$
                   k:=add1 k$
                   reval list('times,if neg then -1 else 1,
                              append(list('df,f,x,n-k),l2),
                              tailsum(sk,k,x)               )
                 >>
                )
    >>
  >>$
  if l then l:=cons(reval cons('plus,l),l1)$
  if tr_genint then
  <<terpri()$
    write "result (without constant or function of integration): "$
    if l then <<
     eqprint car l$
     write "additional equations : "$
     deprint cdr l
    >>   else write " nil "$
  >>$
  return l$
end$

symbolic procedure tailsum(sk,k,x)$
begin scalar j$
j:=-1$
return reval cons('plus,
for each a in sk collect
    <<j:=j+1$
    list('times,a,prod(j+1,j+k),list('expt,x,j)) >> )
end$

symbolic procedure prod(m,n)$
if m>n then 1
       else for i:=m:n product i$

endmodule$


%********************************************************************
module intfactor$
%********************************************************************
%  Routines for finding integrating factors of PDEs
%  Author: Thomas Wolf
%  July 1994

% The following without factorization --> faster but less general
%symbolic procedure fctrs(p,vl,v)$
%begin scalar fl1,fl2,neg;
%
%write"p=",p;
%
% if car p='minus then <<neg:=t;p:=cdr p>>$
% return
% if not pairp p then if my_freeof(p,v) and (not freeoflist(p,vl)) then
%                     list(p,1,neg)                             else
%                     list(1,p,neg)
%                else if car p='plus then list(1,p,neg)
%                                    else
% if car p='times then
% <<for each el in cdr p do if my_freeof(el,v) and (not freeoflist(p,vl)) then
%   fl1:=cons(el,fl1)                                                  else
%   fl2:=cons(el,fl2);
%   if pairp fl1 then fl1:=cons('times,fl1);
%   if pairp fl2 then fl2:=cons('times,fl2);
%   if not fl1 then fl1:=1;
%   if not fl2 then fl2:=1;
%   list(fl1,fl2,neg)
% >>              else if my_freeof(p,v) and (not freeoflist(p,vl)) then
% list(p,1,neg)                                                  else
% list(1,p,neg)
%end$ % of fctrs
%

symbolic procedure fctrs(p,indep,v)$
begin scalar fl1,fl2;
 p:=cdr reval err_catch_fac p;
 for each el in p do
 if freeoflist(el,indep) and 
    ((v=nil) or (not my_freeof(el,v))) then fl1:=cons(el,fl1)
                                       else fl2:=cons(el,fl2);
 if null fl1 then fl1:=1;
 if null fl2 then fl2:=1;
 if pairp fl1 then if length fl1 = 1 then fl1:=car fl1
                                     else fl1:=cons('times,fl1);
 if pairp fl2 then if length fl2 = 1 then fl2:=car fl2
                                     else fl2:=cons('times,fl2);
 return list(fl1,fl2)
end$ % of fctrs


symbolic procedure extractfac(p,indep,v)$
% looks for factors of p dependent of v and independent of indep 
% and returns a list of the numerator factors and a list of the 
% denominator factors
begin scalar nu,de$
 return
 if (pairp p) and (car p='quotient) then
 <<nu:=fctrs( cadr p,indep,v);
   de:=fctrs(caddr p,indep,v);
   list( reval if car  de neq 1 then list('quotient,  car nu,  car de)
                                else car nu,
               if cadr de neq 1 then list('quotient, cadr nu, cadr de)
                                else cadr nu
       )
 >>                                 else fctrs(p,indep,v)
end$ % of extractfac

%----------------------------

symbolic procedure get_kernels(ex)$
% gets the list of all kernels in ex
begin scalar res,pri$
 % pri:=t;
 ex:=reval ex$
 if pri then <<terpri()$write"ex=",ex>>;
 if pairp ex then
 if (car ex='quotient) or (car ex='plus) or (car ex='times) then 
 for each s in cdr ex do res:=union(get_kernels s,res)      else 
 if (car ex='minus) or 
    ((car ex='expt)    and 
%    (numberp caddr ex)) then % not for e.g. (quotient,2,3)
     (cadr ex neq 'E)  and 
     (cadr ex neq 'e)  and 
     (not fixp cadr ex)   ) then res:=get_kernels cadr ex
                            else res:=list ex
             else if idp ex then res:=list ex$
 if pri then <<terpri()$write"res=",res>>;
 return res$
end$

%------------------

symbolic procedure specialsol(p,vl,fl,x,indep,gk)$
% tries a power ansatz for the functions in fl in the kernels 
% of p to make p to zero
% indep is a list of kernels, on which the special solution should
% not depend. Is useful, to reduce the search-space, e.g. when an
% integrating factor for a linear equation for, say f, is to be
% found then f itself can not turn up in the integrating factor fl
% gk are kernels which occur in p and possibly extra ones which
% e.g. are not longer in p because of factorizing p but which are
% likely to play a role, if nil then determined below
% x is a variable on which each factor in the special solution has
% to depend on.
begin
 scalar e1,e2,n,nl,h,hh,ai,sublist,eqs,startval,pri,printold,pcopy;
% pri:=t;
 p:=num p;
 pcopy:=p;
 if pri then <<
  terpri()$write"The equation for the integrating factor:"; 
  terpri()$eqprint p;
 >>;
 if null gk then gk:=get_kernels(p);
 for each e1 in fl do <<
  h:=nil; %---- h is the power ansatz
  if pri then
  for each e2 in gk do <<
   terpri()$write"e2=",e2;
   if my_freeof(e2,x) then write" freeof1";
   if not freeoflist(e2,fl) then write" not freeoflist"$
   if not freeoflist(e2,indep) then write" dependent on indep"
  >>;
  %----- nl is the list of constants to be found
  for each e2 in gk do
  if (not my_freeof(e2,x)) and % integ. fac. should depend on x
     freeoflist(e2,fl)  and % the ansatz for the functions to be
                            % solved should not include these functions
     freeoflist(e2,indep) then <<
   n:=gensym();nl:=cons(n,nl);
   h:=cons(list('expt,e2,n),h); 
  >>;
  if h then <<
   if length h > 1 then h:=cons('times,h)
                   else h:=car h;
   %-- the list of substitutions for the special ansatz
   sublist:=cons((e1 . h),sublist);
   if pri then <<terpri()$write"Ansatz: ",e1," = ",h>>;
   p:= reval num reval subst(h,e1,p);
   if pri then <<terpri()$write"p=";eqprint p>>
  >>
 >>;
 if null h then return nil;
 %------- An numerical approach to solve  for the constants
 if nil then << % numerical approach
  %--- Substituting all kernels in p by numbers
  on rounded;
  precision 20;
  terpri()$terpri()$write"Before substituting numerical values:";
  eqprint p;
  terpri()$terpri()$write"Constants to be calculated: ";
  for each n in nl do write n,"  ";
 
  for each e1 in nl do <<
   h:=p;
   for each e2 in gk do 
   if freeoflist(e2,fl) then
   if pairp e2 and ((car e2 = 'df) or (car e2 = 'int)) then <<
    n:=list('quotient,1+random 30028,30029);
    terpri();write"substitution done: ",e2," = ",n;
    h:=subst(list('quotient,1+random 30028,30029),e2,h)
   >>;
   for each e2 in gk do 
   if freeoflist(e2,fl) then
   if not(pairp e2 and ((car e2 = 'df) or (car e2 = 'int))) then <<
    n:=list('quotient,1+random 30028,30029);
    terpri();write"substitution done: ",e2," = ",n;
    h:=subst(list('quotient,1+random 30028,30029),e2,h)
   >>;

   terpri()$terpri()$write"The equation after all substitutions: ";
   terpri()$
   eqprint h;

   eqs:=cons(reval h,eqs);
   startval:=cons(list('equal,e1,1),startval)
  >>;
  if length eqs = 1 then eqs:=cdr eqs
                    else eqs:=cons('list,eqs);
  if length startval = 1 then startval:=cdr startval
                         else startval:=cons('list,startval);
  terpri()$write"start rdsolveeval!";terpri()$terpri()$
  h:=rdsolveeval list(eqs,startval);
  eqs:=nil;
  off rounded;
 >>;

 %----- An analytical approach to solve for the constants
 if null pri then <<printold:=print_;print_:=nil>>;
 if p and not zerop p then                  % uebernommen aus SEPAR
 if not (pairp p and (car p='quotient) and  %      "       "    "
        intersection(argset smemberl(fl,cadr p),vl)) then 
 p:=separ2(p,fl,list x)                                  else 
 p:=nil;
 if null pri then print_:=printold;

 if p then <<
  % possibly investigating linear dependencies of different caar p
  % solve(lasse x-abhaengige und nl-unabhaengige faktoren fallen von
  %       factorize df(reval list('quotient, caar p1, caar p2),x),nl).
  while p do 
  if freeoflist(cdar p,nl) then <<eqs:=nil;p:=nil>>
  % singular system --> no solution 
                           else <<
   eqs:=cons(cdar p,eqs);
   p:=cdr p
  >>;
 >>;
 if pri then <<terpri()$write"eqs1=",eqs>>;
 if (null eqs) or (length eqs > maxalgsys_) then return nil
                                            else <<
  if pri then <<
   terpri()$write"The algebraic system to solve for ",nl," is:";
   if length eqs > 1 then deprint eqs
                     else eqprint car eqs
  >>;
  if length eqs > 1 then eqs:=cons('list,eqs)
                    else eqs:=car eqs;

  if pri then <<terpri()$write"eqs2=",eqs;terpri();write"nl=",nl>>$

  % for catching the error message `singular equations'
  hh:=cons('list,nl);
  eqs:=<<   
   ai:=!!arbint;
   err_catch_solve(eqs,hh)
  >>;

  if pri then <<terpri()$write"eqs3a=",eqs,"  ai=",ai,"  !!arbint=",
                !!arbint;terpri()>>$
  if not freeof(eqs,'arbcomplex) then <<
   eqs:=reval car eqs;
   for h:=(ai+1):!!arbint do
   eqs:=subst(0,list('arbcomplex,h),eqs);
   if pri then <<terpri()$write"eqs3b=",eqs;terpri()>>$
   eqs:=err_catch_solve(eqs,hh)
  >>;

  if pri then <<terpri()$write"eqs3c=",eqs;terpri()>>$

  %--- eqs is the list of solutions for the constant exponents of the
  %--- integrating factor

  if null eqs then return nil;
  if length nl=1 then eqs:=list eqs;
  if pri then <<write"nl=",nl,"  eqs4=",eqs;terpri()>>;

  for each e1 in eqs do <<  % each e1 is a list of substitutions
   if pri then <<terpri()$write"e2=",e1;terpri()>>$
   if car e1='list then e1:=cdr e1;
   if pri then <<terpri()$write"e3=",e1;terpri()>>$
   for each e2 in e1 do <<
    if pri then algebraic write"solution:",symbolic e2;
    sublist:=subst(caddr e2,cadr e2,sublist)
   >>;
   if pri then <<terpri()$write"The sublist is:",sublist>>
  >>;
 >>;
 if pri then <<terpri()$write"pcopy1=",pcopy;terpri()>>$
 for each e1 in sublist do <<
  pcopy:=subst(cdr e1,car e1,pcopy);
  if pri then <<terpri()$write"e1=",e1;terpri();
                write"pcopy2=",pcopy;terpri()>>$
 >>$
 if pri then <<terpri()$write"pcopy3=",reval pcopy;terpri()>>$
 if pri then <<terpri()$write"pcopy4=",reval reval pcopy;terpri()>>$
 if not zerop reval reval pcopy then return nil else
 return for each e1 in sublist collect (car e1 . reval cdr e1)
end$   % of specialsol

%------------------

symbolic procedure add_factors(gk,p)$
% gk is a list of factors and p anything but a quotient
if null p then gk else
if (  not  pairp p         ) or 
   ((      pairp p   ) and 
    (car p neq 'times)     ) then 
union(list if (pairp p) and (car p = 'minus) then cadr p
                                             else      p,gk) else
<<for each h in cdr p do 
  gk:=union(list if (pairp h) and (car h = 'minus) then cadr h
                                                   else      h,gk);
  gk
>>$

%------------------

symbolic operator findintfac$
symbolic procedure findintfac(pl,ftem,vl,x,doneintvar,intfacdep,
                              factr,verbse)$

% - pl is a list of equations from which the *-part (inhomogeneous
%   terms) have been dropped.
% - each equation of pl gets an integrating factor h
% - doneintvar is a list of variables, on which the integrating factor
%   should not depend. The chances to find an integrating factor
%   increase if the inhomogeneous part of pl is dropped and
%   separately integrated with generalized integration later.
% - if factr is not nil then the equation(s) pl is(are) at first
%   factorized, e.g. if integration(s) have already been done
%   and there is a chance that the equation can factorize, thereby
%   simplify and giving a higher chance for integrability.

begin
 scalar h,newequ,tozero,fl,e1,pri,factr,exfactors,ftr,gk,precise_old,
        carftr,zd;
 % exfactors is the list of factors extracted at the beginning
 % pri:=t;

 precise_old:=!*precise$
 !*precise:=nil$

 factr:=t; % whether tozero should be factorized
 if pri then <<terpri()$write"START VON FINDINTFAC">>;
 %--- Generation of the condition for the integrating factor(s) in fl
 for each e1 in pl do <<
  %--- extracting factors dependend on x and independent of
  %--- doneintvar but only if integrations have already been done,
  %--- i.e. (doneintvar neq nil)
  gk:=union(gk,get_kernels(e1));
  if factr then <<ftr:=extractfac(e1,append(doneintvar,ftem),x);
                  carftr:=car ftr;
                  if not evalnumberp carftr then 
                  if (pairp carftr) and 
                     (car carftr='quotient) then
                  gk:=add_factors(add_factors(gk,cadr carftr),
                                  caddr carftr                ) else
                  gk:=add_factors(gk,carftr);
                >>
           else ftr:=list(1,nil);
  exfactors:=cons(car ftr,exfactors);
  if car ftr neq 1 then <<
   e1:=cadr ftr;
   if pri then <<terpri()$write"extracted factor:",eqprint car ftr>>;
  >>;
  %--- fl is to become the list of integrating factors h
  h:=gensym();
  depl!*:=cons(list(h,x),depl!*)$
  depend h,x;
  fl:=h . fl;
  e1:=intpde(reval list('times,h,e1),ftem,vl,x,t);
  if e1 and car e1 then <<
   newequ:=car e1 . newequ;
   tozero:=cadr e1 . tozero;
   if pri then <<
    terpri()$write" the main part of integration:"$ eqprint(car e1);
    terpri()$write"car e1=",car e1;
    terpri()$write" the remainder of integration:"$ eqprint(cadr e1);
    terpri()$write"cadr e1=",cadr e1;
   >>
  >>;
 >>;
 if null tozero then return nil;
 %-------- newequ is the integral
 newequ:=if length pl > 1 then cons('plus,newequ)
                          else car newequ;
 %-------- tozero is the PDE for the integrating factor
 tozero:=reval if length pl > 1 then cons('plus,tozero)
                                else car tozero;
 
 if pairp tozero and (car tozero='quotient) then tozero:=cadr tozero$

 if factr then <<
  h:=cdr err_catch_fac(tozero)$
  if h then << % else factorization too long
   if pri then <<terpri()$write"The factors of tozero:",h>>;
   tozero:=nil;
   for each e1 in h do
   if smemberl(fl,e1) then tozero:=cons(e1,tozero)$
   tozero:= reval if length tozero > 1 then cons('times,tozero)
                                       else car tozero
  >>
 >>;

 if nil and pri then <<write"tozero =";eqprint tozero >>;
 h:=nil;
 % actually only those f in ftem, in which pl is nonlinear, but also
 % then only integrating factors with a leading derivative low enough
 h:=specialsol(tozero,vl,fl,x,append(ftem,doneintvar),gk);
 % h:=specialsol(tozero,vl,fl,x,doneintvar,gk);
 if pri then <<write"h=",h;terpri()>>;
 if h then <<
  for each e1 in h do << % each e1 is one integrating factor determined
   if pri then <<terpri()$write"e1=",e1;
                   terpri()$write"newequ=",newequ;terpri()>>;
   newequ:=reval subst(cdr e1,car e1,newequ);
   if pri then <<terpri()$write"newequ=",newequ>>;
  >>
 >>   else if pri then write"no integrating factor";

 %--- delete all dependencies of the functions in fl
 %--- must come before the following update
 for each e1 in fl do <<
   depl!*:=delete(assoc(e1,depl!*),depl!*)$
   depl!*:=delete(assoc(mkid(e1,'_),depl!*),depl!*)$
 >>;
  
 %--- update intfacdep
 for each e1 in vl do
 if (e1 neq x) and my_freeof(intfacdep,e1) and
    ((not my_freeof(h,e1)) or (not my_freeof(exfactors,e1)))
 then intfacdep:=cons(e1,intfacdep);

 %--- returns nil if no integrating factor else a list of the
 %--- factors and the integral
 if h and print_ and verbse then <<
  terpri()$write"The integrated equation: ";
  eqprint newequ;
  terpri()$
  if length pl = 1 then write"An integrating factor has been found:"
                   else write"Integrating factors have been found: "$
 >>;
 !*precise:=precise_old$

 if (null h) or (zerop newequ) then return nil$

 % test for zero denominators
 zd:=zero_den(h,ftem); 
 if zd then return <<
  % no constants of integration have been added yet so 
  % added cases do not involve constants of integration
  for each e1 in zd do 
  % <<write"DDDD"$terpri()$
  to_do_list:=union({list('split_into_cases,e1)},to_do_list);
  % >>$
  nil
 >>$

 return 
 list(newequ,
      for each e1 in h collect <<
       ftr:=car exfactors;
       exfactors:=cdr exfactors;
       gk:=if ftr=1 then cdr e1
                    else reval list('quotient,cdr e1,ftr);
       if print_ and verbse then mathprint gk;
       gk
      >>,
      intfacdep)
end$ % findintfac

endmodule$


%********************************************************************
module odeintegration$
%********************************************************************
%  Routines for integration of ode's containing unnown functions
%  Author: Thomas Wolf
%  August 1991

symbolic procedure integrateode(de,fold,xnew,ordr,ftem)$
begin scalar newde,newnewde,l,h,newcond$ 
  h:= % the integrated equation
  if not xnew then <<    % Integr. einer alg. Gl. fuer eine Abl.
   % The following call of solveeval is taken out as it might
   % potentially loose cases for non-linear problems.
   % It definitely drops constant ftem-dependent factors which
   % correspond to a loss of cases which could be fixed through
   % testing : if pairp de and car de = 'times then newde:=de else ...

   %newde:=cadr solveeval list(de,fold)$
   %if not freeof(newde,'ROOT_OF) then nil
   %                                  else <<
   % newde:=reval list('plus,cadr newde,list('minus,caddr newde))$
   % if (l:=integratepde(newde,ftem,nil,genint_,nil)) then 

    if (l:=integratepde(de,ftem,nil,genint_,nil)) then 
    <<newcond:=append(newcond,cdr l);car l>>
                %genflag=t,potflag=nil        
                                                  else nil
   % >>
  >>         else                % eine ode fuer ein f?
  if not pairp fold then         % i.e. not df(...,...), i.e. fold=f
  if (l:=odeconvert(de,fold,xnew,ordr,ftem)) then
  <<newcond:=append(newcond,cdr l);car l>>   else nil
                                 % --> ode fuer eine Abl. von f
                    else <<
   newde:=if (l:=odeconvert(de,fold,xnew,ordr,ftem)) then
          <<newcond:=append(newcond,cdr l);car l>>   else nil$
   if not newde then nil
                else <<
     % Similarly to above for safety reasons and currently the
     % inability to handle more than one solution the following 
     % solveeval is commented out

     % newnewde:=cadr solveeval list(newde,fold)$
     % newnewde:=reval list('plus,cadr newnewde,list('minus,
     %                                                   caddr newnewde))$
     ftem:=union(fnew_,ftem)$
     % newnewde:=integratede(newnewde,ftem,nil)$
     newnewde:=integratede(newde,ftem,nil)$
     if newnewde then <<newcond:=append(newcond,cdr newnewde);
                        car newnewde>>
                 else newde 
   >>
  >>;

 return if not h then nil          
                 else cons(h,newcond) 

end$  % of integrateode

symbolic procedure odecheck(ex,fint,ftem)$
% assumes an reval'ed expression ex
% Goes wrong if car ex is a list of expressions!
begin scalar a,b,op,ex1$
                   %***** ex is a ftem-function *****
 if ex=fint then             % list(ex,0,0,..)
   <<a:=list ex$
     ex:=fctargs ex$
     while ex do
      <<a:=append(list(0,0),a)$
      ex:=cdr ex>>$
      % not checked if it is a function of an expression of x
     op:=reverse a>>
 else if pairp ex then
                          %***** car ex is 'df *****
 if (car ex)='df then
  <<a:=odecheck(cadr ex,fint,ftem)$
  if not pairp a then op:=a
  else                            % a is list(fctname,0,0,..,0,0)
   <<op:=list(car a)$
   a:=fctargs car a$              % a is list(variables), not checked
   ex:=cddr ex$                   % ex is list(derivatives)
   while a do
    <<ex1:=ex$
    while ex1 and ((car a) neq (car ex1)) do ex1:=cdr ex1$
    if null ex1 then op:=cons(0,cons(0,op))
    else
     <<if not cdr ex1 then b:=1   % b is number of deriv. of that var.
     else
      <<b:=cadr ex1$
      if not numberp b then b:=1>>$
     op:=cons(b,cons(b,op))>>$
    a:=cdr a>>$
   op:=reverse op>> >>
 else
             %***** car ex is a standard or other function *****
  <<a:=car ex$                    % for linearity check
  ex:=cdr ex$
  if a='int then ex:=list reval car ex$
  while (op neq '!_abb) and ex do
   <<b:=odecheck(car ex,fint,ftem)$
   if b then                                  % function found
     if b eq '!_abb then op:='!_abb           % occures properly
                    else op:=odetest(op,b)$
   ex:=cdr ex>> >>$
 return op
end$

symbolic procedure integrableode(p,ftem)$
if % length get(p,'derivs) ?
   delength p 
   >(if odesolve_ then odesolve_ else 0) then
   (if cont_ then
      if yesp("expression to be integrated ? ") then
           integrableode1(p,ftem)) 
else integrableode1(p,ftem)$ 

symbolic procedure integrableode1(p,ftem)$
begin scalar a,b,u,vl,le,uvar,
           fint,fivar,% the function to be integrated and its variables
           fold,      % the new function of the ode
           xnew,      % the independ. variable of the ode
           ordr1,     % order of the ode
           ordr2,     % order of the derivative for which it is an ode
           intlist$   % list of ode's
  ftem:=smemberl(ftem,p)$
  vl:=argset ftem$
% p muss genau eine Funktion aus ftem von allen Variablen enthalten.
% Die Integrationsvariable darf nicht Argument anderer in p enthaltener
% ftem-Funktionen sein.
  a:=ftem$
  b:=nil$
  le:=length vl$
  while a and vl do
    <<u:=car a$  
    uvar:=fctargs u$
    if (length uvar) = le then
       if b then 
          <<vl:=nil$a:=list(nil)>>
       else
          <<b:=t$
          fint:=u$
          fivar:=uvar>>
    else vl:=setdiff(vl,uvar)$
    a:=cdr a>>$

  if not b then vl:=nil$
  le:=length p$
  if ((1<le) and vl) then <<
    a:=odecheck(p,fint,ftem)$
    if not atom a then <<                    % The equation is an ode
      ordr1:=0$
      ordr2:=0$
      xnew:=nil$
      a:=cdr a$
      b:=fivar$
      while b do
        <<if (car a) neq 0 then
           <<fold:=cons(car b,fold)$
           if (car a) > 1 then fold:=cons(car a,fold)>>$
        ordr2:=ordr2+car a$
        if (car a) neq (cadr a) then
           <<xnew:=car b$
           if not member(xnew,vl) then
              <<b:=list(nil)$vl:=nil>>$
           ordr1:=(cadr a) - (car a)>>$
        b:=cdr b$
        a:=cddr a>>$
      fold:=reverse fold$
        %fold is the list of diff.variables + number of diff.
      if fold then fold:=cons('df,cons(fint,fold))
              else fold:=fint$
      if vl and ((ordr1 neq 0) or (ordr2 neq 0)) then
        intlist:=list(fold,xnew,ordr1,ordr2)
    >>     % of variable found
  >>$    % of if
  return intlist
end$  % of integrableode1

symbolic procedure odetest(op,b)$
if not op then b
else                           % op=nil --> first function found
  if (car op) neq (car b) then '!_abb else  % f occurs in differ. fct.s
begin scalar dif,a$
 dif:=nil$                     % dif=t --> different derivatives
 a:=list(car op)$              % in one variable already found
 op:=cdr op$
 b:=cdr b$
 while op do
  <<a:=cons(max(cadr op,cadr b),cons(min(car op,car b),a))$
  if (car a) neq ( cadr a) then
  if dif then
    <<a:='!_abb$
    op:=list(1,1)>>
  else dif:=t$
  op:=cddr op$
  b:=cddr b>>$
 if not atom a then a:=reverse a$
 return a      % i.e. '!_abb or  (fctname,min x1-der.,max x1-der.,...)
end$

symbolic procedure odeconvert(de,ford,xnew,ordr,ftem)$
begin scalar j,h,h1,h2,t2,ford_,newco,oldde,newde,newvl,null_,ruli,ld$
%             trig1,trig2,trig3,trig4,trig5,trig6,zd$
 ford_:=gensym()$
 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 depend1(ford_,xnew,t)$
 oldde:=reval subst(ford_,reval ford,de)$
 if pairp ford then                 % i.e.  (car ford) eq 'df then
 << for j:=1:ordr do
   oldde:= reval subst( reval list('df,ford_,xnew,j),
                        reval list('df,ford,xnew,j), oldde)>>$
 algebraic !!arbconst:=0$
 %newde:=algebraic(first odesolve(symbolic oldde,symbolic ford_,symbolic xnew))$
 %newde:=algebraic(first lisp err_catch_odesolve(oldde,ford_,xnew))$

 newde:=err_catch_odesolve(oldde,ford_,xnew)$
 if newde and (car newde='list) and cdr newde and cddr newde then return <<
  if print_ then <<terpri()$
   write "The ode has more than one solution."$
   algebraic write "Equation is: ",algebraic symbolic oldde$
   algebraic write "Solution is: ",algebraic symbolic newde
  >>;
  nil
 >>                                                          else
 newde:=cadr newde$

 if null newde then return nil;

 % Check that the coefficient of the highest power of the highest derivative
 % is not free of ftem functions/constants as there can be cases when
 % ford_ can have an arbitrary value because all terms with ford_ or a
 % derivative of ford_ vanishes and the solution of the ODE does not 
 % involve quotients or logarithms so special cases would not be found to
 % be investigated.
 ld:=reval {'df,ford_,xnew,ordr}$
 h:=algebraic(coeff(lisp oldde,lisp ld));
 while cdr h do h:=cdr h$
 h:=simp car h;
 h:=simplifySQ(h,ftem,t,nil,t)$ 
 if null cdr h then h:=car h
               else <<
  j:=car h; h:=cdr h$
  while h do <<
   j:=multsq(car h,j)$ h:=cdr h
  >>$
  h:=j
 >>$

 if not freeoflist(h,ftem) and not member(h,ineq_) then return <<
  % This case can be added because h does not contain new
  % constants of integration.
  to_do_list:=cons(list('split_into_cases,h),to_do_list);
  nil
 >>$

 % Check the case that newde has the form
 % (equal ford_ (equal .. ..)) 
 % where .. includes ford_
 % which is an error of ODESOLVE
 if pairp newde and
    car newde = 'equal and

    pairp cdr newde and 
    cadr newde = ford_ and

    pairp cddr newde and
    pairp caddr newde and

    caaddr newde = 'equal  then 

    if freeof(caddr newde,ford_) then newde:=nil
                                 else <<
  h:=solveeval {{'list,{'difference,cadr caddr newde,caddr caddr newde}},
                {'list,ford_}};
  if (not freeof(h,'i)) or (not freeof(h,'!:gi!:)) then algebraic(on complex)$
  if pairp h and (car h = 'list) and (pairp cadr h) and 
     (caadr h = 'equal) and (cadadr h = ford_) then newde:=cadr h
 >>$

 % if newde is a parametric solution, i.e. has the form 
 % (list (equal ford_ ...) (equal xnew ...) arbparam(1))
 if pairp newde and
    car newde = 'list and

    pairp cdr newde and 
    pairp cadr newde and
    caadr newde = 'equal and
    cadadr newde = ford_ and 

    pairp cddr newde and
    pairp caddr newde and
    caaddr newde = 'equal and
    car cdaddr newde = xnew and 

    pairp cdddr newde and null
    cddddr newde then <<

  h:=solveeval {{'list,{'difference,cadr caddr newde,caddr caddr newde}},
                {'list,cadddr newde}};

  if (not freeof(h,'i)) or (not freeof(h,'!:gi!:)) then algebraic(on complex)$
  if pairp h and (car h = 'list) and (pairp cadr h) and 
     (caadr h = 'equal) and (cadadr h = cadddr newde) then 
  newde:={'equal,ford_,subst(car cddadr h,cadadr h,car cddadr newde)}
 >>;

 % if the solution is a list of 2 solutions, i.e. a case distinction 
 % would be necessary then currently these solutions are only printed 
 % and can not be used.
 if pairp newde and
    car newde = 'list and

    pairp cdr newde and 
    pairp cadr newde and
    caadr newde = 'equal and
%    cadadr newde = ford_ and 

    pairp cddr newde and
    pairp caddr newde and
    caaddr newde = 'equal and
%    car cdaddr newde = xnew 
    car cdaddr newde = cadadr newde 

 then return <<
  if print_ then <<terpri()$
   write "The ode has more than one solution."$
   algebraic write "Equation is: ",algebraic symbolic oldde$
   algebraic write "Solution is: ",algebraic symbolic newde
  >>;
  nil
 >>$

 ruli:= start_let_rules()$

 if newde then 
 if !*rational then << off rational; newde:=reval newde; on rational>>
 else newde:=reval newde;

 % It the solution has the form {'equal,expression,0} then solve the
 % numerator of expression for ford_ .

 if newde and 
    (car newde='equal) and 
    (caddr newde=0) then newde:={'equal,reval num cadr newde,0};

 % Update of flin_
 if flin_ and
    newde and
    (car newde='equal) then 

 if not freeoflist(cadr newde,flin_) then <<
  % The function that is solved for is a non-linearly occuring function
  % and therefore all occuring functions are now deleted from flin_.
  h1:=flin_;
  for each h in h1 do 
  if not freeof(newde,h) then flin_:=delete(h,flin_)
 >>                                  else << 

  % Are there flin_ constants/functions which do not occure linearly anymore?
  j:=nil;
  h1:=flin_;
  for each h in h1 do 
  if not freeof(newde,h) then 
  if null lin_check(caddr newde,{h}) then flin_:=delete(h,flin_)
                                     else j:=cons(h,j);
  if j and cdr j then 
  if null lin_check(caddr newde,j) then 
  for each h in j do flin_:=delete(h,flin_)$
 >>$

 j:=zero_den(subst(ford,ford_,newde),cons(ford_,ftem)); %,argset ftem
 if null j and not freeoflist(caddr newde,ftem_) then
 j:=ProportionalityConditions(caddr newde,
                              for h1:= 1 : (algebraic !!arbconst)
                              collect list('arbconst,h1), xnew)$
 if j then return 
 if t then nil 
      else <<

  % The following makes only sense if the special case to be investigated
  % involves constants of integration. But then these case distinctions
  % can not be set up because the the new constants of integration are not
  % known after leaving this integration module.
  % possible solution: either adding fnew_ to ftem even if no integrated
  % equation is returned, or returning a product of the integrated
  % equation and the expressions in j.

  newvl:=delete(xnew,if (pairp ford and (car ford='df))
                        then fctargs cadr ford
                        else fctargs ford)$

  for h1:=1 : algebraic !!arbconst do 
  if not freeof(j,list('arbconst,h1)) then <<
   newco:=newfct(fname_,newvl,nfct_)$
   nfct_:=add1 nfct_$
   fnew_:=cons(newco,fnew_)$
   j:=for each h in j collect subst(newco,list('arbconst,h1),h)
  >>$

  while j do <<
   if freeoflist(car j,fnew_) and not member(car j,cdr j) then
   to_do_list:=cons(list('split_into_cases,car j),to_do_list);
   j:=cdr j
  >>$
  nil
 >>$

 % if safeint_ and zero_den(newde,ftem,argset ftem) then newde:=nil;
 if freeint_ and null freeof(newde,'int) then newde:=nil;
 if freeabs_ and null freeof(newde,'abs) then newde:=nil;
 if newde and (cadr newde neq oldde) then <<   % solution found
  % Test der Loesung klappt nur, wenn Loesung explizit gegeben
  if cadr newde neq ford_ then <<
   if print_ then <<terpri()$
    write "Solution of the ode is not explicitly given."$
    algebraic write "Equation is: ",algebraic symbolic oldde$
    algebraic write "Solution is: ",algebraic symbolic newde
   >>;
   if poly_only then % The solution must be rational in the
                     % function and constants of integration
   if not rationalp(newde,ford_) then newde:=nil else <<
    j:=1;
    while (j leq ordr) and  
          rationalp(subst(ford_,list('arbconst,j),newde),ford_) do j:=j+1;
    if j leq ordr then newde:=nil
   >>;
   if pairp newde and (car newde = 'equal) then
   if (pairp cadr newde) and 
      (caadr newde = 'quotient) and 
      (zerop caddr newde) then newde:={'equal,cadadr newde,0}
                          else
   if (pairp caddr newde) and
      (caaddr newde = 'quotient) and 
      (zerop cadr newde)  then newde:={'equal,0,cadr caddr newde}
                          else <<
    % If it is linear in one arbcons(i) and the second terms in the
    % expression is a sqrt or tan or arctan,... then delete this function.
    % Example: arbconst(1) + sqrt(g0785**2  + u1**2 )=0
    h1:=reval {'difference,cadr newde,caddr newde};
    j:=1;
    while (j leq ordr) and  
          (freeof(h1,list('arbconst,j)) or
           (not lin_check(h1,list list('arbconst,j)))) do j:=j+1;
    if j leq ordr then <<
     h:=coeffn(h1,list('arbconst,j),1)$
     t2:=reval {'quotient,{'difference,{'times,list('arbconst,j),h},h1},h};
     h2:={'equal,{'plus,list('arbconst,j),
                  simplifiziere(t2,cons(ford_,cons(xnew,ftem)),nil)},0}$
     if h2 neq newde then <<
      newde:=h2$
      if print_ then 
      algebraic (write "The solution is modified to: ",symbolic newde)
     >>
    >>
   >>
  >>                      else <<
   null_:=simp!* reval subst(caddr newde, ford_, oldde)$  
   if not sqzerop null_ then <<
    if print_ then <<
     write "odesolve solves :  "$
     deprint list oldde$
     write "to"$
     eqprint newde$
     Write "which inserted in the equation yields "$
     eqprint {'!*sq,null_,t}
    >>
   >>
  >>
 >>$

 if newde then
 <<newde:=list('plus,cadr newde,list('minus,caddr newde))$
   if zerop reval list('plus,newde,list('minus,oldde)) then newde:=nil$
   % not anymore needed after writing to to_do_list
   % if newde and (zd neq nil) then 
   % newde:=cons('times,append(zd,list newde))$
 >>$

 depl!*:=delete(assoc(ford_,depl!*),depl!*)$
 stop_let_rules(ruli)$
 return
 if null newde then nil
               else
 <<newde:=subst(ford,ford_,newde)$
   newvl:=delete(xnew,if (pairp ford and (car ford='df))
                         then fctargs cadr ford
                         else fctargs ford)$
%   if pairp ford then newvl:=delete(xnew,cdr assoc(cadr ford,depl!*))
%                 else newvl:=delete(xnew,cdr assoc(ford,depl!*))$

   for j:=1 : algebraic !!arbconst do 
   if not freeof(newde,list('arbconst,j)) then <<
    newco:=newfct(fname_,newvl,nfct_)$
    nfct_:=add1 nfct_$
    fnew_:=cons(newco,fnew_)$
    newde:=subst(newco,list('arbconst,j),newde)$
    if lin_check(newde,{newco}) then flin_:=fctinsert(newco,flin_)$
   >>$
   {newde}
 >>
end$

endmodule$

%********************************************************************
module jetdifferentiation$
%********************************************************************
%  Routines supporting liepde and conlaw
%  Author: Thomas Wolf
%  1998

%-------------

symbolic procedure comparedif1(u1l,u2l)$
% checks whether u2l has more or at least equally many 1's, 2's, ...
% contained as u1l.
% returns a list of 1's, 2's, ... which are in excess in u2l
% compared with u1l. The returned value is 0 if both are identical
begin
 scalar ul;
 if u2l=nil then if u1l neq nil then return nil 
                                else return 0
            else if u1l=nil then return u2l
                            else % both are non-nil
 if car u1l < car u2l then return nil else 
 if car u1l = car u2l then return comparedif1(cdr u1l,cdr u2l) else <<
  ul:=comparedif1(u1l,cdr u2l);
  return if not   ul then nil          else 
         if zerop ul then list car u2l else
                          cons(car u2l,ul)
 >>
end$ % of comparedif1

%-------------

symbolic procedure comparedif2(u1,u1list,du2)$
% checks whether du2 is a derivative of u1 differentiated
% wrt. u1list
begin
 scalar u2l;
 u2l:=combidif(du2)$ % u2l=(u2, 1, 1, ..)
 if car u2l neq u1 then return nil else
 return comparedif1(u1list, cdr u2l)
end$ % of comparedif2

%-------------

symbolic procedure listdifdif1(du1,deplist)$
% lists all elements of deplist which are *not* derivatives
% of du1
begin
 scalar u1,u1list,res,h$
 h:=combidif(du1);
 u1:=car h;
 u1list:=cdr h;
 for each h in deplist do
 if not comparedif2(u1,u1list,h) then res:=cons(h,res);
 return res
end$ % of listdifdif1

%-------------

symbolic procedure diffdeg(p,v)$
%   liefert Ordnung der Ableitung von p nach v$
%   p Liste Varible+Ordnung der Ableitung, v Variable (Atom)
if null p then 0                        %  alle Variable bearbeitet ?
else if car p=v then                    %  v naechste Variable ?
     if cdr p then
        if numberp(cadr p) then cadr p  %  folgt eine Zahl ?
                                else 1
        else 1
     else diffdeg(cdr p,v)$             %  weitersuchen

%-------------

symbolic procedure ldiff1(l,v)$
%  liefert Liste der Ordnungen der Ableitungen nach den Variablen aus v
%  l Liste (Variable + Ordnung)$ v Liste der Variablen
if null v then nil                      %  alle Variable abgearbeitet ?
else cons(diffdeg(l,car v),ldiff1(l,cdr v))$
                                        %  Ordnung der Ableitung nach
                                        %  erster Variable anhaengen

%-------------

symbolic procedure ldifftot(p,f)$
%  leading derivative total degree ordering
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ldifftot1(p,f,fctargs f)$

%-------------

symbolic procedure ldifftot1(p,f,vl)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion, lv Variablenliste
begin scalar a$
  a:=cons(nil,0)$
  if not atom p then
%    if member(car p,list('expt,'plus,'minus,'times,
%                         'quotient,'df,'equal)) then
    if member(car p,REDUCEFUNCTIONS_) then
                                        %  erlaubte Funktionen
    <<if (car p='plus) or (car p='times) or 
         (car p='quotient) or (car p='equal) then
      <<p:=cdr p$
        while p do 
        <<a:=diffreltot(ldifftot1(car p,f,vl),a,vl)$
          p:=cdr p
        >> 
      >>                      else 
      if car p='minus then a:=ldifftot1(cadr p,f,vl) else 
      if car p='expt then               %  Exponent
%      if numberp caddr p then
%      <<a:=ldifftot1(cadr p,f,vl)$
%        a:=cons(car a,times(caddr p,cdr a))
%      >>                 else a:=cons(nil,0)
      <<a:=ldifftot1(cadr p,f,vl)$
        if (numberp caddr p) and
           (numberp cdr a) then a:=cons(car a,times(caddr p,cdr a))
                           else a:=cons(car a,10000)
      >>
                                        %  Potenz aus Basis wird mit
                                        %  Potenz multipliziert
                     else 
      if car p='df then                 %  Ableitung
      if cadr p=f then a:=cons(cddr p,1)
                                        %  f wird differenziert?
                  else a:=cons(nil,0)
                   else                 %  any other non-linear function
      <<p:=cdr p$
        while p do 
        <<a:=diffreltot(ldifftot1(car p,f,vl),a,vl)$
          p:=cdr p
        >>;
        a:=cons(car a,10000)
      >>  
    >> else                             %  sonst Konstante bzgl. f
               
    if p=f then a:=cons(nil,1)                %  Funktion selbst
           else a:=cons(nil,0)          %  alle uebrigen Fkt. werden
  else if p=f then a:=cons(nil,1)$        %  wie Konstante behandelt
  return a
end$

%-------------

symbolic procedure diffreltot(p,q,v)$
%   liefert komplizierteren Differentialausdruck$
if diffreltotp(p,q,v) then q
                      else p$

%-------------

symbolic procedure diffreltotp(p,q,v)$
%   liefert t, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
begin scalar n,m$
m:=eval(cons('plus,ldiff1(car p,v)))$
n:=eval(cons('plus,ldiff1(car q,v)))$
return
 if m<n then t
 else if n<m then nil
      else diffrelp(p,q,v)$
end$

%-------------

algebraic procedure subdif1(xlist,ylist,ordr)$
% A list of lists of derivatives of one order for all functions
begin
 scalar allsub,revx,i,el,oldsub,newsub;
 revx:=sqreverse xlist;
 allsub:={};
 oldsub:= for each y in ylist collect y=y;
 for i:=1:ordr do      %  i is the order of next substitutions
 <<oldsub:=for each el in oldsub join nextdy(revx,xlist,el);
   allsub:=sqcons(oldsub,allsub)
 >>;
 return allsub
end$

%-------------

algebraic procedure nextdy(revx,xlist,dy)$
% generates all first order derivatives of lhs dy
% revx = reverse xlist; xlist is the list of variables;
%                       dy the old derivative
begin
  scalar x,n,ldy,rdy,ldyx,sublist;
  x:=sqfirst revx; revx:=sqrest revx;
  sublist:={};
  ldy:=lhs dy;
  rdy:=rhs dy;
 
  while lisp(not member(prepsq simp!* algebraic x,
             prepsq simp!* algebraic ldy))
        and (revx neq {}) do 
  <<x:=sqfirst revx; revx:=sqrest revx>>;
 
  n:=length xlist;
  if revx neq {} then                % dy is not the function itself
  while sqfirst xlist neq x do xlist:=sqrest xlist;
  xlist:=reverse xlist;

  % New higher derivatives
  while xlist neq {} do
  <<x:=sqfirst xlist;
    ldyx:=df(ldy,x);
    sublist:=cons((lisp reval algebraic ldyx)=
                  mkid(mkid(rdy,!`),n), sublist);
    n:=n-1;
    xlist:=sqrest xlist
  >>;
  return sublist
end$

%-------------

symbolic operator totdeg$
symbolic procedure totdeg(p,f)$
%   Ordnung (total) der hoechsten Ableitung von f im Ausdruck p
eval(cons('plus,ldiff1(car ldifftot(reval p,reval f),fctargs reval f)))$

%-------------

symbolic procedure combidif(s)$
% extracts the list of derivatives from s: % u`1`1`2 --> (u, 1, 1, 2)
begin scalar temp,ans,no,n1;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;
  
  while not null temp do
  <<n1:=<<no:=nil;
          while (not null temp) and (not eqcar(temp,'!`)) do
          <<no:=car temp . no;temp:=cdr temp>>; 
          compress no
        >>;
    if (not fixp n1) then n1:=intern n1;
    ans:=n1 . ans;
    if eqcar(temp,'!`) then <<temp:=cdr temp; temp:=cdr temp>>;
  >>;
  return ans
end$

%-------------

symbolic operator dif$
symbolic procedure dif(s,n)$
% e.g.:   dif(fnc!`1!`3!`3!`4, 3) --> fnc!`1!`3!`3!`3!`4
begin scalar temp,ans,no,n1,n2,done;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;
  n2:=reval n;
  n2:=explode n2;

  while (not null temp) and (not done) do
  <<n1:=<<no:=nil;
          while (not null temp) and (not eqcar(temp,'!`)) do
          <<no:=car temp . no;temp:=cdr temp>>; 
          compress no
        >>;
    if (not fixp n1) or ((fixp n1) and (n1 leq n)) then
    <<ans:=nconc(n2,ans); ans:='!` . ans; ans:='!! . ans; done:=t>>;
    ans:=nconc(no,ans);
    if eqcar(temp,'!`) then <<ans:='!` . ans; ans:='!! . ans; 
                              temp:=cdr temp; temp:=cdr temp>>; 
  >>;
  return intern compress nconc(reverse temp,ans);
end$

%-------------

%symbolic operator totdif$
%symbolic procedure totdif(s,x,n,dylist)$
%% total derivative of s(x,dylist) w.r.t. x which is the n'th variable
%begin
%  scalar tdf,el1,el2;
%  tdf:=simpdf {s,x};
%  <<dylist:=cdr dylist;
%    while dylist do
%    <<el1:=cdar dylist;dylist:=cdr dylist;
%      while el1 do
%      <<el2:=car el1;el1:=cdr el1;
%        tdf:=addsq(tdf ,multsq( simp!* dif(el2,n), simpdf {s,el2}))
%      >>
%    >>
%  >>;
%  return prepsq tdf
%end$

put('totdif,'psopfn,'tot!*dif)$

symbolic procedure tot!*dif(inp)$
% total derivative of s(x,dylist) w.r.t. x which is the n'th variable
begin
  scalar tdf,el1,el2,s,x,n,dylist;
  s     :=    aeval    car inp$ s:=if pairp s and (car s='!*sq) then cadr s
                                                                else simp s;
  x     :=    reval   cadr inp$ if pairp x and (car x='!*sq) then x:=reval x;
  n     :=    reval  caddr inp$
  dylist:=cdr reval cadddr inp$
  tdf:=diffsq(s,x); 
  while dylist do
  <<el1:=cdar dylist;dylist:=cdr dylist;
    while el1 do
    <<el2:=car el1;el1:=cdr el1;
      tdf:= addsq(tdf, multsq( simp!* dif(el2,n), diffsq(s,el2)))
    >>
  >>;
  return {'!*sq, tdf, t}
end$

endmodule$

%********************************************************************
module divintegration$
%********************************************************************
%  Routines to write a given expression as divergence
%  Author: Thomas Wolf
%  1998

%-------------

%symbolic operator  combi$
symbolic procedure combi(ilist)$
% ilist is a list of indexes (of variables of a partial derivative)
% and returns length!/k1!/k2!../ki! where kj! is the multiplicity of j.
begin
  integer n0,n1,n2,n3;
  n1:=1;
%  ilist:=cdr ilist;
  while ilist do  
  <<n0:=n0+1;n1:=n1*n0;
    if car ilist = n2 then <<n3:=n3+1; n1:=n1/n3>>
                      else <<n2:=car ilist; n3:=1>>; 
    ilist:=cdr ilist>>;
  return n1
end$

%-------------

symbolic procedure sortli(l)$
% sort a list of numbers
begin scalar l1,l2,l3,m,n$
 return
 if null l then nil
           else <<
  n:=car l$
  l2:=list car l$
  l:=cdr l$
  while l do <<
   m:=car l$
   if m>n then l1:=cons(car l,l1)
          else if m<n then l3:=cons(car l,l3)
                      else l2:=cons(car l,l2)$
   l:=cdr l
  >>$
  append(sortli(l1),append(l2,sortli(l3)))
 >>
end$

%-------------

symbolic procedure derili(il)$
% make a derivative index list from a list of numbers
if null il then nil else
begin scalar h1,h2,h3$
 h1:=sortli(il);
 while h1 do <<
  h2:=reval algebraic mkid(!`,lisp car h1);
  h3:=if h3 then mkid(h2,h3)
            else h2;
  h1:=cdr h1
 >>;
 return h3
end$

%-------------

symbolic procedure newil(il,mo,nx)$
if (null il) or (length il<mo) then cons(1,il) else
if car il<nx then cons(add1 car il,cdr il) else
<<while il and (car il = nx) do il:=cdr il;
  if null il then nil 
             else cons(add1 car il,cdr il)>>$

%-------------

symbolic operator intcurrent1$
% used in conlaw2,4
symbolic procedure intcurrent1(divp,ulist,xlist,dulist,
                               nx,eqord,densord)$
% computes a list in reverse order from which the conserved
% current is computed through integration
begin scalar ii,il,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,contrace,u,
             nega,pii,mo,pl,nu$
 % contrace:=t;

 xlist:=cdr xlist;
 ulist:=cdr ulist;
 nu:=length ulist;
 mo:=if eqord>densord then eqord-1
                      else densord-1$

 pl:=for ii:=1:nx collect <<  % the components W^i
  il:=nil;
  pii:=nil;
  repeat <<
   h11:=cons(ii,il);
   h1:=derili(h11);
   h11:=combi(sortli(h11));
   if contrace then 
   <<write"==== ii=",ii,"  il=",il,"  h1=",h1,"  h11=",h11;terpri()>>;
   h2:=il;
   h3:=nil;
   if null h2 then h4:=list(nil . nil)
              else <<
    h4:=list(car h2 . nil);
    while h2 do <<
     h3:=cons(car h2,h3);h2:=cdr h2;
     h4:=cons((if h2 then car h2 
                     else nil   ) . derili(h3),h4)$
    >>;
   >>;
   if contrace then <<write"h3=",h3,"  h4=",h4;terpri()>>;
   for e1:=1:nu do <<          % for each function u
    u:=nth(ulist,e1);
    h5:=mkid(u,h1);
    if contrace then <<write"h5=",h5;terpri()>>;
%    h6:=nil;
    if contrace then <<write"h6-1=", list('df,divp,h5);
                       terpri()>>;
%    h6:=cons(reval list('quotient,list('df,divp,h5),h11), h6);
%    if nde=1 then h6:=car h6
%             else h6:=cons('plus,h6);
    h6:=reval list('quotient,list('df,divp,h5),h11);
    if contrace then <<write"h6=",h6;terpri()>>;
    nega:=nil;
    h7:=h4;
    % h7 is in such an order that the first term is always positive

    while h7 and not zerop h6 do <<
     h8:=car h7; h7:=cdr h7;
     h9:=car h8; h8:=cdr h8;
     if contrace then <<write if nega then "--" else "++",
                        " h8=",h8,"   h9=",h9;terpri()>>;
     if contrace then <<write"h9-2=",h9;terpri();
                        write"h6=",h6$terpri();
                        write"xlist=",xlist$terpri();
                        write"dulist=",dulist$terpri()>>;
     if h9 then h6:=reval tot!*dif({aeval h6,nth(xlist,h9),h9,dulist});

     if contrace then <<write"h6-3=",h6;terpri()>>;
      
     h10:=if h8 then mkid(u,h8)
                else u;
     if contrace then <<write"h10=",h10;terpri()>>;
     h10:=list('times,h6,h10);
     if nega then h10:=list('minus,h10);
     if contrace then algebraic write">>>> h10=",h10;
     pii:=cons(h10,pii)$
     nega:=not nega;
    >>
   >>;           % for each function u
   il:=newil(il,mo,nx);
  >> until null il;
  pii:=reval if null pii then 0 else
             if length pii=1 then car pii
                             else cons('plus,pii);
  if contrace then algebraic write"pii-end=",pii;

  pii
 >>;             % for all ii
 return cons('list,pl)
end$  % of intcurrent1

%-------------

symbolic operator intcurrent2$
% used in conlaw2,4, crdec
symbolic procedure intcurrent2(divp,ulist,xlist)$
% computes the conserved current P_i from the divergence through
% partial integration
% potential improvement: one could substitute low order derivatives 
% by high order derivatives using remaining conditions and try again

begin scalar h2,h3,h4,h5,h6,h7,h8,e2,e3,lin_problem_bak;
 lin_problem_bak:=lin_problem$ lin_problem:=t; % for intpde

 % repeated partial integration to compute P_i
 ulist  :=cdr reval ulist;
 xlist  :=cdr reval xlist;

 h4:=list xlist;
 % dequ is here a list containing only the conserved density
 % and flux to drop commen factors
 repeat <<
  e3:=divp;
  h3:=car h4;      % h3 is the list of variables is a spec. order
  h4:=cdr h4;
  h5:=for e2:=1:length h3 collect 0;
                   % h5 is old list of the conserved quantities
  h8:=0;           % h8 counts integrations wrt. all variables
  repeat <<        % integrate several times wrt. all variables
   h8:=h8+1;
   h2:=h3;        % h2 is a copy of h3
   h6:=nil;       % h6 is new list of the conserved quantities
   h7:=nil;       % h7 is true if any integration was possible
   while h2 neq nil do <<  % integrating wrt. each variable
    e2:=intpde(e3,ulist,h3,car h2,t);
    if null e2 then e2:=list(nil,e3)
               else e3:=cadr e2;
    if (car e2) and (not zerop car e2) then h7:=t;
    h6:=cons(list('plus,car e2,car h5),h6);
    h5:=cdr h5;
    h2:=cdr h2
   >>;
   h5:=reverse h6;
  >> until (h7=nil)  % no integration wrt. no variable was possible
        or (e3=0)    % complete integration
        or (h8=10);  % max. 10 integrations wrt. all variables
 >> until (e3=0) or (h4=nil);
 lin_problem:=lin_problem_bak;

 return {'list,reval cons('list, h5),e3}
 % end of the computation of the conserved current P
 % result is a {{P_i},remainder}
 % was successful if 0 = remainder (=e3)
end$   % of intcurrent2


%-------------

symbolic operator intcurrent3$
% crident
symbolic procedure intcurrent3(divp,ulist,xlist)$
% computes the conserved current P_i from the divergence through
% partial integration with restriction of maximal 2 terms

begin scalar xl,h1,h2,h3,h4,h5,resu1,resu2,resu3,succ,lin_problem_bak;
 lin_problem_bak:=lin_problem$ lin_problem:=t; % for intpde

 % repeated partial integration to compute P_i
 ulist  :=cdr reval ulist;
 xlist  :=cdr reval xlist;
 xl:=xlist;
 resu1:=nil;
 succ:=nil;
 % try all possible different pairs of variables
 while (cdr xl) and not succ do << 
  h1:=intpde(divp,ulist,xlist,car xl,t);
  if h1 and not zerop car h1 then <<
   resu2:=cons(car h1,resu1);
   h2:=cdr xl;
   repeat <<
    h3:=intpde(cadr h1,ulist,xlist,car h2,nil);
    if h3 and zerop cadr h3 then <<
     h4:=cons(car h3,resu2);
     for each h5 in cdr h2 do h4:=cons(0,h4);
     succ:=t;
     resu3:= {'list,cons('list,reverse h4),0}
    >>;
    h2:=cdr h2;
    resu2:=cons(0,resu2)
   >> until succ or null h2; 
  >>;
  resu1:=cons(0,resu1);
  xl:=cdr xl
 >>$

 lin_problem:=lin_problem_bak;
 return if succ then resu3
                else {'list,cons('list,cons(0,resu1)),divp} 
end$   % of intcurrent3

endmodule$

%********************************************************************
module quasilinpde_integration$
%********************************************************************
%  Routines to solve a quasilinear first order PDE
%  Author: Thomas Wolf
%  summer 1995

%----------------------------

algebraic procedure select_indep_var(clist,xlist)$
begin scalar s,scal,notfound,cq,x,xx,xanz,sanz,xcop,ok;
  % Find the simplest non-zero element of clist
  notfound:=t;
  xcop:=xlist;
  while notfound and (xcop neq {}) do <<
    x :=first xcop ; xcop :=rest xcop ;
    cq:=first clist; clist:=rest clist;
    if cq neq 0 then <<
      xanz:=0;
      for each xx in xlist do
      if %df(cq,xx)
         not freeof(cq,xx) then xanz:=xanz+1;

      ok:=nil;
      if not s then ok:=t else       % to guarantee s neq nil
      if xanz<sanz then ok:=t else   % as few dependencies as poss.
      if xanz=sanz then
      if length(cq)=1 then ok:=t else
      if length(scal)>1 then
      if part(scal,0)=plus then      % if possible not a sum
      if (part(cq,0) neq plus) or
         (length(cq)<length(scal)) then ok:=t;

      if ok then <<s:=x; scal:=cq; sanz:=xanz>>;
      if scal=1 then notfound:=nil
    >>
  >>;

  return {s,scal}
end$ % of select_indep_var

%----------------------------

algebraic procedure charsyscrack(xlist,cqlist,s,scal,u,ode)$
% formulation and solution of the characteristic ODE-system
begin
  scalar lcopy,x,cS,flist,soln,printold,timeold,facintold,
         adjustold,safeintold,freeintold,odesolveold,
         e1,e2,e3,e4,n,nmax,dff,proclistold,flin_old,
         lin_problem_old,session_old,level_old;
  % formulating the ode/pde - system .
  lcopy := cqlist ;
  cS := {} ;
  for each x in xlist do
  << cq := first lcopy ; lcopy := rest lcopy ;
     if x neq s then
     << depend x,s;
        cS := .(scal*df(x,s)-cq,cS) >>
  >>;
  if s neq u then <<flist:={u}; depend u,s;
                    cS := .(scal*df(u,s)+ode,cS) >>
             else flist:={};
  for each x in xlist do
  if s neq x then flist:=.(x,flist);

  lisp <<
    timeold := time_;       time_ :=nil;
    facintold:=facint_;     facint_:=1000;
    adjustold:=adjust_fnc;  adjust_fnc:=t;
    safeintold:=safeint_;   safeint_:=nil;
    freeintold:=freeint_;   freeint_:=nil;
    odesolveold:=odesolve_; odesolve_:=50;
    proclistold:=proc_list_;
    proc_list_:=delete('stop_batch,delete('alg_solve_single,proc_list_))$
    flin_old:=flin_$       
    lin_problem_old:=lin_problem$
    session_old:=session_$
    level_:=level_old;
  >>$
  % solving the odes using crack.
  if lisp(print_ neq nil) then
  lisp <<
    write "The equivalent characteristic system:";terpri();
    deprint cdr algebraic cS$
    %terpri()$
    write "for the functions: ";
    fctprint( cdr reval algebraic flist);write".";
%    write"---------------------------------------------------------------------------"$terpri()$
    write"A new CRACK computation will start now to solve a characteristic ODE system."$terpri()$
  >>;
  soln:=crack(cS,flist,flist,{});
  lcopy:={};
  for each x in soln do <<
   e1:=first x;
   if (e1 neq {}) and (length e1 + length second x = length flist) then <<

    % are there enough constants of integration?
    e2:=length third x;
    for each e3 in flist do
    if not freeof(third x,e3) then e2:=e2-1;
    if e2=length cS then << % enough constants

     % all remaining conditions are algebraic (non-differential) in all the
     % functions of flist?
     e2:={};
     e3:={};
     for each e4 in third x do if freeof(flist,e4) then e3:=e4 . e3
                                                   else e2:=e4 . e2;
     if (length cS) = (length e3) then << % sufficiently many integrations done
      for each e4 in e2 do
      for each e5 in e1 do
      if lisp(not freeof(lderiv(reval algebraic e5,
                                reval algebraic e4,
                                list(reval algebraic s)),'df)) 
      then <<e2:={};e1:={}>>;

      if e2 neq {} then << 
       % It may be possible that derivatives of unsolved functions
       % occur in the expressions of the evaluated functions:  second x
       nmax:=0;
       for each e4 in e2 do <<        % for each unsolved function
        for each e5 in second x do << % for each solved expression
         lisp <<
          n:=lderiv(reval algebraic rhs e5,reval algebraic e4,
                    list(reval algebraic s));
          n:=if (not pairp car n) or (caar n neq 'df) then 0 else
             % would be wrong, for example, for  n=sin(df(..,..))
             if (length car n) = 3 then 1
                                   else cadddr car n
         >>;
         n:=lisp n;
         if n>nmax then nmax:=n;
        >>;
        if nmax>0 then << % adding further conditions
         e5:=e1;
         while freeof(first e5,e4) do e5:=rest e5;
         e5:=first e5;
         dff:=e4;
         for n:=1:nmax do <<
          e5 :=df(e5,s);  e1:= e5 . e1; 
          dff:=df(dff,s); e3:=dff . e3
         >>
        >>
       >>;
       lcopy:=cons({append(second x,e1),e3},lcopy);
      >> 
     >>
    >>
   >>                                                              else 
   if (first x = {}) and (length cS = length third x) then 
   lcopy:=cons({second x,third x},lcopy)
  >>;

  lisp <<
   time_:=timeold; 
   facint_:=facintold;
   adjust_fnc:=adjustold;
   safeint_:=safeintold;
   freeint_:=freeintold;
   odesolve_:=odesolveold;
   proc_list_:=proclistold;
   flin_:=flin_old;
   lin_problem:=lin_problem_old;
   session_:=session_old;
   level_:=level_old;
  >>;
  return
  if lcopy={} then <<for each x in flist do 
                     if not my_freeof(x,s) then nodepend x,s; {}>>
              else s . lcopy  
  % { {{x=..,y=..,u=..,..,0=..},{df(z,s),df(z,s,2),..,c1,c2,c3,..}},..}
  % df(z,s,..) only if df(z,s,..) turns up in x, y, u. ..  .
end$ % of charsyscrack

%----------------------------

%procedure charsyspsfi(xlist,cqlist,u,ode,denf);
% % This calls psfi(). Not sure where this is defined (16.12.2007)
%begin
% scalar h,s;
% h:=cqlist;
% cqlist:={};
% while h neq {} do <<cqlist:=cons(first h*denf,cqlist);h:=rest h>>;
% cqlist:=cons(-ode*denf,cqlist);
% xlist:=cons(u,reverse xlist);
% s:=lisp gensym();
% for each h in xlist do depend h,s;
% h:=psfi(cqlist,xlist,s);
% for each h in xlist do if not my_freeof(h,s) then nodepend h,s;
% return h 
%end$ % of charsyspsfi

%----------------------------

algebraic procedure storedepend(xlist)$
% stores the dependencies of the elements of xlist in the returned
% list and clears the dependencies
begin scalar q,e1,e2$
  return
  for each e1 in xlist collect
  << q:=fargs e1;
     for each e2 in q do nodepend e1,e2;
     cons(e1,q)>>
end$ % of storedepend

%----------------------------

algebraic procedure restoredepend(prev_depend)$
% assigns the dependencies stored in the argument
begin scalar q,s,x;
  for each s in prev_depend do
  <<q:=first s; s:=rest s;
    for each x in s do depend q,x>>
end$ % of restoredepend
  
%----------------------------

symbolic procedure dropable(h,fl,allowed_to_drop)$
if (not smemberl(fl,h)) or 
   member(h,allowed_to_drop) then t else nil$

%----------------------------

symbolic procedure drop_factors(q,fl,allowed_to_drop)$
if not pairp q or (car q neq 'times)     then 
if dropable(q,fl,allowed_to_drop) then 1 
                                  else q else
reval cons('times,for each h in cdr q collect
                  if dropable(h,fl,allowed_to_drop) then 1 else h)$

%----------------------------

symbolic procedure simplifiziere(q,fl,allowed_to_drop)$
begin
 scalar n,nu,de;
 return
 if not pairp q then q else 
 if member(car q,ONE_ARGUMENT_FUNCTIONS_) or
    (member(car q,{'expt}) and 
     dropable(caddr q,fl,allowed_to_drop)) then simplifiziere(cadr q,fl,allowed_to_drop) 
                                           else 
 if car q = 'quotient then <<
  nu:=drop_factors(cadr  q,fl,allowed_to_drop);
  de:=drop_factors(caddr q,fl,allowed_to_drop);
  if nu=1 then simplifiziere(de,fl,allowed_to_drop) else
  if de=1 then simplifiziere(nu,fl,allowed_to_drop) else {'quotient,nu,de}
 >>                   else
 if car q = 'times then <<
  de:=drop_factors(q,fl,allowed_to_drop);
  if (not pairp de) or (length de < length q) then 
  simplifiziere(de,fl,allowed_to_drop)        else de
 >>                else <<
  q:=signchange(q);
  n:=ncontent(q);
  if n=1 then q % one could also subtract constant multiples of 
                % elements of allowed_to_drop to simplify q
         else simplifiziere(reval list('quotient, q, reval n),
                            fl,allowed_to_drop)
 >>                                    
end$

%----------------------------

algebraic procedure quasilinpde(f,u,xlist)$
% f ... PDE, u ... unknown function, xlist ... variable list
begin scalar i, q, qlist, cq, cqlist, ode, soln, tran,
             xcop, s, s1, x, xx, h1, h2, scal, qlin, prev_depend,
             xlist_cp1,xlist_cp2;
  symbolic put('ff,'simpfn,'simpiden)$
  if lisp print_more then
  write"The quasilinear PDE:  0 = ",f,".";
  % changing the given pde into a quasi-linear ode .
  i := 0 ;
  ode := f;
  qlist := {}; cqlist:={};
  for each x in xlist do
  <<i := i+1 ;
    q := mkid(p_,i) ;
    qlist := .(q,qlist) ;
    f := sub(df(u,x) = q , f) ;
    cq:=df(f,q);
    cqlist:=.(df(f,q),cqlist) ;
    ode := ode - df(u,x)*df(f,q) ;
    %if not my_freeof(u,x) then nodepend u, x ;
  >> ;
  lisp(depl!*:=delete(assoc(u,depl!*),depl!*))$
  lisp(depl!*:=delete(assoc(mkid(u,'_),depl!*),depl!*))$

  qlist  := reverse qlist ;
  cqlist := reverse cqlist ;

  % checking for linearity.
  qlin:=t;
  for each cq in cqlist do
  for each  q in  qlist do
  if df(cq,q) neq 0 then qlin:=nil;
  if not qlin then return {};

%  soln:=charsyspsfi(xlist,cqlist,u,ode,den f);

  % Determination of the independent variable for the ODEs
  pcopy:=cons(-ode,cqlist);xcop:=cons(u,xlist);
  scal:=select_indep_var(pcopy,xcop)$
  s1:=first scal;

  prev_depend:=storedepend(xlist)$ 
  soln:=charsyscrack(xlist,cqlist,s1,second scal,u,ode);
  if soln={} then << % try all other coefficients as factors
    repeat <<
      repeat <<s   :=first xcop ;xcop :=rest xcop;
               scal:=first pcopy;pcopy:=rest pcopy>>
      until (pcopy={}) or ((scal neq 0) and (s neq s1));
      if (s neq s1) and (scal neq 0) then << 
        if lisp print_ then lisp 
        <<terpri()$
          write"New attempt with a different independent variable:";
          terpri()>>$
        soln:=charsyscrack(xlist,cqlist,s,scal,u,ode) 
      >>
    >>
    until (soln neq {}) or (xcop={})
  >>;
  % solving for the constants(eg..c1,c2 etc.) and put them in a
  % linear form.
  % The first element of soln is the ODE-variable
  tran:={};
  if soln neq {} then <<
    s1:=first soln;
    for each s in rest soln do
    <<cq:=first solve(first s,second s);
      x:={};
      for each xx in cq do
      if lisp atom algebraic lhs xx then
      x:=.(lisp <<q:=reval algebraic rhs xx;
                  simplifiziere(q,cons(reval u,cdr xlist),nil)>>,x);
      lisp <<
       x:=cdr x;
       repeat <<
        xx:=x$
        x:=for each h1 in x collect 
           simplifiziere(h1,cons(reval u,cdr xlist),delete(h1,x))
       >> until x=xx$
       x:=cons('list,x);
      >>$
      xx:=tran;
      while (xx neq {}) and 
            <<h1:=x;h2:=first xx;
              while (h1 neq {}) and 
                    (h2 neq {}) and 
                    (first h1 = first h2) do <<h1:=rest h1; h2:=rest h2>>;
              if (h1={}) and (h2={}) then nil 
                                     else t
            >> do xx:=rest xx;
      if xx={} then tran:=.(x,tran);
    >>;
    for each s in xlist do 
    if (s neq s1) and (not my_freeof(s,s1)) then nodepend s,s1
  >>;  

  for each x in xlist do depend u,x;

  if lisp print_more then
  if tran neq {} then <<
    write"The general solution of the PDE is given through";   
    for each x in tran do write"0 = ",
    lisp( cons('ff,cdr reval algebraic x));
    if length tran>1 then write"with arbitrary function(s) ff(..)."
                     else write"with arbitrary function ff(..)."
  >>;
  % restoring the dependencies of the variables of the PDE
  restoredepend(prev_depend)$

  return tran
end$ % of quasilinpde

endmodule$

end$

integration
  integrate_one_pde
    integrate
      integratede
        integrableode
          integrableode1
            odecheck
              odetest
        integrateode 
          odeconvert
            odesolve
        integratepde
          addintco 
          ld_deriv_search 
          potintegrable
          multipleint
            intpde
              intpde_

tr integration
tr integrate_one_pde
tr integrate
tr integratede
tr integrableode
tr integrableode1
tr odecheck
tr odetest
tr integrateode 
tr odeconvert
tr err_catch_odesolve
tr odesolve
tr integratepde
tr addintco 
tr ld_deriv_search 
tr potintegrable
tr multipleint
tr intpde
tr intpde_

30.1.2015: 

 - It can not be that case conditions are added which involve new functions
   which are not passed on and which are not available after the end of this
   integration module.
   --> check all places

 - It must not happen, that a sub-case is started which does not change the
   equation from which the case distinction resulted and then integration is
   tried again and the same case distinction with new and different constants
   of integration is started again and again. What is needed is that before
   case distinctions are written into to_do_list, to check that these
   conditions are not already satisfied.

 - A fix could be to return the integrated equation multiplied by all cases
   Which changes are needed for that?
