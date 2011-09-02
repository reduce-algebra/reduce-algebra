module cslrend; % CSL REDUCE "back-end".

% Authors: Martin L. Griss and Anthony C. Hearn.
% Modified by Arthur Norman for use with CSL.

create!-package('(cslrend csl),nil);

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
	 lispsystem!*
	 ofl!*
	 spare!*
	 statcounter
	 crbuflis!*
	 tab!*
	 version!*
         copyright1!*
         copyright2!*
         loadable!-packages!*
         switches!*
	 symchar!*);

copyright1!* := "Copyright A C Hearn, 1999";
copyright2!* := "Copyright Codemist Ltd, 1999";


loadable!-packages!* := '(
    algint      applysym    arnum       assist      atensor
    avector     boolean     cali        camal       cantens
    cedit       changevr    cl          compact     conlaw
    crack       cvit        defint      desir       dfpart
    dipoly      dummy       dvfsf       eds         excalc
    ezgcd       factor      fide        fmprint     fps
    ftr         gentran     geometry    gnuplot     groebner
    hephys      ideals      ineq        int         invbase
    laplace     lie         liepde      limits      linalg
    mathml      matrix      misc        modsr       mrvlimit
    ncpoly      normform    numeric     odesolve    ofsf
    orthovec    pf          physop      plot        pm
    polydiv     pretty      qsum        randpoly    rataprx
    ratint      rcref       reacteqn    redlog      residue
    rlfi        rlisp88     rltools     roots       rprint
    rsolve      rtrace      scope       sets        sfgamma
    solve       sparse      spde        specfn      sum
    support     susy2       symmetry    taylor      tps
    tri         trigint     trigsimp    wu          xcolor
    xideal      ztrans);


switches!* := '(
    algint            adjprec           allbranch         allfac
    arbvars           asterisk          backtrace         balanced_mod
    bfspace           combineexpt       combinelogs       comp
    complex           compxroots        cramer            cref
    defn              demo              dfprint           div
    echo              errcont           evallhseqp        exp
    expandexpt        expandlogs        ezgcd             factor
    fastfor           force             fort              fortupper
    fullprec          fullprecision     fullroots         gc
    gcd               heugcd            horner            ifactor
    int               intstr            lcm               lessspace
    limitedfactors    list              listargs          lower
    mcd               modular           msg               multiplicities
    nat               nero              noarg             noconvert
    nonlnr            nosplit           numval            output
    period            pgwd              plap              precise
    pret              pri               pwrds             quotenewnam
    raise             rat               ratarg            rational
    rationalize       ratpri            reduced           revpri
    rlisp88           rootmsg           roundall          roundbf
    rounded           savestructr       solvesingular     time
    trallfac          trfac             trint             trroot);


% Constants used in scanner.

flag('(define!-constant),'eval);

cr!* := compress(list('!!, special!-char 6));   % carriage return
ff!* := compress(list('!!, special!-char 5));   % form feed
tab!*:= compress(list('!!, special!-char 3));   % tab key


% One inessential reference to REVERSIP in this module (left unchanged).

% This file defines the system dependent code necessary to run REDUCE
% under CSL.

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

% evload is now defined in cslprolo.red - this has to be the case
% so it can be used (via load_package) to load rlisp and cslrend.
% symbolic procedure evload l;
%   for each m in l do load!-module m;

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
       idifference iquotient iremainder ilessp igreaterp ileq igeq
       izerop ionep), 'lose);

Comment There are also a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% This is constant for the life of the system and could be
% compiled in-line if the compiler permits it.

largest!-small!-modulus := 2**24 - 1; % I could use up to 2^27-1, but
	 % stick to 2^24-1 since that's what Cambridge Lisp used to use.

flag('(modular!-difference modular!-minus modular!-number
       modular!-plus modular!-quotient modular!-reciprocal
       modular!-times modular!-expt set!-small!-modulus), 'lose);

% See comments about gensym() below - which apply also to the
% effects of having different random number generators in different
% host Lisp systems.
% From 3.5 onwards (with a new random generator built into the
% REDUCE sources) I am happy to use the portable version.

% flag('(random next!-random!-number), 'lose);

set!-small!-modulus 3;

% The following are now built into CSL, where by using the C library
% and (hence?) maybe low level tricks or special floating point
% microcode things can go fast.

flag('(acos acosd acosh acot acotd acoth acsc acscd acsch asec asecd
       asech asin asind asinh atan atand atan2 atan2d atanh cbrt cos
       cosd cosh cot cotd coth csc cscd csch exp expt hypot ln log
       logb log10 sec secd sech sin sind sinh sqrt tan tand tanh fix
       ceiling floor round clrhash puthash gethash remhash), 'lose);

% remflag('(int!-gensym1),'lose);

% symbolic procedure int!-gensym1 u;
% In Codemist Lisp compress interns - hence version in int.red may
% not work.  However, it seems to be ok for now.
%   gensym1 u;

% flag('(int!-gensym1),'lose);


Comment We need to define a function BEGIN, which acts as the top-level
call to REDUCE, and sets the appropriate variables;

remflag('(begin),'go);

global '(patchdate!* no_init_file);

symbolic procedure load!-latest!-patches();
  begin
     scalar w;
     w := modulep 'patches;
     if w and (null patchdate!* or datelessp(patchdate!*, w)) then
        begin scalar !*usermode, !*redefmsg;   % Avoid silly messages
           load!-module 'patches;
           patchdate!* := w;
           for each m in loaded!-packages!* do
               if (w := get(m, 'patchfn)) then apply(w, nil)
        end
  end;

symbolic procedure begin;
  begin
     scalar w;
     !*echo := not !*int;
     !*extraecho := t;
     ifl!* := ipl!* := ofl!* := nil;
     if date!* then <<
        verbos nil;
% The linelength may need to be adjusted if we are running in a window.
% To cope with this, CSL allows (linelength t) to set a "default" line
% length that can even vary as window sizes are changed. An attempt
% will be made to ensure that it is 80 at the start of a run, but
% (linelength nil) can return varying values as the user re-sizes the
% main window (in some versions of CSL). However this is still not
% perfect! The protocol
%   old := linelength nil;
%   <do something, possibly changing linelength as you go>
%   linelength old;
% can not restore the variability characteristic. However I make
%   old := linelength n; % n numeric or T
%   ...
%   linelength old;
% preserve things by returning T from (linelength n) in relevant cases.
        linelength t;
% The next four lines have been migrated into the C code in "restart.c"
% so that some sort of information gets back to the user nice and early.
%       prin2 version!*;
%       prin2 ", ";
%       prin2 date!*;
%       prin2t " ...";
        if getd 'addsq then <<
% I assume here that this is an algebra system if ADDSQ is defined, and
% in that case process an initialisation file. Starting up without ADDSQ
% defined means I either have just RLISP built or I am in the middle of
% some bootstrap process. Also if a variable no_init_file is set to TRUE
% then I avoid init file processing.
           !*mode := 'algebraic;
           if null no_init_file then begin
              scalar name;
              name := assoc('executable, lispsystem!*);
              if atom name then name := "reduce"
              else name := list!-to!-string explode2lc cdr name;
              read!-init!-file name end >>
        else !*mode := 'symbolic;
        date!* := nil >>;
% If there is a patches module that is later than one that I currently
% have installed then load it up now.
     load!-latest!-patches();
     w := assoc('opsys, lispsystem!*);
     if not atom w then w := cdr w;
% For MOST systems I will let ^G (bell) be the escape character, but
% under win32 I use that as an interrupt character, and so there I go
% back and use ESC instead.  I do the check at BEGIN time rather than
% further out so that common checkpoint images can be used across
% systems.
     esc!*:= compress list('!!,
		special!-char (if w = 'win32 then 10 else 9));
     while errorp errorset('(begin1), !*backtrace, !*backtrace) do nil;
     prin2t "Leaving REDUCE ... "
  end;

flag('(begin),'go);

% The following function is used in some CSL-specific operations. It is
% also defined in util/rprint, but is repeated here to avoid loading
% that module unnecessarily, and because the definition given there is
% rather PSL specific.

remflag('(string!-downcase),'lose);

symbolic procedure string!-downcase u;
   compress('!" . append(explode2lc u,'(!")));

% princ!-upcase and princ!-downcase are used for fortran output

flag('(string!-downcase princ!-upcase princ!-downcase),'lose);

% This function is used in Rlisp '88.

symbolic procedure igetv(u,v); getv(u,v);

symbolic procedure iputv(u,v,w); putv(u,v,w);

% The following functions are NOT in Standard Lisp and should NOT be
% used anywhere in the REDUCE sources, but the amount of trouble I have
% had with places where they do creep in has encouraged me to define
% them here anyway and put up with the (small) waste of space.

symbolic procedure first x; car x;

symbolic procedure second x; cadr x;

symbolic procedure third x; caddr x;

symbolic procedure fourth x; cadddr x;

symbolic procedure rest x; cdr x;

flag('(iequal),'lose);


Comment Initial setups for REDUCE;

spare!* := 0;    % We need this for bootstrapping.

symchar!* := t;  % Changed prompt when in symbolic mode.


% PSL has gensyms with names g0001, g0002 etc., and in a few places
% REDUCE will insert gensyms into formulae in such a way that their
% names can influence the ordering of terms.  The next fragment of
% commented out code make CSL use similar names (but interned).  This
% is not sufficient to guarantee a match with PSL though, since in (for
% instance) the code
%      list(gensym(), gensym(), gensym())
% there is no guarantee which gensym will have the smallest serial
% number.  Also if !*comp is true and the user defines a procedure it is
% probable that the compiler does a number (just how many we do not
% wish to say) of calls to gensym, upsetting the serial number
% sequence.  Thus other ways of ensuring consistent output from REDUCE
% are needed.

%- global '(gensym!-counter);

%- gensym!-counter := 1;

%- symbolic procedure reduce!-gensym();
%-   begin
%-     scalar w;
%-     w := explode gensym!-counter;
%-     gensym!-counter := gensym!-counter+1;
%-     while length w < 4 do w := '!0 . w;
%-     return compress ('g . w)
%-   end;

%- remflag('(gensym), 'lose);
%- remprop('gensym, 's!:builtin0);

%- smacro procedure gensym();
%-    reduce!-gensym();

% However, the current CSL gensym uses an upper case G as the root,
% which causes inconsistencies in some tests (e.g., int and qsum).
% This definition cures that.

symbolic smacro procedure gensym; gensym1 'g;


symbolic procedure initreduce;
   initrlisp();   % For compatibility.

symbolic procedure initrlisp;
  % Initial declarations for REDUCE
  <<statcounter := 0;
%-  gensym!-counter := 1;
    crbuflis!* := nil;
    spare!* := 0;
%   !*int := not batchp();
    !*int := t;
  >>;

symbolic procedure rlispmain;
    lispeval '(begin);

flag('(rdf preserve reclaim),'opfn);

flag('(rdf preserve),'noval);

flag('(load reload),'noform);

deflist('((load rlis) (reload rlis)),'stat);

symbolic macro procedure load x; PSL!-load(cdr x, nil);
symbolic macro procedure reload x; PSL!-load(cdr x, t);

global '(PSL!-loaded!*);
PSL!-loaded!* := nil;

symbolic procedure PSL!-load(mods, reloadp);
  for each x in mods do <<
    if reloadp or not member(x, PSL!-loaded!*) then <<
%      load!-module x;
       load!-package x;
       PSL!-loaded!* := union(list x, PSL!-loaded!*) >> >>;

symbolic macro procedure tr x;
   list('trace, list('quote, cdr x));

symbolic macro procedure untr x;
   list('untrace, list('quote, cdr x));

symbolic macro procedure trst x;
   list('traceset, list('quote, cdr x));

symbolic macro procedure untrst x;
   list('untraceset, list('quote, cdr x));

flag('(tr untr
      trst untrst
      ),'noform);

deflist('((tr rlis)     (trst rlis)
	  (untr rlis)   (untrst rlis)
	 ),'stat);

symbolic procedure prop x; plist x;  % Yukky PSL compatibility.

Comment The following declarations are needed to build various modules;

flag('(mkquote spaces subla boundp error1),'lose);

% The exact order of items in the lists produced by these is important
% to REDUCE.
flag('(union intersection), 'lose);

flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot), 'lose);

flag('(threevectorp ordp), 'lose);

deflist('((imports rlis)),'stat);

flag('(sort stable!-sort stable!-sortip),'lose);

% We also need this.

flag('(lengthc),'lose);

symbolic procedure concat2(u,v); concat(u,v);

symbolic procedure concat(u,v);
   % This would be better supported at a lower level.
   compress('!" . append(explode2 u,nconc(explode2 v,list '!")));

% Used by patching mechanism.
%
% Note that DESPITE the name this MUST be an interned symbol not a
% gensym since it will be used as the name of a function written out
% using FASLOUT and later re-loaded: gensym identities can not survive
% this transition.  The symbols created by dated!-name are almost
% always going to avoid clashes - see commentary in the CSL source file
% "extras.red" for an explanation.

symbolic procedure dated!-gensym u; dated!-name u;

endmodule;

end;
