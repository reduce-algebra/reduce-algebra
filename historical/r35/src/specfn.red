module specfn;  % Special functions package for REDUCE.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...

%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%                           Konrad-Zuse-Zentrum                  %
%                              fuer Informationstechnik Berlin,  %
%                           Heilbronner Str. 10                  %
%                           10711 Berlin - Wilmersdorf           %
%                           Federal Republic of Germany          %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     This package provides algebraic and numeric                %
%     manipulations upon various special functions:              %
%                                                                %
%              -- Bernoulli Numbers                              %
%              -- Gamma Function                                 %
%              -- Pochhammer Notation                            %
%              -- Digamma (Psi) Function and Derivatives         %
%              -- Riemann Zeta Function                          %
%              -- Bessel Functions J, Y, I and K                 %
%              -- Hankel Functions H1 and H2                     %
%              -- Kummer Hypergeometric Functions M and U        %
%              -- Struve, Lommel and Whittaker Functions         %
%              -- Integral funtions, Si, Ci, s_i (=si), Ei,...       
%                                                                %
%     accessible through the new operators Bernoulli, Gamma,     %
%     Pochhammer, Psi, Polygamma, Zeta, BesselJ, BesselY,        %
%     BesselI, BesselK, Hankel1, Hankel2, KummerM, KummerU,      %
%     Beta, StruveL, StruveH, Lommel1, Lommel2, WhittakerM       %
%     and WhittakerW, with the new switch SaveSFs.               %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %

% load!-package 'arith;   % For bootstrapping purposes.

create!-package ('(specfn
                   sfgen
                   sfbern
                   sfgamma
                   sfpsi
                   sfbes
                   sfkummer
                   sfother
                   dilog
                   sfbinom
                   sfpolys
                   sfsums
                   sfint),
                 '(contrib specfn));

exports sq2bf!*, c!:prec!:;

switch savesfs;
on savesfs;

symbolic fluid '(bernoulli!-alist new!*bfs bf!*base sf!-alist !*savefs);

symbolic ( bernoulli!-alist := nil );
symbolic ( sf!-alist        := nil );

symbolic ( new!*bfs := fluidp '!:bprec!: );
symbolic ( bf!*base := (if new!*bfs then 2 else 10) );
symbolic ( if not globalp 'log2of10 then
               << global '(log2of10);
                           log2of10 := 3.32193 >> );

symbolic smacro procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   (if new!*bfs then lispeval '!:bprec!: else !:prec!:);


algebraic array stieltjes (5);  % for use in raw zeta computations
algebraic array stf       (5);
algebraic array psi!*ld   (1);
algebraic (psi!*ld(0) := -1);   % precision at which last psi was calc'd
algebraic (psi!*ld(1) :=  0);   % lowest post-scale value acceptable at
                                % that precision

% These functions are needed in other modules.

algebraic procedure complex!*on!*switch;
   if not symbolic !*complex then
      if symbolic !*msg then
         << off msg;
            on complex;
            on msg >>
      else on complex
   else t;

algebraic procedure complex!*off!*switch;
   if symbolic !*complex then
      if symbolic !*msg then
         << off msg;
            off complex;
            on msg >>
      else off complex
   else t;

algebraic procedure complex!*restore!*switch(fl);
   if not fl then
      if symbolic !*msg then
         << off msg;
            if symbolic !*complex then
               off complex
            else on complex;
            on msg >>
      else if symbolic !*complex then
            off complex
         else on complex;

endmodule;


module sfgen;   % Handy functions used by the special functions package.

% Author: Chris Cannam.

exports sq2bf!*,bfprin!:roundup,sf!*eval;

symbolic procedure sf!*assoc(compare,val,alist);
   (if null alist then nil
    else if not lispeval list(compare,car car alist,val)
         then car alist
         else sf!*assoc(compare,val,cdr alist));

symbolic procedure sf!*multi!*assoc!*comparator(compare,vals,entry);
   (if null entry
    then (null vals)
    else (not null vals)
      and (lispeval list(compare,list('quote,car vals),
                                 list('quote,car entry)))
      and (sf!*multi!*assoc!*comparator(compare,cdr vals,cdr entry)));

symbolic procedure sf!*multi!*assoc(compare,vals,alist);
   (if null alist then nil
    else if sf!*multi!*assoc!*comparator(compare,vals,car car alist)
         then car alist
         else sf!*multi!*assoc(compare,vals,cdr alist));

symbolic procedure sf!*do!*eval(expression);
   begin scalar prepre, result;
      prepre := precision 0;
      precision (prepre + 3);
      result := aeval expression;
      precision prepre;
      return result;
   end;


% It's a finite state automaton!  It's a big nested if..then..else
% construct!  It's repulsive repetitive code!  It's easy to compile
% and run quickly!  It's longer than it needs to be!  It's all of
% this and more...!   (But at least it works.)

symbolic procedure sf!*eval(name,args);
   begin scalar part1, part2, result, prepre;
      args := cdr args;
      if (part1 := assoc((name . !*complex),sf!-alist))
      then if (part2 := sf!*assoc('lessp,c!:prec!:(),cdr part1))
           then if (result :=
                       sf!*multi!*assoc('evalequal,args,cdr part2))
                then result := cdr result
                else if !*savesfs
                     then setq(cdr part2,
                          (args . (result := sf!*do!*eval(name . args)))
                            . cdr part2)
                     else result := sf!*do!*eval(name . args)
           else if !*savesfs
                then setq(cdr part1,
                      (c!:prec!:()
                         . list ((args .
                              (result := sf!*do!*eval(name . args)))))
                       . cdr part1)
                else result := sf!*do!*eval(name . args)
      else if !*savesfs
           then sf!-alist :=
                 ((name . !*complex) .
                  list ((c!:prec!:() .
                       list ((args .
                              (result := sf!*do!*eval(name . args))
                             ))))) . sf!-alist
           else result := sf!*do!*eval(name . args);
      return result;
   end;

endmodule;


module sfbern;   % Procedures for computing Bernoulli numbers.
%
% Author: Chris Cannam, Oct 1992.

% Module for Euler numbers added by Kerry Gaskell, Sep 1993

%
% Note there is currently no Bernoulli polynomial function.
% There was one in an older version but it won't convert directly.
% This is Something To Be Done.

fluid '(compute!-bernoulli);

imports complex!*on!*switch, complex!*off!*switch,
   complex!*restore!*switch;

exports nearest!-int!-to!-bf, bernoulli!*calc, multi!*bern,
   single!*bern, retrieve!*bern;


algebraic operator bernoulli;
symbolic operator bernoulli!*calc;


algebraic (bernoullirules := {

   bernoulli(~n)  =>  1 when numberp n and n = 0,
   bernoulli(~n)  =>  -1/2 when numberp n and n = 1,
   bernoulli(~n)  =>  0 when numberp n and impart n = 0
      and n = floor n and n/2 neq floor (n/2) and n > 0,
   bernoulli(~n)  =>  bernoulli!*calc n when numberp n
      and impart n = 0 and n = floor n and n > 0

})$

algebraic (let bernoullirules);

algebraic procedure bernoulli!*calc n;
   begin scalar precom, result, prepre;
% Loading the SPECFAUX module will do two things.  First it will
% set compute!-bernoulli to true, so that there is no future attempt
% to load it.  Then it will set up a table of values in the variable
% bernoulli!-alist, where the table is computed at compile time rather
% than load or run-time.  This will make compiling specfaux.red a fairly
% slow process.  It also has bad consequences for any attempt to run
% this code interpreted.
% Note: ACN find the "algebraic symbolic" stuff here pretty heavy
% and confusing, but without it REDUCE sticks in calls to aeval (etc)
% in places where that is not wanted.  Maybe a future version of the
% language will make mixed algebraic/symbolic mode code less delicate.
      if (lisp null compute!-bernoulli) then
         symbolic <<errorset!*('(load_package '(specfaux)), nil); nil>>;
      precom := complex!*off!*switch();
      if (prepre := precision(0)) < !!nfpd
      then precision (!!nfpd + 1);
      result := algebraic symbolic retrieve!*bern(n);
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;

symbolic procedure retrieve!*bern n;
   begin scalar info, result;
      integer heldpre;
      info := assoc(n, bernoulli!-alist);
      if not info then result := bern!*calc (n, '(() () ()))
      else
         << info := cdr info;
            if !*rounded then
               if (heldpre := cadr info) and heldpre >= c!:prec!:() then
                     result := mk!*sq !*f2q rd!:prep caddr info
               else if (result := car info) then
                     result := mk!*sq !*f2q mkround
                                 divbf(i2bf!: caadr result,
                                       i2bf!: cdadr result)
               else result := bern!*calc(n, info)
            else if not (result := car info) then
                  result := bern!*calc(n,info) >>;
      return result;
   end;


symbolic procedure bern!*calc(n, info);
   begin scalar result;
      result := single!*bern(n/2);
      if !*rounded then
         info := list (car info, c!:prec!:(), result)
      else info := list (result, cadr info, caddr info);
      bernoulli!-alist := (n . info) . bernoulli!-alist;
      return result;
   end;



%
%  Computation of Bernoulli numbers using the algorithms of
%     one Herbert S. Wilf, presented by Sandra Fillebrown in the
%     Journal of Algorithms 13 (1992)
%
%  Chris Cannam, October 1992
%


%
% Useful auxiliary fn.
%

symbolic procedure nearest!-int!-to!-bf(x);
   (conv!:bf2i rb)
      where rb = (if lessp!:(x,bfz!*)
         then difference!:(x,bfhalf!*)
         else plus!:(x,bfhalf!*));



%
% Procedure to compute B(2k) for k = 2 ... n
%
% Returns list of even bernoullis from B(4) to B(2n),
% in reverse order; only works when compiled, owing
% to reliance upon msd!:, which is a compiled inline
% macro.
%
% If called with rounded mode off, it computes the
% exact quotient; otherwise it will usually approximate
% (to the correct precision) if it saves time to do so.
%


symbolic procedure multi!*bern(n);
   begin scalar results, primes, tprimes, r0, rk, rkm1, b2k,
         tpi, pie, tk, n2k;
       integer thisp, gn, prepre, prernd, p2k, k2, plim, d2k;

      results := nil;
      prernd := !*rounded;
      if not prernd then on rounded;
      prepre := precision 0;

      if new!*bfs then
         << gn := 2 * n * msd!: n;
            if gn < (log2of10*!!nfpd) then precision (!!nfpd + 2)
            else if prepre > (gn/3) or not prernd then
                     precision (gn/3 + 1)
            else precision (prepre + 2) >>
      else
         << gn := 2 * n * length explode n;
            if gn < !!nfpd then precision (!!nfpd + 2)
            else if prepre > gn or not prernd then
                     precision (gn + 2)
            else precision (prepre + 2) >>;

      tpi := pi!*(); pie := divbf(bfone!*, timbf(tpi, e!*()));

      if n < 1786 then primes := !*primelist!*
      else
         << primes := nil;
            for thisp := 3573 step 2 until (2*n + 1) do
               if primep thisp then primes := thisp . primes;
            primes := append(!*primelist!*, reverse primes) >>;

      r0 := sq2bf!* algebraic ((2*pi)**(-2));
      rkm1 := timbf(i2bf!: 4, r0);

      for k := 2:n do
         << k2 := 2*k;
            rk := timbf(i2bf!:(k2*(k2 - 1)), timbf(r0, rkm1));
            rkm1 := rk;

            tk := bfone!*; d2k := 1;
            plim := 1 + conv!:bf2i timbf(i2bf!: k2, pie);

            tprimes := cdr primes; thisp := car primes;
            while thisp <= plim do
               << p2k := thisp ** k2;
                  tk := timbf(tk, divbf(i2bf!: p2k, i2bf!: (p2k - 1)));
                  thisp := car tprimes;
                  tprimes := cdr tprimes >>;

            tprimes := cdr primes; thisp := car primes;
            while thisp <= k+1 do
               << if cdr divide (k2, thisp - 1) = 0 then
                     d2k := d2k * thisp;
                  thisp := car tprimes;
                  tprimes := cdr tprimes >>;
            if primep (k2 + 1) then d2k := d2k * (k2 + 1);

            n2k := timbf(timbf(rk, tk), i2bf!: d2k);
            if prernd then
               b2k := mk!*sq !*f2q mkround
                        divbf (i2bf!: (((-1)**(k+1)) *
                              nearest!-int!-to!-bf n2k),
                           i2bf!: d2k)
            else b2k := list ('!*sq, (((-1)**(k+1)) *
                           nearest!-int!-to!-bf n2k) . d2k, t);
            results := b2k . results >>;

      precision prepre;
      if not prernd then off rounded;
      return results;

   end;



%
% Procedure to compute B(2n). If it is called with rounded
% mode off, it computes the exact quotient; otherwise it
% will approximate (to the correct precision) whenever it
% saves time to do so.
%

symbolic procedure single!*bern(n);
   begin scalar result, primes, tprimes, rn, tn, n2n, pie;
      integer d2n, thisp, gn, prepre, prernd, p2n, n2, plim;

      prernd := !*rounded;
      if not prernd then on rounded;
      prepre := precision 0;

      if new!*bfs then
         << gn := 2 * n * msd!: n;
            if gn < (log2of10*!!nfpd) then precision (!!nfpd + 2)
            else if prepre > (gn/3) or not prernd then
                      precision (gn/3 + 1)
                 else precision (prepre + 2) >>
      else
         << gn := 2 * n * length explode n;
            if gn < !!nfpd then precision (!!nfpd + 2)
            else if prepre > gn or not prernd then
                     precision (gn + 1)
                 else precision (prepre + 2) >>;

      pie := divbf(bfone!*, timbf(pi!*(), e!*()));

      if n < 1786 then primes := !*primelist!*
      else
         << primes := nil;
            for thisp := 3573 step 2 until (2*n + 1) do
               if primep thisp then primes := thisp . primes;
            primes := append(!*primelist!*, reverse primes) >>;

      n2 := 2*n;
      rn := divbf(i2bf!: (2 * factorial n2),
         sq2bf!* algebraic ((2*pi)**(n2)));

      tn := bfone!*; d2n := 1;
      plim := 1 + conv!:bf2i timbf(i2bf!: n2, pie);

      tprimes := cdr primes; thisp := car primes;
      while thisp <= plim do
         << p2n := thisp ** n2;
            tn := timbf(tn, divbf(i2bf!: p2n, i2bf!: (p2n - 1)));
            thisp := car tprimes;
            tprimes := cdr tprimes >>;

      tprimes := cdr primes; thisp := car primes;
      while thisp <= n+1 do
         << if cdr divide (n2, thisp - 1) = 0 then
               d2n := d2n * thisp;
            thisp := car tprimes;
            tprimes := cdr tprimes >>;
      if primep (n2 + 1) then d2n := d2n * (n2 + 1);

      n2n := timbf(timbf(rn, tn), i2bf!: d2n);

      precision prepre;
      if prernd then
         result := mkround divbf(i2bf!: (((-1)**(n+1)) *
                     nearest!-int!-to!-bf n2n),
                  i2bf!: d2n)
      else
         << off rounded;
            result := list ('!*sq, (((-1)**(n+1)) *
               nearest!-int!-to!-bf n2n) . d2n, t) >>;

      return result;

    end;



% Euler numbers module by Kerry Gaskell

algebraic operator euler;

algebraic
 let {  euler(0)  => 1,
        euler(~n) => euler_aux(n) when fixp n and n > 0};

% A function to calculate the Euler numbers.

symbolic fluid '(euler_list);

euler_list := nil;

flag ('(euler_aux),'opfn);

symbolic procedure euler_aux(n);

begin scalar result;

   if n = 0
        then  result := 1

   else if not evenp(n)
        then result := 0        % If n is an odd number then its
                                % Euler number is zero.
   else if n = 2
        then result := -1

   else if n = 4
        then  result := 5

   else if (result := assoc(n,euler_list))
        then  result := cdr result

   else if remainder(n,4) neq 0
        then

        << result := - (for k:= 1:floor(n/4)
         sum ((euler_aux(n-2k) + euler_aux(n-(n-2k)))
                *algebraic(binomial(n,2k)))) -1;

   euler_list:= cons((n . result), euler_list) >>


   else

        << result :=  - (for k:= 1:n/4 - 1
         sum ((euler_aux(n-2k) + euler_aux(n-(n-2k)))
                *algebraic(binomial(n,2k))))
                - euler_aux(n/2)*algebraic(binomial(n,n/2)) -1;
        
   euler_list:= cons((n . result), euler_list) >>;

return result;
                end;

endmodule;


module sfgamma;   % Gamma function procedures and rules for REDUCE.

% Author: Chris Cannam, Sept/Oct '92

imports complex!*on!*switch, complex!*off!*switch,
   complex!*restore!*switch, sf!*eval;

exports do!*gamma, do!*pochhammer, do!*poch!*conj!*calc;



%
%   Rule set for the gamma function.
%

%
% Comments:
%
%   Base cases are provided for gamma(1) and gamma(1/2).
%   The rules will convert gammas to factorials where appropriate.
%   A numerical value is always computed if rounded mode is on.
%

algebraic operator gamma;
symbolic (operator do!*gamma);


algebraic (gamma!*rules := {

   gamma(~x)  =>  1 when numberp x and x = 1,
   gamma(~x)  =>  sqrt(pi) when numberp x and x = (1/2),

   gamma(~x)  =>  factorial (x-1)
      when numberp x and impart x = 0
         and x = floor x and x > 0,

   gamma(~x)  =>  infinity
      when numberp x and impart x = 0
         and x = floor x and x < 1,

   gamma(~x)  =>  gamma(x-1) * (x-1)
      when numberp x and not symbolic !*rounded
         and impart x = 0 and (64*x) = floor(64*x) and x > 1 and x < 50,

   gamma(~x)  =>  pi / (sin(pi*x) * gamma(-x) * (-x))
      when numberp x and x < 0,

   gamma(~x)  =>  do!*gamma(x)
      when numberp x
         and symbolic !*rounded,

   df(gamma(~x), x)  =>  gamma(x) * psi(x)

})$

algebraic (let gamma!*rules);


algebraic operator beta;

algebraic (beta!*rules := {

beta(~z,~w)  =>  (gamma(z) * gamma(w)) / gamma(z+w)
   when (numberp z and numberp w and impart z = 0 and impart w = 0
         and not ((z = floor z and z < 1)
               or (w = floor w and w < 1)
               or (z+w = floor (z+w) and (z+w) < 1)))
     or (numberp z and numberp w
         and (impart z neq 0 or impart w neq 0))
     or not (numberp z and numberp w),

beta(~z,~w)  =>  0
   when numberp z and numberp w and impart z = 0 and impart w = 0
      and not ((z = floor z and z < 1)
            or (w = floor w and w < 1))
      and (z+w = floor (z+w) and (z+w) < 1),

beta(~z,~w)  =>  infinity
   when numberp z and numberp w and impart z = 0 and impart w = 0
      and ((z = floor z and z < 1)
        or (w = floor w and w < 1))
      and not (z+w = floor (z+w) and (z+w) < 1)

})$

algebraic (let beta!*rules);



Comment Ruleset for calculating the Pochhammer symbol
        Author:  Wolfram Koepf, Freie Universitaet Berlin 1992,
        Translated to Reduce syntax by Winfried Neun, ZIB Berlin.
        Made generally safer (and uglier) by Chris Cannam, ZIB.
        ;


algebraic operator pochhammer;
symbolic (operator do!*pochhammer, do!*poch!*conj!*calc);

algebraic (pochhammer!*rules := {

pochhammer(~z,~k)  =>  1
   when numberp k and k = 0,

pochhammer(~z,~k -1)  =>
   2 * pochhammer(1/2,k) / (2*k -1)
      when numberp z and z = 1/2,

pochhammer(~a,~k)  =>
   factorial(2k)/((4^k) * factorial(k))
      when numberp a and a = 1/2,

pochhammer(~n,~k)  =>
   do!*pochhammer(n,k)
      when numberp n and numberp k
         and impart n = 0 and impart k = 0
            and n = floor n and k = floor k
               and n > -1 and k > 0,

pochhammer(~a,~k)  =>
   do!*pochhammer(a,k)
      when symbolic !*rounded
         and numberp k and numberp a
            and impart a = 0 and impart k = 0
               and ((a neq floor a) or (a > 0))
                  and k = floor k and k > 0,

pochhammer(~n,~k)  =>
   (-1)^k * factorial(-n) / factorial(-n-k)
      when numberp n and numberp k
         and impart n = 0
            and n = floor n and n < 1 and (-n-k) >= 0,

pochhammer(~a,~k)  =>
   pochhammer(2*a-1,2k)/((4^k) * pochhammer((2 a -1)/2,k))
      when numberp a and impart a = 0
         and (a+1/2) = floor (a+1/2) and a > 0});

algebraic (special!*pochhammer!*rules := {

        % these special rules are normally disabled because
        % they produce a lot of load for the algebraic mode

pochhammer(~a,~k)*pochhammer(~b,~k)  =>
   pochhammer(2a,2k)/(4^k)
      when (b-a)=1/2,

pochhammer(~a,~k)  =>
   (-1)^(-a+1/2) * pochhammer(1-a-(-a+1/2),-a+1/2) *
      pochhammer(a +(-a +1/2),k-(-a+1/2))
         when numberp a and impart a = 0
            and (a+1/2) = floor (a+1/2) and a<0,

pochhammer(~z,~k) * pochhammer(~cz,~k)  =>
   do!*poch!*conj!*calc(z,k)
      when numberp z and numberp cz and numberp k
         and not(impart z = 0) and z = conj cz
            and impart k = 0 and k = floor k and k >= 0,

pochhammer(~a,~k)*pochhammer(~aa,~k)  =>
   factorial(3 k)/(factorial(k) * 27^k)
      when numberp a and a = 1/3 and numberp aa and aa = 2/3,

pochhammer(~a,~k) * pochhammer(~aa,~k)  =>
   factorial(1 + 3 k)/(27 ^k * factorial(k))
      when numberp a and a = 2/3 and numberp aa and aa = 4/3,

pochhammer(~b,~k) * pochhammer(~c,~k)  =>
   pochhammer(3*b,3*k)/( 27^k * pochhammer(b +2/3,k))
      when numberp b and numberp c
         and (c-b)=1/3 and (b-1/3) = floor (b-1/3) and not (b-1/3 = 0),

pochhammer(~a,~k)*pochhammer(~aa,~k)*pochhammer(~aaa,~k)  =>
   factorial(4*k)/(factorial(k) * 64^k)
      when numberp a and numberp aa and numberp aaa
         and a = 1/4 and aa = 1/2 and aaa = 3/4,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   factorial(5*k)/(factorial(k) * 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 1/5 and aa = 2/5 and aaa = 3/5 and aaaa = 4/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   5*(1/5 +k)*factorial(5*k)/(factorial(k) * 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 2/5 and aa = 3/5 and aaa = 4/5 and aaaa = 6/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (25 *(1/5+k)*(2/5 +k)*factorial(5*k)) / (factorial(k) * 2* 3125^k)
      when numberp a and numberp aa
         and numberp aaa and numberp aaaa
            and a = 3/5 and aa = 4/5 and aaa = 6/5 and aaaa = 7/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (125*(1/5+k)*(2/5+k)*(3/5+k)*factorial(5*k)) /
      (factorial(k) * 6 *3125^k)
         when numberp a and numberp aa
            and numberp aaa and numberp aaaa
               and a = 4/5 and aa = 6/5 and aaa = 7/5 and aaaa = 8/5,

pochhammer(~a,~k)*pochhammer(~aa,~k)*
      pochhammer(~aaa,~k)*pochhammer(~aaaa,~k)  =>
   (625*(1/5+k)*(2/5+k)*(3/5+k)*(4/5+k)*factorial(5*k)) /
      (factorial(k) * 24 *3125^k)
         when numberp a and numberp aa
            and numberp aaa and numberp aaaa
               and a = 6/5 and aa = 7/5 and aaa = 8/5 and aaaa = 9/5

%
%Pochhammer(~a,~k)//Pochhammer(~b,~k)  =>
%   (a + k -1)/(a - 1)
%      when (a - b)=1,
%
%Pochhammer(~a,~k)//Pochhammer(~b,~k)  =>
%   (b - 1)/(b + k -1)
%      when (b - a)=1,
%

})$

algebraic (let pochhammer!*rules);



algebraic procedure do!*gamma(z);
   (if impart z = 0
    then algebraic sf!*eval('gamma!*calc!*s,{z})
    else algebraic sf!*eval('gamma!*calc,{z}));



algebraic procedure gamma!*calc!*s(z);
   begin scalar scale, result, alglist!*;
      integer p, precom;
      precom := complex!*off!*switch();
      p := precision(0);
      op := lisp c!:prec!:();
      if p < !!nfpd then precision (!!nfpd + 1);
%      else precision(p+3);
      if p > 49 then
         scale := 500 + p
      else scale := 10 * (p+1);
      if z > scale then scale := 2;
      result := gamma!*calc!*s!*sub(z,scale,op);
      precision p;
      complex!*restore!*switch(precom);
      return result;
   end;



algebraic procedure gamma!*calc!*s!*sub(z,scale,op);
   begin scalar za, z1, result; integer z0;
      za := z; z0 := floor (z+1); z1 := z + scale;
      result := algebraic symbolic log!*gamma(z1,z0);
      result := (exp result / pochhammer(z,scale));
      return result;
   end;



symbolic procedure log!*gamma(z, zint);
   begin scalar result, this, zpwr, zsq, admissable, abk;
      integer k, adep, famt, rp, orda, magn;

      magn := bf!*base ** c!:prec!:();

      if zint < 1000 then
         if new!*bfs
         then admissable := divbf
                  (i2bf!: msd!: (1 + (factorial zint / 3)),
                   i2bf!: magn)
         else admissable := divbf
                  (i2bf!: length explode factorial zint,
                   i2bf!: magn)
      else
         admissable := divbf
               (difbf(log!:(timbf(plubf(bftwo!*,bfhalf!*),
                     sqrt!:(exptbf(i2bf!: zint,2*zint+1,bfone!*),8)),8),
                  i2bf!: zint),i2bf!: magn);

      z := sq2bf!* z;
      result := timbf(log!* z, difference!:(z, bfhalf!*));
      result := plubf((difference!: (result, z)), timbf(bfhalf!*,
         log!* timbf(pi!*(), bftwo!*)));
      this := plubf (admissable, bfone!*);
      rp := c!:prec!:(); orda := order!: admissable - 5;
      k := 2; zpwr := z; zsq := timbf (z, z);

      while greaterp!:(abs!: this, admissable) do
         << abk := retag cdr !*a2f retrieve!*bern k;
            this := divide!: (abk,
               timbf (i2bf!: (k * (k-1)), zpwr), rp);
            rp := order!: this - orda;
            result := plubf(result, this);
            zpwr := timbf (zpwr, zsq);
            k := k + 2; >>;

      return mk!*sq !*f2q mkround result;
   end;




%
% algebraic procedure loggamma!*calc!*sub(z);
%
% Procedure to calculate ln(gamma(z)); returns a 2-list of
%   the value of ln(gamma) and the final term used in the
%   constructing series. (This term is used by gamma!*calc!*sub
%   to compute the error.)
%
% Also requires to be fed the indices for the first and last
%     terms to be used in constructing the portion of the
%     series that it will construct.  Both of these values should
%     be even; if the first term's index is 2, then the initial
%     terms to construct the log gamma will also be included.
%

algebraic procedure loggamma!*calc!*sub(z, premier, dernier);
   begin scalar result, ft, sofar, div;
      if premier = 2 then result := ((z - (1/2)) * log z) - z +
         ((1/2) * log (2*pi))
      else result := 0;
      sofar := z ** (dernier-1);
      div := z ** 2;
      result := result + (ft := (bernoulli!*calc(dernier) /
         ((dernier -1) * dernier * sofar)));
      for n := (dernier-2) step -2 until premier
         do << sofar := sofar / div;
               result := result + (bernoulli!*calc(n) /
                  (n * (n-1) * sofar)) >>;
      return { result, ft };
   end;



%
% algebraic procedure gamma!*calc!*sub(z,scale);
%
% Procedure to calculate values of gamma. Given the value
%   at which to calculate and the amount by which to scale
%   up in calculation, returns (eventually) a 2-list of the value
%   of gamma and the maximum error on this value. Needs a
%   better interface -- see the gamma!*calc procedure, below.
%

algebraic procedure gamma!*calc!*sub(z,scale);
   begin scalar result, expresult, ft, err, newerr, rescale,
         admissable, alglist!*;
      integer prepre, premier, dernier;
      prepre := precision(0);
%      precision (prepre + 4);
      rescale := for k := 1:scale product (z+k-1);
      admissable := 1 / (10 ** (prepre + 4));
      err := admissable + 1;
      premier := 2;
      dernier := 50;
      result := 0;
      while (err > admissable) do
         << ft := loggamma!*calc!*sub(z+scale, premier, dernier);
            result := result + first ft;
            ft := second ft;
            expresult := exp result;
            newerr := (abs ((expresult/(exp ft)) - expresult))/rescale;
            if newerr > err or (dernier > 180 and
                     newerr > (admissable * 1000)) then
               << scale := scale * 3;
                  rescale := (for m := 1:scale product (z+m-1));
                  write ("Scaling up to scale=", scale,
                           " (from ", scale/3, ")");
                  result := 0;
                  premier := 2;
                  dernier := 100;
                  err := admissable + 1 >>
               else
               << err := newerr;
                  premier := dernier + 2;
                  dernier := dernier + 30 >> ;
         >>;
      result := expresult / rescale;
%      precision prepre;
      return { result, err };
   end;



%
% algebraic procedure gamma!*calc(z);
%
% Procedure to calculate values of gamma to (one hopes)
%   an error within the tolerance allowed by the current
%   precision. Calls gamma!*calc!*sub (above) with a scale worked
%   out by slightly ad-hoc (but apparently fairly good) methods
%   and will be generally OK for z between 1e-7 and infinity.
%
% Only works for positive z, and only in rounded mode.
%

algebraic procedure gamma!*calc(z);
   if precision(0) > 49
     then first gamma!*calc!*sub(z,500+4*precision(0))
    else first gamma!*calc!*sub(z, ceiling (exp(precision(0)/10) * 2));





%
% Functions to compute Pochhammer(a,k).
%


algebraic procedure do!*pochhammer(a,k);
   algebraic sf!*eval('pochhammer!*calc,{a,k});

algebraic procedure do!*poch!*conj!*calc(z,n);
   algebraic sf!*eval('poch!*conj!*calc,{z,n});


algebraic procedure pochhammer!*calc(a,k);
   (if fixp a and not symbolic !*rounded
   then (symbolic fac!-part(a, a+k-1))
   else pochhammer!*calc!*sub(a,k));


algebraic procedure pochhammer!*calc!*sub(a,k);
   begin scalar result, prepre, precom, a0;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd then precision (1+!!nfpd);
      a0 := a;
      result := if (symbolic new!*bfs)
         then algebraic symbolic pochhammer!*calc!*sub!*sub!*newbf(a,k)
         else algebraic symbolic pochhammer!*calc!*sub!*sub!*oldbf(a,k);
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;


symbolic procedure pochhammer!*calc!*sub!*sub!*oldbf(a,k);
   begin scalar result;
      if fixp a
       then result := poch!*sub!*2(0, k-1, i2bf!: a)
       else << a := sq2bf!* a;
               if order!: a < - !:prec!:
                  then result := poch!*sub!*2(0, k-1, bfone!*)
                  else if length explode mt!: a < !:prec!:/2
                              and order!: a > -2
                          then result := poch!*sub!*2(0, k-1, a)
                          else result := poch!*sub!*1(a, k-1,bfone!*)>>;
      return mk!*sq !*f2q mkround result;
   end;


symbolic procedure pochhammer!*calc!*sub!*sub!*newbf(a,k);
   begin scalar result;
      if fixp a
       then result := poch!*sub!*2(0, k-1, i2bf!: a)
       else << a := sq2bf!* a;
               if order!: a < - c!:prec!:()
                  then result := poch!*sub!*2(0, k-1, bfone!*)
                  else if preci!: a < c!:prec!:()/2 and order!: a>-2
                         then result := poch!*sub!*2(0, k-1, a)
                        else result := poch!*sub!*1(a,k-1,bfone!*)>>;
      return mk!*sq !*f2q result;
   end;


symbolic procedure poch!*sub!*1(a,k,tot);
   if k=0 then timbf(tot,a)
   else poch!*sub!*1(plus!:(a,bfone!*),k-1,timbf(tot,a));


symbolic procedure poch!*sub!*2(m,n,a);
   if m=n then plus!:(a,i2bf!: m)
   else if m = n-1 then
      timbf(plus!:(a,i2bf!: m), plus!:(a,i2bf!: n))
   else (timbf(poch!*sub!*2(m,p,a),poch!*sub!*2(p+1,n,a)))
      where p=(m+n)/2;


algebraic procedure poch!*conj!*calc(z,n);
   for i := 1:n product ((repart z + (i-1))**2 + (impart z)**2);


endmodule;


module sfpsi; % Procedures relevant to the digamma, polygamma & zeta
              % functions.

% Author: Chris Cannam, Sept/Oct '92.

% Added: PSI_SIMP.RED  F.J.Wright, 2 July 1993
%        The polygamma rules are addded by Y.K. Man on 9 July 1993

%        Yiu K. Man's email is: myk@maths.qmw.ac.uk

imports sq2bf!*, sf!*eval;
exports do!*psi, do!*polygamma, do!*trigamma!*halves,
   do!*zeta, do!*zeta!*pos!*intcalc;


%
% A couple of global values are used (from specfns.red) which can speed
% up psi calculations (a bit) when repeated calculations are made at the
% same level of precision.


%
% Here's an approximation sufficiently good for most purposes
%   (assuming it's right, that is); if it isn't good enough, it
%   won't be used.  This approximation is to 506 dec. places.
%

algebraic (old!*precision := precision(0));
precision 510;
algebraic procedure get!-eulers!-constant(a);
<<
a := 577215664901532860606512090082402431 * 10^40 +
                 0421593359399235988057672348848677267776;
a := a * 10^40 + 6467093694706329174674951463144724980708;
a := a * 10^40 + 2480960504014486542836224173997644923536;
a := a * 10^40 + 2535003337429373377376739427925952582470;
a := a * 10^40 + 9491600873520394816567085323315177661152;
a := a * 10^40 + 8621199501507984793745085705740029921354;
a := a * 10^40 + 7861466940296043254215190587755352673313;
a := a * 10^40 + 9925401296742051375413954911168510280798;
a := a * 10^40 + 4234877587205038431093997361372553060889;
a := a * 10^40 + 3312676001724795378367592713515772261027;
a := a * 10^40 + 3492913940798430103417771778088154957066;
a := a * 10^30 + 107501016191663340152278935868;
a := a * (10**(-506)) >>;
algebraic (euler!*constant := get!-eulers!-constant(0));

algebraic precision old!*precision;
algebraic clear old!*precision;




%
% Define some suitable rules for initial simplification of psi
%   (digamma) function expressions.
%
% Comments:
%
%  When rounded mode is on, psi(number) is always computed
%     directly unless it simplifies to an expression in psi(1/2) or
%     psi(1), in which case it is simplified. Expressions in psi(1/2)
%     and psi(1) are expanded into expressions in euler!*constant.
%     If, however, the precision is greater than 500, then
%     euler!*constant is not stored sufficiently precisely, and all
%     such expressions will be computed without simplification.
%
% When rounded mode is off, psi(number) will _never_ be expanded
%     into an expression involving euler!*constant, but will always
%     be expanded into some form involving psi(p), where 0<p<1.
%     It should be borne in mind that computations which will need
%     numerical results could do without such expansion, and there-
%     fore such computations should be performed in rounded mode
%     as soon as possible.
%
% Expressions for the derivative and integral of psi are included.
%

algebraic operator psi, polygamma;
symbolic operator psi!*calc;

algebraic (psi!*rules := {

   psi(~x,~xx) => polygamma(x,xx),

   psi(~z)  =>  infinity
      when repart z = floor repart z and impart z = 0 and z < 1,

   psi(~z)  =>  -euler!*constant
      when numberp z and z = 1
         and symbolic !*rounded and precision(0) < 501,

   psi(~z)  =>  -euler!*constant - 2 * log(2)
      when numberp z and z = (1/2)
         and symbolic !*rounded and precision(0) < 501,

   psi(~z)  =>  do!*psi(z)
      when numberp z and impart z = 0 and symbolic !*rounded,

   psi(~z)  =>  (psi(z/2) + psi((z+1)/2) + 2 * log(2)) / 2
      when numberp z and impart z = 0
         and (z/2) = floor (z/2)
            and z > 0 and not symbolic !*rounded,

   psi(~z)  =>  psi(z-1) + (1 / (z-1))
      when numberp z and impart z = 0
         and z > 1 and not symbolic !*rounded,

   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
      when numberp z and impart z = 0
         and z < 0 and not symbolic !*rounded,

   df(psi(~z),z)  =>  polygamma(1, z),

   int(psi(~z),z)  =>  log gamma(~z)

})$

algebraic (let psi!*rules);


% PSI_SIMP.RED  F.J.Wright, 2 July 1993
% The polygamma rules are addded by Y.K. Man on 9 July 1993

% Support for the psi operator.
% =============================
% psi(x) = df(log Gamma(x), x) as in specfn package, etc.
% The specfn package does not currently provide the required
% simplifications.

algebraic;

% Simplify to "standard form" in which argument is allowed a numeric 
% shift in the range 0 <= shift < 1:

psi_rules := {
   % Rule for integer shifts (x + 3), and non-integer shifts (x + 3/2)in
   % a non-integer number domain (on rational) or with "on intstr, div":
   psi(~x+~n) => psi(x+n-1) + 1/(x+n-1) when numberp n and n >= 1,
   psi(~x+~n) => psi(x+n+1) - 1/(x+n) when numberp n and n < 0,
   polygamma(~m,~x+~n) => polygamma(m,x+n-1)+(-1)^m*factorial(m)
        /(x+n-1)^(m+1) when numberp n and fixp m and n >= 1,
   polygamma(~m,~x+~n) => polygamma(m,x+n+1)-(-1)^(m)*factorial(m)
        /(x+n)^(m+1) when numberp n and fixp m and n < 0,
   % Rule for rational shifts (x + 3/2) in the default (integer) number
   % domain and rational arguments (x/y + 3):
   psi((~x+~n)/~d) => psi((x+n-d)/d) + d/(x+n-d) when
      numberp(n/d) and n/d >= 1,
   psi((~x+~n)/~d) => psi((x+n+d)/d) - d/(x+n) when
      numberp(n/d) and n/d < 0,
   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n-d)/d) +
      (-1)^m*factorial(m)*d^(m+1)/(x+n-d)^(m+1) when
      fixp m and numberp(n/d) and n/d >= 1,
   polygamma(~m,(~x+~n)/~d) => polygamma(m,(x+n+d)/d) -
      (-1)^m*factorial(m)*d^(m+1)/(x+n)^(m+1) when
      fixp m and numberp(n/d) and n/d < 0
};

% NOTE: The rational-shift rule does not work with "on intstr, div".

let psi_rules;

symbolic;

%
% Rules for initial manipulation of polygamma functions.
%

symbolic (operator polygamma!*calc, trigamma!*halves, printerr,
        polygamma_aux);


symbolic procedure printerr(x); rederr x;

algebraic procedure polygamma_aux(n,m);
        for ii:=1:(n-1) sum (1/ii**(m+1));

algebraic (polygamma!*rules := {

   polygamma(~n,~x)  =>  printerr
                 "Index of Polygamma must be an integer >= 0"
        when numberp n and (not fixp n or n < -1),

   polygamma(~n,~x)  =>  psi(x)
      when numberp n and n = 0,

   polygamma(~n,~x)  =>  infinity
      when numberp x and impart x = 0 and x = floor x and x < 1,

   polygamma(~n,~x)  =>  do!*trigamma!*halves(x)
      when numberp n and n = 1 and numberp x and impart x = 0
         and (not (x = floor x) and ((2*x) = floor (2*x))) and x > 1,

   polygamma(~n,~x)  =>  ((-1) ** (n)) * (factorial n) * (- zeta(n+1) +
                         polygamma_aux(x,n))
      when fixp x and x >= 1 and not symbolic !*rounded,

   polygamma(~n,~x)  => ((-1)**n) * factorial n * (-2 * (2**n) *
         zeta(n+1) + 2 * (2**n) + zeta(n+1))
      when numberp x and x = (3/2) and not symbolic !*rounded,

   polygamma(~n,~x)  =>  do!*polygamma(n,x)
      when numberp x and symbolic !*rounded
         and numberp n and impart n = 0 and n = floor n,

   df(polygamma(~n,~x), ~x)  =>  polygamma(n+1, x),

   int(polygamma(~n,~x),~x)  =>  polygamma(n-1,x)

})$

algebraic (let polygamma!*rules);



%
% Set up rules for the initial manipulation of zeta.
%
% Comments:
%
%     Zeta of positive even numbers and negative odd numbers
%     is evaluated (in terms of pi) always when its argument
%     has magnitude less than 31, and only in rounded mode
%     otherwise.  (This is because the coefficients get a bit
%     big when the argument is over about 30.)
%

algebraic operator zeta;
symbolic (operator zeta!*calc, zeta!*pos!*intcalc);


algebraic (zeta!*rules := {

   zeta(~x)  =>  (- (1/2))
      when numberp x and x = 0,

   zeta(~x)  =>  (pi ** 2) / 6
      when numberp x and x = 2,

   zeta(~x)  =>  (pi ** 4) / 90
      when numberp x and x = 4,

   zeta(~x)  =>  infinity
      when numberp x and x = 1,

   zeta(~x)  =>  0
      when numberp x and impart x = 0 and x < 0 and (x/2) = floor(x/2),

   zeta(~x)  =>  ((2*pi)**x) / (2*factorial x)*(abs bernoulli!*calc x)
      when numberp x and impart x = 0 and x > 0
         and (x/2) = floor (x/2) and x < 31,

   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (2*x)
      when numberp x and impart x = 0 and x < 0
         and x = floor x and x > -31,

   zeta(~x)  =>  ((2*pi)**x)/(2 * factorial x)*(abs bernoulli!*calc x)
      when numberp x and impart x = 0 and x > 0
         and (x/2) = floor(x/2) and x < 201 and symbolic !*rounded,

   zeta(~x)  =>  - (bernoulli!*calc (1-x)) / (1-x)
      when numberp x and impart x = 0 and x < 0
         and x = floor x and x > -201 and symbolic !*rounded,

   zeta(~x)  =>  (2**x)*(pi**(x-1))*sin(pi*x/2)*gamma(1-x)*zeta(1-x)
      when numberp x and impart x = 0 and x < 0
         and (x neq floor x or x < -200) and symbolic !*rounded,

   zeta(~x)  =>  do!*zeta!*pos!*intcalc(fix x)
      when symbolic !*rounded and numberp x and impart(x) = 0 and x > 1
         and x = floor x and (x <= 15 or precision 0 > 100
            or 2*x < precision 0),

   zeta(~x)  =>  do!*zeta(x)
      when numberp x and impart x = 0% and x > 1
         and symbolic !*rounded,

   df(zeta(~x),x)  =>  -(1/2)*log(2*pi)
      when numberp x and x = 0

})$

algebraic (let zeta!*rules);



algebraic procedure do!*psi(z);
   algebraic sf!*eval('psi!*calc,{z});

algebraic procedure do!*polygamma(n,z);
   algebraic sf!*eval('polygamma!*calc,{n,z});

algebraic procedure do!*trigamma!*halves(z);
   algebraic sf!*eval('trigamma!*halves,{z});

algebraic procedure do!*zeta(z);
   (if z <= 1.5 and precision(0) <= floor(4+3*z)
    then raw!*zeta(z)
    else if (3*z) > (10*precision(0)) then 1.0
    else if z > 100 then algebraic sf!*eval('zeta!*calc,{z})
    else algebraic sf!*eval('zeta!*general!*calc,{z}));

algebraic procedure do!*zeta!*pos!*intcalc(z);
   algebraic sf!*eval('zeta!*pos!*intcalc,{z});



%
% algebraic procedure psi!*calc(z);
%
%     Compute a value of psi. Works by first computing the
%     smallest positive integral x at which psi(x) is easily
%     computable to the current precision using no more
%     than the first 200 bernoulli numbers, then scaling up
%     the given argument (if necessary) so that it can be
%     computed, scaling down again afterwards.
%
%     Does not work for complex arguments.
%


algebraic procedure psi!*calc(z);
   begin scalar result, admissable, bern300, alglist!*, precom;
      integer prepre, scale, lowest;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd then precision (!!nfpd + 1);
      admissable := (1 / (10 ** prepre)) / 2;
      if prepre = psi!*ld(0) then lowest := psi!*ld(1)
      else
         << bern300 := abs bernoulli!*calc 300;
            lowest := 1 +
               symbolic conv!:bf2i exp!:
                  (divbf(log!:(divbf(sq2bf!* bern300,
                        timbf(i2bf!: 150,
                           sq2bf!* admissable)), 4),
                     i2bf!: 300), 3);  % Use symbolic mode so as to
                                    % force less accuracy for more speed
            psi!*ld(0) := prepre;
            psi!*ld(1) := lowest >> ;
      if lowest>repart z then scale := ceiling(lowest - repart z) + 20;
      z := z + scale;
      result := algebraic symbolic psi!*calc!*sub(z, scale, admissable);

      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;


symbolic procedure psi!*calc!*sub(z, scale, admissable);
   begin scalar result, zsq, zsqp, this, bk;
      integer k, orda, rp; k := 2;
      z := sq2bf!* z;
      admissable := sq2bf!* admissable;
      zsq := timbf(z,z); zsqp := zsq;
      this := plubf(admissable, bfone!*);
      result := difbf (log!: (z,c!:prec!:()),
         divbf(bfone!*, timbf(bftwo!*, z)));
      orda := order!: admissable - 5; rp := c!:prec!:();
      while greaterp!: (abs!: this, admissable) do
         << bk := sq2bf!* symbolic algebraic bernoulli!*calc k;
            this := divide!:(bk, timbf(i2bf!: k, zsqp), rp);
            result := difbf(result, this);
            k := k + 2; rp := order!: this - orda;
            zsqp := timbf(zsqp, zsq) >>;
      for n := 1:scale do
         result := difbf(result, divbf(bfone!*, difbf(z, i2bf!: n)));
      return mk!*sq !*f2q mkround result;
   end;




%
% algebraic procedure polygamma!*aux(n,z);
%
%     Used by the procedure below, to implement the Reflection
%     Formula. This obtains an expression for
%            n
%           d
%           --- ( cot  ( pi * x ) )
%             n
%           dx
%     and substitutes z for x into it, returning the result.
%

algebraic procedure polygamma!*aux(n,z);
   begin scalar poly;
      clear dummy!*arg;
      poly := cot(pi * dummy!*arg);
      for k := 1:n do poly := df(poly, dummy!*arg);
      dummy!*arg := z;
      return poly;
   end;



%
% algebraic procedure polygamma!*calc(n,z);
%
%     Computes a value of the polygamma function, order n,
%     at z.  N must be an integer, and z must be real.  If
%     z is negative, the Reflection Formula is applied by
%     a call to polygamma!*aux (above); then the positive
%     argument is fed to polygamma!*calc!*s which does the
%     real work.
%

algebraic procedure polygamma!*calc(n,z);
   begin scalar result, z0, prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd then precision (!!nfpd + 3)
      else precision (prepre + 3 + floor(prepre/50));
      if z > 0 then
         << z0 := z;
            result := algebraic symbolic polygamma!*calc!*s(n,z0) >>
      else
         << z0 := 1-z;
            result := ((-1)**n)*(pi*polygamma!*aux(n,z0) +
               algebraic symbolic polygamma!*calc!*s(n,z0)) >>;
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;




%
% symbolic procedure polygamma!*calc!*s(n,z);
%
%     Implementation of an asymptotic series for the poly-
%     gamma functions.  Computes a scale factor which should
%     (hopefully) provide a minimum argument for which this
%     series is valid at the given order and precision; then
%     computes the series for that argument and scales down
%     again using the Recurrence Formula.
%

symbolic procedure polygamma!*calc!*s(n,z);
   begin scalar result, this, admissable, partial,
         zexp, zexp1, zsq, nfac, nfac1, kfac, rescale, signer, z0;
      integer k, nm1, nm2, rp, orda, min, scale;

      z := sq2bf!* z; signer := i2bf!:((-1)**(n-1));
      admissable := divide!:(bfone!*,i2bf!:(bf!*base**c!:prec!:()),8);

      min := 10 + conv!:bf2i
              exp!:(times!:(divide!:(bfone!*,i2bf!:(300+n),8),
              log!:(divide!:(timbf(round!:mt(i2bf!: factorial(300+n),8),
                  abs!: sq2bf!* symbolic algebraic bernoulli 300),
                times!:(admissable,round!:mt(i2bf!: factorial 300,8)),
                  8),8)),8);     % In which Chris approximates to 8 bits
                                 % and hopes to get away with it...
      scale := min - (1 + conv!:bf2i z);
      if scale < 0 then scale := 0;
      z0 := plubf(z,i2bf!: scale);

      nfac := round!:mt(i2bf!: factorial(n-1),c!:prec!:());
      zexp := texpt!:any(z0,n);
      result := plubf(divbf(nfac,zexp),
         divbf((nfac1 := timbf(i2bf!: n,nfac)),
            timbf(bftwo!*,(zexp1 := timbf(zexp,z0)))));
      nfac := nfac1; zexp := zexp1;

      nm1 := n-1; nm2 := n-2; rp := c!:prec!:();
      nfac := timbf(nfac, i2bf!: (n+1));
      kfac := bftwo!*; zexp := timbf(zexp,z0);
      zsq := timbf(z0,z0);

      partial := divbf(nfac,timbf(kfac,zexp));
      k := 2; orda := order!: admissable - 5;
      this := bfone!*;

      while greaterp!:(abs!: this, admissable) do
         << result := plubf(result,
               (this := timbf(sq2bf!* retrieve!*bern k,partial)));
            k := k + 2;
            partial := divide!:(timbf(partial,i2bf!:((nm2+k)*(nm1+k))),
               timbf(zsq,i2bf!:((k-1)*k)),rp);
            rp := order!: this - orda >>;

      result := times!:(signer,result);

      if scale neq 0 then
         << rescale := bfz!*;
            nfac := round!:mt(i2bf!: factorial n,c!:prec!:());
            for k := 1:scale do
               <<rescale := plus!:(rescale,timbf(nfac,texpt!:(z,-n-1)));
                  z := plubf(z,bfone!*) >>;
            result := plubf(result,times!:(signer,rescale)) >>;

      return mk!*sq !*f2q mkround result;
   end;




%
% algebraic procedure trigamma!*halves(x);
%
%     Applies a formula to derive the exact value of the trigamma
%     function at x where x = n+(1/2) for n = 1, 2, ...
%

algebraic procedure trigamma!*halves(x);
   begin integer prepre; scalar result, alglist!*;
      result := (1/2) * (pi ** 2) - (4 * (for k := 1:(round (x-(1/2)))
         sum ((2*k - 1) ** (-2))));
      return result;
   end;




%
% algebraic procedure zeta!*calc(s);
%
%     Calculate zeta(s). Only valid for repart(s) > 1.
%
%     This function uses the system !*primelist!* of the first
%     500 primes.  If the system variable disappears or changes,
%     this function is helpless.
%

algebraic procedure zeta!*calc(z);
   begin scalar result, admissable, primelist,
         partialpl, this, modify, spl, alglist!*;
      integer prepre, j, rflag, thisprime, nexti;
      share spl;
      prepre := precision(0);
      precision prepre + 3;
      admissable := (1 / (10 ** (prepre + 2)));

      symbolic (spl := !*primelist!*);
      primelist := {};
      result := 1; modify := 1;
      for k := 1:10 do
         << j := symbolic car spl;
            symbolic (spl := cdr spl);
            primelist := (j . primelist);
            modify := modify * (1 - (1 / (j**z))) >>;
      modify := 1 / modify;

      this := admissable + 1;
      if not symbolic cdr divide (j, 3) then j := j + 2;
      nexti := (if not symbolic cdr divide (j+1, 3) then 2 else 4);
      while ((abs this) > admissable) do
         << rflag := 1; partialpl := primelist;
            while ((partialpl neq {}) and rflag) do
               << thisprime := first partialpl;
                  rflag := symbolic cdr divide(j, thisprime);
                  partialpl := rest partialpl >>;
            if rflag then result := result + (this := (1 / (j**z)));
            j := j + nexti; nexti := 6 - nexti >>;
      result := result * modify;
      precision prepre;
      return result;
   end;


algebraic procedure zeta!*pos!*intcalc(m);
   (((-1)**m)*polygamma(m-1,3)/factorial(m-1)
      + 1 + (1/(2**m)));


algebraic procedure zeta!*error(z,terms);
   (((-1) ** (terms+2)) / ((terms+1) ** z));


algebraic procedure zeta!*general!*calc(z);
   begin scalar result, zp, admissable, z0;
         integer pre, k;
      pre := precision(0);
      admissable := algebraic symbolic
         (mk!*sq !*f2q mkround divide!:(bfone!*,i2bf!:(10 ** pre),8));
      if (z**2) < admissable
      then result := ((-1/2) - ((log(2*pi))*z)/2)
      else if pre < !!nfpd
           then begin scalar sstt, stt;
                   sstt := (for k := 2:(pre-1) sum (k**(-z)));
                   precision (!!nfpd + 2);
                   z0 := z; zp := pre**(-z); stt := sstt + 1;
                   result := algebraic symbolic
                     zeta!*general!*calc!*sub(z0,zp,admissable,pre,stt);
                end
           else <<z0 := z; zp := pre**(-z);
                  result := algebraic symbolic
                   zeta!*general!*calc!*sub(z0,zp,admissable,pre,'())>>;
      precision pre;
      return result;
   end;


symbolic procedure zeta!*general!*calc!*sub(z,zp,admissable,pre,stt);
   begin scalar result, prere, this, fac, pre, zk1, zk2, logz;
         integer k;

      z := sq2bf!* z;
      zp := sq2bf!* zp;
      admissable := sq2bf!* admissable;

      if stt = nil then
         << result := bfone!*; k := 1;
            this := plus!:(admissable,bfone!*);
            while greaterp!: (abs!: this,admissable) and k < pre-1 do
               << k := k + 1;
                  this := texpt!:any(i2bf!: k, minus!: z);
                  result := plubf(result, this) >> >>
      else result := sq2bf!* stt;

      pre := i2bf!: pre;
      zk1 := plubf(z,bftwo!*); zk2 := plubf(z,bfone!*);
      result := plubf(result,
         timbf(zp,plubf(bfhalf!*,divbf(pre,difbf(z,bfone!*)))));
      fac := divbf(bfone!*,timbf(pre,pre));
      this := timbf(divbf(z,bftwo!*),divbf(zp,pre));
      result := plubf(result,divbf(this,i2bf!: 6));
      k := 4; prere := plubf(result,bfone!*);

      while greaterp!: (abs!: difbf(prere,result), admissable) do
         << this := divbf(timbf(this,timbf(fac,timbf(zk1,zk2))),
                          i2bf!:(k*(k-1)));
            prere := result;
            result := plubf(result,timbf(
               sq2bf!* symbolic algebraic bernoulli!*calc k, this));
            zk1 := plus!:(zk1,bftwo!*);
            zk2 := plus!:(zk2,bftwo!*);
            k := k + 2; >>;

      return mk!*sq !*f2q mkround result;
   end;


stieltjes (0) := 0.577215664901532860606512$ % Euler's constant
stieltjes (1) := -0.0728158233766$
stieltjes (2) := -0.00968992187973$
stieltjes (3) := 0.00206262773281$
stieltjes (4) := 0.00250054826029$
stieltjes (5) := 0.00427794456482$
stf (0) := 1$
stf (1) := 1$
stf (2) := 2$
stf (3) := 6$
stf (4) := 24$
stf (5) := 120$

algebraic procedure raw!*zeta(z);
   << z := z-1;
      1/z + (for m := 0:5 sum ((-1)**m * stieltjes(m) * z**m / stf(m)))
   >>;

endmodule;


module sfbes;  % Procedures and Rules for the Bessel functions.

% Author: Chris Cannam, October 1992.
%
% Firstly, procedures to compute values of the Bessel functions by
% direct bigfloat manipulation; also procedures for large arguments,
% using an asymptotic formula.

% These are specific to the Schoepf/Beckingham binary bigfloats, though
% easily adapted, and they should only be used with n and z both
% numeric, real and non-negative.

% Then follow procedures written in algebraic mode and used for certain
% special cases such as complex arguments.  Anybody who wishes to create
% symbolic mode complex-rounded versions is welcome to do so, with my
% blessing.

% No functions are provided to compute bessel K, though for special
% cases the ruleset handles it.


imports complex!*on!*switch, complex!*off!*switch,
   complex!*restore!*switch, sq2bf!*, sf!*eval;


% This module exports no functions.  I want to keep it available only
% through the algebraic operators, largely because the functions are
% quite a complicated lot.  If you want to use it from symbolic mode,
% use a wrapper and use the algebraic operators- it's slower, but at
% least that way you'll get the answers.

global '(logten);

algebraic operator besselj, bessely, besseli, besselk, hankel1, hankel2;

symbolic operator do!*j, do!*y, do!*i;

algebraic (bessel!*rules := {

besselj(~n,~z)  =>  0
   when numberp z and z = 0
      and numberp n and n neq 0,

bessely(~n,~z)  =>  infinity
   when numberp z and z = 0,

besselj(~n,~z)  =>  sqrt(2/(pi*z)) * sin(z)
   when numberp n and n = 1/2,

bessely(~n,~z)  =>  sqrt(2/(pi*z)) * cos(z)
   when numberp n and n = 1/2,


% J and Y for negative values and indices.

besselj(~n,~z)  =>  ((-1)**n) * besselj(-n,z)
   when numberp n and impart n = 0
      and n = floor n and n < 0,

besselj(~n,~z)  =>  ((-1)**n) * besselj(n,-z)
   when numberp n and impart n = 0 and n = floor n
      and numberp z and repart z < 0,

bessely(~n,~z)  =>  ((-1)**n) * bessely(-n,z)
   when numberp n and impart n = 0
      and n = floor n and n < 0,

bessely(~n,~z)  =>  ((besselj(n,z)*cos(n*pi))-(besselj(-n,z)))/sin(n*pi)
   when not symbolic !*rounded
      and numberp n
         and (impart n neq 0 or not (repart n = floor repart n)),


% Hankel functions.

hankel1(~n,~z)  =>  sqrt(2/(pi*z)) * (exp(i*z)/i)
   when symbolic !*complex and numberp n and n = 1/2,

hankel2(~n,~z)  =>  sqrt(2/(pi*z)) * (exp(-i*z)/(-i))
   when symbolic !*complex and numberp n and n = 1/2,

hankel1(~n,~z)  =>  besselj(n,z) + i * bessely(n,z)
   when symbolic !*complex and not symbolic !*rounded,

hankel2(~n,~z)  =>  besselj(n,z) - i * bessely(n,z)
   when symbolic !*complex and not symbolic !*rounded,


% Modified Bessel functions I and K.

besseli(~n,~z)  =>  0
   when numberp z and z = 0
      and numberp n and n neq 0,

besseli(~n,~z)  =>  besseli(-n,z)
   when numberp n and impart n = 0
      and n = floor n and n < 0,

besselk(~n,~z)  =>  besselk(-n,z)
   when numberp n and impart n = 0
      and n < 0,

besselk(~n,~z)  =>  infinity
   when numberp z and z = 0,

besselk(~n,~z)  =>  (pi/2)*((besseli(-n,z) - besseli(n,z))/(sin(n*pi)))
   when numberp n and impart n = 0 and not (n = floor n),


% Derivatives.

df(besselj(~n,~z),z)  =>  -besselj(1,z)
   when numberp n and n = 0,
df(bessely(~n,~z),z)  =>  -bessely(1,z)
   when numberp n and n = 0,
df(besseli(~n,~z),z)  =>  besseli(1,z)
   when numberp n and n = 0,
df(besselk(~n,~z),z)  =>  -besselk(1,z)
   when numberp n and n = 0,

df(besselj(~n,~z),z)  =>  besselj(n-1,z) - (n/2) * besselj(n,z),
df(bessely(~n,~z),z)  =>  bessely(n-1,z) - (n/2) * bessely(n,z),
df(hankel1(~n,~z),z)  =>  hankel1(n-1,z) - (n/2) * hankel1(n,z),
df(hankel2(~n,~z),z)  =>  hankel2(n-1,z) - (n/2) * hankel2(n,z),
df(besseli(~n,~z),z)  => (besseli(n-1,z) + besseli(n+1,z)) / 2,


% Sending to be computed

besselj(~n,~z)  =>  do!*j(n,z)
   when numberp n and numberp z and symbolic !*rounded,

bessely(~n,~z)  =>  do!*y(n,z)
   when numberp n and numberp z and symbolic !*rounded,

besseli(~n,~z)  =>  do!*i(n,z)
   when numberp n and numberp z and symbolic !*rounded

})$

algebraic (let bessel!*rules);



algebraic procedure do!*j(n,z);
   (if impart n = 0 and impart z = 0 and repart z > 0
    then algebraic sf!*eval('j!*calc!*s,{n,z})
    else algebraic sf!*eval('j!*calc,   {n,z}));

algebraic procedure do!*y(n,z);
   (if impart n = 0 and impart z = 0 and n = floor n
    then if repart z < 0
         then algebraic sf!*eval('y!*calc!*sc, {n,z   })
         else algebraic sf!*eval('y!*calc!*s,  {n,z,{}})
    else if impart n neq 0 or n neq floor n
         then y!*reexpress(n,z)
         else algebraic sf!*eval('y!*calc,     {n,z   }));

% What should be the value of BesselY(0,3i)?


algebraic procedure do!*i(n,z);
   (if impart n = 0 and impart z = 0 and repart z > 0
    then algebraic sf!*eval('i!*calc!*s, {n,z})
    else algebraic sf!*eval('i!*calc,    {n,z}));


algebraic procedure j!*calc!*s(n,z);
   begin scalar n0, z0, fkgamnk, result, alglist!*;
      integer prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if z > (2*prepre) and z > 2*n and
         (result := algebraic sf!*eval('asymp!*j!*calc,{n,z})) neq {}
      then
         << precision prepre;
            complex!*restore!*switch(precom);
            return result >>;
      if prepre < !!nfpd
      then precision (!!nfpd+3+floor(abs n/10))
      else precision (prepre+6+floor(abs n/10));
      n0 := n; z0 := z;
      fkgamnk := gamma(n+1);
      result :=
         algebraic sf!*eval('j!*calc!*s!*sub,{n0,z0,fkgamnk,prepre});
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;


symbolic procedure j!*calc!*s!*sub(n,z,fkgamnk,prepre);
   begin scalar result, admissable, this, prev, nprev,
         modify, fkgamnk, zfsq, zfsqp, knk, azfsq, k;
      n := sq2bf!* n; z := sq2bf!* z;
      fkgamnk := sq2bf!* fkgamnk;
      modify := exp!:(timbf(log!:(divbf(z,bftwo!*),
         c!:prec!:()+2),n), c!:prec!:());
               % modify := ((z/2)**n);
      zfsq := minus!:(divbf(timbf(z,z),i2bf!: 4));
               % zfsq := (-(z**2)/4);
      azfsq := abs!: zfsq;
      result := divbf(bfone!*, fkgamnk);
      k := bfone!*; zfsqp := zfsq;
      fkgamnk := timbf(fkgamnk, plubf(n,bfone!*));

      if lessp!:(abs!: result, bfone!*) then
         admissable := abs!: divbf (bfone!*,
            timbf (exp!:(timbf(fl2bf logten, i2bf!:(prepre +
                     length explode fkgamnk)), 8), modify))
      else
         admissable := abs!: divbf (bfone!*,
            timbf (exp!:(timbf(fl2bf logten, i2bf!:(prepre +
                     length explode (1 + conv!:bf2i abs!: result))), 8),
               modify));

      this := plubf(admissable, bfone!*);

      while greaterp!:(abs!: this, admissable) do
         << this := divbf(zfsqp, fkgamnk);
            result := plubf (result, this);
            k := plubf(k,bfone!*);
            knk := timbf (k, plubf(n, k));
            if greaterp!: (azfsq, knk) then
               precision (precision(0) +
                     length explode(1 + conv!:bf2i divbf (azfsq, knk)));
            zfsqp := timbf(zfsqp,zfsq);
            fkgamnk := timbf(fkgamnk,knk) >>;
      result := timbf(result,modify);

      return mk!*sq !*f2q mkround result;
   end;

flag('(j!*calc!*s!*sub), 'opfn);


algebraic procedure asymp!*j!*calc(n,z);
   begin scalar result, admissable, alglist!*,
         modify, chi, mu, p, q, n0, z0;
      integer prepre;
      prepre := precision 0;
      if prepre < !!nfpd
      then precision (!!nfpd + 5)
      else precision (prepre+8);
      modify := sqrt(2/(pi*z));
      admissable := 1 / (10 ** (prepre + 5));
      chi := z - (n/2 + 1/4)*pi;
      mu := 4*(n**2);
      n0 := n; z0 := z;
      p := algebraic symbolic asymp!*p(n0,z0,mu,admissable);
      if p neq {} then
         << q := algebraic symbolic asymp!*q(n0,z0,mu,admissable);
            if q neq {} then
               result := modify*(first p * cos chi - first q * sin chi)
            else result := {} >>
      else result := {};
      precision prepre;
      return result;
   end;


algebraic procedure asymp!*y!*calc(n,z);
   begin scalar result, admissable, alglist!*,
         modify, chi, mu, p, q, n0, z0;
      integer prepre;
      prepre := precision 0;
      if prepre < !!nfpd
      then precision (!!nfpd + 5)
      else precision (prepre+8);
      modify := sqrt(2/(pi*z));
      admissable := 1 / (10 ** (prepre + 5));
      chi := z - (n/2 + 1/4)*pi;
      mu := 4*(n**2);
      n0 := n; z0 := z;
      p := algebraic symbolic asymp!*p(n0,z0,mu,admissable);
      if p neq {} then
         << q := algebraic symbolic asymp!*q(n0,z0,mu,admissable);
            if q neq {} then
               result := modify*(first p * sin chi + first q * cos chi)
            else result := {} >>
      else result := {};
      precision prepre;
      return result;
   end;


symbolic procedure asymp!*p(n,z,mu,admissable);
   begin scalar result, this, prev, zsq, zsqp, aj2t;
      integer k, f;
      n := sq2bf!* n; z := sq2bf!* z; mu := sq2bf!* mu;
      admissable := sq2bf!* admissable;
      k := 2; f := 1 + conv!:bf2i
         difbf(divbf(n,bftwo!*),divbf(bfone!*,i2bf!: 4));
      this := plubf(admissable, bfone!*);
      result := bfone!*;
      aj2t := asymp!*j!*2term(2, mu);
      zsq := timbf(i2bf!: 4, timbf(z, z));
      zsqp := zsq;
      while greaterp!:(abs!: this, admissable) do
         << prev := abs!: this;
            this := timbf(i2bf!: ((-1)**(k/2)), divbf(aj2t, zsqp));
            if greaterp!: (abs!: this, prev) and (k > f)
            then result := this := bfz!*
            else
               << result := plubf(result, this);
                  zsqp := timbf(zsqp, zsq);
                  k := k + 2;
                  aj2t := timbf(aj2t, asymp!*j!*2term!*modifier(k, mu))
               >> >>;
      if result = bfz!* then return '(list)
      else return list('list, mk!*sq !*f2q mkround result);
   end;


symbolic procedure asymp!*q(n,z,mu,admissable);
   begin scalar result, this, prev, zsq, zsqp, aj2t;
      integer k, f;
      n := sq2bf!* n; z := sq2bf!* z; mu := sq2bf!* mu;
      admissable := sq2bf!* admissable;
      k := 1; f := 1 + conv!:bf2i
         difbf(divbf(n,bftwo!*),divbf(i2bf!: 3, i2bf!: 4));
      this := plubf(admissable, bfone!*);
      result := bfz!*;
      aj2t := asymp!*j!*2term(1, mu);
      zsq := timbf(i2bf!: 4, timbf(z, z));
      zsqp := timbf(bftwo!*, z);
      while greaterp!:(abs!: this, admissable) do
         << prev := abs!: this;
            this := timbf(i2bf!: ((-1)**((k-1)/2)), divbf(aj2t, zsqp));
            if greaterp!: (abs!: this, prev) and (k > f)
            then result := this := bfz!*
            else
               << result := plubf(result, this);
                  zsqp := timbf(zsqp, zsq);
                  k := k + 2;
                  aj2t := timbf(aj2t, asymp!*j!*2term!*modifier(k, mu))
               >> >>;
      if result = bfz!* then return '(list)
      else return list('list, mk!*sq !*f2q mkround result);
   end;


symbolic procedure asymp!*j!*2term(k, mu);
   begin scalar result;
      result := bfone!*;
      for j := 1 step 2 until (2*k - 1) do
         result := timbf(result, difbf(mu, i2bf!: (j**2)));
      result := divbf (result, i2bf!: (factorial k * (2**(2*k))));
      return result;
   end;


symbolic procedure asymp!*j!*2term!*modifier(k, mu);
    (timbf (difbf(mu, i2bf!: ((2*k-3)**2)),
         divbf (difbf(mu, i2bf!: ((2*k-1)**2)),
            i2bf!: ((k-1) * k * 16))));



algebraic procedure y!*calc!*s(n,z,st);
   begin scalar n0, z0, st0, ps, fkgamnk, result, alglist!*;
      integer prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if z > (2*prepre) and z > 2*n and
         (result := asymp!*y!*calc(n,z)) neq {}
      then
         << precision prepre;
            complex!*restore!*switch(precom);
            return result >>;
      if prepre < !!nfpd then precision (!!nfpd+5)
      else precision (prepre + 8);
      n0 := n; z0 := z; st0 := st;
      ps := psi 1 + psi(1+n);
      fkgamnk := gamma(n+1);
      result :=
        algebraic symbolic y!*calc!*s!*sub(n0,z0,ps,fkgamnk,prepre,st0);
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;


% The last arg to the next procedure is an algebraic list of the
% modifier, start value and (factorial n) for the series.  If this is
% (LIST) (i.e. the nil algebraic list {}), the values will be computed
% in this procedure; otherwise the values in st0 will be used.  This
% feature is used for decomposition of the computation of y at negative
% real z.  It is of course designed to make the code as hard to follow
% as possible.  Why else?

% n must be a non-negative integer for this next procedure to work.

symbolic procedure y!*calc!*s!*sub(n,z,ps,fkgamnk,prepre, st0);
   begin scalar start, result, this, ps, fc, modify,
         zfsq, zfsqp, nps, azfsq, bj, z0, n0, tpi, admissable;
      integer k, fk, fnk, difd, fcp;
      z0 := z;
      z := sq2bf!* z; ps := sq2bf!* ps;
      n := sq2bf!* n; n0 := conv!:bf2i n;
      tpi := pi!*();

      if st0 = '(list) then
         << modify := divbf(exp!:
                  (timbf(n, log!:(divbf(z, bftwo!*), c!:prec!:()+2)),
                     c!:prec!:()), tpi);
            bj := retag cdr !*a2f
               sf!*eval('j!*calc!*s!*sub,
                  list('list,n0,z0,fkgamnk,prepre));

            if n0 < 1 then
               << start := timbf(timbf(divbf(bftwo!*,tpi),
                        log!:(divbf(z,bftwo!*),c!:prec!:()+1)), bj);
                  fc := factorial n0 >>

            else if (n0 < 100) then
               << start := bfz!*;
                  zfsq := divbf(timbf(z,z), i2bf!: 4);
                  for k := 0:(n0-1) do
                     start := plubf(start, divbf
                        (exptbf(zfsq, k, i2bf!: factorial (n0-k-1)),
                           i2bf!: factorial k));
                  start := minus!: timbf(start, divbf(exp!:
                     (timbf(minus!: n, log!:(divbf(z, bftwo!*),
                        c!:prec!:()+2)), c!:prec!:()), tpi));
                  start := plubf (start,
                        timbf(timbf(divbf(bftwo!*,tpi),bj),
                     log!:(divbf(z,bftwo!*), c!:prec!:()+2)));
                  fc := factorial n0 >>

            else
               << zfsq := divbf(timbf(z,z), i2bf!: 4); zfsqp := bfone!*;
                  fk := 1; fnk := factorial (n0-1); fc := fnk * n0;
                  start := bfz!*;
                  for k := 0:(n0-2) do
                     << start := plubf(start,
                           timbf(i2bf!: fnk, divbf(zfsqp, i2bf!: fk)));
                        fk := fk * (k+1);
                        fnk := fnk / (n0-k-1);
                        zfsqp := timbf(zfsqp, zfsq) >>;
                  start := plubf(start,
                     timbf(i2bf!: fnk, divbf(zfsqp, i2bf!: fk)));
                  start := minus!: plubf(timbf(start,
                        divbf(bfone!*,timbf(modify,timbf(tpi,tpi)))),
                     timbf(timbf(divbf(bftwo!*,tpi), bj),
                        log!:(divbf(z,bftwo!*),c!:prec!:()+2))) >> >>
      else
         << start := sq2bf!* cadr st0;
            modify := sq2bf!* caddr st0;
            fc := cadddr st0 >>;

      zfsq := minus!: divbf(timbf(z,z),i2bf!: 4);
      azfsq := abs!: zfsq;
      result := divbf(ps, i2bf!: fc);
      k := 1; zfsqp := zfsq; fc := fc * (n0+1);
      ps := plubf(ps,plubf(bfone!*,divbf(bfone!*,plubf(n,bfone!*))));


% Note: we are assuming numberp start.  Be sure to catch other cases
% elsewhere.  (Notably for z < 0).  This goes for bessel J as well.

      if lessp!: (abs!: plubf(result, start), bfone!*) then
         admissable := abs!: divbf(divbf(bfone!*,
               exp!:(timbf(fl2bf logten, plubf(i2bf!:(prepre+2),
                  divbf(log!:(divbf(bfone!*,
                        plubf(abs!: result, abs!: start)), 5),
                     fl2bf logten))), 5)), modify)
      else admissable := abs!: divbf(divbf(bfone!*,
               exp!:(timbf(fl2bf logten, plubf(i2bf!:(prepre+2),
                  divbf(log!:(plubf(abs!: result, abs!: start), 5),
                     fl2bf logten))), 5)), modify);

      this := plubf(admissable, bfone!*);

      while greaterp!: (abs!: this, admissable) do
         << this := timbf(ps, divbf(zfsqp, i2bf!: fc));
            result := plubf(result, this);
            k := k + 1; zfsqp := timbf(zfsqp, zfsq);
            nps := plubf(ps,
               plubf(divbf(bfone!*,i2bf!: k),
                  divbf(bfone!*,i2bf!:(k+n0))));
            fcp := k * (n0+k);
            if greaterp!:(timbf(nps,azfsq),timbf(ps,i2bf!: fcp)) then
               << difd := 1 + conv!:bf2i
                     divbf(timbf(nps,azfsq),timbf(ps,i2bf!: fcp));
                  precision (precision(0) + length explode difd) >>;
            fc := fc * fcp;
            ps := nps >>;

      result := difbf(start, timbf(result, modify));
      return mk!*sq !*f2q mkround result;
   end;

algebraic procedure i!*calc!*s(n,z);
   begin scalar n0, z0, ps, fkgamnk, result, alglist!*;
      integer prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd
      then precision (!!nfpd+3+floor(abs n/10))
      else precision (prepre+8+floor(abs n/10));
      n0 := n; z0 := z;
      fkgamnk := gamma(n+1);
      result :=
         algebraic symbolic i!*calc!*s!*sub(n0,z0,fkgamnk,prepre);
      precision prepre;
      complex!*restore!*switch(precom);
      return result;
   end;


symbolic procedure i!*calc!*s!*sub(n,z,fkgamnk,prepre);
   begin scalar result, admissable, this, prev, nprev,
         modify, fkgamnk, zfsq, zfsqp, knk, azfsq, k;

      n := sq2bf!* n; z := sq2bf!* z;
      fkgamnk := sq2bf!* fkgamnk;

      modify := exp!:(timbf(log!:(divbf(z,bftwo!*),
         c!:prec!:()+2),n), c!:prec!:());
               % modify := ((z/2)**n);
      zfsq := divbf(timbf(z,z),i2bf!:(4));
               % zfsq := (-(z**2)/4);
      azfsq := abs!: zfsq;
      result := divbf(bfone!*, fkgamnk);
      k := bfone!*; zfsqp := zfsq;
      fkgamnk := timbf(fkgamnk, plubf(n,bfone!*));

      if lessp!:(abs!: result, bfone!*) then
         admissable := abs!: divbf (bfone!*,
            timbf (exp!:(timbf(fl2bf logten, i2bf!:(prepre +
                     length explode fkgamnk)), 8), modify))
      else
         admissable := abs!: divbf (bfone!*,
            timbf (exp!:(timbf(fl2bf logten, i2bf!:(prepre +
                     length explode (1 + conv!:bf2i abs!: result))),
                  8),
               modify));

      this := plubf(admissable, bfone!*);

      while greaterp!:(abs!: this, admissable) do
         << this := divbf(zfsqp, fkgamnk);
            result := plubf (result, this);
            k := plubf(k,bfone!*);
            knk := timbf (k, plubf(n, k));
            if greaterp!: (azfsq, knk) then
               precision (precision(0) +
                  length explode (1 + conv!:bf2i divbf (azfsq, knk)));
            zfsqp := timbf(zfsqp, zfsq);
            fkgamnk := timbf(fkgamnk, knk) >>;
      result := timbf(result, modify);

      return mk!*sq !*f2q mkround result;
   end;


%
% algebraic procedure j!*calc(n,z);
%
%  Given integer n and arbitrary (I hope) z, compute and return
%  the value of the Bessel J-function, order n, at z.  Current
%  version mostly coded for speed rather than clarity.
%
%  Does work for non-integral n.
%

algebraic procedure j!*calc(n,z);
   begin scalar result, admissable, this, alglist!*,
        modify, fkgamnk, zfsq, zfsqp, azfsq, knk; % bind alglist!* to
      integer prepre, k, difd;       % stop global alglist being cleared
      prepre := precision 0;

% Don't need to check if asymptotic expansion is valid;
% if we're using this routine, it's not appropriate anyway.
%      if z > (2*prepre) and z > 2*n and
%        (result := asymp!*j!*calc(n,z)) neq {}
%      then return result;

      precision (prepre + 4);
      modify := ((z/2) ** n);
      zfsq := (-(z**2)/4); azfsq := abs zfsq;
      fkgamnk := gamma(n+1);
      result := (1 / (fkgamnk));
      k := 1; zfsqp := zfsq; fkgamnk := fkgamnk * (n+1);
      if numberp modify and impart modify = 0 then
         if (abs result) < 1 then
            << difd := ceiling (1/abs result);
               admissable := abs ((1 / (10 ** (prepre +
                  (symbolic length explode difd)))) / modify) >>
         else
            << difd := ceiling abs result;
               admissable := abs ((1 / (10 ** (prepre -
                  (symbolic length explode difd)))) / modify) >>
      else
         if (abs result) < 1 then
            << difd := ceiling (1/abs result);
               admissable := abs (1 / (10 ** (prepre + 10 +
                  (symbolic length explode difd)))) >>
         else
            << difd := ceiling abs result;
               admissable := abs (1 / (10 ** (prepre + 10 -
                  (symbolic length explode difd)))) >>;
      this := admissable + 1;

      while (abs this > admissable) do
         << this := (zfsqp / (fkgamnk));
            result := result + this;
            k := k + 1;                   % Maintain k as term counter,
            knk := k * (n+k);
            if azfsq > knk then
               <<difd := ceiling (azfsq / knk);
                 precision(precision(0)+(lisp length explode difd))>>;
            zfsqp := zfsqp * zfsq;      % zfsqp as ((-(z**2)/4)**k), and
            fkgamnk := fkgamnk * knk >>;
                                        % fkgamnk as k! * gamma(n+k+1).
      result := result * modify;
      precision prepre;

      return result;
   end;



%
% Procedure to compute (modified) start value for
% Bessel Y computations. Also used to get imaginary
% part for certain values
%

algebraic procedure y!*modifier!*calc(n,z);
   begin scalar modify, start, zfsq, zfsqp, fc;
      integer fk, fnk, prepre;
      prepre := precision 0;
%      if prepre < !!nfpd then precision (!!nfpd + 2)
%      else precision (prepre + 2);
      modify := ((z/2)**n) / pi;

      %  Simple expression for start value when n<1.
      if (n < 1) then
         << start := ((2/pi) * log(z/2) * besselj(n,z));
            fc := factorial n >>

      %  If n smallish, just sum using factorials. (REDUCE
      %  seems to do smallish factorials quite quickly. In
      %  fact it does largish factorials quite quickly as well,
      %  but not quite as quickly as we can build them by
      %  per-term multiplication.)
      else if (n < 100) then
         << start := - (((z/2) ** (-n)) / pi) *
               (for k := 0:(n-1) sum
                  ((factorial (n-k-1) * (((z**2)/4) ** k)) /
                     (factorial k))) + ((2/pi)*log(z/2)*besselj(n,z));
            fc := factorial n >>

      %  If n largish, avoid computing factorials, and try
      %  to do the minimum possible real work.
      else
         << zfsq := (z**2)/4; zfsqp := 1;
            fk := 1; fnk := factorial (n-1); fc := fnk * n;
            start := 0;
            for k := 0:(n-2) do
               << start := start + (fnk * zfsqp / fk);
                  fk := fk * (k+1);
                  fnk := floor(fnk/(n-k-1));
                  zfsqp := zfsqp * zfsq >>;
            start := start + (fnk * zfsqp / fk);
            start := - ((1/(modify*(pi**2)))*start)+
               ((2/pi)*log(z/2)*besselj(n,z)) >>;

      precision prepre;
      return {start, modify, fc};
   end;


%
% algebraic procedure y!*calc(n,z);
%
%  Given integer n and arbitrary (I hope) z, compute and return
%  the value of the Bessel Y-function, order n, at z.  Current
%  version mostly coded for speed rather than clarity.
%
%  Owing to its dependence upon factorials, doesn't work for
%  non-integral n.  (But in any case it'd be very slow, particularly
%  for large non-integral n.)
%

algebraic procedure y!*calc(n,z);
   begin scalar start, result, this, ps, fc, smf,
         modify, zfsq, zfsqp, alglist!*, nps, azfsq;
      integer prepre, k, fk, fnk, difd, fcp;
      prepre := precision(0);

      precision (prepre + 8);
      smf := y!*modifier!*calc (n,z);
      start := first smf;
      modify := second smf;
      fc := third smf;

      %  Now we have the starting value: prepare the loop for
      %  the remaining terms. k will be our loop counter. p1
      %  will hold psi(k+1), and p2 psi(k+n+1); zfsqp is
      %  maintained at ((-(z**2)/4)**k); fc is k! * (n+k)!.
      %  The sum is of (p1 + p2) * zfsqp / fc, and we
      %  precompute the first term in order to get an idea
      %  of the general magnitude (it's a decreasing series).
      ps := psi 1 + psi(1+n);
      zfsq := (-(z**2)/4); azfsq := abs zfsq;
      result := ps / fc;
      k := 1; zfsqp := zfsq; fc := fc * (n+1);
      ps := ps + 1 + (1/(n+1));

      %  Having the first term and start, we check whether
      %  they're small or large and modify the maximum
      %  acceptable error accordingly.
      if numberp start then if (abs (result + start)) < 1 then
            admissable := abs ((1 / (10 **
               (prepre+2 + log10(1/(abs result + abs start)))))/modify)
         else admissable := abs ((1 / (10 ** (prepre + 2))) *
                (log10(abs result + abs start)) / modify)
      else admissable := abs (1 / (10 ** (prepre + 10)));
      this := admissable + 1;

      %  Now sum the series.
      while ((abs this) > admissable) do
         << this := ps * (zfsqp / fc);
            result := result + this;
            k := k + 1; zfsqp := zfsqp * zfsq;
            nps := ps + (1/k) + (1/(k+n));
            fcp := k * (n+k);
            if (nps*azfsq) > (ps*fcp) then
               <<difd := ceiling ((nps*azfsq)/(ps*fcp));
                 precision(precision(0) + (lisp length explode difd))>>;
            fc := fc * fcp;                % fc ends up as k! * (n+k)!
            ps := nps >>;

      %  Amalgamate the start value and modification, and
      %  return the answer.
      result := start - (result * modify);
      precision prepre;
      return result;
   end;




%
% algebraic procedure i!*calc(n,z);
%
%  Given integer n and arbitrary (I hope) z, compute and return
%  the value of the (modified) Bessel I-function, order n, at z.
%  Current version mostly coded for speed rather than clarity.
%
%  Does work for non-integral n.
%

algebraic procedure i!*calc(n,z);
   begin scalar result, admissable, this, prev, nprev, alglist!*,
         modify, fkgamnk, zfsq, zfsqp, knk;  % bind alglist!* to prevent
      integer prepre, k, difd;            % global alglist being cleared
      modify := ((z/2) ** n);
      prepre := precision 0;
      precision (prepre + 4);
      zfsq := (z**2)/4; azfsq := abs zfsq;
      fkgamnk := gamma(n+1);
      result := (1 / (fkgamnk));
      k := 1; zfsqp := zfsq; fkgamnk := fkgamnk * (n+1);
      if numberp modify then
         if (abs result) < 1 then
            << difd := ceiling (1/abs result);
               admissable := abs ((1 / (10 ** (prepre +
                  (symbolic length explode difd)))) / modify) >>
         else
            << difd := ceiling abs result;
               admissable := abs ((1 / (10 ** (prepre -
                  (symbolic length explode difd)))) / modify) >>
      else
         if (abs result) < 1 then
            << difd := ceiling (1/abs result);
               admissable := abs (1 / (10 ** (prepre + 10 +
                  (symbolic length explode difd)))) >>
         else
            << difd := ceiling abs result;
               admissable := abs (1 / (10 ** (prepre + 10 -
                  (symbolic length explode difd)))) >>;
      this := admissable + 1; nprev := abs this;
      while (abs this > admissable) do
         << this := (zfsqp / (fkgamnk));
            result := result + this;
            k := k + 1;                   % Maintain k as term counter,
            knk := k * (n+k);
            if azfsq > knk then
               <<difd := ceiling (azfsq / knk);
                 precision(precision(0) + (lisp length explode difd))>>;
            zfsqp := zfsqp * zfsq;      % zfsqp as ((-(z**2)/4)**k), and
            fkgamnk := fkgamnk * knk >>;
                                        % fkgamnk as k! * gamma(n+k+1).
      result := result * modify;
      precision prepre;
      return result;
   end;



algebraic procedure k!*calc!*2(n,z);
   begin scalar result, precom;
      integer prepre;
      prepre := precision 0;
      precision (prepre + 8);
      precom := complex!*on!*switch();
      result := (pi/2)*i*exp((pi/2)*n*i)*hankel1(n,z*exp((pi/2)*i));
      complex!*restore!*switch(precom);
      precision prepre;
      return result;
   end;



%
% Function which simply rewrites bessely (with nonintegral
% order) in terms of besselj.  Turns off rounded mode to
% do so, because if rounded is on, cos(n*pi) =/= 0 for
% n*2 = floor (n*2), which can lead to some spectacular
% inaccuracies.
%

algebraic procedure y!*reexpress(n,z);
   begin scalar result, premsg;
      premsg := lisp !*msg;
      off msg;
      off rounded;
      result := ((besselj(n,z)*cos(n*pi))-(besselj(-n,z)))/sin(n*pi);
      on rounded;
      if premsg then on msg;
      return result;
   end;

        

%
% Function to make an evil blend of the symbolic and
% algebraic mode bessel-y functions where the order
% is real and the arg is real and negative.  Here the
% result will be complex (probably), but most of the
% computations involved will be with real numbers so
% the symbolic mode version will do them better.
%
% Therefore this routine, which gets the modifier
% and initial terms (the only complex bits) from the
% algebraic procedure and then gets the rest from the
% symbolic one.
%

algebraic procedure y!*calc!*sc(n,z);
   begin scalar st, ic, rc, md, fc, result, precom, prepre;
      prepre := precision 0; z := -z;
      if prepre < !!nfpd then precision (!!nfpd + 2)
      else precision (prepre + 4);
      st := y!*modifier!*calc(n,z);
      rc := - first st;
      precom := complex!*on!*switch();
      ic := impart(log(-pi/2));
      complex!*restore!*switch(precom);
      ic := ic*(2/pi)*besselj(n,-z);
      md := - second st; fc := third st;
      precision prepre;
      precom := complex!*off!*switch();
      result := y!*calc!*s(n,z,{rc,md,fc});
      complex!*restore!*switch(precom);
      if symbolic !*complex
      then result := result + i * ic
      else result := (if ic < 0 then 1 else -1) *
            sqrt(-(ic**2)) + result;
      return result;
   end;

endmodule;


module sfkummer; % Functions and rules for the Kummer M and U functions.

% Author: Chris Cannam, Sept/Oct 1992.

imports complex!*on!*switch, complex!*off!*switch,
   complex!*restore!*switch, sq2bf!*;

exports kummerm!*calc;

% Provides algebraic things for both functions, and numeric for (only)
% the M function.  The amount of non-working code for the U function I
% had to cut out of this before getting this version was a sight to
% behold.

algebraic (operator kummerm, kummeru);

symbolic operator kummerm!*calc;


algebraic (kummer!*rules := {

kummeru(~a,~b,~z)  =>  ( pi / sin (pi * b)) *
      ( (kummerm(a,b,z) / (gamma(1+a-b) * gamma(b))) -
         ((z**(1-b)) * (kummerm(1+a-b,2-b,z)/(gamma(a) * gamma(2-b)))))
   when numberp b and (impart b neq 0 or b neq floor b)
      and numberp a and (impart a neq 0 or a neq floor a or a > 0)
         and ((a-b) neq floor repart (a-b) or (a-b) > -1),

kummeru(~a,~b,~z)  =>  ( pi / sin (pi * b)) *
      ( -((z**(1-b)) * (kummerm(1+a-b,2-b,z)/(gamma(a) * gamma(2-b)))))
   when numberp b and (impart b neq 0 or b neq floor b)
      and numberp a and (impart a neq 0 or a neq floor a or a > 0),

kummerm(~a,~b,~z)  =>  exp z
   when a = b,

kummerm(~a,~b,~z)  =>  ((2 * exp (z/2)) / z) * sinh (z/2)
   when numberp a and numberp b and numberp z
      and a = 1 and b = 2 and impart z = 0 and z neq 0,

kummerm(~a,~b,~z)  =>  ((-2 * i * exp (z/2)) / z) * sin (-z / (2*i))
   when numberp a and numberp b and numberp z
      and a = 1 and b = 2 and repart z = 0 and z neq 0,

kummerm(~a,~b,~z)  =>  infinity
   when numberp a and numberp b
      and impart b = 0 and b < 0 and b = floor b
         and not (impart a = 0 and a < 0 and a = floor a and a >= b),

kummerm(~a,~b,~z)  =>  do!*kummerm(a,b,z)
   when symbolic !*rounded
      and numberp a and numberp b and numberp z
         and b neq 0
            and impart a = 0 and impart b = 0 and impart z = 0
               and not (repart b = floor repart b
                        and repart a = floor repart a
                        and repart a < 0 and repart b < 0
                        and repart a >= repart b),

df(kummerm(~a,~b,~z),z)  =>  (a/b) * kummerm(a+1, b+1, z),

df(kummeru(~a,~b,~z),z)  =>  -a * kummeru(a+1,b+1,z)

})$


algebraic (let kummer!*rules);



algebraic procedure do!*kummerm(a,b,z);
   algebraic sf!*eval('kummerm!*calc, {a,b,z});


algebraic procedure kummerm!*calc(a,b,z);
   begin scalar a0, b0, z0, result, alglist!*;
      integer prepre, precom;
      precom := complex!*off!*switch();
      prepre := precision 0;
      if prepre < !!nfpd then precision (!!nfpd + 1)
      else precision (prepre + 2);
      a0 := a; b0 := b; z0 := z;
      result :=
         algebraic symbolic kummerm!*calc!*sub(a0,b0,z0);
      complex!*restore!*switch(precom);
      precision prepre;
      return result;
   end;


symbolic procedure kummerm!*calc!*sub(a,b,z);
   begin scalar result, this,
         admissable, pamod, pbmod;
      integer rp, orda, k;
      a := sq2bf!* a; b := sq2bf!* b; z := sq2bf!* z;
      result := bfone!*; k := 1;
      pamod := timbf(a,z); pbmod := b;
      admissable := divbf(bfone!*,
         i2bf!: (bf!*base**(5 + c!:prec!:())));
      orda := order!: admissable - 5;
      this := bfone!*; rp := c!:prec!:();
      while greaterp!: (abs!: this, admissable) do
         << this := divide!:(times!:(this,pamod),
                  times!:(pbmod, i2bf!: k),rp);
            rp := order!: this - orda;
            result := plus!:(result, this);
            k := k + 1;
            pamod := plus!:(pamod, z);
            pbmod := plus!:(pbmod, bfone!*);
         >>;
      return mk!*sq !*f2q mkround result;
   end;

endmodule;


module sfother;   % Rulesets for the Struve H and L functions, Lommel
                  % 1 and 2 functions and Whittaker M and W functions.

% Author: Chris Cannam, Nov 1992.

% The aim is to re-express in terms % of other (more `standard') special
% functions. No numerical approximation code.

% Neither imports nor exports functions.
% This module contains only rulesets.

algebraic (operator struveh, struvel);

algebraic (struve!*rules := {

df(struveh(~n,~z),z)  =>
   (2/pi) - struveh(1,z)
      when numberp n and n = 0,

df((z**n)*struveh(~n,~z),z)  =>
   (z**n)*struveh(n-1,z),

df((z**(-n))*struveh(~n,~z),z)  =>
   (1/(sqrt(pi)*(2**n)*gamma(n+(3/2)))) - (z**(-n))*struveh(n+1,z),


struveh(~n,~z)  =>
   ((-1)**n)*besselj(-n,z)
      when numberp n and impart n = 0
         and n < 0 and (n*2)=floor(n*2)
         and not evenp floor(n*2),

struveh(~n,~z)  =>
   ((2/(pi*z))**(1/2))*(1-cos z)
      when numberp n and n=1/2,

struveh(~n,~z)  =>
   ((z/(pi*2))**(1/2)) * (1+(2/(z**2))) -
      ((2/(pi*z))**(1/2)) * (sin z + ((cos z)/z))
      when numberp n and n=3/2,


struvel(~n,~z)  =>
   besseli(-n,z)
      when numberp n and impart n = 0
         and n < 0 and (n*2)=floor(n*2)
         and not evenp floor(n*2),

struvel(~n,~z)  =>
   -i*(e**((-i*n*pi)/2))*struveh(n,i*z)
      when symbolic !*complex

})$

algebraic (let struve!*rules);



algebraic (operator lommel1, lommel2);

algebraic (lommel!*rules := {

lommel1(~a,~b,~z)  =>
   -(2**a)*besselj(a,z)*gamma(a+1)+z**a
      when numberp a and numberp b and a = b+1,

lommel1(~a,~b,~z)  =>
   lommel1(a,-b,z)
      when numberp b and b < 0 and a neq b and a neq (b+1),

lommel1(~a,~b,~z)  =>
   (sqrt(pi)*(2**a)*gamma((2*a + 1)/2)*struveh(a,z))/2
      when a = b,

lommel2(~a,~b,~z)  =>
   z**b
      when numberp a and numberp b and a = b+1,

lommel2(~a,~b,~z)  =>
   lommel2(a,-b,z)
      when numberp b and b < 0 and a neq b and a neq (b+1),

lommel2(~a,~b,~z)  =>
   (sqrt(pi)*(2**a)*gamma((2*a + 1)/2)*(-bessely(a,z)+struveh(a,z)))/2
      when a = b

})$

algebraic (let lommel!*rules);



algebraic (operator whittakerm, whittakerw);

algebraic (whittaker!*rules := {

whittakerm(~k,~m,~z)  =>
   exp(-z/2)*(z**(1/2+m))*kummerm(1/2+m-k,1+2*m,z),

whittakerw(~k,~m,~z)  =>
   exp(-z/2)*(z**(1/2+m))*kummeru(1/2+m-k,1+2*m,z)

})$

algebraic (let whittaker!*rules);

endmodule;


module dilog;

% Dilogarithm Integral

% Collected (most items) from Abramowitz-Stegun (27.8.7)
% by Winfried Neun , ZIB Berlin

algebraic <<
operator fps;
operator defint;

let { fps(dilog ~x,~x) => infsum((-1)^k*(x-1)^k/k^2,k,1,infinity)};
let { df(dilog(~x),~x) => - log(x)/(x-1)};
let { defint(log(~tt)/(~tt-1),~tt,1,~x) => -dilog x };
let { defint(log(~tt)/(1-~tt),~tt,1,~x) => dilog x };

let { dilog(exp(-~t)) => - dilog(exp t) - t^2/2,
      dilog(-~x+1) => - dilog(x) -log x * log (1-x) + pi^2/6
                        when numberp x and geq(x,0) and geq(1,x),
      dilog(1/~x) => - dilog(x) -(log x)^2/2
                        when numberp x and geq(x,0) and geq(1,x),
      dilog(~x + 1) =>  dilog(x) - log x *
                        log (x +1)-pi^2/12-(dilog x)^2/2
                        when numberp x and geq(x,0) and geq(2,x),
      dilog(~x) => compute_dilog(x)
                 when numberp x and lisp !*rounded and x>=0,
      dilog 2 => -pi^2/12,
      dilog 1 => 0,
      dilog 0 => pi^2/6};

procedure compute_dilog(x);
   if x = 0.0 then  pi^2/6
    else if x = 1.0 then  0
    else if x = 2.0 then  -pi^2/12
    else if (x >= 1.9 and x < 2.0) then
                 compute_dilog(1-(x-1)^2)/2 - compute_dilog(1-(x-1))
    else if (x > 1.9 or x < -1.0) then
                -(log x)^2/2 -compute_dilog(1/x)
    else if (x < 0.5 and x > 0.0)
                 then -log(1-x)*log(x) + pi^2/6 - compute_dilog(1-x)
    else if (x > 0.5 and x < 1.0 )
                then  -(log x)^2/2 -compute_dilog(1/x)
    else begin scalar !*uncached,yy,summa,ii,term,altern ,xm1,xm1!^ii;
                !*uncached :=t;
                yy := 10^-(lisp !:prec!:);
                summa := 0; xm1 := x-1.0; xm1!^ii := xm1;
                ii :=1; altern := -1;
                while abs(term :=(altern * xm1!^ii/(ii*ii))) >  yy do <<
                 summa := summa +  term; ii:=ii+1 ;
                 altern := -1 * altern; xm1!^ii := xm1!^ii *xm1>>;
                return summa; end;
>>;

endmodule;


module sfbinom;   % Procedures for computing Binomial coefficients
                  % Stirling numbers and such
%
% Author: Winfried Neun, Feb 1993, Sep 1993

algebraic operator binomial;

algebraic << let { binomial (~n,~k) => factorial n /
                                    (factorial k * factorial (n-k))
                        when fixp n and fixp k and n >= k and k >= 0,
                binomial (~n,~k) =>
                    gamma(n+1) / gamma (k+1) / gamma(n-k+1) } >>;

% Some rules for quotients of binomials are still missing

algebraic operator stirling1, stirling2;

algebraic
 let {stirling1(~n,~n) => 1,
      stirling1(~n,0)  => 0 when not n=0,
      stirling1(~n,~n-1) => - binomial(n,2),
      stirling1(~n,~m) => 0 when fixp n and fixp m and n < m,
      stirling1(~n,~m) => (for k:=0:(n-m) sum
                        ( (-1)^k * binomial(n-1+k,n-m+k) *
                          binomial(2*n-m,n-m-k) * stirling2(n-m+k,k)))
                when fixp n and fixp m and n > m,
% This rather naive implementation will cause problem
% when m - n is large !
      stirling2(~n,~n) => 1,
      stirling2(~n,0)  => 0 when not n=0,
      stirling2(~n,~n-1) => binomial(n,2),
      stirling2(~n,~m) => 0 when fixp n and fixp m and n < m,
      stirling2(~n,~m) => calc_stirling2(n,m)
                        when fixp n and fixp m and n >m };

algebraic procedure calc_stirling2 (n,m);

begin scalar bin_row;
bin_row := binomial_row(m);
return
((for k:=0:m sum ( (-1)^(m-k)
  * part(bin_row,k+1)*k^n))/factorial(m));
end;


symbolic procedure binomial_row (n);

        % computes nth row of the Pascal triangle

begin scalar list_of_bincoeff, newlist, old, curr;

if (not fixp n) or (n < 0) then return nil;

list_of_bincoeff := { 1 };

while n > 0 do
     << old := 0;
        newlist := {};
        while not list_of_bincoeff = {} do
            <<  curr := first list_of_bincoeff;
                newlist := (old + curr) . newlist;
                old := curr;
                list_of_bincoeff := rest list_of_bincoeff;
            >>;
        list_of_bincoeff := 1 . newlist;
        n := n -1
     >>;
return 'list . list_of_bincoeff;

end;

flag('(binomial_row),'opfn);

endmodule;


module sfpolys;   % Assorted Polynomials
                  % will be a package of its own one day
%
% Author: Winfried Neun, Feb 1993


% Bernoulli Polynomials (see e.g. Abramowitz Stegun , chapter 23

algebraic operator bernoullip;

algebraic <<
let {   bernoullip (~n,0) => bernoulli n     when fixp n and n >=0,
        bernoullip (~n,~x) => (for k:=0:n sum (binomial(n,k) *
                         bernoulli(k) * x^(n-k)))
                                          when fixp n and n >=0} >>;

% Euler Polynomials (see e.g. Abramowitz Stegun , chapter 23

algebraic operator eulerp ;

algebraic <<
let {   eulerp (~n,1/2) => euler(n)/2^n when fixp n and n >=0,
        eulerp (~n,~x) => (for k:=0:n sum (binomial(n,k) *
                         euler(k)/2^k * (x -1/2)^(n-k)))
                                    when fixp n and n >=0}
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
     hermite_base1(x,n,{2*x,1},1);

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

operator hermitep,jacobip,legendrep,
         laguerrep,chebyshevt,chebyshevu,gegenbauerp;

let {hermitep (~n,~x)=> sub(z = x,first reverse hermite_base (z,n))
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


module sfsums;   % Calculation of infinite sums of reciprocal
                 % Powers, see e.g. Abramowitz/Stegun ch 23.
%
% Author: Winfried Neun, Sep 1993

algebraic <<

 let{
  sum((-1)^~k /(2*(~k)-1)^~n,~k,1,infinity) =>
        pi^n*abs(euler(n-1))/(factorial(n-1) * 2^(n+1))
        when fixp n and n > 0 and not evenp n,

  sum((-1)^~k /(2*(~k)-1)^2,~k,1,infinity) => catalan,

  sum(1/(2*(~k)-1)^~n,~k,1,infinity) => zeta(n) *(1-2^(-n))
        when fixp n and n > 0 and evenp n,

  sum(1/~k^~n,~k,1,infinity) =>  zeta(n)
        when fixp n and n > 0 and evenp n,

  sum((-1)^~k/~k^~n,~k,1,infinity) =>  zeta(n)* (1-2^(1-n))
        when fixp n and n > 0 and evenp n

} >>;
endmodule;


module sfint;     % Assorted Integral Functions, Ei, Si, Ci etc.
                  % Includes rules and limited rounded mode evaluation
                  % for Ei, Si, si (called s_i here!), Ci, Chi, Shi, 
                  % Fresnel_S, Fresnel_C and Erf;
                  % the numerical part to be improved!
%
% Author: Winfried Neun, Jun 1993
% email : neun@sc.ZIB-Berlin.de

% For Math References, see e.g. Abramowitz/Stegun, chapter 5 and 7

% Exponential Integral etc.

algebraic operator ei, fresnel_c, fresnel_s, erfc;

algebraic operator ci, si, s_i, shi, chi;

algebraic let limit(si(~tt),~tt,infinity) => pi/2;

algebraic
let { defint(sin(~tt)/~tt,~tt,0,~z) => si (z),
      si(-~x) => (- si(x)),
      df(si(~x),~x) => sin(x)/x  ,
      si(~x) => compute_int_functions(x,si)
                 when numberp x and lisp !*rounded
    };

algebraic
let { defint(sin(~tt)/~tt,~tt,~z,infinity) => - s_i (z),
      limit(s_i(~tt),x,infinity) => 0,
      s_i(~x) => si(x) - pi/2,
      df(s_i(~x),~x) => sin(x)/x
    };

algebraic
let { defint(exp(~tt)/~tt,~tt,-infinity,~z) =>  ei (z),
      df(ei(~x),~x) => exp(x)/x,
      ei(~x) => compute_int_functions(x,ei)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { defint(cos(~tt)/~tt,~tt,~z,infinity) => - ci (z),
      defint((cos(~tt) -1)/~tt,~tt,0,~z) => ci (z) + psi(1) -log(z),
% psi(1) may be replaced by euler_gamma one day ...
      ci(-~x) => - ci(x) -i*pi,
      df(ci(~x),~x) => cos(x)/x,
      ci(~x) => compute_int_functions(x,ci)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { defint(sinh(~tt)/~tt,~tt,0,~z) => shi (z),
      df(shi(~x),~x) => sinh(x)/x  ,
      shi(~x) => compute_int_functions(x,shi)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { defint((cosh(~tt) -1)/~tt,~tt,0,~z) => chi (z) + psi(1) -log(z),
% psi(1) may be replaced by euler_gamma one day ...
      df(chi(~x),~x) => cosh(x)/x  ,
      chi(~x) => compute_int_functions(x,chi)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { defint(sin(pi/2*~tt^2),~tt,0,~z) => fresnel_s (z),
      fresnel_s(-~x) => (- fresnel_s (x)),
      fresnel_s(i* ~x) => (-i*fresnel_s (x)),
      limit(fresnel_s(~tt),~tt,infinity) => 1/2,
      df(fresnel_s(~x),~x) => sin(pi/2*x^x) ,
      fresnel_s (~x) => compute_int_functions(x,fresnel_s)
              when numberp x and abs(x) <= 10 and lisp !*rounded };

algebraic
let { defint(cos(pi/2*~tt^2),~tt,0,~z) => fresnel_c (z),
      fresnel_c(-~x) => (- fresnel_c (x)),
      fresnel_c(i* ~x) => (i*fresnel_c (x)),
      limit(fresnel_c(~tt),~tt,infinity) => 1/2,
      df(fresnel_c(~x),~x) => cos(pi/2*x^x) ,
      fresnel_c (~x) => compute_int_functions(x,fresnel_c)
               when numberp x and abs(x) <= 10 and lisp !*rounded };

algebraic
let { limit (erf(~x),~x,infinity) => 1,
      limit (erfc(~x),~x,infinity) => 0,
      erfc (~x) => 1-erf(x),
      defint(1/e^(~tt^2),~tt,0,~z) => erf(z)/2*sqrt(pi),
      defint(1/e^(~tt^2),~tt,~z,infinity) => erfc(z)/2*sqrt(pi),
      erf (~x) => compute_int_functions(x,erf)
                when numberp x and abs(x)<3 and lisp !*rounded };

algebraic procedure compute_int_functions(x,f);
   begin scalar pre,!*uncached,scale, term, n, precis,
       result,interm;
   pre := precision 0; precision pre;
   precis := 10^(-2 * pre);
   lisp setq (!*uncached,t);

    if f = si then
           if x < 0 then - compute_int_functions(-x,f) else
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
    else if f = ci then
           if x < 0 then - compute_int_functions(-x,f) -i*pi else
              << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else  if f = ei then
          << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := (term * x)/n;
                    result := result + term/n;
                    n := n + 1>>; >>
    else  if f = shi then
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := (term * x*x)/(2n * (2n+1));
                    result := result + term/(2n+1);
                    n := n + 1>>; >>
    else  if f = chi then
            << n:=1; term := 1; result := euler!*constant + log(x);
               while abs(term) > precis do
                 << term := (term * x*x)/((2n-1) * 2n);
                    result := result + term/(2n);
                    n := n + 1>>; >>
    else if f = erf then
           if x < 0 then - compute_int_functions(-x,f) else
            << n:=1; term := x; result := x;
               while abs(term) > precis do
                 << term := -1 * (term * x*x)/n;
                    result := result + term/(2n+1);
                    n := n + 1>>;
               result := result*2/sqrt(pi) ;>>
    else  if f = fresnel_s then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x^3*pi/2; result := term/3;
                         interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n+1));
                    result := result + term/(4n+3);
                    n := n + 1>>; >>
    else  if f = fresnel_c then
            << if x > 4.0 then precision max(pre,40);
               if x > 6.0 then precision max(pre,80);
               n:=1; term := x; result := x; interm := x^4*(pi/2)^2;
               while abs(term) > precis do
                 << term := -1 * (term * interm)/(2n * (2n-1));
                    result := result + term/(4n+1);
                    n := n + 1>>;  >>;
    precision pre;
    return result;
end;

endmodule;


end;
