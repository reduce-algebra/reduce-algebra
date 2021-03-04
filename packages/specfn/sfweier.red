module sfweier;  % Procedures and Rules for Weierstrass Elliptic functions.

% Author: Alan Barnes, February 2021

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

% See e.g.: DF Lawden, Elliptic Functions & Applications, Springer-Verlag
% (App Math Sci series #80) 1989

algebraic;

% WEIERSTRASS and SIGMA FUNCTIONS
operator weierstrass;
operator weierstrassZeta;
operator sigma, sigma1, sigma2, sigma3;
operator eta1, eta2, eta3, lattice_e1, lattice_e2, lattice_e3;
%######################################################################

sigma_rules :=
{
   sigma(0,~w1,~w3)  => 0,
   sigma1(~w1,~w1,~w3) => 0,
   sigma2(~w1+~w3,~w1,~w3) => 0,
   sigma3(~w3,~w1,~w3) => 0,

   sigma(-~u,~w1,~w3) => -sigma(u,w1,w3),  
   sigma1(-~u,~w1,~w3) => sigma1(u,w1,w3),  
   sigma2(-~u,~w1,~w3) => sigma2(u,w1,w3),  
   sigma3(-~u,~w1,~w3) => sigma3(u,w1,w3),

   sigma(~u,-~w1,-~w3)  => sigma(u,w1,w3),
   sigma1(~u,-~w1,-~w3) => sigma1(u,w1,w3),
   sigma2(~u,-~w1,-~w3) => sigma2(u,w1,w3),
   sigma3(~u,-~w1,-~w3) => sigma3(u,w1,w3),
   
   sigma1(0,~w1,~w3) => 1,
   sigma2(0,~w1,~w3) => 1,
   sigma3(0,~w1,~w3) => 1,

   sigma(~m*~u, ~m*~w1, ~m*~w3) => m*sigma(u, w1, w3)
             when numberp repart m and numberp impart m,
   sigma1(~m*~u, ~m*~w1, ~m*~w3) => sigma1(u, w1, w3)
             when numberp repart m and numberp impart m,
   sigma2(~m*~u, ~m*~w1, ~m*~w3) => sigma2(u, w1, w3)
             when numberp repart m and numberp impart m,
   sigma3(~m*~u, ~m*~w1, ~m*~w3) => sigma3(u, w1, w3)
             when numberp repart m and numberp impart m,

% quasi-periodicity

   sigma((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*sigma(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*sigma(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma1((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*sigma1(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma1((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         exp(2*m*eta3(w1,w3)*(arg+m*w3))*sigma1(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma2((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d)); 
       arg := u/d + (k/d-2*m)*w1;
       return
%         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*sigma2(arg,w1,w3);
          exp(2*m*eta1(w1,w3)*(arg+m*w1))*sigma2(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma2((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
%         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*sigma2(arg,w1,w3); 
          exp(2*m*eta3(w1,w3)*(arg+m*w3))*sigma2(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma3((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         exp(2*m*eta1(w1,w3)*(arg+m*w1))*sigma3(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   sigma3((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*sigma3(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   df(sigma(~u,~w1,~w3),~u)  => sigma(u,w1,w3)*weierstrassZeta(u,w1,w3),

% Numerical evaluation
   sigma(~u,~w1,~w3) => n_sigma(num_sigma,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   sigma1(~u,~w1,~w3) => n_sigma(num_sigma1,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   sigma2(~u,~w1,~w3) => n_sigma(num_sigma2,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   sigma3(~u,~w1,~w3) => n_sigma(num_sigma3,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3

}$
let sigma_rules;

weierstrass_rules :=
{
   weierstrass(-~u,~w1,~w3) => weierstrass(u,w1,w3),
   weierstrass(~m*~u, ~m*~w1, ~m*~w3) => weierstrass(u, w1, w3)/m^2
          when numberp repart m and numberp impart m,

   weierstrass(~u,-~w1,-~w3)   => weierstrass(u,w1,w3),
   weierstrass(~w1, ~w1, ~w3)  => lattice_e1(w1,w3),
   weierstrass(~w3, ~w1, ~w3)  => lattice_e3(w1,w3),
   weierstrass(~w1+~w3, ~w1, ~w3) => lattice_e2(w1,w3),
   
   % double periodicity
   weierstrass((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w1;
         return weierstrass(arg,w1,w3); 
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w3;
         return weierstrass(arg,w1,w3);
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

% Numerical evaluation
   weierstrass(~u,~w1,~w3) => n_sigma(num_weier,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   lattice_e1(~w1, ~w3) => n_lattice(num_e1, w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3,

   lattice_e2(~w1, ~w3) => n_lattice(num_e2, w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3,

   lattice_e3(~w1, ~w3) => n_lattice(num_e3, w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3
}$
let weierstrass_rules;


weierZeta_rules :=
{
   weierstrassZeta(-~u,~w1,~w3) => -weierstrassZeta(u,w1,w3),
   weierstrassZeta(~m*~u, ~m*~w1, ~m*~w3) => weierstrassZeta(u, w1, w3)/m
              when numberp repart m and numberp impart m,

   weierstrassZeta(~u,-~w1,-~w3) => weierstrassZeta(u,w1,w3),
   weierstrassZeta(~w1,~w1,~w3) => eta1(w1,w3),
   weierstrassZeta(~w3,~w1,~w3) => eta3(w1,w3),

   df(weierstrassZeta(~u,~w1,~w3),~u)  => -weierstrass(u,w1,w3),

 % quasi-periodicity
   weierstrassZeta((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w1;
         return weierstrassZeta(arg,w1,w3)+2*m*eta1(w1,w3); 
	end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),
      
   weierstrassZeta((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w3;
         return weierstrassZeta(arg,w1,w3)+2*m*eta3(w1,w3); 
	end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

% Numerical evaluation
   weierstrassZeta(~u,~w1,~w3) => n_sigma(num_weierZeta,u,w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp u and numberp w1 and numberp w3,
		
   eta1(~w1,~w3) => n_lattice(num_eta1,w1,w3)
           when lisp !*rounded and lisp !*complex
  	         and numberp w1 and numberp w3,

   eta2(~w1,~w3) => n_lattice(num_eta2,w1,w3)
           when lisp !*rounded and lisp !*complex
  	         and numberp w1 and numberp w3,

   eta3(~w1,~w3) => n_lattice(num_eta3,w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3
}$
let weierZeta_rules;

% The next 2 functions detect the erroneous case of tau being real, before
% calling num_elliptic -- this ensures the precision doesn't creep upwards
% in case of error.

procedure n_sigma(f, u, w1, w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of Weierstrass functions must be complex")
else num_elliptic(f,u,w1,w3);

procedure n_lattice(f, w1, w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else num_elliptic(f,w1,w3);


procedure num_weier(u,w1,w3);
begin scalar q, tau, t2, t4, e2, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u,w1, tau);
  u := first l;
  if u = 0 then rederr("Weierstrass has poles at lattice points");
  n3 := second l;
  n1 := third l;
  q := exp(i*pi*tau);
  t2 :=  n_theta2(0,q,tau);
  t4 :=  n_theta4(0,q);
  e2 := pi^2*(t2^4-t4^4)/(12*w1^2);
  u := pi*u/(2*w1);
  return e2 + (pi*t2*t4*n_theta3(u,q)/(2*w1*n_theta1(u,q,tau)))^2;
end;

% Lattice roots
procedure num_e1(w1,w3);
begin scalar q, tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  q := exp(i*pi*tau);
  return (pi/w1)^2*(n_theta2(0,q,tau)^4+2*n_theta4(0,q)^4)/12;
end;

procedure num_e2(w1,w3);
begin scalar q, tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  q := exp(i*pi*tau);
  return (pi/w1)^2*(n_theta2(0,q,tau)^4-n_theta4(0,q)^4)/12;
end;

procedure num_e3(w1,w3);
begin scalar q, tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  q := exp(i*pi*tau);
  return -(pi/w1)^2*(2*n_theta2(0,q,tau)^4+n_theta4(0,q)^4)/12;
end;

procedure num_weierZeta(u,w1,w3);
begin scalar q, tau, n1, n3, et1, et3, z, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u,w1, tau);
  u := first l;
  if u = 0 then rederr("WeierstrassZeta has poles at lattice points");
  n3 := second l;
  n1 := third l;
  q := exp(i*pi*tau);
  et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
  et3 := et1*tau-pi*i/(2*w1);
  z := pi*u/(2*w1);
  return et1*u/w1 + pi/(2*w1)*n_theta1d(z,1,tau)/n_theta1(z,q,tau)
           + 2*n3*et3 + 2*n1*et1;
end;

procedure num_eta1(w1,w3);
begin scalar tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  return -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
end;

procedure num_eta2(w1,w3);
begin scalar tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  return
    pi^2/(12*w1)*(1+tau)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)+pi*i/(2*w1);
end;

procedure num_eta3(w1,w3);
begin scalar tau, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  return
    -pi^2/(12*w1)*tau*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)-pi*i/(2*w1);
end;

procedure num_sigma(u,w1,w3);
begin scalar q, tau, n1, n3, et1, et3, td1, m, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u, w1, tau);
  u := first l;
  n3 := second l;
  n1 := third l;
  q := exp(i*pi*tau);
  td1 :=  n_theta1d(0,1,tau);
  et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/td1;
  et3 := et1*tau-pi*i/(2*w1);
  m := (-1)^(n1+n3+n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
  return 2*m*w1*exp(et1*u^2/(2*w1))*n_theta1(pi*u/(2*w1),q,tau)/(td1*pi);
end;

% ******* It is not clear to me why the next three commented out procedures
% ******* fail to return correct results in SOME cases when a modular
% ******* transformation has been used to optimise convergence.
% ******* sigma1 seems to return the result for sigma3 and vice-versa.
% ******* They have been replaced by alternative procedures which
% ******* do not optimise tau before calculating the eta values.

procedure  num_sigma1(u,w1,w3);
begin scalar l, tau, et1, tmp;
  tau :=w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
  return exp(-et1*u)*num_sigma(u+w1,w1,w3)/num_sigma(w1,w1,w3);
end;

% procedure num_sigma1(u,w1,w3);
% begin scalar q, tau, n1, n3, et1, et3, m, l;
%   l := fix_omegas(w1,w3);
%   w1 := first l;
%   w3 := second l;
%   tau := third l;
%   l := fix_arg(u, w1, tau);
%   u := first l;
%   n3 := second l;
%   n1 := third l;
%   q := exp(i*pi*tau);
%   et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
%   et3 := et1*tau-pi*i/(2*w1);
%   m := (-1)^(n1+n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
%   return m*exp(et1*u^2/(2*w1))*n_theta2(pi*u/(2*w1),q,tau)/n_theta2(0,q,tau);
% end;

procedure  num_sigma2(u,w1,w3);
begin scalar l, tau, et2, w2, tmp;
  tau :=w3/w1;
  if impart(tau)<0 then <<
    tmp := w1; w1 := w3;
    w3 := w1; tau := 1/tau
 >>;   
  w2 := -w1-w3;
  et2:= pi^2/(12*w1)*(1+tau)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)+pi*i/(2*w1);
  return exp(-et2*u)*num_sigma(u+w2,w1,w3)/num_sigma(w2,w1,w3);
end;

% procedure num_sigma2(u,w1,w3);
% begin scalar q, tau, n1, n3, et1, et3, m, l;
%   l := fix_omegas(w1,w3);
%   w1 := first l;
%   w3 := second l;
%   tau := third l;
%   l := fix_arg(u, w1, tau);
%   u := first l;
%   n3 := second l;
%   n1 := third l;
%   q := exp(i*pi*tau);
%   et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
%   et3 := et1*tau-pi*i/(2*w1);
% %  m := (-1)^(n1+n3+n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
%   m := (-1)^(n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
%   return m*exp(et1*u^2/(2*w1))*n_theta3(pi*u/(2*w1),q)/n_theta3(0,q);
% end;
% 

procedure  num_sigma3(u,w1,w3);
begin scalar l, tau, et3, tmp;
  tau :=w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := w1; tau := 1/tau
  >>;   
  et3 := -pi^2/(12*w1)*tau*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)-pi*i/(2*w1);
  return exp(-et3*u)*num_sigma(u+w3,w1,w3)/num_sigma(w3,w1,w3);
end;

% procedure num_sigma3(u,w1,w3);
% begin scalar q, tau, n1, n3, et1, et3,  m, l;
%   l := fix_omegas(w1,w3);
%   w1 := first l;
%   w3 := second l;
%   tau := third l;
%   l := fix_arg(u, w1, tau);
%   u := first l;
%   n3 := second l;
%   n1 := third l;
%   q := exp(i*pi*tau);
%   et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
%   et3 := et1*tau-pi*i/(2*w1);
%   m := (-1)^(n3+n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
%   return m*exp(et1*u^2/(2*w1))*n_theta4(pi*u/(2*w1),q)/n_theta4(0,q);
% end;

procedure fix_omegas(w1,w3);
begin scalar tmp, tau, m;
  tau:= w3/w1;
  if impart tau <0 then <<
     tmp := w1; w1 := w3;  w3 := tmp;
     tau := 1/tau;
  >>;
  while impart tau < 0.7 do <<
     m := round repart tau;
     tau := tau - m;
     w3 := w3-m*w1;
     tau := -1/tau;
     tmp := -w1; w1 := w3;  w3 := tmp;
  >>;
  return {w1, w3, tau};
end;

procedure fix_arg(u, w1, tau);
% shift the argument down into the base period parallelogram
begin scalar z, p1, rp1, nump1, nump2;
  z := u/(2*w1);
  rp1 := impart tau;
  nump1 := round(impart(z)/rp1);  % number of periods used
  z := z - nump1*tau;
  nump2 := round repart z;   % number of real periods used
  z := z - nump2;
  return {2*z*w1, nump1, nump2};
end;


%######################################################################

put('weierstrass, 'fancy!-functionsymbol, "P_w");
put('weierstrassZeta, 'fancy!-functionsymbol,"\zeta_w");
put('sigma, 'fancy!-functionsymbol,"\sigma");
put('sigma1, 'fancy!-functionsymbol,"\sigma_1");
put('sigma2, 'fancy!-functionsymbol,"\sigma_2");
put('sigma3, 'fancy!-functionsymbol,"\sigma_3");
put('eta1, 'fancy!-functionsymbol,"\eta_1");
put('eta2, 'fancy!-functionsymbol,"\eta_2");
put('eta3, 'fancy!-functionsymbol,"\eta_3");
put('Weierstrass, 'fancy!-symbol!-length, 4);
put('WeierstrassZeta, 'fancy!-symbol!-length, 4);
put('sigma1, 'fancy!-symbol!-length, 4);
put('sigma2, 'fancy!-symbol!-length, 4);
put('sigma3, 'fancy!-symbol!-length, 4);
put('eta1, 'fancy!-symbol!-length, 4);
put('eta2, 'fancy!-symbol!-length, 4);
put('eta3, 'fancy!-symbol!-length, 4);

put('lattic_e1, 'fancy!-functionsymbol,"e_1");
put('lattic_e2, 'fancy!-functionsymbol,"e_2");
put('lattic_e3, 'fancy!-functionsymbol,"e_3");
put('lattic_e1, 'fancy!-symbol!-length, 4);
put('lattic_e2, 'fancy!-symbol!-length, 4);
put('lattic_e3, 'fancy!-symbol!-length, 4);

put('lattic_e1, 'prifn, 'plain!-symbol);
put('lattic_e1, 'plain!-functionsymbol, 'e1);
put('lattic_e2, 'prifn, 'plain!-symbol);
put('lattic_e2, 'plain!-functionsymbol, 'e2);
put('lattic_e3, 'prifn, 'plain!-symbol);
put('lattic_e3, 'plain!-functionsymbol, 'e3);


% The next 2 declarations enable better checking of the number
% of arguments by simpiden

flag('(sigma sigma1 sigma2 sigma3 weierstrass weierstrassZeta
       eta1 eta2 eta3 lattice_e1 lattice_e2 lattice_e2),
       'specfn);

deflist('((sigma 3) (sigma1 3) (sigma2 3) (sigma3 3)
          (weierstrass 3) (weierstrassZeta 3) (eta1 2) (eta2 2)
	  (eta3 2) (lattice_e1 2) (lattice_e3 2) (lattice_e3 2)
        ), 'number!-of!-args);

endmodule;
end;
