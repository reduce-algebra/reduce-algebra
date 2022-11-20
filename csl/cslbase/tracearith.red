% tracearith.red                               Arthur Norman, November 2022

% Not long enough to justify license pedantry: you may do whatever you
% want with this code!



% There are times when one needs to trace functions that are so deeply
% embedded in Lisp/Reduce that their use tends to end up compiled in-line.
% In such case the normal trace schemes do not work well. Also some
% functions are used by Reduce and Lisp infrastructure so global tracing
% of them can cause utter havoc.

% What I have here is a scheme where one goes:
%   lisp settrace();
%   in "some-module-to-test.red";
%   lisp cleartrace();
%   <some test code that exercises the module>

% settrace() in effect adjusts the Reduce parser so that use of functions
% it handles are expanded so that eg (plus A B C) maps to some code
% along the lines of
%    (lambda a,b,c; (lambda r; <print statements>; r) (plus a b c))(A,B,C)
% where the lambdas are there so that (unless there are rplaca/rplacd
% operations to corrupt them!) the arguments and result of the call to
% plus can be printed.
% This means that really low level functions can be traced.

% This is at present set up to arrange testing of a range of basic
% arithmetic functions like PLUS and TIMES since those are things I
% have been working on. The idea is that one can edit this file to
% adjust exactly what you want traced. Well next I will make it deal
% with modular arithmetic and read in the sources of the factorizer
% to see if I can debug some failures I currently see there...

symbolic procedure body_traced(fnn, av);
  begin
    scalar g := gensym(), i := 0;
    return list(list('lambda, list g, 'progn .
      list('princ, "calling ") .
      list('print, mkquote fnn) .
      append(for each v in av collect
         list('progn, list('prin2, "Arg"),
                      list('prin2, i := i+1),
                      list('prin2, ": "),
                      list('print, v)),
         list(list('princ, "=> "),
              list('print, g)))), fnn . av);
  end;

symbolic procedure form_traced(u,vars,mode);
  begin
    scalar fnn := car u, args := formlis(cdr u, vars, mode);
    scalar av := for each x in args collect gensym();
    if mode='symbolic then
       return ('lambda . av . list body_traced(fnn, av)) . args
    else return (fnn . args);
  end;

fluid '(traced_functions);

% Here I list all the functions defined specially in the --with-arithlib
% varient of CSL, since these are ones I especially want to check up
% on at present. Note that the scheme here ONLY traces direct calls tp
% them from the source code processed... indirect use is not looked at.

traced_functions := '(
  modf            plus            plus2           !+
  add1            !1!+            difference      xdifference
  !-              times           times2          !*
  quotient        !/!/            !/              remainder
  rem             mod             divide          gcd
  gcdn            lcmn            minus           minusp
  plusp           abs             reciprocal      square
  sqrt            isqrt           sub1            !1!-
  zerop           onep            oddp            evenp
  float           float128        fix             round
  fround          scale!-float    truncate        floor
  ceiling         ftruncate       ffloor          fceiling
  frexp           ldexp           expt            max
  max2            imax            min             min2
  imin            eqn             !=              neqn
  !/!=            greaterp        !>              geq
  !>!=            lessp           !<              leq
  !<!=            logand          logor           logior
  logxor          logeqv          land            lor
  lxor            leqv            lognot          lnot
  lsd             msd             integer!-length logcount
  lshift          ash             ashift          ash1
  rshift          modular!-plus   modular!-difference
  modular!-times  modular!-quotient               modular!-expt
  set!-small!-modulus             modular!-number modular!-minus
  modular!-reciprocal             safe!-modular!-reciprocal   iplus
  iplus2          iadd1           idifference     itimes
  itimes2         iquotient       iremainder      irem
  imod            idivide         igcdn           ilcmn
  iminus          iminusp         iabs            ireciprocal
  isquare         isub1           izerop          ionep
  ioddp           ievenp          iexpt           ieqn
  ineqn           igreaterp       igeq            ilessp
  ileq            ilogand         ilogor          ilogxor
  ilogeqv         iland           ilor            ilxor
  ileqv           ilognot         ilnot           ilogcount
  ilshift         irshift         ileftshift      irightshift
  abs             acos            acosd           acosh
  acot            acotd           acoth           acsc
  acscd           acsch           asec            asecd
  asech           asin            asind           asinh
  atand           atan2           atan2d          atanh
  cbrt            cos             cosd            cosh
  cot             cotd            coth            csc
  cscd            csch            exp             expt
  hypot           ln              log             log2
  log10           sec             secd            sech
  sin             sind            sinh            sqrt
  tan             tand            tanh            cis
  phase           signum          atan            logb
  native!-carg    native!-cabs    native!-cexp    native!-clog
  native!-csqrt   native!-csin    native!-ccos    native!-ctan
  native!-ccsc    native!-csec    native!-ccot    native!-casin
  native!-cacos   native!-catan   native!-cacsc   native!-casec
  native!-cacot   native!-csinh   native!-ccosh   native!-ctanh
  native!-ccsch   native!-csech   native!-ccoth   native!-casinh
  native!-cacosh  native!-catanh  native!-cacsch  native!-casech
  native!-cacoth  numerator       denominator     realpart
  imagpart        decode!-float   integer!-decode!-float
  fp!-infinite    float!-infinity!-p              fp!-nan
  fp!-finite      fp!-subnorm     fp!-denormalized!-p
  fp!-signbit     float!-sign     float!-digits   float!-precision
  float!-radix    float_sign      rational        manexp
  rationalize     random          random!-number  next!-random!-number
  random!-fixnum  make!-random!-state             md5
  md5string       md60            inorm           boole
  byte            byte!-position  byte!-size      ldb
  mask!-field     ldb!-test       dpb             deposit!-field
  logbitp         logtest         complex         conjugate
  fp!-evaluate    trap!-floating!-overflow        validate!-number

% Now some more that rely on some of the above
   timbf times!: plubf plus!: setprec infinityp gfplus gftimes 
);

symbolic procedure settrace();
 << for each x in oblist() do remprop(x, 'inline);
    for each x in traced_functions do
       put(x, 'formfn, 'form_traced) >>;

symbolic procedure cleartrace();
   for each x in traced_functions do
      remprop(x, 'formfn);

end;

