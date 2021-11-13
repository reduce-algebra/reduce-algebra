module sfellipinv;  % Procedures and Rules for Inverse Elliptic functions.

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


algebraic;

% see DLMF 19.36(ii) and 19.25(v) for more details on the
% numerical computation of the symmetric elliptic integral RF and the
% inverse Jacobi functions.

algebraic procedure sym_int_RF(x,y,z);
   begin scalar t0,tn,a0,an,c0,cn,tol,theta,n;
      tol := 10.0^-(symbolic !:prec!:);
      % sort arguments into ascending order
      if x>y then <<theta := y; y:=x; x:=theta>>;      
      if y>z then <<theta := z; z:=y; y:=theta>>;      
      if x>y then <<theta := y; y:=x; x:=theta>>;

      cn := 1;
      t0 := sqrt x;
      a0 := sqrt(z-x);
      c0 := sqrt(y-x);
      n:=0;
      while (abs cn > tol) do <<
	 tn := (t0 + sqrt(t0^2+*c0^2))/2;
      	 an := (a0+sqrt(a0^2-c0^2))/2;
         cn :=c0^2/(4*an);
	 c0:=cn; a0:=an; t0:=tn; n:=n+1;
      >>;
      % write "tn = ",tn,"  an = ",an,"   cn = ",cn," count = ",n;
      % Now return Carlson's (hyperbolic) function RC(tn^2+an^2, tn^2) 
      % which equals RF(tn^2, tn^2, tn^2+an^2)
      return atanh(an/sqrt(an^2+tn^2))/an;
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
 arccs(~x,1) => asinh(x),
 arcsc(0,~k)  => 0,
 arcsc(-~x,~k) => -arcsc(x,k),
 arcsc(~x,-~k) => arcsc(x,k),

 arccs(~x,0) => acot(x),
 arccs(~x,1) => acsch(x),
 arccs(0, ~k) => elliptick(k),
 arccs(-~x,~k) => 2*elliptick(k)-arccs(x,k),
 arccs(~x,-~k) => arccs(x,k),

 arcsd(~x,0) => asin(x),
 arcsd(~x,1) => asinh(x),
 arcsd(0,~k)  => 0,
 arcsd(-~x,~k) => -arcsd(x,k),
 arcsd(~x,-~k) => arcsd(x,k),

 arcds(~x,0) => acsc(x),
 arcds(~x,1) => acsch(x),
 arcds(-~x,~k) => 2*elliptick(k)-arcds(x,k),
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

 df(arcsn(~x,~k),~x) => 1/(sqrt(1-x^2)*sqrt(1-k^2*x^2)),
 df(arccn(~x,~k),~x) => -1/(sqrt(1-x^2)*sqrt(1-k^2+k^2*x^2)),
 df(arcdn(~x,~k),~x) => -1/(sqrt(1-x^2)*sqrt(x^2-1+k^2)),
 df(arccd(~x,~k),~x) => -1/(sqrt(1-x^2)*sqrt(1-k^2*x^2)),
 df(arcsd(~x,~k),~x) => -1/(sqrt(1-(1-k^2)*x^2)*sqrt(1+k^2*x^2)),
 df(arcnd(~x,~k),~x) => 1/(sqrt(1-x^2)*sqrt(1-(1-k^2)*x^2)),
 df(arcdc(~x,~k),~x) => 1/(sqrt(x^2-1)*sqrt(x^2-k^2)),
 df(arcnc(~x,~k),~x) => 1/(sqrt(x^2-1)*sqrt(k^2+(1-k^2)*x^2)),
 df(arcsc(~x,~k),~x) => 1/(sqrt(1+x^2)*sqrt(1+(1-k^2)*x^2)),
 df(arcns(~x,~k),~x) => -1/(sqrt(x^2-1)*sqrt(x^2-1+k^2)),
 df(arcds(~x,~k),~x) => -1/(sqrt(x^2+k^2)*sqrt(x^2-1+k^2)),
 df(arccs(~x,~k),~x) => -1/(sqrt(1+x^2)*sqrt(x^2+1-k^2)),

  arcsn(~x,~k) =>  x*sym_int_RF(1, 1-x^2, 1-k^2*x^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x<=1 and abs k<=1,

  arcsc(~x,~k) => x*sym_int_RF(1, 1+x^2, 1+(1-k^2)*x^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs k<=1,

  arcsd(~x,~k) => x*sym_int_RF(1, 1+k^2*x^2, 1-(1-k^2)*x^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k
     and (abs k<1 and x^2 <= 1/(1-k^2) or abs k =1),
 
  arcns(~x,~k) => sign(x)*sym_int_RF(x^2, x^2-1, x^2-k^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x>=1 and abs k<=1,

  arccs(~x,~k) =>
         ((if x>= 0 then  y else 2*elliptick(k)-y)
          where y => sym_int_RF(x^2, x^2+1, x^2+1-k^2))
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs k<=1,

  arcds(~x,~k) => sign(x)*sym_int_RF(x^2, x^2+k^2, x^2+k^2-1)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k  and abs k<=1 and x^2 >= 1-k^2,

  arccn(~x,~k) =>
         (begin scalar w, y;
	    w:= 1-x^2;
	    y := sqrt w * sym_int_RF(x^2,1,1-k^2*w);
            return if x>=0 then y else 2*elliptick(k)-y;
	  end)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x<=1 and abs k<=1,
 
  arcnc(~x,~k) =>
         (begin scalar w, y;
	    w:= 1-x^2;
	    y := sqrt w * sym_int_RF(x^2,1,1+(1-k^2)*w);
            return if x>=0 then y else 2*elliptick(k)-y;
	  end)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x >=1 and abs k<=1,
 
  arcdn(~x,~k) =>  ((sqrt w * sym_int_RF(x^2,1,1-w))
                      where w => (1-x^2)/k^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs k<=1 and k neq 0
     and x <=1 and x >= sqrt(1-k^2),
 
  arcnd(~x,~k) =>  ((sqrt w * sym_int_RF(x^2,1,1+(k^2-1)*w))
                      where w => (x^2-1)/k^2)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and x >=1 
     and (abs k<1 and k neq 0 and x^2 <=1/(1-k^2) or abs k =1),

 arccd(~x,~k) =>
        (begin scalar w, y;
	   w:= (1-x^2)/(1-k^2);
	   y :=  sqrt w * sym_int_RF(x^2,1,1+k^2*w);
           return if x>=0 then y else 2*elliptick(k)-y;
	 end)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x<=1 and abs k<=1,

 arcdc(~x,~k) =>
        (begin scalar w, y;
	   w := (1-x^2)/(1-k^2);
	   y := sqrt w * sym_int_RF(x^2,1,1+w);
           return if x>=0 then y else 2*elliptick(k)-y;
	 end)
     when lisp !*rounded and impart x =0 and impart k =0 
     and numberp x and numberp k and abs x >=1 and abs k<=1
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
