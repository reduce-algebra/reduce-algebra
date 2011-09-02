
%       CONLAW version 2, to calculate conservation laws of systems
%            of PDEs by calculating characteristic functions

%                   by Thomas Wolf, September 1997

%----------------------------------------------------------------------

symbolic fluid '(print_ logoprint_ potint_ facint_ adjust_fnc)$ 
%symbolic fluid '(div_p)$ 

%-------------

symbolic procedure newil(il,mo,nx)$
if (null il) or (length il<mo) then cons(1,il) else
if car il<nx then cons(add1 car il,cdr il) else
<<while il and (car il = nx) do il:=cdr il;
  if null il then nil 
             else cons(add1 car il,cdr il)>>$

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

symbolic operator intcurrent1$
symbolic procedure intcurrent1(divp,ulist,xlist,dulist,
                               nx,nde,eqord,densord)$
% computes a list in reverse order from which the conserved
% current is computed through integration
begin scalar ii,il,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,contrace,u,
             nega,pii,mo,pl$
%contrace:=t;

 ulist:=cdr ulist;
 xlist:=cdr xlist;
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
   for e1:=1:nde do <<          % for each function u
    u:=nth(ulist,e1);
    h5:=mkid(u,h1);
    if contrace then <<write"h5=",h5;terpri()>>;
    h6:=nil;
    if contrace then <<write"h6-1=", list('DF,divp,h5);
                       terpri()>>;
    h6:=cons(reval list('QUOTIENT,list('DF,divp,h5),h11), h6);
    if nde=1 then h6:=car h6
	     else h6:=cons('PLUS,h6);
    if contrace then <<write"h6=",h6;terpri()>>;
    nega:=nil;
    h7:=h4;
    % h7 is in such an order that the first term is always positive

    while h7 and not zerop h6 do <<
     h8:=car h7; h7:=cdr h7;
     h9:=car h8; h8:=cdr h8;
     if contrace then <<write if nega then "--" else "++",
                        " h8=",h8,"   h9=",h9;terpri()>>;
     if contrace then <<write"h9-2=",h9;terpri()>>;
     if h9 then h6:=totdif(h6,nth(xlist,h9),h9,dulist);

     if contrace then <<write"h6-3=",h6;terpri()>>;
      
     h10:=if h8 then mkid(u,h8)
	        else u;
     if contrace then <<write"h10=",h10;terpri()>>;
     h10:=list('TIMES,h6,h10);
     if nega then h10:=list('MINUS,h10);
     if contrace then algebraic write">>>> h10=",h10;
     pii:=cons(h10,pii)$
     nega:=not nega;
    >>
   >>;           % for each function u
   il:=newil(il,mo,nx);
  >> until null il;
  pii:=reval if length pii=1 then car pii
                             else cons('PLUS,pii);
  if contrace then algebraic write"pii-end=",pii;

  pii
 >>;             % for all ii
 return cons('LIST,pl)
end$  % of intcurrent1

%-------------

symbolic operator intcurrent2$
symbolic procedure intcurrent2(divp,ulist,xlist,nondiv)$
% computes the conserved current P_i from the divergence through
% partial integration
begin scalar h2,h3,h4,h5,h6,h7,h8,e2,e3;

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
    e3:=cadr e2;
    if not zerop e2 then h7:=t;
    h6:=cons(list('PLUS,car e2,car h5),h6);
    h5:=cdr h5;
    h2:=cdr h2
   >>;
   h5:=reverse h6;
  >> until (h7=nil)  % no integration wrt. no variable was possible
        or (e3=0)    % complete integration
        or (h8=10);  % max. 10 integrations wrt. all variables
 >> until (e3=0) or (h4=nil);
 return if e3=0 then cons('LIST, h5)
                else nondiv
 % end of the computation of the conserved current P
 % result is a list of P_i
end$   % of intcurrent2

%-------------

algebraic procedure conlaw2(problem,runmode)$
begin
  scalar contrace,eqlist,ulist,xlist,dequ,cllist,divlist,
  sb,densord,flist,eqord,maxord,dulist,revdulist,vl,expl,
  deplist,e1,e2,e3,n,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,
  condi,soln,adjust_old,potold,adjustold,udens,gensepold,
  inequ0,inequ,logoold,treqlist,fl,facold,u,lhslist,cpu,
  gc,cpustart,gcstart,nontriv,cf0,rtnlist,paralist,solns,
  found,clcopy,extraline,nondiv,nx,nde,nonconstc,
  mindensord,mindensord0,maxdensord,rules$

  lisp <<adjustold:=adjust_fnc; adjust_fnc:=t;
	 logoold:=logoprint_;   logoprint_:=t;
	 potold:=potint_;       potint_:=t;
         facold:=facint_;       facint_:=1000>>;

  cpustart:=lisp time()$ gcstart:=lisp gctime()$
% contrace:=t;

  %--- extracting input data
  eqlist:= maklist first problem;
  ulist := maklist second problem;
  xlist := maklist third problem;
  nx:=length xlist;
  nde:=length eqlist;
  if contrace then write"eqlist=",eqlist,
  " ulist=",ulist," xlist=",xlist;

  mindensord:=part(runmode,1)$
  maxdensord:=part(runmode,2)$
  expl      :=part(runmode,3)$
  flist     :=part(runmode,4)$
  inequ0    :=part(runmode,5)$
  problem:=runmode:=0;

  %--- initial printout
  lisp(if logoprint_ then <<terpri()$
    write "--------------------------------------------------",
    "------------------------"$ terpri()$terpri()$
    write "This is CONLAW2 - a program for calculating conservation",
    " laws of DEs"; terpri()
  >>                 else terpri());
  if nde = 1 
  then write "The DE under investigation is :"
  else write "The DEs under investigation are :";
  for each e1 in eqlist do write e1;
  write "for the function(s): ",ulist;
  write"======================================================"$

  %--- lhslist is the list of derivatives to substitute
  %--- is needed in order not to let the Q depend on them and their deriv.
  eqlist:=reverse eqlist;
  lhslist:={};
  for each h1 in eqlist do lhslist:=cons(lhs h1,lhslist);

  %--- bringing eqlist and ulist in line
  h1:={};  h2:={};
  if nde neq length ulist then n:=t else
  for each e1 in eqlist do <<
    e2:=part(lhs e1,1);
    if freeof(ulist,e2) then n:=t
                        else h1:=cons(e2,h1);
    h2:=cons(lhs e1 - rhs e1, h2)
  >>;

  if n then
  rederr("The lists of equations and functions are not consistent!")
       else <<ulist:=h1; eqlist:=h2>>;

  if contrace then write"ulist=",ulist,"    eqlist=",eqlist;

  %--- initializations to be done only once
  rtnlist:={};
  nondiv:=lisp gensym(); % as a marker if p-computation was not succ.

  %------ the list of parameters of the equation to be determined
  paralist:={};
  for each e1 in flist do
  if not freeof(eqlist,e1) then paralist:=cons(e1,paralist);

  %------ determination of the order of the input equations
  eqord:=0;
  mindensord0:=mindensord;
  for each e1 in eqlist do
  for each e2 in ulist do <<
    h1:=totdeg(e1,e2);
    if h1>eqord then eqord:=h1
  >>;
  for n:=1:nde do <<
    h1:=mkid(q_,n);
    if not lisp(null get(mkid('q_,n),'avalue)) then <<
      for each e2 in ulist do <<
        h2:=totdeg(h1,e2);
        if h2>eqord then eqord:=h2;
        if h2>mindensord then mindensord:=h2
      >>;
      cf0:=t;
    >>
  >>;
  if contrace then write"eqord=",eqord;
  if maxdensord<mindensord then maxdensord:=mindensord;

  %------ all transformations into jet-space
  sb:=subdif1(xlist,ulist,eqord)$
  if contrace then write"sb=",sb;
  treqlist:=eqlist;
  for each e1 in sb do treqlist:=sub(e1,treqlist);
  for each e1 in sb do  lhslist:=sub(e1, lhslist);
  if contrace then write"treqlist=",treqlist,
                        "  lhslist=",lhslist;
  if cf0 then
  for n:=1:nde do <<
    h1:=mkid(q_,n);
    if not lisp(null get(mkid('q_,n),'avalue)) then <<
     for each e1 in sb do h1:=sub(e1,h1);
     lisp(mkid('q_,n)):=h1;
    >>
  >>;
  for each e1 in sb do inequ0:=sub(e1,inequ0);

  %--- investigate conservation laws of increasing order
  for densord:=mindensord:maxdensord do <<

    nodepnd(ulist);

    cpu:=lisp time()$ gc:=lisp gctime()$
    if cf0 then
    lisp<<write"A special ansatz of order ",densord,
               " for the characteristic"$terpri()$
          write"function(s) is investigated.";terpri()
        >> else
    lisp<<
      write"Currently conservation laws with characteristic";
      terpri();
      write"function(s) of order ",densord," are determined";
      terpri();
      write"======================================================"$
    >>;

    %--- repeated initializations
    %--- maxord is maximal derivative in condition
    maxord:=eqord  % from the total derivatives
            + 1    % for safety
            + if eqord>densord then eqord
                               else densord$
            %######## possibly to be increased due to substitutions
    if contrace then write"maxord=",maxord;

    if {}=fargs first ulist then
    for each e1 in ulist do depnd(e1,{xlist});
    sb:=subdif1(xlist,ulist,maxord)$
    nodepnd ulist;
    if contrace then write"sb=",sb;

    dulist:=ulist . reverse for each e1 in sb collect
			    for each e2 in e1 collect rhs e2;
    sb:=0;
    revdulist:=reverse dulist;      % dulist with decreasing order
    udens:=part(dulist,densord+1);  % derivatives of order densord
    vl:=for each e1 in dulist join e1;
    if contrace then write"vl=",vl,"  udens=",udens;

    if not flist then fl:={}
		 else fl:=flist;

    %--- initializing characteristic functions cf, the list of functions fl
    deplist:=ulist . for n:=1:densord collect
                     listdifdif2(lhslist,part(dulist,n+1));
    if expl then deplist:=xlist . deplist;
    deplist:=reverse deplist;
    cf:={};
    for n:=1:nde do <<
      h1:=mkid(q_,n);
      if lisp(null get(mkid('q_,n),'avalue)) then <<
        nodepnd({h1});
        depnd(h1, deplist);
        fl:=cons(h1,fl);
      >>;
      cf:=cons(h1,cf);
    >>;
    cf:=reverse cf;

    if contrace then write"fl=",fl;
    if contrace then lisp (write" depl*=",depl!*);

    %--- generation of the conditions
    condi:={};
    for each u in ulist do <<
      if contrace then write"function=",u;
      h1:=treqlist;
      h2:=cf;
      h3:=0;
      while h1 neq {} do <<      % sum over all equations
        if contrace then write"equation :",first h1;
        for each e1 in vl do    % sum over u and all its derivatives
        if lisp(reval algebraic(u) =
                car combidif algebraic(e1)) then
        << % for u and all its derivatives
          e2:=df(first h1, e1);
          if e2 neq 0 then <<
            if contrace then write"e1=",e1;
            dequ:=first h2 * e2;
            e2:=1;
            for each e3 in lisp
            cons('LIST,cdr combidif(algebraic e1)) do
            <<dequ:=totdif(dequ,part(xlist,e3),e3,dulist)$
              e2:=-e2;
              if contrace then write"dequ=",dequ," e3=",e3>>;
            h3:=h3+e2*dequ;
            if contrace then write"h3=",h3;
          >>;
        >>;
        h1:=rest h1;h2:=rest h2
      >>;
      condi:=cons(h3,condi)
    >>;
    if contrace then write"condi=",condi;

    %--- generating a substitution list
    %--- at first using the equations themselves
    sb:={};
    rules:={};
    h1:=treqlist;
    h2:=lhslist;
    h4:=nil;       % h4 is list of undifferentiated substitutions
    while h1 neq {} do <<
      h3:=first h2;
      h5:=h3-first h1;
      rules:=cons(h3 => h5,rules)$
      lisp(e3:=combidif h3);
      % extracts the list of derivatives: u`1`1`2 --> (u, 1, 1, 2)
      lisp(h4:=cons(list(car e3, cdr e3, h5), h4))$
      % function name of h3, derivative list of h3, value of h3
      h1:=rest h1;
      h2:=rest h2;
    >>;
    %--- then their derivatives
    for each e1 in vl do lisp <<
      e1:=reval e1;
      % is e1 a derivative of any of the undifferentiated substitutions?
      h1:=h4;
      while h1 neq nil do <<
        h3:=comparedif2(caar h1, cadar h1, e1);
        if (h3 neq nil) and (h3 neq 0) then algebraic <<
          h3:=lisp(cons('LIST,h3));
          dequ:=lisp caddar h1; % rhs which is to be differentiated
          for each n in h3 do dequ:=totdif(dequ,part(xlist,n),n,dulist);
          % new highest derivatives should be added to vl afterwards
          % if lower derivatives are substituted by higher derivatives
          rules:=cons(e1 => dequ,rules)$
          lisp(h1:=nil)
        >>                             else lisp(h1:=cdr h1);
      >>
    >>;

    if contrace then write"rules=",rules;
    let rules;
    condi:=condi;
    clearrules rules$
    if contrace then write"condi=",condi;

    vl:=append(xlist,vl); % now the full list

    inequ:=inequ0;
    %--- inequ is to stop crack if order of cf is too low
    if (densord neq 0) and 
       ((cf0=nil) or (mindensord0 neq 0)) then <<
      % investigation should stop if
      % cf is independent of highest order derivatives
      dequ:=0;
      for each e1 in cf do <<
        h1:=udens;
        while h1 neq {} do <<
          dequ:=dequ+df(e1,first h1)*(lisp gensym());
          h1:=rest h1
        >>;
      >>;
      inequ:=cons(dequ,inequ)
    >>;
    let rules;
    inequ:=inequ;
    clearrules rules$
    rules:=0;
    if contrace then write"inequ=",inequ;

    %--- freeing some space
    sb:=revdulist:=deplist:=e1:=e2:=e3:=
    n:=h1:=h2:=h3:=soln:=u:=dequ:=0;

    %--- the real calculation
    if lisp(!*time) then
    write "time to formulate condition: ", lisp time() - cpu,
          " ms    GC time : ", lisp gctime() - gc," ms"$
    solns:=crack(condi,inequ,fl,vl);

    %--- postprocessing

    lisp terpri()$
    found:=nil;
    while solns neq {} do <<
      divlist:={};
      cllist:={};
      soln:=first solns;
      solns:=rest solns;
      condi:=first soln;
      cfcopy:=sub(second soln,cf);
      h1:=third soln;
      if contrace then <<
	write"cfcopy=",cfcopy;
	write"soln=",soln;
	write"third soln=",h1;
      >>;
      fl:={};
      h2:={};
      for each e1 in h1 do <<
	if not freeof(condi,e1) then fl:=cons(e1,fl); 
	% fl to output remaining conditions later
	if freeof(paralist,e1) then h2:=cons(e1,h2)
      >>;
      h1:=parti_fn(h2,condi)$
      if contrace then write"h1(partitioned)=",h1;
      extraline:=nil;
      nonconstc:={};
      while h1 neq {} do <<
        e1:=first h1;h1:=rest h1;
        for each h4 in e1 do
	if fargs h4 neq {} then <<
          nonconstc:=cons(h4,nonconstc);
          lisp <<
	    write"The function "$
            fctprint list reval h4$
	    write" is not constant!";
            extraline:=t;
	    terpri()
          >> 
        >>;
	dequ:=0;                              % to compute rhs
	h2:=treqlist;                         %       "
        if paralist then h2:=sub(second soln,h2); %   "
	if contrace then write"h2=",h2;           %   "
	nontriv:=nil;
	h3:=for each e2 in cfcopy collect <<
	  e3:=for each h4 in e1 sum fdepterms(e2,h4);
	  dequ:=dequ+e3*first h2; h2:=rest h2; % computes rhs
	  if e3 neq 0 then nontriv:=t;
	  e3
	>>;
	if nontriv then <<
          found:=t;
	  cllist:=cons(<<if contrace then write"h3-1=",h3,"  dequ=",dequ;
		         sb:=absorbconst(h3,e1)$
			 if (sb neq nil) and (sb neq 0) then <<
			   h3:=sub(sb,h3);
			   dequ:=sub(sb,dequ)
			 >>;
			 if contrace then write"h3-2=",h3,"  dequ=",dequ;
			 if (length(e1)=1) and (fargs first e1 = {}) then <<
                           h4:=first e1;
			   dequ:=sub(h4=1,dequ);
			   sub(h4=1,h3)
			 >>               else h3
		       >>,
		       cllist);
	  divlist:=cons(dequ,divlist)
        >>
      >>;
      if contrace then <<
        write"characteristic functions found so far:";
        write cllist;
      >>$
      if condi neq {} then <<
        write"There are remaining conditions: ",
              condi;
	lisp <<
	write"for the functions: ";
        fctprint cdr reval algebraic fl;terpri();
        write"Corresponding CLs might not be shown below as they";
        terpri()$write"could be of too low order.";terpri()>>;
        extraline:=t;
      >>;
      if extraline then lisp <<
        write"======================================================"$
        terpri()
      >>;

      %--- Dropping conservation laws of too low order
      if (densord > 0) and 
         ((cf0=nil) or (mindensord0 neq 0)) then <<
        h1:={};
        h2:={};
        for each e1 in cllist do <<
          h5:=udens;
          while (h5 neq {}) and 
                freeof(e1,first h5) do h5:=rest h5;
          if h5 neq {} then <<
            h1:=cons(e1,h1);
            h2:=cons(first divlist,h2)
          >>;
          divlist:=rest divlist;
        >>;
        cllist:=h1;
        divlist:=h2
      >>;

      if contrace then write"cllist=",cllist;
      if cllist neq {} then <<
        %--- Below h1 is the list of W^i in the Anco/Bluman formula
        h1:=for e1:=1:(length cllist) collect
        intcurrent1(part(divlist,e1),ulist,xlist,dulist,nx,nde,
                    eqord,densord);

        %--- Backsubstitution of e.g. u`1`1 --> df(u,x,2) 
        for each e1 in ulist do depnd(e1,{xlist});
	on evallhseqp;
	sb:=subdif1(xlist,ulist,maxord)$
	sb:=for each e1 in sb join
	    for each e2 in e1 collect(rhs e2 = lhs e2);
	off evallhseqp;
	cllist:=sub(sb,cllist);

        h1:=sub(sb,h1);

        %--- lambda integration of h1 to compute P_i
        h2:=lisp gensym()$
        for each e1 in ulist do 
        h1:=sub(e1=h2*e1,h1);

        if not lisp(freeof(h1,'SUB)) then h1:={}
                                     else
        h1:=for each e1 in h1 collect << % i.e. for each cl
          h10:=sub(sb,first divlist);  divlist:=rest divlist;
          % at first try direct integration to compute p
          h9:=intcurrent2(h10,append(nonconstc,ulist),xlist,nondiv);
          % if no success use lambda-integration
          if h9=nondiv then <<
 	    h8:=t;         % whether intcurrent1 is still ok

            %--- at first the term h10 = T^i/x^i in conca.tex
            for each e2 in ulist do <<
              if h8 then h10:=err_catch_sub(e2,0,h10);
              if h10 eq nil then h8:=nil
            >>$
            if contrace then write"h10-1=",h10$ 
            if h8 and (h10 neq 0) then <<
              for each e2 in xlist do <<
                if h8 then h10:=err_catch_sub(e2,h2*e2,h10);
                if h10 eq nil then h8:=nil
              >>$
              if h8 then <<
                if contrace then write"h10-2=",h10$ 
                h10:=int(h10*h2**(nx-1),h2);
                if contrace then write"h10-3=",h10$ 

	        %--- the following is to catch errors in: 
	        %--- sub(h2=1,h10)-sub(h2=0,h10)
	        h6:=err_catch_sub(h2,1,h10);
                if contrace then write"h6=",h6$ 
	        if h6 eq nil then h7:=nil
		   	     else h7:=err_catch_sub(h2,0,h10);
                if contrace then write"h7=",h7$ 
	        if h7 eq nil then h8:=nil
			     else h10:=h6-h7
              >>
            >>$
            if contrace then write"h10-4=",h10$ 
	    h4:={};        % h4 becomes the inverse list of P^i
            h11:=0;
	    while h8 and (e1 neq {}) do <<
              h11:=h11+1;
	      e2:=first e1; 
	      e1:=rest e1;
	      if contrace then write"e2=",e2$ 
	      h3:=int(e2/h2,h2);
	      if contrace then write"h3-1=",h3$ 

	      %--- the following is to catch errors in: 
	      %--- sub(h2=1,h3)-sub(h2=0,h3)
	      h6:=err_catch_sub(h2,1,h3);
	      if h6 eq nil then h7:=nil
	 		   else h7:=err_catch_sub(h2,0,h3);
	      if h7 eq nil then h8:=nil
			   else h4:=cons(h6-h7+h10*part(xlist,h11),h4)
	    >>;
            if h8 then h9:=reverse h4
          >>;
          h9
        >>;
        if contrace then write"h1-1=",h1$

	if h1={} then <<
          lisp <<
	    write"The conserved quantities could not be found."$          
            terpri()
          >>$
	  if condi neq {} then lisp <<
	    write"For that the remaining conditions should be solved.";
	    terpri()
	  >>;
          lisp <<
            write"The adjoined symmetries are:"$terpri()
          >>$
          for each e1 in cllist do write e1$
	>>$
	if contrace then <<
	 write"h1=",h1;write"cllist=",cllist;write"eqlist=",eqlist
	>>;
	while h1 neq {} do <<
	  h2:=first h1;
	  h3:=first cllist;
	  rtnlist:=cons({h3,h2},rtnlist);

	  %--- conditions on parameters
	  if paralist neq {} then 
	  for each e2 in second soln do
	  if not freeof(paralist,lhs e2) then 
	  <<write e2,",";lisp(terpri())>>$

          %--- the conservation laws

          %--- Test whether actually only an adjoint symmetry has been
          %--- computed and not a conservation law
	  h4:=eqlist;
          if paralist neq {} then h4:=sub(second soln,h4);

          h8:=0;                       
	  if h2 neq nondiv then <<
            h5:=h4;                     
	    for each e1 in h3 do <<
              h8:=h8 + e1*(first h5)$  
	      h5:=rest h5 
            >>$
            for e1:=1:nx do <<
              h8:=h8-df(part(h2,e1),part(xlist,e1))$ % for test purposes
            >>;
            if h8 neq 0 then h2:=nondiv
          >>;

          if h2=nondiv then write"Adjoint symmetry:"
                       else write"Conservation law:";

	  while h3 neq {} do <<
	    if length h3 < length first cllist then write "+"$
	    write"(",first h3,") * (",first h4,")"$
	    h3:=rest h3; h4:=rest h4
	  >>$

	  if h2=nondiv then <<
            lisp <<
              write"could not be written as a divergence but solves the"$
              terpri()$
              write"adjoint symmetry condition and therefore represents"$
              terpri()$
              write"an adjoint symmetry."$ terpri()$ 
            >>$
            if (h8 neq 0) and (condi neq {}) then <<
              write"Please check: if the remaining conditions guarantee "$
              write" 0 = ",h8$
              write"then the conservation law is"$
              write" 0 = "$
              for e1:=1:nx do <<
	       write"df( ",part(h2,e1),", ",part(xlist,e1)," )"$
	       if e1<nx then write "+"$
              >>
            >>$
	  >>        else <<
	    write"= "$
            for e1:=1:nx do <<
	     write"df( ",part(h2,e1),", ",part(xlist,e1)," )"$
	     if e1<nx then write "+"$
            >>
	  >>;
	  h1:=rest h1;
	  cllist:=rest cllist;
          write"======================================================"$
	>>$
      >>;   %   if cllist neq {} then <<
      nodepnd(ulist);
    >>;    %   while solns neq {} do <<
    if found=nil then <<
      write"There is no conservation law of this order.";
      write"======================================================"$
    >>
  >>;   %   for densord:=mindensord:maxdensord

  if fargs first ulist = {} then
  for each e1 in ulist do depnd(e1,{xlist});

  if lisp(!*time) then
  write "time to run conlaw2: ", lisp time() - cpustart,
        " ms    GC time : ", lisp gctime() - gcstart," ms"$

  lisp <<adjust_fnc:=adjustold;
	 logoprint_:=logoold;
	 %gensep_:=gensepold;
	 potint_:=potold;
	 facint_:=facold>>;
  return rtnlist

end$ % of conlaw2

end$

