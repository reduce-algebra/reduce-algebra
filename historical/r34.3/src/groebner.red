module groebner;

% module structure:       
%
%     GROEBNER  package + GROEBNR2 package
%        polynomial arithmetic:
%         VDP2DIP package included in DIPOLY package
%        factorization:
%         GROEBFAC package is also included here, but could be loaded
%         on demand.

fluid '(currentvdpmodule!*);

currentvdpmodule!* := 'vdp2dip;

imports vdp2dip;

create!-package('(groebner grinterf grinter2 buchbg groebcri
         groesolv groebopt groebsea groebsor groebspa groebfac
         groebidq kredelw),
         '(contrib groebner));

% Other packages needed.

load!-package 'dipoly;

endmodule;


module grinterf;  % Interface of Groebner package to REDUCE.
                  % Entry points to the main module and general
                  % interface support.


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
        gmodule                    % external module basis
        gmodule!*                  % internal module basis
       );

global '(groebrestriction        % interface: name of function
         groebresmax            % maximum number of internal results
         gvarslast                 % output: variable list 
         groebprotfile
         gltb
         glterms                   % list for lterms collection
        );

flag ('(groebrestriction groebresmax gvarslast groebprotfile
        gltb glterms gmodule),'share);

switch groebopt,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,onlyheadtermreduction,groebprereduce,groebstat,
       gcheckpoint,grestart,gltbasis,groebsubs;

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);

% control of the polynomial arithmetic actually loaded
fluid '(currentvdpmodule!*);

vdpsortmode!* := 'lex;     % initial mode 
gltb := '(list);           % initially empty

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    interface functions

symbolic procedure groebnereval u;
  % non factorizing Groebner calculation
   begin integer n; scalar !*groebfac,!*groebrm,!*factor,
                !*exp; !*exp := t;
      n := length u;
      if n=1 then return cadr groebner1(reval car u,nil,nil)
       else if n neq 2
        then rerror(groebner,1,
                    "GROEBNER called with wrong number of arguments");
       u:= groebner1(reval car u,reval cadr u,nil);
       if !*gltbasis then gltb := cadr gltb;
       return cadr u;
      end;

put('groebner,'psopfn,'groebnereval);

symbolic procedure groebnerfeval u;
  % non factorizing Groebner calculation 
   begin integer n; scalar !*groebfac,!*groebrm,!*factor,
         !*exp,!*ezgcd,s,r,q; !*exp := t;
      if null getd 'groebfactorize then load!-package 'groebfac;
      !*groebrm := !*groebfac := t;
      groebrestriction!* := reval groebrestriction;
      if null dmode!* then !*ezgcd:=t;
      n := length u;
      r:=  if n=1 then groebner1(reval car u,nil,nil) else
           if n=2 then groebner1(reval car u,reval cadr u,nil) else
           if n neq 3
        then rerror(groebner,2,
                    "GROEBNER called with wrong number of arguments")
             else  groebner1(reval car u,reval cadr u,reval caddr u);
      q := r;
       % remove duplicates.
      while q do <<s := car q; q := cdr q;
                    if member(s,q) then r := delete(s,r)>>;
      return r;
    end;

put('groebnerf,'psopfn,'groebnerfeval);

symbolic procedure idquotienteval u;
   begin integer n; scalar !*factor,!*exp; !*exp := t;
      n := length u;
      if n=2 then return groebidq(reval car u,reval cadr u,nil)
       else if n neq 3
        then rerror(groebner,3,
                    "IDQUOTIENT called with wrong number of arguments")
       else return groebidq(reval car u,reval cadr u,reval caddr u)
      end;

put('idealquotient,'psopfn,'idquotienteval);

smacro procedure vdpnumber f;
     vdpgetprop(f,'number) ;


symbolic procedure groebner1(u,v,r);
%    Buchberger algorithm system driver. u is a list of expressions
%    and v a list of variables or NIL in which case the variables in u
%    are used.
   begin scalar vars,w,np,oldorder;
         integer pcount!*;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebner,4,"Empty list in Groebner");
      vars := groebnervars(w,v);
      if r then r := groerevlist r;
      groedomainmode();
      if vars then goto notempty;
      u:=0; for each p in w do if p neq 0 then u:=1;
      return {'list,{'list,u}};
   notempty:
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect reorder numr simp j;
                  % optimize varable sequence if desired
      if !*groebopt then<< w:=vdpvordopt (w,vars); vars := cdr w;
                           w := car w; vdpinit vars>>;
      w := for each j in w collect f2vdp j;
      if not !*vdpinteger then
      <<np := t;
        for each p in w do
          np := if np then vdpcoeffcientsfromdomain!? p else nil;
        if not np then <<!*vdpmodular:= nil; !*vdpinteger := t>>;
      >>;
      if !*groebprot then
          <<groebprotfile := list 'list>>;
      if r then r := for each p in r collect f2vdp numr simp p;
      w := groebner2(w,r);
      if !*gltbasis then
        gltb :=
           'list . for each base in w collect
                   'list . for each j in base collect
                      vdp2a vdpfmon(a2vbc 1,vdpevlmon j);
      if cdr w then  % Remove redundant partial bases.
      begin scalar !*gsugar;
        for each b in w do
         for each c in w do
          if b and b neq c then
           <<v:=t; for each p in c do
               v:=v and vdpzero!? groebnormalform(p,b,'list);
             if v then <<w:=delete(b,w); b:=nil>>;
           >>;
      end;
      w := 'list . for each base in w collect
                   'list . for each j in base collect vdp2a j;
      setkorder oldorder;
      gvarslast := 'list . vars;
      return w;
   end;

symbolic procedure groebnervars(w,v);
    begin scalar z,dv,vars;
      vars :=
       if null v then
                for each j in gvarlis w collect !*a2k j
          else                      % test, if vars are really used
             << z := gvarlis w;
                for each j in (v:= groerevlist v) do
                    if member(j,z) then dv := !*a2k j . dv;
                dv := reversip dv;
                if not (length v = length dv) and !*trgroeb then
                      << prin2 " Groebner: ";
                         prin2 (length v - length dv);
                         prin2t " of the variables not used";
                         terpri () >>;
                dv>>;
       return vars;
    end;

% symbolic procedure maklist pl;
% make list of polynomials. pl is a list of polynomials.
% maklist pl returns a list of distributive polynomials.
%  for each p in pl collect f2vdp car p;

symbolic procedure gvarlis u;
   % Finds variables (kernels) in the list of expressions u.
   sort(gvarlis1(u,nil),function ordop);

symbolic procedure gvarlis1(u,v);
   if null u then v
    else union(gvar1(car u,v),gvarlis1(cdr u,v));

symbolic procedure gvar1(u,v);
   if null u or numberp u or (u eq 'i and !*complex) then v
    else if atom u then if u member v then v else u . v
    else if get(car u,'dname) then v
    else if car u memq '(plus times expt difference minus)
     then gvarlis1(cdr u,v)
    else if car u eq 'quotient then gvar1(cadr u,v)
    else if u member v then v
    else u . v;

symbolic procedure groebidq(u,f,v);
%  Ideal quotient. u is a list of expressions (Gbasis), f a polynomial
%  and v a list of variables or NIL 
   begin scalar vars,w,np,oldorder,!*factor,!*exp;
         integer pcount!*; !*exp := t;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebner,5,"Empty list in IDEALQUOTIENT");
      if eqexpr f then f := !*eqn2a f;
      vars := groebnervars(w,v);
      groedomainmode();
      if null vars then vdperr 'idealquotient;
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect numr simp j;
      f :=  numr simp f;
                  % optimize varable sequence if desired
      w := for each j in w collect f2vdp j;
      f := f2vdp f; % now do the conversions
      if not !*vdpinteger then
      <<np := t;
        for each p in f.w do
          np := if np then vdpcoeffcientsfromdomain!? p
                else nil;
        if not np then <<!*vdpmodular:= nil; !*vdpinteger := t>>;
      >>;
      w := groebidq2 (w,f);
      w := 'list . for each j in w collect vdp2a j;
      setkorder oldorder;
      return w;
   end;

fluid '(!*backtrace);

symbolic procedure vdperr name;
  % case that no variables were found
    <<prin2 "**** Groebner illegal parmeter in "; prin2 name;
      if !*backtrace then backtrace();
      rerror(groebner,6," ,e.g. no relevant variables found")>>;

symbolic procedure groeparams(u,nmin,nmax);
   % u is a list of psopfn-parameters; they are given to REVAL and 
   % the number of parameters is controlled to be between nmin, nmax
   % result is the list of evaluated parameters padded with NILs
     begin integer n; scalar w; n:= length u;
       if n<nmin or n>nmax then rerror(groebner,7,
         "Illegal number of parameters in call to Groebner package");
       u:= for each v in u collect
         <<w := reval v;
           if eqcar(w,'list) then 'list . groerevlist w else w>>;
       while length u < nmax do u := append(u,'(nil));
       return u;
     end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% initialization of the distributive plynomial arithmetic
%

symbolic procedure vdpinit (vars);
     begin scalar desired,r,gm;
      % desired :=
      %    if member(vdpsortmode!*,'(LEX GRADLEX))
      %       then 'VDP2SF else 'VDP2DIP;
      % desired := 'VDP2DIP;
      % if desired neq currentVdpModule!* then
      % <<load!-package desired;
      %   currentVdpModule!* := desired>>;
          % Eventually set up module basis.
        if eqcar(gmodule,'list) and cdr gmodule then
         gm := for each y in cdr gmodule collect
          <<y := reval y;
            if not member(y,vars) then vars:=append(vars,{y});
            y >>;
        r:=vdpinit2(vars);
          % convert an eventual module basis.
        gmodule!* := if gm then vdpevlmon a2vdp ('times . gm);
        return r;
    end;

symbolic procedure groedomainmode();
     <<!*vdpinteger := !*vdpmodular := nil;
      if not flagp(dmode!*,'field) then !*vdpinteger := t
           else
      if !*modular then !*vdpmodular := t>>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% some lisp functions which are not member of standard lisp
%

symbolic procedure groedeletip(a,b);
   begin scalar q;
       while b and  a= car b do b:= cdr b;
       if null b then return nil;
       q := b;
       while cdr b do if a=cadr b then cdr b := cddr b else b:= cdr b;
       return q;
   end;

symbolic procedure groerevlist u;
      <<if idp u then u := reval u;
       for each p in getrlist u collect reval p>>;

endmodule;


module grinter2;  % Interface of Groebner package to REDUCE:
                  % autoloadint entry points to operators of groebnr2;


symbolic procedure groebnr2entry(fn,u);
       <<groebnr2load();
         apply(get(fn,'psopfn),list u)>>;

symbolic procedure groebnr2load();
       load!-package 'groebnr2;

put('gsort,'psopfn,
      '(lambda(u)(groebnr2entry 'gsort u)));

put('gsplit,'psopfn,
     '(lambda(u)(groebnr2entry 'gsplit u)));


put('gspoly,'psopfn,
     '(lambda(u)(groebnr2entry 'gspoly u)));

put('gvars,'psopfn,
     '(lambda(u)(groebnr2entry 'gvars u)));

put('greduce,'psopfn,
     '(lambda(u)(groebnr2entry 'greduce u)));

put('preduce,'psopfn,
     '(lambda(u)(groebnr2entry 'preduce u)));

put('groebnert,'psopfn,
     '(lambda(u)(groebnr2entry 'groebnert u)));

put('preducet,'psopfn,
     '(lambda(u)(groebnr2entry 'preducet u)));

put('groebnerm,'psopfn,
     '(lambda(u)(groebnr2entry 'groebnerm u)));

put('glexconvert,'psopfn,
     '(lambda(u)(groebnr2entry 'glexconvert u)));

put('hilbertpolynomial,'psopfn,
     '(lambda(u)(groebnr2entry 'hilbertpolynomial u)));

put('gzerodim!?,'psopfn,
     '(lambda(u)(groebnr2entry 'gzerodim!? u)));

put('trgroeb,'simpfg,'((t (groebnr2load))));
put('trgroebs,'simpfg,'((t (groebnr2load)(setq !*trgroeb t))
                        (nil (setq !*trgroeb nil))));
put('trgroebr,'simpfg,'((t (groebnr2load))));
put('groebstat,'simpfg,'((t ( groebnr2load))));
put('groebweak,'simpfg,'((t (groebnr2load))));
put('groebres,'simpfg,'((t (groebnr2load))));

symbolic procedure groebtestrestriction (a1,a2);
   <<groebnr2load(); apply('groebtestrestriction,list(a1,a2))>>;
endmodule;


module buchbg;  % Central Groebner base code: Buchberger algorithm.

%   Authors:   H. Melenk, H.M. Moeller,  W. Neun
%   ZIB Berlin 
%   July 1988 

fluid '(!*gcd);

fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*groebfullreduction !*groebstat !*groebdivide !*groebprot
        !*groebheufact !*groebweak !*groelterms

        vdpvars!*                  % external names of the variables
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        groebdomain!*              % domain mode if selected explicitly
        factortime!*               % computing time spent in factoring
        factorlevel!*              % bookkeeping of factor tree
        groefeedback!*             % sideeffect factorization
        groesfactors!*             % data structure for act. fact.
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*           % current domain for base coeffs.
        vbcmodule!*                % for modular calculation: 
                                   % current prime
        groetime!*
        !*gsugar                   % enable Traverso's sugar technique
        groecontcount!*            % control of content reduction     
       );

global '(groebrestriction          % interface:
                                   %  name of restriction function
         groebresmax            % maximum number of internal results
         gvarslast                 % output: variable list 
         groebmonfac               % minimum exponent for reduction of
                                   % monomial factors
         groebprotfile             % reduction protocol
         glterms                   % list for lterms collection
        );

flag ('(groebrestriction groebresmax gvarslast groebmonfac
         groebprotfile glterms), 'share);

groebrestriction := nil;
groebresmax := 300;
groebmonfac := 1;
!*groebfullreduction := t;
% !*gsugar := t;
!*groelterms := t;

switch groebopt,groebrm,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,groebfullreduction,groebprereduce,groebstat,
       gcheckpoint,grestart,groebdivide,groebprot;

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);

%      option ' groebopt'    "optimizes" the given input
%                            polynomial set ( variable
%                            ordering )
%      option ' trgroeb'     prints intermediate
%                            results on the output file
%      option ' trgroeb1'    prints internal representation
%                            of critical pair list d
%      option ' trgroebs '   prints S - polynomials
%                            on the output file
%      option   trgroebr     prints (intermediate) results and
%                            computation statistics
% groebstat  the statistics are printed
% groebres   the H- polynomials are optimised using resultant
%            and factorisation method
%
% groebrm    multiplicities of factors in h-polynomials are reduced
%            to simple factors.
%
% groebdivide
%            the algorithm avoids all divisions (only for modular
%            calculation) , if this switch is set off;
%
% groebprot  Write a protocol to the variable "groebprotfile";

!*groebfullreduction := t;
%!*groebPreReduce := T;
!*groebdivide := t;


% the code for checkpointing is factored out
% This version: NO CHECKPOINT FACILITY

smacro procedure groebcheckpoint1(); list nil;
smacro procedure groebcheckpoint2(); list nil;
smacro procedure groebcheckpoint2a(); list nil;
smacro procedure groebcheckpoint3(); list nil;
smacro procedure groebcheckpoint4(); list nil;
smacro procedure groebcheckpoint5(); list nil;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% some macros for local usage only

smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);

symbolic procedure vevdivides!? (vev1,vev2);
    % test: vev1 divides vev2 ? for exponent vectors vev1,vev2
    vevmtest!? (vev2,vev1) and
     null gmodule!* or gevcompatible1(vev1,vev2,gmodule!*);

symbolic procedure gevcompatible1(v1,v2,g);
  % test whether v1 and v2 belong to the same vector column.
   if null g then t
   else if null v1 then (null v2 or gevcompatible1('(0),v2,g))
   else if null v2 then gevcompatible1(v1,'(0),g) else
    (car g = 0 or car v1 = car v2) and
         gevcompatible1(cdr v1,cdr v2,cdr g);

symbolic procedure gcompatible(f,h);
   null gmodule!* or
     gevcompatible1(vdpevlmon f,vdpevlmon h,gmodule!*);

symbolic procedure groebmakepair(f,h);
     % construct a pair from polynomials f and h
   begin scalar ttt,sf,sh;
      ttt:=tt(f,h);
      return if !*gsugar then
      <<sf:=gsugar(f) #+ vevtdeg vevdif(ttt,vdpevlmon f);
        sh:=gsugar(h) #+ vevtdeg vevdif(ttt,vdpevlmon h);
        list(ttt,f,h,max(sf,sh))>>
       else list(ttt,f,h);
   end;

% the 1-polynomial will be constructed at run time
% because the length of the vev is not known in advance
fluid '(vdpone!*);

symbolic procedure vdponepol;
    % construct the polynomial=1
    vdpone!* := vdpfmon(a2vbc 1,vevzero());

symbolic procedure groebner2(p,r);
  % setup all global variables for the Buchberger algorithm
  % printing of statistics
 begin scalar groetime!*,tim1,spac,spac1,p1,factortime!*,
              pairsdone!*,factorlevel!*,groesfactors!*,!*gcd;
       factortime!* := 0;
       groetime!*   := time();
       vdponepol(); % we construct dynamically
       hcount!* := 0; mcount!* := 0; fcount!* := 0;
       bcount!* := 0; b4count!* := 0; hzerocount!* := 0;
       basecount!* := 0; !*gcd := t; glterms := list('list);
       groecontcount!* := 10;
       if !*trgroeb then
       << prin2 "Groebner Calculation starting ";
          terprit 2;
          prin2 " groebopt: "; print !*groebopt;
       >>;
       spac := gctime();

       p1:=  groebbasein (p, !*groebfac, !*groebres,r);

       if !*trgroeb or !*trgroebr or !*groebstat then
       <<
          spac1 := gctime() - spac;
          terpri();
          prin2t "statistics for GROEBNER calculation";
          prin2t "===================================";
          prin2 " total computing time (including gc): ";
          prin2((tim1 := time()) - groetime!*);
          prin2t "          milliseconds  ";
       if factortime!* neq 0 then
        <<prin2 " (time spent in FACTOR (excl. gc):    ";
          prin2 factortime!*;
          prin2t "          milliseconds)";
        >>;
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


smacro procedure testabort h;
     vdpmember (h,abort1) or
      'cancel = (abort2 := groebtestabort(h,abort2));

symbolic procedure groebenumerate f;
  % f is a temporary result. Prepare it for medium range storage
  % and ssign a number
  if vdpzero!? f then f else
   << if not vdpgetprop(f,'number) then
      <<f := vdpputprop(f,'number,(pcount!* := pcount!* #+ 1));
        if !*groebprot then
          << groebprotsetq(mkid('poly,pcount!*),'candidate);
             vdpputprop(f,'groebprot,mkid('poly,pcount!*));
          >>;
      >>;
     f>>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Buchberger's Algorithm
%
% INPUT :   G0 = { f1, ... , fr}  set of nonzero polynomials
% OUTPUT:   groebner basis (list of nonzero polynomials)
%
% internal variables:
%
%    problems  list of problems to be processed. problems is non nil,
%              if the inital problem was split by a successful factoring
%    results   collection of results from problems
%    G         basis under construction
%    G1        local pointer to G
%    D         list of critical pairs during algorithm
%    D1,D2     local lists of pairs during update of D
%    f,fj      polynomials
%    p,p1,p2   pairs
%    s,h       polynomials in the central part of the algorithm
%              (the "s-poly" and the "h-poly" selon Buchberger
%    G99       set of polynomials used for reduction. Held as
%              a search tree
%    abort1    list of polynomials in factorization context.
%              a calculation branch can be cancelled if one of
%              these polys is detected
%    abort2    list of sets of polynomials. If a new h polynomial
%              is calculated, it should be removed from the sets.
%              if one set becomes null, the set restriction is
%              fulfilled and the branch can be cancelled

symbolic procedure groebbasein (g0,fact,groebres,abort1);
   begin scalar problems, results, abort2,x,
                g,g1,d,d1,d2,p,p1,s,h,g99,hlist,lv,lasth;
         integer gvbc;
         integer lastcheckpoint,probcount!*;

         lv := length vdpvars!*;

         groebcheckpoint1();

         for each p in g0 do
            if vdpzero!? p then g0 := delete(p,g0);

          if !*groebprereduce then g0 := groebprereduce g0;

          x := for each fj in g0 collect
                gsetsugar(vdpenumerate vdpsimpcont fj,nil);

          if !*groebprot then
           for each f in x do
           << groebprotsetq(mkid('poly,h:= vdpnumber f), vdp2a f);
              vdpputprop(f,'groebprot,mkid('poly,h))>>;

          g0 := x;

                                       % establish the initial problem
        problems := list (list (nil,nil,nil,g0,abort1,nil,nil,
                          vbccurrentmode!*, nil,nil) );

        !*trgroeb and groebmess1(g,d);
        goto macroloop;


% RESTART:
        groebcheckpoint2();

macroloop:

  while problems and gvbc < groebresmax do
  begin
     groebcheckpoint2a();
                                       % pick up next problem
     x := car problems;
     groebcheckpoint3();
     d := car x;
     g := cadr x;
     g99 := groebstreereconstruct caddr x;
     g0 := cadddr x;
     abort1 := nth(x,5);
     abort2 := nth(x,6);
     pairsdone!* := nth(x,7);
     h := nth(x,8);                     % vbcCurrentMode!*
     factorlevel!* := nth(x,9);
     groesfactors!* := nth(x,10);
     groebcheckpoint4();
     problems := cdr problems;
     g0 := % sort G0, but keep factor in first position
       if factorlevel!* and  g0 and cdr g0 then car g0 . vdplsort cdr g0
        else vdplsort g0;
     x := nil;
     lasth := nil;

                !*trgroeb and groebmess23 (g0,abort1,abort2);

% ITERATION :
      while d or g0 do
       begin
          if groebfasttest(g0,g,d,g99) then goto stop;
                 !*trgroeb and groebmess50(g);
          if g0 then
          <<          % take next poly from input
               h := car g0;
               g0 := cdr g0;
               gsetsugar(h,nil);
               groebsavelterm h;
               p := list(nil,h,h);
          >>
             else
          <<          % take next poly from pairs
               p := car d;
               d := delete (p,d);
               s := groebspolynom (cadr p, caddr p);
               if fact then
                    pairsdone!* := (vdpnumber cadr p
                                      . vdpnumber caddr p)
                              . pairsdone!*;
                           !*trgroeb and groebmess3 (p,s);

               h:=groebsimpcontnormalform groebnormalform(s,g99,'tree);
                  if vdpzero!? h then !*trgroeb and groebmess4(p,d);

                                      % test for possible chains
               if not vdpzero!? h then  % only for real h's
                   << s := groebchain (h,cadr p,g99);
                      if s = h then
                        h := groebchain (h,caddr p,g99);
                        if secondvalue!* then
                            g := delete(secondvalue!*,g)>>;
          >>;

          if vdpzero!? h then goto bott;

          if vevzero!? vdpevlmon h then % base 1 found
                  <<   !*trgroeb and groebmess5(p,h);
                   goto stop>>;

          if testabort(h) then
                  <<   !*trgroeb and groebmess19(h,abort1,abort2);
                   goto stop>>;

          s:= nil;

                    % look for implicit or explicit factorization
          hlist := nil;
          if groebrestriction!* then
                    hlist := groebtestrestriction(h,abort1);
          if not hlist and fact then
                    hlist := groebfactorize(h,abort1,g,g99);
          if hlist = 'zero then goto bott;
          if groefeedback!* then g0 := append(groefeedback!*,g0);
          groefeedback!* := nil;
                   % factorisation found but only one factor survived
          if hlist and length hlist = 2 then
                   <<h := car cadr hlist; hlist := nil>>;
          if not hlist and groebres then
             <<hlist := groebtestresultant(lasth,h,lv);
               if hlist then groebres := nil>>;
          if hlist then
                <<if hlist neq 'cancel then
                   problems:=
                    groebencapsulate(hlist,d,g0,g,g99,
                           abort1,abort2,problems,fact);
                  go stop;
                >>;

                  % h polynomial is accepted now
               h := groebenumerate h; !*trgroeb and groebmess5(p,h);

                              % construct new critical pairs
               d1 := nil;

                   !*trgroeb and groebmess50(g);
               for each f in g do
                  if(car p or % that means "not an input polynomial"
                     not member (vdpnumber h . vdpnumber f, pairsdone!*)
                    ) and gcompatible(f,h)
                   then
                    <<d1 := groebcplistsortin(groebmakepair(f,h),d1);
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

                         % monomials and binomials
                 if vdplength h < 3 and car p then
                   <<g := groebsecondaryreduction (h,g,g99,d,nil,t);
                     if g = 'abort then goto stop;
                     g99 := secondvalue!*;
                     d := thirdvalue!*>>;
                 g := h . g;
                 lasth := h;
                 g99 := groebstreeadd(h, g99);
                            !*trgroeb and groebmess8(g,d);
                 goto bott;

    stop:        d := g := g0 := nil;

    bott:
         groebcheckpoint5();
   end;      %  ITERATION

   g := vdplsort g;       % such that T descending

% FINALREDUCTION:
   x := groebbasein2(g,g99,problems,abort1,abort2,fact);
   g1 := car x; problems := cdr x;
   if g1 then <<results := g1 . results; gvbc := gvbc+1>>;
   !*trgroeb and groebmess13(g1,problems);

  end;     % MACROLOOP

  if gvbc  >= groebresmax then
      lpriw("########","warning: GROEBRESMAX limit reached");

  return groebbasein3 results;
end;

symbolic procedure groebfasttest(g0,g,d,g99); nil;
           % a hook for special techniques

symbolic procedure groebbasein2(g,g99,problems,abort1,abort2,fact);
  % final reduction for a base G: reduce each polynomial with the
  % other members; here again support of factorization
  begin scalar !*groebfullreduction,!*groebheufact;     % saving value
   scalar g1,f,h,hlist,x; integer cnt;
   !*groebfullreduction := t;
   g1 := nil;
   while g do
      <<h := car g;
        g := cdr g;
        if !*groebprot then
          groebprotsetq('candidate,mkid('poly,vdpnumber h));
        h := groebnormalform (h,g,'sort);
        f := groebsimpcontnormalform h;
                           !*trgroeb and groebmess26(h,f);
        if !*groebprot then
          groebprotsetq({'gb,cnt:=cnt+1},'candidate);
        if vdpone!? f then <<g1 := g := nil>>;  % base {1} found
                                                % very late now
        if fact and not vdpzero!? f then
            << hlist := groebfactorize (f,abort1,nil,nil);
               if not null hlist then
                 <<          % lift structure
                  hlist := for each x in cdr hlist collect car x;
                             % discard superfluous factors
                  for each h in hlist do
                       if vdpmember(h,abort1) then
                           <<hlist := delete(h,hlist);
                               !*trgroeb and
                               groebmess19(h,abort1,abort2)>>;
                                       % generate new subproblems
                  x := 0;
                  for each h in hlist do
                    <<hlist := delete(h,hlist);
                      h := groebenumerate h;
                      problems:=
                         list(nil,                 % null D
                              append(g1,g),        % base
                              g99,                 % G99
                              list h,              % G0
                              append(hlist,abort1),
                              abort2,
                              pairsdone!*,
                              vbccurrentmode!*,
                              (x := x+1) . factorlevel!*,
                              groesfactors!*
                             ) . problems;
                    >>;
                  g := g1 := nil;     % cancel actual final reduction
                  f := nil;
                >>
              >>;
        if f and vdpevlmon h neq vdpevlmon f then
        <<g:= vdplsort append(g,f . g1); g1 := nil>> else
        if f and not vdpzero!? f then g1 := append (g1 ,list f);
        >>;
     return g1.problems;
   end;

symbolic procedure groebbasein3(results);
 % final postprocessing : remove multiple bases from the result
 begin scalar x,g,f,p1,p2;
  x := nil; g := results; p1 := p2 := 0;
  while results do
      <<if vdpone!? car car results      % exclude multiple {1}
              then p1 := p1 + 1              % count ones
          else
      <<f := for each p in car results     % delete props for member 
                     collect vdpremallprops p;
        if  member (f,x)                     % each base only once
              then p2 := p2 + 1              % count multiples
            else x := f . x;
         results := cdr results>> >>;
  results := if null x then list list vdpone!* else x;
  return results;
end;

fluid '( !*vbccompress);


symbolic procedure groebchain(h,f,g99);
    % test if a chain from h-plynomials can be computed from the h
   begin scalar h1,h2,h3,count,found;
         secondvalue!* := nil;
       return h; % erst einmal
         if not vevdivides!? (vdpevlmon h, vdpevlmon f) then return h;
         h2 := h;
         h1 := f;
         found := t;
         count := 0;
         while found do
                  <<h3 := groebspolynom(h1,h2);
                    h3 := groebnormalform(h3,g99,'tree);
                    h3 := vdpsimpcont h3;
                    if vdpzero!? h3 then
                           <<found := nil;
                            prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             secondvalue!* := f;
                             count := 9999>>
                      else
                   if vdpone!? h3 then
                           <<found := nil;
                            prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             h2 := h3;
                             count := 9999>>

                      else
                    if vevdivides!?(vdpevlmon h3, vdpevlmon h2) then
                           <<found := t;
                             prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             h1 := h2;
                             h2 := h3;
                             count := count+1>>
                      else
                           found := nil;
                  >>;
       return if count > 0 then
             << prin2 "CHAIN :"; prin2t count; h2>>
            else h;
    end;


symbolic procedure groebencapsulate(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
% hlist is a factorized h poly. This procedure has the job to
% form new problems from hlist and to add them to problems.
% Result is problems.
% Standard procedure: only creation of subproblems
    begin scalar factl,      % list of factorizations under way
                 u,y,z;
          integer fc;
      if length vdpvars!*>10 or car hlist neq 'factor then
          return groebencapsulatehardcase(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
                            % encapsulate for each factor
      factl := groebrecfactl list hlist;;
                   !*trgroeb and groebmess22 (factl,abort1,abort2);
      for each x in reverse factl do
           <<y := append (car x, g0);
             z := vdpunion (cadr x,abort1);
             u := append(caddr x,abort2);
                  problems :=  list(
                            d,
                            g,
                            g,                       % future G99
                            y,                       % as new problem
                            z,                       % abort1
                            u,                       % abort2
                            pairsdone!*,             % pairsdone!*
                            vbccurrentmode!*,
                            (fc:= fc+1) . factorlevel!*,
                            groesfactors!*
                           ) . problems;
            >>;
        return problems;
end;




symbolic procedure groebencapsulatehardcase(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
% hlist is a factorized h poly. This procedure has the job to
% form new problems from hlist and to add them to problems.
% Result is problems.
% First the procedure tries to compute new h-polynomials from the
% remaining pairs which are not affected by the factors in hlist.
% purpose is to find further factorizations and to do calculations
% in common for all factors in order to shorten the separate later
% branches;
    begin scalar factl,      % list of factorizations under way
                 factr,      % variables under factorization
                 u,h,d1,d2,p1,y,z,p,s,f,gc,pd,break,fl1;
          integer fc;
      factl := list hlist;
      factr := vdpspace car cadr hlist;
      for each x in cdr hlist do
         for each p in x do
             factr := vevunion(factr,vdpspace p);

% ITER:
                                 % now process additional pairs
      while d or g0 do
        begin
          break := nil;
          if g0 then
          <<               % next poly from input
               s := car g0; g0 := cdr g0; p := list(nil,s,s);
          >>
             else
          <<               % next poly fropm pairs
               p := car d; d := delete (p,d);
               if not vdporthspacep(car p,factr) then
                 s:= nil else
               <<s := groebspolynom (cadr p, caddr p);
                        !*trgroeb and groebmess3 (p,s);>>;
          >>;

          if null s or not vdporthspacep(vdpevlmon s,factr) then
              <<                     % throw away s polynomial
                 f := cadr p;
                 if not vdpmember3(f,g0,g,gc)
                      then gc := f . gc;
                 f := caddr p;
                 if car p and not vdpmember3 (f,g0,g,gc)
                      then gc := f . gc;
                  goto bott>>;

          h := groebnormalform(s,g99,'tree);
                  if vdpzero!? h and car p then
                               !*trgroeb and groebmess4(p,d);

          if not vdporthspacep(vdpevlmon h,factr) then
              <<                     % throw away h polynomial
                 f := cadr p;
                 if not vdpmember3(f,g0,g,gc)
                      then gc := f . gc;
                 f := caddr p;
                 if car p and not vdpmember3 (f,g0,g,gc)
                      then gc := f . gc;
                 goto bott>>;

          if car p then
                pairsdone!* := (vdpnumber cadr p . vdpnumber caddr p)
                              . pairsdone!*;

          if vdpzero!? h then goto bott;

          if vevzero!? vdpevlmon h then     % base 1 found
                   goto stop;

          h := groebsimpcontnormalform h;   %  coefficients normalized

          if testabort h then
                 <<!*trgroeb and groebmess19(h,abort1,abort2);
                   goto stop>>;

          s:= nil;

          hlist := nil;
          if groebrestriction!* then
                    hlist := groebtestrestriction(h,abort1);
          if hlist = 'cancel then goto stop;

          if not hlist and fact then
                  hlist := groebfactorize(h,abort1,g,g99);
          if groefeedback!* then g0 := append(groefeedback!*,g0);
          groefeedback!* := nil;
          if hlist and length hlist = 2 then
                   <<h := car cadr hlist; hlist := nil>>;
          if hlist then
                << for each x in cdr hlist do
                      for each h in x do
                           factr := vevunion(factr,vdpspace h);
                  factl := hlist . factl; % add to factors
                  goto bott>>;

          h := groebenumerate h;             % ready now

                        !*trgroeb and groebmess5(p,h);

                              % construct new critical pairs
          d1 := nil;


          for each f in g do
             if tt(f,h) = vdpevlmon(f) and gcompatible(f,h) then
              <<g := delete (f,g);
                d1 := groebcplistsortin( groebmakepair(f,h) , d1);
                             !*trgroeb and   groebmess2 f;
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

          if vdplength h < 3 then
                    <<g := groebsecondaryreduction (h,g,g99,d,gc,t);
                      if g = 'abort then goto stop;
                      g99 := secondvalue!*;
                      d := thirdvalue!*;
                      gc := fourthvalue!*>>;
          g := h . g;
          g99 := groebstreeadd(h, g99);

                            !*trgroeb and groebmess8(g,d);
          goto bott;

  stop:
         d := g := g0 := gc := factl := nil;
  bott:
         end;     %ITER

                            % now collect all relvevant polys
        g0 := vdpunion(g0,vdpunion(g,gc));

                            % encapsulate for each factor
        if factl then
           << factl := groebrecfactl factl;
              !*trgroeb and groebmess22 (factl,abort1,abort2);
           >>;
        for each x in reverse factl do
           <<fl1 := (fc := fc+1) . factorlevel!*;
             break:= nil;
             y := append (car x, g0);
             z := vdpunion (cadr x,abort1);
             u := append(caddr x,abort2);
             if vdpmember(vdpone!*,y) then break:=vdpone!*;

                        % inspect the unreduced list first 
             if not break then for each p in z do
                  if vdpmember(p,y) then break := p;

                        % now prepare the reduced list
            if not break then
            <<y := append (car x,groebreducefromfactors(g0,car x));
              pd := secondvalue!*;
              if vdpmember(vdpone!*,y) then break := vdpone!* else
                 for each p in z do if vdpmember(p,y) then break := p;
              pd := subla(pd,pairsdone!*);
            >>;

            if not break then
                  problems :=  list(
                            nil,                     % new D
                            nil,                     % new G
                            nil,                     % future G99
                            y,                       % as new problem
                            z,                       % abort1
                            u,                       % abort2
                            pd,                      % pairsdone!*
                            vbccurrentmode!*,
                            fl1,                     % factorlevel!*,
                            groesfactors!*           % factor db
                           ) . problems
                else !*trgroeb and groebmess19a(break,fl1);
            >>;
        return problems;
end;

symbolic procedure groebrecfactl (factl);
% factl is a list of factorizations:a list of lists of vdps
% generate calculation pathes from them
   begin scalar rf,res,type;
     if null factl then return list list(nil,nil,nil);
     rf := groebrecfactl (cdr factl);
     factl := car factl;
     type := car factl;   % FACTOR or RESTRICT
     factl := cdr factl;
     while factl do
        <<for each y in rf do
           if vdpdisjoint!?(car factl,cadr y) then
             res := list( vdpunion(car factl,car y),
                     (if type = 'factor then
                         append (for each x in cdr factl collect car x,
                                                                cadr y)
                        else
                      if type = 'resultant then
                         append (for each x in cdr factl collect cadr x,
                                                                cadr y)
                        else cadr y),
                     (if type neq 'factor and type neq 'resultant then
                         append(cdr factl,caddr y)
                        else caddr y)
                    ) . res;
          factl := cdr factl>>;
     return res;
   end;


symbolic procedure groebtestabort (h,abort2);
   % tests if h is member of one of the sets in abort2.
   % if yes, it is deleted. If one wet becomes null, the message
   % "CANCEL is returned, otherwise the updated abort2.
    begin scalar x,break,res;
              % car test the occurence
       x := abort2;
       while x and not break do
        << if vdpmember(h,car x) then break := t;
           x := cdr x>>;
       if not break then return abort2;  % not relvevant
       break := nil;
       while abort2 and not break do
        <<x := vdpdeletemember(h,car abort2);
          if null x then break := t;
          res := x . res;
          abort2 := cdr abort2;
        >>;
       !*trgroeb and groebmess25(h,res);
       if break then return 'cancel;
       return res;
    end;




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Reduction of polynomials
%

symbolic procedure groebnormalform(f,g,type);
     % general procedure for reduction of one polynomial from a set
     %  f is a polynomial, G is a Set of polynomials either in
     %     a search tree or in a sorted list
     % type describes the ordering of the set G:
     %    'TREE     G is a search tree
     %    'SORT     G is a sorted list
     %    'LIST     G is a list, but not sorted
     %  f has to be reduced modulo G
  begin scalar f0,f1,c,vev,divisor,break,done,fold,a;
        integer n,s1,s2;
      if !*groebweak and !*vdpinteger
            and groebweakzerotest(f,g,type) then return f2vdp nil;
      fold := f; f1 := vdpzero(); a:= vbcfi 1;
      gsetsugar(f1,gsugar f);
      while not vdpzero!? f do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;

            if not !*groebfullreduction and not vdpzero!? f1 then
                    g := nil;                 % cut off

            if type = 'sort then
                 while g and vevcompless!?(vev,vdpevlmon car g)
                            do g := cdr g;
            if null g then
                  <<f1:=vdpsum (f1,f); f:=vdpzero();
                    break := t; divisor := nil; goto ready>>;

            divisor :=
               if type = 'tree then groebsearchinstree(vev,g)
                               else groebsearchinlist (vev,g);

            if divisor then done := t;    % true action indicator

            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
                      if vdplength divisor = 1 then
                            f := vdpcancelmvev(f,vdpevlmon divisor)
                          else
                      if !*vdpinteger or not !*groebdivide then
                       << f:=groebreduceonestepint(f,f1,c,vev,divisor);
                          f1 := secondvalue!*; n := n+1;
                          if  not vdpzero!? f and
                              n #> groecontcount!* then
                          <<f0 := f;
                            f:=groebsimpcont2(f,f1);
                            groecontentcontrol(f neq f0);
                            f1 := secondvalue!*; n := 0 >>;
                       >>
                       else
                        f := groebreduceonesteprat(f,nil,c,vev,divisor)
               else
                  <<!*gsugar and <<s1:=gsugar(f);s2:=gsugar(f1)>>;
                    f1 := vdpappendmon (f1,vdplbc f,vdpevlmon f);
                    f := vdpred f;
                    !*gsugar and <<gsetsugar(f,s1);
                                   gsetsugar(f1,max(s2,s1))>>;
                    >>;
            ready:
          end;
      if !*groebprot then groebreductionprotocolborder();
      if not done then f1 := fold;
      return f1;
   end;

symbolic procedure groecontentcontrol u;
   % u indicates, that a substantial content reduction was done;
   % update content reduction limit from u.
  groecontcount!*:= if not numberp groecontcount!* then 10 else
                    if u then max(0,groecontcount!*-1)
                         else min(10,groecontcount!*+1);

symbolic procedure groebvbcbig!? a;
    % test if a is a "big" coefficient
     (if numberp x then (x > 1000000000000 or x < -1000000000000)
                   else t)
             where x=vbcnumber a;

symbolic procedure groebsimpcontnormalform h;
  % simpCont version preserving the property SUGAR 
     if vdpzero!? h then h else
     begin scalar sugar,c;
         sugar :=gsugar h; c:=vdplbc h;
         h := vdpsimpcont h;
         gsetsugar(h,sugar);
         if !*groebprot and not(c=vdplbc h)then
          groebreductionprotocol2
             reval list('quotient,vbc2a vdplbc h,vbc2a c);
         return h;
     end;

symbolic procedure groebsimpcont2(f,f1);
  % simplify two polynomials with the gcd of their contents;
    begin scalar c,s1,s2;
         s1:=gsugar f; s2:=gsugar f1;
         c := vdpcontent f;
         if vbcone!? vbcabs c then goto ready;
         if not vdpzero!? f1 then
         << c := vdpcontent1(f1,c);
            if vbcone!? vbcabs c then goto ready;
            f1 :=  vdpdivmon(f1,c,nil)>>;
         f := vdpdivmon(f,c,nil);
                 !*trgroeb and groebmess28 c;
         gsetsugar(f,s1); gsetsugar(f1,s2);
      ready:
         secondvalue!* := f1; return f;
    end;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special case reductions
%

symbolic procedure groebprereduce g;
% reduce the polynomials in g with themselves.
% the reduction is continued until headterms are stable
% is possible;
  begin scalar res,work,oldvev,f,oldf,!*groebweak,!*groebfullreduction;
        integer count;
     if !*trgroebs then
     <<  g := for each p in g collect vdpenumerate p;
         for each p in g do vdpprint p>>;
     res := nil; % delete zero polynomials from G
     for each f in g do if not vdpzero!? f then res := f . res;
     work := g := res := reversip res;
     while work do
      << g := vdplsort res;   % sort prvevious result
         if !*trgroebs then prin2t "Starting cycle in prereduction.";
         res := nil;
         count := count + 1;
         work := nil;
         while g do
         << oldf := f:= car g; g := cdr g;
            oldvev := vdpevlmon f;
            f := vdpsimpcont groebnormalform (f,g,'sort);
            if (!*trgroebs or !*groebprot) and not vdpequal(f,oldf) then
            <<f := vdpenumerate f;
              if !*groebprot then
                if not vdpzero!? f then
                 groebprotsetq(mkid('poly,vdpnumber f), vdp2a f)
                 else groebprotval 0;
              if !*trgroebs then
                 <<prin2t "reducing"; vdpprint oldf; prin2t "to";
                                                    vdpprint f>>;
            >>;
            if not vdpzero!? f then
            <<if oldvev neq vdpevlmon f then work := t;
              res := f . res>>;
         >>;
      >>;
     return for each f in res collect vdpsimpcont f;
     end;

symbolic procedure groebreducefromfactors (g,facts);
% reduce the polynomials in G from those in facts.
   begin scalar new,gnew,f,nold,nnew,numbers;
     if !*trgroebs then <<
                  prin2t "replacing from factors:";
                  for each x in facts do vdpprin2t x
                        >>;
     while g do
          <<f := car g;
            g := cdr g;
            nold := vdpnumber(f);
            new :=  groebnormalform(f,facts,'list);
            if vdpzero!? new then
               << if !*trgroebs then <<prin2 "vanishes ";
                                       prin2 vdpnumber f
                                     >>;
               >>
            else
            if vevzero!? vdpevlmon new then
               << if !*trgroebs then <<prin2 "ONEPOL ";
                                       prin2 vdpnumber f
                                     >>;
                 g := nil;
                 gnew := list vdpone!*;
               >>
            else
            <<
              if new neq f then
               <<new := vdpenumerate vdpsimpcont new;
                 nnew := vdpnumber new;
                 numbers := (nold . nnew) . numbers;
                 if !*trgroebs then <<prin2 "replacing ";
                                      prin2 vdpnumber f;
                                      prin2 " by ";
                                      prin2t vdpnumber new
                                      >>;
               >>;
              gnew := new . gnew;
            >>;
          >>;
    secondvalue!* := numbers;
    return gnew;
    end;

 % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  support for Reduction by "simple" polynomials

symbolic procedure groebnormalform1(f,p);
    % short version; reduce f by p
    % special case: p is a nomomial
     if vdplength p = 1 then vdpcancelmvev(f,vdpevlmon p)
            else groebnormalform(f,list p,nil);

symbolic procedure groebprofitsfromvev(p,vev);
    % tests, if at least one monomial from p would be reduced by vev
    if vdpzero!? p then nil
        else
    if vevdivides!?(vev, vdpevlmon p) then t
        else
            groebprofitsfromvev(vdpred p,vev);


% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special reduction procedures



symbolic procedure groebreduceonestepint(f,f1,c,vev,g1);
      % reduction step for integer case:
      % calculate f= a*f - b*g a,b such that leading term vanishes
      %                        (vev of lvbc g divides vev of lvbc f)
      %
      % and  calculate f1 = a*f1
      % return value=f, secondvalue=f1
 begin scalar vevlcm,a,b,cg,x,rg1;
            % trivial case: g1 single monomial
      if vdpzero!? (rg1:= vdpred g1)
          then return <<f := vdpred f; secondvalue!* := f1; f>>;
      vevlcm := vevdif(vev,vdpevlmon g1);
      cg := vdplbc g1;
            % calculate coefficient factors
      x := if not !*groebdivide then vbcfi 1 else vbcgcd(c,cg);
      a := vbcquot(cg,x);
      b := vbcquot(c,x);
            % multiply relvevant parts from f and f1 by a (vbc)
      if f1 and not vdpzero!? f1 then f1 := vdpvbcprod(f1,a);
      if !*groebprot then groebreductionprotocol(a,vbcneg b,vevlcm,g1);
      f:= vdpilcomb1 (vdpred f, a, vevzero(),
                     rg1,vbcneg b, vevlcm);
            % return with f and f1
      secondvalue!*:= f1;
      thirdvalue!* := a;
      return f;
 end;


symbolic procedure groebreduceonesteprat(f,dummy,c,vev,g1);
      % reduction step for rational case:
      % calculate f= f - g/vdpLbc(f)
      %
 begin scalar x,rg1,vevlcm;
            % trivial case: g1 single monomial
      if vdpzero!? (rg1 := vdpred g1) then return vdpred f ;
            % calculate coefficient factors
      x := vbcneg vbcquot(c,vdplbc g1);
      vevlcm := vevdif(vev,vdpevlmon g1);
      if !*groebprot then
         groebreductionprotocol(a2vbc 1,x,vevlcm,g1);
      return vdpilcomb1(vdpred f,a2vbc 1,vevzero(),
                            rg1,x,vevlcm);
 end;


symbolic procedure groebreductionprotocol(a,b,vevlcm,g1);
    if !*groebprot then
        groebprotfile :=
        if not vbcone!? a then
         append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                         list('times,'candidate,vbc2a a)),
                   list('equal,
                        'candidate,
                        list('plus,
                             'candidate,
                             list('times,
                                  vdp2a vdpfmon(b,vevlcm),
                                  mkid('poly,vdpnumber g1) )))
               )    )
        else
        append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                        list('plus,
                             'candidate,
                             list('times,
                                  vdp2a vdpfmon(b,vevlcm),
                                  mkid('poly,vdpnumber g1) )))

               )    ) ;

symbolic procedure groebreductionprotocol2 a;
      if !*groebprot then
        groebprotfile :=
        if not a=1 then
         append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                         list('times,'candidate,a))));

symbolic procedure groebreductionprotocolborder();
        append(groebprotfile,'!+!+!+!+!+!+!+!+!+!+!+!+!+!+!+!+ . nil);



symbolic procedure groebprotsetq(a,b);
    groebprotfile :=
      append (groebprotfile,
              list (list ('equal,a,b)));

symbolic procedure groebprotval a;
    groebprotfile :=
      append (groebprotfile,
              list (list ('equal,'intermediateresult,a)));



symbolic procedure subset!?(s1,s2);
    % tests if s1 is a subset of s2
       if null s1 then t
          else
       if member(car s1,s2) then subset!?(cdr s1,s2)
          else
            nil;

symbolic procedure vevsplit (vev);
      % split vev such that each exponent vector has only one 1
      begin scalar n,vp,e;
        n := 0;
        for each x in vev do
            <<n := n+1;
              if x neq 0 then
                <<e := append (vdpevlmon vdpone!*,nil);
                  rplaca(pnth(e,n),1);
                  vp := e . vp;
                >>;
            >>;
        return vp;
     end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   calculation of an S-polynomial
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%general strategy:
%
%  groebSpolynom4 calculates the traditional s-Polynomial from p1,p2
%    (linear combination such that the highest term vanishes).
%  groebSpolynom2 subtracts multiples of p2 from the s-polynomial such
%    that head terms are eliminated early.

symbolic procedure groebspolynom (p1,p2);
     groebspolynom2(p1,p2);


symbolic procedure groebspolynom2 (p1,p2);
     if vdpzero!? p1 then p2 else if vdpzero!? p2 then p1 else
   begin scalar s,tp1,tp2,ts,cand;
     s := groebspolynom3(p1,p2);
     if vdpzero!? s or vdpone!? s or !*groebprot then return s;
     tp1 := vdpevlmon p1; tp2 := vdpevlmon p2;
     while not vdpzero!? s
           and ((vevdivides!?(tp2,(ts := vdpevlmon s)) and (cand := p2))
                       or
               (vevdivides!?(tp1,(ts := vdpevlmon s)) and (cand := p1)))
                       do
           << if !*vdpinteger then
                    s := % vdpsimpcont 
                          groebreduceonestepint(s,nil,vdplbc s,ts,cand)
                       else
                          % rational, float and modular case
                        s := groebreduceonesteprat
                                  (s,nil,vdplbc s,ts,cand);
           >>;
     return s;
   end;

symbolic procedure groebspolynom3(p,q);
   begin scalar r,c,g;
     r:=groebspolynom4(p,q);
     groebsavelterm r;
     return r;
   end;

symbolic procedure groebspolynom4 (p1,p2);
  begin scalar ep1,ep2,ep,rp1,rp2,db1,db2,x,r;
    ep1 := vdpevlmon p1; ep2 := vdpevlmon p2;
    ep := vevlcm(ep1, ep2);
    rp1 := vdpred p1; rp2 := vdpred p2;
    gsetsugar(rp1,gsugar p1); gsetsugar(rp2,gsugar p2);
    r:=     ( if vdpzero!? rp1 and vdpzero!? rp2 then rp1
              else ( if vdpzero!? rp1 then
                      <<db2:=a2vbc 0;
                        vdpprod(rp2,
                                vdpfmon(db1:=a2vbc 1,
                                       vevdif(ep, ep2) ) )
                      >>
                     else if vdpzero!? rp2 then
                      <<db1:=a2vbc 0;
                        vdpprod(rp1,
                                vdpfmon(db2:=a2vbc 1,
                                        vevdif(ep, ep1) ) )
                      >>
                          else
                             <<db1 := vdplbc p1;
                               db2 := vdplbc p2;
                               if !*vdpinteger then
                                  << x:= vbcgcd (db1,db2);
                                     if not vbcone!? x then
                                     << db1 := vbcquot (db1,x);
                                        db2 := vbcquot (db2,x);
                                  >> >>;
                                vdpilcomb1 (rp2,db1,vevdif(ep,ep2),
                                          rp1,vbcneg db2,vevdif(ep,ep1))
                             >>
                   )
            );
     if !*groebprot then
        groebprotsetq('candidate,
         {'difference,
           {'times,vdp2a vdpfmon(db2,vevdif(ep,ep2)),
                   mkid('poly,vdpnumber p1)},
           {'times,vdp2a vdpfmon(db1,vevdif(ep,ep1)),
                      mkid('poly,vdpnumber p2)}} );

     return r;
end;

symbolic procedure groebsavelterm r;
     if !*groelterms and not vdpzero!? r then
     <<r:=vbc2a vdplbc r;
       if not numberp r then
         for each p in cdr fctrf numr simp r do
         <<p:=prepf car p;
           if not member(p,glterms) then nconc(glterms,list p);
      >> >>;

symbolic procedure sfcont f;
   % Calculate the integer content of standard form f.
      if domainp f then f else
      gcdf(sfcont lc f, sfcont red f);

symbolic procedure vdplmon u; vdpfmon (vdplbc u,vdplbc u);

symbolic procedure vdpmember3(p,g1,g2,g3);
     % test membership of p in one of then lists g1,g2,g3
       vdpmember(p,g1) or vdpmember(p,g2) or vdpmember(p,g3);

endmodule;


module groebcri;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  criteria for the Buchberger algorithm
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(bcount!* b4count!* mcount!* fcount!*);


smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);

smacro procedure atleast2elementsin (u);
    % test if u has at least a cadr element
    u and cdr u;

symbolic procedure groebbuchcrit4(p1,p2,e);
% Buchberger criterion 4. p1 and p2 are distributive
% polynomials. e is the least common multiple of
% the leading exponent vectors of the distributive
% polynomials p1 and p2. groebBuchcrit4(p1,p2,e) returns a
% boolean expression. True if the reduction of the
% distributive polynomials p1 and p2 is necessary
% else false.
% orig:
%     e neq vevsum( vdpevlmon p1, vdpevlmon p2);
     groebbuchcrit4t(vdpevlmon p1,vdpevlmon p2);

symbolic procedure groebbuchcrit4t(e1,e2);
% nonconstructive test of lcm(e1,e2) = e1 + e2
% equivalent: no matches of nonzero elements.
  if null e1 or null e2 then nil
     else
  if (car e1 neq 0) and (car e2 neq 0) then t
     else groebbuchcrit4t(cdr e1,cdr e2);

symbolic procedure groebinvokecritbuch4 (p,d2);
% Buchberger's criterion 4 is tested on the pair p and the list
% D2 of critical pairs is updated with respect to that crit.
% Result is the updated D2;
    begin scalar p1,p2,vev1,vev2,f1,f2,fd,b4;
          p1 := cadr p;
          p2 := caddr p;
          vev1 := vdpevlmon p1;
          vev2 := vdpevlmon p2;
          f1 := vdpgetprop(p1,'monfac);
          f2 := vdpgetprop(p2,'monfac);
                   % discard known common factors first
          if f1 and f2 then
             <<fd := vevmin (f1,f2);
               b4 := groebbuchcrit4t(vevdif(vev1,fd),vevdif(vev2,fd));
               if b4 and    % is the body itself a common factor?
                     vevdif(vev1,f1) = vevdif(vev2,f2)
                         % test if the polys reduced by their monom.
                         % factor are equal
                     and groebbuchcrit4compatible(p1,f1,p2,f2)
                       then b4 := nil;
             >>
           else
               b4 := groebbuchcrit4t(vev1,vev2);

          if b4 then
                d2 := append (d2, list p)
          else
                b4count!* := b4count!* + 1;
          return d2;
     end;

symbolic procedure groebbuchcrit4compatible (p1,f1,p2,f2);
% p1,p2 polys, f1,f2 exponent vectors (monomials), which are known to
% be factors of their f;
% tests, if p1/f1 = p2/f2
   if vdpzero!? p1 then vdpzero!? p2
       else
   if vdplbc p1 = vdplbc p2
              and
      groebbuchcrit4compatiblevev(vdpevlmon p1,f1,vdpevlmon p2,f2)
       then groebbuchcrit4compatible (vdpred p1,f1,vdpred p2,f2)
      else
          nil;


symbolic procedure groebbuchcrit4compatiblevev (vev1,f1,vev2,f2);
     if null vev1 then null vev2
          else
     if (if f1 then car vev1 - car f1 else car vev1)
                         =
        (if f2 then car vev2 - car f2 else car vev2)
          then
            groebbuchcrit4compatiblevev (cdr vev1,
                                   if f1 then cdr f1 else nil,
                                   cdr vev2,
                                   if f2 then cdr f2 else nil)
         else
            nil;
symbolic procedure groebinvokecritf d1;
% groebInvokeCritF tests a list D1 of critical pairs. It cancels all
% critical pairs but one in D1 having the same lcm (i.e. car
% component) as car(D1). This only one is chosen, if possible,
% such that it doesn't satisfy groebBuchcrit4.
% Version: moeller upgraded 5.7.87

begin
  scalar tp1,p2,active;
  tp1 := car(car(d1));
  active := atleast2elementsin d1;
  while active do
    << p2 := cadr d1;
       if car(p2) = tp1 then
          << fcount!* := fcount!* +1;
             if not groebbuchcrit4t(cadr p2, caddr p2)
                 then d1 := cdr(d1)
                 else d1 := groedeletip(p2,d1);
             active := atleast2elementsin d1;
          >>
         else active := nil
    >>;
  return d1;
end;

symbolic procedure groebinvokecritm (p1,d1);
% D1 is a list of critical pairs, p1 is a critical pair.
% crit M tests, if the lcm of p1 divides one of the lcm's in D1.
% If so, this object is eliminated.
% Result is the updated D1;
   << for each p3 in d1 do
         if vevdivides!?(car(p1), car(p3)) then
             <<mcount!* := mcount!*+1;
               d1 := groedeletip (p3,d1)>>;       %  Criterion M
      d1>>;



symbolic procedure groebinvokecritb (fj,d);
% D is a list of critical pairs, fj is a polynomial.
% Crit B allows to eliminate a pair from D, if the leading monomial
% of fj divides the lcm of the pair, but the lcm of fj with each of
% the members of the pair is not the lcm of the pair itself
% Result is the updated D;
  << for each p in d do
         if vevdivides!?(vdpevlmon(fj), car(p)) and
            tt(fj,cadr(p)) neq car(p) and % Criterion B
            tt(fj,caddr(p)) neq car(p) then
                     <<bcount!* := bcount!* +1;
                       d:= delete  (p,d)>>;
    d>>;

endmodule;


module groesolv; % Tools for solving systems of polynomials (and poly-
%               % nomial equations) based on Groebner basis techniques.

%   Authors:     H.Melenk (ZIB Berlin)
%                H.M Moeller (Fernunversitaet Hagen)
%                W.Neun (ZIB Berlin)
%
%    Aug 1992:   accepting external solutions for univariate pols.   

% operators:
%        
%      GROESOLVE      does the whole job of solving a nonlinear
%                     set of expressions and / or equations
%
%      GROEPOSTPROC   expects that its car parameter is a
%                     lexical groebner base already


fluid '(groesolvelvevel!* !*groebprereduce);
fluid '(groesoldb!* groesoldmode!* !*groebnumval !*groebcomplex
        !*groebopt !*groebprot !*groesolrecurs
        !*groesolgarbage denominators!* variables!*
        groebroots!*    % a-list for predefined root expressions
        depl!*          % the reduce dependency list
        !*vdpinteger    % coefficient mode
       );

fluid '(!*convert !*ezgcd !*msg dmode!* gmodule);
global '(groebprotfile gvarslast !*trgroesolv glterms);

groesolvelvevel!* := 0;

symbolic procedure subsetp(u,v);
  % t if u is a subset of v.
  null u or car u member v and subsetp(cdr u,v);

symbolic procedure groesolveeval u;
    begin scalar !*ezgcd,gblist,vars,oldtorder,res,!*groebopt,
            y,fail,problems,denominators!*,variables!*,gmodule;
      if null dmode!* then !*ezgcd := t;
      !*groebopt := t; gvarslast :='(list);
      oldtorder := apply1('torder,'(lex));
      groesoldmode!* := get(dmode!*,'dname);
      !*groebcomplex := !*complex;
      groesetdmode(groesoldmode!*,nil);
      problems:={u};
      while problems and not fail do
      <<u:=car problems; problems:=cdr problems;
        gblist := cdr groebnerfeval u;
        !*groebopt := nil;    % 29.8.88
        groesetdmode(groesoldmode!*,t);
        if null variables!* then variables!*:=gvarslast;
        if not(gblist = '((list 1))) then
         for each gb in gblist do
         <<if !*trgroesolv then
             <<writepri("starting from basis",'first);
               writepri(mkquote gb,'last)>>;
           for each r in res do if gb
                % do not compare with the mother problem;
             and not subsetp(car r,car u)
              then
           if groesolvidsubset!?(gb,car r,variables!*) then
              res:=delete(r,res) else
           if groesolvidsubset!?(car r,gb,variables!*) then
              <<gb:=nil;
                if !*trgroesolv then writepri("redundant",'only)
              >>;
           if gb then
           <<y:=groesolve0(gb,variables!*);
             if y neq 'failed then res:=(gb.y).res else fail:=t;
             if !*trgroesolv then
             <<writepri("partial result:",'first);
               writepri(mkquote('list.cdar res),'last)
             >>;
             for each d in denominators!* do
              problems:={append(gb,{d}),variables!*}.problems;
             denominators!*:=nil;
           >>;
          >>;
        >>;
      apply1('torder,{oldtorder});
      if fail then return 'failed;
      problems:=nil;
      for each r in res do problems:=union(cdr r,problems);
      return 'list . groesolve!-redun2 problems
     end;

symbolic procedure groesolve!-redun2 sol;
  % Sol is a list of solutions; remove redundancies, now not
  % by ideal theory but by simple substitution.
 begin scalar u,b;
   for each s in sol do
     if s memq sol then
     <<b:=nil;
       for each r in sol do
         if not r eq s then
           if not b and groesolve!-redun2a(r,s) then b:=r;
       if b then sol:=delete(s,sol);
     >>;
   return sol;
 end;

symbolic procedure groesolve!-redun2a(r,s);
  % redundancy test: if sub(s,r)=> trivial then t because s
  % is a special case of r.
    if smemq('root_of,s) then nil else
  begin scalar q,!*evallhseqp,!*protfg;
    !*evallhseqp:=t; !*protfg:=t;
    q:=errorset({'subeval,mkquote {s,r}},nil,nil);
    if errorp q then <<erfg!*:=nil;return nil>>;
    q:=cdar q;
    while q and 0=reval{'difference,cadar q,caddar q} do q:=cdr q;
    return null q;
  end;

symbolic procedure groesolvidsubset!?(b1,b2,vars);
   % test if ideal(b1) is a subset of ideal(b2)
   % (b2 is a specialization of b1 wrt zeros).
  null b1 or (car b1='list or 0=preduceeval{car b1,b2,vars}) and
      groesolvidsubset!?(cdr b1,b2,vars);

%------------------- driver for the postprocessor ----------------

symbolic procedure groesolve0(a,vars);
  begin scalar r,ids,newvars,newa;
    r:=groepostfastsolve(a,vars);
    if r then return r;
    r:=groepostsolveeval{a,vars};
    if r neq 'failed then return cdr r;
    ids:=cdr gindependent_seteval{a,vars};
    if null ids then goto nullerr;
    ids:=car ids;
    newvars:='list.for each x in cdr vars join
                 if not(x memq ids) then {x};
    newa:=groebnereval{a,newvars};
    denominators!*:=cdr glterms;
    if newa='(list 1) then rerror(groebner,24,
        "recomputation for dim=0 failed");
    r:=groepostfastsolve(newa,newvars);
    if r then return r;
    r:=groepostsolveeval{a,vars};
    if r neq 'failed then return cdr r;
nullerr:
    rerror(groebner,23,
        "Moeller ideal decomposition failed with 0 dim ideal");
    end;

symbolic procedure groepostfastsolve(gb,vars);
   % try to find a fast solution.
  begin scalar u,v,p1,p2,fail,kl,res;
    if !*trgroesolv then prin2t "fast solve attempt";
    groesoldmode!* := get(dmode!*,'dname);
    !*groebnumval := member(groesoldmode!* ,
                  '(rounded complex!-rounded));
    groesetdmode(groesoldmode!*,'nil);
    u:=kl:=for each p in cdr gb collect
         <<p:=numr simp p;
           intersection(vars,kernels p).p>>;
    if u='((nil)) then goto trivial;
    while u and cdr u do
    <<p1:=car u; p2:=cadr u; u:= cdr u;
      car p1:=setdiff(car p1,car p2);
      fail:=fail or null car p1>>;
    if fail then goto exit;
    res:= for each r in groepostfastsolve1(reverse kl,nil,0)
        collect 'list.reverse r;
    goto exit;
  trivial:
    res:= {'list.for each x in cdr vars collect
                {'equal,x,mvar makearbcomplex()}};
  exit:
    groesetdmode(groesoldmode!*,t);
    return res;
   end;

fluid '(f);

symbolic procedure groepostfastsolve1(fl,sub,n);
   if null fl then '(nil) else
   begin scalar u,f,v,sub1;
     n:=n+1;
     f:=car fl; v:=car f;  f:=numr subf(cdr f,sub);
     if null f then return groepostfastsolve1(cdr fl,sub,n);
     % v:=car sort(v,function(lambda(x,y);degr(f,x)>degr(f,y)));
     v := car v;
     (f:=reorder f) where kord!*={v};
     if not domainp lc f then groepostcollectden reorder lc f;
     u:=groesolvepolyv(prepf f,v);
     return for each s in u join
     <<sub1:=if smemq('root_of,s) then sub else
         (v . caddar s) . sub;
       for each q in groepostfastsolve1(cdr fl,sub1,n) collect
         car s.q
     >>;
   end;

unfluid '(f);

symbolic procedure groepostcollectden d;
  % d is a non trivial denominator (standard form); 
  % collect its factors.
 for each p in cdr fctrf d do
  if not member(p:=prepf car p,denominators!*) then
      denominators!*:=p.denominators!*;

put('groesolve,'psopfn,'groesolveeval);

symbolic procedure groepostsolveeval u;
    begin scalar a,b,vars,oldorder;
          scalar groesoldb!*;
          scalar !*groebprereduce,!*groebopt,!*groesolgarbage;
         integer lvevel;
        groesoldmode!* := get(dmode!*,'dname);
        groesetdmode(groesoldmode!*,'nil);
        !*groebnumval := member(groesoldmode!* ,
                          '(rounded complex!-rounded));
        if vdpsortmode!* = 'lex then t else
          rerror(groebner,8,
                 "Groepostproc, illegal torder; (only LEX allowed)");
        a := groerevlist reval car u;
        vars := cdr u and groerevlist cadr u or groebnervars(a,nil);
        oldorder := setkorder vars;
        b :=  groesolve1(a,a,vars);
        a := nil;
        if b eq 'failed then a:=b else
        <<for each sol in b do % delete multiplicities
            if not member(sol,a) then a := sol . a;
          a := 'list . for each sol in a collect 'list . sol;
        >>;
        setkorder oldorder;
        groesetdmode(groesoldmode!*,t);
        return a;
    end;

put('groepostproc ,'psopfn,'groepostsolveeval);


% DATA structure:
%
%  all polynomials are held in prefix form (expressions)
%  transformation to standard quotients/ standard forms is done locally
%  only; distributive form is not used here.
%
%  a zero is a set of equations, if possible with a variable on the
%  lhs each
%       e.g. {y=17,z=b+8};
%        internally: ((equal y 17)(equal z (plus b 8)))
%  a zeroset is a list of zeros
%       elgl {{y=17,z=b+8},{y=17,z=b-8}}
%  internally the sets (lists) are kept untagged as lists; the
%  tag 'list is only added to the results and to those lists which
%  are parameters to algebraic operators not in this package.

symbolic procedure groesolve1 (a,fulla,vars);
 %  A        lex Groebner basis or tail of lex Groebner basis
 %  fullA    the complete lex Groebner basis to A
 %  vars     the list of variables
  if null a or a='(1) then nil else
  <<begin scalar f1,a1,res,q,gi,ng1,ng2,ngq,qg,mv,test;
      res := assoc (a,groesoldb!*); if res then return cdr res;
      groesolvelvevel!* := groesolvelvevel!* + 1;
      %%tr prin2t  "=================================================";
      %%tr prin2l list( " groesolvelvevel!*: ",groesolvelvevel!*);
      %%tr           prin2t " Problem:"; 
      %%tr                   writepri (mkquote ('list . a),'only);;
      if member(a,!*groesolrecurs) then return 'failed;
%        <<vars := append(cdr vars,{car vars});
%          if member(vars,!*groesolrecurs) then
%          <<!*groesolgarbage := T;
%            return list for each p in A collect list('EQUAL,p,0) >>;
%          !*groesolrecurs := vars . !*groesolrecurs;
%          A := cdr Groebnereval{'list.A,'list . vars};
%        >>;
      !*groesolrecurs := a . !*groesolrecurs;
      if length a = 1 then
       << %%tr print  "single polynomial; solve it";
          res := groesolvepoly car a; goto ready>>;
         % step 1
      f1 := car a;
      a1 := cdr a;
      test := nil;
      mv := intersection(vars,ltermvariables f1);    % test Buchcrit 4
      for each p in a1 do
         if intersection (mv,ltermvariables p) then test := t;
      if not test then
      << %%tr print "f1 has unique main variable";
         ngq := groesolve1(a1,a1,vars);
         if ngq eq 'failed then <<res:='failed;goto ready>>;
         res := zerosetintersection(ngq,f1,vars);
         goto ready>>;
%     Q := cdr GroebIdq('list . A1,f1,'list . vars);    % A1:f1
      q := groesolvidq(a1,f1,vars);
        %%tr print "A1:f1"; %%tr writepri (mkquote ('list . Q),'only);;
      if q='(1) then     % f1 already member of A1; skip it
        <<%%tr print "f1 already in A1; ignore";
          res:= groesolve1(a1,fulla,vars);
          goto ready>>;
      ngq := groesolve1(q,q,vars);
      if ngq eq 'failed then <<res:='failed;goto ready>>;
      ng1 := zerosetintersection (ngq,f1,vars);
         % step 4
      if groesolvidqtest(a1,f1,vars) then
      << while q do
         << gi := car q; q := cdr q;
            gi := preduceeval list (gi , 'list . a, 'list . vars);
            if gi = 0 then q:= nil else
               a := cdr groebidq('list . a ,gi,'list . vars);
         >>;
         ng2 := groesolve1(a,a,vars);
         if ng2 eq 'failed then <<res:='failed;goto ready>>;
      >> else
      <<ng2 := ();
         if length q = 1 then
         << gi := preduceeval list (car q, 'list . fulla, 'list . vars);
           if gi neq 0 then
           << qg := cdr groebidq('list . fulla,gi,'list . vars); % A1:gi
              ng2 := groesolve1(qg,qg,vars);
              if ng2 eq 'failed then <<res:='failed;goto ready>>;
         >> >>
         else
            <<ng2 := groesolve2(a1,q,vars);
              if ng2 eq 'failed then <<res:='failed;goto ready>>
            >>
      >>;
      res:= zerosetunion (ng1,ng2);
    ready:
      %%tr print list( "Result, level!*: ",groesolvelvevel!*);
      %%tr writeres res;
      %%tr print "...................................................";
      groesolvelvevel!* := groesolvelvevel!* -1;
      groesoldb!* := (a . res) . groesoldb!*;
      return res;
   end
   >> where !*groesolrecurs = !*groesolrecurs; % recursive fluid!

symbolic procedure groesolvidqtest(a1,f1,vars);
      not(deg(f1,car vars) eq deg(car a1,car vars));

symbolic procedure groesolvidq(a1,f1,vars);
      begin scalar x,temp;
         x := car  vars;
         if not groesolvidqtest(a1,f1,vars)
             then return cdr groebidq('list . a1,f1,'list . vars);
         temp :=
           for each p in a1 collect
             reval car reverse coeffeval list(p,x);
         return cdr groebnereval list ('list . temp,'list . vars);
       end;

symbolic procedure groesolve2(a,q,vars);
  % Calculation of the zeroset A1:(g1,g2,,,,gs), 
  % the gi given as members of Q.
     groesolvetree (a,q,q,vars);

symbolic procedure groesolvetree(a,t1,phi,vars);
   begin scalar q,ngtemp,ngall,t2,h,g,a2,phi2;
      %%tr prin2t ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
      %%tr prin2t "groesolvetree; A:";
      %%tr writepri(mkquote ('list . a),'only);
      %%tr writepri( "T1 :",'car); 
      %%tr writepri(mkquote ('list . T1) ,'last); 
      %%tr writepri( "phi:",'car);
      %%tr writepri(mkquote ('list .  phi),'last);
       if null phi then return nil else
       if null t1 then
          <<q := cdr groebidq('list.a, 'times.phi,'list.vars);
            %%tr prin2t "<< << << << << << << << << << << << << <<<";
            return if car q = 1 then nil
                                else groesolve1(q,q,vars) >>;
       for each g in t1 do
       <<h:=preduceeval list(g,'list.a,'list.vars);
         phi := delete(g,phi);
         if not(h=0) then <<t2:=h.t2; phi:=h.phi>>;
       >>;
       if null phi then return nil;  % 29.8.88
       t1 := t2;
       q := cdr groebidq('list.a, 'times.phi,'list.vars);
        %%tr writepri( "PHI :",'car); 
        %%tr writepri(mkquote ('TIMES.phi) ,'last); 
        %%tr writepri( "A:PHI :",'car);
        %%tr  writepri(mkquote ('LIST.Q) ,'last);
       if not(car q = 1) then
       << ngall := groesolve1(q,q,vars);
          if ngall eq 'failed then return 'failed;
       >>;
       if !*groesolgarbage then
               return groesolverestruct(q,phi,vars,ngall);
        while t1 do
          <<g:=car t1; t1:=cdr t1;
            phi2 := delete(g,phi);
            if phi2 then
            <<a2 := cdr groebnereval list('list . g . a,'list . vars);
              if not(car a2 =1) then
               <<ngtemp := groesolvetree(a2,t1,phi2,vars);
                 ngall := zerosetunion(ngtemp,ngall)>>;
           >>>>;
       %%tr prin2t "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
       return ngall;
   end;

symbolic procedure groesolverestruct(a,phi,vars,ngall);
     % there was a problem with an embedded solution in phi such that
     % A:phi = A
     % we try a heuristic by making one variable a formal parameter
    begin scalar newa,newvars,mv,oldorder,solu;
        mv := ltermvariables ('times.phi);
        mv := car mv;
         %%tr prin2 "groesolverestruct:taking variable ";prin2t mv;
        newvars := delete(mv,vars);
        oldorder := setkorder newvars;
        newa := cdr groebnereval list('list . a,'list . newvars);
         %%tr    prin2t "new Groebner basis:";
         %%tr    writepri(mkquote ('LIST . newA),'ONLY);
        !*groesolgarbage := nil;
        solu := groesolve1(newa,newa,newvars);
         %%tr if !*groesolgarbage then prin2t "Heuristics failed"
         %%tr                     else prin2t "better result";
        setkorder oldorder;
        return if !*groesolgarbage then ngall else solu;
    end;



%%tr symbolic procedure writeres r;
%%tr writepri (mkquote ('list.for each x in r collect 'list.x),'ONLY);

symbolic procedure ltermvariables u;
  % extract variables of leading term in u
    begin scalar v;
      u := numr simp u;
      while not domainp u do
      <<v := mvar u . v;
        u := lc u>>;
      return reversip v;
    end;

symbolic procedure zerosetintersection (ng,poly,vars);
     % NG is a zeroset
     % poly is a polynomial
     % the routine maps the zeros in NG by the polynomial:
     %   each zero is substituted into the polynomial; 
     %   that gives a univariate 
     %   solved by SOLVE or numerical techniques.
     % the result is the solution NG, including the solutions of the
     % polynomial.
   begin scalar res,ns,testpoly,ppoly,sol,s,var,dom;
      %%tr print "Intersection ";
      %%tr writepri (mkquote ('list . NG),'only); 
      %%tr         print " with ";
       %%tr writepri(mkquote poly,'only);
      res := ();
      poly := simp poly;
      var:=if not domainp numr poly then groesolmvar(numr poly,vars)
             else 'constant;
    loop:
      if ng=() then goto finish;
      ns := car ng; ng := cdr ng;
      testpoly := poly;
      dom := groesoldmode!* or 'rational;
      groesetdmode(dom,t);
      testpoly := simp prepsq testpoly;
      for each u in ns do
       if idp lhs u and not smemq('root_of,rhs u) then
       <<s := rhs u;
         testpoly := subsq(testpoly,list (lhs u . s));
       >>;
      groesetdmode(dom,nil);
      ppoly := prepf numr testpoly;
      sol := groesolvepolyv(ppoly,var);
      res := append(res , for each r in sol collect append(r,ns) ) ;
      goto loop;
    finish:
      %%tr print  "Schnittresultat: ";
      %%tr writeres res;
      return res;
   end;

symbolic procedure groesolmvar(poly,vars);
  % select main variable wrt vars sequence.
   <<while vars and not smember(car vars,poly) do
      vars:=cdr vars;
     if null vars then rerror('groebner,27,"illegal poly");
     car vars>>;


% solving a single polynomial with respect to its main variable

symbolic procedure groesolvepoly p; groesolvepolyv(p,mainvar p);

symbolic procedure groesolvepolyv(p,var);
   % find the zeros for one polynomial p in the
   % variable "var".
   % current dmode is NIL.
  begin scalar res,u,!*convert,y,z,depl!*;
      if !*trgroesolv then
      <<writepri("   solving univariate with respect to ",'first);
        writepri(mkquote var,'last);
        writepri(mkquote p,'only);
      >>;
      for each s in groebroots!* do
       if 0=reval{'difference,p,car s} then res:=cdr s;
      if res then return res;
      groesetdmode(groesoldmode!*,t);
      u := numr simp p;
      res := if !*groebnumval and univariatepolynomial!? u
               then groeroots(p,var)
              else (solveeval list (p,var))
                where kord!*=nil,
                alglist!* = nil . nil;
      res := cdr res;
       % Collect nontrivial denominator factors.
       % Reorder for different local order during solveeval.
      for each x in res do
      <<y:=prepf (z:=reorder denr simp caddr x);
        if dependsl(y,variables!*) then groepostcollectden z;
      >>;
      res := for each x in res collect list x;
      groesetdmode(groesoldmode!*,nil);
      return res;
  end;

symbolic procedure univariatepolynomial!? fm;
      domainp fm or univariatepolynomial!?1 (fm,mvar fm);

symbolic procedure univariatepolynomial!?1 (fm,v);
       domainp fm or
         domainp lc fm and v = mvar fm and
                           univariatepolynomial!?1(red fm,v);

symbolic procedure predecessor (r,l);
  % looks for the  predecessor of r in l
   if not pairp l or not pairp cdr l or r = car l
          then rerror(groebner,9,"No predecessor available") else
   if r = cadr l then car l else predecessor (r,cdr l);

symbolic procedure zerosetunion(ng1,ng2);
     <<%print list( "union von ",ng1,ng2;
       ng1 := zerosetunion1(ng1,ng2);
     % print list( "-->",ng1);
       ng1>>;

symbolic procedure zerosetunion1(ng1,ng2);
    % Vereinigung von Nullstellengebilden
      if ng1 = () then ng2
            else
      if zerosetmember(car ng1,ng2) then zerosetunion1(cdr ng1,ng2)
            else
      car ng1 . zerosetunion1(cdr ng1,ng2);

symbolic procedure zerosetmember (ns,ng);
      if ng = () then nil else
      if zeroequal(ns,car ng) then ng else
         zerosetmember (ns,cdr ng);

symbolic procedure zeroequal(ns1,ns2);
      if zerosubset(ns1,ns2) then zerosubset(ns2,ns1) else nil;

symbolic procedure zerosubset(ns1,ns2);
      if null ns1 then t else
      if member(car ns1,ns2) then zerosubset(cdr ns1,ns2)
         else nil;

symbolic procedure groesetdmode(dmode,dir);
  % Interface for switching an arbitrary domain on/off.
  % Preserve complex mode. Turn on EZGCD whenever possible.
   if null dmode then nil else
   begin scalar !*msg,x,y;
   if null dir then
   << if !*complex then y:=setdmode('complex,nil);
      !*complex := nil;
      if dmode!* = '!:rd!: then !*rounded :=nil;
      if dmode!* then y:=setdmode(get(dmode!*,'dname),nil);
      if !*groebcomplex then
      <<setdmode('complex,t); !*complex:=t>>;
   >>
   else
   << if memq(dmode,'(complex complex!-rounded complex!-rational))
        then <<!*complex := t; y:=setdmode('complex,t);
                 if (x:=atsoc(dmode,'((complex!-rounded . rounded)
                           (complex!-rational . rational)) ))
                 then y:=setdmode(cdr x,t)>>
           else y:=setdmode(dmode,t);
      if memq(dmode,'(rounded complex!-rounded)) then !*rounded :=t;
    >>;
    !*ezgcd := null dmode!*;
    return y;
  end;

symbolic procedure preduceeval pars;
%  Polynomial reduction driver. u is an expression and v a list of
% expressions. Preduce calculates the polynomial u reduced wrt the list
% of expressions v.
% parameters:
%     1      expression to be reduced
%     2      polynomials or equations; base for reduction
%     3      optional: list of variables
   begin scalar vars,x,u,v,w,oldorder;
         scalar !*factor,!*exp,!*gsugar,!*vdpinteger;
         integer n,pcount!*; !*exp := t;
      if !*groebprot then groebprotfile := list 'list;
      n := length pars;
      x := reval car pars;
      u := reval cadr pars;
      v := if n>2 then reval caddr pars else nil;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,3,"Empty list in Preduce");
      vars :=
           if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then vdperr 'preduce;
      oldorder := vdpinit vars;
      w := for each j in w collect a2vdp j;
      x := a2vdp x;
      if !*groebprot then
          <<w := for each j in w collect vdpenumerate j;
            groebprotsetq('candidate,vdp2a x);
            for each j in w do groebprotsetq(mkid('poly,vdpnumber j),
                                             vdp2a j)>>;
      w := groebnormalform(x,w, 'sort);
      w := vdp2a w;

      setkorder oldorder;
      return if w then w else 0;
   end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% the following code is the interface to Stan's rootfinder
% 


symbolic procedure groeroots(p,x);
   begin scalar r;
      r := reval{'roots,p};
         % re-evaluate rhs in order to get prefix form
      r := for each e in cdr r collect
            list('equal,cadr e,reval caddr e);
      return 'list . r;
   end;

endmodule;


module groebopt;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   optimization of the sequence of variables
%

% Optimization of variable sequence; 
% the theoretical background can be found
% in  Boege/Gebauer/Kredel , J.Symb.Comp(1986)I,83-98
% Techniques modfied to the following algorithm
%
% x > y if
%  x appears in a higher power than y
%       or
%  the highest powers are equal, but x appears more often with 
% that power.
%
% An explicit dependency DEPENDS X,Y will supersede the optimality.

fluid '(vdpvars!*     % list of intersting variables (and korder)
        intvdpvars!*
        !*trgroeb     % control of print messages
       );

symbolic procedure vdpvordopt (w,vars);
  % w : list of polynomials (standard forms)
  % vars: list of variables
  % returns (w . vars), both reorderdered
  begin; scalar c;
        vars := sort(vars,'ordop);
        c := for each x in vars collect x . 0 . 0;
        for each poly in w do vdpvordopt1 (poly,vars,c);
        c := sort(c,function vdpvordopt2);
        intvdpvars!* := for each v in c collect car v;
        vars := sort(intvdpvars!*,function vdpvordopt3);
        setkorder vars;
        if !*trgroeb then
        <<prin2 "optimized sequence of kernels: "; prin2t vars>>;
        return (for each poly in w collect reorder poly) . vars;
  end;


symbolic procedure vdpvordopt1 (p,vl,c);
   if null p then 0
      else
   if domainp p or null vl then 1
      else
   if mvar p neq car vl then vdpvordopt1(p,cdr vl,c)
      else
   begin scalar var,pow,slot; integer n;
      n := vdpvordopt1 (lc p,cdr vl,c);
      var := mvar p;
      pow := ldeg p;
      slot := assoc(var,c);
      if pow #> cadr slot then
          <<rplaca(cdr slot,pow); rplacd(cdr slot,n)>>
        else
          rplacd(cdr slot,n #+ cddr slot);
      return n #+ vdpvordopt1 (red p,vl,c);
   end;

symbolic procedure vdpvordopt2(sl1,sl2);
  % compare two slots from the power table
    <<sl1 := cdr sl1;
      sl2 := cdr sl2;
      car sl1 #< car sl2 or car sl1 = car sl2 and cdr sl1 #< cdr sl2
    >>;

symbolic procedure vdpvordopt3(x,y);
  % two level compare: 1. dependency, 2. optimal order.
     depends(x,y) or member(y,member(x,intvdpvars!*));

endmodule;


module groebsea;

% support of search for reduction polynomials

fluid '(thirdvalue!* fourthvalue!* hcount!* !*groebweak);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  search for reduction candidates in a list

symbolic procedure groebsearchinlist (vev,g);
  % search for a polynomial in the list G, such that the lcm divides
  % vev; G is expected to be sorted in descending sequence
    if null g then nil
    else if vevdivides!?(vdpevlmon car g, vev) then car g
    else groebsearchinlist (vev,cdr g);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  search tree for polynomials
%  simple variant: mapped to search list
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure groebstreeadd (poly,stru);
% add one polynomial to the tree
% if this is a simple polynomial (mono or bino), reform
% the tree
   if hcount!* #< 5000 then vdplsortin(poly,stru)
     else vdplsortinreplacing(poly,stru);

symbolic procedure groebsearchinstree (vev,stru);
% search a polynomial corresponding to the exponent vector vev
     groebsearchinlist (vev,stru);

symbolic procedure groebstreeextract stru;
% gives a linear list of all polynomials in the tree
                 stru;

symbolic procedure groebstreereconstruct u;
% reconstructs a tree from a linear list of polynomials
               vdplsort u;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% reforming G, D and G99 when a very simple polynomial was
% found (e.g. a monomial, a binomial)

symbolic procedure groebsecondaryreduction(poly,g,g99,d,gc,mode);
    % if poly is a simple polynomial, the polynomials in G and G99
    % are reduced in a second pass. Result is G, secondvalue is G99.
    % mode says, that G99 has to be modified in place.
  begin scalar vev,p,pl,x,rep,first,rpoly,break;   % y;
    secondvalue!* := g99; thirdvalue!* := d; fourthvalue!* := gc;
    vev := vdpevlmon poly; rpoly := vdpred poly;
        % cancel redundant elements in G99
    for each p in g99 do if vevdivides!?(vev,vdpevlmon p)
                  then g99:=delete(p,g99);
    if vdplength poly > 2 or  vevzero!? vev then return g;
    if !*groebweak and not vdpzero!? rpoly
       and (groebweaktestbranch!=1(poly,g,d)) then return 'abort;
        !*trgroeb and groebmess50 g;
    pl := union(g,g99);
    first := t;

    while pl and not break do
      << p:= car pl; pl := cdr pl;
         if groebprofitsfromvev(p,vev) then
                          % replace by simplified version
            <<x := groebnormalform1(p,poly);
              x := groebsimpcontnormalform x;
              x := vdpenumerate x;
                 if first then !*trgroeb and groebmess20(poly);
                      first := nil;
                      !*trgroeb and groebmess21(p,x);
                  rep := (p . x) . rep;
              if not vdpzero!? x and
                 vevzero!? vdpevlmon x then break := t; % 1 found 
             >> >>;

    if break then return 'abort;

                           % reform G99
    g99 := for each p in g99 collect groebsecondaryreplace(p,rep);
    secondvalue!* :=  groebsecondaryremovemultiples g99;
                           % reform D
 %  thirdvalue!* := nil;
 %  for each p in D do
 %  <<x := groebSecondaryReplace(cadr p,rep);
 %    y := groebSecondaryReplace(caddr p,rep);
 %    thirdvalue!*:=groebcplistSortIn(groebmakepair(x,y),thirdvalue!*);
 %  >>;
    thirdvalue!* := d;
                          % reform Gc
    fourthvalue!* :=
      groebsecondaryremovemultiples
        for each y in gc collect groebsecondaryreplace(y,rep);

    g:=for each y in g collect groebsecondaryreplace(y,rep);
         !*trgroeb and groebmess50 g;
      % print('groebSecondaryReduction .
      %          for each p in g collect vdpnumber p);
    return groebsecondaryremovemultiples g;
  end;

symbolic procedure groebsecondaryremovemultiples g;
    if null g then nil else
    if vdpzero!? car g or member(car g,cdr g) then
                groebsecondaryremovemultiples cdr g else
    car g  . groebsecondaryremovemultiples cdr g;

symbolic procedure groebsecondaryreplace(x,rep);
   (if y then cdr y else x) where y = atsoc(x,rep);

endmodule;


module groebsor;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  maintenance of lists of critical pairs (sorting etc.)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure groebcplistsortin (p,pl);
% Distributive polynomial critical pair list sort. pl is a
% special list for Groebner calculation, p is a pair.
% returns the updated list pl (p sorted into);
% if null pl then list p
%   else
% if vevcompless!? (car car pl, car p)
%     then car pl  . groebcplistsortin (p, cdr pl)
%   else
%      p . pl;
%  non copying version:
  if null pl then list p
    else
  <<groebcplistsortin1 (p,pl); pl>>;

symbolic procedure groebcplistsortin1(p,pl);
% destructive insert of p into nonnull pl
   if not groebcpcompless!?(car pl, p)
        then <<rplacd(pl,car pl . cdr pl); rplaca(pl,p)>>
      else
   if null cdr pl then rplacd(pl,list p)
      else
        groebcplistsortin1(p,cdr pl);



symbolic procedure groebcplistmerge(pl1,pl2);
% Distributive polynomial critical pair list merge. pl1 and pl2
% are critical pair lists used in the Groebner calculation.
% groebcplistmerge(pl1,pl2) returns the merged list.
begin scalar cpl1,cpl2,sl;
      if null pl1 then return pl2;
      if null pl2 then return pl1;
      cpl1 := car pl1; cpl2 := car pl2;
      sl := groebcpcompless!?(cpl1, cpl2);
      return
           (if sl then cpl1 . groebcplistmerge(cdr pl1,pl2)
                  else cpl2 . groebcplistmerge(pl1,cdr pl2) )
end;

symbolic procedure groebcpcompless!?(p1,p2);
% compare 2 pairs srt their sugar(=cadddr) or their lcm (=car).
    if !*gsugar then
         (if d=0 then vevcompless!?(car p1,car p2) else d<0)
              where d= cadddr p1 - cadddr p2
       else vevcompless!?(car p1,car p2);

endmodule;


module groebspa;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% manipulation of subspaces.
% A subspace among the variables is described by an exponent vector
%  with only zeroes and ones. It terminates with the last
% one. It may be null (nil);

expr procedure vevunion(e1,e2);
    begin scalar x,y;
       y := vevunion1(e1,e2);
       x := reverse y;
       if car x = 1 then return y;
       while x and car x = 0 do x := cdr x;
       return reversip x;
    end;

expr procedure vevunion1(e1,e2);
    if vdpsubspacep(e1,e2) then e2
       else
    if vdpsubspacep(e2,e1) then e1
       else
    if car e1 neq 0 or car e2 neq 0 then 1 . vevunion1(cdr e1,cdr e2)
       else
          0 . vevunion1(cdr e1,cdr e2);

expr procedure vdpsubspacep(e1,e2);
% test if e1 describes a subspace from e2
    if null e1 then t
      else
    if null e2 then vdpspacenullp(e1)
      else
    if car e1 > car e2 then nil
      else
    if e1 = e2 then t
      else
         vdpsubspacep(cdr e1,cdr e2);

expr procedure vdporthspacep(e1,e2);
% test if e1 and e2 describe orthogonal spaces(no intersection);
    if null e1 or null e2 then t
       else
    if car e2 = 0 or car e1 = 0
          then vdporthspacep(cdr e1,cdr e2)
       else nil;


expr procedure vdpspacenullp(e1);
% test if e1 describes an null space
     if null e1 then t
        else
     if car e1 = 0 then vdpspacenullp(cdr e1)
        else nil;


expr procedure vdpspace(p);
  % determine the variables of the polynomial.
    begin scalar x,y;
        if vdpzero!? p then return nil;
        x := vdpgetprop(p,'subroom);
        if x then return x;
        x := vevunion(nil,vdpevlmon p);
        y := vdpred p;
        while not vdpzero!? y do
         <<x := vevunion(x,vdpevlmon y);
           y := vdpred y>>;
        vdpputprop (p,'subroom,x);
        return x;
    end;

symbolic procedure vdpunivariate!?(p);
    if vdpgetprop(p,'univariate) then t
     else begin scalar ev; integer n;
         ev := vdpevlmon p;
         for each x in ev do
           if not(x=0) then n := n#+1;
         if not(n=1) then return nil;
         ev := vdpspace(p);
         for each x in ev do
           if not(x=0) then n := n#+1;
         if not(n=1) then return nil;
         vdpputprop(p,'univariate,t);
         return t;
     end;

endmodule;


module groebfac; % Factorization of polynomials during Groebner calc'n.

% create!-package('(groebfac),'(contrib groebner));

% Other packages needed.

% load!-package 'vdp2dip;

imports groebner,vdp2dip,factor;

fluid '(groebactualg99!* groebactualg!* factortime!* !*vdpmodular
          vdpone!* groebfabort!* !*factor !*groebrm current!-modulus
          !*trgroeb !*gsugar);

symbolic procedure groebfactorize (h,abort1,g,g99);
  begin scalar r,tim,gctim,h1,groebactualg99!*,groebfabort!*,test;
    scalar s;
    s:=!*gsugar and gsugar h;
    groebactualg99!* := g99; groebactualg!* := g;
    groebfabort!* := abort1;
    if vdpgetprop(h,'irreducible) then return groebfactorize3 h;
    tim := time();
    gctim := gctime();
         !*trgroeb and groebmess7 h;
    r := if r := vdpgetprop(h,'factors) then r
     else if !*groebrm then groebfactorize1 h
     else if not !*vdpmodular then groebfactorize2 h
     else nil;
    factortime!* := factortime!* + time() - tim -(gctime()-gctim);
    if null r then <<vdpputprop(h,'irreducible,t);
                     return groebfactorize3 h>>;
               if cdr r then !*trgroeb and groebmess14 (h,r);
    vdpputprop(h,'factors,r);
    for each p in r do
       if vdpmember(car p,g) then test:= car p;
    if test then
       <<!*trgroeb and groebmess27a(h,test); return 'zero>>;
    h1 := car r;
    for each p in r do
       if vdpmember(car p,abort1) then
            <<r := delete(p,r); !*trgroeb and groebmess27 car p >>
       else vdpputprop(car p,'irreducible,t);
    if null r then r := list h1;     % at least one
    if null cdr r then groebfactorize3 caar r;
       % inherit sugar if no substantial factor.
    if !*gsugar then
     if null cdr r then gsetsugar(caar r,s) else
       for each p in r do gsetsugar(car p,vdptdeg car p);
    return 'factor . r;
  end;


symbolic procedure groebfactorize1 h;
  % factorize: separate monomial factors which were detected already;
   begin scalar monf,vp,n,e,h1,h2,vp2;
        monf := vdpgetprop(h,'monfac);
        if null monf then
             return if not !*vdpmodular then groebfactorize2 h
                                       else nil;     % no factor
        h2 := vdpdivmon (h,vbcfi 1,monf);

       if groebmonfac neq 0 then
       <<                                 % now build a polynomial from
        n := 0;                           % each variable in MONFAC
        for each x in monf do
            <<n := n#+1;
              if x neq 0 then
                <<e := list x;
                  for i:=2:n do e := 0 . e; % prefix with n-1 zeros.
                  vp := vdpfmon(a2vbc 1,e) . vp;
                >>;
            >>;
       >>
        else
        !*trgroeb and groebmess15 monf;
                  % append body of orig. poly, factorized
        if not vdpzero!? h2 and
           not vevzero!? vdpevlmon h2 then
               <<if not !*vdpmodular then vp2 := groebfactorize2 h2;
                 vp2 := if not vp2 then list h2
                     else for each v in vp2 collect car v;
                 vp := nconc(vp,vp2)>>;
                   % ascending sorting
    %   if length vp = 1 then return nil;
        h1 := vp;
        return
               reverse  for each x in h1 collect list vdpenumerate x;
   end;

symbolic procedure groebfactorize2 h;
  % tries to factorize a h-polynomial via REDUCE factorizer
   begin scalar h1,h2,!*factor; !*factor := t;
%       h1 := vdp2a vdprectoint (h,vdplcm h);
%       h1 := fctrf !*q2f simp h1;   % factorf
        h1 := groefctrf vdp2f h;
        if null cddr h1      % only one element in factorization list
           and cdr cadr h1 = 1     % and multiplicity = 1
                then return nil;
        h2 := for each l in cdr h1 join
            for i:=1:cdr l collect car l;
        h2 := vdplsort for each p in h2 collect vdpsimpcont f2vdp p;
        return for each x in h2 collect list vdpenumerate x;
   end;

symbolic procedure groefctrf p;
   (fctrf p) where !*factor=t,current!-modulus = current!-modulus;

symbolic procedure groebfactorize3 h;
  % additional efforts to factor something. 
       nil;

endmodule;


module groebidq;

% calculation of ideal quotient using a modified Buchberger algorithm.

%   Authors:   H. Melenk, H.M. Moeller,  W. Neun
%              July 1988

fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*onlyheadtermreduction !*groebstat !*groebdivide !*groebprot
        !*groebidqbasis

        vdpvars!*                  % external names of the variables
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*              % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*            % current domain for base coeffs.
        groetime!*
        !*gsugar

       );


switch groebopt,groebfac,groebrm,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,onlyheadtermreduction,groebprereduce,groebstat,
       gcheckpoint,gcdrart,groebdivide,groebprot,groebidqbasis;
!*groebidqbasis := t;              %default: basis from idq

% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!*
        basecount!* hzerocount!*);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% some macros for local usage only

smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);


symbolic procedure groebidq2 (p,f);
  % setup all global variables for the Buchberger algorithm
  % printing of statistics
 begin scalar groetime!*,tim1,spac,spac1,p1,factortime!*,
       pairsdone!*, factorlvevel!*,!*gsugar;
       factortime!* := 0;
       groetime!* := time();
       vdponepol(); % we construct dynamically
       hcount!* := 0;
       pcount!* := 0;
       mcount!* := 0;
       fcount!* := 0;
       bcount!* := 0;
       b4count!* := 0;
       hzerocount!* := 0;
       basecount!* := 0;
       if !*trgroeb then
       <<
          prin2 "IDQ Calculation starting ";
          terprit 2;
       >>;
       spac := gctime();

       p1:=  groebidq3 (p, f);

       if !*trgroeb or !*trgroebr or !*groebstat then
       <<
          spac1 := gctime() - spac;
          terpri();
          prin2t "statistics for IDQ calculation";
          prin2t "==============================";
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
       return if !*groebidqbasis then car groebner2(p1,nil) else p1;
 end;


symbolic procedure groebidq3 (g0,fff);
   begin scalar result,x,g,d,d1,d2,p,p1,s,h,g99,one,gi;
         gi := g0;
         fff := vdpsimpcont fff;
         vdpputprop(fff,'number,0);         % assign number 0
         vdpputprop(fff,'cofact,a2vdp 1);   % assign cofactor 1
         x := for each fj in g0 collect
           << fj:=vdpenumerate vdpsimpcont fj;
              vdpputprop(fj,'cofact,a2vdp 0);   % assign cofactor 0
              fj>>;
         g0 := list fff;
         for each fj in x do g0 := vdplsortin(fj,g0);

% ITERATION :
      while (d or g0) and not one do
       begin
          if g0 then
          <<          % take next poly from input
               h := car g0;
               g0 := cdr g0;
               p := list(nil,h,h);
          >>
             else
          <<          % take next poly from pairs
               p := car d;
               d := delete (p,d);
               s := idqspolynom (cadr p, caddr p);
                          idqmess3(p,s);
               h := idqsimpcont idqnormalform(s,g99,'tree);
               if vdpzero!? h then
               <<      !*trgroeb and groebmess4(p,d);
                 x := vdpgetprop(h,'cofact);
                 if not vdpzero!? x then
                    if vevzero!? vdpevlmon x then one:= t else
                     << result := idqtoresult(x , result);
                        idqmess0 x>>;
               >>
          >>;
          if vdpzero!? h then goto bott;
          if vevzero!? vdpevlmon h then % base 1 found
                  <<          idqmess5(p,h);
                 result:=gi; d:=g0:=nil;
                 goto bott;>>;
          s:= nil;
                  % h polynomial is accepted now
               h := vdpenumerate h;
                        idqmess5(p,h);
                              % construct new critical pairs
               d1 := nil;
               for each f in g do
                    <<d1 := groebcplistsortin( list(tt(f,h),f,h) , d1);
                      if tt(f,h) = vdpevlmon(f) then
                             <<g := delete (f,g);
                               !*trgroeb and groebmess2 f>>;
                      >>;
                  !*trgroeb and groebmess51(d1);
               d2 := nil;
               while d1 do
                  <<d1 := groebinvokecritf d1;
                    p1 := car d1;
                    d1 := cdr d1;
                    if groebbuchcrit4t(cadr p1,caddr p1)
                       then d2 := append (d2, list p1)
                           else
                    <<x := idqdirectelement(cadr p1,caddr p1);
                      if not vdpzero!? x then
                         if vevzero!? vdpevlmon x then one:= t else
                              <<idqmess1 (x,cadr p1,caddr p1);
                                result := idqtoresult(x,result);
                                >> >>;

                    d1 := groebinvokecritm (p1,d1);
                  >>;
             %   D := groebInvokeCritB (h,D);     
                 d := groebcplistmerge(d,d2);
                 g := h . g;
                 g99 := groebstreeadd(h, g99);
                            !*trgroeb and groebmess8(g,d);
    bott:
   end;      %  ITERATION
                      % now calculate groebner base from quotient base
   if one then result := list vdpfmon(a2vbc 1,vevzero());
        idqmess2 result;
   return result;
end;     % MACROLOOP

symbolic procedure idqtoresult(x,r);
    % x is a new element for the quotient r;
    % is is reduced by r and then added.
      <<x := groebsimpcontnormalform groebnormalform(x,r,'sort);
        if vdpzero!? x then r else vdplsortin(x,r)>>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Reduction of polynomials
%

symbolic procedure idqnormalform(f,g,type);
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
  begin scalar c,vev,divisor,done,fold;
      fold := f;
      while not vdpzero!? f and g do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;
            if type = 'sort then
                 while g
                       and vevcompless!? (vev,vdpevlmon (car g))
                            do g := cdr g;
            divisor :=
               if type = 'tree then groebsearchinstree (vev,g)
                               else groebsearchinlist (vev,g);
            if divisor then done := t;    % true action indicator
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
                      if !*vdpinteger  then
                          f := idqreduceonestepint(f,nil,c,vev,divisor)
                       else
                          f := idqreduceonesteprat(f,nil,c,vev,divisor)
               else
                  g := nil;
          end;
      return if done then f else fold; %in order to preserve history
   end;



% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special reduction procedures



symbolic procedure idqreduceonestepint(f,dummy,c,vev,g1);
      % reduction step for integer case:
      % calculate f= a*f - b*g a,b such that leading term vanishes
      %                        (vev of lvbc g divides vev of lvbc f)
      %
      % and  calculate f1 = a*f1
      % return value=f, secondvalue=f1
 begin scalar vevlcm,a,b,cg,x,fcofa,gcofa;
      fcofa := vdpgetprop(f,'cofact);
      gcofa := vdpgetprop(g1,'cofact);
      vevlcm := vevdif(vev,vdpevlmon g1);
      cg := vdplbc g1;
            % calculate coefficient factors
      x := vbcgcd(c,cg);
      a := vbcquot(cg,x);
      b := vbcquot(c,x);
      f:= vdpilcomb1 (vdpred f, a, vevzero(),
                      vdpred g1,vbcneg b, vevlcm);
      x := vdpilcomb1 (fcofa, a, vevzero(),
                       gcofa ,vbcneg b, vevlcm);
      vdpputprop(f,'cofact,x);
      return f;
 end;


symbolic procedure idqreduceonesteprat(f,dummy,c,vev,g1);
      % reduction step for rational case:
      % calculate f= f - g/vdpLbc(f)
      %
 begin scalar x,fcofa,gcofa,vev;
      fcofa := vdpgetprop(f,'cofact);
      gcofa := vdpgetprop(g1,'cofact);
      vev := vevdif(vev,vdpevlmon g1);
      x := vbcneg vbcquot(c,vdplbc g1);
      f := vdpilcomb1(vdpred f,a2vbc 1,vevzero(),
                      vdpred g1,x,vev);
      x := vdpilcomb1 (fcofa,a2vbc 1 , vevzero(),
                       gcofa,x,vev);
      vdpputprop(f,'cofact,x);
      return f;
 end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   calculation of an S-polynomial and related things
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure idqspolynom (p1,p2);
  begin scalar s,ep1,ep2,ep,rp1,rp2,db1,db2,x,cofac1,cofac2;
    if vdpzero!? p1  then return p1; if vdpzero!? p2  then return p2;
    cofac1 := vdpgetprop(p1,'cofact); cofac2 := vdpgetprop(p2,'cofact);
    ep1 := vdpevlmon p1;             ep2 := vdpevlmon p2;
    ep := vevlcm(ep1, ep2);
    rp1 := vdpred p1;               rp2 := vdpred p2;
    db1 := vdplbc p1;                db2 := vdplbc p2;
    if !*vdpinteger then
     <<x:=vbcgcd(db1,db2); db1:=vbcquot(db1,x); db2:=vbcquot(db2,x)>>;
    ep1 := vevdif(ep,ep1); ep2 := vevdif(ep,ep2); db2 := vbcneg db2;
    s := vdpilcomb1 (rp2,db1,ep2,rp1,db2,ep1);
    x := vdpilcomb1 (cofac2,db1,ep2,cofac1,db2,ep1);
    vdpputprop(s,'cofact,x);
    return s;
   end;


symbolic procedure idqdirectelement(p1,p2);
  % the s-Polynomial is reducable to zero because of
  % buchcrit 4. So we can calculate the corresponing cofactor
  % directly
    (if vdpzero!? c1 and vdpzero!? c2 then c1
     else vdpdif(vdpprod(p1,c2),vdpprod(p2,c1))
                        )  where c1 = vdpgetprop(p1,'cofact),
                                 c2 = vdpgetprop(p2,'cofact);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Normailsation with cofactors taken into account
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


symbolic procedure idqsimpcont(p);
    if !*vdpinteger then idqsimpconti p else idqsimpcontr p;

% routines for integer coefficient case:
% calculation of contents and dividing all coefficients by it

symbolic procedure idqsimpconti (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar res,num,cofac;
    if vdpzero!?  p then return p;
    cofac := vdpgetprop(p,'cofact);
    num := car vdpcontenti p;
    if not vdpzero!? cofac then num:=vbcgcd(num,car vdpcontenti cofac);
    if not vbcplus!? num then num := vbcneg num;
    if not vbcplus!? vdplbc p then num:=vbcneg num;
    if vbcone!? num then return p;
    res := vdpreduceconti (p,num,nil);
    if not vdpzero!? cofac then cofac:=vdpreduceconti(cofac,num,nil);
    res := vdpputprop(res,'cofact,cofac);
    return res;
    end;


% routines for rational coefficient case:
% calculation of contents and dividing all coefficients by it

symbolic procedure idqsimpcontr (p);
%   calculate the contents of p and divide all coefficients by it
  begin scalar res,cofac;
    cofac := vdpgetprop(p,'cofact);
    if vdpzero!?  p then return p;
    if vbcone!? vdplbc p then return p;
    res := vdpreduceconti (p,vdplbc p,nil);
    if not vdpzero!? cofac then
                 cofac:=vdpreduceconti(cofac,vdplbc p,nil);
    res := vdpputprop(res,'cofact,cofac);
    return res;
    end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  trace messages
%

symbolic procedure idqmess0 x;
    if !*trgroeb then
    <<prin2t "adding member to intermediate quotient basis:";
      vdpprint x;
      terpri()>>;

symbolic procedure idqmess1 (x,p1,p2);
    if !*trgroeb then
    <<prin2 "pair ("; prin2 vdpnumber p1; prin2 ",";
      prin2 vdpnumber p2;
      prin2t ") adding member to intermediate quotient basis:";
      vdpprint x;
      terpri()>>;

symbolic procedure idqmess2 b;
    if !*trgroeb then
    <<prin2t "---------------------------------------------------";
      prin2 "the full intermediate base of the ideal quotient is:";
      for each x in b do vdpprin3t x;
      prin2t "---------------------------------------------------";
      terpri()>>;


symbolic procedure idqmess5(p,h);
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
                       vdpprint vdpgetprop(h,'cofact);
                       groetimeprint() >> >>
     else
     if !*trgroeb then <<          % print for input polys
                       prin2t "candidate from input:";
                       vdpprint h;
                       groetimeprint() >>;



symbolic procedure idqmess3(p,s);
     if !*trgroebs then <<
                       prin2 "S-polynomial  ";
                       prin2 " from ";
                       groebpairprint p;
                       vdpprint s;
                       prin2t "with cofactor";
                       vdpprint vdpgetprop(s,'cofact);
                            groetimeprint();
                            terprit 3 >>;

endmodule;


module kredelw; % Kredel Weispfennig algorithm. 

%   Author:     H.Melenk (ZIB Berlin)


fluid '(vdpsortmode!* !*groebopt !*gsugar);

symbolic procedure gdimension_eval u;
  begin integer n,m;
   for each s in cdr gindependent_seteval u
    do if (m:=length cdr s)>n then n:=m;
   return n;
  end;

put('gdimension,'psopfn,'gdimension_eval);

symbolic procedure gindependent_seteval pars;
% Independent set algorithm (Kredel/Weispfennig).
% parameters:
%     1      Groebner basis
%     2      optional: list of variables
   begin scalar vars,x,u,v,w,oldorder,!*factor,!*exp,!*gsugar,
            !*groebopt;
      if vdpsortmode!* neq 'lex then
        typerr(vdpsortmode!*,
            "term order for Kredel-Weispfennig algorithm");
      !*exp := t;
      u := reval car pars;
      v := if cdr pars then reval cadr pars else nil;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,3,"Empty list");
      vars :=  if null v then
                for each j in gvarlis w collect !*a2k j
            else  groerevlist v;
      if not vars then return '(list);
      oldorder := vdpinit vars;
      w:=for each j in w collect vdpevlmon a2vdp j;
      vars:=for each y in vars collect y.vdpevlmon a2vdp y;
      w:=groebkwprec(vars,nil,w,nil);
      return 'list. for each s in w collect
         'list. reversip for each x in s collect car x;
   end;

put('gindependent_sets,'psopfn,'gindependent_seteval);

symbolic procedure groebkwprec(vars,s,lt,m);
  % recursive Kredel Weispfennig algorithm.
  % vars: unprocessed variables,
  % s:    current subset of s,
  % lt:   leading term basis,
  % m:    collection of independent sets so far.
  % returns: updated m.
  begin scalar x,s1,bool;
    s1:=for each y in s collect cdr y;
    while vars do
    <<x:=car vars; vars:= cdr vars;
      if groebkwprec1(cdr x.s1,lt) then
         m:=groebkwprec(vars,x.s,lt,m);
    >>;
    bool:=t;
    for each y in m do % bool and not subsetp(s,y);
        bool:=bool and not length s=length intersection(s,y);
    return if bool then s.m else m;
  end;

symbolic procedure groebkwprec1(s,lt);
  % t if intersection of T(s) and lt is empty.
   if null lt then t else
   groebkwprec2(s,car lt) and groebkwprec1(s,cdr lt);

symbolic procedure groebkwprec2(s,mon);
  % t if monomial not in T(s).
 <<for each m in s do mon:=vevcan0(m,mon);
   not vevzero!? mon>>;

symbolic procedure vevcan0(m,mon);
  % divide multiples of m1 out of mon.
  if vevzero!? m then mon else
  if vevzero!? mon then nil else
  (if car m neq 0 then 0 else car mon).vevcan0(cdr m,cdr mon);

endmodule;


end;
