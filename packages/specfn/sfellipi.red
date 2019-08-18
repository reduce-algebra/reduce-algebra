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
        ellipticf(i*~phi,0) => i*phi,
        ellipticf(~phi,1)   => ln(sec(phi)+tan(phi)),
        ellipticf(i*~phi,1) => i*atan(sinh(phi)),
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
        ellipticd(-~phi,~m) => -ellipticd(phi,m),
        ellipticd(~phi,-~m) =>  ellipticd(phi,m),

% ************************************************
% derivative rules 
        df(ellipticd(~phi,~m),~phi) => sqrt(1-m^2*sin(phi)^2),

%        df(ellipticd(~phi,~m),~m)   =>
%            m*(jacobisn(phi,m)*jacobicn(phi,m)*jacobidn(phi,m)
%               - elliptice(phi,m)*jacobicn(phi,m)^2) / (1-m^2)
%            - m*phi*jacobisn(phi,m)^2,

ellipticd(~phi,~m) => num_elliptic(d_function,phi,m)
                              when lisp !*rounded and numberp phi
                              and numberp m
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
        elliptice(0)     => pi/2,
        elliptice(1)     => 1,
	elliptick(0)     => pi/2,
	elliptick!'(1)   => pi/2,
        elliptice!'(0)   => 1,	
        elliptice!'(1)   => pi/2,
	
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
	         (m*elliptick!'(m)-elliptice(m)/m)/(1-m^2),

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

%       JacobiZeta(~u,~m) => JacobiZeta(u - EllipticK(m),m) -
%                            m * Jacobisn(u - EllipticK(m),m)
%                              * Jacobicd(u - EllipticK(m),m),

        jacobizeta(~u,~m) => num_elliptic(num_jacobizeta,u,m)
                             when lisp !*rounded and numberp u
                             and numberp m
}$
let jacobizetarules;

%#######################################################################
% CALCULATING THE FOUR THETA FUNCTIONS
% These theta functions differ from those originally defined by Lisa Temme
% in that the periods are 2*pi, 2*pi, pi and pi respectively 
% (NOT 4K, 4K, 2K and 2K).
% Also the second argument is the nome q where |q| < 1 and hence
% the quasi-period is -i*log q (NB for q real log q < 0).
% Again we are following the conventions of DF Lawden:
% Elliptic Functions & Applications, Springer,1989

% The series for the theta functions are fairly rapidly convergent 
% due to the quadratic growth of the exponents of q except 
% for values of q for which abs q is near to 1. 
% For values of |q| near to 1 Jacobi's transformation can be used to
% produce a smaller value of the nome and so increase the rate of convergence.
% It is advantageous to first ensure that the nome has a positive real part.
% This works well for real q, but for complex values the situation is less
% clear: the value returned often differs from the 'correct' value by a factor
% which is a fourth root of unity.  The 'correct' values being the ones obtained
% from the defining series expansions and taking the principal value of q^(1/4) 
% in the expressions for theta1 and theta2 which are thus are multi-valued.
% How to choose the 'correct' branch for complex q is currently being
% investigated.

% Somewhat arbitrarily Jacobi's transformation is used 
% whenever |q|>0.75  This seems to produce reasonable behaviour subject to
% the proviso above.
% However, for purely real values of the nome q faster convergence could be
% obtained by using the Jacobi transformation when |q|> 0.5 or 0.4 (say).

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
   else if abs(q) < 0.7 then n_theta1(z,q)
   else begin scalar x, y;
       if repart q < 0 then <<
          if impart q < 0 then x := -1 else x := 1;
          return exp(i*x*pi/4)*num_theta1(z, -q);
       >>;

       % Use Jacobi transformation theta1(i*x*z, q')
       y := log q;
       x := -pi/y;   % x = -i*tau'
       return -i*sqrt(x)*exp(z^2/y)*n_theta1(i*x*z, exp(-pi*x));
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
   else if abs(q) < 0.75 then n_theta2(z, q)
   else begin scalar x, y;
       if repart q < 0 then <<
          if impart q < 0 then x := -1 else x := 1;
          return exp(i*x*pi/4)*num_theta2(z, -q);
       >>;

       % Use Jacobi transformation theta4(i*x*z, q')
       y := log q;
       x := -pi/y;   % x = -i*tau'
       return sqrt(x)*exp(z^2/y)*n_theta4(i*x*z, exp(-pi*x));
   end; 

procedure n_theta3(z,q);
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
   else if abs(q) < 0.75 then n_theta3(z, q)
   else if repart q < 0 then num_theta4(z, -q)
   else begin scalar x, y;
      % Use Jacobi transformation  theta3(i*x*z, q')
      y := log q;
      x := -pi/y;   % x = -i*tau'
      return sqrt(x)*exp(z^2/y)*n_theta3(i*x*z, exp(-pi*x));
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
   else if abs(q) < 0.75 then n_theta4(z, q)
   else if repart q < 0 then num_theta3(z, -q)
   else begin scalar x, y;
      % Use Jacobi transformation  theta2(i*x*z, q')
      y := log q;
      x := -pi/y;   % x = -i*tau'
      return sqrt(x)*exp(z^2/y)*n_theta2(i*x*z, exp(-pi*x));
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
%-----------
   elliptictheta1(-~u,~m) => -elliptictheta1(u,m),

   elliptictheta1(0,~m) => 0,

   elliptictheta1(~u, 0) => 0,

   elliptictheta1(~u, -~m) => exp(i*sign(m)*pi/4)*elliptictheta1(u, m)
                when impart(m) = 0,
 
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
	     f := (-1)^n*exp(-2*i*n*arg)/m^(n^2);
             return f*elliptictheta1(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^n*i*exp(-(2*n+1)*i*arg)/m^(n^2+1/4);
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
   
   elliptictheta2(~u, -~m) => exp(i*sign(m)*pi/4)*elliptictheta2(u, m)
                when impart(m) = 0,

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
	     f := exp(-2*i*n*arg)/m^(n^2);
             return f*elliptictheta2(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := exp(-(2*n+1)*i*arg)/m^(n^2+1/4);
	     return f*elliptictheta2(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta2(~u,~m) => num_elliptic(num_theta2,u,m)
            when lisp !*rounded and numberp u and numberp m,

%Theta3rules
%-----------

   elliptictheta3(-~u,~m) =>  elliptictheta3(u,m),

   elliptictheta3(~u, 0) => 1,
   
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
	     f := exp(-2*i*n*arg)/m^(n^2);
             return f*elliptictheta3(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := exp(-(2*n+1)*i*arg)/m^(n^2+1/4);
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
	     f := (-1)^n*exp(-2*i*n*arg)/m^(n^2);
             return f*elliptictheta4(arg, m);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^n*i*exp(-(2*n+1)*i*arg)/m^(n^2+1/4);
	     return f*elliptictheta1(arg,m);
	  >>;
      end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => 2*impart(k/d)),

   elliptictheta4(~u,~m) => num_elliptic(num_theta4,u,m)
        when lisp !*rounded and numberp u and numberp m,

   nome2mod(~m) => num_elliptic(num_mod, m)
        when lisp !*rounded and numberp m,
	
   nome2mod!'(~m) => num_elliptic(num_mod!', m)
        when lisp !*rounded and numberp m,
	
   nome2!K(~m) => num_elliptic(num_ellipK, m)
        when lisp !*rounded and numberp m,

   nome2!K!'(~m) => num_elliptic(num_ellipK!', m)
        when lisp !*rounded and numberp m
}$
let ellipticthetarules;

procedure num_mod(q);
   if abs(q) >= 1.0 then
      rederr "num_mod: the nome q must satisfy |q| < 1"
   else begin scalar n, pow, total1, total2, res, res0, tol;
       tol := 10.0^-(symbolic !:prec!:);
       total1 := 1.0;
       total2 := 1.0;
       res := 1.0;
       n := 1;

       repeat <<
             res0 := res;
             pow := q^(n*n);
             total2 := total2 + 2.0*pow;
	     total1 := total1 + pow*q^n;
	     res := (total1/total2)^2;
             n := n+1;
          >> until  abs(res-res0) < abs(res)*tol;
       return 4.0*sqrt(q)*res;
   end;

procedure num_mod!'(q);
   if abs(q) >= 1.0 then
      rederr "num_mod': the nome q must satisfy |q| < 1"
   else begin scalar n, pow, total1, total2, res, res0, tol;
       tol := 10.0^-(symbolic !:prec!:);
       total1 := 1.0;
       total2 := 1.0;
       res := 1.0;
       n := 1;
       
       repeat <<
             res0 := res;
             pow := 2.0*q^(n*n);
             total2 := total2 + pow;
	     total1 := total1 + (-1)^n*pow;
	     res := (total1/total2)^2;
             n := n+1;
          >> until  abs(res-res0) < abs(res)*tol;
       return res;
   end;

procedure num_ellip1(q);
   if abs(q) >= 1.0 then
      rederr "num_ellipK: the nome q must satisfy |q| < 1"
   else begin scalar n, pow, total, tol;
       tol := 10.0^-(symbolic !:prec!:);
       total := 1.0;
       n := 1;

       repeat <<
             pow := 2.0*q^(n*n);
             total := total + pow;
             n := n+1;
          >> until  abs(pow) < abs(total)*tol;
       return total^2/2.0;
   end;

procedure num_ellipK(q);
  pi*num_ellip1(q);
  
procedure num_ellipK!'(q);
  -log(q)*num_ellip1(q);
  
endmodule;
end;



