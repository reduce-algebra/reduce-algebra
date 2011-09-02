module fps;     % a package for the algorithmic calculation
                % of Formal Power Series

% Author : Wolfram Koepf, ZIB Berlin

% REDUCE version by: Winfried Neun, ZIB Berlin.
%     (September 1994)

%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%                           Konrad-Zuse-Zentrum                  %
%                              fuer Informationstechnik Berlin,  %
%                           Heilbronner Str. 10                  %
%                           10711 Berlin - Wilmersdorf           %
%                           Federal Republic of Germany          %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %

create!-package ('(fps simplede substexp linrec hgrsolve constre
                        ratalgo),
                 '(contrib specfn));

load_package misc;   % For limits.

load_package factor,specfn;

fluid '(ps!:order!-limit);

lisp(ps!:order!-limit := 30);

algebraic << factor factorial >>;

endmodule;


module simplede;

fluid '(fps_search_depth !*protfg ps!:order!-limit);

global '(inconsistent!*);

share fps_search_depth;

fps_search_depth := 5; %the default

switch tracefps;

algebraic <<  operator ba; operator infsum ;
                array dff(50) >>;

put('simplede,'psopfn,'simpledeeval);

symbolic procedure simpledeeval(u);
   begin scalar res,usevar;
     if length u = 2 then
        << usevar := 'y;
           res := int_simplede(car u,cadr u);
           if eq(res,-1) then return simpledeexit(car u,cadr u,'y);
        >>
        else if length u = 3 then
                << usevar := caddr u;
                res := int_simplede(car u,cadr u);
                if eq(res,-1) then
                         return simpledeexit(car u,cadr u,usevar);
                >>
                else rederr("Wrong number of Arguments for simplede");
     res := sublis('((oddexpt . expt)(ba . a)(nn . k)),res);
     return if reval usevar = usevar then
                     sublis(list('ff . usevar),res)
                else sublis(list('ff . intern gensym()),res);
        end;

algebraic procedure int_simplede(f,x);

begin scalar cap_a,degree0fde,cap_f,j,cap_j,nnn,s,ind,deq,eqq,reqq,
        ak,terms,list1,list2,nmax,cap_m,cap_r,ii,m,leadcoeff,m0,
        len,cap_s,result,parameters,solved,!*allfac,!*protfg;

        !*protfg := t;
        nmax :=fps_search_depth;
        clear a;
        operator a; off allfac;
        depend ff,x;

        dff(0) := f;

% start search for a simple DE

        for degreeofde:=1:nmax do
            <<  dff(degreeofde) := df(dff(degreeofde-1),x);
                eqq :=  dff(degreeofde) +
                       for j:=0:(degreeofde-1) sum a(j) * dff(j);
                eqq := recursionsimplify(eqq);
                eqq := num eqq;
                terms := {};
                list1 := converttolist (eqq,degreeofde+1);
                while list1 neq {} do
                     << list2 := {}; j := fastpart(list1 ,1);
                        cap_j := j; len := fastlength list1;
                        for i:=2:len do
                           if type_ratpoly(j/fastpart(list1,i),x) then
                                cap_j := cap_j + fastpart(list1,i)
                           else list2 := fastpart(list1,i) . list2;
                        terms := cap_j . terms;
                        list1 := reverse list2;
                     >>;

                ind := for j:=0:degreeofde-1 collect a(j);

                s := savesolve(terms,ind);
                if s = {} then nil else
                << if symbolic !*tracefps then write "Solution: ",s;
                        result := degreeofde; nmax := 0 >>;
            >>;

        degreeofde := result;

        if nmax = 0 then << if symbolic !*tracefps then
                         write " successful search for DE">>
          else return -1;

        for each ss in first s do << ss := sub(a(degreeofde)=1,ss);
                                        setze(lhs ss,rhs ss)>>;

% setting up the Differential equation

        on factor;
        deq := df(ff,x,degreeofde) +
                 for j:=0:(degreeofde-1) sum a(j)*df(ff,x,j);
        off factor;
        deq := num deq;
        return deq;
end;

put('fps,'psopfn,'fpseval);

symbolic procedure fpseval(u);
   begin scalar gens,res,!*factor,!*precise;
     if length u = 2 then
        << res := psalg(car u,cadr u);
           if eq(res,-1) then return fpsexit(car u,cadr u,0);
        return sublis('((oddexpt . expt)(ba . a) (nn . k)),res)
        >>
        else if length u = 3 then
               << gens := gensym();
               res := psalg(sublis(list( cadr u . gens),car u),gens);
               if eq(res,-1) then return fpsexit(car u,cadr u,caddr u);
               res := sublis('((oddexpt . expt)(ba . a) (nn . k)),res);
               res := subf(caadr res, list list(gens,'plus,cadr u,
                         list('minus,caddr u)));
               return mk!*sq res;
               >>
                else rederr("Wrong number of Arguments for FPS");
        end;

algebraic procedure asymptpowerseries (f,x);
  sub(x=1/x,fps(sub(x=1/x,f),x));

symbolic procedure fpsexit(a,b,z);
 << erfg!* := nil; list ('fps,a,b, z) >>$

symbolic procedure simpledeexit(a,b,z);
 << erfg!* := nil; list ('simplede,a,b, z) >>$

algebraic procedure psalg(f,x);

begin scalar cap_a,degree0fde,cap_f,j,cap_j,nnn,s,ind,deq,eqq,reqq,
        ak,terms,list1,list2,nmax,cap_m,cap_r,ii,m,leadcoeff,m0,
        len,cap_s,result,parameters,solved,!*allfac,!*protfg;

        f := recursionsimplify f;
        !*protfg := t;
        nmax :=fps_search_depth;
        clear a;
        operator a; off allfac;
        depend ff,x;

        dff(0) := f;

% special cases

        if polynomq(f,x) then return f;
        if type_ratpoly(f,x) then return ratalgo(f,x);

% start search for a simple DE

        clearrules special!*pochhammer!*rules;
        clearrules spec_factorial;
        clearrules spec_pochhammer;

        for degreeofde:=1:nmax do
            <<  dff(degreeofde) := df(dff(degreeofde-1),x);
                eqq :=  dff(degreeofde) +
                       for j:=0:(degreeofde-1) sum a(j) * dff(j);
                eqq := recursionsimplify(eqq);
                eqq := num eqq;
                terms := {};
                list1 := converttolist (eqq,degreeofde+1);
                while list1 neq {} do
                     << list2 := {}; j := fastpart(list1,1); cap_j := j;
                        len := fastlength list1;
                        for i:=2:len do
                                if type_ratpoly(j/fastpart(list1,i),x)
                                  then cap_j:= cap_j + fastpart(list1,i)
                                else list2 := fastpart(list1,i) . list2;
                        terms := cap_j . terms;
                        list1 := reverse list2;
                     >>;

                ind := for j:=0:degreeofde-1 collect a(j);

                s := savesolve(terms,ind);
                if s = {} then nil else
                << if symbolic !*tracefps then write "Solution: ",s;
                        result := degreeofde; nmax := 0 >>;
            >>;

        degreeofde := result;

        if nmax = 0 then << if symbolic !*tracefps then
                         write " successful search for DE">>
          else return -1;

        for each ss in first s do << ss := sub(a(degreeofde)=1,ss);
                                        setze(lhs ss,rhs ss)>>;

% setting up the Differential equation

        on factor;
        deq := df(ff,x,degreeofde) +
                 for j:=0:(degreeofde-1) sum a(j)*df(ff,x,j);
        off factor;
        deq := num deq;
        if symbolic !*tracefps
          then write("Differential equation is: ", deq);

% transforming into Recurrence equation

        factor ba;
        let subst_rules;
        req := pssubst(deq,x,ba,nn);
        clearrules subst_rules;

        if symbolic !*tracefps
          then write("Recurrence equation is :",req);

        ind := {};
        for ii:=-50 : 50 do
           if not(coeffn(req,ba(nn+ii),1) =0) then ind := ii . ind;
        cap_m := first ind;
        if symbolic !*tracefps then
          write(" M, ind, parameters : ",cap_m,",",ind,",", parameters);

        leadcoeff := num coeffn(req,ba(nn+cap_m),1);
        nnn := fastlength ind;

        let special!*pochhammer!*rules;
        let spec_factorial;
        let spec_pochhammer;

        result := 0;

        if (nnn = 1) then <<
                % functions with finite representation
                if symbolic !*tracefps then
                  write
                     "fps with finite number of non-zero coefficients";
                cap_r := sub(nn=nn+(1-cap_m),- reduct(req,ba(nn+cap_m)))
                        /(sub(nn=nn+(1-cap_m),lcof(req,ba(nn+cap_m)))
                         * ba(nn));
                leadcoeff:= sub(nn=nn+(1-cap_m),leadcoeff);
                result := constantre(cap_r,leadcoeff,0,nn,x);
                if result = failed then result :=0;
                >>;

% try hypergeometric case

        if (nnn = 2) then <<
                m := abs(first ind  - second ind);
                cap_r := sub(nn=nn+(m-cap_m),- reduct(req,ba(nn+cap_m)))
                        /(sub(nn=nn+(m-cap_m),lcof(req,ba(nn+cap_m)))
                          * ba(nn));
                leadcoeff:= sub(nn=nn+(m-cap_m),leadcoeff);
                result := hypergeomre(m,cap_r,leadcoeff,0,nn,x)
                >>;

        if result =0 then
        <<
% test for constant coefficients

        terms := for j:=0:(degreeofde-1) join
                         if freeof(a(j),x) then {} else {t};
        if terms = {} then <<
                req := ba(k+degreeofde) +
                         for j:=0:(degreeofde-1) sum ba(k+j)*a(j);
                if symbolic !*tracefps  then
                 << write("DE has constant coefficients");
                    write("DE = ",deq);
                    write("RE = ",req);
                >>;
                s := 0;
                iii := 0;
                while freeof(req,ba(k + iii)) do <<
                        s := s + limit(dff(iii),x,0) * x^iii;
                        iii := iii + 1 >>;
                m0 := iii;
        if symbolic !*tracefps  then write "i was found : ",iii;
        if m0 <= degreeofde-1 then
        << s := solve_lin_rec(req,for i:=m0:(degreeofde-1) collect
                                ba(i) = limit(dff(i),x,0));
           if symbolic !*tracefps  then write("solution : ",s);
           s:=sub(n=nn,s);
           result := infsum(s/(factorial nn) *  x^nn,nn,0,infinity)
        >> else result := s;
       >>;
      >>;

   if result = 0 or not(freeof(result,failed)) then return (-1);
   lisp (erfg!* := nil);
   result:= result;
   let hgspec_pochhammer;
   result:= result;
   clearrules  hgspec_pochhammer;
   result := verbessere (result,nil);
   return result;
end;

flag ('(verbessere), 'opfn);

symbolic procedure verbessere (x,uu);
<< if eqcar (x,'plus) then 'plus .
               foreach xx in cdr x collect verbessere(xx , nil)
  else if not (eqcar (x,'infsum)) then x
  else
  <<
   if eqcar (x,'infsum) and eqcar(cadr x,'quotient) then
     x := list('infsum ,list('quotient,
                simplify_expt cadr cadr x,simplify_expt caddr cadr x));
       uu := cadr x;
   if eqcar (x,'infsum) and eqcar(cadr x,'quotient) then
      << uu := int_simplify_factorial auxcopy cadr x >>;
   list('infsum  , uu,'nn,0,'infinity)>> >>;

symbolic procedure  zerlege u;
 if fixp u and u>0 and  (u<10000 or !*ifactor)
     then <<
        u := zfactor u;
        for each j in u join for jj :=1:cdr j collect (car j) >>
     else list(u);

symbolic procedure simplify_expt u;
  begin scalar uu,exptlist,nonexptlist,asso,numb,expo;
  uu := u;
  if eqcar(u,'times) then u := cdr u;
  while u do
      << if pairp car u and (eq (caar u,'expt)  or eq (caar u,'sqrt))
                then <<
                if numberp cadar u then numb := zerlege (cadar u)
                                else numb := list cadar u;
                expo := if eq (caar u,'sqrt) then '((quotient 1 2))
                                else cddar u;
                while numb do <<
                        if asso:= atsoc (car numb,exptlist) then
                         exptlist := (car numb .
                                list list('plus,car expo,cadr asso)) .
                                        delasc (car numb,exptlist)
                        else
                        exptlist := ((car numb) . expo) . exptlist ;
                        numb := cdr numb;
                             >>;
                     >>
         else if and(idp car u,asso := atsoc (car u,exptlist)) then
                << exptlist := (car u .
                                list list('plus,1,cadr asso)) .
                                        delasc (car u,exptlist) >>
         else nonexptlist := (car u) . nonexptlist;
        u := cdr u;
       >>;
  if null exptlist then return uu;

  for each x in exptlist do
         nonexptlist :=  ('oddexpt . x ) . nonexptlist;
  return (car uu) . nonexptlist;
  end;

fluid ('(rsolve!*!*));

algebraic procedure hypergeomre(m,cap_r,leadcoeff,dffpointer,k,x);

% solve the hypergeometric Recurrence Equation
%
%   a(k+m) = cap_R(k) * a(k)
%
%  where leadcoeff is the leading coefficient of the RE
%  and DF is a table where DF(dffpointer+i) = df(f,x,i)

  begin scalar denr,fract,ii,m0,m1,c0,ck,s,c,df2,q,r2,lterm,nn,
        s0, leadcoeff2;
        denr := solve(leadcoeff,k);
        m0 := {};
        foreach xx in denr do
                if type_rational rhs xx then  m0 := ((rhs xx)+1) . m0;
        if not(m0 = {}) then m0 := max(m0) else m0 := 0;

        if symbolic !*tracefps then
                 << write "RE is of hypergeometric type";
                    write "Symmetry number mm := ",m;
                    write "RE: for all k >= ",m0,": a (k + ",m,") = "
                        ,cap_r * a(k);
                    write "leadcoeff := ",leadcoeff; >>;

        fract := {};
        foreach xx in denr do
                if type_fraction(rhs xx)
                  then fract := den(rhs xx) . fract;
        if not(fract = {}) then
                << q := first fract;
                   dff(dffpointer + 10) := sub(x=x^q,dff(dffpointer));
                   if symbolic !*tracefps then <<
                        write "RE modified to nn= ",k/q;
                        write "=> f := ",dff(dffpointer + 10)>>;
                   s := hypergeomre(q*m,sub(k=k/q,cap_r),
                        sub(k=k/q,leadcoeff),dffpointer + 10,k,x);
                   return sub(x=x^(1/q),s); >>;

        if m0 < 0  then <<
                nn:= -m0 + remainder(-m0,m);
                dff(dffpointer + 10) := df2 := x^nn * dff(dffpointer);
                if symbolic !*tracefps then <<
                        write "working with ",x^nn,"*f";
                        write "=> f :=" ,df2 >>;
                s := hypergeomre(m,sub(k=k-nn,cap_r),
                                   sub(k=k-nn,leadcoeff),
                                   dffpointer + 10,k,x);
                return update_coeff(s,x,-nn) >>;

        if m0 > 0  then <<
         m1 := {};
         foreach xx in denr do if type_rational rhs xx then
                         m1 := append(list (rhs xx +1),m1);
         m1 := min m1;
         if m1 > 0 then <<
                dff(dffpointer + 10) := df2 := x^(-m1)*dff(dffpointer);
                if symbolic !*tracefps then <<
                        write"a(k) = 0 for k < ",m1;
                        write "working with ",x^(-m1),"*f";
                        write "=> f :=" ,df2 >>;
                s := hypergeomre(m,sub(k=k+m1,cap_r),
                                   sub(k=k+m1,leadcoeff),
                                        dffpointer + 10,k,x);
                return update_coeff(s,x,m1);
                        >> >>;

     % logarithmic singularity Baustelle
        if lisp pairp
                 errorset!*(list ('simptaylor,mkquote list(
                                        mkquote list('dff,dffpointer),
                                        mkquote x,0,1)),nil) then
        <<
        lterm := num taylortostandard(taylor(dff(dffpointer),x,0,1));
        nn := 0;
        if lisp(if  member('(log x) ,kernels !*q2f simp lterm)
                         then t else nil) % Comments?
                then <<
                        dff(dffpointer + 10):=dff(dffpointer) -lterm;
                        if symbolic !*tracefps then
                                write "=> f :=",dff(dffpointer + 10);
                        s := hypergeomre(m, r, leadcoeff*(k-nn),
                                dffpointer + 10,k,x);
                        return(lterm+s);
                     >>;
        >>;

        s := 0; s0 := 0;
        for i:=0:(m0+m-1) do <<
           if i > 0 then
             dff(dffpointer + i) := df(dff(dffpointer + i-1),x);
           c0 := limit(dff(dffpointer + i),x,0);

           if (lisp listp reval c0 and fastpart(c0,0) = limit) then
                <<  if symbolic !*tracefps
                        then write "Could not find the limit of: "
                        ,dff(dffpointer + i),",",x,",",0;
                    rederr("Problem using limit operator") >> else
                <<
                c0 := c0/factorial (i);
                if symbolic !*tracefps then write " a(",i,") = ",c0;
                if not (c0 =0) then
                     << s0 := s0+c0*x^i;
                        if i < m0 then s := s + c0 * x^i % single terms
                        else
                     << ck := hypergeomrsolve(sub(k=m*k+i,cap_r),k,c0);
                        if symbolic !*tracefps then write " ck = ",ck;
                        c :=1;
                        ck := ck/c;
                        let hgspec_pochhammer;
                        ck := ck;
                        clearrules hgspec_pochhammer;
                        if ck = 0 then s := s + c0*x^i else
                         if rsolve!*!* = finite then s := s +
                                c*sum(ck*x^(m*k+i), k)
                         else
                         s := s + c * infsum(ck*x^(m*k+i)) ;
                        if symbolic !*tracefps then write " S = ",s;
                >> >> >> >>;
  return (s);
end;

algebraic << let infsum(0) = 0>>;

% some compatibility functions for Maple sources.

symbolic flag('(savesolve type_fraction type_rational),'opfn);

algebraic procedure converttolist (express,len);
 <<
  len := fastlength express;
  for i:=1:len collect fastpart(express , i)>>;

symbolic procedure type_fraction (num);
  (if pairp num1 and fixp car num1 and fixp cdr num1
        and not onep cdr num1
   then num else nil) where num1 := simp num;

symbolic procedure type_rational(num);
 (if pairp num1 and (fixp car num1 or null car num1) and fixp cdr num1
   then t else nil) where num1 := simp num;

algebraic procedure type_ratpoly(exprn,var);
  if (polynomq (den exprn,var) and polynomq (num exprn,var))
    then t else nil;

symbolic procedure savesolve (x,y);

begin scalar !*cramer;
on cramer; % this is a temporary fix for solve !!
           % check with  fps(sin(x)^2 * cos(x)^2,x); !!
return
<< switch solveinconsistent;
   on solveinconsistent;
   inconsistent!* := nil;
   if pairp (x := errorset!*(list ('solveeval,mkquote list(x,y)),nil))
        and not inconsistent!*
        then << x :=car x;
                if x = '(list) then x else
                if eqcar(cadr x,'equal) then % one element solution
                        list('list,x) else x>>
        else list('list) >>;
end;

algebraic procedure setze(x,y);
  let x = y;

symbolic procedure polynomq (x,var);

 if not fixp denr simp x then nil else
 begin scalar kerns,kern;

 kerns := kernels !*q2f simp x;

 aa: if null kerns then return t;
     kern := first kerns;
     kerns := cdr kerns;
     if not(eq (kern, var)) and depends(kern,var)
                then return nil else go aa;
end;

flag('(polynomq),'opfn);

flag ('(polynomq type_ratpoly),'boolean);


algebraic << operator update_coeff;

update_coeff_rules := {

 update_coeff (~a + ~b,~x,~m) => update_coeff(a,~x,~m)
                                + update_coeff(b,~x,~m),
 update_coeff (~c * ~a,~x,~m) => c * update_coeff(a,~x,~m)
        when freeof(c,x),
 update_coeff ( -  ~a,~x,~m) =>  - update_coeff(a,~x,~m),
 update_coeff (~a/~c,~x,~m) => update_coeff(a,~x,~m) /c
        when freeof(c,x) and c neq 1,
 update_coeff (~x,~x,~m) => x^(m + 1),
 update_coeff (~c,~x,~m) => c * x^m  when freeof(c,x),
 update_coeff (infsum(~xx),~x,~m) => infsum update_coeff(xx,x,m),
 update_coeff (~x^~j*~xx,~x,~m) => x^(j + m + 1)when x = xx,
 update_coeff (~x^~j*~xx^~jj,~x,~m) => x^(j + jj + m) when x = xx,
 update_coeff (~x^~j,~x,~m) => x^(j + m)}$

let update_coeff_rules >>$

endmodule;


module substexp;

algebraic;

depend ff,x;
depend f,x;
depend f,!~k;

operator pssubst;

operator a,pproduct;

subst_rules :=

{ pssubst(- ~g,~x,~a,~n) => -pssubst(g,x,a,n),
  pssubst(~g+~h,~x,~a,~n) => pssubst(g,x,a,n) + pssubst(h,x,a,n),
  pssubst(~c*~g,~x,~a,~n) => c*pssubst(g,x,a,n)
                        when freeof(c,x) and freeof(c,g),
  pssubst(df(~f,~x,~k),~x,~a,~n) => pochhammer(n+1,k) * a(n+k),
  pssubst(df(~f,~x),~x,~a,~n) => (n + 1)* a(n + 1),
  pssubst(~x^~j * df(~f,~x),~x,~a,~n) => pochhammer(n+1-j,1)*a(n+1-j),
  pssubst(~x^~j * df(~f,~x,~k),~x,~a,~n)=> pochhammer(n+1-j,k)*a(n+k-j),

  pssubst(ff*~x^~j,~x,~a,~n) => a(n-j),
  pssubst(ff*~x,~x,~a,~n)    => a(n-1),

  pssubst(df(~f,~x) *x,~x,~a,~n) => pochhammer(n,1)*a(n),
  pssubst(df(~f,~x,~k) *x,~x,~a,~n) => pochhammer(n,k)*a(n+k-1),

  pssubst(f,~x,~a,~n) => a(n),
  pssubst(ff,~x,~a,~n) => a(n),

  pssubst(~c,~x,~a,~n) => 0 when freeof(c,x),
  pssubst(~x^~j,~x,~a,~n) => 0 when fixp j,
  pssubst(~x,~x,~a,~n) => 0
  };

spec_pochhammer :=

{ pochhammer(~a,~k)//pochhammer(~b,~k) => (a + k -1)/(a - 1)
     when (a - b)=1,
  pochhammer(~a,~k)//pochhammer(~b,~k) => (b - 1)/(b + k -1)
     when (b - a)=1,
  pochhammer(~z,~k) * pochhammer(~cz,~k) =>
     prod((repart(z) + (j - 1))^2 + (impart(z))^2,j,1,k)
        when not(impart(z) = 0) and z = conj cz,
  pochhammer(~k,~n) => 1 when n=0,
  pochhammer(~k,~n) => pproduct (k,n) when fixp n,
  pproduct (~k,~ii) => 1 when ii =0,
  pproduct (~k,~ii) => (k + ii - 1) * pproduct (k,ii -1)}$

spec_factorial :=

{ factorial (~n) // factorial (~n+1) => 1/(n+1),
  factorial (~n) * factorial (~n) // factorial (~n+1) =>
                                factorial (n)/(n+1),
  factorial (~n+1) // factorial (~n) => (n+1),
  factorial (~n+1) * factorial (~n+1) // factorial (~n) =>
                                (n+1) * factorial (~n+1),
  (~otto ^(~k)) * factorial (~n) // factorial (~n +1) => otto^k  /(n+1),
  (~otto ^(~k)) * factorial (~n+1) // factorial (~n) =>  otto^k * (n+1),
  (~otto ^~k) * ~hugo * factorial (~n) // factorial (~n +1) =>
      otto^k * hugo/(n+1),
  (~otto ^~k) * ~hugo * factorial (~n+1) // factorial (~n) =>
      otto^k * hugo *(n+1)}$

endmodule;


module linrec;

% solves (simple in) homogenous linear recursion relation REC which
% has to have the form var(n)... with initial conditions
% IC in the form of list {var(1)=?,var(2)=...}
% the method used - substitution s(n)=x^n
% like e^(lambda*x) in linear homogenous ODE.

% The inhomogenous term has to be a constant.

% The following code has been developed by Richard Liska from Prague
% for the "Barry Simon Tests for PC Magazine".
% Some checks and generalizations included by W. Neun , ZIB Berlin

% the switch trlinrec turns the verbose mode on.

switch trlinrec;

algebraic procedure rsolve (rec,ic);

begin scalar mvar1,inde,constpart,lowestind,modic,modrec,indis;

mvar1 := part(mainvar rec ,0);
inde  := mainvar part(mainvar rec,1);
indis := the_indices(foreach kk in ic collect lhs kk,mvar1);
highestind := if indis neq {} then max(indis) else nil;
nindis := the_indices(rec,mvar1);

           % applying rule : rec where r(~n) => 0

constpart := lisp aeval list('whereexp,
                list('list,list('replaceby,list(mvar1,list('!~,'n)),0)),
                rec);

if not freeof(constpart,inde) then rederr
   ("Cant solve recurrence equations with non-constant coefficients");

if eq(constpart , 0) then return
        solve_lin_rec(rec,ic)
  else
        <<  modrec := sub (inde = inde +1,rec);
            modrec := modrec -rec;
            if (highestind) then <<
% Propagate the recursion to get additional start value
            modic := sub(inde=inde -max(nindis)+ highestind+1,rec);
            for each aa in ic do modic := sub(aa,modic);
            modic := (first solve(modic,mainvar modic)) . ic >>
            else modic := ic;
            return solve_lin_rec(modrec,modic);
         >>;
end;


fluid '(linrecx!*,linrecvar!*);

algebraic procedure solve_lin_rec(rec,ic);
   % solves homogenous linear recursion relation REC which
   % has to have the form var(n)... with initial conditions
   % IC in the form of list {var(1)=?,var(2)=...}
   % the method used - substitution s(n)=x^n
   % like e^(lambda*x) in linear homogenous ODE.
   % Of course some checking should be added. (Done WN)
   begin
     scalar lrec,sol,msol,gsol,j,flagg,c,linrecvar!*,errflag,nsave;
     clear n;
     linrecvar!* := part (mainvar rec,0);
     linrecx!* := lisp gensym();
     c:= lisp mkquote gensym(); %this is the dirty part. WN
     operator c;
     if(part(rec,0) eq linrecvar!*) and arglength(ic)=1 and
                part(mainvar lhs first ic,0) = linrecvar!*
                then return rhs (first ic);
      if(part(rec,0) neq plus) then return  rederr
       "Cant solve recurrence equations with non-constant coefficients";
      lrec := arglength rec;
      lrec := part(rec,lrec);
     for all n let linrecvar!*(n) = linrecx!*^n;
     lrec := lrec;
     rec:=rec /lrec;
     for all n clear linrecvar!* (n);
     rec:=num rec;
     for each j in coeff(rec,linrecx!*) do
                if (not freeof(j,part(part (part rec,1),1)))
                        then errflag := 17; %???
     if (errflag = 17) then return rederr
       "Cant solve recurrence equations with non-constant coefficients";
     j:=1;
     for each a in solve(rec,linrecx!*) do
       <<a:=rhs a^n;
         gsol:=gsol+c(j)*a;
         j:=j+1;
         msol:=first multiplicities!*;
         multiplicities!*:=rest multiplicities!*;
         while msol>1 do
           <<a:=n*a;
             gsol:=gsol+c(j)*a;
             j:=j+1;
             msol:=msol-1 >> >>;
     if lisp !*trlinrec then write "General solution: ",linrecvar!*
                ,"(N) := ",gsol;
     if ic = {} then sol := {} else
     sol:=solve(for each a in ic collect
                        sub(n=part(lhs a,1),gsol)=rhs a,
                for i:=1:arglength ic collect c(i));
   % If some c(i) remains it can be arbitrary  complex;
     sol := lisp subla('((equal . replaceby)),sol);
     sol := lisp subla('((equal . replaceby)),sol);
     let sol;
     gsol:=gsol;
     clearrules sol;
     let moivre_expt;
     gsol:=gsol;
     clearrules moivre_expt;

     for i:=1:j do  if coeff(gsol,lisp list(c, i)) = list(gsol) then nil
        else gsol:=
           sub(lisp list(c, i) = lisp caaar makearbcomplex(),gsol);
     return gsol
   end;

% (1 + i)**n =>     %applying Moivre's formula for complex numbers

%                N/2       N*PI          N*PI
%               2   *(COS(------) + SIN(------)*I)
%                           4             4

algebraic (moivre_expt := { (~z)^(~k) =>
              moivre(z,k) when not  freeof(z,i)});

algebraic procedure moivre(z,k);

  begin scalar rho,phi; % what ( will happen
  rho := sqrt( (repart z)^2 + (impart z)^2);
  if repart  z = 0 then phi := pi/2 else
        phi := atan((impart z)/(repart  z));
  return rho^k *(cos(k*phi) + i * sin (k*phi));
  end;

algebraic procedure the_indices(ex,mvar);

if part(ex,0) = list then for each kk in ex join the_indices(kk,mvar)
else
begin scalar eqq,l1,l2,kern;
  eqq := ex;
  lisp (kern := union (kernels !*q2f  (numr simp eqq ./ 1),
                        kernels !*q2f (denr simp eqq ./ 1)));

  l1 := 'list . lisp  foreach k in kern join
         if atom k then nil else if eqcar(k,mvar) then
                                list cadr k else nil;

  return l1;
end;
endmodule;


module hypergeomrsolve;

fluid '(!*tracefps);

algebraic procedure hypergeomrsolve (r,k,a0);

% solves the recurrence equation
%
%  a(k+1) = r(k) * a(k), a(0) = a0

  begin scalar re,nnn,ddd,c,p,q,ak,sols,ii;

   p := {}; q := {};
   c := 1;

   re := r * (k + 1);

   nnn := factorize num re; ddd := factorize den re;

   foreach nn in nnn do
   if freeof (nn,k) then c := c * nn
        else if deg(nn,k) =1 then
        << c:= c*coeffn(nn,k,1);
            p:= append (p,list(coeffn(nn,k,0)/coeffn(nn,k,1)))>>
        else if deg(nn,k) =2 then
        << c := c *  lcof(nn,k);
                sols := solve(nn,k);
                for each s in sols do
                   << for i:=1:first multiplicities!* do
                        p:= (- rhs s) . p;
                      multiplicities!* := rest multiplicities!*;
                  >>
        >>
        else rederr(" hypergeomRsolve failed");

   foreach dd in ddd do
   if freeof (dd,k) then c := c / dd
        else if deg(dd,k) =1 then
        << c:= c/coeffn(dd,k,1);
            q:= append (q,list(coeffn(dd,k,0)/coeffn(dd,k,1)))>>
        else if deg(dd,k) =2 then
             << c := c /  lcof(dd,k);
                sols := solve(dd,k);
                for each s in sols do
                   << for i:=1:first multiplicities!* do
                        q:= (- rhs s) . q;
                      multiplicities!* := rest multiplicities!*;
                  >>;
             >>
        else rederr(" hypergeomRsolve failed");

   rsolve := infinite;
   for each s in p do if fixp s and s < 0 then rsolve := finite;
   if symbolic !*tracefps then  write "RSOLVE  = ",rsolve;

   p := for each s in p product pochhammer(s,k);
   q := for each s in q product pochhammer(s,k);

   ak := a0 * (c^k) * p/(q * factorial k);

% Do additional simplification here??

   return ak;
end;

% A special ruleset for powerseries; nn has a special meaning here and
% should be treated as integer

algebraic <<

hgspec_pochhammer :=

{ pochhammer(~kk,~nn) => 1 when nn=0,
  pochhammer(~kk,nn) => 0 when kk = 0,
  pochhammer(~kk,nn) => (-1)^nn * factorial(-kk)/factorial(-kk-nn)
                        when fixp(kk) and kk <=0,
  pochhammer(~kk,nn) => factorial(kk+nn-1)/factorial(kk-1) when fixp kk,
  pochhammer(~kk,~w*nn) =>
     factorial(kk+w*nn-1)/factorial(kk-1) when fixp kk}
>>;

endmodule;


module constre;

algebraic procedure constantre(cap_r,leadcoeff,dffpointer,k,x);

% solve  constant RE
%
%   a(k+1) = cap_R(k) * a(k)
%
%  where leadcoeff is the leading coefficient of the RE
%  and DF is a table where DF(dffpointer+i) = df(f,x,i)

  begin scalar denr,fract,ii,m0,m1,c0,ck,s,c,df2,q,r2,lterm,nn,
        s0, leadcoeff2;
        denr := solve(leadcoeff,k);
        m0 := {};
        foreach xx in denr do
                if type_rational rhs xx then  m0 := ((rhs xx)+1) . m0;
        if not(m0 = {}) then m0 := max(m0) else m0 := 0;

        if symbolic !*tracefps then
                 << write ">>> m0 = ",m0;
                    write "RE is constant";
                    write "RE: for all k >= ",m0,": a (k + 1) = "
                        ,cap_r * a(k);
                    write "leadcoeff := ",leadcoeff; >>;

        fract := {};
        foreach xx in denr do
                if type_fraction(rhs xx) then
                         fract := den(rhs xx) . fract;
        if not(fract = {}) then
                << q := first fract;
                   dff(dffpointer + 10) := sub(x=x^q,dff(dffpointer));
                   if symbolic !*tracefps then <<
                        write "RE modified to nn= ",k/q;
                        write "=> f := ",dff(dffpointer + 10)>>;
                   s := constantre(sub(k=k/q,cap_r),
                        sub(k=k/q,leadcoeff),dffpointer + 10,k,x);
                   return sub(x=x^(1/q),s); >>;

        if m0 < 0  then <<
                nn:= -m0 + 1;
                dff(dffpointer + 10) := df2 := x^nn * dff(dffpointer);
                if symbolic !*tracefps then <<
                        write "working with ",x^nn,"*f";
                        write "=> f :=" ,df2 >>;
                s := constantre(sub(k=k-nn,cap_r),sub(k=k-nn,leadcoeff),
                                        dffpointer + 10,k,x);
                return update_coeff(s,x,-nn);
        >>;

        if m0 = 0 then <<
                if symbolic !*tracefps then write "PS does not exist";
                return failed>>;

        if m0 > 0  then <<
        m1 := {};
        foreach xx in denr do if type_rational rhs xx then
                         m1 := append(list (rhs xx +1),m1);
        m1 := min m1;
        if m1 < 0 then <<
                dff(dffpointer + 10) := df2 := x^(-m1)*dff(dffpointer);
        if symbolic !*tracefps then <<
                        write "working with ",x^(-m1),"*f";
                        write "=> f :=" ,df2 >>;
                s := constantre(sub(k=k+m1,cap_r),sub(k=k+m1,leadcoeff),
                                        dffpointer + 10,k,x);
                return update_coeff(s,x,m1)
                >>;
        >>;

        % { m1 >= 0 }

        s := 0; s0 := 0;
        for i:=0:m0 do
                <<
                if i > m1 then
                  dff(dffpointer + i) := df(dff(dffpointer + i-1),x);
                c0 := limit(dff(dffpointer + i),x,0);
                if (not numberp c0 and part(c0,0) = limit) then
                        <<  write "Could not find the limit of: "
                                ,dff(dffpointer + i),",",x,",",0;
                    rederr("problem using limit operator") >> else
                <<
                c0 := c0/factorial (i);
                s := s + c0*x^i ;
                if symbolic !*tracefps then write " S = ",s;
                >> >>;
  return (s);

end;

endmodule;


module ratalgo;

% rational algorithm for FPS package

algebraic procedure complexapart(f,x);

    begin scalar !*factor,!*complex;
        on factor,complex;
        x := pf(f,x);
        off factor,complex;
        return x;
   end;

algebraic procedure ratalgo(p,x);
     begin scalar afp,tt,s,ak,d,c,j,ss;
     afp := complexapart(p,x);

     s:= 0; ak := 0;

     if symbolic !*tracefps then write " Rational Algorithm applied";

     foreach tt in afp do
        << if freeof(tt,x) then s := s + tt else
           <<
           d := 1/tt;
           if not polynomq(d,x) then <<
                if symbolic !*tracefps then write
                         " Rational Algorithm  failed";
                s := -1 >>;
          if not (s = -1) then
          <<
           d := d/lcof(d,x); c := d * tt;
           j := deg(d,x);
           d := expt(d,1/j);
           if not polynomq(d,x) then <<
                if symbolic !*tracefps then write
                        " Rational Algorithm  failed";
                afp := {}; d :=12;
                s := -1 >>;
           if d = x then s := s + c/d^j  else
                <<
                ss := lcof(d,x);
                d := d /ss; c := c / ss;
                xk := x -d; c:= c*(-1)^j/xk ^j;
                ak  := ak +
                   c*simplify_factorial(factorial(j + k -1)/
                        factorial(k)/factorial(j-1))/xk^k;
        >> >> >> >>;
        if s = -1 then return (-1);
        return s := s + infsum(ak*x^k,k,0,infinity)
    end;

symbolic procedure fastpart(x,n);
        reval nth( x,n +1);

flag ('(fastpart fastlength),'opfn);

symbolic procedure fastlength(x);
        length (x) -1;

symbolic procedure auxcopy(u);
   if pairp u then cons (auxcopy car u, auxcopy cdr u) else u;

% for XR

if getd 'print_format then
        print_format('(pochhammer u v),'(!( u !) !_ v));

endmodule;


end;
