module tpscomp; % Compile prefix expression into network of
                % communicating power series.

% Authors: Julian Padget & Alan Barnes

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


% The compiler is rule driven by looking for a compilation rule (crule)
% property on the property list of the operator.  If a rule does not
% exist the expression is differentiated to get an expression which is
% amenable to compilation but the process takes care to check for the
% existence of cycles in the derivatives e.g. sine and cosine.
%
% The result is an power series object which can be evaluated by the
% power series evaluator.

%fluid '(unknowns !*exp knownps ps!:max!-order ps!:specials dfdx);
fluid '(unknowns !*exp  knownps ps!:max!-order ps!:specials
        ps!:level ps!:max!-level !*ratarg);

ps!:specials := list('psrev, 'pscomp, 'int);

symbolic (ps!:max!-level:= 20);

symbolic procedure ps!:compile(form,depvar,about);
  if idp form then
          make!-ps!-id(form,depvar,about)
   else  if ps!:numberp form then form
   else if ps!:p form then
      if (ps!:expansion!-point form=about) and (ps!:depvar form=depvar)
        then form
      else ps!:compile(ps!:value form,depvar,about)
   else if memq(rator form, ps!:specials) then
      apply(get(car form,'ps!:crule), list(form,depvar,about))
   else begin scalar spec_exp_fn, tmp, ispoly;
      % modified May 2021 to use a begin block to faciliate extensions
      tmp := prepsqxx simp!* list('df,ps!:arg!-values form, depvar);
      if tmp = 0 then <<
         tmp := (rator form).
	    (foreach arg in rands form collect
                if ps!:p arg then <<
                   ps!:find!-order arg;
               	   prepsq ps!:evaluate(arg,0)
		>>
                else subst(about,depvar,arg));
	 tmp := simp!* tmp;
	 if tmp = '(nil . 1) then
	    return 0
	 else
            return make!-constantps(tmp, form, depvar);
      >>;

      % optimisation to represent polynomials as a single complete ps.
      begin scalar !*ratarg := t;
        tmp := reval form;
	if about = 'ps!:inf then
	   tmp := reval subst(list('quotient, 1, depvar), depvar, tmp);
        tmp := cdr coeffeval list(tmp, depvar);
        ispoly := t;
        foreach c in tmp do
	     ispoly := (ispoly and null depends(c, depvar));
        if ispoly and about neq 0 and about neq 'ps!:inf then <<
           tmp := reval subst(list('plus, depvar, about), depvar, form);
           tmp := cdr coeffeval list(tmp, depvar);
        >>;
      end;
      if ispoly then return make!-poly!-ps(form, depvar, about, tmp);

      if get(car form,'ps!:crule) then
         return apply(get(car form,'ps!:crule),list(form,depvar,about));

      % To expand a special function when the default method fails
      % for example about a pole or when simplifcation of terms results
      % in (say) 0/0
      spec_exp_fn := get(car form, '!*specexp);
      if spec_exp_fn then <<
         % deal with possible special expansion and return it
	 % else return nil and continue with default method
         tmp := apply(spec_exp_fn, list(form, depvar, about)); 
         if tmp then return tmp;
      >>;
      tmp := assoc(form,knownps);
      if tmp then
         return '!:ps!:  .  cdr tmp
      else
         return ps!:unknown!-crule(
              (car form) . foreach arg in cdr form collect
                              ps!:compile(arg,depvar,about), depvar,about);
   end;


symbolic procedure make!-ps!-id(id,depvar,about);
begin scalar ps;
  ps:=make!-ps('full, id, depvar, about);
  if id=depvar then
      if about='ps!:inf then <<
         ps!:set!-order(ps, -1);
         ps!:set!-terms(ps, list (0 . (1 ./ 1)));
	 ps!:set!-last!-term(ps,-1);>>
      else <<
         about :=  if idp about then !*k2q about
                   else if ps!:numberp about then !*n2f about ./ 1
                   else simp!* about;
         if numr about then <<
            ps!:set!-order(ps, 0);
            ps!:set!-terms(ps, list(0 . about, 1 . (1 ./ 1)));
	    ps!:set!-last!-term(ps,1);
	 >>
         else <<
            ps!:set!-order(ps, 1);
            ps!:set!-terms(ps, list(0 . (1 ./ 1)));
	    ps!:set!-last!-term(ps,1);>>
       >>
  else <<
     ps!:set!-order(ps, 0);
     ps!:set!-terms(ps, list(0 .  !*k2q id));
     ps!:set!-last!-term(ps,0);
  >>;
  return ps
end;

symbolic procedure make!-constantps(u,v,d);
% u is a constant standard quotient, v is a corresponding prefix form
begin scalar ps;
      if u = '(nil . 1) then return u;	
      ps:=get('tps,'tag) . mkvect 7;
      ps!:set!-order(ps,0);
      ps!:set!-expression(ps, 'full);
      ps!:set!-value(ps, v);
      ps!:set!-last!-term(ps,0);
      ps!:set!-terms(ps,list(0 . u));
      ps!:set!-depvar(ps,d);
      putv(cdr ps, 7, !*sqvar!*);
      return ps
end;

symbolic procedure make!-ps(form,exp,depvar,about);
begin scalar ps;
      ps:=get('tps,'tag) . mkvect 7;
      ps!:set!-order(ps,0);
      ps!:set!-expression(ps,form);
      ps!:set!-value(ps,exp);
      ps!:set!-depvar(ps,depvar);
      ps!:set!-expansion!-point(ps,about);
      ps!:set!-last!-term(ps,-1);
      putv(cdr ps, 7, !*sqvar!*);
      return ps;
end;

symbolic procedure make!-poly!-ps(form,depvar,about, coefflist);
begin scalar ps, ordsetp, len;
      ps:=get('tps,'tag) . mkvect 7;
      ps!:set!-expression(ps, 'full);
      ps!:set!-value(ps,form);
      ps!:set!-depvar(ps,depvar);
      ps!:set!-expansion!-point(ps,about);
      ps!:set!-last!-term(ps, -1);
      len := length(coefflist)-1;
      for n := 0:len do <<
         if car coefflist neq 0 then <<
            if not ordsetp then <<
               ps!:set!-order(ps, n);
 	       ordsetp := t;
  	    >>;
            ps!:set!-term(ps, n, simp!* car coefflist);
	 >>;
         coefflist := cdr coefflist;
      >>;
      putv(cdr ps, 7, !*sqvar!*);
      return ps;
end;

symbolic procedure ps!:plus!-crule(a,d,n);
begin scalar pluses, minuses;
   foreach term in rands a do
      if pairp term and rator term = 'minus  then
           minuses := rand1 term . minuses
      else
           pluses := term . pluses;

   if not null pluses then <<
     if not null cdr pluses then
        pluses := make!-ps('plus . foreach term in pluses collect
                                      ps!:compile(term,d,n),
                           ps!:arg!-values('plus . pluses),d,n)
     else
        pluses := ps!:compile(car pluses,d,n);
     ps!:find!-order pluses>>;

   if not null minuses then <<
     if not null cdr minuses then
        minuses := make!-ps('plus . foreach term in minuses collect
                                      ps!:compile(term,d,n),
                            ps!:arg!-values('plus . minuses),d,n)
     else
        minuses := ps!:compile(car minuses,d,n);
     ps!:find!-order minuses>>;

   if null minuses then
       return pluses
   else if null pluses then
       a:= (make!-ps(ps, ps!:arg!-values ps,d,n)
               where ps = 'minus . list minuses)
   else a:= (make!-ps(ps, ps!:arg!-values ps, d,n)
               where ps = 'difference . list(pluses, minuses));
   ps!:find!-order a;
   return a;
end;

put('plus,'ps!:crule,'ps!:plus!-crule);

symbolic procedure ps!:unary!-crule(a,d,n);
   make!-ps(list(rator a,ps!:compile(rand1 a,d,n)),
                 ps!:arg!-values a,d,n);

symbolic procedure ps!:minus!-crule(a,d,n);
 if ps!:numberp cadr a then
    !:minus cadr a
 else  ps!:unary!-crule(a,d,n);

put('minus,'ps!:crule, 'ps!:minus!-crule);
put('sqrt,'ps!:crule,'ps!:unary!-crule);
put('cbrt,'ps!:crule,'ps!:unary!-crule);

symbolic procedure ps!:binary!-crule(a,d,n);
<<a :=  make!-ps((rator a) . list(ps!:compile(rand1 a,d,n),
                                                          ps!:compile(rand2 a,d,n)),
                      ps!:arg!-values a,d,n);
  ps!:find!-order a;
  a>>;

put('difference,'ps!:crule,'ps!:binary!-crule);

symbolic procedure ps!:nary!-crule(a,d,n);
% called from ps!:times!-crule so args are already power series
<<if null cdddr a then
     a := make!-ps(list(rator a,rand1 a,rand2 a), ps!:arg!-values a,d,n)
  else
     a:= make!-ps(list(rator a,rand1 a,
                       ps!:nary!-crule((rator a) . cddr a,d,n)),
                   ps!:arg!-values a,d,n);
  ps!:find!-order a;
  a>>;


symbolic procedure ps!:times!-crule(a,d,n);
begin scalar prod, variables, constants;
   prod := foreach arg in rands a collect ps!:compile(arg,d,n);
   foreach arg in prod do
      if ps!:numberp arg or
         (not idp cdr arg and ps!:expression arg = 'psconstant) then
           constants := arg . constants
      else variables := arg . variables;
   if not null variables then
      if null cdr variables then
         variables := car variables
      else variables := ps!:nary!-crule('times . variables, d, n);
   if null constants then
      return variables
   else <<
      prod := 1 ./  1;
      foreach arg in constants do
          prod := multsq(prod, if ps!:numberp arg then
                                                     (if arg=0 then nil else arg) ./ 1
                               else ps!:get!-term(arg,0));
      if variables then
         a:= make!-ps(list('psmult, prod, variables),
                      ps!:arg!-values a,d,n)
      else
         return make!-constantps(prod, ps!:arg!-values a, d);
      ps!:find!-order a;
      return a>>;
end;

put('times,'ps!:crule,'ps!:times!-crule);
put('quotient,'ps!:crule,'ps!:quotient!-crule);

symbolic procedure ps!:quotient!-crule(a,d,n);
% forms such as (quotient (expt <x> <y>) (expt <x> <z>)) are
% detected here and transformed into (expt <x>(difference <y> <z>)) to
% help avoid certain essential singularities
begin scalar r1, r2;
  r1 := rand1 a; r2 := rand2 a;
  if eqcar(r1,'expt) and eqcar(r2,'expt) and
        ((rand1 r1)=(rand1 r2)) then
    return ps!:compile(list('expt, rand1 r1,
                            list('difference, rand2 r1, rand2 r2)),
                        d,n);
    r1:=ps!:compile(rand1 a, d, n);
    if (ps!:numberp r1 or
        (not idp cdr r1 and ps!:expression r1 = 'psconstant))
           and eqcar(r2, 'expt) then
     << r2:=ps!:compile(list('expt,rand1 r2,prepsqxx simpminus cddr r2),
                         d,n);
      return
             if onep r1 then r2
        else <<
           a := make!-ps(list('psmult, if ps!:numberp r1 then r1 ./ 1
                                       else ps!:get!-term(r1,0),
                               r2),
                         ps!:arg!-values a,d,n);
           ps!:find!-order a;
             a>>
      >>;
    r2:=ps!:compile(rand2 a, d, n);

    if ps!:numberp r2 or
         (not idp cdr r2 and ps!:expression r2 = 'psconstant) then
      << r2 := if ps!:numberp r2 then 1 ./ r2
               else invsq ps!:get!-term(r2,0);
         a:= make!-ps(list('psmult, r2, r1), ps!:arg!-values a,d,n)>>
    else
         a:= make!-ps(list('quotient, r1, r2), ps!:arg!-values a,d,n);
    ps!:find!-order a;
    return a;
end;

symbolic procedure ps!:int!-crule(a,d,n);
begin scalar r,arg1, psord, intvar, x;
  intvar := rand2 a;
  if not idp intvar then
    typerr(intvar, "kernel: ps!:int!-crule");
  if depends(n, intvar) then
    << r := ps!:compile(rand1 a,d,n);     	  
       x := prepsqxx simp {'int, ps!:value r, intvar};
       if depends(x,'int) then
         rerror(tps,11,
           "Can't integrate this series (expansion pt depends on integration variable)")
        else
           return ps!:compile(x,d,n);
    >>;
  arg1:=ps!:compile(prepsqxx simp!* rand1 a,d,n);
  r:= make!-ps(list('int,arg1,intvar), ps!:arg!-values a,d,n);
  psord:= ps!:find!-order arg1;
  if d=intvar then
     if ps!:expansion!-point(arg1) neq 'ps!:inf then
       <<if (psord < 0) and (ps!:evaluate(arg1,-1) neq (nil ./ 1)) then
           rerror(tps,12,"Logarithmic Singularity")>>
     else  % expansion about infinity
         if (psord < 2) and (ps!:evaluate(arg1,1) neq (nil ./ 1)) then
           rerror(tps,13,"Logarithmic Singularity at Infinity");
  ps!:find!-order r;
  return r;
end;

put('int,'ps!:crule,'ps!:int!-crule);

symbolic procedure ps!:log!-crule(a,d,n);
begin scalar r, dfdx, f;
  f := ps!:compile(rand1 a, d, n);
  if ps!:order f neq 0 then
        rerror(tps,14, "Logarithmic Singularity");
  dfdx := ps!:compile(prepsq simp!* list('df, f, d), d, n);
  r := ps!:compile(list('quotient, dfdx, f), d, n);
  r := make!-ps(list('int, r, d), ps!:arg!-values a, d, n);
  ps!:set!-term(r,0, simp!* list('log, prepsq ps!:get!-term(f,0)));
  ps!:find!-order r;
  return r;
end;

put('log,'ps!:crule, 'ps!:log!-crule);

symbolic procedure ps!:arg!-values funct;
  (rator funct) . (foreach arg in rands funct collect
                     if ps!:atom arg then arg
                     else if ps!:p arg then ps!:value arg
                     else ps!:arg!-values arg);

symbolic procedure ps!:unknown!-crule(a,d,n);
% unknowns is an alist structure, the CAR of which is the
% form which was differentiated and the CDR is a dotted pair whose
% CDR is a gensym'ed identifier which is used to build
% the cyclic structures used to represent a recurrence relation.

   (lambda (aval,tmp);
     if (tmp:=assoc(aval, unknowns)) then  '!:ps!: . cdr tmp
     else if ps!:level > ps!:max!-level then
             rerror(tps,15, "Recursion too deep in ps!:unknown!-crule")
     else
        (lambda(dfdx, unknowns);
           (lambda(r, s); <<
              ps!:level:=ps!:level+1;
              %intern s;  %  not needed, but useful for debugging.
              global list s;  % This is definitely needed in UOLISP.
% it is important to set s before recursing to find the power series
% expansion of dfdx as this may involve evaluating s
              set(s,cdr r);
% it is also important to determine the first non-zero term of the
% series (assumed to be of order >= 0) before recursing in case
% the original series is encountered again in the recursion
              ps!:unknown!-term1(r, a);
              dfdx := ps!:compile(dfdx,d,n);
% the next test is intended to detect the case when a function f(x)
% (say) is expanded about a point x=a (say) at which f has a pole or
% essential singuarity, but where the Reduce simplifier returns a
% seemingly well-defined value for f when x=a.
              if ps!:order dfdx < 0 then
                 rerror(tps, 16, "Pole or Logarithmic Singularity");
              ps!:set!-expression(r,list('int, dfdx, d));
              knownps:=(aval . s) . knownps;
              ps!:level:=ps!:level-1;
             r
            >> )
            (make!-ps(nil,aval,d,n), cdar unknowns))
            (ps!:differentiate(a,d), (aval . gensym()) . unknowns)
   )
    (ps!:arg!-values a,nil);

symbolic procedure ps!:unknown!-term1(ps,a);
% There is an implicit assumption that the order of the series >=0 here
begin scalar psord, term, about, infmult, x;
   psord := 0;
   about := ps!:expansion!-point ps;
   x := ps!:depvar ps;
loop:
   term := simp!* ps!:first!-term a;
   ps!:set!-term(ps, psord, term);
   if numr term = nil then <<
      psord := psord+1;
      if psord > ps!:max!-order then
         rerror('tps, 17, list(ps!:value ps,
                                            "has zero expansion to order",
                                psord));
      a := list('quotient, list('df, a, x), psord);
      if about = 'ps!:inf then <<
         if psord = 1 then
            infmult := ps!:compile(list('minus, list('times, x, x)),
                                   x, about);
         a := list('times, infmult, a)>>;
      a := prepsqxx simp!* a;
      go loop>>;
end;

symbolic procedure ps!:first!-term(l);
  if atom l then  l
  else if ps!:p l then
     if ps!:find!-order l < 0 then
          rederr "Possible essential singularity"
     else prepsqxx ps!:get!-term(l,0)
  else
    car l . foreach arg in cdr l collect ps!:first!-term arg;

symbolic procedure ps!:differentiate(a,v);
   (lambda x;
      if eqcar(x,'df) then
         rerror(tps,18,
           list("ps:differentiate: no rule to differentiate function",
                 car a, "when it has", length a - 1, "arguments"))
      else
         x)
   ((lambda (!*exp);
        prepsqxx simp!* list ('df, a, v)) nil);


symbolic procedure ps!:expt!-crule(a,d,n);
% we will assume that forms like (expt (expt <x> <y>) <z>) will
% continue to be transformed by SIMP!* into (expt <x> (times <y> <z>))
% this is very important for the avoidance of essential singularities
%
% If the exponent is equivalent to a rational number there is a
% convenient algorithm for exponentiation. So use it, otherwise
% use a^b = exp(b*log a) and use the algorithm for exp(power-series)
%
begin scalar eflg,exp1,exp2,b,psvalue;
   b := rand1 a;
   if not ps!:p b or constantpsp b then
      eflg := evalequal(b,prepsq simp!* aeval 'e);
   exp1:=rand2 a;
   if (ps!:p exp1 and constantpsp exp1) then exp1:=ps!:value exp1;
   begin scalar alglist!*, dmode!*;
        exp2:=simp!* exp1;
   end;
   psvalue:=ps!:arg!-values a;
   if (atom numr exp2 and atom denr exp2) then
        <<exp1:=numr exp2; exp2:=denr exp2>>
   else return
     << exp2 := ps!:compile(if eflg then exp1
                            else list('times, exp1, list('log,b)), d,n);
        make!-ps(list('exp, exp2), psvalue, d, n)>>;
   b := ps!:compile(b,d,n);
   if exp2=1 then
      if exp1=nil then
         return if ps!:zerop!: b
                then rerror(tps,19,"0**0 formed: ps:expt-crule")
                else 1
      else if exp1=1 then return b
      else if exp1=2 then
         a := make!-ps(list('times,b,b),psvalue,d,n)
      else if exp1 = -1 then
         a:= make!-ps(list('quotient,1,b),psvalue,d,n)
      else a := make!-ps(list('expt,b,exp1,1),psvalue,d,n)
   else a := make!-ps(list('expt,b,exp1,exp2),psvalue,d,n);
   ps!:find!-order a;
   return a;
end;

put('expt,'ps!:crule,'ps!:expt!-crule);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Added by Alan Barnes, 2021 to cater for expansion about a pole of
% trigonmetric and hyperbolic functions

foreach fn in '(csc cot sec tan csch coth sech tanh) do
   put(fn, '!*specexp, 'trig!-hyp!-polefn);

symbolic procedure trig!-hyp!-polefn(form, depvar, exppt);
  % returns nil if there is no pole at the expansion point
  % otherwise returns the power series of 1/reciprocal function.
begin scalar arg1, tmp, f, fp, p, r;
   arg1 := subst(exppt, depvar, cadr form);
   f := car form;
   if (f = 'csc) or (f = 'cot) or (f = 'csch) or (f = 'coth) then
      if (f = 'csc) or (f = 'cot) then <<
         fp := 0;
         p := 'pi;
         if f = 'cot then
	    r := 'tan
	 else
	    r := 'sin;
      >>
      else <<
         fp := 0;
         p := '(times i pi);
	 if f = 'csch then
	    r := 'sinh
	 else
	    r := 'tanh;
      >>
   else if (f = 'sec) or (f = 'tan) then <<
           fp := '(quotient pi 2);
           p := 'pi;
	   if f = 'sec then
	       r := 'cos
	   else
	       r := 'cot;	   
        >>
   else if (f = 'sech) or (f = 'tanh) then <<
           fp := '(times i (quotient pi 2));
           p := '(times i pi);
  	   if f = 'sech then
	      r := 'cosh
	   else
	      r := 'coth;	   
        >>;
	
   tmp := reval list('quotient,list('difference, arg1, fp), p);
   if fixp tmp then <<
      tmp:= ps!:compile(list('quotient, 1, r . cdr form), depvar, exppt);
      ps!:set!-value(tmp, car(form) . cdr ps!:value(cadr ps!:operands tmp));
      return tmp;
   >>
   else
      return nil;
end;

% This caters for expansion of the Jacobi elliptic functions about a pole.
% It fails if the expansion is about modulus k=0 or k=1. 
% Added by Alan Barnes 2021.

symbolic procedure jacobi!-expansionfn(form, depvar, exppt);
  % returns nil if there is no pole at the expansion point
  % otherwise returns the power series of 1/reciprocal function.
begin scalar arg1, arg2, tmp, f, m, n, r;
   arg1 := subst(exppt, depvar, rand1 form);
   arg2 := rand2 form;
   f := rator form;
   if depends(arg2, depvar) then <<
      arg2 :=  reval subst(exppt, depvar, arg2);
      if arg2 = 0 or arg2 = 1 or arg2 = -1 then
	 rederr("Expansion of Jacobi elliptic functions not supported about unit or zero modulus")
      else % try default method  -- may work or collapse in a heap
         return nil;
   >>;
   begin scalar !*ratarg := t;
      tmp := reval arg1;
      tmp := cdr coeffeval list(tmp, list('ellipticK, arg2));
   end;

   if length tmp > 1 then m := cadr tmp else m := 0;
   n := reval list('quotient, list('times, 'i, car tmp),
                              list('ellipticK!', arg2));
   if not(length tmp <= 2 and fixp m and fixp n) then return nil;  

   if (f = 'jacobisn) or (f = 'jacobicn) or (f = 'jacobidn) then
      <<if not evenp m or evenp n then return nil>>
   else if (f = 'jacobidc) or (f = 'jacobinc) or (f = 'jacobisc) then
      <<if  evenp m or not evenp n then return nil>>
   else if (f = 'jacobicd) or (f = 'jacobisd) or (f = 'jacobind) then
      <<if  evenp m or evenp n then return nil>>
   else if  not evenp m or not evenp n then return nil;

   r := get(f, 'recipfn);
   tmp := ps!:compile(list('quotient, 1, r . cdr form), depvar, exppt);
   ps!:set!-value(tmp, car(form) . cdr ps!:value(cadr ps!:operands tmp));
   return tmp;
end;

deflist('((jacobisn jacobins) (jacobicn jacobinc) (jacobidn jacobind)
          (jacobins jacobisn) (jacobinc jacobicn) (jacobind jacobidn)
          (jacobisc jacobics) (jacobisd jacobids) (jacobics jacobisc)
	  (jacobicd jacobidc) (jacobids jacobisd) (jacobidc jacobicd)
	  ), 'recipfn);

foreach fn in '(jacobisn jacobicn jacobidn jacobins jacobinc jacobind
                jacobisc jacobisd jacobics jacobicd jacobids jacobidc) do
   put(fn, '!*specexp, 'jacobi!-expansionfn);

% Added by Alan Barnes Summer 2021 to allow expansion of Weierstrassian
% elliptic functions including about their poles

symbolic procedure weier!-specexpfn(form, depvar, exppt);
begin scalar arg1, arg2, arg3, tmp, tmp1, f, m, n, r;
   arg1 := subst(exppt, depvar, rand1 form);
   arg2 := rand2 form;
   arg3 := cadddr form;
   f := rator form;
   if depends(arg2, depvar) or depends(arg3, depvar) then
   % can't handle this case yet, so give up.
    rederr("Expansion not supported if arg 2 or 3 depends on expansion variable");

   if f = 'weierstrass1 or f = 'weierstrassZeta1 then <<
      tmp := list('lattice_omega1, arg2, arg3);
      arg3 := list('lattice_omega3, arg2, arg3);
      arg2 := tmp;
   >>;
   
   begin scalar !*ratarg :=t;
      tmp := reval arg1;
      tmp := cdr coeffeval list(tmp, arg2);
   end;

   if length tmp > 1 then m := cadr tmp else m := 0;
   n := reval list('quotient, reval car tmp, arg3);
   if not(length tmp <= 2 and fixp m and fixp n and evenp m and evenp n) then
     % at a regular point
     return simppstay2(form, depvar, exppt, nil);
     
   if f = 'weierstrass or f = 'weierstrassZeta then r := 'RW!*   
   else r := 'RW1!*;

   % Using the standard tps expansion here gives the wrong result,
   % we must use taylor expansion ??!! The standard method seems OK
   % for regular points, but taylor expansion used as a precaution above
   
   tmp := simppstay2(r . cdr form, depvar, exppt, nil);
   tmp := ps!:quotient!-crule(list('quotient, 1, tmp), depvar, exppt);
   tmp1 := cdr ps!:value(cadr ps!:operands tmp);
   if f = 'weierstrassZeta or f = 'weierstrassZeta1 then <<
       tmp := ps!:int!-crule(list('int, tmp, depvar), depvar, exppt);
       tmp := reval (list
	          ('difference,
	              list('plus, list('times, m, list('eta1, arg2, arg3)),
 	                          list('times, n, list('eta3, arg2, arg3))),
		      tmp));
        tmp := ps!:compile(tmp, depvar, exppt);
   >>;
   ps!:set!-value(tmp, car(form) . tmp1);
   return tmp;
end;

put('weierstrass, '!*specexp, 'weier!-specexpfn);
put('weierstrass1, '!*specexp, 'weier!-specexpfn);
put('weierstrassZeta, '!*specexp, 'weier!-specexpfn);
put('weierstrassZeta1, '!*specexp, 'weier!-specexpfn);

% Added by Alan Barnes, October 2021, to allow the Legendre elliptic integrals
% to be expanded as a series in the modulus about k=0.
% The default method works for other values of k (except k=1) and for
% expansion of the incomplete integrals as series in their first argument.

% This function and jacobiinv!-modulus-exp involve use of a new operator
% def!-int which denotes a definite integral whose 1st arg is an indefinite
% integral (a power series). The 2nd and 3rd args are the lower and upper
% integration limits.
% The corresponding erule in tpseval.red evaluates the terms of the series
% for the indefinite integral at the two limits and subtracts them.

symbolic procedure ellipi!-modulus!-exp(form, depvar, about);
begin scalar arg, tmp;
   
   if length form = 2 then
      tmp := rand1 form
   else 
      tmp := rand2 form;
   if not depends(tmp, depvar) then return nil;
   
   arg :=  reval subst(about, depvar, tmp);
   if arg neq 0 and arg neq 1 then
      if length form = 2 then
         % let ps!:unknown!-crule try
         return nil
      else
 	 rederr("Expansion of incomplete elliptic integrals only supported about zero modulus");

   if arg = 1 then
      rederr("Expansion of elliptic integrals about modulus k=1 not supported");

   if rator form = 'ellipticE then 
      tmp := {'expt, {'plus, 1,
	                     {'minus, {'times, {'expt, {'sin, '!*!*x}, 2},
	                                       {'expt, tmp, 2}}}},
 	             {'quotient, 1, 2}}
   else if (rator form = 'ellipticF) or (rator form = 'ellipticK) then
      tmp := {'expt, {'plus, 1,
	                     {'minus, {'times, {'expt, {'sin, '!*!*x}, 2},
	                                       {'expt, tmp, 2}}}},
	             {'quotient, -1, 2}};

   tmp := ps!:compile({'int, tmp, '!*!*x}, depvar, about);
   ps!:set!-value(tmp, form);

   if length form = 2 then
      arg := {'quotient, 'pi, 2} % ellipticK or unary ellipticE
   else
      arg := rand1 form;   % binary ellipticE or ellipticF

   return make!-ps({'def!-int, tmp, 0, arg}, form, depvar, about);
end;

put('ellipticK, '!*specexp, 'ellipi!-modulus!-exp);
put('ellipticF, '!*specexp, 'ellipi!-modulus!-exp);
put('ellipticE, '!*specexp, 'ellipi!-modulus!-exp);

% Added by Alan Barnes, October 2021, to allow the inverse Jacobi elliptic
% functions to be expanded as a series in the modulus k about k=0.
% Other values of k are not yet supported.
% All are in fact elliptic integrals of the first kind.
% The default method works for expansion as series in their first argument.

foreach fn in '(arcsn arccn arcdn arcns arcnc arcnd
                arcsc arcsd arccs arccd arcds arcdc) do
   put(fn, '!*specexp, 'jacobiinv!-modulus!-exp);

symbolic procedure jacobiinv!-modulus!-exp(form, depvar, about);
begin scalar arg, tmp;
   
   if length form = 2 then
      tmp := rand1 form
   else 
      tmp := rand2 form;
   if not depends(tmp, depvar) then return nil;
   
   arg :=  reval subst(about, depvar, tmp);
   if arg neq 0 then
       rederr("Expansion of inverse Jacobi functions only supported about modulus k=0");



   if (rator form = 'arcsn) or (rator form = 'arcns) then
      tmp := {'expt, {'plus, 1,
	                     {'minus, {'times, {'expt, {'sin, '!*!*x}, 2},
	                                       {'expt, tmp, 2}}}},
	             {'quotient, -1, 2}}
   else if (rator form = 'arccn) or (rator form = 'arcnc) then
      tmp :=  {'expt, {'plus, {'plus, 1, {'minus, {'expt, tmp, 2}},
	                      {'times, {'expt, {'cos, '!*!*x}, 2},
	                                       {'expt, tmp, 2}}}},
	             {'quotient, -1, 2}}
   else if (rator form = 'arcdn) or (rator form = 'arcnd) then
%      tmp := {'expt, {'plus, {'plus, {'expt, {'cos, '!*!*x}, 2},
%                                     {'expt, tmp, 2}}, {'minus, 1}},
%	             {'quotient, -1, 2}}
      rederr("arcdn and arcnd not defined for zero modulus")			
   else if (rator form = 'arccd) or (rator form = 'arcdc) then
      tmp := {'expt, {'plus, 1,
	                     {'minus, {'times, {'expt, {'cos, '!*!*x}, 2},
	                                       {'expt, tmp, 2}}}},
	             {'quotient, -1, 2}}
   else if (rator form = 'arcsc) or (rator form = 'arccs) then
      tmp := {'expt, {'times, {'plus, 1, {'expt, '!*!*x, 2}},
 	                      {'plus, {'plus, 1, {'expt, '!*!*x, 2}},
	                              {'minus, {'times, {'expt, '!*!*x, 2},
	                                                {'expt, tmp, 2}}}}},
	             {'quotient, -1, 2}}
   else if (rator form = 'arcsd) or (rator form = 'arcds) then
     tmp := {'expt, {'times, {'plus, 1, {'times, {'expt, '!*!*x, 2}, 
	                                         {'expt, tmp, 2}}},
	                     {'plus, {'plus, 1, {'times, {'expt, '!*!*x, 2}, 
	                                                 {'expt, tmp, 2}}},
			             {'minus, {'expt, '!*!*x, 2}}}}, 
	             {'quotient, -1, 2}};

   tmp := ps!:compile({'int, tmp, '!*!*x}, depvar, about);
   ps!:set!-value(tmp, form);

   arg :=
     if rator form = 'arcsn then {'asin, rand1 form}
     else if rator form = 'arcns then {'asin, {'quotient, 1, rand1 form}}
     else if (rator form = 'arccn) or (rator form = 'arccd)
                                 then {'acos, rand1 form}
     else if (rator form = 'arcnc) or (rator form = 'arcdc)
                                 then {'acos, {'quotient, 1, rand1 form}}
     else if (rator form = 'arcds) or (rator form = 'arccs)
                                 then {'quotient, 1, rand1 form}
     else rand1 form;   %  arcsd or arcsc

   return make!-ps({'def!-int, tmp, 0, arg}, form, depvar, about);
end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Added by Alan Barnes.  November 2015
% Produces an extendible Taylor series using the classic method.
%
%   pstaylor(<function, <depvar>, <about>);
%
%     <function>  the function to be expanded         (algebraic)
%     <depvar>    expansion variable of series        (a kernel)
%     <about>     expansion point of series           (algebraic)



symbolic procedure simppstay a;
  if length a = 3 then apply('simppstay1, a)
  else rerror(tps,5,
          "Args should be <FORM>,<depvar>, and <point>:  simppstay");

put('pstaylor, 'simpfn, 'simppstay);

symbolic procedure simppstay1(form, depvar, about);
  if form=nil then
     rerror(tps,6,"Args should be <FORM>,<depvar>, and <point>: simppstay")
  else if not kernp simp!* depvar then
     typerr(depvar, "kernel:  simppstay")
  else if  smember(depvar,(about:=prepsqxx simp!* about)) then
     rerror(tps,7,"Expansion point depends on dependent variable:  simppstay")
  else simppstay2(ps!:presimp form, depvar, 
                  if about='infinity then 'ps!:inf else about, nil) ./ 1;


symbolic procedure simppstay2(form, depvar, about, gammaflg);
% gammaflg is a boolean argument which causes psi_rules to be turned off
% during the evaluation of derivatives of the gamma function & friends 

   if idp form then make!-ps!-id(form,depvar,about)
   else if ps!:numberp form then form
   else if ps!:p form then
       if (ps!:expansion!-point form=about) and (ps!:depvar form=depvar)
       then form 
       else simppstay2(ps!:value form, depvar, about, gammaflg)
   else begin scalar ps, deriv, psord, term, ept, evar;
       psord := 0;
       if about = 'ps!:inf then 
          << evar := gensym(); ept := 0; 
       	     if gammaflg then rule!-list('(psi_rules), nil);
             deriv :=
                prepsq simp subst(list('quotient, 1, evar), depvar, form);
       	     if gammaflg then rule!-list('(psi_rules), t)>>
       else 
          << deriv := form; ept := about; evar := depvar>>;
       if gammaflg then rule!-list('(psi_rules), t);
       term := simp subst(ept, evar, deriv);
       while numr term = nil and deriv neq 0 do <<
          psord := psord + 1;
     	  if gammaflg then rule!-list('(psi_rules), nil);
          deriv := prepsq simp
                        list('quotient, list('df, deriv, evar), psord);
     	  if gammaflg then rule!-list('(psi_rules), t);
          term := simp subst(ept, evar, deriv);
       >>;
       if deriv=0 then return nil;
       ps := make!-ps(list(if gammaflg then 'ps!:gamma else 'ps!:taylor, 
                           evar, ept, deriv), 
                      form, depvar, about);
       ps!:set!-order(ps, psord);
       ps!:set!-term(ps, psord, term);
       return ps
       end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compilation rules for the gamma function & friends.
% Written by Alan Barnes November 2015

symbolic procedure ps!:gamma!-crule(a,d,n);
% For generic expansion points we use classic Taylor expansion 
% via simppstay2.
% For expansion of Gamma about zero we use the shift formula
%    Gamma(z) = Gamma(z+1)/z
% For expansion of psi about zero we use the shift formula
%    psi(z) = psi(z+1) - 1/z
% For expansion about a negative integer we use the shift formula
% repeatedly and then recurse via ps!:compile and simppstay2.
%
if n = 'ps!:inf then
     rerror(tps,106,
            "Expansion of gamma functions about infinity not yet supported.")
else begin scalar op, arg, exppt, res, fn, gam;
  op := rator a; arg := rand1 a;
  fn := if ps!:p arg then ps!:value arg 
        else if pairp arg then ps!:arg!-values arg 
        else arg;
  exppt := reval subst(n, d, fn);

  if not fixp exppt or exppt>0 then 
    return  simppstay2(list(op, fn), d, n, t)  
  else << 
     gam := simppstay2(list(op, reval list('plus, fn, 1-exppt)), d, n, t);
     arg := if ps!:p arg then arg else ps!:compile(arg,d,n);
     if op = 'gamma then <<
	res := ps!:compile(list('quotient, gam, arg),d,n);
        for i:=1:-exppt do 
          res :=ps!:compile(list('quotient, res, list('plus, arg, i)), d, n)>>
     else << res := for i:=1:-exppt collect 
	        ps!:compile(list('quotient, 1, list('plus, arg, i)), d, n);
	     res := ps!:compile(list('quotient, 1, arg), d, n) . res;
             res := if exppt=0 then car res else 'plus . res;
             res := ps!:compile(list('difference, gam, res), d, n)>>
  >>;
  ps!:set!-value(res, ps!:arg!-values a);
  return res;
end;

symbolic procedure ps!:polygamma!-crule(a,d,n);
% For generic expansion points we use classic Taylor expansion 
% via simppstay2.
% For polygamma about zero the shift formula 
%      polygamma(n, z) := polygamma(n, z+1)+ n!/(-z)^(n+1)
% is used. For non-positive integer expansion points 
% repeated use of the shift formula is used.
%
if n = 'ps!:inf then
   rerror(tps,107,
          "Expansion of polygamma function about infinity not yet supported.")
else
begin scalar exppt, ord, arg, fn, gam, res, fac;
  ord := reval rand1 a;
  if not fixp ord or ord <0 then
    rerror(tps,108,
           "First argument of polygamma must be a non-negative integer.");
  arg := rand2 a;
  fn := if ps!:p arg then ps!:value arg 
        else if pairp arg then ps!:arg!-values arg 
        else arg;
  exppt := reval subst(n,d,fn);

  if not fixp exppt or exppt>0 then return
     simppstay2(list('polygamma, ord, fn), d, n, t)  
  else << 
     gam := simppstay2(list('polygamma, ord, reval list('plus, fn, 1-exppt)), 
                       d, n, t);
     arg := ps!:compile(list('minus, arg), d, n);
     fac := factorial ord;
     ord := -(ord+1);
     res := for i:=1:-exppt collect 
	      ps!:compile(list('times, fac, 
                               list('expt, list('plus, arg, -i), ord)), d, n);
     res := ps!:compile(list('times, fac, list('expt, arg, ord)), d, n) . res;
     res := ps!:compile('plus .  (gam . res), d, n);
     ps!:set!-value(res, ps!:arg!-values a);
     return res
  >>;
end;

put('gamma,'ps!:crule,'ps!:gamma!-crule);
put('psi,'ps!:crule,'ps!:gamma!-crule);
put('polygamma,'ps!:crule,'ps!:polygamma!-crule);

endmodule;

end;
