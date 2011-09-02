module cslrend; % CSL REDUCE "back-end".

% Authors: Martin L. Griss and Anthony C. Hearn.
% Modified by Arthur Norman for use with CSL.

create!-package('(cslrend csl),'(build));

fluid '(!*break
        !*echo
        !*eolinstringok
        !*int
        !*mode
        !*raise
        !*lower
        !*keepsqrts);

global '(!$eol!$
         !*extraecho
         cr!*
         crchar!*
         date!*
         esc!*
         ff!*
         ifl!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         spare!*
         statcounter
         crbuflis!*
         tab!*
         version!*
         symchar!*
         avector!-loaded!*);

% Constants used in scanner.

flag('(define!-constant),'eval);

cr!* := compress(list('!!, special!-char 6));   % carriage return
ff!* := compress(list('!!, special!-char 5));   % form feed
tab!*:= compress(list('!!, special!-char 3));   % tab key


% One inessential reference to REVERSIP in this module (left unchanged).

% This file defines the system dependent code necessary to run REDUCE
% under PSL.

Comment The following functions, which are referenced in the basic
REDUCE source (RLISP, ALG1, ALG2, MATR and PHYS) should be defined to
complete the definition of REDUCE:

        BYE
        EVLOAD
        ERROR1
        FILETYPE
        MKFIL
        ORDERP
        QUIT
        SEPRP
        SETPCHAR.

Prototypical descriptions of these functions are as follows;

remprop('bye,'stat);

symbolic procedure bye;
   %Returns control to the computer's operating system command level.
   %The current REDUCE job cannot be restarted;
   <<close!-output!-files(); stop 0>>;

deflist('((bye endstat)),'stat);

remprop('quit,'stat);

symbolic procedure quit;
   %Returns control to the computer's operating system command level.
   %The current REDUCE job cannot be restarted;
   <<close!-output!-files(); stop 0>>;

deflist('((quit endstat)),'stat);

symbolic procedure evload l;
  for each m in l do load!-module m;

symbolic procedure seprp u;
   % Returns true if U is a blank, end-of-line, tab, carriage return or
   % form feed.  This definition replaces the one in the BOOT file.
   u eq '!  or u eq tab!* or u eq !$eol!$ or u eq ff!* or u eq cr!*;

symbolic procedure filetype u;
   % Determines if string U has a specific file type.
   begin scalar v,w;
      v := cdr explode u;
      while v and not(car v eq '!.) do
        <<if car v eq '!< then while not(car v eq '!>) do v := cdr v;
          v := cdr v>>;
      if null v then return nil;
      v := cdr v;
      while v and not(car v eq '!") do <<w := car v . w; v := cdr v>>;
      return intern compress reversip w
   end;

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;


Comment The following functions are only referenced if various flags are
set, or the functions are actually defined. They are defined in another
module, which is not needed to build the basic system. The name of the
flag follows the function name, enclosed in parentheses:

        CEDIT (?)
        COMPD (COMP)
        EDIT1   This function provides a link to an editor. However, a
                definition is not necessary, since REDUCE checks to see
                if it has a function value.
        EMBFN (?)
        EZGCDF (EZGCD)
        PRETTYPRINT (DEFN --- also called by DFPRINT)
                This function is used in particular for output of RLISP
                expressions in LISP syntax. If that feature is needed,
                and the prettyprint module is not available, then it
                should be defined as PRINT
        RPRINT (PRET)
        TIME (TIME) returns elapsed time from some arbitrary initial
                    point in milliseconds;



Comment The following operator is used to save a REDUCE session as a
file for later use;

symbolic procedure savesession u;
   preserve('begin);

flag('(savesession),'opfn);

flag('(savesession),'noval);


Comment make "system" available as an operator;

flag('(system),'opfn);

flag('(system),'noval);


Comment to make "faslend" an endstat;

put('faslend,'stat,'endstat);


Comment The current REDUCE model allows for the availability of fast
arithmetical operations on small integers (called "inums").  All modern
LISPs provide such support.  However, the program will still run without
these constructs.  The relevant functions that should be defined for
this purpose are as follows;

flag('(iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp), 'lose);

Comment There are also a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% This is constant for the life of the system and could be
% compiled in-line if the compiler permits it.

largest!-small!-modulus := 2**24-1; % I could use up to 2^27-1, but
         % stick to 2^24-1 since that's what Cambridge Lisp used to use.

flag('(modular!-difference modular!-minus modular!-number
       modular!-plus modular!-quotient modular!-reciprocal
       modular!-times modular!-expt set!-small!-modulus
       random next!-random!-number), 'lose);

set!-small!-modulus 3;

% The following are now built into CSL, where by using the C library
% and (hence?) maybe low level tricks or special floating point
% microcode things can go fast.

flag('(acos acosd acosh acot acotd acoth acsc acscd acsch asec asecd
       asech asin asind asinh atan atand atan2 atan2d atanh cbrt cos
       cosd cosh cot cotd coth csc cscd csch exp expt hypot ln log
       logb log10 sec secd sech sin sind sinh sqrt tan tand tanh fix
       ceiling floor round), 'lose);

symbolic procedure int!-gensym1 u;
% in Codemist Lisp compress interns - hence version in int.red is bad;
   gensym1 u;


Comment CSL Specific patches;

Comment We need to define a function BEGIN, which acts as the top-level
call to REDUCE, and sets the appropriate variables;

remflag('(begin),'go);

symbolic procedure begin;
   begin
        scalar w;
        !*int := not batchp();
        !*echo := not !*int;
        !*extraecho := t;
        ifl!* := ipl!* := ofl!* := nil;
        if null date!* then go to a;
        verbos nil;
% The linelength may need to be adjusted if we are running in a window.
        linelength 80;
        prin2 version!*;
        prin2 ", ";
        prin2 date!*;
        prin2t " ...";
        !*mode := if getd 'addsq then 'algebraic else 'symbolic;
        %since most REDUCE users won't use LISP
        date!* := nil;
a:      % crchar!* := '! ;
        if errorp errorset('(begin1), !*backtrace, !*backtrace)
          then go to a;
        prin2t "Leaving REDUCE ... "
 end;

flag('(begin),'go);

% The following function is used in some CSL-specific operations. It is
% also defined in util/rprint, but is repeated here to avoid loading
% that module unnecessarily, and because the definition given there is
% rather PSL specific.

remflag('(string!-downcase),'lose);

symbolic procedure string!-downcase u;
   compress('!" . append(explode2 u,'(!")));

flag('(string!-downcase),'lose);

Comment Initial setups for REDUCE;

spare!* := 11;   % We need this for bootstrapping.

symchar!* := t;  % Changed prompt when in symbolic mode.

symbolic procedure initreduce; initrlisp();   % For compatibility.

symbolic procedure initrlisp;
  % Initial declarations for REDUCE
  <<statcounter := 0;
    crbuflis!* := nil;
    spare!* := 11;
    !*int := not batchp()>>;

symbolic procedure rlispmain;
    lispeval '(begin);

flag('(rdf preserve reclaim),'opfn);

flag('(rdf preserve),'noval);

remflag('(showtime), 'lose);

symbolic procedure showtime;
   begin scalar x,y;
      x := otime!*;
      otime!* := time();
      x := otime!* - x;
      y := ogctime!*;
      ogctime!* := gctime();
      y := ogctime!* - y;
%     x := x - y;
      terpri();
      prin2 "Time: "; prin2 x; prin2 " ms";
      if y = 0 then return terpri();
      prin2 "  plus GC time: "; prin2 y; prin2 " ms"
   end;

flag('(showtime), 'lose);

% flag('(load reload),'noform);
%
% deflist('((load rlis) (reload rlis)),'stat);
%
% flag('(tr trst untr untrst),'noform);
%
% deflist('((tr rlis) (trst rlis) (untr rlis) (untrst rlis)),'stat);


Comment The following declarations are needed to build various modules;

flag('(spaces subla boundp error1 union intersection),'lose);

flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot
       safe!-fp!-pl safe!-fp!-pl0), 'lose);

flag('(threevectorp ordp), 'lose);

deflist('((imports rlis)),'stat);

endmodule;

end;
module csl;  % Support for fast floating point arithmetic in CSL.

imports ash, logand, msd;

exports ashift, msd!:;

fluid '(!!nbfpd);

remflag ('(ashift fl2bf msd!: normbf integerp!:),'lose);

symbolic smacro procedure ashift (m,d); ash(m,d);

symbolic smacro procedure lshift (m,d); ash(m,d);

symbolic smacro procedure msd!: u; msd u;

symbolic smacro procedure make!:ibf (mt, ep);
  '!:rd!: . (mt . ep);

symbolic procedure fl2bf x;
  begin scalar u;
    u := frexp x;
    x := cdr u; % mantissa between 0.5 and 1
    u := car u; % exponent
    x := fix(x*2**!!nbfpd);
    return normbf make!:ibf(x,u-!!nbfpd)
  end;

symbolic procedure normbf x;
   begin scalar mt,s;integer ep,ep1;
      if (mt := mt!: x)=0 then go to ret;
      if mt<0 then <<mt := -mt; s := t>>;
      ep := ep!: x;
      while logand(mt,2147483647)=0 do << % 2**31 - 1
        mt := ash(mt,-31);
        ep := ep+31 >>;
      while logand(mt,255)=0 do <<
        mt := ash(mt,-8);
        ep := ep+8 >>;
      while evenp mt do <<
        mt := ash(mt,-1);
        ep := ep+1>>;
      if s then mt := -mt;
ret:    return make!:ibf(mt,ep) end;


symbolic procedure integerp!: x;
% This function returns T if X is a BINARY BIG-FLOAT
%      representing an integer, else it returns NIL.
% X is any LISP entity.
bfp!: x and
  (ep!: x >= 0 or
    preci!: x > - ep!: x and
      logand(abs mt!: x,lshift(2,-ep!: x) - 1) = 0);

flag ('(ashift fl2bf msd!: normbf integerp!:),'lose);

endmodule;

end;
