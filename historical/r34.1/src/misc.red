module misc;    % Miscellaneous algebraic code.

create!-package('(misc limits pf sum),'(contrib misc));

endmodule;


module limits;

%% A fast limit package for REDUCE for functions which are continuous
%% except for computable poles and singularities.

%% Author: Stanley L. Kameny.

%% Date: 10 Oct 1990.

%% The Truncated Power Series package is used for non-critical points.
%% L'Hopital's rule is used in critical cases, with preprocessing of
%% <infinity - infinity> forms and reformatting of product forms in
%% order to be able to apply l'Hopital's rule.  A limited amount of
%% bounded arithmetic is also employed where applicable.

%% This limits package makes use of the ideas embodied in the
%% limit.red package, by Ian Cohen and John Fitch, 11 July 1990
%% that is in reduce-netlib;  in fact, some code is lifted bodily.
%% The idea of using the Truncated Power Series package to compute
%% limits at non-critical points, and the substitutions used in limit!+
%% and limit!- come from there.

load!-package 'tps;

fluid '(lhop!# lplus!# !*norcrs);

global '(erfg!* !*protfg);

symbolic procedure limit2(top,bot,xxx,a);
   lhopital(top,bot,xxx,a) where lhop!#=0;

symbolic procedure limit!+(ex,x,a);
<<ex := simp!* logsort ex;
  if a = 'infinity then rederr "Cannot approach infinity from above"
  else if a = '(minus infinity) then
     limit(prepsq subsq(ex,list(x .
        list('quotient,-1,list('expt,'!*eps!*,2)))),'!*eps!*,0)
  else limit(prepsq subsq(ex,list(x .
        list('plus,a,list('expt,'!*eps!*,2)))),'!*eps!*,0)>>;

symbolic procedure limit!-(ex,x,a);
<<ex := simp!* logsort ex;
  if a = 'infinity then
     limit(prepsq subsq(ex,list(x .
        list('quotient,1,list('expt,'!*eps!*,2)))),'!*eps!*,0)
  else if a = '(minus infinity) then
     rederr "Cannot approach -infinity from below"
  else limit(prepsq subsq(ex,list(x .
        list('difference,a,list('expt,'!*eps!*,2)))),'!*eps!*,0)>>;

symbolic operator limit1,limit0,limit,limit!+,limit!-,limit2;

symbolic procedure limit(ex,xxx,a); limit0(logsort ex,xxx,a)
  where !*combinelogs=nil,lhop!#=0,lplus!#=0;

symbolic procedure limit0(ex,x,a);
<<ex := simp!* ex;
  if a = 'infinity then limit0(
     prepsq subsq(ex,list(x .
        list('quotient,1,list('expt,'!*tmp!*,2)))),'!*tmp!*,0)
  else if a = '(minus infinity) then limit0(
     prepsq subsq(ex,list(x .
        list('quotient,-1,list('expt,'!*tmp!*,2)))),'!*tmp!*,0)
  else
   ((if null lim1 then
      if !*norcrs then
         lhopital(prepsq !*f2q numr ex,prepsq !*f2q denr ex,x,a)
      else limsimp(prepsq ex,x,a) else lim1)
   where lim1=limitset(prepsq ex,x,a))>>;

symbolic procedure limitset(ex,x,a);
begin scalar oldpslim;
    !*protfg := t; oldpslim := simppsexplim '(1);
    ex := errorset!*(list('limit1,mkquote ex,mkquote x,mkquote a),
       nil);
    !*protfg := nil; simppsexplim list car oldpslim;
    return if errorp ex then nil else car ex;
end;

symbolic procedure limit1(ex,xxx,a);
   begin scalar aaa, nnn, vvv;
     aaa := mk!*sq simpps1(ex,xxx,a);
     nnn := mk!*sq simppsorder list aaa;
     vvv := simppsterm1(aaa,min(nnn,0));
     return
       if nnn>=0 then mk!*sq vvv
       else if atom(nnn := car vvv) and nnn<0
         then aeval '(minus infinity)
       else 'infinity
   end;

put('times,'limsfn,'ltimesfn);
put('quotient,'limsfn,'lquotfn);
put('plus,'limsfn,'lplusfn);

symbolic procedure limsimp(ex,x,a);
  % called when limit1 has failed, to apply more sophisticated methods.
  % output must be aeval form.
   begin scalar y,c,z,m;
      if eqcar(ex,'minus) then <<m := t; ex := cadr ex>>;
      if not atom ex then  % check for plus, times, or quotient.
         <<if(z := get(y := car ex,'limsfn))
              then ex := apply(z,list(ex,x,a))>>
         else <<if ex eq x then ex := a; go to ret>>;
      if y eq 'plus then go to ret;
      if z then<<z := car ex; c := cdr ex>>
         else <<z := prepsq !*f2q numr(ex := simp!* ex);
                c := prepsq !*f2q denr ex>>;
      ex := lhopital(z,c,x,a);
 ret: if m and prepsq simp!* ex neq 'failed then
         ex := aeval lminus2 ex;
      return ex end;

symbolic procedure lminus2 ex;
   if numberp ex then -ex
   else if eqcar(ex,'minus) then cadr ex
   else list('minus,ex);

symbolic procedure ltimesfn(ex,x,a); specchk(ex,1,x,a);

symbolic procedure lquotfn(ex,x,a); specchk(cadr ex,caddr ex,x,a);

symbolic procedure specchk(top,bot,x,a);
   begin scalar tlist,blist,tinfs,binfs,tlogs,blogs,tzros,bzros,
         tnrms,bnrms,m,!*norcrs;
      !*norcrs := t;
      if eqcar(top,'minus) then <<m := t; top := cadr top>>;
      if eqcar(bot,'minus) then <<m := not m; bot := cadr bot>>;
      tlist := limsort(timsift(top,x),x,a);
      blist := limsort(timsift(bot,x),x,a);
      tinfs := cdr(tlogs := logcomb(cadr tlist,x)); tlogs := car tlogs;
      binfs := cdr(blogs := logcomb(cadr blist,x)); blogs := car blogs;
      tzros := car tlist; tnrms := caddr tlist;
      bzros := car blist; bnrms := caddr blist;
      if tlogs and not blogs then
         <<top := triml append(tlogs,tnrms);
           bot := triml append(bzros,append(binfs,
              append(bnrms,trimq append(tinfs,tzros))))>>
      else if blogs and not tlogs then
         <<bot := triml append(blogs,bnrms);
           top := triml append(tzros,append(tinfs,
              append(tnrms,trimq append(binfs,bzros))))>>
      else
         <<top := triml append(cadr tlist,trimq bzros);
           bot := triml append(cadr blist,
              append(bnrms,trimq append(tzros,tnrms)))>>;
      if m then top := list('minus,top);
      return top . bot end;

symbolic procedure trimq l;
   if l then list list('quotient,1,
      if length l>1 then 'times . l else car l);

symbolic procedure triml l;
   if null l then 1 else if length l>1 then 'times . l else car l;

symbolic procedure limsort(ex,x,a);
   begin scalar zros,infs,nrms,q,s;
      for each c in ex do
         if (q := numr(s := simp!* limit0(c,x,a)))
              and numberp q and not zerop q then nrms := q . nrms
         else if null q or zerop q then zros := c . zros
         else if caaar q memq '(failed infinity) then infs := c.infs
         else nrms := (prepsq s) . nrms;
      return list(zros,infs,nrms) end;

symbolic procedure logcomb(tinf,x);
  % separate product list into log terms and others.
   begin scalar tlog,c,z;
      while tinf do
         <<c := car tinf; tinf := cdr tinf;
           if eqcar(c,'log)
              or eqcar(c,'expt) and eqcar(cadr c,'log)
              or eqcar(c,'plus) and
                (eqcar(cadr(c := logjoin(c,x)),'log)
                  or eqcar(cadr c,'minus) and eqcar(cadadr c,'log))
                    and freeof(cddr c,x)
           then tlog := c . tlog else z := c . z>>;
      return tlog . reversip z end;

symbolic procedure logjoin(p,x);
  % combine log terms in sum list into a single log.
   begin scalar ll,z;
      for each c in cdr p do
         if freeof(c,x) then z := c . z
         else if eqcar(c,'log) then ll := (cadr c) . ll
         else if eqcar(c,'minus) and eqcar(cadr c,'log) then
            ll := list('quotient,1,cadadr c) . ll
         else z := c . z;
      if ll then ll := list list('log,'times . ll);
      return (car p) . append(ll,reversip z) end;

symbolic procedure timsift(ex,x);
   if eqcar(ex,'times) then cdr ex
   else if eqcar(ex,'plus) then list logjoin(ex,x)
    % for plus, combine log terms, change infinity - infinity to
    % inner quotient.
   else list ex;

symbolic procedure lplusfn(ex,x,a);
  % combine logs and evaluate each limit term.  if infinity - infinity
  % is found, attempt conversion to quotient form for lhopital.
   begin scalar z,infs,nrms,vals,vp,vm,cz,vnix;
      lplus!# := lplus!# + 1;
     % write "lplus#=",lplus!#; terpri();
      if lplus!#>4 then return aeval 'failed;
      z := limsort(cdr ex,x,a); % ignore car z, a list of 0's.
      nrms := caddr z; infs := cadr z;
      if length infs>1 then
         <<infs := logjoin('plus . infs,x);
           infs := if eqcar(infs,'plus) then cdr infs else list infs>>;
     % at this point, only infs needs to be evaluated.
      vals := for each c in infs collect
         minfix prepsq simp!* limit0(c,x,a);
      z := infs;
      for each c in vals do
         <<cz := car z; z := cdr z;
           if c eq 'infinity then vp := cz . vp
           else if c eq '(minus infinity) then vm := cz . vm
           else if c eq 'failed then vnix := cz . vnix
           else nrms := cz . nrms>>;
      if vm and not vp or vp and not vm or length vnix = 1
         or length vm > 1 or length vp > 1 then return aeval 'failed;
      if vm then vm := qform(car vp,vm);
      if vnix then vnix := qform(car vnix,cdr vnix);
      vm := append(nrms,append(vm,vnix));
      return if null vm then 0 else
         limit0(if length vm>1 then 'plus . vm else car vm,x,a) end;

symbolic procedure minfix v;
   if eqcar(v,'minus) and numberp cadr v then -cadr v else v;

symbolic procedure qform(a,b);
   list list('quotient,list('plus,1,
      list('quotient,if length b = 1 then car b else 'plus . b,a)),
         list ('quotient,1,a));

symbolic procedure lhopital(top,bot,xxx,a);
  begin scalar limt, limb, nvt, nvb;
     nvt := notval(limt := limfix(top,xxx,a));
     nvb := notval(limb := limfix(bot,xxx,a));
 % possibilities for lims are {failed, infinity, -infinity, bounded,
 % nonzero, zero} and each combination of cases has to be handled.
     if limt=0 and limb=0 or nvt and nvb then go to lhop;
     if specval limt or specval limb then return speccomb(limt,limb);
     if limb=0 then return aeval 'infinity;  % maybe impossible.
     return aeval list('quotient,limt,limb);
lhop: lhop!# := lhop!#+1;
    %  write "lhop#=",lhop!#; terpri();
      if lhop!#>6 then return aeval 'failed;
      return limit0(prepsq quotsq(diffsq(simp!* top,xxx),
          diffsq(simp!* bot,xxx)),xxx,a) end;

symbolic procedure notval lim;
   not lim or infinp prepsq simp!* lim;

symbolic procedure infinp x; member(x,'(infinity (minus infinity)));

symbolic procedure specval lim;
   notval lim or lim eq 'bounded;

symbolic procedure speccomb(a,b);
   if not a or not b or b eq 'bounded then aeval 'failed
   else if notval b then 0
   else if notval a then
      if numberp b then aeval
         if b>0 then a else
            if a eq 'infinity then '(minus infinity) else 'infinity
      else aeval list('quotient,a,b)
   else aeval 'failed;

symbolic procedure limfix(ex,x,a);
   (if val then val
       else limitest(ex,x,a))
    where val=limitset(ex,x,a);

symbolic procedure limitest(ex,x,a);
  if ex then if atom ex then if ex eq x then a else ex else
  begin scalar y,arg,val;
    if eqcar(ex,'expt) then
       if cadr ex eq 'e then ex := list('exp,caddr ex)
       else return exptest(cadr ex,caddr ex,x,a);
    if (y := get(car ex,'fixfn)) then
       <<arg := cadr ex; val := limitset(arg,x,a);
         return apply1(y,
          if val then val else limitest(arg,x,a))>>
    else if (y := get(car ex,'limcomb)) then
       return apply3(y,cdr ex,x,a) end;

symbolic procedure exptest(b,n,x,a);
   if numberp n then
      if n<0 then limquot1(1,exptest(b,-n,x,a))
      else if n=0 then 1 else
        ((if 2*y=n then limlabs limitest(b,x,a) else limitest(b,x,a))
         where y=n/2)
   else if numberp b and b>1 then limitest(list('exp,n),x,a);

symbolic procedure limlabs a;
   if null a then nil
   else if infinp a then 'infinity
   else if a eq 'bounded then 'bounded else
     begin scalar n,d; d := denr(n := simp!* a); n := numr n;
     return if null n then a else if not numberp n then nil
         else mk!*sq abs a ./ d end;

symbolic procedure limplus(exl,x,a);
   if null exl then 0
   else limplus1(mkalg limfix(car exl,x,a),limplus(cdr exl,x,a));

symbolic procedure limplus1(a,b);
   if null a or null b then nil
   else if infinp a
      then if infinp b
         then if a eq b then a else nil else a
   else if infinp b then b
   else if a eq 'bounded or b eq 'bounded then 'bounded
   else mk!*sq addsq(simp!* a,simp!* b);

symbolic procedure limtimes(exl,x,a);
   if null exl then 1
  else ltimes1(mkalg limfix(car exl,x,a),limtimes(cdr exl,x,a));

symbolic procedure mkalg x;
   minfix if eqcar(x,'!*sq) then prepsq simp!* x else x;

symbolic procedure ltimes1(a,b);
 begin scalar c;
  return if null a or null b then nil
   else if infinp a then
         if infinp b  then
           if a = b then 'infinity else '(minus infinity)
           else if b eq 'bounded or b=0 then nil
           else if (c := limposp b) eq 'failed then nil
           else if c then a else lminus1 a
   else if infinp b then
      if a eq 'bounded or a=0 then nil
      else if (c := limposp a) eq 'failed then nil
      else if c then b else lminus1 b
   else if a eq 'bounded or b eq 'bounded then 'bounded
   else mk!*sq multsq(simp!* a,simp!* b) end;

symbolic procedure limposp a;
  (if n and not numberp n then 'failed else n and n>0)
  where n=numr simp!* a;

symbolic procedure lminus(exl,x,a);
   lminus1 mkalg limfix(car exl,x,a);

symbolic procedure lminus1 a; if a then
   if a eq 'infinity then '(minus infinity)
   else if a eq '(minus infinity) then 'infinity
   else if a eq 'bounded then a
   else mk!*sq negsq simp!* a;

symbolic procedure limquot(exl,x,a);
   limquot1(mkalg limfix(car exl,x,a),mkalg limfix(cadr exl,x,a));

symbolic procedure limquot1(a,b);
 begin scalar c;
  return if null a or null b then nil
   else if infinp a then
         if infinp b then nil
           else if b eq 'bounded then nil
           else if b=0 then a
           else if (c := limposp b) eq 'failed then nil
           else if c then a else lminus1 a
   else if infinp b then 0
   else if a eq 'bounded then if b=0 then nil else 'bounded
   else if b=0 or b eq 'bounded then nil
   else mk!*sq quotsq(simp!* a,simp!* b) end;

put('log,'fixfn,'fixlog);
put('sin,'fixfn,'fixsin);
put('cos,'fixfn,'fixsin);
put('sqrt,'fixfn,'fixsqrt);
put('cosh,'fixfn,'fixcosh);
put('sinh,'fixfn,'fixsinh);
put('exp,'fixfn,'fixexp);
put('plus,'limcomb,'limplus);
put('minus,'limcomb,'lminus);
put('times,'limcomb,'limtimes);
put('quotient,'limcomb,'limquot);

symbolic procedure fixlog x;
   if zerop x then '(minus infinity) else if infinp x then 'infinity;

symbolic procedure fixsqrt x;
   if zerop x then 0 else if infinp x then 'infinity;

symbolic procedure fixsin x;
   if infinp x then 'bounded;

symbolic procedure fixcosh x;
   if infinp x then 'infinity;

symbolic procedure fixsinh x;
   if infinp x then x;

symbolic procedure fixexp x;
   if x eq 'infinity then x else if x = '(minus infinity) then 0;

endmodule;


module pf;  % Compute partial fractions for an expression.

% Author: Anthony C. Hearn.

Comment PF is the top level operator for finding the partial fractions
of an expression.  It returns the partial fractions as a list.

The algorithms used here are relatively unsophisticated, and use the
extended Euclidean algorithm to break up expressions into factors.
Much more sophisticated algorithms exist in the literature;

fluid '(!*exp !*limitedfactors !*gcd kord!*);

symbolic operator pf;

flag('(pf),'noval);   % Since PF will do its own simplification.

symbolic procedure pf(u,var);
   % Convert an algebraic expression into partial fractions.
   begin scalar !*exp,!*gcd,kord!*,!*limitedfactors,polypart,rfactor,
                u1,u2,u3,u4,var,x,xx,y;
      !*exp := !*gcd := t;
      xx := updkorder var;         % Make var the main variable.
      x := subs2 resimp simp!* u;  % To allow for OFF EXP forms.
      u1 := denr x;
      if degr(u1,var) = 0 then <<setkorder xx; return list('list,u)>>;
      u2 := qremsq(!*f2q numr x,!*f2q u1,var); %Extract polynomial part.
      if caar u2 then polypart := car u2;
      rfactor := 1 ./ 1;           % Factor for rational part.
      u2 := cdr u2;
      u3 := fctrf u1;              % Factorize denominator.
      x := cdr u3;
      u3 := car u3;
      % Process monomial part.
      while not domainp u3 do
       <<if mvar u3 eq var then x := (!*k2f mvar u3 . ldeg u3) . x
          else <<u4 := !*p2f lpow u3;
                 rfactor := numr rfactor ./ multf(u4,denr rfactor);
                 u1 := quotf(u1,u4)>>;
         u3 := lc u3>>;
      if u3 neq 1 then <<rfactor := numr rfactor
                                       ./ multf(u3,denr rfactor);
                         u1 := quotf(u1,u3)>>;
      % Separate power factors in denominator.
      while length x>1 do
       <<u3 := exptf(caar x,cdar x);
         u1 := quotf(u1,u3);
         if degr(u3,var)=0
           then <<rfactor := numr rfactor ./ multf(u3,denr rfactor);
                  u2 := nil>>
          else <<u4 := xeucl(u1,u3,var);
                 % Remove spurious polynomial in numerator.
                 y := (remsq(multsq(car u4,u2),!*f2q u3,var) . car x)
                        . y;
                 u2 := multsq(cdr u4,u2)>>;
         x := cdr x>>;
      u3 := exptf(caar x,cdar x);
      if u2 = (nil ./ 1) then nil
       else if degr(u3,var)=0
        then rfactor := numr rfactor ./ multf(u3,denr rfactor)
      % Remove spurious polynomial in numerator.
       else y := (remsq(u2,!*f2q u3,var) . car x) . y;
      x := nil;
      % Finally break down non-linear terms in denominator.
      for each j in y do
         if cddr j =1 then x := j . x
          else x := append(pfpower(car j,cadr j,cddr j,var),x);
      % Fold in rfactor.
      if rfactor neq '(1 . 1)
        then x := for each j in x
                     collect multsq(rfactor,car j) . cdr j;
      x := for each j in x
              collect list('quotient,prepsq!* car j,
                           if cddr j=1 then prepf cadr j
                            else list('expt,prepf cadr j,cddr j));
      if polypart then x := prepsq!* polypart . x;
      setkorder xx;
      return 'list . x
   end;

symbolic procedure xeucl(u,v,var);
   % Extended Euclidean algorithm with rational coefficients.
   % I.e., find polynomials Q, R in var with rational coefficients (as 
   % standard quotients) such that Q*u + R*v = 1, where u and v are
   % relatively prime standard forms in variable var.  Returns Q . R.
   begin scalar q,r,s,w;
      q := list(1 ./ 1,nil ./ 1);
      r := list(nil ./ 1,1 ./ 1);
      if degr(u,var) < degr(v,var)
        then <<s := u; u := v; v := s; s := q; q := r; r := s>>;
      u := !*f2q u; v := !*f2q v;
      while numr v do
       <<if degr(numr v,var)=0 then w := quotsq(u,v) . (nil ./ 1)
          else w := qremsq(u,v,var);
         s := list(addsq(car q,negsq multsq(car w,car r)),
                   addsq(cadr q,negsq multsq(car w,cadr r)));
         u := v;
         v := cdr w;
         q := r;
         r := s>>;
      v := lnc numr u ./ denr u;   % Is it possible for this not to be
                                   % in lowest terms, and, if so, does
                                   % it matter?
      r := quotsq(v,u);
      return multsq(r,quotsq(car q,v)) . multsq(r,quotsq(cadr q,v))
  end;

symbolic procedure qremsq(u,v,var);
   % Find rational quotient and remainder (as standard quotients)
   % dividing standard quotients u by v wrt var.
   % This should really be done more directly without using quotsq.
   (quotsq(addsq(u,negsq x),v) . x) where x=remsq(u,v,var);

symbolic procedure remsq(u,v,var);
   % Find rational and remainder (as a standard quotient) on
   % dividing standard quotients u by v wrt var.
   begin integer m,n; scalar x;
      n := degr(numr v,var);
      if n=0 then rederr list "Remsq given zero degree polynomial";
      while (m := degr(numr u,var))>= n do
       <<if m=n then x := v
          else x := multsq(!*p2q(var.**(m-n)),v);
         u := addsq(u,
                    negsq multsq(multf(lc numr u,denr v)
                                   ./ multf(lc numr v,denr u),
                                 x))>>;
      return u
   end;

symbolic procedure pfpower(u,v,n,var);
   % Convert u/v^n into partial fractions.
   begin scalar x,z;
      while degr(numr u,var)>0 do
       <<x := qremsq(u,!*f2q v,var);
         z := (cdr x . v . n) . z;
         n := n-1;
         u := car x>>;
      if numr u then z := (u . v . n) . z;
      return z
   end;

endmodule;


module sum; % Package for summation in finite terms.

% Authors: K.Yamamoto, K.Kishimoto & K.Onaga  Hiroshima Univ.
% Modified by: F.Kako                         Hiroshima Univ.
%         Fri Sep. 19, 1986
%         Mon Sep. 7, 1987   added PROD operator (by F. Kako)
% e-mail: kako@kako.math.sci.hiroshima-u.ac.jp
%         or D52789%JPNKUDPC.BITNET

% Usage:
%         sum(expression,variable[,lower[,upper]]);
%         lower and upper are optionals.

%         prod(expression,variable[,lower[,upper]]);
%         returns product of expression.

fluid '(!*trsum);               % trace switch;

switch trsum;

symbolic procedure simp!-sum u;
%ARGUMENT  CAR U: expression of prefix form;
%         CADR U: kernel;
%        CADDR U: lower bound;
%       CADDDR U: upper bound;
%value            : expression of sq form;
   begin scalar v,y,upper,lower,lower1,dif;
      y := cdr u;
      u := simp!* car u;
      if null numr u then return (nil ./ 1)
       else if atom y then return u;
      if not atom cdr y then <<
          lower := cadr y;
          lower1 := if numberp lower then lower - 1
                     else list('plus,lower,-1);
          upper := if not atom cddr y then caddr y else car y;
          dif := addsq(simp!* upper, negsq simp!* lower);
          if denr dif = 1 then
              if null numr dif then return u
                else if fixp numr dif then dif := numr dif
                else dif := nil
           else dif := nil;
          if dif and dif <= 0 then return nil ./ 1;
          if atom cddr y then upper := nil>>;
      v := !*a2k car y;
      return simp!-sum1(u,v,y,upper,lower,lower1,dif)
   end;

symbolic procedure simp!-sum1(u,v,y,upper,lower,lower1,dif);
   begin scalar w,lst,x,z,flg;
      lst := sum!-split!-log(u,v);
      w := car lst;
      lst := cdr lst;
      u := nil ./ 1;
    a:
      if null w then go to b;
      x := multsq(caar w,
                  simp!-prod1(cdar w,v,y,upper,lower,lower1,dif));
      u := addsq(u,simp!* list('log, prepsq x));
      w := cdr w;
      go to a;
    b:
       if null lst then return u;
            flg := nil;
            z := car lst;
            if !*trsum then <<
               prin2!* "Summation ";sqprint z;prin2!*  " w.r.t ";
               xprinf(!*k2f v,nil,nil);terpri!* t >>;
%           z := reorder numr z ./ reorder denr z;
            w := sum!-sq(z,v);
            if w = 'failed then <<
                if !*trsum then <<
                     prin2!* "UMM-SQ failed. Trying SUM-TRIG";
                     terpri!* t>>;
                w := sum!-trig(z,v);
                if w = 'failed then <<
                     if !*trsum then <<
                         prin2!* "SUM-TRIG failed.";
                         terpri!* t>>;
                     w := sum!-unknown(z,v,y,lower,dif);
                     flg := car w;
                     w := cdr w>>>>;
            if !*trsum then <<
                 prin2!* "Result  = "; sqprint w; terpri!* t >>;
            if flg then goto c;
            if upper then
                w := addsq(subsq(w,list(v . upper)),
                           negsq subsq(w,list(v . lower1)))
             else if lower then
                w := addsq(w , negsq subsq(w, list(v . lower1)));
   c:
            u := addsq(u,w);
            lst := cdr lst;
            goto b
   end;


put('sum,'simpfn,'simp!-sum);

%*********************************************************************
%       Case of trigonometric or other functions
%       Trigonometric functions are expressed in terms of exponetials.
%       Pattern matching to get the summation in closed form.
%********************************************************************;

global '(!*trig!-to!-exp);              % variable to indicate
                                        % that the expression contains
                                        % some trig. functions.

symbolic procedure sum!-trig(u,v);
   begin scalar lst,w;  % z;
      !*trig!-to!-exp := nil;           % trig. to exponential.
      u := trig!-to!-expsq(u,v);
      if not !*trig!-to!-exp then return 'failed;
      lst := sum!-term!-split(u,v);
      u := nil ./ 1;
   a:
      if null lst then return exp!-to!-trigsq u;
%     z := reorder numr car lst ./ reorder denr car lst;
%     w := sum!-sq(z,v);
      w := sum!-sq(car lst,v);
      if w = 'failed then return 'failed;
%      w := exp!-to!-trigsq w;     % exponential to trig. function.
      u := addsq(u,w);
      lst := cdr lst;
      goto a
   end;


symbolic procedure sum!-unknown(u,v,y,lower,dif);
   begin scalar z,w;
     if null dif then <<
          z := 'sum . (prepsq u . list car y);
          if w := opmtch z then return (nil . simp w)
           else if null cdr y then return (t . mksq(z,1));
          z := 'sum . (prepsq u . y);
          return (t . if w := opmtch z then simp w else mksq(z,1))>>;
     z := nil ./ 1;
  a:
     if dif < 0 then return (t . z);
     z := addsq(z,subsq(u,list(v . list('plus,lower,dif))));
     dif := dif - 1;
     goto a
   end;


%*********************************************************************
%       Summation by Gosper's algorithm.
%********************************************************************;

symbolic procedure sum!-sq(u,v);
   %Argument U : expression of s-q;
   %         V : kernel;
   %value        : expression of sq (result of summation.);
   begin scalar gn,fn,pn,rn,qn,z,k,x;
      if null numr u then return nil ./ 1;
      x := setkorder list v;
      z := reorder numr u;
      u := z ./ reorder denr u;
      if !*trsum then <<
            prin2t " *** Summation by Gosper's algorithm ***";
            prin2!* "    A(n) = "; sqprint u;terpri!* t;
            terpri!* t>>;
      if domainp z or not (mvar z eq v) or red z then
            <<pn := 1; z := u>>
       else <<pn := !*p2f lpow z;
              z := lc z ./ denr u>>;
      z := quotsq(z,nsubsq(z,v, - 1));
      gn := gcdf!*(numr z,denr z);
      if !*trsum then <<
         prin2!* "A(n)/A(n-1) = ";sqprint z;terpri!* t;
         prin2!* "GN = ";xprinf(gn,nil,nil);terpri!* t>>;
      qn := quotf!*(numr z, gn);
      rn := quotf!*(denr z, gn);
      if nonpolyp(qn,v) or nonpolyp(rn,v) then go to fail;
      if !*trsum then <<
         prin2!* "Initial qn, rn and pn are "; terpri!* t;
         prin2!* "QN = ";xprinf(qn,nil,nil);terpri!* t;
         prin2!* "RN = ";xprinf(rn,nil,nil);terpri!* t;
         prin2!* "PN = ";xprinf(pn,nil,nil);terpri!* t>>;
      k := compress explode '!+j;
      z := integer!-root(resultant(qn,nsubsf(rn,v,k),v),k);
      if !*trsum then <<
         prin2 "Root of resultant(q(n),r(n+j)) are "; prin2t z >>;
      while z do <<
            k := car z;
            gn := gcdf!*(qn,nsubsf(rn,v,k));
            qn := quotf!*(qn,gn);
            rn := quotf!*(rn,nsubsf(gn,v, -k));
            while (k := k - 1)>=0 do
               pn := multf(pn,nsubsf(gn,v, -k));
            z := cdr z>>;
      if !*trsum then <<
         prin2!* "Shift free  qn, rn and pn are";terpri!* t;
         prin2!* "QN = ";xprinf(qn,nil,nil);terpri!* t;
         prin2!* "RN = ";xprinf(rn,nil,nil);terpri!* t;
         prin2!* "PN = ";xprinf(pn,nil,nil);terpri!* t>>;
      qn := nsubsf(qn,v,1);
      if (k := degree!-bound(pn,addf(qn,rn),addf(qn,negf rn),v)) < 0
         then go to fail;
      if !*trsum then <<
         prin2 "DEGREE BOUND is "; prin2t k >>;
      if not(fn := solve!-fn(k,pn,qn,rn,v)) then go to fail;
      if !*trsum then <<
         prin2!* "FN = ";sqprint fn;terpri!* t >>;
      u := multsq(multsq(qn ./ 1,fn), multsq(u, 1 ./ pn));
      z := gcdf!*(numr u, denr u);
      u := quotf!*(numr u, z) ./ quotf!*(denr u,z);
      if !*trsum then <<
            prin2t " *** Gosper's algorithm completed ***";
            prin2!* "    S(n) = "; sqprint u;terpri!* t;
            terpri!* t>>;
      setkorder x;
      return (reorder numr u ./ reorder denr u);
  fail:
      if !*trsum then <<
            prin2t " *** Gosper's algorithm failed ***";
            terpri!* t>>;
      setkorder x;
      return 'failed
   end;

%*********************************************************************
%       integer root isolation
%********************************************************************;

symbolic procedure integer!-root(u,v);
% Produce a list of all positive integer root of U;
   begin scalar x,root,n,w;
        x := setkorder list v;
        u := reorder u;
        if domainp u or not(mvar u eq v) then go to a;
        u := numr cancel(u ./ lc u);
        w := u;                                 % get trailing term;
        while not domainp w and mvar w eq v and cdr w do
            w := cdr w;
        if (n := degr(w,v)) > 0 then <<
            w := lc w;
            while n > 0 do <<
               root := 0 . root;
               n := n - 1>>>>;
        n := dfactors lowcoef w;                % factor tail coeff.
        w := (v . 1) . 1;
        while n do <<
            if not testdivide(u,v,car n) then <<
                root := car n . root;
                u := quotf!*(u, (w . - car n))>>
             else n := cdr n>>;
  a:
        setkorder x;
        return root
   end;


symbolic procedure lowcoef u;
   begin scalar lst,m;
        lst := dcoefl u;
        m := 0;
  a:
        if null lst then return m;
        m := gcdn(m,car lst);
        if m = 1 then return 1;
        lst := cdr lst;
        go to a
   end;


symbolic procedure dcoefl u;
   if domainp u then if fixp u then list abs u else nil
    else nconc(dcoefl lc u , dcoefl red u);

symbolic procedure testdivide(u,v,n);
% Evaluate U at integer point (V = N);
   begin scalar x;
 a:
       if domainp u or not(mvar u eq v) then return addf(u,x);
       x := addf(multd(expt(n,ldeg u),lc u),x);
       if (u := red u) then go to a;
       return x
   end;


%*********************************************************************
%********************************************************************;

symbolic procedure degree!-bound(pn,u,v,kern);
% degree bound for fn;
%       u: q(n+1) + r(n);
%       v: q(n+1) - r(n);
   begin scalar lp,l!+, l!-, x,m,k;
      x := setkorder list kern;
      u := reorder u;
      v := reorder v;
      pn := reorder pn;
      l!+ := if u then degr(u,kern) else -1;
      l!- := if v then degr(v,kern) else -1;
      lp := if pn then degr(pn,kern) else -1;
      if l!+ <= l!- then <<k := lp - l!-;go to  a>>;
      k := lp - l!+ + 1;
      if l!+ > 0 then u := lc u;
      if l!- > 0 then v := lc v;
      if l!+ = l!- + 1 and fixp(m := quotf1(multd(-2,v),u)) then
        k := max(m,k)
       else if lp = l!- then k := max(k,0);
   a:
      setkorder x;
      return k
   end;

%*********************************************************************
%       calculate polynomial f(n) such that
%       p(n) - q(n+1)*f(n) + r(n)*f(n-1) = 0;
%********************************************************************;

symbolic procedure solve!-fn(k,pn,qn,rn,v);
   begin scalar i,fn,x,y,z,u,w,c,clst,flst;
      c := makevar('c,0);
      clst := list c;
      fn := !*k2f c;
      i := 0;
      while (i := i + 1) <= k do <<
         c := makevar('c,i);
         clst := c . clst;
         fn := ((v . i) . !*k2f c) . fn>>;
      z :=
       addf(pn,
            addf(negf multf(qn,fn),
                 multf(rn,nsubsf(fn,v, - 1))));
      x := setkorder (v . clst);
      z := reorder z;
      c := clst;
      if !*trsum then <<
         prin2!* "C Equation is";terpri!* t;
         xprinf(z,nil,nil);terpri!* t >>;
  a:
      if domainp z or
         domainp (y := if mvar z eq v then lc z else z) then
           go to fail;
      w := mvar y;
      if not(w memq clst) then go to fail;
      if !*trsum then <<
         prin2!* "C Equation to solve is ";xprinf(y,nil,nil);terpri!* t;
         prin2!* " w.r.t ";xprinf(!*k2f w,nil,nil);terpri!* t >>;
      u := gcdf!*(red y , lc y);
      u := quotf!*(negf red y, u) ./ quotf!*(lc y, u);
      flst := (w . u) . flst;
      z := subst!-cn(z,w,u);
      if !*trsum then <<
         xprinf(!*k2f w,nil,nil);prin2!* " := ";sqprint u;terpri!* t >>;
      clst := deleteq(clst,w);
      if z then go to a;
      setkorder c;
      fn := reorder fn;
      u := 1;
      while not domainp fn and mvar fn memq c do <<
         w := mvar fn;
         z := atsoc(w,flst);
         fn := subst!-cn(fn,w,if z then cdr z);
         if z then u := multf(u,denr cdr z);
         z := gcdf!*(fn,u);
         fn := quotf!*(fn,z);
         u := quotf!*(u,z)>>;
      setkorder x;
      return cancel(reorder fn ./ reorder u);
 fail:
     if !*trsum then <<
        prin2t "Fail to solve C equation.";
        prin2!* "Z := ";xprinf(z,nil,nil);terpri!* t >>;
     setkorder x;
     return nil
   end;


symbolic procedure subst!-cn(u,v,x);
   begin scalar z;
      z := setkorder list v;
      u := reorder u;
      if not domainp u and mvar u eq v then
         if x then u := addf(multf(lc u,reorder numr x),
                             multf(red u,reorder denr x))
          else u := red u;
      setkorder z;
      return reorder u
   end;



symbolic procedure makevar(id,n);
  compress nconc(explode id, explode n);

symbolic procedure deleteq(u,x);
   if null u then nil
    else if car u eq x then cdr u
    else car u . deleteq(cdr u, x);


symbolic procedure nsubsf(u,kern,i);
% ARGUMENT U : expression of sf;
%          KERN : kernel;
%          I : integer or name of integer variable;
% value        : expression of sf;
   begin scalar x,y,z,n;
      if null i or i = 0 then return u;
      x := setkorder list kern;
      u := reorder u;
      y := addf(!*k2f kern,
                if fixp i then i else !*k2f i);
      z := nil;
   a:
      if domainp u or not(mvar u eq kern) then goto b;
      z := addf(z,lc u);
      n := degr(u,kern) - degr(red u,kern);
      u := red u;
   a1:
      if n <= 0 then goto a;
      z := multf(z,y);
      n := n - 1;
      go to a1;
   b:
      z := addf(z,u);
      setkorder x;
      return reorder z
   end;


symbolic procedure nsubsq(u,kern,i);
% ARGUMENT U : expression of sq;
%       KERN : kernel;
%          I : integer or name of integer variable;
% value        : expression of sq;
   subsq(u,list(kern . list('plus, kern, i)));


%*********************************************************************
%       dependency check
%********************************************************************;

symbolic procedure nonpolyp(u,v);
% check U is not a polynomial of V;
   if domainp u then nil
    else (not(mvar u eq v) and depend!-p(mvar u,v))
         or nonpolyp(lc u,v) or nonpolyp(red u,v);


symbolic procedure depend!-sq(u,v);
   depend!-f(numr u,v) or depend!-f(denr u,v);


symbolic procedure depend!-f(u,v);
   if domainp u then nil
    else depend!-p(mvar u,v) or
         depend!-f(lc u,v) or
         depend!-f(red u,v);


symbolic procedure depend!-p(u,v);
   if u eq v then t
    else if atom u then nil
    else if not atom car u then depend!-f(u,v)
    else if car u eq '!*sq then depend!-sq(cadr u, v)
    else depend!-l(cdr u, v);

symbolic procedure depend!-l(u,v);
   if null u then nil
    else if depend!-sq(simp car u, v) then t
    else depend!-l(cdr u,v);


%*********************************************************************
%       term splitting
%********************************************************************;

symbolic procedure sum!-term!-split(u,v);
   begin scalar y,z,klst,lst,x;
      x := setkorder list v;
      z := qremf(reorder numr u, y := reorder denr u);
      klst := kern!-list(car z,v);
      lst := termlst(car z, 1 ./ 1, klst);
      klst := kern!-list(cdr z,v);
      if depend!-f(y,v) then klst := deleteq(klst,v);
      lst := append(lst, termlst(cdr z, 1 ./ y, klst));
      setkorder x;
      return lst
   end;


symbolic procedure kern!-list(u,v);
% Returns list of kernels that depend on V;
   begin scalar x;
      for each j in kernels u do if depend!-p(j,v) then x := j . x;
      return x
   end;

symbolic procedure termlst(u,v,klst);
   begin scalar x,kern,lst;
      if null u then return nil
       else if null klst or domainp u then
                 return list multsq(!*f2q u,v);
      kern := car klst;
      klst := cdr klst;
      x := setkorder list kern;
      u := reorder u;
      v := reorder(numr v) ./ reorder(denr v);
      while not domainp u and mvar u eq kern do <<
         lst := nconc(termlst(lc u, multsq(!*p2q lpow u, v),klst),lst);
         u := red u>>;
      if u then lst := nconc(termlst(u,v,klst),lst);
      setkorder x;
      return lst
   end;


%*********************************************************************
%       Express trigonometric functions (such as sin, cos ..)
%       by exponentials.
%********************************************************************;

symbolic procedure trig!-to!-expsq(u,v);
   multsq(trig!-to!-expf(numr u,v),
          invsq trig!-to!-expf(denr u,v));


symbolic procedure trig!-to!-expf(u,v);
   if domainp u then u ./ 1
    else addsq(multsq(trig!-to!-expp(lpow u,v),
                      trig!-to!-expf(lc u,v)),
               trig!-to!-expf(red u,v));


symbolic procedure trig!-to!-expp(u,v);
   begin scalar w,x,z,n,wi;
      n := cdr u;          % integer power;
      z := car u;          % main variable;
      if atom z or not atom (x := car z) or not depend!-p(z,v) then
           return !*p2q u;
      if x memq '(sin cos tan sec cosec cot) then <<
          !*trig!-to!-exp := t;
          w := multsq(!*k2q 'i, simp!* cadr z);
          w := simp!* list('expt,'e, mk!*sq w);
%         W := SIMP LIST('EXPT,'E, 'TIMES . ( 'I . CDR Z));
          wi := invsq w;
          if x eq 'sin then
              w := multsq(addsq(w ,negsq wi),
                          1 ./ list(('i .** 1) .* 2))
           else if x eq 'cos then
              w := multsq(addsq(w, wi), 1 ./ 2)
           else if x eq 'tan then
              w := multsq(addsq(w,negsq wi),
                          invsq addsq(w,wi))
           else if x eq 'sec then
              w := multsq(2 ./ 1, invsq addsq(w, wi))
           else if x eq 'cosec then
              w := multsq(list(('i .** 1) .* 2),
                          invsq addsq(w, negsq wi))
           else
              w := multsq(addsq(w, wi),
                          invsq addsq(w, negsq wi))
                     >>
       else if x memq '(sinh cosh tanh sech cosech coth) then <<
          !*trig!-to!-exp := t;
          w := simp!* list('expt,'e,cadr z);
          wi := invsq w;
          if x eq 'sinh then
              w := multsq(addsq(w,negsq wi), 1 ./ 2)
           else if x eq 'cosh then
              w := multsq(addsq(w,wi), 1 ./ 2)
           else if x eq 'tanh then
              w := multsq(addsq(w,negsq wi),
                          invsq addsq(w,wi))
           else if x eq 'sech then
              w := multsq(2 ./ 1, invsq addsq(w, wi))
           else if x eq 'cosech then
              w := multsq(2 ./ 1, invsq addsq(w, negsq wi))
           else
              w := multsq(addsq(w,wi),
                          invsq addsq(w, negsq wi))
                 >>
       else return !*p2q u;
      return exptsq(w,n)
   end;

%*********************************************************************
%       Inverse of trig!-to!-exp.
%       Express exponentials in terms of trigonometric functions
%                (sin, cos, sinh and cosh)
%                               Wed Dec. 17, 1986 by F. Kako;
%********************************************************************;

symbolic procedure exp!-to!-trigsq u;
   multsq(exp!-to!-trigf numr u,
          invsq exp!-to!-trigf denr u);

symbolic procedure exp!-to!-trigf u;
   begin scalar v,v1,x,y,n;
      u := termlst1(u,1,nil ./1);
      v := nil;
   a:
      if null u then go to b;
      x := caar u;
      y := cdar u;
      u := cdr u;
   a1:
      if u and y = cdar u then <<
         x := addf(x,caar u);
         u := cdr u;
         go to a1>>;
      v := (x . y) . v;
      go to a;
   b:
      v1 := reverse v;
      n := length v;
      u := nil ./ 1;
   c:
      if n = 0 then return u
       else if n = 1 then
          return addsq(u,
                       multsq(!*f2q caar v,
                              simp!* list('expt,'e,mk!*sq cdar v)));
      u := addsq(u,exp!-to!-trigl(caar v1,caar v,cdar v1,cdar v));
      v := cdr v;
      v1 := cdr v1;
      n := n - 2;
      go to c
   end;

symbolic procedure exp!-to!-trigl(a,b,c,d);
%       A*E**C + B*E**D
%               -->
%       ((A+B)*COSH((C-D)/2)+(A-B)*SINH((C-D)/2))*E**((C+D)/2);
%       A, B: sf;
%       C, D: sq;
   begin scalar x,y,z;
      x := !*f2q addf(a,b);
      y := !*f2q addf(a, negf b);
      z := multsq(addsq(c,negsq d), 1 ./ 2);
      z := real!-imag!-sincos z;
      return multsq(simp!* list('expt,'e,
                                mk!*sq multsq(addsq(c,d),1 ./ 2)),
                    addsq(multsq(x, cdr z),
                          multsq(y, car z)))
   end;


symbolic procedure termlst1(u,v,w);
%ARGUMENT U : sf;
%         V : sf;
%         W : sq;
%value      : list of (sf . sq);
   begin scalar x,y;
      if null u then return nil
       else if domainp u then return list (multf(u,v) . w);
      x := mvar u;
      y := if atom x or not(car x eq 'expt) or not(cadr x eq 'e) then
              termlst1(lc u,multf(!*p2f lpow u,v),w)
            else termlst1(lc u,v,addsq(w,multsq(simp!* caddr x,
                                                ldeg u ./ 1)));
      return nconc(y,termlst1(red u,v,w))
   end;


%*********************************************************************
%       Module ---  COMPLEX;
%                               Wed Dec. 17, 1986 by F. Kako;
%********************************************************************;


%******************************************************************
%*******        SPLIT REAL AND IMAGINARY PART    ******************
%******************************************************************


symbolic procedure real!-imag!-sq u;
%U is a standard quotient,
%Value is the standard quotient real part and imaginary part of U.
   begin scalar x,y;
      x := real!-imag!-f numr u;
      y := real!-imag!-f denr u;
      u := addf(multf(car y, car y),
                multf(cdr y, cdr y));         % Re Y **2 + Im Y **2;
      return (cancel(addf(multf(car x, car y),
                          multf(cdr x, cdr y))
                     ./ u) .
              cancel(addf(multf(car y, cdr x),
                          negf multf(car x, cdr y))
                     ./ u))
   end;

symbolic procedure real!-imag!-f u;
   %U is a standard form.
   %Value is the standard form real and imag part of U.
   begin scalar x;
      if domainp u then return u . nil;
      x := setkorder list 'i;
      u := reorder u;
      u := if mvar u eq 'i and ldeg u = 1 then red u . lc u
            else u . nil;
      setkorder x;
      return (reorder car u . reorder cdr u)
   end;

%*****************************************************************
%       hyperbolic functions
%*****************************************************************;

symbolic procedure real!-imag!-sincos u;
   begin scalar v,w,z;
      v := real!-imag!-sq u;
      if null cadr v then <<
                u := prepsq u;
                return simp!* list('sinh,u)
                        . simp!* list('cosh,u)>>
       else if null caar v then <<
                u := prepsq cdr v;
                return (multsq(!*k2q 'i, simp!* list('sin,u))
                         . simp!* list('cos,u))>>;
      u := prepsq cdr v;
      v := prepsq car v;
      w := simp!* list('cos,u);
      u := simp!* list('sin,u);
      u := multsq(!*k2q 'i,u);
      z := simp!* list('cosh,v);
      v := simp!* list('sinh,v);
      return (addsq (multsq(w, v), multsq(u,z)))
                . (addsq (multsq(w,z),multsq(u,v)))
   end;


%*********************************************************************
%       module --- product
%       package for production in finite terms
%
%       Author: F.Kako                      Hiroshima Univ.
%                               Mon Sep. 7, 1987
%
%       usage:
%               prod(expression,variable[,lower[,upper]]);
%               lower and upper are optionals;
%
%
%********************************************************************;


%*********************************************************************
%********************************************************************;

symbolic procedure simp!-prod u;
%ARGUMENT  CAR U: expression of prefix form;
%         CADR U: kernel;
%        CADDR U: lower bound;
%       CADDDR U: upper bound;
%value            : expression of sq form;
   begin scalar v,y,upper,lower,lower1,dif;
      y := cdr u;
      u := simp!* car u;
      if null numr u then return (1 ./ 1)
       else if atom y then return u;
      if not atom cdr y then <<
          lower := cadr y;
          lower1 := if numberp lower then lower - 1
                     else list('plus,lower,-1);
          upper := if not atom cddr y then caddr y else car y;
          dif := addsq(simp!* upper, negsq simp!* lower);
          if denr dif = 1 then
              if null numr dif then return u
                else if fixp numr dif then dif := numr dif
                else dif := nil
           else dif := nil;
          if dif and dif <= 0 then return 1 ./ 1;
          if atom cddr y then upper := nil>>;
      v := !*a2k car y;
      return simp!-prod1(u,v,y,upper,lower,lower1,dif)
   end;


symbolic procedure simp!-prod1(u,v,y,upper,lower,lower1,dif);
   begin scalar w,lst,x,z,flg;
      lst := prod!-split!-exp(u,v);
      w := car lst;
      lst := cdr lst;
      u := 1 ./ 1;
    a:
      if null w then go to b;
      x := simp!-sum1(cdar w,v,y,upper,lower,lower1,dif);
      u := multsq(u,simpexpt list(caar w, prepsq x));
      w := cdr w;
      go to a;
    b:
       if null lst then return u;
            flg := nil;
            z := car lst;
            if !*trsum then <<
               prin2!* "Product ";sqprint z;prin2!*  " w.r.t ";
               xprinf(!*k2f v,nil,nil);terpri!* t >>;
%           z := reorder numr z ./ reorder denr z;
            w := prod!-sq(z,v);
            if w = 'failed then <<
                if !*trsum then <<
                     prin2!* "PROD-SQ failed.";
                     terpri!* t>>;
                w := prod!-unknown(z,v,y,lower,dif);
                flg := car w;
                w := cdr w>>;
            if !*trsum then <<
                 prin2!* "Result  = "; sqprint w;terpri!* t >>;
            if flg then goto c;
            if upper then
                w := multsq(subsq(w,list(v . upper)),
                           invsq subsq(w,list(v . lower1)))
             else if lower then
                w := multsq(w , invsq subsq(w, list(v . lower1)));
   c:
            u := multsq(u,w);
            lst := cdr lst;
            goto b
   end;


put('prod,'simpfn,'simp!-prod);

%*********************************************************************
%       Case of other functions
%********************************************************************;


symbolic procedure prod!-unknown(u,v,y,lower,dif);
   begin scalar z,w;
     if null dif then <<
          z := 'prod . (prepsq u . list car y);
          if w := opmtch z then return (nil . simp w)
           else if null cdr y then return (t . mksq(z,1));
          z := 'prod . (prepsq u . y);
          return (t . if w := opmtch z then simp w else mksq(z,1))>>;
     z := 1 ./ 1;
  a:
     if dif < 0 then return (t . z);
     z := multsq(z,subsq(u,list(v . list('plus,lower,dif))));
     dif := dif - 1;
     goto a
   end;


%*********************************************************************
%       Product of rational function
%********************************************************************;

symbolic procedure prod!-sq(u,v);
%ARGUMENT U : expression of s-q;
%         V : kernel;
%value        : expression of sq (result of product.);
   begin scalar gn,p1n,p2n,rn,qn,z,k,x,y;
      if null numr u then return 1 ./ 1;
      x := setkorder list v;
      qn := reorder numr u;
      rn := reorder denr u;
      if !*trsum then <<
            prin2t " *** Product of A(n) = qn/rn with ***";
            prin2!* "QN = ";xprinf(qn,nil,nil);terpri!* t;
            prin2!* "RN = ";xprinf(rn,nil,nil);terpri!* t>>;
      if nonpolyp(qn,v) or nonpolyp(rn,v) then go to fail;
      k := compress explode '!+j;
      z := integer!-root2(resultant(qn,nsubsf(rn,v,k),v),k);
      if !*trsum then <<
         prin2 "Root of resultant(q(n),r(n+j)) are "; prin2t z >>;
      p2n := p1n := 1;
      while z do <<
            k := car z;
            gn := gcdf!*(qn,nsubsf(rn,v,k));
            qn := quotf!*(qn,gn);
            rn := quotf!*(rn,nsubsf(gn,v, -k));
            if k > 0 then
                while (k := k - 1)>=0 do <<
                   p1n := multf(p1n,nsubsf(gn,v, -k));
                   if y := prod!-nsubsf(gn,v,-k)
                     then p2n := multf(p2n,y)>>
             else if k < 0 then
                while k < 0 do <<
                   p2n := multf(p2n,nsubsf(gn,v, -k));
                   if y := prod!-nsubsf(gn,v,-k)
                     then p1n := multf(p1n,y);
                   k := k + 1>>;
            z := cdr z>>;
      if depend!-f(qn,v) or depend!-f(rn,v) then go to fail;
      u := multsq(p1n ./ p2n, simpexpt list(prepsq (qn ./ rn), v));
      if !*trsum then <<
            prin2t " *** Product of rational function calculated ***";
            prin2!* "    P(n) = "; sqprint u;terpri!* t;
            terpri!* t>>;
      setkorder x;
      return (reorder numr u ./ reorder denr u);
      return u;
  fail:
      if !*trsum then <<
            prin2t " *** Product of rational function failed ***";
            terpri!* t>>;
      setkorder x;
      return 'failed
   end;

symbolic procedure prod!-nsubsf(u,kern,i);
% ARGUMENT U : expression of sf;
%          KERN : kernel;
%          I : integer;
% value        : expression of sf;
   begin scalar x,z,n;
      x := setkorder list kern;
      u := reorder u;
      z := nil;
   a:
      if domainp u or not(mvar u eq kern) then goto b;
      z := addf(z,lc u);
      n := degr(u,kern) - degr(red u,kern);
      u := red u;
      if i = 0 then if n = 0 then nil else z := nil
       else z := multf(z,expt(i,n));
      go to a;
   b:
      z := addf(z,u);
      setkorder x;
      return reorder z
   end;

%*********************************************************************
%       integer (positive and negative) root isolation
%********************************************************************;

symbolic procedure integer!-root2(u,v);
% Produce a list of all integer root of U;
   begin scalar x,root,n,w;
        x := setkorder list v;
        u := reorder u;
        if domainp u or not(mvar u eq v) then go to a;
        u := numr cancel(u ./ lc u);
        w := u;                                 % get trailing term;
        while not domainp w and mvar w eq v and cdr w do
            w := cdr w;
        if (n := degr(w,v)) > 0 then <<
            w := lc w;
            while n > 0 do <<
               root := 0 . root;
               n := n - 1>>>>;
        n := dfactors lowcoef w;                % factor tail coeff.;
        w := (v . 1) . 1;
        while n do <<
            if not testdivide(u,v,car n) then <<
                root := car n . root;
                u := quotf!*(u, (w . - car n))>>
             else if not testdivide(u,v,- car n) then <<
                root := (- car n) . root;
                u := quotf!*(u, (w . car n))>>
             else n := cdr n>>;
  a:
        setkorder x;
        return root
   end;



%*********************************************************************
%       log and exponential term splitting for summation and product
%********************************************************************;


symbolic procedure sum!-split!-log(u,v);
   begin scalar x,y,z,lst,llst,mlst;
      lst := sum!-term!-split(u,v);
   a:
      if null lst then return (llst. mlst);
      u := car lst;
      lst := cdr lst;
      z := numr u;
      if domainp z or red z or not (tdeg (z := lt z) = 1) or
          atom tvar z or not ((car tvar z) eq 'log)
          or depend!-f(tc z,v) or depend!-f(denr u,v)
        then <<mlst := u . mlst;go to a>>;
      y := reorder tc z ./ reorder denr u;
      z := simp!* cadr tvar z;
      if x := assoc(y,llst) then rplacd(x,multsq(cdr x,z))
       else if x := assoc(negsq y,llst)
             then rplacd(x,multsq(cdr x,invsq z))
       else llst := (y . z) . llst;
      go to a
   end;


symbolic procedure prod!-split!-exp(u,v);
   begin scalar x,y,z,w,klst,lst;
%     lst := kernels(numr u,nil);
      lst := kernels numr u;
%     lst := kernels1denr u,lst);
      lst := kernels1(denr u,lst);
   a:
      if null lst then go to b;
      z := car lst;
      if not atom z and car z eq 'expt and
         not depend!-p(cadr z,v) and depend!-p(caddr z,v)
        then klst := z . klst;
      lst := cdr lst;
      go to a;
   b:
      if null klst then return (nil . list u);
      x := setkorder klst;
      z := reorder numr u;
      y := reorder denr u;
   c:
      if domainp z or red z or not memq(w := mvar z,klst)
       then go to d;
      v := multsq(tdeg lt z ./ 1,simp!* caddr w);
      w := cadr w;
      if u := assoc(w,lst) then rplacd(u,addsq(cdr u,v))
       else lst := (w . v) . lst;
      z := tc lt z;
      go to c;
   d:
      if domainp y or red y or not memq(w := mvar y,klst)
       then go to e;
      v := multsq(tdeg lt y ./ 1,negsq simp!* caddr w);
      w := cadr w;
      if u := assoc(w,lst) then rplacd(u,addsq(cdr u,v))
       else lst := (w . v) . lst;
      y := tc lt y;
      go to d;
   e:
      setkorder x;
      u := reorder z ./ reorder y;
      return (lst . list u)
   end;

endmodule;


end;
