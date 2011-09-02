module patches; % Patches to correct problems in REDUCE 3.7.

% Author: Anthony C. Hearn.

% Copyright (c) 2001 Anthony C. Hearn.  All Rights Reserved.

global '(patch!-date!*);

patch!-date!* := "7-Sep-2001";

% Bugs fixed by these patches.

% 28 Jun 99.  Gnuplot handling on the Macintosh was not correct.

%  7 Aug 99.  The evaluation of df(tan((sqrt(1-x^2)*asin acos x
%                + 2*sqrt(1-x^2)*x)/x),x) did not terminate.

% 20 Oct 99.  The sequence a1:=12x^2-16x+3; a2:=3x-4; off mcd;
%             on combineexpt; e^(a1/a2); gave the wrong answer.

%  8 Nov 99.  factorize(2*c*s*u^3*v^5-2*c*s*u^3*v +2*c*s*u*v^5-2*c*s*u*v
%               -s^2*u^4*v^4+s^2*u^4+s^2*u^2*v^6-s^2*u^2*v^4-s^2*u^2*v^2
%               +s^2*u^2 +s^2*v^6-s^2*v^2+u^4*v^4-u^4*v^2 -v^4+v^2) gave
%               a catastrophic error.

%  9 Nov 99.  Patched procedures generated a "redefined" message.

% 16 Nov 99.  Some EXCALC calculations could cause a catastrophic error.

% 18 Dec 99.  Integrations could give catastrophic errors because some
%             kernels were not unique.

% 31 Jan 00.  The sequence weight x=1,y=1; wtlevel 10; factor x; led to
%             the error that x was invalid as a kernel.

%  5 Feb 00.  The sequence x := mat((1,2)); sign sqrt 42; led to a
%             spurious error.

%  6 Feb 00.  The sequence on complex; sqrt(i*sqrt(3)-1); gave a wrong
%             result.

% 10 Feb 00.  Some root evaluations could lead to an error like
%             <equation> invalid as scalar.

% 18 Feb 00.  A sequence like m := mat((a,b),(c,d)); det sub(a=1,m);
%             would cause a type mismatch error.

% 18 Apr 00.  Complaints about the pattern matching limit of 5 terms
%             are resolved by the addition of a variable matchlength!*,
%             whose initial value of 5 can be changed as needed.

% 22 Apr 00.  The RULE mechanism left spurious expressions in various
%             non-local variables.

% 28 Jul 00.  A sum index within a derivative was treated as an identifier
%             (e.g., sum(x^n/factorial n*sub(x=0,df(cos x,x,n)),n,0,5);

%  2 Aug 00.  With complex on, some factorizations seemed to run forever
%             (e.g., factorize (400y^12+400y^10*z+40y^9*z^2+100y^8*z^2
%              +20y^7*z^5+120y^7*z^4+20y^7*z^3+41y^6*z^4+60y^5*z^7
%              +60y^5*z^5+20y^4*z^7+6y^4*z^6+20y^4*z^5
%              +2y^3*z^6+9y^2*z^8+6y*z^8+z^8))

% 29 Aug 00.  The sequence load_package gentran,scope; matrix a(10,10);
%             on gentranopt; gentran a(1,1) ::=: a(1,1); caused a
%             segmentation violation or similar error.

% 19 Sep 00.  Clearing some sqrt rules could lead to a spurious
%             "not found" message.

% 20 Sep 00.  The sequence load_package algint;
%             int(1/sqrt((2*e^c-y)/(e^c*y)),y);
%             caused a catastrophic error.

%  8 Nov 00.  Some sequences did not optimize completely when the SCOPE
%             command "optimize" was used.

% 20 Nov 00.  The sum operator did not always preserve a noncom order
%             (e.g., noncom u,v; sum(u(m)*v(1-m),m,0,1);)

% 12 Dec 00.  int with four arguments did not automatically load the
%             defint package.

% 13 Dec 00.  Some gcd calculations could produce an endless loop. E.g.,
%             in on numval,rounded; y:=x^4+x3*x^3+x2*x^2+x1*x+x0;
%             on fullroots; solve(y,x);

%  9 Jan 01.  SOLVE did not return results in same order as the given
%             variables (e.g., solve({y=x+t^2,x=y+u^2},{x,y,u,t});

% 14 Jan 01.  Some resultants (e.g. resultant(p^3-3p^2-a,3p*(p-2),p))
%             caused an error.

% 19 Jan 01.  Some algebraic integrals could produce a catastrophic
%             error when the algint package was loaded.

% 22 Jan 01.  Some algebraic integrals could produce a spurious zero
%             divisor message when the algint package was loaded (e.g.,
%               int((sqrt((-sqrt(a^4*x^2+4)+a^2*x)/(2*x))
%               *(-sqrt(a^4*x^2+4)*a^2*x-a^4*x^2-4))/(2*(a^4*x^2+4)),x))

% 23 Jan 01.  Inverses of matrices containing non-commuting objects
%             could be incorrect (e.g. noncom q; 1/mat((1,0,0),
%                (x/p*q 1,1,0),(x*y/(2p*(p-1))*q 1*q 1,y/(p-2)*q 1,1))).

%  2 Feb 01.  Some calls of SOLVE could produce a "zero divisor" error
%             error (e.g., solve(sqrt x*sqrt((4x^2*x+1)/x)-1=0,x)).

%  9 Feb 01.  The patched version of combine!-logs included an undefined
%             macro.

% 20 Feb 01.  Even with combineexpt on, expressions like a*a^x and
%             e*e^(2/(2-x)) did not simplify adequately.

%  6 Mar 01.  With algint loaded, some integrals would abort before
%             completion (e.g., int((x^(2/3)*sqrt(sqrt(y)*sqrt(pi) + 2pi
%             *y*x)*sqrt(- sqrt(y)*sqrt(pi)+2pi*y*x))/(4pi*y*x^3 - x),x)).

%  7 Apr 01.  Factorizations with rounded and complex rounded were not
%             supported.

% 23 Apr 01.  A term could be dropped from the solution of a set of
%             linear equations involving surds.

%  7 May 01.  Patches of 19 Sep 00 updated to correct bug.

%  1 Jun 01.  With precise on, sqrt(x^2) returned x rather than abs(x).

% 11 Jun 01.  Expressions involving noncommuting arguments of a
%             commuting operator were not handled correctly.
%             E.g., operator p,q; noncom q; p q a*p q b -p q b*p q a;

% 15 Jun 01.  Patch of 9 Jan 01 gave a catastrophic error with depend
%             statements, e.g., depend u,z; solve(u=y/x,z).

%  7 Aug 01.  Resultants could return an error or the wrong sign
%             (replaces patch of 14 Jan 01).

%  9 Aug 01.  Rules for tan, like let tan(~x)=>sin x/cos x, made some
%             integrals not return a closed form (e.g., int(1/sin(y)^2,y)).

% 24 Aug 01.  Some factorizations with complex on could have the wrong
%             sign.

%  7 Sep 01.  Some solve problems could cause a catastrophic error in
%             SQFRF.


% Alg declarations.

fluid '(matchlength!*);

matchlength!* := 5;

flag('(matchlength!*),'share);

fluid '(!*sqrtrulep);

patch alg;

% 20 Oct 99, 20 Feb 01.

symbolic procedure exptunwind(u,v);
   begin scalar x,x1,x2,y,z,z2;
  a:  if null v then return u;
      x := caar v;
      x1 := cadr x;
      x2 := caddr x;
      y := cdar v;
      v := cdr v;
      if !*combineexpt and length u=1 and null cdr(z2 := kernels u)
	then u := {(({'expt,car z2,ldeg u} . 1) . lc u)};
      while (z := assocp1(x1,v)) and
         (z2 := simp {'plus,{'times,x2,y},{'times,caddar z,cdr z}})
         and (!*combineexpt or (fixp numr z2 and fixp denr z2))
	do <<if fixp numr z2 and fixp denr z2
               then <<x2 := divide(numr z2,denr z2);
                      if car x2>0
			then <<if fixp x1 then u := multf(x1**car x2,u)
				else u := multpf(mksp(x1,car x2),u);
                               z2 := cdr x2 ./ denr z2>>;
                      y := numr z2>>
	      else y := 1;
             x2 := prepsq(quotf(numr z2,y) ./ denr z2);
             v := delete(z,v)>>;
      if !*combineexpt and y=1 and fixp x1 then
         <<while (z := assocp2(x2,v)) and cdr z=1 and fixp cadar z do
              <<x1 := cadar z * x1; v := delete(z,v)>>;
           if eqcar(x2,'quotient) and fixp cadr x2 and fixp caddr x2
		and cadr x2<caddr x2
             then <<z := nrootn(x1**cadr x2,caddr x2);
                    if cdr z = 1 then u := multd(car z,u)
                     else if car z = 1
                      then u := multf(formsf(x1,x2,1),u)
		     else <<u := multd(car z,u);
                            v := (list('expt,cdr z,x2) . 1) . v>>>>
            else u := multf(formsf(x1,x2,y),u)>>
       else u := multf(formsf(x1,x2,y),u);
      go to a
   end;

% 31 Jan 00.

symbolic procedure factor1(u,v,w);
   begin scalar x,y,z,r;
        y := lispeval w;
        for each j in u do
          if (x := getrtype j) and (z := get(x,'factor1fn))
              then apply2(z,u,v)
            else <<while eqcar(j:=reval j,'list) and cdr j do 
                     <<r:=append(r,cddr j); j:=cadr j>>;
		   x := !*a2kwoweight j;
                   if v then y := aconc!*(delete(x,y),x)
	            else if not(x member y)
                     then msgpri(nil,j,"not found",nil,nil)
                    else y := delete(x,y)>>;
        set(w,y);
        if r then return factor1(r,v,w)
   end;

% 5 Feb 00.

algebraic (let sign(sqrt ~a)  => 1 when sign a=1);

% 18 Feb 00.

symbolic procedure getrtype u;
   begin scalar x,y;
    return
    if null u then nil
     else if atom u
      then if not idp u then not numberp u and getrtype1 u
	    else if flagp(u,'share)
	     then if (x := eval u) eq u then nil else getrtype x
	    else if (x := get(u,'avalue)) and
		       not(car x memq '(scalar generic))
		    or (x := get(u,'rtype)) and (x := list x)
                    then if y := get(car x,'rtypefn) then apply1(y,nil)
                          else car x
                  else nil
     else if not idp car u then nil
     else if (x := get(car u,'avalue)) and (x := get(car x,'rtypefn))
      then apply1(x,cdr u)
     else if car u eq 'sub then 'yetunknowntype
     else getrtype2 u
   end;

symbolic procedure let3(u,v,w,b,flgg);
   begin scalar x,y1,y2,z;
        x := u;
        if null x then <<u := 0; return errpri1 u>>
         else if numberp x then return errpri1 u;
       y2 := getrtype v;
       if b and idp x then <<remprop(x,'rtype); remprop(x,'avalue)>>;
	if (y1 := getrtype x)
	  then return if z := get(y1,'typeletfn)
			then lispapply(z,list(x,v,y1,b,getrtype v))
		       else typelet(x,v,y1,b,getrtype v)
	 else if y2 and not(y2 eq 'yetunknowntype)
	  then return if z := get(y2,'typeletfn)
			then lispapply(z,list(x,v,nil,b,y2))
		       else typelet(x,v,nil,b,y2)
         else letscalar(u,v,w,x,b,flgg)
   end;

% 18 Apr 00.

symbolic procedure mcharg1(u,v,w);
   if null u and null v then list nil
    else begin integer m,n;
        m := length u;
        n := length v;
        if flagp(w,'nary) and m>2
	  then if m<=matchlength!* and flagp(w,'symmetric)
                             then return mchcomb(u,v,w)
                else if n=2 then <<u := cdr mkbin(w,u); m := 2>>
		else return nil;
        return if m neq n then nil
                else if flagp(w,'symmetric) then mchsarg(u,v,w)
                else if mtp v then list pair(v,u)
                else mcharg2(u,v,list nil,w)
   end;

% 19 Sep 00, 7 May 01, 15 Jun 01.

symbolic procedure letscalar(u,v,w,x,b,flgg);
   begin
      if not atom x
               then if not idp car x then return errpri2(u,'hold)
                     else if car x eq 'df
                      then if null letdf(u,v,w,x,b) then nil
                            else return nil
                     else if getrtype car x
                      then return let2(reval x,v,w,b)
                     else if not get(car x,'simpfn)
                      then <<redmsg(car x,"operator");
                             mkop car x;
                             return let3(u,v,w,b,flgg)>>
                     else nil
         else if null b and null w
          then <<remprop(x,'avalue);
		 remprop(x,'rtype);
                 remflag(list x,'antisymmetric);
                 remprop(x,'infix);
		 remprop(x,'kvalue);
		 remflag(list x,'linear);
		 remflag(list x,'noncom);
                 remprop(x,'op);
                 remprop(x,'opmtch);
                 remprop(x,'simpfn);
                 remflag(list x,'symmetric);
                 wtl!* := delasc(x,wtl!*);
                 if flagp(x,'opfn)
                   then <<remflag(list x,'opfn); remd x>>;
		 rmsubs();
                 return nil>>;
        if eqcar(x,'expt) and caddr x memq frlis!*
          then letexprn(u,v,w,!*k2q x,b,flgg)
         else if eqcar(x,'sqrt)
	  then <<!*sqrtrulep := t;
		 let2({'expt,cadr x,'(quotient 1 2)},v,w,b)>>;
	x := simp0 x where !*precise = t;
        return if not domainp numr x then letexprn(u,v,w,x,b,flgg)
                else errpri1 u
   end;

symbolic procedure setk1(u,v,b);
   begin scalar x,y,z,!*uncached;
      !*uncached := t;
      if atom u
        then <<if null b
                 then <<if not get(u,'avalue)
                          then msgpri(nil,u,"not found",nil,nil)
                         else remprop(u,'avalue);
                        return nil>>
		else if (x:= get(u,'avalue)) then put!-avalue(u,car x,v)
		else put!-avalue(u,'scalar,v);
               return v>>
       else if not atom car u
	then rerror(alg,25,"Invalid syntax: improper assignment");
      u := car u . revlis cdr u;
      if null b
        then <<z:=assoc(u,wtl!*);
               if not(y := get(car u,'kvalue))
                  or not (x := assoc(u,y))
		 then <<if null z and null !*sqrtrulep then
                            msgpri(nil,u,"not found",nil,nil)>>
                else put(car u,'kvalue,delete(x,y));
		if z then wtl!*:=delasc(u,wtl!*);
               return nil>>
       else if not (y := get(car u,'kvalue))
	then put!-kvalue(car u,nil,u,v)
       else <<if x := assoc(u,y)
		then <<updoldrules(u,v); y := delasc(car x,y)>>;
	      put!-kvalue(car u,y,u,v)>>;
      return v
     end;

% 7 May 01.

symbolic procedure clearrules u;
   begin scalar !*sqrtrulep;
      return rule!-list(u,nil)
   end;

% 2 Feb 01.

symbolic procedure simprad(u,n);
   if !*reduced then multsq(radfa(numr u,n),invsq radfa(denr u,n))
     else begin scalar iflag,x,y,z;
       if !*rationalize then <<
	  y:=list(denr u,1);
          u:=multf(numr u, exptf(denr u,n-1)) ./ 1 >>
         else y := radf(denr u,n);
       if n=2 and minusf numr u
	 then <<iflag := t; x := radf(negf numr u,n)>>
	else x := radf(numr u,n);
       z := simp list('quotient,retimes cdr x, retimes cdr y);
       if domainp numr z and domainp denr z
	 then z := multsq(mkrootsq(prepf numr z,n),
			  invsq mkrootsq(prepf denr z,n))
	else <<if iflag
		 then <<iflag := nil;
			z := negsq z>>;
	       z := mkrootsq(prepsq z,n)>>;
       z := multsq(multsq(if !*precise and evenp n 
			    then car x ./ 1
                           else car x ./ 1, 1 ./ car y), z);
       if iflag then z := multsq(z,mkrootsq(-1,2));
       return z
   end;

symbolic procedure radfa(u,n);
   begin scalar x,y;
      x := fctrf u;
      if numberp car x then x := append(zfactor car x,cdr x)
       else x := (car x ./ 1) . cdr x;
      y := 1 ./ 1;
      for each j in x do y := multsq(y,radfb(car j,cdr j,n));
      return y
   end;

symbolic procedure radfb(u,m,n);
   begin scalar x,y;
      x := radf(u,n);
      y := exptf(car x,m) ./ 1;
      return multsq(exptsq(mkrootlsq(cdr x,n),m),y)
   end;

% 20 Feb 01.

symbolic procedure reval2(u,v);
   if v or null !*combineexpt or dmode!* then !*q2a1(simp!* u,v)
    else !*q2a1((simp!* u where !*mcd = nil),v);

% 1 Jun 01.

symbolic procedure simpexpt2(u,n,flg);
   begin scalar m,n,x,y;
    if u=1 then return 1 ./ 1;
    m:=numr n;
    if pairp u then <<
     if car u eq 'expt
      then <<n:=multsq(m:=simp caddr u,n);
	     if !*precise
	       then u := list('abs,cadr u)
	      else u := cadr u;
	     return simpexpt1(u,n,flg)>>
     else if car u eq 'sqrt and not !*keepsqrts
      then return simpexpt2(cadr u, multsq(1 ./ 2,n),flg)
     else if car u eq 'times and not !*precise
      then <<x := 1 ./ 1;
	     for each z in cdr u do x := multsq(simpexpt1(z,n,flg),x);
	     return x>>
     else if car u eq 'times and (y:=split!-sign cdr u) and car y
      then <<x := simpexpt1(retimes append(cadr y,cddr y),n,flg);
             for each z in car y do x := multsq(simpexpt1(z,n,flg),x);
	     return x>>
     else if car u eq 'quotient
	and (not !*precise
		or posnump caddr u and posnump prepsq n
	    )
      then <<if not flg and !*mcd then
		return simpexpt1(prepsq simp!* u,n,t);
	     n := prepsq n;
	     return quotsq(simpexpt{cadr u,n},simpexpt{caddr u,n})>>
     else if car u eq 'minus and not !*precise and not(cadr u = 1)
      then return (multsq(simpexpt list(-1,expon),
		 simpexpt list(cadr u,expon))) where expon=prepsq n>>;
    if null flg
      then <<if null(dmode!* and idp u and get(u,dmode!*))
	       then u := prepsq simp!* u;
	     return simpexpt1(u,n,t)>>
     else if numberp u and zerop u then return nil ./ 1
     else if not numberp m then m := prepf m;
    n := prepf denr n;
    if m memq frlis!* and n=1 then return list ((u . m) . 1) . 1;
    if !*mcd or not numberp m or n neq 1
      or atom u or denr simp!* u neq 1 then return simpx1(u,m,n)
      else return mksq(u,m)
   end;

endpatch;

% Algint declarations.

fluid '(!*noacn !*structure !*tra !*trmin gaussiani intvar sqrtflag);

fluid '(!*pvar listofallsqrts listofnewsqrts);

global '(modevalcount);

patch algint;

% 20 Sep 00.

symbolic procedure algebraiccase(expression,zlist,varlist);
begin
  scalar rischpart,deriv,w,firstterm;
  scalar sqrtflag,!*structure;
  sqrtflag:=t;
  sqrtsave(listofallsqrts,listofnewsqrts,list(intvar . intvar));
  rischpart:= errorset!*(list('doalggeom,mkquote expression),
			 !*backtrace);
  newplace list (intvar.intvar);
  if atom rischpart
    then <<
      if !*tra then prin2t "Inner integration failed";
      deriv:=nil ./ 1;
      rischpart:=deriv >>
    else
      if atom car rischpart
        then <<
      if !*tra or !*trmin then
	prin2t "The 'logarithmic part' is not elementary";
          return (nil ./ 1) . expression >>
      else <<
        rischpart:=car rischpart;
    deriv:=!*diffsq(rischpart,intvar) where sqrtflag=nil;
    if !*tra or !*trmin then <<
      prin2t "Inner working yields";
          printsq rischpart;
      prin2t "with derivative";
          printsq deriv >> >>;
  deriv:=!*addsq(expression,negsq deriv);
  if null numr deriv
    then return rischpart . (nil ./ 1);
  if null involvesq(deriv,intvar)
    then return !*addsq(rischpart,
                !*multsq(deriv,((mksp(intvar,1) .* 1) .+ nil) ./ 1))
          . (nil ./ 1);
  varlist:=getvariables deriv;
  zlist:=findzvars(varlist,list intvar,intvar,nil);
  varlist:=setdiff(varlist,zlist);
  firstterm:=simp!* car zlist;
  w:=sqrt2top !*multsq(deriv,invsq !*diffsq(firstterm,intvar));
  if null involvesq(w,intvar)
    then return !*addsq(rischpart,!*multsq(w,firstterm)) . (nil ./ 1);
  if !*noacn then interr "Testing only logarithmic code";
  deriv:=transcendentalcase(deriv,intvar,nil,zlist,varlist);
  return !*addsq(car deriv, rischpart) . cdr deriv
  end;

% 22 Jan 01, 9 Feb 01.

symbolic procedure combine!-logs(coef,logarg);
begin
  scalar ans,dencoef,parts,logs,lparts,!*rationalize,trueimag;
  !*rationalize:=t;
  coef:=simp!* coef;
  if null numr logarg then return coef;
  parts:=split!-real!-imag numr coef;
  if null numr cdr parts then return multsq(coef,logarg);
  dencoef:=multf(denr coef,denr logarg);
  if !*tra then <<
     prin2t "attempting to find 'real' form for";
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
		       !*exptsq(simp!* cadr mvar logarg,lc logarg));
	logarg:=red logarg >>;
  logs:=rationalizesq logs;
  ans:=multsq(!*multsq(car parts,logs),1 ./ dencoef);
  lparts:=split!-real!-imag numr logs;
  if numr difff(denr cdr lparts,intvar)
    then interr "unexpected denominator";
  lparts:=!*multsq(denr cdr lparts ./ 1,car lparts) . cdr lparts;
  if not onep denr car lparts then interr "unexpected denominator";
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

%  6 Mar 01.

symbolic procedure modevalvar v;
   begin scalar w;
      if atom v
	then <<if (w := get(v,'modvalue)) then return w;
	       put(v,'modvalue,modevalcount);
	       modevalcount := modevalcount+1;
	       return modevalcount-1>>
       else if car v neq 'sqrt
	then <<if !*tra then <<princ "Unexpected algebraic:"; print v>>;
	       error1()>>
       else if numberp cadr v then return (mksp(v,1) .* 1) .+ nil;
      w := modeval(!*q2f simp cadr v,!*pvar);
      w := assoc(w,listofallsqrts);
      if w then return cdr w else return 'failed
   end;

endpatch;

% Excalc declarations.

global '(basisforml!* detm!* indxl!* metricd!* metricu!*);

smacro procedure ldpf u;
   caar u;

smacro procedure lowerind u;
   list('minus,u);

patch excalc;

% 16 Nov 99.

symbolic procedure mkmetric u;
   begin scalar x,y,z,okord;
     putform(list(cadr u,nil,nil),0);
     put(cadr u,'indxsymmetries,
         '((lambda (indl) (tot!-sym!-indp 
                             (evlis '((nth indl 1) 
                                      (nth indl 2)))))));
     put(cadr u,'indxsymmetrize,
         '((lambda (indl) (symmetrize!-inds '(1 2) indl))));
     flag(list cadr u,'covariant);
     okord := kord!*;
     kord!* := basisforml!*;
     x := simp!* caddr u;
     y := indxl!*;
     metricu!* := t;
     for each j in indxl!* do
       <<for each k in y do
           setk(list(cadr u,lowerind j,lowerind k),0);
         y := cdr y>>;
     for each j on partitsq(x,'basep) do
       if ldeg ldpf j = 2 then
           setk(list(cadr u,lowerind cadr mvar ldpf j,
                            lowerind cadr mvar ldpf j),
                mk!*sq lc j)
        else
           setk(list(cadr u,lowerind cadr mvar ldpf j,
                            lowerind cadr mvar lc ldpf j),
                mk!*sq multsq(lc j,1 ./ 2));
     kord!* := okord;
     x := for each j in indxl!* collect
            for each k in indxl!* collect
               simpindexvar list(cadr u,lowerind j,lowerind k);
	 z := subfg!*;
     subfg!* := nil;
     y := lnrsolve(x,generateident length indxl!*);
	 subfg!* := z;
     metricd!* := mkasmetric x;
     metricu!* := mkasmetric y;
     detm!* := mk!*sq detq x
   end;

endpatch;


% Ezgcd declarations.

fluid '(image!-set reduced!-degree!-lclst unlucky!-case);

symbolic smacro procedure polyzerop u; null u;

patch ezgcd;

% 8 Nov 99.

symbolic procedure ezgcdf(u,v);
   begin scalar kordx,x;
      kordx := kord!*;
      x := errorset2{'ezgcdf1,mkquote u,mkquote v};
      if null errorp x then return first x;
      setkorder kordx;
      return gcdf1(u,v)
   end;
 
symbolic procedure poly!-gcd(u,v);
   begin scalar !*exp,z;
        if polyzerop u then return poly!-abs v
         else if polyzerop v then return poly!-abs u
         else if u=1 or v=1 then return 1;
        !*exp := t;
        if quotf1(u,v) then z := v
	 else if quotf1(v,u) then z := u
	 else if !*gcd then z := gcdlist list(u,v)
	 else z := 1;
        return poly!-abs z
   end;
 
symbolic procedure gcdlist3(l,onestep,vlist);
  begin
    scalar unlucky!-case,image!-set,gg,gcont,l1,w,w1,w2,
           reduced!-degree!-lclst,p1,p2;
    l1:=for each p in l collect p . ezgcd!-comfac p;
    l:=for each c in l1 collect
        quotfail1(car c,comfac!-to!-poly cdr c,
                  "Content divison in GCDLIST3 failed");
    gcont:=gcdlist for each c in l1 collect cddr c;
    if domainp gcont then if not(gcont=1)
      then errorf "GCONT has numeric part";
    l := sort(for each p in l collect poly!-abs p,function ordp);
    w := nil;
    while l do <<
       w := car l . w;
       repeat l := cdr l until null l or not(car w = car l)>>;
    l := reversip w;
    w := nil;
    if null cdr l then return multf(gcont,car l);
    if domainp (gg:=car (l:=sort(l,function degree!-order))) then
      return gcont;
    if ldeg gg=1 then <<
       if division!-test(gg,l) then return multf(poly!-abs gg,gcont)
       else return gcont >>;
    if onestep then <<
       p1 := poly!-abs car l; p2 := poly!-abs cadr l;
       if p1=p2 then <<
             if division!-test(p1,cddr l) then return multf(p1,gcont) >>
       else <<
       gg := poly!-gcd(lc p1,lc p2);
       w1 := multf(red p1, quotfail1(lc p2, gg,
        "Division failure when just one pseudoremainder step needed"));
       w2 := multf(red p2,negf quotfail1(lc p1, gg,
        "Division failure when just one pseudoremainder step needed"));
       w := ldeg p1 - ldeg p2;
       if w > 0 then w2 := multf(w2, (mksp(mvar p2, w) .* 1) .+ nil)
	else if w < 0
	 then w1 := multf(w1, (mksp(mvar p1, -w) .* 1) .+ nil);
       gg := ezgcd!-pp addf(w1, w2);
       if division!-test(gg,l) then return multf(gg,gcont) >>>>;
      return gcdlist31(l,vlist,gcont,gg,l1)
   end;

endpatch;

% Int declarations.

fluid '(!*failhard !*purerisch !*reverse !*trdint sqrt!-places!-alist
        badpart ccount cmap cmatrix content cval denbad denominator!*
        lhs!* loglist orderofelim rhs!* tanlist !*intflag!* indexlist
        intvar listofnewsqrts listofallsqrts lorder power!-list!*
        sqrtflag sqrtlist sqrt!-intvar basic!-listofnewsqrts
        basic!-listofallsqrts sqfr sillieslist varlist);

global '(!*number!* !*seplogs !*spsize!* !*statistics gensymcount);

patch int;

% 18 Dec 99.

symbolic procedure findtrialdivs zl;
   begin scalar dlists1,args1;
      for each z in zl do
	 if exportan z
	   then <<if car z eq 'tan
		    then <<args1 := (mksp(z,2) .* 1) .+ 1;
			   tanlist := (args1 ./ 1) . tanlist>>
		   else args1 := !*kk2f z;
		  dlists1 := (z . args1) . dlists1>>;
      return dlists1
   end;

% 12 Dec 00.

symbolic procedure simpdint u;
   begin scalar low,upp,fn,var,x,y;
      if length u neq 4
	then rerror(int,2,"Improper number of arguments to INT");
      load!-package 'defint;
      fn := car u;
      var := cadr u;
      low := caddr u;
      upp := cadddr u;
      low := reval low;
      upp := reval upp;
      if low = upp then return nil ./ 1
       else if null getd 'new_defint then nil
       else if upp = 'infinity
	then if low = 0
	       then if not smemql('(infinity unknown),
				  x := defint!* {fn,var})
		      then return simp!* x else nil
	      else if low = '(minus infinity)
	       then return mkinfint(fn,var)
	      else if freeof(var,low)
	       then if not smemql('(infinity unknown),
				  x := defint!* {fn,var})
		     and not smemql('(infinity unknown),
				  y := indefint!* {fn,var,low})
		      then return simp!* {'difference,x,y} else nil
	      else nil
       else if upp = '(minus infinity) or low = 'infinity
	then return negsq simpdint {fn,var,upp,low}
       else if low = '(minus infinity)
	then return
	   simpdint{prepsq simp{'sub,{'equal,var,{'minus,var}},fn},
		     var,{'minus,upp},'infinity}
       else if low = 0
	then if freeof(var,upp)
		and not smemql('(infinity unknown),
			       x := indefint!* {fn,var,upp})
	       then return simp!* x else nil
       else if freeof(var,upp) and freeof(var,low)
		 and not smemq('(infinity unknown),
			       x := indefint!* {fn,var,upp})
		 and not smemql('(infinity unknown),
			       y := indefint!* {fn,var,low})
	then return simp!* {'difference,x,y};
      return mkdint(fn,var,low,upp)
   end;

% 1 Jun 01.

symbolic procedure simpint u;
   if atom u or null cdr u or cddr u and (null cdddr u or cddddr u)
     then rerror(int,1,"Improper number of arguments to INT")
    else if cddr u then simpdint u
    else begin scalar ans,dmod,expression,variable,loglist,oldvarstack,
		 !*intflag!*,!*purerisch,cflag,intvar,listofnewsqrts,
		 listofallsqrts,sqrtfn,sqrt!-intvar,sqrt!-places!-alist,
		 basic!-listofallsqrts,basic!-listofnewsqrts,coefft,
		 varchange,w,!*precise;
    !*intflag!* := t;
    variable := !*a2k cadr u;
    if not(idp variable or pairp variable and numlistp cdr variable)
      then <<varchange := variable . intern gensym();
	     if !*trint
	       then prin2t {"Integration kernel", variable,
			  "replaced by simple variable", cdr varchange};
	     variable := cdr varchange>>;
    intvar := variable;
    w := cddr u;
    if w then rerror(int,3,"Too many arguments to INT");
    listofnewsqrts:= list mvar gaussiani;
    listofallsqrts:= list (cadr mvar gaussiani . gaussiani);
    sqrtfn := get('sqrt,'simpfn);
    put('sqrt,'simpfn,'proper!-simpsqrt);
    if dmode!* then
       << if (cflag:=get(dmode!*, 'cmpxfn)) then onoff('complex, nil);
	  if (dmod := get(dmode!*,'dname)) then
	     onoff(dmod,nil)>> where !*msg := nil;
    begin scalar dmode!*,!*exp,!*gcd,!*keepsqrts,!*limitedfactors,!*mcd,
		 !*rationalize,!*structure,!*uncached,kord!*,
		 ans1,denexp,badbit,nexp,oneterm;
       !*keepsqrts := !*limitedfactors := t;
       !*exp := !*gcd := !*mcd := !*structure := !*uncached := t;
       dmode!* := nil;
       if !*algint
	 then <<
	    sqrt!-intvar:=!*q2f simpsqrti variable;
	    if (red sqrt!-intvar) or (lc sqrt!-intvar neq 1)
		or (ldeg sqrt!-intvar neq 1)
	      then interr "Sqrt(x) not properly formed"
	      else sqrt!-intvar:=mvar sqrt!-intvar;
	    basic!-listofallsqrts:=listofallsqrts;
	    basic!-listofnewsqrts:=listofnewsqrts;
	    sqrtsave(basic!-listofallsqrts,basic!-listofnewsqrts,
			 list(variable . variable))>>;
       coefft := (1 ./ 1);
       expression := int!-simp car u;
       if varchange
	 then <<depend1(car varchange,cdr varchange,t);
		expression := int!-subsq(expression,{varchange})>>;
       denexp := 1 ./ denr expression;
       nexp := numr expression;
       while not atom nexp and null cdr nexp and
	  not depends(mvar nexp,variable) do
	      <<coefft := multsq(coefft,(((caar nexp) . 1) . nil) ./ 1);
		nexp := lc nexp>>;
       ans1 := nil;
       while nexp do begin
	   scalar x,zv,tmp;
	   if atom nexp then <<x := !*f2q nexp; nexp := nil>>
	    else <<x := !*t2q car nexp; nexp := cdr nexp>>;
	   x := multsq(x,denexp);
	   zv := findzvars(getvariables x,list variable,variable,nil);
	   begin scalar oldzlist;
	       while oldzlist neq zv do <<
		    oldzlist := zv;
		    foreach zz in oldzlist do
		    zv:=findzvars(distexp(pseudodiff(zz,variable)),
				  zv,variable,t)>>;
	       % The following line was added to make, for example,
	       % int(df(sin(x)/x),x) return the expected result.
	       zv := sort(zv, function ordp)
	   end;
	   tmp := ans1;
	   while tmp do
	      <<if zv=caar tmp
		  then <<rplacd(car tmp,addsq(cdar tmp,x));
			 tmp := nil; zv := nil>>
		 else tmp := cdr tmp>>;
	   if zv then ans1 := (zv . x) . ans1
       end;
       if length ans1 = 1 then oneterm := t;
       nexp := ans1;
       ans := nil ./ 1;
       badbit:=nil ./ 1;
       while nexp do
	<<u := cdar nexp;
	  if !*trdint
	    then <<princ "Integrate"; printsq u;
		   princ "with Zvars "; print caar nexp>>;
	  ans1 := errorset!*(list('integratesq,mkquote u,
			     mkquote variable,mkquote loglist,
			     mkquote caar nexp),
			     !*backtrace);
	  nexp := cdr nexp;
	  if errorp ans1 then badbit := addsq(badbit,u)
	   else <<ans := addsq(caar ans1, ans);
		  badbit:=addsq(cdar ans1,badbit)>>>>;
       if !*trdint
	 then <<prin2 "Partial answer="; printsq ans;
		prin2 "To do="; printsq badbit>>;
       if badbit neq '(nil . 1)
	 then <<setkorder nil;
		badbit := reordsq badbit;
		ans := reordsq ans;
		coefft := reordsq coefft;
	  if !*trdint then <<princ "Retrying..."; printsq badbit>>;
	  if oneterm and ans = '(nil . 1) then ans1 := nil
	    else ans1 := errorset!*(list('integratesq,mkquote badbit,
				  mkquote variable,mkquote loglist,nil),
				  !*backtrace);
	  if null ans1 or errorp ans1
	    then ans := addsq(ans,simpint1(badbit . variable . w))
	   else <<ans := addsq(ans,caar ans1);
	      if not smemq(variable, ans) then ans := nil ./ 1;
		  if cdar ans1 neq '(nil . 1)
		    then ans := addsq(ans,
				    simpint1(cdar ans1 . variable . w))
		>>>>;
    end;
    ans := multsq(coefft,ans);
    if !*trdint then << prin2t "Resimp and all that"; printsq ans >>;
    put('int,'simpfn,'simpiden);
    put('sqrt,'simpfn,sqrtfn);
    << if dmod then onoff(dmod,t);
       if cflag then onoff('complex,t)>> where !*msg := nil;
    oldvarstack := varstack!*;
    varstack!* := nil;
    ans := errorset!*(list('int!-resub,mkquote ans,mkquote
			   varchange),t);
    put('int,'simpfn,'simpint);
    varstack!* := oldvarstack;
    return if errorp ans then error1() else car ans
   end;

symbolic procedure mkdint(fn,var,low,upp);
   begin scalar x,!*precise;
      if getd 'defint0
	 and not((x := defint0 {fn,var,low,upp}) eq 'failed)
	then return simp x
       else if not smemq('infinity,low) and not smemq('infinity,upp)
	then <<x := prepsq!* simpint {fn,var};
	       if not eqcar(x,'int)
		 then return simp!* {'difference,
				     subeval {{'equal,var,upp},x},
				     subeval {{'equal,var,low},x}}>>;
      return mksq({'int,fn,var,low,upp},1)
   end;

%  9 Aug 01.

symbolic 
   procedure transcendentalcase(integrand,svar,xlogs,zlist,varlist);
   begin scalar divlist,jhd!-content,content,prim,sqfr,dfu,indexlist,
      sillieslist,originalorder,wrongway,power!-list!*,
      sqrtlist,tanlist,loglist,dflogs,eprim,dfun,unintegrand,
      sqrtflag,badpart,rhs!*,lhs!*,gcdq,cmap,cval,orderofelim,cmatrix;
      scalar ccount,denominator!*,result,denbad,temp;
        gensymcount:=0;
      integrand:=sqrt2top integrand;
      if !*trint then << printc "Extension variables z<i> are";
          print zlist>>;
     begin scalar w,gg;
        gg:=1; 
        foreach z in zlist do
	   <<w := subs2 diffsq(simp z,svar);
             gg := !*multf(gg,quotf(denr w,gcdf(denr w,gg)))>>;
        gg := quotf(gg,gcdf(gg,denr integrand));
        unintegrand := (!*multf(gg,numr integrand)
			./ !*multf(gg,denr integrand));
        if !*trint then <<
                printc "After unnormalization the integrand is ";
                printsq unintegrand >>
      end;
      divlist := findtrialdivs zlist;
      sqrtlist := findsqrts zlist;
      divlist := trialdiv(denr unintegrand,divlist);
      prim := sqfree(cdr divlist,zlist);
      jhd!-content := content;
      printfactors(prim,nil);
      eprim := sqmerge(countz car divlist,prim,nil);
      printfactors(eprim,t);
      sqfr := for each u in eprim collect multup u;
      if !*reverse then zlist := reverse zlist;
      indexlist := createindices zlist;
      dfu:=dfnumr(svar,car divlist);
      loglist := append(loglist,factorlistlist prim);
      loglist := mergein(xlogs,loglist);
      loglist := mergein(tanlist,loglist);
      cmap := createcmap();
      ccount := length cmap;
      if !*trint then <<printc "Loglist "; print loglist>>;
      dflogs := difflogs(loglist,denr unintegrand,svar);
      if !*trint
        then <<printc "************ 'Derivative' of logs is:";
               printsq dflogs>>;
      dflogs := addsq((numr unintegrand) ./ 1,negsq dflogs);
      gcdq := gcdf(denr dflogs,denr dfu);
      dfun := !*multf(numr dfu,denbad:=quotf(denr dflogs,gcdq));
      denbad := !*multf(denr dfu,denbad);
      denbad := !*multf(denr unintegrand,denbad);
      dflogs := !*multf(numr dflogs,quotf(denr dfu,gcdq));
      dfu := dfun;
      rhs!* := multbyarbpowers f2df dfu;
      if checkdffail(rhs!*,svar)
        then <<if !*trint then printsq checkdffail(rhs!*,svar);
      interr "Simplification fails on above expression">>;
      if !*trint then << 
          printc "Distributed Form of Numerator is:";
          printdf rhs!*>>;
      lhs!* := f2df dflogs;
      if !*trint then << printc "Distributed Form of integrand is:";
          printdf lhs!*;
          terpri()>>;
      cval := mkvect(ccount);
      for i := 0:ccount do putv(cval,i,nil ./ 1);
      power!-list!* := tansfrom(rhs!*,zlist,indexlist,0);
      lorder:=maxorder(power!-list!*,zlist,0);
      originalorder := for each x in lorder collect x;
        if !*trint then << 
                printc "Maximum order for variables determined as ";
                print lorder >>;
        if !*statistics then << !*number!*:=0;
                !*spsize!*:=1;
                foreach xx in lorder do
                   !*spsize!*:=!*spsize!* * (xx+1) >>;
      dfun:=solve!-for!-u(rhs!*,lhs!*,nil);
      backsubst4cs(nil,orderofelim,cmatrix);
        if !*statistics then << prin2 !*number!*; prin2 " used out of ";
                printc !*spsize!* >>;
      badpart:=substinulist badpart;
      dfun:=df2q substinulist dfun;
      result:= !*multsq(dfun,!*invsq(denominator!* ./ 1));
      result:= !*multsq(result,!*invsq(jhd!-content ./ 1));
      dflogs:=logstosq();
      if not null numr dflogs then <<
          if !*seplogs and (not domainp numr result) then <<
              result:=mk!*sq result;
              result:=(mksp(result,1) .* 1) .+ nil;
              result:=result ./ 1 >>;
          result:=addsq(result,dflogs)>>;
      if !*trint
	then  <<
          terpri();
          printc
          "*****************************************************";
          printc
           "************ THE INTEGRAL IS : **********************";
          printc
           "*****************************************************";
          terpri();
          printsq result;
          terpri()>>;
      if badpart then begin scalar n,oorder;
          if !*trint
            then printc "plus a part which has not been integrated";
          lhs!*:=badpart;
          lorder:=maxorder(power!-list!*,zlist,0);
          oorder:=originalorder;
          n:=length lorder;
          while lorder do <<
                if car lorder > car originalorder then
                        wrongway:=t;
                if car lorder=car originalorder then n:= n-1;
                lorder:=cdr lorder;
                originalorder:=cdr originalorder >>;
          if !*trint and wrongway then printc "Went wrong way";
          dfun:=df2q badpart;
          dfun:= !*multsq(dfun,invsq(denbad ./ 1));
	  badpart := dfun;
          if wrongway then <<
                if !*trint then printc "Resetting....";
                result:=nil ./ 1;
                dfun := integrand; badpart:=dfun >>;
          if rootcheckp(unintegrand,svar) then
                return simpint1(integrand . svar.nil) . (nil ./ 1)
          else if !*purerisch or allowedfns zlist then 
              << badpart := dfun;
		 dfun := nil ./ 1 >>
           else << !*purerisch:=t;
                if !*trint
                  then <<printc "   Applying transformations ..."; 
                         printsq dfun>>;
	      temp := get('tan,'opmtch);
	      remprop('tan,'opmtch);
              denbad:=transform(dfun,svar);
              if denbad=dfun
		then <<dfun:=nil ./ 1;
		       badpart:=denbad;
		       put('tan,'opmtch,temp)>>
             else <<denbad:=errorset!*(list('integratesq,mkquote denbad,
                                      mkquote svar,mkquote xlogs, nil),
                                      !*backtrace);
		    put('tan,'opmtch,temp);
                     if not atom denbad then <<
			denbad:=car denbad;
                        dfun:=untan car denbad;

                        if (dfun neq '(nil . 1)) then
                            badpart:=untan cdr denbad;
                        if car badpart and not(badpart=denbad) then <<
                          wrongway:=nil;
                          lhs!*:=f2df car badpart;
                          lorder:=maxorder(power!-list!*,zlist,0);
                          n:=length lorder;
                          while lorder do <<
                                if car lorder > car oorder then
                                        wrongway:=t;
                                if car lorder=car oorder then n:= n-1;
                                lorder:=cdr lorder;
                                oorder:=cdr oorder >>;
                          if wrongway or (n=0) then <<
                               if !*trint then printc "Still backwards";
                               dfun := nil ./ 1;
                               badpart := integrand>>>>>>
                     else <<badpart := dfun; dfun := nil ./ 1 >>>>>>;
          if !*failhard then rerror(int,9,"FAILHARD switch set");
          if !*seplogs and not domainp result then <<
                result:=mk!*sq result;
                if not numberp result
                  then result:=(mksp(result,1) .* 1) .+ nil;
                result:=result ./ 1>>;
          result:=addsq(result,dfun) end
         else badpart:=nil ./ 1;
      return (sqrt2top result . badpart)
   end;

endpatch;

unfluid '(indexlist);

patch limits;

% 1 Jun 01.

symbolic procedure simplimit u;
   begin scalar fn,exprn,var,val,old,v,!*precise,!*protfg;
     if length u neq 4
       then rerror(limit,1,
		   "Improper number of arguments to limit operator");
     fn:= car u; exprn := cadr u; var := !*a2k caddr u; val := cadddr u;
     !*protfg := t;
     old := get('cot,'opmtch);
     put('cot,'opmtch,
	 '(((!~x) (nil . t) (quotient (cos !~x) (sin !~x)) nil)));
     v := errorset!*({'apply,mkquote fn,mkquote {exprn,var,val}},nil);
     put('cot,'opmtch,old);
     !*protfg := nil;
     return if errorp v or (v := car v) = aeval 'failed then mksq(u,1)
	     else simp!* v
   end;

endpatch;

% Matrix declarations.

fluid '(!*bezout);

patch matrix;

% 7 Aug 99, 23 Apr 01.

symbolic procedure quotfexf!*1(u,v);
   if null u then nil
    else (if x then x
	   else (if denr y = 1 then numr y
		  else if denr (y := (rationalizesq y
				     where !*rationalize = t))=1
		   then numr y
		  else rerror(matrix,11,
			      "Catastrophic division failure"))
		 where y=rationalizesq(u ./ v))
	  where x=quotf(u,v);

% 23 Jan 01.

symbolic procedure lnrsolve(u,v);
   begin scalar temp,vlhs,vrhs,ok,
                !*exp,!*solvesingular;
   if !*ncmp then return clnrsolve(u,v);
   !*exp := t;
   if asymplis!* or wtl!* then
    <<temp := asymplis!* . wtl!*;
      asymplis!* := wtl!* := nil>>;
   vlhs := for i:=1:length car u collect intern gensym();
   vrhs := for i:=1:length car v collect intern gensym();
   u := car normmat augment(u,v);
   v := append(vlhs,vrhs);
   ok := setkorder v;
   u := foreach r in u collect prsum(v,r);
   v := errorset!*({function solvebareiss, mkquote u,mkquote vlhs},t);
   if caar v memq {'singular,'inconsistent} then 
      <<setkorder ok; rerror(matrix,13,"Singular matrix")>>;
   v := pair(cadr s,car s) where s = cadar v;
   u := foreach j in vlhs collect
	   coeffrow(negf numr q,vrhs,denr q) where q = cdr atsoc(j,v);
   setkorder ok;
   if temp then <<asymplis!* := car temp; wtl!* := cdr temp>>;
   return for each j in u collect
             for each k in j collect
                if temp then resimp k else cancel k;
   end;

% 23 Apr 01.

symbolic procedure extmult(u,v);
   if null u or null v then nil
    else (if x then cdr x .* (if car x then negf c!:subs2multf(lc u,lc v)
			       else c!:subs2multf(lc u,lc v))
			  .+ extadd(extmult(!*t2f lt u,red v),
				    extmult(red u,v))
	   else extadd(extmult(red u,v),extmult(!*t2f lt u,red v)))
	  where x = ordexn(car lpow u,lpow v);

% 14 Jan 01, 7 Aug 01.

symbolic procedure resultant(u,v,var);
   if domainp u and domainp v then 1
    else begin scalar x;
       kord!* := var . kord!*;
       if null domainp u and null(mvar u eq var) then u := reorder u;
       if null domainp v and null(mvar v eq var) then v := reorder v;
       x := if !*bezout then bezout_resultant(u,v,var)
	     else polyresultantf(u,v,var);
       setkorder cdr kord!*;
       return x
   end;

symbolic procedure resultantsq(u,v,var);
   if domainp numr u and domainp numr v and denr u = 1 and denr v = 1
     then 1 ./ 1
    else begin scalar x;
       kord!* := var . kord!*;
       if null domainp numr u and null(mvar numr u eq var)
	 then u := reordsq u;
       if null domainp numr v and null(mvar numr v eq var)
	 then v := reordsq v;
       x := if !*bezout then bezout_resultant(!*q2f u,!*q2f v,var)
	     else polyresultantf(!*q2f u,!*q2f v,var);
       setkorder cdr kord!*;
       return !*f2q x
   end;

symbolic procedure polyresultantf(u,v,var);
   begin scalar beta,cd,cn,delta,gam,r,s,temp,x;
      cd := cn := r := s := 1;
      gam := -1;
      if domainp u or domainp v then return 1
       else if ldeg u<ldeg v
	then <<s := (-1)^(ldeg u*ldeg v); temp := u; u := v; v := temp>>;
      while v do
       <<delta := ldeg u-ldegr(v,var);
	 beta := negf(multf(r,exptf(gam,delta)));
	 r := lcr(v,var);
	 gam := multf(exptf(negf r,delta),exptf(gam,1-delta));
	 temp := u;
	 u := v;
	 if not evenp ldeg temp and not evenp ldegr(u,var) then s := -s;
	 v := quotf(pseudo_remf(temp,v,var),beta);
	 if v
	   then <<cn := multf(cn,exptf(beta,ldeg u));
		  cd := multf(cd,
		     exptf(r,(1+delta)*ldeg u-ldeg temp+ldegr(v,var)));
		  if (x := quotf(cd,cn)) then <<cn := 1; cd := x>>>>>>;
      return if not domainp u and mvar u eq var then nil
	      else if ldeg temp neq 1
	       then quotf(multf(s,multf(cn,exptf(u,ldeg temp))),cd)
	      else u
   end;

symbolic procedure lcr(u,var);
   if domainp u or mvar u neq var then u else lc u;

symbolic procedure ldegr(u,var);
   if domainp u or mvar u neq var then 0 else ldeg u;

symbolic procedure pseudo_remf(u,v,var);
   !*q2f simp pseudo!-remainder {mk!*sq(u ./ 1),mk!*sq(v ./ 1),var};

symbolic procedure bezout_resultant(u,v,w);
   begin integer n,nm; scalar ap,ep,uh,ut,vh,vt;
     if domainp u or null(mvar u eq w)
        then return if not domainp v and mvar v eq w
                       then exptf(u,ldeg v)
                     else 1
      else if domainp v or null(mvar v eq w)
        then return if mvar u eq w then exptf(v,ldeg u) else 1;
     n := ldeg v - ldeg u;
     if n < 0 then return multd((-1)**(ldeg u*ldeg v),
                                bezout_resultant(v,u,w));
     ep := 1;
     nm := ldeg v;
     uh := lc u;
     vh := lc v;
     ut := if n neq 0 then multpf(w to n,red u) else red u;
     vt := red v;
     ap := addf(multf(uh,vt),negf multf(vh,ut));
     ep := b!:extmult(!*sf2exb(ap,w),ep);
     for j := (nm - 1) step -1 until (n + 1) do
        <<if degr(ut,w) = j then
             <<uh := addf(lc ut,multf(!*k2f w,uh));
               ut := red ut>>
           else uh := multf(!*k2f w,uh);
          if degr(vt,w) = j then
             <<vh := addf(lc vt,multf(!*k2f w,vh));
               vt := red vt>>
           else vh := multf(!*k2f w,vh);
          ep := b!:extmult(!*sf2exb(addf(multf(uh,vt),
                                    negf multf(vh,ut)),w),ep)>>;
      if n neq 0
         then <<ep := b!:extmult(!*sf2exb(u,w),ep);
                for j := 1:(n-1) do
                ep := b!:extmult(!*sf2exb(multpf(w to j,u),w),ep)>>; 
      return if null ep then nil else lc ep
   end;

endpatch;

% Ncpoly declarations.

fluid '(!*complex !*trnc dipvars!*);

patch ncpoly;

%  9 Jan 01.

symbolic procedure nc_factsolve(s,vl,all);
  begin scalar v,sb,ns,so,soa,sol,nz,w,q,z,r,abort;
   v:= numr simp car vl;
   ns:=for each e in s collect numr simp e;
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
   if null ns and vl then 
   <<sol:={for each x in vl collect x.1};
     goto done>>;
   s:=for each e in ns collect prepf e;
   if !*trnc then
    <<prin2 "solving ";
      prin2 length s; prin2 " polynomial equations for ";
      prin2 length vl;
      prin2t "variables";
      for each e in s do writepri(mkquote e,'only);>>;
   w:=(cdr solveeval{'list.s,'list.vl} where dipvars!*=nil);
 loop:
   nc_factorize_timecheck();
   if null w then goto done;
   so:= cdr car w; w:=cdr w; soa:=nil;
   if smemq('i,so) and null !*complex then go to loop;
   for each y in vl do if not smember(y,so) then
       <<soa:=(y . 1) . soa; nz:=t>>;
   for each y in so do
   <<z:=nc_factorize_unwrap(reval caddr y,soa); 
     nz:=nz or z neq 0;
     soa:=(cadr y . z).soa;
   >>;
   if not nz then goto loop;
   q:=assoc(car vl,soa);
   if null q or cdr q=0 then go to loop;
   soa := for each j in soa collect (car j . sublis(soa,cdr j));
   sol := soa . sol;
   if all then go to loop;
 done:
   sol:=for each s in sol collect append(sb,s);
   if !*trnc then
    <<prin2t "solutions:";
      for each w in sol do
       writepri(mkquote('list.
         for each s in w collect {'equal,car s,cdr s}),'only);
      prin2t "-------------------------";
    >>;
   return sol
  end;

endpatch;

% Plot declarations.

global '(!*plotpause !*plotusepipe dirchar!* opsys!* plotcleanup!*
	 plotcmds!* plotcommand!* plotdir!* plotdta!* plotheader!*
	 tempdir!*);

patch plot;

% 28 Jun 99.

symbolic procedure init_gnuplot();
 <<
!*plotpause := -1;
plotcleanup!* := {};
tempdir!* := getenv 'tmp;
if null tempdir!* then tempdir!* := getenv 'temp;
dirchar!* := "/";
plotcommand!* := "gnuplot";
opsys!* := assoc('opsys, lispsystem!*);
if null opsys!* then opsys!* := 'unknown
else opsys!* := cdr opsys!*;
if getenv "gnuplot" then plotdir!* := getenv "gnuplot"
 else if null plotdir!* and not (opsys!* = 'unix)
  then plotdir!* := get!-lisp!-directory();
if opsys!* = 'win32 then <<
    plotcommand!* := "wgnuplot";
    plotheader!* := "";
    dirchar!* := "\";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcleanup!* := if null tempdir!* then {"erase gnutmp.tm*"}
                     else {bldmsg("erase %w\gnutmp.tm*", tempdir!*)} >>
else if opsys!* = 'msdos then <<
    plotheader!* := "";      % ?? "set term vga";
    dirchar!* := "\";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcmds!*:= gtmpnam "gnutmp.tm0";
    plotcleanup!* := if null tempdir!* then {"erase gnutmp.tm*"}
                     else {bldmsg("erase %w\gnutmp.tm*", tempdir!*)} >>
else if opsys!* = 'riscos then <<
    plotheader!* := "";
    dirchar!* := ".";
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotcleanup!* :=
       bldmsg("remove %w", plotcmds!*) .
          for each f in plotdta!* collect bldmsg("remove %w", f)
    >>
else if opsys!* = 'unix then <<
    plotheader!* := "set term x11";
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotcleanup!* :=
       bldmsg("rm %w", plotcmds!*) .
          for each f in plotdta!* collect bldmsg("rm %w", f) >>
else if opsys!* = 'finder then <<
    plotcommand!* := "gnuplot";
    plotcmds!*:= "::::gnuplot:reduce.plt";
    plotheader!* := "";
    dirchar!* := ":";
    plotdta!* := for each n in
       {"::::gnuplot:gnutmp.tm1", "::::gnuplot:gnutmp.tm2",
        "::::gnuplot:gnutmp.tm3", "::::gnuplot:gnutmp.tm4",
        "::::gnuplot:gnutmp.tm5", "::::gnuplot:gnutmp.tm6",
        "::::gnuplot:gnutmp.tm7", "::::gnuplot:gnutmp.tm8"}
       collect gtmpnam n;
    plotcleanup!* := nil  >>
else <<
    rederr bldmsg("gnuplot for %w not available yet", opsys!*);
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotheader!* := "set term dumb" >>;
if 'pipes member lispsystem!* then !*plotusepipe:=t
else plotcommand!* := bldmsg("%w %w", plotcommand!*, plotcmds!*);
if plotdir!* then
    plotcommand!* := bldmsg("%w%w%w",
                            plotdir!*, dirchar!*, plotcommand!*);
   nil >>;

endpatch;

patch poly;

% 7 Aug 99.

symbolic procedure rationalizesq u;
   begin scalar !*structure,!*sub2,v,x;
      if x := get(dmode!*,'rationalizefn) then u := apply1(x,u);
      powlis!* := '(i 2 (nil . t) -1 nil) . powlis!*;
      v := subs2q u;
      powlis!* := cdr powlis!*;
      return if domainp denr v then v
	      else if (x := rationalizef denr v) neq 1
	       then <<v := multf(numr v,x) ./ multf(denr v,x);
		      if null !*algint and null !*rationalize 
                        then v := gcdchk v;
		      subs2q v>>
	     else u
   end;

%  6 Feb 00, 7 Sep 01.

symbolic procedure sqfrf u;
   begin integer n; scalar !*gcd,units,v,w,x,y,z,!*msg,r;
      !*gcd := t;
      if (r := !*rounded) then
         <<on rational; u := numr resimp !*f2q u>>;
      n := 1;
      x := mvar u;
      v := gcdf(u,diff(u,x));
      u := quotf(u,v);
      if flagp(dmode!*,'field) and ((y := lnc u) neq 1)
	then <<u := multd(!:recip y,u); v := multd(y,v)>>;
      while degr(v,x)>0 do
       <<w := gcdf(v,u);
         if u neq w then z := (quotf(u,w) . n) . z;
         v := quotf(v,w);
         u := w;
         n := n + 1>>;
         if r then
            <<on rounded;
	      u := numr resimp !*f2q u;
	      z := for each j in z
		       collect numr resimp !*f2q car j . cdr j>>;
      if v neq 1 and assoc(v,units) then v := 1;
      if v neq 1 then if n=1 then u := multf(v,u)
       else if (w := rassoc(1,z)) then rplaca(w,multf(v,car w))
       else if null z and ((w := rootxf(v,n)) neq 'failed)
	then u := multf(w,u)
       else if not domainp v then z := aconc(z,v . 1)
       else errach {"sqfrf failure",u,n,z};
      return (u . n) . z
   end;

% 2 Aug 00.

symbolic procedure sqfrp u;
   begin scalar !*ezgcd, dmode!*;
     if null getd 'ezgcdf1 then load_package ezgcd;
     !*ezgcd := t;
     return domainp gcdf!*(u,diff(u,mvar u))
   end;

% 13 Dec 00.

symbolic procedure gcdk(u,v);
   begin scalar lclst,var,w,x;
        if u=v then return u
         else if domainp u or degr(v,(var := mvar u))=0 then return 1
         else if ldeg u<ldeg v then <<w := u; u := v; v := w>>;
        if quotf1(u,v) then return v
         else if !*heugcd and (x := heu!-gcd(u,v)) then return x
         else if ldeg v=1
           or getd 'modular!-multicheck and modular!-multicheck(u,v,var)
           or not !*mcd
          then return 1;
    a:  w := remk(u,v);
        if null w then return v
         else if degr(w,var)=0 then return 1;
        lclst := addlc(v,lclst);
        if x := quotf1(w,lc w) then w := x
         else for each y in lclst do
	    if atom y and not flagp(dmode!*,'field)
	      or not
	       (domainp y and (flagp(dmode!*,'field)
		  or ((x := get(car y,'units))
		       and y member (for each z in x collect car z))))
	    then while (x := quotf1(w,y)) do w := x;
        u := v; v := prim!-part w;
        if degr(v,var)=0 then return 1 else go to a
   end;

% 19 Jan 01.

symbolic procedure quarticf pol;
   begin scalar !*sub2,a,a2,a0,b,dsc,p,p1,p2,q,shift,var;
      var := mvar pol;
      p := shift!-pol pol;
      a := coeffs car p;
      shift := caddr p;
      if cadr a then rerror(poly,16,list(pol,"not correctly shifted"))
	else if cadddr a then return list(1,pol);
      a2 := cddr a;
      a0 := caddr a2;
      a2 := car a2;
      a := car a; 
      q := quadraticf1(a,a2,a0);
      if not(q eq 'failed)
	then <<a2 := car q; q := cdr q;
	       a := exptsq(addsq(!*k2q mvar pol,shift),2);
	       b := numr subs2q quotsq(addsq(multsq(!*f2q car q,a),
					     !*f2q cadr q),
				       !*f2q cadr p);
	       a := numr subs2q quotsq(addsq(multsq(!*f2q caddr q,a),
					     !*f2q cadddr q),
				       !*f2q cadr p);
	       a := quadraticf!*(a,var);
	       b := quadraticf!*(b,var);
	       return multf(a2,multf(car a,car b))
			 . nconc!*(cdr a,cdr b)>>
       else if null !*surds or denr shift neq 1
	then return list(1,pol);
      shift := numr shift;
      if knowndiscrimsign eq 'negative then go to complex;
      dsc := powsubsf addf(exptf(a2,2),multd(-4,multf(a,a0)));
      p2 := minusf a0;
      if not p2 and minusf dsc then go to complex;
      p1 := not a2 or minusf a2;
      if not p1 then if p2 then p1 := t else p2 := t;
      p1 := if p1 then 'positive else 'negative;
      p2 := if p2 then 'negative else 'positive;
      a := rootxf(a,2);
      if a eq 'failed then return list(1,pol);
      dsc := rootxf(dsc,2);
      if dsc eq 'failed then return list(1,pol);
      p := invsq !*f2q addf(a,a);
      q := multsq(!*f2q addf(a2,negf dsc),p);
      p := multsq(!*f2q addf(a2,dsc),p);
      b := multf(a,exptf(addf(!*k2f mvar pol,shift),2));
      a := powsubsf addf(b,q);
      b := powsubsf addf(b,p);
      knowndiscrimsign := p1;
      a := quadraticf!*(a,var);
      knowndiscrimsign := p2;
      b := quadraticf!*(b,var);
      knowndiscrimsign := nil;
      return multf(car a,car b) . nconc!*(cdr a,cdr b);
   complex:
      a := rootxf(a,2);
      if a eq 'failed then return list(1,pol);
      a0 := rootxf(a0,2);
      if a0 eq 'failed then return list(1,pol);
      a2 := powsubsf addf(multf(2,multf(a,a0)),negf a2);
      a2 := rootxf(a2,2);
      if a2 eq 'failed then return list(1,pol);
      p := addf(!*k2f mvar pol,shift);
      q := addf(multf(a,exptf(p,2)),a0);
      p := multf(a2,p);
      a := powsubsf addf(q,p);
      b := powsubsf addf(q,negf p);
      knowndiscrimsign := 'negative;
      a := quadraticf!*(a,var);
      b := quadraticf!*(b,var);
      knowndiscrimsign := nil;
      return multf(car a,car b) . nconc!*(cdr a,cdr b)
   end;

%  7 Apr 01.

symbolic procedure factorize u;
   (begin scalar x,y;
      x := simp!* u;
      y := denr x;
      if not domainp y then typerr(u,"polynomial");
      u := numr x;
      if u = 1 then return
	 {'list, if !*nopowers then 1 else {'list,1,1}}
       else if fixp u then !*ifactor := t;
      if !*force!-prime and not primep !*force!-prime
	then typerr(!*force!-prime,"prime");
      u := if dmode!* and not(dmode!* memq '(!:rd!: !:cr!:))
	 then if get(dmode!*,'factorfn)
                 then begin scalar !*factor;
                        !*factor := t;
			 return fctrf u
                      end
	   else rerror(poly,14,
		       list("Factorization not supported over domain",
		       get(dmode!*,'dname)))
       else fctrf u;
      return facform2list(u,y)
   end) where !*ifactor = !*ifactor;

% 7 Apr 01, 24 Aug 01.

symbolic procedure factor!-prim!-sqfree!-f u;
   begin scalar x,y,!*msg,r;
      r := !*rounded;
      if r and univariatep numr u and lc numr u=1 and denr u=1
	then return unifactor u
       else if r or !*complex or !*rational then
	 <<if r then on rational;
	   u := numr resimp !*f2q car u . cdr u>>;
      if null !*limitedfactors
        then <<if null dmode!* then y := 'factorf
                else <<x := get(dmode!*,'sqfrfactorfn);
                       y := get(dmode!*,'factorfn);
                       if x and not(x eq y) then y := 'factorf>>;
               if y
                 then <<y := apply1(y,car u);
			u := (exptf(car y,cdr u) . for each j in cdr y
                                           collect(car j . cdr u));
                        go to ret>>>>;
      u := factor!-prim!-sqfree!-f!-1(car u,cdr u);
 ret: if r then
      <<on rounded;
        u := car u . for each j in cdr u collect
           (numr resimp !*f2q car j . cdr j)>>;
      return u
   end;

% 7 Apr 01.

symbolic procedure unifactor u;
   if not eqcar(u := root_val list mk!*sq u,'list)
     then errach {"unifactor1",u}
    else 1 . for each j in cdr u collect
		 if not eqcar(j,'equal) then errach{"unifactor2",u}
		  else addsq(!*k2q cadr j,negsq simp caddr j);

% 11 Jun 01.

symbolic procedure noncomp u; 
   !*ncmp and noncomp1 u;

symbolic procedure noncomp1 u;
  if null pairp u then nil
   else if pairp car u then noncomfp u
   else flagp(car u,'noncom) or noncomlistp cdr u;

symbolic procedure noncomlistp u;
   pairp u and (noncomp1 car u or noncomlistp cdr u);

endpatch;

% Rlisp declarations.

fluid '(newrules!*);

patch rlisp;

%  9 Nov 99.

symbolic procedure load!-package u;
   begin scalar x,y;
      if stringp u then return load!-package intern compress explode2 u
       else if null idp u then rederr list(u,"is not a package name")
       else if memq(u,loaded!-packages!*)
        then return u
       else if or(atom(x:= errorset(list('evload,list('quote,list u)),
                               nil,!*backtrace)),
                  cdr x)
        then rederr
           list("error in loading package",u,"or package not found");
      loaded!-packages!* := u . loaded!-packages!*;
      x := get(u,'package);
      if x then x := cdr x;
   a: if null x then go to b
       else if null atom get(car x,'package) then load!-package car x
       else if or(atom(y := errorset(list('evload,
                                         list('quote,list car x)),
                                    nil,!*backtrace)),
                  cdr y)
        then rederr list("module",car x,"of package",u,
                         "cannot be loaded");
      x := cdr x;
      go to a;
   b: if (x := get(u,'patchfn))
	then begin scalar !*usermode,!*redefmsg; eval list x end
   end;

% 22 April 00.

symbolic procedure begin11 x;
   begin scalar mode,result,newrule!*;
      if cursym!* eq 'end
	 then if terminalp() and null !*lisp!_hook
		then progn(cursym!* := '!*semicol!*, !*nosave!* := t,
			   return nil)
	       else progn(comm1 'end, return 'end)
       else if eqcar((if !*reduce4 then x else cadr x),'retry)
	then if programl!* then x := programl!*
	      else progn(lprim "No previous expression",return nil);
      if null !*reduce4 then progn(mode := car x,x := cadr x);
      program!* := x;
      if eofcheck() then return 'c else eof!* := 0;
      add2inputbuf(x,if !*reduce4 then nil else mode);
      if null atom x
	  and car x memq '(bye quit)
	then if getd 'bye
	       then progn(lispeval x, !*nosave!* := t, return nil)
	      else progn(!*byeflag!* := t, return nil)
       else if null !*reduce4 and eqcar(x,'ed)
	then progn((if getd 'cedit and terminalp()
		      then cedit cdr x
		     else lprim "ED not supported"),
		   !*nosave!* := t, return nil)
       else if !*defn
	then if erfg!* then return nil
	      else if null flagp(key!*,'ignore)
		and null eqcar(x,'quote)
	       then progn((if x then dfprint x else nil),
			  if null flagp(key!*,'eval) then return nil);
      if !*output and ifl!* and !*echo and null !*lessspace
	then terpri();
      result := errorset!*(x,t);
      if errorp result or erfg!*
	then progn(programl!* := list(mode,x),return 'err2)
       else if !*defn then return nil;
      if null !*reduce4
	then if null(mode eq 'symbolic) then x := getsetvars x else nil
       else progn(result := car result,
		  (if null result then result := mkobject(nil,'noval)),
		  mode := type result,
		  result := value result);
      add2resultbuf((if null !*reduce4 then car result else result),
		    mode);
      if null !*output then return nil
       else if null(semic!* eq '!$)
	then if !*reduce4 then (begin
		   terpri();
		   if mode eq 'noval then return nil
		    else if !*debug then prin2t "Value:";
		   rapply1('print,list list(mode,result))
		 end)
       else if mode eq 'symbolic
	      then if null car result and null(!*mode eq 'symbolic)
		     then nil
	      else begin
		  terpri();
		  result:=
		       errorset!*(list('print,mkquote car result),t)
		    end
       else if car result
	then result := errorset!*(list('assgnpri,mkquote car result,
				       (if x then 'list . x else nil),
				       mkquote 'only),
				  t);
      if null !*reduce4
	then return if errorp result then 'err3 else nil
       else if null(!*mode eq 'noval)
	then progn(terpri(), prin2 "of type: ", print mode);
      return nil
   end;

endpatch;

% Roots declarations.

% fluid '(rootacc!#!# rootacc!#!# !*noeqns);

% patch roots;

% 10 Feb 00.

% Commented out since now solved another way (7 Apr 01).

% symbolic procedure root_val x;
%    roots x
%      where rootacc!#!#=p, iniprec!#=p where p=precision 0, !*msg=nil,
%            !*noeqns=t;

% endpatch;

% Scope declarations.

global '(kvarlst prevlst varlst!*);

patch scope;

% 29 Aug 00.

symbolic procedure maxtype type;
   if atom type then type
    else if pairp cdr type then cadr type else car type;

%  8 Nov 00.

symbolic procedure prepmultmat(preprefixlist);
begin scalar tlcm,var,varexp,kvl,kfound,pvl,pfound,tel,ratval,ratlst,
                                                      newvarlst,hvarlst;
 hvarlst:= nil;
 while not null (varlst!*) do
 <<var := car varlst!*; varlst!* := cdr varlst!*;
   if flagp(var,'ratexp)
    then
     <<tlcm:=1;
       remflag(list var,'ratexp);
       foreach elem in get(var,'varlst!*) do
        if pairp cdr elem then tlcm := lcm2(tlcm,cddr elem);
       varexp:=fnewsym();
       tel:=(varexp.(if tlcm = 2
                 then list('sqrt,var)
                 else list('expt,var,
                         if onep cdr(tel:=simpquot list(1,tlcm)) then
                            car tel
                         else
                            list('quotient,car tel,cdr tel))));
       if assoc(var,kvarlst)
        then
         <<kvl:=kfound:=nil;
           while kvarlst and not(kfound) do
            if caar(kvarlst) eq var
             then
              << kvl:=tel.kvl; kfound:=t;
                 pvl:=pfound:=nil; prevlst:=reverse(prevlst);
                 while prevlst and not(pfound) do
                  if cdar(prevlst) eq var
                   then << pvl:=cons(caar prevlst,varexp).pvl;
                           pfound:=t
                        >>
                   else << pvl:=car(prevlst).pvl;
                           prevlst:=cdr(prevlst)
                        >>;
                 if pvl then
                  if prevlst then prevlst:=append(reverse prevlst,pvl)
                             else prevlst:=pvl
              >>
             else
              << kvl:=car(kvarlst).kvl; kvarlst:=cdr kvarlst>>;
           if kvl then
             if kvarlst then kvarlst:=append(reverse kvl,kvarlst)
                      else kvarlst:=reverse kvl
         >>
        else preprefixlist:=tel.preprefixlist;
       ratlst:=newvarlst:=nil;
       foreach elem in get(var,'varlst!*) do
        if pairp cdr elem
         then 
          << ratval:=divide((tlcm * cadr elem)/(cddr elem),tlcm);
             ratlst:=cons(car elem,cdr ratval).ratlst;
             if car(ratval)>0
              then newvarlst:=cons(car elem,car ratval).newvarlst
          >>
         else newvarlst:=elem.newvarlst;
       if ratlst
        then << put(varexp,'varlst!*,reverse ratlst);
                hvarlst:=varexp.hvarlst
             >>;
       if newvarlst
        then << put(var,'varlst!*,reverse newvarlst);
                hvarlst:=var.hvarlst
             >>
        else remprop(var,'varlst!*)
     >>
    else hvarlst:=var.hvarlst
 >>;
 varlst!* := hvarlst;
 return preprefixlist
   end;

endpatch;

% Solve declarations.

fluid '(!*multiplicities vars!*);

global '(multiplicities!*);

patch solve;

%  9 Jan 01.

symbolic procedure !*solvelist2solveeqlist u;
   begin scalar x,y,z;
      u := for each j in u collect solveorder j;
      for each j in u do
         <<if caddr j=0 then rerror(solve,2,"zero multiplicity")
            else if null cadr j
             then  x := for each k in car j collect
                                               list('equal,!*q2a k,0)
            else x := for each k in pair(cadr j,car j)
                          collect list('equal,car k,!*q2a cdr k);
           if length vars!* > 1 then x := 'list . x else x := car x;
           z := (caddr j . x) . z>>;
      z := sort(z,function ordp);
      x := nil;
      if !*multiplicities
	 then <<for each k in z do for i := 1:car k do x := cdr k . x;
		multiplicities!* := nil>>
       else <<for each k in z do << x := cdr k . x; y := car k . y>>;
	      multiplicities!* := 'list . reversip y>>;
      return 'list . reversip x
   end;

% 9 Jan 01, 15 Jun 01.

symbolic procedure solveorder u;
   begin scalar v,w,x,y,z;
      v := vars!*;
      x := cadr u;
      if length x<length v then v := setdiff(v,setdiff(v,x));
      if null x or x=v then return u;
      y := car u;
      while x do <<z := (car x . car y) . z; x := cdr x; y := cdr y>>;
      w := v;
  a:  if null w then return reversip x . v . cddr u
       else if null(y := depassoc(car w,z)) then return u
       else x := cdr y . x;
      w := cdr w;
      go to a
   end;

symbolic procedure depassoc(u,v);
   if null v then nil
    else if u = caar v then car v
    else if depends(caar v,u) then nil
    else depassoc(u,cdr v);

% 2 Feb 01.

symbolic procedure check!-solns(z,ex,var);
   begin scalar x;
      if errorp (x :=
	    errorset2 {'check!-solns1,mkquote z,mkquote ex,mkquote var})
	then return
	   check!-solns1(z,(numr simp!* prepf ex where !*reduced=t),var)
       else return car x
   end;

symbolic procedure check!-solns1(z,ex,var);
   begin scalar x,y,fv,sx,vs;
      fv := freevarl(ex,var);
      for each z1 in z do
        fv := union(fv,union(freevarl(numr caar z1,var),
                             freevarl(denr caar z1,var)));
      fv := delete('i,fv);
      if fv then for each v in fv do
        if not flagp(v,'constant) then
           vs := (v . list('quotient,1+random 999,1000)) . vs;
      sx := if vs then numr subf(ex,vs) else ex;
      while z do
         if null cadar z then <<z := nil; x := 'unsolved>>
         else if
           <<y := numr subf(ex,list(caadar z . mk!*sq caaar z));
             null y
             or fv and null(y := numr subf(sx,list(caadar z .
                   mk!*sq subsq(caaar z,vs))))
             or null numvalue y>>
           then <<x := car z . x; z := cdr z>>
          else z := cdr z;
      return if null x then 'unsolved else x
   end;

%  7 Apr 01.

symbolic procedure solvequadratic(a2,a1,a0);
   if !*rounded and numcoef a0 and numcoef a1 and numcoef a2
      then for each z in cdr root_val list mkpolyexp2(a2,a1,a0)
	 collect simp!* (if eqcar(z,'equal) then caddr z
			  else errach {"Quadratic confusion",z})
    else begin scalar d;
      d := sqrtq subtrsq(quotsqf(exptsq(a1,2),4),multsq(a2,a0));
      a1 := quotsqf(negsq a1,2);
      return list(subs2!* quotsq(addsq(a1,d),a2),
                  subs2!* quotsq(subtrsq(a1,d),a2))
   end;

endpatch;

% Sum declarations.

fluid '(sum_last_attempt_rules!* !*zeilberg);

patch sum;

% 28 Jul 00.

symbolic procedure freeof!-df(u, v);
   if atom u then t
    else if car(u) eq 'df
     then freeof!-df(cadr u, v) and not smember(v,cddr u)
    else freeof!-dfl(cdr u, v);

symbolic procedure freeof!-dfl(u, v);
   if null u then t else freeof!-df(car u,v) and freeof!-dfl(cdr u,v);

symbolic procedure simp!-sum u;
   begin scalar y;
      y := cdr u;
      u := car u;
      if not atom y and not freeof!-df(u, car y) then
	if atom y
	       then return !*p2f(car fkern(list('sum,u)) .* 1) ./ 1
	 else return sum!-df(u, y);
      u := simp!* u;
      return if null numr u then u
	      else if atom y
               then !*p2f(car fkern(list('sum,prepsq u)) .* 1) ./ 1
	      else if !*zeilberg then gosper!*(mk!*sq u,y)
	      else simp!-sum0(u,y)
   end;

symbolic procedure sum!-subst(u,x,a);
   if u = x then a
    else if atom u then u
    else sum!-subst(car u, x,a) . sum!-subst(cdr u,x,a);

symbolic procedure sum!-df(u,y);
   begin scalar w,z,upper,lower,dif;
      if length(y) = 3 then  <<
	 lower := cadr y;
	 upper := caddr y;
	 dif := addsq(simp!* upper, negsq simp!* lower);
	 if denr dif = 1 then
	    if null numr dif
	       then return simp!* sum!-subst(u, car y, upper)
	       else if fixp numr dif then dif := numr dif
	       else dif := nil
	   else dif := nil;
	 if dif and dif <= 0 then return nil ./ 1 >>;
     if null dif then <<
	  z := 'sum . (u . y);
	  let sum_last_attempt_rules!*;
	  w:= opmtch z;
	  rule!-list (list sum_last_attempt_rules!*,nil);
	  return if w then simp w else mksq(z,1)>>;
     z := nil ./ 1;
  a: if dif < 0 then return z;
     z := addsq(z,simp!* sum!-subst(u, car y, list('plus,lower,dif)));
     dif := dif - 1;
     go to a
   end;

% 20 Nov 00.

symbolic procedure termlst(u,v,klst);
   begin scalar x,kern,lst;
      if null u then return nil
       else if null klst or domainp u
	then return list multsq(v,!*f2q u);
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

endpatch;

% Taylor declarations.

fluid '(!*taylorautocombine);

patch taylor;

% 1 Jun 01.

symbolic procedure simptaylor u;
  if remainder(length u,3) neq 1
    then Taylor!-error('wrong!-no!-args,'taylor)
   else if null subfg!* then mksq('taylor . u,1)
   else begin scalar !*precise,arglist,degree,f,ll,result,var,var0;
     if !*taylorautocombine and not ('taysimpsq memq mul!*)
       then mul!* := aconc!*(mul!*,'taysimpsq);
     f := simp!* car u;
     u := revlis cdr u;
     arglist := u;
     while not null arglist do
       << var := car arglist;
          var := if eqcar(var,'list) then cdr var else {var};
          for each el in var collect begin
            el := simp!* el;
            if kernp el then return mvar numr el
             else typerr(prepsq el,'kernel)
            end;
          var0 := cadr arglist;
          degree := caddr arglist;
          if not fixp degree
            then typerr(degree,"order of Taylor expansion");
          arglist := cdddr arglist;
          ll := {var,var0,degree,degree + 1} . ll>>;
     result := taylorexpand(f,reversip ll);
     return if smember('Taylor!*,result) then result
             else mksq('taylor . prepsq f . u,1)
   end;

endpatch;

endmodule;

end;
