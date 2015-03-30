module ztrrules;  % Ztrans ruleset.

% Author: Lisa Temme.

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


algebraic <<
ztransrules := {
  ztrans_aux(1,~n,~z) => z/(z-1),

  ztrans_aux(binomial(~n+~~k,~m),~n,~z) => z^(k+1)/(z-1)^(m+1) when
                                       (freeof(k,n) and freeof(m,n)),

  ztrans_aux(factorial(~n)/(factorial(~n-~k)*factorial(~k)),~n,~z)
                        => ztrans(binomial(n,k),n,z) when freeof(k,n),

  ztrans_aux(1/(~n+~~k),~n,~z) => z^(k-1)*(z*log(z/(z-1))
                              - sum(1/((j+1)*z^j),j,0,k-2))
                              when (freeof(k,n) and fixp(k) and k>0),

  ztrans_aux(~a^(~n+~~k),~n,~z) => a^k*z/(z-a) when (freeof(a,n)
                               and freeof(k,n)),

  ztrans_aux(1/~a^(~n+~~k),~n,~z) => sub(a=1/a,ztrans(a^(n+k),n,z))
                                 when (freeof(a,n) and freeof(k,n)),

  ztrans_aux(e^(~n*~~a),~n,~z) => -z/(e^a-z) when freeof(a,n),

  ztrans_aux(e^((~n+~~k)*~~a),~n,~z) => e^(a*k)*-z/(e^a-z)
                                   when (freeof(a,n) and freeof(k,n)),

  ztrans_aux(1/factorial(~n),~n,~z) => e^(1/z),

  ztrans_aux(1/factorial(2*~n+~~k),~n,~z) =>
                        z^((k-1)/2)*(sqrt(z)*sinh(1/sqrt(z))
                        - sum(1/(factorial(2*j+1)*z^j),j,0,(k-3)/2))
                        when (freeof(k,n) and fixp((k+1)/2) and k>0),

  ztrans_aux(1/factorial(2*~n+~~k),~n,~z) =>
                        z^(k/2)*(cosh(1/sqrt(z))
                        - sum(1/(factorial(2*j)*z^j),j,0,k/2-1))
                        when (freeof(k,n) and fixp(k/2) and k>=0),

  ztrans_aux((-1)^~n/factorial(2*~n+~~k),~n,~z) =>
                (-z)^((k-1)/2)*(sqrt(z)*sin(1/sqrt(z))
                - sum((-1)^j/(factorial(2*j+1)*z^j),j,0,(k-3)/2))
                      when(freeof(k,n) and fixp((k+1)/2) and k>0),

  ztrans_aux((-1)^~n/factorial(2*~n+~~k),~n,~z) =>
                        (-z)^(k/2)*(cos(1/sqrt(z))
                        - sum((-1)^j/(factorial(2*j)*z^j),j,0,k/2-1))
                        when (freeof(k,n) and fixp(k/2) and k>=0),

  ztrans_aux(sinh(~~al*~n+~~p),~n,~z) => z*(z*sinh(p) + sinh(al-p))
                                   /(z^2 - 2*z*cosh(al) + 1)
                                   when (freeof(al,n) and freeof(p,n)),

  ztrans_aux(cosh(~~al*~n+~~p),~n,~z) => z*(z*cosh(p) - cosh(al-p))
                                   /(z^2 - 2*z*cosh(al) + 1)
                                   when (freeof(al,n) and freeof(p,n)),

  ztrans_aux(sin(~~b*~n+~~p),~n,~z) =>  z*(z*sin(p) + sin(b-p))
                                   /(z^2 - 2*z*cos(b) + 1)
                                    when (freeof(b,n) and freeof(p,n)),

  ztrans_aux(cos(~~b*~n+~~p),~n,~z) =>  z*(z*cos(p) - cos(b-p))
                                   /(z^2 - 2*z*cos(b) + 1)
                                    when (freeof(b,n) and freeof(p,n)),

  ztrans_aux(e^(~~a*~n)*sin(~~b*~n),~n,~z) =>
                            z*e^a*sin(b)/(z^2-2*z*e^a*cos(b)+e^(2*a))
                                   when (freeof(a,n) and freeof(b,n)),

  ztrans_aux(e^(~~a*~n)*cos(~~b*~n),~n,~z) =>
                        z*(z-e^a*cos(b))/(z^2-2*z*e^a*cos(b)+e^(2*a))
                                   when (freeof(a,n) and freeof(b,n)),

  ztrans_aux(cos(~~b*(~n+~~k))/(~n+~~k),~n,~z) =>
                        z^(k-1)*(z*log(z/sqrt(z^2-2*z*cos(b)+1))
                        - sum(cos(b*(j+1))/((j+1)*z^j),j,0,k-2))
                        when (freeof(b,n) and freeof(k,n)
                                     and fixp(k) and k>0),

  ztrans_aux(sin(~~b*(~n+~~k))/(~n+~~k),~n,~z) =>
                        z^(k-1)*(-z*atan(sin(b)/(cos(b)-z))
                        - sum(sin(b*(j+1))/((j+1)*z^j),j,0,k-2))
                        when (freeof(b,n) and freeof(k,n)
                                     and fixp(k) and k>0),

  ztrans_aux((-1)^n*cos(~~b*(~n+~~k))/(~n+~~k),~n,~z) =>
                        -(-z)^(k-1)*(z*log(sqrt(z^2+2*z*cos(b)+1/z))
                        - sum((-1)^j*cos(b*(j+1))/((j+1)*z^j),j,0,k-2))
                        when (freeof(b,n) and freeof(k,n) and fixp(k)),

  ztrans_aux(cos(~~b*~n)/factorial(~n),~n,~z) =>
                                cos(sin(b)/z)*e^(cos(b)/z)
                                when freeof(b,n),

  ztrans_aux(cos(~~b*(~n+~~k))/factorial(~n+~~k),~n,~z) =>
                        z^k*(cos(sin(b)/z)*e^(cos(b)/z)
                        - sum(cos(b*j)/(factorial(j)*z^j),j,0,k-1))
                                     when (freeof(b,n) and fixp(k)),

  ztrans_aux(sin(~~b*~n)/factorial(~n),~n,~z) =>
                                sin(sin(b)/z)*e^(cos(b)/z)
                                when freeof(b,n),

  ztrans_aux(sin(~~b*(~n+~~k))/factorial(~n+~~k),~n,~z) =>
                        z^k*(sin(sin(b)/z)*e^(cos(b)/z)
                        - sum(sin(b*j)/(factorial(j)*z^j),j,0,k-1))
                                     when (freeof(b,n) and fixp(k)),

%LINEARITY
  ztrans_aux(-~f,~n,~z)   => -ztrans(f,n,z),
  ztrans_aux(~a,~n,~z)    => a*ztrans(1,n,z)   when freeof(a,n),
  ztrans_aux(~a*~f,~n,~z) => a*ztrans(f,n,z)   when freeof(a,n),
  ztrans_aux(~f/~b,~n,~z) => ztrans(f,n,z)/b   when freeof(b,n),
  ztrans_aux(~a/~g,~n,~z) => a*ztrans(1/g,n,z) when (freeof(a,n)
                                                    and not(a=1)),

  ztrans_aux(~a*~f/~g,~n,~z) => a*ztrans(f/g,n,z) when freeof(a,n),

  ztrans_aux(~f/(~b*~g),~n,~z) => ztrans(f/g,n,z)/b when freeof(b,n),

  ztrans_aux((~f+~g)/~~h,~n,~z) => ztrans(f/h,n,z) + ztrans(g/h,n,z),

%MULTIPLICATION
  ztrans_aux(~n^~~p*~~f,~n,~z) => -z*df(ztrans(n^(p-1)*f,n,z),z)
                                  when freeof(p,n) and fixp(p) and p>0,

  ztrans_aux(~n^~~p*~~f/~g,~n,~z) => -z*df(ztrans(n^(p-1)*f/g,n,z),z)
                                  when freeof(p,n) and fixp(p) and p>0,

%Shift up
  ztrans_aux(~f(~n+~k),~n,~z) =>
                        z^k*(ztrans(f(n),n,z)-sum(f(n)*z^(-n),n,0,k-1))
                        when freeof(k,n) and fixp(k) and k>0,

  ztrans_aux(~f(~n+~k)/~g(~n+~k),~n,~z) =>
                        z^k*(ztrans(f(n)/g(n),n,z)-
                        sum(f(n)/g(n)*z^(-n),n,0,k-1))
                        when freeof(k,n) and fixp(k) and k>0,

  ztrans_aux(1/~g(~n+~k),~n,~z) =>
                        z^k*(ztrans(1/g(n),n,z)-
                        sum(1/g(n)*z^(-n),n,0,k-1))
                        when freeof(k,n) and fixp(k) and k>0,

%Similar Expressions
  ztrans_aux(~a^(~n+~~k)*~f,~n,~z) => a^k*sub(z=(z/a),ztrans(f,n,z))
                                  when freeof(a,n) and freeof(k,n),

  ztrans_aux(~a^(~n+~~k)*~~f/~g,~n,~z) =>
                                    a^k*sub(z=(z/a),ztrans(f/g,n,z))
                                    when freeof(a,n) and freeof(k,n),

  ztrans_aux(~a^(~n-~~k)*~~f/~g,~n,~z) =>
                                    a^k*sub(z=(z/a),ztrans(f/g,n,z))
                                    when freeof(a,n) and freeof(k,n),

  ztrans_aux(1/~a^(~n+~~k)*~f,~n,~z) => 1/a^k*sub(z=z*a,ztrans(f,n,z))
                                    when freeof(a,n) and freeof(k,n),

  ztrans_aux(1/~a^(~n+~~k)*~~f/~g,~n,~z) =>
                                    1/a^k*sub(z=z*a,ztrans(f/g,n,z))
                                    when freeof(a,n) and freeof(k,n),

%Summations
  ztrans_aux(sum(~f(~k)*~g(~n-~k),~k,0,~n),~n,~z) =>
                                ztrans(f(n),n,z)*ztrans(g(n),n,z)
                                when freeof(k,n),

  ztrans_aux(~summ(~f,~k,0,~n),~n,~z) => z*ztrans(sub(k=n,f),n,z)/(z-1)
                                     when freeof(k,n) and summ = sum,

%  ztrans_aux(~summ(~~f/~g,~k,0,~n),~n,~z) =>
%                                     z*ztrans(SUB(k=n,f/g),n,z)/(z-1)
%                                    when (freeof(k,n) and summ = sum),

  ztrans_aux(~summ(~f,~k,0,(~n+~w)),~n,~z) =>
                        z*ztrans(sub(k=n,f),n,z)/(z-1) +
                        sum(z^x*(ztrans(sub(k=n,f),n,z) -
                        sum(sub(k=n,f)/z^n,n,0,x-1)),x,1,w)
                        when (freeof(w,n) and fixp(w) and w>0
                        and summ = sum),

%  ztrans_aux(~summ(~~f/~g,~k,0,(~n+~w)),~n,~z) =>
%                       z*ztrans(SUB(k=n,f/g),n,z)/(z-1) +
%                       sum(z^x*(ztrans(SUB(k=n,f/g),n,z) -
%                       sum(SUB(k=n,f/g)/z^n),n,0,(x-1)),x,1,w)
%                       when (freeof(w,n) and fixp(w) and w>0
%                       and summ = sum),

  ztrans_aux(~summ(~f,~k,~p,~n),~n,~z) =>
                        ztrans(sum(sub(k=k+p,f),k,0,n-p),n,z)
                        when (freeof(p,n) and fixp(p) and p>0
                        and summ = sum),

  ztrans_aux(~summ(~f,~k,0,(~nn)),~n,~z) =>
                ztrans(sub(k=n,f),n,z)/(z-1) -
                sum(1/z^y*ztrans(sub(k=n,f),n,z),y,1,((n-nn)-1))
                when (freeof((nn-n),n) and fixp(nn-n) and
                (nn-n)<0 and summ = sum),

%  ztrans_aux(~summ(~~f/~g,~k,0,(~nn)),~n,~z) =>
%               ztrans(SUB(k=n,f/g),n,z)/(z-1) -
%               sum(1/z^y*ztrans(SUB(k=n,f/g),n,z),y,1,((n-nn)-1))
%               when (freeof((nn-n),n) and fixp (nn-n) and
%               (nn-n)<0 and summ = sum),

  ztrans_aux(~summ(~f,~k,~p,~n),~n,~z) =>
                        ztrans(sum(sub(k=k+p,f),k,0,n+(-p)),n,z)
                        when (freeof(p,n) and fixp(p) and p<0
                        and summ = sum),

  ztrans_aux(~summ(~f,~k,~p,~q),~n,~z) =>
                        (begin scalar r;
                         r := q-p;
                         return ztrans(sum(sub(k=k+p,f),k,0,r),n,z);
                         end)  when (not(p=0) and summ = sum),

%Errors
%======
  ztrans_aux(~~f/(~n+~~k),~n,~z) =>
        (begin
        newrederr{"ERROR: zero divisor in ",
                  sum(f/((n+k)*z^n),n,0,infinity)}
        end)
        when (numberp k and k<1),

  ztrans_aux(~~f/factorial(~n+~~k),~n,~z) =>
        (begin
        newrederr{"ERROR: zero divisor in "
                  ,sum(f/(factorial(n+k)*z^n),n,0,infinity)}
        end)
        when (numberp k and k<0)

}$

let ztransrules>>;

% INVZTRANS: inverse Z transformation, see
% Bronstein, Semendjajew: Taschenbuch der Mathematik, 4.4.4

load!-package 'residue;

%######################################################################

% Final simplification,
% by Wolfram Koepf
algebraic<<
ztranstrighypsimplificationrules:={
asin(sin(~xx))=>xx,
acos(cos(~xx))=>xx,
atan(tan(~xx))=>xx,
acot(cot(~xx))=>xx,
asinh(sinh(~xx))=>xx,
acosh(cosh(~xx))=>xx,
atanh(tanh(~xx))=>xx,
acoth(coth(~xx))=>xx,
(1-sin(~xx)^2)^(1/2)=>cos(xx),
(1-cos(~xx)^2)^(1/2)=>sin(xx),
(cosh(~xx)^2-1)^(1/2)=>sinh(xx),
(1+sinh(~xx)^2)^(1/2)=>cosh(xx),
(cosh(~xx)+sinh(~xx))^~nn=>cosh(nn*xx)+sinh(nn*xx),
(cosh(~xx)-sinh(~xx))^~nn=>cosh(nn*xx)-sinh(nn*xx)
} $

operator invztrans,invztrans_aux,invztrans1,invztrans_end;

% let {binomial(~n,~k)=>prod(n-i,i,0,k-1)/factorial(k) when fixp(k)};
let {binomial(~n,~k)=>
        (for i:=0:k-1 product n-i)/factorial(k) when fixp(k)};

>>;
% Procedural embedding,
% by Wolfram Koepf
algebraic procedure do_invztrans(f,z,n);
begin
scalar tmp,numtmp,dentmp;
   tmp := invztrans1(f,z,n);
   numtmp:=num(tmp);
   dentmp:=den(tmp);
   numtmp:=(numtmp where ztranstrighypsimplificationrules);
   dentmp:=(dentmp where ztranstrighypsimplificationrules);
   tmp:=numtmp/dentmp;
   % tmp:=sub(invztrans_end=invztrans,tmp);
   % macht Probleme wegen Rekursivitaet, next if has no part(.0)
   return tmp;
%   if part(tmp,0)=invztrans then
%       return lisp mk!*sq((list((car fkern list('invztrans,f,z,n) . 1)
%                                                 . 1)) . 1)
%   else return tmp;
end$


%********************************************************************

% invztrans ruleset
% by Lisa Temme

put('slash, 'simpfn, 'simpiden);

algebraic <<
invztransrules:=
{
%Linear rules
%============

  invztrans (~p,~z,~n) => !$do_invztrans!$
        when freeof((!$do_invztrans!$ :=
                          do_invztrans(p,z,n)),lisp 'fail),

  invztrans1(~p,~z,~n) => p*invztrans1(1,z,n)
                 when freeof(p,z) and not (p=1),

  invztrans1(~p*~f,~z,~n) => p*invztrans1(f,z,n) when freeof(p,z),

  invztrans1(~f/~q,~z,~n) => invztrans1(f,z,n)/q when freeof(q,z),

  invztrans1(~p/~g,~z,~n) => p*invztrans1(1/g,z,n) when freeof(p,z)
                            and not(p=1),

  invztrans1(~p*~f/~g,~z,~n) => p*invztrans1(f/g,z,n) when freeof(p,z),

  invztrans1(~f/(~q*~g),~z,~n) =>
                                invztrans1(f/g,z,n)/q when freeof(q,z),

  invztrans1(-~f,~z,~n) => -invztrans1(f,z,n),

  invztrans1((~f+~g)/~~h,~z,~n) =>
                             invztrans1(f/h,z,n) + invztrans1(g/h,z,n),


%**********************************************************************

%For trigonometric/hyperbolic rational
%input goto ruleset invztrans_aux
%=====================================

  invztrans1(~f/~g,~z,~n) => invztrans_aux(f,g,z,n)

        when ( not(freeof(f/g,sin))  or not(freeof(f/g,cos)) or
               not(freeof(f/g,sinh)) or not(freeof(f/g,cosh)) ),


%If not a trig/hyperbolic rational
%input goto ruleset invztrans_end
%(ie. all remaining inputs)
%=================================

  invztrans1(~f,~z,~n) => invztrans_end(f,z,n)
%,


%  invztrans1(~f,~z,~n) =>
%   (begin
%    return lisp mk!*sq((list((car fkern list('invztrans1,reval 'f,
%                                             reval 'z,reval 'n) . 1)
%. 1)) . 1);
%   end)


};let invztransrules;


%######################################################################

invztrans_auxrules :=
{

%Linearity
%=========
  invztrans_aux(~f,-~~x*~z^2+~~w*~z-~y,~z,~n) =>
                                -invztrans_aux(f,x*z^2-w*z+y,z,n),

  invztrans_aux(~f+~h,~g,~z,~n) =>
                invztrans_aux(f,g,z,n) + invztrans_aux(h,g,z,n),


%Rules to match trigonometric/hyperbolic
%rational inputs.
%=======================================

  invztrans_aux(~z,(~~x*~z^2-~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            2*sry^n*sin(acos(srx*w/(2*sry*x))*n)
            / ( srx^n*sqrt(4*x*y-w^2) ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>0 and (w^2)<(4*x*y))
        or   (numberp(x) and numberp(w) and not(numberp(y)) and w>0)
        or   (not(numberp(x) and numberp(w) and numberp(y))
              and freeof((w/x),cosh)),


  invztrans_aux(~z,(~~x*~z^2+~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            -2*sry^n*(-1)^n*sin(acos(srx*w/(2*sry*x))*n)
            / ( srx^n*sqrt(4*x*y-w^2) ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>0 and (w^2)<(4*x*y))
        or   (numberp(x) and numberp(w) and not(numberp(y)) and w<0)
        or   (not(numberp(x) and numberp(w) and numberp(y))
              and freeof((w/x),cosh)),

  invztrans_aux(~z,(~~x*~z^2-~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            2*sry^n*sinh(acosh(srx*w/(2*sry*x))*n)
            / ( srx^n*sqrt(w^2-4*x*y) ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and (w^2)>(4*x*y))
        or   (not(numberp(x) and numberp(w) and numberp(y))),

  invztrans_aux(~z,(~~x*~z^2+~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            -2*(-sry)^n*sinh(acosh(srx*w/(2*sry*x))*n)
            / ( srx^n*sqrt(w^2-4*x*y) ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and (w^2)>(4*x*y))
        or   (not(numberp(x) and numberp(w) and numberp(y))),

  invztrans_aux(~z^2,(~~x*~z^2-~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            (sry^n*(sqrt(4*x*y-w^2)*cos(acos(srx*w/(2*sry*x))*n)
            + sin(acos(srx*w/(2*sry*x))*n)*w))
            / ( srx^n*sqrt(4*x*y-w^2)*x ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>0 and (w^2)<(2*x*y))
        or   (numberp(x) and numberp(w) and w>0)
        or   (not(numberp(x) and numberp(w) and numberp(y))
              and freeof((w/x),cosh)),


  invztrans_aux(~z^2,(~~x*~z^2+~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            (sry^n*(-1)^n*(sqrt(4*x*y-w^2)*cos(acos(srx*w/(2*sry*x))*n)
            + sin(acos(srx*w/(2*sry*x))*n)*w))
            / ( srx^n*sqrt(4*x*y-w^2)*x ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>0 and (w^2)>(4*x*y))
        or   (numberp(x) and numberp(w) and w<0)
        or   (not(numberp(x) and numberp(w) and numberp(y))
              and freeof((w/x),cosh)),


  invztrans_aux(~z^2,(~~x*~z^2-~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            (sry^n*(sqrt(w^2-4*x*y)*cosh(acosh(srx*w/(2*sry*x))*n)
            + sinh(acosh(srx*w/(2*sry*x))*n)*w))
            / ( srx^n*sqrt(w^2-4*x*y)*x ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>(4*x*y))
        or   (not(numberp(x) and numberp(w) and numberp(y))),

  invztrans_aux(~z^2,(~~x*~z^2+~~w*~z+~y),~z,~n) =>

        sub(srx=sqrt(x), srw=sqrt(w), sry=sqrt(y),
            ((-sry)^n*(sqrt(w^2-4*x*y)*cosh(acosh(srx*w/(2*sry*x))*n)
            + sinh(acosh(srx*w/(2*sry*x))*n)*w))
            / ( srx^n*sqrt(w^2-4*x*y)*x ) )

        when (numberp(x) and numberp(w) and numberp(y) and
              y>0 and w>(4*x*y))
        or   (not(numberp(x) and numberp(w) and numberp(y))),

  invztrans_aux(~f,~g,~z,~n) => invztrans_end(f/g,z,n)

};let invztrans_auxrules;

%######################################################################

invztrans_endrules :=
{

%Rules to match other
%trigonometric inputs
%====================

  invztrans_end(~z*atan(sin(~b)//(cos(~b)-~z)),~z,~n) =>
        -sin(b*(n+1))/(n+1) when numberp(b)
     or (freeof(b,z) and not(numberp(b))),

  invztrans_end(~z*atan(sin(~b)//(~z+cos(~b))),~z,~n) =>
        (-1)^n*sin(b*(n+1))/(n+1) when numberp(a)
     or (freeof(a,z) and not(numberp(a))),

  invztrans_end(~z*log(~z/sqrt(~z^2-~a*~z+1)),~z,~n) =>
        cos(acos(a/2)*(n+1))/(n+1) when (numberp(a) and a>0 and a<=-2)
     or (freeof(a,z) and not(numberp(a))),

  invztrans_end(~z*log(~z/sqrt(~z^2+~a*~z+1)),~z,~n) =>
        cos(acos(-a/2)*(n+1))/(n+1) when (numberp(a) and a<0 and a>=-2)
     or (freeof(a,z) and not(numberp(a))),

  invztrans_end(~z*log(sqrt(~z^2-~a*~z+1)/~z),~z,~n) =>
       (-1)^n* cos(acos(-a/2)*(n+1))/(n+1)
        when (numberp(a) and a<0 and a>=-2)
     or (freeof(a,z) and not(numberp(a))),

  invztrans_end(~z*log(sqrt(~z^2+~a*~z+1)/~z),~z,~n) =>
        (-1)^n*cos(acos(a/2)*(n+1))/(n+1)
        when (numberp(a) and a>0 and a<=-2)
     or (freeof(a,z) and not(numberp(a))),

  invztrans_end(cos(~a/~z)*e^(sqrt(1-~a^2)/~z),~z,~n) =>
        cos(asin(a)*n)/factorial(n) when (numberp(a) and a<=1 and
       a>=-1)
     or (freeof(a,z) and not(numberp(a))),

%**********************************************************************

%Rule to calculate the Residues and hence
%determine the invztrans of a rational input
%===========================================
% by Wolfram Koepf

  invztrans_end(~f,~z,~n)=>
        (begin scalar denominator, result, solutionset, solution,
          !*fullroots;
          on fullroots;
          denominator:=den(f);
          solution:=solve(denominator,z);
          if not freeof(solution,root_of) then
            rederr("denominator could not be factorized");
          solutionset:=
           for i:=1:length(solution) collect(part(part(solution,i),2));
          result:=
            for each a in solutionset sum(residue(f*z^(n-1),z,a));
          return(result)
        end) when type_ratpoly(f,z),

%**********************************************************************

%Rules to match non-rational inputs
%==================================

%(Binomial)
%----------
  invztrans(~z^~~k/(z+~~a)^~~m,~z,~n) =>
                binomial(n+k-1,m-1)*(-a)^(n+k)/(-a)^m
                when freeof(k,z) and freeof(m,z) and freeof(a,z) and
                     (not(numberp k) or (numberp k and fixp k)) and
                     (not(numberp m) or (numberp m and fixp m)),

%(over n!)
%---------

  invztrans_end(e^(~k/~z),~z,~n) => k^n/factorial(n) when freeof(k,z),

  invztrans_end(e^(~k/~z)/~z,~z,~n) =>
                                 n/k*k^n/factorial(n) when freeof(k,z),

  invztrans_end(1/e^(~k/~z),~z,~n) =>
                                  (-k)^n/factorial(n) when freeof(k,z),

  invztrans_end(1/(e^(~k/~z)*~z),~z,~n) =>
                             -n/k*(-k)^n/factorial(n) when freeof(k,z),

  invztrans_end(e^(~k/(~~j*~z)),~z,~n) =>
                 (k/j)^n/factorial(n) when freeof(k,z) and freeof(j,z),

  invztrans_end(e^(~k/(~~j*~z))/~z,~z,~n) =>
         n/(k/j)*(k/j)^n/factorial(n) when freeof(k,z) and freeof(j,z),

  invztrans_end(1/e^(~k/(~~j*~z)),~z,~n) =>
                (-k/j)^n/factorial(n) when freeof(k,z) and freeof(j,z),

  invztrans_end(1/(e^(~k/(~~j*~z))*~z),~z,~n) =>
       n/(-k/j)*(-k/j)^n/factorial(n) when freeof(k,z) and freeof(j,z),

  invztrans_end(cos(sin(~~b)/~z)*e^(cos(~~b)/~z),~z,~n) =>
                               cos(b*n)/factorial(n) when freeof (b,z),

  invztrans_end(sin(sin(~~b)/~z)*e^(cos(~~b)/~z),~z,~n) =>
                               sin(b*n)/factorial(n) when freeof (b,z),


%(over 2n!)
%----------

  invztrans_end(cosh(~k/sqrt(~z)),~z,~n) =>
                               k^(2*n)/factorial(2*n) when freeof(k,z),

  invztrans_end(cos(~k/sqrt(~z)),~z,~n) =>
                            (-(k^2))^n/factorial(2*n) when freeof(k,z),

  invztrans_end(cosh(~k/(~~j*sqrt(~z))),~z,~n) =>
           (k/j)^(2*n)/factorial(2*n) when freeof(k,z) and freeof(j,z),

  invztrans_end(cos(~k/(~~j*sqrt(~z))),~z,~n) =>
          (-(k/j)^2)^n/factorial(2*n) when freeof(k,z) and freeof(j,z),

%(over (2n+1)!)
%--------------

  invztrans_end(sqrt(~z)*sinh(~k/sqrt(~z)),~z,~n) =>
                          k*k^(2*n)/factorial(2*n+1) when freeof (k,z),

  invztrans_end(sqrt(~z)*sinh(~k/sqrt(-~z)),~z,~n) =>
                       i*k*(-k^2)*n/factorial(2*n+1) when freeof (k,z),

  invztrans_end(sqrt(~z)*sin(~k/sqrt(~z)),~z,~n) =>
                         k*(-k^2)^n/factorial(2*n+1) when freeof (k,z),

  invztrans_end(sqrt(-~z)*sinh(~k/sqrt(~z)),~z,~n) =>
                 sqrt(-k^2)*k^(2*n)/factorial(2*n+1) when freeof (k,z),

  invztrans_end(sqrt(-~z)*sin(~k/sqrt(~z)),~z,~n) =>
                 k*(-k^2)^n/(i*factorial(2*n+1)) when freeof (k,z),

  invztrans_end(sqrt(-~z)*sinh(~k/sqrt(-~z)),~z,~n) =>
                         k*(-k^2)*n/factorial(2*n+1) when freeof (k,z),

  invztrans_end(sqrt(-~z)*sin(~k/sqrt(~z)),~z,~n) =>
                k*(-k^2)*n/(i*factorial(2*n+1)) when freeof (k,z),


  invztrans_end(sqrt(~z)*sinh(~k/(~~j*sqrt(~z))),~z,~n) =>
                                    (k/j)*(k/j)^(2*n)/factorial(2*n+1)
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(-~z)*sinh(~k/(~~j*sqrt(~z))),~z,~n) =>
                                    (k/j)*(k/j)^(2*n)/factorial(2*n+1)
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(-~b*~z)*sinh(~k/(sqrt(~b)*sqrt(~z))),~z,~n) =>
                                 sqrt(-k^2)*(k^2/b)^n/factorial(2*n+1)
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(~z)*sin(~k/(~~j*sqrt(~z))),~z,~n) =>
                  (sqrt(-k^2)/j)*(-k^2)^n/j^(2*n)/(i*factorial(2*n+1))
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(-~z)*sin(~k/(~~j*sqrt(~z))),~z,~n) =>
                                (k/j)*(k/j)^(2*n)/(i*factorial(2*n+1))
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(-~b*~z)*sin(~k/(sqrt(~b)*sqrt(~z))),~z,~n) =>
                                     k*(-k^2/b)^n/(i*factorial(2*n+1))
                                     when freeof (k,z) and freeof(b,z),


  invztrans_end(sqrt(~z)*sinh(~k/(~~j*sqrt(-~z))),~z,~n) =>
                                  i*(k/j)*(k/j)^(2*n)/factorial(2*n+1)
                                     when freeof (k,z) and freeof(j,z),

  invztrans_end(sqrt(~z)*sin(~k/(~~j*sqrt(-~z))),~z,~n) =>
                  (sqrt(-k^2)/j)*(sqrt(-k^2)/j)^(2*n)/factorial(2*n+1)
                                     when freeof (k,z) and freeof(j,z),

%(over n+1)
%----------

  invztrans_end(~z*log(~~b*~z/(~~b*~z+~a)),~z,~n) =>
                   (-a/b)^(n+1)/(n+1) when freeof(a,z) and freeof(b,z),

  invztrans_end(~z*log((~~b*~z+~a)/(~~b*~z)),~z,~n) =>
                                   -invztrans1(z*log(b*z/(b*z+a)),z,n)
                                      when freeof(a,z) and freeof(b,z),


%If input has not matched any rules
%return INVZTRANS(~f,~z,~n)
%==================================

  invztrans_end(~f,~z,~n) =>  lisp 'fail


};let invztrans_endrules;
>>;

endmodule;

end;
