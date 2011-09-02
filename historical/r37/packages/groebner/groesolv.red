module groesolv; % Tools for solving systems of polynomials (and poly-
%               % nomial equations) based on Groebner basis techniques.

%   Authors:     H.Melenk (ZIB Berlin)
%                H.M Moeller (Fernunversitaet Hagen)
%                W.Neun (ZIB Berlin)
%
%    Aug 1992:   accepting external solutions for univariate pols.   
%
%    March 1994: access to roots/multroot.
%
%    Feb 1995: assumptions, requirements added.
 
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
        !*compxroots    % switch for multroot
        gmodule
        !*arbvars
       );

fluid '(!*convert !*ezgcd !*msg !*precise dmode!* !*varopt);
global '(groebprotfile gvarslast !*trgroesolv glterms assumptions
         requirements);
 
groesolvelvevel!* := 0;

symbolic procedure groesolveeval u;
    begin scalar !*ezgcd,GBlist,oldtorder,res,!*groebopt,!*precise,
            y,fail,problems,denominators!*,variables!*,gmodule,at;
      if null dmode!* then !*ezgcd := t;
      !*groebopt := !*varopt; gvarslast :='(list);
      oldtorder := apply1('torder,'(lex));
      groesoldmode!* := get(dmode!*,'dname);
      !*groebcomplex := !*complex;
      groesetdmode(groesoldmode!*,NIL);
      problems:={u};
      while problems and not fail do
      <<u:=car problems; problems:=cdr problems;
        GBlist := cdr GroebnerFeval u; 
        at := union(at,cdr glterms);
        !*groebopt := nil;    % 29.8.88
        groesetdmode(groesoldmode!*,T);
        if null variables!* then variables!*:=gvarslast;
	if not(Gblist = '((list 1))) then 
         for each gb in GBlist do
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
           <<y:=groesolvearb(groesolve0(gb,variables!*),variables!*);
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
      problems:=nil; if fail then res:=nil;
      if null res then requirements:=append(requirements,at)
        else assumptions := append(assumptions,at);
      for each r in res do problems:=union(cdr r,problems);
      return 'list . groesolve!-redun2 problems
     end;
 
symbolic procedure groesolve!-redun2 sol;
  % Sol is a list of solutions; remove redundancies, now not
  % by ideal theory but by simple substitution.
 begin scalar b;
   for each s in sol do
     if s memq sol then
     <<b:=nil;
       for each r in sol do
	 if not(r eq s) then
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

symbolic procedure groesolvearb(r,vars);
 % Cover unmentioned variables.
  if atom r or not !*arbvars then r else
  for each s in r collect
   <<for each x in cdr vars do
       if not smember(x,s) then 
            s:=append(s,{{'equal,x,prepf makearbcomplex()}});
     s>>;

%------------------- driver for the postprocessor ----------------

symbolic procedure groesolve0(A,vars);
  begin scalar r,ids,newvars,newA;
    if(r:=groepostnumsolve(A,vars))then return r;
    if(r:=groepostfastsolve(A,vars))then return r;
    r:=groepostsolveeval{A,vars};
    if r neq 'failed then return cdr r;
    ids:=cdr gindependent_seteval{A,vars};
    if null ids then goto nullerr;
    ids:=car ids;
    newvars:='list.for each x in cdr vars join 
                 if not(x memq ids) then {x};
    newA:=groebnereval{A,newvars};
    denominators!*:=cdr glterms;
    if newA='(list 1) then rerror(groebner,24,
        "recomputation for dim=0 failed");
    r:=groepostfastsolve(newA,newvars);
    if r then return r;
    r:=groepostsolveeval{A,vars};
    if r neq 'failed then return cdr r;
nullerr:
    rerror(groebner,23,
        "Moeller ideal decomposition failed with 0 dim ideal");
    end;
    
symbolic procedure groepostnumsolve(gb,vars);
  if not errorp errorset('(load!-package 'roots2),nil,nil)
  and getd 'multroot0 
  and get(dmode!*,'dname) member '(ROUNDED COMPLEX!-ROUNDED)
  and length gb = length vars and groepostnumsolve1(gb,vars)
  then (cdr reval multroot0(precision 0,gb)) where !*compxroots=t;

symbolic procedure groepostnumsolve1(gb,vars);
  if null gb then t else
  groepostnumsolve1(cdr gb,cdr vars) and
  <<for each x in kernels numr simp car gb do q:=q and x member vars;
    q>> where q=t;

symbolic procedure groepostfastsolve(gb,vars);
   % try to find a fast solution.
  begin scalar u,p1,p2,fail,kl,res;
    if !*trgroesolv then prin2t "fast solve attempt";
    groesoldmode!* := get(dmode!*,'dname);
    !*groebnumval := member(groesoldmode!* ,
                  '(ROUNDED COMPLEX!-ROUNDED));
    groesetdmode(groesoldmode!*,'NIL);
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
     u:=groesolvePolyv(prepf f,v);
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
        groesoldmode!* := get(dmode!*,'dname);
        groesetdmode(groesoldmode!*,'NIL);
        !*groebnumval := member(groesoldmode!* ,
                          '(ROUNDED COMPLEX!-ROUNDED));
        if vdpsortmode!* = 'LEX then t else
	  rerror(groebner,8,
		 "Groepostproc, illegal torder; (only LEX allowed)");
        a := groerevlist reval car u;
        vars := cdr u and groerevlist cadr u or groebnervars(a,nil);
        oldorder := setkorder vars;
        b :=  groesolve1(a,a,vars);
        a := NIL;
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
 
symbolic procedure groesolve1 (A,fullA,vars);
 %  A        lex Groebner basis or tail of lex Groebner basis
 %  fullA    the complete lex Groebner basis to A
 %  vars     the list of variables
  if null A or A='(1) then nil else
  <<begin scalar f1,A1,res,Q,gi,Ng1,Ng2,NgQ,Qg,mv,test;
      res := assoc (A,groesoldb!*); if res then return cdr res;
      groesolvelvevel!* := groesolvelvevel!* + 1;
      %%tr prin2t  "=================================================";
      %%tr prin2l list( " groesolvelvevel!*: ",groesolvelvevel!*);
      %%tr           prin2t " Problem:"; 
      %%tr                   writepri (mkquote ('list . a),'only);;
      if member(A,!*groesolrecurs) then return 'failed;
%        <<vars := append(cdr vars,{car vars});
%          if member(vars,!*groesolrecurs) then
%          <<!*groesolgarbage := T;
%            return list for each p in A collect list('EQUAL,p,0) >>;
%          !*groesolrecurs := vars . !*groesolrecurs;
%          A := cdr Groebnereval{'list.A,'list . vars};
%        >>;
      !*groesolrecurs := A . !*groesolrecurs;
      if length A = 1 then
       << %%tr print  "single polynomial; solve it";
          res := groesolvePoly car A; goto ready>>;
         % step 1
      f1 := car A;
      A1 := cdr A;
      test := nil;
      mv := intersection(vars,LtermVariables f1);    % test Buchcrit 4
      for each p in A1 do
         if intersection (mv,LtermVariables p) then test := T;
      if not test then
      << %%tr print "f1 has unique main variable";
         NgQ := groesolve1(A1,A1,vars);
         if NgQ eq 'failed then <<res:='failed;goto ready>>;
         res := ZerosetIntersection(NgQ,f1,vars);
         goto ready>>;
%     Q := cdr GroebIdq('list . A1,f1,'list . vars);    % A1:f1
      Q := GroesolvIdq(A1,f1,vars);
        %%tr print "A1:f1"; %%tr writepri (mkquote ('list . Q),'only);;
      if Q='(1) then     % f1 already member of A1; skip it
        <<%%tr print "f1 already in A1; ignore";
          res:= groesolve1(A1,fullA,vars);
          goto ready>>;
      NgQ := groesolve1(Q,Q,vars);
      if NgQ eq 'failed then <<res:='failed;goto ready>>;
      ng1 := ZerosetIntersection (NgQ,f1,vars);
         % step 4
      if GroesolvIdqTest(A1,f1,vars) then 
      << while Q do
         << gi := car Q; Q := cdr Q;
            gi := preduceeval list (gi , 'list . A, 'list . vars);
            if gi = 0 then Q:= nil else
               A := cdr GroebIdq('list . A ,gi,'list . vars);
         >>;
         Ng2 := groesolve1(A,A,vars); 
         if Ng2 eq 'failed then <<res:='failed;goto ready>>;
      >> else
      <<Ng2 := ();
         if length Q = 1 then
         << gi := preduceeval list (car Q, 'list . fullA, 'list . vars);
           if gi neq 0 then
	   << Qg := cdr GroebIdq('list . fullA,gi,'list . vars); % A1:gi
              Ng2 := groesolve1(Qg,Qg,vars);
              if Ng2 eq 'failed then <<res:='failed;goto ready>>;
         >> >>
         else 
            <<Ng2 := groesolve2(A1,Q,vars);
              if Ng2 eq 'failed then <<res:='failed;goto ready>>
            >>
      >>;
      res:= ZerosetUnion (Ng1,Ng2);
    ready:
      %%tr print list( "Result, level!*: ",groesolvelvevel!*);
      %%tr writeres res;
      %%tr print "...................................................";
      groesolvelvevel!* := groesolvelvevel!* -1;
      groesoldb!* := (a . res) . groesoldb!*;
      return res;
   end
   >> where !*groesolrecurs = !*groesolrecurs; % recursive fluid!
 
symbolic procedure GroesolvIdqTest(A1,f1,vars);
      not(deg(f1,car vars) eq deg(car A1,car vars));

symbolic procedure GroesolvIdq(A1,f1,vars); 
      begin scalar x,temp;    
         x := car  vars;
         if not GroesolvIdqTest(A1,f1,vars)
             then return cdr GroebIdq('list . A1,f1,'list . vars);  
         temp := 
           for each p in A1 collect
	     reval car reverse coeffeval list(p,x);
         return cdr groebnereval list ('list . temp,'list . vars); 
       end;
 
symbolic procedure groesolve2(A,Q,vars);
  % Calculation of the zeroset A1:(g1,g2,,,,gs), 
  % the gi given as members of Q.
     groesolvetree (A,Q,Q,vars);
 
symbolic procedure groesolvetree(A,T1,phi,vars);
   begin scalar Q,NGtemp,NGall,T2,h,g,A2,phi2;
      %%tr prin2t ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
      %%tr prin2t "groesolvetree; A:";
      %%tr writepri(mkquote ('list . a),'only);
      %%tr writepri( "T1 :",'car); 
      %%tr writepri(mkquote ('list . T1) ,'last); 
      %%tr writepri( "phi:",'car);
      %%tr writepri(mkquote ('list .  phi),'last);
       if null phi then return nil else
       if null T1 then   
          <<Q := cdr GroebIdq('list.A, 'TIMES.phi,'list.vars);
            %%tr prin2t "<< << << << << << << << << << << << << <<<";
            return if car Q = 1 then nil
                                else groesolve1(Q,Q,vars) >>;
       for each g in T1 do
       <<h:=Preduceeval list(g,'LIST.A,'LIST.vars); 
         phi := delete(g,phi);
         if not(h=0) then <<T2:=h.T2; phi:=h.phi>>;
       >>; 
       if null phi then return nil;  % 29.8.88
       T1 := T2;
       Q := cdr GroebIdq('list.A, 'TIMES.phi,'list.vars);
        %%tr writepri( "PHI :",'car); 
        %%tr writepri(mkquote ('TIMES.phi) ,'last); 
        %%tr writepri( "A:PHI :",'car);
        %%tr  writepri(mkquote ('LIST.Q) ,'last);
       if not(car Q = 1) then
       << NGall := groesolve1(Q,Q,vars);
          if NGall eq 'failed then return 'failed;
       >>;
       if !*groesolgarbage then 
               return groesolverestruct(Q,phi,vars,NGall);
        while T1 do
          <<g:=car T1; T1:=cdr T1;
            phi2 := delete(g,phi);
            if phi2 then
            <<A2 := cdr Groebnereval list('LIST . g . A,'LIST . vars);
              if not(car A2 =1) then
               <<NGtemp := groesolvetree(A2,T1,phi2,vars);
                 NGall := ZerosetUnion(NGtemp,NGall)>>;
           >>>>;
       %%tr prin2t "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
       return NGall;
   end;

symbolic procedure groesolverestruct(A,phi,vars,NGall);
     % there was a problem with an embedded solution in phi such that
     % A:phi = A
     % we try a heuristic by making one variable a formal parameter
    begin scalar newA,newvars,mv,oldorder,solu;
        mv := LtermVariables ('TIMES.phi);
        mv := car mv;
         %%tr prin2 "groesolverestruct:taking variable ";prin2t mv;
        newvars := delete(mv,vars);
        oldorder := setkorder newvars;
        newA := cdr GroebnerEval list('LIST . A,'LIST . newvars);
         %%tr    prin2t "new Groebner basis:";
         %%tr    writepri(mkquote ('LIST . newA),'ONLY);
        !*groesolgarbage := NIL;
        solu := groesolve1(newA,newA,newvars);
         %%tr if !*groesolgarbage then prin2t "Heuristics failed"
         %%tr                     else prin2t "better result";
        setkorder oldorder;
        return if !*groesolgarbage then NGall else solu;
    end;
         
            
 
%%tr symbolic procedure writeres r;
%%tr writepri (mkquote ('list.for each x in r collect 'list.x),'ONLY);
 
symbolic procedure LtermVariables u;
  % extract variables of leading term in u
    begin scalar v;
      u := numr simp u;
      while not domainp u do
      <<v := mvar u . v;
        u := lc u>>;
      return reversip v;
    end;
 
symbolic procedure ZerosetIntersection (NG,poly,vars);
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
      if NG=() then goto finish;
      ns := car NG; NG := cdr NG;
      testpoly := poly;
      dom := groesoldmode!* or 'RATIONAL;
      groesetdmode(dom,T);
      testpoly := simp prepsq testpoly;
      for each u in ns do
       if idp lhs u and not smemq('root_of,rhs u) then 
       <<s := rhs u; 
         testpoly := subsq(testpoly,list (lhs u . s));
       >>;
      groesetdmode(dom,nil);
      ppoly := prepf numr testpoly;
      sol := groesolvePolyv(ppoly,var);
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
 
symbolic procedure groeSolvePoly p; groesolvePolyv(p,mainvar p);
 
symbolic procedure groesolvePolyv(p,var);
   % find the zeros for one polynomial p in the
   % variable "var".
   % current dmode is NIL.
  (begin scalar res,u,!*convert,y,z;
      if (u:=assoc(var,depl!*)) then depl!*:=delete(u,depl!*);
      if !*trgroesolv then
      <<writepri("   solving univariate with respect to ",'first);
        writepri(mkquote var,'last);
        writepri(mkquote p,'only);
      >>;
      for each s in groebroots!* do 
       if 0=reval{'difference,p,car s} then res:=cdr s;
      if res then return res;
      groesetdmode(groesoldmode!*,T);
      u := numr simp p;
      res := if !*groebnumval and UnivariatePolynomial!? u
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
      groesetdmode(groesoldmode!*,NIL);
      return res;
  end) where depl!*=depl!*;
 
symbolic procedure UnivariatePolynomial!? fm;
      domainp fm or UnivariatePolynomial!?1 (fm,mvar fm);
 
symbolic procedure UnivariatePolynomial!?1 (fm,v);
       domainp fm or
         domainp lc fm and v = mvar fm and 
                           UnivariatePolynomial!?1(red fm,v);
 
symbolic procedure predecessor (r,l);
  % looks for the  predecessor of r in l
   if not pairp l or not pairp cdr l or r = car l
	  then rerror(groebner,9,"No predecessor available") else
   if r = cadr l then car l else predecessor (r,cdr l);
 
symbolic procedure ZerosetUnion(ng1,ng2);
     <<%print list( "union von ",ng1,ng2;
       ng1 := ZerosetUnion1(ng1,ng2);
     % print list( "-->",ng1);
       ng1>>;
 
symbolic procedure ZerosetUnion1(ng1,ng2);
    % Vereinigung von Nullstellengebilden
      if ng1 = () then ng2
            else
      if ZerosetMember(car ng1,ng2) then ZerosetUnion1(cdr ng1,ng2)
            else
      car ng1 . ZerosetUnion1(cdr ng1,ng2);
 
symbolic procedure ZerosetMember (ns,ng);
      if ng = () then nil else
      if ZeroEqual(ns,car ng) then ng else
         ZerosetMember (ns,cdr ng);
 
symbolic procedure ZeroEqual(ns1,ns2);
      if Zerosubset(ns1,ns2) then Zerosubset(ns2,ns1) else nil;
 
symbolic procedure Zerosubset(ns1,ns2);
      if null ns1 then T else
      if member(car ns1,ns2) then Zerosubset(cdr ns1,ns2)
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
      if !*groebprot then groebprotfile := list 'LIST;
      n := length pars;
      x := reval car pars;
      u := reval cadr pars;
      v := if n>2 then reval caddr pars else nil;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      if null w then rerror(groebnr2,3,"Empty list in Preduce");
      vars := groebnervars(w,v);
      if not vars then vdperr 'PREDUCE;
      oldorder := vdpinit vars;
      w := for each j in w collect a2vdp j;
      x := a2vdp x;
      if !*groebprot then 
          <<w := for each j in w collect vdpenumerate j; 
            groebprotSetq('CANDIDATE,vdp2a x);
            for each j in w do groebprotSetq(mkid('poly,vdpnumber j),
                                             vdp2a j)>>;
      w := groebNormalForm(x,w, 'sort);
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
      x := nil; r := reval{'roots,p};
         % re-evaluate rhs in order to get prefix form
      r := for each e in cdr r collect 
            list('equal,cadr e,reval caddr e);
      return 'list . r;
   end;

endmodule;

end;
