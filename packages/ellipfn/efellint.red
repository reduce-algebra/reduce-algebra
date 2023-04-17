module efellint;  % Procedures and Rules for Elliptic Integrals.

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

% $Id: sfellipi.red 5874 2021-07-30 21:08:56Z arthurcnorman $
% Renamed (was sfellipi) and moved to a new package ellipfn, December 2021
% by Alan Barnes
algebraic;

algebraic procedure pi_shift(x);
   begin scalar n, sgn;
      sgn := 1;
      if repart x < 0 then <<
	 x := -x;
	 sgn := -1
      >>;
      n := fix (repart(x)/pi);
      x := x-n*pi;
      if repart x > pi/2 then <<
	 n := n+1;
         x := x - pi;
      >>;
      return {sgn*x,sgn*n};
   end;
	 
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticF definition
%====================

operator ellipticf;

ellipticfrules :=
{
   % incomplete elliptic integral of the first kind      
   ellipticf(~phi,0)   => phi,
   ellipticf(~phi,1)   => (log(1+sin phi)-log(1-sin phi))/2,
   ellipticf(0, ~k)    => 0,
   ellipticf(-~phi,~k) => -ellipticf(phi,k),
   ellipticf(~phi,-~k) => ellipticf(phi,k),
   
   ellipticf(i*~phi,0) => i*phi,
   ellipticf(i*~phi,1) => i*atan(sinh(phi)),
   ellipticf(pi/2,~k)  =>  elliptick(k),
   
% quasi-periodicity
   
    ellipticf((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
	 arg := w/d +(k/d-shift)*pi;
	 return ellipticf(arg, m) + 2*shift*elliptick(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

% derivative rule
   df(ellipticf(~u,~k),~x) => df(u,x)/sqrt((1-k^2*sin(u)^2)) +
                 df(k,x)*((elliptice(u,k)/(1-k^2)-ellipticf(u,k))/k
                           - k*sin(u)*cos(u)/((1-k^2)*sqrt(1-k^2*sin(u)^2))),

   ellipticf(~phi,~m)  => num_ellf(phi,m)
      when lisp !*rounded and lisp !*complex and numberp phi and numberp m

}$
let ellipticfrules;

%######################################################################

% incomplete elliptic integral of the first kind
algebraic procedure num_ellf(phi,k);
   if k=0 then phi
   else if phi = pi/2 or phi = -pi/2 then sign(phi)*num_ellk(k)
   else if k=1 or k=-1 and impart(phi)=0 and abs phi <pi/2 then
      (log((1+s)/(1-s))/2) where s => sin phi
   else begin scalar l;
      l := pi_shift phi;
      if second l neq 0 then
      	 return second(l)*num_ellk(k) + num_ellf(first l, k)
      else
	 return num_elliptic(num2_asn, sin phi, k);
   end;

% complete elliptic integral of the first kind
algebraic procedure num_ellk(k);
   if k=1 or k=-1 then
      rederr("Logarithmic Singularity")
   else if k = 0 then pi/2
   else if impart(k) = 0 and abs(k)>1 then
      (RF(0, 1-1/k^2, 1) - i*RF(0, 1/k^2, 1))/abs k
   else
      RF(0,1-k^2,1);

% complementary elliptic integral
% NB the identity K'(k)=K(k') only holds if repart k >= 0.
algebraic procedure num_ellkc(k);
   if k=0 then
      rederr("Logarithmic Singularity")
   else if repart k > 0 or (repart k = 0 and impart k > 0) then
      num_ellk(sqrt(1-k^2))
   else <<
      k := -k;
      if impart k>0 then
      	 num_ellk(sqrt(1-k^2)) + 2i*num_ellk(k)
      else
	 num_ellk(sqrt(1-k^2)) - 2i*num_ellk(k)
   >>;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticK definition
%====================

operator nome;

elliptickrules :=

{% complete elliptic integral of first kind
        elliptick(-~k)    => elliptick(k),
	elliptick(0)      => pi/2,
	elliptick!'(1)    => pi/2,

        elliptick(~m)   => num_elliptic(num_ellk, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp m and m neq 1 and m neq -1,

        elliptick!'(~m) => num_elliptic(num_ellkc, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp m and m neq 0,

        nome(0) => 0,

        nome(1) => 1,

        nome(~m) => exp(-pi*elliptick!'(m)/elliptick(m))
}$
let elliptickrules;

% ######################################################################

algebraic procedure num_elle(phi,k);
   if k=0 then phi
   else if phi=pi/2 or phi =-pi/2 then sign(phi)*num_ellec(k)
   else if (k=1 or k=-1) and impart(phi)=0 and abs phi < pi/2 then sin phi
   else begin scalar l;
      l := pi_shift phi;
      if second l neq 0 then
	 return second(l)*num_ellec(k) + num_elle(first l, k)
      else
	 return num_ellf(phi, k)-k^2*num_elliptic(num_elld, phi, k);
   end;

algebraic procedure num_ellec(k);
   if k = 1 or k = -1 then 1
   else if k = 0 then pi/2
   else begin scalar kp2,rp,ip;
      if impart(k) = 0 and abs(k)>1 then <<
       	 kp2 := 1-1/k^2;
 	 % = k*(E(1/k)-K(1/k))+K(1/k)/k	 
	 rp := RF(0, kp2, 1)/abs k-RD(0, kp2, 1)/(3*abs k);
       	 kp2 := 1-kp2; % =1/k^2
       	 % k*E'(1/k)-K'(1/k)/k
       	 ip := k*(RD(0,kp2,1) + RD(0,1,kp2))*kp2/3-RF(0,kp2,1)/k;
	 return rp+i*ip;
      >> else <<
      	 kp2 := 1-k^2;
      	 return (RD(0, kp2, 1) + RD(0, 1, kp2))*kp2/3;
      >>;
   end;

% The identity E'(k) = E(k') only holds if repart k >= 0
algebraic procedure num_ellecp(k);
 if repart k > 0 or (repart k = 0 and impart k > 0) then
    num_ellec(sqrt(1-k^2))
 else <<
     k := -k;
     if impart k>0 then
      	 num_ellec(sqrt(1-k^2)) + 2i*(num_ellk(k)-num_ellec(k))
      else
	 num_ellec(sqrt(1-k^2)) - 2i*(num_ellk(k)-num_ellec(k))
   >>;
    
% EllipticE(phi, m) definition     Legendre's form of elliptic integral
% ============================     of the second kind.

% operator elliptice; % already defined in efjacobi.red

% Rule list renamed November 2022
ellipticerules :=
{
   % complete elliptic integral of second kind
   elliptice(-~k)    => elliptice(k),
   elliptice(0)      => pi/2,
   elliptice(1)      => 1,
   elliptice!'(0)    => 1,	
   elliptice!'(1)    => pi/2,

   % Legendre's form of the incomplete elliptic integral of second kind
   elliptice(0,~m)     => 0,
   elliptice(~phi,0)   => phi,
   elliptice(~phi,1)   => sin(phi),
   elliptice(i*~phi,0) => i*phi,
   elliptice(i*~phi,1) => i*sinh(phi),
   elliptice(-~phi,~k) => -elliptice(phi,k),
   elliptice(~phi,-~k) =>  elliptice(phi,k),
   elliptice(pi/2,~k)  =>  elliptice(k),

% quasi-periodicity

   elliptice((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
	 arg := w/d +(k/d-shift)*pi;
	 return elliptice(arg, m) + 2*shift*elliptice(m);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

% ************************************************
% derivative rule 
    df(elliptice(~phi,~m),~x) => df(phi,x)*sqrt(1-m^2*sin(phi)^2) +
                                 df(m,x)*(elliptice(phi,m)-ellipticf(phi,m))/m,

    elliptice(~phi,~m) => num_elle(phi,m)
       when lisp !*rounded and lisp !*complex and numberp phi and numberp m,
	     
    elliptice(~m) => num_elliptic(num_ellec, m)
            when lisp !*rounded and lisp !*complex and numberp  m,

    elliptice!'(~m) => num_elliptic(num_ellecp, m)
	   when lisp !*rounded and lisp !*complex and numberp m

}$

let ellipticerules;
% ====================================================================

% An alternative form of the incomplete elliptic integral of second kind
operator ellipticd;

ellipticdrules := {
   % complete elliptic integral of second kind
   ellipticd(-~k)    => ellipticd(k),
   ellipticd(0)      => pi/4,
   ellipticd(~phi,0)   => phi/2-sin(2*phi)/4,
   ellipticd(~phi,1)   => -sin(phi)+(log(1+sin phi)-log(1-sin phi))/2,
   ellipticd(0,~m)     => 0,
   ellipticd(-~phi,~k) => -ellipticd(phi,k),
   ellipticd(~phi,-~k) =>  ellipticd(phi,k),
   ellipticd(pi/2,~k)  =>  ellipticd(k),

   % quasi-periodicity
   
    ellipticd((~~w + ~~k*pi)/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
	 arg := w/d +(k/d-shift)*pi;
	 return ellipticd(arg, m) + 2*shift*ellipticd(m);
      end)
      	 when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   % ************************************************
% derivative rules
   df(ellipticd(~k),~k) => (-2*ellipticd(k)+elliptice(k)/(1-k^2))/k,
   
   df(ellipticd(~u,~k),~x) =>
       df(u,x)*(sin(u)^2/sqrt(1-k^2*sin(u)^2)) +
       	  df(k,x)*(-2*ellipticd(u,k)+
	     (elliptice(u,k)-sin(u)*cos(u)/sqrt(1-k^2*sin(u)^2))/(1-k^2))/k,
	  
    ellipticd(~phi,~m) => n_elld(phi,m)
       when lisp !*rounded and lisp !*complex and numberp phi and numberp m,
	     
   ellipticd(~m) => n_elldc(m)
       when lisp !*rounded and lisp !*complex and numberp m

}$

let ellipticdrules$

algebraic procedure n_elldc(k);
   if k = 0 then pi/4
   else if k= 1 or k=-1 then
      rederr "ellipticd(k) has a logarithmic singularity at k=1"
   else num_elliptic(num_elldc, k);

algebraic procedure num_elldc(k); 
   if impart k =0 and abs k>1 then
      RD(0,1-1/k^2,1)/(3*k^3)+
         i/k*(-RF(0,1/k^2,1)+(1-1/k^2)*RD(0,1/k^2,1)/3)
   else
      RD(0, 1-k^2, 1)/3;

% incomplete elliptic integral of the first kind

algebraic procedure n_elld(phi,k);
   if phi=0 then 0
   else if (k=1 or k=-1) and impart phi=0 and abs phi < pi/2 then
      sign(phi)*(log((1+s)/(1-s))/2-s) where s=> sin phi
   else if phi = pi/2 or phi = -pi/2 then sign(phi)*n_elldc(k)
   else begin scalar l;
      l := pi_shift phi;
      if second l neq 0 then
      	 return second(l)*n_elldc(k) + n_elld(first(l),k)
      else
	 return num_elliptic(num_elld, phi, k);
   end;

algebraic procedure num_elld(phi, k);
   begin scalar s, k2, arg, sgn;
      sgn := 1;
      if repart k <0 or (repart k =0 and impart k < 0) then
      	 k:= -k;
      if impart k = 0 and impart(phi)=0 then <<
      	 % |sin phi| <=1 and k  real
      	 if phi<0 then <<
	    phi := -phi;
	    sgn := -1;
      	 >>;
	 s := sin phi;
	 if k*s > 1 then <<  % one branch point  when k*sin theta =1
	    k2 := sqrt(1-1/k^2);
	    res := RD(0, 1-1/k^2, 1)/(3*k^3) - i*n_and(k*s,k2)/k;
	    arg := sqrt(k^2*s^2-1)/(k*s);
	    res := res +i*arg*sqrt(1-s^2)/k;
	    arg := arg/k2;
 	    res := res +i*k2^2*arg^3*RD(1-arg^2, 1-k2^2*arg^2,1)/(3*k);
	    return sgn*res;
	 >>
	 else % no branch points
	    return sgn*s^3*RD(1-s^2, 1-(k*s)^2, 1)/3;
      >>;

      if impart k = 0 and abs repart phi = pi/2 then <<
	 % sin phi real > 1
	 if repart phi < 0 then <<
	    phi := -phi;
	    sgn := -1;
	 >>;
	 s := cosh impart phi;
	 if k*s <=1 then << % k<1   one branch point (sin theta =1)
	    k2 := sqrt(1-k^2);
	    res := RD(0,1-k^2, 1)/3+i*(n_adn(k*s,k2)-RF(0, k^2, 1))/k^2;
	    arg := sqrt(1-k^2*s^2)/k2;
	    res := res -
	       i*k2^2*(arg^3*RD(1-arg^2,1-k2^2*arg^2,1)-RD(0,k^2,1))/(3*k^2);
	    return sgn*res;
	 >>
	 else if k<1 then << % two branch points sin theta =1,
	       % then k*sin theta =1
	       res := -i*(RF(0, k^2, 1)-(1-k^2)*RD(0, k^2, 1)/3)/k^2;
	       res := res -sqrt((s^2-1)*(k^2*s^2-1))/(k^2*s);
	       arg := 1/(k*s);
	       res := res+arg^3*RD(1-arg^2, 1-k^2*arg^2, 1)/3;
	       return sgn*res;
	 >>
	 else <<  % k > 1 so two branch points k* sin theta =1,
	       % then sin theta =1
	       res := i*((1-1/k^2)*RD(0, 1/k^2, 1)/3 - RF(0, 1/k^2, 1))/k;
	       res := res + RD(1-1/s^2, 1-1/(k*s)^2, 1)/(3*(k*s)^3);
	       res := res - sqrt((k^2*s^2-1)*(s^2-1))/(k^2*s);
	       return sgn *res;
	 >>;
      >>;

      if repart k=0 and repart phi=0 then <<
	 if impart phi<0 then <<
	    phi := -phi;
	    sgn := -1;
	 >>;
	 s := sinh impart phi;
	 k := impart k;

	 if k*s <= 1 then <<
	    k2 := 1/sqrt(1+k^2);
            res := n_acn(k*s, k2)-RF(0, 1-k2^2, 1);
            arg := sqrt(1-k^2*s^2);
	    res := res + (RD(0,1-k2^2,1)-arg^3*RD(1-arg^2,1-k2^2*arg^2,1))/3;
	    return sgn*i*k2*res/k^2;
	 >>;

	 % one branch point abs (k*sinh impart theta) = 1 
	 k2 := k/sqrt(k^2+1);
	 res := i*k2*(RD(0, k2^2, 1)/3-RF(0, k2^2, 1))/k^3;
	 arg := sqrt(k^2*s^2-1)/(k*s);
	 res := res -sqrt(s^2+1)*arg/k;
	 res := res + n_anc(k*s,k2)/sqrt(1+k^2);
	 res := res -arg^3*RD(1-arg^2,1-k2^2*arg^2,1)/(3*sqrt(1+k^2));
	 return sgn*res;
      >>;
	    
      if abs repart phi = pi/2 then <<
	 % one branch point when abs sin theta = 1
	 % sin phi real > 1.    k is not purely real here
	 if repart phi < 0 then <<
	    phi := -phi;
	    sgn := -1;
	 >>;
	 s := cosh impart phi;
	 k2 := sqrt(1-k^2);
	 res := RD(0,1-k^2, 1)/3+i*(n_adn(s,k2)-RF(0, k^2, 1))/k^2;
	    arg := sqrt(1-k^2*s^2)/k2;
	    res := res -
	       i*k2^2*(arg^3*RD(1-arg^2,1-k2^2*arg^2,1)-RD(0,k^2,1))/(3*k^2);
	    return sgn*res;
      >>;

      % phi is complex here
      sgn := 1;
      if repart phi < 0 then <<
	 phi := -phi;
	 sgn := -1;
      >>;
      s := sin phi;
      if impart (k*s) = 0 and abs repart(k*s) > 1 then <<
	 % one branch point when abs(k*sin theta) = 1
	    k2 := sqrt(1-1/k^2);
	    res := RD(0, 1-1/k^2, 1)/(3*k^3);
%%	    arg := sqrt(k^2*s^2-1)/(k*s);
%%	    res := res + i*arg*sqrt(1-s^2)/k - i*n_and(k*s,k2)/k;
%%	    arg := arg/k2;
%%	    res := res -i*k2^2*arg^3*RD(1-arg^2, 1-k2^2*arg^2,1)/(3*k);
            res := res +i*n_adn(ks, k2)/k;
	    arg := sqrt(k^2*s^2-1)/k2;
	    res := res -i*k2^2*arg^3*RD(1-arg^2,1-k2^2*arg^2,1)/(3*k);
	    return sgn*res;
      >>;
      return sgn*s^3*RD(1-s^2, 1-(k*s)^2, 1)/3;	 
   end;

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
% and EllipticE(u,k) (formerly called EllipticD(u,k)) numerically.
% This e_function has been renamed as je_function and the d_function
% renamed as e_function.

% operator jacobie;  % already defined in sfellip.red

% VALUE OF JacobiE(phi,m)

algebraic procedure num_jacobie(u,k);
   if u = 0 then 0
   else if k=0 then u
   else if k=1 or k =-1 then tanh u
   else num_jacobie1(u,k);

algebraic procedure num_jacobie1(u,k);
begin scalar tau, t3, xi, tmp;
   tau :=k2tau(k);
   t3 := num1_theta3(0,tau);
   xi := u/t3^2;
   tmp:= n_theta4d(xi,1,tau)/(num1_theta4(xi,tau)*t3^2);
   % tmp is the value of jacobizeta(u,k)
   return tmp + u*num_ellec(k)/num_ellk(k);
end;

jacobierules :=

   {
      % Jacobi's form of the incomplete elliptic integral of the second kind
        jacobie(0,~m)     => 0,
        jacobie(~phi,0)   => phi,
        jacobie(i*~phi,0) => i*phi,
        jacobie(~phi,1)   => tanh(phi),
        jacobie(i*~phi,1) => i*tan phi,
        jacobie(-~phi,~m) => -jacobie(phi,m),
        jacobie(~phi,-~m) =>  jacobie(phi,m),
	jacobie(elliptick(~m), ~m) => elliptice(m),

	
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

% derivative rules 
    df(jacobie(~phi,~m),~x) => df(phi,x)*jacobidn(phi,m)^2 +
            df(m,x)*(m*(jacobisn(phi,m)*jacobicn(phi,m)*jacobidn(phi,m)
                     - jacobie(phi,m)*jacobicn(phi,m)^2) / (1-m^2)
                     - m*phi*jacobisn(phi,m)^2),	

    df(elliptice(~m),~m) => (elliptice(m)-elliptick(m))/m,

    df(elliptick(~m),~m) => (elliptice(m)/(1-m^2)-elliptick(m))/m,

    df(elliptice!'(~m),~m) => m*(elliptick!'(m) - elliptice!'(m))/(1-m^2),

    df(elliptick!'(~m),~m) => (m*elliptick!'(m)-elliptice!'(m)/m)/(1-m^2),

% numerical evaluation

    jacobie(~phi,~m) => num_elliptic(num_jacobie,phi,m)
       when lisp  !*rounded and lisp !*complex and numberp phi and numberp m
}$

let jacobierules;


%######################################################################
%CALCULATING ZETA

% most agm based functions have been superceded except this one

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

algebraic procedure num_jacobizeta1(u,k);
   % alternative method using theta functions
begin scalar tau, t3, xi;
   tau :=k2tau(k);
   t3 := num1_theta3(0,tau);
   xi := u/t3^2;
   return n_theta4d(xi,1,tau)/(num1_theta4(xi,tau)*t3^2);
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%JacobiZETA definition
%=====================

% operator jacobizeta;

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
      
     jacobizeta(~u+2*elliptick(~m),m) => jacobizeta(u,m),
     jacobizeta(elliptick(~m) -~u,m) => -jacobizeta(elliptick(m)+u,m),

     jacobizeta(~u,~m) => num_elliptic(num_jacobizeta,u,m)
	   when lisp !*rounded and lisp !*complex and numberp u and numberp m,

%derivative rules
    df(jacobizeta(~u, ~k),~x) =>
	  df(jacobie(u,k)-u*ellipticE(k)/ellipticK(k),x)
 
}$
let jacobizetarules;

% Support for theta functions moved to a separate file (eftheta.red).

endmodule;
end;



