module numeric;  % Header module for the numeric package and
                 % support of numerical evaluation of symbolic
                 % expressions.
 
% Author: Herbert Melenk.

% Copyright (c) 1991 ZIB Berlin, RAND.  All rights reserved.

% create!-package('(numeric numeval newton steepstd bounds numint 
%                   numfit bases rungeku),nil);

fluid '(!*noequiv);   
fluid '(accuracy!*);
global '(iterations!* !*trnumeric);
switch trnumeric;

% Create .. as the infix operator if not yet done.

newtok '( (!. !.) !*interval!*);
precedence .., or;
algebraic operator ..;
put('!*interval!*,'prtch,'! !.!.! );

% some common utilities

% intervals
 
symbolic procedure adomainp u;
   numberp u or (pairp u and idp car u and get(car u,'dname));

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if null num or(adomainp car l and adomainp cadr l)then return l;
    typerr(u,"numeric interval");
  end;

symbolic procedure mkinterval(u,v);
   list('!*interval!*,u,v);

% Easy coding of numerical procedures with REDUCE:
%
%  In statements or procedure bodies tagged with "dm:" all 
%  arithmetic function calls are replaced by REDUCE domain 
%  arithmetic.

symbolic macro procedure dm!: u;
  subla('((plus2 . !:plus)(times2 . !:times)
          (plus . !:plusn)(times . !:timesn)
          (quotient . !:!:quotient)
          (difference . !:difference)
          (minus . !:minus)
          (minusp . !:minusp)
          (zerop . !:zerop)
          (lessp . (lambda(a b)(!:minusp (!:difference a b))))
          (greaterp . (lambda(a b)(!:minusp (!:difference b a))))
          (sqrt . num!-sqrtf)
          (abs . absf)
         ) , cadr u);

%wrappers for n-ary plus and times

symbolic macro procedure !:plusn u;
  if null cddr u then cadr u else
   list('!:plus,cadr u,'!:plusn . cddr u);
 
symbolic macro procedure !:timesn u;
  if null cddr u then cadr u else
   list('!:times,cadr u,'!:timesn . cddr u);

endmodule;


module numeval; % numeric evaluation of algebraic expressions.

% Control of accuracy and precision.
%
%  precision:    number of digits used for computation,
%  accuracy:     target precision of the results; 
%
%  precision might be modified automatically for reaching the
%  desired accuracy.

symbolic procedure accuracycontrol(u,da,di);
  % u is an evluated parameter list. Extract
  % accuracy and iterations. If not present, take
  % given default values.
  begin scalar x,n,v;
   v:=u;
   accuracy!*:=da; iterations!*:=di;
   while v do
   <<x:=car v; v:= cdr v;
     if eqcar(x,'equal) and cadr x memq'(accuracy iterations) then
     <<u:=delete(x,u); n:=caddr x;
       if cadr x='accuracy then accuracy!*:=n 
           else iterations!*:=n;
   >>>>;
   return u;
 end;

symbolic procedure update!-precision l;
  % l is a list of domain elements. IF the minimum of their absolute
  % values is smaller than 10**(precision*+3), the precision is
  % increased.
  begin scalar mn; integer zp,p;
   mn:=update!-precision1 l; % positive minimum.
   if null mn then return nil;
   p := precision 0; zp:=!:recip expt(10,p-3);
   dm!: <<
     if mn>zp then return nil;
     while mn<zp do <<p:=p+1;zp:=zp/10>>;
     >>;
   precmsg p;
  end;
   
symbolic procedure update!-precision1 l;
 dm!:( begin scalar x,y,z;
      while l do
      <<x:=car l; l:=cdr l;
        if not zerop x then
        <<y:=abs x; z:=if null z or y<z then y else z>>
      >>;
      return z;
     end );
     
% Switching of mode and introduction of specific simplifiction
% rules.
 
algebraic<<

  rules_rd := 
   {~u ** ~x => exp(log u * x) when not numberp x};
  
  procedure switch!-mode!-rd!-alg u;
   if u=0 then
     <<for all x clear exp x;
       let rules_rd;
     >> else <<
       for all x let exp x=e**x;
       clearrules rules_rd; >>;
 
>>;
 
symbolic procedure switch!-mode!-rd u;
  begin scalar oldmode,prec;
  if null u then
    <<if not memq(dmode!*,'(!:rd!: !:cr))then
       <<oldmode:=t; setdmode('rounded,t)>>;
     !*noequiv:=t; prec:=precision 0; 
     switch!-mode!-rd!-alg 0;
     return list(oldmode,prec)
    >> else <<
     if car u then setdmode('rounded,nil);
     precision cadr u;
     switch!-mode!-rd!-alg 1;
    >>;
  end;
 
% Support for the numerical (=domain specific) evaluation of 
% algebraic equations.
%
% Roughly equivalent:
%   evaluate(u,v,p) = numr subsq(simp u,pair(v,p))
% but avoiding resimplification as we know that all components
% must evaluate to domain elements.

fluid '(dmarith!* !*evaluateerror);
 
dmarith!*:= '(
   (difference . !:difference) (quotient . !:!:quotient)
   (minus . negf) (sqrt . num!-sqrtf)
   (expt . !:dmexpt) );

symbolic procedure evaluate(u,v,p);
   begin scalar a,r,!*evaluateerror;
    a:= pair(v,p);
    r := errorset(list('evaluate1,mkquote u,mkquote a),t,nil);
    if atom r then rederr
        "error during function evaluation (e.g. singularity)";
    return car r;
  end;

symbolic procedure evaluate!*(u,v,p);
  % same as evaluate, but returning arithmetic (but not syntactical)
  % errors to the caller like errorset.
   begin scalar a,r,!*evaluateerror;
    a:= pair(v,p);
    r := errorset(list('evaluate1,mkquote u,mkquote a),t,nil);
    if null !*evaluateerror then return r else
         evaluate1(u,a); % once more, but unprotected.
  end;



symbolic procedure evaluate1(u,v);
    if numberp u or null u then force!-to!-dm u else
    if pairp u and get(car u,'dname) then u else
     (if a then cdr a else 
      if atom u then 
             if u='i then 
              if (u:=get(dmode!*,'ivalue)) then numr apply(u,'(nil))
                else rederr "i used as indeterminate value"
             else if u='e or u='pi then force!-to!-dm numr simp u
             else <<!*evaluateerror:=t; typerr(u,"number")>> 
             else evaluate2(car u,cdr u,v)
                ) where a=assoc(u,v);
 
symbolic procedure evaluate2(op,pars,v);
   <<pars:=for each p in pars collect evaluate1(p,v);
          % arithmetic operator.
     if op='plus then !:dmpluslst pars else
     if op='times then !:dmtimeslst pars else
     if(a:=assoc(op,dmarith!*)) then apply(cdr a,pars) else
          % elementary function, applicable for current dmode.
     if pairp car pars and (a:=get(op,caar pars)) then
          apply(a,pars) else
          % apply REDUCE siplificator otherwise
     force!-to!-dm numr simp (op . for each p in pars collect prepf p)
    >> where a=nil;

symbolic procedure list!-evaluate(u,v,p);
     for each r in u collect evaluate(r,v,p);
 
symbolic procedure matrix!-evaluate(u,v,p);
     for each r in u collect list!-evaluate(r,v,p);

symbolic procedure !:dmexpt(u,v);
    (if fixp n and n>0 and n<20  % only for conventional exponents
          then !:dmexpt1(u,n) else
         force!-to!-dm numr simp list('expt,prepf u, prepf v)
    ) where n=!:dm2fix v;

symbolic procedure !:dm2fix u;
  if fixp u then u else 
    (if fixp(u:=int!-equiv!-chk u) then u else
     if null u then 0 else
     if floatp cdr u and 0.0=cdr u-fix cdr u then fix cdr u
     else u) where !*noequiv=nil;

symbolic procedure !:dmexpt1(u,v);
    if v=0 then 1 else dm!:(u * !:dmexpt1(u,sub1 v));

symbolic procedure !:dmtimeslst u;
    if null u then 1 else 
    if null cdr u then car u else 
       dm!:(car u * !:dmtimeslst cdr u);

symbolic procedure !:dmpluslst u;
    if null u then 0 else 
    if null cdr u then car u else 
       dm!:(car u + !:dmpluslst cdr u);

% vector/matrix arithmetic

symbolic procedure list!+list(l1,l2);
   if null l1 then nil else
       dm!: (car l1 + car l2) . list!+list(cdr l1,cdr l2);

symbolic procedure scal!*list(s,l);
  if null l then nil else
     dm!: (s * car l) . scal!*list(s,cdr l) ;

symbolic procedure innerprod(u,v);
     if null u then 0 else
     dm!: ( car u * car v + innerprod(cdr u,cdr v) );

symbolic procedure conjlist u;
dm!:(if not !*complex then u else
    for each x in u collect 
       repartf x - numr apply(get(dmode!*,'ivalue),'(nil))*impartf x );

symbolic procedure normlist u;
  dm!:(sqrt innerprod(u, conjlist u));

symbolic procedure mat!*list(m,v);
    if null cdr m then scal!*list(car v,car m) else
    for each r in m collect innerprod(r,v);

symbolic procedure !:!:quotient(a,b);
     !:times(a,!:recip b);

symbolic procedure num!-sqrtf a;
   if domainp a then 
       apply(get('sqrt,dmode!*),list force!-to!-dm a)
     else
     <<a:=simpsqrt list prepf a;
       if not onep denr a or not domainp numr a
         then rederr "num-sqrtf called in wrong mode"
       else numr a>>;
 
symbolic procedure force!-to!-dm a;
   if not domainp a then typerr(prepf a,"number") else
   if null a then force!-to!-dm 0 else
   if numberp a then apply(get(dmode!*,'i2d),list a) else
   if pairp a and car a = dmode!* then a else
    (if fcn then apply(fcn,list a) else
       rederr list("conversion error with ",a)
     ) where fcn=(pairp a and get(car a,dmode!*));
 
symbolic procedure printsflist(x);
   begin integer n;
    writepri("(",nil);
    for each y in x do
       <<if n>0 then writepri(" , ",nil);
         n:=n+1;
         writepri(mkquote prepf y,nil)>>;
    writepri(")",nil);
  end;

endmodule;


module newton;  % root finding with generalized Newton methods.
 
% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

fluid '(!*noequiv accuracy!*);
global '(iterations!* !*trnumeric erfg!*);

symbolic procedure rdnewtoneval u;
     % interface function;
  begin scalar e,l,vars,y,z,p,erfg;
        integer n;
    erfg := erfg!*;
    erfg!* := nil;
    u := for each x in u collect reval x;
    u:=accuracycontrol(u,6,50);
    e :=car u; u :=cdr u;
      % construct the function vector.
    e:=if eqcar(e,'list) then cdr e else list e;
    e := for each f in e collect 
     if eqexpr (f:=reval f) then !*eqn2a f else f;
    n := length e;
      % starting point & variables.
    if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if eqcar(x,'equal) then
       <<z:=cadr x; y:=caddr x>> else <<z:=x; y:=random 100>>;
       vars:=z . vars; p := y . p>>;
    vars := reversip vars; p := reversip p;
    if not(n=length vars) then
    <<
   %  lprim "numbers of variables and functions don't match;";
   %  lprim "using steepest descent method instead of Newton";
   %  return rdsolvestdeval list ('list.e,'list.u,
   %                      {'equal,'accuracy,accuracy!*},
   %                      {'equal,'iterations,iterations!*});
      rederr "numbers of variables and functions don't match"
    >>;
    erfg!* := erfg;
    return rdnewton0(e,vars,p,n);
  end;
 
symbolic procedure rdnewton0(e,vars,p,n);
    %preparations for Newton iteration.
  begin scalar l,jac,x,y,oldmode,q,!*noequiv;
    integer prec;
    if not memq(dmode!*,'(!:rd!: !:cr!:))then 
       <<oldmode:=t; setdmode('rounded,t)>>;
    prec:=precision 0;
    p := for each x in p collect 
         force!-to!-dm numr simp x;
    if !*trnumeric then lprim "computing symbolic Jacobian";
    eval list('matrix,mkquote list list('jacobian,n,n));
    for i:=1:n do for j:=1:n do
        setmatelem(list('jacobian,i,j),
         aeval list('df,nth(e,i),nth(vars,j)));
    if !*trnumeric then lprim "inverting symbolic Jacobian";
    jac:= cdr aeval'(quotient 1 jacobian);
    jac := for each r in jac collect
       for each c in r collect reval c;
    !*noequiv:=t;
    x := rdnewton1(e,jac,vars,p,'root);
    if oldmode then setdmode('rounded,nil);
    precision prec;
    if null x then rederr "no solution found";
    return 'list.
       for each p in pair(vars,x) collect
          list('equal,car p,cdr p);
  end;

put('num_solve,'psopfn,'rdnewtoneval);

symbolic procedure rdnewton1(f,jac,vars,x,mode);
  begin scalar r,acc;
        integer n;
     if !*trnumeric then lprim "starting Newton iteration";
     acc := !:!:quotient(1,expt(10,accuracy!*));
     r:= rdnewton2(f,jac,vars,acc,x,mode);
     r:= for each x in r collect prepf x;
     return r;
 end;

symbolic procedure rdnewton2(f,jac,vars,acc,x,mode);
  % Algorithm for finding the root function system f
  % with technique of adaptively damped Newton.
  % f:     function to minimize (list of algebraic exprs);
  % jac:   symbolic inverted Jacobian;                    
  % vars:  variables (list of id's);
  % acc:   requested accuracy (e.g. 0.0000001)
  % x:     starting point (list of domain elements).
 dm!:
  begin scalar n,n0,n1,n2,e0,e1,dx,x1,g,dmp,delta,blowup;
    integer count;
      % reinitialize every 10n iterations.
    e0 := list!-evaluate(f,vars,x); n0 := normlist e0;
    dmp:=1;
  loop: 
    count:=add1 count;
    if count>iterations!* then
    <<lprim "requested accuracy not reached within iteration limit";
      goto ready>>;
      % evaluate inverse Jacobian.
    g := matrix!-evaluate(jac,vars,x);
    dx := mat!*list(g,e0);
    if dmp<1 then dmp:=dmp*2;  % stepwise reduce damping.
   step: 
    blowup := nil;
    x1 := list!+list(x, scal!*list(-dmp,dx));
    e1 := errorset({'list!-evaluate,mkquote f,
              mkquote vars,mkquote x1},nil,nil);
    if atom e1 then blowup := t else  
         <<e1 := car e1; n1 := normlist e1>>;
    if blowup or n1>n0 then 
    <<dmp:=dmp/2; 
      if dmp<acc then rederr "Newton method does not converge";
       goto step>>;
    x := x1; e0:=e1; n0:=n1; delta:=-dmp*normlist dx;
    update!-precision (delta.e0);
    rdnewtonprintpoint(count,x,dmp*normlist dx,e0);
    if n0>acc then<<update!-precision(delta.e0); goto loop>>;
  ready:
    return x;
  end;
 
symbolic procedure rdnewtonprintpoint(count,x,dx,e0);
  if !*trnumeric then
   begin integer n;
    writepri(count,'first);
    writepri(". residue=",nil);
    printsflist e0;
    writepri(", step length=",nil);
    writepri(mkquote prepf dx,'last);
    writepri(" at ",nil);
    printsflist x;
    writepri(" ",'last);
   end;
         
endmodule;


module steepstd;  % Optimization and root finding with method of
                  % steepest descent.
 

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

fluid '(!*noequiv accuracy!*);   
global '(iterations!* !*trnumeric); 

symbolic procedure rdmineval u;
  begin scalar e,l,vars,x,y,z,oldmode,p,!*noequiv;
    oldmode:=steepdecedmode(nil,nil);
    u := for each x in u collect reval x;
    u := accuracycontrol(u,6,40);
    e :=car u; u :=cdr u;
    if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if eqcar(x,'equal) then
       <<z:=cadr x; y:=caddr x>> else <<z:=x; y:=random 100>>;
       vars:=z . vars; p := y . p>>;
    vars := reversip vars; p := reversip p;
    x := steepdeceval1(e,vars,p,'min);
    steepdecedmode(t,oldmode);
    return list('list, car x, 'list. 
       for each p in pair(vars,cdr x) collect
          list('equal,car p,cdr p));
  end;
 
put('num_min,'psopfn,'rdmineval);
 
symbolic procedure rdsolvestdeval u;
   % solving a system of equations via minimizing the
   % sum of sqares.
  begin scalar e,l,vars,x,y,z,oldmode,p,q,!*noequiv;
    oldmode:=steepdecedmode(nil,nil);
    u := for each x in u collect reval x;
    e :=car u; u :=cdr u;
      % construct the function to minimize.
    e:=if eqcar(e,'list) then cdr e else list e;
    q := 'plus . for each f in e collect 
       list('expt,if eqexpr f then !*eqn2a f else f,2);
    q := prepsq simp q;
      % starting point & variables.
    if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if eqcar(x,'equal) then
       <<z:=cadr x; y:=caddr x>> else <<z:=x; y:=random 100>>;
       vars:=z . vars; p := y . p>>;
    vars := reversip vars; p := reversip p;
    x := steepdeceval1(q,vars,p,'root);
    steepdecedmode(t,oldmode);
    if null x then rederr "no solution found";
    return 'list.
       for each p in pair(vars,cdr x) collect
          list('equal,car p,cdr p);
  end;

symbolic procedure steepdecedmode(m,oldmode);
  if not m then % initial call
   << if !*complex then rederr
      "steepest descent method not applicable under complex";
    if not (dmode!*='!:rd!:)then
       <<oldmode:=t; setdmode('rounded,t)>>;
    oldmode.precision 0>>
  else % reset to old dmode.
    <<if car oldmode then setdmode('rounded,nil);
      precision cdr oldmode>>;

symbolic procedure steepdeceval1(f,vars,x,mode);
  begin scalar e,g,r,acc;
        integer n;
     n := length vars;
    % establish the target function and the gradient.
     e := prepsq simp f;
     if !*trnumeric then lprim "computing symbolic gradient";
     g := for each v in vars collect prepsq simp list('df,f,v);
     !*noequiv:=t;
     if !*trnumeric then 
      lprim "starting Fletcher Reeves steepest descent iteration";
     acc := !:!:quotient(1,expt(10,accuracy!*));
     x := for each u in x collect force!-to!-dm numr simp u;
     r:= steepdec2(e,g,vars,acc,x,mode);
     r:= for each x in r collect prepf x;
     return r;
 end;

symbolic procedure steepdec2(f,grad,vars,acc,x,mode);
  % Algorithm for finding the minimum of function f
  % with technique of steepest descent, version Fletcher-Reeves.
  % f:     function to minimize (standard quotient);
  % grad:  symbolic gradient (list of standard quotients);
  % vars:  variables (list of id's);
  % acc:   target precision (e.g. 0.000001)
  % x:     starting point (list of numerial standard forms).
  % mode:  minimum / roots type of operation
 dm!:
  begin scalar e0,e00,e1,e2,a,a1,a1a1,a2,a2a2,x1,x2,g,h,dx,w,
      delta,limit,gold,gnorm,goldnorm,multi;
    integer count,k,n;
    n:=length grad; multi:=n>1; n:=10*n; 
    e00 := e0 := evaluate(f,vars,x);
    a1 := 1;
  init: 
    k:=0;
      % evaluate gradient (negative).
    g := for each v in grad collect -evaluate(v,vars,x);
    gnorm := normlist g; h:=g;
  loop:
    count := add1 count; k:=add1 k;
    if count>iterations!* then
    <<lprim "requested accuracy not reached within iteration limit";
      % mode := nil;
      goto ready>>;

      % quadratic interpolation in direction of h in order
      % to find the minimum value of f in that direction.
    a2 := nil;
   l1:
    x1 := list!+list(x, scal!*list(a1,h));
    e1 := evaluate(f,vars,x1);
    if e1>e0 then <<a2:=a1; x2:=x1; e2:=e1;
            a1 := a1/2; goto l1>>;
    if a2 then goto alph;
   l2:
    a2 := a1+a1;
    x2 := list!+list(x, scal!*list(a2,h));
    e2 := evaluate(f,vars,x2);
    if e2<e1 then <<a1:=a2; e1:=e2; goto l2>>;
   alph:   %compute lowest point of parabel
    if abs(e1-e2)<acc then goto ready; % constant?
    a1a1:=a1*a1; a2a2:=a2*a2;
    a:= (a1a1-a2a2)*e0 + a2a2*e1 - a1a1*e2 ;
    a:= a/((a1-a2)*e0 + a2*e1-a1*e2);
    a:= a/2;
 
     % new point
    dx:=scal!*list(a,h); x:=list!+list(x, dx);
    e0 := evaluate(f,vars,x);
    if e0>e1 then % a1 was better than interpolation.
    <<dx:=scal!*list(a1-a ,h); x:=list!+list(x,dx);
      e0 := e1; dx:=scal!*list(a1,h)>>;
    delta:= normlist dx;
    steepdecprintpoint(count,x,delta,e0,gnorm);
    update!-precision list(delta,e0,gnorm);

      % compute next direction;
    if k>n then goto init; % reinitialize time to time.
    gold := g; goldnorm:= gnorm;
    g := for each v in grad collect -evaluate(v,vars,x);
    gnorm := normlist g; 
    if gnorm<limit then goto ready;
    h := if not multi then g else 
        list!+list(g,scal!*list(gnorm/goldnorm,h));
    if mode='min and gnorm > acc or
       mode='root and e0 > acc then goto loop;

  ready:
    if mode='root and not(abs e0 < acc) then
     <<lprim "probably fallen into local minimum of f^2";
        return nil>>;
    return e0 . x;
  end;
 
symbolic procedure steepdecprintpoint(count,x,d,e0,ng);
 if !*trnumeric then
   begin integer n;
    writepri(count,'first);
    writepri(". residue=",nil);
    writepri(mkquote prepf e0,nil);
    writepri(", gradient length=",nil);
    writepri(mkquote prepf ng,'last);
    writepri(" at (",nil);
    for each y in x do 
       <<if n>0 then writepri(" , ",nil);
         n:=n+1;
         writepri(mkquote prepf y,nil)>>;
    writepri(")",nil);
    writepri(", stepsize=",nil);
    writepri(mkquote prepf d,nil);
    writepri("",'last);
   end;
         

    
endmodule;


module bounds;   % Upper and lower bound of a 
% multivariate functional expression in a n-dimensional interval.
 
% Author: H. Melenk, ZIB, Berlin
 
% Copyright (c): ZIB Berlin 1991, all rights resrved

put('bounds,'psopfn,'boundseval);
put('bounds!-rd,'psopfn,'boundsevalrd);
put('bounds,'numericfn,'bounds!-rd);
 
fluid '(boundsdb!* !*msg);
 
symbolic procedure boundsevalrd u;
   begin scalar dmode!*;
     setdmode('rounded,t);
     return boundseval u;
   end;

symbolic procedure boundseval u;
  begin scalar db,y,l,f; 
    u := for each x in u collect reval x;
    f := car u; u := cdr u;
    if u and eqcar(car u,'list) then 
      u := for each x in cdar u collect reval x;
    for each x in u do
    <<if not eqcar(x,'equal) then typerr(x,"domain description");
      y := revalnuminterval(caddr x,nil);
      l:=list(simp car y,simp cadr y);
      db := (cadr x . minsq l . maxsq l).db>>;
    u := boundseval1(f,db);
    return mkinterval(prepsq car u,prepsq cdr u);
  end;
 
symbolic procedure boundserr(a,b);
    if !*msg then if a then typerr(a,b) else rederr b;

symbolic procedure boundseval0 (f,db,!*msg);
  % internal calling convention:
  %  f            algebraic expression,
  %  db           list of (x . lo . hi), where
  %               lo and hi represent the current interval for
  %               variable x as standard quotients.
  %  result is a pair of standard quotients representing
  %               the bounds for f.
    boundseval1(f,db);

symbolic procedure boundseval1(u,db);
  % centalize intervals for tighter bounds with polynomials.
   begin scalar boundsdb!*,x,l,h,a,m,y;
     for each interv in db do
     <<x:=car interv; l:=cadr interv; h:=cddr interv;
       m:=multsq(addsq(l,h),1 ./ 2);
       if not null numr m then
       <<y:=gensym();
         a:=(x . {'plus,y,prepsq m}) . a;
         interv:=y . (subtrsq(l,m).subtrsq(h,m));
       >>;
       boundsdb!* := interv.boundsdb!*;
     >>;
     if a then u:=prepsq subsq(simp u,a);
     return boundseval2 u;
   end;

symbolic procedure boundseval2 u;
  % Main driver for bounds evaluation.
  if adomainp u then <<u:=simp u;u.u>> else
  begin scalar v,fcn;
    if (v:=assoc(u,boundsdb!*))then return cdr v;
    if atom u then goto err;
    fcn:=get(car u,'boundseval) or 'boundsoperator;
    v := apply(fcn,list u);
    if null v or 
       not domainp numr car v or not domainp denr car v or
       not domainp numr cdr v or not domainp denr cdr v then goto err;
     % cache result for later usage.
    boundsdb!*:= (u.v).boundsdb!*;
    return v;
err: boundserr(nil,"unbounded in range");
  end;

symbolic procedure boundsoperator u;
  % general external interface: function flagged decreasing,
  % increasing of explicit bounds given.
   if flagp(car u,'increasing) then boundsincreasingfn u else
   if flagp(car u,'decreasing) then boundsdecreasingfn u else
   if get(car u,'upperbound) and get(car u,'lowerbound) then 
       simp get(car u,'lowerbound) . simp get(car u,'upperbound)
    else nil;

symbolic procedure boundsplus u;
  begin scalar lo,hi,x;
   u := cdr u; x := boundseval2 car u;
   lo := car x; hi := cdr x;
   for each y in cdr u do
   <<x:= boundseval2 y; lo:=addsq(lo,car x); hi:=addsq(hi,cdr x)>>;
   return lo.hi
  end;
 
put('plus,'boundseval,'boundsplus);
 
symbolic procedure boundsdifference u;
  begin scalar lo,hi,x;
   u := cdr u; x := boundseval2 car u;
   lo := car x; hi := cdr x;
   x:= boundsminus u; 
   lo:=addsq(lo,car x); hi:=addsq(hi,cdr x);
   return lo.hi
  end;

put('difference,'boundseval,'boundsdifference);

symbolic procedure boundsminus(u);
  (negsq cdr v . negsq car v) where v=boundseval2(cadr u);
 
put('minus,'boundseval,'boundsminus);
 
symbolic procedure boundstimes u;
  boundstimes1 cdr u;
 
symbolic procedure boundstimes1 u;
  if null cdr u then boundseval2 car u else
  begin scalar x,y,z;
   x:=boundstimes1 cdr u; y :=boundseval2 car u;
      % first handle simple cases
   if not minusf numr car x and not minusf numr car y then
        return multsq(car x,car y) . multsq(cdr x,cdr y);
   if minusf numr cdr x and minusf numr cdr y then
        return multsq(cdr x,cdr y) . multsq(car x,car y);
   z:=list(multsq(car x,car y), multsq(car x,cdr y),
           multsq(cdr x,car y), multsq(cdr x,cdr y));
   return minsq z . maxsq z;
  end;
 
symbolic procedure minsq l;
  begin scalar x,z;
   x := car l;
   for each y in cdr l do
    if minusf numr subtrsq(y,x) then x:=y;
   return x;
  end;
 
symbolic procedure maxsq l;
  begin scalar x,z;
   x:= car l;
   for each y in cdr l do
    if minusf numr subtrsq(x,y) then x:=y;
   return x;
  end;

symbolic procedure sqgreaterp(x,y);
     minusf numr subtrsq(y,x);
     
put('times,'boundseval,'boundstimes);

symbolic procedure boundsexp u;
        boundsexpt list('expt,'e,cadr u);
 
put('exp,'boundseval,'boundsexp);

symbolic procedure boundsexpt u;
 (if fixp ex and ex>0 then boundsexpt2(base,ex) else
  if adomainp base or (idp base and flagp(base,'constant)) then 
     boundsexpt1(base,ex) else
  if adomainp ex then boundsexpt3(base,ex) else
  boundsexpt4(base,ex) ) where base=cadr u,ex=caddr u;
 
symbolic procedure boundsexpt1(base,ex);
  % Form constant ** x.
  begin scalar b;
    b := boundseval2 ex;
    if not evalgreaterp(base,0) then
       boundserr(base,"base of exponential in bounded expression");
    return simp list('expt,base,prepsq car b) .
           simp list('expt,base,prepsq cdr b);
  end;

symbolic procedure boundsexpt2(base,ex);
  % Form x ** n. Look for even exponents.
  begin scalar b,hi,lo,bh,bl;
    b := boundseval2 base;
    bl := exptsq(car b,ex); bh := exptsq(cdr b,ex);
    if not evenp ex then return bl.bh;
    lo := minusf numr cdr b;
    hi := not minusf numr car b;
    return 
        if hi then bl.bh else  % both had been positive
        if lo then bh.bl else  % both had been negative: invert
             (nil ./ 1) . maxsq list(bl,bh);
   end;

symbolic procedure boundsexpt3(base,ex);
  % Form x ** constant, including fractional exponents.
  begin scalar b,l;
    b := boundseval2 base;
    l := list(simp list('expt,prepsq car b,ex),
              simp list('expt,prepsq cdr b,ex));
    return minsq l . maxsq l;
  end;

symbolic procedure boundsexpt4(base,ex);
  % Form x ** y. x>0 only.
  % Either monotonous growing or falling: pick extremal points.
  begin scalar b,e,l;
    b := boundsprepsq boundseval2 base; 
    e := boundsprepsq boundseval2 ex;
    if agreaterp(0,car b) then return nil;
    l := list(simp list('expt,car b,car e),
              simp list('expt,car b,cdr e),
              simp list('expt,cdr b,car e),
              simp list('expt,cdr b,cdr e));
    return minsq l . maxsq l;
  end;
 
symbolic procedure boundsprepsq u; prepsq car u . prepsq cdr u;

put('expt,'boundseval,'boundsexpt);
 
symbolic procedure boundsquotient u;
  begin scalar n,d,l;
    n:=boundseval2 cadr u; d:=boundseval2 caddr u;
    if minusf numr multsq(car d,cdr d) then
      boundserr(nil,"unbounded in range");
    l := list(quotsq(car n,car d),quotsq(car n,cdr d),
              quotsq(cdr n,car d),quotsq(cdr n,cdr d));
    return minsq l . maxsq l;
  end;
 
put('quotient,'boundseval,'boundsquotient);
 
symbolic procedure boundsabs u;
(if evalgreaterp(prepsq car n,0) then n else
 if evalgreaterp(0,prepsq cdr n) then negsq cdr n . negsq car n else
  (nil ./1) . maxsq list (negsq car n,cdr n)
    ) where n=boundseval2 cadr u;
    
put('abs,'boundseval,'boundsabs);

symbolic procedure boundsincreasingfn u;
  % Bounds for an increasing function. Out-of -range problems will
  % be detected either by the function evaluation or finally by
  % the main driver if the result is not an interval with numeric
  % bounds.
   ( simp list(car u,prepsq car n) . simp list(car u,prepsq cdr n)
    ) where n=boundseval2 cadr u;

put('log,'boundseval,'boundsincreasingfn);
put('asin,'boundseval,'boundsincreasingfn);
put('atan,'boundseval,'boundsincreasingfn);
put('sqrt,'boundseval,'boundsincreasingfn);
 
symbolic procedure boundsdecreasingfn u;
   ( simp list(car u,prepsq cdr n) . simp list(car u,prepsq car n)
    ) where n=boundseval2 cadr u;

put('acos,'boundseval,'boundsdecreasingfn);
put('acot,'boundseval,'boundsdecreasingfn);

symbolic procedure boundssincos u;
   % Reason if one of the turn points (n*pi) is in the
   % range. If yes, include the corresponding value 1 or -1.
   % Otherwise compute the range spanned by the end points.
  begin scalar n,lo,hi,alo,ahi,pi,!2pi,!3pi,l,m;
        integer s;
     n := errorset(list('boundseval2,mkquote cadr u),nil,nil);
     if atom n then goto trivial;
     n := car n;
     lo := car n; hi := cdr n; 
     pi := simp 'pi;
     if not domainp numr pi then goto trivial;
     !2pi := addsq(pi,pi); !3pi := addsq(pi,!2pi);
       % convert sin to cos
     if car u = 'sin then <<m :=multsq(pi, -1 ./ 2);
         lo := addsq(lo,m); hi := addsq(hi,m)>>; 
     m := negsq multsq(!2pi,fixsq quotsq(lo,!2pi));
       % move interval to main interval
     lo:=addsq(lo,m); hi:=addsq(hi,m);
     if minusf numr lo then
     <<lo := addsq(lo,!2pi); hi := addsq(hi,!2pi)>>;
     if null numr lo or sqgreaterp(hi,!2pi) then l:= (1 ./ 1) . l;
     if (sqgreaterp(pi,lo) and  sqgreaterp(hi,pi))
      or(sqgreaterp(!3pi,lo) and  sqgreaterp(hi,!3pi))
       then l := (-1 ./ 1) . l;
     if l and cdr l then goto trivial;
     l := num!-cossq lo . num!-cossq hi . l;
     return minsq l . maxsq l;
 trivial:
     return ((-1)./1) . (1 ./ 1);
  end;

symbolic procedure fixsq u; simp list('fix,prepsq u);
 
symbolic procedure num!-cossq u; simp list('cos,prepsq u);

symbolic procedure agreaterp(u,v);
   (lambda x;
    if not atom denr x or not domainp numr x
      then error(99,"number")
     else numr x and !:minusp numr x)
        simp!* list('difference,v,u);

put('sin,'boundseval,'boundssincos);
put('cos,'boundseval,'boundssincos);

symbolic procedure boundstancot u;
  begin scalar n,lo,hi,alo,ahi,x,m; integer s;
     n := boundseval2 cadr u; lo := car n; hi := cdr n; 
       % convert cot to tan.
     if car u = 'cot then <<m :=simp '(quotient pi -2);
         x:=negsq addsq(lo,m);lo:=negsq addsq(hi,m);hi:=x>>; 
     m := simp list('minus,list('times,'pi,
             list('fix,list('quotient,prepsq lo,'pi))));
       % move interval to central interval
     lo:=addsq(lo,m); hi:=addsq(hi,m);
     if not agreaterp(alo:=prepsq lo,0) then
     <<m:=simp 'pi; lo := addsq(lo,m); hi := addsq(hi,m);
       alo := prepsq lo>>;
     if alo=0 or not agreaterp('pi,ahi:=prepsq hi) then 
         boundserr(nil,"unbounded in range");
     return simp list('tan,alo).simp list('tan,ahi);
  end;

put('tan,'boundseval,'boundstancot);
put('cot,'boundseval,'boundstancot);

endmodule;


module numint; % calculate a numerical integral with M. Wulkow's
                % adaptive multilvel method.

fluid '(!*noequiv accuracy!* singularities!*);
global '(iterations!* !*trnumeric);

symbolic procedure intrdeval u;
     % interface function;
  begin scalar e,l,vars,y,p,singularities!*;
        integer n;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,3,20);
    e :=car u; u :=cdr u;
      % variables and interval's.
    if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if not eqcar(x,'equal) then typerr(x,"interval bounds");
       y:=revalnuminterval(caddr x,t);
       vars:=cadr x.vars; 
       p:=(cadr x. car y. cadr y).p>>;
    return intrd1(e,vars,p);
  end;
 
put('num_int,'psopfn,'intrdeval);

symbolic procedure intrd1 (e,vars,p);
   begin scalar acc,r,oldmode,!*noequiv;
    oldmode:=switch!-mode!-rd nil;
    acc := !:!:quotient(1,expt(10,accuracy!*));
    e := reval e;
    r := if null cdr p then intrduni(e,p,acc) else
          intrdmulti(e,p,acc);
    switch!-mode!-rd oldmode;
    return r;
  end;

symbolic procedure intevaluate1(e,x,v);
  (if atom a then <<singularities!*:=v.singularities!*; 0>> 
     else car a)where a=evaluate!*(e,list x,list v);
 
symbolic procedure intevaluate(e,x,v);
  (if atom a then <<singularities!*:=v.singularities!*; 0>>
     else car a)where a=evaluate!*(e,x,v);

symbolic procedure intrduni (e,p,acc);
   % univariate integral.
 dm!:
  begin scalar lo,flo,hi,fhi,x,d,u,eps,i,il,r,int,oldint;
     integer n,k;
    x := car p; p:= cdr p;
   % evaluate the interval.
    lo := cadr x; hi := cddr x; x := car x;
    lo:=force!-to!-dm lo; hi:=force!-to!-dm hi;
    if hi=lo then return force!-to!-dm nil;
      % initial interval;
    il := list intrdmkinterval(e,x,
               (lo.intevaluate1(e,x,lo)),
               (hi.intevaluate1(e,x,hi)),1);
    int:=car lastpair car il;
  loop:
    k:=add1 k; n:=add1 n;
    if remainder(n,25)=0 then intrdmess(n,il);
   % divide the interval with the biggest local error;
    i:=car il; il:=cdr il; u:=intrdintersect(e,x,i);
    if null u then 
        <<il:=i.il;
          intrdabortmsg(list car cadr i,list x,intcollecteps il);
           goto ready>>;
    for each q in u do il := intrdsortin(q,il);
    if k<5 then goto loop;

   % control variation of result
    if n=5 then 
    <<int:=intcollectint il;acc:=acc*abs int>>; % adjust accuracy
    k:=0; eps := intcollecteps il; 
    if eps>acc then goto loop;
  ready:
    return intcollectint il;
  end;
 
symbolic procedure intrdabortmsg(pt,vars,eps);
   <<writepri(
"requested accuracy cannot be reached within iteration limit",'only);
     writepri("critical area of function near to ",'first);
     writepri(mkquote('list . for each u in pair(vars,pt)
       collect list('equal,car u,prepf cdr u)),'last);
     writepri("current error estimate: ",'first);
     writepri(mkquote prepf eps,'last);
   >>;

symbolic procedure intcollectint il;
 dm!: <<for each i in cdr il do r:= car lastpair i + r; r>>
          where r=car lastpair(car il);

symbolic procedure intcollecteps il;
 dm!: <<for each i in cdr il do r:= car i + r; r>>
          where r=car(car il);

symbolic procedure intrdsortin(u,l);
   % sort interval u into l such that l is sorted with descending car.
 dm!:( if null l then list u else
       if car u < caar l then car l . intrdsortin(u,cdr l) else
       u . l);

symbolic procedure intrdintersect(e,x,i);
  begin scalar d,plo,pmi,phi,lev;
    i:= cdr i;
    plo := car i; i := cdr i;
    pmi := car i; i := cdr i; 
    phi := car i; i := cdr i;
    d   := car i; dm!:(d:=d/2);
    lev := cadr i +1;
    if lev>iterations!* then return nil;
    return list (intrdmkinterval(e,x,plo,pmi,lev) , 
                 intrdmkinterval(e,x,pmi,phi,lev) );
   end;
 
symbolic procedure intrdmkinterval(e,x,lo,hi,lev);
  dm!: begin scalar eps,it,is,mid,mi,flo,fhi,fmid,d,u;
    d := car hi- car lo;
    mid := (car hi+ car lo)/2; 
    flo := cdr lo; fhi := cdr hi;
    fmid:=intevaluate1(e,x,mid);
    mi:=mid.fmid;
    if u:=intrdunisingular(lo,mi,hi) then
         <<flo:=car u; fmid:=cadr u; fhi:=caddr u>>;
    it := d*(flo+ 2fmid + fhi) / 4;         % order 1 integral;
    is := d*(4*flo + 16*fmid + 4*fhi)/24;   %simpson integral;
    eps:= abs(is-it);
                                            % interval record:
    return list (eps,                       % local error contrib
                 lo, mi, hi,                % the 3 points
                 d, lev, is);               % length and simpson.
  end;
 
symbolic procedure intrdunisingular(lo,mi,hi);
  % local extraploation for singular points.
  if singularities!* then
   begin scalar slo,smi,shi,fl,fm,fh,u;
    slo:=member(car lo,singularities!*);
    smi:=member(car mi,singularities!*);
    shi:=member(car hi,singularities!*);
    if not slo and not smi and not shi then return nil;
    if slo and smi and shi then rederr "too many singularities";
    fl:=cdr lo; fm:=cdr mi; fh:=cdr hi;
    dm!:( u := 2*(fl+fm+fh) );
    return list(if slo then u else fl, 
                if smi then u else fm,
                if shi then u else fh);
  end;

symbolic procedure intrdmulti(e,p,acc);
  % multivariate integral.
 dm!:
  begin scalar vars,x,y,u,eps,i,il,r,int,oldint;
     integer n,k,dim;
    dim:=length p;
    il:=intrdmkinitcube(e,p);
    vars := car il; il:= cdr il;
  loop:
    k:=add1 k; n:=add1 n;
    if remainder(n,25)=0 then intrdmess(n,il);
   % divide the simplex with the biggest local error;
    i:=car il; il:=cdr il; u:=intrdrefinecube(e,vars,i);
    if null u then
        <<il:=i.il;
          intrdabortmsg(car cadr i,vars,intcollecteps il);
           goto ready>>;
    for each q in u do il := intrdsortin(q,il);
    if k<5 then goto loop;

   % control variation of result
    if n=5 then 
    <<int:=intcollectint il;acc:=acc*abs int>>; % adjust accuracy
    k:=0; eps := intcollecteps il; 
    if eps>acc then goto loop;
  ready:
    return intcollectint il;
  end;

symbolic procedure intrdmkinitcube(e,p);
  % make initial element.
   begin scalar vol,points,vars,il,lo,hi,x,y;
    vol:=1;
    for each z in p do
    <<vars:=car z.vars; 
      x:=force!-to!-dm cadr z; 
      y:=force!-to!-dm cddr z;
      lo:=x.lo; hi:=y.hi;
      vol:= dm!:( abs(x-y)*vol );
    >>;
    lo:=lo.intevaluate(e,vars,lo);
    hi:=hi.intevaluate(e,vars,hi);
    il:=list intrdmkcube(e,vars,lo,hi,vol,1);
    return vars.il;
  end;

symbolic procedure intrdrefinecube(e,vars,i);
 dm!:  % divide cube into 2.
  begin scalar plo,phi,lo,hi,nlo,nhi,vol,x,y,xnew;
     integer m,lev;
    i:=cdr i;
    plo:=car i; i:=cdr i; phi:=car i; i:=cdr i;
    vol:= car i / 2; lev := add1 cadr i;
    if lev > iterations!* then return nil;
    lo:=car plo; hi:=car phi;
      % select longest edge of interval;
    m := 1; x := car hi-car lo;
    for j:=2:length lo do
      if x<(y:=(nth(hi,j)-nth(lo,j))) then<<m:=j;x:=y>>;
    nlo := append(lo,nil); nhi := append(hi,nil);
    xnew:=(nth(hi,m) + nth(lo,m)) /2 ;
    nth(nlo,m):=xnew; nth(nhi,m):=xnew;
    nlo := nlo.intevaluate(e,vars,nlo);
    nhi := nhi.intevaluate(e,vars,nhi);
    return list(
      intrdmkcube(e,vars,plo,nhi,vol,lev),
      intrdmkcube(e,vars,nlo,phi,vol,lev));
  end;
    
symbolic procedure intrdmkcube(e,vars,lo,hi,vol,lev);
   % make a fresh cube record.
  dm!: begin scalar u,eps,it,is,mid,fmi,flo,fhi;
    flo:= cdr lo; fhi:= cdr hi;
    mid:=list!+list(car lo,car hi); mid:=scal!*list(1/2,mid);
    fmi:= intevaluate(e,vars,mid);
    if u:=intrdunisingular(lo,mid.fmi,hi) then
         <<flo:=car u; fmi:=cadr u; fhi:=caddr u>>;
    is:=flo+fhi;
    it:=is*vol/2; is:=(2*fmi+is)*vol/4;
    eps := abs(is-it);
    return list(eps,lo,hi,vol,lev,is);
  end;

symbolic procedure intrdmess(n,il);
  if !*trnumeric then
   <<writepri(2*n,'first); writepri(" intervals, integral=",nil);
     writepri(mkquote prepf intcollectint il,nil);
     writepri(", error estimate=",nil);
     writepri(mkquote prepf intcollecteps il,nil);
   >>;

symbolic procedure prinxt l;
  begin integer i;
    for each x in l do
     if not eqcar(x,'!:rd!:) then prin2 x else
     if atom cdr x then prin2 x else
       <<prin2 (float cadr x *expt(10.0,cddr x));
         tab (i:=20+i)>>;
     terpri();
   end;  

endmodule;


module numfit; % approximation of functions with least spares.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

fluid '(!*noequiv accuracy!* singularities!*);
global '(iterations !*trnumeric);

symbolic procedure fiteval u;
     % interface function;
  begin scalar a,b,c,d,e,r,l,q,x,v,var,pars,fcn,fl,basis,pts,
        grad,oldmode,!*noequiv;
        integer n,i;
    if not(length u=3) then goto synerr;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,6,200);
    fcn :=car u; u :=cdr u;
    if eqcar(fcn,'list) then fl:=cdr fcn;
    basis:=car u; u :=cdr u;
    if not eqcar(basis,'list) then goto synerr;
    basis := for each x in cdr basis collect simp reval x;
    var:= car u; u := cdr u;
    if not eqcar(var,'equal) then goto synerr;
    if not eqcar(pts:=caddr var,'list) then goto synerr;
    var := cadr var; pts:=cdr pts; n:=length pts;
    if !*trnumeric then prin2t "build generic approximation function";
    a:=nil./1;
    for each b in basis do
    <<v:=gensym(); pars:=v.pars; a:=addsq(multsq(simp v,b),a)>>;
      % generate the error expression
    oldmode:=switch!-mode!-rd nil;!*noequiv:=nil;
    b:=a:=simp prepsq a;
    fcn:=simp if null fl then fcn else 'dummy; e:=nil./1;
    for each p in pts do
    <<i:=i+1;l:=list(var.p); % value to be substituted.
      if fl then l:=('dummy . reval nth(fl,i)).l;
      q:=subtrsq(subsq(fcn,l),subsq(b,l));
      e:=addsq(e,multsq(q,q))>>;
    e:=prepsq e;
    if !*trnumeric then
      <<lprim "error function is:";writepri(mkquote e,'only)>>;
      % find minimum.
      % build gradient.
    grad:='list . for each v in pars collect reval {'df,e,v};
    r:=rdnewtoneval
       list (grad,'list . for each p in pars collect list('equal,p,0),
                  {'equal,'accuracy,accuracy!*},
                  {'equal,'iterations,iterations!*}); 
      % resubstitute into target function.
    if !*trnumeric then lprim "resubstituing in approximating form";
    l:=nil; pars:= nil;
    for each p in cdr r collect 
       <<x:=caddr p; pars:=x.pars; l:=(cadr p.x).l>>;
    a:=prepsq subsq(a,l);
    switch!-mode!-rd oldmode;
    return list('list, a ,'list . pars);
  synerr:
    rederr "illegal parameters in fit";
  end;
 
put('num_fit,'psopfn,'fiteval);

endmodule;


module bases;  % Univariate orthogonal bases (for approximation etc).
 
% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

symbolic procedure binomial(n,m);
    factorial n/(factorial m * factorial(n-m));
    
symbolic operator binomial;

algebraic procedure monomial_base(x,n);
     for i:=0:n collect x**i;
 
algebraic procedure trigonometric_base(x,n);
     1 . for i:=1:n join list(sin(i*x),cos(i*x));
 
algebraic procedure bernstein_base(x,n);
     for i:=0:n collect 
         binomial(n,i)*(1-x)**(n-i)*x**i;
 
algebraic procedure legendre_base(x,n);
     legendre_base1(x,n,{x,1},1);
 
algebraic procedure legendre_base1(x,n,base,r);
     if r>=n then reverse base else
     legendre_base1(x,n,
        (2*(r+1)/(r+1)*x*first base - r/(r+1)*second base )
              . base, r+1);

algebraic procedure laguerre_base(x,n);
     laguerre_base1(x,n,{1-x,1},1);

algebraic procedure laguerre_base1(x,n,base,r);
     if r>=n then reverse base else
     laguerre_base1(x,n,
        ((1+2r-x)*first base - r**2*second base )
              . base, r+1);

algebraic procedure hermite_base(x,n);
     hermite_base1(x,n,{1-x,1},1);

algebraic procedure hermite_base1(x,n,base,r);
     if r>=n then reverse base else
     hermite_base1(x,n,
        (2x*first base - 2r*second base )
              . base, r+1);

algebraic procedure chebyshew_base(x,n);
     chebyshew_base1(x,n,{x,1},1);

algebraic procedure chebyshew_base1(x,n,base,r);
     if r>=n then reverse base else
     chebyshew_base1(x,n,
        (2x*first base - second base )
              . base, r+1);

endmodule;


module rungekuku;  % Numeric solution of ODE's with Runge-Kutta.
 
% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

fluid '(!*noequiv accuracy!*);
global '(iterations!* !*trnumeric);

put ('num_odesolve,'psopfn,'rungekuttaeval);

symbolic procedure rungekuttaeval u;
     % interface function;
  begin scalar e,f,x,y,sx,sy,en,d,nd,v,w;
        integer n;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,20,6);
    e :=car u; u :=cdr u;
    y :=car u; u :=cdr u;
    if not eqcar(y,'equal) or not idp cadr y
     then typerr(y,"expression `dep. variable=starting value'");
    sy:=caddr y; y := cadr y;
    x :=car u; u :=cdr u;
    if not eqcar(x,'equal) or not idp cadr x 
       or null (w:=revalnuminterval(caddr x,t))
        then typerr(x,"expression `indep. variable=interval'");
    sx:=car w; en:=cadr w; x := cadr x;
      % convert expression to explicit ODE.
    d := rukufinddf(e);
    if null d or not(y=cadr d) or not(x=caddr d) or
     (cdddr d and not(1=cadddr d)) then
         typerr(e,"differential form for Runge Kutta");
    nd:= gensym();
    e:=subst(nd,d,e);
    v:=cdr solveeval list(e,nd);
    if atom v or cdr v or
      not(eqcar(v:=car v,'equal) and (cadr v=nd)) then
       rederr("cannot convert expression to explicit ODE");
    f:=reval caddr v;
    return rungekutta1(f,x,y,sx,en,sy);
end;

symbolic procedure rukufinddf(e);
  % Find the differential in algebraic expression e.
  if atom e then nil else
  if car e='df then e else
   rukufinddf car e or rukufinddf cdr e;

symbolic procedure rungekutta1(f,x,y,sx,ex,sy);
    %preparations for rungekutta iteration.
  begin scalar acc,r,oldmode,!*noequiv;
    integer prec;
    if not memq(dmode!*,'(!:rd!: !:cr))then 
       <<oldmode:=t; setdmode('rounded,t)>>;
    !*noequiv:=t; prec:=precision 0;
    sx := force!-to!-dm numr simp sx;
    ex := force!-to!-dm numr simp ex;
    sy := force!-to!-dm numr simp sy;
    acc := !:!:quotient(1,expt(10,accuracy!*));
    if !*trnumeric then prin2t "starting rungekutta iteration";
    r := rungekutta2(f,x,y,sx,ex,sy,acc);
    if oldmode then setdmode('rounded,nil);
    precision prec;
    if null r then rederr "no solution found";
    return 'list.r;
  end;

symbolic procedure rungekutta2(f,xx,yy,xs,xe,ys,acc);
  % Algorithm for numeric ODE solution
  % f(xx,yy): rhs;
  % x:     independent variable;                    
  % y:     dependent variable; 
  % s:     starting point;
  % e:     endpoint;                                
  % acc:   required accuracy
 dm!:
  begin scalar n,h,h2,h4,d1,d2,d3,d4,x,y,r,w1,w2,vars,dir;
    integer count,st;
    vars := list(xx,yy);
    x:=xs; y:=ys;
    h:=(xe - xs)/iterations!*; 
    dir := h>0; st:= iterations!*;
     % compute initial stepsize
  adapt:
    h2:=h/2; h4:=h/4;
     % full stepsize.
    w1:=rungekuttastep(f,vars,x,y,h,h2);
     % same with half stepsize.
    w2:=rungekuttastep(f,vars,x,y,h2,h4);
    w2:=rungekuttastep(f,vars,x+h2,w2,h2,h4);
    if abs(w2 - w1) > acc then
    <<h:=h/2; st:=st+st; goto adapt>>;
    if !*trnumeric and not(st=iterations!*) then
      <<prin2 
         "*** RungeKutta increased number of steps internally to ";
        prin2t st>>;
  loop: 
    if (dir and x>xe) or (not dir and x<xe) then
        return {'list,xs,ys}. rungekuttares(reversip r,st);
    r:={'list,x,y} . r;
    count:=add1 count;
    y:= rungekuttastep(f,vars,x,y,h,h2);
      % Advance solution.
    x:=x+h;
    goto loop;
  end;

symbolic procedure rungekuttares(l,st);
   % eliminate intermediate points.
     if st=iterations!* then l else
     << for i:=1:iterations!* collect
         <<for j:=1:m do l:= cdr l; car l>>
     >> where m=st/iterations!*;

symbolic procedure rungekuttastep(f,vars,x,y,h,h2);
 dm!:
   begin scalar d1,d2,d3,d4;
    d1:= evaluate(f,vars,list(x,y));
    d2:= evaluate(f,vars,list(x+h2,y+h2*d1));
    d3:= evaluate(f,vars,list(x+h2,y+h2*d2));
    d4:= evaluate(f,vars,list(x+h,y+h*d3));
      % find y(x+h).
    y:=y+h*(d1 + 2*d2 + 2*d3 + d4)/6;
    return y;
  end;
 
endmodule;


end;
