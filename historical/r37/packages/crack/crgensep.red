%*********************************************************************
module gensep$
%*********************************************************************
%  Routines for generalized separation of de's
%  Author: Andreas Brand, Thomas Wolf
%  1990 1994 1997
%
% $Id: crgensep.red,v 1.7 1998/06/04 15:04:28 tw Exp tw $
%

symbolic procedure maxnoargs(fl,v)$
% determines the maximal number of arguments of any of the 
% functions of fl
begin scalar n,m;
  n:=0;
  for each f in fl do
  <<m:=fctargs f;
    m:=if m and not_included(v,m) then length m
            else 0;
    if n<m then n:=m
  >>;
  return n
end$

symbolic procedure get_gen_separ_pde(pdes)$
% looking for a pde in pdes which can be indirectly separated
% p ...the next equation that will be chosen
% dw...whether p was already delt with
% nv...maximal number of arguments of any of the functions of p
% nf...min number of functions to be dropped before direct sep.
% leng...length of p
begin scalar p,nv,nf,dw,len,h1,h2,h3,h4$
while pdes do <<
  if flagp(car pdes,'to_gensep)                   and
        % not too many terms:
     (gensep_ > (h1:=get(car pdes,'length))     ) and 
        % no single function depending on all variables:
     (h3:=get(car pdes,'starde)                 ) and 
        % Each time the equation is investigated and differentiated
        % wrt the first element of car h3, this element is dropped.
        % --> The equation should not already have been differentiated
        % wrt all variables:
     (not null car h3                           ) and     
        % If equations have been investigated by generalized
        % separation or if equations resulted from generalized
        % separation then they get the flag used_ to be solved
        % first, not to have too many unevaluated new functions
        % at a time
     ((h4:=flagp(car pdes,'used_)          ) or 
      (null dw)                                 ) and
        % The variables in h3 are the ones wrt which direct separation
        % shall be achieved after differentiation, therefore functions
        % of these variables have to be thrown out. The remaining
        % functions shall be of as many as possible arguments to
        % make quick progress:
     ((null p                              ) or
      (nv < (h2:=maxnoargs(
                 get(car pdes,'fcts),
                 car h3   ))               ) or
      ((null dw) and flagp(car pdes,'used_)) or
      (( nv = h2                 ) and 
       (( nf > cdr h3       ) or
        ((nf = cdr h3 ) and          
         (len > h1    )     )    )         )    ) then
    <<p:=car pdes;
      nv:=if null nv then maxnoargs(get(p,'fcts), 
                                    car h3) % first time
                     else h2;
      if h4 then dw:=h4;
      nf:=cdr h3;
      len:=h1>>$
    pdes:=cdr pdes$
  >>;
  return p
end$

symbolic procedure gensep(p)$
%  generalized separation of pde p
if zerop cdr get(p,'starde) then separate(p)   % be dropped?
else                                           % e.g. a=((x y z).2)
begin scalar ftem,ftem1,a,aa,q,l1,l2,ft,pl,x,vl,vl1,deno,starlist,
             f,nv,nv1,h,firsttime,ruli$
%  remflag1(p,'to_gensep)$
  ruli:=start_let_rules()$
  if print_ then <<terpri()$write "generalized separation of ",p>>$
  if tr_gensep then
  <<a:=get(p,'starde)$
    terpri()$write "de to be separated : "$
    typeeqlist list p$
    terpri()$write "variable list for separation : ",car a$
    terpri()$write "for each of these variables ",cdr a$
    if (cdr a)=1 then write" function does"
                 else write" functions"$
    write" depend on it "
  >>$

  %--- so far only one DE p in the pool starlist of equations
  starlist:=list(list(get(p,'val),    % expression
                      get(p,'fcts),   % functions
                      get(p,'vars),   % variables
                      get(p,'starde), % separation charac.
                      nil             % history of divisions
                     ));
  firsttime:=t;

  while starlist do <<

    %--- take first equation from starlist and 
    %--- delete it from starlist
    l1:=car starlist; starlist:=cdr starlist;

    %--- the content of l1:
    q   :=car l1;        % the expression
    ftem:=cadr l1;       % functions in the expression
    vl  :=caddr l1;      % variables in the expression
    a   :=car cadddr l1; % the variables for direct separation
    l2  :=nth(l1,5);     % history of divisions so far

    %--- ft: the list of functions to drop from q by differ. 
    %--- to do a direct separation wrt x:
    % x:=car a$
    % x:=nth(a,1+random length a)$

    % x = any one variable in a on which a function with as 
    % many as possible variables does not depend on
    ftem1:=ftem;    
    nv:=0;
    while ftem1 do <<
      vl1:=fctargs car ftem1;
      nv1:=if vl1 then length vl1
                  else 0;
      if nv1 > nv then <<
        h:=setdiff(a,vl1);
        if h then <<
          x:=car h;
          f:=car ftem1;
          nv:=nv1
        >>
      >>;
      ftem1:=cdr ftem1
    >>; 
    if nv=0 then x:=car a;  % so far no x had been found

%    f:=car ftem;
%    vl1:=fctargs f;
%    nv:=if vl1 then length vl1
%               else 0;
%
%    for each x in cdr ftem do <<
%      vl2:=fctargs x;
%      if vl2 and (nv<length(vl2)) then <<
%        f:=x; nv:=length(vl2)
%      >>
%    >>;
%    x:=vl;
%    vl1:=fctargs f;
%    while member(car x,vl1) do x:=cdr x; % there must be one
%    x:=car x;
%x:=car a;
    if firsttime then 
    put(p,'starde,delete(x,car cadddr l1) . cdr cadddr l1);

    ft:=nil$
    for each f in ftem do
    if member(x,fctargs f) and not freeof(q,f) then ft:=cons(f,ft)$
    if tr_gensep then
    <<terpri()$write "to separate directly w.r.t. ",x$
      write " the expression : "$deprint list q$
      write "will be differentiated">>$
    ft:=fctsort reverse ft$      % sorting w.r.t. number of args

    %--- throwing out functions ft until ft=nil
    %--- or until the expression lost the *-property
    while ft do     
    if (l1:=felim(q,car ft,ftem,vl,l2)) then <<
      q:=car l1$              % new expression
      l2:=cadr l1$            % extended history
      ftem:=smemberl(ftem,q); % functions still in q
      aa:=stardep(ftem,vl);   % still *-expression?
      if not aa or zerop cdr aa then ft:=nil
                                else ft:=smemberl(cdr ft,q)
    >>                                  else ft:=nil$

    if null l1 then if tr_gensep then <<terpri()$
                      write"felim gave nil!!"$terpri()$
                      write"q=",q;terpri()
                    >>           else
               else
    <<if tr_gensep then <<
        terpri()$
        write"Now ready for direct separation."
      >>;
      %--- make denominator-free for direct separation
      if (pairp q) and (car q='QUOTIENT) then
      <<deno:=caddr q$
        q:=cadr q$
        ft:=smemberl(ftem,q)>>           else ft:=nil$

      %--- prepare list of variables vl1 for direct separation
      if ft then <<
        vl1:=nil$
        for each y in vl do if my_freeof(ft,y) then vl1:=cons(y,vl1)
      >>    else vl1:=vl$

      %--- direct separation if useful (i.e. if aa neq nil)
      if aa and zerop cdr aa and not (q=0) then
      <<if tr_gensep then
        <<terpri()$write "trying direct separation of "$
          deprint list q$
          write "Remaining variables: ",vl1>>$
        l1:=for each bb in separ(q,ftem,vl1) collect cdr bb$
        if tr_gensep then
        <<terpri()$
          write "The result of direct separation: "$deprint l1>>$
        if l1 and cdr l1 and tr_gensep then
        <<terpri()$
          write "direct separation yields ",length l1," equations">>
      >>             else l1:=list q$

      %--- backintegration
      if tr_gensep then <<
        terpri()$
        write"Separation gave ",length l1," condition(s)"
      >>;
      fnew_:=nil$
      stop_let_rules(ruli)$ % because integration may not work properly
      while l1 do <<
        q:=car l1; l1:=cdr l1;
        if deno then q:=list('QUOTIENT,q,deno);
        ft:=smemberl(ftem,q);
        vl1:=argset(ft); % all other explicitly occuring variables
                         % are gone through direct separation
        if (aa:=stardep(ft,vl1)) then
        starlist:=cons(list(q,ft,vl1,aa,l2),starlist)
                                 else
        pl:=union(list(backint(q,l2,union(fnew_,ftem),vl)),pl) 
      >>;
      ruli:=start_let_rules()$
      ftem_:=reverse ftem_$
      for each f in reverse fnew_ do ftem_:=fctinsert(f,ftem_)$
      ftem_:=reverse ftem_$
      fnew_:=nil$
    >>$
    %if null l3 then << a:=cdr a$  q:=get(p,'val)>> else 
    %a:=nil;
    %% Only if all possible separations should be done at once.
    %% Better to stop here and to do substitutions first.
    firsttime:=nil$
  >>$

  if pl then <<
    pl:=mkeqlist(pl,fctsort union(ftem_,get(p,'fcts)),get(p,'vars),
                 cons('to_drop,allflags_),t,get(p,'orderings))$
    flag(list(p),'used_);
    flag(pl,'used_);
    if print_ then <<terpri()$
      a:=length pl$
      write "separation yields ",a," new equation"$
      if a > 1 then write"s"$ write" : "$
      if tr_gensep then typeeqlist pl
                   else listprint pl
    >> 
  >>$
  stop_let_rules(ruli)$
  return cons(p,pl)$
end$

symbolic procedure felim(q,f,ftem,vl,l2)$
begin scalar a,b,l,l1,ft1,v,prflag$

  %--- getting rid of f through diff. wrt. v
  v:=car setdiff(vl,fctargs f)$  

  %--- ft1 are all v-independent functions
  %--- In the call to separ one has to disregard v-dep. functions
  ft1:=nil$
  for each f in ftem do if my_freeof(f,v) then ft1:=cons(f,ft1)$

  %--- To run separ, functions ft1 should not be in the denominator
  %--- ?????? What if nonl. Problems?
  if not (pairp q and (car q='QUOTIENT) and smemberl(ft1,caddr q)) then
  <<prflag:=print_$print_:=nil$
    l:=desort separ(q,ft1,list v)$ % det. all lin. ind. factors with v
    if tr_gensep then
    <<terpri()$write "To get rid of ",f,
		     " we differentiate w.r.t. : ",v>>$
    print_:=prflag$

    %--- l is a list of dotted pairs a each representing a term in q 
    % where car(a) is the product of v-dep. factors and cdr(a) the
    % product of v-independent factors
    %--- A list l1 of car(a) is generated for which cdr(a) depends
    % on f. l1 is the list of divisions to be done before differen.
    l1:=nil$
    while l do
    <<a:=car l$
      b:=nil$
      if not freeof(cdr a,f) and (not zerop car a) then
%     if (pairp cdr a) and (cadr a='PLUS) then
%     <<for each c in cddr a do if not freeof(c,f) then b:=cons(c,b)$
%       if b then b:=cons('PLUS,b)>>      else b:=cdr a$
%     if b then
      <<l1:=cons(car a,l1)$
%       q:=reval list('DIFFERENCE,q,list('times,b,car a))
      >>$
      l:=cdr l
    >>$
    if tr_gensep then
    <<terpri()$
      write v," - depending coefficients of terms containing ",f," : "$
      for each ss in l1 do eqprint ss>>$

    %--- Now the divisions and differentiations are done
    while l1 do
    <<b:=reval aeval car l1$ %--- b is the v-dep. coefficient
      l1:=cdr l1$
      %--- ????? If for non-linear Problems b includes ftem functions
      % then the extra case 0 = b has to be considered
      if not zerop b then
      <<a:=reval aeval list('QUOTIENT,q,b)$
        %--- for later backward integrations: extension of the history
        if new_gensep then   %############## change:
        l:=cons(b . q ,l)    %--- q is the equ. before division & diff.
                      else
        l:=cons(b ,l)$      
        % l will be returned later by felim 
        %--- l1 has to be updated as the coefficients
        % change through division and differentiation
	l1:=for each c in l1 collect
	    reval list('DF,list('QUOTIENT,c,b),v)$
        %--- the differentiation
	q:=reval list('DF,a,v)$
	if tr_gensep then
	<<write "The new equation: "$
	  eqprint q$
	  write "The remaining factors:"$
	  for each ss in l1 do eqprint ss
	>>
      >>
    >>$
    if l then l2:=cons(list(v,l),l2)$

    %--- output
    if tr_gensep then
    <<terpri()$write "new expression (should not depend on ",f,") : "$
      eqprint q$>>$
    if tr_gensep and l2 then
    <<write "The list of multiplications and integrations ",
	    "to go backwards after direct separation:"$
      for each ss in l2 do <<write "integr. wrt. ",car ss$ terpri()$
			     write "multiply with "$
			     for each aa in cadr ss do
                             %--- print all collected factors
				 eqprint aa>>
    >>$

    l1:=list(q,l2)
  >>$
  return l1
  %--- returns nil if not successful (quotient)
  % otherwise a list with 2 elements: the current equation and a history list
  % which is the input history list extended by the current run, each
  % run being represented by one element which itself is a list of the
  % differentiation variable and the list of factors
end$

symbolic procedure backint(s,l2,ftem,vl)$
begin scalar fl,ft,q,l,v,v1,vf,s2,p,f2,fnew1$
  % factors should be dropped which do not depend on any integration
  % variable and not on any variable of the ftem functions but on other
  % variables of vl
  % But factors containing ftem functions should not be dropped.
  % It is assumed that all integration variables are argument to at
  % least one function of ftem
  ft:=smemberl(union(ftem,fnew_),s);
  v1:=argset ft;
  q:=t;
  l:=vl;
  while q and l do 
  if freeof(v1,car l) and 
     (not my_freeof(s,car l)) then q:=nil 
                              else l:=cdr l;
  if not q then s:=cadr extractfac(s,append(v1,ft),nil)$

  % start of the backintegration
  fnew1:=fnew_$
  fl:=q:=t$
  p:=s$
  while l2 and fl do
  <<l:=car l2$
    l2:=cdr l2$
    v:=car l$
    if tr_gensep then
    <<terpri()$
      write "backward integration w.r.t. ",v," of the expression : "$
      eqprint p>>$
    l:=cadr l$
    while l and q do
    <<ft:=smemberl(ftem,p)$
%terpri()$write "vor int: p= "$eqprint p$
      fnew_:=nil$
      q:=integratepde(p,ft,v,nil,nil)$ % genflag:=nil, potflag=nil
      fnew1:=append(fnew_,fnew1)$
      if q then
      <<fl:=t$
	p:=reval list('TIMES,car l,car q)$

	% Substituting the new functions of integration by derivatives
	% of them such that back-integration can be made
% hat fnew_ nur ein element, d.h. wird nur eine Integration gemacht
% oder mehrere?
	for each f1 in fnew_ do
	<<f2:=f1$
	  vf:=setdiff(vl,fctargs f1)$
	  for each s1 in reverse l2 do
	  <<v1:=car s1$
	    if not my_freeof(f1,v1) then
% only then integration makes difficulties
	    <<s2:=reverse cadr s1$
	      while s2 do
	      <<if not smemberl(vf,car s2) then
		  f2:=reval list('DF,list('QUOTIENT,f2,car s2),v1)$
% actually only dividing through those factors of (car s2)
% which depend on v1 and which do not contain variables
% which f2 does not depent on.
		s2:=cdr s2
	      >>
	    >>
	  >>$
	  if f1 neq f2 then
	  <<if tr_gensep then <<terpri()$
                                write f1," is replaced by "$
				eqprint f2>>$
	    p:=subst(f2,f1,p)$
	  >>
	>>$
	ftem:=union(fnew_,ftem)
      >>   else fl:=nil$
      l:=cdr l
    >>
  >>$
  if tr_gensep then if fl then <<terpri()$write "yields : "$
				 eqprint p$>>
			  else <<terpri()$
				 write "was not successful.">>$
  fnew_:=union(fnew1,fnew_)$
  return if fl then p
	       else s
end$

endmodule$

end$


