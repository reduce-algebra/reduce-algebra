module eftheta;  % Procedures and Rules for Jacobi Theta Functions.

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

% $Id: sftheta.red 5874 2021-07-30 21:08:56Z arthurcnorman $
% Substantial additions and corrections by Alan Barnes, 2019
% Numerical procedures for the derivatives of theta functions, Feb. 2021.
% Renamed (was sftheta) and moved to a new package ellipfn, December 2021
% by Alan Barnes

%#######################################################################
% CALCULATING THE FOUR THETA FUNCTIONS
% These theta functions differ from those originally defined by Lisa Temme
% in that the periods are 2*pi, 2*pi, pi and pi respectively 
% (NOT 4K, 4K, 2K and 2K).
% Also the second argument is now not the nome q, but the parameter tau where
% q = exp(i*pi*tau)). It is necessary that impart(tau) > 0 so that |q| < 1.
% The quasi-period is pi*tau.
% As functions of the nome, theta1 and theta2 are multi-valued owing to the
% appearance of q^(1/4) in their defining expansions.

% Regarded as functions of the parameter tau, theta1 and theta2 are
% single-valued functions of tau.
% Note in this case q^(1/4) is interpreted as exp(i*pi*tau/4) rather than
% the principal value of q^(1/4). Thus tau and 2+tau, 4+tau and 6+tau produce
% four different values of both theta1 and theta2 although they produce the
% same nome q.
%
% Again I am following the conventions of DF Lawden:
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
% modular transformation tau' = tau+/-1, which has the effect  of multiplying
% q by -1, so that the new nome has a non-negative real part.

% If tau' = a+ib, |q'| = e^(-pi* b) and arg q' = pi*a with |a| <= 1/2.
% The Jacobi transformation then produces a new nome q'' s.t.
% |q''| =  |q'|^{1/(a^2+b^2)}.

% This works very well for real values of q', i.e. a=0 so
% |q''| = |q'|^{1/b^2}), but for complex values the gains
% are somewhat smaller. The worst case occurs for values of the original nome
% near to +/-i where |q''| ~ |q|^4.

% By using a series of Jacobi transformations preceded, if necessary by the
% modular transformation tau' = tau +/- integer to ensure |a| <= 1/2, to reduce
% |q| to acceptable levels.
% Somewhat arbitrarily Jacobi's transformations are used 
% until b > 0.6 (i.e. |q| < 0.15). This seems to produce reasonable behaviour.
% In practice more than 2 applications of Jacobi's transformation are rarely
% necessary.

% The previous version of the numerical code returned the principal value
% of theta1 and theta2, that is the one obtained by taking the principal value
% of q^(1/4). As indicated above the current version replaces q^(1/4) by
% exp(i*pi*tau/4).  If the principle value is required it is easily obtained
% by multiplying the correcting factor q^(1/4)*exp(-i*pi*tau/4).

algebraic;

procedure shift!-tau(tau);
% shift tau into the range -1 < tau < 1.
begin scalar nt;
  nt := fix repart tau; 
  tau := tau - nt;  % tau now in required range
  nt := nt mod 8;
  return {tau, nt};
end;

procedure shift!-arg(z,tau);
% shift the argument down into the base period parallelogram
begin scalar quasip, rpq, numhqp, numhrp;
  
  quasip := pi*tau;
  rpq := impart quasip;
  numhqp := fix(2*impart(z)/rpq);  % number of half quasi-periods used
  z := z - numhqp*quasip/2;
  numhrp := fix(2*repart(z)/pi);   % number of half real periods used
  z := z - numhrp*pi/2;
  return {z, numhrp, numhqp, tau, numtau};
end;

procedure n_theta1(z, q, tau);
begin scalar n, pow, term, total, tol, m, bound, f;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    n := 0;
    bound := exp abs impart z;
    f := bound^2;
    % abs sin((2n+1)z) <= exp ((2n+1) abs Im z)
    repeat <<
       pow := (-1)^n*q^(n*(n+1));
       term := pow*sin((2*n+1)*z);
       total := total + term;
       n := n+1;
       bound := bound * f;
       m :=  abs(pow)*bound;
    >> until (total = 0 and m < tol) or m < abs(total)*tol;
    return 2*exp(i*pi*tau/4)*total;
end;    

procedure num_theta1(z, q, tau);
begin scalar x, m, nt;
   if impart tau > 0.6  then   % i.e. |q| < 0.15
       return n_theta1(z, q, tau);

   % before applying the Jacobi transformation, ensure |repart tau| <= 1/2
   m := shift!-tau(tau);
   tau := first m;  % now |repart tau| <1
   nt := second m;

   m := exp(i*nt*pi/4);  % scaling factor for the tau-shift
   if repart  q < 0 then <<  %  i.e. 1/2 < |repart tau| <1
     % now ensure |repart tau| < 1/2
      if impart q < 0 then <<  % i.e. repart tau < -1/2
         % apply the modular transformation tau' = 1+tau (q' = -q)
         tau := tau+1;
         m := m*exp(-i*pi/4)>>
      else <<    % i.e. repart tau > 1/2
         % apply the modular transformation tau' = tau-1 (q' = -q)
         tau := tau-1;
         m := m*exp(i*pi/4)>>
   >>;
   % Apply Jacobi's transformation
   x := -1/tau;
   q := exp(i*pi*x);
   return -i*m*(-i*x)^(1/2)*exp(i*x*z^2/pi)*num_theta1(x*z, q, x);
end;

procedure num1_theta1(z, tau);
begin scalar  nr, nq, m, nt, q;
   m := shift!-tau(tau);
   tau := first m;
   nt := second m;
   % |repart tau| is now <1

   % It is important to make impart z as small as possible by shifting so
   % that the size of the trigonometric terms in the Fourier series 
   % expansions are kept reasonably small.
   m := shift!-arg(z,tau);
   z:= first m;
   nr := second m;
   nq := third m;
   q := exp(i*pi*tau);
   m := exp(i*nt*pi/4);  % phase factor for tau shift
   
   nr := nr mod 4;
   if nr = 2 or nr=3 then m :=-m;
   if evenp nr then 
      if evenp nq then <<
         nq := nq/2;
         m := m*(-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
         return m*num_theta1(z, q, tau);
      >> 
      else <<
          nq := (nq-1)/2;
          m := m*(-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
          return m*num_theta4(z,q, tau);
       >>
    else
       if evenp nq then <<
          nq := nq/2;
          m := m*exp(-2*i*nq*z)/q^(nq^2);
          return m*num_theta2(z, q, tau);
       >>
       else <<
          nq := (nq-1)/2;
          m := m*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
          return m*num_theta3(z, q, tau);
       >>;
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

procedure n_theta2(z,q,tau);
begin scalar n, pow, term, total, tol, m, bound, f;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    n := 0;
    bound := exp abs impart z;
    f := bound^2;
    % abs cos((2n+1)z) <= exp ((2n+1) abs Im z)

    repeat <<
       pow := q^(n*(n+1));
       term := pow*cos((2*n+1)*z);
       total := total +  term; 
       n := n+1;
       bound := bound * f;
       m :=  abs(pow)*bound;
    >> until (total = 0 and m < tol) or m < abs(total)*tol;
    return 2*exp(i*pi*tau/4)*total;
end;

procedure num_theta2(z, q, tau);
begin scalar  x, m, nt;
   if  impart tau > 0.6  then  % i.e. |q| < 0.15
       return n_theta2(z, q, tau);

   m := shift!-tau(tau);
   tau := first m;
   nt := second m;
   m := exp(i*nt*pi/4);

   if repart  q < 0 then <<
      if impart q < 0 then <<
         % apply the modular transformation tau' = 1+tau (q' = -q)
         tau := tau+1;
         m := m*exp(-i*pi/4)>>
      else <<
         % apply the modular transformation tau' = tau-1 (q' = -q)
         tau := tau-1;
         m := m*exp(i*pi/4)>>
   >>;

   % Use Jacobi transformation
   x := -1/tau;
   q := exp(i*pi*x);
   return m*(-i*x)^(1/2)*exp(i*x*z^2/pi)*num_theta4(x*z, q, x);
end;


procedure num1_theta2(z,tau);
begin scalar nr, nq, m, nt, q;
   m := shift!-tau(tau);
   tau := first m;
   nt := second m;
   % |repart tau| is now < 1

   % It is important to make impart z as small as possible by shifting so
   % that the size of the trigonometric terms in the Fourier series 
   % expansions are kept reasonably small.
   m := shift!-arg(z,tau);
   z:= first m;
   nr := second m;
   nq := third m;
   q := exp(i*pi*tau);
   m := exp(i*nt*pi/4);  % phase factor for tau shift
    
   nr := nr mod 4;
   if nr = 2 or nr=3 then m :=-m;
   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := m*exp(-2*i*nq*z)/q^(nq^2);
         return m*num_theta2(z, q, tau);
      >>
      else <<
         nq := (nq-1)/2;
         m := m*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
         return m*num_theta3(z, q, tau);
      >>
   else
      if evenp nq then <<
         nq := nq/2;
         m := m*(-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
	 return -m*num_theta1(z, q, tau);
      >>
      else <<
         nq := (nq-1)/2;
         m := m*(-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
         return -m*num_theta4(z, q, tau);
      >>;
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

procedure n_theta3(z, q);
begin scalar n, pow, term, total, tol, m, bound, f;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;
   f := exp (2*abs impart z);
   bound :=1;
   % abs cos(2nz) <= exp (2n abs Im z)

   repeat <<
      pow := q^(n*n);
      term := pow*cos(2*n*z);
      total := total + term;
      n := n+1;
      bound := bound * f;
      m :=  abs(pow)*bound;
   >> until (total = 0 and m < tol) or m < abs(total)*tol;
   return 1 + 2*total;
end;

procedure num_theta3(z, q, tau);
begin scalar x, m, nt;

   if impart tau > 0.6  then   % i.e. |q| < 0.15
       return n_theta3(z, q);

   m := shift!-tau(tau);
   tau := first m;
   nt := second m;

   % note under a tau-shift by an odd integer theta3 --> theta4 and vice-versa
   % whereas for an even shift theta3 and theta4 are unchanged.
   if repart  q >=  0 then <<
        % Use Jacobi transformation 
        x := -1/tau;
	q := exp(i*pi*x);
	m := (-i*x)^(1/2)*exp(i*x*z^2/pi);
        return m*(if evenp nt then num_theta3(x*z, q, x)
		  else num_theta2(x*z, q, x));
   >>;

   if impart q < 0 then 
      % apply the modular transformation tau' = 1+tau (q' = -q)
      tau := tau+1
   else
      % apply the modular transformation tau' = tau-1 (q' = -q)
      tau := tau-1;

   % then Jacobi's transformation
   x:= -1/tau;
   q := exp(i*pi*x);
   m := (-i*x)^(1/2)*exp(i*x*z^2/pi);
   return m*(if evenp nt then num_theta2(x*z, q, x)
             else  num_theta3(x*z, q, x));
end;

procedure num1_theta3(z, tau);
begin scalar m, nt;
  m := shift!-tau(tau);
  tau := first m;
  nt := second m;
  % |repart tau| is now < 1
  % Now allow for the effect of the tau shift
  if evenp nt then
     return num2_theta3(z,tau)
  else
     return num2_theta4(z,tau);
end;

procedure num2_theta3(z,tau);
begin scalar  nr, nq, m, q;
   % It is important to make impart z as small as possible by shifting so
   % that the size of the trigonometric terms in the Fourier series 
   % expansions are kept reasonably small.
   m := shift!-arg(z,tau);
   z := first m;
   nr := second m;
   nq := third m;
   q := exp(i*pi*tau);
   
   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := exp(-2*i*nq*z)/q^(nq^2);
         return m*num_theta3(z, q, tau);
      >>
      else <<
         nq := (nq-1)/2;
         m := exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
	 return m*num_theta2(z, q, tau);
       >>
    else
       if evenp nq then <<
          nq := nq/2;
          m := (-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
          return m*num_theta4(z, q, tau);
       >>
       else <<
          nq := (nq-1)/2;
          m := (-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
          return m*num_theta1(z, q, tau);
       >>;
end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

procedure n_theta4(z, q);
begin scalar n, pow, term, total, tol, m, bound, f;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;
   f := exp (2*abs impart z);
   bound :=1;
   % abs cos(2nz) <= exp (2n abs Im z)

   repeat <<
      pow := (-1)^n*q^(n*n);
      term := pow*cos(2*n*z);
      total := total + term;
      n := n+1;
      bound := bound * f;
      m :=  abs(pow)*bound;
   >> until (total = 0 and m < tol) or m < abs(total)*tol;
   return 1 + 2*total;
end;

procedure num_theta4(z, q, tau);
begin scalar x, m, nt;
   if impart tau > 0.6 then    % i.e. |q| < 0.15
       return n_theta4(z, q);

   m := shift!-tau(tau);
   tau := first m;
   nt := second m;

   if repart  q >= 0 then <<
      % Use Jacobi transformation 
      x := -1/tau;
      q := exp(i*pi*x);
      m := (-i*x)^(1/2)*exp(i*x*z^2/pi);
      return m*(if evenp nt then num_theta2(x*z, q, x)
		else num_theta3(x*z, q, x));
    >>;

   if impart q < 0 then 
      % apply the modular transformation tau' = 1+tau (q' = -q)
      tau := tau+1
   else
      % apply the modular transformation tau' = tau-1 (q' = -q)
      tau := tau-1;

   % then Jacobi's transformation
   x := -1/tau;
   q := exp(i*pi*x);
   m := (-i*x)^(1/2)*exp(i*x*z^2/pi);
   return m*(if evenp nt then num_theta3(x*z, q, x)
             else num_theta2(x*z, q, x));
end;

procedure num1_theta4(z, tau);
begin scalar m, nt;
  m := shift!-tau(tau);
  tau := first m;
  nt := second m;
  % |repart tau| is now < 1
  % Now allow for the effect of the tau shift
  if evenp nt then return num2_theta4(z,tau)
  else return num2_theta3(z,tau);
end;

procedure num2_theta4(z,tau);
begin scalar nr, nq, m, q;
   % It is important to make impart z as small as possible by shifting so
   % that the size of the trigonometric terms in the Fourier series 
   % expansions are kept reasonably small.
   m := shift!-arg(z,tau);
   z:= first m;
   nr := second m;
   nq := third m;
   q := exp(i*pi*tau);

   if evenp nr then
      if evenp nq then <<
         nq := nq/2;
         m := (-1)^nq*exp(-2*i*nq*z)/q^(nq^2);
         return m*num_theta4(z, q, tau);
      >>
      else <<
         nq := (nq-1)/2;
         m := (-1)^nq*i*exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
         return m*num_theta1(z, q, tau);
      >>
   else
      if evenp nq then <<
	 nq := nq/2;
	 m := exp(-2*i*nq*z)/q^(nq^2);
         return m*num_theta3(z, q, tau);
      >>
      else <<
         nq := (nq-1)/2;
	 m := exp(-(2*nq+1)*i*z)/q^(nq^2+nq)*exp(-i*pi*tau/4);
	 return m*num_theta2(z, q, tau);
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
   % parity rules 
   elliptictheta1(-~u,~tau) => -elliptictheta1(u,tau),
   elliptictheta2(-~u,~tau) =>  elliptictheta2(u,tau),
   elliptictheta3(-~u,~tau) =>  elliptictheta3(u,tau),
   elliptictheta4(-~u,~tau) =>  elliptictheta4(u,tau),

   elliptictheta1(0,~tau) => 0,

% numerical evaluation must be performed in complex-rounded mode
% Note impart tau is necessarily > 0 as |q| must be less than 1.

   elliptictheta1(~u,~tau) => n_theta(num1_theta1,u,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

   elliptictheta2(~u,~tau) => n_theta(num1_theta2,u,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

   elliptictheta3(~u,~tau) => n_theta(num1_theta3,u,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

   elliptictheta4(~u,~tau) => n_theta(num1_theta4,u,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

% generalised shift rules added by A Barnes
% periodicity:
   elliptictheta1((~~w + ~~k*pi)/~~d, ~tau) =>
      (begin scalar n, arg, r, s;
          n := fix(2*repart(k/d));
          r := n mod 4;
	  arg := w/d + (k/d-n/2)*pi;
	  if r=2 or r=3 then s := -1 else s := 1;
	  if evenp n then
	     return s*elliptictheta1(arg, tau)
	  else
	     return s*elliptictheta2(arg, tau);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

   elliptictheta2((~~w + ~~k*pi)/~~d, ~tau) =>
      (begin scalar n, arg, r, s;
          n := fix(2*repart(k/d));
          r := n mod 4;
	  arg := w/d + (k/d-n/2)*pi;
	  if r=2 or r=3 then s := -1 else s := 1;
	  if evenp n then
	     return s*elliptictheta2(arg, tau)
	  else
	     return -s*elliptictheta1(arg, tau);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

   elliptictheta3((~~w + ~~k*pi)/~~d, ~tau) =>
      (begin scalar n, arg;
          n := fix(2*repart(k/d));
	  arg := w/d + (k/d-n/2)*pi;
	  if evenp n then
	     return elliptictheta3(arg, tau)
	  else
	     return elliptictheta4(arg, tau);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

   elliptictheta4((~~w + ~~k*pi)/~~d, ~tau) =>
      (begin scalar n, arg;
          n := fix(2*repart(k/d));
	  arg := w/d + (k/d-n/2)*pi;
	  if evenp n then
	     return elliptictheta4(arg, tau)
	  else
	     return elliptictheta3(arg, tau);
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/d)),

% quasi-periodicity:
   elliptictheta1((~~w + ~~k*~tau)/~~d, ~tau) =>
      (begin scalar n, arg, f;
          n := fix(2*repart(k/(pi*d)));
	  arg := w/d + (k/(pi*d)-n/2)*pi*tau;
	  if evenp n then <<
	     n := n/2;
	     f := (-1)^n*exp(-2*i*n*arg)*exp(-i*pi*tau*n^2);
             return f*elliptictheta1(arg, tau);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^n*i*exp(-(2*n+1)*i*arg)*exp(-i*pi*tau*(n^2+n+1/4));
	     return f*elliptictheta4(arg,tau);
	  >>;
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/(pi*d))),

   elliptictheta2((~~w + ~~k*~tau)/~~d, ~tau) =>
      (begin scalar n, arg, f;
          n := fix(2*repart(k/(pi*d)));
	  arg := w/d + (k/(pi*d)-n/2)*pi*tau;
	  if evenp n then <<
	     n := n/2;
	     f := exp(-2*i*n*arg)*exp(-i*pi*tau*n^2);
             return f*elliptictheta2(arg, tau);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := exp(-(2*n+1)*i*arg)*exp(-i*pi*tau*(n^2+n+1/4));
	     return f*elliptictheta3(arg,tau);
	  >>;
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/(pi*d))),

    elliptictheta3((~~w + ~~k*~tau)/~~d, ~tau) =>
       (begin scalar n, arg, f;
           n := fix(2*repart(k/(pi*d)));
 	  arg := w/d + (k/(pi*d)-n/2)*pi*tau;
 	  if evenp n then <<
 	     n := n/2;
 	     f := exp(-2*i*n*arg)*exp(-i*pi*tau*n^2);
              return f*elliptictheta3(arg, tau);
 	  >>
 	  else <<
 	     n := (n-1)/2;
 	     f := exp(-(2*n+1)*i*arg)*exp(-i*pi*tau*(n^2+n+1/4));
 	     return f*elliptictheta2(arg,tau);
 	  >>;
       end)
       when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/(pi*d))),

  elliptictheta4((~~w + ~~k*~tau)/~~d, ~tau) =>
      (begin scalar n, arg, f;
          n := fix(2*repart(k/(pi*d)));
	  arg := w/d + (k/(pi*d)-n/2)*pi*tau;
	  if evenp n then <<
	     n := n/2;
	     f := (-1)^n*exp(-2*i*n*arg)*exp(-i*pi*tau*n^2);
             return f*elliptictheta4(arg, tau);
	  >>
	  else <<
	     n := (n-1)/2;
	     f := (-1)^n*i*exp(-(2*n+1)*i*arg)*exp(-i*pi*tau*(n^2+n+1/4));
	     return f*elliptictheta1(arg, tau);
	  >>;
      end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => 2*repart(k/(pi*d))),

% The next 4 rules implement integer shfts of tau, i.e. iterations of the modular
% transformation tau'=1+tau for which q'=-q. Note that theta1 and theta2 are periodic
% in tau with period 8 whilst theta3 and theta4 have period 2.

   elliptictheta1(~u, (~tau+~k)/~~d) =>
      (begin scalar n, r;
          n := fix(repart(k/d));
	  r := k/d-n;
	  n := n mod 8;
	  return  exp(i*n*pi/4)*elliptictheta1(u, tau/d+r);
      end) when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   elliptictheta2(~u, (~tau+~k)/~~d) =>
      (begin scalar n, r;
          n := fix(repart(k/d));
	  r :=k/d-n;
	  n := n mod 8;
	  return  exp(i*n*pi/4)*elliptictheta2(u, tau/d+r);
      end) when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   elliptictheta3(~u, (~tau+~k)/~~d) =>
      (begin scalar n, r;
          n := fix(repart(k/d));
	  r := k/d-n;
	  if evenp n then return  elliptictheta3(u, tau/d+r)
 	  else return elliptictheta4(u, tau/d+r);
      end) when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   elliptictheta4(~u, (~tau+~k)/~~d) =>
      (begin scalar n, r;
          n := fix(repart(k/d));
	  r := k/d-n;
	  if evenp n then return  elliptictheta4(u, tau/d+r)
 	  else return elliptictheta3(u, tau/d+r);
      end) when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

% The next 4 rules implement Jacobi's modular transformation tau'=-1/tau

   elliptictheta1(~u, -1/~tau) =>
         -i*(-i*tau)^(1/2)*exp(i*tau*u^2/pi)*elliptictheta1(tau*u, tau),

   elliptictheta2(~u, -1/~tau) =>
         (-i*tau)^(1/2)*exp(i*tau*u^2/pi)*elliptictheta4(tau*u, tau),
	 
   elliptictheta3(~u, -1/~tau) =>
         (-i*tau)^(1/2)*exp(i*tau*u^2/pi)*elliptictheta3(tau*u, tau),

   elliptictheta4(~u, -1/~tau) =>
            (-i*tau)^(1/2)*exp(i*tau*u^2/pi)*elliptictheta2(tau*u, tau),
 
   % Below for numerical evaluation it is much better to use theta
   % functions evaluated at zero rather than direct series summations
   % as modular transformations can be used to speed up convergence
   % when |q| is near to one.

   nome2mod(~q) => (((elliptictheta2(0,tau)/elliptictheta3(0,tau))^2)
                       where tau =>-i*log(q)/pi),
	
   nome2mod!'(~q) =>  (((elliptictheta4(tau)/elliptictheta3(0,tau))^2)
                        where tau =>-i*log(q)/pi),
			
   nome2!K(~q) => ((pi*elliptictheta3(0,tau)^2/2)
                       where tau =>-i*log(q)/pi),
		       
   nome2!K!'(~q) => ((-i*tau*pi*elliptictheta3(0,tau)^2/2)
                          where tau =>-i*log(q)/pi)
}$

let ellipticthetarules;

put('elliptictheta1, 'fancy!-functionsymbol,"\vartheta_1");
put('elliptictheta2, 'fancy!-functionsymbol,"\vartheta_2");
put('elliptictheta3, 'fancy!-functionsymbol,"\vartheta_3");
put('elliptictheta4, 'fancy!-functionsymbol,"\vartheta_4");
put('elliptictheta1, 'fancy!-symbol!-length, 4);
put('elliptictheta2, 'fancy!-symbol!-length, 4);
put('elliptictheta3, 'fancy!-symbol!-length, 4);
put('elliptictheta4, 'fancy!-symbol!-length, 4);

put('elliptictheta1, 'plain!-functionsymbol, 'theta1);
put('elliptictheta2, 'plain!-functionsymbol, 'theta2);
put('elliptictheta3, 'plain!-functionsymbol, 'theta3);
put('elliptictheta4, 'plain!-functionsymbol, 'theta4);

put('elliptictheta1, 'prifn, 'plain!-symbol);
put('elliptictheta2, 'prifn, 'plain!-symbol);
put('elliptictheta3, 'prifn, 'plain!-symbol);
put('elliptictheta4, 'prifn, 'plain!-symbol);
put('elliptictau, 'prifn, 'plain!-symbol);

flag('(elliptictheta1 elliptictheta2 elliptictheta3 elliptictheta4),
     'specfn);

deflist('((elliptictheta1 2) (elliptictheta2 2) (elliptictheta3 2)
	  (elliptictheta4 2)
	 ), 'number!-of!-args);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Derivatives of theta functions

procedure n_theta1d(z, d, tau);
% differentiate d times wrt z
if not(fixp d and d>0) then
   rederr("d must be a positve integer: n_theta1d")
else begin scalar n, q, pow, term, total, tol, m, bound, f;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    q := exp(i*pi*tau);

    n := 0;
   bound := exp (abs impart z);
   f := bound^2;
   % abs sin(2n+1 z) <= exp (2n+1 abs Im z)

    repeat <<
       pow := (-1)^n*q^(n*(n+1));
       if evenp d then
          term := (-1)^(d/2)*(2*n+1)^d*pow*sin((2*n+1)*z)
       else
          term := (-1)^((d-1)/2)*(2*n+1)^d*pow*cos((2*n+1)*z);
       total := total + term;
       bound := bound*f; 
       m := (2*n+1)^d*abs(pow)*bound;
       n := n+1;
    >> until (total=0 and m < tol) or m < abs(total)*tol;
    return 2*exp(i*pi*tau/4)*total;
end;    

procedure n_theta2d(z, d, tau);
% differentiate d times wrt z
if not(fixp d and d>0) then
   rederr("d must be a positve integer: n_theta2d")
else begin scalar n, q, pow, term, total, tol, m, bound, f;
    tol := 10.0^-(symbolic !:prec!:);
    total := 0;
    q := exp(i*pi*tau);
    bound := exp (abs impart z);
    f := bound^2;
   % abs sin(2n+1 z) <= exp (2n+1 abs Im z)
    
    n := 0;
    repeat <<
       pow := q^(n*(n+1));
       if evenp d then
          term := (-1)^(d/2)*(2*n+1)^d*pow*cos((2*n+1)*z)
       else
          term := (-1)^((d+1)/2)*(2*n+1)^d*pow*sin((2*n+1)*z);
       total := total +  term; 
       bound := bound*f; 
       m := (2*n+1)^d*abs(pow)*bound;
       n := n+1;
     >> until (total=0 and m < tol) or m < abs(total)*tol;
     return 2*exp(i*pi*tau/4)*total;
end;

procedure n_theta3d(z, d, tau);
% differentiate d times wrt z
if not(fixp d and d>0) then
   rederr("d must be a positve integer: n_theta3d")
else begin scalar n, q, pow, term, total, tol, m, bound, f;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;
   q := exp(i*pi*tau);
   f := exp(2*abs impart z);
   bound :=1;
   repeat <<
      pow := q^(n*n);
      if evenp d then
          term := (-1)^(d/2)*(2*n)^d*pow*cos(2*n*z)
      else
          term := (-1)^((d+1)/2)*(2*n)^d*pow*sin(2*n*z);
      total := total + term;
      bound := bound*f; 
      m := (2*n)^d*abs(pow)*bound;      
      n := n+1;
   >> until (total=0 and m < tol) or m < abs(total)*tol;
   return  2*total;
end;

procedure n_theta4d(z, d, tau);
% differentiate d times wrt z
if not(fixp d and d>0) then
   rederr("d must be a positve integer: n_theta4d")
else begin scalar n, q, pow, term, total, tol, m, bound, f;
   tol := 10.0^-(symbolic !:prec!:);
   total := 0;
   n := 1;
   q := exp(i*pi*tau);
   f := exp(2*abs impart z);
   bound :=1;

   repeat <<
      pow := (-1)^n*q^(n*n);
      if evenp d then
          term := (-1)^(d/2)*(2*n)^d*pow*cos(2*n*z)
      else
          term := (-1)^((d+1)/2)*(2*n)^d*pow*sin(2*n*z);
      total := total + term;
      bound := bound*f; 
      m := (2*n)^d*abs(pow)*bound;
      n := n+1;
   >> until (total=0 and m < tol) or m < abs(total)*tol;
   return 2*total;
end;

procedure n_theta(f,u,tau);
if impart(tau) <= 0 then rederr
  ("2nd parameter of the theta functions must have positive imaginary part")
else num_elliptic(f,u,tau);

procedure n_thetad(f,u,d, tau);
if impart(tau) <= 0 then rederr
  ("3rd parameter of the theta derivs must have positive imaginary part")
else num_elliptic(f,u,d,tau);

operator theta1d, theta2d, theta3d, theta4d;

flag('(n_theta1d n_theta2d n_theta3d n_theta4d), 'specfn);

deflist('((n_theta1d 3) (n_theta2d 3) (n_theta3d 3) (n_theta4d 3)
	 ), 'number!-of!-args);

theta_deriv_rules :=
{
   theta1d(~u,~d,~tau) => n_thetad(n_theta1d,u,d,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

   theta2d(~u,~d,~tau) => n_thetad(n_theta2d,u,d,tau)
        when lisp !*rounded and lisp !*complex
	     and numberp u and numberp tau,

   theta3d(~u,~d,~tau) => n_thetad(n_theta3d,u,d,tau)
        when lisp !*rounded and lisp !*complex 
	     and numberp u and numberp tau,

   theta4d(~u,~d,~tau) => n_thetad(n_theta4d,u,d,tau)
        when lisp !*rounded and lisp !*complex 
	     and numberp u and numberp tau
}$
let theta_deriv_rules$



endmodule;
end;



