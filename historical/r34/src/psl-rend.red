module rend; % PSL REDUCE "back-end".

% Authors: Martin L. Griss and Anthony C. Hearn.

% Except where noted, this works with both PSL 3.2 and PSL 3.4.

create!-package('(rend),'(build));

fluid '(!*break
        !*echo
        !*eolinstringok
        !*fastcar
        !*fulltrace
        !*gc
        !*int
        !*mode
        !*pgwd
        !*plap
        !*pwrds
        !*usermode
        !*verboseload
        currentreadmacroindicator!*
        currentscantable!*
%       current!-modulus
        errout!*
        lispscantable!*
        promptstring!*
        rlispscantable!*);

global '(!$eol!$
         !*extraecho
         !*loadversion
         !*raise
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
         tab!*
         version!*);

switch break,gc,usermode,verboseload;

switch plap,pgwd,pwrds;

!*fastcar := t;   % Since REDUCE doesn't use car and cdr on atoms.


% Constants used in scanner.

flag('(define!-constant),'eval);

define!-constant(cr!*,intern int2id 13);   % carriage return (^M).

define!-constant(ff!*,intern int2id 12);   % form feed (^L).

define!-constant(tab!*,intern int2id 9);   % tab key (^I)

deflist('((!$eol!$ t) (!$eof!$ t)),'constant!?);


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
   <<close!-output!-files(); exitlisp()>>;

deflist('((bye endstat)),'stat);

symbolic procedure seprp u;
   % Returns true if U is a blank, end-of-line, tab, carriage return or
   % form feed.  This definition replaces the one in the BOOT file.
   u eq '!  or u eq tab!* or u eq !$eol!$ or u eq ff!* or u eq cr!*;

symbolic procedure error1;
   %This is the simplest error return, without a message printed. It can
   %be defined as ERROR(99,NIL) if necessary;
   throw('!$error!$,99);

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
      % The following allows for extensions like 1E that the PSL
      % token scanner does not like.
      v := nil;
      while w do <<v := '!! . car w . v; w := cdr w>>;
      return intern compress v
   end;

symbolic procedure mkfil u;
   % Converts file descriptor U into valid system filename.
   if stringp u then u
    else if not idp u then typerr(u,"file name")
    else string!-downcase u;

% The following three functions are only used as part of mkfil.

symbolic procedure string!-downcase u;
   begin scalar z;
      if not stringp u then u := '!" . append(explode2 u,'(!"))
       else u := explode u;
      for each x in u do
         if uppercasep x then z := red!-char!-downcase x . z
          else z := x . z;
      return compress reverse z
   end;

symbolic procedure red!-char!-downcase u;
   begin scalar x;
      if (x := atsoc(u,
         '((A . !a) (B . !b) (C . !c) (D . !d) (E . !e) (F . !f)
           (G . !g) (H . !h) (I . !i) (J . !j) (K . !k) (L . !l)
           (M . !m) (N . !n) (O . !o) (P . !p) (Q . !q) (R . !r)
           (S . !s) (T . !t) (U . !u) (V . !v) (W . !w) (X . !x)
           (Y . !y) (Z . !z))))
        then return cdr x
       else rederr list(u,"not upper case character")
   end;

symbolic procedure uppercasep u;
   u memq '(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z);

symbolic procedure orderp(u,v);
   % U, v are non-numeric atoms (but can be vectors).
   % Returns true if U has same or higher order than id V by some
   % consistent convention (eg unique position in memory).
   wleq(inf u,inf v);       % PSL 3.4 form.
%  id2int u <= id2int v;    % PSL 3.2 form.

procedure setpchar c;
   % Set prompt, return old one.
   begin scalar oldprompt;
    oldprompt := promptstring!*;
    promptstring!* := if stringp c then c
                      else if idp c then copystring id2string c
                      else bldmsg("%W", c);
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


Comment The FACTOR module also requires a definition for GCTIME. Since
this is currently undefined in PSL, we provide the following definition;

symbolic procedure gctime; gctime!*;


Comment The following operator is used to save a REDUCE session as a
file for later use;

symbolic procedure savesession u;
   savesystem("Saved session",u,nil);

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

remflag('(iplus itimes),'lose);

remprop('iplus,'infix);   % to allow for redefinition.

remprop('itimes,'infix);

symbolic macro procedure iplus u; expand(cdr u,'iplus2);

symbolic macro procedure itimes u; expand(cdr u,'itimes2);

flag('(iplus itimes iplus2 itimes2 iadd1 isub1 iminus iminusp
       idifference iquotient iremainder ilessp igreaterp), 'lose);

Comment There are also a number of system constants required for each
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

% remflag('(modular!-times),'lose);

% smacro procedure modular!-times(u,v);
%    iremainder(itimes2(u,v),current!-modulus);

% flag('(modular!-times),'lose);


% The following two definitions are commented out as they lead to
% unchecked vector ranges;

% symbolic smacro procedure getv(a,b); igetv(a,b);

% symbolic smacro procedure putv(a,b,c); iputv(a,b,c);

% flag('(intersection),'lose);


Comment PSL Specific patches;

Comment We need to define a function BEGIN, which acts as the top-level
call to REDUCE, and sets the appropriate variables;

% global '(startuproutine!* toploopread!* toploopeval!* toploopprint!*
%          toploopname!*);

remflag('(begin),'go);

symbolic procedure begin;
   begin
        !*echo := not !*int;
        !*extraecho := t;
        ifl!* := ipl!* := ofl!* := nil;
        if null date!* then go to a;
        if !*loadversion then errorset!*('(load entry),nil);
        !*gc := nil;
        !*usermode := nil;
        linelength 80;
        prin2 version!*;
        prin2 ", ";
        prin2 date!*;
        prin2t " ...";
        !*mode := if getd 'addsq then 'algebraic else 'symbolic;
        if !*mode eq 'algebraic then !*break := nil;
           %since most REDUCE users won't use LISP
        date!* := nil;
a:      % crchar!* := '! ;
        if errorp errorset!*('(begin1),nil) then go to a;
           %until PSL fixed
        prin2t "Entering LISP ... "
 end;

flag('(begin),'go);


Comment Initial setups for REDUCE;

spare!* := 11;   % We need this for bootstrapping.

version!* := "REDUCE 3.4";

symbolic procedure initreduce; initrlisp();   % For compatibility.

symbolic procedure initrlisp;
  % Initial declarations for REDUCE
  <<statcounter := 0;
    spare!* := 11;
    !*int := t;
    !*eolinstringok := t;  % we don't want the "string continued" msg.
    remd 'main;
    copyd('main,'rlispmain);
    date!* := date()>>;

symbolic procedure rlispmain;
  begin scalar l;
    rlispscantable!* := mkvect 128;
    l := '(17 11 11 11 11 11 11 11 11 17 17 11 17 17 11 11 11 11 11 11
           11 11 11 11 11 11 11 11 11 11 11 11 17 14 15 11 11 12 11 11
           11 11 13 11 11 11 20 11 00 01 02 03 04 05 06 07 08 09 13 11
           13 11 13 11 11 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
           10 10 10 10 10 10 10 10 10 10 10 11 16 11 11 10 11 10 10 10
           10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
           10 10 10 11 11 11 11 11 rlispdipthong);
    for i:=0:128 do <<putv(rlispscantable!*,i,car l); l := cdr l>>;
    currentreadmacroindicator!* := 'rlispreadmacro;
    currentscantable!* := rlispscantable!*;
    errout!* := 1;  % Errors to standard output, not special stream;
    lispeval '(begin);
    currentscantable!* := lispscantable!*; % But Slisp should use same
                                           % syntax as RLISP?
    standardlisp()
  end;

flag('(dskin savesystem reclaim),'opfn);

flag('(dskin savesystem),'noval);

flag('(load reload),'noform);

deflist('((load rlis) (reload rlis)),'stat);

flag('(tr trst untr untrst),'noform);

deflist('((tr rlis) (trst rlis) (untr rlis) (untrst rlis)),'stat);

% Allow for direct calls to some UNIX and PSL functions.

flag('(pwd cd setenv getenv set!-heap!-size set!-bndstk!-size
       set_heap_size set_bndstk_size),'opfn);

if getd 'set!-heap!-size then copyd('set_heap_size,'set!-heap!-size);
if getd 'set!-bndstk!-size
  then copyd('set_bndstk_size,'set!-bndstk!-size);


% The following is PSL 3.4 specific.

switch fulltrace;   % Prevents node renaming in trace output.

!*fulltrace := t;   % Since we usually want it this way.

Comment The global variable ESC* is used by the interactive string
editor (defined in CEDIT) as a terminator for input strings.  In PSL
we use the escape character;

esc!* := '!;


% The following are compiler switches.

fluid '(!*pgwd !*plap !*pwrds);

flag('(pgwd plap pwrds),'switch);


Comment The following declarations are needed to build various modules;

flag('(fl2int),'lose);                  % Used in MATH.

% flag('(nth pnth spaces subla),'lose); % Used in ALG1.

flag('(explode2 explode21),'lose);      % Used in RPRINT.

flag('(flag1 remflag1),'lose);          % Used in RCREF.

flag('(vector2list),'lose);             % Used in HILBERTS.

deflist('((imports rlis)),'stat);   % Needed for ~imports to work.

Comment The following are only needed for PSL 3.2;

% symbolic fexpr procedure definebop u; u;

% symbolic fexpr procedure definerop u; u;

endmodule;

end;

