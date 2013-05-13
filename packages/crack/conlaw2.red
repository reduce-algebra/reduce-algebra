
%       CONLAW version 2, to calculate conservation laws of systems
%            of PDEs by calculating characteristic functions

%                   by Thomas Wolf, June 1999, Nov 2006

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

symbolic fluid '(print_ logoprint_ potint_ facint_ adjust_fnc flin_ 
                 done_trafo inverse_trafo_list_incomplete no_current)$

%-------------

algebraic procedure conlaw2(problem,runmode)$
begin
  scalar contrace,eqlist,ulist,xlist,dequ,cllist,divlist,
  sb,densord,flist,eqord,maxord,dulist,revdulist,vl,expl,
  deplist,e1,e2,e3,n,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,
  condi,soln,potold,adjustold,udens,gensepold,non_int,
  inequ0,inequ,logoold,treqlist,fl,facold,u,nodep,subl,cpu,
  gc,cpustart,gcstart,nontriv,cf0,rtnlist,paralist,solns,
  found,clcopy,extraline,nondiv,nx,nde,nonconstc,
  mindensord,mindensord0,maxdensord,rules,new_var_fnc$

  backup_reduce_flags()$
  lisp <<adjustold:=adjust_fnc; adjust_fnc:=t;
         logoold:=logoprint_;   logoprint_:=t;
         potold:=potint_;       potint_:=t;
         facold:=facint_;       facint_:=1000>>;

  cpustart:=lisp time()$ gcstart:=lisp gctime()$
% contrace:=t;

  %--- extracting input data
  eqlist:= sqreverse maklist sqfirst problem;
  ulist := maklist sqsecond problem;
  xlist := maklist sqthird problem;
  nx:=length xlist;
  nde:=length eqlist;
  if contrace then write"eqlist=",eqlist,
  " ulist=",ulist," xlist=",xlist;

  mindensord:=sqpart(runmode,1)$
  maxdensord:=sqpart(runmode,2)$
  expl      :=sqpart(runmode,3)$
  flist     :=sqpart(runmode,4)$
  inequ0    :=sqpart(runmode,5)$
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
  for each e1 in sqreverse eqlist do write e1;
  lisp<<terpri()$write "for the function(s): "$
        fctprint cdr reval ulist;terpri()>>$
  write"======================================================"$

  %--- nodep is a list of derivatives the P do not depend on
  %--- subl is the list of lhs-derivatives to be substituted
  h1:=lhsli(eqlist)$
  nodep:=sqfirst h1$
  subl:=sqsecond h1$

  %--- Here comes a test that lhs's are properly chosen
  chksub(eqlist,ulist)$

  %--- Checking whether an ansatz for characteristic functions
  %--- has been made, then denominator of equations is not dropped
  for n:=1:nde do 
  if not lisp(null get(mkid('q_,n),'avalue)) then cf0:=t;

  eqlist:=sqreverse for each e1 in eqlist collect 
          if part(e1,0)=EQUAL then lhs e1 - rhs e1 
                              else e1;

  if contrace then write"ulist=",ulist,"    eqlist=",eqlist;

  %--- initializations to be done only once
  rtnlist:={};
  nondiv:=lisp intern gensym(); % as a marker if p-computation was not succ.

  %------ the list of parameters of the equation to be determined
  paralist:={};
  for each e1 in flist do
  if not freeof(eqlist,e1) then paralist:=sqcons(e1,paralist);

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
  for each e1 in sb do <<
    treqlist:=sub(e1,treqlist);
    nodep:=sub(e1,nodep);
    subl:=sub(e1,subl);
  >>$
  if contrace then write"treqlist=",treqlist," nodep=",nodep,
                        " subl=", subl;
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

    nodependlist(ulist);

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

    if {}=fargs sqfirst ulist then
    for each e1 in ulist do dependlist(e1,{xlist});
    sb:=subdif1(xlist,ulist,maxord)$
    nodependlist ulist;
    if contrace then write"sb=",sb;

    dulist:=ulist . sqreverse for each e1 in sb collect
                              for each e2 in e1 collect rhs e2;
    sb:=0;
    revdulist:=sqreverse dulist;      % dulist with decreasing order
    udens:=sqpart(dulist,densord+1);  % derivatives of order densord
    vl:=for each e1 in dulist join e1;
    if contrace then write"vl=",vl,"  udens=",udens;

    if not flist then fl:={}
                 else fl:=flist;

    %--- initializing characteristic functions cf, the list of functions fl
    deplist:=lisp(cons('LIST,setdiff(cdr ulist,cdr nodep))) . 
             for n:=1:densord collect listdifdif2(nodep,sqpart(dulist,n+1));
    if expl then deplist:=xlist . deplist;
    deplist:=sqreverse deplist;
    cf:={};
    for n:=1:nde do <<
      h1:=mkid(q_,n);
      if lisp(null get(mkid('q_,n),'avalue)) then <<
        nodependlist({h1});
        dependlist(h1, deplist);
        fl:=sqcons(h1,fl);
        lisp(flin_:=reval h1 . flin_)
      >>;
      cf:=sqcons(h1,cf);
    >>;
    cf:=sqreverse cf;

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
        if contrace then write"equation :",sqfirst h1;
        for each e1 in vl do    % sum over u and all its derivatives
        if lisp(reval algebraic(u) =
                car combidif algebraic(e1)) then
        << % for u and all its derivatives
          e2:=df(sqfirst h1, e1);
%         e2:=df(sqfirst(h2)*sqfirst(h1), e1); % in CONLAW4
          if e2 neq 0 then <<
            if contrace then write"e1=",e1;
            dequ:=sqfirst h2 * e2;
%           dequ:=e2;                          % in CONLAW4
            e2:=1;
            for each e3 in lisp
            cons('LIST,cdr combidif(algebraic e1)) do
            <<dequ:=totdif(dequ,sqpart(xlist,e3),e3,dulist)$
              e2:=-e2;
              if contrace then write"dequ=",dequ," e3=",e3>>;
            if e2=1 then h3:=h3+dequ
                    else h3:=h3-dequ;
            if contrace then write"h3=",h3;
          >>;
        >>;
        h1:=sqrest h1;h2:=sqrest h2
      >>;
      condi:=sqcons(h3,condi)
    >>;
    if contrace then write"condi=",condi;

    %--- generating a substitution list
    %--- at first using the equations themselves
    sb:={};
    rules:={};
    h1:=treqlist;
    h2:=subl;
    h4:=nil;       % h4 is list of undifferentiated substitutions
    while h1 neq {} do <<
      h3:=first h2; % not sqfirst to have just the symbol, not sq
      h5:=h3-(sqfirst h1)/coeffn(sqfirst h1,h3,1);
      rules:=sqcons(h3 => h5,rules)$
      lisp(e3:=combidif h3);
      % extracts the list of derivatives: u`1`1`2 --> (u, 1, 1, 2)
      lisp(h4:=cons(list(car e3, cdr e3, h5), h4))$
      % function name of h3, derivative list of h3, value of h3
      h1:=sqrest h1;
      h2:=sqrest h2;
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
          for each n in h3 do dequ:=totdif(dequ,sqpart(xlist,n),n,dulist);
          % new highest derivatives should be added to vl afterwards
          % if lower derivatives are substituted by higher derivatives
          rules:=sqcons(e1 => dequ,rules)$
          lisp(h1:=nil)
        >>                             else lisp(h1:=cdr h1);
      >>
    >>;

    if contrace then write"rules=",rules;
    let rules;
    condi:=condi;
    clearrules rules$
    if contrace then write"condi=",condi;

    vl:=sqreverse sqappend(xlist,vl); % now the full list

    inequ:=inequ0;
    %--- inequ is to stop crack if order of cf is too low
    if (densord neq 0) and 
       ((cf0=nil) or (mindensord0 neq 0)) then <<
      % investigation should stop if
      % cf is independent of highest order derivatives
      dequ:={};
      for each e1 in cf do <<
        h1:=udens;
        while h1 neq {} do <<
          dequ:=sqcons(df(e1,first h1),dequ);
          h1:=sqrest h1
        >>;
      >>;
      inequ:=sqcons(dequ,inequ)
    >>;
    let rules;
    inequ:=inequ;
    clearrules rules$
    rules:=0;
    if contrace then write"inequ=",inequ;

    if (not lisp(null get('cl_condi,'avalue))) and
       (part(cl_condi,0)=LIST) then 
    condi:=sqappend(condi,cl_condi)$

    %--- freeing some space
    sb:=revdulist:=deplist:=e1:=e2:=e3:=
    n:=h1:=h2:=h3:=soln:=u:=dequ:=0;

    %--- the real calculation
    if lisp(!*time) then
    write "time to formulate condition: ", lisp time() - cpu,
          " ms    GC time : ", lisp gctime() - gc," ms"$
    inverse_trafo_list_incomplete:=nil;  
    condi:=split_simp(condi,inequ,fl,vl,nil)$
    solns:=crack(condi,inequ,fl,vl);

    %--- postprocessing
    lisp 
    if done_trafo and cdr done_trafo then <<
     terpri()$
     if cddr done_trafo                                               then 
     write"The following transformations reverse the transformations" else
     write"The following transformation reverses the transformation"$
     terpri()$
     write"performed in the computation:"$
     algebraic write lisp done_trafo$
     if inverse_trafo_list_incomplete then <<
      write"***** The list 'done_trafo' of inverse transformations"$terpri()$
      write"      is not complete as at least one transformation"$terpri()$
      write"      could not be inverted"$terpri()$
      write"======================================================"$
      terpri()
     >>$

     % fnc_of_new_var() uses global variables done_trafo,depl!*
     % and determines all functions depending on (new) lhs variables 
     % in done_trafo
     new_var_fnc:=fnc_of_new_var()$
    >>$

    lisp terpri()$
    found:=nil;
    while solns neq {} do <<
      divlist:={};
      cllist:={};
      soln:=sqfirst solns;
      solns:=sqrest solns;
      condi:=sqfirst soln;
      cfcopy:=sub(sqsecond soln,cf);
      h1:=sqthird soln; % list of free or still to compute functions/constants
      if contrace then <<
        write"cfcopy=",cfcopy;
        write"soln=",soln;
        write"sqthird soln=",h1;
      >>;
      fl:={}; % list of functions/const. appearing in remaining equations
      h2:={};
      for each e1 in h1 do <<
        if not freeof(condi,e1) then fl:=sqcons(e1,fl); 
        % fl to output remaining conditions later
        if freeof(paralist,e1) then h2:=sqcons(e1,h2)
        % h2: list of fnc/const that are not parameters in orig equations
      >>;

      h1:=parti_fn(h2,condi)$ % h1 is a list of lists of fnc/const 
      % in h2 (i.e. unknowns that are not parameters) that depend 
      % on each other through the list of unsolved conditions condi

      if contrace then write"h1(partitioned)=",h1;
      extraline:=nil;
      nonconstc:={};
      while h1 neq {} do << 
        % i.e. for each subset of interdependent fnc/const, 
        % each subset will give one conservation law
        e1:=sqfirst h1;h1:=sqrest h1; % e1: list of free or to be det, fnc/const
        for each h4 in e1 do
        if fargs h4 neq {} then <<
          nonconstc:=sqcons(h4,nonconstc); % nonconst fnc in e1
          lisp <<
            write reval h4," = "$
            fctprint list reval h4$
            write" is not constant!";
            extraline:=t;
            terpri()
          >> 
        >>;

        dequ:=0;                                    % to compute P^i
        h2:=treqlist;                               %       "
        if paralist then h2:=sub(sqsecond soln,h2); %       "
        if contrace then write"h2=",h2;             %       "
        nontriv:=nil;
        h3:=for each e2 in cfcopy collect <<
          e3:=for each h4 in e1 sum fdepterms(e2,h4);
          dequ:=dequ+e3*sqfirst h2; h2:=sqrest h2; % computes rhs
          if e3 neq 0 then nontriv:=t;
          e3
        >>;
        if nontriv then <<
          found:=t;
          cllist:=sqcons(<<if contrace then write"h3-1=",h3,"  dequ=",dequ;
                           sb:=absorbconst(h3,e1)$
                           if (sb neq nil) and (sb neq 0) then <<
                             h3:=sub(sb,h3);
                             dequ:=sub(sb,dequ)
                           >>;
                           if contrace then write"h3-2=",h3,"  dequ=",dequ;
                           if (length(e1)=1) and (fargs sqfirst e1 = {}) then <<
                             h4:=sqfirst e1;
                             dequ:=sub(h4=1,dequ);
                             sub(h4=1,h3)
                           >>               else h3
                         >>,
                         cllist);
          divlist:=sqcons(dequ,divlist)
        >>
      >>;
      if contrace then <<
        write"characteristic functions found so far:";
        write cllist;
      >>$
      if condi neq {} then <<
        if length condi = 1 then lisp write"There is a remaining condition: "
                            else lisp write"There are remaining conditions: "$
        lisp <<
          deprint cdr algebraic condi;
          write"for the function(s): ";
          fctprint cdr reval algebraic fl;terpri();
        >>;
        extraline:=t;
      >>;
      if extraline then lisp <<
        write"- - - - - - - - - - - - - - - - - - - - - - - - - - - "$
        terpri()
      >>;

      %--- Dropping conservation laws of too low order
      if contrace then write"Start of dropping CLs of too low order"$
      if (densord > 0) and 
         ((cf0=nil) or (mindensord0 neq 0)) then <<
        h1:={};
        h2:={};
        for each e1 in cllist do <<
          if contrace then <<write"----- Consideration of: "$write"e1-0=",e1>>$
          e2:={};
          % At first we collect all independent variables of all functions 
          % that appear in e1 to get e2
          for each h5 in sqthird soln do
          if not freeof(e1,h5) then e2:=sqappend(fargs h5,e2);
          if contrace then write"e2-1=",e2$

          % Then, if transformations have been done, we transform backwards.
          % In doing that it is possible that general parameters from
          % the equation are introduced, which have specific values
          % in this solution. Therefore second soln is substituted again

          if contrace then <<write"done_trafo=",lisp done_trafo$
                             write"paralist=",paralist>>$
          e3:=e1;
          if {} neq lisp done_trafo then <<
            for each h5 in lisp done_trafo do <<
              e3:=sub(h5,e3);
              e2:=sub(h5,e2);
            >>$ 
            if paralist neq {} then <<
              e3:=sub(sqsecond soln,e3);
              e2:=sub(sqsecond soln,e2)
            >>
          >>$
          if contrace then <<write"e1-2=",e3$write"e2-2=",e2>>$

          % Then we check the differential order of the expressions
          h5:=udens;
          while (h5 neq {}) and 
                freeof(e3,lisp reval algebraic sqfirst h5) and
                freeof(e2,lisp reval algebraic sqfirst h5) do h5:=sqrest h5;
          if h5 neq {} then <<
            h1:=sqcons(e1,h1);
            h2:=sqcons(sqfirst divlist,h2)
          >>           else 
          if length e1 = 1 then 
          write "Multiplier ",first e1,
                " is dropped because it is of too low order."
                           else
          write "Multipliers ",e1,
                " are dropped because they are of too low order.";
          divlist:=sqrest divlist;
        >>;
        cllist:=h1;
        divlist:=h2
      >>;

      if contrace then <<write"End of dropping CLs of too low order"$
                         write"cllist=",cllist;
                         write"divlist=",divlist>>$

      if contrace then write"Start of back-transformations"$
      % Backtransformation of all performed (point-)transformations
      lisp (
      if done_trafo and cdr done_trafo then <<

       % h1 collects all new variables
       h1:=for each h3 in cdr done_trafo join
           for each h6 in cdr h3 collect cadr h6$

       % h2 collects all derivatives 
       h2:=search_li2(cllist,'DF)$

       % h3 all derivatives wrt. new variables
       h3:=nil;
       while h2 do <<
        if not freeoflist(car h2,h1) then h3:=cons(car h2,h3);
        h2:=cdr h2
       >>;

       % h8 are all derivatives such that there is only one derivative 
       % for that function
       h8:=nil;
       h9:=h3;
       while h9 do <<
        if freeof(cdr h9,cadar h9) then <<
         h8:=cons(car h9,h8);
         h9:=cdr h9
        >>                         else <<
         h7:=nil;
         for each h2 in h9 do
         if freeof(h2,cadar h9) then h7:=cons(h2,h7);
         h9:=h7
        >> 
       >>$

       % All derivatives wrt new variables are temporarily renamed
       h5:=nil; 
       for each h4 in h3 do <<
        h7:=gensym()$
        h5:=cons((h4 . h7),h5);
        cllist:=subst(h7,h4,cllist);
        divlist:=subst(h7,h4,divlist);
       >>;

       % Backtransformation
       for each h4 in cdr done_trafo do algebraic <<
        cllist :=sub(h4,cllist);
        divlist:=sub(h4,divlist)
       >>$

       % Derivatives are back-substituted
       for each h4 in h5 do 
       if member(car h4,h8) and
          freeof(condi,cadar h4) and
          freeof(cllist,cadar h4) and
          freeof(divlist,cadar h4) then <<
        algebraic (write"To simplify the following output we rename ",
        lisp(car h4)," --> ",lisp(cadar h4)," .")$
        cllist:=subst(cadar h4,cdr h4,cllist);
        divlist:=subst(cadar h4,cdr h4,divlist)
       >>                          else <<
        cllist:=subst(car h4,cdr h4,cllist);
        divlist:=subst(car h4,cdr h4,divlist);
       >>$
      >>)$      

      % For all conservation laws which involve free functions depending
      % on new variables from done_trafo, print the characteristic functions
      % and drop them from cllist to stop processing them further

      if nil then
      if {} neq lisp done_trafo then <<
	h2:={}$ h3:={}$
        lisp <<
          h6:=cllist;
          h7:=divlist;
          if h6 then 
          while cdr h6 do 
          if freeoflist(search_li(cdadr h6,'DF),new_var_fnc) then 
          <<h6:=cdr h6;h7:=cdr h7>>                          else <<
            print_dropping_notice(cadr h6)$
            rplacd(h6,cddr h6)$
            rplacd(h7,cddr h7)$
          >>
        >>$
      >>$
      if contrace then write"End of back-transformations"$

      if cllist neq {} then <<

        if lisp no_current neq nil then <<
         % The computation of conserved currents is not attempted,
         % for example, because in an earlier attempt it got stuck.
         non_int:=for e1:=1:(length cllist) collect e1$
         h1:={}
        >>                         else <<

          %--- Below h1 is the list of W^i in the Anco/Bluman formula
          h1:=for e1:=1:(length cllist) collect
          {intcurrent1(reval sqpart(divlist,e1),ulist,xlist,dulist,nx,
                       eqord,densord),e1};                                   
          % the index is attached to identify the corresponding cl in cllist 

          %--- Backsubstitution of e.g. u`1`1 --> df(u,x,2) 
          for each e1 in ulist do dependlist(e1,{xlist});
          on evallhseqp;
          sb:=subdif1(xlist,ulist,maxord)$
          sb:=for each e1 in sb join
              for each e2 in e1 collect(rhs e2 = lhs e2);
          off evallhseqp;
          cllist:=sub(sb,cllist);
          h2:=sub(sb,h1);   h1:={}$   non_int:={}$                     
          for each e1 in h2 do
          if lisp(freeof(e1,'SUB)) then h1:=sqcons(e1,h1)                   
                                   else non_int:=sqcons(sqsecond e1,non_int);
          h2:=0$
          if h1 neq {} then <<
            %--- lambda integration of h1 to compute P_i
            h2:=lisp intern gensym()$
            for each e1 in ulist do <<
              h10:={}$
              for each e2 in h1 do <<
                h8:=sub(e1=h2*e1,e2);
                if lisp freeof(h8,'SUB) then h10:=sqcons(h8,h10)
                                        else non_int:=sqcons(sqsecond h8,non_int)
              >>$
              h1:=h10$
            >>$ 

            if h1 neq {} then 
            h1:=for each e1 in h1 collect << % i.e. for each cl
              e3:=sqsecond e1$
              h10:=sub(sb,sqpart(divlist,e3)); 
              e1:=sqfirst e1$

              % at first try direct integration to compute p
              h9:=intcurrent2(h10,sqappend(nonconstc,ulist),xlist);
              if sqsecond h9 = 0 then h9:=sqfirst h9
                                 else << % no success --> use lambda-integration
                h9:=nondiv;
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
                    %--- the following is to catch errors in: 
                    %--- int(h10*h2**(nx-1),h2)
                    h10:=if not lisp freeof(h10,'SUB) then nil 
                         else err_catch_int(h10*h2**(nx-1),h2)$
                    if contrace then write"h10-3=",h10$ 
                    if h10 eq nil then h6:=nil
                                  else
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
                  e2:=sqfirst e1; 
                  e1:=sqrest e1;
                  if contrace then write"e2=",e2$ 
                  h3:=err_catch_int(e2/h2,h2)$
                  if contrace then write"h3-1=",h3$ 

                  %--- the following is to catch errors in: 
                  %--- sub(h2=1,h3)-sub(h2=0,h3)
                  h6:=err_catch_sub(h2,1,h3);
                  if h6 eq nil then h7:=nil
                               else h7:=err_catch_sub(h2,0,h3);
                  if h7 eq nil then h8:=nil
                               else h4:=sqcons(h6-h7+h10*sqpart(xlist,h11),h4)
                >>;
                if h8 then h9:=sqreverse h4
              >>;
              {h9,e3}
            >>
          >>;
          if contrace then write"h1-1=",h1$
        >>$

        % Output
        for each e2 in non_int do <<
          lisp <<terpri()$
                 write"Conservation law:";terpri()$
                 write"-----------------";terpri() >>;

          %--- conditions on parameters
          if paralist neq {} then 
          for each h3 in sqsecond soln do
          if not freeof(paralist,lhs h3) then 
          <<write h3,",";lisp(terpri())>>;

          %--- Backsubstitution of e.g. u`1`1 --> df(u,x,2) 
          for each e1 in ulist do dependlist(e1,{xlist});
          on evallhseqp;
          sb:=subdif1(xlist,ulist,maxord)$
          sb:=for each e1 in sb join
              for each e2 in e1 collect(rhs e2 = lhs e2);
          off evallhseqp;
          cllist:=sub(sb,cllist);

          %--- substitution of parameter values
          h3:=sqpart(cllist,e2); h4:=eqlist; 
          if paralist neq {} then <<
           h4:=sub(sqsecond soln,h4);
           h3:=sub(sqsecond soln,h3);
          >>$

          %--- printing the conservation law
          write  "  ( ",sqfirst h3," ) * ( ",sqfirst h4," )"$ 
          h9:=sqfirst h3 * sqfirst h4$
          h3:=sqrest h3$ h4:=sqrest h4$
          while h3 neq {} do <<
            write"+ ( ",sqfirst h3," ) * ( ",sqfirst h4," )"$ 
            h9:=h9 + sqfirst h3 * sqfirst h4$
            h3:=sqrest h3$ h4:=sqrest h4$
          >>$
          write "= ",h9$  % = sqpart(divlist,e2)

          lisp <<
            write"should be a divergence but the program was"$
            terpri()$
            if no_current then 
            write"not instructed to try finding the conserved current."
                          else
            write"not able to find the conserved current."$
            terpri()$
          >>;
          if condi neq {} then lisp <<
            write"For that the remaining conditions should be applied.";
            terpri()
          >>$
          write"======================================================"$
        >>$
        if contrace then <<
          write"h1=",h1;write"cllist=",cllist;write"eqlist=",eqlist
        >>;
        while h1 neq {} do <<
          h9:=sqsecond sqfirst h1$ % the index of the conservation law
          h2:=sqfirst  sqfirst h1$
          h1:=sqrest h1;
          h3:=sqpart(cllist,h9);

          %--- conditions on parameters
          if paralist neq {} then 
          for each e2 in sqsecond soln do
          if not freeof(paralist,lhs e2) then 
          <<write e2,",";lisp(terpri());
            h2:=sub(e2,h2);
            h3:=sub(e2,h3)
          >>$

          rtnlist:=sqcons({h3,h2},rtnlist);

          %--- the conservation laws

          %--- Test whether actually only an adjoint symmetry has been
          %--- computed and not a conservation law
          h4:=eqlist;
          if paralist neq {} then h4:=sub(sqsecond soln,h4);

          h8:=0;                       
          if h2 neq nondiv then <<
            h5:=h4;                     
            for each e1 in h3 do <<
              h8:=h8 + e1*(sqfirst h5)$  
              h5:=sqrest h5 
            >>$
            for e1:=1:nx do <<
              h8:=h8-df(sqpart(h2,e1),sqpart(xlist,e1))$ % for test purposes
            >>;
            if h8 neq 0 then h2:=nondiv
          >>;

          if h2 neq nondiv then <<
            if nx=2 then
            h2:=sqfirst simppl({h2},ulist,sqfirst xlist,sqsecond xlist)$
            lisp <<terpri()$
                   write"Conservation law:";terpri()$
                   write"-----------------";terpri() >>;
            print_claw(h4,h3,h2,xlist)$  % print_claw(eqlist,qlist,plist,xlist)$
        
            %--- factoring out diff operators?
            h6:={};
            for each h5 in nonconstc do
            if not freeof(h3,h5) then h6:=sqcons(h5,h6);
            if h6 neq {} then partintdf(h4,h3,h2,xlist,h6,vl,sb) 
          >>               else <<
            write"Adjoint symmetry:";
            write  "  ( ",sqfirst h3," ) * ( ",sqfirst h4," )"$ 
            h3:=sqrest h3; h4:=sqrest h4$
            while h3 neq {} do <<
              write"+ ( ",sqfirst h3," ) * ( ",sqfirst h4," )"$ 
              h3:=sqrest h3; h4:=sqrest h4
            >>$

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
              write"then the found characteristic function represents ",
                   "a conservation law"$
            >>
          >>;
          write"======================================================"$
        >>$
      >>;   %   if cllist neq {} then <<
      nodependlist(ulist);
    >>;    %   while solns neq {} do <<
    if found=nil then <<
      write"There is no conservation law of this order.";
      write"======================================================"$
    >>
  >>;   %   for densord:=mindensord:maxdensord

  if fargs sqfirst ulist = {} then
  for each e1 in ulist do dependlist(e1,{xlist});

  if lisp(!*time) then
  write "time to run conlaw2: ", lisp time() - cpustart,
        " ms    GC time : ", lisp gctime() - gcstart," ms"$

  lisp <<adjust_fnc:=adjustold;
         logoprint_:=logoold;
         %gensep_:=gensepold;
         potint_:=potold;
         facint_:=facold>>;
  recover_reduce_flags()$

  return rtnlist

end$ % of conlaw2

end$

