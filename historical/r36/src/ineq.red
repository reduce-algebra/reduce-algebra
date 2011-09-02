module ineq; % Inequalities and linear optimization.

% Author:       Herbert Melenk <melenk@zib-berlin.dbp.de>

% Driver for solving inequalities and inequality systems.

% Implemented methods:
%
%   -  linear multivariate system
%   -  polynomial/rational univariate inequality and system

% Common algebraic interface:
%
%     ineq_solve(<ineq/ineqlist> [,<variable/variablelist>])

create!-package('(ineq linineq liqsimp1 liqsimp2 polineq),'(solve));

load!-package 'solve;  % Some routines from solve are needed.

fluid '(solvemethods!*);

if not memq('ineqseval,solvemethods!*) then
      solvemethods!* := 'ineqseval!*!* . solvemethods!*;

if not get('geq,'simpfn) then
    <<mkop 'leq; mkop 'geq; mkop 'lessp; mkop 'greaterp>>;

if not get('!*interval!*,'simpfn) then
    <<mkop '!*interval!*;
      infix !*interval!*;
      put('!*interval!*,'prtch," .. ")
    >>;

symbolic procedure ineqseval!*!* u;
 % Interface to solve.
  (if null w then nil
    else if w='(failed) then if smemql('(leq geq lessp greaterp),u)
      then w else nil
    else w)
      where w=ineqseval u;

symbolic procedure ineqseval!* u;
 % Interface to ineq_solve.
  (if null w or w='(failed) then car u else w)
      where w=ineqseval u;

put('ineq_solve,'psopfn,'ineqseval!*);

symbolic procedure ineqseval(u);
  begin scalar s,s1,v,v1,l,w1,w2,err,ineqp,str;
   integer n;
   s:=reval car u;
   s:=if eqcar(s,'list) then cdr s else {s};
   if cdr u then
   <<v:= reval cadr u;
     v:=if eqcar(v,'list) then cdr v else {v};
   >>;
   % test for linearity, collect variables.
   l:=t;
   s1:=for each q in s join if not err then
   <<if atom q or not memq(car q,'(leq geq lessp greaterp equal))
        then err:=t else
  << if not(car q eq 'equal) then ineqp := t;
     n:=n#+1;
     str := str or memq(car q,'(lessp greaterp));
     w1:=simp cadr q; w2:=simp caddr q;
     v1:=union(v1,solvevars{w1,w2});
     if not domainp denr w1 or not domainp denr w2 then l:=nil;
     {numr w1,denr w1,numr w2,denr w2}
   >> >>;
   if err or not ineqp then return nil;
   if null v then v:=v1;
   l := l and not nonlnrsys(s1,v);
   if length v1 > length v or not subsetp(v,v1) or not l and cdr v1 then
       return '(failed); % Too many indeterminates in inequality system;
%  if not l and n#>1 then
%      return '(failed); % Nonlinear system not implemented.
   if l and str then
       return '(failed); % No strict linear system.
   return if l then linineqseval u else polineqeval u;
  end;

endmodule;


module linineq; % Linear inequalities and linear optimization.

% Author:       Herbert Melenk <melenk@zib-berlin.dbp.de>

% Version 1     January 1990
% Version 1.1   February 1990
%               added parameter "record=t"
% Version 2     May 1991
%               added Branch-and-Bound for Integer Prgramming
% Version 3     Dec 1994
%               added formal simplifier for MAX/MIN expressions.
%               Changed "inf" to "infinity".
%               Operator linineq_solve new.
% Version 4     Jan 95
%               use polytope points for the simplification of MAX/MIN
%               expressions.

%
% Solution of linear inequalities & equations with numerical
% coefficients.
%
%   Fourier(1826) /Motzkin(1936): George. B. Dantzig,
%                  Linear Programming and Extensions.


put('linineq,'psopfn,
       function (lambda(u);
                    rederr "USE simplex (package linalg) instead"));

global '(!*trlinineq !*trlinineqint !*prlinineq);
switch trlinineq,prlinineq,trlinineqint;
fluid '(linineqinterval!* linineqrecord!*);

fluid '(!*ineqerr);   % error code

symbolic procedure linineqeval(u);
  % Interface for algebraic mode.
   begin scalar prob,equa,requa,vars,oldorder,res,u1,x,y,p,e,msg;
         scalar direction,rec,linineqrecord!*,r,intvars,w1,w2,op;
      msg := !*prlinineq or !*trlinineq;
      !*ineqerr :=nil;
      u1 := getrlist reval car u; u := cdr u;
      if u and eqcar(x:= reval car u,'list) then
         <<vars := getrlist x; u:=cdr u>>;
      while u do <<x := reval car u; u := cdr u;
                  if eqcar(x,'equal) and
                     ((cadr x='record and (rec:=t)) or
                      (cadr x='int and (intvars:=getrlist caddr x)))
                  then t else
                  <<!*ineqerr:=2;
                    typerr(x,"illegal parameter")>>;
                >>;
      x := nil;
      for each u in vars do
       <<u := reval u;
         if eqcar(u,'equal) then
           if  member(caddr u,'(min max)) then
            <<direction:=(cadr u. caddr u) . direction;
              u := cadr u>> else
                <<!*ineqerr:=2;
                  rederr "illegal form in 2nd parameter">>;
         if smember(u,u1) and not member(u,x) then x:=u.x>>;
      x := vars := reversip x;
      while u1 do
      <<u := reval car u1; u1:=cdr u1;
        if not pairp u or not (car u memq '(geq leq equal)) then
             <<!*ineqerr:=2; typerr(u,"inequality")>>;
        op:=car u; w1:=reval cadr u; w2:=reval caddr u;
        if op='geq then
          if smemq('infinity,w2) then nil else
          if eqcar(w2,'max) then
             for each q in cdr w2 do
               u1:=append(u1,{{'geq,w1,q}})
          else prob := (simp w1 . simp w2) . prob else
        if op='leq then
         if smemq('infinity,w2) then nil else
         if eqcar(w2,'min) then
             for each q in cdr w2 do
               u1:=append(u1,{{'leq,w1,q}})
          else prob := (simp w2 . simp w1) . prob else
        if op='equal then
            if eqcar(w2,'!*interval!*) then
              u1:=append(u1,{{'geq,w1,cadr w2},{'leq,w1,caddr w2}})
            else
             equa := (simp w1 . simp w2) . equa
         else
           <<!*ineqerr:=1; typerr(u,"inequality")>> >>;
        % control the linearity
      for each p in append(equa,prob) do
      <<if not domainp denr car p or not domainp denr cdr p
          then<<!*ineqerr:=1;
                rederr "unable to process nonlinear system">>;
        vars := linineqevaltest(numr car p,
                        linineqevaltest(numr cdr p,vars));
      >>;
      if msg then <<prin2 "variables:"; prin2t vars;>>;
      oldorder := setkorder vars;
      prob := for each p in prob collect
       (reorder numr car p./denr car p).
             (reorder numr cdr p./denr cdr p);
      equa:= for each p in equa collect
       (reorder numr car p./denr car p).
             (reorder numr cdr p./denr cdr p);
       % eliminate variables from equations
      while equa do
      <<e := car equa; equa := cdr equa;
        e := addsq(car e,negsq cdr e);
        if domainp numr e then
        <<if numr e then  % nonzero constant equated to 0
          <<!*ineqerr:=0; rederr "equation part inconsistent">> >>
         else
        <<u := list((x := mvar numr e).
                  prepsq(y:=multsq(negf red numr e ./ 1,
                                   invsq(lc numr e ./ 1))));
                 if member(x,intvars) then
                          % Dont eliminate integer variables - represent
                          % equation by double inequality instead.
                 <<x:=simp x; prob:=append({x.y,y.x},prob)>>
                 else
                 <<
          prob := for each p in prob collect
                        subsq(car p,u).subsq(cdr p,u);
          equa := for each p in equa collect
                        subsq(car p,u).subsq(cdr p,u);
          requa := append(u,requa);
          if msg then
            <<prin2 "         ";prin2 x;
              prin2 " eliminated by equation";
              terpri()>>;
          vars := delete(x,vars);
                 >>
      >> >>;
      res := if intvars
               then linineqint(prob,vars,msg,direction,rec,intvars)
             else linineq1(prob,vars,msg,direction,rec);
          % backsubstitution in equations;
      if null res then return '(list) else if res=t then res:=nil;
      for each e in requa do
      <<x := prepsq subsq(y:=simp cdr e,res);
        res := (car e . x) . res;
        if rec then
        <<x := prepsq y;
          linineqrecord!* := list(x,x) . linineqrecord!*>>;
      >>;
      setkorder oldorder;
      r := if rec then for each p in
               liqsimp!-maxmin pair(res,linineqrecord!*)
            collect
               list('list,list('equal,caar p,cdar p),cadr p,caddr p)
            else
           for each p in res collect list('equal,car p,cdr p);
      return 'list . r;
   end;

% put('linineq_solve,'psopfn,'linineqseval);

symbolic procedure linineqseval(u);
   'list . reversip for each q in
     cdr linineqeval append(u,'((equal record t)))
       collect {'equal,cadr cadr q,
        if caddr q = cadddr q then caddr q else '!*interval!* . cddr q};

symbolic procedure linineqevaltest(f,v);
   % Collect the variables in standard form f and control linearity.
     if domainp f then v else
     if not(ldeg f=1) then
           <<!*ineqerr:=1;
             rederr "unable to process nonlinear system">>
       else
     if member(mvar f,v) then linineqevaltest(red f,v) else
         linineqevaltest(red f,mvar f.v);

symbolic procedure linineq0(prob,vars,dir,rec);
  % Interface for symbolic mode.
  % Prob is a list (e1,e2,..) of algebraic expressions without
  % relational operators, which are interpreted as
  % set of inequalities ei >= 0. They are linear in the
  % variables vars.
  % Silent operation: result=nil if the system is inconsistent.
   begin scalar oldorder,res;
      linineqrecord!* := nil;
      oldorder := setkorder vars;
      prob := for each u in prob collect simp u . (nil ./ 1);
      res := linineq1(prob,vars,nil,dir,rec);
      setkorder oldorder;
      return res;
   end;

symbolic procedure linineqint(prob,vars,msg,dir,rec,intvars);
  begin scalar x,x0,y,y0,y1,z,w,problems,best,z,z0,zbest,zf,bestr;
       % test integer variables and adjust order;
    for each x in vars do
      if member(x,intvars) then<<w:=x.w;intvars:=delete(x,intvars)>>;
    if intvars
      then <<!*ineqerr:=2;typerr('list.intvars,"int variables")>>;
    intvars:=reversip w;
       % select primary optimization principle.
        if dir then<<z:=caar dir;zf:=if cdar dir='max then 1 else -1>>;
    problems:=list (nil.prob);
       % macro loop.
    while problems do
    <<z0:=caar problems; prob:=cdar problems; problems:=cdr problems;
      if msg or !*trlinineqint
        then linineqprint2("=== next integer subproblem",prob);
      w:=if best and not evalgreaterp({'times,zf,z0},{'times,zf,zbest})
          then nil  % skip problem with suboptimal bound.
         else linineq1(prob,vars,msg,dir,rec);
      if !*trlinineqint then linineqprint3("=== subresult",w);
      if w and dir then
      <<% is better than best so far?
        z0:=cdr assoc(z,w);
        if best and evalgreaterp({'times,zf,zbest},{'times,zf,z0})
           then w:=nil;
      >>;
      if w then
      <<% test feasability;
        y:=list prob;
        for each x in intvars do
        <<x0:=cdr assoc(x,w);
          if not fixp x0 then  % branch and bound
          <<x:=simp x; y0:=simp{'ceiling,x0}; y1:=simp {'floor,x0};
            y:= for each q in y join {(x.y0).q, (y1.x).q};
            if msg or !*trlinineqint then
            <<writepri("branch and bound with",'first);
              writepri(mkquote{'list,{'geq,x:=prepsq x,prepsq y0},
                                     {'leq,x,prepsq y1}},'last);
           >>;
          >>;
        >>;
        if cdr y then
         problems:=append(problems,for each q in y collect z0.q)
        else
         <<zbest:=z0; best:=w; bestr:=linineqrecord!*;
           if !*trlinineqint then prin2t "===>  is feasable";>>;
       >>;  % if w
               % without target dont need additional result.
           if best and null dir then problems:=nil;
     >>;  % while problems
   linineqrecord!*:=bestr;
   return best;
 end;

symbolic procedure linineq1(prob,vars,msg,dir,rec);
  % Algebraic evaluation of a set of inequalities:
  % prob is a list of pairs of standard quotients,
  % (( p1 . q1)(p2 . q2) .. (pn . qn))
  % which are interpreted as inequalities:
  %     pi >= qi ;
  % vars is the list of (linear) variables.
  % dir  the direction of final optimization
  % rec  switch; if t, the record of inequatlities is produced
  % Result is NIL if the system has no solution; otherwise
  % the solution has the form of an association list
  %  ((v1 . val1)(v2 . val2) ... (vn . valn)),
  % where vi are the variables and vali are values in algebraic
  % form. NIL if the system has no solution.
  %
   begin scalar v,vq,lh,rh,x,y,z,prob1,prob2,prob3,prob4,nprob,sw,sol;
      if null vars then return linineq2(prob,msg);
      v := car vars; vars := cdr vars;
      vq := mksq(v,1);
      if !*trlinineq then
       linineqprint2(list("next variable:",v,"; initial system:"),prob);
      prob := linineqnormalize prob;
      for each p in prob do
       <<lh := car p; rh := cdr p;
          % if v appears on the lhs, isolate it
         if not domainp numr lh and mvar numr lh = v then
         <<x :=  invsq(lc numr lh ./ 1);
           sw := (numr x < 0);
           lh := multsq(lh,x); rh := multsq(rh,x);
           rh := addsq(rh,negf red numr lh ./ denr lh);
           if not sw then prob1 := (vq . rh) . prob1 else
                          prob2 := (rh . vq) . prob2;
         >>else if domainp numr rh and domainp numr lh then
                prob4 := (lh . rh) . prob4 else
                prob3 := (lh . rh) . prob3;
       >>;
      if null prob1 and null prob2 and vars then
      << sol := linineq1(prob,vars,msg,dir,rec);
         if rec then linineqrecord!* :=
             append(linineqrecord!*,'(((minus infinity) infinity)));
         return if sol then (v . 0) . sol else nil>>;
      if !*trlinineq then
      <<linineqprint2("class 1:",prob1);
        linineqprint2("class 2:",prob2);
        linineqprint2("class 3:",prob3);
        linineqprint2("class 4:",prob4);
      >>;
      if rec then
      << x := for each u in prob1 collect prepsq cdr u;
         y := for each u in prob2 collect prepsq car u;
         x := if null x then '(minus infinity) else
              if null cdr x then car x else 'max . x;
         y := if null y then ' infinity else
              if null cdr y then car y else 'min . y;
         linineqrecord!* := append(linineqrecord!*, list list(x,y))
      >>;
      if not linineq2(prob4,msg) then return nil;
      nprob := append(prob3,
         for each x in prob1 join
           for each y in prob2 collect
             car y . cdr x);
      if vars then
       << if null (sol := linineq1(nprob,vars,msg,dir,rec)) then
                         return nil>>
        else if not linineq2(nprob,msg) then return nil;
         % lower bound:
      x := if null prob1 then nil else
         linineqevalmax for each p in prob1 collect
                subsq(cdr p,sol);
         % upper bound:
      y := if null prob2 then nil else
         linineqevalmin for each p in prob2 collect
                subsq(car p,sol);
      if (z:=assoc(v,dir)) then z:= cdr z;
      if msg then
      <<writepri("         ",'first);
        writepri(mkquote if x then prepsq x else '(minus infinity),nil);
        writepri(" <= ",nil);
        writepri(mkquote v,nil);
        writepri(" <= ",nil);
        writepri(mkquote if y then prepsq y else 'infinity,nil);
        writepri(";   ",nil)>>;
     linineqinterval!* := x . y;
     if z='min and null x or z='max and null y then
      <<if msg then writepri( " max/min cannot be resolved",'last);
        return nil>>;
      if not(x=y) then
        if z='min then y:=nil else if z='max then x:=nil;
      if msg then
      << writepri(
        if null x and null y then " completely free: " else
        if null y then " minimum: " else
        if null x then " maximum: " else
        if x=y then " zero length interval: " else
                " middle: ",nil);
       >>;
      if null x and null y then x := 0 else % completely free
      if null x then x := prepsq y else
      if null y then x := prepsq x else
      if sqlessp(y,x) then
        <<prin2 "system inconsistent:";
          prin2 prepsq x; prin2 " not <= "; prin2t prepsq y;
          return nil>> else
        x := list('quotient,list('plus,prepsq x,prepsq y),2);
      x := aeval x;
      if msg then
        writepri(mkquote list('equal,v,x),'last);
      return (v . x) . sol;
   end;

symbolic procedure linineq2(prob,msg);
   % All variables are elimitated. Control, if the
   % remaining numerical inequalities are consistent.
   begin scalar rh,lh;
 loop: if null prob then return t;
      lh := caar prob; rh := cdar prob;
      if not domainp numr rh or not domainp numr lh then
        <<!*ineqerr:=1;
          rederr{" non numeric:", rh, lh};
        >>;
      if sqlessp(lh,rh) then
        <<if msg then <<writepri("system inconsistent: ",'first);
                        writepri(mkquote prepsq lh,nil);
                        writepri(" not >= ",nil);
                        writepri(mkquote prepsq rh,'last);>>;
          return nil>>;
      prob := cdr prob;
      goto loop;
    end;

symbolic procedure linineqnormalize prob;
    % Normalize system: reform all inequalities such that they have
    % the canonical form %     polynomial >= constant
    %      (canonical restriction: absolute term of lhs=0,
    %                              denominator of lhs = 1).
    % and remove those, which have same lhs, but smaller rhs
    % (the latter are superfluous).
   begin scalar r,lh,rh,d,ab,x;
     for each p in prob do
     <<lh := car p; rh := cdr p;
         % arithmetic normalizaion
       lh := addsq(lh,negsq rh);
       d := denr lh;
       lh := numr lh;
       ab := lh; x := if domainp lh then 1 else lc ab;
       while not domainp ab do <<x := gcdf(x,lc ab);ab := red ab>>;
       ab := negf ab;
       lh := multsq(addf(lh,ab)./1,1 ./ x);
       rh := multsq(ab ./ 1, 1 ./ x);
         % removal of redundant elements
       x := assoc(lh,r);
       if null x then r:=(lh.rh) . r else
         if sqlessp(cdr x,rh) then rplacd(x,rh);
     >>;
     if !*trlinineq then
         linineqprint2("normalized and reduced:",r);
     return r;
   end;

symbolic procedure linineqevalmin u;
   % Compute the minimum among the list u with sq's.
     linineqevalmin1(car u,cdr u);

symbolic procedure linineqevalmin1(q,u);
   if null u then q else
  (linineqevalmin1( if x and !:minusp x then q else car u, cdr u)
       ) where x=numr addsq(q,negsq car u);

symbolic procedure linineqevalmax u;
   % compute the maximum among the list u with sq's
     linineqevalmax1(car u,cdr u);

symbolic procedure linineqevalmax1(q,u);
   if null u then q else
  (linineqevalmax1(
     if x and !:minusp x then car u else q, cdr u)
        ) where x=numr addsq(q,negsq car u);

symbolic procedure sqlessp(q1,q2);
   (x and !:minusp x) where x=numr addsq(q1,negsq q2);

symbolic procedure liqsimp!-maxmin w;
   liqsimp2!-maxmin liqsimp1!-maxmin w;

endmodule;


module liqsimp1; % interval simplifcation level 1 by
                 % inequality propagation.

fluid'(liqsimp1bounds!*);

symbolic procedure liqsimp1!-maxmin w;
 % W is a list of forms {x , l , u} where the interval [l,u]
 % has been assigned to the variable x. l and u may be formal
 % expressions dominated by an operator MAX or MIN and including
 % variables of the following intervals. I try to simplify the
 % bounds as far as possible by computing inequality chains.
  (liqsimp1!-maxmin1 w) where liqsimp1bounds!*=nil;


symbolic procedure liqsimp1!-maxmin1 w;
 begin scalar x,l,u,r;
   x:=caaar w; l:=cadar w; u:=caddar w;
   if cdr w then % bottom reached?
   << r:=liqsimp1!-maxmin1 cdr w;
      l:=liqsimp1!-reducecases(l);
      u:=liqsimp1!-reducecases(u);
   >>;
   liqsimp1bounds!* :=
        {x , liqsimp1!-maxmin1leaf(l),
             liqsimp1!-maxmin1leaf(u)}
       . liqsimp1bounds!*;
   return {caar w,l,u} . r;
 end;

symbolic procedure liqsimp1!-reducecases(w);
 % M=t: upper bound, M=nil: lower bound.
  begin scalar op,l,tst,d,u;
    if atom w or not memq(car w,'(max min)) then return w;
    op:=car w;
    l:=for each u in cdr w collect u . simp u;
      % check whether an element is covered by another one.
    for each e in l do
    <<tst := nil;
      for each d in l do if d neq e and not tst then
      <<
           % Can I prove that (with op=MAX) e <= d?
           % I compute u=d-e and check the thest u>= 0 down
           % the bounds for the other variables.
       u:=subtrsq(cdr d,cdr e);
       tst:=liqsimp1!-check(u,liqsimp1bounds!*,op);
      >>;
           % then delete it.
      if tst then l:=delete(e,l);
    >>;
      % collect the surviving elements.
    l:=for each u in l collect car u;
    return if cdr l then op. l else car l;
  end;

symbolic procedure liqsimp1!-check(u,bounds,m);
   if m='min then liqsimp1!-check1(negsq u,bounds) else
     liqsimp1!-check1(u,bounds);

symbolic procedure liqsimp1!-check1(u,bounds);
       % On this level I check whether u>=0 is true.
   if domainp numr u then not minusf numr u or null numr u else
   if null bounds then nil else
   if mvar numr u neq caar bounds
       then liqsimp1!-check1(u,cdr bounds) else
    begin scalar x,c,r,d,tst,bds;
     x:=caar bounds;
       % U = c*x + r, car bounds has lower and upper limits for x;
       % U >= 0 is then equivalent to
       %          c >= 0 replace x by lower bounds
       %      or
       %          c <= 0 replace x by upper bounds.
       %
     d:=!*f2q denr u; c:=!*f2q lc numr u; r:=!*f2q red numr u;
     if liqsimp1!-check1(c,bounds) then % C>=0
         bds:=cadar bounds else bds:=caddar bounds;
     for each b in bds do
       tst:=tst
           or liqsimp1!-check1(addsq(multsq(c,b),r),cdr bounds);
      return tst;
   end;

symbolic procedure liqsimp1!-maxmin1leaf(q);
   if q='infinity or q='(minus infinity) then nil else
   for each w in
     (if pairp q and car q memq '(max min) then cdr q else {q})
       collect simp w;

endmodule;


module liqsimp2; % interval simplification level2 by
                 % removal of non-tight hyperplanes.


fluid'(infinities!*);

symbolic procedure liqsimp2!-maxmin w;
 % W is a list of forms {x.x0 , l , u} where the interval [l,u]
 % has been assigned to the variable x. l and u may be formal
 % expressions dominated by an operator MAX or MIN and including
 % variables of the following intervals. I try to simplify the
 % bounds as far as possible by computing inequality chains.
  begin scalar r;
    infinities!* := {simp 'infinity, simp '(minus infinity)};
    w:= for each q in w collect
      {car q, minmax2ql cadr q, minmax2ql caddr q};
     r:= liqsimp2!-maxmin1 w;
    return for each q in r collect
      {car q, ql2minmax('max,cadr q),ql2minmax('min,caddr q)};
  end;

symbolic procedure ql2minmax(m,l);
  <<l:=for each q in l collect prepsq q;
    if cdr l then m.l else car l>>;

symbolic procedure minmax2ql(l);
  if pairp l and car l memq '(min max) then
     for each q in cdr l collect simp q else {simp l};

symbolic procedure liqsimp2!-maxmin1 w;
   if null w then nil else
   liqsimp2!-reducecases(car w,liqsimp2!-maxmin1 cdr w);


symbolic procedure liqsimp2!-reducecases(w,ll);
 % ll is alreayd a simplified chain of intervals.
  begin scalar x,l,u,t1,e1,e2,pts,eqns,y;
   x:=caar w; l:=cadr w; u:=caddr w;
   if null cdr l and null cdr u then return w.ll;

     % If I have more than one inequality in the upper
     % or lower part, I compute all pairwise crossing point
     % because these form the new contribution to the edges.
     % An inequality which has no valid point can be excluded
     % from the set. I may ignore infinite points because each
     % line must have at least two points.
   eqns := for each q in delete(car infinities!*,
              delete(cadr infinities!*,append(l,u)))
      collect {q};
     % Compute crossing points.
   t1:=eqns;
   while t1 and cdr t1 do
   <<e1 := car t1; t1:= cdr t1;
     for each e2 in t1 do
     <<pts :=liqsimp2_mk_edges(x,car e1,car e2,l,u,ll);
       cdr e1:=append(cdr e1,pts); cdr e2 := append(cdr e2,pts);
   >>>>;
   l:=for each q in l join
     if null (y:=assoc(q,eqns)) or cdr y then {q};
   u:=for each q in u join
     if null (y:=assoc(q,eqns)) or cdr y  then {q};
   return{car w,l,u}.ll;
  end;

symbolic procedure liqsimp2_mk_edges(x,e1,e2,l,u,ll);
  % x: current variable,
  % e1,e2: forms defining an edge contribution in x=e1,x=e2 at their
  %        intersection points. e1,e2 free of x.
  % l:     complete lower bounds for x,
  % u:     complete upper bounds for x,
  % ll:    simplified bounds for the lower variables.
 begin scalar form,pts,pl;
   form := subtrsq(e1,e2);
   pl := liqsimp2_mk_edges1(form,ll);
   pts := liqsimp2_mk_edges_check(pl,x,e1,l,u);
   return pts;
  end;

symbolic procedure sfnegativep u;
  if domainp u then minusf u else
  if mvar u = 'infinity then sfnegativep lc u else
  typerr(prepf u,"numeric expression");

symbolic procedure liqsimp2_mk_edges1(f,ll);
  % check f=0 by substituting the hyperplanes in ll.
  if null ll and null numr f then '(nil)
   else
     if null ll then typerr (prepsq f,"soll nicht vorkommen")
   else
  begin scalar fx,fxx,t1,x,l,u,points,pl;
    x:=caaar ll; l:=cadar ll; u:=caddar ll; ll:=cdr ll;
    t1 := delete(car infinities!*,
              delete(cadr infinities!*,append(l,u)));
    if null t1 then t1:='((nil . 1));
    fx:=liqsimp2_mk_edges2(f,x);
    fxx := '(nil . 1);

    points:= if null fx then
       % case 1: f does not depend of x. I must extend all
       % solutions of f wrt the remaining variables
       % by all possible edges from the interval bounds for x.
    <<pl :=liqsimp2_mk_edges1(fxx,ll);
      for each q in t1 join
        for each p in pl collect
         (x . prepsq subsq(q,p)) . p
    >>
    else
      if domainp numr fx then
       % case 2: f has the solution x=a where a does not depend
       % of any further variable. I must select those
       % extensions of x=a which are compatible under the local
       % inequalities.
    << pl:=liqsimp2_mk_edges1(fxx,ll);
       pl := liqsimp2_mk_edges_check(pl,x,fx,l,u);
      pl>>
    else
       % case 3: f depends of x and some more variables.
       % I compute all possible intrsection points with the
       % current interval bounds and extend the to solutions
       % with the remaining variables.
      for each p in t1 join
    <<fxx := subtrsq(fx,p);
      pl :=liqsimp2_mk_edges1(fxx,ll);
       % and remove points which don't satixfy the restrictions.
      pl := liqsimp2_mk_edges_check(pl,x,fx,l,u);
      pl>>;
    return points;
   end;

symbolic procedure liqsimp2_mk_edges_check(pl,x,fx,l,u);
 % select those points of pl where sub(x=p,fx) is compatible
 % with the l and u bounds. Extend the compatible points by
 % a value for x.
  for each p in pl join
  begin scalar fine,x1;
   fine:=t;
   x1:=subsq(fx,p);
   for each l1 in l do
      if fine and sfnegativep numr subtrsq(x1,subsq(l1,p)) then
         fine:=nil;
   for each u1 in u do
      if fine and sfnegativep numr subtrsq(subsq(u1,p),x1) then
         fine:=nil;
   return if fine then {(x.prepsq x1).p};
  end;

symbolic procedure liqsimp2_mk_edges2(f,x);
  % solve f(x)=0 for linear standard quotient f. Return
  % nil if x does not occur in f.
  if not smemq(x,f) then nil else
  begin scalar w;
    w:=(reorder numr f) where kord!*={x};
    return quotsq(negf red w./ 1,lc w ./ 1) ;
  end;

% ============= printing ================================

symbolic procedure linineqprint1(text,lh,rh);
         <<writepri(text,'first);
           writepri(mkquote prepsq lh,nil);
           writepri(" >= ",nil);
           writepri(mkquote prepsq rh,'last)>>;


symbolic procedure linineqprint2(text,prob);
    <<prin2t "--------------------------------";
          if atom text then text:={text};
      for each u in text do prin2 u; terpri();
          writepri(mkquote('list .
         for each p in prob collect
                    {'geq,prepsq car p,prepsq cdr p}),'last)
    >>;

symbolic procedure linineqprint3(text,res);
    <<writepri(text,'first);
          writepri(mkquote('list . for each p in res collect
                     {'equal,car p,cdr p}), 'last);
        >>;

endmodule;


module polineq; % Solve univariate polynomial inequality systems;

% Author: Herbert Melenk, ZIB Berlin.

% All rights reserved.

% Method: compute the real roots of all numerators and denominators
% and check the intervals between them.

global '(!!arbint);

if not get('arbreal,'simpfn) then mkop 'arbreal;

symbolic procedure polineqeval u;
 begin scalar w,x;
   w:=reval car u;
   if eqcar(w,'list) then w:=for each q in cdr w collect reval q
      else w:={w};
   if cdr u then x:=reval cadr u;
   if eqcar(x,'list) then if cddr x then typerr(x,"variable")
       else x:=cadr x;
   return polineq0(w,x);
  end;

symbolic procedure polineq0(ul,x);
  begin scalar b,n,d,l,w,wl,op,u,r,s,x,y,z;
   loop:
     u:=car ul; ul:=cdr ul;
     if not pairp u or not((op:=car u) memq '(geq greaterp leq lessp))
      then go to typerr;
     s:= s or op = 'greaterp or op = 'lessp;
     w:=simp if op='greaterp or op='geq
               then {'difference,cadr u,caddr u}
              else {'difference,caddr u,cadr u};
     wl := w.wl;
     y:=(not domainp numr w and mvar numr w) or
        (not domainp denr w and mvar denr w);
      % check for a polynomial in a free variable.
     if null y or x and x neq y
        or pairp y and (get(car y,'!:rd!:) or get(car y,'opmtch))
         then go to typerr;
     x:=y;
     n:= append(n,polineq!-realroots(numr w,x));
     d:= append(d,polineq!-realroots(denr w,x));
   if ul then go to loop;
   for each y in append(n,d) do if not(y member b) then b:=y.b;
   if null b then return if polineqcheck(wl,{x . 0})
         then {'list,{'equal,x,{'arbreal,!!arbint := !!arbint+1}}}
                   else '(list);
    b:=sort(b,'evallessp);
      % Create the intervals;
    while b do
    <<if null l then l:= {{{'difference,car b,1},nil,car b}};
      z:= if cdr b then {'quotient,{'plus,car b,cadr b},2}
            else {'plus,car b,1};
      l:={z,car b,if cdr b then cadr b}.l;
      b:=cdr b;
    >>;
      % check and collect the intervals;
    for each v in l do
    << if polineqcheck(wl,{x.car v}) then
       r:=(if null cadr v then
             {if s then 'lessp else 'leq, x, caddr v}
           else if null caddr v then
             {if s then 'greaterp else 'geq, x, cadr v}
           else {'equal,x, '!*interval!*.cdr v}) . r
    >>;
    return 'list.r;
typerr: rederr("wrong arguments for polynomial inequality solver");
  end;

symbolic procedure polineqcheck(wl,p);
   null wl or not minusf numr subsq(car wl,p)
                and polineqcheck(cdr wl,p);

symbolic procedure polineq!-realroots(u,x);
  % return real roots of u, if possible as rational numbers.
 if domainp u then nil else
 for each f in cdr fctrf u join
 <<f:= car f;
   if mvar f neq x then rederr "too many variables";
   if ldeg f = 1 then {reval{'quotient,prepf negf red f,prepf lc f}}
    else
   for each y in cdr realroots list prepf f collect caddr y
 >>;

endmodule;


end;
