module sfellip;  % Procedures and Rules for Elliptic functions.

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

%ARITHMETIC GEOMETRIC MEAN

%The following procedure is the process of the Arithmetic Geometric
%Mean.

procedure agm_function(a0,b0,c0);

   begin scalar an, bn, cn, an!-1, bn!-1, alist, blist, clist;

     %Initial values.

        an!-1 := a0;
        bn!-1 := b0;
        cn    := 20; %To initiate while loop below.

     %Put initial values at end of list.

        alist := {a0}$
        blist := {b0}$
        clist := {c0}$

     %Loop to generate lists of aN,bN and cN starting with the Nth
     %value and ending with the initial value.

     %When the absolute value of cN reaches a value smaller than that
     %of the required precision the loop exits. The value of aN=bN=AGM.

        while abs(cn) > 10^(-(symbolic !:prec!:)) do

           << %Calculations for the process of the AGM

                an := (an!-1 + bn!-1) / 2;
                bn := sqrt(an!-1 * bn!-1);
                cn := (an!-1 - bn!-1) / 2;

             %Adding the next term to each of the lists.

                alist := an.alist;
                blist := bn.blist;
                clist := cn.clist;

             %Resetting the values in order to execute the next loop.

                an!-1 := an;
                bn!-1 := bn
           >>;

     %N is the number of terms in each list (excluding the initial
     % values) used to calculate the AGM.

        n := length(alist) - 1;

     %The following list contains all the items required in the
     %calculation of other procedures which use the AGM
     %ie. {N, AGM, {aN to a0},{bN to b0},{cN to c0}}

        return list(n ,an, alist, blist, clist)

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

   begin scalar alist, clist,n,a_n,an,cn,i, phi_n, phi_n!-1, phi_list;

        agm   := agm_function(a0,b0,c0);
        alist := part(agm,3);              % aN to a0
        clist := part(agm,5);              % cN to c0
        n := part(agm,1);
        a_n := part(alist,1);              % Value of the AGM.
        phi_n := (2^n)*a_n*u;
        phi_list := {phi_n}$
        i := 1;

        while i < length(alist) do

           <<
                an := part(alist,i);
                cn := part(clist,i);

                phi_n!-1 := (asin((cn/an)*sin(phi_n)) + phi_n) / 2;
                phi_list := phi_n!-1.phi_list;
                phi_n := phi_n!-1;
                i := i+1
           >>;

     %Returns {phi_0 to phi_N}.

        return phi_list;

   end;

%######################################################################
%JACOBI AMPLITUDE


%This computes the Amplitude of u.

procedure amplitude(u,m);
        asin(jacobisn(u,m));

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

operator jacobiamplitude;

jacobiamrules :=

{
        jacobiamplitude(~u,~m) => amplitude(u,m) when lisp !*rounded
                                         and numberp u and numberp m
}$

let jacobiamrules;

%######################################################################
%JACOBI FUNCTIONS

%Increases the precision used to evaluate algebraic arguments.

symbolic procedure  num_jacobi (u);
% check that length u >= 3 !
 if length u < 3 then
         rederr "illegal call to num_jacobisn" else
   begin scalar oldprec,res;
     oldprec := precision 0;
     precision max(oldprec,15);

    res :=  aeval u;
    precision oldprec;
    return res;

  end;

put('num_elliptic, 'psopfn, 'num_jacobi);

%######################################################################
%This procedure is called by Jacobisn when the on rounded switch is
%used. It evaluates the value of Jacobisn numerically.


procedure num_jacobisn(u,m);

   begin scalar phi0, jsn;
        phi0 := part(phi_function(1,sqrt(1-m),sqrt(m),u),1);
        jsn := sin(phi0);
        return jsn
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisn definition
%===================

operator jacobisn;
operator elliptick!';
operator elliptick;

%This rule list includes all the special cases of the Jacobisn
%function.

jacobisnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobisn(~u,0)   => sin u,
        jacobisn(~u,1)   => tanh u,
        jacobisn(~u,-~m) => jacobisn(u,m),
%Change of argument
%------------------
        jacobisn(~u + ~v,~m) =>
                ( jacobisn(u,m)*jacobicn(v,m)*jacobidn(v,m)
                + jacobisn(v,m)*jacobicn(u,m)*jacobidn(u,m) )
                / (1-m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobisn(2*~u,~m) =>
                ( 2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) )
                / (1-m*((jacobisn(u,m))^4)),

        jacobisn(~u/2,~m) =>
                ( 1- jacobicn(u,m) ) / ( 1 + jacobidn(u,m) ),


        jacobisn(-~u,~m) => -jacobisn(u,m),
        jacobisn((~u+elliptick(~m)),~m)   =>  jacobicd(u,m),
        jacobisn((~u-elliptick(~m)),~m)   => -jacobicd(u,m),
        jacobisn((elliptick(~m)-~u),~m)   =>  jacobicd(u,m),
        jacobisn((~u+2*elliptick(~m)),~m) => -jacobisn(u,m),
        jacobisn((~u-2*elliptick(~m)),~m) => -jacobisn(u,m),
        jacobisn((2*elliptick(~m)-~u),~m) =>  jacobisn(u,m),
        jacobisn(~u+i*elliptick!'(~m),~m) => (m^(-1/2))*jacobins(u,m),

        jacobisn((~u+2*i*elliptick!'(~m)),~m) => jacobisn(u,m),

        jacobisn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                              (m^(-1/2))*jacobidc(u,m),

        jacobisn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobisn(u,m),
%Special Arguments
%-----------------
        jacobisn(0,~m) => 0,

        jacobisn((1/2)*elliptick(~m),~m) =>1/((1+((1-m)^(1/2)))^(1/2)),

        jacobisn(elliptick(~m),~m) => 1,

        jacobisn((1/2)*i*elliptick!'(~m),~m) => i*m^(-1/4),

        jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                            (2^(-1/2))*m^(-1/4)*(((1+(m^(1/2)))^(1/2))
                                            + i*((1-(m^(1/2)))^(1/2))),

        jacobisn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) => m^(-1/4),

        jacobisn(i*elliptick!'(~m),~m) => infinity,

        jacobisn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                              (1-((1-m)^(1/2)))^(-1/2),

        jacobisn(elliptick(~m)+i*elliptick!'(~m),~m) => m^(-1/2),


%Derivatives, Integral
%---------------------
        df(jacobisn(~u,~m),~u)  => jacobicn(u,m)*jacobidn(u,m),
        df(jacobisn(~u,~m),~m)  => (m*jacobisn(u,m)*jacobicn(u,m)^2
                        - elliptice(u,m)*jacobicn(u,m)*jacobidn(u,m)/m)
                        / (1-(m^2)) +  u*jacobicn(u,m)*jacobidn(u,m)/m,

        int(jacobisn(~u,~m),~u) =>
                (m^(-1/2))*ln(jacobidn(u,m)-(m^(1/2))*jacobicn(u,m)),

%Calls Num_Jacobisn when the rounded switch is on.
%-------------------------------------------------
        jacobisn(~u,~m) => num_elliptic(num_jacobisn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobisn(~u,~m) => num_elliptic(complex_sn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0

}$
let jacobisnrules;

%......................................................................
%Evaluates Jacobisn when imaginary argument.

operator complex_sn;
snrule :=
{

        complex_sn(i*~u,~m) => i*num_jacobisc(u,1-m),

        complex_sn(~x + i*~y,~m) =>
                ( num_jacobisn(x,m)*num_jacobidn(y,1-m)
                + i*num_jacobicn(x,m)*num_jacobidn(x,m)
                   *num_jacobisn(y,1-m)*num_jacobicn(y,1-m) )
                / (((num_jacobicn(y,1-m))^2)+
                   m*((num_jacobisn(x,m))^2)*((num_jacobisn(y,1-m))^2))
}$
let snrule;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicn when the on rounded switch is
%used. It evaluates the value of Jacobicn numerically.

procedure num_jacobicn(u,m);

   begin scalar phi0, jcn;
        phi0 := part(phi_function(1,sqrt(1-m),sqrt(m),u),1);
        jcn := cos(phi0);
        return jcn
   end;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobicn definition
%===================

operator jacobicn;

%This rule list includes all the special cases of the Jacobicn
%function.

jacobicnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobicn(~u,0)   => cos u,
        jacobicn(~u,1)   => sech u,
        jacobicn(~u,-~m) => jacobicn(u,m),
%Change of Argument
%------------------
        jacobicn(~u + ~v,~m) =>
                ( jacobicn(u,m)*jacobicn(v,m) - jacobisn(u,m)
                   *jacobidn(u,m)*jacobisn(v,m)*jacobidn(v,m) )
                / (1 - m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobicn(2*~u,~m) =>
                ( ((jacobicn(u,m))^2) - ((jacobisn(u,m))^2)
                  *((jacobidn(u,m))^2) )
                / (1- m*((jacobisn(u,m))^4)),

        jacobicn(~u/2,~m) =>
                ( jacobidn(u,m) + jacobicn(u,m) )
                / ( 1 + jacobidn(u,m) ),

        jacobicn(-~u,~m) => jacobicn (u,m),

        jacobicn((~u+elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((~u-elliptick(~m)),~m) => ((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((~u+2*elliptick(~m)),~m) => -jacobicn(u,m),
        jacobicn((~u-2*elliptick(~m)),~m) => -jacobicn(u,m),
        jacobicn((2*elliptick(~m)-~u),~m) => -jacobicn(u,m),
        jacobicn((~u+i*elliptick!'(~m)),~m) =>
                                            -i*(m^(-1/2))*jacobids(u,m),

        jacobicn((~u+2*i*elliptick!'(~m)),~m) => -jacobicn(u,m),

        jacobicn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                             -i*((1-m)^(1/2))*(m^(-1/2))*jacobinc(u,m),

        jacobicn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobicn(u,m),
%Special Arguments
%-----------------
        jacobicn(0,~m) => 1,

        jacobicn((1/2)*elliptick(~m),~m) =>
                                 ((1-m)^(1/4))/(1+((1-m)^(1/2)))^(1/2),

        jacobicn(elliptick(~m),~m) => 0,

        jacobicn((1/2)*i*elliptick!'(~m),~m) =>
                                       ((1+(m^(1/2)))^(1/2))/(m^(1/4)),

        jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                           (((1-m)/(4*m))^(1/4))*(1-i),

        jacobicn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                  -i*(((1-(m^(1/2)))/(m^(1/2))))^(1/2),

        jacobicn(i*elliptick!'(~m),~m) => infinity,

        jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                          -i*((((1-m)^(1/2))/(1-((1-m)^(1/2))))^(1/2)),

        jacobicn(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                  -i*(((1-m)/m)^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobicn(~u,~m),~u)  => -jacobisn(u,m)*jacobidn(u,m),
        df(jacobicn(~u,~m),~m)  => (-m*(jacobisn(u,m)^2)*jacobicn(u,m)
                                   + elliptice(u,m)*jacobisn(u,m)
                                     *jacobidn(u,m)/m)/(1-(m^2))
                                   - u*jacobisn(u,m)*jacobidn(u,m)/m,

        int(jacobicn(~u,~m),~u) => (m^(-1/2))*acos(jacobidn(u,m)),

%Calls Num_Jacobicn when rounded switch is on.
%---------------------------------------------
        jacobicn(~u,~m) => num_elliptic(num_jacobicn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobicn(~u,~m) => num_elliptic(complex_cn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0
}$
let jacobicnrules;

%......................................................................
%Evaluates Jacobicn when imaginary argument.

operator complex_cn;
cnrule :=
{

        complex_cn(i*~u,~m) => num_jacobinc(u,1-m),

        complex_cn(~x + i*~y,~m) =>

                ( num_jacobicn(x,m)*num_jacobicn(y,1-m)
                - i*num_jacobisn(x,m)*num_jacobidn(x,m)
                   *num_jacobisn(y,1-m)*num_jacobidn(y,1-m) )
                / (((num_jacobicn(y,1-m))^2)+
                   m*((num_jacobisn(x,m))^2)*((num_jacobisn(y,1-m))^2))
}$
let cnrule;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidn when the on rounded switch is
%used. It evaluates the value of Jacobidn numerically.

procedure num_jacobidn(u,m);
   begin scalar phi, phi0,  phi1, numer, denom, jdn;
        phi  := phi_function(1,sqrt(1-m),sqrt(m),u);
        phi0 := part(phi,1);
        phi1 := part(phi,2);
        numer := cos(phi0);
        denom := cos(phi1 - phi0);

        if denom < 10^(-(symbolic !:prec!:))
        then  jdn := otherdn(u,m)
        else  jdn := numer/denom;
        return jdn
   end;

procedure otherdn(u,m);
   begin scalar mu, v, dn;
        mu := ((1-((1-m)^(1/2))) / (1+((1-m)^(1/2))))^2;
        v  := u / (1+(mu^(1/2)));

        dn := ((approx(v,mu))^2 - (1-(mu^(1/2))))

                / ((1+(mu^(1/2))) - (approx(v,mu))^2);
        return dn
   end;


procedure approx(u,m);
   begin scalar near;
        near := 1 - (1/2)*m*(sin(u))^2;
        return near
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidn definition
%===================

operator jacobidn;

%This rule list includes all the special cases of the Jacobidn
%function.

jacobidnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobidn(~u,0)   => 1,
        jacobidn(~u,1)   => sech u,
        jacobidn(~u,-~m) => jacobidn(u,m),
%Change of Argument
%------------------
        jacobidn(~u + ~v,~m) =>
                ( jacobidn(u,m)*jacobidn(v,m) - m*jacobisn(u,m)
                   *jacobicn(u,m)*jacobisn(v,m)*jacobicn(v,m) )
                / (1 - m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobidn(2*~u,~m) =>
                (  ((jacobidn(u,m))^2) - m*((jacobisn(u,m))^2)
                  *((jacobicn(u,m))^2) )
                / (1- m*((jacobisn(u,m))^4)),

        jacobidn(~u/2,~m) =>
                ( (1-m) + jacobidn(u,m) + m*jacobicn(u,m))
                / ( 1 + jacobidn(u,m) ),

        jacobidn(-~u,~m) => jacobidn(u,m),

        jacobidn((~u+elliptick(~m)),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((~u-elliptick(~m)),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((~u+2*elliptick(~m)),~m) => jacobidn(u,m),
        jacobidn((~u-2*elliptick(~m)),~m) => jacobidn(u,m),
        jacobidn((2*elliptick(~m)-~u),~m) => jacobidn(u,m),
        jacobidn((~u+i*elliptick!'(~m)),~m)   => -i*jacobics(u,m),
        jacobidn((~u+2*i*elliptick!'(~m)),~m) => -jacobidn(u,m),

        jacobidn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                         i*((1-m)^(1/2))*jacobisc(u,m),

        jacobidn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobidn(u,m),
%Special Arguments
%-----------------
        jacobidn(0,~m) => 1,

        jacobidn((1/2)*elliptick(~m),~m) => (1-m)^(1/4),

        jacobidn(elliptick(~m),~m) => (1-m)^(1/2),

        jacobidn((1/2)*i*elliptick!'(~m),~m) =>   (1+(m^(1/2)))^(1/2),

        jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                         (((1-m)/4)^(1/4))*(((1+((1-m)^(1/2)))^(1/2))
                                        - i*((1-((1-m)^(1/2)))^(1/2))),

        jacobidn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                   (1-(m^(1/2)))^(1/2),

        jacobidn(i*elliptick!'(~m),~m) => infinity,

        jacobidn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                      -i*((1-m)^(1/4)),

        jacobidn(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Intergal
%---------------------
% Following a hint from Alain Moussiaux
%       df(Jacobidn(~u,~m),~u)  => -m *Jacobisn(u,m)*Jacobicn(u,m),
        df(jacobidn(~u,~m),~u)  => -m**2 *jacobisn(u,m)*jacobicn(u,m),
        df(jacobidn(~u,~m),~m)  => m*(-(jacobisn(u,m)^2)*jacobidn(u,m)
                                   + elliptice(u,m)*jacobisn(u,m)
                                     *jacobicn(u,m))/(1-(m^2))
                                   - m*u*jacobisn(u,m)*jacobicn(u,m),

        int(jacobidn(~u,~m),~u) => asin(jacobisn(u,m)),

%Calls Num_Jacobidn when rounded switch is on.
%---------------------------------------------
        jacobidn(~u,~m) => num_elliptic(num_jacobidn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobidn(~u,~m) => num_elliptic(complex_dn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0
}$
let jacobidnrules;

%......................................................................
%Evaluates Jacobidn when imaginary argument.

operator complex_dn;
dnrule :=
{       complex_dn(i*~u,~m) => num_jacobidc(u,1-m),

        complex_dn(~x + i*~y,~m) =>

        ( num_jacobidn(x,m)*num_jacobicn(y,1-m)*num_jacobidn(y,1-m)
        - i*m*num_jacobisn(x,m)*num_jacobicn(x,m)*num_jacobisn(y,1-m) )
        / ( ((num_jacobicn(y,1-m))^2) + m*((num_jacobisn(x,m))^2)
                                         *((num_jacobisn(y,1-m))^2) )
}$
let dnrule;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicd when the on rounded switch is
%used. It evaluates the value of Jacobicd numerically.

procedure num_jacobicd(u,m);

        num_jacobicn(u,m) / num_jacobidn(u,m);


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
%Change of Argument
%------------------
        jacobicd(-~u,~m)   => jacobicd(u,m),
        jacobicd((~u+elliptick(~m)),~m)   => -jacobisn(u,m),
        jacobicd((~u-elliptick(~m)),~m)   =>  jacobisn(u,m),
        jacobicd((elliptick(~m)-~u),~m)   =>  jacobisn(u,m),
        jacobicd((~u+2*elliptick(~m)),~m) => -jacobicd(u,m),
        jacobicd((~u-2*elliptick(~m)),~m) => -jacobicd(u,m),
        jacobicd((2*elliptick(~m)-~u),~m) => -jacobicd(u,m),
        jacobicd((~u+i*elliptick!'(~m)),~m) =>
                                              (m^(-1/2))*jacobidc(u,m),

        jacobicd((~u+2*i*elliptick!'(~m)),~m) => jacobicd(u,m),

        jacobicd((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                             -(m^(-1/2))*jacobins(u,m),

        jacobicd((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobicd(u,m),
%Special Arguments
%-----------------
        jacobicd(0,~m) => 1,

        jacobicd((1/2)*elliptick(~m),~m) => 1 /(1+((1-m)^(1/2)))^(1/2),

        jacobicd(elliptick(~m),~m) => 0,

        jacobicd((1/2)*i*elliptick!'(~m),~m) => 1/(m^(1/4)),

        jacobicd((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                           (1-i)/((m^(1/4))*(((1+((1-m)^(1/2)))^(1/2))
                                        -i*((1-((1-m)^(1/2)))^(1/2)))),

        jacobicd(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                          -i/(m^(1/4)),

        jacobicd(i*elliptick!'(~m),~m) =>
                                        jacobicn(i*elliptick!'(~m),~m)
                                      / jacobidn(i*elliptick!'(~m),~m),

        jacobicd((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                           1/((1-((1-m)^(1/2)))^(1/2)),

        jacobicd(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives,Integral
%--------------------
        df(jacobicd(~u,~m),~u) => -(1 - m)*jacobisd(u,m)*jacobind(u,m),
        df(jacobicd(~u,~m),~m) =>
                                ( jacobidn(u,m)*df(jacobicn(u,m),m)
                                - jacobicn(u,m)*df(jacobidn(u,m),m))
                                / ((jacobidn(u,m))^2),

        int(jacobicd(~u,~m),~u) =>
                m^(-1/2)*ln(jacobind(u,m) + (m^(1/2))*jacobisd(u,m)),

%Calls Num_Jacobicd when rounded switch is on.
%---------------------------------------------
        jacobicd(~u,~m) => num_elliptic(num_jacobicd, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobicdrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisd when the on rounded switch is
%used. It evaluates the value of Jacobisd numerically.

procedure num_jacobisd(u,m);

   num_jacobisn(u,m) / num_jacobidn(u,m);

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
%Change of Argument
%------------------
        jacobisd(-~u,~m)   => -jacobisd(u,m),

        jacobisd((~u+elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobicn(u,m),
        jacobisd((~u-elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobicn(u,m),

        jacobisd((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobicn(u,m),

        jacobisd((~u+2*elliptick(~m)),~m) => -jacobisd(u,m),
        jacobisd((~u-2*elliptick(~m)),~m) => -jacobisd(u,m),
        jacobisd((2*elliptick(~m)-~u),~m) =>  jacobisd(u,m),

        jacobisd((~u+i*elliptick!'(~m)),~m) =>
                                             i*(m^(-1/2))*jacobinc(u,m),

        jacobisd((~u+2*i*elliptick!'(~m)),~m) => -jacobisd(u,m),

        jacobisd((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                          -i*((1-m)^(-1/2))*(m^(-1/2))*jacobids(u,m),

        jacobisd((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobisd(u,m),
%Special Arguments
%-----------------
        jacobisd(0,~m) => 0,

        jacobisd((1/2)*elliptick(~m),~m) =>
                         1 / (((1+((1-m)^(1/2)))^(1/2))*((1-m)^(1/4))),

        jacobisd(elliptick(~m),~m) => 1/((1-m)^(1/2)),

        jacobisd((1/2)*i*elliptick!'(~m),~m) =>
                                    i*(m^(-1/4))/((1+(m^(1/2)))^(1/2)),

        jacobisd((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobisd(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                        (m^(-1/4))/(1-(m^(1/2))^(1/2)),

        jacobisd(i*elliptick!'(~m),~m) =>
                                        jacobisn(i*elliptick!'(~m),~m)
                                      / jacobidn(i*elliptick!'(~m),~m),

        jacobisd((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                         ((1-((1-m)^(1/2)))^(-1/2))/(-i*((1-m)^(1/4))),

        jacobisd(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives, Integral
%---------------------
        df(jacobisd(~u,~m),~u) => jacobicd(u,m)*jacobind(u,m),
        df(jacobisd(~u,~m),~m) =>
                                ( jacobidn(u,m)*df(jacobisn(u,m),m)
                                - jacobisn(u,m)*df(jacobidn(u,m),m))
                                / ((jacobidn(u,m))^2),

        int(jacobisd(~u,~m),~u) =>
                   (m*(1-m))^(-1/2)*asin(-(m^(1/2))*(jacobicd(u,m))),

%Calls Num_Jacobisd when rounded switch is on.
%---------------------------------------------
        jacobisd(~u,~m) => num_elliptic(num_jacobisd, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
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
%Change of Argument
%------------------
        jacobind(-~u,~m)   => jacobind(u,m),

        jacobind((~u+elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobidn(u,m),
        jacobind((~u-elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobidn(u,m),
        jacobind((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobidn(u,m),

        jacobind((~u+2*elliptick(~m)),~m) => jacobind(u,m),
        jacobind((~u-2*elliptick(~m)),~m) => jacobind(u,m),
        jacobind((2*elliptick(~m)-~u),~m) => jacobind(u,m),

        jacobind((~u+i*elliptick!'(~m)),~m)   => i*jacobisc(u,m),
        jacobind((~u+2*i*elliptick!'(~m)),~m) => -jacobind(u,m),

        jacobind((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                       -i*((1-m)^(-1/2))*jacobics(u,m),

        jacobind((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobind(u,m),
%Special Arguments
%-----------------
        jacobind(0,~m) => 1,

        jacobind((1/2)*elliptick(~m),~m) => 1 / ((1-m)^(1/4)),

        jacobind(elliptick(~m),~m) => 1 / ((1-m)^(1/2)),

        jacobind((1/2)*i*elliptick!'(~m),~m) =>
                                               1/((1+(m^(1/2)))^(1/2)),

        jacobind((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                1/jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobind(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                               1/((1-(m^(1/2)))^(1/2)),

        jacobind(i*elliptick!'(~m),~m) =>
                                    1 / jacobidn(i*elliptick!'(~m),~m),

        jacobind((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                1 / (-i*((1-m)^(1/4))),

        jacobind(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives, Integral
%---------------------
        df(jacobind(~u,~m),~u) => m*jacobisd(u,m)*jacobicd(u,m),
        df(jacobind(~u,~m),~m) =>
                            -(df(jacobidn(u,m),m))/((jacobidn(u,m))^2),

        int(jacobind(~u,~m),~u) => (1-m)^(-1/2)*(acos(jacobicd(u,m))),

%Calls Num_Jacobind when rounded switch is on.
%---------------------------------------------
        jacobind(~u,~m) => num_elliptic(num_jacobind, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobindrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidc when the on rounded switch is
%used. It evaluates the value of Jacobidc numerically.

procedure num_jacobidc(u,m);

        num_jacobidn(u,m) / num_jacobicn(u,m);

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
%Change of Argument
%------------------
        jacobidc(-~u,~m)   => jacobidc(u,m),

        jacobidc((~u+elliptick(~m)),~m) => -jacobins(u,m),
        jacobidc((~u-elliptick(~m)),~m) =>  jacobidns(u,m),
        jacobidc((elliptick(~m)-~u),~m) =>  jacobins(u,m),
        jacobidc((~u+2*elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobidc((~u-2*elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobidc((2*elliptick(~m)-~u),~m)   => -jacobidc(u,m),
        jacobidc((~u+i*elliptick!'(~m)),~m) => (m^(1/2))*jacobicd(u,m),
        jacobidc((~u+2*i*elliptick!'(~m)),~m) => jacobidc(u,m),

        jacobidc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                               (m^(1/2))*jacobisn(u,m),

        jacobidc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobidc(u,m),
%Special Arguments
%-----------------
        jacobidc(0,~m) => 1,

        jacobidc((1/2)*elliptick(~m),~m) => (1+((1-m)^(1/2)))^(1/2),

        jacobidc(elliptick(~m),~m) => infinity,

        jacobidc((1/2)*i*elliptick!'(~m),~m) => m^(1/4),

        jacobidc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobidc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                           i*(m^(1/4)),

        jacobidc(i*elliptick!'(~m),~m) =>
                                        jacobidn(i*elliptick!'(~m),~m)
                                      / jacobicn(i*elliptick!'(~m),~m),

        jacobidc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                               (1-((1-m)^(1/2)))^(1/2),

        jacobidc(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Integral
%---------------------
        df(jacobidc(~u,~m),~u) => (1-m)*jacobisc(u,m)*jacobinc(u,m),
        df(jacobidc(~u,~m),~m) =>
                                (jacobicn(u,m)*df(jacobidn(u,m),m)
                                - jacobidn(u,m)*df(jacobicn(u,m),m))
                                / ((jacobicn(u,m))^2),

        int(jacobidc(~u,~m),~u) => ln(jacobinc(u,m) + jacobisc(u,m)),

%Calls Num_Jacobidc when rounded switch is on.
%---------------------------------------------
        jacobidc(~u,~m) => num_elliptic(num_jacobidc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
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
%Change of Argument
%------------------
        jacobinc(-~u,~m)   => jacobinc(u,m),

        jacobinc((~u+elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobids(u,m),

        jacobinc((~u-elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobids(u,m),
        jacobinc((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobids(u,m),

        jacobinc((~u+2*elliptick(~m)),~m) => -jacobinc(u,m),
        jacobinc((~u-2*elliptick(~m)),~m) => -jacobinc(u,m),
        jacobinc((2*elliptick(~m)-~u),~m) => -jacobinc(u,m),
        jacobinc((~u+i*elliptick!'(~m)),~m) =>
                                             i*(m^(1/2))*jacobisd(u,m),

        jacobinc((~u+2*i*elliptick!'(~m)),~m) => -jacobinc(u,m),

        jacobinc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                            i*((1-m)^(-1/2))*(m^(1/2))*jacobicn(u,m),

        jacobinc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobinc(u,m),
%Special Arguments
%-----------------
        jacobinc(0,~m) => 1,

        jacobinc((1/2)*elliptick(~m),~m) => ((1+((1-m)^(1/2)))^(1/2))
                                                        /((1-m)^(1/4)),

        jacobinc(elliptick(~m),~m) => infinity,

        jacobinc((1/2)*i*elliptick!'(~m),~m) =>
                                       (m^(1/4))/((1+(m^(1/2)))^(1/2)),

        jacobinc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                             ((4*m/(1-m))^(1/4))/(1-i),

        jacobinc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                1 / jacobicn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m),

        jacobinc(i*elliptick!'(~m),~m) =>
                                    1 / jacobicn(i*elliptick!'(~m),~m),

        jacobinc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                1 / jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m),

        jacobinc(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                   i*((m/(1-m))^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobinc(~u,~m),~u) => jacobisc(u,m)*jacobidc(u,m),
        df(jacobinc(~u,~m),~m) =>
                            -(df(jacobicn(u,m),m))/((jacobicn(u,m))^2),

        int(jacobinc(~u,~m),~u) =>

         ((1-m)^(-1/2))*ln(jacobidc(u,m)+((1-m)^(1/2))*jacobisc(u,m)),

%Calls Num_Jacobinc when rounded switch is on.
%---------------------------------------------
        jacobinc(~u,~m) => num_elliptic(num_jacobinc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobincrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisc when the on rounded switch is
%used. It evaluates the value of Jacobisc numerically.

procedure num_jacobisc(u,m);

        num_jacobisn(u,m) / num_jacobicn(u,m);

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
%Change of Argument
%------------------
        jacobisc(-~u,~m)   => -jacobisc(u,m),

        jacobisc((~u+elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobics(u,m),

        jacobisc((~u-elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobics(u,m),

        jacobisc((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobics(u,m),

        jacobisc((~u+2*elliptick(~m)),~m) =>  jacobisc(u,m),
        jacobisc((~u-2*elliptick(~m)),~m) =>  jacobisc(u,m),
        jacobisc((2*elliptick(~m)-~u),~m) => -jacobisc(u,m),
        jacobisc((~u+i*elliptick!'(~m)),~m)   =>i*jacobind(u,m),
        jacobisc((~u+2*i*elliptick!'(~m)),~m) => -jacobisc(u,m),

        jacobisc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                        i*((1-m)^(-1/2))*jacobidn(u,m),

        jacobisc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobisc(u,m),
%Special Arguments
%-----------------
        jacobisc(0,~m) => 0,

        jacobisc((1/2)*elliptick(~m),~m) => 1 / ((1-m)^(1/4)),

        jacobisc(elliptick(~m),~m) => infinity,

        jacobisc((1/2)*i*elliptick!'(~m),~m) =>
                                               i/((1+(m^(1/2)))^(1/2)),

        jacobisc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobisc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                               i/((1-(m^(1/2)))^(1/2)),

        jacobisc(i*elliptick!'(~m),~m) =>
                                      jacobisn(i*elliptick!'(~m),~m)
                                      / jacobicn(i*elliptick!'(~m),~m),

        jacobisc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>

                  jacobisn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m)
                  / jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m),

        jacobisc(elliptick(~m)+i*elliptick!'(~m),~m) =>i/((1-m)^(1/2)),


%Derivatives, Integral
%---------------------
        df(jacobisc(~u,~m),~u) => jacobidc(u,m)*jacobinc(u,m),
        df(jacobisc(~u,~m),~m) =>
                                ( jacobicn(u,m)*df(jacobisn(u,m),m)
                                - jacobisn(u,m)*df(jacobicn(u,m),m))
                                /((jacobicn(u,m))^2),

        int(jacobisc(~u,~m),u) =>

          ((1-m)^(-1/2))*ln(jacobidc(u,m)+((1-m)^(1/2))*jacobinc(u,m)),

%Calls Num_Jacobisc when rounded switch is on.
%---------------------------------------------
        jacobisc(~u,~m) => num_elliptic(num_jacobisc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
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
%Change of Argument
%------------------
        jacobins(-~u,~m)   => -jacobins(u,m),

        jacobins((~u+elliptick(~m)),~m)   =>  jacobidc(u,m),
        jacobins((~u-elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobins((elliptick(~m)-~u),~m)   =>  jacobidc(u,m),
        jacobins((~u+2*elliptick(~m)),~m) => -jacobins(u,m),
        jacobins((~u-2*elliptick(~m)),~m) => -jacobins(u,m),
        jacobins((2*elliptick(~m)-~u),~m) =>  jacobins(u,m),
        jacobins((~u+i*elliptick!'(~m)),~m) => (m^(1/2))*jacobisn(u,m),
        jacobins((~u+2*i*elliptick!'(~m)),~m) => jacobins(u,m),
        jacobins((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                               (m^(1/2))*jacobicd(u,m),

        jacobins((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobins(u,m),
%Special Arguments
%-----------------
        jacobins(0,~m) => infinity,

        jacobins((1/2)*elliptick(~m),~m) => (1+((1-m)^(1/2)))^(1/2),

        jacobins(elliptick(~m),~m) => 1,

        jacobins((1/2)*i*elliptick!'(~m),~m) => -i*(m^(1/4)),

        jacobins((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                1/jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobins(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>(m^(1/4)),

        jacobins(i*elliptick!'(~m),~m) =>

                                      1/jacobisn(i*elliptick!'(~m),~m),

        jacobins((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>

                                               (1-((1-m)^(1/2)))^(1/2),

        jacobins(elliptick(~m)+i*elliptick!'(~m),~m) => m^(1/2),
%Derivatives, Integral
%---------------------
        df(jacobins(~u,~m),~u) => -jacobids(u,m)*jacobics(u,m),
        df(jacobins(~u,~m),~m) =>
                            -(df(jacobisn(u,m),m))/((jacobisn(u,m))^2),

        int(jacobins(~u,~m),~u) => ln(jacobids(u,m) - jacobics(u,m)),

%Calls Num_Jacobins when rounded switch is on.
%---------------------------------------------
        jacobins(~u,~m) => num_elliptic(num_jacobins, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobinsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobids when the on rounded switch is
%used. It evaluates the value of Jacobids numerically.

procedure num_jacobids(u,m);

        num_jacobidn(u,m) / num_jacobisn(u,m);

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
%Change of Argument
%------------------
        jacobids(-~u,~m)   =>-jacobids(u,m),

        jacobids((~u+elliptick(~m)),~m) => ((1-m)^(1/2))*jacobinc(u,m),
        jacobids((~u-elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobinc(u,m),
        jacobids((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobinc(u,m),

        jacobids((~u+2*elliptick(~m)),~m) => -jacobids(u,m),
        jacobids((~u-2*elliptick(~m)),~m) => -jacobids(u,m),
        jacobids((2*elliptick(~m)-~u),~m) =>  jacobids(u,m),
        jacobids((~u+i*elliptick!'(~m)),~m) =>
                                             -i*(m^(1/2))*jacobicn(u,m),

        jacobids((~u+2*i*elliptick!'(~m)),~m) => -jacobids(u,m),

        jacobids((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                               i*((1-m)^(1/2))*(m^(1/2))*jacobisd(u,m),

        jacobids((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobids(u,m),
%Special Arguments
%-----------------
        jacobids(0,~m) => infinity,

        jacobids((1/2)*elliptick(~m),~m) =>
                               ((1+((1-m)^(1/2)))^(1/2))*((1-m)^(1/4)),

        jacobids(elliptick(~m),~m) => (1-m)^(1/2),

        jacobids((1/2)*i*elliptick!'(~m),~m) =>
                                    -i*(m^(1/4))*((1+(m^(1/2)))^(1/2)),

        jacobids((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobids(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                       (m^(1/4))*((1-(m^(1/2)))^(1/2)),

        jacobids(i*elliptick!'(~m),~m) =>
                                      jacobidn(i*elliptick!'(~m),~m)
                                      / jacobisn(i*elliptick!'(~m),~m),

        jacobids((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                            -i*((1-m)^(1/4))*((1-((1-m)^(1/2)))^(1/2)),

        jacobids(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Integral
%---------------------
        df(jacobids(~u,~m),~u) => -jacobics(u,m)*jacobins(u,m),
        df(jacobids(~u,~m),~m) =>
                                (jacobisn(u,m)*df(jacobidn(u,m),m)
                                - jacobidn(u,m)*df(jacobisn(u,m),m))
                                / ((jacobisn(u,m))^2),

        int(jacobids(~u,~m),~u) => ln(jacobins(u,m) - jacobics(u,m)),

%Calls Num_Jacobids when on rounded switch is on.
%------------------------------------------------
        jacobids(~u,~m) => num_elliptic(num_jacobids, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobidsrules;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobics when the on rounded switch is
%used. It evaluates the value of Jacobics numerically.

procedure num_jacobics(u,m);

        num_jacobicn(u,m) / num_jacobisn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobics definition
%===================

operator jacobics;

%This rule list includes all the special cases of the Jacobics
%function.

jacobicsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobics(~u,0)   => cot u,
        jacobics(~u,1)   => csch u,
        jacobics(~u,-~m) => jacobics(u,m),
%Change of Argument
%------------------
        jacobics(-~u,~m)   =>-jacobics(u,m),

        jacobics((~u+elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisc(u,m),
        jacobics((~u-elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisc(u,m),
        jacobics((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobisc(u,m),
        jacobics((~u+2*elliptick(~m)),~m) =>  jacobics(u,m),
        jacobics((~u-2*elliptick(~m)),~m) =>  jacobics(u,m),
        jacobics((2*elliptick(~m)-~u),~m) => -jacobics(u,m),
        jacobics((~u+i*elliptick!'(~m)),~m)   => -i*jacobidn(u,m),
        jacobics((~u+2*i*elliptick!'(~m)),~m) => -jacobics(u,m),

        jacobics((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                        -i*((1-m)^(1/2))*jacobind(u,m),

        jacobics((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobics(u,m),
%Special Arguments
%-----------------
        jacobics(0,~m) => infinity,

        jacobics((1/2)*elliptick(~m),~m) => (1-m)^(1/4),

        jacobics(elliptick(~m),~m) => 0,

        jacobics((1/2)*i*elliptick!'(~m),~m) =>
                                              -i*((1+(m^(1/2)))^(1/2)),

        jacobics((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobics(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                              -i*((1-(m^(1/2)))^(1/2)),

        jacobics(i*elliptick!'(~m),~m) =>
                                      jacobicn(i*elliptick!'(~m),~m)
                                      / jacobisn(i*elliptick!'(~m),~m),

        jacobics((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                      -i*((1-m)^(1/4)),

        jacobics(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                       -i*((1-m)^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobics(~u,~m),~u) => -jacobins(u,m)*jacobids(u,m),
        df(jacobics(~u,~m),~m) =>
                                ( jacobisn(u,m)*df(jacobicn(u,m),m)
                                - jacobicn(u,m)*df(jacobisn(u,m),m))
                                / ((jacobisn(u,m))^2),

        int(jacobics(~u,~m),~u) => ln(jacobins(u,m) - jacobids(u,m)),

%Calls Num_Jacobics when rounded switch is on.
%---------------------------------------------
        jacobics(~u,~m) => num_elliptic(num_jacobics, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
}$
let jacobicsrules;

endmodule;

end;
