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
       
% rules for numerical evaluation
% currently only guaranteed for real arguments and results, but
% may work for some complex arguments and results. However, in other
% cases the function call to RF may generate an error message.
 
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

 arcsn(~x,~k) => num_asn(x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcsc(~x,~k) => num_asc(x,k)
    when lisp !*rounded  and numberp x and numberp k,

 arcsd(~x,~k) => num_asd(x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcns(~x,~k) => num_asn(1/x,k)
    when lisp !*rounded and numberp x and numberp k,

 arccs(~x,~k) => num_asc(1/x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcds(~x,~k) => num_asd(1/x,k)
    when lisp !*rounded and numberp x and numberp k,

 arccn(~x,~k) => num_acn(x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcnc(~x,~k) => num_acn(1/x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcdn(~x,~k) => num_adn(x,k)
    when lisp !*rounded and numberp x and numberp k and k neq 0,

 arcnd(~x,~k) => num_adn(1/x,k)
    when lisp !*rounded and numberp x and numberp k and k neq 0,

 arccd(~x,~k) => num_acd(x,k)
    when lisp !*rounded and numberp x and numberp k,

 arcdc(~x,~k) => num_acd(1/x,k)
    when lisp !*rounded and numberp x and numberp k

 
%%  arcsn(~x,~k) =>
%%        (begin
%% 	   if impart x=0 and impart k =0 then % real args
%% 	      return x*sym_int_RFR(1, 1-x^2, 1-k^2*x^2)
%% 	   else  % complex is on
%% 	      return x*sym_int_RF(1, 1-x^2, 1-k^2*x^2);
%% 	end)  
%%      when lisp !*rounded and numberp x and numberp k,
%% 
%%  arcsc(~x,~k) =>
%%         (begin
%% 	   if impart x=0 and impart k =0 then % real args
%% 	      return x*sym_int_RFR(1, 1+x^2, 1+(1-k^2)*x^2)
%% 	   else % complex is on
%% 	      return x*sym_int_RF(1, 1+x^2, 1+(1-k^2)*x^2);
%% 	end)
%%      when lisp !*rounded  and numberp x and numberp k,
%%  
%%  arcsd(~x,~k) =>
%%         (begin
%% 	   if impart x=0 and impart k =0 then % real args
%% 	      return x*sym_int_RFR(1, 1+k^2*x^2, 1-(1-k^2)*x^2)
%% 	   else  % complex is on
%% 	      return x*sym_int_RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2);
%% 	end)
%%      when lisp !*rounded and numberp x and numberp k,
%% 
%%  arcns(~x,~k) => (begin scalar y;
%%                     if impart x=0 and impart k =0 then % real args
%%                       return sign(x)*sym_int_RFR(x^2, x^2-1, x^2-k^2)
%%                     else << % complex is on
%% 		       if repart x = 0 then  % x purely imaginary
%% 			  y:= sym_int_RF(1, 1-1/x^2, 1-k^2/x^2)/x
%%                        else
%%                        	  y := sym_int_RF(x^2, x^2-1, x^2-k^2);
%% 		       if repart x <0 then
%% 		 	  return -y
%% 	      	       else return y;
%% 		    >>
%%                   end)
%%      when lisp !*rounded and numberp x and numberp k,
%% 
%%  arccs(~x,~k) => (begin scalar y;
%%                    if impart x=0 and impart k =0 then << % real args
%%                         y := sym_int_RFR(x^2, x^2+1, x^2+1-k^2);
%%                         if x>= 0 then  return y
%%                         else return -y;
%% 		   >> else << % complex is on
%% 		      if repart x =0 then  % imaginary argument
%% 			 y:= sym_int_RF(1, 1+k^2/x^2, 1-(1-k^2)/x^2)/x
%%                       else
%% 		         y := sym_int_RF(x^2, x^2+1, x^2+1-k^2);
%% 		      if repart x <0 then
%% 			 return -y
%% 	      	      else return y;
%% 		    >>
%%                 end)
%%      when lisp !*rounded and numberp x and numberp k,
%% 
%%  arcds(~x,~k) => (begin scalar y;
%%                     if impart x=0 and impart k =0 then << % real args
%% 		       y := sym_int_RFR(x^2, x^2+k^2, x^2+k^2-1);
%%                        if x> 0 then  return y
%%                        else return -y;
%%                     >> else << % complex is on
%% 		       if repart x =0 then % imaginary argument
%% 			  y:= sym_int_RF(1, 1+k^2*x^2, 1+(k^2-1)*x^2)/x
%%                        else
%% 			  y:= sym_int_RF(x^2, x^2+k^2, x^2+k^2-1);
%% 	      	       if repart x <0  then
%% 		 	  return -y
%% 	      	       else return y;
%% 		    >>
%%                  end)
%%       when lisp !*rounded and numberp x and numberp k,
%% 
%%  arccn(~x,~k) =>
%%       (begin scalar w, y;
%%          w:= 1-x^2;
%%          if impart x=0 and impart k =0 and impart w=0 then
%% 	     << % real args
%%   	        y := sqrt(abs w) * sym_int_RFR(x^2,1,1-k^2*w);
%% 		if w<0 then y:=i*y;
%%                 return if x>=0 then y else 2*elliptick(k)-y;
%% 	     >> else <<
%% 		y := sqrt w * sym_int_RF(x^2,1,1-k^2*w);
%% 		if repart x <0 then
%% 		   return 2*elliptick(k)-y
%% 		else return y;
%% 	     >>		
%%        end)
%%      when lisp !*rounded and numberp x and numberp k,
%%  
%%  arcnc(~x,~k) =>
%%        (begin scalar w, y;
%%  	  w:= x^2-1;
%% 	  if impart x=0 and impart k =0 and impart w=0  then
%% 	     << % real args
%% 	     	y := sqrt(abs w) * sym_int_RFR(x^2,1,1+(1-k^2)*w);
%% 		if w<0 then y:=i*y;
%%    		return if x>=0 then y else 2*elliptick(k)-y;
%% 	     >> else <<
%% 		y := sqrt w * sym_int_RF(x^2,1,1+(1-k^2)*w);
%% 		if repart x <0 then
%% 		   return 2*elliptick(k)-y
%% 		else return y;
%% 	     >>
%% 	end)
%%      when lisp !*rounded and numberp x and numberp k,
%%  
%%   arcdn(~x,~k) =>
%%          (begin scalar w, y;
%%             w := (1-x^2)/k^2;
%% 	    if impart x=0 and impart k=0 and impart w=0 then <<
%%                y := sqrt(abs w) * sym_int_RFR(x^2,1,1-w);
%%  	       if w<0 then y :=i*y;
%% 	       return y;
%% 	    >> else <<
%% 	       	  y := sqrt w * sym_int_RF(x^2,1,1-w);
%% 	       	  if repart x <0 then
%% 		     return 2*elliptick(k)-y
%% 	       	  else return y;
%% 	    >>	       
%% 	 end)
%%      when lisp !*rounded and numberp x and numberp k and k neq 0,
%% 
%%  
%%   arcnd(~x,~k) =>
%%          (begin scalar w, y;
%%             w := (x^2-1)/k^2;
%%     	    if impart x=0 and impart k =0 and impart w=0 then <<
%% 	       y := sqrt(abs w) * sym_int_RFR(x^2,1,1+(k^2-1)*w);
%%        	       if w<0 then y :=i*y;
%% 	       return y;
%% 	    >> else <<
%% 	       y := sqrt w * sym_int_RF(x^2,1,1+(k^2-1)*w);
%% 	       if repart x <0 then
%% 		  return 2*elliptick(k)-y
%% 	       else return y;
%% 	    >>	       
%%  	 end)
%%      when lisp !*rounded and numberp x and numberp k and k neq 0,
%% 
%%  arccd(~x,~k) =>
%%            (begin scalar w, y;
%% 	      w:= (1-x^2)/(1-k^2);
%%     	      if impart x=0 and impart k =0 and impart w=0 then <<
%%  	         y := sqrt(abs w) * sym_int_RFR(x^2,1,1+k^2*w);
%% 		 if w<0 then y :=i*y;
%%                  return if x>=0 then y else 2*elliptick(k)-y;
%% 	      >> else <<
%% 		 y := sqrt w * sym_int_RF(x^2,1,1+k^2*w);
%% 		 if repart x <0 then
%% 		    return 2*elliptick(k)-y
%% 		 else return y;
%% 	      >>
%% 	    end)
%%      when lisp !*rounded and numberp x and numberp k and k^2 neq 1,
%% 
%%  arcdc(~x,~k) =>
%%         (begin scalar w;
%% 	   w := (x^2-1)/(1-k^2);
%%     	   if impart x=0 and impart k =0 and impart w=0 then <<
%% 	      y := sqrt(abs w) * sym_int_RFR(x^2,1,1+w);
%% 	      if w<0 then y :=i*y;
%%               return if x>=0 then y else 2*elliptick(k)-y;
%% 	   >> else <<
%% 	      y := sqrt w * sym_int_RF(x^2,1,1+w);
%% 	      if repart x <0 then
%% 		 return 2*elliptick(k)-y
%% 	      else return y;
%% 	   >>
%%          end)
%%      when lisp !*rounded and numberp x and numberp k and k^2 neq 1

 }$

let invjacobirules;

algebraic procedure num_asn(x,k);
   begin scalar xo := x;
      if x=0 then return 0;
      if impart x=0 and impart k=0 then << % real args
	 k := abs k; x:= abs x;
	 if k=0 then return asin(xo)
	 else if k=1 then return atanh xo;
	 if x>1 and k*x<=1 then
	    return sign(xo)*(RF(0,1-k^2,1)-i*num_adn(1/x,sqrt(1-k^2)))
	 else if x<=1 and x>1/k then
 	    return sign(xo)*(RF(0,1-1/k^2,1)-i*num_adn(1/(k*x),sqrt(1-1/k^2)))/k
 	 else if x>1 and k>1 then
	    return sign(xo)*(RF(0,1-1/k^2,1)-i*RF(0,1/k^2,1)-num_acd(1/x,1/k))/k;
	 return x*RF(1, 1-x^2, 1-k^2*x^2);
      >>;
      % complex is on
      if impart(k*x)=0 and abs(1/k) < abs(x) then
	 return sign(repart x)*(RF(0,1-1/k^2,1)
	            -i*num_adn(1/(k*x),sqrt(1-1/k^2)))/k
      else if impart x =0 and abs x >1 then
	 return sign(x)*(RF(0,1-k^2,1)-i*num_adn(1/abs x, sqrt(1-k^2)))
      else
	 return x*RF(1, 1-x^2, 1-k^2*x^2);
   end;

algebraic procedure num_asc(x,k);
 x*RF(1, 1+x^2, 1+(1-k^2)*x^2);


algebraic procedure num_asd(x,k);
   x*RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2);



algebraic procedure num_acn(x,k);
   begin scalar w, y;
      w:= 1-x^2;
      y := sqrt w * RF(x^2,1,1-k^2*w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

algebraic procedure num_adn(x,k);
   begin scalar w, y;
      w := (1-x^2)/k^2;
      y := sqrt w * RF(x^2,1,1-w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
   end;

algebraic procedure num_acd(x,k);
   begin scalar w, y;
      w:= (1-x^2)/(1-k^2);
      y := sqrt w * RF(x^2,1,1+k^2*w);
      if repart x <0 then
	 return 2*elliptick(k)-y
      else return y;
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
