module efjacinv;  % Procedures and Rules for Inverse Jacobi Elliptic functions.

% Author: Alan Barnes, October 2021

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

% Renamed (was sfellipinv) and moved to a new package ellipfn, December 2021
% by Alan Barnes

algebraic;

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
%%       y:=tn^2; x:= y+theta+an^2; z:= sqrt(abs(x-y));
%%       % Now return Carlson's hyperbolic or circular function
%%       % RC(tn^2+theta*an^2, tn^2) which equals RF(tn^2, tn^2, tn^2+theta*an^2)
%%       % when theta +1 or -1 respectively
%%       % Negative second argument not possible in this case?
%%       if y<x then tmp := atanh(z/sqrt x)/z 
%%       else if x = 0 then tmp := pi/(2*z)
%%       else if x<y then tmp := atan(z/sqrt x)/z
%%       else tmp := 1/sqrt x;
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

%      write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
%%       y := tn^2; x := y + an^2; z := sqrt(x-y);
%%       if x=y then tmp := 1/sqrt x
%%       else if x=0 then tmp := pi/(2*sqrt y)
%%       else if impart y=0 and y<0 then  %% can this occur??
%%              tmp := atanh(sqrt x/z)/z % Cauchy principal value
%%       else tmp := atanh(z/sqrt x)/z; 
      tmp := carlson_RC(tn^2+an^2,tn^2);
      precision(oldprec);
      return tmp;
   end;

operator arcsn;
operator arccn;
operator arcdn;
operator arcns;
operator arcnc;
operator arcnd;
operator arcsc;
operator arccs;
operator arcsd;
operator arcds;
operator arccd;
operator arcdc;

invjacobirules :=
{
 jacobisn(arcsn(~x,~k),~k) => x,
 jacobicn(arccn(~x,~k),~k) => x,
 jacobidn(arcdn(~x,~k),~k) => x,
 jacobins(arcns(~x,~k),~k) => x,
 jacobinc(arcnc(~x,~k),~k) => x,
 jacobind(arcnd(~x,~k),~k) => x,
 jacobisc(arcsc(~x,~k),~k) => x,
 jacobics(arccs(~x,~k),~k) => x,
 jacobisd(arcsd(~x,~k),~k) => x,
 jacobids(arcds(~x,~k),~k) => x,
 jacobicd(arccd(~x,~k),~k) => x,
 jacobidc(arcdc(~x,~k),~k) => x,

 arcsn(~x,0) => asin(x),
 arcsn(~x,1) => atanh(x),
 arcsn(0,~k)  => 0,
 arcsn(-~x,~k) => -arcsn(x,k),
 arcsn(~x,-~k) => arcsn(x,k),
 arcsn(1, ~k) => elliptick(k),

 arcns(~x,0) => acsc(x),
 arcns(~x,1) => acoth(x),
 arcns(-~x,~k) => -arcns(x,k),
 arcns(~x,-~k) => arcns(x,k),
 arcns(1, ~k) => elliptick(k),

 arccn(~x,0) => acos(x),
 arccn(~x,1) => asech(x),
 arccn(0,~k) => elliptick(k),
 arccn(1,~k) => 0,
 arccn(-~x,~k) => 2*elliptick(k)-arccn(x,k),
 arccn(~x,-~k) => arccn(x,k),

 arcnc(~x,0) => asec(x),
 arcnc(~x,1) => acosh(x),
 arcnc(0,~k) => elliptick(k),
 arcnc(-~x,~k) => 2*elliptick(k)-arcnc(x,k),
 arcnc(~x,-~k) => arcnc(x,k),

 arcdn(~x,1) => asech(x),
 arcdn(0,~k) => 1,
 arcdn(sqrt(1-~k^2),~k) => elliptick(k),
 arcdn(~x,-~k) => arcdn(x,k),
 
 arcnd(~x,1) => acosh(x),
 arcnd(0,~k) => 1,
 arcnd(1/sqrt(1-~k^2),~k) => elliptick(k),
 arcnd(~x,-~k) => arcdn(x,k),

 arcsc(~x,0) => atan(x),
 arcsc(~x,1) => asinh(x),
 arcsc(0,~k)  => 0,
 arcsc(-~x,~k) => -arcsc(x,k),
 arcsc(~x,-~k) => arcsc(x,k),

 arccs(~x,0) => if x> 0 then acot(x)
                else acot(x)-pi,
 arccs(~x,1) => acsch(x),
 arccs(0, ~k) => elliptick(k),
 arccs(-~x,~k) => -arccs(x,k),
 arccs(~x,-~k) => arccs(x,k),

 arcsd(~x,0) => asin(x),
 arcsd(~x,1) => asinh(x),
 arcsd(0,~k)  => 0,
 arcsd(-~x,~k) => -arcsd(x,k),
 arcsd(~x,-~k) => arcsd(x,k),

 arcds(~x,0) => acsc(x),
 arcds(~x,1) => acsch(x),
 arcds(-~x,~k) => -arcds(x,k),
 arcds(~x,-~k) => arcds(x,k),
 
 arccd(~x,0) => acos(x),
 arccd(~x,1) => 1,
 arccd(0,~k)  => elliptick(k),
 arccd(-~x,~k) => 2*elliptick(k)-arccd(x,k),
 arccd(~x,-~k) => arccd(x,k),

 arcdc(~x,0) => asec(x),
 arcdc(~x,1) => 1,
 arcdc(-~x,~k) => 2*elliptick(k)-arcdc(x,k),
 arcdc(~x,-~k) => arcdc(x,k),

 df(arcsn(~x,~k),~y) => df(x,y)/(sqrt(1-x^2)*sqrt(1-k^2*x^2)) +
               df(k,y)*(-arcsn(x,k)/k  + ellipticE(asin(x),k)/(k*(1-k^2))
                        -k*x*sqrt((1-x^2)/(1-k^2*x^2))/(1-k^2)),
 
 df(arccn(~x,~k),~y) => -df(x,y)/(sqrt(1-x^2)*sqrt(1-k^2+k^2*x^2)) +
               df(k,y)*(-arccn(x,k)/k + ellipticE(acos(x),k)/(k*(1-k^2))
                        - k*x*sqrt((1-x^2)/(1-k^2+k^2*x^2))/(1-k^2)),

 df(arcdn(~x,~k),~x) => -df(x,y)/(sqrt(1-x^2)*sqrt(x^2-1+k^2)) +
               df(k,y)*(-arcdn(x,k)/k
                        + ellipticE(asin(sqrt(1-x^2)/k),k)/(k*(1-k^2))
                        - x*sqrt((1-x^2)/(x^2-1+k^2))/(k*(1-k^2))),
 
 df(arccd(~x,~k),~y) => -df(x,y)/(sqrt(1-x^2)*sqrt(1-k^2*x^2)) +
           df(k,y)*(-arccd(x,k)/k
                    + ellipticE(asin(sqrt((1-x^2)/(1-k^2*x^2))),k)/(k*(1-k^2))),

 df(arcsd(~x,~k),~y) => -df(x,y)/(sqrt(1-(1-k^2)*x^2)*sqrt(1+k^2*x^2)) +
           df(k,y)*(-arcsd(x,k)/k
                    + ellipticE(asin(x/sqrt(1+k^2*x^2)),k)/(k*(1-k^2))
                    - k*x/sqrt((1+k^2+x^2)*(1-(1-k^2)*x^2))/(1-k^2)),
 
 df(arcnd(~x,~k),~y) => df(x,y)/(sqrt(1-x^2)*sqrt(1-(1-k^2)*x^2)) +
           df(k,y)*(-arcnd(x,k)/k
                    + ellipticE(asin(sqrt(x^2-1)/(k*x)),k)/(k*(1-k^2)) 
                    - sqrt((x^2-1)/(1+(k^2-1)*x^2))/(k*x(1-k^2))),
 
 df(arcdc(~x,~k),~y) => df(x,y)/(sqrt(x^2-1)*sqrt(x^2-k^2)) +
           df(k,y)*(-arcdc(x,k)/k
                    + ellipticE(asin(sqrt((x^2-1)/(x^2-k^2))),k)/(k*(1-k^2))),

 df(arcnc(~x,~k),~y) => df(x,y)/(sqrt(x^2-1)*sqrt(k^2+(1-k^2)*x^2)) +
           df(k,y)*(-arcnc(x,k)/k + ellipticE(asec(x),k)/(k*(1-k^2)) 
	      - k*sqrt(x^2-1)/(x*sqrt(k^2+(1-k^2)*x^2)*(1-k^2))),
 
 df(arcsc(~x,~k),~y) => df(x,y)/(sqrt(1+x^2)*sqrt(1+(1-k^2)*x^2)) +
           df(k,y)*(-arcsc(x,k)/k + ellipticE(atan(x),k)/(k*(1-k^2))
                    -k*x/sqrt((1+x^2)*(1+x^2-k^2*x^2))/(1-k^2)),
 
 df(arcns(~x,~k),~y) => -df(x,y)/(sqrt(x^2-1)*sqrt(x^2-1+k^2)) +
           df(k,y)*(-arcns(x,k)/k + ellipticE(csc(x),k)/(k*(1-k^2)) 
  	            - k*sqrt(x^2-1)/(x*sqrt(x^2-k^2)*(1-k^2))),
 
 df(arcds(~x,~k),~y) => -df(x,y)/(sqrt(x^2+k^2)*sqrt(x^2-1+k^2)) +
           df(k,y)*(-arcds(x,k)/k
                    + ellipticE(asin(1/sqrt(x^2+k^2)),k)/(k*(1-k^2))
                    - k*x/sqrt((x^2+k^2)*(x^2-1+k^2))/(1-k^2)),
 
 df(arccs(~x,~k),~y) => -df(x,y)/(sqrt(1+x^2)*sqrt(x^2+1-k^2)) +
           df(k,y)*(-arccs(x,k)/k + ellipticE(acot(x),k)/(k*(1-k^2))
                    - k*x/sqrt((x^2+1)*(x^2+1-k^2))/(1-k^2)),
       
% rules for numerical evaluation  --currently only for real arguments and
% results
%%  arcsn(~x,~k) =>  x*sym_int_RF(1, 1-x^2, 1-k^2*x^2)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x<=1 and abs k<=1,
%% 
%%   arcsc(~x,~k) => x*sym_int_RF(1, 1+x^2, 1+(1-k^2)*x^2)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs k<=1,
%% 
%%   arcsd(~x,~k) => x*sym_int_RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k
%%      and (abs k<1 and x^2 <= 1/(1-k^2) or abs k =1),
%%  
%%   arcns(~x,~k) => sign(x)*sym_int_RF(x^2, x^2-1, x^2-k^2)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x>=1 and abs k<=1,
%% 
%%   arccs(~x,~k) =>
%%          (begin scalar y;
%%             y := sym_int_RF(x^2, x^2+1, x^2+1-k^2);
%%             if x>= 0 then  return y
%%             else return 2*elliptick(k)-y;
%%           end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs k<=1,
%% 
%%   arcds(~x,~k) => sign(x)*sym_int_RF(x^2, x^2+k^2, x^2+k^2-1)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k  and abs k<=1 and x^2 >= 1-k^2,
%% 
%%   arccn(~x,~k) =>
%%          (begin scalar w, y;
%% 	    w:= 1-x^2;
%% 	    y := sqrt w * sym_int_RF(x^2,1,1-k^2*w);
%%             return if x>=0 then y else 2*elliptick(k)-y;
%% 	  end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x<=1 and abs k<=1,
%%  
%%   arcnc(~x,~k) =>
%%          (begin scalar w, y;
%% 	    w:= 1-x^2;
%% 	    y := sqrt w * sym_int_RF(x^2,1,1+(1-k^2)*w);
%%             return if x>=0 then y else 2*elliptick(k)-y;
%% 	  end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x >=1 and abs k<=1,
%%  
%%   arcdn(~x,~k) =>
%%          (begin scalar w;
%%             w := (1-x^2)/k^2;
%% 	    return sqrt w * sym_int_RF(x^2,1,1-w);
%% 	 end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs k<=1 and k neq 0
%%      and x <= 1 and x >= sqrt(1-k^2),
%%  
%%   arcnd(~x,~k) =>
%%          (begin scalar w;
%%             w := (x^2-1)/k^2;
%% 	    return sqrt w * sym_int_RF(x^2,1,1+(k^2-1)*w);
%%  	 end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and x >=1 
%%      and (abs k<1 and k neq 0 and x^2 <= 1/(1-k^2) or abs k=1),
%% 
%%  arccd(~x,~k) =>
%%         (begin scalar w, y;
%% 	   w:= (1-x^2)/(1-k^2);
%% 	   y :=  sqrt w * sym_int_RF(x^2,1,1+k^2*w);
%%            return if x>=0 then y else 2*elliptick(k)-y;
%% 	 end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x<=1 and abs k<=1,
%% 
%%  arcdc(~x,~k) =>
%%         (begin scalar w, y;
%% 	   w := (1-x^2)/(1-k^2);
%% 	   y := sqrt w * sym_int_RF(x^2,1,1+w);
%%            return if x>=0 then y else 2*elliptick(k)-y;
%% 	 end)
%%      when lisp !*rounded and impart x = 0 and impart k = 0 
%%      and numberp x and numberp k and abs x >=1 and abs k<=1

 arcsn(~x,~k) =>
       (begin
	   if impart x=0 and impart k =0 then % real args
	      return x*sym_int_RFR(1, 1-x^2, 1-k^2*x^2)
	   else  % complex is on
	      return x*sym_int_RF(1, 1-x^2, 1-k^2*x^2);
	end)  
     when lisp !*rounded and numberp x and numberp k,

 arcsc(~x,~k) =>
        (begin
	   if impart x=0 and impart k =0 then % real args
	      return x*sym_int_RFR(1, 1+x^2, 1+(1-k^2)*x^2)
	   else % complex is on
	      return x*sym_int_RF(1, 1+x^2, 1+(1-k^2)*x^2);
	end)
     when lisp !*rounded  and numberp x and numberp k,
 
 arcsd(~x,~k) =>
        (begin
	   if impart x=0 and impart k =0 then % real args
	      return x*sym_int_RFR(1, 1+k^2*x^2, 1-(1-k^2)*x^2)
	   else  % complex is on
	      return x*sym_int_RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2);
	end)
     when lisp !*rounded and numberp x and numberp k,

 arcns(~x,~k) => (begin scalar y;
                    if impart x=0 and impart k =0 then % real args
                      return sign(x)*sym_int_RFR(x^2, x^2-1, x^2-k^2)
                    else << % complex is on
		       if repart x = 0 then  % x purely imaginary
			  y:= sym_int_RF(1, 1-1/x^2, 1-k^2/x^2)/x
                       else
                       	  y := sym_int_RF(x^2, x^2-1, x^2-k^2);
		       if repart x <0 then
		 	  return -y
	      	       else return y;
		    >>
                  end)
     when lisp !*rounded and numberp x and numberp k,

 arccs(~x,~k) => (begin scalar y;
                   if impart x=0 and impart k =0 then << % real args
                        y := sym_int_RFR(x^2, x^2+1, x^2+1-k^2);
                        if x>= 0 then  return y
                        else return -y;
		   >> else << % complex is on
		      if repart x =0 then  % imaginary argument
			 y:= sym_int_RF(1, 1+k^2/x^2, 1-(1-k^2)/x^2)/x
                      else
		         y := sym_int_RF(x^2, x^2+1, x^2+1-k^2);
		      if repart x <0 then
			 return -y
	      	      else return y;
		    >>
                end)
     when lisp !*rounded and numberp x and numberp k,

 arcds(~x,~k) => (begin scalar y;
                    if impart x=0 and impart k =0 then << % real args
		       y := sym_int_RFR(x^2, x^2+k^2, x^2+k^2-1);
                       if x> 0 then  return y
                       else return -y;
                    >> else << % complex is on
		       if repart x =0 then % imaginary argument
			  y:= sym_int_RF(1, 1+k^2*x^2, 1+(k^2-1)*x^2)/x
                       else
			  y:= sym_int_RF(x^2, x^2+k^2, x^2+k^2-1);
	      	       if repart x <0  then
		 	  return -y
	      	       else return y;
		    >>
                 end)
      when lisp !*rounded and numberp x and numberp k,

 arccn(~x,~k) =>
      (begin scalar w, y;
         w:= 1-x^2;
         if impart x=0 and impart k =0 and impart w=0 then
	     << % real args
  	        y := sqrt(abs w) * sym_int_RFR(x^2,1,1-k^2*w);
		if w<0 then y:=i*y;
                return if x>=0 then y else 2*elliptick(k)-y;
	     >> else <<
		y := sqrt w * sym_int_RF(x^2,1,1-k^2*w);
		if repart x <0 then
		   return 2*elliptick(k)-y
		else return y;
	     >>		
       end)
     when lisp !*rounded and numberp x and numberp k,
 
 arcnc(~x,~k) =>
       (begin scalar w, y;
 	  w:= x^2-1;
	  if impart x=0 and impart k =0 and impart w=0  then
	     << % real args
	     	y := sqrt(abs w) * sym_int_RFR(x^2,1,1+(1-k^2)*w);
		if w<0 then y:=i*y;
   		return if x>=0 then y else 2*elliptick(k)-y;
	     >> else <<
		y := sqrt w * sym_int_RF(x^2,1,1+(1-k^2)*w);
		if repart x <0 then
		   return 2*elliptick(k)-y
		else return y;
	     >>
	end)
     when lisp !*rounded and numberp x and numberp k,
 
  arcdn(~x,~k) =>
         (begin scalar w, y;
            w := (1-x^2)/k^2;
	    if impart x=0 and impart k=0 and impart w=0 then <<
               y := sqrt(abs w) * sym_int_RFR(x^2,1,1-w);
 	       if w<0 then y :=i*y;
	       return y;
	    >> else <<
	       	  y := sqrt w * sym_int_RF(x^2,1,1-w);
	       	  if repart x <0 then
		     return 2*elliptick(k)-y
	       	  else return y;
	    >>	       
	 end)
     when lisp !*rounded and numberp x and numberp k and k neq 0,

 
  arcnd(~x,~k) =>
         (begin scalar w, y;
            w := (x^2-1)/k^2;
    	    if impart x=0 and impart k =0 and impart w=0 then <<
	       y := sqrt(abs w) * sym_int_RFR(x^2,1,1+(k^2-1)*w);
       	       if w<0 then y :=i*y;
	       return y;
	    >> else <<
	       y := sqrt w * sym_int_RF(x^2,1,1+(k^2-1)*w);
	       if repart x <0 then
		  return 2*elliptick(k)-y
	       else return y;
	    >>	       
 	 end)
     when lisp !*rounded and numberp x and numberp k and k neq 0,

 arccd(~x,~k) =>
           (begin scalar w, y;
	      w:= (1-x^2)/(1-k^2);
    	      if impart x=0 and impart k =0 and impart w=0 then <<
 	         y := sqrt(abs w) * sym_int_RFR(x^2,1,1+k^2*w);
		 if w<0 then y :=i*y;
                 return if x>=0 then y else 2*elliptick(k)-y;
	      >> else <<
		 y := sqrt w * sym_int_RF(x^2,1,1+k^2*w);
		 if repart x <0 then
		    return 2*elliptick(k)-y
		 else return y;
	      >>
	    end)
     when lisp !*rounded and numberp x and numberp k and k^2 neq 1,

 arcdc(~x,~k) =>
        (begin scalar w;
	   w := (x^2-1)/(1-k^2);
    	   if impart x=0 and impart k =0 and impart w=0 then <<
	      y := sqrt(abs w) * sym_int_RFR(x^2,1,1+w);
	      if w<0 then y :=i*y;
              return if x>=0 then y else 2*elliptick(k)-y;
	   >> else <<
	      y := sqrt w * sym_int_RF(x^2,1,1+w);
	      if repart x <0 then
		 return 2*elliptick(k)-y
	      else return y;
	   >>
         end)
     when lisp !*rounded and numberp x and numberp k and k^2 neq 1

 }$

let invjacobirules;
   
symbolic;

put('arcsn,'fancy!-functionsymbol,"\mathrm{arcsn}");
put('arccn,'fancy!-functionsymbol,"\mathrm{arccn}");
put('arcdn,'fancy!-functionsymbol,"\mathrm{arcdn}");
put('arcns,'fancy!-functionsymbol,"\mathrm{arcns}");
put('incnc,'fancy!-functionsymbol,"\mathrm{arcnc}");
put('arcnd,'fancy!-functionsymbol,"\mathrm{arcnd}");
put('arcsc,'fancy!-functionsymbol,"\mathrm{arcsc}");
put('arcsd,'fancy!-functionsymbol,"\mathrm{arcsd}");
put('arccd,'fancy!-functionsymbol,"\mathrm{arccd}");
put('arccs,'fancy!-functionsymbol,"\mathrm{arccs}");
put('arcds,'fancy!-functionsymbol,"\mathrm{arcds}");
put('arcdc,'fancy!-functionsymbol,"\mathrm{arcdc}");
   
foreach x in '(arcsn  arccn  arcdn arcns  arcnc  arcnd
               arcsc  arcsd  arccd arccs  arcds  arcdc)
do << put(x, 'fancy!-symbol!-length, 10) >>;

flag('(arcsn arccn arcdn arcns arcnc arcnd 
       arcsc arcsd arccs arccd arcds arcdc
      ), 'specfn);

deflist('((arcsn 2) (arccn 2) (arcdn 2)
          (arcns 2) (arcnc 2) (arcnd 2) (arcsc 2) (arcsd 2)
	  (arccs 2) (arccd 2) (arcds 2) (arcdc 2)
	 ), 'number!-of!-args);

endmodule;
end;
