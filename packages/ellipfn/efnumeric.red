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

%Increases the precision used to evaluate algebraic arguments
% and temporarily switches COMPLEX ON.

symbolic procedure n_elliptic(u);
   % check that length u >= 2 !
   if length u < 2 then
      rederr "illegal call to n_elliptic" else
      begin scalar offcomplex, !*msg, oldprec, res;
         if not !*complex then <<
            offcomplex := t;
            on1 'complex
         >>;
         oldprec := precision(0);
         precision max(oldprec+4,16);
         % Must catch any errors here and then tidy up before
         % re-throwing the error or returning.
         res := errorset!*({'aeval, mkquote u}, nil);
         precision oldprec;
         if offcomplex then off1 'complex else on1 'complex;
         if errorp res then
            error(res, emsg!*)
         else
	    return reval car res;
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

algebraic procedure tidy_result(res);
% Remove a spurious real or imaginary part from result
begin scalar rp,ip,tmp;
   tmp := reimpart res;
   rp := first tmp;
   ip := second tmp;
   tmp := 10.0^-(symbolic !:prec!:-4);
   if ip=0 or rp=0 then return res
   else if abs(ip/rp) <tmp then return rp
   else if abs(rp/ip) <tmp then return i*ip
   else return res;
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
      lisp error(99, "RC: 1st parameter must be non-negative");
      if y = 0 then
      lisp error(99, "RC: 2nd parameter must be non-zero");
      w := 1;
      if impart y = 0 and y<0 then <<
	 tmp := x-y;
	 y := -y;
	 w := sqrt(x)/sqrt(tmp);
	 x := tmp;
      >>;
      oldprec := precision(0);
      tmp := ceiling(oldprec/3);
      tol := 10.0^(-tmp);
      % relative truncation error of result approx. 10^-(2*oldprec)
      mu := (x+2*y)/3;
      if mu =0 then <<
      	 lamda := 2*sqrt(x)*sqrt(y) + y;
	 x := (x+lamda)/4;
	 y := (y+lamda)/4;
      >>;

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
      return tmp;
   end;

algebraic procedure symint_check(x,y,z);
   begin scalar tmp,n;
      n := 0;
      if impart x=0  then
         << tmp := sign x;
            if tmp = -1 then
               rederr("divergent integral: negative 1st argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart y=0  then
         << tmp := sign y;
            if tmp = -1 then
      	       rederr("divergent integral: negative 2nd argument");
 	    if tmp = 0 then n := n+1
	 >>;
      if impart z=0  then
         << tmp := sign z;
            if tmp = -1 then
      	       rederr("divergent integral: negative 3rd argument");
 	    if tmp = 0 then n := n+1;
	 >>;
      if n>1 then
         rederr("divergent integral: more than one argument is zero");
      return n;
end;

% uses Carlson's duplication method
algebraic procedure RF(x,y,z);
   begin scalar dx,dy,dz,xr,yr,zr,mu,lamda,e2, e3,tol,tmp,oldprec;
      tmp := symint_check(x,y,z);
      if tmp=1 then return  % one zero parameter
      	 if x=0 then  RF0(y,z)
	 else if y=0 then RF(x,z) else RF0(x,y);
      
      % relative trunction error of result approx. 10^-(2*oldprec)
      oldprec := precision(0);
      tol := 10.0^-ceiling(oldprec/3);
      mu := (x+y+z)/3;
      tmp := nil;
      repeat <<
	 xr := sqrt x; yr := sqrt y; zr := sqrt z;
	 lamda := xr*(yr+zr)+yr*zr;
	 x := (x+lamda)/4;
	 y := (y+lamda)/4;
	 z := (z+lamda)/4;
	 mu := (x+y+z)/3;
      	 dx :=2-(mu+x)/mu; dy :=2-(mu+y)/mu; dz :=2-(mu+z)/mu;
      	 if max(abs(dx), abs(dy), abs(dz)) < tol then
	    tmp := t;
      >> until tmp;
      
      e2 := dx*dy-dz*dz;
      e3 := dx*dy*dz;
      tmp := (1 + e2*(e2/24-3*e3/44-1/10)+e3/14)/sqrt(mu);
      return tmp
   end;

algebraic procedure RD(x,y,z);
   begin scalar dx,dy,dz,xr,yr,zr,mu,lamda,sigma,e1,e2,e3,e4,
	        tol,tmp,pow, oldprec;
      tmp := symint_check(x,y,z);
      if tmp=1 then
	 if z=0 then
      	    rederr("divergent integral RD: third argument  is zero")
         else if y=0 then return RD0(x,z) else return RD0(y,z);

    % relative trunction error of result approx. 10^-(2*oldprec)
      oldprec := precision(0);
      tol := 10.0^-ceiling(oldprec/3);

      sigma := 0; pow := 1;
      tmp := nil;
      repeat <<
         xr := sqrt x; yr := sqrt y; zr := sqrt z;
	 lamda := xr*(yr+zr)+yr*zr;
	 sigma := sigma+pow/(zr*(z+lamda));
	 x := (x+lamda)/4;
	 y := (y+lamda)/4;
	 z := (z+lamda)/4;
	 pow := pow/4;
	 mu := (x+y+3*z)/5;	 
	 dx := (mu-x)/mu; dy := (mu-y)/mu; dz := (mu-z)/mu;
      	 if max(abs(dx), abs(dy), abs(dz)) < tol then
	    tmp := t;
      >> until tmp;

      e1 := dx*dy;
      tmp := dz*dz;
      e2 := e1-tmp;
      e3 := e1 - 6*tmp;
      e4 := e3+2*e2;
      tmp := e3*(-3/14 + 9/88*e3 - 9/52*dz*e4);
      e1 := dz*(1/6*e4 + dz*(-9/22*e2 + 3/26*dz*e1));
      tmp := 3*sigma + pow*(1+tmp+e1)/(mu*sqrt mu);
      return tmp;
   end;

algebraic procedure RJ1(x,y,z,p);
% Called when p is real and negative. Returns the principal value.
begin scalar a,b, tmp, tmp1, tmp2;
   if y = 0 then <<
      tmp := x; x := 0; y := tmp;
   >>;
   a := 1/(y-p);
   b := a*(z-y)*(y-x);
   tmp := y+b;
   tmp1 := x*z/y;
   tmp2 :=p*tmp/y;
   p := tmp;
   tmp1 := RC(tmp1,tmp2);
   tmp := RJ(x,y,z,p);
   tmp2 := RF(x,y,z);
   return a*(b*tmp + 3*(tmp1-tmp2));
end;

algebraic procedure RJ(x,y,z,p);
   begin scalar tol,dx,dy,dz,dp,xr,yr,zr,tmp,tmp1,
	 oldp, mu,lamda,delta,d,pow,r,s,
         ea,eb,ec,e1,e2;
      if p = 0 then
	 rederr ("divergent integral RJ: 4th argument is zero");
      tmp := symint_check(x,y,z);
      if impart p=0 and p<0 then
	 return RJ1(x,y,z,p);
      
      oldp := precision(0);
      tol := 10.0^-ceiling(oldp/3);

      pow :=1;
      delta := (p-x)*(p-y)*(p-z);

      tmp1 := sqrt p;
      xr := sqrt x; yr := sqrt y; zr := sqrt z;
      d := (tmp1+xr)*(tmp1+yr)*(tmp1+zr);
      s := d/2;
      
      tmp := nil;
      repeat <<
      	 pow :=pow/4;
      	 lamda := xr*(yr+zr)+yr*zr;
      	 x := (x+lamda)/4;
      	 y := (y+lamda)/4;
      	 z := (z+lamda)/4;
      	 p := (p+lamda)/4;
      	 r := s*(1+sqrt(1+pow*delta/s^2));
      	 xr := sqrt x; yr := sqrt y; zr := sqrt z;
      	 tmp1 := sqrt p;
      	 d := (tmp1+xr)*(tmp1+yr)*(tmp1+zr);

	 mu := (x+y+z+2*p)/5;
	 dx := (mu-x)/mu;
	 dy := (mu-y)/mu;
	 dz := (mu-z)/mu;
	 dp := (mu-p)/mu;
	 if max(abs(dx), abs(dy), abs(dz), abs(dp)) < tol then
	    tmp := t
	 else <<
	    xr :=sqrt x; yr :=sqrt y; zr := sqrt z;
      	    s := (d*r-pow^2*delta)/(2*(d+pow*r));
	 >>
      >> until tmp;

      ea := dx*(dy+dz) + dy*dz;
      eb := dx*dy*dz;
      ec := dp*dp;
      e2 := ea - 3*ec;
      e3 := eb + 2*dp*(ea-ec);
      tmp := 1 + e2*(-3/14 + 9/88*e2 - 9/52*e3);
      tmp2 := eb*(1/6 + 3*dp*(-1/11 + dp/26));
      tmp3 := dp*ea*(1/3 - 3*dp/22) - 1/3*dp*ec;
      tmp := pow*(tmp+tmp2+tmp3)/(mu*sqrt mu);
      return tmp+3*RC(1, 1+pow*delta/s^2)/s;
   end;

algebraic procedure RG(x,y,z);
begin scalar n, tmp;
    tmp := symint_check(x,y,z);
    if tmp=1 then
       if  z=0 then
       	  return RG0(x,y)
       else if x=0 then
	  return RG0(y,z)
       else return RG0(x,z);
    % no zero parameters
       return z*RF(x,y,z)/2-(x-z)*(y-z)*RD(x,y,z)/6+sqrt(x*y/z)/2;
end;

algebraic procedure RF0(x,y);
begin scalar xr,yr,tol,oldp,tmp;
   oldp := precision(0);
   tol := 10.0^-ceiling(oldp/2);
   tmp := t;
   xr := sqrt x; yr := sqrt y;
   while tmp do <<
      x := (xr+yr)/2;
      y := sqrt(xr*yr);
      if abs(x-y) < 2.7*tol*abs x then
	 tmp := nil
      else << xr := x; yr := y>>;
   >>;
   return pi/(x+y);
end;

algebraic procedure RG0(x,y);
begin scalar xr,yr,tol,oldp,tmp,s,d;
   oldp := precision(0);
   tol := 10.0^-ceiling(oldp/2);
   tmp := t;
   xr := sqrt x; yr := sqrt y;
   s := (xr+yr)^2/4;
   d := 1/2;
   while tmp do <<
      x := (xr+yr)/2;
      y := sqrt(xr*yr);
      s :=s -(x-y)^2*d;
      d :=d*2;
      if abs(x-y) < 2.7*tol*abs x then
	 tmp := nil
      else << xr := x; yr := y>>;
   >>;
   return s/2*pi/(x+y);
end;

algebraic procedure RD0(x,y);
   if x=0 or y=0 then
      rederr("RD: divergent integral (2 zero arguments)")
   else if x=y then 3pi*y^(-3/2)/4
   else 3*(2*RG0(x,y)-y*RF0(x,y))/(y*(x-y));  

% The next 4 functions may well get replaced by alternative versions
% in efnumeric.red using the duplication method for evaluation rather
% than quadratic transformations.
% But they are retained at least in the short term.

% see DLMF 19.36(ii) and 19.25(v) for more details on the
% numerical computation of the symmetric elliptic integral RF and the
% inverse Jacobi functions.

% only valid for real arguments, but works when only rounded is on.
%% algebraic procedure carlson_RCR(x,y);
%%    (if x<0 or y=0 then
%%       rederr("1st parameter of RC must be non-negative and the 2nd non-zero")
%%     else if y<0 then atanh(sqrt x/z)/z  % Cauchy principal value
%%     else if y<x then atanh(z/sqrt x)/z
%%     else if x = 0 then pi/(2*z)
%%     else if x<y then atan(z/sqrt x)/z
%%     else 1/sqrt x) where z=>sqrt(abs(x-y));
%%
%% % valid for complex arguments but needs both rounded and complex on
%% algebraic procedure carlson_RC(x,y);
%%     if y = 0 or (impart x = 0 and x<0) then
%%       rederr("1st parameter of RC must be non-negative and 2nd non-zero")
%%     else if x=y then 1/sqrt x
%%     else if x=0 then pi/(2*sqrt y)
%%     else (if impart y=0 and y<0 then
%%              atanh(sqrt x/z)/z % Cauchy principal value
%%           else atanh(z/sqrt x)/z)  where z => sqrt(x-y);
%%
%% % only valid for real arguments but works when only rounded is on
%% algebraic procedure sym_int_RFR(x,y,z);
%%    begin scalar t0,tn,a0,an,c0,cn,tol,theta,tmp,oldprec,n:=0;
%%       if x<=0 then
%% 	 if x=0 then n:=n+1
%% 	 else rederr("divergent integral RF: negative first argument");
%%       if y<=0 then
%% 	 if y=0 then n:=n+1
%% 	 else rederr("divergent integral RF: negative second argument");
%%       if z<=0 then
%% 	 if z=0 then n:=n+1
%% 	 else rederr("divergent integral RF: negative third argument");
%%       if n>1 then rederr("divergent integral RF: more than one zero argument");
%%       oldprec := precision();
%%       precision max(oldprec+4,16);
%%       tol := 10.0^-(symbolic !:prec!:);
%%       % sort arguments into ascending order
%%       if x>y then <<tmp := y; y:=x; x:=tmp>>;
%%       if y>z then <<tmp := z; z:=y; y:=tmp>>;
%%       if x>y then <<tmp := y; y:=x; x:=tmp>>;
%%
%%       % use the faster convergent scheme which depends on
%%       % whether y > (x+z)/2 or not
%%       if 2*y >= x+z then <<
%% 	 tmp:=x; x:=z; z:=tmp;
%% 	 % x,y,z now in descending order
%% 	 theta :=-1;
%%       >>
%%       else theta :=1;
%%
%%       cn := 1;
%%       t0 := sqrt x;
%%       a0 := sqrt(abs(x-z));
%%       c0 := sqrt(abs(x-y));
%%       n:=0;
%%       while (abs cn > tol) do <<
%% 	 tn := (t0 + sqrt(t0^2+theta*c0^2))/2;
%%       	 an := (a0+sqrt(a0^2-c0^2))/2;
%%          cn :=c0^2/(4*an);
%% 	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
%%       >>;
%%
%%       % write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
%%       y:=tn^2; x:= y+theta+an^2; z:= sqrt(abs(x-y));
%%       % Now return Carlson's hyperbolic or circular function
%%       % RC(tn^2+theta*an^2, tn^2) which equals RF(tn^2, tn^2, tn^2+theta*an^2)
%%       % when theta +1 or -1 respectively
%%       % Negative second argument not possible in this case?
%%       if y<x then tmp := atanh(z/sqrt x)/z
%%       else if x = 0 then tmp := pi/(2*z)
%%       else if x<y then tmp := atan(z/sqrt x)/z
%%       else tmp := 1/sqrt x;
%%       tmp := carlson_RCR(tn^2+theta*an^2,tn^2);
%%       precision(oldprec);
%%       return tmp;
%%    end;
%%
%% % valid for complex arguments but needs both rounded and complex on
%% algebraic procedure sym_int_RF(x,y,z);
%%    begin scalar t0,tn,a0,an,c0,cn,tol,tmp,oldprec,n:=0;
%%       if impart x=0  then
%%          << tmp := sign x;
%%             if tmp = -1 then
%% 	       rederr("divergent integral RF: negative first argument");
%%  	    if tmp = 0 then n := n+1
%% 	 >>;
%%       if impart y=0  then
%%          << tmp := sign y;
%%             if tmp = -1 then
%% 	       rederr("divergent integral RF: negative second argument");
%%  	    if tmp = 0 then n := n+1
%% 	 >>;
%%       if impart z=0  then
%%          << tmp := sign z;
%%             if tmp = -1 then
%% 	       rederr("divergent integral RF: negative third argument");
%%  	    if tmp = 0 then n := n+1;
%% 	 >>;
%%       if n>1 then
%% 	 rederr("divergent integral RF: more than one argument is zero");
%%       oldprec := precision();
%%       precision max(oldprec+4,16);
%%       tol := 10.0^-(symbolic !:prec!:);
%%       tmp := abs(y-x);
%%       tmp2 := abs(z-x);
%%       if abs(z-x) < tmp then <<
%%          tmp:=y; y:=z; z:=tmp
%%       >>;
%%       cn := 1;
%%       t0 := sqrt x;
%%       a0 := sqrt(z-x);
%%       c0 := sqrt(y-x);
%%       n:=0;
%%       while (abs cn > tol) do <<
%% 	 tn := (t0 + sqrt(t0^2+c0^2))/2;
%%       	 an := (a0+sqrt(a0^2-c0^2))/2;
%%          cn :=c0^2/(4*an);
%% 	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
%%       >>;
%%
%%       %% write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
%%       y := tn^2; x := y + an^2; z := sqrt(x-y);
%%       if x=y then tmp := 1/sqrt x
%%       else if x=0 then tmp := pi/(2*sqrt y)
%%       else if impart y=0 and y<0 then  %% can this occur??
%%              tmp := atanh(sqrt x/z)/z % Cauchy principal value
%%       else tmp := atanh(z/sqrt x)/z;
%%       tmp := carlson_RC(tn^2+an^2,tn^2);
%%       precision(oldprec);
%%       return tmp;
%%    end;

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
   begin scalar x1,x2,x3,x4, y1,y2,y3,y4, u12, u13, u23, L;
      check_factors(fac1, fac2, fac3, fac4, 0);
      if uplim=infinity and lowlim=-infinity then
      	 return ellint_1st(-infinity, 0, fac1, fac2, fac3, fac4) +
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
	 y1 := sqrt(second(fac1));
	 y2 := sqrt(second(fac2));
	 y3 := sqrt(second(fac3));
	 y4 := sqrt(second(fac4));
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
      L := u12*u13+u12*u23+u13*u23;
      return 4*RF(u12^2+L, u13^2+L, u23^2+L);	
   end;

algebraic procedure ellint_2nd(lowlim, uplim, fac1, fac2, fac3, fac4);
   begin scalar x1,x2,x3,x4, y1,y2,y3,y4, u12, u13, u23, d2, d3, L,
                s1, s2, s3, M;
      check_factors(fac1, fac2, fac3, fac4, 0);
      if uplim=infinity and lowlim=-infinity then
   	 return ellint_2nd(-infinity, 0, fac1, fac2, fac3, fac4) +
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
	 y1 := sqrt(second(fac1));
	 y2 := sqrt(second(fac2));
	 y3 := sqrt(second(fac3));
	 y4 := sqrt(second(fac4));
      >> else <<
	 y1 := sqrt(first(fac1)+second(fac1)*lowlim);
	 y2 := sqrt(first(fac2)+second(fac2)*lowlim);
	 y3 := sqrt(first(fac3)+second(fac3)*lowlim);
	 y4 := sqrt(first(fac4)+second(fac4)*lowlim);
      >>;
      if x4=0 or y4=0 then
	 rederr("RD: integral diverges");

      u23 := x2*x3*y1*y4 + y2*y3*x1*x4;
      if u23=0 then   % awkward case  x2=0 and y3=0 or vice-versa. 
	 if second(fac2) neq 0 then <<
	    d2 := first(fac1)*second(fac2) - first(fac2)*second(fac1); % d12
	    d3 := first(fac2)*second(fac4) - first(fac4)*second(fac2); % d24
	    L := ellint_2nd(lowlim,uplim,fac2,fac1,fac3,fac4);
	    return (second(fac1)+second(fac4)*d2/d3)*L/second(fac2) -
	       d2/d3*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >> else << % never called? Factors are not independent
	            % integral is actually elementary and finite
	    d2 := first(fac1)*second(fac3) - first(fac3)*second(fac1); % d13
	    d3 := first(fac3)*second(fac4) - first(fac4)*second(fac3); % d34
	    L := ellint_2nd(lowlim,uplim,fac3,fac1,fac3,fac4);
	    return (second(fac1)+second(fac4)*d12/d13)*L/second(fac3) -
	       d2/d3*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>;

      % generic case
      u12 := x1*x2*y3*y4 + y1*y2*x3*x4;
      u13 := x1*x3*y2*y4 + y1*y3*x2*x4;
      s1 := X1*Y4+X4*Y1;
      s2 := X2*Y4+X4*Y2;
      s3 := X3*Y4+X4*Y3; 
      if uplim neq infinity and lowlim neq -infinity then <<
	 u12 := u12/(uplim-lowlim);
	 u13 := u13/(uplim-lowlim);
	 u23 := u23/(uplim-lowlim);
	 M := 2*(uplim-lowlim)*s1/(X4*Y4*s2*s3);
      >>
      else
      	 M := 2*s1/(X4*Y4*s2*s3);
      L := u12*u13+u12*u23+u13*u23;

      d2 := first(fac1)*second(fac2) - first(fac2)*second(fac1);   % d12
      if u12^2 neq u13^2 then
	 d3 := first(fac1)*second(fac3) - first(fac3)*second(fac1)   % d13
      else <<  % swap  u23 & u13
	 y2 := u13; u13 := u23; u23 := y2;    % real y2 not needed
	 d3 := first(fac2)*second(fac3) - first(fac3)*second(fac2);   % d23
      >>;
      return 4*d2*d3*RD(u12^2+L, u13^2+L, u23^2+L)/3 +M;
   end;	



algebraic procedure ellint_3rd(lowlim, uplim, fac1, fac2, fac3, fac4, fac5);
   begin scalar x1,x2,x3,x4,x5,y1,y2,y3,y4,y5,
	 u12,u13,u23,u15,L, d12,d13,d14,d15,d25,d35,d45,
	 b15,c15,t15,p15;
      check_factors(fac1, fac2, fac3, fac4, fac5);
      if uplim=infinity and lowlim=-infinity then
   	 return ellint_3rd(-infinity, 0, fac1, fac2, fac3, fac4, fac5) +
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
      	 y1 := sqrt(second(fac1));
      	 y2 := sqrt(second(fac2));
      	 y3 := sqrt(second(fac3));
      	 y4 := sqrt(second(fac4));
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
	    L := ellint_3rd(lowlim,uplim,fac2,fac1,fac3,fac4,fac5);
	    return (second(fac1)+second(fac5)*d12/d25)*L/second(fac2) -
	       d12/d25*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>
	 else if x3 neq 0 and y3 neq 0 and second(fac3) neq 0 then
     	 <<
	    d13 := first(fac1)*second(fac3) - first(fac3)*second(fac1);
	    d35 := first(fac3)*second(fac4) - first(fac4)*second(fac3);
	    L := ellint_3rd(lowlim,uplim,fac3,fac1,fac2,fac4,fac5);
	    return (second(fac1)+second(fac5)*d13/d35)*L/second(fac3) -
	       d13/d35*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >> else <<
	    d14 := first(fac1)*second(fac4) - first(fac4)*second(fac1);
	    d45 := first(fac4)*second(fac5) - first(fac5)*second(fac4);
	    L := ellint_3rd(lowlim,uplim,fac4,fac1,fac2,fac3,fac5);
	    return (second(fac1)+second(fac5)*d14/d45)*L/second(fac4) -
	       d14/d45*ellint_1st(lowlim,uplim, fac1,fac2,fac3,fac4);
	 >>;

      % generic case
      u12 := x1*x2*y3*y4 + y1*y2*x3*x4;
      u13 := x1*x3*y2*y4 + y1*y3*x2*x4;
      u23 := x2*x3*y1*y4 + y2*y3*x1*x4;
     
      if uplim neq infinity and lowlim neq -infinity then <<
      	 u12 := u12/(uplim-lowlim);
      	 u13 := u13/(uplim-lowlim);
      	 u23 := u23/(uplim-lowlim);
      >>;
      L := u12*u13+u12*u23+u13*u23;

      d12 := first(fac1)*second(fac2) - first(fac2)*second(fac1);
      d13 := first(fac1)*second(fac3) - first(fac3)*second(fac1);
      d14 := first(fac1)*second(fac4) - first(fac4)*second(fac1);
      d15 := first(fac1)*second(fac5) - first(fac5)*second(fac1);
      d25 := first(fac2)*second(fac5) - first(fac5)*second(fac2);
      d35 := first(fac3)*second(fac5) - first(fac5)*second(fac3);
      d45 := first(fac4)*second(fac5) - first(fac5)*second(fac4);

      fac5 := u12^2-d13*d14*d25/d15;
      u15 := sqrt(fac5);  
      
      b15 := d15*(u15+u12)*(u15+u13)*(u15+u23)/(d12*d13*d14);
       if uplim neq infinity and lowlim neq -infinity then 
      	  c15 := (x2*x3*x4*y5^2/x1+y2*y3*y4*x5^2/y1)/(uplim-lowlim)+
	  x5*y5*u15/(x1*y1)
       else
	  c15 := (x2*x3*x4*y5^2/x1+y2*y3*y4*x5^2/y1) + x5*y5*u15/(x1*y1);
      t15 := d25*d35*d45/d15;
      p15 :=(b15*c15+t15)/(b15+c15);
      if p15 neq 0 then
      	 return 4*d12*d13*d14*RJ(u12^2+L, u13^2+L, u23^2+L, fac5+L)/(3*d15)
      	     + 4*RC(1, 1-t15/p15^2)/p15
      else return 4*d12*d13*d14*RJ(u12^2+L, u13^2+L, u23^2+L, fac5+L)/(3*d15)
             + 2pi/sqrt(-t15);
   end;

endmodule;

;end;
