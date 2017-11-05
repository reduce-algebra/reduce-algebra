%***********************************************************************
%*                             INTEGRATION                             *
%***********************************************************************

module definta;

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


transform_lst := '();

algebraic operator f1$
algebraic operator f2$

fluid '(mellincoef);

%%fluid '(plotsynerr!*);

%***********************************************************************
%*                          MAIN PROCEDURES                            *
%***********************************************************************

symbolic inline procedure defint_gw u;
  % coefficient of integration variable in argument of MeijerG
  caar u$

symbolic inline procedure defint_gl u;
  % numerator of power of integration variable in argument of MeijerG
  caadar u$

symbolic inline procedure defint_gk u;
  % denominator of power of integration variable in argument of MeijerG
  cdadar u$

symbolic inline procedure defint_gr u;
  % power of integration variable in argument of MeijerG
  cadar u$

symbolic inline procedure defint_gm u;
  % upper left index of MeijerG
  caadr u$

symbolic inline procedure defint_gn u;
  % upper right index of MeijerG
  cadadr u$

symbolic inline procedure defint_gp u;
  % lower left index of MeijerG
  caddr cadr u$

symbolic inline procedure defint_gq u;
  % lower right index of MeijerG
  cadddr cadr u$

symbolic inline procedure defint_ga u;
  % list of upper parameters of MeijerG
  caddr u$

symbolic inline procedure defint_gb u;
  % list of lower parameters of MeijerG
  cadddr u$

%*******
% See also plotnum.red and ludecom.red where there are slighly different
% versions of these rdwrap functions: it looks as if originally they may
% have all been mere copies of the same thing but that bug-fixes or upgrades
% were applie din just one place. So really they all need review and
% consolidation.
%*******
% symbolic procedure defint_rdwrap f;
% if numberp f then float f
%   else if f='pi then 3.141592653589793238462643
%   else if f='e then 2.7182818284590452353602987
%   else if atom f then f
%   else if eqcar(f, '!:rd!:) then
%           if atom cdr f then cdr f else bf2flr f
%   else if eqcar(f, '!:dn!:) then defint_rdwrap2 cdr f
%   else if eqcar(f, 'minus) then
%     begin scalar x;
%        x := defint_rdwrap cadr f;
%        return if numberp x then minus float x else {'minus, x}
%     end
%   else if get(car f, 'dname) then
%     << plotsynerr!*:=t;
%        rerror(plotpackage, 32, {get(car f, 'dname),
%                                 "illegal domain for PLOT"})
%     >>
%   else if eqcar(f,'expt) then defint_rdwrap!-expt f
%   else defint_rdwrap car f . defint_rdwrap cdr f;
%
% symbolic procedure defint_rdwrap!-expt f;
% % preserve integer second argument.
%   if fixp caddr f then {'expt!-int,defint_rdwrap cadr f,caddr f}
%     else {'expt,defint_rdwrap cadr f, defint_rdwrap caddr f};
%
% symbolic procedure defint_rdwrap2 f;
% % Convert from domain to LISP evaluable value.
%   if atom f then f else float car f * 10^cdr f;
%
% symbolic procedure defint_rdwrap!* f;
% % convert a domain element to float.
%   if null f then 0.0 else defint_rdwrap f;
%
% % Also in plotnum.red
% symbolic procedure rdunwrap f;
%   if f=0.0 then 0 else if f=1.0 then 1 else '!:rd!: . f;
%
% also in ludecom.red and plotnum.red with same definition
% symbolic procedure expt!-int(a,b); expt(a,fix b);

put('intgg,'simpfn,'simpintgg)$

symbolic procedure simpintgg(u);
<<u:=intggg(car u,cadr u,caddr u,cadddr u);
  simp prepsq u>>;

symbolic procedure intggg(u1,u2,u3,u4);
begin scalar v,v1,v2,s1,s2,s3,coef,uu1,uu2,test_1,test_1a,test_2,m,n,p,
      q,delta,xi,eta,test,temp,temp1,temp2,var,var1,var2,
   !*allfac;

   if !*trdefint then <<
      prin2t "Entering main procedure intggg with parameters";
      mathprint {'setq,'u1,u1};
      mathprint {'setq,'u2,u2};
      mathprint {'setq,'u3,u3};
      mathprint {'setq,'u4,u4};
   >>;
   
 uu1:= cadr u1; uu1:= prepsq cadr(algebraic uu1);
 uu2:= cadr u2; uu2:= prepsq cadr(algebraic uu2);
 u1:=if null cddr u1 then list('f1, uu1) else 'f1 . uu1 . cddr u1;
 u2:=if null cddr u2 then list('f2, uu2) else 'f2 . uu2 . cddr u2;


% Cases for the integration of a single Meijer G-function
 if get('f1,'g)='(1 . 1) and get('f2,'g) = '(1 . 1) then

         return simp 'unknown

 else if get('f1,'g)='(1 . 1) then

% Obtain the appropriate Meijer G-function

    <<s1:=bastab(car u2,cddr u2);

      v:= trpar(car cddddr s1, cadr u2, u4);
      if v='fail then return simp 'fail;

% Substitute in the correct variable value

      temp := car cddddr s1;
      var := cadr u2;
      temp := reval algebraic(sub(x=var,temp));

      s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp};

% Ensure by simplification that the variable does not contain a power

      s1 := simp_expt(u3,s1,u4);

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

      test := list('test_cases,m,n,p,q,delta,xi,eta,test_1,test_1a,test_2);
      if !*trdefint then <<
	 prin2t "Checking test cases:";
	 mathprint test;
      >>;
      test := reval test;
      if !*trdefint then <<
	 prin2t "Result returned is:";
	 mathprint test;
      >>;
      

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

 else if get('f2,'g)='(1 . 1) then

% Obtain the appropriate Meijer G-function

    <<s1:=bastab(car u1,cddr u1);

      v:= trpar(car cddddr s1, cadr u1, u4);
      if v='fail then return simp 'fail;

% Substitute in the correct variable value

      temp := car cddddr s1;
      var := cadr u1;
      temp := reval algebraic(sub(x=var,temp));

      s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp};

% Ensure by simplification that the variable does not contain a power

      s1 := simp_expt(u3,s1,u4);

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
      if !*trdefint then <<
	 prin2t "Checking test cases:";
	 mathprint test;
      >>;
      test := reval test;
      if !*trdefint then <<
	 prin2t "Result returned is:";
	 mathprint test;
      >>;

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

  if !*trdefint then <<
     prin2t "MeijerG representations of the first factor is:";
     prin2!* "MeijerG<";prin2!* car car s1;prin2!* ",";prin2!* cadr car s1;prin2!* ",";
     prin2!* caddr car s1;prin2!* ",";prin2!* cadddr car s1;prin2!* ">";
     maprin ('list . cadr s1); prin2!* "|";
     maprin ('list . caddr s1); prin2!* "|";
     maprin car cddddr s1; terpri!* t;
     if cadddr s1 neq 1 then <<prin2!* "times a factor of"; mathprint cadddr s1>>;
     prin2t "MeijerG representations of the second factor is:";
     prin2!* "MeijerG<";prin2!* car car s2;prin2!* ",";prin2!* cadr car s2;prin2!* ",";
     prin2!* caddr car s2;prin2!* ",";prin2!* cadddr car s2;prin2!* ">";
     maprin ('list . cadr s2); prin2!* "|";
     maprin ('list . caddr s2); prin2!* "|";
     maprin car cddddr s2; terpri!* t;
     if cadddr s2 neq 1 then <<prin2!* "times a coefficient of"; mathprint cadddr s2>>;
  >>;

  coef:=multsq(simp!* cadddr s1,simp!* cadddr s2);

  if !*trdefint then <<
     prin2t "Product of coefficients is";
     printsq coef;
  >>;

  v1:= trpar(car cddddr s1, cadr u1, u4);
  if v1='fail then return simp 'fail;
  if !*trdefint then <<
     prin2t "Argument of first MeijerG function is";
     mathprint {'times,prepsq car v1,{'expt,u4,prepsq cadr v1}};
  >>;

  v2:= trpar(car cddddr s2, cadr u2, u4);
  if v2='fail then return simp 'fail;
  if !*trdefint then <<
     prin2t "Argument of second MeijerG function is";
     mathprint {'times,prepsq car v2,{'expt,u4,prepsq cadr v2}};
  >>;

  !*allfac := t;

% Substitute in the correct variable value

  temp1 := car cddddr s1;
  var1 := cadr u1;
  temp1 := reval algebraic(sub(x=var1,temp1));
  if !*trdefint then <<
     prin2t "After substituting the current expression the argument to the first MeijerG function is";
     mathprint temp1;
  >>;
  s1 := {car s1,cadr s1,caddr s1,cadddr s1,temp1};

  temp2 := car cddddr s2;
  var2 := cadr u2;
  temp2 := reval algebraic(sub(x=var2,temp2));
  if !*trdefint then <<
     prin2t "After substituting the current expression the argument to the second MeijerG function is";
     mathprint temp2;
  >>;
  s2 := {car s2,cadr s2,caddr s2,cadddr s2,temp2};

  s1:=list(v1,car s1,listsq cadr s1,
         listsq caddr s1,simp!*(subpref(cadr u1,1,u4)));


  s2:=list(v2,car s2,listsq cadr s2,
     listsq caddr s2,simp!*(subpref(cadr u2,1,u4)));

  %% RmS: The integral contains a factor var^u3
  %%  The Formula calls for a factor of var^(alpha-1). Compute s3=alpha
  s3:=addsq(simp!* u3,'(1 . 1));

  % Ensure that the arguments of both MeijerG functions are rational powers
  % of the integration variable
  if not numberp(defint_gl s1) or not numberp(defint_gl s2) then
        return simp 'fail
  else
  if defint_gl s1<0 then s1:=cong s1 else
  if defint_gl s2<0 then s2:=cong s2 else

  %% RmS: This is just not very good way of checking that the exponent of the
  %% integration variable in the first MeijerG function is 1.  
  if defint_gl s1=defint_gk s1 then goto a  else      % No reduction is necessary if
                                                      % it is not a meijer G-function
                                                      % of a power of x
  %% RmS: If the 2nd MeijerG's argument is linear in the integration variable, but
  %%  the first isn't, exchange the two factors.
  if defint_gl s2=defint_gk s2 then <<
     v:=s1;s1:=s2;s2:=v;
     if !*trdefint then prin2t "Exchanging the two MeijerG functions";
     go to a>>;
                                                      % No reduction necessary but
                                                      % the Meijer G-functions must
                                                      % be exchanged

  %% RmS: At this point, both of the MeijerG-function's arguments are nonlinear in the 
  %%  integration variable.
  %%  Substitute the latter so that the first is linear, i.e. t -> t'^A
  %%  defint_gr s1 is the exponent A of the power in the argument
  coef:=multsq(coef,invsq defint_gr s1);
                                                      % premultiply by inverse of power
  v:=modintgg(s3,s1,s2);
  s3:=car v;    s1:=cadr v;   s2:=caddr v;

  a:

  %% RmS At this point the first MeijerG function is linear in the integration variable

% Test for validity of the integral

  test := validity_check(s1,s2,u3);

  if test neq 't then
      return simp 'unknown;

  coef := multsq(if numberp(mellincoef) then simp(mellincoef)
                                     else cadr mellincoef,
              multsq(coef,coefintg(s1,s2,s3)));

  if !*trdefint then <<
     prin2t "Overall coefficient is";
     printsq coef;
  >>;
  %% Compute new list of MeijerG parameters
  v := deltagg(s1,s2,s3);
  if !*trdefint then <<
     prin2t "Parameter list of resulting single MeijerG function is";
     mathprint ('list . for each sq in car v collect prepsq sq);
     mathprint ('list . for each sq in cadr v collect prepsq sq);
  >>;
  v := redpargf(list(arggf(s1,s2),indgf(s1,s2),car v,cadr v));
  v := ('MeijerG . mgretro (cadr v,caddr v,car v));
  if !*trdefint then <<
     prin2t "Resulting single MeijerG function is";
     mathprint v;
  >>;
  v := aeval v;

  if !*trdefint then <<
     prin2t "Simplification of the resulting single MeijerG function yields";
     mathprint v;
  >>;
  if eqcar(v,'!*sq) then
      v := cadr v
  else if fixp v then
      v := simp v;

  if v='fail then
      return simp 'fail
  else
      return multsq(coef,v);

end;



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
   if numberp(defint_gl(u1)) and defint_gl(u1) < 0 then u1:=cong u1;
   v:=modintg(u2,u1);
   u1:=cadr v;
   v:=
     multlist(
       list(u3,
            expdeg(defint_gw u1,negsq u2),
            quotsq(
               multgamma(
                 append(
                   specfn!-listplus(car redpar1(defint_gb u1,defint_gm u1),u2),
                   specfn!-listplus(
                     listmin(car redpar1(defint_ga u1,defint_gn u1)),
                     subtrsq('(1 . 1),u2)))),
               multgamma(
                 append(
                   specfn!-listplus(cdr redpar1(defint_ga u1,defint_gn u1),u2),
                   specfn!-listplus(
                     listmin(cdr redpar1(defint_gb u1,defint_gm u1)),
                     subtrsq('(1 . 1),u2)))))));
   return multsq(if numberp(mellincoef) then simp(mellincoef)
                                     else cadr mellincoef,
                 v);
end$

%***********************************************************************
%*              EVALUATION OF THE PARAMETERS FOR THE G-FUNCTION        *
%***********************************************************************

share intggg!-rules1;

algebraic <<

intggg!-rules1 := {
   {~~c*!*intvar!*^~a }
      => {a,c*!*intvar!*} when c freeof !*intvar!* and a freeof !*intvar!*,
   {(~c*!*intvar!*^~a)/~d }
      => {a,c/d*!*intvar!*} when c freeof !*intvar!* and d freeof !*intvar!* and a freeof !*intvar!*,
   {~c/!*intvar!*^~a }
      => {a,c/!*intvar!*} when c freeof !*intvar!* and a freeof !*intvar!*,
   {!*intvar!*^~a/~c }
      => {a,!*intvar!*/c} when c freeof !*intvar!* and a freeof !*intvar!*,
   {1/(~~c*!*intvar!*^~a) }
      => {a,1/(c*!*intvar!*) } when c freeof !*intvar!* and a freeof !*intvar!*,
   {~~c*!*intvar!*^~a*sqrt(!*intvar!*) }
      => {a+1/2,c*!*intvar!*} when c freeof !*intvar!* and a freeof !*intvar!*,
   {~~c*sqrt(!*intvar!*)/!*intvar!*^~a }
      => {a-1/2,c/!*intvar!*} when c freeof !*intvar!* and a freeof !*intvar!*,
   {(!*intvar!*^~a*sqrt(!*intvar!*))/~c }
      => {a+1/2,!*intvar!*/c} when c freeof !*intvar!* and a freeof !*intvar!*,
   {sqrt(!*intvar!*)/(~~c*!*intvar!*^~a) }
      => {a-1/2,1/(c*!*intvar!*) } when c freeof !*intvar!* and a freeof !*intvar!*   
};

>>;

symbolic procedure simp_expt(u,v,intvar);

   % Reduce Meijer G functions of powers of x to x

   % Use the pattern matcher to find powers of the integration variable in the argument of Meijer G

begin scalar var,m,n,coef,alpha,beta,alpha1,alpha2,expt_flag,k,temp1,
                  temp2,varcoef,varnew;

var := car cddddr(v);

beta := 1;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

if length var = 0 then
    return u . v

else

<< k := u;
   coef := cadddr v;

   % step 1: replace generic !*intvar!* by the actual integration variable
   temp1 := subst(intvar,'!*intvar!*,intggg!-rules1);

   % step 2: parse the argument into a coefficient and a power of the integration variable
   temp2 := prepsq evalletsub({{temp1},{'simp!*,mkquote {'list,var}}},nil);

   % step 3: proceed if the match succeeds (result is a list of two elements)
   if length temp2 > 2 then <<
      alpha := cadr temp2;
      var := caddr temp2;
      expt_flag := t >>;

   % for each i in var do

   % << if listp i and not constant_exprp i then
   %    << if car i = 'expt then
   %       << alpha := caddr i;
   %          expt_flag := 't>>

   %       else if car i = 'sqrt then
   %       << beta := 2;
   %          alpha := 1;
   %          expt_flag := 't>>

   %       else if car i = 'times then
   %       << temp1 := cadr i;
   %          temp2 := caddr i;

   %          if listp temp1 then
   %          << if  car temp1 = 'sqrt then
   %             << beta := 2;
   %                alpha1 := 1;
   %                expt_flag := 't>>

   %             else if car temp1 = 'expt and listp caddr temp1 then
   %                << beta := cadr cdaddr temp1;
   %                   alpha1 := car cdaddr temp1;
   %                          expt_flag := 't>>;
   %          >>;

   %          if listp temp2 and car temp2 = 'expt then
   %          << alpha2 := caddr temp2;
   %             expt_flag := 't>>;

   %          if alpha1 neq 'nil then

   %   alpha := reval algebraic(alpha1 + beta*alpha2)
   %          else alpha := alpha2;
   %       >>;

   %    >>

   %    else
   %    << if i = 'expt then
   %       << alpha := caddr var;
   %          expt_flag := 't>>;
   %    >>;
   %  >>;

% If the Meijer G-function is is a function of a variable which is not
% raised to a power then return initial function

   if expt_flag = nil then
       return u . v

% Otherwise reduce the power by using the following formula :-
%
%   infinity                          infinity
%  /                                 /
%  |                             1   |
%  |t^gamma*F(c*t^(alpha))dt = ----- |z^[((gamma + 1)/alpha) - 1]*F(c*z)dz
%  |                           alpha |
%  /                                 /
% 0                                 0

   else

   <<
      % if listp alpha then
      % << m := cadr alpha;
      %    n := caddr alpha;
      %    n := reval algebraic(beta*n)>>

      % else
      % << m := alpha;
      %    n := beta>>;

      if !*trdefint then <<
      	 prin2t "Substituting ";
      	 mathprint {'expt,intvar,reval {'quotient,m,n}}
      >>;
      
      k := reval algebraic(((k + 1)/alpha) - 1);
      coef := reval algebraic(coef/alpha);
%      var := reval algebraic(var^(n/m));

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
                rnd,dmode!*,result;


rnd := !*rounded;
if rnd then off rounded;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< s := algebraic(repart(1 + u));
   s := simp!* s;

   m := caar v;
   n := cadar v;

   a := cadr v;
   b := caddr v;

   if !*trdefint then <<
      prin2t "Checking test_1: -min Re{bj} < Re{s} < 1 - max Re{ai}    i=1..n, j=1..m";
      mathprint {'equal,'s,prepsq s};
      prin2!* length a; prin2!* " upper parameters: ";
      mathprint {'equal,'a,'list . for each sq in a collect prepsq sq};
      prin2!* length b; prin2!* " lower parameters: ";
      mathprint {'equal,'b,'list . for each sq in b collect sq};
   >>;
   
   if aa = nil then
   << for i := 1 :n do

      << if car a = 'nil then
              car a := 0;
          ai := append(ai,{car a});
         a := cdr a>>;


      if ai neq 'nil then
      << a_max := simpmax list('list . ai);
         a_max := simprepart list(mk!*sq a_max)>>;

   >>

   else if aa = 'a then

   << if a neq 'nil then
      << a_max := simpmax list('list . a);
         a_max := simprepart list(mk!*sq a_max)>>;
   >>;


   for j := 1 :m do

   << if car b = 'nil then
          car b := 0;
      bj := append(bj,{car b});
      b := cdr b>>;

   if bj neq 'nil then
   << b_min := simpmin list('list . bj);
      b_min := simprepart list(mk!*sq negsq(b_min))>>;


   if a_max neq nil and b_min neq nil then

   << temp := subtrsq(s,diffsq(a_max,1));
      temp1 := subtrsq(b_min,s);

      if sign!-of mk!*sq temp = -1 and sign!-of mk!*sq temp1 = -1
        then << if rnd then on rounded; result := test2(prepsq s,cadr v,caddr v)>>
       else  << if rnd then on rounded; result := 'fail>>

   >>

   else if null a_max then

   << temp := subtrsq(b_min,s);

      if sign!-of mk!*sq temp = -1
        then << if rnd then on rounded; result := 't >>
       else << if rnd then on rounded; result := 'fail >>

   >>

   else if null b_min then

   << temp :=  subtrsq(s,diffsq(a_max,1));

      if sign!-of mk!*sq temp = -1
      then << if rnd then on rounded; result := 't >>
       else << if rnd then on rounded; result := 'fail >>;

   >>;

   if !*trdefint then <<
      prin2t "Result of test1 is "; prin2!* result; terpri!* t>>;

   return result;
>>
   
else
<< transform_lst := cons (('tst1 . '(list 'lessp (list 'lessp
        (list 'minus
                (list 'min (list 'repart 'bj))) (list 'repart 's))
        (list 'difference 1
                (list 'max(list 'repart 'ai))))),transform_lst);

   if rnd then off rounded;
   return 't>>;

end;


symbolic procedure test2(s,a,b);

% Check validity of the following formula :=
%
% Re{Sum(ai) - Sum(bj)} + 1/2 * (q + 1 - p) > (q - p) * Re{s}
%                                                        i=1..p, j=1..q
% 'The Special Functions and their Approximations', Volume 1,
%  Y.L.Luke. Chapter 5.6 page 157 (4)

begin scalar s,p,q,sum_a,sum_b,diff_sum,temp1,temp2,temp,diff,result;

transform_tst := reval algebraic(transform_tst);

if transform_tst neq 't then

<< s := algebraic(repart(1 + s));

   p := length a;
   q := length b;

   if !*trdefint then <<
      prin2t "Checking test_2: Re{Sum(ai) - Sum(bj)} + 1/2 * (q + 1 - p) > (q - p) * Re{s}, i=1..p, j=1..q";
      mathprint {'equal,'s,s};
      prin2!* p; prin2!* " upper parameters: ";
      mathprint {'equal,'a,'list . for each sq in a collect prepsq sq};
      prin2!* q; prin2!* " lower parameters: ";
      mathprint {'equal,'b,'list . for each sq in b collect sq};
   >>;
   
   for each i in a do << sum_a := reval algebraic(sum_a + i)>>;

   for each j in b do << sum_b := reval algebraic(sum_b + j)>>;

   diff_sum := reval algebraic(repart(sum_a - sum_b));

   temp := reval algebraic(1/2*(q + 1 - p));
   temp1 := reval algebraic(diff_sum + temp);
   temp2 := reval algebraic((q-p)*s);
   diff := simp!* reval algebraic(temp1 - temp2);

   result := if sign!-of mk!*sq diff = 1 then t else  'fail;

   if !*trdefint then <<
      prin2t "Result of test2 is "; prin2!* result; terpri!* t>>;

   return result;

>>

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

if !*trdefint then prin2t "Checking test cases:";
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
test_14 := tst14(u,v,alpha,mu,rho,delta,epsilon,sigma,omega,r,phi,r1,r2);
%%
%% If test 14 fails, we try it again after exchanging the two MeijerG factors
if test_14 = 'fail then
   test_14 := tst14(p,q,alpha,mu,rho,epsilon,delta,omega,sigma,r,phi,r2,r1);

if p = q or u = v then test_15 := 'fail
        else test_15 := tst15(m,n,p,q,k,l,u,v,sigma,omega,eta);

test := {'test_cases2,m,n,p,q,k,l,u,v,delta,epsilon,sigma,omega,rho,
   eta,mu,r1,r2,phi,test_1a,test_1b,test_2,test_3,test_4,test_5,test_6,
   test_7,test_8,test_9,test_10,test_11,test_12,test_13,test_14,
   test_15};
if !*trdefint then <<
   terpri!* t;
   prin2t "Checking test cases:";
   mathprint test;
>>;
test := reval test;
if !*trdefint then <<
	 prin2t "Result returned is:";
	 mathprint test;
>>;

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

   if !*trdefint then <<
      prin2t "Checking tst1a: any difference between an upper and a lower parameter must not be a positive integer";
      prin2!* n; prin2!* " upper parameters: ";
      mathprint {'equal,'a,'list . for each sq in a collect prepsq sq};
      prin2!* m; prin2!* " lower parameters: ";
      mathprint {'equal,'b,'list . for each sq in b collect prepsq sq};
   >>;
   
for i := 1 :n do << a_new := append(a_new,{car a}); a := cdr a>>;

for j := 1 :m do << b_new := append(b_new,{car b}); b := cdr b>>;

for each i in a_new do
<< for each j in b_new do
   << temp := subtrsq(i,j);
      if car temp neq 'nil and car temp > 0
          and cdr temp = 1 then
          fail_test := t>>;
>>;

if !*trdefint then <<
   prin2!* "Result of tst1a is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

   if !*trdefint then <<
      prin2t "Checking tst1b: any difference between an upper and a lower parameter must not be a positive integer";
      prin2!* l; prin2!* " upper parameters: ";
      mathprint {'equal,'c,'list . for each sq in c collect prepsq sq};
      prin2!* k; prin2!* " lower parameters: ";
      mathprint {'equal,'d,'list . for each sq in d collect prepsq sq};
   >>;

for i := 1 :l do << c_new := append(c_new,{car c}); c := cdr c>>;

for j := 1 :k do << d_new := append(d_new,{car d}); d := cdr d>>;

for each i in c_new do
<< for each j in d_new do
   << temp := subtrsq(i,j);
      if car temp neq 'nil and car temp > 0
          and cdr temp = 1 then
          fail_test := t>>;
>>;
if !*trdefint then <<
   prin2!* "Result of tst1b is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

if !*trdefint then <<
   prin2t "Result of tst2 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

   if !*trdefint then <<
      prin2t "Checking tst3: Re{alpha + r*ai + cj} < r + 1,          i=1..n, j=1..l";
      prin2!* n; prin2!* " first upper parameters: ";
      mathprint {'equal,'a,'list . for each sq in a collect prepsq sq};
      prin2!* l; prin2!* " second upper parameters: ";
      mathprint {'equal,'c,'list . for each sq in c collect prepsq sq};
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
   >>;
   
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
if !*trdefint then <<
   prin2t "Result of tst3 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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
<< if !*trdefint then <<
      prin2t "Checking tst4: (p - q)*Re{alpha + cj - 1} - r*Re{mu} > -3*r/2,   j=1..l";
      terpri!* t; prin2!* "p="; prin2!* p; prin2!* ",q=" ; prin2!* q; terpri!* t;
      prin2!* l; prin2!* " second upper parameters: ";
      mathprint {'equal,'c,'list . for each sq in c collect prepsq sq};
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'mu,mu};
   >>;

   for j := 1 :l do
   << temp1 := prepsq car c;
      c_new := append(c_new,{temp1});
      c := cdr c>>;

   for each i in c_new do
   << temp := simp!* reval algebraic((p - q)*repart(alpha + i - 1)
                                                                - r*repart(mu) + 3/2*r);
      if car temp = 'nil or car temp < 0 then fail_test := t;
   >>;

if !*trdefint then <<
   prin2t "Result of tst4 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

<< if !*trdefint then <<
      prin2t "Checking tst5: (p - q)*Re{alpha + dj} - r*Re{mu} > -3*r/2,  j=1..k";
      terpri!* t; prin2!* "p="; prin2!* p; prin2!* ",q=" ; prin2!* q; terpri!* t;
      prin2!* k; prin2!* " second lower parameters: ";
      mathprint {'equal,'d,'list . for each sq in d collect prepsq sq};
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'mu,mu};
   >>;

   for j := 1 :k do
   << temp1 := prepsq car d;
      d_new := append(d_new,{temp1});
      d := cdr d>>;

   for each i in d_new do

   << temp := simp!* reval algebraic((p - q)*repart(alpha + i)
                                                                - r*repart(mu) + 3/2*r);
      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

   if !*trdefint then <<
      prin2t "Result of tst5 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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
<< if !*trdefint then <<
      prin2t "Checking tst6: (u - v)*Re{alpha + r*ai - r} - Re{rho} > -3/2 ,  i=1..n";
      terpri!* t; prin2!* "u="; prin2!* u; prin2!* ",v="; prin2!* v; terpri!* t;
      prin2!* n; prin2!* " first upper parameters: ";
      mathprint {'equal,'a,'list . for each sq in a collect prepsq sq};
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'r,rho};
   >>;

   for j := 1 :n do

   << temp1 := prepsq car a;
      a_new := append(a_new,{temp1});
      a := cdr a>>;

   for each i in a_new do

   << temp := simp!* reval algebraic((u - v)*repart(alpha + r*i - r)
                                                                              - repart(rho) + 3/2);
      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

  if !*trdefint then <<
      prin2t "Result of tst6 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

<< if !*trdefint then <<
      prin2t "Checking tst7: (u - v)*Re{alpha + r*bi} - Re{rho} > -3/2,     i=1..m";
      terpri!* t; prin2!* "u="; prin2!* u; prin2!* ",v="; prin2!* v; terpri!* t;
      prin2!* m; prin2!* " first lower parameters: ";
      mathprint {'equal,'b,'list . for each sq in b collect prepsq sq};
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'r,rho};
   >>;

   for j := 1 :m do
   << temp1 := prepsq car b;
      b_new := append(b_new,{temp1});
      b := cdr b>>;

   for each i in b_new do

   << temp := simp!* reval algebraic((u - v)*repart(alpha + r*i)
                                                                              - repart(rho) + 3/2);

      if car temp = 'nil or car temp < 0 then fail_test := 't;
   >>;

   if !*trdefint then <<
      prin2t "Result of tst7 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

<< if !*trdefint then <<
      prin2t "Checking tst8: abs(phi) + 2*Re{(q - p)*(v - u)*alpha + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)} > 0";
      terpri!* t; prin2!* "p="; prin2!* p; prin2!* ",q=" ; prin2!* q; 
      prin2!* ",u="; prin2!* u; prin2!* ",v="; prin2!* v; terpri!* t;
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'mu,mu};
      mathprint {'equal,'rho,rho};
   >>;

   sum := reval algebraic(2*repart((q - p)*(v - u)*alpha
                                  + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)));

   temp := simp!* reval algebraic(abs phi + sum);
   if car temp = 'nil or car temp < 0 then fail_test := 't;
   if !*trdefint then <<
      prin2t "Result of tst8 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

<< if !*trdefint then <<
      prin2t "Checking tst9: abs(phi) - 2*Re{(q - p)*(v - u)*alpha + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)} > 0";
      terpri!* t; prin2!* "p="; prin2!* p; prin2!* ",q=" ; prin2!* q; 
      prin2!* ",u="; prin2!* u; prin2!* ",v="; prin2!* v; terpri!* t;
      mathprint {'equal,'alpha,alpha};
      mathprint {'equal,'r,r};
      mathprint {'equal,'mu,mu};
      mathprint {'equal,'rho,rho};
   >>;
   sum := reval algebraic(2*repart((q - p)*(v - u)*alpha
                                  + r*(v - u)*(mu - 1) + (q - p)*(rho - 1)));

   temp := simp!* reval algebraic(abs phi - sum);

   if car temp = 'nil or car temp < 0 then fail_test := 't;

   if !*trdefint then <<
      prin2t "Result of tst9 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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
%%
%%   if !*trdefint then <<
%%      prin2t "Checking tst10: abs(arg sigma) < delta*pi";
%%      mathprint {'equal,'sigma,sigma};
%%      mathprint {'equal,'delta,delta};
%%   >>;

if transform_tst neq 't then

<< if symbolic(!*trdefint) then <<
     write "Checking tst10: abs(arg sigma) < delta*pi";
     write "sigma=",sigma;
     write "delta=",delta;
   >>;
   on rounded;
   arg_sigma := abs(atan2(impart sigma,repart sigma));
   pro :=  delta*pi;
   temp :=  pro - arg_sigma;
   if  numberp temp and temp <= 0 then fail_test := t;

   off rounded;

   if symbolic(!*trdefint) then <<
      write "Result of tst10 is ",
	 if symbolic(fail_test) then fail else t;
   >>;
%%if !*trdefint then <<
%%   prin2t "Result of tst10 is "; prin2!* if fail_test then 'fail else t; terpri!* t>>;

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

<< if symbolic(!*trdefint) then <<
     write "Checking tst11: abs(arg sigma) = delta*pi";
     write "sigma=",sigma;
     write "delta=",delta;
   >>;
   arg_sigma := abs(atan2(impart sigma,repart sigma));
   pro := delta*pi;
   if arg_sigma neq pro then fail_test := 't;
   if symbolic(!*trdefint) then <<
      write "Result of tst11 is ",
	 if symbolic(fail_test) then fail else t;
   >>;
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

   if symbolic(!*trdefint) then <<
     write "Checking tst12: abs(arg omega) < epsilon*pi";
     write "omega=",omega;
     write "epsilon=",epsilon;
   >>;
   arg_omega := abs(atan2(impart omega,repart omega));
   pro := epsilon*pi;
   temp := pro - arg_omega;
   if numberp temp and temp <= 0 then fail_test := 't;

   off rounded;

   if symbolic(!*trdefint) then <<
      write "Result of tst12 is ",
	 if symbolic(fail_test) then fail else t;
   >>;
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

<< if symbolic(!*trdefint) then <<
     write "Checking tst13: abs(arg omega) = epsilon*pi";
     write "omega=",omega;
     write "epsilon=",epsilon;
   >>;
   arg_omega := abs(atan2(impart omega,repart omega));
   pro := epsilon*pi;
   if arg_omega neq pro then fail_test := 't;
   if symbolic(!*trdefint) then <<
      write "Result of tst13 is ",
	 if symbolic(fail_test) then fail else t;
   >>;
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

   if symbolic(!*trdefint) then <<
     write "Checking tst14: Compute z = r^[r1*(v - u)]*exp[-(r1*delta + r2*epsilon)*pi*i]";
     write "                  abs(arg(1 - z*sigma^(-r1)*omega^r2)) < pi when phi = 0 and epsilon + r*(delta - 1) <= 0";
     write "                 or";
     write "                   z = sigma^r1*omega^(-r2) when Re{mu + rho + alpha*(v - u)}<1";
     write "u=",u,",v=",v;
     write "alpha=",alpha;
     write "mu=",mu;
     write "rho=",rho;
     write "sigma=",sigma;
     write "delta=",delta;
     write "omega=",omega;
     write "epsilon=",epsilon;
   >>;

   temp := epsilon + r *(delta - 1);
   if phi = 0 and temp <= 0 then
       << z := r^(r2*(v - u))*e^(-(r2*delta+r1*epsilon)*pi*i);
          if symbolic(!*trdefint) then write "Case 1: z=",z;
       >>
   else if numberp (mu + rho + alpha*(v - u)) and
                        repart(mu + rho + alpha*(v - u)) < 1 then
       << z := sigma^r2*omega^(-r1);
          if symbolic(!*trdefint) then write "Case 2: z=",z >>
   else << if symbolic(!*trdefint) then write "Result of tst14 is fail"; return reval 'fail>>; % Wn
   arg := 1 - z*sigma^(-r2)*omega^r1;

   if arg = 0 then arg_test := 0
   else     arg_test := abs(atan2(impart arg,repart arg));

   if numberp arg_test and arg_test < pi then
                << off rounded; 
		   if symbolic(!*trdefint) then write "Result of tst14 is t";
                   return reval 't>>
   else     << off rounded;
  	       if symbolic(!*trdefint) then write "Result of tst14 is fail";
	       return reval 'fail>>;
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

begin scalar lc,ls,temp_ls,psi,theta,arg_omega,arg_sigma,
        !*rounded,dmode!*;

if transform_tst neq 't then

<< if symbolic(!*trdefint) then <<
     write "Checking tst15:";
     write "m=",m,",n=",n,",p=",p,",q=",q,",k=",k,",l=",l,",u=",u,",v=",v;
     write "sigma=",sigma;
     write "omega=",omega;
     write "eta=",eta;
   >>;

   arg_omega := atan2(impart omega,repart omega);
   arg_sigma := atan2(impart sigma,repart sigma);

   psi := (abs arg_omega + (q - m - n)*pi)/(q - p);
   theta := (abs arg_sigma + (v - k - l)*pi)/(v - u);


   lc := (q - p)*abs(omega)^(1/(q - p))*cos psi +
                             (v - u)*abs(sigma)^(1/(v - u))*cos theta;

   lc := lc;
   temp_ls := (q - p)*abs(omega)^(1/(q - p))*sign(arg_omega)*sin psi +
          (v - u)*abs(sigma)^(1/(v - u))*sign(arg_sigma)*sin theta;

   if arg_sigma*arg_omega neq 0 then ls := temp_ls
        else return reval 'fail;

   on rounded;
   if (numberp lc and lc > 0) or lc = 0 and ls = 0 and repart eta > -1
                  or lc = 0 and ls = 0 and repart eta > 0 then
   << off rounded; 
      if symbolic(!*trdefint) then write "Result of tst14 is t";
      return reval 't>>

   else << off rounded;
           if symbolic(!*trdefint) then write "Result of tst15 is fail";
      	   return reval 'fail>>
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
 if null cdr v or null cdr z then defint_sublist(u,car v,car z)
   else
    sublist1(
      defint_sublist(u,car v,car z),
      cdr v,cdr z)$

symbolic procedure subpref1(u,v,z);
% u - pf
% v,z - list pf
 if null cdr v or null cdr z then subpref(u,car v,car z)
   else subpref(subpref1(u,cdr v,cdr z),car v,car z)$

symbolic procedure subpref(u,v,z);
% u,v,z - pf
 prepsq subsqnew(simp!* u,simp!* v,z)$

symbolic procedure defint_sublist(u,v,z);
% u - list pf
% v,z - pf
if null u then nil else
     subpref(car u,v,z) . defint_sublist(cdr u,v,z)$

symbolic procedure trpar(u1,u2,u3);
  % computes the argument c*var^p of the MeijerG function in terms of the
  % integration variable var.
  % parameters:
  %   u1 - variable pattern from MeijerG pattern
  %   u2 - actual argument for replacement
  %   u3 - integration variable
  % returns: a list {c,p}
  if eqcar(u2,'plus) then 'fail else
  begin scalar a!3,l!1,v1,v2,v3,v4;
   if (v1:=dubdeg(numr simp u1,'x))='fail or
           (v2:=dubdeg(denr simp u1,'x))='fail or
           (v3:=dubdeg(numr simp u2,u3))='fail or
           (v4:=dubdeg(denr simp u2,u3))='fail then return 'fail;
   a!3:=multsq(subtrsq(v1,v2), subtrsq(v3,v4));
   l!1:=subpref(u1,u2,'x);
   l!1:=subpref(l!1,1,u3);
   return list(simp!*(l!1),a!3);
  end;

symbolic procedure modintgg(u1,u2,u3);
 {multsq(u1,invsq defint_gr u2),
  defint_change(u2,{cons(defint_gw u2,{'(1 . 1)})},'(1)),
  defint_change(u3,{cons(defint_gw u3,{quotsq(defint_gr u3,defint_gr u2)})},'(1))};

% Name adjusted to avoid clash with desir.red
symbolic procedure defint_change(u1,u2,u3);
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
   list(invsq defint_gw u,negsq defint_gr u),
   list(defint_gn u,defint_gm u,defint_gq u,defint_gp u),
   difflist(listmin defint_gb u,'(-1 . 1)),
   difflist(listmin defint_ga u,'(-1 . 1)))$

symbolic procedure modintg(u1,u2);
 list(
  multsq(u1,invsq defint_gr u2),
  defint_change(u2,
    list(
      cons(defint_gw u2,list '(1 . 1))),'(1)))$

symbolic procedure ccgf(u);
  quotsq(
     simp(2 * defint_gm u + 2 * defint_gn u - defint_gp u - defint_gq u),
     '(2 . 1))$

symbolic procedure vgg(u1,u2);
  subtrsq(
     simp(defint_gq u2 - defint_gp u2),
     multsq(defint_gr u2,simp(defint_gq u1 - defint_gp u1)))$

symbolic procedure nugg(u1,u2,u3);
  subtrsq( subtrsq('(1 . 1), multsq(u3, simp(defint_gq u1 - defint_gp u1))),
           addsq(mugf u2,mugf u1))$

symbolic inline procedure sumlistsq(u);
<< for each pp in u do <<p := addsq(pp,p)>>; p>> where p = '(nil . 1);

symbolic procedure mugf(u);
  addsq(
     quotsq(simp(2 + defint_gp u - defint_gq u),'(2 . 1)),
     addsq(sumlistsq defint_gb u,negsq sumlistsq defint_ga u))$

symbolic procedure coefintg(u1,u2,u3);
  multlist(
   list(
     expdeg(defint_gk u2 . 1,mugf u2),
     expdeg(defint_gl u2 . 1,
       addsq(mugf u1,
         subtrsq(
            multsq(u3,(defint_gq u1-defint_gp u1) . 1),
            '(1 . 1)))),
     expdeg(defint_gw u1,negsq u3),
     expdeg(simp '(times 2 pi),
       addsq(multsq(ccgf u1,(1-defint_gl u2) . 1),
             multsq(ccgf u2,(1-defint_gk u2) . 1)))))$

% The procedure name "delta" had been changed to "defint_delta" to avoid
% clashed with the cantens package.

symbolic procedure deltagg(u1,u2,u3);
  {append( defint_delta(car redpar1(defint_ga u2,defint_gn u2), defint_gk u2),
      append(
        defint_delta( difflist( listmin defint_gb u1, addsq(u3,'(-1 . 1))), defint_gl u2),
        defint_delta( cdr redpar1(defint_ga u2,defint_gn u2), defint_gk u2))),
     append( defint_delta(car redpar1(defint_gb u2,defint_gm u2), defint_gk u2),
      append(defint_delta( difflist(listmin defint_ga u1,addsq(u3,'(-1 . 1))),defint_gl u2),
        defint_delta( cdr redpar1(defint_gb u2,defint_gm u2), defint_gk u2)))};

symbolic procedure redpargf(u);
 begin scalar v1,v2;
  v1:=redpar(car redpar1(defint_gb u,defint_gm u), cdr redpar1(defint_ga u,defint_gn u));
  v2:=redpar(cdr redpar1(defint_gb u,defint_gm u), car redpar1(defint_ga u,defint_gn u));

  return
    list(car u, (cadr v2 . cadr v1), (car v1 . car v2));

end$

symbolic procedure arggf(u1,u2);

% Calculate the coefficient of the variable in the combined meijerg
% function

 multlist(list(
     expdeg(defint_gw u2, defint_gk u2 . 1),
     expdeg(defint_gk u2 . 1, (defint_gk u2 * defint_gp u2 - defint_gk u2 * defint_gq u2) . 1),
     invsq(expdeg(defint_gw u1, defint_gl u2 . 1)),
     expdeg(defint_gl u2 . 1,(defint_gl u2 * defint_gq u1 - defint_gl u2 * defint_gp u1) . 1)))$

symbolic procedure indgf(u1,u2);

% Calculate the values of m,n,p,q of the combined meijerg function

 list(defint_gk u2 * defint_gm u2 + defint_gl u2 * defint_gn u1,
      defint_gk u2 * defint_gn u2 + defint_gl u2 * defint_gm u1,
      defint_gk u2 * defint_gp u2 + defint_gl u2 * defint_gq u1,
      defint_gk u2 * defint_gq u2 + defint_gl u2 * defint_gp u1)$

symbolic procedure dubdeg(x,y);
% x -- SF.
% y -- atom.
begin scalar c,b,a1,a3;
if numberp x or null x then return '(nil . 1);
if not null red x then return 'fail;
lb1: a1:=lpow x;a3:=!_pvar!_ a1;
  if atom a3 and a3=y then b:=pdeg a1 . 1 ;
  if not atom a3 then
    if cadr a3=y then
     if null cddr(a3) then return 'fail else
       if not nump(simp caddr a3) then return simp(caddr a3)
                                else
          c:=times(pdeg a1,cadr caddr a3).caddr caddr a3;
  if atom lc x then
    if null b then
      if null c then return '(nil . 1)
      else return c
    else
    if null c then return b
    else return plus(times(car b,cdr c),car c).cdr c;
  x:=lc x;go to lb1;
end$

symbolic procedure defint_delta(u,n);
  % u -- list of sq.
  % n -- number.
  % returns the concatenated list
  %   for each parm in u conc delta0(parm,n,n)
  if null u then nil else
    append(if n=1 then list car u else
             delta0(quotsq(car u,simp!* n),n,n)
          ,defint_delta(cdr u,n))$

symbolic procedure delta0(u,n,k);
  % u -- SQ.
  % n,k -- numbers.
  % returns a list of {u,u+1/n,u+2/n,...,u+(k-1)/n}
   if k=0 then nil else
       u . delta0(addsq(u,invsq(simp!* n)),n,k-1)$

symbolic procedure nump(x);
 null car x or numberp car x and numberp cdr x;


endmodule;

end;

