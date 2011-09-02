module groebnr2; % Part 2 of the Groebner package.

imports groebner,vdp2dip;

create!-package('(groebnr2 groebman glexconv groebres groebmes
                  groebrst groebtra groeweak hilberts hilbertp),
                '(contrib groebner));

% Other packages needed.

load!-package 'groebner;

endmodule;


module groebman;  % Operators for manipulation of bases and 
                  % polynomials in Groebner style.


fluid '(!*factor !*complex !*exp); % standard REDUCE switch
fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*fullreduction !*groebstat !*groebprot !*gltbasis
        !*groebsubs

        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*              % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*            % current domain for base coeffs.
        vbcmodule!*            % for modular calculation: current prime
       );

global '(groebrestriction        % interface: name of function
         groebresmax            % maximum number of internal results
         gvarslast                 % output: variable list 
         groebprotfile
         gltb
        );

flag ('(groebrestriction groebresmax gvarslast groebprotfile
        gltb),'share);

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);

% control of the polynomial arithmetic actually loaded
fluid '(currentvdpmodule!*);

symbolic procedure gsorteval pars;
% reformat a polynomial or a list of polynomials by a distributive
% ordering; a list will be sorted  and zeros are elimiated
   begin scalar vars,u,v,w,oldorder,nolist,!*factor,!*exp,!*gsugar;
         integer n,pcount!*; !*exp := t;
      n := length pars;
      u := reval car pars;
      v := if n>1 then reval cadr pars else nil;
      if not eqcar(u,'list) then
      <<nolist := t; u := list('list,u)>>;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then vdperr 'gsort;
      oldorder := vdpinit vars;
      w := for each j in w collect a2vdp j;
      w := vdplsort w;
      w := for each x in w collect vdp2a x;
      while member(0,w) do w := delete(0,w);
      setkorder oldorder;
      return if nolist and w then car w else 'list . w;
   end;

put('gsort,'psopfn,'gsorteval);


symbolic procedure gspliteval pars;
% split a polynomial into leading monomial and reductum;             
   begin scalar vars,x,u,v,w,oldorder,!*factor,!*exp,!*gsugar;
         integer n,pcount!*; !*exp := t;
      n := length pars;
      u := reval car pars;
      v := if n>1 then reval cadr pars else nil;
      u := list('list,u);
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then  vdperr 'gsplit;
      oldorder := vdpinit vars;
      w := a2vdp car w;
      if vdpzero!? w then x := w else
      <<x := vdpfmon(vdplbc w,vdpevlmon w);
        w := vdpred w>>;
      w := list('list,vdp2a x,vdp2a w);
      setkorder oldorder;
      return w;
   end;

put('gsplit,'psopfn,'gspliteval);


symbolic procedure gspolyeval pars;
% calculate the S Polynomial from two given polynomials
   begin scalar vars,u,u1,u2,v,w,oldorder,!*factor,
                   !*exp,!*gsugar;
         integer n,pcount!*;  !*exp := t;
      n := length pars;
      if n<2 or n#>3 then
           rerror(groebnr2,1,"GSpoly, illegal number or parameters");
      u1:= car pars; u2:= cadr pars;
      u := list('list,u1,u2);
      v := if n>2 then groerevlist caddr pars else nil;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars := if null v then
                for each j in gvarlis w collect !*a2k j
            else v;
      if not vars then vdperr 'gspoly;
      oldorder := vdpinit vars;
      w := for each j in w collect a2vdp j;
      w := vdp2a groebspolynom3 (car w,cadr w);
      setkorder oldorder;
      return w;
   end;

put('gspoly,'psopfn,'gspolyeval);




symbolic procedure gvarseval u;
% u is a list of polynomials; gvars extracts the variables from u
   begin integer n; scalar v,!*factor,!*exp!*gsugar; !*exp := t;
      n := length u;
      v := for each j in groerevlist reval car u collect
                      if eqexpr j then !*eqn2a j else j;
      v := for each j in  gvarlis v collect !*a2k j;
      v := if n= 2 then
         intersection (v,groerevlist reval cadr u) else v;
      return 'list . v
   end;

put('gvars,'psopfn,'gvarseval);


symbolic procedure greduceeval pars;
%  Polynomial reduction modulo a Groebner basis driver. u is an
% expression and v a list of expressions.  Greduce calculates the
% polynomial u reduced wrt the list of expressions v reduced to a
% groebner basis modulo using the optional caddr argument as the
% order of variables.
%     1      expression to be reduced
%     2      polynomials or equations; base for reduction
%     3      optional: list of variables
  begin scalar vars,x,u,v,w,np,oldorder,!*factor,!*groebfac,!*exp;
       scalar !*gsugar;
       integer n,pcount!*; !*exp := t;
      if !*groebprot then groebprotfile := list 'list;
      n := length pars;
      x := reval car pars;
      u := reval cadr pars;
      v := if n>2 then reval caddr pars else nil;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,2,"Empty list in Greduce");
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then vdperr 'greduce;
      oldorder := vdpinit vars;
      groedomainmode();
                  % cancel common denominators
      w := for each j in w collect reorder numr simp j;
                  % optimize varable sequence if desired
      if !*groebopt then<< w:=vdpvordopt (w,vars); vars := cdr w;
                           w := car w; vdpinit vars>>;
      w := for each j in w collect f2vdp j;
      if !*groebprot then w := for each j in w collect vdpenumerate j;
      if not !*vdpinteger then
      <<np := t;
        for each p in w do
          np := if np then vdpcoeffcientsfromdomain!? p
                else nil;
        if not np then <<!*vdpmodular:= nil; !*vdpinteger := t>>;
      >>;

      w := groebner2(w,nil);
      x := a2vdp x;
      if !*groebprot then
          <<w := for each j in w collect vdpenumerate j;
            groebprotsetq('candidate,vdp2a x);
            for each j in w do groebprotsetq(mkid('poly,vdpnumber j),
                                             vdp2a j)>>;
      w := car w;
      !*vdpinteger := nil;
      w :=  groebnormalform(x , w, 'sort);
      w := vdp2a w;
      setkorder oldorder;
      gvarslast := 'list . vars;
      return if w then w else 0;
   end;


put('greduce,'psopfn,'greduceeval);

% preduceeval moved to groesolv.red

put('preduce,'psopfn,'preduceeval);

endmodule;


module glexconv;  % Newbase-Algorithm:
   % Faugere, Gianni, Lazard, Mora


fluid '(!*factor !*complex !*exp !*gcd !*ezgcd); % REDUCE switch
fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*fullreduction !*groebstat !*groebprot !*gltbasis
        !*groebsubs

        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        !*gsugar                   % sugar mode
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*              % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*            % current domain for base coeffs.
        vbcmodule!*            % for modular calculation: current prime
        glexdomain!*               % information wrt current domain
        !*gsugar
       );

global '(groebrestriction        % interface: name of function
         groebresmax            % maximum number of internal results
         gvarslast                 % output: variable list
         groebprotfile
         gltb
        );

flag ('(groebrestriction groebresmax gvarslast groebprotfile
        gltb),'share);

switch groebopt,groebfac,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,onlyheadtermreduction,groebprereduce,groebstat,
       gcheckpoint,gcdrart,gltbasis,groebsubs;

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);

% control of the polynomial arithmetic actually loaded
fluid '(currentvdpmodule!*);

fluid '(glexmat!*); % matrix for the indirect lex ordering

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    interface functions

% parameters;
%      glexconvert(basis,[vars],[maxdeg=n],[newvars={x,y,..}])

symbolic procedure glexconverteval u;
   begin integer n; scalar !*groebfac,!*groebrm,!*factor,!*gsugar,
          v, bas,vars,maxdeg,newvars,!*exp; !*exp := t;
      u := for each p in u collect reval p;
      bas := car u ; u := cdr u;
      while u do
       << v := car u; u := cdr u;
          if eqcar(v,'list) and null vars then vars := v
          else if eqcar(v,'equal) then
           if(v := cdr v)and eqcar(v,'maxdeg) then maxdeg := cadr v
             else if eqcar(v,'newvars) then newvars := cadr v
             else <<prin2 (car v);
                    rerror(groebnr2,4,"Glexconvert, keyword unknown")>>
            else rerror(groebnr2,5,
                       "Glexconvert, too many positional parameters")>>;
       return glexbase1(bas,vars,maxdeg,newvars);
      end;

put('glexconvert,'psopfn,'glexconverteval);

symbolic procedure glexbase1(u,v,maxdeg,nv);
   begin scalar vars,w,nd,oldorder,!*gcd,!*ezgcd,!*gsugar;
         integer pcount!*;
      !*gcd := t;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,6,"Empty list in Groebner");
      vars := groebnervars(w,v);
      !*vdpinteger := !*vdpmodular := nil;
      if not flagp(dmode!*,'field) then !*vdpinteger := t
           else
      if !*modular then !*vdpmodular := t;

      if null vars then vdperr 'groebner;
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect reorder numr simp j;
                  % optimize varable sequence if desired
      w := for each j in w collect f2vdp j;
      for each p in w do
          nd := nd or not vdpcoeffcientsfromdomain!? p;
      if nd then <<!*vdpmodular:= nil;
                    !*vdpinteger := t;
                    glexdomain!* := 2>>
          else  glexdomain!* := 1;
      if glexdomain!*=1 and not !*vdpmodular then !*ezgcd:=t;
      if null maxdeg then maxdeg := 200;
      if nv then nv := groerevlist nv;
      if null nv then nv := vars else
          for each x in nv do if not member(x,vars) then
           <<rerror(groebnr2,7,list("new variable ",x,
                           " is not a basis variable"))>>;
      u := for each v in nv collect a2vdp v;
      gbtest w;
      w := glexbase2(w,u,maxdeg);

      w := 'list . for each j in w collect prepf j;
      setkorder oldorder;
      gvarslast := 'list . vars;
      return w;
   end;

fluid '(glexeqsys!* glexvars!* glexcount!* glexsub!*);

symbolic procedure glexbase2(oldbase,vars,maxdeg);
   % in contrast to documented algorithm monbase ist a list of
   %  triplets  (mon.cof.vect)
   %   such that cof * mon == vect modulo oldbase
   %       (cof is needed because of the integer algoritm)
   begin scalar lexbase, staircase, monbase;
         scalar monom, listofnexts, vect,q,glexeqsys!*,glexvars!*,
                glexsub!*;
         integer n;
      if not groezerodim!?(oldbase,length vars) then
        prin2t "####### warning: ideal is not zerodimensional ######";
             % prepare matrix for the indirect lex ordering
      glexmat!* := for each u in vars collect vdpevlmon u;
      monbase := staircase := lexbase := nil;
      monom := a2vdp 1;
      listofnexts := nil;
      while not(monom = nil) do
      <<
        if not glexmultipletest(monom,staircase) then
        << vect := glexnormalform(monom,oldbase);
           q := glexlinrel(monom,vect,monbase);
           if q then
           <<lexbase := q . lexbase; maxdeg := nil;
             staircase := monom . staircase;
           >>
           else
           <<monbase := glexaddtomonbase(monom,vect,monbase);
             n := n #+1;
             if maxdeg and n#> maxdeg then
                  rerror(groebnr2,8,
                         "No univar. polynomial within degree bound");
             listofnexts :=
                 glexinsernexts(monom,listofnexts,vars)>>;
        >>;
        if null listofnexts then monom := nil
           else << monom := car listofnexts ;
                   listofnexts := cdr listofnexts >>;
      >>;
      return lexbase;
    end;

symbolic procedure glexinsernexts(monom,l,vars);
   begin scalar x;
     for each v in vars do
     << x := vdpprod(monom,v);
        if not vdpmember(x,l) then
        <<vdpputprop(x,'factor,monom); vdpputprop(x,'monfac,v);
          l := glexinsernexts1(x,l);
        >>;
     >>;
     return l;
   end;

symbolic procedure glexmultipletest(monom,staircase);
    if null staircase then nil
    else if vevmtest!?(vdpevlmon monom, vdpevlmon car staircase)
          then t
    else glexmultipletest(monom, cdr staircase);

symbolic procedure glexinsernexts1(m,l);
    if null l then list m
    else if glexcomp(vdpevlmon m,vdpevlmon car l) then m.l
    else car l . glexinsernexts1(m,cdr l);

symbolic procedure glexcomp(ev1,ev2);
  % true if ev1 is greater than ev2
  % we use an indirect ordering here (mapping via newbase variables)
     glexcomp0(glexcompmap(ev1,glexmat!*),
               glexcompmap(ev2,glexmat!*));

symbolic procedure glexcomp0(ev1,ev2);
     if null ev1 then nil
     else if null ev2 then glexcomp0(ev1,'(0))
     else if (car ev1 #- car ev2) = 0
                  then glexcomp0(cdr ev1,cdr ev2)
     else if car ev1 #< car ev2 then t
     else nil;

symbolic procedure glexcompmap (ev,ma);
      if null ma then nil
      else glexcompmap1(ev,car ma) . glexcompmap(ev,cdr ma);

symbolic procedure glexcompmap1(ev1,ev2);
   % the dot product of two vectors
      if null ev1 or null ev2 then 0
      else (car ev1 #* car ev2) #+ glexcompmap1(cdr ev1,cdr ev2);

symbolic procedure glexaddtomonbase(monom,vect,monbase);
  % primary effect: (monom . vect) . monbase
  % secondary effect: builds the equation system
   begin scalar x;
       if null glexeqsys!* then
        <<glexeqsys!* := a2vdp 0; glexcount!*:=-1>>;
       x := mkid('gunivar,glexcount!*:=glexcount!*+1);
       glexeqsys!* := vdpsum(glexeqsys!*,vdpprod(a2vdp x,cdr vect));
       glexsub!* := (x .(monom . vect)) . glexsub!*;
       glexvars!* := x . glexvars!*;
       return (monom . vect) . monbase;
   end;

symbolic procedure glexlinrelold(monom,vect,monbase);
    if monbase then
    begin scalar sys,sub,auxvars,r,v,x;
       integer n;
         v := cdr vect;
         for each b in reverse monbase do
         <<x := mkid('gunivar,n); n := n+1;
           v := vdpsum(v,vdpprod(a2vdp x,cddr b));
           sub := (x . b) . sub;
           auxvars := x . auxvars>>;
       while not vdpzero!? v do
       <<sys := vdp2f vdpfmon(vdplbc v,nil) . sys; v := vdpred v>>;
       x := sys;
       sys := groelinsolve(sys,auxvars);
       if null sys then return nil;
          % construct the lex polynomial
       if !*trgroeb
         then prin2t " ======= constructing new basis polynomial";
       r := vdp2f vdpprod(monom,car vect) ./ 1;
       for each s in sub do
         r:= addsq(r,multsq(vdp2f vdpprod(cadr s,caddr s) ./ 1,
                            cdr assoc(car s,sys)));
       r := vdp2f vdpsimpcont f2vdp numr r;
       return r;
    end;

symbolic procedure glexlinrel(monom,vect,monbase);
    if monbase then
    begin scalar sys,r,v,x;
       v := vdpsum(cdr vect,glexeqsys!*);
       while not vdpzero!? v do
       <<sys := vdp2f vdpfmon(vdplbc v,nil) . sys; v := vdpred v>>;
       x := sys;
       sys := groelinsolve(sys,glexvars!*);
       if null sys then return nil;
          % construct the lex polynomial
       r := vdp2f vdpprod(monom,car vect) ./ 1;
       for each s in glexsub!* do
         r:= addsq(r,multsq(vdp2f vdpprod(cadr s,caddr s) ./ 1,
                            cdr assoc(car s,sys)));
       r := vdp2f vdpsimpcont f2vdp numr r;
       return r;
    end;



symbolic procedure glexnormalform(m,g);
  % reduce m wrt basis G;
  % the reduction product is preserved in m for later usage
  begin scalar cof,vect,r,f,fac1;
      if !*trgroeb then prin2t " ======= reducing ";
      fac1 := vdpgetprop(m,'factor);
      if fac1 then vect := vdpgetprop(fac1,'vector);
      if vect then
      << f := vdpprod(cdr vect,vdpgetprop(m,'monfac));
         cof := car vect>>
      else
      << f := m; cof :=  a2vdp 1>>;
      r := glexnormalform1(f,g,cof);
      vdpputprop(m,'vector,r);
      if !*trgroeb then
      <<vdpprint vdpprod(car r,m); prin2t " =====> ";
        vdpprint cdr r>>;
      return r;
   end;


symbolic procedure glexnormalform1(f,g,cof);
  begin scalar f1,c,vev,divisor,done,fold,a,b;
        integer n;
      fold := f; f1 := vdpzero(); a:= a2vdp 1;
      while not vdpzero!? f do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;
            divisor := groebsearchinlist (vev,g);
            if divisor then done := t;
            if divisor then
                 if !*vdpinteger then
                  << f:=groebreduceonestepint(f,a,c,vev,divisor);
                     b := secondvalue!*;
                     cof := vdpprod(b,cof);
                     if not vdpzero!? f1 then
                          f1 := vdpprod(b,f1);
                  >>
                  else
                   f := groebreduceonesteprat(f,nil,c,vev,divisor)
             else
                  <<f1 := vdpappendmon (f1,vdplbc f,vdpevlmon f);
                    f := vdpred f;
                    >>;

          end;
      if not done then return cof . fold;
      f := groebsimpcont2(f1,cof); cof := secondvalue!*;
      return cof . f;
   end;


symbolic procedure groelinsolve(equations,xvars);
    (begin scalar r,q,test,oldmod,oldmodulus;
       if !*trgroeb then prin2t " ======= testing linear dependency ";
       r := t;
       if not !*modular and glexdomain!*=1 then
       <<oldmod := dmode!*;
         if oldmod then setdmode(get(oldmod,'dname),nil);
         oldmodulus := current!-modulus;
         setmod list 16381;  % = 2**14-3
         setdmode('modular,t);
         r := groelinsolve1(for each u in equations collect
                                numr simp prepf u, xvars);
         setdmode('modular,nil);
         setmod list oldmodulus;
         if oldmod then setdmode(get(oldmod,'dname),t);
       >> where !*ezgcd=nil;
       if null r then return nil;
       r := groelinsolve1(equations,xvars);
       if null r then return nil;
         % divide out the common content
       for each s in r do
         if not(denr cdr s = 1) then test := t;
       if test then return r;
       q := numr cdr car r;
   %   for each s in cdr r do
   %     if q neq 1 then
   %        q := gcdf!*(q,numr cdr s);
   %   if q=1 then return r;
   %   r := for each s in r collect
   %      car s . (quotf(numr cdr s, q) ./ 1);
       return r;
     end) where !*ezgcd=!*ezgcd;    % stack old value

symbolic procedure groelinsolve1(equations,xvars);
  % Gaussian elimination in integer mode
  %     free of unexact divisions (see Davenport et al,CA, pp86-87
  % special cases: trivial equations are ruled out early
  % INPUT:
  % equations:     list of standard forms
  % xvars:         variables for the solution
  % OUTPUT:
  % list of pairs (var . solu) where solu is a standard quotient
  %
  % internal data structure: standard forms as polynomials in xvars
   begin scalar oldorder,x,p,solutions,val,later,break,gc,field;
    oldorder := setkorder xvars;
    field := dmode!* and flagp(dmode!*,'field);
    equations := for each eqa in equations collect reorder eqa;
    for each eqa in equations do
         if eqa and domainp eqa then break:= t;
    if break then goto empty;
    equations := sort(equations,function grloelinord);

  again:
    break := nil;
    for each eqa in equations do if not break then
     % car step: eliminate equations of type 23 = 0
     %                                    and 17 * u = 0
     %                                    and 17 * u + 22 = 0;
     << if null eqa then equations := delete(eqa,equations)
       else if domainp eqa then break := t  % inconsistent system
       else if not member(mvar eqa,xvars) then break := t
       else if domainp red eqa or not member(mvar red eqa,xvars) then
       <<equations := delete (eqa,equations);
         x := mvar eqa;
         val := if lc eqa = 1 then negf red eqa ./ 1
                      else multsq(negf red eqa ./ 1, 1 ./lc eqa);
         solutions := (x . val) . solutions;
         equations := for each q in equations collect
                               groelinsub(q,list(x.val));
         later :=
              for each q in later collect groelinsub(q,list(x.val));
         break := 0;
        >>;
     >>;
     if break = 0 then goto again else if break then goto empty;

     % perform an elimination loop
     if null equations then goto ready;
     equations := sort(equations,function grloelinord);
     p := car equations; x := mvar p;
     equations := for each eqa in cdr equations collect
       if mvar eqa = x then
          << if field then
            eqa := addf(eqa, negf multf(quotf(lc eqa,lc p),p))
            else
            <<gc := gcdf(lc p,lc eqa);
              eqa := addf(multf(quotf(lc p,gc),eqa),
                        negf multf(quotf(lc eqa,gc),p))>>;
            if not domainp eqa then
                    eqa := numr multsq(eqa ./ 1, 1 ./ lc eqa);
            %%%%%%eqa := groelinscont(eqa,xvars);
            eqa>>
                  else eqa;
     later := p . later;
     goto again;


ready:   % do backsubstitutions
     while later do
     <<p := car later; later := cdr later;
       p := groelinsub(p,solutions);
       if domainp p or not member(mvar p,xvars) or
            (not domainp red p and member(mvar red p,xvars)) then
                               <<break := t; later := nil>>;
       x := mvar p;
       val := if lc p = 1 then negf red p ./ 1
             else quotsq(negf red p ./ 1 , lc p ./ 1);
       solutions := (x . val) . solutions;
     >>;
     if break then goto empty else goto finis;
 empty: solutions := nil;
 finis: setkorder oldorder;
     solutions := for each s in solutions collect
            car s . (reorder numr cdr s ./ reorder denr cdr s);
      return solutions;
  end;


symbolic procedure grloelinord(u,v);
    % apply ordop to the mainvars of u and v
         ordop(mvar u, mvar v);

symbolic procedure groelinscont(f,vars);
   % reduce content from standard form f
  if domainp f then f else
  begin scalar c;
    c := groelinscont1(lc f,red f,vars);
    if c=1 then return f;
    prin2 "*************content: ";print c;
    return quotf(f,c);
  end;

symbolic procedure groelinscont1(q,f,vars);
  % calculate the contents of standard form f
   if null f or q=1 then q
   else if domainp f or not member(mvar f,vars) then gcdf!*(q,f)
   else groelinscont1(gcdf!*(q,lc f),red f,vars);

symbolic procedure groelinsub(s,a);
  % s is a standard form linear in the top level variables
  % a is an assiciation list (variable . sq) . ...
  % The value is the standard form, where all substitutions
  % from a are done in s (common denominator ignored).
         numr groelinsub1(s,a);

symbolic procedure groelinsub1(s,a);
    if domainp s then s  ./ 1
    else (if x then addsq(multsq(cdr x,lc s ./ 1),y)
               else addsq(lt s .+ nil ./ 1,y))
         where x=assoc(mvar s,a),y=groelinsub1(red s,a);

endmodule;


module groebres;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  optimization of h-Polynomials by resultant calculation and
%  factorization
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(!*trgroeb );

% the resultant is calculated from a h-polynomial and its predecessor
% if both are bivariate in the same variables and if these variables
% are the last ones in vdpvars*.    

symbolic procedure groebtestresultant(h1,h2,lv);
     begin scalar v1,hlist;
         v1 := indexcpl(vevsum0(lv,h1),1);
         if groebrescheck!?(2,v1,lv)
            and indexcpl(vevsum0(lv,h2),1)=v1
            then hlist :=
                   reverse vdplsort
                    groebhlistfromresultant
                        (h1,h2,cadr reverse vdpvars!*)
          else
         if groebrescheck1!?(2,v1,lv)
            and indexcpl(vevsum0(lv,h2),1)=v1
            then hlist :=
                   reverse vdplsort
                    groebhlistfromresultant
                        (h1,h2,caddr reverse vdpvars!*);
         if null hlist then return nil;
         return 'resultant .
              for each x in hlist collect list(h2,vdpenumerate x);
     end;



symbolic procedure groebhlistfromresultant(h1,h0,x);
% new h-polynomial calculation: calculate
% the resultant of the two distributive polynomials h1 and h0
% with respect to x.
begin scalar ct00,hh,hh1,hs2;
   ct00:= time();
   hh:= vdpsimpcont groebresultant(h1,h0,x);
   if !*trgroeb  then <<terpri();
                     printb 57;
                     prin2t " *** the resultant from ";
                     vdpprint h1;
                     prin2t "         *** and";
                     vdpprint h0;
                     prin2t "                     *** is";
                     vdpprint hh;
                     printb 57;
                     terprit 4 >>;
   hs2:= nil;
   if not vdpzero!? hh then
       << hh1:= vdp2a vdprectoint(hh,vdplcm hh);
          hh1:= fctrf !*q2f simp hh1;
          if cdr hh1 and cddr hh1 then
               hs2:= for each p in cdr hh1 collect a2vdp prepf car p;
          if !*trgroeb and hs2 then
                    <<prin2 " factorization of resultant successful:";
                      terprit 2;
                      for each x in hs2 do vdpprint x;
                      terprit 2;
                      ct00:= time() - ct00;
                      prin2 " time for factorization:"; prin2 ct00;
                      terpri() >>;
           >>;
  return hs2
  end;


symbolic procedure groebresultant(p1,p2,x);
begin scalar q1,q2,q;
q1:=vdp2a vdprectoint(p1,vdplcm p1);
q2:=vdp2a vdprectoint(p2,vdplcm p2);
q:=a2vdp prepsq simpresultant list(q1,q2,x);
return q;
end;


symbolic procedure groebrescheck!?(a,h1,vl);
  length h1 = a and car h1 = vl - 1;


symbolic procedure groebrescheck1!?(a,h1,vl);
  length h1 = a and car h1 = vl - 2 and cadr h1 = vl - 1;

endmodule;


module groebmes;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  trace messages for the algorithms
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(vdpvars!* !*trgroeb !*trgroebs !*trgroeb1 !*trgroebr hcount!*
          hzerocount!* factorlevel!* basecount!* groetime!* pcount!*);

symbolic procedure groebpairprint (p);
  <<groebmessff(" pair(",cadr p,nil);
    groebmessff(",",caddr p,nil);
    prin2 "), ";
    prin2 " lcm = ";print car p;
  >>;

symbolic procedure groetimeprint;
   << prin2 ">> accum. cpu time:";
      prin2  (time() - groetime!*);
      prin2t " ms";
     >>;

symbolic procedure groebmessff (m1,f,m2);
      << prin2 m1; prin2 vdpnumber f;
         if !*gsugar then <<prin2 "/";prin2 gsugar f>>;
         if m2 then prin2t m2 >>;

symbolic procedure groebmess0 (p);
    if !*trgroeb then << vdpprint p; >>;


symbolic procedure groebmess1 (g,d);
        if !*trgroeb then <<
               prin2 " variables: "; print vdpvars!*;
               printbl();
               prin2t " Start of ITERATION "; terpri (); >>;

symbolic procedure groebmess2 f;
  if !*trgroeb then << terpri();
                 groebmessff ("polynomial ",f," eliminated");
                 groetimeprint()>>;

symbolic procedure groebmess2a(f,cf,fn);
  if !*trgroeb then << terpri();
        groebmessff ("polynomial ",f,nil);
        groebmessff (" elim. with cofactor ",cf," to");
        vdpprint fn; terpri();
        groetimeprint()>>;

symbolic procedure groebmess3(p,s);
     if !*trgroebs then <<
                       prin2 "S-polynomial from ";
                       groebpairprint p;
                       vdpprint s; terpri();
                            groetimeprint();
                            terprit 3 >>;

symbolic procedure groebmess4 (p,d);
    << hcount!* := hcount!*+1;
       hzerocount!* := hzerocount!*+1;
      if !*trgroeb then <<
                       terpri(); printbl();
                       groebmessff(" reduction (",cadr p,nil);
                       groebmessff(",", caddr p,nil);
                       prin2 ") leads to 0; ";
                       << prin2 n;
                          prin2 if n=1 then " pair" else " pairs">>
                            where n=length d;
                       prin2t " left";
                       printbl(); groetimeprint()>>;
     >>;

symbolic procedure groebmess41 (p);
    << hcount!* := hcount!*+1;
       hzerocount!* := hzerocount!*+1;
      if !*trgroeb then << terpri(); printbl();
                       groebmessff(" polynomial(", p,nil);
                       prin2 ") reduced to 0;";
                       terpri(); printbl(); groetimeprint()>>;
     >>;

symbolic procedure groebmess5(p,h);
   if car p then                  % print for true h-Polys
  << hcount!* := hcount!* + 1;
     if !*trgroeb then << terpri();
                       prin2  "H-polynomial ";
                       prin2 pcount!*;
                       prin2 " ev:"; prin2 vdpevlmon h;
                       groebmessff(" from pair (",cadr p,nil);
                       groebmessff(",", caddr p,")");
                       vdpprint h; terpri();
                       groetimeprint() >> >>
     else
     if !*trgroeb then <<          % print for input polys
                       prin2t "from actual problem input:";
                       vdpprint h;
                       groetimeprint() >>;

symbolic procedure groebmess50(g);
     if !*trgroeb1 then <<
                      prin2 "list of active polynomials:";
                      for each d1 in g do
                           <<prin2 vdpgetprop(d1,'number);
                             prin2 " ">>;
                            terprit 2 >>;

symbolic procedure groebmess51(d);
     if !*trgroeb1 then <<
                      prin2t "Candidates for pairs in this step:";
                      for each d1 in d do groebpairprint (d1);
                            terprit 2 >>;




symbolic procedure groebmess52(d);
     if !*trgroeb1 then <<
                       prin2t "Actual new pairs from this step:";
                       for each d1 in d do groebpairprint (d1);
                            terprit 2 >>;

symbolic procedure groebmess7 h;
   if !*trgroebs then
          <<prin2t "Testing factorization for "; vdpprint h>>;

symbolic procedure groebmess8 (g,d);
        if !*trgroeb1 then <<
            prin2t " actual pairs: ";
            if null d then prin2t "null"
                      else for each d1 in d do groebpairprint d1;
            groetimeprint() >>
          else if !*trgroeb then <<
              prin2 n; prin2t if n=1 then " pair" else " pairs" >>
                                          where n=length d;


symbolic procedure groebmess13(g,problems);
   if !*trgroeb or !*trgroebr then <<
      if g then
      <<
         basecount!* := basecount!* +1;
         printbl(); printbl();
         prin2  "end of iteration ";
         for each f in reverse factorlevel!* do
                      <<prin2 f; prin2 ".">>;
         prin2 "; basis "; prin2 basecount!*; prin2t ":";
         prin2 "{";
         for each g1 in g do vdpprin3t g1;
         prin2t "}";
         printbl(); printbl(); groetimeprint();
      >>
        else
      << printbl();
         prin2  "end of iteration branch ";
         for each f in reverse factorlevel!* do
                      <<prin2 f; prin2 ".">>;
         prin2t "  "; printbl(); groetimeprint();
      >>;
      if problems and !*trgroeb then
      <<
            groetimeprint(); terpri(); printbl();
            prin2 " number of partial problems still to be solved:";
            prin2t length problems;
            terpri();
            prin2 " preparing  next problem ";
            if car car problems = 'file then
                        prin2 cdr car problems
            else
            if cadddr car problems then
            vdpprint car cadddr car problems;  % head of list G
            terpri();
      >> >>;


symbolic procedure groebmess14 (h,hf);
   if !*trgroeb then <<
              prin2 "******************* factorization of polynomial ";
               (if x then prin2t x else terpri() )
                           where x = vdpnumber(h);
           %   vdpprint h;
               prin2t " factors:";
               for each g in hf do vdpprint car g;
               groetimeprint();
               >>;


symbolic procedure  groebmess15 f;
    if !*trgroeb then
          <<prin2t "***** monomial factor reduced:";
                   vdpprint vdpfmon(a2vbc 1,f)>>;


symbolic procedure groebmess19(p,restr,u);
    if !*trgroeb then <<
                printbl();
                prin2  "calculation branch ";
                for each f in reverse factorlevel!* do
                      <<prin2 f; prin2 ".">>;
                prin2t " cancelled because";
                vdpprint p;
                prin2t "is member of an actual abort condition";
                printbl(); printbl();
                     >>;

symbolic procedure groebmess19a(p,u);
    if !*trgroeb then <<
                printbl();
                prin2  "during branch preparation ";
                for each f in reverse u do
                      <<prin2 f; prin2 ".">>;
                prin2t " cancelled because";
                vdpprint p;
                prin2t "was found in the ideal branch";
                printbl();
                     >>;

symbolic procedure groebmess20 (p);
    if !*trgroeb then <<
               terpri();
               prin2 "secondary reduction starting with";
               vdpprint p>>;

symbolic procedure groebmess21(p1,p2);
    if !*trgroeb then <<
               prin2 "polynomial ";
               prin2 vdpnumber p1;
               prin2 " replaced during secondary reduction by ";
               vdpprint p2;
                     >>;


symbolic procedure groebmess22(factl,abort1,abort2);
   if null factl then nil
            else
    if !*trgroeb then
           begin integer n;
               prin2t "BRANCHING after factorization point";
               n := 0;
               for each x in reverse factl do
                << n := n+1;
                   prin2 "branch ";
                   for each f in reverse factorlevel!* do
                      <<prin2 f;prin2 ".";>>;
                   prin2t n;
                   for each y in car x do vdpprint y;
                  prin2t "simple IGNORE restrictions for this branch:";
                   for each y in abort1 do vdpprint y;
                   for each y in cadr x do vdpprint y;
                   if abort2 or caddr x then
                  <<prin2t
                      "set type IGNORE  restrictions for this branch:";
                     for each y in abort2 do vdpprintset y;
                     for each y in caddr x do vdpprintset y;
                   >>;
                   printbl()>>;
          end;

symbolic procedure  groebmess23 (g0,rest1,rest2);
    if !*trgroeb then
            if null factorlevel!* then
     prin2t "** starting calculation ******************************"
            else
              << prin2 "** resuming calculation for branch ";
                 for each f in reverse factorlevel!* do
                      <<prin2 f; prin2 ".">>;
                     terpri();
                     if rest1 or rest2 then
                       <<
               prin2t "-------IGNORE restrictions for this branch:";
                      for each x in rest1 do vdpprint x;
                      for each x in rest2 do vdpprintset x;
                       >>;
                      >>;


symbolic procedure groebmess24(h,problems1,restr);
 %  if !*trgroeb then
      <<prin2t
    "**********polynomial affected by NONNEGATIVE/POSITIVE condition:";
        vdpprint h;
        if restr then prin2t "under current restrictions";
        for each x in restr do vdpprint x;
        if null problems1 then prin2t "        CANCELLED"
           else
           <<prin2t "partitioned into";
             vdpprintset car problems1;
           >>;
      >>;

symbolic procedure groebmess25 (h,abort2);
%  if !*trgroeb then
    <<prin2t "reduction of set type cancel conditions by";
      vdpprint h;
      prin2t "remaining:";
      for each x in abort2 do vdpprintset x;
    >>;

symbolic procedure groebmess26 (f1,f2);
  if !*trgroebs and not vdpequal(f1,f2) then
    <<terpri();
      prin2t  "during final reduction";
      vdpprint f1;
      prin2t "reduced to";
      vdpprint f2;
      terpri();>>;

symbolic procedure groebmess27 r;
  if !*trgroeb then
    <<terpri();
      prin2t  "factor ignored (considered already):";
      vdpprint r>>;

symbolic procedure groebmess27a (h,r);
  if !*trgroeb then
    <<terpri();
      vdpprint h;
      prin2t  "     reduced to zero by factor";
      vdpprint r>>;


symbolic procedure groebmess28 r;
  if !*trgroeb then
    <<prin2 "interim content reduction:"; print r>>;

symbolic procedure terprit n;
% print blank lines.
   for i:=1:n do << terpri() >>;

symbolic procedure printbl(); printb (linelength nil #- 2);
symbolic procedure printb n; <<for i:=1:n do prin2 "-"; terpri()>>;


symbolic procedure vdpprintset l;
%  print polynomials in one line;
   if l then
     << prin2 "{"; vdpprin2 car l;
        for each x in cdr l do
        <<prin2 "; "; vdpprin2 x>>;
      prin2t "}";>>;

symbolic procedure vdpprin2l u;
     <<prin2 "("; vdpprin2 car u;
       for each x in cdr u do <<prin2 ","; vdpprin2 x;>>;
            prin2 ")";>>;

endmodule;


module groebrst;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% restrictions for polynomials during Groebner base calculation
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


fluid '(groebrestriction!*);


expr procedure groebtestrestriction (h,arg);
     if groebrestriction!* = 'nonnegative then groebnonneg(h,arg)
         else
     if groebrestriction!* = 'positive then groebpos(h,arg)
         else
           rerror(groebnr2,9,
                  "Groebner: general restrictions not yet implemented");

expr procedure groebnonneg(h,arg);
    % test if h is a polynomial which can have the value zero with
    % only nonnegative variable settings.
     begin scalar x,break,vev1,vevl,problems,problems1,r;
        if vdpzero!? h then return nil
            else
        if vevzero!? vdpevlmon h then goto finish;
                 % car test the coefficients
        if vdpredzero!? h then return nil;   % simple monomial
        break := nil;
        x := h;
        while not vdpzero!? x and not break do
           <<vev1 := vdpevlmon x;
             if not vbcplus!? vdplbc x then break := t;
             if not break then x := vdpred x>>;
        if break then return nil;     % at least one negative coeff
        if vevzero!? vev1 then goto finish; % nonneg. solution imposs.
                       % homogenous polynomial: find combinations of
                       % variables which are solutions
        x := h;
        vev1 := vdpevlmon x;
        vevl := vevsplit(vev1);
        problems := for each x in vevl collect list x;
        x := vdpred x;
        while not vdpzero!? x do
        << vev1 := vdpevlmon x;
           vevl := vevsplit(vev1);
           problems1 := nil;
           for each e in vevl do
             for each p in problems do
               <<r := if not member(e,p) then e . p else p;
                 problems1 := union(list r, problems1)>>;
           problems := problems1;
           x := vdpred x;
        >>;
        problems :=             % lift vevs to polynomials
          for each p in problems collect
             for each e in p collect
               vdpfmon(a2vbc 1,e);
                                % rule out problems contained in others
        for each x in problems do
            for each y in problems do
               if not eq(x,y) and subset!?(x,y) then
                   problems := delete (y,problems);

                                % rule out some by cdr
        problems1 := nil;
        while problems do
          <<if vdpdisjoint!? (car problems,arg)
               then problems1 := car problems . problems1;
            problems := cdr problems;
          >>;
  finish:
                    groebmess24(h,problems1,arg);
        return
         if null problems1 then 'cancel
            else 'restriction . problems1;
     end;

expr procedure groebpos(h,dummy);
    % test if h is a polynomial which can have the value zero with
    % only positive (nonnegative and nonzero) variable settings.
     begin scalar x,break,vev1;
        if vdpzero!? h then return nil
            else
        if vevzero!? vdpevlmon h then return nil;
                     % a simple monomial can never have pos. zeros
        if vdpredzero!? h then return groebposcancel(h);
        break := nil;
        x := h;
                     % test coefficients
        while not vdpzero!? x and not break do
           <<vev1 := vdpevlmon x;
             if not vbcplus!? vdplbc x then break := t;
             if not break then x := vdpred x>>;
        if not break then return groebposcancel(h);
        if not groebposvevaluate h then groebposcancel(h);
        return nil;
     end;

expr procedure groebposvevaluate h; t;
    % test if a polynomial can become zero under user restrictions
    % here a dummy to be rplaced elsewhere

expr procedure groebposcancel(h);
       << groebmess24(h,nil,nil); 'cancel>>;

endmodule;


module groebtra;

 % calculation of a Groebner base with the Buchberger algorithm
 % including the backtracking information which denotes the
 % dependency between base and input polynomials

%   Authors:   H. Melenk, H.M. Moeller,  W. Neun
%              November 1988

fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*onlyheadtermreduction !*groebstat !*groebdivide !*groebprot

        vdpvars!*                  % external names of the variables
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*             % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*           % current domain for base coeffs.
        groetags!*                 % starting point of tag variables
        groetime!*
       );

global '(gvarslast);

switch groebopt,groebfac,groebrm,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,onlyheadtermreduction,groebprereduce,groebstat,
       gcheckpoint,gcdrart,groebdivide,groebprot;

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Interface

symbolic procedure groebnertraeval u;
  % backtracking Groebner calculation
   begin integer n; scalar !*groebfac,!*groebrm,!*groebprot,!*gsugar;
      n := length u;
      if n=1 then return groebnertra1(reval car u,nil,nil)
       else if n neq 2
        then rerror(groebnr2,10,
                    "GROEBNERT called with wrong number of arguments")
       else return groebnertra1(reval car u,reval cadr u,nil)
      end;

put('groebnert,'psopfn,'groebnertraeval);

smacro procedure vdpnumber f;
     vdpgetprop(f,'number) ;

symbolic procedure groebnertra1(u,v,mod);
%    Buchberger algorithm system driver. u is a list of expressions
%    and v a list of variables or NIL in which case the variables in u
%    are used. 
   begin scalar vars,w,y,z,x,np,oldorder,groetags!*,tagvars;
         integer pcount!*,nmod;
      u := for each j in getrlist u collect
          <<if not eqcar(j,'equal)
              or not (idp (w:=cadr j) or (pairp w and
                          w = reval w and
                          get(car w,'simpfn)='simpiden))
              then rerror(groebnr2,11,
           "GROEBNERT parameter not {...,name = polynomial,...}")
            else cadr j . caddr j
          >>;
      if null u then rerror(groebnr2,12,"Empty list in Groebner")
       else if null cdr u then
            return 'list . list('equal,cdar u,caar u);;
      w := for each x in u collect cdr x;
      if mod then
      <<z := nil;
        for each vect in w do
         <<if not eqcar(vect,'list) then
              rerror(groebnr2,13,"Non list given to GROEBNER");
           if nmod=0 then nmod:= length cdr vect else
           if nmod<(x:=length cdr vect) then nmod=x;
           z := append(cdr vect,z);
         >>;
         if not eqcar(mod,'list) then
              rerror(groebnr2,14,"Illegal column weights specified");
         vars := groebnervars(z,v);
         tagvars := for i:=1:nmod collect mkid('! col,i);
         w := for each vect in w collect
         <<z:=tagvars; y := cdr mod;
           'plus . for each p in cdr vect collect
             'times . list('expt,car z,car y) .
                 <<z := cdr z; y := cdr y;
                   if null y then y := '(1); list p>>
         >>;
         groetags!* := length vars + 1;
         vars := append(vars,tagvars);
      >>
      else vars := groebnervars(w,v);
      groedomainmode();
      if null vars then vdperr 'groebner;
      oldorder := vdpinit vars;
                  % cancel common denominators
      u := pair(for each x in u collect car x,w);
      u := for each x in u collect
       <<z := simp cdr x;
         multsq(simp car x,denr z ./ 1) . reorder numr z>>;
      w := for each j in u collect cdr j;
                  % optimize varable sequence if desired
      if !*groebopt then<< w:=vdpvordopt (w,vars); vars := cdr w;
                           w := car w; vdpinit vars>>;
      w := pair (for each x in u collect car x,w);
      w := for each j in w collect
         <<z :=  f2vdp cdr j; vdpputprop(z,'cofact,car j)>>;
      if not !*vdpinteger then
      <<np := t;
        for each p in w do
          np := if np then vdpcoeffcientsfromdomain!? p else nil;
        if not np then <<!*vdpmodular:= nil; !*vdpinteger := t>>;
      >>;

      w := groebtra2 w;
      w := if mod then groebnermodres(w,nmod,tagvars) else
                       groebnertrares w;
      setkorder oldorder;
      gvarslast := 'list . vars;
      return w;
   end;

symbolic procedure groebnertrares w;
   begin scalar c,u;
    return
     'list . for each j in w collect
        <<c := prepsq vdpgetprop(j,'cofact);
          u := vdp2a j;
          if c=0 then u else list('equal,u,c)
        >>;
   end;


symbolic procedure groebnermodres(w,n,tagvars);
   begin scalar x,c,oldorder;
      c := for each u in w collect prepsq vdpgetprop(u,'cofact);
      oldorder := setkorder tagvars;
      w := for each u in w collect
       'list .
        <<u := numr simp vdp2a u;
          for i := 1:n collect
           prepf
            if not domainp u and mvar u = nth(tagvars,i)
             then <<x := lc u; u := red u; x>> else nil
        >>;
      setkorder oldorder;
         % reestablish term order for output
      w := for each u in w collect vdp2a a2vdp u;
      w := pair(w,c);
      return 'list .
        for each p in w collect
          if cdr p=0 then car p else
            list('equal,car p,cdr p);
    end;




symbolic procedure preduceteval pars;
%  trace version of PREDUCE
% parameters:
%     1      expression to be reduced
%            formula or equation
%     2      polynomials or equations; base for reduction
%            must be equations with atomic lhs
%     3      optional: list of variables
   begin scalar vars,x,y,u,v,w,z,oldorder,!*factor,!*exp,!*gsugar;
         integer n,pcount!*; !*exp := t;
      pars := groeparams(pars,2,3);
      y := car pars; u := cadr pars; v:= caddr pars;
      u := for each j in getrlist u
              collect
          <<if not eqcar(j,'equal) then
            j . j else  cadr j . caddr j>>;
      if null u then rerror(groebnr2,15,"Empty list in PREDUCET");
      w := for each p in u collect cdr p;  % the polynomials
      groedomainmode();
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  getrlist v;
      if not vars then vdperr 'preducet;
      oldorder := vdpinit vars;

      u := for each x in u collect
       <<z := simp cdr x;
         multsq(simp car x,denr z ./ 1) . reorder numr z>>;

      w := for each j in u collect
         <<z :=  f2vdp cdr j; vdpputprop(z,'cofact,car j)>>;

      if not eqcar(y,'equal) then y := list('equal,y,y);
      x := a2vdp caddr y;                % the expression
      vdpputprop(x,'cofact,simp cadr y); % the lhs (name etc.)
      w := tranormalform(x,w, 'sort,'f);
      u := list('equal,vdp2a w,prepsq vdpgetprop(w,'cofact));

      setkorder oldorder;
      return u;
   end;

put('preducet,'psopfn,'preduceteval);



symbolic procedure groebnermodeval u;
  % Groebner for moduli calculation
   (if n=0 or n>3 then
       rerror(groebnr2,16,
              "GROEBNERM called with wrong number of arguments")
    else
       groebnertra1(reval car u,
                    if n>=2 then reval cadr u else nil,
                    if n>=3 then reval caddr u else '(list 1))
    ) where n = length u;

put('groebnerm,'psopfn,'groebnermodeval);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% some macros for local usage only

smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);



symbolic procedure groebtra2 (p);
  % setup all global variables for the Buchberger algorithm
  % printing of statistics
 begin scalar groetime!*,tim1,spac,spac1,p1,factortime!*,
              pairsdone!*,factorlvevel!*;
       factortime!* := 0;
       groetime!* := time();
       vdponepol(); % we construct dynamically
       hcount!* := pcount!* := mcount!* := fcount!* :=
       bcount!* := b4count!* := hzerocount!* := basecount!* := 0;
       if !*trgroeb then
       <<
          prin2 "Groebner Calculation with Backtracking starts ";
          terprit 2;
       >>;
       spac := gctime();

       p1:=  groebtra3 (p);

       if !*trgroeb or !*trgroebr or !*groebstat then
       <<
          spac1 := gctime() - spac;
          terpri();
          prin2t "statistics for Groebner calculation";
          prin2t "===================================";
          prin2 " total computing time (including gc): ";
          prin2((tim1 := time()) - groetime!*);
          prin2t "          milliseconds  ";
          prin2 " (time spent for garbage collection:  ";
          prin2 spac1;
          prin2t "          milliseconds)";
          terprit 1;
          prin2  "H-polynomials total: "; prin2t hcount!*;
          prin2  "H-polynomials zero : "; prin2t hzerocount!*;
          prin2  "Crit M hits: "; prin2t mcount!*;
          prin2  "Crit F hits: "; prin2t fcount!*;
          prin2  "Crit B hits: "; prin2t bcount!*;
          prin2  "Crit B4 hits: "; prin2t b4count!*;
       >>;
       return p1;
 end;


symbolic procedure groebtra3 (g0);
   begin scalar x,g,d,d1,d2,p,p1,s,h,g99,one;
         x := for each fj in g0 collect vdpenumerate trasimpcont fj;
         for each fj in x do g := vdplsortin(fj,g0);
         g0 := g; g := nil;

% iteration :
      while (d or g0) and not one do
       begin
          if g0 then
          <<          % take next poly from input
               h := car g0; g0 := cdr g0;
               p := list(nil,h,h);
          >>
             else
          <<          % take next poly from pairs
               p := car d; d := cdr d;
               s := traspolynom (cadr p, caddr p); tramess3(p,s);
               h := groebnormalform(s,g99,'tree); %piloting wo cofact
               if vdpzero!? h then groebmess4(p,d)
               else h := trasimpcont tranormalform(s,g99,'tree,'h);
          >>;
          if vdpzero!? h then goto bott;
          if vevzero!? vdpevlmon h then % base 1 found
                  <<          tramess5(p,h);
                    g0 := d := nil; g:= list h;
                    goto bott>>;
          s:= nil;
                  % h polynomial is accepted now
               h := vdpenumerate h;
                        tramess5(p,h);
                              % construct new critical pairs
               d1 := nil;
               for each f in g do
                  if groebmoducrit(f,h) then
                    <<d1 := groebcplistsortin( list(tt(f,h),f,h) , d1);
                      if tt(f,h) = vdpevlmon(f) then
                                <<g := delete (f,g); groebmess2 f>>;
                      >>;
                  groebmess51(d1);
               d2 := nil;
               while d1 do
                  <<d1 := groebinvokecritf d1;
                    p1 := car d1;
                    d1 := cdr d1;
                    if groebbuchcrit4(cadr p1,caddr p1,car p1)
                       then d2 := append (d2, list p1);
                    d1 := groebinvokecritm (p1,d1);
                  >>;
                 d := groebinvokecritb (h,d);
                 d := groebcplistmerge(d,d2);
                 g := h . g;
                 g99 := groebstreeadd(h, g99);
                            groebmess8(g,d);
    bott:
   end;      %  ITERATION
   return groebtra3post g;
end;

symbolic procedure groebtra3post (g);
  % final reduction
   begin scalar r,p;
      g := vdplsort g;
      while g do
      <<p := tranormalform(car g,cdr g,'sort,'f);
        if not vdpzero!? p then r := trasimpcont p . r;
        g := cdr g>>;
      return reversip r;
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Reduction of polynomials
%

symbolic procedure tranormalform(f,g,type,mode);
     % general procedure for reduction of one polynomial from a set
     %  f is a polynomial, G is a Set of polynomials either in
     %     a search tree or in a sorted list
     % type describes the ordering of the set G:
     %    'TREE     G is a search tree
     %    'SORT     G is a sorted list
     %    'LIST     G is a list, but not sorted
     %  f has to be reduced modulo G
     % version for idealQuotient: doing side effect calculations for
     % the cofactors; only headterm reduction
  begin scalar c,vev,divisor,break;
      while not vdpzero!? f and not break do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;
            divisor :=
               if type = 'tree then groebsearchinstree (vev,g)
                               else groebsearchinlist (vev,g);
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
                      if !*vdpinteger  then
                          f := trareduceonestepint(f,nil,c,vev,divisor)
                       else
                          f := trareduceonesteprat(f,nil,c,vev,divisor)
               else
                  break := t;
          end;
      if mode = 'f then f := tranormalform1(f,g,type,mode);
      return f;
   end;

symbolic procedure tranormalform1(f,g,type,mode);
 % reduction of subsequent terms
  begin scalar c,vev,divisor,break,f1;
    f1 := f;
    while not vdpzero!? f and not vdpzero!? f1 do
    <<f1 := f; break := nil;
      while not vdpzero!? f1 and not break do
          <<vev:=vdpevlmon f1; c:=vdplbc f1;
            f1 := vdpred f1;
            divisor :=
               if type = 'tree then groebsearchinstree (vev,g)
                               else groebsearchinlist (vev,g);
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
            <<  if !*vdpinteger  then
                    f := trareduceonestepint(f,nil,c,vev,divisor)
                  else
                    f := trareduceonesteprat(f,nil,c,vev,divisor);
               break := t>>;
          >>;
      >>;
      return f;
   end;



% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special reduction procedures



symbolic procedure trareduceonestepint(f,dummy,c,vev,g1);
      % reduction step for integer case:
      % calculate f= a*f - b*g a,b such that leading term vanishes
      %                        (vev of lvbc g divides vev of lvbc f)
      %
      % and  calculate f1 = a*f1
      % return value=f, secondvalue=f1
 begin scalar vevlcm,a,b,cg,x,fcofa,gcofa;
      fcofa := vdpgetprop(f,'cofact);
      if null fcofa then fcofa := nil ./ 1;
      gcofa := vdpgetprop(g1,'cofact);
      if null gcofa then gcofa := nil ./ 1;
      vevlcm := vevdif(vev,vdpevlmon g1);
      cg := vdplbc g1;
            % calculate coefficient factors
      x := vbcgcd(c,cg);
      a := vbcquot(cg,x);
      b := vbcquot(c,x);
      f:= vdpilcomb1 (f, a, vevzero(),
                      g1,vbcneg b, vevlcm);
      x := vdpilcomb1tra (fcofa, a, vevzero(),
                       gcofa ,vbcneg b, vevlcm);
      vdpputprop(f,'cofact,x);
      return f;
 end;


symbolic procedure trareduceonesteprat(f,dummy,c,vev,g1);
      % reduction step for rational case:
      % calculate f= f - g/vdpLbc(f)
      %
 begin scalar x,fcofa,gcofa,vev;
      fcofa := vdpgetprop(f,'cofact);
      gcofa := vdpgetprop(g1,'cofact);
      vev := vevdif(vev,vdpevlmon g1);
      x := vbcneg vbcquot(c,vdplbc g1);
      f := vdpilcomb1(f,a2vbc 1,vevzero(),
                      g1,x,vev);
      x := vdpilcomb1tra (fcofa,a2vbc 1 , vevzero(),
                       gcofa,x,vev);
      vdpputprop(f,'cofact,x);
      return f;
 end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   calculation of an S-polynomial 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure traspolynom (p1,p2);
  begin scalar s,ep1,ep2,ep,rp1,rp2,db1,db2,x,cofac1,cofac2;
    if vdpzero!? p1  then return p1; if vdpzero!? p1  then return p2;
    cofac1 := vdpgetprop(p1,'cofact); cofac2 := vdpgetprop(p2,'cofact);
    ep1 := vdpevlmon p1;             ep2 := vdpevlmon p2;
    ep := vevlcm(ep1, ep2);
    rp1 := vdpred p1;               rp2 := vdpred p2;
    db1 := vdplbc p1;                db2 := vdplbc p2;
    if !*vdpinteger then
     <<x:=vbcgcd(db1,db2); db1:=vbcquot(db1,x); db2:=vbcquot(db2,x)>>;
    ep1 := vevdif(ep,ep1); ep2 := vevdif(ep,ep2); db2 := vbcneg db2;
    s := vdpilcomb1 (rp2,db1,ep2,rp1,db2,ep1);
    x := vdpilcomb1tra (cofac2,db1,ep2,cofac1,db2,ep1);
    vdpputprop(s,'cofact,x);
    return s;
   end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Normalisation with cofactors taken into account
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure trasimpcont(p);
    if !*vdpinteger then trasimpconti p else trasimpcontr p;

% routines for integer coefficient case:
% calculation of contents and dividing all coefficients by it

symbolic procedure trasimpconti (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar res,num,cofac;
    if vdpzero!?  p then return p;
    cofac := vdpgetprop(p,'cofact);
    num := car vdpcontenti p;
    if not vbcplus!? num then num := vbcneg num;
    if not vbcplus!? vdplbc p then num:=vbcneg num;
    if vbcone!? num then return p;
    res := vdpreduceconti (p,num,nil);
    cofac:=vdpreducecontitra(cofac,num,nil);
    res := vdpputprop(res,'cofact,cofac);
    return res;
    end;


% routines for rational coefficient case:
% calculation of contents and dividing all coefficients by it

symbolic procedure trasimpcontr (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar res,cofac;
    cofac := vdpgetprop(p,'cofact);
    if vdpzero!?  p then return p;
    if vbcone!? vdplbc p then return p;
    res := vdpreduceconti (p,vdplbc p,nil);
    cofac:=vdpreducecontitra(cofac,vdplbc p,nil);
    res := vdpputprop(res,'cofact,cofac);
    return res;
    end;

symbolic procedure vdpilcomb1tra (cofac1,db1,ep1,cofac2,db2,ep2);
 % the linear combination, here done for the cofactors 
 % (standard quotients)
    addsq(multsq(cofac1,vdp2f vdpfmon(db1,ep1) ./ 1),
          multsq(cofac2,vdp2f vdpfmon(db2,ep2) ./ 1));

symbolic procedure vdpreducecontitra(cofac,num,dummy);
 % divide the cofactor by a number
    quotsq(cofac,simp vbc2a num);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  special handling of moduli
%

symbolic procedure groebmoducrit(p1,p2);
    null groetags!*
      or pnth(vdpevlmon p1,groetags!*) = pnth(vdpevlmon p2,groetags!*);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  trace messages
%

symbolic procedure tramess0 x;
    if !*trgroeb then
    <<prin2t "adding member to intermediate quotient base:";
      vdpprint x;
      terpri()>>;

symbolic procedure tramess1 (x,p1,p2);
    if !*trgroeb then
    <<prin2 "pair ("; prin2 vdpnumber p1; prin2 ",";
      prin2 vdpnumber p2;
      prin2t ") adding member to intermediate quotient base:";
      vdpprint x;
      terpri()>>;


symbolic procedure tramess5(p,h);
   if car p then                  % print for true h-Polys
  << hcount!* := hcount!* + 1;
     if !*trgroeb then <<
                       terpri();
                       prin2  "H-polynomial ";
                       prin2 pcount!*;
                       groebmessff(" from pair (",cadr p,nil);
                       groebmessff(",", caddr p,")");
                       vdpprint h;
                       prin2t "with cofactor";
               writepri(mkquote prepsq vdpgetprop(h,'cofact),'only);
                       groetimeprint() >> >>
     else
     if !*trgroeb then <<          % print for input polys
                       prin2t "candidate from input:";
                       vdpprint h;
                       groetimeprint() >>;



symbolic procedure tramess3(p,s);
     if !*trgroebs then <<
                       prin2 "S-polynomial  ";
                       prin2 " from ";
                       groebpairprint p;
                       vdpprint s;
                       prin2t "with cofactor";
               writepri(mkquote prepsq  vdpgetprop(s,'cofact),'only);
                            groetimeprint();
                            terprit 3 >>;

endmodule;


module groeweak; % weak test for f ~ 0 modulo G


fluid '(!*groebweak current!-modulus pairsdone!* !*vdpinteger
         groebmodular!* !*groebfac);
switch groebweak;

symbolic procedure groebweakzerotest(f,g,type);
     % test f==0 modulo G with ON MODULAR
  begin scalar f1,c,vev,divisor,oldmode,a;
        integer n,oldprim;
      if vdpzero!? f then return f;
      if current!-modulus= 1 then setmod list 2097143;
      oldmode := setdmode('modular,t);
      f := groebvdp2mod f;
      f1 := vdpzero(); a:= vbcfi 1;
      while not vdpzero!? f and vdpzero!? f1 do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;
            if type = 'sort then
                 while  g
                       and vevcompless!? (vev,vdpevlmon (car g))
                            do g := cdr g;

            divisor :=
               if type = 'tree then groebsearchinstree(vev,g)
                               else groebsearchinlist (vev,g);

            if divisor and !*trgroebs then
                       << prin2 "//m-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
                      if vdplength divisor = 1 then
                            f := vdpcancelmvev(f,vdpevlmon divisor)
                          else
                           <<divisor := groebvdp2mod(divisor);
                            if divisor then f :=
                              groebreduceonesteprat(f,nil,c,vev,divisor)
                            else f1 := f>>
               else
                    f1 := f;
 %          ready:
          end;
      if not vdpzero!? f1 and !*trgroebs then
       <<prin2t " - nonzero result in modular reduction:";
         vdpprint f1;
       >>;
      setdmode('modular,nil);
      if oldmode then setdmode(get(oldmode,'dname),t);
      return vdpzero!? f1;
   end;


smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);


symbolic procedure groebweaktestbranch!=1(poly,g,d);
     % test GB(G) == {1} in modular style
       groebweakbasistest(list poly,g,d);

symbolic procedure groebweakbasistest(g0,g,d);
    begin scalar oldmode,d,d1,d2,p,p1,s,h;
      scalar !*vdpinteger;     % switch to field type calclulation
      return nil;
      if not !*groebfac then return nil;
      if current!-modulus= 1 then setmod list 2097143;
       if !*trgroeb then
          prin2t "---------------- modular test of branch ------";

      oldmode := setdmode('modular,t);
      g0 := for each p in g0 collect groebvdp2mod p;
      g := for each p in g collect groebvdp2mod p;
      d := for each p in d collect list (car p,
             groebvdp2mod cadr p, groebvdp2mod caddr p);

      while d or g0 do
       begin
          if g0 then
          <<          % take next poly from input
               h := car g0; g0 := cdr g0; p := list(nil,h,h);
          >>
             else
          <<          % take next poly from pairs
               p := car d;
               d := delete (p,d);
               s := groebspolynom (cadr p, caddr p);
               h:=groebsimpcontnormalform groebnormalform(s,g,'sort);
                  if vdpzero!? h then !*trgroeb and groebmess4(p,d);
          >>;

          if vdpzero!? h then
              <<pairsdone!* := (vdpnumber cadr p . vdpnumber caddr p)
                              . pairsdone!*;
                goto bott>>;

          if vevzero!? vdpevlmon h then % base 1 found
                  <<         !*trgroeb and groebmess5(p,h);
                   goto stop>>;

          s:= nil;

          h := vdpenumerate h; !*trgroeb and groebmess5(p,h);

                              % construct new critical pairs
          d1 := nil;

          for each f in g do
                    <<d1 := groebcplistsortin(list(tt(f,h),f,h),d1);
                      if tt(f,h) = vdpevlmon(f) then
                              <<g := delete (f,g);
                                !*trgroeb and groebmess2 f>>;
                      >>;
                  !*trgroeb and groebmess51(d1);
          d2 := nil;
          while d1 do
                  <<d1 := groebinvokecritf d1;
                    p1 := car d1; d1 := cdr d1;
                    d2 := groebinvokecritbuch4 (p1,d2);
                    d1 := groebinvokecritm (p1,d1);
                  >>;

          d := groebinvokecritb (h,d);
          d := groebcplistmerge(d,d2);

          g := h . g;
          goto bott;

    stop:        d := g := g0 := nil;

    bott:
       end;
          if !*trgroeb and null g then
          prin2t "**** modular test detects empty branch!";
          if !*trgroeb then
          prin2t "------ end of  modular test of branch ------";
       setdmode('modular,nil);
       if oldmode then setdmode(get(oldmode,'dname),t);
       return  null g;
    end;

fluid '(!*localtest);

symbolic procedure groebfasttest(g0,g,d,g99);
     if !*localtest then
       <<!*localtest := nil;
         groebweakbasistest(g0,g,d)>>
     else if !*groebweak and g and vdpunivariate!? car g
            then groebweakbasistest(g0,g,d);

symbolic procedure groebvdp2mod f;
   %convert a vdp in modular form
   % in case of headterm loss, nil is returned
     begin scalar u,c,mf,s;
        u := vdpgetprop(f,'modimage);
        if u then return if u='nasty then nil else u;
        mf := vdpresimp f;
        if !*gsugar then vdpputprop(mf,'sugar,vdpgetprop(f,'sugar));
        c := errorset!*(list('vbcinv,mkquote vdplbc mf),nil);
        if not pairp c then
        <<prin2t "************** nasty module (loss of headterm) ****";
          print f; print u; vdpprint f; vdpprint u;
          vdpputprop(f,'modimage,'nasty);
          return nil>>;
        u := vdpvbcprod(mf,car c);
        vdpputprop(u,'number,vdpgetprop(f,'number));
        vdpputprop(f,'modimage,u);
        if !*gsugar then vdpputprop(u,'sugar,vdpgetprop(f,'sugar));
        return u;
     end;


symbolic procedure groebmodeval(f,break);
     % evaluate LISP form r with REDUCE modular domain
  begin scalar oldmode,a,!*vdpinteger,groebmodular!*;
      groebmodular!* := t;
      if current!-modulus= 1 then setmod list 2097143;
      oldmode := setdmode('modular,t);
      a := errorset!*(f,t);
      setdmode('modular,nil);
      if oldmode then setdmode(get(oldmode,'dname),t);
      return if atom a then nil else car a;
   end;

endmodule;


module hilberts; % Hilbert series of a set of Monomials.

% Author: Joachim Hollman, Royal Institute for Technology,
%                          Stockholm, Sweden
%                          email:  <joachim@nada.kth.se>

Comment
--------------------------------------------------------

A very brief "description" of the method used.


M=k[x,y,z]/(x^2*y,x*z^2,y^2)
 
                    x.
0 --> ker(x.) --> M --> M --> M/x --> 0
 
M/x = k[x,y,z]/(x^2*y,x*z^2,y^2,x) = k[x,y,z]/(x,y^2)
 
ker(x.) = ((x) + (x^2*y,x*z^2,y^2))/(x^2*y,x*z^2,y^2) =
 
        = (x,y^2)/(x^2*y,x*z^2,y^2)
 
 
Hilb(ker(x.)) = Hilb        - Hilb
                    (x,y^2)       (x^2*y,x*z^2,y^2)
 
        = 1/(1-t)^3 - Hilb                -
                          k[x,y,z]/(x,y^2)
 
          - (1/(1-t)^3 - Hilb
                          k[x,y,z]/(x^2*y,x*z^2,y^2)
 
        = Hilb -Hilb
              M     k[x,y,z]/(x,y^2)
 
If you only keep the numerator in Hilb = N(t)/(1-t)^3
                                      M
 
 
then you get
 
 
(1-t)N (t) = N (t)  - t (N (t) - N (t)      )
      I       I+(x)       I       Ann(x) + I
 
i.e.
 
 N (t) = N (t)  + t N (t)               (*)
  I       I+(x)      Ann(x) + I
 
 
Where
      I          = (x^2*y,x*z^2,y^2)
      I + (x)    = (x,y^2)
      I + Ann(x) = (x*y,z^2,y^2)
      N (t) is the numerator polynomial in Hilb
       I                                       k[x,y,z]/I
 
 
Equation (*) is what we use to compute the numerator polynomial, i.e.
we "divide out" one variable at a time until we reach a base case.
(One is not limited to single variables but I don't know of any good
strategy for selecting a monomial.)



Usage: hilb({monomial_1,...,monomial_n} [,variable])

;

fluid '(nvars!*);

% ************** MACROS ETC. **************

smacro procedure term(c,v,e);
    list('times,c,list('expt,v,e));

% -------------- safety check --------------

smacro procedure var!-p(m);
    and(m,atom(m),not(numberp(m)));

smacro procedure check!-expt(m);
    and(eqcar(m,'expt),var!-p(cadr(m)),numberp(caddr(m)));

smacro procedure check!-single!-var(m);
    if var!-p(m) then t
    else check!-expt(m);

smacro procedure check!-mon(m);
    if check!-single!-var(m) then t
    else if eqcar(m,'times) then check!-times(cdr(m))
    else nil;

smacro procedure check!-args(monl,var);
    and(listp monl,eqcar(monl,'list),var!-p(var), check!-monl(monl));

symbolic procedure make!-vector (n,pat);
    begin scalar v;
    v:=mkvect n;
    for i:=1:n do putv(v,i,pat);
    return v;
    end;

% -------------- monomials --------------

smacro procedure alloc!-mon(n);
    make!-vector(n,0);

smacro procedure get!-nth!-exp(mon,n);
    getv(mon,n);

smacro procedure set!-nth!-exp(mon,n,d);
    putv(mon,n,d);

smacro procedure get!-tdeg(mon);
    getv(mon,0);

smacro procedure set!-tdeg(mon,d);
    putv(mon,0,d);

% -------------- ideals --------------

smacro procedure the!-empty!-ideal();
    list(nil,nil);

smacro procedure get!-next!-mon(ideal);
    <<x:=caadr ideal;
      if cdadr ideal then ideal:=list(car ideal,cdadr ideal)
      else ideal:=the!-empty!-ideal();
      x>>;

smacro procedure not!-empty!-ideal(ideal);
    cadr ideal;

smacro procedure first!-mon(ideal);
    caadr ideal;

smacro procedure append!-ideals(ideal1,ideal2);
    list(car ideal2,append(cadr ideal1,cadr ideal2));

symbolic procedure insert!-var(var,ideal);
% inserts variable var as last generator of ideal
begin
    scalar last;
    last:=list(make!-one!-var!-mon(var));
    return(list(last,append(cadr ideal,last)));
end;

symbolic procedure add!-to!-ideal(mon,ideal);
% add mon as generator to the ideal
begin
    scalar last;
    last := list(mon);
    if ideal = the!-empty!-ideal() then
        rplaca(cdr(ideal),last)
    else
        rplacd(car(ideal),last);
    rplaca(ideal,last);
end;

% ************** END OF MACROS ETC. **************

% ************** INTERFACE TO ALGEBRAIC MODE **************

symbolic procedure hilbsereval(u);
begin
    scalar l,monl,var;
    l:=length(u);
    if l < 1 or l > 2 then
        rerror(groebnr2,17,
               "Usage: hilb({monomial_1,...,monomial_n} [,variable])")
    else if l = 1 then
    <<
        monl:= reval car u;
        var:= 'x;
    >>
    else
    <<
        monl:=  reval car u;
        var:= reval cadr u;
    >>;
    monl :=  'list . for each aa in (cdr monl) collect reval aa;
    if not check!-args(monl,var) then
         rerror(groebnr2,18,
                "Usage: hilb({monomial_1,...,monomial_n} [,variable])");
%    return(aeval 
%               list('QUOTIENT,
%                   coefflist2prefix(NPol(gltb2arrideal(monl)), var),
%                   list('EXPT,list('PLUS,1,list('TIMES,-1,var)),
%                        nvars!*)));
    return(aeval
                    coefflist2prefix(npol(gltb2arrideal(monl)), var));
end;

% define "hilb" to be the algebraic mode function
put('hilb,'psopfn,'hilbsereval);

symbolic procedure check!-monl(monl);
begin
    scalar flag,tmp;
    flag:=t;
    monl:=gltb!-fix(monl);
    while monl and flag do
    <<
        tmp:=car monl;
        flag:=check!-mon(tmp);
        monl:=cdr monl;
    >>;
    return(flag);
end;

symbolic procedure check!-times(m);
begin
    scalar flag,tmp;
    flag:=t;
    while m and flag do
    <<
        tmp:= car m;
        flag:=check!-single!-var(tmp);
        m:=cdr m;
    >>;
    return(flag);
end;

symbolic procedure coefflist2prefix(cl,var);
begin
    scalar i,poly;
    i:=0;
    for each c in cl do
    <<
        poly:= cons(term(c,var,i),poly);
        i:=i+1;
    >>;
    return (cons('plus,poly));
end;

symbolic procedure indets(l);
% "indets"  returns a list containing all the 
% indeterminates of l.
% l is supposed to have a form similar to the variable
% GLTB in the Groebner basis package.
% (LIST (EXPT Z 2) (EXPT X 2) Y)
begin
    scalar varlist;
    for each m in l do
        if m neq 'list then
            if atom(m) then varlist:=union(list(m),varlist)
            else if eqcar(m,'expt)
             then varlist:=union(list(cadr(m)),varlist)
            else varlist:=union(indets(cdr(m)),varlist);
    return(varlist);
end;    

symbolic procedure build!-assoc(l);
% Given a list of indeterminates (x1 x2 ...xn) we produce 
% an a-list of the form ((x1.1) (x2.2)... (xn.n))
begin
    scalar i;
    i:=0;
    return(for each var in l collect progn(i:=i+1,cons(var,i)));
end;            

symbolic procedure mons(l);
% rewrite the leading monomials (i.e. GLTB).
% the result is a list of monomials of the form: 
% (variable . exponent) or ((variable1 . exponent1) ...
%     (variablen . exponentn))
%
% mons('(LIST (EXPT Z 2) (EXPT X 2) (TIMES Y (EXPT X 3))));
% (((Y . 1) (X . 3)) (X . 2) (Z . 2))
begin
    scalar monlist;
    for each m in l do
        if m neq 'list then monlist:=
            if atom(m) then cons(cons(m,1),monlist)
            else if eqcar(m,'expt)
             then cons(cons(cadr(m),caddr(m)),monlist)
            else (for each x in cdr(m) collect mons!-aux(x)) . monlist;

    return(monlist);
end;    

symbolic procedure mons!-aux(m);
if atom(m) then cons(m,1)
else if eqcar(m,'expt) then cons(cadr(m),caddr(m));

symbolic procedure lmon2arrmon(m);
% list-monomial to array-monomial
% a list-monomial has the form: (variable_number . exponent)
% or is a list with entries of this form.
% "variable_number" is the number associated with the variable,
% see build!-assoc()
begin
    scalar tdeg,mon;
    mon:=alloc!-mon(nvars!*);
    tdeg:=0;
    if listp m then
        for each varnodotexp in m do
        <<
            set!-nth!-exp(mon,car varnodotexp, cdr varnodotexp);
            tdeg:=tdeg+cdr varnodotexp;
        >>
    else
    <<
        set!-nth!-exp(mon,car m, cdr m);
        tdeg:=tdeg+cdr m;
    >>;
    set!-tdeg(mon,tdeg);
    return(mon);
end;

symbolic procedure gltb!-fix(l);
% sometimes GLTB has the form (list (list...))
% instead of (list ...)
if and(listp cadr l,caadr(l) = 'list) then cadr l else l;
        
symbolic procedure ge(m1,m2);
if get!-tdeg(m1) >= get!-tdeg(m2) then t else nil;

symbolic procedure get!-end!-ptr(l);
begin
    scalar ptr;
    while l do
    <<
        ptr:=l;
        l:=cdr l;
    >>;
    return(ptr);
end;

symbolic procedure gltb2arrideal(xgltb);
% Convert the monomial ideal given by GLTB (in list form)
% to a list of vectors where each vector represents a monomial.
begin
    scalar l;
    l:=indets(gltb!-fix(xgltb));
    nvars!* := length(l);
    l:= sublis(build!-assoc(l),mons(gltb!-fix(xgltb)));
    l:=for each m in l collect lmon2arrmon(m);
    l:=sort(l,'ge);
    return(list(get!-end!-ptr(l),l));
end;

        
% ************** END OF INTERFACE TO ALGEBRAIC MODE **************



%************** PROCEDURES **************

symbolic procedure npol(ideal);
% recursively computes the numerator of the Hilbert series
begin
    scalar v,si;
    v:=next!-var(ideal);
    if not v then return(base!-case!-pol(ideal));
    si:=split!-ideal(ideal,v);
    return(shift!-add(npol(car si),npol(cadr si)));
end;

symbolic procedure divides!-by!-var(var,mon);
begin
    scalar div;
    if get!-nth!-exp(mon,var) = 0 then return(nil);
    div:=alloc!-mon(nvars!*);
    for i:=1 : nvars!* do set!-nth!-exp(div,i,get!-nth!-exp(mon,i));
    set!-nth!-exp(div,var,get!-nth!-exp(mon,var)-1);
    set!-tdeg(div,get!-tdeg(mon)-1);
    return(div);
end;

symbolic procedure divides(m1,m2);
% does m1 divide m2?
% m1 and m2 are monomials
% result: either nil (when m1 does not divide m2) or m2/m1
begin
    scalar m,d,i;
    i:=1;
    m:=alloc!-mon(nvars!*);
    set!-tdeg(m,d:=get!-tdeg(m2)-get!-tdeg(m1));
    while d >= 0 and i <= nvars!* do
    <<
        set!-nth!-exp(m,i,d:=get!-nth!-exp(m2,i) - get!-nth!-exp(m1,i));
        i:= i+1;
    >>;

    if d < 0 then
        return (nil)
    else
        return(m);
end;

symbolic procedure shift!-add(p1,p2);
% p1+z*p2
% p1 and p2 are polynomials (nonempty coefficient lists)
begin
    scalar p,pptr;
    pptr:=p:=cons(car p1,nil);
    p1:=cdr p1;
    while p1 and p2 do
    <<
        rplacd(pptr,cons(car p1 + car p2,nil));
        p1:=cdr p1;
        p2:=cdr p2;
        pptr:=cdr pptr;
    >>;
    if p1 then
        rplacd(pptr,p1)
    else
        rplacd(pptr,p2);
    return(p);
end;

symbolic procedure rem!-mult(ipp1,ipp2);
% the union of two ideals with redundancy of generators eliminated
begin
    scalar fmon,inew,isearch,primeflag,x;
       % fix; x is used in the macro...
    inew := the!-empty!-ideal();
    while not!-empty!-ideal(ipp1) and not!-empty!-ideal(ipp2) do
    begin
        if get!-tdeg(first!-mon(ipp2)) < get!-tdeg(first!-mon (ipp1))
          then <<
            fmon:=get!-next!-mon(ipp1);
            isearch:=ipp2;
        >>
        else
        <<
            fmon:=get!-next!-mon(ipp2);
            isearch:=ipp1;
        >>;
        primeflag:=t;
        while primeflag and not!-empty!-ideal(isearch) do
           if divides(get!-next!-mon(isearch),fmon) then primeflag:=nil;
        if primeflag then add!-to!-ideal(fmon,inew);
    end;
    if not!-empty!-ideal(ipp1) then return(append!-ideals(inew,ipp1))
    else return(append!-ideals(inew,ipp2));
end;

symbolic procedure next!-var(ideal);
% extracts a variable in the ideal suitable for division
begin
    scalar x,m,var;
    repeat
    <<  m:=get!-next!-mon(ideal);
        var:=get!-var!-if!-not!-single(m);
    >> until var or ideal = the!-empty!-ideal();
    return(var);
end;

symbolic procedure get!-var!-if!-not!-single(mon);
% returns nil if the monomial is in a single variable, 
% otherwise the index of the second variable of the monomial
begin
    scalar i,foundvarflag,exp;
    i := 0;
    foundvarflag:=nil;
    while not foundvarflag do
    <<
        i:=i+1;
        exp:=get!-nth!-exp(mon,i);
        if exp > 0 then foundvarflag:=t;
    >>;
    foundvarflag:=nil;
    while i < nvars!* and not foundvarflag do
    <<
        i:=i+1;
        exp:=get!-nth!-exp(mon,i);
        if exp > 0 then foundvarflag:=t;
    >>;
    if foundvarflag then return(i)
    else return(nil);
end;

symbolic procedure make!-one!-var!-mon(vindex);
% returns the monomial consisting of the single variable vindex
begin
    scalar mon;
    mon := alloc!-mon(nvars!*);
    for i := 1:nvars!* do set!-nth!-exp(mon,i,0);
    set!-nth!-exp(mon,vindex,1);
    set!-tdeg(mon,1);
    return(mon);
end;

symbolic procedure split!-ideal(ideal,var);
% splits the ideal into two simpler ideals
begin
    scalar div,ideal1,ideal2,m,x;
    ideal1 := the!-empty!-ideal();
    ideal2 := the!-empty!-ideal();
    while not!-empty!-ideal(ideal) do
    <<
        m:=get!-next!-mon(ideal);
        if div:=divides!-by!-var(var,m) then
            add!-to!-ideal(div,ideal2)
        else
            add!-to!-ideal(m,ideal1);
    >>;
    ideal2:=rem!-mult(ideal1,ideal2);
    ideal1:=insert!-var(var,ideal1);
    return(list(ideal1,ideal2));
end;

symbolic procedure base!-case!-pol(ideal);
% in the base case every monomial is of the form Xi^ei
% result : the numerator polynomial of the Hilbert series
%          i.e. (1-z^e1)*(1-z^e2)*...
begin
    scalar p,degsofar,e,tdeg;
    tdeg:=0;
    for each mon in cadr ideal do tdeg:=tdeg + get!-tdeg(mon);
    p:=make!-vector(tdeg,0);
    putv(p,0,1);
    degsofar:=0;

    for each mon in cadr ideal do
    <<
        e:=get!-tdeg(mon);
        for j:= degsofar step -1 until 0 do
            putv(p,j+e,getv(p,j+e)-getv(p,j));
        degsofar:=degsofar+e;
    >>;
    return(vector2list(p));
end;

symbolic procedure vector2list v;
   % Convert a vector v to a list.  No type checking is done.
   begin scalar u;
      for i:= upbv v step -1 until 0 do u := getv(v,i) . u;
      return u;
   end;

endmodule;


module hilbertp; % Computing Hilbert Polynomial from the Hilbert series.

Comment
Authors: H. Michael Moeller, Fernuniversitaet 
                    Hagen, Germany
                    email: MA105@DHAFEU11.bitnet

         H. Melenk, Konrad-Zuse-Zentrum
                    Berlin, Germany
                    email: melenk@sc.ZIB-Berlin.de
;

symbolic procedure newhilbi (bas,var,vars);
 begin scalar baslt,n,u,grad,h,joa,a,ii,dim0,varx,dmode!*,!*modular;

 % extract leading terms

 baslt:= for each p in cdr bas  collect
           <<u := hgspliteval list (p,vars); cadr u>>;

 % replace non atomic elements in the varlist by gensyms

 for  each x in cdr vars do
        if (pairp x) then
          baslt := cdr subeval list(list('equal,x,gensym()),
                                    'list . baslt);

 % compute the Hilbertseries

 joa := hilbsereval list ('list . baslt,var);

 % get the Hilbert polynomial

 grad := deg(joa,var);
 a:= for i:=0:grad collect coeffn (joa,var,i);
 n:= length cdr vars;

 %dim0 := (for i:=1:n product (var + i))/( for i:=1:n product i);

 varx := !*a2f var;
 dim0 := 1;
 for i:=1:n do dim0:= multf (addd(i,varx),dim0);
 dim0 := multsq(dim0 ./ 1,1 ./ (for i:=1:n product i));

 h := multsq(car(a) ./ 1,dim0);
 a := cdr(a);
 ii := 0;

 while a do
  << dim0 := multsq (dim0, addf(varx,numr simp (minus ii) )
                        ./ addf(varx,numr simp (n -ii)));
     ii := ii + 1;
     if not (car a = 0) then h := addsq (h , multsq(car(a) ./ 1 ,dim0));
     a := cdr(a) >>;
 return mk!*sq h;
 end;

symbolic procedure psnewhilbi (u);
   begin scalar zz;
   zz := 'list . gvarlis groerevlist reval car u;
   if length (u) = 2
     then return newhilbi ( reval car u, 'x, reval cadr u )
    else if length (u) = 1 then return newhilbi(reval car u,'x,zz)
    else rerror(groebnr2,19,"Wrong call to hilbertpolynomial");
   end;

put ('hilbertpolynomial , 'psopfn ,'psnewhilbi);

symbolic procedure hgspliteval pars;
   % A variant of Gsplit from grinterf.red.
   % Split a polynomial into leading monomial and reductum.
   begin scalar vars,x,u,v,w,oldorder,!*factor,!*exp;
         integer n,pcount!*; !*exp := t;
      n := length pars;
      u := reval car pars;
      v := if n>1 then reval cadr pars else nil;
      u := list('list,u);
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then  vdperr 'gsplit;
      oldorder := vdpinit vars;
      w := a2vdp car w;
      if vdpzero!? w then x := w else
%     <<x := vdpfmon(vdplbc w,vdpevlmon w);
      <<x := vdpfmon('( 1 . 1),vdpevlmon w);
        w := vdpred w>>;
      w := list('list,vdp2a x,vdp2a w);
      setkorder oldorder;
      return w;
   end;


% simple Array access method for one- and two-dimensional arrays
% NO check against misusage is done!

% Usage:   Rar:=makeRarray list dim1;  Rar:=makeRarray list(dim1,dim2);
%          val:=getRarray(Rar,ind1);   val:=getrarray(Rar,ind1,ind2);
%          putRarray(Rar,ind1,val);    PutRarray(Rar,in1,ind2,val);

% for two dimensional array access only !

macro procedure functionindex2(u);
  begin scalar dims,ind1,ind2;
    dims := cadr u;
    ind1 := caddr u;
    ind2 := cadddr u;
    return         %%%% ((ind1 #- 1) #* cadr dims) #+ ind2;
      list ('iplus,ind2,list('itimes,list('cadr,dims),
                             list('iplus,ind1,-1)));
  end;

macro procedure getrarray u;
   begin scalar arry,inds;
     arry := cadr(u);
     inds := cddr u;
     if length(inds) = 1 then
               return  list('getv,list('cdr,arry),car inds)
     else
               return list('getv,list('cdr,arry),
                    'functionindex2 . list('car,arry) . inds);
   end;

symbolic procedure makerarray dims;
   begin scalar u,n;
      n := for each i in dims product i;
      u := mkvect n;
      return dims . u;
   end;

macro procedure putrarray u;
   begin scalar arry,inds, val;
     arry := cadr(u);
     inds := cddr u;
     val := nth (u,length u);      % PSL: lastcar u;
     if length(inds) = 2 then
           return  list('putv,list('cdr,arry),car inds,val)
     else
           return  list('putv,list('cdr,arry), 'functionindex2 .
               list('car,arry).car inds. cadr inds . nil , val);
   end;

procedure hilbertzerodimp(nrall, n, rarray);
begin integer i, k, count, vicount;
  count := 0;
  i := 0;
  while ((i:= i+1) <= nrall and count < n) do
  begin vicount := 1;
     for k := 1:n do
       if (getrarray(rarray,i,k) = 0) then vicount := vicount + 1;
     if vicount = n  then count := count + 1;
  end;
  return count = n;
end;

symbolic procedure groezerodim!?(f,n);
  begin scalar explist,a;
        integer r;
           %explist:= list( vev(lt(f1)),...,vev(lt(fr)) );
    explist:= for each fi in f collect vdpevlmon fi;
    r:= length(f);
    a := makerarray list(r,n);
    for i:=1 step 1 until r do
      for k:=1 step 1 until n do
        putrarray(a ,i,k, nth(nth(explist,i),k));
    return hilbertzerodimp (r, n, a);
  end;

symbolic procedure gzerodimeval u;
   begin integer n;
      n := length u;
      if n = 2 then return gzerodim1(reval car u,reval cadr u)
       else
       rerror(groebnr2,20,
              "GZERODIM? called with wrong number of arguments")
   end;

put('gzerodim!?,'psopfn,'gzerodimeval);

symbolic procedure gzerodim1(u,v);
   begin scalar vars,w,z,dv,oldorder;
      w := for each j in getrlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,21,
                            "Empty list in HilbertPolynomial");
      vars :=
       if null v then for each j in gvarlis(w) collect !*a2k j
          else                      % test, if vars are really used
             << z := gvarlis (w);
                for each j in (v:= getrlist v) do
                    if member(j,z) then dv := !*a2k j . dv;
                dv := reversip dv;
                if not (length v = length dv) then
                      << prin2 " HilbertPolynomial: ";
                         prin2 (length v - length dv);
                         prin2t " of the variables not used";
                         terpri () >>;
                dv>>;
      if not vars then vdperr 'gzerodim!?;
      oldorder := vdpinit vars;
      w := for each j in w collect numr simp j;
      w := for each j in w collect f2vdp j;
      w := groezerodim!? (w,length vars);
      setkorder oldorder;
      return if w then newhilbi(u,'x,'list . v) else nil;
   end;

symbolic procedure gbtest(g);
   % test, if the given set of polynomials is a Groebner basis.
   % only fast to compute plausilbility test.
    begin scalar fredu,g1,r,s;
      g := vdplsort g;
        % make abbreviated version of G
      g1:= for each p in g collect
        << r := vdpred p;
           if vdpzero!? r then p else
               vdpsum(vdpfmon(vdplbc p,vdpevlmon p),
                      vdpfmon(vdplbc r,vdpevlmon r))
        >>;
      while g1 do
      <<for each p in cdr g1 do
         if not groebbuchcrit4t(vdpevlmon car g1,vdpevlmon p) then
        <<s := groebspolynom(car g1,p);
          if not vdpzero!? s and
                null groebsearchinlist (vdpevlmon s,cddr g1)
           then rerror(groebnr2,22,
             "****** Not a GROEBNER basis wrt current ordering");
         >>;
        if groebsearchinlist(vdpevlmon car g1,cdr g1) then
             fredu := t;
        g1 := cdr g1;
      >>;
      if fredu then
        <<terpri!* t;
        prin2t "WARNING:system is not a fully reduced GROEBNER basis";
        prin2t "with current term ordering";
        >>;
     end;

endmodule;


end;
