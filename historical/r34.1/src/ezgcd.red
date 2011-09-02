module ezgcd;  % Header module for ezgcd package.

% Authors: A. C. Norman and P. M. A. Moore.

create!-package('(ezgcd alphas coeffts ezgcdf facmisc facstr interfac
                  linmodp mhensfns modpoly multihen unihens),
                '(factor));

fluid '(!*trallfac !*trfac factor!-level factor!-trace!-list);

factor!-level:=0;  % start with a numeric value.

symbolic procedure !*d2n a; if null a then 0 else a;

symbolic procedure adjoin!-term (p,c,r);
   if null c then r else (p .* c) .+ r;

symbolic smacro procedure ttab n; spaces(n-posn());

symbolic smacro procedure polyzerop u; null u;

symbolic smacro procedure didntgo q; null q;

symbolic smacro procedure depends!-on!-var(a,v);
  (lambda !#!#a; (not domainp !#!#a) and (mvar !#!#a=v)) a;

symbolic procedure errorf u;
   rerror(ezgcd,1,list("Factorizer error:",u));

smacro procedure printstr l; << prin2!* l; terpri!*(nil) >>;

smacro procedure printvar v; printstr v;

smacro procedure prinvar v; prin2!* v;

symbolic smacro procedure factor!-trace action;
begin scalar stream;
  if !*trallfac or (!*trfac and factor!-level = 1) then
    stream := nil . nil
  else
    stream := assoc(factor!-level,factor!-trace!-list);
  if stream then <<
    stream:=wrs cdr stream;
    action;
    wrs stream >>
 end;

symbolic smacro procedure getm2(a,i,j);
   % Store by rows, to ease pivoting process.
   getv(getv(a,i),j);

symbolic smacro procedure putm2(a,i,j,v);
   putv(getv(a,i),j,v);

symbolic smacro procedure !*f2mod u; u;

symbolic smacro procedure !*mod2f u; u;

% A load of access smacros for image sets follow:

symbolic smacro procedure get!-image!-set s; car s;

symbolic smacro procedure get!-chosen!-prime s; cadr s;

symbolic smacro procedure get!-image!-lc s; caddr s;

symbolic smacro procedure get!-image!-mod!-p s; cadr cddr s;

symbolic smacro procedure get!-image!-content s; cadr cdr cddr s;

symbolic smacro procedure get!-image!-poly s; cadr cddr cddr s;

symbolic smacro procedure get!-f!-numvec s; cadr cddr cdddr s;

symbolic smacro procedure put!-image!-poly!-and!-content
   (s,imcont,impol);
  list(get!-image!-set s,
       get!-chosen!-prime s,
       get!-image!-lc s,
       get!-image!-mod!-p s,
       imcont,
       impol,
       get!-f!-numvec s);

symbolic procedure printvec(str1,n,str2,v);
<< for i:=1:n do <<
    prin2!* str1;
    prin2!* i;
    prin2!* str2;
    printsf getv(v,i) >>;
   terpri!*(nil) >>;

endmodule;


module alphas;

% Authors: A. C. Norman and P. M. A. Moore, 1981.

fluid '(alphalist current!-modulus hensel!-growth!-size
        number!-of!-factors);


%********************************************************************;
%
% This section contains access and update functions for the alphas.


symbolic procedure get!-alpha poly;
% Gets the poly and its associated alpha from the current alphalist
% if poly is not on the alphalist then we force an error.
  begin scalar w;
    w:=assoc!-alpha(poly,alphalist);
    if null w then errorf list("Alpha not found for ",poly," in ",
        alphalist);
    return w
  end;

symbolic procedure divide!-all!-alphas n;
% Multiply the factors by n mod p and alter the alphas accordingly.
  begin scalar om,m;
    om:=set!-modulus hensel!-growth!-size;
    m:=modular!-expt(
          modular!-reciprocal modular!-number n,
          number!-of!-factors #- 1);
    alphalist:=for each a in alphalist collect
      (times!-mod!-p(n,car a) . times!-mod!-p(m,cdr a));
    set!-modulus om
  end;

symbolic procedure multiply!-alphas(n,oldpoly,newpoly);
% Multiply all the alphas except the one associated with oldpoly
% by n mod p. also replace oldpoly by newpoly in the alphalist.
  begin scalar om,faca;
    om:=set!-modulus hensel!-growth!-size;
    n:=modular!-number n;
    oldpoly:=reduce!-mod!-p oldpoly;
    faca:=get!-alpha oldpoly;
    alphalist:=delete(faca,alphalist);
    alphalist:=for each a in alphalist collect
      car a . times!-mod!-p(cdr a,n);
    alphalist:=(reduce!-mod!-p newpoly . cdr faca) . alphalist;
    set!-modulus om
  end;

symbolic procedure multiply!-alphas!-recip(n,oldpoly,newpoly);
% Multiply all the alphas except the one associated with oldpoly
% by the reciprocal mod p of n. also replace oldpoly by newpoly.
  begin scalar om,w;
    om:=set!-modulus hensel!-growth!-size;
    n:=modular!-reciprocal modular!-number n;
    w:=multiply!-alphas(n,oldpoly,newpoly);
    set!-modulus om;
    return w
  end;

endmodule;


module coeffts;

% Authors: A. C. Norman and P. M. A. Moore, 1981.

fluid '(!*trfac
        alphalist
        best!-known!-factor!-list
        best!-known!-factors
        coefft!-vectors
        deg!-of!-unknown
        difference!-for!-unknown
        divisor!-for!-unknown
        factor!-level
        factor!-trace!-list
        full!-gcd
        hensel!-growth!-size
        image!-factors
        m!-image!-variable
        multivariate!-factors
        multivariate!-input!-poly
        non!-monic
        number!-of!-factors
        polyzero
        reconstructing!-gcd
        true!-leading!-coeffts
        unknown
        unknowns!-list);


%**********************************************************************;
%  Code for trying to determine more multivariate coefficients
%  by inspection before using multivariate hensel construction.


symbolic procedure determine!-more!-coeffts();
% ...
  begin scalar unknowns!-list,uv,r,w,best!-known!-factor!-list;
    best!-known!-factors:=mkvect number!-of!-factors;
    uv:=mkvect number!-of!-factors;
    for i:=number!-of!-factors step -1 until 1 do
      putv(uv,i,convert!-factor!-to!-termvector(
        getv(image!-factors,i),getv(true!-leading!-coeffts,i)));
    r:=red multivariate!-input!-poly;
            % we know all about the leading coeffts;
    if not depends!-on!-var(r,m!-image!-variable)
      or null(w:=try!-first!-coefft(
              ldeg r,lc r,unknowns!-list,uv)) then <<
      for i:=1:number!-of!-factors do
        putv(best!-known!-factors,i,force!-lc(
          getv(image!-factors,i),getv(true!-leading!-coeffts,i)));
      coefft!-vectors:=uv;
      return nil >>;
    factor!-trace <<
      printstr
         "By exploiting any sparsity wrt the main variable in the";
      printstr "factors, we can try guessing some of the multivariate";
      printstr "coefficients." >>;
    try!-other!-coeffts(r,unknowns!-list,uv);
    w:=convert!-and!-trial!-divide uv;
%   trace!-time
%     if full!-gcd then prin2t "Possible gcd found"
%     else prin2t "Have found some coefficients";
    return set!-up!-globals(uv,w)
  end;

symbolic procedure convert!-factor!-to!-termvector(u,tlc);
% ...
  begin scalar termlist,res,n,slist;
    termlist:=(ldeg u . tlc) . list!-terms!-in!-factor red u;
    res:=mkvect (n:=length termlist);
    for i:=1:n do <<
      slist:=(caar termlist . i) . slist;
      putv(res,i,car termlist);
      termlist:=cdr termlist >>;
    putv(res,0,(n . (n #- 1)));
    unknowns!-list:=(reversip slist) . unknowns!-list;
    return res
  end;

symbolic procedure try!-first!-coefft(n,c,slist,uv);
% ...
  begin scalar combns,unknown,w,l,d,v,m;
    combns:=get!-term(n,slist);
    if (combns='no) or not null cdr combns then return nil;
    l:=car combns;
    for i:=1:number!-of!-factors do <<
      w:=getv(getv(uv,i),car l);    % degree . coefft ;
      if null cdr w then <<
         if unknown then <<c := nil; i := number!-of!-factors + 1>>
          else <<unknown := i . car l; d := car w>>>>
      else <<
        c:=quotf(c,cdr w);
        if didntgo c then i := number!-of!-factors+1>>;
      l:=cdr l >>;
    if didntgo c then return nil;
    putv(v:=getv(uv,car unknown),cdr unknown,(d . c));
    m:=getv(v,0);
    putv(v,0,(car m . (cdr m #- 1)));
    if cdr m = 1 and factors!-complete uv then return 'complete;
    return c
  end;

symbolic procedure solve!-next!-coefft(n,c,slist,uv);
% ...
  begin scalar combns,w,unknown,deg!-of!-unknown,divisor!-for!-unknown,
    difference!-for!-unknown,v;
    difference!-for!-unknown:=polyzero;
    divisor!-for!-unknown:=polyzero;
    combns:=get!-term(n,slist);
    if combns='no then return 'nogood;
    while combns do <<
      w:=split!-term!-list(car combns,uv);
      if w='nogood then combns := nil else combns:=cdr combns >>;
    if w='nogood then return w;
    if null unknown then return;
    w:=quotf(addf(c,negf difference!-for!-unknown),
             divisor!-for!-unknown);
    if didntgo w then return 'nogood;
    putv(v:=getv(uv,car unknown),cdr unknown,(deg!-of!-unknown . w));
    n:=getv(v,0);
    putv(v,0,(car n . (cdr n #- 1)));
    if cdr n = 1 and factors!-complete uv then return 'complete;
    return w
  end;

symbolic procedure split!-term!-list(term!-combn,uv);
% ...
  begin scalar a,v,w;
    a:=1;
    for i:=1:number!-of!-factors do <<
      w:=getv(getv(uv,i),car term!-combn);  % degree . coefft ;
      if null cdr w then
        if v or (unknown and not((i.car term!-combn)=unknown)) then
          <<v:='nogood; i := number!-of!-factors+1>>
        else <<
          unknown:=(i . car term!-combn);
          deg!-of!-unknown:=car w;
          v:=unknown >>
      else a:=multf(a,cdr w);
      if not(v eq 'nogood) then term!-combn:=cdr term!-combn >>;
    if v='nogood then return v;
    if v then divisor!-for!-unknown:=addf(divisor!-for!-unknown,a)
    else difference!-for!-unknown:=addf(difference!-for!-unknown,a);
    return 'ok
  end;

symbolic procedure factors!-complete uv;
% ...
  begin scalar factor!-not!-done,r;
    r:=t;
    for i:=1:number!-of!-factors do
      if not(cdr getv(getv(uv,i),0)=0) then
        if factor!-not!-done then <<r:=nil; i:=number!-of!-factors+1>>
        else factor!-not!-done:=t;
    return r
  end;

symbolic procedure convert!-and!-trial!-divide uv;
% ...
  begin scalar w,r,fdone!-product!-mod!-p,om;
    om:=set!-modulus hensel!-growth!-size;
    fdone!-product!-mod!-p:=1;
    for i:=1:number!-of!-factors do <<
      w:=getv(uv,i);
      w:= if (cdr getv(w,0))=0 then termvector2sf w
        else merge!-terms(getv(image!-factors,i),w);
      r:=quotf(multivariate!-input!-poly,w);
      if didntgo r then best!-known!-factor!-list:=
        ((i . w) . best!-known!-factor!-list)
      else if reconstructing!-gcd and i=1
       then <<full!-gcd:=if non!-monic then car primitive!.parts(
          list w,m!-image!-variable,nil) else w;
          i := number!-of!-factors+1>>
      else <<
        multivariate!-factors:=w . multivariate!-factors;
        fdone!-product!-mod!-p:=times!-mod!-p(
          reduce!-mod!-p getv(image!-factors,i),
          fdone!-product!-mod!-p);
        multivariate!-input!-poly:=r >> >>;
    if full!-gcd then return;
    if null best!-known!-factor!-list then multivariate!-factors:=
      primitive!.parts(multivariate!-factors,m!-image!-variable,nil)
    else if null cdr best!-known!-factor!-list then <<
      if reconstructing!-gcd then
        if not(caar best!-known!-factor!-list=1) then
          errorf("gcd is jiggered in determining other coeffts")
        else full!-gcd:=if non!-monic then car primitive!.parts(
          list multivariate!-input!-poly,
          m!-image!-variable,nil)
          else multivariate!-input!-poly
      else multivariate!-factors:=primitive!.parts(
        multivariate!-input!-poly . multivariate!-factors,
        m!-image!-variable,nil);
      best!-known!-factor!-list:=nil >>;
    factor!-trace <<
      if null best!-known!-factor!-list then
        printstr
           "We have completely determined all the factors this way"
      else if multivariate!-factors then <<
        prin2!* "We have completely determined the following factor";
        printstr if (length multivariate!-factors)=1 then ":" else "s:";
        for each ww in multivariate!-factors do printsf ww >> >>;
    set!-modulus om;
    return fdone!-product!-mod!-p
  end;

symbolic procedure set!-up!-globals(uv,f!-product);
  if null best!-known!-factor!-list or full!-gcd then 'done
  else begin scalar i,r,n,k,flist!-mod!-p,imf,om,savek;
    n:=length best!-known!-factor!-list;
    best!-known!-factors:=mkvect n;
    coefft!-vectors:=mkvect n;
    r:=mkvect n;
    k:=if reconstructing!-gcd then 1 else 0;
    om:=set!-modulus hensel!-growth!-size;
    for each w in best!-known!-factor!-list do <<
      i:=car w; w:=cdr w;
      if reconstructing!-gcd and i=1 then << savek:=k; k:=1 >>
      else k:=k #+ 1;
            % in case we are reconstructing gcd we had better know
            % which is the gcd and which the cofactor - so don't move
            % move the gcd from elt one;
      putv(r,k,imf:=getv(image!-factors,i));
      flist!-mod!-p:=(reduce!-mod!-p imf) . flist!-mod!-p;
      putv(best!-known!-factors,k,w);
      putv(coefft!-vectors,k,getv(uv,i));
      if reconstructing!-gcd and k=1 then k:=savek;
            % restore k if necessary;
      >>;
    if not(n=number!-of!-factors) then <<
      alphalist:=for each modf in flist!-mod!-p collect
        (modf . remainder!-mod!-p(times!-mod!-p(f!-product,
          cdr get!-alpha modf),modf));
      number!-of!-factors:=n >>;
    set!-modulus om;
    image!-factors:=r;
    return 'need! to! reconstruct
  end;

symbolic procedure get!-term(n,l);
% ...
  if n#<0 then 'no
  else if null cdr l then get!-term!-n(n,car l)
  else begin scalar w,res;
    for each fterm in car l do <<
      w:=get!-term(n#-car fterm,cdr l);
      if not(w='no) then res:=
        append(for each v in w collect (cdr fterm . v),res) >>;
    return if null res then 'no else res
  end;

symbolic procedure get!-term!-n(n,u);
  if null u or n #> caar u then 'no
  else if caar u = n then list(cdar u . nil)
  else get!-term!-n(n,cdr u);

endmodule;


module ezgcdf; % Polynomial GCD algorithms.

% Author: A. C. Norman, 1981.

fluid '(!*exp
        !*gcd
        !*heugcd
        !*overview
        !*trfac
        alphalist
        bad!-case
        best!-known!-factors
        current!-modulus
        dmode!*
        factor!-level
        factor!-trace!-list
        full!-gcd
        hensel!-growth!-size
        image!-factors
        image!-set
        irreducible
        kord!*
        m!-image!-variable
        multivariate!-factors
        multivariate!-input!-poly
        non!-monic
        no!-of!-primes!-to!-try
        number!-of!-factors
        prime!-base
        reconstructing!-gcd
        reduced!-degree!-lclst
        reduction!-count
        target!-factor!-count
        true!-leading!-coeffts
        unlucky!-case);

symbolic procedure ezgcdf(u,v);
   % Entry point for REDUCE call in GCDF.
   begin scalar factor!-level;
      factor!-level := 0;
      return poly!-abs gcdlist list(u,v)
   end;

%symbolic procedure simpezgcd u;
% calculate the gcd of the polynomials given as arguments;
%  begin
%    scalar factor!-level,w;
%    factor!-level:=0;
%    u := for each p in u collect <<
%        w := simp!* p;
%        if (denr w neq 1) then
%           rederr "EZGCD requires polynomial arguments";
%        numr w >>;
%    return (poly!-abs gcdlist u) ./ 1
%  end;

%put('ezgcd,'simpfn,'simpezgcd);

symbolic procedure simpnprimitive p;
% Remove any simple numeric factors from the expression P;
  begin
    scalar np,dp;
    if atom p or not atom cdr p then
       rerror(ezgcd,2,"NPRIMITIVE requires just one argument");
    p := simp!* car p;
    if polyzerop(numr p) then return nil ./ 1;
    np := quotfail(numr p,numeric!-content numr p);
    dp := quotfail(denr p,numeric!-content denr p);
    return (np ./ dp)
  end;

put('nprimitive,'simpfn,'simpnprimitive);


symbolic procedure poly!-gcd(u,v);
   %U and V are standard forms.
   %Value is the gcd of U and V;
   begin scalar xexp,z;
        if polyzerop u then return poly!-abs v
         else if polyzerop v then return poly!-abs u
         else if u=1 or v=1 then return 1;
        xexp := !*exp;
        !*exp := t;
        % The case of one argument exactly dividing the other is
        % detected specially here because it is perhaps a fairly
        % common circumstance;
        if quotf1(u,v) then z := v
        else if quotf1(v,u) then z := u
        else if !*gcd then  z := gcdlist list(u,v)
        else z := 1;
        !*exp := xexp;
        return poly!-abs z
   end;

% moved('gcdf,'poly!-gcd);



symbolic procedure ezgcd!-comfac p;
  %P is a standard form
  %CAR of result is lowest common power of leading kernel in
  %every term in P (or NIL). CDR is gcd of all coefficients of
  %powers of leading kernel;
  if domainp p then nil . poly!-abs p
  else if null red p then lpow p . poly!-abs lc p
  else begin
    scalar power,coeflist,var;
    % POWER will be the first part of the answer returned,
    % COEFLIST will collect a list of all coefs in the polynomial
    % P viewed as a poly in its main variable,
    % VAR is the main variable concerned;
    var := mvar p;
    while mvar p=var and not domainp red p do <<
      coeflist := lc p . coeflist;
      p:=red p >>;
    if mvar p=var then <<
      coeflist := lc p . coeflist;
      if null red p then power := lpow p
      else coeflist := red p . coeflist >>
    else coeflist := p . coeflist;
    return power . gcdlist coeflist
  end;

symbolic procedure gcd!-with!-number(n,a);
% n is a number, a is a polynomial - return their gcd, given that
% n is non-zero;
    if n=1 or not atom n or flagp(dmode!*,'field) then 1
    else if domainp a
     then if a=nil then abs n
           else if not atom a then 1
           else gcddd(n,a)
    else gcd!-with!-number(gcd!-with!-number(n,lc a),red a);

% moved('gcdfd,'gcd!-with!-number);


symbolic procedure contents!-with!-respect!-to(p,v);
    if domainp p then nil . poly!-abs p
    else if mvar p=v then ezgcd!-comfac p
    else begin
      scalar w,y;
      y := updkorder v;
      w := ezgcd!-comfac reorder p;
      setkorder y;
      return w
    end;

symbolic procedure numeric!-content form;
% Find numeric content of non-zero polynomial.
   if domainp form then absf form
   else if null red form then numeric!-content lc form
   else begin
     scalar g1;
     g1 := numeric!-content lc form;
     if not (g1=1) then g1 := gcddd(g1,numeric!-content red form);
     return g1
   end;

symbolic procedure gcdlist l;
% Return the GCD of all the polynomials in the list L.
%
% First find all variables mentioned in the polynomials in L,
% and remove monomial content from them all. If in the process
% a constant poly is found, take special action. If then there
% is some variable that is mentioned in all the polys in L, and
% which occurs only linearly in one of them establish that as
% main variable and proceed to GCDLIST3 (which will take
% a special case exit). Otherwise, if there are any variables that
% do not occur in all the polys in L they can not occur in the GCD,
% so take coefficients with respect to them to get a longer list of
% smaller polynomials - restart. Finally we have a set of polys
% all involving exactly the same set of variables;
  if null l then nil
  else if null cdr l then poly!-abs car l
  else if domainp car l then gcdld(cdr l,car l)
  else begin
    scalar l1,gcont,x;
    % Copy L to L1, but on the way detect any domain elements
    % and deal with them specially;
    while not null l do <<
        if null car l then l := cdr l
        else if domainp car l then <<
          l1 := list list gcdld(cdr l,gcdld(mapcarcar l1,car l));
          l := nil >>
        else <<
          l1 := (car l . powers1 car l) . l1;
          l := cdr l >> >>;
    if null l1 then return nil
    else if null cdr l1 then return poly!-abs caar l1;
    % Now L1 is a list where each polynomial is paired with information
    % about the powers of variables in it;
    gcont := nil; % Compute monomial content on things in L;
    x := nil; % First time round flag;
    l := for each p in l1 collect begin
        scalar gcont1,gcont2,w;
        % Set GCONT1 to least power information, and W to power
        % difference;
        w := for each y in cdr p
                collect << gcont1 := (car y . cddr y) . gcont1;
                           car y . (cadr y-cddr y) >>;
        % Now get the monomial content as a standard form (in GCONT2);
        gcont2 := numeric!-content car p;
        if null x then << gcont := gcont1; x := gcont2 >>
        else << gcont := vintersection(gcont,gcont1);
                   % Accumulate monomial gcd;
                x := gcddd(x,gcont2) >>;
        for each q in gcont1 do if not cdr q=0 then
            gcont2 := multf(gcont2,!*p2f mksp(car q,cdr q));
        return quotfail1(car p,gcont2,"Term content division failed")
                  . w
        end;
    % Here X is the numeric part of the final GCD.
    for each q in gcont do x := multf(x,!*p2f mksp(car q,cdr q));
%   trace!-time <<
%     prin2!* "Term gcd = ";
%     printsf x >>;
    return poly!-abs multf(x,gcdlist1 l)
  end;


symbolic procedure gcdlist1 l;
% Items in L are monomial-primitive, and paired with power information.
% Find out what variables are common to all polynomials in L and
% remove all others;
  begin
    scalar unionv,intersectionv,vord,x,l1,reduction!-count;
    unionv := intersectionv := cdar l;
    for each p in cdr l do <<
       unionv := vunion(unionv,cdr p);
       intersectionv := vintersection(intersectionv,cdr p) >>;
    if null intersectionv then return 1;
    for each v in intersectionv do
       unionv := vdelete(v,unionv);
    % Now UNIONV is list of those variables mentioned that
    % are not common to all polynomials;
    intersectionv := sort(intersectionv,function lesspcdr);
    if cdar intersectionv=1 then <<
       % I have found something that is linear in one of its variables;
       vord := mapcarcar append(intersectionv,unionv);
       l1 := setkorder vord;
%      trace!-time <<
%        prin2 "Selecting "; prin2 caar intersectionv;
%        prin2t " as main because some poly is linear in it" >>;
       x := gcdlist3(for each p in l collect reorder car p,nil,vord);
       setkorder l1;
       return reorder x >>
    else if null unionv then return gcdlist2(l,intersectionv);
%   trace!-time <<
%     prin2 "The variables "; prin2 unionv; prin2t " can be removed" >>;
    vord := setkorder mapcarcar append(unionv,intersectionv);
    l1 := nil;
    for each p in l do
        l1:=split!-wrt!-variables(reorder car p,mapcarcar unionv,l1);
    setkorder vord;
    return gcdlist1(for each p in l1 collect
      (reorder p . total!-degree!-in!-powers(p,nil)))
  end;


symbolic procedure gcdlist2(l,vars);
% Here all the variables in VARS are used in every polynomial
% in L. Select a good variable ordering;
  begin
    scalar x,x1,gg,lmodp,onestep,vord,oldmod,image!-set,gcdpow,
           unlucky!-case;
% In the univariate case I do not need to think very hard about
% the selection of a main variable!! ;
    if null cdr vars
      then return if !*heugcd and (x := heu!-gcd!-list(mapcarcar l))
                    then x
                   else gcdlist3(mapcarcar l,nil,list caar vars);
    oldmod := set!-modulus nil;
% If some variable appears at most to degree two in some pair of the
% polynomials then that will do as a main variable.  Note that this is
% not so useful if the two polynomials happen to be duplicates of each
% other, but still... ;

    vars := mapcarcar sort(vars,function greaterpcdr);
% Vars is now arranged with the variable that appears to highest
% degree anywhere in L first, and the rest in descending order;
    l := for each p in l collect car p .
      sort(cdr p,function lesspcdr);
    l := sort(l,function lesspcdadr);
% Each list of degree information in L is sorted with lowest degree
% vars first, and the polynomial with the lowest degree variable
% of all will come first;
    x := intersection(deg2vars(cdar l),deg2vars(cdadr l));
    if not null x then <<
%      trace!-time << prin2 "Two inputs are at worst quadratic in ";
%                     prin2t car x >>;
      go to x!-to!-top >>;   % Here I have found two polys with a common
                             % variable that they are quadratic in;
% Now generate modular images of the gcd to guess its degree wrt
% all possible variables;

% If either (a) modular gcd=1 or (b) modular gcd can be computed with
% just 1 reduction step, use that information to choose a main variable;
try!-again:  % Modular images may be degenerate;
    set!-modulus random!-prime();
    unlucky!-case := nil;
    image!-set := for each v in vars
                   collect (v . modular!-number next!-random!-number());
%   trace!-time <<
%     prin2 "Select variable ordering using P=";
%     prin2 current!-modulus;
%     prin2 " and substitutions from ";
%     prin2t image!-set >>;
    x1 := vars;
try!-vars:
    if null x1 then go to images!-tried;
    lmodp := for each p in l collect make!-image!-mod!-p(car p,car x1);
    if unlucky!-case then go to try!-again;
    lmodp := sort(lmodp,function lesspdeg);
    gg := gcdlist!-mod!-p(car lmodp,cdr lmodp);
    if domainp gg or (reduction!-count<2 and (onestep:=t)) then <<
%          trace!-time << prin2 "Select "; prin2t car x1 >>;
           x := list car x1; go to x!-to!-top >>;
    gcdpow := (car x1 . ldeg gg) . gcdpow;
    x1 := cdr x1;
    go to try!-vars;
images!-tried:
  % In default of anything better to do, use image variable such that
  % degree of gcd wrt it is as large as possible;
    vord := mapcarcar sort(gcdpow,function greaterpcdr);
%   trace!-time << prin2 "Select order by degrees: ";
%                  prin2t gcdpow >>;
    go to order!-chosen;

x!-to!-top:
    for each v in x do vars := delete(v,vars);
    vord := append(x,vars);
order!-chosen:
%   trace!-time << prin2 "Selected Var order = "; prin2t vord >>;
    set!-modulus oldmod;
    vars := setkorder vord;
    x := gcdlist3(for each p in l collect reorder car p,onestep,vord);
    setkorder vars;
    return reorder x
  end;

symbolic procedure gcdlist!-mod!-p(gg,l);
   if null l then gg
   else if gg=1 then 1
   else gcdlist!-mod!-p(gcd!-mod!-p(gg,car l),cdr l);

symbolic procedure deg2vars l;
    if null l then nil
    else if cdar l>2 then nil
    else caar l . deg2vars cdr l;

symbolic procedure vdelete(a,b);
    if null b then nil
    else if car a=caar b then cdr b
    else car b . vdelete(a,cdr b);

symbolic procedure vintersection(a,b);
  begin
    scalar c;
    return if null a then nil
    else if null (c:=assoc(caar a,b)) then vintersection(cdr a,b)
    else if cdar a>cdr c then
      if cdr c=0 then vintersection(cdr a,b)
      else c . vintersection(cdr a,b)
    else if cdar a=0 then vintersection(cdr a,b)
    else car a . vintersection(cdr a,b)
  end;


symbolic procedure vunion(a,b);
  begin
    scalar c;
    return if null a then b
    else if null (c:=assoc(caar a,b)) then car a . vunion(cdr a,b)
    else if cdar a>cdr c then car a . vunion(cdr a,delete(c,b))
    else c . vunion(cdr a,delete(c,b))
  end;


symbolic procedure mapcarcar l;
    for each x in l collect car x;


symbolic procedure gcdld(l,n);
% GCD of the domain element N and all the polys in L;
    if n=1 or n=-1 then 1
    else if l=nil then abs n
    else if car l=nil then gcdld(cdr l,n)
    else gcdld(cdr l,gcd!-with!-number(n,car l));

symbolic procedure split!-wrt!-variables(p,vl,l);
% Push all the coeffs in P wrt variables in VL onto the list L
% Stop if 1 is found as a coeff;
    if p=nil then l
    else if not null l and car l=1 then l
    else if domainp p then abs p . l
    else if member(mvar p,vl) then
        split!-wrt!-variables(red p,vl,split!-wrt!-variables(lc p,vl,l))
    else p . l;


symbolic procedure gcdlist3(l,onestep,vlist);
% GCD of the nontrivial polys in the list L given that they all
% involve all the variables that any of them mention,
% and they are all monomial-primitive.
% ONESTEP is true if it is predicted that only one PRS step
% will be needed to compute the gcd - if so try that PRS step;
  begin
    scalar unlucky!-case,image!-set,gg,gcont,l1,w,
           reduced!-degree!-lclst,p1,p2;
    % Make all the polys primitive;
    l1:=for each p in l collect p . ezgcd!-comfac p;
    l:=for each c in l1 collect
        quotfail1(car c,comfac!-to!-poly cdr c,
                  "Content divison in GCDLIST3 failed");
    % All polys in L are now primitive;
    % Because all polys were monomial-primitive, there should
    % be no power of V to go in the result;
    gcont:=gcdlist for each c in l1 collect cddr c;
    if domainp gcont then if not gcont=1
      then errorf "GCONT has numeric part";
    % GCD of contents complete now;
    % Now I will remove duplicates from the list;
%   trace!-time <<
%      prin2t "GCDLIST3 on the polynomials";
%      for each p in l do print p >>;
    l := sort(for each p in l collect poly!-abs p,function ordp);
    w := nil;
    while l do <<
       w := car l . w;
       repeat l := cdr l until null l or not car w = car l >>;
    l := reversip w;
    w := nil;
%   trace!-time <<
%      prin2t "Made positive, with duplicates removed...";
%      for each p in l do print p >>;
    if null cdr l then return multf(gcont,car l);
       % That left just one poly;
    if domainp (gg:=car (l:=sort(l,function degree!-order))) then
      return gcont;
         % Primitive part of one poly is a constant (must be +/-1);
    if ldeg gg=1 then <<
    % True gcd is either GG or 1;
       if division!-test(gg,l) then return multf(poly!-abs gg,gcont)
       else return gcont >>;
    % All polys are now primitive and nontrivial. Use a modular
    % method to extract GCD;
    if onestep then <<
       % Try to take gcd in just one pseudoremainder step, because some
       % previous modular test suggests it may be possible;
       p1 := poly!-abs car l; p2 := poly!-abs cadr l;
       if p1=p2 then <<
             if division!-test(p1,cddr l) then return multf(p1,gcont) >>
       else <<
%      trace!-time prin2t "Just one pseudoremainder step needed?";
       gg := poly!-gcd(lc p1,lc p2);
       gg := ezgcd!-pp addf(multf(red p1,
           quotfail1(lc p2,gg,
        "Division failure when just one pseudoremainder step needed")),
        multf(red p2,negf quotfail1(lc p1,gg,
        "Division failure when just one pseudoremainder step needed")));
%      trace!-time printsf gg;
       if division!-test(gg,l) then return multf(gg,gcont) >>
       >>;
      return gcdlist31(l,vlist,gcont,gg,l1)
   end;

symbolic procedure gcdlist31(l,vlist,gcont,gg,l1);
   begin scalar cofactor,lcg,old!-modulus,prime,w,w1,zeros!-list;
    old!-modulus:=set!-modulus nil; %Remember modulus;
    lcg:=for each poly in l collect lc poly;
%    trace!-time << prin2t "L.C.S OF L ARE:";
%      for each lcpoly in lcg do printsf lcpoly >>;
    lcg:=gcdlist lcg;
%    trace!-time << prin2!* "LCG (=GCD OF THESE) = ";
%      printsf lcg >>;
try!-again:
    unlucky!-case:=nil;
    image!-set:=nil;
    set!-modulus(prime:=random!-prime());
    % Produce random univariate modular images of all the
    % polynomials;
    w:=l;
    if not zeros!-list then <<
      image!-set:=
         zeros!-list:=try!-max!-zeros!-for!-image!-set(w,vlist);
%     trace!-time << prin2t image!-set;
%       prin2 " Zeros-list = ";
%       prin2t zeros!-list >>
      >>;
%   trace!-time prin2t list("IMAGE SET",image!-set);
    gg:=make!-image!-mod!-p(car w,car vlist);
%   trace!-time prin2t list("IMAGE SET",image!-set," GG",gg);
    if unlucky!-case then <<
%     trace!-time << prin2t "Unlucky case, try again";
%       print image!-set >>;
      go to try!-again >>;
    l1:=list(car w . gg);
make!-images:
    if null (w:=cdr w) then go to images!-created!-successfully;
    l1:=(car w . make!-image!-mod!-p(car w,car vlist)) . l1;
    if unlucky!-case then <<
%    trace!-time << prin2t "UNLUCKY AGAIN...";
%      prin2t l1;
%      print image!-set >>;
      go to try!-again >>;
    gg:=gcd!-mod!-p(gg,cdar l1);
    if domainp gg then <<
      set!-modulus old!-modulus;
%     trace!-time print "Primitive parts are coprime";
      return gcont >>;
    go to make!-images;
images!-created!-successfully:
    l1:=reversip l1; % Put back in order with smallest first;
    % If degree of gcd seems to be same as that of smallest item
    % in input list, that item should be the gcd;
    if ldeg gg=ldeg car l then <<
        gg:=poly!-abs car l;
%       trace!-time <<
%         prin2!* "Probable GCD = ";
%         printsf gg >>;
        go to result >>
    else if (ldeg car l=add1 ldeg gg) and
            (ldeg car l=ldeg cadr l) then <<
    % Here it seems that I have just one pseudoremainder step to
    % perform, so I might as well do it;
%       trace!-time <<
%          prin2t "Just one pseudoremainder step needed"
%          >>;
        gg := poly!-gcd(lc car l,lc cadr l);
        gg := ezgcd!-pp addf(multf(red car l,
            quotfail1(lc cadr l,gg,
         "Division failure when just one pseudoremainder step needed")),
         multf(red cadr l,negf quotfail1(lc car l,gg,
         "Divison failure when just one pseudoremainder step needed")));
%       trace!-time printsf gg;
        go to result >>;
    w:=l1;
find!-good!-cofactor:
    if null w then go to special!-case; % No good cofactor available;
    if domainp gcd!-mod!-p(gg,cofactor:=quotient!-mod!-p(cdar w,gg))
      then go to good!-cofactor!-found;
    w:=cdr w;
    go to find!-good!-cofactor;
good!-cofactor!-found:
    cofactor:=monic!-mod!-p cofactor;
%   trace!-time prin2t "*** Good cofactor found";
    w:=caar w;
%    trace!-time << prin2!* "W= ";
%      printsf w;
%      prin2!* "GG= ";
%      printsf gg;
%      prin2!* "COFACTOR= ";
%      printsf cofactor >>;
    image!-set:=sort(image!-set,function ordopcar);
%    trace!-time << prin2 "IMAGE-SET = ";
%      prin2t image!-set;
%      prin2 "PRIME= ";   prin2t prime;
%      prin2t "L (=POLYLIST) IS:";
%      for each ll in l do printsf ll >>;
    gg:=reconstruct!-gcd(w,gg,cofactor,prime,image!-set,lcg);
    if gg='nogood then go to try!-again;
    go to result;
special!-case: % Here I have to do the first step of a PRS method;
%   trace!-time << prin2t "*** SPECIAL CASE IN GCD ***";
%     prin2t l;
%     prin2t "----->";
%     prin2t gg >>;
    reduced!-degree!-lclst:=nil;
try!-reduced!-degree!-again:
%   trace!-time << prin2t "L1 =";
%     for each ell in l1 do print ell >>;
    w1:=reduced!-degree(caadr l1,caar l1);
    w:=car w1; w1:=cdr w1;
    if domainp w1 or ldeg w neq ldeg w1 then go to try!-again;
%   trace!-time << prin2 "REDUCED!-DEGREE = "; printsf w;
%     prin2 " and its image = "; printsf w1 >>;
            % reduce the degree of the 2nd poly using the 1st. Result is
            % a pair : (new poly . image new poly);
    if domainp w and not null w then <<
      set!-modulus old!-modulus; return gcont >>;
            % we're done as they're coprime;
    if w and ldeg w = ldeg gg then <<
      gg:=w; go to result >>;
            % possible gcd;
    if null w then <<
            % the first poly divided the second one;
      l1:=(car l1 . cddr l1);  % discard second poly;
      if null cdr l1 then <<
         gg := poly!-abs caar l1;
         go to result >>;
      go to try!-reduced!-degree!-again >>;
            % haven't made progress yet so repeat with new polys;
    if ldeg w<=ldeg gg then <<
       gg := poly!-abs w;
       go to result >>
    else if domainp gcd!-mod!-p(gg,cofactor:=quotient!-mod!-p(w1,gg))
     then <<
       w := list list w;
       go to good!-cofactor!-found >>;
    l1:= if ldeg w <= ldeg caar l1 then
      ((w . w1) . (car l1 . cddr l1))
      else (car l1 . ((w . w1) . cddr l1));
            % replace first two polys by the reduced poly and the first
            % poly ordering according to degree;
    go to try!-reduced!-degree!-again;
            % need to repeat as we still haven't found a good cofactor;
result: % Here GG holds a tentative gcd for the primitive parts of
        % all input polys, and GCONT holds a proper one for the content;
    if division!-test(gg,l) then <<
      set!-modulus old!-modulus;
      return multf(gg,gcont) >>;
%   trace!-time prin2t list("Trial division by ",gg," failed");
    go to try!-again
  end;

symbolic procedure make!-a!-list!-of!-variables l;
  begin scalar vlist;
    for each ll in l do vlist:=variables!.in!.form(ll,vlist);
    return make!-order!-consistent(vlist,kord!*)
  end;

symbolic procedure make!-order!-consistent(l,m);
% L is a subset of M. Make its order consistent with that
% of M;
    if null l then nil
    else if null m then errorf("Variable missing from KORD*")
    else if car m member l then car m .
       make!-order!-consistent(delete(car m,l),cdr m)
    else make!-order!-consistent(l,cdr m);

symbolic procedure try!-max!-zeros!-for!-image!-set(l,vlist);
  if null vlist then error(50,"VLIST NOT SET IN TRY-MAX-ZEROS-...")
  else begin scalar z;
    z:=for each v in cdr vlist collect
      if domainp lc car l or null quotf(lc car l,!*k2f v) then
        (v . 0) else (v . modular!-number next!-random!-number());
    for each ff in cdr l do
      z:=for each w in z collect
        if zerop cdr w then
          if domainp lc ff or null quotf(lc ff,!*k2f car w) then w
          else (car w . modular!-number next!-random!-number())
        else w;
    return z
  end;

symbolic procedure
   reconstruct!-gcd(full!-poly,gg,cofactor,p,imset,lcg);
  if null addf(full!-poly,negf multf(gg,cofactor)) then gg
  else (lambda factor!-level;
    begin scalar number!-of!-factors,image!-factors,
    true!-leading!-coeffts,multivariate!-input!-poly,
    no!-of!-primes!-to!-try,
    irreducible,non!-monic,bad!-case,target!-factor!-count,
    multivariate!-factors,hensel!-growth!-size,alphalist,
    best!-known!-factors,prime!-base,
    m!-image!-variable, reconstructing!-gcd,full!-gcd;
    if not(current!-modulus=p) then
      errorf("GCDLIST HAS NOT RESTORED THE MODULUS");
            % *WARNING* GCDLIST does not restore the modulus so
              % I had better reset it here!  ;
    if poly!-minusp lcg then error(50,list("Negative GCD: ",lcg));
    full!-poly:=poly!-abs full!-poly;
    initialise!-hensel!-fluids(full!-poly,gg,cofactor,p,lcg);
%    trace!-time << prin2t "TRUE LEADING COEFFTS ARE:";
%      for i:=1:2 do <<
%        printsf getv(image!-factors,i);
%        prin2!* " WITH L.C.:";
%        printsf getv(true!-leading!-coeffts,i) >> >>;
    if determine!-more!-coeffts()='done then
      return full!-gcd;
    if null alphalist then alphalist:=alphas(2,
      list(getv(image!-factors,1),getv(image!-factors,2)),1);
    if alphalist='factors! not! coprime then
      errorf list("image factors not coprime?",image!-factors);
    if not !*overview then factor!-trace <<
      printstr
         "The following modular polynomials are chosen such that:";
      terpri();
      prin2!* "   a(2)*f(1) + a(1)*f(2) = 1 mod ";
      printstr hensel!-growth!-size;
      terpri();
      printstr "  where degree of a(1) < degree of f(1),";
      printstr "    and degree of a(2) < degree of f(2),";
      printstr "    and";
      for i:=1:2 do <<
        prin2!* "    a("; prin2!* i; prin2!* ")=";
        printsf cdr get!-alpha getv(image!-factors,i);
        prin2!* "and f("; prin2!* i; prin2!* ")=";
        printsf getv(image!-factors,i);
        terpri!* t >>
    >>;
    reconstruct!-multivariate!-factors(
      for each v in imset collect (car v . modular!-number cdr v));
    if irreducible or bad!-case then return 'nogood
    else return full!-gcd
  end) (factor!-level+1) ;

symbolic procedure initialise!-hensel!-fluids(fpoly,fac1,fac2,p,lcf1);
% ... ;
  begin scalar lc1!-image,lc2!-image;
    reconstructing!-gcd:=t;
    multivariate!-input!-poly:=multf(fpoly,lcf1);
    no!-of!-primes!-to!-try := 5;
    prime!-base:=hensel!-growth!-size:=p;
    number!-of!-factors:=2;
    lc1!-image:=make!-numeric!-image!-mod!-p lcf1;
    lc2!-image:=make!-numeric!-image!-mod!-p lc fpoly;
% Neither of the above leading coefficients will vanish;
    fac1:=times!-mod!-p(lc1!-image,fac1);
    fac2:=times!-mod!-p(lc2!-image,fac2);
    image!-factors:=mkvect 2;
    true!-leading!-coeffts:=mkvect 2;
    putv(image!-factors,1,fac1);
    putv(image!-factors,2,fac2);
    putv(true!-leading!-coeffts,1,lcf1);
    putv(true!-leading!-coeffts,2,lc fpoly);
    % If the GCD is going to be monic, we know the lc
    % of both cofactors exactly;
    non!-monic:=not(lcf1=1);
    m!-image!-variable:=mvar fpoly
  end;

symbolic procedure division!-test(gg,l);
% Predicate to test if GG divides all the polynomials in the list L;
    if null l then t
    else if null quotf(car l,gg) then nil
    else division!-test(gg,cdr l);



symbolic procedure degree!-order(a,b);
% Order standard forms using their degrees wrt main vars;
    if domainp a then t
    else if domainp b then nil
    else ldeg a<ldeg b;

symbolic procedure make!-image!-mod!-p(p,v);
% Form univariate image, set UNLUCKY!-CASE if leading coefficient
% gets destroyed;
  begin
    scalar lp;
    lp := degree!-in!-variable(p,v);
    p := make!-univariate!-image!-mod!-p(p,v);
    if not degree!-in!-variable(p,v)=lp then unlucky!-case := t;
    return p
  end;


symbolic procedure make!-univariate!-image!-mod!-p(p,v);
% Make a modular image of P, keeping only the variable V;
  if domainp p then
     if p=nil then nil
     else !*n2f modular!-number p
  else if mvar p=v then
     adjoin!-term(lpow p,
                  make!-univariate!-image!-mod!-p(lc p,v),
                  make!-univariate!-image!-mod!-p(red p,v))
    else plus!-mod!-p(
      times!-mod!-p(image!-of!-power(mvar p,ldeg p),
                    make!-univariate!-image!-mod!-p(lc p,v)),
      make!-univariate!-image!-mod!-p(red p,v));

symbolic procedure image!-of!-power(v,n);
  begin
    scalar w;
    w := assoc(v,image!-set);
    if null w then <<
       w := modular!-number next!-random!-number();
       image!-set := (v . w) . image!-set >>
    else w := cdr w;
    return modular!-expt(w,n)
  end;

symbolic procedure make!-numeric!-image!-mod!-p p;
% Make a modular image of P;
  if domainp p then
     if p=nil then 0
     else modular!-number p
    else modular!-plus(
      modular!-times(image!-of!-power(mvar p,ldeg p),
                    make!-numeric!-image!-mod!-p lc p),
      make!-numeric!-image!-mod!-p red p);


symbolic procedure total!-degree!-in!-powers(form,powlst);
% Returns a list where each variable mentioned in FORM is paired
% with the maximum degree it has. POWLST collects the list, and should
% normally be NIL on initial entry;
  if null form or domainp form then powlst
  else begin scalar x;
    if (x := atsoc(mvar form,powlst))
      then ldeg form>cdr x and rplacd(x,ldeg form)
    else powlst := (mvar form . ldeg form) . powlst;
    return total!-degree!-in!-powers(red form,
      total!-degree!-in!-powers(lc form,powlst))
  end;


symbolic procedure powers1 form;
% For each variable V in FORM collect (V . (MAX . MIN)) where
% MAX and MIN are limits to the degrees V has in FORM;
  powers2(form,powers3(form,nil),nil);

symbolic procedure powers3(form,l);
% Start of POWERS1 by collecting power information for
% the leading monomial in FORM;
    if domainp form then l
    else powers3(lc form,(mvar form . (ldeg form . ldeg form)) . l);

symbolic procedure powers2(form,powlst,thismonomial);
    if domainp form then
        if null form then powlst else powers4(thismonomial,powlst)
    else powers2(lc form,
                 powers2(red form,powlst,thismonomial),
                 lpow form . thismonomial);

symbolic procedure powers4(new,old);
% Merge information from new monomial into old information,
% updating MAX and MIN details;
  if null new then for each v in old collect (car v . (cadr v . 0))
  else if null old then for each v in new collect (car v . (cdr v . 0))
  else if caar new=caar old then <<
    % variables match - do MAX and MIN on degree information;
    if cdar new>cadar old then rplaca(cdar old,cdar new);
    if cdar new<cddar old then rplacd(cdar old,cdar new);
    rplacd(old,powers4(cdr new,cdr old)) >>
  else if ordop(caar new,caar old) then <<
    rplacd(cdar old,0); % Some variable not mentioned in new monomial;
    rplacd(old,powers4(new,cdr old)) >>
  else (caar new . (cdar new  . 0)) . powers4(cdr new,old);


symbolic procedure ezgcd!-pp u;
   %returns the primitive part of the polynomial U wrt leading var;
   quotf1(u,comfac!-to!-poly ezgcd!-comfac u);

symbolic procedure ezgcd!-sqfrf p;
   %P is a primitive standard form;
   %value is a list of square free factors;
  begin
    scalar pdash,p1,d,v;
    pdash := diff(p,v := mvar p);
    d := poly!-gcd(p,pdash); % p2*p3**2*p4**3*... ;
    if domainp d then return list p;
    p := quotfail1(p,d,"GCD division in FACTOR-SQFRF failed");
    p1 := poly!-gcd(p,
       addf(quotfail1(pdash,d,"GCD division in FACTOR-SQFRF failed"),
            negf diff(p,v)));
    return p1 . ezgcd!-sqfrf d
  end;

symbolic procedure reduced!-degree(u,v);
   %U and V are primitive polynomials in the main variable VAR;
   %result is pair: (reduced poly of U by V . its image) where by
   % reduced I mean using V to kill the leading term of U;
   begin scalar var,w,x;
%   trace!-time << prin2t "ARGS FOR REDUCED!-DEGREE ARE:";
%    printsf u;  printsf v >>;
    if u=v or quotf1(u,v) then return (nil . nil)
    else if ldeg v=1 then return (1 . 1);
%   trace!-time prin2t "CASE NON-TRIVIAL SO TAKE A REDUCED!-DEGREE:";
    var := mvar u;
    if ldeg u=ldeg v then x := negf lc u
    else x:=(mksp(var,ldeg u - ldeg v) .* negf lc u) .+ nil;
    w:=addf(multf(lc v,u),multf(x,v));
%   trace!-time printsf w;
    if degr(w,var)=0 then return (1 . 1);
%   trace!-time << prin2 "REDUCED!-DEGREE-LCLST = ";
%     print reduced!-degree!-lclst >>;
    reduced!-degree!-lclst := addlc(v,reduced!-degree!-lclst);
%   trace!-time << prin2 "REDUCED!-DEGREE-LCLST = ";
%     print reduced!-degree!-lclst >>;
    if x := quotf1(w,lc w) then w := x
    else for each y in reduced!-degree!-lclst do
      while (x := quotf1(w,y)) do w := x;
    u := v; v := ezgcd!-pp w;
%   trace!-time << prin2t "U AND V ARE NOW:";
%     printsf u; printsf v >>;
    if degr(v,var)=0 then return (1 . 1)
    else return (v . make!-univariate!-image!-mod!-p(v,var))
  end;


% moved('comfac,'ezgcd!-comfac);

% moved('pp,'ezgcd!-pp);

endmodule;


module facmisc;  % Miscellaneous routines used from several sections.

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(current!-modulus
        image!-set!-modulus
        modulus!/2
        othervars
        polyzero
%       pt
        save!-zset
        zerovarset);

global '(largest!-small!-modulus pseudo!-primes teeny!-primes);


% (1) Investigate variables in polynomial.

symbolic procedure multivariatep(a,v);
    if domainp a then nil
    else if not(mvar a eq v) then t
    else if multivariatep(lc a,v) then t
    else multivariatep(red a,v);

symbolic procedure variables!-in!-form a;
% collect variables that occur in the form a;
    variables!.in!.form(a,nil);

symbolic procedure get!.coefft!.bound(poly,degbd);
% Calculates a coefft bound for the factors of poly.  This simple
% bound is that suggested by Paul Wang and Linda p. Rothschild in
% Math. Comp. Vol 29 July 75, p.940, due to Gel'fond.
% Note that for tiny polynomials the bound is forced up to be
% larger than any prime that will get used in the mod-p splitting;
  max(get!-height poly * fixexpfloat sumof degbd,110);

symbolic procedure sumof degbd;
  if null degbd then 0 else cdar degbd + sumof cdr degbd;

symbolic procedure fixexpfloat n;
   % Compute exponential function e**n for potentially large N,
   % rounding result up somewhat. Note that exp(10)=22027 or so,
   % so if the basic floating point exponential function is accurate
   % to 6 or so digits we are protected here against roundoff.
   % This could be replaced by ceiling exp n, but is written this
   % way to avoid floating point overflow.
%  if n>10 then (fixexpfloat(n2)*fixexpfloat(n-n2) where n2 = n/2)
%   else 1+fix exp n;
   if n>10 then 22027*fixexpfloat(n-10) else ceiling exp float n;

% (2) Minor variations on ordinary algebraic operations.

symbolic procedure quotfail(a,b);
% version of quotf that fails if the division does;
  if polyzerop a then polyzero
  else begin scalar w;
    w:=quotf(a,b);
    if didntgo w then errorf list("UNEXPECTED DIVISION FAILURE",a,b)
    else return w
  end;

symbolic procedure quotfail1(a,b,msg);
% version of quotf that fails if the division does, and gives
% custom message;
  if polyzerop a then polyzero
  else begin scalar w;
    w:=quotf(a,b);
    if didntgo w then errorf msg
    else return w
  end;


% (3) pseudo-random prime numbers - small and large.

symbolic procedure set!-teeny!-primes();
  begin scalar i;
    i:=-1;
    teeny!-primes:=mkvect 9;
    putv(teeny!-primes,i:=iadd1 i,3);
    putv(teeny!-primes,i:=iadd1 i,5);
    putv(teeny!-primes,i:=iadd1 i,7);
    putv(teeny!-primes,i:=iadd1 i,11);
    putv(teeny!-primes,i:=iadd1 i,13);
    putv(teeny!-primes,i:=iadd1 i,17);
    putv(teeny!-primes,i:=iadd1 i,19);
    putv(teeny!-primes,i:=iadd1 i,23);
    putv(teeny!-primes,i:=iadd1 i,29);
    putv(teeny!-primes,i:=iadd1 i,31)
  end;

set!-teeny!-primes();

symbolic procedure random!-small!-prime();
  begin
    scalar p;
    repeat <<p:=small!-random!-number(); if evenp p then p := iadd1 p>>
       until primep p;
    return p
  end;

symbolic procedure small!-random!-number();
% Returns a smallish number from a distribution strongly favouring
% smaller numbers;
  begin scalar w;
% The next lines generate a random value in the range 0 to 1000000.
    w:=remainder(next!-random!-number(),1000)
                    +1000*remainder(next!-random!-number(),1000);
    if w < 0 then w := w + 1000000;
    w:=1.0+1.5*float w/1000000.0;  % 1.0 to 2.5
    w:=times(w,w);                 % In range 1.0 to 6.25
    return fix exp w;              % Should be in range 3 to 518,
                                   % < 21 about half the time;
  end;

% symbolic procedure fac!-exp u;
%    % Simple exp routine.  Assumes that Lisp has a routine for
%    % exponentiation of floats by integers.  Relative accuracy 4.e-5.
%    begin scalar x; integer n;
%      n := fix u;
%      if (x := (u - float n)) > 0.5 then <<x := x - 1.0; n := n + 1>>;
%      u := ee***n;
%      return u*((x+6.0)*x+12.0)/((x-6.0)*x+12.0)
%    end;

symbolic procedure random!-teeny!-prime l;
% get one of the first 10 primes at random providing it is
% not in the list L or that L says we have tried them all;
  if l='all or (length l = 10) then nil
  else begin scalar p;
    repeat
       p:=getv(teeny!-primes,remainder(next!-random!-number(),10))
    until not member(p,l);
    return p
  end;

% symbolic procedure primep n;
% Test if prime. Only for use on small integers.
%    n=2 or
%    (n>2 and not evenp n and primetest(n,3));

% symbolic procedure primetest(n,trial);
%    if igreaterp(itimes(trial,trial),n) then t
%    else if iremainder(n,trial)=0 then nil
%    else primetest(n,iplus(trial,2));


% PSEUDO-PRIMES will be a list of all composite numbers which are
% less than 2^24 and where 2926^(n-1) = 3315^(n-1) = 1 mod n.

pseudo!-primes:=mkvect 87;

begin
  scalar i,l;
  i:=0;
  l:= '(2047     4033     33227    38503    56033
        137149   145351   146611   188191   226801
        252601   294409   328021   399001   410041
        488881   512461   556421   597871   636641
        665281   722261   742813   873181   950797
        1047619  1084201  1141141  1152271  1193221
        1373653  1398101  1461241  1584133  1615681
        1627921  1755001  1857241  1909001  2327041
        2508013  3057601  3363121  3542533  3581761
        3828001  4069297  4209661  4335241  4510507
        4588033  4650049  4877641  5049001  5148001
        5176153  5444489  5481451  5892511  5968873
        6186403  6189121  6733693  6868261  6955541
        7398151  7519441  8086231  8134561  8140513
        8333333  8725753  8927101  9439201  9494101
        10024561 10185841 10267951 10606681 11972017
        13390081 14063281 14469841 14676481 14913991
        15247621 15829633 16253551);
    while l do <<
       putv(pseudo!-primes,i,car l);
       i:=i+1;
       l:=cdr l >>
  end;

symbolic procedure random!-prime();
  begin
% I want a random prime that is smaller than largest-small-modulus.
% I do this by generating random odd integers in the range lsm/2 to
% lsm and filtering them for primality. Prime testing is done using
% a Fermat test followed by lookup in an exception table that was
% laboriously precomputed. This process should be distinctly faster
% than trial-division testing of candidate primes, but the exception
% table is tedious to compute, so I limit lsm to 2**24 here. This is
% both the value that Cambridge Lisp can support directly, an indication
% of how large an exception table I computed using 48 hours of CPU time
% and large enough that primes selected this way will hardly ever
% be unlucky just through being too small.
    scalar p,w,oldmod,lsm, lsm2;
    lsm := largest!-small!-modulus;
    if lsm > 2**24 then lsm := 2**24;
    lsm2 := lsm/2;
    % W will become 1 when P is prime;
    oldmod := current!-modulus;
    while not (w=1) do <<
      p := remainder(next!-random!-number(), lsm);
      if p < lsm2 then p := p + lsm2;
      if evenp p then p := p + 1;
      set!-modulus p;
      w:=modular!-expt(modular!-number 2926,isub1 p);
      if w=1
         and (modular!-expt(modular!-number 3315,isub1 p) neq 1
                 or pseudo!-prime!-p p)
        then w:=0>>;
    set!-modulus oldmod;
    return p
  end;

symbolic procedure pseudo!-prime!-p n;
  begin
    scalar low,mid,high,v;
    low:=0;
    high:=87; % Size of vector of pseudo-primes;
    while not (high=low) do << % Binary search in table;
      mid:=iquotient(iplus(iadd1 high,low),2);
         % Mid point of (low,high);
      v:=getv(pseudo!-primes,mid);
      if igreaterp(v,n) then high:=isub1 mid else low:=mid >>;
    return (getv(pseudo!-primes,low)=n)
  end;


% (4) useful routines for vectors.

symbolic procedure form!-sum!-and!-product!-mod!-p(avec,fvec,r);
% sum over i (avec(i) * fvec(i));
  begin scalar s;
    s:=polyzero;
    for i:=1:r do
      s:=plus!-mod!-p(times!-mod!-p(getv(avec,i),getv(fvec,i)),
        s);
    return s
  end;

symbolic procedure form!-sum!-and!-product!-mod!-m(avec,fvec,r);
% Same as above but AVEC holds alphas mod p and want to work
% mod m (m > p) so minor difference to change AVEC to AVEC mod m;
  begin scalar s;
    s:=polyzero;
    for i:=1:r do
      s:=plus!-mod!-p(times!-mod!-p(
        !*f2mod !*mod2f getv(avec,i),getv(fvec,i)),s);
    return s
  end;

symbolic procedure reduce!-vec!-by!-one!-var!-mod!-p(v,pt,n);
% Substitute for the given variable in all elements creating a
% new vector for the result. (All arithmetic is mod p).
  begin scalar newv;
    newv:=mkvect n;
    for i:=1:n do
      putv(newv,i,evaluate!-mod!-p(getv(v,i),car pt,cdr pt));
    return newv
  end;

symbolic procedure make!-bivariate!-vec!-mod!-p(v,imset,var,n);
  begin scalar newv;
    newv:=mkvect n;
    for i:=1:n do
      putv(newv,i,make!-bivariate!-mod!-p(getv(v,i),imset,var));
    return newv
  end;

symbolic procedure times!-vector!-mod!-p(v,n);
% product of all the elements in the vector mod p;
  begin scalar w;
    w:=1;
    for i:=1:n do w:=times!-mod!-p(getv(v,i),w);
    return w
  end;

symbolic procedure make!-vec!-modular!-symmetric(v,n);
% fold each elt of V which is current a modular poly in the
% range 0->(p-1) onto the symmetric range (-p/2)->(p/2);
  for i:=1:n do putv(v,i,make!-modular!-symmetric getv(v,i));

% (5) Combinatorial fns used in finding values for the variables.


symbolic procedure make!-zerovarset vlist;
% vlist is a list of pairs (v . tag) where v is a variable name and
% tag is a boolean tag. The procedure splits the list into two
% according to the tags: Zerovarset is set to a list of variables
% whose tag is false and othervars contains the rest;
  for each w in vlist do
    if cdr w then othervars:= car w . othervars
    else zerovarset:= car w . zerovarset;

symbolic procedure make!-zeroset!-list n;
% Produces a list of lists each of length n with all combinations of
% ones and zeroes;
  begin scalar w;
    for k:=0:n do w:=append(w,kcombns(k,n));
    return w
  end;

symbolic procedure kcombns(k,m);
% produces a list of all combinations of ones and zeroes with k ones
% in each;
  if k=0 or k=m then begin scalar w;
    if k=m then k:=1;
    for i:=1:m do w:=k.w;
    return list w
    end
  else if k=1 or k=isub1 m then <<
    if k=isub1 m then k:=0;
    list!-with!-one!-a(k,1 #- k,m) >>
  else append(
    for each x in kcombns(isub1 k,isub1 m) collect (1 . x),
    for each x in kcombns(k,isub1 m) collect (0 . x) );

symbolic procedure list!-with!-one!-a(a,b,m);
% Creates list of all lists with one a and m-1 b's in;
  begin scalar w,x,r;
    for i:=1:isub1 m do w:=b . w;
    r:=list(a . w);
    for i:=1:isub1 m do <<
      x:=(car w) . x; w:=cdr w;
      r:=append(x,(a . w)) . r >>;
    return r
  end;

symbolic procedure make!-next!-zset l;
  begin scalar k,w;
    image!-set!-modulus:=iadd1 image!-set!-modulus;
    set!-modulus image!-set!-modulus;
    w:=for each ll in cdr l collect
      for each n in ll collect
        if n=0 then n
        else <<
          k:=modular!-number next!-random!-number();
          while (zerop k) or (onep k) do
            k:=modular!-number next!-random!-number();
          if k>modulus!/2 then k:=k-current!-modulus;
           k >>;
    save!-zset:=nil;
    return w
  end;

endmodule;


module facstr;   % Reconstruction of factors.

% Author: P. M. A. Moore, 1979.

% Modifications by: Arthur C. Norman, Anthony C. Hearn.

fluid '(!*trfac
        alphavec
        bad!-case
        best!-known!-factors
        best!-set!-pointer
        current!-modulus
        degree!-bounds
        factor!-level
        factor!-trace!-list
        fhatvec
        full!-gcd
        hensel!-growth!-size
        image!-factors
        irreducible
        m!-image!-variable
        multivariate!-factors
        multivariate!-input!-poly
        non!-monic
        number!-of!-factors
        predictions
        prime!-base
        reconstructing!-gcd
        target!-factor!-count
        valid!-image!-sets);

symbolic procedure reconstruct!-multivariate!-factors vset!-mod!-p;
   % Hensel construction for multivariate case.
   % Full univariate split has already been prepared (if factoring),
   % but we only need the modular factors and the true leading coeffts.
  (lambda factor!-level; begin
    scalar s,om,u0,alphavec,predictions,
      best!-factors!-mod!-p,fhatvec,w1,fvec!-mod!-p,d,degree!-bounds,
      lc!-vec;
    alphavec:=mkvect number!-of!-factors;
    best!-factors!-mod!-p:=mkvect number!-of!-factors;
    lc!-vec := mkvect number!-of!-factors;
        % This will preserve the LCs of the factors while we are working
        % mod p since they may contain numbers that are bigger than the
        % modulus.
    if not(
      (d:=max!-degree(multivariate!-input!-poly,0)) < prime!-base) then
      fvec!-mod!-p:=choose!-larger!-prime d;
    om:=set!-modulus hensel!-growth!-size;
    if null fvec!-mod!-p then <<
      fvec!-mod!-p:=mkvect number!-of!-factors;
      for i:=1:number!-of!-factors do
        putv(fvec!-mod!-p,i,reduce!-mod!-p getv(image!-factors,i)) >>;
    for i:=1:number!-of!-factors do <<
      putv(alphavec,i,cdr get!-alpha getv(fvec!-mod!-p,i));
      putv(best!-factors!-mod!-p,i,
        reduce!-mod!-p getv(best!-known!-factors,i));
      putv(lc!-vec,i,lc getv(best!-known!-factors,i)) >>;
         % Set up the Alphas, input factors mod p and remember to save
         % the LCs for use after finding the multivariate factors mod p.
    if not reconstructing!-gcd then <<
      s:=getv(valid!-image!-sets,best!-set!-pointer);
      vset!-mod!-p:=for each v in get!-image!-set s collect
        (car v . modular!-number cdr v) >>;
%    princ "kord* =";% print kord!*;
%    princ "order of variable substitution=";% print vset!-mod!-p;
    u0:=reduce!-mod!-p multivariate!-input!-poly;
    set!-degree!-bounds vset!-mod!-p;
%   wtime:=time();
    factor!-trace <<
      printstr
         "We use the Hensel Construction to grow univariate modular";
      printstr
         "factors into multivariate modular factors, which will in";
      printstr "turn be used in the later Hensel construction.  The";
      printstr "starting modular factors are:";
      printvec(" f(",number!-of!-factors,")=",best!-factors!-mod!-p);
      prin2!* "The modulus is "; printstr current!-modulus >>;
    find!-multivariate!-factors!-mod!-p(u0,
      best!-factors!-mod!-p,
      vset!-mod!-p);
    if bad!-case then <<
%     trace!-time <<
%       display!-time(" Multivariate modular factors failed in ",
%         time()-wtime);
%       wtime:=time() >>;
      target!-factor!-count:=number!-of!-factors - 1;
      if target!-factor!-count=1 then irreducible:=t;
      set!-modulus om;
      return bad!-case >>;
%   trace!-time <<
%     display!-time(" Multivariate modular factors found in ",
%       time()-wtime);
%     wtime:=time() >>;
    fhatvec:=make!-multivariate!-hatvec!-mod!-p(best!-factors!-mod!-p,
      number!-of!-factors);
    for i:=1:number!-of!-factors do
      putv(fvec!-mod!-p,i,getv(best!-factors!-mod!-p,i));
    make!-vec!-modular!-symmetric(best!-factors!-mod!-p,
      number!-of!-factors);
    for i:=1:number!-of!-factors do <<
%      w1:=getv(coefft!-vectors,i);
%      putv(best!-known!-factors,i,
%        merge!-terms(getv(best!-factors!-mod!-p,i),w1));
      putv(best!-known!-factors,i,
        force!-lc(getv(best!-factors!-mod!-p,i),getv(lc!-vec,i)));
         % Now we put back the LCs before growing the multivariate
         % factors to be correct over the integers giving the final
         % result.
      >>;
%   wtime:=time();
    w1:=hensel!-mod!-p(
      multivariate!-input!-poly,
      fvec!-mod!-p,
      best!-known!-factors,
      get!.coefft!.bound(multivariate!-input!-poly,
        total!-degree!-in!-powers(multivariate!-input!-poly,nil)),
      vset!-mod!-p,
      hensel!-growth!-size);
    if car w1='overshot then <<
%     trace!-time <<
%       display!-time(" Full factors failed in ",time()-wtime);
%       wtime:=time() >>;
      target!-factor!-count:=number!-of!-factors - 1;
      if target!-factor!-count=1 then irreducible:=t;
      set!-modulus om;
      return bad!-case:=t >>;
    if not(car w1='ok) then errorf w1;
%   trace!-time <<
%     display!-time(" Full factors found in ",time()-wtime);
%     wtime:=time() >>;
    if reconstructing!-gcd then <<
      full!-gcd:=if non!-monic then car primitive!.parts(
          list getv(cdr w1,1),m!-image!-variable,nil)
        else getv(cdr w1,1);
      set!-modulus om;
      return full!-gcd >>;
    for i:=1:getv(cdr w1,0) do
      multivariate!-factors:=getv(cdr w1,i) . multivariate!-factors;
    if non!-monic then multivariate!-factors:=
      primitive!.parts(multivariate!-factors,m!-image!-variable,nil);
    factor!-trace <<
      printstr "The full multivariate factors are:";
      for each x in multivariate!-factors do printsf x >>;
    set!-modulus om;
  end) (factor!-level*100);

endmodule;


module interfac;

% Authors: A. C. Norman and P. M. A. Moore, 1981.

% Modifications by: Anthony C. Hearn.

fluid '(m!-image!-variable
        poly!-vector
        polyzero
        unknowns!-list
        varlist);


%**********************************************************************;
%
% Routines that are specific to REDUCE.
%  These are either routines that are not needed in the HASH system
%  (which is the other algebra system that this factorizer
%  can be plugged into) or routines that are specifically
%  redefined in the HASH system.


%---------------------------------------------------------------------;
% The following would normally live in section:  ALPHAS
%---------------------------------------------------------------------;

symbolic procedure assoc!-alpha(poly,alist);  assoc(poly,alist);


%---------------------------------------------------------------------;
% The following would normally live in section:  COEFFTS
%---------------------------------------------------------------------;

symbolic procedure termvector2sf v;
  begin scalar r,w;
    for i:=car getv(v,0) step -1 until 1 do <<
      w:=getv(v,i);
            % degree . coefft;
      r:=if car w=0 then cdr w else
        (mksp(m!-image!-variable,car w) .* cdr w) .+ r
    >>;
    return r
  end;

symbolic procedure force!-lc(a,n);
% force polynomial a to have leading coefficient as specified;
    (lpow a .* n) .+ red a;

symbolic procedure merge!-terms(u,v);
  merge!-terms1(1,u,v,car getv(v,0));

symbolic procedure merge!-terms1(i,u,v,n);
  if i#>n then u
  else begin scalar a,b;
    a:=getv(v,i);
    if domainp u or not(mvar u=m!-image!-variable) then
      if not(car a=0) then errorf list("MERGING COEFFTS FAILED",u,a)
      else if cdr a then return cdr a
      else return u;
    b:=lt u;
    if tdeg b=car a then return
      (if cdr a then tpow b .* cdr a else b) .+
        merge!-terms1(i #+ 1,red u,v,n)
    else if tdeg b #> car a then return b .+ merge!-terms1(i,red u,v,n)
    else errorf list("MERGING COEFFTS FAILED ",u,a)
  end;

symbolic procedure list!-terms!-in!-factor u;
% ...;
  if domainp u then list (0 . nil)
  else (ldeg u . nil) . list!-terms!-in!-factor red u;

symbolic procedure try!-other!-coeffts(r,unknowns!-list,uv);
  begin scalar ldeg!-r,lc!-r,w;
    while not domainp r and (r:=red r) and not(w='complete) do <<
      if not depends!-on!-var(r,m!-image!-variable) then
        << ldeg!-r:=0; lc!-r:=r >>
      else << ldeg!-r:=ldeg r; lc!-r:=lc r >>;
      w:=solve!-next!-coefft(ldeg!-r,lc!-r,unknowns!-list,uv) >>
  end;


%---------------------------------------------------------------------;
% The following would normally live in section:  FACMISC
%---------------------------------------------------------------------;

symbolic procedure derivative!-wrt!-main!-variable(p,var);
% partial derivative of the polynomial p with respect to
% its main variable, var;
    if domainp p or (mvar p neq var) then nil
    else
     begin
      scalar degree;
      degree:=ldeg p;
      if degree=1 then return lc p; %degree one term is special;
      return (mksp(mvar p,degree-1) .* multf(degree,lc p)) .+
        derivative!-wrt!-main!-variable(red p,var)
     end;

symbolic procedure fac!-univariatep u;
% tests to see if u is univariate;
  domainp u or not multivariatep(u,mvar u);

symbolic procedure variables!.in!.form(a,sofar);
    if domainp a then sofar
    else <<
      if not memq(mvar a,sofar) then
        sofar:=mvar a . sofar;
      variables!.in!.form(red a,
        variables!.in!.form(lc a,sofar)) >>;


symbolic procedure degree!-in!-variable(p,v);
% returns the degree of the polynomial p in the
% variable v;
    if domainp p then 0
    else if lc p=0
     then errorf "Polynomial with a zero coefficient found"
    else if v=mvar p then ldeg p
    else max(degree!-in!-variable(lc p,v),
      degree!-in!-variable(red p,v));

symbolic procedure get!-height poly;
% find height (max coefft) of given poly;
  if null poly then 0
  else if numberp poly then abs poly
  else max(get!-height lc poly,get!-height red poly);


symbolic procedure poly!-minusp a;
    if a=nil then nil
    else if domainp a then minusp a
    else poly!-minusp lc a;

symbolic procedure poly!-abs a;
    if poly!-minusp a then negf a
    else a;

symbolic procedure fac!-printfactors l;
% procedure to print the result of factorize!-form;
% ie. l is of the form: (c . f)
%  where c is the numeric content (may be 1)
%  and f is of the form: ( (f1 . e1) (f2 . e2) ... (fn . en) )
%    where the fi's are s.f.s and ei's are numbers;
<< terpri();
  if not (car l = 1) then printsf car l;
  for each item in cdr l do
    printsf !*p2f mksp(prepf car item,cdr item) >>;


%---------------------------------------------------------------------;
% The following would normally live in section:  FACPRIM
%---------------------------------------------------------------------;

symbolic procedure invert!.poly(u,var);
% u is a non-trivial primitive square free multivariate polynomial.
% assuming var is the top-level variable in u, this effectively
% reverses the position of the coeffts: ie
%   a(n)*var**n + a(n-1)*var**(n-1) + ... + a(0)
% becomes:
%   a(0)*var**n + a(1)*var**(n-1) + ... + a(n) .               ;
  begin scalar w,invert!-sign;
    w:=invert!.poly1(red u,ldeg u,lc u,var);
    if poly!-minusp lc w then <<
      w:=negf w;
      invert!-sign:=-1 >>
    else invert!-sign:=1;
    return invert!-sign . w
  end;

symbolic procedure invert!.poly1(u,d,v,var);
% d is the degree of the poly we wish to invert.
% assume d > ldeg u always, and that v is never nil;
  if (domainp u) or not (mvar u=var) then
    (var to d) .* u .+ v
  else invert!.poly1(red u,d,(var to (d-ldeg u)) .* (lc u) .+ v,var);


symbolic procedure trailing!.coefft(u,var);
% u is multivariate poly with var as the top-level variable. we find
% the trailing coefft - ie the constant wrt var in u;
  if domainp u then u
  else if mvar u=var then trailing!.coefft(red u,var)
  else u;


%---------------------------------------------------------------------;
% The following would normally live in section:  IMAGESET
%---------------------------------------------------------------------;

symbolic procedure make!-image!-lc!-list(u,imset);
  reversip make!-image!-lc!-list1(u,imset,
    for each x in imset collect car x);

symbolic procedure make!-image!-lc!-list1(u,imset,varlist);
% If IMSET=((x1 . a1, x2 . a2, ... , xn . an)) (ordered) where xj is
% the variable and aj its value, then this fn creates n images of U wrt
% sets S(i) where S(i)= ((x1 . a1), ... , (xi . ai)). The result is an
% ordered list of pairs: (u(i) . X(i+1)) where u(i)= U wrt S(i) and
% X(i) = (xi, ... , xn) and X(n+1) = NIL.  VARLIST = X(1).
% (Note. the variables tagged to u(i) should be all those
% appearing in u(i) unless it is degenerate). The returned list is
% ordered with u(1) first and ending with the number u(n);
  if null imset then nil
  else if domainp u then list(!*d2n u . cdr varlist)
  else if mvar u=caar imset then
    begin scalar w;
      w:=horner!-rule!-for!-one!-var(
        u,caar imset,cdar imset,polyzero,ldeg u) . cdr varlist;
      return
        if polyzerop car w then list (0 . cdr w)
        else (w . make!-image!-lc!-list1(car w,cdr imset,cdr varlist))
    end
  else make!-image!-lc!-list1(u,cdr imset,cdr varlist);

symbolic procedure horner!-rule!-for!-one!-var(u,x,val,c,degg);
  if domainp u or not(mvar u=x)
    then if zerop val then u else addf(u,multf(c,!*n2f(val**degg)))
  else begin scalar newdeg;
    newdeg:=ldeg u;
    return horner!-rule!-for!-one!-var(red u,x,val,
       if zerop val then lc u
        else addf(lc u,
                  multf(c,!*n2f(val**(idifference(degg,newdeg))))),
                            newdeg)
  end;

symbolic procedure make!-image(u,imset);
% finds image of u wrt image set, imset, (=association list);
  if domainp u then u
  else if mvar u=m!-image!-variable then
    adjoin!-term(lpow u,!*n2f evaluate!-in!-order(lc u,imset),
                        make!-image(red u,imset))
  else !*n2f evaluate!-in!-order(u,imset);

symbolic procedure evaluate!-in!-order(u,imset);
% makes an image of u wrt imageset, imset, using horner's rule. result
% should be purely numeric;
  if domainp u then !*d2n u
  else if mvar u=caar imset then
    horner!-rule(evaluate!-in!-order(lc u,cdr imset),
      ldeg u,red u,imset)
  else evaluate!-in!-order(u,cdr imset);

symbolic procedure horner!-rule(c,degg,a,vset);
% c is running total and a is what is left;
  if domainp a
    then if zerop cdar vset then !*d2n a
          else (!*d2n a)+c*((cdar vset)**degg)
  else if not(mvar a=caar vset)
   then if zerop cdar vset then evaluate!-in!-order(a,cdr vset)
         else evaluate!-in!-order(a,cdr vset)+c*((cdar vset)**degg)
  else begin scalar newdeg;
    newdeg:=ldeg a;
    return horner!-rule(if zerop cdar vset
                          then evaluate!-in!-order(lc a,cdr vset)
                         else evaluate!-in!-order(lc a,cdr vset)
      +c*((cdar vset)**(idifference(degg,newdeg))),newdeg,red a,vset)
  end;


%---------------------------------------------------------------------;
% The following would normally live in section:  MHENSFNS
%---------------------------------------------------------------------;

symbolic procedure max!-degree(u,n);
% finds maximum degree of any single variable in U (n is max so far);
  if domainp u then n
  else if igreaterp(n,ldeg u) then
    max!-degree(red u,max!-degree(lc u,n))
  else max!-degree(red u,max!-degree(lc u,ldeg u));

symbolic procedure diff!-over!-k!-mod!-p(u,k,v);
% derivative of u wrt v divided by k (=number);
  if domainp u then nil
  else if mvar u = v then
    if ldeg u = 1 then quotient!-mod!-p(lc u,modular!-number k)
    else adjoin!-term(mksp(v,isub1 ldeg u),
      quotient!-mod!-p(
        times!-mod!-p(modular!-number ldeg u,lc u),
        modular!-number k),
      diff!-over!-k!-mod!-p(red u,k,v))
  else adjoin!-term(lpow u,
    diff!-over!-k!-mod!-p(lc u,k,v),
    diff!-over!-k!-mod!-p(red u,k,v));

symbolic procedure diff!-k!-times!-mod!-p(u,k,v);
% differentiates u k times wrt v and divides by (k!) ie. for each term
% a*v**n we get [n k]*a*v**(n-k) if n>=k and nil if n<k where
% [n k] is the binomial coefficient;
  if domainp u then nil
  else if mvar u = v then
    if ldeg u < k then nil
    else if ldeg u = k then lc u
    else adjoin!-term(mksp(v,ldeg u - k),
      times!-mod!-p(binomial!-coefft!-mod!-p(ldeg u,k),lc u),
      diff!-k!-times!-mod!-p(red u,k,v))
  else adjoin!-term(lpow u,
    diff!-k!-times!-mod!-p(lc u,k,v),
    diff!-k!-times!-mod!-p(red u,k,v));

symbolic procedure spreadvar(u,v,slist);
% find all the powers of V in U and merge their degrees into SLIST.
% We ignore the constant term wrt V;
  if domainp u then slist
  else <<
    if mvar u=v and not member(ldeg u,slist) then slist:=ldeg u . slist;
    spreadvar(red u,v,spreadvar(lc u,v,slist)) >>;


%---------------------------------------------------------------------;
% The following would normally live in section:  UNIHENS
%---------------------------------------------------------------------;

symbolic procedure root!-squares(u,sofar);
  if null u then pmam!-sqrt sofar
  else if domainp u then pmam!-sqrt(sofar+(u*u))
  else root!-squares(red u,sofar+(lc u * lc u));

%---------------------------------------------------------------------;
% The following would normally live in section:  VECPOLY
%---------------------------------------------------------------------;

symbolic procedure poly!-to!-vector p;
% spread the given univariate polynomial out into POLY-VECTOR;
    if domainp p then putv(poly!-vector,0,!*d2n p)
    else <<
      putv(poly!-vector,ldeg p,lc p);
      poly!-to!-vector red p >>;

symbolic procedure vector!-to!-poly(p,d,v);
% Convert the vector P into a polynomial of degree D in variable V;
  begin
    scalar r;
    if d#<0 then return nil;
    r:=!*n2f getv(p,0);
    for i:=1:d do
      if getv(p,i) neq 0 then r:=((v to i) .* getv(p,i)) .+ r;
    return r
  end;



endmodule;


module linmodp;  % Routines for solving linear equations mod p.

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(prime!-base);

symbolic procedure lu!-factorize!-mod!-p(a,n);
   % A is a matrix of size N*N. Overwrite it with its LU factorization.
   begin scalar w;
    for i:=1:n do begin
     scalar ii,pivot;
     if w eq 'singular then return nil;
     ii:=i;
     while n>=ii and ((pivot:=getm2(a,ii,i))=0
        or iremainder(pivot,prime!-base)=0) do ii := ii+1;
     if ii>n then return(w := 'singular);
     if not ii=i then begin
         scalar temp;
         temp:=getv(a,i);
         putv(a,i,getv(a,ii));
         putv(a,ii,temp) end;
     putm2(a,i,0,ii); % Remember pivoting information;
     pivot:=modular!-reciprocal pivot;
     putm2(a,i,i,pivot);
     for j:=i+1:n do
       putm2(a,i,j,modular!-times(pivot,getm2(a,i,j)));
     for ii:=i+1:n do begin
        scalar multiple;
        multiple:=getm2(a,ii,i);
        for j:=i+1:n do
           putm2(a,ii,j,modular!-difference(getm2(a,ii,j),
             modular!-times(multiple,getm2(a,i,j)))) end end;
     return w
   end;

symbolic procedure back!-substitute(a,v,n);
   % A is an N*N matrix as produced by LU-FACTORIZE-MOD-P, and V is a
   % vector of length N. Overwrite V with solution to linear equations.
   begin
     for i:=1:n do
         begin scalar ii;
            ii:=getm2(a,i,0); % Pivot control;
            if ii neq i
              then begin scalar temp;
                      temp:=getv(v,i);
                      putv(v,i,getv(v,ii));
                      putv(v,ii,temp)
                   end
         end;
     for i:=1:n do begin
         putv(v,i,times!-mod!-p(!*n2f getm2(a,i,i),getv(v,i)));
         for ii:=i+1:n do
            putv(v,ii,difference!-mod!-p(getv(v,ii),
               times!-mod!-p(getv(v,i),!*n2f getm2(a,ii,i)))) end;
             % Now do the actual back substitution;
     for i:=n-1 step -1 until 1 do
       for j:=i+1:n do
         putv(v,i,difference!-mod!-p(getv(v,i),
           times!-mod!-p(!*n2f getm2(a,i,j),getv(v,j))));
     return v
   end;

endmodule;


module mhensfns;

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(!*trfac
        alphalist
        current!-modulus
        degree!-bounds
        delfvec
        factor!-level
        factor!-trace!-list
        forbidden!-primes
        hensel!-growth!-size
        image!-factors
        max!-unknowns
        multivariate!-input!-poly
        non!-monic
        number!-of!-factors
        number!-of!-unknowns
        polyzero
%       pt
        prime!-base);


%**********************************************************************;
%    This section contains some of the functions used in
%    the multivariate hensel growth. (ie they are called from
%    section MULTIHEN or function RECONSTRUCT-MULTIVARIATE-FACTORS). ;



symbolic procedure set!-degree!-bounds v;
  degree!-bounds:=for each var in v collect
    (car var . degree!-in!-variable(multivariate!-input!-poly,car var));

symbolic procedure get!-degree!-bound v;
  begin scalar w;
    w:=atsoc(v,degree!-bounds);
    if null w then errorf(list("Degree bound not found for ",
        v," in ",degree!-bounds));
    return cdr w
  end;

symbolic procedure choose!-larger!-prime n;
% our prime base in the multivariate hensel must be greater than n so
% this sets a new prime to be that (previous one was found to be no
% good). We also set up various fluids e.g. the Alphas;
% the primes we can choose are < 2**24 so if n is bigger
% we collapse;
  if n > 2**24-1 then
    errorf list("CANNOT CHOOSE PRIME > GIVEN NUMBER:",n)
  else begin scalar p,flist!-mod!-p,k,fvec!-mod!-p,forbidden!-primes;
trynewprime:
    if p then forbidden!-primes:=p . forbidden!-primes;
    p:=random!-prime();
            % this chooses a word-size prime (currently 24 bits);
    set!-modulus p;
    if not(p>n) or member(p,forbidden!-primes) or
      polyzerop reduce!-mod!-p lc multivariate!-input!-poly then
       goto trynewprime;
    for i:=1:number!-of!-factors do
      flist!-mod!-p:=(reduce!-mod!-p getv(image!-factors,i) .
                       flist!-mod!-p);
    alphalist:=alphas(number!-of!-factors,flist!-mod!-p,1);
    if alphalist='factors! not! coprime then goto trynewprime;
    hensel!-growth!-size:=p;
    prime!-base:=p;
    factor!-trace <<
      prin2!* "New prime chosen: ";
      printstr hensel!-growth!-size >>;
    k:=number!-of!-factors;
    fvec!-mod!-p:=mkvect k;
    for each w in flist!-mod!-p do <<
      putv(fvec!-mod!-p,k,w); k:=isub1 k >>;
    return fvec!-mod!-p
  end;

symbolic procedure binomial!-coefft!-mod!-p(n,r);
  if n<r then nil
  else if n=r then 1
  else if r=1 then !*n2f modular!-number n
  else begin scalar n!-c!-r,b,j;
    n!-c!-r:=1;
    b:=min(r,n-r);
    n:=modular!-number n;
    r:=modular!-number r;
    for i:=1:b do <<
      j:=modular!-number i;
      n!-c!-r:=modular!-quotient(
        modular!-times(n!-c!-r,
          modular!-difference(n,modular!-difference(j,1))),
        j) >>;
    return !*n2f n!-c!-r
  end;

symbolic procedure make!-multivariate!-hatvec!-mod!-p(bvec,n);
% makes a vector whose ith elt is product over j [ BVEC(j) ] / BVEC(i);
% NB. we must NOT actually do the division here as we are likely
% to be working mod p**n (some n > 1) and the division can involve
% a division by p.;
  begin scalar bhatvec,r;
    bhatvec:=mkvect n;
    for i:=1:n do <<
      r:=1;
      for j:=1:n do if not(j=i) then r:=times!-mod!-p(r,getv(bvec,j));
      putv(bhatvec,i,r) >>;
    return bhatvec
  end;

symbolic procedure max!-degree!-in!-var(fvec,v);
  begin scalar r,d;
    r:=0;
    for i:=1:number!-of!-factors do
      if r<(d:=degree!-in!-variable(getv(fvec,i),v)) then r:=d;
    return r
  end;

symbolic procedure make!-growth!-factor pt;
% pt is of form (v . n) where v is a variable. we make the s.f. v-n;
  if cdr pt=0 then !*f2mod !*k2f car pt
  else plus!-mod!-p(!*f2mod !*k2f car pt,modular!-minus cdr pt);

symbolic procedure terms!-done!-mod!-p(fvec,delfvec,delfactor);
% calculate the terms introduced by the corrections in DELFVEC;
  begin scalar flist,delflist;
    for i:=1:number!-of!-factors do <<
      flist:=getv(fvec,i) . flist;
      delflist:=getv(delfvec,i) . delflist >>;
    return terms!-done1!-mod!-p(number!-of!-factors,flist,delflist,
      number!-of!-factors,delfactor)
  end;

symbolic procedure terms!-done1!-mod!-p(n,flist,delflist,r,m);
  if n=1 then (car flist) . (car delflist)
  else begin scalar k,i,f1,f2,delf1,delf2;
    k:=n/2; i:=1;
    for each f in flist do
    << if i>k then f2:=(f . f2)
       else f1:=(f . f1);
       i:=i+1 >>;
    i:=1;
    for each delf in delflist do
    << if i>k then delf2:=(delf . delf2)
       else delf1:=(delf . delf1);
       i:=i+1 >>;
    f1:=terms!-done1!-mod!-p(k,f1,delf1,r,m);
    delf1:=cdr f1; f1:=car f1;
    f2:=terms!-done1!-mod!-p(n-k,f2,delf2,r,m);
    delf2:=cdr f2; f2:=car f2;
    delf1:=
      plus!-mod!-p(plus!-mod!-p(
        times!-mod!-p(f1,delf2),
        times!-mod!-p(f2,delf1)),
        times!-mod!-p(times!-mod!-p(delf1,m),delf2));
    if n=r then return delf1;
    return (times!-mod!-p(f1,f2) . delf1)
  end;

symbolic procedure primitive!.parts(flist,var,univariate!-inputs);
% finds the prim.part of each factor in flist wrt variable var;
% Note that FLIST may contain univariate or multivariate S.F.s
% (according to UNIVARIATE!-INPUTS) - in the former case we correct the
% ALPHALIST if necessary;
  begin scalar c,primf;
    if null var then
      errorf "Must take primitive parts wrt some non-null variable";
    if non!-monic then
      factor!-trace <<
        printstr "Because we multiplied the original primitive";
        printstr "polynomial by a multiple of its leading coefficient";
        printstr "(see (a) above), the factors we have now are not";
        printstr "necessarily primitive. However the required factors";
        printstr "are merely their primitive parts." >>;
    return for each fw in flist collect
    << if not depends!-on!-var(fw,var) then
            errorf list("WRONG VARIABLE",var,fw);
       c:=comfac fw;
       if car c then errorf(list(
         "FACTOR DIVISIBLE BY MAIN VARIABLE:",fw,car c));
       primf:=quotfail(fw,cdr c);
       if not(cdr c=1) and univariate!-inputs then
         multiply!-alphas(cdr c,fw,primf);
       primf >>
  end;


symbolic procedure make!-predicted!-forms(pfs,v);
% PFS is a vector of S.F.s which represents the sparsity of
% the associated polynomials wrt V. Here PFS is adjusted to a
% suitable form for handling this sparsity. ie. we record the
% degrees of V in a vector for each poly in PFS. Each
% monomial (in V) represents an unknown (its coefft) in the predicted
% form of the associated poly. We count the maximum no of unknowns for
% each poly and return the maximum of these;
  begin scalar l,n,pvec,j,w;
    max!-unknowns:=0;
    for i:=1:number!-of!-factors do <<
      w:=getv(pfs,i);  % get the ith poly;
      l:=sort(spreadvar(w,v,nil),function lessp);
            % Pick out the monomials in V from this poly and order
            % them in increasing degree;
      n:=iadd1 length l; % no of unknowns in predicted poly - we add
                         % one for the constant term;
      number!-of!-unknowns:=(n . i) . number!-of!-unknowns;
      if max!-unknowns<n then max!-unknowns:=n;
      pvec:=mkvect isub1 n;
            % get space for the info on this poly;
      j:=0;
      putv(pvec,j,isub1 n);
            % put in the length of this vector which will vary
            % from poly to poly;
      for each m in l do putv(pvec,j:=iadd1 j,m);
            % put in the monomial info;
      putv(pfs,i,pvec);
            % overwrite the S.F. in PFS with the more compact vector;
      >>;
    number!-of!-unknowns:=sort(number!-of!-unknowns,function lesspcar);
    return max!-unknowns
  end;

symbolic procedure make!-correction!-vectors(bfs,n);
% set up space for the vector of vectors to hold the correction
% terms as we generate them by the function SOLVE-FOR-CORRECTIONS.
% Also put in the starting values;
  begin scalar cvs,cv;
    cvs:=mkvect number!-of!-factors;
    for i:=1:number!-of!-factors do <<
      cv:=mkvect n;
            % each CV will hold the corrections for the ith factor;
            % the no of corrections we put in here depends on the
            % maximum no of unknowns we have in the predicted
            % forms, giving a set of soluble linear systems (hopefully);
      putv(cv,1,getv(bfs,i));
            % put in the first 'corrections';
      putv(cvs,i,cv) >>;
    return cvs
  end;

symbolic procedure construct!-soln!-matrices(pfs,val);
% Here we construct the matrices - one for each linear system
% we will have to solve to see if our predicted forms of the
% answer are correct. Each matrix is a vector of row-vectors
% - the ijth elt is in jth slot of ith row-vector (ie zero slots
% are not used here);
  begin scalar soln!-matrix,resvec,n,pv;
    resvec:=mkvect number!-of!-factors;
    for i:=1:number!-of!-factors do <<
      pv:=getv(pfs,i);
      soln!-matrix:=mkvect(n:=iadd1 getv(pv,0));
      construct!-ith!-matrix(soln!-matrix,pv,n,val);
      putv(resvec,i,soln!-matrix) >>;
    return resvec
  end;

symbolic procedure construct!-ith!-matrix(sm,pv,n,val);
  begin scalar mv;
    mv:=mkvect n;  %  this will be the first row;
    putv(mv,1,1);  % the first column represents the constant term;
    for j:=2:n do putv(mv,j,modular!-expt(val,getv(pv,isub1 j)));
            % first row is straight substitution;
    putv(sm,1,mv);
            % now for the rest of the rows:   ;
    for j:=2:n do <<
      mv:=mkvect n;
      putv(mv,1,0);
      construct!-matrix!-row(mv,isub1 j,pv,n,val);
      putv(sm,j,mv) >>
  end;

symbolic procedure construct!-matrix!-row(mrow,j,pv,n,val);
  begin scalar d;
    for k:=2:n do <<
      d:=getv(pv,isub1 k);  % degree representing the monomial;
      if d<j then putv(mrow,k,0)
      else <<
        d:=modular!-times(!*d2n binomial!-coefft!-mod!-p(d,j),
             modular!-expt(val,idifference(d,j)));
            % differentiate and substitute all at once;
        putv(mrow,k,d) >> >>
  end;

symbolic procedure print!-linear!-systems(soln!-m,correction!-v,
                                              predicted!-f,v);
<<
  for i:=1:number!-of!-factors do
    print!-linear!-system(i,soln!-m,correction!-v,predicted!-f,v);
  terpri!*(nil) >>;

symbolic procedure print!-linear!-system(i,soln!-m,correction!-v,
                                              predicted!-f,v);
  begin scalar pv,sm,cv,mr,n,tt;
    terpri!*(t);
    prin2!* " i = "; printstr i;
    terpri!*(nil);
    sm:=getv(soln!-m,i);
    cv:=getv(correction!-v,i);
      pv:=getv(predicted!-f,i);
      n:=iadd1 getv(pv,0);
      for j:=1:n do << % for each row in matrix ... ;
        prin2!* "(  ";
        tt:=2;
        mr:=getv(sm,j);  % matrix row;
      for k:=1:n do << % for each elt in row ... ;
          prin2!* getv(mr,k);
          ttab!* (tt:=tt+10) >>;
        prin2!* ")  ( [";
        if j=1 then prin2!* 1
        else prinsf adjoin!-term(mksp(v,getv(pv,isub1 j)),1,polyzero);
      prin2!* "]";
      ttab!* (tt:=tt+10);
      prin2!* " )";
      if j=(n/2) then prin2!* "  =  (  " else prin2!* "     (  ";
      prinsf getv(cv,j);
      ttab!* (tt:=tt+30); printstr ")";
      if not(j=n) then <<
        tt:=2;
        prin2!* "(";
        ttab!* (tt:=tt+n*10);
        prin2!* ")  (";
        ttab!* (tt:=tt+10);
        prin2!* " )     (";
        ttab!* (tt:=tt+30);
        printstr ")" >> >>;
    terpri!*(t)
  end;

symbolic procedure try!-prediction(sm,cv,pv,n,i,poly,v,ff,ffhat);
  begin scalar w,ffi,fhati;
    sm:=getv(sm,i);
    cv:=getv(cv,i);
    pv:=getv(pv,i);
    if not(n=iadd1 getv(pv,0)) then
      errorf list("Predicted unknowns gone wrong? ",n,iadd1 getv(pv,0));
    if null getm2(sm,1,0) then <<
      w:=lu!-factorize!-mod!-p(sm,n);
      if w='singular then <<
        factor!-trace <<
          prin2!* "Prediction for ";
          prin2!* if null ff then 'f else 'a;
          prin2!* "("; prin2!* i;
          printstr ") failed due to singular matrix." >>;
        return (w . i) >> >>;
    back!-substitute(sm,cv,n);
    w:=
      if null ff then try!-factor(poly,cv,pv,n,v)
      else <<
        ffi := getv(ff,i);
        fhati := getv(ffhat,i); % The unfolding here is to get round
                                % a bug in the PSL compiler 12/9/82. It
                                % will be tidied back up as soon as
                                % possible;
        try!-alpha(poly,cv,pv,n,v,ffi,fhati) >>;
    if w='bad!-prediction then <<
      factor!-trace <<
        prin2!* "Prediction for ";
        prin2!* if null ff then 'f else 'a;
        prin2!* "("; prin2!* i;
        printstr ") was an inadequate guess." >>;
      return (w . i) >>;
    factor!-trace <<
      prin2!* "Prediction for ";
      prin2!* if null ff then 'f else 'a;
      prin2!* "("; prin2!* i; prin2!* ") worked: ";
      printsf car w >>;
    return (i . w)
  end;

symbolic procedure try!-factor(poly,testv,predictedf,n,v);
  begin scalar r,w;
    r:=getv(testv,1);
    for j:=2:n do <<
      w:=!*f2mod adjoin!-term(mksp(v,getv(predictedf,isub1 j)),1,
                              polyzero);
      r:=plus!-mod!-p(r,times!-mod!-p(w,getv(testv,j))) >>;
    w:=quotient!-mod!-p(poly,r);
    if didntgo w or
      not polyzerop difference!-mod!-p(poly,times!-mod!-p(w,r)) then
      return 'bad!-prediction
    else return list(r,w)
  end;

symbolic procedure try!-alpha(poly,testv,predictedf,n,v,fi,fhati);
  begin scalar r,w,wr;
    r:=getv(testv,1);
    for j:=2:n do <<
      w:=!*f2mod adjoin!-term(mksp(v,getv(predictedf,isub1 j)),1,
                              polyzero);
      r:=plus!-mod!-p(r,times!-mod!-p(w,getv(testv,j))) >>;
    if polyzerop
      (wr:=difference!-mod!-p(poly,times!-mod!-p(r,fhati))) then
      return list (r,wr);
    w:=quotient!-mod!-p(wr,fi);
    if didntgo w or
      not polyzerop difference!-mod!-p(wr,times!-mod!-p(w,fi)) then
      return 'bad!-prediction
    else return list(r,wr)
  end;



endmodule;


module modpoly;   % Routines for performing arithmetic on multivariate
                  % polynomials with coefficients that are modular
                  % numbers as defined by modular!-plus etc.

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(current!-modulus
        exact!-quotient!-flag
        m!-image!-variable
        modulus!/2
        reduction!-count);

% Note that the datastructure used is the same as that used in
% REDUCE except that it is assumed that domain elements are atomic.

symbolic smacro procedure comes!-before(p1,p2);
   % Similar to the REDUCE function ORDPP, but does not cater for non-
   % commutative terms and assumes that exponents are small integers.
    (car p1=car p2 and igreaterp(cdr p1,cdr p2)) or
       (not car p1=car p2 and ordop(car p1,car p2));

symbolic procedure plus!-mod!-p(a,b);
   % form the sum of the two polynomials a and b working over the
   % ground domain defined by the routines % modular!-plus,
   % modular!-times etc. the inputs to this % routine are assumed to
   % have coefficients already in the required domain.
   if null a then b
   else if null b then a
   else if domainp a then
      if domainp b then !*n2f modular!-plus(a,b)
      else (lt b) .+ plus!-mod!-p(a,red b)
   else if domainp b then (lt a) .+ plus!-mod!-p(red a,b)
   else if lpow a = lpow b then
      adjoin!-term(lpow a,
         plus!-mod!-p(lc a,lc b),plus!-mod!-p(red a,red b))
   else if comes!-before(lpow a,lpow b) then
         (lt a) .+ plus!-mod!-p(red a,b)
   else (lt b) .+ plus!-mod!-p(a,red b);

symbolic procedure times!-mod!-p(a,b);
   if (null a) or (null b) then nil
   else if domainp a then multiply!-by!-constant!-mod!-p(b,a)
   else if domainp b then multiply!-by!-constant!-mod!-p(a,b)
   else if mvar a=mvar b then plus!-mod!-p(
     plus!-mod!-p(times!-term!-mod!-p(lt a,b),
                  times!-term!-mod!-p(lt b,red a)),
     times!-mod!-p(red a,red b))
   else if ordop(mvar a,mvar b) then
     adjoin!-term(lpow a,times!-mod!-p(lc a,b),times!-mod!-p(red a,b))
   else adjoin!-term(lpow b,
        times!-mod!-p(a,lc b),times!-mod!-p(a,red b));

symbolic procedure times!-term!-mod!-p(term,b);
   % Multiply the given polynomial by the given term.
    if null b then nil
    else if domainp b then
        adjoin!-term(tpow term,
            multiply!-by!-constant!-mod!-p(tc term,b),nil)
    else if tvar term=mvar b then
         adjoin!-term(mksp(tvar term,iplus(tdeg term,ldeg b)),
                      times!-mod!-p(tc term,lc b),
                      times!-term!-mod!-p(term,red b))
    else if ordop(tvar term,mvar b) then
      adjoin!-term(tpow term,times!-mod!-p(tc term,b),nil)
    else adjoin!-term(lpow b,
      times!-term!-mod!-p(term,lc b),
      times!-term!-mod!-p(term,red b));

symbolic procedure difference!-mod!-p(a,b);
   plus!-mod!-p(a,minus!-mod!-p b);

symbolic procedure minus!-mod!-p a;
   if null a then nil
   else if domainp a then modular!-minus a
   else (lpow a .* minus!-mod!-p lc a) .+ minus!-mod!-p red a;


symbolic procedure reduce!-mod!-p a;
   % Converts a multivariate poly from normal into modular polynomial.
    if null a then nil
    else if domainp a then !*n2f modular!-number a
    else adjoin!-term(lpow a,reduce!-mod!-p lc a,reduce!-mod!-p red a);

symbolic procedure monic!-mod!-p a;
   % This procedure can only cope with polys that have a numeric
   % leading coeff.
   if a=nil then nil
   else if domainp a then 1
   else if lc a = 1 then a
   else if not domainp lc a then
       errorf "LC NOT NUMERIC IN MONIC-MOD-P"
   else multiply!-by!-constant!-mod!-p(a,
     modular!-reciprocal lc a);

symbolic procedure quotfail!-mod!-p(a,b);
   % Form quotient A/B, but complain if the division is not exact.
  begin scalar c;
    exact!-quotient!-flag:=t;
    c:=quotient!-mod!-p(a,b);
    if exact!-quotient!-flag then return c
    else errorf "QUOTIENT NOT EXACT (MOD P)"
  end;

symbolic procedure quotient!-mod!-p(a,b);
   % Truncated quotient of a by b.
    if null b then errorf "B=0 IN QUOTIENT-MOD-P"
    else if domainp b then multiply!-by!-constant!-mod!-p(a,
                             modular!-reciprocal b)
    else if a=nil then nil
    else if domainp a then exact!-quotient!-flag:=nil
    else if mvar a=mvar b then xquotient!-mod!-p(a,b,mvar b)
    else if ordop(mvar a,mvar b) then
       adjoin!-term(lpow a,
          quotient!-mod!-p(lc a,b),
          quotient!-mod!-p(red a,b))
    else exact!-quotient!-flag:=nil;


symbolic procedure xquotient!-mod!-p(a,b,v);
   % Truncated quotient a/b given that b is nontrivial.
    if a=nil then nil
    else if (domainp a) or (not mvar a=v) or
      ilessp(ldeg a,ldeg b) then exact!-quotient!-flag:=nil
    else if ldeg a = ldeg b then begin scalar w;
      w:=quotient!-mod!-p(lc a,lc b);
      if difference!-mod!-p(a,times!-mod!-p(w,b)) then
        exact!-quotient!-flag:=nil;
      return w
      end
    else begin scalar term;
      term:=mksp(mvar a,idifference(ldeg a,ldeg b)) .*
        quotient!-mod!-p(lc a,lc b);
   % That is the leading term of the quotient.  Now subtract term*b from
   % a.
      a:=plus!-mod!-p(red a,
                      times!-term!-mod!-p(negate!-term term,red b));
   % or a:=a-b*term given leading terms must cancel.
      return term .+ xquotient!-mod!-p(a,b,v)
    end;

symbolic procedure negate!-term term;
   % Negate a term.
    tpow term .* minus!-mod!-p tc term;


symbolic procedure remainder!-mod!-p(a,b);
   % Remainder when a is divided by b.
    if null b then errorf "B=0 IN REMAINDER-MOD-P"
    else if domainp b then nil
    else if domainp a then a
    else xremainder!-mod!-p(a,b,mvar b);


symbolic procedure xremainder!-mod!-p(a,b,v);
   % Remainder when the modular polynomial a is divided by b, given that
   % b is non degenerate.
   if (domainp a) or (not mvar a=v) or ilessp(ldeg a,ldeg b) then a
   else begin
    scalar q,w;
    q:=quotient!-mod!-p(minus!-mod!-p lc a,lc b);
   % compute -lc of quotient.
    w:=idifference(ldeg a,ldeg b); %ldeg of quotient;
    if w=0 then a:=plus!-mod!-p(red a,
      multiply!-by!-constant!-mod!-p(red b,q))
    else
      a:=plus!-mod!-p(red a,times!-term!-mod!-p(
            mksp(mvar b,w) .* q,red b));
   % The above lines of code use red a and red b because by construc-
   % tion the leading terms of the required % answers will cancel out.
     return xremainder!-mod!-p(a,b,v)
   end;

symbolic procedure multiply!-by!-constant!-mod!-p(a,n);
   % Multiply the polynomial a by the constant n.
   if null a then nil
   else if n=1 then a
   else if domainp a then !*n2f modular!-times(a,n)
   else adjoin!-term(lpow a,multiply!-by!-constant!-mod!-p(lc a,n),
     multiply!-by!-constant!-mod!-p(red a,n));

symbolic procedure gcd!-mod!-p(a,b);
   % Return the monic gcd of the two modular univariate polynomials a
   % and b.  Set REDUCTION-COUNT to the number of steps taken in the
   % process.
 << reduction!-count := 0;
    if null a then monic!-mod!-p b
    else if null b then monic!-mod!-p a
    else if domainp a then 1
    else if domainp b then 1
    else if igreaterp(ldeg a,ldeg b) then
      ordered!-gcd!-mod!-p(a,b)
    else ordered!-gcd!-mod!-p(b,a) >>;

symbolic procedure ordered!-gcd!-mod!-p(a,b);
   % As above, but deg a > deg b.
  begin scalar steps;
    steps := 0;
top:
    a := reduce!-degree!-mod!-p(a,b);
    if null a then return monic!-mod!-p b;
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

symbolic procedure reduce!-degree!-mod!-p(a,b);
   % Compute A-Q*B where Q is a single term chosen so that the result
   % has lower degree than A did.
  begin
    scalar q,w;
    q:=modular!-quotient(modular!-minus lc a,lc b);
   % compute -lc of quotient;
    w:=idifference(ldeg a,ldeg b); %ldeg of quotient;
   % The next lines of code use red a and red b because by construction
   % the leading terms of the required answers will cancel out.
    if w=0 then return plus!-mod!-p(red a,
      multiply!-by!-constant!-mod!-p(red b,q))
    else return plus!-mod!-p(red a,times!-term!-mod!-p(
            mksp(mvar b,w) .* q,red b))
   end;

symbolic procedure derivative!-mod!-p a;
   % Derivative of a wrt its main variable.
   if domainp a then nil
   else if ldeg a=1 then lc a
   else derivative!-mod!-p!-1(a,mvar a);

symbolic procedure derivative!-mod!-p!-1(a,v);
    if domainp a then nil
    else if not mvar a=v then nil
    else if ldeg a=1 then lc a
   else adjoin!-term(mksp(v,isub1 ldeg a),
                 multiply!-by!-constant!-mod!-p(lc a,
                                                modular!-number ldeg a),
                 derivative!-mod!-p!-1(red a,v));

symbolic procedure square!-free!-mod!-p a;
   % predicate that tests if a is square-free as a modular univariate
   % polynomial.
    domainp a or domainp gcd!-mod!-p(a,derivative!-mod!-p a);

symbolic procedure evaluate!-mod!-p(a,v,n);
   % Evaluate polynomial A at the point V=N.
    if domainp a then a
    else if n=0 then evaluate!-mod!-p(a,v,nil)
    else if v=nil then errorf "Variable=NIL in EVALUATE-MOD-P"
    else if mvar a=v then horner!-rule!-mod!-p(lc a,ldeg a,red a,n,v)
    else adjoin!-term(lpow a,
      evaluate!-mod!-p(lc a,v,n),
      evaluate!-mod!-p(red a,v,n));

symbolic procedure horner!-rule!-mod!-p(v,degg,a,n,var);
   % V is the running total, and it must be multiplied by n**deg and
   % added to the value of a at n.
    if domainp a or not mvar a=var
      then if null n or zerop n then a
            else <<v:=times!-mod!-p(v,expt!-mod!-p(n,degg));
                   plus!-mod!-p(a,v)>>
    else begin scalar newdeg;
      newdeg:=ldeg a;
      return horner!-rule!-mod!-p(if null n or zerop n then lc a
                                   else plus!-mod!-p(lc a,
         times!-mod!-p(v,expt!-mod!-p(n,idifference(degg,newdeg)))),
       newdeg,red a,n,var)
    end;

symbolic procedure expt!-mod!-p(a,n);
   % a**n.
    if n=0 then 1
    else if n=1 then a
    else begin scalar w,x;
     w:=divide(n,2);
     x:=expt!-mod!-p(a,car w);
     x:=times!-mod!-p(x,x);
     if not (cdr w = 0) then x:=times!-mod!-p(x,a);
     return x
    end;

symbolic procedure make!-bivariate!-mod!-p(u,imset,v);
   % Substitute into U for all variables in IMSET which should result in
   % a bivariate poly. One variable is M-IMAGE-VARIABLE and V is the
   % other U is modular multivariate with these two variables at top 2
   % levels - V at 2nd level.
  if domainp u then u
  else if mvar u = m!-image!-variable then
    adjoin!-term(lpow u,make!-univariate!-mod!-p(lc u,imset,v),
      make!-bivariate!-mod!-p(red u,imset,v))
  else make!-univariate!-mod!-p(u,imset,v);

symbolic procedure make!-univariate!-mod!-p(u,imset,v);
   % Substitute into U for all variables in IMSET giving a univariate
   % poly in V. U is modular multivariate with V at top level.
  if domainp u then u
  else if mvar u = v then
    adjoin!-term(lpow u,!*n2f evaluate!-in!-order!-mod!-p(lc u,imset),
      make!-univariate!-mod!-p(red u,imset,v))
  else !*n2f evaluate!-in!-order!-mod!-p(u,imset);

symbolic procedure evaluate!-in!-order!-mod!-p(u,imset);
   % Makes an image of u wrt imageset, imset, using Horner's rule.
   % Result should be purely numeric (and modular).
  if domainp u then !*d2n u
   else if mvar u=caar imset then
    horner!-rule!-in!-order!-mod!-p(
      evaluate!-in!-order!-mod!-p(lc u,cdr imset),ldeg u,red u,imset)
   else evaluate!-in!-order!-mod!-p(u,cdr imset);

symbolic procedure horner!-rule!-in!-order!-mod!-p(c,degg,a,vset);
   % C is running total and a is what is left.
  if domainp a then modular!-plus(!*d2n a,
    modular!-times(c,modular!-expt(cdar vset,degg)))
  else if not(mvar a=caar vset) then
    modular!-plus(
      evaluate!-in!-order!-mod!-p(a,cdr vset),
      modular!-times(c,modular!-expt(cdar vset,degg)))
  else begin scalar newdeg;
    newdeg:=ldeg a;
    return horner!-rule!-in!-order!-mod!-p(
      modular!-plus(
        evaluate!-in!-order!-mod!-p(lc a,cdr vset),
        modular!-times(c,
          modular!-expt(cdar vset,(idifference(degg,newdeg))))),
      newdeg,red a,vset)
  end;

symbolic procedure make!-modular!-symmetric a;
   % Input is a multivariate MODULAR poly A with nos in range 0->(p-1).
   % This folds it onto the symmetric range (-p/2)->(p/2).
    if null a then nil
    else if domainp a then
      if a>modulus!/2 then !*n2f(a - current!-modulus)
      else a
    else adjoin!-term(lpow a,make!-modular!-symmetric lc a,
      make!-modular!-symmetric red a);

endmodule;


module multihen;   %  Hensel construction for the multivariate case.
                   %  (This version is highly recursive.)

% Authors: A. C. Norman and P. M. A. Moore, 1979.

fluid '(!*overshoot
        !*trfac
        alphavec
        bad!-case
        factor!-level
        factor!-trace!-list
        fhatvec
        hensel!-growth!-size
        max!-unknowns
        number!-of!-factors
        number!-of!-unknowns
        predictions);


symbolic procedure find!-multivariate!-factors!-mod!-p(poly,
    best!-factors,variable!-set);
    % All arithmetic is done mod p, best-factors is overwritten.
    if null variable!-set then best!-factors
    else (lambda factor!-level; begin
    scalar growth!-factor,b0s,res,v,
           bhat0s,w,degbd,first!-time,redpoly,
           predicted!-forms,number!-of!-unknowns,solve!-count,
           correction!-vectors,soln!-matrices,max!-unknowns,
           unknowns!-count!-list,poly!-remaining,
           prediction!-results,one!-prediction!-failed;
    v:=car variable!-set;
    degbd:=get!-degree!-bound car v;
    first!-time:=t;
    growth!-factor:=make!-growth!-factor v;
    poly!-remaining:=poly;
    prediction!-results:=mkvect number!-of!-factors;
    find!-msg1(best!-factors,growth!-factor,poly);
    b0s:=reduce!-vec!-by!-one!-var!-mod!-p(best!-factors,
                    v,number!-of!-factors);
            % The above made a copy of the vector.
    for i:=1:number!-of!-factors do
      putv(best!-factors,i,
        difference!-mod!-p(getv(best!-factors,i),getv(b0s,i)));
    redpoly:=evaluate!-mod!-p(poly,car v,cdr v);
    find!-msg2(v,variable!-set);
    find!-multivariate!-factors!-mod!-p(redpoly,b0s,cdr variable!-set);
            % answers in b0s.
    if bad!-case then return;
    for i:=1:number!-of!-factors do
      putv(best!-factors,i,
        plus!-mod!-p(getv(b0s,i),getv(best!-factors,i)));
    find!-msg3(best!-factors,v);
    res:=diff!-over!-k!-mod!-p(
        difference!-mod!-p(poly,
          times!-vector!-mod!-p(best!-factors,number!-of!-factors)),
        1,car v);
            % RES is the residue and must eventually be reduced to zero.
    factor!-trace << printsf res; terpri!*(nil) >>;
    if not polyzerop res and
      cdr variable!-set and not zerop cdr v then <<
      predicted!-forms:=make!-bivariate!-vec!-mod!-p(best!-factors,
        cdr variable!-set,car v,number!-of!-factors);
      find!-multivariate!-factors!-mod!-p(
        make!-bivariate!-mod!-p(poly,cdr variable!-set,car v),
        predicted!-forms,list v);
            % Answers in PREDICTED!-FORMS.
      find!-msg4(predicted!-forms,v);
      make!-predicted!-forms(predicted!-forms,car v);
            % Sets max!-unknowns and number!-of!-unknowns.
      find!-msg5();
      unknowns!-count!-list:=number!-of!-unknowns;
      while unknowns!-count!-list and
         (car (w:=car unknowns!-count!-list))=1 do
        begin scalar i,r;
          unknowns!-count!-list:=cdr unknowns!-count!-list;
          i:=cdr w;
          w:=quotient!-mod!-p(poly!-remaining,r:=getv(best!-factors,i));
          if didntgo w or
            not polyzerop difference!-mod!-p(poly!-remaining,
            times!-mod!-p(w,r)) then
            if one!-prediction!-failed then <<
              factor!-trace printstr "Predictions are no good";
              max!-unknowns:=nil >>
            else <<
              factor!-trace <<
                prin2!* "Guess for f(";
                prin2!* i;
                printstr ") was bad." >>;
              one!-prediction!-failed:=i >>
          else <<
            putv(prediction!-results,i,r);
            factor!-trace <<
              prin2!* "Prediction for f("; prin2!* i;
              prin2!* ") worked: ";
              printsf r >>;
            poly!-remaining:=w >>
        end;
      w:=length unknowns!-count!-list;
      if w=1 and not one!-prediction!-failed then <<
        putv(best!-factors,cdar unknowns!-count!-list,poly!-remaining);
        go to exit >>
      else if w=0 and one!-prediction!-failed then <<
        putv(best!-factors,one!-prediction!-failed,poly!-remaining);
        go to exit >>;
      solve!-count:=1;
      if max!-unknowns then
        correction!-vectors:=
           make!-correction!-vectors(best!-factors,max!-unknowns) >>;
    bhat0s:=make!-multivariate!-hatvec!-mod!-p(b0s,number!-of!-factors);
    return multihen1(list(res,
                             growth!-factor,
                             first!-time,
                             bhat0s,
                             b0s,
                             variable!-set,
                             solve!-count,
                             correction!-vectors,
                             unknowns!-count!-list,
                             best!-factors,
                             v,
                             degbd,
                             soln!-matrices,
                             predicted!-forms,
                             poly!-remaining,
                             prediction!-results,
                             one!-prediction!-failed),
                             nil);
exit:
      multihen!-exit(first!-time,best!-factors,nil);
  end) (factor!-level+1);

symbolic procedure multihen1(u,zz);
   begin scalar res,test!-prediction,growth!-factor,first!-time,hat0s,
            x0s,variable!-set,solve!-count,correction!-vectors,
            unknowns!-count!-list,correction!-factor,frvec,v,
            degbd,soln!-matrices,predicted!-forms,poly!-remaining,
            fvec,previous!-prediction!-holds,
            prediction!-results,one!-prediction!-failed,
            bool,d,x1,k,kk,substres,w;
      res := car u; u := cdr u;
      growth!-factor := car u; u := cdr u;
      first!-time := car u; u := cdr u;
      hat0s := car u; u := cdr u;
      x0s := car u; u := cdr u;
      variable!-set := car u; u := cdr u;
      solve!-count := car u; u := cdr u;
      correction!-vectors := car u; u := cdr u;
      unknowns!-count!-list := car u; u := cdr u;
      frvec := car u; u := cdr u;
      v := car u; u := cdr u;
      degbd := car u; u := cdr u;
      soln!-matrices := car u; u := cdr u;
      predicted!-forms := car u; u := cdr u;
      poly!-remaining := car u; u := cdr u;
      prediction!-results := car u; u := cdr u;
      if zz then <<fvec := car u; u := cdr u;
                   previous!-prediction!-holds := car u; u := cdr u>>;
      one!-prediction!-failed := car u;
      correction!-factor:=growth!-factor;
            % Next power of growth-factor we are adding to the factors.
      x1:=mkvect number!-of!-factors;
      k:=1;
      kk:=0;
temploop:
    bool := nil;
    while not bool and not polyzerop res and (null max!-unknowns
                      or null test!-prediction) do
      if k>degbd then <<
        factor!-trace <<
          prin2!* "We have overshot the degree bound for ";
          printvar car v >>;
        if !*overshoot then
          prin2t "Multivariate degree bound overshoot -> restart";
        bad!-case:= bool := t >>
      else
        if polyzerop(substres:=evaluate!-mod!-p(res,car v,cdr v))
         then <<
          k:=iadd1 k;
          res:=diff!-over!-k!-mod!-p(res,k,car v);
          correction!-factor:=
            times!-mod!-p(correction!-factor,growth!-factor) >>
      else begin
        multihen!-msg(growth!-factor,first!-time,k,kk,substres,zz);
        if null zz
          then <<kk := kk#+1; if first!-time then first!-time := nil>>;
        solve!-for!-corrections(substres,hat0s,x0s,x1,
                                cdr variable!-set);
            % Answers left in x1.
        if bad!-case then return (bool := t);
        if max!-unknowns then <<
          solve!-count:=iadd1 solve!-count;
          for i:=1:number!-of!-factors do
            putv(getv(correction!-vectors,i),solve!-count,getv(x1,i));
          if solve!-count=caar unknowns!-count!-list then
            test!-prediction:=t >>;
        if zz then
           for i:=1:number!-of!-factors do
             putv(frvec,i,plus!-mod!-p(getv(frvec,i),times!-mod!-p(
                  getv(x1,i),correction!-factor)));
        factor!-trace <<
          printstr "   Giving:";
          if null zz then
          printvec("     f(",number!-of!-factors,",1) = ",x1)
           else <<
          printvec("     a(",number!-of!-factors,",1) = ",x1);
          printstr "   New a's are now:";
          printvec("     a(",number!-of!-factors,") = ",frvec) >>>>;
         d:=times!-mod!-p(correction!-factor,
              if zz then form!-sum!-and!-product!-mod!-p(x1,fhatvec,
                number!-of!-factors)
               else terms!-done!-mod!-p(frvec,x1,correction!-factor));
        if degree!-in!-variable(d,car v)>degbd then <<
          factor!-trace <<
            prin2!* "We have overshot the degree bound for ";
            printvar car v >>;
          if !*overshoot then
            prin2t "Multivariate degree bound overshoot -> restart";
          bad!-case:=t;
          return (bool := t)>>;
        d:=diff!-k!-times!-mod!-p(d,k,car v);
        if null zz then
           for i:=1:number!-of!-factors do
             putv(frvec,i,
               plus!-mod!-p(getv(frvec,i),
                 times!-mod!-p(getv(x1,i),correction!-factor)));
        k:=iadd1 k;
        res:=diff!-over!-k!-mod!-p(difference!-mod!-p(res,d),k,car v);
        factor!-trace <<
           if null zz then <<printstr "   New factors are now:";
                printvec("     f(",number!-of!-factors,") = ",frvec)>>;
          prin2!* "   and residue = ";
          printsf res;
          printstr "-------------"
        >>;
        correction!-factor:=
          times!-mod!-p(correction!-factor,growth!-factor) end;
    if not polyzerop res and not bad!-case then <<
      if null zz or null soln!-matrices then
        soln!-matrices
           := construct!-soln!-matrices(predicted!-forms,cdr v);
      factor!-trace <<
        if null zz then <<
        printstr "We use the results from the Hensel growth to";
        printstr "produce a set of linear equations to solve";
        printstr "for coefficients in the relevant factors:" >>
         else <<
        printstr "The Hensel growth so far allows us to test some of";
        printstr "our predictions:" >>>>;
      bool := nil;
      while not bool and unknowns!-count!-list and
        (car (w:=car unknowns!-count!-list))=solve!-count do <<
        unknowns!-count!-list:=cdr unknowns!-count!-list;
        factor!-trace
          print!-linear!-system(cdr w,soln!-matrices,
            correction!-vectors,predicted!-forms,car v);
        w:=try!-prediction(soln!-matrices,correction!-vectors,
          predicted!-forms,car w,cdr w,poly!-remaining,car v,
          if zz then fvec else nil,
          if zz then fhatvec else nil);
        if car w='singular or car w='bad!-prediction then
          if one!-prediction!-failed then <<
            factor!-trace printstr "Predictions were no help.";
            max!-unknowns:=nil;
            bool := t>>
          else if null zz then one!-prediction!-failed:=cdr w
          else <<
            if previous!-prediction!-holds then <<
              predictions:=delasc(car v,predictions);
              previous!-prediction!-holds:=nil >>;
            one!-prediction!-failed:=cdr w >>
        else <<
          putv(prediction!-results,car w,cadr w);
          poly!-remaining:=caddr w >> >>;
      if null max!-unknowns then <<
        if zz and previous!-prediction!-holds then
          predictions:=delasc(car v,predictions);
        goto temploop >>;
      w:=length unknowns!-count!-list;
      if w>1 or (w=1 and one!-prediction!-failed) then <<
        test!-prediction:=nil;
        goto temploop >>;
      if w=1 or one!-prediction!-failed then <<
        w:=if one!-prediction!-failed then one!-prediction!-failed
           else cdar unknowns!-count!-list;
        putv(prediction!-results,w,
             if null zz then poly!-remaining
              else quotfail!-mod!-p(poly!-remaining,
                                    getv(fhatvec,w)))>>;
      for i:=1:number!-of!-factors do
          putv(frvec,i,getv(prediction!-results,i));
      if (not previous!-prediction!-holds or null zz)
         and not one!-prediction!-failed then
        predictions:=
          (car v .
            list(soln!-matrices,predicted!-forms,max!-unknowns,
              number!-of!-unknowns))
          . predictions >>;
      multihen!-exit(first!-time,frvec,zz)
   end;

symbolic
   procedure multihen!-msg(growth!-factor,first!-time,k,kk,substres,zz);
        factor!-trace <<
          prin2!* "Hensel Step "; printstr (kk:=kk #+ 1);
          prin2!* "-------------";
          if kk>10 then printstr "-" else terpri!*(t);
          prin2!* "Next corrections are for (";
          prinsf growth!-factor;
          if not (k=1) then <<
            prin2!* ") ** ";
            prin2!* k >> else prin2!* '!);
          printstr ". To find these we solve:";
          if zz then prin2!* "     sum over i [ a(i,1)*fhat(i,0) ] = "
           else prin2!* "     sum over i [ f(i,1)*fhat(i,0) ] = ";
          prinsf substres;
          prin2!* " mod ";
          prin2!* hensel!-growth!-size;
          if zz then printstr " for a(i,1). "
           else printstr " for f(i,1), ";
          if null zz and first!-time then <<
            prin2!*
               "       where fhat(i,0) = product over j [ f(j,0) ]";
            prin2!* " / f(i,0) mod ";
            printstr hensel!-growth!-size >>;
          terpri!*(nil)
        >>;

symbolic procedure multihen!-exit(first!-time,frvec,zz);
      factor!-trace <<
      if not bad!-case then
        if first!-time then
          if zz then printstr "But these a's are already correct."
           else printstr "Therefore these factors are already correct."
        else <<
          if zz then <<printstr "Correct a's are:";
                     printvec("  a(",number!-of!-factors,") = ",frvec)>>
           else <<printstr "Correct factors are:";
                 printvec("  f(",number!-of!-factors,") = ",frvec) >>>>;
      terpri!*(nil);
      printstr "**************************************************";
      terpri!*(nil)>>;

symbolic procedure find!-msg1(best!-factors,growth!-factor,poly);
    factor!-trace <<
      printstr "Want f(i) s.t.";
      prin2!* "  product over i [ f(i) ] = ";
      prinsf poly;
      prin2!* " mod ";
      printstr hensel!-growth!-size;
      terpri!*(nil);
      printstr "We know f(i) as follows:";
      printvec("  f(",number!-of!-factors,") = ",best!-factors);
      prin2!* " and we shall put in powers of ";
      prinsf growth!-factor;
      printstr " to find them fully."
    >>;

symbolic procedure find!-msg2(v,variable!-set);
    factor!-trace <<
      prin2!*
         "First solve the problem in one less variable by putting ";
      prinvar car v; prin2!* "="; printstr cdr v;
      if cdr variable!-set then <<
        prin2!* "and growing wrt ";
        printvar caadr variable!-set
        >>;
      terpri!*(nil)
    >>;

symbolic procedure find!-msg3(best!-factors,v);
    factor!-trace <<
      prin2!* "After putting back any knowledge of ";
      prinvar car v;
      printstr ", we have the";
      printstr "factors so far as:";
      printvec("  f(",number!-of!-factors,") = ",best!-factors);
      printstr "Subtracting the product of these from the polynomial";
      prin2!* "and differentiating wrt "; prinvar car v;
      printstr " gives a residue:"
    >>;

symbolic procedure find!-msg4(predicted!-forms,v);
      factor!-trace <<
        printstr "To help reduce the number of Hensel steps we try";
        prin2!* "predicting how many terms each factor will have wrt ";
        prinvar car v; printstr ".";
        printstr
          "Predictions are based on the bivariate factors :";
        printvec("     f(",number!-of!-factors,") = ",predicted!-forms)
        >>;

symbolic procedure find!-msg5;
      factor!-trace <<
        terpri!*(nil);
        printstr "We predict :";
        for each w in number!-of!-unknowns do <<
          prin2!* car w;
          prin2!* " terms in f("; prin2!* cdr w; printstr '!) >>;
        if (caar number!-of!-unknowns)=1 then <<
          prin2!* "Since we predict only one term for f(";
          prin2!* cdar number!-of!-unknowns;
          printstr "), we can try";
          printstr "dividing it out now:" >>
        else <<
          prin2!* "So we shall do at least ";
          prin2!* isub1 caar number!-of!-unknowns;
          prin2!* " Hensel step";
          if (caar number!-of!-unknowns)=2 then printstr "."
          else printstr "s." >>;
        terpri!*(nil) >>;

symbolic procedure solve!-for!-corrections(c,fhatvec,fvec,resvec,vset);
% ....;
  if null vset then
    for i:=1:number!-of!-factors do
      putv(resvec,i,
        remainder!-mod!-p(
          times!-mod!-p(c,getv(alphavec,i)),
          getv(fvec,i)))
  else (lambda factor!-level; begin
    scalar residue,growth!-factor,f0s,fhat0s,v,
      degbd,first!-time,redc,
      predicted!-forms,max!-unknowns,solve!-count,number!-of!-unknowns,
      correction!-vectors,soln!-matrices,w,previous!-prediction!-holds,
      unknowns!-count!-list,poly!-remaining,
      prediction!-results,one!-prediction!-failed;
    v:=car vset;
    degbd:=get!-degree!-bound car v;
    first!-time:=t;
    growth!-factor:=make!-growth!-factor v;
    poly!-remaining:=c;
    prediction!-results:=mkvect number!-of!-factors;
    redc:=evaluate!-mod!-p(c,car v,cdr v);
    solve!-msg1(c,fvec,v);
    solve!-for!-corrections(redc,
      fhat0s:=reduce!-vec!-by!-one!-var!-mod!-p(
        fhatvec,v,number!-of!-factors),
      f0s:=reduce!-vec!-by!-one!-var!-mod!-p(
        fvec,v,number!-of!-factors),
      resvec,
      cdr vset); % Results left in RESVEC.
    if bad!-case then return;
    solve!-msg2(resvec,v);
    residue:=diff!-over!-k!-mod!-p(difference!-mod!-p(c,
          form!-sum!-and!-product!-mod!-p(resvec,fhatvec,
            number!-of!-factors)),1,car v);
    factor!-trace <<
      printsf residue;
      prin2!* " Now we shall put in the powers of ";
      prinsf growth!-factor;
      printstr " to find the a's fully."
    >>;
    if not polyzerop residue and not zerop cdr v then <<
      w:=atsoc(car v,predictions);
      if w then <<
        previous!-prediction!-holds:=t;
        factor!-trace <<
          printstr
             "We shall use the previous prediction for the form of";
          prin2!* "polynomials wrt "; printvar car v >>;
        w:=cdr w;
        soln!-matrices:=car w;
        predicted!-forms:=cadr w;
        max!-unknowns:=caddr w;
        number!-of!-unknowns:=cadr cddr w >>
      else <<
        factor!-trace <<
     printstr
        "We shall use a new prediction for the form of polynomials ";
        prin2!* "wrt "; printvar car v >>;
        predicted!-forms:=mkvect number!-of!-factors;
        for i:=1:number!-of!-factors do
          putv(predicted!-forms,i,getv(fvec,i));
            % Make a copy of the factors in a vector we shall overwrite.
        make!-predicted!-forms(predicted!-forms,car v);
            % Sets max!-unknowns and number!-of!-unknowns.
        >>;
      solve!-msg3();
      unknowns!-count!-list:=number!-of!-unknowns;
      while unknowns!-count!-list and
         (car (w:=car unknowns!-count!-list))=1 do
        begin scalar i,r,wr,fi;
          unknowns!-count!-list:=cdr unknowns!-count!-list;
          i:=cdr w;
          w:=quotient!-mod!-p(
            wr:=difference!-mod!-p(poly!-remaining,
              times!-mod!-p(r:=getv(resvec,i),getv(fhatvec,i))),
            fi:=getv(fvec,i));
          if didntgo w or not polyzerop
            difference!-mod!-p(wr,times!-mod!-p(w,fi)) then
            if one!-prediction!-failed then <<
              factor!-trace printstr "Predictions are no good.";
              max!-unknowns:=nil >>
            else <<
              factor!-trace <<
                prin2!* "Guess for a(";
                prin2!* i;
                printstr ") was bad." >>;
              one!-prediction!-failed:=i >>
          else <<
            putv(prediction!-results,i,r);
            factor!-trace <<
              prin2!* "Prediction for a("; prin2!* i;
              prin2!* ") worked: ";
              printsf r >>;
            poly!-remaining:=wr >>
        end;
      w:=length unknowns!-count!-list;
      if w=1 and not one!-prediction!-failed then <<
        putv(resvec,cdar unknowns!-count!-list,
          quotfail!-mod!-p(poly!-remaining,getv(fhatvec,
            cdar unknowns!-count!-list)));
        go to exit >>
      else if w=0 and one!-prediction!-failed then <<
        putv(resvec,one!-prediction!-failed,
          quotfail!-mod!-p(poly!-remaining,getv(fhatvec,
            one!-prediction!-failed)));
        go to exit >>;
      solve!-count:=1;
      if max!-unknowns then
        correction!-vectors:=
           make!-correction!-vectors(resvec,max!-unknowns) >>;
    if not polyzerop residue then first!-time:=nil;
    return multihen1(list(residue,
                            growth!-factor,
                            first!-time,
                            fhat0s,
                            f0s,
                            vset,
                            solve!-count,
                            correction!-vectors,
                            unknowns!-count!-list,
                            resvec,
                            v,
                            degbd,
                            soln!-matrices,
                            predicted!-forms,
                            poly!-remaining,
                            prediction!-results,
                            fvec,
                            previous!-prediction!-holds,
                            one!-prediction!-failed),
                            t);
exit:
      multihen!-exit(first!-time,resvec,t);
  end) (factor!-level+1);

symbolic procedure solve!-msg1(c,fvec,v);
    factor!-trace <<
      printstr "Want a(i) s.t.";
      prin2!* "(*)  sum over i [ a(i)*fhat(i) ] = ";
      prinsf c;
      prin2!* " mod ";
      printstr hensel!-growth!-size;
      prin2!* "    where fhat(i) = product over j [ f(j) ]";
      prin2!* " / f(i) mod ";
      printstr hensel!-growth!-size;
      printstr "    and";
      printvec("      f(",number!-of!-factors,") = ",fvec);
      terpri!*(nil);
      prin2!*
         "First solve the problem in one less variable by putting ";
      prinvar car v; prin2!* '!=; printstr cdr v;
      terpri!*(nil)
    >>;

symbolic procedure solve!-msg2(resvec,v);
    factor!-trace <<
      printstr "Giving:";
      printvec("  a(",number!-of!-factors,",0) = ",resvec);
      printstr "Subtracting the contributions these give in (*) from";
      prin2!* "the R.H.S. of (*) ";
      prin2!* "and differentiating wrt "; prinvar car v;
      printstr " gives a residue:"
    >>;

symbolic procedure solve!-msg3;
      factor!-trace <<
        terpri!*(nil);
        printstr "We predict :";
        for each w in number!-of!-unknowns do <<
          prin2!* car w;
          prin2!* " terms in a("; prin2!* cdr w; printstr '!) >>;
        if (caar number!-of!-unknowns)=1 then <<
          prin2!* "Since we predict only one term for a(";
          prin2!* cdar number!-of!-unknowns;
          printstr "), we can test it right away:" >>
        else <<
          prin2!* "So we shall do at least ";
          prin2!* isub1 caar number!-of!-unknowns;
          prin2!* " Hensel step";
          if (caar number!-of!-unknowns)=2 then printstr "."
          else printstr "s." >>;
        terpri!*(nil) >>;

endmodule;


module unihens;  % Univariate case of Hensel code with quadratic growth.

% Author: P. M. A. Moore, 1979.
% Modifications by J.H. Davenport 1988 following a 1985 draft by Abbott,
% Bradford and Davenport.

fluid '(!*linear
        !*overshoot
        !*overview
        !*trfac
        alphalist
        alphavec
        coefftbd
        current!-factor!-product
        current!-modulus
        delfvec
        deltam
        factor!-level
        factor!-trace!-list
        factors!-done
        factorvec
        facvec
        fhatvec
        hensel!-growth!-size
        hensel!-poly
        irreducible
        m!-image!-variable
        modfvec
        multivariate!-input!-poly
        non!-monic
        number!-of!-factors
        polyzero
        prime!-base
        reconstructing!-gcd);

global '(largest!-small!-modulus);


symbolic procedure uhensel!.extend(poly,best!-flist,lclist,p);
% Extend poly=product(factors in best!-flist) mod p even if poly is
% non-monic.  Return a list (ok. list of factors) if factors can be
% extended to be correct over the integers, otherwise return a list
% (failed <reason> <reason>).
  begin scalar w,k,old!-modulus,alphavec,modular!-flist,factorvec,
        modfvec,coefftbd,fcount,fhatvec,deltam,mod!-symm!-flist,
        current!-factor!-product,facvec,factors!-done,hensel!-poly;
    prime!-base:=p;
    old!-modulus:=set!-modulus p;
%   timer:=readtime();
    number!-of!-factors:=length best!-flist;
    w:=expt(lc poly,number!-of!-factors -1);
    if lc poly < 0 then errorf list("LC SHOULD NOT BE -VE",poly);
    coefftbd:=max(110,p+1,lc poly*get!-coefft!-bound(poly,ldeg poly));
    poly:=multf(poly,w);
    modular!-flist:=for each ff in best!-flist collect
      reduce!-mod!-p ff;
            % Modular factors have been multiplied by a constant to
            % fix the l.c.'s, so they may be out of range - this
            % fixes that.
      if not(w=1) then factor!-trace <<
        prin2!* "Altered univariate polynomial: "; printsf poly >>;
          % Make sure the leading coefft will not cause trouble
          % in the hensel construction.
    mod!-symm!-flist:=for each ff in modular!-flist collect
      make!-modular!-symmetric ff;
    if not !*overview then factor!-trace <<
      prin2!* "The factors mod "; prin2!* p;
      printstr " to start from are:";
      fcount:=1;
      for each ff in mod!-symm!-flist do <<
        prin2!* "   f("; prin2!* fcount; prin2!* ")=";
        printsf ff; fcount:=iadd1 fcount >>;
      terpri!*(nil) >>;
    alphalist:=alphas(number!-of!-factors,modular!-flist,1);
            % 'magic' polynomials associated with the image factors.
    if not !*overview then factor!-trace <<
      printstr
         "The following modular polynomials are chosen such that:";
      terpri();
      prin2!* "   a(1)*h(1) + ... + a(";
      prin2!* number!-of!-factors;
      prin2!* ")*h("; prin2!* number!-of!-factors;
      prin2!* ") = 1 mod "; printstr p;
      terpri();
      printstr "  where h(i)=(product of all f(j) [see below])/f(i)";
      printstr "    and degree of a(i) < degree of f(i).";
      fcount:=1;
      for each a in modular!-flist do <<
        prin2!* "   a("; prin2!* fcount; prin2!* ")=";
        printsf cdr get!-alpha a;
        prin2!* "   f("; prin2!* fcount; prin2!* ")=";
        printsf a;
        fcount:=iadd1 fcount >>
    >>;
    k:=0;
    factorvec:=mkvect number!-of!-factors;
    modfvec:=mkvect number!-of!-factors;
    alphavec:=mkvect number!-of!-factors;
    for each modsymmf in mod!-symm!-flist do
      << putv(factorvec,k:=k+1,force!-lc(modsymmf,car lclist));
         lclist:=cdr lclist
      >>;
    k:=0;
    for each modfactor in modular!-flist do
         << putv(modfvec,k:=k+1,modfactor);
         putv(alphavec,k,cdr get!-alpha modfactor);
         >>;
            % best!-fvec is now a vector of factors of poly correct
            % mod p with true l.c.s forced in.
    fhatvec:=mkvect number!-of!-factors;
    w:=hensel!-mod!-p(poly,modfvec,factorvec,coefftbd,nil,p);
    if car w='overshot then w := uhensel!.extend1(poly,w)
     else w := uhensel!.extend2 w;
   set!-modulus old!-modulus;
    if irreducible then <<
      factor!-trace
         printstr "Two factors and overshooting means irreducible";
      return t >>;
    factor!-trace begin scalar k;
      k:=0;
      printstr "Univariate factors, possibly with adjusted leading";
      printstr "coefficients, are:";
      for each ww in cdr w do <<
        prin2!* " f("; prin2!* (k:=k #+ 1);
        prin2!* ")="; printsf ww >>
    end;
    return if non!-monic then
        (car w . primitive!.parts(cdr w,m!-image!-variable,t))
      else w
  end;

symbolic procedure uhensel!.extend1(poly,w);
      begin scalar oklist,badlist,m,r,ff,om,pol;
        m:=cadr w; % the modulus.
        r:=getv(factorvec,0); % the number of factors.
        if r=2 then return (irreducible:=t);
        if factors!-done then <<
          poly:=hensel!-poly;
          for each ww in factors!-done do
            poly:=multf(poly,ww) >>;
        pol:=poly;
        om:=set!-modulus hensel!-growth!-size;
        alphalist:=nil;
        for i:=r step -1 until 1 do
          alphalist:=
             (reduce!-mod!-p getv(factorvec,i) . getv(alphavec,i))
                      . alphalist;
        set!-modulus om;
            % bring alphalist up to date.
        for i:=1:r do <<
          ff:=getv(factorvec,i);
          if not didntgo(w:=quotf(pol,ff)) then
          << oklist:=ff . oklist; pol:=w>>
          else badlist:=(i . ff) . badlist >>;
        if null badlist then w:='ok . oklist
        else <<
          if not !*overview then factor!-trace <<
            printstr "Overshot factors are:";
            for each f in badlist do <<
              prin2!* " f("; prin2!* car f; prin2!* ")=";
              printsf cdr f >>
          >>;
          w:=try!.combining(badlist,pol,m,nil);
          if car w='one! bad! factor then begin scalar x;
            w:=append(oklist,cdr w);
            x:=1;
            for each v in w do x:=multf(x,v);
            w:='ok . (quotfail(pol,x) . w)
          end
          else w:='ok . append(oklist,w) >>;
        if (not !*linear) and multivariate!-input!-poly then <<
          poly:=1;
          number!-of!-factors:=0;
          for each facc in cdr w do <<
            poly:=multf(poly,facc);
            number!-of!-factors:=1 #+ number!-of!-factors >>;
            % make sure poly is the product of the factors we have,
            % we recalculate it this way because we may have the wrong
            % lc in old value of poly.
          reset!-quadratic!-step!-fluids(poly,cdr w,
                                         number!-of!-factors);
          if m=deltam then errorf list("Coefft bound < prime ?",
              coefftbd,m);
          m:=deltam*deltam;
          while m<largest!-small!-modulus do <<
            quadratic!-step(m,number!-of!-factors);
            m:=m*deltam >>;
          hensel!-growth!-size:=deltam;
          om:=set!-modulus hensel!-growth!-size;
          alphalist:=nil;
          for i:=number!-of!-factors step -1 until 1 do
            alphalist:=
              (reduce!-mod!-p getv(factorvec,i) . getv(alphavec,i))
                      . alphalist;
          set!-modulus om >>;
         return w
      end;

symbolic procedure uhensel!.extend2 w;
   begin scalar r,faclist,om;
      r:=getv(factorvec,0); % no of factors.
      om:=set!-modulus hensel!-growth!-size;
      alphalist:=nil;
      for i:=r step -1 until 1 do
        alphalist:=(reduce!-mod!-p getv(factorvec,i) . getv(alphavec,i))
                    . alphalist;
      set!-modulus om;
            % bring alphalist up to date.
      for i:=r step -1 until 1 do
        faclist:=getv(factorvec,i) . faclist;
      return (car w . faclist)
    end;

symbolic procedure get!-coefft!-bound(poly,ddeg);
% This uses Mignotte's bound which is minimal I believe.
% NB. poly had better be univariate as bound only valid for this.
  binomial!-coefft(ddeg/2,ddeg/4) * root!-squares(poly,0);

symbolic procedure binomial!-coefft(n,r);
  if n<r then nil
  else if n=r then 1
  else if r=1 then n
  else begin scalar n!-c!-r,b;
    n!-c!-r:=1;
    b:=min(r,n-r);
    for i:=1:b do
      n!-c!-r:=(n!-c!-r * (n - i + 1)) / i;
    return n!-c!-r
  end;

symbolic procedure find!-alphas!-in!-a!-ring(n,mflist,fhatlist,gamma);
% Find the alphas (as below) given that the modulus may not be prime
% but is a prime power.
  begin scalar gg,m,ppow,i,gg!-mod!-p,modflist,wvec,alpha,alphazeros,w;
    if null prime!-base then errorf
      list("Prime base not set for finding alphas",
        current!-modulus,n,mflist);
    m:=set!-modulus prime!-base;
    modflist:= if m=prime!-base then mflist
      else for each fthing in mflist collect
        reduce!-mod!-p !*mod2f fthing;
    alphalist:=alphas(n,modflist,gamma);
    if m=prime!-base then <<
      set!-modulus m;
      return alphalist >>;
    i:=0;
    alphazeros:=mkvect n;
    wvec:=mkvect n;
    for each modfthing in modflist do <<
      putv(modfvec,i:=iadd1 i,modfthing);
      putv(alphavec,i,!*f2mod(alpha:=cdr get!-alpha modfthing));
      putv(alphazeros,i,alpha);
      putv(wvec,i,alpha);
      putv(fhatvec,i,car fhatlist);
      fhatlist:=cdr fhatlist >>;
    gg:=gamma;
    ppow:=prime!-base;
    while ppow<m do <<
      set!-modulus m;
      gg:=!*f2mod quotfail(!*mod2f difference!-mod!-p(gg,
          form!-sum!-and!-product!-mod!-m(wvec,fhatvec,n)),prime!-base);
      set!-modulus prime!-base;
      gg!-mod!-p:=reduce!-mod!-p !*mod2f gg;
      for k:=1:n do <<
        putv(wvec,k,w:=remainder!-mod!-p(
          times!-mod!-p(getv(alphazeros,k),gg!-mod!-p),
          getv(modfvec,k)));
        putv(alphavec,k,addf(getv(alphavec,k),multf(!*mod2f w,ppow)))>>;
      ppow:=ppow*prime!-base >>;
    set!-modulus m;
    i:=0;
    return (for each fthing in mflist collect
      (fthing . !*f2mod getv(alphavec,i:=iadd1 i)))
  end;

symbolic procedure alphas(n,flist,gamma);
% Finds alpha,beta,delta,... wrt factors f(i) in flist s.t.
%  alpha*g(1) + beta*g(2) + delta*g(3) + ... = gamma mod p,
% where g(i)=product(all the f(j) except f(i) itself).
% (cf. xgcd!-mod!-p below). n is number of factors in flist.
  if n=1 then list(car flist . gamma)
  else begin scalar k,w,f1,f2,i,gamma1,gamma2;
    k:=n/2;
    f1:=1; f2:=1;
    i:=1;
    for each f in flist do
    << if i>k then f2:=times!-mod!-p(f,f2)
       else f1:=times!-mod!-p(f,f1);
       i:=i+1 >>;
    w:=xgcd!-mod!-p(f1,f2,1,polyzero,polyzero,1);
    if atom w then
      return 'factors! not! coprime;
    gamma1:=remainder!-mod!-p(times!-mod!-p(cdr w,gamma),f1);
    gamma2:=remainder!-mod!-p(times!-mod!-p(car w,gamma),f2);
    i:=1; f1:=nil; f2:=nil;
    for each f in flist do
    << if i>k then f2:=f . f2
       else f1:=f . f1;
       i:=i+1 >>;
    return append(
      alphas(k,f1,gamma1),
      alphas(n-k,f2,gamma2))
  end;

symbolic procedure xgcd!-mod!-p(a,b,x1,y1,x2,y2);
% Finds alpha and beta s.t. alpha*a+beta*b=1.
% Returns alpha . beta or nil if a and b are not coprime.
    if null b then nil
    else if domainp b then begin
        b:=modular!-reciprocal b;
        x2:=multiply!-by!-constant!-mod!-p(x2,b);
        y2:=multiply!-by!-constant!-mod!-p(y2,b);
        return x2 . y2 end
    else begin scalar q;
        q:=quotient!-mod!-p(a,b); % Truncated quotient here.
        return xgcd!-mod!-p(b,difference!-mod!-p(a,times!-mod!-p(b,q)),
            x2,y2,
            difference!-mod!-p(x1,times!-mod!-p(x2,q)),
            difference!-mod!-p(y1,times!-mod!-p(y2,q)))
        end;

symbolic procedure hensel!-mod!-p(poly,mvec,fvec,cbd,vset,p);
% Hensel construction building up in powers of p.
% Given that poly=product(factors in factorvec) mod p, find the full
% factors over the integers.  Mvec contains the univariate factors mod p
% while fvec contains our best knowledge of the factors to date.
% Fvec includes leading coeffts (and in multivariate case possibly other
% coeffts) of the factors. return a list whose first element is a flag
% with one of the following values:
%  ok        construction worked, the cdr of the result is a list of
%            the correct factors.
%  failed    inputs must have been incorrect
%  overshot  factors are correct mod some power of p (say p**m),
%            but are not correct over the integers.
%            result is (overshot,p**m,list of factors so far).
  begin scalar w,u0,delfvec,old!.mod,res,m;
    u0:=initialize!-hensel(number!-of!-factors,p,poly,mvec,fvec,cbd);
            % u0 contains the product (over integers) of factors mod p.
    m := p;
    old!.mod := set!-modulus nil;
    if number!-of!-factors=1
      then <<putv(fvec,1,current!-factor!-product:=poly);
             % Added JHD 28.9.87
             return hensel!-exit(m,old!.mod,p,vset,w)>>;
            % only one factor to grow! but need to go this deep to
            % construct the alphas and set things up for the
            % multivariate growth which may follow.
    hensel!-msg1(p,u0);
    old!.mod:=set!-modulus p;
    res:=addf(hensel!-poly,negf u0);
            % calculate the residue. from now on this is always
            % kept in res.
    m:=p;
            % measure of how far we have built up factors - at this
            % stage we know the constant terms mod p in the factors.
   a: if polyzerop res then return hensel!-exit(m,old!.mod,p,vset,w);
      if (m/2)>coefftbd then
        <<
            % we started with a false split of the image so some
            % of the factors we have built up must amalgamate in
            % the complete factorization.
          if !*overshoot then <<
            prin2 if null vset then "Univariate " else "Multivariate ";
            prin2t "coefft bound overshoot" >>;
          if not !*overview then
        factor!-trace printstr "We have overshot the coefficient bound";
          return hensel!-exit(m,old!.mod,p,vset,'overshot)>>;
      res:=quotfail(res,deltam);
            % next term in residue.
      if not !*overview then factor!-trace <<
        prin2!* "Residue divided by "; prin2!* m; prin2!* " is ";
        printsf res >>;
      if (not !*linear) and null vset
        and m<=largest!-small!-modulus and m>p then
        quadratic!-step(m,number!-of!-factors);
      w:=reduce!-mod!-p res;
      if not !*overview then factor!-trace <<
          prin2!* "Next term in residue to kill is:";
          prinsf w; prin2!* " which is of size ";
          printsf (deltam*m);
          >>;
      solve!-for!-corrections(w,fhatvec,modfvec,delfvec,vset);
            % delfvec is vector of next correction terms to factors.
      make!-vec!-modular!-symmetric(delfvec,number!-of!-factors);
      if not !*overview then factor!-trace <<
        printstr "Correction terms are:";
        w:=1;
        for i:=1:number!-of!-factors do <<
          prin2!* "  To f("; prin2!* w; prin2!* "): ";
          printsf multf(m,getv(delfvec,i));
          w:=iadd1 w >>;
      >>;
      w:=terms!-done(factorvec,delfvec,m);
      res:=addf(res,negf w);
            % subtract out the terms generated by these corrections
            % from the residue.
      current!-factor!-product:=
         addf(current!-factor!-product,multf(m,w));
            % add in the correction terms to give new factor product.
      for i:=1:number!-of!-factors do
        putv(factorvec,i,
          addf(getv(factorvec,i),multf(getv(delfvec,i),m)));
            % add the corrections into the factors.
      if not !*overview then factor!-trace <<
        printstr "   giving new factors as:";
        w:=1;
        for i:=1:number!-of!-factors do <<
          prin2!* " f("; prin2!* w; prin2!* ")=";
          printsf getv(factorvec,i); w:=iadd1 w >>
        >>;
      m:=m*deltam;
      if not polyzerop res and null vset and
        not reconstructing!-gcd then
        begin scalar j,u,fac;
          j:=0;
          while (j:=j #+ 1)<=number!-of!-factors do
%            IF NULL GETV(DELFVEC,J) AND
            % - Try dividing out every time for now.
            if not didntgo
              (u:=quotf(hensel!-poly,fac:=getv(factorvec,j))) then <<
              hensel!-poly:=u;
              res:=adjust!-growth(fac,j,m);
              j:=number!-of!-factors >>
        end;
      go to a
  end;

symbolic procedure hensel!-exit(m,old!.mod,p,vset,w);
   begin
    if factors!-done then <<
      if not(w='overshot) then m:=p*p;
      set!-hensel!-fluids!-back p >>;
    if (not (w='overshot)) and null vset
      and (not !*linear) and multivariate!-input!-poly then
      while m<largest!-small!-modulus do <<
        if not(m=deltam) then quadratic!-step(m,number!-of!-factors);
        m:=m*deltam >>;
            % set up the alphas etc so that multivariate growth can
            % use a Hensel growth size of about word size.
    set!-modulus old!.mod;
            % reset the old modulus.
    hensel!-growth!-size:=deltam;
    putv(factorvec,0,number!-of!-factors);
    return
      if w='overshot then list('overshot,m,factorvec)
      else 'ok . factorvec
  end;

symbolic procedure hensel!-msg1(p,u0);
   begin scalar w;
    factor!-trace <<
      printstr
         "We are now ready to use the Hensel construction to grow";
      prin2!* "in powers of "; printstr current!-modulus;
      if not !*overview then <<prin2!* "Polynomial to factor (=U): ";
        printsf hensel!-poly>>;
      prin2!* "Initial factors mod "; prin2!* p;
      printstr " with some correct coefficients:";
      w:=1;
      for i:=1:number!-of!-factors do <<
        prin2!* " f("; prin2!* w; prin2!* ")=";
        printsf getv(factorvec,i); w:=iadd1 w >>;
      if not !*overview then << prin2!* "Coefficient bound = ";
        prin2!* coefftbd;
      terpri!*(nil);
      prin2!* "The product of factors over the integers is ";
      printsf u0;
      printstr "In each step below, the residue is U - (product of the";
      printstr
         "factors as far as we know them). The correction to each";
      printstr "factor, f(i), is (a(i)*v) mod f0(i) where f0(i) is";
      prin2!* "f(i) mod "; prin2!* p;
      printstr "(ie. the f(i) used in calculating the a(i))"
      >>>>
   end;

symbolic procedure initialize!-hensel(r,p,poly,mvec,fvec,cbd);
% Set up the vectors and initialize the fluids.
  begin scalar u0;
    delfvec:=mkvect r;
    facvec:=mkvect r;
    hensel!-poly:=poly;
    modfvec:=mvec;
    factorvec:=fvec;
    coefftbd:=cbd;
    factors!-done:=nil;
    deltam:=p;
    u0:=1;
    for i:=1:r do u0:=multf(getv(factorvec,i),u0);
    current!-factor!-product:=u0;
    return u0
  end;

% symbolic procedure reset!-quadratic!-step!-fluids(poly,faclist,n);
%   begin scalar i,om,modf;
%     current!-factor!-product:=poly;
%     om:=set!-modulus hensel!-growth!-size;
%     i:=0;
%     for each fac in faclist do <<
%       putv(factorvec,i:=iadd1 i,fac);
%       putv(modfvec,i,modf:=reduce!-mod!-p fac);
%       putv(alphavec,i,cdr get!-alpha modf) >>;
%      for i:=1:n do <<
%        prin2 "F("; % prin2 i; % prin2 ") = ";
%        printsf getv(factorvec,i);
%        prin2 "F("; % prin2 i; % prin2 ") MOD P = ";
%        printsf getv(modfvec,i);
%        prin2 "A("; % prin2 i; % prin2 ") = ";
%        printsf getv(alphavec,i) >>;
%     set!-modulus om
%   end;

symbolic procedure reset!-quadratic!-step!-fluids(poly,faclist,n);
  begin scalar i,om,facpairlist,cfp!-mod!-p,fhatlist;
    current!-factor!-product:=poly;
    om:=set!-modulus hensel!-growth!-size;
    cfp!-mod!-p:=reduce!-mod!-p current!-factor!-product;
    i:=0;
    facpairlist:=for each fac in faclist collect <<
      i:= i #+ 1;
      (fac . reduce!-mod!-p fac) >>;
    fhatlist:=for each facc in facpairlist collect
      quotfail!-mod!-p(cfp!-mod!-p,cdr facc);
    if factors!-done then alphalist:=
      find!-alphas!-in!-a!-ring(i,
        for each facpr in facpairlist collect cdr facpr,
        fhatlist,1);
          % a bug has surfaced such that the alphas get out of step.
          % In this case so recalculate them to stop the error for now.
    i:=0;
    for each facpair in facpairlist do <<
      putv(factorvec,i:=iadd1 i,car facpair);
      putv(modfvec,i,cdr facpair);
      putv(alphavec,i,cdr get!-alpha cdr facpair) >>;
%      for i:=1:n do <<
%        prin2 "f("; % prin2 i; % prin2 ") = ";
%        printsf getv(factorvec,i);
%        prin2 "f("; % prin2 i; % prin2 ") mod p = ";
%        printsf getv(modfvec,i);
%        prin2 "a("; % prin2 i; % prin2 ") = ";
%        printsf getv(alphavec,i) >>;
    set!-modulus om
  end;

symbolic procedure quadratic!-step(m,r);
% Code for adjusting the hensel variables to take quadratic steps in
% the growing process.
  begin scalar w,s,cfp!-mod!-p;
    set!-modulus m;
    cfp!-mod!-p:=reduce!-mod!-p current!-factor!-product;
    for i:=1:r do putv(facvec,i,reduce!-mod!-p getv(factorvec,i));
    for i:=1:r do putv(fhatvec,i,
      quotfail!-mod!-p(cfp!-mod!-p,getv(facvec,i)));
    w:=form!-sum!-and!-product!-mod!-m(alphavec,fhatvec,r);
    w:=!*mod2f plus!-mod!-p(1,minus!-mod!-p w);
    s:=quotfail(w,deltam);
    set!-modulus deltam;
    s:=!*f2mod s;
            % Boxes S up to look like a poly mod deltam.
    for i:=1:r do <<
      w:=remainder!-mod!-p(times!-mod!-p(s,getv(alphavec,i)),
        getv(modfvec,i));
      putv(alphavec,i,
        addf(!*mod2f getv(alphavec,i),multf(!*mod2f w,deltam))) >>;
    s:=modfvec;
    modfvec:=facvec;
    facvec:=s;
    deltam:=m;
            % this is our new growth rate.
    set!-modulus deltam;
    for i:=1:r do <<
      putv(facvec,i,"RUBBISH");
            % we will want to overwrite facvec next time so we
            % had better point it to the old (no longer needed)
            % modvec. Also mark it as containing rubbish for safety.
      putv(alphavec,i,!*f2mod getv(alphavec,i)) >>;
            % Make sure the alphas are boxed up as being mod new deltam.
    if not !*overview then factor!-trace <<
      printstr "The new modular polynomials are chosen such that:";
      terpri();
      prin2!* "   a(1)*h(1) + ... + a(";
      prin2!* r;
      prin2!* ")*h("; prin2!* r;
      prin2!* ") = 1 mod "; printstr m;
      terpri();
      printstr "  where h(i)=(product of all f(j) [see below])/f(i)";
      printstr "    and degree of a(i) < degree of f(i).";
      for i:=1:r do <<
        prin2!* "  a("; prin2!* i; prin2!* ")=";
        printsf getv(alphavec,i);
        prin2!* "   f("; prin2!* i; prin2!* ")=";
        printsf getv(modfvec,i) >>
    >>
  end;

symbolic procedure terms!-done(fvec,delfvec,m);
  begin scalar flist,delflist;
    for i:=1:number!-of!-factors do <<
      flist:=getv(fvec,i) . flist;
      delflist:=getv(delfvec,i) . delflist >>;
    return terms!.done(number!-of!-factors,flist,delflist,
                                 number!-of!-factors,m)
  end;

symbolic procedure terms!.done(n,flist,delflist,r,m);
  if n=1 then (car flist) . (car delflist)
  else begin scalar k,i,f1,f2,delf1,delf2;
    k:=n/2; i:=1;
    for each f in flist do
    << if i>k then f2:=(f . f2)
       else f1:=(f . f1);
       i:=i+1 >>;
    i:=1;
    for each delf in delflist do
    << if i>k then delf2:=(delf . delf2)
       else delf1:=(delf . delf1);
       i:=i+1 >>;
    f1:=terms!.done(k,f1,delf1,r,m);
    delf1:=cdr f1; f1:=car f1;
    f2:=terms!.done(n-k,f2,delf2,r,m);
    delf2:=cdr f2; f2:=car f2;
    delf1:=
      addf(addf(
        multf(f1,delf2),
        multf(f2,delf1)),
        multf(multf(delf1,m),delf2));
    if n=r then return delf1;
    return (multf(f1,f2) . delf1)
  end;

symbolic procedure try!.combining(l,poly,m,sofar);
  try!.combining1(l,poly,m,sofar,2);

% The following code is not optimal. If we find a combination of k
% factors, we will re-rty all the previous combinations of k factors
% already tried.
% This is not frightfully serious, since in practice most such
% combinations will have had something in common with the set found, and
% so won't re-appear.  This is definitely better than the previous
% version, which re-tried all combinations.  JHD 14.1.88.

symbolic procedure try!.combining1(l,poly,m,sofar,k);
% l is a list of factors, f(i), s.t. (product of the f(i) mod m) = poly
% but no f(i) divides poly over the integers.  We find the combinations
% of the f(i) that yield the true factors of poly over the integers.
% Sofar is a list of these factors found so far.
% start combining them K at a time
  if poly=1 then
    if null l then sofar
    else errorf(list("TOO MANY BAD FACTORS:",l))
  else begin scalar n,res,ff,v,w,w1,combined!.factors,ll,lcfinv,oldmod;
    n:=length l;
    if n=1 then
      if ldeg car l > (ldeg poly)/2 then
        return ('one! bad! factor . sofar)
      else errorf(list("ONE BAD FACTOR DOES NOT FIT:",l));
    if n=2 or n=3 then <<
      w:=lc cdar l; % The LC of all the factors is the same.
      while not (w=lc poly) do poly:=quotfail(poly,w);
            % poly's LC may be a higher power of w than we want
            % and we must return a result with the same
            % LC as each of the combined factors.
      if not !*overview then factor!-trace <<
        printstr "We combine:";
         for each lf in l do printsf cdr lf;
         prin2!* " mod "; prin2!* m;
         printstr " to give correct factor:";
         printsf poly >>;
       combine!.alphas(l,t);
       return (poly . sofar) >>;
    ll:=for each ff in l collect (cdr ff . car ff);
%    K := 2; % K is now an argument
    oldmod := set!-general!-modulus m;
    lcfinv := general!-modular!-reciprocal lc cdar l;
    set!-general!-modulus oldmod;
  loop1:
      if k > n/2 then go to exit;
      w:=koutof(k,if 2*k=n then cdr l else l,nil);
                   % We needn't try a combination and its complement
      while w and
            (v:=factor!-trialdiv(poly,car w,m,ll,lcfinv))='didntgo do
      << w:=cdr w;
        while w and
            ((car w = '!*lazyadjoin) or (car w = '!*lazykoutof)) do
          if car w= '!*lazyadjoin then
            w:=lazy!-adjoin(cadr w,caddr w,cadr cddr w)
          else w:=koutof(cadr w,caddr w,cadr cddr w)
        >>;
      if not(v='didntgo) then <<
        ff:=car v; v:=cdr v;
        if not !*overview then factor!-trace <<
          printstr "We combine:";
           for each a in car w do printsf a;
         prin2!* " mod "; prin2!* m;
         printstr " to give correct factor:";
         printsf ff >>;
       for each a in car w do <<
         w1:=l;
         while not (a = cdar w1) do w1:=cdr w1;
         combined!.factors:=car w1 . combined!.factors;
         l:=delete(car w1,l) >>;
       combine!.alphas(combined!.factors,t);
%      Now combine the rest, starting with k-tuples
       res:=try!.combining1(l,v,m,ff . sofar,k);
       go to exit>>;
    k := k + 1;
    go to loop1;
  exit:
    if res then return res
    else <<
      w:=lc cdar l; % The LC of all the factors is the same.
      while not (w=lc poly) do poly:=quotfail(poly,w);
            % poly's LC may be a higher power of w than we want
            % and we must return a result with the same
            % LC as each of the combined factors.
      if not !*overview then factor!-trace <<
        printstr "We combine:";
          for each ff in l do printsf cdr ff;
          prin2!* " mod "; prin2!* m;
          printstr " to give correct factor:";
          printsf poly >>;
      combine!.alphas(l,t);
      return (poly . sofar) >>
  end;

symbolic procedure koutof(k,l,sofar);
% Produces all permutations of length k from list l accumulating them
% in sofar as we go.  We use lazy evaluation in that this results in
% a permutation dotted with:
%   ( '!*lazy . (argument for eval) )
%  except when k=1 when the permutations are explicitly given.
  if k=1 then append(
    for each f in l collect list cdr f,sofar)
  else if k>length l then sofar
  else <<
    while eqcar(l,'!*lazyadjoin) or eqcar(l,'!*lazykoutof) do
      if car l='!*lazyadjoin then
        l := lazy!-adjoin(cadr l,caddr l,cadr cddr l)
      else l := koutof(cadr l,caddr l,cadr cddr l);
    if k=length l then
      (for each ll in l collect cdr ll ) . sofar
    else koutof(k,cdr l,
      list('!*lazyadjoin,cdar l,
        list('!*lazykoutof,(k-1),cdr l,nil),
         sofar)) >>;

symbolic procedure lazy!-adjoin(item,l,tail);
% Dots item with each element in l using lazy evaluation on l.
% If l is null tail results.
 << while eqcar(l,'!*lazyadjoin) or eqcar(l,'!*lazykoutof) do
      if car l ='!*lazyadjoin then
        l:=lazy!-adjoin(cadr l,caddr l,cadr cddr l)
      else l:=koutof(cadr l,caddr l,cadr cddr l);
    if null l then tail
    else (item . car l) .
     if null cdr l then tail
     else list('!*lazyadjoin,item,cdr l,tail) >>;

symbolic procedure factor!-trialdiv(poly,flist,m,llist,lcfinv);
% Combines the factors in FLIST mod M and test divides the result
% into POLY (over integers) to see if it goes. If it doesn't
% then DIDNTGO is returned, else the pair (D . Q) is
% returned where Q is the quotient obtained and D is the product
% of the factors mod M;
% Abbott,J.A., Bradford,R.J. & Davenport,J.H.,
% A Remark on Factorisation.
% SIGSAM Bulletin 19(1985) 2, pp. 31-33, 37.
  if polyzerop poly then errorf "Test dividing into zero?"
  else begin scalar d,q,tcpoly,tcoeff,x,oldmod,w,poly1,try1;
    factor!-trace <<
      prin2!* "We combine factors ";
      for each ff in flist do <<
        w:=assoc(ff,llist);
        prin2!* "f(";
        prin2!* cdr w;
        prin2!* "), " >> ;
      prin2!* "and try dividing : " >>;
    x := mvar poly;
    tcpoly :=trailing!.coefft(poly,x);
    tcoeff := trailing!.coefft(car flist,x);
    oldmod := set!-general!-modulus m;
    for each fac in cdr flist do
      tcoeff := general!-modular!-times(
                  general!-modular!-times(tcoeff,lcfinv),
                                        trailing!.coefft(fac,x));
    if not zerop remainder(tcpoly,
              w:=general!-make!-modular!-symmetric tcoeff) then <<
      factor!-trace printstr " it didn't go (tc test)";
      set!-general!-modulus oldmod;
%      if not(w = trailing!.coefft(car COMBINE(FLIST,M,LLIST,lcfinv),x))
%             then <<
%         printstr "incompatibility: we have";
%         prin2!* w;
%         printstr "which should be the trailing coefficient of:";
%         prin2!* car combine(flist,m,llist,lcfinv) >>;
      return 'didntgo >>;
  % it has passed the tc test - now try evaluating at 1;
    poly1 := eval!-at!-1 poly;
    try1 := eval!-at!-1 car flist;
    for each fac in cdr flist do
      try1 := general!-modular!-times(
                general!-modular!-times(try1,lcfinv),eval!-at!-1 fac);
    if (zerop try1 and not zerop poly1) or
       not zerop remainder(poly1,general!-make!-modular!-symmetric try1)
         then <<
          factor!-trace printstr " it didn't go (test at 1)";
          set!-general!-modulus oldmod;
          return 'didntgo >>;
  % it has passed both tests - work out longhand;
    set!-general!-modulus oldmod;
    d:=combine(flist,m,llist,lcfinv);
    if didntgo(q:=quotf(poly,car d)) then <<
      factor!-trace printstr " it didn't go (division fail)";
      return 'didntgo >>
    else <<
      factor!-trace printstr " it worked !";
      return (car d . quotf(q,cdr d)) >>
  end;

symbolic procedure eval!-at!-1 f;
  % f a univariate standard form over Z with f(0) neq 0;
  % return the integer f(1);
  if atom f then f else (lc f) + eval!-at!-1(red f);

symbolic procedure combine(flist,m,l,lcfinv);
% Multiply factors in flist mod m.
% L is a list of the factors for use in FACTOR!-TRACE.
  begin scalar om,res,lcf,lcfprod;
    lcf := lc car flist; % all leading coeffts should be the same.
    lcfprod := 1;
% This is one of only two places in the entire factorizer where
% it is ever necessary to use a modulus larger than word-size.
    if m>largest!-small!-modulus then <<
      om:=set!-general!-modulus m;
%      lcfinv := general!-modular!-reciprocal lcf; Done once and for all
      res:=general!-reduce!-mod!-p car flist;
      for each ff in cdr flist do <<
        if not lcf=lc ff then errorf "BAD LC IN FLIST";
        res:=general!-times!-mod!-p(
            general!-times!-mod!-p(lcfinv,
                general!-reduce!-mod!-p ff),res);
        lcfprod := lcfprod*lcf >>;
      res:=general!-make!-modular!-symmetric res;
      set!-modulus om;
      return (res . lcfprod) >>
    else <<
      om:=set!-modulus m;
      lcfinv := modular!-reciprocal lcf;
      res:=reduce!-mod!-p car flist;
      for each ff in cdr flist do <<
        if not lcf=lc ff then errorf "BAD LC IN FLIST";
        res:=times!-mod!-p(times!-mod!-p(lcfinv,reduce!-mod!-p ff),res);
        lcfprod := lcfprod*lcf >>;
      res:=make!-modular!-symmetric res;
      set!-modulus om;
      return (res . lcfprod) >>
  end;

symbolic procedure combine!.alphas(flist,fixlcs);
% Combine the alphas associated with each of these factors to
% give the one alpha for their combination.
  begin scalar f1,a1,ff,aa,oldm,lcfac,lcfinv,saveflist;
    oldm:=set!-modulus hensel!-growth!-size;
    flist:=for each fac in flist collect <<
      saveflist:= (reduce!-mod!-p cdr fac) . saveflist;
      (car fac) . car saveflist >>;
    if fixlcs then <<
        lcfinv:=modular!-reciprocal lc cdar flist;
        lcfac:=modular!-expt(lc cdar flist,sub1 length flist)
      >>
      else << lcfinv:=1; lcfac:=1 >>;
            % If FIXLCS is set then we have combined n factors
            % (each with the same l.c.) to give one and we only need one
            % l.c. in the result, we have divided the combination by
            % lc**(n-1) and we must be sure to do the same for the
            % alphas.
    ff:=cdar flist;
    aa:=cdr get!-alpha ff;
    flist:=cdr flist;
    while flist do <<
      f1:=cdar flist;
      a1:=cdr get!-alpha f1;
      flist:=cdr flist;
      aa:=plus!-mod!-p(times!-mod!-p(aa,f1),times!-mod!-p(a1,ff));
      ff:=times!-mod!-p(ff,f1)
    >>;
    for each a in alphalist do
      if not member(car a,saveflist) then
        flist:=(car a . times!-mod!-p(cdr a,lcfac)) . flist;
    alphalist:=(quotient!-mod!-p(ff, lcfac) . aa) . flist;
    set!-modulus oldm
  end;

% The following code is for dividing out factors in the middle
% of the Hensel construction and adjusting all the associated
% variables that go with it.


symbolic procedure adjust!-growth(facdone,k,m);
% One factor (at least) divides out so we can reconfigure the
% problem for Hensel constrn giving a smaller growth and hopefully
% reducing the coefficient bound considerably.
  begin scalar w,u,bound!-scale,modflist,factorlist,fhatlist,
        modfdone,b;
    factorlist:=vec2list!-without!-k(factorvec,k);
    modflist:=vec2list!-without!-k(modfvec,k);
    fhatlist:=vec2list!-without!-k(fhatvec,k);
    w:=number!-of!-factors;
    modfdone:=getv(modfvec,k);
top:
    factors!-done:=facdone . factors!-done;
    if (number!-of!-factors:=number!-of!-factors #- 1)=1 then <<
      factors!-done:=hensel!-poly . factors!-done;
      number!-of!-factors:=0;
      hensel!-poly:=1;
      if not !*overview then factor!-trace <<
        printstr "    All factors found:";
        for each fd in factors!-done do printsf fd >>;
      return polyzero >>;
    fhatlist:=for each fhat in fhatlist collect
      quotfail!-mod!-p(if null fhat then polyzero else fhat,modfdone);
    u:=comfac facdone;  % Take contents and prim. parts.
    if car u then
      errorf(list("Factor divisible by main variable: ",facdone,car u));
    facdone:=quotfail(facdone,cdr u);
    bound!-scale:=cdr u;
    if not((b:=lc facdone)=1) then begin scalar b!-inv,old!-m;
      hensel!-poly:=quotfail(hensel!-poly,b**number!-of!-factors);
      b!-inv:=modular!-reciprocal modular!-number b;
      modflist:=for each modf in modflist collect
        times!-mod!-p(b!-inv,modf);
% This is one of only two places in the entire factorizer where
% it is ever necessary to use a modulus larger than word-size.
      if m>largest!-small!-modulus then <<
        old!-m:=set!-general!-modulus m;
        factorlist:=for each facc in factorlist collect
          adjoin!-term(lpow facc,quotfail(lc facc,b),
            general!-make!-modular!-symmetric(
              general!-times!-mod!-p(
            general!-modular!-reciprocal general!-modular!-number b,
                            general!-reduce!-mod!-p red facc))) >>
      else <<
        old!-m:=set!-modulus m;
        factorlist:=for each facc in factorlist collect
          adjoin!-term(lpow facc,quotfail(lc facc,b),
            make!-modular!-symmetric(
              times!-mod!-p(modular!-reciprocal modular!-number b,
                            reduce!-mod!-p red facc))) >>;
            % We must be careful not to destroy the information
            % that we have about the leading coefft.
      set!-modulus old!-m;
      fhatlist:=for each fhat in fhatlist collect
        times!-mod!-p(
          modular!-expt(b!-inv,number!-of!-factors #- 1),fhat)
    end;
try!-another!-factor:
    if (w:=w #- 1)>0 then
      if not didntgo
        (u:=quotf(hensel!-poly,facdone:=car factorlist)) then <<
        hensel!-poly:=u;
        factorlist:=cdr factorlist;
        modfdone:=car modflist;
        modflist:=cdr modflist;
        fhatlist:=cdr fhatlist;
        goto top >>
      else <<
        factorlist:=append(cdr factorlist,list car factorlist);
        modflist:=append(cdr modflist,list car modflist);
        fhatlist:=append(cdr fhatlist,list car fhatlist);
        goto try!-another!-factor >>;
    set!-fluids!-for!-newhensel(factorlist,fhatlist,modflist);
    bound!-scale:=
      bound!-scale * get!-coefft!-bound(
        quotfail(hensel!-poly,bound!-scale**(number!-of!-factors #- 1)),
        ldeg hensel!-poly);
    % We expect the new coefficient bound to be smaller, but on
    % dividing out a factor our polynomial's height may have grown
    % more than enough to compensate in the bound formula for
    % the drop in degree. Anyway, the bound we computed last time
    % will still be valid, so let's stick with the smaller.
    if bound!-scale < coefftbd then coefftbd := bound!-scale;
    w:=quotfail(addf(hensel!-poly,negf current!-factor!-product),
          m/deltam);
    if not !*overview then factor!-trace <<
      printstr "    Factors found to be correct:";
      for each fd in factors!-done do
        printsf fd;
      printstr "Remaining factors are:";
      printvec("    f(",number!-of!-factors,") = ",factorvec);
      prin2!* "New coefficient bound is "; printstr coefftbd;
      prin2!* " and the residue is now "; printsf w >>;
    return w
  end;

symbolic procedure vec2list!-without!-k(v,k);
% Turn a vector into a list leaving out Kth element.
  begin scalar w;
    for i:=1:number!-of!-factors do
      if not(i=k) then w:=getv(v,i) . w;
    return w
  end;

symbolic procedure set!-fluids!-for!-newhensel(flist,fhatlist,modflist);
<< current!-factor!-product:=1;
  alphalist:=
    find!-alphas!-in!-a!-ring(number!-of!-factors,modflist,fhatlist,1);
  for i:=number!-of!-factors step -1 until 1 do <<
    putv(factorvec,i,car flist);
    putv(modfvec,i,car modflist);
    putv(fhatvec,i,car fhatlist);
    putv(alphavec,i,cdr get!-alpha car modflist);
    current!-factor!-product:=multf(car flist,current!-factor!-product);
    flist:=cdr flist;
    modflist:=cdr modflist;
    fhatlist:=cdr fhatlist >>
>>;

symbolic procedure set!-hensel!-fluids!-back p;
% After the Hensel growth we must be careful to set back any fluids
% that have been changed when we divided out a factor in the middle
% of growing.  Since calculating the alphas involves modular division
% we cannot do it mod DELTAM which is generally a non-trivial power of
% P (prime). So we calculate them mod P and if necessary we can do a
% few quadratic growth steps later.
  begin scalar n,fd,modflist,fullf,modf;
    set!-modulus p;
    deltam:=p;
    n:=number!-of!-factors #+ length (fd:=factors!-done);
    current!-factor!-product:=hensel!-poly;
    for i:=(number!-of!-factors #+ 1):n do <<
      putv(factorvec,i,fullf:=car fd);
      putv(modfvec,i,modf:=reduce!-mod!-p fullf);
      current!-factor!-product:=multf(fullf,current!-factor!-product);
      modflist:=modf . modflist;
      fd:=cdr fd >>;
    for i:=1:number!-of!-factors do <<
      modf:=reduce!-mod!-p !*mod2f getv(modfvec,i);
            % need to 'unbox' a modpoly before reducing it mod p as we
            % know that the input modpoly is wrt a larger modulus
            % (otherwise this would be a stupid thing to do anyway!)
            % and so we are just pretending it is a full poly.
      modflist:=modf . modflist;
      putv(modfvec,i,modf) >>;
    alphalist:=alphas(n,modflist,1);
    for i:=1:n do putv(alphavec,i,cdr get!-alpha getv(modfvec,i));
    number!-of!-factors:=n
  end;

endmodule;


end;
