module grinterf;  % Interface of Groebner package to REDUCE.
                  % Entry points to the main module and general
                  % interface support.
 
 
fluid '(!*factor !*complex !*exp asymplis!* current!-modulus powlis!*);

global '(!*match largest!-small!-modulus);

fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*fullReduction !*groebstat !*groebprot !*gltbasis
        !*groebsubs
 
	!*grmod!*                  % indicating modular coefficients
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpSortMode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        factortime!*               % computing time spent in factoring
        factorlvevel!*             % bookkeeping of factor tree
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbcCurrentMode!*           % current domain for base coeffs.
	vbcModule!*                % for modular calculation:
				   %     current prime
	bczerodivl!*               % coefficient zero divisors (list of
				   % standard forms)
        gmodule                    % external module basis
        gmodule!*                  % internal module basis
        global!-dipvars!*          % predefined variable list
        !*gsugar                   % enable sugar strategy
       );
 
global '(groebrestriction          % interface: name of function
         groebresmax               % maximum number of internal results
         gvarslast                 % output: variable list 
         groebprotfile
         gltb
         glterms                   % list for lterms collection
        );
 
flag ('(groebrestriction groebresmax gvarslast groebprotfile
        gltb glterms gmodule),'share);
 
switch groebopt,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,groebstat,gltbasis,gsugar;
 
% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!* 
        basecount!* hzerocount!*);
 
% control of the polynomial arithmetic actually loaded
fluid '(currentVdpModule!*); 

vdpsortmode!* := 'LEX;     % initial mode 
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
 
symbolic procedure groebnerFeval u;
  % non factorizing Groebner calculation 
   begin integer n; scalar !*groebfac,!*groebrm,!*factor,
         !*exp,!*ezgcd,s,r,q; !*exp := t;
      if null getd 'groebFactorize then load!-package 'GROEBFAC;
      !*groebrm := !*groebfac := T;
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
 
put('groebnerF,'psopfn,'groebnerFeval);

symbolic procedure idquotienteval u;
   begin integer n; scalar !*factor,!*exp; !*exp := t;
      n := length u;
      if n=2 then return groebidq(reval car u,reval cadr u,nil)
       else if n neq 3
	then rerror(groebner,3,
		    "IDQUOTIENT called with wrong number of arguments")
       else return groebidq(reval car u,reval cadr u,reval caddr u)
      end;

put('IDEALQUOTIENT,'psopfn,'idquotienteval);
  
smacro procedure vdpNumber f;
     vdpGetProp(f,'NUMBER) ;
 
 
symbolic procedure groebner1(u,v,r);
%    Buchberger algorithm system driver. u is a list of expressions
%    and v a list of variables or NIL in which case the variables in u
%    are used.
   begin scalar vars,w,np,oldorder,!*grmod!*;
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
      if dmode!* eq '!:mod!: and null setdiff(gvarlis w,vars)
	 and current!-modulus < largest!-small!-modulus
	then !*grmod!* := t;
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect reorder numr simp j;
		  % optimize variable sequence if desired.
      if !*groebopt and vdpsortmode!* memq '(lex gradlex revgradlex)
        then  << w:=vdpvordopt (w,vars); vars := cdr w; 
                 w := car w; vdpinit vars>>; 
      w := for each j in w collect f2vdp j;
      if not !*vdpInteger then
      <<np := t;
        for each p in w do
          np := if np then vdpCoeffcientsFromDomain!? p else nil;
        if not np then <<!*vdpModular:= nil; !*vdpinteger := T>>;
      >>;
      if !*groebprot then
          <<groebprotfile := list 'LIST>>;
      if r then r := for each p in r collect 
           vdpsimpcont f2vdp numr simp p;
      w := groebner2(w,r);
     
      if cdr w then  % Remove redundant partial bases.
      begin scalar !*gsugar;
        for each b in w do
         for each c in w do
          if b and b neq c then
           <<v:=t; for each p in c do 
               v:=v and vdpzero!? groebNormalForm(p,b,'list);
             if v then <<w:=delete(b,w); b:=nil>>;
           >>;
      end;
      if !*gltbasis then 
        gltb := 
           'list . for each base in w collect
                   'list . for each j in base collect
                      vdp2a vdpfmon(a2vbc 1,vdpevlmon j);
      w := 'list . for each base in w collect
                   'list . for each j in base collect vdp2a j;
      vdpcleanup();
      gvarslast := 'list . vars;
      return w;
   end;
 
symbolic procedure groebnervars(w,v);
    begin scalar z,dv,gdv,vars;
      if v='(list) then v:=nil;
      v:=v or (gdv:=cdr global!-dipvars!*) and global!-dipvars!*;
      vars :=
       if null v then
                for each j in gvarlis w collect !*a2k j
          else                      % test, if vars are really used
             << z := gvarlis w;
                groebnerzerobc setdiff(z,v:= groerevlist v);
                for each j in v do
                    if member(j,z) then dv := !*a2k j . dv;
                dv := reversip dv;
                if not (length v = length dv) and !*trgroeb then
                      << prin2 " Groebner: ";
                         prin2 (length v - length dv);
                         prin2t " of the variables not used";
                         terpri () >>;
                dv>>;
       return gdv or vars;
    end;
 
symbolic procedure groebnerzerobc u;
% u is the list of parameters in a Groebner job. Extract the
% corresponding rules from !*match and powlis!*.
 if u then
  begin scalar w,m,p;
    bczerodivl!* := nil;
    m:=!*match; !*match:=nil;
    p:=powlis!*; powlis!*:=nil;
    for each r in m do if cadr r='(nil . t) then
    <<w:=(numr simp {'difference,'times.for each q in car r collect 
{'expt,car q,cdr q}
                    ,caddr r});
      for each x in kernels w do if not member(x,u) then w:=nil;
      if w then bczerodivl!* := w . bczerodivl!*;
    >>;
    for each r in p do if member(car r,u) and caddr r='(nil . t) then
    <<w:=(numr simp {'difference, {'expt,car r,cadr r} ,cadddr r});
      bczerodivl!* := w . bczerodivl!*;
    >>;
    for each r in asymplis!* do if member(car r,u) then
      bczerodivl!* := (r .*1 .+nil) . bczerodivl!*;
    !*match:=m; powlis!*:=p;
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
      if null vars then vdperr 'IDEALQUOTIENT;
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect numr simp j;
      f :=  numr simp f;
      w := for each j in w collect f2vdp j;
      f := f2vdp f; % now do the conversions
      if not !*vdpInteger then
      <<np := t;
        for each p in f.w do
          np := if np then vdpCoeffcientsFromDomain!? p
                else nil;
        if not np then <<!*vdpModular:= nil; !*vdpinteger := T>>;
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

symbolic procedure GroeParams(u,nmin,nmax);
   % u is a list of psopfn-parameters; they are given to REVAL and 
   % the number of parameters is controlled to be between nmin, nmax
   % result is the list of evaluated parameters padded with NILs
     begin integer n; scalar w; n:= length u;
       if n<nmin or n>nmax then rerror(groebner,7,
	 "Illegal number of parameters in call to Groebner package");
       u:= for each v in u collect 
         <<w := reval v;
           if eqcar(w,'LIST) then 'LIST . groerevlist w else w>>;
       while length u < nmax do u := append(u,'(nil));
       return u;
     end;
        

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% initialization of the distributive plynomial arithmetic
%
 
symbolic procedure vdpinit (vars);
     begin scalar r,gm;   
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

end;
