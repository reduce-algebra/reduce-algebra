module rend; % PSL REDUCE "back-end".

% Authors: Martin L. Griss and Anthony C. Hearn.

% Except where noted, this works with both PSL 3.2 and PSL 3.4.

create!-package('(rend psl fastmath fastmod),'(build));

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
         crbuflis!*
         crchar!*
         date!*
         esc!*
         ifl!*
         ipl!*
         largest!-small!-modulus
         ofl!*
         spare!*
         statcounter
         version!*
         lispsystem!*);

compiletime global '(cr!* ff!* tab!*);

switch break,gc,usermode,verboseload;

switch plap,pgwd,pwrds;

flag('(define!-constant),'eval);

% Encode information about underlying system.

compiletime define!-constant(system_list!*, 'psl . system_list!*);

lispsystem!* := system_list!*;

compiletime (lispsystem!* := system_list!*); % for this module

!*fastcar := t;   % Since REDUCE doesn't use car and cdr on atoms.


% Constants used in scanner.

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
         '((a . !a) (b . !b) (c . !c) (d . !d) (e . !e) (f . !f)
           (g . !g) (h . !h) (i . !i) (j . !j) (k . !k) (l . !l)
           (m . !m) (n . !n) (o . !o) (p . !p) (q . !q) (r . !r)
           (s . !s) (t . !t) (u . !u) (v . !v) (w . !w) (x . !x)
           (y . !y) (z . !z))))
        then return cdr x
       else rederr list(u,"not upper case character")
   end;

symbolic procedure uppercasep u;
   u memq '(a b c d e f g h i j k l m n o p q r s t u v w x y z);

% symbolic procedure orderp(u,v);
%    % U, V are non-numeric atoms (but can be vectors).
%    % Returns true if U has same or higher order than id V by some
%    % consistent convention (eg unique position in memory).
%    wleq(inf u,inf v);       % PSL 3.4 form.
% %  id2int u <= id2int v;    % PSL 3.2 form.

symbolic procedure orderp(u,v);
   % This PSL-specific definition of ORDERP is designed to work in
   % lexicographical order.  It also checks to make sure arguments are
   % truly id's, which should be true with current REDUCE.
   begin scalar i,j,k,l,m;  % All sints.
      if idp u then u := strinf symnam idinf u
       else return typerr(u,"identifier");
      if idp v then v := strinf symnam idinf v
       else return typerr(v,"identifier");
      i := 0;
      j := strlen u;
      k := strlen v;
      % In the following, we assume size of u and v are inums.
   a: if null((l := strbyt(u,i)) eq (m := strbyt(v,i)))
        then return ilessp(l,m)
       else if i eq j then return null igreaterp(j,k)
       else if i eq k then return nil;
      i := iplus2(i,1);
      go to a;
   end;

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
%       if not yesp "do you really want to leave REDUCE?"
%          then go to a;
        prin2t "Entering LISP ... "
 end;

flag('(begin),'go);


Comment Initial setups for REDUCE;

spare!* := 11;   % We need this for bootstrapping.

symbolic procedure initreduce; initrlisp();   % For compatibility.

symbolic procedure initrlisp;
  % Initial declarations for REDUCE
  <<statcounter := 0;
    spare!* := 11;
    !*int := t;
    !*eolinstringok := t;  % We don't want the "string continued" msg.
    crbuflis!* := nil;     % We don't want to leave old input around.
    remd 'main;
    copyd('main,'rlispmain)>>;

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

esc!* := intern int2id 27;


% The following are compiler switches.

fluid '(!*pgwd !*plap !*pwrds !*pcmac);

flag('(pgwd plap pwrds pcmac),'switch);


Comment The following declarations are needed to build various modules;

flag('(fl2int),'lose);                  % Used in MATH.

flag('(nth pnth spaces subla),'lose);   % Used in ALG1.

flag('(explode2 explode21),'lose);      % Used in RPRINT.

flag('(flag1 remflag1),'lose);          % Used in RCREF.

flag('(vector2list),'lose);             % Used in HILBERTS.

deflist('((imports rlis)),'stat);   % Needed for ~imports to work.

fluid '(!*defn !*errcont);

global '(erfg!* cmsg!*);

symbolic procedure read!-init!-file name;
  % Read a resource file in REDUCE syntax. Quiet input.
  % Look for file in home directory. If no home directory
  % is defined, use the current directory.
  begin scalar base,fname,x,y;
   base := getenv "home" or getenv "HOME" or
           ((x:=getenv "HOMEDRIVE")and(y:=getenv "HOMEPATH")
            and bldmsg("%w%w",x,y)) or "";
   fname:=if filep (x:=bldmsg("%w/.%wrc",base,name)) then x
          else if filep (x:=bldmsg("%w/%w.rc",base,name)) then x;
   if null fname then return nil;
   x := errorset({'in1,fname,nil},nil,nil)
       where !*int=nil,!*errcont=nil;
   if errorp x or erfg!* then
   <<terpri();
     prin2t "***********************************************";
     prin2t "***  error during processing the resource file ";
     prin2  "***      "; prin2t fname;
     prin2t "***********************************************";
   >>;
   close!-input!-files();
   erfg!*:= cmsg!* := !*defn := nil;
   statcounter:=0;
  end;

endmodule;


module psl;

imports big2sys, bigp, floatloworder, floathighorder, gtneg, gtpos,
        i2bf!:, idifference, igetv, ilessp, iminus, inf, iplus, isub1,
        itimes, land, lshift, make!:ibf, neq, sys2int, trimbignum,
        vecinf, veclen, wand, wdifference, wminus, wor, wplus2, wputv,
        wquotient, wshift;

exports ashift, msd!:, fl2bf, integerp!:, normbf, oddintp, preci!:;

fluid '(bbits!*);

global '(bfz!*);

compiletime
  global '(!!fleps1exp !!plumaxexp !!pluminexp !!timmaxexp !!timminexp);

remflag ('(ashift msd!: fl2bf ff0 ff1
           bf!-bits bf!-bits!-mask integerp!: normbf oddintp preci!:),
         'lose);

flag('(cond),'eval);   % Enable conditional compilation.

%-------------------------------------------------------------------

% The following routines support fast float operations by exploiting
% the IEEE number format explicitly.

if 'ieee member lispsystem!* then
  remflag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose)
    else
  flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose);

% Currently 32 and 64 bit IEEE machines are supported.
%
% The following macros assume that on 64 bit machines floathighorder
% and floatloworder both load the full 64 bit floating point number.

compiletime
<<
  define!-constant(ieeeshift,12 - bitsperword);  % 32 bits:-20
  define!-constant(signshift,1 - bitsperword);   % 32 bits:-31
  define!-constant(ieeebias,1023);
  define!-constant(ieeemask,2047);
  ds(floathiword,x(),floathighorder inf x);
  ds(floatloword,x(),floatloworder inf x);

  if bitsperword=32 then
  <<
    ds(ieeezerop,u(), weq(0,floathiword u) and weq(0,floatloword u));
    ds(ieeeequal,u(v),
           weq(floathiword u,floathiword v)
       and weq(floatloword u,floatloword v));
    ds(ieeemant,f(),
       (lor(lshift(
               wor(wshift(wand (floathiword f, 1048575), % 16#FFFFF
                          6),
                   wshift(lf,-26)),
               26),
               wand(lshift(-1,-6), lf))
         where lf := floatloword f));
   >>
   else if bitsperword=64 then
   <<
    ds(ieeezerop,u(), weq(0,floathiword u));
    ds(ieeeequal,u(v), weq(floathiword u,floathiword v));
    ds(ieeemant,f(), wand (floathiword f,
                           4503599627370495)); % 16#FFFFFFFFFFFFF
 >>
   else error(99,"#### unknown bit size");

  ds(ieeeexpt,u(),
      wdifference(wand(ieeemask,
                       wshift(floathiword u,ieeeshift)),
                 ieeebias));
  ds(ieeesign,u(),wshift(floathiword u,signshift));
     % ieeemant is the mantissa part of the upper 32 bit group.

  define!-constant(!!plumaxexp,1018);
  define!-constant(!!pluminexp,-979);
  define!-constant(!!timmaxexp,509);
  define!-constant(!!timminexp,-510);
  define!-constant(!!fleps1exp,-40)
>>;

symbolic procedure safe!-fp!-plus(x,y);
   if ieeezerop x then y
    else if ieeezerop y then x
    else begin scalar u,ex,ey,sx,sy;
            ex := ieeeexpt x;
            ey := ieeeexpt y;
            if (sx := ieeesign x) eq (sy := ieeesign y)
              then if ilessp(ex,!!plumaxexp) and ilessp(ey,!!plumaxexp)
                    then go to ret else return nil;
            if ilessp(ex,!!pluminexp) and ilessp(ey,!!pluminexp)
              then return nil;
          ret:
            u := floatplus2(x,y);
        return
            if sx eq sy or ieeezerop u then u
             else if ilessp(ieeeexpt u,iplus2(ex,!!fleps1exp)) then 0.0
             else u
         end;

symbolic procedure safe!-fp!-times(x,y);
   if ieeezerop x or ieeezerop y then 0.0
    else if ieeeequal(x,1.0) then y
    else if ieeeequal(y,1.0) then x
    else begin scalar u,v;
            u := ieeeexpt x;
            v := ieeeexpt y;
            if igreaterp(u,!!timmaxexp)
              then if ilessp(v,0) then go to ret else return nil;
            if igreaterp(u,0)
              then if ilessp(v,!!timmaxexp) then go to ret
                    else return nil;
            if igreaterp(u,!!timminexp)
              then if igreaterp(v,!!timminexp) then go to ret
                    else return nil;
            if ilessp(v,0) then return nil;
          ret:
            return floattimes2(x,y)
         end;

symbolic procedure safe!-fp!-quot(x,y);
   if ieeezerop y then rdqoterr()
    else if ieeezerop x then 0.0
    else if ieeeequal(y,1.0) then x
    else begin scalar u,v;
            u := ieeeexpt x;
            v := ieeeexpt y;
            if igreaterp(u,!!timmaxexp)
              then if igreaterp(v,0) then go to ret
                    else return nil;
            if igreaterp(u,0)
              then if igreaterp(v,!!timminexp) then go to ret
                    else return nil;
            if igreaterp(u,!!timminexp)
              then if ilessp(v,!!timmaxexp) then go to ret
                    else return nil;
            if igreaterp(v,0) then return nil;
          ret:
            return floatquotient(x,y)
         end;

compiletime
 if 'ieee member lispsystem!* then
  flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose)
   else
  remflag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose);

%---------------------------------------------------------------

deflist('((iminus iminus)),'unary);

symbolic smacro procedure ashift (m,d);
  if negintp m then -lshift(-m,d) else lshift(m,d);

symbolic smacro procedure oddintp x;
   wand(if bigp x then wgetv(inf x,2)
         else if fixnp x then fixval inf x
         else x,1) eq 1;

symbolic macro procedure bf!-bits (x); {'quote, bbits!*};

%symbolic macro procedure bf!-bits!-mask (x);
%   {'quote, lshift(1, bf!-bits()) - 1};

%symbolic procedure ff1 (w,n);
%  if n eq 0 then w else
%  if wshift (w, wminus n) eq 0 then
%        ff1 (w,wquotient(n,2))
%    else iplus2(ff1 (wshift (w, wminus n),wquotient(n,2)),n) ;

symbolic smacro procedure ff1 (ww,nn);
  <<while not (n eq 0) do <<
      x := wshift(w,wminus n);
      if not (x eq 0) then % left half
        << w := x; y := iplus2(y,n) >>;   % Iplus2 etc. used for
      n := wquotient (n,2)                % bootstrapping.
    >>;
    iplus2(y,w) >>
    where w=ww,n=nn,x=nil,y=0;

%symbolic procedure ff0 (w,n);
%%   returns the number of 0 bits at the least significant end
%  if n eq 0 then w else
%   begin scalar lo;
%     lo := wand(w,isub1 wshift(1,n));
%  return if lo eq 0
%           then iplus2(n,ff0 (wshift(w,wminus n),wquotient(n,2)))
%          else ff0 (lo,wquotient(n,2)) ;
%  end;

Comment ff0 determines the number of 0 bits at the least significant
        end of an integer, ie. the largest power of two by which the
        integer is divisible;

symbolic smacro procedure ff0 (ww,nn);
  <<while not (n eq 0) do <<
      lo := wand(w,isub1 wshift(1,n));
      if lo eq 0 then % left half
        << w := wshift(w,wminus n);
           y := iplus2(y,n) >>;           % Iplus2 etc. used for
      n := wquotient (n,2)                % bootstrapping.
    >>;
    if w eq 0 then iadd1 y else y >>
    where w=ww,n=nn,lo=nil,y=0;

% use wshift(bitsperword,-1) rather than bitsperword/2 as the former
% is open compiled


Comment we split msd!: into two parts: one for bignums, one for
        machine words. That will greatly reduce the size of preci!:
        below;

symbolic smacro procedure word!-msd!: u;
   ff1(u,wshift(bitsperword,-1));

symbolic smacro procedure big!-msd!: u;
   iplus2(itimes2(bf!-bits(),isub1 s),word!-msd!: igetv(u,s))
       where s := veclen vecinf u;

symbolic smacro procedure msd!: u;
   if bigp u then big!-msd!: u
    else if fixnp u then word!-msd!: fixval inf u
    else word!-msd!: u;

%symbolic smacro procedure msd!: u;
%  % returns the most significant (binary) digit of a positive integer u
%  if bigp u
%    then iplus2(itimes2(bf!-bits(),isub1 s),
%                ff1(igetv(u,s),wshift(bitsperword,-1)))
%       where s := veclen vecinf u
%   else if fixnp u then ff1 (fixval inf u,wshift(bitsperword,-1))
%   else ff1 (u,wshift(bitsperword,-1));

symbolic smacro procedure mt!: u; cadr u;
symbolic smacro procedure ep!: u; cddr u;

symbolic smacro procedure preci!: nmbr;
   % This function counts the precision of a number "n". NMBR is a
   % binary bigfloat representation of "n".
   % msd!: abs mt!: nmbr
   (if bigp m then big!-msd!: m
     else if fixnp m
      then (word!-msd!:(if iminusp n then iminus n else n)
                         where n = fixval inf m)
     else if iminusp m then word!-msd!:(iminus m)
     else word!-msd!: m)
    where m = mt!: nmbr;

%symbolic smacro procedure preci!: nmbr;
%   % This function counts the precision of a number "n". NMBR is a
%   % binary bigfloat representation of "n".
%   % msd!: abs mt!: nmbr
%   (if bigp m then msd!: m
%     else if fixnp m
%      then (ff1(if iminusp n then iminus n else n,
%                wshift(bitsperword,-1))
%              where n = fixval inf m)
%     else if iminusp m then ff1(iminus m,wshift(bitsperword,-1))
%     else ff1(m,wshift(bitsperword,-1)))
%    where m = mt!: nmbr;

symbolic smacro procedure make!:ibf (mt, ep);
  '!:rd!: . (mt . ep);

if not('ieee memq lispsystem!*) then
     flag('(fl2bf),'lose);

symbolic procedure fl2bf f;
  % u is a floating point number
  % result is a binary bigfloat
  if fixp f then i2bf!: f
   else begin scalar m,e;
      m := ieeemant f;
      e := ieeeexpt f;
      % if exponent <> -1023 add 16#10000000000000, implicit highest bit
      if e neq  -1023 then m := lor (m, lshift(1,52));
      return
        if izerop m then bfz!*
         else normbf make!:ibf (if ieeesign f eq 1 then -m else m,
                                idifference(e,52))
     end;

symbolic procedure normbf x;
   begin scalar mt,s;integer ep,ep1;
      if (mt := mt!: x)=0 then go to ret;
      if mt<0 then <<mt := -mt; s := t>>;
      ep := ep!: x;
%      ep1 := remainder(ep,bf!-bits());
%      if ep1 < 0 then ep1 := ep1 + bf!-bits();
%      if ep1 neq 0 then <<ep := ep - ep1; mt := lshift(mt,ep1)>>;
      while bigp mt and wgetv(inf mt,2) eq 0 do <<
        mt := lshift(mt,-bf!-bits());
        ep := ep+bf!-bits() >>;
      ep1 := ff0(if bigp mt then wgetv(inf mt,2)
                  else if fixnp mt then fixval inf mt
                  else mt,wshift(bitsperword,-1));
      if not (ep1 eq 0) then <<mt := lshift(mt,wminus ep1);
                               ep := ep + ep1>>;
      if s then mt := -mt;
ret:    return make!:ibf(mt,ep) end;

%symbolic procedure normbf x;
%   begin scalar mt,s;integer ep,ep1;
%      if (mt := mt!: x)=0 then go to ret;
%      if mt<0 then <<mt := -mt; s := t>>;
%      ep := ep!: x;
%      while bigp mt and land(mt,bf!-bits!-mask())=0 do <<
%        mt := lshift(mt,-bf!-bits());
%        ep := ep+bf!-bits() >>;
%      while land(mt,255)=0 do <<
%        mt := lshift(mt,-8);
%        ep := ep+8 >>;
%      while land(mt,1)=0 do <<
%        mt := lshift(mt,-1);
%        ep := ep+1>>;
%%      ep1 := remainder(ep,bf!-bits());
%%      if ep1 < 0 then ep1 := ep1 + bf!-bits();
%%      if ep1 neq 0 then <<ep := ep - ep1; mt := lshift(mt,ep1)>>;
%      if s then mt := -mt;
%ret:    return make!:ibf(mt,ep) end;

symbolic procedure integerp!: x;
% This function returns T if X is a BINARY BIG-FLOAT
%      representing an integer, else it returns NIL.
% X is any LISP entity.
bfp!: x and
  (ep!: x >= 0 or
    preci!: x > - ep!: x and
      land(abs mt!: x,lshift(2,-ep!: x) - 1) = 0);

flag ('(ashift lshift msd!: fl2bf ff0 ff1
        bf!-bits bf!-bits!-mask integerp!: normbf oddintp preci!:),
      'lose);

if not('ieee memq lispsystem!*) then remflag('(fl2bf),'lose);

% This belong in $pxu/nbig30a.

symbolic(bigfloathi!* :=  (2 ** 53 - 1) * 2 ** 971);

symbolic(bigfloatlow!* := - bigfloathi!*);

remflag('(cond),'eval);



% HP-Risc and IBM RS architectures need special handling of fltinf in
% fastmath.red

if 'hp!-risc member lispsystem!* then
   <<remflag('(fltinf),'lose);
     ds(fltinf,x(),mkitem(vector!-tag,x));
     flag('(fltinf),'lose)>>;

if 'ibmrs member lispsystem!* then
   <<remflag('(fltinf),'lose);
     ds(fltinf,x(),mkstr x);
     flag('(fltinf),'lose)>>;

endmodule;


module fastmath;  % Definitions of key functions in the math module of
                  % arith.red using C versions.  This file should be
                  % loaded into REDUCE before the math module is loaded.

global '(!!deg2rad !!rad2deg);

compiletime
  global '(!!fleps1exp !!plumaxexp !!pluminexp !!timmaxexp !!timminexp);

symbolic smacro procedure degreestoradians x; times2(x,!!deg2rad);

symbolic smacro procedure radianstodegrees x; times2(x,!!rad2deg);

remflag('(sin cos tan sind cosd tand cotd secd cscd asin acos atan
       asecd acscd atan2d atan2 sqrt exp log hypot cosh sinh tanh),
      'lose);

% ***** REMOVE THE FOLLOWING LINE WHEN FLOAT.C/EXTERNALS.SL UPDATED.

flag('(hypot cosh sinh tanh),'lose);

% ***** REMOVE THE FOLLOWING LINE WHEN WE KNOW HOW TO HANDLE COMPLEX
%       VALUES FOR ACOS, ASIN.

flag('(acos asin),'lose);

% Trig functions in radians.

symbolic procedure cos x;
   begin scalar result;
      x := float x;    % We put this here to make sure no GC can happen
                       % between gtfltn and mkfltn.
      result := gtfltn();
      uxcos(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure sin x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxsin(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure tan x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxtan(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure acos x;
   begin scalar result;
      if abs x> 1.0
        then rerror(rend,101,list("argument to ACOS too large:",x));
      x := float x;
      result := gtfltn();
      uxacos(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure asin x;
   begin scalar result;
      if abs x> 1.0
        then rerror(rend,102,list("argument to ASIN too large:",x));
      x := float x;
      result := gtfltn();
      uxasin(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure atan x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxatan(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure atan2(y,x);
   begin scalar result;
      x := float x;
      y := float y;
      result := gtfltn();
      uxatan2(floatbase result,floatbase fltinf y,floatbase fltinf x);
      return mkfltn result
   end;

% ASEC defined in math.red.


% Trig functions in degrees.

symbolic procedure sind x;
   sin degreestoradians x;

symbolic procedure cosd x;
   cos degreestoradians x;

symbolic procedure tand x;
   tan degreestoradians x;

symbolic procedure cotd x;
   cot degreestoradians x;

symbolic procedure secd x;
   sec degreestoradians x;

symbolic procedure cscd x;
   csc degreestoradians x;

symbolic procedure asecd x;
   radianstodegrees asec x;

symbolic procedure acscd x;
   radianstodegrees acsc x;

symbolic procedure atan2d(y,x);
   radianstodegrees atan2(y,x);


% Exponential, logarithm, power, square root, hypotenuse.

symbolic procedure exp x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxexp(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure log x;
   begin scalar result;
      if x <= 0.0
        then rerror(rend,103,list("non-positive argument to LOG:",x));
      x := float x;
      result := gtfltn();
      uxlog(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

% LOG10 in math.red.

symbolic procedure sqrt x;
   begin scalar result;
      if x < 0.0
        then rerror(rend,104,list("negative argument to SQRT:",x));
      x := float x;
      result := gtfltn();
      uxsqrt(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure hypot(x,y);
   begin scalar result;
      x := float x;
      y := float y;
      result := gtfltn();
      uxhypot(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;


% Hyperbolic functions.

symbolic procedure cosh x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxcosh(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure sinh x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxsinh(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

symbolic procedure tanh x;
   begin scalar result;
      x := float x;
      result := gtfltn();
      uxtanh(floatbase result,floatbase fltinf x);
      return mkfltn result
   end;

(for each u in
   '(sin cos tan sind cosd tand cotd secd cscd asin acos atan
     asecd acscd atan2d atan2 sqrt exp log hypot cosh sinh tanh)
          do
     if getd intern bldmsg("UX%w",u) then flag(list u,'lose)
   ) where !*lower=nil;

% ***** REMOVE THE FOLLOWING LINE WHEN FLOAT.C/EXTERNALS.SL UPDATED.

remflag('(hypot cosh sinh tanh),'lose);

% ***** REMOVE THE FOLLOWING LINE WHEN WE KNOW HOW TO HANDLE COMPLEX
%       VALUES FOR ACOS, ASIN.

remflag('(acos asin),'lose);

remflag('(cond),'eval);

endmodule;


module fastmod; % fast computation with modular numbers.

% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

%
%    ( a * b ) mod current!-modulus
%
% in one call with double length intermediate result, avoiding
% conversion to bignums. Significant speedup for e.g. factorizer.

remflag('(modular!-times general!-modular!-times),'lose);

compiletime
<<
  if memq('nbig30,options!*) then load muls else load muls32;
  slow_wquotientdouble := memq('mips,lispsystem!*);
>>;

fluid '(!*second!-value!* current!-modulus);

remflag('(modular!-times general!-modular!-times),'lose);

% Routines from smallmod.red and genmod.red

compiletime if slow_wquotientdouble then
     flag('(modular!-times),'lose);

symbolic procedure modular!-times(a,b);
   begin scalar q;
    q:=wtimesdouble(a,b); % upper part in second value.
    wquotientdouble(!*second!-value!*,q,current!-modulus);
                          % remainder in second value.
    return !*second!-value!*;
   end;

compiletime if slow_wquotientdouble then
     remflag('(modular!-times),'lose)
       else
     flag('(modular!-times),'lose);

symbolic procedure modular!-times(a,b);
 % for systems where single divide is substantially faster than
 % double divide.
   begin scalar q;
    q:=wtimesdouble(a,b); % upper part in second value.
    if weq(!*second!-value!*,0) and wgreaterp(q,0) then
        return wremainder(q,current!-modulus);
    wquotientdouble(!*second!-value!*,q,current!-modulus);
                          % remainder in second value.
    return !*second!-value!*;
   end;

compiletime remflag('(modular!-times),'lose);

symbolic procedure general!-modular!-times(a,b);
  % Use fast function if all operands are inums.
   if weq(0,iplus2(tag a,iplus2(tag b,tag current!-modulus)))
      then modular!-times(a,b) else general!-modular!-times!*(a,b);

symbolic procedure general!-modular!-times!*(a,b);
  begin scalar result;
     result:=remainder(a*b,current!-modulus);
     if result<0
       then result := result+current!-modulus;  %can this happen?
     return result
  end;

flag ('(modular!-times general!-modular!-times),'lose);

% Routines from factor/VECPOLY.red. 
% Smallmod arithmetic never allocates heap space such
% that vector base addresses remain valid and subsequent
% vector access can be transformed into index incremental.

remflag('(times!-in!-vector remainder!-in!-vector),'lose);

symbolic procedure times!-in!-vector(a,da,b,db,c);
% Put the product of A and B into C and return its degree.
% C must not overlap with either A or B;
  begin
    scalar dc,ic,w,lc,lb;
    if ilessp(da,0) or ilessp(db,0) then return minus!-one;
    dc:=iplus2(da,db);
    for i:=0:dc do putv(c,i,0);
    for ia:=0:da do <<
      w:=getv(a,ia);
      lb := loc igetv(b,0);
      lc := loc igetv(c,ia);
      for ib:=0:db do <<
        ic:=iplus2(ia,ib);

     %  PUTV(C,IC,MODULAR!-PLUS(GETV(C,IC),
     %    MODULAR!-TIMES(W,GETV(B,IB)))) 

        putmem(lc,modular!-plus(getmem lc,
          modular!-times(w,getmem lb)));
        lb := iplus2(lb,addressingunitsperitem);
        lc := iplus2(lc,addressingunitsperitem);

      >> >>;
    return dc
  end;

symbolic procedure remainder!-in!-vector(a,da,b,db);
% Overwrite the vector A with the remainder when A is
% divided by B, and return the degree of the result;
  begin
    scalar delta,db!-1,recip!-lc!-b,w,la,lb;
    if db=0 then return minus!-one
    else if db=minus!-one then errorf "ATTEMPT TO DIVIDE BY ZERO";
    recip!-lc!-b:=modular!-minus modular!-reciprocal getv(b,db);
    db!-1:=isub1 db; % Leading coeff of B treated specially, hence this;
    while not ilessp(delta:=idifference(da,db),0) do <<
      w:=modular!-times(recip!-lc!-b,getv(a,da));
      la := loc(igetv(a,delta)); lb:= loc(igetv(b,0));
      for i:=0:db!-1 do

       %PUTV(A,I#+DELTA,MODULAR!-PLUS(GETV(A,I#+DELTA),
       %  MODULAR!-TIMES(GETV(B,I),W)));

       <<putmem(la,modular!-plus(getmem la,
          modular!-times(getmem lb,w)));
         la := iplus2(la,addressingunitsperitem);
         lb := iplus2(lb,addressingunitsperitem);
       >>;

      da:=isub1 da;
      while not ilessp(da,0) and getv(a,da)=0 do da:=isub1 da >>;
    return da
  end;

flag('(times!-in!-vector remainder!-in!-vector),'lose);

endmodule;


end;
