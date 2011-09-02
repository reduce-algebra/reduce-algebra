module specfn;  % Special functions package for REDUCE.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...
%          contribution from various authors ...

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
%              -- Airy Functions                                 %
%              -- Hankel Functions H1 and H2                     %
%              -- Kummer Hypergeometric Functions M and U        %
%              -- Struve, Lommel and Whittaker Functions         %
%              -- Integral funtions, Si, Ci, s_i (=si), Ei,...   %
%              -- Simplification of Factorials                   %
%              -- Solid and Spherical Harmonics                  %
%              -- Jacobi Elliptic Functions                      %
%              -- Elliptic Integrals                             %
%                                                                %
%     accessible through the new operators Bernoulli, Gamma,     %
%     Pochhammer, Psi, Polygamma, Zeta, BesselJ, BesselY,        %
%     BesselI, BesselK, Hankel1, Hankel2, KummerM, KummerU,      %
%     AiryAi, AiryBi, AiryAiPrime, AiryBiPrime,                  %
%     Elliptic{sn,cn,dn...}, Elliptic{E,F,K...}
%     Beta, StruveL, StruveH, Lommel1, Lommel2, WhittakerM       %
%     and WhittakerW, with the new switch SaveSFs.               %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %

% load!-package 'arith;   % For bootstrapping purposes.

create!-package ('(specfn sfconsts
                   sfgen sfbern sfgamma sfpsi dilog sfbinom
                   sfpolys sfsums simpfact harmonic jsymbols
                   recsimpl sfellip sfellipi sfint ),
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
               << global '(log2of10); log2of10 := 3.32193 >> );

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
         << off msg; off complex; on msg >>
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

%algebraic operator besselJ,besselY,besselI,besselK,hankel1,hankel2;
%algebraic (operator kummerM, kummerU, struveh, struvel
%                  ,lommel1, lommel2 ,whittakerm, whittakerw,
%                   Airy_Ai, Airy_Bi,Airy_AiPrime,Airy_biprime);

defautoload_operator(besselj,specbess);
defautoload_operator(bessely,specbess);
defautoload_operator(besseli,specbess);
defautoload_operator(besselk,specbess);
defautoload_operator(hankel1,specbess);
defautoload_operator(hankel2,specbess);
defautoload_operator(kummerm,specbess);
defautoload_operator(kummeru,specbess);
defautoload_operator(struveh,specbess);
defautoload_operator(struvel,specbess);
defautoload_operator(lommel1,specbess);
defautoload_operator(lommel2,specbess);
defautoload_operator(whittakerm,specbess);
defautoload_operator(whittakerw,specbess);
defautoload_operator(airy_ai,specbess);
defautoload_operator(airy_bi,specbess);
defautoload_operator(airy_aiprime,specbess);
defautoload_operator(airy_biprime,specbess);

endmodule;


module sfconsts; % Constants from pecial functions such as Euler_Gamma,
                 % Catalan, Khinchin.

algebraic let euler_gamma => compute_euler_gamma();

symbolic flag('(compute_euler_gamma),'opfn);

symbolic procedure compute_euler_gamma ();

  if not(!*rounded) then mk!*sq('((((euler_gamma . 1) . 1)) . 1))
         else aeval '(minus (psi 1));

%%%%%%%%%%%%%%%

algebraic let  golden_ratio = (1 + sqrt(5))/2; % for Architects

%%%%%%%%%%%%%%%%

fluid '(intlogrem);

Comment this program is taken from:

COMPUTATION OF CATALAN'S CONSTANT USING RAMANUJAN'S FORMULA

Greg J. Fee, Dept of Comp Sci, U of Waterloo,

published in ISSAC '90, ACM press ;

algebraic let catalan => compute_catalan();

symbolic flag('(compute_catalan),'opfn);

symbolic procedure compute_catalan ();

  if not(!*rounded) then mk!*sq('((((catalan . 1) . 1)) . 1)) else
   begin scalar ii,j,p,tt,s,g,!*rounded;

      g := !:prec!: + length explode !:prec!: + 3;
      p := 10^g/2;
      tt := p; s := tt; j :=1; ii := 1;

      while tt > 0 do
        << j := j+2; p := (p*ii) / j; tt := (tt * ii + p)/j;
           s := s + tt; ii := ii + 1 >>;

      return list('quotient,s,10^(g));
  end;

%%%%%%%%%%%%%%%%%%%%

algebraic <<

% Khinchin's constant =(prod((1+1/(n*(n+2)))^(ln n/ln2),n,1,infinity))
%
% translated from a (Maple code) posting by Paul Zimmermann
%       in sci.math.symbolic
%
let khinchin => compute_khinchin();

symbolic procedure compute_khinchin();

 (if not(!*rounded) then mk!*sq('((((khinchin . 1) . 1)) . 1)) else
    aeval ('compute_khinchin1 . nil)) where !:prec!: = !:prec!: ;

symbolic flag('(compute_khinchin intlog),'opfn);

procedure compute_khinchin1();
  begin scalar term,summ,acc,k,ln2,ln3,oldprec,zp;
     if evenp(oldprec := precision 0) then
             precision (oldprec+13) else
             precision (oldprec+12);
     acc := 10^(-oldprec -3);
     ln2 := log 2;
     ln3 := log 3;
     k:=2;
     term :=1; summ :=0;
     while abs(term) > acc do <<
        zp := zetaprime(k);
        term :=(-1)^k*(2*zp-2^k*(zp+ln2/2^k+ln3/3^k))/k;
        summ := summ + term;
        k:=k+1   >>;

     summ := e^(summ /ln2+ln3/ln2*(2./3-log(5/3))+1-ln2);
     precision(oldprec);
     return summ;
  end;

procedure zetaprime (u);

  begin scalar term,summ,n,acc,f,j,logm,m,oldprec;
     oldprec := precision 0;
     precision(oldprec+5);
     n:= u;
     lisp setq(intlogrem,nil);
     f := -df(log(x)/x^n,x)/2;
     m:= (oldprec+5)/2;
     logm := log(m);
     term := logm;
     acc := 10^(1-(oldprec +5))/2;
     j:=1;
     summ := -(for ii:=2:(fix m -1) sum intlog(ii)/ii^n) -
        (logm+1/(n-1))/m^(n-1)/(n-1)-logm/2/m^n;
     while abs(term) > acc do
          << term := bernoulli(2*j) * sub(log(x)=logm,x=m,f);
             f := df(f,x,x)/((4j+6)*j +2);
             summ := summ -term;
             j:= j+1;
           >>;
     precision oldprec;
     return summ;
  end;

symbolic procedure intlog(n);

  ( if found := atsoc(n,intlogrem) then cdr found else
       << found := intlog1 n;
    intlogrem := (( n . found)  . intlogrem);
          found >>) where found = nil;

symbolic procedure intlog1 (n);

 (if n=2 or n=3 or n=4 or n=5 or n=7 then
                rdlog!* ('!:rd!: . (n . 0)) else
  if cdr(div := divide(n,2)) #= 0 then
                rd!:plus(intlog 2,intlog(car div)) else
  if cdr(div := divide(n,3)) #= 0 then
                rd!:plus(intlog 3,intlog(car div)) else
  if cdr(div := divide(n,5)) #= 0 then
                rd!:plus(intlog 5,intlog(car div)) else
  if cdr(div := divide(n,7)) #= 0 then
                rd!:plus(intlog 7,intlog(car div)) else
   rdlog!* ('!:rd!: . (n . 0))) where div = nil;

>>;
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
   begin scalar part1, part2, result;
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

flag('(euler_aux),'opfn);

symbolic procedure euler_aux(n);

if not evenp n then 0 else

begin scalar nn,list_of_bincoeff, newlist, old, curr,eulers,sum;

list_of_bincoeff := { 1 };

eulers :={ -1,1};

nn := -2;

while n > 0 do
<<      nn := nn + 1;
        old := 0;
        newlist := {};
        while not(list_of_bincoeff = {}) do

        <<  curr := first list_of_bincoeff;
            newlist := (old + curr) . newlist;
            old := curr;
            list_of_bincoeff := rest list_of_bincoeff;
        >>;

        list_of_bincoeff := 1 . newlist;
        n := n -1        ;

% now that we have got the row of Pascal's triangle
% we can use it and compute the Next Euler number.

        if nn > 0 and evenp nn then <<
           curr := list_of_bincoeff;
           old := eulers; sum := 0;
           while old do <<
              curr := cddr curr;
              sum := sum - first old * first curr;
              old := cdr old;
              >>;
           eulers := sum . eulers;
          >>;
>>;

return first eulers;
end;

endmodule;


module sfgamma;   % Gamma function procedures and rules for REDUCE.

% Author: Chris Cannam, Sept/Oct '92

imports complex!*on!*switch, complex!*off!*switch,
   complex!*restore!*switch, sf!*eval;

exports do!*gamma, do!*pochhammer, do!*poch!*conj!*calc;

fluid '(compute!-bernoulli intlogrem);

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

%  gamma(~x)  =>  infinity
%     when numberp x and impart x = 0
%        and x = floor x and x < 1,

   gamma(~x)  =>  gamma(x-1) * (x-1)
      when numberp x and not symbolic !*rounded
       and impart x = 0 and (64*x) = floor(64*x) and x > 1 and x < 50,

   gamma(~x)  =>  pi / (sin(pi*x) * gamma(-x) * (-x))
      when numberp x and x < 0 and not (fixp x and x < 1),

   gamma(~x)  =>  do!*gamma(x)
      when numberp x and not (fixp x and x < 1) and symbolic !*rounded,

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
      and (z+w = floor (z+w) and (z+w) < 1)

%beta(~z,~w)  =>  Infinity
%   when numberp z and numberp w and impart z = 0 and impart w = 0
%      and ((z = floor z and z < 1)
%        or (w = floor w and w < 1))
%      and not (z+w = floor (z+w) and (z+w) < 1)

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

df(pochhammer(~z,~k),~z) => pochhammer(~z,~k) * (psi(z+k)-psi(z)),

pochhammer(~z,~k)  => (-1)^k*factorial(-z)/factorial(-z-k)
   when fixp z and z<0,

pochhammer(~z,~k)  =>  ( for i:=0:(k-1) product(z + i))
   when numberp k and k < 20 and k > 0,

pochhammer(~z,~k)  =>  1
   when numberp k and k = 0,

pochhammer(~z,~k)  => factorial(z+k-1)/factorial(z-1)
   when fixp z and z > 0,

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
         and (a+1/2) = floor (a+1/2) and a > 0,

pochhammer(~a,~k)  =>
   (-1)^(-a+1/2) * pochhammer(1-a-(-a+1/2),(-a+1/2)) *
                   pochhammer(a+(-a+1/2),k-(-a+1/2))
      when numberp a and impart a = 0
         and (a+1/2) = floor (a+1/2) and a < 0});


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
               and a = 6/5 and aa = 7/5 and aaa = 8/5 and aaaa = 9/5,

pochhammer(~a,~k)//pochhammer(~b,~k)  => (a + k -1)/(a - 1)
                        when (a - b)=1,

pochhammer(~a,~k)//pochhammer(~b,~k)  => (b - 1)/(b + k -1)
                        when (b - a)=1
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
      integer k, rp, orda, magn;

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

      if (lisp null compute!-bernoulli) then
         symbolic <<errorset!*('(load_package '(specfaux)), nil); nil>>;

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


% lets prod (in misc package) know about gamma.

algebraic
  let { prod(~n,~n,~anf,~ende) => gamma(ende + 1)/gamma(anf)
                when not( fixp anf and anf < 0) ,

        prod(~n,~n,~anf) => gamma(n+1)/gamma(anf)
                when not( fixp anf and anf < 0),

        prod(~k +~n,k,~nanf,~nend) =>
                 gamma(nend + 1 + n)/gamma (nanf + n)
                when numberp nanf and numberp n and nanf + n > 0,

        prod(~k +~n,k,~nanf,~nend) => 0
                when numberp nanf and numberp n and nanf= - n,

        prod(~~a*~k +~n,k,~nanf,~nend) => prod(a,k,nanf,nend)*
                 gamma(nend + 1 + n/a)/gamma (nanf + n/a)
                 when freeof(a,k) and freeof (n,k),
%               when not(numberp nanf and numberp n),


%       prod(~n,~n) =>  gamma(n+1)},

        (~~u*gamma(~x+~~n0))//(~~v*gamma(x +~~n1)) =>
        (u*gamma(~x+n0))/(v*(x+n1-1)*gamma(x+n1-1))
                 when not (numberp x and x eq 0)
                 and (fixp n0 and fixp n1 and n0<n1 and (n1 -n0)< 6),

        (~~u*gamma(~x+~~n0))//(~~v*gamma(x +~~n1)) =>
        (u*gamma(~x+n0-1)*(x+n0-1))/(v*gamma(x+n1))
                when not (numberp x and x eq 0)
                 and (fixp n0 and fixp n1 and n0>n1  and (n0-n1)< 6)
};

endmodule;


module sfpsi; % Procedures relevant to the digamma, polygamma & zeta
              % functions.

% Author: Chris Cannam, Sept/Oct '92.

% Added: PSI_SIMP.RED  F.J.Wright, 2 July 1993
%        The polygamma rules are added by Y.K. Man on 9 July 1993

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

algebraic procedure get!-eulers!-constant;
   begin scalar a;
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
      a := a * (10**(-506));
      return a
   end;

algebraic (euler!*constant := get!-eulers!-constant());

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

   psi(~z)  =>  psi(1-z) + pi*cot(pi*(1-z))
      when numberp z and impart z = 0
         and z > 1/2 and z < 1 and not symbolic !*rounded,

   df(psi(~z),z)  =>  polygamma(1, z),

   int(psi(~z),z)  =>  log gamma(~z)

})$

algebraic (let psi!*rules);


% PSI_SIMP.RED  F.J.Wright, 2 July 1993
% The polygamma rules are added by Y.K. Man on 9 July 1993

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

      if null compute!-bernoulli then
         <<errorset!*('(load_package '(specfaux)), nil); nil>>;

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


module dilog;

% Dilogarithm Integral

% Collected (most items) from Abramowitz-Stegun (27.7)
% by Winfried Neun , ZIB Berlin

algebraic <<
operator fps;

let { fps(dilog ~x,~x,1) => infsum((-1)^k*(x-1)^k/k^2,k,1,infinity)};
let { df(dilog(~x),~x) => - log(x)/(x-1)};
let { int(log(~tt)/(~tt-1),~tt,1,~x) => -dilog x };
let { int(log(~tt)/(1-~tt),~tt,1,~x) => dilog x };

let { dilog(exp(-~t)) => - dilog(exp t) - t^2/2,
      dilog(1/e^(~t)) => - dilog(exp t) - t^2/2,
      dilog(-~x+1) => - dilog(x) -log x * log (1-x) + pi^2/6
                        when numberp x and geq(x,0) and geq(1,x),
      dilog(~x)   => - dilog(1-x) - log (x) * log(1-x) + pi^2/6
                        when numberp x and geq(x,0) and geq(1,x)
                        and not fixp(1/x),
      dilog(1/~x) => - dilog(x) -(log x)^2/2
                        when numberp x and geq(x,0),
      dilog(~x) =>   dilog(x-1) - log (x - 1) *
                        log (x)-pi^2/12-dilog( (x-1)^2)/2
                        when numberp x and geq(x,1) and geq(2,x)
                        and not fixp(1/x),
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

algebraic <<
 let { binomial (~n,~k) => factorial n /
                      (factorial k * factorial (n-k))
                        when fixp n and fixp k and n >= k and k >= 0,
       binomial (~n,~k) => 1
                when fixp n and fixp k and n >= k and k =0,
       binomial (~n,~k) => 0
                when fixp n and fixp k and n<k and n >=0,
       binomial (~n,~k) => gamma(n+1) / gamma (k+1) / gamma(n-k+1)
                when numberp n and  numberp k,
       df(binomial(~c,~k),c) => binomial(c,k)*(psi(1+c)-psi(1+c-k))
     } >>;

% Some rules for quotients of binomials are still missing

algebraic operator stirling1, stirling2;

algebraic
 let {stirling1(~n,~n) => 1,
      stirling1(~n,0)  => 0 when not(n=0),
      stirling1(~n,~n-1) => - binomial(n,2),
      stirling1(~n,~m) => 0 when fixp n and fixp m and n < m,
      stirling1(~n,~m) => (for k:=0:(n-m) sum
                        ( (-1)^k * binomial(n-1+k,n-m+k) *
                          binomial(2*n-m,n-m-k) * stirling2(n-m+k,k)))
                when fixp n and fixp m and n > m,
% This rather naive implementation will cause problem
% when m - n is large !
      stirling2(~n,~n) => 1,
      stirling2(~n,0)  => 0 when not(n=0),
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
        while not(list_of_bincoeff = {}) do
            <<  curr := car list_of_bincoeff;
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

symbolic procedure motzkin(n);

if (n:= reval n)=0 then 1 else if n=1 then 1 else
% ((3*n-3)*Motzkin(n-2) + (2*n+1)* Motzkin(n-1))/(n+2);
if not fixp n or n <0 then
         mk!*sq((list((list('motzkin,n) . 1) . 1)) . 1)
   else begin scalar vsop,oldv,newv;
    newv := oldv :=1;
    for i:=2:n do <<
       vsop := oldv;
       oldv := newv;
       newv:= ((3*i-3) * vsop + (2*i +1)*oldv)/(i+2);
       >>;
    return newv;
end;

flag('(motzkin),'opfn);

endmodule;


module sfpolys;   % Assorted Polynomials
                  % will be a package of its own one day
%
% Author: Winfried Neun, Feb 1993

% Revision 6. April 1995, using explicit formulae for the orthogonal
%                       polynomials (Abramowitz/Stegun 22.3)

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

operator hermitep,jacobip,legendrep,legendreq, !~f,
         laguerrep,chebyshevt,chebyshevu,gegenbauerp;

let limit(~f(~n,~x),~x,~lim) => f(n,lim) when freeof (lim,infinity)
       and member (f,{legendrep,chebyshevt,chebyshevu,hermitep,
              laguerrep,bernoullip,eulerp,laguerrep});

let limit(~f(~n,~m,~x),~x,~lim) => f(n,m,lim) when freeof (lim,infinity)
         and member (f,{legendrep,legendreq,gegenbauerp,laguerrep});

let limit(~f(~n,~m,~mm,~x),~x,~lim) => f(n,m,mm,lim)
      when freeof (lim,infinity) and member (f,{jacobip});

let { % AS (22.4)
legendrep(~n,0,0) => cos(n*pi/2)*factorial(n)/(2^n*(factorial(n/2))^2),
% AS (8.6.1)
legendrep(~n,~m,0) =>
        2^m/sqrt(pi)*cos((n+m)*pi/2)*gamma((n+m+1)/2)/gamma((n-m+2)/2),
% AS (8.6.2)
legendreq(~n,~m,0) =>
        2^(m-1)/sqrt(pi)*sin((n+m)*pi/2)*gamma((n+m+1)/2)
          /gamma((n-m+2)/2),
% AS (8.6.1)
legendrep(~n,0) =>
        1/sqrt(pi)*cos((n)*pi/2)*gamma((n+1)/2)/gamma((n+2)/2),
legendrep(~n,1) => 1,
legendrep(~n,-1) => (-1)^n,

% AS (22.4)
gegenbauerp(~n,0,0) => 2*cos(n*pi/2)/n,
gegenbauerp(~n,~a,0)=> cos(n*pi/2)*gamma(a+n/2)
                                /(gamma(a)*factorial(n/2)),
chebyshevt(~n,0) => cos(n*pi/2),
chebyshevu(~n,0) => cos(n*pi/2),
chebyshevt(~n,1) => 1,
chebyshevu(~n,1) => n + 1 ,
chebyshevt(~n,-1) => (-1)^n,
chebyshevu(~n,-1) => (n+1)* (-1)^n,

laguerrep(~n,~a,0) => binomial(n+a,n),
laguerrep(~n,0) => 1,
hermitep(~n,0) => cos(n*pi/2)*factorial(n)/factorial(n/2) }$

let {hermitep (~n,~x)=> %sub(!=z = x,first reverse hermite_base (!=z,n))
        (factorial n * for ii:=0:floor(n/2) sum ((-1)^ii/(factorial ii *
         factorial(n -2ii)) * (2*x)^(n-2ii)))
                        when fixp n and n > 0,
     hermitep (0,~x)=> 1};

let{ legendrep (~n,~x) =>
                (1/2^n * for ii:=0:floor(n/2) sum (binomial(n,ii) *
                        binomial(2n-2ii,n)*(-1)^ii *x^(n-2ii)))
                        when fixp n and n > 0,
     legendrep (~n,~m,~x) => (-1)^m *(1-x^2)^(m/2)*
                                sub(!=z = x,df(legendrep (n,!=z),!=z,m))
                        when fixp n and n > 0 and fixp m and m > 0,
     jacobip (~n,~a,~b,~x) =>
            (1/2^n * for ii:=0:n sum (binomial(n+a,ii) *
                binomial(n+b,n-ii)*(x-1)^(n-ii)*(x+1)^ii))
                when fixp n and n > 0 and numberp a and a > -1
                and numberp b and b > -1,
     jacobip (~n,~a,~b,~x) => sub(!=z = x
                        ,first reverse legendre_base (!=z,n,a,b))
                        when fixp n and n > 0,
     legendrep (0,~x) => 1,
     legendrep (0,0,~x) => 1,
     jacobip (0,~a,~b,~x) => 1};

let{ laguerrep(~n,~x) =>
          (for ii:=0:n sum (binomial(n,n-ii) *
                 (-1)^ii/factorial ii *x^(ii)))
                        when fixp n and n > 0,
     laguerrep(~n,~a,~x) =>
          (for ii:=0:n sum (binomial(n+a,n-ii) *
                 (-1)^ii/factorial ii *x^(ii)))
                        when fixp n and n > 0,
     laguerrep(0,~a,~x) => 1};

let {chebyshevt (~n,~x) =>
        (n/2*for ii:=0:floor(n/2) sum ((-1)^ii*factorial (n-ii-1) /
         (factorial(ii) *factorial(n -2ii))* (2*x)^(n-2ii)))
                        when fixp n and n > 0,
     chebyshevt (0,~x) => 1};

let {chebyshevu (~n,~x) =>
        (for ii:=0:floor(n/2) sum ((-1)^ii*factorial (n-ii) /
         (factorial(ii) *factorial(n -2ii))* (2*x)^(n-2ii)))
                        when fixp n and n > 0,
     chebyshevu (0,~x) => 1};

let {gegenbauerp (~n,~a,~x) =>
        (1/gamma(a)*for ii:=0:floor(n/2) sum
        ((-1)^ii* gamma(a+n-ii)/(factorial ii *factorial(n-2ii))*
                 (2*x)^(n-2ii))) when fixp n and n > 0 and numberp a
                and a > -1/2 and not(a=0),
     gegenbauerp (~n,0,~x) =>
        (for ii:=0:floor(n/2) sum
        ((-1)^ii* factorial(n-ii-1)/(factorial ii *factorial(n-2ii))*
                 (2*x)^(n-2ii))) when fixp n and n > 0 ,
     gegenbauerp (~n,~a,~x) => sub(!=z = x,
                                first reverse gegenbauer_base(!=z,n,a))
                        when fixp n and n > 0,

     gegenbauerp (0,~a,~x) => 1};

% rules for differentiation

let {% AS (8.5.4)
df(legendrep(~a,~b,~z),z)  => 1/(1-z^2)*
        ((a+b)*legendrep(a-1,b,z) - a*z*legendrep(a,b,z)),
df(legendrep(~n,~z),z) => n/(1-z^2)*(legendrep(n-1,z)-z*legendrep(n,z)),
df(legendreq(~a,~b,~z),z)  => 1/(1-z^2)*
        ((a+b)*legendreq(a-1,b,z) - a*z*legendreq(a,b,z)),
% AS (22.8)
df(jacobip(~n,~a,~b,~z),z) => 1/((1-z^2)*(2*n+a+b))*
        (2*(n+a)*(n+b)*jacobip(n-1,a,b,z)+n*(a-b-(2*n+a+b)*z)
          *jacobip(n,a,b,z)),
df(gegenbauerp(~n,~a,~z),z) => 1/(1-z^2)*
        ((n+2*a-1)*gegenbauerp(n-1,a,z)-n*z*gegenbauerp(n,a,z)),
df(chebyshevt(~n,~z),z) =>
                   1/(1-z^2)*(n*chebyshevt(n-1,z)-n*z*chebyshevt(n,z)),
df(chebyshevu(~n,~z),z) => 1/(1-z^2)*
        ((n+1)*chebyshevu(n-1,z)-n*z*chebyshevu(n,z)),
df(laguerrep(~n,~a,~z),z) =>
        1/z*(-(n+a)*laguerrep(n-1,a,z)+n*laguerrep(n,a,z)),
df(laguerrep(~n,~z),z) => 1/z*(-(n)*laguerrep(n-1,z)+n*laguerrep(n,z)),
df(hermitep(~n,~z),z) => 2*n*hermitep(n-1,z),
% AS (23.1.5)
df(bernoullip(~n,~z),z) => n*bernoullip(n-1,z),
% AS (23.1.5)
df(eulerp(~n,~z),z) => n*eulerp(n-1,z) };
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

  sum((-1)^~k /(2*(~k)-1)^2,~k,1,infinity) =>  - catalan,

  sum((-1)^~k /(2*(~k)+1)^2,~k,0,infinity) =>  catalan,

  sum(1/(2*(~k)-1)^~n,~k,1,infinity) => zeta(n) *(1-2^(-n))
        when fixp n and n > 0 and evenp n,

  sum(1/~k^~s,~k,1,infinity) =>  zeta(s),

  sum((-1)^~k/~k^~n,~k,1,infinity) =>  zeta(n)* (1-2^(1-n))
        when fixp n and n > 0 and evenp n

} >>;

endmodule;


module simpfact;

%  Simplification for quotients containing factorials

%  Matthew Rebbeck ( while in placement at ZIB) - March 1994.

%  The new 'really' improved version! Simplifies plain factorials as
%  well as those raised to integer powers and 1/2.
%
%  Deals properly with the generalised factorial idea of simplifying
%  non integers, eg: (k+1/2)!/(k-1/2)! -> k+1/2.

algebraic <<
operator simplify_factorial1;
operator simplify_factorial;
operator int_simplify_factorial;

let simplify_factorial(~x) => simplify_factorial1(num x,den x);

let { simplify_factorial1(~x,~z) => int_simplify_factorial(x/z)};

let { simplify_factorial1 (~x + ~y,~z) =>
      simplify_factorial1 (x,z) + simplify_factorial1(y,z)};
>>;

symbolic procedure int_simplify_factorial (u);
  begin
    scalar minus_num,minus_denom,test_expt;
    if not pairp u or car u neq 'quotient then u
    else
    <<
      %
      %  We firstly produce input of standard form.
      %
      if atom cadr u or atom caddr u then u
       else <<
        %
        %  Remove 'minus if there.
        %
        if car cadr u eq 'minus then
         << cadr u := cadr cadr u;
            minus_num := t; >>;
        if car caddr u eq 'minus then
         << caddr u := cadr caddr u;
            minus_denom := t; >>;

        if car cadr u eq 'factorial then cadr u := {'times,cadr u};
        if car caddr u eq 'factorial then caddr u := {'times,caddr u};
        if car cadr u eq 'oddexpt or car cadr u eq 'expt
        or car cadr u eq 'sqrt
         then cadr u := {'times,cadr u};
        if car caddr u eq 'oddexpt or car caddr u eq 'expt or
        car caddr u eq 'sqrt
         then caddr u := {'times,caddr u};
        %
        %  Test to see if input contains any 'expt's. If it does
        %  then they are converted to 'oddexpts and re converted
        %  at the end. If not (ie: either contains 'oddexpt's or
        %  no powers at all), then no conversion is done and the
        %  output is left in this oddexpt form.
        %
        if test_for_expt(cadr u) or test_for_expt(caddr u) then
        << test_expt := t;
           convert_to_oddexpt(cadr u);
           convert_to_oddexpt(caddr u); >>;

        if test_for_facts(cadr u,caddr u)
         then gothru_numerator(cadr u,caddr u);

        if minus_num then cadr u := {'minus,cadr u};
        if minus_denom then caddr u := {'minus,caddr u};

        cadr u := reval cadr u;
        caddr u := reval caddr u; >>;
        %
        %  Output converted back to 'expt form regardless of the form
        %  of the input. For this conversion to occur only if input
        %  is in 'expt form (perhaps useful with Wolfram's input)
        %  then uncomment next line...
        %if test_expt then
        u := algebraic sub(oddexpt=expt,u);
      >>;
      return u;
  end;

flag('(int_simplify_factorial),'opfn);



symbolic procedure test_for_expt(input);
  %
  % Tests to see if 'expt occurs anywhere.
  %
  begin
    scalar found_expt,not_found;
    not_found := t;
    while input and not_found do
    <<
      if pairp car input and (caar input = 'expt or caar input = 'sqrt)
       then <<found_expt:=t; not_found:=nil;>>;
      input := cdr input;
    >>;
    return found_expt;
  end;

flag('(test_for_expt),'boolean);



symbolic procedure convert_to_oddexpt(input);
  %
  % Converts all expt's to standard form. ie: oddexpt(......,power).
  %
  begin
    while input do
    <<
      if pairp car input and caar input = 'expt
       then caar input := 'oddexpt;
      if pairp car input and caar input = 'sqrt then
      <<
        caar input := 'oddexpt;
        cdar input := {cadar input,{'quotient,1,2}};
      >>;
      input := cdr input;
    >>;
   end;



symbolic procedure gothru_numerator(num,denom);
  %
  % Go systematically through numerator, searching for factorials, and,
  % when  found,  comparing  with  denominator.  'change'  describes if
  % simplifications have been made or not (ie:change eq 0).
  %
  begin
    scalar change,orignum,origdenom;
    change := 0;
    orignum := num;
    origdenom := denom;
    %
    % while in numerator.
    %
    while num do
    <<
      if pairp car num and caar num eq 'oddexpt then
      <<
        if pairp cadar num and caadar num eq 'factorial then
        change := change + gothru_denominator(num,denom);
      >>
      else if pairp car num and caar num eq 'factorial then
      <<
        change := change + gothru_denominator(num,denom);
      >>;
      num := cdr num;
    >>;
    %
    %  If at end of numerator but simplifications have been made,
    %  then repeat.
    %
    if not num and not eq( change,0) then
    <<
      if test_for_facts(orignum,origdenom)
       then gothru_numerator(orignum,origdenom);  %  Beginning.
    >>;
  end;



symbolic procedure gothru_denominator(num,denom);
  %
  % Systematically  goes  through  denominator  finding  factorials and
  % passing numerator and denom. factorials  into  oddexpt_test.  There
  % they  are  simplified  if  possible.  'Compared'  describes  if the
  % factorials were  simplified (ie: car test eq ok) or if  it was  not
  % possible.
  %
  begin
    scalar test,change;
    change := 0;

    while denom and change = 0 do
    <<
      if pairp car denom and caar denom eq 'oddexpt then
      <<
        if pairp cadar denom and caadar denom eq 'factorial then
        <<
          test := oddexpt_test(num,denom,change);
          change := change + test;
        >>;
      >>
      else if pairp car denom and caar denom eq 'factorial then
      <<
        test := oddexpt_test(num,denom,change);
        change := change + test;
      >>;
      denom := cdr denom;
    >>;
    return change;
  end;



symbolic procedure oddexpt_test(num,denom,change);
  %
  % Tests  which parts of quotient, (if any), are exponentials, passing
  % the quotient onto the relevant simplifying function.
  %
  begin
    scalar test;

    if caar num eq 'oddexpt and caar denom neq 'oddexpt then
    << test := compare_numoddexptfactorial(num,denom,change); >>
    else if caar num neq 'oddexpt and caar denom eq 'oddexpt then
    << test := compare_denomoddexptfactorial(num,denom,change); >>
    else if caar num eq 'oddexpt and caar denom eq 'oddexpt then
    << test := compare_bothoddexptfactorial(num,denom,change); >>
    else test := compare_factorial(num,denom,change);

    return test;
  end;



symbolic procedure compare_factorial (num,denom,change);
  %
  % Compares factorials, simplifying if possible.
  %
  begin
    scalar numsimp,denomsimp,diff;

    %  If both factorial arguments are of the same form.
    if numberp (reval list('difference,cadar (num),cadar(denom))) then
    <<
      change := change + 1;
      %  Difference between num. and denom. factorial arguments.
      diff :=(reval list('difference,cadar (num),cadar(denom)));
      %  If argument of num. factorial > argument of denom. factorial.
      if diff >0 then
      <<
        %  numsimp collects simplified numerator arguments.
        numsimp := for i := 1:diff collect reval {'plus,cadar denom,i};
        %  Remove num. factorial and replace with simplification.
        car num := 'times.numsimp;
        %  Remove denom. factorial.
        car denom := 1;
      >>
      else %  if diff <= 0 then
      <<
        diff := -diff;
        denomsimp := for i := 1:diff collect reval {'plus,cadar num,i};
        car denom := 'times.denomsimp;
        car num := 1;
      >>;
    >>;
    return change;
  end;



symbolic procedure compare_numoddexptfactorial (num,denom,change);
  %
  % Compares  factorials with oddexpt num., simplifying if possible.See
  % compare_factorial for more detailed comments.
  %
  begin
    scalar diff;

    if numberp (reval list('difference,car cdadar num,cadar denom))
    then
    <<
      %  New sqrt additions...
      if sqrt_test(num) then
      <<
        <<
          diff :=(reval list('difference, car cdadar num,cadar denom));
          change := change+1;
          if diff > 0 then simplify_sqrt1(num,denom,diff)
           else simplify_sqrt2(num,denom,diff);
        >>;
      >>
      %  If power is not integer or 1/2 then can't simplify.
      else if not_int_or_sqrt(num) then <<>>
      %  If oddexpt. of power 2.
      else if  caddar num-1  eq 1 then
      <<
        %  Remove oddexpt.
        car num := car {cadar num};
        diff := (reval list('difference,cadar num,cadar denom));
        change :=  change +1;
        if diff > 0 then << simplify1(num,denom,diff); >>
        else simplify2(num,denom,diff);
      >>
      else
      <<
        %  Reduce oddexpt by one.
        car num := {caar num,cadar num,car cddar num -1};
        diff :=(reval list('difference,car cdadar num,cadar denom));
        change :=  change + 1;
        if diff >0 then << simplify1(num,denom,diff); >>
        else simplify2(cdar num,denom,diff);
      >>;
    >>;
    return change;
  end;



symbolic procedure simplify_sqrt1(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,cadar denom,i};
    cadar num := car{'times.numsimp};
    car denom := {'oddexpt,car denom,{'quotient,1,2}};
  end;



symbolic procedure simplify_sqrt2(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,car cdadar num,i};
    car denom := reval {'times,car num,car{'times.denomsimp}};
    car num := 1;
  end;



symbolic procedure simplify1(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,cadar denom,i};
    cdr num := car{'times.numsimp}.cdr num;
    car denom := 1;
  end;



symbolic procedure simplify2(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,cadar num,i};
    cdr denom := car{'times.denomsimp}.cdr denom;
    car denom := 1;
  end;



symbolic procedure compare_denomoddexptfactorial (num,denom,change);
  %
  % Compares factorials with oddexpt denom, simplifying if possible.See
  % compare_factorial and compare_numoddexptfactorial for more detailed
  % comments.
  %
  begin
    scalar change,diff;

    if numberp (reval list('difference, cadar num,car cdadar denom))
    then
    <<
      %  New sqrt additions...
      if sqrt_test(denom) then
      <<
        <<
          diff :=(reval list('difference, cadar num,car cdadar denom));
          change := change+1;
          if diff > 0 then simplify_sqrt3(num,denom,diff)
          else  %  if diff <= 0
          simplify_sqrt4(num,denom,diff);
        >>;
      >>
      else if not_int_or_sqrt(denom) then <<>>
      else if caddar denom-1  eq 1 then
      <<
        car denom := car {cadar denom};
        diff := (reval list('difference,cadar num,cadar denom));
        change := change +1;
        if diff > 0 then simplify3(num,denom,diff)
        else  %  if diff <= 0 then
        simplify4(num,denom,diff);
      >>
      else
      <<
        car denom := {caar denom,cadar denom,car cddar denom -1};
        diff :=(reval list('difference, cadar num,car cdadar denom));
        change := change + 1;
        if diff >0 then simplify3(num,cdar denom,diff)
        else simplify4(num,denom,diff);
      >>;
    >>;
    return change;
  end;



symbolic procedure sqrt_test(input);
  %
  % tests if the expt power is 1/2. (boolean)
  %
  begin
    if caddar input = '(quotient 1 2) then return t
     else return nil;
  end;

flag('(sqrt_test),'boolean);



symbolic procedure not_int_or_sqrt(input);
  %
  % tests if the expt power is neither int or 1/2. (boolean)
  %
  begin
    if pairp caddar input and car caddar input = 'quotient
    and cdr caddar input neq '(1 2) then return t
     else return nil;
  end;

flag('(not_int_or_sqrt),'boolean);



symbolic procedure simplify_sqrt3(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,car cdadar denom,i};
    car num := reval{'times,car denom,car{'times.numsimp}};
    car denom := 1;
  end;



symbolic procedure simplify_sqrt4(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,cadar num,i};
    if diff = 0 then car denom := 1
     else cadar denom := car{'times.denomsimp};
    car num := {'oddexpt,car num,{'quotient,1,2}};
  end;



symbolic procedure simplify3(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,cadar denom,i};
    cdr num := car{'times.numsimp}.cdr num;
    car num := 1;
  end;



symbolic procedure simplify4(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,cadar num,i};
    cdr denom := car{'times.denomsimp}.cdr denom;
    car num := 1;
  end;



symbolic procedure compare_bothoddexptfactorial (num,denom,change);
  %
  % Compares factorials with both oddexpt num. & denom., simplifying if
  % possible. See previous compare_...... functions  for  more detailed
  % comments.
  %
  begin
    scalar change,diff;

    if numberp(reval list('difference,car cdadar num,car cdadar denom))
    then
    <<
      %  New sqrt additions...
      if sqrt_test(num) and sqrt_test(denom) then
      <<
        <<
          diff :=(reval list('difference, car cdadar num,car cdadar
                  denom));
          change := change+1;
          if diff > 0 then simplify_sqrt5(num,denom,diff)
           else  %  if diff <= 0
           simplify_sqrt6(num,denom,diff);
        >>;
      >>
      else if not_int_or_sqrt(num) or not_int_or_sqrt(denom) then <<>>
      %  If denom is sqrt but num is not.
      else if sqrt_test(denom) then
      <<
        diff := reval list('difference,cadr cadar num,cadr cadar denom);
        if diff > 0 then simplify_sqrt5(num,denom,diff)
         else  %  if diff <= 0 then
         simplify_sqrt6(num,denom,diff);
      >>
      %  If num is sqrt but denom is not.
      else if sqrt_test(num) then
      <<
        diff := reval list('difference,cadr cadar num,cadr cadar denom);
        if diff > 0 then simplify_sqrt7(num,denom,diff)
         else  %  if diff <= 0 then
         simplify_sqrt8(num,denom,diff);
      >>
      else if caddar num-1 eq 1 and caddar denom-1 eq 1 then
      <<
        car num := car {cadar num};
        car denom := car {cadar denom};
        diff := (reval list('difference,cadar num,cadar denom));
        change := change +1;
        if diff > 0 then simplify5(num,denom,diff)
         else  %  if diff <= 0 then
         simplify6(num,denom,diff);
      >>
      else if caddar num-1 eq 1 and caddar denom-1 neq 1 then
      <<
        car num := car {cadar num};
        car denom := {caar denom,cadar denom,car cddar denom-1};
        diff := (reval list('difference,cadar num,car cdadar denom));
        change := change +1;
        if diff >0 then simplify5(num,cdar denom,diff)
         else  %  if diff <= 0 then
         simplify6(num,denom,diff);
      >>
      else if caddar num-1 neq 1 and caddar denom-1 eq 1 then
      <<
        car num := {caar num,cadar num,car cddar num-1};
        car denom := car {cadar denom};
        diff := (reval list('difference,car cdadar num,cadar denom));
        change := change +1;
        if diff >0 then simplify5(num,denom,diff)
        else simplify6(cdar num,denom,diff);
      >>
      else if caddar num-1 neq 1 and caddar denom-1 neq 1 then
      <<
        car num := {caar num,cadar num,car cddar num-1};
        car denom := {caar denom,cadar denom,car cddar denom-1};
        diff:=(reval list('difference,car cdadar num,car cdadar denom));
        change := change +1;
        if diff >0 then simplify5(num,cdar denom,diff)
        else simplify6(cdar num,denom,diff);
      >>;
    >>;
    return change;
  end;



symbolic procedure simplify_sqrt5(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,car cdadar denom,i};
    car num := {'times,{'oddexpt,cadar denom,{'plus,caddar num,
               {'minus,{'quotient,1,2}}}},{'oddexpt,car{'times.numsimp},
               caddar num}};
    car denom := 1;
  end;



symbolic procedure simplify_sqrt6(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,car cdadar num,i};
    car denom := {'oddexpt,car{'times.denomsimp},{'quotient,1,2}};
    caddar num := {'plus,caddar num,{'minus,{'quotient,1,2}}};
  end;



symbolic procedure simplify_sqrt7(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,car cdadar denom,i};
    car num := {'oddexpt,car{'times.numsimp},{'quotient,1,2}};
    caddar denom := {'plus,caddar denom,{'minus,{'quotient,1,2}}};
  end;



symbolic procedure simplify_sqrt8(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,car cdadar num,i};
    car denom:= {'times,{'oddexpt, cadar num,{'plus,caddar denom,
             {'minus,{'quotient,1,2}}}},{'oddexpt,car{'times.denomsimp},
              caddar denom}};
    car num := 1;
  end;



symbolic procedure simplify5(num,denom,diff);
  begin
    scalar numsimp;
    numsimp := for i := 1:diff collect reval {'plus,cadar denom,i};
    cdr num := car{'times.numsimp}.cdr num;
  end;



symbolic procedure simplify6(num,denom,diff);
  begin
    scalar denomsimp;
    diff := -diff;
    denomsimp := for i := 1:diff collect reval {'plus,cadar num,i};
    cdr denom := car{'times.denomsimp}.cdr denom;
  end;



symbolic procedure test_for_facts(num,denom);
  %
  % Systematically goes through numerator and then  denom. looking  for
  % factorials.
  % (boolean).
  %
  begin
    scalar test;
    if test_num(num) and test_denom(denom) then test := t;
    return test
  end;

flag('(test_for_facts),'boolean);



symbolic procedure test_num(num);
  %
  % Systematically goes through num., looking for  factorials.
  % (boolean).
  %
  begin
    scalar test;
    test := nil;
    if eqcar (num ,'times) or eqcar (num ,'oddexpt) then
     while num and not test do
     <<
       if pairp car num and caar num eq 'factorial then test := t
        else if pairp car num and caar num eq 'oddexpt
         then if pairp cadar num and caadar num eq 'factorial
          then test := t;
       num := cdr num;
     >>;
    return test;
  end;

flag ('(test_num),'boolean);



symbolic procedure test_denom(denom);
  %
  % Systematically goes through denominator,  looking  for  factorials.
  % (boolean).
  %
  begin
    scalar test;
    test := nil;
    if eqcar (denom ,'times) or eqcar (denom ,'oddexpt) then
    while denom and not test do
    <<
      if pairp car denom and caar denom eq 'factorial then test := t
       else if pairp car denom and caar denom eq 'oddexpt
        then if pairp cadar denom and caadar denom eq 'factorial
         then test := t;
       denom:= cdr denom;
     >>;
    return test;
  end;

flag ('(test_denom),'boolean);

endmodule;


module harmonic; % Solid & spherical harmonics.

% Author: Matthew Rebbeck, ZIB.
% Advisor: Rene' Grognard.

% Date:   March 1994

% Version 0 (experimental)

% Solid Harmonics of order n (Laplace polynomials)
% are homogeneous polynomials of degree n in x,y,z
% which are solutions of Laplace equation:-

%       df(P,x,2) + df(P,y,2) + df(P,z,2) = 0.

% There are 2*n+1 independent such polynomials for any given n >=0
% and with:-

%       w!0 = z, w!+ = i*(x-i*y)/2, w!- = i*(x+i*y)/2,

% they are given by the Fourier integral:-

% S(n,m,w!-,w!0,w!+) =

%       (1/(2*pi)) *
%       for u:=-pi:pi integrate (w!0 + w!+ * exp(i*u) + w!- *
%           exp(-i*u))^n * exp(i*m*u) * du;

% which is obviously zero if |m| > n since then all terms in the
% expanded integrand contain the factor exp(i*k*u) with k neq 0,

% S(n,m,x,y,z) is proportional to
%     r^n * Legendre(n,m,cos theta) * exp(i*phi)

% Let r2 = x^2 + y^2 + z^2 and r = sqrt(r2).

% The spherical harmonics are simply the restriction of the solid
% harmonics to the surface of the unit sphere and the set of all
% spherical harmonics {n >=0; -n <= m =< n} form a complete orthogonal
% basis on it, i.e. <n,m|n',m'> = Kronecker_delta(n,n') *
% Kronecker_delta(m,m') using <...|...> to designate the scalar product
% of functions over the spherical surface.

% The coefficients of the solid harmonics are normalised in what
% follows to yield an ortho-normal system of spherical harmonics.

% Given their polynomial nature, there are many recursions formulae
% for the solid harmonics and any recursion valid for Legendre functions
% can be 'translated' into solid harmonics. However the direct proof is
% usually far simpler using Laplace's definition.

% It is also clear that all differentiations of solid harmonics are
% trivial, qua polynomials.

% Some substantial reduction in the symbolic form would occur if one
% maintained throughout the recursions the symbol r2 (r cannot occur
% as it is not rational in x,y,z). Formally the solid harmonics appear
% in this guise as more compact polynomials in (x,y,z,r2).

% Only two recursions are needed:-

% (i) along the diagonal (n,n);

% (ii) along a line of constant n: (m,m),(m+1,m),...,(n,m).

% Numerically these recursions are stable.

% For m < 0 one has:-

%       S(n,m,x,y,z) = (-1)^m * S(n,-m,x,-y,z);

algebraic procedure solidharmonicy(n,m,x,y,z,r2);
begin scalar mp, v, y0, y1, y2;

 if not (fixp(n) and fixp(m)) then  return
    rederr " SolidHarmonicY : n and m must be integers";
 if (n < 0) then return 0;
 mp := abs(m);
 if (n < mp ) then return 0;
 y0 := 1/sqrt(4*pi);
 if (n = 0) then return y0;
 if (mp > 0) then
 << if m > 0 then v:=x+i*y else v:=x-i*y;
  for k:=1:mp do y0 := - sqrt((2*k+1)/(2*k))*v*y0;
  if (n > mp) then <<
   k := mp + 1;
   y1 := y0;
   y0 := z*sqrt(2*k+1)*y1;
   if (n > mp + 1) then for k:=mp+2:n do <<
            y2 := y1;
            y1 := y0;
            y0 := z*sqrt((4*k*k-1)/(k*k-mp*mp))*y1
                   -r2*sqrt(((2*k+1)*(k-mp-1)*(k+mp-1))/
                   ((2*k-3)*(k*k-mp*mp)))*y2 >>;
                  >>;
 >> else << y1 := y0;
            y0 := z*sqrt(3)*y1;
            if n > 1 then for k:=2:n do <<
                   y2 := y1;
                   y1 := y0;
                   y0 := ( z*sqrt(4*k*k-1)*y1 - r2*(k-1)*
                         sqrt((2*k+1)/(2*k-3))*y2)/k >>;
         >>;
 if m < 0 and not evenp mp then y0 := - y0;
 return y0
end;

algebraic procedure sphericalharmonicy(n,m,theta,phi);
        solidharmonicy(n,m,sin(theta)*cos(phi),
                sin(theta)*sin(phi),cos(theta),1)$

endmodule;


module jsymbols;

% Author: Matthew Rebbeck, ZIB.
% Advisor: Rene' Grognard.

% Date:   March 1994

% Version 1 (experimental code for the symbolic 6j symbol)
%            by Winfried Neun (ZIB) email: neun@zib-berlin.de

% ThreeJSymbol with reasoning on the input for optimal computing;
% Note: the code is 'pedestrian' but should be transparent and it
% seems to work !
% It reflects strongly the exploratory code I used to orientate myself
% It should be rewritten in a more 'professional' style;

load!-package 'matrix;   % Needed for matrix input.
load!-package 'solve;
load!-package 'ineq;

symbolic procedure clean_up_sqrt(input);
  %
  %  Takes input and factorises out all sqrt's.
  %
  begin
    scalar num,denom,answer;
    if not pairp input or car input neq 'quotient then answer := input
     else <<
      num := cadr input;
      denom := caddr input;
      num := collect_sqrt(num);
      denom := collect_sqrt(denom);
      answer := {'quotient,num,denom}; >>;
    return answer;
  end;

flag('(clean_up_sqrt),'opfn);


symbolic procedure collect_sqrt(input);
  %
  %  Cleans up a series of multiplied sqrt's.
  %  eg: sqrt(x)*sqrt(y)->sqrt_of(x*y).
  %
  begin
    scalar sqrt_args,extra_bit,minust,answer;
    sqrt_args := {}; extra_bit := {};
    if not pairp input then answer := input
     else <<
      if car input = 'minus then
                <<minust := t;
                  if pairp cadr input then input := cadr input
                                        else return input
                >>;
      if car input='times then input := cdr input else input := {input};
      for each elt in input do

      << if eqcar(elt,'sqrt)
          then sqrt_args := append(sqrt_args,{cadr elt})
           else extra_bit := append(extra_bit,{elt}); >>;
    if sqrt_args = {} then <<answer := extra_bit;>>
     else <<
       sqrt_args:=reval append({'sqrt_of},{append({'times},sqrt_args)});
       answer := append({sqrt_args},extra_bit); >>;
     answer := append({'times},answer);
    if minust then answer := {'minus,answer}; >>;
    return answer;

end;

symbolic operator listp;

algebraic operator sqrt_of, oddexpt;

algebraic << let sqrt_of(~x) => sqrt (x) when numberp x >>;


algebraic procedure threejsymbol (u1,u2,u3);
 if listp u1 and listp u2 and listp u3 then
  begin
   scalar j1,j2,j3,m1,m2,m3,tmp,lower,upper,better,best;
   matrix range(6,2);
   j1:=first u1; m1:=second u1;
   j2:=first u2; m2:=second u2;
   j3:=first u3; m3:=second u3;

   % Vanishing conditions;

   if numberp(tmp:=m1+m2+m3) and tmp neq 0 then return 0
   else if numberp(tmp:=j1+j2+j3) and tmp < -1 then return 0
   else if numberp(tmp:=j1+j2-j3) and tmp < 0 then return 0
   else if numberp(tmp:=j1-j2+j3) and tmp < 0 then return 0
   else if numberp(tmp:=j2+j3-j1) and tmp < 0 then return 0
   else if numberp(tmp:=j1+m1) and tmp < 0 then return 0
   else if numberp(tmp:=j1-m1) and tmp < 0 then return 0
   else if numberp(tmp:=j2+m2) and tmp < 0 then return 0
   else if numberp(tmp:=j2-m2) and tmp < 0 then return 0
   else if numberp(tmp:=j3+m3) and tmp < 0 then return 0
   else if numberp(tmp:=j3-m3) and tmp < 0 then return 0
   else

   % Restrictions on k

   <<range:=mat((0,infinity),
                (0,infinity),
                (0,infinity),
                (0,infinity),
                (0,infinity),
                (0,infinity));
     % as is;

     lower:=range(1,1);upper:=range(1,2);
     if numberp(tmp:=j1+j2-j3) then upper:=tmp;
     if numberp(tmp:=j1-m1) then
           if upper = infinity then upper:=tmp
            else upper:=min(upper,tmp);
     if numberp(tmp:=j2+m2) then
           if upper = infinity then upper:=tmp
            else upper:=min(upper,tmp);
     if numberp(tmp:=j3+j2+m1) then lower = max(lower,-tmp);
     if numberp(tmp:=j2-j1-m2) then lower = max(lower,-tmp);
     range(1,1):=lower;range(1,2):=upper;
     if upper = infinity then <<better:=upper;best:=0>>
     else <<better:=upper-lower+1;best:=1>>;

     % {j1,m1} <-> {j2,m2};

     lower:=range(2,1);upper:=range(2,2);
     if numberp(tmp:=j2+j1-j3) then upper:=tmp;
     if numberp(tmp:=j2-m2) then
                 if upper = infinity then
                         upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j1+m1) then
                 if upper = infinity then
                         upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j3+j1+m2) then lower = max(lower,-tmp);
     if numberp(tmp:=j1-j2-m1) then lower = max(lower,-tmp);
     range(2,1):=lower;range(2,2):=upper;
     if upper neq infinity then
      << tmp:=upper-lower+1;
      if (better = infinity) or (better > tmp) then
                         << better:=tmp;best:=2 >> >>;

     % {j1,m1} <-> {j3,m3};

     lower:=range(3,1);upper:=range(3,2);
     if numberp(tmp:=j3+j2-j1) then upper:=tmp;
     if numberp(tmp:=j3-m3) then
                if upper = infinity then
                         upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j2+m2) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j1+j2+m3) then lower = max(lower,-tmp);
     if numberp(tmp:=j2-j3-m2) then lower = max(lower,-tmp);
     range(3,1):=lower;range(3,2):=upper;
     if upper neq infinity then
      << tmp:=upper-lower+1;
      if (better = infinity) or (better > tmp) then
                 << better:=tmp;best:=3 >> >>;

     % {j2,m2} <-> {j3,m3};

     lower:=range(4,1);upper:=range(4,2);
     if numberp(tmp:=j1+j3-j2) then upper:=tmp;
     if numberp(tmp:=j1-m1) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j3+m3) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j2+j3+m1) then lower = max(lower,-tmp);
     if numberp(tmp:=j3-j1-m3) then lower = max(lower,-tmp);
     range(4,1):=lower;range(4,2):=upper;
     if upper neq infinity then
      << tmp:=upper-lower+1;
      if (better = infinity) or (better > tmp) then
                         << better:=tmp;best:=4 >> >>;

     % {j1,m1} -> {j2,m2} -> {j3,m3} -> {j1,m1};

     lower:=range(5,1);upper:=range(5,2);
     if numberp(tmp:=j2+j3-j1) then upper:=tmp;
     if numberp(tmp:=j2-m2) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j3+m3) then
                if upper = infinity
                        then upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j1+j3+m2) then lower = max(lower,-tmp);
     if numberp(tmp:=j3-j2-m3) then lower = max(lower,-tmp);
     range(5,1):=lower;range(5,2):=upper;
     if upper neq infinity then
      << tmp:=upper-lower+1;
      if (better = infinity) or (better > tmp) then
                         << better:=tmp;best:=5 >> >>;

     % {j1,m1} -> {j3,m3} -> {j2,m2} -> {j1,m1};

     lower:=range(6,1);upper:=range(6,2);
     if numberp(tmp:=j3+j1-j2) then upper:=tmp;
     if numberp(tmp:=j3-m3) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j1+m1) then
                if upper = infinity then
                        upper:=tmp else upper:=min(upper,tmp);
     if numberp(tmp:=j2+j1+m3) then lower = max(lower,-tmp);
     if numberp(tmp:=j1-j3-m1) then lower = max(lower,-tmp);
     range(6,1):=lower;range(6,2):=upper;
     if upper neq infinity then
      << tmp:=upper-lower+1;
      if (better = infinity) or (better > tmp) then
                << better:=tmp;best:=6 >> >>;

     if best = 1 then return !*3j!-symbol!:sign!*(j1-j2-m3)
      * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j1,j2,j3,m1,m2,m3)
           else  - !*3j!-symbol!:one!-term!*(k,j1,j2,j3,m1,m2,m3))

     else if best = 2 then
        return !*3j!-symbol!:sign!*((j1+j2+j3)+j2-j1-m3)
         * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j2,j1,j3,m2,m1,m3)
           else  - !*3j!-symbol!:one!-term!*(k,j2,j1,j3,m2,m1,m3))

     else if best = 3 then
        return !*3j!-symbol!:sign!*((j1+j2+j3)+j3-j2-m1)
         * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j3,j2,j1,m3,m2,m1)
           else  - !*3j!-symbol!:one!-term!*(k,j3,j2,j1,m3,m2,m1))

     else if best = 4 then
        return !*3j!-symbol!:sign!*((j1+j2+j3)+j1-j3-m2)
         * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j1,j3,j2,m1,m3,m2)
           else - !*3j!-symbol!:one!-term!*(k,j1,j3,j2,m1,m3,m2))

     else if best = 5 then
        return !*3j!-symbol!:sign!*(j2-j3-m1) * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j2,j3,j1,m2,m3,m1)
           else - !*3j!-symbol!:one!-term!*(k,j2,j3,j1,m2,m3,m1))

     else if best = 6 then
        return !*3j!-symbol!:sign!*(j3-j1-m2) * clean_up_sqrt(
         for k:=range(best,1):range(best,2) sum
          if evenp(k)
            then !*3j!-symbol!:one!-term!*(k,j3,j1,j2,m3,m1,m2)
           else  - !*3j!-symbol!:one!-term!*(k,j3,j1,j2,m3,m1,m2))

     else return lisp lpri list("ThreeJSymbol({",
                               second u1,",",third u1,
                               "},{",
                               second u2,",",third u2,
                               "},{",
                               second u3,",",third u3,
                               "}) % symbol best left as is;")
   >>
  end
 else
  " the argument must be of the form: {j1,m1},{j2,m2},{j3,m3}"$

algebraic procedure !*3j!-symbol!:sign!* u;
   if rounded then (-1)^u else (-1)^(remainder(num u,2*den u)/(den u))$

algebraic procedure !*3j!-symbol!:one!-term!*(k,j1,j2,j3,m1,m2,m3);
 sqrt(simplify_factorial(
  (  factorial(j1+j2-j3)
    *factorial(j3+j1-j2)
    *factorial(j2+j3-j1)
    *factorial(j1+m1)
    *factorial(j1-m1)
    *factorial(j2+m2)
    *factorial(j2-m2)
    *factorial(j3+m3)
    *factorial(j3-m3)
  )/(factorial(j1+j2+j3+1)
    *(factorial(k)
     *factorial(j1+j2-j3-k)
     *factorial(j3-j2+m1+k)
     *factorial(j3-j1-m2+k)
     *factorial(j1-m1-k)
     *factorial(j2+m2-k)
     )^2
  )
 ))$

algebraic <<

 operator clebsch_gordan;

 let clebsch_gordan({~j1,~m1},{~j2,~m2},{~j3,~m3}) =>
        threejsymbol ({~j1,~m1},{~j2,~m2},{~j3,~m3}) *
        (2*j3+1)^(1/2) * (-1)^(-(j1-j2-m3));

% The 6 J symbol
% The naming of the functions follows Landolt-Boernstein

operator sixjsymbol;

let { sixjsymbol({~j1,~j2,~j3} , {~l1,~l2,~l3}) =>
       (begin scalar nnn,mmm,!*factor,!*exp,signum;
       % necessary conditions for existence

       if (necess_6j (j1,j2,j3,l1,l2,l3) = nil) then return nil;
       on factor;
       mmm := racah_w(j1,j2,j3,l1,l2,l3);
       nnn :=
        square_racah_delta(j1,j2,j3) * square_racah_delta(j1,l2,l3)*
        square_racah_delta(l1,j2,l3) * square_racah_delta(l1,l2,j3)
        * mmm^2;
       nnn := simplify_factorial (nnn);
       signum := sign mmm;
       if numberp signum then return (sign mmm * sqrt nnn)
          else return sqrt nnn; end)};

procedure square_racah_delta(a,b,c);
  simplify_factorial(factorial(a+b-c) *factorial(a-b+c)
                * factorial(-a +b +c) / factorial (a + b + c +1));

procedure racah_w(j1,j2,j3,l1,l2,l3);
 begin scalar mini,maxi,interv;

    mini := min(j1+j2+l1+l2,j2+j3+l2+l3,j3+j1+l3+l1);
    maxi := max(0,j1+j2+j3,j1+l2+l3,l1+j2+l3,l1+l2+j3);

  aaa:
    if numberp (mini - maxi) then
        return for k:=maxi:mini sum
               ((-1)^k*simplify_factorial (factorial (k+1) /
               (factorial (k-j1-j2-j3)*
                factorial (k-j1-l2-l3) *
                factorial (k-l1-j2-l3) *
                factorial (k-l1-l2-j3)*
                factorial (j1+j2+l1+l2-k)*
                factorial (j2+j3+l2+l3-k)*
                factorial (j3+j1+l3+l1-k))))
        else <<
             interv :=findinterval (j1,j2,j3,l1,l2,l3);
             if interv = {} then
              return
               sum((-1)^k* simplify_factorial
                (factorial (k+1) /
               (factorial (k-j1-j2-j3)*
                factorial (k-j1-l2-l3) *
                factorial (k-l1-j2-l3) *
                factorial (k-l1-l2-j3)*
                factorial (j1+j2+l1+l2-k)*
                factorial (j2+j3+l2+l3-k)*
                factorial (j3+j1+l3+l1-k))),k,maxi,mini)
             else        <<
               maxi := first first interv;
               mini := second first interv + maxi;
               go to aaa >>;
            >>;
 end;

% conditions for non vanishing 6j symbol see Landolt/Boernstein

procedure necess_6j(j1,j2,j3,l1,l2,l3);

 begin scalar nnn, !*rounded, dmode!*;
     off rounded;
     nnn := j1 + j2 + j3;
     if (numberp nnn) then if not fixp nnn then return nil;
     nnn := l1 + l2 + j3;
     if (numberp nnn) then if not fixp nnn then return nil;
     nnn := j1 + l2 +l3;
     if (numberp nnn) then if not fixp nnn then return nil;
     nnn := l1 + j2 +l3;
     if (numberp nnn) then if not fixp nnn then return nil;

     if not numberp j1 or  not numberp j2 or  not numberp j3
        or not numberp l1 or not numberp l2 or not numberp l3
        then return t; % don't know

 % Triangle condtions

     if  j1 + j2 - j3 >=0 and   j1 - j2 + j3 >=0 and
        -j1 + j2 + j3 >=0 and   l1 + l2 - j3 >=0 and
         l1 - l2 + j3 >=0 and  -l1 + l2 + j3 >=0 and
         j1 + l2 - l3 >=0 and   j1 - l2 + l3 >=0 and
        -j1 + l2 + l3 >=0 and   l1 + j2 - l3 >=0 and
         l1 - j2 + l3 >=0 and  -l1 + j2 + l3 >=0 then return t;
    end;

procedure aconds!-6j(j1,j2,j3,l1,l2,l3);

   { % Triangle condtions
     j1 + j2 - j3 >=0,      j1 - j2 + j3 >=0,
    -j1 + j2 + j3 >=0,
     l1 + l2 - j3 >=0,      l1 - l2 + j3 >=0,
    -l1 + l2 + j3 >=0,
     j1 + l2 - l3 >=0,      j1 - l2 + l3 >=0,
    -j1 + l2 + l3 >=0,
     l1 + j2 - l3 >=0,      l1 - j2 + l3 >=0,
    -l1 + j2 + l3 >=0,

     % condtions for the summation index

     !=k +1 >= 0,
     !=k-j1-j2-j3 >=0,
     !=k-j1-l2-l3 >=0,
     !=k-l1-j2-l3 >=0,
     !=k-l1-l2-j3 >=0,
     j1+j2+l1+l2-!=k >=0,
     j2+j3+l2+l3-!=k >=0,
     j3+j1+l3+l1-!=k >=0};

% same in Edmonds formulation

procedure conds!-6j(j1,j2,j3,l1,l2,l3);

   { % Triangle condtions
     j1 + j2 - j3 >=0,      j1 - j2 + j3 >=0,
    -j1 + j2 + j3 >=0,
     l1 + l2 - j3 >=0,      l1 - l2 + j3 >=0,
    -l1 + l2 + j3 >=0,
     j1 + l2 - l3 >=0,      j1 - l2 + l3 >=0,
    -j1 + l2 + l3 >=0,
     l1 + j2 - l3 >=0,      l1 - j2 + l3 >=0,
    -l1 + j2 + l3 >=0,

     % condtions for the summation index

     !=k >= 0,
     j1 + j2 + l1 + l2 + 1 -!=k >=0,
     j1 + j2 -j3 -!=k >=0,
     l1 + l2 - j3 -!=k >=0,
     j1 + l2 - l3 -!=k >=0,
     l1 + j2 -l3 -!=k >=0,
    -j1 -l1 + j3 + l3 + !=k >=0,
    -j2 -l2 + j3 + l3 + !=k >=0};

% conditions for non vanishing 3j symbol see Landolt/Boernstein

procedure conds!-3j (j1,j2,j3,m1,m2,m3);

 { m1 + m2 + m3 =0,
   j1 + j2 - j3 >=0,
   j1 - j2 + j3 >=0,
  -j1 + j2 + j3 >=0,
   !=k >=0,
   j1 + j2 -j3 -!=k >=0,
   j1 - m1 -!=k >=0,
   j3 + m2 -!=k >=0,
   j3 -j2 + m1 + !=k >=0,
   j3 - j1 -m2 + !=k >=0};

% Trying to find the approroate intervals for the summation in the
% 6j symbol computation using the ineq package by Herbert Melenk

procedure findinterval(j1,j2,j3,l1,l2,l3);
 begin scalar interv,svars;
  svars := lisp( 'list .
                solvevars list(simp j1,simp j2,simp j3,
                                simp l1, simp l2,simp l3));
  interv :=reverse
                ineq_solve(aconds!-6j(j1,j2,j3,l1,l2,l3)
                        ,!=k . svars,record=t);
  return findinterval1(part(first interv),0);
 end;
>>;

symbolic procedure findinterval1(maxis,minis);
(<<
  if eqcar(maxis,'equal) and cadr maxis eq '!=k then
      maxis := caddr maxis;

  if not eqcar(maxis,'!*interval!*) then
         list('list,list('list,maxis , 0))
  else <<
  minis := caddr maxis;
  maxis := cadr maxis;
  if eqcar(maxis,'max) then
                 maxis := cdr maxis else maxis := list maxis;
  if eqcar(minis,'min) then
                 minis := cdr minis else minis := list minis;
  foreach xx in maxis do
     foreach yy in minis do
        if numberp (difff :=reval list('difference,yy,xx)) then
                fixedints := {'list,xx,difff} . fixedints;
  'list  . fixedints
      >>
 >>) where fixedints = nil , difff = nil;

flag('(findinterval1),'opfn);

symbolic procedure fancy!-clebsch_gordon(u);
  begin scalar a,j1,m1,j2,m2,j,m;
    u:=cdr u; j1:=cadr car u; m1:=caddr car u;
    u:=cdr u; j2:=cadr car u; m2:=caddr car u;
    u:=cdr u; j :=cadr car u; m :=caddr car u;
    a:={j1,m1,j2,m2,'!|,j1,j2,j,m};
    return fancy!-in!-brackets(
       {'fancy!-inprint, mkquote 'times,0,mkquote a},
         '!(,'!));
  end;

put('clebsch_gordon,'fancy!-prifn, 'fancy!-clebsch_gordon);

symbolic procedure fancy!-threejsymbol(u);
     fancy!-matpri2({cdr cadr u,cdr caddr u},nil,nil);

put('threejsymbol,'fancy!-prifn, 'fancy!-threejsymbol);

symbolic procedure fancy!-sixjsymbol(u);
     fancy!-matpri2({cdr cadr u,cdr caddr u},nil,'("{" . "}"));

put('sixjsymbol,'fancy!-prifn, 'fancy!-sixjsymbol);

symbolic procedure fancy!-ninejsymbol(u);
     fancy!-matpri2({cdr cadr u,cdr caddr u, cdr cadddr u},nil,
          '("{" . "}"));

put('ninejsymbol,'fancy!-prifn, 'fancy!-ninejsymbol);

endmodule;


module recsimpl; % Simplification of expressions involving recursions
                 % for special functions.

% Wolfram Koepf, ZIB Berlin , May 1994

% Reduce version (developed from the Maple version) by Winfried Neun.
% Examples can be found in $reduce/xmpl/specfmor.tst

fluid '(spec_nnnnn);

flag ('(spec_check_n),'boolean);

algebraic procedure trim (u);

  if u = {} then {} else
      if member(first u,rest u) then trim rest u
         else first u . trim rest u;

algebraic procedure adelete (v,u);

  if u = {} then {} else
      if v = first u then adelete(v, rest u)
         else first u . adelete(v, rest u);

algebraic procedure recursionsimplify (ex);

begin scalar eqq,l1,l2,l3,l4,l5,f,nargs,n,a,x,kern;

  eqq := ex;
  lisp (kern := union (kernels !*q2f  (numr simp eqq ./ 1),
                        kernels !*q2f (denr simp eqq ./ 1)));

  l1 := 'list . lisp  foreach k in kern join if atom k then nil else
                                list k;
  l2 := 'list . lisp foreach k in kern join if atom k then nil else
                                list (car k , -1 + length k);

  while not(l2 = {}) do <<

        f:=  first l2; l2 := rest l2;
        nargs := first l2; l2 := rest l2;
        l3 := foreach kk in l1 join
                 if part(kk,0) = f  and
                         lisp equal(-1 + length (prepsq cadr kk),nargs)
                 then list kk else list ('list);
       l4:= foreach kk in l3 collect lisp ('list . cddr prepsq cadr kk);
       l4 := trim l4;
       foreach kkk in l4 do  <<
          l5 := foreach kkkk in l3 join
                if kkk = lisp ('list . cddr prepsq cadr kkkk)
                then lisp list('list , cadr prepsq cadr kkkk)
                        else {};
         while length l5 > 2 do <<
                n := max(l5);
                if member(n-1,l5) and member(n-2,l5) then
                   <<   spec_nnnnn:= n;
                        let spec_recrules;
                        eqq := eqq;
                        spec_nnnnn:= nil;
                        clearrules spec_recrules;
                   >>;
                l5 := adelete(n,l5);

                >>; >>; >>;
return eqq;
  end;

algebraic procedure spec_check_n(n);
   if n = spec_nnnnn then t else nil;


algebraic (
spec_recrules :={
% AS (9.1.27)

besselj(~n,~z) => - besselj(n-2,z) + (2*(n-1)/z)*besselj(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

bessely(~n,~z) => - bessely(n-2,z) + (2*(n-1)/z)*bessely(n-1,z)
when spec_check_n(n),
% AS (9.6.26)

besseli(~n,~z) => besseli(n-2,z) - (2*(n-1)/z)*besseli(n-1,z)
when spec_check_n(n),
% AS (9.6.26)

besselk(~n,~z) => besselk(n-2,z) + (2*(n-1)/z)*besselk(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

hankel1(~n,~z) => - hankel1(n-2,z) + (2*(n-1)/z)*hankel1(n-1,z)
when spec_check_n(n),
% AS (9.1.27)

hankel2(~n,~z) => - hankel2(n-2,z) + (2*(n-1)/z)*hankel2(n-1,z)
when spec_check_n(n),
% AS (13.4.2)

kummerm(~a,~b,~z) => 1/(a-1)*
        ((b-a+1)*kummerm(a-2,b,z) + (2*a-2-b+z)*kummerm(a-1,b,z))
when spec_check_n(a),

% AS (13.4.15)
kummeru(~a,~b,~z) => -1/((a-1)*(a-b))*
        (kummeru(a-2,b,z) + (b-2*a+2-z)*kummeru(a-1,b,z))
when spec_check_n(a),
% AS (13.4.29)

whittakerm(~n,~m,~z) => 1/(2*m+2*n-1)*
        ((3+2*m-2*n)*whittakerm(n-2,m,z)
           + (4*n-4-2*z)*whittakerm(n-1,m,z))
when spec_check_n(n),
% AS (13.4.31)

whittakerw(~n,~m,~z) => 1/4*
((-9+4*m^2+12*n-4*n^2)*whittakerw(n-2,m,z)
    - (8*n-8-4*z)*whittakerw(n-1,m,z))
when spec_check_n(n),
% AS (8.5.3)

legendrep(~a,~b,~z) => 1/(a-b)*
        (-(a-1+b)*legendrep(a-2,b,z) + (2*a-1)*z*legendrep(a-1,b,z))
when spec_check_n(a),

legendreq(~a,~b,~z) => 1/(a-b)*
        (-(a-1+b)*legendreq(a-2,b,z) + (2*a-1)*z*legendreq(a-1,b,z))
when spec_check_n(a),
% AS (22.7)

jacobip(~n,~a,~b,~z) => 1/(2*n*(a + b + n)*(-2 + a + b + 2*n))*
((2*(1-a-n)*(-1+b+n)*(a+b+2*n)*jacobip(n-2,a,b,z)) +
((a^2-b^2)*(-1+a+b+2*n)+(-2+a+b+2*n)*(-1+a+b+2*n)*(a+b+2*n)*z)*
jacobip(n-1,a,b,z)) when spec_check_n(n),

gegenbauerp(~n,~a,~z) => 1/n*(
     -(n+2*a-2)*gegenbauerp(n-2,a,z) + 2*(n-1+a)*z*gegenbauerp(n-1,a,z))
when spec_check_n(n),

chebyshevt(~n,~z) => - chebyshevt(n-2,z) +2*z*chebyshevt(n-1,z)
when spec_check_n(n),

chebyshevu(~n,~z) => - chebyshevu(n-2,z) +2*z*chebyshevu(n-1,z)
when spec_check_n(n),

% Two arguments version:
 legendrep(~n,~z) =>
 1/n*(-(n-1)*legendrep(n-2,z)+(2*n-1)*z*legendrep(n-1,z))
 when spec_check_n(n),

laguerrep(~n,~a,~z) => 1/n*
        (-(n-1+a)*laguerrep(n-2,a,z) + (2*n+a-1-z)*laguerrep(n-1,a,z))
when spec_check_n(n),

laguerrep(~n,~z) => 1/n*
        (-(n-1)*laguerrep(n-2,z) + (2*n-1-z)*laguerrep(n-1,z))
when spec_check_n(n),

hermitep(~n,~z) => -2*(n-1)*hermitep(n-2,z) + 2*z*hermitep(n-1,z)
when spec_check_n(n) ,

struveh(~nnnnn,~x)=>
((x^2*struveh(-3 + nnnnn,x) + 5*x*struveh(-2 + nnnnn,x) -
        4*nnnnn*x*struveh(-2 + nnnnn,x) + 2*struveh(-1 + nnnnn,x) -
        6*nnnnn*struveh(-1 + nnnnn,x) + 4*nnnnn^2*struveh(-1 + nnnnn,x)
        + x^2*struveh(-1 + nnnnn,x))/(-x + 2*nnnnn*x))
  when spec_check_n(nnnnn),

%(* AS (12.2.4)-(12.2.5) *)

struvel(~nnnnn,~x) => ((-(x*struvel(-3 + nnnnn, x)) +
(-1 + 4*(-1 + nnnnn))*struvel(-2 + nnnnn, x) +
((-2*(-1 + nnnnn) - 4*(-1 + nnnnn)^2 + x^2)*struvel(-1 + nnnnn, x))/x)/
(1 + 2*(-1 + nnnnn))) when spec_check_n(nnnnn) } )$

% can be locally applied with where.

endmodule;


module sfellip;  % Procedures and Rules for Elliptic functions.

% Author: Lisa Temme, ZIB, October 1994

algebraic <<

%ARITHMETIC GEOMETRIC MEAN

%The following procedure is the process of the Arithmetic Geometric
%Mean.

procedure agm_function(a0,b0,c0);

   begin scalar an, bn, cn, an!-1, bn!-1, alist, blist, clist;

     %Initial values.

        an!-1 := a0;
        bn!-1 := b0;
        cn    := 20;    %To initiate while loop below.

     %Put initial values at end of list.

        alist := {a0};
        blist := {b0};
        clist := {c0};

     %Loop to generate lists of aN,bN and cN starting with the Nth
     %value and ending with the initial value.

     %When the absolute value of cN reaches a value smaller than that
     %of the required precision the loop exits. The value of aN=bN=AGM.

        while abs(cn) > 10^(-(symbolic !:prec!:)) do

           << %Calculations for the process of the AGM

                an := (an!-1 + bn!-1) / 2;
                bn := sqrt(an!-1 * bn!-1);
                cn := (an!-1 - bn!-1) / 2;

             %Adding the next term to each of the lists.

                alist := an.alist;
                blist := bn.blist;
                clist := cn.clist;

             %Resetting the values in order to execute the next loop.

                an!-1 := an;
                bn!-1 := bn
           >>;

     %N is the number of terms in each list (excluding the initial
     % values) used to calculate the AGM.

        n := length(alist) - 1;

     %The following list contains all the items required in the
     %calculation of other procedures which use the AGM
     %ie. {N, AGM, {aN to a0},{bN to b0},{cN to c0}}

        return list(n ,an, alist, blist, clist)

   end;
%######################################################################
%CALCULATING PHI
%               N


%The following procedure sucessively computes phi   ,phi   ,...,phi ,
%                                                N-1    N-2        0
%from the recurrence relation:
%
%       sin(2phi    - phi ) = (c /a )sin phi
%               N-1      N      N  N        N
%
%and returns a list of phi  to phi . This list is then used in the
%                        0       N
%calculation of Jacobisn, Jacobicn, Jacobidn, which in turn are used
%to calculate the remaining twelve Jacobi Functions.


procedure phi_function(a0,b0,c0,u);

   begin scalar alist, clist,n,a_n,an,cn,i, phi_n, phi_n!-1, phi_list;

        agm   := agm_function(a0,b0,c0);
        alist := part(agm,3);            % aN to a0
        clist := part(agm,5);            % cN to c0
        n := part(agm,1);
        a_n := part(alist,1);            % Value of the AGM.
        phi_n := (2^n)*a_n*u;
        phi_list := {phi_n};
        i := 1;

        while i < length(alist) do

           <<
                an := part(alist,i);
                cn := part(clist,i);

                phi_n!-1 := (asin((cn/an)*sin(phi_n)) + phi_n) / 2;
                phi_list := phi_n!-1.phi_list;
                phi_n := phi_n!-1;
                i := i+1
           >>;

     %Returns {phi_0 to phi_N}.

        return phi_list;

   end;

%######################################################################
%JACOBI AMPLITUDE


%This computes the Amplitude of u.

procedure amplitude(u,m);
        asin(jacobisn(u,m));

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

operator jacobiamplitude;

jacobiamrules :=

{
        jacobiamplitude(~u,~m) => amplitude(u,m) when lisp !*rounded
                                         and numberp u and numberp m
};

let jacobiamrules;

%######################################################################
%JACOBI FUNCTIONS

%Increases the precision used to evaluate algebraic arguments.

symbolic procedure  num_jacobi (u);
% check that length u >= 3 !
 if length u < 3 then
         rederr "illegal call to num_jacobisn" else
   begin scalar oldprec,res;
     oldprec := precision 0;
     precision max(oldprec,15);

    res :=  aeval u;
    precision oldprec;
    return res;

  end;

put('num_elliptic, 'psopfn, 'num_jacobi);

%######################################################################
%This procedure is called by Jacobisn when the on rounded switch is
%used. It evaluates the value of Jacobisn numerically.


procedure num_jacobisn(u,m);

   begin scalar phi0, jsn;
        phi0 := part(phi_function(1,sqrt(1-m),sqrt(m),u),1);
        jsn := sin(phi0);
        return jsn
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisn definition
%===================

operator jacobisn;
operator elliptick!';
operator elliptick;

%This rule list includes all the special cases of the Jacobisn
%function.

jacobisnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobisn(~u,0)   => sin u,
        jacobisn(~u,1)   => tanh u,
        jacobisn(~u,-~m) => jacobisn(u,m),
%Change of argument
%------------------
        jacobisn(~u + ~v,~m) =>
                ( jacobisn(u,m)*jacobicn(v,m)*jacobidn(v,m)
                + jacobisn(v,m)*jacobicn(u,m)*jacobidn(u,m) )
                / (1-m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobisn(2*~u,~m) =>
                ( 2*jacobisn(u,m)*jacobicn(u,m)*jacobidn(u,m) )
                / (1-m*((jacobisn(u,m))^4)),

        jacobisn(~u/2,~m) =>
                ( 1- jacobicn(u,m) ) / ( 1 + jacobidn(u,m) ),


        jacobisn(-~u,~m) => -jacobisn(u,m),
        jacobisn((~u+elliptick(~m)),~m)   =>  jacobicd(u,m),
        jacobisn((~u-elliptick(~m)),~m)   => -jacobicd(u,m),
        jacobisn((elliptick(~m)-~u),~m)   =>  jacobicd(u,m),
        jacobisn((~u+2*elliptick(~m)),~m) => -jacobisn(u,m),
        jacobisn((~u-2*elliptick(~m)),~m) => -jacobisn(u,m),
        jacobisn((2*elliptick(~m)-~u),~m) =>  jacobisn(u,m),
        jacobisn(~u+i*elliptick!'(~m),~m) => (m^(-1/2))*jacobins(u,m),

        jacobisn((~u+2*i*elliptick!'(~m)),~m) => jacobisn(u,m),

        jacobisn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                              (m^(-1/2))*jacobidc(u,m),

        jacobisn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobisn(u,m),
%Special Arguments
%-----------------
        jacobisn(0,~m) => 0,

        jacobisn((1/2)*elliptick(~m),~m) =>1/((1+((1-m)^(1/2)))^(1/2)),

        jacobisn(elliptick(~m),~m) => 1,

        jacobisn((1/2)*i*elliptick!'(~m),~m) => i*m^(-1/4),

        jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                            (2^(-1/2))*m^(-1/4)*(((1+(m^(1/2)))^(1/2))
                                            + i*((1-(m^(1/2)))^(1/2))),

        jacobisn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) => m^(-1/4),

        jacobisn(i*elliptick!'(~m),~m) => infinity,

        jacobisn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                              (1-((1-m)^(1/2)))^(-1/2),

        jacobisn(elliptick(~m)+i*elliptick!'(~m),~m) => m^(-1/2),


%Derivatives, Integral
%---------------------
        df(jacobisn(~u,~m),~u)  => jacobicn(u,m)*jacobidn(u,m),
        df(jacobisn(~u,~m),~m)  => (m*jacobisn(u,m)*jacobicn(u,m)^2
                        - elliptice(u,m)*jacobicn(u,m)*jacobidn(u,m)/m)
                        / (1-(m^2)) +  u*jacobicn(u,m)*jacobidn(u,m)/m,

        int(jacobisn(~u,~m),~u) =>
                (m^(-1/2))*ln(jacobidn(u,m)-(m^(1/2))*jacobicn(u,m)),

%Calls Num_Jacobisn when the rounded switch is on.
%-------------------------------------------------
        jacobisn(~u,~m) => num_elliptic(num_jacobisn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobisn(~u,~m) => num_elliptic(complex_sn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0

};
let jacobisnrules;
%......................................................................
%Evaluates Jacobisn when imaginary argument.

operator complex_sn;
snrule :=
{

        complex_sn(i*~u,~m) => i*num_jacobisc(u,1-m),

        complex_sn(~x + i*~y,~m) =>
                ( num_jacobisn(x,m)*num_jacobidn(y,1-m)
                + i*num_jacobicn(x,m)*num_jacobidn(x,m)
                   *num_jacobisn(y,1-m)*num_jacobicn(y,1-m) )
                / (((num_jacobicn(y,1-m))^2)+
                   m*((num_jacobisn(x,m))^2)*((num_jacobisn(y,1-m))^2))
};
let snrule;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicn when the on rounded switch is
%used. It evaluates the value of Jacobicn numerically.

procedure num_jacobicn(u,m);

   begin scalar phi0, jcn;
        phi0 := part(phi_function(1,sqrt(1-m),sqrt(m),u),1);
        jcn := cos(phi0);
        return jcn
   end;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobicn definition
%===================

operator jacobicn;

%This rule list includes all the special cases of the Jacobicn
%function.

jacobicnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobicn(~u,0)   => cos u,
        jacobicn(~u,1)   => sech u,
        jacobicn(~u,-~m) => jacobicn(u,m),
%Change of Argument
%------------------
        jacobicn(~u + ~v,~m) =>
                ( jacobicn(u,m)*jacobicn(v,m) - jacobisn(u,m)
                   *jacobidn(u,m)*jacobisn(v,m)*jacobidn(v,m) )
                / (1 - m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobicn(2*~u,~m) =>
                ( ((jacobicn(u,m))^2) - ((jacobisn(u,m))^2)
                  *((jacobidn(u,m))^2) )
                / (1- m*((jacobisn(u,m))^4)),

        jacobicn(~u/2,~m) =>
                ( jacobidn(u,m) + jacobicn(u,m) )
                / ( 1 + jacobidn(u,m) ),

        jacobicn(-~u,~m) => jacobicn (u,m),

        jacobicn((~u+elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((~u-elliptick(~m)),~m) => ((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobisd(u,m),
        jacobicn((~u+2*elliptick(~m)),~m) => -jacobicn(u,m),
        jacobicn((~u-2*elliptick(~m)),~m) => -jacobicn(u,m),
        jacobicn((2*elliptick(~m)-~u),~m) => -jacobicn(u,m),
        jacobicn((~u+i*elliptick!'(~m)),~m) =>
                                           -i*(m^(-1/2))*jacobids(u,m),

        jacobicn((~u+2*i*elliptick!'(~m)),~m) => -jacobicn(u,m),

        jacobicn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                             -i*((1-m)^(1/2))*(m^(-1/2))*jacobinc(u,m),

        jacobicn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobicn(u,m),
%Special Arguments
%-----------------
        jacobicn(0,~m) => 1,

        jacobicn((1/2)*elliptick(~m),~m) =>
                                 ((1-m)^(1/4))/(1+((1-m)^(1/2)))^(1/2),

        jacobicn(elliptick(~m),~m) => 0,

        jacobicn((1/2)*i*elliptick!'(~m),~m) =>
                                       ((1+(m^(1/2)))^(1/2))/(m^(1/4)),

        jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                           (((1-m)/(4*m))^(1/4))*(1-i),

        jacobicn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                  -i*(((1-(m^(1/2)))/(m^(1/2))))^(1/2),

        jacobicn(i*elliptick!'(~m),~m) => infinity,

        jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                          -i*((((1-m)^(1/2))/(1-((1-m)^(1/2))))^(1/2)),

        jacobicn(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                  -i*(((1-m)/m)^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobicn(~u,~m),~u)  => -jacobisn(u,m)*jacobidn(u,m),
        df(jacobicn(~u,~m),~m)  => (-m*(jacobisn(u,m)^2)*jacobicn(u,m)
                                   + elliptice(u,m)*jacobisn(u,m)
                                     *jacobidn(u,m)/m)/(1-(m^2))
                                   - u*jacobisn(u,m)*jacobidn(u,m)/m,

        int(jacobicn(~u,~m),~u) => (m^(-1/2))*acos(jacobidn(u,m)),

%Calls Num_Jacobicn when rounded switch is on.
%---------------------------------------------
        jacobicn(~u,~m) => num_elliptic(num_jacobicn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobicn(~u,~m) => num_elliptic(complex_cn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0
};
let jacobicnrules;
%......................................................................
%Evaluates Jacobicn when imaginary argument.

operator complex_cn;
cnrule :=
{

        complex_cn(i*~u,~m) => num_jacobinc(u,1-m),

        complex_cn(~x + i*~y,~m) =>

                ( num_jacobicn(x,m)*num_jacobicn(y,1-m)
                - i*num_jacobisn(x,m)*num_jacobidn(x,m)
                   *num_jacobisn(y,1-m)*num_jacobidn(y,1-m) )
                / (((num_jacobicn(y,1-m))^2)+
                   m*((num_jacobisn(x,m))^2)*((num_jacobisn(y,1-m))^2))
};
let cnrule;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidn when the on rounded switch is
%used. It evaluates the value of Jacobidn numerically.

procedure num_jacobidn(u,m);
   begin scalar phi, phi0,  phi1, numer, denom, jdn;
        phi  := phi_function(1,sqrt(1-m),sqrt(m),u);
        phi0 := part(phi,1);
        phi1 := part(phi,2);
        numer := cos(phi0);
        denom := cos(phi1 - phi0);

        if denom < 10^(-(symbolic !:prec!:))
        then  jdn := otherdn(u,m)
        else  jdn := numer/denom;
        return jdn
   end;

procedure otherdn(u,m);
   begin scalar mu, v, dn;
        mu := ((1-((1-m)^(1/2))) / (1+((1-m)^(1/2))))^2;
        v  := u / (1+(mu^(1/2)));

        dn := ((approx(v,mu))^2 - (1-(mu^(1/2))))

                / ((1+(mu^(1/2))) - (approx(v,mu))^2);
        return dn
   end;


procedure approx(u,m);
   begin scalar near;
        near := 1 - (1/2)*m*(sin(u))^2;
        return near
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidn definition
%===================

operator jacobidn;

%This rule list includes all the special cases of the Jacobidn
%function.

jacobidnrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobidn(~u,0)   => 1,
        jacobidn(~u,1)   => sech u,
        jacobidn(~u,-~m) => jacobidn(u,m),
%Change of Argument
%------------------
        jacobidn(~u + ~v,~m) =>
                ( jacobidn(u,m)*jacobidn(v,m) - m*jacobisn(u,m)
                   *jacobicn(u,m)*jacobisn(v,m)*jacobicn(v,m) )
                / (1 - m*((jacobisn(u,m))^2)*((jacobisn(v,m))^2)),

        jacobidn(2*~u,~m) =>
                (  ((jacobidn(u,m))^2) - m*((jacobisn(u,m))^2)
                  *((jacobicn(u,m))^2) )
                / (1- m*((jacobisn(u,m))^4)),

        jacobidn(~u/2,~m) =>
                ( (1-m) + jacobidn(u,m) + m*jacobicn(u,m))
                / ( 1 + jacobidn(u,m) ),

        jacobidn(-~u,~m) => jacobidn(u,m),

        jacobidn((~u+elliptick(~m)),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((~u-elliptick(~m)),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobind(u,m),
        jacobidn((~u+2*elliptick(~m)),~m) => jacobidn(u,m),
        jacobidn((~u-2*elliptick(~m)),~m) => jacobidn(u,m),
        jacobidn((2*elliptick(~m)-~u),~m) => jacobidn(u,m),
        jacobidn((~u+i*elliptick!'(~m)),~m)   => -i*jacobics(u,m),
        jacobidn((~u+2*i*elliptick!'(~m)),~m) => -jacobidn(u,m),

        jacobidn((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                         i*((1-m)^(1/2))*jacobisc(u,m),

        jacobidn((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobidn(u,m),
%Special Arguments
%-----------------
        jacobidn(0,~m) => 1,

        jacobidn((1/2)*elliptick(~m),~m) => (1-m)^(1/4),

        jacobidn(elliptick(~m),~m) => (1-m)^(1/2),

        jacobidn((1/2)*i*elliptick!'(~m),~m) =>   (1+(m^(1/2)))^(1/2),

        jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                         (((1-m)/4)^(1/4))*(((1+((1-m)^(1/2)))^(1/2))
                                        - i*((1-((1-m)^(1/2)))^(1/2))),

        jacobidn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                   (1-(m^(1/2)))^(1/2),

        jacobidn(i*elliptick!'(~m),~m) => infinity,

        jacobidn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                      -i*((1-m)^(1/4)),

        jacobidn(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Intergal
%---------------------
        df(jacobidn(~u,~m),~u)  => -m*jacobisn(u,m)*jacobicn(u,m),
        df(jacobidn(~u,~m),~m)  => m*(-(jacobisn(u,m)^2)*jacobidn(u,m)
                                   + elliptice(u,m)*jacobisn(u,m)
                                     *jacobicn(u,m))/(1-(m^2))
                                   - m*u*jacobisn(u,m)*jacobicn(u,m),

        int(jacobidn(~u,~m),~u) => asin(jacobisn(u,m)),

%Calls Num_Jacobidn when rounded switch is on.
%---------------------------------------------
        jacobidn(~u,~m) => num_elliptic(num_jacobidn, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m and impart(u) = 0,

        jacobidn(~u,~m) => num_elliptic(complex_dn, u, m)
                           when lisp !*rounded and numberp repart u
                           and numberp impart u and numberp m
                           and impart(u) neq 0
};
let jacobidnrules;
%......................................................................
%Evaluates Jacobidn when imaginary argument.

operator complex_dn;
dnrule :=
{       complex_dn(i*~u,~m) => num_jacobidc(u,1-m),

        complex_dn(~x + i*~y,~m) =>

        ( num_jacobidn(x,m)*num_jacobicn(y,1-m)*num_jacobidn(y,1-m)
        - i*m*num_jacobisn(x,m)*num_jacobicn(x,m)*num_jacobisn(y,1-m) )
        / ( ((num_jacobicn(y,1-m))^2) + m*((num_jacobisn(x,m))^2)
                                         *((num_jacobisn(y,1-m))^2) )
};
let dnrule;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobicd when the on rounded switch is
%used. It evaluates the value of Jacobicd numerically.

procedure num_jacobicd(u,m);

        num_jacobicn(u,m) / num_jacobidn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobicd definition
%===================

operator jacobicd;

%This rule list includes all the special cases of the Jacobicd
%function.

jacobicdrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobicd(~u,0)   => cos u,
        jacobicd(~u,1)   => 1,
        jacobicd(~u,-~m) => jacobicd(u,m),
%Change of Argument
%------------------
        jacobicd(-~u,~m)   => jacobicd(u,m),
        jacobicd((~u+elliptick(~m)),~m)   => -jacobisn(u,m),
        jacobicd((~u-elliptick(~m)),~m)   =>  jacobisn(u,m),
        jacobicd((elliptick(~m)-~u),~m)   =>  jacobisn(u,m),
        jacobicd((~u+2*elliptick(~m)),~m) => -jacobicd(u,m),
        jacobicd((~u-2*elliptick(~m)),~m) => -jacobicd(u,m),
        jacobicd((2*elliptick(~m)-~u),~m) => -jacobicd(u,m),
        jacobicd((~u+i*elliptick!'(~m)),~m) =>
                                              (m^(-1/2))*jacobidc(u,m),

        jacobicd((~u+2*i*elliptick!'(~m)),~m) => jacobicd(u,m),

        jacobicd((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                             -(m^(-1/2))*jacobins(u,m),

        jacobicd((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobicd(u,m),
%Special Arguments
%-----------------
        jacobicd(0,~m) => 1,

        jacobicd((1/2)*elliptick(~m),~m) => 1 /(1+((1-m)^(1/2)))^(1/2),

        jacobicd(elliptick(~m),~m) => 0,

        jacobicd((1/2)*i*elliptick!'(~m),~m) => 1/(m^(1/4)),

        jacobicd((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                           (1-i)/((m^(1/4))*(((1+((1-m)^(1/2)))^(1/2))
                                        -i*((1-((1-m)^(1/2)))^(1/2)))),

        jacobicd(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                          -i/(m^(1/4)),

        jacobicd(i*elliptick!'(~m),~m) =>
                                        jacobicn(i*elliptick!'(~m),~m)
                                      / jacobidn(i*elliptick!'(~m),~m),

        jacobicd((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                           1/((1-((1-m)^(1/2)))^(1/2)),

        jacobicd(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives,Integral
%--------------------
        df(jacobicd(~u,~m),~u) => -(1 - m)*jacobisd(u,m)*jacobind(u,m),
        df(jacobicd(~u,~m),~m) =>
                                ( jacobidn(u,m)*df(jacobicn(u,m),m)
                                - jacobicn(u,m)*df(jacobidn(u,m),m))
                                / ((jacobidn(u,m))^2),

        int(jacobicd(~u,~m),~u) =>
                m^(-1/2)*ln(jacobind(u,m) + (m^(1/2))*jacobisd(u,m)),

%Calls Num_Jacobicd when rounded switch is on.
%---------------------------------------------
        jacobicd(~u,~m) => num_elliptic(num_jacobicd, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobicdrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisd when the on rounded switch is
%used. It evaluates the value of Jacobisd numerically.

procedure num_jacobisd(u,m);

   num_jacobisn(u,m) / num_jacobidn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisd definition
%===================

operator jacobisd;

%This rule list includes all the special cases of the Jacobisd
%function.

jacobisdrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobisd(~u,0)   => sin u,
        jacobisd(~u,1)   => sinh u,
        jacobisd(~u,-~m) => jacobisd(u,m),
%Change of Argument
%------------------
        jacobisd(-~u,~m)   => -jacobisd(u,m),

        jacobisd((~u+elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobicn(u,m),
        jacobisd((~u-elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobicn(u,m),

        jacobisd((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobicn(u,m),

        jacobisd((~u+2*elliptick(~m)),~m) => -jacobisd(u,m),
        jacobisd((~u-2*elliptick(~m)),~m) => -jacobisd(u,m),
        jacobisd((2*elliptick(~m)-~u),~m) =>  jacobisd(u,m),

        jacobisd((~u+i*elliptick!'(~m)),~m) =>
                                            i*(m^(-1/2))*jacobinc(u,m),

        jacobisd((~u+2*i*elliptick!'(~m)),~m) => -jacobisd(u,m),

        jacobisd((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                          -i*((1-m)^(-1/2))*(m^(-1/2))*jacobids(u,m),

        jacobisd((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobisd(u,m),
%Special Arguments
%-----------------
        jacobisd(0,~m) => 0,

        jacobisd((1/2)*elliptick(~m),~m) =>
                         1 / (((1+((1-m)^(1/2)))^(1/2))*((1-m)^(1/4))),

        jacobisd(elliptick(~m),~m) => 1/((1-m)^(1/2)),

        jacobisd((1/2)*i*elliptick!'(~m),~m) =>
                                    i*(m^(-1/4))/((1+(m^(1/2)))^(1/2)),

        jacobisd((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobisd(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                        (m^(-1/4))/(1-(m^(1/2))^(1/2)),

        jacobisd(i*elliptick!'(~m),~m) =>
                                        jacobisn(i*elliptick!'(~m),~m)
                                      / jacobidn(i*elliptick!'(~m),~m),

        jacobisd((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                         ((1-((1-m)^(1/2)))^(-1/2))/(-i*((1-m)^(1/4))),

        jacobisd(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives, Integral
%---------------------
        df(jacobisd(~u,~m),~u) => jacobicd(u,m)*jacobind(u,m),
        df(jacobisd(~u,~m),~m) =>
                                ( jacobidn(u,m)*df(jacobisn(u,m),m)
                                - jacobisn(u,m)*df(jacobidn(u,m),m))
                                / ((jacobidn(u,m))^2),

        int(jacobisd(~u,~m),~u) =>
                   (m*(1-m))^(-1/2)*asin(-(m^(1/2))*(jacobicd(u,m))),

%Calls Num_Jacobisd when rounded switch is on.
%---------------------------------------------
        jacobisd(~u,~m) => num_elliptic(num_jacobisd, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobisdrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobind when the on rounded switch is
%used. It evaluates the value of Jacobind numerically.

procedure num_jacobind(u,m);

        1 / num_jacobidn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobind definition
%===================

operator jacobind;

%This rule list includes all the special cases of the Jacobind
%function.

jacobindrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobind(~u,0)   => 1,
        jacobind(~u,1)   => cosh u,
        jacobind(~u,-~m) => jacobind(u,m),
%Change of Argument
%------------------
        jacobind(-~u,~m)   => jacobind(u,m),

        jacobind((~u+elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobidn(u,m),
        jacobind((~u-elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobidn(u,m),
        jacobind((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobidn(u,m),

        jacobind((~u+2*elliptick(~m)),~m) => jacobind(u,m),
        jacobind((~u-2*elliptick(~m)),~m) => jacobind(u,m),
        jacobind((2*elliptick(~m)-~u),~m) => jacobind(u,m),

        jacobind((~u+i*elliptick!'(~m)),~m)   => i*jacobisc(u,m),
        jacobind((~u+2*i*elliptick!'(~m)),~m) => -jacobind(u,m),

        jacobind((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                       -i*((1-m)^(-1/2))*jacobics(u,m),

        jacobind((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobind(u,m),
%Special Arguments
%-----------------
        jacobind(0,~m) => 1,

        jacobind((1/2)*elliptick(~m),~m) => 1 / ((1-m)^(1/4)),

        jacobind(elliptick(~m),~m) => 1 / ((1-m)^(1/2)),

        jacobind((1/2)*i*elliptick!'(~m),~m) =>
                                               1/((1+(m^(1/2)))^(1/2)),

        jacobind((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                1/jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobind(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                               1/((1-(m^(1/2)))^(1/2)),

        jacobind(i*elliptick!'(~m),~m) =>
                                    1 / jacobidn(i*elliptick!'(~m),~m),

        jacobind((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                1 / (-i*((1-m)^(1/4))),

        jacobind(elliptick(~m)+i*elliptick!'(~m),~m) => infinity,

%Derivatives, Integral
%---------------------
        df(jacobind(~u,~m),~u) => m*jacobisd(u,m)*jacobicd(u,m),
        df(jacobind(~u,~m),~m) =>
                            -(df(jacobidn(u,m),m))/((jacobidn(u,m))^2),

        int(jacobind(~u,~m),~u) => (1-m)^(-1/2)*(acos(jacobicd(u,m))),

%Calls Num_Jacobind when rounded switch is on.
%---------------------------------------------
        jacobind(~u,~m) => num_elliptic(num_jacobind, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobindrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobidc when the on rounded switch is
%used. It evaluates the value of Jacobidc numerically.

procedure num_jacobidc(u,m);

        num_jacobidn(u,m) / num_jacobicn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobidc definition
%===================

operator jacobidc;

%This rule list includes all the special cases of the Jacobidc
%function.

jacobidcrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobidc(~u,0)   => sec u,
        jacobidc(~u,1)   => 1,
        jacobidc(~u,-~m) => jacobidc(u,m),
%Change of Argument
%------------------
        jacobidc(-~u,~m)   => jacobidc(u,m),

        jacobidc((~u+elliptick(~m)),~m) => -jacobins(u,m),
        jacobidc((~u-elliptick(~m)),~m) =>  jacobidns(u,m),
        jacobidc((elliptick(~m)-~u),~m) =>  jacobins(u,m),
        jacobidc((~u+2*elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobidc((~u-2*elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobidc((2*elliptick(~m)-~u),~m)   => -jacobidc(u,m),
        jacobidc((~u+i*elliptick!'(~m)),~m) => (m^(1/2))*jacobicd(u,m),
        jacobidc((~u+2*i*elliptick!'(~m)),~m) => jacobidc(u,m),

        jacobidc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                               (m^(1/2))*jacobisn(u,m),

        jacobidc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobidc(u,m),
%Special Arguments
%-----------------
        jacobidc(0,~m) => 1,

        jacobidc((1/2)*elliptick(~m),~m) => (1+((1-m)^(1/2)))^(1/2),

        jacobidc(elliptick(~m),~m) => infinity,

        jacobidc((1/2)*i*elliptick!'(~m),~m) => m^(1/4),

        jacobidc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobidc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                                           i*(m^(1/4)),

        jacobidc(i*elliptick!'(~m),~m) =>
                                        jacobidn(i*elliptick!'(~m),~m)
                                      / jacobicn(i*elliptick!'(~m),~m),

        jacobidc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                               (1-((1-m)^(1/2)))^(1/2),

        jacobidc(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Integral
%---------------------
        df(jacobidc(~u,~m),~u) => (1-m)*jacobisc(u,m)*jacobinc(u,m),
        df(jacobidc(~u,~m),~m) =>
                                (jacobicn(u,m)*df(jacobidn(u,m),m)
                                - jacobidn(u,m)*df(jacobicn(u,m),m))
                                / ((jacobicn(u,m))^2),

        int(jacobidc(~u,~m),~u) => ln(jacobinc(u,m) + jacobisc(u,m)),

%Calls Num_Jacobidc when rounded switch is on.
%---------------------------------------------
        jacobidc(~u,~m) => num_elliptic(num_jacobidc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobidcrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobinc when the on rounded switch is
%used. It evaluates the value of Jacobinc numerically.

procedure num_jacobinc(u,m);

        1 / num_jacobicn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobinc definition
%===================

operator jacobinc;

%This rule list includes all the special cases of the Jacobinc
%function.

jacobincrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobinc(~u,0)   => sec u,
        jacobinc(~u,1)   => cosh u,
        jacobinc(~u,-~m) => jacobinc(u,m),
%Change of Argument
%------------------
        jacobinc(-~u,~m)   => jacobinc(u,m),

        jacobinc((~u+elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobids(u,m),

        jacobinc((~u-elliptick(~m)),~m) =>((1-m)^(-1/2))*jacobids(u,m),
        jacobinc((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobids(u,m),

        jacobinc((~u+2*elliptick(~m)),~m) => -jacobinc(u,m),
        jacobinc((~u-2*elliptick(~m)),~m) => -jacobinc(u,m),
        jacobinc((2*elliptick(~m)-~u),~m) => -jacobinc(u,m),
        jacobinc((~u+i*elliptick!'(~m)),~m) =>
                                            i*(m^(1/2))*jacobisd(u,m),

        jacobinc((~u+2*i*elliptick!'(~m)),~m) => -jacobinc(u,m),

        jacobinc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                            i*((1-m)^(-1/2))*(m^(1/2))*jacobicn(u,m),

        jacobinc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobinc(u,m),
%Special Arguments
%-----------------
        jacobinc(0,~m) => 1,

        jacobinc((1/2)*elliptick(~m),~m) => ((1+((1-m)^(1/2)))^(1/2))
                                                        /((1-m)^(1/4)),

        jacobinc(elliptick(~m),~m) => infinity,

        jacobinc((1/2)*i*elliptick!'(~m),~m) =>
                                       (m^(1/4))/((1+(m^(1/2)))^(1/2)),

        jacobinc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                             ((4*m/(1-m))^(1/4))/(1-i),

        jacobinc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                1 / jacobicn(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m),

        jacobinc(i*elliptick!'(~m),~m) =>
                                    1 / jacobicn(i*elliptick!'(~m),~m),

        jacobinc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                1 / jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m),

        jacobinc(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                   i*((m/(1-m))^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobinc(~u,~m),~u) => jacobisc(u,m)*jacobidc(u,m),
        df(jacobinc(~u,~m),~m) =>
                            -(df(jacobicn(u,m),m))/((jacobicn(u,m))^2),

        int(jacobinc(~u,~m),~u) =>

         ((1-m)^(-1/2))*ln(jacobidc(u,m)+((1-m)^(1/2))*jacobisc(u,m)),

%Calls Num_Jacobinc when rounded switch is on.
%---------------------------------------------
        jacobinc(~u,~m) => num_elliptic(num_jacobinc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobincrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobisc when the on rounded switch is
%used. It evaluates the value of Jacobisc numerically.

procedure num_jacobisc(u,m);

        num_jacobisn(u,m) / num_jacobicn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobisc definition
%===================

operator jacobisc;

%This rule list includes all the special cases of the Jacobisc
%function.

jacobiscrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobisc(~u,0)   => tan u,
        jacobisc(~u,1)   => sinh u,
        jacobisc(~u,-~m) => jacobisc(u,m),
%Change of Argument
%------------------
        jacobisc(-~u,~m)   => -jacobisc(u,m),

        jacobisc((~u+elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobics(u,m),

        jacobisc((~u-elliptick(~m)),~m) => -((1-m)^(-1/2))
                                                        *jacobics(u,m),

        jacobisc((elliptick(~m)-~u),~m) =>((1-m)^(-1/2))*jacobics(u,m),

        jacobisc((~u+2*elliptick(~m)),~m) =>  jacobisc(u,m),
        jacobisc((~u-2*elliptick(~m)),~m) =>  jacobisc(u,m),
        jacobisc((2*elliptick(~m)-~u),~m) => -jacobisc(u,m),
        jacobisc((~u+i*elliptick!'(~m)),~m)   =>i*jacobind(u,m),
        jacobisc((~u+2*i*elliptick!'(~m)),~m) => -jacobisc(u,m),

        jacobisc((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                        i*((1-m)^(-1/2))*jacobidn(u,m),

        jacobisc((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobisc(u,m),
%Special Arguments
%-----------------
        jacobisc(0,~m) => 0,

        jacobisc((1/2)*elliptick(~m),~m) => 1 / ((1-m)^(1/4)),

        jacobisc(elliptick(~m),~m) => infinity,

        jacobisc((1/2)*i*elliptick!'(~m),~m) =>
                                               i/((1+(m^(1/2)))^(1/2)),

        jacobisc((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobisc(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                               i/((1-(m^(1/2)))^(1/2)),

        jacobisc(i*elliptick!'(~m),~m) =>
                                      jacobisn(i*elliptick!'(~m),~m)
                                      / jacobicn(i*elliptick!'(~m),~m),

        jacobisc((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>

                  jacobisn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m)
                  / jacobicn((1/2)*elliptick(~m)+i*elliptick!'(~m),~m),

        jacobisc(elliptick(~m)+i*elliptick!'(~m),~m) =>i/((1-m)^(1/2)),


%Derivatives, Integral
%---------------------
        df(jacobisc(~u,~m),~u) => jacobidc(u,m)*jacobinc(u,m),
        df(jacobisc(~u,~m),~m) =>
                                ( jacobicn(u,m)*df(jacobisn(u,m),m)
                                - jacobisn(u,m)*df(jacobicn(u,m),m))
                                /((jacobicn(u,m))^2),

        int(jacobisc(~u,~m),u) =>

          ((1-m)^(-1/2))*ln(jacobidc(u,m)+((1-m)^(1/2))*jacobinc(u,m)),

%Calls Num_Jacobisc when rounded switch is on.
%---------------------------------------------
        jacobisc(~u,~m) => num_elliptic(num_jacobisc, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobiscrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobins when the on rounded switch is
%used. It evaluates the value of Jacobins numerically.

procedure num_jacobins(u,m);

        1 / num_jacobisn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobins definition
%===================

operator jacobins;

%This rule list includes all the special cases of the Jacobins
%function.

jacobinsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobins(~u,0)   => csc u,
        jacobins(~u,1)   => coth u,
        jacobins(~u,-~m) => jacobins(u,m),
%Change of Argument
%------------------
        jacobins(-~u,~m)   => -jacobins(u,m),

        jacobins((~u+elliptick(~m)),~m)   =>  jacobidc(u,m),
        jacobins((~u-elliptick(~m)),~m)   => -jacobidc(u,m),
        jacobins((elliptick(~m)-~u),~m)   =>  jacobidc(u,m),
        jacobins((~u+2*elliptick(~m)),~m) => -jacobins(u,m),
        jacobins((~u-2*elliptick(~m)),~m) => -jacobins(u,m),
        jacobins((2*elliptick(~m)-~u),~m) =>  jacobins(u,m),
        jacobins((~u+i*elliptick!'(~m)),~m) => (m^(1/2))*jacobisn(u,m),
        jacobins((~u+2*i*elliptick!'(~m)),~m) => jacobins(u,m),
        jacobins((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                               (m^(1/2))*jacobicd(u,m),

        jacobins((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobins(u,m),
%Special Arguments
%-----------------
        jacobins(0,~m) => infinity,

        jacobins((1/2)*elliptick(~m),~m) => (1+((1-m)^(1/2)))^(1/2),

        jacobins(elliptick(~m),~m) => 1,

        jacobins((1/2)*i*elliptick!'(~m),~m) => -i*(m^(1/4)),

        jacobins((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                1/jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobins(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>(m^(1/4)),

        jacobins(i*elliptick!'(~m),~m) =>

                                      1/jacobisn(i*elliptick!'(~m),~m),

        jacobins((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>

                                               (1-((1-m)^(1/2)))^(1/2),

        jacobins(elliptick(~m)+i*elliptick!'(~m),~m) => m^(1/2),
%Derivatives, Integral
%---------------------
        df(jacobins(~u,~m),~u) => -jacobids(u,m)*jacobics(u,m),
        df(jacobins(~u,~m),~m) =>
                            -(df(jacobisn(u,m),m))/((jacobisn(u,m))^2),

        int(jacobins(~u,~m),~u) => ln(jacobids(u,m) - jacobics(u,m)),

%Calls Num_Jacobins when rounded switch is on.
%---------------------------------------------
        jacobins(~u,~m) => num_elliptic(num_jacobins, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobinsrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobids when the on rounded switch is
%used. It evaluates the value of Jacobids numerically.

procedure num_jacobids(u,m);

        num_jacobidn(u,m) / num_jacobisn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobids definition
%===================

operator jacobids;

%This rule list includes all the special cases of the Jacobids
%function.

jacobidsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobids(~u,0)   => csc u,
        jacobids(~u,1)   => csch u,
        jacobids(~u,-~m) => jacobids(u,m),
%Change of Argument
%------------------
        jacobids(-~u,~m)   =>-jacobids(u,m),

        jacobids((~u+elliptick(~m)),~m) => ((1-m)^(1/2))*jacobinc(u,m),
        jacobids((~u-elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobinc(u,m),
        jacobids((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobinc(u,m),

        jacobids((~u+2*elliptick(~m)),~m) => -jacobids(u,m),
        jacobids((~u-2*elliptick(~m)),~m) => -jacobids(u,m),
        jacobids((2*elliptick(~m)-~u),~m) =>  jacobids(u,m),
        jacobids((~u+i*elliptick!'(~m)),~m) =>
                                            -i*(m^(1/2))*jacobicn(u,m),

        jacobids((~u+2*i*elliptick!'(~m)),~m) => -jacobids(u,m),

        jacobids((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                               i*((1-m)^(1/2))*(m^(1/2))*jacobisd(u,m),

        jacobids((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                         jacobids(u,m),
%Special Arguments
%-----------------
        jacobids(0,~m) => infinity,

        jacobids((1/2)*elliptick(~m),~m) =>
                               ((1+((1-m)^(1/2)))^(1/2))*((1-m)^(1/4)),

        jacobids(elliptick(~m),~m) => (1-m)^(1/2),

        jacobids((1/2)*i*elliptick!'(~m),~m) =>
                                    -i*(m^(1/4))*((1+(m^(1/2)))^(1/2)),

        jacobids((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobidn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobids(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                       (m^(1/4))*((1-(m^(1/2)))^(1/2)),

        jacobids(i*elliptick!'(~m),~m) =>
                                      jacobidn(i*elliptick!'(~m),~m)
                                      / jacobisn(i*elliptick!'(~m),~m),

        jacobids((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                            -i*((1-m)^(1/4))*((1-((1-m)^(1/2)))^(1/2)),

        jacobids(elliptick(~m)+i*elliptick!'(~m),~m) => 0,

%Derivatives, Integral
%---------------------
        df(jacobids(~u,~m),~u) => -jacobics(u,m)*jacobins(u,m),
        df(jacobids(~u,~m),~m) =>
                                (jacobisn(u,m)*df(jacobidn(u,m),m)
                                - jacobidn(u,m)*df(jacobisn(u,m),m))
                                / ((jacobisn(u,m))^2),

        int(jacobids(~u,~m),~u) => ln(jacobins(u,m) - jacobics(u,m)),

%Calls Num_Jacobids when on rounded switch is on.
%------------------------------------------------
        jacobids(~u,~m) => num_elliptic(num_jacobids, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobidsrules;
%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%This procedure is called by Jacobics when the on rounded switch is
%used. It evaluates the value of Jacobics numerically.

procedure num_jacobics(u,m);

        num_jacobicn(u,m) / num_jacobisn(u,m);

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Jacobics definition
%===================

operator jacobics;

%This rule list includes all the special cases of the Jacobics
%function.

jacobicsrules :=
{
%When m=0 or 1, Change of Parameter
%----------------------------------
        jacobics(~u,0)   => cot u,
        jacobics(~u,1)   => csch u,
        jacobics(~u,-~m) => jacobics(u,m),
%Change of Argument
%------------------
        jacobics(-~u,~m)   =>-jacobics(u,m),

        jacobics((~u+elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisc(u,m),
        jacobics((~u-elliptick(~m)),~m) =>-((1-m)^(1/2))*jacobisc(u,m),
        jacobics((elliptick(~m)-~u),~m) => ((1-m)^(1/2))*jacobisc(u,m),
        jacobics((~u+2*elliptick(~m)),~m) =>  jacobics(u,m),
        jacobics((~u-2*elliptick(~m)),~m) =>  jacobics(u,m),
        jacobics((2*elliptick(~m)-~u),~m) => -jacobics(u,m),
        jacobics((~u+i*elliptick!'(~m)),~m)   => -i*jacobidn(u,m),
        jacobics((~u+2*i*elliptick!'(~m)),~m) => -jacobics(u,m),

        jacobics((~u+elliptick(~m)+i*elliptick!'(~m)),~m) =>
                                        -i*((1-m)^(1/2))*jacobind(u,m),

        jacobics((~u+2*elliptick(~m)+2*i*elliptick!'(~m)),~m) =>
                                                        -jacobics(u,m),
%Special Arguments
%-----------------
        jacobics(0,~m) => infinity,

        jacobics((1/2)*elliptick(~m),~m) => (1-m)^(1/4),

        jacobics(elliptick(~m),~m) => 0,

        jacobics((1/2)*i*elliptick!'(~m),~m) =>
                                              -i*((1+(m^(1/2)))^(1/2)),

        jacobics((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m) =>

                jacobicn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m)
                / jacobisn((1/2)*(elliptick(~m)+i*elliptick!'(~m)),~m),

        jacobics(elliptick(~m)+(1/2)*i*elliptick!'(~m),~m) =>
                                              -i*((1-(m^(1/2)))^(1/2)),

        jacobics(i*elliptick!'(~m),~m) =>
                                      jacobicn(i*elliptick!'(~m),~m)
                                      / jacobisn(i*elliptick!'(~m),~m),

        jacobics((1/2)*elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                      -i*((1-m)^(1/4)),

        jacobics(elliptick(~m)+i*elliptick!'(~m),~m) =>
                                                      -i*((1-m)^(1/2)),
%Derivatives, Integral
%---------------------
        df(jacobics(~u,~m),~u) => -jacobins(u,m)*jacobids(u,m),
        df(jacobics(~u,~m),~m) =>
                                ( jacobisn(u,m)*df(jacobicn(u,m),m)
                                - jacobicn(u,m)*df(jacobisn(u,m),m))
                                / ((jacobisn(u,m))^2),

        int(jacobics(~u,~m),~u) => ln(jacobins(u,m) - jacobids(u,m)),

%Calls Num_Jacobics when rounded switch is on.
%---------------------------------------------
        jacobics(~u,~m) => num_elliptic(num_jacobics, u, m)
                           when lisp !*rounded and numberp u
                           and numberp m
};
let jacobicsrules;
>> ;

endmodule;


module sfellipi;  % Procedures and Rules for Elliptic Integrals.

% Author: Lisa Temme, ZIB, October 1994

algebraic <<

%######################################################################
%DESCENDING LANDEN TRANSFORMATION

procedure landentrans(phi,alpha);

   begin scalar alpha_n!+1, alpha_n, phi_n!+1, phi_n, antoa0, pntop0,
                a0toan, p0topn;

        alpha_n := alpha;
        phi_n   := phi;
        antoa0 := {alpha_n};
        pntop0 := {phi_n};

        while alpha_n > 10^(-(symbolic !:prec!:)) do
           <<
                alpha_n!+1:= asin(2/(1+cos(alpha_n)) -1);
                phi_n!+1 := phi_n + (atan(cos(alpha_n)*tan(phi_n)))
                            + floor((floor(phi_n/(pi/2))+1)/2)*pi;

                antoa0 := alpha_n!+1.antoa0;
                pntop0 := phi_n!+1.pntop0;

                alpha_n := alpha_n!+1;
                phi_n   := phi_n!+1
           >>;

                a0toan := reverse(antoa0);
                p0topn := reverse(pntop0);
                return list(p0topn, a0toan)
   end;

%######################################################################
%VALUE OF EllipticF(phi,m)

procedure f_function(phi,m);

   begin scalar alpha, bothlists, a0toan, a1toan, p0topn, phi_n, y,
                elptf;

        alpha  := asin(sqrt(m));
        bothlists := landentrans(phi,alpha);
        a0toan := part(bothlists,2);
        a1toan := rest(a0toan);
        p0topn := part(bothlists,1);
        phi_n  := part(reverse(p0topn),1);

        if phi = (pi/2)
           then
                elptf := k_function(m)
           else
                elptf :=
                phi_n *for each y in a1toan product(1/2)*(1+sin(y));
        return elptf
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticF definition
%====================

operator ellipticf;

ellipticfrules :=
{
        ellipticf(~phi,0)   => phi,
        ellipticf(i*~phi,0) => i*phi,
        ellipticf(~phi,1)   => ln(sec(phi)+tan(phi)),
        ellipticf(i*~phi,1) => i*atan(sinh(phi)),
        ellipticf(~phi,~m)  => num_elliptic(f_function,phi,m)
                              when lisp !*rounded and numberp phi
                              and numberp m
};
let ellipticfrules;

%######################################################################
%VALUE OF K(m)

procedure k_function(m);

   begin scalar agm, an;

        agm := agm_function(1,sqrt(1-m),sqrt(m));
        an  := part(agm,2);
        return (pi / (2*an));
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticK definition
%====================

elliptickrules :=

{
        elliptick(~m)   => k_function(m)   when lisp !*rounded
                                                 and numberp m,

        elliptick!'(~m) => k_function(1-m) when lisp !*rounded
                                                 and numberp m
};
let elliptickrules;

%######################################################################
%VALUE OF EllipticE(phi,m)

procedure e_function(phi,m);

   begin scalar f, n, alpha, bothlists, a0toan, p0topn, a1toan, p1topn,
                sinalist, sinplist, b, s, blist, c, allz, w, z, allx,
                h, x, elpte;

        f := f_function(phi,m);
        alpha := asin(sqrt(m));

        bothlists := landentrans(phi,alpha);
        a0toan := part(bothlists, 2);
        p0topn := part(bothlists, 1);
        a1toan := rest(a0toan);
        p1topn := rest(p0topn);

        n := length(a1toan);

        sinalist := sin(a1toan);
        sinplist := sin(p1topn);

        b := part(sinalist,1);
        s := b;
        blist := for each c in rest sinalist collect << b := b*c >>;
        blist := s.blist;

        allz := 0;
        for w := 1:n do
           <<
                z := (1/(2^w))*part(blist,w);
                allz := allz + z
           >>;

        allx := 0;
        for h := 1:n do
           <<
                x := (1/(2^h))*((part(blist,h))^(1/2))
                              *  part(sinplist,h);

                allx := allx + x
           >>;

        elpte := f * (1 - (1/2)*((sin(part(a0toan,1)))^2)*(1 + allz))
                                           + sin(part(a0toan,1))*allx ;
        return elpte;
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%EllipticE(phi,m) definition
%====================

operator elliptice;

jacobierules :=

{
        elliptice(0,~m)     => 0,
        elliptice(~phi,0)   => phi,
        elliptice(i*~phi,0) => i*phi,
        elliptice(~phi,1)   => sin(phi),
        elliptice(i*~phi,1) => i*sinh phi,
        elliptice(-~phi,~m) => -elliptice(phi,m),
        elliptice(~phi,-~m) =>  ellpitice(phi,m),

        df(elliptice(~phi,~m),~phi) => jacobidn(phi,m)^2,
        df(elliptice(~phi,~m),~m)   =>

               m * (jacobisn(phi,m) * jacobicn(phi,m) * jacobidn(phi,m)
                     -  elliptice(phi,m) * jacobicn(phi,m)^2) / (1-m^2)
                     -  m * phi * jacobisn(phi,m)^2,

        elliptice(~phi,~m) => num_elliptic(e_function,phi,m)
                              when lisp !*rounded and numberp phi
                              and numberp m,

        elliptice(~m) => num_elliptic(e_function,pi/2,m)
                         when lisp !*rounded and numberp m
};
let jacobierules;

%######################################################################
%CALCULATING THE FOUR THETA FUNCTIONS
%Theta 1        (often written H(u) - and has period 4K)
%Theta 2        (often written H1(u) -and has period 4K)
%Theta 3        (often written Theta1(u) - and has period 2K)
%Theta 4        (often written Theta(u) - and has period 2K)

procedure num_theta(a,u,m);

   begin scalar n, new, all, z, q, total;

        n := if a>2 then 1 else 0;
        new := 100;                     % To initiate loop
        all := 0;
        z := (pi*u)/(2*elliptick(m));
        q := exp(-pi*elliptick(1-m)/elliptick(m));

        while new > 10^(-(symbolic !:prec!:)) do
          << new := if a =1 then
                        ((-1)^n)*(q^(n*(n+1)))*sin((2*n+1)*z)
                else if a=2 then (q^(n*(n+1)))*cos((2*n+1)*z)
                else if a=3 then (q^(n*n))*cos(2*n*z)
                else if a=4 then ((-1)^n)*(q^(n*n))*cos(2*n*z);
             all := new + all;
             n := n+1
           >>;
        return if a > 2 then (1 + 2*all)
                else   (2*(q^(1/4))*all);
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%Theta Functions

operator elliptictheta;


ellipticthetarules :=
{
%Theta1rules
%-----------
        elliptictheta(1,~u,~m) =>
                 num_elliptic(num_theta,1,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta(1,-~u,~m) => -elliptictheta(1,u,m),

        elliptictheta(1,~u+elliptick(~m),~m) =>  elliptictheta(2,u,m),

        elliptictheta(1,~u+(2*elliptick(~m)),~m) =>
                                                -elliptictheta(1,u,m),

        elliptictheta(1,~u+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(4,u,m),

        elliptictheta(1,~u+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(1,u,m),

        elliptictheta(1,~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(3,u,m),

        elliptictheta(1,~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(1,u,m),

%Theta2rules
%-----------
        elliptictheta(2,~u,~m) =>
                 num_elliptic(num_theta,2,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta(2,-~u,~m) =>  elliptictheta(2,u,m),

        elliptictheta(2,~u+elliptick(~m),~m) => -elliptictheta(1,u,m),

        elliptictheta(2,~u+(2*elliptick(~m)),~m) =>
                                                -elliptictheta(2,u,m),

        elliptictheta(2,~u+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(3,u,m),

        elliptictheta(2,~u+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(2,u,m),

        elliptictheta(2,~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                        -i*(exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(4,u,m),

        elliptictheta(2,~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(2,u,m),

%Theta3rules
%-----------
        elliptictheta(3,~u,~m) =>
                 num_elliptic(num_theta,3,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta(3,-~u,~m) =>  elliptictheta(3,u,m),

        elliptictheta(3,~u+elliptick(~m),~m) =>  elliptictheta(4,u,m),

        elliptictheta(3,~u+(2*elliptick(~m)),~m) =>
                                                 elliptictheta(3,u,m),

        elliptictheta(3,~u+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(2,u,m),
        elliptictheta(3,~u+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(3,u,m),

        elliptictheta(3,~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(1,u,m),

        elliptictheta(3,~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                   (exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(3,u,m),

%Theta4rules
%-----------
        elliptictheta(4,~u,~m) =>
                 num_elliptic(num_theta,4,u,m) when lisp !*rounded
                                  and numberp u and numberp m,

        elliptictheta(4,-~u,~m) =>  elliptictheta(4,u,m),

        elliptictheta(4,~u+elliptick(~m),~m) =>  elliptictheta(3,u,m),

        elliptictheta(4,~u+(2*elliptick(~m)),~m)=>elliptictheta(4,u,m),

        elliptictheta(4,~u+i*elliptick!'(~m),~m) =>
                         i*(exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(1,u,m),
        elliptictheta(4,~u+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(4,u,m),

        elliptictheta(4,~u+elliptick(~m)+i*elliptick!'(~m),~m) =>
                           (exp(-i*pi*0.5*u/elliptick(m)))*(q^(-1/2))
                                                *elliptictheta(2,u,m),

        elliptictheta(4,~u+2*elliptick(~m)+2*i*elliptick!'(~m),~m) =>
                                  -(exp(-i*pi*u/elliptick(m)))*(q^-1)
                                                *elliptictheta(4,u,m),
%Error
%-----
        elliptictheta(~a,~u,~m) =>

            printerr ("In EllipticTheta(a,u,m);   a = 1,2,3 or 4.")
                         when numberp a
                                    and not(fixp a and a<5 and a>0)
};
let ellipticthetarules;

%######################################################################
%CALCULATING ZETA

procedure zeta_function(u,m);

   begin scalar phi_list, clist, l, j, z, cn, phi_n;

        phi_list := phi_function(1,sqrt(1-m),sqrt(m),u);
        clist := part(agm_function(1,sqrt(1-m),sqrt(m)),5);
        l := length(phi_list);
        j := 1;
        z := 0;
        while j < l do
           <<
                cn    := part(clist,l-j);
                phi_n := part(phi_list,1+j);
                z := cn*sin(phi_n) + z;
                j := j+1
           >>;
        return z
   end;

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%JacobiZETA definition
%=====================

operator jacobizeta;

jacobizetarules :=

{

        jacobizeta(~u,0)     => 0,
        jacobizeta(~u,1)     => tanh(u),
        jacobizeta(-~u,~m)   => -jacobizeta(u,m),
        jacobizeta(~u+~v,~m) => jacobizeta(u,m) + jacobizeta(v,m) -
                                (m*jacobisn(u,m)*jacobisn(v,m)
                                                 *jacobisn(u+v,m)),

        jacobizeta(~u+2*elliptick(~m),m) => jacobizeta(u,m),
        jacobizeta(elliptick(~m) - ~u,m) =>
                                        -jacobizeta(elliptick(m)+u,m),

%       JacobiZeta(~u,~m) => JacobiZeta(u - EllipticK(m),m) -
%                            m * Jacobisn(u - EllipticK(m),m)
%                              * Jacobicd(u - EllipticK(m),m),

        jacobizeta(~u,~m) => num_elliptic(zeta_function,u,m)
                             when lisp !*rounded and numberp u
                             and numberp m
};
let jacobizetarules;
%######################################################################
>>;
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

algebraic operator fresnel_c, fresnel_s, erfc,erfi;

algebraic operator ci, si, s_i, shi, chi;

algebraic let limit(si(~tt),~tt,infinity) => pi/2;

algebraic
let { int(sin(~tt)/~tt,~tt,0,~z) => si (z),
      int(cos(~a*~x)*sin(~b*~x)/x,x) => 1/2*si(a*x+b*x)-1/2*si(a*x-b*x),
      int(cos(~a*~x)*sin(~x)/x,x) => 1/2*si(a*x+x)-1/2*si(a*x-x),
      int(cos(~x)*sin(~b*~x)/x,x) => 1/2*si(x+b*x)-1/2*si(x-b*x),
      int(cos(~x)*sin(~x)/x,x) => 1/2*si(2*x),
      si(0) => 0,
      si(-~x) => (- si(x)),
      df(si(~x),~x) => sin(x)/x  ,
      si(~x) => compute_int_functions(x,si)
                 when numberp x and lisp !*rounded
    };

algebraic
let { int(sin(~tt)/~tt,~tt,~z,infinity) => - s_i (z),
      limit(s_i(~tt),x,infinity) => 0,
      s_i(~x) => si(x) - pi/2,
      df(s_i(~x),~x) => sin(x)/x
    };

algebraic
let { int(exp(~tt)/~tt,~tt,-infinity,~z) =>  ei (z),
      df(ei(~x),~x) => exp(x)/x,
      ei(~x) => compute_int_functions(x,ei)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(cos(~tt)/~tt,~tt,~z,infinity) => - ci (z),
      int((cos(~tt) -1)/~tt,~tt,0,~z) => ci (z) + psi(1) -log(z),
% psi(1) may be replaced by euler_gamma one day ...
      ci(-~x) => - ci(x) -i*pi,
      df(ci(~x),~x) => cos(x)/x,
      ci(~x) => compute_int_functions(x,ci)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(sinh(~tt)/~tt,~tt,0,~z) => shi (z),
      df(shi(~x),~x) => sinh(x)/x  ,
      shi(~x) => compute_int_functions(x,shi)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int((cosh(~tt) -1)/~tt,~tt,0,~z) => chi (z) + psi(1) -log(z),
% psi(1) may be replaced by euler_gamma one day ...
      df(chi(~x),~x) => cosh(x)/x  ,
      chi(~x) => compute_int_functions(x,chi)
         when numberp x and abs(x) <= 20 and lisp !*rounded
    };

algebraic
let { int(sin(pi/2*~tt^2),~tt,0,~z) => fresnel_s (z),
      fresnel_s(-~x) => (- fresnel_s (x)),
      fresnel_s(i* ~x) => (-i*fresnel_s (x)),
      limit(fresnel_s(~tt),~tt,infinity) => 1/2,
      df(fresnel_s(~x),~x) => sin(pi/2*x^2) ,
      fresnel_s (~x) => compute_int_functions(x,fresnel_s)
              when numberp x and abs(x) <= 10 and lisp !*rounded };

algebraic
let { int(cos(pi/2*~tt^2),~tt,0,~z) => fresnel_c (z),
      fresnel_c(-~x) => (- fresnel_c (x)),
      fresnel_c(i* ~x) => (i*fresnel_c (x)),
      limit(fresnel_c(~tt),~tt,infinity) => 1/2,
      df(fresnel_c(~x),~x) => cos(pi/2*x^2) ,
      fresnel_c (~x) => compute_int_functions(x,fresnel_c)
               when numberp x and abs(x) <= 10 and lisp !*rounded };

algebraic
let { limit (erf(~x),~x,infinity) => 1,
      limit (erfc(~x),~x,infinity) => 0,
      erfc (~x) => 1-erf(x),
      erfi(~z)  => -i * erf(i*z),
      int(1/e^(~tt^2),~tt,0,~z) => erf(z)/2*sqrt(pi),
      int(1/e^(~tt^2),~tt,~z,infinity) => erfc(z)/2*sqrt(pi),
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
