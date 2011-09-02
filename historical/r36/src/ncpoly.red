module ncpoly; % Computing in non-commutative polynomial rings and
               % ideals.

% Author: H. Melenk, ZIB-Berlin, J. Apel, University of Leipzig.

% Copyright: Konrad-Zuse-Zentrum Berlin, 1994

create!-package ('(ncpoly ncenv ncdip ncgroeb ncfactor ncout),
                 '(contrib ncpoly));

fluid '(ncpi!-brackets!* ncpi!-comm!-rules!* ncpi!-name!-rules!*
        ncpi!-names!*);

share ncpi!-brackets!*,ncpi!-comm!-rules!*,ncpi!-name!-rules!*;

load!-package 'dipoly;
load!-package 'groebner;

(if not numberp v or v<2.8
   then rederr "Groebner package version too old")
     where v=get('groebner,'version);

% For compatibility with REDUCE 3.5:

flag('(noncomf noncomp),if getd 'noncomf then 'lose else 'do);

symbolic procedure noncomf u;
   if domainp u then nil
    else noncomp mvar u or noncomf lc u or noncomf red u;

symbolic procedure noncomp u;
  pairp u and ((if pairp a then noncomf u else flagp(a,'noncom))
                 where a=car u);

endmodule;


module ncenv; % Non-communtative polynomial ring environment.

% This module organizes an environment for computing with
% non-commutative polynomials in algebraic mode, and an embedding
% for non-commutative Groebner bases.

% Author: H. Melenk, ZIB Berlin, J. Apel, University of Leipzig

% Copyright: Konrad-Zuse-Zentrum Berlin, 1994

fluid '(ncpi!-brackets!*
        ncpi!-comm!-rules!*
        ncpi!-name!-rules!*
        ncpi!-names!*
        !*ncg!-right
      );

share ncpi!-brackets!*,ncpi!-comm!-rules!*,ncpi!-name!-rules!*;

algebraic operator nc!*;
algebraic noncom nc!*;

put('nc!*,'prifn,'pri!-nc!*);
put('nc!*,'dipprifn,'dippri!-nc!*);

symbolic procedure pri!-nc!* u;
   prin2!*(w and cdr w or u) where w=assoc(u,ncpi!-names!*);

symbolic procedure dippri!-nc!* u;
   dipprin2(w and cdr w or u) where w=assoc(u,ncpi!-names!*);

symbolic procedure ncpi!-setup u;
  begin scalar vars,al,b,b0,f,m,rs,rn,na,rh,lh,s,x,y,w;
   if (w:=member('left,u)) or (w:=member('right,u)) then
   <<u:=delete(car w,u); !*ncg!-right:=car w='right>>;
   if length u > 2 then rederr "illegal number of arguments";
   if ncpi!-name!-rules!* then
      algebraic clearrules ncpi!-comm!-rules!*,ncpi!-name!-rules!*;
   u:=sublis(ncpi!-names!*,u);
   for each x in cdr listeval(car u,nil) collect
   <<x:=reval x;  y:={'nc!*,mkid('!_,x)}; na:=(y.x).na;
     rn:={'replaceby,x,y}.rn; al:=(x.y).al;vars:=append(vars,{y});
   >>;
   ncpi!-names!*:=na;
   ncpi!-name!-rules!*:='list.rn;
   m:=for i:=1:length vars -1 join
     for j:=i+1:length vars collect nth(vars,i).nth(vars,j);
   if cdr u then ncpi!-brackets!*:=listeval(cadr u,nil);
   if null ncpi!-brackets!* then
       rederr "commutator relations missing";
   for each b in cdr ncpi!-brackets!* do
   <<b0:=sublis(al,b);
     w:= eqcar(b0,'equal) and (lh:=cadr b0) and (rh:=caddr b0)
      and eqcar(lh,'difference) and (f:=cadr lh) and (s:=caddr lh)
      and eqcar(f,'times) and eqcar(s,'times)
      and (x:=cadr f) and (y:=caddr f) and member(x,vars)
          and member(y,vars)
      and x=caddr s and y=cadr s;
     if not w then typerr(b,"commutator relation");
     % Invert commutator if necessary.
     if member(x.y,m) then <<w:=x;x:=y;y:=w; rh:={'minus,rh}>>;
     m:=delete(y.x,m);
     rs:={'replaceby,{'times,x,y},{'plus,{'times,y,x},rh}} .rs;
   >>;
    % Initialize non-commutative distributive Polynomials.
   ncdsetup!*{'list.vars,'list.rs};
   apply('korder,{vars});
   apply('order,{vars});
    % Rules for commutating objects.
   for each c in m do
     rs:={'replaceby,{'times,cdr c,car c},{'times,car c,cdr c}}. rs;
   ncpi!-comm!-rules!*:='list.rs;
   algebraic let ncpi!-comm!-rules!*,ncpi!-name!-rules!*;
  end;

put('nc_setup,'psopfn,'ncpi!-setup);

symbolic procedure nc_cleanup();
   <<algebraic clearrules ncpi!-comm!-rules!*,ncpi!-name!-rules!*;
     algebraic korder nil;
     algebraic order nil;
   >>;

put('nc_cleanup,'stat,'endstat);

endmodule;


module ncdip; % Non-commutative distributive polynomials.

% Author: H. Melenk, ZIB Berlin, J. Apel, University of Leipzig.


fluid '(
        ncdipvars!*         % variable set

        ncdipbase!*         % vector:
                            % the i-th entry is a list (j1,j2...)
                            % where j1,j2 ... < i
                            %    and x_i * x_j neq x_j*x_i

        ncdiptable!*        % 2-dim array:
                            % then entry (i,j) keeps the powers of the
                            % commutator [x_i,x_j] where j<i

        ncdipcircular!*     % t if one variable appears in more than one
                            % commutator

        vdpsortmode!*
        !*gsugar);

symbolic procedure ncdsetup!* u;
 % U is a list of algebraic arguments:
 % 1. list of variables,
 % 2. list of commutator relations in explicit form x*y=y*x + r
 %    where ord(r) < ord(x*y) .
 % All variable pairs whitch do not occur here are considered
 % communtative.
  begin scalar x,y,w,vars,lh,z,lv,r,q;
    vars := for each x in cdr listeval(car u,nil)
       collect reval x;
    ncdipcircular!*:=nil;
    if null vdpsortmode!* then vdpsortmode!*:= 'lex;
    vdpinit2 (ncdipvars!*:=vars);
    lv:=length vars;
    ncdipbase!* := mkvect lv;
    ncdiptable!* := mkvect lv;
    for i:=1:lv do putv(ncdiptable!*,i,mkvect lv);
    q:=cdr listeval(cadr u,nil);

    while q do
    <<r:=car q; q:=cdr q;
     if (eqcar(r,'equal) or eqcar(r,'replaceby)) and
          eqcar(lh:=cadr r,'times) and
          null cdddr r and
          (w:=member(y:=caddr lh,vars)) and
          member(x:=cadr lh,w)
       then
       <<
           % does any variable other than x or y appear in the rhs?
          if smember(x,q) or smember(y,q) then ncdipcircular!*:=t;
          for each v in vars do
           if v neq x and v neq y and smember(v,caddr r) then
            ncdipcircular!*:=t;
           % establish the commutator in DIP form.
          w := ncdipndx(x,vars,1).ncdipndx(y,vars,1);
          r := a2dip (z:= reval caddr r);
          if evcomp(dipevlmon r,dipevlmon a2dip {'times,x,y})<0 then
             typerr({'equal,{'times,x,y},z},
               "commutator under current term order");
          getv(ncdipbase!*,car w) :=
               sort(cdr w.getv(ncdipbase!*,car w),'lessp);
          getv(getv(ncdiptable!*,car w),cdr w):= {'(1 . 1) . r};
       >>
       else typerr(r,"commutator ");
     >>;
   end;

symbolic procedure ncdipndx(x,vars,n);
   if null vars then 0 else
   if x=car vars then n else ncdipndx(x,cdr vars,n #+ 1);

%============ noncom multiply ============================

symbolic procedure vdp!-nc!-m!*p(bc,ev,p);
  % multiply polynomial p left by monomial (bc,ev).
  begin scalar r,s;
   r:=dip2vdp dip!-nc!-m!*p(bc,ev,vdppoly p);
   if !*gsugar then
   <<s:= gsugar p; for each e in ev do s:=s+e;
     r:=gsetsugar(r,s)>>;
   return r;
  end;

symbolic procedure vdp!-nc!-prod(u,v);
  % non-commutative product of two distributive polynomials.
  begin scalar r;
   r:=dip2vdp dip!-nc!-prod(vdppoly u,vdppoly v);
   if !*gsugar then r:=gsetsugar(r,gsugar u + gsugar v);
   return r;
  end;

symbolic procedure dip!-nc!-prod(u,v);
  % We distribute first over the shorter of the two factors.
  if length u < length v then dip!-nc!-prod!-distleft(u,v)
        else dip!-nc!-prod!-distright(u,v);

symbolic procedure dip!-nc!-prod!-distleft(u,v);
  if dipzero!? u then u else
   dipsum(dip!-nc!-m!*p!-distleft(diplbc u,dipevlmon u,v),
          dip!-nc!-prod!-distleft(dipmred u,v));

symbolic procedure dip!-nc!-m!*p!-distleft(bc,ev,p);
   if dipzero!? p then nil else
   begin scalar lev,lbc,q;
     lev := dipevlmon p; lbc := diplbc p;
     p:=dip!-nc!-m!*p!-distleft(bc,ev,dipmred p);
     q:=dip!-nc!-ev!-prod(bc,ev,lbc,lev);
     return dipsum(p,q);
   end;

symbolic procedure dip!-nc!-prod!-distright(u,v);
  if dipzero!? v then v else
   dipsum(dip!-nc!-m!*p!-distright(u,diplbc v,dipevlmon v),
          dip!-nc!-prod!-distright(u,dipmred v));

symbolic procedure dip!-nc!-m!*p!-distright(p,bc,ev);
   if dipzero!? p then nil else
   begin scalar lev,lbc,q;
     lev := dipevlmon p; lbc := diplbc p;
     p:=dip!-nc!-m!*p!-distright(dipmred p,bc,ev);
     q:=dip!-nc!-ev!-prod(lbc,lev,bc,ev);
     return dipsum(p,q);
   end;

symbolic procedure dip!-nc!-ev!-prod(bc1,ev1,bc2,ev2);
  % compute (bc1*ev1) * (bc2*ev2). Result is a dip.
   dip!-nc!-ev!-prod1(ev1,1,dipfmon(bcprod(bc1,bc2),ev2));

symbolic procedure dip!-nc!-ev!-prod1(ev,n,r);
  % loop over ev and n (counter). NOTE: ev must
  % be processed from right to left!
   if null ev then r else
      dip!-nc!-ev!-prod2(car ev,n,
         dip!-nc!-ev!-prod1(cdr ev,n#+1,r));


symbolic procedure dip!-nc!-ev!-prod2(j,n,r);
  % muliply x_n^j * r
  if j=0 or dipzero!? r then r else
 begin scalar ev,bc,r0,w,s,evl,evr; integer i;
    ev := dipevlmon r; bc:= diplbc r;
    r := dip!-nc!-ev!-prod2(j,n,dipmred r);
     % collect the variables in ev which do not commute
     % with x_n;
    w:=getv(ncdipbase!*,n);
    while w and nth(ev,car w)=0 do w:=cdr w;
     % no commutator?
    if null w then
      <<r0:=dipfmon(bc,dipevadd1var(j,n,ev));
        return dipsum(r0,r)>>;

     % we handle now the leftmost commutator and
     % push the rest of the problem down to the recursion:
     % split the monmial into parts left and
     % right of the noncom variable and multiply these.
    w:=car w; s:=nth(ev,w);
     % split the ev into left and right part.
    i:=0; for each e in ev do
    <<i:=i#+1; if i<w then <<evl:=e .evl;evr:=0 .evr>>
          else if i=w then <<evl:=0 .evl;evr:=0 .evr>>
          else             <<evl:=0 .evl;evr:=e .evr>>;
    >>;
    evl:=reversip evl; evr:=reversip evr;
    r0:=dip!-nc!-get!-commutator(n,j,w,s);
         % multiply by left exponent
    r0:=if ncdipcircular!* then
       <<r0:=dip!-nc!-prod(dipfmon(a2bc 1,evl),r0) ;
         r0:=dip!-nc!-prod(r0,dipfmon(bc,evr))
       >> else
       <<r0:=dipprod(dipfmon(a2bc 1,evl),r0) ;
         r0:=dipprod(r0,dipfmon(bc,evr))
       >>;

  done:
    return dipsum(r0,r);
  end;

symbolic procedure dip!-nc!-get!-commutator(n1,e1,n2,e2);
  % Compute the commutator for y^e1 * x^e2 where y is
  % the n1-th variable and x is the n2-th variable.
  %
  % The commutators for power products are computed
  % recursively when needed. They are stored in a data base.
  % I assume here that the commutator for (1,1) has been
  % put into the data base before. We update the table
  % in place by nconc-ing new pairs to its end.
  begin scalar w,r,p;
    w:=getv(getv(ncdiptable!*,n1),n2); p:=e1 . e2;
    if (r:=assoc(p,w)) then return cdr r;
      % compute new commutator recursively:
      % first e1 downwards, then e2
    r := if e1>1 then
      % compute y^e1 * x^e2 as  y * (y^(e1-1) * x^e2)
       dip!-nc!-ev!-prod2(1,n1,
             dip!-nc!-get!-commutator(n1,e1#-1,n2,e2))
     else
      % compute y * x^e2 as  (y * x^(e2-1)) * x
       dip!-nc!-prod(dip!-nc!-get!-commutator(n1,1,n2,e2#-1),
                     dipfvarindex n2);
    nconc(w,{(p.r)});
    return r;
  end;

symbolic procedure dipfvarindex n;
  % make a dip from a single variable index;
    a2dip nth(dipvars!*,n);


symbolic procedure dipevadd1var(e,n,ev);
  % add e into the nth position of ev.
   if null ev or n<1 then ev else
   if n=1 then (car ev #+ e) . cdr ev else
   car ev . dipevadd1var(e,n#-1,cdr ev);

% ============ conversion algebraic => NC DIP===============

symbolic procedure a2ncdip a;
  if atom a then a2dip a else
  if car a = 'difference then
   a2ncdip {'plus,cadr a,{'times,-1,caddr a}} else
  if car a = 'minus then
   a2ncdip {'times,-1,cadr a} else
  if car a = 'expt and fixp caddr a then
   a2ncdip ('times.for i:=1:caddr a collect cadr a) else
  if car a = 'plus then
   begin scalar r;
     r:=a2ncdip cadr a;
     for each w in cddr a do r:=dipsum(r,a2ncdip w);
     return r;
   end  else
  if car a = 'times then
   begin scalar r;
     r:=a2ncdip cadr a;
     for each w in cddr a do r:=dip!-nc!-prod(r,a2ncdip w);
     return r;
   end  else
  if car a = '!*sq then a2ncdip prepsq cadr a else
  a2dip a;

symbolic procedure a2ncvdp a; dip2vdp a2ncdip a;

endmodule;


module ncgroeb; % Groebner for noncommutative one sided ideals.

% Author: H. Melenk, ZIB Berlin, J. Apel, University of Leipzig.

% Following Carlo Traverso's model.

fluid '(pcount!*
        ncdipbase!*
        ncdipvars!*
        !*gsugar
        !*nc!-traverso!-sloppy
        !*trgroebfull    % print a full trace
        !*ncg!-right     % if t, compute in right ideal
        nccof!*          % cofactors after a reduction step
     );

switch gsugar;

symbolic procedure nc!-groebeval u;
  begin scalar g;
    nc!-gsetup();
    u:=car u;
    g := for each p in cdr listeval(u,nil) collect a2ncvdp reval p;
    g := nc!-traverso g;
    return 'list.for each w in g collect vdp2a w;
  end;

put('nc_groebner,'psopfn,'nc!-groebeval);

symbolic procedure nc!-preduce u;
  begin scalar g,p,!*gsugar;
    nc!-gsetup();
    g := for each p in cdr listeval(cadr u,nil) collect a2ncvdp reval p;
    p := a2ncvdp reval car u;
    p := nc!-normalform(p,g,nil,nil);
    return vdp2a p;
  end;

put('nc_preduce,'psopfn,'nc!-preduce);

symbolic procedure nc!-div u;
  begin scalar g,p,!*gsugar;
    nc!-gsetup();
    g := a2ncvdp reval cadr u;
    p := a2ncvdp reval car u;
    p := nc!-qremf(p,g);
    return {'list,vdp2a car p,vdp2a cdr p};
  end;

put('nc_divide,'psopfn,'nc!-div);

symbolic procedure nc!-gsetup();
 <<    factortime!* := 0;
       groetime!*   := time();
       vdpinit2 ncdipvars!*;
       vdponepol(); % we construct dynamically
       hcount!* := 0; mcount!* := 0; fcount!* := 0; pcount!* := 0;
       bcount!* := 0; b4count!* := 0; hzerocount!* := 0;
       basecount!* := 0; !*gcd := t; glterms := list('list);
       groecontcount!* := 10;
       !*nc!-traverso!-sloppy:=t;
       !*vdpinteger:=t;
       if null ncdipbase!* then
        rederr "non-commutative ideal initialization missing";
>>;

!*gsugar := t;

symbolic procedure nc!-traverso g0;
  begin scalar g,d,s,h,p;

  g0:=for each fj in g0 collect
                gsetsugar(vdpenumerate vdpsimpcont fj,nil);

  main_loop:
    if null g0 and null d then return nc!-traverso!-final g;

    if g0 then
         <<h:=car g0;g0:=cdr g0;
           p := list(nil,h,h)
         >>
       else
         <<p := car d;
           d := cdr d;
           s := nc!-spoly (cadr p, caddr p);
                  !*trgroeb and groebmess3 (p,s);
           h:=groebsimpcontnormalform nc!-normalform(s,g,'list,t);
           if vdpzero!? h then
           <<!*trgroeb and groebmess4(p,d); goto main_loop>>;

            if vevzero!? vdpevlmon h then % base 1 found
                  <<   !*trgroeb and groebmess5(p,h);
                       d:=g:=g0:=nil;
                  >>;
         >>;

         h := groebenumerate h; !*trgroeb and groebmess5(p,h);

          % new pair list
         d := nc!-traverso!-pairlist(h,g,d);

          % new basis
         g := nconc(g,{h});
         goto main_loop;
   end;

symbolic procedure nc!-traverso!-pairlist(gk,g,d);
  % gk: new polynomial,
  % g:  current basis,
  % d:  old pair list.
  begin scalar ev,r,n,nn,q;
     % delete triange relations from old pair list.
    d := nc!-traverso!-pairs!-discard1(gk,d);

     % build new pair list.
    ev := vdpevlmon gk;

    for each p in g do n := groebmakepair(p,gk) . n;

     % discard multiples: collect survivers in n

    <<
      if !*nc!-traverso!-sloppy then !*gsugar:=nil;
      n := groebcplistsort(n)
    >>   where !*gsugar=!*gsugar;

    nn := n; n:=nil;
    for each p in nn do
    <<q:=nil;
      for each r in n do
        q:=q or vevdivides!?(car r,car p);
      if not q then n:=groebcplistsortin(p,n);
    >>;

    return groebcplistmerge(d,reversip n);
  end;

symbolic procedure nc!-traverso!-pairs!-discard1(gk,d);
  % crit B
  begin scalar gi,gj,tij,evk;
   evk:=vdpevlmon gk;
   for each pij in d do
   <<tij := car pij; gi:=cadr pij; gj:=caddr pij;
    if vevstrictlydivides!?(tt(gi,gk),tij)
       and vevstrictlydivides!?(tt(gj,gk),tij)
      then d:=delete(pij,d);
   >>;
   return d;
  end;

symbolic procedure vevstrictlydivides!?(ev1,ev2);
   not(ev1=ev2) and vevdivides!?(ev1,ev2);

symbolic procedure nc!-traverso!-final g;
  % final reduction and sorting;
  begin scalar r,p,!*gsugar;
   g:=vdplsort g; % descending
   while g do
   <<p:=car g; g:=cdr g;
     if not groebsearchinlist(vdpevlmon p,g) then
       r := groebsimpcontnormalform nc!-normalform(p,g,'list,t) . r;
   >>;
   return reversip r;
  end;

symbolic procedure nc!-fullprint(comm,cu,u,tu,cv,v,tv,r);
  <<terpri(); prin2 "COMPUTE ";prin2t comm;
    vdpprin2 cu; prin2 " * P("; prin2 vdpnumber u; prin2 ")=> ";
    vdpprint tu;
    vdpprin2 cv; prin2 " * P("; prin2 vdpnumber v; prin2 ")=> ";
    vdpprint tv;
    prin2t "               ====>";
    vdpprint r;
    prin2t " - - - - - - -";
  >>;

symbolic procedure nc!-spoly(u,v);
 % Compute S-polynomial.
  begin scalar cu,cv,tu,tv,bl,l,r;
    l := vev!-cofac(vdpevlmon u,vdpevlmon v);
    bl :=vbc!-cofac(vdplbc u,vdplbc v);
    cu := vdpfmon(car bl, car l);
    cv := vdpfmon(cdr bl, cdr l);
    if !*ncg!-right  then
    << tu:=vdp!-nc!-prod(u,cu);
       tv:=vdp!-nc!-prod(v,cv);
    >>
    else
    << tu:=vdp!-nc!-prod(cu,u);
       tv:=vdp!-nc!-prod(cv,v);
    >>;
    nccof!* := cu.cv;
    r:=vdpdif(tu,tv);
    if !*trgroebfull then
      nc!-fullprint("S polynomial:",cu,u,tu,cv,v,tv,r);
    return r;
  end;

symbolic procedure nc!-qremf(u,v);
 % compute (u/v, remainder(u,v)).
  begin scalar ev,cv,q;
   q:=a2vdp 0;
   if vdpzero!? u then return q.q;
   ev:=vdpevlmon v; cv:=vdplbc v;
   while not vdpzero!? u and vevdivides!?(ev,vdpevlmon u) do
   <<u:=nc!-reduce1(u,vdplbc u,vdpevlmon u, v);
     q:=if !*ncg!-right then vdp!-nc!-prod(q,car nccof!*)
                        else vdp!-nc!-prod(car nccof!*,q);
     q:=vdpsum(q,cdr nccof!*);
   >>;
   return q.u;
 end;

symbolic procedure nc!-reduce1(u,bu,eu,v);
 % Compute u - w*v such that monomial (bu*x^eu) in u is deleted.
  begin scalar cu,cv,tu,tv,bl,l,r;
    l := vev!-cofac(eu,vdpevlmon v);
    bl :=vbc!-cofac(bu,vdplbc v);
    cu := vdpfmon(car bl, car l);
    cv := vdpfmon(cdr bl, cdr l);
    if !*ncg!-right then
    << tu := vdp!-nc!-prod(u,cu);
       tv := vdp!-nc!-prod(v,cv);
    >>
    else
    << tu := vdp!-nc!-prod(cu,u);
       tv := vdp!-nc!-prod(cv,v);
    >>;
    nccof!* := cu.cv;
    r:=vdpdif(tu,tv);
    if !*trgroebfull then
      nc!-fullprint("Reduction step:",cu,u,tu,cv,v,tv,r);
     %%%% if null yesp "cont" then rederr "abort";
    return r;
  end;

symbolic procedure nc!-normalform(s,g,mode,cmode);
   nc!-normalform2(s,g,cmode);

symbolic procedure nc!-normalform2(s,g,cmode);
 % Normal form 2: full reduction.
  begin scalar g0,ev,f,s1,b;
   loop:
     s1:= s;
        % unwind to last reduction point.
     if ev then while vevcomp(vdpevlmon s1,ev)>0 do s1:=vdpred s1;
    loop2:
     if vdpzero!? s1 then return s;
     ev := vdpevlmon s1; b:=vdplbc s1;
     g0 := g;
     f := nil;
     while null f and g0 do
       if vevdivides!?(vdpevlmon car g0,ev) then f:=car g0 else
         g0:=cdr g0;
     if null f then <<s1:=vdpred s1; goto loop2>>;
     s:=nc!-reduce1(s,b,ev,f);
     if !*trgroebs then <<prin2 "//"; prin2 vdpnumber f>>;
     if cmode then s:=groebsimpcontnormalform s;
     goto loop;
   end;

endmodule;


module ncfactor;  % factorization for non-commutative polynomials.

% Author: H. Melenk, ZIB Berlin, J. Apel, University of Leipzig.

fluid '(nc_factor_time nc_factor_time!* !*trnc !*ncg!-right
        !*bcsubs2 !*gsugar ncpi!-names!* ncmp!* !*complex);

% version 1.4: using the commutative factorizer as preprocessor.

switch trnc;

share nc_factor_time;    % time limit in milliseconds.

nc_factor_time:=0;

algebraic operator cc!*;

symbolic procedure nc_factorize u;
 begin scalar r,o,!*gsugar,comm,cr,cl;
   o := apply1('torder,'(gradlex));
   nc!-gsetup();
   comm := nc_commfactors!* u;
   cl := car comm; u:=cadr comm; cr:= caddr comm;
   if constant_exprp u then (if u neq 1 then cl:=u.cl)
      else
     r:=for each p in nc_factorize0(a2ncvdp u,nil,nil,nil,nil,nil)
          collect num vdp2a p;
   o := apply1('torder,{o});
   return 'list.append(cl,append(r,cr));
 end;

symbolic operator nc_factorize;

% copyd('nc_commfactors!*,'nc_commfactors);
symbolic procedure nc_commfactors u;
 begin scalar o,!*gsugar,comm,cr,cl;
   o := apply1('torder,'(gradlex));
   nc!-gsetup();
   comm := nc_commfactors!* u;
   cl := car comm; u:=cadr comm; cr:= caddr comm;
   o := apply1('torder,{o});
   return {'list, 'list.cl, u, 'list. cr};
 end;

symbolic operator nc_commfactors;

symbolic procedure nc_commfactors!* u;
 (begin scalar f,ff,uu,comm,l,crl,cll,!*ncg!-right,w;
   uu:=sublis(ncpi!-names!*,numr simp u);
   comm := (fctrf reorder uu) where ncmp!*=nil;
   if null cddr comm and cdadr comm = 1 then
   <<if !*trnc then writepri("no commutative factors found",'only);
     goto no_comm
   >>;
   l := for each f in cdr comm join
     for i:=1:cdr f collect reval prepf car f;
   if !*trnc then writepri("testing commutative factors:",'only);
   uu:=a2ncvdp u;
   while l do
   <<
     f:=car l; l:=cdr l;
     if !*trnc then writepri(mkquote f,'first);
     !*ncg!-right := right;
     if vdpzero!? cdr (w:=nc!-qremf(uu,ff:=a2ncvdp f)) then
     <<if !*trnc then writepri(nc_dir(),'last);
       cll:=append(cll, {f}); uu:=car w>>
     else
     if vdpzero!? cdr <<!*ncg!-right := not right;w:=nc!-qremf(uu,ff)>>
       then <<if !*trnc then writepri(nc_dir(),'last);
              crl:=f.crl; uu:=car w>>
     else if !*trnc then writepri(" -- discarded",'last);
   >>;
  if null crl and null cll then goto no_comm;
  u:=vdp2a uu;
  if !*trnc then
    <<writepri("remaining noncom  part:",'first);
      writepri(mkquote u,'last)>>;
 no_comm:
   return {crl,u,cll};
 end) where right =!*ncg!-right;

symbolic procedure nc_dir();
   if !*ncg!-right then " right" else " left";


symbolic procedure oneside!-factor(w,m,all);
 % NOTE: we must perform a factorization based on left
 % division (m='l) for obtaining a right factor.
 begin scalar u,d,r,mx,o,!*gsugar;
    % preprocessing for psopfn.
  d:=r:=0;
  u:=reval car w;
  if cdr w then
  <<d:=reval car (w:=cdr w);
    if cdr w then r:=reval cadr w
  >>;
    % preparing for the altorithm.
  o := apply1('torder,'(gradlex));
  nc!-gsetup();
  if r=0 or r='(list) then r := nil else
  <<r:=cdr listeval(r,nil);
    r:=vdpevlmon a2vdp(if null cdr r then reval car r else
      'times. for each y in r collect reval y)>>;
  d:=reval d;
  if d=0 then d:=1000 else
  if not fixp d then
    <<mx :=vdpevlmon a2vdp d; d:=1000>>;
  r:=nc_factorize0(a2ncvdp u,m,d,r,mx,all);
  o := apply1('torder,{o});
  return for each w in r collect num vdp2a w;
 end;

put('left_factor,'psopfn,
     function (lambda(w);
                <<w:=oneside!-factor(w,'r,nil) or w;
                  reval car w>>));

put('left_factors,'psopfn,
     function (lambda(w); 'list. oneside!-factor(w,'r,t)));

put('right_factor,'psopfn,
     function (lambda(w);
                <<w:=oneside!-factor(w,'l,nil) or w;
                  reval car w>>));

put('right_factors,'psopfn,
     function (lambda(w); 'list. oneside!-factor(w,'l,t)));


algebraic procedure nc_factorize_all u;
  % Compute all possible factorizations based on successive
  % right factor extraction.
 begin scalar !*ncg!-right,d,f,w,wn,q,r,trnc,nc_factor_time!*;
   nc_factor_time!*:=lisp time();
   trnc := lisp !*trnc; lisp(!*trnc:=nil);
   w:={{u}}; r:={}; lisp (!*ncg!-right:=nil);
 loop:
   if w={} then goto done;
   lisp (wn:='(list));
   for each c in w do
   <<lisp(q:= cadr c);
     f:=right_factors(q,{},{});
     if trnc then
           write "ncfctrall: Right factors of (",q,"): ",f;
     if f={} then r:=c.r;
     for each fc in f do
     <<d:=nc_divide(q,fc);
       if trnc then
           write "ncfctrall: Quotient (",q,") / (",fc,"): ",d;
       wn:=(first d.fc.rest c).wn>>
   >>;
   w:=wn; goto loop;
 done:
   lisp(!*trnc:=trnc);
   return r;
 end;

symbolic procedure nc_factorize0(u,m,d,rs,mx,all);
 <<if not numberp nc_factor_time!* then nc_factor_time!* := time();
   nc_factorize1(u,m,d,rs,mx,all)>>
     where nc_factor_time!*=nc_factor_time!*;

symbolic procedure nc_factorize1(u,m,d,rs,mx,all);
 % split all left(right) factor of u off.
 % u:  polynomial,
 % m:  mode: restriction for left or right factor:
 % d:  maximum degree restriction,
 % r:  variable set restriction (r is an exponent vector).
 % mx: maximum exponent for each variable (is an exponent vector).
 % all: true if we look for all right(left) factors.
 begin scalar ev,evl,evlx,f,ff,!*ncg!-right;
  nc_factorize_timecheck();
  mx:=if null mx then for each y in vdpvars!* collect 1000 else
    for each y in mx collect if y>0 then y else 1000;
  if !*trnc then<<prin2 "factorize "; vdpprint u>>;
  ev:=vdpevlmon u;
  if vevzero!? ev then return {u};
  d:=d or vevtdeg ev/2;
  evlx:=sort(nc_factorize1!-evl ev,
              function(lambda(x,y);vevcomp(x,y)<0));
  if m='r then goto r;
    % factors up to n
  evl := evlx;
  while (null f or all) and evl and vevtdeg car evl<=d do
  <<if not vevzero!? car evl
      and car evl neq ev
           % testing support;
      and (null rs or vevmtest!?(car evl,rs))
           % testing maximal degrees;
      and vevmtest!?(mx,car evl)
   then
        f:=append(f,nc_factorize2(u,car evl,rs,mx,all));
    evl:=cdr evl>>;
  if f or m='l then goto c;
    % right factors up to tdg-n
  d:=vevtdeg ev -d;
r: !*ncg!-right:=t;
  evl := evlx;
  while (null f or all) and evl and vevtdeg car evl<=d do
  <<if not vevzero!? car evl
        and car evl neq ev
           % testing support;
        and (null rs or vevmtest!?(car evl,rs))
           % testing maximal degrees;
      and vevmtest!?(mx,car evl)
     then
        f:=append(f,nc_factorize2(u,car evl,rs,mx,all));
    evl:=cdr evl>>;
c:
  if null f then return if m then nil else {u};
  if all then return f;
    % only one factor wanted?
  if m then return {cdr f};
  ff := nc_factorize1(car f,nil,nil,nil,mx,all);
  return if !*ncg!-right then append({cdr f},ff)
     else append(ff,{cdr f});
 end;

symbolic procedure nc_factorize1!-evl u;
  % Collect all monomials dividing u.
   if null u then '(nil) else
   (for i:=0:car u join
     for each e in w collect i.e)
      where w=nc_factorize1!-evl cdr u;

algebraic operator ncc!@;

symbolic procedure nc_factorize2(u,ev,rs,mx,all);
  begin scalar ar,p,q,vl,r,s,so,sol,w,y; integer n;
   scalar !*bcsubs2;
   nc_factorize_timecheck();
   p:=a2dip 0;
   if !*trnc then
   <<prin2 if !*ncg!-right then "right " else "left ";
     prin2 "Ansatz for leading term > ";
     vdpprin2 vdpfmon(a2bc 1,ev);
     prin2 " < time so far:";
     prin2 (time()-nc_factor_time!*);
     prin2t "ms";
   >>;
     % establish formal Ansatz.
   for each e in nc_factorize2evl(ev,rs,mx) do
   <<q:={'ncc!@,n:=n+1};
     p:=dipsum(p,dipfmon(a2vbc q,e))>>;
   w:=p;
   while not dipzero!? w do <<vl:=bc2a diplbc w.vl;w:= dipmred w>>;
   vl:=reversip vl;
   p:=dip2vdp p;
     %  prin2 "complete Ansatz:"; vdpprint p;
     % pseudo division.
   r:=nc!-normalform(u,{p},nil,nil);
   nc_factorize_timecheck();
   while not vdpzero!? r do
   << s:=vbc2a vdplbc r.s; r:=vdpred r>>;
   if !*trnc then
   <<prin2t "internal equation system:";
     writepri(mkquote ('list . s),'only);
   >>;
     % solve system
     % 1. look for a free variable:
     %###### das muss aber die Leitvariable sein!!!
   for each v in vl do
    if not smember(v,s) then so:=v;
   if !*trnc and so then <<prin2 "free:"; prin2t so>>;
   if so then sol:={(so . 1) . for each v in vl collect v . 0};
   if null sol or all then sol:=append(sol,nc_factsolve(s,vl,all));
   if null sol then return nil;
   if !*trnc then
   <<prin2t "internal solutions:";
     for each s in so do
     << for each q in s do
       <<writepri(mkquote car q,'first);
         writepri(mkquote " = ",nil);
         writepri(mkquote cdr q,'last);
       >>;
       prin2t "=====================================";
     >>;
   % prin2 "check internal solution:";
   % for each e in s do writepri(mkquote aeval sublis(so,e),'only);
   >>;

collect:
   nc_factorize_timecheck();
   so := car sol; sol:=cdr sol;
   y:=dip2vdp dippolish dipsubf(so,vdppoly p);
     % leading term preserved?
  % if vdpevlmon y neq vdpevlmon p then
   %  return nil;

   %  prin2 "computed factor:"; vdpprint y;
   if vevzero!? vdpevlmon y then
      if not all then return nil else
      if sol then goto collect else goto done_all;
     % turn on bcsubs2 if there is an algebraic number.
   if smemq('expt,y) or smemq('sqrt,y) or smemq('root_of,y) then
       !*bcsubs2:=t;
   w:=nc!-qremf(u,y);
   if not vdpzero!? cdr w then
    <<prin2 "division failure";
      vdpprint u; prin2t "/";
      vdpprint y; prin2 "=> "; vdpprint car w;
      prin2 "rem: "; vdpprint cdr w;
       rederr "noncom factorize">>;
   if !*trnc then
   <<terpri(); prin2 "splitting into > ";
     vdpprin2 car w; prin2t " < and"; prin2 " > ";
     vdpprin2 y; prin2t " <"; terpri();>>;
   ar:=y.ar;
   if all then if sol then goto collect else goto done_all;
done_one:
   return car w.y;
done_all:
   return ar;
  end;

symbolic procedure nc_factsolve(s,vl,all);
  begin scalar v,sb,ns,so,soa,sol,nz,w,q,z,r,abort;
    % 1st phase: divide out leading term variable,
    % remove zero products, and terminate for explicitly
    % unsolvable system.
   v:= numr simp car vl;
   ns:=for each e in s collect numr simp e;

    % remove factors of leading coefficient,
    % remove trivial parts and propagate them into system.
   r:=t;
   while r do
   <<r:=nil; s:=ns; ns:=nil;
     for each e in s do if not abort then
     <<e:=absf numr subf(e,sb);
       while(q:=quotf(e,v)) do e:=q;
       if null e then nil else
       if domainp e or not(mvar e member vl) then abort:=t else
       if null red e and domainp lc e then
       <<w:=mvar e; sb:=(w . 0).sb; r:=t;
         vl:=delete(w,vl)>>
       else if not member(e,ns) then ns:=e.ns
     >>;
   >>;

   if abort or null vl then return nil;
   nc_factorize_timecheck();

     % all equations solved, free variable(s) left
   if null ns and vl then
   <<sol:={for each x in vl collect x.1};
     goto done>>;

     % solve the system.
   s:=for each e in ns collect prepf e;
   if !*trnc then
    <<prin2 "solving ";
      prin2 length s; prin2 " polynomial equations for ";
      prin2 length vl;
      prin2t "variables";
      for each e in s do writepri(mkquote e,'only);>>;
   w:=(cdr solveeval{'list.s,'list.vl} where dipvars!*=nil);
     % select appropiate solution.
 loop:
   nc_factorize_timecheck();
   if null w then goto done;
   so:= cdr car w; w:=cdr w; soa:=nil;
   if smemq('i,so) and null !*complex then go to loop;
     % Insert values for non occuring variables.
   for each y in vl do if not smember(y,so) then
       <<soa:=(y . 1) . soa; nz:=t>>;
   for each y in so do
   <<z:=nc_factorize_unwrap(reval caddr y,soa);
     nz:=nz or z neq 0;
     soa:=(cadr y . z).soa;
   >>;
     % don't accept solution with leading term 0.
   if not nz then goto loop;
   q:=assoc(car vl,soa);
   if null q or cdr q=0 then goto loop;
   sol:=soa.sol;
   if all then goto loop;
 done:
   sol:=for each s in sol collect append(sb,s);
   if !*trnc then
    <<prin2t "solutions:";
      for each w in sol do
       writepri(mkquote('list.
         for each s in w collect {'equal,car s,cdr s}),'only);
      prin2t "-------------------------";
    >>;
   return sol;
  end;

symbolic procedure dipsubf(a,u);
  % construct polynomial u with coefficients from a.
 if dipzero!? u then nil else
  <<q:=if q then cdr q else diplbc u;
    if q neq 0 then dipmoncomp(a2bc q,dipevlmon u,r) else r>>
      where q=assoc(bc2a diplbc u,a), r=dipsubf(a,dipmred u);

symbolic procedure dippolish p1;
   diprectoint(p1,diplcm p1);

symbolic procedure nc_factorize_unwrap(u,s);
   if atom u then u else
   if eqcar(u,'arbcomplex) then 1 else
   (if q then cdr q else
   for each x in u collect nc_factorize_unwrap(x,s))
       where q=assoc(u,s);

symbolic procedure nc_factorize2evl(ev,rs,mx);
  % make list of monomials below ev in gradlex ordering,
  % but only those which occur in rs (if that is non-nil)
  % and which have the maximal degress of mx.
   for each q in nc_factorize2!-evl1(evtdeg ev,length ev,rs)
      join if not vevcompless!?(ev,q)
              and vevmtest!?(mx,q) then {q};

symbolic procedure nc_factorize2!-evl1(n,m,rs);
  % Collect all m-monomials with total degree <n.
   if m=0 then '(nil) else
   for i:=0: (if null rs or car rs>0 then n else 0) join
     for each e in nc_factorize2!-evl1(n#-i,m#-1,if rs then cdr rs)
       collect i.e;

symbolic procedure nc_factorize_timecheck();
   if fixp nc_factor_time and nc_factor_time>0 and
     (time() - nc_factor_time!*) > nc_factor_time
       then rederr "time overflow in noncom. factorization";

endmodule;


module nout; % Output of noncom polynomials.

% Author: H. Melenk, ZIB Berlin, J. Apel, University of Leipzig

% Copyright: Konrad-Zuse-Zentrum Berlin, 1994

fluid '(ncpi!-brackets!*
        ncpi!-comm!-rules!*
        ncpi!-name!-rules!*
        ncpi!-names!*
        !*ncg!-right
      );

symbolic procedure nc_compact u;
 % write a polynomial in factored form.
 begin scalar vl,t1,t2,y,r,d,w;
  vl := intersection(kord!*,for each y in ncpi!-names!* collect car y);
  for each x in vl do
    <<y:=gensym(); t1:=(x.y).t1; t2:=(y.x).t2>>;
  w := simp u where !*factor=nil, !*factors=nil, !*exp=t;
  d:=denr w;
  r:= nc_compactr(numr w,reverse vl,t1,t2);
  return mk!*sq (r ./ d);
 end;

symbolic procedure nc_compactr(u,vl,t1,t2);
  begin scalar x,xn,y,q,w,r,s;
    integer n,m;
  x:=car vl; vl := cdr vl;
  w:=nc_compactd u;
  n:=-1;
loop:
  if null w then goto done;
  n:=n+1;
  xn := if n=0 then 1 else x .** n .* 1 .+ nil;
  q := nc_compactx(w,x,xn);
  w :=cdr q; q :=car q;
  if q then
  begin scalar !*factor,!*exp;
     if null vl or null cdr vl or 2>
       <<m:=0; for each y in vl do if smember(y,q) then m:=m+1;m>>
     then
      <<q:='plus.for each s in q collect prepf sublis(t1,s);
        !*factor:=t;
        q:=reorder sublis(t2,numr simp reval1(q,nil));
      >>
     else
      <<s:=nil; for each f in q do s:=addf(s,f);
        q:=nc_compactr(s,vl,t1,t2);
      >>;
     r:=addf(multf(q,xn), r);
  end;
  goto loop;
done:
  return r;
 end;

symbolic operator nc_compact;

symbolic procedure nc_compactd u;
  % convert standard form into list (=sum) of monomials.
    if domainp u then {u} else
    append(for each s in nc_compactd lc u collect lpow u .* s .+nil,
           red u and nc_compactd red u);

symbolic procedure nc_compactx(u,x,xn);
  % Extract sum of terms which contain multiples of power xn.
  % Divide xn out.
 begin scalar yes,no,w;
   for each r in u do
    if xn=1 and not smember(x,r) then yes:=r.yes
       else
    if (w:=quotf(r,xn)) and not smember(x,w) then yes:=w.yes
       else  no:=r.no;
   return yes.no;
 end;

endmodule;


end;
