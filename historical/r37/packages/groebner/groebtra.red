module groebtra;
 
 % calculation of a Groebner base with the Buchberger algorithm
 % including the backtracking information which denotes the
 % dependency between base and input polynomials
 
%   Authors:   H. Melenk, H.M. Moeller,  W. Neun
%              November 1988
 
fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*groebstat !*groebdivide !*groebprot
 
        vdpvars!*                  % external names of the variables
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpSortMode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*             % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbcCurrentMode!*           % current domain for base coeffs.
        groetags!*                 % starting point of tag variables
        groetime!*
       );
 
global '(gvarslast);
 
switch groebopt,groebfac,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,groebstat,groebprot;
 
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

symbolic procedure groebnertra1(u,v,mod1);
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
	   "groebnert parameter not {...,name = polynomial,...}")
            else cadr j . caddr j
          >>;
      if null u then rerror(groebnr2,12,"Empty list in Groebner")
       else if null cdr u then 
            return 'list . list('equal,cdar u,caar u);;
      w := for each x in u collect cdr x;
      if mod1 then
      <<z := nil;
        for each vect in w do 
         <<if not eqcar(vect,'list) then
	      rerror(groebnr2,13,"Non list given to groebner");
           if nmod=0 then nmod:= length cdr vect else
           if nmod<(x:=length cdr vect) then nmod=x;
           z := append(cdr vect,z);
         >>;
	 if not eqcar(mod1,'list) then
	      rerror(groebnr2,14,"Illegal column weights specified");
         vars := groebnervars(z,v);
         tagvars := for i:=1:nmod collect mkid('! col,i);
         w := for each vect in w collect
	 <<z:=tagvars; y := cdr mod1;
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
         <<z :=  f2vdp cdr j; vdpPutProp(z,'cofact,car j)>>;
      if not !*vdpInteger then
      <<np := t;
        for each p in w do
          np := if np then vdpcoeffcientsfromdomain!? p else nil;
        if not np then <<!*vdpModular:= nil; !*vdpinteger := T>>;
      >>;
 
      w := groebtra2 w;
      w := if mod1 then groebnermodres(w,nmod,tagvars) else
                       groebnertrares w;
      setkorder oldorder;
      gvarslast := 'list . vars; return w;
   end;
 
symbolic procedure groebnertrares w;
   begin scalar c,u;
    return 'list . for each j in w collect
        <<c := prepsq vdpgetprop(j,'cofact);
          u := vdp2a j;
          if c=0 then u else list('equal,u,c) >>;
   end;


symbolic procedure groebnermodres(w,n,tagvars); 
   begin scalar x,c,oldorder;
      c := for each u in w collect prepsq vdpgetprop(u,'cofact);
      oldorder := setkorder tagvars;
      w := for each u in w collect 
       'list . <<u := numr simp vdp2a u;
          for i := 1:n collect
           prepf if not domainp u and mvar u = nth(tagvars,i)
             then <<x := lc u; u := red u; x>> else nil >>;
      setkorder oldorder;
         % reestablish term order for output
      w := for each u in w collect vdp2a a2vdp u;
      w := pair(w,c);
      return 'list . for each p in w collect 
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
         integer pcount!*; !*exp := t;
      pars := groeparams(pars,2,3);
      y := car pars; u := cadr pars; v:= caddr pars;
      u := for each j in getrlist u
              collect
          <<if not eqcar(j,'equal) then
            j . j else  cadr j . caddr j>>;
      if null u then rerror(groebnr2,15,"Empty list in preducet");
      w := for each p in u collect cdr p;  % the polynomials
      groedomainmode();
      vars := if null v then
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
	      "groebnerm called with wrong number of arguments")
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
       << prin2 "Groebner Calculation with Backtracking starts ";
          terprit 2 >>;
       spac := gctime();
       p1:=  groebTra3 (p);
       if !*trgroeb or !*trgroebr or !*groebstat then
       << spac1 := gctime() - spac; terpri();
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
          prin2  "Crit M hits: "; prin2t Mcount!*;
          prin2  "Crit F hits: "; prin2t Fcount!*;
          prin2  "Crit B hits: "; prin2t bcount!*;
          prin2  "Crit B4 hits: "; prin2t B4count!* >>;
       return p1;
 end;
 
symbolic procedure groebTra3 (g0);
   begin scalar x,g,d,d1,d2,p,p1,s,h,g99,one;
         x := for each fj in g0 collect vdpenumerate trasimpcont fj;
         for each fj in x do g := vdplsortin(fj,g0);
         g0 := g; g := nil;
% iteration :
      while (d or g0) and not one do
       begin if g0 then
          <<          % take next poly from input
               h := car g0; g0 := cdr g0;
               p := list(nil,h,h) >>
             else
          <<          % take next poly from pairs
               p := car d; d := cdr d;
               s := traspolynom (cadr p, caddr p); tramess3(p,s);
               h := groebnormalform(s,g99,'tree); %piloting wo cofact
               if vdpzero!? h then groebmess4(p,d)
               else h := trasimpcont tranormalform(s,g99,'tree,'h) >>;
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
                                <<g := delete (f,G); groebmess2 f>> >>;
                  groebmess51(d1);
               d2 := nil;
               while d1 do
                  <<d1 := groebinvokecritf d1; 
                    p1 := car d1;
                    d1 := cdr d1;
                    if groebbuchcrit4(cadr p1,caddr p1,car p1)
                       then d2 := append (d2, list p1);
                    d1 := groebinvokecritm (p1,d1) >>;
                 d := groebinvokecritb (h,d);    
                 d := groebcplistmerge(d,d2);   
                 g := h . g;
                 g99 := groebstreeadd(h, g99);
                            groebmess8(g,d);
    bott:
   end;
   return groebtra3post g;
end;   
 
symbolic procedure groebtra3post (g);
  % final reduction
   begin scalar r,p;
      g := vdplsort g;
      while g do
      <<p := tranormalform(car G,cdr G,'sort,'f);
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
            vev:=vdpevlmon f; c:=vdpLbc f;
            divisor :=
               if type = 'tree then groebsearchinstree (vev,g)
                               else groebsearchinlist (vev,g);
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor >>;
            if divisor then
                      if !*vdpInteger  then
                          f := trareduceonestepint(f,nil,c,vev,divisor)
                       else
                          f := trareduceonesteprat(f,nil,c,vev,divisor)
               else
                  break := t;
          end;
      if mode = 'f then f := tranormalform1(f,g,type,mode);
      return f
   end;

symbolic procedure tranormalform1(f,g,type,mode);
 % reduction of subsequent terms
  begin scalar c,vev,divisor,break,f1;
    mode := nil;
    f1 := f;
    while not vdpzero!? f and not vdpzero!? f1 do
    <<f1 := f; break := nil;
      while not vdpzero!? f1 and not break do
          <<vev:=vdpevlmon f1; c:=vdpLbc f1;
            f1 := vdpred f1;
            divisor :=
               if type = 'tree then groebsearchinstree (vev,g)
                               else groebsearchinlist (vev,g);
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor >>;
            if divisor then
            <<  if !*vdpInteger  then
                    f := trareduceonestepint(f,nil,c,vev,divisor)
                  else
                    f := trareduceonesteprat(f,nil,c,vev,divisor);
               break := t>> >> >>;
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
      dummy := nil;
      fcofa := vdpgetprop(f,'cofact);
      if null fcofa then fcofa := nil ./ 1;
      gcofa := vdpgetprop(g1,'cofact);
      if null gcofa then gcofa := nil ./ 1;
      vevlcm := vevdif(vev,vdpevlmon g1);
      cg := vdpLbc g1;
            % calculate coefficient factors
      x := vbcgcd(c,cg);
      a := vbcquot(cg,x);
      b := vbcquot(c,x);
      f:= vdpilcomb1 (f, a, vevzero(), g1,vbcneg b, vevlcm);
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
      dummy := nil;
      fcofa := vdpgetprop(f,'cofact);
      gcofa := vdpgetprop(g1,'cofact);
      vev := vevdif(vev,vdpevlmon g1);
      x := vbcneg vbcquot(c,vdplbc g1);
      f := vdpilcomb1(f,a2vbc 1,vevzero(), g1,x,vev);
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
    cofac1 := vdpgetprop(p1,'cofact); cofac2 := vdpGetProp(p2,'cofact);
    ep1 := vdpevlmon p1;             ep2 := vdpevlmon p2;
    ep := vevlcm(ep1, ep2);
    rp1 := vdpred p1;               rp2 := vdpred p2;
    db1 := vdpLbc p1;                db2 := vdpLbc p2;
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
    if !*vdpInteger then trasimpconti p else trasimpcontr p;
 
% routines for integer coefficient case:
% calculation of contents and dividing all coefficients by it
 
symbolic procedure trasimpconti (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar res,num,cofac;
    if vdpzero!?  p then return p;
    cofac := vdpgetprop(p,'cofact);
    num := car vdpcontenti p;
    if not vbcplus!? num then num := vbcneg num;
    if not vbcplus!? vdpLbc p then num:=vbcneg num;
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
    if vdpzero!? p then return p;
    if vbcone!? vdpLbc p then return p;
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
    <<dummy := nil; quotsq(cofac,simp vbc2a num)>>;
 
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
     if !*trgroeb then << terpri();
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
               writepri(mkquote prepsq  vdpGetProp(s,'cofact),'only);
                            groetimeprint();
                            terprit 3 >>;
 
endmodule;
 
end;
