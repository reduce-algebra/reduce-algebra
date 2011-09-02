module specfaux;  % Auxiliary functions for
                  %Special functions package for REDUCE.

% Author:  Winfried Neun  Feb 1993

create!-package ('(specfaux
                   sfbinom
                   sfpolys
                   sfbdata),
                 '(contrib specfn));

load!-package 'specfn;

endmodule;


module sfbinom;   % Procedures for computing Binomial coefficients
%
% Author: Winfried Neun, Feb 1993

algebraic operator binomial;

algebraic << let { binomial (~n,~k) => factorial n /
                                    factorial k / factorial (n-k)
                        when fixp n and fixp k and n >= k and k >= 0,
                binomial (~n,~k) =>
                    gamma(n+1) / gamma (k+1) / gamma(n-k+1) } >>;

% Some rules for quotients of binomials are still missing

endmodule;


module sfpolys;   % Assorted Polynomials
                  % will be a package of its own one day
%
% Author: Winfried Neun, Feb 1993


% Bernoulli Polynomials (see e.g. Abramowitz Stegun , chapter 23

algebraic operator bernoullip;

algebraic <<
let { bernoullip (~n,~x) => (for k:=0:n sum (binomial(n,k) *
                         bernoulli(k) * x^(n-k)))
                                          when fixp n and n >=0,
     bernoullip (~n,0) => bernoulli n     when fixp n and n >=0}
>>;

 % Univariate orthogonal bases (for approximation etc).

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1993, all rights resrved

algebraic procedure monomial_base(x,n);
     for i:=0:n collect x**i;

algebraic procedure trigonometric_base(x,n);
     1 . for i:=1:n join list(sin(i*x),cos(i*x));

algebraic procedure bernstein_base(x,n);
     for i:=0:n collect
         binomial(n,i)*(1-x)**(n-i)*x**i;

algebraic procedure legendre_base(x,n,a,b);
     legendre_base1(x,n,{a/2-b/2 + (1+a/2+b/2)*x,1},1,a,b);

algebraic procedure legendre_base1(x,n,base,r,a,b);
     if r>=n then reverse base else
     legendre_base1(x,n,
       (((2*r+a+b+1)*(a**2-b**2)+(2*r+a+b)*(2*r+1+a+b)*(2*r+2+a+b)*x)/
                (2*(r+1)*(r+1+a+b)*(2*r+a+b))*first base -
                2*(r+a)*(r+b)*(2r+2+a+b)/(2*(r+1)*(r+1+a+b)*
                        (2*r+a+b))*second base)
              . base, r+1,a,b);

algebraic procedure laguerre_base(x,n,a);
     laguerre_base1(x,n,{1-x+a,1},1,a);

algebraic procedure laguerre_base1(x,n,base,r,a);
     if r>=n then reverse base else
     laguerre_base1(x,n,
        ((1+2r-x+a)/(r+1)*first base - (r+a)/(r+1)*second base )
              . base, r+1,a);

algebraic procedure hermite_base(x,n);
     hermite_base1(x,n,{1-x,1},1);

algebraic procedure hermite_base1(x,n,base,r);
     if r>=n then reverse base else
     hermite_base1(x,n,
        (2x*first base - 2r*second base)
              . base, r+1);

algebraic procedure chebyshev_base_t(x,n);
     chebyshev_base_t1(x,n,{x,1},1);

algebraic procedure chebyshev_base_t1(x,n,base,r);
     if r>=n then reverse base else
     chebyshev_base_t1(x,n,
        (2x*first base - second base )
              . base, r+1);

algebraic procedure chebyshev_base_u(x,n);
     chebyshev_base_t1(x,n,{2x,1},1);

algebraic procedure gegenbauer_base1(x,n,base,r,a);
     if r>=n then reverse base else
     gegenbauer_base1(x,n,
        (2*(r+a)/(r+1)*x*first base - (r+2*a-1)/(r + 1)*second base )
              . base, r+1,a);

algebraic procedure gegenbauer_base(x,n,a);
     gegenbauer_base1(x,n,{2*a*x,1},1,a);


algebraic <<

operator hermitep,bernsteinp,jacobip,legendrep,
         laguerrep,chebyshevt,chebyshevu,gegenbauerp;

let {hermitep (~n,~x)=> sub(z = x,first reverse hermite_base (z,n))
                        when fixp n and n > 0};

let {bernsteinp (~n,~x) => sub(z = x,first bernstein_base (z,n))
                        when fixp n and n > 0};

let{ legendrep (~n,~x) => sub(z = x,
                        first reverse legendre_base (z,n,0,0))
                        when fixp n and n > 0,
     legendrep (~n,~m,~x) => (-1)^m *(1-x^2)^(m/2)*
                                df(legendrep (n,x),x,m)
                        when fixp n and n > 0 and fixp m and m > 0,
     jacobip (~n,~a,~b,~x) => sub(z = x
                        ,first reverse legendre_base (z,n,a,b))
                        when fixp n and n > 0};

let{ laguerrep(~n,~x) => sub(z = x,first reverse laguerre_base(z,n,0))
                        when fixp n and n > 0,
     laguerrep(~n,~a,~x) => sub(z = x,
                                first reverse laguerre_base(z,n,a))
                        when fixp n and n > 0};

let {chebyshevt (~n,~x) => sub(z = x,
                                first reverse chebyshev_base_t(z,n))
                        when fixp n and n > 0};

let {chebyshevu (~n,~x) => sub(z = x,
                                first reverse chebyshev_base_u(z,n))
                        when fixp n and n > 0};

let {gegenbauerp (~n,~a,~x) => sub(z = x,
                                first reverse gegenbauer_base(z,n,a))
                        when fixp n and n > 0};
>>;

endmodule;


module sfbdata;  % Generate necessary data for Bernoulli computation.

% Author:  Winfried Neun.

fluid '(compute!-bernoulli);

global '(!*force);

flag('(force),'switch);

flag('(on),'eval);

on force;

symbolic macro procedure mk!-bernoulli u;
   <<for i := 1:300 do retrieve!*bern i;
     list('quote, bernoulli!-alist) >>;

% When I read in save!-bernoulli the macro mk!-bernoulli() will get
% expanded.  This is because of the RLISP flag "*force".  The effect
% will be that the definition of save!-bernoulli() is in effect
% just   bernoulli!-alist := '((....))

symbolic procedure save!-bernoulli();
   bernoulli!-alist := mk!-bernoulli();

% I want to execute save!-bernoulli() just once to initialize the
% table.  That way even if I am running interpreted the painfully
% slow initial calculation of the table gets done only once when
% I first process this chunk of code.

save!-bernoulli()$

compute!-bernoulli := t;

off force;

remflag('(on),'eval);

endmodule;


end;
