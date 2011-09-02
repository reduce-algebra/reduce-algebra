module rend; % 386 MS-DOS PSL REDUCE "back-end".

% Authors: Martin L. Griss, Anthony C. Hearn and Winfried Neun.

% Except where noted, this works with both PSL 3.2 and PSL 3.4.

fluid '(!*break
        !*eolinstringok
        !*gc
        !*int
        !*mode
        !*usermode
        currentreadmacroindicator!*
        currentscantable!*
%       current!-modulus
        errout!*
        lispscantable!*
        promptstring!*
        rlispscantable!*);

global '(!$eol!$
         !$cr!$
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

setq(!$cr!$,int2id 13);

switch break,gc,usermode,verboseload;

!*fastcar := t;   % Since REDUCE doesn't use car and cdr on atoms.

% One inessential reference to REVERSIP in this module (left unchanged).

% This file defines the system dependent code necessary to run REDUCE
% under PSL.

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
   <<close!-output!-files(); exitlisp()>>;

deflist('((bye endstat)),'stat);

symbolic procedure delcp u;
   %Returns true if U is a semicolon, dollar sign, or other delimiter.
   %This definition replaces one in the BOOT file;
   u eq '!; or u eq '!$;

symbolic procedure seprp u;
   %returns true if U is a blank or other separator (eg, tab or ff).
   %This definition replaces one in the BOOT file;
   u eq '!  or u eq '!	 or u eq !$eol!$  or u eq !$cr!$;

symbolic procedure error1;
   %This is the simplest error return, without a message printed. It can
   %be defined as ERROR(99,NIL) if necessary;
   throw('!$error!$,99);

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

symbolic procedure string!-downcase u;
   begin scalar z;
      if not stringp u then u := id2string u;
      for each x in explode u do
	 if x memq
	      '(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
		  then z := cdr atsoc(x,
		      '((A . !a) (B . !b) (C . !c) (D . !d) (E . !e)
		       (F . !f) (G . !g) (H . !h) (I . !i) (J . !j)
		       (K . !k) (L . !l) (M . !m) (N . !n) (O . !o)
		       (P . !p) (Q . !q) (R . !r) (S . !s) (T . !t)
		       (U . !u) (V . !v) (W . !w) (X . !x) (Y . !y)
		       (Z . !z))) . z
	  else z := x . z;
      return compress reverse z
   end;


symbolic procedure orderp8(u,v);
   % Returns true if U has same or higher order than id V by some
   % consistent convention (eg unique position in memory).
   wleq(inf u,inf v);       % PSL 3.4 form.
%  id2int u <= id2int v;    % PSL 3.2 form.

loadtime copyd('orderp,'orderp8);

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


Comment The FACTOR module also requires a definition for GCTIME. Since
this is currently undefined in PSL, we provide the following definition;

symbolic procedure gctime; gctime!*;


Comment The following operator is used to save a REDUCE session as a
file for later use;

symbolic procedure savesession u;
   savesystem("Saved session",u,nil);

flag('(savesession),'opfn);

flag('(savesession),'noval);


Comment make "cd" and "system" available as operators;

flag('(cd system),'opfn);

flag('(cd system),'noval);


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

% remflag('(modular!-times),'lose);

% smacro procedure modular!-times(u,v);
%    iremainder(itimes2(u,v),current!-modulus);

% flag('(modular!-times),'lose);


% The following two definitions are commented out as they lead to
% unchecked vector ranges;

% symbolic smacro procedure getv(a,b); igetv(a,b);

% symbolic smacro procedure putv(a,b,c); iputv(a,b,c);

flag('(intersection),'lose);


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
        if !*loadversion then errorset('(load entry),nil,nil);
        !*gc := nil;
        !*usermode := nil;
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

spare!* := 11;   % We need this for bootstrapping.

symbolic procedure initreduce;
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
    eval '(begin);
    currentscantable!* := lispscantable!*; % But Slisp should use same
                                           % syntax as RLISP?
    standardlisp()
  end;

flag('(dskin savesystem reclaim),'opfn);

flag('(dskin savesystem),'noval);

flag('(load),'noform);

deflist('((load rlis)),'stat);

flag('(tr trst untr untrst),'noform);

deflist('((tr rlis) (trst rlis) (untr rlis) (untrst rlis)),'stat);

% The following is PSL 3.4 specific.

switch fulltrace;   % Prevents node renaming in trace output.

!*fulltrace := t;   % Since we usually want it this way.

Comment The global variable ESC* is used by the interactive string
editor (defined in CEDIT) as a terminator for input strings.  In PSL
we use the escape character;

esc!* := '!;


Comment The following declarations are needed to build various modules;

flag('(nth pnth spaces subla),'lose);   % used in ALG1

flag('(explode2 explode21),'lose);      % used in RPRINT

flag('(flag1 remflag1),'lose);          % used in RCREF


Comment The following are only needed for PSL 3.2;

% symbolic fexpr procedure definebop u; u;

% symbolic fexpr procedure definerop u; u;


Comment Specific Optimizations for Cray and Sun 4 version;

remflag('(quotdd),'lose);

symbolic procedure quotdd(u,v);
   % U and V are domain elements.  Value is U/V if division is exact,
   % NIL otherwise.
   if atom u then if atom v
          %%%        then if remainder(u,v)=0 then u/v else nil
                     then (if cdr div = 0 then car div else NIL)
                                   where div = divide (u,v)
                    else quotdd(apply1(get(car v,'i2d),u),v)
   else if atom v then quotdd(u,apply1(get(car u,'i2d),v))
        else dcombine(u,v,'quotient);

flag('(quotdd),'lose);

remflag('(mchk),'lose);

symbolic procedure mchk(u,v);
   IF u eq v then cons(nil,nil)
    else mchk!-aux (u,v);

symbolic procedure mchk!-aux(U,V);
   if not idp u and not idp v and u=v then cons(nil,nil)
    else if atom v
	 then if v memq frlis!* then list list (v . u) else nil
    else if atom u      %special check for negative number match;
     then if numberp u and u<0 then mchk!-aux(list('minus,-u),v)
	 else nil
    else if car u eq car v then mcharg(cdr u,cdr v,car u)
    else nil;

flag('(mchk),'lose);

remflag('(update!-pline),'lose);

symbolic procedure update!-pline(x,y,pline);
   for each j in pline collect
       ((iplus2(caaar j,x) . iplus2(cdaar j,x))
                                 . iplus2(cdar j ,y)) . cdr j;

flag('(update!-pline),'lose);

remflag('(peq ordpp noncomp),'lose);

symbolic smacro procedure peq(u,v);
   %tests for equality of powers U and V;
  (( eq(cdu1,cdu2) and
     if eq(cu1,cu2) then t
        else if atom cu1 or atom cu2 then NIL
                else equal(cu1,cu2)
   ) where cu1 = car u1,cu2 = car u2,cdu1 = cdr u1,cdu2 = cdr u2
  ) where u1 = u,u2 = v;

symbolic smacro procedure ordpp(uu,vv);
   % This used to check (incorrectly) for NCMP!*;
 ((if caru eq carv then igreaterp(cdru,cdrv) else ordop(caru,carv)
  ) where caru = car u, carv = car v, cdru = cdr u, cdrv = cdr v
 )where u=uu,v=vv;

symbolic smacro procedure noncomp uu;
  ( pairp u and ((idp caru and flagp(caru,'noncom)
                )where caru = car u)) where u = uu;

flag('(peq ordpp noncomp),'lose);


Comment Now set the system name;

systemname!* := 'sparc;

endmodule;

end;
