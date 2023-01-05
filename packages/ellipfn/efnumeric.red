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


%Increases the precision used to evaluate algebraic arguments.

symbolic procedure  n_elliptic (u);
% check that length u >= 2 !
 if length u < 2 then
         rederr "illegal call to n_elliptic" else
   begin scalar oldprec,res;
     oldprec := precision(0);
     precision max(oldprec+3,15);

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
      precision(2*oldprec);
      tmp := round(oldprec/3); 
      tol := 10.0^(-tmp);  
      % relative trunction error of result approx. 10^-(2*oldprec)
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
      precision(2*oldprec);    % probably larger than necessary
      n := round(oldprec/3); 
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
      precision(2*oldprec);
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
      precision(2*oldprec);    % probably larger than necessary
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
	 precision(2*oldprec);
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
	    precision(2*oldprec);
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
	 precision(2*oldprec);
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
      precision(2*oldprec);
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
      precision(2*oldprec);
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
   precision(2*oldprec);
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
      precision(2*oldprec);
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

endmodule;

;end;