
%      CONLAW version 1, to calculate conservation laws of systems
%              of PDEs by calculating the conserved currents

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
                 done_trafo inverse_trafo_list_incomplete)$ 

%-------------

algebraic procedure conlaw1(problem,runmode)$
begin
  scalar contrace,eqlist,ulist,xlist,dequ,cllist,pllist,
  sb,densord,flist,eqord,maxord,dulist,revdulist,vl,expl,
  deplist,e1,e2,e3,n,h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,condi,
  soln,soln2,adjust_old,potold,adjustold,udens,gensepold,
  inequ0,inequ,logoold,treqlist,fl,fl2,facold,u,nodep,subl,
  cpu,gc,cpustart,gcstart,found,cf0,rtnlist,deglist,maxdf,
  qlist,extraorder,nx,nde,highdensord,print_old,paralist,
  plcopy,desyli,ddesyli,vl1,lhsord,loworderlimit,extraline,
  rules,nonconstc,new_var_fnc;

  backup_reduce_flags()$
  lisp <<adjustold:=adjust_fnc; adjust_fnc:=t;
         logoold:=logoprint_;   logoprint_:=t;
         potold:=potint_;       potint_:=t;
         facold:=facint_;       facint_:=1000>>;

  cpustart:=lisp time()$ gcstart:=lisp gctime()$
  % contrace:=t;

  %--- extracting input data
  eqlist:= maklist sqfirst problem;
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
    write "This is CONLAW1 - a program for calculating conservation",
    " laws of DEs"; terpri()
  >>                 else terpri());
  if nde = 1 
  then write "The DE under investigation is :"
  else write "The DEs under investigation are :";
  for each e1 in eqlist do write e1;
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
  eqlist:=sqreverse for each e1 in eqlist collect 
          if part(e1,0)=equal then lhs e1 - rhs e1 
                              else e1;

  if contrace then write"ulist=",ulist,"    eqlist=",eqlist;

  %--- initializations to be done only once
  rtnlist:={};
  deglist:={};

  %------ the list of parameters of the equation to be determined
  paralist:={};
  for each e1 in flist do
  if not freeof(eqlist,e1) then paralist:=sqcons(e1,paralist);

  %------ determination of the order of the input equations
  eqord:=0;       % the max. degree of any equation
  extraorder:=0;  % increase of order through substitution
  lhsord:=0;      % max. order of an lhs
  for e1:=1:nde do <<
    e3:=sqpart(eqlist,e1);
    h2:=0; % degree of this equation
    h3:=totdeg(sqpart(subl,e1),sqpart(ulist,e1));
    if h3>lhsord then lhsord:=h3;
    for each e2 in ulist do <<
      h1:=totdeg(e3,e2);
      if h1>h2 then h2:=h1;
      if h1>eqord then eqord:=h1;
    >>;
    deglist:=sqcons(h2,deglist);
    if h2>h3 then extraorder:=extraorder+h2-h3;
  >>;
  deglist:=sqreverse deglist;

  %------ determination of the order of the ansatz
  for n:=1:nx do <<
    % if the index of p_ should be a number then use n instead of h4
    h4:=lisp(reval algebraic(sqpart(xlist,n)));
    h1:=mkid(p_,h4);
    if not lisp(null get(mkid('p_,h4),'avalue)) then <<
      for each e2 in ulist do <<
        h2:=totdeg(h1,e2);
        if h2>eqord then eqord:=h2;
        if h2>mindensord then mindensord:=h2
      >>;
      cf0:=t;
    >>
  >>;
  if contrace then write"eqord=",eqord,"   mindensord=",mindensord,
                   "   extraorder=",extraorder,"   lhsord=",lhsord$;
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
  for n:=1:nx do <<
    % if the index of p_ should be a number then use n instead of h4
    h4:=lisp(reval algebraic(sqpart(xlist,n)));
    h1:=mkid(p_,h4);
    if not lisp(null get(mkid('p_,h4),'avalue)) then <<
      for each e1 in sb do h1:=sub(e1,h1);
      lisp(mkid('p_,h4)):=h1;
    >>
  >>;
  for each e1 in sb do inequ0:=sub(e1,inequ0);

  %--- investigate conservation laws of increasing order
  for densord:=mindensord:maxdensord do <<

    cpu:=lisp time()$ gc:=lisp gctime()$
    if cf0 then
    lisp<<write"A special ansatz of order ",densord," for the",
               " conserved current is investigated.";
          terpri()>>  else
    lisp<<write"Currently conservation laws with a conserved",
               " density";terpri()$
          write"of order ",densord," are determined";terpri();
         write"======================================================"$
    >>;

    if densord+1<lhsord then lisp << write
      "The order of the ansatz is too low for substitutions of equations"$
      terpri()$write"to be done --> no investigation"$terpri()$terpri()
    >>                  else <<     
      % If densord+1=lhsord then conservation laws of lower order
      % than the ansatz are to be considered because this is the
      % first time they can appear because for a lower order ansatz
      % substitutions can not be made and no non-trivial CLs can be detected
      if densord+1=lhsord then loworderlimit:=nil
                          else loworderlimit:=t;
      if contrace then write"loworderlimit=",loworderlimit$   
      %--- repeated initializations

      highdensord:=densord+extraorder;   %--- the max. order of P_xi
         % which is the the order of P_x1 (densord) plus  extraorder 
         % to get the max order P_x2,P_x3,...
      maxord:=highdensord+1+extraorder;  %--- the maximal order of
         % derivatives in condition, = highdensord + extraorder due 
         % to substitutions + 1 due to Div
      if contrace then write"densord=",densord,"  highdensord=",highdensord,
                            "  maxord=",maxord;

      if {}=fargs sqfirst ulist then
      for each e1 in ulist do dependlist(e1,{xlist});
      sb:=subdif1(xlist,ulist,maxord)$
      nodependlist ulist;

      if contrace then write"sb=",sb;

      dulist:=ulist . sqreverse for each e1 in sb collect
                              for each e2 in e1 collect rhs e2;
      revdulist:=sqreverse dulist;           % dulist with decreasing order
      udens:=sqpart(dulist,densord+1);       % derivatives of order densord
      vl:=for each e1 in dulist join e1;
      if contrace then write"vl=",vl,"  udens=",udens;
      vl1:=for e1:=1:(highdensord+2) join sqpart(dulist,e1);
      % vl1 is to generate subst. of u-deriv. up to order highdensord+1
      if contrace then write"vl1=",vl1;


      %--- initializing the list of unknown functions fl,
      %--- the conserved current pl and the condition condi
      if not flist then fl:={}
                   else fl:=flist;
      deplist:=lisp(cons('list,setdiff(cdr ulist,cdr nodep))) . 
               for n:=1:highdensord collect 
               listdifdif2(nodep,sqpart(dulist,n+1));
      deplist1:=for h3:=1:(densord+1) collect sqpart(deplist,h3);
      if expl then << deplist :=xlist . deplist;
                      deplist1:=xlist . deplist1>>;
      deplist :=sqreverse deplist;
      deplist1:=sqreverse deplist1;

      if contrace then lisp (write"1. depl*=",depl!*);
      pl:={};
      condi:=0;
      for n:=1:nx do <<
        % if the index of p_ should be a number then use n instead of h4
        h4:=lisp(reval algebraic(sqpart(xlist,n)));
        h1:=mkid(p_,h4);
        if lisp(null get(mkid('p_,h4),'avalue)) then <<
          nodependlist({h1}); 
          if n=1 then dependlist(h1, deplist1)
                 else dependlist(h1, deplist);
          fl:=h1 . fl;
          lisp(flin_:=reval h1 . flin_)
        >>;%                                      else h1:=sub(sb,h1);
        pl:=sqcons(h1,pl);
        condi:=condi+totdif(h1,h4,n,dulist)
      >>;
      pl:=sqreverse pl;

      if contrace then write"fl=",fl," cf=",cf," pl=",pl;
      if contrace then lisp (write"2. depl*=",depl!*);
      if contrace then write"condi=",condi;
      if contrace then write"udens=",udens;

      %--- generating a substitution list with equations represented
      % by a symbol and derivatives of equations represented by
      % derivatives of that symbol

      %--- at first using the equations themselves
      sbreserve:={};
      desyli:={};     % list of symbols each representing an equation
      ddesyli:={};    % list of all these symbols + their derivatives
      % with the following structure: each element of ddesyli has
      % the form {derivative of the symbol, 
      %           {numbers of the differentiation variables}, 
      %           number of the symbol}
      h1:=treqlist;
      h2:=subl;
      h5:=0;          % h5 is an index of the equations
      while h1 neq {} do <<
        h5:=h5+1;
        h4:=lisp intern gensym();
        dependlist(h4,{xlist});
        desyli :=sqcons(h4, desyli);
        ddesyli:=sqcons({h4,{},h5},ddesyli);
        h3:=sqfirst h2;
        if h3 neq 0 then
        sbreserve:=sqcons(h3 = h3 - (sqfirst h1)/coeffn(sqfirst h1,h3,1) + h4, 
                          sbreserve);
        h1:=sqrest h1;
        h2:=sqrest h2;
      >>;
      sbreserve:=sqreverse sbreserve;
      desyli:=sqreverse desyli;
      if contrace then write"rev desyli=",desyli;
      %--- then their derivatives
      h1:=sbreserve;
      lisp(h2:=nil);  % h2 is list of underived substitutions
      for each e1 in h1 do lisp <<
        e3:=combidif(algebraic lhs e1);
        h2:=cons(list(car e3, cdr e3, algebraic rhs e1), h2)
        % function name and derivative list of e1
      >>;
      for each e1 in vl1 do lisp <<  % e1 occurs in condi
        h1:=h2;
        h5:=0;        % counter of the equation
        while h1 neq nil do <<
          h5:=h5+1;
          h3:=comparedif2(caar h1, cadar h1, reval algebraic e1);
          if (h3 neq nil) and (h3 neq 0) then algebraic <<
            h3:=lisp(cons('list,h3));
            dequ:=lisp caddar h1; % rhs which is to be differentiated
            for each n in h3 do dequ:=totdif(dequ,sqpart(xlist,n),n,dulist);
            % new highest derivatives should be added to vl afterwards
            % if lower derivatives are substituted by higher derivatives
            h6:=sqpart(desyli,h5);
            for each n in h3 do h6:=df(h6,sqpart(xlist,n));
            ddesyli:=sqcons({h6,h3,h5}, ddesyli);
            sbreserve:=sqcons(e1 = dequ, sbreserve);
            lisp(h1:=nil)
          >>                             else lisp(h1:=cdr h1);
        >>
      >>;
      if contrace then write"sbreserve=",sbreserve;
      sb:=sub(for each e1 in desyli collect e1=0,sbreserve);
      if contrace then write"sb=",sb;

      rules:={};
      for each e1 in sb do <<
       h5:=lhs e1; h6:=rhs e1;
       rules:=sqcons(h5 => h6,rules)
      >>$
      if contrace then write"rules=",rules;
      let rules; 
      condi:=condi;
      clearrules rules$
      if contrace then write"condi=",condi;

      vl:=sqreverse sqappend(xlist,vl); % now the full list

      inequ:=inequ0;
      %--- inequ is to stop crack if order of pl is too low
      if loworderlimit then <<
        % for the investigation to stop if
        % P_x1 is independent of derivatives of order densord
        dequ:={};
        e1:=sqfirst pl;
        h1:=udens;
        while h1 neq {} do <<
          dequ:=sqcons(df(e1,first h1),dequ);
          h1:=sqrest h1
        >>;
        inequ:=sqcons(dequ,inequ)
      >>;
      if contrace then write"inequ=",inequ;
      condi:={condi};

      if (not lisp(null get('cl_condi,'avalue))) and
         (part(cl_condi,0)=list) then 
      condi:=sqappend(condi,cl_condi)$

      %--- freeing some space
      sb:=revdulist:=e1:=e2:=e3:=
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
      pllist:={};
      cllist:={};
      found:=nil;
      while solns neq {} do << % for each solution (if param. are determ.)
        soln:=sqfirst solns;
        solns:=sqrest solns;
        condi:=sqfirst soln;
        plcopy:=sub(sqsecond soln,pl);
        h1:=sqthird soln;        % list of free/undeterm. const./functions
        if contrace then <<
          write"plcopy=",plcopy;
          write"soln=",soln;
          write"third soln=",h1;
        >>;
        fl:={};
        h2:={};

        for each e1 in h1 do <<
          if not freeof(condi,e1) then fl:=sqcons(e1,fl); 
          % fl to output remaining conditions later
          if freeof(paralist,e1) then h2:=sqcons(e1,h2)
        >>;

        h1:=parti_fn(h2,condi)$ % h1 is a list of lists of fnc/const 
        % in h2 (i.e. unknowns that are not parameters) that depend 
        % on each other through the list of unsolved conditions condi

        if contrace then write"h1(partitioned)=",h1;

        extraline:=nil;
        nonconstc:={};
        % h1 is the list of lists of constants/functions
        % depending on each other
        while h1 neq {} do << 
          % i.e. for each subset of interdependent fnc/const, 
          % each subset will give one conservation law
          h2:=sqfirst h1;h1:=sqrest h1;

          if contrace then write"h2=",h2;
          %--- h4 is the currant for a single conservation law
          h4:=for each e2 in plcopy collect
              for each e1 in h2 sum fdepterms(e2,e1);

          if contrace then write"h4-1=",h4;
          sb:=absorbconst(h4,h2)$
          if (sb neq nil) and (sb neq 0) then h4:=sub(sb,h4);
          if contrace then write"h4-2=",h4;
          if (length(h2)=1) and (fargs sqfirst h2 = {}) then <<
            e1:=sqfirst h2;
            h4:=sub(e1=1,h4);
          >>;

          if contrace then write"udens=",udens;
          h5:=udens;
          if (cf0=nil) and loworderlimit then 
          while (h5 neq {}) and <<
            h6:=h4;
            while (h6 neq {}) and
                  freeof(sqfirst h6,lisp reval algebraic sqfirst h5) do 
            h6:=sqrest h6;
            if h6={} then t else nil
          >> do h5:=sqrest h5;
          if contrace then write"h5=",h5;
          if h5 neq {} then <<  
            % P_x1 in h4 is of order densord or no loworderlimit
            % h3 is the lhs of the conservation law
            h3:=for e1:=1:nx sum
                totdif(sqpart(h4,e1),sqpart(xlist,e1),e1,dulist);
            if contrace then write"h3-1=",h3;
            if h3 neq 0 then << % non-trivial conservation law
              %--- Compute the characteristic functions
              %--- We have already h3 = Div P 
              h3:=sub(sbreserve,h3);
              if contrace then write"h3-2=",h3;
              if contrace then write"ddesyli=",ddesyli;
              divlist:={};
              for each e1 in ddesyli do <<
                h6:=coeffn(h3,sqfirst e1,1);
                if h6 neq 0 then <<
                  h3:=h3-h6*sqfirst e1;
                  divlist:=sqcons({h6,sqsecond e1,sqthird e1},divlist)
                >>
              >>;
              if contrace then write"h3-3=",h3;
              if contrace then write"divlist=",divlist;

              qlist:=for e1:=1:nde collect 0;
              for each e1 in divlist do << % for each derivative of an equ.
                h9:=sqfirst e1;       % the coeff of the equn. derivative
                e2:=sqsecond e1;
                h10:=sqthird e1;
                if h9 neq 0 then 
                if e2={} then
                qlist:=part(qlist,h10):=
                       part(qlist,h10)+h9
                         else <<
                  h6:=-1;             % the alternating sign
                  if length e2>1 then <<
                    h7:=sqpart(treqlist,h10);
                    if paralist neq {} then h7:=sub(sqsecond soln,h7);
                    h8:=for each e2 in sqrest sqsecond e1 collect
                    h7:=totdif(h7,sqpart(xlist,e2),e2,dulist)$
                  >>             else h8:={};
                 h8:=sqappend(h8,{sqpart(treqlist,h10)});
                  while e2 neq {} do <<
                    e3:=sqfirst e2; e2:=sqrest e2;
                    h4:=part(h4,e3):=
                        part(h4,e3)+h6*h9*(sqfirst h8);
                    h9:=totdif(h9,sqpart(xlist,e3),e3,dulist)$
                    if e2 neq {} then <<
                      h8:=sqrest h8;
                      h6:=-h6;
                    >>           else 
                    qlist:=part(qlist,h10):=
                           part(qlist,h10)+h6*h9
                  >>;
                >>;
              >>;
              %--- Is the CL trivial, i.e. all Q's are 0 ?
              e2:=t;
              for each e1 in qlist do
              if e1 neq 0 then e2:=nil;
              if e2 then h4:=nil;

              if h4 then <<
                for each e1 in h2 do 
                if fargs e1 neq {} then lisp <<
                  nonconstc:=cons('list,cons(reval e1,cdr nonconstc));
                  write reval e1," = "$
                  fctprint list reval e1$
                  write" is not constant.";
                  extraline:=t;
                  terpri()
                >>;
                cllist:=sqcons(qlist,cllist);
                pllist:=sqcons(h4,pllist);
              >>;
              if contrace then write"cllist=",cllist;
              if contrace then write"pllist=",pllist$
            >>
          >>
        >>;
        if condi neq {} then <<
          lisp write"There are remaining conditions: "$
          write condi;
          lisp <<
            write"for the functions: ";
            fctprint cdr reval algebraic fl;terpri();
          >>;
          extraline:=t;
        >>;
        if extraline then lisp <<
          write"- - - - - - - - - - - - - - - - - - - - - - - - - - - "$
          terpri()
        >>;
        for each e1 in ulist do dependlist(e1,{xlist});
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
        pllist:=simppl(pllist,ulist,sqfirst xlist,sqsecond xlist)$

        if contrace then <<
          write"cllist3=",cllist;
          write"pllist3=",pllist;
          write"eqlist=",eqlist;
          write"xlist=",xlist
        >>;
        while pllist neq {} do <<
          h2:=sqfirst pllist;
          h3:=sqfirst cllist;
          %-- Is any P_x of order densord? To be tested only now after simppl
          e1:=ulist;
          if (cf0=nil) and loworderlimit then
          while (e1 neq {}) and <<
            h4:=h2;
            while (h4 neq {}) and 
                  (totdeg(sqfirst h4,sqfirst e1) < densord) do h4:=sqrest h4;
            if h4={} then t else nil
          >> do e1:=sqrest e1;
          if e1 neq {} then <<
            found:=t;
            write"Conservation law:";

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
            if 0 = (for each e1 in h3 sum e1) then <<
              write" = 0 "$
              h4:=xlist$
              while h2 neq {} do <<
                if length h2 < nx then write "+"$
                write"df( ",sqfirst h2,", ",sqfirst h4," )"$
                h2:=sqrest h2;
                h4:=sqrest h4
              >>
            >>                                else <<
              h4:=eqlist;
              if paralist then h4:=sub(sqsecond soln,h4);
              print_claw(h4,h3,h2,xlist)$

              %--- factoring out diff operators?
              h6:={};
              for each h5 in nonconstc do
              if not freeof(h3,h5) then h6:=sqcons(h5,h6);
              if (h6 neq {}) and 
                 (h2 neq nondiv) then partintdf(h4,h3,h2,xlist,h6,vl,sb);

            >>;
            write"======================================================"$
          >>;
          pllist:=sqrest pllist;
          cllist:=sqrest cllist;
        >>$
        if solns neq {} then nodependlist(ulist); 
      >>;
      sbreserve:=0;
      nodependlist(desyli); 
      if found=nil then <<
        write"There is no conservation law of this order.";
        write"======================================================"
      >>$
    >>
  >>; % for densord:=mindensord:maxdensord

  if fargs(sqfirst ulist)={} then
  for each e1 in ulist do dependlist(e1,{xlist});

  if lisp(!*time) then
  write "time to run conlaw1: ", lisp time() - cpustart,
        " ms    GC time : ", lisp gctime() - gcstart," ms"$

  lisp <<adjust_fnc:=adjustold;
         logoprint_:=logoold;
         potint_:=potold;
         facint_:=facold>>;
  recover_reduce_flags()$
  return rtnlist

end$ % of conlaw1

end$
