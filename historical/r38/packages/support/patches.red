module patches; % Patches to correct problems in REDUCE 3.8.

% Author: Anthony C. Hearn.

% Copyright (c) 2004, 2005, 2006, 2007 Anthony C. Hearn.  All Rights Reserved.

global '(patch!-date!* patch!-url!-list!*);

patch!-date!* := "11-Jan-2007";

patch!-url!-list!* :=
   '("http://reduce-algebra.com/support/patches/patches.fsl");


% Bugs fixed by these patches.

% 26 Jun 04.  With rounded arithmetic, solving some linear equation
%             problems could lead to a catastrophic error.

%  8 Jul 04.  Some non-zero integrals (e.g., int(e^(a^(1/3)*x)*sin x,x))
%             returned zero.

%  5 Aug 04.  Using RLFI with latex on could lead to invalid operator errors.

%  2 Sep 04.  In rare circumstances, floating point conversion could give
%             an extraneous error.

%  6 Sep 04.  With rational on, some non-zero factorizations could produce
%             a zero coefficient (e.g., on rational;
%             factorize(r^((1/4*n^2 - 1/4*n + 1)/(n - 1)));).

% 28 Sep 04.  Some integrals would not return a closed form solution
%             with algint on that would with algint off
%             (e.g., int(sqrt(x-1)/(sqrt x*(x-1)),x)).

% 10 Dec 04.  With dfprin on, some products and sums printed incorrectly.

% 31 Jan 05.  Some integrals involving square roots could run forever.

% 12 Feb 05.  SOLVE could produce a spurious recursive loop (e.g.,
%             solve((4*e^(y^3/3)*cte+2x^2+y^3+3)/e^(y^3/3),y)).

% 20 Apr 05. int(e^(-a^(1/4)*(-1)^(1/4)*x),x); terminated with an error.

%  2 May 05. int(e^(-a^(1/4)*(-1)^(1/4)*i*x)*b+(1/4)*e^(-a^(1/4)
%                       *(-1)^(1/4)*i*x)*x,x); terminated with an error.

% 22 May 05. Some integrals, e.g., int(e^((3sqrt 5+1)*x)*(sqrt 5+1)
%             +e^((3sqrt 5-1)*x)*(sqrt 5+1),x), never completed.

% 30 May 05. SOLVE could produce a spurious "Zero divisor" error
%            (e.g., solve({log tan(y/2),y+1/x},{x,y})).

%  4 Oct 05. DEG did not work with rational coefficients (e.g.,
%            deg(x**3/a-x/5+1/4,x)).

%  5 Oct 05. Some SOLVE calculations could give a spurious "Zero Divisor"
%            error (e.g., ex0:= sqrt(a^2-y^2); solve((-log(( - x + a + y)
%               /ex0) + log((x + a + y)/ex0) + x - (a^2 - y^2)/ex0),y);

% 16 Nov 05. System errors could occur with rounded and combineexpt on.
%            (E.g., on rounded,combineexpt; 0.183*e^x*t^4.39;).

% 22 Nov 05. Some definite integrals with variables other than x could
%            give a wrong answer, e.g., int(e^(-y),y,0,x).

%  9 Dec 05. With combineexpt on, expressions could be dropped (e.g.,
%            on combineexpt; 4*e^(-3*h/2) - 3*h*e^(-h) + 2*e^(-h)).

%  4 Feb 06. Setcrackflags() was not set in crack, but needed to be.

% 20 Feb 06. The rule for df(Jacobidn(~u,~m),~u) was wrong.

% 21 Feb 06. Evaluating some integrals could suppress the printing of
%            the results.

% 22 Feb 06. Some sub evaluations could include superfluous terms like
%            x = (x^(1/7))^7.

% 23 May 06. Derivatives and integrals of matrices were not computed.

% 18 Aug 06. After nospur, some traces were still evaluated.

% 29 Sep 06. With dfprint on, derivatives of integrals would print in a
%            truncated form.

% 11 Jan 07. With rounded arithmetic and factor on, a non-numeric
%            argument error could occur.

% Alg declarations.

fluid '(sublist!*);

patch alg;

% 16 Nov 05, 9 Dec 05.

symbolic procedure exptunwind(u,v);
   begin scalar x,x1,x2,y,z,z2;
  a:  if null v then return u;
      x := caar v;
      x1 := cadr x;
      x2 := caddr x;
      y := cdar v;
      v := cdr v;
      if !*combineexpt and null domainp u and null red u
	  and (z2 := kernels u) and null cdr z2
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
	     else if domainp numr z2 then y := 1
	     else <<y := lcoeffgcd cdr comfac numr z2;
		    if not fixp y then y := 1>>;
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

% 22 Feb 06.

symbolic procedure subeval0 u;
   begin scalar x,y,z,ns;
   while cdr u do <<if not eqcar(car u,'equal) then x := car u . x
		     else if not(cadar u = (y := reval caddar u))
		      then x := {caar u,cadar u,y} . x;
		    u := cdr u>>;
   if null x then return car u else u := nconc(reversip x,u);
      if u member sublist!* then return mk!*sq !*p2q mksp('sub . u,1)
       else sublist!* := u . sublist!*;
      if null(u and cdr u)
       then rederr "SUB requires at least 2 arguments";
      (while cdr u do
	  <<x := reval car u;
	    if getrtype x eq 'list then u := append(cdr x,cdr u)
	     else <<if not eqexpr x then errpri2(car u,t);
		    y := cadr x;
		    if null getrtype y then y := !*a2kwoweight y;
		    if getrtype caddr x then ns := (y . caddr x) . ns
		     else z := (y . caddr x) . z;
		    u := cdr u>>>>) where !*evallhseqp=nil;
      x := aeval car u;
      return subeval1(append(ns,z),x)
   end;

symbolic procedure subsubf(l,expn);
   begin scalar x,y;
      for each j in l do if car j neq (y := prepsq!* simp!* cdr j)
			   then x := (car j . y) . x;
      l := reversip x;
      if null l then return expn;
      y := nil;
      for each j in cddr expn do
         if (x := assoc(j,l)) then <<y := x . y; l := delete(x,l)>>;
      expn := sublis(l,car expn)
                 . for each j in cdr expn collect subsublis(l,j);
      if null y then return expn;
      expn := aconc!*(for each j in reversip!* y
                     collect list('equal,car j,aeval cdr j),expn);
      return if l then subeval expn
	      else mk!*sq !*p2q mksp('sub . expn,1)
   end;

% 23 May 06.

symbolic procedure reval1(u,v);
   (begin scalar x,y;
      if null u then return nil
       else if stringp u then return u
       else if fixp u
        then return if flagp(dmode!*,'convert) then reval2(u,v) else u
       else if atom u
	then if null subfg!* then return u
	      else if idp u and (x := get(u,'avalue))
               then if u memq varstack!* then recursiveerror u
                     else <<varstack!* := u . varstack!*;
			    return if y := get(car x,'evfn)
				     then apply2(y,u,v)
				    else reval1(cadr x,v)>>
              else nil
       else if not idp car u
        then errpri2(u,t)
       else if car u eq '!*sq
	then return if caddr u and null !*resimp
                      then if null v then u else prepsqxx cadr u
                     else reval2(u,v)
       else if flagp(car u,'remember) then return rmmbreval(u,v)
       else if flagp(car u,'opfn) then return reval1(opfneval u,v)
       else if x := get(car u,'psopfn)
	 then <<u := apply1(x,cdr u);
		if x := get(x,'cleanupfn) then u := apply2(x,u,v);
		return u>>
       else if arrayp car u then return reval1(getelv u,v);
       return if x := getrtype u then
		  if y := get(x,'evfn) then apply2(y,u,v)
		    else rerror(alg,101,
				list("Missing evaluation for type",x))
	       else if not atom u
		     and not atom cdr u
		     and (y := getrtype cadr u)
		     and null(y eq 'list and cddr u)
		     and (x := get(y,'aggregatefn))
		     and (not(x eq 'matrixmap) or flagp(car u,'matmapfn))
		     and not flagp(car u,'boolean)
		     and not !*listargs and not flagp(car u,'listargp)
                then apply2(x,u,v)
               else reval2(u,v)
   end) where varstack!* := varstack!*;

symbolic procedure getrtype2 u;
   begin scalar x;
      return if (x := get(car u,'rtype)) and (x := get(x,'rtypefn))
	       then apply1(x,cdr u)
	      else if x := get(car u,'rtypefn) then apply1(x,cdr u)
	      else if flagp(car u,'matmapfn) and cdr u
		 and getrtype cadr u eq 'matrix
	       then 'matrix
	      else nil
   end;

endpatch;

patch arith;

% 2 Sep 04.

symbolic procedure read!:num(n);
   if fixp n then make!:ibf(n, 0)
    else if not(numberp n or stringp n) then bflerrmsg 'read!:num
    else begin integer j,m,sign;  scalar ch,u,v,l,appear!.,appear!/;
          j := m := 0;
          sign := 1;
          u := v := appear!. := appear!/ := nil;
          l := explode n;
    loop: ch := car l;
          if digit ch then << u := ch . u; j := j + 1 >>
           else if ch eq '!. then << appear!. := t; j := 0 >>
           else if ch eq '!/ then << appear!/ := t; v := u; u := nil >>
           else if ch eq '!- then sign := -1
	   else if ch memq '(!E !D !B !e !d !b) then go to jump;
           if l := cdr l then goto loop else goto make;
    jump: while l := cdr l do
	    <<if digit(ch := car l) or ch eq '!-
		 then v := ch . v >>;
	  l := reverse v;
	  if car l eq '!- then m := - compress cdr l
			  else m:= compress l;
    make: u := reverse u;
          v := reverse v;
          if appear!/ then
            return conv!:r2bf(make!:ratnum(sign*compress v,compress u),
                              if !:bprec!: then !:bprec!: else 170);
          if appear!. then j := - j else j := 0;
          if sign = 1 then u := compress u else u := - compress u;
          return round!:mt (decimal2internal (u, j + m), !:bprec!:)
                   where !:bprec!: := if !:bprec!: then !:bprec!:
                                       else msd!: abs u
    end;

endpatch;

patch crack;

setcrackflags();

endpatch;

% Defint declarations.

symbolic smacro procedure listsq(u);
   for each uu in u collect simp!* uu;

patch defint;

symbolic procedure new_meijer(u);
begin scalar f,y,mellin,new_mellin,m,n,p,q,old_num,old_denom,temp,a1,
b1,a2,b2,alpha,num,denom,n1,temp1,temp2,coeff,v,var,new_var,new_y,
new_v,k;
f := prepsq simp car u;
y := caddr u;
mellin := bastab(car f,cddr f);
temp := car cddddr mellin;
var := cadr f;
if not idp VAR then RETURN error(99,'FAIL);
temp := reval algebraic(sub(x=var,temp));
mellin := {car mellin,cadr mellin,caddr mellin,cadddr mellin,temp};
temp := reduce_var(cadr u,mellin,var);
alpha := simp!* car temp;
new_mellin := cdr temp;
if car cddddr new_mellin neq car cddddr mellin then
        << k := car cddddr mellin;
           y := reval algebraic(sub(var=y,k));
           new_y := simp y>>
else
<< new_var := car cddddr new_mellin;
   new_y := simp reval algebraic(sub(x=y,new_var))>>;
n1 := addsq(alpha,'(1 . 1));
temp1 := {'expt,y,prepsq n1};
temp2  := cadddr new_mellin;
coeff := simp!* reval algebraic(temp1*temp2);
m := caar new_mellin;
n := cadar new_mellin;
p := caddar new_mellin;
q := car cdddar new_mellin;
old_num := cadr new_mellin;
old_denom := caddr new_mellin;
for i:=1 :n do
<< if old_num = nil then a1 := append(a1,{simp!* old_num })
   else <<  a1 := append(a1,{simp!* car old_num});
            old_num := cdr old_num>>;
>>;
for j:=1 :m do
<< if old_denom = nil then b1 := append(b1,{simp!*  old_denom })
   else <<  b1 := append(b1,{simp!* car old_denom});
            old_denom := cdr old_denom>>;
>>;
a2 := listsq old_num;
b2 := listsq old_denom;
if a1 = nil and a2 = nil then
    num := list({negsq alpha})
else if a2 = nil then num := list(append(a1,{negsq alpha}))
else
<< num := append(a1,{negsq alpha}); num := append({num},a2)>>;
if b1 = nil and b2 = nil then
    denom := list({subtrsq(negsq alpha,'(1 . 1))})
else if b2 = nil then
    denom := list(b1,subtrsq(negsq alpha,'(1 . 1)))
else
<< denom := list(b1,subtrsq(negsq alpha,'(1 . 1)));
   denom := append(denom,b2)>>;
v := gfmsq(num,denom,new_y);
if v = 'fail then return simp 'fail
else v := prepsq subsq(v,list(prepsq new_y . y));
if eqcar(v,'meijerg) then new_v := v else new_v := simp v;
return multsq(new_v,coeff);
end;

endpatch;

patch hephys;

symbolic procedure nospur u; <<rmsubs(); !*nospurp := t; flag(u,'nospur)>>;

endpatch;

% Int declarations.

fluid '(!*purerisch !*trdint gaussiani indexlist intvar sqrt!-places!-alist
        loglist !*intflag!* listofnewsqrts listofallsqrts sqrt!-intvar
        basic!-listofallsqrts basic!-listofnewsqrts !*precise dmode!*
        !*exp !*gcd !*keepsqrts !*limitedfactors !*mcd !*rationalize
	!*structure !*uncached kord!*);

smacro procedure argof u; cadr u;

patch int;

% 8 Jul 04, 31 Jan 05, 20 Apr 05, 2 May 05.

symbolic procedure df2q p;
   begin scalar n,d,w,x,y,z;
      if null p then return nil ./ 1;
      d:=denr lc p;
      w:=red p;
      while w do
       <<d := multf(d,quotf(denr lc w,gcdf(d,denr lc w)));
	 w := red w>>;
      while p do begin
	   w := sqrt2top lc p;
	   x := multf(xl2f(lpow p,zlist,indexlist),multf(numr w,d));
	   if null x then return (p := red p);
	   y := denr w;
	   z := quotf(x,y);
	   if null z
	     then <<z := rationalizesq(x ./ y);
		    if denr z neq 1
		      then <<d := multf(denr z,d); n := multf(denr z,n)>>;
		    z := numr z>>;
	   n := addf(n,z);
	   p := red p
	end;
      return tidy!-powersq (n ./ d)
   end;

% 8 Jul 04, 22 May 05.

symbolic procedure tidy!-powersq x;
   begin scalar expts,!*precise,!*keepsqrts;
    !*keepsqrts := t;
    x := subs2q x;
    expts := find!-expts(numr x,find!-expts(denr x,nil));
    if null expts then return x;
    x := subsq(x,for each v in expts collect
		    (car v . list('expt,cadr v,cddr v)));
    x := subsq(x,for each v in expts collect
		    (cadr v
			. list('expt,car v,list('quotient,1,cddr v))));
    return x
  end;

symbolic procedure find!-expts(ff,l);
   begin scalar w;
      if domainp ff then return l;
      l := find!-expts(lc ff,find!-expts(red ff, l));
      ff := mvar ff;
      if eqcar(ff,'sqrt)
	then ff := list('expt, cadr ff,'(quotient 1 2))
       else if eqcar(ff,'expt) and eqcar(caddr ff,'quotient)
	  and numberp caddr caddr ff
	then <<w := assoc(cadr ff,l);
	       if null w
		 then <<w := cadr ff . gensym() . 1; l := w . l >>;
	       rplacd(cdr w,lcm(cddr w,caddr caddr ff))>>;
      return l
   end;

% 28 Sep 04.

symbolic procedure look_for_quad(integrand, var, zz);
 begin
  if (car zz = 'sqrt and listp cadr zz and caadr zz = 'plus) or
     (car zz = 'expt and listp cadr zz and caadr zz = 'plus and
      listp caddr zz and car caddr zz = 'quotient
         and fixp caddr caddr zz)
   then <<
    zz := simp cadr zz;
    if (cdr zz = 1) then <<
        zz := cdr coeff1(prepsq zz, var, nil);
	if length zz = 2 then return begin
          scalar a, b;
          scalar nvar, res, ss;
          a := car zz; b := cadr zz;
          if (depends(a,var) or depends(b,var)) then return nil;
          nvar := gensym();
          if !*trint then <<
                prin2 "Linear shift suggested ";
                prin2 a; prin2 " "; prin2 b; terpri();
          >>;
	  integrand := subsq(integrand,
                             list(var . list('quotient,
                                             list('difference,
                                                  list('expt,nvar,2),a),
                                                  b)));
	  integrand := multsq(integrand,
                              simp list('quotient,list('times,nvar,2),
                                        b));
          if !*trint then <<
                prin2 "Integrand is transformed by substitution to ";
                printsq integrand;
                prin2 "using substitution "; prin2 var; prin2 " -> ";
                printsq simp list('quotient,
                                 list('difference,list('expt,nvar,2),a),
                                 b);
           >>;
           res := integratesq(integrand, nvar, nil, nil);
           ss := list(nvar . list('sqrt,list('plus,list('times,var,b),
                                  a)));
           res := subsq(car res, ss) .
                  subsq(multsq(cdr res, simp list('quotient,b,
                                                  list('times,nvar,2))), ss);
           return res;
        end
	else if length zz = 3 then return begin
          scalar a, b, c;
          a := car zz; b := cadr zz; c:= caddr zz;
          if (depends(a,var) or depends(b,var) or depends(c,var)) then
                return nil;
	  a := simp list('difference, a,
                         list('times,b,b,
                         list('quotient,1,list('times,4,c))));
	  if null numr a then return nil;
          b := simp list('quotient, b, list('times, 2, c));
          c := simp c;
          return
           if minusf numr c then <<
           if minusf numr a then  begin
                            scalar !*hyperbolic;
                            !*hyperbolic := t;
                            return
                                look_for_invhyp(integrand,nil,var,a,b,c)
                        end
            else                look_for_asin(integrand,var,a,b,c)>>
          else <<
            if minusf numr a then look_for_invhyp(integrand,t,var,a,b,c)
          else                  look_for_invhyp(integrand,nil,var,a,b,c)
          >>
        end
	else if length zz = 5 then return begin
          scalar a, b, c, d, e, nn, dd, mm;
          a := car zz; b := cadr zz; c:= caddr zz;
          d := cadddr zz; e := car cddddr zz;
          if not(b = 0) or not(d = 0) then return nil;
          if (depends(a,var) or depends(c,var)) or depends(e,var) then
                return nil;
          nn := numr integrand;  dd := denr integrand;
          if denr(mm :=quotsq(nn ./ 1, !*kk2q var)) = 1 and
             even_power(numr mm, var) and even_power(dd, var) then <<
              return sqrt_substitute(numr mm, dd, var);
          >>;
          if denr(mm :=quotsq(dd ./ 1, !*kk2q var)) = 1 and
             even_power(nn, var) and even_power(numr mm, var) then <<
              return sqrt_substitute(nn, multf(dd,!*kk2f var), var);
          >>;
          return nil;
        end;
  >>>>;
  return nil
end;

% 21 Feb 06.

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
	       then printc {"Integration kernel", variable,
			  "replaced by simple variable", cdr varchange};
	     variable := cdr varchange>>;
    intvar := variable;
    w := cddr u;
    if w then rerror(int,3,"Too many arguments to INT");
    listofnewsqrts:= list mvar gaussiani;
    listofallsqrts:= list (argof mvar gaussiani . gaussiani);
    sqrtfn := get('sqrt,'simpfn);
    put('sqrt,'simpfn,'proper!-simpsqrt);
    if dmode!* then
       <<
	  if (cflag:=get(dmode!*, 'cmpxfn)) then onoff('complex, nil);
	  if (dmod := get(dmode!*,'dname)) then
	     onoff(dmod,nil)>> where !*msg := nil;
    begin scalar dmode!*,!*exp,!*gcd,!*keepsqrts,!*limitedfactors,!*mcd,
		 !*rationalize,!*structure,!*uncached,kord!*,
		 ans1,badbit,denexp,erfg,nexp,oneterm;
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
	   zv := zvars(getvariables x,zv,variable,t);
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
	  erfg := erfg!*;
	  ans1 := errorset!*(list('integratesq,mkquote u,
			     mkquote variable,mkquote loglist,
			     mkquote caar nexp),
			     !*backtrace);
	  erfg!* := erfg;
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
    if !*trdint then << printc "Resimp and all that"; printsq ans >>;
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

endpatch;

patch mathpr;

% 10 Dec 04, 29 Sep 06.

symbolic procedure dflayout u;
  (begin
      scalar op, args, w;
      w := car (u := cdr u);
      u := cdr u;
      if smemq('int,w) then !*noarg := nil;
      if !*noarg and (atom w or not get(car w, 'op)) then <<
         if atom w then <<
            op := w;
	    args := assoc(op, depl!*);
            if args then args := cdr args >>
         else <<
            op := car w;
	    args := cdr w >>;
         remember!-args(op, args);
         w := op >>;
      maprin w;
      if u then <<
	 u := layout!-formula('!!dfsub!! . u, 0, nil);
         if null u then return 'failed;
         w := 1 + cddr u;
         putpline((update!-pline(0, -w, caar u) . cdar u) .
                  ((cadr u - w) . (cddr u - w))) >>
   end) where !*noarg = !*noarg;

endpatch;

patch matrix;

% 26 Jun 04.

symbolic procedure sparse_backsub(exlis,varlis);
   begin scalar d,z,c;
   if null exlis then return nil;
   d := lc car exlis;
   foreach x in exlis do
      begin scalar s,p,v,r;
      p := lc x;
      v := mvar x;
      x := red x;
      while not domainp x and mvar x member varlis do
	  <<if (c := atsoc(mvar x,z)) then
               s := addf(multf(lc x,cdr c),s)
	    else r := addf(!*t2f lt x,r);
            x := red x>>;
      s := negf quotff(addf(multf(addf(r,x),d),s),p);
      z := (v . s) . z;
      end;
   for each p in z do cdr p := cancel(cdr p ./ d);
   return z
   end;

symbolic procedure quotff(u,v);
   if null u then nil
    else (if x then x
	   else (if denr y = 1 then numr y
		  else rederr "Invalid division in backsub")
		 where y=rationalizesq(u ./ v))
	  where x=quotf(u,v);

% 23 May 06.

symbolic procedure matsm1 u;
   begin scalar x,y,z; integer n;
    a:  if null u then return z
         else if eqcar(car u,'!*div) then go to d
         else if atom car u then go to er
         else if caar u eq 'mat then go to c1
	 else if flagp(caar u,'matmapfn) and cdar u
	    and getrtype cadar u eq 'matrix
	  then x := matsm matrixmap(car u,nil)
	 else <<x := lispapply(caar u,cdar u);
	  if eqcar(x,'mat) then x := matsm x>>;
    b:  z := if null z then x
              else if null cdr z and null cdar z then multsm(caar z,x)
              else multm(x,z);
    c:  u := cdr u;
        go to a;
    c1: if not lchk cdar u then rerror(matrix,3,"Matrix mismatch");
        x := for each j in cdar u collect
                for each k in j collect xsimp k;
        go to b;
    d:  y := matsm cadar u;
        if (n := length car y) neq length y
	  then rerror(matrix,4,"Non square matrix")
	 else if (z and n neq length z)
	  then rerror(matrix,5,"Matrix mismatch")
         else if cddar u then go to h
         else if null cdr y and null cdar y then go to e;
        x := subfg!*;
        subfg!* := nil;
        if null z then z := apply1(get('mat,'inversefn),y)
         else if null(x := get('mat,'lnrsolvefn))
          then z := multm(apply1(get('mat,'inversefn),y),z)
         else z := apply2(get('mat,'lnrsolvefn),y,z);
        subfg!* := x;
        z := for each j in z collect for each k in j collect
                 <<!*sub2 := t; subs2 k>>;
        go to c;
    e:  if null caaar y then rerror(matrix,6,"Zero divisor");
        y := revpr caar y;
        z := if null z then list list y else multsm(y,z);
        go to c;
     h: if null z then z := generateident n;
        go  to c;
    er: rerror(matrix,7,list("Matrix",car u,"not set"))
   end;

symbolic procedure matrixmap(u,v);
   if flagp(car u,'matmapfn)
    then matsm!*1 for each j in matsm cadr u collect
	    for each k in j collect simp!*(car u . mk!*sq k . cddr u)
   else if flagp(car u,'matfn) then reval2(u,v)
    else typerr(car u,"matrix operator");

put('matrix,'aggregatefn,'matrixmap);

flag('(int df taylor),'matmapfn);

flag('(det trace),'matfn);

endpatch;

patch poly;

% 6 Sep 04.

symbolic procedure fctrf u;
   (begin scalar !*ezgcd,!*gcd,denom,x,y;
      if domainp u then return list u
       else if ncmp!* and not noncomfp u then ncmp!* := nil;
      !*gcd := t;
      if null !*limitedfactors and null dmode!* then !*ezgcd := t;
      if null !*mcd
        then rerror(poly,15,"Factorization invalid with MCD off")
       else if null !*exp
        then <<!*exp := t; u := !*q2f resimp !*f2q u>>;
      if dmode!* eq '!:rn!:
	then <<dmode!* := nil; alglist!* := nil . nil;
	       x := simp prepf u;
	       if atom denr x then <<denom := denr x; u := numr x>>
		else denom := 1>>;
      if null ncmp!*
	then <<x := sf2ss u;
	       if homogp x
		 then <<if !*trfac
			then prin2t
		    "This polynomial is homogeneous - variables scaled";
			y := caaar x . listsum caaadr x;
			x := fctrf1 ss2sf(car(x)
				. (reverse subs0 cadr x . 1));
			x := rconst(y,x);
			return car x . sort!-factors cdr x>>>>;
      u := fctrf1 u;
      if denom
	then <<alglist!* := nil . nil;
	       dmode!* := '!:rn!:; car u := quotf!*(car u,denom)>>;
      return  car u . sort!-factors cdr u
   end) where !*exp = !*exp, ncmp!* = ncmp!*;

% 4 Oct 05.

symbolic procedure deg(u,kern);
   <<u := simp!* u; tstpolyarg2(u,kern); numrdeg(numr u,kern)>>
     where dmode!* = gdmode!*;

symbolic procedure tstpolyarg2(u,kern);
 <<for each j in kernels numr u do
      if j=kern then nil
       else if depends(j,kern) then typerr(prepsq u,"polynomial");
   for each j in kernels denr u do
      if depends(j,kern) then typerr(prepsq u,"polynomial")>>;

% 11 Jan 07.

symbolic procedure rnfactor!: u;
   begin scalar x,y,dmode!*; integer m,n;
     x := subf(u,nil);
     if not domainp denr x then return {1,(u . 1)};
     y := factorf numr x;
     n := car y;
     dmode!* := '!:rn!:;
     y := for each j in cdr y collect
           <<n := n*(m := (lnc ckrn car j)**cdr j);
             quotfd(car j,m) . cdr j>>;
     return int!-equiv!-chk mkrn(n,denr x) . y
   end;

endpatch;

patch rlfi;

put('tex,'simpfn,'simpcar);

endpatch;

% Solve declarations.

fluid '(!*cramer bareiss!-step!-size!*);

global '(assumptions);

patch solve;

% 26 Jun 04.

symbolic procedure solvelnrsys(exlis,varlis);
   begin scalar w,x;
   if w := solvesparsecheck(exlis,varlis) then exlis := w
     else exlis := exlis . varlis;
   if null !*cramer
      and null errorp(x :=
	   errorset2{'solvebareiss,mkquote car exlis, mkquote cdr exlis}
		      where bareiss!-step!-size!* = if w then 4 else 2)
     then exlis := car x
    else exlis := solvecramer(car exlis,cdr exlis);
   return solvesyspost(exlis,varlis)
   end;

% 12 Feb 05, 5 Oct 05.

symbolic procedure solvesq (ex,var,mul);
   begin scalar r,x;
      r:= for each w in solvesq1(ex,var,mul) join
	if null cadr w
	   or eqcar(x := prepsq caar w,'root_of)
	   or numr subfx(denr ex,{caadr w . x}) then {w};
      if r and not domainp denr ex then
	   assumptions:=append(assumptions,{prepf denr ex});
      return r
  end;

% 5 Oct 05.

symbolic procedure subfx(u,v);
   begin scalar x;
      x := errorset2 {'subf,mkquote u,mkquote v};
      return if errorp x then 1 ./ 1 else car x
   end;

% 12 Feb 05

symbolic procedure polypeval u;
   begin scalar bool,v;
      v := cadr u;
      u := simpcar u;
      if cdr u neq 1 then return nil else u := kernels car u;
      while u and null bool do
	<<if v neq car u and smember(v,car u) then bool := t;
	  u := cdr u>>;
      return null bool
   end;

put('polyp,'psopfn,'polypeval);

(algebraic <<

depend(!~p,!~x);

clearrules
{root_of(~p,~x,~tg)^~n =>
	sub(x=root_of(p,x,tg),
	    -reduct(p,x)/coeffn(p,x,deg(p,x)))^(n-deg(p,x)+1)
		when fixp n and deg(p,x)>=1 and n>=deg(p,x)};

let root_of(~p,~x,~tg)^~n =>
       sub(x=root_of(p,x,tg),
           -reduct(p,x)/coeffn(p,x,deg(p,x))) ^ (n-deg(p,x)+1)
	       when polyp(p,x) and fixp n and deg(p,x)>=1 and n>=deg(p,x);

nodepend(!~p,!~x);

>>) where dmode!*=nil,!*modular=nil,!*rounded=nil,!*complex=nil;

% 30 May 05.

symbolic procedure solvenonlnrtansolve(u,x,w);
  begin scalar v,s,z,r,y;
    integer ar;
   ar:=!!arbint;
   v:=caar u;u:=prepf numr simp cdr u;
   s:=solveeval{u,'tg!-};
   !!arbint:=ar;
   for each q in cdr s do
   <<z:=reval caddr q;
     z:=reval sublis(solvenonlnrtansolve1 z,z);
     !!arbint:=ar;
     y:=solve0({'equal,{'tan,{'quotient,V,2}},z},x); 
     r:=union(y,r)>>;
   y := errorset2 {'subf,mkquote w,mkquote{x . 'pi}};
   if null errorp y and null numr y
     then <<!!arbint:=ar; r:=union(solve0({'equal,{'cos,x},-1},x),r)>>;
   return t.r end;

% 5 Oct 05.

symbolic procedure check!-solns(z,ex,var);
   begin scalar x,y;
      if not errorp (x :=
	    errorset2 {'check!-solns1,mkquote z,mkquote ex,mkquote var})
	then return car x
       else if ex = (y := (numr simp!* prepf ex where !*reduced=t))
	  or errorp (x :=
	    errorset2 {'check!-solns1,mkquote z,mkquote y,mkquote var})
	then return 'unsolved
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
	 if null cadar z
	   or
	    errorp(y := errorset2 {'check!-solns2,mkquote ex,mkquote z})
	   then <<z := nil; x := 'unsolved>>
	  else if null(y := car y)
             or fv and null(y := numr subf(sx,list(caadar z .
                   mk!*sq subsq(caaar z,vs))))
	     or null numvalue y
           then <<x := car z . x; z := cdr z>>
          else z := cdr z;
      return if null x then 'unsolved else x
   end;

symbolic procedure check!-solns2(ex,z);
   if smemq('root_of,z) then rederr 'check!-solns
    else numr subf(ex,{caadar z . mk!*sq caaar z});

endpatch;

patch specfn;

% 20 Feb 06.

algebraic (for all u,m let df(Jacobidn(u,m),u)
	       = -m^2 *Jacobisn(u,m)*Jacobicn(u,m));

endpatch;

patch rlisp;

!#if (member 'psl lispsystem!*)
   symbolic procedure global idlist;
      fluid idlist;
   symbolic procedure global1 id1;
      if not get(id1,'vartype) then fluid1 id1;
!#endif

endpatch;


endmodule;

end;
