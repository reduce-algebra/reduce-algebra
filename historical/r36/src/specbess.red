module specbess;  % Special functions package; Bessel and relatives.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...
%          contribution from various authors ...

remprop('besseli,'simpfn);
remprop('besselj,'simpfn);
remprop('bessely,'simpfn);
remprop('besseli,'simpfn);
remprop('besselk,'simpfn);
remprop('hankel1,'simpfn);
remprop('hankel2,'simpfn);
remprop('kummerm,'simpfn);
remprop('kummeru,'simpfn);
remprop('struveh,'simpfn);
remprop('struvel,'simpfn);
remprop('lommel1,'simpfn);
remprop('lommel2,'simpfn);
remprop('whittakerm,'simpfn);
remprop('whittakerw,'simpfn);
remprop('airy_ai,'simpfn);
remprop('airy_bi,'simpfn);
remprop('airy_aiprime,'simpfn);
remprop('airy_biprime,'simpfn);


create!-package ('(specbess sfbes sfkummer sfother sfairy),
                 '(contrib specfn));

symbolic smacro procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   (if new!*bfs then lispeval '!:bprec!: else !:prec!:);

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

besselj(~n,~z)  =>  sqrt(2/(pi*z)) * cos(z)
   when numberp n and n = -1/2,

bessely(~n,~z)  =>  sqrt(2/(pi*z)) * sin(z)
   when numberp n and n = -1/2,

bessely(~n,~z)  =>  - sqrt(2/(pi*z)) * cos(z)
   when numberp n and n = 1/2,

besselk(~n,~z)  =>  sqrt(pi/(2*z))*e^(-z)
   when numberp n and (n = 1/2 or n=-1/2),

besseli(~n,~z)  =>  1/sqrt(pi*2*z)*(e^z - e^(-z))
   when numberp n and n = 1/2,

besseli(~n,~z)  =>  1/sqrt(pi*2*z)*(e^z + e^(-z))
   when numberp n and n = -1/2,

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

% AS (9.1.26 and 27)
df(besselj(~n,~z),z)  =>  besselj(n-1,z) - (n/z) * besselj(n,z),
df(bessely(~n,~z),z)  =>  bessely(n-1,z) - (n/z) * bessely(n,z),
df(besselk(~n,~z),z)  =>  - besselk(n-1,z) - (n/z) * besselk(n,z),
df(hankel1(~n,~z),z)  =>  hankel1(n-1,z) - (n/z) * hankel1(n,z),
df(hankel2(~n,~z),z)  =>  hankel2(n-1,z) - (n/z) * hankel2(n,z),
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
         and not(z=0 and repart(1-b) < 0)
         and ((a-b) neq floor repart (a-b) or (a-b) > -1),

kummeru(~a,~b,~z)  =>  ( pi / sin (pi * b)) *
      ( -((z**(1-b)) * (kummerm(1+a-b,2-b,z)/(gamma(a) * gamma(2-b)))))
   when numberp b and (impart b neq 0 or b neq floor b)
      and not(z=0 and repart(1-b) < 0)
                % ComplexInfinity otherwise, but we can't calculate with
                % CI.
      and numberp a and (impart a neq 0 or a neq floor a or a > 0),

kummerm(~a,~b,~z)  =>  exp z     when a = b,

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

%%df(kummerM(~a,~b,~z),z)  =>  (a/b) * kummerM(a+1, b+1, z),

%%df(kummerU(~a,~b,~z),z)  =>  -a * kummerU(a+1,b+1,z)

% AS (13.4.13)
df(kummerm(~a,~b,~z),z)  =>
        1/z*((b-a)*kummerm(a-1,b,z)-(b-a-z)*kummerm(a,b,z)),
% AS (13.4.26)
df(kummeru(~a,~b,~z),z)  =>
        (- kummeru(a-1,b,z) + (a-b+z)*kummeru(a,b,z))/z

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
   (2/pi) - struveh(1,z) when numberp n and n = 0,

df(struveh(~n,~x),x) => (x*struveh(-1 + n,x)- n*struveh(n,x))/x,

df((z**n)*struveh(~n,~z),z)  => (z**n)*struveh(n-1,z),

df((z**(-n))*struveh(~n,~z),z)  =>
   (1/(sqrt(pi)*(2**n)*gamma(n+(3/2)))) - (z**(-n))*struveh(n+1,z),


struveh(~n,~z)  =>
   ((-1)**n)*besselj(-n,z)
      when numberp n and impart n = 0
         and n < 0 and (n*2)=floor(n*2) and not evenp floor(n*2),

struveh(~n,~z)  =>
   ((2/(pi*z))**(1/2))*(1-cos z) when numberp n and n=1/2,

struveh(~n,~z)  =>
   ((z/(pi*2))**(1/2)) * (1+(2/(z**2))) -
      ((2/(pi*z))**(1/2)) * (sin z + ((cos z)/z))
      when numberp n and n=3/2,

struveh(~n,~x) => (x*0.5)^(n+1)*struve_compute_term(n,x,h)
          when numberp x and numberp n and symbolic !*rounded,

struvel(~n,~x) => struve_compute_term(n,x,l)
          when numberp x and numberp n and symbolic !*rounded,

struvel(~n,~z)  =>
   besseli(-n,z)
      when numberp n and impart n = 0
         and n < 0 and (n*2)=floor(n*2) and not evenp floor(n*2),

struvel(~n,~z)  =>
   -i*(e**((-i*n*pi)/2))*struveh(n,i*z) when symbolic !*complex,

df(struvel(~n,~x),x) => (x*struvel(-1 + n,x)- n*struvel(n,x))/x

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
   (sqrt(pi)*(2**a)*gamma((2*a + 1)/2)*struveh(a,z))/2 when a = b,

lommel2(~a,~b,~z)  => z**b when numberp a and numberp b and a = b+1,

lommel2(~a,~b,~z)  => lommel2(a,-b,z)
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
   exp(-z/2)*(z**(1/2+m))*kummeru(1/2+m-k,1+2*m,z),

df(whittakerm(~n,~m,~z),z)  => 1/(2*z)*
        ((1+2*m-2*n)*whittakerm(n-1,m,z) + (2*n-z)*whittakerm(n,m,z)),

df(whittakerw(~n,~m,~z),z)  => 1/(4*z)*
        ((1-4*m^2-4*n+4*n^2)*whittakerw(n-1,m,z)
                 + (4*n-2*z)*whittakerw(n,m,z))
% AS (8.5.4)

})$

algebraic (let whittaker!*rules);

%Handbook of Mathematical Functions - page 496

algebraic procedure struve_compute_term(n,x,h_or_l);

begin scalar dmode!*!*;
  lisp(dmode!*!* :=  dmode!*);
 return
  begin scalar pre,term,k,precis,result,!*complex,!*rounded,
   dmode!*,expo,!*msg;
   lisp (dmode!* := dmode!*!*);
  if h_or_l = l
        then << on complex;
                off rounded;
                expo := e^(-i*n*pi/2);
                on rounded;
                return  (-i*expo*struveh(n,i*x))>>
  else <<
   pre := precision 0;
   precis := 10.0^(-pre-2);
   result := 0;

    << if n > -2 then <<k:=1, term := 2^(n+2)/(pi *
                        (for i:= 1 :n+1 product(2i-1))) ;
                        result := term >>
        else for kk:=0:-(n+2) do << k:=kk+1;
                        term := (-1)^kk*(1/2*x)^(2*kk)/
                                (gamma(kk+3/2) * gamma(kk+n+3/2));
                        result := result + term>>;
        while abs(term) > precis do
          <<  term:= term*(-0.25)*(x^2)/((k+0.5)*(k+n+0.5));
              result := result + term;
              k := k+1>>;
  >>;  >>;
  return result;
end; end;

symbolic operator struve_compute_term;

% Lambert's W  (Omega) function.
% see: "On Lambert's W function" by R. Corless, G. Gonnet et. al.
% only the principal branch is implemented

algebraic <<

    % Remove autoload properties.
 lisp null remprop('lambert_w,'simpfn);
 lisp null remflag('(lambert_w),'full);

 operator lambert_w;

 let {  lambert_w(0) => 0,
        lambert_w(-1/e) => -1,
        sum((- ~n)^(n-1)/factorial n *~z^n,n,1,infinity)
                        => lambert_w(z),
        df(lambert_w(~z),z) => 1/((1 + lambert_w(z))*e^lambert_w z),
        log(lambert_w(~z)) => log(z) - lambert_w z,
        e^(lambert_w ~z) => ~z/lambert_w z,
        int(lambert_w(~z),z) => z*(lambert_w z -1 +1/lambert_w z),
        lambert_w(~z) =>  num_lambert_w(z)
                when numberp z and lisp !*rounded};

procedure num_lambert_w(z);

     if z=0 then 0 else

       begin scalar wjnew,wj,accu,expwj,oldprec,!*complex,olddmode!*;

         lisp setq(olddmode!* ,dmode!*);
         on complex;
         oldprec := precision 5;
         accu := 10^(- lisp !:prec!:);
         if (abs z) <= 1 then  % starting point for iteration
                 if z >= -1/e then wj := 0 else wj := log(z)
         else wj := log(z) - log(log(z));
         wjnew := 100;
         while abs(wjnew) > accu do <<
             expwj := exp(wj);
             wjnew := - (wj*expwj -z)/
                (expwj*(wj+1)-(1/2(wj+2)*(wj*expwj -z))/(wj+1));
             wj := wj + wjnew >>;

         precision oldprec;
         accu := 10^(- lisp !:prec!:);
         while abs(wjnew) > accu do <<
             expwj := exp(wj);
             wjnew := - (wj*expwj -z)/
                (expwj*(wj+1)-(1/2(wj+2)*(wj*expwj -z))/(wj+1));
             wj := wj + wjnew >>;
        lisp setq(dmode!*,olddmode!*);
         return wj;
    end;

>>;

endmodule;


module sfairy;  % Procedures and Rules for the Airy functions.

%***********************************************************************
%
%The following is the code to evaluate Airy Functions and their primes
%using REDUCE.
%
%Author: Stephen Scowcroft                        Date: September 1994
%
%***********************************************************************

%The first section deals with code that evaluates the Airy Functions.
%The second deals with code that evaluates the Airyprime Functions.

%For the sake of efficiency a recursive approach has been taken for all
%expressions. As a result the equations do not directly resemble those
%given in "The Handbook of Mathematical Functions" (Abramowitz & Stegun)
%although this is the source of the expressions.

% The following procedures evaluate the fseries and gseries which are
% used in the ascending series approach to calculating Airy_Ai and
% Airy_Bi.

algebraic procedure myfseries(z);

%Declared local variables used throughout the procedure.

  begin scalar summ,accu,term,zcube,int1,int2;

%These are the initial values of variables used in the procedure.

     summ := 1;
     int1 := 2;
     int2 := 3;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1;
     zcube := (z ^ 3);

%This loop calculates term without a check with the accuracy. As a
%result the code is faster and more efficient.

     for kk:=0:30 do
     <<  term := term * zcube / ((int1) * (int2));
         summ := summ + term;
         int1 := int1 + 3;
         int2 := int2 + 3;
      >>;

%Now the check against the accuracy is carried out in order to bring the
% infinite sum to an approximate summation for use later on.

     while abs(term) > accu do
     <<  term := term * zcube / ((int1) * (int2));
         summ := summ + term;
         int1 := int1 + 3;
         int2 := int2 + 3;
      >>;

%The value of the infinite sum is then returned for use in calculating
%the function.

  return summ;

end;

%This is similar to the above code. As a result the comments above
%are valid here.

algebraic procedure mygseries(z);

  begin scalar k,summ,accu,term,zcube,int1,int2;
     summ := z;
     int1 := 3;
     int2 := 4;
     accu := 10 ^(-(symbolic !:prec!:));
     term := summ;
     zcube := (z ^ 3);

     for kk:=0:30 do
     << term := term * zcube / ((int1)* (int2));
        summ := summ + term;
        int1 := int1 + 3;
        int2 := int2 + 3;
      >>;

     while abs(term) > accu do
     << term := term * zcube / ((int1)* (int2));
        summ := summ + term;
        int1 := int1 + 3;
        int2 := int2 + 3;
      >>;

  return summ;
end;

%The following procedure calls the above f and g series in order to
%calculate the Airy_Ai and Airy_Bi for specific values of z.
%There is one expression for either the Ai or Bi evaluation. This is
%because each is similar.

%The code selects which expression to calculate depending on the value
%of proc. This is done automatically every time the procedure is called.

algebraic  procedure airya2(z,proc);

  begin scalar c1,c2,summ,oldprec;

%In order to calculate the infinite sums with a high accuracy, the
%precision is changed using the following code.
%This is done automatically each time the function is called. The
%precision is then reset to the original value.

   oldprec := precision 0;
   precision (oldprec + 10);

%Initial value used within the equation.

   c1 := (3 ^ (-2/3)) / gamma(2/3);
   c2 := (3 ^ (-1/3)) / gamma(1/3);

%This part selects automatically either Ai or Bi depending on proc.

   if proc=ai then summ := (c1 * myfseries(z)) - (c2 * mygseries(z))
   else summ := sqrt(3) *  ((c1 * myfseries(z)) + (c2 * mygseries(z)));
   precision (oldprec);

 return summ;

 end;

%The following code is the procedures for calculating the infinite sums
%used in the evaluation of the asymptotic expansions of Airy Functions.

%Again this code is used in the expression for Ai and Bi. As a result
%depending on the value of proc the correct one is called.

algebraic procedure asum1(z,proc);

  begin scalar p,k,summ,accu,term,zterm;

%Initial values that are used within the procedure.

     summ := 1;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1 ;
     zterm := (2/3 * (z ^ (3/2)));

%A check to see when the infinite sum should be stopped.

     while abs(term) > accu do
     <<
        term := term * ((if proc=ai then -1 else 1) * ((3k-1/2) *
                 (3k-3/2) * (3k-5/2))
                   / (54 * (k) * (k-1/2))) / zterm;
        summ := summ + term;
        k := k+1;
      >>;

  return summ;
end;

%The following are similar to the code for asum1. As a result the above
%comments apply.

algebraic procedure asum2(z);

  begin scalar p,k,summ,accu,term,sqzterm,sqnum;
     summ := 1;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1;
     sqzterm := (2/3 * (z ^ (3/2))) ^ 2;
     sqnum := (54 ^ 2);

     while abs(term) > accu do
     <<  term := term * ((-1) * ((6k-5.5)*(6k-4.5)*(6k-3.5)*(6k-2.5)
                      *(6k-1.5)*(6k-0.5) / (sqnum * (2k)*(2k-1)
                      *(2k-1.5)*(2k-0.5)))) / sqzterm;

         summ := summ + term;
         k := k+1;
      >>;

  return summ;
end;


algebraic procedure asum3(z);

  begin scalar p,k,summ,accu,term,zterm,sqzterm,sqnum;
     zterm := (2/3 * (z ^ (3/2)));
     sqzterm := zterm ^ 2;
     sqnum := 54 ^ 2;
     summ := ((3/2)*(5/2) / 54) / zterm;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := ((3/2)*(5/2) / 54) / zterm;

     while abs(term) > accu do
     <<  term := term * ((-1) * ((6k+3)-1/2)*((6k+3)-3/2)*
                        ((6k+3)-5/2)*((6k+3)-7/2)*((6k+3)-9/2)
                       *((6k+3)-11/2)
                         /( sqnum * (2k)*(2k+1)
                      *((2k -1/2)*(2k+1/2)))) / sqzterm;

         summ := summ + term;
         k := k+1;
      >>;

  return summ;
end;

%There are two procedures depending on certain criteria for the arg of z
%for both Ai and Bi. They are asymptotic for large values of (-z) and z
%respectively. The choice as to which one is called for large values of
%z is determined in later code.

%Once again, as the expression for Ai and Bi is similar the code has
%been combined.

algebraic procedure asairyam(minusz,proc);

  begin scalar tt,p,ee,summ;
    z := - minusz;
    tt := (z ^ (-1/4));
    p := (pi ^ (-1/2));
    ee := (2/3 * (z ^ (3/2))) + (pi/4);

    if proc=ai then summ := tt * p * ((sin(ee) * asum2(z)) - (cos(ee)
                 * asum3(z)))
    else summ := tt * p * ((cos(ee) * asum2(z)) + (sin(ee) * asum3(z)));
    return summ;
   end;



algebraic procedure asairyap(z,proc);

  begin scalar tt,p,ee,summ;
    tt := (z ^ (-1/4));
    p := (pi ^ (-1/2));
    ee := e ^ ((if proc=ai then -1 else 1)*(2/3 * (z ^ (3/2))));
    if proc=ai then summ := (1/2) * tt * p * ee * asum1(z,ai)
    else summ := tt * p * ee * asum1(z,bi);
    return summ;
   end;

%The following section are the procedures that deal with the evaluation
%of the Airyprime functions.

%Similarly f and g series are calculated for use within the standard
%series approach. The same techniques for obtaining efficiency that were
%used in the code above are used here. As a result comments above apply.


algebraic procedure myfseriesp(z);

  begin scalar k,summ,accu,term,zcube,int1,int2;
     summ := ((z^2) / 2);
     int1 := 3;
     int2 := 5;
     accu := 10 ^(-(symbolic !:prec!:));
     term := ((z^2) / 2);
     zcube := z ^ 3;

     for kk:=0:30 do
     <<  term := term * zcube / ((int1) * (int2));
         summ := summ + term;
         int1 := int1 + 3;
         int2 := int2 + 3;
      >>;

     while abs(term) > accu do
     <<  term := term * zcube / ((int1) * (int2));
         summ := summ + term;
         int1 := int1 + 3;
         int2 := int2 + 3;
      >>;

  return summ;

end;

algebraic procedure mygseriesp(z);

  begin scalar k,summ,accu,term,zcube,int1,int2;
     summ := 1;
     int1 := 3;
     int2 := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1;
     zcube := z ^ 3;

     for kk:=0:30 do
     << term := term * zcube / ((int1) * (int2));
        summ := summ + term;
        int1 := int1 + 3;
        int2 := int2 + 3;
      >>;

     while abs(term) > accu do
     << term := term * zcube / ((int1) * (int2));
        summ := summ + term;
        int1 := int1 + 3;
        int2 := int2 + 3;
      >>;

  return summ;
end;

%Once again, the code for Aiprime and  Biprime is similar and have been
%combined.

algebraic procedure airyap(z,proc);

  begin scalar c1,c2,summ,oldprec;
  oldprec := precision 0;
  precision (oldprec + 10);
  c1 := (3 ^ (-2/3)) / gamma(2/3);
  c2 := (3 ^ (-1/3)) / gamma(1/3);
  if proc=aiprime
    then summ := (c1 * myfseriesp(z)) - (c2 * mygseriesp(z))
   else summ :=  sqrt(3)*((c1 * myfseriesp(z)) + (c2 * mygseriesp(z)));
  precision(oldprec);
  return summ;
end;

%The following are the procedures for calculating the infinite sums used
%in the evaluation of the asymptotic expansion of Airyprime functions.

algebraic procedure apsum1(z,proc);

  begin scalar p,k,summ,accu,term,zterm;
     summ := 1;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1;
     zterm := 2/3 * (z ^ (3/2));

     while abs(term) > accu do
     <<
        term := term * ((if proc=aiprime then -1 else 1)
                       * ((6k-7)/(6k-5) * (6k+1)/(6k-1))
                         *((3k -1/2)*(3k-3/2)*(3k-5/2)) /
                       (54 * k * (k-1/2))) / zterm;
         summ := summ + term;
         k := k+1
      >>;

  return summ;
end;

algebraic procedure apsum2(z);

  begin scalar p,k,summ,accu,term,sqzterm,sqnum;
     summ := 1;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := 1;
     sqzterm := ((2/3 * (z ^ (3/2))) ^ 2);
     sqnum := (54 ^2);

     while abs(term) > accu do
     <<  term := term * ((-1) * ((12k-13)/(12k-11) * (12k+1)/(12k-1))
                 *((6k-5.5)*(6k-4.5)*(6k-3.5)*(6k-2.5)*(6k-1.5)
                  *(6k-0.5)) / (sqnum*(2k)*(2k-1)*(2k-1.5)*(2k-0.5))
                / sqzterm);
         summ := summ + term;
         k := k+1
      >>;

  return summ;
end;

algebraic procedure apsum3(z);

  begin scalar p,k,summ,accu,term,zterm,sqzterm,sqnum;
     zterm := (2/3 * (z ^ (3/2)));
     sqzterm := zterm ^2;
     sqnum := 54 ^ 2;
     summ := (-7/5) * ((3/2)*(5/2) / 54)/ zterm;
     k := 1;
     accu := 10 ^(-(symbolic !:prec!:));
     term := (-7/5) * ((3/2)*(5/2) / 54)/ zterm;

     while abs(term) > accu do
     <<  term := term * ((-1) * ((12k-7)/(12k-5) * (12k+7)/(12k+5)))
                 *((6k+3)-1/2)*((6k+3)-3/2)*((6k+3)-5/2)*((6k+3)-7/2)*
                 ((6k+3)-9/2)*((6k+3)-11/2) / (sqnum * (2k)*(2k+1) *
                 ((2k-1/2)*(2k+1/2)))/ sqzterm;
         summ := summ + term;
         k := k+1
      >>;

  return summ;
end;

%Once again the procedures which call the above infinite sums to
%calculate Aiprime and Biprime have been combined.

algebraic procedure airyapp(z,proc);

  begin scalar tt,p;
    tt := (z ^ (1/4));
    p := (pi ^ (-1/2));
    ee := e ^ ((if proc=aiprime then -1 else 1)*(2/3 * (z ^ (3/2))));
    if proc=aiprime then summ := (1/2) * tt * p * ee * apsum1(z,ai)
    else summ := tt * p * ee * apsum1(z,bi);
    return summ;
   end;


algebraic procedure airyapm(z,proc);

  begin scalar tt,p,ee,summ;
    tt := (z ^ (1/4));
    p := (pi ^ (-1/2));
    ee := (2/3 * (z ^ (3/2))) + (pi/4);
    if proc=aiprime then summ := tt * (-p) * ((cos(ee) * apsum2(z))
                 + (sin(ee) * apsum3(z)))
    else summ := tt*p*((cos(ee) * apsum2(z)) - (sin(ee) * apsum3(z)));
    return summ;
   end;


%When using both standard series and asymptotic approaches for the
%evaluation of Airy functions, there is a point when it is more
%efficient to use the asymptotic approach.

%It therefore remains to choose a value of z where this change over
%occurs. This choice depends on the precision desired.
%A table showing various values of z and the given precision where the
%change should take place was found. This has been implemented below.

%The table appears in a paper called "Numerical Evaluation of airy
%functions with complex arguments" (Corless,Jefferey,Rasmussen),
%J. Comput Phys. 99(1992), 106-114"

algebraic procedure ai_asymptotic(absz);

    begin scalar prec;
       prec := lisp !:prec!:;
       return
         if prec <= 6 and absz > 5 then 1
         else if prec <= 12 and absz > 8 then 1
         else if prec <= 16 and absz > 10 then 1
         else if prec <= 23 and absz > 12 then 1
         else if prec <= 33 and absz > 15 then 1
         else 0 ;
    end;

%Finally the following code deals with selecting the correct approach a
%function should take, depending on z, the above table and the upper
%bounds of the asymptotic functions.

%This procedure also allows for the user to call the correct evaluation
%of an Airy function from the Reduce command line argument.

algebraic procedure num_airy(z,fname);

   begin scalar summ;

%This is the procedure to evaluate Airy_ai of z.

 if fname = ai then <<
    if ai_asymptotic(abs(z)) = 1 then
        <<if abs(arg(-z)) < ((2/3)*pi) then summ:= asairyam(z,ai)
        else if abs(arg(z)) < pi then summ := asairyap(z,ai);
        >>
     else summ := airya2(z,ai);

   return summ; >>

%This is the procedure to evaluate Airy_bi of z.
%Similar procedures for Airy_aiprime and Airy_biprime follow.

 else if fname = bi then <<
     if ai_asymptotic(abs(z)) = 1 then
<<    if abs(arg(-z)) < ((2/3)*pi) then summ := asairyam(z,bi)
       else if abs(arg(z)) < ((1/3)*pi)  then summ := asairyap(z,bi);
>>
   else summ := airya2(z,bi);
    return summ; >>

 else if fname = aiprime then <<
      if ai_asymptotic(abs(z)) = 1 then
<<
       if abs(arg(-z)) < (2/3) * pi then summ := airyapm(z,aiprime)
       else if abs(arg(z)) < pi then summ := airyapp(z,aiprime);
>>
       else summ := airyap(z,aiprime);
    return summ; >>

 else if fname = biprime then <<
       if ai_asymptotic(abs(z)) = 1 then
<<
       if abs(arg(-z)) < ((2/3)*pi) then summ := airyapm(z,biprime)
       else if abs(arg(z)) < ((1/3)*pi) then summ := airyapp(z,biprime);
>>
       else  summ := airyap(z,biprime);
       return summ;>>

   end;


algebraic <<
operator airy_ai, airy_bi, airy_aiprime, airy_biprime;

%The following deals with the trivial cases of all of the Airy and
%Airyprime functions. It also calls the above code to allow the user to
%evaluate each of the four Airy function cases respectively.
%The rule for differentiation are also described.

airy_rules := { airy_ai(0) => (3 ^ (-2/3)) / gamma(2/3),
                airy_ai(~z) => num_airy (z,ai)
                        when symbolic !*rounded and numberp z,
                df(airy_ai(~z),z) => airy_aiprime(z),

                airy_bi(0) => sqrt(3) * (3 ^ (-2/3)) / gamma(2/3),
                airy_bi(~z) => num_airy (z,bi)
                        when symbolic !*rounded and numberp z,
                df(airy_bi(~z),z) => airy_biprime(z),

                airy_aiprime(0) => -((3 ^ (-1/3)) / gamma(1/3)),
                airy_aiprime(~z) => num_airy (z,aiprime)
                        when symbolic !*rounded and numberp z,
                df(airy_aiprime(~z),z) => z * airy_ai(z),

                airy_biprime(0) => sqrt(3) * (3 ^ (-1/3)) / gamma(1/3),
                airy_biprime(~z) => num_airy (z,biprime)
                        when symbolic !*rounded and numberp z,
                df(airy_biprime(~z),z) => z * airy_bi(z)
               };

%This activates the above rule set.

let airy_rules;

%The following is an inactive rule set that can be activated by the user
%if desired.
%When activated, it will represent the Airy functions in terms of Bessel
%Functions.

airy2bessel_rules :=
{ airy_ai(~z) => (1/3) * sqrt(z) * << (besseli(-1/3,ee) -
                 besseli(1/3,ee))
                  where ee => (2/3 * (z ^ (3/2))) >>
                  when numberp z and repart z >=0 ,

airy_ai(~minusz) => <<(sqrt(z/3) * besselj(1/3,ee) + besselj(-1/3,ee))
                  where {ee => (2/3 * (z ^ (3/2))) , z => -minusz} >>
                  when numberp z and repart z <=0,

airy_aiprime(~z) => -(z/3 * << (besseli(-2/3,ee) - besseli(2/3,ee))
                  where ee => (2/3 * (z ^ (3/2))) >>)
                  when numberp z and repart z >=0,

airy_aiprime(~minusz) => << (-(z)/3) * (besselj(-2/3,ee) -
                 besselj(2/3,ee))
                   where {ee => (2/3 * (z ^ (3/2))) , z => -minusz} >>
                   when numberp z and repart z <=0,

airy_bi(~z) => sqrt(z/3) * << (besseli(-1/3,ee) + besseli(1/3,ee))
                   where ee => (2/3 * (z ^ (3/2))) >>
                   when numberp z and repart z >=0,

airy_bi(~minusz) => << sqrt(z/3) * (besselj(-1/3,ee) - besselj(1/3,ee))
                   where {ee => (2/3 * (z ^ (3/2))) , z => -minusz}>>
                   when numberp z and repart <=0,

airy_biprime(~z) => (z / sqrt(3)) * << (besseli(-2/3,ee)
                         + besseli(2/3,ee))
                   where ee => (2/3 * (z ^ (3/2))) >>
                   when numberp z and repart z >=0,

airy_biprime(~minusz) => <<(z/sqrt(3)) * (besselj(-2/3,ee)
                         + besselj(2/3,ee))
                   where {ee => (2/3 * (z ^ (3/2))) , z => -minusz} >>
                   when numberp z and repart z <=0
};

>>;

endmodule;


end;
