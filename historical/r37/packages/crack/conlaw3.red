comment consider many solutions of crack 
;
% CONLAW version 3, to calculate conservation laws of systems of PDEs
%   by calculating characteristic functions and conserved currents

%                   by Thomas Wolf, September 1997

%----------------------------------------------------------------------

symbolic fluid '(print_ logoprint_ potint_ facint_ adjust_fnc)$ 

%-------------

algebraic procedure conlaw3(problem,runmode)$
begin
  scalar contrace,eqlist,ulist,xlist,dequ,cllist,pllist,
  sb,densord,flist,eqord,maxord,dulist,revdulist,vl,expl,
  deplist,e1,e2,e3,n,h1,h2,h3,h4,h5,h6,h7,h8,condi,soln,
  adjust_old,potold,adjustold,udens,gensepold,inequ0,
  inequ,logoold,treqlist,fl,facold,u,lhslist,cpu,gc,
  cpustart,gcstart,found,cf0,rtnlist,solns,nontriv,
  extraline,cf,cfcopy,nx,nde,mindensord,mindensord0,
  maxdensord;

  lisp <<adjustold:=adjust_fnc; adjust_fnc:=t;
	 logoold:=logoprint_;   logoprint_:=t;
	 potold:=potint_;       potint_:=t;
	 facold:=facint_;       facint_:=1000>>;

  cpustart:=lisp time()$ gcstart:=lisp gctime()$
% contrace:=t;

  %--- extracting input data
  eqlist:= maklist first problem;
  ulist := maklist second problem;
  xlist:= maklist third problem;
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
    write "This is CONLAW3 - a program for calculating conservation",
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

  %------ the list of parameters of the equation to be determined
  paralist:={};
  for each e1 in flist do
  if not freeof(eqlist,e1) then paralist:=cons(e1,paralist);

  %------ determination of the order of the input equations
  eqord:=0;
  for each e1 in eqlist do
  for each e2 in ulist do <<
    h1:=totdeg(e1,e2);
    if h1>eqord then eqord:=h1
  >>;
  h3:=eqord;
  mindensord0:=mindensord$
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
  for n:=1:nx do <<
    % if the index of p_ should be a number then use n instead of h4
    h4:=lisp(reval algebraic(part(xlist,n)));
    h1:=mkid(p_,h4);
    if not lisp(null get(mkid('p_,h4),'avalue)) then <<
      for each e2 in ulist do <<
        h2:=totdeg(h1,e2);
        if h2>eqord then eqord:=h2;
        if (h2>=h3) and (mindensord<=h2) then mindensord:=h2+1
      >>;
      cf0:=t;
    >>
  >>;
  if maxdensord<mindensord then maxdensord:=mindensord;

  if contrace then write"eqord=",eqord," cf0=",cf0;

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
  if cf0 then
  for n:=1:nx do <<
    % if the index of p_ should be a number then use n instead of h4
    h4:=lisp(reval algebraic(part(xlist,n)));
    h1:=mkid(p_,h4);
    if not lisp(null get(mkid('p_,h4),'avalue)) then <<
      for each e1 in sb do h1:=sub(e1,h1);
      lisp(mkid('p_,h4)):=h1;
    >>
  >>;
  for each e1 in sb do inequ0:=sub(e1,inequ0);

  %--- investigate conservation laws of increasing order
  for densord:=mindensord:maxdensord do <<

    nodepnd ulist;

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
    maxord:=if eqord>densord then eqord
			     else densord;
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
    %--- the conserved current pl and the condition condi
    condi:=0;
    deplist:=ulist . for h3:=1:densord collect
                     listdifdif2(lhslist,part(dulist,h3+1));

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
      condi:=condi+h1*part(treqlist,n);
    >>;
    cf:=reverse cf$

    deplist:=for h3:=0:(maxord-1) collect part(dulist,h3+1);
    if expl then deplist:=xlist . deplist;
    deplist:=reverse deplist;
    pl:={};
    for n:=1:nx do <<
      % if the index of p_ should be a number then use n instead of h4
      h4:=lisp(reval algebraic(part(xlist,n)));
      h1:=mkid(p_,h4);
      if lisp(null get(mkid('p_,h4),'avalue)) then <<
        nodepnd({h1});
        depnd(h1, deplist);
        fl:=h1 . fl;
      >>;
      pl:=cons(h1,pl);
      condi:=condi-totdif(h1,h4,n,dulist)
    >>;
    sb:=0;

    if contrace then write"fl=",fl," cf=",cf," pl=",pl;
    if contrace then lisp (write" depl*=",depl!*);

    if contrace then write"condi=",condi;
    vl:=append(vl,xlist); % now the full list

    inequ:=inequ0;

    %--- inequ is to stop crack if order of cf is too low
    if (densord neq 0) and 
       ((cf0=nil) or (mindensord0 neq 0)) then <<
      % for the investigation to stop if
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
    if contrace then write"inequ=",inequ;

    %--- freeing some space
    sb:=dulist:=revdulist:=deplist:=e1:=e2:=e3:=
    n:=h1:=h2:=h3:=soln:=u:=dequ:=0;

    %--- the real calculation
    if lisp(!*time) then
    write "time to formulate condition: ", lisp time() - cpu,
	  " ms    GC time : ", lisp gctime() - gc," ms"$
    solns:=crack({condi},inequ,fl,vl);

    %--- postprocessing

    lisp terpri()$
    pllist:={};
    cllist:={};
    found:=nil;
    while solns neq {} do << % for each solution (if param. are determ.)
      soln:=first solns;
      solns:=rest solns;
      condi:=first soln;

      % filtering out conservation laws found in the previous run
      cfcopy:=sub(second soln,cf);
      % any non-trivial conservation law?
      h1:=0;
      for each h2 in cfcopy do if h2 neq 0 then h1:=1;
      if h1 neq 0 then <<
        pl:=sub(second soln,pl);
        if contrace then write"cfcopy=",cfcopy," pl=",pl;
        h1:=third soln;
        if contrace then write"third soln=",h1;
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
        while h1 neq {} do << % for each potential conservation law
          % h1 is the list of lists of constants/functions
          % depending on each other
          h2:=first h1;h1:=rest h1;

          if contrace then write"h2=",h2;
          if contrace then write"cfcopy=",cfcopy;
          nontriv:=nil;
          %--- is the constant/function in the characteristic functions?
          h3:=for each e2 in cfcopy collect <<
            e3:=for each e1 in h2 sum fdepterms(e2,e1);
            if e3 neq 0 then nontriv:=t;
            e3
          >>; 
          if nontriv then <<
            for each e1 in h2 do
            if fargs e1 neq {} then lisp <<
              write"The function "$
	      fctprint list reval e1$
	      write" is not constant!";
              extraline:=t;
	      terpri()
            >>;
            %--- the currant
            h4:=reverse for each e2 in pl collect 
                for each e1 in h2 sum fdepterms(e2,e1);

            if contrace then write"h3-1=",h3,"  h4-1=",h4;
            sb:=absorbconst(h3,h2)$
            if (sb neq nil) and (sb neq 0) then <<
              h3:=sub(sb,h3);
              h4:=sub(sb,h4)
            >>;
            if contrace then write"h3-2=",h3,"  h4-2=",h4;
            if (length(h2)=1) and (fargs first h2 = {}) then <<
              e1:=first h2;
              h4:=sub(e1=1,h4);
              h3:=sub(e1=1,h3)
            >>;

            h5:=udens;
            if (densord > 0) and 
               ((cf0=nil) or (mindensord0 neq 0)) then 
            while (h5 neq {}) and freeof(h3,first h5) do h5:=rest h5;
            if h5 neq {} then << % h3 is of order densord
              cllist:=cons(h3,cllist);
              pllist:=cons(h4,pllist)
            >>
          >>
        >>;
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

        for each e1 in ulist do depnd(e1,{xlist});

        if contrace then write"cllist2=",cllist,"  pllist2=",pllist$
        on evallhseqp;
        sb:=subdif1(xlist,ulist,maxord)$
        sb:=for each e1 in sb join
            for each e2 in e1 collect(rhs e2 = lhs e2);
        if contrace then write"sb=",sb$
        off evallhseqp;
        cllist:=sub(sb,cllist);
        if contrace then write"cllist3=",cllist$
        pllist:=sub(sb,pllist);
        if contrace then write"pllist3=",pllist$
        if nx=2 then
        pllist:=simppl(pllist,ulist,first xlist,second xlist)$

        if contrace then <<
          write"cllist3=",cllist;
          write"pllist3=",pllist;
          write"eqlist=",eqlist;
          write"xlist=",xlist
        >>;
        while pllist neq {} do <<
          found:=t;
          write"Conservation law:";
          h2:=first pllist;
          h3:=first cllist;
          rtnlist:=cons({h3,h2},rtnlist);

	  %--- conditions on parameters
	  if paralist neq {} then 
	  for each e2 in second soln do
	  if not freeof(paralist,lhs e2) then 
	  <<write e2,",";lisp(terpri())>>$

          %--- the conservation laws
          h4:=eqlist;
          if paralist then h4:=sub(second soln,h4);
          n:=length h4$
          while h3 neq {} do <<
            if length h3 < n then write "+"$
            write"( ",first h3," ) * ( ",first h4," )"$
            h3:=rest h3; h4:=rest h4
          >>$
          write" = "$
          h4:=xlist$
          n:=length h4$
          while h2 neq {} do <<
            if length h2 < n then write "+"$
            write"df( ",first h2,", ",first h4," )"$
            h2:=rest h2;
            h4:=rest h4
          >>;
          write"======================================================"$
          pllist:=rest pllist;
          cllist:=rest cllist;
        >>$
      >>;
    >>;
    if found=nil then <<
      write"There is no conservation law of this order.";
      write"======================================================"$
    >>
  >>; % for densord:=mindensord:maxdensord

  if fargs(first ulist)={} then
  for each e1 in ulist do depnd(e1,{xlist});

  if lisp(!*time) then
  write "time to run conlaw3: ", lisp time() - cpustart,
        " ms    GC time : ", lisp gctime() - gcstart," ms"$

  lisp <<adjust_fnc:=adjustold;
         logoprint_:=logoold;
         potint_:=potold;
         facint_:=facold>>;

  return rtnlist

end$ % of conlaw3

end$
