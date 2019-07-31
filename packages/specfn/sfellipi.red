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

   begin scalar alpha_n!+1, alpha_n, phi_n!+1, phi_n, antoa0, pntop0,
                a0toan, p0topn;

        alpha_n := alpha;
        phi_n   := phi;
        antoa0 := {alpha_n};
        pntop0 := {phi_n};

        while alpha_n > 10^(-(symbolic !:prec!:)) do
           <<
                alpha_n!+1:= asin(2/(1+cos(alpha_n)) -1);
                phi_n!+1 := phi_n + (atan(cos(alpha_n)*tan(phi_n)))
                            + floor((floor(phi_n/(pi/2))+1)/2)*pi;

                antoa0 := alpha_n!+1.antoa0;
                pntop0 := phi_n!+1.pntop0;

                alpha_n := alpha_n!+1;
                phi_n   := phi_n!+1
           >>;

                a0toan := reverse(antoa0);
                p0topn := reverse(pntop0);
                return list(p0topn, a0toan)
   end;

%######################################################################
%VALUE OF EllipticF(phi,m)

procedure f_function(phi,m);

   begin scalar alpha, bothlists, a0toan, a1toan, p0topn, phi_n, y,
                elptf;

        alpha  := asin(m);
        bothlists := landentrans(phi,alpha);
        a0toan := part(bothlists,2);
        a1toan := rest(a0toan);
        p0topn := part(bothlists,1);
        phi_n  := part(reverse(p0topn),1);

        if phi = (pi/2)
           then
                elptf := k_function(m)
           else
                elptf :=
                phi_n *for each y in a1toan product(1/2)*(1+sin(y));
        return elptf
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
        an  := part(agm,2);
        return (pi / (2*an));
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticK definition
%====================

operator nome;

elliptickrules :=

{
        elliptick(~m)   => k_function(m)
	       when lisp !*rounded and numberp m,

        elliptick!'(~m) => k_function(sqrt(1-m^2))
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

   begin scalar f, n, alpha, bothlists, a0toan, p0topn, a1toan, p1topn,
                sinalist, sinplist, b, s, blist, c, allz, w, z, allx,
                h, x, elpte;

        f := f_function(phi,m);
        alpha := asin(m);

        bothlists := landentrans(phi,alpha);
        a0toan := part(bothlists, 2);
        p0topn := part(bothlists, 1);
        a1toan := rest(a0toan);
        p1topn := rest(p0topn);

        n := length(a1toan);

        sinalist := sin(a1toan);
        sinplist := sin(p1topn);

        b := part(sinalist,1);
        s := b;
        blist := for each c in rest sinalist collect << b := b*c >>;
        blist := s.blist;

        allz := 0;
        for w := 1:n do
           <<
                z := (1/(2^w))*part(blist,w);
                allz := allz + z
           >>;

        allx := 0;
        for h := 1:n do
           <<
                x := (1/(2^h))*((part(blist,h))^(1/2))
                              *  part(sinplist,h);

                allx := allx + x
           >>;

        elpte := f * (1 - (1/2)*((sin(part(a0toan,1)))^2)*(1 + allz))
                                           + sin(part(a0toan,1))*allx ;
        return elpte;
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
%CALCULATING THE FOUR THETA FUNCTIONS
%Theta 1 (often written H(u) - and has period 4K)
%Theta 2 (often written H1(u) -and has period 4K)
%Theta 3 (often written Theta1(u) - and has period 2K)
%Theta 4 (often written Theta(u) - and has period 2K)

procedure num_theta(a,u,m);

   begin scalar n, new, all, z, q, total;

        n := if a>2 then 1 else 0;
        new := 100;                     % To initiate loop
        all := 0;
        z := (pi*u)/(2*elliptick(m));
        q := exp(-pi*elliptick(1-m^2)/elliptick(m));

        while new > 10^(-(symbolic !:prec!:)) do
          << new := if a =1 then
                        ((-1)^n)*(q^(n*(n+1)))*sin((2*n+1)*z)
                else if a=2 then (q^(n*(n+1)))*cos((2*n+1)*z)
                else if a=3 then (q^(n*n))*cos(2*n*z)
                else if a=4 then ((-1)^n)*(q^(n*n))*cos(2*n*z);
             all := new + all;
             n := n+1
           >>;
        return if a > 2 then (1 + 2*all)
                else   (2*(q^(1/4))*all);
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Theta Functions

operator elliptictheta1;
operator elliptictheta2;
operator elliptictheta3;
operator elliptictheta4;

ellipticthetarules :=
{
%Theta1rules
%-----------
        elliptictheta1(~u,~m) =>
                 num_elliptic(num_theta,1,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta1(-~u,~m) => -elliptictheta1(u,m),

        elliptictheta1(~u+elliptick(~m),~m) =>  elliptictheta2(u,m),

        elliptictheta1(~u+(2*elliptick(~m)),~m) =>
                                                -elliptictheta1(u,m),

        elliptictheta1(~u+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta4(u,m),

        elliptictheta1(~u+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta1(u,m),

        elliptictheta1(~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta3(u,m),

        elliptictheta1(~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta1(u,m),

%Theta2rules
%-----------
        elliptictheta2(~u,~m) =>
                 num_elliptic(num_theta,2,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta2(-~u,~m) =>  elliptictheta2(u,m),

        elliptictheta2(~u+elliptick(~m),~m) => -elliptictheta1(u,m),

        elliptictheta2(~u+(2*elliptick(~m)),~m) =>
                                                -elliptictheta2(u,m),

        elliptictheta2(~u+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta3(u,m),

        elliptictheta2(~u+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta2(u,m),

        elliptictheta2(~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                        -i*(exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta4(u,m),

        elliptictheta2(~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta2(u,m),

%Theta3rules
%-----------
        elliptictheta3(~u,~m) =>
                 num_elliptic(num_theta,3,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta3(-~u,~m) =>  elliptictheta3(u,m),

        elliptictheta3(~u+elliptick(~m),~m) =>  elliptictheta4(u,m),

        elliptictheta3(~u+(2*elliptick(~m)),~m) =>
                                                 elliptictheta3(u,m),

        elliptictheta3(~u+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta2(u,m),
        elliptictheta3(~u+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta3(u,m),

        elliptictheta3(~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta1(u,m),

        elliptictheta3(~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta3(u,m),

%Theta4rules
%-----------
        elliptictheta4(~u,~m) =>
                 num_elliptic(num_theta,4,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta4(-~u,~m) =>  elliptictheta4(u,m),

        elliptictheta4(~u+elliptick(~m),~m) =>  elliptictheta3(u,m),

        elliptictheta4(~u+(2*elliptick(~m)),~m)=>elliptictheta4(u,m),

        elliptictheta4(~u+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta1(u,m),
        elliptictheta4(~u+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta4(u,m),

        elliptictheta4(~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(nome_q^(-1/2))
                                                *elliptictheta2(u,m),

        elliptictheta4(~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(nome_q^-1)
                                                *elliptictheta4(u,m)
%Error
%-----
%        elliptictheta(~a,~u,~m) =>
%
%            printerr ("In EllipticTheta(a,u,m);   a = 1,2,3 or 4.")
%                         when numberp a
%                                         and not(fixp a and a<5 and a>0)

}$
let ellipticthetarules;

%######################################################################
%CALCULATING ZETA

procedure jacobizeta!:numeric(u,m);
  % computes the JacobiZeta function for numeric u,m in rounded mode

   begin scalar phi_list, clist, l, j, z, cn, phi_n;

        phi_list := phi_function(1,sqrt(1-m^2),m,u);
        clist := part(agm_function(1,sqrt(1-m^2),m),5);
        l := length(phi_list);
        j := 1;
        z := 0;
        while j < l do
           <<
                cn    := part(clist,l-j);
                phi_n := part(phi_list,1+j);
                z := cn*sin(phi_n) + z;
                j := j+1
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

        jacobizeta(~u,~m) => num_elliptic(jacobizeta!:numeric,u,m)
                             when lisp !*rounded and numberp u
                             and numberp m
}$
let jacobizetarules;
%######################################################################

endmodule;
end;



