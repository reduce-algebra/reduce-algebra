module rend; % ESL (Emacs Standard LISP) REDUCE "back-end".

% Based on code by Martin L. Griss, Anthony C. Hearn and Winfried Neun.

fluid '(!*break
        !*int
        !*mode
        promptstring!*);

global '(!$eol!$
         !*echo
         !*extraecho
         !*loadversion
         !*raise
         !*rlisp2
         crchar!*
         date!*
         esc!*
         e!-value!*
         ft!-tolerance!*
         ifl!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         pi!-value!*
         spare!*
         statcounter
         systemname!*);

switch break,gc;

% One inessential reference to REVERSIP in this module (left unchanged).

Comment The following functions, which are referenced in the basic
REDUCE source (RLISP, ALG1, ALG2, MATR and PHYS) should be defined to
complete the definition of REDUCE:

        BYE
        DELCP
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
   << close!-output!-files(); eval '(quit) >>;

deflist('((bye endstat)),'stat);

symbolic procedure delcp u;
   %Returns true if U is a semicolon, dollar sign, or other delimiter.
   %This definition replaces one in the BOOT file;
   u eq '!; or u eq '!$;

symbolic procedure seprp u;
   %returns true if U is a blank or other separator (eg, tab or ff).
   %This definition replaces one in the BOOT file.
   u eq '!  or u eq '!	 or u eq '! or u eq !$eol!$;

symbolic procedure error1;
   %This is the simplest error return, without a message printed. It can
   %be defined as ERROR(99,NIL) if necessary;
   %FJW throw('!$error!$,99);
   ERROR(99, nil);

symbolic procedure filetype u;
   %determines if string U has a specific file type.
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
   %converts file descriptor U into valid system filename;
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase id2string u;

% The following is a pretty crude definition, but since it isn't used
% very much, its performance doesn't really matter.

% FJW: I have defined this function in sl.el.
% symbolic procedure string!-downcase u;
%    begin scalar z;
%       if not stringp u then u := id2string u;
%       for each x in explode u do
%      if x memq
%           '(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
%           then z := cdr atsoc(x,
%               '((A . !a) (B . !b) (C . !c) (D . !d) (E . !e)
%                (F . !f) (G . !g) (H . !h) (I . !i) (J . !j)
%                (K . !k) (L . !l) (M . !m) (N . !n) (O . !o)
%                (P . !p) (Q . !q) (R . !r) (S . !s) (T . !t)
%                (U . !u) (V . !v) (W . !w) (X . !x) (Y . !y)
%                (Z . !z))) . z
%       else z := x . z;
%       return compress reverse z
%    end;
 
% FJW: I have defined a version of this function in sl.el.
% symbolic procedure orderp(u,v);
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

        BFQUOTIENT!: (BIGFLOAT)
        CEDIT (?)
        COMPD (COMP)
        EDIT1   This function provides a link to an editor. However, a
                definition is not necessary, since REDUCE checks to see
                if it has a function value.
        EMBFN (?)
        EZGCDF (EZGCD)
        FACTORF (FACTOR)
        LOAD!-MODULE (defined in prolog)
        PRETTYPRINT (DEFN --- also called by DFPRINT)
                This function is used in particular for output of RLISP
                expressions in LISP syntax. If that feature is needed,
                and the prettyprint module is not available, then it
                should be defined as PRINT
        RPRINT (PRET)
        TEXPT!: (BIGFLOAT)
        TEXPT!:ANY (BIGFLOAT)
        TIME (TIME) returns elapsed time from some arbitrary initial
                    point in milliseconds;


Comment There are also a number of system constants required for each
implementation. In systems that don't support inums, the equivalent
single precision integers should be used;

% E!-VALUE and PI!-VALUE are values for these constants that fit in
% the single precision floating point range of the machine.
% FT!-TOLERANCE is the tolerance of floating point calculations.
% LARGEST!-SMALL!-MODULUS is the largest power of two that can
% fit in the fast arithmetic (inum) range of the implementation.
% These four are constant for the life of the system and could be
% compiled in-line if the compiler permits it.

e!-value!* := 2.718282;

pi!-value!* := 3.141593;

ft!-tolerance!* := 0.000001;

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
        !*gc := nil;
        linelength if !*int then 80 else 115;
        prin2 "REDUCE 3.3, ";
        prin2 date!*;
        prin2t " ...";
        !*mode := if getd 'addsq then 'algebraic else 'symbolic;
        if !*mode eq 'algebraic then !*break := nil;
           %since most REDUCE users won't use LISP
        date!* := nil;
a:      crchar!* := '! ;
        if errorp errorset('(begin1),nil,nil) then go to a;
           %until PSL fixed
        prin2t "Entering LISP ... "
 end;

flag('(begin),'go);


Comment Initial setups for REDUCE;

spare!* := 11;   % We need this for bootstrapping. (FJW: Maybe!)

symbolic procedure initreduce;
  % Initial declarations for REDUCE
  << close rds nil;		% FJW: close build file and read from terminal
	 statcounter := 0;
     spare!* := 11;
     !*int := t;
     date!* := date();
     eval '(begin);
  >>;

flag('(load),'noform);

deflist('((load rlis)),'stat);

flag('(tr trst untr untrst),'noform);

deflist('((tr rlis) (trst rlis) (untr rlis) (untrst rlis)),'stat);

Comment The global variable ESC* is used by the interactive string
editor (defined in CEDIT) as a terminator for input strings.  In PSL
we use the escape character;

esc!* := '!;


Comment Now set the system name;

systemname!* := 'emacs;

endmodule;

end;
