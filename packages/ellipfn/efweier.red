module efweier;  % Procedures and Rules for Weierstrass Elliptic functions.

% Author: Alan Barnes, February - March 2021

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

% $Id: sfweier.red 5874 2021-07-30 21:08:56Z arthurcnorman $
% Renamed (was sfweier) and moved to a new package ellipfn, December 2021
% by Alan Barnes


% See e.g.: DF Lawden, Elliptic Functions & Applications, Springer-Verlag
% (App Math Sci series #80) 1989

algebraic;

% WEIERSTRASS and SIGMA FUNCTIONS
operator weierstrass, weierstrassZeta;
operator weierstrass_sigma, weierstrass_sigma1;
operator weierstrass_sigma2, weierstrass_sigma3;
operator eta1, eta2, eta3;
operator lattice_e1, lattice_e2, lattice_e3;
operator lattice_g2, lattice_g3, lattice_delta, lattice_g;
operator lattice_omega1, lattice_omega3;
%######################################################################

sigma_rules :=
{
   weierstrass_sigma(0,~w1,~w3)  => 0,
   weierstrass_sigma1(~w1,~w1,~w3) => 0,
   weierstrass_sigma2(~w1+~w3,~w1,~w3) => 0,
   weierstrass_sigma3(~w3,~w1,~w3) => 0,

   weierstrass_sigma(-~u,~w1,~w3) => -weierstrass_sigma(u,w1,w3),  
   weierstrass_sigma1(-~u,~w1,~w3) => weierstrass_sigma1(u,w1,w3),  
   weierstrass_sigma2(-~u,~w1,~w3) => weierstrass_sigma2(u,w1,w3),  
   weierstrass_sigma3(-~u,~w1,~w3) => weierstrass_sigma3(u,w1,w3),

   weierstrass_sigma(~u,-~w1,-~w3)  => weierstrass_sigma(u,w1,w3),
   weierstrass_sigma1(~u,-~w1,-~w3) => weierstrass_sigma1(u,w1,w3),
   weierstrass_sigma2(~u,-~w1,-~w3) => weierstrass_sigma2(u,w1,w3),
   weierstrass_sigma3(~u,-~w1,-~w3) => weierstrass_sigma3(u,w1,w3),
   
   weierstrass_sigma1(0,~w1,~w3) => 1,
   weierstrass_sigma2(0,~w1,~w3) => 1,
   weierstrass_sigma3(0,~w1,~w3) => 1,

   weierstrass_sigma(~m*~u, ~m*~w1, ~m*~w3) => m*weierstrass_sigma(u, w1, w3)
             when numberp repart m and numberp impart m,
   weierstrass_sigma1(~m*~u, ~m*~w1, ~m*~w3) => weierstrass_sigma1(u, w1, w3)
             when numberp repart m and numberp impart m,
   weierstrass_sigma2(~m*~u, ~m*~w1, ~m*~w3) => weierstrass_sigma2(u, w1, w3)
             when numberp repart m and numberp impart m,
   weierstrass_sigma3(~m*~u, ~m*~w1, ~m*~w3) => weierstrass_sigma3(u, w1, w3)
             when numberp repart m and numberp impart m,

% quasi-periodicity

   weierstrass_sigma((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*weierstrass_sigma(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*weierstrass_sigma(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma1((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*weierstrass_sigma1(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma1((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         exp(2*m*eta3(w1,w3)*(arg+m*w3))*weierstrass_sigma1(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma2((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d)); 
       arg := u/d + (k/d-2*m)*w1;
       return
%         (-1)^m*exp(2*m*eta1(w1,w3)*(arg+m*w1))*weierstrass_sigma2(arg,w1,w3);
          exp(2*m*eta1(w1,w3)*(arg+m*w1))*weierstrass_sigma2(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma2((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
%         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*weierstrass_sigma2(arg,w1,w3); 
          exp(2*m*eta3(w1,w3)*(arg+m*w3))*weierstrass_sigma2(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma3((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w1;
       return
         exp(2*m*eta1(w1,w3)*(arg+m*w1))*weierstrass_sigma3(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   weierstrass_sigma3((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
    (begin scalar m, arg;
       m := fix repart(k/(2*d));
       arg := u/d + (k/d-2*m)*w3;
       return
         (-1)^m*exp(2*m*eta3(w1,w3)*(arg+m*w3))*weierstrass_sigma3(arg,w1,w3); 
     end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   df(weierstrass_sigma(~u,~w1,~w3),~u)  => weierstrass_sigma(u,w1,w3)*weierstrassZeta(u,w1,w3),

% Numerical evaluation
   weierstrass_sigma(~u,~w1,~w3) => n_sigma(num_sigma,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   weierstrass_sigma1(~u,~w1,~w3) => n_sigma(num_sigma1,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   weierstrass_sigma2(~u,~w1,~w3) => n_sigma(num_sigma2,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3,

   weierstrass_sigma3(~u,~w1,~w3) => n_sigma(num_sigma3,u,w1,w3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp w1 and numberp w3

}$
let sigma_rules;

weierstrass_rules :=
{
   weierstrass(-~u,~w1,~w3) => weierstrass(u,w1,w3),
   weierstrass(~u, -~w3, ~w1) => weierstrass(u,w1,w3),
%   weierstrass(~u,-~w1,-~w3)   => weierstrass(u,w1,w3),
   weierstrass(~m*~u, ~m*~w1, ~m*~w3) => weierstrass(u, w1, w3)/m^2
          when numberp repart m and numberp impart m,

   weierstrass(~w1, ~w1, ~w3)  => lattice_e1(w1,w3),
   weierstrass(~w3, ~w1, ~w3)  => lattice_e3(w1,w3),
   weierstrass(~w1+~w3, ~w1, ~w3) => lattice_e2(w1,w3),

   df(weierstrass(~u,~w1,~w3),u) =>
       -sqrt(4*weierstrass(u,w1,w3)^3
             - lattice_g2(w1,w3)*weierstrass(u,w1,w3) - lattice_g3(w1,w2)),

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
	        and numberp w1 and numberp w3,
		
   lattice_g2(~w1, ~w3) => n_lattice(num_g2,w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3,

   lattice_g3(~w1, ~w3) => n_lattice(num_g3,w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3,

   lattice_delta(~w1, ~w3) => n_lattice(num_delta,w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3,

   lattice_g(~w1, ~w3) => n_lattice(num_!G,w1,w3)
           when lisp !*rounded and lisp !*complex 
	        and numberp w1 and numberp w3
}$
let weierstrass_rules;

weierZeta_rules :=
{
   weierstrassZeta(-~u,~w1,~w3) => -weierstrassZeta(u,w1,w3),
   weierstrassZeta(~m*~u, ~m*~w1, ~m*~w3) => weierstrassZeta(u, w1, w3)/m
              when numberp repart m and numberp impart m,

   weierstrassZeta(~u,-~w1,~w3) => weierstrassZeta(u,w3,w1),
   weierstrassZeta(~w1,~w1,~w3) => eta1(w1,w3),
   weierstrassZeta(~w3,~w1,~w3) => eta3(w1,w3),
   weierstrassZeta(~w1+~w3,~w1,~w3) => eta1(w1,w3)+eta3(w1,w3),
   
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

operator weierstrass1, weierstrassZeta1;

weierstrass1_rules :=
{
   weierstrass1(-~u,~g2,~g3) => weierstrass1(u,g2,g3),
   weierstrasszeta1(-~u,~g2,~g3) => -weierstrasszeta1(u,g2,g3),
   weierstrass1(i*~u,~g2,~g3) => -weierstrass1(u,g2,-g3),
   weierstrassZeta1(i*~u,~g2,~g3) => -i*weierstrassZeta1(u,g2,-g3),

   weierstrass1(~m*~u,~g2,~g3) => weierstrass1(u, g2*m^4,g3*m^6)/m^2
           when numberp m,
   weierstrasszeta1(~m*~u,~g2,~g3) => weierstrasszeta1(u, g2*m^4,g3*m^6)/m
           when numberp m,

% Numerical evaluation
   weierstrass1(~u,~g2,~g3) => num_elliptic(num_weier1, u, g2, g3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp g2 and numberp g3,

   weierstrasszeta1(~u,~g2,~g3) => num_elliptic(num_weierZeta1, u, g2, g3)
           when lisp !*rounded and lisp !*complex and numberp u 
	        and numberp g2 and numberp g3,

   df(weierstrass1(~u,~g2,~g3),u) =>
       -sqrt(4*weierstrass1(u,g2,g3)^3 - g2*weierstrass1(u,g2,g3) - g3),

   df(weierstrassZeta1(~u,~g2,~g3),~u)  => -weierstrass1(u,g2,g3)
}$
let weierstrass1_rules;

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
begin scalar q, tau, l;
  l := fix_omegas(w1,w3);
  w1 := first l; tau := third l;
  q := exp(i*pi*tau);
  return (pi/w1)^2*(n_theta2(0,q,tau)^4+2*n_theta4(0,q)^4)/12;
end;

procedure num_e2(w1,w3);
begin scalar q, tau, l;
  l := fix_omegas(w1,w3);
  w1 := first l; tau := third l;
  q := exp(i*pi*tau);
  return (pi/w1)^2*(n_theta2(0,q,tau)^4-n_theta4(0,q)^4)/12;
end;

procedure num_e3(w1,w3);
begin scalar q, tau, l;
  l := fix_omegas(w1,w3);
  w1 := first l; tau := third l;
  q := exp(i*pi*tau);
  return -(pi/w1)^2*(2*n_theta2(0,q,tau)^4+n_theta4(0,q)^4)/12;
end;

procedure lattice_roots(w1,w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else begin scalar res, oldprec;
  oldprec := precision(0);
  precision max(oldprec+3, 15);
  res := l_roots(w1,w3);
  precision oldprec;   
  return res;
end;

procedure l_roots(w1,w3);
begin scalar q, tau, t2, t4, m, l; 
  l := fix_omegas(w1,w3);
  w1 := first l; tau := third l;
  q := exp(i*pi*tau);
  t2 := n_theta2(0,q,tau)^4;
  t4 := n_theta4(0,q)^4;
  m := (pi/w1)^2/12;
  return {m*(t2+2*t4), m*(t2-t4), -m*(2*t2+t4)};
end;

procedure lattice_invariants(w1,w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else begin scalar res, oldprec;
  oldprec := precision(0);
  precision max(oldprec+3, 15);
  res := l_invariants(w1,w3);
  precision oldprec;   
  return res;
end;

procedure l_invariants(w1,w3);
begin scalar l, g2, g3, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  g2 := 2*(e1^2+e2^2+e3^2);
  g3 := 4*e1*e2*e3;
  return {g2, g3, g2^3 - 27*g3^2,
          if g3 = 0 then infinity else g2^3/(27*g3^2)};
end;

procedure num_g2(w1,w3);
begin scalar l, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  return 2*(e1^2+e2^2+e3^2);
end;

procedure num_g3(w1,w3);
begin scalar l, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  g2 := 2*(e1^2+e2^2+e3^2);
  return 4*e1*e2*e3;
end;

procedure num_delta(w1,w3);
begin scalar l, g2, g3, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  g2 := 2*(e1^2+e2^2+e3^2);
  g3 := 4*e1*e2*e3;
  return g2^3 - 27*g3^2;
end;

procedure num_!G(w1,w3);
begin scalar l, g2, g3, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  g2 := 2*(e1^2+e2^2+e3^2);
  g3 := 4*e1*e2*e3;
  return if g3 = 0 then infinity else g2^3/(27*g3^2);
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
  if impart(tau) <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
  >>;
  return -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
end;

procedure num_eta2(w1,w3);
begin scalar tau, tmp;
  tau := w3/w1;
  if impart(tau) <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
  >>;
  return
    pi^2/(12*w1)*(1+tau)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)+pi*i/(2*w1);
end;

procedure num_eta3(w1,w3);
begin scalar tau, tmp;
  tau := w3/w1;
  if impart(tau) <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
  >>;
  return
    -pi^2/(12*w1)*tau*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)-pi*i/(2*w1);
end;

procedure quasi_period_factors(w1,w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else begin scalar res, oldprec;
  oldprec := precision(0);
  precision max(oldprec+3, 15);
  res := num_qpf(w1,w3);
  precision oldprec;   
  return res;
end;

procedure num_qpf(w1,w3);
begin scalar tmp, tau, tmp1; 
  tau := w3/w1;
  if impart(tau) <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
  >>;
  tmp := pi^2*n_theta1d(0,3,tau)/(12*w1*n_theta1d(0,1,tau));
  tmp1 := pi*i/(2*w1);
  return {-tmp, (1+tau)*tmp + tmp1, -tau*tmp -tmp1};
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

% ******* It is not clear to me why the commented-out procedures num_sigma1
% ******* and num_sigma3 fail to return correct results in SOME cases when
% ******* a modular transformation has been used to optimise convergence.
% ******* weierstrass_sigma1 seems to return the result for weierstrass_sigma3 and vice-versa.
% ******* They have been replaced by alternative procedures which
% ******* do not optimise tau before calculating the eta values.
% ******* This leads to some small imaginary parts when they should be zero.

procedure num_sigma1(u,w1,w3);
begin scalar tau, et1, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
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

% procedure num_sigma2(u,w1,w3);
% begin scalar tau, et2, w2, tmp;
%   tau := w3/w1;
%   if impart(tau)<0 then <<
%     tmp := w1; w1 := w3;
%     w3 := tmp; tau := 1/tau;
%   >>;
%   w2 := -w1-w3;
%   et2:= pi^2/(12*w1)*(1+tau)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau)+pi*i/(2*w1);
%   return exp(-et2*u)*num_sigma(u+w2,w1,w3)/num_sigma(w2,w1,w3);
% end;

procedure num_sigma2(u,w1,w3);
begin scalar q, tau, n1, n3, et1, et3, m, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u, w1, tau);
  u := first l;
  n3 := second l;
  n1 := third l;
  q := exp(i*pi*tau);
  et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
  et3 := et1*tau-pi*i/(2*w1);
%  m := (-1)^(n1+n3+n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
  m := (-1)^(n1*n3)*exp((2*n3*et3+2*n1*et1)*(u+n1*w1+n3*w3));
  return m*exp(et1*u^2/(2*w1))*n_theta3(pi*u/(2*w1),q)/n_theta3(0,q);
end;

procedure num_sigma3(u,w1,w3);
begin scalar tau, et3, tmp;
  tau := w3/w1;
  if impart(tau)<0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
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
  tau := w3/w1;
  if impart tau <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
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

%##################################################################
% Alternative forms of the Weierstrass functions

procedure lattice_generators(g2,g3);
begin scalar res, oldprec;
  if g2^3-27*g3^2 = 0 then
    rederr("The discriminant of the invariants is zero.");

  oldprec := precision(0);
  precision max(oldprec+3, 15);
  res := num_omegas(g2,g3);
  precision oldprec;   
  return res;
end;

% For details of the algorithm used to calculate the lattice generators from the
% invariants see the DLMF:NIST chapter 23.22(ii) on Lattice Calculations.
% {https://dlmf.nist.gov/23.22#ii}}.

procedure num_omegas(g2,g3);
begin scalar l, kk, kk1, m;
   if g2 = 0 then <<
       m := gamma(1/3)^3/(4*pi*g3^(1/6));
       return {m, m*(1+i*sqrt 3)/2};
   >>;
   if g3 = 0 then <<
       m := gamma(1/4)^2/(4*sqrt(pi)*g2^(1/4));
       return {m, i*m};
   >>;
   l := solve(4*(!*x!*)^3 - g2*(!*x!*) -g3 = 0, !*x!*);
   l := foreach elem in l collect rhs elem;
   if impart first l=0 and impart second l=0 and impart third l=0
   then
      l := real!-roots(l)
   else
      l := complex!-roots(l);
   k := first l; k1 := second l;

   kk1 := agm_basic(1, sqrt k1);  % ellipticK(k')
   kk := agm_basic(1, sqrt k);  % ellipticK(k)
   m := pi/6*sqrt(g2*(2+k*k1)*(k1-k)/(g3*(1-k*k1)));
   return {m/kk1, i*m/kk};

% alternative method replacing last two lines above
%   m := i*kk1/kk;
%   l1:= (num_g2(1,m)/g2)^(1/4);
%   return {l1, l1*m}; 
end;

procedure complex!-roots(l);
begin scalar l1, n, det, k, k1, tmp;
   l := {second l - first l, third l - second l, first l - third l};
   det :=
     repart first l*impart second l-repart second l*impart first l;
   if det < 0 then % if root triangle is negatively-oriented
      l := {-first l, -second l, -third l};
   l1 := {abs(first l), abs(second l), abs(third l)};
   n:=1;
   if first l1 < second l1 then n := 2;
   if part(l1, n) < third l1 then n := 3;
   
   if n=1 then <<k := -third l, k1 := -second l>>
   else if n=2 then  <<k := -first l, k1 := -third l>>
   else  <<k := -second l, k1 := -first l>>;
   k:=k/part(l,n); k1 := k1/part(l,n);  %  k^2 & k'^2 respectively
   
   if impart k<0 then  % probably redundant
      << tmp := k1, k1:=k; k:=tmp>>;
   return {k,k1};
end;

procedure real!-roots(l);
begin scalar e1, e2, e3, k, k1;
   e1:= max l; e3 := min l;  e2 := -e1-e3;
   %  k^2 & k'^2 respectively
   k:= (e2-e3)/(e1-e3); k1 := (e1-e2)/(e1-e3);  
   return {k,k1};
end;

procedure num_weier1(u,g2,g3);
begin scalar l;
  if g2^3-27*g3^2=0 then
    rederr("num_weier: discriminant of the Weierstrass function is zero.");
  l := num_omegas(g2,g3);
  return num_weier(u, first l, second l); 
end;

procedure num_weierZeta1(u,g2,g3);
begin scalar l;
  if g2^3-27*g3^2=0 then
    rederr("num_weier: discriminant of the Weierstrass function is zero.");
  l := num_omegas(g2,g3);
  return num_weierZeta(u, first l, second l); 
end;

% moved to efnumeric.red by AB, Feb 2022.
%% procedure agm_basic(a0, b0);
%% begin scalar an, bn, cn, tol;
%%    tol := 10.0^-(symbolic !:prec!:);
%%    repeat <<
%%       an := (a0 + b0)/2;
%%       bn := sqrt(a0*b0);
%%       cn := (a0 - b0)/2;
%%       a0 := an;
%%       b0 := bn
%%    >> until cn < tol;
%%    return an;
%% end;

%######################################################################

put('weierstrass1, 'fancy!-functionsymbol, "\wp");
put('weierstrassZeta1, 'fancy!-functionsymbol, "\zeta_w");
put('weierstrass1, 'fancy!-prifn, 'fancy!-weier);
put('weierstrassZeta1, 'fancy!-prifn, 'fancy!-weier);
put('WeierstrassZeta1, 'fancy!-symbol!-length, 4);

put('weierstrass1, 'plain!-functionsymbol, "P_w");
put('weierstrasszZeta1, 'plain!-functionsymbol, "zeta_w");
put('weierstrass1, 'prifn, 'plain!-weier);
put('weierstrassZeta1, 'prifn, 'plain!-weier);

put('weierstrass, 'fancy!-functionsymbol, "\wp");
put('weierstrassZeta, 'fancy!-functionsymbol,"\zeta_w");
put('weierstrass_sigma, 'fancy!-functionsymbol,"\sigma");
put('weierstrass_sigma1, 'fancy!-functionsymbol,"\sigma_1");
put('weierstrass_sigma2, 'fancy!-functionsymbol,"\sigma_2");
put('weierstrass_sigma3, 'fancy!-functionsymbol,"\sigma_3");
put('eta1, 'fancy!-functionsymbol,"\eta_1");
put('eta2, 'fancy!-functionsymbol,"\eta_2");
put('eta3, 'fancy!-functionsymbol,"\eta_3");
put('weierstrassZeta, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma1, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma2, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma3, 'fancy!-symbol!-length, 4);
put('eta1, 'fancy!-symbol!-length, 4);
put('eta2, 'fancy!-symbol!-length, 4);
put('eta3, 'fancy!-symbol!-length, 4);

put('lattice_e1, 'fancy!-functionsymbol,"\mathrm{e_1}");
put('lattice_e2, 'fancy!-functionsymbol,"\mathrm{e_2}");
put('lattice_e3, 'fancy!-functionsymbol,"\mathrm{e_3}");
put('lattice_e1, 'fancy!-symbol!-length, 4);
put('lattice_e2, 'fancy!-symbol!-length, 4);
put('lattice_e3, 'fancy!-symbol!-length, 4);

put('weierstrass, 'prifn, 'plain!-symbol);
put('weierstrassZeta, 'prifn, 'plain!-symbol);
put('weierstrass, 'plain!-functionsymbol, "P_w");
put('weierstrasszeta, 'plain!-functionsymbol, 'zeta_w);

put('lattice_e1, 'prifn, 'plain!-symbol);
put('lattice_e1, 'plain!-functionsymbol, 'e1);
put('lattice_e2, 'prifn, 'plain!-symbol);
put('lattice_e2, 'plain!-functionsymbol, 'e2);
put('lattice_e3, 'prifn, 'plain!-symbol);
put('lattice_e3, 'plain!-functionsymbol, 'e3);

put('lattice_g2, 'fancy!-functionsymbol,"\mathrm{g_2}");
put('lattice_g3, 'fancy!-functionsymbol,"\mathrm{g_3}");
put('lattice_delta, 'fancy!-functionsymbol, "\Delta");
put('lattice_g, 'fancy!-functionsymbol, "\mathrm{G}");
put('lattice_g2, 'fancy!-symbol!-length, 4);
put('lattice_g3, 'fancy!-symbol!-length, 4);
put('lattice_omega1, 'fancy!-functionsymbol, "\omega_1");
put('lattice_omega3, 'fancy!-functionsymbol, "\omega_3");
put('lattice_omega1, 'fancy!-symbol!-length, 4);
put('lattice_omega3, 'fancy!-symbol!-length, 4);

put('lattice_g2, 'prifn, 'plain!-symbol);
put('lattic_g2, 'plain!-functionsymbol, 'g2);
put('lattice_g3, 'prifn, 'plain!-symbol);
put('lattice_g3, 'plain!-functionsymbol, 'g3);
put('lattice_delta, 'plain!-functionsymbol, '!Delta);
put('lattice_delta, 'prifn, 'plain!-symbol);
put('lattice_g, 'plain!-functionsymbol, '!G);
put('lattice_g, 'prifn, 'plain!-symbol);

put('lattice_omega1, 'prifn, 'plain!-symbol);
put('lattice_omega1, 'plain!-functionsymbol, 'w1);
put('lattice_omega3, 'prifn, 'plain!-symbol);
put('lattice_omega3, 'plain!-functionsymbol, 'w3);

% The next 2 declarations enable better checking of the number
% of arguments by simpiden

flag('(weierstrass_sigma weierstrass_sigma1 weierstrass_sigma2
       weierstrass_sigma3 weierstrass weierstrassZeta
       eta1 eta2 eta3 lattice_e1 lattice_e2 lattice_e3 
       lattice_g2 lattice_g3  lattice_delta lattice_g
       lattice_omega1 lattice_omega3 weierstrass1 weierstrasszeta1
      ), 'specfn);


deflist('((weierstrass_sigma 3) (weierstrass_sigma1 3)
          (weierstrass_sigma2 3) (weierstrass_sigma3 3)
          (weierstrass 3) (weierstrassZeta 3) (eta1 2) (eta2 2)
	  (eta3 2) (lattice_e1 2) (lattice_e3 2) (lattice_e3 2)
	  (lattice_roots 2) (lattice_invariants 2) 
	  (lattice_g2 2) (lattice_g3 2)  (lattice_delta 2) (lattice_g 2)
	  (weierstrass1 3) (weierstrassZeta1 3)
	  (lattice_generators 2) (quasi_period_factors 2)
	  (lattice_omega1 2) (lattice_omega3 2)
        ), 'number!-of!-args);

fluid '(fancy!-pos!* fancy!-texpos fancy!-line!*);

symbolic procedure fancy!-weier u;
 fancy!-level
  begin scalar args;
   fancy!-prefix!-operator car u;
   args := {cadr u, '!|, caddr u, '!,, cadddr u};
   return fancy!-in!-brackets(
               {'fancy!-inprint, mkquote 'times, 1,  mkquote args},
	         '!(, '!));
  end;

symbolic procedure plain!-weier(u);
begin;
    prin2!*(get(car u,'plain!-functionsymbol));
    prin2!* "(";
    maprin cadr u;
    prin2!* "|";
    maprin caddr u;
    prin2!* ",";
    maprin cadddr u;
    prin2!* ")";
    return u;
end;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% The following are needed to support power series expansions of
% Weierstrass functions about their (double) poles. The two operators
% RW!* and RW1!* are the reciprocals of weierstrassZeta & weierstrassZeta1
% respectively. They are not really intended for use at top level.

operator RW!*, RW1!*;

weier!-recip!-rules := {
  df(RW!*(~x, ~w1, ~w3), x) =>
      sqrt(4 RW!*(x,w1, w3) -
          lattice_g2(w1,w3)*RW!*(x,w1,w3)^3 -lattice_g3(w1,w3)*RW!*(x,w1,w3)^4),

  df(RW1!*(~x, ~g2, ~g3), x) =>
      sqrt(4 RW1!*(x, g2, g3) -
            g2 * *RW1!*(x, g2, g3)^3 - g3 * *RW1!*(x, g2, g3)^4),

  RW!*(0,~w1,~w3) => 0,
  RW1!*(0,~g2,~g3) => 0,
  RW!*(-~u,~w1,~w3) => RW!*(u,w1,w3),
  RW1!*(-~u,~w1,~w3) => RW1!*(u,w1,w3),

  RW!*((~~u + ~k*~w1)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w1;
         return RW!*(arg, w1, w3); 
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   RW!*((~~u + ~k*~w3)/~~d, ~w1, ~w3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*w3;
         return RW!*(arg, w1, w3);
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),


  RW1!*((~~u + ~k*lattice_omega1(~g2,~g3))/~~d, ~g2, ~g3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*lattice_omega1(g2,g3);
         return RW1!*(arg, g2, g3); 
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d)),

   RW1!*((~~u + ~k*lattice_omega3(~g2,~g3))/~~d, ~g2, ~g3) =>
      (begin scalar m, arg;
         m := fix repart(k/(2*d));
	 arg := u/d + (k/d-2*m)*lattice_omega3(g2,g3);
         return RW1!*(arg, g2, g3); 
      end)
      when ((ratnump(rp) and abs(rp) >= 2) where rp => repart(k/d))
  
}$
let weier!-recip!-rules$

endmodule;
end;
