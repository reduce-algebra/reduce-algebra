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

% $Id$

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

   df(ellipticf(~u,~k),~k) => (elliptice(u,k)/(k^2-1)+ellipticf(u,k))/k
                          + k*sin(u)*cos(u)/((k^2-1)*sqrt(1-k^2*sin(u)^2)),

   ellipticf(~phi,~m)  => num_elliptic(f_function,phi,m)
            when lisp !*rounded and numberp repart phi and numberp impart phi
                 and numberp repart m and numberp impart m
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
	       when lisp !*rounded and numberp repart m and numberp impart m,

        elliptick!'(~m) => num_elliptic(k_function, sqrt(1-m^2))
	       when lisp !*rounded and numberp repart m and numberp impart m,

        nome(0) => 0,

        nome(1) => 1,

        nome(~m) => exp(-pi*elliptick!'(m)/elliptick(m))
	       when lisp !*rounded and numberp repart m and numberp impart m
}$
let elliptickrules;

% ######################################################################
% VALUE OF JacobiE(phi,m)

procedure je_function(phi,m);
  e_function(num_jacobiam(phi, m), m);

procedure e_function(phi, m);
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


% EllipticE(phi, m) definition     Legendre's form of elliptic integral
% ============================     of the second kind.

% operator elliptice; % already defined in sfellip.red

jacobidrules :=
{
        elliptice(0,~m)     => 0,
        elliptice(~phi,0)   => phi,
        elliptice(i*~phi,0) => i*phi,
        elliptice(~phi,1)   => sin(phi),
        elliptice(i*~phi,1) => i*sinh(phi),
        elliptice(-~phi,~k) => -elliptice(phi,k),
        elliptice(~phi,-~k) =>  elliptice(phi,k),
	elliptice(pi/2,~k)  =>  elliptice(k),

% quasi-periodicity

   elliptice((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(2*k/d);
 	 arg := w/d + ((2*k/d)-shift)*pi/2;
         return elliptice(arg, m) + shift*elliptice(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(2*k/d)),

% ************************************************
% derivative rules 
    df(elliptice(~phi,~m),~phi) => sqrt(1-m^2*sin(phi)^2),

    df(elliptice(~phi,~m),~m)   => (elliptice(phi,m)-ellipticf(phi,m))/m,

    elliptice(~phi,~m) => num_elliptic(e_function,phi,m)
            when lisp !*rounded and numberp repart phi and numberp impart phi
                 and numberp repart m and numberp impart m
}$

let jacobidrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%JacobiE(phi,m) definition   Jacobi's form of the elliptic integral
%=========================   of the second kind.
% There is often confusion between Jacobi's form of the incomplete elliptic 
% integral of the 2nd kind jacobie(u,k) and Legendre's form elliptice(phi,k)
% where elliptice(am(u,k), k) = jacobie(u, k)
% Following the NIST Digital Library of Mathematical Functions recommendations
% elliptice will now denote the Legendre form (was previously ellipticd) with
% jacobie denoting the Jacobi form (was formerly elliptice).
% On output on GUIs jacobie should be rendered as \mathcal{E} and
% elliptice by \mathrm{E}. 
%
% The e_function(u, k) and d_functions(u,k) originally evaluated JacobiE(u,k)
% and EllipticE(u,k) numerically.
% This e_function has been renamed as je_function and the d_function
% renamed as e_function.

% operator jacobie;  % already defined in sfellip.red

jacobierules :=

{
        jacobie(0,~m)     => 0,
        jacobie(~phi,0)   => phi,
        jacobie(i*~phi,0) => i*phi,
        jacobie(~phi,1)   => tanh(phi),
        jacobie(i*~phi,1) => i*tan phi,
        jacobie(-~phi,~m) => -jacobie(phi,m),
        jacobie(~phi,-~m) =>  jacobie(phi,m),
	jacobie(elliptick(~m), ~m) => elliptice(m),

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

   jacobie((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
         if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
         return jacobie(arg, m) + shift*elliptice(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

    jacobie((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 if not evenp shift then shift := shift-1;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
         return jacobie(arg, m) + shift*i*(elliptick!'(m) - elliptice!'(m));
      end)
      when ((ratnump(ip) and abs(ip) >= 2) where ip => impart(k/d)),

% quasi-addition

       jacobie((~u+~v)/~~d,~m) => jacobie(u/d,m) + jacobie(v/d,m)
         - m^2*jacobisn(u/d,m)*jacobisn(v/d,m)*jacobisn((u+v)/d,m),

       jacobie(2*~u,~m) =>
          2*jacobie(u,m) - m^2*jacobisn(u,m)^2*jacobisn(2*u,m),
	  
% derivative rules 
        df(jacobie(~phi,~m),~phi) => jacobidn(phi,m)^2,
	
        df(jacobie(~phi,~m),~m)   =>
            m*(jacobisn(phi,m)*jacobicn(phi,m)*jacobidn(phi,m)
               - jacobie(phi,m)*jacobicn(phi,m)^2) / (1-m^2)
            - m*phi*jacobisn(phi,m)^2,

        df(elliptice(~m),~m) => (elliptice(m)-elliptick(m))/m,

        df(elliptick(~m),~m) =>
	         (elliptice(m)/(1-m^2)-elliptick(m))/m,

        df(elliptice!'(~m),~m) => m*(elliptick!'(m) - elliptice!'(m))/(1-m^2),

        df(elliptick!'(~m),~m) =>
	         (m*elliptick!'(m)-elliptice!'(m)/m)/(1-m^2),

% numerical evaluation

        jacobie(~phi,~m) => num_elliptic(je_function,phi,m)
            when lisp !*rounded and numberp repart phi and numberp impart phi
                 and numberp repart m and numberp impart m,

        elliptice(~m) => num_elliptic(e_function,pi/2,m)
            when lisp !*rounded and numberp repart m  and numberp impart m,

        elliptice!'(~m) => num_elliptic(e_function,pi/2,sqrt(1-m^2))
            when lisp !*rounded and numberp repart m  and numberp impart m
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
            when lisp !*rounded and numberp repart u and numberp impart u
                 and numberp repart m  and numberp impart m,             

%derivative rules
       df(jacobizeta(~u, ~k),~u) => jacobidn(u,k)^2 - elliptice(k)/elliptick(k),
       
       df(jacobizeta(~u, ~k),~k) => df(elliptice(u,k),k) - u*df(elliptice(k)/elliptick(k), k)
 
}$
let jacobizetarules;

% Support for theta functions moved to a separate file (sftheta.red).

endmodule;
end;



