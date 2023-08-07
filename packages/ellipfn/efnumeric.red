module efnumeric;

% Authors: Lisa Temme, 1994.  AGM function and Landen transformation.
% Alan Barnes, February 2022.  Added code for numerical evaluation of
% symmetric elliptic integrals: RF, RD, RJ and Carlson's RC. Also includes
% original numerical procedures moved from efjacobi.red, efellint.red etc.

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

% do we really need this?  Simpler and sufficient for use in efweier.red 
procedure agm_basic(a0, b0);
begin scalar an, bn, cn, tol;
   tol := 10.0^-(symbolic !:prec!:);
   repeat <<
      an := (a0 + b0)/2;
      bn := sqrt(a0*b0);
      cn := (a0 - b0)/2;
      a0 := an;
      b0 := bn
   >> until cn < tol;
   return an;
end;

% The following procedure is the Arithmetic Geometric Mean.
% This more complex procedure used in efjacobi.red

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
%       sin(2phi    - phi ) = (c /a )sin phi
%               N-1      N       N  N          N
% and returns a list of phi  to phi . This list is then used in the
%                        0        N
% calculation of Jacobisn, Jacobicn, Jacobidn, which in turn are used
% to calculate the remaining twelve Jacobi Functions.

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
% The following procedures have been superseded as they sometimes fail for
% complex arguments. They have been replaced by methods using thta functions
% or symmetric elliptic integrals

%VALUE OF EllipticF(phi,m)

procedure f_function(phi,m);
    if phi = pi/2 then num_ellk(m)
    else begin scalar  bothlists, alist, plist, phi_n;
       bothlists := landentrans(phi,asin m);
       alist := rest second bothlists;
       plist := first bothlists;
       phi_n  := first reverse plist;
       return (phi_n * for each y in alist product (1+sin y)/2);
    end;

% VALUE OF K(m)

procedure k_function(m);
begin scalar agm, an;
   agm := agm_function(1,sqrt(1-m^2),m);
   an  := first second agm;
   return pi/(2*an);
end;

%######################################################################

% Value of EllipticE(phi,m)

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

%######################################################################

% Value of Jacobi epsilon function

procedure je_function(phi,m);
   %% This function crashed for m >1 and some complex values of m
   %% and is not currently used.
   e_function(num_jacobiam(phi, m), m);

%######################################################################

%Increases the precision used to evaluate algebraic arguments.

symbolic procedure  n_elliptic (u);
% check that length u >= 2 !
 if length u < 2 then
         rederr "illegal call to n_elliptic" else
   begin scalar oldprec,res;
     oldprec := precision(0);
     precision max(oldprec+4,16);

    res :=  aeval u;
    precision oldprec;
    return res;

  end;

put('num_elliptic, 'psopfn, 'n_elliptic);

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
% New routines for the numerical evaluation of symmetric elliptic integrals
% added by Alan Barnes, February 2022.

% see DLMF 19.36(ii) for more details on the numerical computation of
% the symmetric elliptic integrals RF, RD, RJ, and the elementary intgeral RC.
% Also for the use of these symmetric integrals in the evaluation of
% elliptic integrals and the inverse Jacobi functions,
% see DLMF 19.25(i)and 19.25(v).

% The elementary integral RC(x,y) is the definite integral w.r.t. t
% from zero to +infinty of
%     1/(sqrt(4(t+x))*(t+y)).
% For convergence the parameters (possibly complex) must satisfy the conditions:
% x is non-negative and y is non-zero.
% If y is negative, the Cauchy principal value of the integral is computed.
% Logarithmic, inverse circular and hyperbolic functions are all expressible
% in terms of RC.

% The symmetric elliptic integral RF(x,y,z) of the first kind is the definite
% integral w.r.t. t from zero to +infinty of
%     1/sqrt(4(t+x)(t+y)(t+z)).
% For convergence the parameters (possibly complex) must be all be non-negative
% with at most one equal to zero. If one of the parameters is zero, the
% integral is said to be complete, otherwise it is incomplete.

% The semi-symmetric elliptic integral RD(x,y,z) of the second kind is the
% definite integral w.r.t. t from zero to +infinty of
%     3/sqrt(4(t+x)(t+y)(t+z)^3).
% For convergence the parameters (possibly complex) must satisfy the conditions:
% x & y are both non-negative with both x+y & z not negative and not zero.
% If one of the first two parameters is zero, the  integral is said to be
% complete, otherwise it is incomplete.

% The semi-symmetric elliptic integral RJ(x,y,z,p) of the third kind is the
% definite integral w.r.t. t from zero to +infinty of
%     3/(sqrt(4(t+x)(t+y)(t+z))*(t+p)).
% For convergence the parameters (possibly complex) must satisfy the conditions:
% x, y & z are all non-negative with at most one of them zero and p is non-zero.
% If one of the first three parameters is zero, the  integral is said to be
% complete, otherwise it is incomplete.  If p is negative, the Cauchy principal
% value of the integral is computed.

% The code for the next 4 functions is essentially a translation from
% Fortran of the code of Carlson & Notis (1987) generalised for complex
% arguments and structured to avoid GO TO.

% for the next 4 procedures:
% for purely real arguments, it is sufficient that the switch ROUNDED is ON;
% however, for complex arguments the switch COMPLEX must also be ON.

algebraic procedure RC(x,y);
   begin scalar tmp,mu,sn,w,oldprec,tol;
      if impart x =0 and x <0 then
	 rederr("RC: first parameter must be non-negative");
      if y = 0 then
	 rederr("RC: second parameter must be non-zero");
      w := 1;
      if impart y = 0 and y<0 then <<
	 tmp := x-y;
	 y := -y;
	 w := sqrt(x)/sqrt(tmp);
	 x := tmp;
      >>;
      oldprec := precision(0);
      precision max(oldprec+4,16);
      tmp := ceiling(oldprec/3); 
      tol := 10.0^(-tmp);  
      % relative truncation error of result approx. 10^-(2*oldprec)
      tmp := t;
      while tmp do <<
	 mu := (x+2*y)/3;
	 sn := (y+mu)/mu-2;
         if abs sn < tol then
	    tmp := nil
	 else <<
	    lamda := 2*sqrt(x)*sqrt(y) + y;
	    x := (x+lamda)/4;
	    y := (y+lamda)/4;
	 >>;
      >>;
      tmp := sn*sn*(3/10 + sn*(1/7 + sn*(3/8 + 9*sn/22)));
      tmp := w*(1 + tmp)/sqrt mu;
      precision(oldprec);
      return tmp;
   end;

% uses Carlson's duplication method
algebraic procedure RF(x,y,z);
   begin scalar dx,dy,dz,xr,yr,zr,mu,lamda,e2, e3,tol,tmp,oldprec,n:=0;
      if impart x=0  then
         << tmp := sign x;
            if tmp = -1 then
	       rederr("divergent integral RF: negative first argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart y=0  then
         << tmp := sign y;
            if tmp = -1 then
	       rederr("divergent integral RF: negative second argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart z=0  then
         << tmp := sign z;
            if tmp = -1 then
	       rederr("divergent integral RF: negative third argument");
 	    if tmp = 0 then n := n+1;
	 >>;
      if n>1 then
	 rederr("divergent integral RF: more than one argument is zero");
      
      oldprec := precision(0);
      precision max(oldprec+4,16);
      n := ceiling(oldprec/3); 
      tol := 10.0^(-n);  
      % relative trunction error of result approx. 10^-(2*oldprec)
      tmp := t;
      while tmp do <<
      	 mu := (x+y+z)/3;
      	 dx :=2-(mu+x)/mu; dy :=2-(mu+y)/mu; dz :=2-(mu+z)/mu;
      	 if max(abs(dx), abs(dy), abs(dz)) < tol then
	    tmp := nil
	 else  <<
	    xr := sqrt x; yr := sqrt y; zr := sqrt z;
	    lamda := xr*(yr+zr)+yr*zr;
	    x := (x+lamda)/4;
	    y := (y+lamda)/4;
	    z := (z+lamda)/4;
	 >>;
      >>;
      e2 := dx*dy-dz*dz;
      e3 := dx*dy*dz;
      tmp := (1 + e2*(e2/24-3*e3/44-1/10)+e3/14)/sqrt(mu);
      precision(oldprec);
      return tmp
   end;

algebraic procedure RD(x,y,z);
   begin scalar dx,dy,dz,xr,yr,zr,mu,lamda,sigma,e1,e2,e3,e4,
	        tol,tmp,oldprec,pow;
      if impart x=0 and x<0 then
      	 rederr("divergent integral RD: first argument is negative")
      else if impart y=0 and y<0 then
      	 rederr("divergent integral RD: second argument is negative")
      else if impart(x+y)=0 and x+y<=0 then
      	 rederr("divergent integral RD: sum of first two aruments <= 0")
      else if impart z =0 and z<=0 then
      	 rederr("divergent integral RD: third argument <= 0");

      oldprec := precision(0);
      precision max(oldprec+4,16);
      tmp := ceiling(oldprec/3); 
      tol := 10.0^(-tmp);  
      tmp := t; sigma := 0; pow := 1;
      while tmp do <<
	 mu := (x+y+3*z)/5;
	 dx := (mu-x)/mu; dy := (mu-y)/mu; dz := (mu-z)/mu;
      	 if max(abs(dx), abs(dy), abs(dz)) < tol then
	    tmp := nil
	 else <<
	    xr := sqrt x; yr := sqrt y; zr := sqrt z;
	    lamda := xr*(yr+zr)+yr*zr;
	    sigma := sigma+pow/(zr*(z+lamda));
	    x := (x+lamda)/4;
	    y := (y+lamda)/4;
	    z := (z+lamda)/4;
	    pow := pow/4;
	 >>;
      >>;
      e1 := dx*dy;
      tmp := dz*dz;
      e2 := e1-tmp;
      e3 := e1 - 6*tmp;
      e4 := e3+2*e2;
      tmp := e3*(-3/14 + 9/88*e3 - 9/52*dz*e4);
      e1 := dz*(1/6*e4 + dz*(-9/22*e2 + 3/26*dz*e1));
      tmp := 3*sigma + pow*(1+tmp+e1)/(mu*sqrt mu);
      precision(oldprec);
      return tmp;
   end;

algebraic procedure RJ(x,y,z,p);
   begin scalar oldprec,tol,dx,dy,dz,dp,xr,yr,zr,pow,tmp,rcx,
	 oldp,a,b,tmp2,tmp3,sigma,alfa,beta,mu,lamda,n,
         ea,eb,ec,e1,e2;
      n := 0;
      if p = 0 then
	 rederr("divergent integral RJ: fourth argument is zero");
      if impart x=0  then
         << tmp := sign x;
            if tmp = -1 then
	       rederr("divergent integral RJ: negative first argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart y=0  then
         << tmp := sign y;
            if tmp = -1 then
	       rederr("divergent integral RJ: negative second argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart z=0  then
         << tmp := sign z;
            if tmp = -1 then
	       rederr("divergent integral RJ: negative third argument");
 	    if tmp = 0 then n := n+1;
	 >>;
      if n>1 then
	 rederr("divergent integral RJ: more than 1 of first 3 args are zero");
      
      oldprec := precision(0);
      precision max(oldprec+4,16);
      n := ceiling(oldprec/3); 
      tol := 10.0^(-n);  

      oldp := p;
      if p < 0 then <<
	 if y = 0 then <<
	    tmp := x; x := y; y := tmp;
	 >>;
	 a := 1/(y-p);
	 b := a*(z-y)*(y-x);
	 tmp := y+b;
	 tmp1 := x*z/y;
	 tmp2 :=p*tmp/y;
	 p := tmp;
	 precision(oldprec);
	 rcx:= RC(tmp1,tmp2);
      	 precision max(oldprec+4,16);
      >>;
       
      tmp := t; pow := 1; sigma := 0;
      while tmp do <<
	 mu := (x+y+z+2*p)/5;
	 dx := (mu-x)/mu;
	 dy := (mu-y)/mu;
	 dz := (mu-z)/mu;
	 dp := (mu-p)/mu;
	 if max(abs(dx), abs(dy), abs(dz), abs(dp)) < tol then
	    tmp := nil
	 else <<
	    xr :=sqrt x; yr :=sqrt y; zr := sqrt z;
	    lamda := xr*(yr+zr)+yr*zr;
	    alfa := p*(xr+yr+zr) + xr*yr*zr;
	    alfa := alfa*alfa;
	    beta := p*(p+lamda)^2;
	    precision(oldprec);
	    tmp2 := RC(alfa,beta);
	    precision max(oldprec+4,16);
	    sigma := sigma+pow*tmp2;
	    pow := pow/4;
	    x := (x+lamda)/4;
	    y := (y+lamda)/4;
	    z := (z+lamda)/4;
	    p := (p+lamda)/4;
	 >>;
      >>;
      ea := dx*(dy+dz) + dy*dz;
      eb := dx*dy*dz;
      ec := dp*dp;
      e2 := ea - 3*ec;
      e3 := eb + 2*dp*(ea-ec);
      tmp := 1 + e2*(-3/14 + 9/88*e2 - 9/52*e3);
      tmp2 := eb*(1/6 + 3*dp*(-1/11 + dp/26));
      tmp3 := dp*ea*(1/3 - 3*dp/22) - 1/3*dp*ec;
      tmp := 3*sigma + pow*(tmp+tmp2+tmp3)/(mu*sqrt mu);
      if oldp < 0 then <<
	 precision(oldprec);
      	 tmp2 := RF(x,y,z);
      	 precision max(oldprec+4,16);
         tmp := a*(b*tmp + 3*(rcx-tmp2));
      >>;
      precision(oldprec);
      return tmp;
   end;

% The next 4 functions may well get replaced by alternative versions
% in efnumeric.red using the duplication method for evaluation rather
% than quadratic transformations.
% But they are retained at least in the short term.

% see DLMF 19.36(ii) and 19.25(v) for more details on the
% numerical computation of the symmetric elliptic integral RF and the
% inverse Jacobi functions.

% only valid for real arguments, but works when only rounded is on.
algebraic procedure carlson_RCR(x,y);
   (if x<0 or y=0 then
      rederr("1st parameter of RC must be non-negative and the 2nd non-zero")
    else if y<0 then atanh(sqrt x/z)/z  % Cauchy principal value
    else if y<x then atanh(z/sqrt x)/z 
    else if x = 0 then pi/(2*z)
    else if x<y then atan(z/sqrt x)/z
    else 1/sqrt x) where z=>sqrt(abs(x-y));

% valid for complex arguments but needs both rounded and complex on
algebraic procedure carlson_RC(x,y);
    if y = 0 or (impart x = 0 and x<0) then
      rederr("1st parameter of RC must be non-negative and 2nd non-zero")
    else if x=y then 1/sqrt x
    else if x=0 then pi/(2*sqrt y)
    else (if impart y=0 and y<0 then
             atanh(sqrt x/z)/z % Cauchy principal value
          else atanh(z/sqrt x)/z)  where z => sqrt(x-y);

% only valid for real arguments but works when only rounded is on
algebraic procedure sym_int_RFR(x,y,z);
   begin scalar t0,tn,a0,an,c0,cn,tol,theta,tmp,oldprec,n:=0;
      if x<=0 then
	 if x=0 then n:=n+1
	 else rederr("divergent integral RF: negative first argument");
      if y<=0 then
	 if y=0 then n:=n+1
	 else rederr("divergent integral RF: negative second argument");
      if z<=0 then
	 if z=0 then n:=n+1
	 else rederr("divergent integral RF: negative third argument");
      if n>1 then rederr("divergent integral RF: more than one zero argument");
      oldprec := precision();
      precision max(oldprec+4,16);
      tol := 10.0^-(symbolic !:prec!:);
      % sort arguments into ascending order
      if x>y then <<tmp := y; y:=x; x:=tmp>>;      
      if y>z then <<tmp := z; z:=y; y:=tmp>>;      
      if x>y then <<tmp := y; y:=x; x:=tmp>>;

      % use the faster convergent scheme which depends on
      % whether y > (x+z)/2 or not
      if 2*y >= x+z then <<
	 tmp:=x; x:=z; z:=tmp;
	 % x,y,z now in descending order
	 theta :=-1;
      >>
      else theta :=1; 

      cn := 1;
      t0 := sqrt x;
      a0 := sqrt(abs(x-z));
      c0 := sqrt(abs(x-y));
      n:=0;
      while (abs cn > tol) do <<
	 tn := (t0 + sqrt(t0^2+theta*c0^2))/2;
      	 an := (a0+sqrt(a0^2-c0^2))/2;
         cn :=c0^2/(4*an);
	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
      >>;

      % write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
      y:=tn^2; x:= y+theta+an^2; z:= sqrt(abs(x-y));
      % Now return Carlson's hyperbolic or circular function
      % RC(tn^2+theta*an^2, tn^2) which equals RF(tn^2, tn^2, tn^2+theta*an^2)
      % when theta +1 or -1 respectively
      % Negative second argument not possible in this case?
      if y<x then tmp := atanh(z/sqrt x)/z 
      else if x = 0 then tmp := pi/(2*z)
      else if x<y then tmp := atan(z/sqrt x)/z
      else tmp := 1/sqrt x;
      tmp := carlson_RCR(tn^2+theta*an^2,tn^2);
      precision(oldprec);
      return tmp;
   end;

% valid for complex arguments but needs both rounded and complex on
algebraic procedure sym_int_RF(x,y,z);
   begin scalar t0,tn,a0,an,c0,cn,tol,tmp,oldprec,n:=0;
      if impart x=0  then
         << tmp := sign x;
            if tmp = -1 then
	       rederr("divergent integral RF: negative first argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart y=0  then
         << tmp := sign y;
            if tmp = -1 then
	       rederr("divergent integral RF: negative second argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart z=0  then
         << tmp := sign z;
            if tmp = -1 then
	       rederr("divergent integral RF: negative third argument");
 	    if tmp = 0 then n := n+1;
	 >>;
      if n>1 then
	 rederr("divergent integral RF: more than one argument is zero");
      oldprec := precision();
      precision max(oldprec+4,16);
      tol := 10.0^-(symbolic !:prec!:);
      tmp := abs(y-x);
      tmp2 := abs(z-x);
      if abs(z-x) < tmp then <<
         tmp:=y; y:=z; z:=tmp         
      >>;
      cn := 1;
      t0 := sqrt x;
      a0 := sqrt(z-x);
      c0 := sqrt(y-x);
      n:=0;
      while (abs cn > tol) do <<
	 tn := (t0 + sqrt(t0^2+c0^2))/2;
      	 an := (a0+sqrt(a0^2-c0^2))/2;
         cn :=c0^2/(4*an);
	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
      >>;

      %% write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
      y := tn^2; x := y + an^2; z := sqrt(x-y);
      if x=y then tmp := 1/sqrt x
      else if x=0 then tmp := pi/(2*sqrt y)
      else if impart y=0 and y<0 then  %% can this occur??
             tmp := atanh(sqrt x/z)/z % Cauchy principal value
      else tmp := atanh(z/sqrt x)/z; 
      tmp := carlson_RC(tn^2+an^2,tn^2);
      precision(oldprec);
      return tmp;
   end;

%% 
%% % the following two procedures use alternative methods of evaluation
%% % (probably less efficient) and are mainly for checking consistency.
%% 
%% % For RC, the switch COMPLEX may need to be on even for purely real arguments
%% % It uses inverse hyperbolic tangent with a possibly imaginary parameter.

algebraic procedure RC1(x,y);
begin scalar oldprec, res, z;
   if y = 0 or (impart x = 0 and x<0) then
      rederr("1st parameter of RC must be non-negative and 2nd non-zero");
   oldprec := precision(0);
   precision max(oldprec+4,16);
   if x=y then res := 1/sqrt x
   else if x=0 then res :=pi/(2*sqrt y)
   else <<
      z := sqrt(x-y);
      if impart y=0 and y<0 then
	 res:=  atanh(sqrt x/z)/z % Cauchy principal value
      else res := atanh(z/sqrt x)/z;
   >>;
   precision oldprec;
   return res;
end;

%% % uses quadratic transformations and RC1 above
algebraic procedure RF1(x,y,z);
   begin scalar t0,tn,a0,an,c0,cn,tol,tmp,oldprec,n:=0;
      if impart x=0  then
         << tmp := sign x;
            if tmp = -1 then
	       rederr("divergent integral RF: negative first argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart y=0  then
         << tmp := sign y;
            if tmp = -1 then
	       rederr("divergent integral RF: negative second argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart z=0  then
         << tmp := sign z;
            if tmp = -1 then
	       rederr("divergent integral RF: negative third argument");
 	    if tmp = 0 then n := n+1;
	 >>;
      if n>1 then
	 rederr("divergent integral RF: more than one argument is zero");
      oldprec := precision(0);
      precision max(oldprec+4,16);
      tol := 10.0^-(symbolic !:prec!:);
      tmp := abs(y-x);
      tmp2 := abs(z-x);
      if abs(z-x) < tmp then <<
         tmp:=y; y:=z; z:=tmp         
      >>;
      cn := 1;
      t0 := sqrt x;
      a0 := sqrt(z-x);
      c0 := sqrt(y-x);
      n:=0;
      while (abs cn > tol) do <<
	 tn := (t0 + sqrt(t0^2+c0^2))/2;
      	 an := (a0+sqrt(a0^2-c0^2))/2;
         cn :=c0^2/(4*an);
	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
      >>;

%% %     write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
%%       y := tn^2; x := y + an^2; z := sqrt(x-y);
%%       if x=y then tmp := 1/sqrt x
%%       else if x=0 then tmp := pi/(2*sqrt y)
%%       else if impart y=0 and y<0 then  %% can this occur??
%%              tmp := atanh(sqrt x/z)/z % Cauchy principal value
%%       else tmp := atanh(z/sqrt x)/z; 
      tmp := RC1(tn^2+an^2,tn^2);
      precision(oldprec);
      return tmp;
   end;

%#####################################################################
% Basic elliptic integrals

algebraic procedure check_dependence(f1, f2);
   if first(f1)*second(f2) - first(f2)*second(f1) = 0 then
      rederr "Factors in elliptic integral not independent";

algebraic procedure check_factors(fac1, fac2, fac3, fac4, fac5);
<<
   check_dependence(fac1, fac2);
   check_dependence(fac1, fac3);
   check_dependence(fac1, fac4);
   check_dependence(fac2, fac3);
   check_dependence(fac2, fac4);
   check_dependence(fac3, fac4);
   if fac5 neq 0 then <<
      check_dependence(fac1, fac5);
      check_dependence(fac2, fac5);
      check_dependence(fac3, fac5);
      check_dependence(fac4, fac5);
   >>;
>>;

algebraic procedure ellint_1st(lowlim, uplim, fac1, fac2, fac3, fac4);
   begin scalar x1,x2,x3,x4, y1,y2,y3,y4, u12, u13, u23;
      check_factors(fac1, fac2, fac3, fac4, 0);
      if uplim=infinity and lowlim=-infinity then
      	 ellint_1st(-infinity, 0, fac1, fac2, fac3, fac4) +
	 ellint_1st(0, infinity, fac1, fac2, fac3, fac4);

      if uplim = infinity then <<
	 x1 := sqrt(second(fac1));
	 x2 := sqrt(second(fac2));
	 x3 := sqrt(second(fac3));
	 x4 := sqrt(second(fac4));
      >>
      else <<
	 x1 := sqrt(first(fac1)+second(fac1)*uplim);
	 x2 := sqrt(first(fac2)+second(fac2)*uplim);
	 x3 := sqrt(first(fac3)+second(fac3)*uplim);
	 x4 := sqrt(first(fac4)+second(fac4)*uplim);
      >>;

      if lowlim = -infinity then <<
	 y1 := sqrt(-second(fac1));
	 y2 := sqrt(-second(fac2));
	 y3 := sqrt(-second(fac3));
	 y4 := sqrt(-second(fac4));
      >> else <<
	 y1 := sqrt(first(fac1)+second(fac1)*lowlim);
	 y2 := sqrt(first(fac2)+second(fac2)*lowlim);
	 y3 := sqrt(first(fac3)+second(fac3)*lowlim);
	 y4 := sqrt(first(fac4)+second(fac4)*lowlim);
      >>;

      u12 := x1*x2*y3*y4 + y1*y2*x3*x4;
      u13 := x1*x3*y2*y4 + y1*y3*x2*x4;
      u23 := x2*x3*y1*y4 + y2*y3*x1*x4;

      if uplim neq infinity and lowlim neq -infinity then <<
	 u12 := u12/(uplim-lowlim);
	 u13 := u13/(uplim-lowlim);
	 u23 := u23/(uplim-lowlim);
      >>;
      return 2*RF(u12^2, u13^2, u23^2);
   end;


algebraic procedure ellint_2nd(lowlim, uplim, fac1, fac2, fac3, fac4);
   begin scalar x1,x2,x3,x4, y1,y2,y3,y4, u12, u13, u23, d12, d13;
      check_factors(fac1, fac2, fac3, fac4, 0);
      if uplim=infinity and lowlim=-infinity then return
   	 ellint_2nd(-infinity, 0, fac1, fac2, fac3, fac4) +
      	 ellint_2nd(0, infinity, fac1, fac2, fac3, fac4);

      if uplim = infinity then <<
	 x1 := sqrt(second(fac1));
	 x2 := sqrt(second(fac2));
	 x3 := sqrt(second(fac3));
	 x4 := sqrt(second(fac4));
      >>
      else <<
	 x1 := sqrt(first(fac1)+second(fac1)*uplim);
	 x2 := sqrt(first(fac2)+second(fac2)*uplim);
	 x3 := sqrt(first(fac3)+second(fac3)*uplim);
	 x4 := sqrt(first(fac4)+second(fac4)*uplim);
      >>;

      if lowlim = -infinity then <<
	 y1 := sqrt(-second(fac1));
	 y2 := sqrt(-second(fac2));
	 y3 := sqrt(-second(fac3));
	 y4 := sqrt(-second(fac4));
      >> else <<
	 y1 := sqrt(first(fac1)+second(fac1)*lowlim);
	 y2 := sqrt(first(fac2)+second(fac2)*lowlim);
	 y3 := sqrt(first(fac3)+second(fac3)*lowlim);
	 y4 := sqrt(first(fac4)+second(fac4)*lowlim);
      >>;

      u23 := x2*x3*y1*y4 + y2*y3*x1*x4;
      if u23=0 then   % awkward case. Note confusing use of d12, d13, u12
	 if second(fac2) neq 0 then <<
	    d12 := first(fac1)*second(fac2) - first(fac2)*second(fac1);
	    d13 := first(fac2)*second(fac4) - first(fac4)*second(fac2); % d24
	    u12 := ellint_2nd(lowlim,uplim,fac2,fac1,fac3,fac4);
	    return (second(fac1)+second(fac4)*d12/d13)*u12/second(fac2) -
	       d12/d13*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >> else <<
	    d12 := first(fac1)*second(fac3) - first(fac3)*second(fac1); % d13
	    d13 := first(fac3)*second(fac4) - first(fac4)*second(fac3); % d34 
	    u12 := ellint_2nd(lowlim,uplim,fac3,fac1,fac3,fac4);
	    return (second(fac1)+second(fac4)*d12/d13)*u12/second(fac3) -
	       d12/d13*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>;

      % generic case
      u12 := x1*x2*y3*y4 + y1*y2*x3*x4;
      u13 := x1*x3*y2*y4 + y1*y3*x2*x4;

      if uplim neq infinity and lowlim neq -infinity then <<
	 u12 := u12/(uplim-lowlim);
	 u13 := u13/(uplim-lowlim);
	 u23 := u23/(uplim-lowlim);
      >>;

      d12 := first(fac1)*second(fac2) - first(fac2)*second(fac1);
      if u23 neq 0 and u12^2 neq u13^2 then
	 d13 := first(fac1)*second(fac3) - first(fac3)*second(fac1)
      else <<  % swap  u232 & u13
	 y2 := u13; u13 := u23; u23 := y2;
	 d13 := first(fac2)*second(fac3) - first(fac3)*second(fac2);
      >>;
      return 2*d12*d13*RD(u12^2, u13^2, u23^2)/3 +2*x1*y1/(x4*y4*u23);
   end;


algebraic procedure ellint_3rd(lowlim, uplim, fac1, fac2, fac3, fac4, fac5);
   begin scalar x1,x2,x3,x4,y1,y2,y3,y4,
	 u12,u13,u23,  d12,d13,d14,d15,d25, u15,s15,q15;
      check_factors(fac1, fac2, fac3, fac4, 0);
      if uplim=infinity and lowlim=-infinity then
   	 ellint_3rd(-infinity, 0, fac1, fac2, fac3, fac4, fac5) +
      	 ellint_3rd(0, infinity, fac1, fac2, fac3, fac4, fac5);

      if uplim = infinity then <<
      	 x1 := sqrt(second(fac1));
      	 x2 := sqrt(second(fac2));
      	 x3 := sqrt(second(fac3));
      	 x4 := sqrt(second(fac4));
      	 x5 := sqrt(second(fac5));
      >>
      else <<
      	 x1 := sqrt(first(fac1)+second(fac1)*uplim);
      	 x2 := sqrt(first(fac2)+second(fac2)*uplim);
      	 x3 := sqrt(first(fac3)+second(fac3)*uplim);
      	 x4 := sqrt(first(fac4)+second(fac4)*uplim);
      	 x5 := sqrt(first(fac5)+second(fac5)*uplim);
      >>;
    
      if lowlim = -infinity then <<
      	 y1 := sqrt(-second(fac1));
      	 y2 := sqrt(-second(fac2));
      	 y3 := sqrt(-second(fac3));
      	 y4 := sqrt(-second(fac4));
      	 y5 := sqrt(-second(fac5));
      >> else <<
      	 y1 := sqrt(first(fac1)+second(fac1)*lowlim);
      	 y2 := sqrt(first(fac2)+second(fac2)*lowlim);
      	 y3 := sqrt(first(fac3)+second(fac3)*lowlim);
      	 y4 := sqrt(first(fac4)+second(fac4)*lowlim);
      	 y5 := sqrt(first(fac5)+second(fac5)*lowlim);
      >>;
      if x1=0 or y1=0 then   % awkward case
	 if x2 neq 0 and y2 neq 0 and second(fac2) neq 0 then <<
	    d12 := first(fac1)*second(fac2) - first(fac2)*second(fac1);
	    d25 := first(fac2)*second(fac5) - first(fac5)*second(fac2); 
	    u12 := ellint_3rd(lowlim,uplim,fac2,fac1,fac3,fac4,fac5);
	    return (second(fac1)+second(fac5)*d12/d25)*u12/second(fac2) -
	       d12/d25*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>
	 else if x3 neq 0 and y3 neq 0 and second(fac3) neq 0 then
     	 <<
	    d13 := first(fac1)*second(fac3) - first(fac3)*second(fac1);
	    d35 := first(fac3)*second(fac4) - first(fac4)*second(fac3);
	    u12 := ellint_3rd(lowlim,uplim,fac3,fac1,fac2,fac4,fac5);
	    return (second(fac1)+second(fac5)*d13/d35)*u12/second(fac3) -
	       d13/d35*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >> else <<
	    d14 := first(fac1)*second(fac4) - first(fac4)*second(fac1);
	    d45 := first(fac4)*second(fac5) - first(fac5)*second(fac4);
	    u12 := ellint_3rd(lowlim,uplim,fac4,fac1,fac2,fac3,fac5);
	    return (second(fac1)+second(fac5)*d14/d45)*u12/second(fac4) -
	       d14/d45*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>;
	 
      % generic case	    
      u12 := x1*x2*y3*y4 + y1*y2*x3*x4;
      u13 := x1*x3*y2*y4 + y1*y3*x2*x4;
      u23 := x2*x3*y1*y4 + y2*y3*x1*x4;
      s15 := (x2*x3*x4*y5^2/x1  + y2*y3*y4*x5^2/y1);
 
      if uplim neq infinity and lowlim neq -infinity then <<
      	 u12 := u12/(uplim-lowlim);
      	 u13 := u13/(uplim-lowlim);
      	 u23 := u23/(uplim-lowlim);
      	 s15 := s15/(uplim-lowlim);
      >>;

      d12 := first(fac1)*second(fac2) - first(fac2)*second(fac1);
      d13 := first(fac1)*second(fac3) - first(fac3)*second(fac1);
      d14 := first(fac1)*second(fac4) - first(fac4)*second(fac1);
      d15 := first(fac1)*second(fac5) - first(fac5)*second(fac1);
      d25 := first(fac2)*second(fac5) - first(fac5)*second(fac2);
      d35 := first(fac3)*second(fac5) - first(fac5)*second(fac3);
      d45 := first(fac4)*second(fac5) - first(fac5)*second(fac4);

      u15 := u12^2 - d13*d14*d25/d15;  % actually u15^2
      q15 := (x5*y5)^2/(x1*y1)^2*u15; % actually q15^2
      return 2*d12*d13*d14*RJ(u12^2, u13^2, u23^2, u15)/(3*d15) + 2*RC(s15^2,q15);
   end;

endmodule;

;end;