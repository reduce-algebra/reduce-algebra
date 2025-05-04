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
operator weierstrass, weierstrassZeta, epsilon_w;
operator weierstrass_sigma, weierstrass_sigma1;
operator weierstrass_sigma2, weierstrass_sigma3;
operator eta1, eta2, eta3;
operator lattice_e1, lattice_e2, lattice_e3;
operator lattice_g2, lattice_g3, lattice_delta, lattice_g;
operator lattice_omega1, lattice_omega2, lattice_omega3;
operator weierstrass1, weierstrassZeta1, weierstrass_sigma0;
operator lattice1_e1, lattice1_e2, lattice1_e3, epsilon_w1;

flag ('(weierstrass1 weierstrassZeta1 weierstrass_sigma0), 'realvalued);
flag ('(epsilon_w epsilon_w1), 'alwaysrealvalued);
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

   epsilon_w(~u, ~w1, ~w3)^2 => 1,
   df(epsilon_w(~u, ~w1, ~w3), u) => 0,

   % epsilon_w = +/-1 and changes sign at poles of the Weierstrass fn and
   % at when Weierstrass fn is equal to a lattice-root e_1, e_2 or e_3
   % i.e. when u = omega1, omega2 or omega3 where its derivative is zero.     
  df(weierstrass(~u,~w1,~w3),u) =>
      epsilon_w(u,w1,w3)*sqrt(4*weierstrass(u,w1,w3)^3
             - lattice_g2(w1,w3)*weierstrass(u,w1,w3) - lattice_g3(w1,w3)),

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

   sqrt(4*lattice_e1(~w1,~w3)^3 - lattice_g2(w1,w3)*lattice_e1(w1,w3)
   	    - lattice_g3(w1,w3)) => 0,

   sqrt(4*lattice_e2(~w1,~w3)^3 - lattice_g2(w1,w3)*lattice_e2(w1,w3)
   	    - lattice_g3(w1,w3)) => 0,

   sqrt(4*lattice_e3(~w1,~w3)^3 - lattice_g2(w1,w3)*lattice_e3(w1,w3)
   	    - lattice_g3(w1,w3)) => 0,

% Numerical evaluation
   weierstrass(~u,~w1,~w3) => n_sigma(num_weier,u,w1,w3)
      when lisp !*rounded and lisp !*complex and numberp u
	   and numberp w1 and numberp w3,

      lattice_e1(~w1, ~w3) => first lattice_roots(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_e2(~w1, ~w3) => second lattice_roots(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_e3(~w1, ~w3) => third lattice_roots(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_g2(~w1, ~w3) => first lattice_invariants(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_g3(~w1, ~w3) => second lattice_invariants(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_delta(~w1, ~w3) => third lattice_invariants(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3,

   lattice_g(~w1, ~w3) => third rest lattice_invariants(w1,w3)
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
      when lisp !*rounded and lisp !*complex and numberp u
 	   and numberp w1 and numberp w3,

  eta1(~w1,~w3) => first quasi_period_factors(w1,w3)
           when lisp !*rounded and lisp !*complex
  	         and numberp w1 and numberp w3,

   eta2(~w1,~w3) => second quasi_period_factors(w1,w3)
           when lisp !*rounded and lisp !*complex
  	         and numberp w1 and numberp w3,

   eta3(~w1,~w3) => third quasi_period_factors(w1,w3)
           when lisp !*rounded and lisp !*complex
	        and numberp w1 and numberp w3
}$
let weierZeta_rules;


weierstrass1_rules :=
{
   weierstrass1(-~u,~g2,~g3) => weierstrass1(u,g2,g3),
   weierstrasszeta1(-~u,~g2,~g3) => -weierstrasszeta1(u,g2,g3),
   weierstrass_sigma0(-~u,~g2,~g3) => -weierstrass_sigma0(u,g2,g3),

   weierstrass1(i*~u,~g2,~g3) => -weierstrass1(u,g2,-g3),
   weierstrassZeta1(i*~u,~g2,~g3) => -i*weierstrassZeta1(u,g2,-g3),
   weierstrass_sigma0(i*~u,~g2,~g3) => i*weierstrass_sigma0(u,g2,-g3),

   weierstrass1(~m*~u,~g2,~g3) => weierstrass1(u, g2*m^4,g3*m^6)/m^2
           when numberp m,
   weierstrasszeta1(~m*~u,~g2,~g3) => weierstrasszeta1(u, g2*m^4,g3*m^6)/m
           when numberp m,
   weierstrass_sigma0(~m*~u,~g2,~g3) => m*weierstrass_sigma0(u, g2*m^4,g3*m^6)
           when numberp m,

   epsilon_w1(~u, ~g2, ~g3)^2 => 1,
   df(epsilon_w1(~u, ~g2, ~g3), u) => 0,

   % epsilon_w1 = +/-1 and changes sign at poles of the Weierstrass fn and
   % at when Weierstrass fn is equal to a lattice-root e_1, e_2 or e_3
   df(weierstrass1(~u,~g2,~g3),u) => epsilon_w1(u,g2,g3)*
      sqrt(4*weierstrass1(u,g2,g3)^3 - g2*weierstrass1(u,g2,g3) - g3),

   df(weierstrassZeta1(~u,~g2,~g3),~u)  => -weierstrass1(u,g2,g3),

   df(weierstrass_sigma0(~u,~g2,~g3),~u)  =>
      weierstrass_sigma0(u,g2,g3)*weierstrassZeta(u,g2,g3),

   weierstrass1(lattice_omega1(~g2,~g3),g2,g3) => lattice1_e1(g2,g3),
   weierstrass1(lattice_omega3(~g2,~g3),g2,g3) => lattice1_e3(g2,g3),
   weierstrass1(lattice_omega2(~g2,~g3),g2,g3) => lattice1_e2(g2,g3),

   sqrt(4*lattice1_e1(~g2,~g3)^3 - g2*lattice1_e1(g2,g3) - g3) => 0,
   sqrt(4*lattice1_e2(~g2,~g3)^3 - g2*lattice1_e2(g2,g3) - g3) => 0,
   sqrt(4*lattice1_e3(~g2,~g3)^3 - g2*lattice1_e3(g2,g3) - g3) => 0,

% Numerical evaluation
   weierstrass1(~u,~g2,~g3) => num_elliptic(num_weier1, u, g2, g3)
      when lisp !*rounded and numberp u and numberp g2 and numberp g3,

   weierstrasszeta1(~u,~g2,~g3) => num_elliptic(num_weierZeta1, u, g2, g3)
      when lisp !*rounded and numberp u and numberp g2 and numberp g3,

   weierstrass_sigma0(~u, ~g2, ~g3) =>
          num_elliptic(num_weierSigma, u, g2, g3)
      	     when lisp !*rounded and numberp u and numberp g2 and numberp g3,

  lattice_omega1(~g2,~g3) => first lattice_generators(g2,g3) 
      when lisp !*rounded and numberp g2 and numberp g3,

   lattice_omega2(~g2,~g3) => (begin scalar l;
      l:=lattice_generators(g2,g3);
      return first l + second l;
   end)
      when lisp !*rounded and numberp g2 and numberp g3,

  lattice_omega3(~g2,~g3) => second lattice_generators(g2,g3) 
      when lisp !*rounded and numberp g2 and numberp g3,

   lattice1_e1(~g2,~g3) => first lattice1_roots(g2,g3)
      when lisp !*rounded and numberp g2 and numberp g3,
   lattice1_e2(~g2,~g3) => second lattice1_roots(g2,g3)
      when lisp !*rounded and numberp g2 and numberp g3,
   lattice1_e3(~g2,~g3) => third lattice1_roots(g2,g3)
      when lisp !*rounded and numberp g2 and numberp g3
    
 }$
let weierstrass1_rules;

% The function detects the erroneous case of tau being real, before
% calling num_elliptic -- this ensures the precision doesn't creep upwards
% in case of error.

procedure n_sigma(f, u, w1, w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of Weierstrass functions must be complex")
else num_elliptic(f,u,w1,w3);

procedure num_weier(u,w1,w3);
begin scalar q, tau, t2, t4, e2, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u,w1, tau);
  u := first l;
  % The error thrown here must be catchable (by n_elliptic):
  if u = 0 then lisp error(99, "Weierstrass has poles at lattice points");
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
procedure lattice_roots(w1,w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else 
  num_elliptic(l_roots,w1,w3);

procedure l_roots(w1,w3);
begin scalar q, tau, t2, t4, m, l;
  l := fix_omegas(w1,w3);
  w1 := first l; tau := third l;
  q := exp(i*pi*tau);
  t2 := n_theta2(0,q,tau)^4;
  t4 := n_theta4(0,q)^4;
  m := (pi/w1)^2/12;
  return foreach el in {m*(t2+2*t4), m*(t2-t4), -m*(2*t2+t4)}
     collect tidy_result(el);
end;

procedure lattice_invariants(w1,w3);
begin scalar tmp;
   tmp := impart(w3/w1);
   if tmp = 0 then rederr
      ("Ratio of the period parameters of the lattice must be complex");
   if tmp < 0 then << tmp:=w1; w1:=w3; w3:=tmp>>;
   return num_elliptic(l_invariants,w1,w3);
end;

procedure l_invariants(w1,w3);
begin scalar l, g2, g3, e1, e2, e3;
  l := l_roots(w1, w3);
  e1 := first l;
  e2 := second l;
  e3 := third l;
  g2 := tidy_result(2*(e1^2+e2^2+e3^2));
  g3 := tidy_result(4*e1*e2*e3);
  return {g2, g3, tidy_result(g2^3 - 27*g3^2),
          if g3 = 0 then infinity else g2^3/(27*g3^2)};
end;

procedure num_weierZeta(u,w1,w3);
begin scalar q, tau, n1, n3, et1, et3, z, l;
  l := fix_omegas(w1,w3);
  w1 := first l;
  w3 := second l;
  tau := third l;
  l := fix_arg(u,w1, tau);
  u := first l;
  % The error thrown here must be catchable (by n_elliptic):
  if u = 0 then lisp error(99, "WeierstrassZeta has poles at lattice points");
  n3 := second l;
  n1 := third l;
  q := exp(i*pi*tau);
  et1 := -pi^2/(12*w1)*n_theta1d(0,3,tau)/n_theta1d(0,1,tau);
  et3 := et1*tau-pi*i/(2*w1);
  z := pi*u/(2*w1);
  return et1*u/w1 + pi/(2*w1)*n_theta1d(z,1,tau)/n_theta1(z,q,tau)
           + 2*n3*et3 + 2*n1*et1;
end;

procedure quasi_period_factors(w1,w3);
if impart (w3/w1) = 0 then rederr
   ("Ratio of the period parameters of the lattice must be complex")
else
   num_elliptic(num_qpf,w1,w3);

procedure num_qpf(w1,w3);
begin scalar tmp, tau, tmp1;
  tau := w3/w1;
  if impart(tau) <0 then <<
     tmp := w1; w1 := w3;
     w3 := tmp; tau := 1/tau;
  >>;
  tmp := pi^2*n_theta1d(0,3,tau)/(12*w1*n_theta1d(0,1,tau));
  tmp1 := pi*i/(2*w1);
  return foreach eta in {-tmp, (1+tau)*tmp + tmp1, -tau*tmp -tmp1} collect tidy_result eta;
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

procedure lattice_generators(g2,g3);
  if g2^3-27*g3^2 = 0 then
     rederr("The discriminant of the invariants is zero.")
  else
     num_elliptic(num_omegas,g2,g3);

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
   return {tidy_result(m/kk1), tidy_result(i*m/kk)};

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

%##################################################################
% Alternative forms of the Weierstrass functions

procedure num_weier1(u,g2,g3);
begin scalar l;
   if g2^3-27*g3^2=0 then <<
      % Weierstrass function becomes elementary
      l := (3*g2/4)^(1/4);
      if (g2/3)^(3/2) = g3 then
	 return l^2*(csc(l*u)^2-1/3)
      else
	 return l^2*(csch(l*u)^2+1/3);
   >>;
  l := num_omegas(g2,g3);
  return num_weier(u, first l, second l);
end;

procedure num_weierZeta1(u,g2,g3);
begin scalar l;
   if g2^3-27*g3^2=0 then <<
      % Weierstrass Zeta function becomes elementary
      l := (3*g2/4)^(1/4);
      if (g2/3)^(3/2) = g3 then
	 return l*(cot(l*u)+l*u/3)
      else
	 return l*(coth(l*u)-l*u/3);
   >>;
  l := num_omegas(g2,g3);
  return num_weierZeta(u, first l, second l);
end;

procedure num_weierSigma(u,g2,g3);
begin scalar l;
   if g2^3-27*g3^2=0 then <<
      % Sigma function becomes elementary
      l := (3*g2/4)^(1/4);
      if (g2/3)^(3/2) = g3 then
	 return exp(l^2*u^2/6)*sin(l*u)
      else
	 return exp(-l^2*u^2/6)*sinh(l*u);
   >>;
  l := num_omegas(g2,g3);
  return num_sigma(u, first l, second l);
end;

procedure lattice1_roots(g2,g3);
begin scalar l,e1,e2,e3;
   l := solve(4*(!*x!*)^3 - g2*(!*x!*) -g3 = 0, !*x!*);
   l:=foreach elem in l collect tidy_result(rhs elem);
   if impart first l=0 and impart second l=0 and impart third l=0
   then <<
         e1:= max l; e3 := min l;  e2 := -e1-e3;
         return {e1,e2,e3};
   >>
   else <<
      if impart second l =0 then return {second l, first l, third l}
      else if impart third l=0 then return {third l, first l, second l}
      else return l;
   >>;
end;

algebraic procedure canonical_gens(w1,w3);
% If {w1,w3} generate a rectangular or rhombic lattice
% return a canonical set of generators {v1,v3}
% with v1 real and positive and
% for the rectangular case: v3 'positive' imaginary
% or for the rhombic case: Re(v3) = v1/2 & Im(v3)>0
% otherwise return nil
begin scalar rw1, iw1, rw3, iw3, N, a,b,c,d, v1,v3, b0,c0, done;
   if w1 =0 or impart(w3/w1) =0 then return nil;
   
   if impart w3=0 or repart w1=0 then
      << N := w1; w1:=w3; w3:= N>>;
   rw1 :=repart w1;
   rw3 :=repart w3;
   iw1 := impart w1;
   iw3 := impart w3;
   if iw1=0 and (rw3=0 or rw3=rw1/2) then
      return {abs rw1, abs rw3+i*abs iw3};

   N :=  rw1*iw3/(rw1*iw3-iw1*rw3);
   if not fixpp (2*N) then
       return nil;
 
   b0:= -iw1/iw3;
   c0:= -rw3/rw1;
   a := 0;
   done :=nil;
   if fixpp(N) then  <<
      N := round N;
      repeat <<
	 a := a+1;
	 if remainder(N,a)=0 then <<
            if fixpp (b0*a) then <<
	       b := round(b0*a);
	       v1 := a*w1+b*w3;
	       d := N/a;
	       if  fixpp(c0*d) then <<
		  c:= round (c0*d);
		  if n-b*c=1 then <<
                     v3 := c*w1+d*w3;
		     done :=t;
		  >>;
	       >>;
	    >>;
	 >>;
      >> until done or a>=N;
   >>;
   if done then <<
      v1:= abs v1;
      if impart v3 <0 then v3:=-v3; 
      return {v1,v3};
   >>;
   N := round (2N);
   a:=0;
   repeat <<
      a := a+1;
      if remainder(N,a)=0 then <<
	 if fixpp (b0*a) then <<
	    b := round(b0*a);
	    v1 := a*w1+b*w3;
	    d:= N/(2a)+b/2;
	    if fixpp(N*c0/(2a)+a/2) then <<
	       c := round(N*c0/(2a)+a/2);
	       if  a*d-b*c=1 then <<
		  v3 := c*w1+d*w3;
		  done := t;
	       >>;
	    >>;
	 >>;
      >>;
   >> until done or a>=N;
   if done then <<
      v1 := abs v1;
      if repart v3 <0 then v3 :=-v3;
      if impart v3 <0 then v3 :=conj(v3);
      return {v1,v3};
   >>	 
   else 
      return nil;
end;

algebraic procedure fixpp(x);
begin scalar tol, y;
   tol := 10.0^-(symbolic !:prec!: -4);
   y := round x;
   if   y=0 then return if (abs(x-y) < tol) then  1 else 0
   else return if (abs((x-y)/x) <tol) then 1 else 0;
end;

% Special-case numerical evaluation of epsilon_w and epsilon_w1 when
% the Weierstrass functions take real values on the real axis.

% FJW, April 2025.   

% According to <https://dlmf.nist.gov/23.5>, the Weierstrass functions
% take real values on the real axis iff the lattice is fixed under
% complex conjugation, or equivalently g2 and g3 are both real, which
% corresponds to the following lattice configurations:

% Rectangular: w1 and w3/i both real and positive.
% (Lemniscatic special case: g3 = 0; w1 real & positive, w3 = i*w1)

% Rhombic: w1 real and positive, impart(w3) > 0, repart(w3) = 1/2 w1.
% (Equianharmonic special case: g2 = 0; w1 real & positive, w3 = exp(i*pi/3)*w1)

% But don't require the positivity stated above.

let epsilon_w(~u,~w1,~w3) => num_elliptic(num_epsilon_w,u,w1,w3)
   when lisp !*rounded and lisp !*complex and
     numberp u and numberp w1 and numberp w3;

let epsilon_w1(~u,~g2,~g3) => num_elliptic(num_epsilon_w1,u,g2,g3)
   when lisp !*rounded and numberp u and numberp g2 and
   numberp g3 and g2^3-27g3^2 neq 0;

% returns list {a,b} where z = a*z1 + b*z2
algebraic procedure lattice_coords(u,w1,w3);
begin scalar d;
   d := repart(w1)*impart(w3)-impart(w1)*repart(w3);      
   return {(impart(w3)*repart(u) - repart(w3)*impart(u))/d,
           (repart(w1)*impart(u) - impart(w1)*repart(u))/d};
end;       

algebraic procedure base_value(u,w1,w3);
   % w1 and w3 are the so called 'half' periods of the Weierstrass function
   % returns the congruent point in the base parallelogram centred on O.
begin scalar a, b;
      u := lattice_coords(u,w1,w3);
      a := first u;
      b := second u;
      tmp := floor a;
      if evenp tmp then a:=a-tmp else a := a-tmp-1;
      if a =-1 then a:=1;
      tmp := floor b;
      if evenp tmp then b:=b-tmp else b := b-tmp-1;
      if b =-1 then b:=1;
      return a*w1+b*w3;
end;

algebraic procedure num_epsilon_w(u,w1,w3);
   % Return sign of df(weierstrass(u,w1,w3),u)
   % Rough and ready; probably needs fine tuning near zeros of d
 begin scalar g2,g3,p,d,tmp,delta,tol;
   delta := 2^(-10); tol := 2^(-7);
   u := base_value(u,w1,w3);
   if u=0 then rederr("Derivative has a pole at this value");
   p := weierstrass(u,w1,w3);
   tmp:= lattice_invariants(w1,w3);
   g2 := first tmp;
   g3 := second tmp;
   d := sqrt(4p^3-g2*p-g3);
   if abs u <tol then
      return if repart(2/(u^3*d))<0 then 1 else -1;

%%    r := lattice_roots(w1,w3);
%%    e1 := first r; e2 := second r; e3 := third r;
%% 
%%    tmp := u-w1; 
%%    if abs tmp < tol then
%%       return if repart((12e1^2-g2)*tmp/2d)>0 then 1 else 0;
%%    tmp := u+w1; 
%%    if abs tmp < tol then
%%       return if repart((12e1^2-g2)*tmp/2d)>0 then 1 else 0;
%% 
%%    tmp := u-w3;
%%    if abs tmp < tol then
%%       return if repart((12e3^2-g2)*tmp/2d)>0 then 1 else 0;
%%    tmp := u+w3; 
%%    if abs tmp < tol then
%%       return if repart((12e3^2-g2)*tmp/2d)>0 then 1 else 0;
%% 
%%    tmp := u-w1-w3;
%%    if abs tmp < tol then
%%       return if repart((12e2^2-g2)*tmp/2d)>0 then 1 else 0;
%%    tmp := u+w1+w3; 
%%    if abs tmp < tol then
%%       return if repart((12e2^2-g2)*tmp/2d)>0 then 1 else 0;
%%    tmp := u-w1+w3;
%%    if abs tmp < tol then
%%       return if repart((12e2^2-g2)*tmp/2d)>0 then 1 else 0;
%%    tmp := u+w1-w3; 
%%    if abs tmp < tol then
%%       return if repart((12e2^2-g2)*tmp/2d)>0 then 1 else 0;
%%    
   tmp := weierstrass(u+delta,w1,w3);
   return if repart((tmp-p)/(d*delta)) > 0 then 1 else -1;
end;

algebraic procedure num_epsilon_w1(u,g2,g3);
   % Return sign of df(weierstrass1(u,g2,g3),u)
   % Rough and ready; probably needs fine tuning near zeros of d
begin scalar w1,w3,p,d,tmp,delta,tol;
   delta := 2^(-10); tol := 2^(-7);
   tmp:=  lattice_generators(g2,g3);
   w1 := first tmp;
   w3 := second tmp;
   u := base_value(u,w1,w3); 
   if u=0 then rederr("Derivative has a pole at this value");
   p := weierstrass(u,w1,w3);
   d := sqrt(4p^3-g2*p-g3);
   if abs u <tol then
      return if repart(2/(u^3*d))<0 then 1 else -1;
   tmp := weierstrass1(u+delta,g2,g3);
   return if repart((tmp-p)/(d*delta)) > 0 then 1 else -1;
end;


%######################################################################

put('weierstrass1, 'fancy!-functionsymbol, "\wp");
put('weierstrassZeta1, 'fancy!-functionsymbol, "\zeta_w");
put('WeierstrassZeta1, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma0, 'fancy!-functionsymbol, "\sigma");
put('weierstrass1, 'fancy!-prifn, 'fancy!-weier);
put('weierstrassZeta1, 'fancy!-prifn, 'fancy!-weier);
put('weierstrass_sigma0, 'fancy!-prifn, 'fancy!-weier);
put('epsilon_1, 'fancy!-prifn, 'fancy!-weier);
put('epsilon_1, 'fancy!-symbol!-length, 4);
put('epsilon_1, 'fancy!-functionsymbol, "\epsilon_1");

put('weierstrass1, 'plain!-functionsymbol, "P_w");
put('weierstrassZeta1, 'plain!-functionsymbol, "zeta_w");
put('weierstrass_sigma0, 'plain!-functionsymbol, "sigma");
put('weierstrass1, 'prifn, 'plain!-weier);
put('weierstrassZeta1, 'prifn, 'plain!-weier);
put('weierstrass_sigma0, 'prifn, 'plain!-weier);
put('epsilon_1, 'prifn, 'plain!-weier);

put('weierstrass, 'fancy!-functionsymbol, "\wp");
put('weierstrassZeta, 'fancy!-functionsymbol, "\zeta_w");
put('weierstrassZeta, 'fancy!-symbol!-length, 4);
put('epsilon_0, 'fancy!-functionsymbol, "\epsilon_0");
put('epsilon_0, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma, 'fancy!-functionsymbol, "\sigma");
put('weierstrass_sigma1, 'fancy!-functionsymbol, "\sigma_1");
put('weierstrass_sigma2, 'fancy!-functionsymbol, "\sigma_2");
put('weierstrass_sigma3, 'fancy!-functionsymbol, "\sigma_3");
put('weierstrass_sigma1, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma2, 'fancy!-symbol!-length, 4);
put('weierstrass_sigma3, 'fancy!-symbol!-length, 4);

put('weierstrass, 'prifn, 'plain!-symbol);
put('weierstrassZeta, 'prifn, 'plain!-symbol);
put('weierstrass_sigma, 'prifn, 'plain!-symbol);
put('weierstrass_sigma1, 'prifn, 'plain!-symbol);
put('weierstrass_sigma2, 'prifn, 'plain!-symbol);
put('weierstrass_sigma3, 'prifn, 'plain!-symbol);
put('weierstrass, 'plain!-functionsymbol, "P_w");
put('weierstrasszeta, 'plain!-functionsymbol, "zeta_w");
put('weierstrass_sigma, 'plain!-functionsymbol, "sigma");
put('weierstrass_sigma1, 'plain!-functionsymbol, "sigma_1");
put('weierstrass_sigma2, 'plain!-functionsymbol, "sigma_2");
put('weierstrass_sigma3, 'plain!-functionsymbol, "sigma_3");

put('eta1, 'fancy!-functionsymbol, "\eta_1");
put('eta2, 'fancy!-functionsymbol, "\eta_2");
put('eta3, 'fancy!-functionsymbol, "\eta_3");
put('eta1, 'fancy!-symbol!-length, 4);
put('eta2, 'fancy!-symbol!-length, 4);
put('eta3, 'fancy!-symbol!-length, 4);

put('lattice_e1, 'fancy!-functionsymbol, "\mathrm{e_1}");
put('lattice_e2, 'fancy!-functionsymbol, "\mathrm{e_2}");
put('lattice_e3, 'fancy!-functionsymbol, "\mathrm{e_3}");
put('lattice_e1, 'fancy!-symbol!-length, 4);
put('lattice_e2, 'fancy!-symbol!-length, 4);
put('lattice_e3, 'fancy!-symbol!-length, 4);

put('lattice1_e1, 'fancy!-functionsymbol, "\mathrm{e_1}");
put('lattice1_e2, 'fancy!-functionsymbol, "\mathrm{e_2}");
put('lattice1_e3, 'fancy!-functionsymbol, "\mathrm{e_3}");
put('lattice1_e1, 'fancy!-symbol!-length, 4);
put('lattice1_e2, 'fancy!-symbol!-length, 4);
put('lattice1_e3, 'fancy!-symbol!-length, 4);
put('lattice1_e1, 'fancy!-prifn, 'fancy!-weier);
put('lattice1_e2, 'fancy!-prifn, 'fancy!-weier);
put('lattice1_e3, 'fancy!-prifn, 'fancy!-weier);

put('lattice_e1, 'prifn, 'plain!-symbol);
put('lattice_e1, 'plain!-functionsymbol, "e1");
put('lattice_e2, 'prifn, 'plain!-symbol);
put('lattice_e2, 'plain!-functionsymbol, "e2");
put('lattice_e3, 'prifn, 'plain!-symbol);
put('lattice_e3, 'plain!-functionsymbol, "e3");

put('lattice1_e1, 'prifn, 'plain!-weier);
put('lattice1_e1, 'plain!-functionsymbol, "e1");
put('lattice1_e2, 'prifn, 'plain!-weier);
put('lattice1_e2, 'plain!-functionsymbol, "e2");
put('lattice1_e3, 'prifn, 'plain!-weier);
put('lattice1_e3, 'plain!-functionsymbol, "e3");

put('lattice_g2, 'fancy!-functionsymbol, "\mathrm{g_2}");
put('lattice_g3, 'fancy!-functionsymbol,  "\mathrm{g_3}");
put('lattice_delta, 'fancy!-functionsymbol, "\Delta");
put('lattice_g, 'fancy!-functionsymbol, "\mathrm{G}");
put('lattice_g2, 'fancy!-symbol!-length, 4);
put('lattice_g3, 'fancy!-symbol!-length, 4);
put('lattice_omega1, 'fancy!-functionsymbol, "\omega_1");
put('lattice_omega2, 'fancy!-functionsymbol, "\omega_2");
put('lattice_omega3, 'fancy!-functionsymbol, "\omega_3");
put('lattice_omega1, 'fancy!-symbol!-length, 4);
put('lattice_omega2, 'fancy!-symbol!-length, 4);
put('lattice_omega3, 'fancy!-symbol!-length, 4);
put('lattice_omega1, 'fancy!-prifn, 'fancy!-weier);
put('lattice_omega2, 'fancy!-prifn, 'fancy!-weier);
put('lattice_omega3, 'fancy!-prifn, 'fancy!-weier);

put('lattice_g2, 'prifn, 'plain!-symbol);
put('lattice_g2, 'plain!-functionsymbol, "g2");
put('lattice_g3, 'prifn, 'plain!-symbol);
put('lattice_g3, 'plain!-functionsymbol, "g3");
put('lattice_delta, 'plain!-functionsymbol, "!Delta");
put('lattice_delta, 'prifn, 'plain!-symbol);
put('lattice_g, 'plain!-functionsymbol, "!G");
put('lattice_g, 'prifn, 'plain!-symbol);

put('lattice_omega1, 'prifn, 'plain!-weier);
put('lattice_omega1, 'plain!-functionsymbol, "w1");
put('lattice_omega2, 'prifn, 'plain!-weier);
put('lattice_omega2, 'plain!-functionsymbol, "w2");
put('lattice_omega3, 'prifn, 'plain!-weier);
put('lattice_omega3, 'plain!-functionsymbol, "w3");

% The next 2 declarations enable better checking of the number
% of arguments by simpiden

flag('(weierstrass_sigma weierstrass_sigma1 weierstrass_sigma2
       weierstrass_sigma3 weierstrass weierstrassZeta
       eta1 eta2 eta3 lattice_e1 lattice_e2 lattice_e3
       lattice_g2 lattice_g3  lattice_delta lattice_g
       lattice_omega1 lattice_omega3 lattice_omega2 weierstrass1
       weierstrasszeta1 weierstrass_sigma0 epsilon_0 epsilon_1
       lattice1_e1 lattice1_e2 lattice1_e3
), 'specfn);


deflist('((weierstrass_sigma 3) (weierstrass_sigma1 3)
          (weierstrass_sigma2 3) (weierstrass_sigma3 3)
          (weierstrass 3) (weierstrassZeta 3) (epsilon_0 3) (epsilon_1 3)
 	  (eta1 2) (eta2 2) (eta3 2) (lattice_e1 2) (lattice_e3 2)
	  (lattice_e3 2)  (lattice_g2 2) (lattice_g3 2)  (lattice_delta 2)
 	  (lattice_g 2) (weierstrass1 3)
	  (weierstrassZeta1 3) (weierstrass_sigma0 3)
	  (lattice_omega1 2) (lattice_omega3 2) (lattice_omega3 2)
	  (lattice1_e1 2)  (lattice1_e2 2)  (lattice1_e3 2)
        ), 'number!-of!-args);

symbolic procedure plain!-weier(u);
begin;
    prin2!*(get(car u,'plain!-functionsymbol));
    prin2!* "(";
    if cdddr u then <<
       maprin cadr u;
       prin2!* "|";
       maprin caddr u;
       prin2!* ",";
       maprin cadddr u;
    >> else <<
       prin2!* "|";
       maprin cadr u;
       prin2!* ",";
       maprin caddr u;
    >>;
    prin2!* ")";
    return u;
end;

fluid '(fancy!-pos!* fancy!-texpos fancy!-line!*);

symbolic procedure fancy!-weier u;
 fancy!-level
  begin scalar args;
   fancy!-prefix!-operator car u;
   if cdddr u then args := {cadr u, '!|, caddr u, '!,, cadddr u}
   else args :=  {'!|, cadr u, '!,, caddr u};
   return fancy!-in!-brackets(
               {'fancy!-inprint, mkquote 'times, 1,  mkquote args},
	         '!(, '!));
  end;

%% symbolic procedure fancy!-weier u;
%%  fancy!-level
%%   begin scalar args;
%%    fancy!-prefix!-operator car u;
%%    args := {cadr u, '!|, caddr u, '!,, cadddr u};
%%    return fancy!-in!-brackets(
%%                {'fancy!-inprint, mkquote 'times, 1,  mkquote args},
%% 	         '!(, '!));
%%   end;

%% symbolic procedure fancy!-weier1 u;
%%  fancy!-level
%%   begin scalar args;
%%    fancy!-prefix!-operator car u;
%%    args :=  {'!|, cadr u, '!,, caddr u};
%%    return fancy!-in!-brackets(
%%                {'fancy!-inprint, mkquote 'times, 1,  mkquote args},
%% 	         '!(, '!));
%%   end;

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
