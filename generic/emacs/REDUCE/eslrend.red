module eslrend; % ESL (Emacs Standard LISP) REDUCE "back-end".

% Authors: Martin L. Griss, Anthony C. Hearn and Arthur C. Norman.
% Revised for ESL REDUCE by Francis J. Wright.

create!-package('(eslrend),nil);

fluid '(lispsystem!*
   	    !*echo
        !*int
        !*mode
        promptstring!*);

global '(!*extraecho
         !*loadversion
         date!*
         esc!*
         ifl!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         spare!*
         statcounter
		 version!*
		 symchar!*
         !noninteractive);			% FJW: t if Emacs is in batch mode

lispsystem!* := '(esl);					% Not yet used

switch break, lower, redefmsg;

Comment The following functions, which are referenced in the basic
REDUCE source (RLISP, ALG1, ALG2, MATR and PHYS) should be defined to
complete the definition of REDUCE:

	BYE
	EVLOAD -- defined in "esl.el"
	ERROR1 -- defined in "esl.el"
	MKFIL
	ORDERP -- defined in "esl.el"
	QUIT
	SEPRP -- defined in "eslprolo.red"
	SETPCHAR.

Prototypical descriptions of these functions are as follows;

remprop('bye,'stat);

fluid '(bye!-actions!*);

% A package may put a call to some termination code on top of this list.

bye!-actions!* := '((close!-output!-files) (quit));

symbolic procedure bye;
   eval('progn . bye!-actions!*);

deflist('((bye endstat)),'stat);

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;

% FJW: I define string!-downcase in esl.el.

% FJW: I define orderp in esl.el.
% symbolic procedure orderp(u,v);
%    % U, V are non-numeric atoms (but can be vectors).
%    % Returns true if U has same or higher order than id V by some
%    % consistent convention (eg unique position in memory).
%    wleq(inf u,inf v);       % PSL 3.4 form.
% %  id2int u <= id2int v;    % PSL 3.2 form.

procedure setpchar c;
   % Set prompt, return old one.
   begin scalar oldprompt;
    oldprompt := promptstring!*;
    promptstring!* := if stringp c then c
                      else if idp c then id2string c
                      else format("%s", c);
    return oldprompt
   end;


Comment The following functions are only referenced if various flags are
set, or the functions are actually defined. They are defined in another
module, which is not needed to build the basic system. The name of the
flag follows the function name, enclosed in parentheses:

	CEDIT (?)
	COMPD (COMP)
	EDIT1   This function provides a link to an editor. However, a
		definition is not necessary, since REDUCE checks to see
		if it has a function value.
	EZGCDF (EZGCD)
	PRETTYPRINT (DEFN --- also called by DFPRINT)
		This function is used in particular for output of RLISP
		expressions in LISP syntax. If that feature is needed,
		and the prettyprint module is not available, then it
		should be defined as PRINT
	RPRINT (PRET)
	TIME (TIME) returns elapsed time from some arbitrary initial
		    point in milliseconds;


% FJW: I define gctime in esl.el.

Comment to make "bye" and "quit" equivalent, as stated by the REDUCE
manual;

put('quit,'newnam,'bye);


Comment There are a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% This is constant for the life of the system and could be
% compiled in-line if the compiler permits it.

largest!-small!-modulus := 2**23;

% If the (small) modular arithmetic is always limited to LARGEST-SMALL-
% MODULUS, it all fits in the inum range of the machine, with the
% exception of modular-times, that needs to use generic arithmetic for
% the multiplication.  However, on some machines (e.g., the VAX), it is
% possible to 'borrow' the extra precision needed, so that the following
% definition works.  This will not work of course for non-inums.


Comment We need to define a function BEGIN, which acts as the top-level
call to REDUCE, and sets the appropriate variables;

remflag('(begin),'go);

symbolic procedure begin;
   begin
        !*echo := not !*int;
        !*extraecho := t;
        ifl!* := ipl!* := ofl!* := nil;
        if null date!* then go to a;
        if !*loadversion then errorset('(load entry),nil,nil);
		linelength 80;
		prin2 version!*;
		prin2 ", ";
        prin2 date!*;
        prin2t " ...";
        !*mode := if getd 'addsq then 'algebraic else 'symbolic;
        if !*mode eq 'algebraic then !*break := nil;
           %since most REDUCE users won't use LISP
        date!* := nil;
a:      if errorp errorset('(begin1),nil,nil) then go to a;
        prin2t "Entering LISP ... "
 end;

flag('(begin),'go);


Comment Initial setups for REDUCE;

spare!* := 0;		   % We need this for bootstrapping. (FJW: Maybe!)

symchar!* := t;				   % Changed prompt when in symbolic mode.

symbolic procedure initreduce;
  % Initial declarations for REDUCE
  << close rds nil;		% FJW: close build file and read from terminal
	 statcounter := 0;
     spare!* := 0;
     !*int := not !noninteractive;		% FJW: nil in batch mode
     eval '(begin);
  >>;

flag('(load reload),'noform);

deflist('((load rlis) (reload rlis)),'stat);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Machine independent traceset code from REDUCE 3.8 "support/clrend.red".
% Copyright (c) 1993 RAND.  All Rights Reserved.
% Modified slightly by FJW for Emacs REDUCE.

% TR and UNTR are defined in "esl.el".

symbolic procedure traceset1 u;
   if atom u then u
    else if car u memq '(!s!e!t!q !S!E!T!Q)
     then list('progn,
               list('prin2,mkquote cadr u),
               '(prin2 " := "),
               u,
               list('prin2t,cadr u))
    else traceset1 car u . traceset1 cdr u;

symbolic procedure traceset u;
   if get(u,'original!-defn) then lprim list(u,"already traceset")
    else (if not x or not eqcar(cdr x,'lambda)
            then lprim list(u,"has wrong form for traceset")
           else <<put(u,'original!-defn,x);
                  remd u;   % To prevent spurious messages.
                  putd(u,car x,traceset1 cdr x)>>)
          where x=getd u;

symbolic procedure untraceset u;
   (if x
      then <<remprop(u,'original!-defn);
             remd u;   % To prevent spurious messages.
             putd(u,car x,cdr x)>>
     else lprim list(u,"not traceset"))
    where x=get(u,'original!-defn);

symbolic macro procedure trst u;
   mkquote for each x in cdr u do traceset x;

symbolic macro procedure untrst u;
   mkquote for each x in cdr u do untraceset x;

flag('(tr trst untr untrst),'noform);

deflist('((tr rlis) (trst rlis) (untr rlis) (untrst rlis)),'stat);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Comment The global variable ESC* is used by the interactive string
editor (defined in CEDIT) as a terminator for input strings.  The
convention is to use the escape character;

esc!* := '!;


% Make ON DEFN load the prettyprinter if necessary and
% OFF DEFN reinstate property lists saved during ON DEFN:
put('defn, 'simpfg, '((t (!require '!eslpretty))
                      (nil (!esl!-reinstate!-plists))));


% Replace the REDUCE versions of some key functions with better
% ESL-specific versions.

remflag('(boundp gcdn smallcompress), 'lose);
% because the build process currently runs eslrend twice!

% Avoid the definition of BOUNDP in "alg/simp.red".  It detects an
% unbound variable by intentionally throwing an error, which makes
% debugging awkward.  Use the Elisp built-in function instead:
symbolic procedure boundp u; !boundp u;

% Provide a numerical greatest common divisor that should work better
% with ESL big integers than the version in "alg/numsup.red" by using
% the Calc package:
symbolic procedure gcdn(u,v); !c!a!l!c!F!u!n!c!-!g!c!d(u,v);
%  U and v are integers. Value is absolute value of gcd of u and v.

% Down-case the E in floats if appropriate:
symbolic procedure smallcompress (li);
   % Compress list li to a string.  Used in arith/smlbflot.red only.
   begin scalar s;
	  s := !mapconcat((lambda x; !prin1!-to!-string(x,t)), li, "");
	  return if !*lower then !downcase s else s
   end;

flag('(boundp gcdn smallcompress), 'lose);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Fast arithmetic support.
% From REDUCE 3.8 "support/cslrend.red".

Comment The current REDUCE model allows for the availability of fast
arithmetical operations on small integers (called "inums").  All modern
LISPs provide such support.  However, the program will still run without
these constructs.  The relevant functions that should be defined for
this purpose are as follows;

% The following small-integer functions are defined in "esl.el":

flag('(iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp ileq igeq
       izerop ionep), 'lose);

% The following floating-point functions are defined in "esl.el":

% flag('(acos asin atan atan2 cos exp ln log logb log10 sin sqrt tan
%        ceiling floor round), 'lose);

% The above causes errors in the arith test file when trig results or
% arguments are complex so all commented out for now.

% Other REDUCE functions already provided by Emacs Lisp and defined in
% "esl.el":

flag('(reversip lastpair nth pnth), 'lose);

endmodule;

end;
