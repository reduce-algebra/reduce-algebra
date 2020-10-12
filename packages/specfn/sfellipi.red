module sfellipi;  % Procedures and Rules for Elliptic Integrals.

% Author: Lisa Temme, ZIB, October 1994

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


algebraic;

%######################################################################
%DESCENDING LANDEN TRANSFORMATION

procedure landentrans(phi,alpha);
begin scalar alpha1, phi1, alist, plist, tol;
   tol := 10.0^-(symbolic !:prec!:);

   alist :=  list alpha;
   plist :=  list phi;

   while alpha > tol do <<
       alpha1 := asin(2/(1+cos alpha) -1);
       phi1 := phi + (atan(cos(alpha)*tan(phi)))
                     + floor((floor(phi/(pi/2))+1)/2)*pi;

       alist := alpha1 . alist;
       plist := phi1.plist;

       alpha := alpha1;
       phi   := phi1;
   >>;

   return list(reverse plist, reverse alist)
end;

%######################################################################
%VALUE OF EllipticF(phi,m)

procedure f_function(phi,m);
    if phi = pi/2 then k_function(m)
    else begin scalar  bothlists, alist, plist, phi_n;
       bothlists := landentrans(phi,asin m);
       alist := rest second bothlists;
       plist := first bothlists;
       phi_n  := first reverse plist;
       return (phi_n * for each y in alist product (1+sin y)/2);
    end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticF definition
%====================

operator ellipticf;

ellipticfrules :=
{
   ellipticf(~phi,0)   => phi,
   ellipticf(0, ~k)    => 0,
   ellipticf(-~phi,~k) => -ellipticf(phi,k),
   ellipticf(~phi,-~k) => ellipticf(phi,k),
   
   ellipticf(i*~phi,0) => i*phi,
   ellipticf(~phi,1)   => ln(sec(phi)+tan(phi)),
   ellipticf(i*~phi,1) => i*atan(sinh(phi)),
   ellipticf(pi/2,~k)  =>  elliptick(k),
   
% quasi-periodicity

   ellipticf((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(2*k/d);
 	 arg := w/d + ((2*k/d)-shift)*pi/2;
         return ellipticf(arg, m) + shift*elliptick(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(2*k/d)),

% derivative rules
   df(ellipticf(~u,~k),~u) => 1/sqrt((1-k^2*sin(u)^2)),

   df(ellipticf(~u,~k),~k) => (ellipticd(u,k)/(k^2-1)+ellipticf(u,k))/k
                          + k*sin(u)*cos(u)/((k^2-1)*sqrt(1-k^2*sin(u)^2)),

   ellipticf(~phi,~m)  => num_elliptic(f_function,phi,m)
                         when lisp !*rounded and numberp phi
                            and numberp m
}$
let ellipticfrules;

%######################################################################
%VALUE OF K(m)

procedure k_function(m);
begin scalar agm, an;
   agm := agm_function(1,sqrt(1-m^2),m);
   an  := first second agm;
   return pi/(2*an);
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticK definition
%====================

operator nome;

elliptickrules :=

{
        elliptick(~m)   => num_elliptic(k_function, m)
	       when lisp !*rounded and numberp m,

        elliptick!'(~m) => num_elliptic(k_function, sqrt(1-m^2))
	       when lisp !*rounded and numberp m,

        nome(0) => 0,

        nome(1) => 1,

        nome(~m) => exp(-pi*elliptick!'(m)/elliptick(m))
	       when lisp !*rounded and numberp m
}$
let elliptickrules;

% ######################################################################
% VALUE OF EllipticE(phi,m)

procedure e_function(phi,m);
  d_function(num_jacobiam(phi, m), m);

procedure d_function(phi, m);
begin scalar f, n, bothlists, alist, plist, s,
             sinalist, sinplist, b, blist, allz, z, allx, x;

    f := f_function(phi,m);
    bothlists := landentrans(phi,asin m);
	
    alist := second bothlists;
    plist := first bothlists;

    n := length alist - 1;

    sinalist := foreach a in rest alist collect sin a;
    sinplist := foreach p in rest plist collect sin p;
    b := first sinalist;
    blist := foreach c in rest sinalist collect (b := b*c);
    blist := first(sinalist) . blist;

    allz := 0;  allx := 0;
    for w := 1:n do <<
        z := first blist/(2^w);
	x := sqrt(first blist)*first(sinplist)/(2^w);
        allz := allz + z;
	allx := allx + x;
	blist := rest blist;
	sinplist := rest sinplist;
     >>;
     s := sin first alist;
     return f*(1 - s^2*(1 + allz)/2) + s*allx;

end;


% EllipticD(phi, m) definition     Legendre's form of elliptic integral
% ============================     of the second kind.

operator ellipticd;

jacobidrules :=
{
        ellipticd(0,~m)     => 0,
        ellipticd(~phi,0)   => phi,
        ellipticd(i*~phi,0) => i*phi,
        ellipticd(~phi,1)   => sin(phi),
        ellipticd(i*~phi,1) => i*sinh(phi),
        ellipticd(-~phi,~k) => -ellipticd(phi,k),
        ellipticd(~phi,-~k) =>  ellipticd(phi,k),
	ellipticd(pi/2,~k)  =>  elliptice(k),

% quasi-periodicity

   ellipticd((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(2*k/d);
 	 arg := w/d + ((2*k/d)-shift)*pi/2;
         return ellipticd(arg, m) + shift*elliptice(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(2*k/d)),

% ************************************************
% derivative rules 
    df(ellipticd(~phi,~m),~phi) => sqrt(1-m^2*sin(phi)^2),

    df(ellipticd(~phi,~m),~m)   => (ellipticd(phi,m)-ellipticf(phi,m))/m,

    ellipticd(~phi,~m) => num_elliptic(d_function,phi,m)
                     when lisp !*rounded and numberp phi and numberp m
}$

let jacobidrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticE(phi,m) definition  Jacobi's form of the elliptic integral
%===========================   of the second kind.
% There was some original confusion between Jacobi's form of the standard
% elliptic integral of the 2nd kind E(u,k) and Legendre's form D(phi,k)
% where  D(am(u,k), k) = E(u, k)
% In particular e_function(u, k) originally calculated D(u,k).
% The e_function has been renamed as d_function and the e_function redefined.
% Separate rules have been added for E(u,k) and D(u,k).

% operator elliptice;  % already defined in sfellip.red

jacobierules :=

{
        elliptice(0,~m)     => 0,
        elliptice(~phi,0)   => phi,
        elliptice(i*~phi,0) => i*phi,
        elliptice(~phi,1)   => tanh(phi),
        elliptice(i*~phi,1) => i*tan phi,
        elliptice(-~phi,~m) => -elliptice(phi,m),
        elliptice(~phi,-~m) =>  elliptice(phi,m),
	elliptice(elliptick(~m), ~m) => elliptice(m),

% complete elliptic integrals
        elliptick(-~k)    => elliptick(k),
	elliptick!'(-~k)  => elliptick!'(k),
        elliptice(-~k)    => elliptice(k),
	elliptice!'(-~k)  => elliptice!'(k),
        elliptice(0)      => pi/2,
        elliptice(1)      => 1,
	elliptick(0)      => pi/2,
	elliptick!'(1)    => pi/2,
        elliptice!'(0)    => 1,	
        elliptice!'(1)    => pi/2,
	
% quasi-periodicity

   elliptice((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
         if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
         return elliptice(arg, m) + shift*elliptice(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

    elliptice((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
         return elliptice(arg, m) + shift*i*(elliptick!'(m) - elliptice!'(m));
      end)
      when ((ratnump(ip) and abs(ip) >= 2) where ip => impart(k/d)),

% quasi-addition

       elliptice((~u+~v)/~~d,~m) => elliptice(u/d,m) + elliptice(v/d,m)
         - m^2*jacobisn(u/d,m)*jacobisn(v/d,m)*jacobisn((u+v)/d,m),

       elliptice(2*~u,~m) =>
          2*elliptice(u,m) - m^2*jacobisn(u,m)^2*jacobisn(2*u,m),
	  
% derivative rules 
        df(elliptice(~phi,~m),~phi) => jacobidn(phi,m)^2,
	
        df(elliptice(~phi,~m),~m)   =>
            m*(jacobisn(phi,m)*jacobicn(phi,m)*jacobidn(phi,m)
               - elliptice(phi,m)*jacobicn(phi,m)^2) / (1-m^2)
            - m*phi*jacobisn(phi,m)^2,

        df(elliptice(~m),~m) => (elliptice(m)-elliptick(m))/m,

        df(elliptick(~m),~m) =>
	         (elliptice(m)/(1-m^2)-elliptick(m))/m,

        df(elliptice!'(~m),~m) => m*(elliptick!'(m) - elliptice!'(m))/(1-m^2),

        df(elliptick!'(~m),~m) =>
	         (m*elliptick!'(m)-elliptice!'(m)/m)/(1-m^2),

% numerical evaluation

        elliptice(~phi,~m) => num_elliptic(e_function,phi,m)
                              when lisp !*rounded and numberp phi
                              and numberp m,

        elliptice(~m) => num_elliptic(d_function,pi/2,m)
                         when lisp !*rounded and numberp m,

        elliptice!'(~m) => num_elliptic(d_function,pi/2,sqrt(1-m^2))
                         when lisp !*rounded and numberp m
}$
let jacobierules;


%######################################################################
%CALCULATING ZETA

procedure num_jacobizeta(u,m);
% computes the JacobiZeta function
begin scalar phi_list, clist, z, cn, phi;

   phi_list := rest phi_function(1,sqrt(1-m^2),m,u);
   clist := rest reverse third agm_function(1,sqrt(1-m^2),m);

   z := 0;
   foreach phi in phi_list do  <<
      cn := first clist;
      z := cn*sin(phi) + z;
      clist := rest clist;
   >>;
   return z
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%JacobiZETA definition
%=====================

operator jacobizeta;

jacobizetarules :=

{

        jacobizeta(~u,0)     => 0,
        jacobizeta(~u,1)     => tanh(u),
        jacobizeta(-~u,~m)   => -jacobizeta(u,m),
        jacobizeta(~u,-~m)   => jacobizeta(u, m),
        jacobizeta(0,~m)     => 0,
	jacobizeta(elliptick(~m), ~m) => 0,

% periodicity

    jacobizeta((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
         if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
         return jacobizeta(arg, m);
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

% quasi-periodicity
    jacobizeta((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
         return jacobizeta(arg, m) - i*pi*shift/(2*elliptick(m));
      end)
      when ((ratnump(ip) and abs(ip) >= 2) where ip => impart(k/d)),
      
        jacobizeta((~u+~v)/~~d,~m) => jacobizeta(u/d,m) + jacobizeta(v/d,m)
	   - m^2*jacobisn(u/d,m)*jacobisn(v/d,m)*jacobisn((u+v)/d,m),
        jacobizeta(2*~u,~m) =>
             2*jacobizeta(u,m) - m^2*jacobisn(u,m)^2*jacobisn(2*u,m),

        jacobizeta(~u+2*elliptick(~m),m) => jacobizeta(u,m),
        jacobizeta(elliptick(~m) -~u,m) => -jacobizeta(elliptick(m)+u,m),

        jacobizeta(~u,~m) => num_elliptic(num_jacobizeta,u,m)
                             when lisp !*rounded and numberp u
                             and numberp m,

%derivative rules
       df(jacobizeta(~u, ~k),~u) => jacobidn(u,k)^2 - elliptice(k)/elliptick(k),
       
       df(jacobizeta(~u, ~k),~k) => df(elliptice(u,k),k) - u*df(elliptice(k)/elliptick(k), k)
 
}$
let jacobizetarules;

%#######################################################################
% CALCULATING THE FOUR THETA FUNCTIONS
% These theta functions differ from those originally defined by Lisa Temme
% in that the periods are 2*pi, 2*pi, pi and pi respectively 
% (NOT 4K, 4K, 2K and 2K).
% Also the second argument is the nome q where |q| < 1 and hence
% the quasi-period is -i*log q (NB for q real log q < 0).
% theta1 and theta2 are consequently multi-valued owing to the appearance
% of q^(1/4) in their defining expansions.
% The numerical code always returns the principal value of theta1 and theta2
% that is the one obtained by taking the principal value of q^(1/4).
% Thus the negative real-axis of q is a branch cut with the cut line
% regarded as belonging to the second rather than the third quadrant.
%
% Regarded as functions of the 'parameter' (usually denoted by tau where
% q = exp(i*pi*tau)), theta1 and theta2 are single-valued functions of tau.
% Note in this case q^(1/4) is interpreted as exp(i*pi*tau/4) rather than
% the principal value of q^(1/4). Thus tau and 2+tau, 4+tau and 6+tau produce
% four different values of both theta1 and theta2 although they produce the
% same nome q.
%
% Again we are following the conventions of DF Lawden:
% Elliptic Functions & Applications, Springer, 1989
%
% The series for the theta functions are fairly rapidly convergent 
% due to the quadratic growth of the exponents of q except 
% for values of q for which |q| is near to 1.
% In such cases the direct algorithm 
% would suffer from slow convergence and rounding errors.
% For such values of |q| Jacobi's transformation (tau'=-1/tau) can
% be used to produce a smaller value of the nome and so
% increase the rate of convergence.
% When repart(q) < 0 the Jacobi transformation is preceded by the
% modular transformation tau' = 1+tau, which has the effect  of multiplying
% q by -1, so that the new nome has a non-negative real part.
%
% This works very well for real values of q, but for complex values the
% gains are somewhat smaller.
% For nomes whose modulus is near to 1 the Jacobi transformation produces
% a nome q' for which |q'| ~ |q|^(alpha^2) where alpha = pi/|arg(q)| >= 2.
% Thus the worst case occurs for values of the nome q near to +i or -i
% where alpha ~ 2$.

% Somewhat arbitrarily Jacobi's transformation is used 
% whenever |q| >= 0.8. This seems to produce reasonable behaviour.

procedure shift!-arg(z,q);
% shift the argument down into the base period parallelogram
begin scalar quasip, rpq, numhqp, numhrp;
  quasip := -log q;
  rpq := repart quasip;
  numhqp := fix(2*impart(z)/rpq);  % number of half quasi-periods used
  z := z - i*numhqp*quasip/2;
  numhrp := fix(2*repart(z)/pi);   % number of half real periods used
  z := z - numhrp*pi/2;
  return {z, numhrp, numhqp};
end;

procedure n_theta1(z, q);
begin scalar n, pow, term, total, tol;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    n := 0;

    repeat <<
       pow := (-1)^n*q^(n*(n+1));
       term := pow*sin((2*n+1)*z);
       total := total + term;
       n := n+1;
    >> until total = 0 or
          max(abs(pow),abs(term)) < abs(total)*tol;
    return 2*sqrt(sqrt q)*total;
end;    

procedure num_theta1(z,q);
   if abs(q) >= 1.0 then
      rederr "num_theta1: the nome q (2nd arg) must satisfy |q| < 1"
   else if repart q < 0 then
      % apply the modular transformation tau' = 1+tau (so that q' = -q)
      (begin scalar x;
          if impart q < 0  then x := -1 else x := 1;
          return (1+i*x)*num_theta1(z, -q)/sqrt 2;
      end)
   else if abs(q) < 0.8  then
       num1_theta1(z,q) 
   else begin scalar x, m, l, a1, a2, q1;
      % Use Jacobi transformation theta1(i*x*z, q')
      l := log q;
      % calculate the 4th root of unity required to correct the 
      % result of the Jacobi transformation to the principal  value 
      a1 := -pi^2*impart(l)/(repart(l)^2+impart(l)^2);
      x := -pi/l;   % x = -i*tau'
      q1 := exp(-pi*x);
      a2 := arg q1;
      m := exp(i*(a1-a2)/4);
      m := -i*m*sqrt x*exp(-x*z^2/pi);
      return m*num1_theta1(i*x*z, q1);
   end;

procedure num1_theta1(z, q);
begin scalar shiftvalues, nr, nq, m;
   shiftvalues := shift!-arg(z,q);
   z:= first shiftvalues;
   nr := second shiftvalues;
   nq := third shiftvalues;

   nr := nr mod 4;
   if nr = 2 or nr=3 then m :=-1 else m := 1;
   if evenp nr then 
      if evenp nq then <<
         nq := nq/2;
         m := m*(-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
         return m*n_theta1(z, q);
      >> 
      else <<
          nq := (nq-1)/2;
          m := m*(-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
          return m*n_theta4(z,q);
       >>
    else
       if evenp nq then <<
          nq := nq/2;
          m := m*exp(-2*i*nq*z)/q^(nq^2);
          return m*n_theta2(z, q);
       >>
       else <<
          nq := (nq-1)/2;
          m := m*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
          return m*n_theta3(z, q);
       >>;
end;

procedure n_theta2(z,q);
begin scalar n, pow, term, total, tol;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    n := 0;
    repeat <<
       pow := q^(n*(n+1));
       term := pow*cos((2*n+1)*z);
       total := total +  term; 
       n := n+1;
    >> until max(abs(pow),abs(term)) < abs(total)*tol;
    return 2*sqrt(sqrt q)*total;
end;

procedure num_theta2(z,q);
   if abs(q) >= 1.0 then
      rederr "num_theta2: the nome q (2nd arg) must satisfy |q| < 1"
   else if repart q < 0 then
      % apply the modular transformation tau' = 1+tau (so that q' = -q)
      (begin scalar x;
          if impart q < 0  then x := -1 else x := 1;
          return (1+i*x)*num_theta2(z, -q)/sqrt 2;
      end)
   else if abs(q) < 0.8 then
       num1_theta2(z,q)
   else begin scalar x, m;
       % Use Jacobi transformation theta4(i*x*z, q')
       x := -pi/log q;   % x = -i*tau'
       m := sqrt x*exp(-x*z^2/pi);
       return m*num1_theta4(i*x*z, exp(-pi*x));
   end;


procedure num1_theta2(z,q);
begin scalar shiftvalues, nr, nq, m;
   shiftvalues := shift!-arg(z,q);
   z:= first shiftvalues;
   nr := second shiftvalues;
   nq := third shiftvalues;

   nr := nr mod 4;
   if nr = 2 or nr=3 then m :=-1 else m := 1;
   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := m*exp(-2*i*nq*z)/q^(nq^2);
         return m*n_theta2(z, q);
      >>
      else <<
         nq := (nq-1)/2;
         m := m*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
         return m*n_theta3(z,q);
      >>
   else
      if evenp nq then <<
         nq := nq/2;
         m := m*(-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
	 return -m*n_theta1(z, q);
      >>
      else <<
         nq := (nq-1)/2;
         m := m*(-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
         return -m*n_theta4(z, q);
      >>;
end;

procedure n_theta3(z, q);
begin scalar n, pow, term, total, tol;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;

   repeat <<
      pow := q^(n*n);
      term := pow*cos(2*n*z);
      total := total + term;
      n := n+1;
   >> until max(abs(pow),abs(term)) < abs(total)*tol;
   return 1 + 2*total;
end;


procedure num_theta3(z,q);
   if abs(q) >= 1.0 then
      rederr "num_theta3: the nome q (2nd arg) must satisfy |q| < 1"
   else if repart q < 0 then
      % apply the modular transformation tau' = 1+tau (so that q' = -q)
      num_theta4(z, -q)
   else if abs(q) < 0.8 then
      num1_theta3(z, q)
   else begin scalar x, m;
      % Use Jacobi transformation theta3(i*x*z, q')
      x := -pi/log q;   % x = -i*tau'
      m := sqrt x*exp(-x*z^2/pi);
      return m*num1_theta3(i*x*z, exp(-pi*x));
   end;


procedure num1_theta3(z,q);
begin scalar shiftvalues, nr, nq, m;
   shiftvalues := shift!-arg(z,q);
   z:= first shiftvalues;
   nr := second shiftvalues;
   nq := third shiftvalues;

   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := exp(-2*i*nq*z)/q^(nq^2);
         return m*n_theta3(z, q);
      >>
      else <<
         nq := (nq-1)/2;
         m := exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
	 return m*n_theta2(z,q);
       >>
    else
       if evenp nq then <<
          nq := nq/2;
          m := (-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
          return m*n_theta4(z, q);
       >>
       else <<
          nq := (nq-1)/2;
          m := (-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
          return m*n_theta1(z, q);
       >>;
end;

procedure n_theta4(z, q);
begin scalar n, pow, term, total, tol;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;

   repeat <<
      pow := (-1)^n*q^(n*n);
      term := pow*cos(2*n*z);
      total := total + term;
      n := n+1;
   >> until max(abs(pow),abs(term)) < abs(total)*tol;
   return 1 + 2*total;
end;

procedure num_theta4(z,q);
   if abs(q) >= 1.0 then
      rederr "num_theta4: the nome q (2nd arg) must satisfy |q| < 1"
   else if repart q < 0 then
      % apply the modular transformation tau' = 1+tau (so that q' = -q)
      num_theta3(z, -q)
   else if abs(q) < 0.8 then
      num1_theta4(z, q)
   else begin scalar x, m, l, a1, a2, q1;
      % Use Jacobi transformation theta2(i*x*z, q')
      l := log q;
      % calculate the 4th root of unity required to correct the 
      % result of the Jacobi transformation to the principal  value 
      a1 := -pi^2*impart(l)/(repart(l)^2+impart(l)^2);
      x := -pi/l;   % x = -i*tau'
      q1 := exp(-pi*x);
      a2 := arg q1;
      m := exp(i*(a1-a2)/4);  
      m := m*sqrt x*exp(-x*z^2/pi);
      return m*num1_theta2(i*x*z, q1);
   end;

procedure num1_theta4(z, q);
begin scalar shiftvalues, nr, nq, m;
   shiftvalues := shift!-arg(z,q);
   z:= first shiftvalues;
   nr := second shiftvalues;
   nq := third shiftvalues;

   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := (-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
         return m*n_theta4(z, q);
      >>
      else <<
         nq := (nq-1)/2;
         m := (-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
         return m*n_theta1(z,q);
      >>
   else
      if evenp nq then <<
	 nq := nq/2;
	 m := exp(-2*i*nq*z)/q^(nq^2);
         return m*n_theta3(z, q);
      >>
      else <<
         nq := (nq-1)/2;
	 m := exp(-(2*nq+1)*i*z)/q^(nq^2+nq+1/4);
	 return m*n_theta2(z, q);
      >>;
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

operator elliptictheta1;
operator elliptictheta2;
operator elliptictheta3;
operator elliptictheta4;
operator nome2mod;
operator nome2mod!';
operator nome2!K;
operator nome2!K!';

ellipticthetarules :=
{
  
%Theta1rules

   elliptictheta1(-~u,~m) => -elliptictheta1(u,m),

   elliptictheta1(0,~m) => 0,

   elliptictheta1(~u, 0) => 0,

%  This rule implements the modular transformation tau'=1+tau (so q'=-q)
%  for real nomes only
   elliptictheta1(~u, -~m) => exp(i*sign(m)*pi/4)*elliptictheta1(u, m)
                when impart(m) = 0,
		
%   The following version of the rule is quite general but messy
%   elliptictheta1(~u, -~m) =>
%       (begin scalar s;
%	    s := (sign(repart m)-sign(repart m)^2+1)
%	           * (sign(impart m)-sign(impart m)^2+1);
%            return (1+s*i)*elliptictheta1(u, m)/sqrt 2;
%        end),

% generalised shift rules added by A Barnes
% periodicity:
   elliptictheta1((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar n, arg, r, s;
          n := fix(2*repart(k/d));
          r := n mod 4;
	  arg := w/d + ((k/d)-n/2)*pi;
	  if r=2 or r=3 then s := -1 else s := 1;
	  if evenp n then
	     return s*elliptictheta1(arg, m)
	  else
	     return s*elliptictheta2(arg, m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

% quasi-periodicity:
   elliptictheta1((~~w + ~~k*log(~m))/~~d, ~m) =>
      (begin scalar n, arg, f;
          n := fix(2*impart(k/d));
	  arg := w/d + ((k/d)-i*n/2)*log m;
	  if evenp n then <<
	     n := n/2;
	     f := (-1)^n*exp(2*i*n*arg)/m^(n^2);
             return f*elliptictheta1(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^(n+1)*i*exp((2*n+1)*i*arg)/m^(n^2+n+1/4);
	     return f*elliptictheta4(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta1(~u,~m) => num_elliptic(num_theta1,u,m)
       when lisp !*rounded and numberp u and numberp m,

%Theta2rules
%-----------
   elliptictheta2(-~u,~m) =>  elliptictheta2(u,m),

   elliptictheta2(~u, 0) => 0,
   
%  This rule implements the modular transformation tau'=1+tau (so q'=-q)
%  for real nomes only
   elliptictheta2(~u, -~m) => exp(i*sign(m)*pi/4)*elliptictheta2(u, m)
                                  when impart m=0,

%   The following version of the rule is quite general but messy
%   elliptictheta2(~u, -~m) =>
%        (begin scalar s;
%	    s := (sign(repart m)-sign(repart m)^2+1)
%	           * (sign(impart m)-sign(impart m)^2+1);
%            return (1+s*i)*elliptictheta2(u, m)/sqrt 2;
%         end),

% periodicity:
   elliptictheta2((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar n, arg, r, s;
          n := fix(2*repart(k/d));
          r := n mod 4;
	  arg := w/d + ((k/d)-n/2)*pi;
	  if r=2 or r=3 then s := -1 else s := 1;
	  if evenp n then
	     return s*elliptictheta2(arg, m)
	  else
	     return -s*elliptictheta1(arg, m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

% quasi-periodicity:
   elliptictheta2((~~w + ~~k*log(~m))/~~d, ~m) =>
      (begin scalar n, arg, f;
          n := fix(2*impart(k/d));
	  arg := w/d + ((k/d)-i*n/2)*log m;
	  if evenp n then <<
	     n := n/2;
	     f := exp(2*i*n*arg)/m^(n^2);
             return f*elliptictheta2(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := exp((2*n+1)*i*arg)/m^(n^2+n+1/4);
	     return f*elliptictheta3(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta2(~u,~m) => num_elliptic(num_theta2,u,m)
            when lisp !*rounded and numberp u and numberp m,

%Theta3rules
%-----------

   elliptictheta3(-~u,~m) =>  elliptictheta3(u,m),

   elliptictheta3(~u, 0) => 1,
   
%  This rule implements the modular transformation tau'=1+tau (so q'=-q)
   elliptictheta3(~u, -~m) => elliptictheta4(u, m),

% periodicity:
   elliptictheta3((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar n, arg;
          n := fix(2*repart(k/d));
	  arg := w/d + ((k/d)-n/2)*pi;
	  if evenp n then
	     return elliptictheta3(arg, m)
	  else
	     return elliptictheta4(arg, m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

% quasi-periodicity:
   elliptictheta3((~~w + ~~k*log(~m))/~~d, ~m) =>
      (begin scalar n, arg, f;
          n := fix(2*impart(k/d));
	  arg := w/d + ((k/d)-i*n/2)*log m;
	  if evenp n then <<
	     n := n/2;
	     f := exp(2*i*n*arg)/m^(n^2);
             return f*elliptictheta3(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := exp((2*n+1)*i*arg)/m^(n^2+n+1/4);
	     return f*elliptictheta2(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta3(~u,~m) => num_elliptic(num_theta3,u,m)
        when lisp !*rounded and numberp u and numberp m,

%Theta4rules
%-----------

   elliptictheta4(-~u,~m) =>  elliptictheta4(u,m),

   elliptictheta4(~u, 0) => 1,
   
%  This rule implements the modular transformation tau'=1+tau (so q'=-q)
   elliptictheta4(~u, -~m) => elliptictheta3(u, m),

% periodicity:
   elliptictheta4((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar n, arg;
          n := fix(2*repart(k/d));
	  arg := w/d + ((k/d)-n/2)*pi;
	  if evenp n then
	     return elliptictheta4(arg, m)
	  else
	     return elliptictheta3(arg, m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

% quasi-periodicity:
   elliptictheta4((~~w + ~~k*log(~m))/~~d, ~m) =>
      (begin scalar n, arg, f;
          n := fix(2*impart(k/d));
	  arg := w/d + ((k/d)-i*n/2)*log m;
	  if evenp n then <<
	     n := n/2;
	     f := (-1)^n*exp(2*i*n*arg)/m^(n^2);
             return f*elliptictheta4(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^(n+1)*i*exp((2*n+1)*i*arg)/m^(n^2+n+1/4);
	     return f*elliptictheta1(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta4(~u,~m) => num_elliptic(num_theta4,u,m)
        when lisp !*rounded and numberp u and numberp m,

   % Below for numerical evaluation it is much better to use theta
   % functions evaluated at zero rather than direct series summations
   % as modular transformations can be used to speed up convergence
   % when |q| is near to one.

   nome2mod(~q) => (elliptictheta2(0,q)/elliptictheta3(0,q))^2,
	
   nome2mod!'(~q) =>  (elliptictheta4(0,q)/elliptictheta3(0,q))^2,
 
   nome2!K(~q) => pi*elliptictheta3(0,q)^2/2,

   nome2!K!'(~q) => -log q*elliptictheta3(0,q)^2/2
}$
let ellipticthetarules;
  
endmodule;
end;



