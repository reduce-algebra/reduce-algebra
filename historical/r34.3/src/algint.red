module algint; % Header for REDUCE algebraic integration package.

% Authors: J. Davenport and A. C. Hearn.

create!-package('(algint afactor algfn antisubs coates coatesid findmagc
                  findres finitise fixsubf fracdi genus intbasis jhddiff
                  jhdriver linrel log2atan maninp modify modlineq nagell
                  nbasis places precoats removecm sqfrnorm substns
                  inttaylor torsionb wstrass zmodule),
                  % algnums hidden phantoms primes
                '(int alg));

% Other packages needed.

load!-package 'int;

% Various functions used in the algebraic integrator.

symbolic smacro procedure divsf(u,v); sqrt2top(u ./ v);

symbolic smacro procedure maninp(u,v,w);
   interr "MANINP called -- not implemented in this version";

symbolic smacro procedure readclock; time();

symbolic procedure superprint u; prettyprint u;


% Various selectors written as macros.

symbolic smacro procedure argof u;
   % Argument of a unary function.
   cadr u;

symbolic smacro procedure lsubs u; car u;

symbolic smacro procedure rsubs u; cdr u;

symbolic smacro procedure lfirstsubs u; caar u;

symbolic smacro procedure rfirstsubs u; cdar u;


% Selectors for the Taylor series structure.

% Format is:
%function.((first.last computed so far) . assoc list of computed terms).

% ***store-hack-1***:
% remove this macro if more store is available.

symbolic smacro procedure tayshorten u; nil;

symbolic smacro procedure taylordefn u; car u;

symbolic smacro procedure taylorfunction u; caar u;

symbolic smacro procedure taylornumbers u; cadr u;

symbolic smacro procedure taylorfirst u; caadr u;

symbolic smacro procedure taylorlast u; cdadr u;

symbolic smacro procedure taylorlist u; cddr u;

symbolic smacro procedure taylormake(fn,nums,alist);
   fn . (nums . alist);

endmodule;


module afactor;

% Author: James H. Davenport.

fluid '(!*galois !*noextend !*sqfree !*trfield afactorvar listofnewsqrts
        monicpart varlist zlist sqrtlist sqrtflag indexlist);

switch trfield;   % traces the algebraic number field manipluation

exports afactor, jfactor;
imports exptf,ordop,!*multf,addf,makemainvar,algebraicsf,divsf,contents;
imports quotf!*,negf,sqfr!-norm2,prepf,algint!-subf,!*q2f;
imports printsf;

% internal!-fluid '(monicpart);

% This routine, and its subsidiaries, do factorization over algebraic
% extensions, by the Trager modification of van der Waerden's algorithm
% See SYMSAC '76.

symbolic procedure afactor(u,v);
  % Factorises U over the algebraics as a polynomial in V (=afactorvar).
begin
  scalar afactorvar,!*noextend,!*sqfree;
  % !*sqfree is known to be square free (from sqfr-norm).
  !*noextend:=t; % else we get recursion.
  afactorvar:=v;
  if !*trfield
    then <<
    princ "We must factorise the following over: ";
    for each u in listofnewsqrts do <<princ u; princ " " >>;
    terpri();
    printsf u >>;
  v:=algfactor u;
  if !*trfield then <<
    printc "factorizes as ";
    mapc(v,function printsf) >>;
  return v
  end;


symbolic procedure algfactor2(f,a);
if null a
  then for each u in cdr factorf f collect %car factorf is a constant
    if cdr u = 1
      then car u
      else interr "repeated factors found while processing algebraics"
  else if algebraicsf f
    then algfactor3(f,a)
    else begin
      scalar w;
      if !*trfield then <<
        princ "to be factorized over ";
        for each u in a do << princ u; princ " " >>;
        terpri();
        printsf f >>;
      if  (!*galois neq 2) and
          (numberp red f) and
          (not numberp argof car a)
        then return algfactor2(f,cdr a);
        % assumes we need never express a root of a number in terms of
        % non-numbers.
      w:=algfactor2(f,nil);
      if w and null cdr w then return algfactor3(f,a)
        else return 'partial . w
      end;


symbolic procedure algfactor3(f,a);
begin
  scalar ff,w,gg,h,p;
  w:=sqfr!-norm2(f,mvar f,car a);
  !*sqfree:=car w;
  w:=cdr w;
  ff:=algfactor2(!*sqfree,cdr a);
  if null ff then return list f         % does not factor.
   else if car ff eq 'partial then <<p := 'partial; ff := cdr ff>>;
  if null cdr ff then return list f;    % does not factor.
  a:=car a;
  gg:=cadr w;
  w:=list list(afactorvar,'plus,afactorvar,prepf car w);
  h:=for each u in ff
       collect (!*q2f algint!-subf(gcdinonevar(u,gg,afactorvar),w));
  if p eq 'partial then h := p.h;
  return h
  end;

symbolic procedure algfactor u;
begin
  scalar a,aa,z,w,monicpart;
  z:= makemainvar(u,afactorvar);
  if ldeg z iequal 1
    then return list u;
  z:=lc z;
  if z iequal 1
    then go to monic;
  if algebraicsf z
    then u:=!*multf(u,numr divsf(1,z));
    % this de-algebraicises the top coefficient.
  u:=quotf!*(u,contents(u,afactorvar));
  z:=makemainvar(u,afactorvar);
  if lc z neq 1
    then if lc z iequal -1
      then u:=negf u
      else <<
        w:=lc z;
        u:=makemonic z >>;
monic:
  aa:=listofnewsqrts;
  if algebraicsf u
    then go to normal;
  a:=cdr aa;
  % we need not try for the first one, since algfactor2
  % will do this for us.
  z:=t;
  while a and z do begin
    scalar alg,v;
    alg:=car a;
    a:=cdr a;
    v:=algfactor3(u,list alg);
    if null cdr v
      then return;
    if car v eq 'partial
      then v:=cdr v;
      % we do not mind if the factorization is only partial.
    a:=mapcan(v,function algfactor);
    z:=nil
    end;
  monicpart:=w;
  if null z
    then if null w
      then return a
      else return mapcar(a,function demonise);
normal:
  z:=algfactor2(u,aa);
  monicpart:=w;
  if null cdr z or (car z neq 'partial)
    then if null w
      then return z
      else return mapcar(z,function demonise);
  % does not factor.
  if null w
    then return mapcan(cdr z,function algfactor)
    else return for each u in z conc
                  algfactor demonise u;
  end;


symbolic procedure demonise u;
% Replaces afactorvar by afactorvar*monicpart in u.
if atom u
  then u
  else if afactorvar eq mvar u
    then addf(demonise red u,
              !*multf(lt u .+ nil,exptf(monicpart,ldeg u)))
    else if ordop(afactorvar,mvar u)
      then u
      else addf(demonise red u,
                !*multf(!*p2f lpow u,demonise lc u));

symbolic procedure gcdinonevar(u,v,x);
% Gcd of u and v, regarded as polynomials in x.
if null u
  then v
  else if null v
    then u
    else begin
      scalar u1,v1,z,w;
      u1:=stt(u,x);
      v1:=stt(v,x);
    loop:
      if (car u1) > (car v1)
        then go to ok;
      z:=u1;u1:=v1;v1:=z;
      z:=u;u:=v;v:=z;
    ok:
      if car v1 iequal 0
        then interr "Coprimeness in gcd";
      z:=gcdf(cdr u1,cdr v1);
      w:=quotf(cdr u1,z);
      if (car u1) neq (car v1)
        then w:=!*multf(w,!*p2f mksp(x,(car u1)-(car v1)));
      u:=addf(!*multf(v,w),
              !*multf(u,negf quotf(cdr v1,z)));
      if null u
        then return v;
      u1:=stt(u,x);
      go to loop
      end;

symbolic procedure makemonic u;
% U is a makemainvar'd polynomial.
begin
  scalar v,w,x,xx;
  v:=mvar u;
  x:=lc u;
  xx:=1;
  w:=!*p2f lpow u;% the monic term.
  u:=red u;
  for i:=(isub1 ldeg w) step -1 until 1 do begin
    if atom u
      then go to next;
    if mvar u neq v
      then go to next;
    if ldeg u iequal i
      then w:=addf(w,!*multf(lc u,
                     !*multf(!*p2f lpow u,xx)));
    u:=red u;
  next:
    xx:=!*multf(x,xx)
    end;
  w:=addf(w,!*multf(u,xx));
  return w
  end;

symbolic procedure jfactor(sf,var);
   % Algebraic integrator's sole interface to factorization.
   % except for a direct call to the true factoriser from
   % inside afactor
begin
  scalar varlist,zlist,indexlist,sqrtlist,sqrtflag;
  scalar prim,res,answer,u,v,x,y; % scalar var2
  prim:=jsqfree(sf,var);
  indexlist:=createindices zlist;
  while not null prim do <<
    x:=car prim;
    while not null x do <<
        y:=facbypp(car x,varlist);
        while not null y do <<
            res:=append(int!-fac car y,res);
            y:=cdr y >>;
        x:=cdr x >>;
    prim:=cdr prim >>;
  while res do <<
    if caar res eq 'log then <<
        u:=cdar res;
        u:=!*multsq(numr u ./ 1,1 ./ cdr stt(numr u,var));
        v:=denr u;
        while not atom v do v:=lc v;
        if  (numberp v) and (0> v)
          then u:=(negf numr u) ./ (negf denr u);
        if u neq '(1 . 1) then answer := u . answer>>
      else if caar res eq 'atan then nil
      % We can ignore this, since we also get LOG (U**2+1) as another
      % term.
      else interr "Unexpected term in jfactor";
    res:=cdr res >>;
  return answer
  end;

% unfluid '(monicpart);

endmodule;


module algfn;

% Author: James H. Davenport.

% Check if an expression is in a pure algebraic extension of
% Q(all "constants")(var).


exports algfnpl,algebraicsf;

imports simp,interr,dependsp,dependspl;

symbolic procedure algfnp(pf,var);
   if atom pf then t
    else if not atom car pf then interr "Not prefix form"
    else if car pf eq '!*sq then algfnsq(cadr pf,var)
      else if car pf eq 'expt
       then if not algint!-ratnump caddr pf
              then (not dependsp(cadr pf,var))
                and (not dependsp(caddr pf,var))
             else algfnp(cadr pf,var)
    else if not memq(car pf,'(minus plus times quotient sqrt))
           % JPff fiddle
     then not dependspl(cdr pf,var)
    else algfnpl(cdr pf,var);

symbolic procedure algfnpl(p!-list,var);
   null p!-list or algfnp(car p!-list,var) and algfnpl(cdr p!-list,var);

symbolic procedure algfnsq(sq,var);
   algfnsf(numr sq,var) and algfnsf(denr sq,var);

symbolic procedure algfnsf(sf,var);
   atom sf
 or algfnp(mvar sf,var) and algfnsf(lc sf,var) and algfnsf(red sf,var);

symbolic procedure algint!-ratnump q;
   if atom q then numberp q
    else car q eq 'quotient and (numberp cadr q) and (numberp caddr q);

symbolic procedure algebraicsf u;
   if atom u then nil
    else algebraicp mvar u or algebraicsf lc u or algebraicsf red u;

symbolic procedure algebraicp u;
   if atom u then nil
    else if car u eq 'expt then 1 neq denr simp caddr u
    else car u eq 'sqrt;

endmodule;


module antisubs;

% Author: James H. Davenport.

exports antisubs;

imports interr,dependsp,setdiff;


symbolic procedure antisubs(place,x);
% Produces the inverse substitution to a substitution list.
begin
  scalar answer,w;
  while place and
        (x=caar place) do<<
    w:=cdar place;
    % w is the substitution rule.
    if atom w
      then if w neq x
        then interr "False atomic substitution"
        else nil
      else answer:=(x.anti2(w,x)).answer;
    place:=cdr place>>;
  if null answer
    then answer:=(x.x).answer;
  return answer
  end;


symbolic procedure anti2(eexpr,x);
%Produces the function inverse to the eexpr provided.
if atom eexpr
  then if eexpr eq x
    then x
    else interr "False atom"
  else if car eexpr eq 'plus
    then deplus(cdr eexpr,x)
    else if car eexpr eq 'minus
      then subst(list('minus,x),x,anti2(cadr eexpr,x))
      else if car eexpr eq 'quotient
        then if dependsp(cadr eexpr,x)
          then if dependsp(caddr eexpr,x)
            then interr "Complicated division"
            else subst(list('times,caddr eexpr,x),x,anti2(cadr eexpr,x))
          else if dependsp(caddr eexpr,x)
            then subst(list('quotient,cadr eexpr,x),x,
                       anti2(caddr eexpr,x))
            else interr "No division"
        else if car eexpr eq 'expt
          then if caddr eexpr iequal 2
            then subst(list('sqrt,x),x,anti2(cadr eexpr,x))
            else interr "Unknown root"
          else if car eexpr eq 'times
            then detimes(cdr eexpr,x)
            else if car eexpr eq 'difference
              then deplus(list(cadr eexpr,list('minus,caddr eexpr)),x)
              else interr "Unrecognised form in antisubs";



symbolic procedure detimes(p!-list,var);
% Copes with lists 'times.
begin
  scalar u,v;
  u:=deplist(p!-list,var);
  v:=setdiff(p!-list,u);
  if null v
    then v:=var
    else if null cdr v
      then v:=list('quotient,var,car v)
      else v:=list('quotient,var,'times.v);
  if (null u) or
     (cdr u)
    then interr "Weird multiplication";
  return subst(v,var,anti2(car u,var))
  end;


symbolic procedure deplist(p!-list,var);
% Returns a list of those elements of p!-list which depend on var.
if null p!-list
  then nil
  else if dependsp(car p!-list,var)
    then (car p!-list).deplist(cdr p!-list,var)
    else deplist(cdr p!-list,var);


symbolic procedure deplus(p!-list,var);
% Copes with lists 'plus.
begin
  scalar u,v;
  u:=deplist(p!-list,var);
  v:=setdiff(p!-list,u);
  if null v
    then v=var
    else if null cdr v
      then v:=list('plus,var,list('minus,car v))
      else v:=list('plus,var,list('minus,'plus.v));
  if (null u) or
     (cdr u)
    then interr "Weird addition";
  return subst(v,var,anti2(car u,var))
  end;

endmodule;


module coates;

% Author: James H. Davenport.

fluid '(!*tra !*trmin !*galois intvar magiclist nestedsqrts
        previousbasis sqrt!-intvar taylorasslist thisplace
        listofallsqrts listofnewsqrts basic!-listofallsqrts
        basic!-listofnewsqrts gaussiani !*trfield);

global '(coates!-fdi);

exports coates,makeinitialbasis,checkpoles,multbyallcombinations;


symbolic procedure coates(places,mults,x);
begin
  scalar u,tt;
  tt:=readclock();
  u:=coates!-hpfsd(places,mults);
  if !*tra or !*trmin then
    printc  list ('coates,'time,readclock()-tt,'milliseconds);
  return u
  end;


symbolic procedure coates!-real(places,mults);
begin
  scalar thisplace,u,v,save;
  if !*tra or !*trmin then <<
    princ "Find function with zeros of order:";
    printc mults;
    if !*tra then
      princ " at ";
    terpri!*(t);
    if !*tra then
      mapc(places,function printplace) >>;
%  v:=placesindiv places;
    % V is a list of all the substitutors in PLACES;
%  u:=mkunique sqrtsintree(v,intvar,nil);
%  if !*tra then <<
%    princ "Sqrts on this curve:";
%    terpri!*(t);
%    superprint u >>;
%  algnos:=mkunique mapcar(places,function basicplace);
%  if !*tra then <<
%    printc "Algebraic numbers where residues occur:";
%    superprint algnos >>;
  v:=mults;
  for each uu in places do <<
    if (car v) < 0
      then u:=(rfirstsubs uu).u;
    v:=cdr v >>;
  thisplace:=list('quotient,1,intvar);
  if member(thisplace,u)
    then <<
      v:= finitise(places,mults);
      % returns list (places,mults,power of intvar to remove.
      u:=coates!-real(car v,cadr v);
      if atom u
        then return u;
      return multsq(u,!*p2q mksp(intvar,caddr v)) >>;
% It is not sufficient to check the current value of U in FRACTIONAL...
% as we could have zeros over infinity JHD 18/8/86;
  for each uu in places do
    if rfirstsubs uu = thisplace
      then u:=append(u,mapcar(cdr uu,function car));
  coates!-fdi:=fractional!-degree!-at!-infinity u;
% Do we need to blow everything up by a factor of two (or more)
% to avoid fractional powers at infinity?
  if coates!-fdi iequal 1
    then return coatesmodule(places,mults,intvar);
  if !*tra
    then fdi!-print();
  newplace list(intvar . thisplace,
                list(intvar,'expt,intvar,coates!-fdi));
  places:=mapcar(places,function fdi!-upgrade);
  save:=taylorasslist;
  u:=coatesmodule(places,
    mapcar(mults,function (lambda u;u*coates!-fdi)),
                  intvar);
  taylorasslist:=save;
% u:=fdi!-revertsq u;
% That previous line is junk, I think (JHD 22.8.86)
% just because we blew up the places doesn't mean that
% we should deflate the function, because that has already been done.
  return u
  end;



symbolic procedure coatesmodule(places,mults,x);
begin
  scalar pzero,mzero,u,v,basis,sqrts,magiclist,mpole,ppole;
    % MAGICLIST holds the list of extra unknowns created in JHDSOLVE
    % which must be found in CHECKPOLES (calling FINDMAGIC).
  sqrts:=sqrtsinplaces places;
  if !*tra then <<
    princ "Sqrts on this curve:";
    superprint sqrts >>;
  u:=places;
  v:=mults;
  while u do <<
    if 0<car v
      then <<
        mzero:=(car v).mzero;
        pzero:=(car u).pzero >>
      else <<
        mpole:=(car v).mpole;
        ppole:=(car u).ppole >>;
    u:=cdr u;
    v:=cdr v >>;
  % ***time-hack-2***;
  if previousbasis then basis:=previousbasis
    else basis:=mkvec makeinitialbasis ppole;
  u:=completeplaces(ppole,mpole);
  basis:=integralbasis(basis,car u,cdr u,x);
  basis:=normalbasis(basis,x,0);
  u:=coatessolve(mzero,pzero,basis,nil);
    % The NIL is the list of special constraints needed
    % to force certain poles to occur in the answer.
  if atom u
    then return u;
  v:= checkpoles(list u,places,mults);
  if null v
    then return 'failed;
  if not magiclist
    then return u;
  u:=removecmsq substitutesq(u,v);
  % Apply the values from FINDMAGIC.
  if !*tra or !*trmin then <<
    printc "These values give the function";
    printsq u >>;
  magiclist:=nil;
  if checkpoles(list u,places,mults)
    then return u
    else interr "Inconsistent checkpoles"
  end;



symbolic procedure makeinitialbasis places;
begin
  scalar u;
  u:=multbyallcombinations(list(1 ./ 1),
                           for each u in getsqrtsfromplaces places
         collect !*kk2q u);
  if !*tra then <<
    printc "Initial basis for the space m(x)";
    mapc(u,function printsq) >>;
  return u
  end;

symbolic procedure multbyallcombinations(u,l);
% Produces a list of all elements of u,
% each multiplied by every combination of elements of l.
if null l
  then u
  else multbyallcombinations(nconc(multsql(car l,u),u),cdr l);

symbolic procedure multsql(u,l);
   % Multiplies (!*multsq) each element of l by u.
   if null l then nil else !*multsq(u,car l) . multsql(u,cdr l);

symbolic procedure checkpoles(basis,places,mults);
% Checks that the BASIS really does have all the
%  poles in (PLACES.MULTS).
begin
  scalar u,v,l;
  go to outer2;
outer:
  places:=cdr places;
  mults:=cdr mults;
outer2:
  if null places
    then return if magiclist
                  then findmagic l
                  else t;
  if 0 leq car mults
    then go to outer;
  u:=basis;
inner:
  if null u
    then <<
      if !*tra
        then <<
      princ "The answer from the linear equations did";
      printc " not have the poles at:";
          printplace car places >>;
      return nil >>;
  v:=taylorform xsubstitutesq(car u,car places);
  if taylorfirst v=car mults
    then <<
      if magiclist
        then l:=taylorevaluate(v,car mults) . l;
      go to outer >>;
  if taylorfirst v < car mults
    then interr "Extraneous pole introduced";
  u:=cdr u;
  go to inner
  end;



symbolic procedure coates!-hpfsd(oplaces,omults);
begin
  scalar mzero,pzero,mpole,ppole,fun,summzero,answer,places,mults;
  places:=oplaces;
  mults:=omults;
  % Keep originals in case need to use COATES!-REAL directly.
  summzero:=0;
    % holds the sum of all the mzero's.
  while places do <<
    if 0<car mults
      then <<
        summzero:=summzero + car mults;
        mzero:=(car mults).mzero;
        pzero:=(car places).pzero >>
      else <<
        mpole:=(car mults).mpole;
        ppole:=(car places).ppole >>;
    places:=cdr places;
    mults:=cdr mults >>;
  if summzero > 2 then begin
    % We want to combine a zero/pole pair
    % so as to reduce the total index before calling coates!-real
    % on the remaining zeros/poles.
    scalar nplaces,nmults,f,multiplicity,newpole,sqrts,fz,zfound,mult1;
    sqrts:=getsqrtsfromplaces ppole;
    if !*tra or !*trmin then <<
      princ "Operate on divisor:";
      printc append(mzero,mpole);
      printc "at";
      mapc(pzero,function printplace);
      mapc(ppole,function printplace) >>;
iterate:
    nplaces:=list car pzero;
    multiplicity:=car mzero;
    nmults:=list 1;
    if cdr ppole
      then <<
        nplaces:=(car ppole) . ( (cadr ppole) . nplaces);
        multiplicity:=min(multiplicity,- car mpole,- cadr mpole);
        nmults:=(-1) .((-1) . nmults) >>
      else <<
        nplaces:=(car ppole) . nplaces;
        multiplicity:=min(multiplicity,(- car mpole)/2);
        nmults:=(-2) . nmults >>;
    previousbasis:=nil;
    f:=coates!-real(nplaces,nmults);
    if atom f
      then <<
 if !*tra or !*trmin then
          printc "Failure: must try whole divisor";
 return coates!-real(oplaces,omults) >>;
%    newpole:=removezero(findzeros(f,sqrts),car pzero).
    fz:=findzeros(f,sqrts,2);
    zfound:=assoc(car pzero,fz);
    if not zfound
       then interr list("Didn't seem to find the zero",
                        car pzero,
                        "we looked for");
    if cdr zfound > car mzero
       then interr "We found too many zeros";
    fz:=delete(zfound,fz);
    if !*tra or !*trmin then <<
      printc "Replaced by the pole";
      if fz then prettyprint fz
       else <<terpri(); prin2t "The zero we were already looking for">>;
      princ multiplicity;
      printc " times" >>;
    mult1:=car mzero - multiplicity * cdr zfound;
    if mult1 < 0
 then <<if !*tra then  printc "*** A zero has turned into a pole";
     multiplicity:= car mzero / cdr zfound ;
  mult1:=remainder(car mzero, cdr zfound); >>;
    if mult1=0
      then <<
        mzero:=cdr mzero;
        pzero:=cdr pzero >>
      else rplaca(mzero,mult1);
    if null cdr ppole
      then <<
    if (car mpole + 2*multiplicity)=0
          then <<
            ppole:=cdr ppole;
     mpole:=cdr mpole >>
          else rplaca(mpole,car mpole + 2 * multiplicity) >>
      else <<
    if (cadr mpole + multiplicity)=0
          then <<
            ppole:=(car ppole) . (cddr ppole);
            mpole:=(car mpole) . (cddr mpole) >>
          else rplaca(cdr mpole,cadr mpole + multiplicity);
    if (car mpole + multiplicity)=0
          then <<
            ppole:=cdr ppole;
            mpole:=cdr mpole >>
          else rplaca(mpole,car mpole + multiplicity) >>;
    while fz do <<
      newpole:=caar fz;
      mult1:=multiplicity*(cdar fz);
      if newpole member pzero
        then begin
          scalar m,p;
          while newpole neq car pzero do <<
            m:=(car mzero).m;
            mzero:=cdr mzero;
            p:=(car pzero).p;
            pzero:=cdr pzero >>;
          if mult1 < car mzero then <<
            mzero:=(car mzero - mult1) . cdr mzero;
            mzero:=nconc(m,mzero);
            pzero:=nconc(p,pzero);
            return >>;
          if mult1 > car mzero then <<
            ppole:=newpole.ppole;
            mpole:=(car mzero - mult1) . mpole >>;
          mzero:=nconc(m,cdr mzero);
          pzero:=nconc(p,cdr pzero)
          end
        else if newpole member ppole then begin
          scalar m,p;
          m:=mpole;
          p:=ppole;
          while newpole neq car p do <<
            p:=cdr p;
            m:=cdr m >>;
          rplaca(m,car m - mult1)
          end
        else <<
          mpole:=nconc(mpole,list(-mult1));
          ppole:=nconc(ppole,list newpole) >>;
      fz:=cdr fz >>;
    f:=mk!*sq f;
    if multiplicity > 1
      then answer:=list('expt,f,multiplicity).answer
      else answer:=f.answer;
    summzero:=0;
    for each x in mzero do summzero:=summzero+x;
    if !*tra then <<
      princ "Function is now: ";
      printc append(mzero,mpole);
      printc "at";
      mapc(pzero,function printplace);
      mapc(ppole,function printplace) >>;
    if summzero > 2
      then go to iterate;
    end;
  if pzero or ppole then << % there's something left to do
     fun:=coates!-real(nconc(pzero,ppole),
                       nconc(mzero,mpole));
     if null answer
       then return fun
       else answer:=(mk!*sq fun).answer >>;
  return !*k2q('times.answer);
    % This is not valid, but we hope that it will be unpicked;
    % (e.g. by SIMPLOG) before too much damage is caused.
  end;

% symbolic procedure removezero(l,place);
% if place member l
%   then (lambda u; if null cdr u then car u
%             else interr "Removezero") delete(place,l)
%   else interr "Error in removezeros";

symbolic procedure findzeros(sq,sqrts,nzeros);
% NZEROS is the number of zeros known, a priori, to exist
begin
  scalar u,potentials,answer,n,not!-answer,nz,series;
  u:=denr sqrt2top invsq sq;
  potentials:=for each v in jfactor(u,intvar) collect begin
    scalar w,place;
    w:=makemainvar(numr v,intvar);
    if ldeg w neq 1
      then interr "Can't cope";
    if red w
      then place:=list(intvar,'plus,intvar,prepsq(negf red w ./ lc w))
      else place:=intvar . intvar;
      % This IF .. ELSE .. added JHD 3 Sept 1980.
    return place
    end;
  potentials:=list(intvar,'quotient,1,intvar).potentials;
  for each place in potentials do begin
    scalar slist,nestedsqrts;
    place:=list place;
    newplace place;
    u:=substitutesq(sq,place);
    while involvesq(u,sqrt!-intvar) do begin
      scalar z;
      z:=list list(intvar,'expt,intvar,2);
      place:=nconc(place,z);
      newplace place;
      u:=substitutesq(u,z);
      end;
    slist:=sqrtsinsq(u,intvar);
    for each v in sqrts do
      slist:=union(slist,sqrtsinsq(xsubstitutesq(!*kk2q v,place),
       intvar));
    slist:=sqrtsign(slist,intvar);
    for each s in slist do
      if (n:=taylorfirst (series:=taylorform substitutesq(u,s))) > 0
        then answer:=(append(place,s).n).answer
        else not!-answer:=list(u,place,s,series) . not!-answer;
    return answer;
    end;
  nz:= for each u in answer sum cdr u;
  if nz = nzeros then return answer;
  if nz > nzeros
    then interr "We have too many zeros";
  if !*tra
   then printc "Couldn't find enough zeros of the function: try harder";
  for each v in not!-answer do begin
      scalar !*galois,sqrtsavelist,sublist,s;
      % If we don't reset taylorasslist, then all calculations are
      % dubious!
      taylorasslist:=nil;
      !*galois:=t;
      sqrtsavelist:=listofallsqrts.listofnewsqrts;
      listofnewsqrts:=list mvar gaussiani;
      listofallsqrts:=list((argof mvar gaussiani) . gaussiani);
      series:=cadddr v;
      s:=cdr assoc(taylorfirst series,taylorlist series);
      for each u in sortsqrts(sqrtsinsq(s,nil),nil) do begin
          scalar v,uu;
          uu:=!*q2f simp argof u;
          v:=actualsimpsqrt uu;
          listofallsqrts:=(uu.v).listofallsqrts;
          if domainp v or mvar v neq u then <<
             if !*tra or !*trfield then <<
                printc u;
                printc "re-expressed as";
                printsf v >>;
             basic!-listofnewsqrts := union(sqrtsinsf(v,nil,nil),
                                          basic!-listofnewsqrts);
             basic!-listofallsqrts := car listofallsqrts .
                                          basic!-listofallsqrts;
             v:=prepf v;
             sublist:= (u.v) .sublist;

             sqrtsavelist:=( car listofallsqrts .
                            delete(assoc(uu,car sqrtsavelist),
                                   car sqrtsavelist)).
                            delete(u,cdr sqrtsavelist)>>;
          end;
      listofallsqrts:=car sqrtsavelist;
      listofnewsqrts:=cdr sqrtsavelist;
      if sublist and null numr substitutesq(s,sublist) then <<
         if !*tra or !*trfield
           then printc "a non-zero term has become zero";
         !*galois:=nil;
                  % We'll have done all we wanted, and mustn't confuse
         if (n:=taylorfirst taylorform substitutesq(car v,caddr v)) > 0
            then << answer:= (append(cadr v,caddr v).n) . answer;
                    nz:= nz+n ;
                    if !*tra or !*trfield then
                       printc "that found us a new zero of the function"
                  >>>>;
      end;
  if nz = nzeros then return answer;
  interr "can't find enough zeros";
  end;

endmodule;


module coatesid;

% Author: James H. Davenport.

fluid '(!*tra intvar magiclist taylorasslist taylorvariable);

exports coatessolve,vecprod,coates!-lineq;

imports !*invsq,!*multsq,negsq,!*addsq,swap,check!-lineq,non!-null!-vec,
 printsq,sqrt2top,mapvec,mksp,vecsort,addsq,mkilist,mkvec,mapply,
 taylorformp,xsubstitutesq,taylorform,taylorevaluate,multsq,
 invsq,removecmsq;

symbolic procedure coatessolve(mzero,pzero,basis,normals);
begin
  scalar m,n,rightside,nnn;
% if null normals
%   then normals:=list mkilist(basis,1 ./ 1);
%     This provides the default normalisation,
%     viz merely a de-homogenising constraint;
% No it doesn't - JHD May 1983 and August 1986.
% This may be precisely the wrong constraint, as can be seen from
% the example of SQRT(X**2-1).  Fixed 19/8/86 to amend COATESMATRIX
% to insert a normalising constraint if none is provided.
  nnn:=max(length normals,1);
  basis:=mkvec basis;
  m:=coatesmatrix(mzero,pzero,basis,normals);
  n:=upbv m;
  rightside:=mkvect n;
  for i:=0:n do
    putv(rightside,n-i,(if i < nnn
                       then 1
                       else nil) ./ 1);
  n:=coates!-lineq(m,rightside);
  if n eq 'failed
    then return 'failed;
  n:=removecmsq vecprod(n,basis);
  if !*tra then <<
    printc "Answer from linear equation solving is ";
    printsq n >>;
  return n
  end;



symbolic procedure coatesmatrix(mzero,pzero,basis,normals);
% NORMALS is a list of the normalising constraints
% that we must apply.  Thypically, this is NIL, and we have to
% invent one - see the code IF NULL NORMALS ...
begin
  scalar ans,n1,n2,j,w,save,nextflag,save!-taylors,x!-factors,
     normals!-ok,temp;
  save!-taylors:=mkvect isub1 length pzero;
  save:=taylorasslist;
  normals!-ok:=nil;
  n1:=upbv basis;
  n2:=isub1 mapply(function plus2,mzero) + max(length normals,1);
    % the number of constaints in all (counting from 0).
  taylorvariable:=intvar;
  if !*tra then <<
    printc "Basis for the functions with precisely the correct poles";
    mapvec(basis,function printsq) >>;
  ans:=mkvect n2;
  for i:=0:n2 do
    putv(ans,i,mkvect n1);
  for i:=0:n1 do begin
    scalar xmz,xpz,k;
    xmz:=mzero;
    k:=j:=0;
    xpz:=pzero;
    while xpz do <<
      newplace basicplace car xpz;
      if nextflag
        then w:=taylorformp list('binarytimes,
     getv(save!-taylors,k),
     getv(x!-factors,k))
 else if not !*tra
          then w:=taylorform xsubstitutesq(getv(basis,i),car xpz)
          else begin
            scalar flg,u,slists;
            u:=xsubstitutesq(getv(basis,i),basicplace car xpz);
            slists:=extenplace car xpz;
            for each w in sqrtsinsq(u,intvar) do
              if not assoc(w,slists)
                then flg:=w.flg;
            if flg then <<
          printc "The following square roots were not expected";
              mapc(flg,function superprint);
          printc "in the substitution";
              superprint car xpz;
              printsq getv(basis,i) >>;
            w:=taylorform xsubstitutesq(u,slists)
            end;
      putv(save!-taylors,k,w);
      k:=iadd1 k;
      for l:=0 step 1 until isub1 car xmz do <<
        astore(ans,j,i,taylorevaluate(w,l));
        j:=iadd1 j >>;
      if null normals and j=n2 then <<
 temp:=taylorevaluate(w,car xmz);
 astore(ans,j,i,temp);
 % The defaults normalising condition is that the coefficient
 % after the last zero be a non-zero.
 % Unfortunately this too may fail (JHD 21.3.87) - check for it later
 normals!-ok:=normals!-ok or numr temp >>;
      xpz:=cdr xpz;
      xmz:=cdr xmz  >>;
    nextflag:=(i < n1) and
       (getv(basis,i) = multsq(!*kk2q intvar,getv(basis,i+1)));
    if nextflag and null x!-factors then <<
      x!-factors:=mkvect upbv save!-taylors;
      xpz:=pzero;
      k:=0;
      xmz:=invsq !*kk2q intvar;
      while xpz do <<
 putv(x!-factors,k,taylorform xsubstitutesq(xmz,car xpz));
        xpz:=cdr xpz;
        k:=iadd1 k >> >>
    end;
  if null normals and null normals!-ok then <<
     if !*tra
       then printc "Our default normalisation condition was vacuous";
     astore(ans,n2,n1,1 ./ 1)>>;
  while normals do <<
    w:=car normals;
    for k:=0:n1 do <<
      astore(ans,j,k,car w);
      w:=cdr w >>;
    j:=iadd1 j;
    normals:=cdr normals >>;
  tayshorten save;
  return ans
  end;


symbolic procedure printmatrix(ans,n2,n1);
if !*tra
  then <<
    printc "Equations to be solved:";
    for i:=0:n2 do begin
      if null getv(ans,i)
        then return;
      princ "Row number ";
      princ i;
      for j:=0:n1 do
        printsq getv(getv(ans,i),j)
      end >>;



symbolic procedure vecprod(u,v);
begin
  scalar w,n;
  w:=nil ./ 1;
  n:=upbv u;
  for i:=0:n do
    w:=!*addsq(w,!*multsq(getv(u,i),getv(v,i)));
  return w
  end;



symbolic procedure coates!-lineq(m,rightside);
begin
  scalar nnn,n;
  nnn:=desparse(m,rightside);
  if nnn eq 'failed
    then return 'failed;
  m:=car nnn;
  if null m
    then <<
      n:=cddr nnn;
      goto vecprod >>;
  rightside:=cadr nnn;
  nnn:=cddr nnn;
  n:=check!-lineq(m,rightside);
  if n eq 'failed
    then return n;
  n:=jhdsolve(m,rightside,non!-null!-vec nnn);
  if n eq 'failed
    then return n;
  for i:=0:upbv n do
    if (m:=getv(nnn,i))
      then putv(n,i,m);
vecprod:
  for i:=0:upbv n do
    if null getv(n,i) then putv(n,i,nil ./ 1);
  return n
  end;



symbolic procedure jhdsolve(m,rightside,ignore);
% Returns answer to m.answer=rightside.
% Matrix m not necessarily square.
begin
  scalar ii,n1,n2,ans,u,row,swapflg,swaps;
  % The SWAPFLG is true if we have changed the order of the
  % columns and need later to invert this via SWAPS.
  n1:=upbv m;
  for i:=0:n1 do
    if (u:=getv(m,i))
      then (n2:=upbv u);
  printmatrix(m,n1,n2);
  swaps:=mkvect n2;
  for i:=0:n2 do
    putv(swaps,i,n2-i);
    % We have the SWAPS vector, which should be a vector of indices,
    % arranged like this because VECSORT sorts in decreasing order.
  for i:=0:isub1 n1 do begin
    scalar k,v,pivot;
  tryagain:
    row:=getv(m,i);
    if null row
      then go to interchange;
    % look for a pivot in row.
    k:=-1;
    for j:=0:n2 do
      if numr (pivot:=getv(row,j))
        then <<
          k:=j;
          j:=n2 >>;
    if k neq -1
      then goto newrow;
    if numr getv(rightside,i)
      then <<
        m:='failed;
    i:=sub1 n1; %Force end of loop.
        go to finished >>;
    % now interchange i and last element.
interchange:
    swap(m,i,n1);
    swap(rightside,i,n1);
    n1:=isub1 n1;
    if i iequal n1
      then goto finished
      else goto tryagain;
  newrow:
    if i neq k
      then <<
        swapflg:=t;
        swap(swaps,i,k);
      % record what we have done.
        for l:=0:n1 do
          swap(getv(m,l),i,k) >>;
    % place pivot on diagonal.
    pivot:=sqrt2top negsq !*invsq pivot;
    for j:=iadd1 i:n1 do begin
      u:=getv(m,j);
      if null u
        then return;
      v:=!*multsq(getv(u,i),pivot);
      if numr v then <<
        putv(rightside,j,
     !*addsq(getv(rightside,j),!*multsq(v,getv(rightside,i))));
        for l:=0:n2 do
   putv(u,l,!*addsq(getv(u,l),!*multsq(v,getv(row,l)))) >>
      end;
  finished:
    end;
  if m eq 'failed
    then go to failed;
    % Equations were inconsistent.
  while null (row:=getv(m,n1)) do
    n1:=isub1 n1;
  u:=nil;
  for i:=0:n2 do
    if numr getv(row,i)
      then u:='t;
  if null u
    then if numr getv(rightside,n1)
      then go to failed
      else n1:=isub1 n1;
      % Deals with a last equation which is all zero.
  if n1 > n2
    then go to failed;
    % Too many equations to satisfy.
  ans:=mkvect n2;
  n2:=n2 - ignore;
  ii:=n1;
  for i:=0 step 1 until n1 do
    if null getv(m,i)
      then ii:=iadd1 ii;
  if ii < n2 then <<
    if !*tra then <<
      printc "The equations do not completely determine the functions";
      printc "Matrix:";
      mapvec(m,function superprint);
      printc "Right-hand side:";
      superprint rightside;
      printc list("Adding new symbols for ", iadd1 ii," ... ",n2) >>;
%    FOR I:=IADD1 ii:N2 DO <<
%      U:=GENSYM();
%      MAGICLIST:=U.MAGICLIST;
%      PUTV(ANS,I,!*KK2Q U) >>;
    if !*tra then printc "If in doubt consult an expert">>;
  % now to do the back-substitution.
  % Note that the matrix is not necessarily square,
  % but that we have ensured that the non-square (underdetermiined)
  % parts are at the right
  for i:=n1 step -1 until 0 do begin
    row:=getv(m,i);
    if null row
      then return;
%    WHILE NULL NUMR GETV(ROW,II) DO II:=ISUB1 II;
    ii:=0;
    while null numr getv(row,ii) do ii:=iadd1 ii;
    u:=getv(rightside,i);
    for j:=iadd1 ii:n2 do <<
      if null getv(ans,j) then <<
        magiclist:=gensym().magiclist;
        putv(ans,j,!*kk2q car magiclist) >>;
      u:=!*addsq(u,!*multsq(getv(row,j),negsq getv(ans,j)))
      >>;
    putv(ans,ii,!*multsq(u,sqrt2top !*invsq getv(row,ii)));
%    II:=ISUB1 II;
    end;
  if swapflg
    then vecsort(swaps,list ans);
  return ans;
failed:
  if !*tra then printc "Unable to force correct zeroes";
  return 'failed
  end;



symbolic procedure desparse(matrx,rightside);
begin
  scalar vect,changed,n,m,zero,failed;
  zero := nil ./ 1;
  n:=upbv matrx;
  m:=upbv getv(matrx,0);
  vect := mkvect m;
  % for i:=0:m do putv(vect,i,zero);   %%% initialize - ach
  changed:=t;
  while changed and not failed do begin
    changed:=nil;
    for i:=0:n do
      if changed or failed
    then i:=n   % and hence quit the loop.
        else begin
          scalar nzcount,row,pivot;
          row:=getv(matrx,i);
          if null row
            then return;
          nzcount:=0;
          for j:=0:m do
            if numr getv(row,j)
              then <<
                nzcount:=iadd1 nzcount;
                pivot:=j >>;
          if nzcount = 0
            then if null numr getv(rightside,i)
              then return putv(matrx,i,nil)
              else return (failed:='failed);
          if nzcount > 1
            then return nil;
          nzcount:=getv(rightside,i);
          if null numr nzcount
            then <<
              putv(vect,pivot,zero);
       go to was!-zero >>;
   nzcount:=!*multsq(nzcount,!*invsq getv(row,pivot));
          putv(vect,pivot,nzcount);
          nzcount:=negsq nzcount;
          for i:=0:n do
            if (row:=getv(matrx,i))
              then if numr (row:=getv(row,pivot))
  then putv(rightside,i,!*addsq(getv(rightside,i),
      !*multsq(row,nzcount)));
was!-zero:
          for i:=0:n do
            if (row:=getv(matrx,i))
              then putv(row,pivot,zero);
          changed:=t;
          putv(matrx,i,nil);
          swap(matrx,i,n);
          swap(rightside,i,n);
          end;
    end;
  if failed
    then return 'failed;
  changed:=t;
  for i:=0:n do
    if getv(matrx,i)
      then changed:=nil;
  if changed
    then matrx:=nil;
    % We have completely solved the equations by these machinations.
  return matrx.(rightside . vect)
  end;


symbolic procedure astore(a,i,j,val);
   putv(getv(a,i),j,val);

endmodule;


module findmagc;

% Author: James H. Davenport.

fluid '(!*tra magiclist);

symbolic procedure findmagic l;
begin
  scalar p,n,pvec,m,intvec,mcount,temp;
  % L is a list of things which must be made non-zero by means of
%   a suitable choice of values for the variables in MAGICLIST;
  l:=for each u in l collect
     << mapc(magiclist,function (lambda v;
                                 if involvesf(denr u,v)
                                   then interr "Hard findmagic"));
        numr u >>;
  if !*tra then <<
    printc "We must make the following non-zero:";
    mapc(l,function printsf);
    princ "by suitable choice of ";
    printc magiclist >>;
  % Strategy is random choice in a space which has only finitely
%   many singular points;
  p:=0;
  n:=isub1 length magiclist;
  pvec:=mkvect n;
  putv(pvec,0,2);
  for i:=1:n do
    putv(pvec,i,nextprime getv(pvec,isub1 i));
  % Tactics are based on Godel (is this a mistake ??) and let P run
%   through numbers and take the prime factorization of them;
  intvec:=mkvect n;
loop:
  p:=iadd1 p;
  if !*tra then <<
    princ "We try the number ";
    printc p >>;
  m:=p;
  for i:=0:n do <<
    mcount:=0;
    while cdr(temp:=divide(m,getv(pvec,i)))=0 do <<
      mcount:=iadd1 mcount;
      m:=car temp >>;
    putv(intvec,i,mcount) >>;
  if m neq 1
    then go to loop;
  if !*tra then <<
    printc "which corresponds to ";
    superprint intvec >>;
  m:=nil;
  temp:=magiclist;
  for i:=0:n do <<
    m:=((car temp).getv(intvec,i)).m;
    temp:=cdr temp >>;
  % M is the list of substitutions corresponding to this value of P;
  temp:=l;
loop2:
  if null numr algint!-subf(car temp,m)
    then go to loop;
  temp:=cdr temp;
  if temp
    then go to loop2;
  if !*tra then <<
    printc "which corresponds to the values:";
    superprint m >>;
  return m
  end;

endmodule;


module findres;

% Author: James H. Davenport.

fluid '(!*gcd
        !*tra
        !*trmin
        basic!-listofallsqrts
        basic!-listofnewsqrts
        intvar
        listofallsqrts
        listofnewsqrts
        nestedsqrts
        sqrt!-intvar
        taylorvariable);


exports find!-residue,findpoles;
imports sqrt2top,jfactor,prepsq,printplace,simpdf,involvesf,simp;
imports stt,interr,mksp,negf,multf,addf,let2,substitutesq,subs2q,quotf;
imports printsq,clear,taylorform,taylorevaluate,involvesf,!*multsq;
imports sqrtsave,sqrtsinsq,sqrtsign;

symbolic procedure find!-residue(simpdl,x,place);
  % evaluates residue of simpdl*dx at place given by x=place(y).
begin
  scalar deriv,nsd,poss,slist;
  listofallsqrts:=basic!-listofallsqrts;
  listofnewsqrts:=basic!-listofnewsqrts;
  deriv:=simpdf(list(place,x));
  if involvesf(numr deriv,intvar)
    then return residues!-at!-new!-point(simpdl,x,place);
  if eqcar(place,'quotient) and (cadr place iequal 1)
    then goto place!-correct;
  place:=simp list('difference,intvar,place);
  if involvesq(place,intvar)
    then interr "Place wrongly formatted";
  place:=list('plus,intvar,prepsq place);
place!-correct:
  if car place eq 'plus and caddr place = 0
    then place:=list(x.x)
    else place:=list(x.place);
  % the substitution required.
  nsd:=substitutesq(simpdl,place);
  deriv:=!*multsq(nsd,deriv);
  % differential is deriv * dy, where x=place(y).
  if !*tra then <<
    printc "Differential after first substitution is ";
    printsq deriv >>;
  while involvesq(deriv,sqrt!-intvar)
    do <<
      sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,place);
      nsd:=list(list(x,'expt,x,2));
      deriv:=!*multsq(substitutesq(deriv,nsd),!*kk2q x);
      % derivative of x**2 is 2x, but there's a jacobian of 2 to
      % consider.
      place:=nconc(place,nsd) >>;
  % require coeff x**-1 in deriv.
  nestedsqrts:=nil;
  slist:=sqrtsinsq(deriv,x);
  if !*tra and nestedsqrts
    then printc "We have nested square roots";
  slist:=sqrtsign(slist,intvar);
  % The reversip is to ensure that the simpler sqrts are at
  % the front of the list.
  % Slist is a list of all combinations of signs of sqrts.
  taylorvariable:=x;
  for each branch in slist do <<
    nsd:=taylorevaluate(taylorform substitutesq(deriv,branch),-1);
    if numr nsd
      then poss:=(append(place,branch).sqrt2top nsd).poss >>;
  poss:=reversip poss;
  if null poss
    then go to finished;
  % poss is a list of all possible residues at this place.
  if !*tra
    then <<
      princ "Residues at ";
      printplace place;
      printc " are ";
      mapc(poss, function (lambda u; <<
                       printplace car u;
                       printsq cdr u >>)) >>;
finished:
  sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,place);
  return poss
  end;


symbolic procedure residues!-at!-new!-point(func,x,place);
begin
  scalar place2,tempvar,topterm,a,b,xx;
  if !*tra then <<
    printc "Find residues at all roots of";
    superprint place >>;
  place2:=numr simp place;
  topterm:=stt(place2,x);
  if car topterm = 0
    then interr "Why are we here?";
  tempvar:=gensym();
  place2:=addf(place2,
               multf(!*p2f mksp(x,car topterm),negf cdr topterm));
  % The remainder of PLACE2.
  let2(list('expt,tempvar,car topterm),
       subst(tempvar,x,prepsq(place2 ./ cdr topterm)),
       nil,t);
  place2:=list list(x,'plus,x,tempvar);
  !*gcd:=nil;
    % No unnecessary work: only factors of X worry us.
  func:=subs2q substitutesq(func,place2);
  !*gcd:=t;
  xx:=!*k2f x;
  while (a:=quotf(numr func,xx)) and (b:=quotf(denr func,xx))
    do func:=a ./ b;
  if !*tra then <<
    printc "which gives rise to ";
    printsq func >>;
  if null a
    then b:=quotf(denr func,xx);
    % because B goes back to the last time round that WHILE loop.
  if b then go to hard;
  if !*tra then printc "There were no residues";
  clear tempvar;
  return nil;
  % *** thesis remark ***
%   This test for having an X in the denominator only works
%   because we are at a new place, and hence (remark of Trager)
%   if we have a residue at one place over this point, we must have one
%   at them all, since the places are indistinguishable;
hard:
  taylorvariable:=x;
  func:=taylorevaluate(taylorform func,-1);
  printsq func;
  interr "so far"
  end;


symbolic procedure findpoles(simpdl,x);
begin
  scalar simpdl2,poles;
  % finds possible poles of simpdl * dx.
  simpdl2:=sqrt2top simpdl;
  poles:=jfactor(denr simpdl2,x);
  poles:=mapcar(poles,function prepsq);
  % what about the place at infinity.
  poles:=list('quotient,1,x).poles;
  if !*tra or !*trmin
    then <<
      printc "Places at which poles could occur ";
      for each u in poles do
        printplace list(intvar.u) >>;
  return poles
  end;

endmodule;


module finitise;

% Author: James H. Davenport.

fluid '(!*tra intvar);

exports finitise;
imports newplace,getsqrtsfromplaces,interr,completeplaces2,sqrtsign;
imports mkilist,extenplace;


symbolic procedure finitise(places,mults);
begin
  scalar placesmisc,multsmisc,m,n,sqrts;
  scalar places0,mults0,placesinf,multsinf;
  newplace list (intvar.intvar);
    % fix the disaster with 1/sqrt(x**2-1)
    % (but with no other 1/sqrt(x**2-k).
  sqrts:=getsqrtsfromplaces places;
  placesmisc:=places;
  multsmisc:=mults;
  n:=0;
  while placesmisc do <<
    if eqcar(rfirstsubs car placesmisc,'quotient)
        and (n > car multsmisc)
      then <<
        n:=car multsmisc;
        m:=multiplicity!-factor car placesmisc >>;
    placesmisc:=cdr placesmisc;
    multsmisc:=cdr multsmisc >>;
  if n = 0
    then interr "Why did we call finitise ??";
  % N must be corrected to allow for our representation of
  % multiplicities at places where X is not the local parameter.
  n:=divide(n,m);
  if cdr n neq 0 and !*tra
    then printc
     "Cannot get the poles moved precisely because of ramification";
   if (cdr n) < 0
     then n:=(-1) + car n
     else n:=car n;
        % The above 3 lines (as a replacement for the line below)
        % inserted JHD 06 SEPT 80.
%  n:=car n;
% ***** not true jhd 06 sept 80 *****;
    % This works because, e.g., DIVIDE(-1,2) is -1 remainder 1.
    % Note that N is actually negative.
  % We now wish to divide by X**N, thus increasing
  % the degrees of all infinite places by N and
  % decreasing the degrees of all places lying over 0.
  while places do <<
    if atom rfirstsubs car places
      then <<
        places0:=(car places).places0;
        mults0:=(car mults).mults0 >>
      else if car rfirstsubs car places eq 'quotient
        then <<
          placesinf:=(car places).placesinf;
          multsinf:=(car mults).multsinf >>
        else <<
          placesmisc:=(car places).placesmisc;
          multsmisc:=(car mults).multsmisc >>;
    places:=cdr places;
    mults:=cdr mults >>;
  if places0
    then <<
      places0:=completeplaces2(places0,mults0,sqrts);
      mults0:=cdr places0;
      places0:=car places0;
      m:=multiplicity!-factor car places0;
      mults0:=for each u in mults0 collect u+n*m >>
    else <<
      places0:=for each u in sqrtsign(sqrts,intvar)
                 collect (intvar.intvar).u;
      mults0:=mkilist(places0,n * (multiplicity!-factor car places0))>>;
  placesinf:=completeplaces2(placesinf,
                             multsinf,
                             for each u in extenplace car placesinf
                               collect lsubs u);
  multsinf:=cdr placesinf;
  placesinf:=car placesinf;
  while placesinf do <<
    m:=multiplicity!-factor car placesinf;
    if (car multsinf) neq n*m
      then <<
        placesmisc:=(car placesinf).placesmisc;
        multsmisc:=(car multsinf -n*m).multsmisc >>;
      % This test ensures that we do not add places
      % with a multiplicity of zero.
    placesinf:=cdr placesinf;
    multsinf:=cdr multsinf >>;
  return list(nconc(places0,placesmisc),
              nconc(mults0,multsmisc),
              -n)
  end;


symbolic procedure multiplicity!-factor place;
begin
  scalar n;
  n:=1;
  for each u in place do
    if (lsubs u eq intvar) and
        eqcar(rsubs u,'expt)
      then n:=n*(caddr rsubs u);
  return n
  end;

endmodule;


module fixsubf;

% Author: James H. Davenport.

fluid '(!*nosubs asymplis!* dmode!*);

global '(ncmp!*);

% The standard version of SUBF messes with the order of variables before
% calling SUBF1, something we can't afford, so we define a new version.

symbolic procedure algint!-subf(a,b); algint!-subf1(a,b);

symbolic procedure algint!-subsq(u,v);
   !*multsq(algint!-subf(numr u,v),!*invsq algint!-subf(denr u,v));

symbolic procedure algint!-subf1(u,l);
   %U is a standard form,
   %L an association list of substitutions of the form
   %(<kernel> . <substitution>).
   %Value is the standard quotient for substituted expression.
   %Algorithm used is essentially the straight method.
   %Procedure depends on explicit data structure for standard form;
   if domainp u
     then if atom u then if null dmode!* then u ./ 1 else simpatom u
          else if dmode!* eq car u then !*d2q u
          else simp prepf u
    else begin integer n; scalar kern,m,w,x,xexp,y,y1,z;
        z := nil ./ 1;
    a0: kern := mvar u;
        if m := assoc(kern,asymplis!*) then m := cdr m;
    a:  if null u or (n := degr(u,kern))=0 then go to b
         else if null m or n<m then y := lt u . y;
        u := red u;
        go to a;
    b:  if not atom kern and not atom car kern then kern := prepf kern;
        if null l then xexp := if kern eq 'k!* then 1 else kern
         else if (xexp := algint!-subsublis(l,kern)) = kern
                   and not assoc(kern,asymplis!*)
          then go to f;
    c:  w := 1 ./ 1;
        n := 0;
        if y and cdaar y<0 then go to h;
        if (x := getrtype xexp) then typerr(x,"substituted expression");
        x := simp!* xexp;
        % SIMP!* here causes problem with HE package in subf,
        % but we probably need the extra power of simp!*
        x := reorder numr x ./ reorder denr x;
        % needed in case substitution variable is in XEXP;
        if null l and kernp x and mvar numr x eq kern then go to f
         else if null numr x then go to e;   %Substitution of 0;
        for each j in y do
         <<m := cdar j;
           w := !*multsq(!*exptsq(x,m-n),w);
           n := m;
           z := !*addsq(!*multsq(w,algint!-subf1(cdr j,l)),z)>>;
    e:  y := nil;
        if null u then return z
         else if domainp u then return !*addsq(algint!-subf1(u,l),z);
        go to a0;
    f:  sub2chk kern;
        for each j in y do
           z := !*addsq(!*multsq(!*f2q !*p2f car j,
                                 algint!-subf1(cdr j,l)),z);
        go to e;
    h:  %Substitution for negative powers;
        x := simprecip list xexp;
    j:  y1 := car y . y1;
        y := cdr y;
        if y and cdaar y<0 then go to j;
    k:  m := -cdaar y1;
        w := !*multsq(!*exptsq(x,m-n),w);
        n := m;
        z := !*addsq(!*multsq(w,algint!-subf1(cdar y1,l)),z);
        y1 := cdr y1;
        if y1 then go to k else if y then go to c else go to e
     end;

symbolic procedure algint!-subsublis(u,v);
   begin scalar x;
      return if x := assoc(v,u) then cdr x
              else if atom v then v
              else if car v eq '!*sq then
                      list('!*sq,algint!-subsq(cadr v,u),caddr v)
%    Previous two lines added by JHD 7 July 1982.
%    without them, CDRs in SQ expressions buried inside;
%    !*SQ forms are lost;
              else if x := get(car v,'subfunc) then apply2(x,u,v)
              else for each j in v collect algint!-subsublis(u,j)
   end;

put('int,'subfunc,'algint!-subsubf);

symbolic procedure algint!-subsubf(l,expn);
   %Sets up a formal SUB expression when necessary;
   begin scalar x,y;
      for each j in cddr expn do
         if (x := assoc(j,l)) then <<y := x . y; l := delete(x,l)>>;
      expn := sublis(l,car expn)
                 . for each j in cdr expn
                       collect algint!-subsublis(l,j);
        %to ensure only opr and individual args are transformed;
      if null y then return expn;
      expn := aconc!*(for each j in reversip!* y
                     collect list('equal,car j,aeval cdr j),expn);
      return mk!*sq if l then algint!-simpsub expn
                     else !*p2q mksp('sub . expn,1)
   end;

symbolic procedure algint!-simpsub u;
   begin scalar !*nosubs,w,x,z;
    a:  if null cdr u
          then <<if getrtype car u or eqcar(car u,'equal)
                   then typerr(car u,"scalar");
                 u := simp!* car u;
                 z := reversip!* z;   % to put replacements in same
                                      % order as input.
                 return quotsq(algint!-subf(numr u,z),
                               algint!-subf(denr u,z))>>;
        !*nosubs := t;  % We don't want left side of eqns to change.
        w := reval car u;
        !*nosubs := nil;
        if getrtype w eq 'list
          then <<u := append(cdr w,cdr u); go to a>>
         else if not eqexpr w then errpri2(car u,t);
        x := cadr w;
        if null getrtype x then x := !*a2k x;
        z := (x . caddr w) . z;
        u := cdr u;
        go to a;
   end;

endmodule;


module fracdi;

% Author: James H. Davenport.

fluid '(basic!-listofallsqrts basic!-listofnewsqrts expsub intvar
    sqrt!-intvar);

global '(coates!-fdi);

exports fdi!-print,fdi!-revertsq,fdi!-upgrade,
   fractional!-degree!-at!-infinity;

% internal!-fluid '(expsub);

symbolic procedure fdi!-print();
<< princ "We substitute ";
   princ intvar;
   princ "**";
   princ coates!-fdi;
   princ " for ";
   princ intvar;
   printc " in order to avoid fractional degrees at infinity" >>;


symbolic procedure fdi!-revertsq u;
if coates!-fdi iequal 1
  then u
  else (fdi!-revert numr u) ./ (fdi!-revert denr u);


symbolic procedure fdi!-revert u;
if not involvesf(u,intvar)
  then u
  else addf(fdi!-revert red u,
        !*multf(fdi!-revertpow lpow u,
            fdi!-revert lc u));


symbolic procedure fdi!-revertpow pow;
if not dependsp(car pow,intvar)
  then (pow .* 1) .+ nil
  else if car pow eq intvar
    then begin
      scalar v;
      v:=divide(cdr pow,coates!-fdi);
      if cdr pow=0
        then return (mksp(intvar,car pow) .* 1) .+ nil
    else interr "Unable to revert fdi";
      end
    else if eq(car pow,'sqrt)
      then simpsqrt2 fdi!-revert !*q2f simp argof car pow
      else interr "Unrecognised term to revert";


symbolic procedure fdi!-upgrade place;
begin
  scalar ans,u,expsub,n;
  n:=coates!-fdi;
  for each u in place do
    if eqcar(u:=rsubs u,'expt)
      then n:=n / caddr u;
      % if already upgraded, we must take account of this.
  if n = 1
    then return place;
  expsub:=list(intvar,'expt,intvar,n);
  ans:=nconc(basicplace place,list expsub);
  expsub:=list expsub; % this prevents later nconc from causing trouble.
  u:=extenplace place;
  while u do begin
    scalar v,w,rfu;
    v:=fdi!-upgr2 lfirstsubs u;
    if v iequal 1
      then return (u:=cdr u);
    if eqcar(rfu:=rfirstsubs u,'minus)
      then w:=argof rfu
      else if eqcar(rfu,'sqrt)
        then w:=rfu
    else interr "Unknown place format";
    w:=fdi!-upgr2 w;
    if w iequal 1
      then interr "Place collapses under rewriting";
    if eqcar(rfu,'minus)
      then ans:=nconc(ans,list list(v,'minus,w))
      else ans:=nconc(ans,list(v.w));
    u:=cdr u;
    return
    end;
  sqrtsave(basic!-listofallsqrts,
       basic!-listofnewsqrts,
           basicplace ans);
  return ans
  end;


symbolic procedure fdi!-upgr2 u;
begin
  scalar v,mv;
% V:=SUBSTITUTESQ(SIMP U,EXPSUB);
% The above line doesn't work due to int(sqrt(x-1)/sqrt(x+1),x);
% where the attempt to make sqrt(x^2-1) is frustrated by the presence of
% sqrt(x-1) and sqrt(x+1) which get SIMPed (even after we allow for the
% NEWPLACE call in COATES
  v:=xsubstitutep(u,expsub);
  if denr v neq 1
    then goto error;
  v:=numr v;
loop:
  if atom v
    then return v;
  if red v
    then go to error;
  mv:=mvar v;
  if (not dependsp(mv,intvar)) or (mv eq intvar)
    then <<
      v:=lc v;
      goto loop >>;
  if eqcar(mv,'sqrt) and not sqrtsinsf(lc v,nil,intvar)
      then return mv;
error:
  printc "*** Format error ***";
  princ "unable to go x:=x**";
  printc coates!-fdi;
  superprint u;
  interr "Failure to make integral at infinity"
  end;


symbolic procedure fractional!-degree!-at!-infinity sqrts;
if sqrts
  then lcmn(fdi2 car sqrts,fractional!-degree!-at!-infinity cdr sqrts)
  else 1;


symbolic procedure fdi2 u;
   % Returns the denominator of the degree of x at infinity
   % in the sqrt expression u.
begin
  scalar n;
  u:=substitutesq(simp u,list list(intvar,'quotient,1,intvar));
  n:=0;
  while involvesq(u,sqrt!-intvar) do <<
    n:=iadd1 n;
    u:=substitutesq(u,list list(intvar,'expt,intvar,2)) >>;
  return (2**n)
  end;


symbolic procedure lcmn(i,j);
  i*j/gcdn(i,j);

% unfluid '(expsub);

endmodule;


module genus;

% Author: James H. Davenport.

fluid '(!*galois
        !*tra
        !*trmin
        gaussiani
        intvar
        listofallsqrts
        listofnewsqrts
        nestedsqrts
        previousbasis
        sqrt!-intvar
        sqrt!-places!-alist
        sqrtflag
        sqrts!-in!-integrand
        taylorasslist
        taylorvariable);

symbolic procedure simpgenus u;
begin
  scalar intvar,sqrt!-intvar,taylorvariable,taylorasslist;
  scalar listofnewsqrts,listofallsqrts,sqrt!-places!-alist;
  scalar sqrtflag,sqrts!-in!-integrand,tt,u,simpfn;
  tt:=readclock();
  sqrtflag:=t;
  taylorvariable:=intvar:=car u;
  simpfn:=get('sqrt,'simpfn);
  put('sqrt,'simpfn,'proper!-simpsqrt);
  sqrt!-intvar:=mvar !*q2f simpsqrti intvar;
  listofnewsqrts:= list mvar gaussiani; % Initialise the SQRT world.
  listofallsqrts:= list (argof mvar gaussiani . gaussiani);
  u:=for each v in cdr u
            collect simp!* v;
  sqrts!-in!-integrand:=sqrtsinsql(u,intvar);
  u:=!*n2sq length differentials!-1 sqrts!-in!-integrand;
  put('sqrt,'simpfn,simpfn);
  printc list('time,'taken,readclock()-tt,'milliseconds);
  return u
  end;
put('genus,'simpfn,'simpgenus);

symbolic procedure !*n2sq(u1);
if u1=0 then nil . 1 else u1 . 1;

symbolic procedure differentials!-1 sqrtl;
begin
  scalar asqrtl,faclist,places,v,nestedsqrts,basis,
         u,n,hard!-ones,sqrts!-in!-problem;
    % HARD!-ONES  A list of all the factors of our equations which do
    % not factor, and therefore such that we can divide the whole of
    % our INTBASIS by their product in order to get the true INTBASIS,
    % since these ones can cause no complications.
  asqrtl:=for each u in sqrtl
            collect !*q2f simp argof u;
  if !*tra or !*trmin then <<
    printc
      "Find the differentials of the first kind on curve defined by:";
    mapc(asqrtl,function printsf) >>;
  for each s in asqrtl do <<
    faclist:=for each u in jfactor(s,intvar)
               collect numr u;
    if !*tra then <<
      princ intvar;
      printc " is not a local variable at the roots of:";
      mapc(faclist,function printsf) >>;
    for each uu in faclist do <<
      v:=stt(uu,intvar);
      if 1 neq car v
        then hard!-ones:=uu.hard!-ones
        else <<
          u:=addf(uu,(mksp(intvar,1) .* (negf cdr v)) .+ nil) ./ cdr v;
          % U is now the value at which this SQRT has a zero.
          u:=list(list(intvar,'difference,intvar,prepsq u),
                  list(intvar,'expt,intvar,2));
          for each w in sqrtsign(for each w in union(delete(s,asqrtl),
                                                     delete(uu,faclist))
         conc sqrtsinsq(simpsqrtsq
      multsq(substitutesq(w ./ 1,u),
      1 ./ !*p2f mksp(intvar,2)),
                                      intvar),
                                 intvar)
            do places:=append(u,w).places >> >> >>;
  sqrts!-in!-problem:=nconc(for each u in hard!-ones
                              collect list(intvar.intvar,
                                    (lambda u;u.u) list('sqrt,prepf u)),
                            places);
  basis:=makeinitialbasis sqrts!-in!-problem;
                  % Bodge in any extra SQRTS that we will require later.
%  u:=1 ./ mapply(function multf,
%                for each u in sqrtl collect !*kk2f u);
%  basis:=for each v in basis collect multsq(u,v);
  basis:=integralbasis(mkvec basis,places,mkilist(places,-1),intvar);
  if not !*galois
    then basis:=combine!-sqrts(basis,
                               getsqrtsfromplaces sqrts!-in!-problem);
  if hard!-ones
    then <<
      v:=upbv basis;
      u:=1;
      for each v in hard!-ones do
        u:=multf(u,!*kk2f list('sqrt,prepf v));
      hard!-ones:=1 ./ u;
      for i:=0:v do
        putv(basis,i,multsq(getv(basis,i),hard!-ones)) >>;
  if not !*galois
    then basis:=modify!-sqrts(basis,sqrtl);
  v:=fractional!-degree!-at!-infinity sqrtl;
  if v iequal 1
    then n:=2
    else n:=2*v-1;
    % N  is the degree of the zero we need at INFINITY.
  basis:=normalbasis(basis,intvar,n);
  previousbasis:=nil;
    % it might have been set before, and we have changed its meaning.
  if !*tra or !*trmin then <<
    printc "Differentials are:";
    mapc(basis,function printsq) >>;
  return basis;
  end;

endmodule;


module intbasis;

% Author: James H. Davenport.

fluid '(!*tra !*trmin excoatespoles intvar previousbasis taylorasslist
        taylorvariable);

exports completeplaces,completeplaces2,integralbasis;


symbolic procedure deleteplace(a,b);
if null b
  then nil
  else if equalplace(a,car b)
    then cdr b
    else (car b).deleteplace(a,cdr b);


symbolic procedure completeplaces(places,mults);
begin
  scalar current,cp,cm,op,om,ansp,ansm;
  if null places then return nil;       %%% ACH
loop:
  current:=basicplace car places;
  while places do <<
    if current = (basicplace car places)
      then <<
        cp:=(car places).cp;
        cm:=(car mults ).cm >>
      else <<
        op:=(car places).op;
        om:=(car mults ).om >>;
    places:=cdr places;
    mults:=cdr mults >>;
  cp:=completeplaces2(cp,cm,sqrtsinplaces cp);
  ansp:=append(car cp,ansp);
  ansm:=append(cdr cp,ansm);
  places:=op;
  mults:=om;
  cp:=op:=cm:=om:=nil;
  if places
    then go to loop
    else return ansp.ansm
  end;


symbolic procedure completeplaces2(places,mults,sqrts);
  % Adds extra places with multiplicities of 0 as necessary.
begin scalar b,p;
  sqrts:=sqrtsign(sqrts,intvar);
  b:=basicplace car places;
  p:=places;
  while p do <<
    if not(b = (basicplace car p))
      then interr "Multiple places not supported";
    sqrts:=deleteplace(extenplace car p,sqrts);
    p:=cdr p >>;
  mults:=nconc(nlist(0,length sqrts),mults);
  places:=nconc(mappend(sqrts,b),places);
  return places.mults
  end;


symbolic procedure intbasisreduction(zbasis,places,mults);
begin
  scalar i,m,n,v,w,substn,basis;
  substn:=list(intvar.intvar);
    % The X=X substitution.
  n:=upbv zbasis;
  basis:=copyvec(zbasis,n);
  taylorvariable:=intvar;
  v:=sqrtsinplaces places;
  for i:=0:n do
    w:=union(w,sqrtsinsq(getv(basis,i),intvar));
  m:=intersection(v,w);  % Used to be INTERSECT
  v:=setdiff(v,m);
  w:=setdiff(w,m);
  for each u in v do <<
    if !*tra or !*trmin then <<
      prin2t u;
      prin2t "does not occur in the functions";
      mapvec(basis,function printsq) >>;
    m:=!*q2f simp argof u;
    i:=w;
    while i and not quotf(m,!*q2f simp argof car i)
      do i:=cdr i;
    if null i
      then interr
         "Unable to find equivalent representation of branches";
    i:=car i;
    w:=delete(i,w);
    places:=subst(i,u,places);
    if !*tra or !*trmin then <<
      prin2t "replaced by";
      prin2t i >> >>;
  if (length places) neq (iadd1 n) then <<
   if !*tra
      then prin2t "Too many functions";
    basis := shorten!-basis basis;
    n:=upbv basis >>;
  m:=mkvect n;
  for i:=0:n do
    putv(m,i,cl6roweval(basis.i,places,mults,substn));
reductionloop:
  if !*tra then <<
    prin2t "Matrix before a reduction step:";
    mapvec(m,function prin2t) >>;
  v:=firstlinearrelation(m,iadd1 n);
  if null v
    then return replicatebasis(basis,(iadd1 upbv zbasis)/(n+1));
  i:=n;
  while null numr getv(v,i) do
    i:=isub1 i;
  w:=nil ./ 1;
  for j:=0:i do
    w:=!*addsq(w,!*multsq(getv(basis,j),getv(v,j)));
  w:=removecmsq multsq(w,1 ./ !*p2f mksp(intvar,1));
  if null numr w
    then <<
      mapvec(basis,function printsq);
      prin2t iadd1 i;
      interr "Basis collapses" >>;
  if !*tra then <<
    princ "Element ";
    princ iadd1 i;
    prin2t " of the basis replaced by ";
    if !*tra then
      printsq w >>;
  putv(basis,i,w);
  putv(m,i,cl6roweval(basis.i,places,mults,substn));
  goto reductionloop
  end;


symbolic procedure integralbasis(basis,places,mults,x);
begin
  scalar z,save,points,p,m,princilap!-part,m1;
  if null places
    then return basis;
  mults:=mapcar(mults,function (lambda u;min(u,0)));
  % this makes sure that we impose constraints only on
  % poles, not on zeroes.
  points:=removeduplicates mapcar(places,function basicplace);
  if points = list(x.x)
    then basis:=intbasisreduction(basis,places,mults)
    else if cdr points
      then go complex
      else <<
        substitutevec(basis,car points);
        if !*tra then <<
          prin2t "Integral basis reduction at";
          prin2t car points >>;
        basis:=intbasisreduction(basis,
                                 mapcar(places,function extenplace),
                                 mults);
        substitutevec(basis,antisubs(car points,x)) >>;
join:
  save:=taylorasslist;
  % we will not need te taylorevaluates at gensym.
  z:=gensym();
  places:=mapcons(places,x.list('difference,x,z));
  z:=list(x . z);
%  basis:=intbasisreduction(basis,
%                          places,
%                          nlist(0,length places),
%                          x,z);
  taylorasslist:=save;
  % ***time-hack-2***;
  if not excoatespoles
    then previousbasis:=copyvec(basis,upbv basis);
    % Save only if in COATES/FINDFUNCTION, not if in EXCOATES.
  return basis;
complex:
  while points do <<
    p:=places;
    m:=mults;
    princilap!-part:=m1:=nil;
    while p do <<
    if (car points) = (basicplace car p)
      then <<
        princilap!-part:=(extenplace car p).princilap!-part;
        m1:=(car m).m1 >>;
      p:=cdr p;
      m:=cdr m >>;
    substitutevec(basis,car points);
    if !*tra then <<
      prin2t "Integral basis reduction at";
      prin2t car points >>;
    basis:=intbasisreduction(basis,princilap!-part,m1);
    substitutevec(basis,antisubs(car points,x));
    points:=cdr points >>;
  go to join
  end;


symbolic procedure cl6roweval(basisloc,places,mults,x!-alpha);
% Evaluates a row of the matrix in Coates lemma 6.
begin
  scalar i,v,w,save,basiselement,taysave,mmults,flg;
  i:=isub1 length places;
  v:=mkvect i;
  taysave:=mkvect i;
  i:=0;
  basiselement:=getv(car basisloc,cdr basisloc);
  mmults:=mults;
  while places do <<
    w:=substitutesq(basiselement,car places);
    w:=taylorform substitutesq(w,x!-alpha);
      % The separation of these 2 is essential since the x->x-a
      % must occur after the places are chosen.
    save:=taylorasslist;
    if not flg
      then putv(taysave,i,w);
    w:=taylorevaluate(w,car mmults);
    tayshorten save;
    putv(v,i,w);
    i:=iadd1 i;
    flg:=flg or numr w;
    mmults:=cdr mmults;
    places:=cdr places >>;
  if flg
    then return v;
    % There was a non-zero element in this row.
  save:=0;
loop:
  save:=iadd1 save;
  mmults:=mults;
  i:=0;
  while mmults do <<
    w:=taylorevaluate(getv(taysave,i),save + car mmults);
    flg:=flg or numr w;
    mmults:=cdr mmults;
    putv(v,i,w);
    i:=iadd1 i >>;
  if not flg
    then go to loop;
    % Another zero row.
  putv(car basisloc,cdr basisloc,multsq(basiselement,
                                        1 ./ !*p2f mksp(intvar,save)));
  return v
  end;


symbolic procedure replicatebasis(basis,n);
if n = 1
  then basis
  else if n = 2
    then begin
      scalar b,sqintvar,len;
      len:=upbv basis;
      sqintvar:=!*kk2q intvar;
      b:=mkvect(2*len+1);
      for i:=0:len do <<
        putv(b,i,getv(basis,i));
        putv(b,i+len+1,multsq(sqintvar,getv(basis,i))) >>;
      return b
      end
    else interr "Unexpected replication request";


symbolic procedure shorten!-basis v;
begin
  scalar u,n,sfintvar;
  sfintvar:=!*kk2f intvar;
  n:=upbv v;
  for i:=0:n do begin
    scalar uu;
    uu:=getv(v,i);
    if not quotf(numr uu,sfintvar)
      then u:=uu.u
    end;
  return mkvec u
  end;


endmodule;


module jhddiff;

% Author: James H. Davenport.

% Differentiation routines for algebraic expressions;
symbolic procedure !*diffsq(u,v);
   %U is a standard quotient, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   %Algorithm: df(x/y,z)= (x'-(x/y)*y')/y;
   !*multsq(!*addsq(!*difff(numr u,v),
                    negsq !*multsq(u,!*difff(denr u,v))),
          1 ./ denr u);

symbolic procedure !*difff(u,v);
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V;
   if domainp u then nil ./ 1
    else !*addsq(!*addsq(multpq(lpow u,!*difff(lc u,v)),
                        !*multsq(lc u ./ 1,!*diffp(lpow u,v))),
               !*difff(red u,v));

symbolic procedure !*diffp(u,v);
%  Special treatment of SQRT's (JHD is not sure why,
%  but it seems to be necessary);
if atom (car u) then diffp(u,v)
  else if not (caar u) eq 'sqrt then diffp(u,v)
    else begin
           scalar w,dw;
           w:=simp argof car u;
           dw:= !*diffsq(w,v);
           if null numr dw then return dw;
           return !*multsq(!*multsq(dw,invsq w),
                           !*multf(cdr u,mksp(car u,1) .* 1 .+ nil)./ 2)
           end;

endmodule;


module jhdriver;

% Author: James H. Davenport.

fluid '(!*algint
    !*backtrace
    !*coates
    !*noacn
    !*tra
    !*trmin
    !*structure
        basic!-listofallsqrts
        basic!-listofnewsqrts
        gaussiani
        intvar
        listofallsqrts
        listofnewsqrts
        previousbasis
        sqrt!-intvar
        sqrtflag
        sqrts!-in!-integrand
        sqrts!-mod!-prime
        taylorasslist
        varlist
        zlist);

global '(tryharder);

switch algint,coates,noacn,tra,trmin;

exports algebraiccase,doalggeom,coates!-multiple;

!*algint := t;   % Assume algebraic integration wanted if this module
                 % is loaded.

symbolic procedure operateon(reslist,x);
begin
  scalar u,v,answer,save;
  scalar sqrts!-mod!-prime;
  u:=zmodule(reslist);
  v:=answer:=nil ./ 1;
  while u and not atom v do <<
    v:=findfunction cdar u;
    if not atom v then <<
      if !*tra or !*trmin then <<
    printc "Extension logarithm is ";
        printsq v >>;
      save:=tryharder;
      tryharder:=x;
      v:= combine!-logs(caar u, simplogsq v);
      tryharder:=save;
      answer:=!*addsq(answer,v);
      u:=cdr u >> >>;
  if atom v
    then return v
    else return answer
  end;


symbolic procedure findfunction divisor;
begin
  scalar v,places,mults,ans,dof1k;
  scalar previousbasis;
  % ***time-hack-2 :::
    % A hack for decreasing the amount of work done in COATES.
  divisor:=for each u in divisor collect
         correct!-mults u;
  if !*coates
    then go to nohack;
  v:=precoates(divisor,intvar,nil);
  if not atom v
    then return v;
nohack:
  for each u in divisor do <<
    places:=(car u).places;
    mults :=(cdr u).mults >>;
  v:=coates(places,mults,intvar);
  if not atom v
    then return v;
  dof1k:=differentials!-1 getsqrtsfromplaces places;
  if null dof1k
    then interr "Must be able to integrate over curves of genus 0";
  if not mazurp(places,dof1k)
    then go to general;
  ans:='provably!-impossible;
  for i:=2:12 do
    if (i neq 11) and
       not atom (ans:=coates!-multiple(places,mults,i))
    then i:=12;   % leave the loop - we have an answer.
  return ans;
general:
  v:=findmaninparm places;
  if null v
     then return algebraic!-divisor(divisor,dof1k);
  if not maninp(divisor,v,dof1k)
    then return 'provably!-impossible;
  v:=1;
loop:
  v:=iadd1 v;
  if not atom (ans:=coates!-multiple(places,mults,v))
    then return ans;
  go to loop
  end;


symbolic procedure correct!-mults u;
begin
  scalar multip;
  multip:=cdr u;
  for each v in car u do
    if (lsubs v eq intvar) and
        eqcar(rsubs v,'expt)
      then multip:=multip * (caddr rsubs v);
    return (car u).multip
  end;

symbolic procedure algebraiccase(expression,zlist,varlist);
begin
  scalar rischpart,deriv,w,firstterm;
  scalar sqrtflag,!*structure;  % set !*structure to NIL, else 
                                % sqrt(z)^2 isn't simplified
  sqrtflag:=t;
  sqrtsave(listofallsqrts,listofnewsqrts,list(intvar . intvar));
  rischpart:= errorset!*(list('doalggeom,mkquote expression),
                         !*backtrace);
  newplace list (intvar.intvar);
  if atom rischpart
    then <<
      if !*tra then printc "Inner integration failed";
      deriv:=nil ./ 1;
      % assume no answer.
      rischpart:=deriv >>
    else
      if atom car rischpart
        then <<
      if !*tra or !*trmin then
        printc "The 'logarithmic part' is not elementary";
          return (nil ./ 1) . expression >>
      else <<
        rischpart:=car rischpart;
    deriv:=!*diffsq(rischpart,intvar);
    % deriv := squashsqrt deriv;
    % Should no longer be necessary.
    if !*tra or !*trmin then <<
      printc "Inner working yields";
          printsq rischpart;
      printc "with derivative";
          printsq deriv >> >>;
  deriv:=!*addsq(expression,negsq deriv);
  if null numr deriv
    then return rischpart . (nil ./ 1); % no algebraic part.
  if null involvesq(deriv,intvar)
    then return !*addsq(rischpart,
                !*multsq(deriv,((mksp(intvar,1) .* 1) .+ nil) ./ 1))
          . (nil ./ 1);
        % if the difference is merely a constant.
  varlist:=getvariables deriv;
  zlist:=findzvars(varlist,list intvar,intvar,nil);
  varlist:=setdiff(varlist,zlist);
  firstterm:=simp!* car zlist; % this may crop up.
  w:=sqrt2top !*multsq(deriv,invsq !*diffsq(firstterm,intvar));
  if null involvesq(w,intvar)
    then return !*addsq(rischpart,!*multsq(w,firstterm)) . (nil ./ 1);
  if !*noacn then interr "Testing only logarithmic code";
  deriv:=transcendentalcase(deriv,intvar,nil,zlist,varlist);
  return !*addsq(car deriv, rischpart) . cdr deriv
  end;

symbolic procedure doalggeom(differential);
begin
  scalar reslist,place,placelist,
     savetaylorasslist,sqrts!-in!-integrand,
     taylorasslist;
  placelist:=findpoles(differential,intvar);
  reslist:=nil;
  sqrts!-in!-integrand:=sqrtsinsq (differential,intvar);
  while placelist do <<
    place:=car placelist;
    placelist:=cdr placelist;
    savetaylorasslist:=taylorasslist;
    place:=find!-residue(differential,intvar,place);
    if place
      then reslist:=append(place,reslist)
      else taylorasslist:=savetaylorasslist >>;
  if reslist
    then go to serious;
  if !*tra or !*trmin
    then printc "No residues => no logs";
  return nil ./ 1;
serious:
  placelist:=operateon(reslist,intvar);
  if placelist eq 'failed
    then interr "Divisor operations failed";
  return placelist
  end;


symbolic procedure algebraic!-divisor(divisor,dof1k);
if length dof1k = 1
  then lutz!-nagell(divisor)
  else bound!-torsion(divisor,dof1k);


symbolic procedure coates!-multiple(places,mults,v);
begin
  scalar ans;
  if not atom (ans:=coates(places,
                           for each u in mults collect v*u,
                           intvar))
    then <<
      if !*tra or !*trmin then <<
    princ "Divisor has order ";
        printc v >>;
      return !*kk2q list('nthroot,mk!*sq ans,v) >>
    else return ans
  end;


symbolic procedure mazurp(places,dof1k);
   % Checks to ensure we have an elliptic curve over the rationals.
begin
%  scalar sqrt2,sqrt4,v;
%  sqrt2:=0;
%    % Number of SQRTs of things of degree 1 or 2;
%  sqrt4:=0;
%    % " " " 3 or 4;
%  for each u in getsqrtsfromplaces places do <<
%    v:=!*q2f simp u;
%    if sqrtsinsq(v,intvar)
%      then return nil;
%      % Cannot use nested SQRTs;
%    v:=car stt(v,intvar);
%    if v < 3
%      then if sqrt4>0
%        then return nil
%        else if sqrt2>1
%          then return nil
%          else sqrt2:=iadd1 sqrt2
%      else if v < 5
%        then if sqrt2>0 or sqrt4>0
%          then return nil
%          else sqrt4:=1
%        else return nil >>;
  scalar answer;
  if length dof1k neq 1
    then return nil;
    % Genus = # linearly independent differentials of 1st kind;
    % We know know that it is of genus = 1.
  answer:=t;
  while answer and places do
    if sqrtsintree(basicplace car places,nil,nil)
      then answer:= nil
      else places:=cdr places;
  if null answer then return nil;
  if !*tra then
    <<prin2 "*** We can apply Mazur's bound on the torsion of";
      prin2t "elliptic curves over the rationals">>;
  return t
  end;

endmodule;


module linrel;

% Author: James H. Davenport.

symbolic procedure firstlinearrelation(m,n);
% Returns vector giving first linear relation between
% the rows of n*n matrix m.
begin
  scalar m1,u,uu,v,w,x,xx,i,j,isub1n,ans;
  isub1n:=isub1 n;
  m1:=mkvect(isub1n);
  for i:=0 step 1 until isub1n do
    putv(m1,i,copyvec(getv(m,i),isub1n));
  % m1 is a copy of m which we can afford to destroy.
  ans:=mkidenm isub1n;
  i:=0;
outerloop:
  u:=getv(m1,i);
  uu:=getv(ans,i);
  j:=0;
pivotsearch:
  if j iequal n
    then goto zerorow;
  v:=getv(u,j);
  if null numr v then << j:=iadd1 j; goto pivotsearch >>;
  % we now use the j-th element of row i to flatten the j-th
  % element of all later rows.
  if i iequal isub1n then return nil;
    %no further rows to flatten, so no relationships.
  v:=!*invsq negsq v;
  for k:=iadd1 i step 1 until isub1n do <<
    xx:=getv(ans,k);
    x:=getv(m1,k);
    w:=!*multsq(v,getv(x,j));
    for l:=0:isub1n do <<
      putv(x,l,!*addsq(getv(x,l),!*multsq(w,getv(u,l))));
      putv(xx,l,!*addsq(getv(xx,l),!*multsq(w,getv(uu,l)))) >> >>;
  i:=iadd1 i;
  if i < n then goto outerloop;
  % no zero rows found at all.
  return nil;
zerorow:
  % the i-t row is all zero, i.e. rows 1...i are dependent.
  return getv(ans,i)
  end;

endmodule;


module result;

% Author: James H. Davenport.

fluid '( !*rationalize !*tra gaussiani !*trmin intvar );

exports combine!-logs;

symbolic procedure combine!-logs(coef,logarg);
% Attempts to produce a "simple" form for COEF*(LOGARG).  COEF is
% prefix, LOGARG an SQ (and already log'ged for historical reasons).
begin
  scalar ans,dencoef,parts,logs,lparts,!*rationalize,trueimag;
  !*rationalize:=t;    % A first attempt to use this technology.
  coef:=simp!* coef;
  parts:=split!-real!-imag numr coef;
  if null numr cdr parts then return multsq(coef,logarg);
  % Integrand was, or seemed to be, purely real.
  dencoef:=multf(denr coef,denr logarg);
  if !*tra then <<
     printc "attempting to find 'real' form for";
     mathprint list('times,list('plus,prepsq car parts,
                                      list('times,prepsq cdr parts,'i)),
                           prepsq logarg) >>;
  logarg:=numr logarg;
  logs:= 1 ./ 1;
  while pairp logarg do <<
        if ldeg logarg neq 1 then interr "what a log";
        if atom mvar logarg then interr "what a log";
        if car mvar logarg neq 'log then interr "what a log";
        logs:=!*multsq(logs,
                       !*exptsq(simp!* argof mvar logarg,lc logarg));
        logarg:=red logarg >>;
  logs:=rationalizesq logs;
  ans:=multsq(!*multsq(car parts,logs),1 ./ dencoef); % real part
  % Now to apply theory i*log(a+i*b) = atan(a/b) + (i/2 log (a^2+b^2))
  lparts:=split!-real!-imag numr logs;
  if numr difff(denr cdr lparts,intvar)
    then interr "unexpected denominator";
  lparts:=!*multsq(denr cdr lparts ./ 1,car lparts) . cdr lparts;
  if not onep denr car lparts then interr "unexpected denominator";
  % We have discarded the logarithm of a constant: good riddance
  trueimag:=quotsq(addf(!*exptf(numr car lparts,2),
                        !*exptf(numr cdr lparts,2)) ./ 1,
                   !*exptf(denr logs,2) ./ 1);
  if numr diffsq(trueimag,intvar)
     then ans:=!*addsq(ans,
                     !*multsq(gaussiani ./ multf(2,dencoef),
                              !*multsq(simplogsq trueimag,cdr parts)));
  trueimag:=!*multsq(car lparts,!*invsq(numr cdr lparts ./ 1));
  if numr diffsq(trueimag,intvar)
     then ans:=!*addsq(ans,!*multsq(!*multsq(cdr parts,1 ./ dencoef),
                                  !*k2q list('atan,prepsq!* trueimag)));
  return ans;
  end;

symbolic procedure split!-real!-imag sf;
   % Returns coef real.imag as SQs.
 if null sf then (lambda z; z . z) (nil ./ 1)
  else if numberp sf then (sf ./ 1) . (nil ./ 1)
  else if domainp sf then interr "can't handle arbitrary domains"
  else begin
    scalar cparts,rparts,mv,tmp;
    cparts:=split!-real!-imag lc sf;
    rparts:=split!-real!-imag red sf;
    mv:=split!-real!-imagvar mvar sf;
    if null numr cdr mv % main variable totally real
       then <<
          tmp:= lpow sf .* 1 .+ nil ./ 1;
          return !*addsq(!*multsq(car cparts,tmp),car rparts) .
                 !*addsq(!*multsq(cdr cparts,tmp),cdr rparts) >>;
    if null numr car mv then <<
       mv:=!*exptsq(cdr mv,ldeg sf);
       % deal with powers of i
       if not evenp(ldeg sf / 2) then mv:=negsq mv;
       if not evenp ldeg sf
         then return !*addsq(!*multsq(negsq cdr cparts,mv),car rparts) .
                     !*addsq(!*multsq(car cparts,mv),cdr rparts)
         else return !*addsq(!*multsq(car cparts,mv),car rparts) .
                     !*addsq(!*multsq(cdr cparts,mv),cdr rparts) >>;
    % Now we have to handle the general case.
    cparts:=mul!-complex(cparts,exp!-complex(mv,ldeg sf));
    return !*addsq(car cparts,car rparts) .
                   !*addsq(cdr cparts, cdr rparts)
    end;

symbolic procedure mul!-complex(a,b);
!*addsq(!*multsq(negsq cdr a,cdr b),!*multsq(car a,car b)) .
!*addsq(!*multsq(car a,cdr b),!*multsq(cdr a,car b));

symbolic procedure exp!-complex(a,n);
if n=1 then a
   else if evenp n then exp!-complex(mul!-complex(a,a),n/2)
   else mul!-complex(a,exp!-complex(mul!-complex(a,a),n/2));

symbolic procedure split!-real!-imagvar mv;
   % Returns a pair of sf.
 if mv eq 'i then (nil ./ 1) . (1 ./ 1)
   else if atom mv then (mv .** 1 .* 1 .+ nil ./ 1) . (nil ./ 1)
   else if car mv eq 'sqrt then begin
             scalar n,rp,innersqrt,c;
             n:=simp!* argof mv;
             if denr n neq 1 then interr "unexpected denominator";
             rp:=split!-real!-imag numr n;
             if null numr cdr rp and minusf numr car rp and
                null involvesf(numr car rp,intvar) then
                return (nil ./ 1) . simpsqrtsq negsq car rp;
             if null numr cdr rp
                then return (mv .** 1 .* 1 .+ nil ./ 1) . (nil ./ 1);
                            % totally real.
   % OK - it's a general (ish) complex number A+iB
   % its square root is going to be C+iD where
   % C^2 = (A+sqrt(A^2+B^2))/2 (+ve sign of sqrt to make C +ve)
   % C is square root of this
   % D is C * (sqrt(A(2+B^2) -A)/B
   % Note that D has a non-trivial denominator. We could avoid this at
   % the cost of generating non-independent square roots (yuck).
   % Note that the above checks have ensured this den. is non-zero.
              if numr car rp then
                 innersqrt:=simpsqrtsq !*addsq(!*exptsq(car rp,2),
                                               !*exptsq(cdr rp,2))
                 else innersqrt:=cdr rp; % pure imaginary case
              c:=simpsqrtsq multsq(!*addsq(car rp, innersqrt), 1 ./ 2);
              return c . !*multsq(!*multsq(c,!*invsq cdr rp),
                                  !*addsq(innersqrt,negsq car rp));
        end
   else (mv .** 1 .* 1 .+ nil ./ 1) . (nil ./ 1);
        % What the heck: pretend it's real.

endmodule;


module maninp;

% Author: James H. Davenport.

fluid '(intvar);

symbolic procedure findmaninparm places;
begin
  scalar sqrts,vars,u;
  sqrts:=sqrtsinplaces places;
loop:
  if null sqrts then return nil;
  vars:=getvariables simp argof car sqrts;
innerloop:
  if null vars
    then <<
      sqrts:=cdr sqrts;
      go to loop >>;
  u:=car vars;
  vars:=cdr vars;
  if u eq intvar
    then go to innerloop;
  if atom u
    then return u;
  if car u eq 'sqrt
    then << u:=simp argof u;
            vars:=varsinsf(numr u,varsinsf(denr u,vars));
            go to innerloop >>;
  interr "Unrecognised differentiation candidate"
  end;

endmodule;


module modify;

% Author: James H. Davenport.

fluid '(!*tra intvar);

exports modify!-sqrts,combine!-sqrts;

symbolic procedure modify!-sqrts(basis,sqrtl);
begin
  scalar sqrtl!-in!-sf,n,u,v,f;
  n:=upbv basis;
  sqrtl!-in!-sf:=for each u in sqrtl collect
                    !*q2f simp argof u;
  for i:=0:n do begin
    u:=getv(basis,i);
    v:=sqrtsinsq(u,intvar);
    % We have two tasks to perform,
    % the replacing of SQRT(A)*SQRT(B) by SQRT(A*B)
    % where relevant and the replacing of SQRT(A)
    % by SQRT(A*B) or 1 (depending on whether it occurs in
    % the numerator or the denominator).
    v:=setdiff(v,sqrtl);
    if null v
      then go to nochange;
    u:=sqrt2top u;
    u:=multsq(modify2(numr u,v,sqrtl!-in!-sf) ./ 1,
              1 ./ modify2(denr u,v,sqrtl!-in!-sf));
    v:=sqrtsinsq(u,intvar);
    v:=setdiff(v,sqrtl);
    if v then <<
      if !*tra then <<
        printc "Discarding element";
        printsq u >>;
      putv(basis,i,1 ./ 1) >>
      else putv(basis,i,removecmsq u);
    f:=t;
  nochange:
    end;
  basis:=mkuniquevect basis;
  if f and !*tra then <<
    printc "Basis replaced by";
    mapvec(basis,function printsq) >>;
  return basis
  end;


symbolic procedure combine!-sqrts(basis,sqrtl);
begin
  scalar sqrtl!-in!-sf,n,u,v,f;
  n:=upbv basis;
  sqrtl!-in!-sf:=for each u in sqrtl collect
                    !*q2f simp argof u;
  for i:=0:n do begin
    u:=getv(basis,i);
    v:=sqrtsinsq(u,intvar);
    % We have one task to perform,
    % the replacing of SQRT(A)*SQRT(B) by SQRT(A*B)
    % where relevant.
    v:=setdiff(v,sqrtl);
    if null v
      then go to nochange;
    u:=multsq(modify2(numr u,v,sqrtl!-in!-sf) ./ 1,
              1 ./ modify2(denr u,v,sqrtl!-in!-sf));
    putv(basis,i,u);
    f:=t;
  nochange:
    end;
  if f and !*tra then <<
    printc "Basis replaced by";
    mapvec(basis,function printsq) >>;
  return basis
  end;


symbolic procedure modify2(sf,sqrtsin,realsqrts);
if atom sf
  then sf
  else if atom mvar sf
    then sf
    else if eqcar(mvar sf,'sqrt) and dependsp(mvar sf,intvar)
      then begin
        scalar u,v,w,lcsf,sqrtsin2,w2,lcsf2,temp;
        u:=!*q2f simp argof mvar sf;
        v:=realsqrts;
        while v and null (w:=modify!-quotf(car v,u))
          do v:=cdr v;
        if null v
          then <<
            if !*tra then <<
              printc "Unable to modify (postponed)";
              printsf !*kk2f mvar sf >>;
            return sf >>;
        v:=car v;
        % We must modify SQRT(U) into SQRT(V) if possible.
        lcsf:=lc sf;
        sqrtsin2:=delete(mvar sf,sqrtsin);
        while sqrtsin2 and (w neq 1) do <<
          temp:=!*q2f simp argof car sqrtsin2;
          if (w2:=modify!-quotf(w,temp)) and
             (lcsf2:=modify!-quotf(lcsf,!*kk2f car sqrtsin2))
            then <<
              w:=w2;
              lcsf:=lcsf2 >>;
          sqrtsin2:=cdr sqrtsin2 >>;
        if w = 1
          then return addf(multf(lcsf,formsqrt v),
                           modify2(red sf,sqrtsin,realsqrts));
                           % It is important to use FORMSQRT here since
                           % SIMPSQRT will recreate the factorisation
                           % we are trying to destroy.
          % Satisfactorily explained away.
        return addf(multf(!*p2f lpow sf,
                          modify2(lc sf,sqrtsin,realsqrts)),
                    modify2(red sf,sqrtsin,realsqrts))
        end
      else addf(multf(!*p2f lpow sf,
                      modify2(lc sf,sqrtsin,realsqrts)),
                modify2(red sf,sqrtsin,realsqrts));



%symbolic procedure modifydown(sf,sqrtl);
%if atom sf
%  then sf
%  else if atom mvar sf
%    then sf
%    else if eqcar(mvar sf,'sqrt) and
%            dependsp(mvar sf,intvar) and
%           not member(!*q2f simp argof mvar sf,sqrtl)
%      then addf(modifydown(lc sf,sqrtl),
%                modifydown(red sf,sqrtl))
%      else addf(multf(!*p2f lpow sf,
%                      modifydown(lc sf,sqrtl)),
%                modifydown(red sf,sqrtl));


% symbolic procedure modifyup(sf,sqrtl);
% if atom sf
%   then sf
%   else if atom mvar sf
%     then sf
%     else if eqcar(mvar sf,'sqrt) and
%             dependsp(mvar sf,intvar)
%       then begin
%         scalar u,v;
%         u:=!*q2f simp argof mvar sf;
%         if u member sqrtl
%         then return addf(multf(!*p2f lpow sf,
%                                 modifyup(lc sf,sqrtl)),
%                           modifyup(red sf,sqrtl));
%        v:=sqrtl;
%        while v and not modify!-quotf(car v,u)
%          do v:=cdr v;
%        if null v
%          then interr "No sqrt to upgrade to";
%       return addf(multf(!*kk2f simpsqrt2 car v,
%                          modifyup(lc sf,sqrtl)),
%                    modifyup(red sf,sqrtl))
%        end
%      else addf(multf(!*p2f lpow sf,
%                      modifyup(lc sf,sqrtl)),
%                modifyup(red sf,sqrtl));


symbolic procedure modify!-quotf(u,v);
% Replacement for quotf, in that it gets sqrts right.
if atom v or atom mvar v
  then quotf(u,v)
  else if u=v then 1
  else begin
    scalar sq;
    sq:=sqrt2top(u ./ v);
    if involvesf(denr sq,intvar)
      then return nil;
    if not onep denr sq
      then if not numberp denr sq
        then interr "Gauss' lemma violated in modify"
        else if !*tra
          then <<
            printc "*** Denominator ignored in modify";
            printc denr sq >>;
    return numr sq
    end;

endmodule;


module modlineq;

% Author: James H. Davenport.

fluid '(!*tra !*trmin current!-modulus sqrts!-mod!-prime);

global '(list!-of!-medium!-primes sqrts!-mod!-8);

exports check!-lineq;

list!-of!-medium!-primes:='(101 103 107 109);

sqrts!-mod!-8:=mkvect 7;

putv(sqrts!-mod!-8,0,t);

putv(sqrts!-mod!-8,1,t);

putv(sqrts!-mod!-8,4,t);

symbolic procedure modp!-nth!-root(m,n,p);
begin
  scalar j,p2;
  p2:=p/2;
  for i:=-p2 step 1 until p2 do
    if modular!-expt(i,n) iequal m
      then << j:=i; i:=p2 >>;
  return j
  end;


symbolic procedure modp!-sqrt(n,p);
begin
  scalar p2,s,tt;
  p2:=p/2;
  if n < 0
    then n:=n+p;
  for i:=0:p2 do begin
    tt:=n+p*i;
    if null getv(sqrts!-mod!-8,iremainder(tt,8))
      then return;
      % mod 8 test for perfect squares.
    if (iadd1 iremainder(tt,5)) > 2
      then return;
      % squares are -1,0,1 mod 5.
    s:=int!-sqrt tt;
    if fixp s then <<
      p2:=0;
      return >>
    end;
  if (not fixp s) or null s
    then return nil
    else return s
  end;

symbolic procedure subsetp(a,b);
%True if all members of a are also members of b.
    if null a then t
    else if member(car a,b) then subsetp(cdr a,b)
    else nil;

symbolic procedure check!-lineq(m,rightside);
begin
  scalar vlist,n1,n2,u,primelist,m1,v,modp!-subs,atoms;
  n1:=upbv m;
  for i:=0:n1 do <<
    u:=getv(m,i);
    if u
      then for j:=0:(n2:=upbv u) do
        vlist:=varsinsq(getv(u,j),vlist) >>;
  u:=vlist;
  while u do <<
    v:=car u;
    u:=cdr u;
    if atom v
      then atoms:=v.atoms
      else if (car v eq 'sqrt) or (car v eq 'expt)
    then for each w in varsinsf(!*q2f simp argof v,nil) do
             if not (w member vlist)
               then <<
                 u:=w.u;
                 vlist:=w.vlist >>
        else nil
      else interr "Unexpected item" >>;
  if sqrts!-mod!-prime and
     subsetp(vlist,for each u in cdr sqrts!-mod!-prime
                     collect car u)
    then go to end!-of!-loop;
  vlist:=setdiff(vlist,atoms);
  u:=nil;
  for each v in vlist do
    if car v neq 'sqrt
      then u:=v.u;
  vlist:=nconc(u,sortsqrts(setdiff(vlist,u),nil));
    % NIL is the variable to measure nesting on:
    % therefore all nesting is being caught.
  primelist:=list!-of!-medium!-primes;
  set!-modulus car primelist;
  atoms:=for each u in atoms collect
       u . modular!-number random car primelist;
  goto try!-prime;
next!-prime:
  primelist:=cdr primelist;
  if null primelist and !*tra
    then printc "Ran out of primes in check!-lineq";
  if null primelist
    then return t;
  set!-modulus car primelist;
try!-prime:
  modp!-subs:=atoms;
  v:=vlist;
loop:
  if null v
    then go to end!-of!-loop;
  u:=modp!-subst(simp argof car v,modp!-subs);
  if caar v eq 'sqrt
    then u:=modp!-sqrt(u,car primelist)
    else if caar v eq 'expt
      then u:=modp!-nth!-root(modular!-expt(u,cadr caddr car v),
        caddr caddr car v,car primelist)
      else interr "Unexpected item";
  if null u
    then go to next!-prime;
  modp!-subs:=(car v . u) . modp!-subs;
  v:=cdr v;
  go to loop;
end!-of!-loop:
  if null primelist
    then <<
      setmod(car sqrts!-mod!-prime);
      modp!-subs:=cdr sqrts!-mod!-prime >>
    else sqrts!-mod!-prime:=(car primelist).modp!-subs;
  m1:=mkvect n1;
  for i:=0:n1 do begin
    u:=getv(m,i);
    if null u
      then return;
    putv(m1,i,v:=mkvect n2);
    for j:=0:n2 do
      putv(v,j,modp!-subst(getv(u,j),modp!-subs))
    end;
  v:=mkvect n1;
  for i:=0:n1 do
    putv(v,i,modp!-subst(getv(rightside,i),modp!-subs));
  u:=mod!-jhdsolve(m1,v);
  if (u eq 'failed) and (!*tra or !*trmin)
    then <<
      princ "Proved insoluble mod ";
      printc car sqrts!-mod!-prime >>;
  return u
  end;

symbolic procedure varsinsq(sq,vl);
  varsinsf(numr sq,varsinsf(denr sq,vl));

symbolic procedure modp!-subst(sq,slist);
modular!-quotient(modp!-subf(numr sq,slist),
          modp!-subf(denr sq,slist));


symbolic procedure modp!-subf(sf,slist);
if atom sf
  then if null sf
    then 0
    else modular!-number sf
  else begin
    scalar u;
    u:=assoc(mvar sf,slist);
    if null u
      then interr "Unexpected variable";
    return modular!-plus(modular!-times(modular!-expt(cdr u,ldeg sf),
                    modp!-subf(lc sf,slist)),
             modp!-subf(red sf,slist))
    end;


symbolic procedure mod!-jhdsolve(m,rightside);
% Returns answer to m.answer=rightside.
% Matrix m not necessarily square.
begin
  scalar ii,n1,n2,ans,u,row,swapflg,swaps;
  % The SWAPFLG is true if we have changed the order of the
  % columns and need later to invert this via SWAPS.
  n1:=upbv m;
  for i:=0:n1 do
    if (u:=getv(m,i))
      then (n2:=upbv u);
  swaps:=mkvect n2;
  for i:=0:n2 do
    putv(swaps,i,n2-i);
    % We have the SWAPS vector, which should be a vector of indices,
    % arranged like this because VECSORT sorts in decreasing order.
  for i:=0:isub1 n1 do begin
    scalar k,v,pivot;
  tryagain:
    row:=getv(m,i);
    if null row
      then go to interchange;
    % look for a pivot in row.
    k:=-1;
    for j:=0:n2 do
      if (pivot:=getv(row,j)) neq 0
        then <<
          k:=j;
          j:=n2 >>;
    if k neq -1
      then goto newrow;
    if getv(rightside,i) neq 0
      then <<
        m:='failed;
    i:=sub1 n1; %Force end of loop.
        go to finished >>;
interchange:
    % now interchange i and last element.
    swap(m,i,n1);
    swap(rightside,i,n1);
    n1:=isub1 n1;
    if i iequal n1
      then goto finished
      else goto tryagain;
  newrow:
    if i neq k
      then <<
        swapflg:=t;
        swap(swaps,i,k);
      % record what we have done.
        for l:=0:n1 do
          swap(getv(m,l),i,k) >>;
    % place pivot on diagonal.
    pivot:=modular!-minus modular!-reciprocal pivot;
    for j:=iadd1 i:n1 do begin
      u:=getv(m,j);
      if null u
        then return;
      v:=modular!-times(getv(u,i),pivot);
      if v neq 0 then <<
        putv(rightside,j,
        modular!-plus(getv(rightside,j),
        modular!-times(v,getv(rightside,i))));
        for l:=0:n2 do
          putv(u,l,
         modular!-plus(getv(u,l),
         modular!-times(v,getv(row,l)))) >>
      end;
  finished:
    end;
  if m eq 'failed
    then go to failed;
    % Equations were inconsistent.
  while null (row:=getv(m,n1)) do
    n1:=isub1 n1;
  u:=nil;
  for i:=0:n2 do
    if getv(row,i) neq 0 then u:='t;
  if null u
    then if getv(rightside,n1) neq 0
      then go to failed
      else n1:=isub1 n1;
      % Deals with a last equation which is all zero.
  if n1 > n2
    then go to failed;
    % Too many equations to satisfy.
  ans:=mkvect n2;
  for i:=0:n2 do
    putv(ans,i,0);
  % now to do the back-substitution.
  % Note that the system is not necessarily square.
  ii:=n2;
  for i:=n1 step -1 until 0 do begin
    row:=getv(m,i);
    while getv(row,ii) = 0 do ii:=isub1 ii;
    if null row
      then return;
    u:=getv(rightside,i);
    for j:=iadd1 ii:n2 do
      u:=modular!-plus(u,
     modular!-times(getv(row,j),modular!-minus getv(ans,j)));
    putv(ans,ii,modular!-times(u,modular!-reciprocal getv(row,ii)));
    ii:=isub1 ii;
    end;
  if swapflg
    then vecsort(swaps,list ans);
  return ans;
failed:
  if !*tra
    then printc "Unable to force correct zeroes";
  return 'failed
  end;

endmodule;


module nagell;

% Author: James H. Davenport.

fluid '(!*tra !*trmin intvar);

exports lutz!-nagell;

symbolic procedure lutz!-nagell(divisor);
begin
  scalar ans,places,mults,save!*tra;
  for each u in divisor do <<
    places:=(car u).places;
    mults :=(cdr u).mults >>;
  ans:=lutz!-nagell!-2(places,mults);
  if ans eq 'infinite
     then return 'provably!-impossible;
  save!*tra:=!*tra;
  if !*trmin
    then !*tra:=nil;
  ans:=coates!-multiple(places,mults,ans);
  !*tra:=save!*tra;
  return ans
  end;


symbolic procedure lutz!-nagell!-2(places,mults);
begin
  scalar wst,x,y,equation,point,a;
  wst:=weierstrass!-form getsqrtsfromplaces places;
  x:=car wst;
  y:=cadr wst;
  equation:=caddr wst;
  equation:=!*q2f !*multsq(equation,equation);
  equation:=makemainvar(equation,intvar);
  if ldeg equation = 3
    then equation:=red equation
    else interr "Equation not of correct form";
  if mvar equation eq intvar
    then if ldeg equation = 1
      then <<
        a:=(lc equation) ./ 1;
        equation:=red equation >>
      else interr "Equation should not have a x**2 term"
    else a:=nil ./ 1;
  equation:= a . (equation ./ 1);
  places:=for each u in places collect
        wst!-convert(u,x,y);
  point:=elliptic!-sum(places,mults,equation);
  a:=lutz!-nagell!-bound(point,equation);
  if !*tra or !*trmin then <<
    princ "Point actually is of order ";
    printc a >>;
  return a
  end;


symbolic procedure wst!-convert(place,x,y);
begin
  x:=subzero(xsubstitutesq(x,place),intvar);
  y:=subzero(xsubstitutesq(y,place),intvar);
  return x.y
  end;


symbolic procedure elliptic!-sum(places,mults,equation);
begin
  scalar point;
  point:=elliptic!-multiply(car places,car mults,equation);
  places:=cdr places;
  mults:=cdr mults;
  while places do <<
    point:=elliptic!-add(point,
             elliptic!-multiply(car places,car mults,
                        equation),
                         equation);
    places:=cdr places;
    mults:=cdr mults >>;
  return point
  end;


symbolic procedure elliptic!-multiply(point,n,equation);
if n < 0
  then elliptic!-multiply( (car point) . (negsq cdr point),
                           -n,
                           equation)
  else if n = 0
    then interr "N=0 in elliptic!-multiply"
    else if n = 1
      then point
      else begin
        scalar q,r;
        q:=divide(n,2);
        r:=cdr q;
        q:=car q;
    q:=elliptic!-multiply(elliptic!-add(point,point,equation),q,
                        equation);
        if r = 0
          then return q
      else return elliptic!-add(point,q,equation)
        end;


symbolic procedure elliptic!-add(p1,p2,equation);
begin
  scalar x1,x2,y1,y2,x3,y3,inf,a,b,lhs,rhs;
  a:=car equation;
  b:=cdr equation;
  inf:=!*kk2q 'infinity;
  x1:=car p1;
  y1:=cdr p1;
  x2:=car p2;
  y2:=cdr p2;
  if x1 = x2
    then if y1 = y2
      then <<
    % this is the doubling case.
    x3:=!*multsq(!*addsq(!*addsq(!*multsq(a,a),
                     !*exptsq(x1,4)),
                 !*addsq(multsq(-8 ./ 1,!*multsq(x1,b)),
                     !*multsq(!*multsq(x1,x1),
                                              multsq(-2 ./ 1,a)))),
             !*invsq multsq(4 ./ 1,
              !*addsq(b,!*multsq(x1,!*addsq(a,
                           !*exptsq(x1,2))))));
    y3:=!*addsq(y1,!*multsq(!*multsq(!*addsq(x3,negsq x1),
                     !*addsq(a,multsq(3 ./ 1,
                             !*multsq(x1,x1)))),
                 !*invsq multsq(2 ./ 1,
                                                y1))) >>
      else x3:=(y3:=inf)
    else if x1 = inf
      then <<
        x3:=x2;
        y3:=y2 >>
      else if x2 = inf
        then <<
          x3:=x1;
          y3:=y1 >>
        else <<
      x3:=!*multsq(!*addsq(!*multsq(a,!*addsq(x1,x2)),
                   !*addsq(multsq(2 ./ 1,b),
                       !*addsq(!*multsq(!*multsq(x1,x2),
                            !*addsq(x1,x2)),
                                               multsq(-2 ./ 1,
                            !*multsq(y1,y2))))),
               !*invsq !*exptsq(!*addsq(x1,negsq x2),2));
      y3:=!*multsq(!*addsq(!*multsq(!*addsq(y2,negsq y1),x3),
                   !*addsq(!*multsq(x2,y1),
                       !*multsq(x1,negsq y2))),
               !*invsq !*addsq(x1,negsq x2)) >>;
  if x3 = inf
    then return x3.y3;
  lhs:=!*multsq(y3,y3);
  rhs:=!*addsq(b,!*multsq(x3,!*addsq(a,!*multsq(x3,x3))));
  if numr !*addsq(lhs,negsq rhs) % We can't just compare them
                  % since they're algebraic numbers.
                  % JHD Jan 14th. 1987.
    then <<
      prin2t "Point defined by X and Y as follows:";
      printsq x3;
      printsq y3;
      prin2t "on the curve defined by A and B as follows:";
      printsq a;
      printsq b;
      prin2t "gives a consistency check between:";
      printsq lhs;
      printsq rhs;
      interr "Consistency check failed in elliptic!-add" >>;
  return x3.y3
  end;




symbolic procedure infinitep u;
kernp u and (mvar numr u eq 'infinite);


symbolic procedure lutz!-nagell!-bound(point,equation);
begin
  scalar x,y,a,b,lutz!-alist,n,point2,p,l,ans;
    % THE LUTZ!-ALIST is an association list of elements of the form
    % [X-value].([Y-value].[value of N for this point])
    % See thesis, chapter 7, algorithm LUTZ!-NAGELL, step [1].
  x:=car point;
  y:=cdr point;
  if !*tra or !*trmin then <<
    printc "Point to have torsion investigated is";
    printsq x;
    printsq y >>;
  a:=car equation;
  b:=cdr equation;
  if denr y neq 1 then <<
    l:=denr y;
    % we can in fact make l an item whose cube is > denr y.
    y:=!*multsq(y,!*exptf(l,3) ./ 1);
    x:=!*multsq(x,!*exptf(l,2) ./ 1);
    a:=!*multsq(a,!*exptf(l,4) ./ 1);
    b:=!*multsq(b,!*exptf(l,6) ./ 1) >>;
  if denr x neq 1 then <<
    l:=denr x;
    % we can in fact make l an item whose square is > denr x.
    y:=!*multsq(y,!*exptf(l,3) ./ 1);
    x:=!*multsq(x,!*exptf(l,2) ./ 1);
    a:=!*multsq(a,!*exptf(l,4) ./ 1);
    b:=!*multsq(b,!*exptf(l,6) ./ 1) >>;
  % we now have integral co-ordinates for x,y.
  lutz!-alist:=list (x . (y . 0));
  if (x neq car point) and (!*tra or !*trmin) then <<
    printc "Point made integral as ";
    printsq x;
    printsq y;
    printc "on the curve with coefficients";
    printsq a;
    printsq b >>;
  point:=x.y;
  equation:=a.b;
  n:=0;
loop:
  n:=n+1;
  point2:=elliptic!-multiply(x.y,2,equation);
  x:=car point2;
  y:=cdr point2;
  if infinitep x
    then return 2**n;
  if denr x neq 1
    then go to special!-denr;
  if a:=assoc(x,lutz!-alist)
    then if y = cadr a
      then return (ans:=lutz!-reduce(point,equation,2**n-2**(cddr a)))
      else if null numr !*addsq(y,cadr a)
    then return (ans:=lutz!-reduce(point,equation,2**n+2**(cddr a)))
    else interr "Cannot have 3 points here";
  lutz!-alist:=(x.(y.n)).lutz!-alist;
  if ans
    then return ans;
  go to loop;
special!-denr:
  p:=denr x;
  if not primep p
    then return 'infinite;
  n:=1;
  n:=1;
loop2:
  point:=elliptic!-multiply(point,p,equation);
  n:=n*p;
  if infinitep car point
    then return n;
  if quotf(p,denr car point)
    then go to loop2;
  return 'infinite
  end;


symbolic procedure lutz!-reduce(point,equation,power);
begin
  scalar n;
  if !*tra or !*trmin then <<
    princ "Point is of order dividing ";
    printc power >>;
  n:=1;
  while evenp power do <<
    power:=power/2;
    n:=n*2;
    point:=elliptic!-add(point,point,equation) >>;
    % we know that all the powers of 2 must appear in the answer.
  if power = 1
    then return n;
  if primep power
    then return n*power;
  return n*lutz!-reduce2(point,equation,power,3)
  end;



symbolic procedure lutz!-reduce2(point,equation,power,prime);
if power = 1
  then if infinitep car point
    then 1
    else nil
  else if infinitep car point
    then power
    else begin
      scalar n,prime2,u,ans;
      n:=0;
      while cdr divide(power,prime)=0 do <<
        n:=n+1;
        power:=power/prime >>;
      prime2:=nextprime prime;
      for i:=0:n do <<
    u:=lutz!-reduce2(point,equation,power,prime2);
        if u
          then <<
              ans:=u*prime**i;
              i:=n >>
         else <<
          power:=power*prime;
      point:=elliptic!-multiply(point,prime,equation) >> >>;
      if ans
        then return ans
        else return nil
      end;

endmodule;


module nbasis;

% Author: James H. Davenport.

fluid '(!*tra nestedsqrts sqrt!-intvar taylorasslist);

exports normalbasis;
imports substitutesq,taylorform,printsq,newplace,sqrtsinsq,union,
        sqrtsign,interr,vecsort,mapvec,firstlinearrelation,mksp,multsq,
        !*multsq,addsq,removecmsq,antisubs,involvesq;


symbolic procedure normalbasis(zbasis,x,infdegree);
begin
  scalar n,nestedsqrts,sqrts,u,v,w,li,m,lam,i,inf,basis,save;
  save:=taylorasslist;
  inf:=list list(x,'quotient,1,x);
  n:=upbv zbasis;
  basis:=mkvect n;
  lam:=mkvect n;
  m:=mkvect n;
  goto  a;
square:
  sqrts:=nil;
  inf:=append(inf,list list(x,'expt,x,2));
  % we were in danger of getting sqrt(x) where we didnt want it.
a:
  newplace(inf);
  for i:=0:n do <<
    v:=substitutesq(getv(zbasis,i),inf);
    putv(basis,i,v);
    sqrts:=union(sqrts,sqrtsinsq(v,x)) >>;
  if !*tra then <<
    princ "Normal integral basis reduction with the";
    prin2t " following sqrts lying over infinity:";
    superprint sqrts >>;
  if member(list('sqrt,x),sqrts)
    then goto square;
  sqrts:=sqrtsign(sqrts,x);
  if iadd1 n neq length sqrts
    then interr "Length mismatch in normalbasis";
  for i:=0:n do <<
    v:=cl8roweval(getv(basis,i),sqrts);
    putv(m,i,cdr v);
    putv(lam,i,car v) >>;
reductionloop:
  vecsort(lam,list(basis,m));
  if !*tra then <<
    prin2t "Matrix before a reduction step at infinity is:";
    mapvec(m,function prin2t) >>;
  v:=firstlinearrelation(m,iadd1 n);
  if null v
    then goto ret;
  i:=n;
  while null numr getv(v,i) do
    i:=isub1 i;
  li:=getv(lam,i);
  w:=nil ./ 1;
  for j:=0:i do
    w:=!*addsq(w,!*multsq(getv(basis,j),
                 multsq(getv(v,j),1 ./  !*fmksp(x,-li+getv(lam,j)) )));
           % note the change of sign. my x is coates 1/x at this point!.
  if !*tra then <<
    princ "Element ";
    princ i;
    prin2t " replaced by the function printed below:" >>;
  w:=removecmsq w;
  putv(basis,i,w);
  w:=cl8roweval(w,sqrts);
  if car w <= li
    then interr "Normal basis reduction did not work";
  putv(lam,i,car w);
  putv(m,i,cdr w);
  goto reductionloop;
ret:
  newplace list (x.x);
  u:= 1 ./ !*p2f mksp(x,1);
  inf:=antisubs(inf,x);
  u:=substitutesq(u,inf);
  m:=nil;
  for i:=0:n do begin
    v:=getv(lam,i)-infdegree;
    if v < 0
      then goto next;
    w:=substitutesq(getv(basis,i),inf);
    for j:=0:v do <<
      if not involvesq(w,sqrt!-intvar)
        then m:=w.m;
      w:=!*multsq(w,u) >>;
  next:
    end;
  tayshorten save;
  return m
  end;


symbolic procedure !*fmksp(x,i);
% sf for x**i.
if i iequal 0
  then 1
  else !*p2f mksp(x,i);


symbolic procedure cl8roweval(basiselement,sqrts);
begin
  scalar lam,row,i,v,minimum,n;
  n:=isub1 length sqrts;
  lam:=mkvect n;
  row:=mkvect n;
  i:=0;
  minimum:=1000000;
  while sqrts do <<
    v:=taylorform substitutesq(basiselement,car sqrts);
    v:=assoc(taylorfirst v,taylorlist v);
    putv(row,i,cdr v);
    v:=car v;
    putv(lam,i,v);
    if v < minimum
      then minimum:=v;
    i:=iadd1 i;
    sqrts:=cdr sqrts >>;
  if !*tra then <<
    princ "Evaluating ";
    printsq basiselement;
    prin2t lam;
    prin2t row >>;
  v:=1000000;
  for i:=0:n do <<
    v:=getv(lam,i);
    if v > minimum
      then putv(row,i,nil ./ 1) >>;
  return minimum.row
  end;

endmodule;


module places;

% Author: James H. Davenport.

fluid '(basic!-listofallsqrts
        basic!-listofnewsqrts
        intvar
        listofallsqrts
        listofnewsqrts
        sqrt!-intvar
        sqrt!-places!-alist
        sqrts!-in!-integrand);

exports getsqrtsfromplaces,sqrtsinplaces,get!-correct!-sqrts,basicplace,
        extenplace,equalplace,printplace;



% Function to manipulate places
% a place is stored as a list of substitutions
% substitutions (x.f(x)) define the algrbraic number
% of which this place is an extension,
% while places (f(x).g(x)) define the extension.
%    currently g(x( is list ('minus,f(x))
%       or similar,e.g. (sqrt(sqrt x)).(sqrt(-sqrt x)).



% Given a list of places, produces a list of all
% the SQRTs in it that depend on INTVAR.
symbolic procedure getsqrtsfromplaces places;
  % The following loop finds all the SQRTs for a basis,
  % taking account of BASICPLACEs.
begin
  scalar basis,v,b,c,vv;
  for each u in places do <<
    v:=antisubs(basicplace u,intvar);
    vv:=sqrtsinsq (substitutesq(!*kk2q intvar,v),intvar);
      % We must go via SUBSTITUTESQ to get parallel
      % substitutions performed correctly.
    if vv
      then vv:=simp argof car vv;
    for each w in extenplace u do <<
      b:=substitutesq(simp lsubs w,v);
      b:=delete(sqrt!-intvar,sqrtsinsq(b,intvar));
      for each u in b do
        for each v in delete(u,b) do
          if dependsp(v,u)
            then b:=delete(u,b);
            % remove all the "inner" items, since they will
            % be accounted for anyway.
      if length b iequal 1
        then b:=car b
 else b:=mvar numr simpsqrtsq mapply(function !*multsq,
                                for each u in b collect simp argof u);
      if vv and not (b member sqrts!-in!-integrand)
        then <<
          c:=numr multsq(simp argof b,vv);
          c:=car sqrtsinsf(simpsqrt2 c,nil,intvar);
   if c member sqrts!-in!-integrand
            then b:=c >>;
      if not (b member basis)
        then basis:=b.basis >> >>;
  % The following loop deals with the annoying case of, say,
  % (X DIFFERENCE X 1) (X EXPT X 2) which should give rise to
  % SQRT(X-1).
  for each u in places do begin
    v:=cdr u;
    if null v or (car rfirstsubs v neq 'expt)
      then return;
    u:=simp!* subst(list('minus,intvar),intvar,rfirstsubs u);
    while v and (car rfirstsubs v eq 'expt) do <<
      u:=simpsqrtsq u;
      v:=cdr v;
      basis:=union(basis,delete(sqrt!-intvar,sqrtsinsq(u,intvar))) >>
    end;
  return remove!-extra!-sqrts basis
  end;



symbolic procedure sqrtsinplaces u;
% Note the difference between this procedure and
% the previous one: this one does not take account
% of the BASICPLACE component (& is pretty useless).
if null u
  then nil
  else sqrtsintree(for each v in car u collect lsubs v,
                   intvar,
                   sqrtsinplaces cdr u);



%symbolic procedure placesindiv places;
% Given a list of places (i.e. a divisor),
% produces a list of all the SQRTs on which the places
% explicitly depend.
%begin scalar v;
%  for each u in places do
%    for each uu in u do
%      if not (lsubs uu member v)
%        then v:=(lsubs uu) . v;
%  return v
%  end;



symbolic procedure get!-correct!-sqrts u;
% u is a basicplace.
begin
  scalar v;
  v:=assoc(u,sqrt!-places!-alist);
  if v
    then <<
      v:=cdr v;
      listofallsqrts:=cdr v;
      listofnewsqrts:=car v
      >>
    else <<
      listofnewsqrts:=basic!-listofnewsqrts;
      listofallsqrts:=basic!-listofallsqrts
      >>;
  return nil
  end;



%symbolic procedure change!-place(old,new);
%% old and new are basicplaces;
%begin
%  scalar v;
%  v:=assoc(new,sqrt!-places!-alist);
%  if v
%    then sqrtsave(cddr v,cadr v,old)
%    else <<
%      listofnewsqrts:=basic!-listofnewsqrts;
%      listofallsqrts:=basic!-listofallsqrts
%      >>;
%  return nil
%  end;



symbolic procedure basicplace(u);
% Returns the basic part of a place.
if null u
  then nil
  else if atom caar u
    then (car u).basicplace cdr u
    else nil;



symbolic procedure extenplace(u);
% Returns the extension part of a place.
if u and atom caar u
  then extenplace cdr u
  else u;



symbolic procedure equalplace(a,b);
% Sees if two extension places represent the same place or not.
if null a
  then if null b
    then t
    else nil
  else if null b
    then nil
    else if member(car a,b)
      then equalplace(cdr a,delete(car a,b))
      else nil;



symbolic procedure remove!-extra!-sqrts basis;
begin
  scalar basis2,save;
  save:=basis2:=for each u in basis collect !*q2f simp argof u;
  for each u in basis2 do
    for each v in delete(u,basis2) do
      if quotf(v,u)
        then basis2:=delete(v,basis2);
  if basis2 eq save
    then return basis
    else return for each u in basis2 collect list('sqrt,prepf u)
  end;



symbolic procedure printplace u;
begin
  scalar a,n,v;
  a:=rfirstsubs u;
  princ (v:=lfirstsubs u);
  princ "=";
  if atom a
    then princ "0"
    else if (car a eq 'quotient) and (cadr a=1)
      then princ "infinity"
      else <<
 n:=negsq addsq(!*kk2q v,negsq simp!* a);
% NEGSQ added JHD 22.3.87 - the previous value was wrong.
% If the substitution is (X-v) then this takes -v to 0,
% so the place was at -v.
        if (numberp numr n) and (numberp denr n)
          then <<
            princ numr n;
            if not onep denr n
              then <<
                princ " / ";
                princ denr n >> >>
          else <<
            if degreein(numr n,intvar) > 1
             then printc "Any root of:";
            printsq n;
            if cdr u
              then princ "at the place " >> >>;
  u:=cdr u;
  if null u
    then goto nl!-return;
  n:=1;
  while u and (car rfirstsubs u eq 'expt) do <<
    n:=n * caddr rfirstsubs u;
    u:=cdr u >>;
  if n neq 1 then <<
    terpri!* nil;
    prin2 " ";
    princ v;
    princ "=>";
    princ v;
    princ "**";
    princ n >>;
  while u do <<
    if car rfirstsubs u eq 'minus
      then princ "-"
      else princ "+";
    u:=cdr u >>;
nl!-return:
  terpri();
  return
  end;



symbolic procedure degreein(sf,var);
if atom sf
  then 0
  else if mvar sf eq var
    then ldeg sf
    else max(degreein(lc sf,var),degreein(red sf,var));

endmodule;


module precoats;

% Author: James H. Davenport.

fluid '(!*tra
        basic!-listofallsqrts
        basic!-listofnewsqrts
        sqrt!-intvar
        taylorvariable
        thisplace);

exports precoates;
imports mksp,algint!-subf,subzero2,substitutesq,removeduplicates,
        printsq,basicplace,extenplace,interr,get!-correct!-sqrts,
        printplace,simptimes,subzero,negsq,addsq,involvesq,taylorform,
        taylorevaluate,mk!*sq,!*exptsq,!*multsq,!*invsq,sqrt2top,
        jfactor,sqrtsave,antisubs;


symbolic procedure infsubs(w);
if caar w = thisplace
  then (cdar w).(cdr w)
  else (thisplace.(car w)).(cdr w);
% thisplace is (z quotient 1 z) so we are moving to infinity.


symbolic procedure precoates(residues,x,movedtoinfinity);
begin
  scalar answer,placeval,reslist,placelist,placelist2,thisplace;
  reslist:=residues;
  placelist:=nil;
  while reslist do <<
    % car reslist = <substitution list>.<value>;
    placeval:=algint!-subf((mksp(x,1) .* 1) .+ nil,caar reslist);
    if 0 neq cdar reslist
      then if null numr subzero2(denr placeval,x)
        then <<
          if null answer
            then answer:='infinity
            else if answer eq 'finite
              then answer:='mixed;
          if !*tra
            then printc "We have an residue at infinity" >>
        else <<
          if null answer
            then answer:='finite
            else if answer eq 'infinity
              then answer:='mixed;
          placelist:=placeval.placelist;
          if !*tra
            then printc "This is a finite residue" >>;
    reslist:=cdr reslist >>;
  if answer eq 'mixed
    then return answer;
  if answer eq 'infinity
    then <<
      thisplace:=list(x,'quotient,1,x);
      % maps x to 1/x.
      answer:=precoates(for each u in residues collect infsubs u,x,t);
                % derivative of 1/x is -1/x**2.
      if atom answer
        then return answer
        else return substitutesq(answer,list(thisplace)) >>;
  placelist2:=removeduplicates placelist;
  answer := 1 ./ 1;
  % the null divisor.
  if !*tra then <<
    printc "The divisor has elements at:";
    mapcar(placelist2,function printsq) >>;
  while placelist2 do begin
    scalar placelist3,extrasubs,u,bplace;
    % loop over all distinct places.
    reslist:=residues;
    placelist3:=placelist;
    placeval:=nil;
    while reslist do <<
      if car placelist2 = car placelist3
        then <<
          placeval:=(cdar reslist).placeval;
          thisplace:= caar reslist;
          % the substitutions defining car placelist.
          u:=caar reslist;
          bplace:=basicplace u;
          u:=extenplace u;
          extrasubs:=u.extrasubs >>;
      reslist:=cdr reslist;
      placelist3:=cdr placelist3 >>;
    % placeval is a list of all the residues at this place.
    if !*tra then <<
      princ "List of multiplicities at this place:";
      printc placeval;
      princ "with substitutions:";
      superprint extrasubs >>;
    if 0 neq mapply(function plus2,placeval)
      then interr "Divisor not effective";
    get!-correct!-sqrts bplace;
    u:=pbuild(x,extrasubs,placeval);
    sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,bplace);
    if atom u
      then <<
        placelist2:=nil;
        % set to terminate loop.
        answer:=u >>
      else <<
        answer:=substitutesq(!*multsq(answer,u),antisubs(thisplace,x));
        placelist2:=cdr placelist2 >>
    end;
    % loaded in pbuild to check for poles at the correct places.
  return answer
  end;



symbolic procedure dlist(u);
% Given a list of lists,converts to a list.
if null u
  then nil
  else if null car u
    then dlist cdr u
    else append(car u,dlist cdr u);


symbolic procedure debranch(extrasubs,reslist);
begin
  scalar substlist;
  % remove spurious substitutions.
  for each u in dlist extrasubs do
    if not ((car u) member substlist)
      then substlist:=(car u).substlist;
  % substlist is a list of all the possible substitutions).
  while substlist do
    begin scalar tsqrt,usqrt;
      scalar with1,with2,without1,without2,wres;
    scalar a1,a2,b1,b2;
    % decide if tsqrt is redundant.
    tsqrt:=car substlist;
    substlist:=cdr substlist;
    wres:=reslist;
    for each place in extrasubs do <<
      usqrt:=assoc(tsqrt,place);
        % usqrt is s.s' or s.(minus s').
      if null usqrt
        then interr "Places not all there";
      if cadr usqrt eq 'sqrt
        then<<
          with2:=(car wres).with2;
          with1:=delete(usqrt,place).with1>>
        else<<
          if not (cadr usqrt eq 'minus)
            then interr "Ramification format error";
          without2:=(car wres).without2;
          without1:=delete(usqrt,place).without1 >>;
      wres:=cdr wres>>;
    % first see if one item appears passim.
    if null with1
      then go to itswithout;
    if null without1
      then go to itswith;
    % Now must see if WITH2 matches WITHOUT2 in order WITH1/WITHOUT1.
    a1:=with1;
    a2:=with2;
  outerloop:
    b1:=without1;
    b2:=without2;
  innerloop:
    if (car a1) = (car b1)
      then << if (car a2) neq (car b2)
           then return nil
           else go to outeriterate >>;
    b1:=cdr b1;
    b2:=cdr b2;
    if null b1
      then return nil
      else go to innerloop;
      % null b1 => lists do not match at all.
  outeriterate:
    a1:=cdr a1;
    a2:=cdr a2;
    if a1
      then go to outerloop;
    if !*tra then <<
      princ "Residues reduce to:";
      printc without2;
      printc "at ";
      mapc(without1,function printplace) >>;
    extrasubs:=without1;
    reslist:=without2;
    return;
  itswithout:
    % everything is in the "without" list.
    with1:=without1;
    with2:=without2;
  itswith:
    % remove usqrt from the with lists.
    extrasubs:=for each u in with1 collect delete(assoc(tsqrt,u),u);
    if !*tra then <<
      printc "The following appears throughout the list ";
      printc tsqrt >>;
    reslist:=with2
    end;
  return extrasubs.reslist
  end;


symbolic procedure pbuild(x,extrasubs,placeval);
begin
  scalar multivals,u,v,answer;
  u:=debranch(extrasubs,placeval);
  extrasubs:=car u;
  placeval:=cdr u;
  % remove spurious entries.
  if (length car extrasubs) > 1
    then return 'difficult;
  % hard cases not allowed for.
  multivals:=mapcar(dlist extrasubs,function car);
  u:=simptimes removeduplicates multivals;
  answer:= 1 ./ 1;
    while extrasubs do <<
      v:=substitutesq(u,car extrasubs);
      v:=!*addsq(u,negsq subzero(v,x));
      v:=mkord1(v,x);
      if !*tra then <<
        princ "Required component is ";
        printsq v >>;
      answer:=!*multsq(answer,!*exptsq(v,car placeval));
      % place introduced with correct multiplicity.
      extrasubs:=cdr extrasubs;
      placeval:=cdr placeval >>;
  if length jfactor(denr sqrt2top !*invsq  answer,x) > 1
    then return 'many!-poles
    else return answer
  end;


symbolic procedure findord(v,x);
begin
  scalar nord,vd;
  %given v(x) with v(0)=0, makes v'(0) nonzero.
  nord:=0;
  taylorvariable:=x;
  while involvesq(v,sqrt!-intvar) do
    v:=substitutesq(v,list(x.list('expt,x,2)));
  vd:=taylorform v;
loop:
  nord:=nord+1;
  if null numr taylorevaluate(vd,nord)
    then go to loop;
  return nord
  end;


symbolic procedure mkord1(v,x);
begin
  scalar nord;
  nord:=findord(v,x);
  if nord iequal 1
    then return v;
  if !*tra then <<
    princ "Order reduction: ";
    printsq v;
    princ "from order ";
    princ nord;
    printc " to order 1" >>;
  % Note that here we do not need to simplify, since SIMPLOG will
  % remove all these SQRTs or EXPTs later.
  return !*p2q mksp(list('nthroot,mk!*sq v,nord),1)
  end;

endmodule;


module removecm;  % Routines to remove constant factors from expresions.

% Author: James H. Davenport.

fluid '(intvar);

% New improved REMOVECOMMOMMULTIPLES routines.
% These routines replace a straightforward pair with GCDF instead of
% CMGCDF and its associates.  The saving is large in complicated
% expressions (in the "general point of order 7" calculations, they
% exceeded 90% in some cases, being 1.5 secs as opposed to > 15 secs.).
% They are about 1K larger, but this seems a small price to pay.

exports removecmsq; % removeconstantsf;
imports ordop,addf,gcdn,gcdf,gcdk,involvesf,dependsp,makemainvar,quotf;

symbolic procedure removecmsq sq;
(removecmsf numr sq) ./ (removecmsf denr sq);

symbolic procedure removecmsf sf;
if atom sf or not ordop(mvar sf,intvar) or not involvesf(sf,intvar)
  then if sf
    then 1
    else nil
  else if null red sf
    then if dependsp(mvar sf,intvar)
      then (lpow sf .* removecmsf lc sf) .+ nil
      else removecmsf lc sf
    else begin
      scalar u,v;
      % The general principle here is to find a (non-INTVAR-depending)
      % coefficient of a purely INTVAR-depending monomial, and then
      % perform a g.c.d. to discover that factor of this which is a CM.
      u:=sf;
      while (v:=involvesf(u,intvar)) do u:=lc makemainvar(u,v);
      if u iequal 1
        then return sf;
      return quotf(sf,cmgcdf(sf,u))
      end;

symbolic procedure cmgcdf(sf,u);
if numberp u
  then if atom sf
    then if null sf
      then u
      else gcdn(sf,u)
    else if u = 1
      then 1
      else cmgcdf(red sf,cmgcdf(lc sf,u))
  else if atom sf
    then gcdf(sf,u)
    else if mvar u eq mvar sf
      then if ordop(intvar,mvar u)
        then gcdf(sf,u)
        else cmgcdf2(sf,u)
      else if ordop(mvar sf,mvar u)
        then cmgcdf(red sf,cmgcdf(lc sf,u))
        else cmgcdf(u,sf);

symbolic procedure remove!-maxdeg(sf,var);
if atom sf
  then 0
  else if mvar sf eq var
    then ldeg sf
    else if ordop(var,mvar sf)
      then 0
      else max(remove!-maxdeg(lc sf,var),remove!-maxdeg(red sf,var));

symbolic procedure cmgcdf2(sf,u);
% SF and U have the same MVAR, but INTVAR comes somewhere
% down in SF.  Therefore we can do better than a straight
% GCDK, or even a straight MAKEMAINVAR.
begin
  scalar n;
  n:=remove!-maxdeg(sf,intvar);
  if n = 0
    then return gcdf(sf,u);
    % Doesn't actually depend on INTVAR.
loop:
  if u = 1
    then return 1;
  u:=gcdf(u,collectterms(sf,intvar,n));
  n:=isub1 n;
  if n < 0
    then return u
    else go loop
  end;

symbolic procedure collectterms(sf,var,n);
if atom sf
  then if n = 0
    then sf
    else nil
  else if mvar sf eq var
    then if ldeg sf = n
      then lc sf
      else if ldeg sf > n
        then collectterms(red sf,var,n)
        else nil
    else if ordop(var,mvar sf)
      then if n = 0
        then sf
        else nil
      else begin
        scalar v,w;
        v:=collectterms(lc sf,var,n);
        w:=collectterms(red sf,var,n);
        if null v
          then return w
          else return addf(w,(lpow sf .* v) .+ nil)
        end;

% symbolic procedure removeconstantsf sf;
% % Very simple version for now.
% begin
%   scalar u;
%   if null sf
%     then return nil
%     else if atom sf
%       then return 1;
%   while (null red sf) and (remove!-constantp mvar sf) do
%     sf:=lc sf;
%   u:=remove!-const!-content sf;
%   if u = 1
%     then return sf
%     else return quotf!*(sf,u)
%   end;

symbolic procedure remove!-constantp pf;
if numberp pf
  then t
  else if atom pf
    then nil
    else if car pf eq 'sqrt
      then remove!-constantp argof pf
      else if (car pf eq 'expt) or (car pf eq 'quotient)
        then (remove!-constantp argof pf)
             and (remove!-constantp caddr pf)
        else nil;

symbolic procedure remove!-const!-content sf;
if numberp sf
  then sf
  else if null red sf
    then if remove!-constantp mvar sf
      then (lpow sf .* remove!-const!-content lc sf) .+ nil
      else remove!-const!-content lc sf
    else begin
      scalar u;
      u:=remove!-const!-content lc sf;
      if u = 1
        then return u;
      return gcdf(u,remove!-const!-content red sf)
      end;

endmodule;


module sqfrnorm;

% Author: James H. Davenport.

fluid '(!*pvar listofallsqrts);

global '(modevalcount);

modevalcount:=1;

exports sqfr!-norm2,res!-sqrt;

%symbolic procedure resultant(u,v);
%begin
%  scalar maxdeg,zeroes,ldegu,ldegv,m;
%  % we can have gone makemainvar on u and v;
%  ldegu:=ldeg u;
%  ldegv:=ldeg v;
%  maxdeg:=isub1 max2(ldegu,ldegv);
%  zeroes:=nlist(nil,maxdeg);
%  u:=remake(u,mvar u,ldegu);
%  v:=remake(v,mvar v,ldegv);
%  m:=nil;
%  ldegu:=isub1 ldegu;
%  ldegv:=isub1 ldegv;
%  for i:=0 step 1 until ldegv do
%    m:=append(ncdr(zeroes,maxdeg-ldegv+i),
%              append(u,ncdr(zeroes,maxdeg-i))).m;
%  for i:=0 step 1 until ldegu do
%    m:=append(ncdr(zeroes,maxdeg-ldegu+i),
%              append(v,ncdr(zeroes,maxdeg-i))).m;
%  return detqf m
%  end;

% symbolic procedure ncdr(l,n);
%   % we can use small integer arithmetic here.
%   if n=0 then l else ncdr(cdr l,isub1 n);

%symbolic procedure remake(u,v,w);
%% remakes u into a list of sf's representing its coefficients;
%if w iequal 0 then list u
%  else if (pairp u) and (mvar u eq v) and (ldeg u iequal w)
%    then (lc u).remake(red u,v,isub1 w)
%    else (nil ).remake(    u,v,isub1 w);

%fluid '(n); %needed for the mapcar;

%symbolic procedure detqf u;
%   %u is a square matrix standard form.
%%  %value is the determinant of u.
%%  %algorithm is expansion by minors of first row/column;
%   begin integer n;
%   scalar x,y,z;
%        if length u neq length car u then rederr "Non square matrix"
%         else if null cdr u then return caar u;
%        if length u < 3
%          then go to noopt;
%        % try to remove a row with only one non-zero in it;
%        z:=1;
%        x:=u;
%      loop:
%        n:=posnnonnull car x;
%        if n eq t
%          then return nil;
%        % special test for all null;
%        if n then <<
%          y:=nth(car x,n);
%          % next line is equivalent to:
%%           onne of n,z is even;
%          if evenp (n+z-1)
%            then y:=negf y;
%          u:=remove(u,z);
%          return !*multf(y,detqf remove2 u) >>;
%       x:=cdr x;
%       z:=z+1;
%       if x
%         then go to loop;
%     noopt:
%        x := u;
%        n := 1;                 %number of current row/column;
%        z := nil;
%        if nonnull car u < nonnullcar u
%         then go to row!-expand;
%        u:=mapcar(u,function cdr);
%    a:  if null x then return z;
%        y := caar x;
%        if null y then go to b
%         else if evenp n then y := negf y;
%        z := addf(!*multf(y,detqf remove(u,n)),z);
%    b:  x := cdr x;
%        n := iadd1 n;
%        go to a;
%      row!-expand:
%        u:=cdr u;
%        x:=car x;
%      aa:
%        if null x then return z;
%        y:=car x;
%        if null y
%          then go to bb
%          else if evenp n then y:=negf y;
%        z:=addf(!*multf(y,detqf remove2 u),z);
%      bb:
%        x:=cdr x;
%        n:=iadd1 n;
%        go to aa
%   end;
%
%
%symbolic procedure remove2 u;
%mapcar(u,function (lambda x;
%                    remove(x,n)));
%
%unfluid '(n);
%
%symbolic procedure nonnull u;
%if null u
%  then 0
%  else if null car u
%    then nonnull cdr u
%    else iadd1 (nonnull cdr u);
%
%
%symbolic procedure nonnullcar u;
%if null u
%  then 0
%  else if null caar u
%    then nonnullcar cdr u
%    else iadd1 (nonnullcar cdr u);
%
%
%
%symbolic procedure posnnonnull u;
%% returns t if u has no non-null elements
%% nil if more than one
%% else position of the first;
%begin
%  scalar n,x;
%  n:=1;
%loop:
%  if null u
%    then return
%      if x
%        then x
%        else t;
%  if car u
%    then if x
%      then return nil
%      else x:=n;
%  n:=iadd1 n;
%  u:=cdr u;
%  go to loop
%  end;


symbolic procedure res!-sqrt(u,a);
% Evaluates resultant of u ( as a poly in its mvar) and x**-a.
begin
  scalar x,n,v,k,l;
  x:=mvar u;
  n:=ldeg u;
  n:=quotient(n,2);
  v:=mkvect n;
  putv(v,0,1);
  for i:=1:n do
    putv(v,i,!*multf(a,getv(v,i-1)));
  % now substitute for x**2 in u leaving k*x+l.
  k:=l:=nil;
  while u do
    if mvar u neq x
      then <<
        l:=addf(l,u);
        u:=nil >>
      else <<
        if evenp ldeg u
          then l:=addf(l,!*multf(lc u,getv(v,(ldeg u)/2)))
          else k:=addf(k,!*multf(lc u,getv(v,(ldeg u -1)/2)));
        u:=red u >>;
  % now have k*x+l,x**2-a, giving l*l-a*k*k.
  return addf(!*multf(l,l),!*multf(negf a,multf(k,k)))
  end;


symbolic procedure sqfr!-norm2 (f,mvarf,a);
begin
  scalar u,w,aa,ff,resfn;
  resfn:='resultant;
  if eqcar(a,'sqrt)
    then <<
      resfn:='res!-sqrt;
      aa:=!*q2f simp argof a >>
    else rerror(algint,1,"Norms over transcendental extensions");
  f:=pvarsub(f,a,'! gerbil);
  w:=nil;
  if involvesf(f,'! gerbil) then goto l1;
increase:
  w:=addf(w,!*p2f mksp(a,1));
  f:=!*q2f algint!-subf(f,list(mvarf . list('plus,mvarf,
                                            list('minus,'! gerbil))));
l1:
  u:=apply2(resfn,makemainvar(f,'! gerbil),aa);
  ff:=nsqfrp(u,mvarf);
  if ff
    then go to increase;
  f:=!*q2f algint!-subf(f,list('! gerbil.a));
  % cannot use pvarsub since want to squash higher powers.
  return list(u,w,f)
  end;

symbolic procedure nsqfrp(u,v);
begin
  scalar w;
  w:=modeval(u,v);
  if w eq 'failed
    then go to normal;
  if atom w
    then go to normal;
  if ldegvar(w,v) neq ldegvar(u,v)
    then go to normal;
%  printc "Modular image is:";
%  printsf w;
  w:=gcdf(w,partialdiff(w,v));
%  printc "Answer is:";
%  printsf w;
  if w iequal 1
    then return nil;
normal;
  w:=gcdf(u,partialdiff(u,v));
  if involvesf(w,v)
    then return w
    else return nil
  end;

symbolic procedure ldegvar(u,v);
if atom u
  then 0
  else if mvar u eq v
    then ldeg u
    else if ordop(v,mvar u)
      then 0
      else max2(ldegvar(lc u,v),ldegvar(red u,v));


symbolic procedure modeval(u,v);
if atom u
  then u
  else if v eq mvar u
    then begin
      scalar w,x;
      w:=modeval(lc u,v);
      if w eq 'failed
        then return w;
      x:=modeval(red u,v);
      if x eq 'failed
        then return x;
      if null w
        then return x
        else return (lpow u .* w) .+ x
      end
    else begin
      scalar w,x;
      x:=mvar u;
      if not atom x
        then if dependsp(x,v)
          then return 'failed;
      x:=modevalvar x;
      if x eq 'failed
        then return x;
      w:=modeval(lc u,v);
      if w eq 'failed
        then return w;
      if x
        then w:=multf(w,exptf(x,ldeg u));
      x:=modeval(red u,v);
      if x eq 'failed
        then return x;
      return addf(w,x)
      end;


symbolic procedure modevalvar v;
begin scalar w;
  if not atom v then go to alg;
  w:=get(v,'modvalue);
  if w then return w;
  put(v,'modvalue,modevalcount);
  modevalcount:=modevalcount+1;
  return modevalcount-1;
alg:
  if car v neq 'sqrt
    then rerror(algint,2,"Unexpected algebraic");
  if numberp argof v then return (mksp(v,1) .* 1) .+ nil;
  w:=modeval(!*q2f simp argof v,!*pvar);
  w:=assoc(w,listofallsqrts);
  % The variable does not matter, since we know that it does not depend.
  if w then return cdr w else return 'failed
  end;

% unglobal '(modevalcount);

endmodule;


module substns;

% Author: James H. Davenport.

exports xsubstitutep,xsubstitutesq,substitutevec,substitutesq,subzero,
        subzero2,pvarsub;


symbolic procedure xsubstitutep(pf,slist);
simp xsubstitutep2(pf,slist);


symbolic procedure xsubstitutep2(pf,slist);
if null slist
  then pf
  else xsubstitutep2(subst(rfirstsubs slist,
                           lfirstsubs slist,
                           pf),
                     cdr slist);


symbolic procedure xsubstitutesq(sq,slist);
substitutesq(substitutesq(sq,basicplace slist),extenplace slist);


symbolic procedure substitutevec(v,slist);
for i:=0:upbv v do
  putv(v,i,substitutesq(getv(v,i),slist));


symbolic procedure substitutesq(sq,slist);
begin
  scalar list2,nm;
  list2:=nil;
  while slist do <<
    if cdar slist iequal 0
      then <<
        if list2
          then sq:=substitutesq(sq,reversip list2);
        list2:=nil;
        sq:=subzero(sq,caar slist) >>
      else if not (caar slist = cdar slist)
        then if assoc(caar slist,list2)
          then list2:=for each u in list2 collect
                  (car u).subst(cdar slist,caar slist,cdr u)
          else list2:=(car slist).list2;
        % don't bother with the null substitution.
    slist:=cdr slist >>;
  list2:=reversip list2;
  if null list2
    then return sq;
  nm:=algint!-subf(numr sq,list2);
  if numr nm
    then nm:=!*multsq(nm,invsq algint!-subf(denr sq,list2));
  return nm
  end;

% standard interface.
symbolic procedure subzero(exprn,var);
begin
  scalar top;
  top:=subzero2(numr exprn,var);
  if null numr top
    then return nil ./ 1;
  return !*multsq(top,!*invsq subzero2(denr exprn,var))
  end;


symbolic procedure subzero2(sf,var);
if not involvesf(sf,var)
  then sf ./ 1
  else if var eq mvar sf
    then subzero2(red sf,var)
    else if ordop(var,mvar sf)
      then sf ./ 1
      else begin
        scalar u,v;
        if dependsp(mvar sf,var)
          then <<
            u:=simp subst(0,var,mvar sf);
            if numr u
              then u:=!*exptsq(u,ldeg sf) >>
          else u:=((lpow sf .* 1) .+ nil) ./ 1;
        if null numr u
          then return subzero2(red sf,var);
        v:=subzero2(lc sf,var);
        if null numr v
          then return subzero2(red sf,var);
        return !*addsq(subzero2(red sf,var),
                       !*multsq(u,v))
        end;



symbolic procedure pvarsub(f,u,v);
% Changes u to v in polynomial f. No proper substitutions at all.
if atom f
  then f
  else if mvar f equal u
    then addf(multf(lc f,!*p2f mksp(v,ldeg f)),
              pvarsub(red f,u,v))
    else if ordop(u,mvar f)
      then f
      else addf(multf(pvarsub(lc f,u,v),!*p2f lpow f),
                pvarsub(red f,u,v));

endmodule;


module inttaylor;

% Author: James H. Davenport.

fluid '(const taylorasslist taylorvariable);

exports taylorform,taylorformp,taylorevaluate,return0,taylorplus,
         initialtaylorplus,taylorminus,initialtaylorminus,
         tayloroptminus,tayloroptplus,taylorctimes,initialtaylortimes,
         tayloroptctimes,taylorsqrtx,initialtaylorsqrtx,
         taylorquotient,initialtaylorquotient,taylorformersqrt,
         taylorbtimes,taylorformertimes,taylorformerexpt;

 symbolic procedure taylorform sq;
 if involvesf(denr sq,taylorvariable)
   then taylorformp list('quotient,tayprepf numr sq,tayprepf denr sq)
   else if 1 iequal denr sq
     then taylorformp tayprepf numr sq
     else taylorformp list('constanttimes,
                           tayprepf numr sq,
                           mk!*sq(1 ./ (denr sq)));
 % get division by a constant right.


 symbolic procedure taylorformp pf;
 if null pf
   then nil
   else if not dependsp(pf,taylorvariable)
     then taylorconst simp pf
     else begin
       scalar fn,initial,args,n;
       if atom pf
         then if pf eq taylorvariable
           then return taylorformp list ('expt,pf,1)
           else interr "False atom in taylorformp";
       % get 'x right as reduce shorthand for x**1.
       if taylorp pf
         then return pf;
       % cope with pre-expressed cases.
       % ***store-hack-1***
       % remove the (car pf eq 'sqrt) if more store is available.
       if (car pf eq 'sqrt) and
          (fn:=assoc(pf,taylorasslist))
         then go to lookupok;
       % look it up first.
       fn:=get(car pf,'taylorformer);
       if null fn
         then go to ordinary;
       fn:=apply1(fn,cdr pf);
       % ***store-hack-1***
       % remove the test if more store is available.
       if car pf eq 'sqrt
         then taylorasslist:=(pf.fn).taylorasslist;
       return fn;
       % cope with the special cases.
     ordinary:
       args:=mapcar(cdr pf,function taylorformp);
       fn:=get(car pf,'tayloropt);
       if null fn
         then go to nooptimisation;
       fn:=apply1(fn,args);
       if fn
         then go to ananswer;
       % an optimisation has been made.
     nooptimisation:
       fn:=get(car pf,'taylorfunction);
       if null fn
         then interr "No Taylor function provided";
       fn:=fn.args;
       % fn is now the "how to compute" code.
       initial:=get(car pf,'initialtaylorfunction);
       if null initial
         then interr "No initial Taylor function";
       initial:=lispapply(initial,
                      list for each u in cdr fn collect firstterm u);
       % the first term in the expansion, or so we hope.
       n:=car initial;
       fn:=list(fn,n.n,initial);
       while null numr cdr initial do <<
             n:=n+1;
             if !*tra then lprim list("Increasing accuracy to",n);
             initial:=n.taylorevaluate(fn,n);
             fn:=list(car fn,n.n,initial);
             >>;
     ananswer:
       % ***store-hack-1***
       % uncomment this if more store is available;
       % taylorasslist:=(pf.fn).taylorasslist;
       return fn;
     lookupok:
       % These PRINT statements can be enabled in order to test the
       % efficacy of the association list
 %      printc "Taylor lookup succeeded";
 %      superprint car fn;
 %      printc length taylorasslist;
       return cdr fn
       end;


 symbolic procedure taylorevaluate(texpr,n);
 if n<taylorfirst texpr
   then nil ./ 1
   else if n>taylorlast texpr
     then tayloreval2(texpr,n)
     else begin
       scalar u;
       u:=assoc(n,taylorlist texpr);
       if u
         then return cdr u
         else return tayloreval2(texpr,n)
       end;


 symbolic procedure tayloreval2(texpr,n);
 begin
   scalar u;
   % actually evaluates from scratch.
   u:=apply3(taylorfunction texpr,n,texpr,cdr taylordefn texpr);
   if 'return0 eq taylorfunction texpr
     then return u;
   % no need to update with trivial zeroes.
   rplacd(cdr texpr,(n.u).taylorlist texpr);
   % update the association list.
   if n>taylorlast texpr
     then rplacd(taylornumbers texpr,n);
   % update the first/last pointer.
   return u
   end;


 symbolic procedure taylorconst sq;
 list('return0 . nil,0 . 0,0 . sq);


 symbolic procedure return0 (a,b,c);
 nil ./ 1;

 flag('(return0),'taylor);


 symbolic procedure firstterm texpr;
 begin
   scalar n,i;
   i:=taylorfirst texpr;
 trynext:
   n:=taylorevaluate(texpr,i);
   if numr n
     then return i.n;
   if i > 50
     then interr "Potentially zero Taylor series";
   i:=iadd1 i;
   rplaca(taylornumbers texpr,i);
   go to trynext
   end;


 symbolic procedure tayloroneterm u;
 % See if a Taylor expression has only one term.
  'return0 eq taylorfunction u and taylorfirst u=taylorlast u;


 % ***store-hack-1***;
 % uncomment this procedure if more store is available;
 % there is a smacro for this at the start of the file
 % for use if no store can be spared;
 %symbolic procedure tayshorten(save);
 %begin
 %  scalar z;
 %  % shortens the association list back to save,
 %    removing all the non-sqrts from it;
 %  while taylorasslist neq save do <<
 %    if caar taylorasslist eq 'sqrt
 %      then z:=(car taylorasslist).z;
 %    taylorasslist:=cdr taylorasslist >>;
 %  taylorasslist:=nconc(z,taylorasslist);
 %  return nil
 %  end;


 symbolic procedure tayprepf sf;
 if atom sf
   then sf
   else if atom mvar sf
     then taylorpoly makemainvar(sf,taylorvariable)
     else if null red sf
       then tayprept lt sf
       else list('plus,tayprept lt sf,tayprepf red sf);


 symbolic procedure tayprept term;
 if tdeg term = 1
   then if tc term = 1
     then tvar term
     else list('times,tvar term,tayprepf tc term)
   else if tc term = 1
     then list ('expt,tvar term,tdeg term)
     else list('times,list('expt,tvar term,tdeg term),
                    tayprepf tc term);


 symbolic procedure taylorpoly sf;
 % SF is a poly with MVAR = TAYLORVARIABLE.
 begin
   scalar tmax,tmin,u;
   tmax:=tmin:=ldeg sf;
   while sf do
     if atom sf or (mvar sf neq taylorvariable)
       then <<
         tmin:=0;
         u:=(0 . !*f2q sf).u;
         sf:=nil >>
       else <<
         u:=((tmin:=ldeg sf) . !*f2q lc sf) . u;
         sf:=red sf >>;
   return (list 'return0) . ((tmin.tmax).u)
   end;


 symbolic procedure taylorplus(n,texpr,args);
 mapply(function !*addsq,
        for each u in args collect taylorevaluate(u,n));


 symbolic procedure initialtaylorplus slist;
 begin
   scalar n,numlst;
   n:=mapply(function min2,mapcar(slist,function car));
   % the least of the degrees.
   numlst:=nil;
   while slist do <<
     if caar slist iequal n
       then numlst:=(cdar slist).numlst;
     slist:=cdr slist >>;
   return n.mapply(function !*addsq,numlst)
   end;


 put ('plus,'taylorfunction,'taylorplus);
 put ('plus,'initialtaylorfunction,'initialtaylorplus);


 symbolic procedure taylorminus(n,texpr,args);
 negsq taylorevaluate(car args,n);


 symbolic procedure initialtaylorminus slist;
 (caar slist).(negsq cdar slist);


 put('minus,'taylorfunction,'taylorminus);
 put('minus,'initialtaylorfunction,'initialtaylorminus);


 flag('(taylorplus taylorminus),'taylor);


 symbolic procedure tayloroptminus(u);
 if 'return0 eq taylorfunction car u
   then taylormake(taylordefn car u,
                   taylornumbers car u,
                   taylorneglist taylorlist car u)
   else if 'taylorctimes eq taylorfunction car u
     then begin
       scalar const;
       u:=car u;
       const:=caddr taylordefn u;
       % the item to be negated.
       const:=taylormake(taylordefn const,
                         taylornumbers const,
                         taylorneglist taylorlist const);
       return taylormake(list(taylorfunction u,
                              argof taylordefn u,
                              const),
                         taylornumbers u,
                         taylorneglist taylorlist u)
       end
     else nil;
 put('minus,'tayloropt,'tayloroptminus);


 symbolic procedure taylorneglist u;
 mapcar(u,function (lambda v;
                    (car v).(negsq cdr v)));



 symbolic procedure tayloroptplus args;
 begin
   scalar ret,hard,u;
   u:=args;
   while u do <<
     if 'return0 eq taylorfunction car u
       then ret:=(car u).ret
       else hard:=(car u).hard;
     u:=cdr u >>;
   if null ret or
       null cdr ret
     then return nil;
   ret:=mapply(function joinret,ret);
   if null hard
     then return ret;
   rplaca(args,ret);
   rplacd(args,hard);
    return nil
   end;
 put('plus,'tayloropt,'tayloroptplus);


 symbolic procedure joinret(u,v);
 begin
   scalar nums,a,b,al;
   nums:=(min2(taylorfirst u,taylorfirst v).
          max2(taylorlast u,taylorlast v));
   al:=nil;
   u:=taylorlist u;
   v:=taylorlist v;
   for i:=(car nums) step 1 until (cdr nums) do <<
     a:=assoc(i,u);
     b:=assoc(i,v);
     if a
       then if b
         then al:=(i.!*addsq(cdr a,cdr b)).al
         else al:=a.al
       else if b
         then al:=b.al  >>;
   return taylormake(list 'return0,nums,al)
   end;




 % the operator constanttimes
 % has two arguments (actually a list)
 % 1) a form dependent on the taylorvariable
 % 2) a form which is not.


 % the operator binarytimes has two arguments (actually a list)
   % but behaves like times otherwise.


 symbolic procedure taylorctimes(n,texpr,args);
 !*multsq(taylorevaluate(car args,n-(taylorfirst cadr args)),
        taylorevaluate(cadr args,taylorfirst cadr args));


 symbolic procedure initialtaylortimes slist;
 % Multiply the variable by the constant.
 ((caar slist)+(caadr slist)). !*multsq(cdar slist,cdadr slist);


 symbolic procedure tayloroptctimes u;
 if 'taylorctimes eq taylorfunction car u
   then begin
     scalar reala,const,iconst,degg;
     % we have nested multiplication.
     reala:=argof taylordefn car u;
     % the thing to be multiplied by the two constants.
     const:=car taylorlist cadr u;
     %the actual outer constant: deg.sq.
     iconst:=caddr taylordefn car u;
     %the inner constant.
     degg:=(taylorfirst iconst)+(car const);
     iconst:=list(taylordefn iconst,
                   degg.degg,
                   degg.!*multsq(cdar taylorlist iconst,cdr const));
     return list('taylorctimes,reala,iconst).
                 ((((taylorfirst car u) + (car const)).
                         ((taylorlast car u) + (car const))).
                  mapcar(taylorlist car u,function multconst))
     end
   else if 'return0 eq taylorfunction car u
     then begin
       scalar const;
       const:=car taylorlist cadr u;
       % the actual constant:deg.sq.
       u:=car u;
       return (taylordefn u).
                   ((((taylorfirst u)+car const).
                         ((taylorlast u)+car const)).
                   mapcar(taylorlist u,function multconst))
       end
     else nil;


 symbolic procedure multconst v;
 % Multiplies v by const in deg.sq form.
 ((car v)+(car const)) . !*multsq(cdr v,cdr const);


 put('constanttimes,'tayloropt,'tayloroptctimes);
 put('constanttimes,'simpfn,'simptimes);
 put('constanttimes,'taylorfunction,'taylorctimes);
 put('constanttimes,'initialtaylorfunction,'initialtaylortimes);


 symbolic procedure taylorbtimes(n,texpr,args);
 begin
   scalar answer,n1,n2;
   answer:= nil ./ 1;
   n1:=car firstterm car args;
   % the first term in one argument.
   n2:=car firstterm cadr args;
   % the first term in the other.
   for i:=n1 step 1 until (n-n2) do
     answer:=!*addsq(answer,!*multsq(taylorevaluate(cadr args,n-i),
                                       taylorevaluate(car args,i)));
   return answer
   end;




 put('binarytimes,'taylorfunction,'taylorbtimes);
 put('binarytimes,'initialtaylorfunction,'initialtaylortimes);
 put('binarytimes,'simpfn,'simptimes);


symbolic procedure taylorformertimes arglist;
begin
  scalar const,var,degg,wsqrt,negcount;  % u;
  negcount:=0;
  degg:=0;% the deggrees of any solitary x we may meet.
  const:=nil;
  var:=nil;
  wsqrt:=nil;
  while arglist do <<
    if dependsp(car arglist,taylorvariable)
      then if and(eqcar(car arglist,'expt),
                        cadar arglist eq taylorvariable,
                        numberp caddar arglist)
        then degg:=degg+caddar arglist
% removed JHD 21.8.86 - while it is anoptimisation,
% it runs the risk of proving that -1 = +1 by ignoring the
% number of "i" needed - despite the attempts we went to.
%        else if eqcar(car arglist,'sqrt)
%          then <<
%            u:=argof car arglist;
%            wsqrt := u . wsqrt;
%            if minusq cdr firstterm taylorformp u
%              then negcount:=1+negcount >>
          else if car arglist eq taylorvariable
            then degg:=degg + 1
            else var:=(car arglist).var
      else const:=(car arglist).const;
    arglist:=cdr arglist >>;
  if wsqrt
    then if cdr wsqrt
      then var:=list('sqrt,prepsq simptimes wsqrt).var
      else var:=('sqrt.wsqrt).var;
  if var
    then var:=mapply(function (lambda u,v;
                               list('binarytimes,u,v)),var);
  % insert binary multiplications.
  negcount:=negcount/2;
  if onep cdr divide(negcount,2)
    then const:= (-1).const;
  % we had an odd number of (-1) from i*i.
  if const or (degg neq 0)
    then <<
      if const
        then const:=simptimes const
        else const:=1 ./ 1;
      const:=taylormake(list 'return0,degg.degg,list(degg.const));
      if null var
        then var:=const
        else var:=list('constanttimes,var,const) >>;
  return taylorformp var
  end;

put('times,'taylorformer,'taylorformertimes);




flag('(taylorbtimes taylorctimes taylorquotient),'taylor);
symbolic procedure taylorformerexpt arglist;
begin
  scalar base,expon;
  base:=car arglist;
  expon:=simpcar cdr arglist;
  if (denr expon neq 1) or
     (not numberp numr expon)
    then interr "Hard exponent";
  expon:=numr expon;
  if base neq taylorvariable
    then interr "Hard base";
  return list('return0 . nil,expon.expon,expon.(1 ./ 1))
  end;
put ('expt,'taylorformer,'taylorformerexpt);


symbolic procedure initialtaylorquotient slist;
(caar slist - caadr slist). !*multsq(cdar slist,!*invsq cdadr slist);


symbolic procedure taylorquotient(n,texpr,args);
begin
  % problem is texpr=b/c or c*texpr=b.
  scalar sofar,b,c,cfirst;
  b:=car args;
  c:=cadr args;
  cfirst:=taylorfirst c;
  sofar:=taylorevaluate(b,n+cfirst);
  for i:=taylorfirst texpr step 1 until n-1 do
    sofar:=!*addsq(sofar,!*multsq(taylorevaluate(texpr,i),
                              negsq taylorevaluate(c,n+cfirst-i)));
  return !*multsq(sofar,!*invsq taylorevaluate(c,cfirst))
  end;


put('quotient,'taylorfunction,'taylorquotient);
put('quotient,'initialtaylorfunction,'initialtaylorquotient);


% symbolic procedure minusq sq;
%    if null sq then nil
%     else if minusf numr sq then not minusf denr sq
%     else minusf denr sq;

% This is wrapped round TAYLORFORMERSQRT2 in order to
% remove the innards of the SQRT from the asslist.
% note the precautions for nested SQRTs.

symbolic procedure taylorformersqrt arglist;
% ***store-hack-1***;
% Uncomment these lines if more store is available.
%begin
%  scalar z;
%  z:=taylorasslist;
%  if sqrtsintree(car arglist,taylorvariable)
%    then return taylorformersqrt2 arglist;
%  arglist:=taylorformersqrt2 arglist;
%  taylorasslist:=z;
%  return arglist
%  end;
%
%
%symbolic procedure taylorformersqrt2 arglist;
begin
  scalar f,realargs,ff,realsqrt;
  realargs:=taylorformp carx(arglist,'taylorformersqrt2);
  f:=firstterm realargs;
  if not evenp car f
    then interr "Extra sqrt substitution needed";
  if and(0 iequal car f,
         1 iequal numr cdr f,
         1 iequal denr cdr f)
    then return taylorformp list('sqrtx,realargs);
  % if it starts with 1 already then it is easy.
  ff:=- car f;
  ff:=list(list 'return0,ff.ff,ff.(!*invsq cdr f));
  % ff is the leading term in the expansion of realargs.
  realsqrt:=list('sqrtx,list('constanttimes,realargs,ff));
  ff:=(car f)/2;
  return taylorformp list('constanttimes,
                          realsqrt,
                          list(list 'return0,
                               ff.ff,
                               ff.(simpsqrtsq cdr f)))
  end;


put('sqrt,'taylorformer,'taylorformersqrt);


symbolic procedure initialtaylorsqrtx slist;
0 . (1 ./ 1);
% sqrt(1+ ...) = 1+....


symbolic procedure taylorsqrtx(n,texpr,args);
begin scalar sofar;
  sofar:=taylorevaluate(car args,n);
  % (1+.....+a(n)*x**n)**2
  % = ....+x**n*(2*a(n)+sum(0<i<n,a(i)*a(n-i))).
  % So a(n)=(coeff(x**n)-sum) /2.
  for i:=1 step 1 until (n-1) do
    sofar:=!*addsq(sofar,negsq !*multsq(taylorevaluate(texpr,i),
                                    taylorevaluate(texpr,n-i)));
  return multsq(sofar,1 ./ 2)
  end;


flag('(taylorsqrtx),'taylor);
put('sqrtx,'taylorfunction,'taylorsqrtx);
put('sqrtx,'initialtaylorfunction,'initialtaylorsqrtx);

endmodule;


module torsionb;

% Author: James H. Davenport.

fluid '(!*tra !*trmin intvar nestedsqrts);

exports bound!-torsion;

symbolic procedure bound!-torsion(divisor,dof1k);
% Version 1 (see Trinity Thesis for difference).
begin
  scalar field,prime1,prime2,prime3,minimum,places;
  scalar non!-p1,non!-p2,non!-p3,curve,curve2,nestedsqrts;
  places:=for each u in divisor
            collect car u;
  curve:=getsqrtsfromplaces places;
  if nestedsqrts
    then rerror(algint,3,"Not yet implemented")
    else curve2:=curve;
  for each u in places do begin
    u:=rfirstsubs u;
    if eqcar(u,'quotient) and cadr u = 1
      then return;
    u:=substitutesq(simp u,list(intvar . 0));
    field:=union(field,sqrtsinsq(u,nil));
    u:=list(intvar . prepsq u);
    for each v in curve2 do
      field:=union(field,sqrtsinsq(substitutesq(v,u),nil));
    end;
  prime1:=2;
  while null (non!-p1:=good!-reduction(curve,dof1k,field,prime1)) do
    prime1:=nextprime prime1;
  prime2:=nextprime prime1;
  while null (non!-p2:=good!-reduction(curve,dof1k,field,prime2)) do
    prime2:=nextprime prime2;
  prime3:=nextprime prime2;
  while null (non!-p3:=good!-reduction(curve,dof1k,field,prime3)) do
    prime3:=nextprime prime3;
  minimum:=fix sqrt float(non!-p1*non!-p2*non!-p3);
  minimum:=min(minimum,non!-p1*max!-power(prime1,min(non!-p2,non!-p3)));
  minimum:=min(minimum,non!-p2*max!-power(prime2,min(non!-p1,non!-p3)));
  minimum:=min(minimum,non!-p3*max!-power(prime3,min(non!-p2,non!-p1)));
  if !*tra or !*trmin then <<
    princ "Torsion is bounded by ";
    printc minimum >>;
  return minimum
  end;


symbolic procedure max!-power(p,n);
% Greatest power of p not greater than n.
begin scalar ans;
  ans:=1;
  while ans<=n do
    ans:=ans*p;
  ans:=ans/p;
  end;


symbolic procedure good!-reduction(curve,dof1k,field,prime);
begin
  scalar u;
  u:=algebraic!-factorise(prime,field);
  interr "Good reduction not finished";
  end;

endmodule;


module wstrass;

% Author: James H. Davenport.

fluid '(!*exp
        !*gcd
        !*mcd
        !*structure
        !*uncached
        !*keepsqrts        % Forced SIMP to keep square roots around
        !*tra
        !*trmin
        intvar
        listofallsqrts
        listofnewsqrts
        magiclist
        previousbasis
        sqrt!-intvar
        sqrtflag
        sqrts!-in!-integrand
        taylorasslist
        taylorvariable
        thisplace
        zlist);

global '(coates!-fdi);

exports simpwstrass,weierstrass!-form;

imports gcdn,sqrtsinplaces,
        makeinitialbasis,mkvec,completeplaces,integralbasis,
        normalbasis,mksp,multsq,xsubstitutesq,taylorform,taylorevaluate,
        coatessolve,checkpoles,substitutesq,removecmsq,printsq,interr,
        terpri!*,printplace,finitise,fractional!-degree!-at!-infinity,
        !*multsq,fdi!-print,fdi!-upgrade,fdi!-revertsq,simp,newplace,
        xsubstitutep,sqrtsinsq,removeduplicates,!*exptf,!*multf,
        !*multsq,!*q2f,mapvec,upbv,coates!-lineq,addsq,!*addsq;

symbolic procedure simpwstrass u;
begin
  scalar intvar,sqrt!-intvar,taylorvariable,taylorasslist;
  scalar listofallsqrts,listofnewsqrts;
  scalar sqrtflag,sqrts!-in!-integrand,tt,u;
  scalar !*keepsqrts,!*exp,!*gcd,!*mcd,!*structure,!*uncached;
  !*keepsqrts:=t;     % Else nothing will work
  !*exp := !*gcd := !*mcd := !*uncached := t;
  !*structure := nil;  % Algebraic code certainly wants this off:
                       % keeping it on inhibits sqrt(z)^2 -> z
  tt:=readclock();
  sqrtflag:=t;
  taylorvariable:=intvar:=car u;
  sqrt!-intvar:=mvar !*q2f simpsqrti intvar;
  u:=for each v in cdr u
            collect int!-simp v;
  sqrts!-in!-integrand:=sqrtsinsql(u,intvar);
  u:=errorset!*('(weierstrass!-form sqrts!-in!-integrand),t);
  if atom u
    then return u
    else u:=car u;
  printc list('time,'taken,readclock()-tt,'milliseconds);
  printc "New x value is:";
  printsq car u;
  u:=cdr u;
  printc "New y value is:";
  printsq car u;
  u:=cdr u;
  printc "Related by the equation";
  printsq car u;
  return car u
  end;
put('wstrass,'simpfn,'simpwstrass);

symbolic procedure weierstrass!-form sqrtl;
begin
  scalar sqrtl2,u,x2,x1,vect,a,b,c,d,lhs,rhs;
  if !*tra or !*trmin then <<
    printc "Find Weierstrass form for elliptic curve defined by:";
    for each u in sqrtl do
      printsq simp u >>;
  sqrtl2:=sqrts!-at!-infinity sqrtl;
  sqrtl2:=append(car sqrtl2,
                 for each u in cdr sqrtl2 collect
                   u.u);
          % one of the places lying over infinity
          % (after deramification as necessary).
  x2:=coates!-wstrass(list sqrtl2,list(-3),intvar);
    % Note that we do not multiply by the MULTIPLICITY!-FACTOR
    % since we genuinely want a pole of order -3 irrespective
    % of any ramification problems.
  if !*tra then <<
    printc "Function with pole of order 3 (x2) is:";
    printsq x2 >>;
  x1:=coates!-wstrass(list sqrtl2,list(-2),intvar);
  if !*tra then <<
    printc "Function with pole of order 2 (x1) is:";
    printsq x1 >>;
  vect := mkvec list(1 ./ 1,
                  x1,
                  x2,
                  !*multsq(x1,x1),
                  !*multsq(x2,x2),
                  !*multsq(x1,!*multsq(x1,x1)),
                  !*multsq(x1,x2));
  u:=!*lcm!*(!*exptf(denr x1,3),!*multf(denr x2,denr x2)) ./ 1;
  for i:=0:6 do
    putv(vect,i,!*q2f !*multsq(u,getv(vect,i)));
  if !*tra then <<
    printc "List of seven functions in weierstrass!-form:";
    mapvec(vect,function printsf) >>;
  vect := wstrass!-lineq vect;
  if vect eq 'failed then
    interr "Linear equation solving failed in Weierstrass";
% printsq(addsq(getv(vect,0),addsq(!*multsq(getv(vect,1),x1),
%               addsq(!*multsq(getv(vect,2),x2),
%                     addsq(!*multsq(getv(vect,3),!*multsq(x1,x1)),
%                          addsq(!*multsq(getv(vect,4),!*multsq(x2,x2)),
%                             addsq(!*multsq(getv(vect,5),exptsq(x1,3)),
%                                       !*multsq(getv(vect,6),
%                                               !*multsq(x1,x2)))))))));
  x2:=!*addsq(!*multsq(!*multsq(2 ./ 1,getv(vect,4)),x2),
              !*addsq(!*multsq(x1,getv(vect,6)),
                    getv(vect,2)));
  putv(vect,4,!*multsq(-4 ./ 1,getv(vect,4)));
  a:=!*multsq(getv(vect,4),getv(vect,5));
  b:=!*addsq(!*multsq(getv(vect,6),getv(vect,6)),
             !*multsq(getv(vect,3),getv(vect,4)));
  c:=!*addsq(!*multsq(2 ./ 1,!*multsq(getv(vect,2),getv(vect,6))),
             !*multsq(getv(vect,1),getv(vect,4)));
  d:=!*addsq(!*multsq(getv(vect,2),getv(vect,2)),
             !*multsq(getv(vect,0),getv(vect,4)));
  lhs:=!*multsq(x2,x2);
  rhs:=!*addsq(d,!*multsq(x1,
                          !*addsq(c,!*multsq(x1,
                                          !*addsq(b,!*multsq(x1,a))))));
  if lhs neq rhs then <<
    printsq lhs;
    printsq rhs;
    interr "Previous two unequal - consistency failure 1" >>;
  u:=!*lcm!*(!*lcm!*(denr a,denr b),!*lcm!*(denr c,denr d));
  if u neq 1 then <<
    % for now use u**2 whereas we should be using the least
    % square greater than u**2 (does it really matter).
    x2:=!*multsq(x2,u ./ 1);
    u:=!*multf(u,u) ./ 1;
    a:=!*multsq(a,u);
    b:=!*multsq(b,u);
    c:=!*multsq(c,u);
    d:=!*multsq(d,u) >>;
  if (numr b) and not (quotf(numr b,3)) then <<
    % multiply all through by 9 for the hell of it.
    x2:=multsq(3 ./ 1,x2);
    u:=9 ./ 1;
    a:=multsq(a,u);
    b:=multsq(b,u);
    c:=multsq(c,u);
    d:=multsq(d,u) >>;
  x2:=!*multsq(x2,a);
  x1:=!*multsq(x1,a);
  c:=!*multsq(a,c);
  d:=!*multsq(!*multsq(a,a),d);
  lhs:=!*multsq(x2,x2);
  rhs:=!*addsq(d,!*multsq(x1,!*addsq(c,!*multsq(x1,!*addsq(b,x1)))));
  if lhs neq rhs then <<
    printsq lhs;
    printsq rhs;
    interr "Previous two unequal - consistency failure 2" >>;
  b:=quotf(numr b,3) ./ 1;
  x1:=!*addsq(x1,b);
  d:=!*addsq(d,!*addsq(multsq(2 ./ 1,!*multsq(b,!*multsq(b,b))),
                       negsq !*multsq(c,b)));
  c:=!*addsq(c,multsq((-3) ./ 1,!*multsq(b,b)) );
% b:=nil ./ 1;   % not used again.
  if !*tra then <<
    printsq x2;
    printsq x1;
    printc "with coefficients";
    printsq c;
    printsq d;
    rhs:=!*addsq(d,
                 !*addsq(!*multsq(c,x1),
                         !*multsq(x1,!*multsq(x1,x1)) ));
    lhs:=!*multsq(x2,x2);
    if lhs neq rhs then <<
      printsq lhs;
      printsq rhs;
      interr "Previous two unequal - consistency failure 3" >> >>;
    return weierstrass!-form1(c,d,x1,x2)
   end;

symbolic procedure !*lcm!*(u,v); !*multf(u,quotf(v,gcdf(u,v)));

symbolic procedure weierstrass!-form1(c,d,x1,x2);
 begin scalar b,u;
  u:=gcdf(numr c,numr d);
    % We will reduce by anything whose square divides C
    % and whose cube divides D.
  if not numberp u then begin
    scalar cc,dd;
    u:=jsqfree(u,mvar u);
    u:=cdr u;
    if null u
      then return;
      % We found no repeated factors.
    for each v in u do
      for each w in v do
        while (cc:=quotf(numr c,multf(w,w))) and
              (dd:=quotf(numr d,exptf(w,3)))
          do <<
            c:=cc ./ 1;
            d:=dd ./ 1;
            x1:=!*multsq(x1,1 ./ w);
            x2:=!*multsq(x2,1 ./ multf(w,simpsqrt2 w)) >>;
    u:=gcdn(algint!-numeric!-content numr c,
            algint!-numeric!-content numr d)
    end;
  b:=2;
 while not (b*b) > u do begin
    scalar nc,nd,uu;
    nc:=0;
    while cdr(uu:=divide(u,b))=0 do <<
      nc:=nc+1;
      u:=car uu >>;
    if nc < 2
      then go to next;
    uu:=algint!-numeric!-content numr d;
    nd:=0;
    while cdr(uu:=divide(uu,b))=0 do <<
      nd:=nd+1;
      uu:=car uu >>;
    if nd < 3
      then go to next;
    nc:=min(nc/2,nd/3);
      % re-normalise by b**nc.
    uu:=b**nc;
    c:=multsq(c,1 ./ (uu**2));
    d:=multsq(d,1 ./ (uu**3));
    x1:=multsq(x1,1 ./ uu);
    x2:=multsq(x2,1 ./ (uu*b**(nc/2)) );
    if not evenp nc
      then x2:=!*multsq(x2,!*invsq simpsqrti b);
next:
    b:=nextprime(b)
    end;
  u:=!*kk2q intvar;
  u:=!*addsq(!*addsq(d,multsq(c,u)),exptsq(u,3));
  if !*tra or !*trmin then <<
    printc "Standard form is y**2 = ";
    printsq u >>;
  return list(x1,x2,simpsqrtsq u)
  end;

symbolic procedure sqrts!-at!-infinity sqrtl;
begin
  scalar inf,hack,sqrtl2,repeating;
  hack:=list list(intvar,'expt,intvar,2);
  inf:=list list(intvar,'quotient,1,intvar);
  sqrtl2:=list sqrt!-intvar;
  while sqrt!-intvar member sqrtl2 do <<
    if repeating
      then inf:=append(inf,hack);
    newplace inf;
    sqrtl2:=for each v in sqrtl conc
      sqrtsinsq(xsubstitutep(v,inf),intvar);
    repeating:=t >>;
  sqrtl2:=removeduplicates sqrtl2;
  return inf.sqrtl2
  end;

symbolic procedure coates!-wstrass(places,mults,x);
begin
  scalar thisplace,u,finite!-hack,save,places2,mults2;
  if !*tra or !*trmin then <<
    princ "Find function with zeros of order:";
    printc mults;
    if !*tra then
      princ " at ";
    terpri!*(t);
    if !*tra then
      mapc(places,function printplace) >>;
%  finite!-hack:=placesindiv places;
    % FINITE!-HACK is a list of all the substitutors in PLACES;
%  u:=removeduplicates sqrtsintree(finite!-hack,x,nil);
%  if !*tra then <<
%    princ "Sqrts on this curve:";
%    terpri!*(t);
%    superprint u >>;
%  algnos:=removeduplicates mapcar(places,function basicplace);
%  if !*tra then <<
%    printc "Algebraic numbers where residues occur:";
%    superprint algnos >>;
  finite!-hack:= finitise(places,mults);
    % returns list (places,mults,power of x to remove.
  places2:=car finite!-hack;
  mults2:=cadr finite!-hack;
  finite!-hack:=list(places,mults,caddr finite!-hack);
  coates!-fdi:=fractional!-degree!-at!-infinity u;
  if coates!-fdi iequal 1
    then return !*multsq(wstrassmodule(places2,mults2,x,finite!-hack),
                         !*p2q mksp(x,caddr finite!-hack));
  if !*tra
    then fdi!-print();
  newplace list(intvar . thisplace,
                list(intvar,'expt,intvar,coates!-fdi));
  places2:=mapcar(places2,function fdi!-upgrade);
  save:=taylorasslist;
  u:=wstrassmodule(places2,
                  mapcar(mults2,function (lambda u;u*coates!-fdi)),
                  x,finite!-hack);
  taylorasslist:=save;
  u:=fdi!-revertsq u;
  return !*multsq(u,!*p2q mksp(x,caddr finite!-hack))
  end;

symbolic procedure wstrassmodule(places,mults,x,finite!-hack);
begin
  scalar pzero,mzero,u,v,basis,sqrts,magiclist,mpole,ppole;
    % MAGICLIST holds the list of extra unknowns created in JHDSOLVE
    % which must be found in CHECKPOLES (calling FINDMAGIC).
  sqrts:=sqrtsinplaces places;
  if !*tra then <<
    princ "Sqrts on this curve:";
    superprint sqrts >>;
  u:=places;
  v:=mults;
  while u do <<
    if 0<car v
      then <<
        mzero:=(car v).mzero;
        pzero:=(car u).pzero >>
      else <<
        mpole:=(car v).mpole;
        ppole:=(car u).ppole >>;
    u:=cdr u;
    v:=cdr v >>;
  basis:=mkvec makeinitialbasis ppole;
  u:=completeplaces(ppole,mpole);
  basis:=integralbasis(basis,car u,cdr u,x);
  basis:=normalbasis(basis,x,0);
  u:=coatessolve(mzero,pzero,basis,force!-pole(basis,finite!-hack));
    % This is the list of special constraints needed
    % to force certain poles to occur in the answer.
 previousbasis:=nil;
  if atom u
    then return u;
  v:= checkpoles(list u,places,mults);
  if null v
    then return 'failed;
  if not magiclist
    then return u;
  u:=removecmsq substitutesq(u,v);
  % Apply the values from FINDMAGIC.
  if !*tra or !*trmin then <<
    printc "Function is";
    printsq u >>;
  magiclist:=nil;
  if checkpoles(list u,places,mults)
    then return u
    else interr "Inconsistent checkpoles"
  end;

symbolic procedure force!-pole(basis,finite!-hack);
begin
  scalar places,mults,u,ans;
  places:=car finite!-hack;
  mults:=cadr finite!-hack;
  finite!-hack:=caddr finite!-hack;
  u:=!*p2q mksp(intvar,finite!-hack);
  basis:=for each v in basis collect multsq(u,v);
  while places do <<
    u:=for each v in basis collect
       taylorevaluate(taylorform xsubstitutesq(v,car places),
                      car mults);
    mults:=cdr mults;
    places:=cdr places;
    ans:=u.ans >>;
  return ans
  end;

symbolic procedure wstrass!-lineq vect;
begin
  scalar zlist,powlist,m,rightside,v;
  scalar zero,one;
  zero:=nil ./ 1;
  one:=1 ./ 1;
  for i:=0:6 do
    zlist:=varsinsf(getv(vect,i),zlist);
  zlist:=intvar . findzvars(zlist,nil,intvar,nil);
  for i:=0:6 do
    putv(vect,i,f2df getv(vect,i));
  for i:=0:6 do
    for each u in getv(vect,i) do
      if not ((tpow u) member powlist)
        then powlist:=(tpow u).powlist;
  m:=for each u in powlist collect begin
    scalar v;
    v:=mkvect 6;
    for i:=0:6 do
      putv(v,i,(lambda u;
                  if null u
                    then zero
                    else tc u)
                 assoc(u,getv(vect,i)));
    return v
    end;
  v:=mkvect 6;
  for i:=0:6 do
    putv(v,i,zero);
  putv(v,4,one);
    % we know that coefficient e is non-zero.
  m:=mkvec (v.m);
  v:=upbv m;
  rightside:=mkvect v;
  putv(rightside,0,one);
  for i:=1:v do
    putv(rightside,i,zero);
  return coates!-lineq(m,rightside)
  end;

% This is same as NUMERIC!-CONTENT in the EZGCD module, but is included
% here so that that module doesn't need to be loaded.

symbolic procedure algint!-numeric!-content form;
 %Find numeric content of non-zero polynomial.
   if domainp form then abs form
   else if null red form then algint!-numeric!-content lc form
   else begin
     scalar g1;
     g1 := algint!-numeric!-content lc form;
     if not (g1=1)
       then g1 := gcddd(g1,algint!-numeric!-content red form);
     return g1
   end;

endmodule;


module zmodule;

% Author: James H. Davenport.

fluid '(!*galois
        !*tra
        !*trfield
        !*trmin
        basic!-listofallsqrts
        basic!-listofnewsqrts
        commonden
        gaussiani
        listofallsqrts
        listofnewsqrts
        sqrt!-places!-alist
        taylorasslist);

exports zmodule;
imports !*multf,sqrtsinsql,sortsqrts,simp,!*q2f,actualsimpsqrt,printsf;
imports prepf,substitutesq,printsq,mapply,!*multsq,mkilist;
imports mkvecf2q,mkvec,mkidenm,invsq,multsq,negsq,addsq,gcdn;
imports !*invsq,prepsq;

symbolic procedure zmodule(w);
begin
  scalar reslist,denlist,u,commonden,basis,p1,p2,hcf;
  % w is a list of elements (place.residue)=sq.
  for each v in w do <<
    u:=cdr v;
    reslist:=u.reslist;
    denlist:=(denr u).denlist >>;
  basis:=sqrtsinsql(reslist,nil);
  if null u or null cdr u or !*galois
    then go to nochange;
  reslist:=check!-sqrts!-dependence(reslist,basis);
  denlist:=for each u in reslist
             collect denr u;
nochange:
 commonden:=mapply(function(lambda u,v;
                      multf(u,quotf(v,gcdf(u,v)))),denlist)./1;
  u:=nil;
  for each v in reslist do
    u:=(numr !*multsq(v,commonden)).u;
  reslist:=u;
    % We have effectively reversed RESLIST twice, so it is in correct
    % order.
  u:=bexprn(reslist);
  basis:=car u;
  reslist:=cdr u;
  denlist:=nil;
  while basis do <<
    p1:=reslist;
    p2:=w;
    u:=nil;
    hcf:=0;
    while p1 do <<
      if 0 neq caar p1
        then  <<
          u:=((caar p2).(caar p1)).u;
          hcf:=gcdn(hcf,caar p1) >>;
      p1:=cdr p1;
      p2:=cdr p2 >>;
    if hcf neq 1
     then u:=for each uu in u collect
               (car uu). ( (cdr uu) / hcf);
    denlist:=(prepsq !*multsq(car basis,
                              multsq(!*f2q hcf,!*invsq commonden))
                  .u).denlist;
    basis:=cdr basis;
    reslist:=mapcar(reslist,function cdr) >>;
  return denlist
  end;


symbolic procedure bexprn(wlist);
begin
  scalar basis,replist,w,w2,w3,p1,p2;
  % wlist is a list of sf.
  w:=reverse wlist;
  replist:=nil;
  while w do <<
    w2:=sf2df car w;
    % now ensure that all elements of w2 are in the basis.
    w3:=w2;
    while w3 do <<
      % caar is the sf,cdar a its coefficient.
      if not member(caar w3,basis)
        then <<
          basis:=(caar w3).basis;
          replist:=mapcons(replist,0) >>;
          % adds car w3 to basis.
      w3:=cdr w3 >>;
    replist:=mkilist(basis,0).replist;
    % builds a new zero representation.
    w3:=w2;
    while w3 do <<
      p1:=basis;
      p2:=car replist;
      %the list for this element.
      while p1 do <<
        if caar w3 = car p1
          then rplaca(p2,cdar w3);
        p1:=cdr p1;
        p2:=cdr p2 >>;
      w3:=cdr w3 >>;
    w:=cdr w >>;
  return mkbasis(basis,replist)
  end;


symbolic procedure mkbasis(basis,reslist);
begin
  scalar row,nbasis,nreslist,u,v;
  basis:=for each u in basis collect !*f2q u;
  % basis is a list of sq's
  % reslist is a list of representations in the form
  % ( (coeff1 coeff2 ...)    ...).
  nreslist:=mkilist(reslist,nil);
  % initialise our list-of-lists.
  trynewloop:
  row:=mapcar(reslist,function car);
  reslist:=mapcar(reslist,function cdr);
  if obvindep(row,nreslist)
    then u:=nil
    else u:=lindep(row,nreslist);
  if u
    then <<
      % u contains the numbers with which to add this new item into the
      % basis.
      v:=nil;
      while nbasis do <<
        v:=addsq(car nbasis,!*multsq(car basis,car u)).v;
        nbasis:=cdr nbasis;
        u:=cdr u >>;
      nbasis:=reversip v >>
    else <<
      nreslist:=pair(row,nreslist);
      nbasis:=(car basis).nbasis
      >>;
  basis:=cdr basis;
  if basis
   then go to trynewloop;
  return nbasis.nreslist
  end;


symbolic procedure obvindep(row,matrx);
  % True if row is obviously linearly independent of the
  % Rows of the matrix.
begin scalar u;
  if null car matrx
    then return t;
  % no matrix => no dependence.
nexttry:
  if null row
    then return nil;
  if 0 iequal car row
    then go to nouse;
  u:=car matrx;
testloop:
  if 0 neq car u
    then go to nouse;
  u:=cdr u;
  if u
    then go to testloop;
  return t;
nouse:
  row:=cdr row;
  matrx:=cdr matrx;
  go to nexttry
  end;


symbolic procedure sf2df sf;
if null sf
   then nil
   else if numberp sf
    then (1 . sf).nil
    else begin
      scalar a,b,c;
      a:=sf2df lc sf;
      b:=(lpow sf .* 1) .+ nil;
      while a do <<
        c:=(!*multf(caar a,b).(cdar a)).c;
        a :=cdr a >>;
      return nconc(c,sf2df red sf)
      end;





symbolic procedure check!-sqrts!-dependence(sql,sqrtl);
% Resimplifies the list of SQs SQL,
% allowing for all dependencies among the
% sqrts in SQRTl.
begin
  scalar !*galois,sublist,sqrtsavelist,changeflag;
  sqrtsavelist:=listofallsqrts.listofnewsqrts;
  listofnewsqrts:=list mvar gaussiani;
  listofallsqrts:=list((argof mvar gaussiani) . gaussiani);
  !*galois:=t;
  for each u in sortsqrts(sqrtl,nil) do begin
    scalar v,uu;
    uu:=!*q2f simp argof u;
    v:=actualsimpsqrt uu;
    listofallsqrts:=(uu.v).listofallsqrts;
    if domainp v or mvar v neq u
      then <<
        if !*tra or !*trfield then <<
           printc u;
           printc "re-expressed as";
           printsf v >>;
        v:=prepf v;
        sublist:=(u.v) . sublist;
        changeflag:=t >>
    end;
  if changeflag then <<
    sql:=for each u in sql collect
           substitutesq(u,sublist);
    taylorasslist:=nil;
    sqrt!-places!-alist:=nil;
    basic!-listofallsqrts:=listofallsqrts;
    basic!-listofnewsqrts:=listofnewsqrts;
    if !*tra or !*trmin then <<
      printc "New set of residues are";
      mapc(sql,function printsq) >> >>
    else <<
      listofallsqrts:=car sqrtsavelist;
      listofnewsqrts:=cdr sqrtsavelist >>;
  return sql
  end;



symbolic procedure lindep(row,matrx);
  begin
    scalar m,m1,n,u,v,inverse,rowsinuse,failure;
    % Inverse is the answer from the "gaussian elimination"
    % we are doing.
    % Rowsinuse has nil for rows with no "awkward" non-zero entries.
    m1:=length car matrx;
    m:=isub1 m1;
    n:=isub1 length matrx;
    % n=length row.
    row:=mkvecf2q row;
    matrx:=mkvec mapcar(matrx,function mkvecf2q);
    inverse:=mkidenm m1;
    rowsinuse:=mkvect m;
    failure:=t;
    % initialisation complete.
    for i:=0 step 1 until n do begin
      % try to kill off i'th elements in each row.
      u:=nil;
      for j:=0 step 1 until m do <<
        % try to find a  pivot element.
        if  (null u) and
            (null getv(rowsinuse,j)) and
            (numr getv(getv(matrx,i),j))
          then u:=j >>;
      if null u
        then go to nullu;
      putv(rowsinuse,u,t);
      % it is no use trying this again ---
      % u is our pivot element.
      if u iequal m
        then go to nonetokill;
      for j:=iadd1 u step 1 until m do
        if numr getv(getv(matrx,i),j)
          then <<
            v:=negsq multsq(getv(getv(matrx,i),j),
                            invsq getv(getv(matrx,i),u));
            for k:=0 step 1 until m1 do
              putv(getv(inverse,k),j,
                addsq(getv(getv(inverse,k),j),
                  multsq(v,getv(getv(inverse,k),u))));
            for k:=0 step 1 until n do
              putv(getv(matrx,k),j,
                addsq(getv(getv(matrx,k),j),
                  multsq(v,getv(getv(matrx,k),u)))) >>;
      % We have now pivoted throughout matrix.
    nonetokill:
      % now do the same in row if necessary.
      if null numr getv(row,i)
        then go to norowop;
      v:=negsq multsq(getv(row,i),
                 invsq getv(getv(matrx,i),u));
      for k:=0 step 1 until m1 do
        putv(getv(inverse,k),m1,
          addsq(getv(getv(inverse,k),m1),
            multsq(v,getv(getv(inverse,k),u))));
      for k:=0 step 1 until n do
        putv(row,k,addsq(getv(row,k),
                     multsq(v,getv(getv(matrx,k),u))));
      u:=nil;
      for k:=0 step 1 until n do
        if numr getv(row,k)
          then u:=t;
      % if u is null then row is all 0.
      if null u
        then <<
          n:=-1;
          failure:=nil >>;
    norowop:
      if !*tra then <<
        princ "At end of cycle";
        printc row;
        printc matrx;
        printc inverse >>;
      return;
    nullu:
      % there is no pivot for this u.
      if numr getv(row,i)
        then n:=-1;
        % this element cannot be killed.
      end;
    if failure
      then return nil;
    v:=nil;
    for i:=0 step 1 until m do
      v:=(negsq getv(getv(inverse,m-i),m1)).v;
    return v
    end;

endmodule;


end;
