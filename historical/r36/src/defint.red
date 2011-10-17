module defint;  % Special functions integrator package for REDUCE.

% Author:  Kerry Gaskell 1993/94.
%          Winfried Neun, Jan 1995 ...
%          contribution from Victor Adamchik (WRI)

load_package 'specfn2;

algebraic operator m_jacobip,m_gegenbauerp,m_laguerrep,m_hermitep,
                m_chebyshevu,m_chebyshevt,m_legendrep,
                struveh2,mycosh,mysinh;

global '(spec_cond unknown_tst product_tst transform_tst transform_lst);


create!-package ('(defint definta defintc defintf definti defint0
                defintd defintg defintj defintb definte
                definth defintk defintx),
%               definth defintk),
                 '(contrib defint));

!#if (memq 'psl lispsystem!*)
  flag('(definta defintb definte defintf definti defintk),'lap);
!#endif

fluid '(mellincoef);
share mellincoef$

endmodule;


%***********************************************************************
%*                             INTEGRATION                             *
%***********************************************************************

module definta$

transform_lst := '();

algebraic operator f1$
algebraic operator f2$

fluid '(mellincoef);

fluid '(plotsynerr!*);

%***********************************************************************
%*                          MAIN PROCEDURES                            *
%***********************************************************************

symbolic smacro procedure gw u;
  caar u$

symbolic smacro procedure gl u;
  caadar u$

symbolic smacro procedure gk u;
  cdadar u$

symbolic smacro procedure gr u;
  cadar u$

symbolic smacro procedure gm u;
  caadr u$

symbolic smacro procedure gn u;
  cadadr u$

symbolic smacro procedure gp u;
  caddr cadr u$

symbolic smacro procedure gq u;
  cadddr cadr u$

symbolic smacro procedure ga u;
  caddr u$

symbolic smacro procedure gb u;
  cadddr u$

symbolic procedure rdwrap f;
if numberp f then float f
  else if f='pi then 3.141592653589793238462643
  else if f='e then 2.7182818284590452353602987
  else if atom f then f
  else if eqcar(f, '!:rd!:) then
          if atom cdr f then cdr f else bf2flr f
  else if eqcar(f, '!:dn!:) then rdwrap2 cdr f
  else if eqcar(f, 'minus) then
    begin scalar x;
       x := rdwrap cadr f;
       return if numberp x then minus float x else {'minus, x}
    end
  else if get(car f, 'dname) then
    << plotsynerr!*:=t;
       rerror(plotpackage, 32, {get(car f, 'dname),
                                "illegal domain for PLOT"})
    >>
  else if eqcar(f,'expt) then rdwrap!-expt f
  else rdwrap car f . rdwrap cdr f;

symbolic procedure rdwrap!-expt f;
% preserve integer second argument.
  if fixp caddr f then {'expt!-int,rdwrap cadr f,caddr f}
    else {'expt,rdwrap cadr f, rdwrap caddr f};

symbolic procedure rdwrap2 f;
% Convert from domain to LISP evaluable value.
  if atom f then f else float car f * 10^cdr f;

symbolic procedure rdwrap!* f;
% convert a domain element to float.
  if null f then 0.0 else rdwrap f;

symbolic procedure rdunwrap f;
  if f=0.0 then 0 else if f=1.0 then 1 else '!:rd!: . f;

symbolic procedure expt!-int(a,b); expt(a,fix b);

put('intgg,'simpfn,'simpintgg)$

symbolic procedure simpintgg(u);
<<u:=intggg(car u,cadr u,caddr u,cadddr u);
  simp prepsq u>>;

symbolic procedure intggg(u1,u2,u3,u4);
begin scalar v,v1,v2,s1,s2,s3,coef,uu1,uu2,test_1,test_1a,test_2,m,n,p,
        q,delta,xi,eta,test,temp,temp1,temp2,var,var1,var2;


 off allfac;
 uu1:= cadr u1; uu1:= prepsq cadr(algebraic uu1);
 uu2:= cadr u2; uu2:= prepsq cadr(algebraic uu2);
 u1:=if null cddr u1 then list('f1, uu1) else 'f1 . uu1 . cddr u1;
 u2:=if null cddr u2 then list('f2, uu2) else 'f2 . uu2 . cddr u2;


% Cases for the integration of a single Meijer G-function
 if equal(get('f1,'g),'(1 . 1)) and
          equal(get('f2,'g),'(1 . 1)) then

         return simp 'unknown

 else if equal(get('f1,'g),'(1 . 1)) then

% Obtain the appropriate Meijer G-function

    <<s1:=bastab(car u2,cddr u2);

      v:= trpar(car cddddr s1, cadr u2, u4);
      on allfac;
      if v='fail then return simp 'fail;

% Substitute in the correct variable value

      temp := car cddddr s1;
      var := cadr u2;
      temp := reval algebraic(sub(x=var,temp));

      s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp};

% Ensure by simplification that the variable does not contain a power

      s1 := simp_expt(u3,s1);

      u3 := car s1;
      s1 := cdr s1;

% Test the validity of the following formulae

% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 page 157 (3),(3*) & (4)

      test_1 := test_1(nil,u3,s1);
      test_1a := test_1('a,u3,s1);
      test_2 := test2(u3,cadr s1,caddr s1);

      m := caar s1;
      n := cadar s1;
      p := caddar s1;
      q := car cdddar s1;

      delta := reval algebraic(m + n - 1/2*(p + q));
      xi := reval algebraic(m + n - p);

      eta := car cddddr s1;
      eta := reval algebraic(eta/u4);

% Test for validity of the integral

      test := reval list('test_cases,m,n,p,q,delta,xi,eta,test_1,
                                                test_1a,test_2);

      if transform_tst = 't then
          test := 't;

      if test neq 't then
          return simp 'unknown;

      coef:=simp!* cadddr s1;

      s1:=list(v,car s1,listsq cadr s1,
               listsq caddr s1,simp!*(subpref(cadr u2,1,u4)));
      s3:=addsq(simp!* u3,'(1 . 1));
      return intg(s1,s3,coef)

    >>

 else if equal(get('f2,'g),'(1 . 1)) then

% Obtain the appropriate Meijer G-function

    <<s1:=bastab(car u1,cddr u1);

      v:= trpar(car cddddr s1, cadr u1, u4);
      on allfac;
      if v='fail then return simp 'fail;

% Substitute in the correct variable value

      temp := car cddddr s1;
      var := cadr u1;
      temp := reval algebraic(sub(x=var,temp));

      s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp};

% Ensure by simplification that the variable does not contain a power

      s1 := simp_expt(u3,s1);

      u3 := car s1;
      s1 := cdr s1;

% Test the validity of the following formulae

% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 page 157 (3),(3*) & (4)

      test_1 := test_1(nil,u3,s1);
      test_1a := test_1('a,u3,s1);
      test_2 := test2(u3,cadr s1,caddr s1);

      m := caar s1;
      n := cadar s1;
      p := caddar s1;
      q := car cdddar s1;

      delta := reval algebraic(m + n - 1/2*(p + q));
      xi := reval algebraic(m + n - p);

      eta := car cddddr s1;
      eta := reval algebraic(eta/u4);

% Test for validity of the integral

      test := list('test_cases,m,n,p,q,delta,xi,eta,test_1,test_1a,
                                                        test_2);

      test := reval list('test_cases,m,n,p,q,delta,xi,eta,test_1,
                                                test_1a,test_2);

      if transform_tst = 't then
          test := 't;
      if test neq 't then
         return simp 'unknown;

      coef:=simp!* cadddr s1;

      s1:=list(v,car s1,listsq cadr s1,
               listsq caddr s1,simp!*(subpref(cadr u1,1,u4)));
      s3:=addsq(simp!* u3,'(1 . 1));
      return intg(s1,s3,coef)

    >>;

% Case for the integration of a product of two Meijer G-functions

% Obtain the correct Meijer G-functions

  s1:=bastab(car u1,cddr u1);

  s2:=bastab(car u2,cddr u2);

  coef:=multsq(simp!* cadddr s1,simp!* cadddr s2);

  v1:= trpar(car cddddr s1, cadr u1, u4);
  if v1='fail then
  << on allfac;
     return simp 'fail >>;


  v2:= trpar(car cddddr s2, cadr u2, u4);
  if v2='fail then
  << on allfac;
     return simp 'fail >>;

  on allfac;

% Substitute in the correct variable value

  temp1 := car cddddr s1;
  var1 := cadr u1;
  temp1 := reval algebraic(sub(x=var1,temp1));

  s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp1};

  temp2 := car cddddr s2;
  var2 := cadr u2;
  temp2 := reval algebraic(sub(x=var2,temp2));

  s2 := {car s2,cadr s2,caddr s2,cadddr s2,temp2};

  s1:=list(v1,car s1,listsq cadr s1,
         listsq caddr s1,simp!*(subpref(cadr u1,1,u4)));


  s2:=list(v2,car s2,listsq cadr s2,
         listsq caddr s2,simp!*(subpref(cadr u2,1,u4)));
  s3:=addsq(simp!* u3,'(1 . 1));

  if not numberp(gl s1) or not numberp(gl s2) then
        return simp 'fail
  else
  if gl s1<0 then s1:=cong s1 else
  if gl s2<0 then s2:=cong s2 else


  if gl s1=gk s1 then goto a  else      % No reduction is necessary if
                                        % it is not a meijer G-function
                                        % of a power of x
  if gl s2=gk s2 then
            <<v:=s1;s1:=s2;s2:=v;go to a>>;
                                        % No reduction necessary but
                                        % the Meijer G-functions must
                                        % be inverted
  coef:=multsq(coef,invsq gr s1);
                                   %premultiply by inverse of power
  v:=modintgg(s3,s1,s2);
  s3:=car v;    s1:=cadr v;   s2:=caddr v;
  a:

% Test for validity of the integral


  test := validity_check(s1,s2,u3);

  if test neq 't then
      return simp 'unknown;

  coef := multsq(if numberp(mellincoef) then simp(mellincoef)
                                     else cadr mellincoef,
              multsq(coef,coefintg(s1,s2,s3)));

  v := deltagg(s1,s2,s3);
  v := redpargf(list(arggf(s1,s2),indgf(s1,s2),car v,cadr v));
  v := ('meijerg . mgretro (cadr v,caddr v,car v));
  v := aeval v;

  if eqcar(v,'!*sq) then
      v := cadr v
  else if fixp v then
      v := simp v;

  if v='fail then
      return simp 'fail
  else
      return multsq(coef,v);

end$



symbolic procedure mgretro (u,v,w);

  begin scalar caru,carv,cdru,cdrv;

  caru := car u; cdru := cdr u; carv := car v; cdrv := cdr v;

  return
  list('list . cons ('list . foreach aa in caru collect prepsq aa,
              foreach aa in cdru collect prepsq aa),
       'list . cons ('list . foreach aa in carv collect prepsq aa,
              foreach aa in cdrv collect prepsq aa),
       prepsq w);
end;

symbolic procedure intg(u1,u2,u3);
 begin scalar v;
   if numberp(gl(u1)) and gl(u1) < 0 then u1:=cong u1;
   v:=modintg(u2,u1);
   u1:=cadr v;
   v:=
     multlist(
       list(u3,
            expdeg(gw u1,negsq u2),
            quotsq(
               multgamma(
                 append(
                   listplus(car redpar1(gb u1,gm u1),u2),
                   listplus(
                     listmin(car redpar1(ga u1,gn u1)),
                     diff1sq('(1 . 1),u2)))),
               multgamma(
                 append(
                   listplus(cdr redpar1(ga u1,gn u1),u2),
                   listplus(
                     listmin(cdr redpar1(gb u1,gm u1)),
                     diff1sq('(1 . 1),u2)))))));
   return multsq(if numberp(mellincoef) then simp(mellincoef)
                                     else cadr mellincoef,
                 v);
end$

%***********************************************************************
%*              EVALUATION OF THE PARAMETERS FOR THE G-FUNCTION        *
%***********************************************************************

symbolic procedure simp_expt(u,v);

% Reduce Meijer G functions of powers of x to x

begin scalar var,m,n,coef,alpha,beta,alpha1,alpha2,expt_flag,k,temp1,
            temp2;

var := car cddddr(v);

beta := 1;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

if length var = 0 then
    return u . v

else

<< k := u;
   coef := cadddr v;

   for each i in var do

   << if listp i then
      << if car i = 'expt then
         << alpha := caddr i;
            expt_flag := 't>>

         else if car i = 'sqrt then
         << beta := 2;
            alpha := 1;
            expt_flag := 't>>

         else if car i = 'times then
         << temp1 := cadr i;
            temp2 := caddr i;

            if listp temp1 then
            << if  car temp1 = 'sqrt then
               << beta := 2;
                  alpha1 := 1;
                  expt_flag := 't>>

               else if car temp1 = 'expt and listp caddr temp1 then
                  << beta := cadr cdaddr temp1;
                     alpha1 := car cdaddr temp1;
                     expt_flag := 't>>;
            >>;

            if listp temp2 and car temp2 = 'expt then
            << alpha2 := caddr temp2;
               expt_flag := 't>>;

            if alpha1 neq 'nil then

     alpha := reval algebraic(alpha1 + beta*alpha2)
            else alpha := alpha2;
         >>;

      >>

      else
      << if i = 'expt then
         << alpha := caddr var;
            expt_flag := 't>>;
      >>;
   >>;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

   if expt_flag = nil then
       return u . v

% Otherwise reduce the power by using the following formula :-
%
%   infinity                  infinity
%  /                         /
%  |                       n |
%  |t^alpha*F(t^(m/n))dt = - |z^[((alpha + 1)*n - m)/m]*F(z)dz
%  |                       m |
%  /                         /
% 0                         0

   else

   << if listp alpha then
      << m := cadr alpha;
         n := caddr alpha;
         n := reval algebraic(beta*n)>>

      else
      << m := alpha;
         n := beta>>;

      k := reval algebraic(((k + 1)*n - m)/m);
      coef := reval algebraic((n/m)*coef);
      var := reval algebraic(var^(n/m));

      return {k,car v,cadr v, caddr v,coef,var}>>;

>>;


end;

symbolic procedure test_1(aa,u,v);

% Check validity of the following formulae :=
%
% -min Re{bj} < Re{s} < 1 - max Re{ai}    i=1..n, j=1..m
% -min Re{bj} < Re{s} < 1 - max Re{ai}    i=1..n, j=1..p
%
% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 page 157 (3) & (3*)

begin scalar s,m,n,a,b,ai,bj,a_max,b_min,temp,temp1,
                !*rounded,dmode!*;

off rounded;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< s := algebraic(repart(1 + u));
   s := simp!* s;

   m := caar v;
   n := cadar v;

   a := cadr v;
   b := caddr v;

   if aa = nil then
   << for i := 1 :n do

      << if car a = 'nil then
              car a := 0;
          ai := append(ai,{car a});
         a := cdr a>>;


      if ai neq 'nil then
      << a_max := simpmax list('list . ai);
         a_max := simprepart list(list('!*sq,a_max,t))>>;

   >>

   else if aa = 'a then

   << if a neq 'nil then
      << a_max := simpmax list('list . a);
         a_max := simprepart list(list('!*sq,a_max,t))>>;
   >>;


   for j := 1 :m do

   << if car b = 'nil then
          car b := 0;
      bj := append(bj,{car b});
      b := cdr b>>;

   if bj neq 'nil then
   << b_min := simpmin list('list . bj);
      b_min := simprepart list(list('!*sq,negsq(b_min),t))>>;


   if a_max neq nil and b_min neq nil then

   << temp := subtrsq(s,diffsq(a_max,1));
      temp1 := subtrsq(b_min,s);

      if car temp = 'nil or car temp1 = 'nil
       or car temp > 0 or car temp1> 0 then
          return 'fail

      else
          return test2(s,cadr v,caddr v)>>

   else if a_max = nil then

   << temp := subtrsq(b_min,s);

      if car temp = 'nil or car temp > 0 then
          return 'fail

       else
          return 't>>

   else if b_min = nil then

   << temp :=  subtrsq(s,diffsq(a_max,1));

      if car temp = 'nil or car temp > 0 then
          return 'fail

      else
          return 't>>;

>>

else
<< transform_lst := cons (('tst1 . '(list 'lessp (list 'lessp
        (list 'minus
                (list 'min (list 'repart 'bj))) (list 'repart 's))
        (list 'difference 1
                (list 'max(list 'repart 'ai))))),transform_lst);

   return 't>>;

end;


symbolic procedure test2(s,a,b);

% Check validity of the following formula :=
%
% Re{Sum(ai) - Sum(bj)} + 1/2 * (q + 1 - p) > (q - p) * Re{s}
%                                                        i=1..p, j=1..q
% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 page 157 (4)

begin scalar s,p,q,sum_a,sum_b,diff_sum,temp1,temp2,temp,diff;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< s := algebraic(repart(1 + s));

   p := length a;
   q := length b;

   for each i in a do << sum_a := reval algebraic(sum_a + i)>>;

   for each j in b do << sum_b := reval algebraic(sum_b + j)>>;

   diff_sum := reval algebraic(repart(sum_a - sum_b));

   temp := reval algebraic(1/2*(q + 1 - p));
   temp1 := reval algebraic(diff_sum + temp);
   temp2 := reval algebraic((q-p)*s);
   diff := simp!* reval algebraic(temp1 - temp2);

   if car diff ='nil then return 'fail

   else if car diff < 0 then return 'fail else return t>>

else
<< transform_lst := cons (('tst2 . '(list 'greaterp (list 'plus
        (list 'repart (list 'difference (list 'sum 'ai)(list 'sum 'bj)))
        (list 'times (list 'quotient 1 2)
        (list 'plus 'q (list 'difference 1 'p)))) (list 'times
        (list 'difference 'q 'p) (list 'repart 's)))),
         transform_lst);

   return 't;

>>;

end;


symbolic procedure validity_check(s1,s2,u3);

% Check validity of the following formulae :=
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (1) - (15)


begin scalar alpha,m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,r,a,b,c,d,
         b_sum,a_sum,d_sum,c_sum,mu,rho,phi,eta,r1,r2,
         test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
         test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15,
         test;

transform_lst := '();

alpha := reval algebraic(1 + u3);

m := caadr s1;
n := cadadr s1;
p := car cddadr s1;
q := cadr cddadr s1;

epsilon := reval algebraic(m + n - 1/2*(p + q));

k := caadr s2;
l := cadadr s2;
u := car cddadr s2;
v := cadr cddadr s2;

delta := reval algebraic(k + l -1/2*(u + v));

sigma := prepsq caar s1;
omega := prepsq caar s2;

r := prepsq cadar s2;

a := caddr s1;
b := cadddr s1;
c := caddr s2;
d := cadddr s2;

for each i in b do
        << i := prepsq i; b_sum := reval algebraic(b_sum + i)>>;

for each j in a do
        << j := prepsq j; a_sum := reval algebraic(a_sum + j)>>;

for each i in d do
        << i := prepsq i; d_sum := reval algebraic(d_sum + i)>>;

for each j in c do
        << j := prepsq j; c_sum := reval algebraic(c_sum + j)>>;

mu := reval algebraic(b_sum - a_sum + 1/2*(p - q) + 1);
rho := reval algebraic(d_sum - c_sum + 1/2(u - v) + 1);

phi := reval algebraic(q - p - r*(v - u));
eta := reval algebraic(1 - alpha*(v - u) - mu - rho);


if listp r then << r1 := symbolic(cadr r); r2 := symbolic(caddr r)>>
else            << r1 := r; r2 := 1>>;

test_1a := tst1a(m,n,a,b);
test_1b := tst1b(k,l,c,d);
test_2 := tst2(m,k,b,d,alpha,r);
test_3 := tst3(n,l,a,c,alpha,r);
test_4 := tst4(l,p,q,c,alpha,r,mu);
test_5 := tst5(k,p,q,d,alpha,r,mu);
test_6 := tst6(n,u,v,a,alpha,r,rho);
test_7 := tst7(m,u,v,b,alpha,r,rho);
test_8 := tst8(p,q,u,v,alpha,r,mu,rho,phi);
test_9 := tst9(p,q,u,v,alpha,r,mu,rho,phi);
test_10 := tst10(sigma,delta);
test_11 := tst11(sigma,delta);
test_12 := tst12(omega,epsilon);
test_13 := tst13(omega,epsilon);
test_14 := tst14(u,v,alpha,mu,rho,delta,epsilon,sigma,omega,r,phi,r1,
                  r2);
if p = q or u = v then test_15 := 'fail
        else test_15 := tst15(m,n,p,q,k,l,u,v,sigma,omega,eta);

test := {'test_cases2,m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,
   eta,mu,r1,r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
   test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
   test_15};

test := reval test;

if transform_tst = t and spec_cond neq nil then test := t;
return test;
end;


symbolic procedure tst1a(m,n,a,b);

% Check validity of the following formula :=
%
%  ai - bj neq 1,2,3,....         i=1..n, j=1..m
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (1)

begin scalar a_new,b_new,temp,fail_test;

for i := 1 :n do << a_new := append(a_new,{car a}); a := cdr a>>;

for j := 1 :m do << b_new := append(b_new,{car b}); b := cdr b>>;

for each i in a_new do
<< for each j in b_new do
   << temp := subtrsq(i,j);
      if car temp neq 'nil and car temp > 0
          and cdr temp = 1 then
          fail_test := t>>;
>>;
if fail_test = t then return 'fail else return t;
end;

symbolic procedure tst1b(k,l,c,d);

% Check validity of the following formula :=
%
%  ci - dj neq 1,2,3,....         i=1..l, j=1..k
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (1)

begin scalar c_new,d_new,temp,fail_test;

for i := 1 :l do << c_new := append(c_new,{car c}); c := cdr c>>;

for j := 1 :k do << d_new := append(d_new,{car d}); d := cdr d>>;

for each i in c_new do
<< for each j in d_new do
   << temp := subtrsq(i,j);
      if car temp neq 'nil and car temp > 0
          and cdr temp = 1 then
          fail_test := t>>;
>>;
if fail_test = t then return 'fail else return t;
end;

symbolic procedure tst2(m,k,b,d,alpha,r);

% Check validity of the following formula :=
%
%  Re{alpha + r*bi + dj} > 0                 i=1..m, j=1..k
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (2)

begin scalar b_new,d_new,temp,temp1,temp2,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq t then

<< for i := 1 :m do
   << temp1 := prepsq car b;
      b_new := append(b_new,{temp1});
      b := cdr b>>;

   for j := 1 :k do
   << temp2  := prepsq car d;
      d_new := append(d_new,{temp2});
      d := cdr d>>;

   for each k in b_new do
   << for each h in d_new do
      << temp := simp!* reval algebraic(repart(alpha + r*k + h));
         if car temp = 'nil or car temp < 0 then
             fail_test := 't>>;
   >>;
   if fail_test = t then return 'fail else return t>>
else
<< transform_lst := cons (('test2 . '(list 'greaterp
  (list 'repart (list 'plus 'alpha (list 'times 'r 'bi) 'dj))
   0)),transform_lst);
   return t>>;
end;

symbolic procedure tst3(n,l,a,c,alpha,r);

% Check validity of the following formula :=
%
%  Re{alpha + r*ai + cj} < r + 1                  i=1..n, j=1..l
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (3)

begin scalar a_new,c_new,temp,temp1,temp2,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< for i := 1 :n do
   << temp1 := prepsq car a;
      a_new := append(a_new,{temp1});
      a := cdr a>>;

   for j := 1 :l do
   << temp2 := prepsq car c;
      c_new := append(c_new,{temp2});
      c := cdr c>>;

   for each k in a_new do
   << for each h in c_new do
      << temp := simp!* reval algebraic(repart(alpha + r*k + h)- r -1);
         if car temp = 'nil or car temp > 0 then
             fail_test := 't>>;
   >>;
   if fail_test = 't then return 'fail else return t>>
else

<< transform_lst := cons (('test3 . '(list 'lessp (list 'repart
  (list 'plus 'alpha (list 'times 'r 'ai) 'cj)) (list 'plus 'r 1))),
     transform_lst);
   return 't>>;
end;

symbolic procedure tst4(l,p,q,c,alpha,r,mu);

% Check validity of the following formula :=
%
%  (p - q)*Re{alpha + cj - 1} - r*Re{mu} > -3*r/2         j=1..l
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (4)

begin scalar c_new,temp1,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then
<< for j := 1 :l do
   << temp1 := prepsq car c;
      c_new := append(c_new,{temp1});
      c := cdr c>>;

   for each i in c_new do
   << temp := simp!* reval algebraic((p - q)*repart(alpha + i - 1)
                                       - r*repart(mu) + 3/2*r);
      if car temp = 'nil or car temp < 0 then fail_test := t;
   >>;

   if fail_test = t then return 'fail else return t>>
else
<< transform_lst := cons (('test4 . '(list 'greaterp (list 'difference
 (list 'times (list 'difference 'p 'q) (list 'repart (list 'plus 'alpha
 (list 'difference 'cj 1)))) (list 'times 'r (list 'repart (list 'plus
 (list 'difference (list 'sum 'bj) (list 'sum 'ai))
 (list 'times (list 'quotient 1 2) (list 'difference 'p 'q)) 1))))
 (list 'minus (list 'times 3 (list 'quotient 'r 2))))),transform_lst);
   return 't>>;

end;

symbolic procedure tst5(k,p,q,d,alpha,r,mu);

% Check validity of the following formula :=
%
%  (p - q)*Re{alpha + dj} - r*Re{mu} > -3*r/2         j=1..k
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (5)

begin scalar d_new,temp1,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq t then

<< for j := 1 :k do
   << temp1 := prepsq car d;
      d_new := append(d_new,{temp1});
      d := cdr d>>;

   for each i in d_new do

   << temp := simp!* reval algebraic((p - q)*repart(alpha + i)
                                       - r*repart(mu) + 3/2*r);
      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

   if fail_test = t then return 'fail else return t>>
else
<< transform_lst := cons (('test5 .'(list 'greaterp (list 'difference
   (list 'times(list 'difference 'p 'q)
   (list 'repart (list 'plus 'alpha 'dj)))
   (list 'times 'r (list 'repart (list 'plus (list 'difference
   (list 'sum 'bj) (list 'sum 'ai)) (list 'quotient
   (list 'difference 'p 'q) 2) 1))))
   (list 'minus (list 'times 3 (list 'quotient 'r 2)))) ),
   transform_lst);
   return t>>;
end;

symbolic procedure tst6(n,u,v,a,alpha,r,rho);

% Check validity of the following formula :=
%
%  (u - v)*Re{alpha + r*ai - r} - Re{rho} > -3/2         i=1..n
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (6)

begin scalar a_new,temp1,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then
<< for j := 1 :n do

   << temp1 := prepsq car a;
      a_new := append(a_new,{temp1});
      a := cdr a>>;

   for each i in a_new do

   << temp := simp!* reval algebraic((u - v)*repart(alpha + r*i - r)
                                               - repart(rho) + 3/2);
      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

  if fail_test = 't then return 'fail else return 't>>
else
<< transform_lst := cons (('test6 . '(list 'greaterp (list 'difference
  (list 'times (list 'difference 'u 'v) (list 'repart
  (list 'plus 'alpha (list 'difference (list 'times 'r 'ai) 'r))))
  (list 'repart (list 'plus (list 'difference (list 'sum 'dj)
  (list 'sum 'ci)) (list 'times (list 'quotient 1 2)
  (list 'difference 'u 'v)) 1))) (list 'minus (list 'quotient 3 2)))),
  transform_lst);
   return 't>>;
end;

symbolic procedure tst7(m,u,v,b,alpha,r,rho);

% Check validity of the following formula :=
%
%  (u - v)*Re{alpha + r*bi} - Re{rho} > -3/2         i=1..m
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (7)

begin scalar b_new,temp1,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< for j := 1 :m do
   << temp1 := prepsq car b;
      b_new := append(b_new,{temp1});
      b := cdr b>>;

   for each i in b_new do

   << temp := simp!* reval algebraic((u - v)*repart(alpha + r*i)
                                               - repart(rho) + 3/2);

      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

   if fail_test = t then return 'fail else return t>>
else

<< transform_lst := cons (('test7 . '(list 'greaterp (list 'difference
   (list 'times (list 'difference 'u 'v)
   (list 'repart (list 'plus 'alpha (list 'times 'r 'bi))) )
   (list 'repart (list 'plus (list 'difference (list 'sum 'dj)
   (list 'sum 'ci)) (list 'quotient (list 'difference 'u 'v) 2)1)))
   (list 'minus (list 'quotient 3 2)))),transform_lst);
   return 't>>;
end;

symbolic procedure tst8(p,q,u,v,alpha,r,mu,rho,phi);

% Check validity of the following formula :=
%
% abs(phi) + 2*Re{(q - p)*(v - u)*alpha +
%                     r*(v - u)*(mu - 1) + (q - p)*(rho - 1)} > 0
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (8)

begin scalar sum,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< sum := reval algebraic(2*repart((q - p)*(v - u)*alpha
                     + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)));

   temp := simp!* reval algebraic(abs phi + sum);
   if car temp = 'nil or car temp < 0 then fail_test := 't;
   if fail_test = t then return 'fail else return t>>

else

<< transform_lst := cons (('test8 . '(list 'greaterp (list 'plus
  (list 'abs (list 'difference (list 'difference 'q 'p)
  (list 'times 'r (list 'difference 'v 'u))))
  (list 'times 2 (list 'repart (list 'plus
  (list 'times (list 'difference 'q 'p) (list 'difference 'v 'u)
  'alpha) (list 'times 'r (list 'difference 'v 'u)
  (list 'plus (list 'difference (list 'sum 'bj) (list 'sum 'ai))
  (list 'quotient (list 'difference 'p 'q) 2)))
  (list 'times (list 'difference 'q 'p) (list 'plus
  (list 'difference (list 'sum 'dj) (list 'sum 'ci))
  (list 'quotient (list 'difference 'u 'v) 2)))) )))
  0)),transform_lst);
   return 't>>;

end;

symbolic procedure tst9(p,q,u,v,alpha,r,mu,rho,phi);

% Check validity of the following formula :=
%
% abs(phi) - 2*Re{(q - p)*(v - u)*alpha +
%                     r*(v - u)*(mu - 1) + (q - p)*(rho - 1)} > 0
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (9)

begin scalar sum,temp,fail_test;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< sum := reval algebraic(2*repart((q - p)*(v - u)*alpha
                     + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)));

   temp := simp!* reval algebraic(abs phi - sum);

   if car temp = 'nil or car temp < 0 then fail_test := 't;

   if fail_test = t then return 'fail else return t>>
else

<< transform_lst := cons (('test9 . '(list 'greaterp (list 'difference
  (list 'abs (list 'difference (list 'difference 'q 'p)
  (list 'times 'r (list 'difference 'v 'u))))
  (list 'times 2 (list 'repart (list 'plus
  (list 'times (list 'difference 'q 'p) (list 'difference 'v 'u)
  'alpha) (list 'times 'r (list 'difference 'v 'u)
  (list 'plus (list 'difference (list 'sum 'bj) (list 'sum 'ai))
  (list 'quotient (list 'difference 'p 'q) 2)))
  (list 'times (list 'difference 'q 'p) (list 'plus
  (list 'difference (list 'sum 'dj) (list 'sum 'ci))
  (list 'quotient (list 'difference 'u 'v) 2)))) )))
  0)),transform_lst);
   return 't>>;

end;

algebraic procedure tst10(sigma,delta);

% Check validity of the following formula :=
%
% abs(arg sigma) < delta*pi
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (10)

begin scalar arg_sigma,pro,temp,fail_test,!*rounded,dmode!*;

if transform_tst neq 't then

<< on rounded;
   arg_sigma := abs(atan(impart sigma/repart sigma));
   pro :=  delta*pi;
   temp :=  pro - arg_sigma;
   if  numberp temp and temp <= 0 then fail_test := t;

   off rounded;

   if fail_test = t then return reval 'fail else return reval t>>

else

<<symbolic(transform_lst := cons (('test10 .
'(list 'lessp (list 'abs (list 'arg 'sigma))
(list 'times (list 'plus 'k (list 'difference 'l (list 'quotient
(list 'plus 'u 'v) 2))) 'pi))),transform_lst));
   return reval 't>>;

end;

algebraic procedure tst11(sigma,delta);

% Check validity of the following formula :=
%
% abs(arg sigma) = delta*pi
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (11)

begin scalar arg_sigma,pro,fail_test;

if transform_tst neq 't then

<< arg_sigma := abs(atan(impart sigma/repart sigma));
   pro := delta*pi;
   if arg_sigma neq pro then fail_test := 't;
   if fail_test = 't then return reval 'fail else return reval 't>>
else

<< symbolic(transform_lst := cons (('test11 .
'(list 'equal (list 'abs (list 'arg 'sigma))
 (list 'times (list 'plus 'k (list 'difference 'l (list 'quotient
(list 'plus 'u 'v) 2))) 'pi))),transform_lst));
   return reval 't>>;

end;

algebraic procedure tst12(omega,epsilon);

% Check validity of the following formula :=
%
% abs(arg omega) < epsilon*pi
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (12)

begin scalar arg_omega,pro,temp,fail_test,!*rounded,dmode!*;

if transform_tst neq 't then

<< on rounded;

   arg_omega := abs(atan(impart omega/repart omega));
   pro := epsilon*pi;
   temp := pro - arg_omega;
   if numberp temp and temp <= 0 then fail_test := 't;

   off rounded;

   if fail_test = 't then return reval 'fail else return reval 't>>

else

<< symbolic(transform_lst := cons (('test12 .
'(list 'lessp (list 'abs (list 'arg 'omega))
(list 'times (list 'plus 'm (list 'difference 'n
(list 'times (list 'quotient 1 2) (list 'plus 'p 'q))))
'pi))),transform_lst));
   return reval 't>>;

end;

algebraic procedure tst13(omega,epsilon);

% Check validity of the following formula :=
%
% abs(arg omega) = epsilon*pi
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (13)

begin scalar arg_omega,pro,fail_test;

if transform_tst neq 't then

<< arg_omega := abs(atan(impart omega/repart omega));
   pro := epsilon*pi;
   if arg_omega neq pro then fail_test := 't;
   if fail_test = t then return reval 'fail else return reval 't>>
else

<< symbolic(transform_lst := cons (('test13 .
'(list 'equal (list 'abs (list 'arg 'omega))
(list 'times (list 'plus 'm (list 'difference 'n
(list 'times (list 'quotient 1 2) (list 'plus 'p 'q))))
'pi))),transform_lst));
   return reval 't>>;
end;

algebraic procedure tst14(u,v,alpha,mu,rho,delta,epsilon,sigma,omega,
                                                         r,phi,r1,r2);
% Check validity of the following formula :=
%
%  abs(arg(1 - z*sigma^(-r1)*omega^r2)) < pi
%
%     when phi = 0 and epsilon + r*(delta - 1) <= 0
%
%  where z = r^[r1*(v - u)]*exp[-(r1*delta + r2*epsilon)*pi*i]
%
%   or z = sigma^r1*omega^(-r2)
%     when Re{mu + rho + alpha*(v - u)}
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (14)

begin scalar temp,z,arg,arg_test,!*rounded,dmode!*;

if transform_tst neq 't then

<< on rounded;

   temp := epsilon + r *(delta - 1);
   if phi = 0 and temp <= 0 then
       z := r^(r2*(v - u))*e^(-(r2*delta+r1*epsilon)*pi*i)

   else if numberp (mu + rho + alpha*(v - u)) and
                        repart(mu + rho + alpha*(v - u)) < 1 then
       z := sigma^r2*omega^(-r1)
   else return reval 'fail; % Wn
   arg := 1 - z*sigma^(-r2)*omega^r1;

   if arg = 0 then arg_test := 0
   else  arg_test := abs(atan(impart arg/repart arg));

   if numberp arg_test and arg_test < pi then
                << off rounded; return reval 't>>
   else         << off rounded; return reval 'fail>>;
>>

else
<< symbolic(transform_lst := cons (('test14 .'(list 'or (list 'and
  (list 'abs (list 'arg (list 'difference 1 (list 'times
  (list 'times (list 'expt 'r (list 'times 'r1
  (list 'difference 'v 'u))) (list 'exp (list 'minus
  (list 'times (list 'plus (list 'times 'r1 (list 'plus 'k
  (list 'difference 'l (list 'times (list 'quotient 1 2)
  (list 'plus 'u 'v)))) ) (list 'times 'r2 (list 'plus 'm
  (list 'difference 'n (list 'times (list 'quotient 1 2)
  (list 'difference 'p 'q)))) )) 'pi 'i))))
  (list 'expt 'sigma (list 'minus 'r1)) (list 'expt 'omega 'r2)))) )
  (list 'equal 'phi 0) (list 'leq (list 'plus 'k (list 'difference 'l
  (list 'times (list 'quotient 1 2) (list 'plus 'u 'v)))
  (list 'times 'r (list 'plus 'm (list 'difference (list 'difference 'n
  (list 'times (list 'quotient 1 2) (list 'plus 'p 'q))) 1)))) 0))
  (list 'and (list 'lessp (list 'repart (list 'plus
  (list 'difference (list 'sum 'bj) (list 'sum 'ai))
  (list 'times (list 'quotient 1 2) (list 'difference 'p 'q)) 1
  (list 'difference (list 'sum 'dj) (list 'sum 'ci))
  (list 'times (list 'quotient 1 2) (list 'difference 'u 'v)) 1
  (list 'times 'alpha (list 'difference 'v 'u)))) 0)
  (list 'equal 'phi 0) (list 'leq (list 'plus 'k (list 'difference 'l
  (list 'times (list 'quotient 1 2) (list 'plus 'u 'v)))
  (list 'times 'r (list 'plus 'm (list 'difference (list 'difference 'n
  (list 'times (list 'quotient 1 2) (list 'plus 'p 'q))) 1)))) 0)))),
                                        transform_lst));

   return reval 't>>;

end;

algebraic procedure tst15(m,n,p,q,k,l,u,v,sigma,omega,eta);

% Check validity of the following formula :=
%
% lambda_c > 0 or lambda_c = 0 and lambda_s neq 0 and Re{eta} > -1
%     or lambda_c = 0 and lambda_s = 0 and Re{eta} > 0
%
%   psi = [abs(arg(omega)) + (q - m - n)*pi]/(q - p)
%   theta = [abs(arg(sigma)) + (v - s - t)*pi]/(v - u)
%
%  where lambda_c = (q - p)*abs(omega)^[1/(q - p)]*cos psi +
%               (v - u)*abs(omega)^[1/(v - u)]*cos theta
%
%  and when arg sigma * arg omega neq 0
%
%   lambda_s =(q - p)*abs(omega)^[1/(q - p)]*sgn(arg omega)*sin psi +
%           (v - u)*abs(sigma)^[1/(v - u)]*sgn(arg sigma)*sin theta
%
%  or when arg sigma = 0 and arg omega neq 0
%
%   lambda_s = limit lambda_s * limit lambda_s
%             sigma -> +0      sigma -> -0
%
%  or when arg sigma neq 0 and arg omega = 0
%
%   lambda_s = limit lambda_s * limit lambda_s
%             omega -> +0      omega -> -0
%
%  or when arg sigma = 0 and arg omega = 0
%
%   lambda_s = limit lambda_s * limit lambda_s
%             omega -> +0      omega -> +0
%             sigma -> +0      sigma -> -0
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1
%  page 345  (15)

begin scalar lc,ls,temp_ls,psi,theta,arg_omega,arg_sigma,
        !*rounded,dmode!*;

if transform_tst neq 't then

<< arg_omega := atan(impart omega/repart omega);
   arg_sigma := atan(impart sigma/repart sigma);

   psi := (abs arg_omega + (q - m - n)*pi)/(q - p);
   theta := (abs arg_sigma + (v - k - l)*pi)/(v - u);


   lc := (q - p)*abs(omega)^(1/(q - p))*cos psi +
                             (v - u)*abs(sigma)^(1/(v - u))*cos theta;

   lc := lc;
   temp_ls := (q - p)*abs(omega)^(1/(q - p))*sign(arg_omega)*sin psi +
          (v - u)*abs(sigma)^(1/(v - u))*sign(arg_sigma)*sin theta;

   if arg_sigma*arg_omega neq 0 then ls := temp_ls

   else if arg_sigma = 0 and arg_omega neq 0 then
       ls := limit!+(temp_ls,sigma,0)*limit!-(temp_ls,sigma,0)

   else if arg_omega = 0 and arg_sigma neq 0 then
       ls := limit!+(temp_ls,omega,0)*limit!-(temp_ls,omega,0)

   else ls := limit!+(limit!+(temp_ls,omega,0),sigma,0)*
                limit!-(limit!+(temp_ls,omega,0),sigma,0);

   on rounded;
   if (numberp lc and lc > 0) or lc = 0 and ls = 0 and repart eta > -1
                  or lc = 0 and ls = 0 and repart eta > 0 then
   << off rounded; return reval 't>>

   else         << off rounded; return reval 'fail>>
>>

else
<< symbolic(transform_lst := cons (('test15 . '(list 'or
(list 'greaterp 'lambda_c 0) (list 'and (list 'equal 'lambda_c 0)
(list 'neq 'lambda_s 0) (list 'greaterp (list 'repart 'eta)
(list 'minus 1))) (list 'and (list 'equal 'lambda_c 0)
(list 'equal 'lambda_s 0) (list 'greaterp (list 'repart 'eta) 0)))),
                                        transform_lst));
return reval 't>>;

end;

symbolic procedure bastab(u,v);
 if u eq 'f1 then subpar(get('f1,'g),v) else
 if u eq 'f2 then subpar(get('f2,'g),v)$

symbolic procedure subpar(u,v);
if null v then list(cadr u,caddr u, cadddr u,car cddddr u,
                    cadr cddddr u)
  else list(cadr u,sublist1(caddr u,v,car u),
          sublist1(cadddr u,v,car u),
          subpref1(car cddddr u,v,car u),cadr cddddr u)$

symbolic procedure sublist1(u,v,z);
 % u,v,z - list PF.
 if null cdr v or null cdr z then sublist(u,car v,car z)
   else
    sublist1(
      sublist(u,car v,car z),
      cdr v,cdr z)$

symbolic procedure subpref1(u,v,z);
% u - pf
% v,z - list pf
 if null cdr v or null cdr z then subpref(u,car v,car z)
   else subpref(subpref1(u,cdr v,cdr z),car v,car z)$

symbolic procedure subpref(u,v,z);
% u,v,z - pf
 prepsq subsqnew(simp!* u,simp!* v,z)$

symbolic procedure sublist(u,v,z);
% u - list pf
% v,z - pf
if null u then nil else
     subpref(car u,v,z) . sublist(cdr u,v,z)$

symbolic procedure trpar(u1,u2,u3);
  if not numberp u2 and not atom u2 and car(u2)='plus then 'fail else
  begin scalar a!3,l!1,v1,v2,v3,v4;
   if (v1:=dubdeg(car simp u1,'x))='fail or
           (v2:=dubdeg(cdr simp u1,'x))='fail or
           (v3:=dubdeg(car simp u2,u3))='fail or
           (v4:=dubdeg(cdr simp u2,u3))='fail then return 'fail;
   a!3:=multsq(diff1sq(v1,v2), diff1sq(v3,v4));
   l!1:=subpref(u1,u2,'x);
   l!1:=subpref(l!1,1,u3);
   return list(simp!*(l!1),a!3);
  end$

symbolic procedure modintgg(u1,u2,u3);
 list(
    multsq(u1,invsq gr u2),
    change(u2,list(cons(gw u2,list '(1 . 1))),'(1)),
    change(u3,list(cons(gw u3,list(quotsq(gr u3,gr u2)))),'(1)))$

symbolic procedure change(u1,u2,u3);
 begin scalar v;integer k;
  while u1 do begin
   if u3 and car u3=(k:=k+1) then
            << v:=append(v,list car u2);
               if u2 then u2:=cdr u2;
               if u3 then u3:=cdr u3
            >>
     else
      v:=append(v,list car u1);
   u1:=cdr u1;
   if null u3 then << v:= append(v,u1); u1:= nil>>; %WN
  end;
  return v;
end$

symbolic procedure cong(u);
 list(
   list(invsq gw u,negsq gr u),
   list(gn u,gm u,gq u,gp u),
   difflist(listmin gb u,'(-1 . 1)),
   difflist(listmin ga u,'(-1 . 1)))$

symbolic procedure modintg(u1,u2);
 list(
  multsq(u1,invsq gr u2),
  change(u2,
    list(
      cons(gw u2,list '(1 . 1))),'(1)))$

symbolic procedure ccgf(u);
  quotsq(
     simp(2 * gm u + 2 * gn u - gp u - gq u),
     '(2 . 1))$

symbolic procedure vgg(u1,u2);
  diff1sq(
     simp(gq u2 - gp u2),
     multsq(gr u2,simp(gq u1 - gp u1)))$

symbolic procedure nugg(u1,u2,u3);
  diff1sq( diff1sq('(1 . 1), multsq(u3, simp(gq u1 - gp u1))),
           addsq(mugf u2,mugf u1))$

symbolic smacro procedure sumlistsq(u);
<< for each pp in u do <<p := addsq(pp,p)>>; p>> where p = '(nil . 1);

symbolic procedure mugf(u);
  addsq(
     quotsq(simp(2 + gp u - gq u),'(2 . 1)),
     addsq(sumlistsq gb u,negsq sumlistsq ga u))$

symbolic procedure coefintg(u1,u2,u3);
  multlist(
   list(
     expdeg(gk u2 . 1,mugf u2),
     expdeg(gl u2 . 1,
       addsq(mugf u1,
         diff1sq(
            multsq(u3,(gq u1-gp u1) . 1),
            '(1 . 1)))),
     expdeg(gw u1,negsq u3),
     expdeg(simp '(times 2 pi),
       addsq(multsq(ccgf u1,(1-gl u2) . 1),
             multsq(ccgf u2,(1-gk u2) . 1)))))$

symbolic procedure deltagg(u1,u2,u3);
  list(
     append( delta(car redpar1(ga u2,gn u2), gk u2),
      append(
        delta( difflist( listmin gb u1, addsq(u3,'(-1 . 1))), gl u2),
        delta( cdr redpar1(ga u2,gn u2), gk u2))),
     append( delta(car redpar1(gb u2,gm u2), gk u2),
      append(delta( difflist(listmin ga u1,addsq(u3,'(-1 . 1))),gl u2),
        delta( cdr redpar1(gb u2,gm u2), gk u2))))$

symbolic procedure redpargf(u);
 begin scalar v1,v2;
  v1:=redpar(car redpar1(gb u,gm u), cdr redpar1(ga u,gn u));
  v2:=redpar(cdr redpar1(gb u,gm u), car redpar1(ga u,gn u));

  return
    list(car u, (cadr v2 . cadr v1), (car v1 . car v2));

end$

symbolic procedure arggf(u1,u2);

% Calculate the coefficient of the variable in the combined meijerg
% function

 multlist(list(
     expdeg(gw u2, gk u2 . 1),
     expdeg(gk u2 . 1, (gk u2 * gp u2 - gk u2 * gq u2) . 1),
     invsq(expdeg(gw u1, gl u2 . 1)),
     expdeg(gl u2 . 1,(gl u2 * gq u1 - gl u2 * gp u1) . 1)))$

symbolic procedure indgf(u1,u2);

% Calculate the values of m,n,p,q of the combined meijerg function

 list(gk u2 * gm u2 + gl u2 * gn u1,
      gk u2 * gn u2 + gl u2 * gm u1,
      gk u2 * gp u2 + gl u2 * gq u1,
      gk u2 * gq u2 + gl u2 * gp u1)$

symbolic procedure dubdeg(x,y);
% x -- SF.
% y -- atom.
begin scalar c,b,a1,a3;
if numberp x or null x then return '(nil . 1);
if not null cdr(x) then return 'fail;
lb1: a1:=caar x;a3:=car a1;
  if atom a3 and a3=y then b:=cdr a1 . 1 ;
  if not atom a3 then
    if cadr a3=y then
     if null cddr(a3) then return 'fail else
       if not nump(simp caddr a3) then return simp(caddr a3)
                                else
          c:=times(cdr a1,cadr caddr a3).caddr caddr a3;
  if atom cdar x then
    if null b then
      if null c then return '(nil . 1)
      else return c
    else
    if null c then return b
    else return plus(times(car b,cdr c),car c).cdr c;
  x:=cdar x;go to lb1;
end$

symbolic procedure delta(u,n);
  % u -- list of sq.
  % n -- number.
  if null u then nil else
    append(if n=1 then list car u else
             delta0(quotsq(car u,simp!* n),n,n)
          ,delta(cdr u,n))$

symbolic procedure delta0(u,n,k);
  % u -- SQ.
  % n,k -- numbers.
   if k=0 then nil else
       u . delta0(addsq(u,invsq(simp!* n)),n,k-1)$

symbolic procedure nump(x);
 or(null car x,and(numberp car x,numberp cdr x))$


endmodule;


module defintc;

fluid '(mellin!-transforms!* mellin!-coefficients!*);

symbolic (mellin!-transforms!* :=mkvect(200))$

symbolic putv(mellin!-transforms!*,0,'(1 . 1)); % undefined case
symbolic putv(mellin!-transforms!*,1,'(() (1 0 0 1) () (nil) 1 x));

     % trigonometric functions

symbolic putv(mellin!-transforms!*,2,'
    (() (1 0 0 2) () ((quotient 1 2) nil)
    (sqrt pi) (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,25,'
    (() (1 0 0 2) () ((quotient 1 2) nil)
    (minus (sqrt pi)) (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,3,'
    (() (1 0 0 2) () (nil (quotient 1 2))
   (sqrt pi) (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,7,'
    (() (2 0 2 2) (1 1) (nil (quotient 1 2))
    (quotient (sqrt pi) 2) (expt x 2)));

symbolic putv(mellin!-transforms!*,8,'
    (() (0 2 2 2) ((quotient 1 2) 1) (nil nil)
    (quotient (sqrt pi) 2) (expt x 2)));

symbolic putv(mellin!-transforms!*,9,'
    (() (1 2 2 2) ((quotient 1 2) 1) ((quotient 1 2) nil)
    (quotient 1 2) (expt x 2)));

     % hyperbolic functions

symbolic putv(mellin!-transforms!*,10,'
    (() (1 0 1 3) (1) ((quotient 1 2) 1 nil)
    (expt pi (quotient 3 2)) (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,11,'
    (() (1 0 1 3) ((quotient 1 2)) (nil (quotient 1 2) (quotient 1 2))
    (expt pi (quotient 3 2)) (quotient (expt x 2) 4)));


     % the Heavisides

symbolic putv(mellin!-transforms!*,30,'(() (1 0 1 1) (1) (nil) 1 x));

symbolic putv(mellin!-transforms!*,31,'(() (0 1 1 1) (1) (nil) 1 x));

symbolic putv(mellin!-transforms!*,32,'
    (() (2 0 2 2) (1 1) (nil nil) -1 x));

symbolic putv(mellin!-transforms!*,33,'
    (() (0 2 2 2) (1 1) (nil nil) 1 x));

symbolic putv(mellin!-transforms!*,34,'
    (() (1 2 2 2) (1 1) (1 nil) 1 x));

symbolic putv(mellin!-transforms!*,35,'
    (() (2 1 2 2) (nil 1) (nil nil) 1 x));


     % exponential integral

symbolic putv(mellin!-transforms!*,36,'
    (() (2 0 1 2) (1) (nil nil) -1 x));

     % sin integral

symbolic putv(mellin!-transforms!*,37,'
    (() (1 1 1 3) (1) ((quotient 1 2) nil nil)
    (quotient (sqrt pi) 2) (quotient (expt x 2) 4)));

     % cos integral

symbolic putv(mellin!-transforms!*,38,'
    (() (2 0 1 3) (1) (nil nil (quotient 1 2))
    (quotient (sqrt pi) -2) (quotient (expt x 2) 4)));

     % sinh integral

symbolic putv(mellin!-transforms!*,39,'
    (() (1 1 2 4) (1 nil) ((quotient 1 2) nil nil nil)
    (quotient (expt pi (quotient 3 2)) -2) (quotient (expt x 2) 4)));


     % error functions

symbolic putv(mellin!-transforms!*,41,'
    (() (1 1 1 2) (1) ((quotient 1 2) nil)
    (quotient 1 (sqrt pi)) (expt x 2)));

symbolic putv(mellin!-transforms!*,42,'
    (() (2 0 1 2) (1) (nil (quotient 1 2))
    (quotient 1 (sqrt pi)) (expt x 2)));

    % Fresnel integrals

symbolic putv(mellin!-transforms!*,43,'
    (() (1 1 1 3) (1) ((quotient 3 4) nil (quotient 1 4))
    (quotient 1 2) (quotient (expt x 2) 4)));


symbolic putv(mellin!-transforms!*,44,'
    (() (1 1 1 3) (1) ((quotient 1 4) nil (quotient 3 4))
    (quotient 1 2) (quotient (expt x 2) 4)));

    % gamma function

symbolic putv(mellin!-transforms!*,45,'
    ((n) (1 1 1 2) (1) (n nil) 1 x));

    % Bessel functions

symbolic putv(mellin!-transforms!*,50,'
    ((n) (1 0 0 2) () ((quotient n 2) (minus (quotient n 2)))
    1 (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,51,'
    ((n) (2 0 1 3) ((quotient (minus (plus n 1)) 2))
((quotient n 2) (minus (quotient n 2)) (quotient (minus (plus n 1)) 2))
    1 (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,52,'
    ((n) (1 0 1 3) ((plus (quotient 1 2) (quotient n 2)))
    ((quotient n 2) (minus (quotient n 2))
    (plus (quotient 1 2) (quotient n 2)))
    pi (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,53,'
    ((n) (2 0 0 2) () ((quotient n 2) (minus (quotient n 2)))
    (quotient 1 2) (quotient (expt x 2) 4)));

    % struve functions

symbolic putv(mellin!-transforms!*,54,'
    ((n) (1 1 1 3) ((quotient (plus n 1) 2))
    ((quotient (plus n 1) 2) (minus (quotient n 2)) (quotient n 2))
    1 (quotient (expt x 2) 4)));

symbolic putv(mellin!-transforms!*,55,'
    ((n) (1 1 2 4) ((quotient (plus n 1) 2) nil)
    ((quotient (plus n 1) 2) nil (quotient n 2) (minus (quotient n 2)))
    (times (minus pi) (sec (times (quotient (minus n) 2) pi)))
    (quotient (expt x 2) 4)));

    % legendre polynomials

symbolic putv(mellin!-transforms!*,56,'
    ((n) (2 0 2 2) ((minus n) (plus n 1)) (nil nil)
    1 (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,57,'
    ((n) (0 2 2 2) (1 1) ((minus n) (plus n 1))
    1 (quotient (plus x 1) 2)));

    % chebyshev polymomials

symbolic putv(mellin!-transforms!*,58,'
    ((n) (2 0 2 2)
    ((difference (quotient 1 2) n) (plus (quotient 1 2) n))
    (nil (quotient 1 2)) (sqrt pi) (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,59,'
    ((n) (0 2 2 2) (nil (quotient 1 2)) (n (minus n))
    (sqrt pi) (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,60,'
    ((n) (2 0 2 2)
    ((plus (quotient 3 2) n) (difference (minus (quotient 1 2)) n))
    (nil (quotient 1 2)) (quotient (plus n 1) (times 2 (sqrt pi)))
    (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,61,'
    ((n) (0 2 2 2) ((quotient 3 2) 2) ((minus n) (plus n 2))
    (quotient (plus n 1) (times 2 (sqrt pi)))
    (quotient (plus x 1) 2)));

    % hermite polynomials

symbolic putv(mellin!-transforms!*,62,'
    ((n) (1 0 1 2) (plus (quotient n 2) 1)
    ((difference (quotient n 2) (quotient n 2))
    (difference (quotient 1 2) (difference (quotient n 2)
    (quotient n 2))))
    (times (expt (minus 1) (quotient n 2)) (sqrt pi) (factorial n))
    (expt x 2)));

    % laguerre polynomials

symbolic putv(mellin!-transforms!*,63,'
    ((n l) (1 0 1 2) ((plus n 1)) (0 (minus l))
    (gamma (plus l n 1)) x));

    % gegenbauer polynomials

symbolic putv(mellin!-transforms!*,64,'
    ((n l) (2 0 2 2) ((plus l n (quotient 1 2))
    (difference (quotient 1 2) (quotient 1 n)))
    (0 (difference (quotient 1 2) l))
   (quotient (times 2 l (gamma (plus l (quotient 1 2)))) (factorial n))
    (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,65,'
    ((n l) (0 2 2 2) ((plus l (quotient 1 2)) (times 2 l))
    ((minus n) (plus (times 2 l) n))
   (quotient (times 2 l (gamma (plus l (quotient 1 2)))) (factorial n))
    (quotient (plus x 1) 2)));

    % jacobi polynomials

symbolic putv(mellin!-transforms!*,66,'
    ((n r s) (2 0 2 2) ((plus r n 1) (difference (minus s) n))
    (0 (minus s)) (quotient (gamma (plus r n 1)) (factorial n))
    (quotient (plus x 1) 2)));

symbolic putv(mellin!-transforms!*,67,'
    ((n r s) (0 2 2 2) ((plus r 1) (plus r s 1))
    ((minus n) (plus r s n 1))
    (quotient (gamma (plus r n 1)) (factorial n))
    (quotient (plus x 1) 2)));

symbolic (mellin!-coefficients!* :=mkvect(200))$

endmodule;


module defintf;

algebraic <<

operator case20,case21,case22,case23,case24,case25,
         case26,case27,case28,case29,case30,case31,case32,case33,
         case34,case35;

case20_rules :=

{  case20(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when n = 0
        and m > 0
        and epsilon > 0
        and phi < 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_12 = 't
        and transform_test('test2,'test12,nil,nil,nil,nil,nil,nil) = 't
};

let case20_rules;

case21_rules :=

{  case21(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m = 0
        and n > 0
        and epsilon > 0
        and phi > 0
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_12 = 't
        and transform_test('test12,nil,nil,nil,nil,nil,nil,nil) = 't
};

let case21_rules;

case22_rules :=

{  case22(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when k*l = 0
        and delta > 0
        and epsilon > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_10 = 't and test_12 = 't
        and transform_test('test2,'test3,'test10,'test12,nil,nil,nil,
        nil)= 't
};

let case22_rules;

case23_rules :=

{  case23(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m*n = 0
        and delta > 0
        and epsilon > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_10 = 't and test_12 = 't
        and transform_test('test2,'test3,'test10,'test12,nil,nil,nil,
        nil) = 't
};

let case23_rules;

case24_rules :=

{  case24(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m + n > p
        and l = 0
        and phi = 0
        and k > 0
        and delta > 0
        and epsilon < 0
        and mylessp(abs(atan(impart omega/repart omega)),m + n - p + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_10 = 't and test_14 = 't and test_15 ='t
        and transform_test('test2,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case24_rules;

case25_rules :=

{  case25(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m + n > q
        and k = 0
        and phi = 0
        and l > 0
        and delta > 0
        and epsilon < 0
        and mylessp(abs(atan(impart omega/repart omega)),m + n - q + 1)
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_10 = 't and test_14 = 't and test_15 ='t
        and transform_test('test3,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case25_rules;

case26_rules :=

{  case26(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q - 1
        and l = 0
        and phi = 0
        and k > 0
        and delta > 0
        and epsilon >= 0
        and test_arg(abs(atan(impart omega/repart omega)),
                                                epsilon,epsilon + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_10 = 't and test_14 = 't and test_15 = 't
        and transform_test('test2,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case26_rules;

case27_rules :=

{  case27(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q + 1
        and k = 0
        and phi = 0
        and l > 0
        and delta > 0
        and epsilon >= 0
        and test_arg(abs(atan(impart omega/repart omega)),
                                                epsilon,epsilon + 1)
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_10 = 't and test_14 = 't and test_15 = 't
        and transform_test('test3,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case27_rules;

case28_rules :=

{  case28(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p < q - 1
        and l = 0
        and phi = 0
        and k > 0
        and delta > 0
        and epsilon >= 0
        and test_arg(abs(atan(impart omega/repart omega)),
                                                epsilon,m + n - p + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_10 = 't and test_14 = 't and test_15 = 't
        and transform_test('test2,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't

};

let case28_rules;

case29_rules :=

{  case29(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p > q + 1
        and k = 0
        and phi = 0
        and l > 0
        and delta > 0
        and epsilon >= 0
        and test_arg(abs(atan(impart omega/repart omega)),
                                                epsilon,m + n - q + 1)
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_10 = 't and test_14 = 't and test_15 = 't
        and transform_test('test3,'test10,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case29_rules;

case30_rules :=

{  case30(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when n = 0
        and phi = 0
        and k + l > u
        and m > 0
        and epsilon > 0
        and delta < 0
        and mylessp(abs(atan(impart sigma/repart sigma)),k + l - u + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_12 = 't and test_14 = 't and test_15 = 't
        and transform_test('test2,'test12,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case30_rules;

case31_rules :=

{  case31(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m = 0
        and phi = 0
        and k + l > v
        and n > 0
        and epsilon > 0
        and delta < 0
        and mylessp(abs(atan(impart sigma/repart sigma)),k + l - v + 1)
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_12 = 't and test_14 = 't and test_15 = 't
        and transform_test('test3,'test12,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case31_rules;

case32_rules :=

{  case32(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when n = 0
        and phi = 0
        and u = v - 1
        and m > 0
        and epsilon > 0
        and delta >= 0
        and test_arg(abs(atan(impart sigma/repart sigma)),
                                                delta,delta + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_12 = 't and test_14 = 't and test_15 = 't
        and transform_test('test2,'test12,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case32_rules;

case33_rules :=

{  case33(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m = 0
        and phi = 0
        and u = v + 1
        and n > 0
        and epsilon > 0
        and delta >= 0
        and test_arg(abs(atan(impart sigma/repart sigma)),
                                                delta,delta + 1)
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_12 = 't and test_14 = 't and test_15 = 't
        and transform_test('test3,'test12,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case33_rules;

case34_rules :=

{  case34(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when n = 0
        and phi = 0
        and u < v - 1
        and m > 0
        and epsilon > 0
        and delta >= 0
        and test_arg(abs(atan(impart sigma/repart sigma)),
                                                delta,k + l - u + 1)
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_12 = 't and test_14 = 't and test_15 = 't
        and transform_test('test2,'test12,'test14,'test15,nil,nil,nil,
        nil) = 't
};

let case34_rules;

case35_rules :=

{  case35(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => t

     when m = 0
        and phi = 0
        and u > v + 1
        and n > 0
        and epsilon > 0
        and delta >= 0
        and test_arg(abs(atan(impart sigma/repart sigma)),
                                                delta,k + l - v + 1)
        and test_1a = t and test_1b = t and test_3 = t
        and test_12 = t and test_14 = t and test_15 = t
        and transform_test('test3,'test12,'test14,'test15,nil,nil,nil,
        nil) = t
};

let case35_rules;


flag('(test_arg),'boolean);

algebraic procedure test_arg(a,b,c);

begin scalar !*rounded,dmode!*;
if transform_tst neq t then
<< on rounded;
   if b*pi < a and a < c*pi then << off rounded; return t>>
   else << off rounded; return nil>>;
>>
else return t;
end;

>>;

symbolic procedure transform_test(n1,n2,n3,n4,n5,n6,n7,n8);

begin scalar lst,temp,cond_test;

if transform_tst neq t then return t
else
<< lst := {n1,n2,n3,n4,n5,n6,n7,n8};
   for each i in lst do
    if i then  temp := lispeval cdr assoc(i,transform_lst) . temp; ;

   temp := 'and . temp;
   for each j in spec_cond do if j = temp then cond_test := t;
   if cond_test neq t then spec_cond := temp . spec_cond;
   return nil;
>>;
end;

symbolic operator transform_test;

flag('(sigma_tst),'boolean);

algebraic procedure sigma_tst(sigma);

begin scalar test;
if transform_tst neq t then
        << if sigma > 0 then return t else return nil>>
else
<< if test neq t then
   << symbolic(transform_lst := cons (('sigma_cond .'(list 'greaterp
                'sigma 0)),transform_lst));
      test := t>>;
   return reval t>>;
end;

flag('(omega_tst),'boolean);

symbolic procedure omega_tst(omega);

begin scalar test;

if transform_tst neq t then
<< if omega > 0 then return t else return nil>>
else
<< if test neq t then
   << symbolic(transform_lst := cons (('omega_cond .'(list 'greaterp
                'omega 0)),transform_lst));
      test := t>>;
   return reval t>>;
end;

endmodule;


module definti;

% A rule set to test for the validity of the seven cases for the
% integration of a single Meijer G-function.
%
% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 pages 158 & 159

algebraic <<

operator test_cases,case_1,case_2,case_3,case_4,case_5,case_6,case_7;

test_cases_rules :=

{test_cases(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2) => 't

   when case_1(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_2(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_3(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_4(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_5(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_6(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
   or case_7(m,n,p,q,delta,xi,eta,test_1,test_1a,test_2) = 't
};

let test_cases_rules;

case_1_rules :=

{  case_1(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2) => 't
     when 1 <= n and n <= p and p < q
      and 1 <= m and m <= q
      and delta > 0 and eta neq 0
      and mylessp(abs(atan(impart eta/repart eta)),delta) = 't
      and test_1 = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1 and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and not (n = 0 and m = p + 1)
      and delta >0 and eta neq 0
      and mylessp(abs(atan(impart eta/repart eta)),delta) = 't
      and test_1 = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1 and 0 <= n and n <= p
      and 0 <= m and m <= q and q = p
      and delta > 0 and eta neq 0
      and mylessp(abs(atan(impart eta/repart eta)),delta) = 't
      and not (arg_test1(abs(atan(impart eta/repart eta)),delta) = 't)
      and test_1 = 't
      and transform_test2('tst1,nil) = 't

};

let case_1_rules;

case_2_rules :=

{  case_2(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2) => 't
     when n = 0 and 1 <= p + 1 and p + 1 <= m and m <= q
      and delta > 0
      and mylessp(abs(atan(impart eta/repart eta)),delta) = 't
      and test_1 = 't
      and transform_test2('tst1,nil) = 't
};

let case_2_rules;

case_3_rules :=

{  case_3(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2)  => 't
     when 0 <= n and n <= p and p < q
      and 1 <= m and m <= q
      and delta > 0
      and arg_test2(abs(atan(impart eta/repart eta)),delta) = 't
      and test_1 = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or 0 <= n and n <= p and p <= q - 2
      and delta = 0
      and arg_test3a(atan(impart eta/repart eta),0) = 't
      and test_1 = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't
};

let case_3_rules;

case_4_rules :=

{  case_4(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2)  => 't

     when 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 2
      and eta neq 0
      and delta <= 0
      and arg_test(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 2
      and eta neq 0
      and delta >= 1
      and arg_test3(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or test_1 = 't and test_2 = 't
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 2
      and eta neq 0
      and delta >= 0
      and arg_test3a(atan(impart eta/repart eta),delta) = 't
      and test_1 = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't
};

let case_4_rules;

case_5_rules :=

{  case_5(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2)  => 't
     when p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and arg_test4(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi >= 2
      and arg_test5(atan(impart eta/repart eta),delta,xi) = 't
      and test_1a = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi >= 2
      and arg_test6(atan(impart eta/repart eta),delta,xi) = 't
      and test_1a = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1
      and 1 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi >= 1
      and arg_test6a(atan(impart eta/repart eta),delta,xi) = 't
      and test_1 = 't
      and transform_test2('tst1,nil) = 't
};

let case_5_rules;

case_6_rules :=

{  case_6(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2)  => 't
     when p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi <= 1
      and arg_test(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi >= 2
      and arg_test7(atan(impart eta/repart eta),delta,xi) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi <= 1
      and arg_test8(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p + 1
      and eta neq 0
      and xi >= 2
      and arg_test8a(atan(impart eta/repart eta),delta,xi) = 't
      and test_1a = 't and test_2 = 't
      and transform_test2('tst1,'tst2) = 't
};

let case_6_rules;

case_7_rules :=

{  case_7(~m,~n,~p,~q,~delta,~xi,~eta,~test_1,~test_1a,~test_2)  => 't
     when p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p
      and eta neq 0
      and arg_test9(atan(impart eta/repart eta),delta) = 't
      and test_1a = 't
      and transform_test2('tst1,nil) = 't

     or p >= 1
      and 0 <= n and n <= p
      and 1 <= m and m <= q and q = p
      and eta neq 0
      and delta >= 1
      and arg_test9a(atan(impart eta/repart eta),delta) = 't
      and not (arg_test1(abs(atan(impart eta/repart eta)),delta) = 't)
      and test_1 = 't
      and transform_test2('tst1,nil) = 't
};

let case_7_rules;

>>;

endmodule;


module defint0;  % Rules for definite integration.

global '(unknown_tst product_tst transform_tst transform_lst);

transform_lst := '();

fluid '(!*precise);

global '(spec_cond);

symbolic smacro procedure mynumberp(n);

begin; if numberp n then t

else if listp n and car n = 'quotient and (numberp cadr n or
mynumberp cadr n) and (numberp caddr n or mynumberp caddr n) then 't

else if listp n and car n = 'sqrt and (numberp cadr n or cadr n = 'pi)
         then t else nil;
end;

symbolic operator mynumberp;


put('intgggg,'simpfn,'simpintgggg);

% put('defint,'psopfn,'new_defint);

symbolic procedure new_defint(lst);
   begin scalar var,result,n1,n2,n3,n4,!*precise;
      if eqcar(car lst,'times)
        then return new_defint append(cdar lst,cdr lst);
      unknown_tst := nil;
      var := nth(lst,length lst);
      if length lst = 2 and listp car lst then
              lst := test_prod(lst,var);
      transform_tst := reval algebraic(transform_tst);
      if transform_tst neq t then lst := hyperbolic_test(lst);
      for each i in lst do specfn_test(i);
      if length lst = 5 then
         <<n1 := car lst;
           n2 := cadr lst;
           n3 := caddr lst;
           n4 := cadddr lst;
           result := reval algebraic defint2(n1,n2,n3,n4,var)>>
      else if length lst = 4 then
         <<n1 := car lst;
           n2 := cadr lst;
           n3 := caddr lst;
           result := reval algebraic defint2(n1,n2,n3,var)>>
      else if length lst = 3 then
         <<n1 := car lst;
           n2 := cadr lst;
           result := reval algebraic defint2(n1,n2,var)>>
      else if length lst = 2 then
         <<n1 := car lst;
           result := reval algebraic defint2(n1,var)>>;
      algebraic(transform_tst := nil);
      if pairp result then <<for each i in result do test_unknown(i);
             % Tidy up result by ensuring that just unknown is returned
             % and not multiples of it.
            if unknown_tst then return 'unknown else return result>>
       else return result
   end;

symbolic procedure specfn_test(n);

begin;
if listp n and car n = 'times then
<< if listp caddr n and (car caddr n = 'm_gegenbauerp or
                           car caddr n = 'm_jacobip)
    then off exp; >>;
end;

symbolic procedure test_prod(lst,var);

begin scalar temp,ls;

temp := caar lst;

if temp = 'times then
   << if listp caddar lst then

% test for special cases of Meijer G-functions of compoud functions

      << if car caddar lst neq 'm_chebyshevt and
            car caddar lst neq 'm_chebyshevu and
            car caddar lst neq 'm_gegenbauerp and
            car caddar lst neq 'm_jacobip then
            ls := append(cdar lst,{var})

%else returned without change
         else ls := lst;>>
      else ls := append(cdar lst,{var});
   >>

else if temp = 'minus and caadar lst = 'times then
<< if length cadar lst = 3 then
      ls := {{'minus,car cdadar lst},cadr cdadar lst,var}
   else if length cadar lst = 4 then
      ls := {{'minus,car cdadar lst},cadr cdadar lst,
                                             caddr cdadar lst,var}>>
else ls := lst;
return ls;
end;

symbolic procedure test_unknown(n);

% A procedure to test for unknown as the result of the integration
% process

if pairp n then << for each i in n do test_unknown(i)>>
else if n = 'unknown then unknown_tst := 't;

algebraic<<
heaviside_rules :=

{ heaviside(~x) => 1 when numberp x and x >= 0,
  heaviside(~x) => 0 when numberp x and x < 0 };

let heaviside_rules;

operator defint2,defint_choose;

share mellincoef$

defint2_rules:=

{ defint2(~n,cos((~x*~~a)/~~c)-cos((~x*~~b)/~~d),~x) =>
                defint2(-2,n,sin((a/c+b/d)*x/2),sin((a/c-b/d)*x/2),x),
  defint2(cos((~x*~~a)/~~c)-cos((~x*~~b)/~~d),~x) =>
                defint2(-2,sin((a/c+b/d)*x/2),sin((a/c-b/d)*x/2),x),

  defint2(~b,~f1,~f2,~x) => b*defint2(f1,f2,x) when freeof (b,x),

  defint2(~~b*~f1,~~c*~f2,~x) => b*c*defint2(f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~b/~f1,~c/~f2,~x) => c*b*defint2(1/f1,1/f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~~b*~f1,~c/~f2,~x) => c*b*defint2(f1,1/f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~b/~f1,~~c*~f2,~x) => c*b*defint2(1/f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~f1/~~b,~~c*~f2,~x) => c/b*defint2(f1,f2,x)
         when freeof (b,x) and freeof (c,x) and not(b = 1 and c = 1),

  defint2(~b/~f1,~x) => b*defint2(1/f1,x)
        when freeof (b,x) and not(b = 1),

  defint2(~~b*~f1,~x) => b*defint2(f1,x)
        when freeof (b,x) and not(b = 1),

  defint2(~f1/~~b,~x) => 1/b*defint2(f1,x)
        when freeof (b,x) and not(b = 1),

  defint2((~f2+ ~~f1)/~~f3,~x) => defint2(f2/f3,x) + defint2(f1/f3,x)
                        when not(f1=0),
  defint2(-~f1,~x) =>  - defint2(f1,x),
  defint2((~f2+ ~~f1)/~~f3,~n,~x) =>
                 defint2(f2/f3,n,x) + defint2(f1/f3,n,x)
                when not(f1=0),
  defint2(-~f1,~n,~x) =>  - defint2(f1,n,x),
  defint2(~n,(~f2+ ~~f1)/~~f3,~x) =>
                 defint2(n,f2/f3,x) + defint2(n,f1/f3,x)
                when not(f1=0),
  defint2(~n,-~f1,~x) =>  - defint2(n,f1,x),
  defint2(~n,(~f2+ ~~f1)/~~f3,~nn,~x) =>
                 defint2(n,f2/f3,nn,x) + defint2(n,f1/f3,nn,x)
                when not(f1=0),
  defint2(~n,-~f1,~nn,~x) =>  - defint2(n,f1,nn,x),
  defint2(~n,~nn,(~f2+ ~~f1)/~~f3,~x) =>
                 defint2(n,nn,f2/f3,x) + defint2(n,nn,f1/f3,x)
                when not(f1=0),
  defint2(~n,~nn,-~f1,~x) =>  - defint2(n,nn,f1,x),

  defint2(~n,~x^~a,~f1,~f2,~x) =>
                 n*intgggg(defint_choose(f1,x),defint_choose(f2,x),a,x)
   when numberp n ,

  defint2(~n,~x,~f1,~f2,~x) =>
                 n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1,x)
   when numberp n ,
  defint2(~n,1/~x^~~a,~f1,~f2,~x) =>
                 n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-a,x)
   when numberp n ,
  defint2(~n,1/~x,~f1,~f2,~x) =>
                n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1,x)
   when numberp n ,
  defint2(~n,sqrt(~x),~f1,~f2,~x) =>
                n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2,x)
   when numberp n ,
  defint2(~n,sqrt(~x)*~x,~f1,~f2,~x) =>
                n*intgggg(defint_choose(f1,x),defint_choose(f2,x),3/2,x)
   when numberp n ,
  defint2(~n,sqrt(~x)*~x^~a,~f1,~f2,~x) =>
              n*intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2+a,x)
   when numberp n ,
  defint2(~n,1/sqrt(~x),~f1,~f2,~x) =>
               n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2,x)
   when numberp n ,
  defint2(~n,1/(sqrt(~x)*~x),~f1,~f2,~x) =>
               n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-3/2,x)
   when numberp n ,
  defint2(~n,1/(sqrt(~x)*~x^~a),~f1,~f2,~x) =>
             n*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2-a,x)
   when numberp n ,

  defint2(~n,1/~x,~f1,~x) => n*intgggg(defint_choose(f1,x),0,-1,x)
   when numberp n ,
  defint2(~n,1/~x^(~a),~f1,~x) => n*intgggg(defint_choose(f1,x),0,-a,x)
   when numberp n ,
  defint2(~n,1/sqrt(~x),~f1,~x) =>
                 n*intgggg(defint_choose(f1,x),0,-1/2,x) when numberp n,
  defint2(~n,1/(sqrt(~x)*~x),~f1,~x) =>
                 n*intgggg(defint_choose(f1,x),0,-3/2,x)
   when numberp n ,
  defint2(~n,1/(sqrt(~x)*~x^~a),~f1,~x) =>
                 n*intgggg(defint_choose(f1,x),0,-1/2-a,x)
   when numberp n ,
  defint2(~n,~x**(~a),~f1,~x) => n*intgggg(defint_choose(f1,x),0,a,x)
   when numberp n ,
  defint2(~n,~x,~f1,~x) => n*intgggg(defint_choose(f1,x),0,1,x)
   when numberp n ,
  defint2(~n,sqrt(~x),~f1,~x) => n*intgggg(defint_choose(f1,x),0,1/2,x)
    when numberp n ,
 defint2(~n,sqrt(~x)*~x,~f1,~x) =>
    n*intgggg(defint_choose(f1,x),0,3/2,x)
   when numberp n ,
  defint2(~n,sqrt(~x)*~x^~a,~f1,~x) =>
                n*intgggg(defint_choose(f1,x),0,1/2+a,x)
   when numberp n ,

  defint2(~~b*~x^~~a/~~c,~f1,~f2,~x) =>
        b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),a,x)
                        when freeof(b,x) and freeof (c,x),
  defint2(~b/(~~c*~x^~~a),~f1,~f2,~x) =>
        b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),-a,x)
                        when freeof(b,x) and freeof(c,x),
  defint2(sqrt(~x),~f1,~f2,~x) =>
                intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2,x),
  defint2(sqrt(~x)*~x^~~a,~f1,~f2,~x) =>
               intgggg(defint_choose(f1,x),defint_choose(f2,x),1/2+a,x),
  defint2(~b/(~~c*sqrt(~x)),~f1,~f2,~x) =>
            b/c*intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2,x),
  defint2(1/(sqrt(~x)*~x^~~a),~f1,~f2,~x) =>
      intgggg(defint_choose(f1,x),defint_choose(f2,x),-1/2-a,x),

  defint2(1/~x^(~~a),~f1,~x) => intgggg(defint_choose(f1,x),0,-a,x),
  defint2(1/sqrt(~x),~f1,~x) => intgggg(defint_choose(f1,x),0,-1/2,x),
  defint2(1/(sqrt(~x)*~x^~~a),~f1,~x) =>
                intgggg(defint_choose(f1,x),0,-1/2-a,x),
  defint2(~x**(~~a),~f1,~x) => intgggg(defint_choose(f1,x),0,a,x),
  defint2(sqrt(~x),~f1,~x) => intgggg(defint_choose(f1,x),0,1/2,x),
  defint2(sqrt(~x)*~x^~~a,~f1,~x) =>
                 intgggg(defint_choose(f1,x),0,1/2+a,x),

  defint2(~b,~f1,~x) => b*defint2(f1,x) when freeof(b,x),
  defint2(~f1,~f2,~x) =>
        intgggg(defint_choose(f1,x),defint_choose(f2,x),0,x),

  defint2(~n,~f1,~x) => n*intgggg(defint_choose(f1,x),0,0,x),

  defint2(~f1,~x) => intgggg(defint_choose(f1,x),0,0,x),

  defint2((~f1-~f2)/~f3,~f4,~x) =>
                             defint2(f1/f3,f4,x) - defint2(f2/f3,f4,x),
  defint2(-~b,~f1,~f2,~x) => -b*defint2(f1,f2,x) when freeof(b,x)

};

let defint2_rules;
>>;
endmodule;


module defintd;

fluid '(mellincoef mellin!-coefficients!* mellin!-transforms!*);

symbolic procedure simpintgggg (u);

begin scalar ff1,ff2,alpha,var,chosen_num,coef,temp,const,result;

     u := defint_reform(u);
     const := car u;
     if const = 0 then result := nil . 1
     else
     << u := cdr u;
        if length u neq 4 then rederr  "Integration failed";
        if (car u) = 0 then ff1 := '(0 0 x)
        else ff1 := prepsq simp car u;
        if (cadr u) = 0 then ff2 := '(0 0 x)
        else  ff2 := prepsq simp cadr u;

        if (ff1 = 'unknown) then return simp 'unknown;
        if (ff2 = 'unknown) then return simp 'unknown;
        alpha := caddr u;
        var := cadddr u;

        if car ff1 = 'f31 or car ff1 = 'f32 then
                << put('f1,'g,spec_log(ff1)); mellincoef :=1>>
        else
        << chosen_num := cadr ff1;
           put('f1,'g,getv(mellin!-transforms!*,chosen_num));
           coef := getv(mellin!-coefficients!*,chosen_num);
           if coef then mellincoef:= coef else mellincoef :=1>>;

        if car ff2 = 'f31 or car ff2 = 'f32 then
           put('f2,'g,spec_log(ff2))
        else
        << chosen_num := cadr ff2;
           put('f2,'g,getv(mellin!-transforms!*,chosen_num));
           coef := getv(mellin!-coefficients!*,chosen_num);
           if coef then mellincoef:= coef * mellincoef >>;

        temp :=  simp list('intgg,'f1 . cddr ff1,
                                      'f2 . cddr ff2,alpha,var);

        temp := prepsq temp;

        if temp neq 'unknown then
            result := reval algebraic(const*temp)

        else result := temp;
        result := simp!* result; >>;
      return result;
end;

symbolic procedure spec_log(ls);

begin scalar n,num,denom,mellin;

  n := cadr ls;
  num := for i:= 0 :n collect 1;
  denom := for i:= 0 :n collect 0;

  if car ls = 'f31 then
    mellin := {{}, {n+1,0,n+1,n+1},num,denom, (-1)^n*factorial(n),'x}
   else mellin := {{}, {0,n+1,n+1,n+1},num,denom, factorial(n),'x};
return mellin;
end;

 % some rules which let the results look more convenient ...

algebraic <<

 for all z let sinh(z) = (exp (z) - exp(-z))/2;
 for all z let cosh(z) = (exp (z) + exp(-z))/2;

operator laplace2,y_transform2,k_transform2,struveh_transform2,
         fourier_sin2,fourier_cos2;

gamma_rules :=

{ gamma(~n/2+1/2) => gamma(n)/(2^(n-1)*gamma(n/2))*gamma(1/2),
  gamma(~n/2+1) => n/2*gamma(1/2*n),
  gamma(3/4)*gamma(1/4) => pi*sqrt(2),
  gamma(~n)*~n/gamma(~n+1) => 1
};

let gamma_rules;

factorial_rules := {factorial(~a) => gamma(a+1) };
let factorial_rules;

>>;

% A function to calculate laplace transforms of given functions via
% integration of Meijer G-functions.

put('laplace_transform,'psopfn,'new_laplace);

symbolic procedure new_laplace(lst);

begin scalar new_lst;
lst := product_test(lst);
new_lst := {'laplace2,lst};
return defint_trans(new_lst);
end;

% A function to calculate hankel transforms of given functions via
% integration of Meijer G-functions.

put('hankel_transform,'psopfn,'new_hankel);

symbolic procedure new_hankel(lst);

begin scalar new_lst;
lst := product_test(lst);
new_lst := {'hankel2,lst};
return defint_trans(new_lst);
end;

% A function to calculate Y transforms of given functions via
% integration of Meijer G-functions.

put('y_transform,'psopfn,'new_y_transform);

symbolic procedure new_y_transform(lst);

begin scalar new_lst;
lst := product_test(lst);
new_lst := {'y_transform2,lst};
return defint_trans(new_lst);
end;

% A function to calculate K-transforms of given functions via
% integration of Meijer G-functions.

put('k_transform,'psopfn,'new_k_transform);

symbolic procedure new_k_transform(lst);

begin scalar new_lst;
lst := product_test(lst);
new_lst := {'k_transform2,lst};
return defint_trans(new_lst);
end;


% A function to calculate struveh transforms of given functions via
% integration of Meijer G-functions.

put('struveh_transform,'psopfn,'new_struveh);

symbolic procedure new_struveh(lst);

begin scalar new_lst,temp;
        lst := product_test(lst);
        new_lst := {'struveh2,lst};
        temp:=defint_trans(new_lst);
        return defint_trans(new_lst);
end;

% A function to calculate fourier sin transforms of given functions via
% integration of Meijer G-functions.

put('fourier_sin,'psopfn,'new_fourier_sin);

symbolic procedure new_fourier_sin(lst);

begin scalar new_lst;
lst := product_test(lst);
new_lst := {'fourier_sin2,lst};
return defint_trans(new_lst);
end;

% A function to calculate fourier cos transforms of given functions via
% integration of Meijer G-functions.

put('fourier_cos,'psopfn,'new_fourier_cos);

symbolic procedure new_fourier_cos(lst);

  begin scalar new_lst;
        lst := product_test(lst);
        new_lst := {'fourier_cos2,lst};
        return defint_trans(new_lst);
  end;

% A function to test whether the input is in a product form and if so
% to rearrange it into a list form.

% e.g. defint(x*cos(x)*sin(x),x) => defint(x,cos(x),sin(x),x);

symbolic procedure product_test(lst);

begin scalar temp;
product_tst := nil;
if listp car lst then
<< temp := caar lst;
   if temp = 'times and length cdar lst <= 3 then
   << lst := append(cdar lst,cdr lst); product_tst := t>>;
>>;
return lst;
end;

% A function to call the relevant transform's rule-set

symbolic procedure defint_trans(lst);

begin scalar type,temp_lst,new_lst,var,n1,n2,result;

% Set a test to indicate that the relevant conditions for validity
% should not be tested

        algebraic(transform_tst := t);

        spec_cond := '();
        type := car lst; % obtain the transform type
        temp_lst := cadr lst;
        var := nth(temp_lst,length temp_lst);
        new_lst := hyperbolic_test(temp_lst);

        if length temp_lst = 3 then
                << n1 := car new_lst;
                   n2 := cadr new_lst;
                   result := reval list(type,n1,n2,var)>>
         % Call the relevant rule-set

else if length temp_lst = 2 then
<< n1 := car new_lst;
   result := reval list(type,n1,var)>> % Call the relevant rule-set

        else if length temp_lst = 4 and product_tst = 't then
        << n1 := {'times,car new_lst,cadr new_lst};
           n2 := caddr new_lst;
           result := reval list(type,n1,n2,var)>>

        else << algebraic(transform_tst := nil);
                rederr "Wrong number of arguments">>;

return result;
end;

% A function to test for hyperbolic functions and rename them
% in order to avoid their transformation into combinations of
% the exponenetial function

%symbolic procedure hyperbolic_test(lst);
% begin scalar temp,new_lst,lth;
% lth := length lst;
% for i:=1 :lth do
% << temp := car lst;
%    if listp temp and (car temp = 'difference or car temp = 'plus) then
%        temp := hyperbolic_test(temp)
%    else if listp temp and car temp = 'sinh then car temp := 'mysinh
%    else if listp temp and car temp = 'cosh then car temp := 'mycosh;
%    new_lst := append(new_lst,{temp});
%   lst := cdr lst>>;
%return new_lst;
%end;

symbolic procedure hyperbolic_test lst;
   for each u in lst collect
      if atom u then u
       else if car u memq '(difference plus) then hyperbolic_test u
       else if car u eq 'sinh then 'mysinh . cdr u
       else if car u eq 'cosh then 'mycosh . cdr u
       else u;

endmodule;


module defintg;

symbolic procedure print_conditions;

<< if spec_cond neq nil then mathprint ('or . spec_cond) else
            rederr "Conditions not valid";
        spec_cond := nil;
>>;

symbolic operator print_conditions;

symbolic procedure defint_reform(n);

% A function to rearrange the input to the integration process by
% expanding out multiple powers of the exponential function i.e.
%
%     2               2
%    x + x + 1       x     x
%   e            => e  * e  * e
%

begin scalar n,var,vble,const,result,reform_test,temp_result,
                reform_lst,lst,new_lst,res,coef,new_coef;

% test if integral needs to be reformed

on exp;
coef := 1;

var := caddar n;
const := caddr n;
vble := cadddr n;

% test to see if any part of the integral needs reforming

for each i in n do

<< if eqcar(i,'defint_choose) then

% test for integrals of a single function multiplied by a constant

   << if i neq '(defint_choose e x) and numberp cadr i
                and cadr i neq 0 then

      << new_coef := cadr i;
         coef := reval algebraic(coef*new_coef);
         n := const_case(n)>>

% special case for integration of 0

      else if i = '(defint_choose 0 x) then coef := 0

% test for special case of integral of e
      else if i = '(defint_choose e x) then
           coef := reval algebraic(e*coef)

      else if caadr i = 'expt then

      << reform_test := 't;
% Form a list of the functions which must be reformed
         reform_lst := append(reform_lst,{i})>>

      else if caadr i = 'quotient

% don't reform special compound functions which are represented as a
% single Meijer G-function

                and (listp cadadr i and car cadadr i neq 'm_chebyshevt
                        or not listp cadadr i) then

      << reform_test := 't;
% Form a list of the functions which must be reformed
         reform_lst := append(reform_lst,{i})>>

      else if caadr i = 'times then

      << if listp car cddadr i
                  and (caar cddadr i = 'm_chebyshevu
                  or caar cddadr i = 'm_jacobip

% do not reform functions containing the heaviside function

                  or car cadadr i = 'heaviside)
     then
          lst := append(lst,{i})  % A list of the functions which do
                                % not need reforming

         else if listp cdr cddadr i and cdr cddadr i neq 'nil
                        and listp cadr cddadr i
                        and caadr cddadr i = 'm_gegenbauerp
     then
          lst := append(lst,{i})  % A list of the functions which do
                                % not need reforming
         else << reform_test := 't;
% Form a list of the functions which must be reformed
            reform_lst := append(reform_lst,{i});>>
      >>
      else lst := append(lst,{i});  % A list of the functions which do
                                    % not need reforming
   >>;
>>;

if reform_test = nil then << n := coef . n; return n>>
else

<< for each i in reform_lst do

   << new_lst := cadr i;
      if car new_lst = 'expt and cadr new_lst = 'e then
          res := reform_expt(new_lst,var)
      else if car new_lst = 'times then
          res := reform_const(new_lst,var)
      else if car new_lst = 'quotient and cadr new_lst = 1 then
          res := reform_denom(new_lst,var)
      else if car new_lst = 'quotient then
          res := reform_quot(new_lst,var);
      new_coef := car res;
      coef := reval algebraic(coef*new_coef);
      res := cdr res;
      temp_result := append(temp_result,res);
   >>;

   temp_result := coef . temp_result;
   result := append(temp_result,lst);

if lst = nil and length result = 2 then result := append(result,{0});
   result := append(result,{const});
   result := append(result,{vble});
   return result;
>>;

end;


% A function to rearrange the integral if it contains exponentials of
% only positive numbers and there is no constant term

symbolic procedure reform_expt(n,var);

begin scalar temp,coef,lst;

% test for exponentials which do not need reforming i.e. e^x

if not listp n then
<< lst := {{'defint_choose,n,var}}; lst := 1 . lst>>

else if listp caddr n neq t then

<< if numberp caddr n then coef := n
         else lst := {{'defint_choose,n,var}}; >>

else if caaddr n = 'quotient then lst := {{'defint_choose,n,var}}

else
<<  temp := cdaddr n;
   for each i in temp do
   << lst := ({'defint_choose,{'expt,'e,car temp},var} . lst);
      temp := cdr temp>>;
>>;
if coef neq nil then lst := coef . lst else lst := 1 . lst;
return lst;
end;


% A function to rearrange the integral if the exponential is multiplied
% by a constant term

symbolic procedure reform_const(n,var);

begin scalar temp,coef,lst,temp1;

temp := n;

coef := caddr temp;
temp := cadr temp;

if temp neq nil and car temp = 'expt and (atom caddr temp or
                        caaddr temp neq 'plus) then
<< lst := {{'defint_choose,{'expt,'e,caddr temp},var}}>>
else
<< temp1 := cdaddr temp;
   for each i in temp1 do
   << lst := ({'defint_choose,{'expt,'e,car temp1},var} . lst);
      temp1 := cdr temp1>>;
>>;
if coef neq nil then lst := coef . lst else lst := 1 . lst;
return lst;
end;

% A function to rearrange the integral if all the exponential powers
% are negative powers

symbolic procedure reform_denom(n,var);
   begin scalar temp,coef,lst,temp1;
      temp := caddr n;
      % if the function contains e^n where n is a number than this can
      % be taken outside the integral as a constant.
      if not(eqcar(temp,'expt) or eqcar(temp,'times))
                        then return list(1,list('defint_choose,n,var));

      if temp = 'e or fixp caddr temp then <<coef := temp; temp := nil>>
       else if car temp = 'times then
        <<if fixp cadr temp then
           << coef := cadr temp; temp := caddr temp>>
           else << coef := caddr temp; temp := cadr temp>>>>;
      % test for a single occurrence of e.
      if temp and eqcar(caddr temp ,'quotient)
              and listp car cdaddr temp and listp cadr cdaddr temp then
      << off mcd; temp:= {'expt,'e,quotient_case(reval temp)}; on mcd>>;
      if temp and car temp = 'expt and (atom caddr temp or
                              caaddr temp neq 'plus) then
      <<lst := {{'defint_choose,
                   {'quotient,1,{'expt,'e,caddr temp}},var}}>>
      % else if there are multiple occurrences of e
      else if pairp caddr temp then
      << temp1 := cdaddr temp;
         for each i in temp1 do
         << lst:=({'defint_choose,
                       {'quotient,1,{'expt,'e,car temp1}},var}
                       . lst); temp1 := cdr temp1>>>>;
  a:  return if coef then lst := ({'quotient,1,coef} . lst)
              else lst := 1 . lst
   end;

% A function to rearrange the integral if the exponential consists of
% both positive and negative powers

symbolic procedure reform_quot(n,var);

begin scalar num,denom,num_coef,denom_coef,lst,num1,denom1;

num := cadr n;
denom := caddr n;

% Check for constants

if fixp num or atom num then << num_coef := num; num := nil>>

else if num = 'e or fixp caddr num then
        << num_coef := num; num := nil>>

else if car num  = 'times then
        << num_coef := caddr num; num  := cadr num>>;

if fixp denom or atom denom then
        << denom_coef := denom; denom := nil>>

else if denom = 'e or fixp caddr denom then
           << denom_coef := denom; denom := nil>>

else if car denom  = 'times then
        << denom_coef := caddr denom; denom  := cadr denom>>;

if denom and car denom = 'expt and (atom caddr denom or
                        caaddr denom neq 'plus) then
     lst := {{'defint_choose,{'quotient,1,
                {'expt,'e,caddr denom}},var}}

else if denom then

<< denom1 := cdaddr denom;
%  for each i in denom1 do
%  << lst := ({'defint_choose,{'quotient,1,
%               {'expt,'e,car denom1}},var} . lst);
%     denom1 := cdr denom1>>;
   for each i in denom1 do
     lst := ({'defint_choose,{'quotient,1,
                {'expt,'e,i}},var} . lst)>>;

if not atom num and car num = 'expt and (atom caddr num or
                        caaddr num neq 'plus) then

    lst := {'defint_choose,{'expt,'e,caddr num},var} . lst

else if not atom num then

<< num1 := cdaddr num;
   for each i in num1 do
   << lst := ({'defint_choose,{'expt,'e,car num1},var} . lst);
      num1 := cdr num1>>;
>>;

if num_coef then lst := (num_coef . lst)

else if denom_coef neq nil then
    lst := ({'quotient,1,denom_coef} . lst)

else lst := 1 . lst;
return lst;
end;

symbolic procedure const_case(n);

begin scalar n,new_n;
for i := 0 :length n do
<< if not listp car n or listp car n and not numberp cadar n then
       new_n := append(new_n,{car n}); n := cdr n>>;

new_n := append(new_n,{0});
new_n := append(new_n,n);
return new_n;
end;

symbolic procedure quotient_case(n);

begin scalar lst,new_lst;

lst := cdaddr n;
new_lst := {caaddr n};

for each i in lst do
<< if caddr i < 0 then
   << caddr i := minus caddr i;
      i := {car i,cadr i, {'minus,caddr i}}>>;
  new_lst := append(new_lst,{i});
>>;
return new_lst;
end;

put('transf,'simpfn,'simpinteg);
% put('indefint,'psopfn,'new_indefint);

symbolic procedure new_indefint(lst);
   begin scalar var,y,n1,n2,result,!*precise;
      if eqcar(car lst,'times)
        then return new_indefint append(cdar lst,cdr lst);
      var := nth(lst,length lst - 1);
      y := nth(lst,length lst);
      lst := hyperbolic_test(lst);
      if length lst = 4 then << n1 := car lst; n2 := cadr lst;
              result := reval algebraic indefint2(n1,n2,var,y)>>
      else if length lst = 3 then << n1 := car lst;
              result := reval algebraic indefint2(n1,var,y)>>;
      return result
   end;

endmodule;


module defintj;

flag('(mylessp),'boolean);

algebraic procedure mylessp(a,b);

%
% Test the validity of the following :-
%
%      a < b*pi
%

begin scalar !*rounded;

if transform_tst neq 't then

<< on rounded;
   if a < b*pi then << off rounded; return t>>
   else << off rounded; return nil>>;
>>
else << transform_mylessp(); return t>>;
end;


symbolic procedure transform_mylessp();

  begin scalar temp,cond_test;

  temp := lispeval '(list 'lessp (list 'mod (list 'arg 'eta))
                                (list 'times 'pi 'delta));
  if listp spec_cond then
        for each i in spec_cond do  if i = temp then cond_test := t;
  if cond_test neq t then spec_cond := temp . spec_cond;
end;


symbolic operator transform_mylessp;

flag('(arg_test),'boolean);

algebraic procedure arg_test(a,b);

%
% Test the validity of the following :-
%
%      a = (b + 2*k)*pi    k arbitrary integer
%

begin scalar temp;

if transform_tst neq t then
<< temp := (a - b*pi)/(2*pi); temp := symbolic (fixp temp);
   if temp = t  then return t else return nil>>
else << transform_arg_test(); return t>>;
end;

symbolic procedure transform_arg_test();

begin scalar temp,cond_test;

temp := lispeval '(list 'equal (list 'arg 'eta) (list 'times
                        (list 'plus 'delta (list 'times 2 'k)) 'pi));

if listp spec_cond then
 for each i in spec_cond do  if i = temp then cond_test := t;
if cond_test neq t then spec_cond := temp . spec_cond;
end;

symbolic operator transform_arg_test;

flag('(arg_test1),'boolean);

algebraic procedure arg_test1(a,b);

%
% Test the validity of the following :-
%
%      a = (b - 2*k)*pi    k = 0,1,....,[b/2]
%

begin scalar temp,int_test;

temp := (a - b*pi)/(-2*pi);
int_test := symbolic (fixp temp);

if int_test = t and  temp <= b/2 and temp >= 0 then return t
else return nil;
end;

flag('(arg_test2),'boolean);

algebraic procedure arg_test2(a,b);

% Test the validity of the following :-
%
%      a = b*pi     b > 0

if transform_tst neq t then
        if a/(b*pi) = 1 and b > 0 then t else nil
else
<< transform_arg_test2(); t>>;

symbolic procedure transform_arg_test2();

begin scalar temp,cond_test;

temp := lispeval '(list 'equal (list 'mod (list 'arg 'eta))
                                (list 'times 'pi 'delta));
if pairp spec_cond then

<< for each i in spec_cond do
   << if i = temp then cond_test := 't>>; >>;

if cond_test neq 't then spec_cond := temp . spec_cond;
end;

symbolic operator transform_arg_test2;

flag('(arg_test3),'boolean);

algebraic procedure arg_test3(a,b);

%
% Test the validity of the following :-
%
%      a = (b + 2*k)*pi     k >= 0 or k <= -(1 + b)  k an integer
%

begin scalar temp,int_test;
if transform_tst neq 't then

<< temp := (a - b*pi)/(2*pi);
   int_test := symbolic (fixp temp);

   if int_test = 't and (temp >= 0 or temp <= -(1+b)) then
       return 't else return nil>>
else << transform_arg_test3(); return 't>>;
end;

flag('(arg_test3a),'boolean);

algebraic procedure arg_test3a(a,b);

% Test the validity of the following :-
%
%      a = b*pi     b >= 0

if transform_tst neq t then

<< if a - b*pi = 0 then t else nil>>
else << transform_arg_test3(); t>>;

symbolic procedure transform_arg_test3();

begin scalar temp,cond_test;

temp := lispeval '(list 'equal (list 'arg 'eta) (list 'plus 'm
   (list 'difference 'n (list 'times (list 'quotient 1 2)
   (list 'plus 'p 'q) 'pi))));

if listp spec_cond then
 for each i in spec_cond do if i = temp then cond_test := t;
if cond_test neq t then spec_cond := temp . spec_cond;
end;

symbolic operator transform_arg_test3;

flag('(arg_test4),'boolean);

algebraic procedure arg_test4(a,b);

% Test the validity of the following :-
%
%      (b + 2*k - 1)*pi < a < (b + 2*k)*pi     k arbitrary integer

begin scalar l1,l2,new_l1,new_l2;

l1 := (a - b*pi)/(2*pi);
new_l1 := ceiling(l1);

if new_l1 = l1 then new_l1 := new_l1 + 1;

l2 := (a - b*pi + pi)/(2*pi);
new_l2 := floor(l2);
if new_l2 = l2 then new_l2 := new_l2 - 1;
if new_l1 = new_l2 then return 't else return nil;
end;

flag('(arg_test5),'boolean);

algebraic procedure arg_test5(a,b,xi);

% Test the validity of the following :-
%
%      (b + 2*k)*pi <= a < (b + 2*k + 1)*pi    -xi < k < 0 k an integer

begin scalar l1,l2,new_l2;

l1 := floor((a - b*pi)/(2*pi));
l2 := (a - b*pi - pi)/(2*pi);
new_l2 := ceiling(l2);
if l1 = new_l2 and l1 < 0 and -xi < l1 then return t else return nil;
end;

flag('(arg_test6),'boolean);

algebraic procedure arg_test6(a,b,xi);

% Test the validity of the following :-
%
%      a = (b + 2*k - 1)*pi     1-xi < k < 1   k an integer

begin scalar l,int_test;

l := (a - b*pi + pi)/(2*pi);
int_test := symbolic (fixp l);
if int_test = t and l < 1 and l > 1 - xi then return t else return nil;
end;

flag('(arg_test6a),'boolean);

algebraic procedure arg_test6a(a,b,xi);

% Test the validity of the following :-
%
%      a = (b + 2*k - 1)*pi     1-xi <= k <= 0

begin scalar l,int_test;

l := (a - b*pi + pi)/(2*pi);
int_test := symbolic (fixp l);
if l <= 0 and l >= 1 - xi then return t else return nil;
end;

flag('(arg_test7),'boolean);

algebraic procedure arg_test7(a,b,xi);

% Test the validity of the following :-
%
%      a = (b + 2*k)*pi     k >= 0 or k <= -xi   k an integer

begin scalar temp,int_test;

temp := (a - b*pi)/(2*pi);
int_test := symbolic (fixp temp);
if int_test=t and (temp >= 0 or temp <= -xi) then return t
else return nil;
end;

flag('(arg_test8),'boolean);

algebraic procedure arg_test8(a,b);

% Test the validity of the following :-
%
%      a = (b + 2*k - 1)*pi     k arbitrary integer

begin scalar temp,int_test;

temp := (a - b*pi + pi)/(2*pi);
int_test := symbolic (fixp temp);
if int_test = t then return t else return nil;
end;

flag('(arg_test8a),'boolean);

algebraic procedure arg_test8a(a,b,xi);

% Test the validity of the following :-
%
%      a = (b + 2*k - 1)*pi     k >= 1 k <= 1 - xi  k an integer

begin scalar temp,int_test;

temp := (a - b*pi + pi)/(2*pi);
int_test := symbolic (fixp temp);
if int_test = t and (temp >= 1 or temp <= 1 - xi) then return t
else return nil
end;

flag('(arg_test9),'boolean);

algebraic procedure arg_test9(a,b);

% Test the validity of the following :-
%
%      (b + 2*k - 2)*pi < a < (b + 2*k)*pi     k arbitrary

begin scalar l1,l2,new_l1,new_l2;

l1 := (a - b*pi)/(2*pi);
new_l1 := ceiling(l1);
if new_l1 = l1 then new_l1 := new_l1 + 1;
l2 := (a - b*pi + 2*pi)/(2*pi);
new_l2 := floor(l2);
if new_l2 = l2 then new_l2 := new_l2 - 1;
if new_l1 = new_l2 then return t else return nil;
end;

flag('(arg_test9a),'boolean);

algebraic procedure arg_test9a(a,b);

% Test the validity of the following :-
%
%      (b + 2*k - 2)*pi < a < (b + 2*k)*pi     1 - b <= k <= 0
%                                                       k arbitrary

begin scalar l1,l2,new_l1,new_l2;

l1 := (a - b*pi)/(2*pi);
new_l1 := ceiling(l1);
if new_l1 = l1 then new_l1 := new_l1 + 1;
l2 := (a - b*pi + 2*pi)/(2*pi);
new_l2 := floor(l2);
if new_l2 = l2 then new_l2 := new_l2 - 1;
if new_l1 = new_l2 and (1 - b <= new_l1 or new_l1 <= 0) then
    return t else return nil;
end;

symbolic procedure transform_test2(n1,n2);

begin scalar lst,temp,cond_test;

if transform_tst neq t then return t else
<< if n1 then temp := lispeval cdr assoc(n1,transform_lst) . temp;
   if n2 then temp := lispeval cdr assoc(n2,transform_lst) . temp;

   temp := 'and . temp;
   for each j in spec_cond do  if j = temp then cond_test := t;
   if cond_test neq t then spec_cond := temp . spec_cond;
   return nil;
>>;
end;

symbolic operator transform_test2;

endmodule;


module defintb;

algebraic ;

 defint_choose_data :=

{ defint_choose(1/e**(~x),~var) => f1(1,x),
  defint_choose(sin(~x),~var)   => f1(2,x),
  defint_choose(-sin(~x),~var)   => f1(25,x),
  defint_choose(cos(~x),~var)   => f1(3,x),

  defint_choose(acos(~x)*heaviside (1-(~x)),~var) => f1(7,x),
  defint_choose(acos(1/~x)*heaviside ((~x)-1),~var) => f1(8,x),
  defint_choose(atan(~x),~var) => f1(9,x),
  defint_choose(mysinh(~x),~var) => f1(10,x),
  defint_choose((e^(2*~x)-1)/(2*e^~x),~var) => f1(10,x),   %sinh(x)
  defint_choose((e^(~y)-1)/(2*e^~x),~var) => f1(10,x)   %sinh(nx)
     when y = 2*x,
  defint_choose(mycosh(~x),~var)=> f1(11,x),

  defint_choose((e^(2*~x)+1)/(2*e^~x),~var) => f1(11,x),   %cosh(x)
  defint_choose((e^(~y)+1)/(2*e^~x),~var) => f1(11,x)   %cosh(nx)
     when y = 2*x,
  defint_choose(heaviside (1-(~x)),~var) => f1(30,x),
  defint_choose(heaviside ((~p-~x)/~p),~var) => f1(30,x/p),
  defint_choose(heaviside ((~x)-1),~var) => f1(31,x),
  defint_choose(log(~x)*heaviside (1-(~x)),~var) => f1(32,x),
  defint_choose(log(~x)*heaviside ((~x)-1),~var) => f1(33,x),
  defint_choose((log(~x))^(~n)*heaviside (1-(~x)),~var) => f31(n,x),
  defint_choose((log(~x))^(~n)*heaviside ((~x)-1),~var) => f32(n,x),
  defint_choose(log(1+~x),~var) => f1(34,x),
  defint_choose(log((~x+1)/~x),~var) => f1(35,x),
  defint_choose(ei(-~x),~var) => f1(36,x),
  defint_choose(si(~x),~var) => f1(37,x),
  defint_choose(ci(~x),~var) => f1(38,x),
  defint_choose(shi(~x),~var) => f1(39,x),

  defint_choose(erf(~x),~var) => f1(41,x),
  defint_choose(-erf(~x)+1,~var) => f1(42,x),    %erfc(x)
  defint_choose(fresnel_s(~x),~var) => f1(43,x),
  defint_choose(fresnel_c(~x),~var) => f1(44,x),
  defint_choose(gamma(~n,~x),~var) => f1(45,x,n),

  defint_choose(besselj(~n,~x),~var) => f1(50,x,n),
  defint_choose(bessely(~n,~x),~var) => f1(51,x,n),
  defint_choose(besseli(~n,~x),~var) => f1(52,x,n),
  defint_choose(besselk(~n,~x),~var) => f1(53,x,n),
  defint_choose(struveh(~n,~x),~var) => f1(54,x,n),
  defint_choose(struvel(~n,~x),~var) => f1(55,x,n),
  defint_choose(m_legendrep(~n,~x)*heaviside(1-(~x)),~var) =>
                                          f1(56,x,n),
  defint_choose(m_legendrep(~n,1/~x)*heaviside((~x)-1),~var) =>
                                          f1(57,x,n),
  defint_choose((1-(~x))^(-1/2)*m_chebyshevt(~n,~x),~var) =>
                                          f1(58,x,n),
  defint_choose(((~x)-1)^(-1/2)*m_chebyshevt(~n,1/~x),~var) =>
                                          f1(59,x,n),
  defint_choose((1-(~x))^(1/2)*m_chebyshevu(~n,~x),~var) =>
                                          f1(60,x,n),
  defint_choose(((~x)-1)^(1/2)*m_chebyshevu(~n,1/~x),~var) =>
                                          f1(61,x,n),
  defint_choose(m_hermitep(~n,~x),~var) => f1(62,x,n),

  defint_choose(m_laguerrep(~n,~l,~x),~var) => f1(63,x,n,l),

  defint_choose(sqrt(1-~x)*m_gegenbauerp(~n,~l,~x),~var) =>
                                          f1(64,x,n,l),

  defint_choose(sqrt(1-~x)*(1-~x)*m_gegenbauerp(~n,~l,~x),~var) =>
                                          f1(64,x,n,l),

  defint_choose((~x-1)^~k*sqrt(~x-1)*m_gegenbauerp(~n,~l,~x),~var) =>
                                          f1(64,x,n,l),
  defint_choose((~x-1)^~k*sqrt(1-~x)*m_gegenbauerp(~n,~l,~x),~var) =>
                                          f1(64,x,n,l),

  defint_choose(-(~x-1)^~k*sqrt(1-~x)*m_gegenbauerp(~n,~l,~x),~var) =>
                                          f1(64,x,n,l),

  defint_choose(sqrt(~x-1)*m_gegenbauerp(~n,~l,1/~x),~var) =>
                                          f1(65,x,n,l),

  defint_choose(sqrt(~x-1)*(~x-1)*m_gegenbauerp(~n,~l,1/~x),~var) =>
                                          f1(65,x,n,l),

  defint_choose(sqrt(~x-1)*(~x-1)^(~k)*m_gegenbauerp(~n,~k,1/~x),~var)=>
                                          f1(65,x,n,l),

  defint_choose(-sqrt(~x-1)*(~x-1)^(~k)*m_gegenbauerp(~n,~k,1/~x),~var)
                                          => f1(65,x,n,l),

  defint_choose((1-~x)^~r*m_jacobip(~n,~r,~s,~x),~var) =>
                                          f1(66,x,n,r,s),
  defint_choose((~x-1)^~r*m_jacobip(~n,~r,~s,1/~x),~var) =>
                                          f1(67,x,n,r,s),
  defint_choose(0,~var) => f1(0,0),

  defint_choose(~n,~var) => f1(0,n)
     when numberp n,

  defint_choose(~f,~var)        => unknown };  % fallthrough case

let defint_choose_data;

endmodule;


module definte;

algebraic <<

laplace2_rules :=

{ laplace2(1/~x,~f1,~x) => int(1/x*f1*e^(-s*x),x,0,infinity),
  laplace2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(1/sqrt(~x),~f1,~x)=> int(1/sqrt(x)*f1*e^(-s*x),x,0,infinity),
  laplace2(1/(sqrt(~x)*~x),~f1,~x) =>
                 int(1/(sqrt(x)*x)*f1*e^(-s*x),x,0,infinity),
  laplace2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
                 int(1/(sqrt(x)*x^a)*f1*e^(-s*x),x,0,infinity),
  laplace2(~x^~a,~f1,~x) => int(x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(~x,~f1,~x) => int(x*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x),~f1,~x) => int(sqrt(x)*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x)*~x,~f1,~x)=>int(sqrt(x)*x*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x)*~x^~a,~f1,~x) =>
                    int(sqrt(x)*x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(~b,~f1,~x) => int(b*f1*e^(-s*x),x,0,infinity),
  laplace2(~f1,~x) => int(f1*e^(-s*x),x,0,infinity)

};

let laplace2_rules;

hankel2_rules :=

{ hankel2(1/~x,~f1,~x) =>
                int(1/x*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/~x^(~a),~f1,~x) =>
                int(1/x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/sqrt(~x),~f1,~x) =>
                int(1/sqrt(x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/(sqrt(~x)*~x),~f1,~x) =>
            int(1/(sqrt(x)*x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
          int(1/(sqrt(x)*x^a)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~x^~a,~f1,~x) =>
          int(x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~x,~f1,~x) => int(x*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x),~f1,~x) =>
          int(sqrt(x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x)*~x,~f1,~x) =>
          int(sqrt(x)*x,f1,besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x)*~x^~a,~f1,~x) =>
          int(sqrt(x)*x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~b,~f1,~x) => int(b*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~f1,~x) => int(f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity)
};

let hankel2_rules;

y_transform2_rules :=

{ y_transform2(1/~x,~f1,~x) =>
                      int(1/x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(1/~x^(~a),~f1,~x) =>
                    int(1/x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(1/sqrt(~x),~f1,~x) =>
                int(1/sqrt(x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(1/(sqrt(~x)*~x),~f1,~x) =>
            int(1/(sqrt(x)*x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
          int(1/(sqrt(x)*x^a)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(~x^~a,~f1,~x) =>
                int(x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(~x,~f1,~x) =>
                int(x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(sqrt(~x),~f1,~x) =>
                int(sqrt(x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(sqrt(~x)*~x,~f1,~x) =>
                int(sqrt(x)*x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(sqrt(~x)*~x^~a,~f1,~x) =>
              int(sqrt(x)*x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(~b,~f1,~x) =>
              int(b*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  y_transform2(~f1,~x) => int(f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity)
};

let y_transform2_rules;

k_transform2_rules :=

{ k_transform2(1/~x,~f1,~x) =>
                      int(1/x*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(1/~x^(~a),~f1,~x) =>
                    int(1/x^a*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(1/sqrt(~x),~f1,~x) =>
                int(1/sqrt(x)*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(1/(sqrt(~x)*~x),~f1,~x) =>
            int(1/(sqrt(x)*x)*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
          int(1/(sqrt(x)*x^a)*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(~x^~a,~f1,~x) =>
          int(x^a*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(~x,~f1,~x) =>
          int(x*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(sqrt(~x),~f1,~x) =>
          int(sqrt(x)*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(sqrt(~x)*~x,~f1,~x) =>
          int(sqrt(x)*x*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(sqrt(~x)*~x^~a,~f1,~x) =>
          int(sqrt(x)*x^a*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(~b,~f1,~x) =>
          int(b*f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity),
  k_transform2(~f1,~x) => int(f1*besselk(n,2*(s*x)^(1/2)),x,0,infinity)
};

let k_transform2_rules;

struveh2_rules :=

{ struveh2(1/~x,~f1,~x) =>
                 int(1/x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/~x^(~a),~f1,~x) =>
                 int(1/x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/sqrt(~x),~f1,~x) =>
                int(1/sqrt(x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/(sqrt(~x)*~x),~f1,~x) =>
            int(1/(sqrt(x)*x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
          int(1/(sqrt(x)*x^a)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~x^~a,~f1,~x) =>
          int(x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~x,~f1,~x) =>
          int(x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x),~f1,~x) =>
          int(sqrt(x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x)*~x,~f1,~x) =>
          int(sqrt(x)*x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x)*~x^~a,~f1,~x) =>
          int(sqrt(x)*x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~b,~f1,~x) =>
          int(b*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~f1,~x) => int(f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity)
};

let struveh2_rules;

fourier_sin2_rules :=

{ fourier_sin2(1/~x,~f1,~x) => int(1/x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/sqrt(~x),~f1,~x) =>
                                int(1/sqrt(x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/(sqrt(~x)*~x),~f1,~x) =>
                 int(1/(sqrt(x)*x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
                 int(1/(sqrt(x)*x^a)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~x^~a,~f1,~x) => int(x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~x,~f1,~x) => int(x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x),~f1,~x)=> int(sqrt(x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x)*~x,~f1,~x) =>
                 int(sqrt(x)*x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x)*~x^~a,~f1,~x) =>
                 int(sqrt(x)*x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~b,~f1,~x) => int(b*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~f1,~x) => int(f1*sin(s*x),x,0,infinity)
};

let fourier_sin2_rules;

fourier_cos2_rules :=

{ fourier_cos2(1/~x,~f1,~x) => int(1/x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/sqrt(~x),~f1,~x) =>
                int(1/sqrt(x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/(sqrt(~x)*~x),~f1,~x) =>
                int(1/(sqrt(x)*x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/(sqrt(~x)*~x^~a),~f1,~x) =>
                int(1/(sqrt(x)*x^a)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~x^~a,~f1,~x) => int(x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~x,~f1,~x) => int(x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x),~f1,~x)=> int(sqrt(x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x)*~x,~f1,~x) =>
                       int(sqrt(x)*x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x)*~x^~a,~f1,~x) =>
                       int(sqrt(x)*x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~b,~f1,~x) => int(b*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~f1,~x) => int(f1*cos(s*x),x,0,infinity)
};

let fourier_cos2_rules;

>>;

endmodule;


module definth;

fluid '(mellin!-transforms!* mellin!-coefficients!*);

algebraic <<

operator indefint2;

indefint2_rules :=

{ indefint2((~f1+~~f2)/~~f3,~x,~y) =>
         indefint2(f1/f3,x,y)+indefint2(f2/f3,x,y) when not(f2=0),

  indefint2(~n,~f1-~f2,~x,~y) =>
                     indefint2(n,f1,x,y)-indefint2(n,f2,x,y),
  indefint2(~n,~f1+~f2,~x,~y) =>
                     indefint2(n,f1,x,y)+indefint2(n,f2,x,y),

  indefint2(1/~x^(~~a),~f,~x,~y) => transf(defint_choose(f,x),-a,y,x),
  indefint2(~x^(~~b)*sqrt(~x),~f,~x,~y) =>
                 transf(defint_choose(f,x),b+1/2,y,x),
  indefint2(sqrt(~x),~f,~x,~y) =>
                         transf(defint_choose(f,x),1/2,y,x),
  indefint2(~x^(~~a),~f,~x,~y) => transf(defint_choose(f,x),a,y,x),

  indefint2(~b*~ff,~f,~x,~y) => b*indefint2(ff,f,x,y) when freeof (b,x),
  indefint2(~b/(~~c*~ff),~f,~x,~y) => b/c*indefint2(1/ff,f,x,y)
                when freeof (b,x) and freeof (c,x) and not(b=1 and c=1),
  indefint2(~ff/~b,~f,~x,~y) =>
     1/b*indefint2(ff,f,x,y) when freeof (b,x),

  indefint2(~b*~ff,~f,~x,~y) => b*indefint2(ff,f,x,y) when freeof (b,x),
  indefint2(~ff/~b,~f,~x,~y) =>
     1/b*indefint2(ff,f,x,y) when freeof (b,x),

  indefint2(~~b,~f,~x,~y) => b*indefint2(f,x,y)
                         when freeof (b,x) and not(b=1),
  indefint2(~f,~x,~y) => transf(defint_choose(f,x),0,y,x)
};

let indefint2_rules;

symbolic procedure simpinteg(u);

begin scalar ff1,alpha,y,var,chosen_num,coef,!*uncached;

!*uncached := t;
ff1 := prepsq simp car u;

if ff1 = 'unknown then return simp 'unknown;
alpha := cadr u;
y := caddr u;
var := cadddr u;
chosen_num := cadr ff1;

if chosen_num = 0 then << alpha := caddr ff1;
                          return simp reval algebraic(alpha*y)>>
else
<< put('f1,'g,getv(mellin!-transforms!*,chosen_num));
   coef := getv(mellin!-coefficients!*,chosen_num);
   if coef then mellincoef:= coef else mellincoef :=1;

   return  simp list('new_mei,'f1 . cddr ff1,alpha,y,var)>>;

end$

put('new_mei,'simpfn,'new_meijer)$

symbolic procedure new_meijer(u);

begin scalar f,y,mellin,new_mellin,m,n,p,q,old_num,old_denom,temp,a1,
b1,a2,b2,alpha,num,denom,n1,temp1,temp2,coeff,v,var,new_var,new_y,
new_v,k;

f := prepsq simp car u;
y := caddr u;

mellin := bastab(car f,cddr f);

temp := car cddddr mellin;
var := cadr f;
temp := reval algebraic(sub(x=var,temp));

mellin := {car mellin,cadr mellin,caddr mellin,cadddr mellin,temp};

temp := reduce_var(cadr u,mellin);

alpha := simp!* car temp;
new_mellin := cdr temp;

if car cddddr new_mellin neq car cddddr mellin then
        << k := car cddddr mellin;
           y := reval algebraic(sub(x=y,k));
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
else v := prepsq v;

if eqcar(v,'meijerg) then new_v := v else new_v := simp v;
return multsq(new_v,coeff);
end$


symbolic procedure reduce_var(u,v);

% Reduce Meijer G functions of powers of x to x

begin scalar var,m,n,coef,alpha,beta,alpha1,alpha2,expt_flag,k,temp1,
            temp2,const,new_k;

var := car cddddr(v);
beta := 1;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

if length var = 0 then return u . v
else
<< k := u; coef := cadddr v;
   for each i in var do
   << if listp i then
      << if car i = 'expt then
         << alpha := caddr i; expt_flag := 't>>

         else if car i = 'sqrt then
         << beta := 2; alpha := 1; expt_flag := 't>>

         else if car i = 'times then
         << temp1 := cadr i; temp2 := caddr i;

            if listp temp1 then
            << if  car temp1 = 'sqrt then
               << beta := 2; alpha1 := 1; expt_flag := 't>>

               else if car temp1 = 'expt and listp caddr temp1 then
                  << beta := cadr cdaddr temp1;
                     alpha1 := car cdaddr temp1;
                     expt_flag := 't>>;
            >>;

            if listp temp2 and car temp2 = 'expt then
            << alpha2 := caddr temp2; expt_flag := 't>>;

            if alpha1 neq 'nil then

     alpha := reval algebraic(alpha1 + beta*alpha2)
            else alpha := alpha2;
         >>;
      >>
      else
      << if i = 'expt then << alpha := caddr var; expt_flag := 't>>;
      >>;
   >>;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

   if expt_flag = nil then return u . v

% Otherwise reduce the power by using the following formula :-
%
%   y                            (c*y)^(m/n)
%  /                                 /
%  |                           n     |
%  |t^k*F((c*t)^(m/n))dt = --------- |z^[((k + 1)*n - m)/m]*F(z)dz
%  |                       m*c^(k+1) |
%  /                                 /
% 0                                 0

   else

   << if listp alpha then << m := cadr alpha; n := caddr alpha;
                             n := reval algebraic(beta*n)>>

      else << m := alpha; n := beta>>;

      const := reval algebraic(sub(x=1,var));
      const := reval algebraic(1/(const^(n/m)));

      new_k := reval algebraic(((k + 1)*n - m)/m);
      coef := reval algebraic((n/m)*coef*(const)^(k+1));

      var := reval algebraic(var^(n/m));
      return {new_k,car v,cadr v, caddr v,coef,var}>>;
>>;
end$

>>;

endmodule;


module defintk;

% A rule set to test for the validity of the thirty-five cases for
% the validity of the integration of a product of two Meijer
% G-functions.
%
% 'Integrals and Series, Volume 3, More Special Functions',
%  A.P.Prudnikov, Yu.A.Brychkov, O.I.Marichev. Chapter 2.24.1 pages
%  346 & 347

algebraic<<

operator test_cases2,case1,case2,case3,case4,case5,case6,case7,case8,
         case9,case10,case11,case12,case13,case14,case15,case16,case17,
         case18,case19;

test_cases2_rules :=

{test_cases2(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,
        ~rho,~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

   when case1(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case2(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = 't

   or case3(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = 't

   or case4(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = 't

   or case5(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = 't

   or case6(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = t

   or case7(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = t

   or case8(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = t

   or case9(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,r2,
        phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,test_7,
        test_8,test_9,test_10,test_11,test_12,test_13,test_14,test_15)
        = t

   or case10(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case11(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case12(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case13(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case14(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case15(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case16(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case17(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case18(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case19(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case20(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case21(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case22(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case23(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case24(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15)
        = 't

   or case25(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case26(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case27(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case28(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = 't

   or case29(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case30(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case31(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case32(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case33(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case34(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t

   or case35(m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,eta,mu,r1,
        r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
        test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
        test_15) = t
};

let test_cases2_rules;

case1_rules :=

{  case1(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when m*n*k*l neq 0
        and delta > 0
        and epsilon > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_10 = 't and test_12 = 't
        and transform_test('test_2,'test3,'test10,'test12,nil,nil,nil,
        nil) = 't

};

let case1_rules;

case2_rules :=

{  case2(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when u = v
        and delta = 0
        and epsilon > 0
        and sigma_tst(sigma) = 't
        and repart rho < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_12 = 't
        and transform_test('test2,'test3,'test12,'sigma_cond,nil,nil,
        nil,nil) = 't
};

let case2_rules;

case3_rules :=

{  case3(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q
        and epsilon = 0
        and delta >0
        and omega_tst(omega) = 't
        and repart eta < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_10 = 't
        and transform_test(test_2,'test3,'test10,'omega_cond,nil,nil,
        nil,nil) = 't
};

let case3_rules;

case4_rules :=

{  case4(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q
        and u = v
        and delta = 0
        and epsilon = 0
        and sigma_tst(sigma) = 't
        and omega_tst(omega) = 't
        and repart eta < 1
        and repart rho < 1
        and sigma^r1 neq omega^r2
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't
        and transform_test('test_2,'test3,'sigma_cond,'omega_cond,nil,
        nil,nil,nil) = 't
};

let case4_rules;


case5_rules :=

{  case5(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q
        and u = v
        and delta = 0
        and epsilon = 0
        and sigma_tst(sigma) = 't
        and omega_tst(omega) = 't
        and repart(eta + rho) < 1
        and sigma^r1 neq omega^r2
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't
        and transform_test('test2,'test3,'sigma_cond,'omega_cond,nil,
        nil,nil,nil) = 't
};

let case5_rules;

case6_rules :=

{  case6(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p > q
        and k > 0
        and delta > 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_5 = 't and test_10 = 't
        and test_13 = 't
        and transform_test('test3,'test5,'test10,'test13,nil,nil,nil,
        nil) = 't

};

let case6_rules;

case7_rules :=

{  case7(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p < q
        and l > 0
        and delta > 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_4 = 't and test_10 = 't
        and test_13 = 't
        and transform_test('test3,'test4,'test10,'test13,nil,nil,nil,
        nil) = 't

};

let case7_rules;


case8_rules :=

{  case8(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when u > v
        and m > 0
        and delta >= 0
        and epsilon > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_7 = 't and test_11 = 't
        and test_12 = 't
        and transform_test('test3,'test7,'test11,'test12,nil,nil,nil,
        nil) = 't

};

let case8_rules;

case9_rules :=

{  case9(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when u < v
        and n > 0
        and delta >= 0
        and epsilon > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_6 = 't and test_11 = 't
        and test_12 = 't
        and transform_test('test2,'test3,'test6,'test11,'test12,nil,
        nil,nil) = 't

};

let case9_rules;


case10_rules :=

{  case10(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p > q
        and u = v
        and delta = 0
        and epsilon >= 0
        and sigma_tst(sigma) = 't
        and repart rho < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_5 = 't and test_13 = 't
        and transform_test('test2,'test3,'test5,'test13,'sigma_cond,
        nil,nil,nil) = 't


};

let case10_rules;

case11_rules :=

{  case11(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p < q
        and u = v
        and delta = 0
        and epsilon >= 0
        and sigma_tst(sigma) = 't
        and repart rho < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_4 = 't and test_13 = 't
        and transform_test('test2,'test3,'test4,'test13,'sigma_cond,
        nil,nil,nil) = 't
};

let case11_rules;

case12_rules :=

{  case12(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q
        and u > v
        and delta >= 0
        and epsilon = 0
        and omega_tst(omega) = 't
        and repart eta < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_7 = 't and test_11 = 't
        and transform_test('test2,'test3,'test7,'test11,'omega_cond,
        nil,nil,nil) = 't
};

let case12_rules;

case13_rules :=

{  case13(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p = q
        and u < v
        and delta >= 0
        and epsilon = 0
        and omega_tst(omega) = 't
        and repart eta < 1
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_6 = 't and test_11 = 't
        and transform_test('test2,'test3,'test6,'test11,'omega_cond,
        nil,nil,nil) = 't
};

let case13_rules;

case14_rules :=

{  case14(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p < q
        and u > v
        and delta >= 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_4 = 't and test_7 = 't
        and test_11 = 't and test_13 = 't
        and transform_test('test2,'test3,'test4,'test7,'test11,'test13,
        nil,nil) = 't
};

let case14_rules;

case15_rules :=

{  case15(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p > q
        and u < v
        and delta >= 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_5 = 't and test_6 = 't
        and test_11 = 't and test_13 = 't
        and transform_test('test2,'test3,'test5,'test6,'test11,'test13,
        nil,nil) = 't
};

let case15_rules;

case16_rules :=

{  case16(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p > q
        and u > v
        and delta >= 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_5 = 't and test_7 = 't
        and test_8 = 't and test_11 = 't and test_13 = 't
        and test_14 = 't
        and transform_test('test2,'test3,'test5,'test7,'test8,'test11,
        'test13,'test14) = 't
};

let case16_rules;

case17_rules :=

{  case17(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when p < q
        and u < v
        and delta >= 0
        and epsilon >= 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_3 = 't and test_4 = 't and test_6 = 't
        and test_9 = 't and test_11 = 't and test_13 = 't
        and test_14 = 't
        and transform_test('test2,'test3,'test4,'test6,'test9,'test11,
        'test13,'test14) = 't
};

let case17_rules;

case18_rules :=

{  case18(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when l = 0
        and k > 0
        and delta > 0
        and phi > 0
        and test_1a = 't and test_1b = 't and test_2 = 't
        and test_10 = 't
        and transform_test('test2,'test10,nil,nil,nil,nil,nil,nil) = 't
};

let case18_rules;

case19_rules :=

{  case19(~m,~n,~p,~q,~k,~l,~u,~v,~delta,~epsilon,~sigma,~omega,~rho,
        ~eta,~mu,~r1,~r2,~phi,~test_1a,~test_1b,~test_2,~test_3,
        ~test_4,~test_5,~test_6,~test_7,~test_8,~test_9,~test_10,
        ~test_11,~test_12,~test_13,~test_14,~test_15) => 't

     when k = 0
        and l > 0
        and delta > 0
        and phi < 0
        and test_1a = 't and test_1b = 't and test_3 = 't
        and test_10 = 't
        and transform_test('test10,nil,nil,nil,nil,nil,nil,nil) = 't
};

let case19_rules;
>>;

endmodule;


module defintx;  % Code for definite integration using contour methods.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

load_package solve,misc;

fluid '(!*allpoly rdon!* !*norationalgi); switch allpoly;

global '(domainlist!* poles!*);

algebraic <<
logcomplex :=
 {
  log(~x + i) =>
      log(sqrt(x*x+1))+i*atan2(1/sqrt(x*x+1),x/sqrt(x*x+1))
      when repart(x)=x,
  log(~x - i) =>
      log(sqrt(x*x+1))-i*atan2(1/sqrt(x*x+1),x/sqrt(x*x+1))
      when repart(x)=x,
  log(~x + i*~y) =>
      log(sqrt(x*x+y*y))+i*atan2(y/sqrt(x*x+y*y),x/sqrt(x*x+y*y))
      when repart(x)=x and repart(y)=y,
  log(~x - i*~y) =>
      log(sqrt(x*x+y*y))-i*atan2(y/sqrt(x*x+y*y),x/sqrt(x*x+y*y))
      when repart(x)=x and repart(y)=y,
  log(~x/~y) => log(x) - log(y) when repart(y)=y,
  log(sqrt ~x) => (log x)/2,
  log(-1) => i*pi,
  log (-i) => -i*pi/2,
  log i => i*pi/2,
  log(-~x) => i*pi+log x when repart(x)=x and numberp x and x>0,
  log(-i*~x) => -i*pi/2 + log x
       when repart(x)=x and numberp x and x>0,
  log(i*~x) => i*pi/2 + log x  when repart(x)=x and numberp x and x>0
}$

atan2eval :=
 {
  atan2(sqrt 3/2,1/2) => pi/3,
  atan2(-sqrt 3/2,1/2) => -pi/3,
  atan2(sqrt 3/2,-1/2) => 2*pi/3,
  atan2(-sqrt 3/2,-1/2) => -2*pi/3,
  atan2(3/(2*sqrt 3),1/2) => pi/3,      % these shouldn't be needed
  atan2(-3/(2*sqrt 3),1/2) => -pi/3,    % these shouldn't be needed
  atan2(3/(2*sqrt 3),-1/2) => 2*pi/3,   % these shouldn't be needed
  atan2(-3/(2*sqrt 3),-1/2) => -2*pi/3, % these shouldn't be needed
  atan2(1/2,sqrt 3/2) => pi/6,
  atan2(-1/2,sqrt 3/2) => -pi/6,
  atan2(1/2,-sqrt 3/2) => 5*pi/6,
  atan2(-1/2,-sqrt 3/2) => -5*pi/6,
  atan2(1/2,3/(2*sqrt 3)) => pi/6,      % these shouldn't be needed
  atan2(-1/2,3/(2*sqrt 3)) => -pi/6,    % these shouldn't be needed
  atan2(1/2,-3/(2*sqrt 3)) => 5*pi/6,   % these shouldn't be needed
  atan2(-1/2,-3*(2*sqrt 3)) => -5*pi/6, % these shouldn't be needed
  atan2(sqrt 2/2,sqrt 2/2) => pi/4,
  atan2(-sqrt 2/2,sqrt 2/2) => -pi/4,
  atan2(sqrt 2/2,-sqrt 2/2) => 3*pi/4,
  atan2(-sqrt 2/2,-sqrt 2/2) => -3*pi/4,
  atan2(0,-1) => pi,
  atan2(0,1) => 0,
  atan2(1,0) => pi/2,
  atan2(-1,0) => -pi/2
}$

ipower := {i^~n => cos(n*pi/2) + i*sin(n*pi/2),
    (-i)^~n => cos(n*pi/2) - i*sin(n*pi/2)}$

>> $

algebraic let ipower,atan2eval;

%algebraic let logcomplex,atan2eval;

fluid '(!*diffsoln zplist!! poles!# !*msg !*rounded !*complex zlist);
switch diffsoln;

load_package int;

put('defint,'psopfn,'defint0);

symbolic procedure defint0 u;
   begin
      scalar rdon!*,!*msg,c,!*noneglogs,fac,!*norationalgi,
         !*combinelogs,!*rationalize;
      if not getd 'solvesq then load_package solve;
      if length u neq 4 then rederr
        "defint called with wrong number of args";
      c := !*complex; off complex; % since complex on won't work here!
    %  on complex;  % this causes trouble here, so it was moved into
                    % defint11s after splitfactors has operated!
      !*noneglogs := t;
      algebraic (let logcomplex); %,atan2eval);
      fac := !*factor; on factor; !*norationalgi := t;
      u := errorset2 {'defint1,mkquote u};
      !*norationalgi := nil;
      if errorp u then <<u := 'failed; go to ret>> else u := car u;
      off factor;
      if !*rounded then
       % if approximate answer, eliminate infinitessimal real or
       % imaginary part.
          (<<off complex;
            if domainp numr u and denr u = 1 then
              (if evallessp({'times,{'abs,prepsq im},eps},
                 {'abs,prepsq rl})
                  then u := rl else
               if evallessp({'times,{'abs,prepsq rl},eps},
                 {'abs,prepsq im})
                  then u := addsq(u,negsq rl));
            u := mk!*sq u;
            if rdon!* then off rounded;off complex; go to ret2>>
          where rl=repartsq u,im=impartsq u,eps=10.0^(2-precision 0));
      !*rationalize := t;
      u := aeval prepsq u;
      on complex;
      u := simp!* u;
   %   u := evalletsub2({'(logcomplexs),
   %      {'simp!*,{'prepsq,mkquote u}}},nil);
   %   if errorp u then error(99,list("error during log simp"))
   %      else u := car u;
 ret: if fac then on factor;
      algebraic (clearrules logcomplex); %,atan2eval);
      if u neq 'failed then u := prepsq u;
      off complex; on combinelogs;
      if u neq 'failed then u := aeval u;
ret2: if c then on complex;
      return u end;

symbolic procedure defint1 u; defint11s(car u,cadr u,caddr u,cadddr u);

symbolic procedure defint11s(exp,var,llim,ulim);
  % removes from integrand any factors independent of var, and passes
  % the dependent factors to defint11.  Based on FACTOR being on.
   <<% off complex; % not needed here since complex is off already.
     exp := splitfactors(simp!* aeval exp,var);
     on complex; % at this point it is safe to turn complex on.
     multsq(simp!* car exp,
        defint11(cadr exp,var,llim,ulim,t))>>;

symbolic procedure fxinfinity x;
  if x eq 'infinity then 'inf
   else if x = '(minus infinity) then 'minf else x;

symbolic procedure defint11(exp,var,llim,ulim,dtst);
  if evalequal(llim := fxinfinity llim, ulim := fxinfinity ulim)
    or evalequal(exp,0) then nil ./ 1 else
  begin scalar !*norationalgi,r,p,q,poles,rlrts,cmprts,q1;
     scalar m,n;
     if ulim = 'minf or llim = 'inf then
        return defint11({'minus,exp},var,ulim,llim,dtst);
     exp := simp!* exp;
    % Now the lower limit must be 'minf or a finite value,
    % and the upper limit must be 'inf or a finite value. There are
    % four cases:
    % Upper limit is 'inf.  Convert lower limit to zero if necessary,
    % and use methods for infinite integrals.
     if ulim = 'inf then
        <<if not(llim member '(0 minf)) then
            <<exp := subsq(exp,{var . {'plus,var,llim}}); llim := 0>>;
          go to c0>>;
    % lower limit is 'minf.  Convert this case to upper limit 'inf.
     if llim = 'minf then
        <<off complex;
          exp := reval prepsq subsq(exp,{var . {'minus,var}});
          llim := reval {'minus,ulim};
          on complex;
          return defint11(exp,var,llim,'inf,dtst)>>;
    % Both limits are finite, so check for indef integral and
    % substitute values if it exists; else check for special forms with
    % finite limits, try substitutions, or abort.
     r := simpint {prepsq exp,var};
     if eqcar(prepsq r,'int) then go to c1;
     p := subsq(r,{var . ulim}); q := subsq(r,{var . llim});
     return q1 := addsq(p,negsq q);
 c1: rederr "special forms for finite limits not implemented";
 c0: r := exp; p := numr r; q := denr r;
  %   if not polynomp(q,var) then
   %     rederr "only polynomial denominator implemented";
     m := degreeof(p,var); n := degreeof(q,var);
     if smemql('(failed infinity),m) or smemql('(failed infinity),n)
       then return 'failed;
    % Note that degreeof may return a fraction or a general complex
    % quantity.
     if not evalgreaterp(prepsq addsq(repartsq n,negsq repartsq m),1)
        then go to div;
    % this is the point at which special cases can be tested.
     if (q1 := specformtestint(q,p,var,llim,ulim)) then return q1;
    % beyond here, only rational functions are handled.
     if not (m := sq2int m) or not (n := sq2int n) then
       <<write "this irrational function case not handled"; terpri();
         error(99,'failed)>>;
     if n - m < 2 then go to div;
     if dtst and !*diffsoln then
        if (q1 := diffsol(q,p,m,n,var,llim,ulim)) then return q1;
     off factor; !*norationalgi := nil;
     poles := getpoles(q,var,llim);
     rlrts := append(car poles,cadr poles); cmprts := caddr poles;
     !*norationalgi := t;
     q1 := difff(q,var); q := q ./ 1;  p := p ./ 1;
     return if llim = 0 then defint2(p,q,q1,var,rlrts,cmprts)
        else defint3(p,q,q1,var,rlrts,cmprts);
div: % write "integral diverges"; terpri();
     error(99,'failed) end;

symbolic procedure zpsubsq x;
   subsq(x,for each v in zplist!! collect (v . 0));

symbolic procedure degreeof(p,var);
   % p is a standard form.
   % Note that limit returns "failed" as a structure, not an id.
   % Also, the limit code has problems with besseli at the present time.
  if smemq('besseli,p) then !*k2q 'failed else
  (if null car de then de else
    <<if d then onoff(d := get(d,'dname),nil);
      p := simp!*
              limit(list('quotient,list('times,var, prepsq de),prepf p),
                    var,'infinity);
      if d then onoff(d,t); p>>)
    where d=dmode!*,de=difff(p,var);

symbolic procedure genminusp x;
   if domainp x then !:minusp x else !:minusp topeval prepf x;

symbolic procedure sq2int x;
  (if null numr impartsq x and denr y=1
     then if null z then 0 else if numberp z then z else nil)
   where z=numr y where y=repartsq x;

symbolic procedure topeval u;
  <<if not r then on rounded; if not c then on complex;
    u := numr simp!* aeval u;
    if not r then off rounded;if not c then off complex; u>>
  where r=!*rounded,c=!*complex,!*msg=nil;

symbolic procedure firstatom x;
   if atom x then x else firstatom car x;

symbolic procedure valueof u;
   (if firstatom x neq 'root_of then x) where x=caar u;

symbolic procedure rdsolvesq u;
   solvesq(subf(numr simp!* cadr x,list((caddr x) . caadr u)),
        caadr u,caddr u)
   where x=caaaar caar u;

symbolic procedure defint2(p,q,q1,var,rlrts,cmprts);
  % Does the actual computation of integral with limits 0, inf.
  % Pertinent poles and their orders have been found previously.
     begin scalar int;
        p := simp!* aeval{'times,{'log,{'minus,var}},prepsq p};
        int := nil ./ 1;
        for each r in append(rlrts,cmprts) do
           int := addsq(int,residuum(p,q,q1,var,prepsq car r,cdr r));
        return negsq int end;

symbolic procedure defint3(p,q,q1,var,rlrts,cmprts);
  % Does the actual computation of integral with limits minf, inf.
  % Pertinent poles and their orders have been found previously.
     begin scalar int,int2;
        int := int2 := nil ./ 1;
        for each r in cmprts do
           int := addsq(int,residuum(p,q,q1,var,prepsq car r,cdr r));
        int := addsq(int,int);
        for each r in rlrts do
           int2 := addsq(int2,residuum(p,q,q1,var,prepsq car r,cdr r));
        int := addsq(int,int2);
        return multsq(simp!* '(times pi i),int) end;

symbolic procedure diffsqn(sq,var,n);
   <<if n>0 then for j := 1:n do sq := diffsq(sq,var); sq>>;

symbolic procedure polypwrp(exp,var);
   begin scalar pol,fl; integer s,pwr;
     if eqcar(exp,'expt) then
       <<pol := cadr exp; if (pwr := caddr exp) <2 then return nil;
         if atom pol then
           if var eq pol then s := 1 else return nil
         else if not eqcar(pol,'plus) then return nil
         else for each p in cdr pol do s := max(s,termvpwr(p,var));
         return if s = 0 then nil else {pol,s,pwr}>>
     else if eqcar(exp,'times) then
       <<exp := for each p in cdr exp collect polypwrp(p,var);
         for each p in exp do
           <<if null p then fl := t;
             if not fl then pwr := gcdn(pwr,caddr p)>>;
         if fl then return nil;
         s := (for each p in exp sum cadr p * caddr p)/pwr;
         pol := 'times .
           for each p in exp collect {'expt,car p,caddr p/pwr};
         return {pol,s,pwr}>> end;

symbolic procedure termvpwr(p,var);
   if freeof(p,var) then 0
   else if atom p then 1
   else if eqcar(p,'expt) and cadr p = var and
     numberp caddr p then caddr p
   else if eqcar(p,'times) then for each q in cdr p sum termvpwr(q,var)
   else 0;

symbolic procedure diffsol(q,p,mm,nn,var,llim,ulim);
  % p is numerator   q is denom    mm is deg p   nn is deg q
   (q := polypwrp(prepf q,var)) and
   begin scalar n,s,m,r,zplist!!;
     n := mm; s := cadr q; m := caddr q;
    % if s, the power of the base polynomial, > 4 then the base
    % polynomial won't be solved, and this approach won't work!
    % However, for s > 2, the approach is impractical, because the
    % roots of the zp!! polynomial are too complicated, so in the
    % following, s is tested s > 2.
     if s > 2 or m*s neq nn or nn - n <= 2 then return nil;
     r := (n+2)/s; if r*s < n+2 then r := r+1;
     if m = r then return nil;
     q := {'plus,car q,'zp!!}; zplist!! := '(zp!!);
     q := numr simp!*{'expt,q,r};
     nn :=(-1)^(m - r)*factorial(r - 1) ./ factorial(m - 1);
     p := defint11(prepsq(p ./ q),var,llim,ulim,nil);
     p := zpsubsq diffsqn(p,'zp!!,m - r);
     return multsq(nn,p) end;

symbolic procedure residuum(p,q,q1,var,pole,m);
   if m=1 then subsq(quotsq(p,q1),list(var . pole))
   else
   begin integer n;
     q1 := nil;
     for each r in poles!* do
       <<n := cdr r; r := prepsq car r;
         if not evalequal(pole,r)
           then q1 := {'expt,{'difference,var,r},n} . q1>>;
     n := ((lc numr simp!* prepsq q) where !*factor=nil);
     q1 := 'times . (n . q1);
     return if ((lt numr simp!* prepsq q =
       lt numr simp!*{'times,{'expt,{'difference,var,pole},m},q1})
          where !*factor=nil)
       then
           <<q := quotsq(p,simp!* q1);
             q := diffsqn(q,var,m - 1);
             q := subsq(q,{var . pole});
             q := if null numr q
               then q else quotsq(q,factorial(m -1) ./ 1)>>
         else q1 := simp!* (p := limit(
           prepsq
             quotsq(diffsqn(multsq(quotsq(p,q),
                 simp!* {'expt,{'difference,var,pole},m}),var,m - 1),
               factorial(m - 1) ./ 1),var,pole)) end;

symbolic procedure splitfactors(u,var);
  % returns a list of two factors:
  % independent of var and dependent on var.
   begin scalar n,d,ni,nd,di,dd,fli,fld;
     n := prepf numr u;
     if n=0 then return {0,0};
     d := prepf denr u;
     ni := nd := di := dd := 1;
     if simptermp n then
       <<if freeof(n,var) then ni := n else nd := n; go to d>>;
     for each x in cdr n do
         if freeof(x,var) then ni := if ni = 1 then list x
              else <<fli := t; x . ni>>
            else nd := if nd = 1 then list x else <<fld := t; x . nd>>;
     ni := fleshoutt(ni,fli); nd := fleshoutt(nd,fld);
     fli := fld := nil;
  d: if simptermp d then
       <<if freeof(d,var) then di := d else dd := d; go to ret>>;
     for each x in cdr d do
         if freeof(x,var) then di := if di = 1 then list x
              else <<fli := t; x . di>>
            else dd := if dd = 1 then list x else <<fld := t; x . dd>>;
     di := fleshoutt(di,fli); dd := fleshoutt(dd,fld);
ret: return {fleshout(ni,di),fleshout(nd,dd)} end;

symbolic procedure simptermp x;
   atom x or ((y = 'minus and simptermp cadr x or y neq 'times)
     where y=car x);

symbolic procedure fleshout(n,d); if d = 1 then n else {'quotient,n,d};

symbolic procedure fleshoutt(n,d);
   if n = 1 then n else if d then 'times . n else car n;

symbolic procedure specformtestint(den,num,var,llim,ulim);
  % This tests for defint(x^(p-1)/(a*x^n+b)^m,x,0,inf) with
  % m,n,p positive integers, p/n not integer and m>(p/n) and either
  %    a*b>0   or   {a*b<0,m=1}.
  % Since splitfactors has removed all factors which do not depend upon
  % var, both num and den are either 1 or products of terms which
  % depend upon var.
   begin scalar a,b,d,m,n,p,q1,q,k,z,ff;
     den := prepf den; num := prepf num;
     if not(llim=0) and ulim='inf then go to t2;
    % This is the test for defint(y**(q-1)/(a*y**n +b)**m,y,0,inf);
    % which is converted to defint(x**(p-1)/(x+z)**m,x,0,inf);
    % the next test is assumed to be accessed at label t2.
     if num = 1 then q1 := 0
       else if (q1 := varpwrtst(num,var))=0 then go to t2;
     if atom den then go to t2
       else if not eqcar(den,'times) then
        %only (a*y**n+b)**m term in den.
         if (k := aynbmtst(den,var)) then go to sep4 else go to t2
       else if length den neq 3 then go to t2;
    % the denominator is the product of 2 terms, one of which must be
    % y**q and the other an aynbm form like the previous case.
     d := cdr den;
     if not((k := aynbmtst(cadr d,var))
            and eqcar(q := varpwrtst(car d,var),'quotient)
            or
            (k := aynbmtst(car d,var))
            and eqcar(q := varpwrtst(cadr d,var),'quotient))
              then go to t2;
sep4: n := caddr k; if not numberp n then go to t3;
     q := prepsq simp!* {'plus,1,q1,{'minus,q}};
     p := prepsq simp!* {'quotient,q,n};
     m := cadddr k; if not numberp m or m<1 then go to t3;
     a := car k;
     b := cadr k;
     z := prepsq simp!* {'quotient,b,a};
       if numr impartsq simp!* z then go to t2;
     ff := prepsq simp!* aeval {'quotient,1,{'times,n,{'expt,a,m}}};
    % there are two different cases:
    %  z > 0 and m >repart p >0  m >= 1
    %  z < 0 and m=1 (Cauchy principal value)
     if evalgreaterp(z,0) then if
       not (evalgreaterp((k := prepsq repartsq simp!* p),0) and
         evalgreaterp(m,k))
       then go to t3
     else
      <<k := prepsq simp!* aeval
          {'times,{'expt,-1,m+1},'pi,{'expt,z,{'difference,p,m}}};
        n := 1;
        for c := 1:(m-1) do
          n := prepsq simp!* aeval {'times,n,{'difference,p,c}};
        q := prepsq simp!* aeval
          {'times,{'factorial,m-1},{'sin,{'times,p,'pi}}};
        return simp!* aeval {'quotient,{'times,k,n,ff},q}>>;
    if m neq 1 then go to t3;
    write "Cauchy principal value"; terpri();
    k := prepsq simp!* aeval
      {'minus,{'expt,{'quotient,-1,z},{'difference,1,p}}};
    q := prepsq simp!* aeval
      {'times,ff,{'quotient,'pi,{'times,a,n}},{'cot,{'times,'pi,p}}};
    return simp!* aeval {'times,k,q};
t3: return nil; % most (if not all) of these are divergence cases.
t2: return specformtestint2(den,num,var,llim,ulim) end;

symbolic procedure aynbmtst(exp,var);
  % test for form (a*y**n+b)**m (or degenerate forms of this) and
  % extract parameters a,n,b,m.  b qnd m are required to be present.
  % car exp = 'expt or else m=1.
   begin scalar a,b,m,n;
      if not eqcar(exp,'expt) then <<m := 1; goto a2>>;
      m := caddr exp;
      exp := cadr exp;
  a2: if not eqcar(exp,'plus) or length exp neq 3 then return nil;
      b := caddr exp;
      if eqcar(cadr exp,'times) then
         <<exp := cdadr exp;
           if length exp neq 2 or not(
             numberp (a := car exp)
               and (n := varpwrtst(cadr exp,var)) neq 0
             or
             numberp (a := cadr exp)
               and (n := varpwrtst(car exp,var)) neq 0)
             then return nil>>
        else
          <<a := 1;
            if (n := varpwrtst(cadr exp,var)) = 0 then return nil>>;
      return {a,b,n,m} end;

fluid '(!*fullpoly); switch fullpoly;

symbolic procedure getpoles(q,var,llim);
   begin scalar poles,rt,m,rlrt,cmprt,rtv,rtvz,cpv,prlrts,nrlrts,rlrts,
       cmprts,!*multiplicities,!*fullroots,!*norationalgi;
     off factor; !*norationalgi := poles!* := nil;
     !*multiplicities := t;
    if !*fullpoly then !*fullroots := t;
    % if !*allpoly = 'all then
    %   <<on rounded; rdon!* := t; write "test mode"; terpri()>>;
     poles := solvesq(simp!* prepf q,var,1);
     !*norationalgi := t;
 lp: if null poles then go to int;
     rt := car poles; poles := cdr poles; m := caddr rt;
     rlrt := cmprt := nil;
     if (rtv := valueof rt) then
        <<poles!* := (rtv . m) . poles!*;
          rtvz := zpsubsq rtv; rt := car impartsq rtvz;
          if null rt or
            (rt := topevalsetsq prepf rt) and evalequal(0,prepsq rt)
            then rlrt := rtv else cmprt := rtv;
          if llim = 0 then
             <<if rlrt then
                <<if null car rtvz then go to div
                  else if not genminusp car rtvz then
                     <<if m > 1 then go to div else cpv := t;
                       prlrts := (rlrt . m) . prlrts>>
                     else nrlrts := (rlrt . m) . nrlrts>>
               else cmprts := (cmprt . m) . cmprts; go to lp>>
          else
             <<if rlrt then
                  <<if m > 1 then go to div else cpv := t;
                    rlrts := (rlrt . m) . rlrts>>
               else if not genminusp car impartsq rtvz then
                  cmprts := (cmprt . m) . cmprts>>;
          go to lp>>;
una: if !*rounded then rederr "unable to find poles approximately";
     if not !*allpoly then <<write
        "Denominator degree > 4.  Approx integral requires ON ALLPOLY";
        terpri(); error(99,"failed")>>
        else <<write "approximate integral only"; terpri()>>;
     on rounded; rdon!* := t;
     if valueof car(rt := rdsolvesq rt) then
        <<poles := append(rt,poles); go to lp>>;
     go to una;
div: % write "integral diverges"; terpri();
     error(99,'failed);
int: if cpv then <<write "Cauchy principal value"; terpri()>>;
     return if llim=0 then {prlrts,nrlrts,cmprts}
         else {rlrts,nil,cmprts} end;

symbolic procedure specformtestint2(den,num,var,llim,ulim);
  % This checks for defint(x^k*R(x),x,0 inf) where {k != 0,-1<k<1} and
  % limit+(x^(k+1)*R(x),x,0)=limit(x^(k+1)*R(x),x,inf)=0 where R is
  % a rational function with no poles of order >1 on positive real axis.
   begin scalar d,k,k1,m,p,p1,q,q1,poles,prpoles,s1,s2;
     if not(llim=0) and ulim='inf then go to t2;
     p1 := polanalyz(num,var);
     k1 := polanalyz(den,var);
     if not (p1 or k1) then go to t2;
     k := prepsq simp!* aeval {'difference,p1,k1};
     if numberp k or not(evalgreaterp(k,-1) and evalgreaterp(1,k))
        then go to t2;%<==  this was t3 but caused problem!
     if (d := dmode!*) then onoff(d := get(d,'dname),nil);
     m := prepsq simp!* aeval {'quotient,{'times,var,num},den};
     if numr simp!* limit!+(m,var,0)
       or numr simp!* limit(m,var,'infinity) then go to t3;
     if d then onoff(d,t);
    % all tests met, except for finding poles of den.
    % move irrational factor to numerator, changing the sign of var.
     p := simp!* aeval {'times,num,
        {'expt,var,{'times,-1,p1}},{'expt,{'minus,var},k}};
    % note that p in general has a non-trivial denominator.
    % now remove irrational factor from denominator, leaving polynomial.
       q := simp!* aeval {'times,den,{'expt,var,{'times,-1,k1}}};
       q1 := diffsq(q,var);
     poles := getpoles(numr q,var,llim);
     prpoles := car poles; poles := append(cadr poles,caddr poles);
     s1 := s2 := nil ./ 1;
     k1 := {'times,'pi,{'plus,k,1}};
     if poles then
       <<for each r in poles do
           s1 := addsq(s1,residuum(p,q,q1,var,prepsq car r,cdr r));
         s1 := {'quotient,{'times,'pi,prepsq s1},{'sin,k1}}>>
       else s1 := 0;
     if prpoles then
       <<for each r in prpoles do
           s2 := addsq(s2,residuum(p,q,q1,var,prepsq car r,cdr r));
         s2 := {'times,'pi,prepsq s2,{'cot,k1}}>>
       else s2 := 0;
     return simp!* aeval {'difference,s1,s2};
 t2: return nil;  % replace by call to next test.
 t3: % write "integral diverges"; terpri();
     error(99,'failed)  end;

symbolic procedure polanalyz(exp,var);
  % test for fractional power of var in exp.
   if poltstp exp then
   ((if eqcar(
     exp := varpwrtst(if eqcar(ex2,'times) then cadr ex2 else ex2,var),
      'quotient) then exp else 0)
    where ex2=if eqcar(exp,'minus) then cadr exp else exp);

symbolic procedure poltstp exp;
   atom exp and exp or car exp member domainlist!* or
     car exp member '(plus times quotient minus expt sqrt) and
   begin scalar fg;
     for each c in cdr exp do if not poltstp c then fg := t;
     return null fg end;

symbolic procedure evalmax(a,b);
   if numberp a and numberp b then max(a,b)
     else if evalgreaterp(a,b) then a else b;

symbolic procedure evalplus(a,b);
   if numberp a and numberp b then a+b
   else prepsq simp!* aeval {'plus,a,b};

symbolic procedure varpwrtst(exp,var);
   if atom exp then if exp = var then 1 else 0
   else if car exp eq 'minus then varpwrtst(cadr exp,var)
   else if car exp member '(plus,difference) then
     (<<for each c in cdr exp do q := evalmax(q,varpwrtst(c,var)); q>>
      where q=0)
   else if eqcar(exp,'expt) then
     prepsq simp!* aeval{'times,varpwrtst(cadr exp,var),caddr exp}
   else if eqcar(exp,'sqrt) then
     prepsq simp!* aeval{'times,varpwrtst(cadr exp,var),{'quotient,1,2}}
   else if eqcar(exp,'times) then
     (<<for each c in cdr exp do q := evalplus(q,varpwrtst(c,var)); q>>
      where q=0)
   else 0;

endmodule;


end;
