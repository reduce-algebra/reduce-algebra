module efjacinv;  % Procedures and Rules for Inverse Jacobi Elliptic functions.

% Author: Alan Barnes, October 2021
% Modified November 2022 to handle numerical evaluation with complex
% arguments and to use symmetric integrals.

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
 % The condition on the following rule and similar rules below is
 % to aid testing of numerical evaluation routines.
 arcsn(-~x,~k) => -arcsn(x,k) when not numberp x,
 arcsn(~x,-~k) => arcsn(x,k),
 arcsn(1, ~k) => elliptick(k),

 arcns(~x,0) => acsc(x),
 arcns(~x,1) => acoth(x),
 arcns(0,~k) => i*elliptick!'(k),
 arcns(-~x,~k) => -arcns(x,k) when not numberp x,
 arcns(~x,-~k) => arcns(x,k),
 arcns(1, ~k) => elliptick(k),

 arccn(~x,0) => acos(x),
 arccn(~x,1) => asech(x),
 arccn(0,~k) => elliptick(k),
 arccn(1,~k) => 0,
 arccn(-~x,~k) => 2*elliptick(k)-arccn(x,k) when not numberp x,
 arccn(~x,-~k) => arccn(x,k),

 arcnc(~x,0) => asec(x),
 arcnc(~x,1) => acosh(x),
 arcnc(0,~k) => i*elliptick!'(k),
 arcnc(-~x,~k) => 2*elliptick(k)-arcnc(x,k) when not numberp x,
 arcnc(~x,-~k) => arcnc(x,k),

 arcdn(~x,1) => asech(x),
 arcdn(0,~k) => elliptick(k)+i*elliptick!'(k),
 arcdn(-~x,~k) => 2*(elliptick(k)+i*elliptick!'(k))-arcdn(x,k)
                      when not numberp x,
 arcdn(sqrt(1-~k^2),~k) => elliptick(k),
 arcdn(~x,-~k) => arcdn(x,k),
 
 arcnd(~x,1) => acosh(x),
 arcnd(0,~k) => i*elliptick!'(k),
 arcnd(-~x,~k) => 2*(elliptick(k)+i*elliptick!'(k))-arcnd(x,k)
                        when not numberp x,
 arcnd(1/sqrt(1-~k^2),~k) => elliptick(k),
 arcnd(~x,-~k) => arcdn(x,k),

 arcsc(~x,0) => atan(x),
 arcsc(~x,1) => asinh(x),
 arcsc(0,~k)  => 0,
 arcsc(-~x,~k) => -arcsc(x,k) when not numberp x,
 arcsc(~x,-~k) => arcsc(x,k),

 arccs(~x,0) =>  acot(x),
 arccs(~x,1) => acsch(x),
 arccs(0, ~k) => elliptick(k),
 % cf acot x whose principal value is not odd in Reduce.
 arccs(-~x,~k) => 2*elliptick(k)-arccs(x,k) when not numberp x,
 arccs(~x,-~k) => arccs(x,k),

 arcsd(~x,0) => asin(x),
 arcsd(~x,1) => asinh(x),
 arcsd(0,~k)  => 0,
 arcsd(-~x,~k) => -arcsd(x,k) when not numberp x,
 arcsd(~x,-~k) => arcsd(x,k),

 arcds(~x,0) => acsc(x),
 arcds(~x,1) => acsch(x),
 arcds(0,~k) => elliptick(k)+i*elliptick!'(k),
 arcds(-~x,~k) => -arcds(x,k) when not numberp x,
 arcds(~x,-~k) => arccs(x,k),

 arccd(~x,0) => acos(x),
 arccd(0,~k)  => elliptick(k),
 arccd(-~x,~k) => 2*elliptick(k)-arccd(x,k) when not numberp x,
 arccd(~x,-~k) => arccd(x,k),

 arcdc(~x,0) => asec(x),
 arcdc(0,~k) => elliptick(k)+i*elliptick!'(k),
 arcdc(-~x,~k) => 2*elliptick(k)-arcdc(x,k) when not numberp x,
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
       
% rules for numerical evaluation

 arcsn(~x,~k) => num_asn(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arcsc(~x,~k) => num_asc(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arcsd(~x,~k) => num_asd(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arcns(~x,~k) => num_ans(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arccs(~x,~k) => num_acs(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arcds(~x,~k) => num_ads(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arccn(~x,~k) => num_acn(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k, 

 arcnc(~x,~k) => num_anc(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k, 

 arcdn(~x,~k) => num_adn(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arcnd(~x,~k) => num_and(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,

 arccd(~x,~k) => num_acd(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k,
 
 arcdc(~x,~k) => num_adc(x,k)
    when lisp !*rounded and lisp !*complex and numberp x and numberp k
 }$

let invjacobirules;

% The following should not normally be called directly. They are
% normally called from the num_asn, num_acn procedures etc. which
% ensure all arguments to RF are non-negative and at most one is zero.

algebraic procedure n_asn(x,k);
   x*RF(1, 1-x^2, 1-k^2*x^2);

algebraic procedure n_ans(x,k);
   RF(1, 1-1/x^2, 1-k^2/x^2)/x;

algebraic procedure n_asc(x,k);
 x*RF(1, 1+x^2, 1+(1-k^2)*x^2);

algebraic procedure n_acs(x,k);
 RF(1, 1+1/x^2, 1+(1-k^2)/x^2)/x;

algebraic procedure n_asd(x,k);
   x*RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2);

algebraic procedure n_ads(x,k);
   RF(1, 1+k^2/x^2, 1-(1-k^2)/x^2)/x;

algebraic procedure n_acn(x,k);
   begin scalar w, y;
      w:= 1-x^2;
      y := sqrt w * RF(x^2,1,1-k^2*w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

algebraic procedure n_anc(x,k);
   begin scalar w, y;
      w:= x^2-1;
      y := sqrt w * RF(x^2,1,1+(1-k^2)*w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

algebraic procedure n_adn(x,k);
   begin scalar w, y;
      w := (1-x^2)/k^2;
      y := sqrt w * RF(x^2,1,1-w);
      if repart x <0 then
	 return 2*i*elliptick!'(k)-y
      else return y;
   end;

algebraic procedure n_and(x,k);
   begin scalar w, y;
      w := (x^2-1)/k^2;
      y := sqrt w * RF(x^2,1,1-(1-k^2)*w);
      if repart x <0 then
	 return 2*i*elliptick!'(k)-y
      else return y;
   end;

algebraic procedure n_acd(x,k);
   begin scalar w, y;
      w:= (1-x^2)/(1-k^2);
      y := sqrt w * RF(x^2,1,1+k^2*w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

algebraic procedure n_adc(x,k);
   begin scalar w, y;
      w:= (x^2-1)/(1-k^2);
      y := sqrt w * RF(x^2,1,1+w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

% The following procedures num1_asn etc. may not always return the principal
% value of the inverse Jacobi function. The values returned are processed
% by the procedure principal_value via calls to see if they lie within
% the four principal cells of the lattice and if not are adjusted accordingly.

algebraic procedure num_asn(x,k);
    if x=0 then 0
    else if k=0 then asin(x)
    else if k=1 or k=-1 then atanh x
    else num_elliptic(num2_asn, x, k);

algebraic procedure num2_asn(x,k);
   principal_value(num1_asn(x,k), num_ellk(k),
                   i*num_ellk(sqrt(1-k^2)), 'odd);

algebraic procedure num1_asn(x,k);
   % integral from t=0 to x of 1/sqrt((1-t^2)*(1-(k*t)^2))
   % Branch points if one or both factors in the sqrt vanish
   % in the range 0 to x. Need to split the range at these points
   begin scalar kx, s;
      if repart k < 0 then k := -k; % so sqrt(k^2) = k
      kx := k*x; 

      if impart x=0 and impart k=0 then << % real args
	 % up to 2 branch points in defining integral
	 if abs x > 1 then
	   if abs kx <= 1 then % a single branch point when abs x=1 
	      return sign(x)*(RF(0,1-k^2,1)
		              -i*n_and(abs x,sqrt(1-k^2)))
	   else % a second branch point when abs x =1/k
	   if k>1 then 
              return sign(x)*(RF(0,1,1-1/k^2) -n_adc(abs x,1/k)
		 -i*n_adn(1/k,sqrt(1-1/k^2)))/k
	   else
	      return  sign(x)*(RF(0,1-k^2,1)-i*n_and(1/k,sqrt(1-k^2))
		               -n_adc(abs kx,k));
	 
    	 % here abs x <=1
	 if abs kx > 1 then  % a single branch point when abs x=1/k 
 	    return sign(x)*(RF(0,1-1/k^2,1)
	                    -i*n_and(abs kx,sqrt(1-1/k^2)))/k
         else  % no branch points
	    return x*RF(1, 1-x^2, 1-kx^2);
      >>;

      if impart kx = 0 and abs kx > 1 then <<
	 % x complex; one branch point
         s := sign repart x;
	 if s = 0 then s := -sign impart x;
	 return s*(RF(0,1-1/k^2,1)-i*n_and(abs kx,sqrt(1-1/k^2)))/k;
      >> 
      else if impart x = 0 and abs x > 1 then
	 % k complex; 1 branch point 
	 return sign(x)*(RF(0,1-k^2,1)-i*n_and(abs x, sqrt(1-k^2)))
      else  % no branch points
	 return x*RF(1, 1-x^2, 1-kx^2);
   end;

algebraic procedure num_ans(x,k);
% uses the identity arcns(x,k)=arcsn(1/x,k)
   if x = 0 then
      rederr("arcns not defined at the origin")
   else if k = 0 then acsc(x)
   else if k=1 or k=-1 then acoth x
   else num_elliptic(num1_ans, x, k);

algebraic procedure num1_ans(x,k);
   principal_value(num1_asn(1/x,k), num_ellk(k),
                   i*num_ellk(sqrt(1-k^2)), 'odd);

algebraic procedure num_asc(x,k);
   if x=0 then 0
   else if k=0 then atan x
   else if k=1 or k=-1 then asinh x
   else num_elliptic(num2_asc, x, k);

algebraic procedure num2_asc(x,k);
   principal_value(num1_asc(x,k), i*num_ellk(sqrt(1-k^2)),
                   num_ellk(k), 'odd);

algebraic procedure num1_asc(x,k);
% = integral from t=0 to x of 1/sqrt((1+t^2)*(1+(k'*t)^2))
begin scalar kpx, kp, ax, s;

      if repart k < 0 then k := -k;
      kp := sqrt(1-k^2);   % k'

      if repart x=0 and impart kp=0 then << 
         % NB if k' real then either k real <=1 and 0<=k'<=1 or
         %    k imaginary and k'>1
         ax := abs x;
	 s := sign impart x;
         if ax*kp <=1  then % k' real <1 and k real <1
	    if ax >1 then % a single branch point at x = +/-i
               return s*(i*num_ellk(kp) + n_and(ax, k))
 	    else  %  no branch points
	       return x*RF(1, 1-ax^2, 1-kp^2ax^2);
         % here ax*kp >1
	    kpx :=  kp*ax;
            if ax > 1 then  %  2 branch points, one at x=+/-i
	                    % other when kp*abs x = 1
	       if kp < 1 then % k real < 1
	          return s*(i*(RF(0,1,1-kp^2)-n_adc(kpx,kp))
	                 + n_and(1/kp, k))
               else % k imaginary 
 		  return s*(i*(RF(0,1,1-1/kp^2)-n_adc(ax, 1/kp))
	                    +n_adn(1/kp, sqrt(1-1/kp^2)))/kp
	    else % ax <= 1  and kp*ax >1 so one branch point when k'*abs x = 1
	       return s*((i*RF(0, 1, 1-1/kp^2)-n_and(kpx, sqrt(1-1/kp^2)))/kp);
      >>;
      
      if repart x = 0 then << % here k' not real
	 ax := abs x;
	 s := sign impart x; 
	 if ax >1 then % a single branch point at x = +/-i
            return s*(i*num_ellk(kp) + n_and(ax, k));
      >>;

      kpx := kp*x;
      if repart x neq 0 then
	 if repart kpx = 0 and abs kpx >1 then
	     % one branch point when impart kpx = +/-1
             return (i*num_ellk(1/kp) - n_and(impart kpx, sqrt(1-1/kp^2)))/kp;
      
      % no branch points
      return x*RF(1, 1+x^2, 1+kpx^2);
end;

algebraic procedure num_acs(x,k);
% uses the identity arccs(x,k)=arcsc(1/x,k)
   if k=1 or k=-1 then
      if x=0 then
         rederr("arccs not defined at the origin when the modulus is a unit")
      else  acsch x
   else if k = 0 then acot(x)
   else num_elliptic(num1_acs, x, k);

algebraic procedure num1_acs(x,k);  
begin scalar qp1, qp2;
   qp2 := num_ellk(k);
   if x = 0 then return qp2;
   qp1 := num_ellk(sqrt(1-k^2));
   return principal_value(num1_asc(1/x,k), i*qp1, qp2, 'arccs);
end;

algebraic procedure num_asd(x,k);
   if x=0 then 0
   else if k=0 then asin x
   else if k=1 or k=-1 then asinh x
   else num_elliptic(num2_asd, x, k);

algebraic procedure num2_asd(x,k);
   principal_value(num1_asd(x,k), qp1, qp1+i*qp2, 'odd)
      where qp1 => num_ellk(k), qp2 => num_ellk(sqrt(1-k^2));

algebraic procedure num1_asd(x,k);
   % = integral from t=0 to x of 1/sqrt((1+(k*t)^2)*(1-(k'*t)^2))
begin scalar kp, ax, ak, kx, kpx, s;
      if repart k < 0 then k := -k;
      kp := sqrt(1-k^2);  % k'

      % upto 2 branch points in defining integrand
      if impart x = 0 and repart k = 0 then <<
	 ak := abs k;
         ax := abs x;
	 if ax <= 1/kp then % no branch points
	    return x*RF(1, 1+k^2*x^2, 1-kp^2*x^2)  
	 else if ax <= 1/ak then  % a single branch point at ax=1/kp
	    return sign(x)* (num_ellk(ak/kp)-i*n_and(kp*ax, 1/kp))/kp
	 else % second branch point at ax=1/ak
	    return sign(x)*(num_ellk(ak/kp) + n_adc(ax*ak,ak/kp)
	             - i*num_ellk(1/kp))/kp  % =-i*num_and(kp/k, 1/kp)/kp
      >>;

      % again upto 2 branch points in defining integrand
      if repart x = 0 and impart k = 0 and k>1 then <<
	 ax := abs x;
	 kp := abs kp;
	 s := sign impart x;
         if ax <= 1/k then % no branch points
	    return x*RF(1, 1+k^2*x^2, 1+kp^2*x^2)
	 else if ax <= 1/kp then  % a single branch point at ax=1/k
	    return s*(i*num_ellk(kp/k) + n_and(k*ax, 1/k))/k
	 else % a second branch point at ax = abs(1/kp) 
	     return s*(i*(num_ellk(kp/k) - n_adc(kp*ax,kp/k))
 	                + num_ellk(1/k))/k; 
      >>;

      % now at most one branch point is possible
      kx := k*x;
      if repart kx = 0 and abs kx > 1 then << % one branch point
	 s := sign repart x;
	 if s neq sign (impart x) then s :=-s;
 	 return s*(i*num_ellk(i*kp/k)/k + n_anc(abs kx, k));
      >>;
      kpx := kp*x;
      if impart kpx = 0 and abs kpx > 1 then << % one branch point
	 s := sign repart x;
	 return s*(num_ellk(i*k/kp)/kp -i*n_anc(abs kpx, kp));
      >>;
      % default case no branch points
      return x*RF(1, 1+kx^2, 1-kpx^2);
end;

algebraic procedure num_ads(x,k);
% uses the identity arcds(x,k)=arcds(1/x,k)
  if x = 0 and (k=0 or k=1 or k=-1) then
     rederr("arcds not defined at origin when the modulus is zero or a unit") 
  else if k = 0 then acsc(x)
  else if k = 1 or k = -1 then acsch x
  else num_elliptic(num1_ads, x, k);

algebraic procedure num1_ads(x,k);
   begin scalar qp1, qp2;
     qp1 := num_ellk(k);
     qp2 := qp1+i*num_ellk(sqrt(1-k^2));
     if x = 0 then return qp2
     else return principal_value(num1_asd(1/x, k), qp1, qp2, 'odd);
  end;

algebraic procedure num_acn(x,k);
   % integral from t=x to 1 of 1/sqrt((1-t^2)*(k'^2+(k*t)^2))
   % However, simpler to use the identity arccn(x,k) = K(k)-arcsd(x/k', k)
   if x=0 and (k=1 or k=-1) then
      rederr("arccn not defined at the origin with unit modulus")
   else if k=0 then acos(x)
   else if k = 1 or k =-1 then asech x
   else num_elliptic(num1_acn, x, k);

algebraic procedure num1_acn(x,k);
   begin scalar qp1, qp2, kp;
     qp1 := num_ellk(k);
     if x=0 then return qp1;
     kp :=sqrt(1-k^2);
     qp2 := qp1+i*num_ellk(kp);      
     return principal_value(qp1-num1_asd(x/kp,k), qp1, qp2, 'even);
   end;

algebraic procedure num_anc(x,k);
% uses the identity arcnc(x,k)=arccn(1/x,k)
   if x = 0 and (k = 0 or k=1 or k=-1)  then
      rederr("arcnc not defined at the origin with zero or unit modulus")
   else if k = 0 then asec(x)
   else if k=1 or k=-1 then acosh x
   else num_elliptic(num1_anc, x, k);

algebraic procedure num1_anc(x,k);
   begin scalar qp1, qp2, kp;
      kp := sqrt(1-k^2);
      qp2 := i*num_ellk(kp);
      if x=0 then return qp2;
      qp1 := num_ellk(k);
      return principal_value(qp1-num1_asd(1/(x*kp),k),
	                     qp1, qp1+qp2, 'even);
   end;

algebraic procedure num_adn(x,k);
% uses the identity arcdn(x,k) = iK'(k)-arccs(ix,k)   
   if k = 0  then
      rederr("arcdn not defined for zero modulus")
   else if x=0 and (k =1 or k=-1) then
      rederr("arcdn not defined at the origin for unit modulus") 
   else if k=1 or k=-1 then asech x
   else num_elliptic(num1_adn, x, k);

algebraic procedure num1_adn(x,k);
   begin scalar qp1, qp2, kp;
      kp := sqrt(1-k^2);
      qp1 := i*num_ellk(kp);
      qp2 := num_ellk(k);
      if x=0 then return qp1+qp2
      else return principal_value(qp1+qp2 - num1_asc(i*x/kp,k),
	                          qp1, qp2, 'arcdn);
   end;

algebraic procedure num_and(x,k);
   % uses the identity arcnd(x,k)=i*K' - arcsc(x/i,k)
   if k = 0 then
      rederr("arcnd not defined for zero modulus")
   else if x neq 0 and (k=1 or k=-1) then acosh x
   else num_elliptic(num1_and, x, k);

algebraic procedure num1_and(x,k);
   begin scalar Kp;
      Kp := i*num_ellk(sqrt(1-k^2));
      if x=0 then  return Kp 
      else return principal_value(Kp + num1_asc(x/i,k), Kp,
	                          num_ellk(k), 'arcdn);
   end;

algebraic procedure num_acd(x,k);
% uses the identity arccd(x,k) = arcsn(x,k) - K(k)
   if k=1 or k=-1 then
      rederr("arccd is not defined for unit modulus")
   else if k=0 then acos x
   else num_elliptic(num1_acd, x, k);

algebraic procedure num1_acd(x,k);
   begin scalar ek;
      ek :=num_ellk(k);
      if x=0 then return ek
      else return principal_value(ek-num1_asn(x,k), ek,
                                  i*num_ellk(sqrt(1-k^2)), 'even);
   end;

algebraic procedure num_adc(x,k);
   % uses the identity arcdc(x,k)=arccd(1/x,k)
   if k=1 or k=-1 then
      rederr("arcdc is not defined for unit modulus")
   else if x = 0 and k=0 then
      rederr("arcdc not defined at the origin for zero modulus")
   else if k = 0 then asec(x)
   else num_elliptic(num1_adc, x, k);

algebraic procedure num1_adc(x,k);
   begin scalar qp1, qp2;
      qp1 := num_ellk(k);
      qp2 := i*num_ellk(sqrt(1-k^2));
      if x = 0 then return qp1+qp2
      else return principal_value(num1_asn(1/x,k)-qp1, qp1, qp2, 'even);
   end;

% returns list {a,b} where z = a*z1 + b*z2
algebraic procedure lattice_coords(z,z1,z2);
   ({(impart(z2)*repart(z) - repart(z2)*impart(z))/d,
     (repart(z1)*impart(z) - impart(z1)*repart(z))/d})
        where d => repart(z1)*impart(z2)-impart(z1)*repart(z2);

algebraic procedure principal_value(z,z1,z2,parity);
   % z1 and z2 are the so called 'quarter' periods;
   % K and iK' respectively for arcsn, arcns, arccd and arcdc
   % K and K+iK' respectively for arccn, arcnc, arcsd and arcds
   % iK' and K respectively for arcdn, arcnd, arcsc and arccs
   % the actual primitive periods are 4*z1 and 2*z2.
begin scalar a, b;
      z := lattice_coords(z,z1,z2);
      a := first z;
      b := second z;

      % First shift lattice coordinates so 0<=a<4 and 0<=b<2.
      % In practice all of these while loops are likely to terminate
      % after a handful of iterations at most.
      while a>=4 do 
         a := a-4;
      while a<0 do
	 a := a+4;

      while b>2 do
       	 b := b-2;
      while b<0 do
       	 b := b+2;

      if parity = 'even then <<
	 if a > 2 then <<
	    a := 4-a;
	    b := 2-b;
       	 >>;
	 % now 0 <= a <= 2 and  0 <= b < 2
      	 if b > 1 then
	    b := 2-b;
         return a*z1+b*z2;
      >>;

      if parity = 'odd or parity = 'arccs then <<
	 if a > 1 and a < 3 then <<
	    a := 2-a;
	    b := -b;
	 >>
	 else if a > 1 and a < 4 then 
	    a := a - 4;
         % now -1 <= a <= 1 and  -2 < b < 2
	 if b > 1 then
	    b := b-2
	 else if b <= -1 then
            b := 2+b;
         % now -1 <= a <= 1 and  -1 <= b <= 1
      >>;

      % cf the principal values of acot are not treated as odd in Reduce 
      if parity = 'arccs and b < 0 then <<
	 b := 2+b;
      >>;
      return a*z1+b*z2;
end;

algebraic procedure principal_value(z,z1,z2,parity);
   % z1 and z2 are the so called 'quarter' periods;
   % K and iK' respectively for arcsn, arcns, arccd and arcdc
   % K and K+iK' respectively for arccn, arcnc, arcsd and arcds
   % iK' and K respectively for arcdn, arcnd, arcsc and arccs
   % the actual primitive periods are 4*z1 and 2*z2.
begin scalar a, b;
      z := lattice_coords(z,z1,z2);
      a := first z;
      b := second z;

      % First shift lattice coordinates so 0<=a<4 and 0<=b<2.
      % In practice all of these while loops are likely to terminate
      % after a handful of iterations at most.
      while a>=4 do 
         a := a-4;
      while a<0 do
	 a := a+4;

      while b>2 do
       	 b := b-2;
      while b<0 do
       	 b := b+2;

      if parity = 'even or parity = 'arcdn then <<
	 if a > 2 then <<
	    a := 4-a;
	    b := 2-b;
       	 >>;
	 % now 0 <= a <= 2 and 0 <= b < 2 
      	 if parity neq 'arcdn and b > 1 then
	    % ensure  -1 < b <= 1
	    b := b-2;
         return a*z1+b*z2;
      >>;

      if parity = 'odd or parity = 'arccs then <<
	 if a > 1 and a < 3 then <<
	    a := 2-a;
	    b := -b;
	 >>
	 else if a > 1 and a < 4 then 
	    a := a - 4;
         % now -1 <= a <= 1 and  -2 < b < 2
	 if b > 1 then
	    b := b-2
	 else if b <= -1 then
            b := 2+b;
         % now -1 <= a <= 1 and  -1 <= b <= 1
      >>;

      % cf the principal values of acot are not treated as odd in Reduce 
      if parity = 'arccs and b < 0 then <<
	 b := 2+b;
      >>;
      return a*z1+b*z2;
end;
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
