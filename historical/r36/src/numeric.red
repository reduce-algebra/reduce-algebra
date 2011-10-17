module numeric;  % Header module for the numeric package and
                 % support of numerical evaluation of symbolic
                 % expressions.

% Author: Herbert Melenk.

% Copyright (c) 1993 ZIB Berlin, RAND.  All rights reserved.

create!-package('(numeric numeval numsolve gauss newton steepstd
                  bounds numint numfit chebysh rungeku),
                '(contrib numeric));

fluid '(!*noequiv);
fluid '(accuracy!*);
global '(iterations!* !*trnumeric);
switch trnumeric;

% Create .. as infix operator.

newtok '( (!. !.) !*interval!*);

if null get('!*interval!*,'simpfn) then
<<precedence .., or;
  algebraic operator ..;
  put('!*interval!*,'prtch,'! !.!.! );
>>;

% some common utilities

fluid '(minus!-infinity!*);

minus!-infinity!* := '(minus infinity);

% intervals

symbolic procedure adomainp u;
   numberp u or (pairp u and idp car u and get(car u,'dname));

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if adomainpx(car l,num) and adomainpx(cadr l,num)then return l;
    typerr(u,"numeric interval");
  end;

symbolic procedure adomainpx(u,num);
  % extended algebraic domainp test:
  % num = t: u is a domain element;
  % num = inf: u is a domain element or inf or (minus inf)
  % num = nil: u is arbitrary.
    null num or adomainp u or num='infinity
                and member(u,'(infinity (minus infinity)));

symbolic procedure evalgreaterpx(a,b);
  if a =minus!-infinity!* or b = 'infinity then nil else
  a='infinity or b=minus!-infinity!* or evalgreaterp(a,b);

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
          (leq . (lambda(a b)(not (!:minusp (!:difference b a)))))
          (geq . (lambda(a b)(not (!:minusp (!:difference a b)))))
          (sqrt . num!-sqrtf)
          (abs . absf)
          (min2 . dm!:min)
          (max2 . dm!:max)
          (min . dm!:min)
          (max . dm!:max)
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
  % u is an evaluated parameter list. Extract
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
  begin scalar oldmode,prec,ne;
  if null u then
    <<if not memq(dmode!*,'(!:rd!: !:cr))then
       <<oldmode:=t; setdmode('rounded,t)>>;
     ne := !*noequiv;
     !*noequiv:=t; prec:=precision 0;
     switch!-mode!-rd!-alg 0;
     return list(oldmode,prec,!*roundbf,ne)
    >> else <<
     if car u then setdmode('rounded,nil);
     precision cadr u;
     !*roundbf := caddr u;
     !*noequiv := cadddr u;
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
   (expt . !:dmexpt) (min . dm!:min) (max . dm!:max));

symbolic procedure evaluate(u,v,p);
   begin scalar a,r,!*evaluateerror,msg;
    msg := not !*protfg;
    a:= pair(v,p);
    r := errorset(list('evaluate0,mkquote u,mkquote a),msg,nil)
           where !*msg=nil,!*protfg=t;
    if errorp r then rederr
        "error during function evaluation (e.g. singularity)";
    return car r;
  end;

symbolic procedure evaluate!*(u,v,p);
  % same as evaluate, but returning arithmetic (but not syntactical)
  % errors to the caller like errorset.
   begin scalar a,r,!*evaluateerror;
    a:= pair(v,p);
    r := errorset(list('evaluate0,mkquote u,mkquote a),nil,nil)
          where !*msg=nil,!*protfg=t;
    erfg!* := nil;
    if null !*evaluateerror then return r else
         evaluate0(u,a); % once more, but unprotected.
  end;

symbolic procedure evaluate0(u,v);
   evaluate1(evaluate!-horner u,v);

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
 if op='!:dn!: then numr dn!:simp pars else
   <<pars:=for each p in pars collect evaluate1(p,v);
          % arithmetic operator.
     if op='plus then !:dmpluslst pars else
     if op='times then !:dmtimeslst pars else
     if(a:=assoc(op,dmarith!*)) then apply(cdr a,pars) else
          % elementary function, applicable for current dmode.
     if pairp car pars and (a:=get(op,caar pars)) then
          apply(a,pars) else
         % apply REDUCE simplifier otherwise
     force!-to!-dm numr simp (op . for each p in pars collect prepf p)
    >> where a=nil;

symbolic procedure list!-evaluate(u,v,p);
     for each r in u collect evaluate(r,v,p);

symbolic procedure matrix!-evaluate(u,v,p);
     for each r in u collect list!-evaluate(r,v,p);

symbolic procedure !:dmexpt(u,v);
    (if fixp n then !:expt(u,n) else
      <<u:=force!-to!-dm u; v:=force!-to!-dm v;
        if !*complex then crexpt!*(u,v) else rdexpt!*(u,v)
      >>) where n=!:dm2fix v;

symbolic procedure dm!:min(a,b);
   dm!:(if a > b then b else a);

symbolic procedure dm!:max(a,b);
   dm!:(if a > b then a else b);

symbolic procedure !:dm2fix u;
  if fixp u then u else
    (if fixp(u:=int!-equiv!-chk u) then u else
     if null u then 0 else
     if floatp cdr u and 0.0=cdr u-fix cdr u then fix cdr u
     else u) where !*noequiv=nil;

symbolic procedure !:dmtimeslst u;
    if null u then 1 else
    if null cdr u then car u else
       dm!:(car u * !:dmtimeslst cdr u);

symbolic procedure !:dmpluslst u;
    if null u then 0 else
    if null cdr u then car u else
       dm!:(car u + !:dmpluslst cdr u);

symbolic procedure !:!:quotient(u,v);
   !:quotient(u,if fixp v then i2rd!* v else v);

% vector/matrix arithmetic

symbolic procedure list!+list(l1,l2);
   if null l1 then nil else
       dm!: (car l1 + car l2) . list!+list(cdr l1,cdr l2);

symbolic procedure list!-list(l1,l2);
   if null l1 then nil else
       dm!: (car l1 - car l2) . list!-list(cdr l1,cdr l2);

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

symbolic procedure num!-sqrtf a;
   if domainp a then
       apply(get('sqrt,dmode!*),list force!-to!-dm a)
     else
     <<a:=simpsqrt list prepf a;
       if not onep denr a or not domainp numr a
         then rederr "sqrtf called in wrong mode"
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

fluid '(horner!-cache!*);

symbolic procedure evaluate!-horner u;
  (if w then cdr w else
   <<w:=simp!* u;
     w:=prepsq(hornerf numr w ./ hornerf denr w);
     horner!-cache!* := (u.w). horner!-cache!*;
     w
   >>) where w=assoc(u,horner!-cache!*);

endmodule;


module numsolve;  % root finding.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1991, all rights resrved

fluid '(!*noequiv accuracy!* !*exptexpand);
global '(iterations!* !*trnumeric erfg!*);

symbolic procedure rdsolveeval u;
     % interface function;
  begin scalar e,vars,y,z,p,r,erfg,mode,all,!*exptexpand;
        integer n;
    erfg:= erfg!*; erfg!* := nil;
    u := for each x in u collect reval x;
    u:=accuracycontrol(u,6,50);
    if (all:='all memq u) then u:=delete('all,u);
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
       <<z:=cadr x; y:=caddr x;
         if eqcar(y,'!*interval!*) then mode:='i;
       >> else <<z:=x; y:=random 100>>;
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
    if mode='i and length vars>1 or mode neq 'i and all then
           rederr "mode for num_solve not implemented";
    r:=if mode='i then rd!-solve!-interv(e,vars,p,n,all)
        else rdnewton0(e,vars,p,n);
    erfg!* := erfg;
    return r;
  end;

put('num_solve,'psopfn,'rdsolveeval);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  finding root in an interval (secant method and related)
%

symbolic procedure rd!-solve!-interv(e,vars,p,n,all);
 (begin scalar u,fu,l,fl,x,acc,r,de,w,oldmode;
    if length p>1 then typerr('list . p,"single interval");
    p:=car p; e:=car e; x:=car vars;
    w := {'boundseval,mkquote {e,{'equal,x,p}}};
   if not memq(dmode!*,'(!:rd!: !:cr!:))then
       <<oldmode:=t; setdmode('rounded,t)>>;
    if errorp errorset(w,nil,nil) then
     typerr(e,"bounded expression");
    acc := !:!:quotient(1,expt(10,accuracy!*));
    l:=evaluate(cadr p,nil,nil); u:=evaluate(caddr p,nil,nil);
    fl:=evaluateuni(e,x,l); fu:=evaluateuni(e,x,u);
    if not all then
    dm!:(if zerop fl then return prepf l else
         if zerop fu then return prepf u else
         if fl*fu<0 then
          r := regula!-falsi(e,x,l,fl,u,fu,acc));
    if null r then de := reval {'df,e,x};
    if null r and not all then
       r:=rd!-solve!-trynewton(e,de,x,l,fl,u,fu,acc);
    if null r then
       r:=rd!-solve!-hardcase(e,de,x,l,fl,u,fu,acc,all);
    if oldmode then setdmode('rounded,nil);
    if r then return r;
    rederr "not applicable";
   end) where !*roundbf=!*roundbf;

symbolic procedure make!-rdsolve!-result1(x,u);
   'list.for each r in u collect {'equal,x,prepf r};

symbolic procedure rd!-solve!-trynewton(e,de,x,l,fl,u,fu,acc);
  begin scalar r,invde;
    invde := {'quotient,1,de};
  dm!: <<
    if fu*evaluateuni(de,x,u) >0 then
      r := rdnewton2({e},{{invde}},{x},acc,{u},'root,l,u);
    if null r and fl*evaluateuni(de,x,l) <0 then
      r := rdnewton2({e},{{invde}},{x},acc,{l},'root,l,u);
    if r and (r:=car r) and l <= r and r <= u then
         r := make!-rdsolve!-result1(x,{r}) else r:=nil;
     >>;
    return r;
  end;

symbolic procedure regula!-falsi(e,x,l,fl,u,fu,acc);
   make!-rdsolve!-result1(x,
       {regula!-falsi1(e,x,l,fl,u,fu,acc,0,1)});

symbolic procedure regula!-falsi1(e,x,l,fl,u,fu,acc,mode1,mode2);
  % modified regula falsi: using bisection in order to
  % traverse root as often as possible.
 dm!: begin scalar m,fm;
     if mode1=mode2 then m:=(u+l)/2
        else m := l*fu/(fu-fl) + u*fl/(fl-fu);
     if (u-l) < acc then return m;
     fm := evaluateuni(e,x,m);
     if zerop fm then return m;
     return if fl*fm<0
       then regula!-falsi1(e,x,l,fl,m,fm,acc,nil,mode1)
       else regula!-falsi1(e,x,m,fm,u,fu,acc,t,mode1);
    end;

symbolic procedure mkminus u; {'minus,u};

symbolic procedure evaluateuni(e,x,p);
     evaluate(e,{x},{p});

symbolic procedure dmboundsuni(e,x,l,u);
  begin scalar i;
     i:=boundseval {e,{'equal,x,{'!*interval!*,prepf l,prepf u} }};
     return numr simp cadr i . numr simp caddr i;
  end;

symbolic procedure rd!-solve!-hardcase(e,de,x,l,fl,u,fu,acc,all);
 dm!: begin scalar il1,il2,pt,iv,r,rr,b,b1,q,d;
     integer lev;
   il1:={(l.fl) .(u.fu)};
  main_loop:
    lev:=lev+1; il2:=nil;
    if null il1 then goto done;
    il1 := reverse il1;
    rd!-solve!-hardcase!-print(lev,il1);
  loop:
    if null il1 then goto bottom;
    iv :=car il1; il1:= cdr il1;
    l:=caar iv; fl:=cdar iv; u:=cadr iv; fu:=cddr iv;
    if (d:=u-l) <0 then goto loop; %empty
    if abs fl<acc then<<pt:=l;goto root_found>>;
    if abs fu<acc then<<pt:=u;goto root_found>>;
    b:=dmboundsuni(de,x,l,u);
      % left boundary of interval
    if (fl>0 and not((b1:=car b)<0))
     or(fl<0 and not((b1:=cdr b)>0))
     or not((pt:=l-fl/b1)<u)  then goto loop;
    if pt=l then goto precerr;
    q:=evaluateuni(e,x,pt);
    if not all and q*fl<0 then return regula!-falsi(e,x,l,fl,pt,q,acc);
    if abs q<acc then goto root_found;
    l:=pt; fl:=q;
      % right boundary of interval
    if (fu>0 and not((b1:=cdr b)>0))
     or(fu<0 and not((b1:=car b)<0))
     or not((pt:=u-fu/b1)>l) then goto loop;
    if pt=u then goto precerr;
    q:=evaluateuni(e,x,pt);
    if not all and q*fu<0 then return regula!-falsi(e,x,pt,q,u,fu,acc);
    if abs q<acc then goto root_found;
    u:=pt; fu:=q;
      % new point
    pt :=(l+u)/2;  %midpoint
    q:=evaluateuni(e,x,pt);
    if not all and q*fu<0 then return regula!-falsi(e,x,l,fl,pt,q,acc);
       % generate new intervals
    if not(abs q<acc) then
     <<il2 :=find!-root!-addinterval(pt.q,u.fu,
               find!-root!-addinterval(l.fl,pt.q,il2));
       goto loop;
     >>;
  root_found:
    r:=pt.r; if not all then goto done;
    rr:=find!-root!-range(e,x,pt,acc);
    il2 :=find!-root!-addinterval(cdr rr,u.fu ,
               find!-root!-addinterval(l.fl,car rr,il2));
    goto loop;
  bottom:
    il1 :=il2;
    goto main_loop;
  done:
    r:=sort(r,function lessp);
    return make!-rdsolve!-result1(x,r);
  precerr:
    rederr "precision not sufficient for finding all roots";
  end;

symbolic procedure rd!-solve!-hardcase!-print(lev,il1);
 if !*trnumeric then
 << prin2t {"recursion level:",lev,"remaining intervals:",length il1};
    writepri( mkquote( 'list.
           for each i in il1 collect
             {'list,{'!*interval!*,prepf caar i,prepf cadr i},
                               dm!: prepf(cadr i-caar i)}),
            'only);
 >>;

symbolic procedure find!-root!-addinterval(l,h,il);
 dm!:  <<if car l < car h then il:=(l.h).il; il>>;

symbolic procedure find!-root!-range(e,x,p,acc);
  % p is a point in (l .. u) where abs e(x)<acc.
  % Find the next interval where e(x) > acc.
dm!:<<
     while not(abs(fl:=evaluateuni(e,x,pl:=pl-acc/2))>acc) do;
     while not(abs(fu:=evaluateuni(e,x,pu:=pu+acc/2))>acc) do;
     (pl.fl).(pu.fu)
    >> where pl=p,pu=p,fl=nil,fu:=nil;

if errorp errorset('(!:difference nil nil),nil,nil) then
<<
symbolic procedure !:difference(u,v);
   if null u then !:minus v else if null v then u
    else if u=v then nil
    else if atom u and atom v then u-v
    else dcombine(u,v,'difference);

symbolic procedure !:quotient(u,v);
   if null u or u=0 then nil
    else if null v or v=0 then rerror(poly,12,"Zero divisor")
    else if atom u and atom v
     % We might also check that remainder is zero in integer case.
     then if null dmode!* then u/v else dcombine(u,!:recip v,'times)
    else dcombine(u,v,'quotient);

>>;

endmodule;


module gauss;  % Solve linear system.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1994, all rights resrved

fluid '(!*noequiv accuracy!* !*exptexpand);
global '(iterations!* !*trnumeric erfg!*);

put('igetv,'setqfn,'(lambda (v i x) (iputv v i x)));

smacro procedure s(i,j); igetv(igetv(m,i),j);

symbolic procedure rdsolvelin (u,b);
     % U is a n*n matrix with numbers;
     % b is a righthand side. Result is a vector of solutions.
     % Gaussian elimination with partial pivoting.
  begin integer n,n1,k; scalar m,w,r,x,y,err;
    n:=length b; n1:=n#+1;
      % establish system matrix.
    m:=mkvect(n#+1); r:=mkvect(n#+1);
    for i:=1:n do
    <<w:=mkvect(n#+2);
      for j:=1:n do iputv(w,j,nth(nth(u,i),j));
      iputv(w,n1,nth(b,i));
      iputv(m,i,w);
    >>;
      % elimination loop.
    for i:=1:n-1 do if not err then
    << % pivot search
      x:=dm!: abs s(i,i); k:=i;
      for j:=i+1:n do dm!:
      dm!: if (y:=abs s(j,i))>x then <<x:=y; k:=j>>;
      if i neq k then
      <<y:=igetv(m,i); iputv(m,i,igetv(m,k)); iputv(m,k,y)>>;
        % row elimination
      if null s(i,i) then err:=t
      else
      <<x:=dm!: (1/s(i,i));
        for j:=i+1:n do
        <<y:=dm!:(s(j,i)*x);
          for k:=i:n1 do s(j,k):=dm!:(s(j,k) - y*s(i,k));
      >>>>;
     >>;

      % backsubstitution.
     for i:=n step -1 until 1 do if not err then
     <<w:=s(i,n1);
       for j:=i#+1 : n do
        dm!:(w:=w-s(i,j)*igetv(r,j));
       if null s(i,i) then err :=t else
         iputv(r,i,dm!:(w/s(i,i)));
     >>;

     return if err then nil else for i:=1:n collect igetv(r,i);
   end;

remprop('s,'smacro);
remprop('s,'number!-of!-args);

endmodule;


module newton;  % root finding with generalized Newton methods.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1992, all rights resrved
% Version 2: termination and damping criterion modified to affine
%            invariance.
% Nov. 94:   Avoid symbolic inversion of Jacobian.

fluid '(!*noequiv accuracy!* !*invjacobi);
global '(iterations!* !*trnumeric erfg!*);


symbolic procedure rdnewton0(e,vars,p,n);
    %preparations for Newton iteration.
 (begin scalar jac,x,oldmode,!*noequiv;
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
         reval list('df,nth(e,i),nth(vars,j)));
    if !*trnumeric and !*invjacobi
      then lprim "inverting symbolic Jacobian";
    jac := cdr reval
      if !*invjacobi then '(quotient 1 jacobian) else 'jacobian;
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
  end) where !*roundbf=!*roundbf;

symbolic procedure rdnewton1(f,jac,vars,x,mode);
  begin scalar r,acc;
     if !*trnumeric then lprim "starting Newton iteration";
     acc := !:!:quotient(1,expt(10,accuracy!*));
     r:= rdnewton2(f,jac,vars,acc,x,mode,nil,nil);
     r:= for each x in r collect prepf x;
     return r;
 end;

symbolic procedure rdnewton2(f,jac,vars,acc,x,mode,low,high);
  % Algorithm for finding the root function system f
  % with technique of adaptively damped Newton.
  % f:     function to minimize (list of algebraic exprs);
  % jac:   Jacobian, symbolically inverted if *invjacobi is t;

  % vars:  variables (list of id's);
  % acc:   requested accuracy (e.g. 0.0000001)
  % x:     starting point (list of domain elements).
 dm!:
  begin scalar n0,n1,e0,e1,dx,dx2,x1,g,dmp,delta,h;
        scalar dxold,dx2old,dmpold;
    integer count;
    e0 := list!-evaluate(f,vars,x);
  loop:
    count:=add1 count;
    if count>iterations!* then
    <<lprim "requested accuracy not reached within iteration limit";
      goto ready>>;

      % evaluate Jacobian.
    g := matrix!-evaluate(jac,vars,x);
      % the newton step.
    dx := if !*invjacobi then mat!*list(g,e0) else rdsolvelin(g,e0);
    if null dx then goto jacerr;
    n0 := normlist dx;
    dmp:= 1;

  step:
      % evaluate function at new point.
    x1 := list!-list(x, scal!*list(dmp,dx));
    e1 := errorset({'list!-evaluate,mkquote f,
              mkquote vars,mkquote x1},nil,nil)
                       where !*msg=nil,!*protfg=t;;
    if errorp e1 then goto contract else e1 := car e1;

        % anticipated next (simplified) Newton step.
    dx2:=if !*invjacobi then mat!*list(g,e1) else rdsolvelin(g,e1);
    if null dx2 then goto contract;
    n1 := normlist(dx2);
    if n1=0 or n1<n0 then goto accept;
    if null dmpold then goto contract;

       % predict optimal damping factor
    h:= dmpold *(normlist list!-list(dx2old,dx) * normlist(dx))
        / (normlist(dxold) * normlist(dx2old));
    if h>1 then
    << dmp:=if h<10 then 1/h else 1/10;
       dmpold := nil; goto step>>;

  contract:
    dmp:=dmp/2;
    if dmp<acc then rederr "Newton method does not converge";
    goto step;

  accept:
    delta:=dmp*n0;
    x := x1; e0:=e1; n0:=n1;
    if low and high and (low>car x or high<car x) then return nil;
    dmpold := dmp; dxold := dx; dx2old := dx2;
    rdnewtonprintpoint(count,x,delta,e0);
    if n1>acc or dmp<1 then<<update!-precision(delta.e0); goto loop>>;

  ready:
    x := list!-list(x,dx2);
    return x;

  jacerr: rederr "singular Jacobian";
  end;

symbolic procedure rdnewtonprintpoint(count,x,dx,e0);
  if !*trnumeric then
   begin
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
    {oldmode,precision 0,!*roundbf}>>
  else % reset to old dmode.
    <<if car oldmode then setdmode('rounded,nil);
      precision cadr oldmode;
      !*roundbf:=caddr oldmode>>;

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
  % x:     starting point (list of numerical standard forms).
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

fluid '(boundsdb!* !*msg boundspolynomialdb!*
       !*boundsfullcheck boundsknown!* boundsvars!*);

symbolic procedure boundsevalrd u;
   begin scalar dmode!*;
     setdmode('rounded,t);
     return boundseval u;
   end;

symbolic procedure boundseval u;
 (begin scalar db,y,l,f, boundsvars!*;
    u := for each x in u collect reval x;
    f := car u; u := cdr u;
    if u and eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
    <<if not eqcar(x,'equal) then typerr(x,"domain description");
      y := revalnuminterval(caddr x,nil);
      l:=list(simp car y,simp cadr y);
      boundsvars!*:=append(boundsvars!*,{cadr x});
      db := (cadr x . minsq l . maxsq l).db>>;
    u := boundseval1(f,db);
    return mkinterval(prepsq car u,prepsq cdr u);
  end) where !*roundbf=!*roundbf;

symbolic procedure boundserr(a,b);
    if not !*msg then error(99,'bounds) else
    if a then typerr(a,b) else rederr b;

symbolic procedure boundseval0 (f,db,!*msg);
  % internal calling convention:
  %  f            algebraic expression,
  %  db           list of (x . lo . hi), where
  %               lo and hi represent the current interval for
  %               variable x as standard quotients.
  %  result is a pair of standard quotients representing
  %               the bounds for f.
   <<boundsvars!*:=for each x in db collect car x;
     boundseval1(f,db)>>;

symbolic procedure boundseval1(u,boundsdb!*);
    <<if u member boundsknown!* then !*boundsfullcheck := nil else
      << !*boundsfullcheck := t;
        if dmode!* = '!:rd!: then boundsknown!* := u.boundsknown!*;
      >>;
      boundseval2 u>>;

symbolic procedure boundseval2 u;
  % Main driver for bounds evaluation
  if adomainp u then <<u:=simp u;u.u>> else
  boundspolynomial u or
  begin scalar v,w,fcn;
    if (v:=assoc(u,boundsdb!*))then return cdr v;
    if idp u and (fcn:=get(u,dmode!*)) then
      <<v:=apply(fcn,nil); v:=(v ./1).(v ./1); goto done>>;
    if atom u then goto err;
    if car u='expt and fixp caddr u and caddr u>0 then
    <<v:=boundsexpt!-int(boundseval2 cadr u,caddr u);
      goto done>>;
    w := for each y in cdr u collect boundseval2 y;
    v:= if cdr w and cddr w and (fcn:=get(car u,'boundsevaln))
           then apply1(fcn,w)
         else if length w>2 then t
         else if (fcn:=get(car u,'boundseval1))
          then apply2(fcn,car u,car w)
         else if (fcn:=get(car u,'boundseval))
          then if null cdr w then apply1(fcn,car w)
                else apply2(fcn,car w,cadr w)
         else if cdr w then t
         else boundsoperator(car u,car w);
    if v=t then goto err2;
    if null v or
       not domainp numr car v or not domainp denr car v or
       not domainp numr cdr v or not domainp denr cdr v then goto err;
     % cache result for later usage.
  done:
    boundsdb!*:= (u.v).boundsdb!*;
    return v;
err: boundserr(nil,"unbounded in range");
err2: boundserr(nil,"bounds confusion");
  end;

symbolic procedure boundsoperator(fcn,u);
  % general external interface: function flagged decreasing,
  % increasing of explicit bounds given.
   if flagp(fcn,'increasing) then boundsincreasingfn(fcn,u) else
   if flagp(fcn,'decreasing) then boundsdecreasingfn(fcn,u) else
   if get(fcn,'upperbound) and get(fcn,'lowerbound) then
       simp get(fcn,'lowerbound) . simp get(fcn,'upperbound)
    else nil;

symbolic procedure boundsplus u;
   if null cdr u then car u else
   boundsplus2(car u,boundsplus cdr u);

symbolic procedure boundsplus2(u,v);
    addsq(car u,car v) . addsq(cdr u,cdr v);

put('plus,'boundsevaln,'boundsplus);
put('plus,'boundseval,'boundsplus2);

symbolic procedure boundsdifference(x,y);
   subtrsq(car x,cdr y).subtrsq(cdr x,car y);

put('difference,'boundseval,'boundsdifference);

symbolic procedure boundsminus(u);
   negsq cdr u . negsq car u;

put('minus,'boundseval,'boundsminus);

symbolic procedure boundstimes u;
   if null cdr u then car u else
    boundstimes2(car u,boundstimes cdr u);

symbolic procedure boundstimes2(x,y);
  begin scalar z;
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
  begin scalar x;
   x := car l;
   for each y in cdr l do
    if minusf numr subtrsq(y,x) then x:=y;
   return x;
  end;

symbolic procedure maxsq l;
  begin scalar x;
   x:= car l;
   for each y in cdr l do
    if minusf numr subtrsq(x,y) then x:=y;
   return x;
  end;

symbolic procedure sqgreaterp(x,y);
     minusf numr subtrsq(y,x);

put('times,'boundsevaln,'boundstimes);
put('times,'boundseval,'boundstimes2);

symbolic procedure boundsexp u;
   boundsexpt(b . b,u) where b = simp 'e;

put('exp,'boundseval,'boundsexp);

symbolic procedure boundsexpt!-int(b,ex);
  % Form x ** n. Look for even exponents.
  begin scalar hi,lo,bh,bl;
    bl := exptsq(car b,ex); bh := exptsq(cdr b,ex);
    if not evenp ex then return bl.bh;
    lo := minusf numr cdr b;
    hi := not minusf numr car b;
    return
        if hi then bl.bh else  % both had been positive
        if lo then bh.bl else  % both had been negative: invert
             (nil ./ 1) . maxsq list(bl,bh);
   end;

symbolic procedure boundsexpt!-const(b,ex);
  % Form x ** constant, including fractional exponents.
  begin scalar l,n,m;
    n := '(nil . 1);
    if sqgreaterp(n,ex) then
        return boundsquotient('(1 . 1),boundsexpt!-const(b,negsq ex));
    if denr ex = 1 and
      (fixp(m:=numr ex)
         or eqcar(m,'!:rd!:)
            and null addf(numr ex,negf(m := reval{'round,m})))
           then return boundsexpt!-int(b,m);
    if sqgreaterp(n,car b) then
        boundserr(nil,"fractional exponent with negative base");
    l := list(bounds!-evalfcn2('expt,car b,ex),
              bounds!-evalfcn2('expt,cdr b,ex));
    return minsq l . maxsq l;
  end;

symbolic procedure boundsexpt(b,e);
   if car e=cdr e then boundsexpt!-const(b,car e) else
  % Form x ** y. x>0 only.
  % Either monotonous growing or falling: pick extremal points.
  begin scalar l,n;
    n:='(nil . 1);
    if sqgreaterp(n,car b) then return nil;
    l := list(bounds!-evalfcn2('expt,car b,car e),
              bounds!-evalfcn2('expt,car b,cdr e),
              bounds!-evalfcn2('expt,cdr b,car e),
              bounds!-evalfcn2('expt,cdr b,cdr e));
    return minsq l . maxsq l;
  end;

symbolic procedure boundsprepsq u; prepsq car u . prepsq cdr u;

put('expt,'boundseval,'boundsexpt);

symbolic procedure boundsquotient(n,d);
  begin scalar l;
    if boundszero d then boundserr(nil,"unbounded in range");
    l := list(quotsq(car n,car d),quotsq(car n,cdr d),
              quotsq(cdr n,car d),quotsq(cdr n,cdr d));
    return minsq l . maxsq l;
  end;

symbolic procedure boundszero u;
  % test: 0 in interval u.
   not(minusf numr car u = minusf numr cdr u) or
   boundszero1 numr car u or boundszero1 numr cdr u;

symbolic procedure boundszero1 f;
  % test standard form f for zero.
   null f or zerop f or pairp f and apply(get(car f,'zerop),{f});

put('quotient,'boundseval,'boundsquotient);

symbolic procedure boundsabs u;
 if evalgreaterp(prepsq car u,0) then u else
 if evalgreaterp(0,prepsq cdr u) then negsq cdr u . negsq car u else
  (nil ./1) . maxsq list (negsq car u,cdr u);

put('abs,'boundseval,'boundsabs);

symbolic procedure boundsincreasingfn(fn,u);
  % Bounds for an increasing function. Out-of -range problems will
  % be detected either by the function evaluation or finally by
  % the main driver if the result is not an interval with numeric
  % bounds.
  bounds!-evalfcn1(fn,car u) . bounds!-evalfcn1(fn,cdr u);

put('log,'boundseval1,'boundsincreasingfn);
put('asin,'boundseval1,'boundsincreasingfn);
put('atan,'boundseval1,'boundsincreasingfn);
put('sqrt,'boundseval1,'boundsincreasingfn);

symbolic procedure boundsdecreasingfn(fn,u);
       boundsincreasingfn(fn,cdr u.car u);

put('acos,'boundseval1,'boundsdecreasingfn);
put('acot,'boundseval1,'boundsdecreasingfn);

symbolic procedure boundssincos(fcn,n);
   % Reason if one of the turn points (n*pi) is in the
   % range. If yes, include the corresponding value 1 or -1.
   % Otherwise compute the range spanned by the end points.
  begin scalar lo,hi,!1pi,!2pi,!3pi,l,m;
     lo := car n; hi := cdr n;
     <<setdmode('rounded,t);
       !1pi := simp 'pi;
       setdmode('rounded,nil);
     >> where dmode!* =nil;
     if not domainp numr !1pi then goto trivial;
     !2pi := addsq(!1pi,!1pi); !3pi := addsq(!1pi,!2pi);
       % convert sin to cos
     if fcn = 'sin then <<m :=multsq(!1pi, -1 ./ 2);
         lo := addsq(lo,m); hi := addsq(hi,m)>>;
     m := negsq multsq(!2pi,fixsq quotsq(lo,!2pi));
       % move interval to main interval
     lo:=addsq(lo,m); hi:=addsq(hi,m);
     if minusf numr lo then
     <<lo := addsq(lo,!2pi); hi := addsq(hi,!2pi)>>;
     if null numr lo or sqgreaterp(hi,!2pi) then l:= (1 ./ 1) . l;
     if (sqgreaterp(!1pi,lo) and  sqgreaterp(hi,!1pi))
      or(sqgreaterp(!3pi,lo) and  sqgreaterp(hi,!3pi))
       then l := (-1 ./ 1) . l;
     if l and cdr l then goto trivial;
     l:=bounds!-evalfcn1('cos,lo) .bounds!-evalfcn1('cos,hi).l;
     if smemq('cos,l) then goto trivial;
     return minsq l . maxsq l;
 trivial:
     return ((-1)./1) . (1 ./ 1);
  end;

symbolic procedure fixsq u;
         bounds!-evalfcn1('fix,u);

symbolic procedure bounds!-evalfcn1(fcn,u);
   (if domainp numr u and denr u=1
         and (x:=valuechk(fcn,list numr u))
     then x else simp list(fcn,prepsq u)) where x=nil;

symbolic procedure bounds!-evalfcn2(fcn,u,v);
   (if domainp numr u and denr u=1 and
       domainp numr v and denr v=1
         and (x:=valuechk(fcn,list(numr u,numr v)))
     then x else simp list(fcn,prepsq u,prepsq v)) where x=nil;

symbolic procedure agreaterp(u,v);
   (lambda x;
    if not atom denr x or not domainp numr x
      then error(99,"number")
     else numr x and !:minusp numr x)
        simp!* list('difference,v,u);

symbolic procedure boundssin u;
       boundssincos('sin,u);

symbolic procedure boundscos u;
       boundssincos('cos,u);

put('sin,'boundseval,'boundssin);
put('cos,'boundseval,'boundscos);

symbolic procedure boundstancot(fcn,n);
  begin scalar lo,hi,x,ppi;
     lo := car n; hi := cdr n;
     ppi := rdpi!*() ./ 1;
     if sqgreaterp(subtrsq(lo,hi),ppi) then goto no;
     lo:=bounds!-evalfcn1(fcn,lo);
     hi:=bounds!-evalfcn1(fcn,hi);
     if fcn='cot then <<x:=lo;lo:=hi;hi:=x>>;
     if not sqgreaterp(lo,hi) then return lo.hi;
no:  return boundserr(nil,"unbounded in range");
  end;


symbolic procedure boundstan u;
    boundstancot('tan,u);

symbolic procedure boundscot u;
    boundstancot('cot,u);

put('tan,'boundseval,'boundstan);
put('cot,'boundseval,'boundscot);

symbolic procedure boundsmaxmin u;
  if null cdr u then car u else
       boundsmaxmin2(car u,boundsmaxmin cdr u);

symbolic procedure boundsmaxmin2(x,y);
  (if sqgreaterp(car x,car y) then car y else car x).
  (if sqgreaterp(cdr x,cdr y) then cdr x else cdr y);

put('max,'boundsevaln,'boundsmaxmin);
put('min,'boundsevaln,'boundsmaxmin);
put('max,'boundseval,'boundsmaxmin2);
put('min,'boundseval,'boundsmaxmin2);

% for univariate polynomials we look at the extremal points and the
% interval ends. Assuming that the same expression will be investigated
% with different intervals, we store the knowledge about the polynomial.

symbolic procedure boundspolynomial e;
 dm!: begin scalar x,u,lo,hi,d,v,l;
    if dmode!* neq '!:rd!: then return nil;
    if(u:=assoc(e,boundspolynomialdb!*)) then goto old;
    if null !*boundsfullcheck or
       null(x:=boundspolynomialtest e) then return nil;
    d := realroots{reval{'df,e,x}};
    u := x. for each s in cdr d collect
      <<d:=numr simp caddr s;
        d . evaluate(e,{x},{d})>>;
    u:=e.u;
    boundspolynomialdb!*:=u.boundspolynomialdb!*;
 old:
    x:=cadr u; u :=cddr u;
    v := assoc(x,boundsdb!*);
    if null v then return nil;
    lo:=numr cadr v; hi:=numr cddr v;
    l:={evaluate(e,{x},{lo})./1 , evaluate(e,{x},{hi}) ./1};
    for each p in u do
      if lo<car p and car p<hi then l:= (cdr p./1).l;
    return minsq l . maxsq l;
  end;

symbolic procedure boundspolynomialtest e;
 (pairp r and car r) where r=boundspolynomialtest1(e,nil);

symbolic procedure boundspolynomialtest1(e,x);
   if adomainp e then x or t else
   if atom e then boundspolynomialtestvariable(e,x) else
   if car e eq 'expt then
       fixp caddr e and
          boundspolynomialtestvariable(cadr e,x)
      else
   if car e eq 'minus then boundspolynomialtest1(cadr e,x)
      else
   if car e  eq 'plus or car e eq 'times then
    begin scalar r;
      e:=cdr e; r:=t;
      while e and r do
      <<r:=boundspolynomialtest1(car e,x);
        if r neq t then x:=r; e:=cdr e>>;
      return x or r;
    end
      else boundspolynomialtestvariable(e,x);

symbolic procedure boundspolynomialtestvariable(e,x);
  if x and e=car x then x else
  if x then nil else
  if member(e, boundsvars!*) then {e};

%--------------------------------------------------------------
%
% support for compilation
%
%--------------------------------------------------------------

fluid '(boundsdb!* boundscompv!* boundscompcode!*);

symbolic procedure boundscompile(e,v);
  % compile bounds evaluation function for expression e,
  % input intervals v.
  begin scalar boundsdb!*,boundscompv!*,boundscompcode!*,u;
    boundsdb!*:=for each x in v collect x.x;
    u:=boundscompile1(e,nil);
    return
     {'lambda,v,
      'prog . boundscompv!* .
         append(reversip boundscompcode!*,{{'return,u}})};
  end;

symbolic procedure boundscompile1(u,flag);
  % Main driver for bounds compilation
  if adomainp u then <<u:=simp u;mkquote(u.u)>> else
  begin scalar v,w,fcn,var;
    if (v:=assoc(u,boundsdb!*))then return cdr v;
    if idp u and (fcn:=get(u,dmode!*)) then
      <<v:=apply(fcn,nil); v:=mkquote((v ./1).(v ./1)); goto done>>;
    if atom u then goto err1;
    if car u='expt and fixp caddr u and caddr u>0 then
    <<v:={'boundsexpt!-int,boundscompile1(cadr u,t),caddr u};
      goto done>>;
    w := for each y in cdr u collect boundscompile1(y,t);
    v:= if length w>2 and (fcn:=get(car u,'boundsevaln))
              then {fcn,'list.w} else
        if length w>2 then t else
        if (fcn:=get(car u,'boundseval1))
               then {fcn,mkquote car u,car w} else
        if (fcn:=get(car u,'boundseval))
               then if null cdr w then {fcn,car w}
                     else {fcn,car w,cadr w}
         else if cdr w then t
         else {'boundsoperator,car u,car w};
  done:
    if v=t then goto err2;
    if not flag then return v;
    var:=gensym(); boundscompv!* := var.boundscompv!*;
    boundscompcode!*:={'setq,var,v}.boundscompcode!*;
     % cache result for later usage.
    boundsdb!*:= (u.var).boundsdb!*;
    return var;
err1: typerr(u,"bounded value");
err2: typerr(u,"expression to be compiled for bounds");
  end;

endmodule;


module numint; % compute a numerical integral

% Author: H. Melenk,

     % Version March 1993

     % strategy for univariate integrals:
     %
     % 1. look for exact antiderivative, use that if it is
     %          bounded in the interval,
     %
     % 2. try Chebyshev fit,
     %
     % 3. use M. Wulkow's adaptive multilevel quadrature.

fluid '(!*noequiv accuracy!* singularities!*);
global '(iterations!* !*trnumeric);

symbolic procedure intrdeval u;
     % Interface function.
  begin scalar e,vars,y,p,singularities!*,imode,r,protfg!*,
          m,w;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,3,20);
    e :=car u; u :=cdr u;
      % variables and interval's.
    % Allow for int(f,x,low,upp).
    if length u = 3 and (atom car u or not(caar u eq 'equal))
      then u := {{'equal,car u,'!*interval!* . cdr u}}
     else if eqcar(car u,'list) then
      u := for each x in cdar u collect reval x;
    for each x in u do
     <<if not eqcar(x,'equal) then typerr(x,"interval bounds");
       imode := 'infinity;
       if not !*rounded then setdmode('rounded,w:=!*rounded:=t);
       y:=revalnuminterval(caddr x,imode);
       if w then setdmode('rounded,w:=!*rounded:=nil);
       imode := t; % inf only for univariate cases.
       vars:=cadr x.vars;
       p:=(cadr x. car y. cadr y).p>>;
    m:=!*msg;
    if !*trnumeric then !*msg:=nil else protfg!* := t;
    r:= intrd0(e,vars,p);
    erfg!* := nil; !*msg:=m;
    r:=reval r where dmode!* = '!:rd!:;
    return r;
  end;

put('num_int,'psopfn,'intrdeval);

symbolic procedure intrd0 (e,vars,p);
  if cdr vars then intrd2(e,vars,p) else
     % Univariate case.
   begin scalar fcn,x,lo,hi;
    fcn := e;
    x := car vars;
    lo := car cdar p; hi := cdr cdar p;
    return intrd1(fcn,x,lo,hi,0);
  end;

symbolic procedure intrd1(fcn,x,lo,hi,n);
 % Recursively decompose infinite intervals; map -inf to +inf;
 % transform integral over [a,inf] to integral over [0,1].
   begin scalar w,r1,r2,res;
    n := n+1;
    if !*trnumeric then
    <<writepri(n,'first); writepri(" level integrate :",nil);
      writepri(mkquote fcn,nil); writepri(" over ",nil);
      writepri(mkquote mkinterval(lo,hi),'last);
    >>;
    if evalgreaterpx(lo,hi) then
    <<w:=lo;lo:=hi;hi:=w;fcn:={'minus,fcn}>>;

     % Map infinite intervals to finite ones.

     % case 1: [-inf,hi]

    if lo=minus!-infinity!* then
     if evalgreaterpx(hi,-1) then

     << % case 1.1: hi>-1 : [-inf,-1] + [-1,hi]
       r1 := intrd1(fcn,x,-1,hi,n);
       r2 := intrd1(subst({'minus,x},x,fcn),x,1,'infinity,n);
       res := reval {'plus,r1,r2};
     >> else

     << % case 1.2: hi <= -1
        res:= intrd1(subst({'minus,x},x,fcn),
                x,reval{'minus,lo},'infinity,n);
     >>;

     if res then goto fin;

     % case 2: [low .. inf] with -inf < low
    if hi='infinity then
     if evalgreaterpx(1,lo) then

     << % case 2.1: lo < 1: [lo,1] + [1,inf]
       r1 := intrd1(fcn,x,lo,1,n);
       r2 := intrd1(inttrans(fcn,1,x),x,0,1,n);
       res:= reval {'plus,r1,r2};
     >> else

     << % case 2.2: 1<=lo
        res := intrd1(inttrans(fcn,lo,x),x,0,1,n);
     >>;

     if res then goto fin;

     % case 3: finite interval
    res := intrd1a(fcn,x,lo,hi,{x.lo.hi});

 fin:
    if !*trnumeric then
    <<writepri(n,'first); writepri(" level integral :",nil);
      writepri(mkquote res,'last)>>;
    return res;
   end;

symbolic procedure inttrans(u,a,x);
  reval inttrans1(u,a,x);

algebraic procedure inttrans1(u,a,x);
  % Transform function to integrate. The transformation
  % maps integral over [a,inf] to [0,1] when a > 0.
  % Here used only for a>1.
  <<u:=sub(x=a/(1-!&t),u)*a /(a-!&t)^2;
    sub(!&t=x,u)>>;

symbolic procedure intrd1a(fcn,x,lo,hi,p);
   begin scalar u,w,acc,uu,loo,hii,oldmode,cbound;
     integer ord;
    if evalgreaterp(hi,lo) then <<loo:=lo; hii:=hi>>
      else <<loo:=hi; hii:=loo>>;
     % first attempt: look for bounded antiderivative.
    u := reval{'int,reval fcn,x} where dmode!*=nil,!*rounded=nil;
    oldmode:=switch!-mode!-rd nil;
    w:= errorset(
        {'boundseval,mkquote{u, {'equal,x,{'!*interval!*, loo, hii}}}},
                             nil,nil) where !*msg=nil;
    switch!-mode!-rd oldmode;

    if not smemq('int,u) and not errorp w then
      <<
        if !*trnumeric then prin2t "Using bounded antiderivative";
        oldmode:=switch!-mode!-rd nil;
        u:=simp u;
        w:= prepsq subtrsq(subsq(u,{x . hi}),subsq(u,{x . lo}));
        switch!-mode!-rd oldmode;
        return w;
      >>;
    if !*trnumeric then prin2t "No bounded antiderivative found";

    % second attempt: look for a Chebyshev fit.
    w := nil;
    oldmode:=switch!-mode!-rd nil;
    acc := !:!:quotient(1,expt(10,accuracy!*));
    cbound := dm!: (acc /(hii - loo));
    ord := 20;
  chebloop:
    u := chebcoeffs(fcn,x,loo,hii,ord);
    uu := reverse u;
    if int!-chebconverges(uu,acc,cbound) then
    <<
      u:=chebint(u,nil,loo,hii);
      w:=aeval{'difference,chebeval(u,nil,loo,hii,hi),
                           chebeval(u,nil,loo,hii,lo)};
    >>;
    if null w and ord<60 then <<ord:=ord+20; goto chebloop>>;
    switch!-mode!-rd oldmode;
    if w then
    <<if !*trnumeric then
       << prin2 "Using Chebyshev approximation of order ";
          prin2t ord>>;
      return w;
    >>;
    if !*trnumeric then
    <<
       prin2t "No usable Chebyshev approximation found";
       prin2t "Starting adaptive multilevel quadrature";
    >>;
    return intrd2 (fcn,{x.lo.hi},p);
  end;

symbolic procedure int!-chebconverges(u,acc,ab);
  % Test the (reverse) Chebyshev coefficients u for convergence.
  % acc: current accuracy (epsilon), ab: absolute upper bound for
  % trailing coefficient(s).
  begin scalar mx;
    mx := int!-chebmax(u,nil);
    dm!:(mx := mx*acc);
    return dm!:(abs car u < mx
        and abs cadr u < mx and abs caddr u < mx
        and abs car u < ab and abs cadr u < ab
        and abs caddr u < ab);
  end;

symbolic procedure  int!-chebmax(u,mx);
   if null u then mx else
   int!-chebmax(cdr u,if dm!:(w>mx) then w else mx)
          where w=dm!: abs car u;


% ----------------- adaptive multilevel quadrature

symbolic procedure intrd2 (e,vars,p);
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
  begin scalar lo,hi,x,u,eps,i,il,int;
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
  begin scalar vars,u,eps,i,il,int;
     integer n,k,dim;
    if smemq('infinity,p) then
      rederr "no support for infinity in multivariate integrals";
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
   begin scalar vol,vars,il,lo,hi,x,y;
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
    r:=rdsolveeval
       list (grad,'list . for each p in pars collect list('equal,p,0),
                  {'equal,'accuracy,accuracy!*},
                  {'equal,'iterations,iterations!*});
      % resubstitute into target function.
    if !*trnumeric then lprim "resubstituting in approximating form";
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


module chebysh;  % Chebyshev approximation.
   % Literature: Press, Flannery, Teukolski, Vetterling: Numerical
   %                Recipes, Cambridge University Press.

% Author: Herbert Melenk

% Copyright (c) 1993 ZIB Berlin, RAND.  All rights reserved.

put('chebyshev_fit,'psopfn,'(lambda(u)(chebysheveval u 'fit)));
put('chebyshev_eval,'psopfn,'(lambda(u)(chebysheveval u 'eval)));
put('chebyshev_int,'psopfn,'(lambda(u)(chebysheveval u 'int)));
put('chebyshev_df,'psopfn,'(lambda(u)(chebysheveval u 'df)));

symbolic procedure chebysheveval(u,mode);
     % interface function;
  begin scalar w,x,c,e,l,y,p,r,oldmode;
        integer n;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,3,20);
    e :=car u; u :=cdr u;
      % variable and interval.
    w := car u;
    if not eqcar(w,'equal) then typerr(w,"interval bounds");
    oldmode:=switch!-mode!-rd nil;
    y:=revalnuminterval(caddr w,t);
    x:=cadr w;
    if mode = 'fit then
    <<
       n:=if cdr u then ieval cadr u else 20;
       c := chebcoeffs(e,x,car y,cadr y,n);
       r:= {'list,
            chebpol(c,x,car y,cadr y),
            'list . c}; %  for each q in c collect prepf q};
    >>
    else if mode = 'eval then
    <<
       if null cdr u or not eqcar(cadr u,'equal) then
          rederr("Chebyshev_eval: point missing");
       e:=cdr listeval(e,t);
       w:=numr simp caddr cadr u;
       r:= prepf chebeval(e,x,car y,cadr y,w);
    >>
   else if mode = 'int or mode = 'df then
    <<
       e:=cdr listeval(e,t);
       r:= if mode ='int then
                chebint(e,x,car y,cadr y)
           else chebdf (e,x,car y,cadr y);
       r:='list . for each q in r collect prepf q;
    >>;
    switch!-mode!-rd oldmode;
    return r;
  end;

symbolic procedure chebcoeffs(func,x,a,b,n);
  begin
        integer k,j,n1;
        scalar fac,bpa,bma,f,!1pi,c,y,su,nn,half,w;

    x:={x};
    !1pi := rdpi!*();
    nn := dm!:(1/n);
    n1 := n-1;
    half := dm!:(1/2);

     dm!: <<bma:=(b-a)/2; bpa:=(b+a)/2>>;
     w := dm!:(!1pi*nn);
     f:=for k:=0:n1 collect
     <<y := dm!: (rdcos!*(w*(k+half))*bma+bpa);
           evaluate(func,x,{y})
     >>;

     dm!: <<fac:=2*nn>>;
     c:=for j:=0:n1 collect
     <<
        w:= dm!:(!1pi*j*nn);
        su:=nil;
        for k:=0:n1 do
          dm!:(su := su+nth(f,iadd1 k) *rdcos!*(w*(k+half)));
        dm!: (fac*su)
     >>;
    return c;
  end;

symbolic procedure chebpol(c,x,a,b);
  begin scalar d,dd,sv,fac,cnst;
        integer n;
    n:=length c;
    d:=for i:=1:n collect nil;
    dd:=for i:=1:n collect nil;
    car dd := nth(c,n);
    for j:=(n-2) step -1 until 1 do
    <<
      for k:=(n-j) step -1 until 1 do
       << sv := nth(d,k+1);
          nth(d,k+1) := dm!:(2*nth(d,k) - nth(dd,add1 k));
          nth(dd,k+1) := sv
       >>;
      sv:=car d;
      car d := dm!:(- car dd + nth(c,add1 j));
      car dd := sv;
    >>;
    for j:=(n-1) step -1 until 1 do
       nth(d,j+1) := dm!:(nth(d,j) - nth(dd,add1 j));
    car d := dm!:(-car dd + car c/2);

    cnst:=dm!:(2/(b-a));
    fac :=cnst;
    for j:=1:(n-1) do
     <<nth(d,add1 j) := dm!:(nth(d,add1 j) * fac);
       fac := dm!:(fac*cnst);
     >>;
    cnst:=dm!:((a+b)/2);
    for j:=0:(n-2) do
      for k:=(n-2) step -1 until j do
        nth(d,add1 k) := dm!:(nth(d,add1 k) - cnst*nth(d,add1 add1 k));

    return reval ('plus. for i:=1:n collect
      {'times,nth(d,i),{'expt,x,i-1}});
  end;

symbolic procedure chebeval(c,xx,a,b,x);
  begin scalar d,dd,y,y2,sv;
        integer m;
    c:=for each q in c collect numr simp q;
    m:=length c;
    y2 := dm!:(2*(y:=(2*x-a-b)/(b-a)));
    for j:=(m-1) step -1 until 1 do
    << sv:=d;
       d:= dm!:(y2*d-dd+nth(c,add1 j));
       dd := sv;
    >>;
    return dm!:(y*d-dd + car c/2);
  end;

symbolic procedure chebint(c,xx,a,b);
  begin scalar su,fac,con,cint,w;
        integer n,jj;
    n := length c;
    c:=for each q in c collect numr simp q;
    fac := 1;
    con := dm!:((b-a)/4);
    cint := for j:=1:(n-2) collect
    << jj:=j+2;
       dm!:(w:= con*(nth(c,j)-nth(c,jj))/j );
       dm!:(su := su + fac*w);
       dm!:(fac := -fac);
       w
    >>;
    cint := append(cint,{dm!: (con*nth(c,sub1 n)/(n-1))});
    dm!:( su := su+fac*nth(c,n));
    cint := (dm!:(su+su)) . cint;
    return cint;
  end;

symbolic procedure chebdf(c,xx,a,b);
  begin scalar con,cder,w;
        integer n,jj;
    n := length c;
    c:=for each q in c collect numr simp q;
    cder := for i:=1:n collect nil;

    nth(cder,n-1) := dm!:(2*(n-1)*nth(c,n));
    for j:=(n-3) step -1 until 0 do
    <<jj:=j+3;
      nth(cder,j+1):=
       dm!:(nth(cder,jj)+2*(j+1)*nth(c,add1 add1 j));
    >>;

    con := dm!:(2/(b-a));

    return for each q in cder collect dm!:(con * q);
  end;

endmodule;


module rungeku;  % Numeric solution of ODE's with Runge-Kutta.
   % Version 2: supporting ODE systems

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1993, all rights resrved

fluid '(!*noequiv accuracy!*);
global '(iterations!* !*trnumeric);

put ('num_odesolve,'psopfn,'rungekuttaeval);

symbolic procedure rungekuttaeval u;
     % interface function;
  begin scalar e,f,x,y,sx,sy,en,d,nd,v,w,q;
        integer n;
    u := for each x in u collect reval x;
    u := accuracycontrol(u,20,6);

     % equations
    e :=car u; u :=cdr u;
    e := if eqcar(e,'list) then cdr e else {e};

     % dependent variable
    q :=car u; u :=cdr u;
    q := if eqcar(q,'list) then cdr q else {q};
    for each yy in q do
    <<if not eqcar(yy,'equal) or not idp cadr yy
     then typerr(yy,"expression `dep. variable=starting value'");
     sy:=caddr yy.sy; y := cadr yy.y;
    >>;
    sy:=reversip sy; y:=reversip y;
    if length sy neq length e then
      rederr "number of equations and variables don't correspond";

      % independent variable
    x :=car u; u :=cdr u;
    if not eqcar(x,'equal) or not idp cadr x
       or null (w:=revalnuminterval(caddr x,t))
        then typerr(x,"expression `indep. variable=interval'");
    sx:=car w; en:=cadr w; x := cadr x;

      % convert expressions to explicit ODE system.
    q := for each yy in y collect {'df,yy,x};
    v:=cdr solveeval list('list. e, 'list . q);
    if cdr v then
      ruksyserr(nil,"cannot convert to explicit ODE system");
    f := for each d in q collect rukufindrhs(d,v);
    return rungekutta1(f,x,y,sx,en,sy);
end;

symbolic procedure rukufindrhs(d,e);
  % Find the righthand side for d in list e.
  if atom e then
      ruksyserr(d," cannot be moved to lhs of system") else
  if eqcar(car e,'equal) and cadr car e = d then
           reval caddr car e else
  if pairp e and eqcar(car e,'list) then  rukufindrhs(d,cdar e)
  else rukufindrhs(d,cdr e);

symbolic procedure ruksyserr(u,m);
  <<if u then writepri(mkquote u,'first);
    writepri(mkquote m,'last);
    rederr "Runge-Kutta failed";
  >>;

symbolic procedure rungekutta1(f,x,y,sx,ex,sy);
    %preparations for rungekutta iteration.
 (begin scalar acc,r,oldmode,!*noequiv;
    integer prec;
    if not memq(dmode!*,'(!:rd!: !:cr))then
       <<oldmode:=t; setdmode('rounded,t)>>;
    !*noequiv:=t; prec:=precision 0;
    sx := force!-to!-dm numr simp sx;
    ex := force!-to!-dm numr simp ex;
    sy := for each z in sy collect force!-to!-dm numr simp z;
    acc := !:!:quotient(1,expt(10,accuracy!*));
    if !*trnumeric then prin2t "starting rungekutta iteration";
    r := rungekutta2(f,x,y,sx,ex,sy,acc);
    if oldmode then setdmode('rounded,nil);
    precision prec;
    if null r then rederr "no solution found";
    return 'list.r;
  end) where !*roundbf=!*roundbf;

symbolic procedure rungekutta2(f,xx,yy,xs,xe,ys,acc);
  % Algorithm for numeric ODE solution
  % f(xx,yy): rhs;
  % x:     independent variable;
  % y:     dependent variable;
  % s:     starting point;
  % e:     endpoint;
  % acc:   required accuracy
  % f,yy,ys are vectors (lists).
 dm!:
  begin scalar n,h,h2,h4,d1,d2,d3,d4,x,y,r,w1,w2,vars,dir;
    integer count,st;
    vars := xx.yy;
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
      % abs(w2 - w1)
    if normlist list!-list(w2,w1) > acc then
    <<h:=h2; st:=st+st; goto adapt>>;
    if !*trnumeric and not(st=iterations!*) then
      <<prin2
         "*** RungeKutta increased number of steps to ";
        prin2t st>>;
  loop:
    if (dir and x>xe) or (not dir and x<xe) then goto finis;
    r:=('list.x.y) . r;
    count:=add1 count;
    y:= rungekuttastep(f,vars,x,y,h,h2);
      % Advance solution.
    x:=x+h;
    goto loop;
  finis:
    r:= ('list.xx.yy).('list.xs.ys). rungekuttares(reversip r,st);
    return r;
  end;

symbolic procedure rungekuttares(l,st);
   % eliminate intermediate points.
     if st=iterations!* then l else
     << for i:=1:iterations!* collect
         <<for j:=1:m do l:= cdr l; car l>>
     >> where m=st/iterations!*;

symbolic procedure rungekuttastep(f,vars,x,y,h,h2);
  dm!:
   begin scalar d1,d2,d3,d4,q;
             %  f(x,y)
    d1:= list!-evaluate(f,vars,x.y);
             %  f(x+h2,y+h2*d1)
    d2:= list!-evaluate(f,vars,
          (x+h2). list!+list(y,scal!*list(h2,d1)));
             %  f(x+h2,y+h2*d2)
    d3:= list!-evaluate(f,vars,
          (x+h2). list!+list(y,scal!*list(h2,d2)));
             %  f(x+h,y+h*d3)
    d4:= list!-evaluate(f,vars,
          (x+h).list!+list(y,scal!*list(h,d3)));
      % find y(x+h) = y+h*(d1 + 2*d2 + 2*d3 + d4)/6.
    y:=list!+list(y,
       scal!*list(!:!:quotient(h,6),
         list!+list(d1,
          list!+list(scal!*list(2,d2),
           list!+list(scal!*list(2,d3),
            d4)))));
    return y;
  end;

endmodule;


end;
