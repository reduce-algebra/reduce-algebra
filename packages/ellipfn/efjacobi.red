module efjacobi;  % Procedures and Rules for Jacobi Elliptic functions.

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

% $Id: sfellip.red 6190 2021-12-12 17:45:30Z barnesa1 $
% Substantial revisions by Alan Barnes, 2019
% Renamed (was sfellip) and moved to a new package ellipfn, December 2021 

% In the original version the parameter m in the Jacobi functions
% is the square of the modulus; in the revised version m is everywhere
% the modulus, this accords with standard notation (at least in UK).
% See e.g.: DF Lawden, Elliptic Functions & Applications, Springer-Verlag
% (App Math Sci series #80) 1989

% Correction of several of the original rules below
% Some optimisations of the numerical code to avoid repeated computations.

% Generalised shift rules added to remove integer multiples of K and i*K'
% from arguments of the Jacobi elliptic functions.  This renders most of
% the rules for special arguments redundant.

algebraic;

% moved to efnumeric.red by AB Feb 2022
%% ARITHMETIC GEOMETRIC MEAN
%% 
%% CALCULATING PHI
%%

%Increases the precision used to evaluate algebraic arguments.

%% symbolic procedure  n_elliptic (u);

%% %###################################################################### 

%JACOBI FUNCTIONS
operator jacobiam, jacobisn, jacobicn, jacobidn;
operator jacobie, jacobins, jacobinc, jacobind;
operator jacobizeta, jacobisc, jacobisd, jacobics;
operator jacobids, jacobicd, jacobidc;
operator elliptick, elliptick!', elliptice, elliptice!';

%JACOBI AMPLITUDE

procedure n_jacam(z, k);
   % computes Jacobi Amplitude from its Fourier series
   % It fails to converge if Im z is not small -- if q*exp(2*abs Imz) >1
   % which is equivalent to Im z > K'.
   % Rounding errors are  large near to this limiting value
begin scalar n, pow, term, total, tol, m, bound, f, kp, kk, q;
   tol := 10.0^-(symbolic !:prec!:);
   kp := num_ellkc(k);
   kk := num_ellk(k);
   q := exp(-pi*kp/kk);
   z := pi*z/(2*kk);
   n := 1;
   total := z;
   bound := exp abs impart z;
   f := bound^2;
    % abs sin(2nz) <= exp (2n abs Im z)
    repeat <<
       pow := q^n;
       pow := pow/(n*(1+pow^2));
       term := 2*pow*sin(2*n*z);
       total := total + term;
       n := n+1;
       bound := bound * f;
       m :=  abs(pow)*bound;
    >> until (total = 0 and m < tol) or m < abs(total)*tol;
    return total;
end;    

%This computes the Amplitude of u.

procedure num_jacobiam(u,m);
   % produces results in agreement with Fourier Series method for
   % real arguments and also when Im u is small.
   % Moreover sn(u,k) = sin am(u,k) holds in these cases
   % However this identity fails for larger  ie. Im u > K'
   % Also rounding errors become large when Im u is near to K'
     first phi_function(1,sqrt(1-m^2),m,u);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

jacobiamrules :=

{
   jacobiam(~u,0)   => u,
   jacobiam(~u,1)   => asin tanh u,
   jacobiam(-~u,~m) => -jacobiam(u,m),
   jacobiam(~u,-~m) => jacobiam(u,m),
   jacobiam(0,~m) => 0,
       
   df(jacobiam(~u,~m),~x)  => jacobidn(u,m)*df(u,x) +
        df(m,x)*(u*jacobidn(u,m)/m +
	   (m*jacobisn(u,m)*jacobicn(u,k) -jacobie(u,m)*jacobidn(u,m)/m) /
	   (1-m^2)),      

   jacobiam(~u,~m) =>
     num_elliptic(num_jacobiam, u, m)
       	when lisp !*rounded and lisp !*complex and numberp u and numberp m
}$

let jacobiamrules;

%######################################################################
%Jacobisn definition
%===================

%This rule list includes all the special cases of the Jacobisn
%function.

jacobisnrules :=
{
% When m=0 or 1, Change of Parameter
%----------------------------------
   jacobisn(~u,0)   => sin u,
   jacobisn(~u,1)   => tanh u,
   jacobisn(-~u,~m) => -jacobisn(u,m),
   jacobisn(~u,-~m) => jacobisn(u,m),
   jacobisn(0,~m) => 0,
   jacobisn(ellipticK(~k)/2,~k) => 1/sqrt(1+sqrt(1-k^2)),
   jacobisn(i*ellipticK!'(~k)/2,~k) => i/sqrt(k),
   jacobisn(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
      (sqrt(1+k)+i*sqrt(1-k))/sqrt(2*k),
   % the following are necessary if the rules jacobisn(~u,-~k)
   % and ellipticK(-~k) are applied  before those immediately above
       
% generalised shift rules added by A Barnes
   jacobisn((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobisn(arg, m)
	 else
	    return s*jacobicd(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

    jacobisn((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if evenp shift then
	    return jacobisn(arg, m)
	 else
	    return jacobins(arg, m)/m;
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

        jacobisn(i*~~u/~~d,~m) => i*jacobisc(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
        df(jacobisn(~u,~m),~x)  => jacobicn(u,m)*jacobidn(u,m)*df(u,x)+
	          df(m,x)*((m*jacobisn(u,m)*jacobicn(u,m)^2
                            -jacobie(u,m)*jacobicn(u,m)*jacobidn(u,m)/m)/(1-m^2)
                           + u*jacobicn(u,m)*jacobidn(u,m)/m),

        int(jacobisn(~u,~m),~u) => log(jacobidn(u,m)-m*jacobicn(u,m))/m,

%Calls Num_Jacobisn when the rounded switch is on.
%-------------------------------------------------
        jacobisn(~u,~m) => num_elliptic(num_jacobisn, u, m)
	   when lisp !*rounded and lisp !*complex and
                numberp u and numberp m
}$
let jacobisnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobicn definition
%===================

%This rule list includes all the special cases of the Jacobicn
%function.

jacobicnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobicn(~u,0)   => cos u,
   jacobicn(~u,1)   => sech u,
   jacobicn(~u,-~m) => jacobicn(u,m),
   jacobicn(-~u,~m) => jacobicn (u,m),
   jacobicn(0,~m) => 1,
   jacobicn(ellipticK(~k)/2,~k) => sqrt(sqrt(1-k^2))/sqrt(1+sqrt(1-k^2)),
   jacobicn(i*ellipticK!'(~k)/2,~k) => sqrt(1+k)/sqrt(k),
   jacobicn(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
       (1-i)*sqrt sqrt(1-k^2)/sqrt(2*k),         

% generalised shift rules added by A Barnes

 jacobicn((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobicn(arg, m)
	 else
	    return -s*jacobisd(arg, m)*sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

 jacobicn((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobicn(arg, m)
	 else
	    return -i*s*jacobids(arg, m)/m;
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

%Change of Argument

        jacobicn(i*~~u/~~d,~m) => jacobinc(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
        df(jacobicn(~u,~m),~x)  => -jacobisn(u,m)*jacobidn(u,m)*df(u,x) +
 	          df(m,x)*((jacobie(u,m)*jacobisn(u,m)*jacobidn(u,m)/m
	                    - m*jacobisn(u,m)^2*jacobicn(u,m))/(1-m^2)
                           - u*jacobisn(u,m)*jacobidn(u,m)/m),

        int(jacobicn(~u,~m),~u) => asin(m*jacobisn(u,m))/m,
	
% The following commented out rule is also correct
%       int(jacobicn(~u,~m),~u) => acos(jacobidn(u,m))/m,

%Calls Num_Jacobicn when rounded switch is on.
%---------------------------------------------
        jacobicn(~u,~m) => num_elliptic(num_jacobicn, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m

}$
let jacobicnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidn definition
%===================

%This rule list includes all the special cases of the Jacobidn
%function.

jacobidnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobidn(~u,0)   => 1,
   jacobidn(~u,1)   => sech u,
   jacobidn(~u,-~m) => jacobidn(u,m),
   jacobidn(-~u,~m) => jacobidn(u,m),
   jacobidn(0,~m) => 1,
   jacobidn(ellipticK(~k)/2,~k) => sqrt(sqrt(1-k^2)),
   jacobidn(i*ellipticK!'(~k)/2,~k) => sqrt(1+k),
   jacobidn(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
      % sqrt sqrt(1-k^2)*(sqrt(1+sqrt(1-k^2))-i*sqrt(1-sqrt(1-k^2)))/sqrt 2,
      % the above is from DLMF: 22.5 and incorrect in some cases.
      % The following is simpler and uses the third of (2.2.29) of Lawden
      % with u=-(K+iK')/2. It appears to be correct in all cases.
      sqrt sqrt(1-k^2)*(sqrt(1-k)-i*sqrt(1+k))/(1-i),
   
% Shift rules
   jacobidn((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return jacobidn(arg, m)
	 else
	    return sqrt(1-m^2)*jacobind(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   jacobidn((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobidn(arg, m)
	 else
	    return -i*jacobics(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

       jacobidn(i*~~u/~~d,~m) => jacobidc(u/d,sqrt(1-m^2)),
       
%Derivatives, Intergal
%---------------------
        df(jacobidn(~u,~m),~x)  => -m**2 *jacobisn(u,m)*jacobicn(u,m)*df(u,x) +
	          df(m,x)*(m*(jacobie(u,m)*jacobisn(u,m)*jacobicn(u,m)
                              - jacobisn(u,m)^2*jacobidn(u,m))/(1-m^2)
                           - m*u*jacobisn(u,m)*jacobicn(u,m)),

        int(jacobidn(~u,~m),~u) => asin(jacobisn(u,m)),
	

%Calls Num_Jacobidn when rounded switch is on.
%---------------------------------------------
        jacobidn(~u,~m) => num_elliptic(num_jacobidn, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m

}$
let jacobidnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Jacobicd 
%=========

%This rule list includes all the special cases of the Jacobicd
%function.

jacobicdrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobicd(~u,0)   => cos u,
   jacobicd(~u,1)   => 1,
   jacobicd(~u,-~m) => jacobicd(u,m),
   jacobicd(-~u,~m) => jacobicd(u,m),
   jacobicd(0,~m)   => 1,
   jacobicd(ellipticK(~k)/2,~k) => 1/sqrt(1+sqrt(1-k^2)),
   jacobicd(i*ellipticK!'(~k)/2,~k) => 1/sqrt(k),
   jacobicd(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
%      (1-i)*(sqrt(1+sqrt(1-k^2))+i*sqrt(1-sqrt(1-k^2)))/(2*sqrt(2*k)),
       (sqrt(1+k)-i*sqrt(1-k))/sqrt(2*k),
   % above uses the third of (2.2.17) of Lawden with u = -(K+iK')/2
   
 jacobicd((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobicd(arg, m)
	 else
	    return s*jacobisn(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

 jacobicd((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if evenp shift then
	    return jacobicd(arg, m)
	 else
	    return jacobidc(arg, m)/m;
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobicd(i*~~u/~~d,~m) => jacobind(u/d,sqrt(1-m^2)),
      
%Derivatives,Integral
%--------------------
   df(jacobicd(~u,~m),~x) =>
        -(1 - m^2)*jacobisd(u,m)*jacobind(u,m)*df(u,x) +
        df(m,x)*(jacobisn(u,m)*(jacobie(u,m)-u*(1-m^2))/(m*jacobidn(u,m)^2)),

   int(jacobicd(~u,~m),~u) => log(jacobind(u,m) + m*jacobisd(u,m))/m,

%Calls Num_Jacobicd when rounded switch is on.
%---------------------------------------------
        jacobicd(~u,~m) => num_elliptic(num_jacobicd, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m

}$
let jacobicdrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisd definition
%===================

%This rule list includes all the special cases of the Jacobisd
%function.

jacobisdrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobisd(~u,0)   => sin u,
   jacobisd(~u,1)   => sinh u,
   jacobisd(~u,-~m) => jacobisd(u,m),
   jacobisd(-~u,~m) => -jacobisd(u,m),
   jacobisd(0,~m)   => 0,
   jacobisd(ellipticK(~k)/2,~k) =>
      1/(sqrt(1+sqrt(1-k^2))*sqrt(sqrt(1-k^2))),
   jacobisd(i*ellipticK!'(~k)/2,~k) => i/(sqrt(k)*sqrt(1+k)),
   jacobisd(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
%      (sqrt(1+k)+i*sqrt(1-k))*(sqrt(1+sqrt(1-k^2))+i*sqrt(1-sqrt(1-k^2)))/
%	 (2*sqrt sqrt(1-k^2)*sqrt k),
      (1+i)/(sqrt(2*k)*sqrt sqrt(1-k^2)),
  	 
% Shift rules
   jacobisd((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return s*jacobisd(arg, m)
	 else
	    return s*jacobicn(arg, m)/sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   jacobisd((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobisd(arg, m)
	 else
	    return s*i*jacobinc(arg, m)/m;
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobisd(i*~~u/~~d,~m) => i*jacobisd(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
  df(jacobisd(~u,~k),~x) => jacobicd(u,k)*jacobind(u,k)*df(u,x) +
      df(k,x)*((-jacobicn(u,k)*jacobie(u,k)+jacobicn(u,k)*u*(1-k^2) +
         jacobidn(u,k)*jacobisn(u,k)*k^2)/(jacobidn(u,k)^2*k*(1-k^2))),
	
   int(jacobisd(~u,~m),~u) => -asin(m*jacobicd(u,m))/(m*sqrt(1-m^2)),

%Calls Num_Jacobisd when rounded switch is on.
%---------------------------------------------
        jacobisd(~u,~m) => num_elliptic(num_jacobisd, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobisdrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobind definition
%===================

%This rule list includes all the special cases of the Jacobind
%function.

jacobindrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobind(~u,0)   => 1,
   jacobind(~u,1)   => cosh u,
   jacobind(~u,-~m) => jacobind(u,m),
   jacobind(-~u,~m) => jacobind(u,m),
   jacobind(0,~m)   => 1,
   jacobind(ellipticK(~k)/2,~k) => 1/sqrt(sqrt(1-k^2)),
   jacobind(i*ellipticK!'(~k)/2,~k) => 1/sqrt(1+k),
   jacobind(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
%     (sqrt(1+sqrt(1-k^2))+i*sqrt(1-sqrt(1-k^2)))/sqrt(2*sqrt(1-k^2)),
      (1-i)*(sqrt(1-k)+i*sqrt(1+k))/(2*sqrt sqrt(1-k^2)),
   
%Change of Argument

   jacobind((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return jacobind(arg, m)
	 else
	    return jacobidn(arg, m)/sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),


   jacobind((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobind(arg, m)
	 else
	    return i*jacobisc(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

    jacobind(i*~~u/~~d,~m) => jacobicd(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
    df(jacobind(~u,~m),~x) =>
	   df(u,x)*m^2*jacobisd(u,m)*jacobicd(u,m) +
	   df(m,x)*(-(m*(jacobie(u,m)*jacobisn(u,m)*jacobicn(u,m)
                       -jacobisn(u,m)^2*jacobidn(u,m))/(1-m^2)
                    - m*u*jacobisn(u,m)*jacobicn(u,m))/jacobidn(u,m)^2),

    int(jacobind(~u,~m),~u) =>acos(jacobicd(u,m))/sqrt(1-m^2),

%Calls Num_Jacobind when rounded switch is on.
%---------------------------------------------
        jacobind(~u,~m) => num_elliptic(num_jacobind, u, m)
	   when lisp !*rounded and lisp !*complex and
        	numberp u and numberp m
}$
let jacobindrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidc definition
%===================

%This rule list includes all the special cases of the Jacobidc
%function.

jacobidcrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobidc(~u,0)   => sec u,
   jacobidc(~u,1)   => 1,
   jacobidc(~u,-~m) => jacobidc(u,m),
   jacobidc(-~u,~m) => jacobidc(u,m),
   jacobidc(0,~m)   => 1,
   jacobidc(ellipticK(~k)/2,~k) => sqrt(1+sqrt(1-k^2)),
   jacobidc(i*ellipticK!'(~k)/2,~k) => sqrt(k),
   jacobidc(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
%      (1+i)*sqrt(k)*(sqrt(1+sqrt(1-k^2))-i*sqrt(1-sqrt(1-k^2)))/sqrt(2),
       sqrt(k)*(sqrt(1+k)+i*sqrt(1-k))/sqrt 2,
   % above uses the third of (2.2.17) of Lawden with u = -(K+iK')/2
   
   jacobidc((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return s*jacobidc(arg, m)
	 else
	    return s*jacobins(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   jacobidc((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
 	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if evenp shift then
	    return jacobidc(arg, m)
	 else
	    return m*jacobicd(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobidc(i*~~u/~~d,~m) => jacobidn(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobidc(~u,~k),~x) => (1-k^2)*jacobisc(u,k)*jacobinc(u,k)*df(u,x) +
         df(k,x)*(-jacobisn(u,k)*(jacobie(u,k)-u*(1-k^2))/(jacobicn(u,k)^2*k)),

   int(jacobidc(~u,~m),~u) => log(jacobinc(u,m) + jacobisc(u,m)),

%Calls Num_Jacobidc when rounded switch is on.
%---------------------------------------------
        jacobidc(~u,~m) => num_elliptic(num_jacobidc, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobidcrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobinc definition
%===================

%This rule list includes all the special cases of the Jacobinc
%function.

jacobincrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobinc(~u,0)   => sec u,
   jacobinc(~u,1)   => cosh u,
   jacobinc(~u,-~m) => jacobinc(u,m),
   jacobinc(-~u,~m) => jacobinc(u,m),
   jacobinc(0,~m)   => 1,
   jacobinc(ellipticK(~k)/2,~k) => sqrt(1+sqrt(1-k^2))/sqrt(sqrt(1-k^2)),
   jacobinc(i*ellipticK!'(~k)/2,~k) => sqrt(k)/sqrt(1+k),
   jacobinc(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
      sqrt(k/2)*(1+i)/sqrt sqrt(1-k^2),

%Change of Argument

   jacobinc((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobinc(arg, m)
	 else
	    return -s*jacobids(arg, m)/sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

  jacobinc((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobinc(arg, m)
	 else
	    return m*i*s*jacobisd(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobinc(i*~~u/~~d,~m) => jacobicn(u/d,sqrt(1-m^2)),
   
%Derivatives, Integral
%---------------------
    df(jacobinc(~u,~m),~x) => jacobisc(u,m)*jacobidc(u,m)*df(u,x) +
	     df(m,x)*(-((jacobie(u,m)*jacobisn(u,m)*jacobidn(u,m)/m
	                 - m*jacobisn(u,m)^2*jacobicn(u,m))/(1-m^2)
                       -u*jacobisn(u,m)*jacobidn(u,m)/m)/jacobicn(u,m)^2),

    int(jacobinc(~u,~m),~u) =>
            log(jacobidc(u,m)+sqrt(1-m^2)*jacobisc(u,m))/sqrt(1-m^2),

%Calls Num_Jacobinc when rounded switch is on.
%---------------------------------------------
        jacobinc(~u,~m) => num_elliptic(num_jacobinc, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m

}$
let jacobincrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisc definition
%===================

%This rule list includes all the special cases of the Jacobisc
%function.

jacobiscrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobisc(~u,0)   => tan u,
   jacobisc(~u,1)   => sinh u,
   jacobisc(~u,-~m) => jacobisc(u,m),
   jacobisc(-~u,~m) => -jacobisc(u,m),
   jacobisc(0,~m)   => 0,
   jacobisc(ellipticK(~k)/2,~k) => 1/sqrt(sqrt(1-k^2)),
   jacobisc(i*ellipticK!'(~k)/2,~k) => i/sqrt(1+k),
   jacobisc(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
      (1+i)*(sqrt(1+k)+i*sqrt(1-k))/(2*sqrt sqrt(1-k^2)),

% generalised shift rules added by A Barnes
   jacobisc((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return jacobisc(arg, m)
	 else
	    return -jacobics(arg, m)/sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

    jacobisc((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if evenp shift then
	    return s*jacobisc(arg, m)
	 else
	    return s*i*jacobind(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobisc(i*~~u/~~d,~m) => i*jacobisn(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
    df(jacobisc(~u,~k),~x) => jacobidc(u,k)*jacobinc(u,k)*df(u,x) +
	df(k,x)*((jacobidn(u,k)*u*(1-k^2) - jacobidn(u,k)*jacobie(u,k)
	         +jacobisn(u,k)*jacobicn(u,k)*k^2)/(jacobicn(u,k)^2*k*(1-k^2))),
	
    int(jacobisc(~u,~m),u) =>
            log(jacobidc(u,m)+sqrt(1-m^2)*jacobinc(u,m))/sqrt(1-m^2),

%Calls Num_Jacobisc when rounded switch is on.
%---------------------------------------------
        jacobisc(~u,~m) => num_elliptic(num_jacobisc, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobiscrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobins definition
%===================

%This rule list includes all the special cases of the Jacobins
%function.

jacobinsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobins(~u,0)   => csc u,
   jacobins(~u,1)   => coth u,
   jacobins(~u,-~m) => jacobins(u,m),
   jacobins(-~u,~m) => -jacobins(u,m),
   jacobins(0,~m)   => 1/jacobisn(0,m),     % pole
   jacobins(ellipticK(~k)/2,~k) => sqrt(1+sqrt(1-k^2)),
   jacobins(i*ellipticK!'(~k)/2,~k) => -i*sqrt(k),
   jacobins(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
        sqrt(2*k)/(sqrt(1+k)+i*sqrt(1-k)),

%Change of Argument

   jacobins((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobins(arg, m)
	 else
	    return s*jacobidc(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   jacobins((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix impart(k/d);
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if evenp shift then
	    return jacobins(arg, m)
	 else
	    return jacobisn(arg, m)/m;
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

    jacobins(i*~~u/~~d,~m) => -i*jacobics(u/d,sqrt(1-m^2)),
    
%Derivatives, Integral
%---------------------
    df(jacobins(~u,~m),~x) => -jacobids(u,m)*jacobics(u,m)*df(u,x) -
	    df(m,x)*((m*jacobisn(u,m)*jacobicn(u,m)^2
                      -jacobie(u,m)*jacobicn(u,m)*jacobidn(u,m)/m)/(1-m^2)
                     + u*jacobicn(u,m)*jacobidn(u,m)/m)/jacobisn(u,m)^2,
	
    int(jacobins(~u,~m),~u) => log(jacobids(u,m) - jacobics(u,m)),

%Calls Num_Jacobins when rounded switch is on.
%---------------------------------------------
        jacobins(~u,~m) => num_elliptic(num_jacobins, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobinsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobids definition
%===================

%This rule list includes all the special cases of the Jacobids
%function.

jacobidsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobids(~u,0)   => csc u,
   jacobids(~u,1)   => csch u,
   jacobids(~u,-~m) => jacobids(u,m),
   jacobids(-~u,~m) => -jacobids(u,m),
   jacobids(0,~m)   => 1/jacobisd(0,m),      % pole
   jacobids(ellipticK(~k)/2,~k) => sqrt(sqrt(1-k^2))*sqrt(1+sqrt(1-k^2)),
   jacobids(i*ellipticK!'(~k)/2,~k) => -i*sqrt(k)*sqrt(1+k),
   jacobids(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
%      sqrt sqrt(1-k^2)*sqrt k*(sqrt(1+k)-i*sqrt(1-k))*
%      (sqrt(1+sqrt(1-k^2))-i*sqrt(1-sqrt(1-k^2)))/2,
      (1-i)*sqrt(k/2)*sqrt sqrt(1-k^2),
	 
   jacobids((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix repart(k/d);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
 	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return s*jacobids(arg, m)
	 else
	    return s*jacobinc(arg, m)*sqrt(1-m^2);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

   jacobids((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
         r := shift mod 4;
	 arg := w/d + ((k/d)-i*shift)*elliptick(m);
	 if r=2 or r=3 then s := -1 else s := 1;
	 if evenp shift then
	    return s*jacobids(arg, m)
	 else
	    return -s*i*m*jacobicn(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobids(i*~~u/~~d,~m) => -i*jacobids(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobids(~u,~k),~x) => -jacobics(u,k)*jacobins(u,k)*df(u,x) +
       df(k,x)*((jacobicn(u,k)*jacobie(u,k)-u*jacobicn(u,k)*(1-k^2) -
	         jacobidn(u,k)*jacobisn(u,k)*k^2)/(jacobisn(u,k)^2*k*(1-k^2))),

   int(jacobids(~u,~m),~u) => log(jacobins(u,m) - jacobics(u,m)),

%Calls Num_Jacobids when on rounded switch is on.
%------------------------------------------------
        jacobids(~u,~m) => num_elliptic(num_jacobids, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobidsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobics definition
%===================
%This rule list includes all the special cases of the Jacobics function.

jacobicsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
   jacobics(~u,0)   => cot u,
   jacobics(~u,1)   => csch u,
   jacobics(~u,-~m) => jacobics(u,m),
   jacobics(-~u,~m) =>-jacobics(u,m),
   jacobics(0,~m)   => 1/jacobisc(0,m),      % pole
   jacobics(ellipticK(~k)/2,~k) => sqrt(sqrt(1-k^2)),
   jacobics(i*ellipticK!'(~k)/2,~k) => -i*sqrt(1+k),
   jacobics(ellipticK(~k)/2+i*ellipticK!'(~k)/2, ~k) =>
      (1-i)*sqrt sqrt(1-k^2)*(sqrt(1+k)-i*sqrt(1-k))/2,

% generalised shift rules added by A Barnes
   jacobics((~~w + ~~k*elliptick(~m))/~~d, ~m) =>
      (begin scalar shift, arg;
         shift := fix repart(k/d);
	 arg := w/d + ((k/d)-shift)*elliptick(m);
	 if evenp shift then
	    return jacobics(arg, m)
	 else
	    return -sqrt(1-m^2)*jacobisc(arg, m);
	end)
      when ((ratnump(rp) and abs(rp) >= 1) where rp => repart(k/d)),

    jacobics((~~w + ~~k*elliptick!'(~m))/~~d, ~m) =>
      (begin scalar shift, arg, r, s;
         shift := fix impart(k/d);
	 r := shift mod 4;
	 if r=2 or r=3 then s := -1 else s := 1;
	 arg := w/d + ((k/d)-i*shift)*elliptick!'(m);
	 if evenp shift then
	    return s*jacobics(arg, m)
	 else
	    return -s*i*jacobidn(arg, m);
	end)
      when ((ratnump(ip) and abs(ip) >= 1) where ip => impart(k/d)),

   jacobics(i*~~u/~~d,~m) => -i*jacobins(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobics(~u,~k),~x) => -jacobins(u,k)*jacobids(u,k)*df(u,x) -
       df(k,x)*((jacobidn(u,k)*u*(1-k^2) - jacobidn(u,k)*jacobie(u,k)
                 +jacobisn(u,k)*jacobicn(u,k)*k^2)/(jacobisn(u,k)^2*k*(1-k^2))),
	      
   int(jacobics(~u,~m),~u) => log(jacobins(u,m) - jacobids(u,m)),

%Calls Num_Jacobics when rounded switch is on.
%---------------------------------------------
        jacobics(~u,~m) => num_elliptic(num_jacobics, u, m)
	   when lisp !*rounded and lisp !*complex and
	        numberp u and numberp m
}$
let jacobicsrules;

% Numerical evaluation for general arguments is by theta functions.
% Added December 2022 by A. Barnes

algebraic procedure k2nome(k);
   if k=0 then 0
   else if k=1 or k=-1 then 1
   else exp(i*pi*k2tau(k));

%% % This version needs switches rounded and complex to be on except
%% % when k is purely real and 0 < |k| < 1.
algebraic procedure k2tau(k);
   if k=0 or k=1 or k=-1 then
      rederr("tau not defined when k=0, +1 or -1")
   else i*ellipticK!'(k)/ellipticK(k);

% The following need switches rounded and complex to be ON
% %%%%%%%%%%%%%%%%%%%%%%%%% MORE CHECKING NEEDED %%%%%%%%%%%%%%%%%%%%%%%%%%%
algebraic procedure num_jacobisn(x,k);
   if k = 0 then sin x
   else if k=1 or k=-1 then tanh x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return t3*num1_theta1(y,tau)/
	        (num1_theta2(0,tau)*num1_theta4(y,tau));
   end;

algebraic procedure num_jacobins(x,k);
   if k = 0 then csc x
   else if k=1 or k=-1 then coth x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta2(0,tau)*num1_theta4(y,tau)/
	        (t3*num1_theta1(y,tau));
   end;

algebraic procedure num_jacobicn(x,k);
   if k = 0 then cos x
   else if k=1 or k=-1 then sech x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta4(0,tau)*num1_theta2(y,tau)/
                (num1_theta2(0,tau)*num1_theta4(y,tau));
   end;

algebraic procedure num_jacobinc(x,k);
   if k = 0 then sec x
   else if k=1 or k=-1 then cosh x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta2(0,tau)*num1_theta4(y,tau)/
               (num1_theta4(0,tau)*num1_theta2(y,tau));
   end;

algebraic procedure num_jacobidn(x,k);
   if k = 0 then 1
   else if k=1 or k=-1 then sech x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta4(0,tau)*num1_theta3(y,tau)/
                 (t3*num1_theta4(y,tau));
   end;

algebraic procedure num_jacobind(x,k);
   if k = 0 then 1
   else if k=1 or k=-1 then cosh x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return t3*num1_theta4(y,tau)/
               (num1_theta4(0,tau)*num1_theta3(y,tau));
   end;

algebraic procedure num_jacobisc(x,k);
   if k = 0 then tan x
   else if k=1 or k=-1 then sinh x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return t3*num1_theta1(y,tau)/
	        (num1_theta4(0,tau)*num1_theta2(y,tau));
   end;

algebraic procedure num_jacobics(x,k);
  if k = 0 then cot x
   else if k=1 or k=-1 then csch x
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta4(0,tau)*num1_theta2(y,tau)/
	        (t3*num1_theta1(y,tau));
   end;

algebraic procedure num_jacobisd(x,k);
  if k = 0 then sin x
   else if k=1 or k=-1 then sinh x
   else if impart k = 0 and impart x = 0 and abs k <1 then
      num_jacobisd1(x,k)  % use old AGM-based method
   else begin scalar tau, t32, y;
      tau := k2tau(k);
      t32 := num1_theta3(0,tau)^2;
      y := x/t32;
      return t32*num1_theta1(y,tau)/
               (num1_theta4(0,tau)*num1_theta2(0,tau)*num1_theta3(y,tau));
   end;

algebraic procedure num_jacobids(x,k);
  if k = 0 then csc x
   else if k=1 or k=-1 then csch x
   else begin scalar tau, t32, y;
      tau := k2tau(k);
      t32 := num1_theta3(0,tau)^2;
      y := x/t32;
      return num1_theta4(0,tau)*num1_theta2(0,tau)*num1_theta3(y,tau)/
                 (t32*num1_theta1(y,tau));
   end;

algebraic procedure num_jacobicd(x,k);
  if k = 0 then cos x
   else if k=1 or k=-1 then 1
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return t3*num1_theta2(y,tau)/
	        (num1_theta2(0,tau)*num1_theta3(y,tau));
   end;

algebraic procedure num_jacobidc(x,k);
  if k = 0 then sec x
   else if k=1 or k=-1 then 1
   else begin scalar tau, t3, y;
      tau := k2tau(k);
      t3 := num1_theta3(0,tau);
      y := x/t3^2;
      return num1_theta2(0,tau)*num1_theta3(y,tau)/
	        (t3*num1_theta2(y,tau));
   end;

% some utility rule sets added December 2021 by Alan Barnes

% Use Pythagorean identities relating sn^2, cn^2 and dn^2. At most one
% of the three rules should be active at any one time.
to_sn := {jacobicn(~x,~k)^2 => 1-jacobisn(x,k)^2,
          jacobidn(~x,~k)^2 => 1-k^2*jacobisn(x,k)^2};
to_cn := {jacobisn(~x,~k)^2 => 1-jacobicn(x,k)^2,
          jacobidn(~x,~k)^2 => 1-k^2+k^2*jacobicn(x,k)^2};
to_dn := {jacobisn(~x,~k)^2 => (1-jacobidn(x,k)^2)/k^2,
          jacobicn(~x,~k)^2 => (k^2-1+jacobidn(x,k)^2)/k^2}$

% remove reciprocal and quotient Jacobi functions
no_glaisher :={jacobins(~x,~k) => 1/jacobisn(x,k),
               jacobinc(~x,~k) => 1/jacobicn(x,k),
               jacobind(~x,~k) => 1/jacobidn(x,k),
               jacobisc(~x,~k) => jacobisn(x,k)/jacobicn(x,k),
               jacobisd(~x,~k) => jacobisn(x,k)/jacobidn(x,k),
               jacobics(~x,~k) => jacobicn(x,k)/jacobisn(x,k),
               jacobicd(~x,~k) => jacobicn(x,k)/jacobidn(x,k),
               jacobids(~x,~k) => jacobidn(x,k)/jacobisn(x,k),
               jacobidc(~x,~k) => jacobidn(x,k)/jacobicn(x,k)}$

% All addition and duplication rules moved to a new list from individual
% function rule lists.
% NB the rules are not activated by default. A. Barnes December 2022

jacobiadditionrules := {
   jacobisn((~u + ~v)/~~d,~m) =>
      ( jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m)
	 + jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m))
	    / (1-m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

   jacobisn(2*~u,~m) =>
                2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) 
                / (1-m^2*jacobisn(u,m)^4),
   
   jacobisn(~u/2,~m) => sqrt(1-jacobicn(u,m))/sqrt(1+jacobidn(u,m))
                       when u neq i*elliptick!'(k),

   jacobicn((~u + ~v)/~~d,~m) =>
      ( jacobicn(u/d,m)*jacobicn(v/d,m)
	 -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m))
	    / (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

   jacobicn(2*~u,~m) =>
                (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2 )
                / (1- m^2*jacobisn(u,m)^4),
   
   jacobicn(~u/2,~m) =>
	     sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1+jacobidn(u,m))
	           when u neq i*elliptick!'(m),

   jacobidn((~u + ~v)/~~d,~m) =>
      ( jacobidn(u/d,m)*jacobidn(v/d,m)
	 -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m))
	    / (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

   jacobidn(2*~u,~m) =>
             (  jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2 )
                / (1- m^2*jacobisn(u,m)^4),
   
   jacobidn(~u/2,~m) =>
	      sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

   jacobins((~u + ~v)/~~d,~m) =>
%%       (1-m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
%% 	 (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m)
%% 	    + jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),
      (jacobins(u/d,m)^2*jacobins(v/d,m)^2 - m^2) /
	 (jacobins(u/d,m)*jacobics(v/d,m)*jacobids(v/d,m)
	    + jacobins(v/d,m)*jacobics(u/d,m)*jacobids(u/d,m)),

    jacobins(2*~u,~m) => (1-m^2*jacobisn(u,m)^4) /
                           (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)), 
   
    jacobins(~u/2,~m) => sqrt(1+jacobidn(u,m))/sqrt(1-jacobicn(u,m))
	                        when u neq i*elliptick!'(k),
				
   jacobinc((~u + ~v)/~~d,~m) =>
%%      (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
%%        (jacobicn(u/d,m)*jacobicn(v/d,m)
%%          -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)),
      (jacobinc(u/d,m)^2*jacobinc(v/d,m)^2
      	 - m^2*jacobisc(u/d,m)^2*jacobisc(v/d,m)^2) /
       	    (jacobinc(u/d,m)*jacobinc(v/d,m)
             -jacobisc(u/d,m)*jacobidc(u/d,m)*jacobisc(v/d,m)*jacobidc(v/d,m)),

   jacobinc(2*~u,~m) =>
          (1- m^2*jacobisn(u,m)^4) /
              (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),

   jacobinc(~u/2,~m) =>
           sqrt(1+jacobidn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

   jacobind((~u + ~v)/~~d,~m) =>
%%      (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
%%        (jacobidn(u/d,m)*jacobidn(v/d,m)
%% 	- m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),
      (jacobind(u/d,m)^2*jacobind(v/d,m)^2
         - m^2*jacobisd(u/d,m)^2*jacobisd(v/d,m)^2) /
      (jacobind(u/d,m)*jacobind(v/d,m)
        - m^2*jacobisd(u/d,m)*jacobicd(u/d,m)*jacobisd(v/d,m)*jacobicd(v/d,m)),

    jacobind(2*~u,~m) =>
        (1- m^2*jacobisn(u,m)^4) /
           (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),

    jacobind(~u/2,~m) =>
	      sqrt(1+jacobicn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
 	           when u neq i*elliptick!'(m),

   jacobisc((~u + ~v)/~~d,~m) =>
%%        (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
%%             jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)) /
%%        (jacobicn(u/d,m)*jacobicn(v/d,m)
%%          -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m) ),
      (jacobisc(u/d,m)*jacobinc(u/d,m)*jacobidc(v/d,m) +
	 jacobisc(v/d,m)*jacobinc(v/d,m)*jacobidc(u/d,m)) /
       	    (jacobinc(u/d,m)*jacobinc(v/d,m)
              -jacobisc(u/d,m)*jacobidc(u/d,m)*jacobisc(v/d,m)*jacobidc(v/d,m)),

   jacobisc(2*~u,~m) =>
       2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) /
         (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),
   
   jacobisc(~u/2,~m) =>
         sqrt(1-jacobicn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

   jacobisd((~u + ~v)/~~d,~m) =>
%%       (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
%%             jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)) /
%%       (jacobidn(u/d,m)*jacobidn(v/d,m)
%%        -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),
   (jacobisd(u/d,m)*jacobind(u/d,m)*jacobicd(v/d,m) +
            jacobisd(v/d,m)*jacobind(v/d,m)*jacobicd(u/d,m)) /
      (jacobind(u/d,m)*jacobind(v/d,m)
        -m^2*jacobisd(u/d,m)*jacobicd(u/d,m)*jacobisd(v/d,m)*jacobicd(v/d,m)),

    jacobisd(2*~u,~m) =>
       2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) /
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),
   
   jacobisd(~u/2,~m) =>
       jacobisn(u,m)/(sqrt(1+jacobidn(u,m))*sqrt(jacobidn(u,m)+jacobicn(u,m)))
	           when u neq i*elliptick!'(m),

   jacobics((~u + ~v)/~~d,~m) =>
%%        (jacobicn(u/d,m)*jacobicn(v/d,m)
%%          -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m) ) /
%%        (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
%%             jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),
      (jacobics(u/d,m)*jacobics(v/d,m)*jacobins(u/d,m)*jacobins(v/d,m)
         - jacobids(u/d,m)*jacobids(v/d,m)) /
       	    (jacobins(u/d,m)*jacobics(v/d,m)*jacobids(v/d,m) +
               jacobins(v/d,m)*jacobics(u/d,m)*jacobids(u/d,m)),

   jacobics(2*~u,~m) =>
       (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2) /
         (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)),
   
   jacobics(~u/2,~m) =>
         sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1-jacobicn(u,m))
	           when u neq i*elliptick!'(m),
		   
   jacobids((~u + ~v)/~~d,~m) =>
%%     (jacobidn(u/d,m)*jacobidn(v/d,m)
%%       -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m))/
%%       (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
%%             jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),
      (jacobids(u/d,m)*jacobids(v/d,m)*jacobins(u/d,m)*jacobins(v/d,m)
         -m^2*jacobics(u/d,m)*jacobics(v/d,m))/
      	    (jacobins(u/d,m)*jacobics(v/d,m)*jacobids(v/d,m) +
               jacobins(v/d,m)*jacobics(u/d,m)*jacobids(u/d,m)),

    jacobids(2*~u,~m) =>
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2) /
        (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)),

   jacobids(~u/2,~m) =>
       sqrt(1+jacobidn(u,m))*sqrt(jacobidn(u,m)+jacobicn(u,m))/jacobisn(u,m)
	           when u neq i*elliptick!'(m),

   jacobicd((~u + ~v)/~~d,~m) =>
%%       (jacobicn(u/d,m)*jacobicn(v/d,m)
%%         - jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)) /
%%       (jacobidn(u/d,m)*jacobidn(v/d,m)
%%        -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),
     (jacobicd(u/d,m)*jacobicd(v/d,m)*jacobind(u/d,m)*jacobind(v/d,m)
        -jacobisd(u/d,m)*jacobisd(v/d,m)) /
        (jacobind(u/d,m)*jacobind(v/d,m)
         -m^2*jacobisd(u/d,m)*jacobicd(u/d,m)*jacobisd(v/d,m)*jacobicd(v/d,m)),

   jacobicd(2*~u,~m) =>
        (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2) /
         (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),
   
   jacobicd(~u/2,~m) =>
	     sqrt(1+jacobicn(u,m))/sqrt(1+jacobidn(u,m))
 	         when u neq i*elliptick!'(m),

   jacobidc((~u + ~v)/~~d,~m) =>
%%     (jacobidn(u/d,m)*jacobidn(v/d,m)
%%      -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)) /
%% 	(jacobicn(u/d,m)*jacobicn(v/d,m)
%%         - jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)),
     (jacobidc(u/d,m)*jacobidc(v/d,m)*jacobinc(u/d,m)*jacobinc(v/d,m)
       	 -m^2*jacobisc(u/d,m)*jacobisc(v/d,m)) /
	   (jacobinc(u/d,m)*jacobinc(v/d,m)
            - jacobisc(u/d,m)*jacobidc(u/d,m)*jacobisc(v/d,m)*jacobidc(v/d,m)),

   jacobidc(2*~u,~m) =>
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2) / 
         (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),

   jacobidc(~u/2,~m) =>
	     sqrt(1+jacobidn(u,m))/sqrt(1+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

   % quasi-addition
   jacobie((~u+~v)/~~d,~m) => jacobie(u/d,m) + jacobie(v/d,m)
      - m^2*jacobisn(u/d,m)*jacobisn(v/d,m)*jacobisn((u+v)/d,m),

   jacobie(2*~u,~m) =>
          2*jacobie(u,m) - m^2*jacobisn(u,m)^2*jacobisn(2*u,m),
	  
   jacobizeta((~u+~v)/~~d,~m) => jacobizeta(u/d,m) + jacobizeta(v/d,m)
      - m^2*jacobisn(u/d,m)*jacobisn(v/d,m)*jacobisn((u+v)/d,m),

   jacobizeta(2*~u,~m) =>
             2*jacobizeta(u,m) - m^2*jacobisn(u,m)^2*jacobisn(2*u,m)
	 
   }$

symbolic;

put('jacobisn,'fancy!-functionsymbol,"\mathrm{sn}");
put('jacobicn,'fancy!-functionsymbol,"\mathrm{cn}");
put('jacobidn,'fancy!-functionsymbol,"\mathrm{dn}");
put('jacobins,'fancy!-functionsymbol,"\mathrm{ns}");
put('jacobinc,'fancy!-functionsymbol,"\mathrm{nc}");
put('jacobind,'fancy!-functionsymbol,"\mathrm{nd}");
put('jacobisc,'fancy!-functionsymbol,"\mathrm{sc}");
put('jacobisd,'fancy!-functionsymbol,"\mathrm{sd}");
put('jacobicd,'fancy!-functionsymbol,"\mathrm{cd}");
put('jacobics,'fancy!-functionsymbol,"\mathrm{cs}");
put('jacobids,'fancy!-functionsymbol,"\mathrm{ds}");
put('jacobidc,'fancy!-functionsymbol,"\mathrm{dc}");
put('jacobiam,'fancy!-functionsymbol,"\mathrm{am}");
put('jacobizeta,'fancy!-functionsymbol,"\mathrm{Z}");

% CSL GUI does not support \mathcal
% if memq('showmath, lispsystem!*) then
   % Note "\Epsilon" prints as E
%   put('jacobie,'fancy!-functionsymbol,"\epsilon")
% else
   put('jacobie,'fancy!-functionsymbol,"\mathcal{E}");
   
put('jacobisn,'plain!-functionsymbol,'sn);
put('jacobicn,'plain!-functionsymbol,'cn);
put('jacobidn,'plain!-functionsymbol,'dn);
put('jacobins,'plain!-functionsymbol,'ns);
put('jacobinc,'plain!-functionsymbol,'nc);
put('jacobind,'plain!-functionsymbol,'nd);
put('jacobisc,'plain!-functionsymbol,'sc);
put('jacobisd,'plain!-functionsymbol,'sd);
put('jacobicd,'plain!-functionsymbol,'cd);
put('jacobics,'plain!-functionsymbol,'cs);
put('jacobids,'plain!-functionsymbol,'ds);
put('jacobidc,'plain!-functionsymbol,'dc);
put('jacobiam,'plain!-functionsymbol,'am);
put('jacobizeta,'plain!-functionsymbol,'!Z);
put('jacobie,'plain!-functionsymbol, "E_j");

put('elliptice, 'plain!-functionsymbol, '!E);
put('ellipticd, 'plain!-functionsymbol, '!D);
put('elliptick, 'plain!-functionsymbol, '!K);
put('ellipticf, 'plain!-functionsymbol, '!F);
put('elliptick!', 'plain!-functionsymbol, '!K!');
put('elliptice!', 'plain!-functionsymbol,  '!E!');
put('ellipticpi, 'plain!-functionsymbol,  '!Pi);

put('elliptice, 'fancy!-functionsymbol, "\mathrm{E}");
put('ellipticd, 'fancy!-functionsymbol, "\mathrm{D}");
put('elliptick, 'fancy!-functionsymbol, "\mathrm{K}");
put('ellipticf, 'fancy!-functionsymbol, "\mathrm{F}");
put('elliptick!', 'fancy!-functionsymbol,  "\mathrm{K}^\prime");
put('elliptice!', 'fancy!-functionsymbol,  "\mathrm{E}^\prime");
put('ellipticpi, 'fancy!-functionsymbol,  "\Pi");

put('elliptice!', 'fancy!-symbol!-length, 4);
put('elliptick!', 'fancy!-symbol!-length, 4);


foreach x in '(jacobisn  jacobicn  jacobidn jacobins  jacobinc  jacobind
               jacobisc  jacobisd  jacobicd jacobics  jacobids  jacobidc
	       jacobiam)
do << put(x, 'fancy!-symbol!-length, 4);
      put(x, 'prifn, 'plain!-symbol)
   >>;

put('elliptice, 'prifn, 'plain!-symbol);
put('ellipticd, 'prifn, 'plain!-symbol);
put('elliptick, 'prifn, 'plain!-symbol);
put('elliptick!', 'prifn, 'plain!-symbol);
put('elliptice!', 'prifn, 'plain!-symbol);
put('ellipticf, 'prifn, 'plain!-symbol);
put('ellipticpi, 'prifn, 'plain!-symbol);
put('jacobizeta, 'prifn, 'plain!-symbol);
put('jacobie, 'prifn, 'plain!-symbol);

% Moved to mprint.red so it may be used by other modules.
% symbolic procedure plain!-symbol(u);
%     maprin(get(car u,'plain!-functionsymbol) . cdr u);

% The next 2 declarations enable better checking of number of arguments
% by simpiden

flag('(jacobisn jacobicn jacobidn jacobins jacobinc jacobind 
       jacobisc jacobisd jacobics jacobicd jacobids jacobidc
       jacobiam jacobizeta jacobie ellipticK ellipticK!'
       ellipticF ellipticE ellipticE!' ellipticD), 'specfn);

deflist('((jacobisn 2) (jacobicn 2) (jacobidn 2)
          (jacobins 2) (jacobinc 2) (jacobind 2) (jacobisc 2) (jacobisd 2)
	  (jacobics 2) (jacobicd 2) (jacobids 2) (jacobidc 2) (jacobiam 2)
	  (ellipticF 2)  (jacobiZeta 2) (jacobie 2) (ellipticK 1)
	  (ellipticK!' 1) (ellipticE (1 2)) (ellipticE!' 1) (ellipticD (1 2))
	  (ellipticPi (2 3))	
	 ), 'number!-of!-args);

endmodule;
end;
