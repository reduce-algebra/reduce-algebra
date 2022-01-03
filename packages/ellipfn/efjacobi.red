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

%ARITHMETIC GEOMETRIC MEAN

%The following procedure is the process of the Arithmetic Geometric
%Mean.

procedure agm_function(a0,b0,c0);
begin scalar n, an, bn, cn, alist, clist, tol;
     tol := 10.0^-(symbolic !:prec!:);
     cn    := 20; % To initiate while loop below.
     alist := {a0}$
     clist := {c0}$

     while abs(cn) > tol do <<
         an := (a0 + b0)/2;
         bn := sqrt(a0*b0);
         cn := (a0 - b0)/2;

         alist := an.alist;
         clist := cn.clist;
         % Note no need to accumulate bn's

         a0 := an;
         b0 := bn
      >>;

     n := length(alist) - 1;

     return {n, alist, clist};

end;

%######################################################################
%CALCULATING PHI
%               N


%The following procedure sucessively computes phi   ,phi   ,...,phi ,
%                                                N-1    N-2        0
%from the recurrence relation:
%
%       sin(2phi    - phi ) = (c /a )sin phi
%               N-1      N       N  N          N
%
%and returns a list of phi  to phi . This list is then used in the
%                        0        N
%calculation of Jacobisn, Jacobicn, Jacobidn, which in turn are used
%to calculate the remaining twelve Jacobi Functions.


procedure phi_function(a0,b0,c0,u);
begin scalar agm, alist, clist, n, an, cn, phi_n, phi_list;

    agm   := agm_function(a0,b0,c0);
    alist := second agm;
    clist := third agm;
    n :=  first agm;
    an :=  first alist; 
    phi_n := (2^n)*an*u;
    phi_list := {phi_n};

    while rest alist neq {} do <<
        an := first alist;
        cn := first clist;

        phi_n := (asin(cn/an*sin phi_n) + phi_n) / 2;
        phi_list := phi_n.phi_list;
        alist := rest alist;
	clist := rest clist;
    >>;
    return phi_list;
end;

%######################################################################
%JACOBI FUNCTIONS

%Increases the precision used to evaluate algebraic arguments.

symbolic procedure  n_elliptic (u);
% check that length u >= 2 !
 if length u < 2 then
         rederr "illegal call to n_elliptic" else
   begin scalar oldprec,res;
     oldprec := precision 0;
     precision max(oldprec,15);

    res :=  aeval u;
    precision oldprec;
    return res;

  end;

put('num_elliptic, 'psopfn, 'n_elliptic);

%######################################################################
%JACOBI AMPLITUDE


%This computes the Amplitude of u.

procedure num_jacobiam(u,m);
     first phi_function(1,sqrt(1-m^2),m,u);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

operator jacobiam;
operator jacobisn;
operator jacobicn;
operator jacobidn;
operator elliptick!';
operator elliptick;
operator jacobie;
operator elliptice;
operator elliptice!';

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
       when lisp !*rounded and numberp repart u and numberp impart u
             and numberp repart m and numberp impart m
}$

let jacobiamrules;

%######################################################################
%This procedure is called by Jacobisn when the on rounded switch is
%used. It evaluates the value of Jacobisn numerically.


procedure num_jacobisn(u,m);
    sin first phi_function(1,sqrt(1-m^2),m,u);


%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

%Change of argument

        jacobisn((~u + ~v)/~~d,~m) =>
                ( jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m)
                  + jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m) )
                / (1-m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

        jacobisn(2*~u,~m) =>
                2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) 
                / (1-m^2*jacobisn(u,m)^4),

	jacobisn(i*elliptick!'(~m)/2,~m) => i/sqrt(m),
				
        jacobisn(~u/2,~m) => sqrt(1-jacobicn(u,m))/sqrt(1+jacobidn(u,m))
	                        when u neq i*elliptick!'(k),

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
                when lisp !*rounded and numberp repart u and numberp repart m
                     and numberp impart u and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobisnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicn when the on rounded switch is
%used. It evaluates the value of Jacobicn numerically.

procedure num_jacobicn(u,m);
    cos first phi_function(1,sqrt(1-m^2),m,u);
 
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
%------------------
        jacobicn((~u + ~v)/~~d,~m) =>
           ( jacobicn(u/d,m)*jacobicn(v/d,m)
             -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m) )
                / (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

        jacobicn(2*~u,~m) =>
                (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2 )
                / (1- m^2*jacobisn(u,m)^4),

        jacobicn(i*elliptick!'(~m)/2,~m) => sqrt(1+m)/sqrt(m),
	
        jacobicn(~u/2,~m) =>
	     sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1+jacobidn(u,m))
	           when u neq i*elliptick!'(m),

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
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobicnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidn when the on rounded switch is
%used. It evaluates the value of Jacobidn numerically.

procedure num_jacobidn(u,m);
   begin scalar phi, phi0,  phi1, denom;
        phi  := phi_function(1,sqrt(1-m^2),m,u);
        phi0 := first phi;
        phi1 := second phi;
        denom := cos(phi1 - phi0);

        if denom < 10.0^(-(symbolic !:prec!:)) then  return otherdn(u,m)
        else return cos(phi0)/denom;
   end;

procedure otherdn(u,m);
   begin scalar mu, approx, v;
        m := sqrt(1-m^2);
        m := (1-m)/(1+m);
        u  := u/(1+m);
	approx := (1 - (m * sin u)^2/2)^2;
        return (approx - 1+m)/(1+m - approx);
   end;


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

%Change of Argument

      jacobidn((~u + ~v)/~~d,~m) =>
         ( jacobidn(u/d,m)*jacobidn(v/d,m)
           -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m))
                / (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2),

        jacobidn(2*~u,~m) =>
                (  jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2 )
                / (1- m^2*jacobisn(u,m)^4),

        jacobidn(i*elliptick!'(~m)/2,~m) => sqrt(1+m),
	
        jacobidn(~u/2,~m) =>
	      sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

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
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobidnrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicd when the on rounded switch is
%used. It evaluates the value of Jacobicd numerically.

procedure num_jacobicd(u,m);
   begin scalar phi, phi0,  phi1, dendn;
        phi  := phi_function(1,sqrt(1-m^2),m,u);
        phi0 := first phi;
        phi1 := second phi;
        dendn := cos(phi1 - phi0);

        if dendn < 10.0^(-(symbolic !:prec!:)) then
	   return cos(phi0)/otherdn(u,m)
        else return dendn;
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobicd definition
%===================

operator jacobicd;

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

%Change of Argument

   jacobicd((~u + ~v)/~~d,~m) =>
      (jacobicn(u/d,m)*jacobicn(v/d,m)
          - jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)) /
      (jacobidn(u/d,m)*jacobidn(v/d,m)
        -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),

   jacobicd(2*~u,~m) =>
        (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2) /
         (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),

   jacobicd(i*elliptick!'(~m)/2,~m) => 1/sqrt(m),

   jacobicd(~u/2,~m) =>
	     sqrt(1+jacobicn(u,m))/sqrt(1+jacobidn(u,m))
 	         when u neq i*elliptick!'(m),

%    jacobicd(~u/2,~m) => 1/jacobidc(u/2,m),

   jacobicd(i*~~u/~~d,~m) => jacobind(u/d,sqrt(1-m^2)),
      
%Derivatives,Integral
%--------------------
   df(jacobicd(~u,~m),~x) => -(1 - m^2)*jacobisn(u,m)/jacobidn(u,m)^2*df(u,x) +
        df(m,x)*(jacobisn(u,m)*(jacobie(u,m)-u*(1-m^2))/(m*jacobidn(u,m)^2)),

   int(jacobicd(~u,~m),~u) => log(jacobind(u,m) + m*jacobisd(u,m))/m,

%Calls Num_Jacobicd when rounded switch is on.
%---------------------------------------------
        jacobicd(~u,~m) => num_elliptic(num_jacobicd, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobicdrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisd when the on rounded switch is
%used. It evaluates the value of Jacobisd numerically.

procedure num_jacobisd(u,m);
   begin scalar phi, phi0,  phi1, denom, jdn;
        phi  := phi_function(1,sqrt(1-m^2),m,u);
        phi0 := first phi;
        phi1 := second phi;
        denom := cos(phi1 - phi0);

        if denom < 10.0^(-(symbolic !:prec!:)) then  jdn := otherdn(u,m)
        else jdn := cos(phi0)/denom;
	return sin(phi0)/jdn;
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisd definition
%===================

operator jacobisd;

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

%Change of Argument

   jacobisd((~u + ~v)/~~d,~m) =>
      (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
            jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)) /
      (jacobidn(u/d,m)*jacobidn(v/d,m)
        -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),

   jacobisd(2*~u,~m) =>
       2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) /
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),

   jacobisd(i*elliptick!'(~m)/2,~m) => i/(sqrt(m)*sqrt(1+m)),

   jacobisd(~u/2,~m) =>
       jacobisn(u,m)/(sqrt(1+jacobidn(u,m))*sqrt(jacobidn(u,m)+jacobicn(u,m)))
	           when u neq i*elliptick!'(m),

%    jacobisd(~u/2,~m) => 1/jacobids(u/2,m),

   jacobisd(i*~~u/~~d,~m) => i*jacobisd(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobisd(~u,~k),~x) => jacobicn(u,k)/jacobidn(u,k)^2*df(u,x) +
      df(k,x)*((-jacobicn(u,k)*jacobie(u,k)+jacobicn(u,k)*u*(1-k^2) +
         jacobidn(u,k)*jacobisn(u,k)*k^2)/(jacobidn(u,k)^2*k*(1-k^2))),
	
   int(jacobisd(~u,~m),~u) => -asin(m*jacobicd(u,m))/(m*sqrt(1-m^2)),

%Calls Num_Jacobisd when rounded switch is on.
%---------------------------------------------
        jacobisd(~u,~m) => num_elliptic(num_jacobisd, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobisdrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobind when the on rounded switch is
%used. It evaluates the value of Jacobind numerically.

procedure num_jacobind(u,m);
   1 / num_jacobidn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobind definition
%===================

operator jacobind;

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


   jacobind((~u + ~v)/~~d,~m) =>
     (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
       (jacobidn(u/d,m)*jacobidn(v/d,m)
	- m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)),

    jacobind(2*~u,~m) =>
        (1- m^2*jacobisn(u,m)^4) /
           (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2),

    jacobind(i*elliptick!'(~m)/2,~m) => 1/sqrt(1+m),

    jacobind(~u/2,~m) =>
	      sqrt(1+jacobicn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
 	           when u neq i*elliptick!'(m),

%    jacobind(~u/2,~m) => 1/jacobidn(u/2,m),

    jacobind(i*~~u/~~d,~m) => jacobicd(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
    df(jacobind(~u,~m),~x) =>
	   df(u,x)*m^2*jacobisn(u,m)*jacobicn(u,m)/jacobidn(u,m)^2 +
	   df(m,x)*(-(m*(jacobie(u,m)*jacobisn(u,m)*jacobicn(u,m)
                       -jacobisn(u,m)^2*jacobidn(u,m))/(1-m^2)
                    - m*u*jacobisn(u,m)*jacobicn(u,m))/jacobidn(u,m)^2),

    int(jacobind(~u,~m),~u) =>acos(jacobicd(u,m))/sqrt(1-m^2),

%Calls Num_Jacobind when rounded switch is on.
%---------------------------------------------
        jacobind(~u,~m) => num_elliptic(num_jacobind, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0
}$
let jacobindrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidc when the on rounded switch is
%used. It evaluates the value of Jacobidc numerically.

procedure num_jacobidc(u,m);
     1/num_jacobicd(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidc definition
%===================

operator jacobidc;

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

%Change of Argument

   jacobidc((~u + ~v)/~~d,~m) =>
      (jacobidn(u/d,m)*jacobidn(v/d,m)
       -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m)) /
	(jacobicn(u/d,m)*jacobicn(v/d,m)
          - jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)),

   jacobidc(2*~u,~m) =>
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2) / 
         (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),

   jacobidc(i*elliptick!'(~m)/2,~m) => sqrt(m),

   jacobidc(~u/2,~m) =>
	     sqrt(1+jacobidn(u,m))/sqrt(1+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

   jacobidc(i*~~u/~~d,~m) => jacobidn(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobidc(~u,~k),~x) => (1-k^2)*jacobisn(u,k)/jacobicn(u,k)^2*df(u,x) +
         df(k,x)*(-jacobisn(u,k)*(jacobie(u,k)-u*(1-k^2))/(jacobicn(u,k)^2*k)),

   int(jacobidc(~u,~m),~u) => log(jacobinc(u,m) + jacobisc(u,m)),

%Calls Num_Jacobidc when rounded switch is on.
%---------------------------------------------
        jacobidc(~u,~m) => num_elliptic(num_jacobidc, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobidcrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobinc when the on rounded switch is
%used. It evaluates the value of Jacobinc numerically.

procedure num_jacobinc(u,m);
    1 / num_jacobicn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobinc definition
%===================

operator jacobinc;

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


%Change of Argument

   jacobinc((~u + ~v)/~~d,~m) =>
     (1 - m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
       (jacobicn(u/d,m)*jacobicn(v/d,m)
         -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m)),

   jacobinc(2*~u,~m) =>
          (1- m^2*jacobisn(u,m)^4) /
              (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),

   jacobinc(i*elliptick!'(~m)/2,~m) => sqrt(m)/sqrt(1+m),

   jacobinc(~u/2,~m) =>
           sqrt(1+jacobidn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

%    jacobinc(~u/2,~m) => 1/jacobicn(u/2,m),

   jacobinc(i*~~u/~~d,~m) => jacobicn(u/d,sqrt(1-m^2)),
   
%Derivatives, Integral
%---------------------
    df(jacobinc(~u,~m),~x) =>
	   jacobisn(u,m)*jacobidn(u,m)/jacobicn(u,m)^2*df(u,x) +
	     df(m,x)*(-((jacobie(u,m)*jacobisn(u,m)*jacobidn(u,m)/m
	                 - m*jacobisn(u,m)^2*jacobicn(u,m))/(1-m^2)
                       -u*jacobisn(u,m)*jacobidn(u,m)/m)/jacobicn(u,m)^2),

    int(jacobinc(~u,~m),~u) =>
            log(jacobidc(u,m)+sqrt(1-m^2)*jacobisc(u,m))/sqrt(1-m^2),

%Calls Num_Jacobinc when rounded switch is on.
%---------------------------------------------
        jacobinc(~u,~m) => num_elliptic(num_jacobinc, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobincrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisc when the on rounded switch is
%used. It evaluates the value of Jacobisc numerically.

procedure num_jacobisc(u,m);
    tan first phi_function(1,sqrt(1-m^2),m,u);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisc definition
%===================

operator jacobisc;

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

%Change of Argument

   jacobisc((~u + ~v)/~~d,~m) =>
       (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
            jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)) /
       (jacobicn(u/d,m)*jacobicn(v/d,m)
         -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m) ),

   jacobisc(2*~u,~m) =>
       2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) /
         (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2),

   jacobisc(i*elliptick!'(~m)/2,~m) => i/sqrt(1+m),

   jacobisc(~u/2,~m) =>
         sqrt(1-jacobicn(u,m))/sqrt(jacobidn(u,m)+jacobicn(u,m))
	           when u neq i*elliptick!'(m),

%    jacobisc(~u/2,~m) => 1/jacobics(u/2,m),
   
   jacobisc(i*~~u/~~d,~m) => i*jacobisn(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
    df(jacobisc(~u,~k),~x) => jacobidn(u,k)/jacobicn(u,k)^2*df(u,x) +
	df(k,x)*((jacobidn(u,k)*u*(1-k^2) - jacobidn(u,k)*jacobie(u,k)
	         +jacobisn(u,k)*jacobicn(u,k)*k^2)/(jacobicn(u,k)^2*k*(1-k^2))),
	
    int(jacobisc(~u,~m),u) =>
            log(jacobidc(u,m)+sqrt(1-m^2)*jacobinc(u,m))/sqrt(1-m^2),

%Calls Num_Jacobisc when rounded switch is on.
%---------------------------------------------
        jacobisc(~u,~m) => num_elliptic(num_jacobisc, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobiscrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobins when the on rounded switch is
%used. It evaluates the value of Jacobins numerically.

procedure num_jacobins(u,m);
     1 / num_jacobisn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobins definition
%===================

operator jacobins;

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

%Change of argument

    jacobins((~u + ~v)/~~d,~m) =>
       (1-m^2*jacobisn(u/d,m)^2*jacobisn(v/d,m)^2) /
	      (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m)
                + jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),
	       
    jacobins(2*~u,~m) => (1-m^2*jacobisn(u,m)^4) /
                           (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)), 

    jacobins(i*elliptick!'(~m)/2,~m) => -i*sqrt(m),

    jacobins(~u/2,~m) => sqrt(1+jacobidn(u,m))/sqrt(1-jacobicn(u,m))
	                        when u neq i*elliptick!'(k),
				
%     jacobins(~u/2,~m) => 1/jacobisn(u/2, m),
    
    jacobins(i*~~u/~~d,~m) => -i*jacobics(u/d,sqrt(1-m^2)),
    
%Derivatives, Integral
%---------------------
    df(jacobins(~u,~m),~x) =>
	   -jacobidn(u,m)*jacobicn(u,m)/jacobisn(u,m)^2*df(u,x) -
	    df(m,x)*((m*jacobisn(u,m)*jacobicn(u,m)^2
                      -jacobie(u,m)*jacobicn(u,m)*jacobidn(u,m)/m)/(1-m^2)
                     + u*jacobicn(u,m)*jacobidn(u,m)/m)/jacobisn(u,m)^2,
	
    int(jacobins(~u,~m),~u) => log(jacobids(u,m) - jacobics(u,m)),

%Calls Num_Jacobins when rounded switch is on.
%---------------------------------------------
        jacobins(~u,~m) => num_elliptic(num_jacobins, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobinsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobids when the on rounded switch is
%used. It evaluates the value of Jacobids numerically.

procedure num_jacobids(u,m);
      1/num_jacobisd(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobids definition
%===================

operator jacobids;

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

%Change of Argument

   jacobids((~u + ~v)/~~d,~m) =>
      (jacobidn(u/d,m)*jacobidn(v/d,m)
        -m^2*jacobisn(u/d,m)*jacobicn(u/d,m)*jacobisn(v/d,m)*jacobicn(v/d,m))/
      (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
            jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),

   jacobids(2*~u,~m) =>
       (jacobidn(u,m)^2 - m^2*jacobisn(u,m)^2*jacobicn(u,m)^2) /
        (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)),

   jacobids(i*elliptick!'(~m)/2,~m) => -i*sqrt(m)*sqrt(1+m),

   jacobids(~u/2,~m) =>
       sqrt(1+jacobidn(u,m))*sqrt(jacobidn(u,m)+jacobicn(u,m))/jacobisn(u,m)
	           when u neq i*elliptick!'(m),

   jacobids(i*~~u/~~d,~m) => -i*jacobids(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobids(~u,~k),~x) => -jacobicn(u,k)/jacobisn(u,k)^2*df(u,x) +
       df(k,x)*((jacobicn(u,k)*jacobie(u,k)-u*jacobicn(u,k)*(1-k^2) -
	         jacobidn(u,k)*jacobisn(u,k)*k^2)/(jacobisn(u,k)^2*k*(1-k^2))),

   int(jacobids(~u,~m),~u) => log(jacobins(u,m) - jacobics(u,m)),

%Calls Num_Jacobids when on rounded switch is on.
%------------------------------------------------
        jacobids(~u,~m) => num_elliptic(num_jacobids, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobidsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobics when the on rounded switch is
%used. It evaluates the value of Jacobics numerically.

procedure num_jacobics(u,m);
    cot first phi_function(1,sqrt(1-m^2),m,u);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobics definition
%===================

operator jacobics;

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

%Change of Argument

   jacobics((~u + ~v)/~~d,~m) =>
       (jacobicn(u/d,m)*jacobicn(v/d,m)
         -jacobisn(u/d,m)*jacobidn(u/d,m)*jacobisn(v/d,m)*jacobidn(v/d,m) ) /
       (jacobisn(u/d,m)*jacobicn(v/d,m)*jacobidn(v/d,m) +
            jacobisn(v/d,m)*jacobicn(u/d,m)*jacobidn(u/d,m)),

   jacobics(2*~u,~m) =>
       (jacobicn(u,m)^2 - jacobisn(u,m)^2*jacobidn(u,m)^2) /
         (2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m)),

   jacobics(i*elliptick!'(~m)/2,~m) => -i*sqrt(1+m),

   jacobics(~u/2,~m) =>
         sqrt(jacobidn(u,m)+jacobicn(u,m))/sqrt(1-jacobicn(u,m))
	           when u neq i*elliptick!'(m),
		   
   jacobics(i*~~u/~~d,~m) => -i*jacobins(u/d,sqrt(1-m^2)),

%Derivatives, Integral
%---------------------
   df(jacobics(~u,~k),~x) => -jacobidn(u,k)/jacobisn(u,k)^2*df(u,x) -
       df(k,x)*((jacobidn(u,k)*u*(1-k^2) - jacobidn(u,k)*jacobie(u,k)
                 +jacobisn(u,k)*jacobicn(u,k)*k^2)/(jacobisn(u,k)^2*k*(1-k^2))),
	      
   int(jacobics(~u,~m),~u) => log(jacobins(u,m) - jacobids(u,m)),

%Calls Num_Jacobics when rounded switch is on.
%---------------------------------------------
        jacobics(~u,~m) => num_elliptic(num_jacobics, u, m)
                when lisp !*rounded and numberp repart u and numberp impart u
                     and numberp repart m and numberp impart m
%                           when lisp !*rounded and numberp u
%                           and numberp m and impart(u) = 0

}$
let jacobicsrules;

% some utility rule sets added December 2021 by Alan Barnes

% Use Pythagorean identities relating sn^2, cn^2 and dn^2. At most one
% of the three rules should be active at any one time.
to_sn := {jacobicn(~x,~k)^2 => 1-jacobisn(x,k)^2,
          jacobidn(~x,~k)^2 => 1-k^2*jacobisn(x,k)^2};
to_cn := {jacobisn(~x,~k)^2 => 1-jacobicn(x,k)^2,
          jacobidn(~x,~k)^2 => 1-k^2+k^2*jacobicn(x,k)^2};
to_dn := {jacobisn(~x,~k)^2 => (1-jacobidn(x,k)^2)/k^2,
          jacobicn(~x,~k)^2 => (k^2-1+jacobidn(x,k)^2)/k^2};

% remove reciprocal and quotient Jacobi functions
no_glaisher :={jacobins(~x,~k) => 1/jacobisn(x,k),
               jacobinc(~x,~k) => 1/jacobicn(x,k),
               jacobind(~x,~k) => 1/jacobidn(x,k),
               jacobisc(~x,~k) => jacobisn(x,k)/jacobicn(x,k),
               jacobisd(~x,~k) => jacobisn(x,k)/jacobidn(x,k),
               jacobics(~x,~k) => jacobicn(x,k)/jacobisn(x,k),
               jacobicd(~x,~k) => jacobicn(x,k)/jacobidn(x,k),
               jacobids(~x,~k) => jacobidn(x,k)/jacobisn(x,k),
               jacobidc(~x,~k) => jacobidn(x,k)/jacobicn(x,k)};

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
put('elliptick, 'plain!-functionsymbol, '!K);
put('ellipticf, 'plain!-functionsymbol, '!F);
put('elliptick!', 'plain!-functionsymbol, '!K!');
put('elliptice!', 'plain!-functionsymbol,  '!E!');

% put('ellipticd, 'fancy!-functionsymbol, "\mathrm{D}");
put('elliptice, 'fancy!-functionsymbol, "\mathrm{E}");
put('elliptick, 'fancy!-functionsymbol, "\mathrm{K}");
put('ellipticf, 'fancy!-functionsymbol, "\mathrm{F}");
put('elliptick!', 'fancy!-functionsymbol,  "\mathrm{K}^\prime");
put('elliptice!', 'fancy!-functionsymbol,  "\mathrm{E}^\prime");
put('elliptice!', 'fancy!-symbol!-length, 4);
put('elliptick!', 'fancy!-symbol!-length, 4);


foreach x in '(jacobisn  jacobicn  jacobidn jacobins  jacobinc  jacobind
               jacobisc  jacobisd  jacobicd jacobics  jacobids  jacobidc
	       jacobiam)
do << put(x, 'fancy!-symbol!-length, 4);
      put(x, 'prifn, 'plain!-symbol)
   >>;

put('elliptice, 'prifn, 'plain!-symbol);
put('elliptick, 'prifn, 'plain!-symbol);
put('elliptick!', 'prifn, 'plain!-symbol);
put('elliptice!', 'prifn, 'plain!-symbol);
put('ellipticf, 'prifn, 'plain!-symbol);
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
       ellipticF ellipticE ellipticE!'), 'specfn);

deflist('((jacobisn 2) (jacobicn 2) (jacobidn 2)
          (jacobins 2) (jacobinc 2) (jacobind 2) (jacobisc 2) (jacobisd 2)
	  (jacobics 2) (jacobicd 2) (jacobids 2) (jacobidc 2) (jacobiam 2)
	  (ellipticF 2)  (jacobiZeta 2) (jacobie 2)
	  (ellipticK 1) (ellipticK!' 1) (ellipticE (1 2)) (ellipticE!' 1)
	 ), 'number!-of!-args);

endmodule;
end;
