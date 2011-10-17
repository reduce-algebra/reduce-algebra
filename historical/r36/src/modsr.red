module modsr; % Modular Solve and Roots.

% Author: Herbert Melenk, ZIB Berlin, Jan 95.

create!-package('(modsr modsqrt modroots modsolve),'(solve));

fluid '(current!-modulus);

% Some routines from solve and factor(modpoly) are needed.

load!-package 'solve;
load!-package 'factor;

% Now a few things that MIGHT have been in the factorizer but were not
% It is quite possible that as a matter of style these few functions
% should be put into factor.red, even though they are not used there,
% since that way they live near their friends and are more generally
% useful???

symbolic procedure general!-evaluate!-mod!-p(a,v,n);
   % Evaluate polynomial A at the point V=N.
    if domainp a then a
    else if n=0 then general!-evaluate!-mod!-p(a,v,nil)
    else if v=nil then errorf "Variable=NIL in GENERAL-EVALUATE-MOD-P"
    else if mvar a=v
     then general!-horner!-rule!-mod!-p(lc a,ldeg a,red a,n,v)
    else adjoin!-term(lpow a,
      general!-evaluate!-mod!-p(lc a,v,n),
      general!-evaluate!-mod!-p(red a,v,n));

symbolic procedure general!-horner!-rule!-mod!-p(v,degg,a,n,var);
   % V is the running total, and it must be multiplied by n**deg and
   % added to the value of a at n.
    if domainp a or not(mvar a=var)
      then if null n or zerop n then a
            else <<v:=general!-times!-mod!-p(v,
                         general!-expt!-mod!-p(n,degg));
                   general!-plus!-mod!-p(a,v)>>
    else begin scalar newdeg;
      newdeg:=ldeg a;
      return general!-horner!-rule!-mod!-p(
          if null n or zerop n then lc a
          else general!-plus!-mod!-p(lc a,
             general!-times!-mod!-p(v,
                general!-expt!-mod!-p(n,idifference(degg,newdeg)))),
       newdeg,red a,n,var)
    end;

symbolic procedure general!-expt!-mod!-p(a,n);
   % a**n.
    if n=0 then 1
    else if n=1 then a
    else begin scalar w,x;
     w:=divide(n,2);
     x:=general!-expt!-mod!-p(a,car w);
     x:=general!-times!-mod!-p(x,x);
     if not (cdr w = 0) then x:=general!-times!-mod!-p(x,a);
     return x
    end;

symbolic procedure general!-monic!-mod!-p a;
   % This procedure can only cope with polys that have a numeric
   % leading coeff.
   if a=nil then nil
   else if domainp a then 1
   else if lc a = 1 then a
   else if not domainp lc a then
       errorf "LC NOT NUMERIC IN GENERAL-MONIC-MOD-P"
   else general!-multiply!-by!-constant!-mod!-p(a,
     general!-modular!-reciprocal lc a);

symbolic procedure general!-quotient!-mod!-p(a,b);
   % Truncated quotient of a by b.
    if null b then errorf "B=0 IN GENERAL-QUOTIENT-MOD-P"
    else if domainp b then general!-multiply!-by!-constant!-mod!-p(a,
                             general!-modular!-reciprocal b)
    else if a=nil then nil
    else if domainp a then exact!-quotient!-flag:=nil
    else if mvar a=mvar b then general!-xquotient!-mod!-p(a,b,mvar b)
    else if ordop(mvar a,mvar b) then
       adjoin!-term(lpow a,
          general!-quotient!-mod!-p(lc a,b),
          general!-quotient!-mod!-p(red a,b))
    else exact!-quotient!-flag:=nil;


symbolic procedure general!-xquotient!-mod!-p(a,b,v);
   % Truncated quotient a/b given that b is nontrivial.
    if a=nil then nil
    else if (domainp a) or (not(mvar a=v)) or
      ilessp(ldeg a,ldeg b) then exact!-quotient!-flag:=nil
    else if ldeg a = ldeg b then begin scalar w;
      w:=general!-quotient!-mod!-p(lc a,lc b);
      if general!-difference!-mod!-p(a,general!-times!-mod!-p(w,b)) then
        exact!-quotient!-flag:=nil;
      return w
      end
    else begin scalar term;
      term:=mksp(mvar a,idifference(ldeg a,ldeg b)) .*
        general!-quotient!-mod!-p(lc a,lc b);
   % That is the leading term of the quotient.  Now subtract term*b from
   % a.
      a:=general!-plus!-mod!-p(red a,
                general!-times!-term!-mod!-p(general!-negate!-term term,
                                             red b));
   % or a:=a-b*term given leading terms must cancel.
      return term .+ general!-xquotient!-mod!-p(a,b,v)
    end;

symbolic procedure general!-negate!-term term;
   % Negate a term.
    tpow term .* general!-minus!-mod!-p tc term;


symbolic procedure general!-remainder!-mod!-p(a,b);
   % Remainder when a is divided by b.
    if null b then errorf "B=0 IN GENERAL-REMAINDER-MOD-P"
    else if domainp b then nil
    else if domainp a then a
    else general!-xremainder!-mod!-p(a,b,mvar b);


symbolic procedure general!-xremainder!-mod!-p(a,b,v);
   % Remainder when the modular polynomial a is divided by b, given that
   % b is non degenerate.
   if (domainp a) or (not(mvar a=v)) or ilessp(ldeg a,ldeg b) then a
   else begin
    scalar q,w;
    q:=general!-quotient!-mod!-p(general!-minus!-mod!-p lc a,lc b);
   % compute -lc of quotient.
    w:=idifference(ldeg a,ldeg b); %ldeg of quotient;
    if w=0 then a:=general!-plus!-mod!-p(red a,
      general!-multiply!-by!-constant!-mod!-p(red b,q))
    else
      a:=general!-plus!-mod!-p(red a,general!-times!-term!-mod!-p(
            mksp(mvar b,w) .* q,red b));
   % The above lines of code use red a and red b because by construc-
   % tion the leading terms of the required % answers will cancel out.
     return general!-xremainder!-mod!-p(a,b,v)
   end;

symbolic procedure general!-multiply!-by!-constant!-mod!-p(a,n);
   % Multiply the polynomial a by the constant n.
   if null a then nil
   else if n=1 then a
   else if domainp a then !*n2f general!-modular!-times(a,n)
   else adjoin!-term(lpow a,
                     general!-multiply!-by!-constant!-mod!-p(lc a,n),
     general!-multiply!-by!-constant!-mod!-p(red a,n));

symbolic procedure general!-gcd!-mod!-p(a,b);
   % Return the monic gcd of the two modular univariate polynomials a
   % and b.  Set REDUCTION-COUNT to the number of steps taken in the
   % process.
 << reduction!-count := 0;
    if null a then monic!-mod!-p b
    else if null b then monic!-mod!-p a
    else if domainp a then 1
    else if domainp b then 1
    else if igreaterp(ldeg a,ldeg b) then
      general!-ordered!-gcd!-mod!-p(a,b)
    else general!-ordered!-gcd!-mod!-p(b,a) >>;

symbolic procedure general!-ordered!-gcd!-mod!-p(a,b);
   % As above, but deg a > deg b.
  begin scalar steps;
    steps := 0;
top:
    a := general!-reduce!-degree!-mod!-p(a,b);
    if null a then return general!-monic!-mod!-p b;
    steps := steps + 1;
    if domainp a then <<
        reduction!-count := reduction!-count+steps;
        return 1 >>
    else if ldeg a<ldeg b then begin
      scalar w;
      reduction!-count := reduction!-count + steps;
      steps := 0;
      w := a; a := b; b := w
      end;
    go to top
  end;

symbolic procedure general!-reduce!-degree!-mod!-p(a,b);
   % Compute A-Q*B where Q is a single term chosen so that the result
   % has lower degree than A did.
  begin
    scalar q,w;
    q:=general!-modular!-quotient(general!-modular!-minus lc a,lc b);
   % compute -lc of quotient;
    w:=idifference(ldeg a,ldeg b); %ldeg of quotient;
   % The next lines of code use red a and red b because by construction
   % the leading terms of the required answers will cancel out.
    if w=0 then return general!-plus!-mod!-p(red a,
      general!-multiply!-by!-constant!-mod!-p(red b,q))
    else return general!-plus!-mod!-p(red a,
                   general!-times!-term!-mod!-p(mksp(mvar b,w) .* q,
                                                red b))
   end;


%%%%%%%

symbolic procedure modp(a,p);
   <<a:=remainder(a,p); if a<0 then a+p else a>>;

symbolic procedure lowestdeg(f,x,n);
   if null f then n else
   if domainp f or mvar f neq x then 0 else
   lowestdeg(red f,x,ldeg f);

symbolic procedure reduce!-mod!-p!*(f,p);
  (general!-reduce!-mod!-p f) where current!-modulus = p;

symbolic procedure moduntag f;
  if eqcar(f,'!:mod!:) then cdr f else
  if atom f then f else
  moduntag car f . moduntag cdr f;

symbolic procedure safe!-modrecip u;
  % return 1/u or nil.
  begin scalar q,!*msg,!*protfg;
   !*msg=nil;!*protfg:=t;
   if eqcar(u,'!:mod!:) then u:=cdr u;
   q=errorset({'general!-modular!-reciprocal, u},nil,nil);
   erfg!*:=nil;
   return if errorp q then nil else car q;
  end;

endmodule;


module modsqrt; % SQRT n mod p, n integer, p prime.
% Sqrt mod p, p prime.


symbolic procedure modsqrt(a,p);
  <<if not fixp p or p<2 then typerr(p,"modulus for root computation");
    a:=general!-modular!-number a;
      % The break even point between primitive and general algorithm
      % has been evaluated on a 486. For machines without hardware
      % support for integer division, the limit might be set higher.
    if p<50 then modsqrt1(a,p) else modsqrt2(a,p)>>
       where current!-modulus=p;

symbolic procedure modsqrt1(a,p);
  % Primitve but fast algorithm for small p: check all possible values.
   begin integer i,w; scalar r;
     while null r and i<p do
      if w = a then r:=i
        else
        << w:=w #+ i #+ i #+ 1;
           while w #> p do w:=w #- p;
           i:=i#+1;
         >>;
    if null r then typerr({'sqrt,a},"expression mod p");
    return r;
   end;

symbolic procedure modsqrt2(a,p);
 % General algorithm for arbitrary prime p:
 % H. Cohen: Computational Algebraic Number theory, 1.5.1
   begin integer a,b,m,r,y,e,p,q,tt,n,p!-1,x,z;
     x:=a; p!-1:=p-1;
     q:=p-1;
     while evenp q do <<q:=q/2;e:=e+1>>;

 s1: repeat n:=random(p) until legendre!-symbol(n,p)=p!-1;
     z:=general!-modular!-expt(n,q);

 s2: y:=z; r:=e; x:=general!-modular!-expt(a,(q-1)/2);
     b:=modp(a*x*x,p); x:=modp(a*x,p);

 s3: if modp(b,p)=1 then return x;
     m:=0;
     repeat m:=m+1 until general!-modular!-expt(b,expt(2,m)) = 1 or m=r;
     if m=r then typerr({'sqrt,a},"expression mod p");

 s4: tt:= general!-modular!-expt(y,expt(2,r-m-1));
     y:= general!-modular!-times(tt,tt); r:=m;
     x:=general!-modular!-times(x,tt);
     b:=general!-modular!-times(b,y);
     goto s3;
   end;


symbolic procedure legendre!-symbol(a,p);
   general!-modular!-expt(a,(p-1)/2);

symbolic procedure modsqrt!*(u);
    %  print {"we got through:", u};
    !*modular2f modsqrt(cdr u,current!-modulus);

put('sqrt,'!:mod!:,'modsqrt!*);

endmodule;


module modroots; % Roots of a univariate polynomial mod m,
                 % m not necessarily prime.

% Author: Herbert Melenk, ZIB Berlin.

% Algebraic interface: m_roots(polynomial, modulus);

symbolic procedure modroots0(f,m);
 % f: univariate standard form with modular coeffients,
 % m: positive integer modulus.
 % Algorithm: compute roots modulo the biggest factor of m
 % and lift these for the remaining factors. During lifing
 % the number of factors may change in both directions.
 begin scalar ml;
   ml := sort(for each q in zfactor m join
                for i:=1:cdr q collect car q,'lessp);
   return sort(modroots1(f,ml),'lessp);
 end;

symbolic procedure modroots1(f,ml);
   if null cdr ml then modroots2(f,car ml,nil) else
  begin scalar f1,p,q,pq,r,s,x,y;
    p:=car ml; ml:=cdr ml;
    r := modroots1(f,ml);
    if null r then return nil;
    x:=mvar f; y:=gensym();
    q:=for each m in ml product m;
    pq:=p*q;
     % lift roots to p*q:
     %   if f(r)=0 mod q, solve f(n*q+r)=0 mod p.
    for each w in r do
    <<f1:=numr subf(f,{x . {'plus,{'times,y,q},w}});
      for each y in modroots2(reduce!-mod!-p!*(f1,p),p,t)
        do <<y:= modp(y*q+w,pq);
             if null reduce!-mod!-p!*(numr subf(f,{x . y}),pq)
               and not member(y,s) then s:=y.s>>;
    >>;
    return s;
  end;

symbolic procedure modroots2(f,p,rec);
  if domainp f and f then nil
  else if null f then
    if p=2 and rec then '(-1 0 1)
      else for i:=0:(p-1) collect i
  else if p=2 then modroots4(f,t,rec)
  else modroots3(f,p);

symbolic procedure x!*!*p!-w(x,p,w);
  % Make a form x^p - w mod p.
    general!-difference!-mod!-p(x .** p .*1 .+ nil,w);

symbolic procedure modroots3(f,current!-modulus);
 % Roots of a polynomial f mod p, p prime.
 % Algorithm:
 % H. Cohen: Computational Algebraic Number theory, 1.6.1
 begin scalar a,d,p,r,x;  integer n;

     % From now on, we compute with untagged modular coefficients
     % using the routines in "factor/modpoly".
   p := current!-modulus;
   f := general!-reduce!-mod!-p f;
   x := mvar f;

     % gcd(f, x^p - x)
   a := general!-gcd!-mod!-p(f , x!*!*p!-w(x,p,!*k2f x));
   d := ldeg a;
   n := lowestdeg(a,x,0);
   if n>0 then
   <<r:='(0); a:=general!-quotient!-mod!-p(a,x!*!*p!-w(x,n,nil))>>;
   return append(r,modroots31(a,x,p));
 end;

symbolic procedure modroots31(a,x,p);
  begin scalar a0,a1,a2,b,d,e,s,w;

  s2:
   if domainp a then return nil;
   if ldeg a = 1 then
      return {general!-modular!-quotient(
                 if red a then general!-modular!-minus red a else 0,
                 lc a)};
   if ldeg a = 2 then
   <<
     a2:=lc a; a:=red a;
     if not domainp a then
     <<a1:= lc a; a:=red a>> else a1:=0;
     a0:=if null a then 0 else a;
     d:=general!-modular!-difference(
           general!-modular!-times(a1,a1),
           general!-modular!-times(4,general!-modular!-times(a0,a2)));
     s:=legendre!-symbol(d,p);
     if s=-1 then return nil;
     e:= modsqrt(d,p);
     a2:=general!-modular!-reciprocal general!-modular!-plus(a2,a2);
     a1:=general!-modular!-minus a1;
     return
      {general!-modular!-times(general!-modular!-plus(a1,e),a2),
       general!-modular!-times(general!-modular!-difference(a1,e),a2)};
   >>;

   s3:
    e:=random(p);
      % compute gcd[x ^((p-1)/2) - 1, A(x - e)]
    w:=x!*!*p!-w(x,(p-1)/2,1);
    a1:=general!-reduce!-mod!-p numr subf(a,{x.{'difference,x,e}});
    b:=general!-gcd!-mod!-p(w,a1);
    if domainp b or ldeg b = ldeg a then go to s3;

   s4:
     % Compute both root groups and transform roots back to x - e;
    return
    for each w in union(modroots31(general!-quotient!-mod!-p(a1,b),x,p),
                        modroots31(b,x,p))
       collect general!-modular!-difference(w,e)
 end;

symbolic procedure modroots4(f,w,rec);
  % roots of f mod 2: count terms.
  if domainp f then
  <<
   if f then w:=not w;
   append(
    if null f then '(0),
    if w then (if rec then '(-1 1) else '(1))
         )
  >>
  else modroots4(red f,not w,rec);

put('m_roots,'psopfn,
      function(lambda(u);
               'list . modroots0(numr simp car u,reval cadr u)));

endmodule;


module modsolve; % Solve modular.

% Author:       Herbert Melenk <melenk@zib-berlin.dbp.de>

% Algebraic interface: m_solve(eqn/eqnlist [,variables]).

% Some routines from solve and factor(modpoly) are needed.

fluid '(!*trnonlnr );

load!-package 'solve;
load!-package 'factor;

put('m_solve,'psopfn,'msolve);

symbolic procedure msolve(u);
  begin scalar s,s1,v,v1,w;
   s:=reval car u;
   s:=if eqcar(s,'list) then cdr s else {s};
   if cdr u then
   <<v:= reval cadr u;
     v:=if eqcar(v,'list) then cdr v else {v};
   >>;
   % test, collect variables.
   s1:=for each q in s collect
   <<if eqcar(q,'equal) then q:='difference.cdr q;
     w:=numr simp q ./ 1; v1:=union(v1,solvevars{w});
     numr w>>;
   if null v then v:=v1;
   return msolve!-result
      if length s1 = 1
                  then msolve!-poly(car s1,v)
                  else msolve!-psys(s1,v);
  end;

symbolic procedure msolve!-result u;
 if u='failed then u else
  'list . for each v in u collect
     'list . for each w in v collect {'equal,car w,cdr w};

symbolic procedure msolvesys(s1,v,tg);
 % Interface for the Solve package.
  begin scalar w,fail;
   if null cdr s1 then
     <<w:= msolve!-poly(car s1,v); goto done>>;
     % Reject parametric modular equation system.
   for each p in s1 do
     for each x in kernels p do
       if not member(x,v) then fail:=t;
   if fail then
    << if !*trnonlnr
         then lprim "cannot solve parametric modular system";
       go to failed>>;
   w:= msolve!-psys(s1,v);
   if w='failed then go to failed;
 done:
   w:=for each q in w collect
     {for each r in q collect simp cdr r,
      for each r in q collect car r, 1};
   return if tg then t.w else w;
 failed:
   return if tg then '(failed) else 'failed;
  end;

symbolic procedure msolve!-poly1(f,x);
  % polynomial f(x);
 begin scalar w,l;
  if ldeg f = 1 then
   <<w:=safe!-modrecip  lc f;
     erfg!*:=nil;
     if null w then go to enum;
     w:=moduntag multf(w,negf red f);
     if w and (w< 0 or w>current!-modulus)
             then w:=general!-modular!-number w;
     w:={w};
     go to done;
    >>;
 enum:
    l := lowestdeg(f,x,0);
    if l>0 then f:=quotf(f,numr simp {'expt,x,l});
    f:=general!-reduce!-mod!-p moduntag f;
    w:=for i:=1:current!-modulus -1 join
      if null general!-evaluate!-mod!-p(f,x,i) then {i};
    if l>0 then w:=append(w,{nil});
 done:
    return for each q in w collect {x.prepf q};
 end;

symbolic procedure msolve!-poly(f,l);
  % Solve one polynomial wrt several variables.
  begin scalar x,vl;
   vl := kernels f;
   for each x in l do
    <<if not member(x,vl) then l:=delete(x,l);
      vl := delete(x,vl)>>;
   if null l then return nil;
   if vl then return msolve!-polya(f,l);
   return msolve!-polyn(f,l);
  end;

symbolic procedure msolve!-polyn(f,l);
  ( if null cdr l then msolve!-poly1(f,car l) else
   for i:=0: current!-modulus -1 join
      for each s in msolve!-polyn(numr subf(f,{x.i}),cdr l)
         collect (x.i).s) where x=car l;

symbolic procedure msolve!-polya(f,l);
  % F is a polynomial with variables in l and at least one more
  % formal parameter. F can be solved only if f is linear in one of the
  % variables with an invertible coefficient. Otherwise we must return
  % a root-of expression.
  begin scalar x,c,w;
    for each y in l do if null x then
      if 1=ldeg ((w:=reorder f) where kord!* = {y}) then x:=y;
    if null x then goto none;
    c:=lc w; w:=red w;
    if not domainp c then goto none;
    c:=safe!-modrecip c;
    if null c then goto none;
    return {{x.prepf multf(negf w,c)}};
  none:
    return {{car l. mk!*sq caaar mkrootsof(f./1,car l,1)}};
  end;

symbolic procedure msolve!-psys(s,v);
  % Solve system s for variables v. S has no additional free parameters.
  begin scalar b,o,z,w;
    if current!-modulus * length s >1000
        and primep current!-modulus then
    << % Domain is a field and big problem - compute a GB first.
       load!-package 'groebner; load!-package 'groebnr2;
       o:=apply1('torder,{'list.v,'lex});
       b:=groebnereval{'list.for each p in s collect prepf p};
       z:=gzerodimeval {b};
       % The reverse basis for increasing variable number.
       s:=reversip for each p in cdr b collect numr simp p;
       apply1('torder,cdr o);
    >>
     else
    << % Rearrange system for increasing variable number.
       w:=for each p in s collect
         length(for each x in v join if smemq(x,p) then {x}).p;
       w:= for each p in sort(w,'lesspcar) collect cdr p
    >>;
    return msolve!-psys1(s,v);
  end;

symbolic procedure msolve!-psys1(s,v);
  % Solve system by successive substitution.
  begin scalar w,w1,f,f1;
    w:={nil};
    for each f in s do
    <<w1:=nil;
      for each s in w do
      <<f1:=general!-reduce!-mod!-p moduntag numr subf(f,s);
        if null f1 then w1:=s.w1
        else if domainp f1 then nil
        else for each ns in msolve!-poly(f1,v) do
                 w1:=append(s,ns) . w1
      >>;
      w:=w1;
    >>;
    return w;
  end;

endmodule;


end;
